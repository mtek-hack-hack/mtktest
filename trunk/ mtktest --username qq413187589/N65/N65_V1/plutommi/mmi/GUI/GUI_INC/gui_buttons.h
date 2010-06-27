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
 *   gui_buttons.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Button - UI component 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
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

/**********************************************************************************
   Filename:      gui_buttons.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header for buttons
**********************************************************************************/

#ifndef __GUI_BUTTONS_H__
#define __GUI_BUTTONS_H__

#include "MMI_features.h"
#include "gui.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"

    typedef enum
    {
        GUI_BUTTON_PEN_NONE,            /* No event is generated. (but the low-level pen events might be still accepted) */
        GUI_BUTTON_PEN_DOWN,            /* Pen down on button */
        GUI_BUTTON_PEN_REPEAT,          /* Pen Repeat inside button */
        GUI_BUTTON_PEN_LONGTAP,         /* Pen LongTap inside button */
        GUI_BUTTON_PEN_UP_INSIDE,       /* Pen down on button */
        GUI_BUTTON_PEN_UP_OUTSIDE,      /* Pen up outside button */
        GUI_BUTTON_PEN_MOVE_OUTSIDE,    /* Pen is moved outside button */
        GUI_BUTTON_PEN_MOVE_INSIDE      /* Pen is moved into the button  */
    } gui_button_pen_enum;

    typedef struct
    {
        U8 pen_inside;
    } gui_button_pen_state_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    typedef void (*gui_button_clear_background_hdlr) (void *button_object);

    /* UI button structure                    */
    extern UI_button_theme *current_button_theme;

#define UI_BUTTON_TYPE_NORMAL                   0x00000000
#define UI_BUTTON_TYPE_TOGGLE                   0x00000001
#define UI_BUTTON_STATE_UP                      0x00000000
#define UI_BUTTON_STATE_DOWN                    0x00000100
#define UI_BUTTON_STATE_NORMAL                  0x00000000
#define UI_BUTTON_STATE_DISABLED                0x00000200
#define UI_BUTTON_STATE_FOCUSSED                0x00000400
#define UI_BUTTON_STATE_CLICKED                 0x00000800
#define UI_BUTTON_SHIFT_BUTTON1                 0x00001000
#define UI_BUTTON_SHIFT_BUTTON2                 0x00002000
#define UI_BUTTON_DISABLE_BACKGND_DISPLAY       0x00004000
#define UI_BUTTON_DISABLE_TEXT_DISPLAY          0x00008000
#define UI_BUTTON_CENTER_TEXT_X                 0x00010000
#define UI_BUTTON_CENTER_TEXT_Y                 0x00020000
#define UI_BUTTON_SHIFT_TEXT                    0x00040000
#define UI_BUTTON_SHIFT_ICON                    0x00080000
#define UI_BUTTON_CENTER_ICON_X                 0x00100000
#define UI_BUTTON_CENTER_ICON_Y                 0x00200000
#define UI_BUTTON_NO_UNDER_BAR                  0x00400000
#define UI_BUTTON_ALIGN_ICON_TEXT               0x00800000
#define UI_BUTTON_LEFT_ALIGN                    0x01000000
#define UI_BUTTON_RIGHT_ALIGN                   0x02000000
/* Always send GUI_BUTTON_PEN_UP_INSIDE even when pen is up outside the button */
#define UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE     0x04000000
/* Do not shift button when pressed down */
#define UI_BUTTON_NO_SHIFT_BUTTON               0x08000000

