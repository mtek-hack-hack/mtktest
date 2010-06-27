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
 * SmsSettingsGuiInterface.C
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

   FILENAME : SmsSettingsGuiInterface.c

   PURPOSE     : it allows user to access the following settings,
                - service center number, 
                - validity period,
                - message type,
                - prefer storage
                - memory status,
                - reply path,
                - deliver report 

   REMARKS     : nil

   AUTHOR      : Magesh, hiran

   DATE     : 01-01-2003

**************************************************************/

#include "MMI_include.h"
#ifdef __MOD_SMSAL__
/*  */
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
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
/*  */
#include "GSM7BitDefaultAlphabet.h"
#include "wgui_status_icons.h"
/*  */
/*  */
#include "CSP.h"
#include "SettingProfile.h"
#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"
#include "SettingProt.h"
#include "AlarmFrameworkProt.h"
#include "IdleAppProt.h"
/*  */
#include "CallManagementGprot.h"
#include "callsetup.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGProt.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
#define MMI_SMS_SETTING_ITEM_NUM		3

static U8 CommonSettingItem[MMI_SMS_SETTING_ITEM_NUM];
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

//static U8 DeliveryRepyStates[2];
U8 DeliveryRepyStates[2];   // WMD取消此处的static属性

static msg_profile_edit_struct psProfileEditInfo;   /* attn: reduce one of this struct obj.... */
static msg_profile_list_struct psProfileNameList;
static PU8 vpItems[MAX_LFOUR_VP];
static PU8 msgTypeItems[MAX_LFOUR_MSG_TYPE];
static U16 defaultProfileNames[MAX_LFOUR_PROFILES] = 
{
    STR_SET0_MENUENTRY,
    STR_SET1_MENUENTRY,
    STR_SET2_MENUENTRY,
    STR_SET3_MENUENTRY
};
static U16 profileEditIcons[MAX_PROFILE_EDIT_ITEMS] = 
{
    IMG_SMS_PROFILE_NAME,
    IMG_SMS_PROFILE_SC,
    IMG_SMS_PROFILE_VP,
    IMG_SMS_PROFILE_MSG_TYPE
};
U16 profileEditStrings[MAX_PROFILE_EDIT_ITEMS];
static U8 *pMailBoxName[MAX_MAILBOX_PS_SUPPORT] = {NULL, NULL};
static U8 *pMailBoxNumber[MAX_MAILBOX_PS_SUPPORT] = {NULL, NULL};
static U8 psMailBoxDCS[MAX_MAILBOX_PS_SUPPORT];
static msg_mailbox_edit_struct psMailboxEditInfo;

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
static msg_mem_status_struct memStatus = {SMSAL_STORAGE_UNSPECIFIED, 0, 0, 0, 0};
#endif 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
static msg_bearer_enum preferBearer;
#endif 

static U16 mmi_msg_mailbox_num = 0;


static BOOL is_edit_voicemail_num_from_idle; 

/********************************************************************

                  variables

********************************************************************/
extern msg_active_profile_struct activeProfile;

extern U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
extern PU8 hintDataPtrs[MAX_SUB_MENUS];
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern wgui_inline_item wgui_inline_items[];

