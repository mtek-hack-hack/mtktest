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
 *  JMMSUseDetailsUI.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for use details option in all the folders
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
#ifndef _MMI_JMMSUSEDETAILSSECMMI_C
#define _MMI_JMMSUSEDETAILSSECMMI_C

/***************************************************************************** 
* Include
*****************************************************************************/

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "JMMSStoreHandling.h"
#include "MainMenuDef.h"
#include "PhonebookGprot.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>

#include "CallManagementGprot.h"

#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern JC_BOOLEAN IsValidPhoneNumber(JC_INT8 *pPhoneNumber, JC_CHAR *pPhoneNumberUCS2, JC_INT32 iLengthCheck);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_use_details_screen
 * DESCRIPTION
 *  Entry fn for use details screen
 * PARAMETERS
 *  folder_name_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_use_details_screen(S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number = 0;

    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_msg_list_p = NULL;
    JC_CHAR *from_addresses_p = NULL, *to_addresses_p = NULL, *cc_addresses_p = NULL, *bcc_addresses_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    store_ret_filter.uiStartIndex = number - g_jmms_context->curr_scr_hilited_index;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    store_ret_filter.uiNumMessage = 1;

    ret_code = mmi_jmms_get_messages_list(folder_name_p, &temp_msg_list_p, &store_ret_filter);

    message_list_p = temp_msg_list_p;

    if (ret_code != JC_OK || message_list_p == NULL)
    {
        mmi_jmms_error_handler(ret_code);
        return;
    }

    switch (message_list_p->pMessageHeaders->eMsgType)
    {
        case E_MSG_TYPE_NOTIFICATION:
        {
            MESSAGE_NOTIFICATION *notification_p;

            notification_p = (MESSAGE_NOTIFICATION*) (message_list_p->pMessageHeaders->pHeaders);

            from_addresses_p = notification_p->pFrom;

            to_addresses_p = NULL;
            cc_addresses_p = NULL;
            bcc_addresses_p = NULL;

            break;
        }
        case E_MSG_TYPE_RECEIVE:
        {
            MESSAGE_RETRIEVAL *retrieval_p;

            retrieval_p = (MESSAGE_RETRIEVAL*) (message_list_p->pMessageHeaders->pHeaders);

            from_addresses_p = retrieval_p->pFrom;

            to_addresses_p = retrieval_p->pTo;
            cc_addresses_p = retrieval_p->pCc;
            bcc_addresses_p = NULL;

            break;
        }
        case E_MSG_TYPE_DELIVERY_REPORT:
        {
            DELIVERY_REPORT *delievery_report_p;

            delievery_report_p = (DELIVERY_REPORT*) (message_list_p->pMessageHeaders->pHeaders);

            from_addresses_p = NULL;
            to_addresses_p = delievery_report_p->pTo;
            cc_addresses_p = NULL;
            bcc_addresses_p = NULL;

            break;

        }
        case E_MSG_TYPE_READ_REPORT_RESPONSE:
        {
            READ_REPORT_RESPONSE *read_report_p;

            read_report_p = (READ_REPORT_RESPONSE*) (message_list_p->pMessageHeaders->pHeaders);

            from_addresses_p = read_report_p->pFrom;
            to_addresses_p = read_report_p->pTo;
            cc_addresses_p = NULL;
            bcc_addresses_p = NULL;

            break;
        }
        case E_MSG_TYPE_SEND:
        {
            MESSAGE_SEND *send_p;

            send_p = (MESSAGE_SEND*) (message_list_p->pMessageHeaders->pHeaders);

            from_addresses_p = send_p->pFrom;
            to_addresses_p = send_p->pTo;
            cc_addresses_p = send_p->pCc;
            bcc_addresses_p = send_p->pBcc;

            break;
        }
        default:
            return;
    }

    mmi_jmms_free_use_details_adrresses_list();

    mmi_jmms_create_use_details_addresses_list(from_addresses_p, to_addresses_p, cc_addresses_p, bcc_addresses_p);

    /* HIMANSHU Put this condition in Unified Messaging only */
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->g_jmms_use_details.addresses_list == NULL)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_USE_DETAILS_NO_NUMBER),
            IMG_GLOBAL_EMPTY,
            1,
            JMMS_POPUP_TIME,
            EMPTY_LIST_TONE);
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_use_details_number();  /* sachin */
#else 
    mmi_jmms_entry_use_details_screen();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_use_details_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_UNIFIED_MESSAGE__
