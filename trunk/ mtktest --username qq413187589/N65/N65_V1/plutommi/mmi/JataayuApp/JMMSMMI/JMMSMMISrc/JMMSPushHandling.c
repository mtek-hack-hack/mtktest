/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSPushHandling.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file conains the store APIs for interacting with Jatayu Store module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "wgui_datetime.h"
#include "ProfileGprots.h"      /* playRequestedTone() */
#include "MainMenuDef.h"
#include "IdleAppDef.h"
#include "QuickAccessMenuItemProt.h"
#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"

#include <miscutils.h>
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>

#include "JsrTypes.h"

#include "JMMSView.h"

#include "DateTimeDef.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"

#include "MessagesResourceData.h"


#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
/* /#include "JMMSGdcl.h" */
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
#include "wapadp.h"
#include "JPushInboxCommonUI.h"
#include "JMMSPlutoMMIInterface.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "JMMSUMHandling.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "IdleAppProt.h"
#endif 

#include "CallManagementGprot.h"
#include "gpioInc.h"
/***************************************************************************** 
* Define
*****************************************************************************/
/* Define for the read report prepend string */
#define STR_JMMS_READ_REPORT_PREPEND_STRING "Read:"
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
extern void EntryScrAfterPessingRSK(void);
extern em_wap_user_agent_brand_enum wap_get_user_agent_brand(void);

U16 DeleteScreenFromToNnodes(U16 ScrId, U16 num_nodes);
U8 DeleteFromScrUptoScr(U16 beyondScrnid, U16 tillScrnid);

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_roaming_status
 * DESCRIPTION
 *  Updates roaming status
 * PARAMETERS
 *  is_roaming      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_update_roaming_status(unsigned long is_roaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL)
    {
        g_jmms_context->curr_roaming_state = (U32) is_roaming;
    }
}

#ifndef __MMI_UNIFIED_MESSAGE__
#define REFRESH_INBOX_TIMEOUT       1000


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_go_back_refresh_inbox
 * DESCRIPTION
 *  Used to go back to the previous screen after refereshinh Inbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_go_back_refresh_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_refresh_inbox
 * DESCRIPTION
 *  Used to stop timer for refresh inbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_refresh_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_refresh_inbox_no_screen_update
 * DESCRIPTION
 *  Used to refresh inbox with no screen update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_refresh_inbox_no_screen_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((IsScreenPresent(SCR_ID_JMMS_INBOX)) || (GetActiveScreenId() == SCR_ID_JMMS_INBOX))
    {
        g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_refresh_inbox
 * DESCRIPTION
 *  Used to refreah Inbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_refresh_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_refresh_inbox");
    mmi_jmms_refresh_inbox_no_screen_update();
    if (GetActiveScreenId() != SCR_ID_JMMS_INBOX)
    {
        return;
    }
    StartTimer(POPUP_TIMER, REFRESH_INBOX_TIMEOUT, mmi_jmms_go_back_refresh_inbox);
    EntryNewScreen(POPUP_SCREENID, mmi_jmms_exit_refresh_inbox, NULL, NULL);
    ShowCategory66Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_ID_JMMS_LOADING_MMS),
        IMG_ID_JMMS_PROGRESS,
        NULL);
    ClearAllKeyHandler();
}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef CORRUPT_MMS_HANDLING


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_corrupt_mms_notification
 * DESCRIPTION
 *  This function checks whether notification is corrupt or not
 * PARAMETERS
 *  view_content            [IN]        
 *  msg_handle              [IN]        
 *  notify_ind_hdrs_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_corrupt_mms_notification(
            CONTENT_DATA *view_content,
            MSG_HANDLE msg_handle,
            MESSAGE_NOTIFICATION *notify_ind_hdrs_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 msg_index;
    MESSAGE_HEADERS *msg_hdrs_p = NULL;
    JC_UINT32 screen_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%s", "mmi_jmms_is_corrupt_mms_notification",
                         "This function checks whether media is corrupt or not.");

    if (notify_ind_hdrs_p->pContentLocation == NULL || notify_ind_hdrs_p->pTransactionID == NULL ||
        notify_ind_hdrs_p->pVersion == NULL)
    {
        /* when we will receive a corrupt MMS notification then it will be stored in deffered mode
           and user will not be able to download the MMS */
        ret_code = mmi_jmms_notification_reponse(notify_ind_hdrs_p, E_MSG_DEFERRED);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms saving the notification into InBox return: %d", ret_code);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &msg_hdrs_p);
            if (JC_OK == ret_code)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms saving the notification into InBox");
                /* save notification in inbox. */
                ret_code = mmi_jmms_save_message_buffer_in_Store("Inbox", &msg_index, msg_hdrs_p, view_content, NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_set_msg_as_unread((U8) (msg_index - 1));
                }
                mmi_jmms_update_status_icon_indicator();

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s:%d", "save result", ret_code);
                if (ret_code == JC_OK)
                {
                    /* user should not be able to download or view this notification as it is corrupted */
                    screen_id = GetActiveScreenId();
                    if (screen_id && (!isInCall()) && (IsKeyPadLockState() == 0))
                    {
                        g_jmms_context->interupt_screen_title = STR_ID_JMMS_UNABLE_PARSE_PUSH;
                        mmi_jmms_entry_general_pop_screen_in_case_interupt();
                        PlayMessageArrivalTone();
                    }
                    else if ((!isInCall()) && IsKeyPadLockState())
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_UNABLE_PARSE_PUSH,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                        if (ret_code == JC_OK)
                        {
                            mmi_jmms_check_for_idle_screen();
                        }
                        TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
                        PlayMessageArrivalTone();
                    }
                    else
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_UNABLE_PARSE_PUSH,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                        if (ret_code == JC_OK)
                        {
                            mmi_jmms_check_for_idle_screen();
                        }
                    }
                #ifndef __MMI_UNIFIED_MESSAGE__
                    mmi_jmms_refresh_inbox_no_screen_update();
                #endif 
                }
                else
                {
                    if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    else
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
            }
            else
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
            }

        }
        return E_TRUE;
    }
    else
    {
        return E_FALSE;
    }

}
#endif /* CORRUPT_MMS_HANDLING */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_new_mms_notification
 * DESCRIPTION
 *  Used to handle new MMS notification
 * PARAMETERS
 *  view_content                [IN]        
 *  msg_handle                  [IN]        
 *  notify_ind_headers_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_new_mms_notification(
        CONTENT_DATA *view_content,
        MSG_HANDLE msg_handle,
        MESSAGE_NOTIFICATION *notify_ind_headers_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 roaming_status;
    U8 retrieval_mode;
    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 msg_index;
    MESSAGE_HEADERS *message_header_p = NULL;
    JC_UINT32 mms_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CORRUPT_MMS_HANDLING
    if (mmi_jmms_is_corrupt_mms_notification(view_content, msg_handle, notify_ind_headers_p) == E_TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Notification is corrupt");
        return;
    }
#endif /* CORRUPT_MMS_HANDLING */ 
    /* /check the retrival mnode */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_new_mms_notification");

    roaming_status = g_jmms_context->curr_roaming_state;
    if (roaming_status == 1)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Roaming status is 1.");
        if (E_ROAMING_RETRIEVAL_AS_HOME == (U16) mmi_jmms_retrieval_settings_roaming_retrieval_mode())
        {
            retrieval_mode = mmi_jmms_retrieval_settings_home_network_retrieval_mode();
        }
        else
        {
            retrieval_mode = mmi_jmms_retrieval_settings_roaming_retrieval_mode();
        }
    }
    else
    {
        retrieval_mode = mmi_jmms_retrieval_settings_home_network_retrieval_mode();
    }

    if (retrieval_mode == E_ROAMING_RETRIEVAL_RESTRICTED)   /* /E_ROAMING_RETRIEVAL_IMMEDAITE and E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE */
        /* have same values */
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms Retrival Mode: %s", "RETRIEVAL_RESTRICTED");
        ret_code = mmi_jmms_notification_reponse(notify_ind_headers_p, E_MSG_REJECTED);
        return;
    }
    if ((notify_ind_headers_p->eMsgClass == E_MSG_ADVERTISEMENT_CLASS &&
         E_REJECT == mmi_jmms_retrieval_settings_advertisment_filter()) || ((notify_ind_headers_p->pFrom == NULL) &&
                                                                            E_REJECT ==
                                                                            mmi_jmms_retrieval_settings_anonymous_filter
                                                                            ())
#ifdef __MMI_JMMS_NO_OMA_CONF_273__
        || (notify_ind_headers_p->uiMessageSize > mmi_jmms_retrieval_settings_msg_size_filter())
#endif 
        )
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms send the notification response with Reject Status");
        /* /send the notfication response with reject status */
        ret_code = mmi_jmms_notification_reponse(notify_ind_headers_p, E_MSG_REJECTED);
        return;
    }
#ifdef __MMI_JMMS_EXPIRY_HANDLING__
    if (mmi_jmms_check_notification_headers_expired(notify_ind_headers_p))
    {
        ret_code = mmi_jmms_notification_reponse(notify_ind_headers_p, E_MSG_EXPIRED);
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) STR_ID_JMMS_MMS_MSG_EXPIRED,
                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                    NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
        return;
    }
#endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 
#ifndef __MMI_JMMS_NO_OMA_CONF_273__
    if (notify_ind_headers_p->uiMessageSize > mmi_jmms_retrieval_settings_msg_size_filter())
    {
        retrieval_mode = E_ROAMING_RETRIEVAL_DEFFERED;
    }
#endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_jmms_check_usb_mode() == 1)
    {
        retrieval_mode = E_ROAMING_RETRIEVAL_DEFFERED;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (retrieval_mode == E_ROAMING_RETRIEVAL_IMMEDAITE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms retrival mode: %s", "RETRIEVAL_IMMEDAITE");
        ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &message_header_p);
        if (JC_OK == ret_code)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms saving the notification into InBox.");
            /* save notification in inbox. */
            ret_code = mmi_jmms_save_message_buffer_in_Store("Inbox", &(mms_index), message_header_p, view_content, NULL);
            if (ret_code == JC_OK)
            {
                mmi_jmms_set_msg_as_unread((U8) (mms_index - 1));
                ret_code = mmi_jmms_download_mms(notify_ind_headers_p->pContentLocation, E_TYPE_IMMEDIATE_RETRIEVAL_FETCH,
                                          mms_index, 1
            #ifdef __MMI_UNIFIED_COMPOSER__
                                          , NULL
            #endif 
                    );
            #ifdef __MMI_JMMS_NO_OMA_CONF_273__
                if (ret_code == E_MEMORY_FULL_ERROR)
                {
                    ret_code = mmi_jmms_notification_reponse(notify_ind_headers_p, E_MSG_DEFERRED);
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) mms_index,
                                (U8) E_MSG_TYPE_NOTIFICATION,
                                (S8*) notify_ind_headers_p->pContentLocation);
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_show_new_mms_pop_up();
                    }
                #ifndef __MMI_UNIFIED_MESSAGE__
                    mmi_jmms_refresh_inbox_no_screen_update();
                #endif 
                }
                else
            #endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 
                {
                #ifdef __MMI_UNIFIED_MESSAGE__
                    mmi_um_jmms_refresh_ind();
                #else 
                    mmi_jmms_refresh_inbox();
                #endif 
                }
                mmi_jmms_update_status_icon_indicator();
            }
            else
            {
                mms_index = 0;  /* it means notification didn't save successfully */
                if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                }
                else
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                }
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                return;
            }
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms fail to get the MMS Header %d", ret_code);
            ret_code = mmi_jmms_add_pending_mms_info_node(
                        (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                        (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                        NULL);
            if (ret_code == JC_OK)
            {
                mmi_jmms_check_for_idle_screen();
            }

        }
    }
    else if (retrieval_mode == E_ROAMING_RETRIEVAL_DEFFERED)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms Retrival Mode: %s", "RETRIEVAL_DEFFERED");
        ret_code = mmi_jmms_notification_reponse(notify_ind_headers_p, E_MSG_DEFERRED);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms saving the notification into InBox return: %d", ret_code);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &message_header_p);
            if (JC_OK == ret_code)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms saving the notification into InBox");
                /* save notification in inbox. */
                ret_code = mmi_jmms_save_message_buffer_in_Store("Inbox", &msg_index, message_header_p, view_content, NULL);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s:%d", "save result", ret_code);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_set_msg_as_unread((U8) (msg_index - 1));
                #ifdef __MMI_JATAAYU_MMS_DEFER_SILENT__
                #ifdef __MMI_UNIFIED_MESSAGE__
                    mmi_um_jmms_refresh_ind();
                #else 
                    mmi_jmms_refresh_inbox();
                #endif 
                    return;
                #endif /* __MMI_JATAAYU_MMS_DEFER_SILENT__ */ 
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) msg_index,
                                (U8) E_MSG_TYPE_NOTIFICATION,
                                (S8*) notify_ind_headers_p->pContentLocation);
                    if (ret_code == JC_OK)
                    {

                        mmi_jmms_show_new_mms_pop_up();
                    }
                #ifndef __MMI_UNIFIED_MESSAGE__
                    mmi_jmms_refresh_inbox_no_screen_update();
                #endif 
                    mmi_jmms_update_status_icon_indicator();
                }
                else
                {
                    if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    else
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms fail to get the MMS Header %d", ret_code);
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_ERROR_NEW_MMS_NOTIF_SAVING,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_download_mms
 * DESCRIPTION
 *  Used to download MMS
 * PARAMETERS
 *  content_location_p      [IN]        
 *  comm_state              [IN]        
 *  msg_index               [IN]        
 *  retry_counter           [IN]        
 *  communication_cb        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_download_mms(JC_INT8 *content_location_p, U16 comm_state, JC_UINT32 msg_index, U8 retry_counter
#ifdef __MMI_UNIFIED_COMPOSER__
                                 , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    COMM_FETCH_URL fetch_url_info = {0, };
    JC_UINT32 reference_id = 1;
    S8 *temp_url = NULL;
    S32 len = 0;
    S8 *mms_content_location_p = NULL;

#if defined(__MMI_JMMS_NO_OMA_CONF_273__) || defined (__MMI_JMMS_EXPIRY_HANDLING__)
    MESSAGE_NOTIFICATION *notification_p = NULL;
    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;
    JC_UINT64 free_space = 0;
#endif /* defined(__MMI_JMMS_NO_OMA_CONF_273__) || defined (__MMI_JMMS_EXPIRY_HANDLING__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_download_mms");

#if defined(__MMI_JMMS_NO_OMA_CONF_273__) || defined (__MMI_JMMS_EXPIRY_HANDLING__)
    store_ret_filter.uiStartIndex = msg_index;
    store_ret_filter.uiNumMessage = 1;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    ret_code = mmi_jmms_get_messages_list("Inbox", &message_list_p, &store_ret_filter);

    if (ret_code == JC_OK)
    {
        notification_p = (MESSAGE_NOTIFICATION*) (message_list_p->pMessageHeaders->pHeaders);
        /* expiry handling */
    #ifdef __MMI_JMMS_EXPIRY_HANDLING__
        if (mmi_jmms_check_notification_headers_expired(notification_p))
        {
            return E_MESSAGE_EXPIRED;
        }
    #endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 

        /* max size handling */
    #ifdef __MMI_JMMS_NO_OMA_CONF_273__
        free_space = jdd_FSGetMMSFolderFreeSpace();
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "free_space: ", free_space);

        if (notification_p->uiMessageSize > free_space)
        {
            mmi_jmms_update_status_icon_indicator();
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Returing E_MEMORY_FULL_ERROR");
            return E_MEMORY_FULL_ERROR;
        }
    #endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Error getting message list");
        return E_MEMORY_FULL_ERROR;
    }
#endif /* defined(__MMI_JMMS_NO_OMA_CONF_273__) || defined (__MMI_JMMS_EXPIRY_HANDLING__) */ 

    fetch_url_info.eContentMode = E_COMM_BUFFER;

    len = (strlen((S8*) content_location_p) + 1);

    /* adding for retry mechanism */
    mms_content_location_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
    if (mms_content_location_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    /* /commenitng for retry mechnaism */
    temp_url = (S8*) jdd_MemAlloc(sizeof(S8), len * ENCODING_LENGTH);
    if (temp_url == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }
    strcpy((char*)mms_content_location_p, (const char*)content_location_p);
    mmi_asc_to_ucs2((S8*) temp_url, (S8*) content_location_p);
    fetch_url_info.pszURL = (JC_CHAR*) temp_url;
    fetch_url_info.pszContentType = NULL;
    fetch_url_info.uUserDataMode.pucPostData = NULL;
    fetch_url_info.bIsFile = E_FALSE;
    fetch_url_info.uiPostLen = 0;
    fetch_url_info.eCommFetchType = E_COMM_FETCH_GET;
    fetch_url_info.pHeadersInfo = (COMM_HEADERS*) jdd_MemAlloc(sizeof(COMM_HEADERS), 1);
    if (fetch_url_info.pHeadersInfo == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }
    fetch_url_info.pHeadersInfo->pszName = "Accept";
    fetch_url_info.pHeadersInfo->psValue = "*/*";
    fetch_url_info.pHeadersInfo->uiValueSize = 3;
    fetch_url_info.pHeadersInfo->pszCharset = "utf-8";
    fetch_url_info.pHeadersInfo->pNext = NULL;
    if (strlen(mmi_jmms_get_mms_profile_user_name()) || strlen(mmi_jmms_get_mms_profile_password()))
    {
        fetch_url_info.pProxyAuthHeaders = (COMM_AUTH_HEADERS*) jdd_MemAlloc(sizeof(COMM_AUTH_HEADERS), 1);
        if (fetch_url_info.pProxyAuthHeaders == NULL)
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
        fetch_url_info.pProxyAuthHeaders->eAuthType = E_COMM_AUTHORIZATION_BASIC;
        mmi_asc_to_ucs2((S8*) fetch_url_info.pProxyAuthHeaders->szName, mmi_jmms_get_mms_profile_user_name());
        mmi_asc_to_ucs2((S8*) fetch_url_info.pProxyAuthHeaders->szPassword, mmi_jmms_get_mms_profile_password());
    }

    if (comm_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH)
    {
        /*
         * For deffered Retrieval need to use the g_jmms_context->reference_id variable beacuse downloading screen
         * is there and downloading can be cancelled. Also don't use this variable for Immediate Retrieval etc.
         * because during Sending/Defered Downlaod there can be immediate retrieval so this varaiable can be overwritten.
         * 
         * This variable is used during Sending/Deffered Downloading beacause Sending/Deffered Downlaoding can be 
         * cancelled by user and so we require this value in jdi_CommunicationStopReq().
         * Also there is no harm on using the same varaible for sending and deffered retrieval because sending and 
         * deffered retrieval cann't be both together.
         */
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms comm State: %s", "E_TYPE_DEFFERED_RETRIEVAL_FETCH");
        g_jmms_context->reference_id = 0;
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fetch_url_info, &g_jmms_context->reference_id);
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch Download", g_jmms_context->reference_id);

            ret_code = mmi_jmms_add_comm_node(g_jmms_context,
                                              g_jmms_context->reference_id,
                                              comm_state, NULL, msg_index, retry_counter, mms_content_location_p
        #ifdef __MMI_UNIFIED_COMPOSER__
                                              , communication_cb
        #endif 
                );

            if (ret_code != JC_OK)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to add comm node", ret_code);
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
                g_jmms_context->reference_id = 0;
                ret_code = JC_ERR_MEMORY_ALLOCATION;
            }
        }
    }
    else
    {
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fetch_url_info, &reference_id);
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch Download", reference_id);

            ret_code = mmi_jmms_add_comm_node(g_jmms_context,
                                              reference_id,
                                              comm_state, NULL, msg_index, retry_counter, mms_content_location_p
        #ifdef __MMI_UNIFIED_COMPOSER__
                                              , NULL
        #endif 
                );
            if (ret_code != JC_OK)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to add comm node", ret_code);
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, reference_id);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
            }
        }
    }

  END:
    if (temp_url != NULL)
    {
        jdd_MemFree(temp_url);
    }
    if (fetch_url_info.pHeadersInfo != NULL)
    {
        jdd_MemFree(fetch_url_info.pHeadersInfo);
    }

    if (fetch_url_info.pProxyAuthHeaders)
    {
        jdd_MemFree(fetch_url_info.pProxyAuthHeaders);
    }

    if (ret_code != JC_OK)
    {
        if (mms_content_location_p != NULL)
        {
            jdd_MemFree(mms_content_location_p);
        }
    }

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_notification_reponse
 * DESCRIPTION
 *  Usde to send notification response
 * PARAMETERS
 *  notification_p          [IN]        
 *  e_message_status        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_notification_reponse(MESSAGE_NOTIFICATION *notification_p, EMessageStatus e_message_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    NOTIFICATION_RESPONSE *notification_header_p = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MSG_HANDLE mms_signal_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_notification_reponse");

    if (notification_p == NULL || notification_p->pTransactionID == NULL || notification_p->pVersion == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }
    ret_code = mmi_jmms_jdi_msg_init(&mms_signal_handle, NULL);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms msg Initialization Failed", ret_code);
        goto ERROR_HANDLE;
    }
    msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);
    if (msg_headers_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    ret_code = mmi_jmms_jdi_set_msg_headers(mms_signal_handle, msg_headers_p);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to set the message header", ret_code);
        goto ERROR_HANDLE;
    }
    notification_header_p = (NOTIFICATION_RESPONSE*) jdd_MemAlloc(sizeof(NOTIFICATION_RESPONSE), 1);
    if (notification_header_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    notification_header_p->pVersion = (JC_INT8*) jdi_UtilsStrdup(notification_p->pVersion);
    notification_header_p->pTransactionID = jdi_UtilsStrdup(notification_p->pTransactionID);
    notification_header_p->eMessageStatus = e_message_status;
    notification_header_p->bDeliveryReport = (JC_BOOLEAN) mmi_jmms_retrieval_settings_delivery_report();
    msg_headers_p->eMsgType = E_MSG_TYPE_NOTIFICATION_RESPONSE;
    msg_headers_p->pHeaders = notification_header_p;

    ret_code = mmi_jmms_jdi_set_msg_headers(mms_signal_handle, msg_headers_p);
    if (JC_OK != ret_code)
    {
        goto ERROR_HANDLE;
    }

    ret_code = mmi_jmms_send_mms(mms_signal_handle, E_TYPE_NOTIFICATION_RESPONSE, E_TRUE, 1, E_FALSE
#ifdef __MMI_UNIFIED_COMPOSER__
                                 , NULL
#endif 
        );

  ERROR_HANDLE:
    if (mms_signal_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  jmms_mmi_notification_response_for_immediate_retrieval
 * DESCRIPTION
 *  Used to send notification response for immediate retrival
 * PARAMETERS
 *  view_content        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE jmms_mmi_notification_response_for_immediate_retrieval(CONTENT_DATA view_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    NOTIFICATION_RESPONSE *notification_header_p = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_RETRIEVAL *notify_ind_headers_p = NULL;
    MSG_HANDLE mms_signal_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms_mmi_notification_response_for_immediate_retrieval");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&mms_signal_handle, &view_content, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(mms_signal_handle);
    }
    /* Async changes end */

    if (JC_OK != ret_code && mms_signal_handle != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms error in parsing", ret_code);
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
        return ret_code;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(mms_signal_handle, &msg_headers_p);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to get the message header", ret_code);
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
        return ret_code;
    }

    if (msg_headers_p->eMsgType != E_MSG_TYPE_RECEIVE)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
        return E_UNKNOWN_MSG;
    }
    notify_ind_headers_p = (MESSAGE_RETRIEVAL*) msg_headers_p->pHeaders;

    if (notify_ind_headers_p == NULL || notify_ind_headers_p->pTransactionID == NULL ||
        notify_ind_headers_p->pVersion == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }
    notification_header_p = (NOTIFICATION_RESPONSE*) jdd_MemAlloc(sizeof(NOTIFICATION_RESPONSE), 1);
    if (notification_header_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    notification_header_p->pVersion = jdi_UtilsStrdup(notify_ind_headers_p->pVersion);
    notification_header_p->pTransactionID = jdi_UtilsStrdup(notify_ind_headers_p->pTransactionID);
    notification_header_p->eMessageStatus = E_MSG_RETRIEVED;
    notification_header_p->bDeliveryReport = (JC_BOOLEAN) mmi_jmms_retrieval_settings_delivery_report();

    if (NULL != mms_signal_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
    }
    ret_code = mmi_jmms_jdi_msg_init(&mms_signal_handle, NULL);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms msg Initialization Failed", ret_code);
        mms_signal_handle = NULL;
        goto ERROR_HANDLE;
    }
    msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);
    if (msg_headers_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    msg_headers_p->eMsgType = E_MSG_TYPE_NOTIFICATION_RESPONSE;
    msg_headers_p->pHeaders = notification_header_p;

    ret_code = mmi_jmms_jdi_set_msg_headers(mms_signal_handle, msg_headers_p);
    if (JC_OK != ret_code)
    {
        goto ERROR_HANDLE;
    }

    ret_code = mmi_jmms_send_mms(mms_signal_handle, E_TYPE_NOTIFICATION_RESPONSE, E_TRUE, 1, E_FALSE
#ifdef __MMI_UNIFIED_COMPOSER__
                                 , NULL
#endif 
        );

  ERROR_HANDLE:
    if (mms_signal_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d",
                         "jmms mms_mmi_notification_response_for_immediate_retrieval return value: ", ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_show_mms_screen
 * DESCRIPTION
 *  Used to show MMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_show_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer; /* Buffer holding history data */
    S8 temp[14];
    U8 dttemp[40];
    MYTIME time1, time;
    FLOAT timezone;
    S32 len_to_copy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_show_mms_screen");
    timezone = mmi_dt_get_tz();
    EntryNewScreen(SCR_ID_JMMS_NEW_MMS, mmi_jmms_common_exit_property_screen, mmi_jmms_entry_show_mms_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_JMMS_NEW_MMS);

    g_jmms_context->property_display_buffer_p =
        (U8*) jdd_MemAlloc(
                sizeof(U8),
                (MAX_BUFFER_SIZE_FOR_PROPERTY + 1 + (MAX_NO_OF_ALLOWABLE_ADDRESSES * MAX_POSSIBLE_EMAIL_LENGHT_SENT)) * ENCODING_LENGTH);
    if (g_jmms_context->property_display_buffer_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
        return;
    }

    mmi_ucs2cpy((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_FROM));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pFrom == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pFrom,
            MAX_POSSIBLE_NUMBER_LENGHT_SENT,
            MAX_POSSIBLE_EMAIL_LENGHT_SENT);
    }

    /* /TO */
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_TO));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pTo == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pTo,
            MAX_POSSIBLE_NUMBER_LENGHT_SENT,
            MAX_POSSIBLE_EMAIL_LENGHT_SENT);
    }

    /* /CC */
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_CC));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pCc == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pCc,
            MAX_POSSIBLE_NUMBER_LENGHT_SENT,
            MAX_POSSIBLE_EMAIL_LENGHT_SENT);
    }

    /* /Subject */
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_SUBJECT));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pSubject == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        len_to_copy = mmi_ucs2strlen((S8*) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pSubject);
        if (len_to_copy > MAX_SUBJECT_LENGTH)
        {
            len_to_copy = MAX_SUBJECT_LENGTH;
        }
        mmi_ucs2ncat(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->pSubject,
            len_to_copy);
    }

    /* /Date */
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_DATE));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    mmi_dt_utc_sec_2_mytime((U32) ((MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p)->uiDate, &time1, MMI_TRUE);
    mmi_dt_utc_to_rtc(timezone, time1, time);

    /* PMT RAJ KUMAR GUPTA on Sep 05, 2006 */
    /* Date */
    memset(dttemp, 0x00, 40);
    date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);

    memset(temp, 0x00, 6);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    /* Time */
    memset(dttemp, 0x00, 40);
    time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);
    /* END of Changes - RAJ KUMAR GUPTA */

    ShowCategory78Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_ID_JMMS_PLAY,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) g_jmms_context->property_display_buffer_p,
        mmi_ucs2strlen((S8*) g_jmms_context->property_display_buffer_p),
        gui_buffer);

    SetRightSoftkeyFunction(mmi_jmms_back_msg_view_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_msg_view_entry, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_jmms_play_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_play_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_play_mms, KEY_WAP, KEY_EVENT_DOWN);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_end_mms_play, KEY_END, KEY_EVENT_DOWN);
    }

    DeleteScreenIfPresent(SCR_ID_JMMS_READ_REPORT_QUERY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_end_mms_play
 * DESCRIPTION
 *  Used to end MMS play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_end_mms_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_end_mms_play");

    mmi_jmms_deinit_mms_context(g_jmms_context);

    mmi_jmms_free_delivery_report_header();
    mmi_jmms_free_report_report_header();

    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_play_mms
 * DESCRIPTION
 *  Used to play MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_play_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    CONTENT_DATA content = {0, };
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_play_mms");

    mmi_jmms_deinit_mms_context(g_jmms_context);

    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message("Inbox", &content, g_jmms_context->mms_index);

    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to get the message from InBox.", ret_code);
        mmi_jmms_error_handler(ret_code);
        goto END;

    }
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_view();
#endif 
    ret_code = mmi_jmms_pre_entry_mms_view(&content);
    if (g_jmms_context->last_scr_id != IDLE_SCREEN_ID && g_jmms_context->last_scr_id == SCR_ID_JMMS_INBOX_OPTIONS)
    {
        /* it means download from Inbox */
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
    #else 
        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
    #endif 
    }

    DeleteScreenIfPresent(SCR_ID_JMMS_READ_REPORT_QUERY);
    DeleteScreenIfPresent(SCR_ID_JMMS_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_JMMS_POP_SCREEN);
    DeleteScreenIfPresent(SCR_ID_JMMS_INBOX_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
    DeleteScreenIfPresent(SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES);

    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        return;
    }

  END:

    if (ret_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_back_msg_view_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_back_msg_view_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);
    mmi_jmms_free_delivery_report_header();
    mmi_jmms_free_report_report_header();

    if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
    {
        DisplayIdleScreen();
    }
    else
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
        GoBackToHistory(SCR_ID_UM_INBOX);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        GoBackToHistory(SCR_ID_JMMS_INBOX);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_need_mms_ind
 * DESCRIPTION
 *  Used to check if the new MMS need indication or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jmms_need_mms_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 need_ind = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_UNIFIED_MESSAGE__) && defined (__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode() == KAL_FALSE)
