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
 * SmsPsHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   FILENAME : SmsPsHandler.c

   PURPOSE     : It handles protocol SMS messages. 

   REMARKS     : nil

   AUTHOR      : Magesh K, Hiran 

   DATE     : 01-01-2003

**************************************************************/

#include "MMI_include.h"
#ifdef __MOD_SMSAL__
//
//MTK Joy added for FDN check, 1121, shall be removed
//#define FDN_CHECK_TESTING
//MTK end
/*  */

/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
#ifdef __MMI_MESSAGES_CHAT__
#include "ChatAppGprot.h"
#include "ChatAppResDef.h"
#include "ChatGtype.h"
#include "ChatAppGexdcl.h"
#endif /* __MMI_MESSAGES_CHAT__ */ 
/*  */
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "ems.h"
/*  */
#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
/*  */
#include "gpioInc.h"
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "AlarmFrameworkProt.h"
#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "SimDetectionGexdcl.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
/*  */
#include "wgui_status_icons.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedMessageProt.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#include "FileManagerGprot.h"  

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_PFAL_Master_Msgs.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */
//
//
#ifdef __MMI_OPERATOR_LOGO__
extern void mmi_op_logo_parse_ota_data(void);
#endif 

#ifdef __MMI_CLI_ICON__
extern void mmi_cli_icon_parse_ota_data(void);
#endif 

#ifdef __MMI_MESSAGES_CHAT__
extern pBOOL gOutBoxSaveFlag;
extern U16 gChatMsgFlag;    /* Added By Alok */
#endif /* __MMI_MESSAGES_CHAT__ */ 
extern msg_active_profile_struct activeProfile;
extern U16 processRSKStrId;
extern PS8 lookUpNumber(PS8 number);
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
extern void mmi_phb_sms_enter_send_by_group(void);
extern U16 GetCmMarkerScrnID(void);
extern MMI_PHB_LIST_VIEW phbListView;

extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE);


#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
#include "PicMsgApiToOthers.h"

extern U8 gNSMBuffer[];
extern U8 gaddtext_buffer[];
extern U8 gOTADataBuffer[];

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
extern nsm_msg_struct g_nsm_msg_context;
#endif 
extern S8 g_pmsg_TextInMessage[];
static U16 gMessageType = 0;    /*
                                 * Flag to identify Message type
                                 * * 0 - NORMAL MESSAGE
                                 * * 1 - PICTURE MESSAGE
                                 * * 2 - RINGTONE MESSAGE
                                 */

S32 mmi_nsm_send_pic_msg(U8 *bmpDataPtr, U8 *PicTextPtr, U8 **emsDataT);
U8 mmi_nsm_prepare_msg(U8 *data, S32 data_len);
U8 mmi_nsm_pack_and_send_msg(void);
U16 StuffZerosInBetween(S8 *pOutBuffer, S8 *pInBuffer, U16 size);

#define ASCIISEGMENTSIZE 252
static void mmi_nsm_get_picmsg_sendData(mmi_frm_sms_send_struct *sendData);
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
static S32 ucs2_count = 0;  /* For Sending chinese character with pic msg */
extern nsm_picmsg_text_struct picmsg_text_struct;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
/*******************************************************


            protocol event handler           


*******************************************************/
extern msg_msgbox_info_struct msgbox_info;
extern PendingSaveSendDataStruct PendingSaveSendData;
extern void mmi_phb_sms_enter_send_entry(void);
extern U8 mmi_phb_convert_to_digit(U8 *dest, U8 *source, U8 max_dest_len);

#ifdef __MMI_MESSAGES_SEND_BY_GROUP__
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#endif /* ifdef __MMI_MESSAGES_SEND_BY_GROUP__ */

