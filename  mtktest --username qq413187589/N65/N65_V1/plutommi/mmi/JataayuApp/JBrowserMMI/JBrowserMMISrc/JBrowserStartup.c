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
 * JBrowserStartup.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *   Shantanu Meher -20051012
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JBROWSERSTARTUP_C
#define _MMI_JBROWSERSTARTUP_C

/*  Include: MMI header file */

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)

#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "CommonScreens.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGProts.h"
#include "IdleAppDef.h"
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "JProvProts.h"
#include "jdd_ui_datatypes.h"
#include "IdleAppDef.h"
#include "SettingProfile.h"
#include "JPushInboxCommonUI.h"
#include "JPushInboxCommonAPIs.h"
#include "JBrowserDRMHandler.h"
#include "JPushInboxUM.h"
#include "jdd_MMIapi.h"
#include "jdd_ui_input_ctrl.h"
#include "jdd_ui_window.h"
#include "jdd_ui_img_ctrl.h"
#include "jdd_audioapi.h"
#include "jdd_dataconnection.h"
#include "SmsGuiInterfaceType.h"
#include "SmsGuiInterfaceProt.h"
#include "UnifiedMessageResDef.h"
#include "ProfileGprots.h"
#include "gpioInc.h"
#include "content_type.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"
#include "sat_def.h"
#include "ServiceDefs.h"
#include "USBDeviceGprot.h"
#include "FileManagerDef.h"

#if defined (__MMI_FILE_MANAGER__) && !defined (__JBROWSER_DLS_SUPPORT__)       /* Needed for FMGR_MAX_PATH_LEN macro */
#include "FileMgr.h"
#endif 

#include "jdd_ui_ResDef.h"
#include "JMMSResDef.h"
#ifdef JBROWSER_USE_ASM
#endif 
#ifdef MMS_SUPPORT
#include "JMMSGprot.h"
#endif 
#include "wapadp.h"
#include "jdd_ui_utils.h"
#include "JPushInboxCommonAPIs.h"
#include "custom_data_account.h"
#include "CallManagementGprot.h"
#ifdef __JBROWSER_DLS_SUPPORT__
#include "app_mine.h"
#endif 

JC_BROWSER_CONTEXT g_mmi_brw_pbrowser_ctxt;

#ifdef __JBROWSER_DLS_SUPPORT__
mmi_brw_dls_context_struct g_mmi_brw_dls_cntx;
#endif 
/* extern jdd_MemSetActiveModuleID(ETaskID taskId); */
extern JC_RETCODE jdd_MemInitBrowserASMPool(kal_uint32 *mem_pool_p, kal_uint32 mem_pool_size);
extern JC_BOOLEAN mmi_jdd_ui_is_entry_notification_screen_present(void);
extern U8 g_mmi_brw_notification_flag;
JC_HANDLE *g_mmi_brw_pvdrmarg_p;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_startup
 * DESCRIPTION
 *  Startup Event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA event_data = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send browser start up event */
    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.uiEventInfoSize = 0;
    event_data.iEventType = E_BRW_STARTUP_EVENT;
    ret = jdd_QueueCreate(E_TASK_BROWSER_CORE, "BrwCoreQ", sizeof(JC_EVENT_DATA), 128, E_FALSE);

    ret = jdd_QueueCreate(E_TASK_BROWSER_UI, "BrwUIQ", sizeof(JC_EVENT_DATA), 128, E_FALSE);
    ret = jdd_QueueSend(&event_data);
    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jdd_browser_core_events_hdlr
 * DESCRIPTION
 *  Core Event Handler
 * PARAMETERS
 *  event_data_p        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jdd_browser_core_events_hdlr(JC_EVENT_DATA *event_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_TASK_TRANSPORT == event_data_p->srcTaskInfo.iTaskID)
    {
        ret = jdi_BrowserHandleTransportResponse(g_mmi_brw_pbrowser_ctxt, event_data_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_key_left_arrow_event_hdlr
 * DESCRIPTION
 *  mmi_brw_jbrowser_key_left_arrow_event_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_key_left_arrow_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EJCScrollDirection escroll_direction;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    escroll_direction = E_JC_SCROLL_LEFT;
    ret = jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
    if (JC_OK != ret)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_key_right_arrow_event_hdlr
 * DESCRIPTION
 *  mmi_brw_jbrowser_key_right_arrow_event_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_key_right_arrow_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EJCScrollDirection escroll_direction;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    escroll_direction = E_JC_SCROLL_RIGHT;
    ret = jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
    if (JC_OK != ret)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_key_up_arrow_event_hdlr
 * DESCRIPTION
 *  mmi_brw_jbrowser_key_up_arrow_event_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_key_up_arrow_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EJCScrollDirection escroll_direction;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    escroll_direction = E_JC_SCROLL_UP;
    ret = jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
    if (JC_OK != ret)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_key_down_arrow_event_hdlr
 * DESCRIPTION
 *  mmi_brw_jbrowser_key_down_arrow_event_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_key_down_arrow_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EJCScrollDirection escroll_direction;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    escroll_direction = E_JC_SCROLL_DOWN;
    ret = jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
    if (JC_OK != ret)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_go_event
 * DESCRIPTION
 *  Go event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_go_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA eventdata = {0, };
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    eventdata.pEventInfo = NULL;
    eventdata.uiEventInfoSize = 0;
    eventdata.iEventType = E_BRW_START_FETCH_EVENT;

    eventdata.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    eventdata.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&eventdata);

    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_event
 * DESCRIPTION
 *  Deinit event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA eventdata = {0, };
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    eventdata.pEventInfo = NULL;
    eventdata.uiEventInfoSize = 0;
    eventdata.iEventType = E_BRW_DEINIT_EVENT;

    eventdata.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    eventdata.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&eventdata);
    jdd_MemSetActiveModuleID(temp_activated_task_id);

    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wps_deinit_event
 * DESCRIPTION
 *  Deinit event handler for WPS task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wps_deinit_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA eventdata = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eventdata.pEventInfo = NULL;
    eventdata.uiEventInfoSize = 0;
    eventdata.iEventType = E_BRW_DEINIT_EVENT;

    eventdata.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    eventdata.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&eventdata);
    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dataconn_auto_disc_timeout_event
 * DESCRIPTION
 *  Dataconn auto disconnect event handler.It disconn csd call on the basic
 *  of timeout event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dataconn_auto_disc_timeout_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA eventdata = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should be used only with WPS task */

    eventdata.pEventInfo = NULL;
    eventdata.uiEventInfoSize = 0;
    eventdata.iEventType = E_BRW_DATACONN_AUTO_DISC_TIMEOUT_EVENT;

    eventdata.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    eventdata.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&eventdata);
    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_refresh_display_hdlr
 * DESCRIPTION
 *  Refresh event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_refresh_display_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret = jdi_BrowserRefreshDisplay(g_mmi_brw_pbrowser_ctxt);
    if (JC_OK != ret)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_multimedia_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p            [?]     [?]
 *  object_info_p       [?]     [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_multimedia_callback_hdlr(void *apparg_p, JC_OBJECT_INFO *object_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object_info_p)
    {
        ret = mmi_jdd_audio_play(object_info_p);
    }
    else
    {
        ret = mmi_jdd_audio_stop();
    }

    if ((ret != JC_OK) && (ret != JC_ERR_BACKGROUND_AUDIO_PLAY))
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }

    return JC_OK;
}

