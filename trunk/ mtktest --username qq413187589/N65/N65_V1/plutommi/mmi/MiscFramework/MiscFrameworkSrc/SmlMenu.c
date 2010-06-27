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
 *  SmlMenu.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for SIM-ME-Lock application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PersonalizationDef.h"
#include "PersonalizationProt.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "SettingsGdcl.h"       /* gSecuritySetupContext */
#include "MainMenuDef.h"        /* MAIN_MENU_TITLE_SETTINGS_ICON */
#include "CallSetUpEnum.h"      /* STR_RESTORE_PHONE */
#include "SettingProfile.h"     /* ERROR_TONE */
#include "ProfileGprots.h"      /* playRequestedTone */
#include "IdleAppDef.h"         /* g_idle_context */
#include "CustResDef.h"

#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
#include "gpioInc.h"
#endif

#include "SimDetectionGprot.h"
#include "custom_nvram_extra.h"

#include "SimDetectionGexdcl.h"

/* diamond, 2006/04/11 SML menu implementation */
#ifdef __MMI_SML_MENU__

void mmi_sml_entry_add_data(void);
void mmi_sml_read_data_from_sim_query(void);
void mmi_sml_verify_key_req(void);
void mmi_sml_input_key(void);
void mmi_sml_confirm_key(void);

#ifdef __MMI_SML_AUTO_KEY_GEN__
extern void mmi_sml_auto_key_gen_implemetation(U8 *);
#endif 

mmi_sml_menu_struct g_sml_context;

