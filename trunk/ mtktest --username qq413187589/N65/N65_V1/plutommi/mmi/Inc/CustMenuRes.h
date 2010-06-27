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
 *  CustMenuRes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**********************************************************************************
   FILENAME : CustMenuRes.h

   PURPOSE     : To define Common Structures used by the UI Elements and Cutomization Tool 
              for Customizing Menus(MenuItem).

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
**********************************************************************************/

#ifndef _PIXCOM_CUSTMENURES_H
#define _PIXCOM_CUSTMENURES_H

#include "MMIDataType.h"
#include "GlobalMenuItems.h"
/* neerajm5 */
#ifdef __MOD_SMSAL__
// #define MAX_MENU_ITEMS       500
#else 
// #define MAX_MENU_ITEMS       200
#endif 
#define MENU_ITEM_SIZE  50
#define MAX_HILITE_HANDLER    MAX_MENU_ITEMS

typedef enum
{
    LIST_MENU = 1,
    MATRIX_MENU,
    CIRCULAR_3D_MENU,
    PAGE_MENU,
    ANI_BG_LIST_MENU,
    MATRIX_MENU_EMS,
    ROTATE_MENU,
    LIST_MATRIX_MENU
} MMI_MENU_TYPES;

/* The Below is the structure of the MenuItem which can be transfered to any screen. */
typedef struct Custom_MenuItem
{
    U16 nMenuItemId;    /* Unique Id for each MenuItem. */
    U16 nParentId;      /* ItemId of the parent if 0(zero) then no parent. */
    U16 nNumofMenuItem; /* Number of Children it has. */
    U16 nHideFlag;      /* This is a flag to mask/hide.(not sure currently) */
    U16 nMovable;       /* This is a flag for moving like 0-NotMovable Anywhere, */
    /* 1-Movable within the same parent..etc */

    U16 nDispAttribute;     /* This is a display attribute flag like 1-list,2-Circular,3-Tab..etc. */
    U16 nStrId;             /* Unique StringId of the MenuItem. */
    U16 nImageId;           /* Unique Image of the MenuItem. */
    U16 *nOrderMenuItemId;  /* ItemId of the children in Sequence */
} CUSTOM_MENU;

/* The below function gets the ParentId of the ItemId. */
extern U16 GetParentItemId(U16 ItemId);

/* The below function gets the Number of Child of the ItemId. */
extern U16 GetNumOfChild(U16 ItemId);

/* The below function gets the StringId of the ItemId. */
extern U16 GetStringIdOfItem(U16 ItemId);

/* The below function gets the ImageId of the ItemId. */
extern U16 GetImageIdOfItem(U16 ItemId);

/* The below function gets the Display Attribute of the ItemId. */
extern U16 GetDispAttributeOfItem(U16 ItemId);

/* The below function gets the ItemId,StringId,ImageId of the given SeqId & ItemId(Parent). */
extern U16 GetSeqItemId(U16 ParentItemId, U16 Seq);
extern U16 GetSeqItemStringId(U16 ParentItemId, U16 Seq);
extern U16 GetSeqItemImageId(U16 ParentItemId, U16 Seq);

/* The below functions gets the ItemIds,StringIds,ImageIds in sequence of the ItemId(Parent). */
extern void GetSequenceItemIds(U16 ParentItemId, U16 *ItemIds);
extern void GetSequenceStringIds(U16 ParentItemId, U16 *StringIds);
extern void GetSequenceImageIds(U16 ParentItemId, U16 *ImageIds);
extern U8 GetIndexOfStringId(U16 ParentItemId, U16 StringId);

extern S16 GetChildIndex(U16 nChildId, U16 nParentId);

/* The below functions conders the hidden menuitems */
extern U16 GetNumOfChild_Ext(U16 menu_item_id);
extern U16 GetSeqItemId_Ext(U16 parent_item_id, U16 index);
extern U16 GetSeqItemStringId_Ext(U16 parent_item_id, U16 index);
extern U16 GetSeqItemImageId_Ext(U16 parent_item_id, U16 index);
extern U16 GetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds);
extern U16 GetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds);
extern U16 GetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds);
extern U8 GetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId);

extern void mmi_frm_hide_menu_item(U16 menu_item_id);
extern void mmi_frm_unhide_menu_item(U16 menu_item_id);

#endif /* _PIXCOM_CUSTMENURES_H */ 

