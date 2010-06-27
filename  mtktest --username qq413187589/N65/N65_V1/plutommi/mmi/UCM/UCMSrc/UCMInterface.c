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
 *  UCMInterface.c
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
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "wgui_status_icons.h"

#include "GpioInc.h"
#include "NetworkSetupDefs.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"
#include "BGSoundGProt.h"
#include "SSCStringHandle.h"
#include "GSM7BitDefaultAlphabet.h"

#include "IdleAppProt.h"  /* mmi_idle_delete_dialpad_from_history */
#include "app_usedetails.h"

#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_total_call
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  call_type       [IN]            Call type
 * RETURNS
 *  Number of calls based on the given call type.
 *****************************************************************************/
S32 mmi_ucm_app_total_call(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_type & call_type)
        {
            numTotal += g_ucm_p->call_list.group_info[i].num_call;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_outgoing_call
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  call_type       [IN]            Call type
 * RETURNS
 *  Number of outgoing calls based on the given call type.
 *****************************************************************************/
S32 mmi_ucm_app_outgoing_call(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_OUTGOING_STATE))
        {
            numTotal += g_ucm_p->call_list.group_info[i].num_call;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_incoming_call
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  call_type       [IN]            Call type
 * RETURNS
 *  Number of incoming calls based on the given call type.
 *****************************************************************************/
S32 mmi_ucm_app_incoming_call(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_INCOMING_STATE))
        {
            numTotal += g_ucm_p->call_list.group_info[i].num_call;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_active_call
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  call_type       [IN]            Call type
 * RETURNS
 *  Number of active calls based on the given call type.
 *****************************************************************************/
S32 mmi_ucm_app_active_call(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_ACTIVE_STATE))
        {
            numTotal += g_ucm_p->call_list.group_info[i].num_call;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_held_call
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  call_type       [IN]            Call type
 * RETURNS
 *  Number of held calls based on the given call type.
 *****************************************************************************/
S32 mmi_ucm_app_held_call(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_HOLD_STATE))
        {
            numTotal += g_ucm_p->call_list.group_info[i].num_call;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_make_call
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  call_type       [IN]            Call type
 *  num_uri			[IN]			Number or URI in unicode string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen = 0;

#ifdef __MMI_BG_SOUND_EFFECT__
    U8 num_type = 0;
#endif /* __MMI_BG_SOUND_EFFECT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    unicodeLen = (MMI_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((S8*)num_uri)) ? (mmi_ucs2strlen((S8*)num_uri)) : (MMI_UCM_MAX_NUM_URI_LEN - 1);
    g_ucm_p->mo_info.module_id = MMI_UCM_FROM_IDLE;
    g_ucm_p->mo_info.dial_type = call_type;
    memset(g_ucm_p->mo_info.dial_num.num_uri, 0, MMI_UCM_MAX_NUM_URI_LEN);
    mmi_ucs2_n_to_asc((S8*)g_ucm_p->mo_info.dial_num.num_uri, (S8*)num_uri, unicodeLen * ENCODING_LENGTH);

#ifdef __MMI_BG_SOUND_EFFECT__

    num_type = applib_ss_string_parsing((U8*)g_ucm_p->mo_info.dial_num.num_uri, (U8)unicodeLen);

    if (mmi_bgsnd_common_get_mo_bgs_permit_state() &&
        ((call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) || (call_type == MMI_UCM_VOIP_CALL_TYPE)) &&
        mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) == 0 &&
        mmi_ucm_emergency_call_present() == FALSE &&
        num_type == CC_OPERATION &&
    #ifdef __CTM_SUPPORT__
        (mmi_gsm_ctm_is_on() == FALSE) &&
    #endif /* __CTM_SUPPORT__ */ 
        mmi_ucm_is_sos_number(g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.dial_num.num_uri) == FALSE &&
        mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF)
    {        
        if (g_ucm_p->call_misc.is_bgs_selected == FALSE)
        {
            /* select background sound effect */
            mmi_ucm_entry_bgs_effect_select();

            return;
        }
        else
        {
            /* reset the flag and continue outgoing call procedure */
            g_ucm_p->call_misc.is_bgs_selected = FALSE;

            /* delete idle dial pad related screens */
            mmi_idle_delete_dialpad_from_history();
        }
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */
    
    mmi_ucm_outgoing_call_sendkey();

    /* abort auto redial if necessary */
    if (GetExitScrnID() == SCR_ID_UCM_AUTO_REDIAL || IsScreenPresent(SCR_ID_UCM_AUTO_REDIAL))
    {
        StopTimer(UCM_AUTO_REDIAL_TIMER);
        ClearDelScrnIDCallbackHandler(SCR_ID_UCM_AUTO_REDIAL, NULL);
        
        if (GetExitScrnID() == SCR_ID_UCM_AUTO_REDIAL)
        {
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        }

        DeleteScreenIfPresent(SCR_ID_UCM_AUTO_REDIAL);
        if (g_ucm_p->auto_redial.abort_hdlr)
        {
            g_ucm_p->auto_redial.abort_hdlr();                
        }
        memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_make_call_with_source
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  call_type       [IN]            Call type
 *  num_uri			[IN]			Number or URI in unicode string
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_app_make_call_with_source(mmi_ucm_module_origin_enum module_id, mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen = 0;
    U8* num_uri_ascii = NULL;
    MMI_BOOL result = TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bootup_get_active_flight_mode()))
    {
        result = FALSE;
        return result;
    }
#ifdef __MMI_WLAN_FEATURES__
    else if ((mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY) && (call_type != MMI_UCM_VOIP_CALL_TYPE))
    {
        result = FALSE;
        return result;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else if (mmi_ucm_is_pending_action() == MMI_TRUE)
    {
        result = FALSE;
        return result;
    }

    unicodeLen = (MMI_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((S8*)num_uri)) ? (mmi_ucs2strlen((S8*)num_uri)) : (MMI_UCM_MAX_NUM_URI_LEN - 1);
    num_uri_ascii = OslMalloc((unicodeLen + 1) * ENCODING_LENGTH);
    memset(num_uri_ascii, 0, (unicodeLen + 1) * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((S8*)num_uri_ascii, (S8*)num_uri, unicodeLen * ENCODING_LENGTH);
    
    /* do not check sos number for SAT call */
    if ((module_id != MMI_UCM_FROM_SAT) && (mmi_ucm_is_sos_number(call_type, num_uri_ascii) == TRUE))
    {
        if (mmi_ucm_is_sos_in_call_list() == FALSE)
        {
        #if defined(__MMI_DUAL_SIM_MASTER__)
            mmi_ucm_set_call_channel(call_type);
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            g_ucm_p->mo_info.module_id = module_id;
            g_ucm_p->mo_info.dial_type = call_type;
            memset(g_ucm_p->mo_info.dial_num.num_uri, 0, MMI_UCM_MAX_NUM_URI_LEN);
            mmi_ucs2_n_to_asc((S8*)g_ucm_p->mo_info.dial_num.num_uri, (S8*)num_uri, unicodeLen * ENCODING_LENGTH);

            /* If CSD number is ECC, the CSD call fails while ECC voice should be dialed. */
            if (call_type & MMI_UCM_CSD_CALL_TYPE)
            {
                g_ucm_p->mo_info.dial_type = MMI_UCM_VOICE_CALL_TYPE;
            
                if (g_ucm_p->mo_info.module_id == MMI_UCM_FROM_ABM)
                {
                    g_ucm_p->mo_info.module_id = MMI_UCM_FROM_IDLE;
                }
                result = FALSE;
            }
            else if (call_type & MMI_UCM_CSD_CALL_TYPE_SIM2)
            {
                g_ucm_p->mo_info.dial_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;

                if (g_ucm_p->mo_info.module_id == MMI_UCM_FROM_ABM)
                {
                    g_ucm_p->mo_info.module_id = MMI_UCM_FROM_IDLE;
                }
                result = FALSE;                
            }

            if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) != 0)
            {
                PRINT_INFORMATION("\n[mmi_ucm_app_make_call_with_source] End All Calls before Dial SOS\n");
                g_ucm_p->mo_info.is_wait_dial = TRUE;
                mmi_ucm_end_all_action();
            }
            else
            {            
                PRINT_INFORMATION("\n[mmi_ucm_app_make_call_with_source] Directly Dial SOS\n");
                g_ucm_p->mo_info.is_wait_dial = TRUE;
                mmi_ucm_dial_action();
            }
        }
        else /* not allow to dial this sos number */
        {
            result = FALSE;
        }        
    }
    else /* not a sos number */
    {
        if (!strlen((S8*)num_uri_ascii)) /* empty number */
        {
            result = FALSE;
        }
        else if ((!mmi_bootup_is_sim_valid()) && 
                 (call_type != MMI_UCM_VOIP_CALL_TYPE) && 
                 !(call_type & MMI_UCM_SIM2_CALL_TYPE_ALL))
        {
            result = FALSE;
        }
    #if defined(__MMI_DUAL_SIM_MASTER__)
        else if ((!mmi_bootup_is_sim2_valid()) &&
                 (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL))
        {
            result = FALSE;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        /* Data/CSD call priority is lower than voice call priority. */
        else if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) && (call_type & (MMI_UCM_CALL_TYPE_DATA_CSD_ALL)))
        {
            result = FALSE;
        }
        else if ((mmi_ucm_is_busy() == FALSE) && (mmi_ucm_dial_option() == TRUE))
        {
        #if defined(__MMI_DUAL_SIM_MASTER__)
            mmi_ucm_set_call_channel(call_type);
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            g_ucm_p->mo_info.module_id = module_id;
            g_ucm_p->mo_info.dial_type = call_type;
            memset(g_ucm_p->mo_info.dial_num.num_uri, 0, MMI_UCM_MAX_NUM_URI_LEN);
            mmi_ucs2_n_to_asc((S8*)g_ucm_p->mo_info.dial_num.num_uri, (S8*)num_uri, unicodeLen * ENCODING_LENGTH);
        
            if ((g_ucm_p->mo_info.dial_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                (SS_OPERATION == applib_ss_string_parsing((U8*)g_ucm_p->mo_info.dial_num.num_uri, (U8)strlen((S8*)g_ucm_p->mo_info.dial_num.num_uri))))
            {
                /* dial directly if SS operation or SIM operation */
                mmi_ucm_dial_action();
            }
            else if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_DATA_CSD_ALL) && (g_ucm_p->mo_info.dial_type & MMI_UCM_CALL_TYPE_NO_DATA_CSD))
            {
                /* normal call and data call cannot co-exist */
                PRINT_INFORMATION("\n[mmi_ucm_app_make_call_with_source] End All Calls before Dial %d\n", g_ucm_p->mo_info.dial_type);
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
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
    }

    if (result == TRUE)
    {
        /* abort auto redial if necessary */
        if (GetExitScrnID() == SCR_ID_UCM_AUTO_REDIAL ||
            IsScreenPresent(SCR_ID_UCM_AUTO_REDIAL))
        {
            StopTimer(UCM_AUTO_REDIAL_TIMER);
            ClearDelScrnIDCallbackHandler(SCR_ID_UCM_AUTO_REDIAL, NULL);
            
            if (GetExitScrnID() == SCR_ID_UCM_AUTO_REDIAL)
            {
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            }

            DeleteScreenIfPresent(SCR_ID_UCM_AUTO_REDIAL);
            if (g_ucm_p->auto_redial.abort_hdlr)
            {
                g_ucm_p->auto_redial.abort_hdlr();                
            }
            memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));
        }
    }

    OslMfree(num_uri_ascii);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_headset_key
 * DESCRIPTION
 *  Handle headset key after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_headset_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* incoming call exists, headset key is to answer it */
    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
    {
        PRINT_INFORMATION("\n[mmi_ucm_app_headset_key] Answer Incoming Call\n");
        mmi_ucm_incoming_call_sendkey();
    }
    /* outgoing call exists, headset key is to abort it */
    else if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
    {
        PRINT_INFORMATION("\n[mmi_ucm_app_headset_key] Abort Outgoing Call\n");
        mmi_ucm_outgoing_call_endkey();
    }
    /* in call, headset key is to release current highlight tab call */
    else if (g_ucm_p->call_list.num_group > 0)
    {
        PRINT_INFORMATION("\n[mmi_ucm_app_headset_key] Release Highlight Tab Call\n");
        mmi_ucm_in_call_endkey();
    }
}


