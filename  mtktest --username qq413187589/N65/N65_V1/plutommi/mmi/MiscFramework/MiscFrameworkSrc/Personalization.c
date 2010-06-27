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
 * Personalization.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Personalization check
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
 * removed!
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

   FILENAME : Personalization.c

   PURPOSE     : Does Personalization check

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 12/03/03

**************************************************************/

#include "MMI_include.h"

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "UCS2prot.h"
#include "TaskInit.h"
#include "wgui_status_icons.h"
#include "SimDetectionHwMapFile.h"
// #include "SimDetectionType.h"
#include "SimDetectionDef.h"

#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "audioinc.h"
#include "SimDetectionDef.h"
#include "PersonalizationDef.h"
// #include "PersonalizationGdcl.h"
#include "PersonalizationProt.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"

#include "custom_util.h"

/* micha1230 */
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "SettingsGdcl.h"
#include "FlightModeGProt.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "Wgui_touch_screen.h"
#endif 

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
#include "custom_nvram_extra.h"
extern mmi_sml_menu_struct g_sml_context;
#endif /* __MMI_SML_UNLOCK_AFTER_VERIFIED__ */


#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
extern void mmi_sml_set_next_attempt_function(FuncPtr func, S32 countdown);
#endif


/* micha1230 */
extern U8 gCPHSRetryCount;

//extern U8 idleScreenFirst;
//extern U8 gPowerOnPeriod;


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNP
 * DESCRIPTION
 *  Function inputs NP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterNP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2(temp2, temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_NP, NULL, EntryScrEnterNP, NULL);
#ifdef __MMI_SML_NP_ONLY__
    if (g_pwr_context.PowerOnMMIStatus != MMI_POWER_ON_IDLE)
    {
#endif
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_NP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */
#ifdef __MMI_SML_NP_ONLY__
    }