#ifdef __JBROWSER_DLS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_mime_content_callback_hdlr
 * DESCRIPTION
 *  mime callback handler for cached content
 * PARAMETERS
 *  pAppArg             [?]     [?]
 *  pMimeContent        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_mime_content_callback_hdlr(void *pAppArg, COMM_URL_IND *pMimeContent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;
    FS_HANDLE f_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: mime_content_callback");

    g_mmi_brw_dls_cntx.download_state = BRW_DLS_SUSPENDED;
    g_mmi_brw_dls_cntx.has_more_content_data = FALSE;
    g_mmi_brw_dls_cntx.progress_flag = FALSE;

    g_mmi_brw_cntx.total_content_length = pMimeContent->uiLength;
    g_mmi_brw_cntx.downloaded_content_length = 0;

    g_mmi_brw_dls_cntx.session_id = pMimeContent->uiReferenceID;
    g_mmi_brw_dls_cntx.seq_num = 0;
    g_mmi_brw_dls_cntx.header_length = pMimeContent->uiHeaderLength;
    g_mmi_brw_dls_cntx.content_length = pMimeContent->uiLength;
    g_mmi_brw_dls_cntx.total_current_length = pMimeContent->uiLength;

    g_mmi_brw_dls_cntx.url_p = (JC_UINT8*) jdd_MemAlloc(mmi_ucs2strlen((S8*) pMimeContent->psUrl) + 1, sizeof(JC_UINT8));
    mmi_ucs2_to_asc((S8*) g_mmi_brw_dls_cntx.url_p, (S8*) pMimeContent->psUrl);

    g_mmi_brw_dls_cntx.header_p = (JC_UINT8*) jdd_MemAlloc(g_mmi_brw_dls_cntx.header_length, sizeof(JC_UINT8));
    memcpy(g_mmi_brw_dls_cntx.header_p, pMimeContent->pHeader, g_mmi_brw_dls_cntx.header_length);

    g_mmi_brw_dls_cntx.content_list_p =
        (mmi_brw_dls_content_struct*) jdd_MemAlloc(
                                        g_mmi_brw_dls_cntx.total_current_length,
                                        sizeof(mmi_brw_dls_content_struct));
    g_mmi_brw_dls_cntx.content_list_p->content_p =
        (JC_UINT8*) jdd_MemAlloc(g_mmi_brw_dls_cntx.total_current_length, sizeof(JC_UINT8));

    memcpy(
        g_mmi_brw_dls_cntx.content_list_p->content_p,
        pMimeContent->pBuffer,
        g_mmi_brw_dls_cntx.total_current_length);
    g_mmi_brw_dls_cntx.content_list_p->current_length = g_mmi_brw_dls_cntx.total_current_length;
    g_mmi_brw_dls_cntx.content_list_p->next = NULL;

    g_mmi_brw_dls_cntx.content_type_p =
        (JC_INT8*) jdd_MemAlloc(strlen(pMimeContent->pszContentType) + 1, sizeof(JC_INT8));
    strcpy(g_mmi_brw_dls_cntx.content_type_p, pMimeContent->pszContentType);

    g_mmi_brw_dls_cntx.file_name_p = mmi_brw_get_file_name((S8*) pMimeContent->psUrl, '/');

    if (g_mmi_brw_dls_cntx.file_name_p != NULL)
    {
        f_handle = FS_GetAttributes(g_mmi_brw_dls_cntx.file_name_p);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: FS_GetAttributes returns", f_handle);
    }

    if (g_mmi_brw_dls_cntx.file_name_p == NULL || f_handle == FS_INVALID_FILENAME)
    {
        /* File Name is not valid. Creating a temp file name */
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: Invalid file name");
        if (g_mmi_brw_dls_cntx.file_name_p != NULL)
        {
            jdd_MemFree(g_mmi_brw_dls_cntx.file_name_p);
            g_mmi_brw_dls_cntx.file_name_p = NULL;
        }

        g_mmi_brw_dls_cntx.file_name_p = mmi_brw_dls_get_temp_file_name();
    }

    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;

    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count)
    {
        ClearExitHandler();
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: mime_content: ClearExitHandler");
    }

    mmi_brw_dls_send_file_dl_ind();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_header_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                        [?]     [?]
 *  browser_header_indication_p     [?]     [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_dls_header_info_callback_hdlr(void *apparg_p, COMM_HEADER_INDICATION *browser_header_indication_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;
    FS_HANDLE f_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: dls_header_info");

    if (browser_header_indication_p->uiHeaderLength > 2000)
    {
        ASSERT(0);
    }

    g_mmi_brw_cntx.total_content_length = browser_header_indication_p->uiContentLength;
    g_mmi_brw_cntx.downloaded_content_length = 0;

    g_mmi_brw_dls_cntx.session_id = browser_header_indication_p->uiRequestID;
    g_mmi_brw_dls_cntx.seq_num = 0;
    g_mmi_brw_dls_cntx.header_length = browser_header_indication_p->uiHeaderLength;
    g_mmi_brw_dls_cntx.content_length = browser_header_indication_p->uiContentLength;
    g_mmi_brw_dls_cntx.total_current_length = 0;
    g_mmi_brw_dls_cntx.download_state = BRW_DLS_FIRST_CHUNK;
    g_mmi_brw_dls_cntx.progress_flag = TRUE;
    g_mmi_brw_dls_cntx.has_more_content_data = FALSE;

    g_mmi_brw_dls_cntx.url_p =
        (JC_UINT8*) jdd_MemAlloc(mmi_ucs2strlen((S8*) browser_header_indication_p->psUrl) + 1, sizeof(JC_UINT8));
    mmi_ucs2_to_asc((S8*) g_mmi_brw_dls_cntx.url_p, (S8*) browser_header_indication_p->psUrl);

    g_mmi_brw_dls_cntx.header_p = (JC_UINT8*) jdd_MemAlloc(g_mmi_brw_dls_cntx.header_length, sizeof(JC_UINT8));
    memcpy(g_mmi_brw_dls_cntx.header_p, browser_header_indication_p->pucHeader, g_mmi_brw_dls_cntx.header_length);

    g_mmi_brw_dls_cntx.file_name_p = mmi_brw_dls_get_file_name_from_header(
                                        (JC_INT8*) browser_header_indication_p->pucHeader,
                                        browser_header_indication_p->uiHeaderLength,
                                        browser_header_indication_p->eHeaderType);

    if (g_mmi_brw_dls_cntx.file_name_p == NULL)
    {
        g_mmi_brw_dls_cntx.file_name_p = mmi_brw_get_file_name((S8*) browser_header_indication_p->psUrl, '/');
    }

    if (g_mmi_brw_dls_cntx.file_name_p != NULL)
    {
        f_handle = FS_GetAttributes(g_mmi_brw_dls_cntx.file_name_p);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: FS_GetAttributes returns", f_handle);
    }

    if (g_mmi_brw_dls_cntx.file_name_p == NULL || f_handle == FS_INVALID_FILENAME)
    {
        /* File Name is not valid. Creating a temp file name */
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: Invalid file name");
        if (g_mmi_brw_dls_cntx.file_name_p != NULL)
        {
            jdd_MemFree(g_mmi_brw_dls_cntx.file_name_p);
            g_mmi_brw_dls_cntx.file_name_p = NULL;
        }

        g_mmi_brw_dls_cntx.file_name_p = mmi_brw_dls_get_temp_file_name();
    }

    if (browser_header_indication_p->pszContentType == NULL || strlen(browser_header_indication_p->pszContentType) == 0)
    {
        JC_INT8 *mime_type = NULL;

        mime_type = mmi_brw_dls_get_content_type_from_file_name(g_mmi_brw_dls_cntx.file_name_p);
        if (mime_type != NULL)
        {
            g_mmi_brw_dls_cntx.content_type_p = (JC_INT8*) jdd_MemAlloc(strlen(mime_type) + 1, sizeof(JC_UINT8));
            strcpy(g_mmi_brw_dls_cntx.content_type_p, mime_type);
        }
    }
    else
    {
        g_mmi_brw_dls_cntx.content_type_p =
            (JC_INT8*) jdd_MemAlloc(strlen(browser_header_indication_p->pszContentType) + 1, sizeof(JC_INT8));
        strcpy(g_mmi_brw_dls_cntx.content_type_p, browser_header_indication_p->pszContentType);
    }

    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;

    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count || IsScreenPresent(SCR_FMGR_DA_FILE_OPTION))
    {
        ClearExitHandler();
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: dls_header_info: ClearExitHandler");
    }

    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_fetch_indication_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                            [?]     [?]
 *  browser_fetch_url_ind_resp_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_brw_dls_fetch_indication_info_callback_hdlr(
            void *apparg_p,
            COMM_FETCH_URL_IND_RESP *browser_fetch_url_ind_resp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)(%d)", "DLS: dls_fetch_indication",
                         browser_fetch_url_ind_resp_p->uiCurrentLength, browser_fetch_url_ind_resp_p->bHasMoreData,
                         g_mmi_brw_dls_cntx.download_state);

    if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_FIRST_CHUNK)       /* First fetch_indication_info */
    {
        mmi_brw_dls_content_struct *last_content = NULL;
        mmi_brw_dls_content_struct *new_content = NULL;

        g_mmi_brw_dls_cntx.total_current_length += browser_fetch_url_ind_resp_p->uiCurrentLength;

        new_content = (mmi_brw_dls_content_struct*) jdd_MemAlloc(1, sizeof(mmi_brw_dls_content_struct));
        memset(new_content, 0, sizeof(mmi_brw_dls_content_struct));

        new_content->current_length = browser_fetch_url_ind_resp_p->uiCurrentLength;
        new_content->next = NULL;
        new_content->content_p = (JC_UINT8*) jdd_MemAlloc(new_content->current_length, sizeof(JC_UINT8));
        memcpy(new_content->content_p, browser_fetch_url_ind_resp_p->pucBuffer, new_content->current_length);

        last_content = g_mmi_brw_dls_cntx.content_list_p;
        if (last_content != NULL)
        {
            while (last_content->next != NULL)
            {
                last_content = last_content->next;
            }
        }

        if (last_content == NULL)
        {
            g_mmi_brw_dls_cntx.content_list_p = new_content;
        }
        else
        {
            last_content->next = new_content;
        }

        if (g_mmi_brw_dls_cntx.total_current_length + g_mmi_brw_dls_cntx.header_length >= 2000 || browser_fetch_url_ind_resp_p->bHasMoreData == 0)      /* if length exceeds or no more data */
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: Time for Suspend",
                                 g_mmi_brw_dls_cntx.total_current_length + g_mmi_brw_dls_cntx.header_length);

            if (browser_fetch_url_ind_resp_p->bHasMoreData != 0)        /* More chunks are there */
            {
                ret = jdi_BrowserSuspendRequest(g_mmi_brw_pbrowser_ctxt);
                if (ret != JC_OK)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: jdi_BrowserSuspendRequest Failed", ret);
                    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                    mmi_brw_dls_free_cntx_memory();
                    mmi_brw_dls_chk_navigation_history();
                    return ret;
                }
            }
            g_mmi_brw_dls_cntx.download_state = BRW_DLS_SUSPENDED;
            g_mmi_brw_dls_cntx.has_more_content_data = browser_fetch_url_ind_resp_p->bHasMoreData;
            mmi_brw_dls_send_file_dl_ind();
        }
        return JC_OK;
    }
    else
    {
        if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_DOWNLOADING)
        {
            if ((browser_fetch_url_ind_resp_p->bHasMoreData)
                || (!browser_fetch_url_ind_resp_p->bHasMoreData && browser_fetch_url_ind_resp_p->uiCurrentLength))
            {
                g_mmi_brw_cntx.downloaded_content_length += browser_fetch_url_ind_resp_p->uiCurrentLength;
                ret = jdd_FSWrite(
                        (void*)browser_fetch_url_ind_resp_p->pucBuffer,
                        browser_fetch_url_ind_resp_p->uiCurrentLength,
                        1,
                        g_mmi_brw_cntx.dwnld_file_handle);

                if (ret != JC_ERR_FILE_WRITE)
                {
                    if (g_mmi_brw_dls_cntx.progress_flag == TRUE)
                    {
                        mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_DOWNLOADING, WAP_DL_ERROR_OK);
                    }
                }
                else
                {
                    ret = jdd_GetFSWriteErrCode(jdd_MemGetActiveModuleID());
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: ERROR: jdd_FSWrite", ret);

                    g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;
                    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);

                    if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
                    {
                        g_mmi_brw_page_cntx.brw_page_render_status = 1;
                    }

                    mmi_brw_dls_free_dwnld_info(FALSE);
                    mmi_brw_dls_chk_navigation_history();
                    mmi_brw_dls_send_file_err(ret);
                    return JC_ERR_DOWNLOAD_CANCELLED;
                }
            }

            if (!browser_fetch_url_ind_resp_p->bHasMoreData)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: Download Complete",
                                     g_mmi_brw_cntx.downloaded_content_length);
                g_mmi_brw_dls_cntx.download_state = BRW_DLS_COMPLETE;

                if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
                {
                    g_mmi_brw_page_cntx.brw_page_render_status = 1;
                }

                mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_COMPLETE, WAP_DL_ERROR_OK);
                mmi_brw_dls_free_dwnld_info(FALSE);
                mmi_brw_dls_chk_navigation_history();
            }
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: dls_fetch_indication(%d)", g_mmi_brw_dls_cntx.download_state);
            return JC_OK;
        }
        return JC_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_fetch_error_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p            [?]         [?]
 *  ui_reference_id     [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_fetch_error_info_callback_hdlr(void *apparg_p, JC_UINT32 ui_reference_id, JC_RETCODE ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: dls_fetch_error_info", g_mmi_brw_dls_cntx.download_state);

    if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_DOWNLOADING)       /* Connection loss while downloading */
    {
        mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_CONNECTION_CLOSED);
        mmi_brw_dls_free_dwnld_info(FALSE);
    }

    if (g_mmi_brw_dls_cntx.download_state < BRW_DLS_COMPLETE)
    {
        mmi_brw_dls_chk_navigation_history();
    }
    g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;
    mmi_brw_dls_free_cntx_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_send_file_dl_ind
 * DESCRIPTION
 *  To send file download indication to DA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_send_file_dl_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    wap_mmi_file_dl_ind_struct *p_dl_ind_st = NULL;
    wap_mmi_file_dl_var_struct p_dl_var_st = {0};
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 peer_pdu_len = 0, len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "dls_send_file_dl_ind");

    p_dl_ind_st = (wap_mmi_file_dl_ind_struct*) construct_local_para(sizeof(wap_mmi_file_dl_ind_struct), TD_CTRL);
    p_dl_ind_st->session_id = g_mmi_brw_dls_cntx.session_id;

    memset(p_dl_ind_st->url, 0, WAP_DL_MAX_URL_LEN);
    len = strlen((S8*) g_mmi_brw_dls_cntx.url_p);
    strncpy(
        (S8*) p_dl_ind_st->url,
        (S8*) g_mmi_brw_dls_cntx.url_p,
        len > WAP_DL_MAX_URL_LEN ? WAP_DL_MAX_URL_LEN : len);

    memset(p_dl_ind_st->file_name, 0, WAP_DL_MAX_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*) p_dl_ind_st->file_name, (S8*) g_mmi_brw_dls_cntx.file_name_p, sizeof(p_dl_ind_st->file_name));
    jdd_MemFree(g_mmi_brw_dls_cntx.file_name_p);
    g_mmi_brw_dls_cntx.file_name_p = NULL;

    memset(p_dl_ind_st->mime_type, 0, WAP_DL_MAX_MIME_TYPE_LEN);
    if (g_mmi_brw_dls_cntx.content_type_p != NULL)
    {
        len = strlen((S8*) g_mmi_brw_dls_cntx.content_type_p);
        strncpy(
            (S8*) p_dl_ind_st->mime_type,
            g_mmi_brw_dls_cntx.content_type_p,
            len > WAP_DL_MAX_MIME_TYPE_LEN ? WAP_DL_MAX_MIME_TYPE_LEN : len);
    }

    p_dl_ind_st->file_length = g_mmi_brw_dls_cntx.content_length;
    p_dl_var_st.header_len = g_mmi_brw_dls_cntx.header_length;
    p_dl_var_st.header = (kal_uint8*) get_ctrl_buffer(p_dl_var_st.header_len);
    memset(p_dl_var_st.header, 0, p_dl_var_st.header_len);
    memcpy(p_dl_var_st.header, g_mmi_brw_dls_cntx.header_p, p_dl_var_st.header_len);

    p_dl_var_st.content_len = g_mmi_brw_dls_cntx.total_current_length;

    if (p_dl_var_st.content_len)
    {
        mmi_brw_dls_content_struct *temp_content = NULL;
        JC_UINT32 index = 0;
        JC_UINT32 temp_length = 0;

        if (p_dl_var_st.header_len + p_dl_var_st.content_len >= 2000)
        {
            p_dl_var_st.content_len = 2000 - p_dl_var_st.header_len;
        }

        p_dl_var_st.content = (kal_uint8*) get_ctrl_buffer(p_dl_var_st.content_len);
        memset(p_dl_var_st.content, 0, p_dl_var_st.content_len);

        temp_content = g_mmi_brw_dls_cntx.content_list_p;
        temp_length += temp_content->current_length;

        while (temp_content != NULL && temp_length <= p_dl_var_st.content_len)
        {
            memcpy(p_dl_var_st.content + index, temp_content->content_p, temp_content->current_length);
            index += temp_content->current_length;
            temp_content = temp_content->next;

            if (temp_content != NULL)
            {
                temp_length += temp_content->current_length;
            }
        }

        if (temp_content != NULL)
        {
            memcpy(
                p_dl_var_st.content + index,
                temp_content->content_p,
                temp_content->current_length - (temp_length - p_dl_var_st.content_len));
        }
    }

    peer_pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WAP_MMI_FILE_DL_IND, &p_dl_var_st, NULL);

    if (peer_pdu_len > 0)
    {
        peer_buff_ptr = construct_peer_buff(peer_pdu_len, 0, 0, TD_CTRL);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WAP_MMI_FILE_DL_IND, &p_dl_var_st, get_pdu_ptr(peer_buff_ptr, &len))
            != peer_pdu_len)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    if (p_dl_var_st.header)
    {
        free_ctrl_buffer(p_dl_var_st.header);
    }

    if (p_dl_var_st.content)
    {
        free_ctrl_buffer(p_dl_var_st.content);
    }

    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMI_FILE_DL_IND;
    message.oslDataPtr = (oslParaType*) p_dl_ind_st;
    message.oslPeerBuffPtr = peer_buff_ptr;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_file_dl_res_hdlr
 * DESCRIPTION
 *  To handle response message of file download indication from DA
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_file_dl_res_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    wap_mmi_file_dl_res_struct *p_dl_res_st = (wap_mmi_file_dl_res_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)", "DLS: dls_file_dl_res_hdlr", p_dl_res_st->result,
                         g_mmi_brw_dls_cntx.download_state);

    if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_SUSPENDED)
    {
        switch (p_dl_res_st->result)
        {
            case WAP_DL_ERROR_CANCELLED:
                g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                if (g_mmi_brw_dls_cntx.has_more_content_data)
                {
                    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);      /* Download Cancel */
                }

                mmi_brw_dls_chk_navigation_history();
                mmi_brw_dls_free_cntx_memory();
                break;

            case WAP_DL_ERROR_OK:
                if (p_dl_res_st->session_id == g_mmi_brw_dls_cntx.session_id)
                {
                    if (g_mmi_brw_cntx.total_content_length != 0 && mmi_brw_dls_is_free_space_available(p_dl_res_st->file_path) == FALSE)       /* Free Space not available */
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "DLS: ERROR: No Space Available");

                        g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                        if (g_mmi_brw_dls_cntx.has_more_content_data)
                        {
                            jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                        }

                        mmi_brw_dls_chk_navigation_history();
                        mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_DISK_FULL);
                        mmi_brw_dls_free_cntx_memory();
                    }
                    else
                    {
                        ret = jdd_FSInitialize(&g_mmi_brw_cntx.dwnld_fs_handle);
                        if (ret == JC_OK)
                        {
                            g_mmi_brw_dls_cntx.file_path_p =
                                (JC_CHAR*) jdd_MemAlloc(
                                            mmi_ucs2strlen((S8*) p_dl_res_st->file_path) * ENCODING_LENGTH + 2,
                                            sizeof(S8));
                            mmi_ucs2cpy((S8*) g_mmi_brw_dls_cntx.file_path_p, (S8*) p_dl_res_st->file_path);
                            g_mmi_brw_cntx.dwnld_file_handle = jdd_FSOpen(
                                                                g_mmi_brw_cntx.dwnld_fs_handle,
                                                                p_dl_res_st->file_path,
                                                                E_CREATE_SHARED_WRITE_MODE);

                            if (!g_mmi_brw_cntx.dwnld_file_handle)
                            {
                                ret = jdd_GetFSLastErrCode(jdd_MemGetActiveModuleID());
                                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: ERROR: jdd_FSOpen", ret);

                                g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                                if (g_mmi_brw_dls_cntx.has_more_content_data)
                                {
                                    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                                }

                                if (g_mmi_brw_dls_cntx.file_path_p != NULL)
                                {
                                    jdd_MemFree(g_mmi_brw_dls_cntx.file_path_p);
                                    g_mmi_brw_dls_cntx.file_path_p = NULL;
                                }
                                jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
                                g_mmi_brw_cntx.dwnld_fs_handle = NULL;

                                mmi_brw_dls_chk_navigation_history();
                                mmi_brw_dls_send_file_err(ret);
                                mmi_brw_dls_free_cntx_memory();
                                return;
                            }
                            else
                            {
                                if (g_mmi_brw_dls_cntx.total_current_length)    /* Not a zero byte chunk */
                                {
                                    mmi_brw_dls_content_struct *temp_content = NULL;

                                    /* Write chunks to file */
                                    g_mmi_brw_cntx.downloaded_content_length += g_mmi_brw_dls_cntx.total_current_length;

                                    temp_content = g_mmi_brw_dls_cntx.content_list_p;
                                    while (temp_content != NULL)
                                    {
                                        ret = jdd_FSWrite(
                                                (void*)temp_content->content_p,
                                                temp_content->current_length,
                                                1,
                                                g_mmi_brw_cntx.dwnld_file_handle);

                                        if (ret == JC_ERR_FILE_WRITE)
                                        {
                                            break;
                                        }

                                        temp_content = temp_content->next;
                                    }

                                    if (ret != JC_ERR_FILE_WRITE)
                                    {
                                        if (g_mmi_brw_dls_cntx.progress_flag == TRUE)
                                        {
                                            mmi_brw_dls_send_file_dl_progress_ind(
                                                WAP_DL_STATUS_DOWNLOADING,
                                                WAP_DL_ERROR_OK);
                                        }
                                    }
                                    else
                                    {
                                        ret = jdd_GetFSWriteErrCode(jdd_MemGetActiveModuleID());

                                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: ERROR: jdd_FSWrite", ret);

                                        g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                                        if (g_mmi_brw_dls_cntx.has_more_content_data)
                                        {
                                            jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                                        }

                                        if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
                                        {
                                            g_mmi_brw_page_cntx.brw_page_render_status = 1;
                                        }

                                        mmi_brw_dls_chk_navigation_history();
                                        mmi_brw_dls_free_dwnld_info(FALSE);
                                        mmi_brw_dls_free_cntx_memory();
                                        mmi_brw_dls_send_file_err(ret);
                                        return;
                                    }
                                }

                                if (g_mmi_brw_dls_cntx.has_more_content_data == 0)      /* First and Last chunk */
                                {
                                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: Download Complete",
                                                         g_mmi_brw_cntx.downloaded_content_length);
                                    g_mmi_brw_dls_cntx.download_state = BRW_DLS_COMPLETE;

                                    if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
                                    {
                                        g_mmi_brw_page_cntx.brw_page_render_status = 1;
                                    }

                                    mmi_brw_dls_chk_navigation_history();
                                    mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_COMPLETE, WAP_DL_ERROR_OK);
                                    mmi_brw_dls_free_dwnld_info(FALSE);
                                    mmi_brw_dls_free_cntx_memory();
                                }
                                else    /* More chunks to get */
                                {
                                    g_mmi_brw_dls_cntx.download_state = BRW_DLS_DOWNLOADING;
                                    jdi_BrowserResumeRequest(g_mmi_brw_pbrowser_ctxt);  /* Download Start */
                                    mmi_brw_dls_free_cntx_memory();
                                }
                            }
                        }
                        else
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: ERROR: jdd_FSInitialize", ret);

                            g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                            if (g_mmi_brw_dls_cntx.has_more_content_data)
                            {
                                jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                            }

                            mmi_brw_dls_chk_navigation_history();
                            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_FILE_ACCESS);
                            mmi_brw_dls_free_cntx_memory();
                        }
                    }
                }
                else
                {
                    g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                    if (g_mmi_brw_dls_cntx.has_more_content_data)
                    {
                        jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                    }

                    mmi_brw_dls_chk_navigation_history();
                    mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_INVALID_SESSION_ID);      /* WAP_DL_STATUS_ABORT && WAP_DL_ERROR_INVALID_SESSION_ID */
                    mmi_brw_dls_free_cntx_memory();
                }
                break;

            default:    /* Result is other than WAP_DL_ERROR_OK and WAP_DL_ERROR_CANCELLED. */
                g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

                if (g_mmi_brw_dls_cntx.has_more_content_data)
                {
                    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                }

                mmi_brw_dls_chk_navigation_history();
                mmi_brw_dls_free_cntx_memory();
                break;
        }
    }
    else
    {
        if (p_dl_res_st->result == WAP_DL_ERROR_OK)
        {
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_CONNECTION_CLOSED);
            mmi_brw_dls_free_cntx_memory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_send_file_dl_progress_ind
 * DESCRIPTION
 *  To send file progress information to DA
 * PARAMETERS
 *  status      [IN]        
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_send_file_dl_progress_ind(U8 status, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    wap_mmi_file_dl_progress_ind_struct *p_dl_prg_ind_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)", "DLS: dls_send_file_dl_progress_ind", status, cause);

    p_dl_prg_ind_st =
        (wap_mmi_file_dl_progress_ind_struct*) construct_local_para(
                                                sizeof(wap_mmi_file_dl_progress_ind_struct),
                                                TD_CTRL);

    g_mmi_brw_dls_cntx.progress_flag = FALSE;
    g_mmi_brw_dls_cntx.seq_num++;

    p_dl_prg_ind_st->session_id = g_mmi_brw_dls_cntx.session_id;
    p_dl_prg_ind_st->seq_num = g_mmi_brw_dls_cntx.seq_num;
    p_dl_prg_ind_st->status = status;
    p_dl_prg_ind_st->cause = cause;
    p_dl_prg_ind_st->acc_size = g_mmi_brw_cntx.downloaded_content_length;

    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND;
    message.oslDataPtr = (oslParaType*) p_dl_prg_ind_st;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_file_dl_progress_res_hdlr
 * DESCRIPTION
 *  To handle response message of file progress information from DA
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_file_dl_progress_res_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_progress_res_struct *p_dl_prg_res_st = (wap_mmi_file_dl_progress_res_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: dls_file_dl_progress_res", g_mmi_brw_dls_cntx.download_state);

    if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_DOWNLOADING)
    {
        if (g_mmi_brw_dls_cntx.session_id != p_dl_prg_res_st->session_id)
        {
            g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

            jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_INVALID_SESSION_ID);      /* WAP_DL_STATUS_ABORT && WAP_DL_ERROR_INVALID_SESSION_ID */
        }
        else
        {
            g_mmi_brw_dls_cntx.progress_flag = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_file_dl_stop_req_hdlr
 * DESCRIPTION
 *  To handle file download request message from DA
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_file_dl_stop_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_stop_req_struct *p_dl_stop_req = (wap_mmi_file_dl_stop_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "DLS: dls_file_dl_stop_req", g_mmi_brw_dls_cntx.download_state);

    if (g_mmi_brw_dls_cntx.download_state == BRW_DLS_DOWNLOADING)
    {
        if (g_mmi_brw_dls_cntx.session_id != p_dl_stop_req->session_id)
        {
            mmi_brw_dls_send_file_dl_stop_rsp(WAP_DL_STATUS_DOWNLOADING, WAP_DL_ERROR_INVALID_SESSION_ID);
        }
        else
        {
            jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
            g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

            mmi_brw_dls_chk_navigation_history();
            mmi_brw_dls_free_dwnld_info(FALSE);
            mmi_brw_dls_send_file_dl_stop_rsp(WAP_DL_STATUS_CANCELLED, WAP_DL_ERROR_OK);
        }
    }
    else
    {
        mmi_brw_dls_send_file_dl_stop_rsp(WAP_DL_STATUS_COMPLETE, WAP_DL_ERROR_CANCELLED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_send_file_dl_stop_rsp
 * DESCRIPTION
 *  To send response of file donwload request to DA
 * PARAMETERS
 *  status      [IN]        
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_send_file_dl_stop_rsp(U8 status, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    wap_mmi_file_dl_stop_rsp_struct *p_dl_stop_rsp =
        (wap_mmi_file_dl_stop_rsp_struct*) construct_local_para(sizeof(wap_mmi_file_dl_stop_rsp_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)", "DLS: dls_send_file_dl_stop_rsp", status, cause);

    p_dl_stop_rsp->session_id = g_mmi_brw_dls_cntx.session_id;
    p_dl_stop_rsp->seq_num = g_mmi_brw_dls_cntx.seq_num;
    p_dl_stop_rsp->status = status;
    p_dl_stop_rsp->cause = cause;
    p_dl_stop_rsp->acc_size = g_mmi_brw_cntx.downloaded_content_length;

    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMI_FILE_DL_STOP_RSP;
    message.oslDataPtr = (oslParaType*) p_dl_stop_rsp;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_is_free_space_available
 * DESCRIPTION
 *  To determine if free space is available for download
 * PARAMETERS
 *  file_path       [?]     [?]
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_brw_dls_is_free_space_available(void *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    FS_DiskInfo disk_info;
    S8 drv_name[16];
    U64 disk_free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(drv_name, 0, sizeof(drv_name));
    mmi_ucs2ncpy((PS8) drv_name, (PS8) file_path, 3);
    fs_ret = FS_GetDiskInfo((PU16) drv_name, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space > g_mmi_brw_cntx.total_content_length)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_send_file_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_send_file_err(JC_RETCODE err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err_code)
    {
        case JC_ERR_FILE_INVALID_PATH:
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_INVALID_FILE);
            break;

        case JC_ERR_FILE_FULL:
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_DISK_FULL);
            break;

        case JC_ERR_FILE_IS_READ_ONLY:
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_FILE_READ_ONLY);
            break;

        case JC_ERR_FILE_INVALID_ACCESS:
        default:
            mmi_brw_dls_send_file_dl_progress_ind(WAP_DL_STATUS_ABORTED, WAP_DL_ERROR_FILE_ACCESS);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_chk_navigation_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_chk_navigation_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count || IsScreenPresent(SCR_FMGR_DA_FILE_OPTION))
    {
        mmi_brw_set_data_connection_deactive_flag(E_TRUE);
        mmi_brw_deinit_event();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_get_content_type_from_file_name
 * DESCRIPTION
 *  Returns mime type based on file name.
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  JC_CHAR *
 *****************************************************************************/
JC_INT8 *mmi_brw_dls_get_content_type_from_file_name(JC_CHAR *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type_st = NULL;
    JC_INT8 *mime_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type_st = mime_get_file_type(file_name);
    if (mime_type_st)
    {
        mime_type = mime_type_st->mime_string;
    }

    return mime_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_get_file_name_from_header
 * DESCRIPTION
 *  Parses the header to get a file name
 * PARAMETERS
 *  header_p            [IN]        
 *  header_len          [IN]        
 *  header_type         [IN]        
 * RETURNS
 *  JC_CHAR *
 *****************************************************************************/
JC_CHAR *mmi_brw_dls_get_file_name_from_header(JC_INT8 *header_p, JC_UINT32 header_len, ECommHeaderType header_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 *disposition = NULL;
    JC_RETCODE ret;
    JC_INT32 file_index = 0;
    JC_INT32 end_index = 0;
    JC_INT8 *temp_file_name = NULL;
    JC_CHAR *file_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdi_CommunicationParseHeader(header_p, header_len, header_type, "Content-Disposition", &disposition);
    if (JC_OK == ret && NULL != disposition)
    {
        file_index = jdi_UtilsIndexOfSubString(disposition, "filename=", 0);
        if (file_index > 0)
        {
            file_index += jc_strlen("filename=");
            if (disposition[file_index] == '\"')
            {
                file_index++;
                end_index = jdi_UtilsIndexOf('\"', disposition, file_index);
            }

            if (end_index > 0)
            {
                temp_file_name = jdi_UtilsStrCopyIndex(disposition, file_index, end_index - 1);
            }
            else
            {
                temp_file_name = jdi_UtilsStrCopyIndex(disposition, file_index, jc_strlen(disposition) - 1);
            }

            if (NULL != temp_file_name)
            {
                jdi_UtilsCharToTchar(&file_name, temp_file_name);
            }
        }
    }

    if (NULL != disposition)
    {
        jdd_MemFree(disposition);
    }

    if (NULL != temp_file_name)
    {
        jdd_MemFree(temp_file_name);
    }

    return file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_get_temp_file_name
 * DESCRIPTION
 *  Gives a temp file name
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_CHAR *
 *****************************************************************************/
JC_CHAR *mmi_brw_dls_get_temp_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT16 path_buf[WAP_DL_MAX_FILE_NAME_LEN] = {0};
    JC_UINT32 fname_len = 0;
    JC_UINT32 fs_id = 0;
    JC_CHAR *file_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_id = jdd_FSGetUniqueTransationId();
    kal_wsprintf(path_buf, "%5d", fs_id);
    fname_len = kal_wstrlen(path_buf) * 2 + 2;
    file_name = jdd_MemAlloc(1, fname_len);
    jc_memcpy(file_name, path_buf, fname_len);

    return file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_free_cntx_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_free_cntx_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_dls_content_struct *temp_content = NULL;
    mmi_brw_dls_content_struct *prev_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: dls_free_cntx_memory");

    if (g_mmi_brw_dls_cntx.file_name_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_dls_cntx.file_name_p);
        g_mmi_brw_dls_cntx.file_name_p = NULL;
    }

    if (g_mmi_brw_dls_cntx.url_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_dls_cntx.url_p);
        g_mmi_brw_dls_cntx.url_p = NULL;
    }

    if (g_mmi_brw_dls_cntx.content_type_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_dls_cntx.content_type_p);
        g_mmi_brw_dls_cntx.content_type_p = NULL;
    }

    if (g_mmi_brw_dls_cntx.header_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_dls_cntx.header_p);
        g_mmi_brw_dls_cntx.header_p = NULL;
    }

    temp_content = g_mmi_brw_dls_cntx.content_list_p;
    while (temp_content != NULL)
    {
        prev_content = temp_content;
        temp_content = temp_content->next;
        jdd_MemFree(prev_content->content_p);
        jdd_MemFree(prev_content);
    }

    g_mmi_brw_dls_cntx.content_list_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dls_free_dwnld_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  deletefile      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dls_free_dwnld_info(BOOL deletefile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "DLS: dls_free_cntx_memory");

    if (g_mmi_brw_cntx.dwnld_file_handle)
    {
        jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
        g_mmi_brw_cntx.dwnld_file_handle = NULL;
        if (g_mmi_brw_dls_cntx.file_path_p != NULL && g_mmi_brw_cntx.dwnld_fs_handle != NULL)
        {
            if (deletefile)
            {
                jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_dls_cntx.file_path_p);   /* Delete file */
            }
            jdd_MemFree(g_mmi_brw_dls_cntx.file_path_p);
            g_mmi_brw_dls_cntx.file_path_p = NULL;
        }
    }
    if (g_mmi_brw_cntx.dwnld_fs_handle)
    {
        jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        g_mmi_brw_cntx.dwnld_fs_handle = NULL;
    }
}

#else /* __JBROWSER_DLS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_mime_content_callback_hdlr
 * DESCRIPTION
 *  mime callback handler for cached content
 * PARAMETERS
 *  apparg_p            [?]     [?]
 *  mime_content_p      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_mime_content_callback_hdlr(void *apparg_p, COMM_URL_IND *mime_content_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 download_msg[200] = {0};
    S8 tmp_str_ascii[50] = {0};
    S8 tmp_str_ucs2[100] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = FALSE;
    memset((void*)&g_mmi_brw_cntx.dwnld_mime_info, 0, sizeof(JC_MIME_INFO));

    g_mmi_brw_cntx.dwnld_mime_info.psContentType = jdi_UtilsStrdup(mime_content_p->pszContentType);
    if (!g_mmi_brw_cntx.dwnld_mime_info.psContentType)
    {
        goto error_handle;
    }
    g_mmi_brw_cntx.dwnld_mime_info.psUrl = jdi_UtilsTcsDup(mime_content_p->psUrl);
    if (!g_mmi_brw_cntx.dwnld_mime_info.psUrl)
    {
        goto error_handle;
    }
    g_mmi_brw_cntx.dwnld_mime_info.pBuffer = jdd_MemAlloc(mime_content_p->uiLength, 1);
    if (!g_mmi_brw_cntx.dwnld_mime_info.pBuffer)
    {
        goto error_handle;
    }
    memcpy(g_mmi_brw_cntx.dwnld_mime_info.pBuffer, mime_content_p->pBuffer, mime_content_p->uiLength);

    g_mmi_brw_cntx.dwnld_mime_info.iBufferLen = mime_content_p->uiLength;

    mmi_ucs2cpy(download_msg, GetString(STR_ID_BRW_DOWNLOAD_QUERY));
    mmi_ucs2cat(download_msg, "\n");

    if (mime_content_p->uiLength)
    {
        mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_CONTENT_SIZE));
        mmi_ucs2cat(download_msg, ":");

        if (mime_content_p->uiLength >= 1000)
        {
            sprintf(tmp_str_ascii, "%.1f ", (mime_content_p->uiLength / 1024.0));
        }
        else
        {
            sprintf(tmp_str_ascii, "%d ", mime_content_p->uiLength);
        }

        mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
        mmi_ucs2cat(download_msg, tmp_str_ucs2);
        if (mime_content_p->uiLength >= 1000)
        {
            mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_KB));
        }
        else
        {
            mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_BYTES));
        }
    }

    mmi_brw_entry_download_confirm(
        (UI_string_type) download_msg,
        mmi_brw_save_mime_content,
        mmi_brw_cancel_save_mime_content);
    return;

  error_handle:
    mmi_brw_free_dwnld_info_memory();
    DisplayPopup(
        (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_NOT_ENOUGH_MEMORY),
        IMG_GLOBAL_ERROR,
        1,
        MMI_BRW_POPUP_TIME,
        ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_mime_content
 * DESCRIPTION
 *  Save mime content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_mime_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR *filename;
    JC_RETCODE ret;
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = TRUE;
    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count)
    {
        DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        g_mmi_brw_cntx.is_downloading = FALSE;
        goto error_handle;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (jdd_FSInitialize(&g_mmi_brw_cntx.dwnld_fs_handle) == JC_OK)
    {
        jdd_FSGetDownloadFileName(&filename);
        g_mmi_brw_cntx.dwnld_mime_info.psFileName = filename;
        g_mmi_brw_cntx.dwnld_file_handle = jdd_FSOpen(g_mmi_brw_cntx.dwnld_fs_handle, filename, E_CREATE_APPEND_WRITE_MODE);
        if (g_mmi_brw_cntx.dwnld_file_handle)
        {
            ret = jdd_FSWrite(
                    (void*)g_mmi_brw_cntx.dwnld_mime_info.pBuffer,
                    g_mmi_brw_cntx.dwnld_mime_info.iBufferLen,
                    1,
                    g_mmi_brw_cntx.dwnld_file_handle);

            if (ret != 1)
            {
                jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
                jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
                jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);

                DisplayPopup(
                    (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_FULL),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_BRW_POPUP_TIME,
                    ERROR_TONE);
            }
            else
            {
                if (!navlist_count)
                {
                    mmi_brw_set_data_connection_deactive_flag(E_TRUE);
                    mmi_brw_deinit_all();
                }
                jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
                jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);

                ret = jdd_MimeHandler(&g_mmi_brw_cntx.dwnld_mime_info);
                if (ret != JC_OK)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        0,
                        MMI_BRW_POPUP_TIME,
                        ERROR_TONE);
                }
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
    }

  error_handle:
    mmi_brw_free_dwnld_info_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_cancel_save_mime_content
 * DESCRIPTION
 *  Dont save mime content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_cancel_save_mime_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_free_dwnld_info_memory();

    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (navlist_count)
    {
        GoBackHistory();
    }
    else
    {
        mmi_brw_set_data_connection_deactive_flag(E_TRUE);
        mmi_brw_deinit_all();
        GoBacknHistory(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_drm_rights_header_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                        [?]     [?]
 *  browser_header_indication_p     [?]     [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_drm_rights_header_info_callback_hdlr(
            void *apparg_p,
            COMM_HEADER_INDICATION *browser_header_indication_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR *filename;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.show_download_aborted_popup = TRUE;
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.show_download_aborted_popup = FALSE;
        goto error_handle;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    memset((void*)&g_mmi_brw_cntx.dwnld_mime_info, 0, sizeof(JC_MIME_INFO));

    ret = jdd_FSInitialize(&g_mmi_brw_cntx.dwnld_fs_handle);
    if (ret == JC_OK)
    {
        jdd_FSGetDownloadFileName(&filename);
        g_mmi_brw_cntx.dwnld_mime_info.psFileName = filename;
        g_mmi_brw_cntx.dwnld_file_handle = jdd_FSOpen(g_mmi_brw_cntx.dwnld_fs_handle, filename, E_CREATE_APPEND_WRITE_MODE);
        if (!g_mmi_brw_cntx.dwnld_file_handle)
        {
            jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
            ret = JC_ERR_FILE_OPEN;
            goto error_handle;
        }
    }
    else
    {
        goto error_handle;
    }

    g_mmi_brw_cntx.is_downloading = TRUE;
    g_mmi_brw_cntx.total_content_length = 0;
    g_mmi_brw_cntx.downloaded_content_length = 0;

    g_mmi_brw_cntx.dwnld_mime_info.psContentType = jdi_UtilsStrdup(browser_header_indication_p->pszContentType);
    g_mmi_brw_cntx.dwnld_mime_info.psUrl = jdi_UtilsTcsDup(browser_header_indication_p->psUrl);

    if (browser_header_indication_p->uiContentLength)
    {
        g_mmi_brw_cntx.total_content_length = browser_header_indication_p->uiContentLength;
        g_mmi_brw_cntx.dwnld_mime_info.iBufferLen = browser_header_indication_p->uiContentLength;
    }

    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
    return JC_OK;

  error_handle:
    if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
    {
        jdd_MemFree(g_mmi_brw_cntx.dwnld_mime_info.psFileName);
        g_mmi_brw_cntx.dwnld_mime_info.psFileName = NULL;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_drm_rights_fetch_indication_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                            [?]     [?]
 *  browser_fetch_url_ind_resp_p        [?]     [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_drm_rights_fetch_indication_info_callback_hdlr(
            void *apparg_p,
            COMM_FETCH_URL_IND_RESP *browser_fetch_url_ind_resp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((browser_fetch_url_ind_resp_p->bHasMoreData) ||
        (!browser_fetch_url_ind_resp_p->bHasMoreData && browser_fetch_url_ind_resp_p->uiCurrentLength))
    {
        g_mmi_brw_cntx.downloaded_content_length += browser_fetch_url_ind_resp_p->uiCurrentLength;
        ret = jdd_FSWrite(
                (void*)browser_fetch_url_ind_resp_p->pucBuffer,
                browser_fetch_url_ind_resp_p->uiCurrentLength,
                1,
                g_mmi_brw_cntx.dwnld_file_handle);

        if (ret != 1)
        {
            jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
            jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
            jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
            if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
            {
                g_mmi_brw_page_cntx.brw_page_render_status = 1;
            }
            goto error_handle;
        }
    }
    if (!browser_fetch_url_ind_resp_p->bHasMoreData)
    {
        U8 deinit_done_flag = 0;

        g_mmi_brw_cntx.is_downloading = FALSE;
        jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
        jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        if (IsScreenPresent(SCR_FMGR_DA_FILE_OPTION))
        {
            ClearExitHandler();
            mmi_brw_set_data_connection_deactive_flag(E_TRUE);
            mmi_brw_deinit_event();
            deinit_done_flag = 1;
        }

        jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
        if (!navlist_count && !deinit_done_flag)
        {
            mmi_brw_set_data_connection_deactive_flag(E_TRUE);
            mmi_brw_deinit_event();
        }

        if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
        {
            g_mmi_brw_page_cntx.brw_page_render_status = 1;
        }

        ret = jdd_MimeHandler(&g_mmi_brw_cntx.dwnld_mime_info);
        goto error_handle;
    }
    return JC_OK;

  error_handle:
    mmi_brw_free_dwnld_info_memory();
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_drm_rights_fetch_error_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p            [?]         
 *  ui_reference_id     [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_drm_rights_fetch_error_info_callback_hdlr(void *apparg_p, JC_UINT32 ui_reference_id, JC_RETCODE ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.dwnld_file_handle)
    {
        jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
        g_mmi_brw_cntx.dwnld_file_handle = NULL;
    }

    if (g_mmi_brw_cntx.dwnld_fs_handle)
    {
        if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
        {
            jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
        }
        jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        g_mmi_brw_cntx.dwnld_fs_handle = NULL;
    }

    mmi_brw_free_dwnld_info_memory();
    g_mmi_brw_cntx.is_downloading = FALSE;
    g_mmi_brw_cntx.is_download_suspended = FALSE;
    g_mmi_brw_cntx.show_download_aborted_popup = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_header_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_arg_p                       [?]     [?]
 *  browser_header_indication_p     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_header_info_callback_hdlr(void *app_arg_p, COMM_HEADER_INDICATION *browser_header_indication_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 download_msg[200] = {0};
    S8 tmp_str_ascii[50] = {0};
    S8 tmp_str_ucs2[100] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserSuspendRequest(g_mmi_brw_pbrowser_ctxt);
    g_mmi_brw_cntx.is_download_suspended = TRUE;
    g_mmi_brw_cntx.total_content_length = 0;
    g_mmi_brw_cntx.downloaded_content_length = 0;
    memset((void*)&g_mmi_brw_cntx.dwnld_mime_info, 0, sizeof(JC_MIME_INFO));
    g_mmi_brw_cntx.dwnld_mime_info.psContentType = jdi_UtilsStrdup(browser_header_indication_p->pszContentType);
    g_mmi_brw_cntx.dwnld_mime_info.psUrl = jdi_UtilsTcsDup(browser_header_indication_p->psUrl);
    g_mmi_brw_cntx.download_size_in_kb = FALSE;
    if (browser_header_indication_p->uiContentLength)
    {
        g_mmi_brw_cntx.total_content_length = browser_header_indication_p->uiContentLength;
        if (g_mmi_brw_cntx.total_content_length >= 1000)
        {
            g_mmi_brw_cntx.download_size_in_kb = TRUE;
        }
        else
        {
            g_mmi_brw_cntx.download_size_in_kb = FALSE;
        }

        g_mmi_brw_cntx.dwnld_mime_info.iBufferLen = browser_header_indication_p->uiContentLength;
    }

    mmi_ucs2cpy(download_msg, GetString(STR_ID_BRW_DOWNLOAD_QUERY));
    mmi_ucs2cat(download_msg, "\n");

    if (g_mmi_brw_cntx.total_content_length)
    {
        mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_CONTENT_SIZE));
        mmi_ucs2cat(download_msg, ":");

        if (g_mmi_brw_cntx.download_size_in_kb)
        {
            sprintf(tmp_str_ascii, "%.1f ", (g_mmi_brw_cntx.total_content_length / 1024.0));
        }
        else
        {
            sprintf(tmp_str_ascii, "%d ", g_mmi_brw_cntx.total_content_length);
        }
        mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
        mmi_ucs2cat(download_msg, tmp_str_ucs2);
        if (g_mmi_brw_cntx.download_size_in_kb)
        {
            mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_KB));
        }
        else
        {
            mmi_ucs2cat(download_msg, GetString(STR_ID_BRW_BYTES));
        }

    }
    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
    mmi_brw_entry_download_confirm((UI_string_type) download_msg, mmi_brw_start_dwnld, mmi_brw_cancel_dwnld_and_goback);
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_download_confirm
 * DESCRIPTION
 *  Entry screen for download confirmation
 * PARAMETERS
 *  message         [IN]        
 *  lsk_hdlr        [IN]        
 *  rsk_hdlr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_download_confirm(UI_string_type message, FuncPtr lsk_hdlr, FuncPtr rsk_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_WAP_DOWNLOAD_CONFIRM);
    EntryNewScreen(SCR_ID_BRW_WAP_DOWNLOAD_CONFIRM, mmi_brw_exit_download_confirm, NULL, NULL);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        message,
        IMG_GLOBAL_QUESTION,
        gui_buffer_p);

    SetLeftSoftkeyFunction(lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(rsk_hdlr, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_download_confirm
 * DESCRIPTION
 *  Exit screen for download confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_download_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_brw_cntx.is_downloading)
    {
        jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.is_download_suspended = FALSE;
        mmi_brw_free_dwnld_info_memory();

        jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
        if (!navlist_count)
        {
            DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
        }
    }
    stopRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_fetch_indication_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_arg_p                           [?]     [?]
 *  browser_fetch_url_ind_resp_p        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_fetch_indication_info_callback_hdlr(
            void *app_arg_p,
            COMM_FETCH_URL_IND_RESP *browser_fetch_url_ind_resp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((browser_fetch_url_ind_resp_p->bHasMoreData) ||
        (!browser_fetch_url_ind_resp_p->bHasMoreData && browser_fetch_url_ind_resp_p->uiCurrentLength))
    {
        g_mmi_brw_cntx.downloaded_content_length += browser_fetch_url_ind_resp_p->uiCurrentLength;
        ret = jdd_FSWrite(
                (void*)browser_fetch_url_ind_resp_p->pucBuffer,
                browser_fetch_url_ind_resp_p->uiCurrentLength,
                1,
                g_mmi_brw_cntx.dwnld_file_handle);
        if (ret == 1)
        {
            mmi_brw_update_downloading_msg();
            if (GetActiveScreenId() == SCR_ID_BRW_WAP_DOWNLOAD_PROGRESS)
            {
                cat66_update_progress_string();
            }
        }
        else
        {
            g_mmi_brw_cntx.is_downloading = FALSE;
            if (g_mmi_brw_cntx.dwnld_file_handle)
            {
                jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
                g_mmi_brw_cntx.dwnld_file_handle = NULL;
            }
            if (g_mmi_brw_cntx.dwnld_fs_handle != NULL)
            {
                if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
                {
                    jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
                }
                jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
                g_mmi_brw_cntx.dwnld_fs_handle = NULL;
            }

            if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
            {
                g_mmi_brw_page_cntx.brw_page_render_status = 1;
            }

            GoBackHistory();
            goto error_handle;
        }
    }
    if (!browser_fetch_url_ind_resp_p->bHasMoreData)
    {
        JC_UINT32 navlist_count;

        g_mmi_brw_cntx.is_downloading = FALSE;
        if (g_mmi_brw_cntx.dwnld_file_handle)
        {
            jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
            g_mmi_brw_cntx.dwnld_file_handle = NULL;
        }
        if (g_mmi_brw_cntx.dwnld_fs_handle)
        {
            jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
            g_mmi_brw_cntx.dwnld_fs_handle = NULL;
        }

        if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
        {
            g_mmi_brw_page_cntx.brw_page_render_status = 1;
        }
        DeleteScreenIfPresent(SCR_ID_BRW_WAP_DOWNLOAD_PROGRESS);

        jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
        if (!navlist_count)
        {
            mmi_brw_set_data_connection_deactive_flag(E_TRUE);
            mmi_brw_deinit_event();
        }
        ret = jdd_MimeHandler(&g_mmi_brw_cntx.dwnld_mime_info);
        goto error_handle;
    }
    return JC_OK;

  error_handle:
    mmi_brw_free_dwnld_info_memory();
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_fetch_error_info_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                [?]         [?]
 *  ui_reference_id         [IN]        
 *  ret                     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_fetch_error_info_callback_hdlr(void *apparg_p, JC_UINT32 ui_reference_id, JC_RETCODE ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = FALSE;
    g_mmi_brw_cntx.is_download_suspended = FALSE;

    if (g_mmi_brw_cntx.dwnld_file_handle)
    {
        jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
        g_mmi_brw_cntx.dwnld_file_handle = NULL;
    }
    if (g_mmi_brw_cntx.dwnld_fs_handle)
    {
        if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
        {
            jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
        }
        jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        g_mmi_brw_cntx.dwnld_fs_handle = NULL;
    }

    mmi_brw_free_dwnld_info_memory();

    if (g_mmi_brw_cntx.show_download_aborted_popup)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_DOWNLOAD_ABORTED), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    else
    {
        g_mmi_brw_cntx.show_download_aborted_popup = TRUE;
    }

    DeleteScreenIfPresent(SCR_ID_BRW_WAP_DOWNLOAD_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_dwnld
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_dwnld(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR *filename;
    JC_UINT32 navlist_count;
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = TRUE;
    g_mmi_brw_cntx.show_download_aborted_popup = TRUE;

    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count)
    {
        DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.show_download_aborted_popup = FALSE;
        goto error_handle;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    ret = jdd_FSInitialize(&g_mmi_brw_cntx.dwnld_fs_handle);
    if (ret == JC_OK)
    {
        jdd_FSGetDownloadFileName(&filename);
        g_mmi_brw_cntx.dwnld_mime_info.psFileName = filename;
        g_mmi_brw_cntx.dwnld_file_handle = jdd_FSOpen(g_mmi_brw_cntx.dwnld_fs_handle, filename, E_CREATE_APPEND_WRITE_MODE);
        if (!g_mmi_brw_cntx.dwnld_file_handle)
        {
            jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
            g_mmi_brw_cntx.show_download_aborted_popup = FALSE;
            jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
            g_mmi_brw_cntx.dwnld_fs_handle = NULL;
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            goto error_handle;
        }
    }
    else
    {
        jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.show_download_aborted_popup = FALSE;
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        goto error_handle;
    }

    mmi_brw_entry_dwnld_progress();
    return;

  error_handle:
    mmi_brw_free_dwnld_info_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_cancel_dwnld_and_goback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_cancel_dwnld_and_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = FALSE;
    g_mmi_brw_cntx.is_download_suspended = FALSE;
    g_mmi_brw_cntx.show_download_aborted_popup = FALSE;

    mmi_brw_free_dwnld_info_memory();

    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (navlist_count)
    {
        GoBackHistory();
    }
    else
    {
        mmi_brw_set_data_connection_deactive_flag(E_TRUE);
        mmi_brw_deinit_all();
        GoBacknHistory(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_update_downloading_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_update_downloading_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str_ascii[50];
    S8 tmp_str_ucs2[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.total_content_length)
    {
        if (g_mmi_brw_cntx.download_size_in_kb)
        {
            sprintf(
                tmp_str_ascii,
                "%.1f/%.1f",
                (g_mmi_brw_cntx.downloaded_content_length / 1024.0),
                (g_mmi_brw_cntx.total_content_length / 1024.0));
            mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
            mmi_ucs2cpy(g_mmi_brw_cntx.dwnld_progress_str, tmp_str_ucs2);
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, " ");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_KB));
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, "\n");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_DOWNLOADED));
        }
        else
        {
            sprintf(
                tmp_str_ascii,
                "%d/%d",
                g_mmi_brw_cntx.downloaded_content_length,
                g_mmi_brw_cntx.total_content_length);
            mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
            mmi_ucs2cpy(g_mmi_brw_cntx.dwnld_progress_str, tmp_str_ucs2);
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, " ");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_BYTES));
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, "\n");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_DOWNLOADED));
        }
    }
    else
    {
        if (g_mmi_brw_cntx.downloaded_content_length >= 1000)
        {
            sprintf(tmp_str_ascii, "%.1f", (g_mmi_brw_cntx.downloaded_content_length / 1024.0));
            mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
            mmi_ucs2cpy(g_mmi_brw_cntx.dwnld_progress_str, tmp_str_ucs2);
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, " ");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_KB));
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, "\n");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_DOWNLOADED));
        }
        else
        {
            sprintf(tmp_str_ascii, "%d", g_mmi_brw_cntx.downloaded_content_length);
            mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
            mmi_ucs2cpy(g_mmi_brw_cntx.dwnld_progress_str, tmp_str_ucs2);
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, " ");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_BYTES));
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, "\n");
            mmi_ucs2cat(g_mmi_brw_cntx.dwnld_progress_str, GetString(STR_ID_BRW_DOWNLOADED));
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_dwnld_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_dwnld_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_icon = 0;
    nvram_wap_profile_content_struct *activated_wap_profile;

    activated_wap_profile = mmi_ph_get_activated_wap_profile();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.is_download_suspended)
    {
        jdi_BrowserResumeRequest(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.is_download_suspended = FALSE;
    }

    mmi_brw_update_downloading_msg();

    EntryNewScreen(SCR_ID_BRW_WAP_DOWNLOAD_PROGRESS, mmi_brw_exit_dwnld_progress, NULL, NULL);

    if (mmi_ph_check_data_account_type(activated_wap_profile->data_account) == PH_DATA_ACCOUNT_CSD)
    {
        title_icon = IMG_ID_BRW_CONNECTION_STATUS_CSD;
    }
    else if (mmi_ph_check_data_account_type(activated_wap_profile->data_account) == PH_DATA_ACCOUNT_GPRS)
    {
        title_icon = IMG_ID_BRW_CONNECTION_STATUS_GPRS;
    }

    ShowCategory66Screen(
        STR_ID_BRW_INTERNET_SERVICES,
        title_icon,
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) g_mmi_brw_cntx.dwnld_progress_str,
        IMG_ID_BRW_SAT_WAIT,
        NULL);

    ClearAllKeyHandler();

    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_UP, KEY_REPEAT);

    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_REPEAT);

    SetRightSoftkeyFunction(mmi_brw_abort_dwnld, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_dwnld_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_dwnld_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.is_downloading)
    {
        jdi_BrowserSuspendRequest(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_cntx.is_download_suspended = TRUE;
        h.scrnID = SCR_ID_BRW_WAP_DOWNLOAD_PROGRESS;
        h.entryFuncPtr = mmi_brw_entry_dwnld_progress;
        mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nhistory);
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_abort_dwnld
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_abort_dwnld(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_downloading = FALSE;
    g_mmi_brw_cntx.is_download_suspended = FALSE;

    if (g_mmi_brw_cntx.dwnld_file_handle)
    {
        jdd_FSClose(g_mmi_brw_cntx.dwnld_file_handle);
        g_mmi_brw_cntx.dwnld_file_handle = NULL;
    }
    if (g_mmi_brw_cntx.dwnld_fs_handle)
    {
        if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
        {
            jdd_FSDelete(g_mmi_brw_cntx.dwnld_fs_handle, g_mmi_brw_cntx.dwnld_mime_info.psFileName);
        }
        jdd_FSDeinitialize(g_mmi_brw_cntx.dwnld_fs_handle);
        g_mmi_brw_cntx.dwnld_fs_handle = NULL;
    }

    mmi_brw_free_dwnld_info_memory();

    jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_free_dwnld_info_memory
 * DESCRIPTION
 *  Init function for browser application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_free_dwnld_info_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.dwnld_mime_info.psContentType)
    {
        jdd_MemFree(g_mmi_brw_cntx.dwnld_mime_info.psContentType);
        g_mmi_brw_cntx.dwnld_mime_info.psContentType = NULL;
    }

    if (g_mmi_brw_cntx.dwnld_mime_info.pBuffer)
    {
        jdd_MemFree(g_mmi_brw_cntx.dwnld_mime_info.pBuffer);
        g_mmi_brw_cntx.dwnld_mime_info.pBuffer = NULL;
    }

    if (g_mmi_brw_cntx.dwnld_mime_info.psUrl)
    {
        jdd_MemFree(g_mmi_brw_cntx.dwnld_mime_info.psUrl);
        g_mmi_brw_cntx.dwnld_mime_info.psUrl = NULL;
    }

    if (g_mmi_brw_cntx.dwnld_mime_info.psFileName)
    {
        jdd_MemFree(g_mmi_brw_cntx.dwnld_mime_info.psFileName);
        g_mmi_brw_cntx.dwnld_mime_info.psFileName = NULL;
    }
}

