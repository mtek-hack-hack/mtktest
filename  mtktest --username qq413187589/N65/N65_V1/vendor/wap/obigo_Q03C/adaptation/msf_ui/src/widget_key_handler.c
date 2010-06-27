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
 * widget_key_handler.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget key handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * In direct paint mode, paintbox will HDIa_widgetSetInFocus to an input or menu gadget only if 
 * it want to edit it. In other words, a input gadget might be selected (rounded by border) but not focused.
 *
 * In MsfForm, widget call HDIa_widgetSetInFocus when the cursor is on any gadgets (input/image/...), 
 * and it enter full-screen editor only if WGUI_CTX->in_form == FALSE
 *
 */

#include "widget.h"

/* Declaration of static functions */
static void widget_form_scroll_up(void);
static void widget_form_scroll_down(void);
static void widget_form_scroll_right(void);
static void widget_form_scroll_left(void);


/*****************************************************************************
 * FUNCTION
 *  widget_general_keyboard_handler
 * DESCRIPTION
 *  Dispatch an incoming keypad event.
 * PARAMETERS
 *  Keycode     [IN]        
 *  Keytype     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_general_keyboard_handler(kal_uint16 Keycode, kal_uint16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        /* END key doesn't use this function, we can safely return here.
           This might happen if the key event is delivered while WAP is in CTK screens. */
        return;
    }

#ifdef __MMI_TOUCH_SCREEN__
    widget_WAP_pen_on_keypad_event();
#endif 

    if (WGUI_CTX->is_menu_item_index_selection_process == 1)
    {
        /*
         * In MsfMenu case, the users press number keys to select the menu item. 
         * The GUI component, menu list, will start the timer to select the index one,
         * and we need to avoid the user press LSK or MsfYes at the same time.
         */
        if (Keycode == KEY_LSK || Keycode == KEY_ENTER)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENEREAL_KEYBOARD_HANDLER_DROP_KEY);
            if (Keytype == KEY_EVENT_UP)
            {
                WGUI_CTX->is_menu_item_index_selection_process = 0;
            }
            return;
        }
    }

    if (widget_key_ind_handler(Keycode, Keytype))
    {
        if (WGUI_CTX->in_paintbox)  /* Reason? */
        {
        #ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
            if ((Keycode >= KEY_UP_ARROW && Keycode <= KEY_RIGHT_ARROW) && Keytype == KEY_EVENT_UP)
            {
                WGUI_CTX->scrollbar_indication_info = Keytype;
                WGUI_CTX->scrollbar_indication_info <<= 8;
                WGUI_CTX->scrollbar_indication_info |= Keycode;
            }
            else if (Keycode == KEY_SEND || Keycode == KEY_ENTER || 
                     Keycode == KEY_LSK || Keycode == KEY_RSK)
            {
                /*
                 * If the users press MsfKey_Yes, MsfKey_Soft1, MsfKey_Soft2,
                 * we need to stop painting scrollbar indication buttons when changing the screen
                 */
                widget_stop_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER);
                WGUI_CTX->scrollbar_indication_info = 0;
            }
            else
            {
                WGUI_CTX->scrollbar_indication_info = 0;
            }
        #endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */
            widget_set_current_focus(_H(WGUI_CTX->current_focused_paintbox), KAL_TRUE);
        }

        /* If MMI animation is not stopped immediately, it might animate before widget_paint_hdlr,
           even though widget_clear_all_handler also stop these MMI animation. */
        // XXX. It's already handled in widget_on_window_focus_changed().
        // widget_clear_animator_on_key_accepted();
    }
#ifdef WIDGET_UNIT_TEST
    else if (Keytype == KEY_EVENT_UP && Keycode == KEY_STAR)
    {
        widget_start_unit_test();
    }
#endif /* WIDGET_UNIT_TEST */ 
#ifdef WIDGET_TEST_OUT_OF_MEMORY
    else if (Keytype == KEY_EVENT_UP && Keycode == KEY_POUND)
    {
        widget_simulate_out_of_memory();
    }
