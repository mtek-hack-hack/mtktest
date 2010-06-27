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
 *  CentralConfigAgentDispatcher.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Dispatcher Code
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_CCA_SUPPORT__

#include "CentralConfigAgentGProt.h"



/*----------------------------------------------------------------*/
/* DECLARATIONS                                                   */
/*----------------------------------------------------------------*/
/* Data Account */
extern void mmi_dtcnt_ota_proc_cca_doc(U16 conf_id, S32 doc_hdl);
extern void mmi_dtcnt_ota_dm_retrieve_ind(U16 appid, S32 profid);
extern void mmi_dtcnt_ota_dm_update_ind(U16 appid, S32 profid, S32 hconfig);

#ifdef __MMI_BROWSER_2__
    /* Q05A Browser/MMS */
    extern void mmi_prov_browser_cca_new_doc(mmi_cca_app_configure_ind_struct *newConfigDoc);
    extern void mmi_prov_mms_cca_new_doc(mmi_cca_app_configure_ind_struct *newConfigDoc);
#ifdef SYNCML_DM_SUPPORT
    extern void mmi_prov_dm_app_recv_prof_ind(void *msg);
    extern void mmi_prov_dm_app_update_prof_ind(void *msg);
#endif  /* SYNCML_DM_SUPPORT */
#endif  /* __MMI_BROWSER_2__ */

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    /* WLAN - DMP */
    extern void mmi_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl);
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */

#ifdef __MMI_SYNCML_CCA_SUPPORT__
    /* SyncML -- DS */
    extern void mmi_syncml_proc_cca_doc(U16 conf_id, S32 doc_hdl);
    extern void mmi_syncml_construct_cca_document_for_dm(U16 app_id, S32 prof_id);
    extern void mmi_syncml_install_cca_document_from_dm(U16 app_id, S32 prof_id, S32 hConfig);
    extern S32 mmi_syncml_checking_for_dm(void);
#endif  /* __MMI_SYNCML_CCA_SUPPORT__ */

#ifdef __MMI_EMAIL_OTAP__
    /* Email */
    #ifdef __USB_IN_NORMAL_MODE__
        #include "USBDeviceGprot.h"
    #endif 
    extern void mmi_email_handle_app_configure(mmi_cca_app_configure_ind_struct *newConfigDoc);
#endif /* __MMI_EMAIL_OTAP__ */

#ifdef __MMI_IMPS_OTA__
    /* IMPS */
    extern void mmi_imps_proc_cca_doc(U16 config_id, S32 hConfig);
#endif  /* __MMI_IMPS_OTA__ */

#ifdef __MMI_SYNCML_DM_OTAP__
    /* SYNCML DM */
    #include "dmuigprot.h"
#endif  /* __MMI_SYNCML_DM_OTAP__ */

