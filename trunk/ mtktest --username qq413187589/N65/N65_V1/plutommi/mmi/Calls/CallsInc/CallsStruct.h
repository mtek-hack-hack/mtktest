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
 * CallsStruct.h
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

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : PixTel

   DATE     : Jan 15,02

**************************************************************/

#ifndef _PIXCOM_CALLSTRUCT_H
#define _PIXCOM_CALLSTRUCT_H

#include "CallsDefs.h"
/* MTK Leo add 20040321, for new simulator */
#include "l4c_common_enum.h"
/* MTK Leo end */

#define CALL_LOG_NUMBER_STRUCT   l4c_number_struct
#define CALL_LOG_NAME_STRUCT     l4_name_struct

typedef struct
{
    U8 numType;
    U8 numLength;
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    U8 number[(VOIP_URI_LEN) *ENCODING_LENGTH];
    U8 address_type;
#else
    U8 number[(MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH];
#endif /* __MMI_VOIP__ */
    U8 nameLength;
    U8 nameDCS;
    S8 pbName[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    MYTIME startTime;
    MYTIME duration;
    U16 no_of_times;
} LOG_CALL;

typedef LOG_CALL RECEIVED_CALL;
typedef LOG_CALL DIALED_CALL;
typedef LOG_CALL MISSED_CALL;

typedef struct
{
    U8 curCallLogType;
    U8 currDialedCallIndex;
    U8 currMissedCallIndex;
    U8 currRecvdCallIndex;
    U8 nDialedCalls;
    U8 nMissedCalls;
    U8 nRecvdCalls;
    U8 nMissedCallBeforeView;
    U8 dialFromCallLog;
    U8 process;
    U8 sequenceId;
    BOOL isFirstTime;
    BOOL isDeleteAll;
    BOOL isCallLogReady;
    BOOL isReqSent;
    BOOL saveMissedScrn;
#ifdef __MMI_CH_MIXED_CALL_LOG__
    U8 currMixedCallIndex;
    U8 nMixedCalls;
    BOOL isMixedStyle;
    LOG_CALL dialedCalls[TOT_SIZE_OF_DIALED_LIST];
    LOG_CALL missedCalls[TOT_SIZE_OF_MISSED_LIST];
    LOG_CALL recvdCalls[TOT_SIZE_OF_RECVD_LIST];
    LOG_CALL *mixedCalls[TOT_SIZE_OF_MIXED_LIST];
#else /* __MMI_CH_MIXED_CALL_LOG__ */ 
    LOG_CALL *dialedCalls;
    LOG_CALL *missedCalls;
    LOG_CALL *recvdCalls;
    LOG_CALL callsLog[TOT_SIZE_OF_CALLS_LIST];
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

    U16 nSendSMSCount;
    U16 nRecvSMSCount;

    U8 currCostIndex;
    U16 currCostItem;
    U16 nQuickEndTime;
    S32 nQuickEndFlag;
    U32 lastCallCost;
    U32 allCallCost;
    U32 maxCallCost;
    U8 newMaxCostStr[10 *ENCODING_LENGTH];  /* for edit max cost */

    double ppu;                         /* hold PS return ppu */
    U8 PPUStr[20 *ENCODING_LENGTH];     /* hold PS return currency */
    U8 newPPUStr[20 *ENCODING_LENGTH];  /* for edit currency */

    U8 currencyStr[4 *ENCODING_LENGTH];     /* hold PS return currency */
    U8 newCurrencyStr[4 *ENCODING_LENGTH];  /* for edit currency */

    MYTIME total_out_time;
    MYTIME total_in_time;
    MYTIME last_call_time;

} call_history_context_struct;

extern call_history_context_struct *chis_p;

#endif /* _PIXCOM_CALLSTRUCT_H */ 