#define GUI_BUTTON_HORIZONTAL_GAP               2
#define GUI_BUTTON_VERTICAL_GAP                 2


    typedef struct _button
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_up_filler;
        UI_filled_area *normal_down_filler;
        UI_filled_area *disabled_up_filler;
        UI_filled_area *disabled_down_filler;
        UI_filled_area *clicked_up_filler;
        UI_filled_area *clicked_down_filler;
        UI_filled_area *focussed_up_filler;
        UI_filled_area *focussed_down_filler;
        U32 flags;
        gui_button_clear_background_hdlr clear_background_fp;
    #ifdef __MMI_TOUCH_SCREEN__
        gui_button_pen_state_struct pen_state;
    #endif 
    } button;

    extern void gui_set_button_current_theme(button *b);
    extern void gui_set_button_theme(button *b, UI_button_theme *t);
    extern void gui_create_button(button *b, S32 x, S32 y, S32 width, S32 height);
    extern void gui_show_button(button *b);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL gui_button_translate_pen_event(
                    button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* UI text_button structure               */

    extern UI_text_button_theme *current_text_button_theme;

    typedef struct _text_button
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_up_filler;
        UI_filled_area *normal_down_filler;
        UI_filled_area *disabled_up_filler;
        UI_filled_area *disabled_down_filler;
        UI_filled_area *clicked_up_filler;
        UI_filled_area *clicked_down_filler;
        UI_filled_area *focussed_up_filler;
        UI_filled_area *focussed_down_filler;
        U32 flags;
        S32 text_x, text_y, text_height;
        UI_string_type text;
        color normal_up_text_color;
        color normal_down_text_color;
        color disabled_up_text_color;
        color disabled_down_text_color;
        color focussed_up_text_color;
        color focussed_down_text_color;
        color clicked_up_text_color;
        color clicked_down_text_color;
        UI_font_type text_font;
        gui_button_clear_background_hdlr clear_background_fp;
    #ifdef __MMI_TOUCH_SCREEN__
        gui_button_pen_state_struct pen_state;
    #endif 
    } text_button;

    extern void gui_set_text_button_current_theme(text_button *b);
    extern void gui_set_text_button_theme(text_button *b, UI_text_button_theme *t);
    extern void gui_set_text_button_BG_theme(text_button *b, UI_button_theme *t);
    extern void gui_create_text_button(text_button *b, S32 x, S32 y, S32 width, S32 height, UI_string_type text);
    extern void gui_text_button_set_text_position(text_button *b, S32 x, S32 y);
    extern void gui_show_text_button(text_button *b);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL gui_text_button_translate_pen_event(
                    text_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    extern UI_icon_button_theme *current_icon_button_theme;

    typedef struct _icon_button
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_up_filler;
        UI_filled_area *normal_down_filler;
        UI_filled_area *disabled_up_filler;
        UI_filled_area *disabled_down_filler;
        UI_filled_area *clicked_up_filler;
        UI_filled_area *clicked_down_filler;
        UI_filled_area *focussed_up_filler;
        UI_filled_area *focussed_down_filler;
        U32 flags;
        PU8 normal_up_icon;
        PU8 normal_down_icon;
        PU8 disabled_up_icon;
        PU8 disabled_down_icon;
        PU8 clicked_up_icon;
        PU8 clicked_down_icon;
        PU8 focussed_up_icon;
        PU8 focussed_down_icon;
        S32 icon_x, icon_y;
        UI_transparent_color_type icon_transparent_color;
        gui_button_clear_background_hdlr clear_background_fp;
    #ifdef __MMI_TOUCH_SCREEN__
        gui_button_pen_state_struct pen_state;
    #endif 
    } icon_button;

    extern void gui_set_icon_button_current_theme(icon_button *b);
    extern void gui_set_icon_button_theme(icon_button *b, UI_icon_button_theme *t);
    extern void gui_set_icon_button_BG_theme(icon_button *b, UI_button_theme *t);
    extern void gui_create_icon_button(icon_button *b, S32 x, S32 y, S32 width, S32 height, PU8 button_icon);
    extern void gui_resize_icon_button(icon_button *b, S32 width, S32 height);
    extern void gui_move_icon_button(icon_button *b, S32 x, S32 y);
    extern void gui_icon_button_set_icon_positon(icon_button *b, S32 x, S32 y);
    extern void gui_icon_button_set_icon(
                    icon_button *b,
                    PU8 button_icon,
                    UI_transparent_color_type icon_transparent_color);
    extern void gui_show_icon_button(icon_button *b);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL gui_icon_button_translate_pen_event(
                    icon_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* UI icon text button structure             */
    extern UI_icontext_button_theme *current_icontext_button_theme;

    typedef struct _icontext_button
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_up_filler;
        UI_filled_area *normal_down_filler;
        UI_filled_area *disabled_up_filler;
        UI_filled_area *disabled_down_filler;
        UI_filled_area *clicked_up_filler;
        UI_filled_area *clicked_down_filler;
        UI_filled_area *focussed_up_filler;
        UI_filled_area *focussed_down_filler;
        U32 flags;
        PU8 normal_up_icon;
        PU8 normal_down_icon;
        PU8 disabled_up_icon;
        PU8 disabled_down_icon;
        PU8 clicked_up_icon;
        PU8 clicked_down_icon;
        PU8 focussed_up_icon;
        PU8 focussed_down_icon;
        S32 icon_x, icon_y;
        UI_transparent_color_type icon_transparent_color;
        S32 text_x, text_y, text_height, text_width;
        UI_string_type text;
        color normal_up_text_color;
        color normal_down_text_color;
        color disabled_up_text_color;
        color disabled_down_text_color;
        color focussed_up_text_color;
        color focussed_down_text_color;
        color clicked_up_text_color;
        color clicked_down_text_color;
        color normal_up_text_border_color;
        color normal_down_text_border_color;
        color disabled_up_text_border_color;
        color disabled_down_text_border_color;
        color focussed_up_text_border_color;
        color focussed_down_text_border_color;
        color clicked_up_text_border_color;
        color clicked_down_text_border_color;
        UI_font_type text_font;
        gui_button_clear_background_hdlr clear_background_fp;
        S32 touch_area_x1;
        S32 touch_area_y1;
        S32 touch_area_x2;
        S32 touch_area_y2;
        S32 display_area_x1;
        S32 display_area_y1;
        S32 display_area_x2;
        S32 display_area_y2;
    #ifdef __MMI_TOUCH_SCREEN__
        gui_button_pen_state_struct pen_state;
    #endif 
        S32 horizontal_gap;
    } icontext_button;

    extern void gui_set_icontext_button_current_theme(icontext_button *b);
    extern void gui_set_icontext_button_theme(icontext_button *b, UI_icontext_button_theme *t);
    extern void gui_set_icontext_button_BG_theme(icontext_button *b, UI_button_theme *t);
    extern void gui_create_icontext_button(
                    icontext_button *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type text,
                    PU8 button_icon);
    extern void gui_resize_icontext_button(icontext_button *b, S32 width, S32 height);
    extern void gui_move_icontext_button(icontext_button *b, S32 x, S32 y);
    extern void gui_icontext_button_set_icon_positon(icontext_button *b, S32 x, S32 y);
    extern void gui_icontext_button_set_text_position(icontext_button *b, S32 x, S32 y);
    extern void gui_icontext_button_set_icon(
                    icontext_button *b,
                    PU8 button_icon,
                    UI_transparent_color_type icon_transparent_color);
    extern void gui_show_icontext_button(icontext_button *b);
    extern void gui_icontext_set_horizontal_gap(icontext_button *b, S32 horizontal_gap);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL gui_icontext_button_translate_pen_event(
                    icontext_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);
    extern void gui_icontext_button_overwirte_pen_response_area(icontext_button *b, S32 x1, S32 y1, S32 x2, S32 y2);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    extern void gui_icontext_button_get_display_area(icontext_button *b, S32 *display_x1, S32 *display_y1, S32 *display_x2, S32 *display_y2);

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_BUTTONS_H__ */ 

