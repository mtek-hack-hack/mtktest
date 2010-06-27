/***********************************************
File name : MTPNP_PFAL_CC.h
Contents : MTPNP AD direct data transfer interface
History : Create by : Zhang Nan, Mar 16, 2007
************************************************/
#ifndef _MTPNP_PFAL_CC_H_
#define _MTPNP_PFAL_CC_H_

//#ifdef __MERCURY_MASTER__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"
#include "FrameworkStruct.h"
#include "GSM7BitDefaultAlphabet.h"
#include "PhoneBookTypes.h"

typedef enum
{
    MTPNP_AD_AUX_CALL_DISCONNECT = 0,
    MTPNP_AD_AUX_CALL_SETUP
} E_MTPNP_AD_AUX_CALL_STATUES;

/*master call state wrapper function begin*/
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInOutgoing(void);
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInIdle(void);
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInIncoming(void);
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInAcitveOrHold(void);
/*master call state wrapper function end*/
void MTPNP_PFAL_CC_HandleSendKeys(FuncPtr newCallFunc, mmi_key_types_enum keyevent);

void MTPNP_PFAL_AddCCMarkerToHistory(void);

void MTPNP_PFAL_CC_HandleSpeechConnected(void);
MTPNP_BOOL MTPNP_PFAL_CC_GetEarphonePluggin(void);
MTPNP_BOOL MTPNP_PFAL_CC_GetHandFreeOn(void);
#ifdef __MMI_DUAL_SIM_MASTER__
void MTPNP_PFAL_Sync_SpeechMode(void);
#endif /* #ifdef __MMI_DUAL_SIM_MASTER__ */
void MTPNP_PFAL_CC_SetSpeechMode(U8 mode);
MTPNP_UINT8 MTPNP_PFAL_CC_GetSpeechMode(void);

void MTPNP_PFAL_CC_CheckBeforeGoBackHistory(void);
void MTPNP_PFAL_CC_GoBackfromNotifyScr(void);
/*mtpnp slave dtmf handler functions*/
MTPNP_UINT8 MTPNP_PFAL_ConvertKeycode2Ascii(MTPNP_UINT16 key);
void MTPNP_PFAL_CC_HangupAll(void);

U8 MTPNP_PFAL_SSReqHistoryDelHdlr(void *in_param);
void MTPNP_PFAL_DropUssd(PsFuncPtr callback);
void MTPNP_PFAL_EntryScrDisplayUSSNMsg(void);
void MTPNP_PFAL_MMIUSSNReceiveOK(void);
void MTPNP_PFAL_EntryScrDisplayUSSDRes(void);
#ifdef __MMI_USSR_TIMER__
void MTPNP_PFAL_USSRTimeout(void);
#endif
void MTPNP_PFAL_RemoveSSReqScr(void);
void MTPNP_PFAL_DropUssd(PsFuncPtr callback);
void MTPNP_PFAL_EntryScrDisplayUSSRMsg(void);
void MTPNP_PFAL_AbortUSSDResultRequest(void);
void MTPNP_PFAL_CBackDropUSSDReq(void *info);
void MTPNP_PFAL_AbortUSSDResultRequestEND(void);
void MTPNP_PFAL_CBackDropUSSDReqEND(void *info);
void MTPNP_PFAL_EntryScrEditUSSRMsg(void);
void MTPNP_PFAL_EditUSSRGoBack(void);
void MTPNP_PFAL_SendUSSRMsg(void);
void MTPNP_PFAL_DeriveUSSDData(U8 dcs, U8 * ussd_string);
void MTPNP_PFAL_CC_Show_ScrUSSDReq(void);
U8 MTPNP_PFAL_SSReqHistoryDelHdlr(void *in_param);
extern S8 MTPNP_PFAL_gUSSDbuf[MAX_DIGITS_USSD * ENCODING_LENGTH];

extern void RegisterUSSRMsgKeyFunction(U8 * text, U8 * cursor, S32 length);

U16 MTPNP_PFAL_CC_GetDGTotalCallCount(void);
U16 MTPNP_PFAL_CC_GetDGTotalActiveAndHoldCallCount(void);

void MTPNP_PFAL_CC_HangupAll(void);
void MTPNP_PFAL_CC_DgRejectAllIncoming(void);
void MTPNP_PFAL_CC_DGAcceptAllIncoming(void);
void MTPNP_PFAL_CC_AcceptMasterIncomingCall(void);
void MTPNP_PFAL_CC_CancelMasterMOCall(void);
void MTPNP_PFAL_CC_ActiveNonActiveNetCall(void);

void MTPNP_PFAL_SetCMPhoneBookStruct(PHB_CM_INTERFACE * pNumberStruct);
PHB_CM_INTERFACE *MTPNP_PFAL_GetCMPhoneBookStruct(void);
void MTPNP_PFAL_CC_DgEndCurCall(void);
void MTPNP_PFAL_CC_DgActiveCurCall(void);

