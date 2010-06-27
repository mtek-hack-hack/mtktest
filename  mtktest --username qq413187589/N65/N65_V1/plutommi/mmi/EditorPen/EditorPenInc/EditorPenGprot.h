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
 * EditorPenGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is exported interface for EditPen Module
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
#ifndef _EDITOR_PEN_GPROT_H
#define _EDITOR_PEN_GPROT_H


#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "gui_data_types.h"
#include "gui_inputs.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_inputs.h"
#include "wgui_inputs.h"
#include "gui_ems.h"
#include "gui_inputs.h"
#include "gui_themes.h"
#include "wgui_datetime.h"
#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_inline_edit.h"
#include "TouchScreenGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define PEN_EDITOR_CHARACTER_END_PERIOD gPenEditorHWSpeedSet[gPenEditorHWSpeed][0]      /* 750 */
#define PEN_EDITOR_CONFIRM_PERIOD gPenEditorHWSpeedSet[gPenEditorHWSpeed][1]    /* 1750 */
#define PEN_EDITOR_MAX_CANDIDATE_SIZE 20
/* W05.39 Fix the number of characters in Candidate List */ 
#ifdef __MMI_MAINLCD_128X160__
#define PEN_EDITOR_CANDIDATE_SIZE (8)
#else
#define PEN_EDITOR_CANDIDATE_SIZE (9)   /* (9)//((UI_device_width)/gui_get_character_width(0x4E00)-2) */
#endif /* __MMI_MAINLCD_128X160__ */
#define PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS (7)
#define PEN_EDITOR_STROKE_BUFFER_SIZE 500
#define PEN_EDITOR_MAX_CONTROL_SET_SIZE 10
#define PEN_EDITOR_MAX_VK_TEXT_SIZE 7
#define PEN_EDITOR_MAX_BOPOMOFO_SIZE 4
#define PEN_EDITOR_MAX_PINYIN_SIZE 7
#define PEN_EDITOR_MAX_SYLLABLE_CANDIDATE_SIZE 6
#define PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_SCROLL_DELAY 250
#define PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_LINES 25
#define  PEN_EDITOR_DISABLE_HANDWRITNG (1)
#define  PEN_EDITOR_DISABLE_VIRTUAL_KEYBOARD (1<<1)
#define  PEN_EDITOR_DISABLE_KEYPAD (1<<2)
#define PEN_EDITOR_MAX_KEY_BUFFER_SIZE 256
#define PEN_EDITOR_MAX_COMPOSITION_SIZE 128
#define PEN_EDITOR_MAX_SYLLABLE_BUFFER_SIZE 128
#define PEN_EDITOR_VK_MAX_DISABLE_KEYS 20
#define PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM (MMI_content_y + MMI_content_height - mmi_pen_editor_get_candidate_box_height())
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    PEN_EDITOR_NONE = 0,
    PEN_EDITOR_TRADITIONAL_CHINESE,
    PEN_EDITOR_SIMPLIFIED_CHINESE,
    PEN_EDITOR_UPPER_CASE_ENGLISH,
    PEN_EDITOR_LOWER_CASE_ENGLISH,
    PEN_EDITOR_UPPER_CASE_RUSSIAN,
    PEN_EDITOR_LOWER_CASE_RUSSIAN,
    PEN_EDITOR_THAI,//UNI@bw_0802_0002 增加泰文手写输入法     
    PEN_EDITOR_NUMBER,
    PEN_EDITOR_PUNCTUATION
} mmi_pen_editor_input_type_enum;

typedef enum
{
    PEN_EDITOR_MULTILINE_INPUT_BOX,
    PEN_EDITOR_EMS_INPUT_BOX,
    PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX,
    PEN_EDITOR_SINGLE_LINE_INPU_BOX,
    PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX,
    PEN_EDITOR_INLINE_TEXT,
    PEN_EDITOR_DATE,
    PEN_EDITOR_IP4,
    PEN_EDITOR_TIME,
    PEN_EDITOR_TIME_PERIOD,
    PEN_EDITOR_DICT_MULTILINE_INPUT_BOX,
    PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR,
    PEN_EDITOR_NONE_INPUT_BOX
} mmi_pen_editor_input_box_type_enum;

typedef enum
{
    PEN_EDITOR_VK_ON,
    PEN_EDITOR_VK_OFF,
    PEN_EDITOR_VK_GRAY,
    PEN_EDITOR_VK_NONE
} mmi_pen_editor_virtual_keyboard_state_enum;

