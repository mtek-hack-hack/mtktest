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
 * EngineerModeProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode function prototype declaration
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

#ifndef _ENGINEER_MODE_PROT_H
#define _ENGINEER_MODE_PROT_H

#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__    
#include "MMIDataType.h"

#ifdef __TCPIP__
#include "Soc_api.h"
#include "EngineerModeSocketDemoApp.h"
#endif /* __TCPIP__ */ 

/*****************************************************************/
/****************************  Macros ****************************/
/*****************************************************************/
/* ===== Macro ============ */
#define EM_IS_SET(b, a)       ((b & (0x1 << a)) >> a)
#define EM_STATE_SET(b, a)    (b |= (0x1 << a))
#define EM_STATE_UNSET(b, a)  (b &= ~(0x1 << a))
#define EM_STATE_TOGGLE(b, a) (b ^= (0x1 << a))

typedef enum {
   EM_GPRS_ACT_PDP_TYPE_1ST = 0 ,
   EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY ,
   EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY
}  EM_GPRS_ACT_PDP_TYPE_ENUM;


/*****************************************************************/
/***************************  Functions **************************/
/*****************************************************************/

/******************* EM Init *********************/

extern void InitEngineerMode(void);
extern void InitEngineerModeSetting(void);
extern void EntryEngineerModeMenu(void);

/*********************** Network **********************/
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */

extern void EmGetNWCellLockReq(void);
extern void EmGetNWCellLockRsp(void *inMsg);
extern void EmSetNWCellLockReq(MMI_BOOL on_off, MMI_BOOL band1900_on, U16 arfcn);
extern void EmSetNWCellLockRsp(void *inMsg); 

/*********************** EM **********************/

extern void EntryEmGprsMenuNotSupport(void);
extern void EntryEmAudioMenu(void);
extern void ExitEmAudioMenu(void);

extern void EntryEmRingToneMenu(void);
extern void ExitEmRingToneMenu(void);
extern void EntryEmNormalModeMenu(void);
extern void EntryEmLoudSpModeMenu(void);
extern void EntryEmHeadsetModeMenu(void);
extern void EntryEmSetVolume(void);

extern void EntryEmSpeech(void);
extern void EntryEmMelody(void);
extern void EntryEmKeyTone(void);
extern void EntryEmCallTone(void);
extern void EntryEmSound(void);
extern void EntryEmMicrophone(void);
extern void EntryEmSideTone(void);
extern void EntryEmAudSetMaxSwing(void);
extern void EmAudSetParam(void);
extern void SendGetAudioParamReq(void);
extern void EmUpdateAudioParam(U8 *audp);
extern void EngineerModeGetAudioParamRes(void *inMsg);
extern void EngineerModeSetAudioParamRes(void *inMsg);

extern void EntryEmSetMode(void);
extern void EmSetMode(void);
extern void HighlightEmSetMode(void);

extern void EntryEmFIR(void);
extern void EmSetFIR(void);
extern void HighlightEmFIR(void);

extern void EntryEmDeviceMenu(void);

extern void EntryEmUartSetting(void);
extern void HighlightHdlrUartSettingsInline(S32 index);
extern void ExitEmUartSetting(void);
extern void EntryEmSetUartMenu(void);

extern void SendGetUartReq(void);
extern void SetHighlightIndex(S32 nIndex);
extern U32 EM_GetBaudRateByIdx(U8 idx);

/* gprs */
extern void EntryEmGprsMenu(void);
extern void HighlightEmGprs(void);
extern void HighlightEmAutoAttach(void);
extern void HighlightEm1stPDP(void);
extern void HighlightEm2ndPDP(void);
extern void HighlightEmActivate2ndPDP(void);
extern void HighlightEmActivate2ndPDPPrimary(void);
extern void HighlightEmActivate2ndPDPSecondary(void);
extern void HighlightEmActivatePDP(void);
extern void HighlightEmDeactivatePDP(void);
extern void HighlightEmSendDataMenu(void);
extern void HighlightEmSendData(void);

