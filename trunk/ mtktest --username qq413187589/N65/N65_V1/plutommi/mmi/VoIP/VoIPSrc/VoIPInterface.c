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
 *  VoIPInterface.c
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
#include "CallManagementStruct.h"
#include "CallsGprots.h"
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#endif
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "PhoneBookTypes.h"
#include "ProfileGprots.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UCMCallProt.h"
#endif /* __MMI_UCM__ */

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_register_state
 * DESCRIPTION
 *  Get VoIP register state. Mainly for preferred mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  VoIP register state, either MMI_VOIP_DEREG_STATE, MMI_VOIP_PROCESS_STATE, or MMI_VOIP_REG_STATE.
 *****************************************************************************/
mmi_voip_reg_state_enum mmi_voip_app_get_register_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->reg_state_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_make_call
 * DESCRIPTION
 *  Make a VoIP call to the given URI. Mainly for phonebook and call history.
 * PARAMETERS
 *  unicodeUri      [IN]        Destination uri in unicode string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_app_make_call(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 uriLen = 0;
    MMI_BOOL fromPhb = FALSE, fromLog = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
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
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
#endif

    uriLen = (VOIP_URI_LEN > mmi_ucs2strlen((S8*)unicodeUri)) ?
        (mmi_ucs2strlen((S8*)unicodeUri)) : (VOIP_URI_LEN - 1);
    
    memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_misc_info.dispUri, (S8*)unicodeUri, uriLen);
    
    fromPhb = mmi_voip_set_outgoing_origin_app(MMI_VOIP_PHB);
    fromLog = mmi_voip_set_outgoing_origin_app(MMI_VOIP_HISTORY);
    /* cannot dial from phonebook and dial from call log simultaneously */
    MMI_ASSERT(!(fromPhb == TRUE && fromLog == TRUE));
    
    mmi_voip_pre_dial();

    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* reset dial from phonebook flag */
    CHISTSetDialFromCallLogFlag(0);                 /* reset dial from call history flag */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_total_call
 * DESCRIPTION
 *  Total number of voip calls, including outgoing call, incoming call,
 *  active call, held call, etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 means voip not in-call, !0 means voip in-call.
 *****************************************************************************/
