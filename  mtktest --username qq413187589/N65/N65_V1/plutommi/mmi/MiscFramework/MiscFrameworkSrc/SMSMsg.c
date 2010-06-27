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
 *  SMSMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __MOD_SMSAL__


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
#include "CallHistoryGProts.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "AlarmFrameworkProt.h"
#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "CSP.h"
#include "sim_common_enums.h"
/*  */
#include "wgui_status_icons.h"
/*  */
/*  */
#include "FileManagerGProt.h"
/*  */

#include "DateTimeGprot.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"
#include "app_datetime.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif

#if defined(__MMI_MESSAGES_USE_URL__)
#include "wap_ps_struct.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_MessageSetup.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef MMI_FRM_SMS_INVALID_INDEX
#define MMI_FRM_SMS_INVALID_INDEX   0xffff
#endif 
#ifndef MMI_FRM_SMS_INVALID_NUM
#define MMI_FRM_SMS_INVALID_NUM     0xff
#endif 
#ifndef MMI_FRM_SMS_MSG_LEN
#define MMI_FRM_SMS_MSG_LEN      160
#endif 
#ifndef MMI_FRM_SMS_MSG_SEQ_NUM
#define MMI_FRM_SMS_MSG_SEQ_NUM  5
#endif 
#ifndef MMI_FRM_SMS_ACTION_SIZE
#define MMI_FRM_SMS_ACTION_SIZE     15
#endif 

#define MMI_FRM_SMS_SEND_SEG     1

static msg_profile_list_struct *profileList;
static msg_profile_edit_struct *profileDetail;
static msg_mailbox_edit_struct *mailboxDetail;

#ifdef __MMI_MESSAGES_COPY__
static mmi_frm_sms_copy_result_struct *copyResult;
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
mmi_frm_sms_send_struct *sendSMS;
#else /* __MMI_DUAL_SIM_MASTER__ */
static mmi_frm_sms_send_struct *sendSMS;
#endif /* __MMI_DUAL_SIM_MASTER__ */
static mmi_frm_sms_send_struct *saveSMS;
static MYTIME sms_saved_time;
static U16 sendResult = MMI_FRM_SMS_OK;
static U16 readIndex;

static mmi_frm_sms_register_struct mmi_frm_sms_interrupt_handler[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_interrupt_handler_size = 0;

extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE);

#if ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
extern nsm_msg_struct g_nsm_msg_context;
#endif 

/* Call before EMSPack  */
extern void EMS_ConvertAsciiEncodingToGSM7BitDefault(EMSData *data);
extern void EMS_ConvertAsciiEncodingToGSM7BitDefaultWithExtended(EMSData *data);

/* Call after EMSUnpack */
extern void EMS_ConvertGSM7BitDefaultEncodingToAscii(EMSData *data);
extern void EMS_ConvertGSM7BitDefaultEncodingToAsciiWithExtended(EMSData *data);

extern MMI_BOOL g_mmi_frm_sms_change_status;

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern unsigned short *mmi_frm_sms_sim_list;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern PsFuncPtrU16 backgroundSendAbortcallback;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
MMI_BOOL g_mmi_frm_sms_list_finish = FALSE;
#endif

