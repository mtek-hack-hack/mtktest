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
 *  wgui_categories_MM.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Main Menu related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_MM_H__
#define __WGUI_CATEGORIES_MM_H__

#include "MMI_features.h"
#include "wgui_categories_util.h"

/* 1: Enables animated wallpapers in Idle screen
   0: Disables animated wallpapers in Idle screen                    */
#ifdef __MMI_ANIMATED_WALLPAPERS__
#define ENABLE_ANIMATED_WALLPAPERS              1
//#else 
//#define ENABLE_ANIMATED_WALLPAPERS              0
#endif 

/* 1: Enables direct main menu implementation (fast but fixed to 3x3 grid)
   0: Uses standard main menu implementation (slow with flexible grid)     */
#define ENABLE_DIRECT_MAIN_MENU_IMPLEMENTATION     1

/* 1: Enables one pixel spacing around the main menu                 */
/* 0: No spacing around the main menu                          */
/* This applies only to direct main menu                          */
#define DIRECT_MAIN_MENU_BOUNDARY_SPACING       0

/* Use this to define the amount by which the icons displayed
   in unfocussed state (first frame) are shifted in the main menu       */
#define DIRECT_MAIN_MENU_FIRST_FRAME_SHIFT_X    -5
#define DIRECT_MAIN_MENU_FIRST_FRAME_SHIFT_Y    -5

/* Set this to 1 to be able to change icons along with the title. This is
   done externally using the highlight handler registered to the main menu
   Set to 0 for normal operation                               */
#define DISABLE_MAIN_MENU_HIGHLIGHT_TITLE_UPDATE   1

typedef struct _matrix_main_menu_category_history
{
    U16 history_ID;
    S16 highlighted_item;
    U32 flags;
} matrix_main_menu_category_history;

typedef struct _circular_menu_category_history
{
    U16 history_ID;
    S16 highlighted_item;
    U32 flags;
} circular_menu_category_history;

typedef struct _matrix_main_menu
{
    S32 x, y;
    U32 flags;
    S32 n_items;
    S32 highlighted_item;
    PU8 *list_of_items;
    void (*item_highlighted) (S32 item_index);
    void (*item_unhighlighted) (S32 item_index);
    bitmap highlight_area;
    S32 save_x, save_y;
} matrix_main_menu;

extern matrix_main_menu _wgui_main_menu;
extern UI_string_type _wgui_main_menu_item_strings[];

extern void standard_bg_ani_list_highlight_handler(S32 item_index);
extern U8 set_circular_menu_category_history(U16 history_ID, U8 *history_buffer);
extern void get_circular_menu_category_history(U16 history_ID, U8 *history_buffer);

extern void RedrawCategory14Screen(void);
extern void ShowCategory14Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ExitCategory14Screen(void);
extern S32 GetCategory14HistorySize(void);
extern U8 *GetCategory14History(U8 *history_buffer);
extern void initialize_mainmenu_title_icons(void);
extern void draw_bg_animation(void);
extern void draw_bg(void);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern void ShowCategory414Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                U16 *list_of_icons2,
                U16 *list_of_menuitem_id,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ShowCat414Matrix(
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                matrix_menu_category_history *history_buffer);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#endif /* __WGUI_CATEGORIES_MM_H__ */ 

