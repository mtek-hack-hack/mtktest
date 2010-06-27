/***********************************************************
 * system name	: MTPNP protocol SDK
 * file name	: MTPNP_SDK_if.h
 * contents		: MTPNP SDK common interface definition for master side
 *				:	of communication module
 * History		: Feb 23, 2006: Created by HYU
 ***********************************************************/
 
#ifndef _MTPNP_SDK_MASTER_IF_H_
#define _MTPNP_SDK_MASTER_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "MTPNP_SDK_common_if.h"

#define _MTPNP_SDK_MASTER_

typedef enum
{
	/* Directly Data Transfer */
	MTPNP_MSG_DDT_IND,					/* Directly Data Transfer indication */
	
	/* Module Management */
	MTPNP_MSG_MM_SLAVE_STARTUP_FINISH,	/* Slave Module Startup successful finished */
	MTPNP_MSG_MM_SLAVE_STARTUP_SIM_CARD_ABSENT,	/* Slave Module Startup finished without SIM card */
	MTPNP_MSG_MM_SLAVE_STARTUP_CHV1_REQUESTED,	/* Slave Module Startup request CHV1 verification */
	MTPNP_MSG_MM_SLAVE_SHUTDOWN_NOW,	/* Shutdown Slave module Now */
	MTPNP_MSG_MM_MSISDN_READALL_FINISHED,	/* Read slave's own numbers finished */
	MTPNP_MSG_MM_MSISDN_READALL_ONGOING,	/* Read slave's own numbers ongoing */
	MTPNP_MSG_MM_MSISDN_READALL_ERROR,		/* Error occurred during Reading slave's own numbers */
	MTPNP_MSG_MM_MSISDN_UPDATE_RECORD_SUCCEED,	/* Update slave's own numbers succeed */
	MTPNP_MSG_MM_MSISDN_UPDATE_RECORD_FAILED,	/* Update slave's own numbers failed */
	MTPNP_MSG_MM_PB_NEED_LOAD,				/* SIM PhoneBook of slave module need load */
	MTPNP_MSG_MM_PB_READ_RECORD_SUCCEED,	/* Read SIM phonebook record succeed */
	MTPNP_MSG_MM_PB_READ_RECORD_FAILED,		/* Read SIM phonebook record failed or read an empty record */
	MTPNP_MSG_MM_PB_READALL_FINISHED,		/* Read all valid records from SIM phonebook finished */
	MTPNP_MSG_MM_PB_READALL_ONGOING,		/* Read all valid records from SIM phonebook ongoing */
	MTPNP_MSG_MM_PB_READALL_ERROR,			/* Error occurred during Read all valid records from SIM phonebook */
	MTPNP_MSG_MM_PB_ADD_RECORD_SUCCEED,		/* Add SIM phonebook record succeed */
	MTPNP_MSG_MM_PB_ADD_RECORD_FAILED,		/* Add SIM phonebook record failed */
	MTPNP_MSG_MM_PB_UPDATE_RECORD_SUCCEED,	/* Update SIM phonebook record succeed */
	MTPNP_MSG_MM_PB_UPDATE_RECORD_FAILED,	/* Update SIM phonebook record failed */
	MTPNP_MSG_MM_PB_DELETE_RECORD_SUCCEED,	/* Delete SIM phonebook record succeed */
	MTPNP_MSG_MM_PB_DELETE_RECORD_FAILED,	/* Delete SIM phonebook record failed */
	MTPNP_MSG_MM_PB_DELETEALL_ERROR,		/* Error occurred during Delete all valid records from SIM phonebook */
	MTPNP_MSG_MM_PB_DELETEALL_FINISHED,		/* Delete all valid records from SIM phonebook finished */
	MTPNP_MSG_MM_SMS_NEED_LOAD,				/* SIM SMS of slave module need load */
	MTPNP_MSG_MM_SMS_READ_RECORD_SUCCEED,	/* Read SIM SMS record succeed */
	MTPNP_MSG_MM_SMS_READ_RECORD_FAILED,	/* Read SIM SMS record failed or read an empty record */
	MTPNP_MSG_MM_SMS_READALL_FINISHED,		/* Read all valid records from SIM SMS finished */
	MTPNP_MSG_MM_SMS_READALL_ONGOING,		/* Read all valid records from SIM SMS ongoing */
	MTPNP_MSG_MM_SMS_READALL_ERROR,			/* Error occurred during Read all valid records from SIM SMS */
	MTPNP_MSG_MM_SMS_ADD_RECORD_SUCCEED,	/* Add SIM SMS record succeed */
	MTPNP_MSG_MM_SMS_ADD_RECORD_FAILED,		/* Add SIM SMS record failed */
	MTPNP_MSG_MM_SMS_UPDATE_RECORD_SUCCEED,	/* Update SIM SMS record succeed */
	MTPNP_MSG_MM_SMS_UPDATE_RECORD_FAILED,	/* Update SIM SMS record failed */
	MTPNP_MSG_MM_SMS_DELETE_RECORD_SUCCEED,	/* Delete SIM SMS record succeed */
	MTPNP_MSG_MM_SMS_DELETE_RECORD_FAILED,	/* Delete SIM SMS record failed */
	MTPNP_MSG_MM_SMS_DELETEALL_ERROR,		/* Error occurred during Delete all valid records from SIM SMS */
	MTPNP_MSG_MM_SMS_DELETEALL_FINISHED,	/* Delete all valid records from SIM SMS finished */
	MTPNP_MSG_MM_SMS_SET_STATUS_REPORT_SUCCEED,	/* Set status report succeed */
	MTPNP_MSG_MM_SMS_SET_STATUS_REPORT_FAILED,	/* Set status report failed */
	MTPNP_MSG_MM_SMS_SET_REPLY_PATH_SUCCEED,	/* Set reply path succeed */
	MTPNP_MSG_MM_SMS_SET_REPLY_PATH_FAILED,		/* Set reply path failed */
	MTPNP_MSG_MM_SMS_RSP_GET_STATUS_REPORT,		/* Response of getting status report */
	MTPNP_MSG_MM_SMS_RSP_GET_REPLY_PATH,		/* Response of getting reply path */
	MTPNP_MSG_MM_SMS_RSP_REPORT_STATUS_REPORT,	/* Report status report to Master */
	MTPNP_MSG_MM_READY_FOR_WRITE_CFGDATA,		/* Target phone is ready to write config data */
	MTPNP_MSG_MM_WRITE_CFGDATA_SUCCEED,			/* Write configure data succeed */
	MTPNP_MSG_MM_WRITE_CFGDATA_FAILED,			/* Write configure data failed */
////	MTPNP_MSG_MM_SET_SLAVE_RF_FINISHED,			/* Set slave RF status on/off finished */
	MTPNP_MSG_MM_GET_RF_STATUS,					/* Report current RF status of slave module */
	MTPNP_MSG_MM_ISR_OCCURRED,					/* Report ISR occurred in slave module */
	MTPNP_MSG_MM_SLAVE_IMEI_IND,				/* Indicate IMEI of slave module */
	MTPNP_MSG_MM_SLAVE_IMSI_IND,				/* Indicate IMSI of slave module */

	/* SIM Management */
	MTPNP_MSG_SIM_CARD_STATUS_IND,			/* Indication SIM VERIFY CHV status */
	MTPNP_MSG_SIM_CHV_VERIFY_SUCCEED,		/* SIM VERIFY CHV succeed */
	MTPNP_MSG_SIM_CHV_VERIFY_FAILED,		/* SIM VERIFY CHV failed */
	MTPNP_MSG_SIM_CHV_UNBLOCK_SUCCEED,		/* SIM UNBLOCK CHV succeed */
	MTPNP_MSG_SIM_CHV_UNBLOCK_FAILED,		/* SIM UNBLOCK CHV failed */
	MTPNP_MSG_SIM_CHV_CHANGE_SUCCEED,		/* SIM CHANGE CHV succeed */
	MTPNP_MSG_SIM_CHV_CHANGE_FAILED,		/* SIM CHANGE CHV failed */
	MTPNP_MSG_SIM_CHV1_ENABLE_SUCCEED,		/* SIM ENABLE CHV1 succeed */
	MTPNP_MSG_SIM_CHV1_ENABLE_FAILED,		/* SIM ENABLE CHV1 failed */
	MTPNP_MSG_SIM_CHV1_DISABLE_SUCCEED,		/* SIM DISABLE CHV1 succeed */
	MTPNP_MSG_SIM_CHV1_DISABLE_FAILED,		/* SIM DISABLE CHV1 failed */
	MTPNP_MSG_SIM_EF_SMSP_READALL_ONGOING,	/* Read Slave's smsp record ongoing */
	MTPNP_MSG_SIM_EF_SMSP_READALL_ERROR,	/* Read slave's smsp records failed */
	MTPNP_MSG_SIM_EF_SMSP_READALL_FINISHED,	/* Read slave's smsp records finished */
	MTPNP_MSG_SIM_EF_SMSP_UPDATE_RECORD_SUCCEED,	/* Update slave's smsp records succeed */
	MTPNP_MSG_SIM_EF_SMSP_UPDATE_RECORD_FAILED,	/* Update slave's smsp records failed */
	MTPNP_MSG_SIM_EF_OPN_LOADED,			/* Indicate EFopn info */
	MTPNP_MSG_SIM_EF_SPN_LOADED,			/* Indicate EFspn info */
	MTPNP_MSG_SIM_EF_ACM_READ_SUCCEED,		/* Read ACM succeed */
	MTPNP_MSG_SIM_EF_ACM_READ_FAILED,		/* Read ACM failed */
	MTPNP_MSG_SIM_EF_ACMMAX_UPDATE_SUCCEED,		/* Update ACMMAX succeed */
	MTPNP_MSG_SIM_EF_ACMMAX_UPDATE_FAILED,		/* Update ACMMAX failed */
	MTPNP_MSG_SIM_EF_ACM_DELETE_SUCCEED,			/* Delete ACM succeed */
	MTPNP_MSG_SIM_EF_ACM_DELETE_FAILED,			/* Delete ACM failed */
	MTPNP_MSG_SIM_EF_PUCT_UPDATE_SUCCEED,			/* Update PUCT succeed */
	MTPNP_MSG_SIM_EF_PUCT_UPDATE_FAILED,			/* Update PUCT failed */
	MTPNP_MSG_SIM_EF_ACMMAX_READ_SUCCEED,		/* Read ACMMAX succeed */
	MTPNP_MSG_SIM_EF_ACMMAX_READ_FAILED,		/* Read ACMMAX failed */
	MTPNP_MSG_SIM_EF_PUCT_READ_SUCCEED,		/* Read PUCT succeed */
	MTPNP_MSG_SIM_EF_PUCT_READ_FAILED,		/* Read PUCT failed */
	MTPNP_MSG_SIM_EF_ECC_READ_SUCCEED,		/* Read ECC succeed */
	MTPNP_MSG_SIM_EF_ECC_READ_FAILED,		/* Read ECC failed */
	MTPNP_MSG_SIM_EF_FDN_READALL_FINISHED,		/* Read all valid records from EFfdn finished */
	MTPNP_MSG_SIM_EF_FDN_READALL_ONGOING,		/* Read all valid records from EFfdn ongoing */
	MTPNP_MSG_SIM_EF_FDN_READALL_ERROR,			/* Error occurred during Read all valid records from EFfdn */
	MTPNP_MSG_SIM_EF_FDN_ADD_RECORD_SUCCEED,	/* Add EFfdn record succeed */
	MTPNP_MSG_SIM_EF_FDN_ADD_RECORD_FAILED,		/* Add EFfdn record failed */
	MTPNP_MSG_SIM_EF_FDN_DELETE_RECORD_SUCCEED,	/* Delete EFfdn record succeed */
	MTPNP_MSG_SIM_EF_FDN_DELETE_RECORD_FAILED,	/* Delete EFfdn record failed */
	MTPNP_MSG_SIM_EF_FDN_UPDATE_RECORD_SUCCEED,	/* Update EFfdn record succeed */
	MTPNP_MSG_SIM_EF_FDN_UPDATE_RECORD_FAILED,	/* Update EFfdn record failed */
	MTPNP_MSG_SIM_EF_FDN_READ_STATE_SUCCEED,	/* Read state of EFfdn succeed */
	MTPNP_MSG_SIM_EF_FDN_READ_STATE_FAILED,		/* Read state of EFfdn failed */
	MTPNP_MSG_SIM_EF_FDN_SET_STATE_SUCCEED,		/* Set state of EFfdn succeed */
	MTPNP_MSG_SIM_EF_FDN_SET_STATE_FAILED,		/* Set state of EFfdn failed */
	MTPNP_MSG_SIM_EF_SST_READ_STATE_SUCCEED,	/* Read state of EFsss succeed */
	MTPNP_MSG_SIM_EF_SST_READ_STATE_FAILED,		/* Read state of EFsss failed */
	MTPNP_MSG_SIM_EF_SST_UPDATE_STATE_SUCCEED,	/* Update state of EFsss succeed */
	MTPNP_MSG_SIM_EF_SST_UPDATE_STATE_FAILED,		/* Update state of EFsss failed */
	/* Call Control */
	MTPNP_MSG_CC_MT_CALL,					/* Incoming call request */
	MTPNP_MSG_CC_MT_SMS,					/* Incoming SMS request */
	MTPNP_MSG_CC_MO_CALL_PROCEEDING,		/* MO-Call is accepted by network */
	MTPNP_MSG_CC_MO_CALL_FAILED,			/* MO-Call is failed due to network reason */
	MTPNP_MSG_CC_SMS_SENT_SUCCEED,			/* MO-SMS is accepted by network */
	MTPNP_MSG_CC_SMS_SENT_FAILED,				/* MO-SMS is failed due to network reason */
	MTPNP_MSG_CC_SWITCH_CALL_SUCCEED,		/* Switch call succeed */
	MTPNP_MSG_CC_SWITCH_CALL_FAILED,		/* Switch call failed */
	MTPNP_MSG_CC_JOIN_CALL_SUCCEED,			/* Join call succeed */
	MTPNP_MSG_CC_JOIN_CALL_FAILED,			/* Join call failed */
	MTPNP_MSG_CC_SPLIT_CALL_SUCCEED,		/* Split call succeed */
	MTPNP_MSG_CC_SPLIT_CALL_FAILED,			/* Split call failed */
	MTPNP_MSG_CC_CALL_RELEASED,				/* Call is released */
	MTPNP_MSG_CC_CALL_ALERTING,				/* Alert indication during MO-Call */
	MTPNP_MSG_CC_CALL_CONNECTED,			/* Call is connected (accepted by peer side or host) */
	MTPNP_MSG_CC_NET_STATUS,				/* Indicate current network status */
	MTPNP_MSG_CC_QOS_INDICATION,			/* Indicate current QOS value */
	MTPNP_MSG_CC_LOCAL_NUMBER_STATUS_INDICATION,	/* Report current send/hide local number status of slave module */
	MTPNP_MSG_CC_SET_LOCAL_NUMBER_SUCCEED,			/* Set send/hide local number succeed */
	MTPNP_MSG_CC_SET_LOCAL_NUMBER_FAILED,			/* Set send/hide local number failed */
	MTPNP_MSG_CC_LINE_SELECTION_STATUS_INDICATION,	/* Report current line selection status of slave module */
	MTPNP_MSG_CC_SELECT_LINE_SUCCEED,		/* Select line operation succeed */
	MTPNP_MSG_CC_SELECT_LINE_FAILED,		/* Select line operation failed */

	/* Supplementary Services */
	MTPNP_MSG_SS_RSP_CFD_SUCCEED,			/* Response Call Forward succeed */
	MTPNP_MSG_SS_RSP_CFD_FAILED,			/* Response Call Forward failed */
    MTPNP_MSG_SS_RSP_AOCI,					/* Report AOCI information */
    
	/* Debug info from slave side */
	MTPNP_MSG_MISC_IND_DBG_INFO,		/* Slave debug info indication */

	/* Link Error Handler */
	MTPNP_MSG_DATALINK_ERROR,				/* Indicate communication link error occurred */

	/* End of Async message */
	MTPNP_MSG_MAX
} E_MTPNP_ASYNC_MSG;

