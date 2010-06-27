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
 *   gui_themes.c
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

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui_themes.c
   Author:        manju
   Date Created:  July-22-2002
   Contains:      Theme functions for the GUI
**********************************************************************************/

#include "BuildCfg.h"
#include "MMI_features.h"
#define DEFINE_THEME_IMAGE(x) extern const U8 x[]
#define  THEME_IMAGE(x)       (PU8)x
/* Calvin end */

// #include "CustDataRes.h"
#include "FontRes.h"
#include "CustResDef.h"
#include "gui.h"
#include "gui_config.h"
#include "gui_buttons.h"
#include "gui_scrollbars.h"
#include "gui_inputs.h"
#include "gui_generic_menuitems.h"
#include "gui_fixed_menuitems.h"
#include "gui_generic_menus.h"
#include "gui_fixed_menus.h"
#include "gui_windows.h"
#include "gui_themes.h"
#include "SettingProfile.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_ems.h"
#include "gui_tab_bars.h"
#include "gui_virtual_keyboard.h"
#include "wgui_menu_shortcuts.h"
#include "gui_clock.h"
#include "gui_calendar.h"

/* Definition of image id of UI components */
#include "wgui_categories_defs.h"

#include "ScreenRotationGprot.h"

#ifdef __MMI_CSTAR__
#include "cstarHMI.h"
#endif

#define CONST_HARDWARE const

#include "ProfileGprots.h"
#include "SettingGprots.h"
/* This is temporary: Used to load Images from the resource */
#include "wgui.h"
PU8 get_image(MMI_ID_TYPE);

#ifndef __MTK_TARGET__
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */

/* The following are system defaults for fonts,
   colors and themes, do not modify       */
//MTK Leo add,20040318, for new simulator
//Move to FontType.c
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DIALLING_FONT__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

/* Default themes / colors used in the UI    */
/* > 8-bit (Includes 16-bit/24-bit/32-bit)      */

color default_gradient_color_list[] = { {200, 200, 255, 100}
,
{255, 255, 255, 100}
,
{180, 180, 180, 100}
};

U8 default_gradient_color_percentage[] = {20, 80};

gradient_color default_gradient_color = {default_gradient_color_list, default_gradient_color_percentage, 3};

CONST_HARDWARE UI_filled_area_border_theme default_filled_area_border_theme = { {220, 220, 220, 220}
,
{255, 255, 255, 100}
,
{64, 64, 64, 100}
,
{0, 0, 0, 100}
};

/* UI colors                           */
CONST_HARDWARE color UI_COLOR_LIGHT_GREY = {120, 120, 120, 120};
CONST_HARDWARE color UI_COLOR_WHITE = {255, 255, 255, 100};
CONST_HARDWARE color UI_COLOR_DARK_GREY = {64, 64, 64, 100};
CONST_HARDWARE color UI_COLOR_BLACK = {0, 0, 0, 100};
CONST_HARDWARE color UI_COLOR_NONE = {0, 0, 0, 0};
CONST_HARDWARE color UI_COLOR_RED = {255, 0, 0, 100};
CONST_HARDWARE color UI_COLOR_3D_FILLER = {180, 180, 200, 100};
CONST_HARDWARE color UI_COLOR_GREY = {192, 192, 192, 100};
CONST_HARDWARE color UI_COLOR_GREEN = {0, 255, 0, 100};

