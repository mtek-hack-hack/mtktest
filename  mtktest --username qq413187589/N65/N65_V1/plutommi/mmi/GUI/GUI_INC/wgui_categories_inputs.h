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
 *  wgui_categories_inputs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Input/Editor related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
 *  Elvis Lin (MTK00560)
 *  Terry Yang (MTK00866)
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
#ifndef __WGUI_CATEGORIES_INPUTS_H__
#define __WGUI_CATEGORIES_INPUTS_H__

#include "gui_inputs.h"
#include "wgui.h"
/* MTK Terry 20040628 for t9 spanish lang */
#include "MMI_features.h"
/* MTK end */
#include "wgui_categories_inputsenum.h"
extern void (*wgui_singleline_inputbox_RSK_function) (void);

/* MTK Elvis for QSearch */
extern void (*wgui_singleline_inputbox_LSK_function) (void);

/* store rsk key string of single input box */
extern UI_string_type wgui_singleline_inputbox_LSK_label_string;

/* store rsk key icon of single input box */
extern PU8 wgui_singleline_inputbox_LSK_label_icon;

#define MULTILINE_INPUTBOX_HEIGHT_PAD  4

extern BOOL r2lMMIFlag;
extern MMI_BOOL wgui_is_r2l_display(void);
extern void handle_category28_change_input_mode(void);

/* Set this to 1 for (0 -> + -> 0) sequence on 0 key and (* -> p -> w -> *)
   sequence on * key.
   Set this to 0 for (0 only) on 0 key and (* -> + -> p -> w -> *)
   sequence on * key                                        */
#ifdef __MMI_MULTITAP_KEY_0__
#define ENABLE_DIALER_ZERO_KEY_MULTITAP            1
#else 
#define ENABLE_DIALER_ZERO_KEY_MULTITAP            0
#endif 

#define DISABLE_DIALER_BACK_KEY                 1
#define ENABLE_DIALER_PLUS_CHARACTER_HANDLING      1
#define MULTILINE_INPUTBOX_EDIT_HEIGHT_PAD         8
#define MULTILINE_INPUTBOX_HEIGHT_PAD           4
#define MULTILINE_INPUTBOX_LINE_PAD             1

#define WGUI_DIALER_BOX_ACTIVE_MULTITAP_NONE    0
#define WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY   1
#define WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY   2
#define WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY        4

#define INPUT_TYPE_MASK                0x00ff

#define INPUT_TYPE_USE_ENCODING_BASED_LENGTH    0x0100
#define INPUT_TYPE_USE_ONLY_ENGLISH_MODES       0x0200
#define INPUT_TYPE_ONE_LESS_CHARACTER           0x0400
#define INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER    0x0800
#define INPUT_TYPE_OVERRIDE_DEFAULT             0x1000
#define INPUT_TYPE_PLUS_CHARACTER_HANDLING      0x2000
#define INPUT_TYPE_GSM_EXTENDED_HANDLING        0x4000
#define INPUT_TYPE_SMS_CHAT_MAX_LENGTH_HANDLING 0x8000

/* MTK Terry for 0x81 Encoding in Phone Book */
#define INPUT_TYPE_EXT_USE_0x81_ENCODING        0x0001

/* MTK Steven for SAT SIM Numeric */
#define INPUT_TYPE_EXT_SIM_NUMERIC              0x0002

/* MTK Steven for No-Show New Line Symbol */
#define INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL  0x0004

extern multitap_input wgui_dialer_box_star_key_handler;
extern multitap_input wgui_dialer_box_zero_key_handler;
extern U8 wgui_dialer_box_active_multitap;

/* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
#define SINGLELINE_INPUTBOX                        0
#define MULTILINE_INPUTBOX                      1
#define EMS_INPUTBOX                         2
#define  QSEARCH_INPUTBOX                       3
#endif /* defined(__MMI_MULTITAP_THAI__) */ 
/* W05.36 Fix Vietnamese Tone Input Issu */
typedef enum
{
    EDITOR_MULTILINE_INPUT_BOX,
    EDITOR_EMS_INPUT_BOX,
    EDITOR_INLINE_MULTILINE_INPUT_BOX,
    EDITOR_SINGLE_LINE_INPU_BOX,
    EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX,
    EDITOR_INLINE_TEXT,
    EDITOR_NONE_INPUT_BOX
} mmi_editor_inoutbox_enum;

