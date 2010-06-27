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
#include "PixtelDatatypes.h"
#include "MMI_features.h"
#include "gui_themes.h"
#include "ThemeComponents.h"

#define MAX_MMI_THEMES 3


S32 mtk_n_MMI_themes=MAX_MMI_THEMES;

const MMI_theme theme_1={
(UI_filled_area*)&mtab_1,
(UI_filled_area*)&ibox_1,
(UI_filled_area*)&sbar_bkgrnd_1,
(UI_filled_area*)&sbar_indicator_1,
(UI_filled_area*)&Title_1,
(UI_filled_area*)&list_bkgrnd_1,
(UI_filled_area*)&list_normal_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_bkgrnd_1,
(UI_filled_area*)&matrix_normal_item_1,
(UI_filled_area*)&matrix_selected_item_1,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&fibox_normal_1,
(UI_filled_area*)&fibox_selected_1,
(UI_filled_area*)&mm_bkgrnd_1,
(UI_filled_area*)&list_normal_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_normal_item_1,
(UI_filled_area*)&matrix_selected_item_1,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&popup_description_bkgrnd_1,
(UI_filled_area*)&list_bkgrnd_1,
(UI_filled_area*)&list_normal_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&Unused,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&dial_inputbox_bg_filler,
(UI_filled_area*)&virtual_keyboard_down_bkgrnd_1,
(UI_filled_area*)&alarm_background_filler1,
(UI_filled_area*)&small_list_menu_normal_filler1,
(UI_filled_area*)&small_list_screen_border_filler1,
(color*)&black_color,
(color*)&white_color,
(color*)&lite_disp_scr_bg_col_1,
(color*)&LSK_up_txt_col_1,
(color*)&LSK_down_txt_col_1,
(color*)&Disabled_text_col,
(color*)&RSK_up_txt_col_1,
(color*)&RSK_down_txt_col_1,
(color*)&Disabled_text_col,
(color*)&mtab_selector_txt_col_1,
(color*)&mtab_normal_txt_col_1,
(color*)&mtab_selected_txt_col_1,
(color*)&ibox_normal_txt_col_1,
(color*)&ibox_selected_txt_col_1,
(color*)&ibox_selector_col_1,
(color*)&ibox_cursor_col_1,
(color*)&title_scut_txt_col_1,
(color*)&white_color,
(color*)&title_scut_txt_col_1,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&ibox_selector_col_1,
(color*)&ibox_normal_txt_col_1,
(color*)&Disabled_text_col,
(color*)&ibox_selected_txt_col_1,
(color*)&ibox_cursor_col_1,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&white_color,
(color*)&black_color,
(color*)&popup_description_txt_col_1,
(color*)&CM_screen_text_color_1,
(color*)&white_color,
(color*)&white_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&information_bar_col_1,
(color*)&input_method_txt_col_1,
(color*)&input_method_txt_col_1,
(color*)&black_color,
(color*)&ibox_normal_txt_col_1,
(color*)&ibox_selected_txt_col_1,
(color*)&ibox_selector_col_1,
(color*)&ibox_cursor_col_1,
(color*)&list_normal_txt_col_1,
(color*)&list_selected_txt_col_1,
(color*)&Disabled_text_col,
(color*)&ibox_normal_txt_col_1,
(color*)&ibox_selected_txt_col_1,
(color*)&ibox_selector_col_1,
(color*)&ibox_cursor_col_1,
(color*)&ibox_normal_txt_col_1,
(color*)&ibox_selected_txt_col_1,
(color*)&ibox_selector_col_1,
(color*)&ibox_cursor_col_1,
(color*)&virtual_keyboard_key_down_text_col_1,
(color*)&virtual_keyboard_key_up_text_col_1,
(color*)&virtual_keyboard_dead_key_down_text_col_1,
(color*)&virtual_keyboard_dead_key_up_text_col_1,
(color*)&virtual_keyboard_disp_area_text_col_1,
(color*)&calculator_color1,
(color*)&alarm_text_color1,
(color*)&idle_scr_date_color1,
(color*)&idle_scr_time_color1,
(color*)&idle_scr_date_border_color1,
(color*)&idle_scr_time_border_color1,
(color*)&idle_scr_network_name_color1,
(color*)&idle_scr_network_name_border_color1,
(color*)&idle_scr_network_status_color1,
(color*)&idle_scr_network_status_border_color1,
(color*)&idle_scr_network_extra_color1,
(color*)&idle_scr_network_extra_border_color1,
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
&MMI_default_font,
&MMI_default_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
UI_BG_OPACITY_FULL_DEFAULT,
UI_BG_OPACITY_HIGH_DEFAULT,
UI_BG_OPACITY_MEDIUM_DEFAULT,
UI_BG_OPACITY_LOW_DEFAULT,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
(UI_filled_area*)&list_selected_item_1,
/* main_menu_bkg_image */
NULL,
/* sub_menu_bkg_image */
NULL,
/* idle_bkg_image */
NULL,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&black_color,
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
(UI_filled_area*)&softkey_bar_filler_defaultTheme,
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
(UI_filled_area*)&Title_1,
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
(UI_filled_area  *)NULL,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
(UI_filled_area  *)NULL,
/* high light image of matrix main menu */
NULL,
/* background filler of bidegree main menu */
NULL,
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

const MMI_theme theme_2={
(UI_filled_area*)&mtab_2,
(UI_filled_area*)&ibox_2,
(UI_filled_area*)&sbar_bkgrnd_2,
(UI_filled_area*)&sbar_indicator_2,
(UI_filled_area*)&Title_2,
(UI_filled_area*)&list_bkgrnd_2,
(UI_filled_area*)&list_normal_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_bkgrnd_2,
(UI_filled_area*)&matrix_normal_item_2,
(UI_filled_area*)&matrix_selected_item_2,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&fibox_normal_2,
(UI_filled_area*)&fibox_selected_2,
(UI_filled_area*)&mm_bkgrnd_2,
(UI_filled_area*)&list_normal_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_normal_item_2,
(UI_filled_area*)&matrix_selected_item_2,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&popup_description_bkgrnd_2,
(UI_filled_area*)&list_bkgrnd_2,
(UI_filled_area*)&list_normal_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&Unused,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&dial_inputbox_bg_filler,
(UI_filled_area*)&virtual_keyboard_down_bkgrnd_1,
(UI_filled_area*)&alarm_background_filler2,
(UI_filled_area*)&small_list_menu_normal_filler2,
(UI_filled_area*)&small_list_screen_border_filler2,
(color*)&black_color,
(color*)&white_color,
(color*)&lite_disp_scr_bg_col_2,
(color*)&LSK_up_txt_col_2,
(color*)&LSK_down_txt_col_2,
(color*)&Disabled_text_col,
(color*)&RSK_up_txt_col_2,
(color*)&RSK_down_txt_col_2,
(color*)&Disabled_text_col,
(color*)&mtab_selector_txt_col_2,
(color*)&mtab_normal_txt_col_2,
(color*)&mtab_selected_txt_col_2,
(color*)&ibox_normal_txt_col_2,
(color*)&ibox_selected_txt_col_2,
(color*)&ibox_selector_col_2,
(color*)&ibox_cursor_col_2,
(color*)&title_scut_txt_col_2,
(color*)&white_color,
(color*)&title_scut_txt_col_2,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&ibox_selector_col_2,
(color*)&ibox_normal_txt_col_2,
(color*)&Disabled_text_col,
(color*)&ibox_selected_txt_col_2,
(color*)&ibox_cursor_col_2,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&white_color,
(color*)&black_color,
(color*)&popup_description_txt_col_2,
(color*)&CM_screen_text_color_2,
(color*)&white_color,
(color*)&white_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&information_bar_col_2,
(color*)&input_method_txt_col_2,
(color*)&input_method_txt_col_2,
(color*)&black_color,
(color*)&ibox_normal_txt_col_2,
(color*)&ibox_selected_txt_col_2,
(color*)&ibox_selector_col_2,
(color*)&ibox_cursor_col_2,
(color*)&list_normal_txt_col_2,
(color*)&list_selected_txt_col_2,
(color*)&Disabled_text_col,
(color*)&ibox_normal_txt_col_2,
(color*)&ibox_selected_txt_col_2,
(color*)&ibox_selector_col_2,
(color*)&ibox_cursor_col_2,
(color*)&ibox_normal_txt_col_2,
(color*)&ibox_selected_txt_col_2,
(color*)&ibox_selector_col_2,
(color*)&ibox_cursor_col_2,
(color*)&virtual_keyboard_key_down_text_col_1,
(color*)&virtual_keyboard_key_up_text_col_1,
(color*)&virtual_keyboard_dead_key_down_text_col_1,
(color*)&virtual_keyboard_dead_key_up_text_col_1,
(color*)&virtual_keyboard_disp_area_text_col_1,
(color*)&calculator_color2,
(color*)&alarm_text_color2,
(color*)&idle_scr_date_color1,
(color*)&idle_scr_time_color1,
(color*)&idle_scr_date_border_color1,
(color*)&idle_scr_time_border_color1,
(color*)&idle_scr_network_name_color1,
(color*)&idle_scr_network_name_border_color1,
(color*)&idle_scr_network_status_color1,
(color*)&idle_scr_network_status_border_color1,
(color*)&idle_scr_network_extra_color1,
(color*)&idle_scr_network_extra_border_color1,
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
&MMI_default_font,
&MMI_default_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
UI_BG_OPACITY_FULL_DEFAULT,
UI_BG_OPACITY_HIGH_DEFAULT,
UI_BG_OPACITY_MEDIUM_DEFAULT,
UI_BG_OPACITY_LOW_DEFAULT,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
(UI_filled_area*)&list_selected_item_2,
/* main_menu_bkg_image */
NULL,
/* sub_menu_bkg_image */
NULL,
/* idle_bkg_image */
NULL,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&black_color,
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
(UI_filled_area*)&softkey_bar_filler_defaultTheme,
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
(UI_filled_area*)&Title_1,
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
(UI_filled_area  *)NULL,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
(UI_filled_area  *)NULL,
/* high light image of matrix main menu */
NULL,
/* background filler of bidegree main menu */
NULL,
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

const MMI_theme theme_3={
(UI_filled_area*)&mtab_3,
(UI_filled_area*)&ibox_3,
(UI_filled_area*)&sbar_bkgrnd_3,
(UI_filled_area*)&sbar_indicator_3,
(UI_filled_area*)&Title_3,
(UI_filled_area*)&list_bkgrnd_3,
(UI_filled_area*)&list_normal_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_bkgrnd_3,
(UI_filled_area*)&matrix_normal_item_3,
(UI_filled_area*)&matrix_selected_item_3,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&fibox_normal_3,
(UI_filled_area*)&fibox_selected_3,
(UI_filled_area*)&mm_bkgrnd_3,
(UI_filled_area*)&list_normal_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&matrix_normal_item_3,
(UI_filled_area*)&matrix_selected_item_3,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&popup_description_bkgrnd_3,
(UI_filled_area*)&list_bkgrnd_3,
(UI_filled_area*)&list_normal_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&Disabled_items,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&General_BG,
(UI_filled_area*)&Unused,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&common_screen_BG,
(UI_filled_area*)&dial_inputbox_bg_filler,
(UI_filled_area*)&virtual_keyboard_down_bkgrnd_1,
(UI_filled_area*)&alarm_background_filler3,
(UI_filled_area*)&small_list_menu_normal_filler3,
(UI_filled_area*)&small_list_screen_border_filler3,
(color*)&black_color,
(color*)&white_color,
(color*)&lite_disp_scr_bg_col_3,
(color*)&LSK_up_txt_col_3,
(color*)&LSK_down_txt_col_3,
(color*)&Disabled_text_col,
(color*)&RSK_up_txt_col_3,
(color*)&RSK_down_txt_col_3,
(color*)&Disabled_text_col,
(color*)&mtab_selector_txt_col_3,
(color*)&mtab_normal_txt_col_3,
(color*)&mtab_selected_txt_col_3,
(color*)&ibox_normal_txt_col_3,
(color*)&ibox_selected_txt_col_3,
(color*)&ibox_selector_col_3,
(color*)&ibox_cursor_col_3,
(color*)&title_scut_txt_col_3,
(color*)&white_color,
(color*)&title_scut_txt_col_3,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&Unused_color,
(color*)&ibox_selector_col_3,
(color*)&ibox_normal_txt_col_3,
(color*)&Disabled_text_col,
(color*)&ibox_selected_txt_col_3,
(color*)&ibox_cursor_col_3,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&white_color,
(color*)&black_color,
(color*)&popup_description_txt_col_3,
(color*)&CM_screen_text_color_3,
(color*)&white_color,
(color*)&white_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&black_color,
(color*)&information_bar_col_3,
(color*)&input_method_txt_col_3,
(color*)&input_method_txt_col_3,
(color*)&black_color,
(color*)&ibox_normal_txt_col_3,
(color*)&ibox_selected_txt_col_3,
(color*)&ibox_selector_col_3,
(color*)&ibox_cursor_col_3,
(color*)&list_normal_txt_col_3,
(color*)&list_selected_txt_col_3,
(color*)&Disabled_text_col,
(color*)&ibox_normal_txt_col_3,
(color*)&ibox_selected_txt_col_3,
(color*)&ibox_selector_col_3,
(color*)&ibox_cursor_col_3,
(color*)&ibox_normal_txt_col_3,
(color*)&ibox_selected_txt_col_3,
(color*)&ibox_selector_col_3,
(color*)&ibox_cursor_col_3,
(color*)&virtual_keyboard_key_down_text_col_1,
(color*)&virtual_keyboard_key_up_text_col_1,
(color*)&virtual_keyboard_dead_key_down_text_col_1,
(color*)&virtual_keyboard_dead_key_up_text_col_1,
(color*)&virtual_keyboard_disp_area_text_col_1,
(color*)&calculator_color3,
(color*)&alarm_text_color3,
(color*)&idle_scr_date_color1,
(color*)&idle_scr_time_color1,
(color*)&idle_scr_date_border_color1,
(color*)&idle_scr_time_border_color1,
(color*)&idle_scr_network_name_color1,
(color*)&idle_scr_network_name_border_color1,
(color*)&idle_scr_network_status_color1,
(color*)&idle_scr_network_status_border_color1,
(color*)&idle_scr_network_extra_color1,
(color*)&idle_scr_network_extra_border_color1,
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
&MMI_default_font,
&MMI_default_font,
&MMI_virtual_keyboard_font,
UI_SCROLLBAR_WIDTH,
UI_BG_OPACITY_FULL_DEFAULT,
UI_BG_OPACITY_HIGH_DEFAULT,
UI_BG_OPACITY_MEDIUM_DEFAULT,
UI_BG_OPACITY_LOW_DEFAULT,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
(UI_filled_area*)&list_selected_item_3,
/* main_menu_bkg_image */
NULL,
/* sub_menu_bkg_image */
NULL,
/* idle_bkg_image */
NULL,
/* popup_bkg_image */
NULL,
/* popup_text_color */
(color*)&black_color,
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
(UI_filled_area*)&softkey_bar_filler_defaultTheme,
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
(UI_filled_area*)&Title_1,
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
(UI_filled_area  *)NULL,
/* normal image for tab bar */
(UI_filled_area  *)NULL,
/* highlight image for tab bar */
(UI_filled_area  *)NULL,
/* blink image for tab bar */
(UI_filled_area  *)NULL,
/* high light filler of bidegree main menu */
(UI_filled_area  *)NULL,
/* high light image of matrix main menu */
NULL,
/* background filler of bidegree main menu */
NULL,
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
(MMI_theme *)&theme_1,
(MMI_theme *)&theme_2,
(MMI_theme *)&theme_3,
};

#else /* __MMI_THEMES_V2_SUPPORT__ */
const theme_details_struct mtk_MMI_themes[MAX_MMI_THEMES]=
{
	{
		(MMI_theme*)&theme_1,
		NULL,
		NULL
	},
	{
		(MMI_theme*)&theme_2,
		NULL,
		NULL
	},
	{
		(MMI_theme*)&theme_3,
		NULL,
		NULL
	}
};
#endif /* __MMI_THEMES_V2_SUPPORT__ */

/*
 * Before turning on downloadable theme, please use MCT to generate your
 * own theme containing correct phone model name instead of using system 
 * default themes.
 */
const char theme_phone_model[] = "Use-MCT-to-generate-theme-for-DLT";