extern U8 mmi_msg_get_seg_num(void);
extern U16 mmi_msg_get_msgbox_size(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_ready_ind(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
	if ( mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
	{
		return;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */    
    g_msg_cntx.msg_init = TRUE;
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
    RefreshMessagesMenuList();
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_msg_set_msg_icon(FALSE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    /* it is in the processing screen or the processing screen has been interrupted */
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_PROCESSING || IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        if (processRSKStrId == STR_LOADING_INBOX_BACK)
        {
            mmi_msg_entry_inbox_list();
            /* if the processing screen is in the history after entry inbox list */
            DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
        }
        else if (processRSKStrId == STR_LOADING_OUTBOX_BACK)
        {
            mmi_msg_entry_outbox_list();
            /* if the processing screen is in the history after entry outbox list */
            DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
        }
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        else if (processRSKStrId == STR_LOADING_DRAFTBOX_BACK)
        {
            mmi_msg_entry_draftbox_list();
            /* if the processing screen is in the history after entry draftbox list */
            DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
        }
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }

#ifdef __MMI_UNIFIED_MESSAGE__
	if (mmi_bootup_is_sim_valid())
	{
    	mmi_msg_send_ready_ind(KAL_TRUE);
	}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_sync_msgbox_with_at
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_sync_msgbox_with_at(void *dummy, module_type mod, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 todelscrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_INBOX_LIST_OPTION || IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        todelscrid = SCR_ID_MSG_INBOX_LIST_OPTION;
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_OUTBOX_LIST_OPTION || IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        todelscrid = SCR_ID_MSG_OUTBOX_LIST_OPTION;
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_DEFAULT_LIST_OPTION || IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        todelscrid = SCR_ID_MSG_DEFAULT_LIST_OPTION;
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (GetMessagesCurrScrnID() == SCR_ID_MSG_INBOX_MSG || IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        todelscrid = SCR_ID_MSG_INBOX_MSG;
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_OUTBOX_MSG || IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        todelscrid = SCR_ID_MSG_OUTBOX_MSG;
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_DEFAULT_MSG || IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        todelscrid = SCR_ID_MSG_DEFAULT_MSG;
    }

    /* For L4C_AT_SMS_ADD, the refresh ind would be sent in mmi_frm_sms_get_sms_rsp() */
    if (type != L4C_AT_SMS_ADD)
    {
        mmi_msg_send_refresh_ind(UM_MSG_BOX_TYPE_INBOX | UM_MSG_BOX_TYPE_UNSENT | UM_MSG_BOX_TYPE_SENT |
                                 UM_MSG_BOX_TYPE_DRAFT);
    }

#else /* __MMI_UNIFIED_MESSAGE__ */ 

    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    if (GetMessagesCurrScrnID() == SCR_ID_MSG_INBOX_LIST || IsScreenPresent(SCR_ID_MSG_INBOX_LIST))
    {
        todelscrid = SCR_ID_MSG_INBOX_LIST;
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_OUTBOX_LIST || IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        todelscrid = SCR_ID_MSG_OUTBOX_LIST;
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_DRAFTBOX_LIST || IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST))
    {
        todelscrid = SCR_ID_MSG_DRAFTBOX_LIST;
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /* For the case of SIM Refresh, the msg screens should be deleted in mmi_frm_sms_sim_refresh_ind() */
    /* If the SMS screens cannot be deleted, do not show the done pupup. */
    if (todelscrid != 0 && g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes != 0 && type != L4C_SMS_SIM_REFRESH)
    {
        /* Do not interrupt calling screen */
        if (!isIncomingCall())
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
        }
        SetMessagesScrnIdToDelHistoryNodes(todelscrid);
        DeleteMessagesHistoryNodes();
    }
#ifndef __MMI_UNIFIED_MESSAGE__
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
    RefreshMessagesMenuList();

    /* If the new msg is deleted by AT, the new msg indication screen should not be displayed. */
    if (GetExitScrnID() == SCR_ID_MSG_NEW_MSG_IND &&
        type == L4C_AT_SMS_DELETE)
    {
        EntryIdleScreen();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_msg_set_msg_icon(FALSE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_msg_waiting_ind(void *inMsg, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_MSG_WAITING_IND_STRUCT *msgInd = (MMI_FRM_SMS_MSG_WAITING_IND_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msgInd->is_clear)
    {
    	if (g_msg_cntx.msg_waiting_line_number == msgInd->line_no && g_msg_cntx.msg_waiting_ind == msgInd->ind_type + 1
		#ifdef __MMI_DUAL_SIM_MASTER__
			&& g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].isSlave == FALSE
		#endif
			)
		{
			if (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND)
			{
				mmi_msg_go_back_from_msg_waiting_ind();
			}
			g_msg_cntx.msg_waiting_ind = 0;
        }
        g_msg_cntx.msg_waiting_info[(msgInd->line_no)].number[msgInd->ind_type] = 0;
        mmi_msg_set_msg_waiting_icon(msgInd->line_no, msgInd->ind_type, 0);
    }        
    else
    {
        mmi_msg_set_msg_waiting_icon(msgInd->line_no, msgInd->ind_type, 1);

        g_msg_cntx.msg_waiting_info[(msgInd->line_no)].number[msgInd->ind_type] = msgInd->waiting_num;
	#ifdef __MMI_DUAL_SIM_MASTER__
		g_msg_cntx.msg_waiting_info[(msgInd->line_no)].isSlave = FALSE;
	#endif

        /* Only display icon for message indication in storage, not from network. */
        if (msgInd->is_from_storage)
        {
            return;
        }
        
        g_msg_cntx.msg_waiting_is_show_number = msgInd->is_show_num;        
        g_msg_cntx.msg_waiting_line_number = msgInd->line_no;        
        
        mmi_msg_msg_waiting_ind(msgInd->ind_type);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_deliver_report_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_deliver_report_ind(void *inMsg, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_status_report_ind_struct *msgInd = (mmi_frm_sms_status_report_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STATUS_REPORT_NUM; i++)
    {
        if (g_msg_cntx.msg_deliver_report[i] == NULL)
        {
            break;
        }
    }
    if (i == MAX_STATUS_REPORT_NUM)
    {
        U8 j = 0;

        OslMfree(g_msg_cntx.msg_deliver_report[0]);
        g_msg_cntx.msg_deliver_ind--;
        for (j = 0; j < (MAX_STATUS_REPORT_NUM - 1); j++)
        {
            g_msg_cntx.msg_deliver_report[j] = g_msg_cntx.msg_deliver_report[j + 1];
        }
        g_msg_cntx.msg_deliver_report[j] = NULL;
        i = j;
    }
    g_msg_cntx.msg_deliver_report[i] = OslMalloc(sizeof(msg_deliver_report_struct));
    g_msg_cntx.msg_deliver_report[i]->delivered = msgInd->st;
    if (msgInd->ra_number.type == CSMCC_INTERNATIONAL_ADDR||
        (msgInd->ra_number.type & 0xf0) == 0x90)
    {
        g_msg_cntx.msg_deliver_report[i]->type = 1;
    }
    else
    {
        g_msg_cntx.msg_deliver_report[i]->type = 0;
    }
    memset((S8*) g_msg_cntx.msg_deliver_report[i]->number, 0, MSG_NUM_LEN);
    memcpy((S8*) g_msg_cntx.msg_deliver_report[i]->number, msgInd->ra_number.number, msgInd->ra_number.length);
    memcpy((S8*) g_msg_cntx.msg_deliver_report[i]->timestamp, msgInd->dt, 6);
#ifdef __MMI_DUAL_SIM_MASTER__
	g_msg_cntx.msg_deliver_report[i]->isFromMaster = msgInd->isFromMaster;
#endif
    mmi_msg_deliver_report_ind();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_mem_full_ind(void *inMsg, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_MEM_FULL_IND_STRUCT *msgInd = (MMI_FRM_SMS_MEM_FULL_IND_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->type == SMSAL_MEM_FULL_NORMAL
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        || msgInd->type == SMSAL_ME_FULL_ONLY
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    )
    {
#ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_msg_icon(TRUE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	if ((MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) == MTPNP_AD_CARD1)
	{
		MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
        g_msg_cntx.msg_full_ind = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_exceed_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_mem_exceed_ind(void *inMsg, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_MEM_EXCEED_IND_STRUCT *msgInd = (MMI_FRM_SMS_MEM_EXCEED_IND_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->type == SMSAL_MEM_EXCEED_NORMAL || msgInd->type == SMSAL_SM_EXCEED_WITH_CLASS2)
    {
        g_msg_cntx.msg_exceed_ind = TRUE;
        g_msg_cntx.msg_exceed_type = msgInd->type;
		#ifdef __MMI_DUAL_SIM_MASTER__
			g_msg_cntx.msg_exceed_from_slave = FALSE;
		#endif
        TurnOnBacklight(1);
        if (IsMMIInIdleState())
        {
            ClearKeyEvents();
            if (IsKeyPadLockState())
            {
                EntryIdleScreen();
            }
            else
            {
                mmi_msg_entry_mem_exceed_ind();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_avail_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_mem_avail_ind(void *inMsg, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_MEM_AVAILABLE_IND_STRUCT *msgInd = (MMI_FRM_SMS_MEM_AVAILABLE_IND_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->type == SMSAL_MEM_AVAIL_NORMAL
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        || msgInd->type == SMSAL_ME_AVAIL_ONLY
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    )
    {
        g_msg_cntx.msg_full_ind = FALSE;
        g_msg_cntx.msg_exceed_ind = FALSE;
	#ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_msg_icon(FALSE, TRUE);
	#else /* __MMI_DUAL_SIM_MASTER__ */
		MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_TRUE);
	#endif /* __MMI_DUAL_SIM_MASTER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_class0_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 *  content     [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_msg_handle_class0_msg_ind(void *inMsg, void *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_deliver_msg_struct *msgInd = (mmi_frm_sms_deliver_msg_struct*) inMsg;
    mmi_frm_sms_concat_struct *concatinfo = (mmi_frm_sms_concat_struct*) & (msgInd->concat_info);
    U8 type = 0;
    S16 len = 0;
    S8 *unicodecontent = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_class0_p != NULL)
    {
        if (g_msg_cntx.msg_class0_p->data != NULL)
        {
            OslMfree(g_msg_cntx.msg_class0_p->data);
            g_msg_cntx.msg_class0_p->data = NULL;
        }
        OslMfree(g_msg_cntx.msg_class0_p);
        g_msg_cntx.msg_class0_p = NULL;
    }
    g_msg_cntx.msg_class0_p = OslMalloc(sizeof(msg_class0_msg_struct));
    g_msg_cntx.msg_class0_p->length = msgInd->no_msg_data;
    g_msg_cntx.msg_class0_p->fo = msgInd->fo;
    g_msg_cntx.msg_class0_p->dcs = msgInd->dcs;
    g_msg_cntx.msg_class0_p->totalseg = concatinfo->total_seg;
#ifdef __MMI_DUAL_SIM_MASTER__
	if (msgInd->display_type == MMI_FRM_SMS_TYPE_CLASS0)
	{
		g_msg_cntx.msg_class0_p->isSlave = FALSE;
	}
	else
	{
		g_msg_cntx.msg_class0_p->isSlave = TRUE;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    if (msgInd->addr_number.type == CSMCC_INTERNATIONAL_ADDR ||
        (msgInd->addr_number.type & 0xf0) == 0x90)
    {
        mmi_asc_to_ucs2((S8*) g_msg_cntx.msg_class0_p->number, "+");
        type = 1;
    }
    mmi_asc_n_to_ucs2(
        (S8*) g_msg_cntx.msg_class0_p->number + type * ENCODING_LENGTH,
        (S8*) msgInd->addr_number.number,
        MSG_NUM_LEN);
    memcpy(g_msg_cntx.msg_class0_p->timestamp, msgInd->scts, 6);
    /* content might be unicode or ascii, convert it to unicode and store it to unicodecontent */
    if (g_msg_cntx.msg_class0_p->dcs == SMSAL_UCS2_DCS)
    {
        /* len = (S16)mmi_ucs2strlen(content); */
        len = g_msg_cntx.msg_class0_p->length;
        unicodecontent = OslMalloc(len + 2);
        memcpy(unicodecontent, content, len);
        memset(unicodecontent + len, 0, 2);
    }
    else
    {
        /* len = strlen(content); */
        len = g_msg_cntx.msg_class0_p->length / 2;
        unicodecontent = OslMalloc((len + 1) * 2);
        mmi_msg_ascii_to_usc2(unicodecontent, (S8*)content, len);
        memset(unicodecontent + len * 2, 0, 2);
    }
    /* indicate a class0 message with missing segment with (.....) in the front of message content */
    if (!mmi_frm_sms_check_awaited_complete_msg(msgInd->msg_data[0]))
    {
        S8 ascii_miss_str[] = EMS_MISS_SEG_DELIMIT_STR;
        U16 ascii_miss_str_len = strlen((S8*) ascii_miss_str);
        S8 *unicode_miss_str = NULL;
        U16 unicode_miss_str_len = 0;   /* the byte number of unicode_miss_str */

        unicode_miss_str = OslMalloc((ascii_miss_str_len + 1) * 2);
        mmi_asc_n_to_ucs2(unicode_miss_str, ascii_miss_str, ascii_miss_str_len);
        memset(unicode_miss_str + ascii_miss_str_len * 2, 0, 2);
        unicode_miss_str_len = (U16) mmi_ucs2strlen(unicode_miss_str) * 2;

        /* g_msg_cntx.msg_class0_p->length contains (.....) and the length of unicodecontent */
        g_msg_cntx.msg_class0_p->length = g_msg_cntx.msg_class0_p->length + unicode_miss_str_len;
        g_msg_cntx.msg_class0_p->data = OslMalloc(g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
        memset((S8*) g_msg_cntx.msg_class0_p->data, 0, g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
        memcpy((S8*) g_msg_cntx.msg_class0_p->data, (S8*) unicode_miss_str, unicode_miss_str_len);
        memcpy(
            (S8*) (g_msg_cntx.msg_class0_p->data + unicode_miss_str_len),
            (S8*) unicodecontent,
            (g_msg_cntx.msg_class0_p->length - unicode_miss_str_len));

        /* free unicode_miss_str buffer */
        OslMfree(unicode_miss_str);
        unicode_miss_str = NULL;
    }
    else
    {
        g_msg_cntx.msg_class0_p->data = OslMalloc(g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
        memset((S8*) g_msg_cntx.msg_class0_p->data, 0, g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
        memcpy((S8*) g_msg_cntx.msg_class0_p->data, (S8*) unicodecontent, g_msg_cntx.msg_class0_p->length);
    }
    mmi_msg_class0_msg_ind();
    /* free unicodecontent buffer */
    if (unicodecontent != NULL)
    {
        OslMfree(unicodecontent);
        unicodecontent = NULL;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_new_msg_ind(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = *(U16*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy the message to show, "before" read sms screen it shall be copied again */
    mmi_msg_new_msg_ind(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type;
    U16 list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back to Idle screen if the new msg is deleted by AT or SIM refresh is ongoing. */
    if (!mmi_msg_need_new_msg_ind() || mmi_frm_sms_is_in_sim_refresh())
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        g_msg_cntx.msg_ind_in_idle = FALSE;
        return;
    }

    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (!mmi_frm_sms_check_action_pending())
    {
        mmi_msg_exit_inbox_list_dummy();
    }
    g_msg_cntx.msg_ind_in_idle = FALSE;
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_INBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index);
    mmi_frm_sms_get_list_index(&type, &list_index, g_msg_cntx.msg_ind_index);
    /* map message box index to message list index to get the correct inbox header */
    if (type == MMI_FRM_SMS_APP_INBOX)
    {
	#ifdef __MMI_DUAL_SIM_MASTER__
		if (MTPNP_AD_SMS_Get_Show_Style() == MTPNP_AD_SHOW_DIVIDED)
		{
			if (mmi_frm_msg_is_from_master_sim(g_msg_cntx.msg_ind_index))
			{
				MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_MASTER);
			}
			else
			{
				MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_SLAVE);
			}
		}
		else
		{
			MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_ALL);
		}
	#endif /* __MMI_DUAL_SIM_MASTER__ */ 
        g_msg_cntx.currBoxIndex = list_index;
        if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) != MMI_FRM_SMS_INVALID_INDEX)
        {
            msgbox_info.totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
            msgbox_info.totaloutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
            msgbox_info.totaldraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);
            mmi_msg_set_msg_num_hint(msgbox_info.totalinbox, msgbox_info.totaloutbox, msgbox_info.totaldraftbox);
            RefreshMessagesMenuList();
        }
    }
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_after_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_after_send_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType msg_box_type = mmi_um_get_current_msg_box_type();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_msg_get_post_send_action_type())
    {
        case MMI_SMS_PS_ACTION_SEND_SUCCESS_REMOVE_MSG:
        {
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            DisplayPopup(
                (PU8) GetString(STR_SMS_SENDING_ID),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_SUCCESS),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            break;
        }

        case MMI_SMS_PS_ACTION_MOVE_MSG:
        {
            /* Do nothing. */
            mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_DEFAULT);
            return;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT || msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
    {
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
        }
        else
    #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */    
        {    
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
    if (mmi_nsm_get_msg_type() != NORMAL_MESSAGE)   /* When msg count > 0 */
    {
        if ((IsScreenPresent(SCR_ID_MYPIC_DISPLAY)) && (totalInbox != 0))       /* For pic msg in Inbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
        }
        else if ((IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG)) && (totalOutbox != 0))        /* For pic msg in Outbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
        }
        else if ((IsScreenPresent(SCR_ID_MSG_INBOX_MSG)) && (totalDraftbox != 0))       /* For ringtone in Inbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
        }
    #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
        if (g_nsm_msg_context.is_picmsg == TRUE)
        {
            mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        }
    #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 

    DeleteMessagesHistoryNodes();
    g_msg_cntx.msg_full_ind = FALSE;
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_msg_set_msg_icon(FALSE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	g_msg_cntx.msg_full_ind = FALSE;
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_DEFAULT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_after_send_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_after_send_req(U8 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_delete_sms(mmi_msg_delete_msg_after_send_rsp, MOD_MMI, type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_before_save_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_before_save_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType msg_box_type = mmi_um_get_current_msg_box_type();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_msg_save_msg_with_flag_req(MMI_FRM_SMS_SAVE_HIGHLIGHT_NEW_MSG_IND);
    }
    else
    {
        if (result == MMI_FRM_SMS_MEMINSUFFICIENT)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_MEM_CAP_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }

        if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
        {

            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE_OPTION);
            }
            else
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
                {                        
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
            }

        }
        else
        {
            MMI_ASSERT(0);
        }
        DeleteMessagesHistoryNodes();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_before_save_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_before_save_req(U8 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_delete_sms(mmi_msg_delete_msg_before_save_rsp, MOD_MMI, type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_before_save_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_before_save_pre_check(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mem_status_struct *memorystatus = (msg_mem_status_struct*) data;
        U16 total_storage = memorystatus->simTotal + memorystatus->meTotal;
        U16 used_storage = memorystatus->simUsed + memorystatus->meUsed;
        EMSData *pEMS;
        U8 sms_segment_size = mmi_frm_sms_get_sms_received_size(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);

        GetEMSDataForEdit(&pEMS, 0);

        if (pEMS->Reminder.requiredSegment > (total_storage - used_storage + sms_segment_size))
        {
            mmi_msg_delete_msg_before_save_rsp(NULL, MOD_MMI, MMI_FRM_SMS_MEMINSUFFICIENT);
        }
        else
        {
            mmi_msg_delete_msg_before_save_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_before_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_before_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_get_memory_status(mmi_msg_delete_msg_before_save_pre_check, MOD_MMI);
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_rsp(void *number, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_FRM_SMS_OK:
            g_msg_cntx.msg_send_info.CurrSendSmsNumbers++;
            while (g_msg_cntx.msg_send_info.CurrSendSmsNumbers < g_msg_cntx.msg_send_info.TotalSendSmsNumbers)
            {
            #ifdef __MMI_MESSAGES_SEND_TO_MANY__
                if ((g_msg_cntx.sendMessageCase == SEND_CASE_SEND_TO_MANY)
                    &&
                    (mmi_ucs2strlen
                     ((S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.msg_send_info.CurrSendSmsNumbers])))
                {
                    U8 length = mmi_ucs2strlen(g_msg_cntx.msg_send_info.
                                         PhbNumber[g_msg_cntx.msg_send_info.CurrSendSmsNumbers]);
                    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
                    mmi_ucs2_n_to_asc(
                        (S8*) g_msg_cntx.smsPhoneNumber,
                        (S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.msg_send_info. CurrSendSmsNumbers],
                        length * ENCODING_LENGTH);
                    mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
                    return;
                }
            #endif /* __MMI_MESSAGES_SEND_TO_MANY__ */ 
            #ifdef __MMI_MESSAGES_SEND_BY_GROUP__
                else if ((g_msg_cntx.sendMessageCase == SEND_CASE_SEND_BY_GROUP)
                         && (g_msg_cntx.msg_send_info.PhbIndex != NULL))
                {
                    U8 PhbNuminBCD[(MAX_DIGITS + 1) / 2];
                    U8 PhbNum[MAX_DIGITS + 1];
                    S8 PhbNumUCS2[(MAX_DIGITS + 2) * ENCODING_LENGTH];
                    U8 type = 0;
                    U8 length =
                        (PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[g_msg_cntx.msg_send_info.CurrSendSmsNumbers]].tel.length >
                         (MAX_DIGITS / 2)) ? 
                         (MAX_DIGITS / 2) : 
                         PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[g_msg_cntx.msg_send_info.CurrSendSmsNumbers]].tel.length;
                    memset(PhbNuminBCD, 0, (MAX_DIGITS + 1) / 2);
                    memcpy(
                        PhbNuminBCD,
                        PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[g_msg_cntx.msg_send_info.CurrSendSmsNumbers]]. tel.number,
                        length);
                    memset(PhbNum, 0, MAX_DIGITS + 1);
                    mmi_phb_convert_to_digit((U8*) PhbNum, (U8*) PhbNuminBCD, MAX_DIGITS + 1);
                    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
                    if (PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[g_msg_cntx.msg_send_info.CurrSendSmsNumbers]].tel.
                        type == CSMCC_INTERNATIONAL_ADDR)
                    {
                        type = 1;
                        mmi_asc_to_ucs2((S8*) PhbNumUCS2, "+");
                    }
                    mmi_asc_n_to_ucs2((S8*) PhbNumUCS2 + type * ENCODING_LENGTH, (S8*) PhbNum, length);
                    mmi_ucs2_n_to_asc(
                        (S8*) g_msg_cntx.smsPhoneNumber,
                        (S8*) PhbNumUCS2,
                        (length + type) * ENCODING_LENGTH);
                    mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
                    return;
                }
            #endif /* __MMI_MESSAGES_SEND_BY_GROUP__ */ 
                g_msg_cntx.msg_send_info.CurrSendSmsNumbers++;
            }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
			mmi_frm_sms_background_send_schedule();
            mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

            ReleaseEMSEditBuffer();
        #ifdef __MMI_UNIFIED_MESSAGE__

            /* Skip UM write menu */
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                mmi_um_skip_write_menu(KAL_TRUE);
            }

			//Write A New SMS Case
			if (g_msg_cntx.sendMessageCase != SEND_CASE_SEND_FROM_USE_NUMBER && 
				g_msg_cntx.sendMessageCase != SEND_CASE_REPLY_FROM_OTHER_APP &&
				g_msg_cntx.sendMessageCase != SEND_CASE_SEND_FROM_OTHER_APP)
			{
			#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__				
	            if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
	            {
	                /* Remove the sent msg from drafts box */
	                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_SEND_SUCCESS_REMOVE_MSG);

					/* if the sending sms is interrupt by other application such as incoming call,
					   we will not show the processing screen, because the it will stop the interrupt
					   application key respond */
					mmi_msg_set_processing_screen(
	                    STR_UNSENTBOX_MENUENTRY,
	                    STR_DELETING_SMS_CAPTION,
	                    IMG_GLOBAL_PROGRESS,
	                    0);
					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

	                mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
	                return;
	            }
	            else
			#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

				if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT)
	            {
	                /* Remove the sent msg from drafts box */
	                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_SEND_SUCCESS_REMOVE_MSG);

					mmi_msg_set_processing_screen(STR_DRAFTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_PROGRESS, 0);

					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

	                mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
	                return;
	            }
			}
		#endif /* __MMI_UNIFIED_MESSAGE__ */

			//Write A New SMS Case
            if (IsScreenPresent(SCR_ID_MSG_WRITE) &&
				(g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER ||
				 g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP ||
			     g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE); 
            }
			else
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
            }       
#endif
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
            }
            else
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

            if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
            }			
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
            }

        #if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
            }
        #endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            else if (IsScreenPresent(SCR_ID_MSG_TEMPLATE_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_OPTION);
            }
            else if (IsScreenPresent(SCR_ID_MSG_WRITE))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
            }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            DisplayPopup(
                (PU8) GetString(STR_SMS_SENDING_ID),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_SUCCESS),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

            if (g_msg_cntx.msg_send_info.CurrSendSmsNumbers == g_msg_cntx.msg_send_info.TotalSendSmsNumbers)
            {
                DeleteMessagesHistoryNodes();
                mmi_frm_sms_delete_screen_history();
            }

        #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);   /* Reset after sending picture msg */
        #endif 
            AlmEnableSPOF();
            break;

#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        case MMI_FRM_SMS_ABORT:

        #if ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            if (g_nsm_msg_context.is_picmsg == TRUE)
            {
                EMSData *pEMS;

                GetEMSDataForEdit(&pEMS, 1);
                AddString(
                    pEMS,
                    (U8*) g_nsm_msg_context.textbuffer,
                    (U16) mmi_ucs2strlen((S8*) g_nsm_msg_context.textbuffer),
                    NULL);
            }
        #endif /* ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

        #ifdef __MMI_SMART_MESSAGE_MT__
            /* Replying message only contains texts and the content of the msg should be keeped in abort case */
            if ((mmi_nsm_get_msg_type() == PICTURE_MESSAGE) && (g_msg_cntx.sendMessageCase != SEND_CASE_REPLY))
            {
                EMSData *pEMS;

                GetEMSDataForEdit(&pEMS, 0);
                memset(pEMS->textBuffer, 0x00, pEMS->textLength);
                /* memset(&picmsg_text_struct, 0x00, sizeof(picmsg_text_struct)); *//* For issue 140 */
                ReleaseEMSEditBuffer();
            }

        #endif /* __MMI_SMART_MESSAGE_MT__ */ 

            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE_OPTION);
            }
        #ifdef __MMI_SMART_MESSAGE_MT__
            else if (IsScreenPresent(SCR_ID_EDIT_OPTIONS))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_EDIT_OPTIONS);
            }

            else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY)) /* JAI 06-12-2004 for My Pic */
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
            }
        #endif /* __MMI_SMART_MESSAGE_MT__ */ 
            else if (IsScreenPresent(SCR_ID_MSG_SEND_OPTION)) /*ML: edit src --> select done, send to many/ send/ save and send page*/
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SEND_OPTION);
            }
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
            {
                /* sent / forward / abort . This case shall go back to send option */
                if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_SENT)
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }                
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
            {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);              
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */            
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                /* sent / forward / abort . This case shall go back to send option */
                if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_SENT)
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG) )
            {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
            }    
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG) )
            {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
            }              
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            DisplayPopup(
                (PU8) GetString(STR_ABORT_SENDING_SMS),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            DeleteMessagesHistoryNodes();
            mmi_frm_sms_delete_screen_history();
            AlmEnableSPOF();
            break;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

        case MMI_FRM_SMS_NOTREADY:
            DisplayPopup(
                (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            AlmEnableSPOF();
            break;
        case MMI_FRM_SMS_NUMINVALID:
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);

			//Write A New SMS Case
            if (IsScreenPresent(SCR_ID_MSG_WRITE) &&
				(g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER ||
				 g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP ||
			     g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP))
		    {
				SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE); 
			}
			else
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
            }			
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
            }
            else
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */           
        
            if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
            }
        #if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
            }
        #endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            else if (IsScreenPresent(SCR_ID_MSG_WRITE))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
            }
            DeleteMessagesHistoryNodes();
            mmi_frm_sms_delete_screen_history();
            AlmEnableSPOF();
            break;

        case MMI_FRM_SMS_RETURN:
			break;
		
        case MMI_FRM_SMS_END:
        #ifdef __MMI_SMART_MESSAGE_MT__
            if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
            {
                ReleaseEMSEditBuffer();
            }
        #endif /* __MMI_SMART_MESSAGE_MT__ */ 
            break;

