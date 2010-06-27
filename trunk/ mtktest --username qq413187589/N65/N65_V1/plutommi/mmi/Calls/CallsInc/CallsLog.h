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
 * CallsLog.h
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

   FILENAME : Calls_GProts.h

   PURPOSE     : Call application Global Prototypes

   REMARKS     : nil

   AUTHOR      : Tarun

   DATE     : Oct 4,02

**************************************************************/
#ifndef _PIXTEL_CALLSLOG_H
#define _PIXTEL_CALLSLOG_H

extern void HighlightCHISTDialedCalls(void);
extern void HighlightCHISTMissedCalls(void);
extern void HighlightCHISTRecvdCalls(void);

extern void HighlightCHISTCallDialedNum(void);
extern void HighlightCHISTSaveDialedNum(void);
extern void HighlightCHISTDeleteDialedNum(void);
extern void HighlightCHISTEditDialedNum(void);

extern void HighlightCHISTCallMissedNum(void);
extern void HighlightCHISTSaveMissedNum(void);
extern void HighlightCHISTDeleteMissedNum(void);
extern void HighlightCHISTEditMissedNum(void);

extern void HighlightCHISTCallRecvdNum(void);
extern void HighlightCHISTSaveRecvdNum(void);
extern void HighlightCHISTDeleteRecvdNum(void);
extern void HighlightCHISTEditRecvdNum(void);

#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
extern void HighlightCHISTInfoDialedNum(void);
extern void HighlightCHISTInfoMissedNum(void);
extern void HighlightCHISTInfoRecvdNum(void);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 

#ifdef __MMI_CH_OPTIONS_SENDSMS__
extern void HighlightCHISTSendSMSDialedNum(void);
extern void HighlightCHISTSendSMSRecvdNum(void);
extern void HighlightCHISTSendSMSMissedNum(void);
extern void CHISTSendSMSDialedNum(void);
extern void CHISTSendSMSMissedNum(void);
extern void CHISTSendSMSRecvdNum(void);
#endif /* def __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
extern void HighlightCHISTSendMMSDialedNum(void);
extern void HighlightCHISTSendMMSRecvdNum(void);
extern void HighlightCHISTSendMMSMissedNum(void);
extern void CHISTSendMMSDialedNum(void);
extern void CHISTSendMMSMissedNum(void);
extern void CHISTSendMMSRecvdNum(void);
#endif /* def __MMI_CH_OPTIONS_SENDMMS__ */

extern void HintCHISTDialedCalls(U16 index);
extern void HintCHISTMissedCalls(U16 index);
extern void HintCHISTRecvdCalls(U16 index);

extern void EntryCHISTViewDialedCallList(void);
extern void ExitCHISTViewDialedCallList(void);
extern void EntryCHISTViewDialedCall(void);
extern void ExitCHISTViewDialedCall(void);
extern void EntryCHISTDialedListOptions(void);
extern void ExitCHISTDialedListOptions(void);
extern void EntryCHISTDeleteDialedCallConfirm(void);
extern void ExitCHISTDeleteDialedCallConfirm(void);

extern void EntryCHISTViewMissedCallList(void);
extern void ExitCHISTViewMissedCallList(void);
extern void EntryCHISTViewMissedCall(void);
extern void ExitCHISTViewMissedCall(void);
extern void EntryCHISTMissedListOptions(void);
extern void ExitCHISTMissedListOptions(void);
extern void EntryCHISTDeleteMissedCallConfirm(void);
extern void ExitCHISTDeleteMissedCallConfirm(void);
extern void EntrySubCHISTNotifyMissedCall(void);
extern void ExitSubCHISTNotifyMissedCall(void);

extern void EntryCHISTViewRecvdCallList(void);
extern void ExitCHISTViewRecvdCallList(void);
extern void EntryCHISTViewRecvdCall(void);
extern void ExitCHISTViewRecvdCall(void);
extern void EntryCHISTRecvdListOptions(void);
extern void ExitCHISTRecvdListOptions(void);
extern void EntryCHISTDeleteRecvdCallConfirm(void);
extern void ExitCHISTDeleteRecvdCallConfirm(void);

extern void CHISTAnimationTimeOutHdlr(void);
extern void ExitCHISTProcessingAnimation(void);