static U16 unreadIndex = MMI_FRM_SMS_INVALID_INDEX;
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_sendsms_data
 * DESCRIPTION
 *  free control buffer of sendSMS and sendSMS->string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_sms_free_sendsms_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sendSMS != NULL)
    {
        if (sendSMS->string != NULL)
        {
            OslMfree(sendSMS->string);
            sendSMS->string = NULL;
        }
        OslMfree(sendSMS);
        sendSMS = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_savesms_data
 * DESCRIPTION
 *  free control buffer of saveSMS and saveSMS->string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_sms_free_savesms_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (saveSMS != NULL)
    {
        if (saveSMS->string != NULL)
        {
            OslMfree(saveSMS->string);
            saveSMS->string = NULL;
        }
        OslMfree(saveSMS);
        saveSMS = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_message
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
void mmi_frm_sms_send_message(
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
    Message.oslMsgId = (msg_type)MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_interrupt_handler
 * DESCRIPTION
 *  Register interrupt handle
 * PARAMETERS
 *  mod             [IN]        Module type
 *  msgid           [IN]        Message id
 *  callback        [IN]        Callback of interrupt
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_interrupt_handler(module_type mod, U16 msgid, PsFuncPtrU16 callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_interrupt_handler[mmi_frm_sms_interrupt_handler_size].molude = mod;
    mmi_frm_sms_interrupt_handler[mmi_frm_sms_interrupt_handler_size].msgid = msgid;
    mmi_frm_sms_interrupt_handler[mmi_frm_sms_interrupt_handler_size].callback = callback;
    mmi_frm_sms_interrupt_handler_size++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_interrupt_callback
 * DESCRIPTION
 *  callback interrupt handle
 * PARAMETERS
 *  mod             [IN]        Module type
 *  msgid           [IN]        Message id
 *  inMsg           [IN]        msg
 *  result			[IN]		result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_interrupt_callback(module_type mod, U16 msgid, void *inMsg, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < mmi_frm_sms_interrupt_handler_size)
    {
        if (mmi_frm_sms_interrupt_handler[i].msgid == msgid)
        {
            mmi_frm_sms_interrupt_handler[i].callback(inMsg, mod, result);
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_ready_ind
 * DESCRIPTION
 *  Handle ready indication
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_ready_ind(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    // to initialize archive msg here
    if (mmi_frm_sms_init_archive() == MMI_FALSE)  
    {
        MMI_ASSERT(0);
    }
#endif
    g_frm_sms_cntx.mmi_frm_sms_ready = TRUE;
    mmi_frm_sms_get_profile_list(NULL, MOD_MMI);
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    mmi_frm_sms_get_common_settings(NULL, MOD_MMI);
#endif 
    mmi_msg_pre_entry_cb_channel_bootup();
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_READY_IND, NULL, MMI_FRM_SMS_OK);
	mmi_frm_sms_retry_new_msg_ind();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_startup_read_req
 * DESCRIPTION
 *  SMS startup read request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_startup_read_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_startup_read_ind
 * DESCRIPTION
 *  Handle SMS startup read indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_startup_read_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *msgInd = (MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT*) inMsg;
    U8 sendreq = (msgInd->startup_seq_num == 0) ? 1 : 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->startup_seq_num == 0)
    {
        sendreq = TRUE;
    }
	
	if (mmi_bootup_is_sim_valid())
	{
		mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
		U8 seg = (msgInd->concat_info & 0xff000000) >> 24;
    	U8 thisseg = ((seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 0) ?
        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : (seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size);
        U8 total_seg = (msgInd->concat_info & 0x00ff0000) >> 16;

        if (seg > total_seg || seg == 0 || total_seg == 0)
	    {
		    thisseg = 1;
	    }

		memset((S8*) entry, 0, sizeof(mmi_frm_sms_msgbox_struct));
		
	    mmi_frm_sms_convert_startup_read_to_entry((MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT*) msgInd, entry);
	    mmi_frm_sms_add_sms_to_msgbox(entry, msgInd->index, thisseg);

		OslMfree(entry);
	}   

    if (sendreq)
    {
        mmi_frm_sms_startup_read_req(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_startup_finish_ind
 * DESCRIPTION
 *  Handle SMS startup finish indication
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_startup_finish_ind(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (mmi_bootup_is_sim_valid())
    {
        mmi_frm_sms_get_sim_memory_req();
    }
#else /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    mmi_frm_sms_create_sms_list();
#ifdef __MMI_DUAL_SIM_MASTER__
  g_mmi_frm_sms_list_finish = TRUE;
#endif
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_startup_begin_ind
 * DESCRIPTION
 *  Handle SMS startup begin indication
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_startup_begin_ind(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init msgbox in case of sim refresh */
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_frm_sms_init_msgbox();
#else /* __MMI_DUAL_SIM_MASTER__ */
	if (!MTPNP_AD_Msgbox_Is_Init())
	{
		mmi_frm_sms_init_msgbox();
		MTPNP_AD_Msgbox_HasInit();
	}
	/* SIM refresh, unload master SMS */
	else
	{
		MTPNP_PFAL_Master_SMS_Unload();
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetProtocolEventHandler(mmi_frm_sms_startup_read_ind, PRT_MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND);
    SetProtocolEventHandler(mmi_frm_sms_startup_finish_ind, PRT_MSG_ID_MMI_SMS_STARTUP_FINISH_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_status_report_ind
 * DESCRIPTION
 *  Handle status report
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_status_report_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_STATUS_REPORT_IND_STRUCT *data = (MMI_FRM_SMS_STATUS_REPORT_IND_STRUCT*) inMsg;
	mmi_frm_sms_status_report_ind_struct *msgInd = OslMalloc(sizeof(mmi_frm_sms_status_report_ind_struct));
   
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    U8 msg_ref;
    U16 delivery_report_awaited_index;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_convert_status_report(data, msgInd);
	/* If current status report is Temporary error, will not handle */
	if (msgInd->st >= ST_TE1_CONGESTION && msgInd->st <= ST_TE1_ERROR_IN_SME)
	{
		OslMfree(msgInd);
		return;
	}
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
	msg_ref = msgInd->mr;
    /* check if mr is in delivery report awaited list */
    delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_mr(msg_ref);

    /* mr is in delivery report awaited list */
    if (delivery_report_awaited_index != MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_set_delivery_report_awaited_check(delivery_report_awaited_index, msg_ref, msgInd->st);

        if (mmi_frm_sms_check_delivery_report_awaited_complete(delivery_report_awaited_index))
        {
            msgInd->st = mmi_frm_sms_get_delivery_report_awaited_result(delivery_report_awaited_index);
            mmi_frm_sms_remove_delivery_report_awaited(delivery_report_awaited_index);

            mmi_frm_sms_convert_time_stamp(msgInd->dt, msgInd->dt);
			mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND, msgInd, MMI_FRM_SMS_OK);   
        }
    }
    /* Also indicate user if the mr is not in delivery report awaited list */        
    /* For the case that the sending maybe aborted but actually the SMS is sent */
    else
    {
        mmi_frm_sms_convert_time_stamp(msgInd->dt, msgInd->dt);
		mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND, msgInd, MMI_FRM_SMS_OK);       
    }
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 
    mmi_frm_sms_convert_time_stamp(msgInd->dt, msgInd->dt);
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND, msgInd, MMI_FRM_SMS_OK);    
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 
	OslMfree(msgInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_msg_waiting_ind
 * DESCRIPTION
 *  Handle message waiting indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_msg_waiting_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND, inMsg, MMI_FRM_SMS_OK);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_mem_full_ind
 * DESCRIPTION
 *  Handle memory full indication
 * PARAMETERS
 *  inMsg           [?]         
 *  dummy(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_mem_full_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_FULL_IND, inMsg, MMI_FRM_SMS_OK);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_mem_exceed_ind
 * DESCRIPTION
 *  Handle memory exceed indication
 * PARAMETERS
 *  inMsg           [?]         
 *  dummy(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_mem_exceed_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_EXCEED_IND, inMsg, MMI_FRM_SMS_OK);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_mem_avai_ind
 * DESCRIPTION
 *  Handle memory available indication
 * PARAMETERS
 *  inMsg           [?]         
 *  dummy(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_mem_avai_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_MEM_AVAILABLE_IND, inMsg, MMI_FRM_SMS_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_msg_ind
 * DESCRIPTION
 *  Callback new message indication
 * PARAMETERS
 *  index       [IN]        New SMS index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_new_msg_ind(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *data = OslMalloc(sizeof(U16));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data = index;
	if ( mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
	{
		unreadIndex = index;
	}
	else
	{
		unreadIndex = MMI_FRM_SMS_INVALID_INDEX;
		mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND, (void*)data, MMI_FRM_SMS_OK);		
	}
    OslMfree(data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_retry_new_msg_ind
 * DESCRIPTION
 *  Callback new message indication
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_retry_new_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (unreadIndex != MMI_FRM_SMS_INVALID_INDEX)
	{
		mmi_frm_sms_new_msg_ind(unreadIndex);
	}    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_sms_ind
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_new_sms_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DELIVER_MSG_IND_STRUCT *msgInd = (MMI_FRM_SMS_DELIVER_MSG_IND_STRUCT*) inMsg;
    mmi_frm_sms_deliver_msg_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_msg_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHISTIncRecvdSMS();
    /* convert L4 data to MMI data */
    mmi_frm_sms_convert_new_sms(msgInd, data);

    /* put to awaited list last entry, from now on only process new data as awaited list last entry */
    mmi_frm_sms_add_new_sms(data, msgInd->no_msg_data, msgInd->msg_data);

    /* process new sms data */
    mmi_frm_sms_new_sms();

    OslMfree(data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_data_ind
 * DESCRIPTION
 *  Handle new SMS with port number indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_new_data_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_APP_DATA_IND_STRUCT *msgInd = (MMI_FRM_SMS_APP_DATA_IND_STRUCT*) inMsg;
    mmi_frm_sms_deliver_data_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_data_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert L4 data to MMI data */
    mmi_frm_sms_convert_new_data(msgInd, data);

    /* put to awaited list last entry, from now on only process new data as awaited list last entry */
    mmi_frm_sms_add_new_data(data, msgInd->message_len, msgInd->msg_data);

    /* process new sms data */
    mmi_frm_sms_new_data();

    OslMfree(data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_port_rsp
 * DESCRIPTION
 *  Register port response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_port_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_REG_PORT_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_REG_PORT_NUM_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U16 cause = msgRsp->cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&cause, result);
}


#ifdef  __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_slave_port_rsp
 * DESCRIPTION
 *  Register slave SIM port response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_slave_port_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_REG_PORT_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_REG_PORT_NUM_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U16 cause = msgRsp->cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearSlaveProtocolEventHandler(PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&cause, result);
}
#endif /* __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_port_req
 * DESCRIPTION
 *  Register port request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_port_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_REG_PORT_NUM_REQ_STRUCT *msgReq;
    mmi_frm_sms_data_check_struct *data = (mmi_frm_sms_data_check_struct*) inMsg;
	module_type mod_des = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_REG_PORT_NUM_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->enable = data->enable;
    msgReq->mod_id = data->module;
    msgReq->port_num = data->desport;
    
#ifdef  __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__
	if (data->isSlave == TRUE)
	{
		mod_des = MOD_L4C_2;
		SetSlaveProtocolEventHandler(mmi_frm_sms_reg_slave_port_rsp, PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP);
	}
	else	
#endif /* __MMI_DUAL_SIM_MASTER__ */
	{
		SetProtocolEventHandler(mmi_frm_sms_reg_port_rsp, PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP);
	}

#ifndef __MMI_DUAL_SIM_DUAL_CALL__
    mmi_frm_sms_send_message(MOD_MMI, mod_des, 0, PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ, (oslParaType*) msgReq, NULL);
#else	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_DUAL_CALL__ */
    OslMfree(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sc_addr_rsp
 * DESCRIPTION
 *  Get SC address response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sc_addr_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        if (msgRsp->sc_addr.length == 0)
        {
            if (sendSMS->sendcheck & MMI_FRM_SMS_NOT_ALLOW_EMPTY_SC)
            {
                mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_SC_EMPTY);
                mmi_frm_sms_free_sendsms_data();
            }
            else
            {
                mmi_frm_sms_entry_sc();
            }
        }
        else
        {
            sendSMS->sendcheck |= MMI_FRM_SMS_SC;
            mmi_frm_sms_send_sms_req();
        }
    }
    else
    {
        mmi_frm_sms_callback_action(NULL, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sc_addr_req
 * DESCRIPTION
 *  Get SC address request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sc_addr_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT *msgReq;
    U8 index = *(U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->profile_no = index;
    SetProtocolEventHandler(mmi_frm_sms_get_sc_addr_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_sc_addr_rsp
 * DESCRIPTION
 *  Set SC address response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_sc_addr_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;

        /* sending screen is displayed by SMS framework */
        if ((sendSMS->sendcheck & MMI_FRM_SMS_SCR) != MMI_FRM_SMS_SCR)
        {
            DisplayPopupCallBack(
                (PU8) GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE,
                mmi_frm_sms_send_sms_req);
        }
        else /* sending screen is displayed by applications */
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);

            StartTimer(
                MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID, 
                MESSAGES_POPUP_TIME_OUT, 
                mmi_frm_sms_send_sms_req);    
        }

        DeleteScreenIfPresent(SCR_ID_MSG_SC_NUMBER);

        sendSMS->sendcheck |= MMI_FRM_SMS_SC;
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__      
		if (g_frm_sms_background_send_info.sc_addr.length == 0)
		{			
			g_frm_sms_background_send_info.sc_addr.length = strlen((S8*) g_frm_sms_background_send_info.sc_addr.number);
		}
	
	#endif
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_MSG_SC_NUMBER);
        mmi_frm_sms_callback_action(NULL, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_sc_addr_req
 * DESCRIPTION
 *  Set SC address request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_sc_addr_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PROFILE_PARAMS_REQ_STRUCT *msgReq;
    msg_profile_edit_struct *profile = (msg_profile_edit_struct*) inMsg;
    S8 scAddress[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_SET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));

    memset(scAddress, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) profile->scAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->profile_no = profile->profileIndex;
    if (scAddress[0] == '+')
    {
        msgReq->sc_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->sc_addr.length = (strlen(scAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress) - 1);
        memcpy(msgReq->sc_addr.number, scAddress + 1, msgReq->sc_addr.length);
    }
    else
    {
        msgReq->sc_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->sc_addr.length =
            (strlen(scAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress));
        memcpy(msgReq->sc_addr.number, scAddress, msgReq->sc_addr.length);
    }
	
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	{
		S16 errorCode = 0;
		U8 activeProfileNo = 0;

        ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &activeProfileNo, DS_BYTE, &errorCode);       
		if (activeProfileNo == profile->profileIndex)
		{
			memset(&(g_frm_sms_background_send_info.sc_addr), 0x00, sizeof(l4c_number_struct));
			memcpy(&(g_frm_sms_background_send_info.sc_addr), &(msgReq->sc_addr), sizeof(l4c_number_struct));
			g_frm_sms_background_send_info.sc_addr.length = 0;
		}
	}
#endif

    memset(&msgReq->sc_addr.number[msgReq->sc_addr.length], 0, 1);
    msgReq->para_ind = SMSAL_PARA_SCA;
    SetProtocolEventHandler(mmi_frm_sms_set_sc_addr_rsp, PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
}

#ifdef _CHECK_FDL_BY_MMI_


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_fdl_rsp
 * DESCRIPTION
 *  Check FDL response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_check_fdl_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_FDN_CHECK_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_FDN_CHECK_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_FDN_CHECK_RSP);
    if ((msgRsp->result) == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        sendSMS->sendcheck |= MMI_FRM_SMS_FDL;
        mmi_frm_sms_send_sms_req();
    }
    else
    {
        mmi_frm_sms_callback_action(NULL, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_fdl_req
 * DESCRIPTION
 *  Check FDL request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_check_fdl_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_FDN_CHECK_REQ_STRUCT *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_FDN_CHECK_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    SetProtocolEventHandler(mmi_frm_sms_check_fdl_rsp, PRT_MSG_ID_MMI_SMS_FDN_CHECK_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_FDN_CHECK_REQ, (oslParaType*) msgReq, NULL);
    OslMfree(inMsg);
}
#endif /* _CHECK_FDL_BY_MMI_ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_rsp
 * DESCRIPTION
 *  Abort SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ABORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_ABORT_FINISH_IND);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    g_frm_sms_cntx.is_aborting = MMI_FALSE;
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_ABORT;
    }
    mmi_frm_sms_free_sendsms_data();
    mmi_frm_sms_callback_action(NULL, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_ind
 * DESCRIPTION
 *  Handle abort indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_SUCCEED);
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_FAILED);
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_ABORT_START_IND);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
	    		ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    mmi_frm_sms_entry_abort();
#ifndef __MMI_DUAL_SIM_MASTER__
    SetProtocolEventHandler(mmi_frm_sms_abort_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
#else
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_ABORT_FINISH_IND,
											MTPNP_PFAL_Abort_SMS_Rsp);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			SetProtocolEventHandler(mmi_frm_sms_abort_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
			break;
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_req
 * DESCRIPTION
 *  Abort SMS request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_abort_sms_ind(NULL);
    g_frm_sms_cntx.is_aborting = MMI_TRUE;
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_AD_Abort_SMS();
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
			break;
	}
#endif
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_callback_abort_sms_by_end_key
 * DESCRIPTION
 *  Abort SMS by end key callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_callback_abort_sms_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *number = OslMalloc(MAX_DIGITS_SMS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) number, 0, MAX_DIGITS_SMS);
    memcpy((S8*) number, (S8*) sendSMS->number, MAX_DIGITS_SMS);
    mmi_frm_sms_callback_action(number, MMI_FRM_SMS_END_FROM_SENDING);
    OslMfree(number);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_by_end_key_rsp
 * DESCRIPTION
 *  Abort SMS by end key response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_by_end_key_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT*)inMsg; */
    g_frm_sms_cntx.is_aborting = MMI_FALSE;
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);

    mmi_frm_sms_free_sendsms_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_req_by_end_key
 * DESCRIPTION
 *  Abort SMS request without processing screen
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_req_by_end_key(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
    SetProtocolEventHandler(mmi_frm_sms_abort_sms_by_end_key_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
    g_frm_sms_cntx.is_aborting = MMI_TRUE;
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_callback
 * DESCRIPTION
 *  Abort SMS callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_frm_sms_cntx.is_aborting = MMI_FALSE;
    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ABORT);
    mmi_frm_sms_free_sendsms_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_dummy_rsp
 * DESCRIPTION
 *  Abort SMS dummy response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_dummy_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT*)inMsg; */
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
    g_frm_sms_cntx.is_aborting = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sending_sms_req
 * DESCRIPTION
 *  Abort Sending SMS request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sending_sms_req(mmi_frm_sms_abort_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
    
    g_frm_sms_cntx.is_aborting = MMI_TRUE;

    if (type == MMI_FRM_SMS_ABORT_WITH_FINISH_IND)
    {
        SetProtocolEventHandler(mmi_frm_sms_abort_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
    }
    else if (type == MMI_FRM_SMS_ABORT_WITHOUT_FINISH_IND)
    {
        SetProtocolEventHandler(mmi_frm_sms_abort_sms_dummy_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND); 
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
        mmi_frm_sms_abort_sms_callback();
    }
    else
    {
        MMI_ASSERT(0);
    }        
}

/* loop handle */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_sms_rsp
 * DESCRIPTION
 *  Send SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_send_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_MSG_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PendingSaveSendData.presentSegments--;
    if ((msgRsp->result) == TRUE)
    {
#ifndef __MMI_DUAL_SIM_MASTER__
        CHISTIncSentSMS();
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
			 CHISTIncSentSMS();
		default:
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else
    {
        sendResult = MMI_FRM_SMS_ERROR;
    }

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
#ifndef __MMI_DUAL_SIM_MASTER__
    if (g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting)
    {
        mmi_frm_sms_check_delivery_report_awaited(msgRsp->result, msgRsp->concat_info, msgRsp->mr);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
	case MTPNP_AD_CHANNEL_SLAVE:
	case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
	    if (g_frm_sms_cntx.mmi_frm_sms_slave_delivery_report_setting)
	    {
	        mmi_frm_sms_check_delivery_report_awaited(msgRsp->result, msgRsp->concat_info, msgRsp->mr);
	    }

		break;
	case MTPNP_AD_CHANNEL_MASTER:
	case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		  if (g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting)
		  {
		  	mmi_frm_sms_check_delivery_report_awaited(msgRsp->result, msgRsp->concat_info, msgRsp->mr);
		  }
	default:
		break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 

    /* send SMS: pack and send the following segment, inMsg keeps the sent index */
    if (sendResult != MMI_FRM_SMS_ERROR && PendingSaveSendData.nextSegment < PendingSaveSendData.totalSegments)
    {
        mmi_frm_sms_send_sms_seg();
    }
    if (PendingSaveSendData.presentSegments == 0)
    {
        /* not always; use a flag to check */
        U8 *number = OslMalloc(MAX_DIGITS_SMS);

        memset((S8*) number, 0, MAX_DIGITS_SMS);
        memcpy((S8*) number, (S8*) sendSMS->number, MAX_DIGITS_SMS);
        if (((sendSMS->sendrequire & MMI_FRM_SMS_SAVE) == 0) &&
            ((sendSMS->sendrequire & MMI_FRM_SMS_SAVE_AFTER_FAIL) == 0))
        {
            ReleaseEMSEditBuffer();
        }
        mmi_frm_sms_free_sendsms_data();
#ifndef __MMI_DUAL_SIM_MASTER__
        ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
        ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_SUCCEED);
			MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_FAILED);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
			ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
	        ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
		default:
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
	/* no more to send or send fail: returns the result */
        mmi_frm_sms_callback_action((void*)number, sendResult);
        OslMfree(number);
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        g_frm_sms_background_send_info.foreground_state = MMI_FRM_SMS_SEND_STATE_IDLE;
        mmi_frm_sms_background_send_schedule();
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        
    }
}

extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_pack_sms
 * DESCRIPTION
 *  Pack SMS before send/save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_frm_sms_pack_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS = GetEMSDataForEdit(0, 0);
    EMSPosition SavedPosition = pEMS->CurrentPosition;
    U16 i;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(PendingSaveSendData.TPUD, 0, sizeof(PendingSaveSendData.TPUD));

    for (i = 0; i < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size; i++)
    {
        PendingSaveSendData.TPUD_udhi[i] = 0;
        PendingSaveSendData.TPUDLen[i] = 0;
        PendingSaveSendData.TPUD_p[i] = &PendingSaveSendData.TPUD[i * MMI_FRM_SMS_MSG_LEN];
    }

    if (pEMS->dcs == SMSAL_DEFAULT_DCS || pEMS->dcs == SMSAL_UCS2_DCS)
    {
        EMS_ConvertAsciiEncodingToGSM7BitDefaultWithExtended(pEMS);
    }

    result = EMSPack(
                pEMS,
                1,
                &PendingSaveSendData.totalSegments,
                PendingSaveSendData.TPUD_p,
                PendingSaveSendData.TPUDLen);
    if (pEMS->dcs == SMSAL_DEFAULT_DCS || pEMS->dcs == SMSAL_UCS2_DCS)
    {
       EMS_ConvertGSM7BitDefaultEncodingToAsciiWithExtended(pEMS);
    }
    MoveCursorToPosition(pEMS, &SavedPosition);
    if (sendSMS != NULL)    /* in sending procedure */
    {
        PendingSaveSendData.phNumber = (S8*) sendSMS->number;
    }
    else if (saveSMS != NULL)   /* in saving procedure */
    {
        PendingSaveSendData.phNumber = (S8*) saveSMS->number;
    }
    else
    {
        MMI_ASSERT(sendSMS != NULL || saveSMS != NULL);
    }
    PendingSaveSendData.udhi = pEMS->udhi;
    PendingSaveSendData.dcs[0] = pEMS->ps_dcs;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_unpack_sms
 * DESCRIPTION
 *  Unpack SMS after read/receive
 * PARAMETERS
 *  dcs     [IN]        Dcs
 *  fo      [IN]        Fo
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_unpack_sms(U8 dcs, U8 fo, U8 ori_dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    EMSData *pEMSdata;
    U8 UDHI;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_USE_URL__
    GetEMSDataForView(&pEMSdata, 0);
    memset(pEMSdata->textBuffer, 0x00, pEMSdata->textLength);   /* Remove previous message content */
#endif /* __MMI_MESSAGES_USE_URL__ */ 
    GetEMSDataForView(&pEMSdata, 1);
    if (PendingSaveSendData.totalSegments == 1)
    {
        UDHI = GetUDHIBit(fo);
    }
    else
    {
        UDHI = KAL_TRUE;
        for (i = 0; i < PendingSaveSendData.totalSegments; i++)
        {
            if (PendingSaveSendData.TPUD_udhi[i] == KAL_FALSE)
            {
                PendingSaveSendData.TPUD_p[i] = NULL;
            }
        }
    }
    if ((EMSSetDCS(pEMSdata, dcs) == EMS_OK) &&        
        (EMSUnPack(pEMSdata, UDHI, PendingSaveSendData.totalSegments, PendingSaveSendData.TPUD_p,
          PendingSaveSendData.TPUDLen, PendingSaveSendData.dcs) == EMS_OK) &&
        (EMSSetOriDCS(pEMSdata, PendingSaveSendData.ori_dcs, PendingSaveSendData.totalSegments) == EMS_OK))
    {
    }
    else
    {
        GetEMSDataForView(&pEMSdata, 1);
        if (PendingSaveSendData.totalSegments == 1)
        {
            UDHI = KAL_FALSE;
        }
        else
        {
            UDHI = KAL_TRUE;
        }
        for (i = 0; i < PendingSaveSendData.totalSegments; i++)
        {
            PendingSaveSendData.TPUD_p[i] = NULL;
            PendingSaveSendData.TPUDLen[i] = 0;
        }
        EMSSetDCS(pEMSdata, SMSAL_DEFAULT_DCS);
        EMSUnPack(
            pEMSdata,
            UDHI,
            PendingSaveSendData.totalSegments,
            PendingSaveSendData.TPUD_p,
            PendingSaveSendData.TPUDLen, PendingSaveSendData.dcs);
    }

    if (pEMSdata->dcs == SMSAL_DEFAULT_DCS || pEMSdata->dcs == SMSAL_UCS2_DCS)
    {
        EMS_ConvertGSM7BitDefaultEncodingToAsciiWithExtended(pEMSdata);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_sms_seg
 * DESCRIPTION
 *  Send SMS segment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_send_sms_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_MSG_REQ_STRUCT *sendSms;
    S8 *addr = (S8*) sendSMS->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSms = (MMI_FRM_SMS_SEND_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*sendSms));

    sendSms->dcs = PendingSaveSendData.dcs[0];
    sendSms->udhi = PendingSaveSendData.udhi;
    sendSms->length = PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment];
    memset(sendSms->msg, 0, SMSAL_MAX_MSG_LEN);
    memcpy(
        sendSms->msg,
        PendingSaveSendData.TPUD_p[PendingSaveSendData.nextSegment],
        PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment]);
    sendSms->profile = sendSMS->profile;
    sendSms->para = 0;
    sendSms->reply_index = MMI_FRM_SMS_INVALID_INDEX;
    if ((sendSMS->sendrequire & MMI_FRM_SMS_REPLY) == MMI_FRM_SMS_REPLY
         && sendSMS->replyindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        U8 *replyaddr = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_INBOX, sendSMS->replyindex);
        U16 l4_index[MMI_SMS_MAX_MSG_SEG];
        U8 i = 0;

        memset((S8*) sendSMS->number, 0, MAX_DIGITS_SMS);
        memcpy((S8*) sendSMS->number, (S8*) replyaddr, strlen((S8*) replyaddr));
        mmi_frm_sms_get_sms_index(MMI_FRM_SMS_INBOX, sendSMS->replyindex, l4_index);
        while (i < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size)
        {
            if (l4_index[i] != MMI_FRM_SMS_INVALID_INDEX)
            {
           	#ifndef __MMI_DUAL_SIM_MASTER__
                sendSms->reply_index = l4_index[i];
			#else /* __MMI_DUAL_SIM_MASTER__ */
				if (MTPNP_AD_Dual_Card_Reply_SMS())
				{
					switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
					{
						case MTPNP_AD_CHANNEL_SLAVE:
						case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
							if (l4_index[i] >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
							{
								sendSms->reply_index = MTPNP_AD_Get_SIM2_Index(l4_index[i]);
							}
							break;
						case MTPNP_AD_CHANNEL_MASTER:
						case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
						default:						
							if (l4_index[i] < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
							{
								sendSms->reply_index = l4_index[i];
							}							
							break;
					}
				}
				else
				{
					break;
				}
			#endif /* __MMI_DUAL_SIM_MASTER__ */
                break;
            }
            i++;
        }
    }

    if (sendSMS->number[0] == '+')
    {
        sendSms->dest.type = CSMCC_INTERNATIONAL_ADDR;
        addr++;
    }
    else
    {
        sendSms->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
    }
    memset((S8*) sendSms->dest.number, 0, MAX_CC_ADDR_LEN);
    memcpy((S8*) sendSms->dest.number, (S8*) addr, strlen((S8*) addr));
    sendSms->dest.length = strlen((S8*) addr);

    sendSms->seq_num = PendingSaveSendData.nextSegment;

    /* set  to 0 only in the last segment of the last message */
    if (((PendingSaveSendData.nextSegment + 1) < PendingSaveSendData.totalSegments) ||
        ((g_msg_cntx.msg_send_info.CurrSendSmsNumbers + 1) < g_msg_cntx.msg_send_info.TotalSendSmsNumbers))
    {
        sendSms->mms_mode = 1;
    }
    else
    {
        sendSms->mms_mode = 0;
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_SEND_MSG_REQ, (oslParaType*) sendSms, NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Send_Message_Segment((void *)sendSms);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
			 mmi_frm_sms_send_message(MOD_MMI,
			 							MOD_L4C, 
			 							0, 
			 							PRT_MSG_ID_MMI_SMS_SEND_MSG_REQ, 
			 							(oslParaType*) sendSms,
			 							NULL);
		default:
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    PendingSaveSendData.nextSegment++;
    PendingSaveSendData.presentSegments++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_pre_send_sms
 * DESCRIPTION
 *  Pre-send SMS: copy useful data and set flags
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_pre_send_sms(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = (mmi_frm_sms_send_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX ||
        g_frm_sms_cntx.is_aborting )/* The response of the abort is not received. */
    {
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_NOTREADY);
        if (sendData->string != NULL)
        {
            OslMfree(sendData->string);
            sendData->string = NULL;
        }
        OslMfree(sendData);
        return;
    }
    mmi_frm_sms_free_sendsms_data();
    sendSMS = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    memcpy((S8*) sendSMS, (S8*) sendData, sizeof(mmi_frm_sms_send_struct));
    OslMfree(sendData);
    mmi_frm_sms_send_sms_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_number_done
 * DESCRIPTION
 *  After input number, keep send process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_number_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) sendSMS->number, (S8*) g_frm_sms_cntx.mmi_frm_sms_number);
    len = strlen((S8*) sendSMS->number) <
        sizeof(sendSMS->number) ? strlen((S8*) sendSMS->number) : sizeof(sendSMS->number);

    if (len == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_check_dst_number(sendSMS->number, len) == KAL_FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        mmi_frm_sms_send_sms_req();
    }
}

extern EMSTATUS EMSSetMsgClass(EMSData *emsData, kal_uint8 msg_class);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_sms_req
 * DESCRIPTION
 *  Send SMS request: check sc, number and copy content for send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_send_sms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MOD_MMI only, other module skips */
    EMSData *pEMS = GetEMSDataForEdit(0, 0);
    U8 i, j;
    EMSTATUS EMSSetPortResult = EMS_OK;
    EMSTATUS EMSSetClassResult = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check SC: get SC address, inMsg keeps the flag */
    if ((sendSMS->sendcheck & MMI_FRM_SMS_SC) != MMI_FRM_SMS_SC)
    {
#if !defined(__MMI_DUAL_SIM_MASTER__)
        S16 errorCode = 0;
        S8 nvramActiveProfileIndex = 0;

        ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &nvramActiveProfileIndex, DS_BYTE, &errorCode);
        mmi_frm_sms_get_sc_addr_req(&nvramActiveProfileIndex);
        sendSMS->profile = nvramActiveProfileIndex;
        return;
#else /* __MMI_DUAL_SIM_MASTER__ */
        switch (MTPNP_AD_Get_Slave_Type())
        {
	        case MTPNP_CM_GSM_MODULE:
	        case MTPNP_PC_SIMULATOR:
	        {
	            S16 errorCode = 0;
	            S8 nvramActiveProfileIndex = 0;
	        
	            switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	            {
		            case MTPNP_AD_CHANNEL_SLAVE:
		            case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		                ReadValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &nvramActiveProfileIndex, DS_BYTE, &errorCode);
		                mmi_frm_sms_get_card2_sc_addr_req(&nvramActiveProfileIndex);
		                break;
		            case MTPNP_AD_CHANNEL_MASTER:
		            case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		            default:
		                ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &nvramActiveProfileIndex, DS_BYTE, &errorCode);
		                mmi_frm_sms_get_sc_addr_req(&nvramActiveProfileIndex);
		                break;
	            }
	            sendSMS->profile = nvramActiveProfileIndex;
	            return;
	        }
	            break;
	        case MTPNP_CM_PHS_MODULE:
	            break;
	        case MTPNP_CALIBRATION_TOOLS:
	        case MTPNP_UNKNOWN_MODULE:
	        default:
	            break;
        }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    }

    /* check DA: show input screen, inMsg keeps the number */
    if ((sendSMS->sendcheck & MMI_FRM_SMS_DA) != MMI_FRM_SMS_DA)
    {
        memset((S8*) g_frm_sms_cntx.mmi_frm_sms_number, 0, MAX_DIGITS_SMS);
        if ((sendSMS->sendrequire & MMI_FRM_SMS_NUM_SCR) == MMI_FRM_SMS_NUM_SCR)
        {
            mmi_asc_to_ucs2((S8*) g_frm_sms_cntx.mmi_frm_sms_number, (S8*) sendSMS->number);
            mmi_frm_sms_entry_number();
            sendSMS->sendrequire &= ~MMI_FRM_SMS_NUM_SCR;
            return;
        }
        else if ((strlen((S8*) sendSMS->number) == 0) && ((sendSMS->sendrequire & MMI_FRM_SMS_REPLY) == 0))
        {
            if (GetCurrScrnId() != SCR_ID_MSG_NUMBER)
            {
                mmi_frm_sms_entry_number();
            }
            return;
        }
        sendSMS->sendcheck |= MMI_FRM_SMS_DA;
    }

    /* check validity of DA */
    {
        U8 len = strlen((S8*) sendSMS->number) <
            sizeof(sendSMS->number) ? strlen((S8*) sendSMS->number) : sizeof(sendSMS->number);

        /* some digit is not numeric */
        if (mmi_frm_sms_check_dst_number(sendSMS->number, len) == KAL_FALSE)
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_NUMINVALID);
            mmi_frm_sms_free_sendsms_data();
            return;
        }
    }

    /* check FDL: when FDN on */