#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        case MMI_FRM_SMS_END_FROM_SENDING:
        #ifdef __MMI_SMART_MESSAGE_MT__
            if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
            {
                ReleaseEMSEditBuffer();
            }
        #endif /* __MMI_SMART_MESSAGE_MT__ */ 
        #ifdef __MMI_UNIFIED_MESSAGE__
            {
                U8 msg_box_type = mmi_um_get_current_msg_box_type();

				//Write A New SMS Case
				if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER ||
				 	g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP ||
			     	g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP)
				{
					mmi_msg_set_background_process(KAL_TRUE);
                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
				}
				else
				{
					if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT)
	                {
	                    /* unsent / edit / send/ end key, delete the old msg and save the new one   */
	                    if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
	                    {
	                        /* delete the msg in draft and save the msg to unsent  */
	                        mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
	                        mmi_msg_set_background_process(KAL_TRUE);
	                        mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
	                        mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	                    }

	                    /* unsent / send / end key, the msg should be kept. */
	                    else
	                    {
	                        ;   /* Do nothing  */
	                    }
	                }
	                else if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
	                {
	                    /* draft / edit / send/ end key, or draft / send / end key , delete the old msg and save the new one   */
	                    /* delete the msg in draft and save the msg to unsent  */
	                    mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
	                    mmi_msg_set_background_process(KAL_TRUE);
	                    mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
	                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	                }
	                else
	                {
	                    mmi_msg_set_background_process(KAL_TRUE);
	                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	                }
				}
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            break;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__	 
		case MMI_FRM_SMS_MEMFULL:
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                mmi_um_skip_write_menu(KAL_TRUE);
            }

            if (IsScreenPresent(SCR_ID_MSG_WRITE) && g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP)
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE); 
            }
			else if (IsScreenPresent(SCR_ID_MSG_USE_NUMBER_OPTION))
		    {
				SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE); 
			}
			else
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
            }
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
            }       
		#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
            }
            else
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

            if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
            }
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
            }			
		#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
            }
            else if (IsScreenPresent(SCR_ID_MSG_TEMPLATE_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_OPTION);
            }
            else if (IsScreenPresent(SCR_ID_MSG_WRITE))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
            }

	        DisplayPopup(
	            (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
	            IMG_GLOBAL_UNFINISHED,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) WARNING_TONE);

            DeleteMessagesHistoryNodes();
            mmi_frm_sms_delete_screen_history();
			AlmEnableSPOF();
			break;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
				
        default: /*normal error*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__	
	        DisplayPopup(
	            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
	            IMG_GLOBAL_ERROR,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) ERROR_TONE);
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
#ifdef __MMI_UNIFIED_MESSAGE__
        {
            U8 msg_box_type = mmi_um_get_current_msg_box_type();

            /* Skip UM write menu */
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                mmi_um_skip_write_menu(KAL_TRUE);
            }

			//Write A New SMS Case
			if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER ||
				g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP ||
				g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP)
			{
				mmi_msg_set_processing_screen(STR_WMESSAGE_MENUENTRY, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

	            mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
			}
			else
			{
	            if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
	            {
		            /* inbox / edit / send/ send fail , or inbox / forward / send/ send fail, the msg should be saved to unsent box */
		            mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

	                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__		
            else if (msg_box_type == UM_MSG_BOX_TYPE_ARCHIVE)
            {
                /* sent / edit / send/ send fail , or sent / forward / send/ send fail, the msg should be saved to unsent box */
                mmi_msg_set_processing_screen(STR_UM_ARCHIVE_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
            }			
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
	            else if (msg_box_type == UM_MSG_BOX_TYPE_SENT)
	            {
	                /* sent / edit / send/ send fail , or sent / forward / send/ send fail, the msg should be saved to unsent box */
	                mmi_msg_set_processing_screen(STR_UM_SENT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

	                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	            }
	            else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT)
	            {
	                /* unsent / edit / send / send fail, delete the old msg and save the new one */
	                if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
	                {
	                    mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);

			            mmi_msg_set_processing_screen(STR_UM_UNSENT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

						if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
						{
							mmi_msg_replace_sending_to_processing();
						}
						else
						{
			                mmi_msg_entry_processing_generic();
			                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
						}

                        mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
	                    mmi_msg_save_msg_after_send_with_flag_req(
	                        SMSAL_STO_UNSENT,
	                        number,
	                        MMI_FRM_SMS_SAVE_HIGHLIGHT_NEW_MSG_IND);
	                }
	                /* unsent / send/ send fail, the msg should be kept. */
	                else
	                {
	                    /* Do nothing  */
	                #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
	                    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
	                    {
	                        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
	                    }
	                    else
	                #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
	                    {
	                        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
	                    }
			 
	                    DisplayPopup(
	                        (PU8) GetString(STR_SMS_SEND_FAILED),
	                        IMG_SEND_FAIL_PIC_MSG,
	                        1,
	                        MESSAGES_POPUP_TIME_OUT,
	                        (U8) ERROR_TONE);
	                    DeleteMessagesHistoryNodes();
	                    mmi_frm_sms_delete_screen_history();
	                    AlmEnableSPOF();
	                }
	            }
	            else if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
	            {
	                /* draft / edit / send / send fail, or draft / send / send fail, delete the old msg and save the new one to unsent */
	                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
	                mmi_msg_set_processing_screen(STR_UM_DRAFT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

                    mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
					mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	            }
	            else
	            {
					mmi_msg_set_processing_screen(STR_WMESSAGE_MENUENTRY, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

					if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
					{
						mmi_msg_replace_sending_to_processing();
					}
					else
					{
		                mmi_msg_entry_processing_generic();
		                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
					}

	                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
	            }
			}
        }
        #else /* __MMI_UNIFIED_MESSAGE__ */ 
            /* when sending fail, only save the content to outbox if the message is not sent from outbox originally */
   #ifndef __MMI_DUAL_SIM_MASTER__
        if (IsScreenPresent(SCR_ID_MSG_OUTBOX_SEND_OPTION))
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (IsScreenPresent(SCR_ID_MSG_OUTBOX_SEND_OPTION) ||
            IsScreenPresent(SCR_MTPNP_MSG_OUTBOX_SEND_OPTION))
    #endif /* __MMI_DUAL_SIM_MASTER__ */
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
			 
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_FAILED),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                DeleteMessagesHistoryNodes();
                mmi_frm_sms_delete_screen_history();
                AlmEnableSPOF();
            }
            else
            {
                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number              [?]         
 *  replyindex          [IN]        
 *  hidenumscreen       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_req(U8 *number, U16 replyindex, U8 hidenumscreen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
#ifdef __MMI_UNIFIED_MESSAGE__
    if (!(mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT && GetExitScrnID() == SCR_ID_MSG_OUTBOX_OPTION))
#else 
    if (GetMessagesCurrScrnID() != SCR_ID_MSG_OUTBOX_SEND_OPTION)
#endif 
    {
        sendData->sendrequire |= MMI_FRM_SMS_SAVE_AFTER_FAIL; /*ML: to control if we can release EMS or not*/
    }
    memset(sendData->number, 0, MAX_DIGITS_SMS);
    if (strlen((S8*) number))
    {
        memcpy((S8*) sendData->number, (S8*) number, strlen((S8*) number));
    }
    else if (replyindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        sendData->sendrequire |= MMI_FRM_SMS_REPLY;
        sendData->replyindex = replyindex;  
    }
    /* for send to many or send to group, show only one sending screen for all numbers */
    if ((g_msg_cntx.msg_send_info.CurrSendSmsNumbers + 1) < g_msg_cntx.msg_send_info.TotalSendSmsNumbers)
    {
        sendData->sendrequire |= MMI_FRM_SMS_MORE;
    }
    /* if sendcheck has a bit of MMI_FRM_SMS_SCR, do not show sending screen */
    if (g_msg_cntx.msg_send_info.CurrSendSmsNumbers != 0)
    {
        sendData->sendcheck |= MMI_FRM_SMS_SCR;
    }
    if (!hidenumscreen)
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        if ( (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT) 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__            
            ||(mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_ARCHIVE) 
#endif           
        )          
		{
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                sendData->sendrequire |= MMI_FRM_SMS_NUM_SCR;
            }
        }
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
        {
            /* If press Send key in send-to-many number editor screen, the number exists so that not to display the number screen . */
            if (!IsScreenPresent(SCR_ID_MSG_SEND_MANY_LIST_OPTION))
            {
                sendData->sendrequire |= MMI_FRM_SMS_NUM_SCR;
            }
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if ( (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION)   || (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))  || (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG)) )&& 
              (replyindex == MMI_FRM_SMS_INVALID_INDEX))
        {
            /* If press Send key in send-to-many number editor screen, the number exists. */
            if (!(strlen((S8*) number)))
            {
                sendData->sendrequire |= MMI_FRM_SMS_NUM_SCR;
                memset(sendData->number, 0, MAX_DIGITS_SMS);
            }
        }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        /* the case of forward inbox message */
        if ((IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION) || IsScreenPresent(SCR_ID_MSG_INBOX_MSG)) && 
            replyindex == MMI_FRM_SMS_INVALID_INDEX)
        {
            /* If press Send key in send-to-many number editor screen, the number exists. */
            if (!(strlen((S8*) number)))
            {
                sendData->sendrequire |= MMI_FRM_SMS_NUM_SCR;
                memset(sendData->number, 0, MAX_DIGITS_SMS);
            }
        }
    }
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
#if defined(__MMI_SMART_MESSAGE_MT__)
    if ((mmi_nsm_get_msg_type() == PICTURE_MESSAGE) && (g_msg_cntx.sendMessageCase != SEND_CASE_REPLY)) /* If not reply to a picture message then do this */
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    sendData->sendrequire |= MMI_FRM_SMS_BACKGROUND_SEND;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    mmi_frm_sms_send_sms(mmi_msg_send_msg_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_and_save_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_and_save_msg_rsp(void *number, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_FRM_SMS_OK:
    #ifdef __MMI_UNIFIED_MESSAGE__

            /* Skip UM write menu */
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                mmi_um_skip_write_menu(KAL_TRUE);
            }

			//Write A New SMS Case
			if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP)
			{
				mmi_msg_set_processing_screen(STR_WMESSAGE_MENUENTRY, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

				mmi_msg_save_msg_after_send_req(SMSAL_STO_SENT, number);
			}
            else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
            {
                /* delete the msg in draft and save the msg to sent  */
                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
                mmi_msg_set_processing_screen(STR_UM_UNSENT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

                mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
                mmi_msg_save_msg_after_send_req(SMSAL_STO_SENT, number);
            }
            else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT)
            {
                /* delete the msg in draft and save the msg to unsent  */
                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
                mmi_msg_set_processing_screen(STR_UM_DRAFT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

				mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
                mmi_msg_save_msg_after_send_req(SMSAL_STO_SENT, number);
            }
            else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SENT)
            {
                /* After back to sent list, the highlight should be on the old one. */
                mmi_msg_save_msg_after_send_with_flag_req(
                    SMSAL_STO_SENT,
                    number,
                    MMI_FRM_SMS_SAVE_HIGHLIGHT_ORIGINAL_MSG_IND | MMI_FRM_SMS_SAVE_MODIFY_HIGHLIGHT);
            }
            else
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            {
                mmi_msg_save_msg_after_send_req(SMSAL_STO_SENT, number); /*INBOX , ARCHIVE*/
            }
            break;
        case MMI_FRM_SMS_ABORT:
        #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
            {
                ReleaseEMSEditBuffer();
            }
        #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE_OPTION);
            }

        #if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__)
            else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
            }
        #endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) */ 
            else if (IsScreenPresent(SCR_ID_MSG_SEND_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SEND_OPTION);
            }
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
            {
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            DisplayPopup(
                (PU8) GetString(STR_ABORT_SENDING_SMS),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            DeleteMessagesHistoryNodes();
            mmi_frm_sms_delete_screen_history();
            AlmEnableSPOF();
            break;
        case MMI_FRM_SMS_NOTREADY:
            DisplayPopup(
                (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            AlmEnableSPOF();
            break;
        case MMI_FRM_SMS_RETURN:
        case MMI_FRM_SMS_END:
        #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
            {
                ReleaseEMSEditBuffer();
            }
        #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            break;

        case MMI_FRM_SMS_END_FROM_SENDING:
        #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
            {
                ReleaseEMSEditBuffer();
            }
        #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

        #ifdef __MMI_UNIFIED_MESSAGE__
            {
                U8 msg_box_type = mmi_um_get_current_msg_box_type();

				//Write A New SMS Case
				if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP)
				{	
					mmi_msg_set_background_process(KAL_TRUE);
					mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
				}
				else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT)
                {
                    /* unsent / edit / send/ end key, delete the old msg and save the new one   */
                    /* delete the msg in draft and save the msg to unsent  */
                    mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
                    mmi_msg_set_background_process(KAL_TRUE);
                    mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
                }
                else if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
                {
                    /* draft / edit / send/ end key, or draft / send / end key , delete the old msg and save the new one   */
                    /* delete the msg in draft and save the msg to unsent  */
                    mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);
                    mmi_msg_set_background_process(KAL_TRUE);
                    mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
                }
                else
                {
                    mmi_msg_set_background_process(KAL_TRUE);
                    mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
                }
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            break;

        default:
        #ifdef __MMI_UNIFIED_MESSAGE__

            /* Skip UM write menu */
            if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
            {
                mmi_um_skip_write_menu(KAL_TRUE);
            }

			//Write A New SMS Case
			if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP)
			{
				mmi_msg_set_processing_screen(STR_WMESSAGE_MENUENTRY, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

				mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
			}
			else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
			{
                /* delete the msg in draft and save the msg to sent  */
                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);

				mmi_msg_set_processing_screen(STR_UM_UNSENT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

				mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
            }
            else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT)
            {
                /* delete the msg in draft and save the msg to unsent  */
                mmi_msg_set_post_send_action_type(MMI_SMS_PS_ACTION_MOVE_MSG);

				mmi_msg_set_processing_screen(STR_UM_DRAFT_ID, STR_GLOBAL_SAVING, IMG_GLOBAL_PROGRESS, 0);

				if (mmi_msg_check_interrupt_in_sending() == MMI_TRUE)
				{
					mmi_msg_replace_sending_to_processing();
				}
				else
				{
	                mmi_msg_entry_processing_generic();
	                DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
				}

				mmi_msg_delete_msg_after_send_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
            }
            else
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            {
                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, number);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_and_save_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number          [?]         
 *  replyindex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_and_save_msg_req(U8 *number, U16 replyindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    sendData->sendrequire |= MMI_FRM_SMS_SAVE;
    memset(sendData->number, 0, MAX_DIGITS_SMS);
    if (number != NULL)
    {
        memcpy((S8*) sendData->number, (S8*) number, strlen((S8*) number));
    }
    else if (replyindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        sendData->sendrequire = MMI_FRM_SMS_REPLY;
        sendData->replyindex = replyindex;
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
    {
        sendData->sendrequire |= MMI_FRM_SMS_NUM_SCR;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    /* JP for tracker issue : 20050625 */
    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    // #else
#if defined(__MMI_SMART_MESSAGE_MT__)
    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    mmi_frm_sms_send_sms(mmi_msg_send_and_save_msg_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_after_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_after_send_rsp(void *status, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sendresult = *(U8*) status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_FRM_SMS_OK:
    #ifdef __MMI_UNIFIED_MESSAGE__
            if (!mmi_msg_check_background_process())
            {
                if (sendresult == SMSAL_STO_UNSENT)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_UM_SEND_FAILED_SAVE_SUCCESS_ID),
                        IMG_SEND_FAIL_PIC_MSG,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_UM_SEND_SAVE_SUCCESS_ID),
                        IMG_SEND_SUCCESS_PIC_MSG,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) SUCCESS_TONE);
                }
            }
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        {
            if (sendresult == SMSAL_STO_UNSENT)
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_FAILED_SAVE_SUCCESS),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_SAVE_SUCESS),
                    IMG_SEND_SUCCESS_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);   /* Reset after saving picture msg */
    #endif 
            break;
        case MMI_FRM_SMS_ERROR:
        case MMI_FRM_SMS_MEMFULL:
            if (sendresult == SMSAL_STO_UNSENT)
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                if (!mmi_msg_check_background_process())
            #endif 
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_SEND_SAVE_FAILED),
                        IMG_SEND_FAIL_PIC_MSG,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }

            #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
                if (g_nsm_msg_context.is_picmsg == TRUE)
                {
                    EMSData *pEMS;

                    GetEMSDataForEdit(&pEMS, 1);
                    AddString(
                        pEMS,
                        (U8*) g_nsm_msg_context.textbuffer,
                        (U16) mmi_ucs2strlen((S8*) g_nsm_msg_context.textbuffer),
                        NULL);
                }
            #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            }
            else
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                if (!mmi_msg_check_background_process())
            #endif 
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_SEND_SUCESS_SAVE_FILED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }
            }
            break;
        default:
        #ifdef __MMI_UNIFIED_MESSAGE__
            if (!mmi_msg_check_background_process())
        #endif 
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_SAVE_FAILED),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            }
        #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            if (g_nsm_msg_context.is_picmsg == TRUE)
            {
                EMSData *pEMS;

                GetEMSDataForEdit(&pEMS, 1);
                AddString(
                    pEMS,
                    (U8*) g_nsm_msg_context.textbuffer,
                    (U16) mmi_ucs2strlen((S8*) g_nsm_msg_context.textbuffer),
                    NULL);
            }
        #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
            break;
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    if (!mmi_msg_check_background_process())
#endif 
    {
        if (IsScreenPresent(SCR_ID_MSG_WRITE) && 
			(g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER ||
			 g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP ||
			 g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_OTHER_APP))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
        }
        else
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
        }
        else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
        }
        else
    #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    
        if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))            
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
        }
        else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__	
        else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))            
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
        }
        else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
        }		
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/		
        else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
        }
    #ifdef __MMI_SMART_MESSAGE_MT__
        else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
        }
    #endif /* __MMI_SMART_MESSAGE_MT__ */ 
        else if (IsScreenPresent(SCR_ID_MSG_TEMPLATE_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_OPTION);
        }
        else if (IsScreenPresent(SCR_ID_MSG_WRITE))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
        }

        DeleteMessagesHistoryNodes();
        mmi_frm_sms_delete_screen_history();
        AlmEnableSPOF();
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_msg_set_background_process(KAL_FALSE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_after_send_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  number      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_after_send_req(U8 status, void *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    EMSData *data = GetEMSDataForEdit(0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    sendData->dcs = data->dcs;
    sendData->status = status;
    memcpy((S8*) sendData->number, (S8*) number, strlen((S8*) number));
    mmi_frm_sms_save_sms(mmi_msg_save_msg_after_send_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_after_send_with_flag_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  number      [?]         
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_after_send_with_flag_req(U8 status, void *number, U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    EMSData *data = GetEMSDataForEdit(0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    sendData->dcs = data->dcs;
    sendData->status = status;
    sendData->sendrequire = flag;
    memcpy((S8*) sendData->number, (S8*) number, strlen((S8*) number));
    mmi_frm_sms_save_sms(mmi_msg_save_msg_after_send_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_search_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_search_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.PhbSmsInterfaceState = MMI_SEND_ONLY;
	mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmi_msg_get_number_from_phb_ext);
}

#ifdef __MMI_MESSAGES_SEND_TO_MANY__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_to_many
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_to_many(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 last = MAX_SEND_TO_MANY_ITEMS;
    S16 avail = -1;
    U8 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (last > 0)
    {
        last--;
        if (mmi_ucs2strlen((S8*) g_msg_cntx.msg_send_info.PhbNumber[last]))
        {
            /* search for the first free entry to sort the list */
            while (avail < last)
            {
                avail++;
                if (!mmi_ucs2strlen((S8*) g_msg_cntx.msg_send_info.PhbNumber[avail]))
                {
                    memcpy(
                        g_msg_cntx.msg_send_info.PhbNumber[avail],
                        g_msg_cntx.msg_send_info.PhbNumber[last],
                        sizeof(g_msg_cntx.msg_send_info.PhbNumber[last]));
                    memset(g_msg_cntx.msg_send_info.PhbNumber[last], 0, ENCODING_LENGTH);
                    break;
                }
            }
        }
    }
    /* calculate total valid entries */
    for (total = 0; total < MAX_SEND_TO_MANY_ITEMS; total++)
    {
        if (!mmi_ucs2strlen((S8*) g_msg_cntx.msg_send_info.PhbNumber[total]))
        {
            break;
        }
    }
    if (avail == -1)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        U8 length = mmi_ucs2strlen(g_msg_cntx.msg_send_info.PhbNumber[0]);

        memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
        g_msg_cntx.msg_send_info.TotalSendSmsNumbers = total;
        g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
        mmi_ucs2_n_to_asc(
            (S8*) g_msg_cntx.smsPhoneNumber,
            (S8*) g_msg_cntx.msg_send_info.PhbNumber[0],
            length * ENCODING_LENGTH);
        mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
    }
}

#endif /* __MMI_MESSAGES_SEND_TO_MANY__ */ 
#ifdef __MMI_MESSAGES_SEND_BY_GROUP__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_to_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnt             [IN]        
 *  PhbIndex        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_to_group(U16 cnt, U16 *PhbIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 actualCount;
    U8 length;
    U8 numbers[(MAX_DIGITS + 1) / 2];
    U8 tempNumber[MAX_DIGITS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_EMPTY_GROUP_ID),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        return;
    }

    if (g_msg_cntx.msg_send_info.PhbIndex != NULL)
    {
        OslMfree(g_msg_cntx.msg_send_info.PhbIndex);
        g_msg_cntx.msg_send_info.PhbIndex = NULL;
    }
    g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 0;
    g_msg_cntx.msg_send_info.PhbIndex = OslMalloc(cnt * sizeof(U16));

    for (i = 0, actualCount = 0; i < cnt; i++)
    {
        length =
            (PhoneBook[PhbIndex[i]].tel.length >
             (MAX_DIGITS / 2)) ? (MAX_DIGITS / 2) : PhoneBook[PhbIndex[i]].tel.length;
        memset(numbers, 0, (MAX_DIGITS + 1) / 2);
        memcpy(numbers, PhoneBook[PhbIndex[i]].tel.number, length);
        if ((PhoneBook[PhbIndex[i]].tel.length == 0) ||
            (mmi_phb_convert_to_digit(tempNumber, (U8*) numbers, MAX_DIGITS + 1) == 0))
        {
            continue;
        }

        g_msg_cntx.msg_send_info.PhbIndex[actualCount] = PhbIndex[i];
        actualCount++;
    }

    g_msg_cntx.msg_send_info.TotalSendSmsNumbers = (U16) actualCount;

    if (g_msg_cntx.msg_send_info.TotalSendSmsNumbers > 0)
    {
        U8 PhbNuminBCD[(MAX_DIGITS + 1) / 2];
        U8 PhbNum[MAX_DIGITS + 1];
        S8 PhbNumUCS2[(MAX_DIGITS + 2) * ENCODING_LENGTH];
        U8 type = 0;

        length =
            (PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[0]].tel.length >
             (MAX_DIGITS / 2)) ? (MAX_DIGITS / 2) : PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[0]].tel.length;
        memset(PhbNuminBCD, 0, (MAX_DIGITS + 1) / 2);
        memcpy(PhbNuminBCD, PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[0]].tel.number, length);
        memset(PhbNum, 0, MAX_DIGITS + 1);
        mmi_phb_convert_to_digit((U8*) PhbNum, (U8*) PhbNuminBCD, MAX_DIGITS + 1);
        memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
        if (PhoneBook[g_msg_cntx.msg_send_info.PhbIndex[0]].tel.type == CSMCC_INTERNATIONAL_ADDR)
        {
            type = 1;
            mmi_asc_to_ucs2((S8*) PhbNumUCS2, "+");
        }
        mmi_asc_n_to_ucs2((S8*) PhbNumUCS2 + type * ENCODING_LENGTH, (S8*) PhbNum, length);
        g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
        mmi_ucs2_n_to_asc((S8*) g_msg_cntx.smsPhoneNumber, (S8*) PhbNumUCS2, (length + type) * ENCODING_LENGTH);
        mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
    }
    else
    {
        if (g_msg_cntx.msg_send_info.PhbIndex != NULL)
        {
            OslMfree(g_msg_cntx.msg_send_info.PhbIndex);
            g_msg_cntx.msg_send_info.PhbIndex = NULL;
        }
        g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 0;
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_EMPTY_GROUP_ID),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_by_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_BY_GROUP;
    mmi_phb_sms_enter_send_by_group();
}
#endif /* __MMI_MESSAGES_SEND_BY_GROUP__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_to_only_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_to_only_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
    g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 1;
    /* pressing SEND key from send to many phone number editor  or send message from phonebook */
    if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_TO_MANY || g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_PHB)
    {
        S8 phonenumber[(MAX_DIGITS + 1) * ENCODING_LENGTH];
        U8 length = mmi_ucs2strlen(g_msg_cntx.smsPhoneNumber);
        /* The length should be extracted by 1 for the sake of handling odd number of ascii phone number characters. */
        kal_bool isAsciiNumber = mmi_msg_check_ascii_number((U8*) g_msg_cntx.smsPhoneNumber, (U16) (length * ENCODING_LENGTH - 1));

    	if (length == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    
    		return;
        }
        /* convert g_msg_cntx.smsPhoneNumber from unicode to ascii */
        if (!isAsciiNumber)
        {
            memset(phonenumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy(phonenumber, g_msg_cntx.smsPhoneNumber, length * ENCODING_LENGTH);
            memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
            mmi_ucs2_n_to_asc((S8*) g_msg_cntx.smsPhoneNumber, (S8*) phonenumber, length * ENCODING_LENGTH);
        }
    }
    else if (g_msg_cntx.sendMessageCase != SEND_CASE_SEND_FROM_PHB)
    {
        memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
        {
            memcpy(
                g_msg_cntx.smsPhoneNumber,
                (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_UNSENT, (U16) g_msg_cntx.currBoxIndex),
                MAX_DIGITS_SMS);
        }
		else if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT)
		{
            memcpy(
                g_msg_cntx.smsPhoneNumber,
                (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_DRAFTS, (U16) g_msg_cntx.currBoxIndex),
                MAX_DIGITS_SMS);
		}
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
    #ifndef __MMI_DUAL_SIM_MASTER__
        if (GetMessagesCurrScrnID() == SCR_ID_MSG_OUTBOX_SEND_OPTION)
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (GetMessagesCurrScrnID() == SCR_ID_MSG_OUTBOX_SEND_OPTION ||
            GetMessagesCurrScrnID() == SCR_MTPNP_MSG_OUTBOX_SEND_OPTION)
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
        #ifdef __MMI_MESSAGES_DRAFT_BOX__
            if (IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST))
            {
                memcpy(
                    g_msg_cntx.smsPhoneNumber,
                    (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex),
                    MAX_DIGITS_SMS);
            }
            else
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
                memcpy(
                    g_msg_cntx.smsPhoneNumber,
                    (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex),
                    MAX_DIGITS_SMS);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 0);
}

