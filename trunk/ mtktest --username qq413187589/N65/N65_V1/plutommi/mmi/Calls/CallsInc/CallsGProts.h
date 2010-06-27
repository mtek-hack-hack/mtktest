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
 * CallsGProts.h
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

   FILENAME : CallsGProts.h

   PURPOSE     : Call application Global Prototypes

   REMARKS     : nil

   AUTHOR      : Tarun

   DATE     : Oct 4,02

**************************************************************/
#ifndef _PIXTEL_CALLGPROT_H
#define _PIXTEL_CALLGPROT_H

#include "PhoneBookTypes.h"
#include "CallsDefs.h"
#include "CallsStruct.h"

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"

extern void mmi_chist_log_voip_dialed_call(mmi_voip_call_log_struct *call);
extern void mmi_chist_log_voip_missed_call(mmi_voip_call_log_struct *call);
extern void mmi_chist_log_voip_received_call(mmi_voip_call_log_struct *call);
extern void mmi_chist_log_voip_call_duration(mmi_voip_call_log_struct *call, kal_uint8 type);
#endif /* __MMI_VOIP__ */


extern void CHISTGetCallLogName(LOG_CALL *item);
extern void CHISTSetDialFromCallLogFlag(U8 flag);
extern U8 CHISTGetDialFromCallLogFlag(void);

extern void CHISTLogDialedCall(CALL_INFO *call);
extern void CHISTLogDialedCallDuration(CALL_INFO *call);
extern void CHISTLogMissedCall(CALL_INFO *call);
extern void CHISTLogRecvdCall(CALL_INFO *call);
extern void CHISTLogRecvdCallDuration(CALL_INFO *call);
extern void mmi_chist_delete_miss_call_notify_screen(void);

extern U16 CHISTGetQuickEndTime(void);

extern void mmi_chist_set_processing_flag(U8 state);
extern const U8 mmi_chist_get_processing_flag(void);
extern void mmi_chist_set_sentreq_flag(BOOL state);
extern const BOOL mmi_chist_get_sentreq_flag(void);
extern void mmi_chist_set_missed_call_flag(U8 has_missed_call);
extern const U8 mmi_chist_get_missed_call_flag(void);
#endif /* _PIXTEL_CALLGPROT_H */ 

