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
 * VRSIDigitDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for digit dial of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_DIGITDIAL_C
#define _MMI_DIGITDIAL_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "gpioInc.h"
#include "IdleAppProt.h"

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
#include "MainMenuDef.h"

#include "SSCStringHandle.h"
#include "CallManagementGprot.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGProt.h"
#include "MTPNP_PFAL_CC.h"
#endif/*__MMI_DUAL_SIM_MASTER__*/


/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_rcg
 * DESCRIPTION
 *  This function is entry function of digit dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_DIGIT_DIAL_MAIN, mmi_vrsi_exit_ddial_rcg, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                          /* LSK STR */
        0,                          /* LSK IMG */
        STR_GLOBAL_ABORT,           /* RSK STR */
        0,                          /* RSK IMG */
        STR_ID_VRSI_DIGIT_PROMPT,   /* message id */
        IMG_ID_VRSI_RECORDING,      /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_DIGIT;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_DIGIT_DIAL;

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_PROMPT), mmi_vrsi_ddial_start_command);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ddial_rcg
 * DESCRIPTION
 *  This function is exit function of digit dial, it will close engine if leave VR session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ddial_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If next screen is not VRSI digit recognition result screen, abort and leave VR-Session */
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_DIGIT_DIAL_MAIN) || (scr_id == SCR_ID_VRSI_DIGIT_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_start_command
 * DESCRIPTION
 *  This function start engine to init digit recognition.
 *  It will start according to current language.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_start_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.lang == MED_VRSI_INVALID_LANG)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_LANG_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Check engine state and init digit dial */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_digit_rcg(MOD_MMI, g_vrsi_cntx.session_id, g_vrsi_cntx.lang, 0);  /* 0: means no limit */

        if (result == MED_RES_OK)
        {
            return;
        }
    }

    DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_read_result
 * DESCRIPTION
 *  This function read the digit recognition result from engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_read_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length;
    U16 *digit_list;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_dgt_rcg_result(&length, &digit_list);

    if (length == 0)    /* No speak */
    {
        if (g_vrsi_cntx.retry <= MMI_VRSI_MAX_RETRY)
        {
            /* Play prompt TTS, and speak again */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_PROMPT), mmi_vrsi_ddial_start_command);
            g_vrsi_cntx.retry++;
        }
        else
        {
            GoBackHistory();
        }
    }
    else if (length > MMI_VRSI_MAX_DIAL_DIGIT)
    {
        if (g_vrsi_cntx.retry <= MMI_VRSI_MAX_RETRY)
        {
            /* Play prompt TTS, and speak again */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIAL_DIGIT_TOO_LONG), mmi_vrsi_ddial_start_command);
            g_vrsi_cntx.retry++;
        }
        else
        {
            GoBackHistory();
        }
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            g_vrsi_cntx.digit_list[i] = (U8) (digit_list[i] + 0x0030);
        }

        g_vrsi_cntx.digit_list[i] = '\0';

        /* SI engine should still ready here. */
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_rcg_init(mmi_vrsi_entry_ddial_dial_confirm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_dial_confirm
 * DESCRIPTION
 *  Entry function of dial confirmation screen of digit recognition result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_dial_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    S8 str_prompt[(MMI_VRSI_MAX_DIAL_DIGIT + 1 + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Concatenate prompt string */
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
    mmi_ucs2cat(str_prompt, str_digit);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_DIGIT_DIAL_CONFIRM, mmi_vrsi_exit_ddial_dial_confirm, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_vrsi_ddial_dial_number,KEY_EVENT_UP);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_vrsi_ddial_dial_number, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_4;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_DIGIT_DIAL;

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ddial_dial_confirm
 * DESCRIPTION
 *  Exit function of dial confirmation screen of digit recognition result.
 *  It will close engine if leave VR session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ddial_dial_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_DIGIT_DIAL_MAIN) ||  /* Re-enter digit */
        (scr_id == SCR_ID_VRSI_DIGIT_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_dial_confirm_in_history
 * DESCRIPTION
 *  This screen should be the same as "void mmi_vrsi_entry_ddial_dial_confirm(void)"
 *  except VR command. This is for placing this screen in history for keypad operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_dial_confirm_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    S8 str_prompt[(MMI_VRSI_MAX_DIAL_DIGIT + 1 + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Concatenate prompt string */
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
    mmi_ucs2cat(str_prompt, str_digit);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_DIGIT_DIAL_CONFIRM_IN_HISTORY, NULL, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_vrsi_ddial_dial_number,KEY_EVENT_UP);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_vrsi_ddial_dial_number, KEY_SEND, KEY_EVENT_UP);
#endif    /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_dial_number
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_dial_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    if (mmi_ucs2strlen(str_digit))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
		mmi_ucm_app_entry_dial_option((U8*)str_digit,NULL,NULL);
	#else 
        MakeCall(str_digit);
	#endif /*__MMI_DUAL_SIM_MASTER__*/
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_DIGITDIAL_C */ /* #ifndef _MMI_DIGITDIAL_C */