#ifdef __MMI_SEND_BY_SEARCH_NAME__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_to_only_name_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_to_only_name_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.PhbSmsInterfaceState = MMI_SEND_BY_NAME;
    phbListView = MMI_PHB_LIST_FOR_SMS_SEARCH_NAME;
    memset(g_msg_cntx.smsPhoneNumber, 0, ENCODING_LENGTH);
    mmi_phb_search_name_pre_entry();
}

#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    /* Skip UM write menu */
    if (IsScreenPresent(SCR_ID_MSG_WRITE_OPTION))
    {
        mmi_um_skip_write_menu(KAL_TRUE);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        ReleaseEMSEditBuffer();
    #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);   /* Reset after saving picture msg */
    #endif 
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);

    #if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
        if (g_nsm_msg_context.is_picmsg == TRUE)
        {
            EMSData *pEMS;

            GetEMSDataForEdit(&pEMS, 1);
            AddString(
                pEMS,
                (U8*) g_nsm_msg_context.textbuffer,
                (U16) mmi_ucs2strlen((S8*) g_nsm_msg_context.textbuffer),
                NULL);
        }
    #endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    }

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    
    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

    else if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    else if (IsScreenPresent(SCR_ID_MSG_TEMPLATE_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_WRITE))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }
    DeleteMessagesHistoryNodes();
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

#ifdef __MMI_UNIFIED_MESSAGE__
    sendData->status = SMSAL_STO_DRAFT;
#else /* __MMI_UNIFIED_MESSAGE__ */
    sendData->status = SMSAL_STO_UNSENT;
#endif /* __MMI_UNIFIED_MESSAGE__*/

    memset((S8*) sendData->number, 0, MAX_DIGITS_SMS);

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    /* Jp for tracker issue 20050626 */
    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
