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
 * widget_paint_gadget_string.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfStringGadget paint routines
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
/****************************************************************
 paint string
***************************************************************/

/* Reference: HDIa_widgetDrawString() & widget_MMI_paint_blinking_object() */


/*****************************************************************************
 * FUNCTION
 *  widget_paint_gadget_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gstr        [?]     
 *  size        [?]     
 *  pos         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_gadget_string(widget_gadget_string_struct *gstr, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Multiline string gadget will not use this function */
    widget_style_struct *style;
    color fg_color;
    kal_bool is_key_focus;
    int x1, y1, x2, y2, pos_x, pos_y, text_y;
    int bound_x1, bound_x2, bound_y1, bound_y2;
    stFontAttribute pfont;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gstr->text)
    {
        return;
    }

    style = _STYLE(widget_get_style((MSF_UINT32) gstr));
    pfont = widget_convert_to_system_font(&style->font);
    SetFont(pfont, 0);

    gui_measure_string((UI_string_type) widget_string_content(gstr->text), &str_width, &str_height);

    /* TODO: we should move it to HDIa_widgetStringGadgetCreate */
    if (gstr->size.width < (MSF_INT16) str_width)
    {
        gstr->size.width = (MSF_INT16) str_width;
    }
    if (gstr->size.height < (MSF_INT16) str_height + WIDGET_FONT_BOTTOM_SPACING)
    {
        gstr->size.height = (MSF_INT16) str_height + WIDGET_FONT_BOTTOM_SPACING;
    }

    pos_x = x1 = pos->x + gstr->position.x;
    pos_y = y1 = pos->y + gstr->position.y;
    x2 = x1 + gstr->size.width - 1;
    y2 = y1 + gstr->size.height - 1;

    /* Region and Focus */
    if (WGUI_CTX->in_paintbox)
    {
        is_key_focus = widget_register_keyfocus(_H(gstr));
    }
    else
    {
        kal_bool is_want_focus = widget_form_gadget_want_focus(_H(gstr));

        is_key_focus = is_want_focus ? widget_register_keyfocus(_H(gstr)) : KAL_FALSE;

        widget_record_used_range(_H(gstr), is_want_focus, is_key_focus, x1, y1, x2, y2);
    }

    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);
    if (!widget_clipping_intersection(&x1, &y1, &x2, &y2, bound_x1, bound_y1, bound_x2, bound_y2))
    {
        return; /* string gadget out of content region */
    }

    /* 
     * Align text to the bottom of the gadget.
     * Please refer to HDIa_widgetFontGetValues:  font height known by BRS is 
     * WIDGET_FONT_TOP_SPACING + WIDGET_FONT_BOTTOM_SPACING + Get_CharHeightOfAllLang() 
     */
    text_y = pos_y + gstr->size.height - WIDGET_FONT_BOTTOM_SPACING - str_height;

    gui_move_text_cursor(pos_x, text_y);

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);

    fg_color = gui_color((U8) style->fg_color.r, (U8) style->fg_color.g, (U8) style->fg_color.b);
    gui_set_text_color(fg_color);

    gui_print_text((UI_string_type) widget_string_content(gstr->text));

    /* Text attributes */
    if (style->text_property.decoration & MSF_TEXT_DECORATION_UNDERLINE)
    {
        gui_draw_horizontal_line(x1, x2, text_y + str_height, fg_color);
    }

    if (style->text_property.decoration & MSF_TEXT_DECORATION_BLINK)
    {
    #if 0   /* BRS might already change the background color of paintbox */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        /*
         * Tmp fix of BRS set background attribute of string gadget.
         * * However. in order to support blinking on background image, we 
         * * should adopt GDI layer support
         */
        widget_setup_blinking(gstr, style->bg_color);
    }

    /* Border */
    if (!WGUI_CTX->in_paintbox && is_key_focus)
    {
        widget_form_draw_border(_H(gstr), pos_x, pos_y, pos_x + gstr->size.width - 1, pos_y + gstr->size.height - 1);
    }
}

/****************************************************************
 *  Blinking text 
 *
 * (Reference: Marquee)
 ***************************************************************/