#endif /* WIDGET_TEST_OUT_OF_MEMORY */ 
    else if (Keytype == KEY_EVENT_UP)
    {
        if (WGUI_CTX->current_dialog == 0)
        {
            /* No support scroll and change focus in the dialog  */
            switch (Keycode)
            {
                case KEY_VOL_UP:
                    /* 
                     * If playing the audio in MMS viewer, "VolUp" is used for control volume.
                     * If there is no audio or the audio stop, "VolUp" is used for scroll MMS viewer.
                     */
                    if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        if (WGUI_CTX->current_window->property_mask & MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY &&
                            ((WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END) || widget_check_in_playing_video()))
                        {
                            widget_press_inc_volume();
                        }
                        else                    
                        {
                            widget_form_scroll_up();
                        }
                    }
                    break;
                case KEY_UP_ARROW:
				if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_up();
                    }
                    break;
                case KEY_VOL_DOWN:
                    /* 
                     * If playing the audio in MMS viewer, "VolDn" is used for control volume.
                     * If there is no audio or the audio stop, "VolDn" is used for scroll MMS viewer.
                     */
                    if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        if (WGUI_CTX->current_window->property_mask & MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY &&
                            ((WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END) || widget_check_in_playing_video()))
                        {
                            widget_press_dec_volume();
                        }
                        else                    
                        {
                            widget_form_scroll_down();
                        }
                    }
                    break;
                case KEY_DOWN_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_down();
                    }
                    break;
                case KEY_LEFT_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_left();
                    }
                    break;
                case KEY_RIGHT_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_right();
                    }
                    break;
                case KEY_SEND:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_choice_focus();
                    }
                    break;
                case KEY_0:
                case KEY_1:
                case KEY_2:
                case KEY_3:
                case KEY_4:
                case KEY_5:
                case KEY_6:
                case KEY_7:
                case KEY_8:
                case KEY_9:
                case KEY_STAR:
                case KEY_POUND:
                    /* Automatically focus input gadget when pressing anykey.
                       If access keys is set. It will not reach here. */
                    if (WGUI_CTX->in_paintbox)
                    {
                        if (WGUI_CTX->selected_input_in_paintbox != 0)
                        {
                            widget_key_ind_handler(KEY_SEND, KEY_EVENT_UP);
                        }
                    }
                else if ((WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window) &&
                             WGUI_CTX->current_focused_gadget &&
                             IS_GADGET_INPUT_TYPE2(WGUI_CTX->current_focused_gadget))
                    {
                        /* In MsfForm case */
                        widget_choice_focus();
                    }
                    else if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) == WGUI_CTX->current_window)
                    {
                        /*
                         * In MsfMenu case, the users press number keys to select the menu item. 
                         * The GUI component, menu list, will start the timer to select the index one,
                         * and we need to avoid the user press LSK or MsfYes at the same time.
                         */
                        WGUI_CTX->is_menu_item_index_selection_process = 1;
                    }

                    break;
            }
        }
    }

    if (Keytype == KEY_EVENT_UP)    /* Handle Key Down and Key Up together */
    {
        widget_send_update_event_to_wap();
    }
}

/* Used by menu (option group) to select the next item */


