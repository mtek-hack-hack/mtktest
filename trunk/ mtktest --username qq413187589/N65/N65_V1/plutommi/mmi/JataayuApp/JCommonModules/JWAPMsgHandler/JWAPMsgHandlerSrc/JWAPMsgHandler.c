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
 * jWAPMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _JWAPMSGHANDLER_C
#define _JWAPMSGHANDLER_C

#ifdef JATAAYU_SUPPORT

#include "gui_data_types.h"

#if defined(MMS_SUPPORT)        /* //Dilip */
#include "JMMSGprot.h"
#include "JMMSMainMMS.h"
#include "JMMSJSRHandler.h"
#endif /* defined(MMS_SUPPORT) */ 
#include "JBrowserMMIProts.h"

#include "JsrTypes.h"
#include "JsrProts.h"
#include "ddl.h"
#include "jcevent.h"
#include "jcerror.h"
#include "wap_ps_struct.h"
#include "JPushInboxUM.h"
#include "fmt_struct.h"
#include "wapadp.h"
#include "jdd_configapi.h"
#include "jdd_memapi.h"

/* JDD Header Files */
#include "jdd_ui_datatypes.h"
#include "jdd_ui_utils.h"

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#include "JProvCCAHandler.h"
#include "JProvisioning.h"
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

extern JC_INT32 jdd_FSGetDiskLabel(wap_storage_enum storage_id);
extern JC_RETCODE jdd_FSCreateWapMmsSysFolders(void);
extern void jdd_CFGRestoreEmDataFromSYSFile(void);

/* extern jdd_MemSetActiveModuleID(ETaskID taskId); */

#if defined (MMS_SUPPORT)
extern JC_BOOLEAN jmms_whether_format(void);
#endif 

#define WAP_MAX_USERAGENT_LENGTH 255

#ifdef __USB_IN_NORMAL_MODE__

#if defined (WAP_SUPPORT)
extern void mmi_brw_handle_usb_enter_req(void);
extern void mmi_brw_handle_usb_exit_req(void);
#endif /* defined (WAP_SUPPORT) */ 

#if defined (MMS_SUPPORT)
extern void mmi_jmms_handle_usb_enter_req(void);
extern void mmi_jmms_handle_usb_exit_req(void);
#endif /* defined (MMS_SUPPORT) */ 

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_get_wap_user_agent_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_GET_USER_AGENT_RSP primitive to Src Module
 * PARAMETERS
 *  src_mod     [IN]        
 *  sap_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_get_wap_user_agent_rsp(module_type src_mod, sap_type sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_user_agent_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;
    JC_TASK_INFO task_info;
    JC_UINT32 url_length = WAP_MAX_USERAGENT_LENGTH;
    JC_INT8 *url_str = NULL;
    JC_RETCODE rCode = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_get_user_agent_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_user_agent_rsp_struct));
    task_info.iAppID = E_TASK_BROWSER_UI;
    task_info.iTaskID = E_TASK_BROWSER_UI;

    url_str = (JC_INT8*) jdd_MemAlloc(1, WAP_MAX_USERAGENT_LENGTH + 1);

    if (url_str == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        ASSERT(url_str);
    #else 
        return;
    #endif 
    }

    rCode = jdd_CFGGetUserAgent(&task_info, url_str, &url_length);
    if (rCode == JC_OK)
    {
        if (url_length > WAP_MAX_USERAGENT_LENGTH)
        {
            url_length = WAP_MAX_USERAGENT_LENGTH;
        }

        memset(myMsgPtr->user_agent, 0x00, sizeof(myMsgPtr->user_agent));
        myMsgPtr->user_agent_len = strlen(url_str);
        memset(myMsgPtr->user_agent, 0, myMsgPtr->user_agent_len);
        memcpy(myMsgPtr->user_agent, url_str, myMsgPtr->user_agent_len);
        jdd_MemFree(url_str);

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->sap_id = sap_id;
        ilm_ptr->dest_mod_id = src_mod;
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_GET_USER_AGENT_RSP;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);
        return;
    }
