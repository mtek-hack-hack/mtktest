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
 *  JMMSInit.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for template folder in mms
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
// #if 0 //Pranav Commeneted
/*  Include: MMI header file */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "FileManagerDef.h"

#include "JMMSView.h"

#include "JMMSGprot.h"
#include "JMMSExdcl.h"
#include "JMMSView.h"

#include "JMMSMainMMS.h"
#include "JMMSMessageSettings.h"
#include "jdd_MessagingConfig.h"
#include "JMMSStoreHandling.h"
#include "JMMSCompose.h"
#include "JMMSOutbox.h"
#include "JMMSSent.h"
#include "JMMSTemplates.h"
#include "JMMSWriteMMS.h"
#include "JMMSProtocols.h"
#include "JMMSDrafts.h"
#include "JMMSInbox.h"
#include "JMMSResDef.h"
#include "JMMSCoreAPI.h"
#include "JMMSMainMMS.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#endif 
#ifdef __MMI_UNIFIED_COMPOSER__
#include "JMMSUCInterfaceProt.h"
#endif 
#include "JMMSPushHandling.h"
/*  Include: Jataayu header file */
#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"
#include "jdd_ui_datatypes.h"
#include "jdd_ui_window.h"
#include "jdd_videoapi.h"
/* ... Add More MMI header */
/*  Include: PS header file */
/* ... Add More PS header */

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
extern void wap_send_fmt_format_rsp(void);
extern JC_RETCODE jdd_FSCreateWapMmsSysFoldersExt(
                    JC_BOOLEAN isWAPsysFolder,
                    JC_BOOLEAN isMMSsysFolder,
                    JC_BOOLEAN is_remove_temp_files);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_init
 * DESCRIPTION
 *  Initialization function of MMS .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init Start");
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    if (g_jmms_context == NULL)
    {
        g_jmms_context = (mmi_jmms_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_context_struct), 1);
        if (g_jmms_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
    }
    if (g_jmms_context->store_context == NULL)
    {
        g_jmms_context->store_context =
            (mmi_jmms_store_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_store_context_struct), 1);
        if (g_jmms_context->store_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }

    if (g_jmms_context->init_done == JMMS_NOT_INITIALIZED)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init: initial %d", g_jmms_context->init_done);
        g_jmms_context->init_done = JMMS_INITIALIZING;
        g_jmms_context->interupt_screen_title = 0;
        g_jmms_context->g_mms_downloading_busy = 0;
        g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_BACK;
        g_jmms_context->g_jmms_control = E_ENTRY_FROM_MMS_SETTINGS;
        g_jmms_context->g_reply_charging_done = 0;
        g_jmms_context->g_recieve_filter_done = 0;
        g_jmms_context->g_text_custom_color_rgb = 0x00000064;
        g_jmms_context->g_bg_custom_color_rgb = 0x00000064;
        g_jmms_context->g_custom_var_change = 0;
        g_jmms_context->g_custom_var_change = 0;
        g_jmms_context->g_slider_info = MMI_CAT91_COLOR_SLIDER_RED_COLOR;
        g_jmms_context->gtemplate_count = 0;
        g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    #ifdef __MMI_UNIFIED_COMPOSER__
        g_jmms_context->uc_creation_req = JMMS_UC_FOREGROUND_SAVING;
        g_jmms_context->send_node_list = NULL;
        g_jmms_context->uc_cancel_req_id = 0;
    #endif /* __MMI_UNIFIED_COMPOSER__ */ 

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init: %d", g_jmms_context->init_done);
        g_jmms_context->g_media_buffer_p = NULL;
        jdd_MsgConfigFSHandleInit();
        mmi_jmms_create_mms_queue();
        mmi_jmms_init_protocol();
        mmi_jmms_compose_init();
        mmi_jmms_view_init();
    #ifndef __MMI_UNIFIED_MESSAGE__
        mmi_jmms_main_mms_init();
    #endif 
        mmi_jmms_drafts_init();
        mmi_jmms_inbox_init();
        mmi_jmms_message_settings_init();
        mmi_jmms_outbox_init();
        mmi_jmms_sent_init();
    #ifndef __MMI_UNIFIED_COMPOSER__
        mmi_jmms_write_message_init();
    #endif 
        mmi_jmms_templates_init();
        mmi_jmms_init_store();

    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_jmms_check_usb_mode() == 0)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Phone bootup with no USB mode so syncing mms files");
            mmi_jmms_cached_pending_mms();
            mmi_jmms_usb_delete_mms_system_folder();
            mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Phone bootup with USB mode so no syncing of mms files");
        }

    #else /* __USB_IN_NORMAL_MODE__ */ 
        mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        if (g_jmms_context->init_done != JMMS_NOT_INITIALIZED && !g_jmms_context->is_in_ready_without_store_init_mode)
        {
            mmi_jmms_create_templates_in_store();
        }
        if (g_jmms_context->init_done != JMMS_NOT_INITIALIZED && g_jmms_context->is_in_ready_without_store_init_mode)
        {
            g_jmms_context->init_done = JMMS_TEMPLATES_INITIALIZED;
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init in between: %d", g_jmms_context->init_done);
        switch (g_jmms_context->init_done)
        {
            case JMMS_TEMPLATES_INITIALIZED:
                g_jmms_context->init_done = JMMS_READY;
                if (g_jmms_context->is_in_format_mode)
                {
                    wap_send_fmt_format_rsp();
                    g_jmms_context->is_in_format_mode = 0;
                }
            #ifdef __MMI_UNIFIED_MESSAGE__
                mmi_um_jmms_ready_ind();
            #endif 
                break;
            case JMMS_NOT_INITIALIZED:
                g_jmms_context->init_done = JMMS_READY;
                if (g_jmms_context->is_in_format_mode)
                {
                    wap_send_fmt_format_rsp();
                    g_jmms_context->is_in_format_mode = 0;
                }
                mmi_jmms_deinit_shutdown_with_protocol_init();
                g_jmms_context->init_done = JMMS_READY_WITHOUT_STORE;
            #ifdef __MMI_UNIFIED_MESSAGE__
                mmi_um_jmms_ready_ind();
            #endif 
                break;
            case JMMS_INITIALIZING:
                g_jmms_context->init_done = JMMS_INITIALIZED;
                break;
        }
    }
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_delete_uc_compose_files();
#endif 
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init End, ready status: %d", g_jmms_context->init_done);
    g_jmms_context->disable_warning_popup = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_deinit_shutdown
 * DESCRIPTION
 *  Deinits MMS on shutdown
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_deinit_shutdown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enter mmi_jmms_deinit_shutdown: %d", g_jmms_context->init_done);
    if (!(g_jmms_context && g_jmms_context->init_done == JMMS_READY))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_deinit_shutdown MMS Not Initialized");
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_jmms_check_usb_mode() == 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Phone shutdown, caching pending MMS");

        mmi_jmms_cached_pending_mms();
        mmi_jmms_usb_delete_mms_system_folder();
        mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_jmms_recreate_sys_folders();    /* create mms_sys folder */
    mmi_jmms_parse_continue_stop_timer();
    StopTimer(JMMS_ASYNC_SAVE_TIMER);
    mmi_jmms_clean_save_callback_list();

    jdi_CommunicationStopAllReq(g_jmms_context->comm_handle);
    mmi_jmms_free_comm_node_list();
    jdi_CommunicationDeinitialize(g_jmms_context->comm_handle);

    mmi_jmms_de_init_store();
    jdd_MsgConfigFSHandleDeInit();

    if (g_jmms_context != NULL)
    {
        mmi_jmms_free_read_unread_status_bytes();

        if (g_jmms_context->store_context != NULL)
        {
            jdd_MemFree(g_jmms_context->store_context);
            g_jmms_context->store_context = NULL;

        }
    }
    /* Handle the scenario for a new mms notification already present in the queue */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_deinit_shutdown: %d", g_jmms_context->init_done);
    g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
}