extern void MakeCall(PS8 strNumber);


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_mailbox_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailbox     [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_mailbox_rsp(void *mailbox, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_number = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_frm_sms_mailbox_struct *mailboxlist = (mmi_frm_sms_mailbox_struct*) mailbox;

        if (mailboxlist->mailboxNumber == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
        }
        else
        {
        	U8 mailboxnumber;
			U8 currentMailboxIndex;			
        	U8 i;

			if (mailboxlist->mailboxNumber >= MAX_MAILBOX_PS_SUPPORT)
        	{
				mailboxnumber = MAX_MAILBOX_PS_SUPPORT;
			}
			else
			{
				mailboxnumber = mailboxlist->mailboxNumber;
			}

			psMailboxEditInfo.malboxNameLength = mailboxlist->mailboxNameLength;
            for (i = 0; i < mailboxnumber; i++)
            {
                pMailBoxNumber[i] = OslMalloc((MAX_CC_ADDR_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
				mmi_ucs2cpy((S8*)pMailBoxNumber[i], (S8*)mailboxlist->pMailBoxNumber[i]);

                pMailBoxName[i] = OslMalloc((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                mmi_ucs2cpy((S8*)pMailBoxName[i], (S8*)mailboxlist->pMailBoxName[i]);
                psMailBoxDCS[i] = mailboxlist->mailboxNameDcs[i];

                if (mmi_ucs2strlen((PS8) pMailBoxNumber[i]) != 0)
                {
                    is_number = MMI_TRUE;
                }
            }
			
            if (mailboxlist->mailboxNumber >= MAX_MAILBOX_PS_SUPPORT)
            {
                if (g_callset_context.LineID == LINE1)
                {
					currentMailboxIndex = 0;
				}
				else
				{
					currentMailboxIndex = 1;
				}
            }
			else
			{
				currentMailboxIndex = 0;
			}
			
            if (is_number)
            {
                if (pMailBoxNumber[currentMailboxIndex] != NULL &&
                    mmi_ucs2strlen((PS8) pMailBoxNumber[currentMailboxIndex]) != 0)
                {
                #ifdef __MMI_DUAL_SIM_MASTER__   
        			mmi_ucm_app_entry_dial_option((U8*)pMailBoxNumber[currentMailboxIndex], NULL, NULL);
    			#else /* __MMI_DUAL_SIM_MASTER__ */
                    MakeCall((PS8) pMailBoxNumber[currentMailboxIndex]); 
				#endif /* __MMI_DUAL_SIM_MASTER__ */                       
                }
                else
                {	
                	if (mailboxlist->mailboxNumber >= MAX_MAILBOX_PS_SUPPORT)
					{
						mmi_msg_entry_set_voicemail_number_confirm(currentMailboxIndex, mailboxlist->mailboxNameDcs[currentMailboxIndex]);
                	}
					else
					{
						/* Impossible case */
						MMI_ASSERT(0);     
					}
				}
            }
            else
            {
                if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_VOICE_MAIL_NOT_READY_YET),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }
                else
                {
					mmi_msg_entry_set_voicemail_number_confirm(currentMailboxIndex, mailboxlist->mailboxNameDcs[currentMailboxIndex]);
                }
            }
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
 *  mmi_msg_dial_mailbox_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_mailbox_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL); /* To enter dummy screen function */
    ShowCategoryDummyScreen();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_mailbox_info(mmi_msg_dial_mailbox_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_mailbox_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailbox     [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_mailbox_list_rsp(void *mailbox, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_frm_sms_mailbox_struct *mailboxlist = (mmi_frm_sms_mailbox_struct*) mailbox;
        U8 i = 0;

        mmi_msg_mailbox_num = (U16)mailboxlist->mailboxNumber;

        if (mailboxlist->mailboxNumber == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
        }
        else
        {
            psMailboxEditInfo.malboxNameLength = mailboxlist->mailboxNameLength;
            for (i = 0; i < mailboxlist->mailboxNumber; i++)
            {
                pMailBoxName[i] = OslMalloc((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                mmi_ucs2cpy((S8*) pMailBoxName[i], (S8*) mailboxlist->pMailBoxName[i]);

                pMailBoxNumber[i] = OslMalloc((MAX_CC_ADDR_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                mmi_ucs2cpy((S8*) pMailBoxNumber[i], (S8*) mailboxlist->pMailBoxNumber[i]);

                psMailBoxDCS[i] = mailboxlist->mailboxNameDcs[i];
            }
            mmi_msg_entry_voice_mail_server();
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
 *  mmi_msg_get_mailbox_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_mailbox_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_mailbox_info(mmi_msg_get_mailbox_list_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_profile_active_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_profile_active_rsp(void *index, module_type mod_src, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    psProfileNameList.currReqProfileNo = *((U8*) index);
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_profile_active_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_profile_active_req(U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_profile_active(mmi_msg_set_profile_active_rsp, MOD_MMI, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_profile_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_profile_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_msg_set_profile_active_req((U8*) & (g_msg_cntx.currHiliteIndex));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_mailbox_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailboxdetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_mailbox_inline_item_rsp(void *mailboxdetail, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_OPTION);
    if (result == MMI_FRM_SMS_OK)
    {
		if (is_edit_voicemail_num_from_idle == FALSE)
		{
			msg_mailbox_edit_struct *mailbox = (msg_mailbox_edit_struct*) mailboxdetail;

			mmi_ucs2cpy((S8*) pMailBoxName[mailbox->mailboxIndex], (S8*) mailbox->mailboxName);
	        mmi_ucs2cpy((S8*) pMailBoxNumber[mailbox->mailboxIndex], (S8*) mailbox->mailboxAddress);
		}
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
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

	if (is_edit_voicemail_num_from_idle == TRUE)
	{
		DeleteScreenIfPresent(SCR_ID_MSG_VOICE_MAIL_EDIT);
	}
	else
	{
    	DeleteMessagesHistoryNodes();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_mailbox_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_mailbox_inline_item_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_check_valid_number((S8*)psMailboxEditInfo.mailboxAddress) == FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }
    
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_mailbox_info(mmi_msg_set_mailbox_inline_item_rsp, MOD_MMI, (void*)&psMailboxEditInfo);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_mailbox_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_mailbox_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) pMailBoxNumber[g_msg_cntx.currHiliteIndex]) != 0)
    {
        MakeCall((PS8) pMailBoxNumber[g_msg_cntx.currHiliteIndex]);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_VM_NO_NUMBER_TO_DIAL),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_dial_mailbox_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_dial_mailbox_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) pMailBoxNumber[g_msg_cntx.currHiliteIndex]) != 0)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__   
		mmi_ucm_app_entry_dial_option((U8*)pMailBoxNumber[g_msg_cntx.currHiliteIndex], NULL, NULL);
	#else /* __MMI_DUAL_SIM_MASTER__ */
        MakeCall((PS8) pMailBoxNumber[g_msg_cntx.currHiliteIndex]); 
	#endif /* __MMI_DUAL_SIM_MASTER__ */ 
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_VM_NO_NUMBER_TO_DIAL),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_profile_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profilelist     [?]         
 *  mod             [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_profile_list_rsp(void *profilelist, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        memset(&psProfileNameList, 0, sizeof(msg_profile_list_struct));
        memcpy((S8*) & psProfileNameList, (S8*) profilelist, sizeof(msg_profile_list_struct));
        if (psProfileNameList.currMaxPsProfiles > 0)
        {
            mmi_msg_entry_profile_settings();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
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
 *  mmi_msg_get_profile_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_profile_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_profile_list(mmi_msg_get_profile_list_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_profile_highlight_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_profile_highlight_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.currHiliteIndex = nIndex;
    if (g_msg_cntx.currHiliteIndex != psProfileNameList.currReqProfileNo)
    {
        mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_save_profile_active, Messages2GoBackHistory);
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_profile_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROFILE_EDIT);
    if (result == MMI_FRM_SMS_OK)
    {
        msg_profile_edit_struct *profile = (msg_profile_edit_struct*) profiledetail;

        mmi_ucs2cpy(
            (S8*) & psProfileNameList.profileName[psProfileEditInfo.profileIndex],
            (S8*) profile->profileName);
        switch (profile->vpIndex)
        {
            case SMSAL_VP_1_HR:
                psProfileEditInfo.vpIndex = 0;
                break;
            case SMSAL_VP_6_HR:
                psProfileEditInfo.vpIndex = 1;
                break;                
            case SMSAL_VP_12_HR:
                psProfileEditInfo.vpIndex = 2;
                break;
            case SMSAL_VP_24_HR:
                psProfileEditInfo.vpIndex = 3;
                break;
            case SMSAL_VP_72_HR:
                psProfileEditInfo.vpIndex = 4;
                break;                
            case SMSAL_VP_1_WEEK:
                psProfileEditInfo.vpIndex = 5;
                break;
            case SMSAL_VP_MAX:
                psProfileEditInfo.vpIndex = 6;
                break;
            default:
                psProfileEditInfo.vpIndex = 6;
                break;
        }

        switch (profile->msgTypeIndex)
        {
            case SMSAL_DEFAULT_PID:
                psProfileEditInfo.msgTypeIndex = 0;
                break;
            case SMSAL_G3_FAX_PID:
                psProfileEditInfo.msgTypeIndex = 1;
                break;
            case SMSAL_PAGING_PID:
                psProfileEditInfo.msgTypeIndex = 2;
                break;
            case SMSAL_EMAIL_PID:
                psProfileEditInfo.msgTypeIndex = 3;
                break;
            default:
                psProfileEditInfo.msgTypeIndex = 0;
                break;
        }
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
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
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_profile_inline_item_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 scAddress[MAX_DIGITS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(scAddress, 0, MAX_DIGITS + 1);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) psProfileEditInfo.scAddress, (MAX_CC_ADDR_LEN *ENCODING_LENGTH));
    if (MMI_FALSE == mmi_frm_sms_check_dst_number((U8*)scAddress, (U8)strlen(scAddress)))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }
    
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        switch ((U8) psProfileEditInfo.vpIndex)
        {
            case 0:
                psProfileEditInfo.vpIndex = SMSAL_VP_1_HR;
                break;
            case 1:
                psProfileEditInfo.vpIndex = SMSAL_VP_6_HR;
                break;
            case 2:
                psProfileEditInfo.vpIndex = SMSAL_VP_12_HR;
                break;
            case 3:
                psProfileEditInfo.vpIndex = SMSAL_VP_24_HR;
                break;
            case 4:
                psProfileEditInfo.vpIndex = SMSAL_VP_72_HR;
                break;                
            case 5:
                psProfileEditInfo.vpIndex = SMSAL_VP_1_WEEK;
                break;
            case 6:
                psProfileEditInfo.vpIndex = SMSAL_VP_MAX;
                break;
            default:
                psProfileEditInfo.vpIndex = SMSAL_VP_MAX;
                break;
        }
    }
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        switch ((U8) psProfileEditInfo.msgTypeIndex)
        {
            case 0:
                psProfileEditInfo.msgTypeIndex = SMSAL_DEFAULT_PID;
                break;
            case 1:
                psProfileEditInfo.msgTypeIndex = SMSAL_G3_FAX_PID;
                break;
            case 2:
                if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_PAGING))
                {
                    psProfileEditInfo.msgTypeIndex = SMSAL_PAGING_PID;
                    break;
                }
            case 3:
                if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_EMAIL))
                {
                    psProfileEditInfo.msgTypeIndex = SMSAL_EMAIL_PID;
                    break;
                }
            default:
                psProfileEditInfo.msgTypeIndex = SMSAL_DEFAULT_PID;
                break;
        }
    }
    ClearAllKeyHandler();
    mmi_frm_sms_set_profile_detail(mmi_msg_set_profile_inline_item_rsp, MOD_MMI, (void*)&psProfileEditInfo);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_profile_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        memcpy((S8*) & psProfileEditInfo, (S8*) profiledetail, sizeof(msg_profile_edit_struct));
        psProfileEditInfo.profileIndex = g_msg_cntx.currHiliteIndex;
        switch (psProfileEditInfo.vpIndex)
        {
            case SMSAL_VP_1_HR:
                psProfileEditInfo.vpIndex = 0;
                break;
            case SMSAL_VP_6_HR:
                psProfileEditInfo.vpIndex = 1;
                break;
            case SMSAL_VP_12_HR:
                psProfileEditInfo.vpIndex = 2;
                break;
            case SMSAL_VP_24_HR:
                psProfileEditInfo.vpIndex = 3;
                break;
            case SMSAL_VP_72_HR:
                psProfileEditInfo.vpIndex = 4;
                break;                
            case SMSAL_VP_1_WEEK:
                psProfileEditInfo.vpIndex = 5;
                break;
            case SMSAL_VP_MAX:
                psProfileEditInfo.vpIndex = 6;
                break;
            default:
                psProfileEditInfo.vpIndex = 6;
                break;
        }

        switch (psProfileEditInfo.msgTypeIndex)
        {
            case SMSAL_DEFAULT_PID:
                psProfileEditInfo.msgTypeIndex = 0;
                break;
            case SMSAL_G3_FAX_PID:
                psProfileEditInfo.msgTypeIndex = 1;
                break;
            case SMSAL_PAGING_PID:
                psProfileEditInfo.msgTypeIndex = 2;
                break;
            case SMSAL_EMAIL_PID:
                psProfileEditInfo.msgTypeIndex = 3;
                break;
            default:
                psProfileEditInfo.msgTypeIndex = 0;
                break;
        }
        mmi_msg_entry_profile_edit();
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
 *  mmi_msg_get_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_profile_inline_item_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_profile_detail(mmi_msg_get_profile_inline_item_rsp, MOD_MMI, (U8) g_msg_cntx.currHiliteIndex);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_common_settings_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_common_settings_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        U8 *DrRp = (U8*) data;

        DeliveryRepyStates[0] = DrRp[0];
        DeliveryRepyStates[1] = DrRp[1];

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		CommonSettingItem[0] = DeliveryRepyStates[0];
		CommonSettingItem[1] = DeliveryRepyStates[1];
		mmi_frm_sms_get_background_save_setting((BOOL*)&CommonSettingItem[2]);		
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

        mmi_msg_entry_common_settings();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_common_settings_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_common_settings_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_common_settings(mmi_msg_get_common_settings_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_common_settings_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_common_settings_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		if (mmi_frm_sms_set_background_save_setting((BOOL)CommonSettingItem[2]) != MMI_FRM_SMS_OK)
		{
		    DisplayPopup(
	            (PU8) GetString(STR_GLOBAL_UNFINISHED),
	            IMG_GLOBAL_UNFINISHED,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) WARNING_TONE);
		}
		else
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
		{
	        DisplayPopup(
	            (PU8) GetString(STR_GLOBAL_SAVED),
	            IMG_GLOBAL_ACTIVATED,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) SUCCESS_TONE);
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
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_common_settings_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_common_settings_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	DeliveryRepyStates[0] = CommonSettingItem[0];
	DeliveryRepyStates[1] = CommonSettingItem[1];
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    mmi_frm_sms_set_common_settings(mmi_msg_set_common_settings_rsp, MOD_MMI, DeliveryRepyStates);
}

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_bearer_service_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearer      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_bearer_service_rsp(void *bearer, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        preferBearer = (msg_bearer_enum) (*(U8*) bearer);
        mmi_msg_entry_msg_settings();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_bearer_service_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_bearer_service_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_preferred_bearer(mmi_msg_get_bearer_service_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_bearer_service_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_bearer_service_rsp(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        preferBearer = (msg_bearer_enum) g_msg_cntx.currHiliteIndex;
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_bearer_service_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_bearer_service_req(U8 bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_preferred_bearer(mmi_msg_set_bearer_service_rsp, MOD_MMI, bearer);
}
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__

#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_preferred_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage     [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_preferred_storage_rsp(void *storage, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        memStatus.prefStorage = *(U8*) storage;
    #if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
        mmi_msg_get_bearer_service_req();
    #else 
        mmi_msg_entry_msg_settings();
    #endif 
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
 *  mmi_msg_get_preferred_storage_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_preferred_storage_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_preferred_storage(mmi_msg_get_preferred_storage_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_preferred_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage     [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_preferred_storage_rsp(void *storage, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        memStatus.prefStorage = *(U8*) storage;
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_preferred_storage_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_preferred_storage_req(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_preferred_storage(mmi_msg_set_preferred_storage_rsp, MOD_MMI, storage);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_memory_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_memory_status_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mem_status_struct *memorystatus = (msg_mem_status_struct*) data;

        memStatus.simTotal = memorystatus->simTotal;
        memStatus.meTotal = memorystatus->meTotal;
        memStatus.simUsed = memorystatus->simUsed;
        memStatus.meUsed = memorystatus->meUsed;
        if (IsScreenPresent(SCR_ID_MSG_MEMORY_STATUS))
        {
            HistoryReplace(SCR_ID_MSG_MEMORY_STATUS, SCR_ID_MSG_MEMORY_STATUS, mmi_msg_entry_memory_status);
        }
        else
        {
            mmi_msg_entry_memory_status();
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_memory_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_memory_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not  call ClearInputEventHandler(MMI_DEVICE_ALL) if SCR_ID_MSG_MEMORY_STATUS is already in history. Ex. new msg ind pops up when screen is SCR_ID_MSG_MEMORY_STATUS */
    if (!IsScreenPresent(SCR_ID_MSG_MEMORY_STATUS))
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    mmi_frm_sms_get_memory_status(mmi_msg_get_memory_status_rsp, MOD_MMI);
}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_preferred_memory_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_preferred_memory_status_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mem_status_struct *memorystatus = (msg_mem_status_struct*) data;

        memStatus.simTotal = memorystatus->simTotal;
        memStatus.meTotal = memorystatus->meTotal;
        memStatus.simUsed = memorystatus->simUsed;
        memStatus.meUsed = memorystatus->meUsed;
        if (IsScreenPresent(SCR_ID_MSG_PREFERRED_STORAGE))
        {
            HistoryReplace(SCR_ID_MSG_PREFERRED_STORAGE, SCR_ID_MSG_PREFERRED_STORAGE, mmi_msg_entry_preferred_storage);
        }
        else
        {
            mmi_msg_entry_preferred_storage();
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_preferred_memory_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_preferred_memory_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not  call ClearInputEventHandler(MMI_DEVICE_ALL) if SCR_ID_MSG_PREFERRED_STORAGE is already in history. Ex. new msg ind pops up when screen is SCR_ID_MSG_PREFERRED_STORAGE */
    if (!IsScreenPresent(SCR_ID_MSG_PREFERRED_STORAGE))
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    mmi_frm_sms_get_memory_status(mmi_msg_get_preferred_memory_status_rsp, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_preferred_storage
 * DESCRIPTION
 *  Set preferred storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    if (((g_msg_cntx.currHiliteIndex == 0) && (memStatus.prefStorage == 0))
        || ((g_msg_cntx.currHiliteIndex == 1) && (memStatus.prefStorage == 1)))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else if (((g_msg_cntx.currHiliteIndex == 0) && (memStatus.simTotal == 0)) ||
             ((g_msg_cntx.currHiliteIndex == 1) && (memStatus.meTotal == 0)))
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_DOES_NOT_SUPPORT),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        if (g_msg_cntx.currHiliteIndex == 0)
        {
            mmi_msg_set_preferred_storage_req(SMSAL_SM_PREFER);
        }
        else if (g_msg_cntx.currHiliteIndex == 1)
        {
            mmi_msg_set_preferred_storage_req(SMSAL_ME_PREFER);
        }
    }
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_refresh_memory_status
 * DESCRIPTION
 *  Refresh memory status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_refresh_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_MSG_MEMORY_STATUS))
    {
        mmi_msg_get_memory_status_req();
    }
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_PREFERRED_STORAGE))
    {
        mmi_msg_get_preferred_memory_status_req();
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

}

#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_bearer_settings
 * DESCRIPTION
 *  Set bearer settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_bearer_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    if (g_msg_cntx.currHiliteIndex == preferBearer)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        mmi_msg_set_bearer_service_req((U8) g_msg_cntx.currHiliteIndex);
    }

}
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_profile_inline_item
 * DESCRIPTION
 *  Set profile items for edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_profile_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 numOfMenuItems = 2;
    U8 numOfMsgTypes = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vpItems[0] = (PU8) GetString(STR_1HOUR_MENUENTRY);
    vpItems[1] = (PU8) GetString(STR_6HOUR_MENUENTRY);
    vpItems[2] = (PU8) GetString(STR_12HOUR_MENUENTRY);
    vpItems[3] = (PU8) GetString(STR_24HOUR_MENUENTRY);
    vpItems[4] = (PU8) GetString(STR_3DAY_MENUENTRY);
    vpItems[5] = (PU8) GetString(STR_1WEEK_MENUENTRY);
    vpItems[6] = (PU8) GetString(STR_63WEEKS_MENUENTRY);
    /* message type */
    msgTypeItems[0] = (PU8) GetString(STR_TEXT_MENUENTRY);
    msgTypeItems[1] = (PU8) GetString(STR_FAX_MENUENTRY);
    if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_PAGING))
    {
        msgTypeItems[numOfMsgTypes] = (PU8) GetString(STR_PAGE_MENUENTRY);
        numOfMsgTypes++;
    }
    if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_EMAIL))
    {
        msgTypeItems[numOfMsgTypes] = (PU8) GetString(STR_MT_EMAIL_MENUENTRY);
        numOfMsgTypes++;
    }
    /* say activate these items */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    /* profile name */
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[0],
        STR_PROFILE_NAME,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        (PU8) psProfileEditInfo.profileName,
        /* MAX_PROFILE_NAME_LEN */ psProfileNameList.profileNameLength + 1,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_GSM_EXTENDED_HANDLING);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[0], mmi_msg_inline_generic_custom_function);
    /* service center */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) psProfileEditInfo.scAddress,
        MAX_DIGITS_SMS,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[1]);
    /* validity period */
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        SetInlineItemActivation(&wgui_inline_items[numOfMenuItems], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[numOfMenuItems], MAX_LFOUR_VP, vpItems, &psProfileEditInfo.vpIndex);
        numOfMenuItems++;
    }
    /* message type */
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        SetInlineItemActivation(&wgui_inline_items[numOfMenuItems], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[numOfMenuItems],
            numOfMsgTypes,
            msgTypeItems,
            &psProfileEditInfo.msgTypeIndex);
        numOfMenuItems++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_msg_settings
 * DESCRIPTION
 *  Entry message settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_msg_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S32 maskingByte=-1; */

    EntryNewScreen(SCR_ID_MSG_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_msg_settings, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsSettingsGuiInterface.c] EntryScrMessageSetup -------*\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SETTINGS);

    /* diamond, 2005/07/01 add _Ext to menu item functions */
    numItems = GetNumOfChild_Ext(MESSAGES_MENU_MSG_SETTINGS_MENUID);
    GetSequenceStringIds_Ext(MESSAGES_MENU_MSG_SETTINGS_MENUID, nStrItemList);

