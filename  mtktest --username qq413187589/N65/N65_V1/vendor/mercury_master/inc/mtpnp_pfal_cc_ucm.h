/***********************************************
File name : MTPNP_PFAL_CC.h
Contents : MTPNP AD direct data transfer interface
History : Create by : Zhang Nan, Mar 16, 2007
************************************************/
#ifndef _MTPNP_PFAL_CC_UCM_H_
#define _MTPNP_PFAL_CC_UCM_H_

//#ifdef __MERCURY_MASTER__
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MMI_features.h"
#ifdef __MMI_UCM__
#include "MTPNP_AD_master_header.h"
#include "FrameworkStruct.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "CallManagementStruct.h"
#include "GSM7BitDefaultAlphabet.h"

/*maintain the slave group information begin*/
#define MMI_INVALID_CALL_GROUP   0xFF   //invalid call group
void MTPNP_PFAL_SetCallGroup(MTPNP_UINT8 call_group, MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_PFAL_GetCallGroup(MTPNP_UINT16 index);
void MTPNP_PFAL_InitCallGroup(void);
MTPNP_UINT8 MTPNP_PFAL_GetUnUsedGroupID(void);
void MTPNP_PFAL_InitOperationState(void);
/*maintain the slave group information end*/

//void MTPNP_PFAL_SetUCMOperationState(mmi_gsm_ucm_act_type_enum op_type, mmi_gsm_ucm_act_opcode_enum op_code);
//mmi_gsm_ucm_act_opcode_enum MTPNP_PFAL_GetUCMOPCodeState(void);
//mmi_gsm_ucm_act_type_enum MTPNP_PFAL_GetUCMActTypeState(void);

void MTPNP_PFAL_ucm_act_req(MTPNP_UINT8 op_code, void *act_struct);
void MTPNP_PFAL_get_call_list(mmi_ucm_sync_call_list_struct * callList);

#if 0
/* under construction !*/
/* under construction !*/
#endif
void MTPNP_PFAL_CC_UCMInitRegister(void);
void MTPNP_PFAL_CC_UCMShowActiveSrc(void *msg);
void MTPNP_PFAL_CC_UCMCloseActiveSrc(void *msg);
void MTPNP_PFAL_CC_UCMCallIncomingInd(void *msg);
void MTPNP_PFAL_CC_UCMShowIncomingSrc(void *msg);
void MTPNP_PFAL_CC_UCMCloseIncomingSrc(void *msg);
void MTPNP_PFAL_CC_UCMShowOutgoingSrc(void *msg);
void MTPNP_PFAL_CC_UCMCloseOutgoingSrc(void *msg);
void MTPNP_PFAL_CC_UCMShowSwapSucess(void *msg);
void MTPNP_PFAL_CC_UCMShowConfSucess(void *msg);
void MTPNP_PFAL_CC_UCMShowSplitSucess(void *msg);
void MTPNP_PFAL_CC_UCMShowScrUSSDReq(void *msg);
void MTPNP_PFAL_CC_UCMCBShowCallErrorMessage(void *msg);
void MTPNP_PFAL_CC_UCMShowCallForwardRsp(void *msg);
void MTPNP_PFAL_CC_UCMShowCallWaitingRsp(void *msg);
void MTPNP_PFAL_CC_UCMCallBarringRsp(void *msg);
void MTPNP_PFAL_CC_UCMCallChangePwdRsp(void *msg);
void MTPNP_PFAL_CC_UCMShowCallErrorMessage(MTPNP_UINT16 cause, MTPNP_UINT8 opcode);
void MTPNP_PFAL_CC_UCMOutgoingCallAlterRsp(void *msg);
void MTPNP_PFAL_UCMDTMFStop(void);
void MTPNP_PFAL_UCMDTMFHandle(MTPNP_UINT16 keycode);
void MTPNP_PFAL_CC_UCMSpeechInd(void *msg);
void MTPNP_PFAL_speech_ind(BOOL speech, U8 rat);

void MTPNP_PFAL_dial(void *act_struct);
void MTPNP_PFAL_hold_and_dial(void *act_struct);
void MTPNP_PFAL_accept(void *act_struct);
void MTPNP_PFAL_hold_and_accept(void *act_struct);
void MTPNP_PFAL_hold(void *act_struct);
void MTPNP_PFAL_retrieve(void *act_struct);
void MTPNP_PFAL_swap(void *act_struct);
void MTPNP_PFAL_conference(void *act_struct);
void MTPNP_PFAL_split(void *act_struct);
void MTPNP_PFAL_deflect(void *act_struct);
void MTPNP_PFAL_end_single(void *act_struct);
void MTPNP_PFAL_end_conference(void *act_struct);
void MTPNP_PFAL_end_all(void *act_struct);
void MTPNP_PFAL_force_release(void *act_struct);
void MTPNP_PFAL_auto_reject(void *act_struct);
void MTPNP_PFAL_explicit_call_transfer(void *act_struct);
void MTPNP_PFAL_end_active_and_retrieve(void *act_struct);
void MTPNP_PFAL_end_active_and_accept(void *act_struct);

void MTPNP_PFAL_dial_rsp(MTPNP_BOOL result, MTPNP_UINT8 opcode, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_hold_and_dial_rsp(MTPNP_BOOL result, MTPNP_UINT8 opcode, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_accept_req_ind(MTPNP_UINT8 handle);
void MTPNP_PFAL_hold_and_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_hold_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_retrieve_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_swap_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_conference_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_split_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_deflect_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_end_single_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_end_conference_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_end_all_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_force_release_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_auto_reject_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_explicit_call_transfer_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_end_active_and_retrieve_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_end_active_and_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_start_dtmf(void *act_struct);
void MTPNP_PFAL_stop_dtmf(void *act_struct);


void MTPNP_PFAL_sync_call_list_ind(void);
void MTPNP_PFAL_alert_ind(CM_CALL_HANDLE call_handle, MTPNP_UINT8 gen_tone);
void MTPNP_PFAL_connect_ind(void);
void MTPNP_PFAL_notify_ind(MTPNP_UINT8 * error_msg);
void MTPNP_PFAL_dial_req_ind(void *MsgStruct);
#ifdef __SAT__
void MTPNP_PFAL_MakeSATCall(MTPNP_CHAR* InNumber);
void MTPNP_PFAL_MakeSATCallFail();
#endif /* __SAT__ */
void MTPNP_PFAL_MakeCSDCall(MTPNP_CHAR* InNumber);
void MTPNP_PFAL_sat_info_ind(MTPNP_UINT8 * newNumber, MTPNP_UINT8 * msg);
void MTPNP_PFAL_ring_ind(void);
void MTPNP_PFAL_release_ind(MTPNP_UINT16 error_cause);
void MTPNP_PFAL_call_cost_ind(CM_CALL_HANDLE call_handle, PU8 symbol, PU8 value);
void MTPNP_PFAL_auto_redial_ind(void);
void MTPNP_PFAL_csd_call_approve(void *MsgStruct);
void MTPNP_PFAL_csd_call_confirm(MTPNP_BOOL result, void *msg);
void MTPNP_PFAL_start_processing_ind(void);
void MTPNP_PFAL_stop_processing_ind(MTPNP_UINT8 * disp_msg, MTPNP_UINT16 image_id, MTPNP_UINT16 tone_id);
void MTPNP_PFAL_ConfirmDTMFString();
void MTPNP_PFAL_PsCBackConfirmDTMFString(void *info);
void MTPNP_PFAL_PsCBackCallCostInd(void *info);
void MTPNP_PFAL_auto_dtmf_conf_display(MTPNP_UINT8 * disp_msg);
void MTPNP_PFAL_auto_dtmf_conf_cancel(void);
/*mmi_ucm_call_type_enum MTPNP_PFAL_GetCallTypeSim2(void);*/
mmi_ucm_call_type_enum MTPNP_PFAL_GetCallTypeSim2(csmcc_call_type_enum call_type);
#endif /* __MMI_UCM__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* _MTPNP_PFAL_CC_UCM_H_ */
