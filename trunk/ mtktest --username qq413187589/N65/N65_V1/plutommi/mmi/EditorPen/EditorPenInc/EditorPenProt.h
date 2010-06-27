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
 * EditorPenProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is internal prototype header of EditorPen
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!! 
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
 * rebase maintrunk.MAUI_MBJ on 2007-3-17 23:21:53.
 * 
 *
 * removed!
 * removed!

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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _EDITOR_PEN_PROT_H
#define _EDITOR_PEN_PROT_H

#include "MMI_features.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "wgui_categories_util.h"
#include "gui_fixed_menus.h"
#include "DebugInitDef.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"
#include "GlobalDefs.h"
#include "wgui_softkeys.h"
#include "PhoneSetupGprots.h"
#include "ScrMemMgrGprot.h"
#include "gui_virtual_keyboard.h"
#include "IMERes.h"



/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_MAINLCD_240X320__
    #define PEN_EDITOR_BLOCK_HEIGHT 108
#else
    #define PEN_EDITOR_BLOCK_HEIGHT 80    
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern S32 Get_CharHeightOfAllLang(U8 size);
extern UI_EMS_input_box MMI_EMS_inputbox;
extern multi_line_input_box MMI_multiline_inputbox;
extern UI_theme *current_UI_theme;
extern MMI_theme *current_MMI_theme;
extern UI_multitap_input_theme *current_multitap_input_theme;
extern IP4_input *current_IP4_input;
extern date_input *current_date_input;
extern single_line_input_box MMI_inline_singleline_inputbox;
extern time_period_input *current_time_period_input;
extern time_input *current_time_input;
extern S32 UI_device_width;
extern S32 wgui_EMS_inputbox_information_bar_x;
extern S32 wgui_EMS_inputbox_information_bar_y;
extern S32 wgui_EMS_inputbox_information_bar_width;
extern S32 wgui_EMS_inputbox_information_bar_height;
extern S16 MMI_current_input_type;
extern fixed_list_menu MMI_fixed_list_menu;
extern S32(*cat200_search_function) (U8 *);
extern S32 wgui_inline_item_highlighted_index;
extern S32 UI_cursor_x1;
extern S32 UI_cursor_y1;
/* W06.50 for area limited input method block on editor's information bar */
extern S32 wgui_information_bar_input_mode_display_width;
extern S32 wgui_information_bar_input_mode_display_height;
extern S32 wgui_information_bar_input_mode_height;
extern void handle_category28_change_input_mode(void);
extern void (*EMS_inputbox_input_callback) (void);
extern void (*multiline_inputbox_input_callback) (void);
extern void (*singleline_inputbox_input_callback) (void);
extern void (*inline_singleline_inputbox_input_callback) (void);
extern U8 wgui_inline_singleline_inputbox_decimal_input_mode_flag;
extern U8 wgui_multiline_inputbox_decimal_input_mode_flag;
extern U8 wgui_singleline_inputbox_decimal_input_mode_flag;
extern U8 wgui_inline_item_handled;
extern void (*complete_inline_item_edit) (void);
extern U8 wgui_inputbox_RSK_label_clear;
extern U8 category28_RSK_label_clear;
extern U8 wgui_singleline_inputbox_RSK_label_clear;
extern icontext_button MMI_softkeys[];
extern void (*wgui_inline_edit_DONE_function) (void);
extern S16 MMI_current_input_ext_type;
extern U8 numeric_leading_zero;
extern void register_inline_text_edit_handle_right_softkey_up(void);
extern UI_string_type inline_text_edit_RSK_label_string;
extern PU8 inline_text_edit_RSK_label_icon;
extern U8 wgui_inline_list_menu_changed;
extern U8 wgui_inline_list_menu_disable_done;
extern void handle_inline_text_edit_right_softkey_long_press(void);
extern void wgui_inline_text_edit_set_RSK_BACK_function(void);
extern UI_string_type wgui_inline_edit_get_RSK_string(void);
extern void handle_inline_text_edit_right_softkey_down(void);
extern void (*redraw_current_inline_item) (void);
extern void register_EMS_inputbox_keys(void);
extern void wgui_set_EMS_inputbox_RSK(void);
extern void wgui_set_RSK(void);
extern void inline_edit_singleline_inputbox_multitap_input_complete(void);
extern void EMS_inputbox_multitap_input_complete(void);
extern void set_leading_zero(U8 u8type);
extern void gui_multi_line_input_box_set_pen_scroll_delay(multi_line_input_box *b, S32 delay_time);
extern void gui_EMS_input_box_set_pen_scroll_delay(UI_EMS_input_box *b, S32 delay_time);
extern void EMS_inputbox_multitap_input(UI_character_type c);
extern void redraw_EMS_inputbox(void);
extern void show_inline_singleline_inputbox(void);
extern void date_input_move_to_x_y(date_input *d, S32 x, S32 y);
extern void IP4_input_move_to_x_y(IP4_input *ip4, S32 x, S32 y);
extern void time_input_move_to_x_y(time_input *t, S32 x, S32 y);
extern void time_period_input_move_to_x_y(time_period_input *tp, S32 x, S32 y);
extern void wgui_multiline_inputbox_decimal_numeric_handle_pound_key_down(void);
extern void EMS_inputbox_direct_input(UI_character_type c);
extern void refresh_search_list(U8 *name);
extern void wgui_singleline_inputbox_decimal_numeric_handle_pound_key_down(void);
extern void inline_edit_singleline_inputbox_multitap_input(UI_character_type c);
extern void wgui_inline_singleline_inputbox_decimal_numeric_handle_pound_key_down(void);
extern void inline_edit_singleline_inputbox_direct_input(UI_character_type c);
extern void date_input_direct_input_nodraw(UI_character_type c);
extern S32 date_input_test_last_position(date_input *d);
extern void IP4_input_direct_input_nodraw(UI_character_type c);
extern S32 IP4_input_test_last_position(IP4_input *ip4);
extern void time_input_direct_input_nodraw(UI_character_type c);
extern S32 time_input_test_last_position(time_input *t);
extern void time_period_input_direct_input_nodraw(UI_character_type c);
extern S32 time_period_input_test_last_position(time_period_input *tp);
extern void wgui_handle_inputbox_right_softkey_down(void);
extern void EMS_inputbox_backspace(void);
extern void wgui_handle_singleline_inputbox_right_softkey_down(void);
extern void inline_edit_singleline_inputbox_delete_character(void);
extern int gui_multi_line_input_box_get_remaining_length(multi_line_input_box *b);
extern void EMS_inputbox_previous(void);
extern int gui_single_line_input_box_get_remaining_length(single_line_input_box *b);
extern void inline_edit_singleline_inputbox_previous_character(void);
extern void redraw_inline_singleline_inputbox(void);
extern void EMS_inputbox_insert_new_line(void);
extern S32 mmi_ime_get_candidates_by_composition(UI_character_type *composition, UI_character_type *candidatebuffer);
extern S32 mmi_ime_get_candidates_by_phrase(UI_character_type phrase, UI_character_type *candidatebuffer);
extern S32 mmi_ime_get_candidates_by_page(S32 page, UI_character_type *candidatebuffer);
extern S32 mmi_ime_smart_latin_get_candidates_by_key_sequence(
            mmi_keypads_enum *key_sequence,
            S32 key_sequence_length,
            UI_character_type *candidatebuffer);
