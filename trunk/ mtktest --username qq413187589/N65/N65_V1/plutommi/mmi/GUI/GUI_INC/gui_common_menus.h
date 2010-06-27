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
 *  gui_common_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  common flags for menus and menuitems
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_COMMON_MENUS_H__
#define __GUI_COMMON_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* common menu item flags */
#define UI_MENUITEM_STATE_NORMAL                0x00000000
#define UI_MENUITEM_STATE_FOCUSSED              0x00000001
#define UI_MENUITEM_STATE_SELECTED              0x00000002
#define UI_MENUITEM_STATE_DISABLED              0x00000004
#define UI_MENUITEM_STATE_ANIMATE               0x00000008
#define UI_MENUITEM_CENTER_TEXT_X               0x00000010
#define UI_MENUITEM_CENTER_TEXT_Y               0x00000020
#define UI_MENUITEM_FOCUSSED_SHIFT1             0x00000040
#define UI_MENUITEM_FOCUSSED_SHIFT2             0x00000080
#define UI_MENUITEM_CENTER_ICON_X               0x00000100
#define UI_MENUITEM_CENTER_ICON_Y               0x00000200
#define UI_MENUITEM_DISABLE_TEXT_DISPLAY        0x00000400
#define UI_MENUITEM_PEN_USE_LONGPRESS           0x00000800
#define UI_MENUITEM_FOCUSSED_ANIMATE            0x00001000
#define UI_MENUITEM_SELECTED_ANIMATE            0x00002000
#define UI_MENUITEM_DISABLE_HIGHLIGHT           0x00004000
#define UI_MENUITEM_DISABLE_BACKGROUND          0x00008000
#define UI_MENUITEM_RIGHT_JUSTIFY               0x00010000
#define UI_MENUITEM_LEFT_JUSTIFY                0x00020000
#define UI_MENUITEM_MARQUEE_SCROLL              0x00040000
#define UI_MENUITEM_TWO_DIRECTION_SCROLL        0x00080000
#define UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS   0x00100000
#define UI_MENUITEM_DISABLE_TEXT_CLIP           0x00200000
#define UI_MENUITEM_INLINE_EDIT_OBJECT          0x00400000
#define UI_MENUITEM_TEXT_COL1_IS_NUMBER         0x00400000 /* display "1." as ".1" in Arabic for category 89 */
#define UI_MENUITEM_FILL_COL1                   0x00800000
/* fill column 2 (icontext-list menuitem) */
#define UI_MENUITEM_FILL_COL2                   0x01000000
/* for new mainmenu category (icontext menuitem) */
#define UI_MENUITEM_DISABLE_HIGHLIGHT_DISPLAY   0x01000000
#define UI_MENUITEM_RIGHT_JUSTIFY_COL2          0x02000000
#define UI_MENUITEM_DISABLE_ICON                0x04000000
/* trucate too long number/name in call list */
#define UI_MENUITEM_TRUNCATE_CONTENT            0x08000000
/* to check the existance of multi-row menu list */
#define MENU_MUTLIROW_ICON_LIST                 0x10000000
#define UI_MENUITEM_DOTTED_UNDERLINE            0x20000000
/* for bi-degree main menu */
#define UI_MENUITEM_HIGHLIGHT_SWITCH_ICON       0x40000000
/* 
 * for icontext-list with multiple text columns. 
 * Scroll the first column that contains long text. 
 */
#define UI_MENUITEM_AUTO_CHOOSE_MARQUEE         0x80000000

/* 
 * extended menu-item flags in addition to 32 standard menuitem flags.
 */

/* item display function invoked from marquee */
#define UI_MENUITEM_EXT_SHOW_IN_MARQUEE         0x00000001
#define UI_MENUITEM_EXT_SHOW_IN_ROUNDED_RECT    0x00000002
#define UI_MENUITEM_SHOW_ALL_HINTS              0x00000004
#define UI_MENUITEM_SHOW_HIGHLIGHTED_HINT       0x00000008
#define UI_MENUITEM_SHOW_ICON_ONLY_ON_HIGHLIGHT 0x00000010
#define UI_MENUITEM_EXT_SHOW_TWO_LINE_SELECT    0x00000020
#define UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY   0x00000040
#define UI_MENUITEM_EXT_SHOW_ICONTEXT_CHECKBOX      0x00000080
#define UI_MENUITEM_EXT_CONTAIN_TWO_LINE_MENU_ITEM 0x00000100

/* 
 * List menu flags 
 */
#define UI_LIST_MENU_STATE_NORMAL                  0x00000000
#define UI_LIST_MENU_STATE_FOCUSSED                0x00000001
#define UI_LIST_MENU_DISABLE_SCROLLBAR             0x00000002
#define UI_LIST_MENU_LOOP                          0x00000004
#define UI_LIST_MENU_DISABLE_BACKGROUND            0x00000008
#define UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR        0x00000010
#define UI_LIST_MENU_DISABLE_DRAW                  0x00000020
#define UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM  0x00000040
#define UI_LIST_MENU_CENTER_HIGHLIGHTED            0x00000080
#define UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM   0x00000100
#define UI_LIST_MENU_ENABLE_TRANSITION             0x00000200
#define UI_LIST_MENU_ALIGN_TO_TOP                  0x00000400
#define UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA    0x00000800
#define UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER       0x00001000
#define UI_LIST_MENU_DISABLE_PEN                   0x00002000
#define UI_LIST_MENU_DISABLE_MENUITEM_GAP          0x00004000

/* 
 * Matrix menu flags 
 */
#define UI_MATRIX_MENU_STATE_NORMAL                0x00000000
#define UI_MATRIX_MENU_STATE_FOCUSSED              0x00000001
#define UI_MATRIX_MENU_DISABLE_SCROLLBAR           0x00000002
#define UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR      0x00000010
#define UI_MATRIX_MENU_LOOP                        0x00000004
/* For matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
#define UI_MATRIX_MENU_VERTICAL_LOOP               0x00000008
#define UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR     0x00000100
#define UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR   0x00000200
/* For matrix mainmenu optimize */
#define UI_MATRIX_MENU_FOR_MAINMENU                0x00000400
#define UI_MATRIX_MENU_DISABLE_BACKGROUND          0x00000800
#define UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW 0x00001000
#define UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW  0x00002000
#define UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL 0x00004000
#define UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL  0x00008000
#define UI_MATRIX_MENU_SHOW_IND_AREA               0x00010000
/* Use callback function instead of looping on vertical highlight switching */
#define UI_MATRIX_MENU_VERTICAL_TRIGGER            0x00020000
#define UI_MATRIX_MENU_DISABLE_PEN                 0x00040000
/* 
 * Align menu items to left-top instead of scattered evenly in the center of the menu.
 * Typically used when menu item count < total row * column. 
 */
#define UI_MATRIX_MENU_ALIGN_LEFT_TOP              0x00080000
/* 
 * Horizontal selection
 */
#define UI_HORIZONTAL_SELECT_LOOP                  0x00010000
#define UI_HORIZONTAL_SELECT_NO_ITEM_HIGHLIGHTED   0x00020000

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
 
#endif /* __GUI_COMMON_MENUS_H__ */ 