void MTPNP_PFAL_CC_EntryCallsetGeneralSSResut(void);
void MTPNP_PFAL_CC_EntryCallsetGeneralSSResutScr(void);
void MTPNP_PFAL_CC_CallChangePwdRsp(void *info);
void MTPNP_PFAL_CC_CallBarringRsp(void *info);
void MTPNP_PFAL_CC_DisplayCFUInd(void *info);
void MTPNP_PFAL_CC_DisplaySpeechInd(void *info);
void MTPNP_PFAL_CC_ShowScrError(void);
void MTPNP_PFAL_CC_DoPlayConnetTone(void);
void MTPNP_PFAL_CC_DoPlayCRTTone(void);
void MTPNP_PFAL_CC_PHBSetdataforCall(MTPNP_UINT16 index);
extern void MTPNP_PFAL_CC_NOUCMInitRegister(void);
extern void MTPNP_PFAL_CC_UCMInitRegister(void);
void MTPNP_PFAL_CC_RegisterInitCB(void);

void MTPNP_PFAL_CC_EntryMOSelectionScreen(void);
void MTPNP_PFAL_CC_HiliteNetSelectCard1(void);
void MTPNP_PFAL_CC_HiliteNetSelectCard2(void);

#ifdef __LSK_KEYSEND2_IN_ONE__
MTPNP_BOOL MTPNP_PFAL_CC_IsDialFromLSK(void);
void MTPNP_PFAL_CC_SetDialFromLSK(MTPNP_BOOL isTorF);
MTPNP_BOOL MTPNP_PFAL_CC_GetIsKeyForCall(void);
void MTPNP_PFAL_CC_SetIsKeyForCall(MTPNP_BOOL forcall);
MTPNP_UINT16 MTPNP_PFAL_CC_GetSendEventType(void);
void MTPNP_PFAL_CC_RegShareKeyHandler(mmi_key_types_enum sendkeytype);
#endif /*__LSK_KEYSEND2_IN_ONE__*/

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
void MTPNP_PFAL_CC_CSKSelectScreen(void);
void MTPNP_PFAL_CC_SetCenterFunc(FuncPtr cenfunc);
FuncPtr MTPNP_PFAL_CC_GetCenterFunc(void);
void MTPNP_PFAL_CC_ExeCenterFunc(void);
void MTPNP_PFAL_CC_CSKHandler(void);
void MTPNP_PFAL_CC_InitCSKSelectCard(void);
void MTPNP_PFAL_CSK_HiliteSelectCard1(void);
void MTPNP_PFAL_CSK_HiliteSelectCard2(void);
void MTPNP_PFAL_CC_CSKDialCard1(void);
void MTPNP_PFAL_CC_CSKDialCard2(void);
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

void MTPNP_PFAL_CC_SetDial1Func(FuncPtr dialfunc);
void MTPNP_PFAL_CC_SetDial2Func(FuncPtr dialfunc);
FuncPtr MTPNP_PFAL_CC_GetDial1Func(void);
FuncPtr MTPNP_PFAL_CC_GetDial2Func(void);
void MTPNP_PFAL_CC_ExeDial1Func(void);
void MTPNP_PFAL_CC_ExeDial2Func(void);
void MTPNP_PFAL_CC_ShowSelectCard(void);
void MTPNP_PFAL_CC_SelectCardScreen(void);
void MTPNP_PFAL_CC_InitSelectCard(void);
void MTPNP_PFAL_CC_HiliteSelectCard1(void);
void MTPNP_PFAL_CC_HiliteSelectCard2(void);
void MTPNP_PFAL_CC_DialCard1(void);
void MTPNP_PFAL_CC_DialCard2(void);

void MTPNP_PFAL_CC_DgShowMasterIncomingCallAlter(void);
void MTPNP_PFAL_CC_DgShowSlaveIncomingCallAlter(void);

void MTPNP_PFAL_CC_SetMOCallFunc(FuncPtr funcname);
FuncPtr MTPNP_PFAL_CC_GetMOCallFunc(void);
void MTPNP_PFAL_CC_ExeMOCallFunc(void);
void MTPNP_PFAL_CC_SetQuickEndTime(void);
//extern void MTPNP_PFAL_SendSampleADCMsg(unsigned char setOrDis);
MTPNP_BOOL MTPNP_PFAL_Retrieve_CallDial_State(MTPNP_UINT8 * m_dial_enable,
                                                                                               MTPNP_UINT8 * s_dial_enable);
void MTPNP_PFAL_CC_ShowNotAllow(void *msg);
void MTPNP_PFAL_CC_MO_FAILED(void *msg);

void MTPNP_PFAL_CC_InitEntrySelectSendkey(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif
