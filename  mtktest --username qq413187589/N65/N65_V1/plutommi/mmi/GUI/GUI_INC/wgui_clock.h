/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wgui_clock.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  clock related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
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

#ifndef __WGUI_CLOCK_H__
#define __WGUI_CLOCK_H__

#include "wgui.h"
#include "gui_clock.h"

#define WGUI_CLOCK_MAX_ITEMS_MAIN_LCD       4
#define WGUI_CLOCK_MAX_ITEMS_SUB_LCD        2
#define WGUI_CLOCK_MAX_ITEMS                (WGUI_CLOCK_MAX_ITEMS_MAIN_LCD + WGUI_CLOCK_MAX_ITEMS_SUB_LCD)
#define WGUI_CLOCK_START_ID_MAIN_LCD        0
#define WGUI_CLOCK_MAINLCD_CLOCK1           WGUI_CLOCK_START_ID_MAIN_LCD
#define WGUI_CLOCK_MAINLCD_CLOCK2           (WGUI_CLOCK_START_ID_MAIN_LCD + 1)
#define WGUI_CLOCK_START_ID_SUB_LCD         WGUI_CLOCK_MAX_ITEMS_MAIN_LCD
#define WGUI_CLOCK_SUBLCD_CLOCK1            WGUI_CLOCK_START_ID_SUB_LCD
#define WGUI_CLOCK_SUBLCD_CLOCK2            (WGUI_CLOCK_START_ID_SUB_LCD + 1)

extern gui_clock_struct g_wgui_clock_list[WGUI_CLOCK_MAX_ITEMS];

extern void wgui_clock_create(U32 clock_id, S32 x, S32 y, S32 width, S32 height, gui_clock_type_enum clock_type);
extern void wgui_clock_close(U32 clock_id);
extern void wgui_clock_close_all(void);
extern void wgui_clock_close_main_lcd(void);
extern void wgui_clock_close_sub_lcd(void);
extern void wgui_clock_show(void);
extern void wgui_clock_show_main_lcd(void);
extern void wgui_clock_show_sub_lcd(void);
extern void wgui_clock_update(void);
extern void wgui_clock_update_main_lcd(void);
extern void wgui_clock_update_sub_lcd(void);
extern void wgui_clock_move(U32 clock_id, S32 x, S32 y);
extern void wgui_clock_resize(U32 clock_id, S32 width, S32 height);
extern void wgui_clock_set_time(U32 clock_id, applib_time_struct newtime);
extern void wgui_clock_get_time(U32 clock_id, applib_time_struct *time);
extern void wgui_clock_set_hide_function(U32 clock_id, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));


extern void wgui_clock_set_analog_clock_hour_hand_color(U32 clock_id, color new_color);
extern void wgui_clock_set_analog_clock_min_hand_color(U32 clock_id, color new_color);
extern void wgui_clock_set_date_text_font(U32 clock_id, UI_font_type new_font);
extern void wgui_clock_set_date_text_color(U32 clock_id, color new_color);
extern void wgui_clock_set_date_text_border_color(U32 clock_id, color new_color);
extern void wgui_clock_set_time_text_font(U32 clock_id, UI_font_type new_font);
extern void wgui_clock_set_time_text_color(U32 clock_id, color new_color);
extern void wgui_clock_set_time_text_border_color (U32 clock_id, color new_color);

#ifdef __MMI_SUBLCD__
    extern void wgui_clock_set_date_text_font_sub_lcd(U32 clock_id, UI_font_type new_font);
    extern void wgui_clock_set_date_text_color_sub_lcd(U32 clock_id, color new_color);
    extern void wgui_clock_set_date_text_border_color_sub_lcd(U32 clock_id, color new_color);
    extern void wgui_clock_set_time_text_font_sub_lcd(U32 clock_id, UI_font_type new_font);
    extern void wgui_clock_set_time_text_color_sub_lcd(U32 clock_id, color new_color);
    extern void wgui_clock_set_time_text_border_color_sub_lcd(U32 clock_id, color new_color);
#endif /*__MMI_SUBLCD__*/

extern void wgui_clock_set_gap_between_two_lines(U32 clock_id, S32 new_gap);
extern void wgui_clock_measure_time_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font);
extern void wgui_clock_measure_date_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font);
extern void wgui_clock_set_text_border_enable(U32 clock_id,  MMI_BOOL enable);
extern void wgui_clock_set_on_idle(U32 clock_id,  MMI_BOOL on_idle);

#endif /* __WGUI_CLOCK_H__ */ 

