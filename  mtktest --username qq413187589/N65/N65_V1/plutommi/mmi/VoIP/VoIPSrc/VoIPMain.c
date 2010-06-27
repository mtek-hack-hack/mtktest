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
 *  VoIPMain.c
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

#include "CallManagementGprot.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

extern U32 voip_custom_get_max_call_num(void);

mmi_voip_cntx_struct g_voip_cntx;
mmi_voip_cntx_struct *g_voip_cntx_p = &g_voip_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init
 * DESCRIPTION
 *  Initialize VoIP application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_init_context();
    mmi_voip_init_highlight_hdlr();
    mmi_voip_init_protocol_hdlr();
    
    PRINT_INFORMATION("\n[mmi_voip_init] 1st Auto Login\n");
    mmi_voip_entry_auto_login(); /* send request to voip cc in the background */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_deinit
 * DESCRIPTION
 *  Deinitialize VoIP application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        mmi_voip_deregister_req();
    }    
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_wlan_state_callback
 * DESCRIPTION
 *  Callback function of wlan state for VoIP auto login feature.
 * PARAMETERS
 *  state           [IN]            Wlan state, either DTCNT_BEARER_STATE_INACTIVE, 
 *                                  DTCNT_BEARER_STATE_INITIALIZED or DTCNT_BEARER_STATE_CONNECTED
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_wlan_state_callback(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((state == DTCNT_BEARER_STATE_CONNECTED) && 
        (g_voip_cntx_p->reg_state_info == MMI_VOIP_DEREG_STATE)) /* wlan is connected but voip is deregistered */
    {
        PRINT_INFORMATION("\n[mmi_voip_wlan_state_callback] WLAN Connected, VoIP Deregisterd\n");
        mmi_voip_entry_auto_login(); /* send request to voip cc in the background */
    }
}
#endif /* __MMI_WLAN_FEATURES__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_context
 * DESCRIPTION
 *  Initialize all global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_init_setting_context();
    mmi_voip_init_call_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_setting_context
 * DESCRIPTION
 *  Initialize setting related global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_setting_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;

    memset(&g_voip_cntx_p->prof_setting_info, 0, sizeof(mmi_voip_prof_setting_struct));
    g_voip_cntx_p->prof_setting_info.actprofIndex = -1;

    memset(&g_voip_cntx_p->call_setting_info, 0, sizeof(mmi_voip_call_setting_struct));
    g_voip_cntx_p->call_setting_info.numCodec = MMI_VOIP_MAX_CODEC_NUM;

    for (i = 0; i < MMI_VOIP_MAX_PROFILE_NUM; i++)
    {
        mmi_voip_load_profile(i);
    }
    mmi_voip_load_profile_active_index();

    mmi_voip_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_call_context
 * DESCRIPTION
 *  Initialize call related global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_call_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_voip_cntx_p->call_list_info, 0, sizeof(mmi_voip_call_list_struct));
    g_voip_cntx_p->call_list_info.maxnumCall = voip_custom_get_max_call_num();
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;
    g_voip_cntx_p->call_list_info.bkrejCId = -1;
    g_voip_cntx_p->call_list_info.bkrejDId = -1;
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.call_info[i].callId = -1;
        for (j = 0; j < VOIP_MAX_NUM_DIALOG; j++)
        {
            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId = -1;
            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].rtpHandle = -1;
        }
    }
    for (i = 0; i < MMI_VOIP_MAX_HELD_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.held_call_info[i].callId = -1;
    }

    memset(&g_voip_cntx_p->call_redial_info, 0, sizeof(mmi_voip_call_redial_struct));
    g_voip_cntx_p->call_redial_info.maxAttempt = 3;

    memset(&g_voip_cntx_p->dtmf_queue_info, 0, sizeof(mmi_voip_dtmf_queue_struct));
        
    memset(&g_voip_cntx_p->call_misc_info, 0, sizeof(mmi_voip_call_misc_struct));
    g_voip_cntx_p->call_misc_info.isDtmf = TRUE;

    memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    
    memset(&g_voip_cntx_p->call_log_info, 0, sizeof(mmi_voip_call_log_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_highlight_hdlr
 * DESCRIPTION
 *  Initialize all highlight handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_init_setting_highlight_hdlr();
    mmi_voip_init_setting_hint_hdlr();
    mmi_voip_init_call_highlight_hdlr();
    mmi_voip_init_call_hint_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_setting_highlight_hdlr
 * DESCRIPTION
 *  Initialize setting related highlight handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VOIP_MAIN, mmi_voip_highlight_main_menu);
    SetHiliteHandler(MENU_ID_VOIP_STATUS, mmi_voip_highlight_status);
    SetHiliteHandler(MENU_ID_VOIP_SUMMARY, mmi_voip_highlight_summary);
    SetHiliteHandler(MENU_ID_VOIP_PROF_SETTING, mmi_voip_highlight_prof_setting);
    SetHiliteHandler(MENU_ID_VOIP_PROF_SETTING_OPTION_ACTIVATE, mmi_voip_highlight_prof_setting_option_activate);
    SetHiliteHandler(MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT, mmi_voip_highlight_prof_setting_option_edit);
    SetHiliteHandler(MENU_ID_VOIP_PROF_EDIT_COMMON, mmi_voip_highlight_prof_edit_common);
    SetHiliteHandler(MENU_ID_VOIP_PROF_EDIT_ACCOUNT, mmi_voip_highlight_prof_edit_account);
    SetHiliteHandler(MENU_ID_VOIP_PROF_EDIT_OUTBOUND, mmi_voip_highlight_prof_edit_outbound);
    SetHiliteHandler(MENU_ID_VOIP_PROF_EDIT_REGISTER, mmi_voip_highlight_prof_edit_register);
    SetHiliteHandler(MENU_ID_VOIP_PROF_EDIT_NAT, mmi_voip_highlight_prof_edit_nat);
    SetHiliteHandler(MENU_ID_VOIP_FULL_EDITOR_DONE, mmi_voip_highlight_done);
    SetHiliteHandler(MENU_ID_VOIP_FULL_EDITOR_INPUT_METHOD, mmi_voip_highlight_input_method_in_menu);
    SetHiliteHandler(MENU_ID_VOIP_CALL_SETTING, mmi_voip_highlight_call_setting);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_AUTO_ANSWER, mmi_voip_highlight_auto_answer);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_AUTO_REJECT, mmi_voip_highlight_auto_reject);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_AUTO_REDIAL, mmi_voip_highlight_auto_redial);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_HIDE_CALLER_ID, mmi_voip_highlight_hide_caller_id);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_DTMF, mmi_voip_highlight_dtmf_in_menu);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_SECURE_RTP, mmi_voip_highlight_secure_rtp);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_COMFORT_NOISE, mmi_voip_highlight_comfort_noise);
    SetHiliteHandler(MENU_ID_VOIP_SETTING_SET_CODEC_ORDER, mmi_voip_highlight_set_codec_order);
    SetHiliteHandler(MENU_ID_VOIP_CALL_EDITOR, mmi_voip_highlight_new_call);
    SetHiliteHandler(MENU_ID_VOIP_CALL_EDITOR_DIAL, mmi_voip_highlight_dial);
    SetHiliteHandler(MENU_ID_VOIP_CALL_EDITOR_SAVE_PHONEBOOK, mmi_voip_highlight_save_phonebook);
    SetHiliteHandler(MENU_ID_VOIP_CALL_EDITOR_INPUT_METHOD, mmi_voip_highlight_input_method_in_call);
    SetHiliteHandler(MENU_ID_VOIP_CALL_EDITOR_SOS, mmi_voip_highlight_sos);
