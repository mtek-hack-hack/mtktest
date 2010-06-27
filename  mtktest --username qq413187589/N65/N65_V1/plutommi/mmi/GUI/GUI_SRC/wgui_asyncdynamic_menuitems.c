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
 *  wgui_asyncdynamic_menuitems.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
 *  to a category screen, a modification in MMI for dynamic item loading is required as the following.
 *
 *  Compared to dynamic list menu, 
 *  1. it gets data of multiple menu items in one callback function,
 *  2. it uses icontext-list menu item instead of icontext menu item.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_asyncdynamic_menus.h"
#include "DebugInitDef.h"

#if (MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
#error "Internal parameter error"
#endif 

#if (MAX_SUB_MENUS < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
#error "Internal parameter error"
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
asyncdynamic_item_circular_buffer_t asyncdynamic_item_buffer;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  init_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Iitialize the asyncdynamic item buffer.
 *
 *  a. If the icontext-list menu item has more than one string, it can not support hint callback
 *  because hint and secnd string item use the same memory buffer.
 *  b. If 'history' is not NULL, 'h_item' is ignored. 
 * PARAMETERS
 *  total_items         [IN]        total number of items
 *  get_item_func       [IN]        A call back function for filling in item text & image at run time
 *  get_hint_func       [IN]        Callback funtion for filling hint data
 * RETURNS
 *  Return 1 if sucessful; otherwise 0.
 *****************************************************************************/
