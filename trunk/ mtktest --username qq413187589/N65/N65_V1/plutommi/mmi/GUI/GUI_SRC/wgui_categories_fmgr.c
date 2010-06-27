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
 *  wgui_categories_fmgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager related categories.
 *
 *  [Category212]       Info Style Dynamic List Menu 
 *  [Category213]       Thick Style Dynamic List Menu 
 *  [Category214]       Matrix Style Dynamic Image Menu 
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
#include "MMI_features.h"

/* framework related include */
#include "EventsGprot.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "GlobalDefs.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "DebugInitDef.h"

/* gui related include */
#include "gdi_include.h"        /* include for graphic lib */
#include "kal_non_specific_general_types.h"     /* include this for kal data type */
#include "lcd_sw_rnd.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_dynamic_menus.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_categories.h"
#include "wgui_categories_fmgr.h"
#include "wgui_draw_manager.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "ScreenRotationGprot.h"

#include "FileMgr.h"    /* file Utility functions */
#include "FileManagerDef.h"     /* String ID define */

#include "gdi_lcd_config.h"     /* include this for LCD_HEIGHT */

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_MAINLCD_128X128__)
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#elif defined(__MMI_MAINLCD_128X160__)
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#elif defined(__MMI_MAINLCD_176X220__)
#define MMI_THICK_MENUITEM_HEIGHT   (39)
#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_THICK_MENUITEM_HEIGHT   (60)
#elif defined(__MMI_MAINLCD_320X240__)
#define MMI_THICK_MENUITEM_HEIGHT   (44)
#else 
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#endif 

#define CAT214_INSIDE_SPACING          (4)      /* spacing include photo style frame */
#define CAT214_OUTSIDE_SPACING         (4)

/***************************************************************************** 
* Golbal Variable
*****************************************************************************/
S32 MMI_thick_menuitem_height = MMI_THICK_MENUITEM_HEIGHT;  /* this shall move to other customizable place */

extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Golbal Function
*****************************************************************************/
extern S32 wgui_current_pop_up_description_index;
extern void reset_pop_up_descriptions(void);
extern void set_dynamic_pop_up_descriptions(S32 highlighted_item);
extern void (*MMI_matrix_highlight_handler) (S32 item_index);
extern void draw_wallpaper(void);
extern void wgui_title_set_no_icon_shct(MMI_BOOL no_icon_shct);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* [Category212] */
static Cat212DrawInfoFuncPtr cat212_draw_info_callback = NULL;
static Cat212HideInfoFuncPtr cat212_hide_info_callback = NULL;
static U16 cat212_info_box_height = 0;

/* [Category213] */
static Cat213DrawMenuItemFuncPtr cat213_draw_menuitem_callback = NULL;
static Cat213HideMenuItemFuncPtr cat213_hide_menuitem_callback = NULL;
static U16 cat213_menuitem_per_screen;
static U8 cat213_arrow_flag;

/* [Category214] */
static Cat214DrawImageFuncPtr cat214_draw_image_callback = NULL;
static Cat214HideImageFuncPtr cat214_hide_image_callback = NULL;
static U8 cat214_num_per_row;
static U8 cat214_num_per_col;
static U16 cat214_hilighted_index;

#if defined(__MMI_TOUCH_SCREEN__)
static S16 cat214_pen_down_index;
static U16 cat214_pen_down_on_scroll;
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
static U16 cat214_prev_hilighted_index;
static U16 cat214_item_count;
static S16 cat214_page_index;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* [Category212] */
static void ExitCategory212Screen(void);
void DrawCate212CategoryControlArea(dm_coordinates *coordinate);
static void ShowCategory212InfoArea(S32 item_idx);

/* [Category213] */
static void ExitCategory213Screen(void);

static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array);
static void Cat213RedrawDynamicList(void);
static void Cat213KeyUpHdlr(void);
static void Cat213KeyDownHdlr(void);
static void Cat213ShortCutHdlr(S32 item_index);

/* [Category214] */
static void ExitCategory214Screen(void);
static U8 *GetCategory214History(U8 *history_buffer);
static void Cat214KeyUpHdlr(void);
static void Cat214KeyDownHdlr(void);
static void Cat214KeyLeftHdlr(void);
static void Cat214KeyRightHdlr(void);
static void Cat214RedrawMatrix(void);
static void Cat214ShortCutHdlr(S32 item_index);

#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenDownHdlr(mmi_pen_point_struct pos);
static MMI_BOOL Cat214CategoryControlAreaPenMoveHdlr(mmi_pen_point_struct pos);
static MMI_BOOL Cat214CategoryControlAreaPenUpHdlr(mmi_pen_point_struct pos);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