extern S32 mmi_ime_smart_latin_get_candidates_by_index(S32 *index, UI_character_type *candidatebuffer);
extern S32 mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence(
            mmi_keypads_enum *key_sequence,
            S32 key_sequence_length,
            UI_character_type *syllable_buffer,
            S32 start_index,
            S32 end_index);
extern S32 mmi_ime_chinese_stroke_get_candidates_by_key_sequence(
            mmi_keypads_enum *key_sequence,
            S32 key_sequence_length,
            UI_character_type *candidatebuffer,
            UI_character_type *strokebuffer);
extern void wgui_set_singleline_RSK(void);
extern void handle_category28_input(void);
extern void wgui_handle_inputbox_input(void);
extern void wgui_handle_qsearch_singleline_inputbox_change_input_mode(void);
extern void cat200_virtual_keypad_callback(void);
extern void RedrawCategoryControlledArea200Screen(dm_coordinates *coordinate);
extern void wgui_redraw_input_information_bar(void);
extern void change_EMS_inputbox_mode(U8 mode);
extern void wgui_EMS_redraw_input_information_bar(void);
extern void wgui_inline_edit_default_list_highlight_handler(S32 item_index);
extern void wgui_handle_singleline_inputbox_change_input_mode(void);
extern void wgui_handle_inline_singleline_inputbox_change_input_mode(void);
extern MMI_BOOL get_multitap_state(void);
extern void inline_edit_change_singleline_inputbox_mode(U8 mode);
extern U8 *wgui_inline_edit_get_current_item_history(U8 *history_buffer);
extern U8 gui_EMS_input_box_get_previous_character(UI_EMS_input_box *b, UI_character_type *c);

