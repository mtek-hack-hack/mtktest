#ifndef __MTPNP_PFAL_MASTER_IF_H__
#define __MTPNP_PFAL_MASTER_IF_H__

#include "MTPNP_AD_master_if.h"
#include "MTPNP_PFAL_master_Def.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* MTPNP PFAL event ID */
typedef enum
{
    /* Register software */
    MTPNP_PFAL_MSG_STARTREG,
    /* Register software */

    /* Phone control */
    MTPNP_PFAL_MSG_SLAVE_PLUGIN,
    MTPNP_PFAL_MSG_SLAVE_START_FINISHED,
    /* Phone control */
    
    /* NETWORK */
    MTPNP_PFAL_MSG_NETWORK_ATTACH_IND,
    MTPNP_PFAL_MSG_OPN_LOADED,
    MTPNP_PFAL_MSG_SPN_LOADED,
    MTPNP_PFAL_MSG_QOS_IND,
    /* NETWORK */

    /* verify SIM */
    MTPNP_PFAL_MSG_VERIFY_SIM1,
    MTPNP_PFAL_MSG_VERIFY_SIM2,
    /* verify SIM */

    /* RF */
    MTPNP_PFAL_PWRON_MASTER_RF,
    MTPNP_PFAL_PWROFF_MASTER_RF,
    /* RF */

    /* MSISDN */
    MTPNP_PFAL_MSG_MSISDN_LOAD_FINISHED_IND,
    MTPNP_PFAL_MSG_MSISDN_LOAD_FAIL_IND,
    MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP,
    MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP,
    /* MSISDN */

    MTPNP_PFAL_MSG_SMS_STARTUP_READ_BEGIN_IND,
    MTPNP_PFAL_MSG_SMS_STARTUP_READ_FINISH_IND,
    MTPNP_PFAL_MSG_SMS_STARTUP_READ_GOING_IND,
    MTPNP_PFAL_MSG_SMS_READY_IND,

    MTPNP_PFAL_MSG_SMS_SEND_MSG_SUCCEED,
    MTPNP_PFAL_MSG_SMS_SEND_MSG_FAILED,
    MTPNP_PFAL_MSG_SMS_SEND_ABORT_START_IND,
    MTPNP_PFAL_MSG_SMS_SEND_ABORT_FINISH_IND,

    MTPNP_PFAL_MSG_SMS_SET_MSG_RSP,

    MTPNP_PFAL_MSG_SMS_NEW_SMS_IND,
    MTPNP_PFAL_MSG_SMS_APP_DATA_IND,

    MTPNP_PFAL_MSG_SMS_SEND_MSG_REQ,

    MTPNP_PFAL_MSG_SMS_GET_MSG_RSP,

    MTPNP_PFAL_MSG_SMS_DEL_MSG_RSP,
    MTPNP_PFAL_MSG_SMS_COPY_MSG_RSP,

    MTPNP_PFAL_MSG_SMS_STATUS_REPORT_IND,
    MTPNP_PFAL_MSG_SMS_MEM_FULL_IND,
    MTPNP_PFAL_MSG_SMS_MEM_AVAILABLE_IND,
    MTPNP_PFAL_MSG_SMS_MEM_EXCEED_IND,

    /* message setup begin */
    MTPNP_PFAL_MSG_SMS_GET_PROFILE_NUM_RSP,
    MTPNP_PFAL_MSG_SMS_SET_PROFILE_PARAMS_RSP,
    MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP,
    MTPNP_PFAL_MSG_SMS_SET_COMMON_PARAMS_RSP,
    MTPNP_PFAL_MSG_SMS_GET_COMMON_PARAMS_RSP,
    MTPNP_PFAL_MSG_SMS_GET_PREFERRED_STORAGE_RSP,
    MTPNP_PFAL_MSG_SMS_SET_PREFERRED_STORAGE_RSP,
    MTPNP_PFAL_MSG_SMS_GET_MSG_NUM_RSP,
    MTPNP_PFAL_MSG_SMS_MSG_WAITING_IND,
    /* message setup end */

    /* plmn begin */
    MTPNP_PFAL_MSG_NW_GET_PLMN_LIST_RSP,
    MTPNP_PFAL_MSG_NW_SET_PLMN_RSP,
    MTPNP_PFAL_MSG_NW_ABORT_PLMN_LIST_RSP,
    MTPNP_PFAL_MSG_NW_SET_PLMN_SELECT_MODE_RSP,
    MTPNP_PFAL_MSG_GET_PREFERRED_NETWORKS_RSP,
    MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP,
    MTPNP_PFAL_MSG_NW_TIME_ZONE_IND,
    /* plmn end */

    /* cell broadcast messages begin */
    MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP,
    MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP,
    MTPNP_PFAL_MSG_CB_SUBSCRIBE_RSP,
    MTPNP_PFAL_MSG_CB_MSG_IND,
    /* cell broadcast messages end */

    /* voice mail begin */
    MTPNP_PFAL_MSG_SMS_GET_MAILBOX_ADDRESS_RSP,
    MTPNP_PFAL_MSG_SMS_SET_MAILBOX_ADDRESS_RSP,
    /* voice mail end */

    /*call control begin */
    MTPNP_PFAL_MSG_CC_SHOW_OUTGOINGSRC_IND,
    MTPNP_PFAL_MSG_CC_CLOSE_OUTGOINGSRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_INCOMINGSRC_IND,
    MTPNP_PFAL_MSG_CC_CLOSE_INCOMINGSRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_ACTIVESRC_IND,
    MTPNP_PFAL_MSG_CC_CLOSE_ACTIVESRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_USSDSRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_USSDNOTSUPPORTSRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_AOCSRC_IND,
    MTPNP_PFAL_MSG_CC_SHOW_SWAPSUCCESS_IND,
    MTPNP_PFAL_MSG_CC_SHOW_CONFSUCCESS_IND,
    MTPNP_PFAL_MSG_CC_SHOW_SPLITSUCCESS_IND,
    MTPNP_PFAL_MSG_CC_SHOW_ERRMESSAGE_IND,
    MTPNP_PFAL_MSG_CC_OUTGOINGCALL_ALTER_IND,
    MTPNP_PFAL_MSG_CC_OUTGOINGCALL_PROCEEDING_IND,
    MTPNP_PFAL_MSG_CC_LOG_MISSED_IND,
    MTPNP_PFAL_MSG_CC_LOG_DIALED_IND,
    MTPNP_PFAL_MSG_CC_LOG_RECED_IND,
    MTPNP_PFAL_MSG_CC_MAKECALLERR_IND,
    MTPNP_PFAL_MSG_CC_SHOW_CALLFORWARD_RSP,
    MTPNP_PFAL_MSG_CC_SHOW_CALLWAITING_RSP,
    MTPNP_PFAL_MSG_CC_SHOW_CALLBARRING_RSP,
    MTPNP_PFAL_MSG_CC_SHOW_CFU_STATUS,
    MTPNP_PFAL_MSG_CC_SHOW_SPEECH_STATUS,
    MTPNP_PFAL_MSG_CC_SHOW_CALLCHANGEPWD_RSP,
    MTPNP_PFAL_MSG_CC_CALLINCOMING_IND,
    MTPNP_PFAL_MSG_CC_MO_FIALED_IND,
    /*call control end */

    /* Engineer Mode */
    MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_SUCCEED,
    MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_FAILED,
    MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_SUCCEED,
    MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_FAILED,
    MTPNP_PFAL_MSG_FM_COMMTEST_RSP,
    /* Engineer Mode */

    MTPNP_PFAL_EVENT_MAX,
    MTPNP_PFAL_EVENT_TOTAL = MTPNP_PFAL_EVENT_MAX
} E_MTPNP_PFAL_EVENT;
/* MTPNP PFAL event ID */