#endif /* __JBROWSER_DLS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_mime_callback_hdlr
 * DESCRIPTION
 *  mime callback handler
 * PARAMETERS
 *  apparg_p                        [?]     [?]
 *  pmime_info_p                    [?]     [?]
 *  pbrowser_fetch_callbacks_p      [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_mime_callback_hdlr(
            void *apparg_p,
            JC_BROWSER_MIME_INFO *pmime_info_p,
            JC_BROWSER_FETCH_CALLBACKS *pbrowser_fetch_callbacks_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __JBROWSER_DLS_SUPPORT__
    g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;

    pbrowser_fetch_callbacks_p->CB_browserFetchHeaderInfo = mmi_brw_dls_header_info_callback_hdlr;
    pbrowser_fetch_callbacks_p->CB_browserFetchResponseInfo = mmi_brw_dls_fetch_indication_info_callback_hdlr;
    pbrowser_fetch_callbacks_p->CB_browserFetchErrorInfo = mmi_brw_dls_fetch_error_info_callback_hdlr;
#else /* __JBROWSER_DLS_SUPPORT__ */ 
    g_mmi_brw_cntx.is_downloading = FALSE;
    g_mmi_brw_cntx.is_download_suspended = FALSE;
    g_mmi_brw_cntx.show_download_aborted_popup = FALSE;

    if ((jdi_UtilsStartsWith(pmime_info_p->psContentType, "application/vnd.oma.drm.rights+xml") == 0) ||
        (jdi_UtilsStartsWith(pmime_info_p->psContentType, "application/vnd.oma.drm.rights+wbxml") == 0))
    {
        pbrowser_fetch_callbacks_p->CB_browserFetchHeaderInfo = mmi_brw_drm_rights_header_info_callback_hdlr;
        pbrowser_fetch_callbacks_p->CB_browserFetchResponseInfo =
            mmi_brw_drm_rights_fetch_indication_info_callback_hdlr;
        pbrowser_fetch_callbacks_p->CB_browserFetchErrorInfo = mmi_brw_drm_rights_fetch_error_info_callback_hdlr;
    }
    else
    {
        pbrowser_fetch_callbacks_p->CB_browserFetchHeaderInfo = mmi_brw_header_info_callback_hdlr;
        pbrowser_fetch_callbacks_p->CB_browserFetchResponseInfo = mmi_brw_fetch_indication_info_callback_hdlr;
        pbrowser_fetch_callbacks_p->CB_browserFetchErrorInfo = mmi_brw_fetch_error_info_callback_hdlr;
    }
#endif /* __JBROWSER_DLS_SUPPORT__ */ 

    return JC_OK;
}

#ifdef BROWSER_PUSH_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_mmi_in_idle_state
 * DESCRIPTION
 *  This API checks whether mmi is idle state or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  return 1 if mmi is in idle state else return  0.
 *****************************************************************************/
static U16 mmi_brw_is_mmi_in_idle_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((IDLE_SCREEN_ID == GetActiveScreenId()) || g_idle_context.ScreenSaverRunFlag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_callback
 * DESCRIPTION
 *  Push callback
 * PARAMETERS
 *  apparg_p            [?]         [?]
 *  service_value_p     [?]         [?]
 *  cb_confirm          [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_push_callback(
            void *apparg_p,
            SERVICE_VALUE *service_value_p,
            CB_BROWSER_PUSH_RESPONSE_HANDLER cb_confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 is_time_modified = 0;

#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_ALERT_TYPE alert_type;
#endif 
    JC_UINT32 brw_total_msg_count;
    JC_UINT32 brw_unread_msg_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != service_value_p->pmHref)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s : %d", "PUSH Href Length",
                             mmi_ucs2strlen((const S8*)service_value_p->pmHref));
    }

    if (NULL != service_value_p->pSICreated)
    {
        is_time_modified = mmi_brw_push_check_for_maximun_time(&service_value_p->pSICreated);
        if (is_time_modified)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "PUSH - Created Time Get Modified ");
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %u-%u-%u %u:%u:%u",
                             "PUSH - Created Time",
                             service_value_p->pSICreated->year,
                             service_value_p->pSICreated->month,
                             service_value_p->pSICreated->day,
                             service_value_p->pSICreated->hour,
                             service_value_p->pSICreated->minute, service_value_p->pSICreated->seconds);
    }

    if (NULL != service_value_p->pSIRcvd)
    {
        is_time_modified = 0;
        is_time_modified = mmi_brw_push_check_for_maximun_time(&service_value_p->pSIRcvd);
        if (is_time_modified)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "PUSH - Received Time Get Modified ");
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %u-%u-%u %u:%u:%u",
                             "PUSH - Received Time",
                             service_value_p->pSIRcvd->year,
                             service_value_p->pSIRcvd->month,
                             service_value_p->pSIRcvd->day,
                             service_value_p->pSIRcvd->hour,
                             service_value_p->pSIRcvd->minute, service_value_p->pSIRcvd->seconds);
    }

    if (NULL != service_value_p->pSIExpires)
    {
        is_time_modified = 0;
        is_time_modified = mmi_brw_push_check_for_maximun_time(&service_value_p->pSIExpires);
        if (is_time_modified)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "PUSH - Expiry Time Get Modified ");
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %u-%u-%u %u:%u:%u",
                             "PUSH - Expiry Time",
                             service_value_p->pSIExpires->year,
                             service_value_p->pSIExpires->month,
                             service_value_p->pSIExpires->day,
                             service_value_p->pSIExpires->hour,
                             service_value_p->pSIExpires->minute, service_value_p->pSIExpires->seconds);
    }

    if (NULL != service_value_p->pmMessage)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s : %d", "PUSH Message Length",
                             mmi_ucs2strlen((const S8*)service_value_p->pmMessage));
    }

    if (ACTION_SIGNAL_NONE_VAL == service_value_p->eActionSignal)
    {
        mmi_brw_delete_push_msg(0);
        return JC_OK;
    }

    if (NULL == g_mmi_brw_push_cntx.service_msg_list_p)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "PUSH Message : Memory not enough");
        return JC_ERR_MEMORY_ALLOCATION;
    }

    mmi_brw_create_push_msg_list();

