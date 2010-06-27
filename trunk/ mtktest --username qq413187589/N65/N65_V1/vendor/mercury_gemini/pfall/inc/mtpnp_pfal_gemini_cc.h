#ifndef __MTPNP_PFAL_SLAVE_CC_H__
#define __MTPNP_PFAL_SLAVE_CC_H__

// #ifdef __MERCURY_GEMINI__
#ifdef __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__

#include "MTPNP_AD_slave_header.h"
#include "MTPNP_SDK_common_if.h"

/*init function*/
void MTPNP_PFAL_initalizeCC(void);
/*init function*/

/*cc sdk callback handle begin*/
MTPNP_BOOL MTPNP_PFAL_Make_Call(ST_MTPNP_DATA_CALL_INFO * info);
MTPNP_BOOL MTPNP_PFAL_Hung_Up_Call(MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_PFAL_Reject_Incoming_Call(MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_PFAL_Accept_Incoming_Call(MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_PFAL_Switch_Call(void *pMsg);
MTPNP_BOOL MTPNP_PFAL_Join_Call(void *pMsg);
MTPNP_BOOL MTPNP_PFAL_Send_DTMF(MTPNP_UINT8 * digit);
MTPNP_BOOL MTPNP_PFAL_Play_Tone(void *pMsg);
MTPNP_BOOL MTPNP_PFAL_Set_Local_Number_Status(MTPNP_UINT8 status);
/*cc sdk callback handle end*/

void MTPNP_PFAL_CancelMOBeforeDialIndRsp(void *MsgStruct);
MTPNP_BOOL MTPNP_PFAL_EndAllActiveCall(void);
MTPNP_BOOL MTPNP_PFAL_EndAllHoldCall(void);
MTPNP_BOOL MTPNP_PFAL_EndAllExceptIncomingCall(void);
MTPNP_BOOL MTPNP_PFAL_SplictSpecificCall(MTPNP_UINT8 callID);
MTPNP_BOOL MTPNP_PFAL_EndSpecific_call(unsigned char handle);
MTPNP_BOOL MTPNP_PFAL_EndActiveAndReactiveHold(void);
void MTPNP_PFAL_EndAllCall(void);
void MTPNP_PFAL_RejectWaitCall(void);
MTPNP_BOOL MTPNP_PFAL_accept_Waiting_call(void);
void MTPNP_PFAL_Stop_DTMF(void);
void MTPNP_PFAL_CancleMOBeforeDialInd(void);

/*message handler begin*/
void MTPNP_PFAL_CC_RESET_ACM_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_ACM_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_SET_MAX_ACM_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_CCM_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_SET_CUG_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CHLD_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_ATH_RSP_Handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_CALL_LIST_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_DEFLECT_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_START_DTMF_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_STOP_DTMF_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_ATA_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_DIAL_REQ_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_DIAL_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CCM_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_ACMMAX_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_PUCT_IND_handler(void *MsgStruct);

void MTPNP_PFAL_CC_INTERNAL_ALERT_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_WAIT_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_RING_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_CONNECT_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_RELEASE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_DISCONNECT_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_SPEECH_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_AUTO_DTMF_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_NOTIFY_SS_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_NOTIFY_SS_CCBS_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_ACCEPT_REQ_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_ABORT_REQ_IND_handler(void *MsgStruct);
void MTPNP_PFAL_CC_CALL_SYNC_REQ_IND_handler(void *MsgStruct);
#ifdef __TCPIP__
void MTPNP_PFAL_CC_SET_CSD_PROFILE_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CC_GET_CSD_PROFILE_RSP_handler(void *MsgStruct);
#endif
void MTPNP_PFAL_SS_EMLPP_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CALL_FORWARD_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CALL_WAIT_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CLIP_INTERROGATE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CLIR_INTERROGATE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CNAP_INTERROGATE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_COLP_INTERROGATE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_COLR_INTERROGATE_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CALL_BARRING_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_CFU_STATUS_IND(void *MsgStruct);
void MTPNP_PFAL_SS_USSD_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_USSR_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_USSN_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CHANGE_PASSWORD_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_PARSING_STRING_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CB_PASSWORD_IND_handler(void *MsgStruct);
void MTPNP_PFAL_SS_CCBS_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_ABORT_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_SET_CLIR_FLAG_RSP_handler(void *MsgStruct);
void MTPNP_PFAL_SS_SET_PUCT_RSP_handler(void *MsgStruct);
/*message handler end*/

/*other begin*/
void MTPNP_PFAL_Dg_MMI_GetCallList(void);

/*other end*/

#endif/*#ifdef __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__*/

#endif /* __MTPNP_PFAL_SLAVE_CC_H__ */
