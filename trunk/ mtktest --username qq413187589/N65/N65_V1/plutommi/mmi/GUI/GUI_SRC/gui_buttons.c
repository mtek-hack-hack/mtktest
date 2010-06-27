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
 *  gui_buttons.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  UI component - buttons
 *  
 *  o Button
 *  o Icon button
 *  o Text button
 *  o Icontext button
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#include "gui_buttons.h"
#include "MMI_features.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "UCS2Prot.h"
#include "DebugInitDef.h"
#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#endif /*__MMI_SCREEN_ROTATE__*/
#include "Gdi_include.h"


#ifdef __MMI_IDLE_FULL_SCREEN__
extern U16 on_idle_screen;
#endif 

extern BOOL r2lMMIFlag;


UI_button_theme *current_button_theme = NULL;
extern S32 UI_get_font_height(UI_font_type f);

static void gui_icontext_button_get_display_area_ex(icontext_button *b, S32 *display_x1, S32 *display_y1, S32 *display_x2, S32 *display_y2);

/***************************************************************************** 
 * Simple Button (filler only)
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_set_button_current_theme
 * DESCRIPTION
 *  Applies the current theme for a button
 * PARAMETERS
 *  b       [IN]        Is the button to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_button_current_theme(button *b)
{
    /* set the theme of button when the state of button is up */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = current_button_theme->normal_up_filler;
    /* set the theme of button when the state of button is down */
    b->normal_down_filler = current_button_theme->normal_down_filler;
    /* set the theme of button when the  button is disabled */
    b->disabled_up_filler = current_button_theme->disabled_up_filler;

    b->disabled_down_filler = current_button_theme->disabled_down_filler;
    /* set the theme of button when the  button is focussed */
    b->focussed_up_filler = current_button_theme->focussed_up_filler;
    b->focussed_down_filler = current_button_theme->focussed_down_filler;
    b->clicked_up_filler = current_button_theme->clicked_up_filler;
    b->clicked_down_filler = current_button_theme->clicked_down_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_button_theme
 * DESCRIPTION
 *  Applies the given theme to a button
 * PARAMETERS
 *  b       [IN]        Is the button to use
 *  t       [IN]        Is the button theme to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_button_theme(button *b, UI_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_button
 * DESCRIPTION
 *  Creates a button
 *  
 *  Note: Memory must be allocated to the button structure before
 *  being passed to this function.
 * PARAMETERS
 *  b           [IN]        Is the button  (pre-allocated)
 *  x           [IN]        Is the position of the left-top corner of the button
 *  y           [IN]        Is the position of the left-top corner of the button
 *  width       [IN]        Is the width of the button
 *  height      [IN]        Is the height of the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_button(button *b, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;                           /* start x position of button */
    b->y = y;                           /* start y position of button */
    b->width = width;                   /* width of button */
    b->height = height;                 /* height of button */
    b->flags = 0;
    b->clear_background_fp = NULL;
    
    gui_set_button_current_theme(b);    /* set the theme of button to current theme */
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_button
 * DESCRIPTION
 *  Displays a button
 * PARAMETERS
 *  b       [IN]        Is the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_button(button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;                  /* start x position of button */
    y1 = b->y;                  /* start y position of button */
    x2 = x1 + b->width - 1;     /* end x position of button */
    y2 = y1 + b->height - 1;    /* end y position of button */
    if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
		    if (b->flags & UI_BUTTON_NO_SHIFT_BUTTON)
		    {
		        /* No action */
		    }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
            {
                x1 += 2;
                y1 += 2;
                x2 += 2;
                y2 += 2;
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
            {
                x1 += 1;
                y1 += 1;
                x2 += 1;
                y2 += 1;
            }
            f = b->clicked_down_filler;
        }
        else
        {
            f = b->clicked_up_filler;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_FOCUSSED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->focussed_down_filler;
        }
        else
        {
            f = b->focussed_up_filler;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_DISABLED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->disabled_down_filler;
        }
        else
        {
            f = b->disabled_up_filler;
        }
    }
    else
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->normal_down_filler;
        }
        else
        {
            f = b->normal_up_filler;
        }
    }
    
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, f);    /* fill the area with color */
    gui_pop_clip();
}


/***************************************************************************** 
 * Text Button
 *****************************************************************************/

