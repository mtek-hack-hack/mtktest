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
 * SimDetectionGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Global functions declarations for Sim Detction module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : SimDetectionGprot.h

   PURPOSE     : Global functions declarations for Sim 
               Detction module.

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : 12/03/03

**************************************************************/

#ifndef _SIMDETECTION_GPROT_H
#define _SIMDETECTION_GPROT_H

#include "MMIDataType.h"
// #include "SimDetectionType.h"

#include "MMI_features.h"
extern void ReadPinQuery(void);
extern void SendMessageQuerySIMCard(void);
extern void EnterPINagain(void);
extern void ValidatePIN(void);
extern void ValidatePhoneLock(void);
extern void EntryScrEnterPIN(void);
extern void EntryMsgIdGetPinRsp(void *in);
extern void EntryScrnRequestSimInsertion(void);
extern void SimPasswdReqResponse(void *);
extern void SimQueryFailureRsp(void *);
extern void SimQueryFailureRsp(void *in);
extern void ServiceIndicationStringDisplay(void *);

extern void EntryScrnSimBlockRsp(void);
extern void ExitScrPinBlocked(void);

extern void EntryScrIncorrectPUK(void);
extern void EntryScrIncorrectPin(void);
extern void EntryScrEnterPUK(void);
extern void MakeSOSCall(void);
extern void EntryScrPinBlocked(void);
extern void EntryScrEnterNewPINFirstTime(void);
extern void EntryScrEnterNewPINSecondTime(void);
extern void EntryScrPinDoNotMatch(void);
extern void ValidateFirstAndSecondPin(void);
extern void ShowMakeSOSCallScr(void);
extern void InitNetWorkBootUpEventsCallBack(void);
extern void NetWorkAttachedIndication(void *inMsg);
extern void EntryScrEmergencyCallDialing(void);
extern void EntryScrEnterPhoneLock(void);
extern void NetWorkSignalLevelIndication(void *);
extern void NetWorkServiceTypeIndication(void *);
extern void ExitShowMakeSOSCallScr(void);
extern void NumberOfPLMNSuported(void *);
extern void ChangeRoamingState(void);
extern void RspToTestRoamingEnabled(void *);
extern void RequestToTestRoamingEnabled(void);
extern void EntryScrInvalidPUKTransiantScreen(void);
extern void EntryScrIncorrectPUK(void);
extern void EntryScrIncorrectPhoneLock(void);

extern pBOOL IsSOSCall(void);
extern pBOOL IsSOSPossible(void);
extern void EntryScrNoNetworkServiceMessage(void);
extern void EntryScrInvalidPINPUKPLOCKLength(void);

/* void CallBackPowerOnAnimationComplete(void); */
extern void ExitLowBatteryScrAtPowerOn(void);

extern void InitSimDetection(void);
extern void InitSimOptionApp(void);
extern void EntryScrnSimErrorScreen(void);
extern void ExitScrnSimErrorScreen(void);
extern void EntryScrSimOptionMenu(void);
extern void ShowWelcomeScr(void);

/* MTK Modified, Max, Joy: to add customized compile option 1001 */
#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 
extern void BeforeEntryIdleScr(void);

/* MTK end */

extern void ExitScrPUKBlocked(void);

extern PS8 GetCurrentPLMNName(S8 *);

extern void EntryScrNotSOSNumMessage(void);

//void PopulatePLMNList(void);
//void PopulateAphorismList(void);
extern void HandleInsertSIMScrDigitEntry(void);
extern void DialSOSNumber(void);
extern void ExitDialSOSNumber(void);

extern void GoToSOSDialScr(void);
extern void SimECCInfoSave(void *);

extern void EntryScrCodeVerified(void);

#ifdef __MMI_DUAL_SIM_MASTER__
extern pBOOL CheckValidEmergencyNo1(S8 *, U8);
#else
extern pBOOL CheckValidEmergencyNo1(S8 *);
#endif

