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
 *  wgui_calendar.h
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


#ifndef __WGUI_CALENDAR_H__
#define __WGUI_CALENDAR_H__
 
#include "wgui.h"
#include "gui_calendar.h"
#include "lcd_sw_rnd.h"

#define CALENDAR_CACHE_CELL_SIZE    (((GUI_CALENDAR_CACHE_WIDTH * GUI_CALENDAR_CACHE_HEIGHT * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3) * 2)
#define CALENDAR_CACHE_POPUP_SIZE   (((GUI_CALENDAR_FRAME_WIDTH >> 1) * (GUI_CALENDAR_FRAME_HEIGHT >> 1) * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3)

extern gui_calendar_struct g_wgui_calendar;

extern void wgui_calendar_create(U32 calendar_type, U32 row_num, U32 column_num, U8* cell_buf, U8* popup_buf);
extern void wgui_calendar_set_bg(UI_image_ID_type bg_id);
extern void wgui_calendar_set_select_horizontal1(
            UI_image_ID_type left_up,
            UI_image_ID_type left_down,
            UI_image_ID_type right_up,
            UI_image_ID_type right_down,
            U8 *string,
            U32 align_type);
extern void wgui_calendar_set_select_horizontal1_string(U8 *string);
extern void wgui_calendar_set_select_horizontal1_handler(
            GUICalendarV2EventFuncPtr left_handler,
            GUICalendarV2EventFuncPtr right_handler);
extern void wgui_calendar_set_select_horizontal2(
            UI_image_ID_type left_up,
            UI_image_ID_type left_down,
            UI_image_ID_type right_up,
            UI_image_ID_type right_down,
            U8 *string,
            U32 align_type);
extern void wgui_calendar_set_select_horizontal2_string(U8 *string);
extern void wgui_calendar_set_select_horizontal2_handler(
            GUICalendarV2EventFuncPtr left_handler,
            GUICalendarV2EventFuncPtr right_handler);
extern void wgui_calendar_set_select_vertical(
            UI_image_ID_type top_up,
            UI_image_ID_type top_down,
            UI_image_ID_type bottom_up,
            UI_image_ID_type bottom_down,
            U8 **string_list,
            U32 align_type);
extern void wgui_calendar_set_select_vertical_string(U8 **string_list);
extern void wgui_calendar_set_select_vertical_handler(
            GUICalendarV2EventFuncPtr top_handler,
            GUICalendarV2EventFuncPtr bottom_handler);
extern void wgui_calendar_set_normal_title(U8 *string);
extern void wgui_calendar_set_menstrual_title(U8 color_index1, U8 *string1, U8 color_index2, U8 *string2);
extern void wgui_calendar_set_horizontal_string(U8 **string_list, S32 underline_index);
extern void wgui_calendar_set_cell_array(
            gui_calendar_cell_struct *cell,
            U8 cell_bg_fill_type,
            U8 cell_text_display_type,
            U8 cell_icon_display_type);
extern void wgui_calendar_set_current(U32 current_row, U32 current_column);
extern void wgui_calendar_set_highlight(U32 highlighted_row, U32 highlighted_column);
extern void wgui_calendar_set_popup(U8 *message1, U8 *message2, U8 *message3);
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
extern void wgui_calendar_set_infobox(UI_image_ID_type *icon_list, U8 **string_list, U8 entry_num);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
extern void wgui_calendar_register_cell_highlight_handler(MMI_BOOL (*app_cell_highlight_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_left_arrow_key_handler(MMI_BOOL (*app_left_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_right_arrow_key_handler(MMI_BOOL (*app_right_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_up_arrow_key_handler(MMI_BOOL (*app_up_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_down_arrow_key_handler(MMI_BOOL (*app_down_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_up_side_key_handler(MMI_BOOL (*app_up_side_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_down_side_key_handler(MMI_BOOL (*app_down_side_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_close(void);
extern void wgui_calendar_show(void);
#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL wgui_calendar_translate_pen_event(mmi_pen_event_type_enum pen_event, S16 x, S16 y);
extern void wgui_calendar_set_pen_unable(void);
#endif /*__MMI_TOUCH_SCREEN__*/
extern void wgui_calendar_update_base_layer(void);

#endif /* __WGUI_CALENDAR_H__ */ 