#ifdef __MMI_SML_NP_ONLY__
extern void InitSimBlockedScreen(void);
extern void InitEnterPasswordScreen(pBOOL);
extern void ShowSubLCDScreen(FuncPtr);
extern void DinitSubLCDHistory(void); 
extern U8 gCPHSRetryCount;
#endif /* __MMI_SML_NP_ONLY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_reset_input_buffer
 * DESCRIPTION
 *  Reset input buffer of add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_reset_input_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sml_context.input_imsi, 0, (MAX_IMSI_LEN + 1) * ENCODING_LENGTH);
    memset(g_sml_context.input_gid1, 0, (MAX_GID_LEN + 1) * ENCODING_LENGTH);
    memset(g_sml_context.input_gid2, 0, (MAX_GID_LEN + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_init
 * DESCRIPTION
 *  SML initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context.operation_type = 0xFF;
    g_sml_context.selected_category = 0;
    g_sml_context.action_not_from_menu = 0;

    mmi_sml_reset_input_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_is_gid1_valid
 * DESCRIPTION
 *  GID1 validation
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL mmi_sml_is_gid1_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.gid_valid_nibble & 0x01)
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
 *  mmi_sml_is_gid2_valid
 * DESCRIPTION
 *  GID2 validation
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL mmi_sml_is_gid2_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.gid_valid_nibble & 0x10)
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
 *  mmi_sml_password_screen_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]         
 *  cursor      [IN]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_password_screen_lsk_hdlr(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length < MIN_PASSWORD_LENGTH)
    {
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        if (GetActiveScreenId() == SCR_ID_SML_CONFIRM_KEY)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else if (g_sml_context.operation_type == SML_OP_UNLOCK)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else /* SML_OP_LOCK or SML_OP_ADD */
        {
        #ifdef __MMI_SML_AUTO_KEY_GEN__
            if (g_sml_context.key_state[g_sml_context.selected_category] == SML_KEY_EMPTY && mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) == 0)
                EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            else
        #endif
                ChangeLeftSoftkey(0, 0);
        }
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(gSecuritySetupContext.PasswdLenCheckCallBack, KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_popup_error_msg
 * DESCRIPTION
 *  Error string for input wrong key to unlock
 * PARAMETERS
 *  retry_count     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_popup_error_msg(U8 retry_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (retry_count == 1)
    {
        DisplayPopup((PU8) GetString(STR_ID_LAST_RETRY_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_GENERAL_RETRY_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }
}


#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_count_retry_interval
 * DESCRIPTION
 *  Count the retry interval
 * PARAMETERS
 *  retry_count     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_sml_count_retry_interval(U8 retry_count, U8 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S32 interval = MIN_RETRY_INTERVAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < max_count - retry_count; i++)
    {
        interval *= 2;
    }

    return interval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_next_attempt_function
 * DESCRIPTION
 *  Set expiration function and time
 * PARAMETERS
 *  func          [IN]
 *  countdown     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_next_attempt_function(FuncPtr func, S32 countdown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context.next_attempt_hdlr = func;
    g_sml_context.retry_countdown = countdown;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_next_attempt_expire
 * DESCRIPTION
 *  Expiration of next attempt timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_next_attempt_expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategory165Screen();
    TurnOffBacklight();

    (*g_sml_context.next_attempt_hdlr) ();

    g_sml_context.next_attempt_hdlr = NULL;
    g_sml_context.retry_countdown = 0;
}


/*****************************************************************************
 * FUNCTION
 *  sml_exit_please_wait_next_attempt
 * DESCRIPTION
 *  Exit screen of please wait for next attempt to unlock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void sml_exit_please_wait_next_attempt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S32 Cat165CountDownValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context.retry_countdown = Cat165CountDownValue;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_please_wait_next_attempt
 * DESCRIPTION
 *  Entry screen of please wait for next attempt to unlock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_please_wait_next_attempt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.retry_countdown == 0)
    {
        /* re-retry this screen and the timer is already expired */
        mmi_sml_set_next_attempt_expire();
        return;
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_WAIT_ATTEMPT);

    EntryNewScreen(SCR_ID_SML_WAIT_ATTEMPT, sml_exit_please_wait_next_attempt, mmi_sml_entry_please_wait_next_attempt, NULL);
    DinitHistory(); /* only stay in this screen */

    ShowCategory165Screen_ext(
        0,
        0,
        0,
        0,
        get_string(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_WARNING,
        g_sml_context.retry_countdown,
        guiBuffer);

    SetCat165TimerExpireFunc(mmi_sml_set_next_attempt_expire);  /* timeout to execute */

    playRequestedTone(WARNING_TONE);
    TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
}
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_convert_ansii_imsi_to_bcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]     
 *  output      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_convert_ansii_imsi_to_bcd(U8 *input, U8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;
    U8 low_byte = 9, high_byte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_IMSI_LEN; i++)
    {
        if (i % 2 == 0)
        {
            high_byte = *(input + i) - 0x30;
            *(output + j) = (high_byte << 4) + low_byte;
            j++;
        }
        else
        {
            low_byte = *(input + i) - 0x30;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_compact_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]     
 *  output      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_compact_data(U8 *input, U8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 low_byte, high_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    high_byte = *input - 0x30;
    low_byte = *(input + 1) - 0x30;
    *output = (high_byte << 4) + low_byte; // byte 1
    high_byte = *(input + 2) - 0x30;
    low_byte = *(input + 3) - 0x30;
    *(output + 1) = (high_byte << 4) + low_byte; // byte 2

    switch (strlen((S8*) input))
    {
        case 5:
            high_byte = *(input + 4) - 0x30;
            low_byte = 0x0F;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            break;

        case 6:
            high_byte = *(input + 4) - 0x30;
            low_byte = *(input + 5) - 0x30;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            break;

        case 7:
            high_byte = *(input + 4) - 0x30;
            low_byte = 0x0F;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            high_byte = *(input + 5) - 0x30;
            low_byte = *(input + 6) - 0x30;
            *(output + 3) = (high_byte << 4) + low_byte; // byte 4
            break;

        case 8:
            high_byte = *(input + 4) - 0x30;
            low_byte = *(input + 5) - 0x30;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            high_byte = *(input + 6) - 0x30;
            low_byte = *(input + 7) - 0x30;
            *(output + 3) = (high_byte << 4) + low_byte; // byte 4
            break;

        default:
           break;
    }
}


#ifdef __MMI_SML_AUTO_KEY_GEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_auto_key_gen
 * DESCRIPTION
 *  Automatic key generation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_auto_key_gen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 auto_key[MAX_SIM_SETTING_PASSWD_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_auto_key_gen_implemetation(auto_key);   /* defined in custom directory */
    mmi_asc_to_ucs2((S8*) gSecuritySetupContext.NewPassword, (S8*) auto_key);
    mmi_asc_to_ucs2((S8*) gSecuritySetupContext.ConfirmPassword, (S8*) auto_key);
    mmi_sml_verify_key_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_auto_key_gen_confirm
 * DESCRIPTION
 *  Automatic key generation confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_auto_key_gen_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SML_AUTOKEY_CONFIRM, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_AUTOKEY_CONFIRM);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SML_AUTOKEY_CONFIRM),
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_sml_set_auto_key_gen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}
#endif /* __MMI_SML_AUTO_KEY_GEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_add_data_reboot_check
 * DESCRIPTION
 *  Reboot check for add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_add_data_reboot_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_reboot = MMI_FALSE;
    U8 tmp_gid1 = 0, tmp_gid2 = 0;
    S8 tmp_imsi[MAX_IMSI_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
    if (g_sml_context.selected_category == SML_CAT_SP ||
        g_sml_context.selected_category == SML_CAT_C ||
        g_sml_context.selected_category == SML_CAT_NS_SP || g_sml_context.selected_category == SML_CAT_SIM_C)
    {
        tmp_gid1 = (U8) gui_atoi((U16*) g_sml_context.input_gid1);
    }

    if (g_sml_context.selected_category == SML_CAT_C || g_sml_context.selected_category == SML_CAT_SIM_C)
    {
        tmp_gid2 = (U8) gui_atoi((U16*) g_sml_context.input_gid2);
    }

    switch (g_sml_context.selected_category)
    {
        case SML_CAT_N:
        case SML_CAT_NS:
        case SML_CAT_SIM:
            if (strncmp((S8*) g_sml_context.imsi, tmp_imsi, strlen(tmp_imsi)) != 0)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        case SML_CAT_SP:
        case SML_CAT_NS_SP:
            if (strncmp((S8*) g_sml_context.imsi, tmp_imsi, strlen(tmp_imsi)) != 0 || tmp_gid1 != g_sml_context.gid1)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        case SML_CAT_C:
        case SML_CAT_SIM_C:
            if (strncmp((S8*) g_sml_context.imsi, tmp_imsi, strlen(tmp_imsi)) != 0 || tmp_gid1 != g_sml_context.gid1 ||
                tmp_gid2 != g_sml_context.gid2)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        default:
            break;
    }

    if (need_reboot)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_REBOOT_MSG), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        StartTimer(EM_NOTIFYDURATION_TIMER, ST_NOTIFYDURATION, ShutdownSystemOperation);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_personalization_rsp
 * DESCRIPTION
 *  Verify lock/unlock key response
 * PARAMETERS
 *  info        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_personalization_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_personalization_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_set_personalization_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_SET_PERSONALIZATION_RSP);

    if (g_sml_context.operation_type == SML_OP_ADD)
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }

    /* update retry count for each set personalization request */
    g_sml_context.retry_count[g_sml_context.selected_category] = resp->retry_count;
    /* update state for each set personalization request */
    g_sml_context.category_state[g_sml_context.selected_category] = resp->state;

    if (resp->result.flag == L4C_OK)
    {
        switch (g_sml_context.operation_type)
        {
            case SML_OP_DISABLE:
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                g_sml_context.category_state[g_sml_context.selected_category] = SML_STATE_DISABLE;
                break;

            case SML_OP_ADD:
                mmi_sml_add_data_reboot_check();
                g_sml_context.used_records[g_sml_context.selected_category]++;
                break;

            case SML_OP_REMOVE:
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                g_sml_context.used_records[g_sml_context.selected_category] = 0;
                break;

            default:
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                break;
        }
    }
    else
    {
        //DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        mmi_sml_popup_error_msg(resp->retry_count);
    }

    DeleteScreenIfPresent(SCR_ID_SML_FILL_DATA);
    DeleteScreenIfPresent(SCR_ID_SML_INPUT_KEY);
    DeleteScreenIfPresent(SCR_ID_SML_CONFIRM_KEY);

    if (g_sml_context.action_not_from_menu)
    {
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        g_sml_context.action_not_from_menu = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_personalization_req
 * DESCRIPTION
 *  Verify lock/unlock key request
 * PARAMETERS
 *  key             [?]         [?]
 *  category        [IN]        
 *  operation       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_personalization_req(U8 *key, U8 category, U8 operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_set_personalization_req_struct *local_data;
    S8 tmp_gid[MAX_GID_LEN + 1];
    S8 tmp_imsi[MAX_IMSI_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();   /* ClearInputEventHandler(MMI_DEVICE_ALL); */
    SetProtocolEventHandler(mmi_sml_set_personalization_rsp, PRT_MMI_SMU_SET_PERSONALIZATION_RSP);
    PRINT_INFORMATION("@@@@@ Sending request for query personalization status @@@@@");

    local_data =
        (mmi_smu_set_personalization_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_set_personalization_req_struct));
    local_data->category = category;
    local_data->op = operation;
    memset(local_data->data, 0, 10);

    if (key != NULL)
    {
        strncpy((S8*) local_data->key, (S8*) key, 8);
    }
    else
    {
        local_data->key[0] = 0;
    }

    //strcpy((S8*)local_data->imei, (S8*)g_sml_context.input_imsi);
    //strcpy((S8*)local_data->gid1, (S8*)g_sml_context.input_gid1);
    //strcpy((S8*)local_data->gid2, (S8*)g_sml_context.input_gid2);
    if (operation == SML_OP_ADD)
    {
        switch (g_sml_context.selected_category)
        {
            case SML_CAT_N:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                local_data->len = 3;
                break;

            case SML_CAT_NS:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                local_data->len = 4;
                break;

            case SML_CAT_SP:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                local_data->data[3] = (U8) atoi(tmp_gid);
                local_data->len = 4;
                break;

            case SML_CAT_C:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                local_data->data[3] = (U8) atoi(tmp_gid);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid2);
                local_data->data[4] = (U8) atoi(tmp_gid);
                local_data->len = 5;
                break;

            case SML_CAT_SIM:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_convert_ansii_imsi_to_bcd((U8*) tmp_imsi, local_data->data);
                local_data->len = 8;
                break;

            case SML_CAT_NS_SP:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                local_data->data[4] = (U8) atoi(tmp_gid);
                local_data->len = 5;
                break;

            case SML_CAT_SIM_C:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context.input_imsi);
                mmi_sml_convert_ansii_imsi_to_bcd((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                local_data->data[8] = (U8) atoi(tmp_gid);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid2);
                local_data->data[9] = (U8) atoi(tmp_gid);
                local_data->len = 10;
                break;
        }
    }
    else
    {
        local_data->len = 0;
        //local_data->gid1 = 0;
        //local_data->gid2 = 0;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_SET_PERSONALIZATION_REQ;
    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_verify_key_req
 * DESCRIPTION
 *  Verify lock/unlock key request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_verify_key_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;
    U8 key[MAX_SIM_SETTING_PASSWD_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.key_state[g_sml_context.selected_category] == SML_KEY_EMPTY &&
        g_sml_context.operation_type != SML_OP_UNLOCK)
    {
        /* check new key and confirmation key */
        if (mmi_ucs2cmp((S8*) gSecuritySetupContext.NewPassword, (S8*) gSecuritySetupContext.ConfirmPassword) !=
            0)
        {
            memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
            memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);

            DisplayPopup((PU8) GetString(STR_DIFF_PHONE), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_SML_CONFIRM_KEY);

            if (GetHistoryScrID(SCR_ID_SML_INPUT_KEY, &History) == ST_SUCCESS)
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

            return;
        }
    }

    mmi_ucs2_to_asc((S8*) key, (S8*) gSecuritySetupContext.NewPassword);

    if (g_sml_context.operation_type != SML_OP_ADD)
    {
        mmi_sml_reset_input_buffer();
    }

    mmi_sml_set_personalization_req(key, g_sml_context.selected_category, g_sml_context.operation_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_data_valid_check
 * DESCRIPTION
 *  Check the valiation of input data to add
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_sml_data_valid_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn = 1;
    S8 tmp_gid[MAX_GID_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sml_context.selected_category)
    {
        case SML_CAT_N:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_NS:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_NSP_LEN - 1)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_SP:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_C:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid2);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_SIM:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_IMSI_LEN)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_NS_SP:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_NSP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_SIM_C:
            if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context.input_imsi) < MAX_IMSI_LEN)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context.input_gid2);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        default:
            break;
    }

    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_allow_to_lock_or_unlock
 * DESCRIPTION
 *  Allow to send lock or unlock reuqest to L4C or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_sml_allow_to_lock_or_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.operation_type == SML_OP_LOCK || g_sml_context.operation_type == SML_OP_UNLOCK)
    {
        if (g_sml_context.retry_count[g_sml_context.selected_category] == 0)
        {
            DisplayPopup((PU8) GetString(STR_ID_SML_BLOCK_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            return 0;
        }

        if (g_sml_context.used_records[g_sml_context.selected_category] == 0)
        {
            DisplayPopup((PU8) GetString(STR_ID_NO_DATA_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            return 0;
        }

        if (g_sml_context.operation_type == SML_OP_LOCK &&
            g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_LOCK)
        {
            DisplayPopup((PU8) GetString(STR_ID_SML_CAT_LOCKED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
            return 0;
        }

        if (g_sml_context.operation_type == SML_OP_UNLOCK &&
            g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_UNLOCK)
        {
            DisplayPopup((PU8) GetString(STR_ID_SML_CAT_UNLOCKED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
            return 0;
        }

        if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_AUTOLOCK)
        {
            DisplayPopup((PU8) GetString(STR_ID_SML_CAT_AUTOLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
            return 0;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_exit_confirm_key
 * DESCRIPTION
 *  SML password confirmation screen exit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_exit_confirm_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SML_CONFIRM_KEY;
    Scr.entryFuncPtr = mmi_sml_confirm_key;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.ConfirmPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_confirm_key
 * DESCRIPTION
 *  SML password confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_confirm_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_AUTO_KEY_GEN__
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) == 0)
    {
        mmi_sml_entry_auto_key_gen_confirm();
        return;
    }
#endif /* __MMI_SML_AUTO_KEY_GEN__ */

    EntryNewScreen(SCR_ID_SML_CONFIRM_KEY, mmi_sml_exit_confirm_key, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_CONFIRM_KEY);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SML_CONFIRM_KEY);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.ConfirmPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.ConfirmPassword, (S8*) inputBuffer);
    }

    /* Hide LSK if input password length is not enough */
    RegisterInputBoxValidationFunction(mmi_sml_password_screen_lsk_hdlr);

#ifdef UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 

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

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_sml_verify_key_req, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_sml_verify_key_req, KEY_EVENT_UP);
    gSecuritySetupContext.PasswdLenCheckCallBack = mmi_sml_verify_key_req;

    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.ConfirmPassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_exit_input_key
 * DESCRIPTION
 *  SML password input screen exit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_exit_input_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SML_INPUT_KEY;
    Scr.entryFuncPtr = mmi_sml_input_key;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) gSecuritySetupContext.NewPassword);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_input_key
 * DESCRIPTION
 *  SML password input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_input_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sml_allow_to_lock_or_unlock())
    {
        return;
    }

    if (g_sml_context.operation_type == SML_OP_ADD && mmi_sml_data_valid_check() == 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_INVALID_DATA), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SML_INPUT_KEY, mmi_sml_exit_input_key, NULL, NULL);

    sprintf(temp1, " %d", g_sml_context.retry_count[g_sml_context.selected_category]);
    mmi_asc_to_ucs2(temp2, temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_PASS_TRIALS_REMAIN));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_INPUT_KEY);
    inputBuffer = GetCurrInputBuffer(SCR_ID_SML_INPUT_KEY);
    if (inputBuffer == NULL)
    {
        memset(gSecuritySetupContext.NewPassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) gSecuritySetupContext.NewPassword, (S8*) inputBuffer);
    }

    /* Hide LSK if input password length is not enough */
    RegisterInputBoxValidationFunction(mmi_sml_password_screen_lsk_hdlr);

