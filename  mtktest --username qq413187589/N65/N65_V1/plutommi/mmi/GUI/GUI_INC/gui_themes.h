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
 *   gui_themes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common theme definitions   
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui_themes.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      Theme Structures and functions header
**********************************************************************************/

#ifndef __GUI_THEMES_H__
#define __GUI_THEMES_H__

#include "gui.h"
#include "custthemesres.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"
/* MTK Leo end */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    extern stFontAttribute UI_DEFAULT_FONT;

    /* Default themes / colors used in the UI    */
    /* > 8-bit (Includes 16-bit/24-bit/32-bit)      */

    extern color default_gradient_color_list[];
    extern U8 default_gradient_color_percentage[];
    extern gradient_color default_gradient_color;

    extern CONST_HARDWARE UI_filled_area_border_theme default_filled_area_border_theme;

    /* UI colors                           */
    extern CONST_HARDWARE color UI_COLOR_LIGHT_GREY;
    extern CONST_HARDWARE color UI_COLOR_WHITE;
    extern CONST_HARDWARE color UI_COLOR_DARK_GREY;
    extern CONST_HARDWARE color UI_COLOR_BLACK;
    extern CONST_HARDWARE color UI_COLOR_NONE;
    extern CONST_HARDWARE color UI_COLOR_RED;
    extern CONST_HARDWARE color UI_COLOR_3D_FILLER;
    extern CONST_HARDWARE color UI_COLOR_GREY;
    extern CONST_HARDWARE color UI_COLOR_GREEN;

    /* System UI fillers */

    extern CONST_HARDWARE UI_filled_area MMI_down_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_up_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_disabled_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_focussed_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_clicked_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_multitap_filler;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_normal_filler;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_selected_filler;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_disabled_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollbar_normal_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollbar_disabled_filler;
    extern CONST_HARDWARE UI_filled_area MMI_scrollbar_focussed_filler;
    extern CONST_HARDWARE UI_filled_area MMI_progress_indicator_background_filler;
    extern CONST_HARDWARE UI_filled_area MMI_progress_indicator_fillers[];
    extern U8 MMI_progress_indicator_filler_percentages[];
    extern S32 MMI_n_progress_indicator_fillers;
    extern CONST_HARDWARE UI_filled_area MMI_active_title_filler;
    extern CONST_HARDWARE UI_filled_area MMI_inactive_title_filler;
    extern CONST_HARDWARE UI_filled_area MMI_general_background_filler;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_background_filler;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_normal_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_disabled_item_filler;
    extern CONST_HARDWARE UI_filled_area MMI_shortcut_indicator_background;
    extern CONST_HARDWARE UI_filled_area MMI_drop_down_control_normal_filler;
    extern CONST_HARDWARE UI_filled_area MMI_drop_down_control_disabled_filler;
    extern CONST_HARDWARE UI_filled_area MMI_drop_down_control_focussed_filler;
    extern CONST_HARDWARE UI_filled_area MMI_drop_down_button_up_filler;
    extern CONST_HARDWARE UI_filled_area MMI_drop_down_button_down_filler;
    extern CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_normal_filler;
    extern CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_disabled_filler;
    extern CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_selected_filler;

    /* System UI element themes   */

    extern UI_filled_area_border_theme MMI_filled_area_border_theme;
    extern UI_button_theme MMI_button_theme;
    extern UI_text_button_theme MMI_text_button_theme;
    extern UI_icon_button_theme MMI_icon_button_theme;
    extern UI_icontext_button_theme MMI_icontext_button_theme;
    extern UI_multitap_input_theme MMI_multitap_input_theme;
    extern UI_single_line_input_box_theme MMI_singleline_inputbox_theme;
    extern UI_button_theme MMI_scrollbar_control_button_theme;
    extern UI_button_theme MMI_scrollbar_scroll_button_theme;
    extern UI_vertical_scrollbar_theme MMI_vertical_scrollbar_theme;
    extern UI_horizontal_scrollbar_theme MMI_horizontal_scrollbar_theme;
    extern UI_vertical_slide_theme MMI_vertical_slide_theme;
    extern UI_horizontal_slide_theme MMI_horizontal_slide_theme;
    extern UI_multi_line_input_box_theme MMI_multiline_inputbox_theme;
    extern UI_horizontal_progress_indicator_theme MMI_hprogress_indicator_theme;
    extern UI_text_menuitem_theme MMI_text_menuitem_theme;
    extern UI_icontext_menuitem_theme MMI_icontext_menuitem_theme;
    extern UI_fixed_text_menuitem_theme MMI_fixed_text_menuitem_theme;
    extern UI_fixed_icontext_menuitem_theme MMI_fixed_icontext_menuitem_theme;
    extern UI_fixed_icontext_list_menuitem_theme MMI_fixed_icontext_list_menuitem_theme;
    extern UI_list_menu_theme MMI_list_menu_theme;
    extern UI_fixed_list_menu_theme MMI_fixed_list_menu_theme;
    extern UI_matrix_menu_theme MMI_matrix_menu_theme;
    extern UI_fixed_matrix_menu_theme MMI_fixed_matrix_menu_theme;
    extern UI_window_title_theme MMI_window_title_theme;
    extern UI_dialer_input_box_theme MMI_dialer_inputbox_theme;
    extern UI_drop_down_control_theme MMI_drop_down_control_theme;
    extern UI_information_bar_theme MMI_information_bar_theme;
    extern UI_EMS_input_box_theme MMI_EMS_inputbox_theme;
    extern UI_horizontal_tab_bar_theme MMI_horizontal_tab_bar_theme;
    extern UI_virtual_keyboard_theme MMI_virtual_keyboard_theme;
    extern UI_shortcut_box_theme MMI_shortcut_box_theme;
    extern UI_clock_theme MMI_clock_theme;
    extern UI_calendar_theme MMI_calendar_theme;
    extern UI_ime_theme MMI_ime_theme;

    extern void gui_initialize_default_themes(void);

    /*
     * Main theme structure:
     * This structure contains the theme types of all UI elements  
     * This structure remains the same across various MMIs
     */

    typedef struct _UI_theme
    {
        UI_filled_area_border_theme *border_theme;
        UI_button_theme *button_theme;
        UI_text_button_theme *text_button_theme;
        UI_icon_button_theme *icon_button_theme;
        UI_icontext_button_theme *icontext_button_theme;
        UI_multitap_input_theme *multitap_input_theme;
        UI_single_line_input_box_theme *single_line_input_box_theme;
        UI_multi_line_input_box_theme *multi_line_input_box_theme;
        UI_vertical_scrollbar_theme *vertical_scrollbar_theme;
        UI_horizontal_scrollbar_theme *horizontal_scrollbar_theme;
        UI_horizontal_progress_indicator_theme *horizontal_progress_indicator_theme;
        UI_vertical_progress_indicator_theme *vertical_progress_indicator_theme;
        UI_vertical_slide_theme *vertical_slide_theme;
        UI_horizontal_slide_theme *horizontal_slide_theme;
        UI_text_menuitem_theme *text_menuitem_theme;
        UI_icontext_menuitem_theme *icontext_menuitem_theme;
        UI_fixed_text_menuitem_theme *fixed_text_menuitem_theme;
        UI_fixed_icontext_menuitem_theme *fixed_icontext_menuitem_theme;
        UI_fixed_icontext_list_menuitem_theme *fixed_icontext_list_menuitem_theme;
        UI_fixed_twostate_menuitem_theme *fixed_twostate_menuitem_theme;
        UI_list_menu_theme *list_menu_theme;
        UI_fixed_list_menu_theme *fixed_list_menu_theme;
        UI_matrix_menu_theme *matrix_menu_theme;
        UI_fixed_matrix_menu_theme *fixed_matrix_menu_theme;
        UI_window_title_theme *window_title_theme;
        UI_window_title_theme *thick_title_theme;
        UI_window_title_theme *tab_title_theme;        
        UI_dialer_input_box_theme *dialer_inputbox_theme;
        UI_drop_down_control_theme *drop_down_control_theme;
        UI_information_bar_theme *information_bar_theme;
        UI_EMS_input_box_theme *EMS_inputbox_theme;
        UI_horizontal_tab_bar_theme *horizontal_tab_bar_theme;
        UI_virtual_keyboard_theme *virtual_keyboard_theme;
        UI_ime_theme *ime_theme;
        UI_shortcut_box_theme *shortcut_box_theme;
        UI_clock_theme *clock_theme;
        UI_calendar_theme *calendar_theme;
    } UI_theme;

    extern UI_theme system_UI_theme;
    extern UI_theme *current_UI_theme;

    /*
     * MMI theme structure:
     * This structure is used for theme customization --etc in a simple MMI 
     * This structure can change from MMI to MMI
     */

    extern MMI_theme *current_MMI_theme;
    
    extern void change_font(void);

    extern void set_MMI_button_theme(MMI_theme *t);
    extern void set_MMI_text_button_theme(MMI_theme *t);
    extern void set_MMI_icontext_button_theme(MMI_theme *t);
    extern void set_MMI_icon_button_theme(MMI_theme *t);
    extern void set_MMI_multitap_input_theme(MMI_theme *t);
    extern void set_MMI_singleline_inputbox_theme(MMI_theme *t);
    extern void set_MMI_multiline_inputbox_theme(MMI_theme *t);
    extern void set_MMI_vertical_scrollbar_theme(MMI_theme *t);
    extern void set_MMI_horizontal_scrollbar_theme(MMI_theme *t);
    extern void set_MMI_horizontal_progress_indicator_theme(MMI_theme *t);
    extern void set_MMI_vertical_progress_indicator_theme(MMI_theme *t);
    extern void set_MMI_vertical_slide_theme(MMI_theme *t);
    extern void set_MMI_horizontal_slide_theme(MMI_theme *t);
    extern void set_MMI_text_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_text_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_fixed_text_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_fixed_text_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_icontext_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_icontext_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_fixed_icontext_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_fixed_icontext_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_fixed_icontext_list_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_fixed_icontext_list_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_fixed_twostate_menuitem_theme_list(MMI_theme *t);
    extern void set_MMI_fixed_twostate_menuitem_theme_matrix(MMI_theme *t);
    extern void set_MMI_current_fixed_twostate_menuitem_theme_list(void);
    extern void set_MMI_current_fixed_twostate_menuitem_theme_matrix(void);
    extern void set_MMI_current_text_menuitem_theme_list(void);
    extern void set_MMI_current_text_menuitem_theme_matrix(void);
    extern void set_MMI_current_fixed_text_menuitem_theme_list(void);
    extern void set_MMI_current_fixed_text_menuitem_theme_matrix(void);
    extern void set_MMI_current_icontext_menuitem_theme_list(void);
    extern void set_MMI_current_icontext_menuitem_theme_matrix(void);
    extern void set_MMI_current_fixed_icontext_menuitem_theme_list(void);
    extern void set_MMI_current_fixed_icontext_menuitem_theme_matrix(void);
    extern void set_MMI_current_fixed_icontext_menuitem_theme_matrix_bidegree_menu(void);
    extern void set_MMI_current_fixed_icontext_list_menuitem_theme_list(void);
    extern void set_MMI_current_fixed_icontext_list_menuitem_theme_matrix(void);
    extern void set_MMI_list_menu_theme(MMI_theme *t);
    extern void set_MMI_fixed_list_menu_theme(MMI_theme *t);
    extern void set_MMI_matrix_menu_theme(MMI_theme *t);
    extern void set_MMI_fixed_matrix_menu_theme(MMI_theme *t);
    extern void set_MMI_window_title_theme(MMI_theme *t);
    extern void set_MMI_tab_title_theme(MMI_theme *t);
    extern void set_MMI_general_inputbox_theme(MMI_theme *t);
    extern void set_MMI_drop_down_control_theme(MMI_theme *t);
    extern void set_MMI_information_bar_theme(MMI_theme *t);
    extern void set_MMI_EMS_inputbox_theme(MMI_theme *t);
    extern void set_MMI_horizontal_tab_bar_theme(MMI_theme *t);
    extern void set_MMI_virtual_keyboard_theme(MMI_theme *t);
    extern void set_MMI_ime_theme(MMI_theme *t);
    extern void set_MMI_shortcut_box_theme(MMI_theme *t);

    /* Helper functions  */
    extern void set_MMI_singleline_inputbox_shortcut_indicator_theme(void);
    extern void set_MMI_singleline_inputbox_regular_theme(void);
    extern void set_MMI_LSK_theme(void);
    extern void set_MMI_RSK_theme(void);
    extern void set_MMI_regular_button_theme(void);
    extern void set_MMI_matrix_main_menu_theme(void);
    extern void set_MMI_list_main_menu_theme(void);
    extern void set_MMI_3D_circular_main_menu_theme(void);
    extern void set_MMI_matrix_sub_menu_theme(void);
    extern void set_MMI_list_sub_menu_theme(void);

    extern void set_MMI_theme(MMI_theme *t);
    extern UI_font_type get_MMI_font_type(U8 t);
    /* void PopulateThemeResources(void); */