#ifdef SIP_CONFORMANCE_TEST
    SetHiliteHandler(MENU_ID_VOIP_OPTION_QUERY, mmi_voip_highlight_option_query);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_setting_hint_hdlr
 * DESCRIPTION
 *  Initialize setting related hint handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_setting_hint_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHintHandler(MENU_ID_VOIP_SETTING_AUTO_ANSWER, mmi_voip_hint_auto_answer);
    SetHintHandler(MENU_ID_VOIP_SETTING_AUTO_REJECT, mmi_voip_hint_auto_reject);
    SetHintHandler(MENU_ID_VOIP_SETTING_AUTO_REDIAL, mmi_voip_hint_auto_redial);
    SetHintHandler(MENU_ID_VOIP_SETTING_HIDE_CALLER_ID, mmi_voip_hint_hide_caller_id);
    SetHintHandler(MENU_ID_VOIP_SETTING_DTMF, mmi_voip_hint_dtmf_in_menu);
    SetHintHandler(MENU_ID_VOIP_SETTING_SECURE_RTP, mmi_voip_hint_secure_rtp);
    SetHintHandler(MENU_ID_VOIP_SETTING_COMFORT_NOISE, mmi_voip_hint_comfort_noise);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_call_highlight_hdlr
 * DESCRIPTION
 *  Initialize call related highlight handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_call_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VOIP_HOLD_SINGLE, mmi_voip_highlight_hold_single);
    SetHiliteHandler(MENU_ID_VOIP_HOLD_CONFERENCE, mmi_voip_highlight_hold_conference);
    SetHiliteHandler(MENU_ID_VOIP_RETRIEVE_SINGLE, mmi_voip_highlight_retrieve_single);
    SetHiliteHandler(MENU_ID_VOIP_RETRIEVE_CONFERENCE, mmi_voip_highlight_retrieve_conference);
    SetHiliteHandler(MENU_ID_VOIP_SWAP, mmi_voip_highlight_swap);
    SetHiliteHandler(MENU_ID_VOIP_CONFERENCE, mmi_voip_highlight_conference);
    SetHiliteHandler(MENU_ID_VOIP_SPLIT, mmi_voip_highlight_split);
    SetHiliteHandler(MENU_ID_VOIP_END_SINGLE, mmi_voip_highlight_end_single);
    SetHiliteHandler(MENU_ID_VOIP_END_CONFERENCE, mmi_voip_highlight_end_conference);
    SetHiliteHandler(MENU_ID_VOIP_END_ALL, mmi_voip_highlight_end_all);
    SetHiliteHandler(MENU_ID_VOIP_TRANSFER, mmi_voip_highlight_transfer);
    SetHiliteHandler(MENU_ID_VOIP_PHONEBOOK, mmi_voip_highlight_phonebook);