#ifdef UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 

    if (g_sml_context.key_state[g_sml_context.selected_category] == SML_KEY_SET ||
        (g_sml_context.key_state[g_sml_context.selected_category] == SML_KEY_EMPTY &&
         g_sml_context.operation_type == SML_OP_UNLOCK))
    {
        if (g_sml_context.operation_type == SML_OP_UNLOCK)
        {
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_RESTORE_PHONE,
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.NewPassword,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                (U8*) temp1,    /* apply retry count */
                guiBuffer);
        }
        else
        {
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_RESTORE_PHONE,
                INPUT_TYPE_NUMERIC_PASSWORD,
                gSecuritySetupContext.NewPassword,
                (MAX_SIM_SETTING_PASSWD_LEN + 1),
                NULL,   /* retry count only works for unlocking a category */
                guiBuffer);
        }

        SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_sml_verify_key_req, KEY_POUND, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_sml_verify_key_req, KEY_EVENT_UP);
        gSecuritySetupContext.PasswdLenCheckCallBack = mmi_sml_verify_key_req;
    }
    else
    {
        ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_RESTORE_PHONE,
            INPUT_TYPE_NUMERIC_PASSWORD,
            gSecuritySetupContext.NewPassword,
            (MAX_SIM_SETTING_PASSWD_LEN + 1),
            NULL,   /* need to input key twice */
            guiBuffer);

        SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_sml_confirm_key, KEY_POUND, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_sml_confirm_key, KEY_EVENT_UP);
        gSecuritySetupContext.PasswdLenCheckCallBack = mmi_sml_confirm_key;
    }

    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) < MIN_PASSWORD_LENGTH)
    {
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        if (g_sml_context.operation_type == SML_OP_UNLOCK)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else /* SML_OP_LOCK or SML_OP_ADD */
        {
        #ifdef __MMI_SML_AUTO_KEY_GEN__
            if (!(g_sml_context.key_state[g_sml_context.selected_category] == SML_KEY_EMPTY && mmi_ucs2strlen((S8*) gSecuritySetupContext.NewPassword) == 0))
        #endif
                ChangeLeftSoftkey(0, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_generic_highlight_handler
 * DESCRIPTION
 *  SML generic highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_generic_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S32 count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context.selected_category = (U8) index;

    /* count the deactivated items */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] == SML_STATE_DISABLE || g_sml_context.category_state[i] == SML_STATE_NULL)
        {
            g_sml_context.selected_category++;
        }
        else
        {
            count++;
        }

        if (count == index)
        {
            break;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_lock_category_selection
 * DESCRIPTION
 *  Lock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_lock_category_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }

    EntryNewScreen(SCR_ID_SML_LOCK_MENU, NULL, mmi_sml_entry_lock_category_selection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_LOCK_MENU);
    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] != SML_STATE_DISABLE && g_sml_context.category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context.operation_type != SML_OP_LOCK)
    {
        g_sml_context.operation_type = SML_OP_LOCK;
        g_sml_context.selected_category = 0;
    }

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_LOCK_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_LOCK_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context.selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_unlock_category_selection
 * DESCRIPTION
 *  Unlock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_unlock_category_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }

    EntryNewScreen(SCR_ID_SML_UNLOCK_MENU, NULL, mmi_sml_entry_unlock_category_selection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_UNLOCK_MENU);
    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] != SML_STATE_DISABLE && g_sml_context.category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context.operation_type != SML_OP_UNLOCK)
    {
        g_sml_context.operation_type = SML_OP_UNLOCK;
        g_sml_context.selected_category = 0;
    }

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_UNLOCK_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_UNLOCK_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context.selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_fill_add_data_editor
 * DESCRIPTION
 *  Inline editor of add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_fill_add_data_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_reset_input_buffer();

    switch (g_sml_context.selected_category)
    {
        case SML_CAT_NS:
        case SML_CAT_NS_SP:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_NSP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context.input_imsi,
                MAX_NSP_LEN + 1,
                INPUT_TYPE_NUMERIC);
            break;

        case SML_CAT_SIM:
        case SML_CAT_SIM_C:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_SIMP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context.input_imsi,
                MAX_IMSI_LEN + 1,
                INPUT_TYPE_NUMERIC);

            break;

        case SML_CAT_N:
        case SML_CAT_SP:
        case SML_CAT_C:
        default:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_NP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context.input_imsi,
                MAX_NP_LEN + 1,
                INPUT_TYPE_NUMERIC);

            break;
    }

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_SML_SP_DATA));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[3], (PU8) g_sml_context.input_gid1, MAX_GID_LEN + 1, INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_SML_CP_DATA));

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[5], (PU8) g_sml_context.input_gid2, MAX_GID_LEN + 1, INPUT_TYPE_NUMERIC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_process_add_data
 * DESCRIPTION
 *  Process of user input add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_process_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_sml_context.input_imsi) == 0 /* && mmi_ucs2strlen((S8*)g_sml_context.input_gid1) == 0 */)
    {
        /* query for read data from SIM */
        mmi_sml_read_data_from_sim_query();
    }
    else
    {
        /* lock it */
        mmi_sml_input_key();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_highlight_add_data
 * DESCRIPTION
 *  Highlight handler of input data to add
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_highlight_add_data(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_sml_process_add_data);

    g_sml_context.highlight_inline_item = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_exit_add_data
 * DESCRIPTION
 *  Exit screen of input data to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_exit_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_SML_FILL_DATA;
    h.entryFuncPtr = mmi_sml_entry_add_data;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_add_data
 * DESCRIPTION
 *  Entry screen of input data to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U8 inputItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_LOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_UNLOCK_FIRST_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    if (g_sml_context.used_records[g_sml_context.selected_category] ==
        g_sml_context.total_records[g_sml_context.selected_category])
    {
        DisplayPopup((PU8) GetString(STR_ID_NO_RECORD_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_AUTOLOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_AUTOLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SML_FILL_DATA, mmi_sml_exit_add_data, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_FILL_DATA);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SML_FILL_DATA, &inputBufferSize);  /* added for inline edit history */

    mmi_sml_fill_add_data_editor();
    RegisterHighlightHandler(mmi_sml_highlight_add_data);

    switch (g_sml_context.selected_category)
    {
        case SML_CAT_SP:
        case SML_CAT_NS_SP:
            inputItems = 4;
            break;

        case SML_CAT_C:
        case SML_CAT_SIM_C:
            inputItems = 6;
            break;

        case SML_CAT_N:
        case SML_CAT_NS:
        case SML_CAT_SIM:
        default:
            inputItems = 2;
            break;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, inputItems, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_SML_ADD_MENU,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        inputItems,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    if ((g_sml_context.highlight_inline_item == 1 && mmi_ucs2strlen((S8*) g_sml_context.input_imsi) == 0) ||
        (g_sml_context.highlight_inline_item == 3 && mmi_ucs2strlen((S8*) g_sml_context.input_gid1) == 0) ||
        (g_sml_context.highlight_inline_item == 5 && mmi_ucs2strlen((S8*) g_sml_context.input_gid2) == 0))
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_generate_data
 * DESCRIPTION
 *  Automatic data generation from SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_auto_generate_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sml_context.selected_category)
    {
        case SML_CAT_N:
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context.input_imsi,
                (S8*) g_sml_context.imsi,
                g_sml_context.digits_of_mcc_mnc);
            break;
        case SML_CAT_NS:
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context.input_imsi,
                (S8*) g_sml_context.imsi,
                g_sml_context.digits_of_mcc_mnc + 2);
            break;
        case SML_CAT_SP:    /* 5 or 6 digits of IMSI + GID1 */
            if (!mmi_sml_is_gid1_valid())
            {
                DisplayPopup((U8*) GetString(STR_ID_SML_NO_EF_GID), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context.input_imsi,
                (S8*) g_sml_context.imsi,
                g_sml_context.digits_of_mcc_mnc);
            gui_itoa(g_sml_context.gid1, (U16*) (&g_sml_context.input_gid1[0]), 10);
            break;
        case SML_CAT_C: /* 5 or 6 digits of IMSI + GID1 + GID2 */
            if (!mmi_sml_is_gid1_valid() || !mmi_sml_is_gid2_valid())
            {
                DisplayPopup((U8*) GetString(STR_ID_SML_NO_EF_GID), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context.input_imsi,
                (S8*) g_sml_context.imsi,
                g_sml_context.digits_of_mcc_mnc);
            gui_itoa(g_sml_context.gid1, (U16*) (&g_sml_context.input_gid1[0]), 10);
            gui_itoa(g_sml_context.gid2, (U16*) (&g_sml_context.input_gid2[0]), 10);
            break;
        case SML_CAT_SIM:   /* IMSI */
            mmi_asc_to_ucs2((S8*) g_sml_context.input_imsi, (S8*) g_sml_context.imsi);
            break;
        case SML_CAT_NS_SP: /* 7 or 8 digits of IMSI + GID1 */
            if (!mmi_sml_is_gid1_valid())
            {
                DisplayPopup((U8*) GetString(STR_ID_SML_NO_EF_GID), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context.input_imsi,
                (S8*) g_sml_context.imsi,
                g_sml_context.digits_of_mcc_mnc + 2);
            gui_itoa(g_sml_context.gid1, (U16*) (&g_sml_context.input_gid1[0]), 10);
            break;
        case SML_CAT_SIM_C: /* IMSI + GID1 + GID2 */
            if (!mmi_sml_is_gid1_valid() || !mmi_sml_is_gid2_valid())
            {
                DisplayPopup((U8*) GetString(STR_ID_SML_NO_EF_GID), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
                return;
            }
            mmi_asc_to_ucs2((S8*) g_sml_context.input_imsi, (S8*) g_sml_context.imsi);
            gui_itoa(g_sml_context.gid1, (U16*) (&g_sml_context.input_gid1[0]), 10);
            gui_itoa(g_sml_context.gid2, (U16*) (&g_sml_context.input_gid2[0]), 10);
            break;
        default:
            break;
    }

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    DeleteScreenIfPresent(SCR_ID_SML_FILL_DATA);
    GenericExitScreen(SCR_ID_SML_INPUT_KEY, mmi_sml_input_key); /* continue to input key after popup disappears */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_read_data_from_sim_query
 * DESCRIPTION
 *  Query for automatically read data from SIM to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_read_data_from_sim_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SML_QUERY_POPUP, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_QUERY_POPUP);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SML_QUREY_MSG),
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_sml_auto_generate_data, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_add_category_data
 * DESCRIPTION
 *  Add data catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_add_category_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }

    EntryNewScreen(SCR_ID_SML_ADD_MENU, NULL, mmi_sml_entry_add_category_data, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_ADD_MENU);
    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] != SML_STATE_DISABLE && g_sml_context.category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context.operation_type != SML_OP_ADD)
    {
        g_sml_context.operation_type = SML_OP_ADD;
        g_sml_context.selected_category = 0;
    }

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_ADD_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_ADD_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context.selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_add_data, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_delete_req
 * DESCRIPTION
 *  Remove data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_set_personalization_req(NULL, g_sml_context.selected_category, g_sml_context.operation_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_remove_confirm
 * DESCRIPTION
 *  Remove data confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_LOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_UNLOCK_FIRST_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    if (g_sml_context.used_records[g_sml_context.selected_category] == 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_NO_DATA_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_AUTOLOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_AUTOLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SML_REMOVE_CONFIRM, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_REMOVE_CONFIRM);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_sml_send_delete_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_remove_category_data
 * DESCRIPTION
 *  Remove data catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_remove_category_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }

    EntryNewScreen(SCR_ID_SML_REMOVE_MENU, NULL, mmi_sml_entry_remove_category_data, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_REMOVE_MENU);
    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] != SML_STATE_DISABLE && g_sml_context.category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context.operation_type != SML_OP_REMOVE)
    {
        g_sml_context.operation_type = SML_OP_REMOVE;
        g_sml_context.selected_category = 0;
    }

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_REMOVE_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_REMOVE_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context.selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_remove_confirm, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_deactivate_confirm
 * DESCRIPTION
 *  Permanent unlock confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_deactivate_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_LOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_UNLOCK_FIRST_MSG), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    if (g_sml_context.category_state[g_sml_context.selected_category] == SML_STATE_AUTOLOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_AUTOLOCKED), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SML_DEACTIVATE_CONFIRM, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_REMOVE_CONFIRM);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DEACTIVATE),
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_sml_send_delete_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_permanent_unlock_selection
 * DESCRIPTION
 *  Permanent unlock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_permanent_unlock_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }

    EntryNewScreen(SCR_ID_SML_DEACTIVATE_MENU, NULL, mmi_sml_entry_permanent_unlock_selection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SML_DEACTIVATE_MENU);
    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] != SML_STATE_DISABLE && g_sml_context.category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context.operation_type != SML_OP_DISABLE)
    {
        g_sml_context.operation_type = SML_OP_DISABLE;
        g_sml_context.selected_category = 0;
    }

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_DEACTIVATE_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(EntryIdleScreen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_DEACTIVATE_MENU,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context.selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_deactivate_confirm, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_lock_req_by_ssc
 * DESCRIPTION
 *  SSC for lock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_lock_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1, *ptr2 = NULL;
    U8 i, count = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ansii_ssc_string, g_idle_context.DialPadCallBuffer);

    if (memcmp(ansii_ssc_string, SSC_SML_LOCK_CMD, strlen(SSC_SML_LOCK_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_LOCK_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
                if (count == 1)
                {
                    ptr2 = ptr1 + i + 1;
                }
            }
        }

        if (count < 2)
        {
            /* input unfinished */
            return;
        }
        else
        {
            if (strlen((S8*) ptr1) > MAX_SIM_SETTING_PASSWD_LEN || strlen((S8*) ptr1) < MIN_PASSWORD_LENGTH)
            {
                EntryScrInvalidPINPUKPLOCKLength(); /* invalid key length */
                return;
            }

            /* send request */
            g_sml_context.selected_category = (U8) atoi((S8*) ptr2) - 1;

            if (g_sml_context.selected_category < SML_CAT_SIZE)
            {
                g_sml_context.operation_type = SML_OP_LOCK;

                if (!mmi_sml_allow_to_lock_or_unlock())
                {
                    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
                    return;
                }

                g_sml_context.action_not_from_menu = 1;
                mmi_sml_set_personalization_req(ptr1, g_sml_context.selected_category, SML_OP_LOCK);
            }
        }
    }
    else
    {
        /* wrong case for this function */
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_unlock_req_by_ssc
 * DESCRIPTION
 *  SSC for unlock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_unlock_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1, *ptr2 = NULL;
    U8 i, count = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ansii_ssc_string, g_idle_context.DialPadCallBuffer);

    if (memcmp(ansii_ssc_string, SSC_SML_UNLOCK_CMD, strlen(SSC_SML_UNLOCK_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_UNLOCK_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
                if (count == 1)
                {
                    ptr2 = ptr1 + i + 1;
                }
            }
        }

        if (count < 2)
        {
            /* input unfinished */
            return;
        }
        else
        {
            if (strlen((S8*) ptr1) > MAX_SIM_SETTING_PASSWD_LEN || strlen((S8*) ptr1) < MIN_PASSWORD_LENGTH)
            {
                EntryScrInvalidPINPUKPLOCKLength(); /* invalid key length */
                return;
            }

            /* send request */
            g_sml_context.selected_category = (U8) atoi((S8*) ptr2) - 1;

            if (g_sml_context.selected_category < SML_CAT_SIZE)
            {
                g_sml_context.operation_type = SML_OP_UNLOCK;

                if (!mmi_sml_allow_to_lock_or_unlock())
                {
                    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
                    return;
                }

                g_sml_context.action_not_from_menu = 1;
                mmi_sml_set_personalization_req(ptr1, g_sml_context.selected_category, SML_OP_UNLOCK);
            }
        }
    }
    else
    {
        /* wrong case for this function */
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_query_rsp_by_ssc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_query_rsp_by_ssc(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sml_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_sml_status_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_SML_STATUS_RSP);

    /* display this category is locked or unlocked */
    if (resp->state[g_sml_context.selected_category] == SML_STATE_AUTOLOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_AUTOLOCKED), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, 0);
    }
    else if (resp->state[g_sml_context.selected_category] == SML_STATE_LOCK)
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_LOCKED), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, 0);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_UNLOCKED), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, 0);
    }

    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_query_req_by_ssc
 * DESCRIPTION
 *  SSC for lock or unlock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_query_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1;
    U8 i, count = 0, len;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ansii_ssc_string, g_idle_context.DialPadCallBuffer);

    if (memcmp(ansii_ssc_string, SSC_SML_QUERY_CMD, strlen(SSC_SML_QUERY_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_QUERY_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
            }
        }

        if (count < 1)
        {
            /* input unfinished */
            return;
        }
        else
        {
            g_sml_context.selected_category = (U8) atoi((S8*) ptr1) - 1;

            if (g_sml_context.selected_category < SML_CAT_SIZE)
            {
                /* send request */
                ClearAllKeyHandler();   /* ClearInputEventHandler(MMI_DEVICE_ALL); */
                SetProtocolEventHandler(mmi_sml_send_query_rsp_by_ssc, PRT_MMI_SMU_SML_STATUS_RSP);
                PRINT_INFORMATION("@@@@@ Sending request for query personalization status @@@@@");

                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = MOD_L4C;
                Message.oslMsgId = PRT_MMI_SMU_SML_STATUS_REQ;
                Message.oslDataPtr = NULL;  /* no parameters */
                Message.oslPeerBuffPtr = NULL;

                OslMsgSendExtQueue(&Message);
            }
            else
            {
                /* wrong category */
                return;
            }
        }
    }
    else
    {
        /* wrong case for this function */
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_power_on_query_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_power_on_query_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sml_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_sml_status_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_SML_STATUS_RSP);

    memcpy(g_sml_context.category_state, resp->state, SML_CAT_SIZE);
    memcpy(g_sml_context.key_state, resp->key_state, SML_CAT_SIZE);
    memcpy(g_sml_context.total_records, resp->total_size_of_cat, SML_CAT_SIZE);
    memcpy(g_sml_context.used_records, resp->num_of_sets, SML_CAT_SIZE);
    memcpy(g_sml_context.retry_count, resp->retry_count, SML_CAT_SIZE);

    memset(g_sml_context.imsi, 0, MAX_IMSI_LEN + 1);
    strncpy((S8*) g_sml_context.imsi, (S8*) (resp->imsi) + 1, MAX_IMSI_LEN);

    g_sml_context.gid_valid_nibble = 0;
    if (resp->is_valid_gid1)
    {
        g_sml_context.gid_valid_nibble |= 0x01;
        g_sml_context.gid1 = resp->ef_gid1;
    }
    if (resp->is_valid_gid2)
    {
        g_sml_context.gid_valid_nibble |= 0x10;
        g_sml_context.gid2 = resp->ef_gid2;
    }

    if (resp->digits_of_mnc == 0)
    {
        g_sml_context.digits_of_mcc_mnc = 5;    /* default */
    }
    else
    {
        g_sml_context.digits_of_mcc_mnc = resp->digits_of_mnc + 3;
    }

