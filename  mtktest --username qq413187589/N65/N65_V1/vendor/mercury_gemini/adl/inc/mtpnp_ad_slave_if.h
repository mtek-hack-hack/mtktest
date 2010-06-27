/***********************************************
File name : MTPNP_AD_slave_if.h
Contents : MTPNP adapter slave side interface define
History : Create by : Zhang Nan, May 19, 2007
************************************************/

#ifndef __MTPNP_AD_SLAVE_IF_H__
#define __MTPNP_AD_SLAVE_IF_H__

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_SDK_common_if.h"
#include "MTPNP_AD_common_def.h"
#include "MTPNP_AD_slave_common_def.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define __MTPNP_AD_SLAVE__

/* custom data transfer interface */
void MTPNP_CDT_Register(MTPNP_CDT_FuncPtr callbackFunc);
E_MTPNP_DDT_STATUS MTPNP_AD_Direct_Data_Transfer(MTPNP_UINT data_len, MTPNP_UINT8 * data);
/* custom data transfer interface */
#ifdef __MTPNP_VIRTUAL_EINT_SUPPORT__
/* virtual EINT transfer interface */
void MTPNP_VEINT_Register(E_MTPNP_PFAL_EINT_NO veint_no, MTPNP_VEINT_FuncPtr callbackFunc);
E_MTPNP_VEINT_STATUS MTPNP_AD_VEINT_Data_Transfer(ST_MTPNP_AD_VEINT_DATA * veint_data);
/* virtual EINT transfer interface */
#endif /*__MTPNP_VIRTUAL_EINT_SUPPORT__*/
/* custom config */
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_dll_uart(void);
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_app_uart(void);
extern E_MTPNP_UART_BAUDRATE MTPNP_AD_Custom_dll_start_mode(void);
extern MTPNP_UINT8 MTPNP_AD_Custom_qos_min_level(void);
extern MTPNP_UINT8 MTPNP_AD_Custom_qos_max_level(void);
extern void MTPNP_AD_Custom_Enable_Wakeup_Signal(void);
extern void MTPNP_AD_Custom_Disable_Wakeup_Signal(void);

#if 0
/* under construction !*/
#endif
/* custom config */

