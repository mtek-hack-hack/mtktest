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
 *  gui_calendar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Calendar - UI component
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
#ifndef __GUI_CALENDAR_H__
#define __GUI_CALENDAR_H__

#include "MMI_features.h"
#include "gui.h"
#include "Wgui.h"

#if defined (__MMI_MAINLCD_320X240__)
    #define GUI_CALENDAR_MAX_CELL_TEXT                 3
    #define GUI_CALENDAR_FRAME_LINE_PIXEL              1
    #define GUI_CALENDAR_FRAME_START_X                 3
    #define GUI_CALENDAR_FRAME_START_Y                 49
    #define GUI_CALENDAR_FRAME_WIDTH                   317
    #define GUI_CALENDAR_FRAME_HEIGHT                  160
    #define GUI_CALENDAR_TITLE_HEIGHT                  22
    #define GUI_CALENDAR_BOTTOM_HEIGHT                 0
    #define GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT      21
    #define GUI_CALENDAR_VERTICAL_SELECT_WIDTH         40
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER  21
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER   25
    #define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
    #define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5)
#elif defined (__MMI_MAINLCD_240X320__)
    #define GUI_CALENDAR_MAX_CELL_TEXT                 3
    #define GUI_CALENDAR_FRAME_LINE_PIXEL              1
    #define GUI_CALENDAR_FRAME_START_X                 9
    #define GUI_CALENDAR_FRAME_START_Y                 44
    #define GUI_CALENDAR_FRAME_WIDTH                   221
    #define GUI_CALENDAR_FRAME_HEIGHT                  199
    #define GUI_CALENDAR_TITLE_HEIGHT                  22
    #define GUI_CALENDAR_BOTTOM_HEIGHT                 0
    #define GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT      30
    #define GUI_CALENDAR_VERTICAL_SELECT_WIDTH         30
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER  1
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER   5
    #define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
    #define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5)
    #ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
        #define GUI_CALENDAR_MAX_INFOBOX                   2
        #define GUI_CALENDAR_INFOBOX_GAP                   1
        #define GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT          24
        #define GUI_CALENDAR_INFOBOX_START_X               GUI_CALENDAR_FRAME_START_X
        #define GUI_CALENDAR_INFOBOX_START_Y               245
        #define GUI_CALENDAR_INFOBOX_WIDTH                 GUI_CALENDAR_FRAME_WIDTH
        #define GUI_CALENDAR_INFOBOX_HEIGHT                ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT*GUI_CALENDAR_MAX_INFOBOX)+(GUI_CALENDAR_INFOBOX_GAP*(GUI_CALENDAR_MAX_INFOBOX+1)))
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 
#elif defined (__MMI_MAINLCD_176X220__)
    #define GUI_CALENDAR_MAX_CELL_TEXT                 3
    #define GUI_CALENDAR_FRAME_LINE_PIXEL              1
    #define GUI_CALENDAR_FRAME_START_X                 5
    #define GUI_CALENDAR_FRAME_START_Y                 39
    #define GUI_CALENDAR_FRAME_WIDTH                   162
    #define GUI_CALENDAR_FRAME_HEIGHT                  145
    #define GUI_CALENDAR_TITLE_HEIGHT                  18
    #define GUI_CALENDAR_BOTTOM_HEIGHT                 13
    #define GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT      18
    #define GUI_CALENDAR_VERTICAL_SELECT_WIDTH         34
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER  1
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER   5        
    #define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
    #define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5)
#elif defined (__MMI_MAINLCD_128X160__)
    #define GUI_CALENDAR_MAX_CELL_TEXT                 3
    #define GUI_CALENDAR_FRAME_LINE_PIXEL              1
    #define GUI_CALENDAR_FRAME_START_X                 0
    #define GUI_CALENDAR_FRAME_START_Y                 20
    #define GUI_CALENDAR_FRAME_WIDTH                   128
    #define GUI_CALENDAR_FRAME_HEIGHT                  120
    #define GUI_CALENDAR_TITLE_HEIGHT                  20
    #define GUI_CALENDAR_BOTTOM_HEIGHT                 3        
    #define GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT      16
    #define GUI_CALENDAR_VERTICAL_SELECT_WIDTH         16
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER  1
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER   0
    #define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
    #define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5)