#ifdef __MMI_SML_NP_ONLY__    
    gCPHSRetryCount = g_sml_context.retry_count[SML_CAT_N];
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_power_on_query_req
 * DESCRIPTION
 *  Power on period query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_power_on_query_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_sml_power_on_query_rsp, PRT_MMI_SMU_SML_STATUS_RSP);
    PRINT_INFORMATION("@@@@@ Sending request for query personalization status @@@@@");

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_SML_STATUS_REQ;
    Message.oslDataPtr = NULL;  /* no parameters */
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_locked_fail
 * DESCRIPTION
 *  Auto lock failure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_auto_locked_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_ID_SML_FAIL_TO_AUTOLOCK), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_locked_done
 * DESCRIPTION
 *  Auto lock done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_auto_locked_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_ID_SML_AUTOLOCKED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_display_auto_locked_notification
 * DESCRIPTION
 *  Display a popup for auto locked SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_display_auto_locked_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.autolock_nibble != 0)
    {
        if (g_sml_context.autolock_nibble & 0x10)
        {
            StartTimer(SML_AUTOLOCK_IDLE_NOTIFY_TIMER, 3000, mmi_sml_auto_locked_done);
        }
        else
        {
            StartTimer(SML_AUTOLOCK_IDLE_NOTIFY_TIMER, 3000, mmi_sml_auto_locked_fail);
        }
    }
}


