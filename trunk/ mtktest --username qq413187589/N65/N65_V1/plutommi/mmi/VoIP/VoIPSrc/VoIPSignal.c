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
 *  VoIPSignal.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "CallsGprots.h"
#include "DateTimeGprot.h"
#include "PhoneBookGprot.h"
#include "VolumeHandler.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UCMCallProt.h"
#endif /* __MMI_UCM__ */

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"


#ifdef SIP_CONFORMANCE_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_option_query_check
 * DESCRIPTION
 *  Determine target's URI and get ready to process option query action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_option_query_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_voip_cntx_p->call_misc_info.dispUri))
    {
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN);
        mmi_voip_parse_uri(unicodeUri);
        memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
        mmi_ucs2_n_to_asc(
            (S8*)g_voip_cntx_p->call_misc_info.inputUri,
            (S8*)unicodeUri,
            (VOIP_URI_LEN * ENCODING_LENGTH));
        if (mmi_voip_validate_uri(unicodeUri) == TRUE)
        {
            mmi_voip_set_processing_parameter(
                STR_GLOBAL_SEARCHING,
                STR_ID_VOIP_PROCESSING,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                0,
                0,
                0,
                0);
            mmi_voip_entry_processing_screen();
            mmi_voip_option_query_req();
        }
        else
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_VOIP_INVALID_USERNAME),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
    else    /* not allow to query an empty number */
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    OslMfree(unicodeUri);
}
#endif /* SIP_CONFORMANCE_TEST */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_pre_dial
 * DESCRIPTION
 *  Determine to dial or not based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pre_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    U8 opCode = 0;
#endif /* __MMI_UCM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    opCode = (mmi_voip_get_active_call_id() != -1) ? (MMI_UCM_HOLD_AND_DIAL) : (MMI_UCM_DIAL);
#endif /* __MMI_UCM__ */

    /* check register state */
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
    #ifndef __MMI_UCM__
        /* cannot dial voip call when gsm call exists */
        if (GetTotalCallCount() != 0)
        {
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL), IMG_GLOBAL_UNFINISHED);
            g_voip_cntx_p->call_misc_info.isSOS = FALSE;
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
            {
                /* in case it is redialing, redialing screen should be deleted */
                PRINT_INFORMATION("\n[mmi_voip_pre_dial] Redialing Process Aborts because of Incoming GSM Call\n");
                mmi_voip_entry_abort_redial();
            }
            return;
        }
    #endif /* __MMI_UCM__ */
        /* check call boundary */
        if ((mmi_voip_is_codec_compatible(g_voip_cntx_p->call_setting_info.codecEnum, FALSE)) &&
            (g_voip_cntx_p->call_list_info.numTotal < MMI_VOIP_MAX_NUM_CALL))
        {
            mmi_voip_entry_dial();
        }
        else /* current codec does not support or call boundary exceeds */
        {
            g_voip_cntx_p->call_misc_info.isSOS = FALSE;
        #ifndef __MMI_UCM__
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL), IMG_GLOBAL_UNFINISHED);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
        #else   
            mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL));
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        #endif /* __MMI_UCM__ */    
        }
    }
    else if (g_voip_cntx_p->reg_state_info == MMI_VOIP_DEREG_STATE)
    {
        /* in case user intends to dial sos originally but change his mind after login */
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
    #ifndef __MMI_UCM__
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    #endif
        if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
        {
            /* in case receiving deregister_ind in redialing process */
            PRINT_INFORMATION("\n[mmi_voip_pre_dial] Redialing Process Aborts because of Not Register\n");
            mmi_voip_entry_abort_redial();
        }
    #ifdef __MMI_UCM__
        mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, NULL);        
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    #endif /* __MMI_UCM__ */
        mmi_voip_entry_login_confirm(); // TODO: send display confirm to UCM
    }
    else /* g_voip_cntx_p->reg_state_info == MMI_VOIP_PROCESS_STATE */
    {
        /* in case user intends to dial sos originally but change his mind after login */
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
    #ifndef __MMI_UCM__
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    #endif
        if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
        {
            /* in case receiving deregister_ind in redialing process */
            PRINT_INFORMATION("\n[mmi_voip_pre_dial] Redialing Process Aborts because of Register Ongoing\n");
            mmi_voip_entry_abort_redial();
        }
    #ifndef __MMI_UCM__
        mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_PROCESSING), IMG_GLOBAL_UNFINISHED);
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
    #else
        mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_PROCESSING));    
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    #endif /* __MMI_UCM__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_dial
 * DESCRIPTION
 *  Entry function of VoIP\New Call\Option\Dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *unicodeOwner = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    S32 activecallId = 0;
#ifdef __MMI_UCM__
    U8 opCode = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_voip_is_sos_number(g_voip_cntx_p->call_misc_info.dispUri) == TRUE)
    {
        mmi_voip_entry_dial_sos();
        OslMfree(unicodeUri);
        OslMfree(unicodeOwner);
        return;
    }
