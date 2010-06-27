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
 * CallHistoryMain.h
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
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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

   FILENAME : Callorwarding.h

   PURPOSE     : Call application

   REMARKS     : nil

   AUTHOR      : Vandana Dhawan

   DATE     : 29th April 2003

**************************************************************/

#ifndef _PIXTEL_CALLHISTORYMAIN_H
#define _PIXTEL_CALLHISTORYMAIN_H

extern void InitCallHistory(void);
extern void InitCallHistoryContext(void);
extern void InitCallLogs(void);
extern void InitCallCost(void);
extern void InitCallsReset(void);
extern void InitSMSCounter(void);
extern void InitCallTimes(void);

extern void EntryCHISTMainMenu(void);
extern void ExitCHISTMainMenu(void);

extern void CHISTResetCallLogIndex(void);

#ifdef __MMI_GPRS_FEATURES__
extern void InitGPRSCounter(void);
extern void HighlightGPRSCount(void);
extern void HighlightGPRSCountLastSent(void);
extern void HighlightGPRSCountLastRecieved(void);
extern void HighlightGPRSCountAllSent(void);
extern void HighlightGPRSCountAllReceived(void);
extern void HighlightGPRSCountCounterReset(void);
extern void HintGPRSCountLastSent(U16);
extern void HintGPRSCountLastRecieved(U16);
extern void HintGPRSCountAllSent(U16);
extern void HintGPRSCountAllReceived(U16);
extern void GetGPRSCountersRequest(void);
extern void GetGPRSCountersResponse(void *info);
extern void EntryScrGPRSRecvCounterResetConfirmation(void);
extern void ExitScrGPRSRecvCounterResetConfirmation(void);
extern void ResetGPRSCounterReq(void);
extern void ResetGPRSCounterRsp(void *info);
extern void EntryScrGPRSCounter(void);
extern void ExitGPRSCounter(void);
#endif /* __MMI_GPRS_FEATURES__ */ 

#endif /* _PIXTEL_CALLHISTORYMAIN_H */ 