#ifdef __MMI_DUAL_SIM_MASTER__
	mmi_cphs_rearrange_message_setting_menu(SIM1);
	mmi_cphs_rearrange_message_setting_menu(SIM2);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetParentHandler(MESSAGES_MENU_MSG_SETTINGS_MENUID);
    ConstructHintsList(MESSAGES_MENU_MSG_SETTINGS_MENUID, popUpList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetMessagesCurrScrnID(SCR_ID_MSG_SETTINGS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SETTINGS);

    mmi_msg_set_msg_menu_highlight_handler();

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
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
	#ifndef __MMI_GPRS_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    ShowCategory52Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
		STRING_MTPNP_SIM1_MESSAGESETUP_MENUENTRY,
	#else
        STR_MESSAGESETUP_MENUENTRY,
    #endif
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_msg_settings
 * DESCRIPTION
 *  Before entering message settings menu, get preferred storage and/or bearer settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_msg_settings(void)
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
        return;
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    mmi_msg_get_preferred_storage_req();
#elif defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
    mmi_msg_get_bearer_service_req();
#else 
    mmi_msg_entry_msg_settings();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_profile_edit_highlight_handler
 * DESCRIPTION
 *  Entry profile edit screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_profile_edit_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(profileEditStrings[index]));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_profile_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;

    U8 numOfItems = MAX_PROFILE_EDIT_ITEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_PROFILE_EDIT, mmi_msg_exit_profile_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_PROFILE_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_MSG_PROFILE_EDIT, &inputBufferSize);

    RegisterHighlightHandler(mmi_msg_profile_edit_highlight_handler);
    profileEditStrings[0] = STR_PROFILE_NAME;
    profileEditStrings[1] = STR_PROFILE_SC;
    profileEditStrings[2] = STR_PROFILE_VP;
    profileEditStrings[3] = STR_PROFILE_MSG_TYPE;

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        numOfItems--;
    }
    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        numOfItems--;
    }

    mmi_msg_set_profile_inline_item();
    if (guiBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, numOfItems, inputBuffer);
    }

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROFILE_EDIT);
    SetMessagesCurrScrnID(SCR_ID_MSG_PROFILE_EDIT);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_profile_inline_item_req, Messages2GoBackHistory);

    ShowCategory57Screen(
        STR_PROFILE_NAME,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        profileEditIcons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_profile_edit
 * DESCRIPTION
 *  Exit profile edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsSettingsGuiInterface.c] ExitScrProfileSetting -------*\n");
    if (GetUCS2Flag((PS8) psProfileEditInfo.profileName))
    {
        psProfileEditInfo.profileNameDcs = PHB_UCS2;
    }
    else
    {
        psProfileEditInfo.profileNameDcs = PHB_ASCII;
    }
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_PROFILE_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_ID_MSG_PROFILE_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_profile_edit;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) currHistory.inputBuffer);   /* added for inline edit history */
    AddNHistory(currHistory, inputBufferSize);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_profile_settings
 * DESCRIPTION
 *  Entry profile settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_profile_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;
    S32 hiliteitem;

    S8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_PROFILE_LIST, mmi_msg_exit_generic, mmi_msg_entry_profile_settings, NULL);

    for (index = 0; (index < psProfileNameList.currMaxPsProfiles) && (index < MAX_LFOUR_PROFILES); index++)
    {
        if ((psProfileNameList.profileName[index][0] == '\0') && (psProfileNameList.profileName[index][1] == '\0'))
        {
            subMenuDataPtrs[index] = (PU8) GetString((U16) defaultProfileNames[index]);
        }
        else
        {
            subMenuDataPtrs[index] = (PU8) psProfileNameList.profileName[index];
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_PROFILE_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        hiliteitem = psProfileNameList.currReqProfileNo;
    }
    RegisterHighlightHandler(mmi_msg_get_profile_highlight_index);

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROFILE_LIST);
    SetMessagesCurrScrnID(SCR_ID_MSG_PROFILE_LIST);

    ShowCategory36Screen(
        STR_PROFILE_SETTING_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        subMenuDataPtrs,
        (U16) hiliteitem,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_get_profile_inline_item_req, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_common_settings
 * DESCRIPTION
 *  Entry common settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_common_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 numItems = 2;
    S32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_COMMON_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_common_settings, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsSettingsGuiInterface.c] EntryScrCommonSettings -------*\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_COMMON_SETTINGS);
    subMenuDataPtrs[0] = (PU8) GetString((U16) STR_DELIVERY_REPORT_MENUENTRY);
    subMenuDataPtrs[1] = (PU8) GetString((U16) STR_REPLY_PATH_MENUENTRY);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    subMenuDataPtrs[2] = (PU8) GetString((U16) STR_SMS_BACKGROUND_SAVE_SENT_MSG_ID);
	numItems++;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_COMMON_SETTINGS);
    SetMessagesCurrScrnID(SCR_ID_MSG_COMMON_SETTINGS);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_common_settings_req, Messages2GoBackHistory);

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf))
    {
        ResetBit(maskingByte, 0);
    }
    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Reply_path))
    {
        ResetBit(maskingByte, 1);
    }

    MaskStringItems(subMenuDataPtrs, (U8) numItems, maskingByte);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    numItems = MaskItemsU8(CommonSettingItem, (U8) numItems, maskingByte);	
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    numItems = MaskItemsU8(DeliveryRepyStates, (U8) numItems, maskingByte);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(
        STR_COMMONSETTING_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        numItems,
        (U8 **) subMenuDataPtrs,
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		(U8*) CommonSettingItem,
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
		(U8*) DeliveryRepyStates,
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        0,
        guiBuffer);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_memory_status
 * DESCRIPTION
 *  Entry memory status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 modeValue;
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    char spaceBuf[5];
    S8 memoryStatus[MAX_SUBMENU_CHARACTERS * 2 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_MEMORY_STATUS, mmi_msg_exit_generic, mmi_msg_entry_memory_status, NULL);
    memset(memoryStatus, 0, MAX_SUBMENU_CHARACTERS * 2 * ENCODING_LENGTH);
    memset(spaceBuf, 0, 5);
    mmi_asc_to_ucs2(spaceBuf, "\n");

    mmi_ucs2cpy(memoryStatus, GetString(STR_SMSSTATUS_TITLE));
    mmi_ucs2cat(memoryStatus, spaceBuf);

    mmi_ucs2cat(memoryStatus, GetString(STR_SMS_MEMSTATUS_PREFIX_SIM));
    memset(tempBuf, 0, MAX_SUBMENU_CHARACTERS);
    if (memStatus.simTotal > 0)
    {
        modeValue = ((memStatus.simUsed) * 100) % (memStatus.simTotal);
        sprintf(tempBuf, "%d.%02d%%", ((memStatus.simUsed) * 100) / (memStatus.simTotal), (modeValue * 100) / (memStatus.simTotal));
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
    }
    else
    {
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }
    mmi_ucs2cat(memoryStatus, spaceBuf);

    mmi_ucs2ncat(memoryStatus, GetString(STR_SMS_MEMSTATUS_PREFIX_PHONE), 16);
    memset(tempBuf, 0, MAX_SUBMENU_CHARACTERS);
    if (memStatus.meTotal > 0)
    {
        modeValue = ((memStatus.meUsed) * 100) % (memStatus.meTotal);
        sprintf(tempBuf, "%d.%02d%%", ((memStatus.meUsed) * 100) / (memStatus.meTotal), ((modeValue) * 100) / (memStatus.meTotal));
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2ncat(memoryStatus, tempBufUnicode, 16);
    }
    else
    {
        mmi_ucs2ncat(memoryStatus, (S8*) GetString(STR_SMS_DOES_NOT_SUPPORT), 16);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_MEMORY_STATUS);
    if ((guiBuffer != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_ID_MSG_MEMORY_STATUS))
    {
        DeleteNScrId(SCR_ID_MSG_MEMORY_STATUS);
    }

    SetMessagesCurrScrnID(SCR_ID_MSG_MEMORY_STATUS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_MEMORY_STATUS);

    ShowCategory7Screen(
        STR_SMSSTATUS_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) memoryStatus,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_preferred_storage
 * DESCRIPTION
 *  Entry preferred storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 2;
    S32 hiliteitem;
    U16 modeValue;
    char tempBuf[MAX_SUBMENU_CHARACTERS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_PREFERRED_STORAGE, mmi_msg_exit_generic, mmi_msg_entry_preferred_storage, NULL);

    memset(hintData[0], 0, MAX_SUB_MENU_HINT_SIZE);
    memset(hintData[1], 0, MAX_SUB_MENU_HINT_SIZE);

    if (memStatus.simTotal > 0)
    {
        modeValue = ((memStatus.simUsed) * 100) % (memStatus.simTotal);
        sprintf(tempBuf, "%d.%02d%%", ((memStatus.simUsed) * 100) / (memStatus.simTotal), (modeValue * 100) / (memStatus.simTotal));
        mmi_asc_to_ucs2((S8*) hintData[0], tempBuf);
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[0], (S8*) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }

    if (memStatus.meTotal > 0)
    {
        modeValue = ((memStatus.meUsed) * 100) % (memStatus.meTotal);
        sprintf(tempBuf, "%d.%02d%%", ((memStatus.meUsed) * 100) / (memStatus.meTotal), ((modeValue) * 100) / (memStatus.meTotal));
        mmi_asc_to_ucs2((S8*) hintData[1], tempBuf);
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[1], (S8*) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }

    hintDataPtrs[0] = hintData[0];
    hintDataPtrs[1] = hintData[1];

    subMenuDataPtrs[0] = (PU8) GetString(STR_SIM_STORAGE_MENUENTRY);
    subMenuDataPtrs[1] = (PU8) GetString(STR_ME_STORAGE_MENUENTRY);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_PREFERRED_STORAGE);
    if ((guiBuffer != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_ID_MSG_PREFERRED_STORAGE))
    {
        DeleteNScrId(SCR_ID_MSG_PREFERRED_STORAGE);
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        if (memStatus.prefStorage == 0)
        {
            hiliteitem = 0;
        }
        else
        {
            hiliteitem = 1;
        }
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_ID_MSG_PREFERRED_STORAGE);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PREFERRED_STORAGE);

    ShowCategory109Screen(
        STR_PREFEREDSTORAGE_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        subMenuDataPtrs,
        hintDataPtrs,
        hiliteitem,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_save_preferred_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_bearer_settings
 * DESCRIPTION
 *  Entry bearer settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_bearer_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    S32 hiliteitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_BEARER_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_bearer_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_BEARER_SETTINGS);
    nNumofItem = GetNumOfChild(SETUP_MENU_PREFEREDBEARER_MENUID);
    GetSequenceStringIds(SETUP_MENU_PREFEREDBEARER_MENUID, nStrItemList);
    SetParentHandler(SETUP_MENU_PREFEREDBEARER_MENUID);
    if (guiBuffer != NULL)
    {
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        hiliteitem = (S32) preferBearer;
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_ID_MSG_BEARER_SETTINGS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_BEARER_SETTINGS);

    ShowCategory11Screen(
        STR_PREFEREDBEARER_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_save_bearer_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_voice_mail_server
 * DESCRIPTION
 *  Free voice mail data before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_voice_mail_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeVoiceMailData();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_voice_mail_server
 * DESCRIPTION
 *  Free voice mail data before go to idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_end_key_from_voice_mail_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!isInCall())
    {
        FreeVoiceMailData();
    }
    ExecCurrEndKeyDownHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_voice_mail_server
 * DESCRIPTION
 *  Before entry voice mail server list, get mailbox address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_voice_mail_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeVoiceMailData();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_VOICE_MAIL_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
	if (g_msg_cntx.is_voicemail_from_idle == FALSE)