#ifndef __MMI_UNIFIED_MESSAGE__

    TurnOnBacklight(1);

    if (mmi_brw_is_mmi_in_idle_state())
    {
        PlayMessageArrivalTone();
        mmi_brw_new_push_msg_ind_on_idlescreen();
        g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_FALSE;
    }
    else if (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetActiveScreenId())
    {
        PlayMessageArrivalTone();
        g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_TRUE;
        GoBackHistory();
    }
    else if (MMI_FALSE == g_mmi_brw_push_cntx.push_delete_notification)
    {
        /*
         * if (POPUP_SCREENID == GetActiveScreenId()) 
         * {
         * EntryNewScreen(SCR_ID_BRW_WAP_PUSH_POPUP_DUMMY_SCREEN, NULL, NULL, NULL);
         * }
         */
        ShowStatusIcon(STATUS_ICON_WAP);
        UpdateStatusIcons();
        mmi_msg_entry_new_msg_popup(MSG_NEW_PUSH);
        g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_TRUE;

        /* As we are adding the new message at the top of message list, So 
           if a new message come Nth message will become the (N+1)th message. 
           Vivek - 01082006 */
        if ((TRUE == IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX)) || (SCR_ID_BRW_SERVICE_INBOX == GetActiveScreenId()))
        {
            g_mmi_brw_push_cntx.curr_hilited_item_index++;
        }
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 

    TurnOnBacklight(1);
    /* PlayMessageArrivalTone(); */

    if (!isInCall())
    {
        if ((!mmi_brw_is_mmi_in_idle_state()) &&
            (SCR_ID_UM_NEW_MSG_IND != GetActiveScreenId()) &&
            (MMI_FALSE == g_mmi_brw_push_cntx.push_delete_notification))
        {
            /*
             * if (POPUP_SCREENID == GetActiveScreenId()) 
             * {
             * EntryNewScreen(SCR_ID_BRW_WAP_PUSH_POPUP_DUMMY_SCREEN, NULL, NULL, NULL);
             * }
             */
            ShowStatusIcon(STATUS_ICON_WAP);
            UpdateStatusIcons();
            mmi_msg_entry_new_msg_popup(MSG_NEW_PUSH);
        }
    }
    else
    {
        alert_type = GetMtCallAlertTypeEnum();
        if ((alert_type == MMI_VIBRATION_AND_RING) || (alert_type == MMI_VIBRATION_THEN_RING) ||
            (alert_type == MMI_RING))
        {
            playRequestedTone((U8) SMS_IN_CALL_TONE);
        }
    }

    if ((TRUE == IsScreenPresent(SCR_ID_UM_INBOX)) || (SCR_ID_UM_INBOX == GetActiveScreenId()))
    {
        g_mmi_brw_push_cntx.curr_hilited_item_index++;
    }
    mmi_um_brw_new_push_message_ind(service_value_p);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /* Save to persistant storage */
    jdi_BrowserPushSaveCurrentInfo(g_mmi_brw_pbrowser_ctxt);

    jdi_BrowserPushGetStatistics(g_mmi_brw_pbrowser_ctxt, &brw_total_msg_count, &brw_unread_msg_count);

    if (brw_unread_msg_count > 0)
    {
        /* Display unread message icon on idle screen */
        ShowStatusIcon(STATUS_ICON_WAP);
    }
    else
    {
        /* hide unread push message icon on idle screen */
        HideStatusIcon(STATUS_ICON_WAP);
    }

    g_mmi_brw_push_cntx.push_delete_notification = MMI_FALSE;
    return JC_ERR_WAIT_USER_ACTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_PPG_validate_callback
 * DESCRIPTION
 *  Push PPG validate  callback
 * PARAMETERS
 *  apparg_p                [?]         [?]
 *  b_is_ppg_address        [IN]        
 *  pc_ppg_host_address     [?]         [?]         [?]
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_push_PPG_validate_callback(
            void *apparg_p,
            JC_BOOLEAN b_is_ppg_address,
            JC_INT8 *pc_ppg_host_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_BOOLEAN b_is_ppg_valid = E_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b_is_ppg_address)
    {
        b_is_ppg_valid = mmi_brw_check_ip((PS8) pc_ppg_host_address);
    }

    return b_is_ppg_valid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_inbox_full_callback
 * DESCRIPTION
 *  Push Inbox Full callback
 * PARAMETERS
 *  apparg_p            [?]         [?]
 *  service_value_p     [?]         [?]
 *  cb_confirm          [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_push_inbox_full_callback(
            void *apparg_p,
            SERVICE_VALUE *service_value_p,
            CB_BROWSER_PUSHFULL_RESPONSE_HANDLER cb_confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 brw_total_msg_count, brw_unread_msg_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    if (ACTION_SIGNAL_NONE_VAL == service_value_p->eActionSignal)
    {
        return JC_ERR_NOT_SUPPORTED;
    }
    else
    {
        mmi_brw_delete_push_msg(brw_total_msg_count - 1);
    }

    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_inbox_max_size_callback
 * DESCRIPTION
 *  Push Inbox max size reached callback
 * PARAMETERS
 *  ctxt_p      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_inbox_max_size_callback(void *ctxt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_with_delete_action
 * DESCRIPTION
 *  Push Inbox callback when core will get the push with
 *  delete action.
 * PARAMETERS
 *  ctxt_p      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_with_delete_action(void *ctxt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 brw_total_msg_count = 0;
    JC_UINT32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserPushGetStatistics(g_mmi_brw_pbrowser_ctxt, &brw_total_msg_count, &brw_unread_msg_count);

    if (brw_unread_msg_count > 0)
    {
        /* Display unread message icon on idle screen */
        ShowStatusIcon(STATUS_ICON_WAP);
    }
    else
    {
        /* hide unread push message icon on idle screen */
        HideStatusIcon(STATUS_ICON_WAP);

        /* Added by Vivek 26072006 */
        g_mmi_brw_cntx.push_msg_rcvd_flag = MMI_FALSE;
    }
    UpdateStatusIcons();

    if (NULL == g_mmi_brw_push_cntx.service_msg_list_p)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "PUSH Message : Memory not enough");
        return;
    }

    mmi_brw_create_push_msg_list();

    if ((SCR_ID_BRW_READ_SERVICE_MESSAGE == GetActiveScreenId()) ||
        (SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS == GetActiveScreenId()) ||
        ((SCR_CONFIRM_SCREEN == GetActiveScreenId()) && (SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS == GetCurrScrnId())))
    {
        g_mmi_brw_push_cntx.push_delete_notification = MMI_TRUE;
        /* DisplayPopup((PU8) GetString(STR_GLOBAL_DELETE), IMG_GLOBAL_DELETED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE); */
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_PUSH_INBOX_MODIFIED),
            IMG_GLOBAL_INFO,
            1,
            MMI_BRW_POPUP_TIME,
            SUCCESS_TONE);

    #ifndef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);
    #else 
        DeleteUptoScrID(SCR_ID_UM_INBOX);
    #endif 

    }
    else
    {

    #ifndef __MMI_UNIFIED_MESSAGE__

        if ((SCR_ID_BRW_SERVICE_INBOX_OPTIONS == GetActiveScreenId()) ||
            ((SCR_CONFIRM_SCREEN == GetActiveScreenId()) && (SCR_ID_BRW_SERVICE_INBOX_OPTIONS == GetCurrScrnId())))
        {
            g_mmi_brw_push_cntx.push_delete_notification = MMI_TRUE;
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_INBOX_MODIFIED),
                IMG_GLOBAL_INFO,
                1,
                MMI_BRW_POPUP_TIME,
                SUCCESS_TONE);
            DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);
        }
        else if ((SCR_ID_BRW_SERVICE_INBOX == GetActiveScreenId()) ||
                 (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetActiveScreenId()) ||
                 (SCR_ID_BRW_NEW_PUSH_MESSAGE_IND == GetCurrScrnId()))
        {
            g_mmi_brw_push_cntx.push_delete_notification = MMI_TRUE;
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_INBOX_MODIFIED),
                IMG_GLOBAL_INFO,
                1,
                MMI_BRW_POPUP_TIME,
                SUCCESS_TONE);
        }

    #else /* __MMI_UNIFIED_MESSAGE__ */ 

        if ((SCR_ID_UM_MAIN == GetActiveScreenId()) ||
            (SCR_ID_UM_INBOX == GetActiveScreenId()) || (SCR_ID_UM_NEW_MSG_IND == GetActiveScreenId()))
        {
            g_mmi_brw_push_cntx.push_delete_notification = MMI_TRUE;
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_INBOX_MODIFIED),
                IMG_GLOBAL_INFO,
                1,
                MMI_BRW_POPUP_TIME,
                SUCCESS_TONE);
        }

    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
}
#endif /* BROWSER_PUSH_ENABLE */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_progress_bar_callback
 * DESCRIPTION
 *  Show progress bar callback
 * PARAMETERS
 *  app_arg_p               [?]     [?]
 *  progress_bar_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_brw_show_progress_bar_callback(void *app_arg_p, JC_PROGRESSBAR_INFO *progress_bar_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_rendering_status_callback
 * DESCRIPTION
 *  Page rendering status callback
 * PARAMETERS
 *  app_arg_p                   [?]         [?]
 *  epage_rendering_status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_rendering_status_callback(void *app_arg_p, EPageRenderingStatus epage_rendering_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_animated_title
 * DESCRIPTION
 *  Showing title with appropiate icon and animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_show_animated_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_profile_content_struct *activated_wap_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_page_cntx.brw_page_status_code_stack[1] == E_BROWSER_FETCH_BEGIN)
    {
        activated_wap_profile_p = mmi_ph_get_activated_wap_profile();

        if (mmi_brw_is_animated_title() == MMI_FALSE)
        {
            if (mmi_ph_check_data_account_type(activated_wap_profile_p->data_account) == PH_DATA_ACCOUNT_CSD)
            {
                MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_CSD);
            }
            else if (mmi_ph_check_data_account_type(activated_wap_profile_p->data_account) == PH_DATA_ACCOUNT_GPRS)
            {
                MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_GPRS);
            }
            else
            {
                /* Error */
            }

            g_mmi_brw_cntx.title_icon_animation_status = MMI_TRUE;

            if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
            {
                draw_title();
            }
        }
    }
    else if ((g_mmi_brw_page_cntx.brw_page_status_code_stack[0] == E_BROWSER_PAGE_REQUEST_BEGIN) &&
             (g_mmi_brw_page_cntx.brw_page_status_code_stack[1] != E_BROWSER_FETCH_BEGIN) &&
             (g_mmi_brw_page_cntx.brw_page_status_code_stack[2] == E_BROWSER_RENDERING_BEGIN))
    {

        MMI_title_icon = (PU8) get_image(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
        g_mmi_brw_cntx.title_icon_animation_status = MMI_FALSE;

        if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
        {
            draw_title();
        }
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
        {
            mmi_brw_show_normal_title();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_normal_title
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_show_normal_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_profile_content_struct *activated_wap_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.title_icon_animation_status = MMI_FALSE;
    activated_wap_profile_p = mmi_ph_get_activated_wap_profile();
    if (mmi_ph_check_data_account_type(activated_wap_profile_p->data_account) == PH_DATA_ACCOUNT_CSD)
    {
        MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_CSD_STATIC);
    }
    else if (mmi_ph_check_data_account_type(activated_wap_profile_p->data_account) == PH_DATA_ACCOUNT_GPRS)
    {
        MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_GPRS_STATIC);
    }
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_animated_title
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_brw_is_animated_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_cntx.title_icon_animation_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_empty_navlist_callback
 * DESCRIPTION
 *  Empty Navigation List  callback
 * PARAMETERS
 *  apparg_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_empty_navlist_callback(void *apparg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
    g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
    g_mmi_brw_page_cntx.brw_rsk_label = STR_ID_BRW_EXIT;
    g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_entry_exit_menu;
    if (E_TRUE == mmi_brw_is_back())
    {
        g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_BACK;
        g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_goto_prev_page;
    }
    if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        ChangeRightSoftkey(g_mmi_brw_page_cntx.brw_rsk_label, 0);
        ChangeLeftSoftkey(g_mmi_brw_page_cntx.brw_lsk_label, 0);
        SetLeftSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_lsk_fun_ptr, KEY_EVENT_UP);
        SetRightSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_rsk_fun_ptr, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_request_begin
 * DESCRIPTION
 *  It handle the page request begin status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_request_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_brw_page_cntx.brw_page_status_code_stack, -1, sizeof(g_mmi_brw_page_cntx.brw_page_status_code_stack));
    /* In case of auto page refresh and current screen is rendered page option screen */
    if (GetActiveScreenId() == SCR_ID_BRW_RENDERED_PAGE_OPTIONS)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
    }
    /* The function below added by Shantanu(PMT) - 20060808 */
    /* This function will check the active screen.And if the active screen is not browser
       it will make browser screen the active screen.Specially for listbox */
    mmi_jdd_ui_goback_to_browser_screen();
    /* This flag will intimate the user that the page content has been refreshed if
       while the user is inside the fullscreen editor and when selects done from the 
       input editor option screen */
    mmi_jdd_ui_set_jdd_flag(JDD_AUTO_REFRESH_FLAG, E_TRUE);
    /* We will not allow the user to enter the fullscreen editor if submit button is clicked */
    mmi_jdd_ui_set_jdd_flag(JDD_MANUAL_REFRESH_FLAG, E_TRUE);

    jdi_BrowserSuspendMarqueeTimer(g_mmi_brw_pbrowser_ctxt);

    g_mmi_brw_page_cntx.brw_page_status_code_stack[0] = E_BROWSER_PAGE_REQUEST_BEGIN;
    g_mmi_brw_page_cntx.brw_page_fetch_status = 1;
    g_mmi_brw_page_cntx.brw_is_refresh_display = MMI_FALSE;
    g_mmi_brw_page_cntx.brw_lsk_label = 0;
    g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_CANCEL;
    g_mmi_brw_page_cntx.brw_lsk_fun_ptr = NULL;
    g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_stop_fetch;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_request_terminated
 * DESCRIPTION
 *  It handle the page request terminated status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_request_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.end_key_pressed)
    {
        DisplayIdleScreen();
        return;
    }

    if ((g_mmi_brw_page_cntx.brw_page_render_status == 1) || (g_mmi_brw_page_cntx.brw_cancel_flag))
    {
        if (g_mmi_brw_page_cntx.brw_page_render_status)
        {
            g_mmi_brw_page_cntx.brw_pre_page_render_status = 1;
        }
        if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
        {
            mmi_brw_show_normal_title();
        }

        if (E_TRUE == mmi_brw_is_back())
        {
            g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
            g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_BACK;
            g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
            g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_goto_prev_page;
        }
        else
        {
            if (g_mmi_brw_page_cntx.brw_cancel_flag)
            {
                if (    /* g_mmi_brw_cntx.page_fetch_event == BRW_START_FETCH_EVENT && */
                       (g_mmi_brw_page_cntx.brw_page_render_status != 1) &&
                       (!g_mmi_brw_page_cntx.brw_pre_page_render_status))
                {
                    g_mmi_brw_page_cntx.brw_cancel_flag = 0;
                    g_mmi_brw_page_cntx.brw_page_render_status = 0;
                    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
                    g_mmi_brw_page_cntx.brw_pre_page_render_status = 0;
                    mmi_brw_set_data_connection_deactive_flag(E_TRUE);
                    mmi_brw_deinit_event();
                    /*if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
                    {
                        mmi_brw_set_data_connection_deactive_flag(E_TRUE);
                        mmi_brw_deinit_all();
                        GoBackHistory();
                    }
                    else
                    {
                        mmi_brw_set_data_connection_deactive_flag(E_TRUE);
                        mmi_brw_deinit_all();
                        DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
                    }*/
                    jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);
                    return;

                }
            }

            g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
            g_mmi_brw_page_cntx.brw_rsk_label = STR_ID_BRW_EXIT;
            g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
            g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_entry_exit_menu;
        }
        g_mmi_brw_cntx.enter_add_hist_flag = 0;
    }

    g_mmi_brw_page_cntx.brw_cancel_flag = 0;
    g_mmi_brw_page_cntx.brw_page_render_status = 0;
    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;

    /* Added By Shantanu - 20060810 */
    /* We have to reset the flag so that the user can enter the fullscreen editor */
    mmi_jdd_ui_set_jdd_flag(JDD_MANUAL_REFRESH_FLAG, E_FALSE);

    jdi_BrowserResumeMarqueeTimer(g_mmi_brw_pbrowser_ctxt);

    memset(g_mmi_brw_page_cntx.brw_page_status_code_stack, -1, sizeof(g_mmi_brw_page_cntx.brw_page_status_code_stack));
    jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_fetch_begin
 * DESCRIPTION
 *  It handle the page fetch begin status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_fetch_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_page_cntx.brw_page_status_code_stack[1] = E_BROWSER_FETCH_BEGIN;
    mmi_brw_show_animated_title();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_fetch_terminated
 * DESCRIPTION
 *  It handle the page fetch terminated status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_fetch_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        mmi_brw_show_normal_title();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_rendering_begin
 * DESCRIPTION
 *  It handle the page rendering begin status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_rendering_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_page_cntx.brw_page_status_code_stack[2] = E_BROWSER_RENDERING_BEGIN;
    //      if(mmi_brw_is_animated_title() == MMI_FALSE)
    //      {
    mmi_brw_show_animated_title();
    /* } */
    g_mmi_brw_page_cntx.brw_page_render_status = 1;
    /* Added By Shantanu -20060810 */
    /* We will reset the manual refresh flag so that the user can enter the fullscreen editor
       when rendering is started.We will check this flag while entering the editor screen */
    mmi_jdd_ui_set_jdd_flag(JDD_MANUAL_REFRESH_FLAG, E_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_rendering_terminated
 * DESCRIPTION
 *  It handle the page rendering terminated status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_rendering_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_refresh_begin
 * DESCRIPTION
 *  It handle the page refresh begin status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_refresh_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JDD_UI_DRAW_IMAGE_ON_TIMER_EVENT__
    MMI_JDD_UI_WINDOW_INFO_STRUCT *jdd_window_info_struct_p = NULL;
    JC_UINT32 ui_window_id = 0;
#endif /* __MMI_JDD_UI_DRAW_IMAGE_ON_TIMER_EVENT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mmi_brw_page_cntx.brw_page_fetch_status || g_mmi_brw_page_cntx.brw_is_refresh_display))
    {
        g_mmi_brw_page_cntx.brw_lsk_label = 0;
        g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_CANCEL;
        g_mmi_brw_page_cntx.brw_lsk_fun_ptr = NULL;
        g_mmi_brw_page_cntx.brw_rsk_fun_ptr = NULL;
        g_mmi_brw_page_cntx.brw_page_refresh_disp_status = 1;
    #ifdef __MMI_JDD_UI_DRAW_IMAGE_ON_TIMER_EVENT__
        ui_window_id = mmi_jdd_ui_get_appWindowID(E_TASK_BROWSER_CORE);
        jdd_window_info_struct_p = (MMI_JDD_UI_WINDOW_INFO_STRUCT*) ui_window_id;
        if (jdd_window_info_struct_p != NULL)
        {
            mmi_jdd_ui_flush_image_display_queue(ui_window_id);
        }
    #endif /* __MMI_JDD_UI_DRAW_IMAGE_ON_TIMER_EVENT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_page_refresh_terminated
 * DESCRIPTION
 *  It handle the page refresh terminated status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_page_refresh_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mmi_brw_page_cntx.brw_page_fetch_status || g_mmi_brw_page_cntx.brw_is_refresh_display))
    {
        g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
        g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
        g_mmi_brw_page_cntx.brw_rsk_label = STR_ID_BRW_EXIT;
        g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_entry_exit_menu;
        if (E_TRUE == mmi_brw_is_back())
        {
            g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_BACK;
            g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_goto_prev_page;
        }
        g_mmi_brw_page_cntx.brw_page_refresh_disp_status = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pageupdate_callback
 * DESCRIPTION
 *  It handle the when there is no page status update from core
 * PARAMETERS
 *  apparg_p                [?]         [?]
 *  b_is_script_abort       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pageupdate_callback(void *apparg_p, JC_BOOLEAN b_is_script_abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_brw_pageupdate_callback() called");
    if (g_mmi_brw_page_cntx.brw_page_fetch_status)
    {
        return; /* If page status callback has alredy been called then return */
    }
    if (b_is_script_abort)
    {
        if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
        {
            mmi_brw_show_normal_title();
        }

        if (E_TRUE == mmi_brw_is_back())
        {
            g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
            g_mmi_brw_page_cntx.brw_rsk_label = STR_GLOBAL_BACK;
            g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
            g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_goto_prev_page;
        }
        else
        {
            g_mmi_brw_page_cntx.brw_lsk_label = STR_GLOBAL_OPTIONS;
            g_mmi_brw_page_cntx.brw_rsk_label = STR_ID_BRW_EXIT;
            g_mmi_brw_page_cntx.brw_lsk_fun_ptr = mmi_brw_rendered_page_options;
            g_mmi_brw_page_cntx.brw_rsk_fun_ptr = mmi_brw_entry_exit_menu;
        }
        g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
        jdi_BrowserResumeMarqueeTimer(g_mmi_brw_pbrowser_ctxt);

        memset(
            g_mmi_brw_page_cntx.brw_page_status_code_stack,
            -1,
            sizeof(g_mmi_brw_page_cntx.brw_page_status_code_stack));
        jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);

    }
    if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        mmi_brw_clear_key_handler(KEY_LSK);
        mmi_brw_clear_key_handler(KEY_RSK);
        ChangeRightSoftkey(g_mmi_brw_page_cntx.brw_rsk_label, 0);
        ChangeLeftSoftkey(g_mmi_brw_page_cntx.brw_lsk_label, 0);
        SetLeftSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_lsk_fun_ptr, KEY_EVENT_UP);
        SetRightSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_rsk_fun_ptr, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_status_callback
 * DESCRIPTION
 *  Rendering status callback
 * PARAMETERS
 *  apparg_p                    [?]         
 *  ebrowser_status_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_status_callback(void *apparg_p, E_BROWSER_STATUS_CODE ebrowser_status_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!((GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN) || IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN)))
    {
        if (ebrowser_status_code == E_BROWSER_PAGE_REQUEST_TERMINATED)
        {
            g_mmi_brw_page_cntx.brw_cancel_flag = 0;
            g_mmi_brw_page_cntx.brw_page_render_status = 0;
            g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
            memset(
                g_mmi_brw_page_cntx.brw_page_status_code_stack,
                -1,
                sizeof(g_mmi_brw_page_cntx.brw_page_status_code_stack));
            jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);

        }
        return;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Page status calbk called with status", ebrowser_status_code);
    if (ebrowser_status_code == E_BROWSER_PAGE_REQUEST_BEGIN)
    {
        mmi_brw_handle_page_request_begin();
    }
    else if (ebrowser_status_code == E_BROWSER_PAGE_REQUEST_TERMINATED)
    {
        mmi_brw_handle_page_request_terminated();
    }
    else if (ebrowser_status_code == E_BROWSER_FETCH_BEGIN)
    {
        mmi_brw_handle_page_fetch_begin();
    }
    else if (ebrowser_status_code == E_BROWSER_FETCH_TERMINATED)
    {
        mmi_brw_handle_page_fetch_terminated();
    }
    else if (ebrowser_status_code == E_BROWSER_RENDERING_BEGIN)
    {
        mmi_brw_handle_page_rendering_begin();
    }
    else if (ebrowser_status_code == E_BROWSER_RENDERING_TERMINATED)
    {
        mmi_brw_handle_page_rendering_terminated();
    }
    else if (ebrowser_status_code == E_BROWSER_PAGE_REFRESH_BEGIN)
    {
        mmi_brw_handle_page_refresh_begin();
    }
    else if (ebrowser_status_code == E_BROWSER_PAGE_REFRESH_TERMINATED)
    {
        mmi_brw_handle_page_refresh_terminated();
    }
    else
    {
        ASSERT(0);
        /* assert should fail */
    }

    if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        mmi_brw_clear_key_handler(KEY_LSK);
        mmi_brw_clear_key_handler(KEY_RSK);
        ChangeRightSoftkey(g_mmi_brw_page_cntx.brw_rsk_label, 0);
        ChangeLeftSoftkey(g_mmi_brw_page_cntx.brw_lsk_label, 0);
        SetLeftSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_lsk_fun_ptr, KEY_EVENT_UP);
        SetRightSoftkeyFunction((FuncPtr) g_mmi_brw_page_cntx.brw_rsk_fun_ptr, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_goto_prev_page
 * DESCRIPTION
 *  Fetch the previous page from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_goto_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free the DO List for last rendered page */
    mmi_brw_free_do_list();

    ret = jdi_BrowserBack(g_mmi_brw_pbrowser_ctxt);
    if (JC_OK != ret && JC_ERR_INVALID_STATE != ret)
    {
        ASSERT(0);
        /* Error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_brw_page
 * DESCRIPTION
 *  Exit from browser screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_brw_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_entry_exit_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stop_fetch
 * DESCRIPTION
 *  Fetch stop event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stop_fetch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA eventdata = {0, };
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send browser start up event */
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    eventdata.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    eventdata.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    eventdata.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    /* eventdata.pEventInfo = NULL ; */
    eventdata.uiEventInfoSize = 0;
    eventdata.iEventType = E_BRW_STOP_FETCH_EVENT;

    ret = jdd_QueueSend(&eventdata);

    g_mmi_brw_page_cntx.brw_cancel_flag = 1;
    /* This variable was set when we try to fetch a page through EnterAddress Option
       screen. Reset this flag to 0 when page fetch was cancelled as depending on this
       core will set the title in EnterAddress Title history. */

    jdd_MemSetActiveModuleID(temp_activated_task_id);

    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_authentication_callback
 * DESCRIPTION
 *  Show authentication handler callback.
 * PARAMETERS
 *  apparg_p                [?]     [?]
 *  auth_indication_p       [?]     [?]     [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_show_authentication_callback(void *apparg_p, JC_AUTH_INDICATION *auth_indication_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_FALSE == mmi_brw_is_browser_window_active())
    {
        return JC_OK;
    }
    if (auth_indication_p->pcHeaders == NULL)
    {
        jdd_MMINotificationMessage(JC_ERR_AUTH_METHOD_INVALID, E_NOTIFICATION_ERR, NULL, NULL);
        return JC_ERR_USER_CANCELLED;
    }

    /* Himanshu: Clear the username and password buffer while entering authentication screen */
    memset(g_mmi_brw_cntx.brw_auth_username, 0, sizeof(g_mmi_brw_cntx.brw_auth_username));
    memset(g_mmi_brw_cntx.brw_auth_password, 0, sizeof(g_mmi_brw_cntx.brw_auth_password));

    mmi_brw_entry_auth_handler();
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_do_tag_callback
 * DESCRIPTION
 *  Do tag_ handler callback
 * PARAMETERS
 *  apparg_p        [?]     [?]
 *  do_list_p       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_do_tag_callback(void *apparg_p, JC_DO_LIST *do_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_DO_LIST *temp_do_list_p;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_FALSE == mmi_brw_is_browser_window_active())
    {
        return;
    }

    /* Free the DO List for last rendered page */
    mmi_brw_free_do_list();

    if (NULL != do_list_p)
    {
        mmi_brw_copy_linked_list(do_list_p, &temp_do_list_p);
        if (NULL == temp_do_list_p)
        {
            jdd_MMINotificationMessage((JC_INT32) JC_ERR_MEMORY_ALLOCATION, E_NOTIFICATION_ERR, NULL, NULL);
            return;
        }
        g_mmi_brw_cntx.do_element_count = mmi_brw_get_do_element_count(temp_do_list_p);
    }

    if (g_mmi_brw_cntx.do_element_count != 0)
    {
        g_mmi_brw_cntx.do_element_list =
            (JC_DO_LIST **) jdd_MemAlloc(g_mmi_brw_cntx.do_element_count, sizeof(JC_DO_LIST*));
        if (NULL == g_mmi_brw_cntx.do_element_list)
        {
            mmi_brw_free_duplicate_do_list(&temp_do_list_p);
            jdd_MMINotificationMessage((JC_INT32) JC_ERR_MEMORY_ALLOCATION, E_NOTIFICATION_ERR, NULL, NULL);
            return;
        }

        while (NULL != temp_do_list_p)
        {
            g_mmi_brw_cntx.do_element_list[count] = temp_do_list_p;
            temp_do_list_p = temp_do_list_p->pNext;
            count++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_do_element_count
 * DESCRIPTION
 *  Function to get the number of do elements on the page
 * PARAMETERS
 *  temp_do_list_p      [?]     [?]     [?]
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_brw_get_do_element_count(JC_DO_LIST *temp_do_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (NULL != temp_do_list_p)
    {
        count++;
        temp_do_list_p = temp_do_list_p->pNext;
    }

    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_free_duplicate_do_list
 * DESCRIPTION
 *  Free the memory assign to the duplecate link list.
 * PARAMETERS
 *  temp_do_list_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_free_duplicate_do_list(JC_DO_LIST **temp_do_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_DO_LIST *temp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (NULL != *temp_do_list_p)
    {
        if (NULL != (*temp_do_list_p)->pDoLabel)
        {
            jdd_MemFree((*temp_do_list_p)->pDoLabel);
            (*temp_do_list_p)->pDoLabel = NULL;
        }

        if (NULL != (*temp_do_list_p)->pDoType)
        {
            jdd_MemFree((*temp_do_list_p)->pDoType);
            (*temp_do_list_p)->pDoType = NULL;
        }

        temp_p = *temp_do_list_p;
        *temp_do_list_p = (*temp_do_list_p)->pNext;
        jdd_MemFree(temp_p);
        temp_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_copy_linked_list
 * DESCRIPTION
 *  Function to make a copy of the linked list
 * PARAMETERS
 *  do_list_p           [?]         [?]         [?]
 *  temp_do_list_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_copy_linked_list(JC_DO_LIST *do_list_p, JC_DO_LIST **temp_do_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_DO_LIST *temp_p = NULL;
    JC_DO_LIST *temp_do_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *temp_do_list_p = NULL;

    while (NULL != do_list_p)
    {
        temp_do_node_p = (JC_DO_LIST*) jdd_MemAlloc(1, sizeof(JC_DO_LIST));
        if (NULL == temp_do_node_p)
        {
            mmi_brw_free_duplicate_do_list(temp_do_list_p);
            return;
        }

        temp_do_node_p->pDoElement = do_list_p->pDoElement;

        temp_do_node_p->pDoLabel = (JC_CHAR*) jdi_UtilsTcsDup(do_list_p->pDoLabel);
        if (NULL == temp_do_node_p->pDoLabel)
        {
            jdd_MemFree(temp_do_node_p);
            temp_do_node_p = NULL;

            mmi_brw_free_duplicate_do_list(temp_do_list_p);
            return;
        }

        temp_do_node_p->pDoType = (JC_CHAR*) jdi_UtilsTcsDup(do_list_p->pDoType);
        if (NULL == temp_do_node_p->pDoType)
        {
            jdd_MemFree(temp_do_node_p->pDoLabel);
            temp_do_node_p->pDoLabel = NULL;

            jdd_MemFree(temp_do_node_p);
            temp_do_node_p = NULL;

            mmi_brw_free_duplicate_do_list(temp_do_list_p);
            return;
        }

        if (NULL == *temp_do_list_p)
        {
            *temp_do_list_p = temp_do_node_p;
            temp_p = *temp_do_list_p;
        }
        else
        {
            temp_p->pNext = temp_do_node_p;
            temp_p = temp_p->pNext;
        }

        do_list_p = do_list_p->pNext;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_confirm_callback
 * DESCRIPTION
 *  set confirm callback
 * PARAMETERS
 *  apparg_p        [?]         [?]
 *  mmsg_p          [?]         [?]
 *  msoft1_p        [?]         [?]
 *  msoft2_p        [?]         [?]
 *  cb_confirm      [IN]        
 *  cb_arg_p        [?]         [?]
 *  estatus_p       [?]         [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_set_confirm_callback(
            void *apparg_p,
            JC_CHAR *mmsg_p,
            JC_CHAR *msoft1_p,
            JC_CHAR *msoft2_p,
            BROWSER_CONFIRM_CB cb_confirm,
            void *cb_arg_p,
            JC_BOOLEAN *estatus_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 i_str_len = 0;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_FALSE == mmi_brw_is_browser_window_active())
    {
        return ret;
    }

    if ((NULL != mmsg_p) && ((i_str_len = jc_tcslen(mmsg_p)) > 0))
    {
        g_mmi_brw_cntx.pm_msg = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) mmsg_p) + 1, sizeof(JC_CHAR));
        if (NULL != g_mmi_brw_cntx.pm_msg)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.pm_msg, (S8*) mmsg_p);
        }
        else
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
    }
    else
    {
        *estatus_p = E_FALSE;
        return JC_ERR_INVALID_PARAMETER;
    }

    g_mmi_brw_cntx.call_back_confirm = cb_confirm;
    g_mmi_brw_cntx.arg_p = cb_arg_p;

    if (msoft1_p)
    {
        g_mmi_brw_cntx.confirm_soft1 = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) msoft1_p) + 1, sizeof(JC_CHAR));
        if (NULL != g_mmi_brw_cntx.confirm_soft1)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.confirm_soft1, (S8*) msoft1_p);
        }
        else
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
    }

    if (msoft2_p)
    {
        g_mmi_brw_cntx.confirm_soft2 = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) msoft2_p) + 1, sizeof(JC_CHAR));
        if (NULL != g_mmi_brw_cntx.confirm_soft2)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.confirm_soft2, (S8*) msoft2_p);
        }
        else
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
    }

    mmi_brw_entry_confirm_callback_screen();
    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
    ret = JC_ERR_WAIT_USER_ACTION;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_confirm_callback_screen
 * DESCRIPTION
 *  Entry function for confirm callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_confirm_callback_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_WAP_CONFIRM_SCREEN, NULL, mmi_brw_entry_confirm_callback_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_WAP_CONFIRM_SCREEN);

    ShowCategory165Screen(0, 0, 0, 0, (UI_string_type) g_mmi_brw_cntx.pm_msg, IMG_GLOBAL_QUESTION, gui_buffer_p);

    if (!g_mmi_brw_cntx.confirm_soft1)
    {
        ChangeLeftSoftkeyByString((UI_string_type) GetString(STR_GLOBAL_OK), NULL);
    }
    else
    {
        ChangeLeftSoftkeyByString((UI_string_type) g_mmi_brw_cntx.confirm_soft1, NULL);
    }

    if (!g_mmi_brw_cntx.confirm_soft2)
    {
        ChangeRightSoftkeyByString((UI_string_type) GetString(STR_GLOBAL_CANCEL), NULL);
    }
    else
    {
        ChangeRightSoftkeyByString((UI_string_type) g_mmi_brw_cntx.confirm_soft2, NULL);
    }

    SetLeftSoftkeyFunction(mmi_brw_confirm_msg_LSK_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_confirm_msg_RSK_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_msg_LSK_hdlr
 * DESCRIPTION
 *  LSK handler for confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_msg_LSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    g_mmi_brw_cntx.call_back_confirm(g_mmi_brw_cntx.arg_p, E_TRUE);
    if (g_mmi_brw_cntx.pm_msg)
    {
        jdd_MemFree(g_mmi_brw_cntx.pm_msg);
        g_mmi_brw_cntx.pm_msg = NULL;
    }
    if (g_mmi_brw_cntx.confirm_soft1)
    {
        jdd_MemFree(g_mmi_brw_cntx.confirm_soft1);
        g_mmi_brw_cntx.confirm_soft1 = NULL;
    }
    if (g_mmi_brw_cntx.confirm_soft2)
    {
        jdd_MemFree(g_mmi_brw_cntx.confirm_soft2);
        g_mmi_brw_cntx.confirm_soft2 = NULL;
    }
    if (g_mmi_brw_cntx.call_back_confirm)
    {
        g_mmi_brw_cntx.call_back_confirm = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_msg_RSK_hdlr
 * DESCRIPTION
 *  RSK handler for confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_msg_RSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    g_mmi_brw_cntx.call_back_confirm(g_mmi_brw_cntx.arg_p, E_FALSE);
    if (g_mmi_brw_cntx.pm_msg)
    {
        jdd_MemFree(g_mmi_brw_cntx.pm_msg);
        g_mmi_brw_cntx.pm_msg = NULL;
    }
    if (g_mmi_brw_cntx.confirm_soft1)
    {
        jdd_MemFree(g_mmi_brw_cntx.confirm_soft1);
        g_mmi_brw_cntx.confirm_soft1 = NULL;
    }
    if (g_mmi_brw_cntx.confirm_soft2)
    {
        jdd_MemFree(g_mmi_brw_cntx.confirm_soft2);
        g_mmi_brw_cntx.confirm_soft2 = NULL;
    }
    if (g_mmi_brw_cntx.call_back_confirm)
    {
        g_mmi_brw_cntx.call_back_confirm = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_alert_callback
 * DESCRIPTION
 *  Set alert callback
 * PARAMETERS
 *  apparg_p        [?]         [?]
 *  pm_msg_p        [?]         [?]         [?]
 *  cb_alert        [IN]        
 *  cb_arg_p        [?]         [?]         [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_set_alert_callback(void *apparg_p, JC_CHAR *pm_msg_p, BROWSER_ALERT_CB cb_alert, void *cb_arg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 i_str_len = 0;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_FALSE == mmi_brw_is_browser_window_active())
    {
        return ret;
    }

    if ((NULL != pm_msg_p) && ((i_str_len = jc_tcslen(pm_msg_p)) > 0))
    {
        g_mmi_brw_cntx.pm_msg = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) pm_msg_p) + 1, sizeof(JC_CHAR));
        if (NULL != g_mmi_brw_cntx.pm_msg)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.pm_msg, (S8*) pm_msg_p);
        }
        else
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
    }
    else
    {
        return JC_ERR_INVALID_PARAMETER;
    }

    g_mmi_brw_cntx.call_back_alert = cb_alert;
    g_mmi_brw_cntx.arg_p = cb_arg_p;

    mmi_brw_entry_alert_callback_screen();
    g_mmi_brw_page_cntx.brw_page_fetch_status = 0;
    ret = JC_ERR_WAIT_USER_ACTION;
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_alert_callback_screen
 * DESCRIPTION
 *  Entry function for alert callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_alert_callback_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_WAP_ALERT_SCREEN, NULL, mmi_brw_entry_alert_callback_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_WAP_ALERT_SCREEN);

    ShowCategory165Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (UI_string_type) g_mmi_brw_cntx.pm_msg,
        IMG_GLOBAL_QUESTION,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_alert_msg_LSK_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_alert_msg_LSK_hdlr
 * DESCRIPTION
 *  LSK handler for alert callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_alert_msg_LSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    g_mmi_brw_cntx.call_back_alert(g_mmi_brw_cntx.arg_p);
    if (g_mmi_brw_cntx.pm_msg)
    {
        jdd_MemFree(g_mmi_brw_cntx.pm_msg);
        g_mmi_brw_cntx.pm_msg = NULL;
    }
    if (g_mmi_brw_cntx.call_back_alert)
    {
        g_mmi_brw_cntx.call_back_alert = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_prompt_callback
 * DESCRIPTION
 *  Prompt callback handler
 * PARAMETERS
 *  apparg_p                [?]         [?]
 *  mmsg_p                  [?]         [?]
 *  pm_default_value        [?]         [?]
 *  cb_prompt               [IN]        
 *  cb_arg_p                [?]         [?]
 *  pm_msg_p                [IN]        
 *  estatus_p               [?]         [?]
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
/* PROMPT CALLBACK */
JC_RETCODE mmi_brw_set_prompt_callback(
            void *apparg_p,
            JC_CHAR *mmsg_p,
            JC_CHAR *pm_default_value,
            BROWSER_PROMPT_CB cb_prompt,
            void *cb_arg_p,
            JC_CHAR **pm_msg_p,
            JC_BOOLEAN *estatus_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 i_str_len = 0;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (E_FALSE == mmi_brw_is_browser_window_active())
    {
        return ret;
    }

    if ((NULL != mmsg_p) && ((i_str_len = jc_tcslen(mmsg_p)) > 0) && (NULL != pm_msg_p))
    {
        g_mmi_brw_cntx.pm_msg = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) mmsg_p) + 1, sizeof(JC_CHAR));
        if (NULL != g_mmi_brw_cntx.pm_msg)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.pm_msg, (S8*) mmsg_p);
        }
        else
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
        if (pm_default_value)
        {
            g_mmi_brw_cntx.pm_default_value =
                (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) pm_default_value) + 1, sizeof(JC_CHAR));
            if (NULL != g_mmi_brw_cntx.pm_default_value)
            {
                mmi_ucs2cpy((S8*) g_mmi_brw_cntx.pm_default_value, (S8*) pm_default_value);
            }
        }
        else
        {
            g_mmi_brw_cntx.pm_default_value = NULL;
        }
    }
    else
    {
        *estatus_p = E_FALSE;
        return JC_ERR_INVALID_PARAMETER;
    }

    g_mmi_brw_cntx.call_back_prompt = cb_prompt;
    g_mmi_brw_cntx.arg_p = cb_arg_p;

    mmi_brw_entry_prompt_callback_screen();
    ret = JC_ERR_WAIT_USER_ACTION;
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_prompt_callback_screen
 * DESCRIPTION
 *  Entry function for prompt callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_prompt_callback_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_len = 0;
    U8 *gui_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_WAP_PROMPT_INPUT_SCREEN, NULL, mmi_brw_entry_prompt_callback_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_WAP_PROMPT_INPUT_SCREEN);
    msg_len = mmi_ucs2strlen((S8*) g_mmi_brw_cntx.pm_msg);
    /* added by pawan 31-07-06 for dialoge input box */
    ShowCategory74Screen(
        STR_ID_BRW_PROMPT_MESSAGE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (PU8) g_mmi_brw_cntx.pm_msg,
        msg_len,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_pre_entry_prompt_callback_editor_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_prompt_callback_editor_screen
 * DESCRIPTION
 *  Pre entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_prompt_callback_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.prompt_buffer = jdd_MemAlloc((MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD + 1) * ENCODING_LENGTH, 1);
    if (NULL != g_mmi_brw_cntx.prompt_buffer)
    {
        memset(
            g_mmi_brw_cntx.prompt_buffer,
            0,
            (MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD + 1) * ENCODING_LENGTH);

        if (g_mmi_brw_cntx.pm_default_value != NULL)
        {
            mmi_ucs2ncpy(
                (S8*) g_mmi_brw_cntx.prompt_buffer,
                (S8*) g_mmi_brw_cntx.pm_default_value,
                MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD);
        }

        if (g_mmi_brw_cntx.pm_default_value)
        {
            jdd_MemFree(g_mmi_brw_cntx.pm_default_value);
            g_mmi_brw_cntx.pm_default_value = NULL;
        }
    }
    if (g_mmi_brw_cntx.pm_msg)
    {
        jdd_MemFree(g_mmi_brw_cntx.pm_msg);
        g_mmi_brw_cntx.pm_msg = NULL;
    }
    mmi_brw_entry_prompt_callback_editor_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_prompt_callback_editor_screen
 * DESCRIPTION
 *  RSK handler for prompt callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_prompt_callback_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_WAP_PROMPT_EDITOR_SCREEN, NULL, mmi_brw_entry_prompt_callback_editor_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_WAP_PROMPT_EDITOR_SCREEN);
    /*
     * g_mmi_brw_cntx.prompt_buffer = jdd_MemAlloc((MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD + 1) * ENCODING_LENGTH, 1);
     * if (NULL != g_mmi_brw_cntx.prompt_buffer)
     * {
     * memset(g_mmi_brw_cntx.prompt_buffer, 0, (MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD + 1) * ENCODING_LENGTH);
     * 
     * if (g_mmi_brw_cntx.pm_default_value != NULL)
     * {
     * mmi_ucs2cpy((S8*) g_mmi_brw_cntx.prompt_buffer, (S8*) g_mmi_brw_cntx.pm_default_value);
     * }
     * 
     * if(g_mmi_brw_cntx.pm_default_value)
     * {
     * jdd_MemFree(g_mmi_brw_cntx.pm_default_value);
     * g_mmi_brw_cntx.pm_default_value = NULL;
     * }
     * 
     * }
     */
    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (PU8) g_mmi_brw_cntx.prompt_buffer,
        MMI_JDD_UI_MAX_INPUT_LEN_FOR_ENABLED_INPUT_METHOD,
        gui_buffer_p);
    SetCategory5RightSoftkeyFunction(mmi_brw_prompt_msg_RSK_hdlr, KEY_EVENT_UP);        /* pawan 28/10/2006 */
    SetLeftSoftkeyFunction(mmi_brw_prompt_msg_LSK_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prompt_msg_RSK_hdlr
 * DESCRIPTION
 *  LSK handler for prompt callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prompt_msg_RSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_BRW_WAP_PROMPT_INPUT_SCREEN);
    GoBackHistory();
    g_mmi_brw_cntx.call_back_prompt(g_mmi_brw_cntx.arg_p, g_mmi_brw_cntx.pm_default_value, E_FALSE);

    if (g_mmi_brw_cntx.prompt_buffer != NULL)
    {
        jdd_MemFree(g_mmi_brw_cntx.prompt_buffer);
        g_mmi_brw_cntx.prompt_buffer = NULL;
    }

    if (g_mmi_brw_cntx.pm_default_value)
    {
        jdd_MemFree(g_mmi_brw_cntx.pm_default_value);
        g_mmi_brw_cntx.pm_default_value = NULL;
    }
    if (g_mmi_brw_cntx.call_back_prompt)
    {
        g_mmi_brw_cntx.call_back_prompt = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prompt_msg_LSK_hdlr
 * DESCRIPTION
 *  LSK handler for prompt callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prompt_msg_LSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_BRW_WAP_PROMPT_INPUT_SCREEN);
    GoBackHistory();
    g_mmi_brw_cntx.call_back_prompt(g_mmi_brw_cntx.arg_p, g_mmi_brw_cntx.prompt_buffer, E_TRUE);

    if (g_mmi_brw_cntx.prompt_buffer != NULL)
    {
        jdd_MemFree(g_mmi_brw_cntx.prompt_buffer);
        g_mmi_brw_cntx.prompt_buffer = NULL;
    }
    if (g_mmi_brw_cntx.call_back_prompt)
    {
        g_mmi_brw_cntx.call_back_prompt = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_page_info_callback
 * DESCRIPTION
 *  Set page info callback.
 * PARAMETERS
 *  apparg_p        [?]     
 *  page_info_p     [?]     [?]
 *  pAppArg         [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_page_info_callback(void *apparg_p, JC_PAGE_INFO *page_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_progress_status_callback
 * DESCRIPTION
 *  Progress status callback.
 * PARAMETERS
 *  apparg_p            [?]     [?]
 *  progress_ind_p      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_progress_status_callback(void *apparg_p, COMM_PROGRESS_IND *progress_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_focus_callback
 * DESCRIPTION
 *  Callback for handling current focused control information.
 * PARAMETERS
 *  apparg_p            [?]         [?]
 *  efocus_type         [IN]        
 *  b_is_selectable     [IN]        
 *  ui_ctrl_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_focus_callback(void *apparg_p, EControlType efocus_type, JC_BOOLEAN b_is_selectable, JC_UINT32 ui_ctrl_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_data_conn_status_app_callback
 * DESCRIPTION
 *  This function is used to get the status of data connection.
 * PARAMETERS
 *  data_account_id     [IN]        [?]
 *  estatus             [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_data_conn_status_app_callback(JC_UINT32 data_account_id, JC_UINT32 estatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_account_id < custom_get_csd_profile_num())
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Dataconn calbk called with status", estatus);
        if (g_mmi_brw_cntx.is_layout_initialized == E_TRUE)
        {
            switch (estatus)
            {
                case JDD_DATACONN_ACTIVATING:

                    g_mmi_brw_cntx.data_connection_state = BRW_DATACONN_ACTIVATING;
                    break;

                case JDD_DATACONN_ACTIVATED:

                    g_mmi_brw_cntx.data_connection_state = BRW_DATACONN_ACTIVATED;
                    break;

                case JDD_DATACONN_DEACTIVATING:

                    g_mmi_brw_cntx.data_connection_state = BRW_DATACONN_DEACTIVATING;
                    break;

                case JDD_DATACONN_DEACTIVATED:

                    g_mmi_brw_cntx.csd_call_aborted_status = GetDropRequestFlag();
                    g_mmi_brw_cntx.data_connection_state = BRW_DATACONN_DEACTIVATED;
                    /* If data connection is deactivated for
                       E_BRW_DATACONN_AUTO_DISC_TIMEOUT_EVENT or by application then deinit will not be performed */
                    if (!(g_mmi_brw_cntx.brw_csd_call_disconnect || g_mmi_brw_cntx.is_data_connection_deactivate))
                    {
                        mmi_brw_wps_deinit_event();
                    }
                    g_mmi_brw_cntx.brw_csd_call_disconnect = FALSE;
                    g_mmi_brw_cntx.is_data_connection_deactivate = E_FALSE;
                    break;

                case JDD_DATACONN_AUTO_DISC_TIMEOUT:

                    mmi_brw_dataconn_auto_disc_timeout_event();
                    break;

                default:
                    break;
            }
        }
        else if (estatus == JDD_DATACONN_AUTO_DISC_TIMEOUT)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "LAYOUT is not initialized");
            jdd_DataConnHandleAutoDiscTimeout(data_account_id, estatus);
            mmi_brw_show_long_idle_disconnected_notification();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jdd_browser_ui_events_hdlr
 * DESCRIPTION
 *  EVENT HANDLER FOR BROWSER UI.
 * PARAMETERS
 *  event_data_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jdd_browser_ui_events_hdlr(JC_EVENT_DATA *event_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_MMI_EVENT *mmi_event_data_p = NULL;
    JC_MMI_EVENT mmi_event_data;
    EJCScrollDirection escroll_direction;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((E_TASK_BROWSER_CORE == event_data_p->srcTaskInfo.iTaskID)
        || (E_TASK_BROWSER_UI == event_data_p->srcTaskInfo.iTaskID))
    {
        switch (event_data_p->iEventType)
        {
                /* Handle secondary specific events */
            case E_BRW_STARTUP_EVENT:
            {
            #ifdef JBROWSER_USE_ASM
                /* Register the browser application with ASM. */
                applib_mem_ap_register(
                    APPLIB_MEM_AP_ID_JATAAYU_WAP,
                    STR_ID_BRW_JBROWSER,
                    NULL,
                    mmi_brw_stop_wap_application);
            #endif /* JBROWSER_USE_ASM */ 
                /* PIXTEL_JATAAYU : Initialize the Browser State machine */
                ret = jdi_BrowserInitContext(&g_mmi_brw_pbrowser_ctxt, g_mmi_brw_pbrowser_ctxt);
                if (JC_OK != ret)
                {
                    ASSERT(0);
                }

                ret = jdi_BrowserInitCommPush(g_mmi_brw_pbrowser_ctxt);
                if (JC_OK != ret)
                {
                    ASSERT(0);
                }

            #ifdef BROWSER_PUSH_ENABLE
                if (g_mmi_brw_cntx.is_service_msg_setting)
                {
                    mmi_brw_enable_push_Message(E_TRUE);
                }
                else
                {
                    mmi_brw_enable_push_Message(E_FALSE);
                }
                mmi_brw_initialize_push_message_list();
                jdi_BrowserRegisterPushHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_push_callback);
                jdi_BrowserRegisterPushPPGValidateHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_push_PPG_validate_callback);
                jdi_BrowserRegisterPushInboxHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_push_inbox_max_size_callback);
                jdi_BrowserRegisterPushInboxFullHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_push_inbox_full_callback);
                jdi_BrowserRegisterPushUpdateHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_push_with_delete_action);
            #endif /* BROWSER_PUSH_ENABLE */ 
                g_mmi_brw_cntx.is_browser_ready = TRUE;
                g_mmi_brw_cntx.is_browser_init_in_progress = FALSE;
                /* Added By vivek to resolve the push status icon problem on 
                   rebooting the phone */
                mmi_brw_unread_push_message_indication();
            #ifdef __MMI_UNIFIED_MESSAGE__
                mmi_um_brw_push_ready_ind();
            #endif 
                jdd_DataConnSetStatusAppCB(mmi_brw_data_conn_status_app_callback);
                g_mmi_brw_cntx.data_connection_state = BRW_DATACONN_DEACTIVATED;
            #if defined WAP_SEC_SUPPORT
                mmi_brw_init_security_context();
            #endif 

            }
                break;

            case E_BRW_START_FETCH_EVENT:
            {
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
                if (mmi_brw_is_browser_window_active())
                {
                    jdi_BrowserOpen(g_mmi_brw_pbrowser_ctxt);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error:jdi_BrowserOpen: Browser is not active screen");
                }
                jdi_BrowserSetMagnification(g_mmi_brw_pbrowser_ctxt, 100);

                if (g_mmi_brw_cntx.is_layout_initialized == E_TRUE && !g_mmi_brw_cntx.is_connection_active)
                {
                    mmi_brw_set_transport_and_data_profile();
                    g_mmi_brw_cntx.is_connection_active = MMI_TRUE;
                }

                ret = mmi_brw_set_proxy_auth_info();
                if (ret == JC_ERR_MEMORY_ALLOCATION)
                {
                    jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
                    return;
                }

                ret = jdi_BrowserFetchRequest(g_mmi_brw_pbrowser_ctxt, &g_mmi_brw_cntx.fetch_url_info);
                mmi_brw_free_proxy_auth_info();
                if (JC_OK != ret)
                {
                    jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
                    return;
                }
                g_mmi_brw_cntx.page_fetch_event = BRW_START_FETCH_EVENT;        /* added by tk */
            }
                break;

            case E_BRW_KEY_LEFT_EVENT:
                escroll_direction = E_JC_SCROLL_LEFT;
                jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
                break;

            case E_BRW_KEY_RIGHT_EVENT:
                escroll_direction = E_JC_SCROLL_RIGHT;
                jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
                break;

            case E_BRW_KEY_UP_EVENT:
                escroll_direction = E_JC_SCROLL_UP;
                jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
                break;

            case E_BRW_KEY_DOWN_EVENT:
                escroll_direction = E_JC_SCROLL_DOWN;
                jdi_BrowserHandleScroll(g_mmi_brw_pbrowser_ctxt, escroll_direction);
                break;

            case E_BRW_REFRESH_EVENT:
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
                jdi_BrowserRefreshDisplay(g_mmi_brw_pbrowser_ctxt);
                break;

            case E_BRW_STOP_FETCH_EVENT:
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
                jdi_BrowserFetchStop(g_mmi_brw_pbrowser_ctxt);
                /* jdi_BrowserRefreshDisplay(g_mmi_brw_pbrowser_ctxt) ;//commented by tk */
                break;

            case E_BRW_ACTION_EVENT:
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
                jc_memset(&mmi_event_data, 0, sizeof(JC_MMI_EVENT));
                mmi_event_data_p = (JC_MMI_EVENT*) event_data_p->pEventInfo;
                mmi_event_data = *mmi_event_data_p;
                ret = jdi_BrowserHandlePrimaryMMI(g_mmi_brw_pbrowser_ctxt, &mmi_event_data);
                if (JC_OK != ret)
                {
                    jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
                }
                jdd_QueueFree(event_data_p);
                g_mmi_brw_cntx.page_fetch_event = BRW_ACTION_EVENT;
                break;

            case E_BRW_SAT_GOTO_URL_EVENT:
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
                if (mmi_brw_is_browser_window_active())
                {
                    jdi_BrowserOpen(g_mmi_brw_pbrowser_ctxt);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error:jdi_BrowserOpen: Browser is not active screen");
                }
                jdi_BrowserSetMagnification(g_mmi_brw_pbrowser_ctxt, 100);
                ret = jdi_BrowserFetchRequest(g_mmi_brw_pbrowser_ctxt, &g_mmi_brw_cntx.fetch_url_info);
                if (JC_OK != ret)
                {
                    jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
                    return;
                }
                g_mmi_brw_cntx.page_fetch_event = BRW_START_FETCH_EVENT;        /* added by tk */

                break;

            #ifdef __DRM_SUPPORT__
            case E_BRW_PARSE_DRM_EVENT:

                mmi_jbrowser_parse_drm_content();
                break;

            #endif /* __DRM_SUPPORT__ */ 
            case E_BRW_DEINIT_EVENT:

                if (g_mmi_brw_cntx.end_key_pressed && (!g_mmi_brw_page_cntx.brw_page_fetch_status))
                {
                    DisplayIdleScreen();
                }
                else if (!g_mmi_brw_cntx.end_key_pressed)
                {
                    mmi_brw_deinit_all();
                    mmi_brw_delete_brw_screen();
                }
                break;

            case E_BRW_DATACONN_AUTO_DISC_TIMEOUT_EVENT:

                g_mmi_brw_cntx.brw_csd_call_disconnect = TRUE;
                jdi_BrowserDisconnect(g_mmi_brw_pbrowser_ctxt);
                mmi_brw_show_long_idle_disconnected_notification();
                break;

            case E_BRW_ENDKEY_EVENT:
                mmi_brw_goto_idle_screen();
                break;

            default:
                break;
        }
    }
}