#ifdef _CHECK_FDL_BY_MMI_
    if ((sendSMS->sendcheck & MMI_FRM_SMS_FDL) != MMI_FRM_SMS_FDL)
    {
        if (gSecuritySetupContext.FdlStatus)
        {
            U8 *msg = OslMalloc(strlen((S8*) sendSMS->number));

            memcpy((S8*) msg, (S8*) sendSMS->number, strlen((S8*) sendSMS->number));
            mmi_frm_sms_check_fdl_req(msg);
            return;
        }
        sendSMS->sendcheck |= MMI_FRM_SMS_FDL;
    }
#endif /* _CHECK_FDL_BY_MMI_ */ 

    {
        S8 *textbuf = NULL;
        S8 *textbufucs2 = NULL;
        U32 textlen = 0;
        U16 result = 0;
        history temphistory;

        if (sendSMS->filename != NULL)
        {
            S32 errorCode = 0;
            FS_HANDLE emsObjectFilePtr;
            U32 read_size = 0;

            ReleaseEMSEditBuffer();
            pEMS = GetEMSDataForEdit(0, 1);

            emsObjectFilePtr = FS_Open((U16*) sendSMS->filename, FS_READ_ONLY);
            /* the file exists without error */
            if (emsObjectFilePtr > 0)
            {
                FS_GetFileSize(emsObjectFilePtr, &textlen);

                /* the file size is > 0 */
                if (textlen > 0)
                {
                    if (sendSMS->dcs == SMSAL_8BIT_DCS)
                    {
                        /* the file is too large. */
                        if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG) ||
                            textlen > ((MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE / ENCODING_LENGTH) - 1))
                        {
                            FS_Close(emsObjectFilePtr);
                            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
                            mmi_frm_sms_free_sendsms_data();
                            return;
                        }
                        /* the file size is allowed */
                        textbuf = OslMalloc(textlen + 1);
                        errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                        FS_Close(emsObjectFilePtr);
                        /* the file content is corrupted */
                        if (errorCode < 0)
                        {
                            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
                            OslMfree(textbuf);
                            mmi_frm_sms_free_sendsms_data();
                            return;
                        }
                        /* the file content is allowed */
                        textbufucs2 = OslMalloc((textlen + 1) * ENCODING_LENGTH);
                        mmi_asc_n_to_ucs2(textbufucs2, textbuf, textlen);
                        memset(textbufucs2 + textlen * ENCODING_LENGTH, 0, ENCODING_LENGTH);
                        OslMfree(textbuf);
                    }
                    /* UCS2 and  DEFAULT DCS */
                    else
                    {
                        /* the file is too large. */
                        if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG) ||
                            textlen > (MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE - ENCODING_LENGTH))
                        {
                            FS_Close(emsObjectFilePtr);
                            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
                            mmi_frm_sms_free_sendsms_data();
                            return;
                        }
                        /* the file size is allowed */
                        textbuf = OslMalloc(textlen + ENCODING_LENGTH);
                        errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                        FS_Close(emsObjectFilePtr);
                        /* the file content is corrupted */
                        if (errorCode < 0)
                        {
                            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
                            OslMfree(textbuf);
                            mmi_frm_sms_free_sendsms_data();
                            return;
                        }
                        /* the file content is allowed */
                        textbufucs2 = OslMalloc((textlen + ENCODING_LENGTH));
                        memset(textbufucs2, 0, (textlen + ENCODING_LENGTH));
                        memcpy(textbufucs2, textbuf, textlen);
                        OslMfree(textbuf);
                    }
                }
            }
            else
            {
                mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
                mmi_frm_sms_free_sendsms_data();
                return;
            }
        }
        else if (sendSMS->string != NULL && sendSMS->stringlength > 0)
        {
            ReleaseEMSEditBuffer();
            pEMS = GetEMSDataForEdit(0, 1);
            
            textbufucs2 = OslMalloc((sendSMS->stringlength) * ENCODING_LENGTH);
            memset((S8*) textbufucs2, 0, ((sendSMS->stringlength) * ENCODING_LENGTH));
            memcpy(textbufucs2, sendSMS->string, ((sendSMS->stringlength) * ENCODING_LENGTH));
        }

        if ((sendSMS->sendrequire & MMI_FRM_SMS_PORT) == MMI_FRM_SMS_PORT)
        {
            EMSSetPortResult = EMSSetPortNum(pEMS, sendSMS->srcport, sendSMS->desport);
        }
        if ((sendSMS->sendrequire & MMI_FRM_SMS_CLASS) == MMI_FRM_SMS_CLASS)
        {
            EMSSetClassResult = EMSSetMsgClass(pEMS, sendSMS->dcs_class);
        }

        if ((EMSSetPortResult != EMS_OK) || (EMSSetClassResult != EMS_OK))
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
            mmi_frm_sms_free_sendsms_data();
            if (textbufucs2)
            {
                OslMfree(textbufucs2);
            }
            return;
        }

        if (textbufucs2)
        {
            if (sendSMS->filename != NULL)
            {
                result = AppendEMSString(
                            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                            pEMS,
                            (U8*) textbufucs2,
                            sendSMS->dcs,
                            temphistory.guiBuffer);
            }
            else if (sendSMS->string != NULL)
            {
                EMSSetDCS(pEMS, sendSMS->dcs);
                result = AddString(pEMS, (U8*) textbufucs2, sendSMS->stringlength, NULL);
            }
            OslMfree(textbufucs2);

            if ((sendSMS->filename != NULL && result == 0) || (sendSMS->string != NULL && result != EMS_OK))
            {
                mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
                mmi_frm_sms_free_sendsms_data();
                return;
            }
        }

        result = mmi_frm_sms_pack_sms();
        if (result != EMS_OK)
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
            mmi_frm_sms_free_sendsms_data();
            return;
        }
        if ((sendSMS->sendcheck & MMI_FRM_SMS_SCR) != MMI_FRM_SMS_SCR)
        {
	    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	        if ((sendSMS->sendrequire & MMI_FRM_SMS_BACKGROUND_SEND) == MMI_FRM_SMS_BACKGROUND_SEND)
	        {
	            g_frm_sms_background_send_info.isBackground = TRUE;
	        }
			else
			{
				g_frm_sms_background_send_info.isBackground = FALSE;
			}
	    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            mmi_frm_sms_entry_send();
        }
        PendingSaveSendData.nextSegment = 0;
        PendingSaveSendData.presentSegments = 0;
        
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if ((sendSMS->sendrequire & MMI_FRM_SMS_BACKGROUND_SEND) == MMI_FRM_SMS_BACKGROUND_SEND)
        {
            sendSMS->status = SMSAL_STO_UNSENT;
            mmi_frm_sms_save_sms_to_unsent_seg();
        }
        else   
        {
        
            if (g_frm_sms_background_send_info.background_state == MMI_FRM_SMS_SEND_STATE_SENDING)
            {
                g_frm_sms_background_send_info.foreground_state = MMI_FRM_SMS_SEND_STATE_SUSPEND;                               
            }
            else
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            {
           	#ifndef __MMI_DUAL_SIM_MASTER__
                SetProtocolEventHandler(mmi_frm_sms_send_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
                SetProtocolEventHandler(mmi_frm_sms_abort_sms_ind, PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);			
			#else /* __MMI_DUAL_SIM_MASTER__ */
				switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
				{
					case MTPNP_AD_CHANNEL_SLAVE:
					case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
						MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_SUCCEED,
														MTPNP_PFAL_Send_Message_Succeed);
						MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SEND_MSG_FAILED,
														MTPNP_PFAL_Send_Message_Failed);
						break;
					case MTPNP_AD_CHANNEL_MASTER:
					case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
					default:
						SetProtocolEventHandler(mmi_frm_sms_send_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
				        SetProtocolEventHandler(mmi_frm_sms_abort_sms_ind, PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);
						break;
				}
			#endif /* __MMI_DUAL_SIM_MASTER__ */                
                j = (PendingSaveSendData.totalSegments >= MMI_FRM_SMS_SEND_SEG) ? MMI_FRM_SMS_SEND_SEG : 1;
                sendResult = MMI_FRM_SMS_OK;
                for (i = 0; i < j; i++)
                {
                    mmi_frm_sms_send_sms_seg();
                }  
            }
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        }
    #endif
    }
}

extern U8 GetRefFromNVRAM(void);

/* loop handle */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_rsp
 * DESCRIPTION
 *  Save SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_MSG_RSP_STRUCT*) inMsg;
#ifdef __MMI_UNIFIED_MESSAGE__
    U16 msgbox_index = 0;
#endif /* __MMI_UNIFIED_MESSAGE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
        U16 ref = (U16) GetRefFromNVRAM();

        memset((S8*) entry, 0, sizeof(mmi_frm_sms_msgbox_struct));

        ref = (ref > 0) ? (ref - 1) : MMI_FRM_SMS_INVALID_NUM;
        mmi_frm_sms_convert_mo_to_entry(
            saveSMS,
            entry,
            msgRsp->index,
            msgRsp->status,
            PendingSaveSendData.totalSegments,
            ref,
            msgRsp->storage_type,
            &sms_saved_time);

    #ifdef __MMI_UNIFIED_MESSAGE__
        /* Only save content for the first segment */
        if (PendingSaveSendData.nextSegment == 1)
        {
            U8 *content = OslMalloc(mmi_msg_get_max_content_size() * ENCODING_LENGTH);
            EMSData *pEMS = NULL;
            U32 content_size = 0;

            pEMS = GetEMSDataForEdit(0, 0);

            if (pEMS->dcs == SMSAL_UCS2_DCS)
            {
                content_size =
                    ((mmi_msg_get_max_content_size() - 1) <
                     (pEMS->textLength / 2)) ? (mmi_msg_get_max_content_size() - 1) : (pEMS->textLength / 2);

                memset(entry->content, 0, sizeof(entry->content));
                memset(content, 0, mmi_msg_get_max_content_size() * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) content, (S8*) pEMS->textBuffer, content_size);
            }
            else
            {
                U32 handled_content_size = mmi_msg_get_max_content_size() * 2 * ENCODING_LENGTH;
                U8 *handled_content = OslMalloc(handled_content_size);
                U32 handled_content_len = 0;
                U16 ori_content_size = 
                        ((mmi_msg_get_max_content_size() - 1) <
                         (pEMS->textLength / 2)) ? (mmi_msg_get_max_content_size() - 1) : (pEMS->textLength / 2);

                memset(handled_content, 0, handled_content_size);
                mmi_frm_sms_remove_escape_symbol_for_extension_char
                    ((U16*)handled_content, 
                     (U16*)pEMS->textBuffer, 
                     (U16) (ori_content_size));

                handled_content_len = mmi_ucs2strlen((S8*)handled_content);

                content_size =
                    ((mmi_msg_get_max_content_size() - 1) <
                     (handled_content_len)) ? (mmi_msg_get_max_content_size() - 1) : (handled_content_len);

                memset(entry->content, 0, sizeof(entry->content));
                memset(content, 0, mmi_msg_get_max_content_size() * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) content, (S8*) handled_content, content_size);

                OslMfree(handled_content);
            }

            if (mmi_ucs2strlen((S8*) content))
            {
                mmi_frm_sms_add_content_to_entry(entry, content);
            }

            OslMfree(content);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

	#ifdef __MMI_UNIFIED_MESSAGE__
        msgbox_index = mmi_frm_sms_add_sms_to_msgbox(entry, msgRsp->index, PendingSaveSendData.presentSegments);
	#else /* __MMI_UNIFIED_MESSAGE__ */
		mmi_frm_sms_add_sms_to_msgbox(entry, msgRsp->index, PendingSaveSendData.presentSegments);
	#endif /* __MMI_UNIFIED_MESSAGE__ */

        OslMfree(entry);
        if (PendingSaveSendData.nextSegment < PendingSaveSendData.totalSegments)
        {
            mmi_frm_sms_save_sms_seg();
        }
        else
        {
            ReleaseEMSEditBuffer();

        #ifdef __MMI_UNIFIED_MESSAGE__
            if (saveSMS->sendrequire & MMI_FRM_SMS_SAVE_MODIFY_HIGHLIGHT)
            {
                U16 type;
                U16 list_index;
                BOOL msg_box_match = KAL_FALSE;

                mmi_frm_sms_get_list_index(&type, &list_index, msgbox_index);

                switch (type)
                {
                    case MMI_FRM_SMS_INBOX:
                    {
                        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_INBOX)
                        {
                            msg_box_match = KAL_TRUE;
                        }
                        break;
                    }
                    case MMI_FRM_SMS_OUTBOX:
                    {
                        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SENT)
                        {
                            msg_box_match = KAL_TRUE;
                        }
                        break;
                    }
                    case MMI_FRM_SMS_DRAFTS:
                    {
                        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_DRAFT)
                        {
                            msg_box_match = KAL_TRUE;
                        }
                        break;
                    }
                    case MMI_FRM_SMS_UNSENT:
                    {
                        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_UNSENT)
                        {
                            msg_box_match = KAL_TRUE;
                        }
                        break;
                    }
                }

                if (msg_box_match)
                {
                    if (list_index <= g_msg_cntx.currBoxIndex)
                    {
                        g_msg_cntx.currBoxIndex++;
                    }
                }
            }

            if (saveSMS->sendrequire & MMI_FRM_SMS_SAVE_HIGHLIGHT_NEW_MSG_IND)
            {
                mmi_frm_sms_highlight_ind(MMI_FRM_SMS_NOBOX, msgbox_index);
            }

            if (saveSMS->sendrequire & MMI_FRM_SMS_SAVE_HIGHLIGHT_ORIGINAL_MSG_IND)
            {
                U8 type = mmi_um_get_current_msg_box_type();

                switch (type)
                {
                    case UM_MSG_BOX_TYPE_INBOX:
                    {
                        mmi_frm_sms_highlight_ind(MMI_FRM_SMS_INBOX, (U16)g_msg_cntx.currBoxIndex);
                        break;
                    }

                    case UM_MSG_BOX_TYPE_UNSENT:
                    {
                        mmi_frm_sms_highlight_ind(MMI_FRM_SMS_UNSENT, (U16)g_msg_cntx.currBoxIndex);
                        break;
                    }

                    case UM_MSG_BOX_TYPE_SENT:
                    {
                        mmi_frm_sms_highlight_ind(MMI_FRM_SMS_OUTBOX, (U16)g_msg_cntx.currBoxIndex);
                        break;
                    }
                    case UM_MSG_BOX_TYPE_DRAFT:
                    {
                        mmi_frm_sms_highlight_ind(MMI_FRM_SMS_DRAFTS, (U16)g_msg_cntx.currBoxIndex);
                        break;
                    }
                }
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 

            /* no more to send or send fail: returns the result */
            mmi_frm_sms_callback_action(&(saveSMS->status), MMI_FRM_SMS_OK);
            mmi_frm_sms_free_savesms_data();
        }
    }
    else
    {
        mmi_frm_sms_callback_action(&(saveSMS->status), MMI_FRM_SMS_MEMFULL);
        mmi_frm_sms_free_savesms_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_seg
 * DESCRIPTION
 *  Save SMS segment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_REQ_STRUCT *saveSms;
    S8 *addr = (S8*) saveSMS->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    saveSms = (MMI_FRM_SMS_SET_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*saveSms));
    /* memset((S8*)saveSms, 0, sizeof(MMI_FRM_SMS_SET_MSG_REQ_STRUCT)); */
	#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		if (saveSMS->status == SMSAL_STO_DRAFT)
		{
			saveSMS->status = SMSAL_STO_UNSENT;
		}
	#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    saveSms->status = saveSMS->status;
    if (addr[0] == '+')
    {
        saveSms->dest.type = CSMCC_INTERNATIONAL_ADDR;
        addr++;
    }
    else
    {
        saveSms->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
    }

    memset((S8*) saveSms->dest.number, 0, MAX_CC_ADDR_LEN);
    memcpy((S8*) saveSms->dest.number, (S8*) addr, strlen((S8*) addr));
    saveSms->dest.length = strlen((S8*) addr);

    saveSms->profile = saveSMS->profile;    /* active profile number.. */
    saveSms->para = 0;
    saveSms->udhi = PendingSaveSendData.udhi;
    saveSms->dcs = PendingSaveSendData.dcs[0];
    saveSms->length = PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment];
    saveSms->index = MMI_FRM_SMS_INVALID_INDEX;
    mmi_frm_sms_convert_mytime(saveSms->scts, &sms_saved_time);
    memset(saveSms->msg, 0, SMSAL_MAX_MSG_LEN);
    memcpy(
        saveSms->msg,
        PendingSaveSendData.TPUD_p[PendingSaveSendData.nextSegment],
        PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment]);
