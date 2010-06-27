#ifndef __MTPNP_PFAL_MASTER_CHIS_H__
#define __MTPNP_PFAL_MASTER_CHIS_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MMI_features.h"
#include "MTPNP_AD_master_header.h"
#include "CallsStruct.h"

typedef struct
{
    MTPNP_UINT8 curCallLogType;
    MTPNP_UINT8 currDialedCallIndex;
    MTPNP_UINT8 currMissedCallIndex;
    MTPNP_UINT8 currRecvdCallIndex;

    MTPNP_CHAR name[MTPNP_AD_MAX_NAME_LEN];
    MTPNP_CHAR number[MTPNP_AD_MAX_CC_ADDR_LEN * 2];

    MTPNP_UINT16 no_of_times;
    ST_MTPNP_AD_TIME startTime;
    ST_MTPNP_AD_TIME duration;

} ST_MTPNP_CALLHIS_INFO;


typedef struct
{
    ST_MTPNP_AD_TIME total_out_time;
    ST_MTPNP_AD_TIME total_in_time;
    ST_MTPNP_AD_TIME last_call_time;
} ST_MTPNP_CALL_TIME_S;


typedef enum
{
    LASTMISSEDCALL_TYPE_NULL=0,
    LASTMISSEDCALL_TYPE_SIM1,
    LASTMISSEDCALL_TYPE_SIM2,
    LASTMISSEDCALL_TYPE_VOIP
}MTPNP_PFAL_LASTMISSEDCALL_TYPE;

void MTPNP_PFAL_CC_InitMissNotify(void);

void MTPNP_PFAL_EntryDialedCallList(void);

void HighlightSlaveCHISTMainMenu(void);
void HighlightSlaveCHISTResetAllLogs(void);
void HighlightSlaveCHISTDeleteAllMissed(void);
void HighlightSlaveCHISTDeleteAllDialed(void);
void HighlightSlaveCHISTDeleteAllRecvd(void);
void HighlightSlaveCHISTDeleteAllLogs(void);

void MTPNP_PFAL_chist_slave_req_read_missed_num_by_key(void);
void MTPNP_PFAL_chist_slave_rsp_read_missed_num(void);
void MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key(void);
void MTPNP_PFAL_chist_slave_rsp_read_recvd_num(void);
void MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key(void);
void MTPNP_PFAL_chist_slave_rsp_read_dialed_num(void);
void MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key(void);

void HighlightSlaveCHISTDialedCalls(void);
void HighlightSlaveCHISTMissedCalls(void);
void HighlightSlaveCHISTRecvdCalls(void);

void HighlightSlaveCHISTCallTime(void);
void HighlightSlaveCHISTLastTime(void);
void HighlightSlaveCHISTSentTime(void);
void HighlightSlaveCHISTRecvdTime(void);
void HighlightSlaveCHISTResetAllTime(void);

void HighlightSlaveCHISTSlaveSMSCount(void);
void HighlightSlaveCHISTSlaveSentSMS(void);
void HighlightSlaveCHISTSlaveRecvdSMS(void);

void HighlightSlaveCHISTInfoDialedNum(void);
void HighlightSlaveCHISTDeleteDialedNum(void);
void HighlightSlaveCHISTSaveDialedNum(void);
void HighlightSIM2CHISTCall1DialedNum(void);
void HighlightSlaveCHISTEditDialedNum(void);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSDialedNum(void);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSDialedNum(void);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HighlightSlaveCHISTInfoMissedNum(void);
void HighlightSlaveCHISTDeleteMissedNum(void);
void HighlightSlaveCHISTSaveMissedNum(void);
void HighlightSIM2CHISTCall1MissedNum(void);
void HighlightSlaveCHISTEditMissedNum(void);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSMissedNum(void);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSMissedNum(void);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HighlightSlaveCHISTInfoRecvdNum(void);
void HighlightSlaveCHISTDeleteRecvdNum(void);
void HighlightSlaveCHISTSaveRecvdNum(void);
void HighlightSIM2CHISTCall1RecvdNum(void);
void HighlightSlaveCHISTEditRecvdNum(void);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSRecvdNum(void);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSRecvdNum(void);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HighlightCHISTMasterMissedNotify(void);
void HighlightCHISTSlaveMissedNotify(void);
void MTPNP_PFAL_CHIST_Rearrange_Missed_Call_Status_Icon(void);