#ifdef JBROWSER_USE_ASM


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stop_wap_application
 * DESCRIPTION
 *  This function will be invoked when ASM requests WAP application memmory to free memory.
 *  This function will only be invoked in MMI context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stop_wap_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* De-initialize the application */
    mmi_brw_wap_deinit();

    /* Free the application memmory */
    /* applib_mem_ap_free(g_mmi_brw_cntx.wap_heap_space); */

    /* Notify MMI about application being stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_JATAAYU_WAP, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_enter_req_handler
 * DESCRIPTION
 *  Responsible for launch of application screen. If it fals to allocate memory. it can
 *  invoke mmi_frm_appmem_propmt_to_release_mem to enter out of memmory screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_wap_enter_req_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.wap_heap_space)
    {
        ret = jdd_MemInitBrowserASMPool(g_mmi_brw_cntx.wap_heap_space, g_mmi_brw_cntx.asm_mem_size);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_JATAAYU_WAP,
            NULL,
            g_mmi_brw_cntx.asm_mem_size,
            mmi_brw_wap_request_asm_success_callback);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_request_asm_success_callback
 * DESCRIPTION
 *  This function will get called when user stops other applications and releases
 *  enough memory. This function will again try to allocate ASM memory to browser.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wap_request_asm_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.wap_heap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JATAAYU_WAP, g_mmi_brw_cntx.asm_mem_size);

    ASSERT(g_mmi_brw_cntx.wap_heap_space);

    ret = mmi_brw_jbrowser_init_app();
    if (ret != JC_OK)
    {
        ASSERT(0);
    }

    switch (g_mmi_brw_cntx.init_app_flag)
    {
        case BRW_INIT_APP_GOTO_INTERNET_SERVICES:
            g_mmi_brw_cntx.is_saturl = E_FALSE;
            mmi_brw_entry_internet_services();
            break;

        case BRW_INIT_APP_GOTO_HOMEPAGE:
            g_mmi_brw_cntx.page_fetch_req_src = 1;
            mmi_brw_entry_homepage();
            break;

        case BRW_INIT_APP_GOTO_URL:
            mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url);
            mmi_brw_pre_entry_goto_url();
            break;

        case BRW_INIT_APP_GOTO_PUSH_MESSAGE:
            mmi_brw_set_current_url((S8*) g_mmi_brw_push_cntx.current_service_message->pmHref);
            mmi_brw_pre_entry_goto_url();

            /* Start - PMTSW00006677 & PMTSW00007001 */

    #ifndef __MMI_UNIFIED_MESSAGE__

            /* 
             * When there is only one unread service message, We display the message body 
             * directly, instead of displaying the service Inbox, that is why  we are  adding 
             * service Inbox screen so that while pressing cacel or while exiting the browser 
             * user will come on Service Inbox screen. 
             */
            if ((FALSE == IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX)) &&
                (FALSE == IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX_OPTIONS)))
            {
                HistoryReplace(SCR_ID_BRW_READ_SERVICE_MESSAGE, SCR_ID_BRW_SERVICE_INBOX, mmi_brw_entry_service_inbox);
            }
            DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);

    #else /* __MMI_UNIFIED_MESSAGE__ */ 

            DeleteUptoScrID(SCR_ID_UM_INBOX);

    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

            /* End - PMTSW00006677 & PMTSW00007001 */

            break;

        case BRW_INIT_APP_GOTO_SAT:
            /* Yet to decide */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}
