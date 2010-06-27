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
 *  ATHandlerProt.h
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
   Filename:      ATHandlerProt.h
   Author:        Gautam
   Date Created:  
   Contains:   AT comamnd handler
**********************************************************************************/
#ifndef __ATPROT_H
#define __ATPROT_H
#include "MMIDataType.h"

extern void ATSetVolume(void *msg);
extern void ATSimulateKeyBoard(void *msg);
extern void ATTextOnLCD(void *msg);
extern void AtShowStatusIcon(void *msg);
extern void ATSetAlarm(void *msg);
extern void ATCancelAlarm(void *msg);
extern void ATSetRTC(void *msg);
extern void ATQueryAlarm(void *msg);
extern void AtSetGreetingTextHdlr(void *msg);
extern void ATMakeOutgoingCall(void *msg);
extern void ATAnswerIncomingCall(void *msg);
extern void ATHangupCall(void *msg);
extern void ATSyncCallTable(void *msg);
extern void ATTextOnLCDExit(void);
extern void ATSetDateTime(void *msg);
extern void ATSetMute(void *msg);
extern void ATSetSilentMode(void *msg);
extern void ATSetVibrationMode(void *msg);
extern void ATSetDateandTimeFormat(void *msg);
extern void ATSetLanguage(void *msg);
extern void SendLangChange2AT(U8 lang);

extern void AtQueryGreetingTextIndHdlr(void *msg);
extern void AtQueryLangIndHdlr(void *msg);
extern void ATSetProfileHandler(void *msg);
extern void AtQuerySilentModeIndHdlr(void *msg);
extern void AtQueryVibratorModeIndHdlr(void *msg);
extern void AtQueryDTFmtIndHdlr(void *msg);
extern void AtQueryMuteModeIndHdlr(void *msg);
extern void ATPowerReset(void *);
extern void SendMsg2AT(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

#endif /* __ATPROT_H */ 