#endif 
    {
        if (g_jmms_context != NULL && g_jmms_context->pending_mms_info_list != NULL)
    #ifdef __MMI_UNIFIED_MESSAGE__
            if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP
    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
                || g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER
    #endif 
                )
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            {
                need_ind = 1;
            }
    }

    return need_ind;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_new_mms_ind
 * DESCRIPTION
 *  Uesd to pop new MMS or error string pop up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_new_mms_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_new_mms_ind");

    if (g_jmms_context == NULL)
    {
        g_jmms_context = (mmi_jmms_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_context_struct), 1);
        if (g_jmms_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
    }

    if (g_jmms_context->pending_mms_info_list == NULL)
    {
        return;
    }

    EntryNewScreen(SCR_ID_JMMS_NEW_MMS_IND, NULL, NULL, NULL);
    /*
     * sandeep start in error situations like when fail to save mms notification ring tone should not play
     * // amit start
     * PlayMessageArrivalTone();
     * // amit end tone play on idle screen
     */

    GetCurrEndKeyDownHandler();

    if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_DELIVERY_REPORT
        || g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_READ_REPORT_RESPONSE
        || g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_RECEIVE)
    {
        strid = STR_ID_JMMS_READ_NEW_MMS;
    }
    else if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_NOTIFICATION)
    {
        strid = STR_ID_JMMS_DOWNLOAD_NEW_MMS;

    }
    else if (g_jmms_context->pending_mms_info_list->type != E_MSG_TYPE_IDLE_SCREEN_POP_UP
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
             && g_jmms_context->pending_mms_info_list->type != E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER
#endif 
        )
    {
        return;
    }
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->pending_mms_info_list->type != E_MSG_TYPE_IDLE_SCREEN_POP_UP
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
        && g_jmms_context->pending_mms_info_list->type != E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER
#endif 
        )
    {
        mmi_um_jmms_new_mms_message_ind(g_jmms_context->pending_mms_info_list->index);
    }
    else
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
        if (IsKeyPadLockState() == 0)
        {

            if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP)
            {

                ShowCategory2Screen(
                    STR_MMS_MENUENTRY,
                    GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    g_jmms_context->pending_mms_info_list->index,
                    NULL);
                SetRightSoftkeyFunction(mmi_jmms_delete_mms_pop_up_node, KEY_EVENT_UP);
                if (isInCall() == FALSE)
                {
                    SetKeyHandler(mmi_jmms_free_mms_pop_ups_list, KEY_END, KEY_EVENT_DOWN);     /* /delete the link list */
                }
            }
        #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
            else if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER)
            {
                ShowCategory7Screen(
                    STR_MMS_MENUENTRY,
                    GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*) g_jmms_context->pending_mms_info_list->mms_url_p,
                    NULL);
                SetRightSoftkeyFunction(mmi_jmms_delete_mms_pop_up_node, KEY_EVENT_UP);
                if (isInCall() == FALSE)
                {
                    SetKeyHandler(mmi_jmms_free_mms_pop_ups_list, KEY_END, KEY_EVENT_DOWN);     /* /delete the link list */
                }

            }
        #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
            else
            {
                ShowCategory154Screen(
                    0,
                    0,
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    (PU8) GetString(strid),
                    NULL,
                    IMG_ID_JMMS_NEW_MESSAGE_NOTIFICATION_MSG,
                    NULL);
                SetRightSoftkeyFunction(mmi_jmms_delete_mms_pop_up_node, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(mmi_jmms_handle_mms_pop_up, KEY_EVENT_UP);
                if (isInCall() == FALSE)
                {
                    SetKeyHandler(mmi_jmms_free_mms_pop_ups_list, KEY_END, KEY_EVENT_DOWN);     /* /delete the link list */
                }
            }
        }
        else    /* keypad is locked */
        {

            if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP)
            {
                ShowCategory2Screen(
                    STR_MMS_MENUENTRY,
                    GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    g_jmms_context->pending_mms_info_list->index,
                    NULL);
            }
        #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
            else if (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER)
            {
                ShowCategory7Screen(
                    STR_MMS_MENUENTRY,
                    GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*) g_jmms_context->pending_mms_info_list->mms_url_p,
                    NULL);
                SetRightSoftkeyFunction(mmi_jmms_delete_mms_pop_up_node, KEY_EVENT_UP);
                if (isInCall() == FALSE)
                {
                    SetKeyHandler(mmi_jmms_free_mms_pop_ups_list, KEY_END, KEY_EVENT_DOWN);     /* /delete the link list */
                }

            }
        #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
            else
            {
                ShowCategory154Screen(
                    0,
                    0,
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    (PU8) GetString(strid),
                    NULL,
                    IMG_ID_JMMS_NEW_MESSAGE_NOTIFICATION_MSG,
                    NULL);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_mms_pop_up_node
 * DESCRIPTION
 *  Deletes MMS pop up node.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_mms_pop_up_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_pending_mms_info_struct *node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_delete_mms_pop_up_node");

    node_p = g_jmms_context->pending_mms_info_list;

    if (node_p == NULL)
    {
        GoBackToHistory(IDLE_SCREEN_ID);
        return;
    }

    if (node_p->type == E_MSG_TYPE_DELIVERY_REPORT)
    {
        mmi_jmms_pending_mms_delivery_reports_struct *node1 = NULL;

        if (g_jmms_context->pending_delivery_reports != NULL)
        {

            node1 = g_jmms_context->pending_delivery_reports->next_p;
            if (g_jmms_context->pending_delivery_reports->to_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_delivery_reports->to_p);
            }
            jdd_MemFree(g_jmms_context->pending_delivery_reports);
            g_jmms_context->pending_delivery_reports = node1;
        }
    }
    else if (node_p->type == E_MSG_TYPE_READ_REPORT_RESPONSE)
    {
        mmi_jmms_pending_mms_read_reports_struct *node1 = NULL;

        if (g_jmms_context->pending_read_reports != NULL)
        {

            node1 = g_jmms_context->pending_read_reports->next_p;
            if (g_jmms_context->pending_read_reports->from_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_read_reports->from_p);
            }
            jdd_MemFree(g_jmms_context->pending_read_reports);
            g_jmms_context->pending_read_reports = node1;
        }
    }

    g_jmms_context->pending_mms_info_list = node_p->next_p;
    if (node_p->mms_url_p != NULL)
    {
        jdd_MemFree(node_p->mms_url_p);
    }

    jdd_MemFree(node_p);
    node_p = NULL;

    GoBackToHistory(IDLE_SCREEN_ID);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_mms_pop_up
 * DESCRIPTION
 *  this function handles the click on MMS pop up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_mms_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_pending_mms_info_struct *node_p = NULL;

    JC_RETCODE ret_code = JC_OK;
    JC_INT32 index = 0;
    CONTENT_DATA content = {0, };

    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_mms_pop_up");

    node_p = g_jmms_context->pending_mms_info_list->next_p;

    index = (JC_INT32) g_jmms_context->pending_mms_info_list->index;
    type = g_jmms_context->pending_mms_info_list->type;

    ///set the msg status as open for At Delete
    ///It will reset on going to idle screen
    g_jmms_context->msg_open_status[0] = E_JMMS_INBOX;
    /* PMT HIMANSHU START 20060425 */
    g_jmms_context->msg_open_status[1] = (U32) mmi_jmms_get_message_id(MMI_JMMS_INBOX, index);
    /* PMT HIMANSHU END 20060425 */

    switch (type)
    {
        case E_MSG_TYPE_NOTIFICATION:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms msg type: %s", "E_MSG_TYPE_NOTIFICATION");
            if (g_jmms_context->pending_mms_info_list->mms_url_p == NULL)
            {

                jdd_MemFree(g_jmms_context->pending_mms_info_list);
                g_jmms_context->pending_mms_info_list = NULL;

                g_jmms_context->pending_mms_info_list = node_p;
                return;
            }

            ret_code = mmi_jmms_download_mms((JC_INT8*) g_jmms_context->pending_mms_info_list->mms_url_p,
                                             E_TYPE_DEFFERED_RETRIEVAL_FETCH, index, 1
        #ifdef __MMI_UNIFIED_COMPOSER__
                                             , mmi_jmms_handle_screen_flow_callback
        #endif 
                );
            if (ret_code == JC_OK)
            {
                g_jmms_context->last_scr_id = IDLE_SCREEN_ID;
                mmi_jmms_set_progress_screen_title(STR_ID_JMMS_MMS_DOWNLOADING);
                memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
                mmi_jmms_entry_communication_progress_screen();
            }

        #ifdef __MMI_JMMS_EXPIRY_HANDLING__
            else if (ret_code == E_MESSAGE_EXPIRED)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_MMS_MSG_EXPIRED),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
            }
        #endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 

        #ifdef __MMI_JMMS_NO_OMA_CONF_273__
            else if (ret_code == E_MEMORY_FULL_ERROR)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_MMS_SIZE_EXCEEDS),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
            }
        #endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 

            mmi_jmms_free_pending_mms_info_node();

            g_jmms_context->pending_mms_info_list = node_p;

            return;
        }

        case E_MSG_TYPE_DELIVERY_REPORT:
        {
            mmi_jmms_pending_mms_delivery_reports_struct *node1 = NULL;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms msg type: %s", "E_MSG_TYPE_DELIVERY_REPORT");
            if (g_jmms_context->pending_delivery_reports == NULL)
            {
                /* no delivery report node present */
                mmi_jmms_free_pending_mms_info_node();
                g_jmms_context->pending_mms_info_list = node_p;
                return;
            }

            g_jmms_context->last_scr_id = IDLE_SCREEN_ID;

            ret_code = mmi_jmms_create_delivery_report_header_for_idle_screen(g_jmms_context->pending_delivery_reports);
            if (ret_code != JC_OK)
            {
                mmi_jmms_error_handler(ret_code);
            }
            else
            {
                /* /for setting read status */
                mmi_jmms_set_msg_as_read((U8) (index - 1));
                mmi_jmms_entry_show_delivery_report_screen();

            }

            /* /free the delivery report node */
            node1 = g_jmms_context->pending_delivery_reports->next_p;
            if (g_jmms_context->pending_delivery_reports->to_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_delivery_reports->to_p);
            }
            jdd_MemFree(g_jmms_context->pending_delivery_reports);
            g_jmms_context->pending_delivery_reports = node1;

            /* free the node for general message */
            mmi_jmms_free_pending_mms_info_node();
            g_jmms_context->pending_mms_info_list = node_p;

            return;
        }
        case E_MSG_TYPE_READ_REPORT_RESPONSE:
        {
            mmi_jmms_pending_mms_read_reports_struct *node1 = NULL;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms msg type: %s", "E_MSG_TYPE_READ_REPORT_RESPONSE");
            if (g_jmms_context->pending_read_reports == NULL)
            {
                //no report report node present
                //free the node for general message
                mmi_jmms_free_pending_mms_info_node();
                g_jmms_context->pending_mms_info_list = node_p;
                return;
            }

            g_jmms_context->last_scr_id = IDLE_SCREEN_ID;

            ret_code = mmi_jmms_create_read_report_header_for_idle_screen(g_jmms_context->pending_read_reports);
            if (ret_code != JC_OK)
            {
                mmi_jmms_error_handler(ret_code);
            }
            else
            {
                /* /for setting read status */
                mmi_jmms_set_msg_as_read((U8) (index - 1));
                mmi_jmms_entry_show_read_report_screen();
            }

            /* /free the read report node */
            node1 = g_jmms_context->pending_read_reports->next_p;
            if (g_jmms_context->pending_read_reports->from_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_read_reports->from_p);
            }
            jdd_MemFree(g_jmms_context->pending_read_reports);
            g_jmms_context->pending_read_reports = node1;

            /* free the node for general message */
            mmi_jmms_free_pending_mms_info_node();
            g_jmms_context->pending_mms_info_list = node_p;

            return;

        }

    }   /* /switch(type) */

    mmi_jmms_free_pending_mms_info_node();

    g_jmms_context->pending_mms_info_list = node_p;

    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message("Inbox", &content, index);

    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to get messages from InBox.", ret_code);
        DisplayPopup((PU8) GetString(STR_ID_JMMS_ERROR_GET_MSG_LIST), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        goto END;
    }

    mmi_jmms_deinit_mms_context(g_jmms_context);

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&g_jmms_context->msg_handle, &content, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(g_jmms_context->msg_handle);
    }
    /* Async changes end */

    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms parsing failed!", ret_code);
        if (g_jmms_context->msg_handle != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Deinitializing the msg header.");
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }
        goto END;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, (MESSAGE_HEADERS **) (&g_jmms_context->msg_headers_p));
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to get the msg header", ret_code);
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
        goto END;
    }

    switch (((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->eMsgType)
    {

        case E_MSG_TYPE_RECEIVE:
        {
            g_jmms_context->msg_header_type_p =
                (MESSAGE_RETRIEVAL*) ((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->pHeaders;

            /* /for setting read status */
            mmi_jmms_set_msg_as_read((U8) (index - 1));

            g_jmms_context->mms_index = index;

            g_jmms_context->last_scr_id = IDLE_SCREEN_ID;

            g_jmms_context->is_unread_msg_deleted = 0;

        #ifdef __MMI_UNIFIED_MESSAGE__
            g_jmms_context->show_property_screen = MMI_FALSE;
        #endif 
            mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);
            break;
        }

        default:
            break;
    }

    if (content.pFileName != NULL)
    {
        jdd_MemFree(content.pFileName);
        content.pFileName = NULL;
    }
    return;

  END:
    if (content.pFileName != NULL)
    {
        jdd_MemFree(content.pFileName);
        content.pFileName = NULL;
    }

    /* GoBackToHistory(IDLE_SCREEN_ID); */
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_read_report_header_for_idle_screen
 * DESCRIPTION
 *  this function is used to create header for read report
 * PARAMETERS
 *  read_report_header      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_create_read_report_header_for_idle_screen(
            mmi_jmms_pending_mms_read_reports_struct *read_report_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    READ_REPORT_RESPONSE *read_report_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_read_report_header_for_idle_screen");

    read_report_p = (READ_REPORT_RESPONSE*) jdd_MemAlloc(sizeof(READ_REPORT_RESPONSE), 1);
    if (read_report_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    read_report_p->eReadStatus = read_report_header->status;

    if (read_report_header->from_p != NULL)
    {
        read_report_p->pFrom =
            (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), jc_tcslen((JC_CHAR*) (read_report_header->from_p)) + 1);
        if (read_report_p->pFrom == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        jc_tcscpy(read_report_p->pFrom, (JC_CHAR*) (read_report_header->from_p));
    }

    read_report_p->uiReceivedTime = read_report_header->date;

    g_jmms_context->read_report_p = (READ_REPORT_RESPONSE*) (read_report_p);

  ERROR_HANDLE:

    if (ret_code != JC_OK && read_report_p != NULL)
    {
        mmi_jmms_free_report_report_header();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_create_read_report_header_for_idle_screen Return value",
                         ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_delivery_report_header_for_idle_screen
 * DESCRIPTION
 *  this function is used to create header for dilvery report.
 * PARAMETERS
 *  delivery_header     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_create_delivery_report_header_for_idle_screen(
            mmi_jmms_pending_mms_delivery_reports_struct *delivery_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DELIVERY_REPORT *delivery_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_delivery_report_header_for_idle_screen");

    mmi_jmms_free_delivery_report_header();

    delivery_p = (DELIVERY_REPORT*) jdd_MemAlloc(sizeof(DELIVERY_REPORT), 1);
    if (delivery_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (delivery_header->to_p != NULL)
    {
        delivery_p->pTo = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), jc_tcslen((JC_CHAR*) (delivery_header->to_p)) + 1);
        if (delivery_p->pTo == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        jc_tcscpy(delivery_p->pTo, (JC_CHAR*) (delivery_header->to_p));
    }

    delivery_p->eDeliveryStatus = delivery_header->status;

    delivery_p->uiDate = delivery_header->date;

    g_jmms_context->delivery_p = (DELIVERY_REPORT*) (delivery_p);

  ERROR_HANDLE:

    if (ret_code != JC_OK && delivery_p != NULL)
    {
        mmi_jmms_free_delivery_report_header();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)",
                         "mmi_jmms_create_delivery_report_header_for_idle_screen Return value", ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_read_report
 * DESCRIPTION
 *  This function is used to handle whether to send the read report or not.
 * PARAMETERS
 *  msg_retrival        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_read_report(MESSAGE_RETRIEVAL *msg_retrival)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 read_report_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060401 */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_read_report");

    mmi_jmms_update_status_icon_indicator();
    /* PMT VIKAS END 20060401 */
    if (msg_retrival->bReadReport == MMI_TRUE)
    {
        read_report_status = mmi_jmms_retrieval_settings_read_report();
        switch (read_report_status)
        {
            case E_READ_REPORT_SEND_ON_REQUEST:
                playRequestedTone(WARNING_TONE);
                mmi_jmms_show_read_report_query_screen();
                break;
            case E_READ_REPORT_SEND_ALWAYS:
        #ifdef __MMI_UNIFIED_MESSAGE__
                if (g_jmms_context->show_property_screen == MMI_FALSE)
                {
                    mmi_jmms_create_and_send_read_report();
                    if (g_jmms_context->is_unread_msg_deleted == 0)
                    {
                        mmi_jmms_play_mms();
                    }
                }
                else
                {
                    if (g_jmms_context->is_unread_msg_deleted == 0)
                    {
                        mmi_jmms_entry_show_mms_screen();
                    }
                    mmi_jmms_create_and_send_read_report();
                }
        #else /* __MMI_UNIFIED_MESSAGE__ */ 
                if (g_jmms_context->is_unread_msg_deleted == 0)
                {
                    mmi_jmms_entry_show_mms_screen();
                }
                mmi_jmms_create_and_send_read_report();
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                break;
            case E_READ_REPORT_SEND_NEVER:
            #ifdef __MMI_UNIFIED_MESSAGE__
                if (g_jmms_context->show_property_screen == MMI_FALSE)
                {
                    mmi_jmms_play_mms();
                }
                else
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                if (g_jmms_context->is_unread_msg_deleted == 0)
                {
                    mmi_jmms_entry_show_mms_screen();
                }
                break;
        }
    }
    else
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (g_jmms_context->show_property_screen == MMI_FALSE && g_jmms_context->is_unread_msg_deleted == 0)
        {
            mmi_jmms_play_mms();
        }
        else
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

        if (g_jmms_context->is_unread_msg_deleted == 0)
        {
            mmi_jmms_entry_show_mms_screen();
        }
    }

    DeleteScreenIfPresent(SCR_ID_JMMS_POP_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_read_report_query_screen
 * DESCRIPTION
 *  this function shows read report query screen to user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_read_report_query_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_show_read_report_query_screen");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_JMMS_READ_REPORT_QUERY);
    EntryNewScreen(
        SCR_ID_JMMS_READ_REPORT_QUERY,
        mmi_jmms_exit_read_report_query_screen,
        mmi_jmms_show_read_report_query_screen,
        NULL);

    ShowCategory154Screen(
        0,
        0,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) GetString(STR_ID_JMMS_READ_REPORT_REQUEST),
        NULL,
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_jmms_handle_read_report_confirm, KEY_EVENT_UP);
    if (g_jmms_context->is_unread_msg_deleted == 0)
    {
        SetRightSoftkeyFunction(mmi_jmms_entry_show_mms_screen, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_end_mms_play, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_read_report_query_screen
 * DESCRIPTION
 *  Exit fn for read report query confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_read_report_query_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_read_report_confirm
 * DESCRIPTION
 *  This function is used to confirm that if user wants to send read report or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_read_report_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->show_property_screen == MMI_FALSE)
    {
        mmi_jmms_create_and_send_read_report();
        if (g_jmms_context->is_unread_msg_deleted == 0)
        {
            mmi_jmms_play_mms();
        }
    }
    else
    {
        if (g_jmms_context->is_unread_msg_deleted == 0)
        {
            mmi_jmms_entry_show_mms_screen();
        }
        else
        {
            GoBackHistory();
        }
        mmi_jmms_create_and_send_read_report();
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (g_jmms_context->is_unread_msg_deleted == 0)
    {
        mmi_jmms_entry_show_mms_screen();
    }
    else
    {
        GoBackHistory();
    }

    mmi_jmms_create_and_send_read_report();
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_pending_mms_info_node
 * DESCRIPTION
 *  this function is used to free pending MMS nodes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_pending_mms_info_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_free_pending_mms_info_node");

    if (g_jmms_context->pending_mms_info_list->mms_url_p != NULL)
    {
        jdd_MemFree(g_jmms_context->pending_mms_info_list->mms_url_p);
    }
    jdd_MemFree(g_jmms_context->pending_mms_info_list);
    g_jmms_context->pending_mms_info_list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_mms_pop_ups_list
 * DESCRIPTION
 *  this function is used to free MMS pop up list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_mms_pop_ups_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_mms_pop_ups_list();
    GoBackToHistory(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_mms_pop_ups_list
 * DESCRIPTION
 *  this function is used to delete MMS pop up list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_mms_pop_ups_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_delete_mms_pop_ups_list");

    if (g_jmms_context->pending_delivery_reports != NULL)
    {
        mmi_jmms_pending_mms_delivery_reports_struct *node1 = NULL;

        do
        {
            node1 = g_jmms_context->pending_delivery_reports->next_p;
            if (g_jmms_context->pending_delivery_reports->to_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_delivery_reports->to_p);
            }
            jdd_MemFree(g_jmms_context->pending_delivery_reports);
            g_jmms_context->pending_delivery_reports = node1;
        } while (node1 != NULL);
    }

    /* free all read reports nodes */
    if (g_jmms_context->pending_read_reports != NULL)
    {
        mmi_jmms_pending_mms_read_reports_struct *node1 = NULL;

        do
        {
            node1 = g_jmms_context->pending_read_reports->next_p;
            if (g_jmms_context->pending_read_reports->from_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_read_reports->from_p);
            }
            jdd_MemFree(g_jmms_context->pending_read_reports);
            g_jmms_context->pending_read_reports = node1;
        } while (node1 != NULL);
    }

    /* free all general mesage nodes */
    if (g_jmms_context->pending_mms_info_list != NULL)
    {
        mmi_jmms_pending_mms_info_struct *node1 = NULL;

        do
        {
            node1 = g_jmms_context->pending_mms_info_list->next_p;

            if (g_jmms_context->pending_mms_info_list->mms_url_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_mms_info_list->mms_url_p);
            }
            jdd_MemFree(g_jmms_context->pending_mms_info_list);
            g_jmms_context->pending_mms_info_list = node1;
        } while (node1 != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry
 * DESCRIPTION
 *  this function deletes MMS pop ups on inbox entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry");

    if (g_jmms_context->pending_delivery_reports != NULL)
    {
        mmi_jmms_pending_mms_delivery_reports_struct *node1 = NULL;

        do
        {
            node1 = g_jmms_context->pending_delivery_reports->next_p;
            if (g_jmms_context->pending_delivery_reports->to_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_delivery_reports->to_p);
            }
            jdd_MemFree(g_jmms_context->pending_delivery_reports);
            g_jmms_context->pending_delivery_reports = node1;
        } while (node1 != NULL);
    }

    /* free all read reports nodes */
    if (g_jmms_context->pending_read_reports != NULL)
    {
        mmi_jmms_pending_mms_read_reports_struct *node1 = NULL;

        do
        {
            node1 = g_jmms_context->pending_read_reports->next_p;
            if (g_jmms_context->pending_read_reports->from_p != NULL)
            {
                jdd_MemFree(g_jmms_context->pending_read_reports->from_p);
            }
            jdd_MemFree(g_jmms_context->pending_read_reports);
            g_jmms_context->pending_read_reports = node1;
        } while (node1 != NULL);
    }

    /* free all general mesage nodes except E_MSG_TYPE_IDLE_SCREEN_POP_UP */
    if (g_jmms_context->pending_mms_info_list != NULL)
    {
        mmi_jmms_pending_mms_info_struct *node_p = NULL;
        mmi_jmms_pending_mms_info_struct *pre_node = NULL;

        node_p = g_jmms_context->pending_mms_info_list;
        pre_node = node_p;

        while (node_p != NULL)
        {
            if (node_p->type != E_MSG_TYPE_IDLE_SCREEN_POP_UP)
            {
                mmi_jmms_pending_mms_info_struct *next_node = NULL;

                next_node = node_p->next_p;
                if (g_jmms_context->pending_mms_info_list == node_p)
                {
                    g_jmms_context->pending_mms_info_list = next_node;
                    pre_node = next_node;
                }
                else
                {
                    pre_node->next_p = node_p->next_p;
                }

                if (node_p->mms_url_p != NULL)
                {
                    jdd_MemFree(node_p->mms_url_p);
                }
                jdd_MemFree(node_p);
                node_p = next_node;
            }
            else
            {
                pre_node = node_p;
                node_p = node_p->next_p;
            }

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_show_read_report_screen
 * DESCRIPTION
 *  This function show screen for the read report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_show_read_report_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer; /* Buffer holding history data */
    S8 temp[14];
    U8 dttemp[40];
    MYTIME time;
    FLOAT timezone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_show_read_report_screen");

    timezone = mmi_dt_get_tz();
    EntryNewScreen(
        SCR_ID_JMMS_NEW_MMS,
        mmi_jmms_common_exit_property_screen,
        mmi_jmms_entry_show_read_report_screen,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_JMMS_NEW_MMS);

    g_jmms_context->property_display_buffer_p =
        (U8*) jdd_MemAlloc(
                sizeof(U8),
                (MAX_BUFFER_SIZE_FOR_PROPERTY + 1 + (MAX_NO_OF_ALLOWABLE_ADDRESSES * MAX_POSSIBLE_EMAIL_LENGHT_SENT)) * ENCODING_LENGTH);
    if (g_jmms_context->property_display_buffer_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
        return;
    }

    /* STATUS */
    mmi_ucs2cpy((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_STATUS));
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "jmms read status: ", g_jmms_context->read_report_p->eReadStatus);
    switch (g_jmms_context->read_report_p->eReadStatus)
    {
        case E_STATUS_READ:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms read status: E_STATUS_READ.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_READ_REPORT_READ));
            break;
        case E_STATUS_DELETED:
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_READ_REPORT_DELETED));
            break;
        default:
            mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_UNKNOWN));
            break;

    }

    /* FROM */
    memset(temp, 0x00, 4);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_FROM));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (g_jmms_context->read_report_p->pFrom == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) (g_jmms_context->read_report_p->pFrom),
            MAX_POSSIBLE_NUMBER_LENGHT_SENT,
            MAX_POSSIBLE_EMAIL_LENGHT_SENT);
    }

    /* Date */
    memset(dttemp, 0x00, 40);
    date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);

    /* Time */
    memset(temp, 0x00, 6);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    memset(dttemp, 0x00, 40);
    time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);

    ShowCategory78Screen(
        STR_ID_SETTINGS_READ_REPORT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        NULL,
        (U8*) g_jmms_context->property_display_buffer_p,
        mmi_ucs2strlen((S8*) g_jmms_context->property_display_buffer_p),
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_jmms_back_msg_view_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_msg_view_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_back_msg_view_entry, KEY_WAP, KEY_EVENT_DOWN);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_end_mms_play, KEY_END, KEY_EVENT_DOWN);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_show_delivery_report_screen
 * DESCRIPTION
 *  this function is sued to show Dilvery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_show_delivery_report_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer; /* Buffer holding history data */
    S8 temp[14];
    U8 dttemp[40];
    MYTIME time1, time;
    FLOAT timezone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_show_delivery_report_screen");

    timezone = mmi_dt_get_tz();

    /* sandeep start to Fix bug number PMT00006350 */
    mmi_jmms_update_status_icon_indicator();
    /* sandeep end to Fix bug number PMT00006350 */

    EntryNewScreen(
        SCR_ID_JMMS_NEW_MMS,
        mmi_jmms_common_exit_property_screen,
        mmi_jmms_entry_show_delivery_report_screen,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_JMMS_NEW_MMS);

    g_jmms_context->property_display_buffer_p =
        (U8*) jdd_MemAlloc(
                sizeof(U8),
                (MAX_BUFFER_SIZE_FOR_PROPERTY + 1 + (MAX_NO_OF_ALLOWABLE_ADDRESSES * MAX_POSSIBLE_EMAIL_LENGHT_SENT)) * ENCODING_LENGTH);
    if (g_jmms_context->property_display_buffer_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
        return;
    }

    /* STATUS */
    mmi_ucs2cpy((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_STATUS));
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    switch (g_jmms_context->delivery_p->eDeliveryStatus)
    {
        case E_MSG_EXPIRED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_EXPIRED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_EXPIRED));
            break;
        case E_MSG_RETRIEVED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_RETRIEVED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_RETRIEVED));
            break;
        case E_MSG_REJECTED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_REJECTED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_REJECTED));
            break;
        case E_MSG_DEFERRED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_DEFERRED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_DEFFERED));
            break;
        case E_MSG_UNRECOGNIZED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_UNRECOGNIZED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_UNRECOGNISED));
            break;
        case E_MSG_INDETERMINATE:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status:E_MSG_INDETERMINATE.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_INDETERMINATE));
            break;
        case E_MSG_FORWARDED:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_FORWARDED.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_FORWARDED));
            break;
        case E_MSG_UNREACHABLE:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms Delievery Status: E_MSG_UNREACHABLE.");
            mmi_ucs2cat(
                (S8*) g_jmms_context->property_display_buffer_p,
                (S8*) GetString(STR_ID_JMMS_DELIVERY_STATUS_UNREACHABLE));
            break;
        default:
            mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_UNKNOWN));
            break;
    }

    /* TO */
    memset(temp, 0x00, 4);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_TO));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (g_jmms_context->delivery_p->pTo == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) (g_jmms_context->delivery_p->pTo),
            MAX_POSSIBLE_NUMBER_LENGHT_SENT,
            MAX_POSSIBLE_EMAIL_LENGHT_SENT);
    }

    /* /Date */
    memset(temp, 0x00, 6);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_DATE));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    mmi_dt_utc_sec_2_mytime((U32) (g_jmms_context->delivery_p->uiDate), &time1, MMI_TRUE);
    mmi_dt_utc_to_rtc(timezone, time1, time);

    /* PMT RAJ KUMAR GUPTA on Sep 05, 2006 */
    /* Date */
    memset(dttemp, 0x00, 40);
    date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);

    memset(temp, 0x00, 6);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    /* Time */
    memset(dttemp, 0x00, 40);
    time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) dttemp);
    /* End of Changes - RAJ KUMAR GUPTA */

    ShowCategory78Screen(
        STR_ID_JMMS_DELIVERY_REPORT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        NULL,
        (U8*) g_jmms_context->property_display_buffer_p,
        mmi_ucs2strlen((S8*) g_jmms_context->property_display_buffer_p),
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_jmms_back_msg_view_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_msg_view_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_back_msg_view_entry, KEY_WAP, KEY_EVENT_DOWN);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_end_mms_play, KEY_END, KEY_EVENT_DOWN);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_deffered_retrieved_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  content     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_deffered_retrieved_mms(CONTENT_DATA content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_deffered_retrieved_mms");

    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&g_jmms_context->msg_handle, &content, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(g_jmms_context->msg_handle);
    };
    /* Async changes end */

    if (JC_OK != ret_code && g_jmms_context->msg_handle != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms parsing failed! Deinitializing the Msg Handler.",
                             ret_code);
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
        return ret_code;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, (MESSAGE_HEADERS **) (&g_jmms_context->msg_headers_p));
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms failed to get the message Header.", ret_code);
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
        return ret_code;
    }

    if ((((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->eMsgType) != E_MSG_TYPE_RECEIVE)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
        return E_UNKNOWN_MSG;
    }

    g_jmms_context->msg_header_type_p =
        (MESSAGE_RETRIEVAL*) ((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->pHeaders;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_handle_deffered_retrieved_mms Return value", ret_code);
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  jmms_mmi_ack_for_deffered_retrieval
 * DESCRIPTION
 *  This function is used to send acknowledgement to MMS server for deffered retrival.
 * PARAMETERS
 *  content     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE jmms_mmi_ack_for_deffered_retrieval(CONTENT_DATA content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_ACK *ack_p = NULL;
    MESSAGE_RETRIEVAL *notify_ind_headers_p = NULL;
    MSG_HANDLE mms_signal_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jmms_mmi_ack_for_deffered_retrieval");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&mms_signal_handle, &content, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(mms_signal_handle);
    };
    /* Async changes end */

    if (JC_OK != ret_code && mms_signal_handle != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms parsing failed! Deinitializing the Msg Handler.",
                             ret_code);
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
        return ret_code;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(mms_signal_handle, &msg_headers_p);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to get the Msg Header", ret_code);
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
        return ret_code;
    }

    notify_ind_headers_p = (MESSAGE_RETRIEVAL*) msg_headers_p->pHeaders;

    if (notify_ind_headers_p == NULL || notify_ind_headers_p->pTransactionID == NULL ||
        notify_ind_headers_p->pVersion == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }

    ack_p = (MESSAGE_ACK*) jdd_MemAlloc(sizeof(MESSAGE_ACK), 1);
    if (ack_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    ack_p->bDeliveryReport = (JC_BOOLEAN) mmi_jmms_retrieval_settings_delivery_report();
    ack_p->pVersion = jdi_UtilsStrdup(notify_ind_headers_p->pVersion);
    ack_p->pTransactionID = jdi_UtilsStrdup(notify_ind_headers_p->pTransactionID);

    if (NULL != mms_signal_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
    }

    ret_code = mmi_jmms_jdi_msg_init(&mms_signal_handle, NULL);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms Msg initialization failed.", ret_code);
        mms_signal_handle = NULL;
        goto ERROR_HANDLE;
    }

    msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);
    if (msg_headers_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    msg_headers_p->eMsgType = E_MSG_TYPE_ACKNOWLEDGE;
    msg_headers_p->pHeaders = ack_p;
    ret_code = mmi_jmms_jdi_set_msg_headers(mms_signal_handle, msg_headers_p);
    if (JC_OK != ret_code)
    {
        goto ERROR_HANDLE;
    }

    mmi_jmms_send_mms(mms_signal_handle, E_TYPE_ACK_RESPONSE, E_TRUE, 1, E_FALSE
#ifdef __MMI_UNIFIED_COMPOSER__
                      , NULL
#endif 
        );

  ERROR_HANDLE:
    if (mms_signal_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(mms_signal_handle);
        mms_signal_handle = NULL;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms_mmi_ack_for_deffered_retrieval Return value", ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_and_send_read_report
 * DESCRIPTION
 *  This function is used to create and send read report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_and_send_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MESSAGE_RETRIEVAL *retrieve_headers = NULL;
    U16 temp_comm_state = E_TYPE_NULL;
    MSG_HANDLE read_report_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_and_send_read_report");

    retrieve_headers = (MESSAGE_RETRIEVAL*) g_jmms_context->msg_header_type_p;
    if (jc_strcmp(retrieve_headers->pVersion, "1.0") == 0)
    {
        ret_code = mmi_jmms_set_read_reply_message(
                    &read_report_handle,
                    retrieve_headers->pMessageID,
                    retrieve_headers->pFrom,
                    retrieve_headers->pSubject);
        if (ret_code == JC_OK)
        {
            temp_comm_state = E_TYPE_READ_REPORT_MMS;
        }
    }
    else
    {
        ret_code = mmi_jmms_set_read_reply_pdu(
                    &read_report_handle,
                    retrieve_headers->pMessageID,
                    retrieve_headers->pFrom,
                    retrieve_headers->pVersion);
        if (ret_code == JC_OK)
        {
            temp_comm_state = E_TYPE_READ_REPORT_PDU;
        }
    }

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_send_mms(read_report_handle, temp_comm_state, E_TRUE, 1, E_FALSE
    #ifdef __MMI_UNIFIED_COMPOSER__
                                     , NULL
    #endif 
            );
    }

    if (ret_code != JC_OK)
    {
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            ret_code = mmi_jmms_add_pending_mms_info_node(
                        (U16) STR_ID_JMMS_STORAGE_ERROR_READ_REPORT_SENT,
                        (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                        NULL);
        }
        else
        {
            ret_code = mmi_jmms_add_pending_mms_info_node(
                        (U16) STR_ID_JMMS_ERROR_READ_REPORT_SENT,
                        (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                        NULL);
        }

        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
    }
    else    /* /in case of error mmi_jmms_set_read_reply_pdu || */
        /* mmi_jmms_set_read_reply_message themselves will free the handle */
    {
        if (read_report_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit_without_header(read_report_handle);
            read_report_handle = NULL;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_read_reply_message
 * DESCRIPTION
 *  This function is used to prepare the MMS for read report.
 * PARAMETERS
 *  msg_handle_p        [IN]        
 *  msg_id              [IN]        
 *  to_address_p        [IN]        
 *  pSubject            [IN]        
 * RETURNS
 *  JC_OK           on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_read_reply_message(
            MSG_HANDLE *msg_handle_p,
            JC_INT8 *msg_id,
            JC_CHAR *to_address_p,
            JC_CHAR *pSubject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    MESSAGE_HEADERS *read_report_headers_p = NULL;
    MESSAGE_SEND *read_report_send_headers_p = NULL;
    JC_UINT32 media_id = 0;
    S8 *temp_string = NULL;
    U32 len = 0, temp_len = 0;

    MEDIA_INFO MediaInfo = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_set_read_reply_message");

    if (msg_handle_p == NULL || msg_id == NULL || to_address_p == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }
    ret_code = mmi_jmms_jdi_msg_init(msg_handle_p, NULL);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms msg initialization failed.", ret_code);
        goto ERROR_HANDLE;
    }

    ret_code = mmi_jmms_jdi_set_msg_type(*msg_handle_p, E_TYPE_MMS);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to set the MMS type", ret_code);
        goto ERROR_HANDLE;
    }
    ret_code = mmi_jmms_jdi_set_presentation_type(*msg_handle_p, E_PRESENTATION_NONE);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to set the presentation type", ret_code);
        goto ERROR_HANDLE;
    }

    /* pMediaInfo = (MEDIA_INFO *)jdd_MemAlloc(sizeof(MEDIA_INFO), 1) ;
       if(pMediaInfo == NULL)
       {
       ret_code = JC_ERR_MEMORY_ALLOCATION ;
       goto ERROR_HANDLE ;
       } */
    MediaInfo.eMediaType = E_MEDIA_TEXT;

    MediaInfo.pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), 1);
    if (MediaInfo.pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    MediaInfo.pMimeInfo->MimeHeaders.pContentType =
        (JC_INT8*) jdd_MemAlloc(jc_strlen("text/plain") + 1, sizeof(JC_INT8));
    if (MediaInfo.pMimeInfo->MimeHeaders.pContentType == NULL)
    {

        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    else
    {
        jc_strcpy(MediaInfo.pMimeInfo->MimeHeaders.pContentType, "text/plain");
    }

    if (g_jmms_context->is_unread_msg_deleted == 1)
    {
        len = (mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_READ_REPORT_DELETE_MSG))) * ENCODING_LENGTH;
    }
    else
    {
        len = (mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_READ_REPORT_MSG))) * ENCODING_LENGTH;
    }
    len = len + ((mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_READ_REPORT_MSG_ID))) * ENCODING_LENGTH);
    temp_len = (strlen((const char*)msg_id)) * ENCODING_LENGTH;
    len = len + temp_len;

    MediaInfo.pMimeInfo->ContentData.pBuffer = jdd_MemAlloc(sizeof(S8), len + ENCODING_LENGTH);
    if (MediaInfo.pMimeInfo->ContentData.pBuffer == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    temp_string = jdd_MemAlloc(sizeof(S8), temp_len + ENCODING_LENGTH);
    if (temp_string == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    mmi_asc_to_ucs2((S8*) temp_string, (S8*) msg_id);

    if (g_jmms_context->is_unread_msg_deleted == 1)
    {
        mmi_ucs2cpy(
            (S8*) (MediaInfo.pMimeInfo->ContentData.pBuffer),
            (S8*) GetString(STR_ID_JMMS_READ_REPORT_DELETE_MSG));
        g_jmms_context->is_unread_msg_deleted = 0;
    }
    else
    {
        mmi_ucs2cpy((S8*) (MediaInfo.pMimeInfo->ContentData.pBuffer), (S8*) GetString(STR_ID_JMMS_READ_REPORT_MSG));
    }
    mmi_ucs2cat((S8*) (MediaInfo.pMimeInfo->ContentData.pBuffer), (S8*) GetString(STR_ID_JMMS_READ_REPORT_MSG_ID));

    mmi_ucs2cat((S8*) (MediaInfo.pMimeInfo->ContentData.pBuffer), (S8*) temp_string);

    if (temp_string != NULL)
    {
        jdd_MemFree(temp_string);
        temp_string = NULL;
    }

    jdi_UtilsCharToTchar(&(MediaInfo.PresentationInfo.pRegionName), "Text");
    MediaInfo.pMimeInfo->ContentData.uiCurSize = MediaInfo.pMimeInfo->ContentData.uiTotalSize = len + ENCODING_LENGTH;

    ret_code = mmi_jmms_jdi_add_media(*msg_handle_p, &MediaInfo, 1, &media_id);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms fail to add media.", ret_code);
        goto ERROR_HANDLE;
    }

    read_report_headers_p = jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);
    if (read_report_headers_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    read_report_headers_p->eMsgType = E_MSG_TYPE_SEND;
    read_report_send_headers_p = (MESSAGE_SEND*) jdd_MemAlloc(sizeof(MESSAGE_SEND), 1);
    if (read_report_send_headers_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    read_report_send_headers_p->eMsgClass = E_MSG_AUTO_CLASS;
    read_report_send_headers_p->eMsgPriority = (U32) mmi_jmms_sending_settings_priority();

    if (wap_get_user_agent_brand() == EM_WAP_USERAGENT_BRAND_SE)
    {
        read_report_send_headers_p->uiDate = get_current_utc_time();
        read_report_send_headers_p->uiExpiryTime = 0;
    }
    else
    {
        read_report_send_headers_p->uiExpiryTime = (U32) MAX_VALIDITY_PERIOD_VALUE;
    }

    if (pSubject != NULL)
    {
        len = (mmi_ucs2strlen((S8*) pSubject)) * ENCODING_LENGTH;
        len = len + ((strlen((S8*) STR_JMMS_READ_REPORT_PREPEND_STRING)) * ENCODING_LENGTH);

        read_report_send_headers_p->pSubject = jdd_MemAlloc(sizeof(S8), (len + ENCODING_LENGTH));
        if (read_report_send_headers_p->pSubject == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((S8*) read_report_send_headers_p->pSubject, (S8*) STR_JMMS_READ_REPORT_PREPEND_STRING);
        mmi_ucs2cat((S8*) (read_report_send_headers_p->pSubject), (S8*) (pSubject));

    }
    else
    {
        len = (strlen((S8*) STR_JMMS_READ_REPORT_PREPEND_STRING)) * ENCODING_LENGTH;
        read_report_send_headers_p->pSubject = jdd_MemAlloc(sizeof(S8), len + ENCODING_LENGTH);
        if (read_report_send_headers_p->pSubject == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((S8*) read_report_send_headers_p->pSubject, (S8*) STR_JMMS_READ_REPORT_PREPEND_STRING);
    }

    read_report_send_headers_p->pTo = jdd_MemAlloc(jc_tcslen(to_address_p) + 1, sizeof(JC_CHAR));
    if (read_report_send_headers_p->pTo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy(read_report_send_headers_p->pTo, to_address_p);

    read_report_send_headers_p->pVersion = jdd_MemAlloc(sizeof(JC_INT8), MAX_VERSION_LENGTH + 1);
    if (read_report_send_headers_p->pVersion)
    {
        jc_strcpy(read_report_send_headers_p->pVersion, "1.0");
    }

    read_report_headers_p->pHeaders = read_report_send_headers_p;

    ret_code = mmi_jmms_jdi_set_msg_headers(*msg_handle_p, read_report_headers_p);

  ERROR_HANDLE:
    if (ret_code != JC_OK)
    {
        if (*msg_handle_p != NULL)
        {
            mmi_jmms_jdi_msg_deinit_without_header(*msg_handle_p);
            msg_handle_p = NULL;
        }

    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_set_read_reply_message Return value", ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_read_reply_pdu
 * DESCRIPTION
 *  This function is used to prepare PDU for read report.
 * PARAMETERS
 *  msg_handle_p        [IN]        
 *  msg_id              [IN]        
 *  to_address_p        [IN]        
 *  version_p           [IN]        
 * RETURNS
 *  JC_OK            on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_read_reply_pdu(
            MSG_HANDLE *msg_handle_p,
            JC_INT8 *msg_id,
            JC_CHAR *to_address_p,
            JC_INT8 *version_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    READ_REPORT *pReadReport = NULL;
    MESSAGE_HEADERS *pReadReportPDU = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_set_read_reply_pdu");

    if (msg_handle_p == NULL || msg_id == NULL || to_address_p == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }
    ret_code = mmi_jmms_jdi_msg_init(msg_handle_p, NULL);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "jmms msg Initialization failed.", ret_code);
        goto ERROR_HANDLE;
    }
    pReadReportPDU = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);
    if (pReadReportPDU == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    pReadReport = (READ_REPORT*) jdd_MemAlloc(sizeof(READ_REPORT), 1);
    if (pReadReport == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    if (g_jmms_context->is_unread_msg_deleted == 1)
    {
        pReadReport->eReadStatus = E_STATUS_DELETED;
        g_jmms_context->is_unread_msg_deleted = 0;
    }
    else
    {
        pReadReport->eReadStatus = E_STATUS_READ;
    }

    pReadReport->pMessageID = jdi_UtilsStrdup(msg_id);
    pReadReport->pTo = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), jc_tcslen(to_address_p) + 1);
    if (pReadReport->pTo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy(pReadReport->pTo, to_address_p);
    pReadReport->pVersion = jdi_UtilsStrdup(version_p);

    if (wap_get_user_agent_brand() == EM_WAP_USERAGENT_BRAND_SE)
    {
        pReadReport->uiDate = get_current_utc_time();
    }

    pReadReportPDU->eMsgType = E_MSG_TYPE_READ_REPORT;
    pReadReportPDU->pHeaders = pReadReport;
    ret_code = mmi_jmms_jdi_set_msg_headers(*msg_handle_p, pReadReportPDU);

  ERROR_HANDLE:
    if (ret_code != JC_OK)
    {
        if (*msg_handle_p != NULL)
        {
            mmi_jmms_jdi_msg_deinit_without_header(*msg_handle_p);
            msg_handle_p = NULL;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_set_read_reply_pdu Return value", ret_code);
    return ret_code;
}

#ifdef __MMI_JMMS_EXPIRY_HANDLING__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_notification_headers_expired
 * DESCRIPTION
 *  Returns whether the Notification Headers have expired
 * PARAMETERS
 *  notify_ind_headers_p        [IN]        Notification Headers
 * RETURNS
 *  JC_BOOLEAN        TRUE/FALSE
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_notification_headers_expired(MESSAGE_NOTIFICATION *notify_ind_headers_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 current_time = 0;
    JC_UINT32 expiry_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notify_ind_headers_p->uiReceivedTime == 0 && notify_ind_headers_p->bExpiryAbs == 0)
    {
        return E_FALSE;
    }
    if (notify_ind_headers_p->bExpiryAbs == 1)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_check_notification_headers_expired: Absolute Time");
        expiry_time = notify_ind_headers_p->uiExpiryTime;
    }
    else
    {
        expiry_time = notify_ind_headers_p->uiReceivedTime + notify_ind_headers_p->uiExpiryTime;
    }
    current_time = get_current_utc_time();
    if (current_time > expiry_time)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)(%d)(%d)", "mmi_jmms_check_notification_headers_expired: ",
                             expiry_time, current_time, notify_ind_headers_p->uiExpiryTime,
                             notify_ind_headers_p->uiReceivedTime);
        return E_TRUE;
    }
    else
    {
        return E_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_has_notification_expired
 * DESCRIPTION
 *  Returns whether Nitification at msg_index has expired have expired
 * PARAMETERS
 *  msg_index       [IN]        
 * RETURNS
 *  JC_BOOLEAN        TRUE/FALSE
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_has_notification_expired(JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_index) store_ret_filter.uiStartIndex = msg_index;
    store_ret_filter.uiNumMessage = 1;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    ret_code = mmi_jmms_get_messages_list("Inbox", &message_list_p, &store_ret_filter);
    if (ret_code == JC_OK)
    {
        return
            mmi_jmms_check_notification_headers_expired((MESSAGE_NOTIFICATION*) (message_list_p->pMessageHeaders->
                                                                                  pHeaders));
    }
    return E_FALSE;
}
#endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