static void DrawCate214CategoryControlArea(dm_coordinates *coordinate);

/*****************************************************************************
* [Category212]
*
* This category is for File Manager to display drive info.
*
*  **********************
*  *                    *
*  *                  ----------- info box   
*  **********************
*  *  # Folder          *
*  *  # File A          *
*  *  # File B          *
*  *                    *
*  *                    *
*  *                 -------------- Fix List 
*  *                    *
*  *                    *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory211Screen
 * DESCRIPTION
 *  Show sategory 211 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory211Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        S32 info_box_height,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 shortcut_width;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    cat212_draw_info_callback = draw_info_callback;
    cat212_hide_info_callback = hide_info_callback;

    cat212_info_box_height = (U16) info_box_height;

    /* lock */
    gui_lock_double_buffer();

    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    create_fixed_icontext_menuitems();

    MMI_current_menu_type = LIST_MENU;

    /* init dynamic list */
    associate_fixed_icontext_list();

    init_dynamic_item_buffer(num_of_items, get_item_func, get_hint_func, UI_dummy_function);
    MMI_fixed_list_menu.n_items = num_of_items;

    /* register shortcut */
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(Cat212ShortCutHdlr);

    register_dynamic_list_keys();
    shortcut_width = set_menu_item_count(num_of_items) + 7;

    //resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    //register_hide_menu_shortcut(draw_title);
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    //set_fixed_icontext_positions(MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0, 1, 0);

    move_fixed_list(0, (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + cat212_info_box_height);  /* use two menuitem height to draw drive info */
    resize_fixed_list(MMI_content_width, MMI_content_height - cat212_info_box_height);

    /* when hilight, will update info area */
    register_fixed_list_highlight_handler(ShowCategory212InfoArea);

    h_flag = set_list_menu_category_history(MMI_CATEGORY212_ID, history_buffer);
    dynamic_list_goto_item_no_redraw(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);

    /* init title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    resize_dynamic_icontext_menuitems_to_list_width();
    set_dynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);  /* ????? */

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory212Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY212_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate212CategoryControlArea);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory212Screen
 * DESCRIPTION
 *  Show sategory 212 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory212Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory211Screen(
        title, 
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        get_item_func,
        get_hint_func,
        draw_info_callback,
        hide_info_callback,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT,
        info_bg_img_id,
        highlighted_item,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory212Screen
 * DESCRIPTION
 *  Exit category 212 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory212Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }

    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();

    /* reset cat212 related golbal var */
    cat212_info_box_height = 0;

    cat212_draw_info_callback = NULL;
    cat212_hide_info_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate212CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category212 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate212CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory212InfoArea(MMI_fixed_list_menu.highlighted_item);
    coordinate->s16X = 0;
    coordinate->s16Y = (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/);
    coordinate->s16Height = cat212_info_box_height;
    coordinate->s16Width = MMI_content_width;
}


/*****************************************************************************
 * FUNCTION
 *  DrawTextAreaBackground
 * DESCRIPTION
 *  Show the background of text area
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 info_bg_y,info_bg_bottom_y;
    S32 image_width, image_height;
    
    /* Draw top area */
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_TOP, &image_width, &image_height);
    gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_TOP);
    info_bg_y += image_height;

    /* Draw bottom area */
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_BOTTOM, &image_width, &image_height);
    info_bg_bottom_y = (y2 - image_height + 1);
    gdi_image_draw_id(x1, info_bg_bottom_y, WGUI_IMG_TEXT_BG_BOTTOM);

    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(
        x1,
        info_bg_y,
        x2,
        info_bg_bottom_y - 1);

    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_MID, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_MID);
        info_bg_y += image_height;
    }while (info_bg_y < info_bg_bottom_y);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  FillFullTextBackground
 * DESCRIPTION
 *  fill full area with text background image
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 info_bg_y,info_bg_bottom_y;
    S32 image_width, image_height;
    
    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_MID, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_MID);
        info_bg_y += image_height;
    }while (info_bg_y <= y2);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory212InfoArea
 * DESCRIPTION
 *  Show the info area for category212
 * PARAMETERS
 *  item_idx        [IN]        Item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory212InfoArea(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call dynamic list's hilight handler */
    dynamic_list_highlight_handler(item_idx);

    gdi_layer_lock_frame_buffer();

    /* drive info block */
    gui_reset_clip();
#if defined(__MMI_MAINLCD_128X128__)  
    gui_fill_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + cat212_info_box_height - 1,
        gui_color(255, 255, 255));
    gui_draw_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + cat212_info_box_height - 1,
        gui_color(0, 0, 0));
