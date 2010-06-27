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
 *  gui_scrollbars_post_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Scrollbars - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_SCROLLBARS_POST_OEM_H__
#define __GUI_SCROLLBARS_POST_OEM_H__

#include "gui_scrollbars.h"

#if defined(UI_SCROLLBAR_STYLE_5)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT  5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON  15
#define GUI_SCROLLBAR_ARROW_GAP  3
#elif defined(UI_SCROLLBAR_STYLE_4) 
#define GUI_SCROLLBAR_STYLE4_GAP    1
#define GUI_SCROLLBAR_ALPHA         50

#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT  5

#define GUI_SCROLLBAR_STYLE4_TOUCH_GAP 2

#define GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP 1

#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON  15

/* Minimum height of scroll button to have 3 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3 30
/* Minimum height of scroll button to have 2 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2 20
#define GUI_SCROLLBAR_MARK_WIDTH 6

/* Spacing of arrow and icon border */
#define GUI_SCROLLBAR_ARROW_GAP  3
/* 
* In current design, 176x220 use 14-pixel scrollbar. 240x320 use 16-pixel scrollbar 
* There is only 10 graident colors inside 16-pixel scrollbar.
* GUI_SCROLLBAR_NUM_GRADIENT_COLOR=16 is pretty enough for normal use.
*/
#define GUI_SCROLLBAR_NUM_GRADIENT_COLOR        3

#define GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS    220
#define GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS    180

#define GUI_SCROLLBAR_MAX_GRADIENT_SATURATION   220
#define GUI_SCROLLBAR_MIN_GRADIENT_SATURATION   180


#elif defined(UI_SCROLLBAR_STYLE_3) 
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT  5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON  15

/* Minimum height of scroll button to have 3 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3 30
/* Minimum height of scroll button to have 2 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2 20
#define GUI_SCROLLBAR_MARK_WIDTH 6

/* Spacing of arrow and icon border */
#define GUI_SCROLLBAR_ARROW_GAP  3

/* 
 *Only GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL and GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL
 * use theme colors.
 */

#define GUI_SCROLLBAR_ARROW_SATURATION          200     /* large value */
#define GUI_SCROLLBAR_ARROW_LIGHTNESS           140     /* small value */

/* 
 * In current design, 176x220 use 14-pixel scrollbar. 240x320 use 16-pixel scrollbar 
 * There is only 10 graident colors inside 16-pixel scrollbar.
 * GUI_SCROLLBAR_NUM_GRADIENT_COLOR=16 is pretty enough for normal use.
 */
#define GUI_SCROLLBAR_NUM_GRADIENT_COLOR        16

#define GUI_SCROLLBAR_MAX_GRADIENT_SATURATION   230
#define GUI_SCROLLBAR_MIN_GRADIENT_SATURATION   160
#define GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS    210
#define GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS    160

#define GUI_SCROLLBAR_LIGHT_SATURATION          200     /* < GUI_SCROLLBAR_MAX_GRADIENT_SATURATION */
#define GUI_SCROLLBAR_LIGHT_LIGHTNESS           230     /* > GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS */
#define GUI_SCROLLBAR_MEDIUM_SATURATION         180
#define GUI_SCROLLBAR_MEDIUM_LIGHTNESS          175
#define GUI_SCROLLBAR_DARK_SATURATION           150
#define GUI_SCROLLBAR_DARK_LIGHTNESS            145
#define GUI_SCROLLBAR_BORDER_SATURATION         250     /* large value */
#define GUI_SCROLLBAR_BORDER_LIGHTNESS          120     /* small value */

#elif defined(UI_SCROLLBAR_STYLE_2)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT  5
#endif /* UI_SCROLLBAR_STYLE_5 */


extern void gui_horizontal_scrollbar_redraw_button_style_1(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_1(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_1(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_1(vertical_scrollbar *v);

extern void gui_horizontal_scrollbar_redraw_button_style_2(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_2(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_2(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_2(vertical_scrollbar *v);

extern void gui_horizontal_scrollbar_redraw_button_style_3(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_3(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_3(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_3(vertical_scrollbar *v);

extern void gui_horizontal_scrollbar_redraw_button_style_4(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_4(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_4(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_4(vertical_scrollbar *v);

extern void gui_horizontal_scrollbar_redraw_button_style_5(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_5(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_5(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_5(vertical_scrollbar *v);
#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
extern S32 gui_scrollbar_get_button_min_size(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif
#endif /* __GUI_SCROLLBARS_POST_OEM_H__ */

