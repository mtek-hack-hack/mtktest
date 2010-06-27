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

/*******************************************************************************
 * Filename:
 * ---------
 * SATProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM application toolkit related functions
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SATProts.h

   PURPOSE     : SAT application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Mar 24,03

**************************************************************/

#ifndef _PIXTEL_SATPROTS_H
#define _PIXTEL_SATPROTS_H

#ifdef __SAT__

extern void InitSimAppToolkit(void);
extern void ExitSATToIdle(void);
extern void ExitVariables(void);

extern void SATMessageWaitTimer(void);
extern void SATStopWaitTimer(void);
extern void SATPleaseWaitScreen(U16 string, U16 image);
extern void PleaseWaitActualScreen(void);

extern void StartSATTimerNoResponsefromUser(FuncPtr FuncPtr);
extern void StopSATTimerNoResponsefromUser(void);
extern void TemporaryStopSATTimerNoResponsefromUser(void);
extern void RestartSATTimerNoResponsefromUser(void);

extern void StartSATTimerHelp(FuncPtr FuncPtr);
extern void StopSATTimerHelp(void);
extern void TemporaryStopSATTimerHelp(void);
extern void RestartSATTimerHelp(void);

extern void SATNoFurtherCommandInd(void *msgPtr);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSIMFileChangeSIM1Ind(void *msgPtr);
extern void SATSIMFileChangeSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSIMFileChangeInd(void *msgPtr);
extern void GoToSATRebootScreen(void);
extern void SATRefreshRebootTimeOut(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSetupMenuSIM1Ind(void *msgPtr);
extern void SATSetupMenuSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSetupMenuInd(void *msgPtr);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSetupMenuInd_2(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSetupMenuRsp(void *msgPtr);
extern void SendTerminalResponseSetupMenu(U8 res, U8 *cmdDetail);

extern void GoToSATMainMenu(void);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void GoToSATMainMenu_2(void);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern PU8 SATReturnNextAction(U8 NextActionID);
extern void SATCompletePreviousTransaction(void);
extern void ExitSATMainMenu(void);
extern void FreeMainMenu(SATSETUPMENU *mainMenu);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void FreeMainMenu_2(SATSETUPMENU *mainMenu);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATMenuIndex(S32 index);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATMenuIndex_2(S32 index);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void EnvelopeSetupMenuOK(void);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void EnvelopeSetupMenuOK_2(void);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void EnvelopeSetupMenuHelp(void);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void EnvelopeSetupMenuHelp_2(void);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void EnvelopeSetupMenu(U8 itemId, U8 isHelpInfoRequested);
extern void SATMenuSelectRsp(void *msgPtr);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSelectItemSIM1Ind(void *msgPtr);
extern void SATSelectItemSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSelectItemInd(void *msgPtr);
extern void SATSelectItemRsp(void *msgPtr);
extern void SelectItemWrongData(void);
extern void GoToSATSubMenu(void);
extern void SelectItemTimer(void);
extern void TerminalResponseSelectItemOK(void);
extern void TerminalResponseSelectItemMoveBack(void);
extern void TerminalResponseSelectItemHelp(void);
extern void TerminalResponseSelectItemExpire(void);
extern void TerminalResponseSelectItem(U8 res, U8 itemId, U8 *cmdDetail);
extern void FreeSubMenu(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATDisplayTextSIM1Ind(void *msgPtr);
extern void SATDisplayTextSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATDisplayTextInd(void *msgPtr);
extern void SATDisplayTextRsp(void *msgPtr);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATDisplayTextRsp_2(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void GoToSATDisplayTextScreen(void);
extern void DisplayTextTimer(void);
extern void TerminalResponseDisplayTextOK(void);
extern void TerminalResponseDisplayTextMoveBack(void);
extern void TerminalResponseDisplayTextExpire(void);
extern void TerminalResponseDisplayText(U8 res, U8 *cmdDetail);
extern void FreeDisplayText(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATGetInputSIM1Ind(void *msgPtr);
extern void SATGetInputSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATGetInputInd(void *msgPtr);
extern void SATGetInputRsp(void *msgPtr);
extern void GoToGetInput(void);
extern void SATEntryScrForInputMethodAndDone(void);
extern void SATInputMethodAndDoneHiliteHandler(S32 index);
extern void SATGoBacknHistoryFromInputMethod(void);
extern void TerminalResponseGetInputOKDone(void);
extern void GetInputTimer(void);
extern void TerminalResponseGetInputOK(void);
extern void TerminalResponseGetInputMoveBack(void);
extern void TerminalResponseGetInputHelp(void);
extern void TerminalResponseGetInputExpire(void);
extern void TerminalResponseGetInput(U8 res, U8 *cmdDetail);
extern void FreeGetInput(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATGetInkeySIM1Ind(void *msgPtr);
extern void SATGetInkeySIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATGetInkeyInd(void *msgPtr);
extern void SATGetInkeyRsp(void *msgPtr);
extern void GoToGetInkey(void);
extern void GetInkeyTimer(void);
extern void SATHiliteYesNo(S32 index);
extern void TerminalResponseGetInkeyYesNo(void);
extern void TerminalResponseGetInkeyOKDone(void);
extern void TerminalResponseGetInkeyOK(void);
extern void TerminalResponseGetInkeyYes(void);
extern void TerminalResponseGetInkeyNo(void);
extern void TerminalResponseGetInkeyMoveBack(void);
extern void TerminalResponseGetInkeyHelp(void);
extern void TerminalResponseGetInkeyExpire(void);
extern void TerminalResponseGetInkey(U8 res, U8 isYesSelected, U8 *cmdDetail);
extern void FreeGetInkey(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATCallSetupSIM1Ind(void *msgPtr);
extern void SATCallSetupSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATCallSetupInd(void *msgPtr);
extern void SATCallSetupStage1Rsp(void *msgPtr);
extern void SATCallSetupStage2Rsp(void *msgPtr);
extern void GoToCallConformationScreen(void);
extern void TerminalResponseCallSetupExpire(void);
extern void SATCallSetupTerminalResponseMoveBack(void);
extern void TerminalResponseCallSetup(U8 res, U8 addInfo, U8 *cmdDetail);
extern void SATCallSetupStage1Req(void);
extern void FreeCallSetup(void);
extern void SATCMCallBackScreen(void);
extern void SATCMCallBackScreenExitHandler(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSendSMSSIM1Ind(void *msgPtr);
extern void SATSendSMSSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSendSMSInd(void *msgPtr);
extern void SATSendSMSStage1Rsp(void *msgPtr);
extern void SATSendSMSStage2Rsp(void *msgPtr);
extern void TerminalResponseSendSMS(U8 res, U8 cause, U8 *cmdDetail);
extern void GoToSMSConformationScreen(void);
extern void SATSendSmsTerminalResponseUnable(void);
extern void SATSendSmsTerminalResponseExpire(void);
extern void SATSendSMSStage1Req(void);
extern void DisplaySMSWindow(void);
extern void FreeSendSms(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSendSSSIM1Ind(void *msgPtr);
extern void SATSendSSSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSendSSInd(void *msgPtr);
extern void SATSendSSStage1Rsp(void *msgPtr);
extern void SATSendSSStage2Rsp(void *msgPtr);
extern void TerminalResponseSendSS(U8 res, U8 len, U8 *info, U8 *cmdDetail);
extern void SATSendSSStage1Req(mmi_sat_send_ss_ind_struct *sendSSInd);
extern void DisplaySSWindow(void);
extern void FreeSendSS(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSendUSSDSIM1Ind(void *msgPtr);
extern void SATSendUSSDSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSendUSSDInd(void *msgPtr);
extern void SATSendUSSDStage1Rsp(void *msgPtr);
extern void SATSendUSSDStage2Rsp(void *msgPtr);
extern void SATSendSSUSSDError(void);
extern void TerminalResponseSendUSSD(U8 res, U8 len, U8 *info, U8 *cmdDetail);
extern void SATSendUSSDStage1Req(mmi_sat_send_ussd_ind_struct *sendSSInd);
extern void DisplayUSSDWindow(void);
extern void FreeSendUSSD(void);

extern void SATMMIInfoInd(void *msgPtr);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATPlayToneSIM1Ind(void *msgPtr);
extern void SATPlayToneSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATPlayToneInd(void *msgPtr);
extern void SATPlayToneRsp(void *msgPtr);
extern void SATPlayToneTimer(void);
extern void DisplayPlayToneWindow(void);
extern void ExitPlayTone(void);
extern void TerminalResponsePlayToneBackward(void);
extern void TerminalResponsePlayToneExpire(void);
extern void TerminalResponsePlayTone(U8 res, U8 *cmdDetail);
extern void FreePlayTone(void);

extern void SendImageLenRecordReq(U8 iconId);
extern void SendImageInstRecordReq(mmi_smu_read_sim_rsp_struct *satReadSimRes);
extern void SendImageDataRecordReq(mmi_smu_read_sim_rsp_struct *satReadSimRes);
extern void SendImageDataCallBack(mmi_smu_read_sim_rsp_struct *satReadSimRes);
extern void SATSendReadSimFileRsp(void *msgPtr);
extern void SATSendReadSimFileReq(U16 fileIdx, U16 recordNo, U16 length);

extern void SATEVDLBrowserTerminationInd(void *msgPtr);
extern void SATEVDLBrowserTermination(U8 res);

extern void SATLangNotifyInd(void *msgPtr);
extern void SATSetLanguage(PU8 Lang);
extern void TerminalResponseLangNotify(U8 res, U8 *cmdDetail);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATLaunchBrowserSIM1Ind(void *msgPtr);
extern void SATLaunchBrowserSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATLaunchBrowserInd(void *msgPtr);
extern void WAPLaunchBrowserRsp(void *msgPtr);
extern void SATLaunchBrowserRsp(void *msgPtr);
extern void GoToLaunchBrowserConformationScreen(void);
extern void LaunchBrowserConformationOK(void);
extern void SATSendLaunchBrowserTerminalResponseExpire(void);
extern void SATSendLaunchBrowserTerminalResponseUnable(void);
extern void TerminalResponseLaunchBrowser(U8 res, U8 add_info, U8 *cmdDetail);
extern void FreeLaunchBrowser(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSendDTMFSIM1Ind(void *msgPtr);
extern void SATSendDTMFSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSendDTMFInd(void *msgPtr);
extern void SATSendDTMFStage1Rsp(void *msgPtr);
extern void SATSendDTMFStage2Rsp(void *msgPtr);
extern void GoToDTMFConformationScreen(void);
extern void SATSendDTMFTerminalResponseExpire(void);
extern void SATSendDTMFTerminalResponseUnable(void);
extern void SATSendDTMFStage1Req(void);
extern void DisplayDTMFWindow(void);
extern void SATSendDTMFAbortReq(void);
extern void TerminalResponseSendDTMF(U8 res, U8 cause, U8 *cmdDetail);
extern void FreeSendDTMF(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSetupIdleDisplaySIM1Ind(void *msgPtr);
extern void SATSetupIdleDisplaySIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSetupIdleDisplayInd(void *msgPtr);
extern void GoToSATSetupIdleDisplay(void);
extern void TerminalResponseSetupIdleDisplay(U8 res, U8 *cmdDetail);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATRunATCommandSIM1Ind(void *msgPtr);
extern void SATRunATCommandSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATRunATCommandInd(void *msgptr);
extern void DisplayATCommandScreen(void);
extern void ExitDisplayATCommandScreen(void);
extern void DisplayATCommandTimerOver(void);

extern void SATHistoryHandler(void);
extern void SATSaveHistory(void);
extern void SATGenericExitHandler(void);
extern U8 SATScrKeyHandler(KEYBRD_MESSAGE *eventKey);
extern void SetIsInSATScreen(void);
extern void ClearIsInSATScreen(void);

#ifdef __SATCE__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATOpenChannelSIM1Ind(void *msgPtr);
extern void SATOpenChannelSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATOpenChannelInd(void *msgPtr);
extern void GoToOpenChannelConformationScreen(void);
extern void SATOpenChannelTerminalResponseExpire(void);
extern void SATOpenChannelTerminalResponseUnable(void);
extern void TerminalResponseOpenChannel(U8 res, U8 addInfo, U8 *cmdDetail);
extern void SATOpenChannelReq(void);
extern void DisplayOpenChannelWindow(void);
extern void SATOpenChannelRes(void *msgPtr);
extern void FreeOpenChannel(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATCloseChannelSIM1Ind(void *msgPtr);
extern void SATCloseChannelSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATCloseChannelInd(void *msgPtr);
extern void DisplayCloseChannelWindow(void);
extern void SATCloseChannelTerminalResponseExpire(void);
extern void TerminalResponseCloseChannel(U8 res, U8 *cmdDetail);
extern void SATCloseChannelRes(void *msgPtr);
extern void FreeCloseChannel(void);
extern void DisplayCloseChannelScreen(void);
extern void ExitCloseChannelScreen(void);
extern void CloseChannelCommandTimerOver(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATSendDataSIM1Ind(void *msgPtr);
extern void SATSendDataSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATSendDataInd(void *msgPtr);
extern void GoToSendDataConformationScreen(void);
extern void SATSendDataTerminalResponseExpire(void);
extern void SATSendDataTerminalResponseUnable(void);
extern void TerminalResponseSendData(U8 res, U8 *cmdDetail);
extern void SATSendDataReq(void);
extern void DisplaySendDataWindow(void);
extern void SATSendDataRes(void *msgPtr);
extern void FreeSendData(void);

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
extern void SATRecvDataSIM1Ind(void *msgPtr);
extern void SATRecvDataSIM2Ind(void *msgPtr);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
extern void SATRecvDataInd(void *msgPtr);
extern void GoToRecvDataConformationScreen(void);
extern void SATRecvDataTerminalResponseExpire(void);
extern void SATRecvDataTerminalResponseUnable(void);
extern void TerminalResponseRecvData(U8 res, U8 *cmdDetail);
extern void SATRecvDataReq(void);
extern void DisplayRecvDataWindow(void);
extern void SATRecvDataRes(void *msgPtr);
extern void FreeRecvData(void);

extern void SATNotifyMMIInd(void *msgPtr);
#endif /* __SATCE__ */ 

/* diamond, 2006/01/14 restart please wait timer */
extern void mmi_sat_restart_please_wait_timer(U32 please_wait_time);
extern void mmi_sat_read_sim_file_with_path(U16 offset, U16 length, U8 *path); /* read from EF path, total 6 bytes for path */
extern void mmi_sat_clear_idle_display_text(U16 refresh_type);
extern void mmi_sat_refresh_to_update_imsi(U16 refresh_type);
extern void mmi_sat_get_msisdn_info(void);
extern void mmi_sat_get_spn_data(void);
extern void mmi_sat_nw_detach_before_reboot(void);
extern void mmi_sat_remove_text_pending_characters(U8 *text_string, U16 *text_length, U8 text_dcs);
extern void mmi_sat_refresh_next_file(void);

#ifdef __USAT__
extern void mmi_sat_terminal_response_get_inkey_digit(void);
extern U32 mmi_sat_count_get_inkey_user_rsp(void);
#endif /* __USAT__ */ 

extern void mmi_sat_get_color_lookup_table_req(void);
extern void mmi_sat_get_color_lookup_table_rsp(void *info);

#ifdef __MMI_UCM__
extern void mmi_sat_call_setup_ucm_request(void);
extern U8 mmi_sat_call_setup_screen_delete_callback(void *p);
#endif /* __MMI_UCM__ */

extern U16 gCurrLangIndex;

extern void RefreshNwProviderName(U8 *UpdatePlmn);
extern void EntryIdleScreen(void);

/* diamond, 2005/07/22 GET INPUT numeric input without 'p' and 'w' */
extern S16 MMI_current_input_ext_type;

extern void mmi_frm_sms_sim_refresh_ind(U16);
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);

#ifdef __GEMINI__
extern kal_bool is_test_sim(kal_uint8);
#else
extern kal_bool is_test_sim(void);
#endif

/* diamond, 2005/12/12 Display SS reponse */
extern void smsal_gsm7_unpack(U8 *, U8 *, U16, U16);
extern U16 smsal_msg_len_in_character(U8, U16, U8 last_byte);

extern S32 mmi_is_redrawing_bk_screens(void);

#endif /* __SAT__ */

#endif /* _PIXTEL_SATPROTS_H */ 