#ifdef __MMI_SOUND_RECORDER__
    SetHiliteHandler(MENU_ID_VOIP_SOUND_RECORDER, mmi_voip_highlight_sound_recorder);
#endif
    SetHiliteHandler(MENU_ID_VOIP_MUTE, mmi_voip_highlight_mute);
    SetHiliteHandler(MENU_ID_VOIP_DTMF, mmi_voip_highlight_dtmf_in_call);
    SetHiliteHandler(MENU_ID_VOIP_TRANSFER_OPTION, mmi_voip_highlight_transfer_option);
    SetHiliteHandler(MENU_ID_VOIP_TRANSFER_OPTION_DONE, mmi_voip_highlight_transfer_option_done);
    SetHiliteHandler(MENU_ID_VOIP_TRANSFER_OPTION_INPUT_METHOD, mmi_voip_highlight_input_method_in_call);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_call_hint_hdlr
 * DESCRIPTION
 *  Initialize call related hint handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_call_hint_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHintHandler(MENU_ID_VOIP_MUTE, mmi_voip_hint_mute);
    SetHintHandler(MENU_ID_VOIP_DTMF, mmi_voip_hint_dtmf_in_call);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_protocol_hdlr
 * DESCRIPTION
 *  Initialize all protocol handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_protocol_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_voip_register_rsp, MSG_ID_MMI_VOIP_REGISTER_RSP);
    SetProtocolEventHandler(mmi_voip_deregister_rsp, MSG_ID_MMI_VOIP_DEREGISTER_RSP);
    SetProtocolEventHandler(mmi_voip_deregister_ind, MSG_ID_MMI_VOIP_DEREGISTER_IND);
    SetProtocolEventHandler(mmi_voip_setting_rsp, MSG_ID_MMI_VOIP_SETTING_RSP);

    SetProtocolEventHandler(mmi_voip_progressing_ind, MSG_ID_MMI_VOIP_PROGRESSING_IND);
    SetProtocolEventHandler(mmi_voip_call_ring_ind, MSG_ID_MMI_VOIP_CALL_RING_IND);
    SetProtocolEventHandler(mmi_voip_call_end_ind, MSG_ID_MMI_VOIP_CALL_END_IND);
    SetProtocolEventHandler(mmi_voip_call_state_ind, MSG_ID_MMI_VOIP_CALL_STATE_IND);
    SetProtocolEventHandler(mmi_voip_call_replace_ind, MSG_ID_MMI_VOIP_CALL_REPLACE_IND);
    SetProtocolEventHandler(mmi_voip_call_replace_complete_ind, MSG_ID_MMI_VOIP_CALL_REPLACE_COMPLETE_IND);
    SetProtocolEventHandler(mmi_voip_background_reject_rsp, MSG_ID_MMI_VOIP_ACT_BK_REJ_RSP);
    SetProtocolEventHandler(mmi_voip_dispatch_call_act_rsp, MSG_ID_MMI_VOIP_CALL_ACT_RSP);

    SetProtocolEventHandler(mmi_voip_msg_waiting_ind, MSG_ID_MMI_VOIP_WAITING_MSG_IND);

    SetProtocolEventHandler(mmi_voip_at_call_ctrl_approve_ind, MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_profile
 * DESCRIPTION
 *  Load profile data with specific index from NVRAM to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index].
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to load profile
 * RETURNS
 *  TRUE means load success; FALSE means load fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_load_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((profIndex < 0) || (profIndex >= MMI_VOIP_MAX_PROFILE_NUM))
    {
        return FALSE;
    }

    result = ReadRecord(
                NVRAM_EF_VOIP_PROF_LID,
                (U16) (profIndex + 1),
                g_voip_cntx_p->prof_setting_info.saved_prof + profIndex,
                sizeof(mmi_voip_prof_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_profile
 * DESCRIPTION
 *  Save g_voip_cntx_p->prof_setting_info.saved_prof[index] to NVRAM
 *  with profile data with specific index.
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to save profile
 * RETURNS
 *  TRUE means save success; FALSE means save fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_save_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((profIndex < 0) || (profIndex >= MMI_VOIP_MAX_PROFILE_NUM))
    {
        return FALSE;
    }

    result = WriteRecord(
                NVRAM_EF_VOIP_PROF_LID,
                (U16) (profIndex + 1),
                g_voip_cntx_p->prof_setting_info.saved_prof + profIndex,
                sizeof(mmi_voip_prof_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_profile_active_index
 * DESCRIPTION
 *  Load activate profile index from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_load_profile_active_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);

    if (data == 0xFF)
    {
        data = 0;
        WriteValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);
        g_voip_cntx_p->prof_setting_info.actprofIndex = -1;
    }
    else
    {
        g_voip_cntx_p->prof_setting_info.actprofIndex = data - 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_profile_active_index
 * DESCRIPTION
 *  Save activate profile index to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_save_profile_active_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = g_voip_cntx_p->prof_setting_info.actprofIndex + 1;
    WriteValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_setting
 * DESCRIPTION
 *  Load call setting data from NVRAM to
 *  g_voip_cntx_p->call_setting_info.saved_setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means load success; FALSE means load fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ReadRecord(
                NVRAM_EF_VOIP_SETTING_LID,
                1,
                &g_voip_cntx_p->call_setting_info.saved_setting,
                sizeof(mmi_voip_setting_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    /* check if codec order string empty */
    for (i = 0; i < MMI_VOIP_MAX_CODEC_NUM; i++)
    {
        if (!strlen((S8*)g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i]))
        {
            mmi_ucs2_to_asc(
                (S8*)g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i], 
                (S8*)GetString(STR_ID_VOIP_SETTING_CODEC2 + i));
            MMI_ASSERT(g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i][MMI_VOIP_MAX_CODEC_NAME_LEN - 1] == '\0');
        }
    }
    /* set g_voip_cntx_p->call_setting_info.codecEnum */
    mmi_voip_update_setting_codec_cache_to_disp();
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_setting
 * DESCRIPTION
 *  Save g_voip_cntx_p->call_setting_info.saved_setting to NVRAM
 *  with call setting data.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means save success; FALSE means save fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = WriteRecord(
                NVRAM_EF_VOIP_SETTING_LID,
                1,
                &g_voip_cntx_p->call_setting_info.saved_setting,
                sizeof(mmi_voip_setting_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    return TRUE;
}
#endif /* __MMI_VOIP__ */