/* phone control API */
void MTPNP_AD_Init_Slave(MTPNP_UINT8 * version);
MTPNP_UINT16 MTPNP_AD_Get_Supported_Feature(void);
MTPNP_BOOL MTPNP_AD_Request_Slave_Startup(void);
void MTPNP_AD_Set_Slave_PowerOn_Mode(E_MTPNP_AD_POWERON_MODE mode);
E_MTPNP_AD_POWERON_MODE MTPNP_AD_Get_Slave_PowerOn_Mode(void);
E_MTPNP_SLAVE_STARTUP_MODE MTPNP_AD_Get_Slave_Startup_Mode(void);
void MTPNP_AD_EventHandler(void *MsgHandler);
void MTPNP_AD_Bootup_Slave(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_Startup_Finished(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_SIM_Absent(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_Need_CHV(void);
/* phone control API */

/* network management interface */
void MTPNP_AD_Set_QOS_Level(ST_MTPNP_QOS_LEVEL level);
MTPNP_BOOL MTPNP_AD_Report_Slave_RX_Level(MTPNP_UINT8 current_band, MTPNP_UINT8 level);
MTPNP_BOOL MTPNP_AD_Report_Slave_Line_Selection_Status(E_MTPNP_AD_LINE_TPYE line);
MTPNP_BOOL MTPNP_AD_Select_Line_Succeed(void);
MTPNP_BOOL MTPNP_AD_Select_Line_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_CallID_Status(E_MTPNP_LOCAL_NUMBER_STATUS status);
MTPNP_BOOL MTPNP_AD_Update_CallID_Succeed(void);
MTPNP_BOOL MTPNP_AD_Update_CallID_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_PLMN_ID(MTPNP_UINT8 *plmn);
MTPNP_BOOL MTPNP_AD_Report_Network_Lost(void);
MTPNP_BOOL MTPNP_AD_Report_Network_Attach_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_Network_Attach_Succeed(MTPNP_UINT8 * plmn, MTPNP_BOOL home);
MTPNP_BOOL MTPNP_AD_Report_SPN(E_MTPNP_CODING_SCHEME code, MTPNP_CHAR * spn);
/* network management interface */

/* msisdn */
MTPNP_UINT16 MTPNP_AD_Get_MSISDN_List_Count(void);
MTPNP_BOOL MTPNP_AD_MSISDN_Read_Succeed(MTPNP_UINT16 index,
                                        E_MTPNP_CODING_SCHEME coding_scheme,
                                        MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);
MTPNP_BOOL MTPNP_AD_MSISDN_Read_Failed(const MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_MSISDN_ReadAll_Finished(MTPNP_UINT16 list_count);
MTPNP_BOOL MTPNP_AD_MSISDN_Record_Erase_Succeed(void);
MTPNP_BOOL MTPNP_AD_MSISDN_Record_Erase_Failed(void);
MTPNP_BOOL MTPNP_AD_MSISDN_Record_Update_Succeed(void);
MTPNP_BOOL MTPNP_AD_MSISDN_Record_Update_Failed(MTPNP_UINT16 fail_cause, E_MTPNP_STORAGE_TYPE storage);
/* msidsn */

/* CHV management interface */
extern void MTPNP_AD_Get_SIM_PIN_Status_Request(void);
extern void MTPNP_AD_Update_CHV_Info(ST_SIM_CHV_INFO * chv_info);
extern void MTPNP_AD_Set_SMU_Status(E_MTPNP_AD_SMU_OPERATION status);
extern E_MTPNP_AD_SMU_OPERATION MTPNP_AD_Get_SMU_Status(void);
extern void MTPNP_AD_Set_CHV_Status(E_MTPNP_AD_CHV_STATUS status);
E_MTPNP_AD_CHV_STATUS MTPNP_AD_Get_CHV_Status(void);
extern MTPNP_BOOL MTPNP_AD_CHV_Operation_Rsp(MTPNP_BOOL result);
extern MTPNP_BOOL MTPNP_AD_Report_CHV_Status(void);
extern void MTPNP_AD_Set_SIM_CurrPwd(MTPNP_UINT8 type);
extern MTPNP_UINT8 MTPNP_AD_Get_SIM_CurrPwd(void);
/* CHV management interface */

/* phonebook management */
 /*ADN*/ void MTPNP_AD_ADN_Startup_Read(ST_MTPNP_DATA_PB_CAPACITY *info);
MTPNP_UINT16 MTPNP_AD_ADN_GetOpIndex(void);
SLAVE_ADN_OP_TYPE MTPNP_AD_ADN_GetOPType(void);
MTPNP_UINT16 MTPNP_AD_ADN_GetNextValidIndex(MTPNP_UINT16 Begin);
MTPNP_BOOL MTPNP_AD_ADN_READALL_FINISH(MTPNP_UINT8 max_name_len, MTPNP_UINT16 capacity, MTPNP_UINT8 max_number_len);
MTPNP_BOOL MTPNP_AD_ADN_Record_ADD_Succeed(MTPNP_UINT16 index, MTPNP_UINT16 name_length, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_ADD_Failed(MTPNP_UINT16 fail_cause, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_EDIT_Succeed(MTPNP_UINT16 index, MTPNP_UINT16 name_length, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_EDIT_Failed(MTPNP_UINT16 fail_cause, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_DEL_Succeed(MTPNP_UINT16 index, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_DEL_Failed(MTPNP_UINT16 index, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_DELALL_Succeed(MTPNP_UINT16 index, E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_AD_ADN_Record_DELALL_Failed(MTPNP_UINT16 index, E_MTPNP_STORAGE_TYPE storage);


MTPNP_BOOL MTPNP_AD_ADN_READ_SUCCEED(MTPNP_UINT16 index,
                                     E_MTPNP_CODING_SCHEME coding_scheme,
                                     MTPNP_UINT8 name_length,
                                     MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);

 /*ADN*/
    /*FDN*/
    MTPNP_BOOL MTPNP_AD_FDN_Read_Succeed(MTPNP_UINT16 index,
                                         E_MTPNP_CODING_SCHEME coding_scheme,
                                         MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);
MTPNP_BOOL MTPNP_AD_FDN_readall_finish(MTPNP_UINT8 max_name_len, MTPNP_UINT16 capacity, MTPNP_UINT8 max_number_len);

MTPNP_UINT16 MTPNP_AD_FDN_CombineIndex(const MTPNP_UINT16 Lsb, const MTPNP_UINT16 Msb);
MTPNP_UINT16 MTPNP_AD_FDN_GetIndexFromSDK(const MTPNP_UINT16 index);
MTPNP_UINT16 MTPNP_AD_FDN_GetRecordIndexFromSDK(const MTPNP_UINT16 index);
void MTPNP_AD_FDN_SetOPIndex(MTPNP_UINT16 index);
void MTPNP_AD_FDN_SetCapatity(MTPNP_UINT16 total);
MTPNP_UINT16 MTPNP_AD_FDN_GetCapatity(void);
MTPNP_UINT8 MTPNP_AD_FDN_GetNameLen(void);
void MTPNP_AD_FDN_SetNameLen(MTPNP_UINT8 len);

MTPNP_UINT16 MTPNP_AD_FDN_GetOPIndex(void);
MTPNP_BOOL MTPNP_AD_FDN_Add_Record_Succeed(MTPNP_UINT16 index, MTPNP_UINT16 record_index);
MTPNP_BOOL MTPNP_AD_FDN_FDN_Add_Record_Failed(void);
MTPNP_BOOL MTPNP_AD_FDN_Update_Record_Succeed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_FDN_Update_Record_Failed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Delete_Record_Succeed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Delete_Record_Failed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Return_STATE_Succeed(MTPNP_UINT8 Status);
MTPNP_BOOL MTPNP_AD_FDN_Return_STATE_Failed(void);
MTPNP_BOOL MTPNP_AD_FDN_Set_STATE_Succeed(void);
MTPNP_BOOL MTPNP_AD_FDN_Set_STATE_Failed(void);
void MTPNP_AD_FDN_SetState(MTPNP_UINT8 state);
MTPNP_UINT8 MTPNP_AD_FDN_GetState(void);
 /*FDN*/
/*phonebook management */
/* SMS management interface */
    MTPNP_BOOL MTPNP_AD_SMS_Begin_Loaded(ST_MTPNP_DATA_SMS_CAPACITY * capacity);
MTPNP_BOOL MTPNP_AD_SMS_Load_Ongoing(ST_MTPNP_AD_SMS_LOAD_ONGOING * sms_index);
MTPNP_BOOL MTPNP_AD_SMS_Load_Finished(ST_MTPNP_DATA_SMS_CAPACITY * capacity);
MTPNP_BOOL MTPNP_AD_SMS_Ready(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Full_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Exceed_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Avail_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Status_Report(ST_MTPNP_AD_SMS_STATUS_REPORT * status);
MTPNP_BOOL MTPNP_AD_SMS_Deliver_New_SMS(ST_MTPNP_AD_DELIVER_SMS * sms);
MTPNP_BOOL MTPNP_AD_SMS_Deliver_App_Data(ST_MTPNP_AD_APP_DATA * data);
ST_MTPNP_AD_SMS_SEND_MSG *MTPNP_AD_Get_SMS_Temp(void);
MTPNP_BOOL MTPNP_AD_Free_SMS_Temp(void);
MTPNP_BOOL MTPNP_AD_SMS_Need_Saved(void);
MTPNP_BOOL MTPNP_AD_SMS_Send_Result(ST_MTPNP_AD_SMS_SEND_RSP * rspSend);
MTPNP_BOOL MTPNP_AD_SMS_Abort_Result(MTPNP_BOOL abort_result);
MTPNP_BOOL MTPNP_AD_SMS_Save_Result(ST_MTPNP_AD_SMS_SAVE_RSP * rspSave);
MTPNP_BOOL MTPNP_AD_SMS_Read_Result(ST_MTPNP_AD_SMS_GET_RSP * sms_record);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Full(E_MTPNP_AD_SMS_MEMORY_FULL type);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Avail(E_MTPNP_AD_SMS_MEMORY_AVAIL type);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Exceed(E_MTPNP_AD_SMS_MEMORY_EXCEED type);
MTPNP_BOOL MTPNP_AD_SMS_Delete_Result(ST_MTPNP_AD_SMS_DEL_RSP * del_result);
MTPNP_BOOL MTPNP_AD_SMS_Copy_Result(ST_MTPNP_AD_SMS_COPY_RSP * copy_rsp);
/* SMS management interface */

/* message setup begin */
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Num_Rsp(ST_MTPNP_AD_SMS_GET_PROFILE_NUM_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Params_Rsp(ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Profile_Params_Rsp(ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Common_Params_Rsp(ST_MTPNP_AD_SMS_GET_COMMON_PARAMS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Common_Params_Rsp(ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Prefer_Storage_Rsp(ST_MTPNP_AD_SMS_GET_PREFER_STORAGE_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Prefer_Storage_Rsp(ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Msg_Num_Rsp(ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Msg_Waiting_Ind(ST_MTPNP_AD_SMS_MSG_WAITING_IND * msg_ind);
/* message setup end */

/* call control begin*/
/*cc for framework begin*/
void MTPNP_AD_CC_Init(void);
void MTPNP_AD_CC_Deinit(void);
void MTPNP_AD_CC_CB_Init_Register(void);
/*cc for framework end*/

void MTPNP_AD_SetDialInd(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_GetDialInd(void);

void MTPNP_AD_SetConnectInd(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_GetConnectInd(void);

void MTPNP_AD_SetMTCallID(MTPNP_UINT8 value);
MTPNP_UINT8 MTPNP_AD_GetMTCallID(void);

void MTPNP_AD_SetMOCallID(MTPNP_UINT8 value);
MTPNP_UINT8 MTPNP_AD_GetMOCallID(void);
void MTPNP_AD_SetAutoRejectCallID(MTPNP_UINT8 value);
MTPNP_UINT8 MTPNP_AD_GetAutoRejectCallID(void);

SLAVE_CHLD_TYPE_ENUM MTPNP_AD_GetCHLDType(void);
void MTPNP_AD_SetCHLDType(SLAVE_CHLD_TYPE_ENUM type);

void MTPNP_AD_SetIsNeedSyncCallState(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_GetIsNeedSyncCallState(void);

void MTPNP_AD_Set_Caller_ID(MTPNP_UINT8 callerID);
MTPNP_UINT8 MTPNP_AD_Get_Caller_ID(void);
MTPNP_BOOL MTPNP_AD_Notify_Incoming_Call(ST_MTPNP_DATA_CALL_INFO * MsgStruct);
MTPNP_BOOL MTPNP_AD_ReportMOSuccessToMaster(void *msg);
MTPNP_BOOL MTPNP_AD_ReportMOFailedToMaster(MTPNP_UINT16 ErrorCause);
MTPNP_BOOL MTPNP_AD_SlaveReportCCFailed(MTPNP_UINT16 cause);
MTPNP_BOOL MTPNP_AD_SplictSpecificCallSuc(void);
MTPNP_BOOL MTPNP_AD_EndactiveAndReactivehold(void);
MTPNP_BOOL MTPNP_AD_EndactiveAndAccept(void);
MTPNP_BOOL MTPNP_AD_SSCallWaitRsp(void *msg);
MTPNP_BOOL MTPNP_AD_SSChangePwdRsp(void *msg);
MTPNP_BOOL MTPNP_AD_SSCallBarringRsp(void *msg);
MTPNP_BOOL MTPNP_AD_ReportCFUStatus(ST_MTPNP_AD_CFU_IND * msg);
void MTPNP_AD_Slave_CC_DDTCback_DropUSSD(void *msgbuf);
void MTPNP_AD_Slave_CC_DDTCback_PlayConnectTone(void *msgbuf);
void MTPNP_AD_Slave_DDTCback_MuteOnSpeech(void *msgbuf);
MTPNP_BOOL MTPNP_AD_ReportSpeechStatus(ST_MTPNP_SPEECH_IND_INFO * msg);
MTPNP_BOOL MTPNP_AD_ReportCCState(void *msg);
void MTPNP_PFAL_CC_DropUSSD(void);
void MTPNP_PFAL_MuteOnSpeech(MTPNP_BOOL on);
/* call control end*/

/* plmn begin */
extern MTPNP_BOOL MTPNP_AD_Get_Select_Mode_Rsp(E_MTPNP_AD_PLMN_MODE mode);
extern MTPNP_BOOL MTPNP_AD_Set_Select_Mode_Rsp(MTPNP_BOOL result);
extern MTPNP_BOOL MTPNP_AD_PLMN_List_Ind(MTPNP_UINT16 num);
extern MTPNP_BOOL MTPNP_AD_Get_Preferred_Network_Rsp(ST_MTPNP_AD_GET_PREFERRED_NETWORK_RSP * network_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_Preferred_Network_Rsp(ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_PLMN_Rsp(ST_MTPNP_AD_SET_PLMN_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Get_PLMN_List_Rsp(ST_MTPNP_AD_GET_PLMN_LIST_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Abort_PLMN_List_Rsp(void);
extern MTPNP_BOOL MTPNP_AD_Report_NITZ(ST_MTPNP_AD_NW_TIME_ZONE_IND *nitz);
/* plmn end */

/* cell broadcast messages begin */
extern MTPNP_BOOL MTPNP_AD_Get_CB_Mode_Rsp(ST_MTPNP_AD_GET_CB_MODE_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_CB_Mode_Rsp(ST_MTPNP_AD_SET_CB_MODE_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Subscribe_CB_Rsp(MTPNP_BOOL result);
extern MTPNP_BOOL MTPNP_AD_New_CB_Ind(ST_MTPNP_AD_CB_MSG_IND * cb_ind);
/* cell broadcast messages end */

/* voice mail begin */
extern MTPNP_BOOL MTPNP_AD_Get_Mailbox_Info_Rsp(ST_MTPNP_AD_GET_MAILBOX_ADDRESS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_Mailbox_Address_Rsp(ST_MTPNP_AD_SET_MAILBOX_ADDRESS_RSP * set_rsp);
/* voice mail end */

/* CallHistory begin */
void MTPNP_AD_ReportCallHistoryReady(void);
void MTPNP_AD_ReportCallHistory(MTPNP_AD_RSP_LOAD_CALL_SCT * msg);
void MTPNP_AD_RspDelCallHistory(MTPNP_AD_RSP_DEL_CALL_SCT * msg);
void MTPNP_AD_RspSetCallHistory(MTPNP_AD_RSP_SET_CALL_SCT * msg);
void MTPNP_AD_Slave_CallHistorySetReq( void *info);
void MTPNP_AD_Slave_CallHistoryDelReq( void *info);

void MTPNP_AD_Slave_CallHistoryLoadReq( void *info);
void MTPNP_AD_RspUpdatePUCT(MTPNP_AD_RSP_RESET_CALLCOST_SCT * msg);
void MTPNP_AD_RspReadPUCT(MTPNP_AD_RSP_READ_CALLCOST_SCT * msg);
void MTPNP_AD_RspReadCCM(MTPNP_AD_RSP_READ_CCM_SCT * msg);

MTPNP_BOOL MTPNP_AD_ACM_Read_Succeed(MTPNP_UINT32 acm);
MTPNP_BOOL MTPNP_AD_ACM_Read_Failed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Read_Succeed(MTPNP_UINT32 acm_max);
MTPNP_BOOL MTPNP_AD_ACMMAX_Read_Failed(void);
MTPNP_BOOL MTPNP_AD_ACM_Delete_Succeed(void);
MTPNP_BOOL MTPNP_AD_ACM_Delete_Failed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Update_Succeed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Update_Failed(void);

/* CallHistory end */

/* RF setting */
MTPNP_BOOL MTPNP_AD_Report_RF_Status(MTPNP_BOOL rf);
/* RF setting */

/* engineer/factory mode begin */
extern MTPNP_BOOL MTPNP_AD_FM_Comm_Test_Rsp(void);
/* engineer/factory mode end */
#ifdef __cplusplus
}
#endif

#else
#include "MTPNP_SDK_slave_if.h"
#include "MTPNP_AD_slave_common_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define __MTPNP_AD_SLAVE__

/* custom data transfer interface */
void MTPNP_CDT_Register(MTPNP_CDT_FuncPtr callbackFunc);
E_MTPNP_DDT_STATUS MTPNP_AD_Direct_Data_Transfer(MTPNP_UINT data_len, MTPNP_UINT8 * data);
/* custom data transfer interface */

/* virtual EINT transfer interface */
void MTPNP_VEINT_Register(E_MTPNP_PFAL_EINT_NO veint_no, MTPNP_VEINT_FuncPtr callbackFunc);
E_MTPNP_VEINT_STATUS MTPNP_AD_VEINT_Data_Transfer(ST_MTPNP_AD_VEINT_DATA * veint_data);
/* virtual EINT transfer interface */

/* custom config */
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_dll_uart(void);
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_app_uart(void);
extern E_MTPNP_UART_BAUDRATE MTPNP_AD_Custom_dll_start_mode(void);
extern MTPNP_UINT8 MTPNP_AD_Custom_qos_min_level(void);
extern MTPNP_UINT8 MTPNP_AD_Custom_qos_max_level(void);
extern void MTPNP_AD_Custom_Enable_Wakeup_Signal(void);
extern void MTPNP_AD_Custom_Disable_Wakeup_Signal(void);

#if 0
/* under construction !*/
#endif
/* custom config */

/* phone control API */
void MTPNP_AD_Init_Slave(MTPNP_UINT8 * version);
void MTPNP_AD_Notify_Startup_Req(void);
MTPNP_BOOL MTPNP_AD_Is_Recved_Startup_Req(void);
MTPNP_UINT16 MTPNP_AD_Get_Supported_Feature(void);
MTPNP_BOOL MTPNP_AD_Request_Slave_Startup(void);
void MTPNP_AD_Set_Slave_PowerOn_Mode(E_MTPNP_AD_POWERON_MODE mode);
E_MTPNP_AD_POWERON_MODE MTPNP_AD_Get_Slave_PowerOn_Mode(void);
E_MTPNP_SLAVE_STARTUP_MODE MTPNP_AD_Get_Slave_Startup_Mode(void);
void MTPNP_AD_EventHandler(void *MsgHandler);
void MTPNP_AD_Bootup_Slave(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_Startup_Finished(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_SIM_Absent(void);
MTPNP_BOOL MTPNP_AD_Report_Slave_Need_CHV(void);
/* phone control API */

/* network management interface */
void MTPNP_AD_Set_QOS_Level(ST_MTPNP_QOS_LEVEL level);
MTPNP_BOOL MTPNP_AD_Report_Slave_RX_Level(MTPNP_UINT8 current_band, MTPNP_UINT8 level);
MTPNP_BOOL MTPNP_AD_Report_Slave_Line_Selection_Status(E_MTPNP_AD_LINE_TPYE line);
MTPNP_BOOL MTPNP_AD_Select_Line_Succeed(void);
MTPNP_BOOL MTPNP_AD_Select_Line_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_CallID_Status(E_MTPNP_LOCAL_NUMBER_STATUS status);
MTPNP_BOOL MTPNP_AD_Update_CallID_Succeed(void);
MTPNP_BOOL MTPNP_AD_Update_CallID_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_Network_Lost(void);
MTPNP_BOOL MTPNP_AD_Report_Network_Attach_Failed(void);
MTPNP_BOOL MTPNP_AD_Report_Network_Attach_Succeed(MTPNP_UINT8 * plmn, MTPNP_BOOL home);
MTPNP_BOOL MTPNP_AD_Report_SPN(E_MTPNP_CODING_SCHEME code, MTPNP_CHAR * spn);
/* network management interface */


/* CHV management interface */
extern void MTPNP_AD_Get_SIM_PIN_Status_Request(void);
extern void MTPNP_AD_Update_CHV_Info(ST_SIM_CHV_INFO * chv_info);
extern void MTPNP_AD_Set_SMU_Status(E_MTPNP_AD_SMU_OPERATION status);
extern E_MTPNP_AD_SMU_OPERATION MTPNP_AD_Get_SMU_Status(void);
extern void MTPNP_AD_Set_CHV_Status(E_MTPNP_AD_CHV_STATUS status);
E_MTPNP_AD_CHV_STATUS MTPNP_AD_Get_CHV_Status(void);
extern void MTPNP_AD_CHV_Operation_Rsp(MTPNP_BOOL result);
extern void MTPNP_AD_Report_CHV_Status(void);
extern void MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_UINT8 type);
extern MTPNP_UINT8 MTPNP_AD_Get_SIM_CurrentPassword(void);
/* CHV management interface */

/* phonebook management */
    /*FDN*/
    MTPNP_BOOL MTPNP_AD_FDN_Read_Succeed(MTPNP_UINT16 index,
                                         E_MTPNP_CODING_SCHEME coding_scheme,
                                         MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);
MTPNP_BOOL MTPNP_AD_FDN_readall_finish(MTPNP_UINT8 max_name_len, MTPNP_UINT16 capacity, MTPNP_UINT8 max_number_len);

MTPNP_UINT16 MTPNP_AD_FDN_CombineIndex(const MTPNP_UINT16 Lsb, const MTPNP_UINT16 Msb);
MTPNP_UINT16 MTPNP_AD_FDN_GetIndexFromSDK(const MTPNP_UINT16 index);
MTPNP_UINT16 MTPNP_AD_FDN_GetRecordIndexFromSDK(const MTPNP_UINT16 index);
void MTPNP_AD_FDN_SetOPIndex(MTPNP_UINT16 index);
void MTPNP_AD_FDN_SetCapatity(MTPNP_UINT16 total);
MTPNP_UINT16 MTPNP_AD_FDN_GetCapatity(void);
MTPNP_UINT8 MTPNP_AD_FDN_GetNameLen(void);
void MTPNP_AD_FDN_SetNameLen(MTPNP_UINT8 len);

MTPNP_UINT16 MTPNP_AD_FDN_GetOPIndex(void);
MTPNP_BOOL MTPNP_AD_FDN_Add_Record_Succeed(MTPNP_UINT16 index, MTPNP_UINT16 record_index);
MTPNP_BOOL MTPNP_AD_FDN_FDN_Add_Record_Failed(void);
MTPNP_BOOL MTPNP_AD_FDN_Update_Record_Succeed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_FDN_Update_Record_Failed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Delete_Record_Succeed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Delete_Record_Failed(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Return_STATE_Succeed(MTPNP_UINT8 Status);
MTPNP_BOOL MTPNP_AD_FDN_Return_STATE_Failed(void);
MTPNP_BOOL MTPNP_AD_FDN_Set_STATE_Succeed(void);
MTPNP_BOOL MTPNP_AD_FDN_Set_STATE_Failed(void);
void MTPNP_AD_FDN_SetState(MTPNP_UINT8 state);
MTPNP_UINT8 MTPNP_AD_FDN_GetState(void);
 /*FDN*/
/*phonebook management */
/* SMS management interface */
    MTPNP_BOOL MTPNP_AD_SMS_Begin_Loaded(ST_MTPNP_DATA_SMS_CAPACITY * capacity);
MTPNP_BOOL MTPNP_AD_SMS_Load_Ongoing(ST_MTPNP_AD_SMS_LOAD_ONGOING * sms_index);
MTPNP_BOOL MTPNP_AD_SMS_Load_Finished(ST_MTPNP_DATA_SMS_CAPACITY * capacity);
MTPNP_BOOL MTPNP_AD_SMS_Ready(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Full_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Exceed_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Avail_Indicate(void);
MTPNP_BOOL MTPNP_AD_SMS_Status_Report(ST_MTPNP_AD_SMS_STATUS_REPORT * status);
MTPNP_BOOL MTPNP_AD_SMS_Deliver_New_SMS(ST_MTPNP_AD_DELIVER_SMS * sms);
MTPNP_BOOL MTPNP_AD_SMS_Deliver_App_Data(ST_MTPNP_AD_APP_DATA * data);
ST_MTPNP_AD_SMS_SEND_MSG *MTPNP_AD_Get_SMS_Temp(void);
MTPNP_BOOL MTPNP_AD_Free_SMS_Temp(void);
MTPNP_BOOL MTPNP_AD_SMS_Need_Saved(void);
MTPNP_BOOL MTPNP_AD_SMS_Send_Result(ST_MTPNP_AD_SMS_SEND_RSP * rspSend);
MTPNP_BOOL MTPNP_AD_SMS_Abort_Result(MTPNP_BOOL abort_result);
MTPNP_BOOL MTPNP_AD_SMS_Save_Result(ST_MTPNP_AD_SMS_SAVE_RSP * rspSave);
MTPNP_BOOL MTPNP_AD_SMS_Read_Result(ST_MTPNP_AD_SMS_GET_RSP * sms_record);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Full(E_MTPNP_AD_SMS_MEMORY_FULL type);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Avail(E_MTPNP_AD_SMS_MEMORY_AVAIL type);
MTPNP_BOOL MTPNP_AD_SMS_Memory_Exceed(E_MTPNP_AD_SMS_MEMORY_EXCEED type);
MTPNP_BOOL MTPNP_AD_SMS_Delete_Result(ST_MTPNP_AD_SMS_DEL_RSP * del_result);
MTPNP_BOOL MTPNP_AD_SMS_Copy_Result(ST_MTPNP_AD_SMS_COPY_RSP * copy_rsp);
/* SMS management interface */

/* message setup begin */
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Num_Rsp(ST_MTPNP_AD_SMS_GET_PROFILE_NUM_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Params_Rsp(ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Profile_Params_Rsp(ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Common_Params_Rsp(ST_MTPNP_AD_SMS_GET_COMMON_PARAMS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Common_Params_Rsp(ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Prefer_Storage_Rsp(ST_MTPNP_AD_SMS_GET_PREFER_STORAGE_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Prefer_Storage_Rsp(ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Msg_Num_Rsp(ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_SMS_Msg_Waiting_Ind(ST_MTPNP_AD_SMS_MSG_WAITING_IND * msg_ind);
/* message setup end */

/* call control begin*/
/*cc for framework begin*/
void MTPNP_AD_CC_Init(void);
void MTPNP_AD_CC_Deinit(void);
void MTPNP_AD_CC_CB_Init_Register(void);
/*cc for framework end*/

void MTPNP_AD_SetDialInd(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_GetDialInd(void);

void MTPNP_AD_SetMTCallID(MTPNP_UINT8 value);
MTPNP_UINT8 MTPNP_AD_GetMTCallID(void);

void MTPNP_AD_SetMOCallID(MTPNP_UINT8 value);
MTPNP_UINT8 MTPNP_AD_GetMOCallID(void);

SLAVE_CHLD_TYPE_ENUM MTPNP_AD_GetCHLDType(void);
void MTPNP_AD_SetCHLDType(SLAVE_CHLD_TYPE_ENUM type);

void MTPNP_AD_SetIsNeedSyncCallState(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_GetIsNeedSyncCallState(void);

void MTPNP_AD_Set_Caller_ID(MTPNP_UINT8 callerID);
MTPNP_UINT8 MTPNP_AD_Get_Caller_ID(void);
MTPNP_BOOL MTPNP_AD_Notify_Incoming_Call(ST_MTPNP_DATA_CALL_INFO * MsgStruct);
MTPNP_BOOL MTPNP_AD_ReportMOFailedToMaster(MTPNP_UINT16 ErrorCause);
MTPNP_BOOL MTPNP_AD_SlaveReportCCFailed(MTPNP_UINT16 cause);
MTPNP_BOOL MTPNP_AD_SplictSpecificCallSuc(void);
MTPNP_BOOL MTPNP_AD_EndactiveAndReactivehold(void);
MTPNP_BOOL MTPNP_AD_SSCallWaitRsp(void *msg);
MTPNP_BOOL MTPNP_AD_SSChangePwdRsp(void *msg);
MTPNP_BOOL MTPNP_AD_SSCallBarringRsp(void *msg);
MTPNP_BOOL MTPNP_AD_ReportCFUStatus(ST_MTPNP_AD_CFU_IND * msg);
MTPNP_BOOL MTPNP_AD_ReportSpeechStatus(ST_MTPNP_SPEECH_IND_INFO * msg);
MTPNP_BOOL MTPNP_AD_ReportCCState(void *msg);
void MTPNP_PFAL_CC_DropUSSD(void);
void MTPNP_PFAL_MuteOnSpeech(MTPNP_BOOL on);
/* call control end*/

/* plmn begin */
extern MTPNP_BOOL MTPNP_AD_Get_Select_Mode_Rsp(E_MTPNP_AD_PLMN_MODE mode);
extern MTPNP_BOOL MTPNP_AD_Set_Select_Mode_Rsp(MTPNP_BOOL result);
extern MTPNP_BOOL MTPNP_AD_PLMN_List_Ind(MTPNP_UINT16 num);
extern MTPNP_BOOL MTPNP_AD_NW_Cipher_Ind(MTPNP_BOOL cipher);
extern MTPNP_BOOL MTPNP_AD_Get_Preferred_Network_Rsp(ST_MTPNP_AD_GET_PREFERRED_NETWORK_RSP * network_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_Preferred_Network_Rsp(ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_PLMN_Rsp(ST_MTPNP_AD_SET_PLMN_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Get_PLMN_List_Rsp(ST_MTPNP_AD_GET_PLMN_LIST_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Abort_PLMN_List_Rsp(void);
extern MTPNP_BOOL MTPNP_AD_Report_NITZ(ST_MTPNP_AD_NW_TIME_ZONE_IND *nitz);
/* plmn end */

/* cell broadcast messages begin */
extern MTPNP_BOOL MTPNP_AD_Get_CB_Mode_Rsp(ST_MTPNP_AD_GET_CB_MODE_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_CB_Mode_Rsp(ST_MTPNP_AD_SET_CB_MODE_RSP * set_rsp);
extern MTPNP_BOOL MTPNP_AD_Subscribe_CB_Rsp(MTPNP_BOOL result);
extern MTPNP_BOOL MTPNP_AD_New_CB_Ind(ST_MTPNP_AD_CB_MSG_IND * cb_ind);
/* cell broadcast messages end */

/* voice mail begin */
extern MTPNP_BOOL MTPNP_AD_Get_Mailbox_Info_Rsp(ST_MTPNP_AD_GET_MAILBOX_ADDRESS_RSP * get_rsp);
extern MTPNP_BOOL MTPNP_AD_Set_Mailbox_Address_Rsp(ST_MTPNP_AD_SET_MAILBOX_ADDRESS_RSP * set_rsp);
/* voice mail end */

/* CallHistory begin */
void MTPNP_AD_ReportCallHistoryReady(void);
void MTPNP_AD_ReportCallHistory(MTPNP_AD_RSP_LOAD_CALL_SCT * msg, MTPNP_UINT32 len);
void MTPNP_AD_RspDelCallHistory(MTPNP_AD_RSP_DEL_CALL_SCT * msg);
void MTPNP_AD_RspSetCallHistory(MTPNP_AD_RSP_SET_CALL_SCT * msg);
void MTPNP_AD_RspUpdatePUCT(MTPNP_AD_RSP_RESET_CALLCOST_SCT * msg);
void MTPNP_AD_RspReadPUCT(MTPNP_AD_RSP_READ_CALLCOST_SCT * msg);
void MTPNP_AD_RspReadCCM(MTPNP_AD_RSP_READ_CCM_SCT * msg);

MTPNP_BOOL MTPNP_AD_ACM_Read_Succeed(MTPNP_UINT32 acm);
MTPNP_BOOL MTPNP_AD_ACM_Read_Failed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Read_Succeed(MTPNP_UINT32 acm_max);
MTPNP_BOOL MTPNP_AD_ACMMAX_Read_Failed(void);
MTPNP_BOOL MTPNP_AD_ACM_Delete_Succeed(void);
MTPNP_BOOL MTPNP_AD_ACM_Delete_Failed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Update_Succeed(void);
MTPNP_BOOL MTPNP_AD_ACMMAX_Update_Failed(void);

/* CallHistory end */

/* RF setting */
MTPNP_BOOL MTPNP_AD_Report_RF_Status(MTPNP_BOOL rf);
/* RF setting */

/* engineer/factory mode begin */
extern MTPNP_BOOL MTPNP_AD_FM_Comm_Test_Rsp(void);
/* engineer/factory mode end */
#ifdef __cplusplus
}
#endif
#endif
#endif // __MTPNP_AD_SLAVE_IF_H__
