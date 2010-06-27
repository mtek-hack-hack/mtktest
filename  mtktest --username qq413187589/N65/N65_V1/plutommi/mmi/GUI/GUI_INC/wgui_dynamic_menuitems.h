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
 *  wgui_dynamic_menuitems.h
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

#ifndef __WGUI_DYNAMIC_MENUITEMS_H__
#define __WGUI_DYNAMIC_MENUITEMS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_HINT_NUM                    5
#define MAX_DYNAMIC_ITEM_TEXT_SIZE      MAX_SUB_MENU_SIZE
#define MAX_DYNAMIC_ITEMS_BUFF          32
#define MASK_DYNAMIC_ITEMS_BUFF         31

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef pBOOL (*GetItemFuncPtr)(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
typedef S32 (*GetHintFuncPtr)(S32 item_index, UI_string_type *hint_array);
typedef void (*FlushDataFuncPtr)(void);

typedef struct
{
    S32 head_item_index;
    S32 head;
    S32 tail;
    S32 count;
    S32 n_total_items;
    GetItemFuncPtr load_func;
    GetHintFuncPtr hint_func;
    FlushDataFuncPtr flush_func;
} dynamic_item_circular_buffer_t;

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
extern dynamic_item_circular_buffer_t dynamic_item_buffer;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void init_dynamic_item_buffer(
                S32 n_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                FlushDataFuncPtr flush_data_func);
extern void load_dynamic_item_buffer(S32 n_items);
extern fixed_icontext_menuitem_type* get_dynamic_item_from_buffer(S32 index);
extern pBOOL in_dynamic_item_buffer(S32 index);
extern void flush_dynamic_item_buffer_before_load_chunk(void);
extern S32 load_chunk_dynamic_item_buffer(S32 start_index, S32 n_items);
extern void resize_dynamic_icontext_menuitems_to_list_width(void);

#endif /* __WGUI_DYNAMIC_MENUITEMS_H__ */ 

