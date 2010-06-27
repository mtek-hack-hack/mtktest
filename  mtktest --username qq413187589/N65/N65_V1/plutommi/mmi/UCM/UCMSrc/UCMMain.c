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
 *  UCMMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template source file
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "SettingGProts.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#ifdef __MMI_BT_HP_SUPPORT__
#include "BTMMIHPGprots.h"
#endif
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"
#include "CallsGProts.h"
#include "DateTimeGprot.h"
#include "NetworkSetupDefs.h"
#include "PhoneBookGprot.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"
#include "VoIPGProt.h"
#include "SSCStringHandle.h"
#include "GSM7BitDefaultAlphabet.h"
#include "app_usedetails.h"

#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_custom_hw.h"
#include "MTPNP_PFAL_Master_CallHistory.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

mmi_ucm_cntx_struct g_mmi_ucm_cntx;
mmi_ucm_cntx_struct *g_ucm_p = &g_mmi_ucm_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_context();
    mmi_ucm_init_highlight_handler();
    mmi_ucm_init_hint_handler();
    mmi_ucm_init_protocol_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_context
 * DESCRIPTION
 *  Initialize UCM context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_list, 0, sizeof(mmi_ucm_call_list_struct));
    for (i = 0; i < MMI_UCM_MAX_NUM_TAB; i++)
    {
        mmi_ucm_reset_group_entry(i);
    }
    
    memset(&g_ucm_p->call_misc, 0, sizeof(mmi_ucm_call_misc_struct));
    mmi_ucm_reset_index_list();
    g_ucm_p->call_misc.is_dtmf = TRUE;
    g_ucm_p->call_misc.nw_service_status = (MMI_UCM_SIM1_ACTIVE | MMI_UCM_SIM2_ACTIVE);

#ifdef __MMI_BG_SOUND_EFFECT__    
    g_ucm_p->call_misc.is_bgs_selected = FALSE;
