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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  VoIPGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines exported prototypes.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VOIP_GPROT_H
#define VOIP_GPROT_H

#include "nvram_common_defs.h"

typedef enum
{
    MMI_VOIP_DEREG_STATE = 0,
    MMI_VOIP_PROCESS_STATE,
    MMI_VOIP_REG_STATE,
    MMI_VOIP_REG_STATE_TOTAL
} mmi_voip_reg_state_enum;

typedef enum
{
    MMI_VOIP_CALL_CONN_NONE = 0,
    MMI_VOIP_CALL_CONN_AT,
    MMI_VOIP_CALL_CONN_GSM,
    MMI_VOIP_CALL_CONN_VOIP,
    MMI_VOIP_CALL_CONN_TOTAL
} mmi_voip_call_conn_enum;

typedef struct
{
    U16 dispName[VOIP_DISP_NAME_LEN];
    U8 remoteUri[VOIP_URI_LEN];
    U8 dispDcs;
    MYTIME startTime;
    MYTIME endTime;
} mmi_voip_call_log_struct;

/* VoIPMain.c */
extern void mmi_voip_init(void);
extern void mmi_voip_deinit(void);

/* VoIPInterface.c */
extern mmi_voip_reg_state_enum mmi_voip_app_get_register_state(void);
extern void mmi_voip_app_make_call(U8 *unicodeUri);
extern S32 mmi_voip_app_total_call(void);
extern void mmi_voip_app_set_conn_flag(mmi_voip_call_conn_enum needConn);
extern mmi_voip_call_conn_enum mmi_voip_app_get_conn_flag(void);
extern U16 mmi_voip_app_get_marker_screen(void);
extern void mmi_voip_entry_headsetkey(void);
extern U8 mmi_voip_need_msg_waiting_ind(void);
extern void mmi_voip_entry_msg_waiting_ind(void);
extern void mmi_voip_go_back_to_idle(void);
extern void mmi_voip_entry_msg_waiting_popup(void);

// extern void mmi_voip_ucm_get_call_list(mmi_ucm_sync_call_list_struct *callList);
extern void mmi_voip_ucm_get_log_name(S32 callId, S32 dialogId, U16 *logName);
extern void mmi_voip_ucm_get_disp_name(S32 callId, S32 dialogId, U16 *dispName);
extern void mmi_voip_ucm_get_num_uri(S32 callId, S32 dialogId, U8 *numUri);
extern void mmi_voip_ucm_get_speech_direction(S32 rtpDirection, MMI_BOOL *localSwitch, MMI_BOOL *remoteSwitch);
extern void mmi_voip_ucm_get_rtp_direction(MMI_BOOL localSwitch, MMI_BOOL remoteSwitch, S32 *rtpDirection);
extern void mmi_voip_ucm_act_req(U8 opCode, void *actStruct);
extern void mmi_voip_ucm_dial_req(void *actStruct);
extern void mmi_voip_ucm_accept_req(void *actStruct);
extern void mmi_voip_ucm_hold_req(void *actStruct);
extern void mmi_voip_ucm_retrieve_req(void *actStruct);
extern void mmi_voip_ucm_swap_req(void *actStruct);
extern void mmi_voip_ucm_conference_req(void *actStruct);
extern void mmi_voip_ucm_split_req(void *actStruct);
extern void mmi_voip_ucm_transfer_req(void *actStruct);
extern void mmi_voip_ucm_end_single_req(void *actStruct);
extern void mmi_voip_ucm_end_conference_req(void *actStruct);
extern void mmi_voip_ucm_end_all_req(void *actStruct);
extern void mmi_voip_ucm_background_reject_req(void *actStruct);
extern void mmi_voip_ucm_start_dtmf(void *actStruct);
extern void mmi_voip_ucm_stop_dtmf(void *actStruct);
extern void mmi_voip_ucm_dial_act_rsp(U8 opCode, S32 groupId, S32 callId, U8 result, U8 *dispMsg);
extern void mmi_voip_ucm_act_rsp(U8 opCode, U8 result, U8 *dispMsg);
extern void mmi_voip_ucm_sync_call_list(void);
extern void mmi_voip_ucm_alert_ind(MMI_BOOL localGen);
extern void mmi_voip_ucm_connect_ind(S32 groupId, S32 callId);
extern void mmi_voip_ucm_notify_ind(U8* dispMsg, U16 imageId, U16 toneId);
extern void mmi_voip_ucm_session_ind(U8 sessionType, MMI_BOOL sessionSwitch);
extern void mmi_voip_ucm_speech_ind(U8 sessionType, MMI_BOOL localSwitch, MMI_BOOL remoteSwitch);
extern void mmi_voip_ucm_ring_ind(S32 groupId, S32 callId);
extern void mmi_voip_ucm_release_ind(S32 groupId, S32 callId, U8 *dispMsg, U16 imageId, U16 toneId);
extern void mmi_voip_ucm_auto_redial_ind(void);
extern void mmi_voip_ucm_start_processing_ind(S32 groupId, S32 callId, U8 *dispMsg);
extern void mmi_voip_ucm_stop_processing_ind(U8 *dispMsg, U16 imageId, U16 toneId);
extern void mmi_voip_ucm_control_rtp(U8 rtpHandle, U8 localSwitch, U8 remoteSwitch);
extern void mmi_voip_ucm_suspend_rtp(void);

/* VoIPSignal.c */
extern S32 mmi_voip_get_outgoing_call_id(void);
extern S32 mmi_voip_get_incoming_call_id(void);
extern void mmi_voip_entry_abort_call(void);
extern void mmi_voip_entry_ans_to_conn_voip(void);
extern void mmi_voip_entry_ans_to_disconn_voip(void);
#endif /* VOIP_GPROT_H */ 

