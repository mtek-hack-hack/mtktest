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
 * SecuritySetup.c
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

#include "MMI_include.h"
#include "MainMenuDef.h"
#include "CallsDefs.h"
#include "settingstructs.h"
#include "settinggprots.h"
#include "SimDetectionGprot.h"
#include "ProtocolEvents.h"
#include "CallFixedDial.h"
#include "BarredDialList.h"
#include "SettingProfile.h"
#include "PhoneBookDef.h"
#include "CommonScreens.h"
#include "CallSetUpEnum.h"
#include "SettingProt.h"
#include "NetworkSetupGProt.h"
#include "OrganizerGProt.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "SimDetectionGexdcl.h"
#include "SettingsGexdcl.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "PhoneBookGprot.h"
#include "CallManagementGProt.h"
#include "SecuritySetup.h"
#include "ProfileGprots.h"
#include "SSCStringHandle.h"
#include "GSM7BitDefaultAlphabet.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "Wgui_touch_screen.h"
#endif

#ifdef __MMI_SML_MENU__
#include "PersonalizationDef.h"
#include "PersonalizationProt.h"
#endif

#include "FlightModeGProt.h"

#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

extern kal_bool smu_query_phone_lock_enabled(void);
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
extern S32 mmi_is_redrawing_bk_screens(void);
extern void mmi_sim_error_hide_menu_items(void);

SecuritySetupContext gSecuritySetupContext;


/*****************************************************************************
 * FUNCTION
 *  InitSecuritySetupApp
 * DESCRIPTION
 *  Initialize Security
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSecuritySetupApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU9101_SECURITY, HighlightSecurity);
    SetHiliteHandler(MENU9169_SIM_LOCK, HighlightSIMLock);
    SetHiliteHandler(MENU9165_PHONE_LOCK, HighlightPhoneLock);
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    SetHiliteHandler(MENU9178_AKPL_TIME, HighlightAutoKeyPadLock);
#endif 
    SetHiliteHandler(MENU9167_FIXED_DIAL, HighlightFixedDial);
    SetHiliteHandler(MENU_SETTING_FDL_MODE, HighlightFdlMode);
    SetHiliteHandler(MENU_SETTING_FDL_LIST, HighlightFdlList);
    SetHiliteHandler(MENU9168_BARRED_DAIL, HighlightBarredDial);
    SetHiliteHandler(MENU_SETTING_BDL_MODE, HighlightBdlMode);
    SetHiliteHandler(MENU_SETTING_BDL_LIST, HighlightBdlList);
    SetHiliteHandler(MENU9170_CHANGE_PASSWORD, HighlightChangePassword);
    SetHiliteHandler(MENU9174_CP_PIN1, HighlightPin1Passwd);
    SetHiliteHandler(MENU9175_CP_PIN2, HighlightPin2Passwd);
    SetHiliteHandler(MENU9173_CP_PHONE_LOCK, HighlightPhonePasswd);

#ifdef __CERTMAN_SUPPORT__
    SetHiliteHandler(MENU_CERTIFICATE_MANAGER, mmi_certman_highlight_launch_certficate_manager);
#endif /*__CERTMAN_SUPPORT__*/

    SetHintHandler(MENU9169_SIM_LOCK, HintSimLock);
    SetHintHandler(MENU9165_PHONE_LOCK, HintPhoneLock);
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    SetHintHandler(MENU9178_AKPL_TIME, HintAutoKeypadLock);
#endif 
    SetHintHandler(MENU9167_FIXED_DIAL, HintFdl);
    SetHintHandler(MENU9168_BARRED_DAIL, HintBdl);
    SetHintHandler(MENU_SETTING_FDL_MODE, HintFdlMode);
    SetHintHandler(MENU_SETTING_BDL_MODE, HintBdlMode);

    /*
     * gSecuritySetupContext.FdlStatus = 0;
     * gSecuritySetupContext.BdlStatus = 0;
     * gSecuritySetupContext.SimLockStatus = 0;
     * gSecuritySetupContext.PhoneLockStatus = 0;
     * gSecuritySetupContext.AutoKeyPadLockTime = 0;
     * gSecuritySetupContext.CurrentPassword = 0;
     * gSecuritySetupContext.PINBlocked = 0;
     * gSecuritySetupContext.CHV1Count = 0;
     * gSecuritySetupContext.CHV2Count = 0;
     * gSecuritySetupContext.UBCHV1Count = 0;
     * gSecuritySetupContext.UBCHV2Count = 0;
     */

    gSecuritySetupContext.SMULockSuccessCallBack = NULL;
    gSecuritySetupContext.SMULockFailCallBack = NULL;
    gSecuritySetupContext.VerifyPassSuccessCallBack = NULL;

    /* diamond, 2006/02/27 Move this function call to another timing */
    /* GetPhoneLock(); */

#ifdef __MMI_SML_MENU__
    mmi_sml_init();
#endif

    SetProtocolEventHandler(mmi_secset_at_cmd_update_chv, MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSecurity
 * DESCRIPTION
 *  HighLight Security-Setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSecurity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntrySECSETMain, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSIMLock
 * DESCRIPTION
 *  Highlight fn for SimLock Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSIMLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.SimLockStatus != CHV_DISABLED)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntrySECSETSIMLockPIN1, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETSIMLockPIN1, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhoneLock
 * DESCRIPTION
 *  highlight phone lock option in security setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetParentHandler() == MENU9101_SECURITY
