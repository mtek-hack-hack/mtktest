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
 *   lcd_lqueue.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Light weight C Data structures library: Linear Queue.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _LCD_LQUEUE_H
#define _LCD_LQUEUE_H

/*************************************************************************
 * Macros Without Parameters
 *************************************************************************/
#define  BIN_OVERHEAD             2

/*************************************************************************
 * Data  structure definition
 *************************************************************************/
typedef enum {
    NOT_SET,
    BY_FN_P,
    BY_USR_MEM
}mem_for_items;

/*************************************************************************
 * Arbitrary Size Linear Queue
 *************************************************************************/

/* This queue works by maintaining a doubly linked list of bins of
 * size bin_size, when the current bin is full a new bin is allocated
 * and chained to the end of the current bin. Likewise when the last
 * item in a bin is removed and the next bin is there, the current
 * bin is freed and the head is moved to the first item in the next
 * bin. See figure given bellow.
 *
 *         ____      ____      ____      ____
 *        |    |    |    |    |    |    |    |
 *        |____|    |____|    |____|    |____|
 * head ->|    |    |    |    |    |    |    |
 *        |____|    |____|    |____|    |____|
 *        |    |    |    |    |    |    |    | <- tail
 *        |____|    |____|    |____|    |____|
 *        |    |    |    |    |    |    |    |
 *        |____|<---|____|<---|____|<---|____|
 *        |    |    |    |    |    |    |    |
 *        |____|    |____|    |____|    |____|
 *            |______^  |______^  |_______^
 *
 */

typedef void * * lcd_lqueue_bin;

typedef struct lcd_lqueue {
    unsigned int       bin_size;
         /* The first bin. */
    lcd_lqueue_bin     start;
         /* The position of the head within the bin. */
    unsigned int       head;
         /* The last bin. */
    lcd_lqueue_bin     end;
         /* The position of the tail within the bin. */
    unsigned int       tail;
         /* Number of bins allocated so far. */
    unsigned int       bin_count;
         /* Indicates the type of memory for items. */
    mem_for_items      item_mem;
    kal_bool           is_empty;
    malloc_fp_t        alloc_fn_p;
    free_fp_t          free_fn_p;
    kal_bool           is_cntxt_mem_usr_mem;
} lcd_lqueue;

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
extern lcd_lqueue *lcd_create_lqueue(unsigned int   bin_size,
                                     malloc_fp_t    alloc_fn_p,
                                     free_fp_t      free_fn_p);

extern lcd_lqueue *lcd_create_lqueue_with_mem(unsigned int   bin_size,
                                            malloc_fp_t    alloc_fn_p,
                                            free_fp_t      free_fn_p,
                                            void           *mem_ptr);

extern kal_uint32 lcd_lqueue_mem_size(unsigned int bin_size);

extern kal_bool lcd_lqueue_insert_at_rear(lcd_lqueue    *q,
                                          void          *item);

extern kal_bool lcd_lqueue_insert_at_rear_with_mem(lcd_lqueue  *q,
                                                void        *item,
                                                void        *mem_ptr);

extern kal_uint32 lcd_lqueue_mem_for_insert_at_rear(lcd_lqueue  *q);

extern kal_bool lcd_lqueue_insert_at_front(lcd_lqueue    *q,
                                           void          *item);

extern kal_bool lcd_lqueue_insert_at_front_with_mem(lcd_lqueue  *q,
                                                 void        *item,
                                                 void        *mem_ptr);

extern kal_uint32 lcd_lqueue_mem_for_insert_at_front(lcd_lqueue  *q);

/* The following function will be removed once variable
 * length array is implemented.
 */
extern kal_bool lcd_lqueue_insert_at_index(lcd_lqueue *q, void *item,
                                           unsigned int   index);

extern kal_bool lcd_lqueue_insert_at_index_with_mem(lcd_lqueue     *q,
                                                void           *item,
                                                unsigned int  index,
                                                void          *mem_ptr);

extern kal_uint32 lcd_lqueue_mem_for_insert_at_index(lcd_lqueue    *q,
                                                 unsigned int  index);

extern void *lcd_lqueue_remove(lcd_lqueue *q, void **mem_to_free);

extern void *lcd_lqueue_remove_rear(lcd_lqueue *q, void **mem_to_free);

extern kal_bool lcd_lqueue_is_empty(lcd_lqueue *q);

extern unsigned int lcd_lqueue_num_of_items(lcd_lqueue *q);

extern void  *lcd_lqueue_index(lcd_lqueue *q, unsigned int idx);

extern void lcd_lqueue_map(lcd_lqueue *q, lcd_mapfunc f, void *info);

/* The following function is a conditional map function
 * which stop mapping items when function 'f' returns
 * KAL_FALSE.If mapping is done for all items, it returns
 * KAL_TRUE, else returns KAL_FALSE.
 */
extern kal_bool lcd_lqueue_cmap(lcd_lqueue *q, lcd_cmapfunc f, void *info);

extern void lcd_lqueue_delete_all(lcd_lqueue *q);

extern void lcd_delete_lqueue(lcd_lqueue *q);

extern void*  lcd_lqueue_remove_from_index(lcd_lqueue   *q,
                                           unsigned int idx,
                                           void  **mem_to_free);

#ifdef _DEBUG_LCD_LQUEUE
extern void lcd_lqueue_print(lcd_lqueue    *q);
#endif
#endif /* _LCD_LQUEUE_H */