#ifdef __MMI_CLAMSHELL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_clam_open
 * DESCRIPTION
 *  Handle clam open after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_clam_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ANSWERING_MODE ansMode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clam open accept call will only take effect when there is no pending action */
    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
    {
        PRINT_INFORMATION("\n[mmi_ucm_app_clam_open] No Pending Action\n");
        memcpy(&ansMode, GetAnsweringMode(), sizeof(MMI_ANSWERING_MODE));
        if ((ansMode.coverAnswer == TRUE) && (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0))
        {
            PRINT_INFORMATION("\n[mmi_ucm_app_clam_open] Ready to Answer Incoming Call\n");
            mmi_ucm_incoming_call_sendkey();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_clam_close
 * DESCRIPTION
 *  Handle clam close after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_clam_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
    {                
        PRINT_INFORMATION("\n[mmi_ucm_app_clam_close] In Call, Ready to End All Calls\n");
        mmi_ucm_end_all_action();
    }
}
#endif /* __MMI_CLAMSHELL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_get_marker_scrn_id
 * DESCRIPTION
 *  get marker screen id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_ucm_app_get_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SCR_ID_UCM_MARKER;
}


/*****************************************************************************
 * FUNCTION
 *  isInCall
 * DESCRIPTION
 *  For other application to check if it is in-call
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in call.
 *  FALSE means it is not in call.
 *****************************************************************************/
