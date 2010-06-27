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
 *  gui_windows.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Miscellaneous UI components. 
 *
 *  [Popup description]
 *  [Scrolling text]
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_WINDOWS_H__
#define __GUI_WINDOWS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"
#include "gui_theme_struct.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL        0x00000010
#define UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL  0x00000020
#define UI_POP_UP_DESCRIPTION_DISPLAY_SCROLL        0x00000040
#define UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM        0x00000080

#define MAX_POP_UP_DESCRIPTION_STRINGS              2

/* number of steps for transition animation */
#define MAX_POP_UP_DESCRIPTION_TRANSITION_STEPS     9
/* step time in ms for transition animation */
#define POPUP_DESCRIPTION_TRANSITION_STEP_TIME      100


#define UI_SCROLLING_TEXT_ENABLE_SCROLL             0x00000001
#define UI_SCROLLING_TEXT_MARQUEE_SCROLL            0x00000002
#define UI_SCROLLING_TEXT_TWO_DIRECTION_SCROLL      0x00000004
#define UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT    0x00000008
#define UI_SCROLLING_TEXT_BORDERED_TEXT             0x00000010
#define UI_SCROLLING_TEXT_DISPLAY_SCROLL            0x00000020


#define GUI_WAIT_LONGPRESS_MAX_DISTANCE             15
#define GUI_WAIT_LONGPRESS_CACHE_SIZE               (50 * 50 * 2)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct _UI_pop_up_description
{
    S32 x, y;
    S32 width, height;
    color text_color;
    UI_font_type text_font;
    UI_filled_area *background_filler;
    UI_string_type text_strings[MAX_POP_UP_DESCRIPTION_STRINGS];
    S32 n_strings;
    S32 text_x, text_y;
    S32 scroll_x, scroll_width, text_width;
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    S32 transition_step;
#endif
    U32 flags;
} UI_pop_up_description;


typedef struct _scrolling_text
{
    S32 x, y;
    S32 width, height;
    S32 text_width, text_height;
    U32 flags;
    S32 scroll_size;
    S32 scroll_gap;
    S32 scroll_pause;
    color text_color;
    color text_border_color;
    stFontAttribute text_font;
    UI_string_type text;
    S32 scroll_x;
    S32 scroll_counter;
    S32 scroll_time;
    bitmap *graphics_context;
    void (*timer_callback)(void);
    void (*draw_background)(S32 x1, S32 y1, S32 x2, S32 y2);

    UI_string_type scroll_text;
    UI_string_type scroll_text_end;
} scrolling_text;


typedef enum
{
    GUI_WAIT_LONGPRESS_UNDECIDED = 0,
    GUI_WAIT_LONGPRESS_INVALID,
    GUI_WAIT_LONGPRESS_ANIMATING,
    GUI_WAIT_LONGPRESS_ANIMATION_FINISHED,
    GUI_WAIT_LONGPRESS_READY
} gui_wait_longpress_enum;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/*
 * popup description
 */
extern UI_pop_up_description_theme *current_pop_up_description_theme;

extern void gui_set_pop_up_description_current_theme(UI_pop_up_description *b);
extern void gui_set_pop_up_description_theme(UI_pop_up_description *b, UI_pop_up_description_theme *t);
extern void gui_create_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height);
extern void gui_resize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height);
extern void gui_move_pop_up_description(UI_pop_up_description *b, S32 x, S32 y);
extern void gui_set_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height);
extern void gui_set_pop_up_description_n_strings(UI_pop_up_description *b, S32 n);
extern void gui_set_pop_up_description_text(UI_pop_up_description *b, S32 i, UI_string_type text);
extern void gui_show_pop_up_description(UI_pop_up_description *b);
extern U8 gui_autoresize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height);
extern void gui_pop_up_description_start_scroll(UI_pop_up_description *m);
extern void gui_pop_up_description_stop_scroll(void);

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
extern void gui_setup_pop_up_description_transition(UI_pop_up_description *b);
#endif 


/* 
 * scrolling text
 */
extern void default_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_create_scrolling_text(
                scrolling_text *s, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                UI_string_type text,
                void (*timer_callback)(void), 
                void (*draw_background)(S32 x1, S32 y1, S32 x2, S32 y2), 
                color text_color,
                color border_color);
extern void gui_redraw_scrolling_text(scrolling_text *s);
extern void gui_handle_scrolling_text(scrolling_text *s);
extern void gui_scrolling_text_start(scrolling_text *s);
extern void gui_scrolling_text_stop(scrolling_text *s);
extern void gui_show_scrolling_text(scrolling_text *s);
extern void gui_change_scrolling_text_font(scrolling_text *s, UI_font_type font);
extern void gui_change_scrolling_text(scrolling_text *s, UI_string_type text);


/* 
 * multiple layer screen utility 
 */
extern U8 gui_is_entry_new_screen(void);
extern void gui_set_entry_new_screen(U8 new_entry);
extern void gui_free_multilayer_screen(void);

extern void gui_layer_transparent(S32 gui_show_layer, U8 trans_value, S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_layer_show_animation_file(
                S32 gui_show_layer,
                U8 trans_value,
                S32 *frame_idx,
                S8 *file_name,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                S32 image_x1,
                S32 image_y1);
extern void gui_layer_show_animation_ID(
                S32 gui_show_layer,
                U8 trans_value,
                S32 *frame_idx,
                U16 image_id,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                S32 image_x1,
                S32 image_y1);
/* multiple layer mask */
extern void gui_set_multilayer_mask(S32 in_multilayer_mask);
extern U16 gui_get_multilayer_mask(void);


/* Touch Panel - Utility functions for waiting longtap animation */
#ifdef __MMI_TOUCH_SCREEN__
extern gui_wait_longpress_enum gui_pen_wait_longpress(mmi_pen_event_type_enum pen_event, S16 x, S16 y);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_WINDOWS_H__ */