#ifdef __MMI_UCM__
    activecallId = mmi_voip_get_active_call_id();
    opCode = (activecallId != -1) ? (MMI_UCM_HOLD_AND_DIAL) : (MMI_UCM_DIAL);
#endif /* __MMI_UCM__ */
    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_misc_info.dispUri))
    {
        MMI_ASSERT(g_voip_cntx_p->call_misc_info.dispUri[VOIP_URI_LEN * ENCODING_LENGTH - 2] == '\0' && g_voip_cntx_p->call_misc_info.dispUri[VOIP_URI_LEN * ENCODING_LENGTH - 1] == '\0');
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN);
        mmi_voip_parse_uri(unicodeUri);
        memset(unicodeOwner, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*)unicodeOwner, 
            (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username, 
            VOIP_URI_LEN);
        if (mmi_voip_is_owner_number(unicodeUri, unicodeOwner) == TRUE)
        {
        #ifndef __MMI_UCM__
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_CANNOT_DIAL_OWNER), IMG_GLOBAL_UNFINISHED);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
        #else
            mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_CANNOT_DIAL_OWNER));
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        #endif /* __MMI_UCM__ */
        }
        else /* normal call */
        {
            if (mmi_voip_validate_uri(unicodeUri) == TRUE)
            {
                memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
                mmi_ucs2_n_to_asc(
                    (S8*)g_voip_cntx_p->call_misc_info.inputUri,
                    (S8*)unicodeUri,
                    (VOIP_URI_LEN * ENCODING_LENGTH));
                if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
                {
                    MMI_ASSERT(g_voip_cntx_p->call_misc_info.inputUri[VOIP_URI_LEN - 1] == '\0');
                    memcpy(g_voip_cntx_p->call_redial_info.redialUri, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
                }
                /* set all rtp directions as inactive before action */
                mmi_voip_switch_rtp(TRUE, -1, -1);
            #ifndef __MMI_UCM__
                /* marker has to add before outgoing call screen, otherwise, it will clear outgoing call screen key handler */
                mmi_voip_entry_marker();
                mmi_voip_entry_outgoing_call();
            #else
                mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, TRUE, NULL);
            #endif
                activecallId = mmi_voip_get_active_call_id();
                if (activecallId != -1)
                {
                    mmi_voip_hold_and_dial_req(activecallId);
                }
                else
                {
                    mmi_voip_dial_req();
                }
            }
            else
            {
            #ifndef __MMI_UCM__
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
                mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_INVALID_USERNAME), IMG_GLOBAL_UNFINISHED);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
            #else
                mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_INVALID_USERNAME));
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            #endif /* __MMI_UCM__ */
            }
        }
    }
    else /* not allow to dial an empty number */
    {
    #ifndef __MMI_UCM__
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));    
        mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME), IMG_GLOBAL_UNFINISHED);
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
    #else
        mmi_voip_ucm_dial_act_rsp(opCode, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME));
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    #endif /* __MMI_UCM__ */
    }
    OslMfree(unicodeUri);
    OslMfree(unicodeOwner);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_redial
 * DESCRIPTION
 *  Entry function when redial timer expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_redial(void)
{
    StopTimer(VOIP_AUTOREDIAL_TIMER);
    MMI_ASSERT(g_voip_cntx_p->call_redial_info.redialUri[VOIP_URI_LEN - 1] == '\0');
    mmi_asc_n_to_ucs2((S8*)g_voip_cntx_p->call_misc_info.dispUri, (S8*)g_voip_cntx_p->call_redial_info.redialUri, VOIP_URI_LEN);
    g_voip_cntx_p->call_redial_info.currAttempt++;
    mmi_voip_pre_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_save_phonebook
 * DESCRIPTION
 *  Entry function of VoIP\New Call\Option\Save to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_save_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save dtmf digits to phonebook in call */
    if (GetExitScrnID() == SCR_ID_VOIP_DTMF_EDITOR)
    {
        SaveNumberFromIdleScrn((S8*)g_voip_cntx_p->call_misc_info.dispDtmf, 0);
    }
    /* save uri address to phonebook in call */
    else
    {
        /* cannot save empty uri address to phonebook */
        if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_misc_info.dispUri))
        {
            mmi_phb_save_entry_for_service_field(NULL, (S8*)g_voip_cntx_p->call_misc_info.dispUri, MMI_PHB_ENTER_FROM_VOIP);
        }
        else
        {
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME), IMG_GLOBAL_UNFINISHED);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_sos
 * DESCRIPTION
 *  Entry function of VoIP\New Call\Option\SOS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_sos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    mmi_voip_pre_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_dial_sos
 * DESCRIPTION
 *  Dial emergency number.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_dial_sos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*)g_voip_cntx_p->call_misc_info.inputUri,
        (S8*)g_voip_cntx_p->call_misc_info.dispUri,
        (VOIP_URI_LEN * ENCODING_LENGTH));
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
#ifndef __MMI_UCM__
    /* marker has to add before outgoing call screen, otherwise, it will clear outgoing call screen key handler */
    mmi_voip_entry_marker();
    mmi_voip_entry_outgoing_call();