extern void EntryEmAutoAttach(void);
extern void EntryEm1stPDPMenu(void);
extern void EntryEm2ndPDPMenu(void);
extern void EntryEmActivatePDPMenu(void);
extern void EMGPRSActivatePDPReq(void);
extern void EntryEmActivate2ndPDPMenu(void);
extern void EntryEmDeactivatePDP(void);
extern void EntryEmSendData(void);
extern void EntryEmSendDataMenu(void);

extern void EntryEmMisc(void);
extern void EntryEmAutoAnswer(void);
extern void EntryEmHighSpeedSIM(void);
extern void EntryEmMiscBacklight(void);
extern void EntryEmSerialPortEnable(void);
extern void EntryEmAutoReset(void);

extern void EntryEmMMIDebug(void);
extern void ExitEmMMIDebug(void);
extern void EntryEmMemoryDump(void);
extern void ExitEmMemoryDump(void);

extern void EntryEmCellReselect(void);
extern void EMCellReselectDoneFunc(void);

extern void EntryEmFRMProfiling(void);
extern void ExitEmFRMProfiling(void);
extern void HighlightEmFRMProfiling(void);

extern void HighlightEmUIBenchmark(void);
extern void mmi_em_entry_ui_bench(void);
extern void mmi_em_ui_bench_stop(void);
extern void mmi_em_exit_ui_bench(void); 
extern void mmi_em_ui_bench_callback(const U8 *message);
extern void mmi_em_entry_ui_bench_result(void);

#if defined(__MMI_CASCADE_MENU__)
extern void HighlightCascadeMenuTest(void);
extern void mmi_em_entry_cascade_menu_test(void);
#endif /* defined(__MMI_CASCADE_MENU__) */

extern void EntryEmWAP(void);
extern void EntryEmWAPEnableDebug(void);
extern void ExitEmWAPEnableDebug(void);
extern void EntryEmOfflinePage(void);
extern void ExitEmOfflinePage(void);
extern void EntryEmUserAgent(void);
extern void EntryEmAcceptHeader(void);
extern void EntryEMMMSVersion(void);

extern void HighlightOnCertainSerialPortMenu(S32 index);
extern void HighlightEmSerialPortEnable(void);
extern void SerialPortMenuLSKHandler(void);
extern void HighlightEmAutoReset(void);

/* Lisen 012605 */
extern void HighlightEmMMIDebug(void);
extern void HighlightEmMemoryDump(void);

/* Lisen 03092005 */
extern void HightlightEMRAMTestHdlr(void);

#if defined(__AMR_SUPPORT__)
extern void HighlightEmAMR(void);
extern void EntryEMFAMR(void);
#endif /* defined(__AMR_SUPPORT__) */ 

extern void HiliteAllTestIdx(S32 hiliteIdx);
extern U16 GetSelectedTestList(void);

extern void ReadTestResultFromNVRAM(void);
extern void WriteTestResultToNVRAM(void);
extern void ReadTimeFromNVRAM(void);
extern void WriteCurrentTimeToNVRAM(void);
extern void ReadSettingsFromNVRAM(void);
extern void SaveNewItemToNVRAM(void);
extern void SavePriorityChangeToNVRAM(void);
extern void SaveRemoveItemToNVRAM(void);

extern void HiliteAutoTestAddFromList(void);
extern void EntryScrChangePriority(void);
extern void HiliteAutoTestChangePriority(void);
extern void HiliteAutoTestRemove(void);
extern void HiliteAutoTestCurrSelIdx(S32 hiliteIdx);
extern void GoBackAutoTestSetting(void);
extern void EM_InitAutoTest(void);
extern void HighlightAutoTestSetting(void);

extern void EntryEmAutoTestSetting(void);

extern void EntryScrShowAutoTestOptions(void);

extern void EntryScrEnterItemPriority(void);

extern void HighlightEmPWRDownCtrl(void);
extern void EntryEmPWRDownCtrl(void);
extern void ExitEmPWRDownCtrl(void);

#ifdef __J2ME__
extern void HighlightEmMiscJ2meTck(void);
#endif 

