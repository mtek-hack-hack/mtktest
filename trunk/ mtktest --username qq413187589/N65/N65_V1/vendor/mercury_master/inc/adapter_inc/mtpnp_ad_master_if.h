/***********************************************
File name : MTPNP_AD_master_if.h
Contents : MTPNP adapter master side interface define
History : Create by : Zhang Nan, May 19, 2007
************************************************/
#ifndef __MTPNP_AD_MASTER_IF_H__
#define __MTPNP_AD_MASTER_IF_H__

#include "MTPNP_SDK_master_if.h"
#include "MTPNP_AD_master_common_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define __MTPNP_AD_MASTER__

/* custom data transfer interface */
void MTPNP_CDT_Register(MTPNP_CDT_FuncPtr callbackFunc);
void MTPNP_CDT_Remove(MTPNP_CDT_FuncPtr callbackFunc);
E_MTPNP_DDT_STATUS MTPNP_AD_Direct_Data_Transfer(MTPNP_UINT data_len, MTPNP_UINT8 * data);
/* custom data transfer interface */

/* AT command handler */
MTPNP_BOOL MTPNP_Is_Enable_ATCMD(void);
void MTPNP_ATCMD_Set_Symbol(MTPNP_CHAR symbol);
MTPNP_CHAR *MTPNP_ATCMD_Parse(MTPNP_CHAR * full_cmd_string);
/* remember, the buffer point return MTPNP_ATCMD_Parse should be free manual */
void MTPNP_ATCMD_Free_buffer(MTPNP_CHAR * buffer);
/* AT command handler */

/* virtual EINT transfer interface */
void MTPNP_VEINT_Register(E_MTPNP_PFAL_EINT_NO veint_no, MTPNP_VEINT_FuncPtr callbackFunc);
E_MTPNP_VEINT_STATUS MTPNP_AD_VEINT_Data_Transfer(ST_MTPNP_AD_VEINT_DATA * veint_data);
/* virtual EINT transfer interface */

/* custom config */
extern void MTPNP_AD_Custom_Get_CurrentTime(ST_MTPNP_DATE_TIME * date_time);
extern E_MTPNP_CTRL_SLAVE_MODE MTPNP_AD_Custom_Ctrl_Slave_Mode(void);
extern E_PMU_CTRL_TYPE MTPNP_AD_Custom_PMU_State(void);
extern E_MTPNP_DUALMODE_OPTION MTPNP_AD_Custom_DM_Option(void);
extern MTPNP_BOOL MTPNP_AD_Custom_auto_switch_to_validmode(void);
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_dll_uart(void);
extern E_MTPNP_SDK_UART_DEF MTPNP_AD_Custom_app_uart(void);
extern E_MTPNP_UART_BAUDRATE MTPNP_AD_Custom_dll_start_mode(void);
extern void MTPNP_AD_Custom_Enable_Wakeup_Signal(void);
extern void MTPNP_AD_Custom_Disable_Wakeup_Signal(void);
extern void MTPNP_AD_Custom_Slave_PowerOn(void);
extern void MTPNP_AD_Custom_Slave_PowerOff(void);

extern MTPNP_UINT8 MTPNP_AD_Custom_Get_SignalGrid(void);
extern void MTPNP_AD_Get_SignalLevel(MTPNP_UINT8 grid, MTPNP_UINT8 * level);

#if 0
/* under construction !*/
#endif
/* custom config */

/* Phone control API */
MTPNP_BOOL MTPNP_AD_Get_Revision(ST_MTPNP_AD_VERSION * revision);
MTPNP_BOOL MTPNP_AD_SW_Need_Register(void);
MTPNP_BOOL MTPNP_AD_SW_Register(void);
E_MTPNP_SLAVE_MODULE_TYPE MTPNP_AD_Get_Slave_Type(void);

MTPNP_BOOL MTPNP_AD_Set_QOS_Report_Frequency(const E_MTPNP_QOS_RPT_FREQUENCY frequency);
void MTPNP_AD_Init(void);

MTPNP_BOOL MTPNP_AD_Startup(E_MTPNP_AD_STARTUP_MODE mode);
MTPNP_BOOL MTPNP_AD_Shutdown(E_MTPNP_AD_SHUTDOWN_MODE mode);
MTPNP_BOOL MTPNP_AD_Factory_Restart(void);

void MTPNP_AD_EventHandler(void *MsgHandler);

void MTPNP_AD_Bootup(void);
void MTPNP_AD_Pwnon_Dual_SIM(void);
void MTPNP_AD_Exception_Bootup(void);

E_MTPNP_AD_NVRAM_STATUS MTPNP_AD_Get_Startup_Mode(void);
E_MTPNP_AD_STATUS MTPNP_AD_Get_Status(void);
E_MTPNP_AD_SIMCARD_USABLE_SIDE MTPNP_AD_Get_UsableSide(void);
MTPNP_BOOL MTPNP_AD_Slave_Is_Plugged(void);
MTPNP_BOOL MTPNP_AD_SDK_Is_Startup_Finished(void);
MTPNP_BOOL MTPNP_AD_SDK_Is_PowerOff(void);
MTPNP_BOOL MTPNP_AD_SDK_Is_Shutdown_Finished(void);