#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_unlock_after_verified_paswd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_unlock_after_verified_paswd_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_personalization_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_set_personalization_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_SET_PERSONALIZATION_RSP);

    /* update retry count for each set personalization request */
    g_sml_context.retry_count[g_sml_context.selected_category] = resp->retry_count;
    /* update state for each set personalization request */
    g_sml_context.category_state[g_sml_context.selected_category] = resp->state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_unlock_after_verified_paswd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_unlock_after_verified_paswd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MYQUEUE Message;
    mmi_smu_set_personalization_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context.category_state[i] == SML_STATE_LOCK)
        {
            SetProtocolEventHandler(mmi_sml_unlock_after_verified_paswd_hdlr, PRT_MMI_SMU_SET_PERSONALIZATION_RSP);
            PRINT_INFORMATION("@@@@@ Sending request for query personalization status @@@@@");

            local_data =
                (mmi_smu_set_personalization_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_set_personalization_req_struct));
            local_data->category = i;
            local_data->op = SML_OP_UNLOCK;
            strncpy((S8*) local_data->key, (S8*) g_sml_context.auto_unlock_key[i], 8);
            memset(local_data->data, 0, 10);
            local_data->len = 0;

            Message.oslSrcId = MOD_MMI;
            Message.oslDestId = MOD_L4C;
            Message.oslMsgId = PRT_MMI_SMU_SET_PERSONALIZATION_REQ;
            Message.oslDataPtr = (oslParaType*) local_data;
            Message.oslPeerBuffPtr = NULL;

            OslMsgSendExtQueue(&Message);
            return;
        }
    }
}


