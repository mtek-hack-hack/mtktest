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
 * JMMSUMHandling.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all the function calls for handling UM requests.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JMMSUMHANDLE_C
#define _MMI_JMMSUMHANDLE_C


#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)

#ifdef __MMI_UNIFIED_MESSAGE__
#include "time.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "MessagesResourceData.h"

#include "wap_ps_struct.h"
#include "wapadp.h"

#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"

#include "jdi_communicator.h"
#include "jdi_BrowserDatatype.h"

#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
// #include "JBrowserStartup.h"

/* PMT DARA  PROFILE HANDLER 020106 */
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"


#include "JMMSCoreAPI.h"
#include "JMMSStoreHandling.h"
#include "JMMSMainMMS.h"
#include "JMMSStructs.h"
#include "JMMSConfig.h"
#include "JMMSExdcl.h"
#include "JMMSUMHandling.h"
#include "JMMSInbox.h"
#include "JMMSOutbox.h"
#include "JMMSDrafts.h"
#include "JMMSSent.h"
#include "JMMSTemplates.h"
#include "JPushInboxCommonAPIs.h"
#include "JPushInboxUM.h"
#include "JPushInboxCommonUI.h"
#include "wgui_status_icons.h"
#include "jdi_MMSErr.h"
#include "JMMSResDef.h"
#include "UnifiedMessageProt.h"
#include "DateTimeGprot.h"
#include "app_datetime.h"
#include "PhoneBookGprot.h"

#include "JMMSProtocols.h"      /* compiler warning removal */
#include "JMMSGprot.h"
#include "JMMSView.h"

extern void *g_um_jmms_rsp_struct = NULL;