extern void ReqReadDialedNumByKey(void);
extern void ReqReadDialedNum(void);
extern void RspReadDialedNum(void *info);
extern void ReqWriteCallLog(CALL_INFO *dailCall, U8 type);
extern void RspWriteDialedNum(void *info);
extern void ReqDeleteCallLog(U8 type, U8 index, U8 no_data);
extern void RspDeleteDialedNum(void *info);

extern void ReqReadMissedNumByKey(void);
extern void ReqReadMissedNum(void);
extern void RspReadMissedNum(void *info);
extern void RspWriteMissedNum(void *info);
extern void RspDeleteMissedNum(void *info);

extern void ReqReadRecvdNumByKey(void);
extern void ReqReadRecvdNum(void);
extern void RspReadRecvdNum(void *info);
extern void RspWriteRecvdNum(void *info);
extern void RspDeleteRecvdNum(void *info);

extern void RspWriteNum(void *info);

extern void mmi_chist_init_get_data_from_nvram(void);
extern void mmi_chist_set_have_missed_call(void);
extern void ReadyLogIndication(void *info);

#ifdef __IP_NUMBER__
extern void CHISTCallDialedNumByIP(void);
extern void CHISTCallMissedNumByIP(void);
extern void CHISTCallRecvdNumByIP(void);
#endif /* __IP_NUMBER__ */ 

extern void CHISTDeleteDialedNum(void);
extern void CHISTSaveDialedNum(void);
extern void CHISTCallDialedNum(void);
extern void mmi_chist_call_dialed_num_cbk(void *p);
extern void CHISTEditDialedNum(void);

extern void CHISTDeleteMissedNum(void);
extern void CHISTSaveMissedNum(void);
extern void CHISTCallMissedNum(void);
extern void mmi_chist_call_missed_num_cbk(void *p);
extern void CHISTEditMissedNum(void);

extern void CHISTDeleteRecvdNum(void);
extern void CHISTSaveRecvdNum(void);
extern void CHISTCallRecvdNum(void);
extern void mmi_chist_call_recvd_num_cbk(void *p);
extern void CHISTEditRecvdNum(void);

extern void CHISTPopulateDialedCallList(U8 *numberList[], U8 *phoneList[]);
extern void CHISTPopulateMissedCallList(U8 *numberList[], U8 *phoneList[]);
extern void CHISTPopulateRecvdCallList(U8 *numberList[], U8 *phoneList[]);

extern void CHISTGetCurrDialedCallIndex(S32 ind);
extern void CHISTGetCurrMissedCallIndex(S32 ind);
extern void CHISTGetCurrRecvdCallIndex(S32 ind);

extern void CHISTExtractPSCallLog(LOG_CALL *logCall, PHB_LN_ENTRY *phbLastNumber);

#ifdef __MMI_CH_MIXED_CALL_LOG__
extern void EntryCHISTViewMixedCallList(void);
extern void ExitCHISTViewMixedCallList(void);

/* Start by Julia */
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
extern void EntryCHISTMixedListOptions(void);
#else 
extern void EntryCHISTViewMixedCall(void);
#endif 
/* End by Julia */
extern void CHISTCallMixedNum(void);
extern void mmi_chist_call_mixed_num_cbk(void *p);

#ifdef __IP_NUMBER__
extern void CHISTCallMixedNumByIP(void);
#endif 
extern void CHISTPopulateMixedCallList(U8 *numberList[], U8 *phoneList[]);
extern void CHISTGetCurrMixedCallIndex(S32 ind);
extern void CHISTSortCallLogsByTime(void);
extern BOOL CHISTIsDuplicatedNumber(U8 index);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
extern void CHISTCallVTDialedNum(void);
extern void CHISTCallVTMissedNum(void);
extern void CHISTCallVTRecvdNum(void);
extern void CHISTCallVTMixedNum(void);
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

extern void CHISTIgnoreMissedCallScreen(void);
extern void CHISTReadMissedNum(void);
extern void ConvertRTC2MYTIME(MYTIME *time, CALL_LOG_RTCTIMEFORMAT *rtc);
extern void ConvertMYTIME2RTC(CALL_LOG_RTCTIMEFORMAT *rtc, MYTIME *time);

#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
extern void CHISTDeleteTabPaneScreen(void);
#endif

#endif /* _PIXTEL_CALLSLOG_H */ 