#endif
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_NP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateNP, KEY_EVENT_UP);
    SetKeyHandler(ValidateNP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateNP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNSP
 * DESCRIPTION
 *  Function inputs NSP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterNSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_NSP, NULL, EntryScrEnterNSP, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_NSP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_NSP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateNSP, KEY_EVENT_UP);
    SetKeyHandler(ValidateNSP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateNSP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterSP
 * DESCRIPTION
 *  Function inputs SP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_SP, NULL, EntryScrEnterSP, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_SP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_SP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateSP, KEY_EVENT_UP);
    SetKeyHandler(ValidateSP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateSP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterCP
 * DESCRIPTION
 *  Function inputs CP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterCP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_CP, NULL, EntryScrEnterCP, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_CP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_CP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateCP, KEY_EVENT_UP);
    SetKeyHandler(ValidateCP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateCP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterSIMP
 * DESCRIPTION
 *  Function inputs SIMP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterSIMP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_SIMP, NULL, EntryScrEnterSIMP, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_SIMP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_SIMP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateSIMP, KEY_EVENT_UP);
    SetKeyHandler(ValidateSIMP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateSIMP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectNP
 * DESCRIPTION
 *  Flash Message Incorrect NP try again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectNP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterNP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_N_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_NP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectSP
 * DESCRIPTION
 *  Flash Message Incorrect SP try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterSP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_SP_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_SP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectCP
 * DESCRIPTION
 *  Flash Message Incorrect CP try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectCP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterCP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_C_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_CP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectNSP
 * DESCRIPTION
 *  Flash Message Incorrect NSP try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectNSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterNSP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_NS_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_NSP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectSIMP
 * DESCRIPTION
 *  Flash Message Incorrect SIMP try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectSIMP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterSIMP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_SIM_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_SIMP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  ValidateNP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */

    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    //PRINT_INFORMATION("@@@@@ Sending request for verifying NP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_NP;

    /* 1. Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_N], (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_NP_ONLY__
    if (!mmi_bootup_is_in_power_on_period())
    {
        gSecuritySetupContext.VerifyPassSuccessCallBack = mmi_bootup_sim_verify_success;
        SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
    }
#endif /* __MMI_SML_NP_ONLY__ */

#endif /* __MMI_SML_UNLOCK_AFTER_VERIFIED__ */ 

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  ValidateSIMP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateSIMP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */

    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    //PRINT_INFORMATION("@@@@@ Sending request for verifying SIMP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_IMSI_LOCK;

    /* 1. Change gInputSIMPBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_SIM], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  ValidateSP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    //PRINT_INFORMATION("@@@@@ Sending request for verifying SP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_SP;

    /* 1. Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_SP], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  ValidateCP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateCP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    //PRINT_INFORMATION("@@@@@ Sending request for verifying CP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_CP;

    /* 1. Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_C], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  ValidateNSP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */

    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    //PRINT_INFORMATION("@@@@@ Sending request for verifying NSP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_NSP;

    /* 1. Change gInputNSPBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_NS], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


#ifdef __MMI_SML_MENU__
/*****************************************************************************
 * FUNCTION
 *  ValidateNSP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNSSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    //PRINT_INFORMATION("@@@@@ Sending request for verifying NSSP  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_LINK_NS_SP;

    /* 1. Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_NS_SP], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNSP
 * DESCRIPTION
 *  Function inputs NS-SP from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterNSSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_NS_SP, NULL, EntryScrEnterNSSP, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_NS_SP;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_NSSP_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateNSSP, KEY_EVENT_UP);
    SetKeyHandler(ValidateNSSP, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateNSSP;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectSP
 * DESCRIPTION
 *  Flash Message Incorrect NS-SP try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectNSSP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterNSSP, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_NS_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_NSSP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  ValidateNSP
 * DESCRIPTION
 *  Function to validate password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateSIMC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Validate password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    MYQUEUE Message;
    MMISMUVERIFYPINREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        EntryScrInvalidPINPUKPLOCKLength();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    //PRINT_INFORMATION("@@@@@ Sending request for verifying SIMC  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha0420 */
    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMISMUVERIFYPINREQ*) OslConstructDataPtr(sizeof(MMISMUVERIFYPINREQ));
    local_data->pin_type = MMI_TYPE_UNSPECIFIED; //MMI_TYPE_LINK_SIM_C;

    /* 1. Change gInputPwdBuffer to ASCII then copy local_data->pin */
    mmi_ucs2_to_asc((S8*) local_data->pin, (S8*) gInputPwdBuffer);

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    mmi_ucs2_to_asc((S8*) g_sml_context.auto_unlock_key[SML_CAT_SIM_C], (S8*) gInputPwdBuffer);
#endif

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEnterNSP
 * DESCRIPTION
 *  Function inputs SIM-C from the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEnterSIMC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1230 */
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp1, "%d", gCPHSRetryCount);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    EntryNewScreen(SCR_ENTER_SIM_C, NULL, EntryScrEnterSIMC, NULL);
    DinitHistory();
    g_pwr_context.PrevScreenIndicator = ENTER_SIM_C;

    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_RSK_SOS,
        0,
        STR_ENTER_SIMC_MSG,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) gInputPwdBuffer,
        /* micha1230 */ MAX_PWD_LENGTH_MMI,
        (U8*) temp1,
        NULL);

    SetLeftSoftkeyFunction(ValidateSIMC, KEY_EVENT_UP);
    SetKeyHandler(ValidateSIMC, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(GoToSOSDialScr,KEY_SEND,KEY_EVENT_UP);
    }

    /* Disable LSK if the input password length isn't enough */
    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateSIMC;
    if (mmi_ucs2strlen((S8*) gInputPwdBuffer)  < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncorrectSP
 * DESCRIPTION
 *  Flash Message Incorrect SIM-C try again
 *  
 *  For h/w this fn will be called in response of L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncorrectSIMC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    mmi_sml_popup_error_msg(gCPHSRetryCount);
    mmi_sml_set_next_attempt_function(EntryScrEnterSIMC, mmi_sml_count_retry_interval(gCPHSRetryCount, SML_RETRY_COUNT_C_CAT - 1));
    GenericExitScreen(SCR_ID_SML_WAIT_ATTEMPT, mmi_sml_entry_please_wait_next_attempt);
#else /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    DisplayPopup((U8*) GetString(STR_WRONG_SIMC_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
}

#endif /* __MMI_SML_MENU__ */

