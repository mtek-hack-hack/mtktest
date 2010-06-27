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
 * ManageCallMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : Vandana Dhawan 

   DATE     : April 25,03

**************************************************************/

#ifndef _PIXTEL_MANAGECALLSMAIN_H
#define _PIXTEL_MANAGECALLSMAIN_H

extern void HighlightManageCalls(void);
extern void EntryCALLSETMain(void);
extern void EntryCALLSETCallTimeReminder(void);
extern void ExitCALLSETCallTimeReminder(void);
extern void EntryCALLSETCtrTime(void);
extern void ExitCALLSETCtrTime(void);

#if (0)
/* under construction !*/
#endif /* (0) */ 
extern void EntryCALLSETCUGMain(void);
extern void InitCallWaiting(void);
extern void InitCallForwarding(void);
extern void InitCallBarring(void);
extern void InitGroupListApp(void);
extern void InitLineSwitch(void);
extern void InitCallerId(void);
extern void HintCALLSETCallerID(U16);
extern void HintCALLSETLineSwitch(U16);
extern void HintCALLSETCallTimeReminder(U16);
extern void HintCALLSETCallTimeDisplay(U16);
extern void HintCALLSETAutoRedial(U16);

#ifdef __MMI_SS_SHOW_CAUSE__
typedef struct
{
    U16 cause_number;
    U8 cause_string[80];
} SSCauseDisplayStruct;
#endif /* __MMI_SS_SHOW_CAUSE__ */ 

/* IP number begin */

#ifdef __IP_NUMBER__
extern void InitIPNumber(void);
extern void HighlightIPNumber(void);
extern void LoadIPNumbers(void);
extern void EntryScrViewIPNumbers(void);
extern void SetCurIPNumberIndex(S32 index);
extern void EntryScrIPNumberOptions(void);
extern void HighlightIPNumActivate(void);
extern void HighlightIPNumEdit(void);
extern void ActivateIPNumber(void);
extern void EntryScrIPNumberEdit(void);
extern void SetIPNumber(void);
extern void GetCurrIPNumber(U8 *num_str);
extern S8 *GetCurrIPNumberUCS2(void);

#ifdef __MMI_DUAL_SIM_MASTER__
extern void HighlightCard2IPNumActivate(void);
extern void ActivateCard2IPNumber(void);
extern void GetCurrCard2IPNumber(U8 *num_str);
extern S8 *GetCurrCard2IPNumberUCS2(void);
#endif/* __MMI_DUAL_SIM_MASTER__*/

#endif /* __IP_NUMBER__ */ 
/* Start by Julia */
#ifdef __MMI_CM_BLACK_LIST__
extern void InitBlackList(void);
extern void HighlightBlackList(void);
extern void HighlightBlackListMode(void);
extern void HighlightBlackListNum(void);
extern void HintBlackList(U16 index);
extern void HintBlackListMode(U16 index);
extern void EntryScrBlackList(void);
extern void EntryScrBlackListMode(void);
extern void EntryScrBlackListNum(void);
extern void ExitScrBlackListNum(void);
extern void EntryScrSetBlackListNumConfirm(void);
extern void GoToBlackList(void);
extern void SetBlackListMode(pBOOL flag);
extern pBOOL GetBlackListMode(void);
extern void SetBlackListNum(void);
extern void LoadBlackListNum(void);
extern void SetCurrBlackListNumIndex(S32 index);
extern pBOOL IsBlackListNum(PU8 number);
#endif /* __MMI_CM_BLACK_LIST__ */ 
/* End by Julia */
#endif /* _PIXTEL_MANAGECALLSMAIN_H */ 