#ifndef __MMI_DUAL_SIM_MASTER__
    SetProtocolEventHandler(mmi_frm_sms_save_sms_rsp, PRT_MSG_ID_MMI_SMS_SET_MSG_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_SET_MSG_REQ, (oslParaType*) saveSms, NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_MSG_RSP,
											MTPNP_PFAL_Save_Message_Rsp);
			MTPNP_PFAL_Save_Message((void *)saveSms);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			SetProtocolEventHandler(mmi_frm_sms_save_sms_rsp, PRT_MSG_ID_MMI_SMS_SET_MSG_RSP);
	    		mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_SET_MSG_REQ, (oslParaType*) saveSms, NULL);
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    PendingSaveSendData.nextSegment++;
    PendingSaveSendData.presentSegments++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_req
 * DESCRIPTION
 *  Save SMS request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *textbuf = NULL;
    S8 *textbufucs2 = NULL;
    U32 textlen = 0;
    U16 result = 0;
    history temphistory;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do not replace saveSMS by sendSMS because sendSMS structure may be cleared by abort rsp */
    mmi_frm_sms_free_savesms_data();
    saveSMS = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    memcpy((S8*) saveSMS, (S8*) inMsg, sizeof(mmi_frm_sms_send_struct));
    OslMfree(inMsg);

    if (saveSMS->filename != NULL)
    {
        S32 errorCode = 0;
        FS_HANDLE emsObjectFilePtr;
        U32 read_size = 0 ;

        emsObjectFilePtr = FS_Open((U16*) saveSMS->filename, FS_READ_ONLY);
        /* the file exists without error */
        if (emsObjectFilePtr > 0)
        {
            FS_GetFileSize(emsObjectFilePtr, &textlen);

            /* the file size is 0 */
            if (textlen == 0)
            {
                FS_Close(emsObjectFilePtr);
                mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEMPTY);
                mmi_frm_sms_free_savesms_data();
                return;
            }

            if (saveSMS->dcs == SMSAL_8BIT_DCS)
            {
                /* the file is too large. */
                if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG / ENCODING_LENGTH) ||
                    textlen > ((MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE / ENCODING_LENGTH) - 1))
                {
                    FS_Close(emsObjectFilePtr);
                    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
                    mmi_frm_sms_free_savesms_data();
                    return;
                }
                /* the file size is allowed */
                textbuf = OslMalloc(textlen + 1);
                errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
                    OslMfree(textbuf);
                    mmi_frm_sms_free_savesms_data();
                    return;
                }
                /* the file content is allowed */
                textbufucs2 = OslMalloc((textlen + 1) * ENCODING_LENGTH);
                mmi_asc_n_to_ucs2(textbufucs2, textbuf, textlen);
                memset(textbufucs2 + textlen * ENCODING_LENGTH, 0, ENCODING_LENGTH);
                OslMfree(textbuf);
            }
            /* UCS2 and  DEFAULT DCS */
            else
            {
                /* the file is too large. */
                if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG) ||
                    textlen > (MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE - ENCODING_LENGTH))
                {
                    FS_Close(emsObjectFilePtr);
                    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
                    mmi_frm_sms_free_savesms_data();
                    return;
                }
                /* the file size is allowed */
                textbuf = OslMalloc(textlen + ENCODING_LENGTH);
                errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
                    OslMfree(textbuf);
                    mmi_frm_sms_free_savesms_data();
                    return;
                }
                /* the file content is allowed */
                textbufucs2 = OslMalloc((textlen + ENCODING_LENGTH));
                memset(textbufucs2, 0, (textlen + ENCODING_LENGTH));
                memcpy(textbufucs2, textbuf, textlen);
                OslMfree(textbuf);
            }
        }
        else
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
            mmi_frm_sms_free_savesms_data();
            return;
        }
    }
    else if (saveSMS->string != NULL && saveSMS->stringlength > 0)
    {
        textbufucs2 = OslMalloc((saveSMS->stringlength) * ENCODING_LENGTH);
        memset((S8*) textbufucs2, 0, ((saveSMS->stringlength) * ENCODING_LENGTH));
        memcpy(textbufucs2, saveSMS->string, ((saveSMS->stringlength) * ENCODING_LENGTH));
    }

    if (textbufucs2)
    {
        EMSTATUS EMSSetPortResult = EMS_OK;
        EMSTATUS EMSSetClassResult = EMS_OK;

        ReleaseEMSEditBuffer();
        pEMS = GetEMSDataForEdit(0, 1);
        if ((saveSMS->sendrequire & MMI_FRM_SMS_SAVE_PORT) == MMI_FRM_SMS_SAVE_PORT)
        {
            EMSSetPortResult = EMSSetPortNum(pEMS, saveSMS->srcport, saveSMS->desport);
        }
        if ((saveSMS->sendrequire & MMI_FRM_SMS_SAVE_CLASS) == MMI_FRM_SMS_SAVE_CLASS)
        {
            EMSSetClassResult = EMSSetMsgClass(pEMS, saveSMS->dcs_class);
        }

        if ((EMSSetPortResult != EMS_OK) || (EMSSetClassResult != EMS_OK))
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
            mmi_frm_sms_free_savesms_data();
            OslMfree(textbufucs2);
            return;
        }

        if (saveSMS->filename != NULL)
        {
            result = AppendEMSString(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) textbufucs2,
                        saveSMS->dcs,
                        temphistory.guiBuffer);
        }
        else if (saveSMS->string != NULL)
        {
            EMSSetDCS(pEMS, saveSMS->dcs);
            result = AddString(pEMS, (U8*) textbufucs2, saveSMS->stringlength, NULL);
        }
        OslMfree(textbufucs2);

        if ((saveSMS->filename != NULL && result == 0) || (saveSMS->string != NULL && result != EMS_OK))
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAEXCEED);
            mmi_frm_sms_free_savesms_data();
            return;
        }
    }

    /* JP added to save a NSm message */
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    if (saveSMS->desport == 0x158A)
    {
        EMSData *pEMS = NULL;

        ReleaseEMSEditBuffer();
        pEMS = GetEMSDataForEdit(0, 0);

        EMSSetPortNum(pEMS, saveSMS->srcport, saveSMS->desport);
        EMSSetDCS(pEMS, saveSMS->dcs);
        AddString(pEMS, (U8*) saveSMS->string, saveSMS->stringlength, NULL);
    }
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    result = mmi_frm_sms_pack_sms();
    if (result != EMS_OK)
    {
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_DATAINVALID);
        mmi_frm_sms_free_savesms_data();
    }
    else
    {
        PendingSaveSendData.nextSegment = 0;
        PendingSaveSendData.presentSegments = 0;
        GetDateTime(&sms_saved_time);

        if (saveSMS->sendrequire & MMI_FRM_SMS_SAVE_DISPLAY_SAVING_SCREEN)
        {
            mmi_frm_sms_entry_save();
        }

        mmi_frm_sms_save_sms_seg();
    }
}

/* loop handle */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_sms_rsp
 * DESCRIPTION
 *  Read SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_read_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MSG_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        memcpy(PendingSaveSendData.TPUD_p[PendingSaveSendData.presentSegments], msgRsp->msg_data, msgRsp->no_msg_data);
        PendingSaveSendData.TPUDLen[PendingSaveSendData.presentSegments] = (U8) msgRsp->no_msg_data;
        PendingSaveSendData.TPUD_udhi[PendingSaveSendData.presentSegments] = (U8) GetUDHIBit(msgRsp->fo);
        PendingSaveSendData.mti = msgRsp->mti;
        PendingSaveSendData.dcs[PendingSaveSendData.presentSegments] = msgRsp->dcs;
        PendingSaveSendData.ori_dcs[PendingSaveSendData.presentSegments] = msgRsp->ori_dcs;
        PendingSaveSendData.st = msgRsp->st;
    }
    else
    {
        PendingSaveSendData.dcs[PendingSaveSendData.presentSegments] = SMSAL_RESERVED_DCS;
        PendingSaveSendData.ori_dcs[PendingSaveSendData.presentSegments] = SMSAL_RESERVED_DCS;
        PendingSaveSendData.TPUD_p[PendingSaveSendData.presentSegments] = NULL;
        PendingSaveSendData.TPUDLen[PendingSaveSendData.presentSegments] = 0;
        PendingSaveSendData.TPUD_udhi[PendingSaveSendData.presentSegments] = KAL_FALSE;
    }

