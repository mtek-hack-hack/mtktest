/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_hint_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_themes.h"
#include "wgui_hint_pre_oem.h"
#include "wgui_hint_post_oem.h"

void gui_show_pop_up_description_oem(UI_pop_up_description *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 text_x, text_y;
    S32 i, sw, sh, text_width;
    color text_color = b->text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;
    y1 = b->y;
    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;
    /* MTK Elvis for R2L characters */
    if (!r2lMMIFlag)
    {
        text_x = b->text_x + b->scroll_x;
    }
    else
    {
        text_x = b->width - (b->text_x + b->scroll_x);
    }
    /* MTK end */
    text_y = b->text_y;

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    if (b->transition_step > 0)
    {
        text_color = gui_blend_two_color(
                        text_color,
                        b->background_filler->c,
                        MAX_POP_UP_DESCRIPTION_TRANSITION_STEPS - b->transition_step + (MAX_POP_UP_DESCRIPTION_TRANSITION_STEPS / 3),
                        b->transition_step);
    }
#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 

#ifdef UI_POPUP_DESCRIPTION_STYLE_3
    /* Support image in popup description for more flexible theme */
    if ((b->background_filler->flags & UI_FILLED_AREA_MASK_TYPE) != UI_FILLED_AREA_TYPE_BITMAP)
    {
        if (b->flags & UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM)
        {
            b->background_filler->flags = UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE2;
        }
        else
        {
            b->background_filler->flags = UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1;
            text_y += 3;
        }
    }
#endif /* UI_POPUP_DESCRIPTION_STYLE_3 */ 

    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, b->background_filler);
    gui_push_text_clip();
    gui_set_text_clip(x1 + 2, y1 + 2, x2 - 3, y2 - 2);
#if(UI_USE_WORD_SCROLLING_TEXT)
    text_width = x2 - 3 - (x1 + 2) + 1;
#else 
    text_width = b->text_width;
#endif 
    gui_set_text_color(text_color);
    gui_set_font(b->text_font);
    for (i = 0; i < b->n_strings; i++)
    {
        if (b->text_strings[i] != NULL)
        {
            gui_measure_string(b->text_strings[i], &sw, &sh);
            gui_move_text_cursor(x1 + text_x, y1 + text_y);
            gui_set_line_height(sh);
        #if(UI_USE_WORD_SCROLLING_TEXT)
            if (b->flags & UI_POP_UP_DESCRIPTION_DISPLAY_SCROLL)
            {
                GUI_current_pop_up_description_scroll_text_end[i] = GUI_current_pop_up_description_scroll_text[i];
            }
            else
            {
                GUI_current_pop_up_description_scroll_text_end[i] = b->text_strings[i];
            }
            if (gui_print_truncated_text2
                (x1 + text_x, y1 + text_y, text_width, &GUI_current_pop_up_description_scroll_text_end[i]))
            {
                GUI_current_pop_up_description_scroll_text_end[i] = b->text_strings[i];
            }
        #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
            gui_print_text(b->text_strings[i]);
            if (b->flags & UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL)
            {
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x1 + text_x - (text_width + UI_TEXT_MENUITEM_SCROLL_GAP), y1 + text_y);
                }
                else
                {
                    gui_move_text_cursor(x1 + text_x + text_width + UI_TEXT_MENUITEM_SCROLL_GAP, y1 + text_y);
                }

                gui_set_line_height(sh);
                gui_print_text(b->text_strings[i]);
            }
        #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
            text_y += sh;
        }
    }
    gui_pop_text_clip();
    gui_pop_clip();
}