#endif /* __MMI_BG_SOUND_EFFECT__ */

    memset(&g_ucm_p->mo_info, 0, sizeof(mmi_ucm_dial_info_struct));

    memset(&g_ucm_p->mo_mt_display, 0, sizeof(mmi_ucm_ring_info_struct));

    memset(&g_ucm_p->proc_scr, 0, sizeof(mmi_ucm_proc_scr_struct));

    memset(&g_ucm_p->cnf_scr, 0, sizeof(mmi_ucm_display_cnf_struct));

    memset(&g_ucm_p->call_end, 0, sizeof(mmi_ucm_call_end_struct));

    memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));

    memset(&g_ucm_p->call_cost, 0, sizeof(mmi_ucm_call_cost_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_protocol_handler
 * DESCRIPTION
 *  Initialize UCM protocol handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_protocol_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetProtocolEventHandler(mmi_ucm_master_at_req_ind, MSG_ID_MMI_UCM_AT_REQ_IND);
    SetProtocolEventHandler(mmi_ucm_master_service_ind_hdlr, MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetSlaveProtocolEventHandler(mmi_ucm_slave_service_ind_hdlr, MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND);
    SetSlaveProtocolEventHandler(mmi_ucm_slave_at_req_ind, MSG_ID_MMI_UCM_AT_REQ_IND);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_reset_group_entry
 * DESCRIPTION
 *  Reset group entry.
 * PARAMETERS
 *  group_index     [IN]            Group index that is going to be reset
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_reset_group_entry(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_list.group_info[group_index], 0, sizeof(mmi_ucm_group_entry_struct));
    g_ucm_p->call_list.group_info[group_index].group_id = -1;
    for (i = 0; i < MMI_UCM_MAX_NUM_INDEX; i++)
    {
        mmi_ucm_reset_call_entry(group_index, i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_reset_call_entry
 * DESCRIPTION
 *  Reset call entry.
 * PARAMETERS
 *  group_index     [IN]            Group index that is going to be reset 
 *  call_index      [IN]            Call index that is going to be reset
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_reset_call_entry(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_list.group_info[group_index].call_info[call_index], 0, sizeof(mmi_ucm_call_entry_struct));
    g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_id = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_reset_index_list
 * DESCRIPTION
 *  Reset index list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_reset_index_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_misc.index_list, -1, (MMI_UCM_MAX_NUM_TAB * MMI_UCM_MAX_NUM_INDEX * sizeof(mmi_ucm_index_info_struct)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_sendkey
 * DESCRIPTION
 *  Handle SEND key when dialing an outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_outgoing_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_make_call = MMI_FALSE;
    U8 tone_id = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_SIMCARD_USABLE_SIDE status = MTPNP_AD_Get_UsableSide();
    E_MTPNP_AD_STATUS dual_sim_setting = MTPNP_AD_Get_Status();
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__)
    mmi_ucm_set_call_channel(g_ucm_p->mo_info.dial_type);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    tone_id = mmi_ucm_get_error_tone();
    
    if (mmi_bootup_get_active_flight_mode())
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            tone_id);
    }
#ifdef __MMI_WLAN_FEATURES__
    else if ((mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY) && (g_ucm_p->mo_info.dial_type != MMI_UCM_VOIP_CALL_TYPE))
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            tone_id);
    }
#endif /* __MMI_WLAN_FEATURES__ */

    else if (mmi_ucm_is_pending_action() == MMI_TRUE)
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            tone_id);        
    }
    else if (mmi_ucm_is_crss(g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.dial_num.num_uri) == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] CRSS Action Done\n");
    }
    else if (mmi_ucm_is_sos_number(g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.dial_num.num_uri) == TRUE)
    {
        if (mmi_ucm_is_sos_in_call_list() == FALSE)
        {
            mmi_ucm_nw_status_enum nw_status = mmi_ucm_get_nw_service_status();

            /* treat video call emergency call as voice emergency call, the same as reference phone behavior */
            if (g_ucm_p->mo_info.dial_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                g_ucm_p->mo_info.dial_type = MMI_UCM_VOICE_CALL_TYPE;
            }

        #ifdef __MMI_DUAL_SIM_MASTER__
            if (g_ucm_p->mo_info.dial_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                if (((nw_status & MMI_UCM_SIM2_ACTIVE) == 0) &&
                    (nw_status & MMI_UCM_SIM1_ACTIVE) &&
                    (dual_sim_setting == MTPNP_AD_DUALCARD) &&
                    (mmi_ucm_is_sos_number(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->mo_info.dial_num.num_uri) == TRUE))
                {
                    g_ucm_p->mo_info.dial_type = MMI_UCM_VOICE_CALL_TYPE;
                    mmi_ucm_set_call_channel(g_ucm_p->mo_info.dial_type);
                    PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] Change dial type to SIM1 for SOS call\n");
                }
            }
            else if (g_ucm_p->mo_info.dial_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                if (((nw_status & MMI_UCM_SIM1_ACTIVE) == 0) &&
                    (nw_status & MMI_UCM_SIM2_ACTIVE) &&
                    (dual_sim_setting == MTPNP_AD_DUALCARD) &&
                    (mmi_ucm_is_sos_number(MMI_UCM_VOICE_CALL_TYPE_SIM2, g_ucm_p->mo_info.dial_num.num_uri) == TRUE))
                {
                    g_ucm_p->mo_info.dial_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;
                    mmi_ucm_set_call_channel(g_ucm_p->mo_info.dial_type);
                    PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] Change dial type to SIM2 for SOS call\n");
                }
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
		
            if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) != 0)
            {
                PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] End All Calls before Dial SOS\n");
                g_ucm_p->mo_info.is_wait_dial = TRUE;
                mmi_ucm_end_all_action();
            }
            else
            {            
                PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] Directly Dial SOS\n");
                g_ucm_p->mo_info.is_wait_dial = TRUE;
                mmi_ucm_dial_action();
            }
            
            is_make_call = MMI_TRUE;
        }
        else /* not allow to dial this sos number */
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }
    }
    else /* not a sos number */
    {
        if (!strlen((S8*)g_ucm_p->mo_info.dial_num.num_uri)) /* empty number */
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NO_NUMBER_TO_DIAL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }
        else if (mmi_ucm_emergency_call_present())
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }
    #ifndef __MMI_DUAL_SIM_MASTER__
        else if ((!mmi_bootup_is_sim_valid()) && 
                 (g_ucm_p->mo_info.dial_type != MMI_UCM_VOIP_CALL_TYPE))
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_SOS_NUMBER),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }                 
    #else /* __MMI_DUAL_SIM_MASTER__ */
        else if ((g_ucm_p->mo_info.dial_type != MMI_UCM_VOIP_CALL_TYPE) && 
                 !(g_ucm_p->mo_info.dial_type & MMI_UCM_SIM2_CALL_TYPE_ALL) &&
                 (status != MTPNP_AD_SIMCARD1_USABLE) &&
                 (status != MTPNP_AD_DUALSIM_USABLE))
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_SOS_NUMBER),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }                 
        else if ((g_ucm_p->mo_info.dial_type & MMI_UCM_SIM2_CALL_TYPE_ALL) &&
                 (status != MTPNP_AD_SIMCARD2_USABLE) &&
                 (status != MTPNP_AD_DUALSIM_USABLE))
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_SOS_NUMBER),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        else if ((mmi_ucm_is_busy() == FALSE) && (mmi_ucm_dial_option() == TRUE))
        {            
            if ((g_ucm_p->mo_info.dial_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (SS_OPERATION == applib_ss_string_parsing((U8*)g_ucm_p->mo_info.dial_num.num_uri, (U8)strlen((S8*)g_ucm_p->mo_info.dial_num.num_uri))))
            {
                /* dial directly if SS operation or SIM operation */
                mmi_ucm_dial_action();
            }
            else if ((mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_DATA_CSD) && (g_ucm_p->mo_info.dial_type & (MMI_UCM_CALL_TYPE_DATA_CSD_ALL))) || 
                     (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_DATA_CSD_ALL) && (g_ucm_p->mo_info.dial_type & MMI_UCM_CALL_TYPE_NO_DATA_CSD)))
            {
                /* normal call and data call cannot co-exist */
                PRINT_INFORMATION("\n[mmi_ucm_outgoing_call_sendkey] End All Calls before Dial %d\n", g_ucm_p->mo_info.dial_type);
                g_ucm_p->mo_info.is_wait_dial = TRUE;
                mmi_ucm_end_all_action();
            }
            else if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
            {
                mmi_ucm_hold_and_dial_action();
            }
            else
            {
                mmi_ucm_dial_action();
            }
            
            is_make_call = MMI_TRUE;
        }
        else
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_DIAL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }
    }
    
    if (is_make_call == MMI_FALSE)
    {
        mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* reset dial from phonebook flag */
        CHISTSetDialFromCallLogFlag(0);                 /* reset dial from call history flag */
        
    #ifdef __IP_NUMBER__
        if (g_ucm_p->mo_info.dial_type & (MMI_UCM_VOICE_CALL_TYPE_ALL))
        {
            SetTempUseIPNumber(MMI_FALSE);    /* reset IP dial flag from gsm voice calls */
        }
    #endif /* __IP_NUMBER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_endkey
 * DESCRIPTION
 *  Handle END key in the outgoing call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_outgoing_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_inband_tone();
    
    MMI_ASSERT(mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    mmi_ucm_end_single_action_with_index(groupIndex, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ANSWERING_MODE ansMode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: abort outgoing call first
    mmi_ucm_stop_incoming_tone();
    memcpy(&ansMode, GetAnsweringMode(), sizeof(MMI_ANSWERING_MODE));
    if (ansMode.automatic == TRUE)
    {
        StopTimer(UCM_AUTO_ANSWER_TIMER);
    }
    
    if (mmi_ucm_answer_option() == TRUE)
    {
        if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
            (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
            (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0))
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_ACCEPT),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
        }
        else if ((mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_DATA_CSD)) && (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_DATA_CSD_ALL)))
        {
            /* normal call and data call cannot co-exist */
            mmi_ucm_end_all_and_accept_action();
        }
    #ifdef __CTM_SUPPORT__   
        else if(mmi_gsm_ctm_is_connected() == TRUE)
        {
            /* drop ctm call before answering the waiting call*/
            mmi_ucm_end_active_and_accept_action();
        }
    #endif /* __CTM_SUPPORT__ */
        else if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
        {
            mmi_ucm_hold_and_accept_action();
        }
        else
        {
            mmi_ucm_accept_action();
        }
    }
    else
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_ACCEPT),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE_IN_CALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_endkey
 * DESCRIPTION
 *  Handle END key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ANSWERING_MODE ansMode;
    S32 groupIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_incoming_tone();
    memcpy(&ansMode, GetAnsweringMode(), sizeof(MMI_ANSWERING_MODE));
    if (ansMode.automatic == TRUE)
    {
        StopTimer(UCM_AUTO_ANSWER_TIMER);
    }

    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
    {
        mmi_ucm_end_single_action_with_index(groupIndex, 0);
    }
    else /* the auto reject call is in the call list */
    {
        mmi_ucm_set_processing_parameter(
            STR_ID_UCM_END_CALL,
            STR_ID_UCM_PROCESSING,
            IMG_GLOBAL_PROGRESS,
            0,
            0,
            0,
            0,
            0,
            mmi_ucm_force_release_action);
    
        mmi_ucm_entry_processing_screen();
        
        /* auto reject */
        mmi_ucm_auto_reject_action_with_index(groupIndex, 0);

        DeleteScreenIfPresent(SCR_ID_UCM_PROCESSING);

        /* set to general process screen */
        mmi_ucm_set_processing_parameter(
            STR_ID_UCM_PROCESSING,
            STR_ID_UCM_PROCESSING,
            IMG_GLOBAL_PROGRESS,
            0,
            0,
            0,
            0,
            0,
            mmi_ucm_force_release_action);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_show_option
 * DESCRIPTION
 *  Check if incoming call option can be displayed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means incoming call option should show;
 *  FALSE means incoming call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_incoming_call_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucm_emergency_call_present() == TRUE) || 
        (mmi_bootup_is_in_power_on_period() == MMI_TRUE) ||
        (mmi_bootup_is_in_security_check() == MMI_TRUE) ||
        (mmi_secset_is_in_puk_check() == MMI_TRUE) ||
    #ifdef __MMI_DUAL_SIM_MASTER__
        (mmi_bootup_is_in_sim2_security_check() == MMI_TRUE) ||
        (mmi_secset_is_in_sim2_puk_check() == MMI_TRUE) ||
    #endif /* #ifdef __MMI_DUAL_SIM_MASTER__ */
        MMI_FALSE
        )
    {
        return FALSE;
    }
    else if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
            (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
            (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0))
    {
        return FALSE;
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
    {
        if (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1)
        {
            mmi_ucm_swap_action();
        }
        else if ((mmi_ucm_hold_single_option() == TRUE) || (mmi_ucm_hold_conference_option() == TRUE))
        {
            mmi_ucm_hold_action();
        }
        else /* 3 held calls exist */
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_HOLD),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
        }
    }
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
    {
        if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) /* active call exists */
        {
            if (mmi_ucm_swap_option() == TRUE) 
            {
                mmi_ucm_swap_action();
            }
            else
            {
                DisplayPopup(
                    (U8*)GetString(STR_ID_UCM_NOT_ALLOW_TO_SWAP),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE_IN_CALL);
            }
        }
        else /* no active call exists */
        {
            mmi_ucm_retrieve_action();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_endkey
 * DESCRIPTION
 *  Handle END key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].num_call == 1)
    {
        mmi_ucm_end_single_action();
    }
    else if (mmi_ucm_end_conference_option() == TRUE)
    {
        mmi_ucm_end_conference_action();
    }
    else
    {
        /* end key is pressed in call editor without any active call existed */
        DisplayIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_show_option
 * DESCRIPTION
 *  Check if in call option can be displayed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means in call option should show;
 *  FALSE means in call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_in_call_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucm_emergency_call_present() == TRUE) || 
        (mmi_bootup_is_in_power_on_period() == MMI_TRUE) ||
        (mmi_bootup_is_in_security_check() == MMI_TRUE) ||
        (mmi_secset_is_in_puk_check() == MMI_TRUE) ||
    #ifdef __MMI_DUAL_SIM_MASTER__
        (mmi_bootup_is_in_sim2_security_check() == MMI_TRUE) ||
        (mmi_secset_is_in_sim2_puk_check() == MMI_TRUE) ||
    #endif /* #ifdef __MMI_DUAL_SIM_MASTER__ */
        MMI_FALSE)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option
 * DESCRIPTION
 *  Check if dial option can be displayed in the outgoing call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means dial option should show;
 *  FALSE means dial option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_dial_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
        (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_HELD_TAB))
    {
        PRINT_INFORMATION("\n[mmi_ucm_dial_option] Exceed Call Boundary\n");
        return FALSE;
    }
    else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
             (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) != 0))
    {
        PRINT_INFORMATION("\n[mmi_ucm_dial_option] Voice Call State Not Allow\n");
        return FALSE;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
             (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) != 0))
    {
        PRINT_INFORMATION("\n[mmi_ucm_dial_option] Voice Call State Not Allow\n");
        return FALSE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else if (mmi_ucm_emergency_call_present() == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_dial_option] Emergency Call Exists\n");
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_answer_option
 * DESCRIPTION
 *  Check if answer option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means answer option should show;
 *  FALSE means answer option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_answer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
        (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_HELD_TAB))
    {
        PRINT_INFORMATION("\n[mmi_ucm_answer_option] Exceed Call Boundary\n");
        return FALSE;
    }
    else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
             (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) != 0))
    {
        PRINT_INFORMATION("\n[mmi_ucm_answer_option] Voice Call State Not Allow\n");
        return FALSE;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
             (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) != 0))
    {
        PRINT_INFORMATION("\n[mmi_ucm_answer_option] Voice Call State Not Allow\n");
        return FALSE;
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    else if (mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_NO_DATA_CSD) == 0)
    {
        PRINT_INFORMATION("\n[mmi_ucm_answer_option] MT call type cannot be answered\n");
        return FALSE;        
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_option
 * DESCRIPTION
 *  Check if deflect option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means deflect option should show;
 *  FALSE means deflect option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_deflect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numIncoming = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
    if (numIncoming == 1)
    {
        return TRUE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_deflect_option] Not Incoming Voice Call\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_replace_option
 * DESCRIPTION
 *  Check if replace option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means replace option should show;
 *  FALSE means replace option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_replace_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numIncoming = 0;
    S32 numActive = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, g_ucm_p->call_misc.index_list);
    numActive = mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, g_ucm_p->call_misc.index_list);
    
    if (numIncoming == 1 && numActive == 1)
    {
        return TRUE;
    }
    
    return FALSE;
}


#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__    
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_redial_from_other_sim_option
 * DESCRIPTION
 *  Check if redial from other sim option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means replace option should show;
 *  FALSE means replace option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_redial_from_other_sim_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numIncoming = 0;
    S32 numTotal = 0;
    S32 groupIndex = 0;
    mmi_ucm_call_type_enum call_type = MMI_UCM_VOICE_CALL_TYPE;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_NO_CSD, g_ucm_p->call_misc.index_list);
    numTotal = mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD);
    
    if (numIncoming == 1 && numTotal == 1)
    {
        groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
        call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;

        if (call_type == MMI_UCM_VOICE_CALL_TYPE && !MTPNP_PFAL_Is_Card2Absent()) /* tony : to-do wait for Diamond's API */
        {
            return TRUE;
        }
        else if (call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2 && mmi_bootup_is_sim_valid())
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }    
    return FALSE;
}
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_active_option
 * DESCRIPTION
 *  Check if end all active calls option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the option should show;
 *  FALSE means the option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_all_active_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }    
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_held_option
 * DESCRIPTION
 *  Check if end all held calls option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the option should show;
 *  FALSE means the option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_all_held_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }    
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_sound_incoming_option
 * DESCRIPTION
 *  Check if background sound option can be displayed in the incoming call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means deflect option should show;
 *  FALSE means deflect option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_bk_sound_incoming_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numIncoming = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, g_ucm_p->call_misc.index_list);