#if !defined(__SENDKEY2_SUPPORT__) || defined(E8D)
void HighlightCHISTDualMasterMixedCallLog(void);
void HighlightCHISTDualSlaveMixedCallLog(void);
#endif /* __SENDKEY2_SUPPORT__ */

void EntrySlaveCHISTMainMenu(void);
void EntrySlaveCHISTResetAllLogs(void);
void EntrySlaveCHISTCallTime(void);
void EntryCHISTSlaveSMSCount(void);

void EntrySlaveCHISTViewDialedCallList(void);
void EntrySlaveCHISTViewMissedCallList(void);
void EntrySlaveCHISTViewRecvdCallList(void);

void GetSlaveCurrDialedCallHISIndex(S32 ind);
void GetSlaveCurrRecvdCallHISIndex(S32 ind);
void GetSlaveCurrMissedCallHISIndex(S32 ind);
void EntrySlaveCHISTDialedListOptions(void);
void EntrySlaveCHISTMissedListOptions(void);
void EntrySlaveCHISTRecvdListOptions(void);
void ExitSlaveCHISTDialedListOptions(void);
void ExitSlaveCHISTMissedListOptions(void);
void ExitSlaveCHISTRecvdListOptions(void);
void EntrySlaveCHISTViewDialedCallInfo(void);
void EntrySlaveCHISTViewMissedCallInfo(void);
void EntrySlaveCHISTViewRecvdCallInfo(void);
void ExitSlaveCHISTViewDialedCall(void);
void ExitSlaveCHISTViewMissedCall(void);
void ExitSlaveCHISTViewRecvdCall(void);
void MTPNP_PFAL_CHIST_Delete_Dial_From_Call_Log_Scrn(MTPNP_UINT8 type);

void MTPNP_PFAL_DelAllDialedCallHistory(void);
void MTPNP_PFAL_DelAllMissedCallHistory(void);
void MTPNP_PFAL_DelAllRecvedCallHistory(void);
void MTPNP_PFAL_DelAllCallHistory(void);

void EntrySlaveCHISTDeleteAllDialedConfirm(void);
void EntrySlaveCHISTDeleteAllMissedConfirm(void);
void EntrySlaveCHISTDeleteAllRecvdConfirm(void);
void EntrySlaveCHISTDeleteAllConfirm(void);

void EntryDeleteSIM2DialedLogConfirm(void);
void EntryDeleteSIM2RecvedLogConfirm(void);
void EntryDeleteSIM2MissedLogConfirm(void);

void MTPNP_PFAL_CallLog_Del_DialedNum(void);
void MTPNP_PFAL_CallLog_Del_RecvedNum(void);
void MTPNP_PFAL_CallLog_Del_MissedNum(void);

void MTPNP_PFAL_Save_Dialed(void);
void MTPNP_PFAL_Save_Recved(void);
void MTPNP_PFAL_Save_Missed(void);

void MTPNP_PFAL_Call_Dialed(void);
void MTPNP_PFAL_Call_Dialed_cbk(void *p);
void MTPNP_PFAL_Call_Recved(void);
void MTPNP_PFAL_Call_Recvd_cbk(void *p);
void MTPNP_PFAL_Call_Missed(void);
void MTPNP_PFAL_Call_Missed_cbk(void *p);
void MTPNP_PFAL_GetCallLogName(ST_MTPNP_AD_CALL_NAME *item);