pBOOL isInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  isOutgoingCall
 * DESCRIPTION
 *  For other application to check if outgoing call exists
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means outgoing call exists.
 *  FALSE means outgoing call not exists.
 *****************************************************************************/
pBOOL isOutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  isIncomingCall
 * DESCRIPTION
 *  For other application to check if incoming call exists
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means incoming call exists.
 *  FALSE means incoming call not exists.
 *****************************************************************************/
pBOOL isIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  IsWapCallPresent
 * DESCRIPTION
 *  check if wap call present
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL IsWapCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetWapCallPresent
 * DESCRIPTION
 *  check if wap call present
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetWapCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsWapCallPresent();
}


/*****************************************************************************
 * FUNCTION
 *  IsFaxCallPresent
 * DESCRIPTION
 *  check if fax call present
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL IsFaxCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_DATA_CALL_TYPE_ALL) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CBackCallDeflectNumberFromPB
 * DESCRIPTION
 *  Call deflect function specific for phonebook
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CBackCallDeflectNumberFromPB(PS8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ucm_p->mo_info.dial_pad_buffer, 0x00, sizeof(g_ucm_p->mo_info.dial_pad_buffer));
    mmi_ucs2ncpy((S8*)g_ucm_p->mo_info.dial_pad_buffer, (S8*)number, MMI_UCM_MAX_NUM_URI_LEN);
    mmi_ucm_deflect();   
}


/*****************************************************************************
 * FUNCTION
 *  IsPhoneInMute
 * DESCRIPTION
 *  This function informs whethere the phone is in mute or not.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  U16(?)      [OUT]       
 * RETURNS
 *  returns TRUE if muted else FALSE
 *****************************************************************************/
U16 IsPhoneInMute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16)g_ucm_p->call_misc.is_mute;
}


/*****************************************************************************
 * FUNCTION
 *  MutethePhone
 * DESCRIPTION
 *  This function mutes the phone i,e currently changing the global flag.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  changes(?)      [OUT]       The value of gPhoneinMute.
 * RETURNS
 *  void
 *****************************************************************************/
void MutethePhone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.is_mute = TRUE;
    MuteOnMicrophone();
    ShowStatusIcon(STATUS_ICON_MUTE);
    UpdateStatusIcons();   
}


/*****************************************************************************
 * FUNCTION
 *  UnMutethePhone
 * DESCRIPTION
 *  This function informs whethere the phone is in mute or not.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  U16(?)      [OUT]       
 * RETURNS
 *  returns TRUE if muted else FALSE(?)
 *****************************************************************************/
void UnMutethePhone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.is_mute = FALSE;
    MuteOffMicrophone();
    HideStatusIcon(STATUS_ICON_MUTE);
    UpdateStatusIcons();    
}

#endif /* __MMI_UCM__ */