#else

  //#if defined(__USE_WMD_APPLICATION__)
    // 增加下面这句话，是为了修改MTK动态LIST的BUG
    if( cat212_info_box_height > 0 )
  //#endif  /* #if defined(__USE_WMD_APPLICATION__) */

    DrawTextAreaBackground(
        0,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),
        UI_device_width - 1, 
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + cat212_info_box_height - 1);
#endif
    /* stop previous action, such as gif animation, decoder, timer etc. */
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }

    gdi_image_cache_reset();

    /* if is emtpty folder, show a empty string */
    if (MMI_fixed_list_menu.n_items == 0)
    {
        gui_set_font(&MMI_medium_font);
        //gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }

    if (cat212_draw_info_callback != NULL)
    {
        cat212_draw_info_callback(
            MMI_fixed_list_menu.highlighted_item,   /* idx */
            0,                                      /* x1 */
            (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),       /* y1 */
            UI_device_width - 1,                    /* x2 */
            (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + cat212_info_box_height - 1);       /* y2 */
    }

    /* 
     * lock then blt, will not update to lcm directly, but will force next blt function 
     * also update this region 
     */
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  Cat212ShortCutHdlr
 * DESCRIPTION
 *  Category 212 short cut goto item hdlr
 * PARAMETERS
 *  item_index      [IN]        Goto item's index
 * RETURNS
 *  void
 *****************************************************************************/
void Cat212ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate213CategoryControlArea
 * DESCRIPTION
 *  draw control area
 * PARAMETERS
 *  coordinate      [IN]        Coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate213CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items == 0)
    {
        show_dynamic_list();
        gui_reset_text_clip();
        gui_set_font(&MMI_medium_font);
        //gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }
    else
    {
        Cat213RedrawDynamicList();
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_handler
 * DESCRIPTION
 *  pen handler
 * PARAMETERS
 *  point           [IN]        pen event position
 *  pen_event       [IN]        pen event type
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Display prompt string instead of menu */
    if (MMI_fixed_list_menu.n_items == 0)
    {
        return MMI_FALSE;
    }

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        MMI_fixed_list_menu.pen_redraw_menu_function = Cat213RedrawDynamicList;
        gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
        gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
    }

    return wgui_general_pen_dynamic_list_menu_hdlr(point, pen_event);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_down_handler
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        pen down position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_move_handler
 * DESCRIPTION
 *  pen move handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_longtap_handler
 * DESCRIPTION
 *  pen longtap handler
 * PARAMETERS
 *  point       [IN]        pen longtap handler
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_longtap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_repeat_handler
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  point       [IN]        pen repeat position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_up_handler
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  point       [IN]        pen up position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_abort_handler
 * DESCRIPTION
 *  pen abourt handler
 * PARAMETERS
 *  point       [IN]        pen abort position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_ABORT);
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
* FUNCTION
*  GetCategory213HistorySize
* DESCRIPTION
*  Gets the history buffer size of category 213
* PARAMETERS
*  void
* RETURNS
*  size in U8s of the history buffer
*****************************************************************************/
S32 GetCategory213HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(list_menu_category_history);
}


/*****************************************************************************
* FUNCTION
*  GetCategory213History
* DESCRIPTION
*  Gets the history buffer of category213
* PARAMETERS
*  history_buffer      [OUT]        Is the buffer into which the history data is stored
* RETURNS
*  return history buffer
*****************************************************************************/
U8 *GetCategory213History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY213_ID, history_buffer);
    return (history_buffer);
}



/*****************************************************************************
* [Category213]
*
* This category is for ImageViewer to display drive info.
*
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory213Screen
 * DESCRIPTION
 *  Show sategory 223 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  draw_menuitem_callback      [IN]        Callback function to draw menuitem
 *  hide_menuitem_callback      [IN]        Callback function to hide menuitem
 *  highlighted_item            [IN]        Highlighted item index
 *  arrow_flag                  [IN]        Arrow on buttom bar
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory213Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
        Cat213HideMenuItemFuncPtr hide_menuitem_callback,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 shortcut_width;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    cat213_draw_menuitem_callback = draw_menuitem_callback;
    cat213_hide_menuitem_callback = hide_menuitem_callback;

    cat213_menuitem_per_screen = MMI_content_height / (MMI_thick_menuitem_height - 1);
    cat213_arrow_flag = arrow_flag;

    /* lock */
    gui_lock_double_buffer();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
    create_fixed_icontext_menuitems();

    MMI_current_menu_type = LIST_MENU;

    /* init dynamic list */
    associate_fixed_icontext_list();

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_menuitem_transparent_effect();
#endif 

