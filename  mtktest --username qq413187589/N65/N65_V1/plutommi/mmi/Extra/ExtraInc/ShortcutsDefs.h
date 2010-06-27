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
 * ShortcutsDefs.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant and enum value used in Shortcuts application.
 *
 * Author:
 * -------
 * -------
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
   * Nov 12 2005 mtk01215
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
/**************************************************************

   FILENAME : ShortcutsDefs.h

   PURPOSE     : Shortcuts application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : May 12,03

**************************************************************/
#ifndef _MMI_SHORTCUTSDEFS_H
#define _MMI_SHORTCUTSDEFS_H

#include "MMI_features.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__

#include "StdC.h"
#include "MMIDataType.h"
#include "FrameworkStruct.h"
#include "ShortcutsStruct.h"
#include "ShortcutsResDef.h"
/* 
 * Define
 */
#define  SHCT_MAX_ALIAS_TABLE    1
#define  SHCT_COUNT_BYTE         0
#define  SHCT_INTEGRITY_BYTE     1
#define  SHCT_DATA_BYTE          2
// #define      SHCT_MENUID_START                       SHCT_DATA_BYTE + SHCT_MAX_SEL_LIST
#define  ENABLE_STATE            1
#define  DISABLE_STATE           0

#define  SHCT_DEFAULT_MENU_ID    0
#define  SHCT_NVRAM_SIZE         250
#define  SHCT_MAX_LIST        30
#define  SHCT_MAX_CANDI_LIST     50
extern U8 shct_max_list_cand;
extern U8 shct_list_default;

#define SHCT_NEED_SIM 0x01
#define SHCT_NEED_PREFERRED_MODE_CHECK 0x02
#define SHCT_VALID_UNDER_FLIGHT_MODE    0x04
#define SHCT_INVALID_UNDER_NO_IDLE  0x40   //cannot be excuted if idlescreen is not present 

#if defined(__MMI_DUAL_SIM_MASTER__)
#define SHCT_NEED_SIM1 0x08
#define SHCT_NEED_SIM2 0x10
#define SHCT_VALID_UNDER_CLOSED_SIM 0x20
#endif /* __MMI_DUAL_SIM_MASTER__*/
/* 
 * Typedef 
 */

/* Option Ids */
typedef enum
{
    SHR_OPTIONS_ADD = 0,
    SHR_OPTIONS_EDIT,
    SHR_OPTIONS_DELETE,
    SHR_OPTIONS_DELETE_ALL,
    SHR_OPTIONS_ENABLE,
    SHR_OPTIONS_DISABLE,
    SHR_OPTIONS_CHANGE_ORDER,
    SHR_OPTIONS_TOTAL
} OPTION_ID_SHCT_ENUM;


#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
typedef enum
{
    DEDICATED_KEY_UP = 0,
    DEDICATED_KEY_DOWN,
    DEDICATED_KEY_LEFT,
    DEDICATED_KEY_RIGHT,
    TOTAL_DEDICATED_KEYS
} SHCT_DEDICATED_KEY_ENUM;
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 

typedef struct
{
    FuncPtr LSKFunc;
#ifdef __MMI_TOUCH_SCREEN__
    /* Always append one entry for Pen Calibration on display */
    shct_item_struct SelShctList[SHCT_MAX_LIST + 1];
    /* U8   SelShctState[SHCT_MAX_SEL_LIST+1]; */
#else /* __MMI_TOUCH_SCREEN__ */ 
    shct_item_struct SelShctList[SHCT_MAX_LIST];
    /* U8   SelShctState[SHCT_MAX_SEL_LIST]; */
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* 6    SelShctEnableList[SHCT_MAX_SEL_LIST+1]; */
    U16 CandShctList[SHCT_MAX_CANDI_LIST];
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    U16 DediShctList[TOTAL_DEDICATED_KEYS];
    U8 CurrSelArrow;
    U8 IsKeyRetrieving;
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 
    U8 NumCandShct;     /* number of candidate shortcut */
    U8 NumSelShct;      /* number of selected shortcut */
    U8 CurrSelShct;     /* current selected shortcut from shortcut list */
    U8 CurrEditShct;    /* current selected shortcut from candidate list */
    U8 CurrOptionShct;  /* current selected option item */
    U8 Integrity;
    S32 Order;          /* order of selected item */
    /* displayItemNum; */
} shct_context_struct;

/*
 * Extern Global Variable
 */
extern shct_context_struct g_shct_cntx;

/* 
 * Extern Global Function
 */
#endif /* __DISABLE_SHORTCUTS_IMPL__ */ /* #ifndef __DISABLE_SHORTCUTS_IMPL__ */
#endif /* _MMI_SHORTCUTSDEFS_H */ 