#ifndef __MMI_DUAL_SIM_MASTER__
	if (PendingSaveSendData.nextSegment < PendingSaveSendData.totalSegments && mmi_frm_sms_read_sms_seg() == TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
	if (PendingSaveSendData.nextSegment < PendingSaveSendData.totalSegments && MTPNP_PFAL_Read_SMS_Segment() == MTPNP_TRUE)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        return;
    }
    else
    {
        result = MMI_FRM_SMS_OK;
        if (msgRsp->result == TRUE)
        {
            switch (msgRsp->status)
            {
                case SMSAL_REC_UNREAD:
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_UNREAD;
                    break;
                case SMSAL_REC_READ:
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_INBOX;
                    break;

                case SMSAL_STO_SENT:
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_OUTBOX;
                    break;

                case SMSAL_STO_UNSENT:
                #ifdef __MMI_UNIFIED_MESSAGE__
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_UNSENT;
                #else
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_DRAFTS;
                #endif
                    break;
                    
                case SMSAL_STO_DRAFT:
                    type = (msgRsp->mti << 12) | MMI_FRM_SMS_DRAFTS;
                    break;
                    
            }
            mmi_frm_sms_unpack_sms(msgRsp->dcs, msgRsp->fo, msgRsp->ori_dcs);    /* change pendingsavesenddata struct */
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            if (msgRsp->storage_type == SMSAL_SM)
            {
                type = (msgRsp->mti << 12) | MMI_FRM_SMS_SIM;
            }
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        }
        else
        {
            PendingSaveSendData.mti = SMSAL_MTI_UNSPECIFIED;
            type = (SMSAL_MTI_UNSPECIFIED << 12) | MMI_FRM_SMS_NOBOX;
        }
        mmi_frm_sms_callback_action(&type, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_sms_seg
 * DESCRIPTION
 *  Read SMS segment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_read_sms_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (PendingSaveSendData.nextSegment < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size)
    {
        if (PendingSaveSendData.l4index[PendingSaveSendData.nextSegment] != MMI_FRM_SMS_INVALID_INDEX)
        {
            MMI_FRM_SMS_GET_MSG_REQ_STRUCT *msgReq;

            msgReq = (MMI_FRM_SMS_GET_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));

            msgReq->index = PendingSaveSendData.l4index[PendingSaveSendData.nextSegment];
            msgReq->change_status = g_mmi_frm_sms_change_status;
            SetProtocolEventHandler(mmi_frm_sms_read_sms_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_RSP);
            mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_REQ, (oslParaType*) msgReq, NULL);
            PendingSaveSendData.presentSegments = PendingSaveSendData.nextSegment;
            PendingSaveSendData.nextSegment++;
            return TRUE;
        }
        PendingSaveSendData.nextSegment++;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_sms_req
 * DESCRIPTION
 *  Read SMS request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_read_sms_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *index = (U16*) inMsg;
    U8 segment = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (segment = 0; segment < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size; segment++)
    {
        PendingSaveSendData.dcs[segment] = 0;
        PendingSaveSendData.ori_dcs[segment] = 0;
        PendingSaveSendData.l4index[segment] = index[segment];
        PendingSaveSendData.TPUD_udhi[segment] = 0;
        PendingSaveSendData.TPUDLen[segment] = 0;
        PendingSaveSendData.TPUD_p[segment] = &PendingSaveSendData.TPUD[segment * MMI_FRM_SMS_MSG_LEN];
    }
    PendingSaveSendData.totalSegments = (U8) index[g_frm_sms_cntx.mmi_frm_sms_msg_seg_size];
    OslMfree(inMsg);
    
    PendingSaveSendData.nextSegment = 0;
    PendingSaveSendData.presentSegments = 0;
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_frm_sms_read_sms_seg();
#else /* __MMI_DUAL_SIM_MASTER__ */
	MTPNP_PFAL_Read_SMS_Segment();
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_rsp
 * DESCRIPTION
 *  Get SMS response: update message box
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MSG_RSP_STRUCT*) inMsg;
    mmi_frm_sms_msgbox_struct *entry;
    U8 segment = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_MSG_RSP);
    
    if (msgRsp->result == TRUE)
    {
        entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
        if (((msgRsp->concat_info.seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 0)
        {
            segment = (U8) g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
        }
        else
        {
            segment = (msgRsp->concat_info.seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
        }        
        mmi_frm_sms_convert_read_to_entry(msgRsp, entry, readIndex);
        mmi_frm_sms_add_sms_to_msgbox(entry, readIndex, segment);
        
        OslMfree(entry);        
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_OK);
    }
    else
    {
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
    }
    
#ifdef __MMI_UNIFIED_MESSAGE__    
    mmi_msg_send_refresh_ind(UM_MSG_BOX_TYPE_INBOX | UM_MSG_BOX_TYPE_UNSENT | UM_MSG_BOX_TYPE_SENT |
                             UM_MSG_BOX_TYPE_DRAFT);    
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_req
 * DESCRIPTION
 *  Get SMS request for updating message box
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *index = (U16*) inMsg;
    MMI_FRM_SMS_GET_MSG_REQ_STRUCT *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_GET_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    readIndex = *index;
    msgReq->index = *index;
    msgReq->change_status = (kal_bool)FALSE;
    SetProtocolEventHandler(mmi_frm_sms_get_sms_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_REQ, (oslParaType*) msgReq, NULL);
    OslMfree(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms_rsp
 * DESCRIPTION
 *  Delete SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DEL_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_DEL_MSG_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        mmi_frm_sms_remove_sms_from_msgbox(msgRsp->del_bitmap);
    }

#if defined(__MMI_DUAL_SIM_MASTER__)
    MTPNP_PFAL_Set_Msgs_DelAll_State(DM_MASTER_BOX);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_sms_callback_action(NULL, result);
}

/* use index array delete at once!!! */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms_req
 * DESCRIPTION
 *  Delete SMS request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_sms_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *msgReq;
    U8 *index = (U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_DEL_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->del_flag = SMSAL_DEL_BITMAP;
    memcpy((S8*) msgReq->del_bitmap, (S8*) index, 480);
	msgReq->is_background_action = KAL_FALSE;
    SetProtocolEventHandler(mmi_frm_sms_delete_sms_rsp, PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ, (oslParaType*) msgReq, NULL);
    OslMfree(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_name_rsp
 * DESCRIPTION
 *  Get profile name response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_name_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        U16 tempLen = ((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
        U8 *tempbuf = OslMalloc(tempLen);
		
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		{
			S16 errorCode = 0;
			U8 activeProfileNo = 0;

            ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &activeProfileNo, DS_BYTE, &errorCode);
            if (activeProfileNo >= profileList->currMaxPsProfiles)
            {
                activeProfileNo = 0;
            }
			if (activeProfileNo == profileList->currReqProfileNo)
			{
				g_frm_sms_background_send_info.vp = msgRsp->vp;
				memset(&(g_frm_sms_background_send_info.sc_addr), 0x00, sizeof(l4c_number_struct));
				memcpy(&(g_frm_sms_background_send_info.sc_addr), &(msgRsp->sc_addr), sizeof(l4c_number_struct));
			}
		}
	#endif

        memset((PS8) tempbuf, 0, (tempLen));
        /* tempbuf = CovertStringForPlatform (msgRsp->profile_name.name, msgRsp->profile_name.name_length, msgRsp->profile_name.name_dcs, &outLen); */
        if (msgRsp->profile_name.name_length > 0)
        {
            /* add null terminator */
            if (msgRsp->profile_name.name_dcs == SMSAL_DEFAULT_DCS)
            {
                if (msgRsp->profile_name.name_length < sizeof(msgRsp->profile_name.name))
                {
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length] = 0;
                }
            }
            else
            {
                if ((msgRsp->profile_name.name_length + 1) < sizeof(msgRsp->profile_name.name))
                {
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length] = 0;
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length + 1] = 0;
                }
            }
            
            InputboxConvertGSMToDeviceEncoding(
                msgRsp->profile_name.name,
                tempbuf,
                msgRsp->profile_name.name_length,
                tempLen,
                msgRsp->profile_name.name_dcs,
                0,
                1);
        }
        memcpy((PS8) profileList->profileName[profileList->currReqProfileNo], tempbuf, tempLen);
        if (tempbuf)
        {
            OslMfree(tempbuf);
            tempbuf = NULL;
        }
        profileList->currReqProfileNo++;
        result = MMI_FRM_SMS_OK;
    }
    if ((profileList->currReqProfileNo >= profileList->currMaxPsProfiles) || (result == MMI_FRM_SMS_ERROR))
    {
        if (profileList->currMaxPsProfiles > 0)
        {
            S16 errorCode = 0;

            ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &(profileList->currReqProfileNo), DS_BYTE, &errorCode);
            if (profileList->currReqProfileNo >= profileList->currMaxPsProfiles)
            {
                profileList->currReqProfileNo = 0;
                WriteValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &(profileList->currReqProfileNo), DS_BYTE, &errorCode);
            }
        }

        mmi_frm_sms_callback_action((void*)profileList, result);
        OslMfree(profileList);
    }
    else
    {
        mmi_frm_sms_get_profile_name_req(&(profileList->currReqProfileNo));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_name_req
 * DESCRIPTION
 *  Get profile name request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_name_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT *msgReq;
    U8 index = *(U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->profile_no = index;
    SetProtocolEventHandler(mmi_frm_sms_get_profile_name_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_num_rsp
 * DESCRIPTION
 *  Get profile number response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_num_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PROFILE_NUM_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profileList = OslMalloc(sizeof(msg_profile_list_struct));
    profileList->currMaxPsProfiles = 0;
    profileList->currReqProfileNo = 0;
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        profileList->currMaxPsProfiles = msgRsp->profile_no;
        profileList->profileNameLength = msgRsp->name_len;
        result = MMI_FRM_SMS_OK;
    }
    if (profileList->currMaxPsProfiles == 0)
    {
        mmi_frm_sms_callback_action((void*)profileList, result);
        OslMfree(profileList);
    }
    else
    {
        mmi_frm_sms_get_profile_name_req(&(profileList->currReqProfileNo));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_num_req
 * DESCRIPTION
 *  Get profile number request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_num_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_profile_num_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_detail_rsp
 * DESCRIPTION
 *  Get profile detail response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_detail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profileDetail = OslMalloc(sizeof(msg_profile_edit_struct));
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {

        U16 tempLen = ((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
        U8 *tempbuf = OslMalloc(tempLen);
        U8 type = (msgRsp->sc_addr.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;

        memset((PS8) tempbuf, 0, (tempLen));

        //tempbuff        =       CovertStringForPlatform (msgRsp->profile_name.name, msgRsp->profile_name.name_length, 
        //                                msgRsp->profile_name.name_dcs, &outLen);
        if (msgRsp->profile_name.name_length > 0)
        {
            /* add null terminator */
            if (msgRsp->profile_name.name_dcs == SMSAL_DEFAULT_DCS)
            {
                if (msgRsp->profile_name.name_length < sizeof(msgRsp->profile_name.name))
                {
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length] = 0;
                }
            }
            else
            {
                if ((msgRsp->profile_name.name_length + 1) < sizeof(msgRsp->profile_name.name))
                {
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length] = 0;
                    msgRsp->profile_name.name[msgRsp->profile_name.name_length + 1] = 0;
                }
            }
            
            InputboxConvertGSMToDeviceEncoding(
                msgRsp->profile_name.name,
                tempbuf,
                msgRsp->profile_name.name_length,
                tempLen,
                msgRsp->profile_name.name_dcs,
                0,
                1);
        }
        memset((PS8) profileDetail->profileName, 0, (MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
        memcpy((PS8) profileDetail->profileName, (PS8) tempbuf, tempLen);
        profileDetail->profileNameDcs = msgRsp->profile_name.name_dcs;
        if (tempbuf)
        {
            OslMfree(tempbuf);
            tempbuf = NULL;
        }
        profileDetail->vpIndex = (U32) msgRsp->vp;
        profileDetail->msgTypeIndex = (U32) msgRsp->pid;

        if (type)
        {
            mmi_asc_to_ucs2((PS8) profileDetail->scAddress, (PS8) "+");
        }
        mmi_asc_n_to_ucs2(
            (PS8) profileDetail->scAddress + (type * ENCODING_LENGTH),
            (PS8) msgRsp->sc_addr.number,
            msgRsp->sc_addr.length);
        memset(
            (void*)&profileDetail->scAddress[(msgRsp->sc_addr.length + type) * ENCODING_LENGTH],
            0,
            ENCODING_LENGTH);
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)profileDetail, result);
    OslMfree(profileDetail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_detail_req
 * DESCRIPTION
 *  Get profile detail request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_detail_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT *msgReq;
    U8 index = *(U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->profile_no = index;
    SetProtocolEventHandler(mmi_frm_sms_get_profile_detail_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_profile_detail_rsp
 * DESCRIPTION
 *  Set profile detail response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_profile_detail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)profileDetail, result);
    OslMfree(profileDetail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_profile_detail_req
 * DESCRIPTION
 *  Set profile detail response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_profile_detail_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PROFILE_PARAMS_REQ_STRUCT *msgReq;
    msg_profile_edit_struct *profile = (msg_profile_edit_struct*) inMsg;
    S8 scAddress[MAX_DIGITS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profileDetail = OslMalloc(sizeof(msg_profile_edit_struct));
    memcpy(profileDetail, profile, sizeof(msg_profile_edit_struct));
    msgReq = (MMI_FRM_SMS_SET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->para_ind = 0;
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        msgReq->vp = (U8) profile->vpIndex;
        msgReq->para_ind |= SMSAL_PARA_VP;
    }

    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        msgReq->pid = (U8) profile->msgTypeIndex;
        msgReq->para_ind |= SMSAL_PARA_PID;
    }

    if (profile->profileNameDcs == PHB_UCS2)
    {
        msgReq->profile_name.name_dcs = MMI_PHB_UCS2;
        msgReq->profile_name.name_length = ((U8) mmi_ucs2strlen((PS8) profile->profileName)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM(
            (PU8) profile->profileName,
            msgReq->profile_name.name,
            MAX_PROFILE_NAME_LEN,
            MMI_PHB_UCS2,
            0,
            1);
    }
    else
    {
        msgReq->profile_name.name_dcs = MMI_PHB_ASCII;
        msgReq->profile_name.name_length = InputboxConvertDeviceEncodingToGSM(
                                            (PU8) profile->profileName,
                                            msgReq->profile_name.name,
                                            MAX_PROFILE_NAME_LEN,
                                            MMI_PHB_ASCII,
                                            0,
                                            1) - 1;
    }
    memset(&msgReq->profile_name.name[msgReq->profile_name.name_length], 0, 1);
    msgReq->para_ind |= SMSAL_PARA_PROFILE_NAME;

    memset(&scAddress, 0, MAX_DIGITS_SMS * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) profile->scAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->profile_no = profile->profileIndex;
    if (scAddress[0] == '+')
    {
        msgReq->sc_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->sc_addr.length = (strlen(scAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress) - 1);
        memcpy(msgReq->sc_addr.number, scAddress + 1, msgReq->sc_addr.length);
    }
    else
    {
        msgReq->sc_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->sc_addr.length =
            (strlen(scAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress));
        memcpy(msgReq->sc_addr.number, scAddress, msgReq->sc_addr.length);
    }
    memset(&msgReq->sc_addr.number[msgReq->sc_addr.length], 0, 1);
    msgReq->para_ind |= SMSAL_PARA_SCA;

    SetProtocolEventHandler(mmi_frm_sms_set_profile_detail_rsp, PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_common_settings_rsp
 * DESCRIPTION
 *  Get common settings response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_common_settings_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_COMMON_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_COMMON_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 settings[2] = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        settings[0] = msgRsp->status_report;
        settings[1] = msgRsp->reply_path;
        result = MMI_FRM_SMS_OK;

    #ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting = msgRsp->status_report;
    #endif 
    }
    mmi_frm_sms_callback_action((void*)settings, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_common_settings_req
 * DESCRIPTION
 *  Get common settings request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_common_settings_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_common_settings_rsp, PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_common_settings_rsp
 * DESCRIPTION
 *  Set common settings response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_common_settings_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_COMMON_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_COMMON_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    #ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting = g_frm_sms_cntx.mmi_frm_sms_delivery_report_temp_setting;
    #endif 
    }
    mmi_frm_sms_callback_action(NULL, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_common_settings_req
 * DESCRIPTION
 *  Set common settings request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_common_settings_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_COMMON_PARAMS_REQ_STRUCT *msgReq;
    U8 *DrRp = (U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_SET_COMMON_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf))
    {
        if (DrRp[0] == 0)
        {
            DrRp[0] = 0;
            DrRp[1] = 0;
        }
        else    /* DrRp[0] == 1 */
        {
            DrRp[0] = 0;
            DrRp[1] = 1;
        }
    }

    msgReq->status_report = DrRp[0];
    msgReq->reply_path = DrRp[1];
    msgReq->para_ind = SMSAL_COM_PARA_STATUS_REP | SMSAL_COM_PARA_REPLY_PATH;

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    g_frm_sms_cntx.mmi_frm_sms_delivery_report_temp_setting = msgReq->status_report;
#endif 
    SetProtocolEventHandler(mmi_frm_sms_set_common_settings_rsp, PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);
}

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_memory_status_rsp
 * DESCRIPTION
 *  Get memory status response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_memory_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    msg_mem_status_struct memory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        memory.simTotal = msgRsp->total_sim_num;
        memory.meTotal = msgRsp->total_me_num;
        memory.simUsed = msgRsp->in_sim_no + msgRsp->out_sim_no;
        memory.meUsed = msgRsp->in_me_no + msgRsp->out_me_no;
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&memory, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_memory_status_req
 * DESCRIPTION
 *  Get memory status request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_memory_status_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_memory_status_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_storage_rsp
 * DESCRIPTION
 *  Get preferred storage response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_storage_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PREFERRED_STORAGE_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PREFERRED_STORAGE_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 storage = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP);
    if (msgRsp->result == TRUE)
    {
        if (msgRsp->info.mem2 == SMSAL_SM || msgRsp->info.mem2 == SMSAL_SM_PREFER)
        {
            storage = SMSAL_SM;
        }
        else
        {
            storage = SMSAL_ME;
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&storage, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_storage_req
 * DESCRIPTION
 *  Get preferred storage request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_storage_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_preferred_storage_rsp, PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_storage_rsp
 * DESCRIPTION
 *  Set preferred storage response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_storage_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PREFERRED_STORAGE_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_PREFERRED_STORAGE_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 preferStorage = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP);
    if ((msgRsp->result) == TRUE)
    {
        if (msgRsp->param.mem2 == SMSAL_SM || msgRsp->param.mem2 == SMSAL_SM_PREFER)
        {
            preferStorage = SMSAL_SM;
        }
        else
        {
            preferStorage = SMSAL_ME;
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&preferStorage, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_storage_req
 * DESCRIPTION
 *  Set preferred storage request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_storage_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_PREFERRED_STORAGE_REQ_STRUCT *msgReq;
    U8 storage = *(U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_SET_PREFERRED_STORAGE_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->mem2 = storage;
    msgReq->mem1 = SMSAL_STORAGE_UNSPECIFIED;
#ifdef __MMI_MESSAGES_PREFER_STORAGE_ONLY_FOR_MO_SMS__
    msgReq->mem3 = SMSAL_STORAGE_UNSPECIFIED;
#else 
    msgReq->mem3 = storage;
#endif 
    SetProtocolEventHandler(mmi_frm_sms_set_preferred_storage_rsp, PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);
}
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_bearer_rsp
 * DESCRIPTION
 *  Get preferred bearer response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_bearer_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_COMMON_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_COMMON_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 bearer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        if (msgRsp->bearer_service == SMS_PREFER_GPRS)
        {
            bearer = MMI_SMS_PREFER_GPRS;
        }
        else if (msgRsp->bearer_service == SMS_PREFER_GSM)
        {
            bearer = MMI_SMS_PREFER_GSM;
        }
        else if (msgRsp->bearer_service == SMS_GSM_ONLY)
        {
            bearer = MMI_SMS_GSM_ONLY;
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&bearer, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_bearer_req
 * DESCRIPTION
 *  Get preferred bearer request
 * PARAMETERS
 *  dummy       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_bearer_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_preferred_bearer_rsp, PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_bearer_rsp
 * DESCRIPTION
 *  Set preferred bearer response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_bearer_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_COMMON_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_COMMON_PARAMS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP);
    if ((msgRsp->result) == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action(NULL, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_bearer_req
 * DESCRIPTION
 *  Set preferred bearer request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_bearer_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_COMMON_PARAMS_REQ_STRUCT *msgReq;
    U8 bearer = *(U8*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_SET_COMMON_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    switch (bearer)
    {
        case MMI_SMS_PREFER_GPRS:
            bearer = SMS_PREFER_GPRS;
            break;
        case MMI_SMS_PREFER_GSM:
            bearer = SMS_PREFER_GSM;
            break;
        case MMI_SMS_GSM_ONLY:
            bearer = SMS_GSM_ONLY;
            break;
    }
    msgReq->bearer_service = bearer;
    msgReq->para_ind = SMSAL_COM_PARA_BEARER;
    SetProtocolEventHandler(mmi_frm_sms_set_preferred_bearer_rsp, PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);
}

#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_mailbox_info_rsp
 * DESCRIPTION
 *  Get mailbox info response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_mailbox_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MAILBOX_ADDRESS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MAILBOX_ADDRESS_RSP_STRUCT*) inMsg;
    mmi_frm_sms_mailbox_struct mailboxInfo;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        mailboxInfo.mailboxNumber = msgRsp->mailbox_num;
        mailboxInfo.mailboxNameLength = msgRsp->alpha_length;
        for (i = 0; i < mailboxInfo.mailboxNumber; i++)
        {
            U8 type = (msgRsp->mailbox_info[i].number_info.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
            U8 length = msgRsp->mailbox_info[i].number_info.length;
            U16 nameLen = (msgRsp->mailbox_info[i].name.name_length + 1) * ENCODING_LENGTH;

            mailboxInfo.mailboxNameDcs[i] = msgRsp->mailbox_info[i].name.name_dcs;
            mailboxInfo.pMailBoxName[i] = OslMalloc(nameLen);
            memset(mailboxInfo.pMailBoxName[i], 0, nameLen);
            if (msgRsp->mailbox_info[i].name.name_length > 0)
            {
                /* add null terminator */
                if (msgRsp->mailbox_info[i].name.name_dcs == SMSAL_DEFAULT_DCS)
                {
                    if (msgRsp->mailbox_info[i].name.name_length < sizeof(msgRsp->mailbox_info[i].name.name))
                    {
                        msgRsp->mailbox_info[i].name.name[msgRsp->mailbox_info[i].name.name_length] = 0;
                    }
                }
                else
                {
                    if ((msgRsp->mailbox_info[i].name.name_length + 1) < sizeof(msgRsp->mailbox_info[i].name.name))
                    {
                        msgRsp->mailbox_info[i].name.name[msgRsp->mailbox_info[i].name.name_length] = 0;
                        msgRsp->mailbox_info[i].name.name[msgRsp->mailbox_info[i].name.name_length + 1] = 0;
                    }
                }
                
                InputboxConvertGSMToDeviceEncoding(
                    msgRsp->mailbox_info[i].name.name,
                    mailboxInfo.pMailBoxName[i],
                    msgRsp->mailbox_info[i].name.name_length,
                    nameLen,
                    msgRsp->mailbox_info[i].name.name_dcs,
                    0,
                    1);
            }
            //mailboxInfo.pMailBoxName[i] = CovertStringForPlatform (msgRsp->mailbox_info[i].name.name, 
            //msgRsp->mailbox_info[i].name.name_length, msgRsp->mailbox_info[i].name.name_dcs, &outlen);
            mailboxInfo.pMailBoxNumber[i] = OslMalloc((type + length + 1) * ENCODING_LENGTH);
            if (type)
            {
                mmi_asc_to_ucs2((PS8) mailboxInfo.pMailBoxNumber[i], (PS8) "+");
            }
            mmi_asc_n_to_ucs2(
                (PS8) (mailboxInfo.pMailBoxNumber[i] + (type * ENCODING_LENGTH)),
                (PS8) msgRsp->mailbox_info[i].number_info.number,
                length);
            memset(mailboxInfo.pMailBoxNumber[i] + ((type + length) * ENCODING_LENGTH), 0, ENCODING_LENGTH);
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void*)&mailboxInfo, result);
    for (i = 0; i < mailboxInfo.mailboxNumber; i++)
    {
        if (mailboxInfo.pMailBoxName[i])
        {
            OslMfree(mailboxInfo.pMailBoxName[i]);
        }
        if (mailboxInfo.pMailBoxNumber[i])
        {
            OslMfree(mailboxInfo.pMailBoxNumber[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_mailbox_info_req
 * DESCRIPTION
 *  Get mailbox info request
 * PARAMETERS
 *  dummy           [?]         
 *  inMsg(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_mailbox_info_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_mailbox_info_rsp, PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_mailbox_info_rsp
 * DESCRIPTION
 *  Set mailbox info response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_mailbox_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MAILBOX_ADDRESS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_MAILBOX_ADDRESS_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP);
    if ((msgRsp->result) == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action(mailboxDetail, result);
    OslMfree(mailboxDetail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_mailbox_info_req
 * DESCRIPTION
 *  Set mailbox info request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_mailbox_info_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MAILBOX_ADDRESS_REQ_STRUCT *msgReq;
    msg_mailbox_edit_struct *mailbox = (msg_mailbox_edit_struct*) inMsg;
    S8 mailboxAddress[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailboxDetail = OslMalloc(sizeof(msg_mailbox_edit_struct));
    memcpy(mailboxDetail, mailbox, sizeof(msg_mailbox_edit_struct));
    msgReq = (MMI_FRM_SMS_SET_MAILBOX_ADDRESS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));

    if (mailbox->mailboxNameDcs == PHB_UCS2)
    {
        msgReq->name.name_dcs = MMI_PHB_UCS2;
        msgReq->name.name_length = ((U8) mmi_ucs2strlen((PS8) mailbox->mailboxName)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM(
            (PU8) mailbox->mailboxName,
            msgReq->name.name,
            MAX_PROFILE_NAME_LEN,
            MMI_PHB_UCS2,
            0,
            1);
    }
    else
    {
        msgReq->name.name_dcs = MMI_PHB_ASCII;
        msgReq->name.name_length = InputboxConvertDeviceEncodingToGSM(
                                    (PU8) mailbox->mailboxName,
                                    msgReq->name.name,
                                    MAX_PROFILE_NAME_LEN,
                                    MMI_PHB_ASCII,
                                    0,
                                    1) - 1;
    }
    memset(&msgReq->name.name[msgReq->name.name_length], 0, 1);

    memset(mailboxAddress, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) mailboxAddress, (PS8) mailbox->mailboxAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->mailbox_num = mailbox->mailboxIndex;
    if (mailboxAddress[0] == '+')
    {
        msgReq->num_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->num_addr.length =
            (strlen(mailboxAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(mailboxAddress) - 1);
        memcpy(msgReq->num_addr.number, mailboxAddress + 1, msgReq->num_addr.length);
    }
    else
    {
        msgReq->num_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->num_addr.length =
            (strlen(mailboxAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(mailboxAddress));
        memcpy(msgReq->num_addr.number, mailboxAddress, msgReq->num_addr.length);
    }
    memset(&msgReq->num_addr.number[msgReq->num_addr.length], 0, 1);

    SetProtocolEventHandler(mmi_frm_sms_set_mailbox_info_rsp, PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ,
        (oslParaType*) msgReq,
        NULL);
    OslMfree(inMsg);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_sync_msg_ind
 * DESCRIPTION
 *  Handle sync indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_sync_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SYNC_MSG_IND_STRUCT *msgInd = (MMI_FRM_SMS_SYNC_MSG_IND_STRUCT*) inMsg;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msgInd->action)
    {
        case L4C_AT_SMS_ADD:
            mmi_frm_sms_get_sms(NULL, MOD_MMI, msgInd->index);
            break;
        case L4C_AT_SMS_READ_CMGR:
        case L4C_AT_SMS_READ_CMGL:
        {
            U16 msgbox_index = 0;
            U16 msg_type = 0;

            mmi_frm_sms_get_sms_msgbox_index(msgInd->index, &msgbox_index);

            if (msgbox_index != MMI_FRM_SMS_INVALID_INDEX)
            {
                msg_type = (mmi_frm_sms_msg_box[msgbox_index].msgtype & 0x000f);

                /* From UNREAD to READ */
                if (msg_type == MMI_FRM_SMS_UNREAD && msgInd->status == SMSAL_REC_READ)
                {
                    mmi_frm_sms_set_sms_status(MMI_FRM_SMS_NOBOX, msgbox_index, MMI_FRM_SMS_INBOX);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMsg.c] mmi_frm_sms_sync_msg_ind UNREAD index %d is updated-------*\n",
                                         msgInd->index);
                }
                /* From READ to UNREAD */
                else if (msg_type == MMI_FRM_SMS_INBOX && msgInd->status == SMSAL_REC_UNREAD)
                {
                    mmi_frm_sms_set_sms_status(MMI_FRM_SMS_NOBOX, msgbox_index, MMI_FRM_SMS_UNREAD);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMsg.c] mmi_frm_sms_sync_msg_ind UNREAD index %d is updated-------*\n",
                                         msgInd->index);
                }

                /* Do nothing if from READ to READ and from UNREAD to UNREAD */
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*-------[SmsMsg.c] mmi_frm_sms_sync_msg_ind READ no MSG BOX index %d-------*\n",
                                     msgInd->index);
            }

            break;
        }
        case L4C_AT_SMS_DELETE:
            mmi_frm_sms_remove_sms_from_msgbox(msgInd->del_bitmap);
            break;
        case L4C_SMS_SIM_REFRESH:
            mmi_frm_sms_ready_ind(NULL);
            break;
    }
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND, NULL, (U16) msgInd->action);   

    /* Design for flow control */
    if (msgInd->action == L4C_AT_SMS_READ_CMGR ||
    	  msgInd->action == L4C_AT_SMS_ADD || msgInd->action == L4C_AT_SMS_DELETE)
    {
        mmi_sms_sync_msg_res_req_struct *msgReq;

        msgReq = (mmi_sms_sync_msg_res_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

        msgReq->result = (kal_bool)TRUE;
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ, (oslParaType*) msgReq, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_sim_refresh_ind
 * DESCRIPTION
 *  Handle sim refresh indication from SAT
 * PARAMETERS
 *  dummy       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_sim_refresh_ind(U16 dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_screen = GetExitScrnID();
    BOOL in_sms_screen = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsMsg.c] mmi_frm_sms_sim_refresh_ind SIM Refresh -------*\n");
    g_frm_sms_cntx.mmi_frm_sms_ready = FALSE;

#ifdef __MMI_UNIFIED_MESSAGE__

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION) || current_screen == SCR_ID_MSG_INBOX_LIST_OPTION)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION) || current_screen == SCR_ID_MSG_OUTBOX_LIST_OPTION)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION) || current_screen == SCR_ID_MSG_ARCHIVE_LIST_OPTION)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION) || current_screen == SCR_ID_MSG_SIMBOX_LIST_OPTION)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }    
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION) || current_screen == SCR_ID_MSG_DEFAULT_LIST_OPTION)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG) || current_screen == SCR_ID_MSG_INBOX_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG) || current_screen == SCR_ID_MSG_OUTBOX_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG) || current_screen == SCR_ID_MSG_ARCHIVE_OUTBOX_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG) || current_screen == SCR_ID_MSG_ARCHIVE_INBOX_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_SIMBOX_MSG) || current_screen == SCR_ID_MSG_SIMBOX_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }    
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_MSG) || current_screen == SCR_ID_MSG_DEFAULT_MSG)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_SETTINGS) || current_screen == SCR_ID_MSG_SETTINGS)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SETTINGS);
    }
    else if (IsScreenPresent(SCR_ID_MSG_VOICE_MAIL_LIST) || current_screen == SCR_ID_MSG_VOICE_MAIL_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_LIST);
    }
    else if (IsScreenPresent(SCR_ID_MSG_CB_MAIN_MENU) || current_screen == SCR_ID_MSG_CB_MAIN_MENU)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MAIN_MENU);
    }
    else if (IsScreenPresent(SCR_ID_MSG_TEMPLATE_LIST) || current_screen == SCR_ID_MSG_TEMPLATE_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_LIST);
    }
    else if (IsScreenPresent(SCR_ID_MSG_WRITE) || current_screen == SCR_ID_MSG_WRITE)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
    }
    else
    {
        in_sms_screen = FALSE;
    }