/*
 * extern UI_character_type   wgui_dialer_box_star_key_string[];
 * extern UI_character_type   wgui_dialer_box_zero_key_string[];
 * extern byte wgui_multiline_inputbox_input_mode_changed;
 * extern byte wgui_multiline_inputbox_input_type;
 * extern byte wgui_multiline_inputbox_decimal_input_mode_flag;
 * extern S32 (*wgui_inputbox_UCS2_count_function)(void);
 * extern S32 (*wgui_inputbox_GSM_ext_count_function)(void);
 * extern byte       wgui_multiline_inputbox_decimal_flag;
 * extern S32  wgui_inputbox_buffer_size;
 * extern multitap_input      wgui_inputbox_multitap_zero_key;
 * extern UI_character_type   wgui_inputbox_phone_number_zero_key_string;
 */
/* CODE ADDED VANDANA MEHTANI FOR SINGLE LINE HISTORY BUFFER */
typedef struct _singleline_inputbox_category_history
{
    U16 history_ID;
    S16 text_length;
    S16 allocated_length;
    S16 available_length;
    S16 current_position;
    S16 text_offset_x;
    S16 input_type;
    S16 UCS2_count;
    U32 flags;
#if defined(__MMI_TOUCH_SCREEN__)
    S16 vk_lang_type;
#endif 
} singleline_inputbox_category_history;

typedef struct _mutliline_inputbox_category_history
{
    U16 history_ID;
    S16 text_length;
    S16 allocated_length;
    S16 available_length;
    S16 n_lines;
    S16 text_height;
    S16 text_offset_x;
    S16 text_offset_y;
    S16 cursor_x;
    S16 cursor_y;
    S16 cursor_line_position_counter;
    S16 line_before_cursor_line_p;
    S16 cursor_line_p;
    S16 cursor_p;
    S16 line_after_cursor_line_p;
    S16 line_after_cursor_line_last_p;
    S16 last_position_p;
    S16 input_type;
    U32 flags;  /* 032505 Calvin switched */
    S16 UCS2_count;
    S32 hilite_idx;
#if defined(__MMI_TOUCH_SCREEN__)
    S16 vk_lang_type;
#endif 
    S8 state;   /* MTK 2004-02-13 Wilson, To keep current screen state in history buffer. */
    //barcode
	S32	current_hilite_idx;
   S32	curr_hilite_text_offset_y;
	HILITE_STR 		*hilite_list;
	U16	hilite_str_number;
	void 	(*hilite_cb)(S32 idx);
	U32     ext_flags;    
    MMI_BOOL multitap_state;
   /*** ritesh started****/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    U32 start_page_id;
    U32 end_page_id;
    S32 text_offset;
    //U32 ext_flags;
    U8 previous_shared_bytes;
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
   /*** ritesh ended****/
} multiline_inputbox_category_history;

extern void wgui_hide_input_information_bar(void);
extern void wgui_dialer_inputbox_set_border(MMI_BOOL is_border_existing, color border_color);
extern void wgui_setup_inputbox_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U16 input_type,
                U8 *history_buffer,
                U8 information_bar_flag,
                U32 additional_flags,
                S16 min_text_height,
                S16 min_line_height,
                S16 header_height,
                S16 footer_height,
                multi_line_input_box_icon_hdlr icon_callback);
extern void wgui_setup_inputbox(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U16 input_type,
                U8 *history_buffer,
                U8 information_bar_flag);
extern S32 wgui_multiline_inputbox_get_UCS2_count(void);
extern void wgui_set_default_input_type(U16 *input_type);
extern void wgui_set_qsearch_default_input_type(U16 *input_type);
extern S32 wgui_inputbox_information_bar_x;
extern S32 wgui_inputbox_information_bar_y;
extern S32 wgui_inputbox_information_bar_width;
extern S32 wgui_inputbox_information_bar_height;
extern U8 wgui_inputbox_information_flag;

/* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_CATEGORY_EDITOR
extern U8 wgui_small_editor_information_flag;
#endif 
/* END VIJAY PMT 20050930 */
extern PU8 wgui_inputbox_information_icon;
extern void wgui_show_inputbox(void);
extern void category5_hide_multitap(void);
extern void set_MMI_current_input_type(void);
extern void wgui_close_inputbox(void);

/* Common inputbox input method functions */
extern void (*wgui_change_inputbox_type)(U8 input_type);
extern void (*wgui_inputbox_insert_symbol) (UI_character_type c);
extern void (*wgui_inputbox_not_empty_callback) (void);
extern void (*wgui_inputbox_empty_callback) (void);
extern void (*wgui_inputbox_validation_callback) (U8 *text, U8 *cursor, S32 text_length);

void RegisterInputBoxValidationFunction(void (*f) (U8 *, U8 *, S32));
void RegisterInputBoxNotEmptyFunction(void (*f) (void));
void RegisterInputBoxEmptyFunction(void (*f) (void));
extern S32 GetInputBoxUCS2Count(void);
extern S32 GetInputBoxExtendedGSMCount(void);

/* Function Decleration Added - Gurinder - 23/4/2006 */
extern void wgui_setup_input_information(S32 x, S32 y, S32 width, S32 height);

extern void category5_hide_multitap(void);
extern void RedrawCategory5Screen(void);
extern void ShowCategory5Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
/* Begin AP Symbol table */
extern void ShowCategory5Screen_ext(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer,
                S16 input_ext_type,
                S16 *required_input_mode_set,
                U8 *no_show_symbol_list[]);
/* End AP Symbol table */
extern void ExitCategory5Screen(void);
extern S32 GetCategory5HistorySize(void);
extern U8 *GetCategory5History(U8 *history_buffer);
void SetCategory5RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void AppendCategory5String(S16 input_type, U8 *buffer, S32 buffer_size, U8 *s, U8 *history_buffer);

/* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_CATEGORY_EDITOR
extern void category100_hide_multitap(void);
extern void ShowCategory100Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
extern void ExitCategory100Screen(void);
#endif /* UI_SMALL_CATEGORY_EDITOR */ 
/* END VIJAY PMT 20050930 */
extern void RedrawCategory35Screen(void);
extern void ShowCategory35Screen(
                U8 *left_softkey,
                PU8 left_softkey_icon,
                U8 *right_softkey,
                PU8 right_softkey_icon,
                U8 *message,
                PU8 message_icon,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
extern void ExitCategory35Screen(void);
extern S32 GetCategory35HistorySize(void);
extern U8 *GetCategory35History(U8 *history_buffer);
void SetCategory35RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

extern void ShowCategory171Screen(
                U8 *left_softkey,
                PU8 left_softkey_icon,
                U8 *right_softkey,
                PU8 right_softkey_icon,
                U8 *message,
                PU8 message_icon,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
extern void ExitCategory171Screen(void);
extern U8 *GetCategory171History(U8 *history_buffer);
extern S32 GetCategory171HistorySize(void);
extern void RedrawCategory171Screen(void);
void SetCategory171RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

extern void SetInputboxLSKFunction(FuncPtr f);
extern void SetInputboxLSKText(void);

extern void wgui_handle_dialer_inputbox_right_softkey_down(void);
extern void wgui_handle_dialer_inputbox_right_softkey_up(void);
extern void wgui_handle_dialer_inputbox_right_softkey_long_press(void);

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
#define CAT115_MAXSIZE  128

extern void ShowCategory115Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *buffer,
                S32 buffer_size,
                U8 *input_format,
                U8 input_required,
                U8 *history_buffer);
extern void ShowCategory115Screen_ext(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *buffer,
                S32 buffer_size,
                U8 *input_format,
                U8 input_required,
                U16 input_type,
                U8 *history_buffer);
extern U8 *GetCategory115History(U8 *history_buffer);
void SetCategory115RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
extern S32 mmi_nsm2_get_remaining_len(void);
#endif 

extern void wgui_input_information_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_show_input_mode(U8 input_mode, PU8 inputbox_information_icon);
extern void wgui_setup_input_information(S32 x, S32 y, S32 width, S32 height);

extern void wgui_handle_inputbox_change_input_mode(void);
extern U8 MMI_allow_only_english_input_modes;
extern void change_input_mode(void);
extern void change_multiline_information_bar_input_method(void);
extern void change_multiline_inputbox_input_mode(void);

/* Begin AP input mode set */
extern void wgui_fill_AP_required_input_mode_set(S16 *required_input_mode_set);
extern void wgui_set_AP_required_input_mode_set_flag(void);
extern void wgui_unset_AP_required_input_mode_set_flag(void);

/* End AP input mode set */

extern void (*inputbox_change_mode) (void);
extern U8 MMI_current_input_mode;

extern void wgui_multiline_setup_inputbox(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U16 input_type,
                U8 *history_buffer,
                U8 information_bar_flag);
extern void wgui_multiline_inputbox_append_string(
                    S16 input_type, 
                    U8 *buffer, 
                    S32 buffer_size, 
                    U8 *s, 
                    U8 *history_buffer,
                    U16 category_id,
                    MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 C));
