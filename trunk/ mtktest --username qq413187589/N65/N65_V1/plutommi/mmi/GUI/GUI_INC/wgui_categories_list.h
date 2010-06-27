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

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_categories_list.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  list related categories.
 *
 *  Author:
 * -------
 *  Nan Zhao
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
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_LIST_H__
#define __WGUI_CATEGORIES_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "FrameworkStruct.h"

extern void mmi_cat_refresh_asyncdynamic_list(
                S32 number_of_items,
                S32 highlighted_item,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func);


#ifdef __MMI_MAINLCD_240X320__
#define CAT85_MAIN_IMAGE_WIDTH  27
#define CAT85_MAIN_IMAGE_HEIGHT 25
#define CAT85_SUB_IMAGE_WIDTH   17
#define CAT85_SUB_IMAGE_HEIGHT  17
#define CAT85_MENUITEM_OFFSET   4
#else /* __MMI_MAINLCD_240X320__ */ 
#define CAT85_MAIN_IMAGE_WIDTH  27
#define CAT85_MAIN_IMAGE_HEIGHT 25
#define CAT85_SUB_IMAGE_WIDTH   17
#define CAT85_SUB_IMAGE_HEIGHT  17
#define CAT85_MENUITEM_OFFSET   2
#endif /* __MMI_MAINLCD_240X320__ */ 


extern void ShowCategory85Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 main_icon,
                U16 sub_icon,
                U8 *history_buffer);




#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_MAINLCD_240X320__
#define CAT265_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT)
#define CAT265_CONTROL_AREA_HEIGHT  (96)
#define CAT265_LIST_Y               (CAT265_CONTROL_AREA_Y+CAT265_CONTROL_AREA_HEIGHT)
#define CAT265_LIST_HEIGHT          (182)
#define CAT265_PREVIEW_X            (7)
#define CAT265_PREVIEW_WIDTH        (95)
#define CAT265_PREVIEW_Y            (29)
#define CAT265_PREVIEW_HEIGHT       (75)
#define CAT265_TITLE_X              (CAT265_PREVIEW_X+CAT265_PREVIEW_WIDTH+5)
#define CAT265_TITLE_WIDTH          (MAIN_LCD_DEVICE_WIDTH-CAT265_TITLE_X-CAT265_PREVIEW_X)
#define CAT265_TITLE_Y              (60)
#define CAT265_TITLE_HEIGHT         (30)
#define CAT265_TEXT_0_X             (0)
#define CAT265_TEXT_0_WIDTH         (66)
#define CAT265_TEXT_0_OFFSET        (2)
#define CAT265_ICON_X               (CAT265_TEXT_0_X+CAT265_TEXT_0_WIDTH)
#define CAT265_ICON_WIDTH           (26)
#define CAT265_ICON_OFFSET          (1)
#define CAT265_TEXT_1_X             (CAT265_ICON_X+CAT265_ICON_WIDTH)
#define CAT265_TEXT_1_OFFSET        (2)
#else /* __MMI_MAINLCD_240X320__ */ 
#define CAT265_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT)
#define CAT265_CONTROL_AREA_HEIGHT  (96)
#define CAT265_LIST_Y               (CAT265_CONTROL_AREA_Y+CAT265_CONTROL_AREA_HEIGHT)
#define CAT265_LIST_HEIGHT          (182)
#define CAT265_PREVIEW_X            (4)
#define CAT265_PREVIEW_WIDTH        (86)
#define CAT265_PREVIEW_Y            (29)
#define CAT265_PREVIEW_HEIGHT       (68)
#define CAT265_TEXT_0_X             (0)
#define CAT265_TEXT_0_WIDTH         (66)
#define CAT265_TEXT_0_OFFSET        (1)
#define CAT265_ICON_X               (CAT265_TEXT_0_X+CAT265_TEXT_0_WIDTH)
#define CAT265_ICON_WIDTH           (30)
#define CAT265_ICON_OFFSET          (1)
#define CAT265_TEXT_1_X             (CAT265_ICON_X+CAT265_ICON_WIDTH)
#define CAT265_TEXT_1_OFFSET        (1)
#endif /* __MMI_MAINLCD_240X320__ */ 
#define CAT265_PREVIEW_AREA_SIZE    (((CAT265_PREVIEW_WIDTH * CAT265_PREVIEW_HEIGHT * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3))


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void (*LayerRedrawCallback)(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height);
    
/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void wgui_cat265_set_title(U8 *title);
extern void ShowCategory265Screen(
        U8 *title,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        FuncPtr pre_highlight_callback,
        LayerRedrawCallback redraw_callback,
        S32 highlighted_item,
        //U16 list_icon,
        U8 *history_buffer);
void wgui_cat265_refresh_list(S32 number_of_items, S32 highlighted_item, MMI_BOOL redraw_flag);
#endif /* __MMI_CAT265_SUPPORT__ */


extern void ShowCategory427Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U8 *history_buffer);

#endif /* __WGUI_CATEGORIES_LIST_H__ */ 

