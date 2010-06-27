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
 *   gui_scrollbars.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Scrollbar - UI component
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

/**********************************************************************************
   Filename:      gui_scrollbars.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header for scrollbars, progress indicators,
               Slide controls --etc.
**********************************************************************************/

#ifndef __GUI_SCROLLBARS_H__
#define __GUI_SCROLLBARS_H__

#include "gui.h"
#include "gui_buttons.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"
#include "gui_scrollbars_pre_oem.h"


/* MTK Leo end */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

typedef enum
{
    GUI_SCROLLBAR_REGION_VERTICAL,
    GUI_SCROLLBAR_REGION_HORIZONTAL
} gui_scrollbar_region_enum;


typedef enum
{
    GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL,
    GUI_SCROLLBAR_BUTTON_UP,
    GUI_SCROLLBAR_BUTTON_DOWN,
    GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL,
    GUI_SCROLLBAR_BUTTON_LEFT,
    GUI_SCROLLBAR_BUTTON_RIGHT
} gui_scrollbar_buttton_enum;
#ifdef __MMI_TOUCH_SCREEN__

    /* In the current UI design,  we do not apply Up/Down button in scrollbar */

#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"

    /* the range that user can drag the scroll button */
#define GUI_SCROLLBAR_VALID_RANGE   (50)

    typedef enum
    {
        GUI_SCROLLBAR_PEN_NONE,     /* No event is generated. (but the low-level pen events might be still accepted) */
        GUI_SCROLLBAR_PEN_JUMP_TO_I /* Jump to certain item */
    } gui_scrollbar_pen_enum;

    typedef enum
    {
        GUI_SCROLLBAR_PEN_STATE_INVALID,
        GUI_SCROLLBAR_PEN_STATE_AREA1,
        GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE,      /* Outside bar */
        GUI_SCROLLBAR_PEN_STATE_AREA2,
        GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE,      /* Outside bar */
        GUI_SCROLLBAR_PEN_STATE_SBUTTON,
        GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE,    /* Outside bar for GUI_SCROLLBAR_VALID_RANGE */
        GUI_SCROLLBAR_PEN_STATE_BUTTON1,
        GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE,
        GUI_SCROLLBAR_PEN_STATE_BUTTON2,
        GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE
    } gui_scrollbar_pen_state_enum;

    typedef struct
    {
        gui_scrollbar_pen_state_enum state;
        /* Space excluding up/down/scroll button area */
        S16 remain_space;
        /* The relative position where user press on  scroll button */
        S16 initial_pen_down_pos;
        S16 initial_sbutton_pos;
        /* Original scrollbar value */
        U32 original_value;
        /* Previous value in gui_vertical(horizontal)_scrollbar_translate_pen_event */
        U32 previous_value;
    } gui_scrollbar_pen_state_struct;

#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* UI vertical_scrollbar structure              */