#if defined(__MMI_SMART_MESSAGE_MT__)
    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    mmi_frm_sms_save_sms(mmi_msg_save_msg_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_with_flag_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_with_flag_req(U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

#ifdef __MMI_UNIFIED_MESSAGE__
    sendData->status = SMSAL_STO_DRAFT;
#else /* __MMI_UNIFIED_MESSAGE__ */
    sendData->status = SMSAL_STO_UNSENT;
#endif /* __MMI_UNIFIED_MESSAGE__ */

    memset((S8*) sendData->number, 0, MAX_DIGITS_SMS);
    sendData->sendrequire = flag;

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    /* Jp for tracker issue 20050626 */
    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
#if defined(__MMI_SMART_MESSAGE_MT__)
    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        mmi_nsm_get_picmsg_sendData(sendData);
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    mmi_frm_sms_save_sms(mmi_msg_save_msg_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_msg_to_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_msg_to_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION, STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE, 0);
    mmi_msg_entry_processing_generic();

#if defined(__MMI_UNIFIED_MESSAGE__) && defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	/**
		if write a new message through use number and send sms 
	  	or use url to enter wap and send sms, don't delete the 
	  	draft msg which is highlighted in the draft box
	**/
    if (!IsScreenPresent(SCR_ID_MSG_USE_NUMBER_OPTION) && !IsScreenPresent(SCR_ID_MSG_USE_URL_OPTION) &&
		(mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT))
    {
        /* mmi_msg_delete_msg_before_save_req(MMI_FRM_SMS_APP_DRAFTS, (U16)g_msg_cntx.currBoxIndex); */
        mmi_msg_delete_msg_before_save();
        return;
    }
#endif /* defined(__MMI_UNIFIED_MESSAGE__) && defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) */ 

    mmi_msg_save_msg_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_and_save_to_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_and_save_to_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
    {
        mmi_msg_send_and_save_msg_req(
            mmi_frm_sms_get_address(MMI_FRM_SMS_UNSENT, (U16) g_msg_cntx.currBoxIndex),
            MMI_FRM_SMS_INVALID_INDEX);
    }
    else
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
        mmi_msg_send_and_save_msg_req(NULL, MMI_FRM_SMS_INVALID_INDEX);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_reply_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_reply_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
    g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
    g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 1;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
    {
        memcpy(g_msg_cntx.smsPhoneNumber,
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_ARCHIVE, (U16)g_msg_cntx.currBoxIndex),
        	MAX_DIGITS_SMS);
        //fill g_msg_cntx.smsPhoneNumber, (becasue if the field is empty, will use addr in L4 for reply )		
        //fill MMI_FRM_SMS_INVALID_INDEX -- because if archive save empty number(should not happen), force not MMI_FRM_SMS_REPLY
        mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    {
        mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, (U16) g_msg_cntx.currBoxIndex, 1);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_reply_msg_to_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_reply_msg_to_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UNIFIED_COMPOSER__
    U8 *replyaddr;	
    
    ReleaseEMSEditBuffer();
    
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
//because use same id---SMS_INBOX_OPT_REPLY_MENUID-->highlight call this api
    if(g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
    {
        replyaddr = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_ARCHIVE, (U16)g_msg_cntx.currBoxIndex);
        mmi_msg_entry_uc(replyaddr , (U16)MMI_UC_STATE_REPLY, MMI_FRM_SMS_INVALID_INDEX, MMI_UC_MSG_TYPE_DEFAULT);
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    {
        replyaddr = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_INBOX, (U16)g_msg_cntx.currBoxIndex);
        mmi_msg_entry_uc(replyaddr , (U16)MMI_UC_STATE_REPLY, (U16)g_msg_cntx.currBoxIndex, MMI_UC_MSG_TYPE_DEFAULT);
    }
    
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    } 	
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
    {
        MMI_ASSERT(0);
    }
    
    DeleteMessagesHistoryNodes();

    return;

#else /* __MMI_UNIFIED_COMPOSER__ */

    g_msg_cntx.sendMessageCase = SEND_CASE_REPLY;
    ReleaseEMSEditBuffer();
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
#endif 
    mmi_msg_entry_write_msg();

#endif /* __MMI_UNIFIED_COMPOSER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_number_from_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_number_from_phb(U8 name[], U8 number[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    U8 ascii_num[MAX_DIGITS_SMS + 1];
#endif /* __MMI_UNIFIED_COMPOSER__ */     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) number) > (MAX_DIGITS_SMS - 1))
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
        return;
    }

    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
    if (number)
    {
        mmi_ucs2cpy(g_msg_cntx.smsPhoneNumber, (PS8) number);
    }
    if (g_msg_cntx.PhbSmsInterfaceState == MMI_SEND_SMS_FROM_PHB)
    {
    #ifdef __MMI_UNIFIED_COMPOSER__

        memset(ascii_num, 0, sizeof(ascii_num));            
        mmi_ucs2_to_asc((S8*)ascii_num, (S8*)number);
        mmi_msg_entry_uc(ascii_num, MMI_UC_STATE_WRITE_NEW_MSG, 0, MMI_UC_MSG_TYPE_SMS_ONLY);    

    #else /* __MMI_UNIFIED_COMPOSER__ */

        g_msg_cntx.sendMessageCase = SEND_CASE_SEND_FROM_PHB;
        ReleaseEMSEditBuffer();
        mmi_msg_entry_write_msg();

    #endif /* __MMI_UNIFIED_COMPOSER__ */ 
    }
    else if (IsScreenPresent(SCR_ID_MSG_NUMBER))
    {
        /* put the selected number to editor */
        HistoryReplace(SCR_ID_MSG_NUMBER, SCR_ID_MSG_NUMBER, mmi_msg_entry_phone_number);
        GoBackToHistory(SCR_ID_MSG_NUMBER);
    }
    else
    {
        mmi_msg_entry_phone_number();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_number_from_phb_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_number_from_phb_ext(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_get_number_from_phb((U8*) name, (U8*) number);	
}

#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_edit_msg_by_uc
 * DESCRIPTION
 *  Edit msg by unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_edit_msg_by_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType msgbox_type = mmi_um_get_current_msg_box_type();
    U8* addr = NULL;
	U8 number[MAX_DIGITS_SMS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgbox_type == UM_MSG_BOX_TYPE_UNSENT)
    {
        addr = mmi_frm_sms_get_address(MMI_FRM_SMS_UNSENT, (U16) g_msg_cntx.currBoxIndex);
    }
    else if (msgbox_type == UM_MSG_BOX_TYPE_SENT)
    {
        addr = mmi_frm_sms_get_address(MMI_FRM_SMS_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
    }
    else if (msgbox_type == UM_MSG_BOX_TYPE_DRAFT)
    {
        addr = mmi_frm_sms_get_address(MMI_FRM_SMS_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (msgbox_type == UM_MSG_BOX_TYPE_ARCHIVE)
    {
        addr = mmi_frm_sms_get_address(MMI_FRM_SMS_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);
    }
#endif

	if (addr != NULL)
	{
		memcpy((S8*)number, (S8*)addr, MAX_DIGITS_SMS);
		number[MAX_DIGITS_SMS] = 0;
	}
	else
	{
		number[0] = 0;
	}
    mmi_msg_entry_uc(number , MMI_UC_STATE_EDIT_EXISTED_MSG, (U16)g_msg_cntx.currBoxIndex, MMI_UC_MSG_TYPE_DEFAULT);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }	
#endif
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }        
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }        
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
    {
        MMI_ASSERT(0);
    }    
    DeleteMessagesHistoryNodes();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_edit_msg_from_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_edit_msg_from_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {

        if (mmi_nsm2_is_valid_picmsg() == MMI_NSM_PIC_FORMAT_ERROR)
        {
            ShowPictureErrorMessage();
            return;
        }
        else
        {
            /* 
             *   JP for tracker issue 200506
             *Copy to bufforview is already done in EntryNSMpicmsg API 
             */
            memcpy(g_nsm_msg_context.picbuffer, gNSMBuffer, sizeof(g_nsm_msg_context.picbuffer));
            g_nsm_msg_context.is_picmsg = TRUE;
        }
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
    #ifdef __MMI_UNIFIED_COMPOSER__

        EMSData *pEMS;
        GetEMSDataForEdit(&pEMS, 0);
        
        if (pEMS->listHead)
        {
            mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_edit_msg_by_uc, GoBackHistory);
            mmi_msg_entry_confirm_generic();
        }
        else
        {
            mmi_msg_edit_msg_by_uc();
        }        
    #else /* __MMI_UNIFIED_COMPOSER__ */
    
        mmi_msg_entry_write_msg();
    
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    U16 totalArchive = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_ARCHIVE); 
#endif

#ifdef __MMI_UNIFIED_MESSAGE__
    U16 totalUnsentbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_UNSENT);
#endif 

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 totalSimbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_SIM);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    {
        UmMsgBoxType msg_box_type = mmi_um_get_current_msg_box_type();
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if(msg_box_type ==UM_MSG_BOX_TYPE_ARCHIVE )
        {
              if (totalArchive == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
                }			
                else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
                }							
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                /*should not assert here, the following case will have no previous screen but it's also what we want.*/
                /*ex. MAUI_00233656 -- user remove archive folder via usb and enter archive box to do action, error handler will find out
                      the idx.a and content files does not match, therefore pop delete confirm screen to ask user. user select delete, at
                      this time, no above screen exist.*/
                /*
                else
                {
                    MMI_ASSERT(0);
                }
                */
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalArchive)
            {
                g_msg_cntx.currBoxIndex = totalArchive - 1;
            }
        }
        else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
        {
            if (totalInbox == 0)
            {            
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

                if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }                
                g_msg_cntx.msg_ind_in_idle = 0;
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalInbox)
            {
                g_msg_cntx.currBoxIndex = totalInbox - 1;
            }
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_SENT)
        {
            if (totalOutbox == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalOutbox)
            {
                g_msg_cntx.currBoxIndex = totalOutbox - 1;
            }
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT)
        {
            if (totalUnsentbox == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
				if (IsScreenPresent(SCR_ID_MSG_UNSENTBOX_OPTION))
                {
                	mmi_msg_update_unsent_icon();
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_UNSENTBOX_OPTION);
                }
				else
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
				if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalUnsentbox)
            {
                g_msg_cntx.currBoxIndex = totalUnsentbox - 1;
            }
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
        {
            if (totalDraftbox == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalDraftbox)
            {
                g_msg_cntx.currBoxIndex = totalDraftbox - 1;
            }
        }
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        else if (msg_box_type == UM_MSG_BOX_TYPE_SIM)
        {
            if (totalSimbox == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                g_msg_cntx.sim_msg_ind_in_idle = FALSE;
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalSimbox)
            {
                g_msg_cntx.currBoxIndex = totalSimbox - 1;
            }        
        }
    #endif/* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST))
    {
        if (totalInbox == 0)
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST);
            g_msg_cntx.msg_ind_in_idle = 0;
            g_msg_cntx.currBoxIndex = 0;
        }

        /* Delete the last msg of msg list  */
        else if (g_msg_cntx.currBoxIndex >= totalInbox)
        {
            g_msg_cntx.currBoxIndex = totalInbox - 1;
        }
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        if (totalOutbox == 0)
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST);
            g_msg_cntx.currBoxIndex = 0;
        }

        /* Delete the last msg of msg list  */
        else if (g_msg_cntx.currBoxIndex >= totalOutbox)
        {
            g_msg_cntx.currBoxIndex = totalOutbox - 1;
        }
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST))
    {
        if (totalDraftbox == 0)
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DRAFTBOX_LIST);
            g_msg_cntx.currBoxIndex = 0;
        }

        /* Delete the last msg of msg list  */
        else if (g_msg_cntx.currBoxIndex >= totalDraftbox)
        {
            g_msg_cntx.currBoxIndex = totalDraftbox - 1;
        }
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
    if (mmi_nsm_get_msg_type() != NORMAL_MESSAGE)   /* When msg count > 0 */
    {
        if ((IsScreenPresent(SCR_ID_MYPIC_DISPLAY)) && (totalInbox != 0))       /* For pic msg in Inbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
        }
        else if ((IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG)) && (totalOutbox != 0))        /* For pic msg in Outbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
        }
        else if ((IsScreenPresent(SCR_ID_MSG_INBOX_MSG)) && (totalDraftbox != 0))       /* For ringtone in Inbox list */
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
        }
    #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
        if (g_nsm_msg_context.is_picmsg == TRUE)
        {
            mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        }
    #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 
    DeleteMessagesHistoryNodes();

    if (result == MMI_FRM_SMS_OK)
    {
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_SIM)
    #endif
        {
       #ifndef __MMI_DUAL_SIM_MASTER__
            g_msg_cntx.msg_full_ind = FALSE;
        	mmi_msg_set_msg_icon(FALSE, FALSE);
		#else /* __MMI_DUAL_SIM_MASTER__ */
			if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_ALL || MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_MASTER)
			{
				g_msg_cntx.msg_full_ind = FALSE;
			}					
			MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
			MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
		#endif /* __MMI_DUAL_SIM_MASTER__ */
        }        
    }
    
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}

#if defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dm_delete_all_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dm_delete_all_msg_rsp(void *dummy, module_type mod, U16 result)
{
    if (MTPNP_PFAL_Get_Msgs_DelAll_State() > 0)
    {
        return;
    }

    mmi_msg_delete_msg_rsp(dummy, mod, result);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
void mmi_msg_move_to_archive_rsp(void *dummy, module_type mod, U16 result)
{
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);

    
    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    }
    else
    {
        FS_HANDLE *pfsErrCode = (FS_HANDLE *) dummy;  
        if((dummy != NULL) && (*pfsErrCode < 0))  //means fs related error, display coreesponding err string
        { 
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString((S32)(*pfsErrCode))),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);  
        }
        else //means other error, display sms storage full
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_ARCHIVE_MEMORY_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);

        }
    }
#ifdef __MMI_UNIFIED_MESSAGE__
    {        
       UmMsgBoxType msg_box_type = mmi_um_get_current_msg_box_type();

        if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
        {
            if (totalInbox == 0)
            {            
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

                if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))   
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }                
                g_msg_cntx.msg_ind_in_idle = 0;
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalInbox)
            {
                g_msg_cntx.currBoxIndex = totalInbox - 1;
            }
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_SENT)
        {
            if (totalOutbox == 0)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))    
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                
                g_msg_cntx.currBoxIndex = 0;
            }

            /* Delete the last msg of msg list  */
            else if (g_msg_cntx.currBoxIndex >= totalOutbox)
            {
                g_msg_cntx.currBoxIndex = totalOutbox - 1;
            }
        }
    }
#endif //__MMI_UNIFIED_MESSAGE__
    DeleteMessagesHistoryNodes();

    if (result == MMI_FRM_SMS_OK)
    {
        g_msg_cntx.msg_full_ind = FALSE;
    #ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_msg_icon(FALSE, FALSE);
	#else	/* __MMI_DUAL_SIM_MASTER__ */
		g_msg_cntx.msg_full_ind = FALSE;
		MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
		MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	#endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS));
    
}    


/*here, type is src box*/
void mmi_msg_move_msg_to_archive_req(U16 type, U16 index)
{
    U16 type_remap; /*will seprate MMI_FRM_SMS_APP_UNREAD, MMI_FRM_SMS_APP_READ, MMI_FRM_SMS_APP_OUTBOX*/
    if ((mmi_frm_sms_get_status(type, index) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
    {
        type_remap =  MMI_FRM_SMS_APP_UNREAD;          
    }
    else 
    {
        type_remap =  type;     
    }
    mmi_frm_sms_move_to_archive(mmi_msg_move_to_archive_rsp, MOD_MMI, type_remap, index);

}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_req(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (type == MMI_FRM_SMS_APP_ARCHIVE)
    {
        mmi_frm_sms_delete_one_archive_msg_req(mmi_msg_delete_msg_rsp, type, index);    
    }	
    else	
#endif
    {
        mmi_frm_sms_delete_sms(mmi_msg_delete_msg_rsp, MOD_MMI, type, index);
    }
}

#if defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_dm_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 * side         [IN]
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_dm_msg_req(U8 side, U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (type == MMI_FRM_SMS_APP_ARCHIVE)
    {
        mmi_frm_sms_delete_one_archive_msg_req(mmi_msg_delete_msg_rsp, type, index);    
    }	
    else	
#endif
    {
        MTPNP_PFAL_Init_Msgs_DelAll_State(side);
        mmi_frm_sms_dm_delete_sms(side, mmi_msg_dm_delete_all_msg_rsp, MOD_MMI, type, index);
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_move_msg_to_archive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_move_msg_to_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) MMI_SMS_ARCH_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    mmi_msg_set_confirm_screen(STR_MOVE_TO_ARCHIVE_MENUENTRY_QUERY_ID, mmi_msg_move_msg_to_archive, GoBackHistory);
	mmi_msg_entry_confirm_generic();
}


void mmi_msg_move_msg_to_archive(void)
{
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);            
            mmi_msg_entry_processing_generic();
            mmi_msg_move_msg_to_archive_req(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
        break;   

        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
            mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);                       
            mmi_msg_entry_processing_generic();
            mmi_msg_move_msg_to_archive_req(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
        break;

        default:

        break;
			
    }
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
    #ifdef __MMI_UNIFIED_MESSAGE__
            mmi_msg_set_processing_screen(STR_UM_SENT_ID, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    #else 
            mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    #endif 
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
            break;

#ifdef __MMI_UNIFIED_MESSAGE__
        case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            mmi_msg_set_processing_screen(STR_UNSENTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
            break;
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
           	mmi_msg_set_processing_screen(STR_DRAFTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
            break;
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */
	
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case TO_DISPLAY_MESSAGE_LIST_ARCHIVE:  
            mmi_msg_set_processing_screen(STR_UM_ARCHIVE_ID, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);
            break;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case TO_DISPLAY_MESSAGE_LIST_SIMBOX:
            mmi_msg_set_processing_screen(STR_SIMBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
            mmi_msg_entry_processing_generic();
            mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_SIM, (U16) g_msg_cntx.currBoxIndex);
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_inbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_INBOX);
    return;
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    mmi_msg_entry_processing_generic();
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

    g_msg_cntx.msg_ind_in_idle = FALSE;
    g_msg_cntx.msg_ind_after_call = FALSE;

#if !defined(__MMI_DUAL_SIM_MASTER__)
    mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_SMS_Get_Filter_Rule())
    {
	    case MTPNP_AD_FILTER_MASTER:
	        mmi_msg_delete_dm_msg_req(DM_MASTER_BOX, MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX);        
	        break;
	    case MTPNP_AD_FILTER_SLAVE:
	        mmi_msg_delete_dm_msg_req(DM_SLAVE_BOX, MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX);
	        break;
	    case MTPNP_AD_FILTER_ALL:
	        mmi_msg_delete_dm_msg_req(DM_MIX_BOX, MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX);
	        break;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_msg_all_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_msg_set_confirm_screen(STR_INBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_inbox, GoBackHistory);
    mmi_msg_entry_confirm_generic();
    return;
#else /* __MMI_UNIFIED_MESSAGE__ */ 

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_confirm_screen(STR_INBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_inbox, GoBackHistory);
	#else /* __MMI_DUAL_SIM_MASTER__ */
		if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_MASTER)
		{
			mmi_msg_set_confirm_screen(STRING_MTPNP_MASTER_DELETE_INBOX_MENUENTRY, mmi_msg_delete_msg_all_inbox, GoBackHistory);
		}
		else if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_SLAVE)
		{
			mmi_msg_set_confirm_screen(STRING_MTPNP_SLAVE_DELETE_INBOX_MENUENTRY, mmi_msg_delete_msg_all_inbox, GoBackHistory);
		}
		else
		{
			mmi_msg_set_confirm_screen(STR_INBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_inbox, GoBackHistory);
		}
	#endif /* __MMI_DUAL_SIM_MASTER__ */
        mmi_msg_entry_confirm_generic();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_SENT);
    return;
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    mmi_msg_entry_processing_generic();
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#if !defined(__MMI_DUAL_SIM_MASTER__)
    mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_SMS_Get_Filter_Rule())
    {
	    case MTPNP_AD_FILTER_MASTER:
	        mmi_msg_delete_dm_msg_req(DM_MASTER_BOX, MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX);        
	        break;
	    case MTPNP_AD_FILTER_SLAVE:
	        mmi_msg_delete_dm_msg_req(DM_SLAVE_BOX, MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX);
	        break;
	    case MTPNP_AD_FILTER_ALL:
	        mmi_msg_delete_dm_msg_req(DM_MIX_BOX, MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX);
	        break;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_msg_all_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SENTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_outbox, GoBackHistory);
    mmi_msg_entry_confirm_generic();
    return;
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_confirm_screen(STR_OUTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_outbox, GoBackHistory);
	#else /* __MMI_DUAL_SIM_MASTER__ */
		if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_MASTER)
		{
			mmi_msg_set_confirm_screen(STRING_MTPNP_MASTER_DELETE_OUTBOX_MENUENTRY, mmi_msg_delete_msg_all_outbox, GoBackHistory);
		}
		else if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_SLAVE)
		{
			mmi_msg_set_confirm_screen(STRING_MTPNP_SLAVE_DELETE_OUTBOX_MENUENTRY, mmi_msg_delete_msg_all_outbox, GoBackHistory);
		}
		else
		{
			mmi_msg_set_confirm_screen(STR_OUTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_outbox, GoBackHistory);
		}
	#endif /* __MMI_DUAL_SIM_MASTER__ */
        mmi_msg_entry_confirm_generic();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_archive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_archive(void)
{
    mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_ARCHIVE);
}