#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_dispatch_mmi_cca_app_configure_ind
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_APP_CONFIGURE_IND data to target applications in MMI task
 * PARAMETERS
 *  newConfigDoc    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_dispatch_mmi_cca_app_configure_ind(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_DISPATCHER_PROV, newConfigDoc->config_id);

    MMI_CCA_LOG_DOC(newConfigDoc->hConfig);

    switch (newConfigDoc->config_id)
    {
/*----------------------------------------------------------------*/
/* DISPATCH: DATA ACCOUNT                                         */
/*----------------------------------------------------------------*/
        case CCA_CONFIG_DTACCT:
            mmi_dtcnt_ota_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: WLAN                                                 */
/*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
        case CCA_CONFIG_WLAN:
            mmi_wlan_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
#elif defined(__MMI_WLAN_OTAP_DMP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*----------------------------------------------------------------*/
/* DISPATCH: BROWSER                                              */
/*----------------------------------------------------------------*/
        case CCA_CONFIG_BROWSER:
#if defined(OBIGO_Q03C)
            /* shouldnt enter this place as Q03C Browser is handled in MOD_WAP */
            ASSERT(0);
#elif defined(__MMI_BROWSER_2__)
            mmi_prov_browser_cca_new_doc(newConfigDoc);
#elif defined(JATAAYU_SUPPORT)
            ASSERT(0);
#else

            MMI_TRACE(CCA_TRACE_ERROR, MMI_CCA_DISPATCHER_PROV_APP_NOT_SUPPORT);

            mmi_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
#endif
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: MMS                                                  */
/*----------------------------------------------------------------*/
        case CCA_CONFIG_MMS:
#if defined(OBIGO_Q03C)
            /* shouldnt enter this place as Q03C MMS is handled in MOD_WAP */
            ASSERT(0);
#elif defined(__MMI_BROWSER_2__)
            mmi_prov_mms_cca_new_doc(newConfigDoc);
#elif defined(JATAAYU_SUPPORT)
            ASSERT(0);
#else
            MMI_TRACE(CCA_TRACE_ERROR, MMI_CCA_DISPATCHER_PROV_APP_NOT_SUPPORT);

            mmi_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
#endif
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: SIP                                                  */
/*----------------------------------------------------------------*/
        /*case CCA_CONFIG_SIP:
            //trigger callback or send ILM
            mmi_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
            break;*/

#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */

/*----------------------------------------------------------------*/
/* DISPATCH: EMAIL                                                */
/*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
        case CCA_CONFIG_EMAIL:
            #ifdef __USB_IN_NORMAL_MODE__
                if (mmi_usb_is_in_mass_storage_mode())
                {
                    mmi_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
                }
                else
            #endif /* __USB_IN_NORMAL_MODE__ */
                {
                    mmi_email_handle_app_configure(newConfigDoc);
                }
            break;
#endif /*__MMI_EMAIL_OTAP__*/

/*----------------------------------------------------------------*/
/* DISPATCH: SyncML-DS                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
        case CCA_CONFIG_SYNCMLDS:
            mmi_syncml_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
#endif  /* __MMI_SYNCML_CCA_SUPPORT__ */

/*----------------------------------------------------------------*/
/* DISPATCH: SyncML-DM                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DM_OTAP__
        case CCA_CONFIG_SYNCMLDM:
            mmi_syncml_dm_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
#endif /* __MMI_SYNCML_DM_OTAP__ */

/*----------------------------------------------------------------*/
/* DISPATCH: IMPS                                                 */
/*----------------------------------------------------------------*/
#ifdef __MMI_IMPS_OTA__
        case CCA_CONFIG_IMPS:
            mmi_imps_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
#endif  /* __MMI_IMPS_OTA__ */

/*----------------------------------------------------------------*/
/* DISPATCH: FOTA                                                 */
/*----------------------------------------------------------------*/
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_FOTA_OTAP_DMP__ */

        default:

            MMI_TRACE(CCA_TRACE_ERROR, MMI_CCA_DISPATCHER_PROV_CONFIG_ID_NOT_FOUND); 

            mmi_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_dispatch_mmi_profile_operations
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_APP_GET_PROF_IND and MSG_ID_CCA_APP_UPDATE_PROF_IND
 *  to target applications in MMI task
 * PARAMETERS
 *  local_parm      [in]
 *  oper            [in]    {CCA_OPER_GET, CCA_OPER_UPDATE}
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_dispatch_mmi_profile_operations(cca_oper_enum oper, U16 app_id, void *local_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct *get_prof_ind = 0;
    mmi_cca_app_update_prof_ind_struct *update_prof_ind = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_DISPATCHER_ASYNC, oper, app_id);

    if (oper==CCA_OPER_GET)
    {
        get_prof_ind = (mmi_cca_app_get_prof_ind_struct*)local_parm;
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_DISPATCHER_ASYNC_GET, get_prof_ind->app_id, get_prof_ind->prof_id);
    }
    else if (oper==CCA_OPER_UPDATE)
    {
        update_prof_ind = (mmi_cca_app_update_prof_ind_struct*)local_parm;

        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_DISPATCHER_ASYNC_UPDATE, 
            update_prof_ind->app_id, update_prof_ind->prof_id, update_prof_ind->hConfig);
        
    }
    else
        ASSERT(0);

    switch (app_id)
    {
/*----------------------------------------------------------------*/
/* DISPATCH: DATA ACCOUNT                                         */
/*----------------------------------------------------------------*/
        case CCA_APP_DTACCT:
            if (oper==CCA_OPER_GET)
                mmi_dtcnt_ota_dm_retrieve_ind(app_id, get_prof_ind->prof_id);
            else if (oper==CCA_OPER_UPDATE)
                mmi_dtcnt_ota_dm_update_ind(app_id, update_prof_ind->prof_id, update_prof_ind->hConfig);
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: WLAN                                                 */
/*----------------------------------------------------------------*/
        /*case CCA_APP_WLAN:
            //trigger callback or send ILM
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;*/

/*----------------------------------------------------------------*/
/* DISPATCH: BROWSER                                              */
/*----------------------------------------------------------------*/
        case CCA_APP_BROWSER:
#if defined(OBIGO_Q03C)
            /* shouldnt enter this place as Q03C Browser is handled in MOD_WAP */
            ASSERT(0);
#elif defined(__MMI_BROWSER_2__)
#ifdef SYNCML_DM_SUPPORT
            if (oper==CCA_OPER_GET)
                mmi_prov_dm_app_recv_prof_ind(local_parm);
            else if (oper==CCA_OPER_UPDATE)
                mmi_prov_dm_app_update_prof_ind(local_parm);
#else
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
#endif  /* SYNCML_DM_SUPPORT */
#elif defined(JATAAYU_SUPPORT)
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
#endif
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: MMS                                                  */
/*----------------------------------------------------------------*/
        case CCA_APP_MMS:
#if defined(OBIGO_Q03C)
            /* shouldnt enter this place as Q03C MMS is handled in MOD_WAP */
            ASSERT(0);
#elif defined(__MMI_BROWSER_2__)
#ifdef SYNCML_DM_SUPPORT
            if (oper==CCA_OPER_GET)
                mmi_prov_dm_app_recv_prof_ind(local_parm);
            else if (oper==CCA_OPER_UPDATE)
                mmi_prov_dm_app_update_prof_ind(local_parm);
#else
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
#endif  /* SYNCML_DM_SUPPORT */
#elif defined(JATAAYU_SUPPORT)
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
#endif
            break;

/*----------------------------------------------------------------*/
/* DISPATCH: SIP                                                  */
/*----------------------------------------------------------------*/
        /*case CCA_APP_SIP:
            //trigger callback or send ILM
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;*/

/*----------------------------------------------------------------*/
/* DISPATCH: EMAIL                                                */
/*----------------------------------------------------------------*/
        /*case CCA_APP_EMAIL:
            //trigger callback or send ILM
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;*/

/*----------------------------------------------------------------*/
/* DISPATCH: SyncML-DS                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
        case CCA_APP_SYNCMLDS:
            if (oper==CCA_OPER_GET)
                mmi_syncml_construct_cca_document_for_dm(app_id, get_prof_ind->prof_id);
            else if (oper==CCA_OPER_UPDATE)
                mmi_syncml_install_cca_document_from_dm(app_id, update_prof_ind->prof_id, update_prof_ind->hConfig);
            break;
#endif  /* __MMI_SYNCML_CCA_SUPPORT__ */

/*----------------------------------------------------------------*/
/* DISPATCH: SyncML-DM                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DM_OTAP__
        case CCA_APP_SYNCMLDM:
            if (oper==CCA_OPER_GET)
                mmi_syncml_dm_send_cca_get_prof_rsp(app_id, get_prof_ind->prof_id);
            else if (oper==CCA_OPER_UPDATE)
                mmi_syncml_dm_send_cca_update_prof_rsp(app_id, update_prof_ind->prof_id, update_prof_ind->hConfig);
            break;
#endif /* __MMI_SYNCML_DM_OTAP__ */

/*----------------------------------------------------------------*/
/* DISPATCH: IMPS                                                 */
/*----------------------------------------------------------------*/
        /*case CCA_APP_IMPS:
            //trigger callback or send ILM
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;*/

/*----------------------------------------------------------------*/
/* DISPATCH: FOTA                                                 */
/*----------------------------------------------------------------*/
        /*case CCA_APP_FOTA:
            //trigger callback or send ILM
            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;*/

        default:
            MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_DISPATCHER_ASYNC_APP_NOT_FOUND);

            if (oper==CCA_OPER_GET)
                mmi_cca_send_cca_app_get_prof_rsp(get_prof_ind->sim_id, app_id, get_prof_ind->prof_id, 0, CCA_STATUS_FAIL);
            else if (oper==CCA_OPER_UPDATE)
                mmi_cca_send_cca_app_update_prof_rsp(update_prof_ind->sim_id, app_id, update_prof_ind->prof_id, update_prof_ind->hConfig, CCA_STATUS_FAIL);
            break;
    }
}

#endif  /* __MMI_CCA_SUPPORT__ */