/*****************************************************************************
 * FUNCTION
 *  widget_goto_prev_keyfocus_keyboard_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_goto_prev_keyfocus_keyboard_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        HDIa_widgetSetInFocus((MSF_UINT32) WGUI_CTX->current_focused_paintbox, 1);
    }
    else
    {
        WGUI_CTX->in_form = 1;
        widget_form_scroll_up();
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_goto_next_keyfocus_keyboard_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_goto_next_keyfocus_keyboard_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        HDIa_widgetSetInFocus((MSF_UINT32) WGUI_CTX->current_focused_paintbox, 1);
    }
    else
    {
        WGUI_CTX->in_form = 1;
        widget_form_scroll_down();

    }

    return KAL_TRUE;
}

// TODO: move to widget_form.c (maybe renamed as widget_form_choose )


/*****************************************************************************
 * FUNCTION
 *  widget_choice_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_choice_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->in_paintbox && WGUI_CTX->current_focused_gadget)
    {
        if (_H(WGUI_CTX->current_focused_gadget)->module_id != MSF_MODID_MEA && 
            _H(WGUI_CTX->current_focused_gadget)->module_id != MSF_MODID_SMA)
        {
            /*
             * We don't need call widget_paint() again in MMS viewer. 
             * It may cause the gif animation redraw again.
             * by the way, there is no gadget input in MMS viewer.
             */

            if (IS_GADGET_INPUT_TYPE(WGUI_CTX->current_focused_gadget))     /* Gadgets that we can enter */
            {
                /*
                 * Although we have set this in widget_set_current_focus, we need to set it again 
                 * * for enter => leave => enter input gadget
                 * * FIXME. The code is ugly.
                 */
                if (WGUI_CTX->in_form)
                {
                    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_WANT_EXECUTE;
                }
                WGUI_CTX->in_form = !WGUI_CTX->in_form;
            }
    
            widget_paint();
        }
    }
}

#ifdef WIDGET_SLIDING_SMIL_SUPPORT

/* Reference: widget_form_update_for_sliding_SMIL() */


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_up_sliding_SMIL
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_scroll_up_sliding_SMIL(widget_form_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * 1. We do not handle scrollbar 
     * 2. WGUI_CTX->current_pos is reset when change WGUI_CTX->current_window
     */
    widget_gadget_image_struct *node;
    widget_gadget_image_struct *gimg_text, *gimg_image;
    widget_gadget_image_struct *next_gadget;
    int i;
    MSF_INT16 top = WGUI_CTX->display_pos.y;
    MSF_INT16 top_padding;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!form->sliding_info)
    {
        return;
    }

    /* Get gimg_text and gimg_image */
    i = 0;
    gimg_text = gimg_image = NULL;
    foreach(_H(form), GADGET_IMAGE, node,
            {
            if (_GIMG(node)->image && _IMG(_GIMG(node)->image)->is_drawn_image)
            {
            WAP_DBG_ASSERT(!gimg_text); gimg_text = node;}
            else
            {
            WAP_DBG_ASSERT(!gimg_image); gimg_image = node;}
            i++;}
    );

    if (i == 0 || WGUI_CTX->current_focused_gadget == NULL)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FORM_SCROLL_UP_SLIDING_SMIL);
        return;
    }

    /* Get next_gadget */
    next_gadget = NULL;
    if (WGUI_CTX->current_focused_gadget == _H(gimg_text) && gimg_image && form->sliding_info->image_on_top)
    {
        WAP_DBG_ASSERT(gimg_image->position.y < gimg_text->position.y);
        next_gadget = gimg_image;
        top  = top + WIDGET_SLIDING_SMIL_TOP;
    }

    if (WGUI_CTX->current_focused_gadget == _H(gimg_image) && gimg_text && !form->sliding_info->image_on_top)
    {
        WAP_DBG_ASSERT(gimg_image->position.y > gimg_text->position.y);
        next_gadget = gimg_text;
    }

    if (next_gadget == NULL)
    {
        if (WGUI_CTX->current_focused_gadget == _H(gimg_image))
        {
            top  = top + WIDGET_SLIDING_SMIL_TOP;
        }
    }

    /* Scroll */
    if (WGUI_CTX->current_pos.y + _W(WGUI_CTX->current_focused_gadget)->position.y < top) /* Current gadget partially out of screen */
    {
        WGUI_CTX->current_pos.y += WIDGET_SCROLL_DOWN_SIZE;
    }
    else if (!next_gadget)  /* Current gadget inside screen, no next gadget */
    {
        if (WGUI_CTX->current_focused_gadget == _H(gimg_text))
        {
            /* 
             * After scrolling the content of SMIL textbox up to the top (MTR or SMTR), it will delete user events.
             * We need to send MsfNotifyFocus again for it to add user events again.
             */
            widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);
        }
    }
    else if (next_gadget == gimg_image) /* HDIa_widgetSetInFocus will send MsfNotifyLostFocus */
    {
        MSF_INT16 y_next = WGUI_CTX->current_pos.y + next_gadget->position.y + next_gadget->size.height - 1;

        if (y_next >= top)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* Text gadget already de-register Up/Down key */
            widget_enqueue_keypad_event(KEY_UP_ARROW, KEY_EVENT_UP);
        }
        else if (y_next + WIDGET_SCROLL_UP_SIZE >= top)
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1);
        }
        else
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
        }
    }
    else
    {
        MSF_INT16 y_next = WGUI_CTX->current_pos.y + next_gadget->position.y;

        /* Text-to-image gadget must be scolled into screen before focused */
        if (y_next >= top)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* It does not send MsfNotifyFocus */
            widget_notify(_H(next_gadget), MsfNotifyFocus); /* Text gadget will register Up/Down key */
            widget_enqueue_keypad_event(KEY_UP_ARROW, KEY_EVENT_UP);    /* Let the text gadget scroll */
        }
        else if (y_next + WIDGET_SCROLL_UP_SIZE >= top)
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* It does not send MsfNotifyFocus */
            widget_notify(_H(next_gadget), MsfNotifyFocus);
        }
        else
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
        }
    }

    /* the top limit */
    if (WGUI_CTX->current_pos.y > WGUI_CTX->display_pos.y)
    {
        WGUI_CTX->current_pos.y = WGUI_CTX->display_pos.y;
    }