typedef enum
{
    PEN_EDITOR_CONTROL_INFORMATION_BAR,
    PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX,
    PEN_EDITOR_CONTROL_EMS_INPUT_BOX,
    PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX,
    PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX,
    PEN_EDITOR_CONTROL_INLINE_TEXT,
    PEN_EDITOR_CONTROL_DATE,
    PEN_EDITOR_CONTROL_IP4,
    PEN_EDITOR_CONTROL_TIME,
    PEN_EDITOR_CONTROL_TIME_PERIOD,
    PEN_EDITOR_CONTROL_SCROLL_BAR,
    PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD,
    PEN_EDITOR_CONTROL_COMPOSITION_AREA,
    PEN_EDITOR_CONTROL_CANDIDATE_AREA,
    PEN_EDITOR_CONTROL_IME_BUTTON,
    PEN_EDITOR_CONTROL_MULTITAP,
    PEN_EDITOR_CONTROL_PAGING_IN_MULTLINE_EDITOR,
    PEN_EDITOR_CONTROL_NONE
} mmi_pen_editor_control_type_enum;

typedef enum
{
    PEN_EDITOR_SORT_CAPITAL_FIRST,
    PEN_EDITOR_SORT_NON_CAPITAL_FIRST
} mmi_pen_editor_resort_type_enum;

typedef enum
{
    PEN_EDITOR_RSK_BY_STATE,
    PEN_EDITOR_RSK_BACK,
    PEN_EDITOR_RSK_CLEAR
} mmi_pen_editor_rsk_type_enum;

typedef enum
{
    PEN_EDITOR_CANDIDATE_OFF,
    PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS,
    PEN_EDITOR_CANDIDATE_ON_AND_FOCUS
} mmi_pen_editor_candidate_state_enum;

typedef enum
{
    PEN_EDITOR_IN_CONTROL,
    PEN_EDITOR_IN_RIGHT_ARROW,
    PEN_EDITOR_IN_LEFT_ARROW,
    PEN_EDITOR_MOVE_OUT,
    PEN_EDITOR_OUT_OF_RANGE
} mmi_pen_editor_control_with_arrow_enum;

typedef enum
{
    PEN_EDITOR_ARROW_PRESS_UP,
    PEN_EDITOR_ARROW_PRESS_DOWN,
    PEN_EDITOR_ARROW_DISABLE
} mmi_pen_editor_arrow_state_enum;

typedef enum
{
    PEN_EDITOR_ARROW_DIRECTION_UP,
    PEN_EDITOR_ARROW_DIRECTION_DOWN,
    PEN_EDITOR_ARROW_DIRECTION_LEFT,
    PEN_EDITOR_ARROW_DIRECTION_RIGHT
} mmi_pen_editor_arrow_direction_enum;

typedef enum
{
    PEN_EDITOR_ARROW_FOR_CANDIDATE,
    PEN_EDITOR_ARROW_FOR_COMPOSITION
} mmi_pen_editor_arrow_type_enum;

typedef enum
{
    PEN_EDITOR_HANDWRITING_STYLE_FULL_SCREEN,
    PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK
} mmi_pen_editor_handwriting_style_enum;

typedef struct
{
    U8 NumberofControlSets;
    U8 reserverd1;
    U16 reserverd2;
    mmi_pen_editor_control_type_enum PenEditorControlSet[PEN_EDITOR_MAX_CONTROL_SET_SIZE];
} mmi_pen_editor_control_set_struct;

typedef struct
{
    S8 TextLength;
    U8 reserverd1;
    U16 reserverd2;
    UI_character_type VKText[PEN_EDITOR_MAX_VK_TEXT_SIZE + 1];
} mmi_pen_editor_vk_text_struct;

typedef struct
{
    U32 KeyLength;
    mmi_keypads_enum KeySequence[PEN_EDITOR_MAX_KEY_BUFFER_SIZE + 1];
} mmi_pen_editor_key_sequence_struct;

typedef struct
{
    mmi_pen_editor_candidate_state_enum candidate_state;
    MMI_BOOL arrow_enable;
    mmi_pen_editor_arrow_state_enum left_arrow_state;
    mmi_pen_editor_arrow_state_enum right_arrow_state;
    mmi_pen_editor_control_with_arrow_enum pen_down_state;
    UI_character_type selected_candidate;
} mmi_pen_editor_candidate_state_struct;

typedef struct
{
    MMI_BOOL is_allowed;
    MMI_BOOL is_changed;
    UI_character_type *characters_list;
    gui_virtual_keyboard_pen_enum *event_keys_list;
} mmi_pen_editor_vk_keys_set_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_pen_editor_hide_candidate_area(void);
extern void mmi_pen_editor_clear_and_show_virtual_keyboard_area(void);
extern void mmi_pen_editor_hide_virtual_keyboard_area(void);
extern void mmi_pen_editor_stroke_down_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_stroke_move_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_stroke_up_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_stroke_up_timer_handler(void);
extern void mmi_pen_editor_confirm_selection(void);
extern int mmi_pen_editor_get_candidates_from_hand_writing(void);
extern void mmi_pen_editor_input_selection_character(UI_character_type c);
extern void mmi_pen_editor_pen_down_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_up_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_long_tap_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_repeat_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_abort_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_move_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_pen_set_stroke_color(color stroke_color);
extern void mmi_pen_editor_setup_input_box
    (mmi_pen_handwriting_area_struct *stroke_area,
     mmi_pen_handwriting_area_struct *ext_stroke,
     U16 input_type, U8 information_bar_flag, mmi_pen_editor_input_box_type_enum input_box_type);
