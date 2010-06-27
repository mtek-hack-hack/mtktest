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
 * ComposeRingToneProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines prototypes for Ring Tone Composer application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
                                                                                  *******************************************************************************//**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : ComposeRingToneProts.h

   PURPOSE     : Prototypes Funtions for the ComposeRingTone Application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : July-28-2003

**************************************************************/
#ifndef _MMI_COMPRINGTONEPROTOS_H
#define _MMI_COMPRINGTONEPROTOS_H
#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#include "DownloadDefs.h"
/* if some header should be include before this one */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void InitRingToneComposer(void);

/* these two functions is still using by other app. */
extern S8 *GetComposedIMelodyNameInFileSystem(U16 AudioId);
extern U8 GetComposedIMelodyInfo(DYNAUDIOINFO **downloadAudioInfo);

extern void HighlightRngcMenu(void);
extern void EntryRngcApp(void);
extern void HighlightRngcCompTone(S32 nIndex);
extern void EntryRngcMainMenuOptList(void);
extern void SetRingToneFilenameBuf(void);
extern void EntryRngcDeleteToneConfirm(void);
extern void DeleteCompRingTone(void);
extern void EntryRngcPlayTone(void);
extern void ExitRngcPlayTone(void);
extern void EntryRngcCompToneOptList(void);
extern void HighlightRngcCompToneOpt(S32 nIndex);

extern void RngcGotoSelectedCompToneOpt(void);
extern void EntryRngcPlaySpeed(void);
extern void HighlightRngcGenericOptHdlr(S32 nIndex);
extern void SetCurrCompRingToneSpeed(void);
extern U8 GetIndexCurrCompRingToneSpeed(void);
extern void EntryRngcInstrument(void);
extern U8 GetCurrIndexCompRingToneInst(void);
extern void SetCurrCompRingToneInstrument(void);
extern void EntryRngcEditFileName(void);
extern void GetCompRingToneSaveOpt(S32 nIndex);
extern void RngcDisplayPopupAfterSave(void);
extern void EntryRngcEditFilenameOptList(void);
extern S32 SetSaveCompRingTone(void);
extern void RngcGotoEditFinenameOpt(void);
extern void GoBacknHistoryFromInputMethod(void);
extern U8 IsCompToneExisted(PS8 filename);

extern void ExecCurrEndKeyDownHandler(void);
extern void GetCurrEndKeyDownHandler(void);
extern void EntryInputMethodScreen(void);
extern void RegisterInputMethodScreenCloseFunction(void (*f) (void));

extern void EntryRngcComposerEngine(void);
extern void RngcExecAdd(void);

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)

#endif /* _MMI_COMPRINGTONEPROTOS_H */ // #ifndef _MMI_COMPRINGTONEPROTOS_H