S32 init_asyncdynamic_item_buffer(S32 total_items, GetAsyncItemFuncPtr get_item_func, GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_item_buffer.head_item_index = 0;
    asyncdynamic_item_buffer.head = 0;
    asyncdynamic_item_buffer.tail = 0;
    asyncdynamic_item_buffer.count = 0;
    asyncdynamic_item_buffer.n_total_items = total_items;
    asyncdynamic_item_buffer.load_func = get_item_func;
    asyncdynamic_item_buffer.hint_func = get_hint_func;

    /* asyncdynamic_list_goto_item_no_redraw() will load the data */
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  get_asyncdynamic_item_from_buffer
 * DESCRIPTION
 *  Get the specified item in the buffer.
 * PARAMETERS
 *  index       [IN]        item index to be retrieved
 * RETURNS
 *  An icontext list menu item
 *****************************************************************************/
fixed_icontext_list_menuitem_type *get_asyncdynamic_item_from_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = index - asyncdynamic_item_buffer.head_item_index;
    MMI_ASSERT(offset >= 0 && offset < asyncdynamic_item_buffer.count);

    return &MMI_fixed_icontext_list_menuitems[(offset + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
}


/*****************************************************************************
 * FUNCTION
 *  in_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Check whether a item is loaded in buffer
 * PARAMETERS
 *  index       [IN]        item index to be checked
 * RETURNS
 *  Return TRUE if the specified item exists in the buffer; otherwise, FALSE.
 *****************************************************************************/
pBOOL in_asyncdynamic_item_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asyncdynamic_item_buffer.count == 0)
    {
        return FALSE;
    }
    count = index - asyncdynamic_item_buffer.head_item_index;
    if (count < 0 || count >= asyncdynamic_item_buffer.count)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  load_chunk_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Load a chunk of items, starting from [start_index] to [start_index+n_items-1], to the buffer.
 *  The loading mechanism will try to maintain the continuous buffer as large as possible.
 * PARAMETERS
 *  start_index     [IN]        the starting index of requested items
 *  n_items         [IN]        the number of items to be loaded
 * RETURNS
 *  1: success, 0: fail
 *****************************************************************************/
S32 load_chunk_asyncdynamic_item_buffer(S32 start_index, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 i;
    S32 start;  /* Start index in queue */
    S32 offset; /* Offset to queue head */
    S32 count;  /* count of loaded menu item */
    gui_iconlist_menu_item md[MAX_ASYNCDYNAMIC_ITEMS_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use two array subMenuData[] and hintData[] only. */
    /* MMI_DBG_ASSERT(!asyncdynamic_item_buffer.hint_func || MMI_fixed_icontext_list_menuitem.n_text_columns <= 1); */
    MMI_DBG_ASSERT(MMI_fixed_icontext_list_menuitem.n_text_columns <= 2);

    /*
     * FIXME. 
     * 1. the algorithm is slightly different than load_chunk_dynamic_item_buffer() 
     * it should be revised some day.
     *
     * 2. The performance can be improved if some data is already in the queue.
     * This is okay because n_items is typically 1 or 2. However, n_items might be large
     * with touch screen.
     * 
     */

    /* 
     * Compute the number of menu item to load 
     */
    if (asyncdynamic_item_buffer.count == 0)
    {
        offset = 0;
    }
    else    /* sometimes offset < 0 */
    {
        offset = start_index - asyncdynamic_item_buffer.head_item_index;
    }

    if (n_items > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
    {
        n_items = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
    }

    if (start_index + n_items > asyncdynamic_item_buffer.n_total_items)
    {
        n_items = asyncdynamic_item_buffer.n_total_items - start_index;
    }

    if (n_items <= 0)
    {
        return 0;
    }

    /* 
     * Get the data 
     */
    for (i = 0; i < n_items; i++)   /* Use md[] to hold data temporarily */
    {
        /* We hold data in subMenuData[] and hintData[]. */
        if (MMI_fixed_icontext_list_menuitem.n_text_columns >= 1)
        {
            md[i].item_list[0] = (UI_string_type)subMenuData[(i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
        }
        
        if (MMI_fixed_icontext_list_menuitem.n_text_columns >= 2)
        {
            md[i].item_list[1] = (UI_string_type)hintData[(i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
        }
        
        /* The 3rd text column shares hintData[][] with the 2nd text column. */
        MMI_ASSERT(MAX_ASYNCDYNAMIC_ITEMS_BUFF * 2 <= MAX_SUB_MENUS);
        if (MMI_fixed_icontext_list_menuitem.n_text_columns >= 3)
        {
            md[i].item_list[2] = (UI_string_type)hintData[((i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF) + MAX_ASYNCDYNAMIC_ITEMS_BUFF];
        }
    }

    count = asyncdynamic_item_buffer.load_func(start_index, md, n_items);

    if (count != n_items)
    {
        /* Data loaded fail */
        return 0;
    }

    start = (offset + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;

    for (i = 0; i < n_items; i++)
    {
        S32 j;
        S32 k = (i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;

        for (j = 0; j < MMI_fixed_icontext_list_menuitem.n_icon_columns; j++)
        {
            MMI_fixed_icontext_list_menuitems[k].item_icons[j] = md[i].image_list[j];
        }

        for (j = 0; j < MMI_fixed_icontext_list_menuitem.n_text_columns; j++)
        {
            MMI_fixed_icontext_list_menuitems[k].item_texts[j] = md[i].item_list[j];
        }

        for (j = 0; j < FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS; j++)
        {
            /* Icon animation is not enabled, but it can be supported easily */
            MMI_fixed_icontext_list_menuitems[k].item_icon_handles[j] = GDI_ERROR_HANDLE;
        }

        MMI_fixed_icontext_list_menuitems[k].flags = 0;
    }

    /* 
     * Setup queue head & tail
     */
    if (asyncdynamic_item_buffer.count == 0 || (offset < 0 && offset + count < 0) ||
        (offset > asyncdynamic_item_buffer.count))
    {
        /* Drop all old data */
        asyncdynamic_item_buffer.head_item_index = start_index;
        asyncdynamic_item_buffer.head = start;
        asyncdynamic_item_buffer.tail = (start + count) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
        asyncdynamic_item_buffer.count = count;
    }
    else if (offset < 0)
    {
        /* Move head backward */
        asyncdynamic_item_buffer.head_item_index = start_index;
        asyncdynamic_item_buffer.head = start;
        size = asyncdynamic_item_buffer.count - offset;
        if (size > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
        {
            size = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
        }
        else if (size < count)
        {
            size = count;
        }
        asyncdynamic_item_buffer.tail = (start + size) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
        asyncdynamic_item_buffer.count = size;
    }
    else
    {
        size = count + offset;
        if (size > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
        {
            asyncdynamic_item_buffer.head = asyncdynamic_item_buffer.tail =
                (start + count) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
            asyncdynamic_item_buffer.head_item_index = start_index + count - MAX_ASYNCDYNAMIC_ITEMS_BUFF;
            MMI_DBG_ASSERT(asyncdynamic_item_buffer.head_item_index >= 0);
            asyncdynamic_item_buffer.count = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
        }
        else if (size > asyncdynamic_item_buffer.count)
        {
            asyncdynamic_item_buffer.tail = (asyncdynamic_item_buffer.head + size) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
            asyncdynamic_item_buffer.count = size;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  resize_asyncdynamic_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the asyncdynamic menu item width to the maximum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_asyncdynamic_icontext_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_DRAW;

        gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);

        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_DRAW;
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_icontext_list_menuitems(
                MMI_fixed_list_menu.width - 4,
                MMI_fixed_icontext_list_menuitem.height);
        }
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_icontext_list_menuitems(MMI_fixed_list_menu.width - 4, MMI_fixed_icontext_list_menuitem.height);
    }
}