/* System UI fillers */
/* theme color of button down */
CONST_HARDWARE UI_filled_area MMI_down_button_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {40, 66, 118, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of button up */
CONST_HARDWARE UI_filled_area MMI_up_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_SHADOW,
    UI_NULL_IMAGE,
    NULL,
    {244, 188, 74, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of button disabled */
CONST_HARDWARE UI_filled_area MMI_disabled_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_SHADOW,
    UI_NULL_IMAGE,
    NULL,
    {64, 64, 64, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of button focussed  */
CONST_HARDWARE UI_filled_area MMI_focussed_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_SHADOW,
    UI_NULL_IMAGE,
    NULL,
    {0, 128, 128, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of button clicked */
CONST_HARDWARE UI_filled_area MMI_clicked_button_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {222, 166, 50, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of multotap filler */
CONST_HARDWARE UI_filled_area MMI_multitap_filler = 
{

    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    0
};

/* theme color of input box normal  */
CONST_HARDWARE UI_filled_area MMI_inputbox_normal_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of input box selected */
CONST_HARDWARE UI_filled_area MMI_inputbox_selected_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of input box disabled */
CONST_HARDWARE UI_filled_area MMI_inputbox_disabled_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of scroll bar of button up */
CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 225, 225, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of scroll bar of button down */
CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 225, 225, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of scroll bar of disabled */
CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {128, 128, 128, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme colro of scroll bar button select */
CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 225, 225, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {82, 212, 60, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of scroll bar button down */
CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {197, 197, 197, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of scroll bar disabled button */
CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {128, 128, 128, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {197, 197, 197, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* MTK Leo modify 0912 */
CONST_HARDWARE UI_filled_area MMI_scrollbar_normal_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {240, 235, 90, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* MTK Leo end */
CONST_HARDWARE UI_filled_area MMI_scrollbar_disabled_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {220, 220, 220, 100},
    {0, 0, 0, 0},
    {128, 128, 128, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of scroll bar focussed filler */
CONST_HARDWARE UI_filled_area MMI_scrollbar_focussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {148, 208, 246, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* theme color of progrss indicator bgkg color */
CONST_HARDWARE UI_filled_area MMI_progress_indicator_background_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* progress indiactor filler */
CONST_HARDWARE UI_filled_area MMI_progress_indicator_fillers[MAX_PROGRESS_INDICATOR_FILLERS] =
    { {UI_FILLED_AREA_TYPE_COLOR,
       UI_NULL_IMAGE,
       NULL,
       {0, 128, 0, 100},
       {0, 0, 0, 0},
       {0, 0, 0, 0},
       {0, 0, 0, 0},
       0}
};

U8 MMI_progress_indicator_filler_percentages[MAX_PROGRESS_INDICATOR_FILLERS] = {100
};

S32 MMI_n_progress_indicator_fillers = 1;

CONST_HARDWARE color MMI_temp_active_title_gc_colors[] = { {255, 255, 255, 100},
{116, 193, 255, 100},
};

U8 MMI_temp_active_title_gc_percentages[] = {100
};

gradient_color MMI_temp_active_title_gc = { (color *) MMI_temp_active_title_gc_colors,
    MMI_temp_active_title_gc_percentages,
    2,
};

/* This image must be present in the image resource. In case not present,
   set the structure member to NULL and build the resource. Then place a
   pointer to a valid image (which will be automatically generated in the
   image resource) as the structure member                           */

/* MTK Leo add */

CONST_HARDWARE UI_filled_area MMI_active_title_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_IMAGE_ID_NULL,
    NULL,
    {66, 96, 215, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    0
};

/* them colro of inactive title bar */
CONST_HARDWARE UI_filled_area MMI_inactive_title_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {64, 64, 64, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of general bgkg */
CONST_HARDWARE UI_filled_area MMI_general_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of transparent bgkg */
CONST_HARDWARE UI_filled_area MMI_transparent_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color oflist menu */
CONST_HARDWARE color MMI_temp_list_menu_gc_colors[] = { {255, 255, 255, 100},
{153, 207, 237, 100},
};

U8 MMI_temp_list_menu_gc_percentages[] = {100,
};

gradient_color MMI_temp_list_menu_gc = { (color *) MMI_temp_list_menu_gc_colors,
    MMI_temp_list_menu_gc_percentages,
    2,
};

CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {240, 240, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {240, 240, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {141, 167, 191, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_main_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of main menu normal item */
CONST_HARDWARE UI_filled_area MMI_list_main_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {190, 220, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of main menu selected item */
CONST_HARDWARE UI_filled_area MMI_list_main_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 240, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of main menu disable item */
CONST_HARDWARE UI_filled_area MMI_list_main_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {141, 167, 191, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrix menu bhkg */
CONST_HARDWARE UI_filled_area MMI_matrix_menu_background_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    255
};

/* theme color of matrix menu normal item filler */
CONST_HARDWARE UI_filled_area MMI_matrix_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrix meneu selected item */
CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {51, 88, 171, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrix meneu disabled  item */
CONST_HARDWARE UI_filled_area MMI_matrix_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {200, 200, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrx main menu bkg */
CONST_HARDWARE UI_filled_area MMI_matrix_main_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {206, 206, 206, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    255
};

/* theme color of matrix menu normal item */
CONST_HARDWARE UI_filled_area MMI_matrix_main_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrix menu selected item */
CONST_HARDWARE UI_filled_area MMI_matrix_main_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of matrix main menu disabled item */
CONST_HARDWARE UI_filled_area MMI_matrix_main_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {200, 200, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of shorcut indiactor bkg */
CONST_HARDWARE UI_filled_area MMI_shortcut_indicator_background =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {224, 224, 224, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_drop_down_button_up_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_drop_down_button_down_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_drop_down_control_normal_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {128, 128, 128, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_drop_down_control_disabled_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {192, 192, 192, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_drop_down_control_focussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of formated input box normal filler */
CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_normal_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {200, 200, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of formated input box selected  filler */
CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_selected_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme color of formated input box disabled  filler */
CONST_HARDWARE UI_filled_area MMI_formatted_inputbox_disabled_filler =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {192, 192, 192, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_pop_up_description_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {245, 247, 115, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of LSK up filler */
CONST_HARDWARE UI_filled_area MMI_LSK_up_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of LSK down filler */
CONST_HARDWARE UI_filled_area MMI_LSK_down_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of LSK disabled */
CONST_HARDWARE UI_filled_area MMI_LSK_disabled_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme colro of RSK uo filler */
CONST_HARDWARE UI_filled_area MMI_RSK_up_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_RSK_down_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of RSK disabled */
CONST_HARDWARE UI_filled_area MMI_RSK_disabled_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {118, 224, 15, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of circular main meu bkg */
CONST_HARDWARE UI_filled_area MMI_circular_main_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_BITMAP,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    255
};

/* theme color of circular menu normal item */
CONST_HARDWARE UI_filled_area MMI_circular_main_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of circular menu selected item */
CONST_HARDWARE UI_filled_area MMI_circular_main_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme color of circular menu disabled  item */
CONST_HARDWARE UI_filled_area MMI_circular_main_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {200, 200, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_list_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {240, 240, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_list_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {240, 240, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_list_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {167, 232, 93, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_list_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {192, 192, 192, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_edit_focussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {167, 232, 93, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_edit_unfocussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inline_edit_noboundary_filler = {UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {167, 232, 93, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_PIN_inputbox_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 222, 255, 100},
    {0, 0, 0, 0},
    {255, 0, 0, 100},
    {255, 0, 0, 100},
    0
};

CONST_HARDWARE UI_filled_area MMI_PIN_screen_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_network_screen_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_aphorism_screen_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_CM_screen_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_progress_screen_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_dialer_inputbox_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_virtual_keyboard_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    0
};

CONST_HARDWARE UI_filled_area alarm_background_filler_default = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 00, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    0
};

CONST_HARDWARE UI_filled_area MMI_softkey_bkg_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_IMAGE_ID_NULL,
    NULL,
    {0, 0, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    0
};

#ifdef __MMI_SCREEN_ROTATE__

/* Use simple white background */
CONST_HARDWARE UI_filled_area MMI_rotated_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_IMAGE_ID_NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    0
};

/* UI_filled_area.b will be setup later. */
UI_filled_area MMI_rotated_title_background_filler = 
{
    UI_FILLED_AREA_TYPE_BITMAP,
    NULL,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    0
};

#endif /* __MMI_SCREEN_ROTATE__ */ 

/* Default theme added by vikram */
CONST_HARDWARE color MMI_black_color = {0, 0, 0, 100};

CONST_HARDWARE color MMI_white_color = {255, 255, 255, 100};

CONST_HARDWARE color lite_disp_scr_bg_color_Default = {255, 255, 255, 100};

CONST_HARDWARE color button_up_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color button_down_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color button_disabled_txt_col_Default = {128, 128, 128, 100};

CONST_HARDWARE color button_focused_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color button_clicked_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color multitap_selector_txt_col_Default = {51, 88, 171, 100};

CONST_HARDWARE color multitap_normal_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color multitap_selected_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color ibox_selector_txt_col_Default = {51, 88, 171, 100};

CONST_HARDWARE color ibox_normal_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color ibox_disabled_txt_col_Default = {128, 128, 128, 100};

CONST_HARDWARE color ibox_selected_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color ibox_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color active_title_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color active_title_txt_bcol_Default = {0, 0, 0, 100};

CONST_HARDWARE color active_title_txt_border_col = {37, 83, 17, 100};

CONST_HARDWARE color inactive_title_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color title_shortcut_txt_color = {0, 0, 0, 100};

CONST_HARDWARE color list_normal_txt_col_Default = {0, 46, 114, 100};

CONST_HARDWARE color list_selected_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color list_disabled_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color matrix_normal_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color matrix_selected_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color matrix_disabled_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color mbar_index_bgrnd_col_Default = {50, 90, 140, 100};

CONST_HARDWARE color mbar_item_bgrnd_col_Default = {149, 207, 247, 100};

CONST_HARDWARE color mbar_index_txt_col_Default = {255, 255, 255, 100};

CONST_HARDWARE color mbar_item_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color scut_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color scut_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color title_txt_col_Default = {96, 0, 0, 100};

CONST_HARDWARE color popup_hint_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color CM_screen_text_color_Default = {0, 0, 0, 100};

CONST_HARDWARE color popup_screen_col_Default = {246, 255, 171, 100};
CONST_HARDWARE color popup_screen_bcol_Default = {142, 204, 145, 100};

CONST_HARDWARE color dt_bar_bkg_col_Default = {176, 223, 141, 100};
CONST_HARDWARE color dt_bar_duration_bkg_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color dt_bar_date_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color dt_bar_time_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color dt_bar_duration_txt_col_default = {224, 0, 0, 100};
CONST_HARDWARE color dt_bar_AOC_txt_col_default = {0, 0, 0, 100};

CONST_HARDWARE color temp_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color dropdn_normal_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color dropdn_disabled_txt_col_Default = {64, 64, 64, 100};
CONST_HARDWARE color dropdn_focused_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color fibox_selector_col_Default = {51, 88, 171, 100};
CONST_HARDWARE color fibox_normal_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color fibox_disabled_txt_col_Default = {128, 128, 128, 100};
CONST_HARDWARE color fibox_selected_txt_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color fibox_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color LSK_up_txt_col_Default = {37, 83, 17, 100};
CONST_HARDWARE color LSK_down_txt_col_Default = {37, 83, 17, 100};
CONST_HARDWARE color RSK_up_txt_col_Default = {37, 83, 17, 100};
CONST_HARDWARE color RSK_down_txt_col_Default = {37, 83, 17, 100};

CONST_HARDWARE color inline_focussed_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color inline_unfocussed_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color inline_selected_txt_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color inline_selector_col_Default = {51, 88, 171, 100};
CONST_HARDWARE color inline_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color inline_list_normal_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color inline_list_selected_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color inline_list_disabled_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color button_bar_col_Default = {216, 212, 212, 100};

CONST_HARDWARE color infobar_col_Default = {255, 231, 93, 100};

CONST_HARDWARE color input_method_col_Default = {255, 0, 0, 100};
CONST_HARDWARE color remaining_length_col_Default = {0, 0, 0, 100};

/* 101204 MTK Calvin modified to match background */
/* CONST_HARDWARE color statusbar0_col_Default={216,212,212,100}; */
CONST_HARDWARE color statusbar0_col_Default = {255, 255, 255, 100};

/* MTK Calvin end */

CONST_HARDWARE color PIN_inputbox_normal_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color PIN_inputbox_selected_txt_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color PIN_inputbox_selector_col_Default = {51, 88, 171, 100};
CONST_HARDWARE color PIN_inputbox_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color dialer_inputbox_normal_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color dialer_inputbox_selected_txt_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color dialer_inputbox_selector_col_Default = {51, 88, 171, 100};
CONST_HARDWARE color dialer_inputbox_cursor_col_Default = {255, 0, 0, 100};

CONST_HARDWARE color virtual_key_up_txt_col_Default = {0, 0, 0, 100};
CONST_HARDWARE color virtual_key_down_txt_col_Default = {255, 255, 255, 100};
CONST_HARDWARE color virtual_key_disp_area_txt_col_Default = {0, 0, 0, 100};

CONST_HARDWARE color calculator_color_default = {234, 56, 23, 100};
CONST_HARDWARE color alarm_text_color_default = {0, 0, 0, 100};

CONST_HARDWARE color idle_scr_date_color_default = {234, 123, 45, 100}; 
CONST_HARDWARE color idle_scr_date_border_color_default = {0,0,0,100};
CONST_HARDWARE color idle_scr_time_color_default = {234, 123, 45, 100};
CONST_HARDWARE color idle_scr_time_border_color_default = {0,0,0,100};
CONST_HARDWARE color idle_scr_network_name_color_default = {255,255,255,100};
CONST_HARDWARE color idle_scr_network_name_border_color_default = {0,0,0,100};
CONST_HARDWARE color idle_scr_network_status_color_default = {0,255,255,100};
CONST_HARDWARE color idle_scr_network_status_border_color_default = {0,0,0,100};
CONST_HARDWARE color idle_scr_network_extra_color_default = {255,255,0,100};
CONST_HARDWARE color idle_scr_network_extra_border_color_default = {0,0,0,100};

#define UI_BG_OPACITY_FULL_DEFAULT (255)
#define UI_BG_OPACITY_HIGH_DEFAULT (90)
#define UI_BG_OPACITY_MEDIUM_DEFAULT (70)
#define UI_BG_OPACITY_LOW_DEFAULT (40)

CONST_HARDWARE color softkey_text_border_color_default = {255,255,255,100}; 

CONST_HARDWARE color ime_underline_color_default = {255,0,0,100}; 
CONST_HARDWARE color ime_indicator_color_default  = {255,0,0,100};
CONST_HARDWARE color ime_focused_background_color_default  = {254,250,203,100};
CONST_HARDWARE color ime_background_color_default  = {255,255,255,100};
CONST_HARDWARE color ime_focused_border_color_default  = {200,0,0,100};
CONST_HARDWARE color ime_border_color_default  = {200,200,200,100};
CONST_HARDWARE color ime_text_color_default  = {0,0,0,100};
CONST_HARDWARE color ime_lable_color_default  = {246,0,1,100};
CONST_HARDWARE color ime_hilite_color_default  = {200,0,0,100};
CONST_HARDWARE color ime_hilite_text_color_default  = {255,255,255,100};
CONST_HARDWARE color ime_cursor_color_default  = {255,0,0,100};
CONST_HARDWARE color ime_arrow_color_default  = {0,0,0,100};


/* defualt theme */
MMI_theme theme_Default = 
{
    (UI_filled_area *)&MMI_multitap_filler,
    (UI_filled_area *)&MMI_inputbox_normal_filler,

    (UI_filled_area *)&MMI_scrollbar_normal_filler,
    (UI_filled_area *)&MMI_scroll_up_button_filler,

    (UI_filled_area *)&MMI_active_title_filler,

    (UI_filled_area *)&MMI_list_menu_background_filler,
    (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,

    (UI_filled_area *)&MMI_matrix_menu_background_filler,
    (UI_filled_area *)&MMI_matrix_menu_normal_item_filler,
    (UI_filled_area *)&MMI_matrix_menu_selected_item_filler,
    (UI_filled_area *)&MMI_matrix_menu_disabled_item_filler,

    (UI_filled_area *)&MMI_formatted_inputbox_normal_filler,
    (UI_filled_area *)&MMI_formatted_inputbox_selected_filler,

    (UI_filled_area *)&MMI_matrix_main_menu_background_filler,

    (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,

    (UI_filled_area *)&MMI_matrix_menu_normal_item_filler,
    (UI_filled_area *)&MMI_matrix_menu_selected_item_filler,
    (UI_filled_area *)&MMI_matrix_menu_disabled_item_filler,

    (UI_filled_area *)&MMI_general_background_filler,

    (UI_filled_area *)&MMI_pop_up_description_filler,

    (UI_filled_area *)&MMI_inline_list_menu_background_filler,
    (UI_filled_area *)&MMI_inline_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_inline_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_inline_list_menu_disabled_item_filler,

    (UI_filled_area *)&MMI_inline_edit_focussed_filler,
    (UI_filled_area *)&MMI_inline_edit_unfocussed_filler,
    (UI_filled_area *)&MMI_inline_edit_noboundary_filler,

    (UI_filled_area *)&MMI_PIN_inputbox_background_filler,
    (UI_filled_area *)&MMI_PIN_screen_background_filler,
    (UI_filled_area *)&MMI_network_screen_background_filler,
    (UI_filled_area *)&MMI_aphorism_screen_background_filler,
    (UI_filled_area *)&MMI_CM_screen_background_filler,
    (UI_filled_area *)&MMI_progress_screen_background_filler,
    (UI_filled_area *)&MMI_dialer_inputbox_background_filler,
    (UI_filled_area *)&MMI_virtual_keyboard_filler,
    (UI_filled_area *)&alarm_background_filler_default,
    NULL,
    NULL,
    (color *) & MMI_black_color,
    (color *) & MMI_white_color,

    (color *) & lite_disp_scr_bg_color_Default,

    (color *) & LSK_up_txt_col_Default,
    (color *) & LSK_down_txt_col_Default,
    (color *) & LSK_up_txt_col_Default,
    (color *) & RSK_up_txt_col_Default,
    (color *) & RSK_down_txt_col_Default,
    (color *) & RSK_up_txt_col_Default,

    (color *) & multitap_selector_txt_col_Default,
    (color *) & multitap_normal_txt_col_Default,
    (color *) & multitap_selected_txt_col_Default,

    (color *) & ibox_normal_txt_col_Default,
    (color *) & ibox_selected_txt_col_Default,
    (color *) & ibox_selector_txt_col_Default,
    (color *) & ibox_cursor_col_Default,

    (color *) & active_title_txt_col_Default,
    (color *) & active_title_txt_bcol_Default,
    (color *) & title_shortcut_txt_color,

    (color *) & list_normal_txt_col_Default,
    (color *) & list_selected_txt_col_Default,
    (color *) & list_disabled_txt_col_Default,

    (color *) & matrix_normal_txt_col_Default,
    (color *) & matrix_selected_txt_col_Default,
    (color *) & matrix_disabled_txt_col_Default,

    (color *) & mbar_index_bgrnd_col_Default,
    (color *) & mbar_item_bgrnd_col_Default,
    (color *) & mbar_index_txt_col_Default,
    (color *) & mbar_item_txt_col_Default,

    (color *) & dropdn_normal_txt_col_Default,
    (color *) & dropdn_disabled_txt_col_Default,
    (color *) & dropdn_focused_txt_col_Default,

    (color *) & fibox_selector_col_Default,
    (color *) & fibox_normal_txt_col_Default,
    (color *) & fibox_disabled_txt_col_Default,
    (color *) & fibox_selected_txt_col_Default,
    (color *) & fibox_cursor_col_Default,

    (color *) & list_normal_txt_col_Default,
    (color *) & list_selected_txt_col_Default,
    (color *) & list_disabled_txt_col_Default,

    (color *) & matrix_normal_txt_col_Default,
    (color *) & matrix_selected_txt_col_Default,
    (color *) & matrix_disabled_txt_col_Default,

    (color *) & matrix_normal_txt_col_Default,
    (color *) & matrix_selected_txt_col_Default,
    (color *) & matrix_disabled_txt_col_Default,

    (color *) & popup_screen_col_Default,
    (color *) & popup_screen_bcol_Default,

    (color *) & popup_hint_txt_col_Default,

    (color *) & CM_screen_text_color_Default,

    (color *) & dt_bar_bkg_col_Default,
    (color *) & dt_bar_duration_bkg_col_Default,
    (color *) & dt_bar_date_txt_col_Default,
    (color *) & dt_bar_time_txt_col_Default,
    (color *) & dt_bar_duration_txt_col_default,
    (color *) & dt_bar_AOC_txt_col_default,

    (color *) & infobar_col_Default,
    (color *) & input_method_col_Default,
    (color *) & remaining_length_col_Default,

    (color *) & inline_focussed_txt_col_Default,
    (color *) & inline_unfocussed_txt_col_Default,
    (color *) & inline_selected_txt_col_Default,
    (color *) & inline_selector_col_Default,
    (color *) & inline_cursor_col_Default,

    (color *) & inline_list_normal_txt_col_Default,
    (color *) & inline_list_selected_txt_col_Default,
    (color *) & inline_list_disabled_txt_col_Default,

    (color *) & PIN_inputbox_normal_txt_col_Default,
    (color *) & PIN_inputbox_selected_txt_col_Default,
    (color *) & PIN_inputbox_selector_col_Default,
    (color *) & PIN_inputbox_cursor_col_Default,

    (color *) & dialer_inputbox_normal_txt_col_Default,
    (color *) & dialer_inputbox_selected_txt_col_Default,
    (color *) & dialer_inputbox_selector_col_Default,
    (color *) & dialer_inputbox_cursor_col_Default,
    (color *) & virtual_key_down_txt_col_Default,
    (color *) & virtual_key_up_txt_col_Default,
    (color *) & virtual_key_down_txt_col_Default,
    (color *) & virtual_key_up_txt_col_Default,
    (color *) & virtual_key_disp_area_txt_col_Default,
    (color *) & calculator_color_default,
    (color *) & alarm_text_color_default,

    (color *) & idle_scr_date_color_default, 
    (color *) & idle_scr_time_color_default,
    (color *) & idle_scr_date_border_color_default,
    (color *) & idle_scr_time_border_color_default,
    (color *) & idle_scr_network_name_color_default,
    (color *) & idle_scr_network_name_border_color_default,
    (color *) & idle_scr_network_status_color_default,
    (color *) & idle_scr_network_status_border_color_default,
    (color *) & idle_scr_network_extra_color_default,
    (color *) & idle_scr_network_extra_border_color_default,

    &MMI_default_font,
    &MMI_default_font,
    &MMI_default_font,
    &MMI_default_font,
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

    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,
    (UI_filled_area*)&MMI_list_menu_selected_item_filler,

    /* full-screen background */
    NULL,
    NULL,
    NULL,
    
    /* popup background*/
    NULL,
    NULL,

    /* weekday in idle */
    NULL,
    NULL,

    /* clock */  
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,


    /* softkey */
    (color *)&softkey_text_border_color_default,
    (UI_filled_area *)&MMI_softkey_bkg_filler,

    /* tab title */
    (UI_filled_area *)&MMI_active_title_filler,
    (color *)& active_title_txt_col_Default,
    (color *)& active_title_txt_bcol_Default,
    (color *)& title_shortcut_txt_color,
    &MMI_default_font,

    /* IME */
    (color *) &ime_underline_color_default,
    (color *)&ime_indicator_color_default,
    (color *)&ime_focused_background_color_default,
    (color *)&ime_background_color_default,
    (color *)&ime_focused_border_color_default,
    (color *)&ime_border_color_default,
    (color *)&ime_text_color_default,
    (color *)&ime_lable_color_default,
    (color *)&ime_hilite_color_default,
    (color *)&ime_hilite_text_color_default,
    (color *)&ime_cursor_color_default,
    (color *)&ime_arrow_color_default,
    &MMI_default_font,
    &MMI_small_font,

    /* inline edit */
    NULL,

    /* calendar */ 
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    
    /* Status icon bar */
    NULL,
        
    /* thick title */
    NULL,
    NULL,
    NULL,
    NULL,
        
    /* main menu icon */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL

    
};

/* End of change */

/* System UI element themes   */
/* theme color of filled arae border color */
UI_filled_area_border_theme MMI_filled_area_border_theme = { {220, 220, 220, 220},
{255, 255, 255, 100},
{64, 64, 64, 100},
{0, 0, 0, 100}
};

/* theme color of button */
UI_button_theme MMI_button_theme = { (UI_filled_area *)&MMI_up_button_filler,
    (UI_filled_area *)&MMI_down_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler
};

/* theme color of text of button */
UI_text_button_theme MMI_text_button_theme = { {255, 255, 255, 100},
{255, 255, 255, 100},
{128, 128, 128, 100},
{128, 128, 128, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{200, 200, 255, 100},
{200, 200, 255, 100},
&UI_DEFAULT_FONT,
UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y,
};

/* theme color of icon of button */
UI_icon_button_theme MMI_icon_button_theme = { (UI_filled_area *)&MMI_up_button_filler,
    (UI_filled_area *)&MMI_down_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler,
    UI_BUTTON_CENTER_ICON_X | UI_BUTTON_CENTER_ICON_Y,
};

/* teme color of icontext button */
UI_icontext_button_theme MMI_icontext_button_theme = { (UI_filled_area *)&MMI_up_button_filler,
    (UI_filled_area *)&MMI_down_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_disabled_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_focussed_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler,
    (UI_filled_area *)&MMI_clicked_button_filler,
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {128, 128, 128, 100},
    {255, 255, 255, 100},
    {128, 128, 128, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {200, 200, 255, 100},
    {255, 255, 255, 100},
    {200, 200, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_BUTTON_CENTER_ICON_Y | UI_BUTTON_CENTER_TEXT_Y
};

/* theme color of multitap */
UI_multitap_input_theme MMI_multitap_input_theme = { (UI_filled_area *)&MMI_multitap_filler,
    {200, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    2,
    UI_MULTITAP_INPUT_CENTER_X | UI_MULTITAP_INPUT_CENTER_Y
};

/* theme color of single line input box */
UI_single_line_input_box_theme MMI_singleline_inputbox_theme = { (UI_filled_area *)&MMI_inputbox_normal_filler,
    (UI_filled_area *)&MMI_inputbox_selected_filler,
    (UI_filled_area *)&MMI_inputbox_disabled_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &UI_DEFAULT_FONT,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};

/* theme color of scroll bar control button theme */
UI_button_theme MMI_scrollbar_control_button_theme = { (UI_filled_area *)&MMI_scrollcontrol_up_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_down_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_disabled_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_disabled_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_focussed_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_focussed_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_focussed_button_filler,
    (UI_filled_area *)&MMI_scrollcontrol_focussed_button_filler
};

UI_button_theme MMI_scrollbar_scroll_button_theme = { (UI_filled_area *)&MMI_scroll_up_button_filler,
    (UI_filled_area *)&MMI_scroll_down_button_filler,
    (UI_filled_area *)&MMI_scroll_disabled_button_filler,
    (UI_filled_area *)&MMI_scroll_disabled_button_filler,
    (UI_filled_area *)&MMI_scroll_focussed_button_filler,
    (UI_filled_area *)&MMI_scroll_focussed_button_filler,
    (UI_filled_area *)&MMI_scroll_focussed_button_filler,
    (UI_filled_area *)&MMI_scroll_focussed_button_filler
};

/* them color of vertical scroll bar */
UI_vertical_scrollbar_theme MMI_vertical_scrollbar_theme = { (UI_filled_area *)&MMI_scrollbar_focussed_filler,
    (UI_filled_area *)&MMI_scrollbar_normal_filler,
    (UI_filled_area *)&MMI_scrollbar_disabled_filler,
    &MMI_scrollbar_control_button_theme,
    &MMI_scrollbar_control_button_theme,
    &MMI_scrollbar_scroll_button_theme,
    UI_NULL_IMAGE,
    UI_NULL_IMAGE,
    UI_NULL_IMAGE,
#if !defined(__MMI_TOUCH_SCREEN__) && !defined(UI_SCROLLBAR_STYLE_3) && !defined(UI_SCROLLBAR_STYLE_5)
    UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS
#else 
    0
#endif 
};

/* theme color of horizontal scroll bar */
UI_horizontal_scrollbar_theme MMI_horizontal_scrollbar_theme = { (UI_filled_area *)&MMI_scrollbar_focussed_filler,
    (UI_filled_area *)&MMI_scrollbar_normal_filler,
    (UI_filled_area *)&MMI_scrollbar_disabled_filler,
    &MMI_scrollbar_control_button_theme,
    &MMI_scrollbar_control_button_theme,
    &MMI_scrollbar_scroll_button_theme,
    UI_NULL_IMAGE,
    UI_NULL_IMAGE,
    UI_NULL_IMAGE,
#if !defined(__MMI_TOUCH_SCREEN__) && !defined(UI_SCROLLBAR_STYLE_3) && !defined(UI_SCROLLBAR_STYLE_5)
    UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS
#else 
    0
#endif 
};

/* theme color of multiline input box */
UI_multi_line_input_box_theme MMI_multiline_inputbox_theme = { (UI_filled_area *)&MMI_inputbox_normal_filler,
    (UI_filled_area *)&MMI_inputbox_selected_filler,
    (UI_filled_area *)&MMI_inputbox_disabled_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    {0, 0, 255, 100},
    &UI_DEFAULT_FONT,
    1,
    0,
    '*',
    5
};

/* theme color of horizontal progrss indiactor */
UI_horizontal_progress_indicator_theme MMI_hprogress_indicator_theme = {0,
    (UI_filled_area *)&MMI_progress_indicator_background_filler,
    (UI_filled_area *)MMI_progress_indicator_fillers,
    1,
    MMI_progress_indicator_filler_percentages,
    4,
    1,
    3
};

/* theme color of vertical progrss indicator */
UI_vertical_progress_indicator_theme MMI_vprogress_indicator_theme = {0,
    (UI_filled_area *)&MMI_progress_indicator_background_filler,
    (UI_filled_area *)MMI_progress_indicator_fillers,
    1,
    MMI_progress_indicator_filler_percentages,
    4,
    1,
    3
};

/* theme color of vertical slide */
UI_vertical_slide_theme MMI_vertical_slide_theme = { (UI_filled_area *)&MMI_scrollbar_focussed_filler,
    (UI_filled_area *)&MMI_scrollbar_normal_filler,
    (UI_filled_area *)&MMI_scrollbar_disabled_filler,
    &MMI_scrollbar_scroll_button_theme,
    UI_NULL_IMAGE,
    0
};

/* theme color of horizontal slide */
UI_horizontal_slide_theme MMI_horizontal_slide_theme = { (UI_filled_area *)&MMI_scrollbar_focussed_filler,
    (UI_filled_area *)&MMI_scrollbar_normal_filler,
    (UI_filled_area *)&MMI_scrollbar_disabled_filler,
    &MMI_scrollbar_scroll_button_theme,
    UI_NULL_IMAGE,
    0
};

/* them colro of menu text */
UI_text_menuitem_theme MMI_text_menuitem_theme = { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_MENUITEM_CENTER_TEXT_Y
};

UI_icontext_menuitem_theme MMI_icontext_menuitem_theme = { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y
};

UI_fixed_text_menuitem_theme MMI_fixed_text_menuitem_theme = { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_MENUITEM_CENTER_TEXT_Y
};

UI_fixed_icontext_menuitem_theme MMI_fixed_icontext_menuitem_theme =
    { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y
};

UI_fixed_icontext_list_menuitem_theme MMI_fixed_icontext_list_menuitem_theme =
    { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    {{0, 0, 0, 100}, {0, 0, 0, 100}},
    {{0, 0, 0, 100}, {0, 0, 0, 100}},
    {{255, 255, 255, 100}, {255, 255, 255, 100}},
    {{255, 255, 255, 100}, {255, 255, 255, 100}},
    {&UI_DEFAULT_FONT, &UI_DEFAULT_FONT},
    UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y
};

/* theme color of two state fixed menu item */
UI_fixed_twostate_menuitem_theme MMI_fixed_twostate_menuitem_theme =
    { (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    (UI_filled_area *)&MMI_list_menu_disabled_item_filler,
    (UI_filled_area *)&MMI_list_menu_selected_item_filler,
    (UI_filled_area *)&MMI_list_menu_normal_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y
};

/* theme color of list  menu item */
UI_list_menu_theme MMI_list_menu_theme = { (UI_filled_area *)&MMI_list_menu_background_filler,
    (UI_filled_area *)&MMI_list_menu_background_filler,
    5,
    0
};

UI_fixed_list_menu_theme MMI_fixed_list_menu_theme = { (UI_filled_area *)&MMI_list_menu_background_filler,
    (UI_filled_area *)&MMI_list_menu_background_filler,
    5,
    UI_LIST_MENU_LOOP
};

/* theme color of matrix menu */
UI_matrix_menu_theme MMI_matrix_menu_theme = { (UI_filled_area *)&MMI_matrix_menu_background_filler,
    (UI_filled_area *)&MMI_matrix_menu_background_filler,
    5,
    5,
    UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR
};

UI_fixed_matrix_menu_theme MMI_fixed_matrix_menu_theme = { (UI_filled_area *)&MMI_matrix_menu_background_filler,
    (UI_filled_area *)&MMI_matrix_menu_background_filler,
    5,
    5,
    UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR
};

/* theme color of title of scrren */
UI_window_title_theme MMI_window_title_theme = { {255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{0, 0, 0, 100},
{255, 255, 255, 100},
&UI_DEFAULT_FONT,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_inactive_title_filler,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_active_title_filler
};

/* theme color of title of scrren */
UI_window_title_theme MMI_thick_title_theme = { {255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{0, 0, 0, 100},
{255, 255, 255, 100},
&UI_DEFAULT_FONT,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_inactive_title_filler,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_active_title_filler
};

UI_window_title_theme MMI_tab_title_theme = { {255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{255, 255, 255, 100},
{0, 0, 0, 100},
{255, 255, 255, 100},
&UI_DEFAULT_FONT,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_inactive_title_filler,
(UI_filled_area *)&MMI_active_title_filler,
(UI_filled_area *)&MMI_active_title_filler
};

UI_dialer_input_box_theme MMI_dialer_inputbox_theme = { (UI_filled_area *)&MMI_inputbox_normal_filler,
    (UI_filled_area *)&MMI_inputbox_selected_filler,
    (UI_filled_area *)&MMI_inputbox_disabled_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &UI_DEFAULT_FONT,
    1,
    0,
    '*',
};

UI_button_theme MMI_drop_down_button_theme = { (UI_filled_area *)&MMI_drop_down_button_up_filler,
    (UI_filled_area *)&MMI_drop_down_button_down_filler,
    (UI_filled_area *)&MMI_drop_down_button_up_filler,
    (UI_filled_area *)&MMI_drop_down_button_down_filler,
    (UI_filled_area *)&MMI_drop_down_button_up_filler,
    (UI_filled_area *)&MMI_drop_down_button_down_filler,
    (UI_filled_area *)&MMI_drop_down_button_up_filler,
    (UI_filled_area *)&MMI_drop_down_button_down_filler,
};

UI_drop_down_control_theme MMI_drop_down_control_theme = { (UI_filled_area *)&MMI_drop_down_control_normal_filler,
    (UI_filled_area *)&MMI_drop_down_control_disabled_filler,
    (UI_filled_area *)&MMI_drop_down_control_focussed_filler,
    (UI_filled_area *)&MMI_drop_down_control_normal_filler,
    {0, 0, 0, 100},
    {64, 64, 64, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    &UI_DEFAULT_FONT,
    0,
    &MMI_drop_down_button_theme,
    UI_NULL_IMAGE
};

UI_information_bar_theme MMI_information_bar_theme = 
{
    {255, 255, 255, 100}
};

UI_EMS_input_box_theme MMI_EMS_inputbox_theme = { (UI_filled_area *)&MMI_inputbox_normal_filler,
    (UI_filled_area *)&MMI_inputbox_selected_filler,
    (UI_filled_area *)&MMI_inputbox_disabled_filler,
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    {255, 255, 0, 100},
    /* START PMT NEERAJ 20050916 */
    UI_EMS_INPUT_BOX_NEWLINE_DRAW | UI_EMS_INPUT_BOX_ALL_LINE_DRAW,
    /* END PMT NEERAJ 20050916 */
    5,
};

/* theme color of horizontal tab bar */
UI_horizontal_tab_bar_theme MMI_horizontal_tab_bar_theme = 
{
    (UI_filled_area *)&MMI_general_background_filler,
    &UI_DEFAULT_FONT,
    &UI_DEFAULT_FONT,
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    &UI_DEFAULT_FONT,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    4,
    0,
    (UI_filled_area *)&MMI_pop_up_description_filler,
    NULL,
    NULL,
    NULL,
    IMG_HORIZONTAL_NORMAL_TAB,
    IMG_HORIZONTAL_NORMAL_TAB,
    IMG_HORIZONTAL_NORMAL_TAB,
    NULL,
    NULL,
    NULL,
    IMG_HORIZONTAL_BLINKING_TAB,
    IMG_HORIZONTAL_BLINKING_TAB,
    IMG_HORIZONTAL_BLINKING_TAB,
    NULL,
    NULL,
    NULL,
    IMG_HORIZONTAL_FOCUSED_TAB,
    IMG_HORIZONTAL_FOCUSED_TAB,
    IMG_HORIZONTAL_FOCUSED_TAB,
    IMG_HORIZONTAL_TAB_L_ARROW,
    IMG_HORIZONTAL_TAB_R_ARROW
};

UI_pop_up_description_theme MMI_pop_up_description_theme = { {0, 0, 0, 100},
&UI_DEFAULT_FONT,
(UI_filled_area *)&MMI_pop_up_description_filler,
0
};

UI_virtual_keyboard_theme MMI_virtual_keyboard_theme = 
{
    (UI_filled_area *)&MMI_virtual_keyboard_filler,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    &MMI_virtual_keyboard_font,
    0
};

UI_ime_theme MMI_ime_theme = 
{
    {255,0,0,100},
    {255,0,0,100},
    {254,250,203,100},
    {255,255,255,100},
    {200,0,0,100},
    {200,200,200,100},
    {0,0,0,100},
    {246,0,1,100},
    {200,0,0,100},
    {255,255,255,100},
    {255,0,0,100},
    {0,0,0,100},
    &MMI_default_font,
    &MMI_small_font
};

UI_shortcut_box_theme MMI_shortcut_box_theme = 
{
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    MMI_FALSE
};

UI_clock_theme MMI_clock_theme = 
{
    #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
        &MMI_medium_font,
        &MMI_medium_font,
#else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
        &MMI_large_font,
        &MMI_large_font,
    #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__*/
    
    {0,0,0,100},
    {255,255,255,100},
    {0,0,0,100},
    {255,255,255,100},

#ifdef __MMI_SUBLCD__
    
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
        &MMI_large_font,
        &MMI_large_font,
#else /* __MMI_SUBLCD_DATE_LARGE_FONT__ */ 
        &MMI_small_font,
        &MMI_small_font,
#endif /* __MMI_SUBLCD_DATE_LARGE_FONT__ */ 

    #ifdef __MMI_SUB_WALLPAPER__
    {255,255,255,100},
    {0,0,0,100},
    {255,255,255,100},
    {0,0,0,100},
#else /* __MMI_SUB_WALLPAPER__ */ 
    {0,0,0,100},
    {0,0,0,100},
#endif /* __MMI_SUB_WALLPAPER__ */ 
    
#endif /* __MMI_SUBLCD__ */ 

    {0,0,0,100},
    {0,0,0,100},
    {0,0,0,100}
};

UI_calendar_theme MMI_calendar_theme = 
{
    {0, 0, 0, 255},
    {8, 93, 189, 255},
    {255, 255, 255, 255},
    {255, 255, 255, 255},
    {0, 0, 0, 255},
    {   
        {0, 0, 0, 255},
        {79, 249, 155, 255},
        {30, 49, 131, 255},
        {255, 70, 144, 255},
        {255, 126, 0, 255},
        {255, 234, 0, 255},
        {200, 200, 200, 255}  
    },
    {30, 49, 131, 255},
    {192, 192, 192, 255},
    {255, 0, 0, 255},    

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    {218, 229, 245, 255},
    {184, 207, 240, 255},
    {166, 27, 50, 255},
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)
    &MMI_medium_font,
#else 
    &MMI_small_font,
#endif
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 

#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)
    &MMI_sublcd_font,
    &MMI_sublcd_font
#else 
    &MMI_small_font,
    &MMI_small_font
#endif

};



/*****************************************************************************
 * FUNCTION
 *  gui_initialize_default_themes
 * DESCRIPTION
 *  Initializes the default themes
 *  
 *  Called once by the bootup sequence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_initialize_default_themes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_filled_area_border_theme = &MMI_filled_area_border_theme;
    current_button_theme = &MMI_button_theme;
    current_text_button_theme = &MMI_text_button_theme;
    current_icon_button_theme = &MMI_icon_button_theme;
    current_icontext_button_theme = &MMI_icontext_button_theme;
    current_multitap_input_theme = &MMI_multitap_input_theme;
    current_single_line_input_box_theme = &MMI_singleline_inputbox_theme;
    current_vertical_scrollbar_theme = &MMI_vertical_scrollbar_theme;
    current_horizontal_scrollbar_theme = &MMI_horizontal_scrollbar_theme;
    current_multi_line_input_box_theme = &MMI_multiline_inputbox_theme;
    current_horizontal_progress_indicator_theme = &MMI_hprogress_indicator_theme;
    current_vertical_progress_indicator_theme = &MMI_vprogress_indicator_theme;
    current_vertical_slide_theme = &MMI_vertical_slide_theme;
    current_horizontal_slide_theme = &MMI_horizontal_slide_theme;
    current_fixed_matrix_menu_theme = &MMI_fixed_matrix_menu_theme;
    current_fixed_list_menu_theme = &MMI_fixed_list_menu_theme;
    current_fixed_text_menuitem_theme = &MMI_fixed_text_menuitem_theme;
    current_fixed_icontext_menuitem_theme = &MMI_fixed_icontext_menuitem_theme;
    current_fixed_icontext_list_menuitem_theme = &MMI_fixed_icontext_list_menuitem_theme;
    current_fixed_twostate_menuitem_theme = &MMI_fixed_twostate_menuitem_theme;
    current_dialer_input_box_theme = &MMI_dialer_inputbox_theme;
    current_drop_down_control_theme = &MMI_drop_down_control_theme;
    current_information_bar_theme = &MMI_information_bar_theme;
    current_EMS_input_box_theme = &MMI_EMS_inputbox_theme;
    current_horizontal_tab_bar_theme = &MMI_horizontal_tab_bar_theme;
    current_virtual_keyboard_theme = &MMI_virtual_keyboard_theme;
#ifdef __MMI_CSTAR__
    current_ime_theme = &MMI_ime_theme;
#endif
    current_shortcut_box_theme = &MMI_shortcut_box_theme;
    current_clock_theme = &MMI_clock_theme;
    current_calendar_theme = & MMI_calendar_theme;
    current_window_title_theme = & MMI_window_title_theme;
    current_thick_title_theme = & MMI_thick_title_theme;
    current_tab_title_theme = & MMI_tab_title_theme;
}

UI_theme system_UI_theme = { &MMI_filled_area_border_theme,
    &MMI_button_theme,
    &MMI_text_button_theme,
    &MMI_icon_button_theme,
    &MMI_icontext_button_theme,
    &MMI_multitap_input_theme,
    &MMI_singleline_inputbox_theme,
    &MMI_multiline_inputbox_theme,
    &MMI_vertical_scrollbar_theme,
    &MMI_horizontal_scrollbar_theme,
    &MMI_hprogress_indicator_theme,
    &MMI_vprogress_indicator_theme,
    &MMI_vertical_slide_theme,
    &MMI_horizontal_slide_theme,
    &MMI_text_menuitem_theme,
    &MMI_icontext_menuitem_theme,
    &MMI_fixed_text_menuitem_theme,
    &MMI_fixed_icontext_menuitem_theme,
    &MMI_fixed_icontext_list_menuitem_theme,
    &MMI_fixed_twostate_menuitem_theme,
    &MMI_list_menu_theme,
    &MMI_fixed_list_menu_theme,
    &MMI_matrix_menu_theme,
    &MMI_fixed_matrix_menu_theme,
    &MMI_window_title_theme,
    &MMI_thick_title_theme,
    &MMI_tab_title_theme,
    &MMI_dialer_inputbox_theme,
    &MMI_drop_down_control_theme,
    &MMI_information_bar_theme,
    &MMI_EMS_inputbox_theme,
    &MMI_horizontal_tab_bar_theme,
    &MMI_virtual_keyboard_theme,
    &MMI_ime_theme,
    &MMI_shortcut_box_theme,
    &MMI_clock_theme,
    &MMI_calendar_theme
};

UI_theme *current_UI_theme = &system_UI_theme;

MMI_theme *current_MMI_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  get_MMI_font_type
 * DESCRIPTION
 *  get MMi font type
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  UI_font_type
 *****************************************************************************/
UI_font_type get_MMI_font_type(U8 t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (t)
    {
        case SMALL_FONT:
            return (&MMI_small_font);
        case MEDIUM_FONT:
            return (&MMI_medium_font);
        case LARGE_FONT:
            return (&MMI_large_font);
    }
    return (&MMI_default_font);
}

#if(0)

/*----------------------------------------------------------------------------
Function:			set_MMI_button_theme
Description:		Applies the theme for buttons
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_button_theme(MMI_theme *t)
{	current_UI_theme->button_theme->normal_up_filler=t->button_up_filler;
	current_UI_theme->button_theme->normal_down_filler=t->button_down_filler;
	current_UI_theme->button_theme->disabled_up_filler=t->button_disabled_filler;
	current_UI_theme->button_theme->disabled_down_filler=t->button_disabled_filler;
	current_UI_theme->button_theme->focussed_up_filler=t->button_focussed_filler;
	current_UI_theme->button_theme->focussed_down_filler=t->button_focussed_filler;
	current_UI_theme->button_theme->clicked_down_filler=t->button_focussed_filler;
	current_UI_theme->button_theme->clicked_up_filler=t->button_focussed_filler;
}

/*----------------------------------------------------------------------------
Function:			set_MMI_text_button_theme
Description:		Applies the theme for text buttons
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_text_button_theme(MMI_theme *t)
{	current_UI_theme->text_button_theme->normal_up_text_color=*t->button_up_text_color;
	current_UI_theme->text_button_theme->normal_down_text_color=*t->button_down_text_color;
	current_UI_theme->text_button_theme->disabled_up_text_color=*t->button_disabled_text_color;
	current_UI_theme->text_button_theme->disabled_down_text_color=*t->button_disabled_text_color;
	current_UI_theme->text_button_theme->focussed_up_text_color=*t->button_focussed_text_color;
	current_UI_theme->text_button_theme->focussed_down_text_color=*t->button_focussed_text_color;
	current_UI_theme->text_button_theme->clicked_down_text_color=*t->button_focussed_text_color;
	current_UI_theme->text_button_theme->clicked_up_text_color=*t->button_focussed_text_color;
	current_UI_theme->text_button_theme->text_font=(UI_font_type)(t->button_font);
}

/*----------------------------------------------------------------------------
Function:			set_MMI_icontext_button_theme
Description:		Applies the theme for icon text buttons
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_icontext_button_theme(MMI_theme *t)
{	current_UI_theme->icontext_button_theme->normal_up_filler=t->button_up_filler;
	current_UI_theme->icontext_button_theme->normal_down_filler=t->button_down_filler;
	current_UI_theme->icontext_button_theme->disabled_up_filler=t->button_disabled_filler;
	current_UI_theme->icontext_button_theme->disabled_down_filler=t->button_disabled_filler;
	current_UI_theme->icontext_button_theme->focussed_up_filler=t->button_focussed_filler;
	current_UI_theme->icontext_button_theme->focussed_down_filler=t->button_focussed_filler;
	current_UI_theme->icontext_button_theme->clicked_up_filler=t->button_focussed_filler;
	current_UI_theme->icontext_button_theme->clicked_down_filler=t->button_focussed_filler;
	current_UI_theme->icontext_button_theme->normal_up_text_color=*t->button_up_text_color;
	current_UI_theme->icontext_button_theme->normal_down_text_color=*t->button_down_text_color;
	current_UI_theme->icontext_button_theme->disabled_up_text_color=*t->button_disabled_text_color;
	current_UI_theme->icontext_button_theme->disabled_down_text_color=*t->button_disabled_text_color;
	current_UI_theme->icontext_button_theme->focussed_up_text_color=*t->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->focussed_down_text_color=*t->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->clicked_up_text_color=*t->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->clicked_down_text_color=*t->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->text_font=(UI_font_type)(t->button_font);
}

/*----------------------------------------------------------------------------
Function:			set_MMI_icon_button_theme
Description:		Applies the theme for icon buttons
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_icon_button_theme(MMI_theme *t)
{	current_UI_theme->icon_button_theme->normal_up_filler=t->button_up_filler;
	current_UI_theme->icon_button_theme->normal_down_filler=t->button_down_filler;
	current_UI_theme->icon_button_theme->disabled_up_filler=t->button_disabled_filler;
	current_UI_theme->icon_button_theme->disabled_down_filler=t->button_disabled_filler;
	current_UI_theme->icon_button_theme->focussed_up_filler=t->button_focussed_filler;
	current_UI_theme->icon_button_theme->focussed_down_filler=t->button_focussed_filler;
	current_UI_theme->icon_button_theme->clicked_up_filler=t->button_focussed_filler;
	current_UI_theme->icon_button_theme->clicked_down_filler=t->button_focussed_filler;
}

#endif /* (0) */ 


/*****************************************************************************
 * FUNCTION
 *  set_MMI_multitap_input_theme
 * DESCRIPTION
 *  Applies the theme for multitap objects
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_multitap_input_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->multitap_input_theme->f = t->multitap_filler;
    current_UI_theme->multitap_input_theme->normal_text_color = *t->multitap_normal_text_color;
    current_UI_theme->multitap_input_theme->selected_text_color = *t->multitap_selected_text_color;
    current_UI_theme->multitap_input_theme->selector_color = *t->multitap_selector_color;
    current_UI_theme->multitap_input_theme->text_font = (UI_font_type) (t->multitap_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_singleline_inputbox_theme
 * DESCRIPTION
 *  Applies the theme for singleline inputbox
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_singleline_inputbox_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->single_line_input_box_theme->normal_filler = t->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->disabled_filler = t->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->selected_filler = t->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->normal_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->disabled_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->selected_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->selection_color = *t->inputbox_selector_color;
    current_UI_theme->single_line_input_box_theme->selection_text_color = *t->inputbox_selected_text_color;
    current_UI_theme->single_line_input_box_theme->text_font = (UI_font_type) (t->inputbox_font);
    current_UI_theme->single_line_input_box_theme->cursor_color = *t->inputbox_cursor_color;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_multiline_inputbox_theme
 * DESCRIPTION
 *  Applies the theme for multiline inputbox
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_multiline_inputbox_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->multi_line_input_box_theme->normal_filler = t->inputbox_filler;
    current_UI_theme->multi_line_input_box_theme->disabled_filler = t->inputbox_filler;
    current_UI_theme->multi_line_input_box_theme->selected_filler = t->inputbox_filler;
    current_UI_theme->multi_line_input_box_theme->normal_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->multi_line_input_box_theme->disabled_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->multi_line_input_box_theme->selected_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->multi_line_input_box_theme->selection_color = *t->inputbox_selector_color;
    current_UI_theme->multi_line_input_box_theme->selection_text_color = *t->inputbox_selected_text_color;
    current_UI_theme->multi_line_input_box_theme->text_font = (UI_font_type) (t->inputbox_font);
    current_UI_theme->multi_line_input_box_theme->cursor_color = *t->inputbox_cursor_color;
    current_UI_theme->multi_line_input_box_theme->vbar_width = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_vertical_scrollbar_theme
 * DESCRIPTION
 *  Applies the theme for Vertical scrollbars
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_vertical_scrollbar_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->vertical_scrollbar_theme->normal_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->vertical_scrollbar_theme->disabled_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->vertical_scrollbar_theme->focussed_bar_filler = t->scrollbar_background_filler;

    current_UI_theme->vertical_scrollbar_theme->up_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->disabled_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->focussed_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->up_button_theme->clicked_down_filler = t->scrollbar_indicator_filler;

    current_UI_theme->vertical_scrollbar_theme->down_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->disabled_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->focussed_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->down_button_theme->clicked_down_filler = t->scrollbar_indicator_filler;

    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->disabled_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->focussed_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_scrollbar_theme->scroll_button_theme->clicked_down_filler =
        t->scrollbar_indicator_filler;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_horizontal_scrollbar_theme
 * DESCRIPTION
 *  Applies the theme for Horizontal scrollbars
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_horizontal_scrollbar_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->horizontal_scrollbar_theme->normal_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->horizontal_scrollbar_theme->disabled_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->horizontal_scrollbar_theme->focussed_bar_filler = t->scrollbar_background_filler;

    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->disabled_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->focussed_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->left_button_theme->clicked_down_filler =
        t->scrollbar_indicator_filler;

    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->normal_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->disabled_up_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->disabled_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->focussed_up_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->focussed_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->right_button_theme->clicked_down_filler =
        t->scrollbar_indicator_filler;

    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->normal_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->disabled_up_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->disabled_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->focussed_up_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->focussed_down_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->clicked_up_filler =
        t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_scrollbar_theme->scroll_button_theme->clicked_down_filler =
        t->scrollbar_indicator_filler;
}

#if(0)

/*----------------------------------------------------------------------------
Function:			set_MMI_horizontal_progress_indicator_theme
Description:		Applies the theme for Horizontal Progress Indicators
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_horizontal_progress_indicator_theme(MMI_theme *t)
{	current_UI_theme->horizontal_progress_indicator_theme->background_filler=t->progress_indicator_background_filler;
	current_UI_theme->horizontal_progress_indicator_theme->foreground_filler=t->progress_indicator_fillers;
	current_UI_theme->horizontal_progress_indicator_theme->percentages=t->progress_indicator_percentages;
	current_UI_theme->horizontal_progress_indicator_theme->n_fillers=t->progress_indicator_n_fillers;
}

/*----------------------------------------------------------------------------
Function:			set_MMI_vertical_progress_indicator_theme
Description:		Applies the theme for Vertical Progress Indicators
Input Parameters:	t		is the MMI_theme
Output Parameters:	none
Returns:			void
Remarks:			See MMI_theme structure
----------------------------------------------------------------------------*/

void set_MMI_vertical_progress_indicator_theme(MMI_theme *t)
{	current_UI_theme->vertical_progress_indicator_theme->background_filler=t->progress_indicator_background_filler;
	current_UI_theme->vertical_progress_indicator_theme->foreground_filler=t->progress_indicator_fillers;
	current_UI_theme->vertical_progress_indicator_theme->percentages=t->progress_indicator_percentages;
	current_UI_theme->vertical_progress_indicator_theme->n_fillers=t->progress_indicator_n_fillers;
}

#endif /* (0) */ 


/*****************************************************************************
 * FUNCTION
 *  set_MMI_vertical_slide_theme
 * DESCRIPTION
 *  Applies the theme for Vertical scrollbars
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_vertical_slide_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->vertical_slide_theme->normal_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->vertical_slide_theme->disabled_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->vertical_slide_theme->focussed_bar_filler = t->scrollbar_background_filler;

    current_UI_theme->vertical_slide_theme->scroll_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->disabled_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->focussed_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->vertical_slide_theme->scroll_button_theme->clicked_down_filler = t->scrollbar_indicator_filler;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_horizontal_slide_theme
 * DESCRIPTION
 *  Applies the theme for Vertical scrollbars
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_horizontal_slide_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->horizontal_slide_theme->normal_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->horizontal_slide_theme->disabled_bar_filler = t->scrollbar_background_filler;
    current_UI_theme->horizontal_slide_theme->focussed_bar_filler = t->scrollbar_background_filler;

    current_UI_theme->horizontal_slide_theme->scroll_button_theme->normal_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->normal_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->disabled_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->disabled_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->focussed_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->focussed_down_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->clicked_up_filler = t->scrollbar_indicator_filler;
    current_UI_theme->horizontal_slide_theme->scroll_button_theme->clicked_down_filler = t->scrollbar_indicator_filler;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_text_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for Text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_text_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->text_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->text_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->text_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->text_menuitem_theme->selected_filler = t->list_selected_item_filler;
    current_UI_theme->text_menuitem_theme->normal_text_color = *t->list_normal_text_color;
    current_UI_theme->text_menuitem_theme->disabled_text_color = *t->list_disabled_text_color;
    current_UI_theme->text_menuitem_theme->focussed_text_color = *t->list_selected_text_color;
    current_UI_theme->text_menuitem_theme->selected_text_color = *t->list_selected_text_color;
    current_UI_theme->text_menuitem_theme->text_font = (UI_font_type) (t->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_text_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for Text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_text_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->text_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->text_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->text_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->text_menuitem_theme->selected_filler = t->matrix_selected_item_filler;
    current_UI_theme->text_menuitem_theme->normal_text_color = *t->matrix_normal_text_color;
    current_UI_theme->text_menuitem_theme->disabled_text_color = *t->matrix_disabled_text_color;
    current_UI_theme->text_menuitem_theme->focussed_text_color = *t->matrix_selected_text_color;
    current_UI_theme->text_menuitem_theme->selected_text_color = *t->matrix_selected_text_color;
    current_UI_theme->text_menuitem_theme->text_font = (UI_font_type) (t->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_text_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for Fixed Text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_text_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_text_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->selected_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->normal_text_color = *t->list_normal_text_color;
    current_UI_theme->fixed_text_menuitem_theme->disabled_text_color = *t->list_disabled_text_color;
    current_UI_theme->fixed_text_menuitem_theme->focussed_text_color = *t->list_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->selected_text_color = *t->list_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->text_font = (UI_font_type) (t->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_text_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for Fixed Text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_text_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_text_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->selected_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->normal_text_color = *t->matrix_normal_text_color;
    current_UI_theme->fixed_text_menuitem_theme->disabled_text_color = *t->matrix_disabled_text_color;
    current_UI_theme->fixed_text_menuitem_theme->focussed_text_color = *t->matrix_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->selected_text_color = *t->matrix_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->text_font = (UI_font_type) (t->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_icontext_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for IconText menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_icontext_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->icontext_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->icontext_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->selected_filler = t->list_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->normal_text_color = *t->list_normal_text_color;
    current_UI_theme->icontext_menuitem_theme->disabled_text_color = *t->list_disabled_text_color;
    current_UI_theme->icontext_menuitem_theme->focussed_text_color = *t->list_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->selected_text_color = *t->list_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->text_font = (UI_font_type) (t->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  change_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void change_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fontSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontSize = PhnsetGetFontSize();

    switch (fontSize)
    {
        case THEME_DEFAULT:
            MMI_default_font.size = MEDIUM_FONT;
            break;
        case SMALL:
            MMI_default_font.size = SMALL_FONT;
            break;

        case MEDIUM:
            MMI_default_font.size = MEDIUM_FONT;
            break;
        case LARGE:
            MMI_default_font.size = LARGE_FONT;
            break;

        default:
            MMI_default_font.size = MEDIUM_FONT;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  change_font_Theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void change_font_Theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fontSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontSize = PhnsetGetFontSize();

    switch (fontSize)
    {
        case THEME_DEFAULT:
            MMI_default_font.size = MEDIUM_FONT;
            break;
        case SMALL:
            MMI_default_font.size = SMALL_FONT;
            break;

        case MEDIUM:
            MMI_default_font.size = MEDIUM_FONT;
            break;
        case LARGE:
            MMI_default_font.size = LARGE_FONT;
            break;

        default:
            MMI_default_font.size = MEDIUM_FONT;
            break;
    }
    MMI_apply_current_theme();  /* apply current theme */
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_icontext_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for IconText menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_icontext_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->icontext_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->icontext_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->selected_filler = t->matrix_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->normal_text_color = *t->matrix_normal_text_color;
    current_UI_theme->icontext_menuitem_theme->disabled_text_color = *t->matrix_disabled_text_color;
    current_UI_theme->icontext_menuitem_theme->focussed_text_color = *t->matrix_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->selected_text_color = *t->matrix_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->text_font = (UI_font_type) (t->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_icontext_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for Fixed IconText menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_icontext_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *t->list_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color = *t->list_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color = *t->list_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color = *t->list_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (t->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_icontext_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for Fixed IconText menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_icontext_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *t->matrix_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color = *t->matrix_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color = *t->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color = *t->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (t->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_icontext_list_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for Fixed IconText List menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_icontext_list_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_list_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->selected_filler = t->list_selected_item_filler;
    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS; i++)
    {
        current_UI_theme->fixed_icontext_list_menuitem_theme->normal_text_colors[i] = *t->list_normal_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_text_colors[i] = *t->list_disabled_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_text_colors[i] = *t->list_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->selected_text_colors[i] = *t->list_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->text_fonts[i] = (UI_font_type) (t->list_menu_font);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_icontext_list_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for Fixed IconText List menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_icontext_list_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_list_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->selected_filler = t->matrix_selected_item_filler;
    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS; i++)
    {
        current_UI_theme->fixed_icontext_list_menuitem_theme->normal_text_colors[i] = *t->matrix_normal_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_text_colors[i] = *t->matrix_disabled_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_text_colors[i] = *t->matrix_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->selected_text_colors[i] = *t->matrix_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->text_fonts[i] = (UI_font_type) (t->matrix_menu_font);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_twostate_menuitem_theme_list
 * DESCRIPTION
 *  Applies the List theme for Fixed Twostate menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_twostate_menuitem_theme_list(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_twostate_menuitem_theme->normal_filler = t->list_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_filler = t->list_disabled_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_filler = t->list_selected_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_filler = t->list_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->normal_text_color = *t->list_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_text_color = *t->list_disabled_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_text_color = *t->list_selected_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_text_color = *t->list_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->text_font = (UI_font_type) (t->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_twostate_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the Matrix theme for Fixed Twostate menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_twostate_menuitem_theme_matrix(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_twostate_menuitem_theme->normal_filler = t->matrix_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_filler = t->matrix_disabled_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_filler = t->matrix_selected_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_filler = t->matrix_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->normal_text_color = *t->matrix_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_text_color = *t->matrix_disabled_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_text_color = *t->matrix_selected_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_text_color = *t->matrix_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->text_font = (UI_font_type) (t->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_text_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_text_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->text_menuitem_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    current_UI_theme->text_menuitem_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;
    current_UI_theme->text_menuitem_theme->focussed_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->text_menuitem_theme->selected_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->text_menuitem_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    current_UI_theme->text_menuitem_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    current_UI_theme->text_menuitem_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->text_menuitem_theme->selected_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->text_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_text_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_text_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->text_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->text_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->text_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->text_menuitem_theme->selected_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->text_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->text_menuitem_theme->disabled_text_color = *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->text_menuitem_theme->focussed_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->text_menuitem_theme->selected_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->text_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_text_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for Fixed text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_text_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *highlight_filler;
    UI_fixed_text_menuitem_theme *text_mi_theme;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_mi_theme = current_UI_theme->fixed_text_menuitem_theme;
    
    text_mi_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    text_mi_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;

    /* use orginal highlight filler under rotation */
#ifdef __MMI_SCREEN_ROTATE__
     if (mmi_frm_is_screen_width_height_swapped())
    {
        highlight_filler = current_MMI_theme->list_selected_item_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        highlight_filler = current_MMI_theme->menuitem_single_line_highlight_filler;
    }
      
    text_mi_theme->focussed_filler = highlight_filler;
    text_mi_theme->selected_filler = highlight_filler;
    
    text_mi_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    text_mi_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    text_mi_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    text_mi_theme->selected_text_color = *current_MMI_theme->list_selected_text_color;
    text_mi_theme->text_font = (UI_font_type) (current_MMI_theme->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_text_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for Fixed text menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_text_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_text_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->selected_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_text_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->fixed_text_menuitem_theme->disabled_text_color = *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->fixed_text_menuitem_theme->focussed_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->selected_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_text_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_icontext_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for icontext menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_icontext_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_menuitem_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    current_UI_theme->icontext_menuitem_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;
    current_UI_theme->icontext_menuitem_theme->focussed_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->selected_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    current_UI_theme->icontext_menuitem_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    current_UI_theme->icontext_menuitem_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->selected_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_icontext_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for icontext menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_icontext_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->icontext_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->icontext_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->selected_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->icontext_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->icontext_menuitem_theme->disabled_text_color = *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->icontext_menuitem_theme->focussed_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->selected_text_color = *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_icontext_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for Fixed icontext menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_icontext_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *highlight_filler;
    UI_fixed_icontext_menuitem_theme *icontext_mi_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icontext_mi_theme = current_UI_theme->fixed_icontext_menuitem_theme;

    icontext_mi_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    icontext_mi_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;

    /* use the orginal highlight filler under rotation */
#ifdef __MMI_SCREEN_ROTATE__
     if (mmi_frm_is_screen_width_height_swapped())
    {
        highlight_filler = current_MMI_theme->list_selected_item_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        highlight_filler = current_MMI_theme->menuitem_single_line_highlight_filler;
    }

    icontext_mi_theme->focussed_filler = highlight_filler;
    icontext_mi_theme->selected_filler = highlight_filler;

    icontext_mi_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    icontext_mi_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    icontext_mi_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    icontext_mi_theme->selected_text_color = *current_MMI_theme->list_selected_text_color;
    
    icontext_mi_theme->text_font = (UI_font_type) (current_MMI_theme->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_icontext_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for Fixed icontext menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_icontext_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color =
        *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color =
        *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color =
        *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_icontext_menuitem_theme_matrix_bidegree_menu
 * DESCRIPTION
 *  Applies the current Matrix theme for Fixed icontext menuitems in bidgree menu 
 *
 *  Note: `matrix_main_menu_normal_item_filler', `matrix_main_menu_selected_item_filler', etc are used in 
 *  bi-degree menu instead of matrix main menu because matrix main menu does not have text in each menu item
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_icontext_menuitem_theme_matrix_bidegree_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->matrix_main_menu_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->matrix_main_menu_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->matrix_main_menu_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->matrix_main_menu_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_main_menu_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color =
        *current_MMI_theme->matrix_main_menu_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color =
        *current_MMI_theme->matrix_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color =
        *current_MMI_theme->matrix_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_icontext_list_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for Fixed icontext List menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_icontext_list_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_font_type text_font;
    UI_filled_area *highlight_filler;
    UI_fixed_icontext_list_menuitem_theme *icontext_list_mi_theme;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icontext_list_mi_theme = current_UI_theme->fixed_icontext_list_menuitem_theme;

    icontext_list_mi_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    icontext_list_mi_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;

    /* use orginal highlight filler under rotation */
#ifdef __MMI_SCREEN_ROTATE__
     if (mmi_frm_is_screen_width_height_swapped())
    {
        highlight_filler = current_MMI_theme->list_selected_item_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        highlight_filler = current_MMI_theme->menuitem_single_line_highlight_filler;
    }
    
    icontext_list_mi_theme->focussed_filler = highlight_filler;
    icontext_list_mi_theme->selected_filler = highlight_filler;

    if (MMI_fixed_icontext_list_menuitem.flags & MENU_MUTLIROW_ICON_LIST)
    {
        text_font = (UI_font_type)&MMI_small_font;
    }
    else
    {
        text_font = (UI_font_type)current_MMI_theme->list_menu_font;
    }

    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS; i++)
    {
        icontext_list_mi_theme->normal_text_colors[i] = *current_MMI_theme->list_normal_text_color;
        icontext_list_mi_theme->disabled_text_colors[i] = *current_MMI_theme->list_disabled_text_color;
        icontext_list_mi_theme->focussed_text_colors[i] = *current_MMI_theme->list_selected_text_color;
        icontext_list_mi_theme->selected_text_colors[i] = *current_MMI_theme->list_selected_text_color;
        icontext_list_mi_theme->text_fonts[i] = text_font;
    }    

    /* if the menuitem is multirow, the first text font is the list menu font. */
    if (MMI_fixed_icontext_list_menuitem.flags & MENU_MUTLIROW_ICON_LIST)
    {
        icontext_list_mi_theme->text_fonts[0] = (UI_font_type)current_MMI_theme->list_menu_font;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_icontext_list_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for Fixed icontext List menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_icontext_list_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_list_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_filler =
        current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_filler =
        current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_list_menuitem_theme->selected_filler =
        current_MMI_theme->matrix_selected_item_filler;
    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS; i++)
    {
        current_UI_theme->fixed_icontext_list_menuitem_theme->normal_text_colors[i] =
            *current_MMI_theme->matrix_normal_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->disabled_text_colors[i] =
            *current_MMI_theme->matrix_disabled_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->focussed_text_colors[i] =
            *current_MMI_theme->matrix_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->selected_text_colors[i] =
            *current_MMI_theme->matrix_selected_text_color;
        current_UI_theme->fixed_icontext_list_menuitem_theme->text_fonts[i] =
            (UI_font_type) (current_MMI_theme->matrix_menu_font);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_twostate_menuitem_theme_list
 * DESCRIPTION
 *  Applies the current List theme for Fixed Twostate menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_twostate_menuitem_theme_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *highlight_filler;
    UI_fixed_twostate_menuitem_theme *twostate_mi_theme;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    twostate_mi_theme = current_UI_theme->fixed_twostate_menuitem_theme;
    
    twostate_mi_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    twostate_mi_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;

    /* use orginal highlight filler under rotation */
#ifdef __MMI_SCREEN_ROTATE__
     if (mmi_frm_is_screen_width_height_swapped())
    {
        highlight_filler = current_MMI_theme->list_selected_item_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        highlight_filler = current_MMI_theme->menuitem_single_line_highlight_filler;
    }

    twostate_mi_theme->focussed_filler = highlight_filler;

    twostate_mi_theme->selected_filler = current_MMI_theme->list_normal_item_filler;
    twostate_mi_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    twostate_mi_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    twostate_mi_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    twostate_mi_theme->selected_text_color = *current_MMI_theme->list_normal_text_color;
    twostate_mi_theme->text_font = (UI_font_type)(current_MMI_theme->list_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_current_fixed_twostate_menuitem_theme_matrix
 * DESCRIPTION
 *  Applies the current Matrix theme for Fixed Twostate menuitems
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_current_fixed_twostate_menuitem_theme_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_twostate_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_twostate_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->disabled_text_color =
        *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->focussed_text_color =
        *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->selected_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->fixed_twostate_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_list_menu_theme
 * DESCRIPTION
 *  Applies the theme for list menu
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_list_menu_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->list_menu_theme->normal_filler = t->list_background_filler;
    current_UI_theme->list_menu_theme->focussed_filler = t->list_background_filler;
    current_UI_theme->list_menu_theme->vbar_width = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_list_menu_theme
 * DESCRIPTION
 *  Applies the theme for Fixed list menu
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_list_menu_theme(MMI_theme *t)
{
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        current_UI_theme->fixed_list_menu_theme->normal_filler = (UI_filled_area*)&MMI_rotated_menu_background_filler;
        current_UI_theme->fixed_list_menu_theme->focussed_filler =
            (UI_filled_area*)&MMI_rotated_menu_background_filler;
    }
    else
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    {
        current_UI_theme->fixed_list_menu_theme->normal_filler = t->list_background_filler;
        current_UI_theme->fixed_list_menu_theme->focussed_filler = t->list_background_filler;
    }
    current_UI_theme->fixed_list_menu_theme->vbar_width = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_matrix_menu_theme
 * DESCRIPTION
 *  Applies the theme for matrix menu
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_matrix_menu_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->matrix_menu_theme->normal_filler = t->matrix_background_filler;
    current_UI_theme->matrix_menu_theme->focussed_filler = t->matrix_background_filler;
    current_UI_theme->matrix_menu_theme->vbar_width = t->scrollbar_size;
    current_UI_theme->matrix_menu_theme->hbar_height = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_fixed_matrix_menu_theme
 * DESCRIPTION
 *  Applies the theme for Fixed matrix menu
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_fixed_matrix_menu_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_matrix_menu_theme->normal_filler = t->matrix_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->focussed_filler = t->matrix_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->vbar_width = t->scrollbar_size;
    current_UI_theme->fixed_matrix_menu_theme->hbar_height = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_window_title_theme
 * DESCRIPTION
 *  Applies the theme for the Window title
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_window_title_theme(MMI_theme *t)
{
#ifdef __MMI_SCREEN_ROTATE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        MMI_rotated_title_background_filler.b = (PU8) GetImage(IMG_SCREEN_ROTATE_TITLE);
        current_UI_theme->window_title_theme->active_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->window_title_theme->inactive_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->window_title_theme->focussed_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->window_title_theme->selected_filler = &MMI_rotated_title_background_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
    {
        current_UI_theme->window_title_theme->active_filler = t->title_filler;
        current_UI_theme->window_title_theme->inactive_filler = t->title_filler;
        current_UI_theme->window_title_theme->focussed_filler = t->title_filler;
        current_UI_theme->window_title_theme->selected_filler = t->title_filler;
    }
    current_UI_theme->window_title_theme->active_text_color = *t->title_text_color;
    current_UI_theme->window_title_theme->inactive_text_color = *t->title_text_color;
    current_UI_theme->window_title_theme->focussed_text_color = *t->title_text_color;
    current_UI_theme->window_title_theme->selected_text_color = *t->title_text_color;
    current_UI_theme->window_title_theme->shortcut_text_color = *t->title_shortcut_text_color;
    current_UI_theme->window_title_theme->text_border_color = *t->title_text_border_color; 
    current_UI_theme->window_title_theme->text_font = (UI_font_type) (t->window_title_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_thick_title_theme
 * DESCRIPTION
 *  Applies the theme for the thick title
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_thick_title_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->thick_title_theme->active_filler = t->thick_title_filler;
    current_UI_theme->thick_title_theme->inactive_filler = t->thick_title_filler;
    current_UI_theme->thick_title_theme->focussed_filler = t->thick_title_filler;
    current_UI_theme->thick_title_theme->selected_filler = t->thick_title_filler;
    if (t->thick_title_text_color)
    {
        current_UI_theme->thick_title_theme->active_text_color = *t->thick_title_text_color;
        current_UI_theme->thick_title_theme->inactive_text_color = *t->thick_title_text_color;
        current_UI_theme->thick_title_theme->focussed_text_color = *t->thick_title_text_color;
        current_UI_theme->thick_title_theme->selected_text_color = *t->thick_title_text_color;
    }
    if (t->thick_title_shortcut_text_color)
    {
        current_UI_theme->thick_title_theme->shortcut_text_color = *t->thick_title_shortcut_text_color;
    }
    if (t->thick_title_text_border_color)
    {
        current_UI_theme->thick_title_theme->text_border_color = *t->thick_title_text_border_color; 
    }
    current_UI_theme->thick_title_theme->text_font = (UI_font_type) (t->window_title_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_tab_title_theme
 * DESCRIPTION
 *  Applies the theme for the Window title
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_tab_title_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        current_UI_theme->tab_title_theme->active_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->tab_title_theme->inactive_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->tab_title_theme->focussed_filler = &MMI_rotated_title_background_filler;
        current_UI_theme->tab_title_theme->selected_filler = &MMI_rotated_title_background_filler;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
    {
        current_UI_theme->tab_title_theme->active_filler = t->tab_title_filler;
        current_UI_theme->tab_title_theme->inactive_filler = t->tab_title_filler;
        current_UI_theme->tab_title_theme->focussed_filler = t->tab_title_filler;
        current_UI_theme->tab_title_theme->selected_filler = t->tab_title_filler;
    }
    current_UI_theme->tab_title_theme->active_text_color = *t->tab_title_text_color;
    current_UI_theme->tab_title_theme->inactive_text_color = *t->tab_title_text_color;
    current_UI_theme->tab_title_theme->focussed_text_color = *t->tab_title_text_color;
    current_UI_theme->tab_title_theme->selected_text_color = *t->tab_title_text_color;
    current_UI_theme->tab_title_theme->shortcut_text_color = *t->tab_title_shortcut_text_color;
    current_UI_theme->tab_title_theme->text_border_color = *t->tab_title_text_border_color;    
    current_UI_theme->tab_title_theme->text_font = (UI_font_type) (t->tab_title_text_font);
}



/*****************************************************************************
 * FUNCTION
 *  set_MMI_dialer_inputbox_theme
 * DESCRIPTION
 *  Applies the theme for dialer inputbox
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_dialer_inputbox_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->dialer_inputbox_theme->normal_filler = t->dialer_inputbox_background_filler;
    current_UI_theme->dialer_inputbox_theme->disabled_filler = t->dialer_inputbox_background_filler;
    current_UI_theme->dialer_inputbox_theme->selected_filler = t->dialer_inputbox_background_filler;
    current_UI_theme->dialer_inputbox_theme->normal_text_color = *t->dialer_inputbox_normal_text_color;
    current_UI_theme->dialer_inputbox_theme->disabled_text_color = *t->dialer_inputbox_normal_text_color;
    current_UI_theme->dialer_inputbox_theme->selected_text_color = *t->dialer_inputbox_normal_text_color;
    current_UI_theme->dialer_inputbox_theme->selection_color = *t->dialer_inputbox_selector_color;
    current_UI_theme->dialer_inputbox_theme->selection_text_color = *t->dialer_inputbox_selected_text_color;
    current_UI_theme->dialer_inputbox_theme->text_font = (UI_font_type) (t->inputbox_font);
    current_UI_theme->dialer_inputbox_theme->cursor_color = *t->dialer_inputbox_cursor_color;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_drop_down_control_theme
 * DESCRIPTION
 *  Applies the theme for drop down control
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_drop_down_control_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->drop_down_control_theme->normal_filler = t->list_background_filler;
    current_UI_theme->drop_down_control_theme->disabled_filler = t->list_background_filler;
    current_UI_theme->drop_down_control_theme->focussed_filler = t->list_background_filler;
    current_UI_theme->drop_down_control_theme->clicked_filler = t->list_background_filler;
    current_UI_theme->drop_down_control_theme->normal_text_color = *t->drop_down_normal_text_color;
    current_UI_theme->drop_down_control_theme->disabled_text_color = *t->drop_down_disabled_text_color;
    current_UI_theme->drop_down_control_theme->focussed_text_color = *t->drop_down_focussed_text_color;
    current_UI_theme->drop_down_control_theme->clicked_text_color = *t->drop_down_normal_text_color;
    current_UI_theme->drop_down_control_theme->text_font = (UI_font_type) (t->drop_down_control_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_information_bar_theme
 * DESCRIPTION
 *  Applies the theme for information bar
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_information_bar_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->information_bar_theme->background_color = *(t->information_bar_color);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_EMS_inputbox_theme
 * DESCRIPTION
 *  Applies the theme for EMS inputbox
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_EMS_inputbox_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->EMS_inputbox_theme->normal_filler = t->inputbox_filler;
    current_UI_theme->EMS_inputbox_theme->disabled_filler = t->inputbox_filler;
    current_UI_theme->EMS_inputbox_theme->selected_filler = t->inputbox_filler;
    current_UI_theme->EMS_inputbox_theme->normal_text_color = *t->inputbox_normal_text_color;
    current_UI_theme->EMS_inputbox_theme->selected_text_color = *t->inputbox_selected_text_color;
    current_UI_theme->EMS_inputbox_theme->selection_color = *t->inputbox_selector_color;
    current_UI_theme->EMS_inputbox_theme->cursor_color = *t->inputbox_cursor_color;
    current_UI_theme->EMS_inputbox_theme->vbar_width = t->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_horizontal_tab_bar_theme
 * DESCRIPTION
 *  Applies the theme for horizontal tab bar
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_horizontal_tab_bar_theme(MMI_theme *t)
{
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->horizontal_tab_bar_theme->background_filler =
        (UI_filled_area*)&MMI_transparent_background_filler;
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
    current_UI_theme->horizontal_tab_bar_theme->background_filler = t->general_background_filler;
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
    current_UI_theme->horizontal_tab_bar_theme->hint_text_font = t->window_title_font;
    current_UI_theme->horizontal_tab_bar_theme->hint_text_color = *t->title_text_color;
    current_UI_theme->horizontal_tab_bar_theme->hint_text_border_color = *t->title_text_border_color;
    current_UI_theme->horizontal_tab_bar_theme->normal_tab_filler = t->tab_normal_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->normal_l_tab_filler = t->tab_normal_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->normal_r_tab_filler = t->tab_normal_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->focused_tab_filler = t->tab_highlight_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->focused_l_tab_filler = t->tab_highlight_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->focused_r_tab_filler = t->tab_highlight_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->blinking_tab_filler = t->tab_blink_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->blinking_l_tab_filler = t->tab_blink_tab_filler;
    current_UI_theme->horizontal_tab_bar_theme->blinking_r_tab_filler = t->tab_blink_tab_filler;
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)
    current_UI_theme->horizontal_tab_bar_theme->hint_bg_image = IMG_HORIZONTAL_TAB_HINT_AREA;
#else 
    current_UI_theme->horizontal_tab_bar_theme->hint_bg_image = 0;
#endif 
    current_UI_theme->horizontal_tab_bar_theme->hint_filler = t->title_filler;
}

/*    Helper functions  */


/*****************************************************************************
 * FUNCTION
 *  set_MMI_singleline_inputbox_shortcut_indicator_theme
 * DESCRIPTION
 *  set mmi single input box shortcut indiactor theme
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_singleline_inputbox_shortcut_indicator_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_singleline_inputbox_regular_theme
 * DESCRIPTION
 *  set  single input box theme to current theme
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_singleline_inputbox_regular_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->single_line_input_box_theme->normal_filler = current_MMI_theme->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->disabled_filler = current_MMI_theme->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->selected_filler = current_MMI_theme->inputbox_filler;
    current_UI_theme->single_line_input_box_theme->normal_text_color = *current_MMI_theme->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->disabled_text_color = *current_MMI_theme->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->selected_text_color = *current_MMI_theme->inputbox_normal_text_color;
    current_UI_theme->single_line_input_box_theme->selection_color = *current_MMI_theme->inputbox_selector_color;
    current_UI_theme->single_line_input_box_theme->selection_text_color =
        *current_MMI_theme->inputbox_selected_text_color;
    current_UI_theme->single_line_input_box_theme->text_font = (UI_font_type) (current_MMI_theme->inputbox_font);
    current_UI_theme->single_line_input_box_theme->cursor_color = *current_MMI_theme->inputbox_cursor_color;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_LSK_theme
 * DESCRIPTION
 *  set  lsk theme equal to current theme of button
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//PMT VIKAS START 20050707 
// Changes for enabling of flags for Dalmatian status bar and softkey.

#if defined(__MMI_UI_DALMATIAN_SOFTKEYS__)
UI_filled_area Dalmatiian_LSK_up;
UI_filled_area Dalmatiian_LSK_down;
#endif /* defined(__MMI_UI_DALMATIAN_SOFTKEYS__) */ 
//PMT VIKAS END 20050707 
//lsk
void set_MMI_LSK_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_button_theme->normal_up_filler = NULL;
    current_UI_theme->icontext_button_theme->normal_down_filler = NULL;
    current_UI_theme->icontext_button_theme->disabled_up_filler = NULL;
    current_UI_theme->icontext_button_theme->disabled_down_filler = NULL;
    current_UI_theme->icontext_button_theme->focussed_up_filler = NULL;
    current_UI_theme->icontext_button_theme->focussed_down_filler = NULL;
    current_UI_theme->icontext_button_theme->clicked_up_filler = NULL;
    current_UI_theme->icontext_button_theme->clicked_down_filler = NULL;
    current_UI_theme->icontext_button_theme->normal_up_text_color = *current_MMI_theme->LSK_up_text_color;
    current_UI_theme->icontext_button_theme->normal_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->normal_down_text_color = *current_MMI_theme->LSK_down_text_color;
    current_UI_theme->icontext_button_theme->normal_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->disabled_up_text_color = *current_MMI_theme->LSK_up_text_color;
    current_UI_theme->icontext_button_theme->disabled_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->disabled_down_text_color = *current_MMI_theme->LSK_down_text_color;
    current_UI_theme->icontext_button_theme->disabled_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->focussed_up_text_color = *current_MMI_theme->LSK_up_text_color;
    current_UI_theme->icontext_button_theme->focussed_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->focussed_down_text_color = *current_MMI_theme->LSK_down_text_color;
    current_UI_theme->icontext_button_theme->focussed_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->clicked_up_text_color = *current_MMI_theme->LSK_up_text_color;
    current_UI_theme->icontext_button_theme->clicked_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->clicked_down_text_color = *current_MMI_theme->LSK_down_text_color;
    current_UI_theme->icontext_button_theme->clicked_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->text_font = (UI_font_type) (current_MMI_theme->button_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_RSK_theme
 * DESCRIPTION
 *  set  rsk theme equal to current theme of button
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_RSK_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->icontext_button_theme->normal_up_filler = NULL;
    current_UI_theme->icontext_button_theme->normal_down_filler = NULL;
    current_UI_theme->icontext_button_theme->disabled_up_filler = NULL;
    current_UI_theme->icontext_button_theme->disabled_down_filler = NULL;
    current_UI_theme->icontext_button_theme->focussed_up_filler = NULL;
    current_UI_theme->icontext_button_theme->focussed_down_filler = NULL;
    current_UI_theme->icontext_button_theme->clicked_up_filler = NULL;
    current_UI_theme->icontext_button_theme->clicked_down_filler = NULL;
    current_UI_theme->icontext_button_theme->normal_up_text_color = *current_MMI_theme->RSK_up_text_color;
    current_UI_theme->icontext_button_theme->normal_down_text_color = *current_MMI_theme->RSK_down_text_color;
    current_UI_theme->icontext_button_theme->disabled_up_text_color = *current_MMI_theme->RSK_up_text_color;
    current_UI_theme->icontext_button_theme->disabled_down_text_color = *current_MMI_theme->RSK_down_text_color;
    current_UI_theme->icontext_button_theme->focussed_up_text_color = *current_MMI_theme->RSK_up_text_color;
    current_UI_theme->icontext_button_theme->focussed_down_text_color = *current_MMI_theme->RSK_down_text_color;
    current_UI_theme->icontext_button_theme->clicked_up_text_color = *current_MMI_theme->RSK_up_text_color;
    current_UI_theme->icontext_button_theme->clicked_down_text_color = *current_MMI_theme->RSK_down_text_color;
    current_UI_theme->icontext_button_theme->normal_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->normal_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->disabled_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->disabled_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->focussed_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->focussed_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->clicked_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->clicked_down_text_border_color = *current_MMI_theme->softkey_text_border_color;
    current_UI_theme->icontext_button_theme->text_font = (UI_font_type) (current_MMI_theme->button_font);
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_regular_button_theme
 * DESCRIPTION
 *  set  button  theme equal to current theme of button
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_regular_button_theme(void)
{
#if(0)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	current_UI_theme->icontext_button_theme->normal_up_filler=current_MMI_theme->button_up_filler;
	current_UI_theme->icontext_button_theme->normal_down_filler=current_MMI_theme->button_down_filler;
	current_UI_theme->icontext_button_theme->disabled_up_filler=current_MMI_theme->button_disabled_filler;
	current_UI_theme->icontext_button_theme->disabled_down_filler=current_MMI_theme->button_disabled_filler;
	current_UI_theme->icontext_button_theme->focussed_up_filler=current_MMI_theme->button_focussed_filler;
	current_UI_theme->icontext_button_theme->focussed_down_filler=current_MMI_theme->button_focussed_filler;
	current_UI_theme->icontext_button_theme->clicked_up_filler=current_MMI_theme->button_focussed_filler;
	current_UI_theme->icontext_button_theme->clicked_down_filler=current_MMI_theme->button_focussed_filler;
	current_UI_theme->icontext_button_theme->normal_up_text_color=*current_MMI_theme->button_up_text_color;
	current_UI_theme->icontext_button_theme->normal_down_text_color=*current_MMI_theme->button_down_text_color;
	current_UI_theme->icontext_button_theme->disabled_up_text_color=*current_MMI_theme->button_disabled_text_color;
	current_UI_theme->icontext_button_theme->disabled_down_text_color=*current_MMI_theme->button_disabled_text_color;
	current_UI_theme->icontext_button_theme->focussed_up_text_color=*current_MMI_theme->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->focussed_down_text_color=*current_MMI_theme->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->clicked_up_text_color=*current_MMI_theme->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->clicked_down_text_color=*current_MMI_theme->button_focussed_text_color;
	current_UI_theme->icontext_button_theme->text_font=(UI_font_type)(current_MMI_theme->button_font);
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_matrix_main_menu_theme
 * DESCRIPTION
 *  set  matrix menu theme equal to current theme of matrix menu
 *
 *  Note: it does not use  `matrix_main_menu_normal_item_filler', `matrix_main_menu_selected_item_filler', etc
 *  because these fillers are used in bi-degree main menu only.
 *
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_matrix_main_menu_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color =
        *current_MMI_theme->matrix_main_menu_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color =
        *current_MMI_theme->matrix_main_menu_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color =
        *current_MMI_theme->matrix_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color =
        *current_MMI_theme->matrix_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font =
        (UI_font_type) (current_MMI_theme->matrix_main_menu_font);
    current_UI_theme->fixed_icontext_menuitem_theme->flags |=
        (UI_MENUITEM_DISABLE_HIGHLIGHT | UI_MENUITEM_DISABLE_BACKGROUND);

    current_UI_theme->fixed_matrix_menu_theme->normal_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->focussed_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->vbar_width = current_MMI_theme->scrollbar_size;
    current_UI_theme->fixed_matrix_menu_theme->hbar_height = current_MMI_theme->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_list_main_menu_theme
 * DESCRIPTION
 *  set  list menu theme equal to current theme of list menu
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_list_main_menu_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->list_main_menu_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->list_main_menu_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->list_main_menu_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->list_main_menu_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color =
        *current_MMI_theme->list_main_menu_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color =
        *current_MMI_theme->list_main_menu_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color =
        *current_MMI_theme->list_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color =
        *current_MMI_theme->list_main_menu_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font =
        (UI_font_type) (current_MMI_theme->list_main_menu_font);

    current_UI_theme->fixed_list_menu_theme->normal_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_list_menu_theme->focussed_filler = current_MMI_theme->main_menu_background_filler;
    current_UI_theme->fixed_list_menu_theme->vbar_width = current_MMI_theme->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_3D_circular_main_menu_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_3D_circular_main_menu_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_matrix_sub_menu_theme
 * DESCRIPTION
 *  set  matrix sub  menu theme equal to current theme of
 *  matrix sub menu
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_matrix_sub_menu_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->matrix_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->matrix_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->matrix_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *current_MMI_theme->matrix_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color =
        *current_MMI_theme->matrix_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color =
        *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color =
        *current_MMI_theme->matrix_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->matrix_menu_font);
    current_UI_theme->fixed_icontext_menuitem_theme->flags &=
        ~(UI_MENUITEM_DISABLE_HIGHLIGHT | UI_MENUITEM_DISABLE_BACKGROUND);

    current_UI_theme->fixed_matrix_menu_theme->normal_filler = current_MMI_theme->matrix_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->focussed_filler = current_MMI_theme->matrix_background_filler;
    current_UI_theme->fixed_matrix_menu_theme->vbar_width = current_MMI_theme->scrollbar_size;
    current_UI_theme->fixed_matrix_menu_theme->hbar_height = current_MMI_theme->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_list_sub_menu_theme
 * DESCRIPTION
 *  set  list sub  menu theme equal to current theme of
 *  list sub menu
 *  Input Parameters  none
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_list_sub_menu_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->fixed_icontext_menuitem_theme->normal_filler = current_MMI_theme->list_normal_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_filler = current_MMI_theme->list_disabled_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_filler = current_MMI_theme->list_selected_item_filler;
    current_UI_theme->fixed_icontext_menuitem_theme->normal_text_color = *current_MMI_theme->list_normal_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->disabled_text_color = *current_MMI_theme->list_disabled_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->focussed_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->selected_text_color = *current_MMI_theme->list_selected_text_color;
    current_UI_theme->fixed_icontext_menuitem_theme->text_font = (UI_font_type) (current_MMI_theme->list_menu_font);

    current_UI_theme->fixed_list_menu_theme->normal_filler = current_MMI_theme->list_background_filler;
    current_UI_theme->fixed_list_menu_theme->focussed_filler = current_MMI_theme->list_background_filler;
    current_UI_theme->fixed_list_menu_theme->vbar_width = current_MMI_theme->scrollbar_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_popup_description_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_popup_description_theme(MMI_theme *t)
{
#if defined(UI_POPUP_DESCRIPTION_STYLE_3) || defined(UI_POPUP_DESCRIPTION_STYLE_2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Override flag to UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1 */
    static UI_filled_area popup_filler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popup_filler = *t->popup_description_background_filler;
    /* We do not override filler flags because DLT may use image here */
    // popup_filler.flags = UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1;
    MMI_pop_up_description_theme.background_filler = &popup_filler;
#else /* defined(UI_POPUP_DESCRIPTION_STYLE_3) || defined(UI_POPUP_DESCRIPTION_STYLE_2) */ 
    MMI_pop_up_description_theme.background_filler = t->popup_description_background_filler;
#endif /* defined(UI_POPUP_DESCRIPTION_STYLE_3) || defined(UI_POPUP_DESCRIPTION_STYLE_2) */ 
    MMI_pop_up_description_theme.text_color = *t->popup_description_text_color;
}

extern UI_filled_area wgui_pop_up_dialog_background;
extern UI_filled_area wgui_pop_up_dialog_inputbox_background;


/*****************************************************************************
 * FUNCTION
 *  set_MMI_popup_screen_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_popup_screen_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pop_up_dialog_background.c = *t->popup_screen_background_color;
    wgui_pop_up_dialog_inputbox_background.c = *t->popup_screen_background_color;
    wgui_pop_up_dialog_background.border_color = *t->popup_screen_border_color;
}

extern UI_single_line_input_box_theme wgui_inline_singleline_inputbox_focussed_theme;
extern UI_single_line_input_box_theme wgui_inline_singleline_inputbox_unfocussed_theme;
extern UI_single_line_input_box_theme wgui_inline_singleline_inputbox_no_boundary_theme;
extern UI_fixed_icontext_menuitem_theme wgui_inline_fixed_icontext_menuitem_theme;
extern UI_fixed_list_menu_theme wgui_inline_fixed_list_menu_theme;


/*****************************************************************************
 * FUNCTION
 *  set_MMI_inline_edit_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_inline_edit_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_singleline_inputbox_focussed_theme.normal_filler = current_MMI_theme->inline_edit_focussed_filler;
    wgui_inline_singleline_inputbox_focussed_theme.disabled_filler = current_MMI_theme->inline_edit_focussed_filler;
    wgui_inline_singleline_inputbox_focussed_theme.selected_filler = current_MMI_theme->inline_edit_focussed_filler;
    wgui_inline_singleline_inputbox_focussed_theme.normal_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_focussed_theme.selected_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_focussed_theme.disabled_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_focussed_theme.selection_text_color =
        *current_MMI_theme->inline_edit_selected_text_color;
    wgui_inline_singleline_inputbox_focussed_theme.selection_color = *current_MMI_theme->inline_edit_selector_color;
    wgui_inline_singleline_inputbox_focussed_theme.cursor_color = *current_MMI_theme->inline_edit_cursor_color;

    wgui_inline_singleline_inputbox_unfocussed_theme.normal_filler = current_MMI_theme->inline_edit_unfocussed_filler;
    wgui_inline_singleline_inputbox_unfocussed_theme.disabled_filler = current_MMI_theme->inline_edit_unfocussed_filler;
    wgui_inline_singleline_inputbox_unfocussed_theme.selected_filler = current_MMI_theme->inline_edit_unfocussed_filler;
    wgui_inline_singleline_inputbox_unfocussed_theme.normal_text_color =
        *current_MMI_theme->inline_edit_unfocussed_text_color;
    wgui_inline_singleline_inputbox_unfocussed_theme.selected_text_color =
        *current_MMI_theme->inline_edit_unfocussed_text_color;
    wgui_inline_singleline_inputbox_unfocussed_theme.disabled_text_color =
        *current_MMI_theme->inline_edit_unfocussed_text_color;
    wgui_inline_singleline_inputbox_unfocussed_theme.selection_text_color =
        *current_MMI_theme->inline_edit_selected_text_color;
    wgui_inline_singleline_inputbox_unfocussed_theme.selection_color = *current_MMI_theme->inline_edit_selector_color;
    wgui_inline_singleline_inputbox_unfocussed_theme.cursor_color = *current_MMI_theme->inline_edit_cursor_color;

    wgui_inline_singleline_inputbox_no_boundary_theme.normal_filler = current_MMI_theme->inline_edit_noboundary_filler;
    wgui_inline_singleline_inputbox_no_boundary_theme.disabled_filler =
        current_MMI_theme->inline_edit_noboundary_filler;
    wgui_inline_singleline_inputbox_no_boundary_theme.selected_filler =
        current_MMI_theme->inline_edit_noboundary_filler;
    wgui_inline_singleline_inputbox_no_boundary_theme.normal_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_no_boundary_theme.selected_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_no_boundary_theme.disabled_text_color =
        *current_MMI_theme->inline_edit_focussed_text_color;
    wgui_inline_singleline_inputbox_no_boundary_theme.selection_text_color =
        *current_MMI_theme->inline_edit_selected_text_color;
    wgui_inline_singleline_inputbox_no_boundary_theme.selection_color = *current_MMI_theme->inline_edit_selector_color;
    wgui_inline_singleline_inputbox_no_boundary_theme.cursor_color = *current_MMI_theme->inline_edit_cursor_color;

    wgui_inline_fixed_icontext_menuitem_theme.normal_filler = current_MMI_theme->inline_list_normal_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.disabled_filler = current_MMI_theme->inline_list_disabled_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.selected_filler = current_MMI_theme->inline_list_selected_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.focussed_filler = current_MMI_theme->inline_list_selected_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.normal_text_color = *current_MMI_theme->inline_list_normal_text_color;
    wgui_inline_fixed_icontext_menuitem_theme.disabled_text_color = *current_MMI_theme->inline_list_disabled_text_color;
    wgui_inline_fixed_icontext_menuitem_theme.selected_text_color = *current_MMI_theme->inline_list_selected_text_color;
    wgui_inline_fixed_icontext_menuitem_theme.focussed_text_color = *current_MMI_theme->inline_list_selected_text_color;

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    if (mmi_frm_is_screen_width_height_swapped())
    {
        wgui_inline_fixed_list_menu_theme.normal_filler = (UI_filled_area*)&MMI_rotated_menu_background_filler;
        wgui_inline_fixed_list_menu_theme.focussed_filler = (UI_filled_area*)&MMI_rotated_menu_background_filler;
    }
    else
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    {
        wgui_inline_fixed_list_menu_theme.normal_filler = current_MMI_theme->inline_list_background_filler;
        wgui_inline_fixed_list_menu_theme.focussed_filler = current_MMI_theme->inline_list_background_filler;
    }
    wgui_inline_fixed_list_menu_theme.vbar_width = current_MMI_theme->scrollbar_size;
}

extern UI_single_line_input_box_theme PIN_singleline_inputbox_theme;


/*****************************************************************************
 * FUNCTION
 *  set_MMI_PIN_inputbox_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_PIN_inputbox_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PIN_singleline_inputbox_theme.normal_filler = t->PIN_inputbox_background_filler;
    PIN_singleline_inputbox_theme.selected_filler = t->PIN_inputbox_background_filler;
    PIN_singleline_inputbox_theme.disabled_filler = t->PIN_inputbox_background_filler;
    PIN_singleline_inputbox_theme.normal_text_color = *t->PIN_inputbox_normal_text_color;
    PIN_singleline_inputbox_theme.selected_text_color = *t->PIN_inputbox_normal_text_color;
    PIN_singleline_inputbox_theme.disabled_text_color = *t->PIN_inputbox_normal_text_color;
    PIN_singleline_inputbox_theme.selection_text_color = *t->PIN_inputbox_selected_text_color;
    PIN_singleline_inputbox_theme.selection_color = *t->PIN_inputbox_selector_color;
    PIN_singleline_inputbox_theme.cursor_color = *t->PIN_inputbox_cursor_color;
}


/*****************************************************************************
 * FUNCTION
 *  set_MMI_virtual_keyboard_theme
 * DESCRIPTION
 *  Applies the theme for virtual keyboard
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_virtual_keyboard_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->virtual_keyboard_theme->key_down_filler = t->virtual_keyboard_key_down_filler;
    current_UI_theme->virtual_keyboard_theme->key_down_text_color = *t->virtual_keyboard_key_down_text_color;
    current_UI_theme->virtual_keyboard_theme->key_up_text_color = *t->virtual_keyboard_key_up_text_color;
    current_UI_theme->virtual_keyboard_theme->dead_key_down_text_color = *t->virtual_keyboard_dead_key_down_text_color;
    current_UI_theme->virtual_keyboard_theme->dead_key_up_text_color = *t->virtual_keyboard_dead_key_up_text_color;
    current_UI_theme->virtual_keyboard_theme->disp_area_text_color = *t->virtual_keyboard_disp_area_text_color;
    current_UI_theme->virtual_keyboard_theme->text_font = t->virtual_keyboard_font;
}

/*****************************************************************************
 * FUNCTION
 *  set_MMI_ime_theme
 * DESCRIPTION
 *  Applies the theme for ime
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_ime_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->ime_theme->underline_color = *t->ime_underline_color;
    current_UI_theme->ime_theme->indicator_color = *t->ime_indicator_color;
    current_UI_theme->ime_theme->focused_background_color = *t->ime_focused_background_color;
    current_UI_theme->ime_theme->background_color = *t->ime_background_color;
    current_UI_theme->ime_theme->focused_border_color = *t->ime_focused_border_color;
    current_UI_theme->ime_theme->border_color = *t->ime_border_color;
    current_UI_theme->ime_theme->text_color = *t->ime_text_color;
    current_UI_theme->ime_theme->lable_color = *t->ime_lable_color;
    current_UI_theme->ime_theme->hilite_color = *t->ime_hilite_color;
    current_UI_theme->ime_theme->hilite_text_color = *t->ime_hilite_text_color;
    current_UI_theme->ime_theme->cursor_color = *t->ime_cursor_color;
    current_UI_theme->ime_theme->arrow_color = *t->ime_arrow_color;
    current_UI_theme->ime_theme->text_font = t->ime_text_font;
    current_UI_theme->ime_theme->lable_font = t->ime_lable_font;
}

/*****************************************************************************
 * FUNCTION
 *  set_MMI_shortcut_box_theme
 * DESCRIPTION
 *  Applies the theme for menu shortcut
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_shortcut_box_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_UI_theme->shortcut_box_theme->normal_text_color = *t->title_shortcut_text_color;
    current_UI_theme->shortcut_box_theme->normal_text_border_color = *t->title_text_border_color;

    gui_RGB_to_HLS(current_UI_theme->shortcut_box_theme->normal_text_color, &hls);
    value = hls.l;
    value *= 3; /* 1.5 */
    value >>= 1;
    if (value <= 255)
    {
        hls.l = (U8) value;
    }
    else
    {
        hls.l = 255;
    }
    gui_HLS_to_RGB(hls, &current_UI_theme->shortcut_box_theme->active_text_color);
    current_UI_theme->shortcut_box_theme->active_text_border_color = *t->title_text_border_color;
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_240X320__) && !defined( __MMI_MAINLCD_320X240__)
    if (mmi_frm_is_screen_width_height_swapped())
    {
        current_UI_theme->shortcut_box_theme->use_border = 1;
    }
    else
#endif 
    {
        current_UI_theme->shortcut_box_theme->use_border = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  set_MMI_clock_theme
 * DESCRIPTION
 *  Applies the theme for clock
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_clock_theme(MMI_theme *t)
{
    current_UI_theme->clock_theme->analog_axis_color = *t->analog_axis_color;
    current_UI_theme->clock_theme->analog_hand_hour_color = *t->analog_hand_hour_color;
    current_UI_theme->clock_theme->analog_hand_min_color = *t->analog_hand_min_color;
    current_UI_theme->clock_theme->date_text_border_color = *t->date_text_border_color;
    current_UI_theme->clock_theme->date_text_color = *t->date_text_color;
    current_UI_theme->clock_theme->date_text_font = t->date_text_font;
    current_UI_theme->clock_theme->time_text_border_color = *t->time_text_border_color;
    current_UI_theme->clock_theme->time_text_color = *t->time_text_color;
    current_UI_theme->clock_theme->time_text_font = t->time_text_font;

#ifdef __MMI_SUBLCD__
    current_UI_theme->clock_theme->date_text_font_sub_lcd = t->date_text_font_sub_lcd;
    current_UI_theme->clock_theme->time_text_font_sub_lcd = t->time_text_font_sub_lcd;
    current_UI_theme->clock_theme->date_text_color_sub_lcd = *t->date_text_color_sub_lcd;
#ifdef __MMI_SUB_WALLPAPER__
    current_UI_theme->clock_theme->date_text_border_color_sub_lcd = *t->date_text_border_color_sub_lcd;
#endif/*__MMI_SUB_WALLPAPER__*/
    current_UI_theme->clock_theme->time_text_color_sub_lcd = *t->time_text_color_sub_lcd;
#ifdef __MMI_SUB_WALLPAPER__
    current_UI_theme->clock_theme->time_text_border_color_sub_lcd = *t->time_text_border_color_sub_lcd;
#endif/*__MMI_SUB_WALLPAPER__*/
#endif /* __MMI_SUBLCD__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  set_MMI_calendar_theme
 * DESCRIPTION
 *  Applies the theme for calendar
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI_theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_calendar_theme(MMI_theme *t)
{
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_CURRENT] = *t->calendar_current_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_ONE_TASK] = *t->calendar_one_task_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_MORE_TASK] = *t->calendar_more_task_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_MENSTRUAL] = *t->calendar_menstrual_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_PP] = *t->calendar_PP_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_DANGER] = *t->calendar_danger_color;
    current_UI_theme->calendar_theme->cell_bg[GUI_CALENDAR_COLOR_INVALID] = *t->calendar_invalid_color;
    current_UI_theme->calendar_theme->title_fg = *t->calendar_title_fg_color;
    current_UI_theme->calendar_theme->cell_font = t->calendar_cell_font;
    current_UI_theme->calendar_theme->cell_highlight = *t->calendar_highlight_color;
    current_UI_theme->calendar_theme->cell_invalid_fg = *t->calendar_invalid_fg_color;
    current_UI_theme->calendar_theme->cell_valid_fg = *t->calendar_valid_fg_color;
    current_UI_theme->calendar_theme->horizontal_select_border = *t->calendar_horizontal_border_color;
    current_UI_theme->calendar_theme->horizontal_select_fg = *t->calendar_horizontal_fg_color;
    current_UI_theme->calendar_theme->horizontal_string_fg = *t->calendar_horizontal_string_fg_color;
    current_UI_theme->calendar_theme->horizontal_string_font = t->calendar_horizontal_string_font;
    current_UI_theme->calendar_theme->vertical_select_fg = *t->calendar_vertical_fg_color;
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    current_UI_theme->calendar_theme->infobox_bg = *t->calendar_infobox_bg_color;
    current_UI_theme->calendar_theme->infobox_entry_bg = *t->calendar_infobox_entry_bg_color;
    current_UI_theme->calendar_theme->infobox_fg = *t->calendar_infobox_fg_color;
    current_UI_theme->calendar_theme->infobox_font = t->calendar_infobox_font;
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  set_MMI_theme
 * DESCRIPTION
 *  Sets the current MMI theme to use
 *  
 *  See MMI_theme structure
 * PARAMETERS
 *  t       [IN]        Is the MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_theme(MMI_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        return;
    }
#endif /* __MTK_TARGET__ */

    current_MMI_theme = t;
    current_UI_theme->border_theme = &MMI_filled_area_border_theme;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    set_MMI_multitap_input_theme(t);
    /* set single line input box theme */
    set_MMI_singleline_inputbox_theme(t);
    /* set multiline input box theme */
    set_MMI_multiline_inputbox_theme(t);
    /* set vertical scroll abr theme */
    set_MMI_vertical_scrollbar_theme(t);
    /* set horozontal scrollbar theme */
    set_MMI_horizontal_scrollbar_theme(t);
#if(0)
	set_MMI_horizontal_progress_indicator_theme(t);
	//set vertical progrss indiator theme 
	set_MMI_vertical_progress_indicator_theme(t);
#endif /* (0) */ 
    set_MMI_text_menuitem_theme_list(t);
    set_MMI_icontext_menuitem_theme_list(t);

    /*
     * set fixed menuitem UI themes from the current MMI theme
     *
     * note: current_MMI_theme = t
     */      
    set_MMI_current_fixed_text_menuitem_theme_list();
    set_MMI_current_fixed_icontext_menuitem_theme_list();
    set_MMI_current_fixed_icontext_list_menuitem_theme_list();
    set_MMI_current_fixed_twostate_menuitem_theme_list();
    
    /* set list menu theme */
    set_MMI_list_menu_theme(t);
    set_MMI_fixed_list_menu_theme(t);
    /* set matrix menu them e */
    set_MMI_matrix_menu_theme(t);
    set_MMI_fixed_matrix_menu_theme(t);
    /* set window title bar theme */
    set_MMI_window_title_theme(t);
    set_MMI_thick_title_theme(t);
    set_MMI_tab_title_theme(t);
    set_MMI_drop_down_control_theme(t);
    set_MMI_information_bar_theme(t);
    /* set EMSinput box theme */
    set_MMI_EMS_inputbox_theme(t);
    set_MMI_horizontal_tab_bar_theme(t);

    set_MMI_popup_description_theme(t);
    set_MMI_popup_screen_theme(t);
    set_MMI_inline_edit_theme(t);
    set_MMI_PIN_inputbox_theme(t);
    set_MMI_dialer_inputbox_theme(t);
    set_MMI_virtual_keyboard_theme(t);
    set_MMI_ime_theme(t);
    set_MMI_shortcut_box_theme(t);
    set_MMI_clock_theme(t);
    set_MMI_calendar_theme(t);

    current_filled_area_border_theme = current_UI_theme->border_theme;
    current_button_theme = current_UI_theme->button_theme;
    current_text_button_theme = current_UI_theme->text_button_theme;
    current_icon_button_theme = current_UI_theme->icon_button_theme;
    current_icontext_button_theme = current_UI_theme->icontext_button_theme;
    current_multitap_input_theme = current_UI_theme->multitap_input_theme;
    current_single_line_input_box_theme = current_UI_theme->single_line_input_box_theme;
    current_vertical_scrollbar_theme = current_UI_theme->vertical_scrollbar_theme;
    current_horizontal_scrollbar_theme = current_UI_theme->horizontal_scrollbar_theme;
    current_multi_line_input_box_theme = current_UI_theme->multi_line_input_box_theme;
    current_horizontal_progress_indicator_theme = current_UI_theme->horizontal_progress_indicator_theme;
    current_vertical_progress_indicator_theme = current_UI_theme->vertical_progress_indicator_theme;
    current_vertical_slide_theme = current_UI_theme->vertical_slide_theme;
    current_horizontal_slide_theme = current_UI_theme->horizontal_slide_theme;
    current_fixed_matrix_menu_theme = current_UI_theme->fixed_matrix_menu_theme;
    current_fixed_list_menu_theme = current_UI_theme->fixed_list_menu_theme;
    current_fixed_text_menuitem_theme = current_UI_theme->fixed_text_menuitem_theme;
    current_fixed_icontext_menuitem_theme = current_UI_theme->fixed_icontext_menuitem_theme;
    current_fixed_icontext_list_menuitem_theme = current_UI_theme->fixed_icontext_list_menuitem_theme;
    current_window_title_theme = current_UI_theme->window_title_theme;
    current_thick_title_theme = current_UI_theme->thick_title_theme;
    current_tab_title_theme = current_UI_theme->tab_title_theme;
    current_dialer_input_box_theme = current_UI_theme->dialer_inputbox_theme;
    current_drop_down_control_theme = current_UI_theme->drop_down_control_theme;
    current_information_bar_theme = current_UI_theme->information_bar_theme;
    current_EMS_input_box_theme = current_UI_theme->EMS_inputbox_theme;
    current_horizontal_tab_bar_theme = current_UI_theme->horizontal_tab_bar_theme;
    current_virtual_keyboard_theme = current_UI_theme->virtual_keyboard_theme;
#ifdef __MMI_CSTAR__
    current_ime_theme = current_UI_theme->ime_theme;
#endif
    current_shortcut_box_theme = current_UI_theme->shortcut_box_theme;
    current_clock_theme = current_UI_theme->clock_theme;
    current_calendar_theme = current_UI_theme->calendar_theme;

	set_MMI_multitap_theme();
}

/* These should be moved to the custom resource files */

/* Extra fonts */

stFontAttribute newfont1 = {0, 0, 0, MEDIUM_FONT, 0, 1};
stFontAttribute newfont2 = {0, 0, 0, MEDIUM_FONT, 0, 4};
stFontAttribute newfont3 = {0, 0, 0, MEDIUM_FONT, 0, 2};
stFontAttribute newfont4 = {0, 0, 0, MEDIUM_FONT, 0, 1};

/* Extra fillers  */

CONST_HARDWARE UI_filled_area MMI_down_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_up_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 226, 110, 100},
    {190, 191, 117, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_disabled_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 226, 110, 100},
    {190, 191, 117, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_focussed_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_clicked_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_multitap_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_SHADOW |
UI_FILLED_AREA_SHADOW_DOUBLE_LINE,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_inputbox_normal_filler3 = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inputbox_selected_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inputbox_disabled_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 226, 110, 100},
    {190, 191, 117, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {225, 226, 110, 100},
    {190, 191, 117, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {140, 216, 163, 100},
    {98, 186, 125, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollbar_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {100, 100, 100, 100},
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* progress indicator bkg theme */
CONST_HARDWARE UI_filled_area MMI_progress_indicator_background_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

/* scrollbar indiactor filler theme */
CONST_HARDWARE UI_filled_area MMI_progress_indicator_fillers3[MAX_PROGRESS_INDICATOR_FILLERS] =
    { {UI_FILLED_AREA_TYPE_COLOR,
       UI_NULL_IMAGE,
       NULL,
       {0, 128, 0, 100},
       {0, 0, 0, 0},
       {0, 0, 0, 0},
       {0, 0, 0, 0},
       0}
};

U8 MMI_progress_indicator_filler_percentages3[MAX_PROGRESS_INDICATOR_FILLERS] = {100
};

S32 MMI_n_progress_indicator_fillers3 = 1;

CONST_HARDWARE UI_filled_area MMI_active_title_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {107, 82, 158, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inactive_title_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {64, 64, 64, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_general_background_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {228, 216, 162, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {228, 216, 162, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler3 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {220, 220, 220, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {141, 167, 191, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_matrix_menu_background_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_matrix_menu_normal_item_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {26, 118, 54, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_matrix_menu_disabled_item_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {200, 200, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_shortcut_indicator_background3 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_down_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_3D_DEPRESSED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {201, 204, 213, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_up_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_3D_ELEVATED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {212, 208, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_disabled_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_3D_ELEVATED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {212, 208, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_focussed_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_3D_ELEVATED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {212, 208, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_clicked_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_3D_DEPRESSED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {201, 204, 213, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_multitap_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_SHADOW |
UI_FILLED_AREA_SHADOW_DOUBLE_LINE,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

CONST_HARDWARE UI_filled_area MMI_active_title_filler2 =
    {UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_3D_ELEVATED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {64, 64, 64, 100},
    {30, 30, 30, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_inactive_title_filler2 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {64, 64, 64, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_background_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {212, 208, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_normal_item_filler2 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {212, 208, 200, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_selected_item_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_3D_ELEVATED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {120, 120, 120, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_list_menu_disabled_item_filler2 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {141, 167, 191, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_matrix_menu_selected_item_filler2 = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {166, 200, 188, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_up_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {120, 200, 180, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_down_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {120, 200, 180, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_disabled_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {128, 128, 128, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar  focussed theme */

CONST_HARDWARE UI_filled_area MMI_scrollcontrol_focussed_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {120, 200, 180, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar  button up theme */

CONST_HARDWARE UI_filled_area MMI_scroll_up_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {180, 190, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar  button down theme */
CONST_HARDWARE UI_filled_area MMI_scroll_down_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {180, 190, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar disabled button  theme */
CONST_HARDWARE UI_filled_area MMI_scroll_disabled_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {128, 128, 128, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar focussed  theme */
CONST_HARDWARE UI_filled_area MMI_scroll_focussed_button_filler2 =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {180, 190, 240, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* scrollbar normal filler theme */
CONST_HARDWARE UI_filled_area MMI_scrollbar_normal_filler2 = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {100, 100, 100, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 40},
    0
};