extern void mmi_pen_editor_close_input_box(void);
extern void mmi_pen_editor_show_component(void);
extern void mmi_pen_editor_add_cocontrol
    (mmi_pen_editor_control_set_struct *peneditorcontrolset, mmi_pen_editor_control_type_enum peneditorcontrol);
extern void mmi_pen_editor_reset_control_set(mmi_pen_editor_control_set_struct *peneditorcontrolset);
extern void mmi_pen_editor_input_character(UI_character_type c, MMI_BOOL needselect);
extern void mmi_pen_editor_reset_vk_text(mmi_pen_editor_vk_text_struct *peneditorvktext);
extern void mmi_pen_editor_backspace(void);
extern void mmi_pen_editor_bracket(void);
extern void mmi_pen_editor_new_line(void);
extern void mmi_pen_editor_resize_content_area(int changed_height);
extern void mmi_pen_editor_set_virtual_keyboard_by_input_mode(S32 input_mode);
extern MMI_BOOL mmi_pen_editor_vk_insert_character(mmi_pen_editor_vk_text_struct *vk_text, UI_character_type ch);
extern MMI_BOOL mmi_pen_editor_vk_delete_character(mmi_pen_editor_vk_text_struct *vk_text);
extern MMI_BOOL mmi_pen_editor_get_candidates_by_phrase(UI_character_type ch);
extern MMI_BOOL mmi_pen_editor_get_candidates_by_page(S32 page);
extern void mmi_pen_editor_get_candidates_prev_page(void);
extern void mmi_pen_editor_get_candidates_next_page(void);
extern void mmi_pen_editor_get_candidates_prev(void);
extern void mmi_pen_editor_get_candidates_next(void);
extern void mmi_pen_editor_register_arrow_keys(void);
extern void mmi_pen_editor_set_inline_text_item(const wgui_inline_item *i);
extern void mmi_pen_editor_right_soft_key_handler(void);
extern void mmi_pen_editor_left_soft_key_handler(void);
extern void mmi_pen_editor_switch_input_method(void);
extern void mmi_pen_editor_vk_caps_lock(void);
extern void mmi_pen_editor_vk_insertcharacter(gui_pen_event_param_struct vk_para);
extern void mmi_pen_editor_vk_hide(void);
extern void mmi_pen_editor_vk_show(void);
extern void mmi_pen_editor_vk_symbol_picker(MMI_BOOL is_european_symbol);
extern void mmi_pen_editor_set_inputbox_LSK_Function(FuncPtr f);
extern void mmi_pen_editor_store_LSK_Text(void);
extern gui_virtual_keyboard_language_enum mmi_pen_editor_history_vk_lang_type(void);
extern MMI_BOOL mmi_pen_editor_check_valid_input(UI_character_type input, const UI_character_type *valid_input);
extern void mmi_pen_editor_resort_candidates(
                UI_character_type *candidates,
                int num,
                mmi_pen_editor_resort_type_enum SortRequirement);
extern void mmi_pen_editor_clear_key_handler(void);
extern void mmi_pen_editor_vk_list_menu_resize(void);
extern void mmi_pen_editor_store_list_menu_height(S32 list_menu_height);
extern S32 mmi_pen_editor_get_list_menu_height(void);
extern void mmi_pen_editor_list_menu_highlight_resize(void);
extern void mmi_pen_editor_resize_multiline_input_box_for_vk(void);
extern void mmi_pen_editor_reset_candidate_index(void);
extern void mmi_pen_editor_set_CSK_content(void);
extern void mmi_pen_editor_reset_key_sequence(mmi_pen_editor_key_sequence_struct *peneditorkeysequence);
extern void mmi_pen_editor_exit_screen(void);
extern void mmi_pen_editor_set_handwriting_style(mmi_pen_editor_handwriting_style_enum style);
extern mmi_pen_editor_handwriting_style_enum mmi_pen_editor_get_handwriting_style(void);
/* W06.09 Touch Screen With Keypad V1 */
extern void mmi_pen_editor_bpmf_pinyin_key_down_handler(S32 key);
extern void mmi_pen_editor_bpmf_pinyin_key_up_handler(S32 key);
extern void mmi_pen_editor_bpmf_pinyin_disable_active_multitap(void);
extern void mmi_pen_editor_bpmf_pinyin_multitap_input(UI_character_type c);
extern void mmi_pen_editor_bpmf_pinyin_multitap_input_complete(void);
extern void mmi_pen_editor_bpmf_pinyin_register_multitap_function(void);
extern void mmi_pen_editor_bpmf_pinyin_create_multitap(U8 input_mode);
extern void mmi_pen_editor_hold_confirm(void);
extern void mmi_pen_editor_set_vk_to_show(MMI_BOOL enable);
extern void mmi_pen_editor_disable_input(U32 disable_input_flag);
extern void mmi_pen_editor_show_candidate_area(
                MMI_BOOL arrow_enable,
                mmi_pen_editor_candidate_state_enum candiate_state);
