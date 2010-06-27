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
 * VRSIProfile.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for switch profile of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSIPROFILE_C
#define _MMI_VRSIPROFILE_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"

/* ... Add More MMI header */
#include "med_global.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "VRSIResDef.h"
#include "gpioInc.h"
#include "MainMenuDef.h"

/* Profile Related */
#include "UserProfilesResDef.h"
#include "ProfileGprots.h"
#include "Profiles_prot.h"
#include "SettingProfile.h"

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */
/*
 * typedef enum
 * {
 * MMI_VRSI_PROFILE_MODE_1,
 * MMI_VRSI_PROFILE_MODE_2,
 * MMI_VRSI_PROFILE_MODE_3,
 * MMI_VRSI_PROFILE_MODE_4,   
 * MMI_VRSI_PROFILE_MODE_5,
 * MMI_VRSI_PROFILE_MODE_6,
 * MMI_VRSI_PROFILE_MODE_7
 * } vrsi_profile_mode_enum;
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_vrsi_profile_mode;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U8 gactivatedprofile;

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_rcg_grammar1_result
 * DESCRIPTION
 *  This function get profile index by recognition result.
 * PARAMETERS
 *  rcg_result      [IN]        Profile ID of recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_rcg_grammar1_result(U16 rcg_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((rcg_result >= VRSI_CMD1_PROFILE1) && (rcg_result <= VRSI_CMD1_PROFILE6))
    {
        /* Profile 1 enum value is 0: MMI_PROFILE_GENERAL */
        g_vrsi_profile_mode = rcg_result - VRSI_CMD1_PROFILE1;
    }
    else if ((rcg_result >= VRSI_CMD1_SWITCH_PROFILE1) && (rcg_result <= VRSI_CMD1_SWITCH_PROFILE7))
    {
        /* Profile 1 enum value is 0: MMI_VRSI_PROFILE_MODE_1 */
        g_vrsi_profile_mode = rcg_result - VRSI_CMD1_SWITCH_PROFILE1;
    }
    else
    {
        mmi_vrsi_prf_no_mode_prompt();
        return;
    }

    mmi_vrsi_prf_pre_switch_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_pre_switch_mode
 * DESCRIPTION
 *  This function check if it can switch to desire mode before switch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_pre_switch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_profile_mode == gactivatedprofile)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_ALREADY_IN_MODE),
            IMG_GLOBAL_WARNING,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            WARNING_TONE);
        return;
    }

#ifdef __MMI_BT_PROFILE__
    if (IsHeadsetModeActivated() || mmi_profiles_bt_is_activated())
#else 
    if (IsHeadsetModeActivated())
#endif 
        mmi_vrsi_prf_cannot_switch_prompt();
    else if (g_vrsi_profile_mode == MMI_PROFILE_HEADSET || g_vrsi_profile_mode == MMI_PROFILE_BT)       /* headset/bt mode, enum value 4 or 6 */
    {
        mmi_vrsi_prf_cannot_switch_prompt();
    }
    else
    {
        mmi_vrsi_entry_prf_switch_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_switch_prompt_message
 * DESCRIPTION
 *  This function play prompt tts when switch mode
 * PARAMETERS
 *  str_prompt      [IN]        Prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_switch_prompt_message(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_SWITCHED_PROMPT));

    mmi_vrsi_prf_get_mode_prompt(str_prompt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_prf_switch_prompt
 * DESCRIPTION
 *  Entry function of switch profile mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_prf_switch_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_prf_switch_prompt_message(str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_SWITCH_PROFILE_PROMPT, mmi_vrsi_exit_prf_switch_prompt, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                  /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message id */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    //g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_DIGIT;
    //g_vrsi_cntx.curr_scenario = VRSI_CMD1_DIGIT_DIAL;

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_prf_switch_mode);

    /* g_vrsi_cntx.retry++; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_prf_switch_prompt
 * DESCRIPTION
 *  Exit function of switch profile mode. it will close engine if leave VR session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_prf_switch_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_switch_mode
 * DESCRIPTION
 *  This function switch current profile mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_switch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_profile_mode == MMI_PROFILE_SILENT)  /* silent mode, enum value 5 */
    {
        ActivateSilentProfile();
    }
    else
    {
        mmi_profiles_entry_activate_profile_by_id(g_vrsi_profile_mode);  /* enum value = 0, or 1, or 2, or 3 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_no_mode_prompt
 * DESCRIPTION
 *  This function play tts for no profile to switch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_no_mode_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));
    mmi_ucs2cat(str_prompt, GetString(STR_PROFILE_CAPTION));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SPEAK_AGAIN_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_cannot_switch_prompt
 * DESCRIPTION
 *  This function play tts for can not switch to specific mode. (Ex. headset mode)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_cannot_switch_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_CANT_SWITCH_PROMPT));

    mmi_vrsi_prf_get_mode_prompt(str_prompt);

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SPEAK_AGAIN_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_prf_get_mode_prompt
 * DESCRIPTION
 *  This function return mode string according to index.
 * PARAMETERS
 *  str_prompt      [IN]        Prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_prf_get_mode_prompt(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_profile_mode == MMI_PROFILE_GENERAL)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_GENERAL));
    }
    else if (g_vrsi_profile_mode == MMI_PROFILE_MEETING)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_MEETING));
    }
    else if (g_vrsi_profile_mode == MMI_PROFILE_OUTDOOR)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_OUTDOOR));
    }
    else if (g_vrsi_profile_mode == MMI_PROFILE_INDOOR)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_INDOOR));
    }
    else if (g_vrsi_profile_mode == MMI_PROFILE_HEADSET)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_HEADSET));
    }
    else if (g_vrsi_profile_mode == MMI_PROFILE_SILENT)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_PROFILE_SILENT));
    }
#ifdef __MMI_BT_PROFILE__    
    else if (g_vrsi_profile_mode == MMI_PROFILE_BT)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_PROFILES_BT));
    }
#endif    
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSIPROFILE_C */ /* #ifndef _MMI_VRSIPROFILE_C */