UI_text_button_theme *current_text_button_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_text_button_current_theme
 * DESCRIPTION
 *  Applies the current theme for a text button
 * PARAMETERS
 *  b       [IN]        Is the text button to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_text_button_current_theme(text_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = current_button_theme->normal_up_filler;
    b->normal_down_filler = current_button_theme->normal_down_filler;
    b->disabled_up_filler = current_button_theme->disabled_up_filler;
    b->disabled_down_filler = current_button_theme->disabled_down_filler;
    b->focussed_up_filler = current_button_theme->focussed_up_filler;
    b->focussed_down_filler = current_button_theme->focussed_down_filler;
    b->clicked_up_filler = current_button_theme->clicked_up_filler;
    b->clicked_down_filler = current_button_theme->clicked_down_filler;
    b->normal_up_text_color = current_text_button_theme->normal_up_text_color;
    b->normal_down_text_color = current_text_button_theme->normal_down_text_color;
    b->disabled_up_text_color = current_text_button_theme->disabled_up_text_color;
    b->disabled_down_text_color = current_text_button_theme->disabled_down_text_color;
    b->focussed_up_text_color = current_text_button_theme->focussed_up_text_color;
    b->focussed_down_text_color = current_text_button_theme->focussed_down_text_color;
    b->clicked_up_text_color = current_text_button_theme->clicked_up_text_color;
    b->clicked_down_text_color = current_text_button_theme->clicked_down_text_color;
    b->text_font = current_text_button_theme->text_font;
    b->flags |= current_text_button_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_text_button_theme
 * DESCRIPTION
 *  Applies the given theme to a text button
 * PARAMETERS
 *  b       [IN]        Is the text button to use
 *  t       [IN]        Button theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_text_button_theme(text_button *b, UI_text_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = current_button_theme->normal_up_filler;
    b->normal_down_filler = current_button_theme->normal_down_filler;
    b->disabled_up_filler = current_button_theme->disabled_up_filler;
    b->disabled_down_filler = current_button_theme->disabled_down_filler;
    b->focussed_up_filler = current_button_theme->focussed_up_filler;
    b->focussed_down_filler = current_button_theme->focussed_down_filler;
    b->clicked_up_filler = current_button_theme->clicked_up_filler;
    b->clicked_down_filler = current_button_theme->clicked_down_filler;
    b->normal_up_text_color = t->normal_up_text_color;
    b->normal_down_text_color = t->normal_down_text_color;
    b->disabled_up_text_color = t->disabled_up_text_color;
    b->disabled_down_text_color = t->disabled_down_text_color;
    b->focussed_up_text_color = t->focussed_up_text_color;
    b->focussed_down_text_color = t->focussed_down_text_color;
    b->clicked_up_text_color = t->clicked_up_text_color;
    b->clicked_down_text_color = t->clicked_down_text_color;
    b->text_font = t->text_font;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_text_button_BG_theme
 * DESCRIPTION
 *  Applies the given button theme to a text button
 * PARAMETERS
 *  b       [IN]        Is the text button to use
 *  t       [IN]        Is the button theme (Note: This is not a text button theme)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_text_button_BG_theme(text_button *b, UI_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_text_button
 * DESCRIPTION
 *  Creates a text button
 *  
 *  Note: Memory must be allocated to the button structure before
 *  being passed to this function.
 * PARAMETERS
 *  b           [IN]        Is the text button
 *  x           [IN]        Is the position of the left-top corner of the button
 *  y           [IN]        Is the position of the left-top corner of the button
 *  width       [IN]        Is the width of the button
 *  height      [IN]        Is the height of the button
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_text_button(text_button *b, S32 x, S32 y, S32 width, S32 height, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;                               /* start x position of button */
    b->y = y;                               /* start y position of button */
    b->width = width;                       /* width of button */
    b->height = height;                     /* height of button */
    b->flags = 0;
    b->text = text;                         /* text of button */
    b->clear_background_fp = NULL;
    
    gui_set_text_button_current_theme(b);   /* set the theme of button equal to current theme */
    
    /* Autocalculate the text position based on font   */
    gui_set_font(b->text_font);             /* set font of text button */
    gui_measure_string(text, &sw, &sh);     /* measure width and height of string */
    b->text_height = sh;                    /* text height of button */
    if (b->flags & UI_BUTTON_CENTER_TEXT_X)
    {
        b->text_x = (width >> 1) - (sw >> 1);   /* start x position of text of button */
        if (b->text_x < 0)
        {
            if (r2lMMIFlag)
            {
                b->text_x = width - sw;
            }
            else
            {
                b->text_x = 0;
            }
        }
    }
    else
    {
        b->text_x = 0;  /* start x position of text of button */
    }
    if (b->flags & UI_BUTTON_CENTER_TEXT_Y)
    {
        b->text_y = (height >> 1) - (sh >> 1);  /* start y position of text of button */
    }
    else
    {
        b->text_y = 0;  /* start y position of text of button */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_button_set_text_position
 * DESCRIPTION
 *  Changes the position of the text in the text button
 * PARAMETERS
 *  b       [IN]        Is the text button
 *  x       [IN]        Is the position text (Offset from the left-top corner of the button)
 *  y       [IN]        Is the position text (Offset from the left-top corner of the button)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_button_set_text_position(text_button *b, S32 x, S32 y)
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
 *  gui_show_text_button
 * DESCRIPTION
 *  Displays the text button
 * PARAMETERS
 *  b       [IN]        Is the text button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_text_button(text_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 text_x, text_y;
    color text_color;
    UI_filled_area *f;
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;                  /* start x position of button */
    y1 = b->y;                  /* start y position of button */
    x2 = x1 + b->width - 1;     /* end x position of button */
    y2 = y1 + b->height - 1;    /* end y position of button */
    text_x = b->text_x;         /* start x position of texr */
    text_y = b->text_y;         /* start y position of text */

    if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            if (b->flags & UI_BUTTON_NO_SHIFT_BUTTON)
            {
                /* No action */
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
            {
                x1 += 2;
                y1 += 2;
                x2 += 2;
                y2 += 2;
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
            {
                x1 += 1;
                y1 += 1;
                x2 += 1;
                y2 += 1;
            }
            f = b->clicked_down_filler;
            text_color = b->clicked_down_text_color;    /* set the text color if button is clicked */
        }
        else
        {
            f = b->clicked_up_filler;
            text_color = b->clicked_up_text_color;  /* set the text color if button is up */
        }
    }
    else if (b->flags & UI_BUTTON_STATE_FOCUSSED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->focussed_down_filler;
            text_color = b->focussed_down_text_color;
        }
        else
        {
            f = b->focussed_up_filler;
            text_color = b->focussed_up_text_color;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_DISABLED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->disabled_down_filler;
            text_color = b->disabled_down_text_color;   /* color of text when button is disabled */
        }
        else
        {
            f = b->disabled_up_filler;
            text_color = b->disabled_up_text_color;
        }
    }
    else
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->normal_down_filler;
            text_color = b->normal_down_text_color;
        }
        else
        {
            f = b->normal_up_filler;
            text_color = b->normal_up_text_color;
        }
    }
    
    if ((b->flags & UI_BUTTON_SHIFT_TEXT) && (b->flags & UI_BUTTON_STATE_DOWN))
    {
        text_x += 1;
        text_y += 1;
    }
    
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_push_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);
    w = gui_get_string_width((UI_string_type) b->text);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + text_x + w, y1 + text_y); /* move cursor to x,y position */
    }
    else
    {
        gui_move_text_cursor(x1 + text_x, y1 + text_y); /* move cursor to x,y position */
    }
    gui_set_text_color(text_color); /* set color of text */
    gui_set_font(b->text_font);     /* set text font */
    gui_set_line_height(b->text_height);
    gui_print_text(b->text);        /* print text */
    gui_pop_text_clip();
    gui_pop_clip();
}