void mmi_msg_pre_delete_msg_all_archive(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__

    mmi_msg_set_confirm_screen(STR_ARCHIVE_DELETEALL_QUERY, mmi_msg_delete_msg_all_archive, GoBackHistory);
    mmi_msg_entry_confirm_generic();
    return;
#else /* __MMI_UNIFIED_MESSAGE__ */ 

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_ARCHIVE) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_ARCHIVE) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_ARCHIVE_DELETEALL_QUERY, mmi_msg_delete_msg_all_archive, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_set_confirm_screen(STR_SMS_BACKGROUND_DEL_ALL_WITHOUT_SENDING_ID, mmi_msg_delete_msg_all_unsentbox, GoBackHistory);
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
	mmi_msg_set_confirm_screen(STR_UNSENTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_unsentbox, GoBackHistory);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

	mmi_msg_entry_confirm_generic();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   	mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_UNSENT);
}
#endif /* __MMI_UNIFIED_MESSAGE__ */


#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
        mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_DRAFT);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen(STR_DRAFTBOX_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    mmi_msg_entry_processing_generic();
    if (IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DRAFTBOX_LIST);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#if !defined(__MMI_DUAL_SIM_MASTER__)
    mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_SMS_Get_Filter_Rule())
    {
	    case MTPNP_AD_FILTER_MASTER:
	        mmi_msg_delete_dm_msg_req(DM_MASTER_BOX, MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);        
	        break;
	    case MTPNP_AD_FILTER_SLAVE:
	        mmi_msg_delete_dm_msg_req(DM_SLAVE_BOX, MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);
	        break;
	    case MTPNP_AD_FILTER_ALL:
	        mmi_msg_delete_dm_msg_req(DM_MIX_BOX, MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);
	        break;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_msg_all_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__	
    mmi_msg_set_confirm_screen(STR_DRAFTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_draftbox, GoBackHistory);
    mmi_msg_entry_confirm_generic();
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_DRAFTS) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_DRAFTBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_draftbox, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen(STR_DELETE_ALL_MENUENTRY, STR_DELETING_SMS_CAPTION, IMG_GLOBAL_DELETED, 0);
    mmi_msg_entry_processing_generic();
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);

    mmi_msg_delete_msg_req(
        MMI_FRM_SMS_APP_INBOX | MMI_FRM_SMS_APP_OUTBOX | MMI_FRM_SMS_APP_DRAFTS,
        MMI_FRM_SMS_INVALID_INDEX | MMI_FRM_SMS_INBOX
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        | MMI_FRM_SMS_ARCHIVE
#endif        
        ); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_msg_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if ((mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == 0) &&
             (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == 0)
#ifdef __MMI_MESSAGES_DRAFT_BOX__
             && (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS) == 0)
#endif 
        )
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    else
    {
        mmi_msg_set_confirm_screen(STR_DELETE_ALL_QUERY, mmi_msg_delete_msg_all, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
}
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */ 

#ifdef __MMI_MESSAGES_COPY__

extern void HangupAllCalls(void);
extern pBOOL isInCall(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_frm_sms_copy_result_struct* rsp = (mmi_frm_sms_copy_result_struct*)data; */
    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    }
    else
    {
        if (result == MMI_FRM_SMS_MEMFULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
    }

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
    else
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
	
    DeleteMessagesHistoryNodes();
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);
    mmi_frm_sms_copy_result_struct *rsp = (mmi_frm_sms_copy_result_struct*) data;

    S8 *asciiString = OslMalloc(30);
    S8 *ucs2String = OslMalloc(60);
    S8 *causeString = OslMalloc(100);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_DONE));
    }
    else if (result == MMI_FRM_SMS_MEMFULL)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_SMS_FAILURE_MEM_FULL));
    }
    else if (result == MMI_FRM_SMS_ABORT)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_CANCEL));
    }
    else
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_UNFINISHED));
    }

    if (rsp->msg_number <= 1)
    {
        sprintf((S8*) asciiString, "\n  %d ", (U32) rsp->msg_number);
    }
    else
    {
        sprintf((S8*) asciiString, "\n  %d ", (U32) rsp->msg_number);
    }

    mmi_asc_to_ucs2((S8*) ucs2String, (S8*) asciiString);
    mmi_ucs2cat((S8*) causeString, (S8*) ucs2String);

    if (rsp->msg_number <= 1)
    {
        mmi_ucs2cat((S8*) causeString, (S8*) GetString(STR_SMS_MESSAGE_COPIED));
    }
    else
    {
        mmi_ucs2cat((S8*) causeString, (S8*) GetString(STR_SMS_MESSAGES_COPIED));
    }

    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup((PU8) causeString, IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT, (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) causeString, IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) WARNING_TONE);
    }
    OslMfree(asciiString);
    OslMfree(ucs2String);
    OslMfree(causeString);
    
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
        }
        else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
        }
        else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
        }
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
    else
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
	
    DeleteMessagesHistoryNodes();
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  index           [IN]        
 *  action          [IN]        
 *  dst_storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_req(U16 type, U16 index, U8 action, U8 dst_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_set_highlight_msg(0);
#endif 

    if (index == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_frm_sms_copy_sms(mmi_msg_copy_msg_all_rsp, MOD_MMI, type, index, action, dst_storage);
    }
    else
    {
        mmi_frm_sms_copy_sms(mmi_msg_copy_msg_rsp, MOD_MMI, type, index, action, dst_storage);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_abort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_copy_abort();
}

#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_phone_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_phone_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_INBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_sim_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_sim_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_INBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();
    
    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_ME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_phone_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_phone_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_SENT_ID, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen_ext(STR_OUTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL,mmi_msg_copy_msg_all_abort);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_sim_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_sim_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_SENT_ID, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen_ext(STR_OUTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_ME);
}


#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_phone_unsentbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_phone_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_UNSENT_ID, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort); 
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_UNSENT, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_SM);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_sim_unsentbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_sim_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_UNSENT_ID, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_UNSENT, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_ME);
}
#endif /* __MMI_UNIFIED_MESSAGE__ */


#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_phone_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_phone_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_DRAFTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_from_sim_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_from_sim_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_DRAFTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_ME);
}
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dst_storage = SMSAL_ME;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex, SMSAL_COPY_MSG, dst_storage);
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
        #ifdef __MMI_UNIFIED_MESSAGE__
            mmi_msg_set_processing_screen(STR_UM_SENT_ID, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);
        #else 
            mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);
        #endif 
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex, SMSAL_COPY_MSG, dst_storage);
            break;

#ifdef __MMI_UNIFIED_MESSAGE__
        case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            mmi_msg_set_processing_screen(STR_UNSENTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex, SMSAL_COPY_MSG, dst_storage);
            break;