/* dual mode switch*/
extern void DualModeSwitchComplete(void);
extern void DualModeSwitchFailed(void);
/* dual mode switch */

/* call management */
extern void MTPNP_PFAL_CC_USSD_Abort_Rsp(ST_MTPNP_AD_CC_RESULT * msgbuf);
extern void MTPNP_PFAL_CC_USSR_IND(ST_MTPNP_AD_CC_USSR_IND * msgbuf);
extern void MTPNP_PFAL_CC_USSN_IND(ST_MTPNP_AD_CC_USSN_IND * msgbuf);
extern void MTPNP_PFAL_CC_USSD_Rsp(ST_MTPNP_AD_CC_USSD_RSP * msgbuf);

extern void MTPNP_PFAL_CC_StopPlayAlterTone(void);
extern MTPNP_BOOL MTPNP_PFAL_CC_GetEarphonePluggin(void);
extern void MTPNP_PFAL_CC_SetSpeechMode(MTPNP_UINT8 mode);
extern MTPNP_UINT8 MTPNP_PFAL_CC_GetSpeechMode(void);
extern void MTPNP_PFAL_CC_SetInitSpeechVolume(MTPNP_UINT8 mode);
extern MTPNP_UINT8 MTPNP_PFAL_CC_GetModeSpeechVolume(MTPNP_UINT8 mode);
extern void MTPNP_AD_MuteOnSpeech(MTPNP_BOOL on);
extern void MTPNP_PFAL_CC_SetUnknownToNum(MTPNP_CHAR * number);
extern void MTPNP_PFAL_CC_HandleSpeechDisConnected(void);
extern void MTPNP_PFAL_CC_RefreshCurWin(void);
extern void MTPNP_PFAL_CC_ReportCCState(void *msgbuf);
extern void MTPNP_PFAL_CC_NotifyRetrieveSuccess(void);
extern void MTPNP_PFAL_CC_StopAutoAnsTimer(void);
extern void MTPNP_PFAL_CC_SetRedialNum(void);
extern void MTPNP_PFAL_CC_ShowScrError(void);
extern E_MTPNP_AD_CALL_ALTER MTPNP_PFAL_CC_HandleSlaveIncomingCall(void);
extern MTPNP_BOOL MTPNP_PFAL_CC_IsInCall(void);
extern void MTPNP_PFAL_DropCFTMOCall(void);
extern MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInIdle(void);
extern MTPNP_BOOL MTPNP_PFAL_CC_IsBlockSlaveIncoming(void);
extern MTPNP_BOOL MTPNP_PFAL_CC_IsBlockMasterIncoming(void);
/* call management */

