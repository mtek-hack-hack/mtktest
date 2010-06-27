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
 * ShortcutsProts.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes of Shortcut application.
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

   FILENAME : ShortcutsProts.h

   PURPOSE     : Shortcuts application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : May 12,03

**************************************************************/
#ifndef _MMI_SHORTCUTSPROTS_H
#define _MMI_SHORTCUTSPROTS_H

#include "MMI_features.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__

#include "MMIDataType.h"
#include "FrameworkStruct.h"

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void EntryShctInIdle(void);
extern void EntryShctInMainMenu(void);
extern BOOL ATSetShortcuts(U8 *index);

extern void ShctGetCandidateList(void);
extern void ShctReadFromNvram(void);
extern void ShctWriteToNvram(void);
extern void HighlightShctSelShortcut(S32 index);
extern void ShctExecSelectedShortcut(void);

extern void ShortcutsMenuIndex(S32);
extern void EntryShctEditScreen(void);
extern void ExitEditShortcuts(void);
extern void HighlightShctEdit(S32 index);
extern void ShctSaveChanges(void);
extern void ShctMenuShortcut(S32 index);
extern U16 ShctGetStringID(U16 menu_id);

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
extern void ShctReadDedicatedListFromNVRAM(void);
extern void ShctWriteDedicatedListToNVRAM(void);
extern void EntryShctArrowKeyList(void);
extern void ExitDedicatedKeyScreen(void);
extern void HighlightDedicatedKeys(void);
extern void HighlightShctSelectedKey(S32 nIndex);
extern void HighlightDedicatedKeys(void);
extern void EntryShctEditDedicatedKey(void);
extern void ShctSaveDedicated(void);
extern void RegisterDedicatedKeyHandlers(void);
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 

#endif /* __DISABLE_SHORTCUTS_IMPL__ */ /* #ifndef __DISABLE_SHORTCUTS_IMPL__ */
#endif /* _MMI_SHORTCUTSPROTS_H */ 