#else /* __MMI_UNIFIED_MESSAGE__ */ 

    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST) || current_screen == SCR_ID_MSG_INBOX_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST) || current_screen == SCR_ID_MSG_OUTBOX_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST);
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST) || current_screen == SCR_ID_MSG_DRAFTBOX_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DRAFTBOX_LIST);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    else if (IsScreenPresent(SCR_ID_MSG_SETTINGS) || current_screen == SCR_ID_MSG_SETTINGS)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SETTINGS);
    }
    else if (IsScreenPresent(SCR_ID_MSG_VOICE_MAIL_LIST) || current_screen == SCR_ID_MSG_VOICE_MAIL_LIST)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_LIST);
    }
    else if (IsScreenPresent(SCR_ID_MSG_CB_MAIN_MENU) || current_screen == SCR_ID_MSG_CB_MAIN_MENU)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MAIN_MENU);
    }
    else if (IsScreenPresent(SCR_ID_MSG_WRITE))
    {
        /* Only delete SMS screens if sending or saving SMS messages */
        if (mmi_frm_sms_check_action_pending())
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
        }
        else
        {
            in_sms_screen = FALSE;
        }
    }
    else
    {
        in_sms_screen = FALSE;
    }

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    if (in_sms_screen)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_SIM_REFRESH),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }
    mmi_frm_sms_delete_action_pending();
    if (in_sms_screen)
    {
        DeleteMessagesHistoryNodes();
    }
    mmi_frm_sms_delete_screen_history();

#ifdef __MMI_UNIFIED_MESSAGE__

    mmi_um_handle_sim_refresh(UM_MSG_TYPE_SMS, in_sms_screen);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}

#ifdef __MMI_MESSAGES_COPY__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_callback
 * DESCRIPTION
 *  generic callback action for SMS copy
 * PARAMETERS
 *  result      [IN]        cause
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_callback(U16 result, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copyResult = OslMalloc(sizeof(mmi_frm_sms_copy_result_struct));
    copyResult->msg_number = g_frm_sms_copy_info.copy_msg_number;
    copyResult->cause = cause;
    mmi_frm_sms_callback_action(copyResult, result);
    OslMfree(copyResult);
    copyResult = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_rollback_rsp
 * DESCRIPTION
 *  Delete SMS response for rollback
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_rollback_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DEL_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_DEL_MSG_RSP_STRUCT*) inMsg;
    U8 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        mmi_frm_sms_remove_sms_from_msgbox(msgRsp->del_bitmap);
    }

    mmi_frm_sms_copy_sms_callback((U16) result, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_move_rsp
 * DESCRIPTION
 *  Delete SMS response for move action
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_move_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DEL_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_DEL_MSG_RSP_STRUCT*) inMsg;
    U8 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        mmi_frm_sms_remove_sms_from_msgbox(msgRsp->del_bitmap);

        g_frm_sms_copy_info.copy_msg_number++;
        g_frm_sms_copy_info.present_L4_index = MMI_FRM_SMS_INVALID_INDEX;
        g_frm_sms_copy_info.dst_msg_index = MMI_FRM_SMS_INVALID_INDEX;
        g_frm_sms_copy_info.handled_msg_number++;
        /* all msgs are handled */
        if (g_frm_sms_copy_info.handled_msg_number >= g_frm_sms_copy_info.total_msg_number)
        {
            if (g_frm_sms_copy_info.is_memory_full)
            {
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
            }
            else
            {
                mmi_frm_sms_copy_sms_callback((U16) result, result);
            }
            return;
        }
        /* handle the next msg */
        else
        {
            mmi_frm_sms_pre_copy_sms_req(NULL);
            return;
        }
    }
    else
    {
        mmi_frm_sms_copy_sms_callback((U16) result, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_seg_rsp
 * DESCRIPTION
 *  copy one sms segment rsp
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_seg_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_COPY_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_COPY_MSG_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_COPY_MSG_RSP);

    if (msgRsp->result == TRUE)
    {
        U16 msgindex = 0;
        mmi_frm_sms_msgbox_struct *entry;
        
        entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
        mmi_frm_sms_get_sms_msgbox_index(g_frm_sms_copy_info.present_L4_index,&msgindex);
        memcpy((S8*) entry, (S8*) & mmi_frm_sms_msg_box[msgindex], sizeof(mmi_frm_sms_msgbox_struct));
        /* if(entry->storageType != MMI_FRM_SMS_PREFER_STORAGE) */
        entry->storageType = msgRsp->dst_storage;
        entry->startindex = msgRsp->dst_index;
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		if (entry->msgtype & MMI_FRM_SMS_UNSENT)
		{
    		entry->send_status = MMI_FRM_SMS_FAILTOSEND;
		}
	#endif

        /* There is not timestamp info for outbox SMS stored in SIM  */
        if (g_frm_sms_copy_info.msg_list_type != MMI_FRM_SMS_INBOX && g_frm_sms_copy_info.msg_list_type != MMI_FRM_SMS_UNREAD)
        {
            if (msgRsp->dst_storage == SMSAL_SM)
            {            
                memset(entry->timestamp, 0, sizeof(entry->timestamp));
            }
        }

    #ifdef __MMI_UNIFIED_MESSAGE__
        /* The MMI SMS content is added in the first segment */
        if (mmi_frm_sms_index_list[msgRsp->src_index].segment != 1)
        {
            memset(entry->content,0,sizeof(entry->content));
        }
    
    #endif /* __MMI_UNIFIED_MESSAGE__ */

        g_frm_sms_copy_info.dst_msg_index = mmi_frm_sms_add_sms_to_msgbox(entry, msgRsp->dst_index, mmi_frm_sms_index_list[msgRsp->src_index].segment);
        OslMfree(entry);

        /* remaing unsent segment of this msg */
        if (mmi_frm_sms_index_list[g_frm_sms_copy_info.present_L4_index].nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_copy_sms_seg_req();
            return;
        }
        /* total segments of this msg have sent */
        else
        {
            U16 msgIndex;
            U16 type;
            U16 list_index;

            mmi_frm_sms_get_sms_msgbox_index(g_frm_sms_copy_info.present_L4_index,&msgIndex);            
            if (msgIndex != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_get_sms_list_index(&type, &list_index, msgIndex);                
                /* Check if the new msg is added in front of the original one in the list */ 
                if (list_index > g_frm_sms_copy_info.present_msg_index)
                {
                #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                    if (g_frm_sms_copy_info.action == SMSAL_MOVE_MSG)
                    {
                        g_frm_sms_copy_info.handled_msg_number += (list_index - g_frm_sms_copy_info.present_msg_index - 1);
					#ifdef __MMI_DUAL_SIM_MASTER__
						MTPNP_PFAL_SMS_adjust_Copy_Index(list_index - g_frm_sms_copy_info.present_msg_index - 1);
					#endif
                    }
                    else
                #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                    {
                        g_frm_sms_copy_info.handled_msg_number += (list_index - g_frm_sms_copy_info.present_msg_index);
					#ifdef __MMI_DUAL_SIM_MASTER__
						MTPNP_PFAL_SMS_adjust_Copy_Index(list_index - g_frm_sms_copy_info.present_msg_index);
					#endif
                    }
                }
                g_frm_sms_copy_info.present_msg_index = list_index;
            }            
            /* delete original msg if action == move */
            if (g_frm_sms_copy_info.action == SMSAL_MOVE_MSG)
            {
            #ifndef __MMI_DUAL_SIM_MASTER__
                U8 *data = OslMalloc(sizeof(U8) * 480);
                U16 deleteMsgIndex = 0;

                deleteMsgIndex = g_frm_sms_copy_info.present_msg_index;
                memset((S8*) data, 0, sizeof(U8) * 480);

            #if (0)
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
            #endif /* (0) */ 

                /* swap the new added one with the original next one */
                //mmi_frm_sms_swap_list_index(g_frm_sms_copy_info.msg_list_type, (U16)g_frm_sms_copy_info.present_msg_index , list_index);
                //deleteMsgIndex = list_index;

                if (mmi_frm_sms_get_sms_bitmap(g_frm_sms_copy_info.msg_list_type, deleteMsgIndex, data) == FALSE)
                {
                    OslMfree(data);
                    mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
                    return;
                }
                else
                {
                    MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *msgReq;

                    msgReq = (MMI_FRM_SMS_DEL_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
                    msgReq->del_flag = SMSAL_DEL_BITMAP;
                    memcpy((S8*) msgReq->del_bitmap, (S8*) data, 480);
                    OslMfree(data);
                    SetProtocolEventHandler(mmi_frm_sms_copy_sms_move_rsp, PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
                    mmi_frm_sms_send_message(
                        MOD_MMI,
                        MOD_L4C,
                        0,
                        PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }
            #else /* __MMI_DUAL_SIM_MASTER__ */
                MTPNP_PFAL_Copy_SMS_Move_Req();
                return;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }

            /* if action == copy */
            g_frm_sms_copy_info.copy_msg_number++;
            g_frm_sms_copy_info.present_L4_index = MMI_FRM_SMS_INVALID_INDEX;
            g_frm_sms_copy_info.dst_msg_index = MMI_FRM_SMS_INVALID_INDEX;
            g_frm_sms_copy_info.handled_msg_number++;

            /* The new msg is already in list. Get new list size if copy all */
            if (g_frm_sms_copy_info.total_msg_number > 1)
            {
            #if !defined(__MMI_DUAL_SIM_MASTER__)
                g_frm_sms_copy_info.total_msg_number = mmi_frm_sms_get_sms_list_size(g_frm_sms_copy_info.msg_list_type);
            #else /* __MMI_DUAL_SIM_MASTER__ */
                g_frm_sms_copy_info.total_msg_number = MTPNP_PFAL_SMS_Get_SMS_List_Size(type);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }

            /* all msgs are handled */
            if (g_frm_sms_copy_info.handled_msg_number >= g_frm_sms_copy_info.total_msg_number)
            {
                if (g_frm_sms_copy_info.is_memory_full)
                {
                    mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
                }
                else
                {
                    mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_OK, MMI_FRM_SMS_OK);
                }
                return;
            }
            /* handle the next msg */
            else
            {
            #if !defined(__MMI_DUAL_SIM_MASTER__)
                g_frm_sms_copy_info.present_msg_index++;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                MTPNP_PFAL_SMS_Increment_Copy_Index();
            #endif /* __MMI_DUAL_SIM_MASTER__ */
                mmi_frm_sms_pre_copy_sms_req(NULL);
                return;
            }
        }
    }
    /* if(msgRsp->result == TRUE) */
    else
    {
        /* kal_uint8 result;
           kal_uint16  cause;
           kal_uint8   action;
           kal_uint8   dst_storage;
           kal_uint16  src_index;
           kal_uint16  dst_index; */

        /* first segment , no need to rollback */
        if (g_frm_sms_copy_info.dst_msg_index == MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
            return;
        }
        /* rollback the last incomplete copied msg */
        else
        {
            U8 *data = OslMalloc(sizeof(U8) * 480);

            memset((S8*) data, 0, sizeof(U8) * 480);
            if (mmi_frm_sms_get_sms_bitmap
                (MMI_FRM_SMS_AWAITS, mmi_frm_sms_msg_box[g_frm_sms_copy_info.dst_msg_index].startindex, data) == FALSE)
            {
                OslMfree(data);
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
                return;
            }
            else
            {
                MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *msgReq;

                msgReq = (MMI_FRM_SMS_DEL_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
                msgReq->del_flag = SMSAL_DEL_BITMAP;
                memcpy((S8*) msgReq->del_bitmap, (S8*) data, 480);
                SetProtocolEventHandler(mmi_frm_sms_copy_sms_rollback_rsp, PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
                mmi_frm_sms_send_message(
                    MOD_MMI,
                    MOD_L4C,
                    0,
                    PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ,
                    (oslParaType*) msgReq,
                    NULL);
                OslMfree(data);
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_seg_req
 * DESCRIPTION
 *  copy one sms segment req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_seg_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_COPY_MSG_REQ_STRUCT *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_COPY_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));

    /* first segment of message */
    if (g_frm_sms_copy_info.present_L4_index == MMI_FRM_SMS_INVALID_INDEX)
    {
        U16 msgindex = 0;

        switch (g_frm_sms_copy_info.msg_list_type)
        {
            case MMI_FRM_SMS_NOBOX:
                msgindex = g_frm_sms_copy_info.present_msg_index;
                break;

            case MMI_FRM_SMS_INBOX:
            case MMI_FRM_SMS_UNREAD:
                msgindex = mmi_frm_sms_inbox_list[g_frm_sms_copy_info.present_msg_index];
                break;

            case MMI_FRM_SMS_OUTBOX:
        #ifndef __MMI_MESSAGES_DRAFT_BOX__
            case MMI_FRM_SMS_DRAFTS:
        #endif 
                msgindex = mmi_frm_sms_outbox_list[g_frm_sms_copy_info.present_msg_index];
                break;

        #ifdef __MMI_MESSAGES_DRAFT_BOX__
            case MMI_FRM_SMS_DRAFTS:
                msgindex = mmi_frm_sms_drafts_list[g_frm_sms_copy_info.present_msg_index];
                break;
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

        #ifdef __MMI_UNIFIED_MESSAGE__
            case MMI_FRM_SMS_UNSENT:
                msgindex = mmi_frm_sms_unsent_list[g_frm_sms_copy_info.present_msg_index];
                break;
        #endif 
        
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            case MMI_FRM_SMS_SIM:                                
                if (mmi_frm_sms_sim_list != NULL)
                {
                    msgindex = mmi_frm_sms_sim_list[g_frm_sms_copy_info.present_msg_index];
                }
                break;                
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        }        
        g_frm_sms_copy_info.present_L4_index = mmi_frm_sms_msg_box[msgindex].startindex;
    }

    /* not the first segment */
    else
    {   /* check if the nextindex == invalid index in mmi_frm_sms_copy_sms_seg_rsp, not here */
        g_frm_sms_copy_info.present_L4_index = mmi_frm_sms_index_list[g_frm_sms_copy_info.present_L4_index].nextindex;
    }

    msgReq->action = SMSAL_COPY_MSG;
    msgReq->dst_storage = g_frm_sms_copy_info.dst_storage;
    msgReq->src_index = g_frm_sms_copy_info.present_L4_index;

#ifndef __MMI_DUAL_SIM_MASTER__
    SetProtocolEventHandler(mmi_frm_sms_copy_sms_seg_rsp, PRT_MSG_ID_MMI_SMS_COPY_MSG_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_COPY_MSG_REQ, (oslParaType*) msgReq, NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
    MTPNP_PFAL_Copy_SMS_Req(msgReq);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_pre_copy_sms_rsp
 * DESCRIPTION
 *  Get memory status response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_pre_copy_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT*) inMsg;
    U8 segmentNumber = mmi_frm_sms_get_sms_received_size(g_frm_sms_copy_info.msg_list_type, g_frm_sms_copy_info.present_msg_index);
    U16 availableMemorySize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);

    if (msgRsp->result == TRUE)
    {

        if (g_frm_sms_copy_info.total_msg_number > 1)
        {  
        	U16 list_size;
        #ifdef __MMI_DUAL_SIM_MASTER__
			if (MTPNP_AD_SMS_Get_Filter_Rule() != MTPNP_AD_FILTER_ALL)
			{
				list_size = MTPNP_PFAL_SMS_Get_SMS_List_Size(g_frm_sms_copy_info.msg_list_type);
			}
			else
		#endif
			{
            	list_size = mmi_frm_sms_get_sms_list_size(g_frm_sms_copy_info.msg_list_type);
			}
            
            if (g_frm_sms_copy_info.msg_list_type == MMI_FRM_SMS_INBOX || 
                g_frm_sms_copy_info.msg_list_type == MMI_FRM_SMS_UNREAD)
            {         
                /* If new msg arrives during copying all, current msg index would be increased by one */
                if (g_frm_sms_copy_info.action == SMSAL_COPY_MSG)                
                {
                    if (g_frm_sms_copy_info.total_msg_number < list_size)
                    {
                    #if !defined(__MMI_DUAL_SIM_MASTER__)
                        g_frm_sms_copy_info.present_msg_index++;
                    #else /* __MMI_DUAL_SIM_MASTER__ */
                        MTPNP_PFAL_SMS_Increment_Copy_Index();
                    #endif /* __MMI_DUAL_SIM_MASTER__ */

                        g_frm_sms_copy_info.handled_msg_number++;
                        segmentNumber = mmi_frm_sms_get_sms_received_size(g_frm_sms_copy_info.msg_list_type, g_frm_sms_copy_info.present_msg_index);
                    }
                }
                else
                {
                    g_frm_sms_copy_info.total_msg_number = list_size;
                }
            }
        }
            
        if (g_frm_sms_copy_info.dst_storage == SMSAL_SM)
        {
            availableMemorySize = msgRsp->total_sim_num - msgRsp->in_sim_no - msgRsp->out_sim_no;
        }
        else    /* SMSAL_ME */
        {
            availableMemorySize = msgRsp->total_me_num - msgRsp->in_me_no - msgRsp->out_me_no;
        }

        if (availableMemorySize == 0)   /* no more available Memory */
        {
            mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
            return;
        }
        else if (availableMemorySize < segmentNumber)   /* not enough for this msg, try the next msg */
        {
            g_frm_sms_copy_info.is_memory_full = TRUE;
            g_frm_sms_copy_info.handled_msg_number++;
            if (g_frm_sms_copy_info.handled_msg_number >= g_frm_sms_copy_info.total_msg_number)
            {
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
                return;
            }
            else
            {
            #if !defined(__MMI_DUAL_SIM_MASTER__)
                g_frm_sms_copy_info.present_msg_index++;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                MTPNP_PFAL_SMS_Increment_Copy_Index();
            #endif /* __MMI_DUAL_SIM_MASTER__ */

                mmi_frm_sms_pre_copy_sms_req(NULL);
            }
        }
        else
        {
            mmi_frm_sms_copy_sms_seg_req();
        }
    }
    else
    {
        mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_pre_copy_sms_req
 * DESCRIPTION
 *  pre-copy SMS : check before copy SMS
 * PARAMETERS
 *  dummy       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_pre_copy_sms_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if user aborts SMS copy action */
    if (g_frm_sms_copy_info.is_aborted)
    {
        g_frm_sms_copy_info.is_aborted = FALSE;
        mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ABORT, MMI_FRM_SMS_ABORT);
        return;
    }

    /* check msg storage */
    while (mmi_frm_sms_get_sms_storage(g_frm_sms_copy_info.msg_list_type, g_frm_sms_copy_info.present_msg_index) ==
           g_frm_sms_copy_info.dst_storage)
    {
        g_frm_sms_copy_info.handled_msg_number++;

        /*  copy one by one should not enter this loop, or will return here  */
        if (g_frm_sms_copy_info.handled_msg_number >= g_frm_sms_copy_info.total_msg_number)
        {
            if (g_frm_sms_copy_info.is_memory_full)
            {
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
            }
            else
            {
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_OK, MMI_FRM_SMS_OK);
            }
            return;
        }

        /* only for copy all */
    #if !defined(__MMI_DUAL_SIM_MASTER__)
        g_frm_sms_copy_info.present_msg_index++;
    #else /* __MMI_DUAL_SIM_MASTER__ */
        MTPNP_PFAL_SMS_Increment_Copy_Index();
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    SetProtocolEventHandler(mmi_frm_sms_pre_copy_sms_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ, NULL, NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
    MTPNP_PFAL_Pre_Copy_SMS_Req();
#endif /* __MMI_DUAL_SIM_MASTER__ */
}
#endif /* __MMI_MESSAGES_COPY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_write_msg_req
 * DESCRIPTION
 *  entry write msg screen with content
 * PARAMETERS
 *  entry_write_data        [?]     
 *  void*  data(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_write_msg_req(void *entry_write_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *data = (mmi_frm_sms_api_entry_write_struct*) entry_write_data;
    EMSData *pEMS;
    S8 *textbuf = NULL;
    S8 *textbufucs2 = NULL;
    U32 textlen = 0;
    U16 result = 0;
    history temphistory;

#ifdef __MMI_UNIFIED_COMPOSER__
    U8* addr = NULL;
    U16 type = MMI_UC_STATE_WRITE_NEW_MSG;
#endif /* __MMI_UNIFIED_COMPOSER__ */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_removed())
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_removed() && (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT))
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsMsg.c] mmi_frm_sms_entry_write_msg_req INSERT SIM -------*\n");
        
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_AVAILABLE),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    if (data->filename != NULL)
    {
        S32 errorCode = 0;
        FS_HANDLE emsObjectFilePtr;
        U32 read_size = 0;

        emsObjectFilePtr = FS_Open((U16*) data->filename, FS_READ_ONLY);
        /* the file exists without error */
        if (emsObjectFilePtr > 0)
        {
            FS_GetFileSize(emsObjectFilePtr, &textlen);

            /* the file size is 0 */
            if (textlen == 0)
            {
                FS_Close(emsObjectFilePtr);
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_DATA_EMPTY),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                return;
            }

            if (data->dcs == SMSAL_8BIT_DCS)
            {
                /* the file is too large. */
                if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG / ENCODING_LENGTH) ||
                    textlen > ((MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE / ENCODING_LENGTH) - 1))
                {
                    FS_Close(emsObjectFilePtr);
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_FAILURE_DATA_EXCEED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                    return;
                }
                /* the file size is allowed */
                textbuf = OslMalloc(textlen + 1);
                errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_FAILURE_DATA_INVALID),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                    OslMfree(textbuf);
                    return;
                }
                /* the file content is allowed */
                textbufucs2 = OslMalloc((textlen + 1) * ENCODING_LENGTH);
                mmi_asc_n_to_ucs2(textbufucs2, textbuf, textlen);
                memset(textbufucs2 + textlen * ENCODING_LENGTH, 0, ENCODING_LENGTH);
                OslMfree(textbuf);
            }
            /* UCS2 and  DEFAULT DCS */
            else
            {
                /* the file is too large. */
                if (textlen > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG) ||
                    textlen > (MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE - ENCODING_LENGTH))
                {
                    FS_Close(emsObjectFilePtr);
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_FAILURE_DATA_EXCEED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                    return;
                }
                /* the file size is allowed */
                textbuf = OslMalloc(textlen + ENCODING_LENGTH);
                errorCode = FS_Read( emsObjectFilePtr, textbuf, textlen, &read_size);
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_FAILURE_DATA_INVALID),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                    OslMfree(textbuf);
                    return;
                }
                /* the file content is allowed */
                textbufucs2 = OslMalloc((textlen + ENCODING_LENGTH));
                memset(textbufucs2, 0, (textlen + ENCODING_LENGTH));
                memcpy(textbufucs2, textbuf, textlen);
                OslMfree(textbuf);
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_DATA_INVALID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
    }
    else if (data->string != NULL && data->stringlength > 0)
    {
       if (data->stringlength > (MMI_FRM_SMS_MSG_LEN * MMI_SMS_MAX_MSG_SEG / ENCODING_LENGTH) ||
            data->stringlength > ((MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE / ENCODING_LENGTH) - 1))
        {            
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_DATA_EXCEED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }			
        textbufucs2 = OslMalloc((data->stringlength) * ENCODING_LENGTH);
        memset((S8*) textbufucs2, 0, ((data->stringlength) * ENCODING_LENGTH));
        memcpy(textbufucs2, data->string, ((data->stringlength) * ENCODING_LENGTH));
    }
    else
    {
        ReleaseEMSEditBuffer();
    }

    if (textbufucs2)
    {
        EMSTATUS EMSSetPortResult = EMS_OK;
        EMSTATUS EMSSetClassResult = EMS_OK;

        ReleaseEMSEditBuffer();
        pEMS = GetEMSDataForEdit(0, 1);
        if ((data->flag & MMI_FRM_SMS_ENTRY_WRITE_PORT) == MMI_FRM_SMS_ENTRY_WRITE_PORT)
        {
            EMSSetPortResult = EMSSetPortNum(pEMS, data->srcport, data->desport);
        }
        if ((data->flag & MMI_FRM_SMS_ENTRY_WRITE_CLASS) == MMI_FRM_SMS_ENTRY_WRITE_CLASS)
        {
            EMSSetClassResult = EMSSetMsgClass(pEMS, data->dcs_class);
        }

        if ((EMSSetPortResult != EMS_OK) || (EMSSetClassResult != EMS_OK))
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_DATA_INVALID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            OslMfree(textbufucs2);
            return;
        }

        if (data->filename != NULL)
        {
            result = AppendEMSString(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) textbufucs2,
                        data->dcs,
                        temphistory.guiBuffer);
        }
        else if (data->string != NULL)
        {
            EMSSetDCS(pEMS, data->dcs);
            result = AddString(pEMS, (U8*) textbufucs2, data->stringlength, NULL);
        }
        OslMfree(textbufucs2);

        if ((data->filename != NULL && result == 0) || (data->string != NULL && result != EMS_OK))
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_DATA_EXCEED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
    }