void mmi_jmms_entry_use_details_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 scrid;
    U16 menuid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->store_context->current_folder_name == E_JMMS_INBOX)
    {
        scrid = SCR_ID_JMMS_INBOX_OPTIONS_USE_DETAILS;
        menuid = MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS;

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_OUTBOX)
    {
        scrid = SCR_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS;
        menuid = MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS;
    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_SENT)
    {
        scrid = SCR_ID_JMMS_SENT_OPTIONS_USE_DETAILS;
        menuid = MENU_ID_JMMS_SENT_OPTIONS_USE_DETAILS;
    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS)
    {
        scrid = SCR_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS;
        menuid = MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS;
    }
    else
    {
        return;
    }

    EntryNewScreen(scrid, NULL, mmi_jmms_entry_use_details_screen, NULL);

    gui_buffer_p = GetCurrGuiBuffer(scrid);

    num_item = GetNumOfChild(menuid);
    GetSequenceStringIds_Ext(menuid, str_item_list);

    SetParentHandler(menuid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        (U8 **) NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(mmi_jmms_back_from_use_details_main_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_from_use_details_main_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_back_from_use_details_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_back_from_use_details_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_free_use_details_adrresses_list();
    GoBackHistory();
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_use_details_addresses_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  from_p      [IN]        
 *  to_p        [IN]        
 *  cc_p        [IN]        
 *  bcc_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_use_details_addresses_list(JC_CHAR *from_p, JC_CHAR *to_p, JC_CHAR *cc_p, JC_CHAR *bcc_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mms_addresses_list *node_p = NULL;
    S32 len_to_copy = 0;
    S8 *str_p = NULL;
    S32 len = 0;
    S32 start_index = 0;
    U16 num_len = 0;
    S8 ansii_number[MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1];

#if defined(LARGE_MMS_HANDLING)
    S32 counter_of_address = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_00018175 Start */
    if (g_jmms_context->view_context != NULL &&
        g_jmms_context->view_context->focus_object_type == E_MSG_FOCUS_PHONE_NUMBER)
        /* MAUI_00018175 End */
    {
        ACTIVE_MEDIA_INFO activeMediaInfo;

        mmi_jmms_jdi_get_active_media_info(g_jmms_context->msg_handle, &activeMediaInfo);
        node_p = (mms_addresses_list*) jdd_MemAlloc(sizeof(mms_addresses_list), 1);
        if (node_p == NULL)
        {

            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
            mmi_jmms_free_use_details_adrresses_list();
            return;
        }
        node_p->is_email = MMI_FALSE;
        len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
        node_p->address = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);

        if (node_p->address == NULL)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
            /* HIMANSHU Memory Leak Fix Start */
            if (node_p != NULL)
            {
                jdd_MemFree(node_p);
                node_p = NULL;
            }
            /* HIMANSHU Memory Leak Fix End */
            mmi_jmms_free_use_details_adrresses_list();
            return;
        }

        mmi_ucs2ncpy((S8*) node_p->address, (S8*) activeMediaInfo.LinkInfo.pLinkText, len_to_copy);

        /* HIMANSHU Memory Leak Fix Start */
        if (g_jmms_context->g_jmms_use_details.addresses_list != NULL)
        {
            mmi_jmms_free_use_details_adrresses_list();
        }
        g_jmms_context->g_jmms_use_details.addresses_list = node_p;
        /* HIMANSHU Memory Leak Fix End */
    }
    if (from_p != NULL)
    {
        str_p = (S8*) (from_p);
        len = 0;
        start_index = 0;
        node_p = NULL;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {
        #if defined(LARGE_MMS_HANDLING)
            if (counter_of_address == MAX_NO_OF_ALLOWABLE_ADDRESSES)
            {
                break;
            }
            counter_of_address++;
        #endif /* defined(LARGE_MMS_HANDLING) */ 

            node_p = (mms_addresses_list*) jdd_MemAlloc(sizeof(mms_addresses_list), 1);
            if (node_p == NULL)
            {

                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }
            node_p->is_email = MMI_FALSE;
            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    node_p->is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;

            }

            if (node_p->is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (node_p->is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            node_p->address = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (node_p->address == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                /* HIMANSHU Memory Leak Fix Start */
                if (node_p != NULL)
                {
                    jdd_MemFree(node_p);
                    node_p = NULL;
                }
                /* HIMANSHU Memory Leak Fix End */
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }

            mmi_ucs2ncpy((S8*) node_p->address, (S8*) (from_p + start_index), len_to_copy);
            if (node_p->is_email == MMI_FALSE)
            {
                num_len = mmi_ucs2_n_to_asc(
                            (PS8) ansii_number,
                            (PS8) node_p->address,
                            MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH);
                ansii_number[num_len] = 0;
                if (!IsValidPhoneNumber((JC_INT8*) ansii_number, (JC_CHAR*) node_p->address, 0))
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                    start_index = start_index + len + 1;
                    len = 0;
                    if ((*str_p) != '\0')
                    {
                        str_p = str_p + ENCODING_LENGTH;
                    }
                    continue;
                }
            }
            if (g_jmms_context->g_jmms_use_details.addresses_list == NULL)
            {
                g_jmms_context->g_jmms_use_details.addresses_list = node_p;
            }
            else
            {
                mms_addresses_list *temp_p, *temp1;
                MMI_BOOL is_duplicate = MMI_FALSE;

                temp_p = g_jmms_context->g_jmms_use_details.addresses_list;
                while (temp_p != NULL)
                {
                    if (mmi_ucs2cmp((S8*) (node_p->address), (S8*) (temp_p->address)) == 0)
                    {
                        is_duplicate = MMI_TRUE;
                        break;
                    }
                    temp1 = temp_p;
                    temp_p = temp_p->next_p;
                }
                /* HIMANSHU Memory Leak Fix Start */
                if (is_duplicate == MMI_FALSE)
                {
                    temp1->next_p = node_p;
                }
                else
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                }
                /* HIMANSHU Memory Leak Fix End */

            }

            start_index = start_index + len + 1;
            len = 0;
            node_p = NULL;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }

        }

    }

    if (to_p != NULL)
    {
        str_p = (S8*) (to_p);
        len = 0;
        start_index = 0;
        node_p = NULL;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {
        #if defined(LARGE_MMS_HANDLING)
            if (counter_of_address == MAX_NO_OF_ALLOWABLE_ADDRESSES)
            {
                break;
            }
            counter_of_address++;
        #endif /* defined(LARGE_MMS_HANDLING) */ 
            node_p = (mms_addresses_list*) jdd_MemAlloc(sizeof(mms_addresses_list), 1);
            if (node_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }
            node_p->is_email = MMI_FALSE;
            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    node_p->is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;

            }

            if (node_p->is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (node_p->is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            node_p->address = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (node_p->address == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                /* HIMANSHU Memory Leak Fix Start */
                if (node_p != NULL)
                {
                    jdd_MemFree(node_p);
                    node_p = NULL;
                }
                /* HIMANSHU Memory Leak Fix End */
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }

            mmi_ucs2ncpy((S8*) node_p->address, (S8*) (to_p + start_index), len_to_copy);
            if (node_p->is_email == MMI_FALSE)
            {
                num_len = mmi_ucs2_n_to_asc(
                            (PS8) ansii_number,
                            (PS8) node_p->address,
                            MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH);
                ansii_number[num_len] = 0;
                if (!IsValidPhoneNumber((JC_INT8*) ansii_number, (JC_CHAR*) node_p->address, 0))
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                    start_index = start_index + len + 1;
                    len = 0;
                    if ((*str_p) != '\0')
                    {
                        str_p = str_p + ENCODING_LENGTH;
                    }
                    continue;
                }
            }
            if (g_jmms_context->g_jmms_use_details.addresses_list == NULL)
            {
                g_jmms_context->g_jmms_use_details.addresses_list = node_p;
            }
            else
            {
                mms_addresses_list *temp_p, *temp1;
                MMI_BOOL is_duplicate = MMI_FALSE;

                temp_p = g_jmms_context->g_jmms_use_details.addresses_list;
                while (temp_p != NULL)
                {
                    if (mmi_ucs2cmp((S8*) (node_p->address), (S8*) (temp_p->address)) == 0)
                    {
                        is_duplicate = MMI_TRUE;
                        break;
                    }
                    temp1 = temp_p;
                    temp_p = temp_p->next_p;
                }
                /* HIMANSHU Memory Leak Fix Start */
                if (is_duplicate == MMI_FALSE)
                {
                    temp1->next_p = node_p;
                }
                else
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                }
                /* HIMANSHU Memory Leak Fix End */

            }

            start_index = start_index + len + 1;
            len = 0;
            node_p = NULL;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }

        }

    }

    if (cc_p != NULL)
    {
        str_p = (S8*) (cc_p);
        len = 0;
        start_index = 0;
        node_p = NULL;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {
        #if defined(LARGE_MMS_HANDLING)
            if (counter_of_address == MAX_NO_OF_ALLOWABLE_ADDRESSES)
            {
                break;
            }
            counter_of_address++;
        #endif /* defined(LARGE_MMS_HANDLING) */ 

            node_p = (mms_addresses_list*) jdd_MemAlloc(sizeof(mms_addresses_list), 1);
            if (node_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                mmi_jmms_free_use_details_adrresses_list();

                return;
            }
            node_p->is_email = MMI_FALSE;
            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    node_p->is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;

            }

            if (node_p->is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (node_p->is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            node_p->address = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (node_p->address == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                /* HIMANSHU Memory Leak Fix Start */
                if (node_p != NULL)
                {
                    jdd_MemFree(node_p);
                    node_p = NULL;
                }
                /* HIMANSHU Memory Leak Fix End */
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }

            mmi_ucs2ncpy((S8*) node_p->address, (S8*) (cc_p + start_index), len_to_copy);
            if (node_p->is_email == MMI_FALSE)
            {
                num_len = mmi_ucs2_n_to_asc(
                            (PS8) ansii_number,
                            (PS8) node_p->address,
                            MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH);
                ansii_number[num_len] = 0;
                if (!IsValidPhoneNumber((JC_INT8*) ansii_number, (JC_CHAR*) node_p->address, 0))
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                    start_index = start_index + len + 1;
                    len = 0;
                    if ((*str_p) != '\0')
                    {
                        str_p = str_p + ENCODING_LENGTH;
                    }
                    continue;
                }
            }

            if (g_jmms_context->g_jmms_use_details.addresses_list == NULL)
            {
                g_jmms_context->g_jmms_use_details.addresses_list = node_p;
            }
            else
            {
                mms_addresses_list *temp_p, *temp1;
                MMI_BOOL is_duplicate = MMI_FALSE;

                temp_p = g_jmms_context->g_jmms_use_details.addresses_list;
                while (temp_p != NULL)
                {
                    if (mmi_ucs2cmp((S8*) (node_p->address), (S8*) (temp_p->address)) == 0)
                    {
                        is_duplicate = MMI_TRUE;
                        break;
                    }
                    temp1 = temp_p;
                    temp_p = temp_p->next_p;
                }
                /* HIMANSHU Memory Leak Fix Start */
                if (is_duplicate == MMI_FALSE)
                {
                    temp1->next_p = node_p;
                }
                else
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                }
                /* HIMANSHU Memory Leak Fix End */

            }

            start_index = start_index + len + 1;
            len = 0;
            node_p = NULL;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }

        }

    }

    if (bcc_p != NULL)
    {
        str_p = (S8*) (bcc_p);
        len = 0;
        start_index = 0;
        node_p = NULL;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {
        #if defined(LARGE_MMS_HANDLING)
            if (counter_of_address == MAX_NO_OF_ALLOWABLE_ADDRESSES)
            {
                break;
            }
            counter_of_address++;
        #endif /* defined(LARGE_MMS_HANDLING) */ 

            node_p = (mms_addresses_list*) jdd_MemAlloc(sizeof(mms_addresses_list), 1);
            if (node_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }
            node_p->is_email = MMI_FALSE;
            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    node_p->is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;

            }

            if (node_p->is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (node_p->is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            node_p->address = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (node_p->address == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                /* HIMANSHU Memory Leak Fix Start */
                if (node_p != NULL)
                {
                    jdd_MemFree(node_p);
                    node_p = NULL;
                }
                /* HIMANSHU Memory Leak Fix End */
                mmi_jmms_free_use_details_adrresses_list();
                return;
            }

            mmi_ucs2ncpy((S8*) node_p->address, (S8*) (bcc_p + start_index), len_to_copy);
            if (node_p->is_email == MMI_FALSE)
            {
                num_len = mmi_ucs2_n_to_asc(
                            (PS8) ansii_number,
                            (PS8) node_p->address,
                            MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH);
                ansii_number[num_len] = 0;
                if (!IsValidPhoneNumber((JC_INT8*) ansii_number, (JC_CHAR*) node_p->address, 0))
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                    start_index = start_index + len + 1;
                    len = 0;
                    if ((*str_p) != '\0')
                    {
                        str_p = str_p + ENCODING_LENGTH;
                    }
                    continue;
                }
            }

            if (g_jmms_context->g_jmms_use_details.addresses_list == NULL)
            {
                g_jmms_context->g_jmms_use_details.addresses_list = node_p;
            }
            else
            {
                mms_addresses_list *temp_p, *temp1;
                MMI_BOOL is_duplicate = MMI_FALSE;

                temp_p = g_jmms_context->g_jmms_use_details.addresses_list;
                while (temp_p != NULL)
                {
                    if (mmi_ucs2cmp((S8*) (node_p->address), (S8*) (temp_p->address)) == 0)
                    {
                        is_duplicate = MMI_TRUE;
                        break;
                    }
                    temp1 = temp_p;
                    temp_p = temp_p->next_p;
                }
                /* HIMANSHU Memory Leak Fix Start */
                if (is_duplicate == MMI_FALSE)
                {
                    temp1->next_p = node_p;
                }
                else
                {
                    if (node_p != NULL)
                    {
                        if (node_p->address != NULL)
                        {
                            jdd_MemFree(node_p->address);
                            node_p->address = NULL;
                        }
                        jdd_MemFree(node_p);
                        node_p = NULL;
                    }
                }
                /* HIMANSHU Memory Leak Fix End */

            }

            start_index = start_index + len + 1;
            len = 0;
            node_p = NULL;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_use_details_adrresses_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_use_details_adrresses_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_addresses_list *temp_p, *node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_p = g_jmms_context->g_jmms_use_details.addresses_list;
    while (temp_p != NULL)
    {
        node_p = temp_p->next_p;
        if (temp_p->address != NULL)
        {
            jdd_MemFree(temp_p->address);
            temp_p->address = NULL;
        }
        jdd_MemFree(temp_p);
        temp_p = NULL;

        temp_p = node_p;
    }

    g_jmms_context->g_jmms_use_details.addresses_list = NULL;
}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_options_use_details_number
 * DESCRIPTION
 *  Highlight hdlr of use details use number option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_options_use_details_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_jmms_use_details.number_email_flag = E_USE_NUMBER;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_use_details_number, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_use_details_number, KEY_SEND, KEY_EVENT_DOWN); */
    SetKeyHandler(mmi_jmms_use_details_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_use_details_number, KEY_WAP, KEY_EVENT_DOWN);

}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_use_details_number
 * DESCRIPTION
 *  Pre entry fn for number list screen. It checks whether some number is present
 *  or not in To,Cc,From fields of selected message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_use_details_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL is_number_present = MMI_FALSE;
    mms_addresses_list *node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->g_jmms_use_details.addresses_list;
    while (node_p != NULL)
    {
        if (node_p->is_email == MMI_FALSE)
        {
            is_number_present = MMI_TRUE;
            break;
        }
        node_p = node_p->next_p;
    }

    if (is_number_present == MMI_FALSE)
    {

        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_USE_DETAILS_NO_NUMBER),
            IMG_GLOBAL_EMPTY,
            1,
            JMMS_POPUP_TIME,
            EMPTY_LIST_TONE);

    }
    else
    {
    #ifdef LARGE_MMS_HANDLING
        g_jmms_context->g_jmms_use_details.hilite_address_index = 0;
    #endif 
        mmi_jmms_entry_use_details_addresses_list();
    }

}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_options_use_details_email
 * DESCRIPTION
 *  Highlight hdlr of use details use email option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_options_use_details_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_jmms_use_details.number_email_flag = E_USE_EMAIL;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_use_details_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_use_details_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_use_details_email, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_use_details_email
 * DESCRIPTION
 *  Pre entry fn for email list screen. It checks whether some email is present
 *  or not in To,Cc,From fields of selected message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_use_details_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL bIsEmailPresent = MMI_FALSE;

    mms_addresses_list *node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->g_jmms_use_details.addresses_list;
    while (node_p != NULL)
    {
        if (node_p->is_email == MMI_TRUE)
        {
            bIsEmailPresent = MMI_TRUE;
            break;
        }
        node_p = node_p->next_p;
    }

    if (bIsEmailPresent == MMI_FALSE)
    {

        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_USE_DETAILS_NO_EMAIL_ID),
            IMG_GLOBAL_EMPTY,
            1,
            JMMS_POPUP_TIME,
            EMPTY_LIST_TONE);

    }
    else
    {
    #ifdef LARGE_MMS_HANDLING
        g_jmms_context->g_jmms_use_details.hilite_address_index = 0;
    #endif 
        mmi_jmms_entry_use_details_addresses_list();
    }

}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef LARGE_MMS_HANDLING


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_use_number_data
 * DESCRIPTION
 *  callback handler for the category 184 screen
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_jmms_get_use_number_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = -1;
    mms_addresses_list *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = g_jmms_context->g_jmms_use_details.addresses_list;
    while (MMI_TRUE)
    {
        if (!node)
        {
            break;
        }
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER && node->is_email == FALSE)
        {
            count++;
        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL && node->is_email == TRUE)
        {
            count++;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        if (count == item_index)
        {
            break;
        }
        else
        {
            node = node->next_p;
        }
    }
    mmi_ucs2ncpy((S8*) str_buff, (S8*) node->address, MAX_SUBMENU_CHARACTERS);
    *img_buff_p = get_image(IMG_ID_JMMS_USE_DETAILS_IMAGE);
    return TRUE;
}
#endif /* LARGE_MMS_HANDLING */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_use_details_addresses_list
 * DESCRIPTION
 *  Entry fn for numbers (or emails) list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_use_details_addresses_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer_p;   /* Buffer holding history data */
    U16 strid;

