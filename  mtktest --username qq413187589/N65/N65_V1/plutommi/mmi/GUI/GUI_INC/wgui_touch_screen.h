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
 *   wgui_touch_screen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifndef __WGUI_TOUCH_SCREEN_H__
#define __WGUI_TOUCH_SCREEN_H__

#if defined(__MMI_TOUCH_SCREEN__)

#include "TouchScreenGprot.h"

#define GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY 250

enum PEN_EVENT_ON_SOFTKEY
{
    NONE = 0,
    ON_LSK,
    ON_RSK
};

typedef struct
{
    U32 pos_x;
    U32 pos_y;
    U32 width;
    U32 height;
} wgui_component_info_struct;

/* Leo start 20050722, revise code */
typedef MMI_BOOL(*mmi_pen_handler) (mmi_pen_point_struct point);

/* Leo end 20050722 */
extern void wgui_general_pen_down_hdlr(mmi_pen_point_struct point);
extern void wgui_general_pen_move_hdlr(mmi_pen_point_struct point);
extern void wgui_general_pen_up_hdlr(mmi_pen_point_struct point);
extern void wgui_general_pen_abort_hdlr(mmi_pen_point_struct point);
extern void wgui_general_pen_long_tap_hdlr(mmi_pen_point_struct point);
extern void wgui_general_pen_repeat_hdlr(mmi_pen_point_struct point);
extern void wgui_register_pen_up_handler(mmi_pen_hdlr pen_up_hdlr);
extern void wgui_register_pen_down_handler(mmi_pen_hdlr pen_down_hdlr);
extern void wgui_register_pen_move_handler(mmi_pen_hdlr pen_move_hdlr);
extern void wgui_register_pen_abort_handler(mmi_pen_hdlr pen_abort_hdlr);
extern void wgui_register_pen_repeat_handler(mmi_pen_hdlr pen_repeat_hdlr);
extern void wgui_register_pen_long_tap_handler(mmi_pen_hdlr pen_repeat_hdlr);
extern void wgui_register_general_pen_handler(void);
extern void wgui_clear_pen_handlers(void);
extern MMI_BOOL wgui_general_pen_list_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_inline_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_dynamic_list_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_asyncdynamic_list_menu_hdlr(
                    mmi_pen_point_struct point,
                    mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_matrix_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_slide_control_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_3D_circular_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);
extern MMI_BOOL wgui_general_pen_horizontal_tab_bar_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event);

extern MMI_BOOL wgui_test_object_position(mmi_pen_point_struct pos, wgui_component_info_struct obj);
extern MMI_BOOL wgui_test_image_object_position(mmi_pen_point_struct pos, S32 pos_x, S32 pos_y, PU8 img_ptr);
extern MMI_BOOL wgui_test_lsk_position(mmi_pen_point_struct pos);
extern MMI_BOOL wgui_test_rsk_position(mmi_pen_point_struct pos);

extern void wgui_reset_category_screen_control_pen_handler(void);
extern void wgui_register_category_screen_control_area_pen_handlers(
                mmi_pen_handler pen_fp,
                mmi_pen_event_type_enum event_type);
extern void wgui_reset_image_control_pen_handler(void);
extern void wgui_register_image_control_pen_handlers(
                S32 index,
                mmi_pen_handler pen_fp,
                mmi_pen_event_type_enum event_type);
extern void wgui_register_category_screen_control_area2_pen_handlers(
                mmi_pen_handler pen_fp,
                mmi_pen_event_type_enum event_type);

void wgui_register_list_item_selected_callback(void (*pen_event_selected_callback_function) (void));
void wgui_register_list_item_selected_callback_all(void (*pen_event_selected_callback_function) (void));
extern void wgui_reset_list_item_selected_callback(void);
void wgui_register_matrix_item_selected_callback(void (*pen_event_selected_callback_function) (void));
void wgui_register_matrix_item_selected_callback_all(void (*pen_event_selected_callback_function) (void));
extern void wgui_reset_matrix_item_selected_callback(void);

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

#endif /* __WGUI_TOUCH_SCREEN_H__ */ 