#ifdef __MMI_BG_SOUND_EFFECT__
    if ((numIncoming == 1) && (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_DATA_CSD) == 1))
    {
        return TRUE;
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */
    PRINT_INFORMATION("\n[mmi_ucm_bk_sound_incoming_option] Other Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_single_option
 * DESCRIPTION
 *  Check if hold single option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means hold single option should show;
 *  FALSE means hold single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_hold_single_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_hold_single_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_single_check
 * DESCRIPTION
 *  Check if hold single option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means hold single option should show;
 *  FALSE means hold single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_hold_single_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_hold_single_check] No Hold Single for Data Call\n");
        return FALSE;
    }
    else if (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) < MMI_UCM_MAX_HELD_TAB)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].num_call == 1) && 
            (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE))
        {
            if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)
            {
                if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 0)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_hold_single_option] Voice Held Call Exists\n");
                return FALSE;
            }
    #ifdef __MMI_DUAL_SIM_MASTER__
            else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)
            {
                if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 0)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_hold_single_option] Card2 Voice Held Call Exists\n");
                return FALSE;
            }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_hold_single_option] Not Single Active Call\n");
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_hold_single_option] Held Call Boundary Exceeds\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_conference_option
 * DESCRIPTION
 *  Check if hold conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means hold conference option should show;
 *  FALSE means hold conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_hold_conference_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_hold_conference_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_conference_check
 * DESCRIPTION
 *  Check if hold conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means hold conference option should show;
 *  FALSE means hold conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_hold_conference_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_hold_conference_check] No Hold Conference for Data Call\n");
        return FALSE;
    }
    else if (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) < MMI_UCM_MAX_HELD_TAB)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].num_call >= 2) && 
            (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE))
        {
            if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)
            {
                if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 0)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_hold_conference_option] Voice Held Call Exists\n");
                return FALSE;
            }
    #ifdef __MMI_DUAL_SIM_MASTER__
            else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)
            {
                if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 0)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_hold_conference_option] Card2 Voice Held Call Exists\n");
                return FALSE;
            }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_hold_conference_option] Not Active Conference Call\n");
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_hold_conference_option] Held Call Boundary Exceeds\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_single_option
 * DESCRIPTION
 *  Check if retrieve single option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means retrieve single option should show;
 *  FALSE means retrieve single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_retrieve_single_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_retrieve_single_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_single_check
 * DESCRIPTION
 *  Check if retrieve single option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means retrieve single option should show;
 *  FALSE means retrieve single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_retrieve_single_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_retrieve_single_check] No Retrieve Single for Data Call\n");
        return FALSE;
    }
    else if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) == 0)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].num_call == 1) && 
            (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE))
        {
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_retrieve_single_option] Not Single Held Call\n");
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_retrieve_single_option] Active Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_conference_option
 * DESCRIPTION
 *  Check if retrieve conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means retrieve single option should show;
 *  FALSE means retrieve single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_retrieve_conference_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_retrieve_conference_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_conference_check
 * DESCRIPTION
 *  Check if retrieve conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means retrieve single option should show;
 *  FALSE means retrieve single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_retrieve_conference_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_retrieve_conference_check] No Retrieve Conference for Data Call\n");
        return FALSE;
    }
    else if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) == 0)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].num_call >= 2) && 
            (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE))
        {
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_retrieve_conference_option] Not Held Conference Call\n");
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_retrieve_conference_option] Active Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_option
 * DESCRIPTION
 *  Check if swap option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means swap option should show;
 *  FALSE means swap option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_swap_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_swap_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_check
 * DESCRIPTION
 *  Check if swap option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means swap option should show;
 *  FALSE means swap option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_swap_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_swap_option] Data Call Cannot Swap\n");
        return FALSE;
    }
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
    {  
        if (mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) != 0)
        {
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_swap_option] No Held Call Exists\n");
        return FALSE;
    }
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
    {
        if (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_NO_DATA_CSD, FALSE, g_ucm_p->call_misc.index_list) != 0)
        {
            if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) != 0) && 
                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) != 0)) /* 1A1H in voice call, cannot allow to swap in different call type */
            {
                if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE) /* highlight held call is one of the 1A1H in voice call */
                {
                    return TRUE;
                }
                return FALSE;
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) != 0) && 
                     (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) != 0)) /* 1A1H in voice call, cannot allow to swap in different call type */
            {
                if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2) /* highlight held call is one of the 1A1H in voice call */
                {
                    return TRUE;
                }
                return FALSE;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_swap_option] No Active Call Exists\n");
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_swap_option] Neither Active Call Nor Held Call\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_option
 * DESCRIPTION
 *  Check if conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means conference option should show;
 *  FALSE means conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_conference_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_conference_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_check
 * DESCRIPTION
 *  Check if conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means conference option should show;
 *  FALSE means conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_conference_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numCall = 0, groupIndex = 0, hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE) && 
            (g_ucm_p->call_list.group_info[hiliteTab].num_call < MMI_UCM_MAX_NUM_INDEX))
        {
            numCall = mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list);
            if(numCall != 0)
            {
                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                if (g_ucm_p->call_list.group_info[groupIndex].num_call < MMI_UCM_MAX_NUM_INDEX)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_conference_option] Held Call Number Exceeds\n");
                return FALSE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No Voice Held Call Exists\n");
            return FALSE;
        }        
        else if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE) && 
                (g_ucm_p->call_list.group_info[hiliteTab].num_call < MMI_UCM_MAX_NUM_INDEX))
        {
            numCall = mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list);
            if (numCall != 0)
            {
                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                if (g_ucm_p->call_list.group_info[groupIndex].num_call < MMI_UCM_MAX_NUM_INDEX)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_conference_option] Active Call Number Exceeds\n");
                return FALSE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No Voice Active Call Exists\n");
            return FALSE;
        }
        return FALSE;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE) && 
            (g_ucm_p->call_list.group_info[hiliteTab].num_call < MMI_UCM_MAX_NUM_INDEX))
        {
            numCall = mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list);
            if(numCall != 0)
            {
                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                if (g_ucm_p->call_list.group_info[groupIndex].num_call < MMI_UCM_MAX_NUM_INDEX)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_conference_option] Held Call Number Exceeds\n");
                return FALSE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No Voice Held Call Exists\n");
            return FALSE;
        }        
        else if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE) && 
                (g_ucm_p->call_list.group_info[hiliteTab].num_call < MMI_UCM_MAX_NUM_INDEX))
        {
            numCall = mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list);
            if (numCall != 0)
            {
                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                if (g_ucm_p->call_list.group_info[groupIndex].num_call < MMI_UCM_MAX_NUM_INDEX)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_conference_option] Active Call Number Exceeds\n");
                return FALSE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No Voice Active Call Exists\n");
            return FALSE;
        }
        return FALSE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOIP_CALL_TYPE)
    {
        if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE) && 
            (g_ucm_p->call_list.group_info[hiliteTab].num_call == 1))
        {
            if (mmi_ucm_get_held_group(MMI_UCM_VOIP_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list) != 0)
            {
                return TRUE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No VoIP Single Held Call\n");
            return FALSE;
        }
        else if ((g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE) && 
                (g_ucm_p->call_list.group_info[hiliteTab].num_call == 1))
        {
            if (mmi_ucm_get_active_group(MMI_UCM_VOIP_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list) != 0)
            {
                return TRUE;
            }
            PRINT_INFORMATION("\n[mmi_ucm_conference_option] No VoIP Single Active Call\n");
            return FALSE;
        }
        return FALSE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_conference_option] Neither Voice Call Nor VoIP Call\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_split_option
 * DESCRIPTION
 *  Check if split option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means split option should show;
 *  FALSE means split option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_split_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_split_option] Same as Hold Conference Condition\n");
    return mmi_ucm_hold_conference_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_option
 * DESCRIPTION
 *  Check if transfer option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means transfer option should show;
 *  FALSE means transfer option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_transfer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_transfer_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_check
 * DESCRIPTION
 *  Check if transfer option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means transfer option should show;
 *  FALSE means transfer option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_transfer_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].num_call == 1)
    {
        if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)
        {
            if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
            {
                if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                PRINT_INFORMATION("\n[mmi_ucm_transfer_option] No Voice Single Outgoing / Held Call\n");
                return FALSE;
            }
            else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
            {
                if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                else if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
                {
                    return TRUE;                    
                }
                PRINT_INFORMATION("\n[mmi_ucm_transfer_option] No Voice Single Outgoing / Active Call\n");
                return FALSE;
            }            
            PRINT_INFORMATION("\n[mmi_ucm_transfer_option] Neither Voice Active Call Nor Voice Held Call\n");
            return FALSE;
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
	    else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)
        {
            if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
            {
                if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, TRUE, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                return FALSE;
            }
            else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
            {
                if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, g_ucm_p->call_misc.index_list) == 1)
                {
                    return TRUE;
                }
                else if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, TRUE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
                {
                    return TRUE;                    
                }
                return FALSE;
            }            
            return FALSE;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOIP_CALL_TYPE)
        {
            return TRUE;
        }
        PRINT_INFORMATION("\n[mmi_ucm_transfer_option] Neither Voice Call Nor VoIP Call\n");
        return FALSE;
    }    
    PRINT_INFORMATION("\n[mmi_ucm_transfer_option] Not Single Call\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_option
 * DESCRIPTION
 *  Check if end single option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means end single option should show;
 *  FALSE means end single option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_single_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_option
 * DESCRIPTION
 *  Check if end conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means end conference option should show;
 *  FALSE means end conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_conference_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_end_conference_check(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_check
 * DESCRIPTION
 *  Check if end conference option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means end conference option should show;
 *  FALSE means end conference option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_conference_check(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].num_call >= 2)
    {
        return TRUE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_end_conference_option] Not Conference Call\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_option
 * DESCRIPTION
 *  Check if end all option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means end all option should show;
 *  FALSE means end all option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_end_all_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.num_group >= 2)
    {
        return TRUE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_end_all_option] No Other Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_new_call_option
 * DESCRIPTION
 *  Check if new call option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means new call option should show;
 *  FALSE means new call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_new_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_new_call_option] Data Call Cannot New Call\n");
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_phonebook_option
 * DESCRIPTION
 *  Check if phonebook option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means phonebook option should show;
 *  FALSE means phonebook option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_phonebook_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sms_option
 * DESCRIPTION
 *  Check if sms option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means sms option should show;
 *  FALSE means sms option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_sms_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sound_recorder_option
 * DESCRIPTION
 *  Check if sound recorder option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means sound recorder option should show;
 *  FALSE means sound recorder option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_sound_recorder_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_sound_recorder_option] No Sound Recorder for Data Call\n");
        return FALSE;
    }
