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
/********************************************************************************
* Filename:
* ---------
*	ThemeRes.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file contains all themes
*
* Version:
* ------------
*	07A VERSION
*
*******************************************************************************/
/******************************************************************************
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/
#include "PixtelDatatypes.h"
#include "MMI_features.h"
#include "gui_themes.h"
#include "ThemeComponents.h"

#define MAX_MMI_THEMES 3

S32 mtk_n_MMI_themes=MAX_MMI_THEMES;

const MMI_theme theme_defaultTheme={
(UI_filled_area*)&multitap_filler_defaultTheme,
(UI_filled_area*)&inputbox_filler_defaultTheme,
(UI_filled_area*)&scrollbar_background_filler_defaultTheme,
(UI_filled_area*)&scrollbar_indicator_filler_defaultTheme,
(UI_filled_area*)&title_filler_defaultTheme,
(UI_filled_area*)&list_background_filler_defaultTheme,
(UI_filled_area*)&list_normal_item_filler_defaultTheme,
(UI_filled_area*)&list_selected_item_filler_defaultTheme,
(UI_filled_area*)&list_disabled_item_filler_defaultTheme,
(UI_filled_area*)&matrix_background_filler_defaultTheme,
(UI_filled_area*)&matrix_normal_item_filler_defaultTheme,
(UI_filled_area*)&matrix_selected_item_filler_defaultTheme,
(UI_filled_area*)&matrix_disabled_item_filler_defaultTheme,
(UI_filled_area*)&formatted_inputbox_normal_filler_defaultTheme,
(UI_filled_area*)&formatted_inputbox_selected_filler_defaultTheme,
(UI_filled_area*)&main_menu_background_filler_defaultTheme,
(UI_filled_area*)&list_main_menu_normal_item_filler_defaultTheme,
(UI_filled_area*)&list_main_menu_selected_item_filler_defaultTheme,
(UI_filled_area*)&list_main_menu_disabled_item_filler_defaultTheme,
(UI_filled_area*)&matrix_main_menu_normal_item_filler_defaultTheme,
(UI_filled_area*)&matrix_main_menu_selected_item_filler_defaultTheme,
(UI_filled_area*)&matrix_main_menu_disabled_item_filler_defaultTheme,
(UI_filled_area*)&general_background_filler_defaultTheme,
(UI_filled_area*)&popup_description_background_filler_defaultTheme,
(UI_filled_area*)&inline_list_background_filler_defaultTheme,
(UI_filled_area*)&inline_list_normal_item_filler_defaultTheme,
(UI_filled_area*)&inline_list_selected_item_filler_defaultTheme,
(UI_filled_area*)&inline_list_disabled_item_filler_defaultTheme,
(UI_filled_area*)&inline_edit_focussed_filler_defaultTheme,
(UI_filled_area*)&inline_edit_unfocussed_filler_defaultTheme,
(UI_filled_area*)&inline_edit_noboundary_filler_defaultTheme,
(UI_filled_area*)&PIN_inputbox_background_filler_defaultTheme,
(UI_filled_area*)&PIN_screen_background_filler_defaultTheme,
(UI_filled_area*)&network_screen_background_filler_defaultTheme,
(UI_filled_area*)&aphorism_screen_background_filler_defaultTheme,
(UI_filled_area*)&CM_screen_background_filler_defaultTheme,
(UI_filled_area*)&Progress_screen_background_filler_defaultTheme,
(UI_filled_area*)&dialer_inputbox_background_filler_defaultTheme,
(UI_filled_area*)&virtual_keyboard_key_down_filler_defaultTheme,
(UI_filled_area*)&alarm_filler_defaultTheme,
(UI_filled_area*)&small_list_menu_normal_filler_defaultTheme,
(UI_filled_area*)&small_list_screen_border_filler_defaultTheme,
(color*)&UI_black_color_defaultTheme,
(color*)&UI_white_color_defaultTheme,
(color*)&lite_disp_scr_bg_color_defaultTheme,
(color*)&LSK_up_text_color_defaultTheme,
(color*)&LSK_down_text_color_defaultTheme,
(color*)&LSK_disabled_text_color_defaultTheme,
(color*)&RSK_up_text_color_defaultTheme,
(color*)&RSK_down_text_color_defaultTheme,
(color*)&RSK_disabled_text_color_defaultTheme,
(color*)&multitap_selector_color_defaultTheme,
(color*)&multitap_normal_text_color_defaultTheme,
(color*)&multitap_selected_text_color_defaultTheme,
(color*)&inputbox_normal_text_color_defaultTheme,
(color*)&inputbox_selected_text_color_defaultTheme,
(color*)&inputbox_selector_color_defaultTheme,
(color*)&inputbox_cursor_color_defaultTheme,
(color*)&title_text_color_defaultTheme,
(color*)&title_text_border_color_defaultTheme,
(color*)&title_shortcut_text_color_defaultTheme,
(color*)&list_normal_text_color_defaultTheme,
(color*)&list_selected_text_color_defaultTheme,
(color*)&list_disabled_text_color_defaultTheme,
(color*)&matrix_normal_text_color_defaultTheme,
(color*)&matrix_selected_text_color_defaultTheme,
(color*)&matrix_disabled_text_color_defaultTheme,
(color*)&menubar_index_background_color_defaultTheme,
(color*)&menubar_item_background_color_defaultTheme,
(color*)&menubar_index_text_color_defaultTheme,
(color*)&menubar_item_text_color_defaultTheme,
(color*)&drop_down_normal_text_color_defaultTheme,
(color*)&drop_down_disabled_text_color_defaultTheme,
(color*)&drop_down_focussed_text_color_defaultTheme,
(color*)&formatted_inputbox_selector_color_defaultTheme,
(color*)&formatted_inputbox_normal_text_color_defaultTheme,
(color*)&formatted_inputbox_disabled_text_color_defaultTheme,
(color*)&formatted_inputbox_selected_text_color_defaultTheme,
(color*)&formatted_inputbox_cursor_color_defaultTheme,
(color*)&list_main_menu_normal_text_color_defaultTheme,
(color*)&list_main_menu_selected_text_color_defaultTheme,
(color*)&list_main_menu_disabled_text_color_defaultTheme,
(color*)&matrix_main_menu_normal_text_color_defaultTheme,
(color*)&matrix_main_menu_selected_text_color_defaultTheme,
(color*)&matrix_main_menu_disabled_text_color_defaultTheme,
(color*)&circular_main_menu_normal_text_color_defaultTheme,
(color*)&circular_main_menu_selected_text_color_defaultTheme,
(color*)&circular_main_menu_disabled_text_color_defaultTheme,
(color*)&popup_screen_background_color_defaultTheme,
(color*)&popup_screen_border_color_defaultTheme,
(color*)&popup_description_text_color_defaultTheme,
(color*)&CM_screen_text_color_defaultTheme,
(color*)&datetime_bar_background_color_defaultTheme,
(color*)&datetime_bar_duration_background_color_defaultTheme,
(color*)&datetime_bar_date_text_color_defaultTheme,
(color*)&datetime_bar_time_text_color_defaultTheme,
(color*)&datetime_bar_duration_text_color_defaultTheme,
(color*)&datetime_bar_AOC_text_color_defaultTheme,
(color*)&information_bar_color_defaultTheme,
(color*)&input_method_text_color_defaultTheme,
(color*)&remaining_length_text_color_defaultTheme,
(color*)&inline_edit_focussed_text_color_defaultTheme,
(color*)&inline_edit_unfocussed_text_color_defaultTheme,
(color*)&inline_edit_selected_text_color_defaultTheme,
(color*)&inline_edit_selector_color_defaultTheme,
(color*)&inline_edit_cursor_color_defaultTheme,
(color*)&inline_list_normal_text_color_defaultTheme,
(color*)&inline_list_selected_text_color_defaultTheme,
(color*)&inline_list_disabled_text_color_defaultTheme,
(color*)&PIN_inputbox_normal_text_color_defaultTheme,
(color*)&PIN_inputbox_selected_text_color_defaultTheme,
(color*)&PIN_inputbox_selector_color_defaultTheme,
(color*)&PIN_inputbox_cursor_color_defaultTheme,
(color*)&dialer_inputbox_normal_text_color_defaultTheme,
(color*)&dialer_inputbox_selected_text_color_defaultTheme,
(color*)&dialer_inputbox_selector_color_defaultTheme,
(color*)&dialer_inputbox_cursor_color_defaultTheme,
(color*)&virtual_keyboard_key_down_text_color_defaultTheme,
(color*)&virtual_keyboard_key_up_text_color_defaultTheme,
(color*)&virtual_keyboard_dead_key_down_text_color_defaultTheme,
(color*)&virtual_keyboard_dead_key_up_text_color_defaultTheme,
(color*)&virtual_keyboard_disp_area_text_color_defaultTheme,
(color*)&calculator_text_color_defaultTheme,
(color*)&alarm_text_color_defaultTheme,
(color*)&idle_scr_date_color_defaultTheme,
(color*)&idle_scr_time_color_defaultTheme,
(color*)&idle_scr_date_border_color_defaultTheme,
(color*)&idle_scr_time_border_color_defaultTheme,
(color*)&idle_scr_network_name_color_defaultTheme,
(color*)&idle_scr_network_name_border_color_defaultTheme,
(color*)&idle_scr_network_status_color_defaultTheme,
(color*)&idle_scr_network_status_border_color_defaultTheme,
(color*)&idle_scr_network_extra_color_defaultTheme,
(color*)&idle_scr_network_extra_border_color_defaultTheme,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_medium_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_medium_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
255,
220,
220,
220,

#if (UI_SCROLLBAR_WIDTH == 14)
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_160x22_filler_defaultTheme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_160x44_filler_defaultTheme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_defaultTheme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_defaultTheme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_160x35_filler_defaultTheme,
#else /* UI_SCROLLBAR_STYLE_3 */
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_166x22_filler_defaultTheme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_166x44_filler_defaultTheme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_defaultTheme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_defaultTheme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_166x35_filler_defaultTheme,
#endif /* UI_SCROLLBAR_STYLE_3 */