#ifdef WIDGET_SLIDING_SMIL_VBAR
    if (form->sliding_info->vbar)
    {
        _GBAR(form->sliding_info->vbar)->value =
            form->sliding_info->text_scroll_offset + (WGUI_CTX->display_pos.y - WGUI_CTX->current_pos.y);
    }
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 

    widget_paint();
}
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldy = WGUI_CTX->current_pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for BRS, it manage scrollbar by itself */
	if(WGUI_CTX->in_paintbox || !WGUI_CTX->in_form) 
    {
        WAP_DBG_ASSERT(0);
        return;
    }

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /* Allow multiple execution before widget_paint_hdlr because we do not rely on widget_paint_hdlr to pre-compute some values */
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _FORM(WGUI_CTX->current_window)->sliding_info)
    {
        widget_form_scroll_up_sliding_SMIL(_FORM(WGUI_CTX->current_window));
        return;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    /* do not scroll before repaint, because we need repaint to update the region of the widgets */
    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint(); // TODO: It let SMIL redraw slow.
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    if (widget_prev_keyfocus
        && WGUI_CTX->display_pos.x <= widget_prev_widget_position.x
        && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= widget_prev_widget_position.x)
    {
        if (WGUI_CTX->display_pos.y <= widget_prev_widget_position.y)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) widget_prev_keyfocus, 1);
            return;
        }
        else if (WGUI_CTX->display_pos.y <= widget_prev_widget_position.y + WIDGET_SCROLL_UP_SIZE)
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) widget_prev_keyfocus, 1);

            /* update scrollbar if WGUI_CTX->current_pos is changed */
            if (WGUI_CTX->current_vertical_scrollbar)
            {
                WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
            }
            widget_paint();

            return;
        }
    }

    /* 
     * After scrolling outside of SMIL textbox (MTR or SMTR), it will delete user events.
     * We need to send MsfNotifyFocus again for it to add user events again.
     */
    // TODO: this is temp fix.
    widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);

    WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;

    /* the top limit */
    if (WGUI_CTX->current_pos.y > WGUI_CTX->display_pos.y)
    {
        WGUI_CTX->current_pos.y = WGUI_CTX->display_pos.y;
    }

    /* update scrollbar if WGUI_CTX->current_pos is changed */
    if (WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
    }

    widget_paint();
}

#ifdef WIDGET_SLIDING_SMIL_SUPPORT