/* CHV MTK platform abstract interface */
extern void MTPNP_PFAL_Entry_Card2_Blocked(MTPNP_UINT8 type);
extern void MTPNP_PFAL_Entry_IncorrectPIN(MTPNP_UINT8 type);
extern void MTPNP_PFAL_Entry_IncorrectPUK(MTPNP_UINT8 type);
extern void MTPNP_PFAL_Entry_EnterPIN(void);
extern void MTPNP_PFAL_Entry_UnblockPIN(void);
extern void MTPNP_PFAL_Exit_PINblocked(void);
extern void MTPNP_PFAL_Entry_EnterPUK(void);
extern void MTPNP_PFAL_Delete_ScreenBeforeUnblockPIN(void);
extern void MTPNP_PFAL_ClearAllKeyHandler(void);
extern void MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc(MTPNP_UINT8 * text, MTPNP_UINT8 * cursor, MTPNP_INT length);
extern void MTPNP_PFAL_SettingPukValidation(MTPNP_UINT8 * text, MTPNP_UINT8 * cursor, MTPNP_INT length);
extern void MTPNP_PFAL_FillCountDownString(E_MTPNP_AD_SECURITYTYPE tpyeofpass, MTPNP_UINT8 * passcountdowndisp);
extern void MTPNP_PFAL_ShowMakeSOSCallScreen(void);
extern void MTPNP_PFAL_Entry_SIM2_Verified_Screen(void);
extern void MTPNP_PFAL_Show_Invalid_CHV_Length(void);
extern void MTPNP_PFAL_Entry_EnterNewPIN_1st(void);
extern void MTPNP_PFAL_Entry_EnterNewPIN_2nd(void);
extern void MTPNP_PFAL_Validate_1stAnd2ndPIN(void);
extern void MTPNP_PFAL_Entry_PIN_NotMatch(void);
extern void MTPNP_PFAL_Entry_Unblock_Verified_Screen(void);
extern void MTPNP_PFAL_Unblock_Verified_Timerout(void);
extern MTPNP_BOOL MTPNP_PFAL_Get_CHV_Value(MTPNP_CHAR * chv_value);
extern void MTPNP_PFAL_SECSETSetSIMLockRsp(MTPNP_BOOL result);
extern void MTPNP_PFAL_CHV_Change_Failed(MTPNP_UINT8 type);
extern void MTPNP_PFAL_CHV_Change_Succeed(MTPNP_UINT8 type);
extern void MTPNP_PFAL_Entry_UnblockPIN2(void);
extern void MTPNP_PFAL_Entry_CHV_Change(MTPNP_UINT8 type);
extern void MTPNP_PFAL_Entry_CHV1_Lock(void);
extern void MTPNP_PFAL_Entry_CHV2_Status_Rsp(void);
extern void MTPNP_PFAL_Entry_Card2_Security(void);
extern void MTPNP_PFAL_Entry_Card2_Not_Support(void);
/* CHV MTK platform abstract interface */