typedef struct
{
	E_MTPNP_SDK_UART_DEF uart_no;	/* Indicate which uart will be used for MT-PNP communication with slave module */
	E_MTPNP_UART_BAUDRATE baud_rate;/* Indicate which baud rate should be used */
	MTPNP_UINT8 QOS_display_grid;	/* Indicate how many grid will be used for display signal strength of slave module */
	MTPNP_UINT8 RCV_gain;			/* Indicate default receiver gain value in DB of slave module */
} ST_MTPNP_SDK_INIT_DATA;

/********************************************************************
* SDK basic management functions
********************************************************************/
MTPNP_BOOL MTPNP_SDK_Startup(const E_MTPNP_STARTUP_MODE mode, const ST_MTPNP_SDK_INIT_DATA * p);
MTPNP_BOOL MTPNP_Register_Callback(const E_MTPNP_ASYNC_MSG msgId, MTPNP_BOOL (*func)(void *));
MTPNP_BOOL MTPNP_Append_Callback(const E_MTPNP_ASYNC_MSG msgId, MTPNP_BOOL (*func)(void *));
MTPNP_BOOL MTPNP_Insert_Callback(const E_MTPNP_ASYNC_MSG msgId, MTPNP_BOOL (*func)(void *));
MTPNP_BOOL MTPNP_Remove_All_Callback(const E_MTPNP_ASYNC_MSG msgId);
MTPNP_BOOL MTPNP_Remove_Callback(const E_MTPNP_ASYNC_MSG msgId, MTPNP_BOOL (*func)(void *));
MTPNP_BOOL MTPNP_Request_Slave_Startup(const E_MTPNP_SLAVE_STARTUP_MODE mode);
E_MTPNP_SLAVE_STATUS MTPNP_Get_Slave_Status(void);
E_MTPNP_SLAVE_MODULE_TYPE MTPNP_Get_Slave_Type(void);
MTPNP_UINT8 * MTPNP_Get_Slave_Version(void);
MTPNP_BOOL MTPNP_Set_Date_Time(const ST_MTPNP_DATE_TIME * curr_datetime);
/********************************************************************
* SDK Interface functions
********************************************************************/
MTPNP_BOOL MTPNP_Is_Coding_Scheme_Supported(const E_MTPNP_CODING_SCHEME coding_scheme);
MTPNP_BOOL MTPNP_Prepare_Shutdown(const E_MTPNP_SLAVE_SHUTDOWN_MODE mode);
MTPNP_BOOL MTPNP_Set_Mic_Gain(const MTPNP_UINT8 mic_gain_db);
MTPNP_BOOL MTPNP_Set_Receiver_Gain(const MTPNP_UINT8 rcv_gain_db);
MTPNP_BOOL MTPNP_CHV_Get_Status(void);
MTPNP_BOOL MTPNP_CHV_Req_Change(const ST_MTPNP_DATA_CHANGE_CHV_INFO * CHV_info);
MTPNP_BOOL MTPNP_CHV1_Req_Enable(const MTPNP_UINT8 * CHV_value);
MTPNP_BOOL MTPNP_CHV1_Req_Disable(const MTPNP_UINT8 * CHV_value);
MTPNP_BOOL MTPNP_CHV_Req_Verify(const ST_MTPNP_DATA_CHV_VALUE * CHV_value);
MTPNP_BOOL MTPNP_CHV_Req_Unblock(const ST_MTPNP_DATA_CHANGE_CHV_INFO * CHV_info);