void MTPNP_AD_Set_PowerOn_Mode(E_MTPNP_AD_POWERON_MODE mode);
E_MTPNP_AD_POWERON_MODE MTPNP_AD_Get_PowerOn_Mode(void);

E_MTPNP_AD_NVRAM_STATUS MTPNP_AD_Get_DM_Switch_Tmp(void);
void MTPNP_AD_Set_DM_Switch_Tmp(E_MTPNP_AD_NVRAM_STATUS tmp);

MTPNP_BOOL MTPNP_AD_Bootup_Is_Completed(void);
MTPNP_BOOL MTPNP_PFAL_Is_Popup_Card_Removed(void);
MTPNP_BOOL MTPNP_PFAL_Is_FlightMode(void);
MTPNP_BOOL MTPNP_PFAL_Is_Card1Absent(void);
MTPNP_BOOL MTPNP_PFAL_Is_Card2Absent(void);
MTPNP_BOOL MTPNP_PFAL_Is_Card1CHVBlocked(void);
MTPNP_BOOL MTPNP_PFAL_Is_Card2CHVBlocked(void);
MTPNP_BOOL MTPNP_PFAL_Is_InCard1securityCheck(void);
MTPNP_BOOL MTPNP_PFAL_Is_InCard2securityCheck(void);

void MTPNP_AD_During_Mode_Switch(void);
void MTPNP_AD_terminate_Mode_Switch(void);
MTPNP_BOOL MTPNP_AD_Is_During_Mode_Switch(void);
MTPNP_BOOL MTPNP_AD_Is_Enable_Mode_Switch(void);
MTPNP_UINT8 MTPNP_AD_Update_Switch_Table(void);
MTPNP_BOOL MTPNP_AD_Get_Mode_Item(E_MTPNP_AD_NVRAM_STATUS option, MTPNP_INT8 * index);
MTPNP_BOOL MTPNP_AD_Get_Sel_Item(E_MTPNP_AD_NVRAM_STATUS option, MTPNP_INT8 * index);
MTPNP_UINT8 MTPNP_AD_Update_Sel_Table(void);
MTPNP_BOOL MTPNP_AD_Update_DM_Setup(void);

MTPNP_BOOL MTPNP_AD_Is_Need_Switch_Mode(E_MTPNP_AD_STATUS dm_status, 
                                                                                          E_MTPNP_AD_NVRAM_STATUS * new_mode);

/* dual mode switch status mechanism */
E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_AD_Switch_To_DualCard(E_MTPNP_AD_NVRAM_STATUS curr_status);
E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_AD_Switch_To_Card1(E_MTPNP_AD_NVRAM_STATUS curr_status);
E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_AD_Switch_To_Card2(E_MTPNP_AD_NVRAM_STATUS curr_status);
E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_AD_Switch_To_FlightMode(E_MTPNP_AD_NVRAM_STATUS curr_status);
/* dual mode switch status mechanism */

MTPNP_BOOL MTPNP_AD_Enable_Card1_RF(void);
MTPNP_BOOL MTPNP_AD_Disable_Card1_RF(void);
MTPNP_BOOL MTPNP_AD_Enable_Card2_RF(void);
MTPNP_BOOL MTPNP_AD_Disable_Card2_RF(void);

/* master RF control */
void MTPNP_AD_MasterRF_PwrOn_Completed(void);
void MTPNP_AD_MasterRF_PwrOff_Completed(void);
/* master RF control */

/* query power on mode */
void MTPNP_AD_PowerOn_Query_Screen_Need_Duration(void);
void MTPNP_AD_PowerOn_Query_Screen_UnNeed_Duration(void);
MTPNP_BOOL MTPNP_AD_PowerOn_Query_Screen_Is_Need_Duration(void);
/* query power on mode */

void MTPNP_AD_Query_Select_DualCard_Startup(void);
void MTPNP_AD_Query_Select_Card1_Startup(void);
void MTPNP_AD_Query_Select_Card2_Startup(void);
void MTPNP_AD_Query_Select_FlightMode_Startup(void);

extern MTPNP_BOOL MTPNP_PFAL_Master_Is_Cause_Exception_Reboot(void);
extern void MTPNP_PFAL_Entry_PowerOn_Query_Screen(void);

MTPNP_UINT16 MTPNP_AD_Get_Supported_Feature(void);
/* Phone control API */

/* Channel handle */
E_MTPNP_AD_CHANNELS MTPNP_AD_Set_Channel(E_MTPNP_AD_CHANNELS_OWNER owner, E_MTPNP_AD_CHANNELS channel);
E_MTPNP_AD_CHANNELS MTPNP_AD_Get_Channel(E_MTPNP_AD_CHANNELS_OWNER owner);
void MTPNP_AD_Free_Channel(E_MTPNP_AD_CHANNELS_OWNER owner);
/* Channel handle */

/* Network management */
E_MTPNP_AD_RF_STATUS MTPNP_AD_Get_Card1RFStatus(void);
E_MTPNP_AD_RF_STATUS MTPNP_AD_Get_Card2RFStatus(void);

