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
 *   lcd_ip_cqueue.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines Generic circular queue data structure definition
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
/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _LCD_IP_CQUEUE_H
#define _LCD_IP_CQUEUE_H

/*************************************************************************
 * Macros With Parameters
 *************************************************************************/

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE
*
* DESCRIPTION
*
* PARAMETERS
*  _type is the type of item to be put in queue.
* _length is the size of the queue.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE(_type, _length)                                \
    struct {                                                         \
        unsigned int    head;                                        \
        unsigned int    tail;                                        \
        kal_bool        is_full;                                     \
        _type           queue[_length];                              \
    }

#else

#define LCD_IP_CQUEUE(_type, _length)                                \
    struct {                                                         \
        unsigned int    head;                                        \
        unsigned int    tail;                                        \
        unsigned int    multiple;                                    \
        unsigned int    max_used_item;                               \
        kal_bool        is_full;                                     \
        _type           queue[_length];                              \
    }
    
#endif

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE_INIT
*
* DESCRIPTION
*
* PARAMETERS
*  _q is the structure variable of the queue
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE_INIT(_q)                                       \
{                                                                    \
    _q.head = _q.tail = 0;                                           \
    _q.is_full = KAL_FALSE;                                          \
}

#else

#define LCD_IP_CQUEUE_INIT(_q)                                       \
{                                                                    \
    _q.head = _q.tail = 0;                                           \
    _q.multiple = 1;                                                 \
    _q.max_used_item = 0;                                            \
    _q.is_full = KAL_FALSE;                                          \
}

#define LCD_IP_CQUEUE_INIT_N(_q, n)                                  \
{                                                                    \
    _q.head = _q.tail = 0;                                           \
    _q.multiple = n;                                                 \
    _q.max_used_item = 0;                                            \
    _q.is_full = KAL_FALSE;                                          \
}

#endif

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE_INSERT
*
* DESCRIPTION
*
* PARAMETERS
*  _q is the structure variable of the queue
*  _item is the item to be inserted  to the queue
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE_INSERT(_q, _item)                              \
{                                                                    \
    _q.queue[_q.tail] = _item;                                       \
    _q.tail = (_q.tail + 1) % (sizeof(_q.queue)/sizeof(_q.queue[0]));\
    if (_q.head == _q.tail) { _q.is_full = KAL_TRUE; }               \
}

#else

#define LCD_IP_CQUEUE_INSERT(_q, _item)                              \
{                                                                    \
    _q.queue[_q.tail] = _item;                                       \
    _q.tail = (_q.tail + 1) % (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0]));\
    if (_q.head == _q.tail) { _q.is_full = KAL_TRUE; }               \
}

#endif

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE_REMOVE
*
* DESCRIPTION
*
* PARAMETERS
*  _q is the structure variable of the queue
*  _item is the variable to which removed item is stored
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE_REMOVE(_q, _item)                              \
{                                                                    \
    _item = _q.queue[_q.head];                                       \
    _q.head = (_q.head + 1) % (sizeof(_q.queue)/sizeof(_q.queue[0]));\
   if (_q.is_full == KAL_TRUE)                               \
      _q.is_full = KAL_FALSE;                                      \
}

#else

#define LCD_IP_CQUEUE_REMOVE(_q, _item)                              \
{                                                                    \
    _item = _q.queue[_q.head];                                       \
    _q.head = (_q.head + 1) % (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0]));\
   if (_q.is_full == KAL_TRUE)                               \
      _q.is_full = KAL_FALSE;                                      \
}

#endif

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE_NUM_OF_ITEMS
*
* DESCRIPTION
*
* PARAMETERS
* _q is the structure variable of the queue
* _num_of_items is the variable to which the
* number of items in the queue is assigned
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE_NUM_OF_ITEMS(_q,_num_of_items)                 \
{                                                                    \
    _num_of_items = _q.is_full ?                                     \
        (sizeof(_q.queue)/sizeof(_q.queue[0])) :                     \
        (_q.tail + (sizeof(_q.queue)/sizeof(_q.queue[0])) - _q.head) \
        % (sizeof(_q.queue)/sizeof(_q.queue[0]));                    \
}

#else

#define LCD_IP_CQUEUE_NUM_OF_ITEMS(_q,_num_of_items)                 \
{                                                                    \
    _num_of_items = _q.is_full ?                                     \
        (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0])) :                     \
        (_q.tail + (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0])) - _q.head) \
        % (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0]));                    \
}

#endif

/*************************************************************************
* FUNCTION
*  LCD_IP_CQUEUE_INDEX
*
* DESCRIPTION
*
* PARAMETERS
* _q is the structure variable of the queue
* _index is the index position of the queue from which queue item to be accessed
* _item is the variable to which element at index is stored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __ROMSA_SUPPORT__

#define LCD_IP_CQUEUE_INDEX(_q,_index,_item)                         \
{                                                                    \
 _item = _q.queue[(_q.head + _index) %                               \
                            (sizeof(_q.queue)/sizeof(_q.queue[0]))]; \
}

#else

#define LCD_IP_CQUEUE_INDEX(_q,_index,_item)                         \
{                                                                    \
 _item = _q.queue[(_q.head + _index) %                               \
                            (sizeof(_q.queue)*_q.multiple/sizeof(_q.queue[0]))]; \
}

#endif

//#ifndef __ROMSA_SUPPORT__
#define LCD_UP_CQUEUE_UPDATE_MAX(_q, _max)   \
{                                            \
   LCD_IP_CQUEUE_NUM_OF_ITEMS(_q, _max)      \
   if (_max > _q.max_used_item)              \
   {                                         \
      _q.max_used_item = _max;               \
   }                                         \
   else if (_max < _q.max_used_item)         \
   {                                         \
      _max = _q.max_used_item;               \
   }                                         \
}

/* _q is the structure variable of the queue */
#define LCD_IP_CQUEUE_IS_FULL(_q)  (_q.is_full)
#define LCD_IP_CQUEUE_IS_EMPTY(_q) ((_q.head == _q.tail) && !_q.is_full)

#endif /* _LCD_IP_CQUEUE_H */