extern void mmi_pen_editor_draw_arrow(
                mmi_pen_editor_arrow_direction_enum arrow_direction,
                mmi_pen_editor_arrow_state_enum arrow_state,
                mmi_pen_editor_arrow_type_enum arrow_type);

extern void mmi_pen_editor_smart_latin_register_key_function(void);
extern void mmi_pen_editor_smart_latin_key_down_handler(S32 key);
extern void mmi_pen_editor_smart_latin_key_up_handler(S32 key);
extern void mmi_pen_editor_smart_latin_highlight_candidate(U32 candidate_length);
extern void mmi_pen_editor_smart_latin_unhighlight_candidate(MMI_BOOL draw);
extern void mmi_pen_editor_chinese_stroke_register_key_function(void);
extern void mmi_pen_editor_chinese_stroke_key_down_handler(S32 key);
extern void mmi_pen_editor_chinese_stroke_key_up_handler(S32 key);
extern void mmi_pen_editor_hide_composition_area(void);
extern void mmi_pen_editor_smart_latin_register_arrow_keys(void);
extern void mmi_pen_editor_smart_latin_confirm_candidate_left(void);
extern void mmi_pen_editor_smart_latin_confirm_candidate_right(void);
extern void mmi_pen_editor_smart_latin_get_candidates_prev(void);
extern void mmi_pen_editor_smart_latin_get_candidates_next(void);
extern S32 mmi_pen_editor_get_remaining_length(void);
extern void mmi_pen_editor_smart_latin_confirm_select(void);
extern void mmi_pen_editor_smart_latin_replace_candidate(UI_character_type *candidate_buffer, S32 candidatelength);
extern void mmi_pen_editor_smart_bpmf_pinyin_register_key_function(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_key_down_handler(S32 key);
extern void mmi_pen_editor_smart_bpmf_pinyin_key_up_handler(S32 key);
extern void mmi_pen_editor_reset_composition_index(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_register_arrow_keys(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_get_syllable_prev(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_get_syllable_next(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable(void);
extern void mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(S32 index);
extern S32 mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position(void);
extern void mmi_pen_editor_cancel_handwriting(void);
extern void mmi_pen_editor_set_vk_keys(
                MMI_BOOL is_allowed,
                const UI_character_type *characters_lsit,
                const gui_virtual_keyboard_pen_enum *disable_enevt_keys_list);
extern void mmi_pen_editor_draw_handwriting_block(void);
extern void mmi_pen_editor_inline_full_screen_redraw_handwriting_area(void);
extern void mmi_pen_editor_reset_LSK_and_RSK_state(void);
extern void mmi_pen_editor_set_whether_vk_hide_to_tray(MMI_BOOL hide_or_not);
extern MMI_BOOL mmi_pen_editor_need_to_hide_to_tray_or_not(void);

extern void mmi_pen_editor_get_vk_type_by_input_mode(S32 input_mode, U8 *vk_type, MMI_BOOL *has_candidate_box);
extern void mmi_pen_editor_get_vk_type_by_input_mode_for_quick_search(S32 input_mode, U8 *vk_type, MMI_BOOL *has_candidate_box);
extern mmi_pen_editor_input_type_enum mmi_pen_editor_get_hand_writing_type_by_input_mode(S32 input_mode);
extern U8 mmi_pen_editor_get_caps_lock_input_mode(S32 input_mode);
extern MMI_BOOL mmi_pen_editor_is_valid_vk_type_for_quick_search(gui_virtual_keyboard_language_enum vk_type);
extern U16 mmi_pen_editor_get_Lang_special_attrib_by_input_mode(U8 input_mode);
extern U16 mmi_pen_editor_get_mode_special_attrib_by_input_mode(U8 input_mode);
extern gui_virtual_keyboard_language_enum mmi_pen_editor_get_vk_type_by_input_type(U16 input_type);
extern gui_virtual_keyboard_language_enum mmi_pen_editor_get_vk_type_by_input_type_for_quick_search(U16 input_type);
extern MMI_BOOL mmi_pen_editor_is_valid_input_type_for_inline_editor(U16 input_type);
extern void mmi_pen_editor_do_not_resize_input_box(void);

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#endif /* _EDITOR_PEN_GPROT_H */ 