void MTPNP_AD_Set_Card1NetStatus(E_MTPNP_AD_NW_STATUS net_status);
E_MTPNP_AD_NW_STATUS MTPNP_AD_Get_Card1NetStatus(void);
E_MTPNP_AD_NW_STATUS MTPNP_AD_Get_Card2NetStatus(void);
void MTPNP_AD_Set_Card1ServiceType(E_MTPNP_AD_SERVICE_TYPE svr_type);
E_MTPNP_AD_SERVICE_TYPE MTPNP_AD_Get_Card1ServiceType(void);
E_MTPNP_AD_SERVICE_TYPE MTPNP_AD_Get_Card2ServiceType(void);

MTPNP_BOOL MTPNP_AD_Get_Network_ID(MTPNP_UCHAR * plmn);
MTPNP_UINT8 MTPNP_AD_Get_Slave_rssi(void);

void MTPNP_AD_Set_Card1CurrLineID(E_MTPNP_AD_LINE_TPYE line_id);
E_MTPNP_AD_LINE_TPYE MTPNP_AD_Get_Card1CurrLineID(void);
E_MTPNP_AD_LINE_TPYE MTPNP_AD_Get_Card2CurrLineID(void);
MTPNP_BOOL MTPNP_AD_Select_LineID(MTPNP_UINT8 line_id);

MTPNP_BOOL MTPNP_AD_Card2_IsRoam(void);

void MTPNP_AD_Update_Card2_Caller_ID_Status_Tmp(E_MTPNP_LOCAL_NUMBER_STATUS status);
E_MTPNP_LOCAL_NUMBER_STATUS MTPNP_AD_Get_Card2_Caller_ID_Status(void);
void MTPNP_AD_Update_Card2_CallerID_Status(void);

MTPNP_BOOL MTPNP_AD_Get_Slave_IMEI(MTPNP_UINT8 * imei);
/* Network management */

/* CHV management */
void MTPNP_AD_Set_Card1Status(E_MTPNP_AD_SIMCARD_STATUS card_status);
E_MTPNP_AD_SIMCARD_STATUS MTPNP_AD_Get_Card1Status(void);
E_MTPNP_AD_SIMCARD_STATUS MTPNP_AD_Get_Card2Status(void);

MTPNP_BOOL MTPNP_AD_SIM_CHV1_Is_Enable(void);
MTPNP_BOOL MTPNP_AD_SIM_CHV1_Is_Disable(void);
MTPNP_BOOL MTPNP_AD_SIM_CHV1_Blocked(void);
MTPNP_BOOL MTPNP_AD_SIM_CHV1_Need_Verified(void);
MTPNP_BOOL MTPNP_AD_SIM_CHV1_Need_Unblocked(void);
MTPNP_BOOL MTPNP_AD_SIM_Is_PIN1_Verified(void);
void MTPNP_AD_SIM_PIN1_Verified_Finish(void);
MTPNP_BOOL MTPNP_AD_SIM_Is_PIN2_Verified(void);
MTPNP_UINT8 MTPNP_AD_Get_CHV1_Count(void);
MTPNP_UINT8 MTPNP_AD_Get_CHV2_Count(void);
MTPNP_UINT8 MTPNP_AD_Get_UBCHV1_Count(void);
MTPNP_UINT8 MTPNP_AD_Get_UBCHV2_Count(void);
void MTPNP_AD_SIM_PIN_Pwd_Need_Save(void);
void MTPNP_AD_SIM_PIN_Pwd_Unneed_Save(void);
MTPNP_BOOL MTPNP_AD_SIM_PIN_Pwd_Is_Need_Save(void);
MTPNP_BOOL MTPNP_AD_Enable_Close_Card1PIN_Screen(void);
MTPNP_BOOL MTPNP_AD_Enable_Close_Card2PIN_Screen(void);
void MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_AD_FuncPtr funcptr);
MTPNP_AD_FuncPtr MTPNP_AD_Get_CB_CheckPwdLength(void);
void MTPNP_AD_Card2_CHV_Request(void);
void MTPNP_AD_Close_One_Cause_CancelPIN(MTPNP_BOOL card1);
void MTPNP_AD_Close_One_Cause_CancelPUK(MTPNP_BOOL card1);
extern void MTPNP_AD_Validate_CHV(void);
extern void MTPNP_AD_Validate_PUK(MTPNP_CHAR * chv, MTPNP_CHAR * new_chv);
extern void MTPNP_AD_SetSIMLockReq(void);
extern void MTPNP_AD_ReqToChangePwd(MTPNP_CHAR * chv, MTPNP_CHAR * new_chv);
extern void MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_UINT8 type);
extern MTPNP_UINT8 MTPNP_AD_Get_SIM_CurrentPassword(void);
extern void MTPNP_AD_Get_SIM_Status_For_Security(void);
extern void MTPNP_AD_Get_SIM_Status_For_CHV2(void);
extern void MTPNP_AD_Get_SIM_Status_For_Lock(void);
extern void MTPNP_AD_Get_SIM_Status_For_Change(void);
extern void MTPNP_AD_Set_CHV_Pass_CB(MTPNP_AD_FuncPtr funcptr);
extern MTPNP_AD_FuncPtr MTPNP_AD_Get_CHV_Pass_CB(void);
extern void MTPNP_PFAL_Clear_CHV_Input_Pwd(void);
/* CHV management */