void MTPNP_PFAL_Edit_Dialed(void);
void MTPNP_PFAL_Edit_Recved(void);
void MTPNP_PFAL_Edit_Missed(void);

#ifdef __MMI_CH_OPTIONS_SENDSMS__
void MTPNP_PFAL_SendSMS_From_Dialed(void);
void MTPNP_PFAL_SendSMS_From_Recved(void);
void MTPNP_PFAL_SendSMS_From_Missed(void);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
void MTPNP_PFAL_SendMMS_From_Dialed(void);
void MTPNP_PFAL_SendMMS_From_Recved(void);
void MTPNP_PFAL_SendMMS_From_Missed(void);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HintSlaveCHISTDialedCalls(U16 index);
void HintSlaveCHISTRecvdCalls(U16 index);
void HintSlaveCHISTMissedCalls(U16 index);

void HintSlaveCHISTDeleteAllDialed(U16 index);
void HintSlaveCHISTDeleteAllRecvd(U16 index);
void HintSlaveCHISTDeleteAllMissed(U16 index);

void HintSlaveCHISTLastTime(U16 index);
void HintSlaveCHISTSentTime(U16 index);
void HintSlaveCHISTRecvdTime(U16 index);

void HintCHISTSlaveSentSMS(U16 index);
void HintCHISTSlaveRecvdSMS(U16 index);

void HintCHISTMasterMissedNotify(U16 index);
void HintCHISTSlaveMissedNotify(U16 index);

void CallHISIncreaseSlaveSentSMS(void);
void InitNvramSlaveSMSCounters(void);
void CallHISIncreaseSlaveRecvdSMS(void);
void LogSlaveDialedCallDuration(ST_MTPNP_AD_SLAVE_CALL_INFO * callinfo);
void MTPNP_PFAL_CHIST_SAT_Handler(void);
void InitSlaveCallHistoryContext(void);
void CHISTMasterMissedNotifyHandler(void);
void CHISTSlaveMissedNotifyHandler(void);

void MTPNP_PFAL_SetLastMissedCallType(MTPNP_PFAL_LASTMISSEDCALL_TYPE type);
MTPNP_PFAL_LASTMISSEDCALL_TYPE MTPNP_PFAL_GetLastMissedCallType(void);
void MTPNP_PFAL_ReadDualModeMissedNum(void);
void MTPNP_PFAL_chist_init_get_data_from_nvram(void);
void MTPNP_PFAL_chist_set_have_missed_call_flag(MTPNP_UINT8 is_missed_call);
MTPNP_UINT8 MTPNP_PFAL_chist_get_have_missed_call_flag(void);
void MTPNP_PFAL_chist_set_have_missed_call(void);
void MTPNP_PFAL_ReadDualMixedCallLog(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_GPRS_FEATURES__
void MTPNP_PFAL_GPRSCounter_Init(void);
void HighlightSlaveGPRSCount(void);
void HighlightSlaveGPRSCountLastSent(void);
void HighlightSlaveGPRSCountLastRecieved(void);
void HighlightSlaveGPRSCountAllSent(void);
void HighlightSlaveGPRSCountAllReceived(void);
void HighlightSlaveGPRSCountCounterReset(void);
void HintSlaveGPRSCountLastSent(U16 index);
void HintSlaveGPRSCountLastRecieved(U16 index);
void HintSlaveGPRSCountAllSent(U16 index);
void HintSlaveGPRSCountAllReceived(U16 index);
void GetSlaveGPRSCountersRequest(void);
void GetSlaveGPRSCountersResponse(void *info);
void EntryScrSlaveGPRSRecvCounterResetConfirmation(void);
void ResetSlaveGPRSCounterReq(void);
void ResetSlaveGPRSCounterRsp(void *info);
void EntryScrSlaveGPRSCounter(void);
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __MTPNP_PFAL_MASTER_CHIS_H__ */
