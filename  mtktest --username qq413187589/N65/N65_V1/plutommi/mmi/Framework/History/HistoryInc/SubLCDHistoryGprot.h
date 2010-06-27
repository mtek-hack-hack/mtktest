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
 * SubLCDHistoryGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SubLCD History prototype.
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

#ifndef _PIXCOM_SUBLCDHISTORYGPROT_H
#define _PIXCOM_SUBLCDHISTORYGPROT_H

#include "FrameworkStruct.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* redefine the function name */
#define  GetCurrSubLCDScreenFunc    GetCurrSubLCDScreenExitFunc

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void ExecSubLCDCurrExitHandler(void);
extern void AddSubLCDHistory(SubLCDHistoryNode *CurrSubLCDHistory);
extern void AddSubLCDHistoryWithScrID(SubLCDHistoryNode *CurrSubLCDHistory, U16 scrID);
extern void AddSubLCDHistoryWithScrIDEx(SubLCDHistoryNodeEx *CurrSubLCDHistory, U16 scrID);
extern void SetSubLCDExitHandler(FuncPtr);
extern void SetSubLCDEntryHandler(FuncPtr);

extern void InitSubLCDHistory(SubLcdHistoryCBPtr sublcdrootscreen);
extern void DinitSubLCDHistory(void);
extern void ShowSubLCDScreen(FuncPtr);
extern void ForceSubLCDScreen(FuncPtr SubLCDEntryFn);
extern void DisplaySubLCDScreen(U16 scrnId, FuncPtr SubLCDEntryFn, MMI_BOOL is_force);

//PMT START NEERAJ 20051111
//extern void ForceSubLCDScreen_old(FuncPtr SubLCDEntryFn);//102805 Calvin: temp solution
//PMT END NEERAJ 20051111

extern void GoBackSubLCDHistory(void);
extern void GoBacknSubLCDHistory(U16 nHistory);
extern U8 GoBackToSubLCDHistory(U16 scrnid);
extern U8 GoBeyondSubLCDMarkerScr(U16 scrnid);
extern void GoBackBothLCDHistory(void);

extern U8 DeleteUptoSubLCDScrID(U16 scrnid);
extern U8 DeleteNSubLCDScrId(U16 scrnid);
extern U16 DeleteSubLCDScreen(U16 ScrId);

extern void DeleteNSubLCDHistory(U16 DeleteCount);
extern U8 DeleteBeyondSubLCDScrTillScr(U16 beyondScrnid, U16 tillScrnid);       /* *********************** */
extern U16 DeleteBetweenSubLCDScreen(U16 StartScrId, U16 EndScrId);

extern pBOOL SubLCDHistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);

extern pBOOL IsSubLCDHistoryBack(void);

extern pBOOL IsSubLCDScreenPresent(U16 scrnId);

extern FuncPtr GetCurrSubLCDScreenExitFunc(void);
extern FuncPtr GetCurrSubLCDScreenEntryFunc(void);

extern S16 GetSubLCDScreenCountInHistory(void);

extern U8 GetSubLCDHistory(U16 scrnID, SubLCDHistoryNodeEx *ptrHistory);
extern U8 *GetCurrSubLCDGuiBuffer(U16 scrnid);
extern pBOOL GetPreviousSubLCDScrnIdOf(U16 scrnId, U16 *previousScrnId);
extern pBOOL GetNextSubLCDScrnIdOf(U16 scrnId, U16 *nextScrnId);
extern U16 GetSubLCActiveScreenId(void);
extern U16 GetSubLCDExitScrnId(void);
extern U16 GetSubLCDScrnId(U16 index);
extern void SubLCDHistoryDump(void);

#ifdef __MMI_SUBLCD_MASTER_MODE__
extern void SwitchSubLCDHistory(void);
extern void ClearSubLCDMasterHistory(void);
extern BOOL IsSubLCDMasterHistoryEmpty(void);
extern S16 GetScreenCountInSubLCDMasterModeHistory(void);
extern void ForceExitCurrScr(void);
extern void SetCurrSubLCDUpdateBySubLCDApp(MMI_BOOL enable);
extern MMI_BOOL GetCurrSubLCDUpdateBySubLCDApp(void);

#endif /* __MMI_SUBLCD_MASTER_MODE__ */ 

#endif /* _PIXCOM_SUBLCDHISTORYGPROT_H */ 