#endif /* __MMI_UNIFIED_MESSAGE__ */
			
        #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
            mmi_msg_set_processing_screen(STR_DRAFTBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex, SMSAL_COPY_MSG, dst_storage);
            break;
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case TO_DISPLAY_MESSAGE_LIST_SIMBOX:
            {               
                mmi_msg_set_processing_screen(STR_SIMBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, 0);                
                mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_SIM, (U16) g_msg_cntx.currBoxIndex, SMSAL_COPY_MSG, SMSAL_ME);
            }
            break;        
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    }
    mmi_msg_entry_processing_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_frm_sms_copy_result_struct* rsp = (mmi_frm_sms_copy_result_struct*)data; */
    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    }
    else
    {
        if (result == MMI_FRM_SMS_MEMFULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
    }
    
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
    else
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

    DeleteMessagesHistoryNodes();
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalInbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    U16 totalOutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
    U16 totalDraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);
    mmi_frm_sms_copy_result_struct *rsp = (mmi_frm_sms_copy_result_struct*) data;

    S8 *asciiString = OslMalloc(30);
    S8 *ucs2String = OslMalloc(60);
    S8 *causeString = OslMalloc(100);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_DONE));
    }
    else if (result == MMI_FRM_SMS_MEMFULL)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_SMS_FAILURE_MEM_FULL));
    }
    else if (result == MMI_FRM_SMS_ABORT)
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_CANCEL));
    }
    else
    {
        mmi_ucs2cpy((S8*) causeString, (S8*) GetString(STR_GLOBAL_UNFINISHED));
    }

    if (rsp->msg_number <= 1)
    {
        sprintf((S8*) asciiString, "\n  %d ", (U32) rsp->msg_number);
    }
    else
    {
        sprintf((S8*) asciiString, "\n  %d ", (U32) rsp->msg_number);
    }

    mmi_asc_to_ucs2((S8*) ucs2String, (S8*) asciiString);
    mmi_ucs2cat((S8*) causeString, (S8*) ucs2String);

    if (rsp->msg_number <= 1)
    {
        mmi_ucs2cat((S8*) causeString, (S8*) GetString(STR_SMS_MESSAGE_MOVED));
    }
    else
    {
        mmi_ucs2cat((S8*) causeString, (S8*) GetString(STR_SMS_MESSAGES_MOVED));
    }

    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup((PU8) causeString, IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT, (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) causeString, IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) WARNING_TONE);
    }
    OslMfree(asciiString);
    OslMfree(ucs2String);
    OslMfree(causeString);
    
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
    else
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
	
    DeleteMessagesHistoryNodes();
    mmi_msg_set_msg_num_hint(totalInbox, totalOutbox, totalDraftbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  index           [IN]        
 *  action          [IN]        
 *  dst_storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_req(U16 type, U16 index, U8 action, U8 dst_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_set_highlight_msg(0);
#endif 

    if (index == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_frm_sms_copy_sms(mmi_msg_move_msg_all_rsp, MOD_MMI, type, index, action, dst_storage);
    }
    else
    {
        mmi_frm_sms_copy_sms(mmi_msg_move_msg_rsp, MOD_MMI, type, index, action, dst_storage);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_abort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_copy_abort();
}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_phone_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_phone_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_INBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_sim_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_sim_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_INBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_ME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_phone_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_phone_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_SENT_ID, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen_ext(STR_OUTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_sim_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_sim_outbox(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UM_SENT_ID, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_set_processing_screen_ext(STR_OUTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_ME);
}


#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_phone_unsentbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_phone_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UNSENTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_UNSENT, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_SM);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_sim_unsentbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_sim_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_UNSENTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_UNSENT, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_ME);
}

#endif /* __MMI_UNIFIED_MESSAGE__ */


#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_phone_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_phone_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_DRAFTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

	mmi_msg_move_msg_req(MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_SM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_from_sim_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_from_sim_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   	mmi_msg_set_processing_screen_ext(STR_DRAFTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

	mmi_msg_move_msg_req(MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_ME);
}
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dst_storage = SMSAL_ME;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            mmi_msg_set_processing_screen(STR_INBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_move_msg_req(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex, SMSAL_MOVE_MSG, dst_storage);
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
            mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_move_msg_req(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex, SMSAL_MOVE_MSG, dst_storage);
            break;

#ifdef __MMI_UNIFIED_MESSAGE__
        case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            mmi_msg_set_processing_screen(STR_UNSENTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_move_msg_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex, SMSAL_MOVE_MSG, dst_storage);
            break;
#endif /* __MMI_UNIFIED_MESSAGE__ */
			
#ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
            mmi_msg_set_processing_screen(STR_DRAFTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            mmi_msg_move_msg_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex, SMSAL_MOVE_MSG, dst_storage);
            break;
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case TO_DISPLAY_MESSAGE_LIST_SIMBOX:
            {               
                mmi_msg_set_processing_screen(STR_SIMBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);                
                mmi_msg_move_msg_req(MMI_FRM_SMS_APP_SIM, (U16) g_msg_cntx.currBoxIndex, SMSAL_MOVE_MSG, SMSAL_ME);
            }
            break;        
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    }
    mmi_msg_entry_processing_generic();
}
#endif /* __MMI_MESSAGES_COPY__ */ /* ifdef __MMI_MESSAGES_COPY__ */



#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__


void mmi_frm_sms_delete_current_archive_msg(void)
{
    mmi_msg_delete_msg_req(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);
    //mmi_frm_sms_delete_one_archive_msg_req(mmi_msg_delete_msg_rsp, MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex); 
}

void mmi_msg_get_archive_rsp(U16 fromBoxType,  U16 result)  //here, fromboxtype==>mmi_frm_sms_msgbox_enum
{

    if (result != MMI_FRM_SMS_OK)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_DELETE_SMS_QUERY_ID),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_frm_sms_delete_current_archive_msg, KEY_EVENT_UP);
        DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);			
        return;   
    }

    if ( (fromBoxType == MMI_FRM_SMS_INBOX) || (fromBoxType == MMI_FRM_SMS_UNREAD))	
    {
        if (fromBoxType == MMI_FRM_SMS_UNREAD)
        {
            mmi_frm_sms_archive_change_status_to_read(MMI_FRM_SMS_ARCHIVE, (U16) (g_msg_cntx.currBoxIndex)); 
        }        
        mmi_msg_entry_archive_msg_inbox();
    }
    else
    {
        mmi_msg_entry_archive_msg_outbox();
    }       
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);	

}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type = *(U16*) data;
    EMSData *pEms;
    MMI_BOOL is_compress = MMI_FALSE;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);

    switch (pEms->PortNum.dst_port)
    {
    #if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
        case MMI_RINGTONE_MSG_PORT_NUM:
            mmi_nsm_set_msg_type(RINGTONE_MESSAGE);
            PrepareEntryNsmRingtoneoption();
            break;

        case MMI_PIC_MSG_PORT_NUM:
            mmi_nsm_set_msg_type(PICTURE_MESSAGE);
            PrepareEntryNsmPicturemsg();
            break;
    #endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    #ifdef __MMI_OPERATOR_LOGO__
        case MMI_OPLOGO_MSG_PORT_NUM:
            mmi_nsm_set_msg_type(PICTURE_MESSAGE);
            mmi_op_logo_parse_ota_data();
            break;
    #endif /* __MMI_OPERATOR_LOGO__ */ 
    #ifdef __MMI_CLI_ICON__
        case MMI_CLI_ICON_MSG_PORT_NUM:
            mmi_nsm_set_msg_type(PICTURE_MESSAGE);
            mmi_cli_icon_parse_ota_data();
            break;
    #endif /* __MMI_CLI_ICON__ */ 
        default:    /* MMI_NORMAL_MSG_PORT_NUM */
    #if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
            mmi_nsm_set_msg_type(NORMAL_MESSAGE);
    #endif 

            /* The SMS is NSM so that SMS content shall show "Not Support" */
            if (pEms->PortNum.dst_port == 0x1581 || pEms->PortNum.dst_port == 0x158A
                || pEms->PortNum.dst_port == 0x1582 || pEms->PortNum.dst_port == 0x1583)
            {
                type |= (SMSAL_MTI_UNSPECIFIED << 12);
                PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
                mmi_msg_entry_default_msg();
                break;
            }

        #ifdef __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__
            /* Do not display SMS with 8bit dcs */
            if (pEms->dcs == SMSAL_8BIT_DCS)
            {
                type |= (SMSAL_MTI_UNSPECIFIED << 12);
                PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
                mmi_msg_entry_default_msg();
                break;
            }
        #endif /* __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__ */
        
            /* Compress dcs SMS is not supported. */
            for (i = 0; i < PendingSaveSendData.totalSegments; i++)
            {
                ems_decode_dcs(PendingSaveSendData.ori_dcs[i], &is_compress);
                if (is_compress == TRUE)
                {
                    break;
                }
            }
            if (is_compress)
            {
                type |= (SMSAL_MTI_UNSPECIFIED << 12);
                PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
                mmi_msg_entry_default_msg();
                break;	
            }
            switch (type & 0x0fff)
            {
                case MMI_FRM_SMS_APP_UNREAD:
                case MMI_FRM_SMS_APP_INBOX:
                    if ((type & 0xf000) >> 12 == SMSAL_MTI_STATUS_REPORT)
                    {
                        mmi_msg_entry_default_msg();
                    }
                    else
                    {
#ifdef __MMI_MESSAGES_CHAT__
                		gChatInvitation = FALSE;
#endif /* __MMI_MESSAGES_CHAT__ */                       
                        mmi_msg_entry_inbox_msg();
                    }
                    break;

#ifdef __MMI_UNIFIED_MESSAGE__
				case MMI_FRM_SMS_APP_UNSENT:		
#endif /* __MMI_UNIFIED_MESSAGE__ */
                case MMI_FRM_SMS_APP_OUTBOX:
                case MMI_FRM_SMS_APP_DRAFTS:
                    mmi_msg_entry_outbox_msg();
                    break;
            #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                case MMI_FRM_SMS_APP_SIM:                
                    mmi_msg_entry_simbox_msg();
                    break;
            #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
            
                default:
                    mmi_msg_entry_default_msg();
                    break;
            }
            break;

    }

    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_msg_set_msg_icon(FALSE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_req(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION, STR_READING_SMS, IMG_GLOBAL_PROGRESS, 0);
    mmi_msg_entry_processing_generic();
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(type == MMI_FRM_SMS_APP_ARCHIVE)
    {
        //1. read archive from file
        mmi_frm_sms_read_one_archive_msg(mmi_msg_get_archive_rsp, type, index); //type is for future used        
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    {
        mmi_frm_sms_read_sms(mmi_msg_get_msg_rsp, MOD_MMI, type, index, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_INBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_OUTBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
}

#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_unsentbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_UNSENTBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex);
}
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_archive
 * DESCRIPTION
 *  read one archive msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_archive(void)  
{
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_ARCHIVE;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_draftbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_DRAFTBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
}

#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_check_class0_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  withobject      [IN]        
 *  content         [?]         
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_msg_check_class0_msg(void *data, int withobject, void *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_deliver_msg_struct *msg = (mmi_frm_sms_deliver_msg_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->display_type == SMSAL_MSG_TYPE_CLASS0
#ifdef __MMI_DUAL_SIM_MASTER__
		|| msg->display_type == MMI_FRM_SMS_TYPE_CLASS0_SLAVE
#endif
       )
    {
        return TRUE;
    }
    return FALSE;
}

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_send_pic_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bmpDataPtr      [?]         
 *  PicTextPtr      [?]         
 *  emsDataT        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_nsm_send_pic_msg(U8 *bmpDataPtr, U8 *PicTextPtr, U8 **emsDataT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptrOta = NULL;  /* pointer that will be returned by Pic msg */
    U16 count;          /* count for keeping data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptrOta = mmi_pmsg_convert_bmp_to_ota(bmpDataPtr);   /* convert BMP to OTA */

    if (ptrOta == NULL)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return -1;
    }

    count = mmi_pmsg_add_picture_text(ptrOta, PicTextPtr);  /* Add text to the OTA data */

    PRINT_INFORMATION("\nOTA Data Len to Send :%d", count);
    /* convert ASCII buffer to Hex and then store in PendingSaveSendData.TPUD_p */

    (*emsDataT) = OslMalloc((count + 1) * 2);
    memset((*emsDataT), '\0', ((count + 1) * 2));
    StuffZerosInBetween((S8*) (*emsDataT), (S8*) ptrOta, count + 1);

    OslMfree(ptrOta);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_get_msg_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_nsm_get_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMessageType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_set_msg_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_set_msg_type(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMessageType = type;
}


/*****************************************************************************
 * FUNCTION
 *  StuffZerosInBetween
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [?]         
 *  pInBuffer       [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 StuffZerosInBetween(S8 *pOutBuffer, S8 *pInBuffer, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 count = -1;
    U8 charLen = 0;
    U8 arrOut[2];
    U16 index = 0;
    U16 len = size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index < len)
    {
        mmi_wc_to_ucs2((U16) * pInBuffer, &charLen, arrOut);
        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;
        index++;

    }
    /* 
     * JP commented for tracker issue 846
     *   2 bytes memory leak
     */
#if (0)
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 
    return count + 1;
}

#if defined(__MMI_SMART_MESSAGE_MT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_is_unicode_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_nsm_is_unicode_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_count > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_get_picmsg_sendData
 * DESCRIPTION
 *  Store picture message OTA string in SendData.
 *  Set picture messsage Dest Port and Source Port.
 * PARAMETERS
 *  sendData        [?]     
 * RETURNS
 *  void
 * REMARKS
 *  NOTE :   Here we allocate memory to SendData string (emsDataT).And free it as follows
 *  
 *  (1)   Send Only      -  In mmi_frm_sms_send_sms_rsp
 *  
 *  (2)   Send To Many   -  In mmi_frm_sms_send_sms_rsp
 *  
 *  (3)   Send To Group  -  In mmi_frm_sms_send_sms_rsp
 *  
 *  (4) Save       -  In mmi_frm_sms_save_sms_rsp
 *  
 *  (5) Send and Save -  In mmi_frm_sms_send_sms_rsp
 *  
 *  (6) Save after send fail   - In mmi_frm_sms_send_sms_rsp
 *****************************************************************************/
static void mmi_nsm_get_picmsg_sendData(mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 AsciiTextBuffer[MAX_PICMSG_DEFAULT_DCS_TEXT_LEN*ENCODING_LENGTH+4]; */
    U8 *AsciiTextBuffer = NULL;
    U8 *emsDataT = NULL;
    S32 length = 0;
    S8 *tmp_txtptr = NULL;  /* Text buffer pointer */
    U16 tmp_ucs2_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AsciiTextBuffer = OslMalloc((MAX_PICMSG_DEFAULT_DCS_TEXT_LEN + 4) * ENCODING_LENGTH);
    memset(AsciiTextBuffer, '\0', ((MAX_PICMSG_DEFAULT_DCS_TEXT_LEN + 4) * ENCODING_LENGTH));

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    tmp_txtptr = (S8*) g_nsm_msg_context.textbuffer;
    tmp_ucs2_count = g_nsm_msg_context.UCS2_count;
#elif defined(__MMI_SMART_MESSAGE_MT__)
    tmp_txtptr = (S8*) picmsg_text_struct.pic_textbuff;
    tmp_ucs2_count = picmsg_text_struct.ucs2_count;
#endif 

    if (tmp_ucs2_count > 0)
    {
        mmi_ucs2cpy((S8*) AsciiTextBuffer, (S8*) tmp_txtptr);
    }
    else
    {
        mmi_ucs2_to_asc((S8*) AsciiTextBuffer, (S8*) tmp_txtptr);
    }

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    length = mmi_nsm_send_pic_msg(g_nsm_msg_context.picbuffer, AsciiTextBuffer, &emsDataT);
#elif defined(__MMI_SMART_MESSAGE_MT__)
    length = mmi_nsm_send_pic_msg(gNSMBuffer, AsciiTextBuffer, &emsDataT);
#endif 

    OslMfree(AsciiTextBuffer);

    if ((length < 0) || (emsDataT == NULL))
    {
        return;
    }
    sendData->sendrequire |= MMI_FRM_SMS_PORT;
    sendData->srcport = 0x0000;
    sendData->desport = 0x158A;
    sendData->dcs = SMSAL_8BIT_DCS;
    sendData->string = (S8*) emsDataT;
    sendData->stringlength = length;
}
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_all_msg_by_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  um_folder_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_all_msg_by_um(U8 um_folder_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_all_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_um_delete_all_ind_struct*) construct_local_para(sizeof(mmi_um_delete_all_ind_struct), TD_CTRL | TD_RESET);
    ind->msg_box_type = (UmMsgBoxType) um_folder_type;
    ind->msg_type = UM_MSG_TYPE_SMS;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_DELETE_ALL_IND, (oslParaType*) ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_delete_all_msg_by_um_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_delete_all_msg_by_um_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType msg_box_type = mmi_um_get_current_msg_box_type();
    mmi_um_delete_all_res_struct *msgRes = (mmi_um_delete_all_res_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRes->msg_type == UM_MSG_TYPE_SMS)
    {
        if (msgRes->result)
        {
            if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
            {            
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                g_msg_cntx.msg_ind_in_idle = 0;
            }
            else if (msg_box_type == UM_MSG_BOX_TYPE_SENT)
            {            
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (msg_box_type == UM_MSG_BOX_TYPE_ARCHIVE)
            {            
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
                }				
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
                }
		  else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
                }					
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/			
            else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT)
            {
			#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_UNSENTBOX_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_UNSENTBOX_OPTION);
                }
			#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
			#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
			#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            }
            else if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            else if (msg_box_type == UM_MSG_BOX_TYPE_SIM)
            {
            #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
                }
                else
            #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            
                if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
                }
                else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG))
                {
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                g_msg_cntx.sim_msg_ind_in_idle = FALSE;
            }        
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        }
        else
        {
            MMI_ASSERT(0);
        }

        DeleteMessagesHistoryNodes();
        g_msg_cntx.currBoxIndex = 0;

        /* archive will not affect full or new icon*/
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (msg_box_type != UM_MSG_BOX_TYPE_ARCHIVE)        
    #endif  
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (msg_box_type != UM_MSG_BOX_TYPE_SIM)            
    #endif 
        {
            g_msg_cntx.msg_full_ind = FALSE;
       #ifndef __MMI_DUAL_SIM_MASTER__
        	mmi_msg_set_msg_icon(FALSE, FALSE);
		#else /* __MMI_DUAL_SIM_MASTER__ */
			MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
			MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
		#endif /* __MMI_DUAL_SIM_MASTER__ */
        }
         
  
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_get_num_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_get_num_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_req_struct *msgReq = (mmi_um_get_msg_num_req_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgReq->msg_type == UM_MSG_TYPE_SMS)
    {
        U16 inbox_msg_number = 0;
        U16 inbox_unread_msg_number = 0;
        U16 unsent_msg_number = 0;
        U16 sent_msg_number = 0;
        U16 draft_msg_number = 0;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        U16 archive_msg_number = 0;	
        #endif
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        U16 sim_msg_number = 0;
    #endif
        mmi_um_get_msg_num_rsp_struct *msg =
            (mmi_um_get_msg_num_rsp_struct*) construct_local_para(sizeof(mmi_um_get_msg_num_rsp_struct), TD_CTRL | TD_RESET);

        msg->result = mmi_msg_get_msg_num(
                        &inbox_msg_number,
                        &inbox_unread_msg_number,
                        &unsent_msg_number,
                        &sent_msg_number, 
						&draft_msg_number 
                    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                        , &archive_msg_number
                    #endif 
                    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                        , &sim_msg_number
                    #endif
                        ); 
        msg->msg_type = UM_MSG_TYPE_SMS;
        msg->inbox_unread_msg_number = inbox_unread_msg_number;
        msg->inbox_read_msg_number = inbox_msg_number - inbox_unread_msg_number;
        msg->unsent_msg_number = unsent_msg_number;
        msg->sent_msg_number = sent_msg_number;
        msg->draft_msg_number = draft_msg_number;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        msg->archive_msg_number = archive_msg_number; 
        #endif
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        msg->sim_msg_number = sim_msg_number;
    #endif
        mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_RSP, (oslParaType*) msg, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_get_list_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_get_list_info_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_req_struct *msgReq = (mmi_um_get_list_req_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgReq->msg_type == UM_MSG_TYPE_SMS)
    {
        kal_uint16 start_entry = msgReq->start_entry;
        kal_uint16 msg_number = 0;
        kal_bool more = KAL_FALSE;
        mmi_um_get_list_rsp_struct *msg =
            (mmi_um_get_list_rsp_struct*) construct_local_para(sizeof(mmi_um_get_list_rsp_struct), TD_CTRL | TD_RESET);

        msg->result = mmi_msg_get_list_info(
                        msgReq->msg_box_type,
                        start_entry,
                        MMI_UM_MAX_GET_LIST_MSG_NUMBER,
                        &msg_number,
                        msg->list_info,
                        &more);
        msg->msg_type = UM_MSG_TYPE_SMS;
        msg->msg_box_type = msgReq->msg_box_type;
        msg->start_entry = start_entry;
        msg->msg_number = msg_number;
        msg->more = more;

        mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_GET_LIST_RSP, (oslParaType*) msg, NULL);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_get_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_get_msg_info_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_info_req_struct *msgReq = (mmi_um_get_msg_info_req_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgReq->msg_type == UM_MSG_TYPE_SMS)
    {
        kal_uint16 rsp_msg_number = 0;

        mmi_um_get_msg_info_rsp_struct *msg =
            (mmi_um_get_msg_info_rsp_struct*) construct_local_para(sizeof(mmi_um_get_msg_info_rsp_struct), TD_CTRL | TD_RESET);

        msg->result = mmi_msg_get_msg_info(
                        msgReq->msg_box_type,
                        msgReq->start_entry,
                        msgReq->msg_number,
                        &rsp_msg_number,
                        msg->msg_info);
        msg->msg_type = UM_MSG_TYPE_SMS;
        msg->msg_box_type = msgReq->msg_box_type;
        msg->start_entry = msgReq->start_entry;
        msg->msg_number = rsp_msg_number;
        mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_GET_MSG_INFO_RSP, (oslParaType*) msg, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_delete_folder_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_delete_folder_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_folder_req_struct *msgReq = (mmi_um_delete_folder_req_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgReq->msg_type == UM_MSG_TYPE_SMS)
    {
        mmi_msg_handle_delete_folder_by_um(msgReq->msg_box_type);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_ready_ind
 * DESCRIPTION
 *  send ready indication to UM
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_ready_ind(kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ready_ind_struct *msg = (mmi_um_ready_ind_struct*) construct_local_para(sizeof(mmi_um_ready_ind_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = result;
    msg->msg_type = UM_MSG_TYPE_SMS;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_READY_IND, (oslParaType*) msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_new_msg_ind
 * DESCRIPTION
 *  send new msg indication to UM
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  list_index          [IN]        
 *  timestamp           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_new_msg_ind(U8 msg_box_type, U16 list_index, U32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_new_msg_ind_struct *msg =
        (mmi_um_new_msg_ind_struct*) construct_local_para(sizeof(mmi_um_new_msg_ind_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->msg_type = UM_MSG_TYPE_SMS;
    msg->msg_box_type = (UmMsgBoxType) msg_box_type;
    msg->msg_index = list_index;
    msg->timestamp = timestamp;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_NEW_MSG_IND, (oslParaType*) msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_refresh_ind
 * DESCRIPTION
 *  send refresh ind to UM
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_refresh_ind(U8 msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_refresh_ind_struct *msg =
        (mmi_um_refresh_ind_struct*) construct_local_para(sizeof(mmi_um_refresh_ind_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->msg_type = UM_MSG_TYPE_SMS;
    msg->msg_box_type = (UmMsgBoxType) msg_box_type;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_highlight_decided_by_um_ind
 * DESCRIPTION
 *  send highlight need to change ind to UM when msg is deleted after sent
 * PARAMETERS
 *  msg_box_type        [IN]	UM box type
 *  msg_index			[IN]	the deleted msg index after sent 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_highlight_decided_by_um_ind(U8 msg_box_type, U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_decided_by_UM_struct *msg =
        (mmi_um_highlight_decided_by_UM_struct*) construct_local_para(sizeof(mmi_um_highlight_decided_by_UM_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg->msg_type = UM_MSG_TYPE_SMS;
    msg->msg_box_type = (UmMsgBoxType)msg_box_type;
	msg->msg_index = msg_index;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND, (oslParaType*)msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslSapId = MSG_SAP;
    Message.oslMsgId = MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_list_option_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_list_option_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type = *(U16*) data;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);

    /* The SMS is NSM so that SMS content shall show "Not Support" */
    if (pEms->PortNum.dst_port == 0x1581 || pEms->PortNum.dst_port == 0x158A
        || pEms->PortNum.dst_port == 0x1582 || pEms->PortNum.dst_port == 0x1583)
    {
        PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
        mmi_msg_entry_default_list_opt();
        DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
        return;
    }

#ifdef __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__
    /* Do not display SMS with 8bit dcs */
    if (pEms->dcs == SMSAL_8BIT_DCS)
    {
        PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
        mmi_msg_entry_default_list_opt();
        DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
        return;
    }
#endif /* __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__ */
    switch (type & 0x0fff)
    {
        case MMI_FRM_SMS_APP_UNREAD:
        case MMI_FRM_SMS_APP_INBOX:
            if ((type & 0xf000) >> 12 == SMSAL_MTI_STATUS_REPORT)
            {
                mmi_msg_entry_default_list_opt();
            }
            else
            {
                mmi_msg_entry_inbox_list_opt();
            }
            break;

		case MMI_FRM_SMS_APP_UNSENT:
        case MMI_FRM_SMS_APP_OUTBOX:
        case MMI_FRM_SMS_APP_DRAFTS:
            mmi_msg_entry_outbox_list_opt();
            break;
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_APP_SIM:       
            mmi_msg_entry_sim_list_opt();
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */        
        default:
            mmi_msg_entry_default_list_opt();
            break;
    }

    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
void mmi_msg_pre_entry_archive_list_option_rsp(U16 fromBoxType,  U16 result)  
{
    if (result != MMI_FRM_SMS_OK)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_DELETE_SMS_QUERY_ID),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_frm_sms_delete_current_archive_msg, KEY_EVENT_UP);
        DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);			
        return;   
    }

    //should not change to read here, because only option/view will set it to read
    if ((fromBoxType == MMI_FRM_SMS_INBOX) || (fromBoxType == MMI_FRM_SMS_UNREAD) )	
        mmi_msg_entry_archive_list_inbox_opt();
    else
        mmi_msg_entry_archive_list_outbox_opt();
	
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_list_option_req
 * DESCRIPTION
 *  Pre entry list option 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_list_option_req(U16 msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	if(msg_box_type != MMI_FRM_SMS_APP_UNSENT)
	{
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

		if (mmi_frm_sms_check_action_pending())
	    {
	        DisplayPopup(
	            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
	            IMG_GLOBAL_UNFINISHED,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) ERROR_TONE);
	        return;
	    }

	    mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION, STR_SMS_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
	    mmi_msg_entry_processing_generic();

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

	switch (msg_box_type)
    {
        case MMI_FRM_SMS_APP_INBOX:
        {
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_INBOX;
            mmi_frm_sms_read_sms(
                mmi_msg_pre_entry_list_option_rsp, 
                MOD_MMI, 
                MMI_FRM_SMS_APP_INBOX, 
                (U16) g_msg_cntx.currBoxIndex, 
                MMI_FALSE);
            break;
        }
        case MMI_FRM_SMS_APP_OUTBOX:
        {            
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_OUTBOX;
            mmi_frm_sms_read_sms(
                mmi_msg_pre_entry_list_option_rsp, 
                MOD_MMI, 
                MMI_FRM_SMS_APP_OUTBOX, 
                (U16) g_msg_cntx.currBoxIndex,
                MMI_FALSE);
            break;
        }

        case MMI_FRM_SMS_APP_UNSENT:
        {		
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
			mmi_msg_pre_entry_option_unsent();
#else  /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_UNSENTBOX;	
            mmi_frm_sms_read_sms(
                mmi_msg_pre_entry_list_option_rsp, 
                MOD_MMI, 
                MMI_FRM_SMS_APP_UNSENT, 
                (U16) g_msg_cntx.currBoxIndex,
                MMI_FALSE);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            break;
        }

        case MMI_FRM_SMS_APP_DRAFTS:
        {
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_DRAFTBOX;
            mmi_frm_sms_read_sms(
                mmi_msg_pre_entry_list_option_rsp, 
                MOD_MMI, 
                MMI_FRM_SMS_APP_DRAFTS, 
                (U16) g_msg_cntx.currBoxIndex,
                MMI_FALSE);
            break;
        }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
         case MMI_FRM_SMS_APP_ARCHIVE:
        {
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_ARCHIVE;
            mmi_frm_sms_read_one_archive_msg(
                mmi_msg_pre_entry_archive_list_option_rsp,
                MMI_FRM_SMS_APP_ARCHIVE, 
                (U16) g_msg_cntx.currBoxIndex);             
            break;
        }       
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_APP_SIM:
        {
            g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_SIMBOX;
            mmi_frm_sms_read_sms(
                mmi_msg_pre_entry_list_option_rsp, 
                MOD_MMI, 
                MMI_FRM_SMS_APP_SIM, 
                (U16) g_msg_cntx.currBoxIndex,
                MMI_FALSE);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }    
    }    
}

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete_all_simbox
 * DESCRIPTION
 *  Highlight simbox delete all handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_delete_msg_all_simbox,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_msg_all_simbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_msg_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_msg_set_confirm_screen(STR_SIMBOX_DELETEALL_QUERY, mmi_msg_delete_msg_all_simbox, GoBackHistory);
    mmi_msg_entry_confirm_generic();
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_msg_all_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_msg_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_delete_all_msg_by_um(UM_MSG_BOX_TYPE_SIM);
    return;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_simbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_copy_msg_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_SIMBOX_MENUENTRY, STR_SMS_COPYING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_copy_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_copy_msg_req(MMI_FRM_SMS_APP_SIM, MMI_FRM_SMS_INVALID_INDEX, SMSAL_COPY_MSG, SMSAL_ME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_all_simbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_move_msg_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_processing_screen_ext(STR_SIMBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, STR_GLOBAL_CANCEL, NULL, mmi_msg_move_msg_all_abort);
    mmi_msg_entry_processing_generic();

    mmi_msg_move_msg_req(MMI_FRM_SMS_APP_SIM, MMI_FRM_SMS_INVALID_INDEX, SMSAL_MOVE_MSG, SMSAL_ME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_simbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_SIMBOX;
    mmi_msg_get_msg_req(MMI_FRM_SMS_APP_SIM, (U16) g_msg_cntx.currBoxIndex);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_sim_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_sim_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back to Idle screen if the new msg is deleted by AT or SIM refresh is ongoing. */
    if (!mmi_msg_need_new_sim_msg_ind() || mmi_frm_sms_is_in_sim_refresh())
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        g_msg_cntx.sim_msg_ind_in_idle = FALSE;
        return;
    }

    g_msg_cntx.sim_msg_ind_in_idle = FALSE;
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (!mmi_frm_sms_check_action_pending())
    {       
        mmi_um_pre_entry_simbox();        
    }    
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_protocol_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND, mmi_msg_handle_new_msg_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_READY_IND, mmi_msg_handle_ready_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_AVAILABLE_IND, mmi_msg_handle_mem_avail_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_EXCEED_IND, mmi_msg_handle_mem_exceed_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_FULL_IND, mmi_msg_handle_mem_full_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND, mmi_msg_handle_msg_waiting_ind);
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND, mmi_msg_sync_msgbox_with_at);
    mmi_frm_sms_reg_msg_check(mmi_msg_check_class0_msg, mmi_msg_handle_class0_msg_ind);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP, mmi_msg_handle_sms_set_status_rsp);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __MMI_MESSAGES_CHAT__
    mmi_frm_sms_reg_msg_check(CheckForChatMessage, HandleChatMessage);
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
    SetProtocolEventHandler(mmi_msg_handle_delete_all_msg_by_um_rsp, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES);
    SetProtocolEventHandler(mmi_msg_handle_get_num_req, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ);
    SetProtocolEventHandler(mmi_msg_handle_get_list_info_req, PRT_MSG_ID_MMI_UM_GET_LIST_REQ);
    SetProtocolEventHandler(mmi_msg_handle_get_msg_info_req, PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ);
    SetProtocolEventHandler(mmi_msg_handle_delete_folder_req, PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_check_interrupt_in_sending
 * DESCRIPTION
 *  check whether it exist an interrupt from other application when sending sms.
 * PARAMETERS
 *  void
 * RETURNS
 *  If exist, return MMI_TRUE, else return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_msg_check_interrupt_in_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (GetExitScrnID() == SCR_ID_MSG_SENDING)
	{
		return MMI_FALSE;
	}
	else
	{
		return MMI_TRUE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_replace_sending_to_processing
 * DESCRIPTION
 *  replace the sending sms screen to the processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_replace_sending_to_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	HistoryReplace(SCR_ID_MSG_SENDING, SCR_ID_MSG_PROCESSING, mmi_msg_entry_processing_generic);

	g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_PROCESSING;
}


#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
static void mmi_msg_handle_failed_popup_timer(void);
static U8 failed_popup_flag;
static U8 status_change_flag;


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_send_sms_from_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_sms_set_status_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 refresh_box_type = 0;
	U16 unsent_box_index = *(U16*)data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (result)
	{
		case MMI_FRM_SMS_SUCTOSEND:
			{
				BOOL is_save_sent_msg = FALSE;
				UmMsgBoxType box_type;

				box_type = mmi_um_get_current_msg_box_type();
				if (box_type == UM_MSG_BOX_TYPE_UNSENT)
				{
					U16 box_size;

					if (((GetExitScrnID() == SCR_ID_MSG_UNSENTBOX_OPTION) || 
					     IsScreenPresent(SCR_ID_MSG_UNSENTBOX_OPTION)) &&
						(g_msg_cntx.background_sending_index == g_msg_cntx.currBoxIndex))
					{
						DisplayPopup(
				            (PU8) GetString(STR_SMS_BACKGROUND_NOT_EXIST_ID),
				            IMG_GLOBAL_WARNING,
				            1,
				            MESSAGES_POPUP_TIME_OUT,
				            (U8) WARNING_TONE);
						DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
					}

					mmi_msg_send_highlight_decided_by_um_ind(UM_MSG_BOX_TYPE_UNSENT, (U16)g_msg_cntx.background_sending_index);

					box_size = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_UNSENT);
					if (box_size > 0)
					{	
						if (g_msg_cntx.currBoxIndex > 0)
						{
							if (g_msg_cntx.currBoxIndex > g_msg_cntx.background_sending_index)
							{
								g_msg_cntx.currBoxIndex = g_msg_cntx.currBoxIndex - 1;
							}
						}
					}
				}

				mmi_msg_update_unsent_icon();

				mmi_frm_sms_get_background_save_setting(&is_save_sent_msg);
				if(is_save_sent_msg == TRUE)
				{
					refresh_box_type |= UM_MSG_BOX_TYPE_SENT;
				}
			}
			break;

		case MMI_FRM_SMS_FAILTOSEND:
			{
				DisplayPopup(
			        (PU8) GetString(STR_SMS_SEND_FAILED),
			        IMG_SEND_FAIL_PIC_MSG,
			        1,
			        MESSAGES_POPUP_TIME_OUT,
			        (U8) ERROR_TONE);
				
				if (IsScreenPresent(SCR_ID_MSG_UNSENTBOX_OPTION))
				{
					failed_popup_flag = TRUE;
					StartTimer(MMI_MSG_FAILED_POPUP_TIMER_ID, (MESSAGES_POPUP_TIME_OUT / 2), mmi_msg_handle_failed_popup_timer);	

					if (g_msg_cntx.background_sending_index == g_msg_cntx.currBoxIndex)
					{
						DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
					}
				}
			}
			break;

		case MMI_FRM_SMS_SENDING:
			{
				g_msg_cntx.background_sending_index = unsent_box_index;

				if (mmi_msg_get_unsent_operate_state() != UNSENT_SEND_STATE)
				{
					if (((GetExitScrnID() == SCR_ID_MSG_UNSENTBOX_OPTION) || 
						 IsScreenPresent(SCR_ID_MSG_UNSENTBOX_OPTION)) &&
						(g_msg_cntx.background_sending_index == g_msg_cntx.currBoxIndex))
					{
						if (failed_popup_flag == FALSE)
						{
							DisplayPopup(
								(PU8) GetString(STR_SMS_BACKGROUND_STATUS_CHANGED_ID),
								IMG_GLOBAL_WARNING,
								1,
								MESSAGES_POPUP_TIME_OUT,
								(U8) WARNING_TONE);
							DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
						}
						else
						{
							status_change_flag = TRUE;
						}
					}
				}
				mmi_msg_update_unsent_icon();
			}
			break;

		case MMI_FRM_SMS_WAITING:	
		default:
			break;
	}

	refresh_box_type |= UM_MSG_BOX_TYPE_UNSENT;

	mmi_msg_send_refresh_ind(refresh_box_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_failed_popup_timer
 * DESCRIPTION
 *  handler failed popup timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_handle_failed_popup_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	failed_popup_flag = FALSE;

	if (status_change_flag == TRUE)
	{
		DisplayPopup(
			(PU8) GetString(STR_SMS_BACKGROUND_STATUS_CHANGED_ID),
			IMG_GLOBAL_WARNING,
			1,
			MESSAGES_POPUP_TIME_OUT,
			(U8) WARNING_TONE);
		DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
		status_change_flag = FALSE;
	}
	StopTimer(MMI_MSG_FAILED_POPUP_TIMER_ID);
}

#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_ascii_to_usc2
 * DESCRIPTION
 *  Convert ASCII content to USC2;
 *  Remove Null char which is not end of the message content;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_ascii_to_usc2(S8* out_usc2, const S8* in_ascii, U16 ascci_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 ascii_index = 0;
	U16 usc2_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(ascii_index < ascci_len)
	{
		if (in_ascii[ascii_index] != '\0')
		{
			out_usc2[usc2_index] = in_ascii[ascii_index];
			out_usc2[usc2_index + 1] = 0;

			usc2_index += 2; 
		}
		ascii_index++;
	}

	out_usc2[usc2_index] = 0;
	out_usc2[usc2_index + 1] = 0;
}

#endif /* __MOD_SMSAL__ */ 

