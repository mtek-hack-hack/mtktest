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
 *   ThemeConverterData.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Data file for the ThemeConverter of DLT project
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#ifndef __THEME_CONVERTER_XML_C__
#error This file can only be included in ThemeConverterXml.c
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#define BASE_PTR(x)		(&(buffer_DLT.x))

typedef struct {
	UI_filled_area	multitap_filler;
	UI_filled_area	inputbox_filler;

	UI_filled_area	scrollbar_background_filler;
	UI_filled_area	scrollbar_indicator_filler;

	UI_filled_area	title_filler;

	UI_filled_area	list_background_filler;
	UI_filled_area	list_normal_item_filler;
	UI_filled_area	list_selected_item_filler;
	UI_filled_area	list_disabled_item_filler;

	UI_filled_area	matrix_background_filler;
	UI_filled_area	matrix_normal_item_filler;
	UI_filled_area	matrix_selected_item_filler;
	UI_filled_area	matrix_disabled_item_filler;

	UI_filled_area	formatted_inputbox_normal_filler;
	UI_filled_area	formatted_inputbox_selected_filler;

	UI_filled_area	main_menu_background_filler;

	UI_filled_area	list_main_menu_normal_item_filler;
	UI_filled_area	list_main_menu_selected_item_filler;
	UI_filled_area	list_main_menu_disabled_item_filler;

	UI_filled_area	matrix_main_menu_normal_item_filler;
	UI_filled_area	matrix_main_menu_selected_item_filler;
	UI_filled_area	matrix_main_menu_disabled_item_filler;

	UI_filled_area	general_background_filler;

	UI_filled_area	popup_description_background_filler;

	UI_filled_area	inline_list_background_filler;
	UI_filled_area	inline_list_normal_item_filler;
	UI_filled_area	inline_list_selected_item_filler;
	UI_filled_area	inline_list_disabled_item_filler;

	UI_filled_area	inline_edit_focussed_filler;
	UI_filled_area	inline_edit_unfocussed_filler;
	UI_filled_area	inline_edit_noboundary_filler;

	UI_filled_area	PIN_inputbox_background_filler;
	UI_filled_area	PIN_screen_background_filler;
	UI_filled_area	network_screen_background_filler;
	UI_filled_area	aphorism_screen_background_filler;
	UI_filled_area	CM_screen_background_filler;
	UI_filled_area	progress_screen_background_filler;
	UI_filled_area	dialer_inputbox_background_filler;

	UI_filled_area	virtual_keyboard_key_down_filler;

	UI_filled_area	alarm_background_filler;

	UI_filled_area	small_list_menu_normal_filler;
	UI_filled_area	small_list_screen_border_filler;
	color	UI_black_color;
	color	UI_white_color;

	color	lite_disp_scr_bg_color;

	color	LSK_up_text_color;
	color	LSK_down_text_color;
	color	LSK_disabled_text_color;
	color	RSK_up_text_color;
	color	RSK_down_text_color;
	color	RSK_disabled_text_color;

	color	multitap_selector_color;
	color	multitap_normal_text_color;
	color	multitap_selected_text_color;

	color	inputbox_normal_text_color;
	color	inputbox_selected_text_color;
	color	inputbox_selector_color;
	color	inputbox_cursor_color;

	color	title_text_color;
	color	title_text_border_color;
	color	title_shortcut_text_color;

	color	list_normal_text_color;
	color	list_selected_text_color;
	color	list_disabled_text_color;

	color	matrix_normal_text_color;
	color	matrix_selected_text_color;
	color	matrix_disabled_text_color;

	color	menubar_index_background_color;
	color	menubar_item_background_color;
	color	menubar_index_text_color;
	color	menubar_item_text_color;

	color	drop_down_normal_text_color;
	color	drop_down_disabled_text_color;
	color	drop_down_focussed_text_color;

	color	formatted_inputbox_selector_color;
	color	formatted_inputbox_normal_text_color;
	color	formatted_inputbox_disabled_text_color;
	color	formatted_inputbox_selected_text_color;
	color	formatted_inputbox_cursor_color;

	color	list_main_menu_normal_text_color;
	color	list_main_menu_selected_text_color;
	color	list_main_menu_disabled_text_color;

	color	matrix_main_menu_normal_text_color;
	color	matrix_main_menu_selected_text_color;
	color	matrix_main_menu_disabled_text_color;

	color	circular_main_menu_normal_text_color;
	color	circular_main_menu_selected_text_color;
	color	circular_main_menu_disabled_text_color;

	color	popup_screen_background_color;
	color	popup_screen_border_color;

	color	popup_description_text_color;

	color	CM_screen_text_color;

	color	datetime_bar_background_color;
	color	datetime_bar_duration_background_color;
	color	datetime_bar_date_text_color;
	color	datetime_bar_time_text_color;
	color	datetime_bar_duration_text_color;
	color	datetime_bar_AOC_text_color;

	color	information_bar_color;
	color	input_method_text_color;
	color	remaining_length_text_color;

	color	inline_edit_focussed_text_color;
	color	inline_edit_unfocussed_text_color;
	color	inline_edit_selected_text_color;
	color	inline_edit_selector_color;
	color	inline_edit_cursor_color;

	color	inline_list_normal_text_color;
	color	inline_list_selected_text_color;
	color	inline_list_disabled_text_color;

	color	PIN_inputbox_normal_text_color;
	color	PIN_inputbox_selected_text_color;
	color	PIN_inputbox_selector_color;
	color	PIN_inputbox_cursor_color;

	color	dialer_inputbox_normal_text_color;
	color	dialer_inputbox_selected_text_color;
	color	dialer_inputbox_selector_color;
	color	dialer_inputbox_cursor_color;

	color	virtual_keyboard_key_down_text_color;
	color	virtual_keyboard_key_up_text_color;
	color	virtual_keyboard_dead_key_down_text_color;
	color	virtual_keyboard_dead_key_up_text_color;
	color	virtual_keyboard_disp_area_text_color;

	color	calculator_color;
	color	alarm_text_color;

	color	idle_scr_date_color;
	color	idle_scr_time_color;
	color	idle_scr_date_border_color;
	color	idle_scr_time_border_color;
	color	idle_scr_network_name_color;
	color	idle_scr_network_name_border_color;
	color	idle_scr_network_status_color;
	color	idle_scr_network_status_border_color;
	color	idle_scr_network_extra_color;
	color	idle_scr_network_extra_border_color;

	stFontAttribute	button_font;
	stFontAttribute	multitap_font;
	stFontAttribute	inputbox_font;
	stFontAttribute	window_title_font;
	stFontAttribute	list_menu_font;
	stFontAttribute	matrix_menu_font;
	stFontAttribute	menu_bar_index_font;
	stFontAttribute	menu_bar_item_font;
	stFontAttribute	shortcut_indicator_font;
	stFontAttribute	title_text_font;
	stFontAttribute	drop_down_control_font;
	stFontAttribute	list_main_menu_font;
	stFontAttribute	matrix_main_menu_font;
	stFontAttribute	virtual_keyboard_font;

    /* highlight fillers */
    /*
     * Highlight dimension for menu items
     *
     * HIGHLIGHT WIDTH = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP
     * HIGHLIGT HEIGHT: 
     *      Single-line     = MMI_MENUITEM_HEIGHT
     *      Two-line        = MMI_MENUITEM_HEIGHT * 2
     *      Multi-row       = MMI_MULTIROW_MENUITEM_HEIGHT
     *      Thick           = MMI_THICK_MENUITEM_HEIGHT = CAT425_MENUITEM_HEIGHT
     *      Thick with tab  = CAT425_MENUITEM_HEIGHT_NO_TAB
     *
     * If the menu item dimension does not fit perfectly, the highlight filler will be list_selected_item_filler.
     */
	UI_filled_area	menuitem_single_line_highlight_filler;
	UI_filled_area	menuitem_two_line_highlight_filler;
	UI_filled_area	menuitem_multirow_highlight_filler;
	UI_filled_area	menuitem_thick_highlight_filler;
	UI_filled_area	menuitem_thick_with_tab_highlight_filler;
    
	UI_filled_area	symbol_picker_highlight_filler;
	UI_filled_area	matrix_highlight_filler;

    /* full-screen background */
	UI_filled_area	main_menu_bkg_filler;
	UI_filled_area	sub_menu_bkg_filler;
	UI_filled_area	idle_bkg_filler;

    /* popup background*/
	color	popup_text_color;

    /* weekday in idle */
	color	idle_scr_weekday_color;
	color	idle_scr_weekday_border_color;

    /* clock */    
	stFontAttribute	date_text_font;
	stFontAttribute	time_text_font;
	color	date_text_color;
	color	date_text_border_color;
	color	time_text_color;
	color	time_text_border_color;
	stFontAttribute	date_text_font_sub_lcd;
	stFontAttribute	time_text_font_sub_lcd;
	color	date_text_color_sub_lcd;
	color	date_text_border_color_sub_lcd;
	color	time_text_color_sub_lcd;
	color	time_text_border_color_sub_lcd;
	color	analog_hand_hour_color;
	color	analog_hand_min_color;
	color	analog_axis_color;

    /* softkey */
	color	softkey_text_border_color;
	UI_filled_area	softkey_bar_bkg_filler;

    /* tab title */
	UI_filled_area	tab_title_filler;
	color	tab_title_text_color;
	color	tab_title_text_border_color;
	color	tab_title_shortcut_text_color;
	stFontAttribute	tab_title_text_font;

    /* IME */
	color	ime_underline_color;
	color	ime_indicator_color;
	color	ime_focused_background_color;
	color	ime_background_color;
	color	ime_focused_border_color;
	color	ime_border_color;
	color	ime_text_color;
	color	ime_lable_color;
	color	ime_hilite_color;
	color	ime_hilite_text_color;
	color	ime_cursor_color;
	color	ime_arrow_color;
	stFontAttribute	ime_text_font;
	stFontAttribute	ime_lable_font;

    /* inline edit */
	UI_filled_area	inline_list_default_text_item_filler;

    /* calendar */
	color	calendar_title_fg_color;
	color	calendar_horizontal_fg_color;
	color	calendar_horizontal_border_color;
	color	calendar_vertical_fg_color;
	color	calendar_horizontal_string_fg_color;
	color	calendar_current_color;
	color	calendar_one_task_color;
	color	calendar_more_task_color;
	color	calendar_menstrual_color;
	color	calendar_PP_color;
	color	calendar_danger_color;
	color	calendar_invalid_color;
	color	calendar_valid_fg_color;
	color	calendar_invalid_fg_color;
	color	calendar_highlight_color;
	color	calendar_infobox_bg_color;
	color	calendar_infobox_entry_bg_color;
	color	calendar_infobox_fg_color;
	stFontAttribute	calendar_infobox_font;
	stFontAttribute	calendar_horizontal_string_font;
	stFontAttribute	calendar_cell_font;
    
    /* Status icon bar */
	UI_filled_area	status_icon_bar_filler;

    /* thick title */
	UI_filled_area	thick_title_filler;
	color	thick_title_text_color;
	color	thick_title_text_border_color;
	color	thick_title_shortcut_text_color;

    /* main menu icon */
    
} MMI_theme_buff_type;


