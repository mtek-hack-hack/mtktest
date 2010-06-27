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
 *   gui_inputs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Input box - UI component
 *
 * Author:
 * -------
 *   
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

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui_inputs.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header for Input related objects
**********************************************************************************/

#ifndef __GUI_INPUTS_H__
#define __GUI_INPUTS_H__

#include "MMI_features.h"
#include "gui.h"
#include "gui_scrollbars.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"
/* MTK Leo end */

#ifdef __MMI_TOUCH_DIAL_SCREEN__
/* start vijay 20050221, for Touch Dialing Screen */
#include "gdi_datatype.h"
#include "gdi_image_bmp.h"
#include "wgui.h"
#include "wgui_categories_defs.h"
#include "TouchScreenGprot.h"
#include "gui_fixed_menus.h"
#include "MMIDataType.h"
/* end vijay */
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"

typedef enum
{
    GUI_SINGLE_LINE_INPUT_BOX_PEN_NONE,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_LEFT_DOWN,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_LEFT_UP,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_RIGHT_DOWN,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_RIGHT_UP,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_DOWN,
    GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_UP
} gui_single_line_input_box_pen_enum;

typedef struct
{
    U8 pen_inside;
} gui_single_line_input_box_pen_state_struct;

typedef enum
{
    GUI_MULTI_LINE_INPUT_BOX_PEN_NONE,
    GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN,
    GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_UP,
    GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR,
    GUI_MULTI_LINE_INPUT_BOX_PEN_MAX
} gui_multi_line_input_box_pen_enum;

typedef struct
{
    U8 pen_inside;
    U8 pen_on_scroll_bar;
} gui_multi_line_input_box_pen_state_struct;
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    extern UI_information_bar_theme *current_information_bar_theme;

    /* UI multitap_input structure                  */

#define UI_MULTITAP_INPUT_CENTER_X                 0x00000010
#define UI_MULTITAP_INPUT_CENTER_Y                 0x00000020
    extern UI_multitap_input_theme *current_multitap_input_theme;

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    /* start vijay 20050224, for Touch Dialing Screen */
    typedef enum
    {
        GUI_DIALING_PEN_NONE,
        GUI_DIALING_KEYPAD_HIGHLIGHT_CHANGED,
        GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I,
        GUI_DIALING_KEYPAD_PEN_INSERT_STAR,
        GUI_DIALING_KEYPAD_PEN_INSERT_HASH
            /* 053005 Calvin added for function key */
    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            , GUI_DIALING_KEYPAD_PEN_INSERT_FUNC,
        GUI_DIALING_KEYPAD_PEN_INSERT_PHB = GUI_DIALING_KEYPAD_PEN_INSERT_FUNC,
        GUI_DIALING_KEYPAD_PEN_INSERT_CALL
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
        ,GUI_DIALING_KEYPAD_PEN_INSERT_CALL_SLAVE
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
    #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
            /* Calvin end */
    } gui_dialing_key_pen_enum;
    /* end vijay */
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

    typedef struct _multitap_input
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *f;
        color selector_color;
        UI_string_type text;
        S32 text_x, text_y;
        color normal_text_color;
        color selected_text_color;
        S32 length;
        S32 current_position;
        UI_font_type text_font;
        S8 text_gap;
        U32 flags;
        void (*input_complete_callback) (void);
        void (*input_callback) (UI_character_type);
    } multitap_input;

    typedef enum
    {
        GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,
        GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,
        GUI_MULTI_LINE_INPUT_BOX_DELETEALL
    } gui_multi_line_input_box_change_event_enum;


    /* MTK Elvis for color dialling font */
    typedef struct _color_dialing_font
    {
        UI_character_type ch;
        color c;
    } color_dialing_font;
    /* MTK end */

    extern void gui_set_multitap_input_current_theme(multitap_input *m);
    extern void gui_set_multitap_input_theme(multitap_input *m, UI_multitap_input_theme *t);
    extern void gui_create_multitap_input(multitap_input *b, S32 x, S32 y, S32 width, S32 height, UI_string_type text);
    void gui_set_multitap_input_callbacks(multitap_input *b, void (*input_callback) (UI_character_type),
                                          void (*input_complete_callback) (void));
    extern void gui_change_multitap_input_state(multitap_input *b);
    extern void gui_show_multitap_input(multitap_input *b);
    extern void gui_multitap_input_complete(multitap_input *b);
    extern void gui_resize_multitap_input(multitap_input *b, S32 width, S32 height);
    extern void gui_move_multitap_input(multitap_input *b, S32 x, S32 y);
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    extern BOOL gui_multitap_input_translate_pen_position(multitap_input *b, S32 x, S32 y, S32 *char_index);
#endif 

    /* UI Single line Input box structure              */

#define  UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL           0x00000000
#define UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED          0x00000001
#define UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED          0x00000002
#define UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP          0x00000004
#define UI_SINGLE_LINE_INPUT_BOX_CENTER_Y             0x00000008
#define UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS         0x00000010
#define UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW            0x00000020
#define UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND         0x00000040
#define UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW     0x00000080
#define UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY          0x00000100
#define UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE          0x00000200
#define UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY           0x00000400
#define UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING       0x00000800
#define UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR       0x00001000
#define UI_SINGLE_LINE_INPUT_BOX_NO_BORDER               0x00002000
#define UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH  0x00004000
#define UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT          0x00008000
#define UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER         0x00010000
#define UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES           0x00020000
#define UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING 0x00040000
#define UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT     0x00080000
#define UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR   0x00100000
#define UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS    0x00200000
#define UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED         0x00400000
    /* MTK Leo add 1125, trucate too long number/name with "..." in call list. */
#define UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT        0x00800000
#define UI_SINGLE_LINE_INPUT_BOX_SECOND_WORD_HIGHLIGHT              0x01000000
#define UI_SINGLE_LINE_INPUT_BOX_SWITCH_WORD_HIGHLIGHT_COLOR        0x02000000
#define UI_SINGLE_LINE_INPUT_BOX_FORCE_BORDER_DISPLAY             0x04000000
    /* 022405 Calvin added to trucate too long number/name without */
#define UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT_NO_BRIEF  0x08000000
    /* Calvin end */
    /* TODO: remove the following line */
#define UI_MULTI_LINE_INPUT_BOX_LINE_HEIGHT_WITH_UNDERLINE  20

#define UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID          (1<<0)
#define UI_SINGLE_LINE_INPUT_BOX_EXT_ENABLE_ARROW     (1<<1)

    extern UI_single_line_input_box_theme *current_single_line_input_box_theme;

    typedef struct _single_line_input_box
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_filler;
        UI_filled_area *disabled_filler;
        UI_filled_area *selected_filler;
        U32 flags;
        U32 ext_flags;
        S32 grid_width;
        UI_buffer_type text;
        S32 text_length;
        S32 allocated_length;
        S32 available_length;
        UI_buffer_type current_text_p;
        UI_buffer_type last_position_p;
        S32 text_x;
        S32 text_y;
        S32 text_offset_x;
        S32 cursor_x;
        S32 text_width;
        color normal_text_color;
        color disabled_text_color;
        color selected_text_color;
        color selection_text_color;
        color selection_color;
        color cursor_color;
        UI_font_type text_font;
        S8 text_gap;
        U8 mask_character;
        S32 UCS2_count;
        S32 GSM_ext_count;
        void (*overflow_callback) (void);
        void (*change_callback) (void);
        void (*validation_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);
        UI_buffer_type highlight_start_position;
        UI_buffer_type highlight_end_position;
        /* Elvis for second word highlight */
        UI_buffer_type second_highlight_start_position;
        UI_buffer_type second_highlight_end_position;
        /* MTK end */
    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        gui_single_line_input_box_pen_state_struct pen_state;
    #endif 
    } single_line_input_box;

    extern void gui_set_single_line_input_box_current_theme(single_line_input_box *b);
    extern void gui_set_single_line_input_box_theme(single_line_input_box *b, UI_single_line_input_box_theme *t);
    extern void gui_create_single_line_input_box(
                    single_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    S32 length);
    extern void gui_create_single_line_input_box_use_buffer(
                    single_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length);
    extern void gui_create_single_line_input_box_set_buffer(
                    single_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length,
                    S32 text_length,
                    S32 edit_position);
    extern void gui_single_line_input_box_show_cursor(single_line_input_box *b, S32 x, S32 y, S32 height);
    extern void gui_show_single_line_input_box(single_line_input_box *b);
    extern void gui_destroy_single_line_input_box(single_line_input_box *b);
    extern void gui_single_line_input_box_delete_character(single_line_input_box *b);
    extern void gui_single_line_input_box_insert_character(single_line_input_box *b, UI_character_type c);
    extern void gui_single_line_input_box_insert_multitap_character(single_line_input_box *b, UI_character_type c);
    extern void gui_single_line_input_box_confirm_multitap_character(single_line_input_box *b);
    extern void gui_single_line_input_box_insert_character_in_pos(single_line_input_box *b, UI_character_type c, S32 pos);
    extern void gui_single_line_input_box_delete_character_in_pos(single_line_input_box *b, S32 pos);
    

    /* PMT dara added for Multitap thai */