#ifndef LARGE_MMS_HANDLING
    S8 *str_item_list_p[MAX_POSSIBLE_ADDRESSES];
#endif 
    U16 num_item = 0;

    U16 scrid;
    U16 menuid;
    mms_addresses_list *node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->store_context->current_folder_name == E_JMMS_INBOX)
    {
        scrid = SCR_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_ADDRESSES;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_NUMBER;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_EMAIL;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_OUTBOX)
    {
        scrid = SCR_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_ADDRESSES;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_NUMBER;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_EMAIL;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_SENT)
    {
        scrid = SCR_ID_JMMS_SENT_OPTIONS_USE_DETAILS_ADDRESSES;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_SENT_OPTIONS_USE_DETAILS_NUMBER;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_SENT_OPTIONS_USE_DETAILS_EMAIL;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS)
    {
        scrid = SCR_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_ADDRESSES;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_NUMBER;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_EMAIL;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }

    else
    {
        return;
    }

    EntryNewScreen(scrid, NULL, mmi_jmms_entry_use_details_addresses_list, NULL);

    gui_buffer_p = GetCurrGuiBuffer(scrid);

    if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
    {
        strid = STR_ID_JMMS_OPTIONS_USE_DETAILS_NUMBER_LIST;

        node_p = g_jmms_context->g_jmms_use_details.addresses_list;
        while (node_p != NULL)
        {
            if (node_p->is_email == MMI_FALSE)
            {
            #ifndef LARGE_MMS_HANDLING
                str_item_list_p[num_item++] = node_p->address;
                if (num_item == MAX_POSSIBLE_ADDRESSES)
                {
                    break;
                }
            #else /* LARGE_MMS_HANDLING */ 
                num_item++;
            #endif /* LARGE_MMS_HANDLING */ 
            }
            node_p = node_p->next_p;
        }

    }