#if defined(__MMI_DUAL_SIM_MASTER__)
        || GetParentHandler() == MENU_MTPNP_DM_SECURITY_SETTING
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */
        )
    {
        if (gSecuritySetupContext.PhoneLockStatus)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntrySECSETPhoneLock, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETPhoneLock, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAutoKeyPadLock
 * DESCRIPTION
 *  Highlight handler for Autokeypadlock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_AUTO_KEYPAD_LOCK__
void HighlightAutoKeyPadLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntrySECSETAKPLTime, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETAKPLTime, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_AUTO_KEYPAD_LOCK__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightFixedDial
 * DESCRIPTION
 *  Highlight handler for fixed dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFixedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(SECSETGetFdlStatusReq, KEY_EVENT_UP);
    SetKeyHandler(SECSETGetFdlStatusReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightFdlMode
 * DESCRIPTION
 *  Highlight handler for FDL mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFdlMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.FdlStatus)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_secset_set_fixed_dial_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_secset_set_fixed_dial_mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightFdlList
 * DESCRIPTION
 *  Highlight handler for FDL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFdlList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    SetLeftSoftkeyFunction(EntryFdlList, KEY_EVENT_UP);
    SetKeyHandler(EntryFdlList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBarredDial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBarredDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(SECSETGetBdlStatusReq, KEY_EVENT_UP);
    SetKeyHandler(SECSETGetBdlStatusReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBdlMode
 * DESCRIPTION
 *  Highlight handler for BDL mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBdlMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.BdlStatus)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_secset_set_barred_dial_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_secset_set_barred_dial_mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBdlList
 * DESCRIPTION
 *  Highlight handler for BDL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBdlList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    SetLeftSoftkeyFunction(EntryBdlList, KEY_EVENT_UP);
    SetKeyHandler(EntryBdlList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChangePassword
 * DESCRIPTION
 *  Highlight handler for Change password option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChangePassword(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntrySECSETChangePassword, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETChangePassword, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPin1Passwd
 * DESCRIPTION
 *  Highlight handler for Change Pin1 option in change pwd screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPin1Passwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.CurrentPassword = 0;
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(SECSETGetPIN1ForChangeReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(SECSETGetPIN1ForChangeReq, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPin2Passwd
 * DESCRIPTION
 *  Highlight handler for Change Pin2 option in change pwd screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPin2Passwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.CurrentPassword = 1;
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(SECSETGetPIN2ForChangeReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(SECSETGetPIN2ForChangeReq, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhonePasswd
 * DESCRIPTION
 *  Highlight handler for Change phone lock option in change pwd screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhonePasswd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.CurrentPassword = 2;
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(EntrySECSETChangePWOldPWD, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySECSETChangePWOldPWD, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HintSimLock
 * DESCRIPTION
 *  Hint Hnadler for Sim Lock.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintSimLock(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (gSecuritySetupContext.SimLockStatus == CHV_DISABLED)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintPhoneLock
 * DESCRIPTION
 *  Hint handler for Phone lock.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhoneLock(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (GetPhoneLock())
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintAutoKeypadLock
 * DESCRIPTION
 *  Hint handler for AutoKeypad lock.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_AUTO_KEYPAD_LOCK__
void HintAutoKeypadLock(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (0 != GetAutoKeypadLockTime())
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}
#endif /* __MMI_AUTO_KEYPAD_LOCK__ */ 


/*****************************************************************************
 * FUNCTION
 *  HintFdl
 * DESCRIPTION
 *  Hint handler for FDL.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintFdl(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (gSecuritySetupContext.FdlStatus)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintBdl
 * DESCRIPTION
 *  Hint handler for BDL
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintBdl(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (gSecuritySetupContext.BdlStatus)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintFdlMode
 * DESCRIPTION
 *  Hint handler for FDL mode.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintFdlMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (gSecuritySetupContext.FdlStatus)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintBdlMode
 * DESCRIPTION
 *  Hint handler for BDL Mode.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintBdlMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (gSecuritySetupContext.BdlStatus)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETMain
 * DESCRIPTION
 *  enter security-setup menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *SecurityType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_MAIN, NULL, EntrySECSETMain, NULL);

    /* 2 Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_MAIN);

    /* 3 Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU9101_SECURITY);

    /* 4 Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU9101_SECURITY, nStrItemList);

    /* 5 Set current parent id */
    SetParentHandler(MENU9101_SECURITY);

    /* 6 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 7 Construct the Hints List */
    ConstructHintsList(MENU9101_SECURITY, SecurityType);

    /* 8 Display Category52 Screen */
    ShowCategory52Screen(
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SCR9002_SECURITY_CAPTION,
    #else
        STRING_MTPNP_CARD1_SECURITY_SETTING,
    #endif
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        SecurityType,
        0,
        0,
        guiBuffer);

    /* 9 Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPhoneLock
 * DESCRIPTION
 *  entry sceen to enter phonelock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PHONE_LOCK, ExitSECSETPhoneLock, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PHONE_LOCK);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PHONE_LOCK);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    /* START VIJAY PMT 20060103 */
#if defined UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 
    /* END VIJAY PMT 20060103 */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_RESTORE_PHONE,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.Password,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(SECSETSetPhoneLockReq, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SECSETSetPhoneLockReq, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = SECSETSetPhoneLockReq;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETPhoneLock
 * DESCRIPTION
 *  Exit screen for enter phone lock screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* * Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PHONE_LOCK;
    Scr.entryFuncPtr = EntrySECSETPhoneLock;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETAKPLTime
 * DESCRIPTION
 *  Entry screen for Autokeypadlock Time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_AUTO_KEYPAD_LOCK__
void EntrySECSETAKPLTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

    U8 data1 = 0;
    S16 error1 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_AKPL_TIME, NULL, EntrySECSETAKPLTime, NULL);

    /* 2 Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_AKPL_TIME);

    /* 3 Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU9178_AKPL_TIME);

    /* 4 Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU9178_AKPL_TIME, nStrItemList);

    /* 5 Set current parent id */
    SetParentHandler(MENU9178_AKPL_TIME);

    /* 6 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(AutoKeyPadLockTimeHandler);

    ReadValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &data1, DS_BYTE, &error1);
    if (data1 == 0xff)
    {
        data1 = 0;
        WriteValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &data1, DS_BYTE, &error1);
    }

    gSecuritySetupContext.AutoKeyPadLockTime = data1;

    /* 8 Display Category11 Screen */
    ShowCategory11Screen(
        STR_MENU9166_AUTO_KEYPAD_LOCK,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16) data1,
        guiBuffer);

    /* 9 Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(SendAKPLTimeMessageAndShowScreen, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_AUTO_KEYPAD_LOCK__ */ 


/*****************************************************************************
 * FUNCTION
 *  AutoKeyPadLockTimeHandler
 * DESCRIPTION
 *  Handler function when user select any of the given
 *  options in autokeypad lock time screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AutoKeyPadLockTimeHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentOnOff = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  SendAKPLTimeMessageAndShowScreen
 * DESCRIPTION
 *  Set hint handler as On or Off for autokeypad lock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendAKPLTimeMessageAndShowScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    data = gCurrentOnOff;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (data)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(2, hintData[index]);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(2, hintData[index]);
    }
    RedrawCategoryFunction();

    if (gSecuritySetupContext.AutoKeyPadLockTime != gCurrentOnOff)
    {
        WriteValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &data, DS_BYTE, &error);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        DeleteNHistory(1);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN2StatusReq
 * DESCRIPTION
 *  Send request to L4 to get the status of PIN2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN2StatusReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetProtocolEventHandler(SECSETGetPIN2StatusRsp, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN2StatusRsp
 * DESCRIPTION
 *  Response of request to get the status of PIN2.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN2StatusRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMUSTATUSRSP *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (SMUSTATUSRSP*) (info);

    FillCountDownNumber(resp->chv_info);
    if (resp->chv_status.chv2_status == CHV_BLOCKED)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_SETTING_PIN2_BLK2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_PIN2_BLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
        mmi_secset_delete_upto_puk2();
    }
    else if (resp->chv_status.chv2_status == CHV_RETRY_ALLOW || resp->chv_status.chv2_status == CHV_VERIFIED)
    {
        if (gFDLBDLContext.is_set_toggle == 1)
        {
            gFDLBDLContext.is_set_toggle = 0;
            gFDLBDLContext.small_screen = 1;
        }
        else
        {
            gFDLBDLContext.small_screen = 0;
        }
        EntrySECSETPIN2();
    }
    else if (resp->chv_status.chv2_status == CHV_INVALID_TYPE || resp->chv_status.chv2_status == CHV_DEAD || resp->chv_status.chv2_status == CHV_NOTINITED)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PIN2_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN1StatusReq
 * DESCRIPTION
 *  Send request to L4 to get the status of PIN1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN1StatusReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(SECSETGetPIN1StatusRsp, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN1StatusRsp
 * DESCRIPTION
 *  Response of request to get the status of PIN1.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN1StatusRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMUSTATUSRSP *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (SMUSTATUSRSP*) (info);

    FillCountDownNumber(resp->chv_info);
    gSecuritySetupContext.SimLockStatus = resp->chv_status.chv1_status;
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPIN2
 * DESCRIPTION
 *  Entry fn to enter PIN2 for FDL.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPIN2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PIN2, ExitSECSETPIN2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PIN2);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    FillCountDownString(MMI_SETTING_TYPE_CHV2, PassCountdownDisp);
#if defined UI_SMALL_PIN_EDITOR_SCREEN
    if (gFDLBDLContext.small_screen == 1)
    {
        enable_resized_small_screen();
    }
#endif 
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SCR9027_PIN2_CAPTION,
    #else
        STRING_MTPNP_ENTER_CARD1PIN2,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.Password,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        PassCountdownDisp,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(VerifyPin2, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(VerifyPin2, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = VerifyPin2;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETPIN2
 * DESCRIPTION
 *  Exit Fixed dial menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETPIN2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PIN2;
    Scr.entryFuncPtr = EntrySECSETPIN2;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  VerifyPin2
 * DESCRIPTION
 *  Verify Pin2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VerifyPin2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    SECSETVerifyPINReq(MMI_SETTING_TYPE_CHV2, gSecuritySetupContext.Password, tempBuffer, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFixDial
 * DESCRIPTION
 *  Entry screen for FDL option screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFixDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *FdlType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FIX_DIAL, NULL, EntrySECSETFixDial, NULL);

    /* 2 Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_FIX_DIAL);

    /* 3 Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU9167_FIXED_DIAL);

    /* 4 Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU9167_FIXED_DIAL, nStrItemList);

    /* 5 Set current parent id */
    SetParentHandler(MENU9167_FIXED_DIAL);

    /* 6 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 7 Construct the Hints List */
    ConstructHintsList(MENU9167_FIXED_DIAL, FdlType);

    /* 8 Display Category52 Screen */
    ShowCategory52Screen(
        STR_MENU9167_FIXED_DIAL,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        FdlType,
        0,
        0,
        guiBuffer);

    /* 9 Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBarDial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBarDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *BdlType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_BAR_DIAL, NULL, EntrySECSETBarDial, NULL);

    /* 2 Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_BAR_DIAL);

    /* 3 Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU9168_BARRED_DAIL);

    /* 4 Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU9168_BARRED_DAIL, nStrItemList);

    /* 5 Set current parent id */
    SetParentHandler(MENU9168_BARRED_DAIL);

    /* 6 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 7 Construct the Hints List */
    ConstructHintsList(MENU9168_BARRED_DAIL, BdlType);

    /* 8 Display Category52 Screen */
    ShowCategory52Screen(
        STR_MENU9168_BARRED_DAIL,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        BdlType,
        0,
        0,
        guiBuffer);

    /* 9 Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetSIMLockReq
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetSIMLockReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    MMISMULOCKREQSTRUCT *smuLockReq;
    S8 pOutBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);

    smuLockReq = OslConstructDataPtr(sizeof(MMISMULOCKREQSTRUCT));

    if (gSecuritySetupContext.SimLockStatus != CHV_DISABLED)
    {
        smuLockReq->opcode = MMI_DISABLE;
    }
    else
    {
        smuLockReq->opcode = MMI_ENABLE;
    }

    smuLockReq->type = (U8) MMI_SETTING_TYPE_CHV1;

    memset(smuLockReq->passwd, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.Password);
    memcpy(smuLockReq->passwd, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    gSecuritySetupContext.SMULockSuccessCallBack = SECSETSetSIMLockSuccess;
    gSecuritySetupContext.SMULockFailCallBack = SECSETSetSIMLockFail;
    SetProtocolEventHandler(SECSETSMULockRsp, PRT_MMI_SMU_LOCK_RSP);

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_LOCK_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) smuLockReq;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetSIMLockSuccess
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetSIMLockSuccess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (gSecuritySetupContext.SimLockStatus != CHV_DISABLED)
    {
        gSecuritySetupContext.SimLockStatus = CHV_DISABLED;
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(0, hintData[index]);
        change_left_softkey(STR_GLOBAL_ON, 0);
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_SETTING_SIM_UNLOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_SETTING_CARD1_SIM_UNLOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #endif
    }
    else
    {
        gSecuritySetupContext.SimLockStatus = CHV_VERIFIED;
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(0, hintData[index]);
        change_left_softkey(STR_GLOBAL_OFF, 0);
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_SETTING_SIM_LOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_SETTING_CARD1_SIM_LOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #endif
    }

    DeleteScreenIfPresent(SCR_ID_SECSET_SIM_LOCK_PIN1);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetSIMLockFail
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetSIMLockFail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    DisplayPopup((PU8) GetString(STR_WRONG_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
#else
    DisplayPopup((PU8) GetString(STRING_MTPNP_WRONG_CARD1_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
#endif
    if (GetHistoryScrID(SCR_ID_SECSET_SIM_LOCK_PIN1, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetPhoneLockReq
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetPhoneLockReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    MMISMULOCKREQSTRUCT *smuLockReq;
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    MMISMULOCKREQSTRUCT *smuLock2Req;
#endif
    S8 pOutBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);

    smuLockReq = OslConstructDataPtr(sizeof(MMISMULOCKREQSTRUCT));

    if (gSecuritySetupContext.PhoneLockStatus)
    {
        smuLockReq->opcode = MMI_DISABLE;
    }
    else
    {
        smuLockReq->opcode = MMI_ENABLE;
    }

    smuLockReq->type = (U8) MMI_SETTING_TYPE_PHONELOCK;

    memset(smuLockReq->passwd, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.Password);
    memcpy(smuLockReq->passwd, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    smuLock2Req = OslConstructDataPtr(sizeof(MMISMULOCKREQSTRUCT));

    if (gSecuritySetupContext.PhoneLockStatus)
    {
        smuLock2Req->opcode = MMI_DISABLE;
    }
    else
    {
        smuLock2Req->opcode = MMI_ENABLE;
    }

    smuLock2Req->type = (U8) MMI_SETTING_TYPE_PHONELOCK;

    memset(smuLock2Req->passwd, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.Password);
    memcpy(smuLock2Req->passwd, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));
#endif

    gSecuritySetupContext.SMULockSuccessCallBack = SECSETSetPhoneLockSuccess;
    gSecuritySetupContext.SMULockFailCallBack = SETSETSetPhoneLockFail;
    SetProtocolEventHandler(SECSETSMULockRsp, PRT_MMI_SMU_LOCK_RSP);

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_LOCK_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) smuLockReq;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C_2;
    msgStruct.oslMsgId = PRT_MMI_SMU_LOCK_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) smuLock2Req;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetPhoneLockSuccess
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetPhoneLockSuccess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    gSecuritySetupContext.PhoneLockStatus = !gSecuritySetupContext.PhoneLockStatus;

    if (gSecuritySetupContext.PhoneLockStatus == 0)
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(1, hintData[index]);
        change_left_softkey(STR_GLOBAL_ON, 0);
        DisplayPopup((PU8) GetString(STR_SETTING_PHONE_UNLOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
        Category52ChangeItemDescription(1, hintData[index]);
        change_left_softkey(STR_GLOBAL_OFF, 0);
        DisplayPopup((PU8) GetString(STR_SETTING_PHONE_LOCK), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    }

    DeleteScreenIfPresent(SCR_ID_SECSET_PHONE_LOCK);
}


/*****************************************************************************
 * FUNCTION
 *  SETSETSetPhoneLockFail
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SETSETSetPhoneLockFail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    if (GetHistoryScrID(SCR_ID_SECSET_PHONE_LOCK, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SETSETSMURspFailure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SETSETSMURspFailure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_ID_SECSET_UNSPECIFIED_ERROR), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    if (GetHistoryScrID(SCR_ID_SECSET_PHONE_LOCK, &History) == ST_SUCCESS ||
        GetHistoryScrID(SCR_ID_SECSET_SIM_LOCK_PIN1, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, ENCODING_LENGTH);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSMULockRsp
 * DESCRIPTION
 *  A general fn to make Req for all type of Security options.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSMULockRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMULOCKRSP *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (SMULOCKRSP*) (info);

    if (!(resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UNSPECIFIED))
    {
        FillCountDownNumber(resp->chv_info);
    }

    if (resp->result == 1)
    {
        if (gSecuritySetupContext.SMULockSuccessCallBack != NULL)
        {
            (*gSecuritySetupContext.SMULockSuccessCallBack) ();
            gSecuritySetupContext.SMULockSuccessCallBack = NULL;
        }
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV1)
    {
        //DisplayPopup((PU8) GetString(STR_SETTING_PIN_BLK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        gSecuritySetupContext.PINBlocked = 1;
        g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;       /* 0x01: Invalid SIM */
    #ifdef __MMI_DUAL_SIM_MASTER__
        /* set the card1 status to work */
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_INVALID);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        //mmi_secset_delete_upto_puk1();
        mmi_secset_entry_scr_pin_blocked();
        gSecuritySetupContext.SMULockSuccessCallBack = NULL;
        gSecuritySetupContext.SMULockFailCallBack = NULL;
    }
    /* diamond, 2006/03/30 Handle the specific case of SMU busy for something */
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UNSPECIFIED)
    {
        SETSETSMURspFailure();
        gSecuritySetupContext.SMULockSuccessCallBack = NULL;
        gSecuritySetupContext.SMULockFailCallBack = NULL;
    }
    else
    {
        if (gSecuritySetupContext.SMULockFailCallBack != NULL)
        {
            (*gSecuritySetupContext.SMULockFailCallBack) ();
            gSecuritySetupContext.SMULockFailCallBack = NULL;
        }
    }
    mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) "");
}

#if defined(__MMI_DUAL_SIM_MASTER__)
static U8 enter_cp = 0;
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */

/*****************************************************************************
 * FUNCTION
 *  EntrySECSETChangePassword
 * DESCRIPTION
 *  Entry fn for change password option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETChangePassword(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

#if defined(__MMI_DUAL_SIM_MASTER__)
    /*
    U32 maskingByte = -1;
    U32 HideItemId = -1;
    */
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_CHANGE_PASSWORD, NULL, EntrySECSETChangePassword, NULL);

    mmi_frm_unhide_menu_item(MENU9174_CP_PIN1);
    mmi_frm_unhide_menu_item(MENU9175_CP_PIN2);
    mmi_frm_unhide_menu_item(MENU9173_CP_PHONE_LOCK);

    /* 2 Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_CHANGE_PASSWORD);

#if defined(__MMI_DUAL_SIM_MASTER__)
    if (GetParentHandler() == MENU9101_SECURITY)
    {
        /*
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9173_CP_PHONE_LOCK);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
        */
        mmi_frm_hide_menu_item(MENU9173_CP_PHONE_LOCK);
        enter_cp = 0;
    }
    else if (GetParentHandler() == MENU_MTPNP_DM_SECURITY_SETTING)
    {
        /*
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9174_CP_PIN1);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9175_CP_PIN2);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
        */
        mmi_frm_hide_menu_item(MENU9174_CP_PIN1);
        mmi_frm_hide_menu_item(MENU9175_CP_PIN2);
        enter_cp = 1;
    }
    else
    {
        if (enter_cp == 0)
        {
            /*
            HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9173_CP_PHONE_LOCK);
            if (HideItemId != -1)
            {
                ResetBit(maskingByte, HideItemId);
            }
            */
            mmi_frm_hide_menu_item(MENU9173_CP_PHONE_LOCK);
        }
        else if (enter_cp == 1)
        {
            /*
            HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9174_CP_PIN1);
            if (HideItemId != -1)
            {
                ResetBit(maskingByte, HideItemId);
            }
            HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9170_CHANGE_PASSWORD, MENU9175_CP_PIN2);
            if (HideItemId != -1)
            {
                ResetBit(maskingByte, HideItemId);
            }
            */
            mmi_frm_hide_menu_item(MENU9174_CP_PIN1);
            mmi_frm_hide_menu_item(MENU9175_CP_PIN2);
        }
    }
#else /* defined(__MMI_DUAL_SIM_MASTER__) */
    if (!mmi_bootup_is_sim_valid())
    {
        mmi_frm_hide_menu_item(MENU9174_CP_PIN1);
        mmi_frm_hide_menu_item(MENU9175_CP_PIN2);
    }
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */

    /* 3 Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU9170_CHANGE_PASSWORD);

    /* 4 Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU9170_CHANGE_PASSWORD, nStrItemList);

    /* 5 Set current parent id */
    SetParentHandler(MENU9170_CHANGE_PASSWORD);

    /* 6 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_DUAL_SIM_MASTER__)
    /*
    MaskHiliteItems(MENU9170_CHANGE_PASSWORD, maskingByte);
    nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
    */
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */

    /* 8 Display Category15 Screen */
    ShowCategory15Screen(
        STR_SCR9026_CHANGE_PASSWORD_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* 9 Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN1ForChangeReq
 * DESCRIPTION
 *  To get the status of Pin1/Pin2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN1ForChangeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetProtocolEventHandler(SECSETGetPIN1ForChangeRsp, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN2ForChangeReq
 * DESCRIPTION
 *  To get the status of Pin1/Pin2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN2ForChangeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetProtocolEventHandler(SECSETGetPIN2ForChangeRsp, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN1ForChangeRsp
 * DESCRIPTION
 *  Handles response of req to get the status of PIN1/PIN2.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN1ForChangeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMUSTATUSRSP *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (SMUSTATUSRSP*) (info);

    FillCountDownNumber(resp->chv_info);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    /* diamond, 2006/03/21 CHV1 enabled or not should be referred to mmi_smu_check_pin_status_rsp.chv_info.is_chv1_enabled */
    if (resp->chv_info.is_chv1_enabled)
    {
        EntrySECSETChangePWOldPWD();
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_ENABLE_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_ENABLE_CARD1_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetPIN2ForChangeRsp
 * DESCRIPTION
 *  Handles response of req to get the status of PIN1/PIN2.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetPIN2ForChangeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMUSTATUSRSP *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (SMUSTATUSRSP*) (info);

    FillCountDownNumber(resp->chv_info);

    switch (resp->chv_status.chv2_status)
    {
        case CHV_BLOCKED:
        #ifndef __MMI_DUAL_SIM_MASTER__
            DisplayPopup((PU8) GetString(STR_SETTING_PIN2_BLK2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #else
            DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_PIN2_BLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #endif
            mmi_secset_delete_upto_puk2();
            break;
        case CHV_DEAD:
        case CHV_INVALID_TYPE:
        case CHV_NOTINITED:
            DisplayPopup(
                (PU8) GetString(STR_ID_PIN2_NOT_SUPPORT),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
            break;
        default:
            EntrySECSETChangePWOldPWD();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETChangePWOldPWD
 * DESCRIPTION
 *  Entry screen to get old pwd of Phonelock/pin1/pin2 from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETChangePWOldPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_CHANGEPW_OLD_PWD, ExitSECSETChangePWOldPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    switch (gSecuritySetupContext.CurrentPassword)
    {
        case 0:
            FillCountDownString(MMI_SETTING_TYPE_CHV1, PassCountdownDisp);
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
            #ifndef __MMI_DUAL_SIM_MASTER__
                STR_SETTING_OLD_PIN,
            #else
                STRING_MTPNP_SETTING_OLD_CARD1_PIN,
            #endif
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.Password,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                PassCountdownDisp,
                guiBuffer);
            break;
        case 1:
            FillCountDownString(MMI_SETTING_TYPE_CHV2, PassCountdownDisp);
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
            #ifndef __MMI_DUAL_SIM_MASTER__
                STR_SETTING_OLD_PIN2,
            #else
                STRING_MTPNP_SETTING_OLD_CARD1_PIN2,
            #endif
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.Password,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                PassCountdownDisp,
                guiBuffer);
            break;
        case 2:
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_SCR9029_CURRENT_PW_CAPTION,
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.Password,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                NULL,
                guiBuffer);
            break;
    }

    SetLeftSoftkeyFunction(EntrySECSETChangePWNewPWD, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETChangePWNewPWD, KEY_POUND, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETChangePWNewPWD;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETChangePWOldPWD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETChangePWOldPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_CHANGEPW_OLD_PWD;
    Scr.entryFuncPtr = EntrySECSETChangePWOldPWD;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETChangePWNewPWD
 * DESCRIPTION
 *  Entry screen to enter new pwd for all options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETChangePWNewPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_CHANGEPW_NEW_PWD, ExitSECSETChangePWNewPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.NewPassword, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    switch (gSecuritySetupContext.CurrentPassword)
    {
        case 0:
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
            #ifndef __MMI_DUAL_SIM_MASTER__
                STR_SETTING_NEW_PIN,
            #else
                STRING_MTPNP_SETTING_NEW_CARD1_PIN,
            #endif
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.NewPassword,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                NULL,
                guiBuffer);
            break;
        case 1:
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
            #ifndef __MMI_DUAL_SIM_MASTER__
                STR_SETTING_NEW_PIN2,
            #else
                STRING_MTPNP_SETTING_NEW_CARD1_PIN2,
            #endif
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.NewPassword,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                NULL,
                guiBuffer);
            break;
        case 2:
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_SCR9030_NEW_PW_CAPTION,
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.NewPassword,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                NULL,
                guiBuffer);
            break;
    }

    SetLeftSoftkeyFunction(EntrySECSETChangePWCfmPWD, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETChangePWCfmPWD, KEY_POUND, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETChangePWCfmPWD;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETChangePWNewPWD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETChangePWNewPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_CHANGEPW_NEW_PWD;
    Scr.entryFuncPtr = EntrySECSETChangePWNewPWD;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.NewPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETChangePWCfmPWD
 * DESCRIPTION
 *  Entry screen to confirm new pwd for all options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETChangePWCfmPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_CHANGEPW_CFM_PWD, ExitSECSETChangePWCfmPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.ConfirmPassword, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SCR9031_CONFIRM_PW_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.ConfirmPassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    SetLeftSoftkeyFunction(SendReqToChangePwd, KEY_EVENT_UP);
    SetKeyHandler(SendReqToChangePwd, KEY_POUND, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = SendReqToChangePwd;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.ConfirmPassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETChangePWCfmPWD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETChangePWCfmPWD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_CHANGEPW_CFM_PWD;
    Scr.entryFuncPtr = EntrySECSETChangePWCfmPWD;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.ConfirmPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  SendReqToChangePwd
 * DESCRIPTION
 *  Make the req to L4 for change pwd of Phonelock,Pin1/Pin2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendReqToChangePwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    PASSWORDREQ *passWord;
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    PASSWORDREQ *passWord2 = NULL;
#endif
    historyNode *History;

    S8 pOutBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);

    if ((mmi_ucs2cmp((PS8) gSecuritySetupContext.NewPassword, (PS8) gSecuritySetupContext.ConfirmPassword) == 0))
    {
        passWord = OslConstructDataPtr(sizeof(PASSWORDREQ));
        mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.Password);
        memcpy(passWord->old, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);
        mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.NewPassword);
        memcpy(passWord->new1, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);
        mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.ConfirmPassword);
        memcpy(passWord->new2, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        switch (gSecuritySetupContext.CurrentPassword)
        {
            case 0:
                passWord->type = MMI_SETTING_TYPE_CHV1;
                SetProtocolEventHandler(SECSETChangePasswordPIN1Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                break;
            case 1:
                passWord->type = MMI_SETTING_TYPE_CHV2;
                SetProtocolEventHandler(SECSETChangePasswordPIN2Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                break;
            case 2:
                passWord->type = MMI_SETTING_TYPE_PHONELOCK;
                SetProtocolEventHandler(SECSETChangePasswordPhoneRsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);

            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                passWord2 = OslConstructDataPtr(sizeof(PASSWORDREQ));
                mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.Password);
                memcpy(passWord2->old, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

                memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);
                mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.NewPassword);
                memcpy(passWord2->new1, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

                memset(pOutBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) + 1);
                mmi_ucs2_to_asc(pOutBuffer, (PS8) gSecuritySetupContext.ConfirmPassword);
                memcpy(passWord2->new2, pOutBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

                passWord2->type = MMI_SETTING_TYPE_PHONELOCK;
            #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
                break;
            default:
                break;
        }

        ClearInputEventHandler(MMI_DEVICE_ALL);
        msgStruct.oslSrcId = MOD_MMI;
        msgStruct.oslDestId = MOD_L4C;
        msgStruct.oslMsgId = PRT_MMI_SMU_CHANGE_PASSWORD_REQ;
        msgStruct.oslSapId = INVALID_SAP;
        msgStruct.oslDataPtr = (oslParaType*) passWord;
        msgStruct.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&msgStruct);

    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        if (gSecuritySetupContext.CurrentPassword == 2)
        {
            msgStruct.oslSrcId = MOD_MMI;
            msgStruct.oslDestId = MOD_L4C_2;
            msgStruct.oslMsgId = PRT_MMI_SMU_CHANGE_PASSWORD_REQ;
            msgStruct.oslSapId = INVALID_SAP;
            msgStruct.oslDataPtr = (oslParaType*) passWord2;
            msgStruct.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&msgStruct);
        }
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    }
    else
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);

        switch (gSecuritySetupContext.CurrentPassword)
        {
            case 0:
                DisplayPopup(
                #ifndef __MMI_DUAL_SIM_MASTER__
                    (PU8) GetString(STR_DIFF_PIN),
                #else
                    (PU8) GetString(STRING_MTPNP_CARD1_PIN_DONOT_MATCH),
                #endif
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
                if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_NEW_PWD, &History) == ST_SUCCESS)
                {
                    if (History->inputBuffer != NULL)
                    {
                        memset(History->inputBuffer, 0, ENCODING_LENGTH);
                    }
                    if (History->guiBuffer != NULL)
                    {
                        memset(History->guiBuffer, 0, 2);
                    }
                }
                break;
            case 1:
            #ifndef __MMI_DUAL_SIM_MASTER__
                DisplayPopup((PU8) GetString(STR_DIFF_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #else
                DisplayPopup((PU8) GetString(STRING_MTPNP_CARD1_PIN2_DONOT_MATCH), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #endif
                DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
                if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_NEW_PWD, &History) == ST_SUCCESS)
                {
                    if (History->inputBuffer != NULL)
                    {
                        memset(History->inputBuffer, 0, ENCODING_LENGTH);
                    }
                    if (History->guiBuffer != NULL)
                    {
                        memset(History->guiBuffer, 0, 2);
                    }
                }
                break;
            case 2:
                DisplayPopup((PU8) GetString(STR_DIFF_PHONE), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
                if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_NEW_PWD, &History) == ST_SUCCESS)
                {
                    if (History->inputBuffer != NULL)
                    {
                        memset(History->inputBuffer, 0, ENCODING_LENGTH);
                    }
                    if (History->guiBuffer != NULL)
                    {
                        memset(History->guiBuffer, 0, 2);
                    }
                }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETChangePasswordPhoneRsp
 * DESCRIPTION
 *  Response handler of change phonelock password req.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETChangePasswordPhoneRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RESULTSTRUCT *resp;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (RESULTSTRUCT*) (info);

    memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);

    if (resp->result == 1)
    {
        DisplayPopup((PU8) GetString(STR_PHONE_CHANGE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
        DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
        if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_OLD_PWD, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETChangePasswordPIN1Rsp
 * DESCRIPTION
 *  Response handler of change PIN1 password req.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETChangePasswordPIN1Rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_change_password_rsp_struct *resp;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_change_password_rsp_struct*) (info);

    FillCountDownNumber(resp->chv_info);

    memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);

    if (resp->result == 1)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_PIN_CHANGE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_CARD1_PIN_CHANGE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #endif
        if (IsScreenPresent(SCR_ID_SECSET_CHANGE_PASSWORD))
        {
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
        }
        else
        {
            mmi_secset_delete_upto_idle_screen();
        }
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV1)
    {
        //DisplayPopup((PU8) GetString(STR_SETTING_PIN_BLK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        gSecuritySetupContext.PINBlocked = 1;
        g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;       /* 0x01: Invalid SIM */
    #ifdef __MMI_DUAL_SIM_MASTER__
        /* set the card1 status to work */
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_INVALID);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        //mmi_secset_delete_upto_puk1();
        mmi_secset_entry_scr_pin_blocked();
        mmi_ssc_delete_sim_operation_screens();
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_WRONG_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_WRONG_CARD1_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
        if (IsScreenPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD))
        {
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
            if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_OLD_PWD, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
        }
        else
        {
            mmi_secset_delete_upto_idle_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETChangePasswordPIN2Rsp
 * DESCRIPTION
 *  Response handler of change Pin2 password req.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETChangePasswordPIN2Rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_change_password_rsp_struct *resp;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_change_password_rsp_struct*) (info);

    FillCountDownNumber(resp->chv_info);

    memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);

    if (resp->result == 1)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_PIN2_CHANGE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_CARD1_PIN2_CHANGE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    #endif
        if (IsScreenPresent(SCR_ID_SECSET_CHANGE_PASSWORD))
        {
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
        }
        else
        {
            mmi_secset_delete_upto_idle_screen();
        }
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV2)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_SETTING_PIN2_BLK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_PIN2_BLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
        mmi_secset_delete_upto_puk2();
        mmi_ssc_delete_sim_operation_screens();
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV2_BLOCKED)
    {
        DisplayPopup((PU8) GetString(STR_ID_PIN2_NOT_SUPPORT), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_WRONG_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_WRONG_CARD1_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
        if (IsScreenPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD))
        {
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
            DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
            if (GetHistoryScrID(SCR_ID_SECSET_CHANGEPW_OLD_PWD, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
        }
        else
        {
            mmi_secset_delete_upto_idle_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetPhoneLock
 * DESCRIPTION
 *  Get the status of phonelock from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
U8 GetPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.PhoneLockStatus = smu_query_phone_lock_enabled();
    if (gSecuritySetupContext.PhoneLockStatus == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetAutoKeypadLockTime
 * DESCRIPTION
 *  API to return the Autokeypadlock time.
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
SETTING_AKPL_TIME GetAutoKeypadLockTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &data, DS_BYTE, &error);
    if (data == 0xff)
    {
        data = 0;
        WriteValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &data, DS_BYTE, &error);
    }

    return (SETTING_AKPL_TIME) (data);
}


/*****************************************************************************
 * FUNCTION
 *  DialSoSPUK1
 * DESCRIPTION
 *  Function takes care that from which buffer DialPadBuffer should be filled up.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialSoSPUK1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gSecuritySetupContext.NewPassword);
    EntryScrEmergencyCallDialing();
}


/*****************************************************************************
 * FUNCTION
 *  DialSoSNewPIN1
 * DESCRIPTION
 *  Function takes care that from which buffer DialPadBuffer should be filled up.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialSoSNewPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gSecuritySetupContext.Password);
    EntryScrEmergencyCallDialing();
}


/*****************************************************************************
 * FUNCTION
 *  DialSoSNewPIN1Conf
 * DESCRIPTION
 *  Function takes care that from which buffer DialPadBuffer should be filled up.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialSoSNewPIN1Conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) gSecuritySetupContext.ConfirmPassword);
    EntryScrEmergencyCallDialing();
}

/*****************************************************************************
 * FUNCTION
 *  SECSETPUK1DeleteHandler
 * DESCRIPTION
 *  Call back function when the screen is deleted
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 SECSETPUK1DeleteHandler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.PINBlocked == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUK1
 * DESCRIPTION
 *  Entry fn for PUK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUK1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK1, ExitSECSETPUK1, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK1);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK1);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.NewPassword, (S8*) inputBuffer);
    }

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;
    g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;   /* 0x01: Invalid SIM */
#ifdef __MMI_DUAL_SIM_MASTER__
    /* set the card1 status to work */
    MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_INVALID);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    gSecuritySetupContext.PINBlocked = 1;

    RegisterInputBoxValidationFunction(ScrSettingPukValidation);
    FillCountDownString(MMI_SETTING_TYPE_UBCHV1, PassCountdownDisp);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (!mmi_is_redrawing_bk_screens())
#endif
    {
        sprintf(g_idle_context.DialPadCallBuffer, ""); /* reset dial pad for input * to start ssc */
    }

    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_SETTING_SOS,
        0,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SETTING_PUK,
    #else
        STRING_MTPNP_ENTER_CARD1PUK,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.NewPassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        PassCountdownDisp,
        guiBuffer);

    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
        SetKeyHandler(DialSoSPUK1, KEY_SEND, KEY_EVENT_UP);
    }

    /* If this screen is deleted, call back function. */
    //SetDelScrnIDCallbackHandler(SCR_ID_SECSET_PUK1, (HistoryDelCBPtr) SECSETPUK1DeleteHandler);

    SetKeyHandler(SSCHandleEnterPUKFromSecset1, KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(EntrySECSETPUKNewPIN1, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETPUKNewPIN1, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETPUKNewPIN1;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETPUK1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETPUK1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK1;
    Scr.entryFuncPtr = EntrySECSETPUK1;
    if (g_pwr_context.SOSCallFlagTOAvoidHistorySave == 1)
    {
        memset(Scr.inputBuffer, 0, ENCODING_LENGTH);
        memset(Scr.guiBuffer, 0, ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.NewPassword);
        GetCategoryHistory(Scr.guiBuffer);
    }
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUKNewPIN1
 * DESCRIPTION
 *  Entry fn to enter new PIN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUKNewPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK_NEW_PIN1, ExitSECSETNewPIN1, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK_NEW_PIN1);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK_NEW_PIN1);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_NEW_PIN1,
    #else
        STRING_MTPNP_ENTER_CARD1_NEW_PIN,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.Password,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntrySECSETPUKConfirmPIN1, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETPUKConfirmPIN1, KEY_POUND, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        SetKeyHandler(DialSoSNewPIN1, KEY_SEND, KEY_EVENT_UP);
    }

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETPUKConfirmPIN1;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETNewPIN1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETNewPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK_NEW_PIN1;
    Scr.entryFuncPtr = EntrySECSETPUKNewPIN1;
    if (g_pwr_context.SOSCallFlagTOAvoidHistorySave == 1)
    {
        memset(Scr.inputBuffer, 0, ENCODING_LENGTH);
        memset(Scr.guiBuffer, 0, ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
        GetCategoryHistory(Scr.guiBuffer);
    }
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUKConfirmPIN1
 * DESCRIPTION
 *  ENtry fn for confirm PIN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUKConfirmPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK_CONFIRM_PIN1, ExitSECSETNewPIN1Confirm, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.ConfirmPassword, (S8*) inputBuffer);
    }

    g_pwr_context.SOSCallFlagTOAvoidHistorySave = 0;
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SCR9031_CONFIRM_PW_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.ConfirmPassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(ValidateNewPin1, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ValidateNewPin1, KEY_EVENT_UP);
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        SetKeyHandler(DialSoSNewPIN1Conf, KEY_SEND, KEY_EVENT_UP);
    }

    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateNewPin1;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.ConfirmPassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETNewPIN1Confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETNewPIN1Confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK_CONFIRM_PIN1;
    Scr.entryFuncPtr = EntrySECSETPUKConfirmPIN1;
    if (g_pwr_context.SOSCallFlagTOAvoidHistorySave == 1)
    {
        memset(Scr.inputBuffer, 0, ENCODING_LENGTH);
        memset(Scr.guiBuffer, 0, ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.ConfirmPassword);
        GetCategoryHistory(Scr.guiBuffer);
    }
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  ValidateNewPin1
 * DESCRIPTION
 *  validates the length of Both new pin and confirm pin and also
 *  Check if both Pin matches.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNewPin1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;
    S32 first_len, second_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_len = mmi_ucs2strlen((S8*) gSecuritySetupContext.Password);
    second_len = mmi_ucs2strlen((S8*) gSecuritySetupContext.ConfirmPassword);

    if (first_len == second_len && memcmp
        (gSecuritySetupContext.Password, gSecuritySetupContext.ConfirmPassword,
         first_len * ENCODING_LENGTH) == 0)
    {
        SECSETVerifyPINReq(
            MMI_SETTING_TYPE_UBCHV1,
            gSecuritySetupContext.NewPassword,
            gSecuritySetupContext.Password,
            ValidateNewPin1Success);
    }
    else
    {
        DisplayPopup(
        #ifndef __MMI_DUAL_SIM_MASTER__
            (PU8) GetString(STR_DIFF_PIN),
        #else
            (PU8) GetString(STRING_MTPNP_CARD1_PIN_DONOT_MATCH),
        #endif
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
        if (GetHistoryScrID(SCR_ID_SECSET_PUK_NEW_PIN1, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ValidateNewPin1Success
 * DESCRIPTION
 *  validates the length of Both new pin and confirm pin and also
 *  Check if both Pin matches.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNewPin1Success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SECSETGetPIN1StatusReq();
    DisplayPopup((PU8) GetString(STR_SETTING_CODE_VERIFIED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    mmi_secset_delete_puk1_and_puk2();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUK2
 * DESCRIPTION
 *  Entry fn for PUK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUK2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK2, ExitSECSETPUK2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK2);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK2);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.NewPassword, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(ScrSettingPukValidation);
    FillCountDownString(MMI_SETTING_TYPE_UBCHV2, PassCountdownDisp);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (!mmi_is_redrawing_bk_screens())
#endif
    {
        sprintf(g_idle_context.DialPadCallBuffer, ""); /* reset dial pad for input * to start ssc */
    }

    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SETTING_ENTER_PUK2,
    #else
        STRING_MTPNP_SETTING_SIM1_PUK2,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.NewPassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        PassCountdownDisp,
        guiBuffer);

    SetKeyHandler(SSCHandleEnterPUKFromSecset1, KEY_STAR, KEY_EVENT_DOWN);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntrySECSETPUK2NewPIN2, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETPUK2NewPIN2, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETPUK2NewPIN2;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETPUK2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETPUK2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK2;
    Scr.entryFuncPtr = EntrySECSETPUK2;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.NewPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUK2NewPIN2
 * DESCRIPTION
 *  Entry fn to enter new PIN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUK2NewPIN2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK2_NEW_PIN2, ExitSECSETNewPIN2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK2_NEW_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK2_NEW_PIN2);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SETTING_ENTER_NEW_PIN2,
    #else
        STRING_MTPNP_SETTING_SIM1_NEW_PIN2,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.Password,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntrySECSETPUK2ConfirmPIN2, KEY_EVENT_UP);
    SetKeyHandler(EntrySECSETPUK2ConfirmPIN2, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = EntrySECSETPUK2ConfirmPIN2;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETNewPIN2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETNewPIN2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK2_NEW_PIN2;
    Scr.entryFuncPtr = EntrySECSETPUK2NewPIN2;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETPUK2ConfirmPIN2
 * DESCRIPTION
 *  ENtry fn for confirm PIN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETPUK2ConfirmPIN2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_PUK2_CONFIRM_PIN2, ExitSECSETNewPIN2Confirm, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.ConfirmPassword, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,  /* OK */
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SCR9031_CONFIRM_PW_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.ConfirmPassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(ValidateNewPin2, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ValidateNewPin2, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = ValidateNewPin2;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.ConfirmPassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETNewPIN2Confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETNewPIN2Confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_PUK2_CONFIRM_PIN2;
    Scr.entryFuncPtr = EntrySECSETPUK2ConfirmPIN2;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.ConfirmPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  ValidateNewPin2
 * DESCRIPTION
 *  validates the length of Both new pin and confirm pin and also
 *  Check if both Pin matches.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateNewPin2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp
        (gSecuritySetupContext.Password, gSecuritySetupContext.ConfirmPassword,
         ((MAX_SIM_SETTING_PASSWD_LEN + 1) - 1) * ENCODING_LENGTH) == 0)
    {
        gSecuritySetupContext.VerifyPassSuccessCallBack = NULL;
        SECSETVerifyPINReq(
            MMI_SETTING_TYPE_UBCHV2,
            gSecuritySetupContext.NewPassword,
            gSecuritySetupContext.Password,
            NULL);
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STR_DIFF_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #else
        DisplayPopup((PU8) GetString(STRING_MTPNP_CARD1_PIN2_DONOT_MATCH), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    #endif
        DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
        if (GetHistoryScrID(SCR_ID_SECSET_PUK2_NEW_PIN2, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETVerifyPINReq
 * DESCRIPTION
 *  Send PUK to L4 for verification.
 * PARAMETERS
 *  pin_type                [IN]        
 *  ucs2_pin                [?]         
 *  ucs2_new_pin            [?]         
 *  success_callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETVerifyPINReq(U8 pin_type, U8 *ucs2_pin, U8 *ucs2_new_pin, FuncPtr success_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1)];

    MYQUEUE Message;
    MMIPHONEVERIFYREQ *local_data;
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    MMIPHONEVERIFYREQ *local_data_2;
#endif
    U32 l4c_flag = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);   /* So that user can't go to idle screen. */
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

#if 0
/* under construction !*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (pin_type == MMI_SETTING_TYPE_PHONELOCK)
    {
        if (!mmi_bootup_is_sim2_removed() && !mmi_bootup_is_sim2_valid())
        {
            l4c_flag = MOD_L4C;
        }
        else if (!mmi_bootup_is_sim_removed() && !mmi_bootup_is_sim_valid())
        {
            l4c_flag = MOD_L4C_2;
        }
        else
        {
            l4c_flag = MOD_L4C + MOD_L4C_2;
        }
    }
#endif

    if (l4c_flag == MOD_L4C
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        || l4c_flag == MOD_L4C + MOD_L4C_2
#endif
        )
    {
        local_data = (MMIPHONEVERIFYREQ*) OslConstructDataPtr(sizeof(MMIPHONEVERIFYREQ));

        memset(local_data->pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memset(local_data->new_pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));

        local_data->pin_type = pin_type;    /* _smu_security_type_enum */

        memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        mmi_ucs2_n_to_asc((S8*) tempBuffer, (S8*) ucs2_pin, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memcpy(local_data->pin, tempBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        mmi_ucs2_n_to_asc((S8*) tempBuffer, (S8*) ucs2_new_pin, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memcpy(local_data->new_pin, tempBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        if (success_callback != NULL)
        {
            gSecuritySetupContext.VerifyPassSuccessCallBack = success_callback;
        }
        SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        ClearSlaveProtocolEventHandler(PRT_MMI_SMU_VERIFY_PIN_RSP);
#endif
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
        Message.oslDataPtr = (oslParaType*) local_data;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (l4c_flag == MOD_L4C_2/* || l4c_flag == MOD_L4C + MOD_L4C_2*/)
    {
        local_data_2 = (MMIPHONEVERIFYREQ*) OslConstructDataPtr(sizeof(MMIPHONEVERIFYREQ));

        memset(local_data_2->pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memset(local_data_2->new_pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));

        local_data_2->pin_type = pin_type;    /* _smu_security_type_enum */

        memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        mmi_ucs2_n_to_asc((S8*) tempBuffer, (S8*) ucs2_pin, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memcpy(local_data_2->pin, tempBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        mmi_ucs2_n_to_asc((S8*) tempBuffer, (S8*) ucs2_new_pin, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        memcpy(local_data_2->new_pin, tempBuffer, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        //if (l4c_flag == MOD_L4C_2)
        //{
            if (success_callback != NULL)
            {
                gSecuritySetupContext.VerifyPassSuccessCallBack = success_callback;
            }
            SetSlaveProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
        //}
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C_2;
        Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
        Message.oslDataPtr = (oslParaType*) local_data_2;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SECSETVerifyPINRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETVerifyPINRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_verify_pin_rsp_struct *local_data = (mmi_smu_verify_pin_rsp_struct*) info;
    historyNode *History;

    extern S8 ssc_dialpad_buffer[];
#ifndef __MMI_DUAL_SIM_MASTER__
    extern U16 simErrorDisplayString;
#endif
#ifdef __MMI_SML_NP_ONLY__
    extern U8 gCPHSRetryCount;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FillCountDownNumber(local_data->chv_info);

    gSecuritySetupContext.PINBlocked = 0;

    /* Not reset invalid sim flag because verify pin request may be used in no sim case or SAP mode */
#ifdef __MMI_SIMAP_SUPPORT__
    if ((!mmi_bootup_is_sim_removed() && !mmi_bootup_get_active_bt_access_profile_mode() && mmi_bootup_is_sim_valid())
        || IsScreenPresent(SCR_ID_SECSET_PUK1))
#else
    if ((!mmi_bootup_is_sim_removed() && mmi_bootup_is_sim_valid())
        || IsScreenPresent(SCR_ID_SECSET_PUK1))
#endif
    {
        g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;      /* 0x01: Invalid SIM reset */
    #ifdef __MMI_DUAL_SIM_MASTER__
        /* set the card1 status to work */
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_VALID);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }

    switch (local_data->next_type)
    {
        case MMI_SETTING_TYPE_NO_REQUIRED:
            if (gSecuritySetupContext.VerifyPassSuccessCallBack != NULL)
            {
                (*gSecuritySetupContext.VerifyPassSuccessCallBack) ();
                gSecuritySetupContext.VerifyPassSuccessCallBack = NULL;
            }
            else
            {
                //PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SecuritySetup.c] SECSETVerifyPINRsp ABNORMAL");
                DisplayPopup((PU8) GetString(STR_SETTING_CODE_VERIFIED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
                mmi_secset_delete_puk1_and_puk2();
            }
            break;
        case MMI_SETTING_TYPE_PHONELOCK:
            DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            if (GetHistoryScrID(SCR_RESTORE, &History) == ST_SUCCESS ||
                GetHistoryScrID(SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
            memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
            break;
        case MMI_SETTING_TYPE_CHV1:
        #ifndef __MMI_DUAL_SIM_MASTER__
            DisplayPopup((PU8) GetString(STR_WRONG_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #else
            DisplayPopup((PU8) GetString(STRING_MTPNP_WRONG_CARD1_PIN), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #endif
            break;
        case MMI_SETTING_TYPE_CHV2:
        #ifndef __MMI_DUAL_SIM_MASTER__
            DisplayPopup((PU8) GetString(STR_WRONG_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #else
            DisplayPopup((PU8) GetString(STRING_MTPNP_WRONG_CARD1_PIN2), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #endif
            if (GetHistoryScrID(SCR_ID_SECSET_PIN2, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
            break;
        case MMI_SETTING_TYPE_UBCHV1:
        #ifndef __MMI_DUAL_SIM_MASTER__
            DisplayPopup((PU8) GetString(STR_SETTING_WRONG_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #else
            DisplayPopup((PU8) GetString(STRING_MTPNP_INCORRECT_CARD1_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        #endif
            /* input wrong PUK from idle screen doesn't need to enter PUK */
            if (!mmi_ssc_is_sim_operation((U8*) ssc_dialpad_buffer, MMI_UCS2_DCS))
            {
                mmi_secset_delete_upto_puk1();
            }
            RemoveSSReqScr();
            break;
        case MMI_SETTING_TYPE_UBCHV2:
            if (GetExitScrnID() == SCR_ID_SECSET_PIN2)
            {
                ClearExitHandler();
                ExitSECSETPUK2();
            #ifndef __MMI_DUAL_SIM_MASTER__
                DisplayPopup((PU8) GetString(STR_SETTING_PIN2_BLK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #else
                DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_PIN2_BLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #endif
            }
            else
            {
                DisplayPopup(
                #ifndef __MMI_DUAL_SIM_MASTER__
                    (PU8) GetString(STR_SETTING_WRONG_PUK2),
                #else
                    (PU8) GetString(STRING_MTPNP_INCORRECT_CARD1_PUK2),
                #endif
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
                /* input wrong PUK from idle screen doesn't need to enter PUK */
                if (!mmi_ssc_is_sim_operation((U8*) ssc_dialpad_buffer, MMI_UCS2_DCS))
                {
                    mmi_secset_delete_upto_puk2();
                }
                RemoveSSReqScr();
            }

            if (GetHistoryScrID(SCR_ID_SECSET_PUK2, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
            break;
        case MMI_SETTING_TYPE_CHV1_BLOCKED:
            break;
        case MMI_SETTING_TYPE_CHV2_BLOCKED:
            DisplayPopup(
                (PU8) GetString(STR_SETTING_PIN2_BLOCK_MSG),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
            DeleteNScrId(SCR_ID_SECSET_MAIN);
            break;
        case MMI_SETTING_TYPE_SIM_CARD_BLOCKED:
            if (IsScreenPresent(SCR_ID_SECSET_PUK1) ||
                !(GetActiveScreenId() == SCR_RESTORE || GetActiveScreenId() == SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK))
            {
                gSecuritySetupContext.PINBlocked = 0;
                g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
            #ifdef __MMI_DUAL_SIM_MASTER__
                /* set the card1 status to work */
                MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHVBLOCKED);
                /* rearrange the menu item */
                MTPNP_PFAL_Rearrange_MenuItem();
                /* rearrange the status bar on idle screen */
                MTPNP_PFAL_Rearrange_StatusBar();
                mmi_sim_error_hide_menu_items();
                DisplayPopupCallBack(
                    (PU8) GetString(STRING_MTPNP_CARD1_SIM_BLOCK),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE,
                    mmi_idle_entry_dual_sim_root_screen);
            #else /* __MMI_DUAL_SIM_MASTER__ */
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                DisplayPopupCallBack(
                    (PU8) GetString(STR_SIM_BLOCK_MSG),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE,
                    EntryScrnSimBlockRsp);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
            else
            {
                if (local_data->result == 1)
                {
                    if (gSecuritySetupContext.VerifyPassSuccessCallBack != NULL)
                    {
                        (*gSecuritySetupContext.VerifyPassSuccessCallBack) ();
                        gSecuritySetupContext.VerifyPassSuccessCallBack = NULL;
                    }
                }
                else
                {
                    DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
                    if (GetHistoryScrID(SCR_RESTORE, &History) == ST_SUCCESS ||
                        GetHistoryScrID(SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK, &History) == ST_SUCCESS)
                    {
                        if (History->inputBuffer != NULL)
                        {
                            memset(History->inputBuffer, 0, ENCODING_LENGTH);
                        }
                        if (History->guiBuffer != NULL)
                        {
                            memset(History->guiBuffer, 0, 2);
                        }
                    }
                    memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
                }
            }
            break;
        case MMI_SETTING_TYPE_UBCHV2_BLOCKED:
            DisplayPopup(
                (PU8) GetString(STR_ID_PIN2_NOT_SUPPORT),
                IMG_GLOBAL_ERROR,
                0,
                ST_NOTIFYDURATION,
                ERROR_TONE);
            DeleteNScrId(SCR_ID_SECSET_PUK2);
            break;
        case MMI_SETTING_TYPE_UBCHV1_CHV1_NOT_LOCK:
            break;
        case MMI_SETTING_TYPE_UNSPECIFIED:
            DisplayPopup((PU8) GetString(STR_ID_SECSET_UNSPECIFIED_ERROR), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
            break;
    #ifdef __MMI_SML_NP_ONLY__
        case MMI_SETTING_TYPE_NP:
            DisplayPopup((U8*) GetString(STR_WRONG_NP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
            memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
            gCPHSRetryCount--;
            if (gCPHSRetryCount == 0)
            {
                DeleteScreenIfPresent(SCR_ENTER_NP);
            }
            break;
    #endif /* __MMI_SML_NP_ONLY__ */
        default:
            break;
    }

    mmi_ssc_delete_sim_operation_screens();
    memset(ssc_dialpad_buffer, 0, 2);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETSIMLockPIN1
 * DESCRIPTION
 *  Entry fn to get SIM lock pwd from user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETSIMLockPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_SIM_LOCK_PIN1, ExitSECSETSIMLockPIN1, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_SIM_LOCK_PIN1);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SECSET_SIM_LOCK_PIN1);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.Password, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.Password, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);
    FillCountDownString(MMI_SETTING_TYPE_CHV1, PassCountdownDisp);
    /* START VIJAY PMT 20060103 */
#if defined UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 
    /* END VIJAY PMT 20060103 */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
    #ifndef __MMI_DUAL_SIM_MASTER__
        STR_SCR9028_PIN1_CAPTION,
    #else
        STRING_MTPNP_ENTER_CARD1PIN,
    #endif
        INPUT_TYPE_NUMERIC_PASSWORD,
        gSecuritySetupContext.Password,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        PassCountdownDisp,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SECSETSetSIMLockReq, KEY_EVENT_UP);
    SetKeyHandler(SECSETSetSIMLockReq, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = SECSETSetSIMLockReq;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETSIMLockPIN1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETSIMLockPIN1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SECSET_SIM_LOCK_PIN1;
    Scr.entryFuncPtr = EntrySECSETSIMLockPIN1;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.Password);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetFdlModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetFdlModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    MMISMUDIALMODEREQSTRUCT *dailStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dailStruct = OslConstructDataPtr(sizeof(MMISMUDIALMODEREQSTRUCT));

    if (gSecuritySetupContext.FdlStatus)
    {
        dailStruct->on_off = (U8) MMI_OFF_OPTION;
    }
    else
    {
        dailStruct->on_off = (U8) MMI_ON_OPTION;
    }

    dailStruct->type = MMI_TYPE_FDN;
    memset(dailStruct->pin, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    SetProtocolEventHandler(SECSETSetFdlModeRsp, PRT_MMI_SMU_SET_DIAL_MODE_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_SET_DIAL_MODE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) dailStruct;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetFdlModeRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetFdlModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_dial_mode_rsp_struct *resp;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    resp = (mmi_smu_set_dial_mode_rsp_struct*) (info);

    if (resp->result == 1)
    {
        gSecuritySetupContext.FdlStatus = !gSecuritySetupContext.FdlStatus;
        g_phb_cntx.phb_ready = FALSE;
        if (gSecuritySetupContext.FdlStatus)
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_OFF, 0);
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
        else
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_ON, 0);
            DisplayPopup((PU8) GetString(STR_FDL_IS_OFF), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetBdlModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetBdlModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    MMISMUDIALMODEREQSTRUCT *dailStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dailStruct = OslConstructDataPtr(sizeof(MMISMUDIALMODEREQSTRUCT));

    if (gSecuritySetupContext.BdlStatus)
    {
        dailStruct->on_off = (U8) MMI_OFF_OPTION;
    }
    else
    {
        dailStruct->on_off = (U8) MMI_ON_OPTION;
    }

    dailStruct->type = MMI_TYPE_BDN;
    memset(dailStruct->pin, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    SetProtocolEventHandler(SECSETSetBdlModeRsp, PRT_MMI_SMU_SET_DIAL_MODE_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_SET_DIAL_MODE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) dailStruct;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetBdlModeRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetBdlModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_dial_mode_rsp_struct *resp;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    resp = (mmi_smu_set_dial_mode_rsp_struct*) (info);

    if (resp->result == 1)
    {
        gSecuritySetupContext.BdlStatus = !gSecuritySetupContext.BdlStatus;
        g_phb_cntx.phb_ready = FALSE;
        if (gSecuritySetupContext.BdlStatus)
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_OFF, 0);
            DisplayPopup((PU8) GetString(STR_BDL_IS_ON), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
        else
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_ON, 0);
            DisplayPopup((PU8) GetString(STR_BDL_IS_OFF), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
}


/*****************************************************************************
 * FUNCTION
 *  ScrSettingPukValidation
 * DESCRIPTION
 *  Fn for length validation at PUk screen
 * PARAMETERS
 *  text        [?]         
 *  cursor      [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ScrSettingPukValidation(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(gSecuritySetupContext.PasswdLenCheckCallBack, KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlBdlModeReq
 * DESCRIPTION
 *  Send req to L4 to know the status of FDL mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlBdlModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(SECSETGetFdlBdlModeRsp, PRT_MMI_SMU_GET_DIAL_MODE_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_GET_DIAL_MODE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlBdlModeRsp
 * DESCRIPTION
 *  Response handler for req to know the status of FDL mode.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlBdlModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DIALMODESTATUSRSPSTRUCT *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (DIALMODESTATUSRSPSTRUCT*) (info);

    switch (resp->dial_mode)
    {
        case MMI_TYPE_ADN:
            gSecuritySetupContext.BdlStatus = 0;
            gSecuritySetupContext.FdlStatus = 0;
            break;
        case MMI_TYPE_FDN:
            gSecuritySetupContext.FdlStatus = 1;
            gSecuritySetupContext.BdlStatus = 0;
            break;
        case MMI_TYPE_BDN:
            gSecuritySetupContext.FdlStatus = 0;
            gSecuritySetupContext.BdlStatus = 1;
            break;
        case MMI_TYPE_FDN_BDN:
            gSecuritySetupContext.BdlStatus = 1;
            gSecuritySetupContext.FdlStatus = 1;
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  FillCountDownNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  chv_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FillCountDownNumber(sim_chv_info_struct chv_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.CHV1Count = chv_info.chv1_count;
    gSecuritySetupContext.CHV2Count = chv_info.chv2_count;
    gSecuritySetupContext.UBCHV1Count = chv_info.ubchv1_count;
    gSecuritySetupContext.UBCHV2Count = chv_info.ubchv2_count;
}


/*****************************************************************************
 * FUNCTION
 *  FillCountDownString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  TypeOfPass              [IN]        
 *  PassCountdownDisp       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void FillCountDownString(U8 TypeOfPass, U8 *PassCountdownDisp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp1[10];
    S8 temp2[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (TypeOfPass)
    {
        case MMI_SETTING_TYPE_CHV1:
            sprintf(temp1, "%d", gSecuritySetupContext.CHV1Count);
            break;
        case MMI_SETTING_TYPE_CHV2:
            sprintf(temp1, "%d", gSecuritySetupContext.CHV2Count);
            break;
        case MMI_SETTING_TYPE_UBCHV1:
            sprintf(temp1, "%d", gSecuritySetupContext.UBCHV1Count);
            break;
        case MMI_SETTING_TYPE_UBCHV2:
            sprintf(temp1, "%d", gSecuritySetupContext.UBCHV2Count);
            break;
    }

    mmi_asc_to_ucs2(temp2, temp1);
    mmi_ucs2cpy((S8*) PassCountdownDisp, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) PassCountdownDisp, (S8*) temp2);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlStatusReq
 * DESCRIPTION
 *  Send req to L4 to know the status of FDL or BDL.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlStatusReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_smu_read_file_info_req_struct *fdlstatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    fdlstatus = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    fdlstatus->file_idx = FILE_FDN_IDX;
    SetProtocolEventHandler(SECSETGetFdlStatusRsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) fdlstatus;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlStatusRsp
 * DESCRIPTION
 *  Response for the request to get the status of FDL or BDL.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlStatusRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_read_file_info_rsp_struct*) (info);

    if (resp->result.flag == 0  /* ok */
    #ifdef __GEMINI__
        && (sim_service_table_query(SERVICE_FDN, 0) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_FDN, 0) == SERVICE_ALLOCATE)
    #else
        && (sim_service_table_query(SERVICE_FDN) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_FDN) == SERVICE_ALLOCATE)
    #endif
        )                       /* diamond, 2006/01/26 Need to check both FDN file and SIM service table */
    {
        gFDLBDLContext.MaxFDL = resp->num_of_rec;
        EntrySECSETFixDial();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_NO_FDL), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetBdlStatusReq
 * DESCRIPTION
 *  Send req to L4 to know the status of FDL or BDL.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetBdlStatusReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_smu_read_file_info_req_struct *fdlstatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    fdlstatus = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    fdlstatus->file_idx = FILE_BDN_IDX;
    SetProtocolEventHandler(SECSETGetBdlStatusRsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) fdlstatus;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetBdlStatusRsp
 * DESCRIPTION
 *  Response for the request to get the status of FDL or BDL.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetBdlStatusRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_read_file_info_rsp_struct*) (info);

    if (resp->result.flag == 0  /* ok */
    #ifdef __GEMINI__
        && (sim_service_table_query(SERVICE_BDN, 0) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_BDN, 0) == SERVICE_ALLOCATE)
    #else
        && (sim_service_table_query(SERVICE_BDN) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_BDN) == SERVICE_ALLOCATE)
    #endif
        )                       /* diamond, 2006/01/26 Need to check both BDN file and SIM service table */
    {
        gFDLBDLContext.MaxBDL = resp->num_of_rec;
        EntrySECSETBarDial();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_NO_FDL), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_fixed_dial_mode
 * DESCRIPTION
 *  Entry function of set FDN mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_set_fixed_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_set_toggle = 1;
    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETSetFdlModeReq;
    SECSETGetPIN2StatusReq();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_barred_dial_mode
 * DESCRIPTION
 *  Entry function of set BDN mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_set_barred_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_set_toggle = 1;
    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETSetBdlModeReq;
    SECSETGetPIN2StatusReq();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_at_cmd_update_chv
 * DESCRIPTION
 *  Message handler for AT verify PIN
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_at_cmd_update_chv(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_verify_pin_result_ind_struct *at_verify_pin_ind = (mmi_smu_verify_pin_result_ind_struct *)info;

#ifndef __MMI_DUAL_SIM_MASTER__
    extern U16 simErrorDisplayString;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FillCountDownNumber(at_verify_pin_ind->chv_info);

    switch (at_verify_pin_ind->next_type)
    {
        case MMI_SETTING_TYPE_NO_REQUIRED:
            if (gSecuritySetupContext.PINBlocked)
            {
                gSecuritySetupContext.PINBlocked = 0;
                g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;  /* 0x01: Invalid SIM */
            #ifdef __MMI_DUAL_SIM_MASTER__
                /* set the card1 status to work */
                MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_VALID);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                DeleteScreenIfPresent(SCR_ID_SECSET_PUK1);
                DeleteScreenIfPresent(SCR_ID_SECSET_PUK_NEW_PIN1);
                DeleteScreenIfPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
            }
            break;

        case MMI_SETTING_TYPE_UBCHV1:
            if (gSecuritySetupContext.PINBlocked)
            {
            #ifndef __MMI_DUAL_SIM_MASTER__
                DisplayPopup((PU8) GetString(STR_SETTING_WRONG_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #else
                DisplayPopup((PU8) GetString(STRING_MTPNP_INCORRECT_CARD1_PUK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            #endif
                mmi_secset_delete_upto_puk1();
            }
            else
            {
                //DisplayPopup((PU8) GetString(STR_SETTING_PIN_BLK), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
                memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
                gSecuritySetupContext.PINBlocked = 1;
                g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;       /* 0x01: Invalid SIM */
            #ifdef __MMI_DUAL_SIM_MASTER__
                /* set the card1 status to work */
                MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_INVALID);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
                mmi_secset_entry_scr_pin_blocked();
            }

            mmi_secset_force_to_delete_upto_puk1();
            break;

        case MMI_SETTING_TYPE_SIM_CARD_BLOCKED:
            gSecuritySetupContext.PINBlocked = 0;
            g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the card1 status to work */
            MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_CHVBLOCKED);
            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
            mmi_idle_entry_dual_sim_root_screen();
        #else /* __MMI_DUAL_SIM_MASTER__ */
            simErrorDisplayString = STR_SIM_BLOCK_MSG;
            EntryScrnSimBlockRsp();
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_delete_upto_puk1
 * DESCRIPTION
 *  fix the bug: send request to L4C + AT call + receive request from L4C + DeleteUptoScrID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_delete_upto_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* delete PUK1 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK_NEW_PIN1);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK1);
    /* delete PIN1 screen */
    DeleteScreenIfPresent(SCR_ID_SECSET_SIM_LOCK_PIN1);
    /* delete change PIN1 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    
    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        mmi_frm_add_history_before_cm_marker(SCR_ID_SECSET_PUK1, EntrySECSETPUK1);
    }
    else
    {
        ExitSECSETPUK1();
        if (GetHistoryScrID(SCR_ID_SECSET_PUK1, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_delete_upto_puk2
 * DESCRIPTION
 *  fix the bug: send request to L4C + AT call + receive request from L4C + DeleteUptoScrID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_delete_upto_puk2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* delete PUK2 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    /* delete PIN2 screen */
    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    /* delete change PIN2 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);

    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        mmi_frm_add_history_before_cm_marker(SCR_ID_SECSET_PUK2, EntrySECSETPUK2);
    }
    else
    {
        ExitSECSETPUK2();
        if (GetHistoryScrID(SCR_ID_SECSET_PUK2, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, ENCODING_LENGTH);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_delete_upto_idle_screen
 * DESCRIPTION
 *  fix the bug: send request to L4C + AT call + receive request from L4C + DeleteUptoScrID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_delete_upto_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        DeleteBeyondScrTillScr(GetCmMarkerScrnID(), IDLE_SCREEN_ID);
        mmi_frm_add_history_before_cm_marker(IDLE_SCREEN_ID, EntryIdleScreen);
    }
    else
    {
        if (IsScreenPresent(SCR_SIM_BLOCK))
        {
            DeleteUptoScrID(SCR_SIM_BLOCK);
        }
        else if (IsScreenPresent(SCR_SIM_INSERTION))
        {
            DeleteUptoScrID(SCR_SIM_INSERTION);
        }
        else
        {
            DeleteUptoScrID(IDLE_SCREEN_ID);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_delete_puk1_and_puk2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_delete_puk1_and_puk2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* delete PUK1 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK_NEW_PIN1);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK1);
    /* delete PIN1 screen */
    DeleteScreenIfPresent(SCR_ID_SECSET_SIM_LOCK_PIN1);
    /* delete PUK2 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    /* delete PIN2 screen */
    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    /* delete change PIN1/&PIN2 screens */
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_force_to_delete_upto_puk1
 * DESCRIPTION
 *  fix the bug: send request to L4C + AT call + receive request from L4C + DeleteUptoScrID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_force_to_delete_upto_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        StartTimer(AT_PUK_IN_CALL_TIMER, 2000, mmi_secset_force_to_delete_upto_puk1);
        return;
    }

    DeleteUptoScrID(SCR_ID_SECSET_PUK1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_entry_scr_pin_blocked
 * DESCRIPTION
 *  Flash message PIN is blocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_entry_scr_pin_blocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_secset_is_call_interrupt())
    {
        mmi_frm_add_history_before_cm_marker(SCR_ID_SECSET_PUK1, EntrySECSETPUK1);
        return;
    }

    EntryNewScreen(SCR_POP_UP_HISTORY, mmi_secset_exit_scr_pin_blocked, NULL, NULL);
    GenericExitScreen(SCR_ID_SECSET_PUK1, EntrySECSETPUK1);
#ifndef __MMI_DUAL_SIM_MASTER__
    ShowCategory123Screen(0, 0, 0, 0, 0, 0, STR_PIN_BLOCKED_PUK, IMG_GLOBAL_WARNING, NULL);
#else
    ShowCategory123Screen(0, 0, 0, 0, 0, 0, STRING_MTPNP_SIM1_PIN_BLOCKED, IMG_GLOBAL_WARNING, NULL);
#endif
    playRequestedTone(WARNING_TONE);
    StartTimer(CODE_VERIFIED_TIMER, CODE_VERIFIED_TIMEOUT, GoBackHistory);
    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_exit_scr_pin_blocked
 * DESCRIPTION
 *  Exit function for PIN blocked screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_exit_scr_pin_blocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    StopTimer(CODE_VERIFIED_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_is_call_interrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_secset_is_call_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((isInCall() && !IsWapCallPresent()) || (isOutgoingCall()))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_is_in_puk_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_secset_is_in_puk_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.PINBlocked == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_secset_is_in_sim2_puk_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_secset_is_in_sim2_puk_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSecuritySetupContext.PINBlocked_2 == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

