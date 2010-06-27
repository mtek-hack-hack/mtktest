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
 * wgui_categories_panel.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Categories with panel component
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
//#include "MMIDataType.h"
//#include "GlobalDefs.h"
//#include "gui_data_types.h"
//#include "CustDataProts.h"
//#include "CustMenuRes.h"
//#include "EventsDef.h"
#include "gui_themes.h"
#include "wgui.h"
#include "CustThemesRes.h"
#include "DebugInitDef.h"
//#include "wgui_tab_bars.h"
//#include "wgui_inputs.h"
//#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "wgui_status_icons.h"
//#include "wgui_categories_defs.h"
//#include "wgui_categories_inputs.h"
//#include "wgui_categories_idlescreen.h"
//#include "wgui_categories_multimedia.h"
//#include "CallManagementStruct.h"
//#include "CallSetup.h"
//#include "PhoneBookDef.h"
#include "gdi_include.h"
#include "lcd_if.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_panel.h"

#ifdef __MMI_TOUCH_DIAL_SCREEN__
#include "wgui_touch_screen.h"
#include "gui_setting.h"
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

#ifdef __GDI_MEMORY_PROFILE_2__
#include "gdi_datatype.h"
#include "gdi_layer.h"
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

/*-------------------------------
External Global variables
-------------------------------*/
extern BOOL r2lMMIFlag;

/*-------------------------------
External Global Functions
-------------------------------*/
extern icontext_button MMI_softkeys[];

/*-------------------------------
Global variables
-------------------------------*/
static MMI_ID_TYPE wgui_cat95_panel_bg_id;
static S32 wgui_cat95_panel_handle;


/***************************************************************************** 
* Local Function
*****************************************************************************/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "gui_panel.h"

/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_general_key_handler
 * DESCRIPTION
 *  wgui_cat95_general_key_handler
 *  
 *  Calendar hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    gui_panel_struct* panel;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    panel = dm_get_panel(wgui_cat95_panel_handle);
    gui_panel_general_key_handler(panel, keycode, keytype);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_hide_left_softkey
 * DESCRIPTION
 *  Hides the left softkey
 *  
 *  Calendar hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_hide_left_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
        UI_device_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
        UI_device_height - 1, 
        GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw_id(0, 0, wgui_cat95_panel_bg_id);
#endif 
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_hide_right_softkey
 * DESCRIPTION
 *  Hides the right softkey
 *  
 *  Calendar hide right softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_hide_right_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
        UI_device_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
        UI_device_height - 1, 
        GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw_id(0, 0, wgui_cat95_panel_bg_id);
#endif 
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_draw_title
 * DESCRIPTION
 *  Displays the category95 screen title
 * PARAMETERS
 *  x                   [IN]        x of the top-left of the title
 *  y            [IN]        y of the top-left of the title
 *  clip_x1       [IN]        x1 of the clip area
 *  clip_y1           [IN]        y1 of the clip area
 *  clip_x2      [IN]        x2 of the clip area
 *  clip_y2          [IN]        y2 of the clip area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_draw_title(
                    S32 x, 
                    S32 y, 
                    S32 clip_x1, 
                    S32 clip_y1, 
                    S32 clip_x2, 
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width , string_height;
    S32 string_x, string_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    
    gui_set_font((UI_font_type) (current_MMI_theme->window_title_font));
    gui_measure_string(MMI_title_string, &string_width, &string_height);
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_set_text_border_color(*current_MMI_theme->title_text_border_color);

    string_x = clip_x1 + (clip_x2 - clip_x1 + 1 - string_width)>>1;
    if (r2lMMIFlag)
    {
        string_x = string_x + string_width - 1;
    }
    string_y = clip_y1 + (clip_y2 - clip_y1 + 1 - string_height)>>1;
    gui_move_text_cursor(string_x, string_y);
    gui_print_bordered_text(MMI_title_string);

    gdi_layer_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory95Screen
 * DESCRIPTION
 *  Displays the category95 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  history_buffer          [IN]        History buffer
 *  bg_id                   [IN]        panel background image id
 *  element_list            [IN]        list of panel elements
 *  num_of_element          [IN]        number of panel elements
 *  focused_element         [IN]        focused panel element
 *  repeat_period           [IN]        period of repeat events in milliseconds (0 for default)
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory95Screen(
        U8 *title,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        MMI_ID_TYPE bg_id,
        wgui_cat95_panel_element_struct *element_list,
        S32 num_of_element,
        S32 focused_element,
        U32 repeat_period,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter, title_painter;
    S32 current_focus = focused_element;
    S32 i;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    wgui_cat95_panel_bg_id = bg_id;

    disable_softkey_background();
    register_hide_left_softkey(wgui_cat95_hide_left_softkey);
    register_hide_right_softkey(wgui_cat95_hide_right_softkey);

    hide_status_icon_bar(0);
    hide_status_icon_bar(1);

/* background */    
#ifdef __GDI_MEMORY_PROFILE_2__
    gui_util_painter_create_transparent(&bg_painter);
    dm_add_image(get_image(bg_id), NULL, NULL);
#else 
    gui_util_painter_create_imageid(&bg_painter, bg_id);
#endif 
    wgui_cat95_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_TRUE, repeat_period);

/* title */
    MMI_title_string = (UI_string_type)title;
    gui_util_painter_create_callback(&title_painter, wgui_cat95_draw_title);
    dm_add_panel_element(
            wgui_cat95_panel_handle,
            0,
            0,
            MMI_title_width,
            MMI_title_height,
            KEY_INVALID,
            NULL,
            NULL,
            NULL,
            title_painter,
            title_painter,
            title_painter,
            title_painter,
            MMI_FALSE);

/* button */
    for(i = 0; i < num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_cat95_panel_handle,
            element_list[i].x,
            element_list[i].y,
            element_list[i].width,
            element_list[i].height,
            element_list[i].keycode,
            element_list[i].down_event_callback,
            element_list[i].up_event_callback,
            element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
    }

    h_flag = set_panel_category_history(MMI_CATEGORY95_ID, history_buffer);
    if(!h_flag)
    {
        dm_set_panel_element_focus(wgui_cat95_panel_handle, current_focus, MMI_FALSE);
    }

    dm_register_panel_keys(wgui_cat95_panel_handle, wgui_cat95_general_key_handler);
    
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory95Screen;

#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY95_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}   /* end of ShowCategory129Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory95Screen
 * DESCRIPTION
 *  Exits the category95 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory95Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enable_softkey_background();//032607 HID softkey
}   /* end of ExitCategory129Screen */