/* event & msg and so on platform abstract interface */
void MTPNP_PFAL_Send_Msg_To_App(const void *pData, const MTPNP_UINT16 len);
void MTPNP_PFAL_MMI_Send_Msg_To_MMI(MTPNP_UINT32 message_id, void *peerbuf, void *localbuf);
void MTPNP_PFAL_Start_Timer(MTPNP_UINT16 timer_id, MTPNP_UINT32 delay, MTPNP_AD_FuncPtr funcptr);
void MTPNP_PFAL_Stop_Timer(MTPNP_UINT16 timer_id);
MTPNP_BOOL MTPNP_PFAL_Set_sys_Info(ST_MTPNP_AD_SYS_ID * sys_id);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_Task_Mod(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MMI_Task_Mod(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_Data_Msg_ID(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_DLL_Resume_Msg_ID(void);
MTPNP_UINT16 MTPNP_PFAL_Get_MTPNP_AD_Restart_TimerID(void);

extern void MTPNP_PFAL_Send_Msg_To_Queue(void *message);
extern void *MTPNP_PFAL_Malloc_Local_Buffer(MTPNP_UINT32 size);
extern void MTPNP_PFAL_Free_Local_Buffer(void *data);

void MTPNP_PFAL_Register_Event_Handler(MTPNP_UINT16 eventID, MTPNP_EVENTHANDLER_FuncPtr funcptr);
void MTPNP_PFAL_Remove_Event_Handler(MTPNP_UINT16 eventID);
/* event & msg and so on platform abstract interface */

/* idle screen platform abstract interface */
void MTPNP_PFAL_Entry_Idlescreen(void);
void MTPNP_PFAL_Entry_CardErrscreen(void);
void MTPNP_PFAL_Entry_CardBlockdscreen(void);
void MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea(void);

void MTPNP_PFAL_Set_Show_OPN(MTPNP_BOOL b);
MTPNP_BOOL MTPNP_PFAL_Is_Show_OPN(void);
MTPNP_BOOL MTPNP_PFAL_Is_Show_OwnerName(void);

extern void MTPNP_PFAL_SetIdleScreenNetworkName(MTPNP_UCHAR * s);
extern void MTPNP_PFAL_SetIdleScreenNetworkStatus(MTPNP_UCHAR * s);
extern void MTPNP_PFAL_RefreshNwProviderName(MTPNP_UCHAR * plmn);
extern MTPNP_UINT8 MTPNP_PFAL_Card2_Get_User_Defined_Max_Owner_Number_Length(void);

extern void MTPNP_PFAL_Empty_Slave_IdleField(void);
extern void MTPNP_PFAL_Show_Idle_Card2_DuringClose(void);
extern void MTPNP_PFAL_Show_Idle_NW_Register(void);
extern void MTPNP_PFAL_Show_NetWorkFlag(void);
extern void MTPNP_PFAL_Show_Idle_NW_Noservice(void);
extern void MTPNP_PFAL_Show_Idle_NW_Manual(void);
extern void MTPNP_PFAL_Show_Idle_NW_Limitservice(void);
extern void MTPNP_PFAL_Show_Idle_Card2Absent(void);
extern void MTPNP_PFAL_Show_Idle_Card2Blocked(void);
extern void MTPNP_PFAL_Show_Idle_Card2Closed(void);
extern void MTPNP_PFAL_Show_Idle_OwnerName(void);
extern void MTPNP_PFAL_Show_Idle_OPN(void);
extern void MTPNP_PFAL_Show_Idle_SPN(void);
extern void MTPNP_PFAL_Show_Idle_Card1Absent(void);
extern void MTPNP_PFAL_Show_Idle_Card1Blocked(void);
extern void MTPNP_PFAL_Show_Idle_Card1Closed(void);

extern MTPNP_BOOL MTPNP_PFAL_Is_InIdlescreen(void);
extern MTPNP_BOOL MTPNP_PFAL_Is_InSIMErrorscreen(void);
extern void MTPNP_PFAL_Entry_Idle_From_SIM_error(void);
/* idle screen platform abstract interface */

/* menu platform abstract interface */
/* MENU RESOURCE */
void MTPNP_PFAL_Hide_Menu(MTPNP_UINT16 menu_id);
void MTPNP_PFAL_Show_Menu(MTPNP_UINT16 menu_id);
void MTPNP_PFAL_Set_MenuHiliteHandler(MTPNP_UINT16 menu_id, MTPNP_AD_FuncPtr funcptr);
void MTPNP_PFAL_Set_MenuHintHandler(MTPNP_UINT16 menu_id, MTPNP_AD_FuncPtr funcptr);
/* MENU RESOURCE */

extern void MTPNP_PFAL_Rearrange_MenuItem(void);
extern void MTPNP_PFAL_Hide_AllCard2_MenuItemEntry(void);
/* menu platform abstract interface */

/* status bar platform abstract interface */
/* IMAGE RESOURCE */
void MTPNP_PFAL_Hide_StatusICON(MTPNP_INT16 icon_id);
void MTPNP_PFAL_Show_StatusICON(MTPNP_INT16 icon_id);
void MTPNP_PFAL_Replace_StatusICON(MTPNP_INT16 icon_id, MTPNP_UINT16 image_id);
void MTPNP_PFAL_Blink_StatusICON(MTPNP_UINT16 icon_id);
void MTPNP_PFAL_Refresh_StatusBar(void);
void MTPNP_PFAL_Update_SlaveQOS(MTPNP_UCHAR level);
void MTPNP_PFAL_Set_Current_Slave_Signal_ID(MTPNP_INT16 icon_id);
/* IMAGE RESOURCE */

extern void MTPNP_PFAL_Rearrange_StatusBar(void);
extern void MTPNP_PFAL_Update_Slave_Cipher_Icon(MTPNP_BOOL cipher);
/* status bar platform abstract interface */

/* string platform abstract interface */
void MTPNP_PFAL_Replace_MenuStrID(MTPNP_UINT16 menu_id, MTPNP_UINT16 string_id);
void MTPNP_PFAL_Get_String(MTPNP_UINT16 string_id);
/* string platform abstract interface */

/* utility interface */
MTPNP_INT MTPNP_PFAL_Unicode_String_Length(const MTPNP_CHAR * str);
MTPNP_CHAR *MTPNP_PFAL_Unicode_String_Copy(MTPNP_CHAR * dest, const MTPNP_CHAR * src);
MTPNP_CHAR *MTPNP_PFAL_Unicode_Memory_Copy(MTPNP_CHAR * dest, const MTPNP_CHAR * src, MTPNP_UINT32 len);
MTPNP_CHAR *MTPNP_PFAL_Unicode_Strcat(MTPNP_CHAR * dest, const MTPNP_CHAR * src);
MTPNP_UINT16 MTPNP_PFAL_Ansii_To_Unicode_String(MTPNP_CHAR * dest, MTPNP_CHAR * src);
MTPNP_UINT16 MTPNP_PFAL_Unicode_To_Ansii_String(MTPNP_CHAR * dest, MTPNP_CHAR * src);
MTPNP_INT MTPNP_PFAL_Decode_GSM7bit(MTPNP_UINT8 * inBuffer,
                                    MTPNP_UINT8 * outBuffer,
                                    MTPNP_UINT8 inBufferLength,
                                    MTPNP_INT outBufferSize,
                                    MTPNP_INT UCS2_count, MTPNP_INT GSM_ext_count, MTPNP_UINT8 flag);
MTPNP_INT MTPNP_PFAL_Encode_GSM7bit(MTPNP_UINT8 * inBuffer,
                                    MTPNP_UINT8 * outBuffer,
                                    MTPNP_INT outBufferSize,
                                    MTPNP_INT UCS2_count, MTPNP_INT GSM_ext_count, MTPNP_UINT8 flag);
MTPNP_UINT8 MTPNP_PFAL_digit_to_BCD(MTPNP_UINT8 * source, MTPNP_UINT8 * dest, MTPNP_UINT8 max_dest_len);
MTPNP_UINT8 MTPNP_PFAL_DCB_to_digit(MTPNP_UINT8 * source, MTPNP_UINT8 * dest);
/* utility interface */

/* nvram platform abstract interface */
MTPNP_BOOL MTPNP_PFAL_Set_nvram_Info(ST_MTPNP_AD_NVRAM_ID * nvram_id);
/* nvram platform abstract interface */

/* network platform abstract interface */
extern void MTPNP_PFAL_Get_Master_IMEI(MTPNP_UINT8 * imei);
extern void MTPNP_PFAL_MMSRomaingIndication(MTPNP_UCHAR card2_roaming);
extern void MTPNP_PFAL_Line_Switching_Succeed(void);
extern void MTPNP_PFAL_Line_Switching_Failed(void);
extern void MTPNP_PFAL_CallID_Update_Succeed(void);
extern void MTPNP_PFAL_CallID_Update_Failed(void);
/* network platform abstract interface */

/* phonebook platform abstract interface */
extern void MTPNP_PFAL_ADN_HandleReadSuccessEntry(ST_MTPNP_DATA_PB_RECORD_INFO * info);
extern MTPNP_BOOL MTPNP_PFAL_ADN_HandleNeedLoad(ST_MTPNP_DATA_PB_CAPACITY * info);
extern MTPNP_BOOL MTPNP_PFAL_ADN_IsNeedHandlePBLoad(void);
extern void MTPNP_PFAL_ADN_HandleAddSuccess(MTPNP_UINT16 index, MTPNP_UINT16 name_length);
extern void MTPNP_PFAL_ADN_HandleEditSuccess(MTPNP_UINT16 index, MTPNP_UINT16 name_length);
extern void MTPNP_PFAL_ADN_HandleDelSuccess(MTPNP_UINT16 index);
extern void MTPNP_PFAL_ADN_HandleEditFail(MTPNP_UINT16 fail_cause);
extern void MTPNP_PFAL_ADN_HandleDelFail(MTPNP_UINT16 index);
extern void MTPNP_PFAL_ADN_HandleDelAllOneAfterOneSuccess(void *data);
extern void MTPNP_PFAL_ADN_HandleDelAllAbort(void);
extern void MTPNP_PFAL_ADN_HandleAddFail(MTPNP_UINT16 fail_cause);
extern void MTPNP_PFAL_ADN_HandleDelAllSuccess(void);
extern void MTPNP_PFAL_ADN_HandleAllFail(MTPNP_UINT16 DelTotal, MTPNP_UINT16 index);
extern void MTPNP_PFAL_ADN_HandleUnload(void);
extern void MTPNP_PFAL_ADN_HandleLoadFinish(void);
extern void MTPNP_PFAL_ADN_GetSpeedDialInfo(void);
extern void MTPNP_PFAL_ADN_HandleSlaveUnload(void);
#if 0
/* under construction !*/
#endif
void MTPNP_PFAL_FDN_ShowSetStateSuccess(void);
void MTPNP_PFAL_FDN_ShowSetStateFailed(void);
void MTPNP_PFAL_FDN_SetNewOpIndex(MTPNP_UINT16 index);
void MTPNP_PFAL_FDN_ShowAddSuccess(void);
void MTPNP_PFAL_FDN_ShowUpdateSuccess(void);
void MTPNP_PFAL_FDN_ShowDelSuccess(void);
void MTPNP_PFAL_FDN_ShowFailed(void);
void MTPNP_PFAL_FDN_HandleReadSuccessEntry(ST_MTPNP_DATA_FDN_RECORD_INFO * info);
MTPNP_UINT16 MTPNP_PFAL_FDN_GetOPIndex(void);

 /* phonebook platform abstract interface */

/* sms platform abstract interface */
extern void MTPNP_PFAL_SMS_Init_Msgbox(void);
extern void MTPNP_PFAL_Unpack_SMS(MTPNP_UINT8 dcs, MTPNP_UINT8 fo, MTPNP_UINT8 ori_dcs);
extern void MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_BOOL blink, MTPNP_BOOL unblink);
extern void MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_BOOL blink, MTPNP_BOOL unblink);
extern void MTPNP_PFAL_Add_SMS_To_List(void *data, MTPNP_UINT16 index);

extern MTPNP_BOOL MTPNP_PFAL_Card1_SMS_Is_Avail(void);

extern MTPNP_BOOL MTPNP_PFAL_Read_SMS_Segment(void);
extern void MTPNP_PFAL_Card1_Read_SMS_Rsp(void *in_msg);
 /*CALLLOG*/ extern void MTPNP_PFAL_CC_SetMissNotify(void);
extern void MTPNP_PFAL_CC_ShowCard2MissIcon(void);
extern void MTPNP_PFAL_CC_HideCard2MissIcon(void);
void MTPNP_PFAL_Delete_Calllog_Success(void);
void MTPNP_PFAL_Delete_Calllog_Failed(void);
void MTPNP_PFAL_Delete_DialedCalllog_Success(void);
void MTPNP_PFAL_Delete_MissedCalllog_Success(void);
void MTPNP_PFAL_Delete_RecvedCalllog_Success(void);
void MTPNP_PFAL_Delete_DialedCalllog_Failed(void);
void MTPNP_PFAL_Delete_MissedCalllog_Failed(void);
void MTPNP_PFAL_Delete_RecvedCalllog_Failed(void);
void MTPNP_PFAL_Delete_AllCalllogs_Success(void);

void MTPNP_PFAL_handle_GetAOCFinish(void);
void MTPNP_PFAL_handle_DelAOCSuccess(void);
void MTPNP_PFAL_handle_DelAOCFailed(void);
void MTPNP_PFAL_Show_CAI_processing(void);
MTPNP_UINT MTPNP_PFAL_handle_UpdateACMMAXSuccess(void);
void MTPNP_PFAL_handle_UpdateACMMAXFailed(void);
void MTPNP_PFAL_handle_ReadError(void);
//void  MTPNP_PFAL_handle_UpdatePUCTSuccess(void);
//void  MTPNP_PFAL_handle_UpdatePUCTFailed(void);
void MTPNP_PFAL_Update_PUCT_handler_Success(void);
void MTPNP_PFAL_Update_PUCT_handler_Unavaialable(void);
void MTPNP_PFAL_Update_PUCT_handler_Failed(void);
void MTPNP_PFAL_CHISTGetAOC(void);
double MTPNP_PFAL_Get_CAI_TempPPU(void);
MTPNP_CHAR *MTPNP_PFAL_Get_CAI_TempCuCode(void);
void MTPNP_PFAL_Read_PUCT_handler_Success(void);

 /*CALLLOG*/
/* Engineer Mode */
void MTPNP_PFAL_Operate_Slave(void);
void MTPNP_PFAL_Operate_Master(void);
MTPNP_BOOL MTPNP_PFAL_Is_Operate_Slave(void);
MTPNP_BOOL MTPNP_AD_Get_Audio_Profile(MTPNP_UINT8 mode);
MTPNP_BOOL MTPNP_AD_Set_Audio_Profile(ST_MTPNP_AD_AUDIO_PROFILE * prifile);
MTPNP_BOOL MTPNP_PFAL_EM_Assert_Slave(void);
/* Engineer Mode */

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_PFAL_MASTER_IF_H__