#else
    mmi_voip_ucm_dial_act_rsp(MMI_UCM_DIAL, MMI_UCM_INVALID_ID, MMI_UCM_INVALID_ID, TRUE, NULL);
#endif
    mmi_voip_dial_sos_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_call
 * DESCRIPTION
 *  Abort outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
    {
        mmi_voip_entry_abort_redial();
    }
#ifndef __MMI_UCM__
    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_GLOBAL_ABORT,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_VOIP_OUTGOING_CALL);
#endif
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    callId = mmi_voip_get_outgoing_call_id();
    g_voip_cntx_p->call_misc_info.isAbort = TRUE;
    if (callId != -1)
    {
    #ifndef __MMI_UCM__
        mmi_voip_stop_inbandtone();
    #endif
        mmi_voip_release_req(callId, 0);
        mmi_voip_force_release_req(callId, 0);
    }
    else
    {
        /* progressing_ind is not received yet */
        mmi_voip_release_req(g_voip_cntx_p->call_list_info.maxnumCall, 0);
        mmi_voip_force_release_req(g_voip_cntx_p->call_list_info.maxnumCall, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_redial
 * DESCRIPTION
 *  Abort redialing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_redial(void)
{
#ifndef __MMI_UCM__
    StopTimer(VOIP_AUTOREDIAL_TIMER);
#endif
    memset(&g_voip_cntx_p->call_redial_info, 0, sizeof(mmi_voip_call_redial_struct));
    g_voip_cntx_p->call_redial_info.maxAttempt = 3;
#ifndef __MMI_UCM__
    if (GetExitScrnID() == SCR_ID_VOIP_REDIALING_CALL)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);
    }
#endif /* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_answer_call
 * DESCRIPTION
 *  Answer incoming call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_answer_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 2)
    {
        StopTimer(VOIP_AUTOANSWER_TIMER);
    }

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_ANSWER,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    callId = mmi_voip_get_incoming_call_id();
    if (callId != -1)
    {
        /* release all gsm calls before answering voip call */
        if (GetTotalCallCount() != 0)
        {
            g_voip_cntx_p->call_list_info.needConn = MMI_VOIP_CALL_CONN_VOIP;
            mmi_voip_entry_ans_to_disconn_gsm();
        }
        else
        {
            mmi_voip_entry_ans_to_conn_voip();
        }
    }
    else
    {
        MMI_ASSERT(callId != -1);   /* incoming call does not exist */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_ans_to_conn_voip
 * DESCRIPTION
 *  Connect VoIP incoming call. Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_ans_to_conn_voip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mtcallId = 0, activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtcallId = mmi_voip_get_incoming_call_id();
    if (mtcallId != -1)
    {
        activecallId = mmi_voip_get_active_call_id();
        if (activecallId != -1)
        {
            mmi_voip_stop_incoming_tone();
            /* ringtone must take effect before critical session is started, otherwise it will be suspended */
            mmi_voip_switch_session(MMI_VOIP_ACTIVE_STATE);
            mmi_voip_hold_and_accept_req(activecallId, mtcallId);
        }
        else
        {
            mmi_voip_stop_incoming_tone();
            /* ringtone must take effect before critical session is started, otherwise it will be suspended */
            mmi_voip_switch_session(MMI_VOIP_ACTIVE_STATE);
            mmi_voip_accept_req(mtcallId);
        }
    }
    else
    {
        MMI_ASSERT(mtcallId != -1); /* incoming call does not exist */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_ans_to_disconn_voip
 * DESCRIPTION
 *  Disconnect VoIP incoming call. Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_ans_to_disconn_voip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_list_info.numTotal == 0)
    {
        /* do nothing */
    }
    else
    {
        /* END key is disable in processing screen because force release will execute automatically */
        mmi_voip_set_processing_parameter(
            STR_ID_VOIP_CALL_END,
            STR_ID_VOIP_PROCESSING,
            IMG_GLOBAL_PROGRESS,
            0,
            0,
            0,
            0,
            0,
            0);
        mmi_voip_entry_processing_screen();
        DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        mmi_voip_switch_rtp(TRUE, -1, -1);
        mmi_voip_stop_inbandtone();
        mmi_voip_stop_incoming_tone();
        mmi_voip_background_release_all_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_reject_call
 * DESCRIPTION
 *  Reject incoming call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_reject_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 2)
    {
        StopTimer(VOIP_AUTOANSWER_TIMER);
    }

    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_REJECT,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    callId = mmi_voip_get_incoming_call_id();
    if (callId != -1)
    {
        mmi_voip_stop_incoming_tone();
        mmi_voip_release_req(callId, 0);
        mmi_voip_force_release_req(callId, 0);
    }
    else
    {
        MMI_ASSERT(callId != -1);   /* incoming call does not exist */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_in_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_in_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_ACTIVE_STATE)
    {
        if (g_voip_cntx_p->call_list_info.numHeld < MMI_VOIP_MAX_HELD_CALL)
        {
            if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)
            {
                mmi_voip_entry_hold_single();
            }
            else if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 2)
            {
                mmi_voip_entry_hold_conference();
            }
            else
            {
                MMI_ASSERT(0); /* numDialog should be either 1 or 2 */
            }
        }
        else /* 3 held calls exist */
        {
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_HOLD), IMG_GLOBAL_UNFINISHED);
        }
    }
    else if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_HOLD_STATE)
    {
        if (mmi_voip_get_active_call_id() != -1)
        {
            mmi_voip_entry_swap();
        }
        else
        {
            if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)
            {
                mmi_voip_entry_retrieve_single();
            }
            else if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 2)
            {
                mmi_voip_entry_retrieve_conference();
            }
            else
            {
                MMI_ASSERT(0); /* numDialog should be either 1 or 2 */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_in_call_endkey
 * DESCRIPTION
 *  Handle END key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_in_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)  /* single call */
    {
        mmi_voip_entry_end_single();
    }
    else if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 2)     /* conference call */
    {
        mmi_voip_entry_end_conference();
    }
    else
    {
        /* end key is pressed in call editor without any active call existed */
        DisplayIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_sidekey
 * DESCRIPTION
 *  Handle side key for all VoIP call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_sidekey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(SetKeyPadVolUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(SetKeyPadVolDown, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_pre_send_dtmf
 * DESCRIPTION
 *  Determine to send DTMF or not based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pre_send_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callState = MMI_VOIP_IDLE_STATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_voip_cntx_p->call_misc_info.dispDtmf, 0, (MMI_VOIP_DTMF_LEN * ENCODING_LENGTH));
    memset(g_voip_cntx_p->call_misc_info.inputDtmf, 0, MMI_VOIP_DTMF_LEN);

    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callState = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState;

    if ((callState == MMI_VOIP_ACTIVE_STATE) && (g_voip_cntx_p->call_misc_info.isDtmf == TRUE))
    {
        mmi_voip_entry_dtmf_editor();
        mmi_voip_dtmf_key_down();
    }
    else
    {
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_UP);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_LONG_PRESS);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_hold_single
 * DESCRIPTION
 *  Entry function of call option\Hold Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_hold_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_HOLD_SINGLE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_hold_req(callId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_hold_conference
 * DESCRIPTION
 *  Entry function of call option\Hold Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_hold_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_HOLD_CONFERENCE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_hold_req(callId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_retrieve_single
 * DESCRIPTION
 *  Entry function of call option\Retrieve Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_retrieve_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_RETRIEVE_SINGLE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_retrieve_req(callId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_retrieve_conference
 * DESCRIPTION
 *  Entry function of call option\Retrieve Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_retrieve_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_RETRIEVE_CONFERENCE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_retrieve_req(callId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_swap
 * DESCRIPTION
 *  Entry function of call option\Swap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_swap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0, othercallId = 0, callState = MMI_VOIP_IDLE_STATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
    callState = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState;
    mmi_voip_get_held_call_list(FALSE);
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_SWAP,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);

    if ((callState == MMI_VOIP_ACTIVE_STATE) && (g_voip_cntx_p->call_list_info.numHeld > 1))
    {
        mmi_voip_entry_multi_held_call();
    }
    else
    {
        mmi_voip_entry_processing_screen();
        /* set all rtp directions as inactive before action */
        mmi_voip_switch_rtp(TRUE, -1, -1);
        if (callState == MMI_VOIP_ACTIVE_STATE) /* only one held call */
        {
            othercallId = g_voip_cntx_p->call_list_info.held_call_info[0].callId;
            mmi_voip_swap_req(callId, othercallId);
        }
        else if (callState == MMI_VOIP_HOLD_STATE)
        {
            othercallId = mmi_voip_get_active_call_id();
            mmi_voip_swap_req(othercallId, callId);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_conference
 * DESCRIPTION
 *  Entry function of call option\Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0, othercallId = 0, callState = MMI_VOIP_IDLE_STATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
    callState = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState;
    mmi_voip_get_held_call_list(TRUE);
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_CONFERENCE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);

    if ((callState == MMI_VOIP_ACTIVE_STATE) && (g_voip_cntx_p->call_list_info.numHeld > 1))
    {
        mmi_voip_entry_multi_held_call();
    }
    else
    {
        if (callState == MMI_VOIP_ACTIVE_STATE) /* only one single held call */
        {
            if (mmi_voip_is_codec_compatible(g_voip_cntx_p->call_list_info.held_call_info[0].codecList, TRUE))
            {
                mmi_voip_entry_processing_screen();
                /* set all rtp directions as inactive before action */
                mmi_voip_switch_rtp(TRUE, -1, -1);
                othercallId = g_voip_cntx_p->call_list_info.held_call_info[0].callId;
                mmi_voip_merge_req(callId, othercallId);
            }
            else
            {
                mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_CONFERENCE_FAIL), IMG_GLOBAL_UNFINISHED);
            }
        }
        else if (callState == MMI_VOIP_HOLD_STATE)
        {
            if (mmi_voip_is_codec_compatible(g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[0].sdp_info.codec, TRUE))
            {
                mmi_voip_entry_processing_screen();
                /* set all rtp directions as inactive before action */
                mmi_voip_switch_rtp(TRUE, -1, -1);
                othercallId = mmi_voip_get_active_call_id();
                mmi_voip_merge_req(othercallId, callId);
            }
            else
            {
                mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_CONFERENCE_FAIL), IMG_GLOBAL_UNFINISHED);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_split
 * DESCRIPTION
 *  Entry function of call option\Split
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_split(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, unhiliteIndex = 0, callId = 0, dialogId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
    unhiliteIndex = (g_voip_cntx_p->call_misc_info.currhiliteIndex == 0) ? (1) : (0);
    dialogId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[unhiliteIndex].dialogId;

    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_SPLIT,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_voip_entry_release_call);
    mmi_voip_entry_processing_screen();
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_split_req(callId, dialogId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_end_single
 * DESCRIPTION
 *  Entry function of call option\End Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_end_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, currhiliteIndex = 0, callId = 0, dialogId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
    currhiliteIndex = g_voip_cntx_p->call_misc_info.currhiliteIndex;
    dialogId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[currhiliteIndex].dialogId;

    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_END_SINGLE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(callId, dialogId);
    mmi_voip_force_release_req(callId, dialogId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_end_conference
 * DESCRIPTION
 *  Entry function of call option\End Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_end_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_END_CONFERENCE,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(callId, -1);
    mmi_voip_force_release_req(callId, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_end_all
 * DESCRIPTION
 *  Entry function of call option\End All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_end_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_END_ALL,
        STR_ID_VOIP_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(-1, -1);
    mmi_voip_force_release_req(-1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_release_call
 * DESCRIPTION
 *  Entry function of release call during other action processing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_release_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* END key is disable in processing screen because force release will execute automatically */
    mmi_voip_set_processing_parameter(
        STR_ID_VOIP_CALL_END,
        STR_GLOBAL_ABORTING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);
    mmi_voip_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
    mmi_voip_release_req(g_voip_cntx_p->call_list_info.processCId, g_voip_cntx_p->call_list_info.processDId);
    mmi_voip_force_release_req(g_voip_cntx_p->call_list_info.processCId, g_voip_cntx_p->call_list_info.processDId);
}


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
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_held_call_selected
 * DESCRIPTION
 *  Select the specific held call and get ready to process swap or conference action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_held_call_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callIndex = 0, callId = 0, othercallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
    callIndex = g_voip_cntx_p->call_misc_info.currhiliteIndex;
    othercallId = g_voip_cntx_p->call_list_info.held_call_info[callIndex].callId;

    if (g_voip_cntx_p->proc_scr_info.title_string == STR_ID_VOIP_SWAP)
    {
        mmi_voip_entry_processing_screen();
        /* set all rtp directions as inactive before action */
        mmi_voip_switch_rtp(TRUE, -1, -1);
        mmi_voip_swap_req(callId, othercallId);
    }
    else if (g_voip_cntx_p->proc_scr_info.title_string == STR_ID_VOIP_CONFERENCE)
    {
        if (mmi_voip_is_codec_compatible(g_voip_cntx_p->call_list_info.held_call_info[callIndex].codecList, TRUE))
        {
            mmi_voip_entry_processing_screen();
            /* set all rtp directions as inactive before action */
            mmi_voip_switch_rtp(TRUE, -1, -1);
            mmi_voip_merge_req(callId, othercallId);
        }
        else
        {
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_CONFERENCE_FAIL), IMG_GLOBAL_UNFINISHED);
            DeleteScreenIfPresent(SCR_ID_VOIP_MULTI_HELD_CALL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_transfer_call_determined
 * DESCRIPTION
 *  Determine transfer target's URI and get ready to process transfer action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_transfer_call_determined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *unicodeOwner = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 currhiliteTab = 0, callId = 0, dialogId = 0;
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_misc_info.dispUri))
    {
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN);
        mmi_voip_parse_uri(unicodeUri);
        memset(unicodeOwner, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*)unicodeOwner, 
            (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username, 
            VOIP_URI_LEN);
        if (mmi_voip_is_owner_number(unicodeUri, unicodeOwner) == TRUE)
        {
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_CANNOT_DIAL_OWNER), IMG_GLOBAL_UNFINISHED);
            DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION); /* go back to transfer screen */
        }
        else
        {
            if (mmi_voip_validate_uri(unicodeUri) == TRUE)
            {
                memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
                mmi_ucs2_n_to_asc(
                    (S8*)g_voip_cntx_p->call_misc_info.inputUri,
                    (S8*)unicodeUri,
                    (VOIP_URI_LEN * ENCODING_LENGTH));
                currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
                callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;
                dialogId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[0].dialogId;
                mmi_voip_set_processing_parameter(
                    STR_ID_VOIP_TRANSFER,
                    STR_ID_VOIP_PROCESSING,
                    IMG_GLOBAL_PROGRESS,
                    0,
                    0,
                    0,
                    0,
                    0,
                    mmi_voip_entry_release_call);
                mmi_voip_entry_processing_screen();
                /* set all rtp directions as inactive before action */
                mmi_voip_switch_rtp(TRUE, -1, -1);
                mmi_voip_transfer_req(callId, dialogId);
            }
            else
            {
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
                mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_INVALID_USERNAME), IMG_GLOBAL_UNFINISHED);
                DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION); /* go back to transfer screen */
            }
        }
    }
    else /* not allow to dial an empty number */
    {
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME), IMG_GLOBAL_UNFINISHED);
        DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION); /* go back to transfer screen */
    }
    OslMfree(unicodeUri);
    OslMfree(unicodeOwner);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_outgoing_call_id
 * DESCRIPTION
 *  Check if outgoing call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if outgoing call exists; -1 if outgoing call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_outgoing_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (MMI_VOIP_MAX_NUM_CALL - 1); i >= 0; i--)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_OUTGOING_STATE)
        {
            return g_voip_cntx_p->call_list_info.call_info[i].callId;
        }
    }
    if (i == -1)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_incoming_call_id
 * DESCRIPTION
 *  Check if incoming call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if incoming call exists; -1 if incoming call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_incoming_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (MMI_VOIP_MAX_NUM_CALL - 1); i >= 0; i--)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_INCOMING_STATE)
        {
            return g_voip_cntx_p->call_list_info.call_info[i].callId;
        }
    }
    if (i == -1)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_active_call_id
 * DESCRIPTION
 *  Check if active call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if active call exists; -1 if active call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_active_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numActive = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numActive = g_voip_cntx_p->call_list_info.numTotal - g_voip_cntx_p->call_list_info.numHeld;

    if (numActive == 0)
    {
        return -1;
    }
    else    /* numActive > 1 */
    {
        for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
        {
            if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE)
            {
                return g_voip_cntx_p->call_list_info.call_info[i].callId;
            }
        }
        if (i == MMI_VOIP_MAX_NUM_CALL)
        {
            return -1;  /* incoming call or outgoing call */
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_held_call_list
 * DESCRIPTION
 *  Check if held call exists and get its call id.
 *  If more than one held calls exist, put them all in the held call list.
 * PARAMETERS
 *  singlecallOnly      [IN]        Single held call or don't care
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_held_call_list(MMI_BOOL singlecallOnly)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset held call list */
    memset(&g_voip_cntx_p->call_list_info.held_call_info, 0, sizeof(mmi_voip_held_call_struct));
    for (i = 0; i < MMI_VOIP_MAX_HELD_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.held_call_info[i].callId = -1;
    }

    /* assign held call to held call list */
    if (g_voip_cntx_p->call_list_info.numHeld > 0)
    {
        for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
        {
            if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE)
            {
                callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
                if (singlecallOnly)
                {
                    if (g_voip_cntx_p->call_list_info.call_info[i].numDialog == 1)
                    {
                        g_voip_cntx_p->call_list_info.held_call_info[j].callId = callId;
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].dispName,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].dispName,
                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].remoteUri,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].remoteUri,
                            VOIP_URI_LEN);
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].codecList,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].sdp_info.codec,
                            VOIP_MAX_NUM_CODEC);
                        j++;
                    }
                }
                else
                {
                    g_voip_cntx_p->call_list_info.held_call_info[j].callId = callId;
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].dispName,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].dispName,
                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].remoteUri,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].remoteUri,
                        VOIP_URI_LEN);
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].codecList,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].sdp_info.codec,
                        VOIP_MAX_NUM_CODEC);
                    j++;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_index
 * DESCRIPTION
 *  Get call index based on the call id.
 * PARAMETERS
 *  callId      [IN]        Call id
 * RETURNS
 *  call index.
 *****************************************************************************/