#define UI_VERTICAL_SCROLLBAR_STATE_NORMAL         0x00000000
#define UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED    0x00000001
#define UI_VERTICAL_SCROLLBAR_STATE_DISABLED    0x00000002
#define UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT1        0x00000010
#define UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT2        0x00000020
#define UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS      0x00000040
    extern UI_vertical_scrollbar_theme *current_vertical_scrollbar_theme;

    typedef struct _vertical_scrollbar
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 scale;
        U32 flags;
        UI_filled_area *focussed_bar_filler;
        UI_filled_area *normal_bar_filler;
        UI_filled_area *disabled_bar_filler;
        icon_button up_button;
        icon_button down_button;
        icon_button scroll_button;
    #ifdef __MMI_TOUCH_SCREEN__
        S16 min_pen_offset;
        S16 pen_self_scroll;
        gui_scrollbar_pen_state_struct pen_state;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    } vertical_scrollbar;

    extern void gui_set_vertical_scrollbar_current_theme(vertical_scrollbar *v);
    extern void gui_set_vertical_scrollbar_theme(vertical_scrollbar *v, UI_vertical_scrollbar_theme *t);
    extern void gui_create_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y, S32 width, S32 height);
    extern void gui_set_vertical_scrollbar_range(vertical_scrollbar *v, S32 range);
    extern void gui_set_vertical_scrollbar_value(vertical_scrollbar *v, S32 value);
    extern void gui_set_vertical_scrollbar_scale(vertical_scrollbar *v, S32 scale);
    extern void gui_move_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y);
    extern void gui_resize_vertical_scrollbar(vertical_scrollbar *v, S32 width, S32 height);
    extern void (*gui_show_vertical_scrollbar)(vertical_scrollbar *v);
    extern void (*gui_vertical_scrollbar_redraw_button)(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
#ifdef __MMI_TOUCH_SCREEN__
    extern void gui_vertical_scrollbar_set_minimum_pen_offset(vertical_scrollbar *v, S32 min_offset);
    extern void gui_vertical_scrollbar_set_pen_self_scroll(vertical_scrollbar *v, BOOL enable);
    extern void gui_vertical_scrollbar_reconfigure_pen_value(vertical_scrollbar *v, S16 x, S16 y);
    extern BOOL gui_vertical_scrollbar_translate_pen_event(
                    vertical_scrollbar *v,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_scrollbar_pen_enum *scrollbar_event,
                    gui_pen_event_param_struct *scrollbar_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* UI horizontal_scrollbar structure               */

#define UI_HORIZONTAL_SCROLLBAR_STATE_NORMAL    0x00000000
#define UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED     0x00000001
#define UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED     0x00000002
#define UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT1      0x00000010
#define UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT2      0x00000020
#define UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS    0x00000040
    extern UI_horizontal_scrollbar_theme *current_horizontal_scrollbar_theme;

    typedef struct _horizontal_scrollbar
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 scale;
        U32 flags;
        UI_filled_area *focussed_bar_filler;
        UI_filled_area *normal_bar_filler;
        UI_filled_area *disabled_bar_filler;
        icon_button left_button;
        icon_button right_button;
        icon_button scroll_button;
    #ifdef __MMI_TOUCH_SCREEN__
        S16 min_pen_offset;
        S16 pen_self_scroll;
        gui_scrollbar_pen_state_struct pen_state;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    } horizontal_scrollbar;

    extern void gui_set_horizontal_scrollbar_current_theme(horizontal_scrollbar *v);
    extern void gui_set_horizontal_scrollbar_theme(horizontal_scrollbar *v, UI_horizontal_scrollbar_theme *t);
    extern void gui_create_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y, S32 width, S32 height);
    extern void gui_set_horizontal_scrollbar_range(horizontal_scrollbar *v, S32 range);
    extern void gui_set_horizontal_scrollbar_value(horizontal_scrollbar *v, S32 value);
    extern void gui_set_horizontal_scrollbar_scale(horizontal_scrollbar *v, S32 scale);
    extern void gui_move_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y);
    extern void gui_resize_horizontal_scrollbar(horizontal_scrollbar *v, S32 width, S32 height);
    extern void (*gui_show_horizontal_scrollbar)(horizontal_scrollbar *v);
    extern void (*gui_horizontal_scrollbar_redraw_button)(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
#ifdef __MMI_TOUCH_SCREEN__
    extern void gui_horizontal_scrollbar_set_minimum_pen_offset(horizontal_scrollbar *h, S32 min_offset);
    extern void gui_horizontal_scrollbar_set_pen_self_scroll(horizontal_scrollbar *h, BOOL enable);
    extern void gui_horizontal_scrollbar_reconfigure_pen_value(horizontal_scrollbar *h, S16 x, S16 y);
    extern BOOL gui_horizontal_scrollbar_translate_pen_event(
                    horizontal_scrollbar *h,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_scrollbar_pen_enum *scrollbar_event,
                    gui_pen_event_param_struct *scrollbar_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 

extern MMI_BOOL gui_scrollbar_redraw_clip_enable;

extern void gui_enable_scrollbar_redraw_clip(MMI_BOOL enable);

    /* UI Horizontal Progress Indicator structure               */

#define  UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_STEP            0x00000001
#define UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR    0x00000002
#define UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_REVERSE       0x00000004
    extern UI_horizontal_progress_indicator_theme *current_horizontal_progress_indicator_theme;

    typedef struct _horizontal_progress_indicator
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 flags;
        UI_filled_area *background_filler;
        UI_filled_area *foreground_filler;
        S32 n_fillers;
        U8 *percentages;
        S32 block_width;
        S32 block_gap;
        S32 border_gap;
    } horizontal_progress_indicator;

    extern void gui_set_horizontal_progress_indicator_theme(horizontal_progress_indicator *pi);
    extern void gui_create_horizontal_progress_indicator(
                    horizontal_progress_indicator *pi,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height);
    extern void gui_set_horizontal_progress_indicator_range(horizontal_progress_indicator *pi, S32 range);
    extern void gui_set_horizontal_progress_indicator_value(horizontal_progress_indicator *pi, S32 value);
    extern void gui_show_horizontal_progress_indicator(horizontal_progress_indicator *pi);

    /* UI vertical Progress Indicator structure              */

#define  UI_VERTICAL_PROGRESS_INDICATOR_TYPE_STEP           0x00000001
#define UI_VERTICAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR         0x00000002
#define UI_VERTICAL_PROGRESS_INDICATOR_TYPE_REVERSE            0x00000004

    extern UI_vertical_progress_indicator_theme *current_vertical_progress_indicator_theme;

    typedef struct _vertical_progress_indicator
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 flags;
        UI_filled_area *background_filler;
        UI_filled_area *foreground_filler;
        S32 n_fillers;
        U8 *percentages;
        S32 block_height;
        S32 block_gap;
        S32 border_gap;
    } vertical_progress_indicator;

    extern void gui_set_vertical_progress_indicator_theme(vertical_progress_indicator *pi);
    extern void gui_create_vertical_progress_indicator(
                    vertical_progress_indicator *pi,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height);
    extern void gui_set_vertical_progress_indicator_range(vertical_progress_indicator *pi, S32 range);
    extern void gui_set_vertical_progress_indicator_value(vertical_progress_indicator *pi, S32 value);
    extern void gui_show_vertical_progress_indicator(vertical_progress_indicator *pi);

    /* UI vertical_slide structure               */

