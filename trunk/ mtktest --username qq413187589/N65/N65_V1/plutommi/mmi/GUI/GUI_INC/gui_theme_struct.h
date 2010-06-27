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
 *   gui_theme_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Basic theme data structure 
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

#ifndef THEME_STRUCT_H
#define  THEME_STRUCT_H
#include "CustThemesRes.h"
typedef struct _UI_button_theme
{
    UI_filled_area *normal_up_filler;
    UI_filled_area *normal_down_filler;
    UI_filled_area *disabled_up_filler;
    UI_filled_area *disabled_down_filler;
    UI_filled_area *focussed_up_filler;
    UI_filled_area *focussed_down_filler;
    UI_filled_area *clicked_up_filler;
    UI_filled_area *clicked_down_filler;
} UI_button_theme;

typedef struct _UI_text_button_theme
{
    color normal_up_text_color;
    color normal_down_text_color;
    color disabled_up_text_color;
    color disabled_down_text_color;
    color focussed_up_text_color;
    color focussed_down_text_color;
    color clicked_up_text_color;
    color clicked_down_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_text_button_theme;

typedef struct _UI_icon_button_theme
{
    UI_filled_area *normal_up_filler;
    UI_filled_area *normal_down_filler;
    UI_filled_area *disabled_up_filler;
    UI_filled_area *disabled_down_filler;
    UI_filled_area *focussed_up_filler;
    UI_filled_area *focussed_down_filler;
    UI_filled_area *clicked_up_filler;
    UI_filled_area *clicked_down_filler;
    U32 flags;
} UI_icon_button_theme;

typedef struct _UI_icontext_button_theme
{
    UI_filled_area *normal_up_filler;
    UI_filled_area *normal_down_filler;
    UI_filled_area *disabled_up_filler;
    UI_filled_area *disabled_down_filler;
    UI_filled_area *focussed_up_filler;
    UI_filled_area *focussed_down_filler;
    UI_filled_area *clicked_up_filler;
    UI_filled_area *clicked_down_filler;
    color normal_up_text_color;
    color normal_up_text_border_color;
    color normal_down_text_color;
    color normal_down_text_border_color;
    color disabled_up_text_color;
    color disabled_up_text_border_color;
    color disabled_down_text_color;
    color disabled_down_text_border_color;
    color focussed_up_text_color;
    color focussed_up_text_border_color;
    color focussed_down_text_color;
    color focussed_down_text_border_color;
    color clicked_up_text_color;
    color clicked_up_text_border_color;
    color clicked_down_text_color;
    color clicked_down_text_border_color;
    UI_font_type text_font;
    U32 flags;
} UI_icontext_button_theme;

typedef struct _UI_vertical_scrollbar_theme
{
    UI_filled_area *focussed_bar_filler;
    UI_filled_area *normal_bar_filler;
    UI_filled_area *disabled_bar_filler;
    UI_button_theme *up_button_theme;
    UI_button_theme *down_button_theme;
    UI_button_theme *scroll_button_theme;
    PU8 up_button_icon;
    PU8 down_button_icon;
    PU8 scroll_button_icon;
    U32 flags;
} UI_vertical_scrollbar_theme;

typedef struct _UI_horizontal_scrollbar_theme
{
    UI_filled_area *focussed_bar_filler;
    UI_filled_area *normal_bar_filler;
    UI_filled_area *disabled_bar_filler;
    UI_button_theme *left_button_theme;
    UI_button_theme *right_button_theme;
    UI_button_theme *scroll_button_theme;
    PU8 left_button_icon;
    PU8 right_button_icon;
    PU8 scroll_button_icon;
    U32 flags;
} UI_horizontal_scrollbar_theme;

typedef struct _UI_horizontal_progress_indicator_theme
{
    U32 flags;
    UI_filled_area *background_filler;
    UI_filled_area *foreground_filler;
    S32 n_fillers;
    U8 *percentages;
    S32 block_width;
    S32 block_gap;
    S32 border_gap;
} UI_horizontal_progress_indicator_theme;

typedef struct _UI_vertical_progress_indicator_theme
{
    U32 flags;
    UI_filled_area *background_filler;
    UI_filled_area *foreground_filler;
    S32 n_fillers;
    U8 *percentages;
    S32 block_height;
    S32 block_gap;
    S32 border_gap;
} UI_vertical_progress_indicator_theme;

typedef struct _UI_vertical_slide_theme
{
    UI_filled_area *focussed_bar_filler;
    UI_filled_area *normal_bar_filler;
    UI_filled_area *disabled_bar_filler;
    UI_button_theme *scroll_button_theme;
    PU8 scroll_button_icon;
    U32 flags;
} UI_vertical_slide_theme;

typedef struct _UI_horizontal_slide_theme
{
    UI_filled_area *focussed_bar_filler;
    UI_filled_area *normal_bar_filler;
    UI_filled_area *disabled_bar_filler;
    UI_button_theme *scroll_button_theme;
    PU8 scroll_button_icon;
    U32 flags;
} UI_horizontal_slide_theme;

typedef struct _UI_multitap_input_theme
{
    UI_filled_area *f;
    color selector_color;
    color normal_text_color;
    color selected_text_color;
    UI_font_type text_font;
    S8 text_gap;
    U32 flags;
} UI_multitap_input_theme;

typedef struct _UI_single_line_input_box_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color selection_text_color;
    color selection_color;
    color cursor_color;
    UI_font_type text_font;
    S8 text_gap;
    U32 flags;
    U8 mask_character;
} UI_single_line_input_box_theme;