/* SMS management */
MTPNP_BOOL MTPNP_AD_Msgbox_Is_Init(void);
void MTPNP_AD_Msgbox_HasInit(void);
void MTPNP_AD_Msgbox_Deinit(void);
MTPNP_BOOL MTPNP_AD_Card2_SMS_Is_Load_Finished(void);
MTPNP_BOOL MTPNP_AD_Card2_SMS_Is_Ready(void);
MTPNP_BOOL MTPNP_AD_Card2_SMS_Is_Avail(void);
MTPNP_BOOL MTPNP_AD_Card2_SMS_Is_Storage_Exceed(void);

MTPNP_BOOL MTPNP_AD_SMS_Is_Recv_From_Card2(void);
void MTPNP_AD_SMS_Recv_From_Card1(void);
void MTPNP_AD_SMS_Recv_From_Card2(void);
MTPNP_BOOL MTPNP_AD_SMS_Report_Status_Is_From_Card2(void);
void MTPNP_AD_SMS_Report_Status_From_Card1(void);
void MTPNP_AD_SMS_Report_Status_From_Card2(void);
MTPNP_BOOL MTPNP_AD_SMS_Send_Is_Through_Card2(void);
void MTPNP_AD_SMS_Send_Through_Card1(void);
void MTPNP_AD_SMS_Send_Through_Card2(void);
void MTPNP_AD_Set_Msgbox_Capacity(MTPNP_UINT16 capacity);
MTPNP_UINT16 MTPNP_AD_Get_Card2_StartIdx_In_Msgbox(void);
void MTPNP_AD_Reset_SMS_Count(E_MTPNP_SMSCOUNT_TYPE smscount_type);
MTPNP_UINT16 MTPNP_AD_Get_SMS_Count(E_MTPNP_SMSCOUNT_TYPE smscount_type);
MTPNP_BOOL MTPNP_AD_Dual_Card_Reply_SMS(void);
MTPNP_BOOL MTPNP_AD_Send_SMS(ST_MTPNP_AD_SMS_SEND_MSG * sms);
MTPNP_BOOL MTPNP_AD_Abort_SMS(void);
MTPNP_BOOL MTPNP_AD_Save_SMS(ST_MTPNP_AD_SMS_SAVE_MSG * sms);
MTPNP_BOOL MTPNP_AD_Get_SMS(MTPNP_UINT16 index, MTPNP_BOOL change_status);
MTPNP_BOOL MTPNP_AD_Delete_SMS(ST_MTPNP_AD_SMS_DEL_REQ * bitmap);
MTPNP_BOOL MTPNP_AD_Copy_SMS(ST_MTPNP_AD_SMS_COPY_REQ * copy_req);

MTPNP_BOOL MTPNP_AD_Index_IsSame_Part(MTPNP_UINT16 idx1, MTPNP_UINT16 idx2);
MTPNP_UINT16 MTPNP_AD_Set_SIM2_Index(MTPNP_UINT16 list_idx);
MTPNP_UINT16 MTPNP_AD_Get_SIM2_Index(MTPNP_UINT16 list_idx);
/* SMS management */

/* sms show begin */
extern void MTPNP_AD_SMS_Set_Show_Style(E_MTPNP_AD_SHOW_STYLE style);
extern E_MTPNP_AD_SHOW_STYLE MTPNP_AD_SMS_Get_Show_Style(void);
extern void MTPNP_AD_SMS_Set_Filter_Rule(E_MTPNP_AD_FILTER_RULE rule);
extern E_MTPNP_AD_FILTER_RULE MTPNP_AD_SMS_Get_Filter_Rule(void);
/* sms show end */