extern PS8 GetHomePLMNName(void);
extern void SSCHandleEnterPUK(void);
extern void SSCHandleEnterPUKCommon(void);
extern void SSCHandleEnterPUKFromSecset1(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void SSCHandleEnterPUKFromSecset2(void);
#endif
extern void ExitSSCHandleEnterPUK(void);
extern void ValidateSSCStringPUK(void);
extern void MakeCallSSCStringPUK(void);

extern void ScrBootUpPasswordaValidation(U8 *, U8 *, S32);
extern void PUKLengthValidation(U8 *, U8 *, S32);

/* MTK added, for SIM refresh and abnormal reset 0912 */
extern U8 GetAbnormalReset(void);
extern void SetAbnormalReset(void);
extern void ResetAbnormalReset(void);

/* MTK end */

extern void ExitAphorismScreen(void);
extern void ExitWelcomeScreen(void);

extern void RemoveStatusIconsForSimRemoved(void);
extern void FirstTimeTurnOnBackLight(void);
extern void DisplayInvalidSimInfo(void);

/* micha0120 */
extern void UpdateGPRSStatusIcon(U8 gprs_state);
extern void GPRSStatusUpdateIndication(void *info);
extern void GPRSStatusGetGPRSModeReq(void);
extern void GPRSStatusGetGPRSModeRsp(void *info);
extern void GPRSStatusDetachGPRSReq(void);
extern void GPRSStatusDetachGPRSRsp(void *info);

#ifdef _NETWORK_CIPHER_SUPPORT_
extern void NetWorkCipherIndication(void *info);
#endif /* GSM/GPRS ciphering indication */

#ifdef __MANUAL_MODE_NW_SEL__
extern void PLMNSelectionModeIndication(void *info);
extern void PLMNGetSelectionModeRsp(void *info);
extern void PLMNGetSelectionModeReq(void);
#endif /* __MANUAL_MODE_NW_SEL__ */ 

/*****SubLCDFunctions********/
extern void ShowSubLCDSimError(void);
extern void ExitSubLCDSimError(void);
extern void ShowSubLCDBlockedSIM(void);
extern void ExitSubLCDBlockedSIM(void);
extern void ShowSubLCDEnterPIN(void);
extern void ExitSubLCDEnterPIN(void);
extern void ShowSubLCDEnterPUK(void);
extern void ExitSubLCDEnterPUK(void);
extern void ShowSubLCDEnterPhoneLock(void);
extern void ExitSubLCDEnterPhoneLock(void);

/***************************/

extern void PowerOnBatteryIndicationCompletePhase2(void);

#if defined(__FS_CHECKDRIVE_SUPPORT__)
extern void PWR_NAND_SanityCheck_response_handler(void);
#endif 

#ifdef __HOMEZONE_SUPPORT__
extern void HomezoneStatusIndication(void *info);
#endif 

/* diamond, 2005/08/16 bootup revise */
extern pBOOL mmi_bootup_is_in_power_on_period(void);
extern pBOOL mmi_bootup_is_searching_or_idle_reached(void);
extern pBOOL mmi_bootup_is_idle_screen_reached(void);
extern pBOOL mmi_bootup_is_power_on_animation_complete(void);
extern pBOOL mmi_bootup_is_in_security_check(void);
extern pBOOL mmi_bootup_is_before_power_on(void);
extern pBOOL mmi_bootup_is_playing_power_on_animation(void);
extern pBOOL mmi_bootup_is_sim_valid(void);
extern pBOOL mmi_bootup_is_sim_removed(void);
extern pBOOL mmi_bootup_is_sim_need_security_check(void);
extern pBOOL mmi_bootup_is_sim_failure_received(void);
extern pBOOL mmi_bootup_is_sim_refresh(void);
extern pBOOL mmi_bootup_is_roaming(void);
extern pBOOL mmi_bootup_is_network_searching_complete(void);
extern pBOOL mmi_bootup_is_nw_registration_ok(void);
extern pBOOL mmi_bootup_get_plmn_selection_mode(void);
extern pBOOL mmi_bootup_get_active_flight_mode(void);
extern pBOOL mmi_bootup_get_active_bt_access_profile_mode(void);
extern pBOOL mmi_bootup_is_network_service_available(void);
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern pBOOL mmi_bootup_is_sim2_valid(void);
extern pBOOL mmi_bootup_is_sim2_refresh(void);
extern pBOOL mmi_bootup_is_sim2_removed(void);
extern pBOOL mmi_bootup_is_sim2_roaming(void);
extern pBOOL mmi_bootup_is_in_sim2_security_check(void);
extern pBOOL mmi_bootup_is_sim2_power_on_animation_complete(void);
extern pBOOL mmi_bootup_is_sim2_searching_or_idle_reached(void);
extern pBOOL mmi_bootup_is_sim2_network_searching_complete(void);
extern pBOOL mmi_bootup_is_sim2_nw_registration_ok(void);
extern void mmi_bootup_update_sim1_status(void *info);
extern void mmi_bootup_update_sim2_status(void *info);
extern void mmi_bootup_power_on_sim1_flight_mode(void); /* case 11 */
extern void mmi_bootup_power_on_sim2_normal_mode(void); /* case 12 */
extern void mmi_bootup_power_on_sim1_flight_mode_rsp(void *info);
extern void mmi_bootup_power_on_sim2_normal_mode_rsp(void *info);
extern void mmi_bootup_rac1_activated_indication(void *info);
extern void mmi_bootup_rac2_activated_indication(void *info);
extern void mmi_bootup_network_search_finish_ind(void *info);
extern pBOOL mmi_bootup_is_power_on_mode_change_finish(void);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
/* end, diamond */

/* diamond, 2005/09/30 bootup revise */
extern void mmi_bootup_stop_countdown_screen(void);
extern void mmi_bootup_entry_disk_check(void);
extern void mmi_bootup_exit_disk_check(void);
extern void mmi_bootup_entry_flight_mode_query(void);
extern void mmi_bootup_exit_flight_mode_query(void);
extern void mmi_bootup_entry_animation(void);
extern void mmi_bootup_exit_animation(void);
extern void mmi_bootup_entry_low_battery_warning(void);
extern void mmi_bootup_exit_low_battery_warning(void);
extern void mmi_bootup_entry_nand_check_query(void);
extern void mmi_bootup_exit_nand_check_query(void);
extern void mmi_bootup_entry_security_check(void);
extern void mmi_bootup_exit_security_check(void);
extern void mmi_bootup_entry_welcome_screen(void);
extern void mmi_bootup_exit_welcome_screen(void);
extern void mmi_bootup_entry_aphorism_screen(void);
extern void mmi_bootup_exit_aphorism_screen(void);
extern void mmi_bootup_entry_network_searching(void);
extern void mmi_bootup_exit_network_searching(void);
extern void mmi_bootup_entry_idle_screen(void);
/* end, diamond */

/* diamond, 2006/03/08 New PLMN management */
extern S16 mmi_netset_retrieve_opname_from_plmn(U8 *plmn, U8 *opname);
extern pBOOL mmi_netset_equivalent_plmn_check(void);
extern pBOOL mmi_netset_is_t_mobile_us_sim(void);
extern void mmi_netset_sort_plmn_list_by_alphabet(U16 total_record);
extern void mmi_netset_sort_plmn_list_by_default(U16 total_record);
extern MMI_BOOL mmi_netset_plmn_matching_criteria(const U8 *sim_plmn, const U8 *bcch_plmn);

#ifndef __MTK_TARGET__ /* MoDIS only */
extern void mmi_netset_write_auto_test_result(pBOOL result);
#endif
extern MMI_BOOL mmi_netset_is_cell_support_egprs(void);

#ifdef __MMI_SIMAP_SUPPORT__
extern void mmi_sim_error_update_sim_access_profile_menu_items(void);
extern void mmi_sim_error_restore_sim_access_profile_menu_items(void);
#endif /* __MMI_SIMAP_SUPPORT__ */

extern void mmi_sim_error_idle_toggle_profile(void);
extern void mmi_sim_error_reset_input_password_guibuffer(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_sim_error_notify_bootup_ready_to_wap(void);
#endif
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern void mmi_sim_error_set_emergency_call_path(void);
#endif

#endif /* _SIMDETECTION_GPROT_H */ 