extern void SendGprsAttachReq(void);
extern void SendGprsAttachReq(void);
extern void SendGprsDeactivatePDPReq(void);
extern void SendGprsSendDataReq(kal_uint32 size);
extern void SendGprsActivatePDPContext(kal_uint8 pdp_idx);
extern void EngineerModeGprsAttachReq(void);
extern void EngineerModeGprsAttachRes(void *inMsg);
extern void EngineerModeGprsDeactivatePDPReq(void);
extern void EngineerModeGprsDeactivatePDPRes(void *inMsg);
extern void EngineerModeGprsSendDataReq(kal_uint32 size);
extern void EngineerModeGprsSendDataRes(void *inMsg);
extern void EngineerModeGprsActivatePDPContext(kal_uint8 pdp_idx);
extern void EngineerModeGprsSetDefinitionRes(void *inMsg);
extern void EngineerModeGprsSetQosRes(void *inMsg);

#ifdef __R99__
extern void EngineerModeGprsSetEQosRes(void *inMsg);
#endif 
extern void EngineerModeGprsActTestRes(void *inMsg);
extern void EmSendDataScreenLSKHandler(void);
extern void HighlightEmSetSleepMode(void);
extern void EntryEmSetSleepMode(U8 index);
extern void ExitEmSetSleepMode(void);
extern void SendSetSleepModeReq(void);

extern void mmi_em_sph_enh_entry_main(void);
extern void mmi_em_sph_enh_entry_para_list(void);

#if defined(DCM_ENABLE)
extern void HighlightEmDCMMODE(void);
extern void EmEntryDCMModeMenu(void);
extern void SendSetDCMModeReq(void);
extern void EngineerModeSetDCMModeReq(U16 is_on);
#endif /* defined(DCM_ENABLE) */ 

extern void EntrySetUartPowerONOFFScr(void);
extern void SetUARTPowerOnOffHdlr(void);
extern void SetUartPowerOnHighlightIndex(S32 nIndex);

extern void HighlightEmAudio(void);
extern void HighlightEmRingTone(void);
extern void HighlightEmNormalMode(void);
extern void HighlightEmLoudSpMode(void);
extern void HighlightEmHeadsetMode(void);

extern void HighlightEmSpeech(void);
extern void HighlightEmSideTone(void);
extern void HighlightEmKeyTone(void);
extern void HighlightEmCallTone(void);
extern void HighlightEmMelody(void);
extern void HighlightEmSound(void);
extern void HighlightEmMicrophone(void);
extern void HighlightEmLoopBack(void);
extern void mmi_em_sph_enh_main_highlight_hdlr(void);
extern void mmi_em_sph_enh_common_para_highlight_hdlr(void);
extern void mmi_em_sph_enh_normal_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_headset_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_loudspk_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_bt_earphone_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_bt_cordless_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_aux1_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_aux2_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_aux3_mode_highlight_hdlr(void);
extern void mmi_em_sph_enh_para_list_highlight_hdlr(S32 index);
extern void HighlightEmAudSetMaxSwing(void);

#if defined(TV_OUT_SUPPORT)
extern void HighlightEmAudTVOUT(void);
extern void EntryEmAudTVOUT(void);
#endif

extern void HighlightEmAudVMDebugInfo(void);
extern void HighlightEmAudAutoVMSetting(void);
extern void EntryAudioAutoVMSetting(void);
extern void EmAudAutoVMSettingHighlightIndex(S32 nIndex);
extern void EmAudAutoVMSetting(void);

extern void EmSet16LevelVolume(void);
extern void EmGetCurrent16LevelInfo(U8 *gain, U8 *step);

extern void HighlightEmDevice(void);
extern void HighlightEmSetUart(void);
extern void HighlightEmUartSetting(void);
extern void HighlightEmUartPowerOnOff(void);

extern void HighlightEmMisc(void);
extern void HighlightEmAutoAnswer(void);
extern void HighlightEmHighSpeedSIM(void);
extern void HighlightEmMiscBacklight(void);

extern void HightlightEMCellReselect(void);

