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
 * Filename:
 * ---------
 *  gui_panel.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel - UI component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

#ifndef __GUI_PANEL_H__
#define __GUI_PANEL_H__

#include "gui.h"
#include "kal_non_specific_general_types.h"
#include "FrameworkStruct.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "TouchScreenGprot.h"
#endif

#define GUI_PANEL_MAX_ELEMENT_COUNT     (20)
#define GUI_PANEL_MAX_ANIMATOR_COUNT    (3)

/* default time period of repeat events in milliseconds */
#define GUI_PANEL_DEFAULT_REPEAT_PERIOD (300)

typedef enum 
{
    GUI_PANEL_ANIM_STATE_STOPPED,
    GUI_PANEL_ANIM_STATE_STARTED,
    GUI_PANEL_ANIM_STATE_END_OF_ENUM
} gui_panel_anim_state_enum;

/* State of a panel element */
typedef enum
{
    GUI_PANEL_ELEM_STATE_NORMAL = 0,
    GUI_PANEL_ELEM_STATE_DOWN,
    GUI_PANEL_ELEM_STATE_FOCUSSED,
    GUI_PANEL_ELEM_STATE_DISABLED,
    GUI_PANEL_ELEM_STATE_TOTAL
} gui_panel_elem_state_enum;

/* UI Component: an element inside a panel */
typedef struct
{
    /* Position */
    S32 x1, y1, x2, y2;
    
    /* Registered key (KEY_INVALID if not registered) */
    U16 keycode;

    /* Callback function on Pen Down or Key Down */
    FuncPtr down_event_callback;

    /* Callback function on Pen Up or Key Up */
    FuncPtr up_event_callback;

    /* Callback function when key stays pressed or pen stays on element */
    FuncPtr repeat_event_callback;
    
    /* Painter of normal (up/unfocussed), down, foccussed state  */
    gui_util_painter_struct painters[GUI_PANEL_ELEM_STATE_TOTAL];

    /* 0: up, 1: down */
    U32 down_state : 1;

    /* 0: normal, 1: disabled */
    U32 disabled_state : 1;
    
    /* Whether to redraw the panel background after pressed/released/focused/unfocussed.
       This flag depends on the shape of each painter */
    U32 redraw_bg_after_state_changed : 1;
} gui_panel_element_struct;

typedef struct
{
    /* Position */
    S32 x1, y1, x2, y2;
    // TODO: unfinished
} gui_panel_animator_struct;

/* UI Component: a panel */
typedef struct
{
    S32 x, y;
    S32 width, height;

    /* Panel background */
    gui_util_painter_struct background;

    /* Elements */
    gui_panel_element_struct elements[GUI_PANEL_MAX_ELEMENT_COUNT];
    S32 element_count;    
    S32 element_focus_index;

#ifdef __MMI_TOUCH_SCREEN__
    S32 element_pen_down_index;
#endif

    /* repeat event period in milliseconds */
    U32 repeat_period;

    /* Animators */
    S32 animator_count;
    gui_panel_animator_struct animators[GUI_PANEL_MAX_ANIMATOR_COUNT];
    
    /* Change the display of an element when it's focussed */
    U32 display_focus : 1;
} gui_panel_struct;

extern void gui_panel_create(
                gui_panel_struct *panel,
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                gui_util_painter_struct background,
                MMI_BOOL display_focus,
                U32 repeat_period);

extern void gui_panel_show(gui_panel_struct *panel);

extern void gui_panel_set_element_focus(
                gui_panel_struct *panel,
                S32 element_index,
                MMI_BOOL update_display);

extern S32 gui_panel_get_element_focus(gui_panel_struct *panel);

extern S32 gui_panel_add_element(
                gui_panel_struct *panel,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U16 keycode,
                FuncPtr down_event_callback,
                FuncPtr up_event_callback,
                FuncPtr repeat_event_callback,
                gui_util_painter_struct normal_painter,
                gui_util_painter_struct down_painter,
                gui_util_painter_struct focussed_painter,
                gui_util_painter_struct disabled_painter,
                MMI_BOOL redraw_bg_after_state_changed);

extern void gui_panel_enable_element(
                gui_panel_struct *panel,
                S32 elem_idx,
                MMI_BOOL enabled,
                MMI_BOOL update_display);

extern void gui_panel_general_key_handler(gui_panel_struct *panel, U16 keycode, U16 keytype);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_panel_translate_pen_event(
                    gui_panel_struct *panel,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y);
#endif /* __MMI_TOUCH_SCREEN__ */ 

extern void gui_panel_set_element_image_id(
        gui_panel_struct *panel,
        S32 element_index,
        gui_panel_elem_state_enum state,
        MMI_ID_TYPE image_id);


#endif /* __GUI_PANEL_H__ */

