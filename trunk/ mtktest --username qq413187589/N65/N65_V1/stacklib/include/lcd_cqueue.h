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
 *   lcdcqueue.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Light weight C Data structures library: Circular Queue.
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

#ifndef _LCD_CQUEUE_H
#define _LCD_CQUEUE_H

/*******************************************************************************
 * Data Structure definition
 *******************************************************************************/
typedef struct lcd_cqueue {
    void        * * queue;
    unsigned    int size;
    unsigned    int head;
    unsigned    int tail;
    kal_bool    is_full;
    malloc_fp_t alloc_fn_p;
    free_fp_t   free_fn_p;
} lcd_cqueue;

/*******************************************************************************
 * Exported Function Prototypes
 *******************************************************************************/
extern lcd_cqueue *lcd_create_cqueue(unsigned int size, malloc_fp_t alloc_fn_p,
                            free_fp_t free_fn_p);

extern kal_uint32 new_lcd_cqueue_mem_size(unsigned int size);

extern void lcd_cqueue_insert(lcd_cqueue *q, void *item);

extern void lcd_cqueue_insert_front(lcd_cqueue *q, void *item);

extern void *lcd_cqueue_remove(lcd_cqueue *q);

extern void *lcd_cqueue_remove_rear(lcd_cqueue *q);

extern kal_bool lcd_cqueue_is_empty(lcd_cqueue *q);

extern kal_bool lcd_cqueue_is_full(lcd_cqueue *q);

extern unsigned int lcd_cqueue_num_of_items(lcd_cqueue *q);

extern void *lcd_cqueue_index(lcd_cqueue *q , unsigned int    index);

extern void lcd_cqueue_map(lcd_cqueue *q, lcd_mapfunc f, void *info);

extern void lcd_cqueue_delete_all(lcd_cqueue *q);

extern void lcd_delete_cqueue(lcd_cqueue *q);

extern lcd_cqueue *lcd_create_cqueue_with_mem(unsigned int size,void *mem_ptr);

#ifdef _DEBUG_LCD_CQUEUE
extern void lcd_cqueue_print(lcd_cqueue    *q);
#endif
#endif /* _LCD_CQUEUE_H */