#ifndef __PRODUCTION_RELEASE__
    ASSERT(0);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_fmt_format_rsp
 * DESCRIPTION
 *  This function is used to send FMT format response
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_fmt_format_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_format_rsp_strcut *fmt_format_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_format_rsp =
        (mmi_fmt_format_rsp_strcut*) construct_local_para((kal_uint16) sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);
    fmt_format_rsp->result = FS_NO_ERROR;

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = MSG_ID_MMI_FMT_FORMAT_RSP;
    Message.oslDataPtr = (oslParaType*) fmt_format_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#if defined (WAP_SUPPORT) || defined (MMS_SUPPORT)
#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  wap_send_usb_enter_req_res
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_usb_enter_req_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMS_ENTER_USB_MODE_RSP;
    message.oslDataPtr = NULL;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_usb_exit_req_res
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_usb_exit_req_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMS_EXIT_USB_MODE_RSP;
    message.oslDataPtr = NULL;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}

#endif /* __USB_IN_NORMAL_MODE__ */ 
#endif /* defined (WAP_SUPPORT) || defined (MMS_SUPPORT) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_handle_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_handle_msg(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message = (MYQUEUE*) msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Message->msg_id)
    {
            /* Ask WAP to power on */
        case MSG_ID_MMI_EQ_POWER_ON_IND:
        {
            extern void jtransport_initialize(module_type modId);
            extern void mmi_ph_init(void);
            extern void mmi_jmms_init(void);
            extern void mmi_brw_wap_init(void);

        #ifdef MMS_SUPPORT
            if (wap_is_ready() == KAL_TRUE || wap_is_init() == KAL_TRUE ||
                mmi_jmms_is_template_creation_underway() == KAL_TRUE)
        #else /* MMS_SUPPORT */ 
            if (wap_is_ready() == KAL_TRUE || wap_is_init() == KAL_TRUE)
        #endif /* MMS_SUPPORT */ 
            {
                break;
            }

            /* Create WAP System Folder, z:\@wap, z:\@wap\mms_sys, @mms */
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            jdd_FSCreateWapMmsSysFolders();
            /* Restore WAP EngineerMode Setting */
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            jdd_CFGRestoreEmDataFromSYSFile();
            /* Send primitive to WPS to startup JTA and Transport task */
            jtransport_initialize(MOD_MMI);

            /* TO-Do: PMT shall initialize browser and mms here. */
            /* IMPORTANT: For now, mmi_ph_init() must be called before mmi_jmms_init() & mmi_brw_wap_init(). (FIX IT...) */
        #if defined (WAP_SUPPORT) || defined (MMS_SUPPORT)
            mmi_ph_init();
        #ifdef __MMI_JATAAYU_CCA_SUPPORT__
        #ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__
            mmi_prov_cca_dm_init();
        #endif 
        #endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
        #endif /* defined (WAP_SUPPORT) || defined (MMS_SUPPORT) */ 

            /* The function below will init the font information required for both Browser and MMS */
            mmi_jdd_ui_init_font_info();

        #if defined (MMS_SUPPORT)
            mmi_jmms_init();
        #endif 

        #if defined (WAP_SUPPORT)
            mmi_brw_wap_init();
        #endif 

            break;
        }
        case MSG_ID_MMI_JATAAYU_QUEUE_RECV_IND:
        {
        #if defined(MMS_SUPPORT)        /* Dilip */
            extern void jMMSAppProcessEventsInQueue(void);
            extern void jMMSCoreProcessEventsInQueue(void);
        #endif /* defined(MMS_SUPPORT) */ 
            extern void mmi_brw_jbrowser_app_process_events_in_queue(void);
            extern void mmi_brw_jbrowser_core_process_events_in_queue(void);
            extern void jdd_QueueSendRecvIndToTask(module_type module);
            extern void jdd_QueueDecreaseTaskRecvInd(module_type taskId);

            jdd_QueueDecreaseTaskRecvInd(MOD_WAP);
        #if defined(MMS_SUPPORT)        /* Dilip */
            jMMSAppProcessEventsInQueue();
            jMMSCoreProcessEventsInQueue();
        #endif /* defined(MMS_SUPPORT) */ 
            mmi_brw_jbrowser_app_process_events_in_queue();
            mmi_brw_jbrowser_core_process_events_in_queue();

            /* Send the MSG_ID_MMI_JATAAYU_QUEUE_RECV_IND to MMI task again */
            jdd_QueueSendRecvIndToTask(MOD_WAP);
            break;
        }

    #if defined (WAP_SUPPORT) || defined (MMS_SUPPORT)
    #ifdef __USB_IN_NORMAL_MODE__

        case MSG_ID_MMS_ENTER_USB_MODE_REQ:
        {
        #if defined (WAP_SUPPORT)
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_brw_handle_usb_enter_req();
        #endif /* defined (WAP_SUPPORT) */ 

        #if defined (MMS_SUPPORT)
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
            mmi_jmms_handle_usb_enter_req();
        #endif /* defined (MMS_SUPPORT) */ 

            wap_send_usb_enter_req_res();
            break;
        }

        case MSG_ID_MMS_EXIT_USB_MODE_REQ:
        {
        #if defined (WAP_SUPPORT)
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_brw_handle_usb_exit_req();
        #endif /* defined (WAP_SUPPORT) */ 

        #if defined (MMS_SUPPORT)
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
            mmi_jmms_handle_usb_exit_req();
        #endif /* defined (MMS_SUPPORT) */ 

            wap_send_usb_exit_req_res();

            break;
        }

    #endif /* __USB_IN_NORMAL_MODE__ */ 

    #ifdef __MMI_JATAAYU_CCA_SUPPORT__
        case MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP:
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_prov_cca_new_doc_res_hdlr((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP:
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_prov_cca_new_setting_res_hdlr((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_CCA_APP_CONFIGURE_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_prov_cca_app_config_req_hdlr((void*)Message->oslDataPtr);
            break;
        }
    #ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__
        case MSG_ID_MMI_CCA_APP_GET_PROF_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_prov_cca_dm_get_prof_ind((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
            mmi_prov_cca_dm_update_prof_ind((void*)Message->oslDataPtr);
            break;
        }

    #endif /* __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */ 
    #endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    #endif /* defined (WAP_SUPPORT) || defined (MMS_SUPPORT) */ 
        case MSG_ID_WAP_GET_BRA_PROF_ID_REQ:
        {
            extern void mmi_ph_get_activated_prof_id_req_hdlr(module_type req_src_id);

            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_ph_get_activated_prof_id_req_hdlr(Message->src_mod_id);
            break;
        }
        case MSG_ID_WAP_GET_PROF_LIST_REQ:
        {
            extern void mmi_ph_get_prof_list_req_hdlr(module_type);

            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

            mmi_ph_get_prof_list_req_hdlr(Message->src_mod_id);
            break;

        }
        case MSG_ID_WAP_GET_PROF_CONTENT_REQ:
        {

            extern void mmi_ph_get_prof_content_req_hdlr(module_type, void*);

            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

            mmi_ph_get_prof_content_req_hdlr(Message->src_mod_id, (void*)Message->oslDataPtr);
            break;
        }

            /* /manish - 03-April */
        case MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ:
        {
            extern void mmi_brw_wap_restore_factory_setting_req(void *dataBuf);

            jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

            mmi_brw_wap_restore_factory_setting_req((void*)Message->oslDataPtr);
            break;

        }
        case MSG_ID_MMI_FMT_FORMAT_REQ:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Recieved Format Req in JWAPMsgHandler");

        #ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
            mmi_brw_offline_pages_reset_sync();
        #endif 

            if (wap_is_ready())
            {
                mmi_fmt_format_req_strcut *fmt_format_req = (mmi_fmt_format_req_strcut*) Message->oslDataPtr;

                ASSERT(fmt_format_req);

                if (fmt_format_req->drive == (kal_uint8) jdd_FSGetDiskLabel(WAP_STORAGE_MMS))
                {
                    /* Restart JBrowser and JMMS here */
                    /* After shutdown JBrowser and JMMS, please invoke wap_send_fmt_format_rsp() to send reply to MOD_FMT */
                    extern void mmi_brw_wap_deinit(void);
                    extern void mmi_brw_deinit_jbrowser_ctxt(void);
                    extern void mmi_brw_wap_init(void);

                    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
                    mmi_brw_wap_deinit();
                    mmi_brw_deinit_jbrowser_ctxt();
                    jdd_FSCreateWapMmsSysFolders(); /* Create Folders before Init */
                    mmi_brw_wap_init();
                #if defined (MMS_SUPPORT)       /* //Dilip */
                    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
                    mmi_jmms_deinit_mms_for_file_format();
                    mmi_jmms_init_mms_after_file_format();
                #endif /* defined (MMS_SUPPORT) */ 
                }
                else
                {
                    jdd_FSCreateWapMmsSysFolders();
                    wap_send_fmt_format_rsp();
                }
            }
            else
            {
            #if defined (MMS_SUPPORT)
                mmi_fmt_format_req_strcut *fmt_format_req = (mmi_fmt_format_req_strcut*) Message->oslDataPtr;

                ASSERT(fmt_format_req);
            #endif /* defined (MMS_SUPPORT) */ 
                jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
                jdd_FSCreateWapMmsSysFolders();
            #if defined (MMS_SUPPORT)
                if ((fmt_format_req->drive == (kal_uint8) jdd_FSGetDiskLabel(WAP_STORAGE_MMS)) && jmms_whether_format())
                {
                    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
                    mmi_jmms_deinit_mms_for_file_format();
                    mmi_jmms_init_mms_after_file_format();
                }
                else
            #endif /* defined (MMS_SUPPORT) */ 
                {
                    wap_send_fmt_format_rsp();
                }
            }
            break;
        }
        case MSG_ID_WAP_GET_USER_AGENT_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_get_wap_user_agent_rsp(Message->src_mod_id, Message->sap_id);
            break;
        }
        case MSG_ID_WAP_BROWSER_POWEROFF_REQ:
        {
            extern void mmi_brw_wap_poweroff_request(void *dataBuf);

            mmi_brw_wap_poweroff_request((void*)Message->oslDataPtr);
            break;
        }

        case MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ:
        {
            extern void mmi_brw_sat_launch_request(void *dataBuf);

            mmi_brw_sat_launch_request((void*)Message->oslDataPtr);
            break;
        }

        case MSG_ID_WAP_BROWSER_STARTUP_REQ:
        {
            extern void mmi_brw_wap_startup_req_hdlr(void *dataBuf);

            if (wap_is_ready())
            {
                mmi_brw_wap_startup_req_hdlr((void*)Message->oslDataPtr);
            }
            else
            {
                wap_entry_no_ready_screen(WAP_SERVICE_BROWSER);
            }

            break;
        }

        case MSG_ID_WAP_SELECT_BOOKMARK_REQ:
        {
            g_mmi_brw_cntx.jbrowser_frm_ext_app = MMI_TRUE;
            mmi_brw_entry_bookmark_list();
            break;
        }

    #if defined (MMS_SUPPORT)       /* Dilip */
            //PMT HIMANSHU START 20060326
            // Java Profile
        case MSG_ID_WAP_MMC_GET_MMS_PROF_REQ:
        {
            extern void mmi_jsr_get_mms_profile_req(void *msg);

            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_get_mms_profile_req((void*)Message->oslDataPtr);

            break;
        }
            /* AT Commands */
        case MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_read_folder_status_req_hldr((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_upload_msg_req_hldr((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_delete_msg_req_hldr((void*)Message->oslDataPtr);
            break;
        }
            /* JSR Messages */
        case MSG_ID_WAP_MMC_SEND_APPMMS_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_send_appmms_req_hldr(
                (void*)Message->oslDataPtr,
                (int)Message->oslSrcId,
                (void*)Message->oslPeerBuffPtr);
            break;
        }
        case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_send_post_appmms_msg_part_rsp((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMC_RECV_APPMMS_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_receive_appmms_req_hldr((void*)Message->oslDataPtr);
            break;
        }
            /* PMT HIMANSHU START 20060425 */
        case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_read_appmms_msg_part_req();
            break;
        }
            /* PMT HIMANSHU END 20060425 */
        case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_cfg_appmms_appid_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_check_appmms_coming_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMC_ABORT_APPMMS_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_jsr_abort_appmms_req((void*)Message->oslDataPtr);
            break;
        }
    #endif /* defined (MMS_SUPPORT) */ 
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_um_brw_get_message_count_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_UM_GET_LIST_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_um_brw_get_message_list_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_um_brw_get_message_info_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_um_brw_delete_all_messages_req((void*)Message->oslDataPtr);
            break;
        }
        case MSG_ID_MMI_UM_DELETE_ALL_RES:
        {
            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            mmi_um_brw_delete_all_messages_rsp((void*)Message->oslDataPtr);
            break;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
      /**********************************************************************
        This case is added to handle the message to get the virtual file
        path of the attachment file. It generates the response message after 
        getting the virtual file path of the attached file.

        Date       : July 19, 2006
        Written By : RAJ KUMAR GUPTA
      **********************************************************************/
    #if defined(MMS_SUPPORT)        /* Dilip */
    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__

        case MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ:
        {
            ilm_struct *send_ilm = NULL;

            /* Get the parameters, attached with the request message */
            mms_get_attachment_req_struct *req_msg = (mms_get_attachment_req_struct*) Message->local_para_ptr;
            mms_get_attachment_rsp_struct *msg = construct_local_para(sizeof(mms_get_attachment_rsp_struct), TD_CTRL);

            jdd_MemSetActiveModuleID(E_TASK_MMS_UI);

            /* To get the virtual file's path, if it exists in the attachment. */
            mmi_jmms_get_attachment_filepath((S8*) req_msg->filename, msg);
            send_ilm = allocate_ilm(MOD_WAP);
            send_ilm->src_mod_id = MOD_WAP;
            send_ilm->dest_mod_id = MOD_J2ME;
            send_ilm->local_para_ptr = (local_para_struct*) msg;
            send_ilm->peer_buff_ptr = NULL;
            /* Set the Message ID */
            send_ilm->msg_id = MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP;
            send_ilm->sap_id = J2ME_MMI_SAP;
            msg_send_ext_queue(send_ilm);
            break;
        }
    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
    #endif /* defined(MMS_SUPPORT) */ 

    #ifdef __JBROWSER_DLS_SUPPORT__
        case MSG_ID_WAP_MMI_FILE_DL_RES:
        {
            mmi_brw_dls_file_dl_res_hdlr((void*)Message->oslDataPtr);
            break;
        }

        case MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES:
        {
            mmi_brw_dls_file_dl_progress_res_hdlr((void*)Message->oslDataPtr);
            break;
        }

        case MSG_ID_WAP_MMI_FILE_DL_STOP_REQ:
        {
            mmi_brw_dls_file_dl_stop_req_hdlr((void*)Message->oslDataPtr);
            break;
        }

    #endif /* __JBROWSER_DLS_SUPPORT__ */ 

    #if defined (__UNIFIED_COMPOSER_SUPPORT__) && defined(MMS_SUPPORT)
        case MSG_ID_WAP_MMA_UC_START_RSP:
        case MSG_ID_WAP_MMA_GET_SETTING_REQ:
        case MSG_ID_WAP_MMA_CREATE_REQ:
        case MSG_ID_WAP_MMA_PREVIEW_REQ:
        case MSG_ID_WAP_MMA_SAVE_REQ:
        case MSG_ID_WAP_MMA_SEND_REQ:
        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        case MSG_ID_WAP_MMA_DELETE_REQ:
        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            void mmi_jmms_uc_wap_handle_msg(void *msgPtr);

            mmi_jmms_uc_wap_handle_msg((void*)msgPtr);
            break;
        }
    #endif /* defined (__UNIFIED_COMPOSER_SUPPORT__) && defined(MMS_SUPPORT) */ 
    #if defined (WAP_SEC_SUPPORT) && defined (__CERTMAN_SUPPORT__)
        case MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF:
            mmi_brw_handle_get_certificate_details_cnf((void*)Message->oslDataPtr);
            break;
        case MSG_ID_CERTMAN_READY_SUBSCRIBE_CNF:
            mmi_brw_handle_certman_ready_cnf((void*)Message->oslDataPtr);
            break;
        case MSG_ID_CERTMAN_GET_PRIVKEY_CNF:
            mmi_brw_get_private_key_cnf((void*)Message->oslDataPtr);
            break;
        case MSG_ID_MMI_CERTMAN_INVALID_CERT_RSP:
            mmi_brw_handle_invalid_cert_resp((void*)Message->oslDataPtr);
            break;
        case MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_RSP:
            mmi_brw_handle_select_user_cert_resp((void*)Message->oslDataPtr);
            break;
        case MSG_ID_MMI_CERTMAN_VIEW_CERT_RSP:
            mmi_brw_handle_view_cert_resp((void*)Message->oslDataPtr);
            break;
    #endif /* defined (WAP_SEC_SUPPORT) && defined (__CERTMAN_SUPPORT__) */ 
        default:
            break;
    }
}

#endif /* JATAAYU_SUPPORT */ // #ifdef JATAAYU_SUPPORT
#endif /* _JWAPMSGHANDLER_C */ 