/* symbol_picker_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_defaultTheme,
/* matrix_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_defaultTheme,
/* main_menu_bkg_image */
(UI_filled_area*)&main_menu_bkg_filler_defaultTheme_1,
/* sub_menu_bkg_image */
(UI_filled_area*)&sub_menu_bkg_filler_defaultTheme_1,
/* idle_bkg_image */
(UI_filled_area*)&idle_menu_bkg_filler_defaultTheme_1,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&UI_black_color_defaultTheme,
/* idle_scr_weekday_color */
(color*)&idle_weekday_text_color_DefaultTheme,
/* idle_scr_weekday_border_color */
(color*)&idle_weekday_text_border_color_DefaultTheme,
/* date_text_font */
&MMI_large_font,
/* time_text_font */
&MMI_large_font,
/* date_text_color */
(color*)&clock_date_text_color_DefaultTheme,
/* date_text_border_color */
(color*)&clock_date_text_border_color_DefaultTheme,
/* time_text_color */
(color*)&clock_time_text_color_DefaultTheme,
/* time_text_border_color */
(color*)&clock_time_text_border_color_DefaultTheme,
/* date_text_font_sub_lcd */
&MMI_small_font,
/* time_text_font_sub_lcd */
&MMI_small_font,
/* date_text_color_sub_lcd */
(color*)&clock_date_text_color_sublcd_wallpaper_DefaultTheme,
/* date_text_border_color_sub_lcd */
(color*)&clock_date_text_border_color_sublcd_wallpaper_DefaultTheme,
/* time_text_color_sub_lcd */
(color*)&clock_time_text_color_sublcd_wallpaper_DefaultTheme,
/* time_text_border_color_sub_lcd */
(color*)&clock_time_text_border_color_sublcd_wallpaper_DefaultTheme,
/* analog_hand_hour_color */
(color*)&clock_analog_hand_hour_DefaultTheme,
/* analog_hand_min_color */
(color*)&clock_analog_hand_min_DefaultTheme,
/* analog_axis_color */
(color*)&clock_analog_axis_DefaultTheme,
/* softkey_text_border_color */
(color*)&softkey_text_border_defaultTheme,
/* softkey_bar_bkg_image */
NULL,
/* tab_title_filler */
(UI_filled_area*)&tab_title_filler_defaultTheme,
/* tab_title_text_color */
(color*)&title_text_color_defaultTheme,
/* tab_title_text_border_color */
(color*)&title_text_border_color_defaultTheme,
/* tab_title_shortcut_text_color */
(color*)&title_shortcut_text_color_defaultTheme,
/* tab_title_text_font */
&MMI_medium_font,
/* ime_underline_color */
(color*)&ime_underline_color_defaultTheme,
/* ime_indicator_color */
(color*)&ime_indicator_color_defaultTheme,
/* ime_focused_background_color */
(color*)&ime_focused_background_color_defaultTheme,
/* ime_background_color */
(color*)&ime_background_color_defaultTheme,
/* ime_focused_border_color */
(color*)&ime_focused_border_color_defaultTheme,
/* ime_border_color */
(color*)&ime_border_color_defaultTheme,
/* ime_text_color */
(color*)&ime_text_color_defaultTheme,
/* ime_lable_color */
(color*)&ime_lable_color_defaultTheme,
/* ime_hilite_color */
(color*)&ime_hilite_color_defaultTheme,
/* ime_hilite_text_color */
(color*)&ime_hilite_text_color_defaultTheme,
/* ime_cursor_color */
(color*)&ime_cursor_color_defaultTheme,
/* ime_arrow_color */
(color*)&ime_arrow_color_defaultTheme,
/* ime_text_font */
&MMI_medium_font,
/* ime_lable_font */
&MMI_small_font,
/* inline_list_default_text_item_filler */
NULL,
/* calendar_title_fg_color */
(color*)&calendar_title_fg_DefaultTheme,
/* calendar_horizontal_fg_color */
(color*)&calendar_horizontal_select_fg_DefaultTheme,
/* calendar_horizontal_border_color */
(color*)&calendar_horizontal_select_border_DefaultTheme,
/* calendar_vertical_fg_color */
(color*)&calendar_vertical_select_fg_DefaultTheme,
/* calendar_horizontal_string_fg_color */
(color*)&calendar_horizontal_string_fg_DefaultTheme,
/* calendar_current_color */
(color*)&calendar_cell_current_DefaultTheme,
/* calendar_one_task_color */
(color*)&calendar_cell_one_task_DefaultTheme,
/* calendar_more_task_color */
(color*)&calendar_cell_more_task_DefaultTheme,
/* calendar_menstrual_color */
(color*)&calendar_cell_menstrual_DefaultTheme,
/* calendar_PP_color */
(color*)&calendar_cell_PP_DefaultTheme,
/* calendar_danger_color */
(color*)&calendar_cell_danger_DefaultTheme,
/* calendar_invalid_color */
(color*)&calendar_cell_invalid_DefaultTheme,  
/* calendar_valid_fg_color */
(color*)&calendar_valid_fg_DefaultTheme,
/* calendar_invalid_fg_color */
(color*)&calendar_invalid_fg_DefaultTheme,
/* calendar_highlight_color */
(color*)&calendar_highlight_DefaultTheme,    
/* calendar_infobox_bg_color */
(color*)&calendar_infobox_bg_DefaultTheme,
/* calendar_infobox_entry_bg_color */
(color*)&calendar_infobox_entry_bg_DefaultTheme,
/* calendar_infobox_fg_color */
(color*)&calendar_infobox_fg_DefaultTheme,
/* calendar_infobox_font */
&MMI_small_font,
/* calendar_horizontal_string_font */
&MMI_small_font,
/* calendar_cell_font */
&MMI_small_font,
/* status icon bar filler*/
(UI_filled_area*)&status_icon_bar_filler_defaultTheme,
/* thick title filler*/
(UI_filled_area*)&title_filler_defaultTheme,
/* thick title text color */
(color*)&title_text_color_defaultTheme,
/* thick title text border color */
(color*)&title_text_border_color_defaultTheme,
/* thick title shortcut color */
(color*)&title_shortcut_text_color_defaultTheme,
/* main menu icon 1 */
NULL,
/* main menu icon 2 */
NULL,
/* main menu icon 3 */
NULL,
/* main menu icon 4 */
NULL,
/* main menu icon 5 */
NULL,
/* main menu icon 6 */
NULL,
/* main menu icon 7 */
NULL,
/* main menu icon 8 */
NULL,
/* main menu icon 9 */
NULL,
/* main menu icon 10 */
NULL,
/* main menu icon 11 */
NULL,
/* main menu icon 12 */
NULL,
/* main menu icon 13 */
NULL,
/* main menu icon 14 */
NULL,
/* main menu icon 15 */
NULL,
/* back ground filler of rotate screen*/
(UI_filled_area  *)NULL,
/* back ground image of rotate popup screen */
NULL,
/* filler of title in rotate screen */
(UI_filled_area  *)NULL,
/* filler of title in small screen */
(UI_filled_area*)&small_title_filler_Theme,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_highlight_filler_defaultTheme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