S32 mmi_voip_app_total_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->call_list_info.numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_set_conn_flag
 * DESCRIPTION
 *  Set the flag before disconnecting the other type of call.
 *  After disconnecting successfully, connect the given type of call.
 *  Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  needConn        [IN]        Need to connect what type of call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_app_set_conn_flag(mmi_voip_call_conn_enum needConn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.needConn = needConn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_conn_flag
 * DESCRIPTION
 *  Get the flag before connecting call so that we know what type of call that needs to connect.
 *  Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_VOIP_CALL_CONN_NONE means no need to connect call;
 *  MMI_VOIP_CALL_CONN_GSM means to connect gsm call;
 *  MMI_VOIP_CALL_CONN_VOIP means to connect voip call.
 *****************************************************************************/
mmi_voip_call_conn_enum mmi_voip_app_get_conn_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->call_list_info.needConn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_marker_screen
 * DESCRIPTION
 *  Get VoIP marker screen id so that other application can insert its screen 
 *  before VoIP call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  VoIP marker screen id.
 *****************************************************************************/
U16 mmi_voip_app_get_marker_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SCR_ID_VOIP_MARKER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_headsetkey
 * DESCRIPTION
 *  Handle headset key after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_headsetkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* incoming call exists, headset key is to answer it */
    if (mmi_voip_get_incoming_call_id() != -1)
    {
        PRINT_INFORMATION("\n[mmi_voip_entry_headsetkey] Answer Incoming Call\n");
        mmi_voip_entry_answer_call();
    }
    /* outgoing call exists, headset key is to abort it */
    else if (mmi_voip_get_outgoing_call_id() != -1)
    {
        PRINT_INFORMATION("\n[mmi_voip_entry_headsetkey] Abort Outgoing Call\n");
        mmi_voip_entry_abort_call();
    }
    /* in call, headset key is to release current highlight tab call */
    else if (g_voip_cntx_p->call_list_info.numTotal > 0)
    {
        PRINT_INFORMATION("\n[mmi_voip_entry_headsetkey] Release Highlight Tab Call\n");
        mmi_voip_entry_in_call_endkey();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_need_msg_waiting_ind
 * DESCRIPTION
 *  Display message waiting screen in idle screen or not. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means need to show message waiting screen in idle;
 *  FALSE means need not to show message waiting screen in idle.
 *****************************************************************************/
U8 mmi_voip_need_msg_waiting_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->msg_waiting_info.isDisp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_msg_waiting_ind
 * DESCRIPTION
 *  Message waiting screen in idle screen. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_msg_waiting_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lskStr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_voip_cntx_p->msg_waiting_info.mwiStr, 0, MMI_VOIP_MAX_STRING_LEN);
    mmi_voip_get_mwi_string((U8*)g_voip_cntx_p->msg_waiting_info.mwiStr);

    if (mmi_voip_is_keypad_lock_state() == FALSE)
    {
        EntryNewScreen(SCR_ID_VOIP_MSG_WAITING, NULL, mmi_voip_entry_msg_waiting_ind, NULL);
        if ((g_voip_cntx_p->msg_waiting_info.mwiType == STR_ID_VOIP_VOICE_MESSAGE) &&
            (!strlen((S8*) g_voip_cntx_p->msg_waiting_info.mwiAcct)))
        {
            lskStr = STR_ID_VOIP_DIAL;
            memset(g_voip_cntx_p->call_misc_info.dispUri, 0, VOIP_URI_LEN);
            mmi_asc_n_to_ucs2(
                (S8*) g_voip_cntx_p->call_misc_info.dispUri,
                (S8*) g_voip_cntx_p->msg_waiting_info.mwiAcct,
                VOIP_URI_LEN);
        }
        else
        {
            lskStr = 0;
        }
        ShowCategory141Screen(
            g_voip_cntx_p->msg_waiting_info.mwiType,
            GetRootTitleIcon(MENU_ID_VOIP_MAIN),
            lskStr,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)g_voip_cntx_p->msg_waiting_info.mwiStr,
            IMG_ID_VOIP_MSG_WAITING,
            NULL);
        if (lskStr)
        {
            SetLeftSoftkeyFunction(mmi_voip_pre_dial, KEY_EVENT_UP);
        }
        SetRightSoftkeyFunction(mmi_voip_go_back_to_idle, KEY_EVENT_UP);
        SetKeyHandler(mmi_voip_go_back_to_idle, KEY_END, KEY_EVENT_DOWN);
    }
    else    /* keypad lock */
    {
        ShowCategory141Screen(
            g_voip_cntx_p->msg_waiting_info.mwiType,
            GetRootTitleIcon(MENU_ID_VOIP_MAIN),
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*)g_voip_cntx_p->msg_waiting_info.mwiStr,
            IMG_ID_VOIP_MSG_WAITING,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_idle
 * DESCRIPTION
 *  Handle RSK and END key in message waiting screen. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->msg_waiting_info.isDisp = FALSE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_msg_waiting_popup
 * DESCRIPTION
 *  Message waiting popup in other application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_msg_waiting_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_POPUP_SCREEN, NULL, NULL, NULL);
    strId = g_voip_cntx_p->msg_waiting_info.mwiType;
    ShowCategory65Screen((U8*) GetString(strId), IMG_GLOBAL_OK, NULL);
    SetGroupKeyHandler(NULL, (U16*) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(GoBackHistory, (U16*) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_call_list
 * DESCRIPTION
 *  Assign VoIP call list to UCM call list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_call_list(mmi_ucm_sync_call_list_struct *callList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(callList, 0, sizeof(mmi_ucm_sync_call_list_struct));
    
    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
        {        
            callList->call_info[numTotal].uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
            callList->call_info[numTotal].uid_info.group_id = g_voip_cntx_p->call_list_info.call_info[i].callId;
            callList->call_info[numTotal].uid_info.call_id = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId;
            mmi_voip_ucm_get_log_name(
                callList->call_info[numTotal].uid_info.group_id, 
                callList->call_info[numTotal].uid_info.call_id, 
                callList->call_info[numTotal].remote_info.log_name);
            mmi_voip_ucm_get_disp_name(
                callList->call_info[numTotal].uid_info.group_id, 
                callList->call_info[numTotal].uid_info.call_id, 
                callList->call_info[numTotal].remote_info.disp_name);
            memcpy(callList->call_info[numTotal].remote_info.num_uri, g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].remoteUri, VOIP_URI_LEN);
            callList->call_info[numTotal].call_state = g_voip_cntx_p->call_list_info.call_info[i].currState;
            MMI_ASSERT(callList->call_info[numTotal].call_state >= MMI_UCM_IDLE_STATE && callList->call_info[numTotal].call_state < MMI_UCM_CALL_STATE_TOTAL);         
            numTotal++;
        }
    }    
    callList->call_type = MMI_UCM_VOIP_CALL_TYPE;    
    callList->total_num = numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_log_name
 * DESCRIPTION
 *  Assign VoIP display name or application name to UCM log name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_log_name(S32 callId, S32 dialogId, U16* logName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(logName, 0, (MMI_UCM_MAX_DISP_NAME_LEN * sizeof(U16)));
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);
    
    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)logName,
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
            VOIP_DISP_NAME_LEN);
    }
    else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)logName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 
            VOIP_DISP_NAME_LEN);
    }
    else
    {
        PRINT_INFORMATION("\n[mmi_voip_ucm_get_log_name] Log Name Empty\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_disp_name
 * DESCRIPTION
 *  Assign VoIP display name, application name, or uri to UCM display name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_disp_name(S32 callId, S32 dialogId, U16 *dispName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dispName, 0, (MMI_UCM_MAX_DISP_NAME_LEN * sizeof(U16)));
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);

    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
            VOIP_DISP_NAME_LEN);
    }
    else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 
            VOIP_DISP_NAME_LEN);
    }
    else
    {
        mmi_asc_n_to_ucs2(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
            VOIP_URI_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_num_uri
 * DESCRIPTION
 *  Assign VoIP uri to UCM num and uri.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_num_uri(S32 callId, S32 dialogId, U8* numUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(numUri, 0, MMI_UCM_MAX_NUM_URI_LEN);
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);

    memcpy(numUri, g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, VOIP_URI_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_speech_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_speech_direction(S32 rtpDirection, MMI_BOOL *localSwitch, MMI_BOOL *remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtpDirection)
    {
        case VOIP_RTP_DIRECTION_SENDRECV: /* send and receive */
            *localSwitch = TRUE;
            *remoteSwitch = TRUE;
            break;
        case VOIP_RTP_DIRECTION_SENDONLY: /* send only */
            *localSwitch = TRUE;
            *remoteSwitch = FALSE;
            break;
        case VOIP_RTP_DIRECTION_RECVONLY: /* receive only */
            *localSwitch = FALSE;
            *remoteSwitch = TRUE;
            break;
        case VOIP_RTP_DIRECTION_INACTIVE: /* inactive */
            *localSwitch = FALSE;
            *remoteSwitch = FALSE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_rtp_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_rtp_direction(MMI_BOOL localSwitch, MMI_BOOL remoteSwitch, S32 *rtpDirection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((localSwitch == TRUE) && (remoteSwitch == TRUE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_SENDRECV;
    }
    else if ((localSwitch == TRUE) && (remoteSwitch == FALSE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_SENDONLY;
    }
    else if ((localSwitch == FALSE) && (remoteSwitch == TRUE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_RECVONLY;
    }
    else
    {
        *rtpDirection = VOIP_RTP_DIRECTION_INACTIVE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_req(U8 opCode, void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (opCode)
    {
        case MMI_UCM_DIAL:
        case MMI_UCM_HOLD_AND_DIAL:
            mmi_voip_ucm_dial_req(actStruct);
            break;        
        case MMI_UCM_ACCEPT:
        case MMI_UCM_HOLD_AND_ACCEPT:
            mmi_voip_ucm_accept_req(actStruct);
            break;
        case MMI_UCM_HOLD:
            mmi_voip_ucm_hold_req(actStruct);
            break;
        case MMI_UCM_RETRIEVE:
            mmi_voip_ucm_retrieve_req(actStruct);
            break;
        case MMI_UCM_SWAP:
            mmi_voip_ucm_swap_req(actStruct);
            break;
        case MMI_UCM_CONFERENCE:
            mmi_voip_ucm_conference_req(actStruct);
            break;
        case MMI_UCM_SPLIT:
            mmi_voip_ucm_split_req(actStruct);
            break;
        case MMI_UCM_TRANSFER:
            mmi_voip_ucm_transfer_req(actStruct);
            break;
        case MMI_UCM_END_SINGLE:
            mmi_voip_ucm_end_single_req(actStruct);
            break;
        case MMI_UCM_END_CONFERENCE:
            mmi_voip_ucm_end_conference_req(actStruct);
            break;
        case MMI_UCM_END_ALL:
            mmi_voip_ucm_end_all_req(actStruct);
	        break;
        case MMI_UCM_FORCE_RELEASE:
            break;
        case MMI_UCM_AUTO_REJECT:
            mmi_voip_ucm_background_reject_req(actStruct);
            break;
        case MMI_UCM_START_DTMF:
            mmi_voip_ucm_start_dtmf(actStruct);
            break;
        case MMI_UCM_STOP_DTMF:
            mmi_voip_ucm_stop_dtmf(actStruct);
            break;
        default:
            MMI_ASSERT(0); /* not valid action */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_dial_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_dial_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 asciiLen = 0;
    mmi_ucm_dial_req_struct *dialReq = (mmi_ucm_dial_req_struct*)actStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    asciiLen = (VOIP_URI_LEN > strlen((S8*)dialReq->num_uri)) ? (strlen((S8*)dialReq->num_uri)) : (VOIP_URI_LEN - 1);
    memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2((S8*)g_voip_cntx_p->call_misc_info.dispUri, (S8*)dialReq->num_uri, asciiLen);
    
    mmi_voip_set_outgoing_origin_app(MMI_VOIP_PHB);
    mmi_voip_set_outgoing_origin_app(MMI_VOIP_HISTORY);
    
    mmi_voip_pre_dial();

    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* reset dial from phonebook flag */
    CHISTSetDialFromCallLogFlag(0);                 /* reset dial from call history flag */   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_accept_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_accept_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mtcallId = 0, activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mtcallId = mmi_voip_get_incoming_call_id();
    if (mtcallId != -1)
    {    
        activecallId = mmi_voip_get_active_call_id();
        if (activecallId != -1)
        {
            mmi_ucm_multiple_call_struct *acceptReq = (mmi_ucm_multiple_call_struct*)actStruct;
        
            MMI_ASSERT(acceptReq->active_uid.group_id == activecallId); /* active call id does not match */
            MMI_ASSERT(acceptReq->other_uid.group_id == mtcallId); /* incoming call id does not match */
            mmi_voip_switch_session(MMI_VOIP_ACTIVE_STATE);
            mmi_voip_hold_and_accept_req(acceptReq->active_uid.group_id, acceptReq->other_uid.group_id);
        }
        else
        {
            mmi_ucm_single_call_struct *acceptReq = (mmi_ucm_single_call_struct*)actStruct;
            
            MMI_ASSERT(acceptReq->action_uid.group_id == mtcallId); /* incoming call id does not match */
            mmi_voip_switch_session(MMI_VOIP_ACTIVE_STATE);
            mmi_voip_accept_req(acceptReq->action_uid.group_id);
        }
    }
    else
    {
        MMI_ASSERT(mtcallId != -1); /* incoming call does not exist */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_hold_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_hold_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_single_call_struct *holdReq = (mmi_ucm_single_call_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_hold_req(holdReq->action_uid.group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_retrieve_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_retrieve_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_single_call_struct *retrieveReq = (mmi_ucm_single_call_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_retrieve_req(retrieveReq->action_uid.group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_swap_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_swap_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_multiple_call_struct *swapReq = (mmi_ucm_multiple_call_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_swap_req(swapReq->other_uid.group_id, swapReq->active_uid.group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_conference_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_conference_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_conf_req_struct *confReq = (mmi_ucm_conf_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_merge_req(confReq->active_group, confReq->held_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_split_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_split_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_split_req_struct *splitReq = (mmi_ucm_split_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_split_req(splitReq->active_group, splitReq->split_call);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_transfer_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_transfer_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_cd_or_ct_req_struct *transferReq = (mmi_ucm_cd_or_ct_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
    memcpy(g_voip_cntx_p->call_misc_info.inputUri, transferReq->num_uri, MMI_UCM_MAX_NUM_URI_LEN);
    mmi_voip_transfer_req(transferReq->action_uid.group_id, transferReq->action_uid.call_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_single_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_single_call_struct *releaseReq = (mmi_ucm_single_call_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_outgoing_call(MMI_UCM_VOIP_CALL_TYPE))
    {
        mmi_voip_entry_abort_call();
    }
    else
    {
        /* set all rtp directions as inactive before action */
        mmi_voip_switch_rtp(TRUE, -1, -1);
        mmi_voip_release_req(releaseReq->action_uid.group_id, releaseReq->action_uid.call_id);
        mmi_voip_force_release_req(releaseReq->action_uid.group_id, releaseReq->action_uid.call_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_conference_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_conference_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_end_conf_req_struct *releaseReq = (mmi_ucm_end_conf_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(releaseReq->action_group, -1);
    mmi_voip_force_release_req(releaseReq->action_group, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_all_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_all_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(-1, -1);
    mmi_voip_force_release_req(-1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_background_reject_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_background_reject_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_single_call_struct *releaseReq = (mmi_ucm_single_call_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_voip_background_reject_req(releaseReq->action_uid.group_id, releaseReq->action_uid.call_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_start_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_start_dtmf(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_voip_dtmf_key_down();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_stop_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_stop_dtmf(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_voip_dtmf_key_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_dial_act_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opCode          [IN]            Operation code
 *  groupId         [IN]            VoIP call id
 *  callId          [IN]            VoIP dialog id
 *  result          [IN]            Result, TRUE or FALSE
 *  dispMsg         [IN]            Error message if result is FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_dial_act_rsp(U8 opCode, S32 groupId, S32 callId, U8 result, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_dial_act_rsp_struct *dialRsp = OslMalloc(sizeof(mmi_ucm_dial_act_rsp_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dialRsp, 0, sizeof(mmi_ucm_dial_act_rsp_struct));
    dialRsp->result_info.result = result;
    dialRsp->result_info.error_msg = dispMsg;
    mmi_ucs2ncpy((S8*)dialRsp->remote_info.log_name, (S8*)g_voip_cntx_p->call_originapp_info.dispName, VOIP_DISP_NAME_LEN);
    if (mmi_ucs2strlen((S8*)dialRsp->remote_info.log_name))
    {
        mmi_ucs2ncpy((S8*)dialRsp->remote_info.disp_name, (S8*)g_voip_cntx_p->call_originapp_info.dispName, VOIP_DISP_NAME_LEN);
    }
    else
    {
        mmi_asc_n_to_ucs2((S8*)dialRsp->remote_info.disp_name, (S8*)g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
    }
    memcpy(dialRsp->remote_info.num_uri, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
    dialRsp->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    if (dialRsp->result_info.result == TRUE)
    {
        callList->call_info[callList->total_num].uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
        callList->call_info[callList->total_num].uid_info.group_id = MMI_UCM_INVALID_ID;
        callList->call_info[callList->total_num].uid_info.call_id = MMI_UCM_INVALID_ID;
        mmi_ucs2ncpy((S8*)callList->call_info[callList->total_num].remote_info.log_name, (S8*)dialRsp->remote_info.log_name, MAX_PB_NAME_LENGTH);
        mmi_ucs2ncpy((S8*)callList->call_info[callList->total_num].remote_info.disp_name, (S8*)dialRsp->remote_info.disp_name, MMI_UCM_MAX_DISP_NAME_LEN);
        memcpy(callList->call_info[callList->total_num].remote_info.num_uri, dialRsp->remote_info.num_uri, MMI_UCM_MAX_NUM_URI_LEN);
        callList->call_info[callList->total_num].call_state = MMI_UCM_OUTGOING_STATE;
        callList->total_num++;
    }
    mmi_ucm_dispatch_rsp(opCode, MMI_UCM_VOIP_CALL_TYPE, (void*)dialRsp);
    OslMfree(callList);
    OslMfree(dialRsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opCode          [IN]            Operation code
 *  result          [IN]            Result, TRUE or FALSE
 *  dispMsg         [IN]            Error message if result is FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_rsp(U8 opCode, U8 result, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct *actRsp = OslMalloc(sizeof(mmi_ucm_act_rsp_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(actRsp, 0, sizeof(mmi_ucm_act_rsp_struct));
    actRsp->result_info.result = result;
    actRsp->result_info.error_msg = dispMsg;
    actRsp->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_rsp(opCode, MMI_UCM_VOIP_CALL_TYPE, (void*)actRsp);
    OslMfree(callList);
    OslMfree(actRsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_sync_call_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_sync_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_SYNC_CALL_LIST, (void*)callList);
    OslMfree(callList);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_alert_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_alert_ind(MMI_BOOL localGen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_alert_ind_struct *alertInd = OslMalloc(sizeof(mmi_ucm_alert_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(alertInd, 0, sizeof(mmi_ucm_alert_ind_struct));
    alertInd->call_type = MMI_UCM_VOIP_CALL_TYPE;
    alertInd->local_gen = localGen;
    alertInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_ALERT_IND, (void*)alertInd);
    OslMfree(callList);
    OslMfree(alertInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  groupId         [IN]            VoIP call id
 *  callId          [IN]            VoIP dialog id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_connect_ind(S32 groupId, S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_connect_ind_struct *connectInd = OslMalloc(sizeof(mmi_ucm_connect_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(connectInd, 0, sizeof(mmi_ucm_connect_ind_struct));
    connectInd->uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
    connectInd->uid_info.group_id = groupId;
    connectInd->uid_info.call_id = callId;
    mmi_voip_ucm_get_log_name(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.log_name);
    mmi_voip_ucm_get_disp_name(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.disp_name);
    mmi_voip_ucm_get_num_uri(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.num_uri);
    connectInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_CONNECT_IND, (void*)connectInd);
    OslMfree(callList);
    OslMfree(connectInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_notify_ind(U8* dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_notify_ind_struct *notifyInd = OslMalloc(sizeof(mmi_ucm_notify_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(notifyInd, 0, sizeof(mmi_ucm_notify_ind_struct));
    notifyInd->call_type = MMI_UCM_VOIP_CALL_TYPE;
    notifyInd->disp_msg = dispMsg;
    notifyInd->image_id = imageId;
    notifyInd->tone_id = toneId;
    notifyInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_NOTIFY_IND, (void*)notifyInd);    
    OslMfree(callList);
    OslMfree(notifyInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_session_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_session_ind(U8 sessionType, MMI_BOOL sessionSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_session_ind_struct *sessionInd = OslMalloc(sizeof(mmi_ucm_session_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sessionInd, 0, sizeof(mmi_ucm_session_ind_struct));
    sessionInd->session_type = sessionType;
    sessionInd->session_switch = sessionSwitch;
    sessionInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_SESSION_IND, (void*)sessionInd);   
    OslMfree(callList);
    OslMfree(sessionInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_speech_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_speech_ind(U8 rtpHandle, MMI_BOOL localSwitch, MMI_BOOL remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_speech_ind_struct *speechInd = OslMalloc(sizeof(mmi_ucm_speech_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(speechInd, 0, sizeof(mmi_ucm_speech_ind_struct));
    speechInd->call_type = MMI_UCM_VOIP_CALL_TYPE;
    speechInd->session_type = 0;
    speechInd->rtp_handle = rtpHandle;
    speechInd->local_switch = localSwitch;
    speechInd->remote_switch = remoteSwitch;
    speechInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_SPEECH_IND, (void*)speechInd);
    OslMfree(callList);
    OslMfree(speechInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_ring_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_ring_ind(S32 groupId, S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_ring_ind_struct *ringInd = OslMalloc(sizeof(mmi_ucm_ring_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ringInd, 0, sizeof(mmi_ucm_ring_ind_struct));
    ringInd->uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
    ringInd->uid_info.group_id = groupId;
    ringInd->uid_info.call_id = callId;
    mmi_voip_ucm_get_log_name(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->display_info.log_name);
    mmi_voip_ucm_get_disp_name(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->display_info.disp_name);
    mmi_voip_ucm_get_num_uri(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->display_info.num_uri);
    ringInd->alert_info.tone_id = GetRingToneID();
    ringInd->alert_info.image_info.image_id = IMG_PHB_DEFAULT;
    ringInd->alert_info.alert_type = GetMtCallAlertTypeEnum();
    ringInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_RING_IND, (void*)ringInd);
    OslMfree(callList);
    OslMfree(ringInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_release_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_release_ind(S32 groupId, S32 callId, U8 *dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_release_ind_struct *releaseInd = OslMalloc(sizeof(mmi_ucm_release_ind_struct));
    mmi_ucm_sync_call_list_struct *callList = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(releaseInd, 0, sizeof(mmi_ucm_release_ind_struct));
    releaseInd->uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
    releaseInd->uid_info.group_id = groupId;
    releaseInd->uid_info.call_id = callId;
    releaseInd->disp_msg = dispMsg;
    releaseInd->image_id = imageId;
    releaseInd->tone_id = toneId;
    releaseInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    mmi_ucm_dispatch_ind(MMI_UCM_RELEASE_IND, (void*)releaseInd);
    OslMfree(callList);
    OslMfree(releaseInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_auto_redial_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_auto_redial_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_auto_redial_struct *redialInd = OslMalloc(sizeof(mmi_ucm_auto_redial_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(redialInd, 0, sizeof(mmi_ucm_auto_redial_struct));
    redialInd->call_type = MMI_UCM_VOIP_CALL_TYPE;
    memcpy(redialInd->num_uri, g_voip_cntx_p->call_redial_info.redialUri, VOIP_URI_LEN);
    redialInd->attempt = (U8)g_voip_cntx_p->call_redial_info.currAttempt;
    redialInd->time = MMI_VOIP_GENERAL_TIMEOUT;
    redialInd->abort_hdlr = mmi_voip_entry_abort_redial;
    mmi_ucm_dispatch_ind(MMI_UCM_AUTO_REDIAL_IND, (void*)redialInd);
    OslMfree(redialInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_start_processing_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_start_processing_ind(S32 groupId, S32 callId, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_start_processing_struct *startInd = OslMalloc(sizeof(mmi_ucm_start_processing_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(startInd, 0, sizeof(mmi_ucm_start_processing_struct));
    startInd->uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
    startInd->uid_info.group_id = groupId;
    startInd->uid_info.call_id = callId;
    startInd->content = dispMsg;
    mmi_ucm_dispatch_ind(MMI_UCM_START_PROCESSING_IND, (void*)startInd);
    OslMfree(startInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_stop_processing_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_stop_processing_ind(U8* dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_processing_struct *stopInd = OslMalloc(sizeof(mmi_ucm_stop_processing_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(stopInd, 0, sizeof(mmi_ucm_stop_processing_struct));
    stopInd->disp_msg = dispMsg;
    stopInd->image_id = imageId;
    stopInd->tone_id = toneId;
    mmi_ucm_dispatch_ind(MMI_UCM_STOP_PROCESSING_IND, (void*)stopInd);
    OslMfree(stopInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_control_rtp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_control_rtp(U8 rtpHandle, U8 localSwitch, U8 remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rtpDirection = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_ucm_get_rtp_direction(localSwitch, remoteSwitch, &rtpDirection);
    mmi_voip_control_rtp(rtpHandle, rtpDirection);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_suspend_rtp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_suspend_rtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
        {
            mmi_voip_switch_rtp(TRUE, g_voip_cntx_p->call_list_info.call_info[i].callId, g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId);
        }
    }
}
#endif /* __MMI_UCM__ */
#endif /* __MMI_VOIP__ */