#ifdef __MMI_UNIFIED_COMPOSER__

    if ((data->flag & MMI_FRM_SMS_ENTRY_WRITE_REPLY) == MMI_FRM_SMS_ENTRY_WRITE_REPLY)
    {
        if (data->ascii_addr && strlen((S8*)data->ascii_addr))
        {
            if (strlen((S8*)data->ascii_addr) > (MAX_DIGITS_SMS - 1))
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    PHB_NOTIFY_TIMEOUT,
                    (U8) ERROR_TONE);
                
                ReleaseEMSEditBuffer();
                return;
            }
            
            addr = data->ascii_addr;
        }
    }

    mmi_msg_entry_uc(addr, type, 0, MMI_UC_MSG_TYPE_SMS_ONLY);

#else /* __MMI_UNIFIED_COMPOSER__ */

    if ((data->flag & MMI_FRM_SMS_ENTRY_WRITE_REPLY) == MMI_FRM_SMS_ENTRY_WRITE_REPLY)
    {
        if (data->ascii_addr && strlen((S8*)data->ascii_addr))
        {
            if (strlen((S8*)data->ascii_addr) > (MAX_DIGITS_SMS - 1))
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    PHB_NOTIFY_TIMEOUT,
                    (U8) ERROR_TONE);
                    
                ReleaseEMSEditBuffer();
                return;
            }
            
            strncpy((S8*)g_msg_cntx.smsPhoneNumber, (S8*)data->ascii_addr, MAX_DIGITS_SMS - 1);
            g_msg_cntx.sendMessageCase = SEND_CASE_REPLY_FROM_OTHER_APP;
        }
        else
		{
			g_msg_cntx.sendMessageCase = SEND_CASE_SEND_FROM_OTHER_APP;
		}
    }
	else
	{
		g_msg_cntx.sendMessageCase = SEND_CASE_SEND_FROM_OTHER_APP;
	}

    mmi_msg_entry_write_msg();