#elif defined (__MMI_MAINLCD_128X128__)
    #define GUI_CALENDAR_MAX_CELL_TEXT                 3
    #define GUI_CALENDAR_FRAME_LINE_PIXEL              1
    #define GUI_CALENDAR_FRAME_START_X                 0
    #define GUI_CALENDAR_FRAME_START_Y                 18
    #define GUI_CALENDAR_FRAME_WIDTH                   128
    #define GUI_CALENDAR_FRAME_HEIGHT                  91
    #define GUI_CALENDAR_TITLE_HEIGHT                  16
    #define GUI_CALENDAR_BOTTOM_HEIGHT                 0        
    #define GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT      10
    #define GUI_CALENDAR_VERTICAL_SELECT_WIDTH         16
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER  1
    #define GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER   5
    #define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
    #define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5) 
#endif

#define GUI_CALENDAR_POPUP_WAIT_TIME       2000

extern UI_calendar_theme *current_calendar_theme;

typedef enum
{
    GUI_CALENDAR_TITLE_NORMAL,
    GUI_CALENDAR_TITLE_MENSTRUAL,
    GUI_CALENDAR_TITLE_TOTAL
} GUI_CALENDAR_TITLE_TYPE;

typedef enum
{
    GUI_CALENDAR_IDLE_NORMAL,
    GUI_CALENDAR_IDLE_SMALL,
    GUI_CALENDAR_NORMAL,
    GUI_CALENDAR_SMALL
} GUI_CALENDAR_INIT_TYPE;

typedef enum
{
    GUI_CALENDAR_SELECT_ALIGN_CENTER,
    GUI_CALENDAR_SELECT_ALIGN_LEFT,
    GUI_CALENDAR_SELECT_ALIGN_LINE,
    GUI_CALENDAR_SELECT_ALIGN_CELL
} GUI_CALENDAR_SELECT_ALIGN_TYPE;

typedef enum
{
    GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL,
    GUI_CALENDAR_CELL_BG_FILL_VERTICAL
} GUI_CALENDAR_CELL_BG_FILL_TYPE;

typedef enum
{
    GUI_CALENDAR_CELL_TEXT_DISPLAY_DISABLE,
    GUI_CALENDAR_CELL_TEXT_DISPLAY_CENTER,
    GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM
} GUI_CALENDAR_CELL_TEXT_DISPLAY_TYPE;

typedef enum
{
    GUI_CALENDAR_CELL_ICON_DISPLAY_DISABLE,
    GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER,
    GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP
} GUI_CALENDAR_CELL_ICON_DISPLAY_TYPE;

typedef MMI_BOOL (*GUICalendarV2EventFuncPtr) (U32 highlighted_row, U32 highlighted_column);
typedef void (*GUICalendarV2FuncPtr) (void);

typedef struct
{
    UI_image_ID_type left_up;
    UI_image_ID_type left_down;
    UI_image_ID_type right_up;
    UI_image_ID_type right_down;
    GUICalendarV2EventFuncPtr left_handler;
    GUICalendarV2EventFuncPtr right_handler;    
    U8 *string;
    U32 align_type;
    S32 left_width;
    S32 left_height;
    S32 right_width;
    S32 right_height;
    U8 left_pressed;
    U8 right_pressed;
    U8 is_updated;
} gui_calendar_horizontal_select_struct;

typedef struct
{
    UI_image_ID_type top_up;
    UI_image_ID_type top_down;
    UI_image_ID_type bottom_up;
    UI_image_ID_type bottom_down;
    GUICalendarV2EventFuncPtr top_handler;
    GUICalendarV2EventFuncPtr bottom_handler; 
    U8 **string_list;
    U32 align_type;
    S32 top_width;
    S32 top_height;
    S32 bottom_width;
    S32 bottom_height;
    U8 top_pressed;
    U8 bottom_pressed;
    U8 is_updated;
} gui_calendar_vertical_select_struct;

typedef struct
{
    U8 color_index1;
    U8 *string1;
    U8 color_index2;
    U8 *string2;
    GUICalendarV2FuncPtr show_title;
    U8 is_updated;
} gui_calendar_title_struct;

typedef struct
{
    U8 **string_list;
    U8 is_updated;
    S32 underline_index; /* the index of item that need underlined */
} gui_calendar_horizontal_string_struct;

typedef struct
{
    U8 bg_index;
    UI_image_ID_type icon_id;
    UI_character_type text[GUI_CALENDAR_MAX_CELL_TEXT];
    MMI_BOOL valid;
} gui_calendar_cell_struct;

typedef struct
{
    gui_calendar_cell_struct *cell;
    U8 bg_fill_type;
    U8 text_display_type;
    U8 icon_display_type;
    U8 is_updated;
#ifdef __MMI_TOUCH_SCREEN__
    U8 pen_on_highlighted;
#endif
} gui_calendar_cell_array_struct;

