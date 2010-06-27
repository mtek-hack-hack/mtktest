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
 *  Wgui_title.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title
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

#ifndef __WGUI_TITLE_H__
#define __WGUI_TITLE_H__

#include "MMI_features.h"
#include "CustMenuRes.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_menu_shortcut.h"
#include "gui_title.h"

#define WGUI_TITLE_CHANGE_ICON           0x00000001
#define WGUI_TITLE_CHANGE_ICON2          0x00000002
#define WGUI_TITLE_CHANGE_TEXT           0x00000004

#define WGUI_TITLE_SHORTCUT_CHANGE_GOTO         0x00000001
#define WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO     0x00000002
#define WGUI_TITLE_SHORTCUT_CHANGE_ALL     (WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO | WGUI_TITLE_SHORTCUT_CHANGE_GOTO)

extern UI_string_type MMI_title_string;
extern PU8 MMI_title_icon;
extern PU8 MMI_title_icon2;
extern gui_title_struct g_wgui_title_bar;

#define MMI_menu_shortcut_box (g_wgui_title_bar.sc)

extern void wgui_title_create(void);
extern void wgui_title_close(void);
extern void wgui_title_show(U32 npart);
extern void wgui_title_stop_animation(void);
extern void wgui_title_move(S32 x, S32 y);
extern void wgui_title_resize(S32 width, S32 height);
extern void wgui_title_change(U16 icon_ID, U16 icon2_ID, U8 *text, U32 flag);
extern void wgui_title_start_scrolling(void);
extern void wgui_title_stop_scrolling(void);
extern void wgui_title_register_keys(void);
extern void wgui_title_register_callback(void (*pre_goto_funcptr) (S32 i), void (*goto_funcptr) (S32 i), U32 flag);
extern void wgui_title_set_shortcut_count(S32 n_items);
extern void wgui_title_set_style(U32 style);
extern void wgui_title_unset_style(U32 style);
extern void wgui_title_set_no_icon_shct(MMI_BOOL no_icon_shct);
extern void wgui_title_set_thick(MMI_BOOL thick); 

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
extern void wgui_title_stop_animation(void);
extern void wgui_title_start_animation(void);
extern MMI_BOOL wgui_title_is_animation_enabled(void);
extern void wgui_title_enable_animation(MMI_BOOL enable_animation);
extern void wgui_title_unset_animation_style(void);
extern void wgui_title_set_animation_style(wgui_title_effect_styles animated_style);

#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

#ifdef __MMI_UI_TITLE_TRANSITION__
extern MMI_BOOL wgui_title_in_transition_blocking(void);
extern void wgui_title_set_transition_enable(MMI_BOOL enable);
extern MMI_BOOL wgui_title_is_transition_enable(void);
extern void wgui_title_set_transition(gui_title_transition_enum style);
extern gui_title_transition_enum wgui_title_get_transition(void);
extern void wgui_title_set_transition_on_keys(MMI_BOOL onkey);
extern MMI_BOOL wgui_title_get_transition_on_keys(void);

#ifdef TITLE_TRANSITION_STYLE_NON_BLOCKING
extern void wgui_title_stop_transition_non_blocking(void);
extern void wgui_title_enable_transition(MMI_BOOL enable_transition);
extern S32 wgui_title_is_transition_enabled(void);
#endif /* TITLE_TRANSITION_STYLE_NON_BLOCKING */ 
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 

/*
 * Backward-compatible API
 */
extern void draw_title(void);
extern void wgui_stop_title_animation(void);
extern void draw_title_wap(void);   /* 070705 Calvin added */
extern void draw_title_left_align(void);

#ifdef __MMI_UI_TITLE_TRANSITION__
extern void set_title_transition_based_on_keys(void);
extern void set_title_transition(wgui_transition_styles style);
extern S32 get_title_transition(void);
extern void reset_title_transition(void);
extern void draw_transition_tite(void);
extern S32 is_mmi_title_transition_on_keys(void);

#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
#define TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT

#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
#define MAX_TITLE_AREA_HEIGHT_FOR_TRANSITION (MMI_TITLE_HEIGHT + MMI_MENUITEM_HEIGHT)
#endif /*TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT*/

extern void wgui_stop_transition_title_non_blocking(void);
extern void save_copy_original_title_x(void);
extern S32 is_in_nonblocking_title_transition(void);
extern void wgui_title_tranisition_abort_cleanup_function(void);
extern void enable_title_transition(void);
extern void disable_title_transition(void);
extern S32 is_enable_title_transition(void);

#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
extern S32 get_prev_menu_shortcut(void);
extern void reset_prev_menu_shortcut(void);
extern void set_prev_menu_shortcut(S32 menu_shortcut_index);
#else /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
extern void set_previous_title_shortcut(S32 shortcut_no);
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 

#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 

#endif /* __MMI_UI_TITLE_TRANSITION__ */ 
extern void move_title(S32 s32X, S32 s32Y);
extern void resize_title(S32 s32Width, S32 s32Height);
extern void ChangeTitleString(U8 *string);
extern void ChangeTitleIcon(U16 image_ID);
extern void ChangeTitle(U16 image_ID, U8 *string);
extern void draw_scrolling_title(void);
extern void draw_scrolling_title_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void scrolling_title_timer_callback(void);
extern void setup_scrolling_title(void);
extern void close_scrolling_title(void);

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
extern void wgui_stop_animate_title(void);
extern void wgui_start_animate_title(void);
extern void disable_animated_title_effect(void);
extern void enable_animated_title_effect(void);
extern void wgui_draw_animate_title_image_frame_0(S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_title_draw_animate_image_frame_0(S32 x1, S32 y1, S32 x2, S32 y2);
extern S32 is_enable_animated_title_effect(void);
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

#if defined(__MMI_TOUCH_SCREEN__)

extern FuncPtr gMMI_touch_title_button1_down_handler;
extern FuncPtr gMMI_touch_title_button1_up_handler;
extern FuncPtr gMMI_touch_title_button2_down_handler;
extern FuncPtr gMMI_touch_title_button2_up_handler;

extern void register_touch_button_handlers(FuncPtr f1_up, FuncPtr f1_down, FuncPtr f2_up, FuncPtr f2_down);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

extern void wgui_set_touch_title_bar_buttons(void);
extern void wgui_reset_touch_title_bar_buttons(void);
extern MMI_BOOL wgui_is_touch_title_bar_buttons(void);

/* for menu shortcut wrapper */

extern void create_menu_shortcut_handler(void);
extern void register_menu_shortcut_keys(void);

extern void move_menu_shortcut_handler(S32 x, S32 y);
extern void resize_menu_shortcut_handler(S32 width, S32 height);
extern void override_menu_shortcut_default_region(S32 x, S32 y, S32 width, S32 height);

extern void register_hide_menu_shortcut(void (*f) (void));
extern void reset_menu_shortcut_handler(void);

extern S32 set_menu_item_count(S32 n_items);
extern void gui_hide_menu_shortcut(void);
extern void gui_redraw_menu_shortcut(void);
extern void show_menu_shortcut(void);
extern void register_menu_shortcut_handler(void (*f) (S32 i));
extern void register_menu_shortcut_selected(void (*f) (S32 i));
extern void register_menu_shortcut_selected_only(void (*f) (S32 i));

extern void wgui_set_disable_shortcut_display(void);
extern void wgui_reset_disable_shortcut_display(void);
extern BOOL wgui_is_disable_shortcut_display(void);

#endif /* __WGUI_TITLE_H__ */ 

