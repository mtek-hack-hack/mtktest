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
 *  gui_calendar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  calendar - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

#include "gui.h"
#include "gui_themes.h"
#include "gui_calendar.h"
#include "wgui_clock.h"
#include "DebugInitDef.h"
#include "wgui_categories_defs.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "UCS2Prot.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "touchScreenGprot.h"
#include "Wgui_status_icons.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

void gui_calendar_create(
        gui_calendar_struct *c,
        U32 calendar_type,
        U32 row_num,
        U32 column_num,
        U8 *cell_buf,
        U8 *popup_buf);
void gui_calendar_set_bg(gui_calendar_struct* c, UI_image_ID_type bg_id);
void gui_calendar_set_select_horizontal1(
        gui_calendar_struct *c,
        UI_image_ID_type left_up,
        UI_image_ID_type left_down,
        UI_image_ID_type right_up,
        UI_image_ID_type right_down,
        U8 *string,
        U32 align_type);
void gui_calendar_set_select_horizontal1_string(gui_calendar_struct* c, U8 *string);
void gui_calendar_set_select_horizontal1_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler);
void gui_calendar_set_select_horizontal2(
        gui_calendar_struct *c,
        UI_image_ID_type left_up,
        UI_image_ID_type left_down,
        UI_image_ID_type right_up,
        UI_image_ID_type right_down,
        U8 *string,
        U32 align_type);
void gui_calendar_set_select_horizontal2(
        gui_calendar_struct *c,
        UI_image_ID_type left_up,
        UI_image_ID_type left_down,
        UI_image_ID_type right_up,
        UI_image_ID_type right_down,
        U8 *string,
        U32 align_type);
void gui_calendar_set_select_horizontal2_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler);
void gui_calendar_set_select_vertical(
        gui_calendar_struct *c,
        UI_image_ID_type top_up,
        UI_image_ID_type top_down,
        UI_image_ID_type bottom_up,
        UI_image_ID_type bottom_down,
        U8 **string_list,
        U32 align_type);
void gui_calendar_set_select_vertical_string(gui_calendar_struct* c, U8 **string_list);
void gui_calendar_set_select_vertical_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr top_handler,
        GUICalendarV2EventFuncPtr bottom_handler);
void gui_calendar_set_normal_title(gui_calendar_struct* c, U8 *string);
void gui_calendar_set_menstrual_title(
        gui_calendar_struct *c,
        U8 color_index1,
        U8 *string1,
        U8 color_index2,
        U8 *string2);
void gui_calendar_set_horizontal_string(gui_calendar_struct* c, U8 **string_list, S32 underline_index);
void gui_calendar_set_cell_array(
        gui_calendar_struct *c,
        gui_calendar_cell_struct *cell,
        U8 cell_bg_fill_type,
        U8 cell_text_display_type,
        U8 cell_icon_display_type);
void gui_calendar_set_current(gui_calendar_struct* c, U32 current_row, U32 current_column);
void gui_calendar_set_highlight(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column);
void gui_calendar_set_popup(gui_calendar_struct* c, U8 *message1, U8 *message2, U8 *message3);
void gui_calendar_update_base_layer(gui_calendar_struct *c);
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
void gui_calendar_set_infobox(gui_calendar_struct* c, UI_image_ID_type *icon_list, U8 **string_list, U8 entry_num);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
void gui_calendar_register_cell_highlight_handler(gui_calendar_struct *c,
                                                  MMI_BOOL(*app_cell_highlight_handler) (U32 highlighted_row,
                                                                                         U32 highlighted_column));
void gui_calendar_register_left_arrow_key_handler(gui_calendar_struct *c,
                                                  MMI_BOOL(*app_left_arrow_key_handler) (U32 highlighted_row,
                                                                                         U32 highlighted_column));
void gui_calendar_register_right_arrow_key_handler(gui_calendar_struct *c,
                                                   MMI_BOOL(*app_right_arrow_key_handler) (U32 highlighted_row,
                                                                                           U32 highlighted_column));
void gui_calendar_register_up_arrow_key_handler(gui_calendar_struct *c,
                                                MMI_BOOL(*app_up_arrow_key_handler) (U32 highlighted_row,
                                                                                     U32 highlighted_column));
void gui_calendar_register_down_arrow_key_handler(gui_calendar_struct *c,
                                                  MMI_BOOL(*app_down_arrow_key_handler) (U32 highlighted_row,
                                                                                         U32 highlighted_column));
void gui_calendar_register_up_side_key_handler(gui_calendar_struct *c,
                                               MMI_BOOL(*app_up_side_key_handler) (U32 highlighted_row,
                                                                                   U32 highlighted_column));
void gui_calendar_register_down_side_key_handler(gui_calendar_struct *c,
                                                 MMI_BOOL(*app_down_side_key_handler) (U32 highlighted_row,
                                                                                       U32 highlighted_column));
static void gui_calendar_HandleKeyRight(void);
static void gui_calendar_HandleKeyLeft(void);
static void gui_calendar_HandleKeyUp(void);
static void gui_calendar_HandleKeyDown(void);
static void gui_calendar_HandleSideKeyUp(void);
static void gui_calendar_HandleSideKeyDown(void);
static void gui_calendar_set_keyhandler(gui_calendar_struct* c);

#ifdef __MMI_TOUCH_SCREEN__
static void gui_calendar_translate_pen_position(gui_calendar_struct* c, S32 x, S32 y, U32* pen_row, U32* pen_column);
static MMI_BOOL gui_calendar_PenDownHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenUpHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenMoveHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
MMI_BOOL gui_calendar_translate_pen_event(gui_calendar_struct *c, mmi_pen_event_type_enum pen_event, S16 x, S16 y);
#endif /*__MMI_TOUCH_SCREEN__*/
void gui_calendar_close(gui_calendar_struct* c);
static void gui_calendar_redraw_bg(gui_calendar_struct* c);
static void gui_calendar_redraw_select_horizontal1(gui_calendar_struct* c);
static void gui_calendar_redraw_select_horizontal2(gui_calendar_struct* c);
static void gui_calendar_redraw_horizontal_string(gui_calendar_struct* c);
static void gui_calendar_redraw_select_vertical(gui_calendar_struct* c);
static void gui_calendar_redraw_normal_title(void);
static void gui_calendar_redraw_menstrual_title(void);
void gui_calendar_redraw_cell_array(gui_calendar_struct* c);
static void gui_calendar_redraw_cell(
                gui_calendar_struct *c,
                S32 cell_x,
                S32 cell_y,
                S32 cell_width,
                S32 cell_height,
                gui_calendar_cell_struct *cell);
static void gui_calendar_redraw_popup(void);

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
static void gui_calendar_redraw_infobox(gui_calendar_struct* c);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
static void gui_calendar_highlight_cell(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column);
static void gui_calendar_unhighlight_cell(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column);
void gui_calendar_show(gui_calendar_struct* c);