#endif
	{
    	mmi_msg_get_mailbox_list_req();
	}
#ifdef __MMI_DUAL_SIM_MASTER__
	else
	{
		mmi_msg_dial_mailbox_req();
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_voice_mail_server
 * DESCRIPTION
 *  Entry voice mail server list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_voice_mail_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_VOICE_MAIL_LIST, mmi_msg_exit_generic, mmi_msg_entry_voice_mail_server, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_VOICE_MAIL_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = (g_msg_cntx.currHiliteIndex < mmi_msg_mailbox_num) ? g_msg_cntx.currHiliteIndex : 0;
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_ID_MSG_VOICE_MAIL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_LIST);

    GetCurrEndKeyDownHandler();
    ShowCategory184Screen(
        STR_VMAIL_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32)mmi_msg_mailbox_num,
        mmi_msg_voice_mail_server_get_item,
        mmi_msg_voice_mail_server_get_hint,
        hiliteitem,
        guiBuffer);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_msg_dial_mailbox_address,KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_msg_dial_mailbox_address, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetLeftSoftkeyFunction(mmi_msg_entry_voice_mail_server_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_voice_mail_server_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_msg_go_back_from_voice_mail_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_back_from_voice_mail_server, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_end_key_from_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_voice_mail_server_get_item
 * DESCRIPTION
 *  Display voice mail server item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Current item index
 *  d(?)                [IN/OUT]        Current item mask
 *  c(?)                [IN/OUT]        Current item icon
 *  b(?)                [IN/OUT]        Current item string
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_voice_mail_server_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= MAX_MAILBOX_PS_SUPPORT))
    {
        return FALSE;
    }
    if (mmi_ucs2strlen((S8*) pMailBoxName[item_index]) != 0)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) pMailBoxName[item_index]);
    }
    else if (mmi_ucs2strlen((S8*) pMailBoxNumber[item_index]) != 0)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) pMailBoxNumber[item_index]);
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString((U16) STR_GLOBAL_EMPTY_LIST));
    }
    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_voice_mail_server_get_hint
 * DESCRIPTION
 *  Display voice mail server hint
 * PARAMETERS
 *  item_index      [IN]            
 *  hint_array      [?]             
 *  a(?)            [IN]            Current item index
 *  b(?)            [IN/OUT]        Current item hint
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
S32 mmi_msg_voice_mail_server_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2strlen((S8*) pMailBoxName[item_index]) != 0)
        && (mmi_ucs2strlen((S8*) pMailBoxNumber[item_index]) != 0))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) pMailBoxNumber[item_index]);
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_voice_mail_server_option
 * DESCRIPTION
 *  Entry voice mail server option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_voice_mail_server_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_VOICE_MAIL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_voice_mail_server_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsMoMtGuiInterface.c] mmi_msg_entry_option_other -------*\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_VOICE_MAIL_OPTION);

    numItems = GetNumOfChild(MENU_ITEM_VOICE_MAIL_OPTION);
    GetSequenceStringIds(MENU_ITEM_VOICE_MAIL_OPTION, nStrItemList);
    SetParentHandler(MENU_ITEM_VOICE_MAIL_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_VOICE_MAIL_OPTION);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_OPTION);

    GetCurrEndKeyDownHandler();
    ShowCategory52Screen(
        STR_VOICE_MAIL_OPTION_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetKeyHandler(mmi_msg_end_key_from_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_mailbox_inline_item
 * DESCRIPTION
 *  Entry voice mail server edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_mailbox_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mailboxNameLength = psMailboxEditInfo.malboxNameLength + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* make sure the max length of name no more than MAX_PROFILE_NAME_LEN */
    if (mailboxNameLength > MAX_PROFILE_NAME_LEN + 1)
    {
        mailboxNameLength = MAX_PROFILE_NAME_LEN + 1;
    }
    
    /* say activate these items */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    /* profile name */
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[0],
        STR_VOICE_MAIL_NAME,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        (PU8) psMailboxEditInfo.mailboxName,
        /* MAX_PROFILE_NAME_LEN */(S32) mailboxNameLength,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_GSM_EXTENDED_HANDLING);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[0], mmi_msg_inline_generic_custom_function);
    /* service center */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) psMailboxEditInfo.mailboxAddress,
        MAX_DIGITS_SMS,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[1]);
    /* validity period */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_voice_mail_server_edit_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_voice_mail_server_edit_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(profileEditStrings[index]));
    draw_title();

    /* voice server name */
    if (index == 0)
    {
        /* The length of voice server name is zero. */
        if (psMailboxEditInfo.malboxNameLength == 0)
        {
            ChangeLeftSoftkey(0, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_voice_mail_server_edit
 * DESCRIPTION
 *  Exit profile edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_voice_mail_server_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsSettingsGuiInterface.c] ExitScrProfileSetting -------*\n");
    if (GetUCS2Flag((PS8) psMailboxEditInfo.mailboxName))
    {
        psMailboxEditInfo.mailboxNameDcs = PHB_UCS2;
    }
    else
    {
        psMailboxEditInfo.mailboxNameDcs = PHB_ASCII;
    }
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_VOICE_MAIL_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_ID_MSG_VOICE_MAIL_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_voice_mail_server_edit;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) currHistory.inputBuffer);   /* added for inline edit history */
    AddNHistory(currHistory, inputBufferSize);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_voice_mail_server_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_voice_mail_server_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;

    U8 numOfItems = MAX_MAILBOX_PS_SUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_VOICE_MAIL_EDIT, mmi_msg_exit_voice_mail_server_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_VOICE_MAIL_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_MSG_VOICE_MAIL_EDIT, &inputBufferSize);

    GetCurrEndKeyDownHandler();
    RegisterHighlightHandler(mmi_msg_voice_mail_server_edit_highlight_handler);
    profileEditStrings[0] = STR_VOICE_MAIL_NAME;
    profileEditStrings[1] = STR_VOICE_MAIL_NUM;

	if (is_edit_voicemail_num_from_idle == FALSE)
	{
	    psMailboxEditInfo.mailboxIndex = g_msg_cntx.currHiliteIndex;
	    psMailboxEditInfo.mailboxNameDcs = psMailBoxDCS[psMailboxEditInfo.mailboxIndex];
	}
    mmi_ucs2cpy((S8*) psMailboxEditInfo.mailboxName, (S8*) pMailBoxName[psMailboxEditInfo.mailboxIndex]);
    mmi_ucs2cpy((S8*) psMailboxEditInfo.mailboxAddress, (S8*) pMailBoxNumber[psMailboxEditInfo.mailboxIndex]);
    mmi_msg_set_mailbox_inline_item();
    if (guiBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, numOfItems, inputBuffer);
    }

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_VOICE_MAIL_EDIT);
    SetMessagesCurrScrnID(SCR_ID_MSG_VOICE_MAIL_EDIT);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_mailbox_inline_item_req, Messages2GoBackHistory);

    ShowCategory57Screen(
        STR_VMAIL_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        profileEditIcons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    SetKeyHandler(mmi_msg_end_key_from_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_msg_settings
 * DESCRIPTION
 *  Handle highlight on message settings menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_msg_settings(void)
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
        mmi_msg_pre_entry_msg_settings,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_profile_settings
 * DESCRIPTION
 *  Handle highlight on profile settings menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_profile_settings(void)
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
        mmi_msg_get_profile_list_req,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_common_settings
 * DESCRIPTION
 *  Handle highlight on common settings menu item
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_msg_highlight_common_settings(void)
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
        mmi_msg_get_common_settings_req,
        GoBackHistory);

}

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_memory_status
 * DESCRIPTION
 *  Handle highlight on memory status menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_memory_status(void)
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
        mmi_msg_get_memory_status_req,
        GoBackHistory);

}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_preferred_storage
 * DESCRIPTION
 *  Handle highlight on preferred storage menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_preferred_storage(void)
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
        mmi_msg_get_preferred_memory_status_req,
        GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_hint_preferred_storage
 * DESCRIPTION
 *  Handle hint on preferred storage
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_hint_preferred_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 StorageStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memStatus.prefStorage == 0)
    {
        StorageStr = (PU8) GetString((U16) STR_SIM_STORAGE_MENUENTRY);
    }
    else
    {
        StorageStr = (PU8) GetString((U16) STR_ME_STORAGE_MENUENTRY);
    }
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) StorageStr);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_bearer_settings
 * DESCRIPTION
 *  Handle highlight on bearer settings menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_bearer_settings(void)
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
        mmi_msg_entry_bearer_settings,
        GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_hint_bearer_settings
 * DESCRIPTION
 *  Handle hint on bearer settings menu item
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_hint_bearer_settings(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 BearerStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (preferBearer)
    {
        case MMI_SMS_PREFER_GPRS:
            BearerStr = (PU8) GetString((U16) STR_PREFER_GPRS_BEARER_MENUENTRY);
            break;
        case MMI_SMS_PREFER_GSM:
            BearerStr = (PU8) GetString((U16) STR_PREFER_GSM_BEARER_MENUENTRY);
            break;
        case MMI_SMS_GSM_ONLY:
            BearerStr = (PU8) GetString((U16) STR_GSM_BEARER_MENUENTRY);
            break;
        default:
            BearerStr = (PU8) GetString((U16) STR_PREFER_GPRS_BEARER_MENUENTRY);
            break;
    }
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) BearerStr);
}