#define MAX_PROGRESS_INDICATOR_FILLERS 8

    /* Built-In font data   */

    extern stFontAttribute MMI_small_font;
    /* Issue 31 - 25/04/2004 */
    extern stFontAttribute MMI_sublcd_font;
    /* End */
    extern stFontAttribute MMI_medium_font;
    extern stFontAttribute MMI_medium_bold_font;
    extern stFontAttribute MMI_large_font;
    extern stFontAttribute MMI_default_font;
    extern stFontAttribute MMI_virtual_keyboard_font;

    /* Extra stuff: Needs to be moved to custom resource files, see also gui_themes.c   */

    /* Extra fonts */

    extern stFontAttribute newfont1;
    extern stFontAttribute newfont2;
    extern stFontAttribute newfont3;
    extern stFontAttribute newfont4;

    /* Extra fillers  */

    extern CONST_HARDWARE UI_filled_area MMI_down_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_up_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_disabled_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_focussed_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_clicked_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_multitap_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_normal_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_selected_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_inputbox_disabled_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_scrollbar_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_progress_indicator_background_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_progress_indicator_fillers3[];
    extern U8 MMI_progress_indicator_filler_percentages3[];
    extern S32 MMI_n_progress_indicator_fillers3;
    extern CONST_HARDWARE UI_filled_area MMI_active_title_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_inactive_title_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_general_background_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_background_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_normal_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_disabled_item_filler3;
    extern CONST_HARDWARE UI_filled_area MMI_shortcut_indicator_background3;
    extern CONST_HARDWARE UI_filled_area MMI_down_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_up_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_disabled_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_focussed_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_clicked_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_multitap_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_active_title_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_inactive_title_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler2;
    extern CONST_HARDWARE UI_filled_area MMI_scrollbar_normal_filler2;

    /* Theme images ID definitions: Must be moved to a different file */

#define THEME_IMAGE_BASE_ID         (CATEGORY_SCREENS_BASE+400)
#define THEME_0_IMAGE_0_IMAGE_ID (THEME_IMAGE_BASE_ID+0)
#define THEME_0_IMAGE_1_IMAGE_ID (THEME_IMAGE_BASE_ID+1)
#define THEME_0_IMAGE_2_IMAGE_ID (THEME_IMAGE_BASE_ID+2)

    extern MMI_theme theme_Default;

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_THEMES_H__ */ 