#ifdef __MMI_SML_NP_ONLY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_verify_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_sim_verify_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_in_power_on_period())
    {
        return;
    }

    mmi_sml_power_on_query_req();
    mmi_sml_unlock_after_verified_paswd();
    memset((S8*) gInputPwdBuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    if (!mmi_bootup_is_sim_valid())
    {
        EntryScrnSimErrorScreen();
    }
    else
    {
        GoBackHistory();
        DeleteScreenIfPresent(SCR_ENTER_NP);
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_entry_check_np_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_sim_entry_check_np_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context.category_state[SML_CAT_N] == SML_STATE_LOCK)
    {
        if (gCPHSRetryCount > 0)
        {
            EntryScrEnterNP();
            InitEnterPasswordScreen(MMI_TRUE);
        }
        else
        {
            return;
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_SML_CAT_UNLOCKED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_entry_pending_np_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_sim_entry_pending_np_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U16 BlockSIMScreenDigits[MAX_INSERT_SCR_DIGITS] =
        {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCPHSRetryCount == 0)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: insert/blocked SIM idle screen */
        InitSimBlockedScreen();
        return;
    }

    if (g_pwr_context.PrevScreenIndicator == ENTER_NP)
    {
        DisplayPopup((U8*) GetString(STR_WRONG_NP_MSG), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_SIM_BLOCK, NULL, mmi_bootup_sim_entry_pending_np_screen, NULL);

    DinitHistory(); /* Dinit History is called to prevent memory leak */
    g_pwr_context.PrevScreenIndicator = ENTER_NP_PENDING;
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_SECURITY_PERSONALIZATION;     /* 0x14: Personalization lock */

    guiBuffer = GetCurrGuiBuffer(SCR_SIM_BLOCK);

    ShowSubLCDScreen(ShowSubLCDBlockedSIM);
    DinitSubLCDHistory();

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 

    //ShowCategory123Screen(0, 0, 0, 0, STR_RSK_SOS, 0, STR_SIM_BLOCK_MSG, IMG_GLOBAL_WARNING, NULL);
    ShowCategory123Screen(0, 0, KEYPAD_LOCKED_RSK_TEXT, 0, STR_RSK_SOS, 0, STR_SIM_BLOCK_MSG, IMG_GLOBAL_WARNING, NULL);
 
    SetLeftSoftkeyFunction(mmi_bootup_sim_entry_check_np_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(ShowMakeSOSCallScr, KEY_EVENT_UP);
    SetGroupKeyHandler(HandleInsertSIMScrDigitEntry, BlockSIMScreenDigits, MAX_INSERT_SCR_DIGITS - 1, KEY_EVENT_DOWN);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) )
    SetCenterSoftkeyFunction(HandleInsertSIMScrDigitEntry, KEY_EVENT_UP);
#endif 
}

#endif /* __MMI_SML_NP_ONLY__ */

#endif /* __MMI_SML_UNLOCK_AFTER_VERIFIED__ */ 

#endif /* __MMI_SML_MENU__ */ 