#ifndef __MMI_UNIFIED_MESSAGE__
    else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
    {
        strid = STR_ID_JMMS_OPTIONS_USE_DETAILS_EMAIL_LIST;

        node_p = g_jmms_context->g_jmms_use_details.addresses_list;
        while (node_p != NULL)
        {
            if (node_p->is_email == MMI_TRUE)
            {
            #ifndef LARGE_MMS_HANDLING
                str_item_list_p[num_item++] = node_p->address;
                if (num_item == MAX_POSSIBLE_ADDRESSES)
                {
                    break;
                }
            #else /* LARGE_MMS_HANDLING */ 
                num_item++;
            #endif /* LARGE_MMS_HANDLING */ 
            }
            node_p = node_p->next_p;
        }

    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    else
    {
        return;
    }

    SetParentHandler(menuid);
    RegisterHighlightHandler(mmi_jmms_use_details_list_highlight_hdlr);
#ifndef LARGE_MMS_HANDLING
    ShowCategory53Screen(
        strid,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        (U8 **) str_item_list_p,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

#else /* LARGE_MMS_HANDLING */ 

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Implementing the list as dynamic");

    ShowCategory184Screen(
        strid,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        mmi_jmms_get_use_number_data,
        0,
        g_jmms_context->g_jmms_use_details.hilite_address_index,
        gui_buffer_p);
#endif /* LARGE_MMS_HANDLING */ 
    SetLeftSoftkeyFunction(mmi_jmms_entry_use_details_addresses_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_use_details_addresses_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_use_details_addresses_options, KEY_WAP, KEY_EVENT_DOWN);

    /* MAUI_00018175 Start */
    if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
    {
        SetKeyHandler(mmi_jmms_use_details_call, KEY_SEND, KEY_EVENT_DOWN);
    }
    /* MAUI_00018175 End */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_use_details_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight hdlr of address in address list screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_use_details_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_jmms_use_details.hilite_address_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_use_details_addresses_options
 * DESCRIPTION
 *  Entry fn for options for use number (or use email) addresses list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_use_details_addresses_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */

    U16 scrid;
    U16 menuid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->store_context->current_folder_name == E_JMMS_INBOX)
    {
        scrid = SCR_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_INBOX_USE_DETAILS_ADDRESSES_OPTIONS1;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_INBOX_USE_DETAILS_ADDRESSES_OPTIONS2;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_OUTBOX)
    {
        scrid = SCR_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_OUTBOX_USE_DETAILS_ADDRESSES_OPTIONS1;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_OUTBOX_USE_DETAILS_ADDRESSES_OPTIONS2;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_SENT)
    {
        scrid = SCR_ID_JMMS_SENT_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_SENT_USE_DETAILS_ADDRESSES_OPTIONS1;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_SENT_USE_DETAILS_ADDRESSES_OPTIONS2;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else if (g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS)
    {
        scrid = SCR_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS;
        if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
        {
            menuid = MENU_ID_JMMS_DRAFTS_USE_DETAILS_ADDRESSES_OPTIONS1;

        }
    #ifndef __MMI_UNIFIED_MESSAGE__
        else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
        {
            menuid = MENU_ID_JMMS_DRAFTS_USE_DETAILS_ADDRESSES_OPTIONS2;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            return;
        }

    }
    else
    {
        return;
    }

    EntryNewScreen(scrid, NULL, mmi_jmms_entry_use_details_addresses_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(scrid);

    num_item = GetNumOfChild(menuid);
    GetSequenceStringIds_Ext(menuid, str_item_list);

    SetParentHandler(menuid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        (U8 **) NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_options_use_details_add_to_contact
 * DESCRIPTION
 *  Highlight handler of Add to Contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_options_use_details_add_to_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_use_details_add_to_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_use_details_add_to_contact, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_use_details_add_to_contact, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_use_details_add_to_contact
 * DESCRIPTION
 *  Add the selected address to contacts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_use_details_add_to_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_addresses_list *node_p;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_NUMBER)
    {

        node_p = g_jmms_context->g_jmms_use_details.addresses_list;
        while (count != g_jmms_context->g_jmms_use_details.hilite_address_index || node_p->is_email == MMI_TRUE)
        {

            if (node_p->is_email == MMI_FALSE)
            {
                count++;
            }

            node_p = node_p->next_p;

        }
        if (node_p == NULL)
        {
            return;
        }

        SaveNumberFromIdleScrn((S8*) (node_p->address), 0);

    }
    else if (g_jmms_context->g_jmms_use_details.number_email_flag == E_USE_EMAIL)
    {

        node_p = g_jmms_context->g_jmms_use_details.addresses_list;
        while (count != g_jmms_context->g_jmms_use_details.hilite_address_index || node_p->is_email == MMI_FALSE)
        {

            if (node_p->is_email == MMI_TRUE)
            {
                count++;
            }

            node_p = node_p->next_p;

        }
        if (node_p == NULL)
        {
            return;
        }

        mmi_phb_email_save_entry_to_phb_from_jmms((S8*) (node_p->address));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_options_use_details_call
 * DESCRIPTION
 *  Highlight hdlr of call option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_options_use_details_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_use_details_call, KEY_EVENT_UP);        /* Amit added prompt screen */
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_use_details_call, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_use_details_call
 * DESCRIPTION
 *  Dial confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_use_details_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mms_addresses_list *node_p;
    U8 count = 0;

    /* U32 len = 0; // COMPILER WARNING REMOVAL */
    S8 tempstr[(MAX_POSSIBLE_NUMBER_LENGHT_SENT + 5) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->g_jmms_use_details.addresses_list;

    while (count != g_jmms_context->g_jmms_use_details.hilite_address_index || node_p->is_email == MMI_TRUE)
    {

        if (node_p->is_email == MMI_FALSE)
        {
            count++;
        }

        node_p = node_p->next_p;

    }
    if (node_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return;
    }

    memset(tempstr, 0, sizeof(tempstr));
    mmi_ucs2cpy(tempstr, (S8*) get_string(STR_GLOBAL_DIAL));
    mmi_ucs2cat(tempstr, " ");
    mmi_ucs2cat(tempstr, node_p->address);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) tempstr,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_use_details_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}   /* Amit end */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_use_details_call
 * DESCRIPTION
 *  Calls the selected number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_use_details_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mms_addresses_list *node_p;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->g_jmms_use_details.addresses_list;
    while (count != g_jmms_context->g_jmms_use_details.hilite_address_index || node_p->is_email == MMI_TRUE)
    {

        if (node_p->is_email == MMI_FALSE)
        {
            count++;
        }

        node_p = node_p->next_p;

    }
    if (node_p == NULL)
    {
        return;
    }

    MakeCall((S8*) (node_p->address));

}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

#endif /* _MMI_JMMSUSEDETAILSSECMMI_C */ 