#ifdef __MMI_SCREEN_ROTATE__
     if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;
    }
    
    init_dynamic_item_buffer(num_of_items, Cat213GetItemCallback, Cat213GetHintCallback, UI_dummy_function);
    MMI_fixed_list_menu.n_items = num_of_items;

    /* register shortcut */
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(Cat213ShortCutHdlr);

    clear_keyboard_key_handler();
    SetKeyHandler(Cat213KeyUpHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyDownHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyUpHdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyDownHdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    shortcut_width = set_menu_item_count(num_of_items) + 7;

    //resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    //register_hide_menu_shortcut(draw_title);

    resize_fixed_icontext_menuitems(0, MMI_thick_menuitem_height);

    //set_fixed_icontext_positions(MMI_ICONTEXT_MENUITEM_HEIGHT, 0, 1, 0);

    /* change menuitem's height */
    move_fixed_list(0, (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/));
    resize_fixed_list(MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT);

    register_fixed_list_highlight_handler(dynamic_list_highlight_handler);

    /* if caller wish to use gui buffer as histoy */
    h_flag = set_list_menu_category_history(MMI_CATEGORY213_ID, history_buffer);

    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }

    dynamic_list_goto_item_no_redraw(highlighted_item);

    /* adjust hilight - since its is thick menu and previous function will not calc correclty */
    MMI_fixed_list_menu.highlighted_item = highlighted_item;

    if (num_of_items < cat213_menuitem_per_screen)
    {
        MMI_fixed_list_menu.first_displayed_item = 0;
        MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
    }
    else
    {
        if ((num_of_items - highlighted_item) < cat213_menuitem_per_screen)
        {

            MMI_fixed_list_menu.first_displayed_item = num_of_items - cat213_menuitem_per_screen;
            MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
        }
        else
        {
            MMI_fixed_list_menu.first_displayed_item = highlighted_item;
            MMI_fixed_list_menu.last_displayed_item = highlighted_item + num_of_items - 1;
        }
    }

    /* init title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    resize_dynamic_icontext_menuitems_to_list_width();
    resize_fixed_icontext_menuitems(0, MMI_thick_menuitem_height);

    set_dynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);  /* ????? */

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory213Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory213History, GetCategory213HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY213_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_down_handler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category213_control_area_pen_up_handler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_move_handler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_repeat_handler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_longtap_handler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_abort_handler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate213CategoryControlArea);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory213Screen
 * DESCRIPTION
 *  Exit category 213 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory213Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