#if defined(__MMI_EM_FIXED_GAIN_FOR_HELIOS2__)
extern void HightlightEMFixedGainForHelios2(void);
extern void EntryEMFixedGainForHelios2(void);
#endif /* __MMI_EM_FIXED_GAIN_FOR_HELIOS2__ */


#if defined(__MMI_EM_MT6223_DEBUG_MODE__)
extern void HightlightEMMT6223DebugMode(void);
extern void EntryEmMT6223DebugMode(void);
extern void EMMT6223DebugModeDoneFunc(void);
#endif

#if defined(MT6223P)
extern void HightlightEMLSDSlowerMode(void);
extern void EntryEmLSDSlowerMode(void);
extern void EmSetLSDSlowerHandler(void);
#endif

#ifdef __MMI_TVOUT__
extern void HighlightEmTVOut(void);
#endif 

#if defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT)
extern void HighlightVideoHiBitrate(void);
#endif 

extern void HighlightEMWAP(void);
extern void HighlightEmWAPEnableDebug(void);
extern void HighlightEmWAPOfflinePage(void);
extern void HighlightEMUserAgent(void);
extern void HighlightEMAcceptHeader(void);
extern void HighlightEMMMSVersion(void);

extern void HighlightAutoTestSetting(void);

extern void SendSetVolumeReq(void);
extern void EmAudioVolumeUp(void);
extern void EmAudioVolumeDown(void);
extern void EmSetVolume(void);
extern void SendGetAudioProfileReq(void);
extern void EmUpdateAudioProfile(U8 *speech, U8 *keytone, U8 *melody, U8 *sound, U8 *mic, U8 sidetone, U8 *tvout, U8 max_gain, U8 step);

extern void EngineerModeErrorNotice(U16 stringId);
extern void EngineerModeWarningNotice(U16 stringId);
extern void EngineerModeSuccessNotice(U16 stringId);

/* Lisen 09062005 */
extern void EngineerModeSuccessRebootNotice(U16 stringId);
extern void EngineerModeNoticeText(U8 *string, U16 icon);
extern void EngineerModeStartRes(void *inMsg);
extern void EngineerModeStopRes(void *inMsg);
extern void EngineerModePlayAudioReq(U8 index, U8 type);
extern void EngineerModeStopAudioReq(U8 index, U8 type);
extern void EngineerModeStatusInd(void *inMsg);
extern void EngineerModeSetVolumeReq(U8 volumeType, U8 volumeLevel);
extern void EngineerModeGetUartReq(void);
extern void EngineerModeGetUartRes(void *inMsg);
extern void EngineerModeSetUartReq(void);
extern BOOL EmIsPortAllow(U8 port_num);
extern void EngineerModeSetHighSpeedSIMReq(void);
extern void EngineerModeSetUartRes(void *inMsg);
extern void EngineeringModeUartSendDetachReq(void);
extern void EngineerModeDetachUartRes(void *inMsg);
extern void EngineeringModeUartSendAttachReq(void);
extern void EngineerModeAttachUartRes(void *inMsg);

extern void EngineerModeGetAudioProfileReq(U8 mode);
extern void EngineerModeGetAudioProfileRes(void *inMsg);
extern void EngineerModeSetAudioProfileReq(void *audioProfile);
extern void EngineerModeSetAudioProfileRes(void *inMsg);
extern void EngineerModeSetSleepModeReq(U8 index);
extern void EngineerModeSetSleepModeRes(void *inMsg);
extern void EngineerModeSetAudioParamReq(void *audioParam);
extern void EngineerModeGetAudioParamReq(void);

extern void EMPWRDownCtrlHighlightHandler(S32 index);
extern void EMPWRDownCtrlDoneFunc(void);
extern void EntryEmPWRDownCtrl(void);
extern void ExitEmPWRDownCtrl(void);

extern void idle_screen_show_em_info(void);

extern void EngineerModeSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void EngineerModeSendMsg_Ext(U16 msg_id, U16 dest_mod_id, void *local_param_ptr, void *peer_buf_ptr);

extern void HighlightEMDebugInfo(void);
extern void EntryEMDebugInfo(void);

