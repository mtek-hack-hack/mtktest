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
 * Filename:
 * ---------
 *  gui_dynamic_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  In order to use limited memory (size decided in compile-time) to load 
 *  unlimited items (size decide in run-time) to a category screen, a 
 *  modification in MMI for dynamic item loading is required as the following.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef __GUI_DYNAMIC_MENUS_H__
#define __GUI_DYNAMIC_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_fixed_menus.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void gui_show_dynamic_list_menu(fixed_list_menu *m);
extern void gui_show_dynamic_list_menu_no_draw(fixed_list_menu *m);

extern void switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item);

extern void gui_dynamic_list_menu_goto_item(fixed_list_menu *m, S32 i);
extern void gui_dynamic_list_menu_goto_next_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_goto_previous_item(fixed_list_menu *m);

extern void gui_dynamic_list_menu_locate_highlighted_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_locate_previous_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_locate_next_item(fixed_list_menu *m);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_dynamic_list_menu_translate_pen_event(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menu_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_DYNAMIC_MENUS_H__ */ 

