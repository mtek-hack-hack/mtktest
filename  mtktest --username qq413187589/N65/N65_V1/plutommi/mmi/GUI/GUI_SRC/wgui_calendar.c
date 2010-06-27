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
 *  wgui_calendar.c
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

 
#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_categories.h"
#include "wgui_calendar.h"
#include "MMI_features.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_defs.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

gui_calendar_struct g_wgui_calendar;


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calendar_type       [IN]        
 *  row_num             [IN]        
 *  column_num          [IN]        
 *  cell_buf            [?]         
 *  popup_buf           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_create(U32 calendar_type, U32 row_num, U32 column_num, U8* cell_buf, U8* popup_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_create(&g_wgui_calendar, calendar_type, row_num, column_num, cell_buf, popup_buf);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bg_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_bg(UI_image_ID_type bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_bg(&g_wgui_calendar, bg_id);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_up         [IN]        
 *  left_down       [IN]        
 *  right_up        [IN]        
 *  right_down      [IN]        
 *  string          [?]         
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal1(
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
    gui_calendar_set_select_horizontal1(&g_wgui_calendar, left_up, left_down, right_up, right_down, string, align_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal1_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal1_string(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_horizontal1_string(&g_wgui_calendar, string);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal1_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_handler        [IN]        
 *  right_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal1_handler(
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_horizontal1_handler(&g_wgui_calendar, left_handler, right_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_up         [IN]        
 *  left_down       [IN]        
 *  right_up        [IN]        
 *  right_down      [IN]        
 *  string          [?]         
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal2(
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
    gui_calendar_set_select_horizontal2(&g_wgui_calendar, left_up, left_down, right_up, right_down, string, align_type);
}
 

/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal2_string(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_horizontal2_string(&g_wgui_calendar, string);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_horizontal2_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_handler        [IN]        
 *  right_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_horizontal2_handler(
        GUICalendarV2EventFuncPtr left_handler,
        GUICalendarV2EventFuncPtr right_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_horizontal2_handler(&g_wgui_calendar, left_handler, right_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_vertical
 * DESCRIPTION
 *  
 * PARAMETERS
 *  top_up          [IN]        
 *  top_down        [IN]        
 *  bottom_up       [IN]        
 *  bottom_down     [IN]        
 *  string_list     [IN]        
 *  align_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_vertical(
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
    gui_calendar_set_select_vertical(
        &g_wgui_calendar,
        top_up,
        top_down,
        bottom_up,
        bottom_down,
        string_list,
        align_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_vertical_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_list     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_vertical_string(U8 **string_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_vertical_string(&g_wgui_calendar, string_list);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_select_vertical_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  top_handler         [IN]        
 *  bottom_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_select_vertical_handler(
        GUICalendarV2EventFuncPtr top_handler,
        GUICalendarV2EventFuncPtr bottom_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_select_vertical_handler(&g_wgui_calendar, top_handler, bottom_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_normal_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_normal_title(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_normal_title(&g_wgui_calendar, string);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_menstrual_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_index1        [IN]        
 *  string1             [?]         
 *  color_index2        [IN]        
 *  string2             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_menstrual_title(U8 color_index1, U8 *string1, U8 color_index2, U8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_menstrual_title(&g_wgui_calendar, color_index1, string1, color_index2, string2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_horizontal_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_list     [IN]        
 *  underline_index [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_horizontal_string(U8 **string_list, S32 underline_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_horizontal_string(&g_wgui_calendar, string_list, underline_index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_cell_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell                        [?]         
 *  cell_bg_fill_type           [IN]        
 *  cell_text_display_type      [IN]        
 *  cell_icon_display_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_cell_array(
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
    gui_calendar_set_cell_array(
        &g_wgui_calendar,
        cell,
        cell_bg_fill_type,
        cell_text_display_type,
        cell_icon_display_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_current
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_row         [IN]        
 *  current_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_current(U32 current_row, U32 current_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_current(&g_wgui_calendar, current_row, current_column);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  highlighted_row         [IN]        
 *  highlighted_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_highlight(U32 highlighted_row, U32 highlighted_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_highlight(&g_wgui_calendar, highlighted_row, highlighted_column);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message1        [?]     
 *  message2        [?]     
 *  message3        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_popup(U8 *message1, U8 *message2, U8 *message3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_popup(&g_wgui_calendar, message1, message2, message3);
}

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_infobox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_list       [?]         
 *  string_list     [IN]        
 *  entry_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_infobox(UI_image_ID_type *icon_list, U8 **string_list, U8 entry_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_infobox(&g_wgui_calendar, icon_list, string_list, entry_num);
}
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_cell_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_cell_highlight_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_cell_highlight_handler(MMI_BOOL (*app_cell_highlight_handler)(U32 highlighted_row, U32 highlighted_column))
{    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_cell_highlight_handler(&g_wgui_calendar, app_cell_highlight_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_left_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_left_arrow_key_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_left_arrow_key_handler(MMI_BOOL (*app_left_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_left_arrow_key_handler(&g_wgui_calendar, app_left_arrow_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_right_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_right_arrow_key_handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_calendar_register_right_arrow_key_handler(MMI_BOOL (*app_right_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_right_arrow_key_handler(&g_wgui_calendar, app_right_arrow_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_up_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_up_arrow_key_handler        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_calendar_register_up_arrow_key_handler(MMI_BOOL (*app_up_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_up_arrow_key_handler(&g_wgui_calendar, app_up_arrow_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_down_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_down_arrow_key_handler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_calendar_register_down_arrow_key_handler(MMI_BOOL (*app_down_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_calendar_register_down_arrow_key_handler(&g_wgui_calendar, app_down_arrow_key_handler);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_up_side_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_up_side_key_handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_calendar_register_up_side_key_handler(MMI_BOOL (*app_up_side_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_up_side_key_handler(&g_wgui_calendar, app_up_side_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_down_side_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_down_side_key_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_calendar_register_down_side_key_handler(MMI_BOOL (*app_down_side_key_handler)(U32 highlighted_row, U32 highlighted_column))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_down_side_key_handler(&g_wgui_calendar, app_down_side_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_close(&g_wgui_calendar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_show(&g_wgui_calendar);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_calendar_translate_pen_event(mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_calendar_translate_pen_event(&g_wgui_calendar, pen_event, x, y);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_pen_unable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_pen_unable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_pen_unable(&g_wgui_calendar);
}
#endif /*__MMI_TOUCH_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_update_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_update_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_update_base_layer(&g_wgui_calendar);
}