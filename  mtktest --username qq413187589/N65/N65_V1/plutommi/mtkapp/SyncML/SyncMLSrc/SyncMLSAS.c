/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    SyncMLSAS.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#include "App_mine.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"

#include "ProfileGprots.h"
#include "wapadp.h"

#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountDef.h"
#include "NetworkSetupDefs.h"
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"


/*
 * Local Variable
 */
syncml_sas_struct g_sas_context;


/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;
extern syncml_display_info[1024];


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_sas
 * DESCRIPTION
 *  Initialize highlight and hint for server alerted sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_sas(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_sas_context, 0, sizeof(syncml_sas_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_receive_da_file
 * DESCRIPTION
 *  WAP Push handler for SyncML server alerted sync notification
 * PARAMETERS
 *  session_id              [IN]        Not referred in this function
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        Not referred in this function
 *  filepath                [IN]        The filepath to indicate this message
 *  url                     [IN]        Not referred in this function
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mime_type == MIME_TYPE_APPLICATION);
    MMI_ASSERT(mime_subtype == MIME_SUBTYPE_DS_NOTIFICATION);

    if (mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        return; /* nothing to do during the sync session */
    }

    mmi_syncml_wap_push_req(filepath); /* this file should be delete in syncml task */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sas_accept
 * DESCRIPTION
 *  Entry function to accept the server alerted sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sas_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    g_sas_context.phn_sync_type = g_syncml_context.sync_type;
#endif
    g_sas_context.phn_applications_to_sync = g_syncml_context.applications_to_sync;
    g_sas_context.phn_active_profile = g_syncml_context.active_profile;

    g_sas_context.sync_from_server = MMI_TRUE;

    /* server alerted sync query screen doens't need to be saved to history
       if the user has decided to sync or not to sync */
    SetCurrEntryFuncPtr(NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_syncml_sas_req(SYNCML_SAS_ACCEPT_SYNC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sas_reject
 * DESCRIPTION
 *  Entry function to reject the server alerted sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sas_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sas_context.sync_from_server = MMI_FALSE;

    /* server alerted sync query screen doens't need to be saved to history
       if the user has decided to sync or not to sync */
    SetCurrEntryFuncPtr(NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_syncml_sas_req(SYNCML_SAS_REJECT_SYNC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sas_notification
 * DESCRIPTION
 *  Entry function of server alerted sync notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sas_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 temp_line[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     *  (Title) Server Alerted Sync
     *
     *  "sync.server.com" requires to start sync from your handset.
     *
     *  Sync type: Two-way sync
     *  Applications to sync: phonebook and to-do-list
     *
     *  Do you want to aceept?
     */

    EntryNewScreen(SCR_ID_SYNC_SAS_NOTIFICATION, NULL, mmi_syncml_entry_sas_notification, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_SAS_NOTIFICATION);

    mmi_ucs2cpy((PS8)syncml_display_info, (PS8)L""); /* reset string */

    kal_wsprintf((PU16) temp_line, "\"%s\" ", g_sas_context.sas_server_uri);
    mmi_ucs2cpy((PS8) syncml_display_info, (PS8)temp_line);
    mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_SAS_CONTEXT_1));
    mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n\n");

    mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_TYPE));
    kal_wsprintf((PU16) temp_line, ": ");
    mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
    switch(g_sas_context.sas_sync_type)
    {
        case SYNCML_SYNC_TWO_WAY_SYNC:
        case SYNCML_SYNC_TWO_WAY_SLOW:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_TWOWAY));
            break;

        case SYNCML_SYNC_CLIENT_ONE_WAY_SYNC:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_EXPORT));
            break;

        case SYNCML_SYNC_CLIENT_ONE_WAY_REFRESH:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_BACKUP));
            break;

        case SYNCML_SYNC_SERVER_ONE_WAY_SYNC:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_IMPORT));
            break;

        case SYNCML_SYNC_SERVER_ONE_WAY_REFRESH:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_RESTORE));
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n\n");

    mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_APPLICATIONS));
    kal_wsprintf((PU16) temp_line, ": ");
    mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
    switch (g_sas_context.sas_applications_to_sync)
    {
        case 1:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) GetString(STR_ID_SYNC_HINT_PHB_ONLY));
            break;

        case 2:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) GetString(STR_ID_SYNC_HINT_TDL_ONLY));
            break;

        case 3:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) GetString(STR_ID_SYNC_HINT_PHB_TDL));
            break;

        default:
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) GetString(STR_ID_SYNC_REGULARITY_NONE));
            break;
    }
    mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n\n");

    mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_SAS_CONTEXT_2));

    ShowCategory74Screen(
        STR_ID_SYNC_SAS_NOTIFICATION,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*) syncml_display_info,
        mmi_ucs2strlen((const S8*) syncml_display_info),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_syncml_entry_sas_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_entry_sas_reject, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_wap_push_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  filepath    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_wap_push_req(PU16 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_wap_push_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_syncml_wap_push_rsp, MSG_ID_MMI_SYNCML_WAP_PUSH_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_WAP_PUSH_REQ;

    dataPtr =
        (mmi_syncml_wap_push_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_wap_push_req_struct));

    mmi_ucs2cpy((PS8) dataPtr->wap_push_filepath, (PS8)filepath);

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_wap_push_rsp
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_wap_push_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL sas_validation = MMI_TRUE;
    applib_mime_type_struct *mime1, *mime2;
    syncml_profile_struct temp_profile[MAX_SYNCML_SV_PROFILES];
    U8 i;

    mmi_syncml_wap_push_rsp_struct *local_data = (mmi_syncml_wap_push_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_SYNCML_WAP_PUSH_RSP);

    strcpy((S8*) g_sas_context.sas_server_uri, (S8*) local_data->server_uri);

    for (i = 0; i <MAX_SYNCML_PROFILES ; i++)
    {
        mmi_syncml_read_profile_from_nvram((U8)(i + 1), (void *)(&temp_profile[i]));
        if (strstr((S8*) temp_profile[i].server_address, (S8*) g_sas_context.sas_server_uri) != NULL)
        {
            g_sas_context.sas_active_profile = i + 1;
        }
    }

    if (g_sas_context.sas_active_profile == 0)
    {
        /* no matched profile to perform the server alerted sync*/
        mmi_syncml_sas_req(SYNCML_SAS_PROFILE_MISMATCH);
        return;
    }

    g_sas_context.ui_mode = local_data->ui_mode;

    if (local_data->num_syncs == 0)
    {
        /* sync with default settings */
        g_sas_context.sas_sync_type = SYNCML_TYPE_DEFAULT;
        g_sas_context.sas_applications_to_sync |= SYNCML_DB_PHONEBOOK;
        g_sas_context.sas_applications_to_sync |= SYNCML_DB_TODOLIST;
    }
    else if (local_data->num_syncs > 2)
    {
        /* currently, only two data stores can be accepted */
        sas_validation = MMI_FALSE;
    }
    else
    {
        g_sas_context.sas_sync_type = local_data->sync_type;

        mime1 = mime_type_look_up(NULL, NULL, 0, MIME_SUBTYPE_XVCARD);
        mime2 = mime_type_look_up(NULL, NULL, 0, MIME_SUBTYPE_XVCALENDAR);

        if (strcmp((S8*) local_data->mime_type_code1, mime1->mime_string) == 0)
        {
            g_sas_context.sas_applications_to_sync |= SYNCML_DB_PHONEBOOK;
            strcpy((S8*) g_sas_context.sas_contact_database_uri, (S8*) local_data->data_store_uri1);
        }
        else if (strcmp((S8*) local_data->mime_type_code1, mime2->mime_string) == 0)
        {
            g_sas_context.sas_applications_to_sync |= SYNCML_DB_TODOLIST;
            strcpy((S8*) g_sas_context.sas_calendar_database_uri, (S8*) local_data->data_store_uri1);
        }
        else if (strcmp((S8*) local_data->mime_type_code1, (S8*) "*/*") == 0)
        {
            for (i = 0; i <MAX_SYNCML_PROFILES ; i++)
            {
                if (strstr((S8*) temp_profile[i].contact_address, (S8*) local_data->data_store_uri1) != NULL)
                {
                    g_sas_context.sas_applications_to_sync |= SYNCML_DB_PHONEBOOK;
                    strcpy((S8*) g_sas_context.sas_contact_database_uri, (S8*) local_data->data_store_uri1);
                }
                else if (strstr((S8*) temp_profile[i].calendar_address, (S8*) local_data->data_store_uri1) != NULL)
                {
                    g_sas_context.sas_applications_to_sync |= SYNCML_DB_TODOLIST;
                    strcpy((S8*) g_sas_context.sas_calendar_database_uri, (S8*) local_data->data_store_uri1);
                }
                else
                {
                    sas_validation = MMI_FALSE;
                }
            }
        }
        else
        {
           sas_validation = MMI_FALSE;
        }

        if (strcmp((S8*) local_data->mime_type_code2, mime1->mime_string) == 0)
        {
            g_sas_context.sas_applications_to_sync |= SYNCML_DB_PHONEBOOK;
            strcpy((S8*) g_sas_context.sas_contact_database_uri, (S8*) local_data->data_store_uri1);
        }
        else if (strcmp((S8*) local_data->mime_type_code2, mime2->mime_string) == 0)
        {
            g_sas_context.sas_applications_to_sync |= SYNCML_DB_TODOLIST;
            strcpy((S8*) g_sas_context.sas_calendar_database_uri, (S8*) local_data->data_store_uri1);
        }
        else if (strcmp((S8*) local_data->mime_type_code2, (S8*) "*/*") == 0)
        {
            for (i = 0; i <MAX_SYNCML_PROFILES ; i++)
            {
                if (strstr((S8*) temp_profile[i].contact_address, (S8*) local_data->data_store_uri2) != NULL)
                {
                    g_sas_context.sas_applications_to_sync |= SYNCML_DB_PHONEBOOK;
                    strcpy((S8*) g_sas_context.sas_contact_database_uri, (S8*) local_data->data_store_uri2);
                }
                else if (strstr((S8*) temp_profile[i].calendar_address, (S8*) local_data->data_store_uri2) != NULL)
                {
                    g_sas_context.sas_applications_to_sync |= SYNCML_DB_TODOLIST;
                    strcpy((S8*) g_sas_context.sas_calendar_database_uri, (S8*) local_data->data_store_uri2);
                }
                else
                {
                    sas_validation = MMI_FALSE;
                }
            }
        }
        else
        {
           sas_validation = MMI_FALSE;
        }
    }

    if (sas_validation)
    {
        switch (g_sas_context.ui_mode)
        {
            case SYNCML_UI_MODE_BACKGROUND:
            case SYNCML_UI_MODE_INFORMATIVE:
                mmi_syncml_sas_req(SYNCML_SAS_ACCEPT_SYNC); /* directly accept to sync if the UI mode is background or informative */
                 break;

            case SYNCML_UI_MODE_NONE:
            case SYNCML_UI_MODE_INTERACTION:
            default:
                mmi_syncml_entry_sas_notification();
                break;
        }
    }
    else
    {
        mmi_syncml_sas_req(SYNCML_SAS_PARAMETER_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_wap_push_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  cause       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sas_req(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_sas_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_syncml_sas_rsp, MSG_ID_MMI_SYNCML_SAS_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_SAS_REQ;

    dataPtr =
        (mmi_syncml_sas_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_sas_req_struct));

    dataPtr->cause = cause;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sas_rsp
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sas_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_SYNCML_SAS_RSP);

    /* start sync */
    if (g_sas_context.sync_from_server)
    {
    #ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        g_syncml_context.sync_type = g_sas_context.sas_sync_type;
    #endif
        g_syncml_context.applications_to_sync = g_sas_context.sas_applications_to_sync;
        g_syncml_context.active_profile = g_sas_context.sas_active_profile;

        switch (g_sas_context.ui_mode)
        {
            case SYNCML_UI_MODE_BACKGROUND:
                mmi_syncml_entry_sas_background_sync();
                break;

            case SYNCML_UI_MODE_INFORMATIVE:
                playRequestedTone(MESSAGE_TONE);
            case SYNCML_UI_MODE_NONE:
            case SYNCML_UI_MODE_INTERACTION:
            default:
                mmi_syncml_entry_sync_pre_check();
                break;
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_OK),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_started_from_server
 * DESCRIPTION
 *  Query the sync is started by server alerted sync
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_sync_started_from_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_sas_context.sync_from_server;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sas_finish
 * DESCRIPTION
 *  Finish the server alerted sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sas_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sas_context.sync_from_server)
    {
    #ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        g_syncml_context.sync_type = g_sas_context.phn_sync_type;
    #endif
        g_syncml_context.applications_to_sync = g_sas_context.phn_applications_to_sync;
        g_syncml_context.active_profile = g_sas_context.phn_active_profile;

        g_sas_context.sync_from_server = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sas_background_sync
 * DESCRIPTION
 *  Entry function of server alerted sync with UI mode is background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sas_background_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.active_profile == 0 ||
        g_syncml_context.applications_to_sync == 0 ||
        !mmi_syncml_is_phb_ready() ||
        !wap_is_ready())
    {
        return;
    }

#ifdef __MMI_WLAN_FEATURES__
    if ((mmi_netset_get_active_preferred_mode() == P_GSM_ONLY  && mmi_syncml_get_active_profile_bearer() > MAX_DATA_ACCOUNT_GSM_LIMIT + MAX_DATA_ACCOUNT_GPRS_LIMIT - 1) ||
        (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY && mmi_syncml_get_active_profile_bearer() < MAX_DATA_ACCOUNT_GSM_LIMIT + MAX_DATA_ACCOUNT_GPRS_LIMIT))
    {
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.next_phb_anchor = g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1] + 1;
        }
        if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
        {
            g_syncml_context.next_tdl_anchor = g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1] + 1;
        }
        g_syncml_context.power_on_sync = 0;
        mmi_syncml_init_sync_report();
        mmi_syncml_get_imei_req();
    }
}


#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