extern void wgui_multiline_inputbox_show_current_input_method(S32 x1,S32 y1,S32 x2,S32 y2);
extern U8 set_multiline_inputbox_category_history(U16 history_ID, U8 *history_buffer, S16 *input_type);
extern void get_multiline_inputbox_category_history(U16 history_ID, U8 *history_buffer, S16 input_type);
extern void set_multiline_inputbox_category_history_state(U16 history_ID, U8 *history_buffer, S8 state);       /* MTK 2004-02-12 Wilson */
extern S8 get_multiline_inputbox_category_history_state(U16 history_ID, U8 *history_buffer);   /* MTK 2004-02-12 Wilson */

/* for E-dictionary */
void wgui_set_e_dictionary_test_clear_inputbox_buffer_funcptr(pBOOL(*FuncPtr) (void));
extern void wgui_reset_e_dictionary_test_clear_inputbox_buffer_funcptr(void);
extern pBOOL(*wgui_e_dictionary_test_clear_inputbox_buffer) (void);
void Register_cat5_editor_buffer_need_flush(BOOL(*FuncPtr) (void));
void Register_pound_key_buffer_flush_test_function(BOOL(*FuncPtr) (void));

/* For Draw Manager  */
extern void get_singleline_inputbox_category_history(U16 history_ID, U8 *history_buffer, S16 input_type);

/* for Chat */
#define CHAT_MESSAGE_BUFFER      (3024+(100<<2))        /* Added  100<<2 for Icon Text(Arrow+Buddy) */
typedef struct _chat_message
{
    U8 *chat_message_string;
    U8 flag;
} chat_message_struct;


extern void ShowCategory305Screen(
                U16 title_id,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                chat_message_struct *chat,
                U8 *history_buffer,
                U8 *top_msg,
                U16 top_msg_icon);

extern void ExitCategory305Screen(void);
extern U8 *GetCategory305History(U8 *history_buffer);
extern S32 GetCategory305HistorySize(void);
extern void RedrawCategory305Screen(void);
extern void ShowCatMessage(U8 *message, U8 type_of_msg);

extern void handle_category28_right_softkey_down(void);
extern void handle_category28_right_softkey_long_press(void);
extern void handle_category28_right_softkey_up(void);
extern MMI_BOOL wgui_is_smart_input_mode(U16 input, MMI_BOOL is_type);
extern MMI_BOOL wgui_is_Chinese_input_mode(U16 input_mode);

extern MMI_BOOL cat_215_text_change_event_callback(gui_multi_line_input_box_change_event_enum event, U16 C);
extern void cat_215_text_total_characters_in_byte_callback(S32 x1, S32 y1, S32 x2, S32 y2);
extern void cat_215_fit_text_for_ut8_length_in_multiline_inputbox(U8 *buffer);
extern void cat_215_draw_infobar_callback(S32 x1, S32 y1, S32 x2, S32 y2);
extern void ShowCategory215Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S16 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer);

extern void wgui_inputbox_change_input_type(U8 input_type);
extern MMI_BOOL wgui_inputbox_input_mode_changed;
extern U8 wgui_inputbox_input_type;

#endif /* __WGUI_CATEGORIES_INPUTS_H__ */ 