#define UI_VERTICAL_SLIDE_STATE_NORMAL       0x00000000
#define UI_VERTICAL_SLIDE_STATE_FOCUSSED     0x00000001
#define UI_VERTICAL_SLIDE_STATE_DISABLED     0x00000002
#define UI_VERTICAL_SLIDE_TYPE_REVERSE       0x00000004

    extern UI_vertical_slide_theme *current_vertical_slide_theme;

    typedef struct _vertical_slide
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 scale;
        U32 flags;
        UI_filled_area *focussed_bar_filler;
        UI_filled_area *normal_bar_filler;
        UI_filled_area *disabled_bar_filler;
        icon_button scroll_button;
    } vertical_slide;

    extern void gui_set_vertical_slide_current_theme(vertical_slide *v);
    extern void gui_set_vertical_slide_theme(vertical_slide *v, UI_vertical_slide_theme *t);
    extern void gui_create_vertical_slide(vertical_slide *v, S32 x, S32 y, S32 width, S32 height);
    extern void gui_set_vertical_slide_range(vertical_slide *v, S32 range);
    extern void gui_set_vertical_slide_value(vertical_slide *v, S32 value);
    extern void gui_set_vertical_slide_scale(vertical_slide *v, S32 scale);
    extern void gui_move_vertical_slide(vertical_slide *v, S32 x, S32 y);
    extern void gui_resize_vertical_slide(vertical_slide *v, S32 width, S32 height);
    extern void gui_show_vertical_slide(vertical_slide *v);

    /* UI horizontal_slide structure             */

#define UI_HORIZONTAL_SLIDE_STATE_NORMAL     0x00000000
#define UI_HORIZONTAL_SLIDE_STATE_FOCUSSED      0x00000001
#define UI_HORIZONTAL_SLIDE_STATE_DISABLED      0x00000002
#define UI_HORIZONTAL_SLIDE_TYPE_REVERSE     0x00000004

    extern UI_horizontal_slide_theme *current_horizontal_slide_theme;

    typedef struct _horizontal_slide
    {
        S32 x, y;
        S32 width, height;
        U32 range;
        U32 value;
        U32 scale;
        U32 flags;
        UI_filled_area *focussed_bar_filler;
        UI_filled_area *normal_bar_filler;
        UI_filled_area *disabled_bar_filler;
        icon_button scroll_button;
    } horizontal_slide;

    extern void gui_set_horizontal_slide_current_theme(horizontal_slide *v);
    extern void gui_set_horizontal_slide_theme(horizontal_slide *v, UI_horizontal_slide_theme *t);
    extern void gui_create_horizontal_slide(horizontal_slide *v, S32 x, S32 y, S32 width, S32 height);
    extern void gui_set_horizontal_slide_range(horizontal_slide *v, S32 range);
    extern void gui_set_horizontal_slide_value(horizontal_slide *v, S32 value);
    extern void gui_set_horizontal_slide_scale(horizontal_slide *v, S32 scale);
    extern void gui_move_horizontal_slide(horizontal_slide *v, S32 x, S32 y);
    extern void gui_resize_horizontal_slide(horizontal_slide *v, S32 width, S32 height);
    extern void gui_show_horizontal_slide(horizontal_slide *v);

#ifdef __cplusplus
}
#endif 
#include "gui_scrollbars_post_oem.h"

#endif /* __GUI_SCROLLBARS_H__ */ 