extern void mmi_jmms_set_folder_message_size(S32 number);
void (*mmi_um_jmms_folder_list_callback) (void) = NULL;


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_set_folder_list_callback_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_set_folder_list_callback_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_folder_list_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_dummy_folder_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_dummy_folder_list_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy call */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_msgs_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_type_list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_delete_all_msgs_list(UmMsgBoxType folder_type_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U8 msgs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* folder_type = UM_MSG_BOX_TYPE_INBOX | UM_MSG_BOX_TYPE_UNSENT | UM_MSG_BOX_TYPE_SENT | UM_MSG_BOX_TYPE_DRAFT; */

    if (folder_type_list & UM_MSG_BOX_TYPE_INBOX)
    {
        if (mmi_jmms_is_immediate_retrival_underway())
        {
            return -1;
        }
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &msgs);
        if (ret_code == JC_OK && msgs != 0)
        {
            ret_code = mmi_jmms_delete_all_message(MMI_JMMS_INBOX);
            /* reset all msgs status as unread */
            mmi_jmms_delete_all_msgs_status();

            if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
            {
                mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
            }
            if (ret_code != JC_OK)
            {
                return ret_code;
            }
        }
        if (ret_code != JC_OK)
        {
            return ret_code;
        }
    }

    if (folder_type_list & UM_MSG_BOX_TYPE_UNSENT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &msgs);
        if (ret_code == JC_OK && msgs != 0)
        {
            ret_code = mmi_jmms_delete_all_message(MMI_JMMS_OUTBOX);
            if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
            {
                mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
            }
        }
        if (ret_code != JC_OK)
        {
            return ret_code;
        }
    }

    if (folder_type_list & UM_MSG_BOX_TYPE_SENT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &msgs);
        if (ret_code == JC_OK && msgs != 0)
        {
            ret_code = mmi_jmms_delete_all_message(MMI_JMMS_SENT);
            if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
            {
                mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
            }
        }
        if (ret_code != JC_OK)
        {
            return ret_code;
        }
    }

    if (folder_type_list & UM_MSG_BOX_TYPE_DRAFT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &msgs);
        if (ret_code == JC_OK && msgs != 0)
        {
            ret_code = mmi_jmms_delete_all_message(MMI_JMMS_DRAFTS);
            if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
            {
                mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
            }
        }
        if (ret_code != JC_OK)
        {
            return ret_code;
        }
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jataayu_entry_message_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jataayu_entry_message_mms(UmMsgBoxType msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->curr_scr_hilited_index = msg_index;
    mmi_um_jmms_free_msgs_list();
    switch (msg_box_type)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
            g_jmms_context->store_context->current_folder_name = E_JMMS_INBOX;
            g_jmms_context->store_context->jmms_start_index = 1;
            /* set the open msg status- for At delete */
            g_jmms_context->msg_open_status[0] = E_JMMS_INBOX;
            g_jmms_context->msg_open_status[1] =
                (U32) mmi_jmms_get_message_id(
                        MMI_JMMS_INBOX,
                        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
            g_jmms_context->last_scr_id = 0;    /* To fix LSK option issue for Notification, RReport,DReport & JSR Mesages */
            mmi_jmms_inbox_view();
            break;

        case UM_MSG_BOX_TYPE_UNSENT:
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
            g_jmms_context->store_context->current_folder_name = E_JMMS_OUTBOX;
            g_jmms_context->store_context->jmms_start_index = 1;
            /* set the open msg status- for At delete */
            g_jmms_context->msg_open_status[0] = E_JMMS_OUTBOX;
            g_jmms_context->msg_open_status[1] =
                (U32) mmi_jmms_get_message_id(
                        MMI_JMMS_OUTBOX,
                        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
            mmi_jmms_outbox_view();

            break;

        case UM_MSG_BOX_TYPE_SENT:
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
            g_jmms_context->store_context->current_folder_name = E_JMMS_SENT;
            g_jmms_context->store_context->jmms_start_index = 1;
            /* set the open msg status- for At delete */
            g_jmms_context->msg_open_status[0] = E_JMMS_SENT;
            g_jmms_context->msg_open_status[1] =
                (U32) mmi_jmms_get_message_id(
                        MMI_JMMS_SENT,
                        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
            mmi_um_jmms_set_folder_list_callback_function(mmi_jmms_sent_view);
            mmi_jmms_sent_view();
            break;

        case UM_MSG_BOX_TYPE_DRAFT:
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
            g_jmms_context->store_context->current_folder_name = E_JMMS_DRAFTS;
            g_jmms_context->store_context->jmms_start_index = 1;
            /* set the open msg status- for At delete */
            g_jmms_context->msg_open_status[0] = E_JMMS_DRAFTS;
            g_jmms_context->msg_open_status[1] =
                (U32) mmi_jmms_get_message_id(
                        MMI_JMMS_DRAFTS,
                        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
            mmi_jmms_drafts_view();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_free_msgs_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_free_msgs_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_folder_msgs_list_struct *list_p;
    mmi_jmms_folder_msgs_list_struct *list1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
    {
        list_p = g_jmms_context->store_context->messages_list;
        while (list_p != NULL)
        {
            list1_p = list_p->next_p;
            if (list_p->um_msg_info_p != NULL &&
                list_p->um_msg_info_p->msg_index != g_jmms_context->curr_scr_hilited_index)
            {
                jdd_MemFree(list_p->um_msg_info_p);
                list_p->um_msg_info_p = NULL;
            }
            list_p = list1_p;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_create_new_mms_hint_for_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_info_rsp_p      [IN]        
 *  to_p                [IN]        
 *  cc_p                [IN]        
 *  bcc_p               [IN]        
 *  msg_counter         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_create_new_mms_hint_for_sent(
        mmi_um_msg_info_struct **mms_info_rsp_p,
        JC_CHAR *to_p,
        JC_CHAR *cc_p,
        JC_CHAR *bcc_p,
        S32 msg_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_p = NULL;
    S32 len = 0;
    S32 start_index = 0;
    MMI_BOOL is_email = MMI_FALSE;
    S32 len_to_copy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (to_p != NULL)
    {
        str_p = (S8*) (to_p);
        len = 0;
        start_index = 0;

        while (((*str_p) != ';') && ((*str_p) != '\0'))
        {
            if ((*str_p) == '@')
            {
                is_email = MMI_TRUE;
            }

            len++;
            str_p = str_p + ENCODING_LENGTH;

        }

        if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
        }
        else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
        }
        else
        {
            len_to_copy = len;
        }
        if (is_email == MMI_TRUE)
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_EMAIL_ADDRESS;
        }
        else
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_PHONE_NUMBER;
        }
        mmi_ucs2ncpy((S8*) (*mms_info_rsp_p)->address, (S8*) (to_p + start_index), len_to_copy);
        (*mms_info_rsp_p)->address_length = len_to_copy;
        return;

    }

    if (cc_p != NULL)
    {

        str_p = (S8*) (cc_p);
        len = 0;
        start_index = 0;
        is_email = MMI_FALSE;

        while (((*str_p) != ';') && ((*str_p) != '\0'))
        {
            len++;

            if ((*str_p) == '@')
            {
                is_email = MMI_TRUE;
            }

            str_p = str_p + ENCODING_LENGTH;
        }

        if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
        }
        else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
        }
        else
        {
            len_to_copy = len;
        }
        if (is_email == MMI_TRUE)
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_EMAIL_ADDRESS;
        }
        else
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_PHONE_NUMBER;
        }
        mmi_ucs2ncpy((S8*) (*mms_info_rsp_p)->address, (S8*) (cc_p + start_index), len_to_copy);
        (*mms_info_rsp_p)->address_length = len_to_copy;
        return;

    }

    /* /Make the BCc Addresses list */
    if (bcc_p != NULL)
    {
        str_p = (S8*) (bcc_p);
        len = 0;
        start_index = 0;
        is_email = MMI_FALSE;

        while (((*str_p) != ';') && ((*str_p) != '\0'))
        {
            len++;
            if ((*str_p) == '@')
            {
                is_email = MMI_TRUE;
            }
            str_p = str_p + ENCODING_LENGTH;
        }

        if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
        }
        else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
        }
        else
        {
            len_to_copy = len;
        }
        if (is_email == MMI_TRUE)
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_EMAIL_ADDRESS;
        }
        else
        {
            (*mms_info_rsp_p)->address_type = UM_ADDR_TYPE_PHONE_NUMBER;
        }
        mmi_ucs2ncpy((S8*) (*mms_info_rsp_p)->address, (S8*) (bcc_p + start_index), len_to_copy);
        (*mms_info_rsp_p)->address_length = len_to_copy;
        return;
    }
    (*mms_info_rsp_p)->address_length = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_add_mms_sub_for_list_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_info_rsp_p      [IN]        
 *  subject_p           [IN]        
 *  msg_counter         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_add_mms_sub_for_list_info(
        mmi_um_msg_info_struct **mms_info_rsp_p,
        JC_CHAR *subject_p,
        S32 msg_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len_to_copy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len_to_copy = mmi_ucs2strlen((S8*) (subject_p)) * ENCODING_LENGTH;
    if (len_to_copy > MMI_UM_MAX_SUBJECT_LEN)
    {
        len_to_copy = MMI_UM_MAX_SUBJECT_LEN;
    }
    mmi_ucs2ncpy((S8*) (*mms_info_rsp_p)->subject, (S8*) (subject_p), len_to_copy);
    (*mms_info_rsp_p)->subject_length = len_to_copy;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_add_mms_address_for_list_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_info_p      [IN]        
 *  from_p          [IN]        
 *  msg_counter     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_add_mms_address_for_list_info(mmi_um_msg_info_struct **mms_info_p, JC_CHAR *from_p, S32 msg_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_p = NULL;
    S32 len = 0;
    S32 start_index = 0;
    MMI_BOOL is_email = MMI_FALSE;
    S32 len_to_copy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (from_p != NULL)
    {
        str_p = (S8*) (from_p);
        len = 0;
        start_index = 0;

        while (((*str_p) != ';') && ((*str_p) != '\0'))
        {
            if ((*str_p) == '@')
            {
                is_email = MMI_TRUE;
            }

            len++;
            str_p = str_p + ENCODING_LENGTH;

        }

        if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
        }
        else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
        {
            len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
        }
        else
        {
            len_to_copy = len;
        }
        if (is_email == MMI_TRUE)
        {
            (*mms_info_p)->address_type = UM_ADDR_TYPE_EMAIL_ADDRESS;
        }
        else
        {
            (*mms_info_p)->address_type = UM_ADDR_TYPE_PHONE_NUMBER;
        }
        mmi_ucs2ncpy((S8*) (*mms_info_p)->address, (S8*) (from_p + start_index), len_to_copy);
        (*mms_info_p)->address_length = len_to_copy;
        return;

    }
    (*mms_info_p)->address_length = len_to_copy;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_at_delete_pre_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_at_delete_pre_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_open_status[0] = 0;
    g_jmms_context->msg_open_status[1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_store_update_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  ui_extra_bytes      [IN]        
 *  media_count         [IN]        
 *  ui_msg_index        [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_um_jmms_store_update_message(
            S8 *folder_name_p,
            JC_UINT32 ui_extra_bytes,
            U8 media_count,
            JC_UINT32 ui_msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        return ret_code;
    }

    if (media_count > 0)
    {
        ui_extra_bytes = ui_extra_bytes | 0x10000000;
        mmi_um_update_status_attachment(
            g_jmms_context->g_attachment_pending_list->index_to_parse,
            E_JMMS_ATTACHMENT_PRESENT);
    }
    else
    {
        ui_extra_bytes = ui_extra_bytes | 0x20000000;
        mmi_um_update_status_attachment(
            g_jmms_context->g_attachment_pending_list->index_to_parse,
            E_JMMS_ATTACHMENT_NOT_PRESENT);
    }
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

    ret_code = mmi_jmms_store_update_message_extrabyte(folder_name_p, ui_msg_index, ui_extra_bytes);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_attacment_pending_status_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_attacment_pending_status_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_um_jmms_attachment_present_list_struct *temp_pending_list_p = g_jmms_context->g_attachment_pending_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_pending_list_p != NULL)
    {
        g_jmms_context->g_attachment_pending_list = g_jmms_context->g_attachment_pending_list->next_p;
        jdd_MemFree(temp_pending_list_p);
        temp_pending_list_p = g_jmms_context->g_attachment_pending_list;
    }
    temp_pending_list_p = NULL;
    g_jmms_context->g_attachment_pending_list = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_add_new_node_attachment_pending_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  temp_pending_list_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_add_new_node_attachment_pending_list(
        mmi_jmms_um_jmms_attachment_present_list_struct *temp_pending_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_um_jmms_attachment_present_list_struct *pending_list_p = g_jmms_context->g_attachment_pending_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pending_list_p == NULL)
    {
        g_jmms_context->g_attachment_pending_list = temp_pending_list_p;
    }
    else
    {
        while (pending_list_p->next_p != NULL)
        {
            pending_list_p = pending_list_p->next_p;
        }
        pending_list_p->next_p = temp_pending_list_p;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_parse_attachment_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_parse_attachment_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 media_count = 0;
    U32 ui_extra_bytes = 0;
    mmi_um_get_list_rsp_struct *mms_info_rsp_p = NULL;
    mmi_jmms_um_jmms_attachment_present_list_struct *temp_pending_list_p = NULL;
    U8 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_info_rsp_p = (mmi_um_get_list_rsp_struct*) g_um_jmms_rsp_struct;

    temp_pending_list_p = g_jmms_context->g_attachment_pending_list;

    if (temp_pending_list_p != NULL && ret_code == JC_OK)
    {
        mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &media_count, E_TRUE);
        switch (mms_info_rsp_p->msg_box_type)
        {
            case UM_MSG_BOX_TYPE_INBOX:
                mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number);
                ui_extra_bytes =
                    (U32) mmi_jmms_get_message_id(MMI_JMMS_INBOX, (U16) (number - temp_pending_list_p->index_to_parse));
                ret_code = mmi_um_jmms_store_update_message(
                            MMI_JMMS_INBOX,
                            ui_extra_bytes,
                            media_count,
                            (number - temp_pending_list_p->index_to_parse));
                break;
            case UM_MSG_BOX_TYPE_UNSENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &number);
                ui_extra_bytes =
                    (U32) mmi_jmms_get_message_id(
                            MMI_JMMS_OUTBOX,
                            (U16) (number - temp_pending_list_p->index_to_parse));
                ret_code = mmi_um_jmms_store_update_message(
                            MMI_JMMS_OUTBOX,
                            ui_extra_bytes,
                            media_count,
                            (number - temp_pending_list_p->index_to_parse));
                break;
            case UM_MSG_BOX_TYPE_SENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &number);
                ui_extra_bytes =
                    (U32) mmi_jmms_get_message_id(MMI_JMMS_SENT, (U16) (number - temp_pending_list_p->index_to_parse));
                ret_code = mmi_um_jmms_store_update_message(
                            MMI_JMMS_SENT,
                            ui_extra_bytes,
                            media_count,
                            (number - temp_pending_list_p->index_to_parse));
                break;
            case UM_MSG_BOX_TYPE_DRAFT:
                mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &number);
                ui_extra_bytes =
                    (U32) mmi_jmms_get_message_id(
                            MMI_JMMS_DRAFTS,
                            (U16) (number - temp_pending_list_p->index_to_parse));
                ret_code = mmi_um_jmms_store_update_message(
                            MMI_JMMS_DRAFTS,
                            ui_extra_bytes,
                            media_count,
                            (number - temp_pending_list_p->index_to_parse));
        }
    }
    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
            g_jmms_context->parse_content_p->pFileName = NULL;
        }
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }

    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

    if (temp_pending_list_p != NULL)
    {
        g_jmms_context->g_attachment_pending_list = g_jmms_context->g_attachment_pending_list->next_p;
        jdd_MemFree(temp_pending_list_p);
        temp_pending_list_p = NULL;
        if (g_jmms_context->g_attachment_pending_list != NULL)
        {
            mmi_um_jmms_parse_mms_for_attachment();
        }
        else
        {
            mmi_um_jmms_get_message_list_rsp();
        }
    }
    else
    {
        mmi_um_jmms_get_message_list_rsp();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_update_status_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_index               [IN]        
 *  attachment_status       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_update_status_attachment(U16 msg_index, mmi_jmms_mms_attachment_status_enum attachment_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_folder_msgs_list_struct *msg_list_p = g_jmms_context->store_context->messages_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (msg_list_p != NULL)
    {
        if (msg_list_p->um_msg_info_p->msg_index == msg_index)
        {
            msg_list_p->attachment_status = attachment_status;
            return;
        }
        msg_list_p = msg_list_p->next_p;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_fill_list_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_info_rsp_p      [OUT]       
 *  msg_info_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_fill_list_info(
        mmi_um_get_msg_info_rsp_struct *mms_info_rsp_p,
        mmi_um_get_msg_info_req_struct *msg_info_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_counter = 0;
    mmi_jmms_folder_msgs_list_struct *msg_list_p = g_jmms_context->store_context->messages_list;
    S8 *name_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (msg_list_p != NULL && msg_list_p->um_msg_info_p->msg_index != mms_info_rsp_p->start_entry)
    {
        msg_list_p = msg_list_p->next_p;
    }

    for (msg_counter = 0; (msg_list_p != NULL && msg_counter <= mms_info_rsp_p->msg_number); msg_counter++)
    {
        mms_info_rsp_p->msg_info[msg_counter].timestamp = msg_list_p->um_msg_info_p->timestamp;
        switch (msg_list_p->attachment_status)
        {
            case E_JMMS_ATTACHMENT_PRESENT:
                mms_info_rsp_p->msg_info[msg_counter].icon_id = IMG_ID_JMMS_MMS_WITH_ATTACHMENT;
                break;
            case E_JMMS_ATTACHMENT_NOT_PRESENT:
                mms_info_rsp_p->msg_info[msg_counter].icon_id = IMG_ID_JMMS_MMS_WITHOUT_ATTACHMENT;
                break;
            default:
                mms_info_rsp_p->msg_info[msg_counter].icon_id = IMG_ID_JMMS_MMS_WITHOUT_ATTACHMENT;
                break;
                break;
        }
        mms_info_rsp_p->msg_info[msg_counter].msg_index = msg_list_p->um_msg_info_p->msg_index;
        mmi_ucs2cpy((S8*) mms_info_rsp_p->msg_info[msg_counter].address, (S8*) msg_list_p->um_msg_info_p->address);
        mms_info_rsp_p->msg_info[msg_counter].address_length = msg_list_p->um_msg_info_p->address_length;
        mms_info_rsp_p->msg_info[msg_counter].address_type = msg_list_p->um_msg_info_p->address_type;
        mmi_ucs2cpy((S8*) mms_info_rsp_p->msg_info[msg_counter].subject, (S8*) msg_list_p->um_msg_info_p->subject);
        mms_info_rsp_p->msg_info[msg_counter].subject_length = msg_list_p->um_msg_info_p->subject_length;
        if (mms_info_rsp_p->msg_info[msg_counter].address_type == UM_ADDR_TYPE_PHONE_NUMBER)
        {
            name_p = (S8*) lookUpNumber((PS8) mms_info_rsp_p->msg_info[msg_counter].address);
            if (mmi_ucs2strlen(name_p))
            {
                mmi_ucs2ncpy((S8*) mms_info_rsp_p->msg_info[msg_counter].address, (S8*) name_p, mmi_ucs2strlen(name_p));
                mms_info_rsp_p->msg_info[msg_counter].address_length = mmi_ucs2strlen(name_p);
            }
        }
        name_p = NULL;
        msg_list_p = msg_list_p->next_p;
    }   /* End of For Loop */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_parse_mms_for_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_parse_mms_for_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U8 number = 0;
    mmi_jmms_um_jmms_attachment_present_list_struct *temp_pending_list_p = NULL;
    mmi_um_get_list_rsp_struct *mms_info_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_info_rsp_p = (mmi_um_get_list_rsp_struct*) g_um_jmms_rsp_struct;
    temp_pending_list_p = g_jmms_context->g_attachment_pending_list;

    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }
    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
    if (temp_pending_list_p != NULL)
    {

        switch (mms_info_rsp_p->msg_box_type)
        {
            case UM_MSG_BOX_TYPE_INBOX:
                mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number);
                ret_code = mmi_jmms_get_message(
                            MMI_JMMS_INBOX,
                            g_jmms_context->parse_content_p,
                            number - temp_pending_list_p->index_to_parse);
                break;
            case UM_MSG_BOX_TYPE_UNSENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &number);
                ret_code = mmi_jmms_get_message(
                            MMI_JMMS_OUTBOX,
                            g_jmms_context->parse_content_p,
                            number - temp_pending_list_p->index_to_parse);
                break;
            case UM_MSG_BOX_TYPE_SENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &number);
                ret_code = mmi_jmms_get_message(
                            MMI_JMMS_SENT,
                            g_jmms_context->parse_content_p,
                            number - temp_pending_list_p->index_to_parse);
                break;
            case UM_MSG_BOX_TYPE_DRAFT:
                mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &number);
                ret_code = mmi_jmms_get_message(
                            MMI_JMMS_DRAFTS,
                            g_jmms_context->parse_content_p,
                            number - temp_pending_list_p->index_to_parse);
                break;
        }

        if (ret_code != JC_OK)
        {
            mmi_um_jmms_parse_attachment_async_callback(ret_code);
            return;
        }

        ret_code = mmi_jmms_jdi_parse_msg_buffer(
                    &g_jmms_context->msg_handle,
                    g_jmms_context->parse_content_p,
                    E_TYPE_MMS,
                    E_TRUE);

        if (ret_code == JC_ERR_MMS_PARSE_PENDING)
        {
            mmi_jmms_parse_continue_start_timer(
                g_jmms_context->msg_handle,
                mmi_um_jmms_parse_attachment_async_callback,
                mmi_jmms_only_abort_parsing_progress);
            return;
        }
    }
    mmi_um_jmms_parse_attachment_async_callback(ret_code);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_fill_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_list_rsp_p      [OUT]       
 *  msg_list_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_fill_list(mmi_um_get_list_rsp_struct *mms_list_rsp_p, mmi_um_get_list_req_struct *msg_list_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->store_context->jmms_start_index = mms_list_rsp_p->start_entry + 1;
    switch (mms_list_rsp_p->msg_box_type)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            ret_code = mmi_jmms_get_folder_msg_list(
                        &(g_jmms_context->store_context->messages_list),
                        MMI_JMMS_INBOX,
                        (U8) mms_list_rsp_p->msg_number);
            break;

        case UM_MSG_BOX_TYPE_UNSENT:
            ret_code = mmi_jmms_get_folder_msg_list(
                        &(g_jmms_context->store_context->messages_list),
                        MMI_JMMS_OUTBOX,
                        (U8) mms_list_rsp_p->msg_number);
            break;

        case UM_MSG_BOX_TYPE_SENT:
            ret_code = mmi_jmms_get_folder_msg_list(
                        &(g_jmms_context->store_context->messages_list),
                        MMI_JMMS_SENT,
                        (U8) mms_list_rsp_p->msg_number);
            break;

        case UM_MSG_BOX_TYPE_DRAFT:
            ret_code = mmi_jmms_get_folder_msg_list(
                        &(g_jmms_context->store_context->messages_list),
                        MMI_JMMS_DRAFTS,
                        (U8) mms_list_rsp_p->msg_number);
            break;
    }
    if (ret_code != JC_OK || g_jmms_context->store_context->messages_list == NULL)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_generate_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_list_rsp_p      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_um_jmms_generate_list(mmi_um_get_list_rsp_struct *mms_list_rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    S32 msg_counter = 0;
    mmi_jmms_folder_msgs_list_struct *msg_list_p = g_jmms_context->store_context->messages_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_counter = 0;
    if (msg_list_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }
    while (msg_list_p != NULL)
    {
        mms_list_rsp_p->list_info[msg_counter].timestamp = msg_list_p->um_msg_info_p->timestamp;
        mms_list_rsp_p->list_info[msg_counter].msg_index = msg_list_p->um_msg_info_p->msg_index;
        msg_counter++;
        msg_list_p = msg_list_p->next_p;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
    switch (g_jmms_context->store_context->current_folder_name)
    {
        case E_JMMS_INBOX:
            HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
            DeleteUptoScrID(SCR_ID_UM_INBOX);
            mmi_um_delete_highlight_folder(UM_MSG_BOX_TYPE_INBOX);
            break;

        case E_JMMS_OUTBOX:
            HistoryReplace(SCR_ID_UM_UNSENT, SCR_ID_UM_UNSENT, mmi_um_jmms_pre_entry_outbox);
            DeleteUptoScrID(SCR_ID_UM_UNSENT);
            mmi_um_delete_highlight_folder(UM_MSG_BOX_TYPE_UNSENT);
            break;

        case E_JMMS_SENT:
            HistoryReplace(SCR_ID_UM_SENT, SCR_ID_UM_SENT, mmi_um_jmms_pre_entry_sent);
            DeleteUptoScrID(SCR_ID_UM_SENT);
            mmi_um_delete_highlight_folder(UM_MSG_BOX_TYPE_SENT);
            break;

        case E_JMMS_DRAFTS:
            HistoryReplace(SCR_ID_UM_DRAFT, SCR_ID_UM_DRAFT, mmi_um_jmms_pre_entry_draft);
            DeleteUptoScrID(SCR_ID_UM_DRAFT);
            mmi_um_delete_highlight_folder(UM_MSG_BOX_TYPE_DRAFT);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_push_message_count_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_push_message_count_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_get_msg_num_rsp_struct *mms_count_rsp_p;
    U8 total_num_unread_messages = 0;
    U8 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    mms_count_rsp_p = (mmi_um_get_msg_num_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_msg_num_rsp_struct));
    mms_count_rsp_p->result = KAL_TRUE;
    mms_count_rsp_p->msg_type = UM_MSG_TYPE_MMS;
    if (jmms_is_ready_with_store())
    {
        mmi_jmms_get_number_of_unread_messages_in_inbox(&total_num_unread_messages);    /* mms_count_rsp_p->inbox_unread_msg_number = 0; */
        mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number);
        mms_count_rsp_p->inbox_unread_msg_number = total_num_unread_messages;
        mms_count_rsp_p->inbox_read_msg_number = number - total_num_unread_messages;
        mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &number);
        mms_count_rsp_p->unsent_msg_number = number;
        mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &number);
        mms_count_rsp_p->sent_msg_number = number;
        mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &number);
        mms_count_rsp_p->draft_msg_number = number;
        if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
        {
            mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
        }
    }
    else
    {
        mms_count_rsp_p->inbox_unread_msg_number = 0;
        mms_count_rsp_p->inbox_read_msg_number = 0;
        mms_count_rsp_p->unsent_msg_number = 0;
        mms_count_rsp_p->draft_msg_number = 0;
        mms_count_rsp_p->sent_msg_number = 0;
    }
    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_GET_MSG_NUM_RSP;
    message.oslDataPtr = (oslParaType*) mms_count_rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_message_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_message_list_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_get_list_rsp_struct *mms_list_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_list_rsp_p = (mmi_um_get_list_rsp_struct*) g_um_jmms_rsp_struct;
    g_um_jmms_rsp_struct = NULL;
    mms_list_rsp_p->result = KAL_TRUE;
    mmi_um_jmms_generate_list(mms_list_rsp_p);
    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_GET_LIST_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_list_rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_mms_message_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list_req_p      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_mms_message_list_req(mmi_um_get_list_req_struct *msg_list_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_rsp_struct *mms_list_rsp_p;
    U8 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    if (jmms_is_ready_with_store())
    {
        if (g_um_jmms_rsp_struct != NULL)
        {
            OslFreeDataPtr((void*)g_um_jmms_rsp_struct);
            g_um_jmms_rsp_struct = NULL;
        }
        mms_list_rsp_p = (mmi_um_get_list_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_list_rsp_struct));
        switch (msg_list_req_p->msg_box_type)
        {
            case UM_MSG_BOX_TYPE_INBOX:
                mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number);
                break;

            case UM_MSG_BOX_TYPE_UNSENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &number);
                break;

            case UM_MSG_BOX_TYPE_SENT:
                mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &number);
                break;

            case UM_MSG_BOX_TYPE_DRAFT:
                mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &number);
                break;

        }

        /* memset(mms_list_rsp_p, 0, sizeof(mmi_um_get_list_rsp_struct)); */

        mms_list_rsp_p->msg_type = UM_MSG_TYPE_MMS;
        mms_list_rsp_p->msg_box_type = msg_list_req_p->msg_box_type;
        mms_list_rsp_p->start_entry = msg_list_req_p->start_entry;

        if (mms_list_rsp_p->start_entry + MMI_UM_MAX_GET_LIST_MSG_NUMBER < number)
        {
            mms_list_rsp_p->msg_number = MMI_UM_MAX_GET_LIST_MSG_NUMBER;
            mms_list_rsp_p->more = TRUE;
        }
        else
        {
            mms_list_rsp_p->msg_number = number - mms_list_rsp_p->start_entry;
            mms_list_rsp_p->more = FALSE;
            g_jmms_context->store_context->num_msg_in_curr_folder = number;
        }

        g_um_jmms_rsp_struct = (void*)mms_list_rsp_p;
        mmi_um_jmms_set_folder_list_callback_function(mmi_um_jmms_parse_mms_for_attachment);
        if (g_jmms_context->store_context != NULL && g_jmms_context->store_context->messages_list != NULL)
        {
            mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
        }
        /* This has been done to make sure that if any attachment list parsing is going on
           it should be stopped */
        if (g_jmms_context->g_attachment_pending_list != NULL)
        {
            mmi_jmms_parse_continue_stop_timer();
            mmi_jmms_free_attacment_pending_status_list();
            if (g_jmms_context->parse_content_p != NULL)
            {
                if (g_jmms_context->parse_content_p->pFileName != NULL)
                {
                    jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
                }
                jdd_MemFree(g_jmms_context->parse_content_p);
                g_jmms_context->parse_content_p = NULL;
            }
            if (g_jmms_context->msg_handle != NULL)
            {
                mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                g_jmms_context->msg_handle = NULL;
            }
        }
        mmi_um_jmms_get_fill_list(mms_list_rsp_p, ((mmi_um_get_list_req_struct*) msg_list_req_p));
    }
    else
    {
        MYQUEUE message;

        mms_list_rsp_p = (mmi_um_get_list_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_list_rsp_struct));
        mms_list_rsp_p->result = KAL_TRUE;
        mms_list_rsp_p->msg_box_type = msg_list_req_p->msg_box_type;
        mms_list_rsp_p->start_entry = 0;
        mms_list_rsp_p->msg_number = 0;
        mms_list_rsp_p->msg_type = UM_MSG_TYPE_MMS;
        /* Prepare response structure */
        message.oslSrcId = MOD_WAP;
        message.oslDestId = MOD_MMI;
        message.oslMsgId = MSG_ID_MMI_UM_GET_LIST_RSP;
        /* Send Response to MMI Queue */
        message.oslDataPtr = (oslParaType*) mms_list_rsp_p;
        message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&message);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_get_mms_message_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info_req_p      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_get_mms_message_info_req(mmi_um_get_msg_info_req_struct *msg_info_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_get_msg_info_rsp_struct *mms_info_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    mms_info_rsp_p = (mmi_um_get_msg_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_msg_info_rsp_struct));
    /* memset(mms_info_rsp_p, 0, sizeof(mmi_um_get_msg_info_rsp_struct)); */
    mms_info_rsp_p->result = KAL_TRUE;
    mms_info_rsp_p->msg_type = UM_MSG_TYPE_MMS;
    mms_info_rsp_p->msg_box_type = msg_info_req_p->msg_box_type;
    mms_info_rsp_p->start_entry = msg_info_req_p->start_entry;
    mms_info_rsp_p->msg_number = msg_info_req_p->msg_number;
    mmi_um_jmms_get_fill_list_info(mms_info_rsp_p, msg_info_req_p);

    mmi_um_jmms_at_delete_pre_set();
    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_GET_MSG_INFO_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_info_rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_delete_all_mms_message_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_delete_all_req_p        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_delete_all_mms_message_req(mmi_um_delete_folder_req_struct *msg_delete_all_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_delete_folder_rsp_struct *mms_delete_all_rsp_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    S16 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    mms_delete_all_rsp_p =
        (mmi_um_delete_folder_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_folder_rsp_struct));

    /* memset(mms_delete_all_rsp_p, 0, sizeof(mmi_um_delete_folder_rsp_struct)); */
    mms_delete_all_rsp_p->msg_type = msg_delete_all_req_p->msg_type;

    if (JMMS_READY_WITHOUT_STORE == g_jmms_context->init_done)
    {
        number = 0;
    }
    else
    {
        number = mmi_jmms_get_number_of_messages_from_msg_box_type(msg_delete_all_req_p->msg_box_type);
    }
    if (number >= 0)
    {
        if (number == 0)
        {
            mms_delete_all_rsp_p->result = KAL_TRUE;
        }
        else
        {

        #ifdef __USB_IN_NORMAL_MODE__
            if (mmi_jmms_check_usb_mode() == 0)
        #endif 
            {
                ret_code = mmi_jmms_delete_all_msgs_list(msg_delete_all_req_p->msg_box_type);

                if (ret_code == JC_OK)
                {
                    mms_delete_all_rsp_p->result = KAL_TRUE;
                }
                else
                {
                    mms_delete_all_rsp_p->result = KAL_FALSE;
                }
            }
        #ifdef __USB_IN_NORMAL_MODE__
            else
            {
                mms_delete_all_rsp_p->result = KAL_FALSE;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 
        }
    }
    else
    {
        mms_delete_all_rsp_p->result = KAL_FALSE;
    }
    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_DELETE_FOLDER_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_delete_all_rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_ready_ind
 * DESCRIPTION
 *  Function to send an indication to UM that browser is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_ready_ind_struct *mms_um_ready_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_um_ready_ind_p = (mmi_um_ready_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_ready_ind_struct));
    mms_um_ready_ind_p->result = KAL_TRUE;
    mms_um_ready_ind_p->msg_type = UM_MSG_TYPE_MMS;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_READY_IND;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_um_ready_ind_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_delete_all_mms_messages_rsp
 * DESCRIPTION
 *  Function to recieve information that if user has confirmed
 *  to delete all mms messages or not.
 * PARAMETERS
 *  result      [IN]        - confirmation of deletion of all messages.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_delete_all_mms_messages_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == KAL_TRUE && !(IsScreenPresent(SCR_ID_UM_INBOX) || IsScreenPresent(SCR_ID_UM_UNSENT)
                                || IsScreenPresent(SCR_ID_UM_SENT) || IsScreenPresent(SCR_ID_UM_DRAFT)))
    {
        DeleteUptoScrID(SCR_ID_UM_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_delete_highlight_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_delete_highlight_folder(um_msg_delete_folder_enum folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_delete_all_ind_struct *mms_delete_all_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_delete_all_ind_p = (mmi_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_all_ind_struct));
    mms_delete_all_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_delete_all_ind_p->msg_box_type = folder;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_DELETE_ALL_IND;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_delete_all_ind_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_new_mms_timestamp
 * DESCRIPTION
 *  Function to send an indication to UM that a new mms message has arrived.
 * PARAMETERS
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U64 mmi_um_jmms_new_mms_timestamp(U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_msg_list_p = NULL;
    U64 timestamp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_ret_filter.uiStartIndex = msg_index;
    store_ret_filter.uiNumMessage = 1;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    ret_code = mmi_jmms_get_messages_list("Inbox", &temp_msg_list_p, &store_ret_filter);
    if (ret_code != JC_OK || temp_msg_list_p == NULL)
    {
        return timestamp;   /* JC_ERR_MEMORY_ALLOCATION; */
    }
    message_list_p = temp_msg_list_p;
    switch (message_list_p->pMessageHeaders->eMsgType)
    {
        case E_MSG_TYPE_NOTIFICATION:
        {
            MESSAGE_NOTIFICATION *notification_p;

            notification_p = (MESSAGE_NOTIFICATION*) (message_list_p->pMessageHeaders->pHeaders);

            timestamp = (*notification_p).uiReceivedTime;
            break;
        }

        case E_MSG_TYPE_RECEIVE:
        {
            MESSAGE_RETRIEVAL *retrieval_p;

            retrieval_p = (MESSAGE_RETRIEVAL*) (message_list_p->pMessageHeaders->pHeaders);

            timestamp = retrieval_p->uiDate;
            break;
        }

        case E_MSG_TYPE_DELIVERY_REPORT:
        {
            DELIVERY_REPORT *delivery_p;

            delivery_p = (DELIVERY_REPORT*) (message_list_p->pMessageHeaders->pHeaders);

            timestamp = delivery_p->uiDate;

            break;
        }

        case E_MSG_TYPE_READ_REPORT_RESPONSE:
        {
            READ_REPORT_RESPONSE *read_report_p;

            read_report_p = (READ_REPORT_RESPONSE*) (message_list_p->pMessageHeaders->pHeaders);
            timestamp = (*read_report_p).uiReceivedTime;
            break;
        }
    }
    return timestamp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_new_mms_message_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_new_mms_message_ind(U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_new_msg_ind_struct *mms_new_msg_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_new_msg_ind_p = (mmi_um_new_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_new_msg_ind_struct));
    mms_new_msg_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_new_msg_ind_p->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    mms_new_msg_ind_p->msg_index = msg_index;
    mms_new_msg_ind_p->timestamp = mmi_um_jmms_new_mms_timestamp(msg_index);

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_NEW_MSG_IND;
    message.oslDataPtr = (oslParaType*) mms_new_msg_ind_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_refresh_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_refresh_ind_struct *mms_ref_msg_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_ref_msg_ind_p = (mmi_um_refresh_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_refresh_ind_struct));
    mms_ref_msg_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_ref_msg_ind_p->msg_box_type = mmi_um_get_current_msg_box_type();

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_REFRESH_IND;
    message.oslDataPtr = (oslParaType*) mms_ref_msg_ind_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_highlight_mms_message_ind
 * DESCRIPTION
 *  Function to send information to UM about the currently highlighted item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_highlight_mms_message_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_um_highlight_msg_ind_struct *mms_highlight_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_highlight_ind_p =
        (mmi_um_highlight_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_highlight_msg_ind_struct));
    mms_highlight_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_highlight_ind_p->msg_box_type = mmi_um_get_current_msg_box_type();
    mms_highlight_ind_p->msg_index = g_jmms_context->curr_scr_hilited_index;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) mms_highlight_ind_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_pre_entry_inbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_pre_entry_unsent();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_pre_entry_sent();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_draft
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_pre_entry_draft();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_curr_folder_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_um_get_curr_folder_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folder_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_um_get_current_msg_box_type())
    {
        case UM_MSG_BOX_TYPE_INBOX:
            folder_scr_id = SCR_ID_UM_INBOX;
            break;
        case UM_MSG_BOX_TYPE_UNSENT:
            folder_scr_id = SCR_ID_UM_UNSENT;
            break;
        case UM_MSG_BOX_TYPE_SENT:
            folder_scr_id = SCR_ID_UM_SENT;
            break;
        case UM_MSG_BOX_TYPE_DRAFT:
            folder_scr_id = SCR_ID_UM_DRAFT;
            break;
        default:
            folder_scr_id = 0;
            break;
    }
    return folder_scr_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_inbox_including_highlighter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_inbox_including_highlighter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_jmms_highlight_mms_message_ind();
    mmi_um_pre_entry_inbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jmms_pre_entry_draft_including_highlighter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jmms_pre_entry_draft_including_highlighter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_jmms_at_delete_pre_set();
    mmi_um_jmms_highlight_mms_message_ind();
    mmi_um_pre_entry_draft();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_number_of_messages_from_msg_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_jmms_get_number_of_messages_from_msg_box_type(UmMsgBoxType msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = 0;
    U8 number = 0;
    S16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box_type & UM_MSG_BOX_TYPE_INBOX)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number);
        if (ret_code != JC_OK)
        {
            goto ERROR;
        }
        total += number;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_UNSENT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &number);
        if (ret_code != JC_OK)
        {
            goto ERROR;
        }
        total += number;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_SENT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_SENT, &number);
        if (ret_code != JC_OK)
        {
            goto ERROR;
        }
        total += number;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_DRAFT)
    {
        ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &number);
        if (ret_code != JC_OK)
        {
            goto ERROR;
        }
        total += number;
    }
  ERROR:
    if (ret_code != JC_OK)
    {
        total = -1;
    }
    return total;
}
#else /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_um_handling_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_um_handling_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_JMMSUMHANDLE_C */ 