#endif /* JBROWSER_USE_ASM */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_init_app
 * DESCRIPTION
 *  Initialize the browser application if not already initialized
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_brw_jbrowser_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    nvram_wap_profile_content_struct *activated_wap_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the layout is not Initialized then Initialize it */
    if (g_mmi_brw_cntx.is_layout_initialized == E_FALSE)
    {
        activated_wap_profile = mmi_ph_get_activated_wap_profile();
        if (mmi_ph_check_data_account_type(activated_wap_profile->data_account) == PH_DATA_ACCOUNT_CSD)
        {
            if (IsWapCallPresent())
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_BRW_CANNOT_CONNECT),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_BRW_POPUP_TIME,
                    ERROR_TONE);
                return -1;
            }
        }

    #ifdef JBROWSER_USE_ASM
        /* Allocate browser ASM pool. */
        if (!g_mmi_brw_cntx.wap_heap_space)
        {
            g_mmi_brw_cntx.asm_mem_size = applib_mem_ap_get_pool_size();
            if (JBROWSER_ASM_MEM_SIZE < g_mmi_brw_cntx.asm_mem_size)
            {
                g_mmi_brw_cntx.asm_mem_size = JBROWSER_ASM_MEM_SIZE;
            }

            g_mmi_brw_cntx.wap_heap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JATAAYU_WAP, g_mmi_brw_cntx.asm_mem_size);
        }
        /* Initialized browser ASM pool. */
        ret = mmi_brw_wap_enter_req_handler();
        if (ret != JC_OK)
        {
            return ret;
        }
    #endif /* JBROWSER_USE_ASM */ 
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        jdi_BrowserInitLayoutHistory(g_mmi_brw_pbrowser_ctxt);
        jdi_BrowserInitCacheCookie(g_mmi_brw_pbrowser_ctxt);

        jdi_BrowserSetMagnification(g_mmi_brw_pbrowser_ctxt, 100);
    #ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
        jdi_BrowserInitOfflinePages(g_mmi_brw_pbrowser_ctxt, mmi_brw_init_offline_context());
        jdi_BrowserRegisterOfflinePagesStatusCallback(g_mmi_brw_pbrowser_ctxt, mmi_brw_offline_status_callback);
        mmi_brw_offline_pages_init_app();
    #endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 
        jdi_BrowserRegisterShowAuthHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_show_authentication_callback);
        /* Presently not in use */
        //jdi_BrowserRegisterShowProgressHandler (g_mmi_brw_pbrowser_ctxt, mmi_brw_show_progress_bar_callback) ;
        //jdi_BrowserRegisterPageStatusHandler (g_mmi_brw_pbrowser_ctxt, mmi_brw_rendering_status_callback) ; 
        //ADDED BY TK to register a callback for page fetching
        jdi_BrowserRegisterBrowserStatusIndicator(g_mmi_brw_pbrowser_ctxt, mmi_brw_page_status_callback);
        jdi_BrowserRegisterPageUpdateIndicator(g_mmi_brw_pbrowser_ctxt, mmi_brw_pageupdate_callback);   /* pawan */
        jdi_BrowserRegisterEmptyNavListInd(g_mmi_brw_pbrowser_ctxt, mmi_brw_empty_navlist_callback);
        /* Presently not in use */
        /* jdi_BrowserRegisterPageRenderingStatusHandler (g_mmi_brw_pbrowser_ctxt, mmi_brw_page_rendering_status_callback)  ; */
        jdi_BrowserRegisterDoTagHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_do_tag_callback);
        jdi_BrowserEnableCache(g_mmi_brw_pbrowser_ctxt, E_TRUE);
        jdi_BrowserEnableCookie(g_mmi_brw_pbrowser_ctxt, E_TRUE);
        jdi_BrowserEnableFourWayNavigation(g_mmi_brw_pbrowser_ctxt, E_TRUE);
        jdi_BrowserEnableOfflineBrowsing(g_mmi_brw_pbrowser_ctxt, E_FALSE);
        jdi_BrowserEnableCircularScrolling(g_mmi_brw_pbrowser_ctxt, E_TRUE);
        /* Below modified by Shantanu - 20060606 */
        jdi_BrowserSetImageAsSelectable(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.image_selection);
    #if defined WAP_SEC_SUPPORT
        jdi_BrowserRegisterSecureToNonsecure(g_mmi_brw_pbrowser_ctxt, mmi_brw_security_switch_callback_hdlr);
        jdi_BrowserRegisterSecurityHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_security_indication_callback_hdlr);
        jdi_BrowserRegisterSecurityFailureHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_security_failure_callback_hdlr);
        jdi_BrowserRegisterNonSecureIndication(
            g_mmi_brw_pbrowser_ctxt,
            mmi_brw_nonsecure_mode_indication_callback_hdlr);
        jdi_BrowserRegisterUserCertificateReqHandler(
            g_mmi_brw_pbrowser_ctxt,
            mmi_brw_user_certificate_indication_callback_hdlr);
    #endif /* defined WAP_SEC_SUPPORT */ 
    #ifdef CURRENTLY_NOT_SUPPORTED
        mmi_certman_update_action_callbacks[0] = mmi_brw_certman_update_action_ind;
    #endif 
        jdi_BrowserSetAlertCB(g_mmi_brw_pbrowser_ctxt, mmi_brw_set_alert_callback, NULL);
        jdi_BrowserSetConfirmCB(g_mmi_brw_pbrowser_ctxt, mmi_brw_set_confirm_callback, NULL);
        jdi_BrowserSetPromptCB(g_mmi_brw_pbrowser_ctxt, mmi_brw_set_prompt_callback, NULL);
        jdi_BrowserRegisterPageInfoHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_set_page_info_callback);
        jdi_BrowserRegisterProgressStatusHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_progress_status_callback);
        jdi_BrowserRegisterFocusHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_focus_callback);
        jdi_BrowserRegisterMimeHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_mime_callback_hdlr);
        jdi_BrowserRegisterMimeContentHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_mime_content_callback_hdlr);
        jdi_BrowserSetBgImageDisplay(g_mmi_brw_pbrowser_ctxt, E_FALSE);

    #ifdef __DRM_SUPPORT__
        jdi_BrowserRegisterDRMCB(
            g_mmi_brw_pbrowser_ctxt,
            mmi_jbrowser_drm_indication_handler,
            mmi_jbrowser_drm_rights_update_handler,
            NULL,
            g_mmi_brw_pvdrmarg_p);
    #endif /* __DRM_SUPPORT__ */ 
        jdi_BrowserRegisterMultimediaHandler(g_mmi_brw_pbrowser_ctxt, mmi_brw_multimedia_callback_hdlr);

        /* Added by Sandeep to set if images should be shown on the rendered page or not */
        jdi_BrowserGraphicsEnable(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.show_images);

    #ifdef __JBROWSER_DLS_SUPPORT__
        g_mmi_brw_dls_cntx.download_state = BRW_DLS_IDLE;
    #endif 

        /* We have to set this flag to prevent multiple initialization */
        g_mmi_brw_cntx.is_layout_initialized = E_TRUE;
    #if defined WAP_SEC_SUPPORT
        mmi_brw_init_wap_security();
    #endif 
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_communication_init
 * DESCRIPTION
 *  Create a new browser communication handle and initialize it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_communication_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_TASK_INFO app_task_info = {0, };
    JC_TASK_INFO transport_task_info = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_brw_communication_init");

    app_task_info.iTaskID = (JC_INT32) E_TASK_BROWSER_CORE;
    app_task_info.iAppID = (JC_INT32) E_TASK_BROWSER_CORE;
    transport_task_info.iTaskID = (JC_INT32) E_TASK_TRANSPORT;
    transport_task_info.iAppID = (JC_INT32) E_TASK_TRANSPORT;

    ret = jdi_CommunicationInitialize(
            &app_task_info,
            &transport_task_info,
            &g_mmi_brw_cntx,
            &g_mmi_brw_cntx.hcomm_handle);
    if (JC_OK != ret)
    {
        ASSERT(0);
        /* goto error; */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_deinit_app
 * DESCRIPTION
 *  Deinitialize the browser application(on exit from browser)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_deinit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_JBrowserDeInitApp");
    /* Tk start 18/01/2007 */
#ifdef JBROWSER_USE_ASM
    /* DeInitialize the communicator */
    /* jdi_CommunicationStopAllReq(g_mmi_brw_cntx.hcomm_handle); */
    /* Added by TK to deinitialize the communication layer of browser */
    jdi_BrowserCommunicationDeinitialize(g_mmi_brw_pbrowser_ctxt);
#endif /* JBROWSER_USE_ASM */ 
    /* Tk end 18/01/2007 */
    jdi_BrowserDeInitCacheCookie(g_mmi_brw_pbrowser_ctxt);
    jdi_BrowserDeInitLayoutHistory(g_mmi_brw_pbrowser_ctxt);
#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
    jdi_BrowserDeInitOfflinePages(g_mmi_brw_pbrowser_ctxt);
#endif 
    jdi_BrowserDeInit(g_mmi_brw_pbrowser_ctxt);
    /* Added by Sandeep for checking data connection active or not */
    /* If the data profile is chnaged by the user then we have to set this flag as false so that 
       when a new page is fetched then we have to set the profile again */
    g_mmi_brw_cntx.is_connection_active = MMI_FALSE;

    /* Added by Sandeep to check if any page is rendered or not This is used when notification
       comes on a link fetched from the page which is opened for the first time. THe rendered page 
       should be restored. */
    g_mmi_brw_cntx.is_rendered_flag = E_FALSE;

    /* Added by Sandeep : to reset the layoutInitialized flag */
    g_mmi_brw_cntx.is_layout_initialized = E_FALSE;
#ifdef JATAAYU_IMAGE_CACHING_ENABLE
    /* DeInitialize the memory pool container used for buffered images. */
    mmi_jdd_ui_deinit_image_pool();
#endif /* JATAAYU_IMAGE_CACHING_ENABLE */ /* ifdef JATAAYU_IMAGE_CACHING_ENABLE */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Exit mmi_JBrowserDeInitApp");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_jbrowser_ctxt
 * DESCRIPTION
 *  Deinitialize the browser Context (at shutdown)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_jbrowser_ctxt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt != NULL)
    {
        /* PIXTEL_JATAAYU
           jdi_BrowserDeInitialize(g_mmi_brw_pbrowser_ctxt); */
        jdi_BrowserDeInitContext(g_mmi_brw_pbrowser_ctxt);
        g_mmi_brw_pbrowser_ctxt = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_refresh_page
 * DESCRIPTION
 *  Refresh the current rendered page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_refresh_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserOpen(g_mmi_brw_pbrowser_ctxt);
    jdi_BrowserSetMagnification(g_mmi_brw_pbrowser_ctxt, 100);
    /* g_mmi_brw_page_cntx.brw_page_refresh_status = 1; */
    /* Added By Shantanu -20060810 */
    /* We will set this flag when the user selects "Refresh" from rendered page
       option menu.This flag will restrict the user to enter the full screen editor 
       while the page is being refreshed */
    mmi_jdd_ui_set_jdd_flag(JDD_MANUAL_REFRESH_FLAG, E_TRUE);

#ifdef DOWNLOAD_CLIENT_ENABLE
    if (InitDownloadClient(g_mmi_brw_pbrowser_ctxt) != JC_OK)
    {

    }
#endif /* DOWNLOAD_CLIENT_ENABLE */ 
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    jdi_BrowserRefreshPage(g_mmi_brw_pbrowser_ctxt);
}