#if defined(__FS_TRACE_SUPPORT__)
extern void HighlightEMFsTrace(void);
extern void EntryEMFsTrace(void);
extern void ExitEmFSTraceScreen(void);
extern void HighlightHdlrFSTraceInline(S32 index);
extern void EmSetFSTrace(void);
#endif /* defined(__FS_TRACE_SUPPORT__) */ 

extern void HighlightEMLastException(void);
extern void EntryEMLastException(void);

extern void HighlightEMSysStat(void);
extern void EntryEMSysStat(void);
extern void HighlightEMWriteSysStats(void);
extern void EntryEMWriteSysStats(void);
extern void HighlightEMSavingStatPWROFF(void);
extern void EntryEMSavingStatPWROFF(void);

extern void HighlightEMPowerOnDuration(void);
extern void EntryEMPowerOnDurationMenu(void);

extern void HighlightEmSWPatch(void);
extern void EntryEmSWPatch(void);
extern void ExitEmSWPatch(void);
extern void EMSWPatchHighlightHandler(S32 index);

extern void EntryEmSWDBG(void);
extern void HighlightEMSWDBG(void);

/* socket test */
#ifdef __TCPIP__
extern void HighlightEmSocket(void);
extern void HighlightEmDNSQuery(void);
extern void HighlightEmHTTPGet(void);
extern void HighlightEmEcho(void);
extern void HighlightEmDate(void);
extern void HighlightEmDNSQueryDone(void);
extern void HighlightEmDNSQueryInputMethod(void);
extern void HighlightEmHTTPGetDone(void);
extern void HighlightEmHTTPGetInputMethod(void);
extern void EntryEmSocketMenu(void);
extern void EntryEmDNSQuery(void);
extern void EntryEmDNSOption(void);
extern void EntryEmHTTPGet(void);
extern void EntryEmHTTPOption(void);
extern void EntryEmEcho(void);
extern void EntryEmDate(void);
extern void EntryEmSocketInProgress(void);
extern void EmSocketInProgressAbort(void);
extern void ExitEmEcho(void);
extern void ExitEmDate(void);
extern void EmSocketEchoFillInlineStruct(void);
extern void EntryEmSocketConfirm(void);
extern void GoToMainEmSocketScreen(void);
extern void EmSocketFullLineEditScreen(void);
extern void EmSocketDateFillInlineStruct(void);
extern void EmSocketSendReq(void);
extern void EntryEmSocketResult(void);
extern void EmSocketShowErrorMsg(void);
extern void EmSocketRsp(mmi_soc_demo_app_enum app_id_enum, int result, char *response, int response_len);
extern void EmSocketInitResult(void);
extern void EmSocketCheckAmPm(char *response);
extern void EmSocketGoBack2History(void);
extern void EmShowTraceRtResult(void);
extern void EmStartTraceRtResult(S8* string);
extern MMI_BOOL EmAppendTraceRtResult(S8* string);
extern void EmEndTraceRt(void);
extern void EmSocketShowErrorMsgByCause(int msg);

/* BEGIN OF IPERF */
extern void HighlightEmIperf(void);
extern void HighlightEmIperfTcp(void);
extern void HighlightEmIperfUdp(void);
extern void PreEntryEmIperf(void);
extern void PreEntryEmIperfTcp(void);
extern void PreEntryEmIperfUdp(void);
extern void EntryEmIperf(void);
extern void EntryEmIperfSetting(void);
extern void EntryEmIperfReport(void);
extern void em_iperf_run_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr);
extern void em_iperf_show_progressing_screen(void);
extern void em_iperf_progress_abort(void);
extern void em_iperf_exit_iperf_setting(void);
extern void em_iperf_exit_tcp_setting(void);
extern void em_iperf_exit_udp_setting(void);
extern U8 em_iperf_setting_del_callback (void *param);
extern void em_iperf_setting_fill_inline_struct(void);
extern void em_iperf_setting_data_acct(void);
extern void em_iperf_dt_callback(U32 account_id);
extern void em_iperf_ip_addr_callback(U8* string_buffer,U8 *IP1,U8 *IP2,U8 *IP3,U8 *IP4);
extern void em_iperf_run(void);
extern void em_iperf_check(void);
extern void em_iperf_not_run(void);
extern void em_iperf_disp_err_popup(U16 str_id);
extern void em_iperf_disp_not_support_popup(void);
extern void em_iperf_disp_fail_popup(U16 str_id);
extern void em_iperf_save(void);
extern void em_iperf_send_req(void);
extern void em_iperf_read_file(void);
extern void em_iperf_load_default(void);
extern void em_iperf_run_cnf_hf(void* msg);
extern void em_iperf_report_ind_hf(void* msg);
extern void em_iperf_report_back(void);
/* END OF IPERF */

