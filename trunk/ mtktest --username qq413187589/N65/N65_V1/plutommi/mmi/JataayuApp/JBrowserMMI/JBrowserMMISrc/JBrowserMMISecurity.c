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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGPROFILEREES TO LOOK ONLY TO SUCH
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
 * JBrowserMMISecurity.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Security integration.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_JBROWSERMMISECURITY_C
#define _MMI_JBROWSERMMISECURITY_C

/*  Include: MMI header file */
#include "MMI_features.h"
#if defined WAP_SEC_SUPPORT
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "jdd_ui_resdef.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"
#include "jdi_browserinterface.h"
#include "USBDeviceGprot.h"
#ifdef __CERTMAN_SUPPORT__
#include "certman_api.h"
#include "CertManMMIGprots.h"
#include "pki_api.h"
#endif /* __CERTMAN_SUPPORT__ */ 
#include "jdd_mmiapi.h"
#include "browserlayout.h"
#include "fsm.h"

mmi_brw_certificates_ctxt_struct g_mmi_brw_cert_ctxt;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_switch_callback_hdlr
 * DESCRIPTION
 *  Callback handler for security switching
 * PARAMETERS
 *  apparg_p                    [?]         [?]         [?]
 *  br_fetch_mode               [IN]        
 *  bisappinitiated             [IN]        
 *  cbrewokehandler             [IN]        
 *  cbarg_p                     [?]         [?]         [?]
 *  is_main_page_content        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_security_switch_callback_hdlr(
            void *apparg_p,
            E_BR_FETCH_MODE br_fetch_mode,
            JC_BOOLEAN bisappinitiated,
            CB_BROWSER_REWOKE_SECURITY_HANDLER cbrewokehandler,
            void *cbarg_p,
            JC_BOOLEAN is_main_page_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.cbrewokehandler = cbrewokehandler;
    g_mmi_brw_cert_ctxt.cbarg_p = cbarg_p;
    switch (br_fetch_mode)
    {
        case E_SECURE_MODE:
            if ((g_mmi_brw_cert_ctxt.session_status == BRW_NON_SECURE_SESSION_IN_PROGRESS) &&
                (is_main_page_content == E_FALSE))
            {
                return JC_OK;
            }
            else
            {
                if (g_mmi_brw_cert_ctxt.is_select_user_cert_ind_repeated == BRW_SELECT_USER_CERTIFICATE_IND_REPEATED)
                {
                    g_mmi_brw_cert_ctxt.is_select_user_cert_ind_repeated = BRW_SELECT_USER_CERTIFICATE_IND_NOT_REPEATED;
                    return JC_OK;
                }
            }
            mmi_brw_nonsecure_to_secure_mode_switch();
            break;
        case E_NON_SECURE_MODE:
            if ((g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS) &&
                (is_main_page_content == E_FALSE))
            {
                return JC_OK;
            }
            mmi_brw_secure_to_nonsecure_mode_switch();
            break;
        case E_NON_SECURE_POST:
            if ((g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS) &&
                (is_main_page_content == E_FALSE))
            {
                return JC_OK;
            }
            mmi_brw_post_data_in_nonsecure_mode();
            break;
        default:
            break;
    }
    return JC_ERR_WAIT_USER_ACTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_secure_to_nonsecure_mode_switch
 * DESCRIPTION
 *  Displays confirmation screen for switching from secure mode to non-secure mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_secure_to_nonsecure_mode_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_BRW_CONFIRM_SWITCH_TO_NONSECURE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_brw_allow_switching_to_nonsecure_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_cancel_switching, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_nonsecure_to_secure_mode_switch
 * DESCRIPTION
 *  Displays confirmation screen for switching from nonsecure mode to secure mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_nonsecure_to_secure_mode_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_BRW_CONFIRM_SWITCH_TO_SECURE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_brw_allow_switching_to_secure_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_cancel_switching, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_post_data_in_nonsecure_mode
 * DESCRIPTION
 *  Displays confirmation screen for posting data in nonsecure mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_post_data_in_nonsecure_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_BRW_CONFIRM_POST_DATA_IN_NONSECURE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_brw_allow_post_data_in_nonsecure_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_cancel_switching, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_allow_switching_to_nonsecure_mode
 * DESCRIPTION
 *  Sends E_TRUE as response for security switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_allow_switching_to_nonsecure_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.cbrewokehandler(g_mmi_brw_cert_ctxt.cbarg_p, E_TRUE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_allow_switching_to_secure_mode
 * DESCRIPTION
 *  Sends E_TRUE as response for security switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_allow_switching_to_secure_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cert_ctxt.is_root_certs_added == BRW_CERTIFICATES_ADDED)
    {
        g_mmi_brw_cert_ctxt.cbrewokehandler(g_mmi_brw_cert_ctxt.cbarg_p, E_TRUE);
    }
    else
    {
        g_mmi_brw_cert_ctxt.is_browser_waiting_for_certificates = BRW_WAITING_FOR_CERTIFICATES;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_allow_post_data_in_nonsecure_mode
 * DESCRIPTION
 *  Sends E_TRUE as response for security switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_allow_post_data_in_nonsecure_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.cbrewokehandler(g_mmi_brw_cert_ctxt.cbarg_p, E_TRUE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_cancel_switching
 * DESCRIPTION
 *  Sends E_FALSE as response for security switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_cancel_switching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 navlist_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.cbrewokehandler(g_mmi_brw_cert_ctxt.cbarg_p, E_FALSE);
    jdi_BrowserGetNavListCount(g_mmi_brw_pbrowser_ctxt, &navlist_count);
    if (!navlist_count)
    {
        DeleteScreenIfPresent(SCR_ID_BRW_JBROWSER_MAIN);
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_failure_callback_hdlr
 * DESCRIPTION
 *  Callback handler for failure in establishing secure session
 * PARAMETERS
 *  apparg_p                        [?]         [?]         [?]
 *  commsecurityfailureind_p        [?]         [?]         [?]
 *  is_main_page_content            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_failure_callback_hdlr(
        void *apparg_p,
        COMM_SECURITY_FAILURE_IND *commsecurityfailureind_p,
        JC_BOOLEAN is_main_page_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (commsecurityfailureind_p->eSecurityClass)
    {
        case E_COMM_CLASS_II:
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_BRW_CLASS_TWO_AUTHENTICATION_FAILED),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);
            break;
        case E_COMM_CLASS_III:
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_BRW_CLASS_THREE_AUTHENTICATION_FAILED),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);
            break;
        default:
            break;
    }
    SetLeftSoftkeyFunction(mmi_brw_continue_secure_authentication, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_cancel_secure_authentication, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_continue_secure_authentication
 * DESCRIPTION
 *  Sends E_TRUE as response for continuing authentication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_continue_secure_authentication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserSendSecurityFailureResponse(g_mmi_brw_pbrowser_ctxt, E_TRUE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_cancel_secure_authentication
 * DESCRIPTION
 *  Sends E_FALSE as response for cancelling authentication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_cancel_secure_authentication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserSendSecurityFailureResponse(g_mmi_brw_pbrowser_ctxt, E_FALSE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_indication_callback_hdlr
 * DESCRIPTION
 *  Callback handler for indication of successful secure session establishment
 * PARAMETERS
 *  apparg_p                    [?]         [?]         [?]
 *  commsecurityind_p           [?]         [?]         [?]
 *  is_main_page_content        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_indication_callback_hdlr(
        void *apparg_p,
        COMM_SECURITY_IND *commsecurityind_p,
        JC_BOOLEAN is_main_page_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR module_name[(MMI_BRW_MAX_MODULE_NAME_LENGTH + 1) * ENCODING_LENGTH];
    BOOL disable_install;
    kal_uint32 certificate_warning = 0;
    JC_RETCODE ret;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
    g_mmi_brw_cert_ctxt.server_cert_buf_size = commsecurityind_p->uiLength;
    if (g_mmi_brw_cert_ctxt.server_cert_buf != NULL)
    {
        jdd_MemFree(g_mmi_brw_cert_ctxt.server_cert_buf);
        g_mmi_brw_cert_ctxt.server_cert_buf = NULL;
    }
    g_mmi_brw_cert_ctxt.server_cert_buf = jdd_MemAlloc(commsecurityind_p->uiLength, 1);
    if (g_mmi_brw_cert_ctxt.server_cert_buf == NULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_FILE_SYSTEM_FULL),
            IMG_GLOBAL_ERROR,
            0,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        jdi_BrowserSendSecurityResponse(g_mmi_brw_pbrowser_ctxt, E_FALSE);
    }
    memcpy(g_mmi_brw_cert_ctxt.server_cert_buf, commsecurityind_p->pucBuffer, commsecurityind_p->uiLength);
    if (mmi_brw_compare_certificates(g_mmi_brw_cert_ctxt.server_cert_buf, g_mmi_brw_cert_ctxt.server_cert_buf_size) ==
        E_TRUE)
    {
        goto continue_fetch;
    }
    else
    {
        if (commsecurityind_p->uiCertWarning != E_SSL_CERT_WARN_NONE)
        {
            certificate_warning = mmi_brw_map_ssl_warning_to_certman(commsecurityind_p->uiCertWarning);
        }
        if (mmi_brw_compare_certificate_url(commsecurityind_p->psUrl) == E_FALSE)
        {
            certificate_warning |= MMI_CERTMAN_WARN_URLS_DONT_MATCH;
            disable_install = E_TRUE;
            goto send_indication;
        }
        else
        {
            if (certificate_warning != MMI_CERTMAN_CERT_WARN_NONE)
            {
                if (mmi_brw_search_url_in_the_list((JC_CHAR*) g_mmi_brw_cert_ctxt.certificate_url) == E_TRUE)
                {
                    goto continue_fetch;
                }
                else
                {
                    disable_install = E_FALSE;
                    goto send_indication;
                }
            }
            else
            {
                goto continue_fetch;
            }
        }
    }
  continue_fetch:
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (g_mmi_brw_cert_ctxt.session_status == BRW_NON_SECURE_SESSION_IN_PROGRESS)
    {
        g_mmi_brw_cert_ctxt.session_status = BRW_SECURE_SESSION_IN_PROGRESS;
        jdd_MMIDisplaySecurityIndication();
    }
    jdi_BrowserSendSecurityResponse(g_mmi_brw_pbrowser_ctxt, E_TRUE);
    return;

  send_indication:
    ret = mmi_brw_create_file(
            MMI_BRW_SERVER_CERTIFICATE_FILE,
            commsecurityind_p->pucBuffer,
            commsecurityind_p->uiLength);
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (ret != JC_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_ERROR_CREATING_FILE),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        mmi_brw_stop_fetch();
        return;
    }
    kal_wsprintf(module_name, "%s", "Browser");
    mmi_certman_invalid_certificates_ind(
        MOD_WAP,
        MMI_CERTMAN_OPEN,
        disable_install,
        certificate_warning,
        module_name,
        MMI_BRW_SERVER_CERTIFICATE_FILE,
        1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_nonsecure_mode_indication_callback_hdlr
 * DESCRIPTION
 *  Callback handler for indication of nonsecure mode
 * PARAMETERS
 *  apparg_p                    [?]         [?]         [?]
 *  is_main_page_content        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_nonsecure_mode_indication_callback_hdlr(void *apparg_p, JC_BOOLEAN is_main_page_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.session_status = BRW_NON_SECURE_SESSION_IN_PROGRESS;
    jdd_MMIHideSecurityIndication();
    if (g_mmi_brw_cert_ctxt.server_cert_buf != NULL)
    {
        jdd_MemFree(g_mmi_brw_cert_ctxt.server_cert_buf);
        g_mmi_brw_cert_ctxt.server_cert_buf = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_user_certificate_indication_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  apparg_p                    [?]         [?]         [?]
 *  user_cert_req_details       [?]         [?]         [?]
 *  is_main_page_content        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_user_certificate_indication_callback_hdlr(
        void *apparg_p,
        COMM_USER_CERT_REQ_IND *user_cert_req_details,
        JC_BOOLEAN is_main_page_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_main_page_content == E_TRUE)
    {
        mmi_ucs2cpy(
            (S8*) g_mmi_brw_cert_ctxt.user_cert_req_details.issuers_names_file,
            (S8*) user_cert_req_details->authNamesFile);
        memcpy(
            g_mmi_brw_cert_ctxt.user_cert_req_details.cert_types,
            user_cert_req_details->certTypes,
            sizeof(user_cert_req_details->certTypes));
        g_mmi_brw_cert_ctxt.user_cert_req_details.cert_type_count = user_cert_req_details->certTypeCount;
        mmi_brw_entry_select_user_certificate();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_init_security_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_init_security_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.is_root_certs_added = BRW_CERTIFICATES_NOT_ADDED;
    g_mmi_brw_cert_ctxt.is_browser_waiting_for_certificates = BRW_NOT_WAITING_FOR_CERTIFICATES;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_init_wap_security
 * DESCRIPTION
 *  Initializes the wap security feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_init_wap_security(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cert_ctxt.session_status = BRW_NON_SECURE_SESSION_IN_PROGRESS;
    g_mmi_brw_cert_ctxt.trans_id = 0;
    g_mmi_brw_cert_ctxt.is_user_certs_added = BRW_CERTIFICATES_NOT_ADDED;
    g_mmi_brw_cert_ctxt.is_select_user_cert_ind_repeated = BRW_SELECT_USER_CERTIFICATE_IND_NOT_REPEATED;
    if (g_mmi_brw_cert_ctxt.is_root_certs_added == BRW_CERTIFICATES_NOT_ADDED)
    {
        certman_send_ready_subscribe_req(MOD_WAP);
    }
    else
    {
        ST_BROWSER_ROOT_CERT root_cert;

        mmi_ucs2cpy((S8*) root_cert.psz_cert_foldername, (S8*) CERTMAN_SHARED_CERTS_PATH);
        jdi_BrowserAddRootCertificate(g_mmi_brw_pbrowser_ctxt, &root_cert);
    }
    mmi_brw_create_folder(MMI_BRW_USER_CERTIFICATES_FOLDER);
    g_mmi_brw_cert_ctxt.secure_urls_list = NULL;
    g_mmi_brw_cert_ctxt.server_cert_buf = NULL;
    memset(g_mmi_brw_cert_ctxt.certificate_url, 0, ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_wap_security
 * DESCRIPTION
 *  De-initializes the wap security feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_wap_security(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_delete_folder(MMI_BRW_USER_CERTIFICATES_FOLDER);
    if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
    {
        mmi_brw_deinit_wap_secure_mode();
    }
    fsmResetSessionToNonsecure(g_mmi_brw_pbrowser_ctxt);
    if (g_mmi_brw_cert_ctxt.user_cert != NULL)
    {
        jdd_MemFree(g_mmi_brw_cert_ctxt.user_cert);
        g_mmi_brw_cert_ctxt.user_cert = NULL;
    }
    if (g_mmi_brw_cert_ctxt.user_cert_details != NULL)
    {
        jdd_MemFree(g_mmi_brw_cert_ctxt.user_cert_details);
        g_mmi_brw_cert_ctxt.user_cert_details = NULL;
    }
    if (g_mmi_brw_cert_ctxt.server_cert_buf != NULL)
    {
        jdd_MemFree(g_mmi_brw_cert_ctxt.server_cert_buf);
        g_mmi_brw_cert_ctxt.server_cert_buf = NULL;
    }
    if (g_mmi_brw_cert_ctxt.secure_urls_list != NULL)
    {
        mmi_brw_free_urls_list();
        g_mmi_brw_cert_ctxt.secure_urls_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_wap_secure_mode
 * DESCRIPTION
 *  De-initializes the wap security feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_wap_secure_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cert_ctxt.is_root_certs_added == BRW_CERTIFICATES_ADDED)
    {
        jdi_BrowserClearRootCertificate(g_mmi_brw_pbrowser_ctxt);
    }
    if (g_mmi_brw_cert_ctxt.is_user_certs_added == BRW_CERTIFICATES_ADDED)
    {
        jdi_BrowserClearUserCertificate(g_mmi_brw_pbrowser_ctxt);
    }
    jdd_MMIHideSecurityIndication();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_certman_ready_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_certman_ready_cnf(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ST_BROWSER_ROOT_CERT root_cert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) root_cert.psz_cert_foldername, (S8*) CERTMAN_SHARED_CERTS_PATH);
    jdi_BrowserAddRootCertificate(g_mmi_brw_pbrowser_ctxt, &root_cert);
    g_mmi_brw_cert_ctxt.is_root_certs_added = BRW_CERTIFICATES_ADDED;
    if (g_mmi_brw_cert_ctxt.is_browser_waiting_for_certificates == BRW_WAITING_FOR_CERTIFICATES)
    {
        g_mmi_brw_cert_ctxt.cbrewokehandler(g_mmi_brw_cert_ctxt.cbarg_p, E_TRUE);
        g_mmi_brw_cert_ctxt.is_browser_waiting_for_certificates = BRW_NOT_WAITING_FOR_CERTIFICATES;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_get_certificate_details_cnf
 * DESCRIPTION
 *  Sends request to certman for getting a particular certificate
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_get_certificate_details_cnf(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_get_cert_by_id_cnf_struct *cert_details_p;

    g_mmi_brw_cert_ctxt.user_cert = jdd_MemAlloc((sizeof(ST_BROWSER_USER_CERT)), 1);
    if (g_mmi_brw_cert_ctxt.user_cert == NULL)
    {
        ASSERT(0);
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cert_details_p = (certman_get_cert_by_id_cnf_struct*) data_buf;
    if (g_mmi_brw_cert_ctxt.user_cert_details != NULL)
    {
        if ((cert_details_p->trans_id == g_mmi_brw_cert_ctxt.user_cert_details->user_cert_trans_id) &&
            (cert_details_p->cert_id == g_mmi_brw_cert_ctxt.user_cert_details->user_cert_id))
        {
            if (cert_details_p->status == CERTMAN_ERR_NONE)
            {
                mmi_ucs2cpy((S8*) g_mmi_brw_cert_ctxt.user_cert->psz_cert_filename, (S8*) cert_details_p->filename);
                g_mmi_brw_cert_ctxt.user_cert->ecert_file_type = E_SSL_PEM;
            #ifdef __CERTMAN_SUPPORT__
                certman_send_get_privkey_req(
                    MOD_WAP,
                    ++g_mmi_brw_cert_ctxt.trans_id,
                    cert_details_p->cert_id,
                    mmi_brw_password_fb_callback_hdlr,
                    CERTMAN_ENC_PEM,
                    MMI_BRW_USER_CERTIFICATES_FOLDER);
            #endif /* __CERTMAN_SUPPORT__ */ 
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Error in mmi_brw_handle_get_certificate_details_cnf!");
                ASSERT(0);
            }
            jdd_MemFree(g_mmi_brw_cert_ctxt.user_cert_details);
            g_mmi_brw_cert_ctxt.user_cert_details = NULL;
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                 "Response for details of user certificate does not match with the present database!");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_view_server_certificate_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_view_server_certificate_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_view_certificate_indication, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_view_certificate_indication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_view_certificate_indication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_brw_create_file(
            MMI_BRW_SERVER_CERTIFICATE_FILE,
            g_mmi_brw_cert_ctxt.server_cert_buf,
            g_mmi_brw_cert_ctxt.server_cert_buf_size);
    if (ret != JC_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_ERROR_CREATING_FILE),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
    }
    else
    {
        mmi_certman_view_certificates_ind(MOD_WAP, MMI_CERTMAN_OPEN, MMI_BRW_SERVER_CERTIFICATE_FILE, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_invalid_cert_resp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_invalid_cert_resp(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_rsp_struct *invalid_cert_resp = (mmi_certman_invalid_cert_rsp_struct*) data_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (invalid_cert_resp->invalid_cert_action)
    {
        case MMI_CERTMAN_INVALID_CERT_INSTALL:
        case MMI_CERTMAN_INVALID_CERT_ACCEPT:
            if (g_mmi_brw_cert_ctxt.session_status == BRW_NON_SECURE_SESSION_IN_PROGRESS)
            {
                g_mmi_brw_cert_ctxt.session_status = BRW_SECURE_SESSION_IN_PROGRESS;
                jdd_MMIDisplaySecurityIndication();
            }
            mmi_brw_add_url_to_list((JC_CHAR*) g_mmi_brw_cert_ctxt.certificate_url);
            jdi_BrowserSendSecurityResponse(g_mmi_brw_pbrowser_ctxt, E_TRUE);
            break;
        case MMI_CERTMAN_INVALID_CERT_DENY:
            mmi_brw_stop_fetch();
            jdi_BrowserSendSecurityResponse(g_mmi_brw_pbrowser_ctxt, E_FALSE);
            break;
        default:
            break;
    }
    mmi_brw_delete_file(MMI_BRW_SERVER_CERTIFICATE_FILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_select_user_certificate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_select_user_certificate_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR module_name[(MMI_BRW_MAX_MODULE_NAME_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(module_name, "%s", "Browser");
    mmi_certman_select_user_certificates_ind(
        MOD_WAP,
        MMI_CERTMAN_OPEN,
        CERTMAN_KP_CLIENT_AUTH,
        g_mmi_brw_cert_ctxt.user_cert_req_details.cert_type_count,
        (kal_uint8*) g_mmi_brw_cert_ctxt.user_cert_req_details.cert_types,
        module_name,
        g_mmi_brw_cert_ctxt.user_cert_req_details.issuers_names_file,
        1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_select_user_cert_resp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_select_user_cert_resp(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_rsp_struct *user_cert_resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_cert_resp = (mmi_certman_select_user_cert_rsp_struct*) data_buf;
    if (g_mmi_brw_cert_ctxt.user_cert_details == NULL)
    {
        if (user_cert_resp->personal_cert_id == 0)
        {
            mmi_brw_pre_entry_goto_url();
            DeleteScreenIfPresent(SCR_ID_BRW_SELECT_USER_CERTIFICATE);
            g_mmi_brw_cert_ctxt.is_select_user_cert_ind_repeated = BRW_SELECT_USER_CERTIFICATE_IND_REPEATED;
        }
        else
        {
        #ifdef __CERTMAN_SUPPORT__
            certman_send_get_cert_by_id_req(
                MOD_WAP,
                ++g_mmi_brw_cert_ctxt.trans_id,
                user_cert_resp->personal_cert_id,
                CERTMAN_ENC_PEM,
                CERTMAN_KP_CLIENT_AUTH,
                MMI_BRW_USER_CERTIFICATES_FOLDER);
        #endif /* __CERTMAN_SUPPORT__ */ 
            g_mmi_brw_cert_ctxt.user_cert_details = jdd_MemAlloc(sizeof(mmi_brw_user_cert_details_struct), 1);
            if (g_mmi_brw_cert_ctxt.user_cert_details == NULL)
            {
                ASSERT(0);
            }
            g_mmi_brw_cert_ctxt.user_cert_details->user_cert_trans_id = g_mmi_brw_cert_ctxt.trans_id;
            g_mmi_brw_cert_ctxt.user_cert_details->user_cert_id = user_cert_resp->personal_cert_id;
        }
    }
    else
    {
        /* condition yet to be handled */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_handle_view_cert_resp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_handle_view_cert_resp(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_delete_file(MMI_BRW_SERVER_CERTIFICATE_FILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_private_key_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_buf        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_get_private_key_cnf(void *data_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_get_privkey_cnf_struct *priv_key_info = (certman_get_privkey_cnf_struct*) data_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) g_mmi_brw_cert_ctxt.user_cert->psz_key_filename, (S8*) priv_key_info->filename);
    g_mmi_brw_cert_ctxt.user_cert->ekey_file_type = CERTMAN_ENC_PEM;
    jdi_BrowserAddUserCertificate(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cert_ctxt.user_cert);
    g_mmi_brw_cert_ctxt.is_user_certs_added = BRW_CERTIFICATES_ADDED;
    jdd_MemFree(g_mmi_brw_cert_ctxt.user_cert);
    g_mmi_brw_cert_ctxt.user_cert = NULL;
    mmi_brw_pre_entry_goto_url();
    DeleteScreenIfPresent(SCR_ID_BRW_SELECT_USER_CERTIFICATE);
    g_mmi_brw_cert_ctxt.is_select_user_cert_ind_repeated = BRW_SELECT_USER_CERTIFICATE_IND_REPEATED;
}

#ifdef CURRENTLY_NOT_SUPPORTED


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_certman_update_action_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action          [IN]        
 *  buffer_p        [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_certman_update_action_ind(mmi_certman_update_action_enum action, void *buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case MMI_CERTMAN_UPDATE_ACTION_ADD:
        {
            mmi_certman_add_certificate_struct *cert_add_details = (mmi_certman_add_certificate_struct*) buffer_p;

            if (cert_add_details->cert_group != CERTMAN_CERTGRP_PERSONAL)
            {
                certman_send_get_cert_by_id_req(
                    MOD_WAP,
                    ++g_mmi_brw_cert_ctxt.trans_id,
                    cert_add_details->cert_id,
                    CERTMAN_ENC_PEM,
                    CERTMAN_KP_SERVER_AUTH,
                    g_mmi_brw_cert_ctxt.root_cert_path_buf);
            }
            break;
        }
        case MMI_CERTMAN_UPDATE_ACTION_DELETE:
        case MMI_CERTMAN_UPDATE_ACTION _DELETE_ALL:
        case MMI_CERTMAN_UPDATE_ACTION_MODIFY:
        default:
            break;
    }
}
#endif /* CURRENTLY_NOT_SUPPORTED */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_password_fb_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  trans_id        [IN]        
 *  cert_id         [IN]        
 *  pwd             [IN]        
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_password_fb_callback_hdlr(kal_uint32 trans_id, kal_uint32 cert_id, const kal_uint8 *pwd, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_mmi_brw_cert_ctxt.user_cert->psz_password, pwd, size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_name     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_brw_create_folder(JC_CHAR *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FSHANDLE filesyshandle = NULL;
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdd_FSInitialize(&filesyshandle);
    if (ret == JC_OK)
    {
        ret = jdd_FSMakeDir(filesyshandle, folder_name);
        if (ret == JC_ERR_FILE_FULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_FILE_SYSTEM_FULL),
                IMG_GLOBAL_ERROR,
                0,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);

            ASSERT(jdd_FSDeinitialize(filesyshandle) == JC_OK);
            return ret;
        }
        else
        {
            jdd_FSDeinitialize(filesyshandle);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
            IMG_GLOBAL_ERROR,
            0,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_name     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_folder(JC_CHAR *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FSHANDLE filesyshandle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jdd_FSInitialize(&filesyshandle) == JC_OK)
    {
        if (jdd_FSIsDirExist(filesyshandle, folder_name) == E_TRUE)
        {
            jdd_FSDelDir(filesyshandle, folder_name);
            jdd_FSDeinitialize(filesyshandle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]         [?]         [?]
 *  data_buffer     [?]         [?]         [?]
 *  data_length     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_create_file(JC_CHAR *file_name, JC_UINT8 *data_buffer, JC_UINT32 data_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_ERR_FILE_SYS_INIT;
    JDD_FSHANDLE fs_sys_handle = NULL;
    JDD_FILE fhandle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdd_FSInitialize(&fs_sys_handle);
    if (ret == JC_OK)
    {
        fhandle = jdd_FSOpen(fs_sys_handle, file_name, E_CREATE_APPEND_WRITE_MODE);
        if (fhandle != NULL)
        {
            if (data_length > 0)
            {
                JC_INT32 fsret = jdd_FSWrite((void*)data_buffer, 1, data_length, fhandle);

                if (fsret != data_length)
                {
                    ret = fsret;
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Error writing data in file");
                }
            }
            jdd_FSClose(fhandle);
            jdd_FSDeinitialize(fs_sys_handle);
            return ret;
        }
        ret = JC_ERR_FILE_OPEN;
        jdd_FSDeinitialize(fs_sys_handle);
        return ret;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_delete_file(JC_CHAR *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_ERR_FILE_SYS_INIT;
    JDD_FSHANDLE fs_sys_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdd_FSInitialize(&fs_sys_handle);
    if (ret == JC_OK)
    {
        ret = jdd_FSDelete(fs_sys_handle, file_name);
        jdd_FSDeinitialize(fs_sys_handle);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_select_user_certificate
 * DESCRIPTION
 *  Displays screen to promt user to select a user certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_select_user_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SELECT_USER_CERTIFICATE, NULL, mmi_brw_entry_select_user_certificate, NULL);
    ShowCategory2Screen(
        STR_ID_BRW_CHOOSE_CERTIFICATE,
        0,
        STR_ID_BRW_LIST_USER_CERTIFICATES,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_OPTIONS,
        STR_ID_BRW_SELECT_USER_CERTIFICATE,
        NULL);

    SetLeftSoftkeyFunction(mmi_brw_send_select_user_certificate_ind, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_stop_fetch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_compare_certificate_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url                         [?]         
 *  server_cert_buf_size(?)     [IN]        
 *  server_cert_buf             [?]         [?](?)
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_compare_certificate_url(JC_CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR url_prefix[6 * ENCODING_LENGTH];
    JC_CHAR *invalid_cert_url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(url_prefix, "%s", "https");
    if (mmi_ucs2ncmp((S8*) url, (S8*) url_prefix, strlen("https")) == 0)
    {
        invalid_cert_url = (JC_CHAR*) (((JC_UINT32) url) + (strlen("https://") * ENCODING_LENGTH));
    }
    else
    {
        invalid_cert_url = (JC_CHAR*) (((JC_UINT32) url) + (strlen("http://") * ENCODING_LENGTH));
    }
    if (mmi_ucs2ncmp
        ((S8*) g_mmi_brw_cert_ctxt.certificate_url, (S8*) invalid_cert_url,
         mmi_ucs2strlen((S8*) g_mmi_brw_cert_ctxt.certificate_url)) != 0)
    {
        return E_FALSE;
    }
    else
    {
        return E_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_malloc_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_brw_malloc_cb(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdd_MemAlloc(size, sizeof(JC_INT8));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_mfree_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memblock        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_mfree_cb(void *memblock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemFree(memblock);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_compare_certificates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  server_cert_buf             [?]         
 *  server_cert_buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_compare_certificates(JC_UINT8 *server_cert_buf, JC_UINT32 server_cert_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pki_context_struct *pki_ctx;
    pki_x509_struct *px509;
    pki_name_struct *p_name;
    pki_error_enum ret;
    U8 temp_certificate_url[MMI_BRW_BKM_MAX_URL_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pki_ctx = pki_context_new(mmi_brw_malloc_cb, mmi_brw_mfree_cb);
    if (NULL == pki_ctx)
    {
        pki_context_release(&pki_ctx);
        return JC_ERR_MEMORY_ALLOCATION;
    }

    ret = pki_x509_new(pki_ctx, PKI_DATA_USE, server_cert_buf, (kal_uint32) server_cert_buf_size, &px509);
    if (PKI_ERR_NONE != ret)
    {
        goto error;
    }
    ret = pki_x509_get_subject(px509, &p_name);
    if (PKI_ERR_NONE != ret)
    {
        goto error;
    }
    pki_name_parse(p_name);
    if (p_name->dcs[PKI_NAMETYPE_COMMON_NAME] == CERTMAN_DCS_ASCII)
    {
        mmi_asc_to_ucs2((S8*) temp_certificate_url, (S8*) p_name->names[PKI_NAMETYPE_COMMON_NAME]);
    }
    else
    {
        mmi_ucs2cpy((S8*) temp_certificate_url, (S8*) p_name->names[PKI_NAMETYPE_COMMON_NAME]);
    }
    if (mmi_ucs2strlen((S8*) g_mmi_brw_cert_ctxt.certificate_url) != 0)
    {
        if (mmi_ucs2cmp((S8*) temp_certificate_url, (S8*) g_mmi_brw_cert_ctxt.certificate_url) != 0)
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cert_ctxt.certificate_url, (S8*) temp_certificate_url);
            pki_name_release(&p_name);
            pki_x509_release(&px509);
            pki_context_release(&pki_ctx);
            return E_FALSE;
        }
        else
        {
            pki_name_release(&p_name);
            pki_x509_release(&px509);
            pki_context_release(&pki_ctx);
            return E_TRUE;
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) g_mmi_brw_cert_ctxt.certificate_url, (S8*) temp_certificate_url);
    }
  error:
    pki_name_release(&p_name);
    pki_x509_release(&px509);
    pki_context_release(&pki_ctx);
    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_add_url_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_add_url_to_list(JC_CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    mmi_brw_secure_urls_list_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cert_ctxt.secure_urls_list != NULL)
    {
        ret = mmi_brw_search_url_in_the_list(url);
        if (ret == E_FALSE)
        {
            temp = (mmi_brw_secure_urls_list_struct*) jdd_MemAlloc(sizeof(mmi_brw_secure_urls_list_struct), 1);
            if (temp == NULL)
            {
                ASSERT(0);
            }
            mmi_ucs2cpy((S8*) temp->url, (S8*) url);
            temp->next_url = g_mmi_brw_cert_ctxt.secure_urls_list;
            g_mmi_brw_cert_ctxt.secure_urls_list = temp;
        }
    }
    else
    {
        g_mmi_brw_cert_ctxt.secure_urls_list =
            (mmi_brw_secure_urls_list_struct*) jdd_MemAlloc(sizeof(mmi_brw_secure_urls_list_struct), 1);
        if (g_mmi_brw_cert_ctxt.secure_urls_list == NULL)
        {
            ASSERT(0);
        }
        mmi_ucs2cpy((S8*) g_mmi_brw_cert_ctxt.secure_urls_list->url, (S8*) url);
        g_mmi_brw_cert_ctxt.secure_urls_list->next_url = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_search_url_in_the_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_brw_search_url_in_the_list(JC_CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_secure_urls_list_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = g_mmi_brw_cert_ctxt.secure_urls_list;
    while (temp != NULL)
    {
        if (mmi_ucs2cmp((S8*) temp->url, (S8*) url) == 0)
        {
            return E_TRUE;
        }
        temp = temp->next_url;
    }
    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_free_urls_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_free_urls_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_secure_urls_list_struct *temp, *temp1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = g_mmi_brw_cert_ctxt.secure_urls_list;
    while (temp != NULL)
    {
        temp1 = temp;
        temp = temp->next_url;
        jdd_MemFree(temp1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_map_ssl_warning_to_certman
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ssl_warning     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mmi_brw_map_ssl_warning_to_certman(JC_UINT32 ssl_warning)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 certman_warning = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ssl_warning & E_SSL_CERT_WARN_CHAIN)
    {
        certman_warning |= MMI_CERTMAN_WARN_CHAIN;
    }
    if (ssl_warning & E_SSL_CERT_WARN_BCONST_NOT_CRITICAL)
    {
        certman_warning |= MMI_CERTMAN_WARN_BCONST_NOT_CRITICAL;
    }
    if (ssl_warning & E_SSL_CERT_WARN_UNKNOWN_CRITICAL_EXT)
    {
        certman_warning |= MMI_CERTMAN_WARN_UNKNOWN_CRITICAL_EXT;
    }
    if (ssl_warning & E_SSL_CERT_WARN_VALIDITY)
    {
        certman_warning |= MMI_CERTMAN_WARN_VALIDITY;
    }
    if (ssl_warning & E_SSL_CERT_WARN_NO_KEY_USAGE)
    {
        certman_warning |= MMI_CERTMAN_WARN_NO_KEY_USAGE;
    }
    if (ssl_warning & E_SSL_CERT_WARN_KEY_MISUSE)
    {
        certman_warning |= MMI_CERTMAN_WARN_KEY_MISUSE;
    }
    if (ssl_warning & E_SSL_CERT_WARN_BCONST_FAIL)
    {
        certman_warning |= MMI_CERTMAN_WARN_BCONST_FAIL;
    }
    if (ssl_warning & E_SSL_CERT_WARN_NO_TRUSTED_CERTS)
    {
        certman_warning |= MMI_CERTMAN_WARN_NO_TRUSTED_CERTS;
    }
    if (ssl_warning & E_SSL_CERT_WARN_INVALID_SIGNATURE)
    {
        certman_warning |= MMI_CERTMAN_WARN_INVALID_SIGNATURE;
    }
    if (ssl_warning & E_SSL_CERT_WARN_INTERNAL)
    {
        certman_warning |= MMI_CERTMAN_WARN_INTERNAL;
    }
    if (ssl_warning & E_SSL_CERT_WARN_TRUSTED_KEY_MISUSE)
    {
        certman_warning |= MMI_CERTMAN_WARN_TRUSTED_KEY_MISUSE;
    }
    if (ssl_warning & E_SSL_CERT_WARN_TRUSTED_EXPIRED)
    {
        certman_warning |= MMI_CERTMAN_WARN_TRUSTED_EXPIRED;
    }
    if (ssl_warning & E_SSL_CERT_WARN_CORRUPTED_CERT)
    {
        certman_warning |= MMI_CERTMAN_WARN_CORRUPTED_CERT;
    }
    if (ssl_warning & E_SSL_CERT_WARN_TRUSTED_NO_KEY_USAGE)
    {
        certman_warning |= MMI_CERTMAN_WARN_TRUSTED_NO_KEY_USAGE;
    }
    if (ssl_warning & E_SSL_CERT_WARN_NO_CERT_HASH)
    {
        certman_warning |= MMI_CERTMAN_WARN_NO_CERT_HASH;
    }
    return certman_warning;
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* defined WAP_SEC_SUPPORT */ 

#endif /* _MMI_JBROWSERMMISECURITY_C */ 