/* W06.09 Touch Screen With Keypad V1 */
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
extern UI_character_type *get_bpmf_multitap_string(S32 i);
extern const UI_character_type numberless_lowercase_multitap_strings[MAX_MULTITAPS][32];
extern void handle_inline_text_edit_right_softkey_up(void);
extern void cat201_register_key_func(void);
extern void RedrawCategoryControlledArea201Screen(void);
extern S32 handwriting_stroke_layer_mem;
extern S32 gui_EMS_input_box_highlight_cursor_number(UI_EMS_input_box *b, S32 numOfChar);
extern void gui_single_line_input_box_locate_cursor(single_line_input_box *b);
extern void draw_resizeable_arrow(S32 x, S32 y, U8 arrow_type, color c, S32 width, S32 height);
extern S32 UI_get_font_height(UI_font_type f);
extern void wgui_EMS_set_text_format(EMSTextFormat text_format);
#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
extern void wgui_handle_inputbox_change_input_mode_bymultitapthai(void);
extern void wgui_handle_qsearch_change_input_mode_bymultitapthai(void);
#endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */ 

//editor pen share functions
extern void mmi_pen_editor_set_left_soft_key_select(void);
extern void mmi_pen_editor_set_left_soft_key(void);
extern void mmi_pen_editor_set_right_softkey(mmi_pen_editor_rsk_type_enum rsk_type);
extern void mmi_pen_editor_multi_block_stroke_down_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_multi_block_stroke_move_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_multi_block_stroke_up_handler(mmi_pen_point_struct pos);
extern void mmi_pen_editor_change_handwriting_area(void);
extern MMI_BOOL mmi_pen_editor_del_key_sequence(mmi_pen_editor_key_sequence_struct *key_sequence);
extern void mmi_pen_editor_enable_multi_block_handwriting(void);
extern void mmi_pen_editor_disable_multi_block_handwriting(void);
extern S32 mmi_pen_editor_handwriting_check_block(mmi_pen_point_struct pos);
extern MMI_BOOL mmi_pen_editor_reset_candidate_and_composition_box(single_line_input_box * candidate_box, UI_character_type * candidate_buffer, S32 num, MMI_BOOL is_highlight_first);
extern void mmi_pen_editor_set_smart_latin_pre_candidate_length(U32 candidatelength);
extern U32 mmi_pen_editor_get_smart_latin_pre_candidate_length(void);
extern void mmi_pen_editor_set_smart_latin_candidate_index(S32 candidateindex);
extern S32 mmi_pen_editor_get_smart_latin_candidate_index(void);
extern mmi_pen_editor_key_sequence_struct * mmi_pen_editor_get_key_sequence(void);
extern MMI_BOOL mmi_pen_editor_is_candidate_in_selection(void);
extern void  mmi_pen_editor_set_candidate_selection_status(MMI_BOOL is_in_selection);
extern void mmi_pen_editor_set_compositon_index(U32 composion_index);
extern U32 mmi_pen_editor_get_compositon_index(void);
extern mmi_pen_editor_candidate_state_struct * mmi_pen_editor_get_composition_state(void);
extern void mmi_pen_editor_set_candaidate_state(mmi_pen_editor_candidate_state_struct * candidate_state_struct, mmi_pen_editor_candidate_state_enum candidate_state);
extern single_line_input_box * mmi_pen_editor_get_composition_box(void);
extern S32 mmi_pen_editor_get_composition_box_height(void);
extern S32 mmi_pen_editor_get_composition_box_x(void);
extern S32 mmi_pen_editor_get_composition_box_y(void);
extern UI_buffer_type mmi_pen_editor_get_composition_box_current_text(void);
extern UI_buffer_type mmi_pen_editor_get_composition_box_text(void);
extern single_line_input_box * mmi_pen_editor_get_candidate_box(void);
extern S32 mmi_pen_editor_get_candidate_box_height(void);
extern S32 mmi_pen_editor_get_candidate_box_x(void);
extern S32 mmi_pen_editor_get_candidate_box_y(void);
extern UI_font_type mmi_pen_editor_get_candidate_box_text_font(void);
extern S32 mmi_pen_editor_get_candidate_box_text_length(void);
extern void mmi_pen_editor_set_active_multitap_index(S32 index);
extern void mmi_pen_editor_set_candidate_page(S32 page);
extern void mmi_pen_editor_set_candidate_index(S32 index);
extern MMI_BOOL  mmi_pen_editor_get_candidate_arrow_state(void);
extern void mmi_pen_editor_set_resized_by_vk_or_not(MMI_BOOL is_resized_by_vk);
extern void mmi_pen_editor_set_show_vk_at_start_or_not(MMI_BOOL show_at_start);
extern mmi_pen_editor_vk_text_struct * mmi_pen_editor_get_vk_text(void);
extern S8  mmi_pen_editor_get_vk_text_string_length(void);
extern UI_character_type * mmi_pen_editor_get_vk_text_string(void);
extern MMI_BOOL mmi_pen_editor_is_there_vk_candidate_box(void);
extern void mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_BOOL has_candidate_box_or_not);
extern void mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_BOOL redraw_or_not);
extern void mmi_pen_editor_set_multi_block_stroke_area(S16 index, S32 x1, S32 y1, S32 x2, S32 y2);
extern mmi_pen_handwriting_area_struct * mmi_pen_editor_get_multi_block_stroke_area(void);
extern MMI_BOOL mmi_pen_editor_is_handwriting_enabled(void);
extern void mmi_pen_editor_set_handwriting_enabled_or_not(MMI_BOOL enabled_or_not);
extern void mmi_pen_editor_set_vk_disabled_or_not(MMI_BOOL disabled_or_not);
extern void mmi_pen_editor_set_history_vk_type(gui_virtual_keyboard_language_enum vk_type);
extern void mmi_pen_editor_get_point_by_index(S16 index, mmi_pen_point_struct * point);
extern mmi_pen_point_struct * mmi_pen_editor_get_stroke_buffer(void);
extern mmi_pen_handwriting_area_struct * mmi_pen_editor_get_original_handwriting_area(void);
extern void mmi_pen_editor_reset_vk_key_set(void);
extern void mmi_pen_editor_set_vk_state(mmi_pen_editor_virtual_keyboard_state_enum vk_state);
extern mmi_pen_editor_virtual_keyboard_state_enum mmi_pen_editor_get_vk_state(void);
extern mmi_pen_editor_input_box_type_enum mmi_pen_editor_get_input_box_type(void);
extern MMI_BOOL mmi_pen_editor_get_handwriting_state(void);
extern void mmi_pen_editor_set_handwriting_disabled_or_not(MMI_BOOL diabled_or_not);
extern MMI_BOOL mmi_pen_editor_is_stroke_up_timer_on(void);
extern MMI_BOOL mmi_pen_editor_candidate_is_able_to_prev_page(void);
extern MMI_BOOL mmi_pen_editor_candidate_is_able_to_next_page(void);
extern MMI_BOOL mmi_pen_editor_composition_is_able_to_next(void);
extern MMI_BOOL mmi_pen_editor_composition_is_able_to_prev(void);
extern S32 mmi_pen_editor_compute_candidate_input_box_height(void);
extern void mmi_pen_editor_show_composition_area(MMI_BOOL arrow_enable, mmi_pen_editor_candidate_state_enum candiate_state);
extern void mmi_pen_editor_change_inputbox_mode(U8 input_mode);
extern void mmi_pen_editor_set_syllable_confirmed_or_not(MMI_BOOL confirmed);
extern MMI_BOOL mmi_pen_editor_get_candidates_by_vk(MMI_BOOL refresh_candidate);
extern S32 mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence(
            mmi_pen_editor_key_sequence_struct *key_sequence, MMI_BOOL refresh_candidate);
extern S32 mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(
            mmi_pen_editor_key_sequence_struct *key_sequence,
            MMI_BOOL is_reset, MMI_BOOL refresh_candidate);
extern void mmi_pen_editor_setup_input_by_keypad(U16 input_type_only);
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
extern void mmi_pen_editor_show_word_prediction(void);
#endif
extern void mmi_pen_editor_set_vk_resize(MMI_BOOL v);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_pen_editor_hand_writing_initialize(void);
extern void mmi_pen_editor_hand_writing_deinitialize(void);
extern S32 mmi_pen_editor_hand_writing_get_candidates(
            U16 *stroke_buffer,
            UI_character_type *candidate_array,
            mmi_pen_editor_input_type_enum h_w_type,
            S32 number);
#ifdef __MMI_PENPOWER_PHRASE__            
extern S32 mmi_pen_editor_get_candidates_by_phrase_from_penpower(UI_character_type phrase, UI_character_type *candidatebuffer);
extern S32 mmi_pen_editor_get_candidates_by_page_from_penpower(S32 page, UI_character_type *candidatebuffer);
#endif /*  __MMI_PENPOWER_PHRASE__ */


#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#endif /* _EDITOR_PEN_PROT_H */ 