#ifdef __CTM_SUPPORT__
    else if (mmi_gsm_ctm_is_on() == TRUE)
    {
        return FALSE;
    }
#endif /* __CTM_SUPPORT__ */ 
#ifdef __MMI_SOUND_RECORDER__
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
    {
        return TRUE;
    }
#endif /* __MMI_SOUND_RECORDER__ */
    PRINT_INFORMATION("\n[mmi_ucm_sound_recorder_option] No Active Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_sound_in_call_option
 * DESCRIPTION
 *  Check if background sound option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means background sound option should show;
 *  FALSE means background sound option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_bk_sound_in_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_bk_sound_in_call_option] No Background Sound for Data Call\n");
        return FALSE;
    }
#ifdef __MMI_BG_SOUND_EFFECT__
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE &&
             g_ucm_p->call_list.num_group == 1)
    {
        return TRUE;
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */
    PRINT_INFORMATION("\n[mmi_ucm_bk_sound_in_call_option] No Active Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_loud_option
 * DESCRIPTION
 *  Check if loud speaker option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means loud option should show;
 *  FALSE means loud option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_loud_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_loud_option] No Handfree for Data Call\n");
        return FALSE;
    }
#ifdef __MMI_BT_SUPPORT__
    else if (mmi_bt_is_incall_aud_swap2bt() == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_loud_option] Audio Swap to BT\n");
        return FALSE;
    }
#endif /* __MMI_BT_SUPPORT__ */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mute_option
 * DESCRIPTION
 *  Check if mute option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means mute option should show;
 *  FALSE means mute option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_mute_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_mute_option] No Mute for Data Call\n");
        return FALSE;
    }
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
    {
        return TRUE;
    }
    PRINT_INFORMATION("\n[mmi_ucm_mute_option] No Active Call Exists\n");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dtmf_option
 * DESCRIPTION
 *  Check if dtmf option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means dtmf option should show;
 *  FALSE means dtmf option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_dtmf_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_dtmf_option] Same as Mute Condition\n");
    return mmi_ucm_mute_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_bt_audio_path_option
 * DESCRIPTION
 *  Check if swap bluetooth audio path option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means swap bt audio path option should show;
 *  FALSE means swap bt audio path option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_swap_bt_audio_path_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_swap_bt_audio_path_option] Data Call Cannot Swap Audio Path\n");
        return FALSE;
    }
#ifdef __MMI_BT_SUPPORT__
    if (mmi_bt_is_hs_connected() == FALSE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_swap_bt_audio_path_option] BT Not Connect\n");
        return FALSE;
    }
    if (g_ucm_p->call_misc.is_speech == FALSE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_swap_bt_audio_path_option] Speech is Off\n");
        return FALSE;
    }
    return TRUE;
#else /* __MMI_BT_SUPPORT__ */
    return FALSE;
#endif /* __MMI_BT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_connect_bt_default_headset_option
 * DESCRIPTION
 *  Check if connect bluetooth default headset option can be displayed in the in-call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means connect bt default headset option should show;
 *  FALSE means connect bt default headset option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_connect_bt_default_headset_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_DATA_CALL_TYPE_ALL)
    {
        PRINT_INFORMATION("\n[mmi_ucm_swap_bt_audio_path_option] Data Call Cannot Connect Default Headset\n");
        return FALSE;
    }
#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_HFP_SUPPORT__)
    if ((mmi_bt_is_power_on(MMI_FALSE) == MMI_FALSE) || (mmi_bt_is_default_hs_existed() == MMI_FALSE))
    {
    	PRINT_INFORMATION("\n[mmi_ucm_connect_bt_default_headset_option] BT Not Power On or Default Headset Not Exists\n");
	return FALSE;	
    }
    return TRUE;
#else /* defined(__MMI_BT_SUPPORT__) && defined(__MMI_HFP_SUPPORT__) */
    return FALSE;
#endif /* defined(__MMI_BT_SUPPORT__) && defined(__MMI_HFP_SUPPORT__) */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ctm_option
 * DESCRIPTION
 *  Check if ctm can connect
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means ctm is able to connect now.
 *  FALSE means user can't connect ctm now.
 *****************************************************************************/
MMI_BOOL mmi_ucm_ctm_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __CTM_SUPPORT__    
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CTM_SUPPORT__
    if ((g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) &&
        g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE &&
        g_ucm_p->call_list.group_info[hiliteTab].num_call == 1 &&
        mmi_gsm_ctm_is_open() == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_ctm_option] CTM connect is allow\n");
        return TRUE;
    }