/***************************************************************************** 
 * Icon Button
 *****************************************************************************/

UI_icon_button_theme *current_icon_button_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_icon_button_current_theme
 * DESCRIPTION
 *  Applies the current theme for an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icon_button_current_theme(icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = current_icon_button_theme->normal_up_filler;
    b->normal_down_filler = current_icon_button_theme->normal_down_filler;
    b->disabled_up_filler = current_icon_button_theme->disabled_up_filler;
    b->disabled_down_filler = current_icon_button_theme->disabled_down_filler;
    b->focussed_up_filler = current_icon_button_theme->focussed_up_filler;
    b->focussed_down_filler = current_icon_button_theme->focussed_down_filler;
    b->clicked_up_filler = current_icon_button_theme->clicked_up_filler;
    b->clicked_down_filler = current_icon_button_theme->clicked_down_filler;
    b->flags |= current_icon_button_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_icon_button_theme
 * DESCRIPTION
 *  Applies the given theme to an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 *  t       [IN]        Is the theme to be applied
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icon_button_theme(icon_button *b, UI_icon_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_icon_button_BG_theme
 * DESCRIPTION
 *  Applies the given button theme to an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 *  t       [IN]        Is the button theme to be applied
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icon_button_BG_theme(icon_button *b, UI_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_icon_button
 * DESCRIPTION
 *  Creates an icon button
 *  
 *  Note: Memory must be allocated to the button structure before
 *  being passed to this function.
 *  See PU8 (Abstract type) for the icon
 * PARAMETERS
 *  b               [IN]        Is the icon button   (pre-allocated)
 *  x               [IN]        Is the position of the left-top corner of the button
 *  y               [IN]        Is the position of the left-top corner of the button
 *  width           [IN]        Is the width of the button
 *  height          [IN]        Is the height of the button
 *  button_icon     [IN]        Is the icon to be used in the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_icon_button(icon_button *b, S32 x, S32 y, S32 width, S32 height, PU8 button_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;           /* start x position of icon button */
    b->y = y;           /* start y position of icon button */
    b->width = width;   /* width of icon button */
    b->height = height; /* height of icon button */
    b->flags = 0;
    b->normal_down_icon = button_icon;
    b->normal_up_icon = button_icon;
    b->disabled_down_icon = button_icon;
    b->disabled_up_icon = button_icon;
    b->clicked_down_icon = button_icon;
    b->clicked_up_icon = button_icon;
    b->focussed_down_icon = button_icon;
    b->focussed_up_icon = button_icon;
    b->clear_background_fp = NULL;
    
    gui_set_icon_button_current_theme(b);
    
    /* Autocalculate the icon position */
    if (button_icon != UI_NULL_IMAGE)
    {
        S32 icon_width, icon_height;

        gui_measure_image(button_icon, &icon_width, &icon_height);
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = 0;
        }
        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 0;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_icon_button
 * DESCRIPTION
 *  Changes the size of an icon button
 * PARAMETERS
 *  b           [IN]        Is the icon button
 *  width       [IN]        Is the new width of the button
 *  height      [IN]        Is the new height of the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_icon_button(icon_button *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;   /* width of button */
    b->height = height; /* height of button */

    /* Autocalculate the icon position              */
    if (b->normal_up_icon != UI_NULL_IMAGE)
    {
        S32 icon_width, icon_height;

        /* measure width and height of icon */
        gui_measure_image(b->normal_up_icon, &icon_width, &icon_height);
        /* set start x and start y positon of icon */
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = 0;
        }
        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 0;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_icon_button
 * DESCRIPTION
 *  Changes the location of an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 *  x       [IN]        Is the new location
 *  y       [IN]        Is the new location
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_icon_button(icon_button *b, S32 x, S32 y)
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
 *  gui_icon_button_set_icon_positon
 * DESCRIPTION
 *  Changes the position of the icon within the icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 *  x       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 *  y       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_button_set_icon_positon(icon_button *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->icon_x = x;
    b->icon_y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_button_set_icon
 * DESCRIPTION
 *  Changes the icon used in the icon button
 *  
 *  See UI_transparent_color_type (Abstract type)
 * PARAMETERS
 *  b                           [IN]        Is the icon button
 *  button_icon                 [IN]        
 *  icon_transparent_color      [IN]        Is the transparent color to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_button_set_icon(icon_button *b, PU8 button_icon, UI_transparent_color_type icon_transparent_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_down_icon = button_icon;
    b->normal_up_icon = button_icon;
    b->disabled_down_icon = button_icon;
    b->disabled_up_icon = button_icon;
    b->clicked_down_icon = button_icon;
    b->clicked_up_icon = button_icon;
    b->focussed_down_icon = button_icon;
    b->focussed_up_icon = button_icon;
    b->icon_transparent_color = icon_transparent_color;
    
    /* Autocalculate the icon position              */
    if (button_icon != UI_NULL_IMAGE)
    {
        S32 icon_width, icon_height;

        gui_measure_image(button_icon, &icon_width, &icon_height);
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (b->width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = 0;
        }
        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (b->height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 0;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_icon_button
 * DESCRIPTION
 *  Displays an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_icon_button(icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f;
    PU8 button_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;
    y1 = b->y;
    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;
    if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            if (b->flags & UI_BUTTON_NO_SHIFT_BUTTON)
            {
                /* No action */
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
            {
                x1 += 2;
                y1 += 2;
                x2 += 2;
                y2 += 2;
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
            {
                x1 += 1;
                y1 += 1;
                x2 += 1;
                y2 += 1;
            }
            f = b->clicked_down_filler;
            button_icon = b->clicked_down_icon;
        }
        else
        {
            f = b->clicked_up_filler;
            button_icon = b->clicked_up_icon;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_FOCUSSED)   /* if button is focused */
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->focussed_down_filler;
            button_icon = b->focussed_down_icon;
        }
        else
        {
            f = b->focussed_up_filler;
            button_icon = b->focussed_up_icon;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_DISABLED)   /* if flag of button is disabled */
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->disabled_down_filler;
            button_icon = b->disabled_down_icon;
        }
        else
        {
            f = b->disabled_up_filler;
            button_icon = b->disabled_up_icon;
        }
    }
    else
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)    /* if button is down */
        {
            f = b->normal_down_filler;
            button_icon = b->normal_down_icon;
        }
        else
        {
            f = b->normal_up_filler;
            button_icon = b->normal_up_icon;
        }
    }
    
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    /* fill the buton with color */
    gui_draw_filled_area(x1, y1, x2, y2, f);
    if (button_icon != UI_NULL_IMAGE)
    {
        gui_show_transparent_image(x1 + b->icon_x, y1 + b->icon_y, button_icon, b->icon_transparent_color);
    }
    gui_pop_clip();
}


/***************************************************************************** 
 * IconText Button
 *****************************************************************************/

UI_icontext_button_theme *current_icontext_button_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_icontext_button_current_theme
 * DESCRIPTION
 *  Applies the current theme for an icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icontext_button_current_theme(icontext_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = current_icontext_button_theme->normal_up_filler;
    b->normal_down_filler = current_icontext_button_theme->normal_down_filler;
    b->disabled_up_filler = current_icontext_button_theme->disabled_up_filler;
    b->disabled_down_filler = current_icontext_button_theme->disabled_down_filler;
    b->focussed_up_filler = current_icontext_button_theme->focussed_up_filler;
    b->focussed_down_filler = current_icontext_button_theme->focussed_down_filler;
    b->clicked_up_filler = current_icontext_button_theme->clicked_up_filler;
    b->clicked_down_filler = current_icontext_button_theme->clicked_down_filler;
    b->normal_up_text_color = current_icontext_button_theme->normal_up_text_color;
    b->normal_down_text_color = current_icontext_button_theme->normal_down_text_color;
    b->disabled_up_text_color = current_icontext_button_theme->disabled_up_text_color;
    b->disabled_down_text_color = current_icontext_button_theme->disabled_down_text_color;
    b->focussed_up_text_color = current_icontext_button_theme->focussed_up_text_color;
    b->focussed_down_text_color = current_icontext_button_theme->focussed_down_text_color;
    b->clicked_up_text_color = current_icontext_button_theme->clicked_up_text_color;
    b->clicked_down_text_color = current_icontext_button_theme->clicked_down_text_color;
    b->normal_up_text_border_color = current_icontext_button_theme->normal_up_text_border_color;
    b->normal_down_text_border_color = current_icontext_button_theme->normal_down_text_border_color;
    b->disabled_up_text_border_color = current_icontext_button_theme->disabled_up_text_border_color;
    b->disabled_down_text_border_color = current_icontext_button_theme->disabled_down_text_border_color;
    b->focussed_up_text_border_color = current_icontext_button_theme->focussed_up_text_border_color;
    b->focussed_down_text_border_color = current_icontext_button_theme->focussed_down_text_border_color;
    b->clicked_up_text_border_color = current_icontext_button_theme->clicked_up_text_border_color;
    b->clicked_down_text_border_color = current_icontext_button_theme->clicked_down_text_border_color;
    b->text_font = current_icontext_button_theme->text_font;
    b->flags |= current_icontext_button_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_icontext_button_theme
 * DESCRIPTION
 *  Applies the given theme to an icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 *  t       [IN]        Is the theme to be applied
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icontext_button_theme(icontext_button *b, UI_icontext_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
    b->normal_up_text_color = t->normal_up_text_color;
    b->normal_down_text_color = t->normal_down_text_color;
    b->disabled_up_text_color = t->disabled_up_text_color;
    b->disabled_down_text_color = t->disabled_down_text_color;
    b->focussed_up_text_color = t->focussed_up_text_color;
    b->focussed_down_text_color = t->focussed_down_text_color;
    b->clicked_up_text_color = t->clicked_up_text_color;
    b->clicked_down_text_color = t->clicked_down_text_color;
    b->normal_up_text_border_color = t->normal_up_text_border_color;
    b->normal_down_text_border_color = t->normal_down_text_border_color;
    b->disabled_up_text_border_color = t->disabled_up_text_border_color;
    b->disabled_down_text_border_color = t->disabled_down_text_border_color;
    b->focussed_up_text_border_color = t->focussed_up_text_border_color;
    b->focussed_down_text_border_color = t->focussed_down_text_border_color;
    b->clicked_up_text_border_color = t->clicked_up_text_border_color;
    b->clicked_down_text_border_color = t->clicked_down_text_border_color;
    b->text_font = t->text_font;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_icontext_button_BG_theme
 * DESCRIPTION
 *  Applies the given button theme to an icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 *  t       [IN]        Is the button theme to be applied
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_icontext_button_BG_theme(icontext_button *b, UI_button_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_up_filler = t->normal_up_filler;
    b->normal_down_filler = t->normal_down_filler;
    b->disabled_up_filler = t->disabled_up_filler;
    b->disabled_down_filler = t->disabled_down_filler;
    b->focussed_up_filler = t->focussed_up_filler;
    b->focussed_down_filler = t->focussed_down_filler;
    b->clicked_up_filler = t->clicked_up_filler;
    b->clicked_down_filler = t->clicked_down_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_icontext_button
 * DESCRIPTION
 *  Creates an icontext button
 *  
 *  Note: Memory must be allocated to the button structure before
 *  being passed to this function.
 * PARAMETERS
 *  b               [IN]        Is the icontext button  (pre-allocated)
 *  x               [IN]        Is the position of the left-top corner of the button
 *  y               [IN]        Is the position of the left-top corner of the button
 *  width           [IN]        Is the width of the button
 *  height          [IN]        Is the height of the button
 *  text            [IN]        
 *  button_icon     [IN]        Is the icon to be used in the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_icontext_button(
        icontext_button *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type text,
        PU8 button_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->touch_area_x1 = 0;
    b->touch_area_y1 = 0;
    b->touch_area_x2 = width - 1;
    b->touch_area_y2 = height - 1;
    b->flags = 0;
    b->normal_down_icon = button_icon;
    b->normal_up_icon = button_icon;
    b->disabled_down_icon = button_icon;
    b->disabled_up_icon = button_icon;
    b->clicked_down_icon = button_icon;
    b->clicked_up_icon = button_icon;
    b->focussed_down_icon = button_icon;
    b->focussed_up_icon = button_icon;
    b->text = text;
    b->clear_background_fp = NULL;
    
    b->horizontal_gap = GUI_BUTTON_HORIZONTAL_GAP;
    
    /* set the theme of button eqaul to current theme */
    gui_set_icontext_button_current_theme(b);

    /* Autocalculate the icon position              */
    /* set font of text of button */
    gui_set_font(b->text_font);
    /* measure width and height of text */
    gui_measure_string(text, &sw, &sh);
    /* if button icon is not null */
    if (button_icon != UI_NULL_IMAGE)
    {
        S32 icon_width, icon_height;

        /* measure width and height of icon of button */
        gui_measure_image(button_icon, &icon_width, &icon_height);
        /* set x and y position of button icon */
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = 0;
        }
        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 0;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
    /* Autocalculate the text position based on font   */
    b->text_height = sh;
    /* set start x and y of text position of button */
    if (b->flags & UI_BUTTON_CENTER_TEXT_X)
    {
        b->text_x = (width >> 1) - (sw >> 1);
        if (b->text_x < 0)
        {
            if (r2lMMIFlag)
            {
                b->text_x = width - sw;
            }
            else
            {
                b->text_x = 0;
            }
        }
    }
    else
    {
        b->text_x = 0;
    }
    if (b->flags & UI_BUTTON_CENTER_TEXT_Y)
    {
        b->text_y = (height >> 1) - (sh >> 1);
    }
    else
    {
        b->text_y = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_icontext_button
 * DESCRIPTION
 *  Changes the size of an icontext button
 * PARAMETERS
 *  b           [IN]        Is the icon button
 *  width       [IN]        Is the new width of the button
 *  height      [IN]        Is the new height of the button
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_icontext_button(icontext_button *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;
    UI_font_type f = UI_font;
    S32 icon_width, icon_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;   /* width of button */
    b->height = height; /* height of button */
    
    /* Autocalculate the icon position              */
    if (b->normal_up_icon != UI_NULL_IMAGE)
    {
        /* measure width and height of button icon */
        gui_measure_image(b->normal_up_icon, &icon_width, &icon_height);
        /* set x and y position of button icon */
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = b->horizontal_gap;
        }
        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 2;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
    
    /* Autocalculate the text position based on font   */
    gui_set_font(b->text_font);             /* set font of text */
    gui_measure_string(b->text, &sw, &sh);  /* measure width and height of string */
    b->text_height = sh;
    b->text_width = sw;
    
    /* set start x and y position of text */
    if (b->flags & UI_BUTTON_CENTER_TEXT_X)
    {
        b->text_x = (width >> 1) - (sw >> 1);
        if (b->text_x < 0)
        {
            if (r2lMMIFlag)
            {
                b->text_x = width - sw;
            }
            else
            {
                b->text_x = 0;
            }
        }
    }
    else if (b->flags & UI_BUTTON_LEFT_ALIGN)
    {
        b->text_x = b->horizontal_gap;
    }
    else if (b->flags & UI_BUTTON_RIGHT_ALIGN)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (b->normal_up_icon != UI_NULL_IMAGE && mmi_frm_is_screen_width_height_swapped())
        {
            b->icon_x = width - icon_width - b->horizontal_gap;    
            b->text_x = b->icon_x - sw -1;
        }
        else
    #endif /*__MMI_SCREEN_ROTATE__*/
        {
        b->text_x = width - sw - b->horizontal_gap;
    }
    }
    else
    {
        b->text_x = 0;
    }
    
    if (b->text_x < 0)
    {
        b->text_x = 0;
    }
    
    if (b->flags & UI_BUTTON_CENTER_TEXT_Y)
    {
        /* Adjust the string position -- move down */
        b->text_y = 2 + ((height - 2) >> 1) - (sh >> 1);
    }
    else
    {
        b->text_y = 0;
    }
    
    gui_set_font(f);
    
    gui_icontext_button_get_display_area_ex(b, 
        &b->display_area_x1, 
        &b->display_area_y1, 
        &b->display_area_x2, 
        &b->display_area_y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_icontext_button
 * DESCRIPTION
 *  Changes the location of an icon button
 * PARAMETERS
 *  b       [IN]        Is the icon button
 *  x       [IN]        Is the new location
 *  y       [IN]        Is the new location
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_icontext_button(icontext_button *b, S32 x, S32 y)
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
 *  gui_icontext_button_set_icon_positon
 * DESCRIPTION
 *  Changes the position of the icon within the icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 *  x       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 *  y       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icontext_button_set_icon_positon(icontext_button *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->icon_x = x;
    b->icon_y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_set_text_position
 * DESCRIPTION
 *  Changes the position of the text within the icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 *  x       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 *  y       [IN]        Is the position of the icon (offset from the left-top corner of the button)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icontext_button_set_text_position(icontext_button *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_x = x;
    b->text_y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_set_icon
 * DESCRIPTION
 *  Changes the icon used in the icontext button
 *  
 *  See UI_transparent_color_type (Abstract type)
 * PARAMETERS
 *  b                           [IN]        Is the icontext button
 *  button_icon                 [IN]        
 *  icon_transparent_color      [IN]        Is the transparent color to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icontext_button_set_icon(
        icontext_button *b,
        PU8 button_icon,
        UI_transparent_color_type icon_transparent_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_down_icon = button_icon;
    b->normal_up_icon = button_icon;
    b->disabled_down_icon = button_icon;
    b->disabled_up_icon = button_icon;
    b->clicked_down_icon = button_icon;
    b->clicked_up_icon = button_icon;
    b->focussed_down_icon = button_icon;
    b->focussed_up_icon = button_icon;
    b->icon_transparent_color = icon_transparent_color;
    
    /* Autocalculate the icon position              */
    if (button_icon != UI_NULL_IMAGE)
    {
        S32 icon_width, icon_height;

        /* measure width and height of icon */
        gui_measure_image(button_icon, &icon_width, &icon_height);
        /* set x and y position of icon */
        if (b->flags & UI_BUTTON_CENTER_ICON_X)
        {
            b->icon_x = (b->width >> 1) - (icon_width >> 1);
        }
        else
        {
            b->icon_x = b->horizontal_gap;
        }

        if (b->flags & UI_BUTTON_CENTER_ICON_Y)
        {
            b->icon_y = (b->height >> 1) - (icon_height >> 1);
        }
        else
        {
            b->icon_y = 2;
        }
        b->icon_transparent_color = gui_transparent_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_icontext_button
 * DESCRIPTION
 *  Displays an icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_theme *current_MMI_theme;
void gui_show_icontext_button(icontext_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f;
    color text_color,border_color;
    PU8 button_icon;
    S32 ix, iy, tx, ty;
    S32 iwidth, iheight;
    UI_font_type font = UI_font;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;                  /* start x position of button */
    y1 = b->y;                  /* satrt y position of button */
    x2 = x1 + b->width - 1;     /* end x position of button */
    y2 = y1 + b->height - 1;    /* end y position of button */
    if (b->flags & UI_BUTTON_STATE_DISABLED)
    {
        return;        
    }
    else if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            if (b->flags & UI_BUTTON_NO_SHIFT_BUTTON)
            {
                /* No action */
            }	
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
            {
                x1 += 2;
                y1 += 2;
                x2 += 2;
                y2 += 2;
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
            {
                x1 += 1;
                y1 += 1;
                x2 += 1;
                y2 += 1;
            }
            f = b->clicked_down_filler;
            text_color = b->clicked_down_text_color;
            border_color = b->clicked_down_text_border_color;
            button_icon = b->clicked_down_icon;
        }
        else
        {
            f = b->clicked_up_filler;
            text_color = b->clicked_up_text_color;
            border_color = b->clicked_up_text_border_color;
            button_icon = b->clicked_up_icon;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_FOCUSSED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->focussed_down_filler;
            text_color = b->focussed_down_text_color;
            border_color = b->focussed_down_text_border_color;
            button_icon = b->focussed_down_icon;
        }
        else
        {
            f = b->focussed_up_filler;
            text_color = b->focussed_up_text_color;
            border_color = b->focussed_up_text_border_color;
            button_icon = b->focussed_up_icon;
        }
    }
    else
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            f = b->normal_down_filler;
            text_color = b->normal_down_text_color;
            border_color = b->normal_down_text_border_color;
            button_icon = b->normal_down_icon;
        }
        else
        {
            f = b->normal_up_filler;
            text_color = b->normal_up_text_color;
            border_color = b->normal_up_text_border_color;
            button_icon = b->normal_up_icon;
        }
    }
    gui_push_clip();
    if (!(b->flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY) && (f != NULL))
    {
        gui_set_clip(x1, y1, x2 + 2, y2 + 2);
        gui_draw_filled_area(x1, y1, x2, y2, f);
    }
    else
    {
        gui_set_clip(x1, y1, x2, y2);
    }

    ix = x1 + b->icon_x;
    iy = y1 + b->icon_y;
    if (button_icon != UI_NULL_IMAGE)
    {
        gui_show_transparent_image(ix, iy, button_icon, b->icon_transparent_color);
    }
    if (!(b->flags & UI_BUTTON_DISABLE_TEXT_DISPLAY))
    {
        S32 sw, sh;

        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);
        gui_set_text_color(text_color);
        gui_set_font(b->text_font);
        tx = x1 + b->text_x;
        ty = y1 + b->text_y;
        gui_measure_string(b->text, &sw, &sh);
        if (b->flags & UI_BUTTON_ALIGN_ICON_TEXT)
        {
            if (button_icon != UI_NULL_IMAGE)
            {
                gui_measure_image(button_icon, &iwidth, &iheight);      /* measure width and height of image */
                if ((ix - x1) < ((x2 - x1) >> 1))
                {
                    tx = ix + iwidth + 1;
                }
                else
                {
                    tx = ix - sw - 1;
                }
            }
        }

        gdi_layer_push_clip();

        gdi_layer_set_clip(tx, y1, tx + b->width - b->horizontal_gap - 1, y2);

        if (r2lMMIFlag)
        {
            tx += sw;
        }

        gui_move_text_cursor(tx, ty);   /* move cursor to x,y position */
        gui_set_line_height(sh);

        gui_set_text_border_color(border_color); /* set bordered colr */


        gui_print_bordered_text(b->text);   /* print bordered text on button */

        gdi_layer_pop_clip();
       
        gui_pop_text_clip();
    }
    gui_pop_clip();
    gui_set_font(font);
}


/***************************************************************************** 
 * FUNCTION
 *  gui_show_icontext_button
 * DESCRIPTION
 *  Displays an icontext button
 * PARAMETERS
 *  b       [IN]        Is the icontext button
 *  horizontal_gap  [IN]    Horizontal gap
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icontext_set_horizontal_gap(icontext_button *b, S32 horizontal_gap)
{
    b->horizontal_gap = horizontal_gap;
}


/***************************************************************************** 
 * Touch Screen Adaptation
 *****************************************************************************/

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_general_button_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object           [IN/OUT]         
 *  flags                   [IN]        
 *  pen_state               [IN/OUT]         
 *  button_x                [IN]        
 *  button_y                [IN]        
 *  button_width            [IN]        
 *  button_height           [IN]        
 *  draw_down_fp            [IN]        
 *  draw_up_fp              [IN]        
 *  clear_background_fp     [IN]        
 *  pen_event               [IN]        
 *  x                       [IN]        
 *  y                       [IN]        
 *  button_event            [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_general_button_translate_pen_event(
                void *button_object,
                U32 flags,
                gui_button_pen_state_struct *pen_state,
                S32 button_x,
                S32 button_y,
                S32 button_width,
                S32 button_height,
                void draw_down_fp(void*),
                void draw_up_fp(void*),
                gui_button_clear_background_hdlr clear_background_fp,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, button_x, button_y, button_width, button_height))
            {
                ret = MMI_TRUE;
                *button_event = GUI_BUTTON_PEN_DOWN;
                pen_state->pen_inside = MMI_TRUE;
                if (clear_background_fp)
                {
                    clear_background_fp(button_object);
                }
                draw_down_fp(button_object);
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_UP:
            if ((flags & UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE) ||
                PEN_CHECK_BOUND(x, y, button_x, button_y, button_width, button_height))
            {
                *button_event = GUI_BUTTON_PEN_UP_INSIDE;
            }
            else
            {
                *button_event = GUI_BUTTON_PEN_UP_OUTSIDE;
            }

            if (pen_state->pen_inside)
            {
                /* Even if the screen change, still need 'draw_up_fp' to set up states of button */
                if (clear_background_fp)
                {
                    clear_background_fp(button_object);
                }
                draw_up_fp(button_object);
            }
            pen_state->pen_inside = MMI_FALSE;  /* new change...on up event it should be set to 0 again */
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            *button_event = GUI_BUTTON_PEN_LONGTAP;
            break;

        case MMI_PEN_EVENT_REPEAT:
            if (pen_state->pen_inside)
            {
                *button_event = GUI_BUTTON_PEN_REPEAT;
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (PEN_CHECK_BOUND(x, y, button_x, button_y, button_width, button_height))
            {
                if (!pen_state->pen_inside)
                {
                    *button_event = GUI_BUTTON_PEN_MOVE_INSIDE;
                    pen_state->pen_inside = MMI_TRUE;
                    if (clear_background_fp)
                    {
                        clear_background_fp(button_object);
                    }
                    draw_down_fp(button_object);
                }
                else
                {
                    *button_event = GUI_BUTTON_PEN_NONE;
                }
            }
            else
            {
                if (pen_state->pen_inside)
                {
                    *button_event = GUI_BUTTON_PEN_MOVE_OUTSIDE;
                    pen_state->pen_inside = MMI_FALSE;
                    if (clear_background_fp)
                    {
                        clear_background_fp(button_object);
                    }
                    draw_up_fp(button_object);
                }
                else
                {
                    *button_event = GUI_BUTTON_PEN_NONE;
                }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            if (pen_state->pen_inside)
            {
                if (clear_background_fp)
                {
                    clear_background_fp(button_object);
                }
                draw_up_fp(button_object);
            }
            if (flags & UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE)
            {
                *button_event = GUI_BUTTON_PEN_UP_INSIDE;
            }
            else
            {
                *button_event = GUI_BUTTON_PEN_UP_OUTSIDE;
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_button_show_down_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_button_show_down_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    button *b = (button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_button_show_up_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_button_show_up_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    button *b = (button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_button_show_down_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_text_button_show_down_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    text_button *b = (text_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_text_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_button_show_up_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_text_button_show_up_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    text_button *b = (text_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_text_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_button_show_down_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_button_show_down_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icon_button *b = (icon_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_icon_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_button_show_up_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_button_show_up_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icon_button *b = (icon_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_icon_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_show_down_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icontext_button_show_down_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_icontext_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_show_up_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icontext_button_show_up_by_pen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);

    gui_show_icontext_button(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width - 1 + 2, b->y + b->height - 1 + 2);
}

/* Translate low-level pen events to high-level button events in button */


/*****************************************************************************
 * FUNCTION
 *  gui_button_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  button_event        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_button_translate_pen_event(
        button *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_general_button_translate_pen_event(
            b,
            b->flags,
            &b->pen_state,
            b->x,
            b->y,
            b->width,
            b->height,
            gui_button_show_down_by_pen,
            gui_button_show_up_by_pen,
            b->clear_background_fp,
            pen_event,
            x,
            y,
            button_event);
}

/* Translate low-level pen events to high-level button events in text button */


/*****************************************************************************
 * FUNCTION
 *  gui_text_button_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  button_event        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_text_button_translate_pen_event(
        text_button *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->text)
    {
        return MMI_FALSE;
    }

    return gui_general_button_translate_pen_event(
            b,
            b->flags,
            &b->pen_state,
            b->x,
            b->y,
            b->width,
            b->height,
            gui_text_button_show_down_by_pen,
            gui_text_button_show_up_by_pen,
            b->clear_background_fp,
            pen_event,
            x,
            y,
            button_event);
}

/* Translate low-level pen events to high-level button events in icon button */


/*****************************************************************************
 * FUNCTION
 *  gui_icon_button_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  button_event        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_icon_button_translate_pen_event(
        icon_button *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->normal_up_icon)
    {
        return MMI_FALSE;
    }

    return gui_general_button_translate_pen_event(
            b,
            b->flags,
            &b->pen_state,
            b->x,
            b->y,
            b->width,
            b->height,
            gui_icon_button_show_down_by_pen,
            gui_icon_button_show_up_by_pen,
            b->clear_background_fp,
            pen_event,
            x,
            y,
            button_event);
}

/* Translate low-level pen events to high-level button events in icon-text button */


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  button_event        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_icontext_button_translate_pen_event(
        icontext_button *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->text && !b->normal_up_icon)
    {
        return MMI_FALSE;
    }

    return gui_general_button_translate_pen_event(
            b,
            b->flags,
            &b->pen_state,
            b->touch_area_x1 + b->x,
            b->touch_area_y1 + b->y,
            b->touch_area_x2 - b->touch_area_x1 + 1,
            b->touch_area_y2 - b->touch_area_y1 + 1,
            gui_icontext_button_show_down_by_pen,
            gui_icontext_button_show_up_by_pen,
            b->clear_background_fp,
            pen_event,
            x,
            y,
            button_event);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_overwirte_pen_response_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN/OUT]         
 *  x1                  [IN]        
 *  y1                  [IN]     
 *  x2                  [IN]   
 *  y2                  [IN]   
 * RETURNS
 *  
 *****************************************************************************/
void gui_icontext_button_overwirte_pen_response_area(icontext_button *b, S32 x1, S32 y1, S32 x2, S32 y2)
{
    b->touch_area_x1 = x1 - b->x;
    b->touch_area_y1 = y1 - b->y;
    b->touch_area_x2 = x2 - b->x;
    b->touch_area_y2 = y2 - b->y;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_get_display_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                           [IN/OUT]         
 *  display_x1                  [IN]        
 *  display_y1                  [IN]     
 *  display_x2                  [IN]   
 *  display_y2                  [IN]   
 * RETURNS
 *  
 *****************************************************************************/
void gui_icontext_button_get_display_area(icontext_button *b, S32 *display_x1, S32 *display_y1, S32 *display_x2, S32 *display_y2)
{
    *display_x1 = b->display_area_x1;
    *display_y1 = b->display_area_y1;
    *display_x2 = b->display_area_x2;
    *display_y2 = b->display_area_y2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icontext_button_get_display_area_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                           [IN/OUT]         
 *  display_x1                  [IN]        
 *  display_y1                  [IN]     
 *  display_x2                  [IN]   
 *  display_y2                  [IN]   
 * RETURNS
 *  
 ****************************************************************************/
static void gui_icontext_button_get_display_area_ex(icontext_button *b, S32 *display_x1, S32 *display_y1, S32 *display_x2, S32 *display_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    PU8 button_icon;
    S32 ix, iy, tx, ty;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;                  /* start x position of button */
    y1 = b->y;                  /* satrt y position of button */
    x2 = x1 + b->width - 1;     /* end x position of button */
    y2 = y1 + b->height - 1;    /* end y position of button */

    *display_x1 = 0;
    *display_y1 = 0;
    *display_x2 = 0;
    *display_y2 = 0;
    
    if (b->flags & UI_BUTTON_STATE_DISABLED)
    {
        return;        
    }
    else if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            if (b->flags & UI_BUTTON_NO_SHIFT_BUTTON)
            {
                /* No action */
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
            {
                x1 += 2;
                y1 += 2;
                x2 += 2;
                y2 += 2;
            }
            else if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
            {
                x1 += 1;
                y1 += 1;
                x2 += 1;
                y2 += 1;
            }
            button_icon = b->clicked_down_icon;
        }
        else
        {
            button_icon = b->clicked_up_icon;
        }
    }
    else if (b->flags & UI_BUTTON_STATE_FOCUSSED)
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            button_icon = b->focussed_down_icon;
        }
        else
        {
            button_icon = b->focussed_up_icon;
        }
    }
    else
    {
        if (b->flags & UI_BUTTON_STATE_DOWN)
        {
            button_icon = b->normal_down_icon;
        }
        else
        {
            button_icon = b->normal_up_icon;
        }
    }

    ix = x1 + b->icon_x;
    iy = y1 + b->icon_y;

    if (button_icon != UI_NULL_IMAGE)
    {
        gui_measure_image(button_icon, &iwidth, &iheight);    
        *display_x1 = ix;
        *display_y1 = iy;
        *display_x2 = ix + iwidth - 1;
        *display_y2 = iy + iheight - 1;
    }

    if (!(b->flags & UI_BUTTON_DISABLE_TEXT_DISPLAY))
    {
        S32 sw, sh;

        gui_set_font(b->text_font);
        tx = x1 + b->text_x;
        ty = y1 + b->text_y;
        gui_measure_string(b->text, &sw, &sh);
        if (b->flags & UI_BUTTON_ALIGN_ICON_TEXT)
        {
            if (button_icon != UI_NULL_IMAGE)
            {
                if ((ix - x1) < ((x2 - x1) >> 1))
                {
                    tx = ix + iwidth + 1;
                }
                else
                {
                    tx = ix - sw - 1;
                }
            }
        }

        if (button_icon == UI_NULL_IMAGE)
        {
            *display_x1 = tx;
            *display_y1 = ty;
        }

        if (r2lMMIFlag)
        {
            tx += sw;

            if (tx > *display_x2)
            {
                *display_x2 = tx;
            }   
        }
        else
        {
            *display_x2 = tx + sw - 1;
        }   

        if (y1 < *display_y1)
        {
            *display_y1 = y1;
        }

        if ( y1 + sh - 1 > *display_y2)
        {
            *display_y2 = y1 + sh - 1;
        }
    }
}


