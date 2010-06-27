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
 * widget_paint_gadget_input.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfInputGadget paint routines
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
 *==============================================================================
 *******************************************************************************/

/*
 * Input gadget
 * * We have two modes: inplace multiline edit & fullscreen editor
 * *
 * * Bugs:
 * * o inplace multiline edit doesn't check CSS when exiting edit (However, MsfText is fullscreen editor)
 * * o inplace multiline edit doesn't restore original input when cancel (i.e. RSK when no text)
 * *
 * * Todo:
 * * o prevent manipulating internal data structures of Pixtel MMI
 * * o maybe we should change all inplace multiline edit to inline input & fullscreen editor
 * * o implement CSS as a MMI category
 */

#include "widget.h"
#include "app_str.h"

#include "gdi_datatype.h"
#include "gdi_include.h"

#include "gui_data_types.h"
#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "wgui_inputs.h"

/* 
 * global variables (maybe we should move it to mobile_suite_app.c)
 */

static kal_uint8 backup_editor_buffer[STR_SIZE(WIDGET_MAX_INPUT_LEN + 1)];

/*
 * Declaration of static functions
 */


/*****************************************************************************
 * FUNCTION
 *  widget_init_paint_input_gadget
 * DESCRIPTION
 *  initialize global variables of input module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_paint_input_gadget()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FIXME. move backup_editor_buffer to mobile_suite_app.c and use widget_init_fullscreen_editor */
    backup_editor_buffer[0] = 0;
    backup_editor_buffer[1] = 0;
}

/////////////////////////////////////////////////////////////////////////
// backup the editor buffer
/////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  widget_backup_editor_buffer
 * DESCRIPTION
 *  restore with the buffer of original input text
 * PARAMETERS
 *  src     [IN]     -  buffer to backup
 * RETURNS
 *  void
 *****************************************************************************/