#endif /* __TCPIP__ */ 

/* Lisen 03092005 */
extern void EntryEMRAMTestMenu(void);

#if defined(__MMI_TOUCH_SCREEN__)
extern void HighlightEmPen(void);
extern void HighlightEmPenStatistics(void);
extern void HighlightEmPenExit(void);
extern void EntryEmPenOptions(void);
extern void EntryEmPenStatisticsList(void);
extern void EmPenLeaveTest(void);
extern void EmPenTestClear(void);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
#endif /* __MMI_ENGINEER_MODE__ */ 

/* profiling */
extern void mmi_em_init_profiling(void);


#if defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__)
/* RF Test Tool */
extern void HighlightRFTestTool(void);
extern void EmRFTestDisableSleepMode(void);
extern void EntryEmRFTestTool(void);
extern void EmRFTestEnableSleepMode(void);
extern void EmRFTestToolSleepModeHdlr(void* inMsg);
extern void ExitEmRFTestInlineSelectScreen(void);
#endif 

#ifdef __FLIGHT_MODE_SUPPORT__ 
/* RF Test Tool -- GSM */
extern void EMRFTestGSMInitContext(void);
extern void EMRFTestGsmSendReq(void);
extern void EMRFTestGsmSendRes(void* inMsg);
extern void EmStopRFTestGsm(void);
extern void HighlightRFTestGSM(void);
extern void EntryRFTestGSMEnterCondirm(void);
extern void EmRFTestGSMEnterFlightMode(void);
extern void EntryEmRFTestGSM(void);
extern void EmRFTestGSMExitFlightMode(void);
/* RF Test Tool -- GSM TX Test */
extern void HighlightRFTestGSMTxTest(void);
extern void EntryEmRFTestGSMTxTest(void);
extern void HighlightHandlerRFGSMTxInline(S32 index);
extern void HighlightHandlerRFGSMBandInline(S32 index);
extern void EMRFGSMTXTestCheckAndSendReq(void);
extern void EntryEMRFTESTGsmTXTestDone(void) ;
/* RF Test Tool -- GSM RX Test */
extern void HighlightRFTestGSMRxTest(void);
extern void EntryEmRFTestGSMRxTest(void);
extern void HighlightHandlerRFGSMRxInline(S32 index);
extern void EMRFGSMRXTestCheckAndSendReq(void);
extern void EMRFTestGsmRXTestTimeoutHdlr(void);
extern void EntryEMRFTESTGsmRXTestDone(void);
/* RF Test Tool -- GSM Power Save */
extern void HighlightRFTestGSMPowerScan(void);
extern void EntryEmRFTestGSMPowerScan(void);
extern void HighlightHandlerRFGSMPowerScanInline(S32 index) ;
extern void EMRFGSMPowerScanFunc(void);
extern void EntryEMRFGSMPowerScanRsp(PS16 arfcn, PS16 power);
extern void EmRFTestGSMPowerScanBack(void);
extern void EmRFTestGSMPowerScanAbort(void);
/* RF Test Tool -- GSM Common function */
extern MMI_BOOL check_gsm_arfcn_valid(void);
#endif /* #ifdef __FLIGHT_MODE_SUPPORT__ */