/* Reference: widget_form_update_for_sliding_SMIL() */


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_down_sliding_SMIL
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_scroll_down_sliding_SMIL(widget_form_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * 1. We do not handle scrollbar 
     * 2. WGUI_CTX->current_pos is reset when change WGUI_CTX->current_window
     */
    widget_gadget_image_struct *node;
    widget_gadget_image_struct *gimg_text, *gimg_image;
    widget_gadget_image_struct *next_gadget;
    int i;
    MSF_INT16 bottom = WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height - 1;
    MSF_INT16 padding = 0;
    MSF_INT16 bottom_window_pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!form->sliding_info)
    {
        return;
    }

    /* Get gimg_text and gimg_image */
    i = 0;
    gimg_text = gimg_image = NULL;
    foreach(_H(form), GADGET_IMAGE, node,
            {
            if (_GIMG(node)->image && _IMG(_GIMG(node)->image)->is_drawn_image)
            {
            WAP_DBG_ASSERT(!gimg_text); gimg_text = node;}
            else
            {
            WAP_DBG_ASSERT(!gimg_image); gimg_image = node;}
            i++;}
    );

    if (i == 0 || WGUI_CTX->current_focused_gadget == NULL)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FORM_SCROLL_DOWN_SLIDING_SMIL);
        return;
    }

    /* Get next_gadget */
    next_gadget = NULL;
    if (WGUI_CTX->current_focused_gadget == _H(gimg_text) && gimg_image && !form->sliding_info->image_on_top)
    {
        WAP_DBG_ASSERT(gimg_image->position.y > gimg_text->position.y);
        next_gadget = gimg_image;
    }

    if (WGUI_CTX->current_focused_gadget == _H(gimg_image) && gimg_text && form->sliding_info->image_on_top)
    {
        WAP_DBG_ASSERT(gimg_image->position.y < gimg_text->position.y);
        next_gadget = gimg_text;
    }

    /* Compute bottom_window_pos */
    if (next_gadget)
    {
        if (next_gadget == gimg_image)
        {
            /* we will have padding in gadget_image only */
            padding = WIDGET_SLIDING_SMIL_BOTTOM;
        }
        bottom_window_pos = next_gadget->position.y + next_gadget->size.height + padding - 1;
    }
    else
    {
        if (WGUI_CTX->current_focused_gadget == _H(gimg_image))
        {
            /* we will have padding in gadget_image only */
            padding = WIDGET_SLIDING_SMIL_BOTTOM;
        }
        bottom_window_pos = _W(WGUI_CTX->current_focused_gadget)->position.y + 
                            _W(WGUI_CTX->current_focused_gadget)->size.height + padding - 1;
    }

    /* Scroll */
    if (WGUI_CTX->current_pos.y + _W(WGUI_CTX->current_focused_gadget)->position.y + _W(WGUI_CTX->current_focused_gadget)->size.height - 1 > bottom)   /* Current gadget partially out of screen */
    {
        WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
    }
    else if (!next_gadget)  /* Current gadget inside screen, no next gadget */
    {
        if (WGUI_CTX->current_focused_gadget == _H(gimg_text))
        {
            /* 
             * After scrolling the content of SMIL textbox down to the bottom (MTR or SMTR), it will delete user events.
             * We need to send MsfNotifyFocus again for it to add user events again.
             */
            widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);
        }
    }
    else if (next_gadget == gimg_image) /* HDIa_widgetSetInFocus will send MsfNotifyLostFocus */
    {
        MSF_INT16 y_next = WGUI_CTX->current_pos.y + next_gadget->position.y;

        if (y_next <= bottom)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* Text gadget already de-register Up/Down key */
            widget_enqueue_keypad_event(KEY_DOWN_ARROW, KEY_EVENT_UP);
        }
        else if (y_next - WIDGET_SCROLL_DOWN_SIZE <= bottom)
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1);
        }
        else
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
        }
    }
    else
    {
        MSF_INT16 y_next = WGUI_CTX->current_pos.y + next_gadget->position.y;

        /* Text-to-image gadget must be scolled into screen before focused */
        if (y_next + next_gadget->size.height - 1 <= bottom)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* It does not send MsfNotifyFocus */
            widget_notify(_H(next_gadget), MsfNotifyFocus); /* Text gadget will register Up/Down key */
            widget_enqueue_keypad_event(KEY_DOWN_ARROW, KEY_EVENT_UP);  /* Let the text gadget scroll */
        }
        else if (y_next + next_gadget->size.height - 1 - WIDGET_SCROLL_DOWN_SIZE <= bottom)
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) next_gadget, 1); /* It does not send MsfNotifyFocus */
            widget_notify(_H(next_gadget), MsfNotifyFocus);
        }
        else
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
        }
    }

    /* The bottom limit */
    if ((bottom_window_pos >= WGUI_CTX->display_size.height - padding - 1) &&
        (WGUI_CTX->current_pos.y + bottom_window_pos < bottom))
    {
        WGUI_CTX->current_pos.y = bottom - bottom_window_pos;
    }