static kal_bool widget_enqueue_blinking(widget_gadget_string_struct *gstr);
static kal_bool widget_dequeue_blinking(widget_gadget_string_struct *gstr);
static kal_bool widget_has_blinking_text_displayed(void);
static void widget_MMI_paint_blinking_hdlr(void);
static void widget_paint_blinking_hdlr(void *arg);
static void widget_start_blinking_animation(void);
static void widget_stop_blinking_animation(void);

/* En-queue to WGUI_CTX->blinking_head */


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_blinking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gstr        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_enqueue_blinking(widget_gadget_string_struct *gstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_string_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We need to check the existence first */
    curr = WGUI_CTX->blinking_head;
    while (curr)
    {
        if (curr == gstr)
        {
            return KAL_FALSE;
        }
        curr = curr->blinking_next;
    }

    /* Insert it */
    WAP_DBG_ASSERT(gstr->blinking_next == NULL);
    gstr->blinking_next = WGUI_CTX->blinking_head;
    WGUI_CTX->blinking_head = gstr;
    return KAL_TRUE;
}

/* De-queue from WGUI_CTX->marquee_head */


/*****************************************************************************
 * FUNCTION
 *  widget_dequeue_blinking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gstr        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_dequeue_blinking(widget_gadget_string_struct *gstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_string_struct *curr, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gstr);

    if (WGUI_CTX->blinking_head == gstr)
    {
        WGUI_CTX->blinking_head = gstr->blinking_next;
        gstr->blinking_next = NULL;
        return KAL_TRUE;
    }

    prev = WGUI_CTX->blinking_head;
    curr = prev->blinking_next;

    while (curr)
    {
        if (curr == gstr)
        {
            prev->blinking_next = gstr->blinking_next;
            gstr->blinking_next = NULL;
            return KAL_TRUE;
        }
        prev = curr;
        curr = curr->blinking_next;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_has_blinking_text_displayed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_has_blinking_text_displayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_string_struct *curr = WGUI_CTX->blinking_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr)
    {
        ASSERT(curr->blinking);
        if (curr->blinking->displayed)
        {
            return KAL_TRUE;
        }

        curr = curr->blinking_next;
    }
    return KAL_FALSE;
}

/*
 * Timer handler of blinking text animation 
 * * Reference: widget_paint_gadget_string
 */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_blinking_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gstr            [?]     
 *  blinking        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_blinking_object(widget_gadget_string_struct *gstr, widget_blinking_struct *blinking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We do not paint outside look, and we need to clip region to content size */
    widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) gstr));
    int x1, y1, x2, y2, pos_x, pos_y, text_y;
    stFontAttribute pfont;
    color fg_color;
    int bound_x1, bound_x2, bound_y1, bound_y2;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos_x = x1 = WGUI_CTX->current_pos.x + gstr->position.x;
    pos_y = y1 = WGUI_CTX->current_pos.y + gstr->position.y;
    x2 = x1 + gstr->size.width - 1;
    y2 = y1 + gstr->size.height - 1;

    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);
    if (!widget_clipping_intersection(&x1, &y1, &x2, &y2, bound_x1, bound_y1, bound_x2, bound_y2))
    {
        return; /* string gadget out of content region */
    }

    if (WGUI_CTX->blinking_on)
    {
        if (gstr->text)
        {
            gui_lock_double_buffer();

            gui_push_clip();
            gui_push_text_clip();

            pfont = widget_convert_to_system_font(&style->font);
            SetFont(pfont, 0);
            gui_measure_string((UI_string_type) widget_string_content(gstr->text), &str_width, &str_height);

            if (str_height + WIDGET_FONT_BOTTOM_SPACING > gstr->size.height)
            {
                WAP_DBG_ASSERT(0);  /* Unexpected. 'str_height' should be less than (str_height + WIDGET_FONT_BOTTOM_SPACING) */
                text_y = pos_y;
            }
            else
            {
                text_y = pos_y + gstr->size.height - WIDGET_FONT_BOTTOM_SPACING - str_height;
            }

            gui_set_text_clip(x1, y1, x2, y2);
            gui_set_clip(x1, y1, x2, y2);

            fg_color = gui_color((U8) style->fg_color.r, (U8) style->fg_color.g, (U8) style->fg_color.b);
            gui_set_text_color(fg_color);
            gui_move_text_cursor(pos_x, text_y);

            gui_print_text((UI_string_type) widget_string_content(gstr->text));
            if (style->text_property.decoration & MSF_TEXT_DECORATION_UNDERLINE)
            {
                gui_draw_horizontal_line(x1, x2, text_y + str_height, fg_color);
            }

            gui_pop_text_clip();
            gui_pop_clip();

            gui_unlock_double_buffer();
            gui_BLT_double_buffer(x1, y1, x2, y2);
        }
    }
    else
    {
        color bg_color;

        gui_lock_double_buffer();

        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);

        bg_color = gui_color((U8) blinking->bgcolor.r, (U8) blinking->bgcolor.g, (U8) blinking->bgcolor.b);

        gui_fill_rectangle(x1, y1, x2, y2, bg_color);

        gui_pop_clip();

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_blinking_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_blinking_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_string_struct *gstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_blinking_text_displayed())
    {
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_BLINKING_HDLR);

    gstr = WGUI_CTX->blinking_head;
    while (gstr)
    {
        ASSERT(gstr->blinking);
        WAP_DBG_ASSERT(IS_GADGET_STRING_TYPE(gstr));

        /* Paint it */
        if (gstr->blinking->displayed)
        {
            widget_MMI_paint_blinking_object(gstr, gstr->blinking);
        }

        gstr = gstr->blinking_next;
    }

    if (WGUI_CTX->blinking_on)
    {
        WGUI_CTX->blinking_on = KAL_FALSE;
    }
    else
    {
        WGUI_CTX->blinking_on = KAL_TRUE;
    }

    widget_start_blinking_animation();
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_blinking_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paint_blinking_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_blinking_text_displayed())
    {
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    widget_execute_MMI(widget_MMI_paint_blinking_hdlr, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_start_blinking_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_start_blinking_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_blinking_text_displayed())
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    widget_start_timer(WIDGET_BLINKING_TIMER, widget_paint_blinking_hdlr, NULL, WIDGET_BLINKING_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_blinking_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_stop_blinking_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_stop_timer(WIDGET_BLINKING_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  widget_setup_blinking
 * DESCRIPTION
 *  Setup blinking information of a string gadget
 * PARAMETERS
 *  gstr        [?]         
 *  bgcolor     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_blinking(widget_gadget_string_struct *gstr, MsfColor bgcolor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gstr->blinking)
    {
        gstr->blinking = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_blinking_struct));
        gstr->blinking->displayed = 1;
        gstr->blinking->bgcolor = bgcolor;

        res = widget_enqueue_blinking(gstr);
        WAP_DBG_ASSERT(res);
    }
    else
    {
        gstr->blinking->displayed = 1;
        gstr->blinking->bgcolor = bgcolor;
    }

    widget_start_blinking_animation();
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_all_blinking
 * DESCRIPTION
 *  Stop all blinking text when repaint or exit widget screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_all_blinking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_string_struct *curr = WGUI_CTX->blinking_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr)
    {
        ASSERT(curr->blinking);
        curr->blinking->displayed = 0;
        curr = curr->blinking_next;
    }

    WAP_DBG_ASSERT(!widget_has_blinking_text_displayed());  /* Be paranoid */
    widget_stop_blinking_animation();
}


/*****************************************************************************
 * FUNCTION
 *  widget_remove_blinking
 * DESCRIPTION
 *  When deleting a string gadget
 * PARAMETERS
 *  gstr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_remove_blinking(widget_gadget_string_struct *gstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gstr->blinking)
    {
        kal_bool res;

        res = widget_dequeue_blinking(gstr);
        WAP_DBG_ASSERT(res);

        MSF_MEM_FREE(MSF_MODID_WIDGET, gstr->blinking);
        gstr->blinking = NULL;

        if (!widget_has_blinking_text_displayed())
        {
            widget_stop_blinking_animation();
        }
    }
}

