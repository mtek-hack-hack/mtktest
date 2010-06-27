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
 *	asn-list.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/
/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

/*
 * asn_list.h
 *
 *  ---------
 *  | AsnList |
 *  |  last |-------------------------------------------|
 *  |  curr |--------------------------|                |
 *  |  first|--------|                 |                |
 *  ---------        |                 |                |
 *                   V                 V                V
 *                ---------        ---------        ---------
 *                |AsnListNode       |AsnListNode       |AsnListNode
 *                | next  |---...->|  next |--...-->| next  |-----|i.
 *         .i|----| prev  |<--...--|  prev |<--...--| prev  |
 *                | data  |        |  data |        | data  |
 *                ---------        ---------        ---------
 *
 */

#ifndef _asn_list_h_
#define _asn_list_h_

#ifdef MTK_PEER 
#define IMP __declspec(dllimport) 
#else 
#define IMP 
#endif 

typedef struct AsnListNode
{
    struct AsnListNode	*prev;
    struct AsnListNode	*next;
    void		*data;		/* this must be the last field of this structure  */
} AsnListNode;

typedef struct AsnList
{
    AsnListNode		*first;
    AsnListNode		*last;
    AsnListNode		*curr;
    int			count;		/* number of elements in list               */
    int			dataSize;	/* space required in each node for the data */
} AsnList;

#define FOR_EACH_LIST_ELMT( elmt,  al)\
  if ((al) == 0)\
    ;\
  else\
    for ((al)->curr = (al)->first; ((al)->curr != NULL) && (((elmt) = (void *)(al)->curr->data) != NULL); (al)->curr = (al)->curr->next)

/* paul modify begin */
#define FOR_EACH_LIST_ELMT_RVS( elmt,  al)\
  if (!(al))\
    ;\
  else\
    for ((al)->curr = (al)->last; ((al)->curr != NULL) && (((elmt) = (void *)(al)->curr->data) != NULL); (al)->curr = (al)->curr->prev)
/*    for ((al)->curr = (al)->last; (al)->curr && ((elmt) = (void *)(al)->curr->data); (al)->curr = (al)->curr->prev)
 * paul modify end */

/* paul modify begin */
#define FOR_REST_LIST_ELMT( elmt,  al)\
  if (!(al))\
    ;\
  else\
    for (; ((al)->curr != NULL) && (((elmt) = (void *)(al)->curr->data) != NULL); (al)->curr = (al)->curr->next)
/*    for (; (al)->curr && ((elmt) = (void *)(al)->curr->data); (al)->curr = (al)->curr->next)
 * paul modify end */

/* paul modify begin */
#define FOR_REST_LIST_ELMT_RVS( elmt,  al)\
  if (!(al))\
    ;\
  else\
    for (; ((al)->curr != NULL) && (((elmt) = (void *)(al)->curr->data) != NULL); (al)->curr = (al)->curr->prev)
/*    for (; ((al)->curr && ((elmt) = (void *)(al)->curr->data); (al)->curr = (al)->curr->prev)
 * paul modify end */

#define LISTINIT( act_list, type) \
{\
        AsnListInit (&(act_list),sizeof(type));\
}

#define LISTAPPEND( act_list, elmt, type) \
{\
        (elmt) = (type **) AsnListAppend ((AsnList *) &(act_list));\
}


/*
 * The following macros return the pointer stored in the
 * data part of the listNode.  The do not change the current
 * list pointer.
 */
#define CURR_LIST_ELMT( al)			((al)->curr->data)
#define NEXT_LIST_ELMT( al)			((al)->curr->next->data)
#define PREV_LIST_ELMT( al)			((al)->curr->prev->data)
#define LAST_LIST_ELMT( al)			((al)->last->data)
#define FIRST_LIST_ELMT( al)			((al)->first->data)
#define LIST_EMPTY( al)				((al)->count == 0)
#define LIST_COUNT( al)				((al)->count)

/*
 * list nodes are the parts of the list that contain ptrs/data
 * to/of the list elmts.
 */
#define CURR_LIST_NODE( al)			((al)->curr)
#define FIRST_LIST_NODE( al)			((al)->first)
#define LAST_LIST_NODE( al)			((al)->last)
#define PREV_LIST_NODE( al)			((al)->curr->prev)
#define NEXT_LIST_NODE( al)			((al)->curr->next)
#define SET_CURR_LIST_NODE( al, listNode)	((al)->curr = (listNode))

void	AsnListRemove (AsnList *);
void	*AsnListAdd (AsnList *);
void	*AsnListInsert (AsnList *);
void	AsnListInit (AsnList *act_list, int dataSize);
AsnList	*AsnListNew (int);
void	*AsnListPrev (AsnList *);
void	*AsnListNext (AsnList *);
void	*AsnListLast (AsnList *);
void	*AsnListFirst (AsnList *);
void	*AsnListPrepend (AsnList *);
void	*AsnListAppend (AsnList *);
void	*AsnListCurr (AsnList *);
int	AsnListCount (AsnList *);
AsnList	*AsnListConcat (AsnList *, AsnList *);
long int GetAsnListElmtIndex (void *elmt,AsnList *act_list);
void	AsnListFree ( AsnList *);
void	AsnListFreeOnlyNodes ( AsnList *);
void	*GetAsnListElmt (AsnList *act_list, unsigned int index);

#endif /* conditional include */


