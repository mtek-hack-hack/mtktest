#ifndef __MTPNP_PFAL_SLAVE_IF_H__
#define __MTPNP_PFAL_SLAVE_IF_H__

#include "MTPNP_AD_slave_if.h"
#include "MTPNP_PFAL_Gemini_Def.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* event & msg and so on platform abstract interface */
void MTPNP_PFAL_Send_Msg_To_App(const void *pData, const MTPNP_UINT16 len);
void MTPNP_PFAL_MMI_Send_Msg_To_MMI(MTPNP_UINT32 message_id, void *peerbuf, void *localbuf);
void MTPNP_PFAL_Start_Timer(MTPNP_UINT16 timer_id, MTPNP_UINT32 delay, MTPNP_AD_FuncPtr funcptr);
void MTPNP_PFAL_Stop_Timer(MTPNP_UINT16 timer_id);
MTPNP_BOOL MTPNP_PFAL_Set_sys_Info(ST_MTPNP_AD_SYS_ID * sys_id);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_Task_Mod(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MMI_Task_Mod(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_Data_Msg_ID(void);
MTPNP_UINT32 MTPNP_PFAL_Get_MTPNP_Startup_Req_Msg_ID(void);

extern void MTPNP_PFAL_Send_Msg_To_Queue(void *message);
extern void *MTPNP_PFAL_Malloc_Local_Buffer(MTPNP_UINT32 size);
extern void MTPNP_PFAL_Free_Local_Buffer(void *data);
/* event & msg and so on platform abstract interface */

/* get code version */
extern MTPNP_UINT8 *MTPNP_PFAL_Get_Slave_ExtVersion(void);
/* get code version */

/* get imei */
extern void MTPNP_PFAL_Get_Slave_IMEI(MTPNP_UINT8 * imei);
/* get imei */

/* network inferface */
extern void MTPNP_PFAL_Select_line(const E_MTPNP_AD_LINE_TPYE line);
extern void MTPNP_PFAL_Update_Clir(const E_MTPNP_AD_CLIR clir);
/* network inferface */

/* owner number */
extern void MTPNP_PFAL_MSISDN_ReadAll(void);
extern void MTPNP_PFAL_MSISDN_Erase(MTPNP_UINT16 index);
extern void MTPNP_PFAL_MSISDN_Edit(MTPNP_UINT16 index,
                                   E_MTPNP_CODING_SCHEME coding_scheme,
                                   MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);
/* owner number */
MTPNP_BOOL MTPNP_PFAL_ADN_ADD(MTPNP_UINT16 index,
                              E_MTPNP_CODING_SCHEME coding_scheme,
                              MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);

MTPNP_BOOL MTPNP_PFAL_ADN_EDIT(MTPNP_UINT16 index,
                               E_MTPNP_CODING_SCHEME coding_scheme,
                               MTPNP_UINT8 * name, MTPNP_UINT8 TON_NPI, MTPNP_UINT8 * number);
void MTPNP_PFAL_ADN_DELETE(MTPNP_UINT16 index, MTPNP_BOOL deleteall);

extern void MTPNP_AD_ADN_SetOpIndex(MTPNP_UINT16 index);
extern MTPNP_UINT16 MTPNP_PFAL_ADN_GetNextValidIndex(MTPNP_UINT16 Begin);

 /*FDN*/ void MTPNP_PFAL_FDN_AddRecord(ST_MTPNP_DATA_FDN_RECORD_INFO * info);
void MTPNP_PFAL_FDN_UpdateRecord(ST_MTPNP_DATA_FDN_RECORD_INFO * info);
void MTPNP_PFAL_FDN_DeleteRecord(MTPNP_UINT16 index);
void MTPNP_PFAL_FDN_GetCapatictyReq(void);
void MTPNP_PFAL_FDN_read_state(void);
void MTPNP_PFAL_FDN_set_state(MTPNP_UINT8 Status);

 /*FDN*/
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

/*call control begin*/
extern MTPNP_BOOL MTPNP_PFAL_Make_Call(ST_MTPNP_DATA_CALL_INFO * info);
extern MTPNP_BOOL MTPNP_PFAL_Reject_Incoming_Call(MTPNP_UINT8 call_id);
extern MTPNP_BOOL MTPNP_PFAL_Accept_Incoming_Call(MTPNP_UINT8 call_id);
extern MTPNP_BOOL MTPNP_PFAL_End_Active_and_Accept_Incoming_Call(MTPNP_UINT8 call_id);
extern MTPNP_BOOL MTPNP_PFAL_End_Active_and_Retrieve_Held_Call(void);
extern void MTPNP_PFAL_ConfirmDTMF(MTPNP_UINT8 *MsgStruct);
extern MTPNP_BOOL MTPNP_PFAL_Switch_Call(void *pMsg);
extern MTPNP_BOOL MTPNP_PFAL_ECT(void *pMsg);
extern MTPNP_BOOL MTPNP_PFAL_Deflect(MTPNP_UINT8 * pMsg);
extern MTPNP_BOOL MTPNP_PFAL_Join_Call(void *pMsg);
extern MTPNP_BOOL MTPNP_PFAL_Send_DTMF(MTPNP_UINT8 * digit);
extern MTPNP_BOOL MTPNP_PFAL_Play_Tone(void *pMsg);     /*sdk */
extern MTPNP_BOOL MTPNP_PFAL_Set_Local_Number_Status(MTPNP_UINT8 status);
extern MTPNP_BOOL MTPNP_PFAL_EndAllActiveCall(void);
extern MTPNP_BOOL MTPNP_PFAL_EndAllHoldCall(void);
extern MTPNP_BOOL MTPNP_PFAL_EndAllExceptIncomingCall(void);
extern MTPNP_BOOL MTPNP_PFAL_SplictSpecificCall(MTPNP_UINT8 callID);
extern MTPNP_BOOL MTPNP_PFAL_EndSpecific_call(unsigned char handle);
extern MTPNP_BOOL MTPNP_PFAL_EndActiveAndReactiveHold(void);
extern void MTPNP_PFAL_EndAllCall(void);
extern void MTPNP_PFAL_CancleMOBeforeDialInd(void);
extern void MTPNP_PFAL_CC_PlayConnetTone(MTPNP_UINT16 toneID);  /*ddt */
extern void MTPNP_PFAL_CC_SetSpeechModeNormal(void);
extern void MTPNP_PFAL_CC_SetSpeechModeHeadset(void);
extern void MTPNP_PFAL_CC_SetSpeechModeHandfree(void);
extern void MTPNP_PFAL_CC_SetSpeechModeBtNormal(void);
extern void MTPNP_PFAL_CC_SetSpeechModeResumeBtNormal(void);
extern void MTPNP_PFAL_CC_SetSpeechVolume(MTPNP_UINT8 volume);
/*call control end*/
/* chv interface begin*/
extern void MTPNP_PFAL_Get_CHV_Status_Req(void);
extern void MTPNP_PFAL_Verify_CHV_Req(ST_MTPNP_DATA_CHV_VALUE * chv_value);
extern void MTPNP_PFAL_Unblock_CHV_Req(ST_MTPNP_DATA_CHANGE_CHV_INFO * chv_info);
extern void MTPNP_PFAL_Change_CHV_Req(ST_MTPNP_DATA_CHANGE_CHV_INFO * chv_info);
extern void MTPNP_PFAL_Lock_CHV1_Req(ST_MTPNP_DATA_CHV_VALUE * chv_value, MTPNP_BOOL is_enable);
/* chv interface end*/

/* message setup begin */
extern void MTPNP_PFAL_SMS_Get_Profile_Num(void);
extern void MTPNP_PFAL_SMS_Get_Profile_Params(MTPNP_UINT8 profile_no);
extern void MTPNP_PFAL_SMS_Set_Profile_Params(ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ * set_req);
extern void MTPNP_PFAL_SMS_Get_Common_Params(void);
extern void MTPNP_PFAL_SMS_Set_Common_Params(ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_REQ * set_req);
extern void MTPNP_PFAL_SMS_Get_Prefer_Storage(void);
extern void MTPNP_PFAL_SMS_Set_Prefer_Storage(ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_REQ * set_req);
extern void MTPNP_PFAL_SMS_Get_Msg_Num(void);
/* message setup end */

/* SMS */
extern void MTPNP_PFAL_Send_SMS(ST_MTPNP_AD_SMS_SEND_MSG * sms);
extern void MTPNP_PFAL_Abort_SMS(void);
extern void MTPNP_PFAL_Save_SMS(ST_MTPNP_AD_SMS_SAVE_MSG * sms);
extern void MTPNP_PFAL_Load_Next_SMS(void);
extern void MTPNP_PFAL_Get_SMS(ST_MTPNP_AD_SMS_GET_REQ * get_req);
extern void MTPNP_PFAL_Delete_SMS(ST_MTPNP_AD_SMS_DEL_REQ * del_req);
extern void MTPNP_PFAL_Copy_SMS(ST_MTPNP_AD_SMS_COPY_REQ * copy_req);
/* SMS */

/* plmn begin */
extern void MTPNP_PFAL_Set_Select_Mode(E_MTPNP_AD_PLMN_MODE mode);
extern void MTPNP_PFAL_Get_Preferred_Network(ST_MTPNP_AD_GET_PREFERRED_NETWORK_REQ * network_req);
extern void MTPNP_PFAL_Set_Preferred_Network(ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ * set_req);
extern void MTPNP_PFAL_Set_PLMN(ST_MTPNP_AD_SET_PLMN_REQ * set_req);
extern void MTPNP_PFAL_Get_PLMN_List(void);
extern void MTPNP_PFAL_Abort_PLMN_List(void);
/* plmn end */

/* cell broadcast messages begin */
extern void MTPNP_PFAL_Get_CB_Mode(void);
extern void MTPNP_PFAL_Set_CB_Mode(ST_MTPNP_AD_SET_CB_MODE_REQ * set_req);
extern void MTPNP_PFAL_Subscribe_CB(MTPNP_UINT8 subscribe);
/* cell broadcast messages end */

/* voice mail begin */
extern void MTPNP_PFAL_Get_Mailbox_Info(void);
extern void MTPNP_PFAL_Set_Mailbox_Address(ST_MTPNP_AD_SET_MAILBOX_ADDRESS_REQ * set_req);
/* voice mail end */

/* call history */

extern void MTPNP_PFAL_CallHistory_Del(MTPNP_AD_REQ_DEL_CALL_SCT * type);
extern void MTPNP_PFAL_CallHistory_Load(MTPNP_AD_REQ_LOAD_CALL_SCT * type);
extern void MTPNP_PFAL_CallHistory_Set(MTPNP_AD_REQ_CALL_RECORD_SCT * type);
extern void MTPNP_PFAL_CAI_ResetPUCT(MTPNP_AD_REQ_RESET_CALLCOST_SCT * puct);
void MTPNP_PFAL_read_CCM(void);
void MTPNP_PFAL_read_ACM(void);
void MTPNP_PFAL_read_ACMMAX(void);
void MTPNP_PFAL_Delete_ACM(void);
void MTPNP_PFAL_Update_ACMMAX(MTPNP_UINT32 value);
void MTPNP_PFAL_read_PUCT(void);
/* call history */

/* RF setting */
extern void MTPNP_PFAL_PwrOn_RF(void);
extern void MTPNP_PFAL_PwrOff_RF(void);
/* RF setting */

/* engineer/factory mode begin */
extern void MTPNP_PFAL_Get_Audio_Profile(MTPNP_UINT8 mode);
extern void MTPNP_PFAL_Set_Audio_Profile(ST_MTPNP_AD_AUDIO_PROFILE * profile);
MTPNP_BOOL MTPNP_PFAL_Report_Audio_Profile(ST_MTPNP_AD_AUDIO_PROFILE * param);
MTPNP_BOOL MTPNP_PFAL_Report_Set_Audio_Profile_Result(ST_MTPNP_AD_SET_AUDIO_PROF_RSP * set_result);
extern void MTPNP_PFAL_FM_Comm_Test(void);
extern void MTPNP_PFAL_FM_Test_Mic(MTPNP_UINT8 on_off);
extern void MTPNP_PFAL_FM_Test_Speaker(MTPNP_UINT8 on_off);
extern void MTPNP_PFAL_FM_Test_Receiver(MTPNP_UINT8 on_off);
extern void MTPNP_PFAL_FM_Test_Headset(MTPNP_UINT8 on_off);
extern void MTPNP_PFAL_FM_Test_RestoreNormal(void);
/* engineer/factory mode end */

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_PFAL_SLAVE_IF_H__