MMI_theme_buff_type buffer_DLT;

/* tags should be sorted in ASCII code order */
const tc_all_tags_index_struct g_tc_xml_tags_map[] = {
	{"CM_screen_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(CM_screen_background_filler), (void *)BASE_PTR(CM_screen_background_filler)},
	{"CM_screen_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(CM_screen_text_color), (void *)BASE_PTR(CM_screen_text_color)},
	{"LSK_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(LSK_disabled_text_color), (void *)BASE_PTR(LSK_disabled_text_color)},
	{"LSK_down_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(LSK_down_text_color), (void *)BASE_PTR(LSK_down_text_color)},
	{"LSK_up_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(LSK_up_text_color), (void *)BASE_PTR(LSK_up_text_color)},
	{"PIN_inputbox_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(PIN_inputbox_background_filler), (void *)BASE_PTR(PIN_inputbox_background_filler)},
	{"PIN_inputbox_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(PIN_inputbox_cursor_color), (void *)BASE_PTR(PIN_inputbox_cursor_color)},
	{"PIN_inputbox_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(PIN_inputbox_normal_text_color), (void *)BASE_PTR(PIN_inputbox_normal_text_color)},
	{"PIN_inputbox_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(PIN_inputbox_selected_text_color), (void *)BASE_PTR(PIN_inputbox_selected_text_color)},
	{"PIN_inputbox_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(PIN_inputbox_selector_color), (void *)BASE_PTR(PIN_inputbox_selector_color)},
	{"PIN_screen_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(PIN_screen_background_filler), (void *)BASE_PTR(PIN_screen_background_filler)},
	{"RSK_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(RSK_disabled_text_color), (void *)BASE_PTR(RSK_disabled_text_color)},
	{"RSK_down_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(RSK_down_text_color), (void *)BASE_PTR(RSK_down_text_color)},
	{"RSK_up_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(RSK_up_text_color), (void *)BASE_PTR(RSK_up_text_color)},
	{"UI_black_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(UI_black_color), (void *)BASE_PTR(UI_black_color)},
	{"UI_white_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(UI_white_color), (void *)BASE_PTR(UI_white_color)},
	{"alarm_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(alarm_background_filler), (void *)BASE_PTR(alarm_background_filler)},
	{"alarm_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(alarm_text_color), (void *)BASE_PTR(alarm_text_color)},
	{"analog_axis_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(analog_axis_color), (void *)BASE_PTR(analog_axis_color)},
	{"analog_hand_hour_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(analog_hand_hour_color), (void *)BASE_PTR(analog_hand_hour_color)},
	{"analog_hand_min_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(analog_hand_min_color), (void *)BASE_PTR(analog_hand_min_color)},
	{"aphorism_screen_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(aphorism_screen_background_filler), (void *)BASE_PTR(aphorism_screen_background_filler)},
	{"bg_opacity_full", mmi_tc_s32_tag_handler, (void *)DLT_PTR(bg_opacity_full), (void *)NULL},
	{"bg_opacity_high", mmi_tc_s32_tag_handler, (void *)DLT_PTR(bg_opacity_high), (void *)NULL},
	{"bg_opacity_low", mmi_tc_s32_tag_handler, (void *)DLT_PTR(bg_opacity_low), (void *)NULL},
	{"bg_opacity_medium", mmi_tc_s32_tag_handler, (void *)DLT_PTR(bg_opacity_medium), (void *)NULL},
	{"button_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(button_font), (void *)BASE_PTR(button_font)},
	{"calculator_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calculator_color), (void *)BASE_PTR(calculator_color)},
	{"calendar_PP_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_PP_color), (void *)BASE_PTR(calendar_PP_color)},
	{"calendar_cell_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(calendar_cell_font), (void *)BASE_PTR(calendar_cell_font)},
	{"calendar_current_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_current_color), (void *)BASE_PTR(calendar_current_color)},
	{"calendar_danger_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_danger_color), (void *)BASE_PTR(calendar_danger_color)},
	{"calendar_highlight_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_highlight_color), (void *)BASE_PTR(calendar_highlight_color)},
	{"calendar_horizontal_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_horizontal_border_color), (void *)BASE_PTR(calendar_horizontal_border_color)},
	{"calendar_horizontal_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_horizontal_fg_color), (void *)BASE_PTR(calendar_horizontal_fg_color)},
	{"calendar_horizontal_string_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_horizontal_string_fg_color), (void *)BASE_PTR(calendar_horizontal_string_fg_color)},
	{"calendar_horizontal_string_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(calendar_horizontal_string_font), (void *)BASE_PTR(calendar_horizontal_string_font)},
	{"calendar_infobox_bg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_infobox_bg_color), (void *)BASE_PTR(calendar_infobox_bg_color)},
	{"calendar_infobox_entry_bg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_infobox_entry_bg_color), (void *)BASE_PTR(calendar_infobox_entry_bg_color)},
	{"calendar_infobox_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_infobox_fg_color), (void *)BASE_PTR(calendar_infobox_fg_color)},
	{"calendar_infobox_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(calendar_infobox_font), (void *)BASE_PTR(calendar_infobox_font)},
	{"calendar_invalid_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_invalid_color), (void *)BASE_PTR(calendar_invalid_color)},
	{"calendar_invalid_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_invalid_fg_color), (void *)BASE_PTR(calendar_invalid_fg_color)},
	{"calendar_menstrual_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_menstrual_color), (void *)BASE_PTR(calendar_menstrual_color)},
	{"calendar_more_task_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_more_task_color), (void *)BASE_PTR(calendar_more_task_color)},
	{"calendar_one_task_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_one_task_color), (void *)BASE_PTR(calendar_one_task_color)},
	{"calendar_title_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_title_fg_color), (void *)BASE_PTR(calendar_title_fg_color)},
	{"calendar_valid_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_valid_fg_color), (void *)BASE_PTR(calendar_valid_fg_color)},
	{"calendar_vertical_fg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(calendar_vertical_fg_color), (void *)BASE_PTR(calendar_vertical_fg_color)},
	{"circular_main_menu_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(circular_main_menu_disabled_text_color), (void *)BASE_PTR(circular_main_menu_disabled_text_color)},
	{"circular_main_menu_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(circular_main_menu_normal_text_color), (void *)BASE_PTR(circular_main_menu_normal_text_color)},
	{"circular_main_menu_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(circular_main_menu_selected_text_color), (void *)BASE_PTR(circular_main_menu_selected_text_color)},
	{"date_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(date_text_border_color), (void *)BASE_PTR(date_text_border_color)},
	{"date_text_border_color_sub_lcd", mmi_tc_color_tag_handler, (void *)DLT_PTR(date_text_border_color_sub_lcd), (void *)BASE_PTR(date_text_border_color_sub_lcd)},
	{"date_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(date_text_color), (void *)BASE_PTR(date_text_color)},
	{"date_text_color_sub_lcd", mmi_tc_color_tag_handler, (void *)DLT_PTR(date_text_color_sub_lcd), (void *)BASE_PTR(date_text_color_sub_lcd)},
	{"date_text_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(date_text_font), (void *)BASE_PTR(date_text_font)},
	{"date_text_font_sub_lcd", mmi_tc_font_tag_handler, (void *)DLT_PTR(date_text_font_sub_lcd), (void *)BASE_PTR(date_text_font_sub_lcd)},
	{"datetime_bar_AOC_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_AOC_text_color), (void *)BASE_PTR(datetime_bar_AOC_text_color)},
	{"datetime_bar_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_background_color), (void *)BASE_PTR(datetime_bar_background_color)},
	{"datetime_bar_date_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_date_text_color), (void *)BASE_PTR(datetime_bar_date_text_color)},
	{"datetime_bar_duration_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_duration_background_color), (void *)BASE_PTR(datetime_bar_duration_background_color)},
	{"datetime_bar_duration_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_duration_text_color), (void *)BASE_PTR(datetime_bar_duration_text_color)},
	{"datetime_bar_time_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(datetime_bar_time_text_color), (void *)BASE_PTR(datetime_bar_time_text_color)},
	{"deviceinfo", mmi_tc_deviceinfo_tag_handler, (void *)NULL, (void *)NULL},
	{"devicetheme", mmi_tc_device_theme_ver_info, (void *)NULL, (void *)NULL},
	{"dialer_inputbox_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(dialer_inputbox_background_filler), (void *)BASE_PTR(dialer_inputbox_background_filler)},
	{"dialer_inputbox_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(dialer_inputbox_cursor_color), (void *)BASE_PTR(dialer_inputbox_cursor_color)},
	{"dialer_inputbox_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(dialer_inputbox_normal_text_color), (void *)BASE_PTR(dialer_inputbox_normal_text_color)},
	{"dialer_inputbox_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(dialer_inputbox_selected_text_color), (void *)BASE_PTR(dialer_inputbox_selected_text_color)},
	{"dialer_inputbox_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(dialer_inputbox_selector_color), (void *)BASE_PTR(dialer_inputbox_selector_color)},
	{"drop_down_control_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(drop_down_control_font), (void *)BASE_PTR(drop_down_control_font)},
	{"drop_down_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(drop_down_disabled_text_color), (void *)BASE_PTR(drop_down_disabled_text_color)},
	{"drop_down_focussed_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(drop_down_focussed_text_color), (void *)BASE_PTR(drop_down_focussed_text_color)},
	{"drop_down_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(drop_down_normal_text_color), (void *)BASE_PTR(drop_down_normal_text_color)},
	{"formatted_inputbox_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(formatted_inputbox_cursor_color), (void *)BASE_PTR(formatted_inputbox_cursor_color)},
	{"formatted_inputbox_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(formatted_inputbox_disabled_text_color), (void *)BASE_PTR(formatted_inputbox_disabled_text_color)},
	{"formatted_inputbox_normal_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(formatted_inputbox_normal_filler), (void *)BASE_PTR(formatted_inputbox_normal_filler)},
	{"formatted_inputbox_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(formatted_inputbox_normal_text_color), (void *)BASE_PTR(formatted_inputbox_normal_text_color)},
	{"formatted_inputbox_selected_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(formatted_inputbox_selected_filler), (void *)BASE_PTR(formatted_inputbox_selected_filler)},
	{"formatted_inputbox_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(formatted_inputbox_selected_text_color), (void *)BASE_PTR(formatted_inputbox_selected_text_color)},
	{"formatted_inputbox_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(formatted_inputbox_selector_color), (void *)BASE_PTR(formatted_inputbox_selector_color)},
	{"general_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(general_background_filler), (void *)BASE_PTR(general_background_filler)},
	{"idle_bkg_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(idle_bkg_filler), (void *)BASE_PTR(idle_bkg_filler)},
	{"idle_scr_date_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_date_border_color), (void *)BASE_PTR(idle_scr_date_border_color)},
	{"idle_scr_date_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_date_color), (void *)BASE_PTR(idle_scr_date_color)},
	{"idle_scr_network_extra_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_extra_border_color), (void *)BASE_PTR(idle_scr_network_extra_border_color)},
	{"idle_scr_network_extra_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_extra_color), (void *)BASE_PTR(idle_scr_network_extra_color)},
	{"idle_scr_network_name_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_name_border_color), (void *)BASE_PTR(idle_scr_network_name_border_color)},
	{"idle_scr_network_name_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_name_color), (void *)BASE_PTR(idle_scr_network_name_color)},
	{"idle_scr_network_status_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_status_border_color), (void *)BASE_PTR(idle_scr_network_status_border_color)},
	{"idle_scr_network_status_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_network_status_color), (void *)BASE_PTR(idle_scr_network_status_color)},
	{"idle_scr_time_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_time_border_color), (void *)BASE_PTR(idle_scr_time_border_color)},
	{"idle_scr_time_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_time_color), (void *)BASE_PTR(idle_scr_time_color)},
	{"idle_scr_weekday_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_weekday_border_color), (void *)BASE_PTR(idle_scr_weekday_border_color)},
	{"idle_scr_weekday_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(idle_scr_weekday_color), (void *)BASE_PTR(idle_scr_weekday_color)},
	{"image_id", mmi_tc_image_list_tag_handler, (void *)NULL, (void *)NULL},
	{"ime_arrow_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_arrow_color), (void *)BASE_PTR(ime_arrow_color)},
	{"ime_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_background_color), (void *)BASE_PTR(ime_background_color)},
	{"ime_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_border_color), (void *)BASE_PTR(ime_border_color)},
	{"ime_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_cursor_color), (void *)BASE_PTR(ime_cursor_color)},
	{"ime_focused_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_focused_background_color), (void *)BASE_PTR(ime_focused_background_color)},
	{"ime_focused_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_focused_border_color), (void *)BASE_PTR(ime_focused_border_color)},
	{"ime_hilite_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_hilite_color), (void *)BASE_PTR(ime_hilite_color)},
	{"ime_hilite_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_hilite_text_color), (void *)BASE_PTR(ime_hilite_text_color)},
	{"ime_indicator_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_indicator_color), (void *)BASE_PTR(ime_indicator_color)},
	{"ime_lable_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_lable_color), (void *)BASE_PTR(ime_lable_color)},
	{"ime_lable_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(ime_lable_font), (void *)BASE_PTR(ime_lable_font)},
	{"ime_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_text_color), (void *)BASE_PTR(ime_text_color)},
	{"ime_text_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(ime_text_font), (void *)BASE_PTR(ime_text_font)},
	{"ime_underline_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(ime_underline_color), (void *)BASE_PTR(ime_underline_color)},
	{"information_bar_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(information_bar_color), (void *)BASE_PTR(information_bar_color)},
	{"inline_edit_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_edit_cursor_color), (void *)BASE_PTR(inline_edit_cursor_color)},
	{"inline_edit_focussed_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_edit_focussed_filler), (void *)BASE_PTR(inline_edit_focussed_filler)},
	{"inline_edit_focussed_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_edit_focussed_text_color), (void *)BASE_PTR(inline_edit_focussed_text_color)},
	{"inline_edit_noboundary_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_edit_noboundary_filler), (void *)BASE_PTR(inline_edit_noboundary_filler)},
	{"inline_edit_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_edit_selected_text_color), (void *)BASE_PTR(inline_edit_selected_text_color)},
	{"inline_edit_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_edit_selector_color), (void *)BASE_PTR(inline_edit_selector_color)},
	{"inline_edit_unfocussed_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_edit_unfocussed_filler), (void *)BASE_PTR(inline_edit_unfocussed_filler)},
	{"inline_edit_unfocussed_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_edit_unfocussed_text_color), (void *)BASE_PTR(inline_edit_unfocussed_text_color)},
	{"inline_list_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_list_background_filler), (void *)BASE_PTR(inline_list_background_filler)},
	{"inline_list_default_text_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_list_default_text_item_filler), (void *)BASE_PTR(inline_list_default_text_item_filler)},
	{"inline_list_disabled_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_list_disabled_item_filler), (void *)BASE_PTR(inline_list_disabled_item_filler)},
	{"inline_list_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_list_disabled_text_color), (void *)BASE_PTR(inline_list_disabled_text_color)},
	{"inline_list_normal_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_list_normal_item_filler), (void *)BASE_PTR(inline_list_normal_item_filler)},
	{"inline_list_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_list_normal_text_color), (void *)BASE_PTR(inline_list_normal_text_color)},
	{"inline_list_selected_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inline_list_selected_item_filler), (void *)BASE_PTR(inline_list_selected_item_filler)},
	{"inline_list_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inline_list_selected_text_color), (void *)BASE_PTR(inline_list_selected_text_color)},
	{"input_method_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(input_method_text_color), (void *)BASE_PTR(input_method_text_color)},
	{"inputbox_cursor_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inputbox_cursor_color), (void *)BASE_PTR(inputbox_cursor_color)},
	{"inputbox_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(inputbox_filler), (void *)BASE_PTR(inputbox_filler)},
	{"inputbox_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(inputbox_font), (void *)BASE_PTR(inputbox_font)},
	{"inputbox_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inputbox_normal_text_color), (void *)BASE_PTR(inputbox_normal_text_color)},
	{"inputbox_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inputbox_selected_text_color), (void *)BASE_PTR(inputbox_selected_text_color)},
	{"inputbox_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(inputbox_selector_color), (void *)BASE_PTR(inputbox_selector_color)},
	{"list_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_background_filler), (void *)BASE_PTR(list_background_filler)},
	{"list_disabled_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_disabled_item_filler), (void *)BASE_PTR(list_disabled_item_filler)},
	{"list_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_disabled_text_color), (void *)BASE_PTR(list_disabled_text_color)},
	{"list_main_menu_disabled_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_main_menu_disabled_item_filler), (void *)BASE_PTR(list_main_menu_disabled_item_filler)},
	{"list_main_menu_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_main_menu_disabled_text_color), (void *)BASE_PTR(list_main_menu_disabled_text_color)},
	{"list_main_menu_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(list_main_menu_font), (void *)BASE_PTR(list_main_menu_font)},
	{"list_main_menu_normal_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_main_menu_normal_item_filler), (void *)BASE_PTR(list_main_menu_normal_item_filler)},
	{"list_main_menu_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_main_menu_normal_text_color), (void *)BASE_PTR(list_main_menu_normal_text_color)},
	{"list_main_menu_selected_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_main_menu_selected_item_filler), (void *)BASE_PTR(list_main_menu_selected_item_filler)},
	{"list_main_menu_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_main_menu_selected_text_color), (void *)BASE_PTR(list_main_menu_selected_text_color)},
	{"list_menu_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(list_menu_font), (void *)BASE_PTR(list_menu_font)},
	{"list_normal_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_normal_item_filler), (void *)BASE_PTR(list_normal_item_filler)},
	{"list_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_normal_text_color), (void *)BASE_PTR(list_normal_text_color)},
	{"list_selected_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(list_selected_item_filler), (void *)BASE_PTR(list_selected_item_filler)},
	{"list_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(list_selected_text_color), (void *)BASE_PTR(list_selected_text_color)},
	{"lite_disp_scr_bg_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(lite_disp_scr_bg_color), (void *)BASE_PTR(lite_disp_scr_bg_color)},
	{"main_menu_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(main_menu_background_filler), (void *)BASE_PTR(main_menu_background_filler)},
	{"main_menu_bkg_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(main_menu_bkg_filler), (void *)BASE_PTR(main_menu_bkg_filler)},
	{"main_menu_icon1", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon1), (void *)NULL},
	{"main_menu_icon10", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon10), (void *)NULL},
	{"main_menu_icon11", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon11), (void *)NULL},
	{"main_menu_icon12", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon12), (void *)NULL},
	{"main_menu_icon13", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon13), (void *)NULL},
	{"main_menu_icon14", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon14), (void *)NULL},
	{"main_menu_icon15", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon15), (void *)NULL},
	{"main_menu_icon2", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon2), (void *)NULL},
	{"main_menu_icon3", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon3), (void *)NULL},
	{"main_menu_icon4", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon4), (void *)NULL},
	{"main_menu_icon5", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon5), (void *)NULL},
	{"main_menu_icon6", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon6), (void *)NULL},
	{"main_menu_icon7", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon7), (void *)NULL},
	{"main_menu_icon8", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon8), (void *)NULL},
	{"main_menu_icon9", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(main_menu_icon9), (void *)NULL},
	{"matrix_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_background_filler), (void *)BASE_PTR(matrix_background_filler)},
	{"matrix_disabled_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_disabled_item_filler), (void *)BASE_PTR(matrix_disabled_item_filler)},
	{"matrix_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_disabled_text_color), (void *)BASE_PTR(matrix_disabled_text_color)},
	{"matrix_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_highlight_filler), (void *)BASE_PTR(matrix_highlight_filler)},
	{"matrix_main_menu_disabled_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_main_menu_disabled_item_filler), (void *)BASE_PTR(matrix_main_menu_disabled_item_filler)},
	{"matrix_main_menu_disabled_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_main_menu_disabled_text_color), (void *)BASE_PTR(matrix_main_menu_disabled_text_color)},
	{"matrix_main_menu_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(matrix_main_menu_font), (void *)BASE_PTR(matrix_main_menu_font)},
	{"matrix_main_menu_normal_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_main_menu_normal_item_filler), (void *)BASE_PTR(matrix_main_menu_normal_item_filler)},
	{"matrix_main_menu_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_main_menu_normal_text_color), (void *)BASE_PTR(matrix_main_menu_normal_text_color)},
	{"matrix_main_menu_selected_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_main_menu_selected_item_filler), (void *)BASE_PTR(matrix_main_menu_selected_item_filler)},
	{"matrix_main_menu_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_main_menu_selected_text_color), (void *)BASE_PTR(matrix_main_menu_selected_text_color)},
	{"matrix_menu_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(matrix_menu_font), (void *)BASE_PTR(matrix_menu_font)},
	{"matrix_normal_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_normal_item_filler), (void *)BASE_PTR(matrix_normal_item_filler)},
	{"matrix_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_normal_text_color), (void *)BASE_PTR(matrix_normal_text_color)},
	{"matrix_selected_item_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(matrix_selected_item_filler), (void *)BASE_PTR(matrix_selected_item_filler)},
	{"matrix_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(matrix_selected_text_color), (void *)BASE_PTR(matrix_selected_text_color)},
	{"media", mmi_tc_generic_dummy_handler, (void *)NULL, (void *)NULL},
	{"menu_bar_index_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(menu_bar_index_font), (void *)BASE_PTR(menu_bar_index_font)},
	{"menu_bar_item_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(menu_bar_item_font), (void *)BASE_PTR(menu_bar_item_font)},
	{"menubar_index_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(menubar_index_background_color), (void *)BASE_PTR(menubar_index_background_color)},
	{"menubar_index_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(menubar_index_text_color), (void *)BASE_PTR(menubar_index_text_color)},
	{"menubar_item_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(menubar_item_background_color), (void *)BASE_PTR(menubar_item_background_color)},
	{"menubar_item_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(menubar_item_text_color), (void *)BASE_PTR(menubar_item_text_color)},
	{"menuitem_multirow_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(menuitem_multirow_highlight_filler), (void *)BASE_PTR(menuitem_multirow_highlight_filler)},
	{"menuitem_single_line_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(menuitem_single_line_highlight_filler), (void *)BASE_PTR(menuitem_single_line_highlight_filler)},
	{"menuitem_thick_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(menuitem_thick_highlight_filler), (void *)BASE_PTR(menuitem_thick_highlight_filler)},
	{"menuitem_thick_with_tab_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(menuitem_thick_with_tab_highlight_filler), (void *)BASE_PTR(menuitem_thick_with_tab_highlight_filler)},
	{"menuitem_two_line_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(menuitem_two_line_highlight_filler), (void *)BASE_PTR(menuitem_two_line_highlight_filler)},
	{"multitap_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(multitap_filler), (void *)BASE_PTR(multitap_filler)},
	{"multitap_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(multitap_font), (void *)BASE_PTR(multitap_font)},
	{"multitap_normal_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(multitap_normal_text_color), (void *)BASE_PTR(multitap_normal_text_color)},
	{"multitap_selected_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(multitap_selected_text_color), (void *)BASE_PTR(multitap_selected_text_color)},
	{"multitap_selector_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(multitap_selector_color), (void *)BASE_PTR(multitap_selector_color)},
	{"network_screen_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(network_screen_background_filler), (void *)BASE_PTR(network_screen_background_filler)},
	{"popup_bkg_image", mmi_tc_pu8_tag_handler, (void *)DLT_PTR(popup_bkg_image), (void *)NULL},
	{"popup_description_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(popup_description_background_filler), (void *)BASE_PTR(popup_description_background_filler)},
	{"popup_description_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(popup_description_text_color), (void *)BASE_PTR(popup_description_text_color)},
	{"popup_screen_background_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(popup_screen_background_color), (void *)BASE_PTR(popup_screen_background_color)},
	{"popup_screen_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(popup_screen_border_color), (void *)BASE_PTR(popup_screen_border_color)},
	{"popup_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(popup_text_color), (void *)BASE_PTR(popup_text_color)},
	{"progress_screen_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(progress_screen_background_filler), (void *)BASE_PTR(progress_screen_background_filler)},
	{"remaining_length_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(remaining_length_text_color), (void *)BASE_PTR(remaining_length_text_color)},
	{"scrollbar_background_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(scrollbar_background_filler), (void *)BASE_PTR(scrollbar_background_filler)},
	{"scrollbar_indicator_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(scrollbar_indicator_filler), (void *)BASE_PTR(scrollbar_indicator_filler)},
	{"scrollbar_size", mmi_tc_s32_tag_handler, (void *)DLT_PTR(scrollbar_size), (void *)NULL},
	{"shortcut_indicator_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(shortcut_indicator_font), (void *)BASE_PTR(shortcut_indicator_font)},
	{"small_list_menu_normal_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(small_list_menu_normal_filler), (void *)BASE_PTR(small_list_menu_normal_filler)},
	{"small_list_screen_border_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(small_list_screen_border_filler), (void *)BASE_PTR(small_list_screen_border_filler)},
	{"softkey_bar_bkg_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(softkey_bar_bkg_filler), (void *)BASE_PTR(softkey_bar_bkg_filler)},
	{"softkey_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(softkey_text_border_color), (void *)BASE_PTR(softkey_text_border_color)},
	{"status_icon_bar_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(status_icon_bar_filler), (void *)BASE_PTR(status_icon_bar_filler)},
	{"sub_menu_bkg_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(sub_menu_bkg_filler), (void *)BASE_PTR(sub_menu_bkg_filler)},
	{"symbol_picker_highlight_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(symbol_picker_highlight_filler), (void *)BASE_PTR(symbol_picker_highlight_filler)},
	{"tab_title_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(tab_title_filler), (void *)BASE_PTR(tab_title_filler)},
	{"tab_title_shortcut_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(tab_title_shortcut_text_color), (void *)BASE_PTR(tab_title_shortcut_text_color)},
	{"tab_title_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(tab_title_text_border_color), (void *)BASE_PTR(tab_title_text_border_color)},
	{"tab_title_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(tab_title_text_color), (void *)BASE_PTR(tab_title_text_color)},
	{"tab_title_text_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(tab_title_text_font), (void *)BASE_PTR(tab_title_text_font)},
	{"thick_title_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(thick_title_filler), (void *)BASE_PTR(thick_title_filler)},
	{"thick_title_shortcut_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(thick_title_shortcut_text_color), (void *)BASE_PTR(thick_title_shortcut_text_color)},
	{"thick_title_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(thick_title_text_border_color), (void *)BASE_PTR(thick_title_text_border_color)},
	{"thick_title_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(thick_title_text_color), (void *)BASE_PTR(thick_title_text_color)},
	{"time_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(time_text_border_color), (void *)BASE_PTR(time_text_border_color)},
	{"time_text_border_color_sub_lcd", mmi_tc_color_tag_handler, (void *)DLT_PTR(time_text_border_color_sub_lcd), (void *)BASE_PTR(time_text_border_color_sub_lcd)},
	{"time_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(time_text_color), (void *)BASE_PTR(time_text_color)},
	{"time_text_color_sub_lcd", mmi_tc_color_tag_handler, (void *)DLT_PTR(time_text_color_sub_lcd), (void *)BASE_PTR(time_text_color_sub_lcd)},
	{"time_text_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(time_text_font), (void *)BASE_PTR(time_text_font)},
	{"time_text_font_sub_lcd", mmi_tc_font_tag_handler, (void *)DLT_PTR(time_text_font_sub_lcd), (void *)BASE_PTR(time_text_font_sub_lcd)},
	{"title_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(title_filler), (void *)BASE_PTR(title_filler)},
	{"title_shortcut_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(title_shortcut_text_color), (void *)BASE_PTR(title_shortcut_text_color)},
	{"title_text_border_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(title_text_border_color), (void *)BASE_PTR(title_text_border_color)},
	{"title_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(title_text_color), (void *)BASE_PTR(title_text_color)},
	{"title_text_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(title_text_font), (void *)BASE_PTR(title_text_font)},
	{"tones_list", mmi_tc_tones_list_tag_handler, (void *)NULL, (void *)NULL},
	{"virtual_keyboard_dead_key_down_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(virtual_keyboard_dead_key_down_text_color), (void *)BASE_PTR(virtual_keyboard_dead_key_down_text_color)},
	{"virtual_keyboard_dead_key_up_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(virtual_keyboard_dead_key_up_text_color), (void *)BASE_PTR(virtual_keyboard_dead_key_up_text_color)},
	{"virtual_keyboard_disp_area_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(virtual_keyboard_disp_area_text_color), (void *)BASE_PTR(virtual_keyboard_disp_area_text_color)},
	{"virtual_keyboard_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(virtual_keyboard_font), (void *)BASE_PTR(virtual_keyboard_font)},
	{"virtual_keyboard_key_down_filler", mmi_tc_filler_tag_handler, (void *)DLT_PTR(virtual_keyboard_key_down_filler), (void *)BASE_PTR(virtual_keyboard_key_down_filler)},
	{"virtual_keyboard_key_down_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(virtual_keyboard_key_down_text_color), (void *)BASE_PTR(virtual_keyboard_key_down_text_color)},
	{"virtual_keyboard_key_up_text_color", mmi_tc_color_tag_handler, (void *)DLT_PTR(virtual_keyboard_key_up_text_color), (void *)BASE_PTR(virtual_keyboard_key_up_text_color)},
	{"window_title_font", mmi_tc_font_tag_handler, (void *)DLT_PTR(window_title_font), (void *)BASE_PTR(window_title_font)},
};

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

