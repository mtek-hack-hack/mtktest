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
 *   lcd_dll.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Light weight C Data structures library:  Doubly Linked List.
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

#ifndef _LCD_DLL_H
#define _LCD_DLL_H

/*******************************************************************************
 * Data Structure definition
 *******************************************************************************/
typedef struct lcd_dll_node lcd_dll_node;

/*************************************************************************
* STRUCT
*  lcd_dll_node
*
* DESCRIPTION
*  double-linked list node
*
*************************************************************************/
struct lcd_dll_node {
   void            *data;
   lcd_dll_node    *prev;
   lcd_dll_node    *next;
};

/*************************************************************************
* STRUCT
*  lcd_dll
*
* DESCRIPTION
*  double-linked list will allocation/deallocation handler
*
*************************************************************************/
typedef struct lcd_dll {
   lcd_dll_node    *head;
   lcd_dll_node    *tail;
   lcd_cmpfunc     cmpfunc;
   malloc_fp_t     alloc_fn_p;
   free_fp_t       free_fn_p;
#ifdef MTK_REMOVED_API
   kal_bool        is_ext_mem;
#endif /* MTK_REMOVED_API */
} lcd_dll;

/*******************************************************************************
 * Exported Function Prototypes
 *******************************************************************************/
extern lcd_dll *lcd_new_dll(lcd_cmpfunc cmpfunc, malloc_fp_t alloc_fn_p,
                            free_fp_t free_fn_p);

extern kal_bool lcd_dll_is_empty(lcd_dll *dll);

extern kal_uint32 new_lcd_dll_mem_size(void);

extern lcd_dll_node *lcd_dll_insert_end(lcd_dll *dll, void *data);

extern kal_uint32 new_lcd_dll_node_mem_size(void);

extern lcd_dll_node *lcd_dll_delete_till(lcd_dll *dll, void *data);

extern kal_bool lcd_dll_delete_node(lcd_dll *dll, lcd_dll_node *del_node);

extern kal_bool lcd_dll_delete_node_fromhead(lcd_dll_node *dll_head, lcd_dll_node *del_node);

extern void lcd_delete_dll(lcd_dll *dll);

extern void lcd_dll_map(lcd_dll *dll, lcd_mapfunc f, void *info);

extern void lcd_dll_delete_all(lcd_dll *dll);

extern lcd_dll_node *lcd_dll_insert_end_with_mem(lcd_dll *dll, void *data,
                                                 void *mem_ptr);
#ifdef MTK_REMOVED_API
extern lcd_dll *lcd_new_dll_with_mem(lcd_cmpfunc cmpfunc, malloc_fp_t alloc_fn_p,
                                     free_fp_t free_fn_p, void *mem_ptr);

   #ifdef _DEBUG_LCD_DLL
extern void lcd_dll_print(lcd_dll *dll);
   #endif /* _DEBUG_LCD_DLL */
#endif /* MTK_REMOVED_API */
#endif /* _LCD_DLL_H */