/* high light image of matrix main menu */
(PU8)matrix_main_menu_highlight_image_defaultTheme,

/* background filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_background_filler_defaultTheme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

/* separator color in list menu */
(color *)NULL,
/* separator color of cascade menu */
(color *)NULL,
/* normal text color of cascade menu */
(color *)NULL,
/* selected text color of cascade menu */
(color *)NULL,
/* disabled text color of cascade menu */
(color *)NULL,
/* border color of cascade menu */
(color *)NULL,
/* back ground filler of cascade menu */
(UI_filled_area  *)NULL,
/* high light filler of cascade menu */
(UI_filled_area  *)NULL,
/* left arrow image of cascade submenu */
NULL,
/* right arrow image of cascade submenu */
NULL,
/* selected image for check */
NULL,
/* unselected image for check */
NULL,
/* selected image for radio */
NULL,
/* unselected image for radio */
NULL,
/* left arrow image in inline edit */
NULL,
/* right arrow image in inline edit */
NULL,
/* color of base line in inputbox */
(color *)&inputbox_base_line_color_defaultTheme,
/* color of control character base line in ems */
(color *)&inputbox_ems_cr_base_line_color_defaultTheme,
/* text color in dialer inputbox */
(color *)&dialer_inputbox_text_color_defaultTheme,
/* border color in dialer inputbox */
(color *)&dialer_inputbox_text_border_color_defaultTheme,
/* back ground filler for dialer inputbox for touch screen */
(UI_filled_area  *)&dialer_inputbox_touch_background_filler_defaultTheme,
/* down filler of left key*/
(UI_filled_area  *)NULL,
/* up filler of left key*/
(UI_filled_area  *)NULL,
/* down filler of right key*/
(UI_filled_area  *)NULL,
/* up filler of right key*/
(UI_filled_area  *)NULL
};

const MMI_theme theme_1Theme={
(UI_filled_area*)&multitap_filler_1Theme,
(UI_filled_area*)&inputbox_filler_1Theme,
(UI_filled_area*)&scrollbar_background_filler_1Theme,
(UI_filled_area*)&scrollbar_indicator_filler_1Theme,
(UI_filled_area*)&title_filler_1Theme,
(UI_filled_area*)&list_background_filler_1Theme,
(UI_filled_area*)&list_normal_item_filler_1Theme,
(UI_filled_area*)&list_selected_item_filler_1Theme,
(UI_filled_area*)&list_disabled_item_filler_1Theme,
(UI_filled_area*)&matrix_background_filler_1Theme,
(UI_filled_area*)&matrix_normal_item_filler_1Theme,
(UI_filled_area*)&matrix_selected_item_filler_1Theme,
(UI_filled_area*)&matrix_disabled_item_filler_1Theme,
(UI_filled_area*)&formatted_inputbox_normal_filler_1Theme,
(UI_filled_area*)&formatted_inputbox_selected_filler_1Theme,
(UI_filled_area*)&main_menu_background_filler_1Theme,
(UI_filled_area*)&list_main_menu_normal_item_filler_1Theme,
(UI_filled_area*)&list_main_menu_selected_item_filler_1Theme,
(UI_filled_area*)&list_main_menu_disabled_item_filler_1Theme,
(UI_filled_area*)&matrix_main_menu_normal_item_filler_1Theme,
(UI_filled_area*)&matrix_main_menu_selected_item_filler_1Theme,
(UI_filled_area*)&matrix_main_menu_disabled_item_filler_1Theme,
(UI_filled_area*)&general_background_filler_1Theme,
(UI_filled_area*)&popup_description_background_filler_1Theme,
(UI_filled_area*)&inline_list_background_filler_1Theme,
(UI_filled_area*)&inline_list_normal_item_filler_1Theme,
(UI_filled_area*)&inline_list_selected_item_filler_1Theme,
(UI_filled_area*)&inline_list_disabled_item_filler_1Theme,
(UI_filled_area*)&inline_edit_focussed_filler_1Theme,
(UI_filled_area*)&inline_edit_unfocussed_filler_1Theme,
(UI_filled_area*)&inline_edit_noboundary_filler_1Theme,
(UI_filled_area*)&PIN_inputbox_background_filler_1Theme,
(UI_filled_area*)&PIN_screen_background_filler_1Theme,
(UI_filled_area*)&network_screen_background_filler_1Theme,
(UI_filled_area*)&aphorism_screen_background_filler_1Theme,
(UI_filled_area*)&CM_screen_background_filler_1Theme,
(UI_filled_area*)&Progress_screen_background_filler_1Theme,
(UI_filled_area*)&dialer_inputbox_background_filler_1Theme,
(UI_filled_area*)&virtual_keyboard_key_down_filler_1Theme,
(UI_filled_area*)&alarm_filler_1Theme,
(UI_filled_area*)&small_list_menu_normal_filler_1Theme,
(UI_filled_area*)&small_list_screen_border_filler_1Theme,
(color*)&UI_black_color_1Theme,
(color*)&UI_white_color_1Theme,
(color*)&lite_disp_scr_bg_color_1Theme,
(color*)&LSK_up_text_color_1Theme,
(color*)&LSK_down_text_color_1Theme,
(color*)&LSK_disabled_text_color_1Theme,
(color*)&RSK_up_text_color_1Theme,
(color*)&RSK_down_text_color_1Theme,
(color*)&RSK_disabled_text_color_1Theme,
(color*)&multitap_selector_color_1Theme,
(color*)&multitap_normal_text_color_1Theme,
(color*)&multitap_selected_text_color_1Theme,
(color*)&inputbox_normal_text_color_1Theme,
(color*)&inputbox_selected_text_color_1Theme,
(color*)&inputbox_selector_color_1Theme,
(color*)&inputbox_cursor_color_1Theme,
(color*)&title_text_color_1Theme,
(color*)&title_text_border_color_1Theme,
(color*)&title_shortcut_text_color_1Theme,
(color*)&list_normal_text_color_1Theme,
(color*)&list_selected_text_color_1Theme,
(color*)&list_disabled_text_color_1Theme,
(color*)&matrix_normal_text_color_1Theme,
(color*)&matrix_selected_text_color_1Theme,
(color*)&matrix_disabled_text_color_1Theme,
(color*)&menubar_index_background_color_1Theme,
(color*)&menubar_item_background_color_1Theme,
(color*)&menubar_index_text_color_1Theme,
(color*)&menubar_item_text_color_1Theme,
(color*)&drop_down_normal_text_color_1Theme,
(color*)&drop_down_disabled_text_color_1Theme,
(color*)&drop_down_focussed_text_color_1Theme,
(color*)&formatted_inputbox_selector_color_1Theme,
(color*)&formatted_inputbox_normal_text_color_1Theme,
(color*)&formatted_inputbox_disabled_text_color_1Theme,
(color*)&formatted_inputbox_selected_text_color_1Theme,
(color*)&formatted_inputbox_cursor_color_1Theme,
(color*)&list_main_menu_normal_text_color_1Theme,
(color*)&list_main_menu_selected_text_color_1Theme,
(color*)&list_main_menu_disabled_text_color_1Theme,
(color*)&matrix_main_menu_normal_text_color_1Theme,
(color*)&matrix_main_menu_selected_text_color_1Theme,
(color*)&matrix_main_menu_disabled_text_color_1Theme,
(color*)&circular_main_menu_normal_text_color_1Theme,
(color*)&circular_main_menu_selected_text_color_1Theme,
(color*)&circular_main_menu_disabled_text_color_1Theme,
(color*)&popup_screen_background_color_1Theme,
(color*)&popup_screen_border_color_1Theme,
(color*)&popup_description_text_color_1Theme,
(color*)&CM_screen_text_color_1Theme,
(color*)&datetime_bar_background_color_1Theme,
(color*)&datetime_bar_duration_background_color_1Theme,
(color*)&datetime_bar_date_text_color_1Theme,
(color*)&datetime_bar_time_text_color_1Theme,
(color*)&datetime_bar_duration_text_color_1Theme,
(color*)&datetime_bar_AOC_text_color_1Theme,
(color*)&information_bar_color_1Theme,
(color*)&input_method_text_color_1Theme,
(color*)&remaining_length_text_color_1Theme,
(color*)&inline_edit_focussed_text_color_1Theme,
(color*)&inline_edit_unfocussed_text_color_1Theme,
(color*)&inline_edit_selected_text_color_1Theme,
(color*)&inline_edit_selector_color_1Theme,
(color*)&inline_edit_cursor_color_1Theme,
(color*)&inline_list_normal_text_color_1Theme,
(color*)&inline_list_selected_text_color_1Theme,
(color*)&inline_list_disabled_text_color_1Theme,
(color*)&PIN_inputbox_normal_text_color_1Theme,
(color*)&PIN_inputbox_selected_text_color_1Theme,
(color*)&PIN_inputbox_selector_color_1Theme,
(color*)&PIN_inputbox_cursor_color_1Theme,
(color*)&dialer_inputbox_normal_text_color_1Theme,
(color*)&dialer_inputbox_selected_text_color_1Theme,
(color*)&dialer_inputbox_selector_color_1Theme,
(color*)&dialer_inputbox_cursor_color_1Theme,
(color*)&virtual_keyboard_key_down_text_color_1Theme,
(color*)&virtual_keyboard_key_up_text_color_1Theme,
(color*)&virtual_keyboard_dead_key_down_text_color_1Theme,
(color*)&virtual_keyboard_dead_key_up_text_color_1Theme,
(color*)&virtual_keyboard_disp_area_text_color_1Theme,
(color*)&calculator_text_color_1Theme,
(color*)&alarm_text_color_1Theme,
(color*)&idle_scr_date_color_1Theme,
(color*)&idle_scr_time_color_1Theme,
(color*)&idle_scr_date_border_color_1Theme,
(color*)&idle_scr_time_border_color_1Theme,
(color*)&idle_scr_network_name_color_1Theme,
(color*)&idle_scr_network_name_border_color_1Theme,
(color*)&idle_scr_network_status_color_1Theme,
(color*)&idle_scr_network_status_border_color_1Theme,
(color*)&idle_scr_network_extra_color_1Theme,
(color*)&idle_scr_network_extra_border_color_1Theme,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_medium_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
255,
120,
120,
120,

#if (UI_SCROLLBAR_WIDTH == 14)
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_160x22_filler_1Theme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_160x44_filler_1Theme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_1Theme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_1Theme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_160x35_filler_1Theme,
#else /* UI_SCROLLBAR_STYLE_3 */
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_166x22_filler_1Theme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_166x44_filler_1Theme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_1Theme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_1Theme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_166x35_filler_1Theme,
#endif /* UI_SCROLLBAR_STYLE_3 */

/* symbol_picker_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_1Theme,
/* matrix_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_1Theme,
/* main_menu_bkg_image */
(UI_filled_area*)&main_menu_bkg_filler_defaultTheme_2,
/* sub_menu_bkg_image */
(UI_filled_area*)&sub_menu_bkg_filler_defaultTheme_2,
/* idle_bkg_image */
(UI_filled_area*)&idle_menu_bkg_filler_defaultTheme_2,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&UI_black_color_1Theme,
/* idle_scr_weekday_color */
(color*)&idle_weekday_text_color_1Theme,
/* idle_scr_weekday_border_color */
(color*)&idle_weekday_text_border_color_1Theme,
/* date_text_font */
&MMI_large_font,
/* time_text_font */
&MMI_large_font,
/* date_text_color */
(color*)&clock_date_text_color_1Theme,
/* date_text_border_color */
(color*)&clock_date_text_border_color_1Theme,
/* time_text_color */
(color*)&clock_time_text_color_1Theme,
/* time_text_border_color */
(color*)&clock_time_text_border_color_1Theme,
/* date_text_font_sub_lcd */
&MMI_small_font,
/* time_text_font_sub_lcd */
&MMI_small_font,
/* date_text_color_sub_lcd */
(color*)&clock_date_text_color_sublcd_wallpaper_1Theme,
/* date_text_border_color_sub_lcd */
(color*)&clock_date_text_border_color_sublcd_wallpaper_1Theme,
/* time_text_color_sub_lcd */
(color*)&clock_time_text_color_sublcd_wallpaper_1Theme,
/* time_text_border_color_sub_lcd */
(color*)&clock_time_text_border_color_sublcd_wallpaper_1Theme,
/* analog_hand_hour_color */
(color*)&clock_analog_hand_hour_1Theme,
/* analog_hand_min_color */
(color*)&clock_analog_hand_min_1Theme,
/* analog_axis_color */
(color*)&clock_analog_axis_1Theme,
/* softkey_text_border_color */
(color*)&softkey_text_border_1Theme,
/* softkey_bar_bkg_image */
NULL,
/* tab_title_filler */
(UI_filled_area*)&tab_title_filler_1Theme,
/* tab_title_text_color */
(color*)&title_text_color_1Theme,
/* tab_title_text_border_color */
(color*)&title_text_border_color_1Theme,
/* tab_title_shortcut_text_color */
(color*)&title_shortcut_text_color_1Theme,
/* tab_title_text_font */
&MMI_medium_font,
/* ime_underline_color */
(color*)&ime_underline_color_1Theme,
/* ime_indicator_color */
(color*)&ime_indicator_color_1Theme,
/* ime_focused_background_color */
(color*)&ime_focused_background_color_1Theme,
/* ime_background_color */
(color*)&ime_background_color_1Theme,
/* ime_focused_border_color */
(color*)&ime_focused_border_color_1Theme,
/* ime_border_color */
(color*)&ime_border_color_1Theme,
/* ime_text_color */
(color*)&ime_text_color_1Theme,
/* ime_lable_color */
(color*)&ime_lable_color_1Theme,
/* ime_hilite_color */
(color*)&ime_hilite_color_1Theme,
/* ime_hilite_text_color */
(color*)&ime_hilite_text_color_1Theme,
/* ime_cursor_color */
(color*)&ime_cursor_color_1Theme,
/* ime_arrow_color */
(color*)&ime_arrow_color_1Theme,
/* ime_text_font */
&MMI_medium_font,
/* ime_lable_font */
&MMI_small_font,
/* inline_list_default_text_item_filler */
NULL,
/* calendar_title_fg_color */
(color*)&calendar_title_fg_1Theme,
/* calendar_horizontal_fg_color */
(color*)&calendar_horizontal_select_fg_1Theme,
/* calendar_horizontal_border_color */
(color*)&calendar_horizontal_select_border_1Theme,
/* calendar_vertical_fg_color */
(color*)&calendar_vertical_select_fg_1Theme,
/* calendar_horizontal_string_fg_color */
(color*)&calendar_horizontal_string_fg_1Theme,
/* calendar_current_color */
(color*)&calendar_cell_current_1Theme,
/* calendar_one_task_color */
(color*)&calendar_cell_one_task_1Theme,
/* calendar_more_task_color */
(color*)&calendar_cell_more_task_1Theme,
/* calendar_menstrual_color */
(color*)&calendar_cell_menstrual_1Theme,
/* calendar_PP_color */
(color*)&calendar_cell_PP_1Theme,
/* calendar_danger_color */
(color*)&calendar_cell_danger_1Theme,
/* calendar_invalid_color */
(color*)&calendar_cell_invalid_1Theme,  
/* calendar_valid_fg_color */
(color*)&calendar_valid_fg_1Theme,
/* calendar_invalid_fg_color */
(color*)&calendar_invalid_fg_1Theme,
/* calendar_highlight_color */
(color*)&calendar_highlight_1Theme,    
/* calendar_infobox_bg_color */
(color*)&calendar_infobox_bg_1Theme,
/* calendar_infobox_entry_bg_color */
(color*)&calendar_infobox_entry_bg_1Theme,
/* calendar_infobox_fg_color */
(color*)&calendar_infobox_fg_1Theme,
/* calendar_infobox_font */
&MMI_small_font,
/* calendar_horizontal_string_font */
&MMI_small_font,
/* calendar_cell_font */
&MMI_small_font,
/* status icon bar filler*/
(UI_filled_area*)&status_icon_bar_filler_1Theme,
/* thick title filler*/
(UI_filled_area*)&title_filler_1Theme,
/* thick title text color */
(color*)&title_text_color_1Theme,
/* thick title text border color */
(color*)&title_text_border_color_1Theme,
/* thick title shortcut color */
(color*)&title_shortcut_text_color_1Theme,
/* main menu icon 1 */
NULL,
/* main menu icon 2 */
NULL,
/* main menu icon 3 */
NULL,
/* main menu icon 4 */
NULL,
/* main menu icon 5 */
NULL,
/* main menu icon 6 */
NULL,
/* main menu icon 7 */
NULL,
/* main menu icon 8 */
NULL,
/* main menu icon 9 */
NULL,
/* main menu icon 10 */
NULL,
/* main menu icon 11 */
NULL,
/* main menu icon 12 */
NULL,
/* main menu icon 13 */
NULL,
/* main menu icon 14 */
NULL,
/* main menu icon 15 */
NULL,
/* back ground filler of rotate screen*/
(UI_filled_area  *)NULL,
/* back ground image of rotate popup screen */
NULL,
/* filler of title in rotate screen */
(UI_filled_area  *)NULL,
/* filler of title in small screen */
(UI_filled_area*)&small_title_filler_Theme,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_highlight_filler_1Theme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */

/* high light image of matrix main menu */
(PU8)matrix_main_menu_highlight_image_1Theme,

/* background filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_background_filler_1Theme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */

/* separator color in list menu */
(color *)NULL,
/* separator color of cascade menu */
(color *)NULL,
/* normal text color of cascade menu */
(color *)NULL,
/* selected text color of cascade menu */
(color *)NULL,
/* disabled text color of cascade menu */
(color *)NULL,
/* border color of cascade menu */
(color *)NULL,
/* back ground filler of cascade menu */
(UI_filled_area  *)NULL,
/* high light filler of cascade menu */
(UI_filled_area  *)NULL,
/* left arrow image of cascade submenu */
NULL,
/* right arrow image of cascade submenu */
NULL,
/* selected image for check */
NULL,
/* unselected image for check */
NULL,
/* selected image for radio */
NULL,
/* unselected image for radio */
NULL,
/* left arrow image in inline edit */
NULL,
/* right arrow image in inline edit */
NULL,
/* color of base line in inputbox */
(color *)&inputbox_base_line_color_1Theme,
/* color of control character base line in ems */
(color *)&inputbox_ems_cr_base_line_color_1Theme,
/* text color in dialer inputbox */
(color *)&dialer_inputbox_text_color_1Theme,
/* border color in dialer inputbox */
(color *)&dialer_inputbox_text_border_color_1Theme,
/* back ground filler for dialer inputbox for touch screen */
(UI_filled_area  *)&dialer_inputbox_touch_background_filler_1Theme,
/* down filler of left key*/
(UI_filled_area  *)NULL,
/* up filler of left key*/
(UI_filled_area  *)NULL,
/* down filler of right key*/
(UI_filled_area  *)NULL,
/* up filler of right key*/
(UI_filled_area  *)NULL
};

const MMI_theme theme_2Theme={
(UI_filled_area*)&multitap_filler_2Theme,
(UI_filled_area*)&inputbox_filler_2Theme,
(UI_filled_area*)&scrollbar_background_filler_2Theme,
(UI_filled_area*)&scrollbar_indicator_filler_2Theme,
(UI_filled_area*)&title_filler_2Theme,
(UI_filled_area*)&list_background_filler_2Theme,
(UI_filled_area*)&list_normal_item_filler_2Theme,
(UI_filled_area*)&list_selected_item_filler_2Theme,
(UI_filled_area*)&list_disabled_item_filler_2Theme,
(UI_filled_area*)&matrix_background_filler_2Theme,
(UI_filled_area*)&matrix_normal_item_filler_2Theme,
(UI_filled_area*)&matrix_selected_item_filler_2Theme,
(UI_filled_area*)&matrix_disabled_item_filler_2Theme,
(UI_filled_area*)&formatted_inputbox_normal_filler_2Theme,
(UI_filled_area*)&formatted_inputbox_selected_filler_2Theme,
(UI_filled_area*)&main_menu_background_filler_2Theme,
(UI_filled_area*)&list_main_menu_normal_item_filler_2Theme,
(UI_filled_area*)&list_main_menu_selected_item_filler_2Theme,
(UI_filled_area*)&list_main_menu_disabled_item_filler_2Theme,
(UI_filled_area*)&matrix_main_menu_normal_item_filler_2Theme,
(UI_filled_area*)&matrix_main_menu_selected_item_filler_2Theme,
(UI_filled_area*)&matrix_main_menu_disabled_item_filler_2Theme,
(UI_filled_area*)&general_background_filler_2Theme,
(UI_filled_area*)&popup_description_background_filler_2Theme,
(UI_filled_area*)&inline_list_background_filler_2Theme,
(UI_filled_area*)&inline_list_normal_item_filler_2Theme,
(UI_filled_area*)&inline_list_selected_item_filler_2Theme,
(UI_filled_area*)&inline_list_disabled_item_filler_2Theme,
(UI_filled_area*)&inline_edit_focussed_filler_2Theme,
(UI_filled_area*)&inline_edit_unfocussed_filler_2Theme,
(UI_filled_area*)&inline_edit_noboundary_filler_2Theme,
(UI_filled_area*)&PIN_inputbox_background_filler_2Theme,
(UI_filled_area*)&PIN_screen_background_filler_2Theme,
(UI_filled_area*)&network_screen_background_filler_2Theme,
(UI_filled_area*)&aphorism_screen_background_filler_2Theme,
(UI_filled_area*)&CM_screen_background_filler_2Theme,
(UI_filled_area*)&Progress_screen_background_filler_2Theme,
(UI_filled_area*)&dialer_inputbox_background_filler_2Theme,
(UI_filled_area*)&virtual_keyboard_key_down_filler_2Theme,
(UI_filled_area*)&alarm_filler_2Theme,
(UI_filled_area*)&small_list_menu_normal_filler_2Theme,
(UI_filled_area*)&small_list_screen_border_filler_2Theme,
(color*)&UI_black_color_2Theme,
(color*)&UI_white_color_2Theme,
(color*)&lite_disp_scr_bg_color_2Theme,
(color*)&LSK_up_text_color_2Theme,
(color*)&LSK_down_text_color_2Theme,
(color*)&LSK_disabled_text_color_2Theme,
(color*)&RSK_up_text_color_2Theme,
(color*)&RSK_down_text_color_2Theme,
(color*)&RSK_disabled_text_color_2Theme,
(color*)&multitap_selector_color_2Theme,
(color*)&multitap_normal_text_color_2Theme,
(color*)&multitap_selected_text_color_2Theme,
(color*)&inputbox_normal_text_color_2Theme,
(color*)&inputbox_selected_text_color_2Theme,
(color*)&inputbox_selector_color_2Theme,
(color*)&inputbox_cursor_color_2Theme,
(color*)&title_text_color_2Theme,
(color*)&title_text_border_color_2Theme,
(color*)&title_shortcut_text_color_2Theme,
(color*)&list_normal_text_color_2Theme,
(color*)&list_selected_text_color_2Theme,
(color*)&list_disabled_text_color_2Theme,
(color*)&matrix_normal_text_color_2Theme,
(color*)&matrix_selected_text_color_2Theme,
(color*)&matrix_disabled_text_color_2Theme,
(color*)&menubar_index_background_color_2Theme,
(color*)&menubar_item_background_color_2Theme,
(color*)&menubar_index_text_color_2Theme,
(color*)&menubar_item_text_color_2Theme,
(color*)&drop_down_normal_text_color_2Theme,
(color*)&drop_down_disabled_text_color_2Theme,
(color*)&drop_down_focussed_text_color_2Theme,
(color*)&formatted_inputbox_selector_color_2Theme,
(color*)&formatted_inputbox_normal_text_color_2Theme,
(color*)&formatted_inputbox_disabled_text_color_2Theme,
(color*)&formatted_inputbox_selected_text_color_2Theme,
(color*)&formatted_inputbox_cursor_color_2Theme,
(color*)&list_main_menu_normal_text_color_2Theme,
(color*)&list_main_menu_selected_text_color_2Theme,
(color*)&list_main_menu_disabled_text_color_2Theme,
(color*)&matrix_main_menu_normal_text_color_2Theme,
(color*)&matrix_main_menu_selected_text_color_2Theme,
(color*)&matrix_main_menu_disabled_text_color_2Theme,
(color*)&circular_main_menu_normal_text_color_2Theme,
(color*)&circular_main_menu_selected_text_color_2Theme,
(color*)&circular_main_menu_disabled_text_color_2Theme,
(color*)&popup_screen_background_color_2Theme,
(color*)&popup_screen_border_color_2Theme,
(color*)&popup_description_text_color_2Theme,
(color*)&CM_screen_text_color_2Theme,
(color*)&datetime_bar_background_color_2Theme,
(color*)&datetime_bar_duration_background_color_2Theme,
(color*)&datetime_bar_date_text_color_2Theme,
(color*)&datetime_bar_time_text_color_2Theme,
(color*)&datetime_bar_duration_text_color_2Theme,
(color*)&datetime_bar_AOC_text_color_2Theme,
(color*)&information_bar_color_2Theme,
(color*)&input_method_text_color_2Theme,
(color*)&remaining_length_text_color_2Theme,
(color*)&inline_edit_focussed_text_color_2Theme,
(color*)&inline_edit_unfocussed_text_color_2Theme,
(color*)&inline_edit_selected_text_color_2Theme,
(color*)&inline_edit_selector_color_2Theme,
(color*)&inline_edit_cursor_color_2Theme,
(color*)&inline_list_normal_text_color_2Theme,
(color*)&inline_list_selected_text_color_2Theme,
(color*)&inline_list_disabled_text_color_2Theme,
(color*)&PIN_inputbox_normal_text_color_2Theme,
(color*)&PIN_inputbox_selected_text_color_2Theme,
(color*)&PIN_inputbox_selector_color_2Theme,
(color*)&PIN_inputbox_cursor_color_2Theme,
(color*)&dialer_inputbox_normal_text_color_2Theme,
(color*)&dialer_inputbox_selected_text_color_2Theme,
(color*)&dialer_inputbox_selector_color_2Theme,
(color*)&dialer_inputbox_cursor_color_2Theme,
(color*)&virtual_keyboard_key_down_text_color_2Theme,
(color*)&virtual_keyboard_key_up_text_color_2Theme,
(color*)&virtual_keyboard_dead_key_down_text_color_2Theme,
(color*)&virtual_keyboard_dead_key_up_text_color_2Theme,
(color*)&virtual_keyboard_disp_area_text_color_2Theme,
(color*)&calculator_text_color_2Theme,
(color*)&alarm_text_color_2Theme,
(color*)&idle_scr_date_color_2Theme,
(color*)&idle_scr_time_color_2Theme,
(color*)&idle_scr_date_border_color_2Theme,
(color*)&idle_scr_time_border_color_2Theme,
(color*)&idle_scr_network_name_color_2Theme,
(color*)&idle_scr_network_name_border_color_2Theme,
(color*)&idle_scr_network_status_color_2Theme,
(color*)&idle_scr_network_status_border_color_2Theme,
(color*)&idle_scr_network_extra_color_2Theme,
(color*)&idle_scr_network_extra_border_color_2Theme,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_medium_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_medium_font,
&MMI_default_font,
&MMI_default_font,
&MMI_default_font,
&MMI_medium_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
255,
150,
150,
150,

#if (UI_SCROLLBAR_WIDTH == 14)
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_160x22_filler_2Theme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_160x44_filler_2Theme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_2Theme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_160x39_filler_2Theme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_160x35_filler_2Theme,
#else /* UI_SCROLLBAR_STYLE_3 */
/* menuitem_single_line_highlight_filler */
(UI_filled_area*)&menu_item_166x22_filler_2Theme,
/* menuitem_two_line_highlight_filler */
(UI_filled_area*)&menu_item_166x44_filler_2Theme,
/* menuitem_multirow_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_2Theme,
/* menuitem_thick_highlight_filler */
(UI_filled_area*)&menu_item_166x39_filler_2Theme,
/* menuitem_thick_with_tab_highlight_filler */
(UI_filled_area*)&menu_item_166x35_filler_2Theme,
#endif /* UI_SCROLLBAR_STYLE_3 */

/* symbol_picker_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_2Theme,
/* matrix_highlight_filler */
(UI_filled_area*)&list_selected_item_filler_2Theme,
/* main_menu_bkg_image */
(UI_filled_area*)&main_menu_bkg_filler_defaultTheme_3,
/* sub_menu_bkg_image */
(UI_filled_area*)&sub_menu_bkg_filler_defaultTheme_3,
/* idle_bkg_image */
(UI_filled_area*)&idle_menu_bkg_filler_defaultTheme_3,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&UI_black_color_2Theme,
/* idle_scr_weekday_color */
(color*)&idle_weekday_text_color_2Theme,
/* idle_scr_weekday_border_color */
(color*)&idle_weekday_text_border_color_2Theme,
/* date_text_font */
&MMI_large_font,
/* time_text_font */
&MMI_large_font,
/* date_text_color */
(color*)&clock_date_text_color_2Theme,
/* date_text_border_color */
(color*)&clock_date_text_border_color_2Theme,
/* time_text_color */
(color*)&clock_time_text_color_2Theme,
/* time_text_border_color */
(color*)&clock_time_text_border_color_2Theme,
/* date_text_font_sub_lcd */
&MMI_small_font,
/* time_text_font_sub_lcd */
&MMI_small_font,
/* date_text_color_sub_lcd */
(color*)&clock_date_text_color_sublcd_wallpaper_2Theme,
/* date_text_border_color_sub_lcd */
(color*)&clock_date_text_border_color_sublcd_wallpaper_2Theme,
/* time_text_color_sub_lcd */
(color*)&clock_time_text_color_sublcd_wallpaper_2Theme,
/* time_text_border_color_sub_lcd */
(color*)&clock_time_text_border_color_sublcd_wallpaper_2Theme,
/* analog_hand_hour_color */
(color*)&clock_analog_hand_hour_2Theme,
/* analog_hand_min_color */
(color*)&clock_analog_hand_min_2Theme,
/* analog_axis_color */
(color*)&clock_analog_axis_2Theme,
/* softkey_text_border_color */
(color*)&softkey_text_border_2Theme,
/* softkey_bar_bkg_image */
NULL,
/* tab_title_filler */
(UI_filled_area*)&tab_title_filler_2Theme,
/* tab_title_text_color */
(color*)&title_text_color_2Theme,
/* tab_title_text_border_color */
(color*)&title_text_border_color_2Theme,
/* tab_title_shortcut_text_color */
(color*)&title_shortcut_text_color_2Theme,
/* tab_title_text_font */
&MMI_medium_font,
/* ime_underline_color */
(color*)&ime_underline_color_2Theme,
/* ime_indicator_color */
(color*)&ime_indicator_color_2Theme,
/* ime_focused_background_color */
(color*)&ime_focused_background_color_2Theme,
/* ime_background_color */
(color*)&ime_background_color_2Theme,
/* ime_focused_border_color */
(color*)&ime_focused_border_color_2Theme,
/* ime_border_color */
(color*)&ime_border_color_2Theme,
/* ime_text_color */
(color*)&ime_text_color_2Theme,
/* ime_lable_color */
(color*)&ime_lable_color_2Theme,
/* ime_hilite_color */
(color*)&ime_hilite_color_2Theme,
/* ime_hilite_text_color */
(color*)&ime_hilite_text_color_2Theme,
/* ime_cursor_color */
(color*)&ime_cursor_color_2Theme,
/* ime_arrow_color */
(color*)&ime_arrow_color_2Theme,
/* ime_text_font */
&MMI_medium_font,
/* ime_lable_font */
&MMI_small_font,
/* inline_list_default_text_item_filler */
NULL,
/* calendar_title_fg_color */
(color*)&calendar_title_fg_2Theme,
/* calendar_horizontal_fg_color */
(color*)&calendar_horizontal_select_fg_2Theme,
/* calendar_horizontal_border_color */
(color*)&calendar_horizontal_select_border_2Theme,
/* calendar_vertical_fg_color */
(color*)&calendar_vertical_select_fg_2Theme,
/* calendar_horizontal_string_fg_color */
(color*)&calendar_horizontal_string_fg_2Theme,
/* calendar_current_color */
(color*)&calendar_cell_current_2Theme,
/* calendar_one_task_color */
(color*)&calendar_cell_one_task_2Theme,
/* calendar_more_task_color */
(color*)&calendar_cell_more_task_2Theme,
/* calendar_menstrual_color */
(color*)&calendar_cell_menstrual_2Theme,
/* calendar_PP_color */
(color*)&calendar_cell_PP_2Theme,
/* calendar_danger_color */
(color*)&calendar_cell_danger_2Theme,
/* calendar_invalid_color */
(color*)&calendar_cell_invalid_2Theme,  
/* calendar_valid_fg_color */
(color*)&calendar_valid_fg_2Theme,
/* calendar_invalid_fg_color */
(color*)&calendar_invalid_fg_2Theme,
/* calendar_highlight_color */
(color*)&calendar_highlight_2Theme,    
/* calendar_infobox_bg_color */
(color*)&calendar_infobox_bg_2Theme,
/* calendar_infobox_entry_bg_color */
(color*)&calendar_infobox_entry_bg_2Theme,
/* calendar_infobox_fg_color */
(color*)&calendar_infobox_fg_2Theme,
/* calendar_infobox_font */
&MMI_small_font,
/* calendar_horizontal_string_font */
&MMI_small_font,
/* calendar_cell_font */
&MMI_small_font,
/* status icon bar filler*/
(UI_filled_area*)&status_icon_bar_filler_2Theme,
/* thick title filler*/
(UI_filled_area*)&title_filler_2Theme,
/* thick title text color */
(color*)&title_text_color_2Theme,
/* thick title text border color */
(color*)&title_text_border_color_2Theme,
/* thick title shortcut color */
(color*)&title_shortcut_text_color_2Theme,
/* main menu icon 1 */
NULL,
/* main menu icon 2 */
NULL,
/* main menu icon 3 */
NULL,
/* main menu icon 4 */
NULL,
/* main menu icon 5 */
NULL,
/* main menu icon 6 */
NULL,
/* main menu icon 7 */
NULL,
/* main menu icon 8 */
NULL,
/* main menu icon 9 */
NULL,
/* main menu icon 10 */
NULL,
/* main menu icon 11 */
NULL,
/* main menu icon 12 */
NULL,
/* main menu icon 13 */
NULL,
/* main menu icon 14 */
NULL,
/* main menu icon 15 */
NULL,
/* back ground filler of rotate screen*/
(UI_filled_area  *)NULL,
/* back ground image of rotate popup screen */
NULL,
/* filler of title in rotate screen */
(UI_filled_area  *)NULL,
/* filler of title in small screen */
(UI_filled_area*)&small_title_filler_Theme,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_highlight_filler_2Theme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */

/* high light image of matrix main menu */
(PU8)matrix_main_menu_highlight_image_2Theme,

/* background filler of bidegree main menu */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
(UI_filled_area  *)&main_menu_bidegree_tab_background_filler_2Theme,
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
(UI_filled_area  *)NULL,  
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */

/* separator color in list menu*/
(color *)NULL,
/* separator color of cascade menu */
(color *)NULL,
/* normal text color of cascade menu */
(color *)NULL,
/* selected text color of cascade menu */
(color *)NULL,
/* disabled text color of cascade menu */
(color *)NULL,
/* border color of cascade menu */
(color *)NULL,
/* back ground filler of cascade menu */
(UI_filled_area  *)NULL,
/* high light filler of cascade menu */
(UI_filled_area  *)NULL,
/* left arrow image of cascade submenu */
NULL,
/* right arrow image of cascade submenu */
NULL,
/* selected image for check */
NULL,
/* unselected image for check */
NULL,
/* selected image for radio */
NULL,
/* unselected image for radio */
NULL,
/* left arrow image in inline edit */
NULL,
/* right arrow image in inline edit */
NULL,
/* color of base line in inputbox */
(color *)&inputbox_base_line_color_2Theme,
/* color of control character base line in ems */
(color *)&inputbox_ems_cr_base_line_color_2Theme,
/* text color in dialer inputbox */
(color *)&dialer_inputbox_text_color_2Theme,
/* border color in dialer inputbox */
(color *)&dialer_inputbox_text_border_color_2Theme,
/* back ground filler for dialer inputbox for touch screen */
(UI_filled_area  *)&dialer_inputbox_touch_background_filler_2Theme,
/* down filler of left key*/
(UI_filled_area  *)NULL,
/* up filler of left key*/
(UI_filled_area  *)NULL,
/* down filler of right key*/
(UI_filled_area  *)NULL,
/* up filler of right key*/
(UI_filled_area  *)NULL
};

#ifndef __MMI_THEMES_V2_SUPPORT__

const MMI_theme *mtk_MMI_themes[MAX_MMI_THEMES]={
(MMI_theme *)&theme_defaultTheme,
(MMI_theme *)&theme_1Theme,
(MMI_theme *)&theme_2Theme
};

#else

const theme_details_struct mtk_MMI_themes[MAX_MMI_THEMES]={
{
(MMI_theme *)&theme_defaultTheme,
NULL,
NULL
},
{
(MMI_theme *)&theme_1Theme,
NULL,
NULL
},
{
(MMI_theme *)&theme_2Theme,
NULL,
NULL
}
};
#endif

U8* MMI_theme_names[MAX_MMI_THEMES]={
NULL,
NULL,
NULL
};

const char theme_phone_model[]="SAPPHIRE28_DEMO_HW";