#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_voice_mail_server_edit
 * DESCRIPTION
 *  Handle highlight on voice mail server edit menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_voice_mail_server_edit(void)
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
        mmi_msg_entry_voice_mail_server_edit,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_voice_mail_server_dial
 * DESCRIPTION
 *  Handle highlight on voice mail server dial menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_voice_mail_server_dial(void)
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
        mmi_msg_highlight_dial_mailbox_address,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ConvertL4NumberStructToDisplay
 * DESCRIPTION
 *  Convert L4 number structure to display
 * PARAMETERS
 *  number      [?]         
 *  length      [IN]        
 *  type        [IN]        
 *  a(?)        [IN]        Number from L4
 *  c(?)        [IN]        Type from L4
 *  b(?)        [IN]        Length from L4
 * RETURNS
 *  converted number
 *****************************************************************************/
U8 *ConvertL4NumberStructToDisplay(U8 *number, U8 length, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData;
    U8 typeInternational = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[MessagesMiscell.c] ConvertL4NumberStructToDisplay -------*\n");
    if (length)
    {
        if (type == CSMCC_INTERNATIONAL_ADDR)
        {
            typeInternational = 1;
        }
        else
        {
            typeInternational = 0;
        }

        convertedData = OslMalloc(((length + typeInternational) * ENCODING_LENGTH) + ENCODING_LENGTH);
    #ifdef __UCS2_ENCODING
        if (typeInternational)
        {
            mmi_asc_to_ucs2((PS8) convertedData, (PS8) "+");
        }
        mmi_asc_n_to_ucs2((PS8) convertedData + (typeInternational * ENCODING_LENGTH), (PS8) number, length);
        memset((void*)&convertedData[(length + typeInternational) * ENCODING_LENGTH], 0, ENCODING_LENGTH);
    #else /* __UCS2_ENCODING */ 
        if (typeInternational)
        {
            mmi_ucs2cpy((PS8) convertedData, (PS8) "+");
        }
        mmi_ucs2cpy((PS8) convertedData + typeInternational, (PS8) number, length);
        convertedData[length + typeInternational] = '\0';
    #endif /* __UCS2_ENCODING */ 
        return convertedData;
    }
    else
    {
        convertedData = OslMalloc(ENCODING_LENGTH);
        memset((void*)convertedData, 0, ENCODING_LENGTH);
        return convertedData;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DialVoiceMail
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialVoiceMail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_remove_dialer_screen_exit_handler();
#ifndef __MMI_DUAL_SIM_MASTER__
    FreeVoiceMailData();
    mmi_msg_dial_mailbox_req();
#else
	if (GetNumOfChild_Ext(SMS_INBOX_OPT_FORWARD_MENUID) == 2)
	{
		g_msg_cntx.is_voicemail_from_idle = TRUE;
		mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_VOICE_MAIL, NULL, DialVoiceMail, 
                         MENU_MTPNP_DM_VMAIL, STR_VMAIL_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
	}
	else if (!mmi_frm_test_menu_item_hide(MESSAGES_MENU_VMAIL_MENUID))
	{
		FreeVoiceMailData();
		mmi_msg_dial_mailbox_req();
	}
	else if (!mmi_frm_test_menu_item_hide(MENU_MTPNP_VMAIL))
	{
		mmi_msg_dial_card2_mailbox_req();
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  FreeVoiceMailData
 * DESCRIPTION
 *  Free voice mail server data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeVoiceMailData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "\n [VoiceMail]@@@@@ FreeVoiceMailData -  @@@@@");
    for (i = 0; i < MAX_MAILBOX_PS_SUPPORT; i++)
    {
        if (pMailBoxName[i])
        {
            OslMfree(pMailBoxName[i]);
            pMailBoxName[i] = NULL;
        }
        if (pMailBoxNumber[i])
        {
            OslMfree(pMailBoxNumber[i]);
            pMailBoxNumber[i] = NULL;
        }
    }

	is_edit_voicemail_num_from_idle = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DeInitVoiceMailApp
 * DESCRIPTION
 *  Deinit voice mail application (free voice mail server data)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitVoiceMailApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeVoiceMailData();
}
	
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_set_voicemail_number_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_set_voicemail_number_confirm(U8 mailboxIndex, U8 mailboxNameDcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	psMailboxEditInfo.mailboxIndex = mailboxIndex;
	psMailboxEditInfo.mailboxNameDcs = mailboxNameDcs;
	
	mmi_msg_set_confirm_screen(STR_SMS_SET_VOICEMAIL_QUERY_ID, mmi_msg_pre_entry_edit_voicemail_num_from_idle, GoBackHistory);
    mmi_msg_entry_confirm_generic();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_edit_voicemail_num_from_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_edit_voicemail_num_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_edit_voicemail_num_from_idle = TRUE;
	mmi_msg_entry_voice_mail_server_edit();
}

#endif /* __MOD_SMSAL__ */ 