#endif 

    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }

    cat213_draw_menuitem_callback = NULL;
    cat213_hide_menuitem_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetItemCallback
 * DESCRIPTION
 *  Get category 213 get item callback function
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str_buff, (PS8) L"");
    *img_buff_p = NULL;;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetHintCallback
 * DESCRIPTION
 *  Get category 213 get hint callback function
 * PARAMETERS
 *  item_idx        [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213RedrawDynamicList
 * DESCRIPTION
 *  Redraw category 213 dynamic list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213RedrawDynamicList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    BOOL is_done;
    S32 item_width, item_height;
    S32 offset_y;
    S32 total_height;
    S32 counter;
    S32 list_height;
    BOOL is_hilighted;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hide previous menuitems, usually stop animation and some off-line decoder */
    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }

    gui_lock_double_buffer();

    /* show list, only show the frame - content will be draw by callback function */
    show_dynamic_list();

    list_height = MMI_fixed_list_menu.height;
    is_done = FALSE;
    total_height = 0;
    counter = 0;

    MMI_fixed_list_menu.item_measure_function(
                            MMI_fixed_list_menu.items[0],
                            MMI_fixed_list_menu.common_item_data,
                            &item_width,
                            &item_height);
    item_height = MMI_thick_menuitem_height;

    for (i = MMI_fixed_list_menu.first_displayed_item; (i < MMI_fixed_list_menu.n_items && !is_done); i++)
    {
        if (i == MMI_fixed_list_menu.highlighted_item)
        {
        #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
            g_mmi_frm_cntx.dump_screen_info.hightlight_type = MMI_SCREEN_HIGHLIGHT_FOR_CAR213_DYNAMIC_LIST;
        #endif

            is_hilighted = TRUE;
        }
        else
        {
            is_hilighted = FALSE;
        }

        if (i == MMI_fixed_list_menu.highlighted_item)
        {
            current_fixed_list_menuitem_display_index = -1;
        }
        else
        {
            current_fixed_list_menuitem_display_index = i;
        }

        offset_y = total_height;
        total_height += item_height;

        if (total_height > list_height + 1)
        {
            is_done = TRUE;
            if (counter == 0)
            {
                if (cat213_draw_menuitem_callback != NULL)
                {
                    if (r2lMMIFlag)
                    {
                        cat213_draw_menuitem_callback(
                            i,
                            is_hilighted,
                            MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + 1,
                            MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                            MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + item_width + 1,
                            MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                    }
                    else
                    {
                        cat213_draw_menuitem_callback(
                            i,
                            is_hilighted,
                            MMI_fixed_list_menu.x + 1,
                            MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                            MMI_fixed_list_menu.x + item_width + 1,
                            MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                    }
                }
            }
        }
        else
        {
            if (cat213_draw_menuitem_callback != NULL)
            {
                if (r2lMMIFlag)
                {
                    cat213_draw_menuitem_callback(
                        i,
                        is_hilighted,
                        MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + 1,
                        MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                        MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + item_width + 1,
                        MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                }
                else
                {
                    cat213_draw_menuitem_callback(
                        i,
                        is_hilighted,
                        MMI_fixed_list_menu.x + 1,
                        MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                        MMI_fixed_list_menu.x + item_width + 1,
                        MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                }

            }
            counter++;
        }
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213KeyUpHdlr
 * DESCRIPTION
 *  Category 213 key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213KeyUpHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilight_idx = MMI_fixed_list_menu.highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    if (hilight_idx - 1 >= 0)
    {
        hilight_idx--;
    }
    else
    {
        hilight_idx = MMI_fixed_list_menu.n_items - 1;
    }

    gui_lock_double_buffer();

    /* goto prev item */
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, hilight_idx);

    /* redraw dynamic list */
    Cat213RedrawDynamicList();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213KeyDownHdlr
 * DESCRIPTION
 *  Category 213 key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213KeyDownHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilight_idx = MMI_fixed_list_menu.highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    if (hilight_idx + 1 < MMI_fixed_list_menu.n_items)
    {
        hilight_idx++;
    }
    else
    {
        hilight_idx = 0;
    }

    gui_lock_double_buffer();

    /* goto next item */
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, hilight_idx);

    /* redraw dynamic list */
    Cat213RedrawDynamicList();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213ShortCutHdlr
 * DESCRIPTION
 *  Category 213 shot cut key press handler
 * PARAMETERS
 *  item_index      [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        RedrawCategoryFunction();
    }
}

/*****************************************************************************
* [Category214]
*
* This category is for File Manager to display drive info.
*
*  *********************
*  *                  ----------- Title
*  *********************
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     ----------- Matrix Images
*  *  ******* *******  *
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     *  *
*  *  ******* *******  *
*  *********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory214Screen
 * DESCRIPTION
 *  Show sategory 214 screen.
 * PARAMETERS
 *  title                   [IN]        Title string id
 *  title_icon              [IN]        Title image id
 *  left_softkey            [IN]        Lsk string id
 *  left_softkey_icon       [IN]        Lsk image id
 *  right_softkey           [IN]        Rsk string id
 *  right_softkey_icon      [IN]        Rsk image id
 *  num_of_items            [IN]        How many items
 *  draw_image_callback     [IN]        Callback function to draw image
 *  hide_image_callback     [IN]        Callback function to hide
 *  num_per_row             [IN]        Num of image pre row
 *  num_per_col             [IN]        Num of image pre col
 *  highlighted_item        [IN]        Highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory214Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    GDI_HANDLE cat214_bg_layer;
#endif 

    S32 num_of_page;
    S32 item_per_page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg checking */
    MMI_ASSERT(num_per_row != 0);
    MMI_ASSERT(num_per_col != 0);

    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    gui_setup_submenu_layout();

    cat214_draw_image_callback = draw_image_callback;
    cat214_hide_image_callback = hide_image_callback;
    cat214_num_per_row = num_per_row;
    cat214_num_per_col = num_per_col;
    cat214_hilighted_index = (U16) highlighted_item;
    cat214_prev_hilighted_index = (U16) highlighted_item;
    cat214_item_count = num_of_items;
    cat214_page_index = -1; /* this will force to redraw whole matrix */

    MMI_menu_shortcut_number = -1;

    /* init highligthed item idx */
    MMI_fixed_list_menu.highlighted_item = 0;
    MMI_fixed_list_menu.n_items = num_of_items;

    item_per_page = num_per_row * num_per_col;
    num_of_page = num_of_items / (item_per_page);

    if (num_of_items % item_per_page != 0)
    {
        num_of_page++;
    }

    /* use MMI_fixed_list_menu's history */
    if (set_list_menu_category_history(MMI_CATEGORY214_ID, history_buffer))
    {
        cat214_hilighted_index = (U16) MMI_fixed_list_menu.highlighted_item;
    }

    /* create layer */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();
#endif
    
    gdi_layer_lock_frame_buffer();

    if (num_of_items != 0)
    {
        /* use fixed list menu's scroll bar to save memory */
        if (r2lMMIFlag)
        {
            gui_create_vertical_scrollbar(
                &MMI_fixed_list_menu.vbar,
                0,
                (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),
                current_MMI_theme->scrollbar_size,
                MMI_content_height);

        }
        else
        {
            gui_create_vertical_scrollbar(
                &MMI_fixed_list_menu.vbar,
                UI_device_width - current_MMI_theme->scrollbar_size,
                (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/),
                current_MMI_theme->scrollbar_size,
                MMI_content_height);
        }

        gui_set_vertical_scrollbar_range(&MMI_fixed_list_menu.vbar, num_of_page);
        gui_set_vertical_scrollbar_scale(&MMI_fixed_list_menu.vbar, 1);
        gui_set_vertical_scrollbar_value(&MMI_fixed_list_menu.vbar, highlighted_item / item_per_page);
        gui_show_vertical_scrollbar(&MMI_fixed_list_menu.vbar);
    }

    gdi_layer_get_base_handle(&wgui_base_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, UI_SUBMENU_OPACITY_BASED_LAYER);

#if !(defined(__MMI_WALLPAPER_ON_BOTTOM__)) && defined(__GDI_MEMORY_PROFILE_2__)
    /* dm will draw a wallpaper bg on extra layer */

    dm_create_layer(0, 0, UI_device_width, UI_device_height, &cat214_bg_layer, DM_LAYER_BOTTOM);
    gdi_layer_push_and_set_active(cat214_bg_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_reset_clip();
    /* draw fix list backgroud */
    gui_draw_filled_area(
        0,
        MMI_content_y,
        UI_device_width - 1,
        MMI_content_y + MMI_content_height - 1,
        current_MMI_theme->list_background_filler);

    gdi_layer_pop_and_restore_active();

#endif /* !(defined(__MMI_WALLPAPER_ON_BOTTOM__)) && defined(__GDI_MEMORY_PROFILE_2__) */ 

    /* shortcut */
    register_menu_shortcut_keys();
    register_menu_shortcut_selected_only(Cat214ShortCutHdlr);

    set_menu_item_count(num_of_items);
    //resize_menu_shortcut_handler(set_menu_item_count(num_of_items) + 7, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    //register_hide_menu_shortcut(draw_title);

    if (cat214_item_count != 0)
    {
        MMI_menu_shortcut_number = cat214_hilighted_index + 1;
    }

    MMI_disable_title_shortcut_display = FALSE;

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    SetKeyHandler(Cat214KeyUpHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyDownHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyUpHdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyDownHdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyLeftHdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyRightHdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* init title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    /* call highlight handler */
    if ((MMI_list_highlight_handler != NULL) && (num_of_items != 0))
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory214Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory214History, get_list_menu_category_history_size);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenDownHdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenMoveHdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenUpHdlr, MMI_PEN_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY214_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate214CategoryControlArea);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory214Screen
 * DESCRIPTION
 *  Exit category 214
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory214Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_menu_shortcut_handler();
    reset_softkeys();

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    /* flatten layer */
    gdi_layer_flatten_previous_to_base();

    gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
    gdi_layer_multi_layer_disable();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory214History
 * DESCRIPTION
 *  Get category214 history.
 * PARAMETERS
 *  history_buffer      [OUT]        History buffer
 * RETURNS
 *  hitsory buffer
 *****************************************************************************/
static U8 *GetCategory214History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY214_ID, history_buffer);
    return (history_buffer);
}   /* end of GetCategory32History */