UI_calendar_theme *current_calendar_theme = NULL;
static gui_calendar_struct* current_calendar_pointer = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_current_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_current_theme(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->title_fg = current_calendar_theme->title_fg;
    c->horizontal_select_fg = current_calendar_theme->horizontal_select_fg;
    c->horizontal_select_border = current_calendar_theme->horizontal_select_border;
    c->vertical_select_fg = current_calendar_theme->vertical_select_fg;
    c->horizontal_string_fg = current_calendar_theme->horizontal_string_fg;
    for (i = 0; i < GUI_CALENDAR_COLOR_TOTAL; i ++)
    {
        c->cell_bg[i] = current_calendar_theme->cell_bg[i];
    }
    c->cell_valid_fg = current_calendar_theme->cell_valid_fg;
    c->cell_invalid_fg = current_calendar_theme->cell_invalid_fg;
    c->cell_highlight = current_calendar_theme->cell_highlight;
    c->horizontal_string_font = current_calendar_theme->horizontal_string_font;
    c->cell_font = current_calendar_theme->cell_font;
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    c->infobox_bg = current_calendar_theme->infobox_bg;
    c->infobox_entry_bg = current_calendar_theme->infobox_entry_bg;
    c->infobox_fg = current_calendar_theme->infobox_fg;
    c->infobox_font = current_calendar_theme->infobox_font;
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 *  t       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_theme(gui_calendar_struct *c, UI_calendar_theme *t)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->title_fg = t->title_fg;
    c->horizontal_select_fg = t->horizontal_select_fg;
    c->horizontal_select_border = t->horizontal_select_border;
    c->vertical_select_fg = t->vertical_select_fg;
    c->horizontal_string_fg = t->horizontal_string_fg;
    for (i = 0; i < GUI_CALENDAR_COLOR_TOTAL; i ++)
    {
        c->cell_bg[i] = t->cell_bg[i];
    }
    c->cell_valid_fg = t->cell_valid_fg;
    c->cell_invalid_fg = t->cell_invalid_fg;
    c->cell_highlight = t->cell_highlight;
    c->horizontal_string_font = t->horizontal_string_font;
    c->cell_font = t->cell_font;
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    c->infobox_bg = t->infobox_bg;
    c->infobox_entry_bg = t->infobox_entry_bg;
    c->infobox_fg = t->infobox_fg;
    c->infobox_font = t->infobox_font;
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_create
 * DESCRIPTION
 *  initialize the settings of calendar
 * PARAMETERS
 *  gui_calendar_struct* [IN]
 *  calendar_type       [IN]        Calendar type <- GUI_CALENDAR_INIT_TYPE
 *  row_num             [IN]        Number of row
 *  column_num          [IN]        Number of column
 *  cell_buf            [IN]        Buffer for cache 1 cell
 *  popup_buf           [IN]        Buffer for cache 1 popup
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_create(
        gui_calendar_struct *c,
        U32 calendar_type,
        U32 row_num,
        U32 column_num,
        U8 *cell_buf,
        U8 *popup_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    switch (calendar_type)
    {
        case GUI_CALENDAR_NORMAL:
            c->vertical_select_display = MMI_TRUE;
            c->content_x = 0;
            c->content_y = 0;
            c->content_width = UI_device_width;
            c->content_height = UI_device_height;
            c->frame_line_pixel = GUI_CALENDAR_FRAME_LINE_PIXEL;
            c->horizontal_select_x = GUI_CALENDAR_FRAME_START_X;
            c->horizontal_select_y = MMI_status_bar_height;
            c->horizontal_select_width = GUI_CALENDAR_FRAME_WIDTH;
            c->horizontal_select_height = GUI_CALENDAR_FRAME_START_Y - c->horizontal_select_y;
            c->title_x = GUI_CALENDAR_FRAME_START_X + c->frame_line_pixel;
            c->title_y = GUI_CALENDAR_FRAME_START_Y + c->frame_line_pixel;
            c->title_width = GUI_CALENDAR_FRAME_WIDTH - c->frame_line_pixel * 2;
            c->title_height = GUI_CALENDAR_TITLE_HEIGHT;
            c->vertical_select_x = GUI_CALENDAR_FRAME_START_X + c->frame_line_pixel;
            c->vertical_select_y = c->title_y + c->title_height + c->frame_line_pixel;
            c->vertical_select_width = GUI_CALENDAR_VERTICAL_SELECT_WIDTH;
            c->vertical_select_height = GUI_CALENDAR_FRAME_HEIGHT + GUI_CALENDAR_BOTTOM_HEIGHT - c->title_height - c->frame_line_pixel * 3;
            c->horizontal_string_x = c->vertical_select_x + c->vertical_select_width + c->frame_line_pixel;
            c->horizontal_string_y = c->vertical_select_y;
            c->horizontal_string_width = GUI_CALENDAR_FRAME_WIDTH - c->vertical_select_width - c->frame_line_pixel * 3;
            c->horizontal_string_height = GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT;
            c->cell_array_x = c->horizontal_string_x;
            c->cell_array_y = c->horizontal_string_y + c->horizontal_string_height + c->frame_line_pixel;
            c->cell_array_width = c->horizontal_string_width;
            c->cell_array_height = c->vertical_select_height - GUI_CALENDAR_BOTTOM_HEIGHT - c->horizontal_string_height - c->frame_line_pixel;
    #ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
            c->infobox_x = GUI_CALENDAR_INFOBOX_START_X;
            c->infobox_y = GUI_CALENDAR_INFOBOX_START_Y;
            c->infobox_width = GUI_CALENDAR_INFOBOX_WIDTH;
            c->infobox_height = GUI_CALENDAR_INFOBOX_HEIGHT;
    #endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 

            break;
            
        case GUI_CALENDAR_SMALL:
            /* adjust for 128X128 &128X160 */
            c->vertical_select_display = MMI_TRUE;
            c->content_x = 0;
            c->content_y = 0;
            c->content_width = UI_device_width;
        #if defined(__MMI_MAINLCD_320X240__)
            c->content_height = UI_device_height;
        #else
            c->content_height = UI_device_height - MMI_button_bar_height;
        #endif
            c->frame_line_pixel = GUI_CALENDAR_FRAME_LINE_PIXEL;
            c->horizontal_select_x = GUI_CALENDAR_FRAME_START_X;
            c->horizontal_select_y = 0;
            c->horizontal_select_width = GUI_CALENDAR_FRAME_WIDTH;
            c->horizontal_select_height = GUI_CALENDAR_FRAME_START_Y - c->horizontal_select_y;
            c->title_x = GUI_CALENDAR_FRAME_START_X + c->frame_line_pixel;
            c->title_y = GUI_CALENDAR_FRAME_START_Y + c->frame_line_pixel;
            c->title_width = GUI_CALENDAR_FRAME_WIDTH - c->frame_line_pixel * 2;
            c->title_height = GUI_CALENDAR_TITLE_HEIGHT;
            c->vertical_select_x = GUI_CALENDAR_FRAME_START_X + c->frame_line_pixel;
            c->vertical_select_y = c->title_y + c->title_height + c->frame_line_pixel;
            c->vertical_select_width = GUI_CALENDAR_VERTICAL_SELECT_WIDTH;
            c->vertical_select_height = GUI_CALENDAR_FRAME_HEIGHT - c->title_height - c->frame_line_pixel * 3;
            c->horizontal_string_x = c->vertical_select_x + c->vertical_select_width + c->frame_line_pixel;
            c->horizontal_string_y = c->vertical_select_y;
            c->horizontal_string_width = GUI_CALENDAR_FRAME_WIDTH - c->vertical_select_width - c->frame_line_pixel * 3;
            c->horizontal_string_height = GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT;
            c->cell_array_x = c->horizontal_string_x;
            c->cell_array_y = c->horizontal_string_y + c->horizontal_string_height + c->frame_line_pixel;
            c->cell_array_width = c->horizontal_string_width;
            /* subtract GUI_CALENDAR_BOTTOM_HEIGHT to adjust cell array's height */
            c->cell_array_height = c->vertical_select_height - c->horizontal_string_height - GUI_CALENDAR_BOTTOM_HEIGHT - c->frame_line_pixel;
            break;

        case GUI_CALENDAR_IDLE_NORMAL:

            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    c->pen_unable = MMI_FALSE;
#endif
    
    c->row_num = row_num;
    c->column_num = column_num;
    c->cell_width = (c->cell_array_width - (c->column_num - 1) * c->frame_line_pixel) / c->column_num;
    c->cell_height = (c->cell_array_height - (c->row_num - 1) * c->frame_line_pixel) / c->row_num;
    c->cell_cache.buf_ptr = cell_buf;
    c->popup_cache.buf_ptr = popup_buf;
/* c->cell_bg[GUI_CALENDAR_COLOR_CURRENT] = current_UI_theme->fixed_text_menuitem_theme->selected_filler->c;*/
    c->highlighted_row = 0xffffffff;
    c->highlighted_column = 0xffffffff;
    c->highlighted_row_old = 0xffffffff;
    c->highlighted_column_old = 0xffffffff;

    c->bg_updated = TRUE;

#ifdef __GDI_MEMORY_PROFILE_2__
    c->bg_layer = GDI_LAYER_EMPTY_HANDLE;
    c->date_layer = GDI_LAYER_EMPTY_HANDLE;
#endif /*__GDI_MEMORY_PROFILE_2__*/

    current_calendar_pointer = c;

    gui_calendar_set_current_theme(c);

    gui_calendar_set_keyhandler(c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]         
 *  bg_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_bg(gui_calendar_struct* c, UI_image_ID_type bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->bg_id = bg_id;
    c->bg_updated = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  left_up         [IN]        
 *  left_down       [IN]        
 *  right_up        [IN]        
 *  right_down      [IN]        
 *  string          [IN]         
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal1(
        gui_calendar_struct *c,
        UI_image_ID_type left_up,
        UI_image_ID_type left_down,
        UI_image_ID_type right_up,
        UI_image_ID_type right_down,
        U8 *string,
        U32 align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[0].left_up = left_up;
    c->horizontal_select[0].left_down = left_down;
    c->horizontal_select[0].right_up = right_up;
    c->horizontal_select[0].right_down = right_down;
    c->horizontal_select[0].string = string;
    c->horizontal_select[0].align_type = align_type;
    c->horizontal_select[0].left_pressed = 0;
    c->horizontal_select[0].right_pressed = 0;
    c->horizontal_select[0].is_updated = TRUE;   

    if (left_up != 0)
    {
        gdi_image_get_dimension_id(
            (U16) left_up,
            &c->horizontal_select[0].left_width,
            &c->horizontal_select[0].left_height);
    }
    else
    {
        c->horizontal_select[0].left_width = c->horizontal_select[0].left_height = 0;
    }

    if (right_up != 0)
    {
        gdi_image_get_dimension_id(
            (U16) right_up,
            &c->horizontal_select[0].right_width,
            &c->horizontal_select[0].right_height);
    }
    else
    {
        c->horizontal_select[0].right_width = c->horizontal_select[0].right_height = 0;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal1_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]     
 *  string      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal1_string(gui_calendar_struct* c, U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[0].string = string;
    c->horizontal_select[0].is_updated = TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal1_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                   [IN]         
 *  left_handler        [IN]        
 *  right_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal1_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[0].left_handler = left_handler;
    c->horizontal_select[0].right_handler = right_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  left_up         [IN]        
 *  left_down       [IN]        
 *  right_up        [IN]        
 *  right_down      [IN]        
 *  string          [IN]         
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal2(
        gui_calendar_struct *c,
        UI_image_ID_type left_up,
        UI_image_ID_type left_down,
        UI_image_ID_type right_up,
        UI_image_ID_type right_down,
        U8 *string,
        U32 align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[1].left_up = left_up;
    c->horizontal_select[1].left_down = left_down;
    c->horizontal_select[1].right_up = right_up;
    c->horizontal_select[1].right_down = right_down;
    c->horizontal_select[1].string = string;
    c->horizontal_select[1].align_type = align_type;
    c->horizontal_select[1].left_pressed = 0;
    c->horizontal_select[1].right_pressed = 0;
    c->horizontal_select[1].is_updated = TRUE;     

    if (left_up != 0)
    {
        gdi_image_get_dimension_id(
            (U16) left_up,
            &c->horizontal_select[1].left_width,
            &c->horizontal_select[1].left_height);
    }
    else
    {
        c->horizontal_select[1].left_width = c->horizontal_select[1].left_height = 0;
    }

    if (right_up != 0)
    {
        gdi_image_get_dimension_id(
            (U16) right_up,
            &c->horizontal_select[1].right_width,
            &c->horizontal_select[1].right_height);
    }
    else
    {
        c->horizontal_select[1].right_width = c->horizontal_select[1].right_height = 0;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]     
 *  string      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal2_string(gui_calendar_struct* c, U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[1].string = string;
    c->horizontal_select[1].is_updated = TRUE; 
}  


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_horizontal2_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                   [IN]         
 *  left_handler        [IN]        
 *  right_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_horizontal2_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_select[1].left_handler = left_handler;
    c->horizontal_select[1].right_handler = right_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_vertical
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  top_up          [IN]        
 *  top_down        [IN]        
 *  bottom_up       [IN]        
 *  bottom_down     [IN]        
 *  string_list     [IN]        
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_vertical(
        gui_calendar_struct *c,
        UI_image_ID_type top_up,
        UI_image_ID_type top_down,
        UI_image_ID_type bottom_up,
        UI_image_ID_type bottom_down,
        U8 **string_list,
        U32 align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->vertical_select.top_up = top_up;
    c->vertical_select.top_down = top_down;
    c->vertical_select.bottom_up = bottom_up;
    c->vertical_select.bottom_down = bottom_down;
    c->vertical_select.string_list = string_list;
    c->vertical_select.align_type = align_type;
    c->vertical_select.top_pressed = 0;
    c->vertical_select.bottom_pressed = 0;
    c->vertical_select.is_updated = TRUE;

    if (top_up != 0)
    {
        gdi_image_get_dimension_id((U16)top_up, &c->vertical_select.top_width, &c->vertical_select.top_height);
    }
    else
    {
        c->vertical_select.top_width = c->vertical_select.top_height = 0;
    }

    if (bottom_up != 0)
    {
        gdi_image_get_dimension_id((U16)top_up, &c->vertical_select.bottom_width, &c->vertical_select.bottom_height);
    }
    else
    {
        c->vertical_select.bottom_width = c->vertical_select.bottom_height = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_vertical_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  string_list     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_vertical_string(gui_calendar_struct* c, U8 **string_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->vertical_select.string_list = string_list;
    c->vertical_select.is_updated = TRUE;
}  


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_select_vertical_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                   [IN]         
 *  top_handler         [IN]        
 *  bottom_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_select_vertical_handler(
        gui_calendar_struct *c,
        GUICalendarV2EventFuncPtr top_handler,
        GUICalendarV2EventFuncPtr bottom_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->vertical_select.top_handler = top_handler;
    c->vertical_select.bottom_handler = bottom_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_normal_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]     
 *  string      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_normal_title(gui_calendar_struct* c, U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->title.string1 = string;
    c->title.show_title= gui_calendar_redraw_normal_title;
    c->title.is_updated = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_menstrual_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                   [IN]         
 *  color_index1        [IN]        
 *  string1             [IN]         
 *  color_index2        [IN]        
 *  string2             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_menstrual_title(
        gui_calendar_struct *c,
        U8 color_index1,
        U8 *string1,
        U8 color_index2,
        U8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->title.color_index1 = color_index1;
    c->title.string1 = string1;
    c->title.color_index2 = color_index2;
    c->title.string2 = string2;
    c->title.show_title= gui_calendar_redraw_menstrual_title;
    c->title.is_updated = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_horizontal_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  string_list     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_horizontal_string(gui_calendar_struct* c, U8 **string_list, S32 underline_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->horizontal_string.string_list = string_list;
    c->horizontal_string.is_updated = TRUE;
    c->horizontal_string.underline_index = underline_index;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_cell_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                           [IN]         
 *  cell                        [IN]         
 *  cell_bg_fill_type           [IN]        
 *  cell_text_display_type      [IN]        
 *  cell_icon_display_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_cell_array(
        gui_calendar_struct *c,
        gui_calendar_cell_struct *cell,
        U8 cell_bg_fill_type,
        U8 cell_text_display_type,
        U8 cell_icon_display_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->cell_array.cell = cell;
    c->cell_array.bg_fill_type= cell_bg_fill_type;
    c->cell_array.text_display_type = cell_text_display_type;
    c->cell_array.icon_display_type = cell_icon_display_type;
    c->cell_array.is_updated = TRUE;
#ifdef __MMI_TOUCH_SCREEN__
    c->cell_array.pen_on_highlighted = FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_current
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                   [IN]         
 *  current_row         [IN]        
 *  current_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_current(gui_calendar_struct* c, U32 current_row, U32 current_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->current_row = current_row;
    c->current_column = current_column;
    c->cell_array.is_updated = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]         
 *  highlighted_row         [IN]        
 *  highlighted_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_highlight(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->highlighted_row_old = c->highlighted_row;
    c->highlighted_column_old = c->highlighted_column;
    c->highlighted_row = highlighted_row;
    c->highlighted_column = highlighted_column;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]     
 *  message1        [IN]     
 *  message2        [IN]     
 *  message3        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_popup(gui_calendar_struct* c, U8 *message1, U8 *message2, U8 *message3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->popup.message1 = message1;
    c->popup.message2 = message2;
    c->popup.message3 = message3;
    c->popup.need_popup = TRUE;
}

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_infobox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  icon_list       [IN]         
 *  string_list     [IN]        
 *  entry_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_infobox(gui_calendar_struct* c, UI_image_ID_type *icon_list, U8 **string_list, U8 entry_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->infobox.icon_list = icon_list;
    c->infobox.string_list = string_list;
    MMI_ASSERT(entry_num <= GUI_CALENDAR_MAX_INFOBOX);
    c->infobox.num_of_entry = entry_num;
    c->infobox.is_updated = TRUE;
}
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_cell_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_cell_highlight_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_cell_highlight_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_cell_highlight_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppCellHighlightHanlder = app_cell_highlight_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_left_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_left_arrow_key_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_left_arrow_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_left_arrow_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppLeftArrowKeyHanlder = app_left_arrow_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_right_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_right_arrow_key_handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_right_arrow_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_right_arrow_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppRightArrowKeyHanlder = app_right_arrow_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_up_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_up_arrow_key_handler        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_up_arrow_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_up_arrow_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppUpArrowKeyHanlder = app_up_arrow_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_down_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_down_arrow_key_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_down_arrow_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_down_arrow_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppDownArrowKeyHanlder = app_down_arrow_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_up_side_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                           [IN]         
 *  app_up_side_key_handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_up_side_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_up_side_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppUpSideKeyHanlder = app_up_side_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_down_side_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                               [IN]         
 *  app_down_side_key_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_down_side_key_handler(
        gui_calendar_struct *c,
        MMI_BOOL(*app_down_side_key_handler) (U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->AppDownSideKeyHanlder = app_down_side_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleKeyRight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_row, temp_column;

    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);

    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }

    temp_row = c->highlighted_row;
    temp_column = c->highlighted_column + 1;

    if ((temp_row < c->row_num) && (temp_column < c->column_num) && 
        (gui_calendar_cell_struct*)(c->cell_array.cell+temp_row*c->column_num+temp_column)->valid)
    {        
        c->highlighted_row_old = c->highlighted_row;
        c->highlighted_column_old = c->highlighted_column;
        c->highlighted_row = temp_row;
        c->highlighted_column = temp_column;

        gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);

        /* Infobox */
        
    }
    else
    {
        if (c->AppRightArrowKeyHanlder)
        {
            if (c->AppRightArrowKeyHanlder(c->highlighted_row, c->highlighted_column))
            {
                gui_calendar_show(c);
            }
        }
    }

    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleKeyLeft
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_row, temp_column;
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }
    
    temp_row = c->highlighted_row;
    temp_column = c->highlighted_column - 1;

    if ((temp_row < c->row_num) && (temp_column < c->column_num) && 
        (gui_calendar_cell_struct*)(c->cell_array.cell+temp_row*c->column_num+temp_column)->valid)
    {        
        c->highlighted_row_old = c->highlighted_row;
        c->highlighted_column_old = c->highlighted_column;
        c->highlighted_row = temp_row;
        c->highlighted_column = temp_column;

        gui_calendar_unhighlight_cell(c,c->highlighted_row_old, c->highlighted_column_old);
        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);

        /* Infobox */
        
    }
    else
    {
        if (c->AppLeftArrowKeyHanlder)
        {
            if (c->AppLeftArrowKeyHanlder(c->highlighted_row, c->highlighted_column))
            {
                gui_calendar_show(c);
            }
        }
    }

    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleKeyUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleKeyUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_row ,temp_column;

    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }

    temp_row = c->highlighted_row - 1;
    temp_column = c->highlighted_column;

    if ((temp_row < c->row_num) && (temp_column < c->column_num) && 
        (gui_calendar_cell_struct*)(c->cell_array.cell+temp_row*c->column_num+temp_column)->valid)
    {        
        c->highlighted_row_old = c->highlighted_row;
        c->highlighted_column_old = c->highlighted_column;
        c->highlighted_row = temp_row;
        c->highlighted_column = temp_column;

        gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);

        /* Infobox */
        
    }
    else
    {
        if (c->AppUpArrowKeyHanlder)
        {
            if (c->AppUpArrowKeyHanlder(c->highlighted_row, c->highlighted_column))
            {
                gui_calendar_show(c);
            }
        }
    }

    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleKeyDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleKeyDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_row ,temp_column;

    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }

    temp_row = c->highlighted_row + 1;
    temp_column = c->highlighted_column;

    if ((temp_row < c->row_num) && (temp_column < c->column_num) && 
        (gui_calendar_cell_struct*)(c->cell_array.cell+temp_row*c->column_num+temp_column)->valid)
    {        
        c->highlighted_row_old = c->highlighted_row;
        c->highlighted_column_old = c->highlighted_column;
        c->highlighted_row = temp_row;
        c->highlighted_column = temp_column;

        gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);

        /* Infobox */
        
    }
    else
    {
        if (c->AppDownArrowKeyHanlder)
        {
            if (c->AppDownArrowKeyHanlder(c->highlighted_row, c->highlighted_column))
            {
                gui_calendar_show(c);
            }
        }
    }

    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleSideKeyUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleSideKeyUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }
    
    if (c->AppUpSideKeyHanlder)
    {
        if (c->AppUpSideKeyHanlder(c->highlighted_row, c->highlighted_column))
        {
            gui_calendar_show(c);
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_HandleSideKeyDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_HandleSideKeyDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    if (c->AppCellHighlightHanlder == NULL)
    {
        return;
    }

    if (c->AppDownSideKeyHanlder)
    {
        if (c->AppDownSideKeyHanlder(c->highlighted_row, c->highlighted_column))
        {
            gui_calendar_show(c);
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_keyhandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_set_keyhandler(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    SetKeyHandler(gui_calendar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(gui_calendar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(gui_calendar_HandleKeyUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleKeyUp, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(gui_calendar_HandleKeyDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleKeyDown, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(gui_calendar_HandleSideKeyUp, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleSideKeyUp, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(gui_calendar_HandleSideKeyDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_HandleSideKeyDown, KEY_VOL_DOWN, KEY_LONG_PRESS);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  x               [IN]        
 *  y               [IN]        
 *  pen_row         [IN]         
 *  pen_column      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_translate_pen_position(gui_calendar_struct* c, S32 x, S32 y, U32* pen_row, U32* pen_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if ((x-c->cell_array_x + 1) % (c->cell_width + c->frame_line_pixel) != 0)
    {
        *pen_column = (x - c->cell_array_x + 1) / (c->cell_width + c->frame_line_pixel);
    }
    
    if ((y-c->cell_array_y + 1) % (c->cell_height + c->frame_line_pixel) != 0)
    {
        *pen_row = (y-c->cell_array_y + 1) / (c->cell_height + c->frame_line_pixel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenDownHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    /* horizontal select 1 */
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, c->horizontal_select_x, c->horizontal_select_y, c->horizontal_select_width >> 1,
         c->horizontal_select_height))
    {
        /* left arrow */
        if (PEN_CHECK_BOUND
            (pos.x, pos.y, c->horizontal_select_x + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER,
             c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[0].left_height) >> 1),
             c->horizontal_select[0].left_width, c->horizontal_select[0].left_height))
        {
            gdi_layer_lock_frame_buffer();
            c->horizontal_select[0].left_pressed = 1;
            gui_calendar_redraw_select_horizontal1(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->horizontal_select_x,
                c->horizontal_select_y,
                c->horizontal_select_x + (c->horizontal_select_width >> 1) - 1,
                c->horizontal_select_y + c->horizontal_select_height - 1);
            c->horizontal_select[0].left_pressed = 0;
            c->horizontal_select[0].is_updated = 1;
            if(c->horizontal_select[0].left_handler)
            {
                if(c->horizontal_select[0].left_handler(c->highlighted_row, c->highlighted_column))
                {
                    gui_calendar_show(c);
                    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
                }
            }
        }

        /* right arrow */
        if (PEN_CHECK_BOUND
            (pos.x, pos.y,
             c->horizontal_select_x + (c->horizontal_select_width >> 1) - c->horizontal_select[0].right_width -
             GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER,
             c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[0].right_height) >> 1),
             c->horizontal_select[0].right_width, c->horizontal_select[0].right_height))
        {
            gdi_layer_lock_frame_buffer();
            c->horizontal_select[0].right_pressed = 1;
            gui_calendar_redraw_select_horizontal1(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->horizontal_select_x,
                c->horizontal_select_y,
                c->horizontal_select_x + (c->horizontal_select_width >> 1) - 1,
                c->horizontal_select_y + c->horizontal_select_height - 1);
            c->horizontal_select[0].right_pressed = 0;
            c->horizontal_select[0].is_updated = 1;
            if(c->horizontal_select[0].right_handler)
            {
                if(c->horizontal_select[0].right_handler(c->highlighted_row, c->highlighted_column))
                {
                    gui_calendar_show(c);
                    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
                }
            }
        }
    }

    /* horizontal select 2 */
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, c->horizontal_select_x + (c->horizontal_select_width >> 1), c->horizontal_select_y,
         c->horizontal_select_width >> 1, c->horizontal_select_height))
    {
        /* left arrow */
        if (PEN_CHECK_BOUND
            (pos.x, pos.y,
             c->horizontal_select_x + (c->horizontal_select_width >> 1) + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER,
             c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[1].left_height) >> 1),
             c->horizontal_select[1].left_width, c->horizontal_select[1].left_height))
        {
            gdi_layer_lock_frame_buffer();
            c->horizontal_select[1].left_pressed = 1;
            gui_calendar_redraw_select_horizontal2(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->horizontal_select_x + (c->horizontal_select_width >> 1),
                c->horizontal_select_y,
                c->horizontal_select_x + c->horizontal_select_width - 1,
                c->horizontal_select_y + c->horizontal_select_height - 1);
            c->horizontal_select[1].left_pressed = 0;
            c->horizontal_select[1].is_updated = 1;
            if(c->horizontal_select[1].left_handler)
            {
                if(c->horizontal_select[1].left_handler(c->highlighted_row, c->highlighted_column))
                {
                    gui_calendar_show(c);
                    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
                }
            }
        }

        /* right arrow */
        if (PEN_CHECK_BOUND
            (pos.x, pos.y,
             c->horizontal_select_x + c->horizontal_select_width - c->horizontal_select[0].right_width -
             GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER,
             c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[1].right_height) >> 1),
             c->horizontal_select[1].right_width, c->horizontal_select[1].right_height))
        {
            gdi_layer_lock_frame_buffer();
            c->horizontal_select[1].right_pressed = 1;
            gui_calendar_redraw_select_horizontal2(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->horizontal_select_x + (c->horizontal_select_width >> 1),
                c->horizontal_select_y,
                c->horizontal_select_x + c->horizontal_select_width - 1,
                c->horizontal_select_y + c->horizontal_select_height - 1);
            c->horizontal_select[1].right_pressed = 0;
            c->horizontal_select[1].is_updated = 1;
            if(c->horizontal_select[1].right_handler)
            {
                if(c->horizontal_select[1].right_handler(c->highlighted_row, c->highlighted_column))
                {
                    gui_calendar_show(c);
                    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
                }
            }
        }
    }

    /* vertical select */
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, c->vertical_select_x, c->vertical_select_y, c->vertical_select_width, c->vertical_select_height))
    {
        /* top arrow */
        if (PEN_CHECK_BOUND
            (pos.x, pos.y, c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
             c->vertical_select_y + 1, c->vertical_select.top_width, c->vertical_select.top_height))
        {
            gdi_layer_lock_frame_buffer();
            c->vertical_select.top_pressed = 1;
            c->vertical_select.bottom_pressed = 0;
            gui_calendar_redraw_select_vertical(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->vertical_select_x,
                c->vertical_select_y,
                c->vertical_select_x + c->vertical_select_width - 1,
                c->vertical_select_y + c->vertical_select_height - 1);
            c->vertical_select.top_pressed = 0;
            c->vertical_select.is_updated = 1;
            if(c->vertical_select.top_handler)
            {
                c->vertical_select.top_handler(c->highlighted_row, c->highlighted_column);
            }
            gui_calendar_show(c);
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        }

        /* bottom arrow */
        else if (PEN_CHECK_BOUND
            (pos.x, pos.y, c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
             c->vertical_select_y + c->vertical_select_height - c->vertical_select.bottom_height - 1,
             c->vertical_select.bottom_width, c->vertical_select.bottom_height))
        {
            gdi_layer_lock_frame_buffer();
            c->vertical_select.bottom_pressed = 1;
            c->vertical_select.top_pressed = 0;
            gui_calendar_redraw_select_vertical(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->vertical_select_x,
                c->vertical_select_y,
                c->vertical_select_x + c->vertical_select_width - 1,
                c->vertical_select_y + c->vertical_select_height - 1);
            c->vertical_select.bottom_pressed = 0;
            c->vertical_select.is_updated = 1;
            if(c->vertical_select.bottom_handler)
            {
                c->vertical_select.bottom_handler(c->highlighted_row, c->highlighted_column);
            }
            gui_calendar_show(c);
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        }
    }

    /* cell array */
    if (PEN_CHECK_BOUND(pos.x, pos.y, c->cell_array_x, c->cell_array_y, c->cell_array_width, c->cell_array_height))
    {
        U32 pen_row = 0xffffffff;
        U32 pen_column = 0xffffffff;
        
        gui_calendar_translate_pen_position(c, pos.x, pos.y, &pen_row, &pen_column);

        if (pen_row >= c->row_num || pen_column >= c->column_num)
        {
            return MMI_FALSE;
        }

        if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
        {
            if ((c->highlighted_row == pen_row) && (c->highlighted_column == pen_column))
            {
                c->cell_array.pen_on_highlighted = TRUE;
            }
            else if((gui_calendar_cell_struct*)(c->cell_array.cell + pen_row * c->column_num + pen_column)->valid)
            {
                c->highlighted_row_old = c->highlighted_row;
                c->highlighted_column_old = c->highlighted_column;
                c->highlighted_row = pen_row;
                c->highlighted_column = pen_column;
                gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
                gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);
                gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            }
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenUpHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    /* cell array */
    if (PEN_CHECK_BOUND(pos.x, pos.y, c->cell_array_x, c->cell_array_y, c->cell_array_width, c->cell_array_height))
    {
        U32 pen_row = 0xffffffff;
        U32 pen_column = 0xffffffff;
        
        gui_calendar_translate_pen_position(c, pos.x, pos.y, &pen_row, &pen_column);

        if (pen_row >= c->row_num || pen_column >= c->column_num)
        {
            return MMI_FALSE;
        }

        if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
        {
            if ((c->highlighted_row == pen_row) && (c->highlighted_column == pen_column))
            {
                if (c->cell_array.pen_on_highlighted == TRUE)
                {
                    c->cell_array.pen_on_highlighted = FALSE;
                    if (GetKeyHandler(KEY_LSK, KEY_EVENT_UP))
                    {
                        /* Some softkey handlers use GetkeyInfo() */
                        SetkeyInfo(KEY_LSK, KEY_EVENT_UP);
                        execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
                    }
                }
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenMoveHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (PEN_CHECK_BOUND(pos.x, pos.y, c->cell_array_x, c->cell_array_y, c->cell_array_width, c->cell_array_height))
    {
        U32 pen_row = 0xffffffff;
        U32 pen_column = 0xffffffff;

        gui_calendar_translate_pen_position(c, pos.x, pos.y, &pen_row, &pen_column);

        if (pen_row >= c->row_num || pen_column >= c->column_num)
        {
            return MMI_FALSE;
        }

        if ((c->highlighted_row == pen_row) && (c->highlighted_column == pen_column) &&
            (c->cell_array.pen_on_highlighted == TRUE))
        {
            c->cell_array.pen_on_highlighted = TRUE;
        }
        else
        {
            if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
            {
                if ((c->highlighted_row != pen_row) || (c->highlighted_column != pen_column))
                {
                    if((gui_calendar_cell_struct*)(c->cell_array.cell + pen_row * c->column_num + pen_column)->valid)
                    {
                        c->highlighted_row_old = c->highlighted_row;
                        c->highlighted_column_old = c->highlighted_column;
                        c->highlighted_row = pen_row;
                        c->highlighted_column = pen_column;
                        gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
                        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);
                        gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
                    }
                }
            }   
            c->cell_array.pen_on_highlighted = FALSE;
        }
    }
    else
    {
        
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_calendar_translate_pen_event(gui_calendar_struct *c, mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_pen_point_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (c->pen_unable == MMI_TRUE)
    {
        return ret;
    }
    
    pos.x = x;
    pos.y = y;
    
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            ret = gui_calendar_PenDownHandler(c, pos);
            break;
            
        case MMI_PEN_EVENT_UP:
            ret = gui_calendar_PenUpHandler(c, pos);
            break;
    
        case MMI_PEN_EVENT_MOVE:
            ret = gui_calendar_PenMoveHandler(c, pos);
            break;

        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
        case MMI_PEN_EVENT_ABORT:
            break;

        default:
            MMI_ASSERT(0);
    }
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_pen_unable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_pen_unable(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->pen_unable = MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_close(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (c->cell_cache_buf != NULL)
    {
        c->cell_cache_buf = NULL;
    }

    if (c->popup_cache_buf != NULL)
    {
        c->popup_cache_buf = NULL;
    }
    
    if (c->popup.need_popup)
    {
        gui_cancel_timer(gui_calendar_redraw_popup); /* stop the timer */
    }

    /* ToDo: clean up selector */
    memset((U8*) &c->horizontal_select[0], 0, sizeof(c->horizontal_select[0]));
    memset((U8*) &c->horizontal_select[1], 0, sizeof(c->horizontal_select[1]));
    memset((U8*) &c->vertical_select, 0, sizeof(c->vertical_select));
    memset((U8*) &c->popup, 0, sizeof(c->popup));

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);

    c->AppCellHighlightHanlder = NULL;
    c->AppLeftArrowKeyHanlder = NULL;
    c->AppRightArrowKeyHanlder = NULL;
    c->AppUpArrowKeyHanlder = NULL;
    c->AppDownArrowKeyHanlder = NULL;
    c->AppUpSideKeyHanlder = NULL;
    c->AppDownSideKeyHanlder = NULL;
    
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    c->infobox.icon_list = NULL;
    c->infobox.string_list = NULL;
    c->infobox.num_of_entry = 0;
    c->infobox.is_updated = FALSE;
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
    /* pop date layer */
    set_status_icon_bar_layer(0, GDI_ERROR_HANDLE);
    gdi_layer_pop_and_restore_active();
    gdi_layer_multi_layer_disable();
    c->bg_layer = GDI_LAYER_EMPTY_HANDLE;
    c->date_layer = GDI_LAYER_EMPTY_HANDLE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_bg(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    if (c->bg_layer == GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_get_base_handle(&c->bg_layer);
        gdi_layer_push_and_set_active(c->bg_layer);
        gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    if (c->date_layer == GDI_LAYER_EMPTY_HANDLE)
    {
        dm_create_layer(0, 0, UI_device_width, UI_device_height, &c->date_layer, DM_LAYER_TOP);
        gdi_layer_push_and_set_active(c->date_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        set_status_icon_bar_layer(0, c->date_layer);
    }
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
    if(c->bg_updated)
    {
        gdi_layer_push_and_set_active(c->bg_layer);
        gdi_image_abm_set_source_layer(c->bg_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            c->content_x,
            c->content_y,
            c->content_x + c->content_width - 1,
            c->content_y + c->content_height - 1);
        gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
        gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_pop_and_restore_active();
#endif
        c->bg_updated = FALSE;
    
    #ifndef __GDI_MEMORY_PROFILE_2__
        c->horizontal_select[0].is_updated = TRUE;
        c->horizontal_select[1].is_updated = TRUE;
        c->vertical_select.is_updated = TRUE;
        c->title.is_updated = TRUE;
        c->horizontal_string.is_updated = TRUE;
        c->cell_array.is_updated = TRUE;
        c->highlighted_row_old = 0xffffffff;
        c->highlighted_column_old = 0xffffffff;
    #endif
    
    #ifdef __GDI_MEMORY_PROFILE_2__
    }
    #endif /* __GDI_MEMORY_PROFILE_2__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_select_horizontal1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_select_horizontal1(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_width, string_x = 0; 
    S32 string_width, string_height;
    UI_image_ID_type icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->horizontal_select_x,
        c->horizontal_select_y,
        c->horizontal_select_x + (c->horizontal_select_width >> 1) - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->horizontal_select_x,
        c->horizontal_select_y,
        c->horizontal_select_x + (c->horizontal_select_width >> 1) - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1,
        GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* left arrow */
    if (c->horizontal_select[0].left_pressed == 0)
    {
        icon_id = c->horizontal_select[0].left_up;
    }
    else
    {
        icon_id = c->horizontal_select[0].left_down;
    }
    if(icon_id != 0)
    {
        gdi_image_draw_id(
            c->horizontal_select_x + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER,
            c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[0].left_height) >> 1),
            (U16) icon_id);
    }

    /* right arrow */
    if (c->horizontal_select[0].right_pressed == 0)
    {
        icon_id = c->horizontal_select[0].right_up;
    }
    else
    {
        icon_id = c->horizontal_select[0].right_down;
    }
    if(icon_id != 0)
    {
        gdi_image_draw_id(
            c->horizontal_select_x + (c->horizontal_select_width >> 1) - c->horizontal_select[0].right_width - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER,
            c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[0].right_height) >> 1),
            (U16) icon_id);
    }

    /* text */
#if defined (__MMI_MAINLCD_128X160__)
    cell_x =
        c->horizontal_select_x + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER + c->horizontal_select[0].left_width;
    cell_width =
        (c->horizontal_select_width >> 1) - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER -
        c->horizontal_select[0].left_width - c->horizontal_select[0].right_width -
        GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER;
#else
    cell_x =
        c->horizontal_select_x + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER + c->horizontal_select[0].left_width + 1;
    cell_width =
        (c->horizontal_select_width >> 1) - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER -
        c->horizontal_select[0].left_width - c->horizontal_select[0].right_width -
        GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER - 2;
#endif
    gdi_layer_set_clip(
        cell_x,
        c->horizontal_select_y,
        cell_x + cell_width - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1);
    
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(c->horizontal_select_fg);
    gui_set_text_border_color(c->horizontal_select_border);

    gui_measure_string((UI_string_type)c->horizontal_select[0].string, &string_width, &string_height);

    if (c->horizontal_select[0].align_type == GUI_CALENDAR_SELECT_ALIGN_CENTER)
    {
        string_x = cell_x + ((cell_width - string_width) >> 1);
        if (r2lMMIFlag)
        {
            string_x += string_width;
        }
    }
    else if (c->horizontal_select[0].align_type == GUI_CALENDAR_SELECT_ALIGN_LEFT)
    {
        string_x = cell_x;
        if (r2lMMIFlag)
        {
            string_x += cell_width;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    gui_move_text_cursor(string_x, c->horizontal_select_y + ((c->horizontal_select_height - string_height) >> 1));
   
    gui_print_bordered_text((UI_string_type)c->horizontal_select[0].string);

    c->horizontal_select[0].is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_select_horizontal2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_select_horizontal2(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_width, string_x; 
    S32 string_width, string_height;
    UI_image_ID_type icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->horizontal_select_x + (c->horizontal_select_width >> 1),
        c->horizontal_select_y,
        c->horizontal_select_x + c->horizontal_select_width - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->horizontal_select_x + (c->horizontal_select_width >> 1),
        c->horizontal_select_y,
        c->horizontal_select_x + c->horizontal_select_width - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1,
        GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* left arrow */
    if (c->horizontal_select[1].left_pressed == 0)
    {
        icon_id = c->horizontal_select[1].left_up;
    }
    else
    {
        icon_id = c->horizontal_select[1].left_down;
    }
    if(icon_id != 0)
    {
        gdi_image_draw_id(
            c->horizontal_select_x + (c->horizontal_select_width >> 1) + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER,
            c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[1].left_height) >> 1),
            (U16) icon_id);
    }

    /* right arrow */
    if (c->horizontal_select[1].right_pressed == 0)
    {
        icon_id = c->horizontal_select[1].right_up;
    }
    else
    {
        icon_id = c->horizontal_select[1].right_down;
    }
    if(icon_id != 0)
    {
        gdi_image_draw_id(
            c->horizontal_select_x + c->horizontal_select_width - c->horizontal_select[0].right_width - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER,
            c->horizontal_select_y + ((c->horizontal_select_height - c->horizontal_select[1].right_height) >> 1),
            (U16) icon_id);
    }

    /* text */
    cell_x =
        c->horizontal_select_x + (c->horizontal_select_width >> 1) + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER +
        c->horizontal_select[1].left_width + 1;
    cell_width =
        (c->horizontal_select_width >> 1) - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER -
        c->horizontal_select[1].left_width - c->horizontal_select[1].right_width -
        GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER - 2;
    gdi_layer_set_clip(
        cell_x,
        c->horizontal_select_y,
        cell_x + cell_width - 1,
        c->horizontal_select_y + c->horizontal_select_height - 1);
    
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(c->horizontal_select_fg);
    gui_set_text_border_color(c->horizontal_select_border);

    gui_measure_string((UI_string_type)c->horizontal_select[1].string, &string_width, &string_height);

    string_x = cell_x + ((cell_width - string_width) >> 1);
    if (r2lMMIFlag)
    {
        string_x += string_width;
    }
    gui_move_text_cursor(string_x, c->horizontal_select_y + ((c->horizontal_select_height - string_height) >> 1));

    gui_print_bordered_text((UI_string_type)c->horizontal_select[1].string);

    c->horizontal_select[1].is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_horizontal_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_horizontal_string(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 string_width, string_height, string_x; 
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->horizontal_string_x,
        c->horizontal_string_y,
        c->horizontal_string_x + c->horizontal_string_width - 1,
        c->horizontal_string_y + c->horizontal_string_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->horizontal_string_x,
        c->horizontal_string_y,
        c->horizontal_string_x + c->horizontal_string_width - 1,
        c->horizontal_string_y + c->horizontal_string_height - 1,
        GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    cell_x = c->horizontal_string_x;
    cell_y = c->horizontal_string_y;
    cell_width = (c->horizontal_string_width - (c->column_num - 1) * c->frame_line_pixel) / c->column_num;
    cell_height = c->horizontal_string_height;
    gui_set_font(c->horizontal_string_font);
    gui_set_text_color(c->horizontal_string_fg);

    for(i = 0; i < (S32)c->column_num; i++)
    {
        gui_measure_string((UI_string_type)c->horizontal_string.string_list[i], &string_width, &string_height);

        string_x = cell_x + ((cell_width - string_width) >> 1);
        if (r2lMMIFlag)
        {
            string_x += string_width;
        }        
        gui_move_text_cursor(string_x, cell_y + ((cell_height - string_height) >> 1));

        gui_print_text((UI_string_type)c->horizontal_string.string_list[i]);
        
        if (c->horizontal_string.underline_index == i)
        {
            S32 underline_y;
            underline_y = cell_y + cell_height - ((cell_height - string_height) >> 1);
            if (underline_y > c->horizontal_string_y + c->horizontal_string_height - 1)
            {
                underline_y = c->horizontal_string_y + c->horizontal_string_height - 1;
            }
            
            if (r2lMMIFlag)
            {
                gui_draw_horizontal_line(string_x - string_width, string_x, underline_y, c->horizontal_string_fg);
            }
            else
            {
                gui_draw_horizontal_line(string_x, string_x + string_width, underline_y, c->horizontal_string_fg);
            }
        }
        
        cell_x += (cell_width + c->frame_line_pixel);
    }

    c->horizontal_string.is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_select_vertical
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_select_vertical(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y = 0, cell_width, cell_height;    
    S32 string_width, string_height, string_x; 
    U32 i;
    UI_image_ID_type icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->vertical_select_x,
        c->vertical_select_y,
        c->vertical_select_x + c->vertical_select_width - 1,
        c->vertical_select_y + c->vertical_select_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->vertical_select_x,
        c->vertical_select_y,
        c->vertical_select_x + c->vertical_select_width - 1,
        c->vertical_select_y + c->vertical_select_height - 1,
        GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* top arrow */
    if (c->vertical_select.top_pressed == 0)
    {
        icon_id = c->vertical_select.top_up;
    }
    else
    {
        icon_id = c->vertical_select.top_down;
    }
    if(icon_id != 0)
    {
    #if defined (__MMI_MAINLCD_128X160__) /* adjust 1 pixel up to avoid press_down icon from covering top date */
        gdi_image_draw_id(
            c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
            c->vertical_select_y,
            (U16) icon_id);
    #else /* (__MMI_MAINLCD_128X160__) */
        gdi_image_draw_id(
            c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
            c->vertical_select_y + 1,
            (U16) icon_id);
    #endif /* (__MMI_MAINLCD_128X160__) */
    }

    /* bottom arrow */
    if (c->vertical_select.bottom_pressed == 0)
    {
        icon_id = c->vertical_select.bottom_up;
    }
    else
    {
        icon_id = c->vertical_select.bottom_down;
    }
    if(icon_id != 0)
    {
    #if defined (__MMI_MAINLCD_128X160__) /* adjust 1 pixel down to avoid press_down icon from covering bottom date */ 
        gdi_image_draw_id(
            c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
            c->vertical_select_y + c->vertical_select_height - c->vertical_select.bottom_height,
            (U16) icon_id);
    #else /* (__MMI_MAINLCD_128X160__) */
        gdi_image_draw_id(
            c->vertical_select_x + ((c->vertical_select_width - c->vertical_select.top_width) >> 1),
            c->vertical_select_y + c->vertical_select_height - c->vertical_select.bottom_height - 1,
            (U16) icon_id);
    #endif /* (__MMI_MAINLCD_128X160__) */
    }

    /* text */
    cell_x = c->vertical_select_x;
    cell_width = c->vertical_select_width;
    cell_height = (c->cell_array_height - (c->row_num - 1) * c->frame_line_pixel) / c->row_num;
    if(c->vertical_select.align_type == GUI_CALENDAR_SELECT_ALIGN_CELL)
    {
        cell_y = c->cell_array_y;        
    }
    else if(c->vertical_select.align_type == GUI_CALENDAR_SELECT_ALIGN_LINE)
    {
        cell_y = c->cell_array_y - (cell_height >> 1);
    }
    else
    {
        MMI_ASSERT(0);
    }
    gui_set_font(c->cell_font);
    gui_set_text_color(c->vertical_select_fg);

    for(i = 0; i < c->row_num; i++)
    {
        gui_measure_string((UI_string_type)c->vertical_select.string_list[i], &string_width, &string_height);

        string_x = cell_x + ((cell_width - string_width) >> 1);
        if (r2lMMIFlag)
        {
            string_x += string_width;
        }        
    #if defined(__MMI_MAINLCD_128X128__)
        gui_move_text_cursor(string_x, cell_y + cell_height - string_height + 1);
    #elif defined(__MMI_MAINLCD_128X160__)/* adjust all date 1 pixel up to avoid bottom press_down icon from covering bottom date */
	gui_move_text_cursor(
            string_x,
            cell_y + ((cell_height - string_height) >> 1) - 1);
    #else /* defined(__MMI_MAINLCD_128X128__) */ 
        gui_move_text_cursor(
            string_x,
            cell_y + ((cell_height - string_height) >> 1));
    #endif /* defined(__MMI_MAINLCD_128X128__) */ 

        gui_print_text((UI_string_type)c->vertical_select.string_list[i]);
        cell_y += (cell_height+c->frame_line_pixel);
    }

    c->vertical_select.is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_normal_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_normal_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height, string_x; 
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(c->title_x, c->title_y, c->title_x + c->title_width - 1, c->title_y + c->title_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->title_x,
        c->title_y,
        c->title_x + c->title_width - 1,
        c->title_y + c->title_height - 1,
        GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_image_draw_id(c->content_x, c->content_y, c->bg_id);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gui_set_font(&MMI_medium_font);
    gui_set_text_color(c->title_fg);
    
    gui_measure_string((UI_string_type)c->title.string1, &string_width, &string_height);

    string_x = c->title_x + ((c->title_width - string_width) >> 1);    
    if (r2lMMIFlag)
    {
        string_x += string_width;
    }    
    gui_move_text_cursor(string_x, c->title_y + ((c->title_height - string_height) >> 1));

    gui_print_text((UI_string_type)c->title.string1);

    c->title.is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_menstrual_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_menstrual_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;
    MMI_DBG_ASSERT(c != NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_cell_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_redraw_cell_array(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 current_cell_x, current_cell_y;
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->cell_array_x - c->frame_line_pixel,
        c->cell_array_y - c->frame_line_pixel,
        c->cell_array_x + c->cell_array_width + (2 * c->frame_line_pixel) - 1,
        c->cell_array_y + c->cell_array_height + (2 * c->frame_line_pixel) - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        c->cell_array_x - c->frame_line_pixel,
        c->cell_array_y - c->frame_line_pixel,
        c->cell_array_x + c->cell_array_width + (2 * c->frame_line_pixel) - 1,
        c->cell_array_y + c->cell_array_height + (2 * c->frame_line_pixel) - 1,
        GDI_COLOR_TRANSPARENT);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    cell_x = c->cell_array_x;
    cell_y = c->cell_array_y;
    cell_width = c->cell_width;
    cell_height = c->cell_height;

    /* current cell bg */
    if ((c->current_row < c->row_num) && (c->current_column < c->column_num))
    {
        current_cell_x = cell_x + (cell_width + c->frame_line_pixel) * c->current_column;
        current_cell_y = cell_y + (cell_height + c->frame_line_pixel) * c->current_row;
        gdi_draw_solid_rect(
            current_cell_x,
            current_cell_y,
            current_cell_x + cell_width - 1,
            current_cell_y + cell_height - 1,
            gdi_act_color_from_rgb(c->cell_bg[GUI_CALENDAR_COLOR_CURRENT].alpha, c->cell_bg[GUI_CALENDAR_COLOR_CURRENT].r, c->cell_bg[GUI_CALENDAR_COLOR_CURRENT].g, c->cell_bg[GUI_CALENDAR_COLOR_CURRENT].b));
    }

    /* each cell */
    for(i = 0; i < c->row_num; i ++)
    {
        cell_x = c->cell_array_x;
        for(j = 0; j < c->column_num; j++)
        {
            gui_calendar_redraw_cell(
                c,
                cell_x,
                cell_y,
                cell_width,
                cell_height,
                c->cell_array.cell + i * c->column_num + j);
            cell_x += (cell_width + c->frame_line_pixel);
        }
        cell_y += (cell_height + c->frame_line_pixel);
    }    

    c->cell_array.is_updated = FALSE;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  cell_x          [IN]        
 *  cell_y          [IN]        
 *  cell_width      [IN]        
 *  cell_height     [IN]        
 *  cell            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_cell(
                gui_calendar_struct *c,
                S32 cell_x,
                S32 cell_y,
                S32 cell_width,
                S32 cell_height,
                gui_calendar_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fill_bg_x = 0, fill_bg_y = 0, fill_bg_width = 0, fill_bg_height = 0;    /* 120406 warning remove */
    S32 text_x = 0, text_y = 0, text_width, text_height;
    S32 icon_x = 0, icon_y = 0, icon_width, icon_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    /* fill bg */
    if (c->cell_array.bg_fill_type == GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL)
    {
        fill_bg_x = cell_x;
        fill_bg_y = cell_y + cell_height - (cell_height >> 1);
        fill_bg_width = cell_width;
        fill_bg_height = cell_height >> 1;
    }
    else if(c->cell_array.bg_fill_type == GUI_CALENDAR_CELL_BG_FILL_VERTICAL)
    {
        fill_bg_x = cell_x + (cell_width >> 2);
        fill_bg_y = cell_y;
        fill_bg_width = cell_width >> 1;
        fill_bg_height = cell_height;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (cell->bg_index != GUI_CALENDAR_COLOR_NONE)
    {
        gdi_draw_solid_rect(
            fill_bg_x,
            fill_bg_y,
            fill_bg_x + fill_bg_width - 1,
            fill_bg_y + fill_bg_height - 1,
            gdi_act_color_from_rgb(c->cell_bg[cell->bg_index].alpha, c->cell_bg[cell->bg_index].r, c->cell_bg[cell->bg_index].g, c->cell_bg[cell->bg_index].b));
    }

    /* draw icon */
    if ((c->cell_array.icon_display_type != GUI_CALENDAR_CELL_ICON_DISPLAY_DISABLE) && (cell->icon_id != 0))
    {
        gdi_image_get_dimension_id((U16)cell->icon_id, &icon_width, &icon_height);
        if (c->cell_array.icon_display_type == GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP)
        {
            icon_x = cell_x + cell_width - icon_width - 1;
            icon_y = cell_y + 1;
        }
        else if (c->cell_array.icon_display_type == GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER)
        {
            icon_x = cell_x + ((cell_width-icon_width) >> 1);
            icon_y = cell_y + ((cell_height-icon_height) >> 1);
        }
        else
        {
            MMI_ASSERT(0);
        }
        gdi_image_draw_id(icon_x, icon_y, (U16) cell->icon_id);
    }

    /* draw text */
    if (c->cell_array.text_display_type != GUI_CALENDAR_CELL_TEXT_DISPLAY_DISABLE)
    {
        gui_measure_string(cell->text, &text_width, &text_height);
        if (c->cell_array.text_display_type == GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM)
        {
            text_x = cell_x;
            text_y = cell_y + cell_height - text_height + 1;
        }
        else if(c->cell_array.text_display_type == GUI_CALENDAR_CELL_TEXT_DISPLAY_CENTER)
        {
            text_x = cell_x + ((cell_width-text_width) >> 1);
            text_y = cell_y + ((cell_height-text_height) >> 1);
        }
        else
        {
            MMI_ASSERT(0);
        }
        gui_set_font(c->cell_font);
        if (cell->valid)
        {
            gui_set_text_color(c->cell_valid_fg);
        }
        else
        {
            gui_set_text_color(c->cell_invalid_fg);
        }

        if (r2lMMIFlag)
        {
            text_x += text_width;
        }   

        gui_move_text_cursor(text_x, text_y);
        gui_print_text((UI_string_type)cell->text);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* These can be obtained from theme data  */
    const UI_filled_area popup_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
        UI_NULL_IMAGE,
        NULL,
        {47, 55, 143, 80},
        {0, 0, 0, 0},
        {0, 0, 0, 100},
        {0, 0, 0, 0},
        0
    };
    color tc = *(current_MMI_theme->UI_white_color);
    UI_font_type text_font = &MMI_medium_font;
    S32 px1, py1, px2, py2;
    S32 width, height, y;
    S32 w1, w2, w3, h1, h2, h3;
    S32 x1 ,y1 , x2;
    UI_string_type msg1 ,msg2, msg3;

    gui_calendar_struct* c;

    c = current_calendar_pointer;

    MMI_DBG_ASSERT(c != NULL);
    
    x1 = c->cell_array_x + (c->cell_width + c->frame_line_pixel) * c->highlighted_column;
    y1 = c->cell_array_y + (c->cell_height + c->frame_line_pixel) * c->highlighted_row;
    x2 = x1 + c->cell_width - 1;

    /* set message 1 of popup */
    msg1 = (UI_string_type) c->popup.message1;

    /* set message 2 of popup */
    msg2 = (UI_string_type) c->popup.message2;

    /* set message 3 of popup */
    msg3 = (UI_string_type) c->popup.message3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set font of popup */
    gui_set_font(text_font);
    if ((msg1 == NULL) && (msg2 == NULL) && (msg3 == NULL))
    {
        c->popup.is_drawed = FALSE;
        return;
    }
    if (msg1 == NULL)
    {
        h1 = 0;
        w1 = 0;
    }
    else
    {
        gui_measure_string(msg1, &w1, &h1); /* measue width and height of msg1 */
    }
    if (msg2 == NULL)
    {
        h2 = 0;
        w2 = 0;
    }
    else
    {
        gui_measure_string(msg2, &w2, &h2); /* measue width and height of msg1 */
    }
    if (msg3 == NULL)
    {
        h3 = 0;
        w3 = 0;
    }
    else
    {
        gui_measure_string(msg3, &w3, &h3); /* measue width and height of msg1 */
    }
    height = h1 + h2 + h3 + 8;
    width = w1;
    if (w2 > width)
    {
        width = w2;
    }
    if (w3 > width)
    {
        width = w3;
    }
    width += 8;
    if (width > (GUI_CALENDAR_FRAME_WIDTH * 3 / 4))
    {
        width = (GUI_CALENDAR_FRAME_WIDTH * 3 / 4);
    }
    if (height > (GUI_CALENDAR_FRAME_WIDTH * 3 / 4))
    {
        height = (GUI_CALENDAR_FRAME_WIDTH * 3 / 4);
    }
    px1 = x2 + c->frame_line_pixel;
    px1 = px1 + c->frame_line_pixel; /* adjust position to avoid cover highlighted cell frame */

    py1 = y1;
    if ((px1 + width - 1) > c->cell_array_x + c->cell_array_width - 1)
    {
        px1 = x1 - width - c->frame_line_pixel;
        if (px1 < c->cell_array_x)
        {
            px1 = c->cell_array_x;
        }
    }
    if ((py1 + height - 1) > c->cell_array_y + c->cell_array_height - 1)
    {
        py1 = c->cell_array_y + c->cell_array_height - height;
        if (py1 < c->cell_array_y)
        {
            py1 = c->cell_array_y;
        }
    }
    px2 = px1 + width - 1;
    py2 = py1 + height - 1;
    gdi_layer_push_clip();
    gdi_layer_set_clip(px1, py1, px2, py2);
    gdi_image_cache_bmp_get(px1, py1, px2, py2, &c->popup_cache);
    c->popup.is_drawed = TRUE;
    c->popup_x = px1;
    c->popup_y = py1;
    /* fill the color of popup */
    gui_draw_filled_area(px1, py1, px2, py2, (UI_filled_area*)&popup_filler);
    /* set text color */
    gui_set_text_color(tc);
    y = py1 + 4;
    if (msg1 != NULL)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(px1 + 4 + w1, y);
        }
        else
        {
            gui_move_text_cursor(px1 + 4, y);
        }
        gui_print_text(msg1);
        y += h1;
    }
    if (msg2 != NULL)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(px1 + 4 + w2, y);
        }
        else
        {
            gui_move_text_cursor(px1 + 4, y);
        }
        gui_print_text(msg2);
        y += h2;
    }
    if (msg3 != NULL)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(px1 + 4 + w3, y);
        }
        else
        {
            gui_move_text_cursor(px1 + 4, y);
        }
        gui_print_text(msg3);
        y += h3;
    }
    gdi_layer_pop_clip();
    gdi_layer_blt_previous(px1, py1, px2, py2);  
}

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_infobox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_infobox(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_x, entry_y, entry_width, entry_height;
    S32 icon_x, icon_width, icon_height;
    S32 string_x, string_width, string_height, string_xwidth;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    entry_width = GUI_CALENDAR_INFOBOX_WIDTH - GUI_CALENDAR_INFOBOX_GAP*2;
    entry_height = GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
    entry_x = c->infobox_x + GUI_CALENDAR_INFOBOX_GAP;
    entry_y = c->infobox_y + GUI_CALENDAR_INFOBOX_GAP;
    icon_x = entry_x;
    if(c->infobox.icon_list)
    {
        string_x = entry_x + GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
    }
    else
    {
        string_x = entry_x;
    }
    string_xwidth = entry_x + entry_width - string_x;

    if (r2lMMIFlag)
    {
        icon_x += (entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT);
        if(c->infobox.icon_list)
        {
            string_x += (entry_width - 2 * GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT);
        }
        else
        {
            string_x += (entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT);
        }
    }    
    
    gui_set_font(c->infobox_font);
    gui_set_text_color(c->infobox_fg);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->infobox_x,
        c->infobox_y,
        c->infobox_x + c->infobox_width - 1,
        c->infobox_y + c->infobox_height - 1);
    gdi_draw_solid_rect(
        c->infobox_x,
        c->infobox_y,
        c->infobox_x + c->infobox_width - 1,
        c->infobox_y + c->infobox_height - 1,
        gdi_act_color_from_rgb(c->infobox_bg.alpha, c->infobox_bg.r, c->infobox_bg.g, c->infobox_bg.b));

    for (i = 0; i < c->infobox.num_of_entry; i++)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(entry_x, entry_y, entry_x + entry_width - 1, entry_y + entry_height - 1);
        gdi_draw_solid_rect(
            entry_x,
            entry_y,
            entry_x + entry_width - 1,
            entry_y + entry_height - 1,
            gdi_act_color_from_rgb(c->infobox_entry_bg.alpha, c->infobox_entry_bg.r, c->infobox_entry_bg.g, c->infobox_entry_bg.b));

        if(c->infobox.icon_list)
        {
            if(c->infobox.icon_list[i] != 0)
            {
                gdi_image_get_dimension_id((U16)c->infobox.icon_list[i], &icon_width, &icon_height);
                gdi_image_draw_id(
                    icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                    entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                    (U16) c->infobox.icon_list[i]);
            }
        }
        
        if(c->infobox.string_list)
        {
            if(c->infobox.string_list[i] != NULL)
            {
                gui_measure_string((UI_string_type)c->infobox.string_list[i], &string_width, &string_height);
                gui_print_truncated_text(
                    string_x,
                    entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - string_height) >> 1),
                    string_xwidth, 
                    (UI_string_type)c->infobox.string_list[i]);
            }
        }
        
        entry_y += entry_height + GUI_CALENDAR_INFOBOX_GAP;
        gdi_layer_pop_clip();
    }
    gdi_layer_pop_clip();
}
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_highlight_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]         
 *  highlighted_row         [IN]        
 *  highlighted_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_highlight_cell(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 highlighted_cell_x, highlighted_cell_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    cell_x = c->cell_array_x;
    cell_y = c->cell_array_y;
    cell_width = c->cell_width;
    cell_height = c->cell_height;
    highlighted_cell_x = cell_x + (cell_width + c->frame_line_pixel) * c->highlighted_column;
    highlighted_cell_y = cell_y + (cell_height + c->frame_line_pixel) * c->highlighted_row;

    /* adjust highlight field to include cell's frame line */
    highlighted_cell_x = highlighted_cell_x - c->frame_line_pixel;
    highlighted_cell_y = highlighted_cell_y - c->frame_line_pixel;
    cell_width = cell_width + 2 * c->frame_line_pixel;
    cell_height = cell_height + 2 * c->frame_line_pixel;    
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        highlighted_cell_x,
        highlighted_cell_y,
        highlighted_cell_x + cell_width - 1,
        highlighted_cell_y + cell_height - 1);
    if ((c->highlighted_row_old != c->highlighted_row) || (c->highlighted_column_old != c->highlighted_column))
    {
        gdi_image_cache_bmp_get(
            highlighted_cell_x,
            highlighted_cell_y,
            highlighted_cell_x + cell_width - 1,
            highlighted_cell_y + cell_height - 1,
            &c->cell_cache);
    }
    gdi_draw_rect(
        highlighted_cell_x,
        highlighted_cell_y,
        highlighted_cell_x + cell_width - 1,
        highlighted_cell_y + cell_height - 1,
        gdi_act_color_from_rgb(c->cell_highlight.alpha, c->cell_highlight.r, c->cell_highlight.g, c->cell_highlight.b));
    gdi_layer_pop_clip();
    if (c->AppCellHighlightHanlder)
    {
        c->AppCellHighlightHanlder(highlighted_row, highlighted_column);
    }
    c->highlighted_row_old = c->highlighted_row;
    c->highlighted_column_old = c->highlighted_column;

    /* draw left horizontal select */
    if(c->horizontal_select[0].is_updated)
    {
        gui_calendar_redraw_select_horizontal1(c);
    }

    /* draw right horizontal select */
    if(c->horizontal_select[1].is_updated)
    {
        gui_calendar_redraw_select_horizontal2(c);
    }

    if(c->title.is_updated)
    {
        c->title.show_title();
    }
    
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    if (c->infobox.is_updated)
    {
        gui_calendar_redraw_infobox(c);
    }
#endif

    if (c->popup.need_popup)
    {
        gui_cancel_timer(gui_calendar_redraw_popup);
        gui_start_timer(GUI_CALENDAR_POPUP_WAIT_TIME, gui_calendar_redraw_popup);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_unhighlight_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]         
 *  highlighted_row         [IN]        
 *  highlighted_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_unhighlight_cell(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 highlighted_cell_x, highlighted_cell_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    cell_x = c->cell_array_x;
    cell_y = c->cell_array_y;
    cell_width = c->cell_width;
    cell_height = c->cell_height;
    highlighted_cell_x = cell_x + (cell_width + c->frame_line_pixel) * highlighted_column;
    highlighted_cell_y = cell_y + (cell_height + c->frame_line_pixel) * highlighted_row;
    
    /* adjust unhighlight field to include cell's frame line */
    highlighted_cell_x = highlighted_cell_x - c->frame_line_pixel;
    highlighted_cell_y = highlighted_cell_y - c->frame_line_pixel;
    cell_width = cell_width + 2 * c->frame_line_pixel;
    cell_height = cell_height + 2 * c->frame_line_pixel;

    if (c->popup.need_popup && c->popup.is_drawed)
    {
        gdi_image_cache_bmp_draw(c->popup_x, c->popup_y, &c->popup_cache);
        c->popup.is_drawed = FALSE;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        highlighted_cell_x,
        highlighted_cell_y,
        highlighted_cell_x + cell_width - 1,
        highlighted_cell_y + cell_height - 1);
    gdi_image_cache_bmp_draw(highlighted_cell_x, highlighted_cell_y, &c->cell_cache);
    gdi_layer_pop_clip();
    
    if (c->popup.need_popup)
    {
        gui_cancel_timer(gui_calendar_redraw_popup); /* stop the timer */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_show(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    /* draw calendar background image */
    gui_calendar_redraw_bg(c);

    /* draw left horizontal select */
    if(c->horizontal_select[0].is_updated)
    {
        gui_calendar_redraw_select_horizontal1(c);
    }

    /* draw right horizontal select */
    if(c->horizontal_select[1].is_updated)
    {
        gui_calendar_redraw_select_horizontal2(c);
    }

    /* draw title */
    if(c->title.is_updated)
    {
        c->title.show_title();
    }

    /* draw horizontal string */
    if(c->horizontal_string.is_updated)
    {
        gui_calendar_redraw_horizontal_string(c);
    }

    /* draw vertical select */
    if(c->vertical_select_display)
    {
        if(c->vertical_select.is_updated)
        {
            gui_calendar_redraw_select_vertical(c);
        }
    }

    /* draw calendar cells */
    if(c->cell_array.is_updated)
    {
        gui_calendar_redraw_cell_array(c);
        c->highlighted_row_old = 0xffffffff;
        c->highlighted_column_old = 0xffffffff;
        c->popup.is_drawed = MMI_FALSE;
    }

    /* unhighlighted and highlighted cell */
    if ((c->highlighted_row_old<c->row_num) && (c->highlighted_column<c->column_num))
    {
        if ((c->highlighted_row_old!=c->highlighted_row) || (c->highlighted_column_old<c->highlighted_column))
        {
            gui_calendar_unhighlight_cell(c, c->highlighted_row_old, c->highlighted_column_old);
        }
    }
    if ((c->highlighted_row<c->row_num) && (c->highlighted_column<c->column_num))
    {
        gui_calendar_highlight_cell(c, c->highlighted_row, c->highlighted_column);
    }

    /* Infobox */
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_update_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_update_base_layer(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
#ifdef __GDI_MEMORY_PROFILE_2__
    c->bg_updated = TRUE;
    gui_calendar_redraw_bg(c);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif
}