S32 mmi_voip_get_call_index(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].callId == callId)
        {
            return i;
        }
    }
    if (i == MMI_VOIP_MAX_NUM_CALL)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_dialog_index
 * DESCRIPTION
 *  Get dialog index based on the dialog id.
 * PARAMETERS
 *  callIndex       [IN]        Call index
 *  dialogId        [IN]        Dialog id
 * RETURNS
 *  dialog index.
 *****************************************************************************/
S32 mmi_voip_get_dialog_index(S32 callIndex, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId == dialogId)
        {
            return i;
        }
    }
    if (i == VOIP_MAX_NUM_DIALOG)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_log_call_end_time
 * DESCRIPTION
 *  Put current time as end time and calculate call duration.
 * PARAMETERS
 *  callId          [IN]        Call id
 *  dialogId        [IN]        Dialog id
 *  duration        [IN]        Duration of the call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_log_call_end_time(S32 callId, S32 dialogId, MYTIME *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callIndex = mmi_voip_get_call_index(callId);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
        if (dialogIndex != -1)
        {
            DTGetRTCTime(&currTime);
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].endTime = currTime;
            /* overflow 2030/12/31/23:59:59 */
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear == 2030 && 
                currTime.nYear < g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear)
            {
                currTime.nYear = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear;
                currTime.nMonth = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nMonth;
                currTime.nDay = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nDay + 1;
            }
            GetTimeDifference(
                &currTime,
                &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime,
                duration);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_log_call_history
 * DESCRIPTION
 *  Log dialed call history entry when outgoing call is connected, local-aborted or remote-rejected.
 *  Log received call history entry when incoming call is accepted.
 *  Log missed call history entry when incoming call is local-rejected or remote-aborted.
 * PARAMETERS
 *  callId          [IN]        Call id
 *  dialogId        [IN]        Dialog id
 *  callOrigin      [IN]        Call origin, either MMI_VOIP_MO_ORIGIN or MMI_VOIP_MT_ORIGIN
 *  isConnect       [IN]        Call connect or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_log_call_history(S32 callId, S32 dialogId, mmi_voip_call_origin_enum callOrigin, MMI_BOOL isConnect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeAnony = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 callIndex = 0, dialogIndex = 0;
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset call log info */
    memset(&g_voip_cntx_p->call_log_info, 0, sizeof(mmi_voip_call_log_struct));

    /* it is possible that progressing_ind is not received yet, therefore, the outgoing call is not in the call list */
    PRINT_INFORMATION("\n[mmi_voip_log_call_history] Outgoing Call Id: %d, Connect or Not: %d\n", mmi_voip_get_outgoing_call_id(), isConnect);
    if ((callOrigin == MMI_VOIP_MO_ORIGIN) && (isConnect == FALSE) && (mmi_voip_get_outgoing_call_id() == -1))
    {
        memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*)g_voip_cntx_p->call_misc_info.dispUri,
            (S8*)g_voip_cntx_p->call_misc_info.inputUri,
            VOIP_URI_LEN);
        if (mmi_voip_get_outgoing_disp_name(
                MMI_VOIP_PHB|MMI_VOIP_HISTORY|MMI_VOIP_SOS, 
                g_voip_cntx_p->call_misc_info.dispUri, 
                (U8*)g_voip_cntx_p->call_log_info.dispName, 
                VOIP_DISP_NAME_LEN) == TRUE)
        {
            g_voip_cntx_p->call_log_info.dispDcs =
                (GetUCS2Flag((S8*)g_voip_cntx_p->call_log_info.dispName) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        }
        /* do not write anonymous uri to call log */
        memset(unicodeAnony, 0, VOIP_URI_LEN * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2((S8*)unicodeAnony, (S8*)g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
        mmi_voip_convert_uri_lower_case(unicodeAnony, unicodeAnony);
        if (!mmi_ucs2ncmp((S8*)unicodeAnony, (S8*)anonyUri, mmi_ucs2strlen((S8*)anonyUri)))
        {
            memset(g_voip_cntx_p->call_log_info.remoteUri, 0, VOIP_URI_LEN);
        }
        else
        {
            memcpy(g_voip_cntx_p->call_log_info.remoteUri, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
        }
        DTGetRTCTime(&currTime);
        g_voip_cntx_p->call_log_info.startTime = currTime;
        mmi_chist_log_voip_dialed_call(&g_voip_cntx_p->call_log_info);
    }
    else
    {
        if (callId != -1)
        {
            callIndex = mmi_voip_get_call_index(callId);
            if (dialogId != -1)
            {
                dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
                if (callOrigin == MMI_VOIP_MO_ORIGIN)
                {
                    PRINT_INFORMATION("\n[mmi_voip_log_call_history] Reset origin app Structure\n");
                    /* reset origin app structure */
                    memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
                    memcpy(
                        g_voip_cntx_p->call_log_info.dispName,
                        g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName,
                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                    /* do not write anonymous uri to call log */
                    memset(unicodeAnony, 0, VOIP_URI_LEN * ENCODING_LENGTH);
                    mmi_asc_n_to_ucs2((S8*)unicodeAnony, (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, VOIP_URI_LEN);
                    mmi_voip_convert_uri_lower_case(unicodeAnony, unicodeAnony);
                    if (!mmi_ucs2ncmp((S8*)unicodeAnony, (S8*)anonyUri, mmi_ucs2strlen((S8*)anonyUri)))
                    {
                        memset(g_voip_cntx_p->call_log_info.remoteUri, 0, VOIP_URI_LEN);
                    }
                    else
                    {
                        memcpy(
                            g_voip_cntx_p->call_log_info.remoteUri,
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
                            VOIP_URI_LEN);
                    }
                    g_voip_cntx_p->call_log_info.dispDcs =
                        (GetUCS2Flag((S8*)g_voip_cntx_p->call_log_info.dispName) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
                    if (isConnect == TRUE)
                    {
                        g_voip_cntx_p->call_log_info.startTime =
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime;                        
                        mmi_chist_log_voip_dialed_call(&g_voip_cntx_p->call_log_info);
                    }
                    else /* isConnect == FALSE */
                    {
                        DTGetRTCTime(&currTime);
                        g_voip_cntx_p->call_log_info.startTime = currTime;                        
                        mmi_chist_log_voip_dialed_call(&g_voip_cntx_p->call_log_info);
                    }
                }
                else if (callOrigin == MMI_VOIP_MT_ORIGIN)
                {
                    memcpy(
                        g_voip_cntx_p->call_log_info.dispName,
                        g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName,
                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                    /* do not write anonymous uri to call log */
                    memset(unicodeAnony, 0, VOIP_URI_LEN * ENCODING_LENGTH);
                    mmi_asc_n_to_ucs2((S8*)unicodeAnony, (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, VOIP_URI_LEN);
                    mmi_voip_convert_uri_lower_case(unicodeAnony, unicodeAnony);
                    if (!mmi_ucs2ncmp((S8*)unicodeAnony, (S8*)anonyUri, mmi_ucs2strlen((S8*)anonyUri)))
                    {
                        memset(g_voip_cntx_p->call_log_info.remoteUri, 0, VOIP_URI_LEN);
                    }
                    else
                    {
                        memcpy(
                            g_voip_cntx_p->call_log_info.remoteUri,
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
                            VOIP_URI_LEN);
                    }
                    g_voip_cntx_p->call_log_info.dispDcs =
                        (GetUCS2Flag((S8*)g_voip_cntx_p->call_log_info.dispName) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
                    if (isConnect == TRUE)
                    {
                        g_voip_cntx_p->call_log_info.startTime =
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime;                        
                        mmi_chist_log_voip_received_call(&g_voip_cntx_p->call_log_info);
                    }
                    else /* isConnect == FALSE */
                    {
                        DTGetRTCTime(&currTime);
                        g_voip_cntx_p->call_log_info.startTime = currTime;
                        mmi_chist_log_voip_missed_call(&g_voip_cntx_p->call_log_info);
                        SetMissedCallFlag(TRUE); /* display missed call screen in idle screen */
                    }
                }
                else
                {
                    MMI_ASSERT(0);  /* call origin should be either MMI_VOIP_MO_ORIGIN or MMI_VOIP_MT_ORIGIN */
                }
            }
            else
            {
                MMI_ASSERT(dialogId != -1);
            }
        }
        else
        {
            MMI_ASSERT(callId != -1);
        }
    }

    OslMfree(unicodeAnony);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_log_call_duration
 * DESCRIPTION
 *  Log call history duration when call is released.
 * PARAMETERS
 *  callId          [IN]        Call id
 *  dialogId        [IN]        Dialog id
 *  callOrigin      [IN]        Call origin, either MMI_VOIP_MO_ORIGIN or MMI_VOIP_MT_ORIGIN
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_log_call_duration(S32 callId, S32 dialogId, mmi_voip_call_origin_enum callOrigin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset call log info */
    memset(&g_voip_cntx_p->call_log_info, 0, sizeof(mmi_voip_call_log_struct));

    if (callId != -1)
    {
        callIndex = mmi_voip_get_call_index(callId);
        if (dialogId != -1)
        {
            dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
            if (callOrigin == MMI_VOIP_MO_ORIGIN)
            {
                memcpy(
                    g_voip_cntx_p->call_log_info.dispName,
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName,
                    (VOIP_DISP_NAME_LEN * sizeof(U16)));
                memcpy(
                    g_voip_cntx_p->call_log_info.remoteUri,
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
                    VOIP_URI_LEN);
                g_voip_cntx_p->call_log_info.dispDcs =
                    (GetUCS2Flag((S8*)g_voip_cntx_p->call_log_info.dispName) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
                g_voip_cntx_p->call_log_info.startTime =
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime;
                g_voip_cntx_p->call_log_info.endTime =
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].endTime;
                mmi_chist_log_voip_call_duration(&g_voip_cntx_p->call_log_info, PHB_LND);
            }
            else if (callOrigin == MMI_VOIP_MT_ORIGIN)
            {
                memcpy(
                    g_voip_cntx_p->call_log_info.dispName,
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName,
                    (VOIP_DISP_NAME_LEN * sizeof(U16)));
                memcpy(
                    g_voip_cntx_p->call_log_info.remoteUri,
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
                    VOIP_URI_LEN);
                g_voip_cntx_p->call_log_info.dispDcs =
                    (GetUCS2Flag((S8*)g_voip_cntx_p->call_log_info.dispName) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
                g_voip_cntx_p->call_log_info.startTime =
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime;
                g_voip_cntx_p->call_log_info.endTime =
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].endTime;
                mmi_chist_log_voip_call_duration(&g_voip_cntx_p->call_log_info, PHB_LNR);
            }
            else
            {
                MMI_ASSERT(0);  /* call origin should be either MMI_VOIP_MO_ORIGIN or MMI_VOIP_MT_ORIGIN */
            }
        }
        else
        {
            MMI_ASSERT(dialogId != -1);
        }
    }
    else
    {
        MMI_ASSERT(callId != -1);
    }
}
#endif /* __MMI_VOIP__ */