typedef struct _UI_multi_line_input_box_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    color special_text_color;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color selection_text_color;
    color selection_color;
    color boundary_color;
    color cursor_color;
    UI_font_type text_font;
    S8 text_gap;
    U32 flags;
    U8 mask_character;
    S32 vbar_width;
} UI_multi_line_input_box_theme;

typedef struct _UI_dialer_input_box_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color selection_text_color;
    color selection_color;
    color cursor_color;
    UI_font_type text_font;
    S8 text_gap;
    U32 flags;
    U8 mask_character;
} UI_dialer_input_box_theme;

typedef struct _UI_text_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color focussed_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_text_menuitem_theme;

typedef struct _UI_icontext_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color focussed_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_icontext_menuitem_theme;

typedef struct _UI_fixed_text_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color focussed_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_fixed_text_menuitem_theme;

typedef struct _UI_fixed_icontext_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color focussed_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_fixed_icontext_menuitem_theme;

/* Minimum 4 icons are required for email/IMPS */
#define FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS 4
/*
 * "At-most" 2 text columns are supported for dynamic list menu because 
 * * the implementation uses subMenuData[] and hintData[] to hold text data.
 */
// TODO: The DL Agent category needs 3 text columns. Should move this to gui_config.h.
#define FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS 3

typedef struct _UI_fixed_icontext_list_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color disabled_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color selected_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color focussed_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    UI_font_type text_fonts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    U32 flags;
} UI_fixed_icontext_list_menuitem_theme;

typedef struct _UI_fixed_twostate_menuitem_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    UI_filled_area *focussed_filler;
    color normal_text_color;
    color disabled_text_color;
    color selected_text_color;
    color focussed_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_fixed_twostate_menuitem_theme;

typedef struct _UI_list_menu_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    S32 vbar_width;
    U32 flags;
} UI_list_menu_theme;

typedef struct _UI_matrix_menu_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    S32 vbar_width;
    S32 hbar_height;
    U32 flags;
} UI_matrix_menu_theme;

typedef struct _UI_fixed_list_menu_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    S32 vbar_width;
    U32 flags;
} UI_fixed_list_menu_theme;

typedef struct _UI_fixed_matrix_menu_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    S32 vbar_width;
    S32 hbar_height;
    U32 flags;
} UI_fixed_matrix_menu_theme;

typedef struct _UI_drop_down_control_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *focussed_filler;
    UI_filled_area *clicked_filler;
    color normal_text_color;
    color disabled_text_color;
    color focussed_text_color;
    color clicked_text_color;
    UI_font_type text_font;
    U32 flags;
    UI_button_theme *down_button_theme;
    PU8 down_button_icon;
} UI_drop_down_control_theme;

typedef struct _UI_horizontal_select_theme
{
    UI_filled_area *background_filler;
    U32 flags;
} UI_horizontal_select_theme;

typedef struct _UI_window_title_theme
{
    color active_text_color;
    color inactive_text_color;
    color focussed_text_color;
    color selected_text_color;
    color text_border_color;
    color shortcut_text_color;
    UI_font_type text_font;
    UI_filled_area *active_filler;
    UI_filled_area *inactive_filler;
    UI_filled_area *focussed_filler;
    UI_filled_area *selected_filler;
} UI_window_title_theme;

typedef struct _UI_pop_up_description_theme
{
    color text_color;
    UI_font_type text_font;
    UI_filled_area *background_filler;
    U32 flags;
} UI_pop_up_description_theme;

typedef struct _UI_information_bar_theme
{
    color background_color;
} UI_information_bar_theme;

typedef struct _UI_EMS_input_box_theme
{
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *selected_filler;
    color normal_text_color;
    color selected_text_color;
    color selection_color;
    color cursor_color;
    color boundary_color;   /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
    U32 flags;
    S32 vbar_width;
} UI_EMS_input_box_theme;

