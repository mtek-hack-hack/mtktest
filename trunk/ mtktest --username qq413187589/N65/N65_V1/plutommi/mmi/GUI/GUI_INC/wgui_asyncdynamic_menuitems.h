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
*  LAWS PRINCIPLES.	 ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *  wgui_asyncdynamic_menuitems.h
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
 *			   HISTORY
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

#ifndef __WGUI_ASYNCDYNAMIC_MENUITEMS_H__
#define __WGUI_ASYNCDYNAMIC_MENUITEMS_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "wgui.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_ASYNCHINT_NUM                   5
#define MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE     MAX_SUB_MENU_SIZE
#define MAX_ASYNCDYNAMIC_ITEMS_BUFF         16
#define MASK_ASYNCDYNAMIC_ITEMS_BUFF        15
    
#define FIXED_ICONLIST_MAX_TEXT_COLUMNS     3
#define FIXED_ICONLIST_MAX_ICON_COLUMNS     4

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    UI_string_type item_list[FIXED_ICONLIST_MAX_TEXT_COLUMNS];
    PU8 image_list[FIXED_ICONLIST_MAX_ICON_COLUMNS];
} gui_iconlist_menu_item;

typedef S32 (*GetAsyncItemFuncPtr)(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
typedef S32 (*GetAsyncHintFuncPtr)(S32 start_index, UI_string_type *hint_array);

typedef struct
{
    S32 head_item_index;
    S32 head;
    S32 tail;
    S32 count;
    S32 n_total_items;
    GetAsyncItemFuncPtr load_func;
    GetAsyncHintFuncPtr hint_func;
} asyncdynamic_item_circular_buffer_t;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern asyncdynamic_item_circular_buffer_t asyncdynamic_item_buffer;
    
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern S32 init_asyncdynamic_item_buffer(
            S32 n_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func);
extern fixed_icontext_list_menuitem_type* get_asyncdynamic_item_from_buffer(S32 index);
extern pBOOL in_asyncdynamic_item_buffer(S32 index);
extern S32 load_chunk_asyncdynamic_item_buffer(S32 start_index, S32 n_items);
extern void resize_asyncdynamic_icontext_menuitems_to_list_width(void);

#endif /* __WGUI_ASYNCDYNAMIC_MENUITEMS_H__ */