#endif /* __MMI_UNIFIED_COMPOSER__ */
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_protocol_event_handler
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_new_sms_ind, PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND);
    SetProtocolEventHandler(mmi_frm_sms_new_data_ind, PRT_MSG_ID_MMI_SMS_APP_DATA_IND);
    SetProtocolEventHandler(mmi_frm_sms_ready_ind, PRT_MSG_ID_MMI_SMS_READY_IND);
    SetProtocolEventHandler(mmi_frm_sms_startup_begin_ind, PRT_MSG_ID_MMI_SMS_STARTUP_BEGIN_IND);
    SetProtocolEventHandler(mmi_frm_sms_status_report_ind, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND);
    SetProtocolEventHandler(mmi_frm_sms_mem_avai_ind, PRT_MSG_ID_MMI_SMS_MEM_AVAILABLE_IND);
    SetProtocolEventHandler(mmi_frm_sms_mem_exceed_ind, PRT_MSG_ID_MMI_SMS_MEM_EXCEED_IND);
    SetProtocolEventHandler(mmi_frm_sms_mem_full_ind, PRT_MSG_ID_MMI_SMS_MEM_FULL_IND);
    SetProtocolEventHandler(mmi_frm_sms_msg_waiting_ind, PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND);
    SetProtocolEventHandler(mmi_frm_sms_sync_msg_ind, PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND);
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    SetSlaveProtocolEventHandler(mmi_frm_card2_sms_sync_msg_ind, PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sim_memory_req
 * DESCRIPTION
 *  Get memory status request
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sim_memory_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_sms_get_sim_memory_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_memory_status_rsp
 * DESCRIPTION
 *  Get memory status response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sim_memory_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT*) inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
    if (msgRsp->result == TRUE)
    {       
        if (mmi_frm_sms_sim_list != NULL)
        {
            OslMfree(mmi_frm_sms_sim_list);
        }
        if (msgRsp->total_sim_num > 0)
        {
            mmi_frm_sms_sim_list = OslMalloc(sizeof(unsigned short)*msgRsp->total_sim_num);  
        }      
        mmi_frm_sms_create_sms_list();
 	#ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_msg_icon(FALSE, FALSE);
	#else /* __MMI_DUAL_SIM_MASTER__ */
		MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
		MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	#endif /* __MMI_DUAL_SIM_MASTER__ */
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		mmi_msg_update_unsent_icon();
	#endif
        
        return;
    }
    mmi_frm_sms_get_sim_memory_req();
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_to_unsent_seg
 * DESCRIPTION
 *  Save SMS segment to unsent 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_to_unsent_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_REQ_STRUCT *saveSms;
    S8 *addr = (S8*) sendSMS->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    saveSms = (MMI_FRM_SMS_SET_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*saveSms));
    /* memset((S8*)saveSms, 0, sizeof(MMI_FRM_SMS_SET_MSG_REQ_STRUCT)); */
    saveSms->status = sendSMS->status;
	saveSms->index = MMI_FRM_SMS_INVALID_INDEX;
	if ((sendSMS->sendrequire & MMI_FRM_SMS_REPLY) == MMI_FRM_SMS_REPLY)
    {
        U8 *replyaddr = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_INBOX, sendSMS->replyindex);
        
        memset((S8*) sendSMS->number, 0, MAX_DIGITS_SMS);
        memcpy((S8*) sendSMS->number, (S8*) replyaddr, strlen((S8*) replyaddr));
	}
    
	if (addr[0] == '+')
    {
        saveSms->dest.type = CSMCC_INTERNATIONAL_ADDR;
        addr++;
    }
    else
    {
        saveSms->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
    }

    memset((S8*) saveSms->dest.number, 0, MAX_CC_ADDR_LEN);
    memcpy((S8*) saveSms->dest.number, (S8*) addr, strlen((S8*) addr));
    saveSms->dest.length = strlen((S8*) addr);

    saveSms->profile = sendSMS->profile;    /* active profile number.. */
    saveSms->para = 0;
    saveSms->udhi = PendingSaveSendData.udhi;
    saveSms->dcs = PendingSaveSendData.dcs[0];
    saveSms->length = PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment];
    GetDateTime(&sms_saved_time);
    mmi_frm_sms_convert_mytime(saveSms->scts, &sms_saved_time);
    memset(saveSms->msg, 0, SMSAL_MAX_MSG_LEN);
    memcpy(
        saveSms->msg,
        PendingSaveSendData.TPUD_p[PendingSaveSendData.nextSegment],
        PendingSaveSendData.TPUDLen[PendingSaveSendData.nextSegment]);
	saveSms->vp = g_frm_sms_background_send_info.vp;
	if (g_frm_sms_background_send_info.sc_addr.length != 0)
	{
		memcpy(&(saveSms->sc_addr), &(g_frm_sms_background_send_info.sc_addr), sizeof(l4c_number_struct));
	}
    SetProtocolEventHandler(mmi_frm_sms_save_sms_to_unsent_rsp, PRT_MSG_ID_MMI_SMS_SET_MSG_RSP);
    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_SET_MSG_REQ, (oslParaType*) saveSms, NULL);
    PendingSaveSendData.nextSegment++;
    PendingSaveSendData.presentSegments++;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_to_unsent_rsp
 * DESCRIPTION
 *  Save SMS to unsent response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_to_unsent_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SET_MSG_RSP_STRUCT*) inMsg;
    U16 msgbox_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
        U16 ref = (U16) GetRefFromNVRAM();

        memset((S8*) entry, 0, sizeof(mmi_frm_sms_msgbox_struct));

        ref = (ref > 0) ? (ref - 1) : MMI_FRM_SMS_INVALID_NUM;
        mmi_frm_sms_convert_mo_to_entry(
            sendSMS,
            entry,
            msgRsp->index,
            msgRsp->status,
            PendingSaveSendData.totalSegments,
            ref,
            msgRsp->storage_type,
            &sms_saved_time);
    
        /* Only save content for the first segment */
        if (PendingSaveSendData.nextSegment == 1)
        {
            U8 *content = OslMalloc(mmi_msg_get_max_content_size() * ENCODING_LENGTH);
            EMSData *pEMS = NULL;
            U32 content_size = 0;

            pEMS = GetEMSDataForEdit(0, 0);

            if (pEMS->dcs == SMSAL_UCS2_DCS)
            {
                content_size =
                    ((mmi_msg_get_max_content_size() - 1) <
                     (pEMS->textLength / 2)) ? (mmi_msg_get_max_content_size() - 1) : (pEMS->textLength / 2);

                memset(entry->content, 0, sizeof(entry->content));
                memset(content, 0, mmi_msg_get_max_content_size() * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) content, (S8*) pEMS->textBuffer, content_size);
            }
            else
            {
                U32 handled_content_size = mmi_msg_get_max_content_size() * 2 * ENCODING_LENGTH;
                U8 *handled_content = OslMalloc(handled_content_size);
                U32 handled_content_len = 0;
                U16 ori_content_size = 
                        ((mmi_msg_get_max_content_size() - 1) <
                         (pEMS->textLength / 2)) ? (mmi_msg_get_max_content_size() - 1) : (pEMS->textLength / 2);

                memset(handled_content, 0, handled_content_size);
                mmi_frm_sms_remove_escape_symbol_for_extension_char
                    ((U16*)handled_content, 
                     (U16*)pEMS->textBuffer, 
                     (U16) (ori_content_size));

                handled_content_len = mmi_ucs2strlen((S8*)handled_content);

                content_size =
                    ((mmi_msg_get_max_content_size() - 1) <
                     (handled_content_len)) ? (mmi_msg_get_max_content_size() - 1) : (handled_content_len);

                memset(entry->content, 0, sizeof(entry->content));
                memset(content, 0, mmi_msg_get_max_content_size() * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) content, (S8*) handled_content, content_size);

				OslMfree(handled_content);
            }

            if (mmi_ucs2strlen((S8*) content))
            {
                mmi_frm_sms_add_content_to_entry(entry, content);
            }

            OslMfree(content);
        }

        entry->send_status = MMI_FRM_SMS_WAITING;
        msgbox_index = mmi_frm_sms_add_sms_to_msgbox(entry, msgRsp->index, PendingSaveSendData.presentSegments);

        OslMfree(entry);
        if (PendingSaveSendData.nextSegment < PendingSaveSendData.totalSegments)
        {
            mmi_frm_sms_save_sms_to_unsent_seg();
        }
        else
        {  
			mmi_frm_sms_free_sendsms_data();
            /* no more to send or send fail: returns the result */
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_OK);
            
        }
    }
    else
    {
		mmi_frm_sms_free_sendsms_data();
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_MEMFULL);        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_send_sms_seg
 * DESCRIPTION
 *  Background send SMS segment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_send_sms_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_MSG_BY_STORAGE_REQ_STRUCT *msgReq;
	BOOL isSave = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_frm_sms_background_send_info.l4_index == MMI_FRM_SMS_INVALID_INDEX)
    {
    	g_frm_sms_cntx.is_aborting = MMI_FALSE;
        return;
    }
    mmi_frm_sms_get_background_save_setting(&isSave);
    msgReq = (MMI_FRM_SMS_SEND_MSG_BY_STORAGE_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq)); 
	if (!isSave && mmi_frm_sms_index_list[g_frm_sms_background_send_info.l4_index].nextindex == MMI_FRM_SMS_INVALID_INDEX)
	{
		msgReq->need_delete = KAL_TRUE;
	}
	SetProtocolEventHandler(mmi_frm_sms_background_send_sms_rsp, PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_RSP);
    msgReq->index = g_frm_sms_background_send_info.l4_index;
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_REQ,
        (oslParaType*) msgReq,
        NULL);
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_send_sms_rsp
 * DESCRIPTION
 *  Background send SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_send_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_MSG_BY_STORAGE_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_MSG_BY_STORAGE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((msgRsp->result) == TRUE)
    {
        CHISTIncSentSMS();
    }
    else
    {
        /* change the status of segment sent successfully from sent to unsent */            
        mmi_frm_sms_background_change_sent_to_unsent_req();

		return;
    }
    
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_RSP);
    
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    if (g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting)
    {
        mmi_frm_sms_check_delivery_report_awaited(msgRsp->result, msgRsp->concat_info, msgRsp->mr);        
    }
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */    

    
    /* send the next segment by storage index */
    if (mmi_frm_sms_index_list[msgRsp->index].nextindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        if (g_frm_sms_background_send_info.foreground_state == MMI_FRM_SMS_SEND_STATE_SUSPEND)
        {
            g_frm_sms_background_send_info.background_state = MMI_FRM_SMS_SEND_STATE_SUSPEND;        
            mmi_frm_sms_background_send_schedule();
            
            return;
        }
		
    	if (g_frm_sms_cntx.is_aborting)
		{
            ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
			mmi_frm_sms_background_change_sent_to_unsent_req();
		}
		else
		{
	        g_frm_sms_background_send_info.l4_index = mmi_frm_sms_index_list[msgRsp->index].nextindex;
	        mmi_frm_sms_background_send_sms_seg();
		}
    }
    else
    {
        BOOL isSave;

		if (g_frm_sms_cntx.is_aborting)
		{
			g_frm_sms_cntx.is_aborting = FALSE;
			ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
			backgroundSendAbortcallback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
		}
			
		while (mmi_frm_sms_index_list[g_frm_sms_background_send_info.l4_index].prevtype == MMI_FRM_SMS_NOBOX)
		{
			g_frm_sms_background_send_info.l4_index = mmi_frm_sms_index_list[g_frm_sms_background_send_info.l4_index].previndex;
		}
		
        mmi_frm_sms_get_background_save_setting(&isSave);
        if (isSave)
        {
        	U16 listindex;

			/* add current message to sent box list */
        	mmi_frm_sms_get_sms_msgbox_index(g_frm_sms_background_send_info.l4_index, &listindex);
			mmi_frm_sms_msg_box[listindex].msgtype &= 0xf000;
			mmi_frm_sms_msg_box[listindex].msgtype |= MMI_FRM_SMS_OUTBOX;
			mmi_frm_sms_move_sms_from_msgbox(MMI_FRM_SMS_UNSENT, listindex);
			mmi_frm_sms_index_list[g_frm_sms_background_send_info.l4_index].prevtype = MMI_FRM_SMS_OUTBOX;

			/* if sent successfully, only  refresh list, so index is invalid */
			mmi_frm_sms_background_send_refresh_ind(MMI_FRM_SMS_INVALID_INDEX, MMI_FRM_SMS_SUCTOSEND);
			g_frm_sms_background_send_info.background_state = MMI_FRM_SMS_SEND_STATE_IDLE;
			mmi_frm_sms_background_send_schedule();            
        }
        else
        {
            U16 L4index;
			MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *msgReq;
            
            /* delete current sent message */
            msgReq = (MMI_FRM_SMS_DEL_MSG_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
            L4index = g_frm_sms_background_send_info.l4_index;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_set_bitmap(L4index, msgReq->del_bitmap);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
		    msgReq->del_flag = SMSAL_DEL_BITMAP;
			msgReq->is_background_action = KAL_TRUE;
			g_frm_sms_background_send_info.l4_index = MMI_FRM_SMS_INVALID_INDEX;
		    SetProtocolEventHandler(mmi_frm_sms_delete_sms_sent_rsp, PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
		    mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ, (oslParaType*) msgReq, NULL);
			
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_pre_copy_sms_req
 * DESCRIPTION
 *  pre-copy SMS : check before copy SMS
 * PARAME     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_change_sent_to_unsent_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 l4_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	l4_index = g_frm_sms_background_send_info.l4_index;
    while (mmi_frm_sms_index_list[l4_index].prevtype == MMI_FRM_SMS_NOBOX)
    {
        l4_index = mmi_frm_sms_index_list[l4_index].previndex;
    }    
    if (l4_index != MMI_FRM_SMS_INVALID_INDEX)
    {
    	MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT *msgReq; 
		
	    msgReq = (MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
		
	    msgReq->new_status = SMSAL_STO_UNSENT;
	    msgReq->index = l4_index;
		msgReq->is_background_action = KAL_TRUE;
	    SetProtocolEventHandler(mmi_frm_sms_background_change_sent_to_unsent_rsp, PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP);   
	    mmi_frm_sms_send_message(
	        MOD_MMI,
	        MOD_L4C,
	        0,
	        PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ,
	        (oslParaType*) msgReq,
	        NULL);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_change_sent_to_unsent_rsp
 * DESCRIPTION
 *  set background message status response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_change_sent_to_unsent_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_STATUS_CNF_STRUCT *msgRsp = (MMI_FRM_SMS_SET_MSG_STATUS_CNF_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((msgRsp->result) == TRUE)
    { 
        if (mmi_frm_sms_index_list[msgRsp->index].nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
        	MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT *msgReq;			
            
           /* change the status of segment sent successfully from sent to unsent */            
            msgReq = (MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
			msgReq->new_status = SMSAL_STO_UNSENT;
		    msgReq->index = mmi_frm_sms_index_list[msgRsp->index].nextindex;
			msgReq->is_background_action = KAL_TRUE;		        
		    mmi_frm_sms_send_message(
		        MOD_MMI,
		        MOD_L4C,
		        0,
		        PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ,
		        (oslParaType*) msgReq,
		        NULL);
        }
        else
        {
        	U16 index;

			ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP);
	        mmi_frm_sms_get_sms_msgbox_index(msgRsp->index, &index);
	        mmi_frm_sms_msg_box[index].send_status = MMI_FRM_SMS_FAILTOSEND;
	        g_frm_sms_background_send_info.background_state = MMI_FRM_SMS_SEND_STATE_IDLE;
	    	if (g_frm_sms_cntx.is_aborting)
			{
				g_frm_sms_cntx.is_aborting = FALSE;
                ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
				backgroundSendAbortcallback(NULL, MOD_MMI, MMI_FRM_SMS_OK);
			}
			else
			{
				/* Only  refresh list, so index is invalid */
				mmi_frm_sms_background_send_refresh_ind(MMI_FRM_SMS_INVALID_INDEX, MMI_FRM_SMS_FAILTOSEND);
			}
	        mmi_frm_sms_background_send_schedule();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_pre_move_to_otherbox_req
 * DESCRIPTION
 *  pre-copy SMS : check before move SMS to other msgbox
 * PARAMETERS
 *  dummy       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_pre_move_to_otherbox_req(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_frm_sms_background_send_info.cur_l4_index != MMI_FRM_SMS_INVALID_INDEX)
    {
        if (g_frm_sms_background_send_info.dst_status == SMSAL_INVALID_STATUS)
        {
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
            
            return;
        }
		else
		{
			MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT *msgReq;

		    msgReq = (MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
		    msgReq->new_status = g_frm_sms_background_send_info.dst_status;
		    msgReq->index = g_frm_sms_background_send_info.cur_l4_index;
			msgReq->is_background_action = KAL_FALSE;
		    SetProtocolEventHandler(mmi_frm_sms_background_move_to_otherbox_rsp, PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP);    
		    mmi_frm_sms_send_message(
		        MOD_MMI,
		        MOD_L4C,
		        0,
		        PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ,
		        (oslParaType*) msgReq,
		        NULL);
		}        
    }
    else
    {
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_move_to_otherbox_rsp
 * DESCRIPTION
 *  set message status response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_move_to_otherbox_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SET_MSG_STATUS_CNF_STRUCT *msgRsp = (MMI_FRM_SMS_SET_MSG_STATUS_CNF_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (msgRsp->result == TRUE)
    { 
        if (mmi_frm_sms_index_list[msgRsp->index].nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
        	MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT *msgReq;
			
            /* change the status of segment sent successfully from sent to unsent */
		    msgReq = (MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
		    msgReq->new_status = g_frm_sms_background_send_info.dst_status;
		    msgReq->index = mmi_frm_sms_index_list[msgRsp->index].nextindex;
			msgReq->is_background_action = KAL_FALSE;		        
		    mmi_frm_sms_send_message(
		        MOD_MMI,
		        MOD_L4C,
		        0,
		        PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ,
		        (oslParaType*) msgReq,
		        NULL);      
        }
        else
        {
        	U16 listindex = mmi_frm_sms_index_list[g_frm_sms_background_send_info.cur_l4_index].previndex;
			U8 type;
			
		    switch (g_frm_sms_background_send_info.dst_status)
		    {
		        case SMSAL_REC_UNREAD:
		            type = MMI_FRM_SMS_UNREAD;
		            break;
		        case SMSAL_REC_READ:
		            type = MMI_FRM_SMS_INBOX;
		            break;
		        case SMSAL_STO_SENT:
		            type = MMI_FRM_SMS_OUTBOX;
		            break;
		        case SMSAL_STO_UNSENT:
		            type = MMI_FRM_SMS_UNSENT;
		            break;
				case SMSAL_STO_DRAFT:
					type = MMI_FRM_SMS_DRAFTS;
					break;
		        default:
		            type = MMI_FRM_SMS_NOBOX;
		            break;
		    }
			mmi_frm_sms_msg_box[listindex].msgtype &= 0xf000;
			mmi_frm_sms_msg_box[listindex].msgtype |= type;
			mmi_frm_sms_index_list[g_frm_sms_background_send_info.cur_l4_index].prevtype = type;
        	ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP);            
            mmi_frm_sms_move_sms_from_msgbox(g_frm_sms_background_send_info.msgType, listindex);           
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_OK);
        }
    }
	else
	{
		mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_ERROR);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_send_refresh_ind
 * DESCRIPTION
 *  Callback new message indication
 * PARAMETERS
 *  index       [IN]        failed SMS index
 *  send_stauts [IN]		the send status of message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_send_refresh_ind(U16 index, U8 send_stauts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *data = OslMalloc(sizeof(U16));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data = index;
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP, (void*)data, (U16)send_stauts);    
    OslMfree(data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms_sent_rsp
 * DESCRIPTION
 *  Delete sent SMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_sms_sent_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_DEL_MSG_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_DEL_MSG_RSP_STRUCT*) inMsg;
    U16 result = MMI_FRM_SMS_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        mmi_frm_sms_remove_sms_from_msgbox(msgRsp->del_bitmap);
        
		/* Only  refresh list, so index is invalid */
		mmi_frm_sms_background_send_refresh_ind(MMI_FRM_SMS_INVALID_INDEX, MMI_FRM_SMS_SUCTOSEND);		
        g_frm_sms_background_send_info.background_state = MMI_FRM_SMS_SEND_STATE_IDLE;
        mmi_frm_sms_background_send_schedule();		
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_vp_sc_req
 * DESCRIPTION
 *  Get vp and sc request
 * PARAMETERS
 *  index       [IN]        the index of profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_vp_sc_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT *msgReq;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->profile_no = index;
    SetProtocolEventHandler(mmi_frm_sms_get_vp_sc_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    mmi_frm_sms_send_message(
        MOD_MMI,
        MOD_L4C,
        0,
        PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ,
        (oslParaType*) msgReq,
        NULL);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_vp_sc_rsp
 * DESCRIPTION
 *  Get vp and sc response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_vp_sc_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT *msgRsp = (MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT*) inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {	
		g_frm_sms_background_send_info.vp = msgRsp->vp;
		memset(&(g_frm_sms_background_send_info.sc_addr), 0x00, sizeof(l4c_number_struct));
		memcpy(&(g_frm_sms_background_send_info.sc_addr), &(msgRsp->sc_addr), sizeof(l4c_number_struct));		
    }
}


#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __MMI_DUAL_SIM_MASTER__
void mmi_frm_sms_common_status_report_ind(void *inMsg)
{
	U8 i = 0;
	
	while (i < mmi_frm_sms_interrupt_handler_size)
       {
       	if (mmi_frm_sms_interrupt_handler[i].msgid == PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND)
              {
              	mmi_frm_sms_interrupt_handler[i].callback(inMsg, MOD_MMI, MMI_FRM_SMS_OK);
                    	break;
              }
              i++;
	}
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_card2_sms_sync_msg_ind
 * DESCRIPTION
 *  Handle sync indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_card2_sms_sync_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SYNC_MSG_IND_STRUCT *msgInd = (MMI_FRM_SMS_SYNC_MSG_IND_STRUCT*) inMsg;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msgInd->index != 0xffff)
	{
		msgInd->index += MTPNP_AD_Get_Card2_StartIdx_In_Msgbox();
	}
    switch (msgInd->action)
    {
        case L4C_AT_SMS_ADD:
            mmi_frm_sms_get_sms(NULL, MOD_MMI, msgInd->index);
            break;
        case L4C_AT_SMS_READ_CMGR:
        case L4C_AT_SMS_READ_CMGL:
        {
            U16 msgbox_index = 0;
            U16 msg_type = 0;

            mmi_frm_sms_get_sms_msgbox_index(msgInd->index, &msgbox_index);

            if (msgbox_index != MMI_FRM_SMS_INVALID_INDEX)
            {
                msg_type = (mmi_frm_sms_msg_box[msgbox_index].msgtype & 0x000f);

                /* From UNREAD to READ */
                if (msg_type == MMI_FRM_SMS_UNREAD && msgInd->status == SMSAL_REC_READ)
                {
                    mmi_frm_sms_set_sms_status(MMI_FRM_SMS_NOBOX, msgbox_index, MMI_FRM_SMS_INBOX);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMsg.c] mmi_frm_card2_sms_sync_msg_ind UNREAD index %d is updated-------*\n",
                                         msgInd->index);
                }
                /* From READ to UNREAD */
                else if (msg_type == MMI_FRM_SMS_INBOX && msgInd->status == SMSAL_REC_UNREAD)
                {
                    mmi_frm_sms_set_sms_status(MMI_FRM_SMS_NOBOX, msgbox_index, MMI_FRM_SMS_UNREAD);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMsg.c] mmi_frm_card2_sms_sync_msg_ind UNREAD index %d is updated-------*\n",
                                         msgInd->index);
                }

                /* Do nothing if from READ to READ and from UNREAD to UNREAD */
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*-------[SmsMsg.c] mmi_frm_card2_sms_sync_msg_ind READ no MSG BOX index %d-------*\n",
                                     msgInd->index);
            }

            break;
        }
        case L4C_AT_SMS_DELETE:
            mmi_frm_sms_remove_slave_sms_from_msgbox(msgInd->del_bitmap);
            break;
        case L4C_SMS_SIM_REFRESH:
			g_frm_sms_cntx.mmi_frm_sms_ready = TRUE;
            MTPNP_PFAL_Message_Ready_Ind(NULL);
            break;
    }
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND, NULL, (U16) msgInd->action);   

    /* Design for flow control */
    if (msgInd->action == L4C_AT_SMS_READ_CMGR ||
    	  msgInd->action == L4C_AT_SMS_ADD || msgInd->action == L4C_AT_SMS_DELETE)
    {
        mmi_sms_sync_msg_res_req_struct *msgReq;

        msgReq = (mmi_sms_sync_msg_res_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

        msgReq->result = TRUE;
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C_2, 0, MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ, (oslParaType*) msgReq, NULL);
    }
}
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

#endif /* __MOD_SMSAL__ */ 