#endif  /*__CTM_SUPPORT__*/
    PRINT_INFORMATION("\n[mmi_ucm_ctm_option] CTM connect is allow\n");
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 freeTab = g_ucm_p->call_list.num_group;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_ucm_p->call_misc.curr_action = MMI_UCM_DIAL;
    MMI_ASSERT(freeTab < MMI_UCM_MAX_NUM_TAB); /* no empty group entry to add */
    g_ucm_p->call_list.group_info[freeTab].group_id = MMI_UCM_INVALID_ID;
    g_ucm_p->call_list.group_info[freeTab].call_type = g_ucm_p->mo_info.dial_type;
    g_ucm_p->call_list.group_info[freeTab].call_state = MMI_UCM_OUTGOING_STATE;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].call_id = MMI_UCM_INVALID_ID;
    memcpy(&g_ucm_p->call_list.group_info[freeTab].call_info[0].remote_info, &g_ucm_p->mo_info.dial_num, sizeof(mmi_ucm_remote_info_struct));
    g_ucm_p->call_list.group_info[freeTab].call_info[0].call_origin = MMI_UCM_MO_ORIGIN;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].module_id = g_ucm_p->mo_info.module_id;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].proc_state = MMI_UCM_DO_PROCESS_STATE;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].act_type = MMI_UCM_DIAL;
    g_ucm_p->call_list.group_info[freeTab].num_call++;
    g_ucm_p->call_list.num_group++;

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[freeTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[freeTab].group_id;
    
#ifdef __MMI_TOUCH_SCREEN__
    /* stop virtual keypad tone if necessary. Ex. speed dial case */
    mmi_pen_reset();
#endif /* __MMI_TOUCH_SCREEN__ */

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

    mmi_ucm_pre_send_req(MMI_UCM_DIAL, &actionId, NULL, &g_ucm_p->mo_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_and_dial_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_and_dial_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, activeIndex = 0, freeTab = g_ucm_p->call_list.num_group;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_HOLD,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_HOLD_AND_DIAL;
    MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1);
    activeIndex = g_ucm_p->call_misc.index_list[0].group_index;
    MMI_ASSERT(freeTab < MMI_UCM_MAX_NUM_TAB); /* no empty group entry to add */
    g_ucm_p->call_list.group_info[freeTab].group_id = MMI_UCM_INVALID_ID;
    g_ucm_p->call_list.group_info[freeTab].call_type = g_ucm_p->mo_info.dial_type;
    g_ucm_p->call_list.group_info[freeTab].call_state = MMI_UCM_OUTGOING_STATE;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].call_id = MMI_UCM_INVALID_ID;
    memcpy(&g_ucm_p->call_list.group_info[freeTab].call_info[0].remote_info, &g_ucm_p->mo_info.dial_num, sizeof(mmi_ucm_remote_info_struct));
    g_ucm_p->call_list.group_info[freeTab].call_info[0].call_origin = MMI_UCM_MO_ORIGIN;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].module_id = g_ucm_p->mo_info.module_id;
    g_ucm_p->call_list.group_info[freeTab].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    g_ucm_p->call_list.group_info[freeTab].num_call++;
    g_ucm_p->call_list.num_group++;
    if (g_ucm_p->call_list.group_info[activeIndex].call_type == g_ucm_p->call_list.group_info[freeTab].call_type)
    {
        for (i = 0;  i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_HOLD_AND_DIAL;
        }
        for (i = 0; i < g_ucm_p->call_list.group_info[freeTab].num_call; i++)
        {
            g_ucm_p->call_list.group_info[freeTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            g_ucm_p->call_list.group_info[freeTab].call_info[i].act_type = MMI_UCM_HOLD_AND_DIAL;
        }

        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;                
        otherId.call_type = g_ucm_p->call_list.group_info[freeTab].call_type;
        otherId.group_id = g_ucm_p->call_list.group_info[freeTab].group_id;
        
        mmi_ucm_pre_send_req(MMI_UCM_HOLD_AND_DIAL, &firstId, &otherId, &g_ucm_p->mo_info);
    }
    else
    {
        for (i = 0;  i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_HOLD;
        }
        for (i = 0; i < g_ucm_p->call_list.group_info[freeTab].num_call; i++)
        {
            g_ucm_p->call_list.group_info[freeTab].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
            g_ucm_p->call_list.group_info[freeTab].call_info[i].act_type = MMI_UCM_DIAL;
        }

        /* For the action from AT, implied action should not be indicated to L4 */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {       
            if ((g_ucm_p->call_list.group_info[activeIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (g_ucm_p->call_list.group_info[freeTab].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
            {
                g_ucm_p->call_misc.no_rcode_count++;
            }
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        firstId.call_id = MMI_UCM_MAX_NUM_INDEX;

        mmi_ucm_pre_send_req(MMI_UCM_HOLD, &firstId, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_accept_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_accept_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_ANSWER,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_ACCEPT;    
    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[0].module_id = g_ucm_p->call_misc.curr_module;
    g_ucm_p->call_list.group_info[groupIndex].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state = MMI_UCM_DO_PROCESS_STATE;
    g_ucm_p->call_list.group_info[groupIndex].call_info[0].act_type = MMI_UCM_ACCEPT;

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id;

    mmi_ucm_pre_send_req(MMI_UCM_ACCEPT, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_and_accept_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_and_accept_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, activeIndex = 0, incomingIndex = 0;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_ANSWER,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_HOLD_AND_ACCEPT;
    MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1);
    activeIndex = g_ucm_p->call_misc.index_list[0].group_index;
    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    incomingIndex = g_ucm_p->call_misc.index_list[0].group_index;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].module_id = g_ucm_p->call_misc.curr_module;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    if (g_ucm_p->call_list.group_info[activeIndex].call_type == g_ucm_p->call_list.group_info[incomingIndex].call_type)
    {
        for (i = 0; i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_HOLD_AND_ACCEPT;
        }
        for (i = 0; i < g_ucm_p->call_list.group_info[incomingIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].act_type = MMI_UCM_HOLD_AND_ACCEPT;
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        firstId.call_id = MMI_UCM_MAX_NUM_INDEX;
        otherId.call_type = g_ucm_p->call_list.group_info[incomingIndex].call_type;
        otherId.group_id = g_ucm_p->call_list.group_info[incomingIndex].group_id;
        otherId.call_id = g_ucm_p->call_list.group_info[incomingIndex].call_info[0].call_id;
        
        mmi_ucm_pre_send_req(MMI_UCM_HOLD_AND_ACCEPT, &firstId, &otherId, NULL);
    }
    else
    {
        for (i = 0;  i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_HOLD;
        }
        for (i = 0;  i < g_ucm_p->call_list.group_info[incomingIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].act_type = MMI_UCM_ACCEPT;
        }

        /* For the action from AT, implied action should not be indicated to L4 */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {       
            if ((g_ucm_p->call_list.group_info[activeIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (g_ucm_p->call_list.group_info[incomingIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
            {
                g_ucm_p->call_misc.no_rcode_count++;
            }
        }

        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        firstId.call_id = MMI_UCM_MAX_NUM_INDEX;
        
        mmi_ucm_pre_send_req(MMI_UCM_HOLD, &firstId, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_hold_action_with_index(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_action_with_index(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, hiliteTab = group_index;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_HOLD,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_HOLD;
    for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
    {
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_HOLD;
    }

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = MMI_UCM_MAX_NUM_INDEX;
    
    mmi_ucm_pre_send_req(MMI_UCM_HOLD, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_retrieve_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_retrieve_action_with_index(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_retrieve_action_with_index(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, hiliteTab = group_index;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_RETRIEVE,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_RETRIEVE;
    for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
    {
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_RETRIEVE;
    }

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = MMI_UCM_MAX_NUM_INDEX;
    
    mmi_ucm_pre_send_req(MMI_UCM_RETRIEVE, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_swap_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_swap_action_with_index(g_ucm_p->call_misc.hilite_tab, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_swap_action_with_index(S32 current_index, S32 assign_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numGroup = 0, groupIndex = 0, hiliteTab = current_index;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_SWAP,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
    {
        numGroup = mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
        if (numGroup >= 2)
        {
            if ((g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE) && 
                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) != 0))
            {
                numGroup = 1;
                assign_index = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else if ((g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2) && 
                     (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) != 0))
            {
                numGroup = 1;
                assign_index = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else if (assign_index != -1)
            {
                numGroup = 1;
            }
            else
            {
                /* enter multiple held call selection screen */
                mmi_ucm_entry_multi_held_call();
                return;
            }            
        }
        if (numGroup == 1)
        {
            g_ucm_p->call_misc.curr_action = MMI_UCM_SWAP;
            mmi_ucm_reset_index_list();
            mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);
            if (g_ucm_p->call_list.group_info[hiliteTab].call_type == g_ucm_p->call_list.group_info[groupIndex].call_type)
            {                
                for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_SWAP;
                }
                for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_SWAP;
                }
                
                memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
                memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
                firstId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
                firstId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;                
                otherId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
                otherId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;

                mmi_ucm_pre_send_req(MMI_UCM_SWAP, &firstId, &otherId, NULL);
            }
            else
            {
                for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_HOLD;
                }
                for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_RETRIEVE;
                }

                /* For the action from AT, implied action should not be indicated to L4 */
                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {       
                    if ((g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                        (g_ucm_p->call_list.group_info[groupIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
                    {
                        g_ucm_p->call_misc.no_rcode_count++;
                    }
                }

                memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
                firstId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
                firstId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
                
                mmi_ucm_pre_send_req(MMI_UCM_HOLD, &firstId, NULL, NULL);
            }
        }
        else
        {
            MMI_ASSERT(numGroup != 0);
        }
    }
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
    {
        g_ucm_p->call_misc.curr_action = MMI_UCM_SWAP;
        MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1);
        groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);
        if (g_ucm_p->call_list.group_info[hiliteTab].call_type == g_ucm_p->call_list.group_info[groupIndex].call_type)
        {
            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_SWAP;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_SWAP;
            }
            
            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            firstId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;            
            otherId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
            otherId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
            
            mmi_ucm_pre_send_req(MMI_UCM_SWAP, &firstId, &otherId, NULL);
        }
        else
        {
            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_RETRIEVE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_HOLD;
            }

            /* For the action from AT, implied action should not be indicated to L4 */
            if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
            {       
                if ((g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                    (g_ucm_p->call_list.group_info[groupIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }

            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            firstId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
            
            mmi_ucm_pre_send_req(MMI_UCM_HOLD, &firstId, NULL, NULL);
        }
    }
            
    mmi_ucm_entry_processing_screen();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_conference_action_with_index(g_ucm_p->call_misc.hilite_tab, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_conference_action_with_index(S32 current_index, S32 assign_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numGroup = 0, groupIndex = 0, hiliteTab = current_index;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_CONFERENCE,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);

    if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)
    {        
        g_ucm_p->call_misc.curr_action = MMI_UCM_CONFERENCE;
        if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
        {
            MMI_ASSERT(mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }

            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = MMI_UCM_VOICE_CALL_TYPE;
            firstId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
            otherId.call_type = MMI_UCM_VOICE_CALL_TYPE;
            otherId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;

            mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
        }
        else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
        {
            MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            
            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = MMI_UCM_VOICE_CALL_TYPE;
            firstId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;            
            otherId.call_type = MMI_UCM_VOICE_CALL_TYPE;
            otherId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;

            mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)
    {        
        g_ucm_p->call_misc.curr_action = MMI_UCM_CONFERENCE;
        if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
        {
            MMI_ASSERT(mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }

            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;
            firstId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
            otherId.call_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;
            otherId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;

            mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
        }
        else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
        {
            MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            
            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;
            firstId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;            
            otherId.call_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;
            otherId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;

            mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
        }
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    else if (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOIP_CALL_TYPE)
    {        
        if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_ACTIVE_STATE)
        {
            numGroup = mmi_ucm_get_held_group(MMI_UCM_VOIP_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list);
            if (numGroup >= 2)
            {
                if (assign_index != -1)
                {
                    numGroup = 1;
                }
                else
                {
                    /* enter multiple held call selection screen */
                    mmi_ucm_entry_multi_held_call();
                    return;
                }                
            }
            if (numGroup == 1)
            {
                g_ucm_p->call_misc.curr_action = MMI_UCM_CONFERENCE;
                groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

                for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
                }
                for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
                {
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                    g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
                }

                memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
                memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
                firstId.call_type = MMI_UCM_VOIP_CALL_TYPE;
                firstId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
                otherId.call_type = MMI_UCM_VOIP_CALL_TYPE;
                otherId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;

                mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
            }
            else
            {
                MMI_ASSERT(numGroup != 0);
            }
        }
        else if (g_ucm_p->call_list.group_info[hiliteTab].call_state == MMI_UCM_HOLD_STATE)
        {
            g_ucm_p->call_misc.curr_action = MMI_UCM_CONFERENCE;
            MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_VOIP_CALL_TYPE, TRUE, g_ucm_p->call_misc.index_list) == 1);
            groupIndex = (assign_index == -1) ? (g_ucm_p->call_misc.index_list[0].group_index) : (assign_index);

            for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
            {
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }
            for (i = 0; i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
            {
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
                g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_CONFERENCE;
            }

            memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
            memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
            firstId.call_type = MMI_UCM_VOIP_CALL_TYPE;
            firstId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;            
            otherId.call_type = MMI_UCM_VOIP_CALL_TYPE;
            otherId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;

            mmi_ucm_pre_send_req(MMI_UCM_CONFERENCE, &firstId, &otherId, NULL);
        }
    }
        
    mmi_ucm_entry_processing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_split_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_split_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_split_action_with_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_split_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_split_action_with_index(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, hiliteTab = group_index, hiliteIndex = call_index;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_SPLIT,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_SPLIT;
    for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
    {
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_SPLIT;
    }

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].call_id;
    
    mmi_ucm_pre_send_req(MMI_UCM_SPLIT, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deflect_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, groupIndex = 0;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_DEFLECT,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_DEFLECT;    
    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    for (i = 0;  i < g_ucm_p->call_list.group_info[groupIndex].num_call; i++)
    {
        g_ucm_p->call_list.group_info[groupIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
        g_ucm_p->call_list.group_info[groupIndex].call_info[i].act_type = MMI_UCM_DEFLECT;
    }
    
    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id;

    mmi_ucm_pre_send_req(MMI_UCM_DEFLECT, &actionId, NULL, &g_ucm_p->mo_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_action_with_number
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deflect_action_with_number(PU8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ucm_p->mo_info.dial_num.num_uri, 0, MMI_UCM_MAX_NUM_URI_LEN);
    memcpy(g_ucm_p->mo_info.dial_num.num_uri, number, MMI_UCM_MAX_NUM_URI_LEN);

    mmi_ucm_deflect_action();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_transfer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, hiliteTab = g_ucm_p->call_misc.hilite_tab;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_TRANSFER,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_TRANSFER;
    for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
    {
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_TRANSFER;
    }

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[hiliteTab].call_info[0].call_id;

    mmi_ucm_pre_send_req(MMI_UCM_TRANSFER, &actionId, NULL, &g_ucm_p->mo_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_explict_call_transfer_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_explict_call_transfer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, firstIndex = 0, secondIndex = 0;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_TRANSFER,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_EXPLICT_CALL_TRANSFER;
    if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->call_misc.index_list) == 1)
    {
        firstIndex = g_ucm_p->call_misc.index_list[0].group_index;
        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
        {
            secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
        }
        else
        {
            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1)
            {
                secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else
            {
                MMI_ASSERT(0); /* outgoing + active + held should be 2 */
            }
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, g_ucm_p->call_misc.index_list) == 1)
    {
        firstIndex = g_ucm_p->call_misc.index_list[0].group_index;
        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
        {
            secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
        }
        else
        {
            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1)
            {
                secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else
            {
                MMI_ASSERT(0); /* outgoing + active + held should be 2 */
            }
        }
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
        {
            firstIndex = g_ucm_p->call_misc.index_list[0].group_index;
            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1)
            {
                secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB)
        {
            firstIndex = g_ucm_p->call_misc.index_list[0].group_index;
            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1)
            {
                secondIndex = g_ucm_p->call_misc.index_list[0].group_index;
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    for (i = 0; i < g_ucm_p->call_list.group_info[firstIndex].num_call; i++)
    {
        g_ucm_p->call_list.group_info[firstIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[firstIndex].call_info[i].act_type = MMI_UCM_EXPLICT_CALL_TRANSFER;
    }
    for (i = 0; i < g_ucm_p->call_list.group_info[secondIndex].num_call; i++)
    {
        g_ucm_p->call_list.group_info[secondIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[secondIndex].call_info[i].act_type = MMI_UCM_EXPLICT_CALL_TRANSFER;
    }

    memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
    memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
    firstId.call_type = g_ucm_p->call_list.group_info[firstIndex].call_type;
    firstId.group_id = g_ucm_p->call_list.group_info[firstIndex].group_id;
    otherId.call_type = g_ucm_p->call_list.group_info[secondIndex].call_type;
    otherId.group_id = g_ucm_p->call_list.group_info[secondIndex].group_id;

    mmi_ucm_pre_send_req(MMI_UCM_EXPLICT_CALL_TRANSFER, &firstId, &otherId, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_single_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_end_single_action_with_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_single_action_with_index(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = group_index, hiliteIndex = call_index;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_END_SINGLE,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_force_release_action);
    
    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_END_SINGLE;
    g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].act_type = MMI_UCM_END_SINGLE;

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].call_id;
    
    mmi_ucm_pre_send_req(MMI_UCM_END_SINGLE, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_end_conference_action_with_index(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_conference_action_with_index(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, hiliteTab = group_index;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_END_CONFERENCE,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_force_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_END_CONFERENCE;
    for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
    {
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
        g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_END_CONFERENCE;
    }

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;

    mmi_ucm_pre_send_req(MMI_UCM_END_CONFERENCE, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_end_all_action_with_type(MMI_UCM_CALL_TYPE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_action_with_type
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_action_with_type(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_END_ALL,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_force_release_action);
    
    mmi_ucm_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_UCM_PROCESSING); /* in case clam close in the processing screen */
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ALL;
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_type & call_type)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_ALL;
            }
        }
    }

    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;

    /* For the case of end all call before dial SOS from AT, end_all is implied action so it should not be indicated to L4 */
    if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
        (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
    {       
        if ((g_ucm_p->mo_info.is_wait_dial == TRUE) &&
            (mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL)))
        {
            g_ucm_p->call_misc.no_rcode_count++;
        }
    }
    
    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_active_and_retrieve_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_active_and_retrieve_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_end_active_and_retrieve_action_with_index(g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_active_and_retrieve_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_active_and_retrieve_action_with_index(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, activeIndex = 0, hiliteTab = group_index;
    mmi_ucm_id_info_struct firstId, otherId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_RETRIEVE,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
        
    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ACTIVE_AND_RETRIEVE;
    MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1);
    activeIndex = g_ucm_p->call_misc.index_list[0].group_index;    
    if (((g_ucm_p->call_list.group_info[activeIndex].call_type == MMI_UCM_VOICE_CALL_TYPE) &&
        (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE)) || 
        ((g_ucm_p->call_list.group_info[activeIndex].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2) &&
        (g_ucm_p->call_list.group_info[hiliteTab].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)))
    {
        for (i = 0; i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_ACTIVE_AND_RETRIEVE;
        }
        for (i = 0; i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
        {
            g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_END_ACTIVE_AND_RETRIEVE;
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        otherId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
        otherId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
        otherId.call_id = g_ucm_p->call_list.group_info[hiliteTab].call_info[0].call_id;
        
        mmi_ucm_pre_send_req(MMI_UCM_END_ACTIVE_AND_RETRIEVE, &firstId, &otherId, NULL);
    }
    else
    {
        for (i = 0;  i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            if (g_ucm_p->call_list.group_info[activeIndex].num_call == 1)
            {
                g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_SINGLE;
            }
            else if (g_ucm_p->call_list.group_info[activeIndex].num_call > 1)
            {
                g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_CONFERENCE;
            }
        }
        for (i = 0;  i < g_ucm_p->call_list.group_info[hiliteTab].num_call; i++)
        {
            g_ucm_p->call_list.group_info[hiliteTab].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
            g_ucm_p->call_list.group_info[hiliteTab].call_info[i].act_type = MMI_UCM_RETRIEVE;
        }

        /* For the action from AT, implied action should not be indicated to L4 */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {       
            if ((g_ucm_p->call_list.group_info[activeIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (g_ucm_p->call_list.group_info[hiliteTab].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
            {
                g_ucm_p->call_misc.no_rcode_count++;
            }
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;

        if (g_ucm_p->call_list.group_info[activeIndex].call_info[0].act_type == MMI_UCM_END_SINGLE)
        {
            firstId.call_id = g_ucm_p->call_list.group_info[activeIndex].call_info[0].call_id;
        }
        
        mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[activeIndex].call_info[0].act_type, &firstId, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_and_accept_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_active_and_accept_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, activeIndex = 0, incomingIndex = 0;
    mmi_ucm_id_info_struct firstId, otherId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_ANSWER,
        STR_ID_UCM_PROCESSING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_release_action);
    
    mmi_ucm_entry_processing_screen();
    
    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ACTIVE_AND_ACCEPT;
    MMI_ASSERT(mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 1);
    activeIndex = g_ucm_p->call_misc.index_list[0].group_index;
    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    incomingIndex = g_ucm_p->call_misc.index_list[0].group_index;    
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].module_id = g_ucm_p->call_misc.curr_module;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    if (((g_ucm_p->call_list.group_info[activeIndex].call_type == MMI_UCM_VOICE_CALL_TYPE) &&
        (g_ucm_p->call_list.group_info[incomingIndex].call_type == MMI_UCM_VOICE_CALL_TYPE)) || 
        ((g_ucm_p->call_list.group_info[activeIndex].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2) &&
        (g_ucm_p->call_list.group_info[incomingIndex].call_type == MMI_UCM_VOICE_CALL_TYPE_SIM2)))
    {
        for (i = 0; i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_ACTIVE_AND_ACCEPT;
        }
        for (i = 0; i < g_ucm_p->call_list.group_info[incomingIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].act_type = MMI_UCM_END_ACTIVE_AND_ACCEPT;
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        memset(&otherId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        otherId.call_type = g_ucm_p->call_list.group_info[incomingIndex].call_type;
        otherId.group_id = g_ucm_p->call_list.group_info[incomingIndex].group_id;
        otherId.call_id = g_ucm_p->call_list.group_info[incomingIndex].call_info[0].call_id;
        
        mmi_ucm_pre_send_req(MMI_UCM_END_ACTIVE_AND_ACCEPT, &firstId, &otherId, NULL);
    }
    else
    {
        for (i = 0;  i < g_ucm_p->call_list.group_info[activeIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[activeIndex].call_info[i].proc_state = MMI_UCM_DO_PROCESS_STATE;
            if (g_ucm_p->call_list.group_info[activeIndex].num_call == 1)
            {
                g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_SINGLE;
            }
            else if (g_ucm_p->call_list.group_info[activeIndex].num_call > 1)
            {
                g_ucm_p->call_list.group_info[activeIndex].call_info[i].act_type = MMI_UCM_END_CONFERENCE;
            }
        }
        for (i = 0;  i < g_ucm_p->call_list.group_info[incomingIndex].num_call; i++)
        {
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
            g_ucm_p->call_list.group_info[incomingIndex].call_info[i].act_type = MMI_UCM_ACCEPT;
        }

        /* For the action from AT, implied action should not be indicated to L4 */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {       
            if ((g_ucm_p->call_list.group_info[activeIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (g_ucm_p->call_list.group_info[incomingIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL))
            {
                g_ucm_p->call_misc.no_rcode_count++;
            }
        }
        
        memset(&firstId, 0, sizeof(mmi_ucm_id_info_struct));
        firstId.call_type = g_ucm_p->call_list.group_info[activeIndex].call_type;
        firstId.group_id = g_ucm_p->call_list.group_info[activeIndex].group_id;
        
        if (g_ucm_p->call_list.group_info[activeIndex].call_info[0].act_type == MMI_UCM_END_SINGLE)
        {
            firstId.call_id = g_ucm_p->call_list.group_info[activeIndex].call_info[0].call_id;
        }

        mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[activeIndex].call_info[0].act_type, &firstId, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_and_accept_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_and_accept_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0, incomingIndex = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter(
    STR_ID_UCM_ANSWER,
    STR_ID_UCM_PROCESSING,
    IMG_GLOBAL_PROGRESS,
    0,
    0,
    0,
    0,
    0,
    mmi_ucm_release_action);

    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ALL;
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state != MMI_UCM_INCOMING_STATE)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_SINGLE;
                }
                else if (g_ucm_p->call_list.group_info[i].num_call > 1)
                {
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_CONFERENCE;
                }
            }
        }
    }

    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    
    MMI_ASSERT(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    incomingIndex = g_ucm_p->call_misc.index_list[0].group_index;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].module_id = g_ucm_p->call_misc.curr_module;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].l4c_source = g_ucm_p->call_misc.l4c_info.l4c_source;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
    g_ucm_p->call_list.group_info[incomingIndex].call_info[0].act_type = MMI_UCM_ACCEPT;

    PRINT_INFORMATION("\n[mmi_ucm_end_all_and_accept_action] End All from Group Index: %d, Call Index: %d, Accept Type: %d\n", groupIndex, callIndex, g_ucm_p->call_list.group_info[incomingIndex].call_type);

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_quick_end
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_quick_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no active/held voice calls to drop */
    if(mmi_ucm_app_active_call(MMI_UCM_VOICE_CALL_TYPE_ALL) == 0 &&
       mmi_ucm_app_held_call(MMI_UCM_VOICE_CALL_TYPE_ALL) == 0)
    {
        PRINT_INFORMATION("\n[mmi_ucm_auto_quick_end] No voice calls to drop\n");
        return;
    }
    
    mmi_ucm_set_processing_parameter(
    STR_ID_UCM_END_CALL,
    STR_ID_UCM_PROCESSING,
    IMG_GLOBAL_PROGRESS,
    0,
    0,
    0,
    0,
    0,
    mmi_ucm_release_action);

    mmi_ucm_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_UCM_PROCESSING);

    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ALL;
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state != MMI_UCM_INCOMING_STATE &&
            g_ucm_p->call_list.group_info[i].call_state != MMI_UCM_OUTGOING_STATE)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 1"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_SINGLE;
                }
                else if (g_ucm_p->call_list.group_info[i].num_call > 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 2"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_CONFERENCE;
                }
            }
        }
    }

    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    
    PRINT_INFORMATION("\n[mmi_ucm_auto_quick_end] End All from Group Index: %d, Call Index: %d\n", groupIndex, callIndex);

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_held_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_held_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no held voice calls to drop */
    MMI_ASSERT(mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) > 0);
   
    mmi_ucm_set_processing_parameter(
    STR_ID_UCM_ANSWER,
    STR_ID_UCM_PROCESSING,
    IMG_GLOBAL_PROGRESS,
    0,
    0,
    0,
    0,
    0,
    mmi_ucm_release_action);

    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ALL;
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_HOLD_STATE)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 1"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_SINGLE;
                }
                else if (g_ucm_p->call_list.group_info[i].num_call > 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 2"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_CONFERENCE;
                }
            }
        }
    }

    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    
    PRINT_INFORMATION("\n[mmi_ucm_end_all_held_action] End All from Group Index: %d, Call Index: %d\n", groupIndex, callIndex);

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_active_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_active_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no active calls to drop */
    MMI_ASSERT(mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) > 0);
   
    mmi_ucm_set_processing_parameter(
    STR_ID_UCM_ANSWER,
    STR_ID_UCM_PROCESSING,
    IMG_GLOBAL_PROGRESS,
    0,
    0,
    0,
    0,
    0,
    mmi_ucm_release_action);

    mmi_ucm_entry_processing_screen();

    g_ucm_p->call_misc.curr_action = MMI_UCM_END_ALL;
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_ACTIVE_STATE)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 1"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_SINGLE;
                }
                else if (g_ucm_p->call_list.group_info[i].num_call > 1)
                {
                    PRINT_INFORMATION(("\n[Mick debug] test 2"));
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = MMI_UCM_WAIT_PROCESS_STATE;
                    g_ucm_p->call_list.group_info[i].call_info[j].act_type = MMI_UCM_END_CONFERENCE;
                }
            }
        }
    }

    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    
    PRINT_INFORMATION("\n[mmi_ucm_end_all_held_action] End All from Group Index: %d, Call Index: %d\n", groupIndex, callIndex);

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_reject_action_with_index
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_reject_action_with_index(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = group_index, hiliteIndex = call_index;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
    g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].act_type = MMI_UCM_AUTO_REJECT;

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[hiliteTab].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[hiliteTab].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[hiliteTab].call_info[hiliteIndex].call_id;
    
    mmi_ucm_pre_send_req(MMI_UCM_AUTO_REJECT, &actionId, NULL, NULL);
    mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_release_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_release_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, typeIndex = 0, groupIndex = 0, callIndex = 0, numTotal = 0, numOutgoing = 0;
    mmi_ucm_call_type_enum callType = 0;
    mmi_ucm_id_info_struct actionId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_set_processing_parameter(
        STR_ID_UCM_END_CALL,
        STR_ID_UCM_RELEASING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_force_release_action);
    
    mmi_ucm_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_UCM_PROCESSING);

    numOutgoing = mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
    if (numOutgoing > 0)
    {
        for (i = 0;  i < numOutgoing; i++)
        {
            groupIndex = g_ucm_p->call_misc.index_list[i].group_index;

            /* call application does not have this call yet, so remove the call from call list directly */
            if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state == MMI_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_p->call_list.group_info[groupIndex].num_call--;
                g_ucm_p->call_list.num_group--;
                mmi_ucm_reset_group_entry(groupIndex);
            }
        }
    }

    mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_WAIT_PROCESS_STATE);
    mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_WAIT_PROCESS_STATE);
    numTotal = mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    for (typeIndex = 0; typeIndex < g_ucm_p->call_list.num_group; typeIndex++)
    {
        PRINT_INFORMATION("\n[mmi_ucm_release_action] Type Index: %d, Call Type: %d\n", typeIndex, g_ucm_p->call_list.group_info[typeIndex].call_type);
        callType = g_ucm_p->call_list.group_info[typeIndex].call_type;
        for (i = 0; i < numTotal; i++)
        {
            groupIndex = g_ucm_p->call_misc.index_list[i].group_index;
            callIndex = g_ucm_p->call_misc.index_list[i].call_index;
            if (g_ucm_p->call_list.group_info[groupIndex].call_type == callType)
            {
                if (g_ucm_p->call_list.group_info[groupIndex].num_call == 1)
                {
                    PRINT_INFORMATION("\n[mmi_ucm_release_action] Possible to End Single for Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
                    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_END_SINGLE;
                }
                else if (g_ucm_p->call_list.group_info[groupIndex].num_call > 1)
                {
                    PRINT_INFORMATION("\n[mmi_ucm_release_action] Possible to End Conference for Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
                    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_END_CONFERENCE;
                }
            }
        }
        numTotal = mmi_ucm_get_process_state(MMI_UCM_IDLE_PROCESS_STATE, g_ucm_p->call_misc.index_list);
        for (i = 0; i < numTotal; i++)
        {
            groupIndex = g_ucm_p->call_misc.index_list[i].group_index;
            if (g_ucm_p->call_list.group_info[groupIndex].call_type == callType)
            {
                PRINT_INFORMATION("\n[mmi_ucm_release_action] Impossible to Use End All Action for Call Type %d\n", callType);
                break; /* impossible to use end all action for this call type */
            }
        }
        if (i == numTotal)
        {
            numTotal = mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
            for (i = 0; i < numTotal; i++)
            {
                groupIndex = g_ucm_p->call_misc.index_list[i].group_index;
                callIndex = g_ucm_p->call_misc.index_list[i].call_index;
                if (g_ucm_p->call_list.group_info[groupIndex].call_type == callType)
                {
                    if (g_ucm_p->call_list.group_info[groupIndex].num_call == 1)
                    {
                        PRINT_INFORMATION("\n[mmi_ucm_release_action] Replace End Single to End All for Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
                        g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_END_ALL;
                    }
                    else if (g_ucm_p->call_list.group_info[groupIndex].num_call > 1)
                    {
                        PRINT_INFORMATION("\n[mmi_ucm_release_action] Replace End Conference to End All for Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
                        g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_END_ALL;
                    }
                }
            }            
        }
    }
    
    mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    callIndex = g_ucm_p->call_misc.index_list[0].call_index;
    g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;

    memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
    actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
    actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
    actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
    
    mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_force_release_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_force_release_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, groupIndex = 0, callIndex = 0, numTotal = 0;
    mmi_ucm_id_info_struct actionId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    numTotal = mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    for (i = 0; i < numTotal; i++)
    {
        groupIndex = g_ucm_p->call_misc.index_list[i].group_index;
        callIndex = g_ucm_p->call_misc.index_list[i].call_index;

        memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
        actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
        actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
        actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;

        if ((g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_SINGLE) || 
            (g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_CONFERENCE) || 
            (g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_ALL))
        {
            g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_FORCE_RELEASE;

            PRINT_INFORMATION("\n[mmi_ucm_force_release_action] Force Release Directly from Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
            mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &actionId, NULL, NULL);
        }
    }

    mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_WAIT_PROCESS_STATE);
    numTotal = mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list);
    for (i = 0; i < numTotal; i++)
    {
        groupIndex = g_ucm_p->call_misc.index_list[i].group_index;
        callIndex = g_ucm_p->call_misc.index_list[i].call_index;

        memset(&actionId, 0, sizeof(mmi_ucm_id_info_struct));
        actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
        actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
        actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;

        if ((g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_SINGLE) || 
            (g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_CONFERENCE) || 
            (g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type == MMI_UCM_END_ALL))
        {
            g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].proc_state = MMI_UCM_DO_PROCESS_STATE;        
            g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type = MMI_UCM_FORCE_RELEASE;

            PRINT_INFORMATION("\n[mmi_ucm_force_release_action] Wait / Complete Process End Single + Force Release from Group Index: %d, Call Index: %d\n", groupIndex, callIndex);
            mmi_ucm_pre_send_req(MMI_UCM_END_SINGLE, &actionId, NULL, NULL);
            mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &actionId, NULL, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_log_call_history
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  group_index     [IN]            Group index
 *  call_index      [IN]            Call index
 *  is_connect      [IN]            Call connect or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_log_call_history(S32 group_index, S32 call_index, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CALL_INFO voiceLog;
#ifdef __MMI_VOIP__
    mmi_voip_call_log_struct voipLog;
#endif
    S32 unicodeLen = 0, asciiLen = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    ST_MTPNP_AD_SET_CALLLOG card2log;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if(g_ucm_p->call_list.group_info[group_index].call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
    {
        memset(&card2log, 0, sizeof(ST_MTPNP_AD_SET_CALLLOG));
        unicodeLen = ((MTPNP_AD_MAX_NAME_LEN-2)/2 > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : ((MTPNP_AD_MAX_NAME_LEN - 2)/2);
        mmi_ucs2ncpy(card2log.log_name, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        asciiLen = ((MAX_NUMBER / ENCODING_LENGTH) > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : ((MAX_NUMBER / ENCODING_LENGTH) - 1);
        mmi_asc_n_to_ucs2((S8 *)card2log.log_num, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);            
        
        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */ 
	     memcpy(&card2log.start_time, 
	                    &g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time,
	                    sizeof(MYTIME));
            MTPNP_AD_Log_DialedCall(&card2log);
        }
        else if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MT_ORIGIN)
        {
            if (is_connect == TRUE)
            {
                /* received */
		  memcpy(&card2log.start_time,
		                &g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time, 
		                sizeof(MYTIME));          
                MTPNP_AD_Log_RecvedCall(&card2log);
            }
            else
            {
                /* missed */                
                DTGetRTCTime(&card2log.start_time);
                MTPNP_PFAL_SetLastMissedCallType(LASTMISSEDCALL_TYPE_SIM2);
                MTPNP_AD_Log_MissedCall(&card2log);
                SetMissedCallFlag(TRUE); /* display missed call screen in idle screen */
            }
        }
        else
        {
            MMI_ASSERT(0); /* should be either MMI_UCM_MO_ORIGIN or MMI_UCM_MT_ORIGIN */
        }
	 return;
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_VOIP__
    if (g_ucm_p->call_list.group_info[group_index].call_type == MMI_UCM_VOIP_CALL_TYPE)
    {
        memset(&voipLog, 0, sizeof(mmi_voip_call_log_struct));
        unicodeLen = (VOIP_DISP_NAME_LEN > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : (VOIP_DISP_NAME_LEN - 1);
        mmi_ucs2ncpy((S8*)voipLog.dispName, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        voipLog.dispDcs = (GetUCS2Flag((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
        asciiLen = (VOIP_URI_LEN > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : (VOIP_URI_LEN - 1);
        strncpy((S8*)voipLog.remoteUri, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);            
        
        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */            
            voipLog.startTime = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
            mmi_chist_log_voip_dialed_call(&voipLog);
        }
        else if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MT_ORIGIN)
        {
            if (is_connect == TRUE)
            {
                /* received */
                voipLog.startTime = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
                mmi_chist_log_voip_received_call(&voipLog);
            }
            else
            {
                /* missed */
                DTGetRTCTime(&voipLog.startTime);
                mmi_chist_log_voip_missed_call(&voipLog);
                SetMissedCallFlag(TRUE); /* display missed call screen in idle screen */
            }
        }
        else
        {
            MMI_ASSERT(0); /* should be either MMI_UCM_MO_ORIGIN or MMI_UCM_MT_ORIGIN */
        }
    }
    else
#endif /* __MMI_VOIP__ */
    {
        memset(&voiceLog, 0, sizeof(CALL_INFO));
        unicodeLen = (MAX_NAME > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : (MAX_NAME - 1);
        mmi_ucs2ncpy((S8*)voiceLog.pBname, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        voiceLog.name_dcs = (GetUCS2Flag((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
        asciiLen = ((MAX_NUMBER / ENCODING_LENGTH) > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : ((MAX_NUMBER / ENCODING_LENGTH) - 1);
        mmi_asc_n_to_ucs2((S8*)voiceLog.num, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);            
        mmi_ucs2ncpy((S8*)voiceLog.number, (S8*)voiceLog.num, mmi_ucs2strlen((S8*)voiceLog.num));
        voiceLog.call_type = g_ucm_p->call_list.group_info[group_index].call_type ;

        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */            
            voiceLog.start_time = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
            CHISTLogDialedCall(&voiceLog);
        }
        else if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MT_ORIGIN)
        {
            if (is_connect == TRUE)
            {
                /* received */                
                voiceLog.start_time = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
                CHISTLogRecvdCall(&voiceLog);
            }
            else
            {
                /* missed */                
                DTGetRTCTime(&voiceLog.start_time);
                CHISTLogMissedCall(&voiceLog);
                SetMissedCallFlag(TRUE); /* display missed call screen in idle screen */
            }
        }
        else
        {
            MMI_ASSERT(0); /* should be either MMI_UCM_MO_ORIGIN or MMI_UCM_MT_ORIGIN */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_log_call_duration
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  var_1           [IN]            Description of var_1
 *  var_2_ptr       [OUT]           Description of var_2_ptr
 *  var_3_ptr       [IN/OUT]        Description of var_3_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_log_call_duration(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CALL_INFO voiceLog;
#ifdef __MMI_VOIP__
    mmi_voip_call_log_struct voipLog;
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
    ST_MTPNP_AD_SLAVE_CALL_INFO slaveLog;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    S32 unicodeLen = 0, asciiLen = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_ucm_p->call_list.group_info[group_index].call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
    {
        memset(&slaveLog, 0, sizeof(ST_MTPNP_AD_SLAVE_CALL_INFO));
        
        unicodeLen = ((MTPNP_AD_MAX_NAME_LEN / ENCODING_LENGTH) > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : ((MTPNP_AD_MAX_NAME_LEN / ENCODING_LENGTH) - 1);
        mmi_ucs2ncpy((S8*)slaveLog.call_name.name, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        slaveLog.call_name.dcs= (GetUCS2Flag((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
        slaveLog.call_name.name_len = unicodeLen;
        
        asciiLen = ((MTPNP_AD_MAX_CC_ADDR_LEN / ENCODING_LENGTH) > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : ((MTPNP_AD_MAX_CC_ADDR_LEN / ENCODING_LENGTH) - 1);
        mmi_asc_n_to_ucs2((S8*)slaveLog.call_number.number, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);
        slaveLog.call_number.number_len = asciiLen;

        memcpy(&slaveLog.start_time,
               &g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time, 
               sizeof(ST_MTPNP_AD_TIME));

        memcpy(&slaveLog.end_time,
               &g_ucm_p->call_list.group_info[group_index].call_info[call_index].end_time, 
               sizeof(ST_MTPNP_AD_TIME));
        
        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */            
            slaveLog.orgination_flag = MTPNP_CM_CALL_MO;
        }
        else
        {
            /* received */                
            slaveLog.orgination_flag = MTPNP_CM_CALL_MT;
        }

        LogSlaveDialedCallDuration(&slaveLog);
    }
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_VOIP__
    if (g_ucm_p->call_list.group_info[group_index].call_type == MMI_UCM_VOIP_CALL_TYPE)
    {
        memset(&voipLog, 0, sizeof(mmi_voip_call_log_struct));
        unicodeLen = (VOIP_DISP_NAME_LEN > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : (VOIP_DISP_NAME_LEN - 1);
        mmi_ucs2ncpy((S8*)voipLog.dispName, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        voipLog.dispDcs = (GetUCS2Flag((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
        asciiLen = (VOIP_URI_LEN > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : (VOIP_URI_LEN - 1);
        strncpy((S8*)voipLog.remoteUri, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);            
        voipLog.startTime = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
        voipLog.endTime = g_ucm_p->call_list.group_info[group_index].call_info[call_index].end_time;
            
        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */            
            mmi_chist_log_voip_call_duration(&voipLog, PHB_LND);
        }
        else
        {
            /* received */
            mmi_chist_log_voip_call_duration(&voipLog, PHB_LNR);
        }
    }
    else
#endif /* __MMI_VOIP__ */
    {
        memset(&voiceLog, 0, sizeof(CALL_INFO));
        unicodeLen = (MAX_NAME > mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) ? (mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name)) : (MAX_NAME - 1);
        mmi_ucs2ncpy((S8*)voiceLog.pBname, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name, unicodeLen); 
        voiceLog.name_dcs = (GetUCS2Flag((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name) == TRUE) ? (MMI_PHB_UCS2) : (MMI_PHB_ASCII);
        asciiLen = ((MAX_NUMBER / ENCODING_LENGTH) > strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) ? (strlen((S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri)) : ((MAX_NUMBER / ENCODING_LENGTH) - 1);
        mmi_asc_n_to_ucs2((S8*)voiceLog.num, (S8*)g_ucm_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, asciiLen);            
        mmi_ucs2ncpy((S8*)voiceLog.number, (S8*)voiceLog.num, mmi_ucs2strlen((S8*)voiceLog.num));
        voiceLog.start_time = g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time;
        voiceLog.end_time = g_ucm_p->call_list.group_info[group_index].call_info[call_index].end_time;
        
        if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_origin == MMI_UCM_MO_ORIGIN)
        {
            /* dialed */            
            CHISTLogDialedCallDuration(&voiceLog);
        }
        else
        {
            /* received */                
            CHISTLogRecvdCallDuration(&voiceLog);
        }
    }
}
#endif /* __MMI_UCM__ */