#if defined(__WIFI_SUPPORT__)
/* RF Test Tool -- WiFi */
extern void EMRFTestWiFiInitContext(void);
extern void EMRFTestWiFiSendReq(void);
extern void EMRFTestWifiSendRes(void* inMsg);
extern void EmStopRFTestWiFi(void);
extern void HighlightRFTestWiFi(void);
extern void EntryRFTestWifiEnterCondirm(void);
extern void EmRFTestWifiEnterTestMode(void);
extern void EntryEmRFTestWiFi(void);
extern void EmRFTestWifiExitTestMode(void);
/* RF Test Tool -- WiFi Tx Test */
extern void HighlightRFTestWiFiTxTest(void);
extern void EntryEmRFTestWiFiTxTest(void);
/* RF Test Tool -- WiFi Tx Test -- DAC */
extern void HighlightRFTestWiFiTXDACOffset(void);
extern void EmRFTestWiFiTXDACOffset(void);
extern void EntryEmRFTestWiFiTXDACOffsetRsp(U8 ich, U8 qch);
/* RF Test Tool -- WiFi Tx Test -- Output Power */
extern void HighlightRFTestWiFiTXOutputPower(void);
extern void EntryEmRFTestWiFiTxOutputPower(void);
extern void HighlightHandlerRFWifiTxOutputPowerInline(S32 index);
extern void EMRFTESTWifiTXOutputPowerCheckAndSendReq(void);
extern void EntryEMRFTESTWifiTXOutputPowerDone(void);
/* RF Test Tool -- WiFi Tx Test -- Carrier Supp */
extern void HighlightRFTestWiFiTXCarrierSupp(void);
extern void EntryEmRFTestWiFiTxCarrierSupp(void);
extern void HighlightHandlerRFWifiTxCarrierSuppInline(S32 index);
extern void EMRFTESTWifiTXCarrierSuppCheckAndSendReq(void);
extern void EntryEMRFTESTWifiTXCarrierSuppDone(void);
/* RF Test Tool -- WiFi Tx Test -- Local Freq. */
extern void HighlightRFTestWiFiTXLocalFreq(void);
extern void EntryEmRFTestWiFiTxLocalFreq(void);
extern void HighlightHandlerRFWifiTxLocalFreqInline(S32 index);
extern void EMRFTESTWifiTXLocalFreqCheckAndSendReq(void);
extern void EntryEMRFTESTWifiTXLocalFreqDone(void);
/* RF Test Tool -- WiFi Tx Test -- TX Cont PKT */
extern void HighlightRFTestWiFiTXContPKT(void);
extern void EntryEmRFTestWiFiTxContPKT(void);
extern void HighlightHandlerRFWifiTxContPKTInline(S32 index) ;
extern void EMRFTESTWifiTXContPKTCheckAndSendReq(void);
extern void EntryEMRFTESTWifiTXContPKTDone(void);
/* RF Test Tool -- WiFi Tx Tests Common function */
extern MMI_BOOL EMRFWifiTXCommonCheckAndSendReq(void) ;
extern void EMRFWifiTxFillInlineStruct(void);
extern void EMRFWifiTxFillInlineStructForView(void);
/* RF Test Tool -- Wifi RX */
extern void HighlightRFTestWiFiContPKTRx(void);
extern void EntryEmRFTestWiFiRxContPKT(void);
extern void HighlightHandlerRFWifiRxContPKTInline(S32 index) ;
extern void EMRFTESTWifiRXContPKTSendReq(void);
extern void EntryEmRFTestWiFiRXContPKTRsp(U8 *response);
/* RF Test Tool -- Wifi Power Save */
extern void HighlightRFTestWiFiPowerSave(void);
extern void EntryEmRFTestWiFiPowerSave(void);
extern void HighlightHandlerRFWifiPowerSaveInline(S32 index);
extern void EMRFTESTWifiPowerSaveSendReq(void);
extern void EntryEmRFTestWiFiPowerSaveDone(void);
/* RF Test Tool -- Wifi Register Access */
extern void HighlightRFTestWiFiRegisterAccess(void);
extern void EntryEmRFTestWiFiRegisterAccess(void);
/* RF Test Tool -- Wifi Register Access -- MCR */
extern void HighlightRFTestWiFiRegisterMCR(void);
extern void EntryEmRFTestWiFiRegisterMCR(void);
extern void HighlightRFWifiRegMCRAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegMCRInline(S32 index);
extern void EMRFTESTWifiRegMCRSendReq(void);
extern void EntryEmRFTestWiFiRegMCRAccessRsp(U32 mcr_data);
/* RF Test Tool -- Wifi Register Access -- BBCR */
extern void HighlightRFTestWiFiRegisterBBCR(void);
extern void EntryEmRFTestWiFiRegisterBBCR(void);
extern void HighlightRFWifiRegBBCRAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegBBCRInline(S32 index);
extern void EMRFTESTWifiRegBBCRSendReq(void);
extern void EntryEmRFTestWiFiRegBBCRAccessRsp(U32 bbcr_data);
/* RF Test Tool -- Wifi Register Access -- EEPROM */
extern void HighlightRFTestWiFiRegisterEEPROM(void);
extern void EntryEmRFTestWiFiRegisterEEPROM(void);
extern void HighlightRFWifiRegEEPROMAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegEEPROMInline(S32 index);
extern void EMRFTESTWifiRegEEPROMSendReq(void);
extern void EntryEmRFTestWiFiRegEEPROMAccessRsp(U32 eeprom_data);
#endif  /* defined(__WIFI_SUPPORT__) */