#ifdef __MMI_MULTITAP_THAI__
    extern U8 gui_single_line_input_box_get_previous_character(single_line_input_box *b, UI_character_type *c);
#endif 
    extern void gui_single_line_input_box_previous(single_line_input_box *b);
    extern void gui_single_line_input_box_next(single_line_input_box *b);
    extern void gui_resize_single_line_input_box(single_line_input_box *b, S32 width, S32 height);
    extern void gui_move_single_line_input_box(single_line_input_box *b, S32 x, S32 y);
    extern void gui_single_line_input_box_delete_all(single_line_input_box *b);
    extern void gui_single_line_input_box_delete_current_character(single_line_input_box *b);
    extern void gui_single_line_input_box_toggle_insert_mode(single_line_input_box *b);
    extern void gui_single_line_input_box_goto_first_character(single_line_input_box *b);
    extern void gui_single_line_input_box_goto_last_character(single_line_input_box *b);
    extern void gui_single_line_input_box_clear(single_line_input_box *b);
    extern U8 gui_single_line_input_box_test_overflow(single_line_input_box *b);
    extern U8 gui_single_line_input_box_test_first_position(single_line_input_box *b);
    extern U8 gui_single_line_input_box_test_last_position(single_line_input_box *b);
    extern U8 gui_single_line_input_box_test_last_position_overflow(single_line_input_box *b);
    extern S32 gui_single_line_input_box_get_text_length(single_line_input_box *b);
    extern U8 gui_single_line_input_box_test_last_character_position(single_line_input_box *b);
    extern void gui_create_single_line_input_box_set_buffer_first_position(
                    single_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length,
                    S32 text_length,
                    S32 edit_position);
    extern S32 gui_single_line_input_box_highlight_cursor_end(single_line_input_box *b);
    /* MTK Elvis */
    extern S32 gui_single_line_input_box_highlight_cursor_number(single_line_input_box *b, S32 numOfChar);
    /* MTK end */
    extern S32 gui_single_line_input_box_highlight_cursor_start(single_line_input_box *b);
    /* MTK Add By Elvis */
    extern S32 gui_single_line_input_box_insert_string(single_line_input_box *b, UI_string_type s, S32 o);
    /* MTK end */
    extern S32 gui_single_line_input_box_next_steps(single_line_input_box *b, S32 steps);
    extern S32 gui_single_line_input_box_previous_steps(single_line_input_box *b, S32 steps);
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    extern BOOL gui_single_line_input_box_translate_pen_event(
                    single_line_input_box *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_single_line_input_box_pen_enum *single_line_input_box_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
    extern void gui_show_single_line_input_box_ext(single_line_input_box *b, S32 move_to_x, S32 move_to_y);

    /* UI multiline input box structure          */
    extern UI_multi_line_input_box_theme *current_multi_line_input_box_theme;

#define  UI_MULTI_LINE_INPUT_BOX_STATE_NORMAL            0x00000000
#define UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED           0x00000001
#define UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED           0x00000002
#define UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND       0x00000004
#define UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP           0x00000008
#define UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR        0x00000010
#define UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE           0x00000020
#define UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW             0x00000040
#define UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW      0x00000080
#define UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS             0x00000100
#define UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY              0x00000200
#define UI_MULTI_LINE_INPUT_BOX_RIGHT_JUSTIFY               0x00000400
#define UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH   0x00000800
#define UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR      0x00001000
#define UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT              0x00002000
#define UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING         0x00004000
#define UI_MULTI_LINE_INPUT_BOX_VIEW_MODE                   0x00008000
#define UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER          0x00010000
#define UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING     0x00020000
#define UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED          0x00040000
#define UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE        0x00080000
#define UI_MULTI_LINE_INPUT_BOX_DISABLE_WRAPPING_BY_WORD    0x00100000
    /* Multiline inputbox inside inline editor */
#define UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU          0x00200000
    /* WAP CSS input format */
#define UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE                 0x00400000
#define UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL        0x00800000
#define  UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA          0x01000000
#define  UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER  0x02000000
    /* Replace CRLF as a separator line  */
#define UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR              0x04000000
    /* Draw underline for each line. Used with min_line_height */
#define UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE              0x08000000
#define UI_MULTI_LINE_INPUT_BOX_DISPLAY_LASTLINE            0x10000000
    /* Change text format (color/size/alignment)  when marker code is identified */
#define UI_MULTI_LINE_INPUT_BOX_RICHTEXT                    0x20000000
#define UI_MULTI_LINE_INPUT_BOX_SMS_MAX_LENGTH_HANDLING     0x40000000
#define UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND      0x80000000  /* 070405 Calvin added */

/* these are used in ext_flags */
#define GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE                0x00000001
#define GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE                0x00000002
#define GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT                0x00000004
#define GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY               0x00000008
#define GUI_MULTI_LINE_INPUT_BOX_DISABLE_DALMATIAN_EDITOR        0x00000010
#define GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR     0x00000020
#define GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT               0x00000040
#define GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE           0x00000080
#define GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER                     0x00000100
#define GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER                   0x00000200
#define GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER                   0x00000400
#define GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR                    0x00000800
#define GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR                   0x00001000
#define GUI_MULTI_LINE_INPUT_BOX_SEARCH_WORD                     0x00002000

    /* Max length for character sequence that can be translated into an icon */
#define MMI_MULTILINE_ICON_MAX_STRING_LEN 5

    /* Type of callback handler to translate a string into an icon */
    typedef S32(*multi_line_input_box_icon_hdlr) (const U8 *s, BOOL do_draw, S32 *icon_width, S32 *icon_height,
                                                  S32 x, S32 y);

//barcode
typedef struct
{
	PS8   str_addr;
	U16   length;
} HILITE_STR;


/*** ritesh started****/
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#include "Gui_setting.h"


#define GUI_SHARED_BYTES MAIN_LCD_DEVICE_HEIGHT/2       /* As LCD_WIDTH=220 shared bytes =LCD_WIDTH/2 */
#define GUI_NO_OF_PAGES 4

#define GUI_PAGE_SIZE 512
#define GUI_PAGE_SIZE_IN_UCS2 GUI_PAGE_SIZE*ENCODING_LENGTH

#define GUI_SCROLL_STEPS_LINE_BY_LINE 5

    typedef struct _page_details
    {
        U32 page_id;
        U16 page_height;
        U8 shared_no_of_bytes;
        U8 shared_data[GUI_SHARED_BYTES];
    } gui_page_details;
//PMT SUKRIT START MMSVIEWER
typedef void (*get_page_callback)(U32 start_id, U32 end_id, PU8 buffer);
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
/**** ritesh ended*****/
    typedef struct _multi_line_input_box
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_filler;
        UI_filled_area *disabled_filler;
        UI_filled_area *focussed_filler;
        UI_filled_area *text_filler;
        color special_text_color;
        color normal_text_color;
        color disabled_text_color;
        color focussed_text_color;
        color selected_text_color;
        color selector_color;
        color cursor_color;
        color boundary_color;
        color default_bg_color;
        color underline_color;
        S8 text_gap;
        UI_font_type text_font;
        U32 flags;
        U32 ext_flags;
        UI_buffer_type text;
        S32 text_length;
        S32 allocated_length;
        S32 available_length;
        S32 edit_width;
        S32 edit_height;
        S32 text_x;
        S32 text_y;
        /* The gap between editor edge and the rightmost text edge */
        S32 text_x2_gap_width;
        S32 text_offset_x;
        S32 text_offset_y;
        S32 cursor_x;
        S32 cursor_y;
        S32 n_lines;
        S32 text_height;
        S32 cursor_line_position_counter;
        UI_buffer_type line_before_cursor_line_p;
        UI_buffer_type cursor_line_p;
        UI_buffer_type cursor_p;
        UI_buffer_type line_after_cursor_line_p;
        UI_buffer_type line_after_cursor_line_last_p;
        UI_buffer_type last_position_p;
        U8 mask_character;
        S32 UCS2_count;
        S32 GSM_ext_count;
        void (*overflow_callback) (void);
        void (*change_callback) (void);
        void (*validation_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);
        vertical_scrollbar vbar;
        UI_buffer_type highlight_start_position;
        UI_buffer_type highlight_end_position;
        S32 max_line_height;
        S32 editor_changed;     /* Gurinder - 03/12/2003 - Variable to track change in multiline input box. */
        S32 vertical_scroll_on; /* Vikram : Start a vertical scroll timer. 0- Not started, 1 - Started */
        /* Minimum height of text area */
        S16 min_text_height;
        /* Maximum height of text area when text is empty */
        S16 max_empty_text_height;
        /* Minimum line height */
        S16 min_line_height;
        /* Height of header/footer area */
        S16 header_height, footer_height, header_gap;
        /* Customized information bar draw function */
        void (*infobar_redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2);
        void (*infobar_reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2);
        /* Customized header draw function */
        void (*header_callback) (MMI_BOOL is_draw,S32 yoffset, S32 height,S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2);
        /* Customized footer draw function */
        void (*footer_callback) (MMI_BOOL is_draw,S32 yoffset, S32 height,S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2);
        /* Pen down at header, footer, left or right area*/
        void (*pen_down_control_area_callback)(U8 area_type, S32 x, S32 y);
        /* Change Event Handler */
        MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 C);
        /*
         * Customized function to replace a string with icon. Return the number of characters consumed. 
         * * If icon height is taller than typical character height, 'min_line_height' should be also set.
         */
        multi_line_input_box_icon_hdlr icon_callback;
   //barcode
	S32					curr_hilite_text_offset_y;
	HILITE_STR 			*hilite_list;
	U16					hilite_str_number;
	void 					(*hilite_cb)(S32 idx);
	S32					current_hilite_idx;
    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        S16 pen_scroll_delay_time;
        S16 pen_scroll_after_delay;
        gui_multi_line_input_box_pen_state_struct pen_state;
    #endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
    #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
        U32 start_id;                                   /* needed to give the appropriate id to page during next page or previous page requirement.At every call to next page and previous page its value gets changed. */
        U32 end_id;                                     /* needed to give the appropriate id to page during next page or previous page requirement.At every call to next page and previous page its value gets changed. */
        S32 edit_height_displayed_lines;                /* height of the currently displayed text. */
        U32 last_page_id;                               /* id of the last page */
        S32 page_zero_prev_height;                      /* to maintain the text relocation while new page entry in buffer during previous page requirement. */
        S32 size_of_total_data;                         /* size of the whole text currently in the buffer */
        S32 text_offset;                                /* this variable shows the position of the chracter where text_offset_y is currently pointing.During exit ,Application wants the current offset of the displayed window. */
        S16 last_page_size;                             /* size of the last page */
        S16 page_offset;                                /* for text display from the same position.This variable is needed when concerned application give some offset. */
        S16 jump_offset_from_app;
        S16 last_window_text_height;                    /* height of the text in the last multiline window of last page. */
        pBOOL last_page_flag;                           /* to maintain the text relocation last page flag is taken. */
        pBOOL jump_to_offset_flag;
        /* PMT Start 00071 */
        pBOOL scroll_type;
        /* PMT End 00071 */
        U8 previous_shared_bytes;                       /* shared bytes between page at 0th index to last page out from the buffer.This variable is needed to copy the pages in upward and downward direction. */
        U8 scroll_speed;
        U8 font_style;                                  /* speed of the auto scrolling. */
        pBOOL next_line_scroll_flag;
        pBOOL search_flag_is_on;
        gui_page_details page_details[GUI_NO_OF_PAGES]; /* page details structure */
   //PMT SUKRIT START MMSVIEWER
        get_page_callback get_page_cb;
   //PMT SUKRIT END MMSVIEWER
        void (*displayed_text_callback) (UI_buffer_type first_display_text, S32 text_length); /* callback for displayed text */
    #endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
    void (*locate_cursor_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 buffer_pos, S32 text_length);
    void (*underline_callback) (UI_buffer_type text, S32 cursor_offset, S32 text_length);
    U32 show_action_flag;
   
    } multi_line_input_box;

    extern void gui_set_multi_line_input_box_current_theme(multi_line_input_box *b);
    extern void gui_set_multi_line_input_box_theme(multi_line_input_box *b, UI_multi_line_input_box_theme *t);
    extern void gui_create_multi_line_input_box(
                    multi_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 length);
    extern void gui_create_multi_line_input_box_use_buffer(
                    multi_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length);
    extern void gui_create_multi_line_input_box_set_buffer(
                    multi_line_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length,
                    S32 text_length,
                    S32 edit_position);
    extern void gui_move_multi_line_input_box(multi_line_input_box *b, S32 x, S32 y);
    extern void gui_resize_multi_line_input_box(multi_line_input_box *b, S32 width, S32 height);
    extern void gui_show_multi_line_input_box(multi_line_input_box *b);
    extern void gui_destroy_multi_line_input_box(multi_line_input_box *b);
    extern void gui_multi_line_input_box_delete_character(multi_line_input_box *b);
    extern void gui_multi_line_input_box_delete_all(multi_line_input_box *b);
    extern void gui_multi_line_input_box_delete_current_character(multi_line_input_box *b);
    extern MMI_BOOL gui_multi_line_input_box_insert_character(multi_line_input_box *b, UI_character_type c);
    extern void gui_multi_line_input_box_insert_multitap_character(multi_line_input_box *b, UI_character_type c);
    extern void gui_multi_line_input_box_confirm_multitap_character(multi_line_input_box *b);
    extern void gui_multi_line_input_box_register_infobar_callback(
                        multi_line_input_box *b,
                        void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        U32 height);
    extern void gui_multi_line_input_box_register_change_event_handler(multi_line_input_box *b,MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C));
    extern void gui_set_multi_line_input_box_underline_color(multi_line_input_box *b, color c);
    extern void gui_multi_line_input_box_delete_character_in_pos(multi_line_input_box *b, S32 pos);
    extern void gui_multi_line_input_box_insert_character_in_pos(multi_line_input_box *b, UI_character_type c, S32 pos);

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)

    typedef enum
    {
        PAGE_ZERO,
        PAGE_ONE,
        PAGE_TWO,
        PAGE_THREE,
//PMT SUKRIT START MMSVIEWER
        PAGE_MAX
//PMT SUKRIT END MMSVIEWER
    } gui_paging_no_of_pages;

    typedef enum
    {
        FONT_DEFAULT,
        FONT_ITALIC,
        FONT_BOLD
    } gui_paging_font_style;
    //PMT SUKRIT START MMSVIEWER
    #if 0
/* under construction !*/
    #endif
    //PMT SUKRIT END 
    extern void gui_paging_multi_line_input_box_get_previous_page_callback(multi_line_input_box *b);
    extern void gui_paging_multi_line_input_box_get_next_page_callback(multi_line_input_box *b);
    extern void gui_paging_multi_line_input_box_previous_page(multi_line_input_box *b);
    extern void gui_paging_multi_line_input_box_next_page(multi_line_input_box *b);
    extern void gui_paging_multi_line_input_box_previous_line_in_paging(multi_line_input_box *b);
    extern void gui_paging_multi_line_input_box_next_line_in_paging(multi_line_input_box *b);
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
    extern U8 gui_multi_line_input_box_get_previous_character(multi_line_input_box *b, UI_character_type *c);
    extern void gui_multi_line_input_box_previous(multi_line_input_box *b);
    extern void gui_multi_line_input_box_next(multi_line_input_box *b);
    extern void gui_multi_line_input_box_previous_line(multi_line_input_box *b);
    extern void gui_multi_line_input_box_next_line(multi_line_input_box *b);
    extern void gui_multi_line_input_box_previous_page(multi_line_input_box *b);
    extern void gui_multi_line_input_box_next_page(multi_line_input_box *b);
    extern void gui_multi_line_input_box_toggle_insert_mode(multi_line_input_box *b);
    extern void gui_multi_line_input_box_clear(multi_line_input_box *b);
    extern U8 gui_multi_line_input_box_test_overflow(multi_line_input_box *b);
    extern U8 gui_multi_line_input_box_test_first_position(multi_line_input_box *b);
    extern U8 gui_multi_line_input_box_test_last_position(multi_line_input_box *b);
    extern U8 gui_multi_line_input_box_test_last_position_overflow(multi_line_input_box *b);
    extern S32 gui_multi_line_input_box_get_text_length(multi_line_input_box *b);
    extern S32 gui_multi_line_input_box_highlight_cursor_end(multi_line_input_box *b);
    extern S32 gui_multi_line_input_box_highlight_cursor_start(multi_line_input_box *b);
    extern S32 gui_multi_line_input_box_highlight_cursor_number(multi_line_input_box *b, S32 n);
    extern void gui_multi_line_input_box_insert_newline(multi_line_input_box *b);
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    extern BOOL gui_multi_line_input_box_translate_pen_event(
                    multi_line_input_box *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_multi_line_input_box_pen_enum *multi_line_input_box_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
    extern void gui_show_multi_line_input_box_ext(multi_line_input_box *b, S32 move_to_x, S32 move_to_y);
    /* barcode */
    extern void gui_multi_line_input_box_go_to_hilite(multi_line_input_box *b, U16 idx, MMI_BOOL need_scroll_to_pos);
    extern void gui_multi_line_input_box_go_to_pre_hilite(multi_line_input_box *b);
    extern void gui_multi_line_input_box_go_to_next_hilite(multi_line_input_box *b);
    extern MMI_BOOL gui_multi_line_input_box_is_pen_down_in_hilite(multi_line_input_box *b);

    /*
     * UI_MULTI_LINE_INPUT_BOX_RICHTEXT
     *
     * Specical marker code for styles and colors  
     *
     * "Private Use" Region in Unicode is 0xE000 (57344) - 0xF900 (63744)
     * Regions defined in gRange_Properitory[] must not be overlapped.
     */

#define GUI_INPUT_MARKER_BEGIN                     0xEA00
#define GUI_INPUT_MARKER_END                       0xEFFF

    /* 
     * Font Format. Multiple format can be combined with bitwise OR 
     */

    /* The significant byte is 0xEA */
#define GUI_INPUT_MARKER_FORMAT                    0xEA00
#define GUI_INPUT_MARKER_FORMAT_MASK               0xFF00

    /* 1-bit flag */
#define GUI_INPUT_MARKER_BOLD                      0xEA01
#define GUI_INPUT_MARKER_ITALIC                    0xEA02
#define GUI_INPUT_MARKER_UNDERLINE                 0xEA04
#define GUI_INPUT_MARKER_BORDER                    0xEA08
    /* USAT */
#define GUI_INPUT_MARKER_STRIKETHROUGH             0xEA10

    /* 2 bits are reserved */

    /* 2-bit flag for size */
#define GUI_INPUT_MARKER_SIZE_MASK                 0xFFC0
#define GUI_INPUT_MARKER_MEDIUM                    0xEA40
#define GUI_INPUT_MARKER_SMALL                     0xEA80
#define GUI_INPUT_MARKER_LARGE                     0xEAC0

    /* 
     * Paragraph Format. Multiple format can be combined with bitwise OR 
     */

    /* The significant byte is 0xEB */
#define GUI_INPUT_MARKER_PARAGRAPH                 0xEB00
#define GUI_INPUT_MARKER_PARAGRAPH_MASK            0xFF00

    /* 2-bit flag for alignment. Flag still valid in the next line */
#define GUI_INPUT_MARKER_ALIGN_MASK                0xFF03
#define GUI_INPUT_MARKER_ALIGN_LEFT                0xEB01
#define GUI_INPUT_MARKER_ALIGN_CENTER              0xEB02
#define GUI_INPUT_MARKER_ALIGN_RIGHT               0xEB03

    /* 3-bit flag for more spacing between the previous line. (Flag cleared in the next line) */
#define GUI_INPUT_MARKER_LINE_SPACING_MASK               0xFF1C
#define GUI_INPUT_MARKER_LINE_SPACING_1                  0xEB04
#define GUI_INPUT_MARKER_LINE_SPACING_2                  0xEB08
#define GUI_INPUT_MARKER_LINE_SPACING_3                  0xEB0C
#define GUI_INPUT_MARKER_LINE_SPACING_4                  0xEB10
#define GUI_INPUT_MARKER_LINE_SPACING_5                  0xEB14
#define GUI_INPUT_MARKER_LINE_SPACING_6                  0xEB18
#define GUI_INPUT_MARKER_LINE_SPACING_7                  0xEB1C

    /* 2 bits are reserved */

    /* 1-bit flag separator between the previous line. (Flag cleared in the next line) */
#define GUI_INPUT_MARKER_LINE_SEPARATOR            0xEB80

    /* 
     * One-byte marker 
     */

    /* Reset all  */
#define GUI_INPUT_MARKER_RESET_ALL                 0xEC00
    /* Reset paragraph */
#define GUI_INPUT_MARKER_RESET_PARAGRAPH           0xEC01
    /* Reset font format */
#define GUI_INPUT_MARKER_RESET_FORMAT              0xEC02
    /* Reset font color */
#define GUI_INPUT_MARKER_RESET_COLOR               0xEC03

    /* Range of W3C color marker */
#define GUI_INPUT_MARKER_W3C_COLOR_BEGIN           0xEC04
#define GUI_INPUT_MARKER_W3C_COLOR_END             0xECFF

    /* Range of default color marker */
#define GUI_INPUT_MARKER_COLOR_BEGIN               0xED00
#define GUI_INPUT_MARKER_COLOR_END                 0xED7F
    /* USAT */
    /* Range of text background color marker */
#define GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN              0xED80
#define GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_END                0xEDFF

    /* Range of border color marker */
#define GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN          0xEE04
#define GUI_INPUT_MARKER_W3C_BORDER_COLOR_END            0xEEFF

#define GUI_INPUT_MARKER_BORDER_COLOR_BEGIN              0xEF00
#define GUI_INPUT_MARKER_BORDER_COLOR_END                0xEFFF

    /*
     * Default color marker code (122 colors)
     */
    typedef enum
    {
        GUI_INPUT_COLOR_00 = GUI_INPUT_MARKER_COLOR_BEGIN,
        GUI_INPUT_COLOR_01,
        GUI_INPUT_COLOR_02,
        GUI_INPUT_COLOR_03,
        GUI_INPUT_COLOR_04,
        GUI_INPUT_COLOR_05,
        GUI_INPUT_COLOR_06,
        GUI_INPUT_COLOR_07,
        GUI_INPUT_COLOR_08,
        GUI_INPUT_COLOR_09,
        GUI_INPUT_COLOR_0A,
        GUI_INPUT_COLOR_0B,
        GUI_INPUT_COLOR_0C,
        GUI_INPUT_COLOR_0D,
        GUI_INPUT_COLOR_0E,
        GUI_INPUT_COLOR_0F,
        GUI_INPUT_COLOR_10,
        GUI_INPUT_COLOR_11,
        GUI_INPUT_COLOR_12,
        GUI_INPUT_COLOR_13,
        GUI_INPUT_COLOR_14,
        GUI_INPUT_COLOR_15,
        GUI_INPUT_COLOR_16,
        GUI_INPUT_COLOR_17,
        GUI_INPUT_COLOR_18,
        GUI_INPUT_COLOR_19,
        GUI_INPUT_COLOR_1A,
        GUI_INPUT_COLOR_1B,
        GUI_INPUT_COLOR_1C,
        GUI_INPUT_COLOR_1D,
        GUI_INPUT_COLOR_1E,
        GUI_INPUT_COLOR_1F,
        GUI_INPUT_COLOR_20,
        GUI_INPUT_COLOR_21,
        GUI_INPUT_COLOR_22,
        GUI_INPUT_COLOR_23,
        GUI_INPUT_COLOR_24,
        GUI_INPUT_COLOR_25,
        GUI_INPUT_COLOR_26,
        GUI_INPUT_COLOR_27,
        GUI_INPUT_COLOR_28,
        GUI_INPUT_COLOR_29,
        GUI_INPUT_COLOR_2A,
        GUI_INPUT_COLOR_2B,
        GUI_INPUT_COLOR_2C,
        GUI_INPUT_COLOR_2D,
        GUI_INPUT_COLOR_2E,
        GUI_INPUT_COLOR_2F,
        GUI_INPUT_COLOR_30,
        GUI_INPUT_COLOR_31,
        GUI_INPUT_COLOR_32,
        GUI_INPUT_COLOR_33,
        GUI_INPUT_COLOR_34,
        GUI_INPUT_COLOR_35,
        GUI_INPUT_COLOR_36,
        GUI_INPUT_COLOR_37,
        GUI_INPUT_COLOR_38,
        GUI_INPUT_COLOR_39,
        GUI_INPUT_COLOR_3A,
        GUI_INPUT_COLOR_3B,
        GUI_INPUT_COLOR_3C,
        GUI_INPUT_COLOR_3D,
        GUI_INPUT_COLOR_3E,
        GUI_INPUT_COLOR_3F,
        GUI_INPUT_COLOR_40,
        GUI_INPUT_COLOR_41,
        GUI_INPUT_COLOR_42,
        GUI_INPUT_COLOR_43,
        GUI_INPUT_COLOR_44,
        GUI_INPUT_COLOR_45,
        GUI_INPUT_COLOR_46,
        GUI_INPUT_COLOR_47,
        GUI_INPUT_COLOR_48,
        GUI_INPUT_COLOR_49,
        GUI_INPUT_COLOR_4A,
        GUI_INPUT_COLOR_4B,
        GUI_INPUT_COLOR_4C,
        GUI_INPUT_COLOR_4D,
        GUI_INPUT_COLOR_4E,
        GUI_INPUT_COLOR_4F,
        GUI_INPUT_COLOR_50,
        GUI_INPUT_COLOR_51,
        GUI_INPUT_COLOR_52,
        GUI_INPUT_COLOR_53,
        GUI_INPUT_COLOR_54,
        GUI_INPUT_COLOR_55,
        GUI_INPUT_COLOR_56,
        GUI_INPUT_COLOR_57,
        GUI_INPUT_COLOR_58,
        GUI_INPUT_COLOR_59,
        GUI_INPUT_COLOR_5A,
        GUI_INPUT_COLOR_5B,
        GUI_INPUT_COLOR_5C,
        GUI_INPUT_COLOR_5D,
        GUI_INPUT_COLOR_5E,
        GUI_INPUT_COLOR_5F,
        GUI_INPUT_COLOR_60,
        GUI_INPUT_COLOR_61,
        GUI_INPUT_COLOR_62,
        GUI_INPUT_COLOR_63,
        GUI_INPUT_COLOR_64,
        GUI_INPUT_COLOR_65,
        GUI_INPUT_COLOR_66,
        GUI_INPUT_COLOR_67,
        GUI_INPUT_COLOR_68,
        GUI_INPUT_COLOR_69,
        GUI_INPUT_COLOR_6A,
        GUI_INPUT_COLOR_6B,
        GUI_INPUT_COLOR_6C,
        GUI_INPUT_COLOR_6D,
        GUI_INPUT_COLOR_6E,
        GUI_INPUT_COLOR_6F,
        GUI_INPUT_COLOR_70,
        GUI_INPUT_COLOR_71,
        GUI_INPUT_COLOR_72,
        GUI_INPUT_COLOR_73,
        GUI_INPUT_COLOR_74,
        GUI_INPUT_COLOR_75,
        GUI_INPUT_COLOR_76,
        GUI_INPUT_COLOR_77,
        GUI_INPUT_COLOR_78,
        GUI_INPUT_COLOR_79
    } gui_input_color_marker_enum;

    /* 
     * http://www.w3.org/TR/css3-color/ 
     * W3C color marker code (147 colors)
     */
    typedef enum
    {
        GUI_INPUT_COLOR_ALICEBLUE = GUI_INPUT_MARKER_W3C_COLOR_BEGIN,
        GUI_INPUT_COLOR_ANTIQUEWHITE,
        GUI_INPUT_COLOR_AQUA,
        GUI_INPUT_COLOR_AQUAMARINE,
        GUI_INPUT_COLOR_AZURE,
        GUI_INPUT_COLOR_BEIGE,
        GUI_INPUT_COLOR_BISQUE,
        GUI_INPUT_COLOR_BLACK,
        GUI_INPUT_COLOR_BLANCHEDALMOND,
        GUI_INPUT_COLOR_BLUE,
        GUI_INPUT_COLOR_BLUEVIOLET,
        GUI_INPUT_COLOR_BROWN,
        GUI_INPUT_COLOR_BURLYWOOD,
        GUI_INPUT_COLOR_CADETBLUE,
        GUI_INPUT_COLOR_CHARTREUSE,
        GUI_INPUT_COLOR_CHOCOLATE,
        GUI_INPUT_COLOR_CORAL,
        GUI_INPUT_COLOR_CORNFLOWERBLUE,
        GUI_INPUT_COLOR_CORNSILK,
        GUI_INPUT_COLOR_CRIMSON,
        GUI_INPUT_COLOR_CYAN,
        GUI_INPUT_COLOR_DARKBLUE,
        GUI_INPUT_COLOR_DARKCYAN,
        GUI_INPUT_COLOR_DARKGOLDENROD,
        GUI_INPUT_COLOR_DARKGRAY,
        GUI_INPUT_COLOR_DARKGREEN,
        GUI_INPUT_COLOR_DARKGREY,
        GUI_INPUT_COLOR_DARKKHAKI,
        GUI_INPUT_COLOR_DARKMAGENTA,
        GUI_INPUT_COLOR_DARKOLIVEGREEN,
        GUI_INPUT_COLOR_DARKORANGE,
        GUI_INPUT_COLOR_DARKORCHID,
        GUI_INPUT_COLOR_DARKRED,
        GUI_INPUT_COLOR_DARKSALMON,
        GUI_INPUT_COLOR_DARKSEAGREEN,
        GUI_INPUT_COLOR_DARKSLATEBLUE,
        GUI_INPUT_COLOR_DARKSLATEGRAY,
        GUI_INPUT_COLOR_DARKSLATEGREY,
        GUI_INPUT_COLOR_DARKTURQUOISE,
        GUI_INPUT_COLOR_DARKVIOLET,
        GUI_INPUT_COLOR_DEEPPINK,
        GUI_INPUT_COLOR_DEEPSKYBLUE,
        GUI_INPUT_COLOR_DIMGRAY,
        GUI_INPUT_COLOR_DIMGREY,
        GUI_INPUT_COLOR_DODGERBLUE,
        GUI_INPUT_COLOR_FIREBRICK,
        GUI_INPUT_COLOR_FLORALWHITE,
        GUI_INPUT_COLOR_FORESTGREEN,
        GUI_INPUT_COLOR_FUCHSIA,
        GUI_INPUT_COLOR_GAINSBORO,
        GUI_INPUT_COLOR_GHOSTWHITE,
        GUI_INPUT_COLOR_GOLD,
        GUI_INPUT_COLOR_GOLDENROD,
        GUI_INPUT_COLOR_GRAY,
        GUI_INPUT_COLOR_GREY,
        GUI_INPUT_COLOR_GREEN,
        GUI_INPUT_COLOR_GREENYELLOW,
        GUI_INPUT_COLOR_HONEYDEW,
        GUI_INPUT_COLOR_HOTPINK,
        GUI_INPUT_COLOR_INDIANRED,
        GUI_INPUT_COLOR_INDIGO,
        GUI_INPUT_COLOR_IVORY,
        GUI_INPUT_COLOR_KHAKI,
        GUI_INPUT_COLOR_LAVENDER,
        GUI_INPUT_COLOR_LAVENDERBLUSH,
        GUI_INPUT_COLOR_LAWNGREEN,
        GUI_INPUT_COLOR_LEMONCHIFFON,
        GUI_INPUT_COLOR_LIGHTBLUE,
        GUI_INPUT_COLOR_LIGHTCORAL,
        GUI_INPUT_COLOR_LIGHTCYAN,
        GUI_INPUT_COLOR_LIGHTGOLDENRODYELLOW,
        GUI_INPUT_COLOR_LIGHTGRAY,
        GUI_INPUT_COLOR_LIGHTGREEN,
        GUI_INPUT_COLOR_LIGHTGREY,
        GUI_INPUT_COLOR_LIGHTPINK,
        GUI_INPUT_COLOR_LIGHTSALMON,
        GUI_INPUT_COLOR_LIGHTSEAGREEN,
        GUI_INPUT_COLOR_LIGHTSKYBLUE,
        GUI_INPUT_COLOR_LIGHTSLATEGRAY,
        GUI_INPUT_COLOR_LIGHTSLATEGREY,
        GUI_INPUT_COLOR_LIGHTSTEELBLUE,
        GUI_INPUT_COLOR_LIGHTYELLOW,
        GUI_INPUT_COLOR_LIME,
        GUI_INPUT_COLOR_LIMEGREEN,
        GUI_INPUT_COLOR_LINEN,
        GUI_INPUT_COLOR_MAGENTA,
        GUI_INPUT_COLOR_MAROON,
        GUI_INPUT_COLOR_MEDIUMAQUAMARINE,
        GUI_INPUT_COLOR_MEDIUMBLUE,
        GUI_INPUT_COLOR_MEDIUMORCHID,
        GUI_INPUT_COLOR_MEDIUMPURPLE,
        GUI_INPUT_COLOR_MEDIUMSEAGREEN,
        GUI_INPUT_COLOR_MEDIUMSLATEBLUE,
        GUI_INPUT_COLOR_MEDIUMSPRINGGREEN,
        GUI_INPUT_COLOR_MEDIUMTURQUOISE,
        GUI_INPUT_COLOR_MEDIUMVIOLETRED,
        GUI_INPUT_COLOR_MIDNIGHTBLUE,
        GUI_INPUT_COLOR_MINTCREAM,
        GUI_INPUT_COLOR_MISTYROSE,
        GUI_INPUT_COLOR_MOCCASIN,
        GUI_INPUT_COLOR_NAVAJOWHITE,
        GUI_INPUT_COLOR_NAVY,
        GUI_INPUT_COLOR_OLDLACE,
        GUI_INPUT_COLOR_OLIVE,
        GUI_INPUT_COLOR_OLIVEDRAB,
        GUI_INPUT_COLOR_ORANGE,
        GUI_INPUT_COLOR_ORANGERED,
        GUI_INPUT_COLOR_ORCHID,
        GUI_INPUT_COLOR_PALEGOLDENROD,
        GUI_INPUT_COLOR_PALEGREEN,
        GUI_INPUT_COLOR_PALETURQUOISE,
        GUI_INPUT_COLOR_PALEVIOLETRED,
        GUI_INPUT_COLOR_PAPAYAWHIP,
        GUI_INPUT_COLOR_PEACHPUFF,
        GUI_INPUT_COLOR_PERU,
        GUI_INPUT_COLOR_PINK,
        GUI_INPUT_COLOR_PLUM,
        GUI_INPUT_COLOR_POWDERBLUE,
        GUI_INPUT_COLOR_PURPLE,
        GUI_INPUT_COLOR_RED,
        GUI_INPUT_COLOR_ROSYBROWN,
        GUI_INPUT_COLOR_ROYALBLUE,
        GUI_INPUT_COLOR_SADDLEBROWN,
        GUI_INPUT_COLOR_SALMON,
        GUI_INPUT_COLOR_SANDYBROWN,
        GUI_INPUT_COLOR_SEAGREEN,
        GUI_INPUT_COLOR_SEASHELL,
        GUI_INPUT_COLOR_SIENNA,
        GUI_INPUT_COLOR_SILVER,
        GUI_INPUT_COLOR_SKYBLUE,
        GUI_INPUT_COLOR_SLATEBLUE,
        GUI_INPUT_COLOR_SLATEGRAY,
        GUI_INPUT_COLOR_SLATEGREY,
        GUI_INPUT_COLOR_SNOW,
        GUI_INPUT_COLOR_SPRINGGREEN,
        GUI_INPUT_COLOR_STEELBLUE,
        GUI_INPUT_COLOR_TAN,
        GUI_INPUT_COLOR_TEAL,
        GUI_INPUT_COLOR_THISTLE,
        GUI_INPUT_COLOR_TOMATO,
        GUI_INPUT_COLOR_TURQUOISE,
        GUI_INPUT_COLOR_VIOLET,
        GUI_INPUT_COLOR_WHEAT,
        GUI_INPUT_COLOR_WHITE,
        GUI_INPUT_COLOR_WHITESMOKE,
        GUI_INPUT_COLOR_YELLOW,
        GUI_INPUT_COLOR_YELLOWGREEN
    } gui_input_w3c_color_marker_enum;

    /* 
     * http://www.w3.org/TR/css3-color/ 
     * W3C color marker code (147 colors)
     * For text background color only define 17 colors
     */
    typedef enum
    {
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKGREY = GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKRED,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_YELLOW,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKGREEN,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKCYAN,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKBLUE,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_DARKMAGENTA,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_GRAY,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_WHITE,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_RED,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_LIGHTYELLOW,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_LIGHTGREEN,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_LIGHTCYAN,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_LIGHTBLUE,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_MAGENTA,
        GUI_INPUT_TEXT_BACKGROUND_COLOR_BLACK
    } gui_input_w3c_text_background_color_marker_enum;

    /*
     * Default color marker code (122 colors)
     */

    typedef enum
    {
        GUI_INPUT_BORDER_COLOR_00 = GUI_INPUT_MARKER_BORDER_COLOR_BEGIN,
        GUI_INPUT_BORDER_COLOR_01,
        GUI_INPUT_BORDER_COLOR_02,
        GUI_INPUT_BORDER_COLOR_03,
        GUI_INPUT_BORDER_COLOR_04,
        GUI_INPUT_BORDER_COLOR_05,
        GUI_INPUT_BORDER_COLOR_06,
        GUI_INPUT_BORDER_COLOR_07,
        GUI_INPUT_BORDER_COLOR_08,
        GUI_INPUT_BORDER_COLOR_09,
        GUI_INPUT_BORDER_COLOR_0A,
        GUI_INPUT_BORDER_COLOR_0B,
        GUI_INPUT_BORDER_COLOR_0C,
        GUI_INPUT_BORDER_COLOR_0D,
        GUI_INPUT_BORDER_COLOR_0E,
        GUI_INPUT_BORDER_COLOR_0F,
        GUI_INPUT_BORDER_COLOR_10,
        GUI_INPUT_BORDER_COLOR_11,
        GUI_INPUT_BORDER_COLOR_12,
        GUI_INPUT_BORDER_COLOR_13,
        GUI_INPUT_BORDER_COLOR_14,
        GUI_INPUT_BORDER_COLOR_15,
        GUI_INPUT_BORDER_COLOR_16,
        GUI_INPUT_BORDER_COLOR_17,
        GUI_INPUT_BORDER_COLOR_18,
        GUI_INPUT_BORDER_COLOR_19,
        GUI_INPUT_BORDER_COLOR_1A,
        GUI_INPUT_BORDER_COLOR_1B,
        GUI_INPUT_BORDER_COLOR_1C,
        GUI_INPUT_BORDER_COLOR_1D,
        GUI_INPUT_BORDER_COLOR_1E,
        GUI_INPUT_BORDER_COLOR_1F,
        GUI_INPUT_BORDER_COLOR_20,
        GUI_INPUT_BORDER_COLOR_21,
        GUI_INPUT_BORDER_COLOR_22,
        GUI_INPUT_BORDER_COLOR_23,
        GUI_INPUT_BORDER_COLOR_24,
        GUI_INPUT_BORDER_COLOR_25,
        GUI_INPUT_BORDER_COLOR_26,
        GUI_INPUT_BORDER_COLOR_27,
        GUI_INPUT_BORDER_COLOR_28,
        GUI_INPUT_BORDER_COLOR_29,
        GUI_INPUT_BORDER_COLOR_2A,
        GUI_INPUT_BORDER_COLOR_2B,
        GUI_INPUT_BORDER_COLOR_2C,
        GUI_INPUT_BORDER_COLOR_2D,
        GUI_INPUT_BORDER_COLOR_2E,
        GUI_INPUT_BORDER_COLOR_2F,
        GUI_INPUT_BORDER_COLOR_30,
        GUI_INPUT_BORDER_COLOR_31,
        GUI_INPUT_BORDER_COLOR_32,
        GUI_INPUT_BORDER_COLOR_33,
        GUI_INPUT_BORDER_COLOR_34,
        GUI_INPUT_BORDER_COLOR_35,
        GUI_INPUT_BORDER_COLOR_36,
        GUI_INPUT_BORDER_COLOR_37,
        GUI_INPUT_BORDER_COLOR_38,
        GUI_INPUT_BORDER_COLOR_39,
        GUI_INPUT_BORDER_COLOR_3A,
        GUI_INPUT_BORDER_COLOR_3B,
        GUI_INPUT_BORDER_COLOR_3C,
        GUI_INPUT_BORDER_COLOR_3D,
        GUI_INPUT_BORDER_COLOR_3E,
        GUI_INPUT_BORDER_COLOR_3F,
        GUI_INPUT_BORDER_COLOR_40,
        GUI_INPUT_BORDER_COLOR_41,
        GUI_INPUT_BORDER_COLOR_42,
        GUI_INPUT_BORDER_COLOR_43,
        GUI_INPUT_BORDER_COLOR_44,
        GUI_INPUT_BORDER_COLOR_45,
        GUI_INPUT_BORDER_COLOR_46,
        GUI_INPUT_BORDER_COLOR_47,
        GUI_INPUT_BORDER_COLOR_48,
        GUI_INPUT_BORDER_COLOR_49,
        GUI_INPUT_BORDER_COLOR_4A,
        GUI_INPUT_BORDER_COLOR_4B,
        GUI_INPUT_BORDER_COLOR_4C,
        GUI_INPUT_BORDER_COLOR_4D,
        GUI_INPUT_BORDER_COLOR_4E,
        GUI_INPUT_BORDER_COLOR_4F,
        GUI_INPUT_BORDER_COLOR_50,
        GUI_INPUT_BORDER_COLOR_51,
        GUI_INPUT_BORDER_COLOR_52,
        GUI_INPUT_BORDER_COLOR_53,
        GUI_INPUT_BORDER_COLOR_54,
        GUI_INPUT_BORDER_COLOR_55,
        GUI_INPUT_BORDER_COLOR_56,
        GUI_INPUT_BORDER_COLOR_57,
        GUI_INPUT_BORDER_COLOR_58,
        GUI_INPUT_BORDER_COLOR_59,
        GUI_INPUT_BORDER_COLOR_5A,
        GUI_INPUT_BORDER_COLOR_5B,
        GUI_INPUT_BORDER_COLOR_5C,
        GUI_INPUT_BORDER_COLOR_5D,
        GUI_INPUT_BORDER_COLOR_5E,
        GUI_INPUT_BORDER_COLOR_5F,
        GUI_INPUT_BORDER_COLOR_60,
        GUI_INPUT_BORDER_COLOR_61,
        GUI_INPUT_BORDER_COLOR_62,
        GUI_INPUT_BORDER_COLOR_63,
        GUI_INPUT_BORDER_COLOR_64,
        GUI_INPUT_BORDER_COLOR_65,
        GUI_INPUT_BORDER_COLOR_66,
        GUI_INPUT_BORDER_COLOR_67,
        GUI_INPUT_BORDER_COLOR_68,
        GUI_INPUT_BORDER_COLOR_69,
        GUI_INPUT_BORDER_COLOR_6A,
        GUI_INPUT_BORDER_COLOR_6B,
        GUI_INPUT_BORDER_COLOR_6C,
        GUI_INPUT_BORDER_COLOR_6D,
        GUI_INPUT_BORDER_COLOR_6E,
        GUI_INPUT_BORDER_COLOR_6F,
        GUI_INPUT_BORDER_COLOR_70,
        GUI_INPUT_BORDER_COLOR_71,
        GUI_INPUT_BORDER_COLOR_72,
        GUI_INPUT_BORDER_COLOR_73,
        GUI_INPUT_BORDER_COLOR_74,
        GUI_INPUT_BORDER_COLOR_75,
        GUI_INPUT_BORDER_COLOR_76,
        GUI_INPUT_BORDER_COLOR_77,
        GUI_INPUT_BORDER_COLOR_78,
        GUI_INPUT_BORDER_COLOR_79
    } gui_input_border_color_marker_enum;

    /* 
     * http://www.w3.org/TR/css3-color/ 
     * W3C color marker code (147 colors)
     */

    typedef enum
    {
        GUI_INPUT_BORDER_COLOR_ALICEBLUE = GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN,
        GUI_INPUT_BORDER_COLOR_ANTIQUEWHITE,
        GUI_INPUT_BORDER_COLOR_AQUA,
        GUI_INPUT_BORDER_COLOR_AQUAMARINE,
        GUI_INPUT_BORDER_COLOR_AZURE,
        GUI_INPUT_BORDER_COLOR_BEIGE,
        GUI_INPUT_BORDER_COLOR_BISQUE,
        GUI_INPUT_BORDER_COLOR_BLACK,
        GUI_INPUT_BORDER_COLOR_BLANCHEDALMOND,
        GUI_INPUT_BORDER_COLOR_BLUE,
        GUI_INPUT_BORDER_COLOR_BLUEVIOLET,
        GUI_INPUT_BORDER_COLOR_BROWN,
        GUI_INPUT_BORDER_COLOR_BURLYWOOD,
        GUI_INPUT_BORDER_COLOR_CADETBLUE,
        GUI_INPUT_BORDER_COLOR_CHARTREUSE,
        GUI_INPUT_BORDER_COLOR_CHOCOLATE,
        GUI_INPUT_BORDER_COLOR_CORAL,
        GUI_INPUT_BORDER_COLOR_CORNFLOWERBLUE,
        GUI_INPUT_BORDER_COLOR_CORNSILK,
        GUI_INPUT_BORDER_COLOR_CRIMSON,
        GUI_INPUT_BORDER_COLOR_CYAN,
        GUI_INPUT_BORDER_COLOR_DARKBLUE,
        GUI_INPUT_BORDER_COLOR_DARKCYAN,
        GUI_INPUT_BORDER_COLOR_DARKGOLDENROD,
        GUI_INPUT_BORDER_COLOR_DARKGRAY,
        GUI_INPUT_BORDER_COLOR_DARKGREEN,
        GUI_INPUT_BORDER_COLOR_DARKGREY,
        GUI_INPUT_BORDER_COLOR_DARKKHAKI,
        GUI_INPUT_BORDER_COLOR_DARKMAGENTA,
        GUI_INPUT_BORDER_COLOR_DARKOLIVEGREEN,
        GUI_INPUT_BORDER_COLOR_DARKORANGE,
        GUI_INPUT_BORDER_COLOR_DARKORCHID,
        GUI_INPUT_BORDER_COLOR_DARKRED,
        GUI_INPUT_BORDER_COLOR_DARKSALMON,
        GUI_INPUT_BORDER_COLOR_DARKSEAGREEN,
        GUI_INPUT_BORDER_COLOR_DARKSLATEBLUE,
        GUI_INPUT_BORDER_COLOR_DARKSLATEGRAY,
        GUI_INPUT_BORDER_COLOR_DARKSLATEGREY,
        GUI_INPUT_BORDER_COLOR_DARKTURQUOISE,
        GUI_INPUT_BORDER_COLOR_DARKVIOLET,
        GUI_INPUT_BORDER_COLOR_DEEPPINK,
        GUI_INPUT_BORDER_COLOR_DEEPSKYBLUE,
        GUI_INPUT_BORDER_COLOR_DIMGRAY,
        GUI_INPUT_BORDER_COLOR_DIMGREY,
        GUI_INPUT_BORDER_COLOR_DODGERBLUE,
        GUI_INPUT_BORDER_COLOR_FIREBRICK,
        GUI_INPUT_BORDER_COLOR_FLORALWHITE,
        GUI_INPUT_BORDER_COLOR_FORESTGREEN,
        GUI_INPUT_BORDER_COLOR_FUCHSIA,
        GUI_INPUT_BORDER_COLOR_GAINSBORO,
        GUI_INPUT_BORDER_COLOR_GHOSTWHITE,
        GUI_INPUT_BORDER_COLOR_GOLD,
        GUI_INPUT_BORDER_COLOR_GOLDENROD,
        GUI_INPUT_BORDER_COLOR_GRAY,
        GUI_INPUT_BORDER_COLOR_GREY,
        GUI_INPUT_BORDER_COLOR_GREEN,
        GUI_INPUT_BORDER_COLOR_GREENYELLOW,
        GUI_INPUT_BORDER_COLOR_HONEYDEW,
        GUI_INPUT_BORDER_COLOR_HOTPINK,
        GUI_INPUT_BORDER_COLOR_INDIANRED,
        GUI_INPUT_BORDER_COLOR_INDIGO,
        GUI_INPUT_BORDER_COLOR_IVORY,
        GUI_INPUT_BORDER_COLOR_KHAKI,
        GUI_INPUT_BORDER_COLOR_LAVENDER,
        GUI_INPUT_BORDER_COLOR_LAVENDERBLUSH,
        GUI_INPUT_BORDER_COLOR_LAWNGREEN,
        GUI_INPUT_BORDER_COLOR_LEMONCHIFFON,
        GUI_INPUT_BORDER_COLOR_LIGHTBLUE,
        GUI_INPUT_BORDER_COLOR_LIGHTCORAL,
        GUI_INPUT_BORDER_COLOR_LIGHTCYAN,
        GUI_INPUT_BORDER_COLOR_LIGHTGOLDENRODYELLOW,
        GUI_INPUT_BORDER_COLOR_LIGHTGRAY,
        GUI_INPUT_BORDER_COLOR_LIGHTGREEN,
        GUI_INPUT_BORDER_COLOR_LIGHTGREY,
        GUI_INPUT_BORDER_COLOR_LIGHTPINK,
        GUI_INPUT_BORDER_COLOR_LIGHTSALMON,
        GUI_INPUT_BORDER_COLOR_LIGHTSEAGREEN,
        GUI_INPUT_BORDER_COLOR_LIGHTSKYBLUE,
        GUI_INPUT_BORDER_COLOR_LIGHTSLATEGRAY,
        GUI_INPUT_BORDER_COLOR_LIGHTSLATEGREY,
        GUI_INPUT_BORDER_COLOR_LIGHTSTEELBLUE,
        GUI_INPUT_BORDER_COLOR_LIGHTYELLOW,
        GUI_INPUT_BORDER_COLOR_LIME,
        GUI_INPUT_BORDER_COLOR_LIMEGREEN,
        GUI_INPUT_BORDER_COLOR_LINEN,
        GUI_INPUT_BORDER_COLOR_MAGENTA,
        GUI_INPUT_BORDER_COLOR_MAROON,
        GUI_INPUT_BORDER_COLOR_MEDIUMAQUAMARINE,
        GUI_INPUT_BORDER_COLOR_MEDIUMBLUE,
        GUI_INPUT_BORDER_COLOR_MEDIUMORCHID,
        GUI_INPUT_BORDER_COLOR_MEDIUMPURPLE,
        GUI_INPUT_BORDER_COLOR_MEDIUMSEAGREEN,
        GUI_INPUT_BORDER_COLOR_MEDIUMSLATEBLUE,
        GUI_INPUT_BORDER_COLOR_MEDIUMSPRINGGREEN,
        GUI_INPUT_BORDER_COLOR_MEDIUMTURQUOISE,
        GUI_INPUT_BORDER_COLOR_MEDIUMVIOLETRED,
        GUI_INPUT_BORDER_COLOR_MIDNIGHTBLUE,
        GUI_INPUT_BORDER_COLOR_MINTCREAM,
        GUI_INPUT_BORDER_COLOR_MISTYROSE,
        GUI_INPUT_BORDER_COLOR_MOCCASIN,
        GUI_INPUT_BORDER_COLOR_NAVAJOWHITE,
        GUI_INPUT_BORDER_COLOR_NAVY,
        GUI_INPUT_BORDER_COLOR_OLDLACE,
        GUI_INPUT_BORDER_COLOR_OLIVE,
        GUI_INPUT_BORDER_COLOR_OLIVEDRAB,
        GUI_INPUT_BORDER_COLOR_ORANGE,
        GUI_INPUT_BORDER_COLOR_ORANGERED,
        GUI_INPUT_BORDER_COLOR_ORCHID,
        GUI_INPUT_BORDER_COLOR_PALEGOLDENROD,
        GUI_INPUT_BORDER_COLOR_PALEGREEN,
        GUI_INPUT_BORDER_COLOR_PALETURQUOISE,
        GUI_INPUT_BORDER_COLOR_PALEVIOLETRED,
        GUI_INPUT_BORDER_COLOR_PAPAYAWHIP,
        GUI_INPUT_BORDER_COLOR_PEACHPUFF,
        GUI_INPUT_BORDER_COLOR_PERU,
        GUI_INPUT_BORDER_COLOR_PINK,
        GUI_INPUT_BORDER_COLOR_PLUM,
        GUI_INPUT_BORDER_COLOR_POWDERBLUE,
        GUI_INPUT_BORDER_COLOR_PURPLE,
        GUI_INPUT_BORDER_COLOR_RED,
        GUI_INPUT_BORDER_COLOR_ROSYBROWN,
        GUI_INPUT_BORDER_COLOR_ROYALBLUE,
        GUI_INPUT_BORDER_COLOR_SADDLEBROWN,
        GUI_INPUT_BORDER_COLOR_SALMON,
        GUI_INPUT_BORDER_COLOR_SANDYBROWN,
        GUI_INPUT_BORDER_COLOR_SEAGREEN,
        GUI_INPUT_BORDER_COLOR_SEASHELL,
        GUI_INPUT_BORDER_COLOR_SIENNA,
        GUI_INPUT_BORDER_COLOR_SILVER,
        GUI_INPUT_BORDER_COLOR_SKYBLUE,
        GUI_INPUT_BORDER_COLOR_SLATEBLUE,
        GUI_INPUT_BORDER_COLOR_SLATEGRAY,
        GUI_INPUT_BORDER_COLOR_SLATEGREY,
        GUI_INPUT_BORDER_COLOR_SNOW,
        GUI_INPUT_BORDER_COLOR_SPRINGGREEN,
        GUI_INPUT_BORDER_COLOR_STEELBLUE,
        GUI_INPUT_BORDER_COLOR_TAN,
        GUI_INPUT_BORDER_COLOR_TEAL,
        GUI_INPUT_BORDER_COLOR_THISTLE,
        GUI_INPUT_BORDER_COLOR_TOMATO,
        GUI_INPUT_BORDER_COLOR_TURQUOISE,
        GUI_INPUT_BORDER_COLOR_VIOLET,
        GUI_INPUT_BORDER_COLOR_WHEAT,
        GUI_INPUT_BORDER_COLOR_WHITE,
        GUI_INPUT_BORDER_COLOR_WHITESMOKE,
        GUI_INPUT_BORDER_COLOR_YELLOW,
        GUI_INPUT_BORDER_COLOR_YELLOWGREEN
    } gui_input_w3c_border_color_marker_enum;

    /* UI General input box structure            */
    extern UI_dialer_input_box_theme *current_dialer_input_box_theme;

#define UI_DIALER_INPUT_BOX_DISABLE_BACKGROUND        0x00000001
#define UI_DIALER_INPUT_BOX_DISABLE_DRAW           0x00000002
#define UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW       0x00000004
#define UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH 0x00000008
#define UI_DIALER_INPUT_BOX_STATE_MULTITAP            0x00000010
#define UI_DIALER_INPUT_BOX_OVERWRITE_MODE            0x00000020
#define UI_DIALER_INPUT_BOX_MASK_CHARACTERS           0x00000040
#define UI_DIALER_INPUT_BOX_SHOW_BLOCK_CURSOR         0x00000080
#define UI_DIALER_INPUT_BOX_CHARACTER_QUEUE           0x00000100
#define UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER        0x00000200
#define UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING      0x00000400
#define UI_DIALER_INPUT_BOX_SHOW_BORDER               0x00000800

    typedef struct _dialer_input_box
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *background_filler;
        U32 flags;
        UI_buffer_type text;
        S32 text_length;
        S32 allocated_length;
        S32 available_length;
        S32 n_lines;
        color text_color;
        color selection_text_color;
        color selection_color;
        color cursor_color;
        S8 text_gap;
        UI_font_type text_font;
        U8 mask_character;
        UI_buffer_type current_text_p;
        UI_buffer_type last_position_p;
        UI_buffer_type first_position_p;
        S32 UCS2_count;
        S32 cursor_x, cursor_y;
        void (*overflow_callback) (void);
        void (*change_callback) (void);
        void (*validation_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);
    } dialer_input_box;

    /* MTK Elvis for color dialling font */
    extern color gui_get_dialing_font_color(UI_character_type c);
    /* MTK end */

    extern void gui_set_dialer_input_box_current_theme(dialer_input_box *b);
    extern void gui_set_dialer_input_box_theme(dialer_input_box *b, UI_dialer_input_box_theme *t);
    extern void gui_create_dialer_input_box(dialer_input_box *b, S32 x, S32 y, S32 width, S32 height, S32 length);
    extern void gui_create_dialer_input_box_use_buffer(
                    dialer_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length);
    extern void gui_create_dialer_input_box_set_buffer(
                    dialer_input_box *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type buffer,
                    S32 length,
                    S32 text_length,
                    S32 edit_position);
    extern void gui_dialer_input_box_show_cursor(dialer_input_box *b, S32 x, S32 y, S32 height);
    extern void gui_show_dialer_input_box(dialer_input_box *b);
    extern void gui_show_dialer_input_box_ext(dialer_input_box *b, S32 move_to_x, S32 move_to_y);
    extern void gui_destroy_dialer_input_box(dialer_input_box *b);
    extern void gui_dialer_input_box_delete_character(dialer_input_box *b);
    extern void gui_dialer_input_box_insert_character(dialer_input_box *b, UI_character_type c);
    extern void gui_dialer_input_box_insert_multitap_character(dialer_input_box *b, UI_character_type c);
    extern void gui_dialer_input_box_confirm_multitap_character(dialer_input_box *b);
    extern void gui_dialer_input_box_previous(dialer_input_box *b);
    extern void gui_dialer_input_box_next(dialer_input_box *b);
    extern void gui_resize_dialer_input_box(dialer_input_box *b, S32 width, S32 height);
    extern void gui_move_dialer_input_box(dialer_input_box *b, S32 x, S32 y);
    extern void gui_dialer_input_box_delete_all(dialer_input_box *b);
    extern void gui_dialer_input_box_delete_current_character(dialer_input_box *b);
    extern void gui_dialer_input_box_toggle_insert_mode(dialer_input_box *b);
    extern void gui_dialer_input_box_goto_first_character(dialer_input_box *b);
    extern void gui_dialer_input_box_goto_last_character(dialer_input_box *b);
    extern void gui_dialer_input_box_clear(dialer_input_box *b);
    extern U8 gui_dialer_input_box_test_overflow(dialer_input_box *b);
    extern U8 gui_dialer_input_box_test_first_position(dialer_input_box *b);
    extern U8 gui_dialer_input_box_test_last_position(dialer_input_box *b);
    extern U8 gui_dialer_input_box_test_last_position_overflow(dialer_input_box *b);
    extern S32 gui_dialer_input_box_get_text_length(dialer_input_box *b);
    extern U8 gui_dialer_input_box_test_last_character_position(dialer_input_box *b);

    extern void UI_dummy_validation_function(UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);

    extern void UI_editor_play_tone_cannot_change(void);
    extern void UI_editor_play_tone_cannot_navigate(void);
    extern void UI_editor_play_tone_cannot_insert(void);
    extern void UI_editor_play_tone_invalid_data(void);
    extern void UI_editor_disable_tones(void);
    extern void UI_editor_enable_tones(void);

    extern void UI_inputbox_blink_cursor(void);
    extern void UI_inputbox_show_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void gui_multi_line_input_box_change(multi_line_input_box *b);

    extern void gui_get_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font);
    extern void gui_set_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font);
    extern void gui_set_multi_line_input_box_default_bg_color(
                          multi_line_input_box *b, 
                          color c, 
                          MMI_BOOL b_set);
    extern UI_buffer_type gui_multi_line_inputbox_adjust_cursor_for_icon_callback(multi_line_input_box *b, UI_buffer_type current_p, U8 direction);

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    extern S8 gui_parse_WCSS_string(U8 *s1, U8 *s2, U8 *s3, S16 str_len, U8 reserve_data);
    extern U8 gui_WCSS_check_next_multitap_input(multi_line_input_box *b);
    extern S32 get_category_115_format_buffer_length(U8 *s1, S32 buffer_size);
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    /* Gurinder - 5/5/2004 Inline Multiline Box History Control */
    extern void gui_create_multi_line_input_box_set_buffer_no_text_reset(
                    multi_line_input_box *,
                    S32,
                    S32,
                    S32,
                    S32,
                    UI_string_type,
                    S32,
                    S32,
                    S32);

#ifdef __MMI_TOUCH_DIAL_SCREEN__

    typedef enum
    {
        MMI_DIALING_KEY_START = 0,
        MMI_DIALING_KEY_STAR = 10,
        MMI_DIALING_KEY_ZERO,
        MMI_DIALING_KEY_HASH
  /*shaokai modify it.start 090817*/
    //#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)    
	,MMI_DIALING_KEY_FUNC,
	MMI_DIALING_KEY_CALL=MMI_DIALING_KEY_FUNC
	//#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
       ,MMI_DIALING_KEY_CALL_SLAVE,
       // #endif
	MMI_DIALING_KEY_PHB
    //#endif
        #if 0
    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
        ,MMI_DIALING_KEY_FUNC,
        MMI_DIALING_KEY_PHB = MMI_DIALING_KEY_FUNC,
        MMI_DIALING_KEY_CALL
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
        ,MMI_DIALING_KEY_CALL_SLAVE
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
    #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
 #endif
  /*shaokai modify it.start 090817*/
        ,MMI_DIALING_KEY_END
    } gui_dialing_key;

    typedef struct _dialing_keypad_struct
    {
        S32 keypad_x, keypad_y;
        S32 keypad_width, keypad_height;
        S32 key_width, key_height;
        S32 horizontal_gap, vertical_gap;
        S32 selected_key_x, selected_key_y;
        S32 n_rows, n_column;
    #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
        S32 keypad_func_x, keypad_func_y;
        S32 func_key_width, func_key_height;
        S32 func_horizontal_gap, func_vertical_gap;
        S32 func_n_rows, func_n_column;
    #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
        S32 key_type;   /* selected key index */
    #ifndef __GDI_MEMORY_PROFILE_2__
        gdi_image_cache_bmp_struct selected_key_bitmap;
    #endif 
    } dialing_keypad_struct;

    extern void gui_setup_dialing_keypad(dialing_keypad_struct *dialing_keypad);
    extern void gui_dialing_screen_translate_pen_position(
                    dialing_keypad_struct *dialing_keypad,
                    S32 x,
                    S32 y,
                    S32 *item_index);
    extern BOOL gui_dialing_screen_translate_pen_event(
                    dialing_keypad_struct *dialing_keypad,
                    S32 x,
                    S32 y,
                    mmi_pen_event_type_enum pen_event,
                    gui_dialing_key_pen_enum *menu_event,
                    gui_pen_event_param_struct *dialing_key_param);
    extern void gui_dialing_key_unselect(dialing_keypad_struct *dialing_keypad);
    extern void gui_dialing_key_select(dialing_keypad_struct *dialing_keypad, S32 item_index);

    /* 110105 dialing deflect Calvin Start */
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
    extern void gui_show_dialing_key(gui_dialing_key key, BOOL enableFlag);
#endif 
    /* 110105 dialing deflect Calvin End */
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_INPUTS_H__ */ 