/* phonebook management */
/* card2 onwer number */
MTPNP_BOOL MTPNP_AD_Card2_Owner_Number_Is_Ready(void);
MTPNP_UINT16 MTPNP_AD_Get_Card2_Owner_Number_Count(void);
MTPNP_BOOL MTPNP_AD_Prepare_Card2_Owner_Number(void);
MTPNP_BOOL MTPNP_AD_Active_Owner_Number(E_MTPNP_AD_MSISDN_DISPLAY_OPTION option, MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_Get_Active_Owner_Info(MTPNP_CHAR * info);
MTPNP_UINT8 MTPNP_AD_Get_MSISDN_Name(MTPNP_UINT16 index, MTPNP_UINT8 * name);
MTPNP_UINT8 MTPNP_AD_Get_MSISDN_Number(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_BOOL MTPNP_AD_Update_MSISDN_Record(MTPNP_BOOL is_erase,
                                         E_MTPNP_CODING_SCHEME coding_scheme,
                                         MTPNP_CHAR * name,
                                         MTPNP_CHAR * number, MTPNP_UINT8 TON_NPI, MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_Is_Show_Card2_Owner_Number(void);
void MTPNP_AD_Show_Card2_Owner_Number(void);
void MTPNP_AD_Hide_Card2_Owner_Number(void);
void MTPNP_AD_Update_Show_Owner_Number_Flag(void);
/* card2 onwer number */

 /*ADN*/ 
MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetTagSupport(void);
MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetUCS2LenSupport(void);
void MTPNP_AD_ADN_SIMIncreaseUsedNumber(void);
void  MTPNP_AD_ADN_SIMDecreaseUsedNumber(void);
MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetUsedNumber(void);
MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetTagLen(void);
MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetNumLen(void);
MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetCapacity(void);
MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetNumberSupport(void);
MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetErrorNum(void);
MTPNP_BOOL MTPNP_AD_ADN_SIM2GetFailFlag(void);
void MTPNP_AD_ADN_SIM2SetNumberSupport(MTPNP_UINT16 len);
void MTPNP_AD_ADN_SIM2SetTagSupport(MTPNP_UINT8 len);
MTPNP_BOOL MTPNP_AD_ADN_SIM2_Is_LoadFinished(void);
MTPNP_BOOL MTPNP_AD_ADN_SIM2_PB_DeleteAll(void);

  /*ADN*/
/*FDN*/
MTPNP_UINT16 MTPNP_AD_FDN_GetUsedNumber(void);
MTPNP_UINT16 MTPNP_AD_FDN_GetTotalNumber(void);
MTPNP_UINT8 MTPNP_AD_FDN_GetMaxNameLen(void);
MTPNP_UINT8 MTPNP_AD_FDN_GetMaxNumberLen(void);
MTPNP_UINT16 MTPNP_AD_FDN_GetRecordIndex(MTPNP_UINT16 pos);
MTPNP_UINT8 MTPNP_AD_FDN_GetReady(void);

MTPNP_BOOL MTPNP_AD_FDN_Delete_Record(MTPNP_UINT16 index);
MTPNP_BOOL MTPNP_AD_FDN_Get_STATE(void);
MTPNP_BOOL MTPNP_AD_FDN_Set_STATE(MTPNP_UINT8 state);
MTPNP_BOOL MTPNP_AD_Add_FDN_Record(MTPNP_BOOL is_add,
                                   E_MTPNP_CODING_SCHEME coding_scheme,
                                   MTPNP_CHAR * name, MTPNP_CHAR * number, MTPNP_UINT8 TON_NPI, MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_Get_FDN_Name(MTPNP_UINT16 index, MTPNP_UINT8 * name);
MTPNP_UINT8 MTPNP_AD_Get_FDN_Number(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_UINT8 MTPNP_AD_FDN_GetStatus(void);
 /*FDN*/
/* phonebook management */
/* message setup begin */
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Num_Req(void);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Profile_Params_Req(MTPNP_UINT8 profile_no);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Profile_Params_Req(ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Common_Params_Req(void);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Common_Params_Req(ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_Prefer_Storage_Req(void);
extern MTPNP_BOOL MTPNP_AD_SMS_Set_Prefer_Storage_Req(ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_SMS_Get_MSG_Num_Req(void);
/* message setup end */

/* plmn begin */
extern MTPNP_BOOL MTPNP_AD_Set_Select_Mode_Req(void);
extern void MTPNP_AD_Set_PLMN_Selection_Mode(E_MTPNP_AD_PLMN_MODE mode);
extern E_MTPNP_AD_PLMN_MODE MTPNP_AD_Get_PLMN_Selection_Mode(void);
extern MTPNP_UINT16 MTPNP_AD_Get_NoOfPLMNSupported(void);
extern void MTPNP_AD_Set_NoOfPLMNSupported(MTPNP_UINT16 num);
extern MTPNP_BOOL MTPNP_AD_Get_Preferred_Network_Req(ST_MTPNP_AD_GET_PREFERRED_NETWORK_REQ * get_req);
extern MTPNP_BOOL MTPNP_AD_Set_Preferred_Network_Req(ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_Set_PLMN_Req(ST_MTPNP_AD_SET_PLMN_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_Get_PLMN_List_Req(void);
extern MTPNP_BOOL MTPNP_AD_Abort_PLMN_List_Req(void);
/* plmn end */

/* cell broadcast messages begin */
extern MTPNP_BOOL MTPNP_AD_Get_CB_Mode_Req(void);
extern MTPNP_BOOL MTPNP_AD_Set_CB_Mode_Req(ST_MTPNP_AD_SET_CB_MODE_REQ * set_req);
extern MTPNP_BOOL MTPNP_AD_Subscribe_CB_Req(MTPNP_UINT8 subscribe);
/* cell broadcast messages end */

/* voice mail begin */
extern MTPNP_BOOL MTPNP_AD_Get_Mailbox_Info_Req(void);
extern MTPNP_BOOL MTPNP_AD_Set_Mailbox_Address_Req(ST_MTPNP_AD_SET_MAILBOX_ADDRESS_REQ * set_req);
/* voice mail end */

/* call management */
void MTPNP_AD_CC_SetCallCftOperType(E_MTPNP_AD_CALL_CONFLICT_OPERATE type);
E_MTPNP_AD_CALL_CONFLICT_OPERATE MTPNP_AD_CC_GetCallCftOperType(void);
MTPNP_BOOL MTPNP_AD_CC_IsSlaveCCInIncoming(void);
MTPNP_BOOL MTPNP_AD_CC_IsSlaveCCInOutgoing(void);
MTPNP_BOOL MTPNP_AD_CC_IsSlaveInCall(void);
MTPNP_UINT8 MTPNP_AD_CC_GetTotalActiveCallCount(void);
MTPNP_UINT8 MTPNP_AD_CC_GetTotalCallCount(void);
MTPNP_UINT8 MTPNP_AD_CC_GetTotalHeldCallCount(void);
MTPNP_UINT8 MTPNP_AD_CC_GetTotalActiveAndHoldCallCount(void);
MTPNP_BOOL MTPNP_AD_CC_GetFirstFreeCallIndex(MTPNP_UINT16 * index);
MTPNP_BOOL MTPNP_AD_CC_GetCallIndexbyHandle(MTPNP_UINT8 handle, MTPNP_UINT16 * out);
MTPNP_BOOL MTPNP_AD_GetIncomingCallIndex(MTPNP_UINT16 * index);
MTPNP_BOOL MTPNP_AD_GetOutgoingCallIndex(MTPNP_UINT16 * index);
MTPNP_BOOL MTPNP_AD_GetActiveCallIndex(MTPNP_UINT16 * index);
MTPNP_UINT8 *MTPNP_AD_GetCallLogNum(MTPNP_UINT16 callHandle);
MTPNP_UINT8 *MTPNP_AD_GetCallLogName(MTPNP_UINT16 callHandle);
E_MTPNP_AD_CALL_OPERATION MTPNP_AD_CC_GetCallOper(MTPNP_UINT16 index);
E_MTPNP_AD_CALL_STATE MTPNP_AD_CC_GetCallPrevState(MTPNP_UINT16 index);
void MTPNP_AD_CC_SetCallPrevState(E_MTPNP_AD_CALL_STATE state, MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_CC_GetCallHandle(MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_CC_GetCallType(MTPNP_UINT16 index);
void MTPNP_AD_CC_GetL4cInfo(ST_MTPNP_L4C_NUMBER_STRUCT *L4C_info, MTPNP_UINT16 index);
void MTPNP_AD_CC_SetCallHandle(MTPNP_UINT8 handle, MTPNP_UINT16 index);
ST_MTPNP_AD_SLAVE_CALL_INFO *MTPNP_AD_GetCallInfoByIndex(MTPNP_UINT16 callindex);
void MTPNP_AD_CC_SetCallCurState(E_MTPNP_AD_CALL_STATE state, MTPNP_UINT16 index);
E_MTPNP_AD_CALL_STATE MTPNP_AD_CC_GetCallCurState(MTPNP_UINT16 index);
void MTPNP_AD_CC_SetCurIndex(MTPNP_UINT16 index);
MTPNP_UINT16 MTPNP_AD_CC_GetCurIndex(void);
void MTPNP_AD_CC_SetRelHandle(MTPNP_UINT8 handle);
MTPNP_UINT8 MTPNP_AD_CC_GetRelHandle(void);
void MTPNP_AD_CC_SetCallOldestIndex(MTPNP_UINT8 index);
MTPNP_UINT8 MTPNP_AD_CC_GetCallOldestIndex(void);
void MTPNP_AD_CC_SetActiveCallSlaveNet(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_CC_GetActiveCallSlaveNet(void);
void MTPNP_AD_CC_UpdateCallStateMachine(void);
E_MTPNP_AD_CM_CALL_TYPE MTPNP_AD_CC_GetSlaveCallType(void);
E_MTPNP_AD_DIALBACK_TYPE MTPNP_AD_CC_GetDialBackType(void);
void MTPNP_AD_CC_SetDialBackType(E_MTPNP_AD_DIALBACK_TYPE type);
void MTPNP_AD_Log_MissedCall(ST_MTPNP_AD_SET_CALLLOG * loginfo);
void MTPNP_AD_Log_BlockedCall(ST_MTPNP_AD_SET_CALLLOG * loginfo);
void MTPNP_AD_Log_DialedCall(ST_MTPNP_AD_SET_CALLLOG * loginfo);
void MTPNP_AD_Log_RecvedCall(ST_MTPNP_AD_SET_CALLLOG * loginfo);

void MTPNP_AD_CC_MakeUssdReq(MTPNP_CHAR * InNumber);
void MTPNP_AD_CC_CancelSlaveMOCall(void);
void MTPNP_AD_CC_MakeACall(MTPNP_CHAR * InNumber, MTPNP_CHAR * IPStr);
#ifdef __SAT__
void MTPNP_AD_CC_MakeSATCall(MTPNP_CHAR* InNumber);
#endif /* __SAT__ */
void MTPNP_AD_CC_MakeCSDCall(MTPNP_CHAR* InNumber);
void MTPNP_AD_CC_RejectIncomingCall(void);
void MTPNP_AD_CC_AcceptSlaveIncomingCall(void);
void MTPNP_AD_CC_HangupAllSlaveCall(void);
void MTPNP_AD_CC_HangUpAllCall(void);
void MTPNP_AD_CC_SwitchCall(void);
void MTPNP_AD_CC_EndAllActiveCall(void);
void MTPNP_AD_CC_EndAllHoldCall(void);
void MTPNP_AD_CC_SplitCall(MTPNP_UINT8 handle);
void MTPNP_AD_CC_EndAllExceptIncoming(void);
void MTPNP_AD_CC_CallConference(void);
void MTPNP_AD_CC_EndSingleCall(MTPNP_UINT8 handle);
void MTPNP_AD_CC_EndAllActiveAndRetriveHold(void);
void MTPNP_AD_CC_SetSpeechVolume(MTPNP_UINT8 level);
void MTPNP_AD_CC_SetCallCurrNameLen(MTPNP_UINT16 index, MTPNP_UINT8 length);
MTPNP_UINT8 MTPNP_AD_CC_GetCallCurrNameLen(MTPNP_UINT16 index);
void MTPNP_AD_CC_SetCallCurrName(MTPNP_UINT16 index, MTPNP_UINT8 * name);
void MTPNP_AD_CC_SetCallCurrTime(MTPNP_UINT16 index, ST_MTPNP_AD_TIME * logtime);
void MTPNP_AD_CC_SetCallCurrNum(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_UINT8 *MTPNP_AD_CC_GetCurrCallName(MTPNP_UINT16 index);
MTPNP_UINT8 *MTPNP_AD_CC_GetCurrCallNum(MTPNP_UINT16 index);
E_MTPNP_AD_CALL_OPERATION MTPNP_AD_CC_GetCurrCallType(MTPNP_UINT16 index);
void MTPNP_AD_CC_DropUSSDReq(void);
MTPNP_BOOL MTPNP_AD_CC_Accept_Call(MTPNP_UINT8 callID);
MTPNP_BOOL MTPNP_AD_CC_End_Active_and_Accept_Call(MTPNP_UINT8 callID);
MTPNP_BOOL MTPNP_AD_CC_Hold_Call(void);
MTPNP_BOOL MTPNP_AD_CC_ECT(void);
MTPNP_BOOL MTPNP_AD_CC_Deflect(MTPNP_UINT8* num);
MTPNP_BOOL MTPNP_AD_CC_Retrieve_Held(void);
MTPNP_BOOL MTPNP_AD_CC_End_Active_and_Retrieve_Held(void);
void MTPNP_AD_CC_ConfirmDTMFString( void *MsgStruct);
void MTPNP_AD_CC_SlavePlayConnectTone(MTPNP_UINT16 type);
void MTPNP_AD_CC_DoPlayConnectTone(void);
void MTPNP_AD_CC_AddIndicatorStr(E_MTPNP_AD_CALL_TYPE type, MTPNP_UINT8 * Str);
void MTPNP_AD_CC_SetSlaveRingTwice(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_CC_GetSlaveRingTwice(void);
void MTPNP_AD_CC_SetMasterRingTwice(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_CC_GetMasterRingTwice(void);
void MTPNP_AD_CC_SetReRingIncomingCall(MTPNP_BOOL value);
MTPNP_BOOL MTPNP_AD_CC_GetReRingIncomingCall(void);
void MTPNP_AD_CC_AlterCFTInd(MTPNP_UINT8 alterType);
void MTPNP_AD_CC_Accept_Req_Ind(void *MsgStruct);
MTPNP_UINT8 MTPNP_AD_CC_GetSourceId(void);
void MTPNP_AD_CC_SetSourceId(MTPNP_UINT8 source_id);

/* call management */

//begin CallHistory Related
MTPNP_BOOL MTPNP_AD_SIM2_CallLog_Need_Updated(void);

void MTPNP_AD_DelAllDialedCallHistory(void);
void MTPNP_AD_DelAllMissedCallHistory(void);
void MTPNP_AD_DelAllRecvedCallHistory(void);
void MTPNP_AD_DelAllCallHistory(void);

void MTPNP_AD_LoadCallHistoryReq(MTPNP_AD_REQ_LOAD_CALL_SCT type);
void MTPNP_AD_DelCallHistoryReq(MTPNP_AD_REQ_DEL_CALL_SCT type);
void MTPNP_AD_SetCallHistoryReq(MTPNP_AD_REQ_CALL_RECORD_SCT type);

MTPNP_UINT8 MTPNP_AD_Get_CallHistory_Dialedcall(void);
MTPNP_UINT8 MTPNP_AD_Get_CallHistory_Recvdcall(void);
MTPNP_UINT8 MTPNP_AD_Get_CallHistory_Missedcall(void);
void MTPNP_AD_Set_CallHistory_Dialedcall(MTPNP_UINT8 num);
void MTPNP_AD_Set_CallHistory_Missedcall(MTPNP_UINT8 num);
void MTPNP_AD_Set_CallHistory_Recvdcall(MTPNP_UINT8 num);
void MTPNP_AD_slave_req_read_dialed_num(void);
void MTPNP_AD_slave_req_read_missed_num(void);
void MTPNP_AD_slave_req_read_recvd_num(void);
MTPNP_UINT8 MTPNP_AD_Get_DialedCallHistory_Name(MTPNP_UINT16 index, MTPNP_UINT8 * name);
MTPNP_UINT8 MTPNP_AD_Get_DialedCallHistory_Number(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_UINT8 MTPNP_AD_Get_DialedCallHistory_Name_DCS(MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_Get_RecvdCallHistory_Name(MTPNP_UINT16 index, MTPNP_UINT8 * name);
MTPNP_UINT8 MTPNP_AD_Get_RecvdCallHistory_Number(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_UINT8 MTPNP_AD_Get_RecvdCallHistory_Name_DCS(MTPNP_UINT16 index);
MTPNP_UINT8 MTPNP_AD_Get_MissedCallHistory_Name(MTPNP_UINT16 index, MTPNP_UINT8 * name);
MTPNP_UINT8 MTPNP_AD_Get_MissedCallHistory_Number(MTPNP_UINT16 index, MTPNP_UINT8 * number);
MTPNP_UINT8 MTPNP_AD_Get_MissedCallHistory_Name_DCS(MTPNP_UINT16 index);
void MTPNP_AD_Get_DialedCallHistory_StratTime(MTPNP_UINT16 index, ST_MTPNP_AD_TIME * startTime);
void MTPNP_AD_Get_MissedCallHistory_StratTime(MTPNP_UINT16 index, ST_MTPNP_AD_TIME * startTime);
void MTPNP_AD_Get_RecvdCallHistory_StratTime(MTPNP_UINT16 index, ST_MTPNP_AD_TIME * startTime);
MTPNP_UINT16 MTPNP_AD_Get_DialedCallHistory_no_of_times(MTPNP_UINT16 index);
MTPNP_UINT16 MTPNP_AD_Get_MissedCallHistory_no_of_times(MTPNP_UINT16 index);
MTPNP_UINT16 MTPNP_AD_Get_RecvdCallHistory_no_of_times(MTPNP_UINT16 index);
ST_MTPNP_AD_TIME MTPNP_AD_Get_DialedCallHistory_duration(MTPNP_UINT16 index);
//MTPNP_UINT32 MTPNP_AD_Get_MissedCallHistory_duration(MTPNP_UINT16 index);
ST_MTPNP_AD_TIME MTPNP_AD_Get_RecvdCallHistory_duration(MTPNP_UINT16 index);

void MTPNP_AD_DelDialedCallHistory(MTPNP_UINT8 index);
void MTPNP_AD_DelMissedCallHistory(MTPNP_UINT8 index);
void MTPNP_AD_DelRecvedCallHistory(MTPNP_UINT8 index);
MTPNP_BOOL MTPNP_AD_Calllog_GetIsReady(void);
MTPNP_BOOL MTPNP_AD_Calllog_GetStatus(void);

MTPNP_UINT MTPNP_AD_GetCCM(void);
MTPNP_UINT MTPNP_AD_GetACM(void);
MTPNP_UINT MTPNP_AD_GetACMMAX(void);
double MTPNP_AD_GetPPU(void);
MTPNP_UINT8 *MTPNP_AD_GetPPUCode(void);
MTPNP_UINT8 *MTPNP_AD_GetPPUStr(void);
MTPNP_CHAR MTPNP_AD_GetAOCFinish(void);
MTPNP_CHAR MTPNP_AD_GetAOCError(void);
void MTPNP_AD_CHISTGetAOC(void);
void MTPNP_AD_CHISTResetCallCost(void);
void MTPNP_AD_CHISTResetMaxCost(const MTPNP_UINT32 newMaxCost);
void MTPNP_AD_ResetCallCost_PUCT_Req(MTPNP_AD_REQ_RESET_CALLCOST_SCT * puct);
void MTPNP_AD_DDT_CallCost_Read_CCM_Req(void);
MTPNP_UINT8 MTPNP_AD_Get_MissedCallCount_BeforeView(void);
void MTPNP_AD_Set_MissedCallCount(MTPNP_UINT8 cout);

//end CallHistory Related

/* engineer/factory mode begin */
extern MTPNP_BOOL MTPNP_AD_FM_Comm_Test_Req(void);
extern MTPNP_BOOL MTPNP_AD_FM_Test_Mic_Req(MTPNP_UINT8 on_off);
extern MTPNP_BOOL MTPNP_AD_FM_Test_Speaker_Req(MTPNP_UINT8 on_off);
extern MTPNP_BOOL MTPNP_AD_FM_Test_Receiver_Req(MTPNP_UINT8 on_off);
extern MTPNP_BOOL MTPNP_AD_FM_Test_Headset_Req(MTPNP_UINT8 on_off);
extern MTPNP_BOOL MTPNP_AD_FM_Test_RestoreNormal_Req(void);
/* engineer/factory mode end */

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_AD_MASTER_IF_H__
