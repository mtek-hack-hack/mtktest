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
#ifdef __MMI_UCM__

#ifndef _PIXCOM_COMMON_STUB_H
#define _PIXCOM_COMMON_STUB_H

#ifdef __MMI_INCOMING_CALL_VIDEO__
#define CM_RINGTONE_VIDEO 0xffff
#endif 

#include "UCMGProt.h"
#include "UCMCallProt.h"

typedef struct
{
    S8 RedialNum[MAX_NUMBER];
    U8 MaxAttempts;
    U8 CurrentAttempt;
    U8 Timer;
    BOOL ErrRedialScreen;   /* guard cm error pop up timeout or not */
    BOOL RedialState;       /* guard redial timer expire or not  */
    U8 DialFromPhb;
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 DialFromCallLog;
#endif /* __MMI_DUAL_SIM_MASTER__*/
    U8 call_type;   /* __MMI_VIDEO_TELEPHONY__ */ 
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

typedef enum
{
    /*UCM standard operation*/
    MMI_GSM_UCM_IDLE = 0,
    MMI_GSM_UCM_DIAL,
    MMI_GSM_UCM_HOLD_AND_DIAL,
    MMI_GSM_UCM_ACCEPT,
    MMI_GSM_UCM_HOLD_AND_ACCEPT,
    MMI_GSM_UCM_HOLD,
    MMI_GSM_UCM_RETRIEVE,
    MMI_GSM_UCM_SWAP,
    MMI_GSM_UCM_CONFERENCE,
    MMI_GSM_UCM_SPLIT,
    MMI_GSM_UCM_DEFLECT,
    MMI_GSM_UCM_END_SINGLE,
    MMI_GSM_UCM_END_CONFERENCE,
    MMI_GSM_UCM_END_ALL,
    MMI_GSM_UCM_FORCE_RELEASE,
    MMI_GSM_UCM_AUTO_REJECT,
    MMI_GSM_UCM_EXPLICT_CALL_TRANSFER,
    MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE,
    MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT,
    MMI_GSM_UCM_SENDING_DTMF,

    /*GSM only operation*/
    MMI_GSM_UCM_END_ALL_HELD_CALL,
    MMI_GSM_UCM_END_ALL_ACTIVE_CALL,
    MMI_GSM_UCM_ACTIVATE_CCBS,
    MMI_GSM_UCM_AUTO_QUICK_END,
    
    MMI_GSM_UCM_ACT_OPCODE_TOTAL
} mmi_gsm_ucm_act_opcode_enum;

typedef enum
{
    MMI_GSM_UCM_NO_ACTION = 0,
    MMI_GSM_UCM_NORMAL,
    MMI_GSM_UCM_CRSS,
    MMI_GSM_UCM_ACT_TYPE_TOTAL
} mmi_gsm_ucm_act_type_enum;

typedef struct
{
    mmi_ucm_id_info_struct  ucm_current_uid;
    CALL_STATE              state;    
} mmi_gsm_disc_call_struct;

typedef struct
{
    cm_state_struct state_info;
    cm_redial_struct redial_info;
    cm_alert_struct alert_info;
    cm_history_struct history_info;
    mmi_gsm_ucm_act_opcode_enum ucm_operation;
    mmi_gsm_ucm_act_opcode_enum ucm_sub_operation;
    mmi_ucm_id_info_struct ucm_auto_dtmf_uid;
    mmi_gsm_disc_call_struct disc_call;
    mmi_gsm_disc_call_struct auto_reject_call;
    mmi_gsm_ucm_act_type_enum ucm_action_type;
    l4c_source_id_enum ucm_source_id;
    /*for L4C information*/
    l4c_number_struct l4c_number;
#ifdef __MMI_DUAL_SIM_MASTER__
    BOOL slave_ss_session;
    BOOL slave_reply_ussr;
#endif /* __MMI_DUAL_SIM_MASTER__ */
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
#ifdef __MMI_DUAL_SIM_MASTER__
extern void PlayCard2ConnectNotice(void);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

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

extern void mmi_gsm_dial(void *act_struct);
extern void mmi_gsm_hold_and_dial(void *act_struct);
extern void mmi_gsm_accept(void *act_struct);
extern void mmi_gsm_hold_and_accept(void *act_struct);
extern void mmi_gsm_hold(void *act_struct);
extern void mmi_gsm_retrieve(void *act_struct);
extern void mmi_gsm_swap(void *act_struct);
extern void mmi_gsm_conference(void *act_struct);
extern void mmi_gsm_split(void *act_struct);
extern void mmi_gsm_deflect(void *act_struct);
extern void mmi_gsm_end_single(void *act_struct);
extern void mmi_gsm_end_conference(void *act_struct);
extern void mmi_gsm_end_all(void *act_struct);
extern void mmi_gsm_force_release(void *act_struct);
extern void mmi_gsm_auto_reject(void *act_struct);
extern void mmi_gsm_explicit_call_transfer(void *act_struct);
extern void mmi_gsm_end_active_and_retrieve(void *act_struct);
extern void mmi_gsm_end_active_and_accept(void *act_struct);
extern void mmi_gsm_start_dtmf(void *act_struct);
extern void mmi_gsm_stop_dtmf(void *act_struct);

extern void mmi_gsm_dial_rsp(BOOL result, U8 opcode, U8 *error_msg);
extern void mmi_gsm_hold_and_dial_rsp(BOOL result, U8 opcode, U8 *error_msg);
extern void mmi_gsm_accept_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_accept_req_ind(CM_CALL_HANDLE handle);
extern void mmi_gsm_hold_and_accept_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_hold_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_retrieve_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_swap_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_conference_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_split_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_deflect_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_end_single_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_end_conference_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_end_all_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_force_release_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_auto_reject_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_explicit_call_transfer_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_end_active_and_retrieve_rsp(BOOL result, U8 *error_msg);
extern void mmi_gsm_end_active_and_accept_rsp(BOOL result, U8 *error_msg);

extern void mmi_gsm_get_call_list(mmi_ucm_sync_call_list_struct * call_list);
extern PU8 GetDisplayName(CM_CALL_HANDLE handle);
extern mmi_ucm_call_type_enum GetUCMCallType(csmcc_call_type_enum call_type); 
extern void SetUCMOperationState(mmi_gsm_ucm_act_type_enum op_type, mmi_gsm_ucm_act_opcode_enum op_code);
extern CM_CALL_HANDLE GetUnUsedGroupID(void);

extern void mmi_gsm_sync_call_list_ind(void);
extern void mmi_gsm_alert_ind(CM_CALL_HANDLE call_handle, U8 gen_tone);
extern void mmi_gsm_connect_ind(CM_CALL_HANDLE call_handle);
extern void mmi_gsm_notify_ind(U8 *error_msg, U16 image_id, U16 tone_id);
extern void mmi_gsm_speech_ind(BOOL speech, U8 rat, U8 call_type);
extern void mmi_gsm_ring_ind(void);
extern void mmi_gsm_dial_req_ind(void);
extern void mmi_gsm_release_ind(U16 error_cause);
extern void mmi_gsm_call_cost_ind(CM_CALL_HANDLE call_handle, PU8 symbol, PU8 value);
extern void mmi_gsm_auto_redial_ind(void);
extern void mmi_gsm_csd_call_approve(void *MsgStruct);
extern void mmi_gsm_csd_call_confirm(MMI_BOOL result, void *msg);
extern void mmi_gsm_start_processing_ind(void);
extern void mmi_gsm_stop_processing_ind(U8 *disp_msg, U16 image_id, U16 tone_id);
extern void mmi_gsm_auto_dtmf_conf_display(U8 *disp_msg);
extern void mmi_gsm_auto_dtmf_conf_cancel(void);
extern void mmi_gsm_ccbs_activation_conf(U8 *disp_msg);
extern void mmi_gsm_ccbs_activation_conf_cancel(void);
extern void mmi_gsm_ccbs_recall_conf(U8 *disp_msg);
extern void mmi_gsm_ccbs_recall_conf_cancel(void);
extern void mmi_gsm_ccbs_recall(void);

#ifdef __MMI_CH_QUICK_END__
extern void autoQuickEnd(void);
#endif

#endif /* _PIXCOM_COMMON_STUB_H */ 
#endif /* __MMI_UCM__ */
