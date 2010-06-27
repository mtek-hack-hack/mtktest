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
 * widget_paint_gadget_bar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfBarGadget paint routines
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "gui_scrollbars.h"

extern kal_int16 widget_get_scrollbar_width(void);

/****************************************************************
 paint bar
***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_paint_gadget_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bar             [?]         
 *  size            [?]         
 *  pos             [?]         
 *  force_paint     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_gadget_bar(widget_gadget_bar_struct *bar, MsfSize *size, MsfPosition *pos, kal_bool force_paint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Note that we don't record range for scrollbar
     */

    switch (bar->bar_type)
    {
        case MsfInteractiveBar:
            break;
        case MsfProgressBar:
        {
            horizontal_progress_indicator b;

            gui_create_horizontal_progress_indicator(
                &b,
                pos->x + bar->position.x,
                pos->y + bar->position.y,
                bar->size.width,
                bar->size.height);

            widget_record_used_range(
                _H(bar),
                KAL_FALSE,
                KAL_FALSE,
                pos->x + bar->position.x,
                pos->y + bar->position.y,
                pos->x + bar->position.x + bar->size.width,
                pos->y + bar->position.y + bar->size.height);

            gui_set_horizontal_progress_indicator_range(&b, bar->max_value);
            gui_set_horizontal_progress_indicator_value(&b, bar->value);
            gui_show_horizontal_progress_indicator(&b);
        }
            break;
        case MsfVerticalScrollBar:
            WGUI_CTX->current_vertical_scrollbar = bar;

            if (force_paint)
            {
                vertical_scrollbar *b;
                S32 bar_x, bar_y, bar_width, bar_height, bar_scale;

            #ifdef __MMI_TOUCH_SCREEN__
                b = &WGUI_CTX->vbar;
            #else /* __MMI_TOUCH_SCREEN__ */ 
                vertical_scrollbar tmp_vbar;

                b = &tmp_vbar;
            #endif /* __MMI_TOUCH_SCREEN__ */ 

                if (WGUI_CTX->in_paintbox)
                {
                    bar_x = pos->x + bar->position.x;
                    bar_y = pos->y + bar->position.y;
                }
                else
                {
                    /* scrollbar is not moved as the MsfForm window scroll */
                    bar_x = bar->position.x + WGUI_CTX->display_pos.x;
                    bar_y = bar->position.y + WGUI_CTX->display_pos.y;
                }
                bar_width = bar->size.width;
                bar_height = bar->size.height;

                /*
                 * If the window has horizontal and vertical scroll-bar,
                 * the scale of vertical scroll bar need to decrease 
                 * the horizontal scroll bar's height.
                 */
                if (WGUI_CTX->current_horizontal_scrollbar != 0)
                {
                    bar_scale = bar_height - (S32) widget_get_scrollbar_width();
                }
                else
                {
                    bar_scale = bar_height;
                }

            #ifdef __MMI_TOUCH_SCREEN__
                if (_H(bar) != WPEN_CTX->handler)
                {
                    S32 min_offset = bar->max_value / 15;

                    gui_create_vertical_scrollbar(b, bar_x, bar_y, bar_width, bar_height);

                    if (bar->pen_min_offset > -1)
                    {
                        gui_vertical_scrollbar_set_minimum_pen_offset(b, bar->pen_min_offset);
                    }
                    else
                    {
                        gui_vertical_scrollbar_set_minimum_pen_offset(b, min_offset > 20 ? 20 : min_offset);
                    }

                    /* Scroll scrollbar async to the display content */
                    gui_vertical_scrollbar_set_pen_self_scroll(b, MMI_TRUE);
                    gui_set_vertical_scrollbar_range(b, bar->max_value);
                    gui_set_vertical_scrollbar_value(b, bar->value);
                    gui_set_vertical_scrollbar_scale(b, bar_scale);
                }
                else
                {
                    /* Pen still tapped down on the scrollbar */
                    gui_set_vertical_scrollbar_value(b, bar->value);
                }
            #else /* __MMI_TOUCH_SCREEN__ */ 
                gui_create_vertical_scrollbar(b, bar_x, bar_y, bar_width, bar_height);
                gui_set_vertical_scrollbar_range(b, bar->max_value);
                gui_set_vertical_scrollbar_value(b, bar->value);
                gui_set_vertical_scrollbar_scale(b, bar_scale);

			#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
                if (WGUI_CTX->in_paintbox)
                {
                    kal_bool flag = KAL_FALSE;
                    gui_scrollbar_buttton_enum button_type;
                    int currKeyCode = WGUI_CTX->scrollbar_indication_info & 0xFF;
                    int currKeyType = WGUI_CTX->scrollbar_indication_info >> 8;

                    if (currKeyCode == KEY_UP_ARROW)
                    {
                        flag = KAL_TRUE;
                        button_type = GUI_SCROLLBAR_BUTTON_UP;
                    }
                    if (currKeyCode == KEY_DOWN_ARROW)
                    {
                        flag = KAL_TRUE;
                        button_type = GUI_SCROLLBAR_BUTTON_DOWN;
                    }
                    if (flag && WGUI_CTX->allow_to_update_scrollbar_indication)
                    {
                        gui_vertical_scrollbar_redraw_button(b, button_type, MMI_TRUE);
                        widget_stop_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER);
                        widget_start_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER, widget_paint_scrollbar_ind_hdlr, NULL, WIDGET_PAINTBOX_SCROLL_INDICATION_DELAY_TIMER);
                    }

                }
                WGUI_CTX->v_scrollbar_value = bar->value;
			#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */
            #endif /* __MMI_TOUCH_SCREEN__ */ 
                gui_show_vertical_scrollbar(b);
            }

            break;
        case MsfHorizontalScrollBar:
            WGUI_CTX->current_horizontal_scrollbar = bar;

            if (force_paint)
            {
                horizontal_scrollbar *b;
                S32 bar_x, bar_y, bar_width, bar_height;

            #ifdef __MMI_TOUCH_SCREEN__
                b = &WGUI_CTX->hbar;
            #else /* __MMI_TOUCH_SCREEN__ */ 
                horizontal_scrollbar tmp_hbar;

                b = &tmp_hbar;
            #endif /* __MMI_TOUCH_SCREEN__ */ 

                if (WGUI_CTX->in_paintbox)
                {
                    bar_x = pos->x + bar->position.x;
                    bar_y = pos->y + bar->position.y;
                }
                else
                {
                    /* scrollbar is not moved as the MsfForm window scroll */
                    bar_x = bar->position.x + WGUI_CTX->display_pos.x;
                    bar_y = bar->position.y + WGUI_CTX->display_pos.y;
                }
                bar_width = bar->size.width;
                bar_height = bar->size.height;

            #ifdef __MMI_TOUCH_SCREEN__
                if (_H(bar) != WPEN_CTX->handler)
                {
                    S32 min_offset = bar->max_value / 15;

                    gui_create_horizontal_scrollbar(b, bar_x, bar_y, bar_width, bar_height);

                    if (bar->pen_min_offset > -1)
                    {
                        gui_horizontal_scrollbar_set_minimum_pen_offset(b, bar->pen_min_offset);
                    }
                    else
                    {
                        gui_horizontal_scrollbar_set_minimum_pen_offset(b, min_offset > 20 ? 20 : min_offset);
                    }

                    /* Scroll scrollbar async to the display content */
                    gui_horizontal_scrollbar_set_pen_self_scroll(b, MMI_TRUE);
                    gui_set_horizontal_scrollbar_range(b, bar->max_value);
                    gui_set_horizontal_scrollbar_value(b, bar->value);
                    gui_set_horizontal_scrollbar_scale(b, bar_width);
                }
                else
                {
                    /* Pen still tapped down on the scrollbar */
                    gui_set_horizontal_scrollbar_value(b, bar->value);
                }
            #else /* __MMI_TOUCH_SCREEN__ */ 
                gui_create_horizontal_scrollbar(b, bar_x, bar_y, bar_width, bar_height);
                gui_set_horizontal_scrollbar_range(b, bar->max_value);
                gui_set_horizontal_scrollbar_value(b, bar->value);
                gui_set_horizontal_scrollbar_scale(b, bar_width);
			#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
                if (WGUI_CTX->in_paintbox)
                {
                    kal_bool flag = KAL_FALSE;
                    gui_scrollbar_buttton_enum button_type;
                    int currKeyCode = WGUI_CTX->scrollbar_indication_info & 0xFF;
                    int currKeyType = WGUI_CTX->scrollbar_indication_info >> 8;

                    if (currKeyCode == KEY_LEFT_ARROW)
                    {
                        flag = KAL_TRUE;
                        button_type = GUI_SCROLLBAR_BUTTON_LEFT;
                    }
                    if (currKeyCode == KEY_RIGHT_ARROW)
                    {
                        flag = KAL_TRUE;
                        button_type = GUI_SCROLLBAR_BUTTON_RIGHT;
                    }
                    if (flag && WGUI_CTX->allow_to_update_scrollbar_indication)
                    {
                        gui_horizontal_scrollbar_redraw_button(b, button_type, MMI_TRUE);

                        widget_stop_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER);
                        widget_start_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER, widget_paint_scrollbar_ind_hdlr, NULL, WIDGET_PAINTBOX_SCROLL_INDICATION_DELAY_TIMER);
                    }
                }
                WGUI_CTX->h_scrollbar_value = bar->value;
			#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */
            #endif /* __MMI_TOUCH_SCREEN__ */ 
                gui_show_horizontal_scrollbar(b);
            }

            break;
    }
}