void widget_backup_editor_buffer(kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: use widget_ucs2_strncpy
    for (pos = 0; CHR_AT(src, pos) && pos < WIDGET_MAX_INPUT_LEN - 1; pos++)    /* FIXME maxlen is WIDGET_MAX_INPUT_LEN */
    {
        SET_CHR_AT(backup_editor_buffer, pos, CHR_AT(src, pos));
    }
    SET_CHR_AT(backup_editor_buffer, pos, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_restore_editor_buffer
 * DESCRIPTION
 *  restore with the buffer of original input text
 * PARAMETERS
 *  dest        [OUT]     -  output
 * RETURNS
 *  void
 *****************************************************************************/
void widget_restore_editor_buffer(kal_uint8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pos = 0; CHR_AT(backup_editor_buffer, pos) && pos < WIDGET_MAX_INPUT_LEN - 1; pos++)
    {
        SET_CHR_AT(dest, pos, CHR_AT(backup_editor_buffer, pos));
    }
    SET_CHR_AT(dest, pos, CHR(0));
}


/*****************************************************************************
 * FUNCTION
 *  widget_discard_editor_buffer
 * DESCRIPTION
 *  drop the buffer of original input text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_discard_editor_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    backup_editor_buffer[0] = 0;
    backup_editor_buffer[1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_temp_editor_buffer
 * DESCRIPTION
 *  Use backup_editor_buffer temporarily for other purpose
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *widget_get_temp_editor_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return backup_editor_buffer;
}


/////////////////////////////////////////////////////////////////////////////
// readonly input 
/////////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  widget_readonly_multiline_inputbox_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_readonly_multiline_inputbox_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);

    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    gui_BLT_double_buffer(
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
}


/*****************************************************************************
 * FUNCTION
 *  widget_readonly_multiline_inputbox_previous_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_readonly_multiline_inputbox_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);

    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    gui_BLT_double_buffer(
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
}

/*****************************************************************************
 * Misc. function related to setup of multiline input gadget
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_multiline_inputbox_set_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN]         
 *  is_mask     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_multiline_inputbox_set_mask(multi_line_input_box *b, kal_bool is_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_bit_flag(b->flags, UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS, is_mask);
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_gadget_input
 * DESCRIPTION
 *  main routine to draw input gadget, set keyboard handler, and enter fullscreen editor if necessary
 * PARAMETERS
 *  inp         [IN]     -  input gadget
 *  size        [IN]     -  default size
 *  pos         [IN]     -  absolute position
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_gadget_input(widget_gadget_input_struct *inp, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO: Because we use full-screen editor to edit internal data, we do not need to separate multi_line_input_box variables.
    multi_line_input_box *b, B;
    void *buffer;
    int text_length;
    kal_bool is_key_focus;
    kal_bool is_selected_in_paintbox = KAL_FALSE;   /* Check displaying cursor or not */
    int bound_x1, bound_x2, bound_y1, bound_y2;
    widget_style_struct *style = (widget_style_struct*) widget_get_style((MSF_UINT32)inp);
    gdi_color fg_color = gdi_act_color_from_rgb(255, style->fg_color.r, style->fg_color.g, style->fg_color.b);
    kal_uint32 c_r, c_g, c_b, c_a;

    UI_font_type old_font;  /* restore the default font */
    stFontAttribute fontdata;
    stFontAttribute pfont;
    color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_gadget_in_form(size, &inp->position, &inp->size))
    {
        return;
    }
    if (inp->index != -1)
    {
        /* If the inputbox in the dialog, we don't show it in the browser */
        return;
    }

    /* fetch the raw data */
    buffer = widget_string_content(inp->text);
    text_length = STR_LEN((const char*)buffer);

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ 
    /* initialize CSS pattern; We will check the inputbox content is valid in WCSS format */
    widget_init_input_CSS_pattern((const char *)inp->format_pattern);
    {
        /* Adjust the WCSS input box length */
        kal_uint8* tmp_buf = NULL;

        tmp_buf = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (WIDGET_MAX_INPUT_LEN + 1)*ENCODING_LENGTH);
        widget_set_wcss_input_format_default_value(
            (kal_uint8*) tmp_buf,
            &(inp->input_max_size),
            (const char*)inp->format_pattern);
        MSF_MEM_FREE(MSF_MODID_WIDGET, tmp_buf);
        if (inp->input_max_size > WIDGET_MAX_INPUT_LEN)
        {
            /* The max size is WIDGET_MAX_INPUT_LEN */
            inp->input_max_size = WIDGET_MAX_INPUT_LEN;
        }
    }
    if (widget_is_match_CSS_pattern(buffer) == KAL_FALSE)
    {
        widget_set_wcss_input_format_default_value(
            (kal_uint8*) buffer,
            &(inp->input_max_size),
            (const char*)inp->format_pattern);
    }
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */

    /*
     * Get focus information
     */

    if (WGUI_CTX->in_paintbox)
    {
        /* When we back to the browser from fullscreen editor, we don't re-enter fullscreen editor again */
        if (!inp->is_string_gadget_emulation && WEDITOR_CTX->leave_from_fullscreen == KAL_FALSE)
        {
            /* after painting in paintbox once, we allow to enter fullscreen editor */
            is_key_focus = widget_register_keyfocus(_H(inp));
        }
        else
        {
            is_key_focus = KAL_FALSE;   /* Even if the string gadget is focused by paintbox */
        }
    }
    else
    {
        kal_bool is_want_focus = widget_form_gadget_want_focus(_H(inp));

        is_key_focus = is_want_focus ? widget_register_keyfocus(_H((inp))) : KAL_FALSE;

        widget_record_used_range(
            _H(inp),
            is_want_focus,
            is_key_focus,
            pos->x + inp->position.x,
            pos->y + inp->position.y,
            pos->x + inp->position.x + inp->size.width,
            pos->y + inp->position.y + inp->size.height);
    }

    if (is_key_focus == KAL_FALSE && WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_WANT_EXECUTE)
    {
        /*
         * In the web page includes accesskey tag and the target supports keypad and touch panel,
         * the user pressed the accesskey first to focus the inputbox and
         * we will set WEDITOR_CTX->current_state to FULLSCREEN_EDITOR_WANT_EXECUTE.
         * If that inputbox isn't in the current display area, we need to reset WEDITOR_CTX->current_state
         * Or when the users scroll the web page on the touch panel, widget will auto enter
         * the fullscreen editor when that inputbox is in the display area.
         */
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    }
    /*
     * When we select a input in browser, BRS doesnot HDIa_widgetSetInFocus it (just draw borders around it).
     * * As a result, we use another way to get the focus information
     */
    if (WGUI_CTX->in_paintbox && (inp == (widget_gadget_input_struct*) WGUI_CTX->selected_input_in_paintbox))
    {
        is_selected_in_paintbox = KAL_TRUE;
    }

    /* 
     * initialize multi_line_input_box *b
     */
    if (is_key_focus && !WGUI_CTX->in_form)
    {
        b = &MMI_multiline_inputbox;
    }
    else
    {
        b = &B; /* atmost one input can be edited */
    }

    gui_set_clip(
        pos->x + inp->position.x - 1,
        pos->y + inp->position.y - 1,
        pos->x + inp->position.x + inp->size.width,
        pos->y + inp->position.y + inp->size.height);

    gui_set_multi_line_input_box_theme(b, current_UI_theme->multi_line_input_box_theme);

    gui_create_multi_line_input_box_set_buffer(
        b,
        pos->x + inp->position.x,
        pos->y + inp->position.y,
        inp->size.width,
        inp->size.height,
        (UI_string_type) buffer,
        STR_SIZE(inp->input_max_size + 1),
        STR_SIZE(text_length + 1),
        0);
    /* Set the font color according the foreground color */
    gdi_act_color_to_rgb(
        &c_a,
        &c_r,
        &c_g,
        &c_b,
        fg_color);
    b->normal_text_color.alpha = (byte)c_a;
    b->normal_text_color.r = (byte)c_r;
    b->normal_text_color.g = (byte)c_g;
    b->normal_text_color.b = (byte)c_b;

    /* 
     * initilalize MMI related information 
     */

    pfont = widget_convert_to_system_font(&style->font);
    memcpy(&fontdata, b->text_font, sizeof(stFontAttribute));
    fontdata = pfont;
    /* fontdata.size = MEDIUM_FONT; */
    old_font = b->text_font;
    b->text_font = &fontdata;

    b->flags = 0;
    if (inp->is_single_line)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
            UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE | UI_MULTI_LINE_INPUT_BOX_DISABLE_WRAPPING_BY_WORD;
    }

    /*
     * Because we show border in web pages, we change text_y to 1 (default value is 2).
     * It will avoid Chinese word will sticky on the bottom border.
     */
    b->text_y = 1;
    /* It's tricky that we need to invoke gui_resize_multi_line_input_box() to recompute b->edit_width */
    gui_resize_multi_line_input_box(b, inp->size.width, inp->size.height);

    switch (inp->text_type)
    {
        case MsfPasswordText:
        case MsfPasswordNumber:
            widget_multiline_inputbox_set_mask(b, KAL_TRUE);
            break;
        default:
            widget_multiline_inputbox_set_mask(b, KAL_FALSE);
            break;
    }

    /* 
     * edit it 
     */
    if (is_key_focus && !WGUI_CTX->in_form)
    {
        if (!inp->is_readonly)
        {
            /* After the page is download finished, we allow the users to enter full screen editor */
            if ((WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_WANT_EXECUTE) &&
                (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY) != WIDGET_STATUS_BAR_BUSY)
            {
                MsfTextType override_type;

                b->text_font = old_font;
                override_type = inp->text_type;
                if (inp->text_type == MsfText)
                {
                #ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
                    if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*m") == 0 ||
                        app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"m*m") == 0)
                    {
                        /* We don't handle that case that WCSS is *M and default input method is lowercase alphanumeric */
                        override_type = (MsfTextType) MsfMMIDefaultInputMethod;
                    }
                    else if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*M") == 0 ||
                             app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"M*M") == 0)
                    {
                        override_type = (MsfTextType) MsfUpperCase;
                    }
                    else if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*N") == 0)
                    {
                        /* allow the entry of any numeric character */
                        override_type = MsfNumber;
                    }
                    else if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*n") == 0)
                    {
                        /* allow the entry of any numeric, symbol, or punctuation character */
                        override_type = MsfInteger;
                    }
                #else /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 
                    if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*N") == 0)
                    {
                        override_type = MsfNumber;
                    }
                    else if (app_ucs2_strcmp((const kal_int8*)inp->format_pattern, (const kal_int8*)L"*n") == 0)
                    {
                        override_type = MsfInteger;
                    }
                    else
                    {
                        widget_utf8_to_ucs2_string((kal_uint8*)inp->format_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN, (const kal_uint8*)"*m");
                    }
                #endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 
                }

                widget_setup_fullscreen_editor(
                    _H(inp),
                    buffer,
                    inp->input_max_size + 1,
                    override_type,
                    inp->is_input_required,
                    0,
                    (const char*)inp->format_pattern);

                /* put widget screen in history */
                widget_enter_fullscreen_editor();

                /*
                 * Note that it will still paint other gadgets after this return
                 * * However, since WGUI_CTX->is_widget_screen == KAL_FALSE after go to full screen editor
                 * * other gadgets wont display
                 */
                return; /* EXIT POINT */
            }
        }
        else
        {
            WAP_DBG_ASSERT(!WGUI_CTX->in_paintbox);

            if (!WGUI_CTX->in_paintbox)
            {
                b->flags |= UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

                /* set softkey */
                set_left_softkey_label((UI_string_type) NULL);
                set_left_softkey_icon(NULL);
                set_right_softkey_label((UI_string_type) GetString(STR_GLOBAL_BACK));
                set_right_softkey_icon(NULL);
                SetRightSoftkeyFunction(widget_choice_focus, KEY_EVENT_UP);

                /* set up/down key handler */
                SetKeyHandler((FuncPtr) widget_readonly_multiline_inputbox_previous_line, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_readonly_multiline_inputbox_next_line, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        }
    }

    /*
     * Cursor display 
     * * Since the cursor blinks in MMI, we should prevent cursor from being overlapped with softkey or titlebar.
     */
    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

    if (((is_key_focus && !inp->is_readonly && WGUI_CTX->in_form) || is_selected_in_paintbox) &&
        (pos->y + inp->position.y) >= bound_y1 && (pos->y + inp->position.y + inp->size.height - 1) <= bound_y2)
    {
        disable_bit_flag(b->flags, UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    }
    else
    {
        enable_bit_flag(b->flags, UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    }

    /* Scrollbar & background color of string gadget (emulated by input gadget) */
    if (inp->is_string_gadget_emulation)
    {
        S32 fh;

        /* Compute the height of the box */
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

        fh = gui_get_character_height();
        if (inp->size.height > b->n_lines * fh)
        {
            b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        }

        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND;
    }
    /* We don't want show DALMATIAN image in empty inputbox  */
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_DALMATIAN_EDITOR;

    /* 
     * Finally, show the input box (if not fullscreen editor )
     */
    /* Support inputbox text style */
    gui_get_multi_line_input_box_default_font_style(b, &fontdata);

    /* Support inputbox background color */
    bg_color.r = (byte)style->bg_color.r;
    bg_color.g = (byte)style->bg_color.g;
    bg_color.b = (byte)style->bg_color.b;
    bg_color.alpha = 100;
    gui_set_multi_line_input_box_default_bg_color(b, bg_color, MMI_TRUE);
    gui_show_multi_line_input_box(b);

    b->text_font = old_font;

#ifdef WIDGET_RESIDENT_STATUS_ICON
    /* Maybe we need to redraw status icons pane */
    if (pos->y + inp->position.y <= WGUI_CTX->status_icons_pane_bottom.y &&
        pos->y + inp->position.y + inp->size.height - 1 >= WGUI_CTX->status_icons_pane_top.y)
    {
        WGUI_CTX->redraw_status_icons_pane = 1;
    }
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

    /*
     * BRS will draw the border by itself
     * 
     */
    if (!WGUI_CTX->in_paintbox && is_key_focus && !inp->is_string_gadget_emulation)
    {
        gui_draw_horizontal_line(
            pos->x + inp->position.x,
            pos->x + inp->position.x + inp->size.width,
            pos->y + inp->position.y + inp->size.height,
            WGUI_CTX->cursor_shadow_color);

        gui_draw_vertical_line(
            pos->y + inp->position.y,
            pos->y + inp->position.y + inp->size.height,
            pos->x + inp->position.x + inp->size.width,
            WGUI_CTX->cursor_shadow_color);
    }
}