#if defined(__VOIP__)
extern void HighlightEmVOIP(void);
extern void EntryEmVOIP(void);
extern void HighlightEmVOIPSetting(void);
extern void EntryEmVOIPSetting(void);
extern void EmGetVOIPSettingInfo(void);
extern void ExitEmVOIPSettingScreen(void);
extern void HighlightHdlrVOIPSettingsInline(S32 index);
extern void EmSetVOIPSettingInfo(void);
extern void HighlightEmVOIPSIPSupported(void);
extern void EntryEmVOIPSIPSupported(void);
extern void LSKEmVOIPSetSIPSupportedHandler(void);
extern void HighlightEmVOIPSIPRequire(void);
extern void EntryEmVOIPSIPRequire(void);
extern void LSKEmVOIPSetSIPRequireHandler(void);

extern void HighlightEmVOIPLog(void);
extern void EntryEmVOIPLog(void);
extern void HighlightEmVOIPLogSetting(void);
extern void EntryEmVOIPLogSetting(void);
extern void ExitEmVOIPLogSettingScreen(void);
extern void HighlightHdlrVOIPLogInline(S32 index);
extern void EmSetVOIPLogInfo(void);
extern void HighlightEmVOIPLogView(void);
extern void EntryEmVOIPLogOption(void);
extern void EntryEMVOIPLogSelected(void *path, int is_short);
extern void EMVOIPLogDisplayOption(void);
extern void HighlightEmVOIPLogOptionView(void);
extern void EntryEmVOIPLogOptionView(void);
extern void HighlightEmVOIPLogOptionDelete(void);
extern void HighlightEmVOIPLogOptionDeleteAll(void);
extern void entry_em_voip_log_delete_confirm(void);
extern void em_voip_log_delete_all_file(void);
extern void em_voip_log_delete_file(void);
extern void em_voip_log_delete_rsp_hdlr(void *info);
extern void entry_em_voip_delete_animation(void);
extern void exit_em_voip_delete_animation(void);
extern U8   em_voip_delete_animation_callback(void *param);

extern void em_voip_log_init(void);
extern MMI_BOOL em_voip_log_check_activate_status(void);
extern void em_voip_log_change_id(void* ori_id, void* new_id);
extern void em_voip_log_save(void* id, void *buf, S32 buf_len);
extern void em_voip_log_call_start( void* id, MMI_BOOL mdir);
extern void em_voip_log_call_end( void* id);
//extern MMI_BOOL em_voip_log_check_disk_space(void);
extern void em_voip_log_check_and_delete( void);
#endif  /*  __VOIP__ */

extern void EngineerModeSendMsg_Check_Prefer_SIM(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern MMI_BOOL mmi_em_device_is_use_usb_as_uart_port(void);

#endif /* _ENGINEER_MODE_PROT_H */ 