typedef struct _UI_shortcut_box_theme
{
    color normal_text_color;
    color normal_text_border_color;
    color active_text_color;
    color active_text_border_color;
    S8 use_border;
} UI_shortcut_box_theme;

typedef struct _UI_horizontal_tab_bar_theme
{
    UI_filled_area *background_filler;

    UI_font_type tab_text_font;
    UI_font_type focused_tab_text_font;

    color focused_tab_text_color;
    color normal_tab_text_color;
    color blinking_tab_text_color;

    UI_font_type hint_text_font;
    color hint_text_color;
    color hint_text_border_color;
    S8 hint_text_gap;
    U16 hint_bg_image;
    UI_filled_area *hint_filler;

    /* Blinking and normal tab has the same size */
    UI_filled_area *normal_tab_filler;
    UI_filled_area *normal_l_tab_filler;
    UI_filled_area *normal_r_tab_filler;
    U16 normal_tab_icon;
    U16 normal_l_tab_icon;
    U16 normal_r_tab_icon;

    UI_filled_area *blinking_tab_filler;
    UI_filled_area *blinking_l_tab_filler;
    UI_filled_area *blinking_r_tab_filler;
    U16 blinking_tab_icon;
    U16 blinking_l_tab_icon;
    U16 blinking_r_tab_icon;

    /* Focused tab might be larger than normal tab */
    UI_filled_area *focused_tab_filler;
    UI_filled_area *focused_l_tab_filler;
    UI_filled_area *focused_r_tab_filler;
    U16 focused_tab_icon;
    U16 focused_l_tab_icon;
    U16 focused_r_tab_icon;

    U16 left_button_icon;
    U16 right_button_icon;
} UI_horizontal_tab_bar_theme;

typedef struct _UI_virtual_keyboard_theme
{
    UI_filled_area *key_down_filler;
    color key_down_text_color;
    color key_up_text_color;
    color dead_key_down_text_color;
    color dead_key_up_text_color;
    color disp_area_text_color;
    UI_font_type text_font;
    U32 flags;
} UI_virtual_keyboard_theme;

typedef struct _UI_ime_theme
{
    color           underline_color;
    color           indicator_color;
    color           focused_background_color;
    color           background_color;
    color           focused_border_color;
    color           border_color;
    color           text_color;
    color           lable_color;
    color           hilite_color;
    color           hilite_text_color;
    color           cursor_color;
    color           arrow_color;
    UI_font_type    text_font;
    UI_font_type    lable_font;
} UI_ime_theme;

typedef struct 
{
    UI_font_type date_text_font;
    UI_font_type time_text_font;
    color date_text_color;
    color date_text_border_color;
    color time_text_color;
    color time_text_border_color;
    
#ifdef __MMI_SUBLCD__
    UI_font_type date_text_font_sub_lcd;
    UI_font_type time_text_font_sub_lcd;
    color date_text_color_sub_lcd;
    #ifdef __MMI_SUB_WALLPAPER__
    color date_text_border_color_sub_lcd;
#endif/*__MMI_SUB_WALLPAPER__*/
    color time_text_color_sub_lcd;
    #ifdef __MMI_SUB_WALLPAPER__
    color time_text_border_color_sub_lcd;
#endif/*__MMI_SUB_WALLPAPER__*/
#endif /* __MMI_SUBLCD__ */ 

    color analog_hand_hour_color;
    color analog_hand_min_color;
    color analog_axis_color;
} UI_clock_theme;

typedef enum
{
    GUI_CALENDAR_COLOR_CURRENT,
    GUI_CALENDAR_COLOR_ONE_TASK,
    GUI_CALENDAR_COLOR_MORE_TASK,
    GUI_CALENDAR_COLOR_MENSTRUAL,
    GUI_CALENDAR_COLOR_PP,
    GUI_CALENDAR_COLOR_DANGER,
    GUI_CALENDAR_COLOR_INVALID,        
    GUI_CALENDAR_COLOR_TOTAL,
    GUI_CALENDAR_COLOR_NONE = GUI_CALENDAR_COLOR_TOTAL
} GUI_CALENDAR_CELL_COLOR_INDEX;

typedef struct
{
    color title_fg;
    color horizontal_select_fg;
    color horizontal_select_border;
    color vertical_select_fg;
    color horizontal_string_fg;
    color cell_bg[GUI_CALENDAR_COLOR_TOTAL];
    color cell_valid_fg;
    color cell_invalid_fg;
    color cell_highlight;    
    
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    color infobox_bg;
    color infobox_entry_bg;
    color infobox_fg;    
    stFontAttribute *infobox_font;
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 

    stFontAttribute *horizontal_string_font;
    stFontAttribute *cell_font;
}UI_calendar_theme;


#endif /* THEME_STRUCT_H */ 