/*****************************************************************************
 * FUNCTION
 *  Cat214RedrawMatrix
 * DESCRIPTION
 *  Redraw Category 214 Matrix
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214RedrawMatrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    BOOL is_redraw_all;
    BOOL is_hilighted;
    S32 item_per_page;
    color *color_ptr;

    gdi_color box_bg_color;
    gdi_color box_frame_color;
    gdi_color box_hilight_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();

    gdi_layer_set_clip(
        0,
        MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height + 1*/,
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + MMI_SUBMENU_CONTENT_HEIGHT/*MMI_content_height*/ - 1);

    box_frame_color = gdi_act_color_from_rgb(255,150, 150, 150);
    box_hilight_color = gdi_act_color_from_rgb(255,255, 0, 0);

    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/;
    content_height = MMI_content_height;

    box_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    box_width /= cat214_num_per_col;

    box_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    box_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;

    /* clear whole content background */
    if (is_redraw_all)
    {
        if (r2lMMIFlag)
        {
            gdi_draw_solid_rect(
                current_MMI_theme->scrollbar_size,
                MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/,
                UI_device_width - 1,
                (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + MMI_content_height - 1,
                GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gdi_draw_solid_rect(
                0,
                MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/,
                UI_device_width - current_MMI_theme->scrollbar_size - 1,
                (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + MMI_content_height - 1,
                GDI_COLOR_TRANSPARENT);
        }

        if (cat214_item_count != 0)
        {
            gui_set_vertical_scrollbar_value(&MMI_fixed_list_menu.vbar, cat214_hilighted_index / item_per_page);
            gui_show_vertical_scrollbar(&MMI_fixed_list_menu.vbar);
        }
    }

    /* empty category */
    if (cat214_item_count == 0)
    {
        gdi_layer_pop_clip();
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        return;
    }

    /* draw each item */
    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)
            {
                is_hilighted = (index == cat214_hilighted_index) ? TRUE : FALSE;

                box_offset_x = box_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                box_offset_y = box_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;

                if (is_redraw_all || (index == cat214_hilighted_index) || (index == cat214_prev_hilighted_index))       /* draw all or changed */
                {
                    /* clear item's background */
                    gdi_draw_solid_rect(
                        box_offset_x - 3,
                        box_offset_y - 3,
                        box_offset_x + box_width + 2,
                        box_offset_y + box_height + 2,
                        GDI_COLOR_TRANSPARENT);

                    if (is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        box_bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        box_bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }

                    /* draw box */
            #ifdef __MMI_MAINLCD_128X128__
                    gdi_draw_solid_rect(
                        box_offset_x,
                        box_offset_y,
                        box_offset_x + box_width - 1,
                        box_offset_y + box_height - 1,
                        box_bg_color);
            #else
                    FillFullTextBackground(box_offset_x,
                                           box_offset_y,
                                           box_offset_x + box_width - 1,
                                           box_offset_y + box_height - 1);

            #endif


                    if (index == cat214_hilighted_index)
                    {
                        /* highlight frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_hilight_color);
                    }
                    else
                    {
                        /* draw frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_frame_color);
                    }

                    /* call draw image callback function */
                    if (cat214_draw_image_callback != NULL)
                    {
                        cat214_draw_image_callback(
                            index,
                            cur_page_index,
                            cur_page_index + item_per_page - 1,
                            is_hilighted,
                            TRUE,           /* need update */
                            is_redraw_all,  /* new page */
                            box_offset_x,
                            box_offset_y,
                            box_offset_x + box_width - 1,
                            box_offset_y + box_height - 1);

                    }

                }
                else
                {

                    if (index == cat214_hilighted_index)
                    {
                        /* highlight frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_hilight_color);
                    }
                    else
                    {
                        if (index == cat214_prev_hilighted_index)
                        {
                            /* clear highlight frame with transparent color */
                            gdi_draw_rect(
                                box_offset_x - 1,
                                box_offset_y - 1,
                                box_offset_x + box_width,
                                box_offset_y + box_height,
                                box_frame_color);
                        }
                    }

                    /* call draw image callback function */
                    if (cat214_draw_image_callback != NULL)
                    {
                        cat214_draw_image_callback(
                            index,
                            cur_page_index,
                            cur_page_index + item_per_page - 1,
                            is_hilighted,
                            FALSE,  /* not need update */
                            FALSE,  /* not new page */
                            box_offset_x,
                            box_offset_y,
                            box_offset_x + box_width - 1,
                            box_offset_y + box_height - 1);

                    }
                }

            }
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory214BoxSize
 * DESCRIPTION
 *  Get 214 box size
 * PARAMETERS
 *  num_per_row         [IN]        N     number per row
 *  num_per_col         [IN]        Number per column
 *  box_width_ptr       [OUT]       Box width ptr
 *  box_height_ptr      [OUT]       Box height ptr
 * RETURNS
 *  void
 *****************************************************************************/
void GetCategory214BoxSize(S32 num_per_row, S32 num_per_col, S32 *box_width_ptr, S32 *box_height_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *box_width_ptr = MMI_content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (num_per_col - 1);
    *box_width_ptr /= num_per_col;

    *box_height_ptr = MMI_content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (num_per_row - 1);
    *box_height_ptr /= num_per_row;
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyUpHdlr
 * DESCRIPTION
 *  Category 214 key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyUpHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index - cat214_num_per_col;

    /* move to last if needed */
    if (moved_index < 0)
    {
        cat214_hilighted_index = cat214_item_count - 1;
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyDownHdlr
 * DESCRIPTION
 *  Category 214 key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyDownHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index + cat214_num_per_col;
    
    /* move to first if needed */
    if (moved_index >= cat214_item_count)
    {
        if (((cat214_hilighted_index)%(cat214_num_per_col*cat214_num_per_row))>(cat214_num_per_col*cat214_num_per_row - cat214_num_per_col -1)
            && ((cat214_item_count-1)%(cat214_num_per_col*cat214_num_per_row))<(cat214_num_per_col*cat214_num_per_row - cat214_num_per_col - 1))
            cat214_hilighted_index = cat214_item_count - 1;
        else
            cat214_hilighted_index = (cat214_prev_hilighted_index%cat214_num_per_col);
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyLeftHdlr
 * DESCRIPTION
 *  Category 214 key left handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyLeftHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index - 1;

    /* move to last if needed */
    if (moved_index < 0)
    {
        cat214_hilighted_index = cat214_item_count - 1;
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyRightHdlr
 * DESCRIPTION
 *  Category 214 key right handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyRightHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index + 1;

    /* move to first if needed */
    if (moved_index >= cat214_item_count)
    {
        cat214_hilighted_index = 0;
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214ShortCutHdlr
 * DESCRIPTION
 *  Category 214 shot cut key press handler
 * PARAMETERS
 *  item_index      [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    if (item_index < cat214_item_count)
    {
        cat214_prev_hilighted_index = cat214_hilighted_index;
        cat214_hilighted_index = (U16) item_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate214CategoryControlArea
 * DESCRIPTION
 *  Draw category 214 control area
 * PARAMETERS
 *  coordinate      [IN]        Cooridinate
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate214CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear background */
    if (r2lMMIFlag)
    {
        gdi_draw_solid_rect(
            current_MMI_theme->scrollbar_size,
            MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/,
            UI_device_width - 1,
            (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + MMI_content_height - 1,
            GDI_COLOR_TRANSPARENT);

    }
    else
    {
        gdi_draw_solid_rect(
            0,
            MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/,
            UI_device_width - current_MMI_theme->scrollbar_size - 1,
            (MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/) + MMI_content_height - 1,
            GDI_COLOR_TRANSPARENT);
    }

    Cat214RedrawMatrix();

    /* if is emtpty folder, show a empty string */
    if (cat214_item_count == 0)
    {
        gui_reset_clip();
        gui_set_font(&MMI_medium_font);
        //gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenDownHdlr
 * DESCRIPTION
 *  Cat 214 pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenDownHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    BOOL is_redraw_all;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    cat214_pen_down_on_scroll = FALSE;

    /* Scroll bar */
    if (gui_vertical_scrollbar_translate_pen_event(
            &MMI_fixed_list_menu.vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param))
    {
        cat214_pen_down_on_scroll = TRUE;

        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

            if (index >= cat214_item_count)
            {
                index = cat214_item_count - 1;
            }

            Cat214ShortCutHdlr(index);
        }
        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    Cat214ShortCutHdlr(index);
                    cat214_pen_down_index = index;
                    return MMI_TRUE;
                }
            }
        }
    }

    cat214_pen_down_index = -1;
    return MMI_FALSE;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenMoveHdlr
 * DESCRIPTION
 *  Cat 214 pen move hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenMoveHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    BOOL is_redraw_all;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    if (cat214_pen_down_on_scroll)
    {
        /* Scroll bar */
        if (gui_vertical_scrollbar_translate_pen_event(
                &MMI_fixed_list_menu.vbar,
                MMI_PEN_EVENT_MOVE,
                pos.x,
                pos.y,
                &scrollbar_event,
                &scrollbar_param))
        {
            if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
            {
                index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

                if (index >= cat214_item_count)
                {
                    index = cat214_item_count - 1;
                }

                Cat214ShortCutHdlr(index);
            }
        }
        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    Cat214ShortCutHdlr(index);
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenUpHdlr
 * DESCRIPTION
 *  Cat 214 pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenUpHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    if (cat214_pen_down_on_scroll)
    {
        if (gui_vertical_scrollbar_translate_pen_event(
                &MMI_fixed_list_menu.vbar,
                MMI_PEN_EVENT_UP,
                pos.x,
                pos.y,
                &scrollbar_event,
                &scrollbar_param))

        {
            cat214_pen_down_on_scroll = FALSE;
        }
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

            if (index >= cat214_item_count)
            {
                index = cat214_item_count - 1;
            }

            Cat214ShortCutHdlr(index);
        }

        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y/*MMI_title_y + MMI_title_height*/;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    if (cat214_pen_down_index == index)
                    {
                        execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
                    }

                    cat214_pen_down_index = -1;
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