MTPNP_BOOL MTPNP_EF_SMSP_Readall(void);
MTPNP_BOOL MTPNP_EF_SMSP_Update_Record(const ST_MTPNP_DATA_SMSP_RECORD_INFO * SMS_info);
MTPNP_BOOL MTPNP_EF_MSISDN_Readall(void);
MTPNP_BOOL MTPNP_EF_MSISDN_Update_Record(const ST_MTPNP_DATA_MSISDN_RECORD_INFO * MSISDN_info);
MTPNP_BOOL MTPNP_PB_Read_Record(const ST_MTPNP_DATA_STORAGE_W_IDX index_info);
MTPNP_BOOL MTPNP_PB_Readall(const E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_PB_Deleteall(const E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_PB_Delete_Record(const ST_MTPNP_DATA_STORAGE_W_IDX index_info);
MTPNP_BOOL MTPNP_PB_Update_Record(const ST_MTPNP_DATA_PB_RECORD_INFO * PB_info);
MTPNP_BOOL MTPNP_PB_Add_Record(const ST_MTPNP_DATA_PB_RECORD_INFO * PB_info);

MTPNP_BOOL MTPNP_SMS_Read_Record(const ST_MTPNP_DATA_STORAGE_W_IDX index_info);
MTPNP_BOOL MTPNP_SMS_Readall(const E_MTPNP_STORAGE_TYPE storage);
MTPNP_BOOL MTPNP_SMS_Deleteall(const E_MTPNP_STORAGE_TYPE storage, const E_MTPNP_SMS_STATUS SMS_type);
MTPNP_BOOL MTPNP_SMS_Delete_Record(const ST_MTPNP_DATA_STORAGE_W_IDX index_info);
MTPNP_BOOL MTPNP_SMS_Update_Record(const ST_MTPNP_DATA_SMS_INFO * SMS_info);
MTPNP_BOOL MTPNP_SMS_Add_Record(const ST_MTPNP_DATA_SMS_INFO * SMS_info);
MTPNP_BOOL MTPNP_SMS_Set_Status_Report(const MTPNP_BOOL enabled);
MTPNP_BOOL MTPNP_SMS_Set_Reply_Path(const MTPNP_BOOL enabled);
MTPNP_BOOL MTPNP_SMS_Get_Status_Report(void);
MTPNP_BOOL MTPNP_SMS_Get_Reply_Path(void);

MTPNP_BOOL MTPNP_EF_ACM_Read(void);
MTPNP_BOOL MTPNP_EF_ACMMAX_Update(const MTPNP_UINT32  ACMMAX_info);
MTPNP_BOOL MTPNP_EF_ACM_Delete(void);
MTPNP_BOOL MTPNP_EF_PUCT_Update(const ST_MTPNP_DATA_PUCT_RECORD_INFO *puct_info);
MTPNP_BOOL MTPNP_EF_ACMMAX_Read(void);
MTPNP_BOOL MTPNP_EF_PUCT_Read(void);
MTPNP_BOOL MTPNP_EF_FDN_Read_STATE(void);
MTPNP_BOOL MTPNP_EF_FDN_Set_STATE(MTPNP_UINT8 state);
MTPNP_BOOL MTPNP_EF_FDN_Readall(void);
MTPNP_BOOL MTPNP_EF_FDN_Add_Record(const ST_MTPNP_DATA_FDN_RECORD_INFO * FDN_info);
MTPNP_BOOL MTPNP_EF_FDN_Delete_Record(const MTPNP_UINT16 record_idx);
MTPNP_BOOL MTPNP_EF_FDN_Update_Record(const ST_MTPNP_DATA_FDN_RECORD_INFO * FDN_info);
MTPNP_BOOL MTPNP_EF_ECC_Read(void);
MTPNP_BOOL MTPNP_EF_SST_Read_STATE(E_MTPNP_SST_TYPE type);
MTPNP_BOOL MTPNP_EF_SST_Update_STATE(ST_MTPNP_DATA_SST_STATE sst_info);
MTPNP_BOOL MTPNP_Set_QOS_Report_Frequency(const E_MTPNP_QOS_RPT_FREQUENCY frequency);
MTPNP_BOOL MTPNP_Get_Local_Number_Status(void);
MTPNP_BOOL MTPNP_Set_Local_Number_Status(const E_MTPNP_LOCAL_NUMBER_STATUS status);
MTPNP_BOOL MTPNP_Get_Slave_IMEI(void);
MTPNP_BOOL MTPNP_Get_Slave_IMSI(void);
MTPNP_BOOL MTPNP_Get_Line_Selection_Status(void);
MTPNP_BOOL MTPNP_Select_Line(const MTPNP_UINT8 line_no);
MTPNP_BOOL MTPNP_Set_Slave_RF(const MTPNP_BOOL on_off);
MTPNP_BOOL MTPNP_Set_Audio_Loopback(const MTPNP_BOOL on_off);
MTPNP_BOOL MTPNP_Get_Slave_RF_Status(void);
MTPNP_BOOL MTPNP_Set_Audio_Loopback(const MTPNP_BOOL on_off);
MTPNP_BOOL MTPNP_read_EF_SPN(void);
MTPNP_BOOL MTPNP_Make_Phone_Call(const ST_MTPNP_DATA_CALL_INFO * number_info);
MTPNP_BOOL MTPNP_SMS_Send(const ST_MTPNP_DATA_SMS_INFO * sms_info);
MTPNP_BOOL MTPNP_Hang_Up_Call(const MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_Accept_Call(const MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_Reject_Call(const MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_Switch_Call(void);
MTPNP_BOOL MTPNP_Join_Call(void);
MTPNP_BOOL MTPNP_Split_Call(const MTPNP_UINT8 call_id);
MTPNP_BOOL MTPNP_Send_DTMF(const MTPNP_CHAR DTMF);
MTPNP_BOOL MTPNP_Play_Minutes_Notify(void);
MTPNP_BOOL MTPNP_Play_Call_Waiting_Notify(void);
#if 0
/* under construction !*/
#endif

/********************************************************************
* Fixed callback functions
********************************************************************/

/* Notify incompatible module is plug-in */
void MTPNP_FCB_Notify_Incompatible_Module(void);

/* Register callback handler for all MT-PNP asynchronous message */
void MTPNP_FCB_Reg_All_Async_Msg_Handler(ST_MTPNP_SLAVE_MODULE_INFO * info);

/* Enable slave module's power supply */
void MTPNP_FCB_Enable_Slave_Module_Power(void);

/* Disable slave module's power supply */
void MTPNP_FCB_Disable_Slave_Module_Power(void);


#ifdef __cplusplus
}
#endif

#endif