typedef struct
{
    U8 *message1;
    U8 *message2;
    U8 *message3;
    U8 need_popup;
    U8 is_drawed;
} gui_calendar_popup_struct;

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
typedef struct
{
    UI_image_ID_type *icon_list;
    U8 **string_list;
    U8 num_of_entry;
    U8 is_updated;
} gui_calendar_infobox_struct;
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/

typedef struct
{
    S32 content_x;
    S32 content_y;
    S32 content_width;
    S32 content_height;
    S32 horizontal_select_x;
    S32 horizontal_select_y;
    S32 horizontal_select_width;
    S32 horizontal_select_height;
    S32 title_x;
    S32 title_y;
    S32 title_width;
    S32 title_height;
    S32 vertical_select_x;
    S32 vertical_select_y;
    S32 vertical_select_width;
    S32 vertical_select_height;
    S32 horizontal_string_x;
    S32 horizontal_string_y;
    S32 horizontal_string_width;
    S32 horizontal_string_height;
    S32 cell_array_x;
    S32 cell_array_y;
    S32 cell_array_width;
    S32 cell_array_height;
    S32 cell_width;
    S32 cell_height;
    gdi_image_cache_bmp_struct cell_cache;
    gdi_image_cache_bmp_struct popup_cache;
    S32 frame_line_pixel;
    S32 popup_x;
    S32 popup_y;
    
    gui_calendar_horizontal_select_struct horizontal_select[2];
    gui_calendar_vertical_select_struct vertical_select;
    gui_calendar_title_struct title;
    gui_calendar_horizontal_string_struct horizontal_string;
    gui_calendar_cell_array_struct cell_array;
    gui_calendar_popup_struct popup;
    MMI_BOOL vertical_select_display;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL pen_unable;
#endif
    
    U32 row_num;
    U32 column_num;
    U32 current_row;
    U32 current_column;
    U32 highlighted_row;
    U32 highlighted_column;
    U32 highlighted_row_old;
    U32 highlighted_column_old;
    
    UI_image_ID_type bg_id;
    U8 bg_updated;
    
    U8* cell_cache_buf;
    U8* popup_cache_buf;
    
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    gui_calendar_infobox_struct infobox;
    S32 infobox_x;
    S32 infobox_y;
    S32 infobox_width;
    S32 infobox_height;    
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 
    
#ifdef __GDI_MEMORY_PROFILE_2__
    GDI_HANDLE bg_layer;
    GDI_HANDLE date_layer;
#endif /*__GDI_MEMORY_PROFILE_2__*/
    
    MMI_BOOL (*AppCellHighlightHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppLeftArrowKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppRightArrowKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppUpArrowKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppDownArrowKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppUpSideKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    MMI_BOOL (*AppDownSideKeyHanlder)(U32 highlighted_row, U32 highlighted_column);
    
    color title_fg;
    color horizontal_select_fg;
    color horizontal_select_border;
    color vertical_select_fg;
    color horizontal_string_fg;
    color cell_bg[GUI_CALENDAR_COLOR_TOTAL];
    color cell_valid_fg;
    color cell_invalid_fg;
    color cell_highlight;    
    stFontAttribute *horizontal_string_font;
    stFontAttribute *cell_font;
    
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    color infobox_bg;
    color infobox_entry_bg;
    color infobox_fg;    
    stFontAttribute *infobox_font;
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 
}gui_calendar_struct;

extern void gui_calendar_set_theme(gui_calendar_struct *c, UI_calendar_theme *t);
extern void gui_calendar_set_current_theme(gui_calendar_struct *c);
extern void gui_calendar_create(
                gui_calendar_struct *c,
                U32 calendar_type,
                U32 row_num,
                U32 column_num,
                U8 *cell_buf,
                U8 *popup_buf);
extern void gui_calendar_set_bg(gui_calendar_struct* c, UI_image_ID_type bg_id);
extern void gui_calendar_set_select_horizontal1(
                gui_calendar_struct *c,
                UI_image_ID_type left_up,
                UI_image_ID_type left_down,
                UI_image_ID_type right_up,
                UI_image_ID_type right_down,
                U8 *string,
                U32 align_type);
extern void gui_calendar_set_select_horizontal1_string(gui_calendar_struct* c, U8 *string);
extern void gui_calendar_set_select_horizontal1_handler(
                gui_calendar_struct *c,
                GUICalendarV2EventFuncPtr left_handler,
                GUICalendarV2EventFuncPtr right_handler);
extern void gui_calendar_set_select_horizontal2(
                gui_calendar_struct *c,
                UI_image_ID_type left_up,
                UI_image_ID_type left_down,
                UI_image_ID_type right_up,
                UI_image_ID_type right_down,
                U8 *string,
                U32 align_type);
extern void gui_calendar_set_select_horizontal2_string(gui_calendar_struct* c, U8 *string);
extern void gui_calendar_set_select_horizontal2_handler(
                gui_calendar_struct *c,
                GUICalendarV2EventFuncPtr left_handler,
                GUICalendarV2EventFuncPtr right_handler);
extern void gui_calendar_set_select_vertical(
                gui_calendar_struct *c,
                UI_image_ID_type top_up,
                UI_image_ID_type top_down,
                UI_image_ID_type bottom_up,
                UI_image_ID_type bottom_down,
                U8 **string_list,
                U32 align_type);
extern void gui_calendar_set_select_vertical_string(gui_calendar_struct* c, U8 **string_list);
extern void gui_calendar_set_select_vertical_handler(
                gui_calendar_struct *c,
                GUICalendarV2EventFuncPtr top_handler,
                GUICalendarV2EventFuncPtr bottom_handler);
extern void gui_calendar_set_normal_title(gui_calendar_struct* c, U8 *string);
extern void gui_calendar_set_menstrual_title(
                gui_calendar_struct *c,
                U8 color_index1,
                U8 *string1,
                U8 color_index2,
                U8 *string2);
extern void gui_calendar_set_horizontal_string(gui_calendar_struct* c, U8 **string_list, S32 underline_index);
extern void gui_calendar_set_cell_array(
                gui_calendar_struct *c,
                gui_calendar_cell_struct *cell,
                U8 cell_bg_fill_type,
                U8 cell_text_display_type,
                U8 cell_icon_display_type);
extern void gui_calendar_set_current(gui_calendar_struct* c, U32 current_row, U32 current_column);
extern void gui_calendar_set_highlight(gui_calendar_struct* c, U32 highlighted_row, U32 highlighted_column);
extern void gui_calendar_set_popup(gui_calendar_struct* c, U8 *message1, U8 *message2, U8 *message3);

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
extern void gui_calendar_set_infobox(
                gui_calendar_struct *c,
                UI_image_ID_type *icon_list,
                U8 **string_list,
                U8 entry_num);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
extern void gui_calendar_register_cell_highlight_handler(gui_calendar_struct *c,
                                                         MMI_BOOL(*app_cell_highlight_handler) (U32 highlighted_row,
                                                                                                U32
                                                                                                highlighted_column));
extern void gui_calendar_register_left_arrow_key_handler(gui_calendar_struct *c,
                                                         MMI_BOOL(*app_left_arrow_key_handler) (U32 highlighted_row,
                                                                                                U32
                                                                                                highlighted_column));
extern void gui_calendar_register_right_arrow_key_handler(gui_calendar_struct *c,
                                                          MMI_BOOL(*app_right_arrow_key_handler) (U32 highlighted_row,
                                                                                                  U32
                                                                                                  highlighted_column));
extern void gui_calendar_register_up_arrow_key_handler(gui_calendar_struct *c,
                                                       MMI_BOOL(*app_up_arrow_key_handler) (U32 highlighted_row,
                                                                                            U32 highlighted_column));
extern void gui_calendar_register_down_arrow_key_handler(gui_calendar_struct *c,
                                                         MMI_BOOL(*app_down_arrow_key_handler) (U32 highlighted_row,
                                                                                                U32
                                                                                                highlighted_column));
extern void gui_calendar_register_up_side_key_handler(gui_calendar_struct *c,
                                                      MMI_BOOL(*app_up_side_key_handler) (U32 highlighted_row,
                                                                                          U32 highlighted_column));
extern void gui_calendar_register_down_side_key_handler(gui_calendar_struct *c,
                                                        MMI_BOOL(*app_down_side_key_handler) (U32 highlighted_row,
                                                                                              U32 highlighted_column));
#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_calendar_translate_pen_event(
           gui_calendar_struct* c,
           mmi_pen_event_type_enum pen_event,
           S16 x,
           S16 y);
extern void gui_calendar_set_pen_unable(gui_calendar_struct* c);
#endif /*__MMI_TOUCH_SCREEN__*/
extern void gui_calendar_close(gui_calendar_struct* c);
extern void gui_calendar_redraw_cell_array(gui_calendar_struct* c);
extern void gui_calendar_show(gui_calendar_struct* c);
extern void gui_calendar_update_base_layer(gui_calendar_struct *c);
#endif /*__GUI_CALENDAR_H__*/