/*****************************************************************************
 * FUNCTION
 *  jmms_whether_format
 * DESCRIPTION
 *  Checks if phone is in format mode or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN jmms_whether_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Format req: g_jmms_context->init_done = %d", g_jmms_context->init_done);
        if (g_jmms_context->init_done != JMMS_NOT_INITIALIZED)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Format req: Returns TRUE");
            return E_TRUE;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Format req: Returns FALSE");
    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jmms_is_init
 * DESCRIPTION
 *  Checks if MMS is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN jmms_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL && g_jmms_context->init_done == JMMS_INITIALIZING)
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
 *  mmi_jmms_is_template_creation_underway
 * DESCRIPTION
 *  Checks if MMS is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_template_creation_underway(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL && g_jmms_context->init_done == JMMS_INITIALIZED)
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
 *  jmms_is_ready
 * DESCRIPTION
 *  Check if MMS is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN jmms_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL &&
        (g_jmms_context->init_done == JMMS_READY || g_jmms_context->init_done == JMMS_READY_WITHOUT_STORE))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready: g_jmms_context->init_done = %d",
                             g_jmms_context->init_done);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready returns TRUE");
        return E_TRUE;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready returns FALSE");
        return E_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_deinit_mms_for_file_format
 * DESCRIPTION
 *  Deinit MMS for File Format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_deinit_mms_for_file_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init_mms_before_file_format: %d", g_jmms_context->init_done);
    g_jmms_context->is_in_format_mode = 1;
    jdi_CommunicationStopAllReq(g_jmms_context->comm_handle);
    mmi_jmms_free_comm_node_list();
    jdi_CommunicationDeinitialize(g_jmms_context->comm_handle);
    mmi_jmms_recreate_sys_folders();
    mmi_jmms_parse_continue_stop_timer();
    mmi_jmms_deinit_mms_context(g_jmms_context);
    StopTimer(JMMS_ASYNC_SEND_TIMER);
    StopTimer(JMMS_ASYNC_SAVE_TIMER);
    mmi_jmms_clean_save_callback_list();
    mmi_jmms_clean_send_callback_list();
    mmi_jmms_de_init_store();
    jdd_MsgConfigFSHandleDeInit();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_init_mms_after_file_format
 * DESCRIPTION
 *  Re-Initialize MMS after File Format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_init_mms_after_file_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init_mms_after_file_format: %d", g_jmms_context->init_done);
    g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
    mmi_jmms_init();
    if (g_jmms_context->pending_mms_info_list || g_jmms_context->pending_read_reports)
    {
        mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry();
    }
    mmi_jmms_update_status_icon_indicator();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_deinit_shutdown_with_protocol_init
 * DESCRIPTION
 *  Checks if MMS is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_deinit_shutdown_with_protocol_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_jmms_context && g_jmms_context->init_done == JMMS_READY))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_deinit_shutdown_with_protocol_init");
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_jmms_check_usb_mode() == 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_deinit_shutdown_with_protocol_init, caching pending MMS");

        mmi_jmms_cached_pending_mms();
        mmi_jmms_usb_delete_mms_system_folder();
        mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    jdi_CommunicationStopAllReq(g_jmms_context->comm_handle);
    mmi_jmms_free_comm_node_list();

    mmi_jmms_de_init_store();
    jdd_MsgConfigFSHandleDeInit();

    if (g_jmms_context != NULL)
    {
        mmi_jmms_free_read_unread_status_bytes();

        if (g_jmms_context->store_context != NULL)
        {
            jdd_MemFree(g_jmms_context->store_context);
            g_jmms_context->store_context = NULL;
        }
    }
    /* Handle the scenario for a new mms notification already present in the queue */
    g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_ready_without_store
 * DESCRIPTION
 *  Checks if MMS is initializing
 * PARAMETERS
 *  show_indication     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_is_ready_without_store(S32 show_indication)
{
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->init_done != JMMS_READY_WITHOUT_STORE)
    {
        return 0;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: Store is not ready");
        ret_code = jdd_FSCreateWapMmsSysFoldersExt(E_FALSE, E_TRUE, E_FALSE);
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Fail to create MMS SYS folder");
        }
        if (mmi_jmms_sys_folders_exist() == JC_OK)
        {
            g_jmms_context->is_in_ready_without_store_init_mode = 1;
            jdi_CommunicationDeinitialize(g_jmms_context->comm_handle);
            g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
            mmi_jmms_init();
            mmi_jmms_update_status_icon_indicator();
            g_jmms_context->is_in_ready_without_store_init_mode = 0;
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Fail to create MMS SYS folder at bottom");
        if (g_jmms_context->init_done == JMMS_READY_WITHOUT_STORE)
        {
            if (show_indication)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
            }
            return 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jmms_is_ready_with_store
 * DESCRIPTION
 *  Check if MMS is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN jmms_is_ready_with_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL && g_jmms_context->init_done == JMMS_READY)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready_with_store: g_jmms_context->init_done = %d",
                             g_jmms_context->init_done);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready_with_store returns TRUE");
        return E_TRUE;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "jmms_is_ready_with_store returns FALSE");
        return E_FALSE;
    }
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

