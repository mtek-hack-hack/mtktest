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
 * JBrowserMMIServiceInbox.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for service inbox implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMISERVICEINBOX_C
#define _MMI_JBROWSERMMISERVICEINBOX_C


#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "time.h"
#ifndef __MMI_UNIFIED_MESSAGE__
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#include "DateTimeGprot.h"

#include "settingGprots.h"

#include "wgui_status_icons.h"


#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"
#include "browserlayout.h"
#include "jdi_servicehandler.h"
#include "jdi_browserinterface.h"
#include "fsm.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"

#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"

#include "JPushInboxCommonAPIs.h"
#include "JPushInboxCommonUI.h"
#include "DateTimeGprot.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"

#ifdef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
#endif 
/*
 * Commented by Vikas Lal
 * U8 *g_read_arrived_message_buffer = NULL;
 * SERVICE_VALUE *g_brw_rcvd_service_msg_p = NULL;
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_service_inbox
 * DESCRIPTION
 *  Entry function for service inbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_service_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 ret_code = 0;
    JC_UINT32 brw_total_msg_count = 0;
    JC_UINT32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mmi_brw_push_cntx.service_msg_list_p)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_PUSH_MEMORY_NOT_ENOUGH),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    ret_code = mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %u", "PUSH- Inside Push Inbox", ret_code);
        ASSERT(0);
    }

    /* While reading the messsage from idle screen when user will press back. 
       at that time while displying the message list local buffer should clear
       Vivek - 12082006 */
    mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);

    g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_FALSE;
    g_mmi_brw_push_cntx.push_delete_notification = MMI_FALSE;

    /* Display 'Empty' if no push messages are present */
    if ((brw_total_msg_count) == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);

        /* Added by Vivek - 30july, 2006. If push inbox is open from the 'idle screen 
           push indication'. After showing the empty pop up it should return to 
           idle screen */
        if (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetCurrScrnId())
        {
            DeleteNHistory(1);
        }
    }
    else
    {
        EntryNewScreen(SCR_ID_BRW_SERVICE_INBOX, NULL, mmi_brw_entry_service_inbox, NULL);

        /* Added by Vivek - 11july, 2006. If push inbox is open from the 'idle screen 
           push indication' */
        if (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetCurrScrnId())
        {
            DeleteNHistory(1);
        }

        guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SERVICE_INBOX);

        mmi_brw_create_push_msg_list();

        ShowCategory184Screen(
            STR_ID_BRW_SERVICE_INBOX,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            0,
            STR_GLOBAL_BACK,
            0,
            brw_total_msg_count,
            mmi_brw_service_inbox_list_get_item,
            0,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_brw_highlighted_push_msg, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_highlighted_push_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_service_inbox_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of push messages
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_service_inbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct tm expiry_timestamp = {0};
    U64 expiry_secs_since_1970 = {0};
    U64 current_secs_since_1970 = {0};
    U32 rcvd_message_href_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > g_mmi_brw_push_cntx.max_push_messages))
    {
        return FALSE;
    }

    /* Edited by Vivek - 5th july 2006 */
    if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->service_flag == SERVICE_INDICATION)
    {
        if ((NULL == g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmMessage) ||
            !mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmMessage))
        {
            rcvd_message_href_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref);
            if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
            {
                mmi_ucs2ncpy(
                    (S8*) str_buff,
                    (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref,
                    MAX_SUBMENU_CHARACTERS - 3);
                mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
            }
            else
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref);
            }
        }
        else
        {
            rcvd_message_href_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmMessage);
            if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
            {
                mmi_ucs2ncpy(
                    (S8*) str_buff,
                    (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmMessage,
                    MAX_SUBMENU_CHARACTERS - 3);
                mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
            }
            else
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmMessage);
            }
        }
    }
    else if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->service_flag == SERVICE_LOADING)
    {
        rcvd_message_href_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref);
        if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
        {
            mmi_ucs2ncpy(
                (S8*) str_buff,
                (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref,
                MAX_SUBMENU_CHARACTERS - 3);
            mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pmHref);
        }
    }
    else
    {
        /* ERROR */
    }

    /* Expiry time is to be calculated in case of SI to display expired message in case of expired message */
    if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->service_flag == SERVICE_INDICATION)
    {
        if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires != NULL)
        {
            expiry_timestamp.tm_mon = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->month - 1;        /* month scale to 0 to 11 */
            expiry_timestamp.tm_year = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->year - 1900;     /* offset since 1900 */
            expiry_timestamp.tm_mday = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->day;
            expiry_timestamp.tm_hour = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->hour;
            expiry_timestamp.tm_min = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->minute;
            expiry_timestamp.tm_sec = g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires->seconds;

            /* Get difference of seconds of expiry time from 1970 (as per UTC standard) */
            expiry_secs_since_1970 = (time_t) mktime(&expiry_timestamp);
            /* Get difference of seconds of current time from 1970 (as per UTC standard) */
            current_secs_since_1970 = get_current_utc_time();
        }

        /* Show icon depending on whether it is read,unread,read but expired and unread but expired */
        if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->bIsRead == 0)
        {
            if ((expiry_secs_since_1970 > current_secs_since_1970) ||
                (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires == NULL))
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_UNREAD);
            }
            else
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_EXPIRED_UNREAD);
            }
        }
        else
        {
            if ((expiry_secs_since_1970 > current_secs_since_1970) ||
                (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->pSIExpires == NULL))
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_READ);
            }
            else
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_EXPIRED_READ);
            }
        }
    }
    else if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->service_flag == SERVICE_LOADING)
    {
        if (g_mmi_brw_push_cntx.service_msg_list_p[item_index]->bIsRead == 0)
        {
            *img_buff_p = get_image(IMG_ID_BRW_PUSH_UNREAD);
        }
        else
        {
            *img_buff_p = get_image(IMG_ID_BRW_PUSH_READ);
        }
    }
    else
    {
        /* error */
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_highlighted_push_msg
 * DESCRIPTION
 *  Function to get the highlighted push message and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_highlighted_push_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_push_cntx.curr_hilited_item_index = (U8) GetHighlightedItem();
    mmi_brw_entry_service_inbox_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_all_push_messages
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_all_push_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_counter;
    JC_UINT32 brw_total_msg_count = 0;
    JC_UINT32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* added by Vivek */
    HideStatusIcon(STATUS_ICON_WAP);

    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    for (msg_counter = 0; msg_counter < brw_total_msg_count; msg_counter++)
    {
        mmi_brw_delete_push_msg(0);
    }

    /* Added by Vivek - 13072006 */
    mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);

    /* Edited By Vivek - 5 July 2006 */
    /* DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_DELETED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
    /* Edited by Vivek - 02082006. Now instead of displaying the image IMG_GLOBAL_DELETED
       we are displaying IMG_GLOBAL_ACTIVATED as we are doing in other part of browser */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    if (IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX))
    {
        DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);
    }
    else    /* when message is deleted from idle screen */
    {
        mmi_brw_entry_service_inbox();
        DeleteScreenIfPresent(SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND);
        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    }

    /* Save to persistant storage */
    mmi_brw_save_current_push_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_service_inbox_options_back
 * DESCRIPTION
 *  Back function for service inbox options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_service_inbox_options_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Added by Vivek - 13072006 */
    mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_service_inbox_options
 * DESCRIPTION
 *  Entry function for service inbox options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_service_inbox_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 UC_list_of_items[3];
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SERVICE_INBOX_OPTIONS, NULL, mmi_brw_entry_service_inbox_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SERVICE_INBOX_OPTIONS);

    num_of_items = GetNumOfChild(MENU_ID_BRW_PUSH_MSG_OPTIONS);
    GetSequenceStringIds(MENU_ID_BRW_PUSH_MSG_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_PUSH_MSG_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        UC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_entry_service_inbox_options_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_entry_service_inbox_options_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#if 0   /* Commented by vikas lal */
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
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_read_arrived_push_message
 * DESCRIPTION
 *  Entry Function to read arrived push message form idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_read_arrived_push_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    if (1 == brw_unread_msg_count)
    {
        g_mmi_brw_push_cntx.curr_hilited_item_index = 0;
        mmi_brw_entry_read_push_message();
    }
    else
    {
        mmi_brw_entry_service_inbox();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_new_push_msg_ind
 * DESCRIPTION
 *  Function to check the status whether new message is recieved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_new_push_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_cntx.push_msg_rcvd_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_new_push_msg_ind_on_idlescreen
 * DESCRIPTION
 *  Entry Function to display screen for push message arrived indication
 *  on idle-screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_new_push_msg_ind_on_idlescreen(void)   /* added by puneet */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 buf[4] = {0};
    S8 pOutBuffer[8] = {0};
    S8 message_string[40] = {0};
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    if (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetActiveScreenId())
    {
        DeleteNHistory(1);
    }

    if (0 == brw_unread_msg_count)
    {
        DisplayIdleScreen();
        return;
    }

    if (brw_unread_msg_count < 10)
    {
        sprintf(buf, "%01d", brw_unread_msg_count);
    }
    else
    {
        sprintf(buf, "%02d", brw_unread_msg_count);
    }

    mmi_asc_to_ucs2(pOutBuffer, buf);
    mmi_ucs2cpy((S8*) message_string, pOutBuffer);
    mmi_ucs2cat((S8*) message_string, " ");
    mmi_ucs2cat((S8*) message_string, GetString(STR_ID_BRW_SERVICE_MESSAGE_RCVD));

    EntryNewScreen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND, NULL, mmi_brw_new_push_msg_ind_on_idlescreen, NULL);
    ShowStatusIcon(STATUS_ICON_WAP);

    if (0 == g_keylock_context.gKeyPadLockFlag)
    {
        /*
         * ShowCategory154Screen(
         * 0,
         * 0,
         * STR_ID_BRW_READ,
         * IMG_GLOBAL_YES,
         * STR_GLOBAL_BACK,
         * IMG_GLOBAL_BACK,
         * (PU8) message_string,
         * 0,
         * IMG_NEW_MESSAGE_NOTIFICATION_MSG,
         * NULL);
         */

        /* Modified by vikas lal - 29032007 Category 154 will be replaced(By Category 66) here for text wraping */
        ShowCategory66Screen(
            0,
            0,
            STR_ID_BRW_READ,
            IMG_GLOBAL_YES,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) message_string,
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            NULL);

        g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_FALSE;

        if (1 == brw_unread_msg_count)
        {
            SetLeftSoftkeyFunction(mmi_brw_read_arrived_push_message, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_brw_entry_service_inbox, KEY_EVENT_UP);
        }

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else    /* Keypad is locked */
    {
        extern void EntryScrAfterPessingRSK(void);

    #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
        extern void EntryScrKeyPadLockOnPessingAnyKey(void);
    #endif 

        /*
         * ShowCategory154Screen(  
         * 0,
         * 0,
         * g_keylock_context.KeyLockLSKStringID,
         * g_keylock_context.KeyLockLSKIconID,
         * g_keylock_context.KeyLockRSKStringID,
         * g_keylock_context.KeyLockRSKIconID,
         * (PU8) message_string,
         * 0,
         * IMG_NEW_MESSAGE_NOTIFICATION_MSG,
         * NULL);
         */
        /* Modified by vikas lal - 29032007 Category 154 will be replaced(By Category 66) here for text wraping */
        ShowCategory66Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) message_string,
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            NULL);

    #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
        SetGroupKeyHandler(
            EntryScrKeyPadLockOnPessingAnyKey,
            (PU16) PresentAllKeys,
            (U8) TOTAL_KEYS,
            (U16) KEY_EVENT_DOWN);
    #endif /* defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__) */ 

    #ifdef __MMI_TOUCH_SCREEN__

    #ifdef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        SetRightSoftkeyFunction(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_DOWN);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        SetLeftSoftkeyFunction(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_DOWN);
    #endif 
    #else /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
        ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    #endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
        SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);

    #else /* __MMI_TOUCH_SCREEN__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        SetRightSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        SetLeftSoftkeyFunction(EntryScrAfterPessingRSK, KEY_EVENT_DOWN);
    #endif 

    #endif /* __MMI_TOUCH_SCREEN__ */ 

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_idle_pen_block();
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_new_push_msg_ind
 * DESCRIPTION
 *  Entry Function to display screen for push message arrived indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_new_push_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_new_push_msg_ind_on_idlescreen();
    g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_FALSE;
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* _MMI_JBROWSERMMISERVICEINBOX_C */ 