#ifdef WIDGET_SLIDING_SMIL_VBAR
    if (form->sliding_info->vbar)
    {
        _GBAR(form->sliding_info->vbar)->value =
            form->sliding_info->text_scroll_offset + (WGUI_CTX->display_pos.y - WGUI_CTX->current_pos.y);
    }
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 

    widget_paint();
}
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldy = WGUI_CTX->current_pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(WGUI_CTX->in_paintbox || !WGUI_CTX->in_form) 
    {
        WAP_DBG_ASSERT(0);
        return;
    }

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /* Allow multiple execution before widget_paint_hdlr */
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _FORM(WGUI_CTX->current_window)->sliding_info)
    {
        widget_form_scroll_down_sliding_SMIL(_FORM(WGUI_CTX->current_window));
        return;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint(); // TODO: It let SMIL redraw slow.
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    /* if next widget is visible */
    if (widget_next_keyfocus
        && WGUI_CTX->display_pos.x <= widget_next_widget_position.x
        && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= widget_next_widget_position.x)
    {
        if (WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height >
            widget_next_widget_position.y + widget_next_widget_size.height)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) widget_next_keyfocus, 1);
            return;
        }
        else if (WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height >
                 widget_next_widget_position.y + widget_next_widget_size.height - WIDGET_SCROLL_DOWN_SIZE)
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) widget_next_keyfocus, 1);
            /* update scrollbar if WGUI_CTX->current_pos is changed */
            if (WGUI_CTX->current_vertical_scrollbar)
            {
                WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
            }
            widget_paint();
            return;
        }
    }

    /* 
     * After scrolling outside of SMIL textbox (MTR or SMTR), it will delete user events.
     * We need to send MsfNotifyFocus again for it to add user events again.
     */
    widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);

    /* If there is nothing below the screen, we will not allow to scroll down. */
    if (widget_max_y <= WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height + 1)
    {
        return;
    }

    WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;

    /* Update scrollbar if WGUI_CTX->current_pos is changed */
    if (WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
    }
    widget_paint();
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_left
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldx = WGUI_CTX->current_pos.x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _FORM(WGUI_CTX->current_window)->sliding_info)
    {
        /* Disable Left/Right */
        return;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    if (WGUI_CTX->in_paintbox || !WGUI_CTX->in_form)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint();
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    WGUI_CTX->current_pos.x += WIDGET_SCROLL_LEFT_SIZE;

    if (WGUI_CTX->current_pos.x > WGUI_CTX->display_pos.x)
    {
        WGUI_CTX->current_pos.x = WGUI_CTX->display_pos.x;
    }

    /* update scrollbar */
    if (WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar->value += (oldx - WGUI_CTX->current_pos.x);
    }

    widget_paint();
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldx = WGUI_CTX->current_pos.x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _FORM(WGUI_CTX->current_window)->sliding_info)
    {
        /* Disable Left/Right */
        return;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    if (WGUI_CTX->in_paintbox || !WGUI_CTX->in_form)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint();
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    /* if there is nothing int the right side of the screen, we will not allow to scroll right. */
    if (widget_max_x <= WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width + 1)
    {
        return;
    }

    WGUI_CTX->current_pos.x -= WIDGET_SCROLL_RIGHT_SIZE;

    /* update scrollbar */
    if (WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar->value += (oldx - WGUI_CTX->current_pos.x);
    }

    widget_paint();
}