/* Function Below added by Shantanu for Accesskey Support - 20060412 */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_fill_accesskey_info_and_send_event_to_queue
 * DESCRIPTION
 *  Function to fill accesskey info and sent it to the queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_fill_accesskey_info_and_send_event_to_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_JDD_UI_WINDOW_INFO_STRUCT *jdd_window_info_struct_p = NULL;
    JC_UINT32 ui_window_id = 0;
    JC_EVENT_DATA event_data = {0, };
    JC_MMI_EVENT control_event_data = {0, };
    JC_RETCODE ret = JC_OK;
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.iEventType = E_BRW_ACTION_EVENT;

    ui_window_id = mmi_jdd_ui_get_appWindowID(E_TASK_BROWSER_CORE);
    jdd_window_info_struct_p = (MMI_JDD_UI_WINDOW_INFO_STRUCT*) ui_window_id;
    if (jdd_window_info_struct_p != NULL)
    {
        /* for getting the last key press event */
        GetkeyInfo(&keycode, &keytype);

        switch (keycode)
        {
            case KEY_0:
            case KEY_1:
            case KEY_2:
            case KEY_3:
            case KEY_4:
            case KEY_5:
            case KEY_6:
            case KEY_7:
            case KEY_8:
            case KEY_9:
                control_event_data.eventData.accessKeyEvent.uiAccessKeyIndex = keycode;
                break;

            case KEY_STAR:
                control_event_data.eventData.accessKeyEvent.uiAccessKeyIndex = STAR_ACCESS_KEY;
                break;

            case KEY_POUND:
                control_event_data.eventData.accessKeyEvent.uiAccessKeyIndex = HASH_ACCESS_KEY;
                break;

        #ifdef BROWSER_SENDKEY_AS_ACCESSKEY
            case KEY_SEND:
                control_event_data.eventData.accessKeyEvent.uiAccessKeyIndex = SEND_ACCESS_KEY;
                break;
        #endif /* BROWSER_SENDKEY_AS_ACCESSKEY */ 

            default:
                /* All the accesskeys are handled above. 
                   If it gives an assert then we should handle the new key */
                ASSERT(0);
        }
        control_event_data.eEventType = JC_MMI_ACCESSKEY_EVENT;

        event_data.uiEventInfoSize = sizeof(JC_MMI_EVENT);

        ret = jdd_QueueAlloc(&event_data);
        if (JC_OK != ret)
        {
            return;
        }

        jc_memcpy(event_data.pEventInfo, &control_event_data, sizeof(JC_MMI_EVENT));

        ret = jdd_QueueSend(&event_data);

        if (JC_OK != ret)
        {
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_fill_control_info_and_send_event_to_queue
 * DESCRIPTION
 *  Function to fill control info and sent it to the queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_fill_control_info_and_send_event_to_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_JDD_UI_WINDOW_INFO_STRUCT *jdd_window_info_struct_p = NULL;
    JC_UINT32 ui_window_id = 0;
    JC_EVENT_DATA event_data = {0, };
    JC_MMI_EVENT control_event_data = {0, };
    JC_RETCODE ret = JC_OK;
    JDD_CONTROL_INFO *control_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.iEventType = E_BRW_ACTION_EVENT;

    ui_window_id = mmi_jdd_ui_get_appWindowID(E_TASK_BROWSER_CORE);
    jdd_window_info_struct_p = (MMI_JDD_UI_WINDOW_INFO_STRUCT*) ui_window_id;
    if (jdd_window_info_struct_p != NULL)
    {
        control_event_data.uiControlID = (JC_UINT32) jdd_window_info_struct_p->currFocussedControlID;
        control_event_data.uiWindowID = jdd_window_info_struct_p->uiWindowID;
        control_info_p = (JDD_CONTROL_INFO*) jdd_window_info_struct_p->currFocussedControlID;
        if (control_info_p == NULL)
        {
            return;
        }

        switch (control_info_p->uiControlType)
        {
            case E_TEXT_BOX:
            {
                control_event_data.eEventType = JC_MMI_LINK_EVENT;
            }
                break;

            case E_INPUT_BOX:
            {
                control_event_data.eEventType = JC_MMI_INPUT_EVENT;
            }
                break;

            case E_BUTTON:
            {
                control_event_data.eEventType = JC_MMI_BUTTON_EVENT;
            }
                break;

            case E_CHECK_BOX:
            {
                control_event_data.eEventType = JC_MMI_CHECK_EVENT;
            }
                break;

            case E_RADIO_BOX:
            {
                control_event_data.eEventType = JC_MMI_RADIO_EVENT;
            }
                break;

            case E_LIST_BOX:
            {
                control_event_data.eEventType = JC_MMI_LIST_EVENT;
            }
                break;

            case E_COMBO_BOX:
            {
                control_event_data.eEventType = JC_MMI_COMBO_EVENT;
            }
                break;

            case E_PICTOGRAM:
            case E_IMAGE_TEXT:
            case E_IMAGE:
            case E_OBJECT:
            {
                control_event_data.eEventType = JC_MMI_IMAGE_EVENT;
            }
                break;

            default:
            {
                return;
            }
        }

        event_data.uiEventInfoSize = sizeof(JC_MMI_EVENT);

        ret = jdd_QueueAlloc(&event_data);
        if (JC_OK != ret)
        {
            return;
        }

        jc_memcpy(event_data.pEventInfo, &control_event_data, sizeof(JC_MMI_EVENT));

        ret = jdd_QueueSend(&event_data);

        if (JC_OK != ret)
        {
            return;
        }

        g_mmi_brw_cntx.is_rendered_flag = E_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_sat_goto_url_event
 * DESCRIPTION
 *  Goto event from sat(fetch a url from sat application)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_sat_goto_url_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA event_data = {0, };
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    jc_memset(&event_data, 0, sizeof(JC_EVENT_DATA));

    event_data.pEventInfo = NULL;
    event_data.uiEventInfoSize = 0;
    event_data.iEventType = E_BRW_SAT_GOTO_URL_EVENT;

    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&event_data);

    jdd_MemSetActiveModuleID(temp_activated_task_id);

    if (JC_OK != ret)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_jbrowser_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_cntx.is_browser_ready;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_is_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_jbrowser_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_cntx.is_browser_init_in_progress;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_is_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_jbrowser_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return g_mmi_brw_cntx.is_layout_initialized; */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_shutdown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_shutdown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_wap_deinit();
    /* Free the DO List for last rendered page */
    mmi_brw_free_do_list();

#ifdef __SAT__
    if (g_mmi_brw_cntx.is_saturl == E_TRUE)
    {
        mmi_brw_send_termination_to_mmi(SAT_BROWSER_USER_TERMINATION);
    }
#endif /* __SAT__ */ 

    if (IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
    {
        DeleteNScrId(SCR_ID_BRW_INTERNET_SERVICES);
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_wap_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_wap_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_WAP_NOT_READY, mmi_brw_exit_wap_not_ready, NULL, NULL);
    StartTimer(JBROWSER_WAP_NOT_READY_TIMER, 2000, mmi_brw_wap_wait_and_go_back);

    ShowCategory66Screen(
        STR_ID_BRW_INTERNET_SERVICES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_ID_BRW_PLEASE_WAIT),
        IMG_ID_BRW_SAT_WAIT,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_wap_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_wap_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(JBROWSER_WAP_NOT_READY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_wait_and_go_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wap_wait_and_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(JBROWSER_WAP_NOT_READY_TIMER);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_cancel_flag_set
 * DESCRIPTION
 *  Function to check if cancel lag is set
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_is_cancel_flag_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_mmi_brw_page_cntx.brw_cancel_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_back
 * DESCRIPTION
 *  Function to check if there is any page behid the current rendered page i.e in history.
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_is_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdi_BrowserIsBack(g_mmi_brw_pbrowser_ctxt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_connection_active_flag
 * DESCRIPTION
 *  Function to check if connection is already there or not
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_connection_active_flag(JC_BOOLEAN flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.is_connection_active = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_data_connection_deactive_flag
 * DESCRIPTION
 *  Function to set data conn deactivate flag only if data connection is in
 *  activated or activating state in case of CSD only and it is reset in data conn callbk.
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_data_connection_deactive_flag(JC_BOOLEAN flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.data_connection_state == BRW_DATACONN_ACTIVATING ||
        g_mmi_brw_cntx.data_connection_state == BRW_DATACONN_ACTIVATED)
    {
        if (mmi_brw_check_csd_data_account())
        {
            g_mmi_brw_cntx.is_data_connection_deactivate = flag;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_rendered_flag
 * DESCRIPTION
 *  Function to check if any page is rendered or not
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_is_rendered_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return g_mmi_brw_cntx.is_rendered_flag; */
    return (g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_brw_screen
 * DESCRIPTION
 *  Function to delete the browser screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_brw_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if there is already rendered page then it remains on the render page if we press abort on calling screen in case of csd bearer */
    if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN) && !mmi_brw_check_browser_scr_pre_delte_condition() &&
        !(g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status))
    {
        DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
    }
    else if ((GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN) &&
             !(g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status))
    {
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_window_active
 * DESCRIPTION
 *  Function to check if the browser window is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_is_browser_window_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        return E_TRUE;
    }

    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_transport_and_data_profile
 * DESCRIPTION
 *  Function to set the profile and data connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_transport_and_data_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    COMM_PROFILE profile;
    JC_RETCODE ret = JC_OK;
    GENERIC_DATA_CONN pdata_conn;
    nvram_wap_profile_content_struct *activated_wap_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activated_wap_profile_p = mmi_ph_get_activated_wap_profile();
    jc_memset(&profile, 0, sizeof(COMM_PROFILE));
    sprintf(
        (PS8) profile.szHostName,
        "%d.%d.%d.%d",
        activated_wap_profile_p->proxy_ip[0],
        activated_wap_profile_p->proxy_ip[1],
        activated_wap_profile_p->proxy_ip[2],
        activated_wap_profile_p->proxy_ip[3]);
    profile.uiPortNumber = (JC_UINT32) activated_wap_profile_p->proxy_port;

    switch (activated_wap_profile_p->conn_type)
    {
        case PH_CONN_TYPE_CONNECTION_OREINTED:
            profile.eConnMode = E_COMM_WSP_CONNECTION_ORIENTED;
            profile.uiPortNumber = (JC_UINT32) MMI_BRW_PH_CONN_PORTNUMBER;
            break;

    #if defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT)
        case PH_CONN_TYPE_CONNECTION_OREINTED_SECURE:
            profile.eConnMode = E_COMM_WSP_CONNECTION_ORIENTED_SECURE;
            profile.uiPortNumber = (JC_UINT32) MMI_BRW_PH_CONN_SECURE_PORTNUMBER;
            break;
    #endif /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 

        case PH_CONN_TYPE_HTTP:
            if (strcmp((PS8) profile.szHostName, (PS8) "0.0.0.0") == 0)
            {
                profile.eConnMode = E_COMM_WPHTTP_DIRECT;
            }
            else
            {
                profile.eConnMode = E_COMM_WPHTTP_PROXY;
                if (profile.uiPortNumber == 0)
                {
                    profile.uiPortNumber = MMI_BRW_PH_CONN_HTTP_PORTNUMBER;
                }
            }
            break;

        default:
            break;
    }
    mmi_brw_set_timeout_value();
    ret = jdi_BrowserSetTransportProfile(g_mmi_brw_pbrowser_ctxt, &profile);

    if (JC_OK != ret)
    {
        ASSERT(0);
    }

    /* Set Data connection profile */
    memset(&pdata_conn, 0, sizeof(GENERIC_DATA_CONN));
    pdata_conn.account_id = activated_wap_profile_p->data_account;

    ret = jdi_BrowserSetDataConnectionProfile(g_mmi_brw_pbrowser_ctxt, (const GENERIC_DATA_CONN*)&pdata_conn);
    if (JC_OK != ret)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_wap_screen_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_brw_jbrowser_wap_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMS_SUPPORT
    U16 screen_id;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_SUPPORT
    screen_id = mms_is_re_entrant();
    if (screen_id)
    {
        return screen_id;
    }
#endif /* MMS_SUPPORT */ 
    return SCR_ID_BRW_JBROWSER_MAIN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_brw_deinit_all, Deinit All");
    /* jdi_BrowserDisconnect(g_mmi_brw_pbrowser_ctxt); */
    /* If browser launch from wap menu then return */
    mmi_jdd_ui_set_jdd_flag(JDD_RENDERING_STARTED, E_FALSE);
    if (!g_mmi_brw_cntx.page_fetch_req_src)
    {
        /* This variable was set when we try to fetch a page through EnterAddress Option
           screen. Reset this flag to 0 when second page fetch from render page's Enter Address throws error. */
        g_mmi_brw_notification_flag = 0;
        g_mmi_brw_cntx.brw_csd_call_disconnect = FALSE;
        jdi_BrowserDisconnect(g_mmi_brw_pbrowser_ctxt);
        return;
    }

    mmi_brw_wap_deinit();

#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
    mmi_ph_deinit_profiles();
    mmi_prov_deinit();
#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Exit mmi_brw_deinit_all, Deinit Completed");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_csd_data_account
 * DESCRIPTION
 *  Returns the status of csd data account
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_brw_check_csd_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_profile_content_struct *activated_wap_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activated_wap_profile_p = mmi_ph_get_activated_wap_profile();

    if (mmi_ph_check_data_account_type(activated_wap_profile_p->data_account) == PH_DATA_ACCOUNT_CSD)
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
 *  mmi_brw_get_ren_page_status
 * DESCRIPTION
 *  Returns the rendering status of cyrrent page
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_get_ren_page_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_page_cntx.brw_page_render_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_ren_page_refersh_display_status
 * DESCRIPTION
 *  Returns the rendering status of rendered page refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_get_ren_page_refersh_display_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_page_cntx.brw_page_refresh_disp_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_browser_scr_pre_delte_condition
 * DESCRIPTION
 *  It checks whether we can delete the brw scr or not
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_brw_check_browser_scr_pre_delte_condition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((IsScreenPresent(SCR_ID_BRW_WAP_ALERT_SCREEN)) ||
        (IsScreenPresent(SCR_ID_BRW_WAP_PROMPT_INPUT_SCREEN)) || (IsScreenPresent(SCR_ID_BRW_AUTHENTICATION)) ||
        /* (IsScreenPresent() == SCR_ID_BRW_JBROWSER_MAIN) || */
        mmi_jdd_ui_is_entry_notification_screen_present())
    {
        return E_TRUE;
    }
    else
    {
        return E_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_long_idle_disconnected_notification
 * DESCRIPTION
 *  Shows long idle disconnected notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_show_long_idle_disconnected_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetTotalCallCount() > 1)    /* voice call as well as data call */
    {
        EntryNewScreen(SCR_ID_BRW_LONG_IDLE_DISCONNECTED, NULL, NULL, NULL);

        ShowCategory151Screen(
            0,
            0,
            0,
            0,
            0,
            0,
            (PU8) GetString(STR_ID_BRW_LONG_IDLE_DISCONNECTED),
            (PU8) GetImage(IMG_GLOBAL_INFO),
            0);
        if (g_mmi_brw_cntx.is_layout_initialized == E_TRUE)
        {
            /* Delete browser screen */
            if ((IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN)) &&
                !(mmi_brw_check_browser_scr_pre_delte_condition()) &&
                !(g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status ||
                  mmi_brw_is_back()))
            {
                DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
            }
        }

    }
    else
    {
        EntryNewScreen(SCR_ID_BRW_LONG_IDLE_DISCONNECTED, NULL, mmi_brw_show_long_idle_disconnected_notification, NULL);

        ShowCategory151Screen(
            0,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            (PU8) GetString(STR_ID_BRW_LONG_IDLE_DISCONNECTED),
            (PU8) GetImage(IMG_GLOBAL_INFO),
            0);

        SetLeftSoftkeyFunction(mmi_brw_handle_long_idle_disconnected_notification, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_long_idle_disconnected_notification
 * DESCRIPTION
 *  Handle key event for long idle disconnected notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_long_idle_disconnected_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if((GetCurrScrnId() == SCR_ID_BRW_JBROWSER_MAIN) &&
     * !(g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status || mmi_brw_is_back()))
     * {
     * DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
     * }
     */
    if (g_mmi_brw_cntx.is_layout_initialized == E_TRUE)
    {
        if ((IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN)) &&
            !(mmi_brw_check_browser_scr_pre_delte_condition()) &&
            !(g_mmi_brw_page_cntx.brw_pre_page_render_status || g_mmi_brw_page_cntx.brw_page_render_status ||
              mmi_brw_is_back()))
        {
            DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
        }
    }

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_focussed_ctrl_title
 * DESCRIPTION
 *  Returns the current focussed control's title
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_CHAR
 *****************************************************************************/
JC_CHAR *mmi_brw_get_focussed_ctrl_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdi_BrowserGetFocusedCtrlTitle(g_mmi_brw_pbrowser_ctxt);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_stylus_focussed_controlID
 * DESCRIPTION
 *  This function is called from JDD level to determine the focus controlID if any.
 * PARAMETERS
 *  curr_controlID          [IN]        This specify the controlID to be searched
 *  focussed_controlID      [OUT]       This provides the associated focus controlID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_get_stylus_focussed_controlID(JC_UINT32 curr_controlID, JC_UINT32 *focussed_controlID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt == NULL)
    {
        *focussed_controlID = 0;
        return;
    }

    ret = jdi_BrowserGetStylusFocusedCtrl(g_mmi_brw_pbrowser_ctxt, curr_controlID, focussed_controlID);
    if (ret != JC_OK)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_stylus_event
 * DESCRIPTION
 *  This function is called from JDD level to intimate browser core with the pen event
 * PARAMETERS
 *  x           [IN]        This specify the x - coordinate realtive to browser window
 *  y           [IN]        This specify the y - coordinate realtive to browser window
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_stylus_event(JC_INT32 x, JC_INT32 y, EStylusEvent event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt == NULL)
    {
        return;
    }

    ret = jdi_BrowserHandleStylusEvent(g_mmi_brw_pbrowser_ctxt, x, y, event);
    if (ret != JC_OK)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_stylus_scroll_event
 * DESCRIPTION
 *  This function is called from JDD level to intimate browser core with the pen scroll event
 * PARAMETERS
 *  ipos            [IN]        This specify the scrollbar position
 *  escrolltype     [IN]        This specify the type of scrollbar Horizontal/Vertical
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_stylus_scroll_event(JC_INT32 ipos, EScrollBarType escrolltype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt == NULL)
    {
        return;
    }

    ret = jdi_BrowserHandleStylusScroll(g_mmi_brw_pbrowser_ctxt, ipos, escrolltype);
    if (ret != JC_OK)
    {
        jdd_MMINotificationMessage((JC_INT32) ret, E_NOTIFICATION_ERR, NULL, NULL);
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_suspend_layout_marquee_timer
 * DESCRIPTION
 *  This function is called from JDD level to intimate browser core for suspending
 *  Layout Marquee Timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_suspend_layout_marquee_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt == NULL)
    {
        return;
    }

    jdi_BrowserSuspendMarqueeTimer(g_mmi_brw_pbrowser_ctxt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_goto_idle_screen_event
 * DESCRIPTION
 *  Function for displaying the idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_goto_idle_screen_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;
    JC_EVENT_DATA event_data = {0, };
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    g_mmi_brw_cntx.end_key_pressed = TRUE;  /* Indicate that end key has been pressed */

    event_data.pEventInfo = NULL;
    event_data.uiEventInfoSize = 0;
    event_data.iEventType = E_BRW_ENDKEY_EVENT;

    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    ret = jdd_QueueSend(&event_data);

    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (JC_OK != ret)
    {
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_resume_layout_marquee_timer
 * DESCRIPTION
 *  This function is called from JDD level to intimate browser core for resuming
 *  Layout Marquee Timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_resume_layout_marquee_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_pbrowser_ctxt == NULL)
    {
        return;
    }

    jdi_BrowserResumeMarqueeTimer(g_mmi_brw_pbrowser_ctxt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_file_name
 * DESCRIPTION
 *  This function returns file name from the given url
 * PARAMETERS
 *  url         [?]         [?]
 *  delim       [IN]        
 * RETURNS
 *  JC_CHAR *
 *****************************************************************************/
JC_CHAR *mmi_brw_get_file_name(S8 *url, U8 delim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 url_len, file_name_len, file_ext_len, index_of_delim, index_of_dot, index_of_file_name_end;
    S16 i;
    JC_CHAR *file_name_p = NULL;
    S8 *url_query_p = NULL;

#ifdef __JBROWSER_DLS_SUPPORT__
    U16 max_file_len = WAP_DL_MAX_FILE_NAME_LEN;
#else 
    U16 max_file_len = FMGR_MAX_PATH_LEN;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(url);

    url_len = (mmi_ucs2strlen((S8*) url)) * ENCODING_LENGTH;
    file_name_len = index_of_delim = index_of_dot = 0;

    url_query_p = (S8*) jc_tcschr((JC_CHAR*) url, '?');
    if (url_query_p != NULL)
    {
        index_of_file_name_end = url_query_p - url; /* '?' symbol present in the url. Ignore characters after '?' symbol */
    }
    else
    {
        index_of_file_name_end = url_len;   /* Here index_of_file_name_end is that index in the url which is either NULL character or special character like '?' */
    }

    for (i = index_of_file_name_end - 1; i >= 0; i--)
    {
        if (*(url + i) == '.')
        {
            index_of_dot = i;
        }

        if (*(url + i) == delim)
        {
            index_of_delim = i;
            break;
        }
    }

    if (delim == '\\')  /* Extracting from default file path given by jdd_FSGetDownloadFileName */
    {
        file_name_len = index_of_file_name_end - index_of_delim - (1 * ENCODING_LENGTH);
        if (file_name_len + (1 * ENCODING_LENGTH) > max_file_len)       /* If file name length exceeds */
        {
            file_name_len = max_file_len - (1 * ENCODING_LENGTH);
        }

        file_name_p = (JC_CHAR*) jdd_MemAlloc(file_name_len + (1 * ENCODING_LENGTH), sizeof(S8));

        /* Copying file_name_len characters from the url */
        for (i = index_of_delim + (1 * ENCODING_LENGTH); i <= index_of_file_name_end; i++)
        {
            *((S8*) file_name_p + i - index_of_delim - (1 * ENCODING_LENGTH)) = *(url + i);
            if (i - index_of_delim - (1 * ENCODING_LENGTH) == file_name_len - 1)        /* break if file_name_len characters are copied */
            {
                break;
            }
        }

        *((S8*) file_name_p + file_name_len) = '\0';
        *((S8*) file_name_p + file_name_len + 1) = '\0';

        return file_name_p;;
    }

    if (index_of_delim == 0 || index_of_file_name_end == 0 || index_of_file_name_end < index_of_delim)  /* Invalid URL. */
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)(%d)(%d)", "DLS: dls_set_file_name", index_of_delim,
                             index_of_dot, index_of_file_name_end);
        return NULL;
    }

    file_ext_len = index_of_file_name_end - index_of_dot;
    file_name_len = index_of_dot - index_of_delim - (1 * ENCODING_LENGTH);

    if (file_name_len + (1 * ENCODING_LENGTH) > max_file_len - file_ext_len)    /* If file name length exceeds */
    {
        file_name_len = max_file_len - file_ext_len - (1 * ENCODING_LENGTH);
    }
    file_name_p = (JC_CHAR*) jdd_MemAlloc(file_name_len + file_ext_len + (1 * ENCODING_LENGTH), sizeof(S8));

    /* Copying file_name_len characters from the url */
    for (i = index_of_delim + (1 * ENCODING_LENGTH); i < index_of_dot; i++)
    {
        *((S8*) file_name_p + i - index_of_delim - (1 * ENCODING_LENGTH)) = *(url + i);
        if (i - index_of_delim - (1 * ENCODING_LENGTH) == file_name_len - 1)    /* break if file_name_len characters are copied */
        {
            break;
        }
    }

    /* Copying file_ext_len characters from the url */
    for (i = 0; i < file_ext_len; i++)
    {
        *((S8*) file_name_p + file_name_len + i) = *(url + index_of_dot + i);
    }

    *((S8*) file_name_p + file_name_len + file_ext_len) = '\0';
    *((S8*) file_name_p + file_name_len + file_ext_len + 1) = '\0';

    return file_name_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_proxy_auth_info
 * DESCRIPTION
 *  This function is to set proxy header in g_mmi_brw_cntx.fetch_url_info
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_brw_set_proxy_auth_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_profile_content_struct *activated_wap_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo = jdd_MemAlloc(sizeof(JC_AUTH_INFO), 1);
    if (g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    activated_wap_profile = mmi_ph_get_activated_wap_profile();
    memset(g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo, 0, sizeof(JC_AUTH_INFO));
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo->sUsername,
        (S8*) activated_wap_profile->username);
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo->sPassword,
        (S8*) activated_wap_profile->password);

    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_free_proxy_auth_info
 * DESCRIPTION
 *  This function is used to free memory allocated by mmi_brw_set_proxy_auth_info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_free_proxy_auth_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemFree(g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo);
    g_mmi_brw_cntx.fetch_url_info.pProxyAuthInfo = NULL;
}
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ // #if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#endif /* _MMI_JBROWSERSTARTUP_C */ // #define _MMI_JBROWSERSTARTUP_C

