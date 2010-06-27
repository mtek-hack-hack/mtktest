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
 * SecuritySetup.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Security Setup related functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef _SECURITYSETUP_H
#define _SECURITYSETUP_H

typedef struct
{
    U8 HighlightedFDN;
    U8 HighlightedBDN;
    MMI_PHB_ENTRY_STRUCT FDLBDLEntries[MAX_SIM_ENTRIES];
    U8 MaxFDL;
    U8 MaxBDL;
    U8 FDNBDNCount;
    U8 FDNBDNEdit;
    InlineItem FDLBDLInlineDisplay[2];
    U8 FDLBDLName[(MAX_NAME_LEN_FSB_LIST + 1) *ENCODING_LENGTH];
    U8 FDLBDLNumber[(MAX_NUMBER_LEN_FSB_LIST + 1 + 1) *ENCODING_LENGTH];
    U8 is_set_toggle;
    U8 small_screen;
    U8 is_fdn;
} FDLBDLContext;

extern void HighlightSecurity(void);
extern void HighlightSIMLock(void);
extern void HighlightPhoneLock(void);

#ifdef __MMI_AUTO_KEYPAD_LOCK__
extern void HighlightAutoKeyPadLock(void);
#endif 
extern void HighlightFixedDial(void);
extern void HighlightFdlMode(void);
extern void HighlightFdlList(void);
extern void HighlightBarredDial(void);
extern void HighlightBdlMode(void);
extern void HighlightBdlList(void);
extern void HighlightChangePassword(void);
extern void HighlightPin1Passwd(void);
extern void HighlightPin2Passwd(void);
extern void HighlightPhonePasswd(void);
#ifdef __CERTMAN_SUPPORT__
extern void HighlightCertificateManager(void);
extern void mmi_certman_launch_certficate_manager(void);
#endif /*__CERTMAN_SUPPORT__*/

extern void HintSimLock(U16 index);
extern void HintPhoneLock(U16 index);

#ifdef __MMI_AUTO_KEYPAD_LOCK__
extern void HintAutoKeypadLock(U16 index);
#endif 
extern void HintFdl(U16 index);
extern void HintBdl(U16 index);
extern void HintFdlMode(U16 index);
extern void HintBdlMode(U16 index);

extern void EntrySECSETMain(void);
extern void EntrySECSETPhoneLock(void);
extern void ExitSECSETPhoneLock(void);

#ifdef __MMI_AUTO_KEYPAD_LOCK__
extern void EntrySECSETAKPLTime(void);
#endif 
extern void EntrySECSETPIN2(void);
extern void ExitSECSETPIN2(void);
extern void EntrySECSETFixDial(void);
extern void EntrySECSETBarDial(void);
extern void EntrySECSETChangePassword(void);
extern void ExitSECSETChangePassword(void);
extern void EntrySECSETChangePWOldPWD(void);
extern void ExitSECSETChangePWOldPWD(void);
extern void EntrySECSETChangePWNewPWD(void);
extern void ExitSECSETChangePWNewPWD(void);
extern void EntrySECSETChangePWCfmPWD(void);
extern void ExitSECSETChangePWCfmPWD(void);
extern void EntrySECSETPUK1(void);
extern void ExitSECSETPUK1(void);
extern void EntrySECSETPUKNewPIN1(void);
extern void ExitSECSETNewPIN1(void);
extern void EntrySECSETPUKConfirmPIN1(void);
extern void ExitSECSETNewPIN1Confirm(void);
extern void EntrySECSETPUK2(void);
extern void ExitSECSETPUK2(void);
extern void EntrySECSETPUK2NewPIN2(void);
extern void ExitSECSETNewPIN2(void);
extern void EntrySECSETPUK2ConfirmPIN2(void);
extern void ExitSECSETNewPIN2Confirm(void);
extern void EntrySECSETSIMLockPIN1(void);
extern void ExitSECSETSIMLockPIN1(void);

extern void SECSETSetSIMLockReq(void);
extern void SECSETSetSIMLockSuccess(void);
extern void SECSETSetSIMLockFail(void);
extern void SECSETSetPhoneLockReq(void);
extern void SECSETSetPhoneLockSuccess(void);
extern void SETSETSetPhoneLockFail(void);
extern void SECSETSMULockRsp(void *info);
extern void SECSETGetPIN1ForChangeReq(void);
extern void SECSETGetPIN1ForChangeRsp(void *info);
extern void SECSETGetPIN2ForChangeReq(void);
extern void SECSETGetPIN2ForChangeRsp(void *info);
extern void SECSETGetPIN1StatusReq(void);
extern void SECSETGetPIN1StatusRsp(void *info);
extern void SECSETGetPIN2StatusReq(void);
extern void SECSETGetPIN2StatusRsp(void *info);
extern void SECSETVerifyPINReq(U8 pin_type, U8 *ucs2_pin, U8 *ucs2_new_pin, FuncPtr success_callback);
extern void SECSETVerifyPINRsp(void *info);
extern void SECSETGetFdlBdlModeReq(void);
extern void SECSETGetFdlBdlModeRsp(void *info);
extern void SECSETSetFdlModeReq(void);
extern void SECSETSetFdlModeRsp(void *info);
extern void SECSETSetBdlModeReq(void);
extern void SECSETSetBdlModeRsp(void *info);
extern void SECSETGetBdlStatusReq(void);
extern void SECSETGetBdlStatusRsp(void *info);
extern void SECSETGetFdlStatusReq(void);
extern void SECSETGetFdlStatusRsp(void *info);
extern void SECSETChangePasswordPhoneRsp(void *info);

extern void AutoKeyPadLockTimeHandler(S32 index);
extern void SendAKPLTimeMessageAndShowScreen(void);
extern void VerifyPin2(void);
extern void SendReqToChangePwd(void);
extern SETTING_AKPL_TIME GetAutoKeypadLockTime(void);
extern void SettingChangePasswdPuk(void);
extern void GoBackToPasswordScr(void);
extern void DialSoSPUK1(void);
extern void DialSoSNewPIN1(void);
extern void DialSoSNewPIN1Conf(void);
extern void ValidateNewPin1(void);
extern void ValidateNewPin1Success(void);
extern void ValidateNewPin2(void);
extern void EntryFdlList(void);
extern void EntryBdlList(void);
extern void ScrSettingPukValidation(U8 *text, U8 *cursor, S32 length);
extern void FillCountDownNumber(sim_chv_info_struct chv_info);
extern void FillCountDownString(U8 TypeOfPass, U8 *PassCountdownDisp);
extern void ChangePasswordPIN2SuccessCallBack(void);

extern void mmi_secset_set_fixed_dial_mode(void);
extern void mmi_secset_set_barred_dial_mode(void);
extern void mmi_secset_at_cmd_update_chv(void *info);

extern void mmi_secset_delete_upto_puk1(void);
extern void mmi_secset_delete_upto_puk2(void);
extern void mmi_secset_delete_upto_idle_screen(void);
extern void mmi_secset_delete_puk1_and_puk2(void);
extern void mmi_secset_force_to_delete_upto_puk1(void); /* add for AT command to block SIM */

extern void mmi_secset_entry_scr_pin_blocked(void);
extern void mmi_secset_exit_scr_pin_blocked(void);
extern U8 mmi_secset_is_call_interrupt(void);

extern pBOOL phonebookReady;
extern FDLBDLContext gFDLBDLContext;

#endif /* _SECURITYSETUP_H */ 

