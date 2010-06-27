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
 *  CommonStubsProt.h
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

   FILENAME : CommonStubsProt.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : Nov 11,02

**************************************************************/
#ifndef __MMI_UCM__

#ifndef _PIXCOM_COMMON_STUB_H
#define _PIXCOM_COMMON_STUB_H

#ifdef __MMI_INCOMING_CALL_VIDEO__
#define CM_RINGTONE_VIDEO 0xffff
#endif 

typedef struct
{
    S8 RedialNum[MAX_NUMBER];
    U8 MaxAttempts;
    U8 CurrentAttempt;
    BOOL ErrRedialScreen;   /* guard cm error pop up timeout or not */
    BOOL RedialTimer;       /* guard redial timer expire or not  */
    U8 DialFromPhb;
} cm_redial_struct;

typedef struct
{
    U16 RingToneId;
    U16 BacklightPatternId;
    U16 QuickEndTime;
    MYTIME LastCTRTime;
    U8 AlertType;
    BOOL DTMF;  /* default ON */
    BOOL IsSilent;
    BOOL IsMute;
    BOOL IsLoudSpk;
    BOOL IsHFree;
    BOOL IsInternalAlert;
    BOOL IsSpeechOn;
    BOOL IsRinging;
    BOOL IsRecord;
    BOOL IsCTRStart;
    BOOL IsRingAfterVib;
} cm_alert_struct;

typedef struct
{
    FuncPtr CbackAfterNotifySS;
    BOOL IsPopUp;
    BOOL IsNotifySS;
    BOOL IsSave;
    BOOL IsClamCloseEndCall;
} cm_history_struct;

typedef struct
{
    cm_state_struct state_info;
    cm_redial_struct redial_info;
    cm_alert_struct alert_info;
    cm_history_struct history_info;
} cm_context_struct;

extern cm_context_struct *cm_p;

extern void MutethePhone(void);
extern void UnMutethePhone(void);
extern void OptionMuteorUnMutetheCall(void);

extern pBOOL IsPhoneInSilent(void);
extern void UnSilencethePhone(void);

extern pBOOL GetLSpkNowOff(void);

extern void SetVoiceRecordingFlag(pBOOL flag);
extern pBOOL GetVoiceRecordingFlag(void);

extern void CMSetupAlertForMT(void);

extern void ShowIncomingCallIndication(void);
extern void StopIncomingCallIndication(void);
extern void StartRingtoneOrVibrator(void);
extern void StopRingtoneOrVibrator(void);

extern void StartRingTone(U16 ringTone);
extern void StopRingTone(U16 ringTone);
extern void VibratorThenRing(void);
extern void StopVibratorPlayRing(void);

extern void PlayConnectNotice(void);

extern pBOOL GetRingAfterVibFlag(void);
extern void SetRingAfterVibFlag(pBOOL truth);
extern pBOOL GetRingingFlag(void);
extern void SetRingingFlag(pBOOL truth);
extern pBOOL GetSpeechFlag(void);
extern void SetSpeechFlag(pBOOL truth);
extern pBOOL GetInternalAlert(void);
extern void SetInternalAlert(pBOOL truth);
extern void PlayInternalOutgoingTone(void);
extern void StopInternalOutgoingTone(void);
extern void PsCBackPlayInternalTone(void *info);

extern void SetDTMFFlag(pBOOL dtmfFlag);
extern void DTMFFunction(void);
extern U16 GetHFreeHeld(void);
extern void SetHFreeHeld(BOOL HFreeHeldFlag);
extern void LoudSpeakerFunction(void);

extern void SetSideVolumeKeysForCM(void);
extern void SetKeyPadStartVoiceRecordLongPress(void);
extern void SetKeyPadStopVoiceRecordLongPress(void);
extern void insert_screen_before_call_marker(U16 scrnID, FuncPtr entryFuncPtr);
extern void DummyAforSideKeyHandling(void);
extern void DummyBforSideKeyHandling(void);
extern void DummyCforSideKeyHandling(void);
extern void DummyDforSideKeyHandling(void);

extern pBOOL IsSimControlProcedure(PU8 buf);
extern pBOOL IsManufactuerSpecific(PU8 buf);

#endif /* _PIXCOM_COMMON_STUB_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "CommonStubsProtEX.h"
#endif /* __MMI_UCM__ */