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
 * JProvisioning.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _JPROVISIONING_C
#define _JPROVISIONING_C

#include "ddl.h"
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))


#include "JProvisioning.h"
#include "custom_nvram_editor_data_item.h"
#include "JProfileHandlerResDef.h"
#include "JProfileHandlerProts.h"
#include "Conversions.h"
#ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__
#include "JBrowserResDef.h"
#include "JBrowserMMIGprots.h"
#include "cbfunc.h"
#endif /* __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */ 
prov_context_struct g_prov_cntx;

const U16 prov_brw_cca_mapping_table[] = {CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, PROV_BRW_NODE_PROXY, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, PROV_BRW_NODE_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, PROV_BRW_NODE_PXAUTHINFO, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, PROV_BRW_NODE_APP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_RESOURCE, PROV_BRW_NODE_RESOURCE, 0xFFFF,
};

const U16 prov_mms_cca_mapping_table[] = {CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, PROV_MMS_NODE_PROXY, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, PROV_MMS_NODE_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, PROV_MMS_NODE_PXAUTHINFO, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, PROV_MMS_NODE_APP, 0xFFFF
};

#ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_init
 * DESCRIPTION
 *  Initializes app check function for dm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_dm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_set_check_function(DM_SETTING_TYPE_WAP, mmi_prov_cca_dm_check_func);
    mmi_dm_set_check_function(DM_SETTING_TYPE_MMS, mmi_prov_cca_dm_check_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_check_func
 * DESCRIPTION
 *  Check whether DM can update the profile or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
bf_bool mmi_prov_cca_dm_check_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_PROF_HDLR_SHOW_SETTING_INFO) || GetActiveScreenId() == SCR_ID_PROF_HDLR_SHOW_SETTING_INFO
        || IsScreenPresent(mmi_brw_jbrowser_wap_screen_id()) || GetActiveScreenId() == mmi_brw_jbrowser_wap_screen_id()
        || IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN) || GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_check_set_prof_id
 * DESCRIPTION
 *  Check valid profile id for update profile operation
 * PARAMETERS
 *  prof_id         [IN]        
 *  max_prof_id     [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_prov_cca_dm_check_set_prof_id(S32 prof_id, S32 max_prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE retcode = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_check_set_prof_id");
    if ((prof_id >= 0 && prof_id <= (max_prof_id - 1)) || (prof_id == CCA_PROF_CURRENT))
    {
        retcode = PROV_OK;
    }
    else
    {
        ASSERT(0);
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_check_get_prof_id
 * DESCRIPTION
 *  Check valid profile id for get profile operation
 * PARAMETERS
 *  prof_id         [IN]        
 *  max_prof_id     [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_cca_dm_check_get_prof_id(S32 prof_id, S32 max_prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_check_get_prof_id");
    if ((prof_id >= 0 && prof_id <= (max_prof_id - 1)) || (prof_id == CCA_PROF_CURRENT))
    {
        return prof_id;
    }

    return PROV_DEFAULT_PROF_ID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_update_brw_profile
 * DESCRIPTION
 *  Update browser profile
 * PARAMETERS
 *  doc_config_h        [IN]        
 *  prof_id             [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_cca_dm_update_brw_profile(S32 doc_config_h, S32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum retcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_update_brw_profile");
    retcode = mmi_cca_doc_process(
                doc_config_h,
                prov_brw_cca_mapping_table,
                sizeof(prov_brw_cca_mapping_table) / sizeof(U16),
                0,
                mmi_prov_brw_nodes_process_callback,
                0);
    if (retcode == CCA_STATUS_OK)
    {
        g_prov_cntx.prov_type = PROV_BRS_SETTINGS;
        retcode = mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();
        if (retcode == CCA_STATUS_OK)
        {
            ASSERT(g_prov_cntx.wap_profile_list);
            mmi_ph_set_brw_profile_data(g_prov_cntx.wap_profile_list, prof_id);
        }

    }
    mmi_prov_free_mem();
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_update_mms_profile
 * DESCRIPTION
 *  Update mms profile
 * PARAMETERS
 *  doc_config_h        [IN]        
 *  prof_id             [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_cca_dm_update_mms_profile(S32 doc_config_h, S32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum retcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_update_mms_profile");
    retcode = mmi_cca_doc_process(
                doc_config_h,
                prov_mms_cca_mapping_table,
                sizeof(prov_mms_cca_mapping_table) / sizeof(U16),
                0,
                mmi_prov_mms_nodes_process_callback,
                0);
    if (retcode == CCA_STATUS_OK)
    {
        g_prov_cntx.prov_type = PROV_MMS_SETTINGS;
        retcode = mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();
        if (retcode == CCA_STATUS_OK)
        {
            ASSERT(g_prov_cntx.mms_profile_list);
            mmi_ph_set_mms_profile_data(g_prov_cntx.mms_profile_list, prof_id);
        }
    }
    mmi_prov_free_mem();
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_update_prof_ind
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_dm_update_prof_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_ind_struct *data;

    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_update_prof_ind");
    memset(&g_prov_cntx, 0, sizeof(g_prov_cntx));

    data = (mmi_cca_app_update_prof_ind_struct*) msg;

    if (data->app_id == CCA_APP_BROWSER)
    {
        mmi_prov_cca_dm_check_set_prof_id(data->prof_id, NVRAM_WAP_PROFILE_MAX);
        retcode = mmi_prov_cca_dm_update_brw_profile(data->hConfig, data->prof_id);
    }
    else if (data->app_id == CCA_APP_MMS)
    {
        mmi_prov_cca_dm_check_set_prof_id(data->prof_id, NVRAM_MMS_PROFILE_MAX);
        retcode = mmi_prov_cca_dm_update_mms_profile(data->hConfig, data->prof_id);
    }
    else
    {
        //mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
        //return;
        ASSERT(0);
    }

    mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, retcode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_get_prof_ind
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_APP_GET_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_dm_get_prof_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct *data;
    cca_state_enum status = CCA_STATUS_OK;
    S32 hconfig = -1;
    S32 prof_id = PROV_DEFAULT_PROF_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_get_prof_ind");
    data = (mmi_cca_app_get_prof_ind_struct*) msg;

    if (data->app_id == CCA_APP_BROWSER)
    {
        if (mmi_prov_alloc_wap_profile_node() == CCA_STATUS_MEMFULL)
        {
            status = CCA_STATUS_MEMFULL;
            goto error;
        }
        prof_id = mmi_prov_cca_dm_check_get_prof_id(data->prof_id, NVRAM_WAP_PROFILE_MAX);
        mmi_ph_get_brw_profile_data(g_prov_cntx.wap_profile_list, prof_id);
        hconfig = mmi_prov_cca_dm_construct_brw_doc(g_prov_cntx.wap_profile_list);
    }
    else if (data->app_id == CCA_APP_MMS)
    {

        if (mmi_prov_alloc_mms_profile_node() == CCA_STATUS_MEMFULL)
        {
            status = CCA_STATUS_MEMFULL;
            goto error;
        }
        prof_id = mmi_prov_cca_dm_check_get_prof_id(data->prof_id, NVRAM_MMS_PROFILE_MAX);
        mmi_ph_get_mms_profile_data(g_prov_cntx.mms_profile_list, prof_id);
        hconfig = mmi_prov_cca_dm_construct_mms_doc(g_prov_cntx.mms_profile_list);
    }
    else
    {
        //mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
        //return;
        ASSERT(0);
    }
    if (prof_id == PROV_DEFAULT_PROF_ID)
    {
        status = CCA_STATUS_OUT_OF_RANGE;
    }

  error:
    if (hconfig == -1)
    {
        mmi_cca_send_cca_app_get_prof_rsp(data->app_id, data->prof_id, hconfig, CCA_STATUS_MEMFULL);
    }
    else
    {
        mmi_cca_send_cca_app_get_prof_rsp(data->app_id, data->prof_id, hconfig, status);
    }
    mmi_prov_free_profile_nodes();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_construct_brw_doc
 * DESCRIPTION
 *  Costruct CCA doc from brw profile
 * PARAMETERS
 *  wap_profile_list        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_cca_dm_construct_brw_doc(prov_wap_profile_list_struct *wap_profile_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 doc_config_h, root_h, node_h, proxy_node_h;
    S8 ip_address[16] = {0, };
    cca_state_enum status = CCA_STATUS_OK;
    nvram_wap_profile_content_struct *profile_content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_construct_brw_doc");

    ASSERT(wap_profile_list);
    profile_content = wap_profile_list->profile_content;
    ASSERT(profile_content);

    root_h = mmi_cca_doc_new_rootnode();
    if (!root_h)
    {
        return -1;
    }

    proxy_node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, root_h);
    if (!proxy_node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_NODEID, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_PROXY_ID, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_NAME, (S8*) wap_profile_list->profile_name) ==
        CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    sprintf(
        ip_address,
        "%d.%d.%d.%d",
        profile_content->proxy_ip[0],
        profile_content->proxy_ip[1],
        profile_content->proxy_ip[2],
        profile_content->proxy_ip[3]);

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_PXADDR, (S8*) ip_address) == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_int(proxy_node_h, CCA_NS_DATAACCTID, profile_content->data_account)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, proxy_node_h);
    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_PXAUTH_ID, (S8*) profile_content->username)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_PXAUTH_PW, (S8*) profile_content->password)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, proxy_node_h);
    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_int(node_h, CCA_NS_OMA_PORTNBR, profile_content->proxy_port) == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if ((mmi_cca_doc_add_nodedata_int(
            node_h,
            CCA_NS_OMA_SERVICE,
            mmi_prov_cca_dm_convert_conn_type(profile_content->conn_type, profile_content->proxy_port))) ==
        CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, root_h);

    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_APPID, (S8*) "w2") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_TO_PROXY, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_RESOURCE, node_h);
    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_URI, (S8*) profile_content->homepage_url)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_STARTPAGE, (S8*) "") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (status == CCA_STATUS_OK)
    {
        doc_config_h = mmi_cca_doc_new(root_h);
    }

  error:
    if ((status != CCA_STATUS_OK) || (!doc_config_h))
    {
        mmi_cca_docroot_release(root_h);
        return -1;
    }

    return doc_config_h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_construct_mms_doc
 * DESCRIPTION
 *  Costruct CCA doc from mms profile
 * PARAMETERS
 *  mms_profile_list        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_cca_dm_construct_mms_doc(prov_mms_profile_list_struct *mms_profile_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 doc_config_h, root_h, node_h, proxy_node_h;
    S8 ip_address[16] = {0, };
    cca_state_enum status = CCA_STATUS_OK;
    nvram_mms_profile_content_struct *profile_content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_construct_mms_doc");

    ASSERT(mms_profile_list);
    profile_content = mms_profile_list->profile_content;
    ASSERT(profile_content);

    root_h = mmi_cca_doc_new_rootnode();
    if (!root_h)
    {
        return -1;
    }

    proxy_node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, root_h);
    if (!proxy_node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_NODEID, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_PROXY_ID, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_NAME, (S8*) mms_profile_list->profile_name) ==
        CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    sprintf(
        ip_address,
        "%d.%d.%d.%d",
        profile_content->proxy_ip[0],
        profile_content->proxy_ip[1],
        profile_content->proxy_ip[2],
        profile_content->proxy_ip[3]);

    if (mmi_cca_doc_add_nodedata_str(proxy_node_h, CCA_NS_OMA_PXADDR, (S8*) ip_address) == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_int(proxy_node_h, CCA_NS_DATAACCTID, profile_content->data_account)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, proxy_node_h);
    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_PXAUTH_ID, (S8*) profile_content->username)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_PXAUTH_PW, (S8*) profile_content->password)
        == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, proxy_node_h);
    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_int(node_h, CCA_NS_OMA_PORTNBR, profile_content->proxy_port) == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if ((mmi_cca_doc_add_nodedata_int(
            node_h,
            CCA_NS_OMA_SERVICE,
            mmi_prov_cca_dm_convert_conn_type(profile_content->conn_type, profile_content->proxy_port))) ==
        CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, root_h);

    if (!node_h)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_APPID, (S8*) "w4") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }
    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_TO_PROXY, (S8*) "PROXY_1") == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (mmi_cca_doc_add_nodedata_str(node_h, CCA_NS_OMA_ADDR, (S8*) profile_content->mmsc_url) == CCA_STATUS_MEMFULL)
    {
        status = CCA_STATUS_MEMFULL;
        goto error;
    }

    if (status == CCA_STATUS_OK)
    {
        doc_config_h = mmi_cca_doc_new(root_h);
    }

  error:
    if ((status != CCA_STATUS_OK) || (!doc_config_h))
    {
        mmi_cca_docroot_release(root_h);
        return -1;
    }

    return doc_config_h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_dm_convert_conn_type
 * DESCRIPTION
 *  Convert profile module conn type to CCA module conn type
 * PARAMETERS
 *  conn_type       [IN]        
 *  port_parm       [IN]        
 * RETURNS
 *  cca_oma_values_enum
 *****************************************************************************/
cca_oma_values_enum mmi_prov_cca_dm_convert_conn_type(U8 conn_type, U16 port_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_dm_convert_conn_type");
    if (conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
    {
        return CCA_NS_VAL_CO_WSP;
    }
    else if (conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE)
    {
        return CCA_NS_VAL_CO_SEC_WSP;
    }
    else if (conn_type == PH_CONN_TYPE_HTTP)
    {
        switch (port_parm)
        {
            case PROV_PORT_443:
                return CCA_NS_VAL_OTA_HTTP_TLS_TO;
            case PROV_PORT_80:
            default:
                return CCA_NS_VAL_OTA_HTTP_TO;
        }
    }
    else
    {
        ASSERT(0);
        return CCA_NS_VAL_OTA_HTTP_TO;
    }
}

#endif /* __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */ /* #ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_mem
 * DESCRIPTION
 *  Free allocated memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_free_mem");
    mmi_prov_free_proxy_app_nodes();
    mmi_prov_free_profile_nodes();
    mmi_prov_free_bookmark_nodes();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_app_config_req_hdlr
 * DESCRIPTION
 *  handle MSG_ID_MMI_CCA_APP_CONFIGURE_IND events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_app_config_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_ind_struct *newConfigDoc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_cca_app_config_req_hdlr");
    newConfigDoc = (mmi_cca_app_configure_ind_struct*) msg;
    memset(&g_prov_cntx, 0, sizeof(g_prov_cntx));
    g_prov_cntx.config_id = newConfigDoc->config_id;
    g_prov_cntx.config_h = newConfigDoc->hConfig;

    switch (newConfigDoc->config_id)
    {
        case CCA_CONFIG_BROWSER:
            mmi_prov_new_brw_setting_ind(newConfigDoc);
            break;

        case CCA_CONFIG_MMS:
            mmi_prov_new_mms_setting_ind(newConfigDoc);
            break;

        default:
            ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_new_brw_setting_ind
 * DESCRIPTION
 *  It gets the new document from CCA and sends back the hconfig to get
 *  the nodes or data in the document.
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_new_brw_setting_ind(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum retcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_new_brw_setting_ind");

    if (mmi_cca_doc_process(
            newConfigDoc->hConfig,
            prov_brw_cca_mapping_table,
            sizeof(prov_brw_cca_mapping_table) / sizeof(U16),
            0,
            mmi_prov_brw_nodes_process_callback,
            0) == CCA_STATUS_OK)
    {
        g_prov_cntx.prov_type = PROV_BRS_SETTINGS;
        retcode = mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();
        if (retcode == CCA_STATUS_OK)
        {
            mmi_prov_entry_show_setting_info();
        }
        else
        {
            mmi_prov_free_mem();
            mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
        }

    }
    else
    {
        mmi_prov_free_mem();
        mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_new_mms_setting_ind
 * DESCRIPTION
 *  It gets the new document from CCA and sends back the hconfig to get
 *  the nodes or data in the document.
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_new_mms_setting_ind(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum retcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_new_mms_setting_ind");

    if (mmi_cca_doc_process(
            newConfigDoc->hConfig,
            prov_mms_cca_mapping_table,
            sizeof(prov_mms_cca_mapping_table) / sizeof(U16),
            0,
            mmi_prov_mms_nodes_process_callback,
            0) == CCA_STATUS_OK)
    {
        g_prov_cntx.prov_type = PROV_MMS_SETTINGS;
        retcode = mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();
        if (retcode == CCA_STATUS_OK)
        {
            mmi_prov_entry_show_setting_info();
        }
        else
        {
            mmi_prov_free_mem();
            mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
        }
    }
    else
    {
        mmi_prov_free_mem();
        mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_brw_nodes_process_callback
 * DESCRIPTION
 *  Callback function called by CCA as per the node like (proxy,port ,apllication & bookmark)
 *  being triggered.Used only for browser.
 * PARAMETERS
 *  hConfig             [IN]        
 *  node_h              [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [IN]        
 *  user_data           [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_brw_nodes_process_callback(
                    S32 hConfig,
                    S32 node_h,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* cca_core_data_struct *data = NULL; */
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_brw_nodes_process_callback");
    ASSERT(iter_datalist);
    switch (node_symbol)
    {
        case PROV_BRW_NODE_PROXY:
            status = mmi_prov_proxy_node_handler(iter_datalist);
            break;

        case PROV_BRW_NODE_PORT:
            status = mmi_prov_port_node_handler(iter_datalist);
            break;

        case PROV_BRW_NODE_PXAUTHINFO:
            status = mmi_prov_pxauthinfo_node_handler(iter_datalist);
            break;

        case PROV_BRW_NODE_APP:
            status = mmi_prov_application_node_handler(iter_datalist);
            break;

        case PROV_BRW_NODE_RESOURCE:
            status = mmi_prov_resource_node_handler(iter_datalist);
            break;
        default:
            ASSERT(0);
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_alloc_proxy_node
 * DESCRIPTION
 *  Allocates meory for proxy node
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_alloc_proxy_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_proxy_list_struct *temp_list_ptr = NULL;
    prov_proxy_list_struct *new_node = NULL;
    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_alloc_proxy_node");
    new_node = jdd_MemAlloc(1, sizeof(prov_proxy_list_struct));
    if (NULL == new_node)
    {
        return CCA_STATUS_MEMFULL;
    }
    new_node->proxy_content = jdd_MemAlloc(1, sizeof(prov_proxy_content_struct));
    if (NULL == new_node->proxy_content)
    {
        jdd_MemFree(new_node);
        new_node = NULL;
        return CCA_STATUS_MEMFULL;
    }
    /* Proxy default values */
    new_node->proxy_content->px_port = PROV_PORT_80;
    new_node->proxy_content->px_service = PH_CONN_TYPE_HTTP;
    new_node->proxy_content->px_addrtype = CCA_NS_VAL_IPV4;
    new_node->proxy_list_next = NULL;

    if (g_prov_cntx.proxy_list)
    {
        temp_list_ptr = (prov_proxy_list_struct*) g_prov_cntx.proxy_list;
        while (temp_list_ptr->proxy_list_next != NULL)
        {
            temp_list_ptr = (prov_proxy_list_struct*) temp_list_ptr->proxy_list_next;
        }
        temp_list_ptr->proxy_list_next = (prov_proxy_list_struct*) new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cntx.proxy_list = new_node;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_current_proxy_node_content
 * DESCRIPTION
 *  Find last node in proxy list
 * PARAMETERS
 *  void
 * RETURNS
 *  prov_proxy_content_struct
 *****************************************************************************/
prov_proxy_content_struct *mmi_prov_get_current_proxy_node_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_proxy_list_struct *temp_list_ptr = g_prov_cntx.proxy_list;

    /* cca_status_enum retcode = CCA_STATUS_OK; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_current_proxy_node_content");
    if (temp_list_ptr)
    {

        while (temp_list_ptr->proxy_list_next != NULL)
        {
            temp_list_ptr = (prov_proxy_list_struct*) temp_list_ptr->proxy_list_next;
        }

    }
    else
    {
        ASSERT(0);
    }
    return temp_list_ptr->proxy_content;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_alloc_app_node
 * DESCRIPTION
 *  Allocates meory for app node
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_alloc_app_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_app_list_struct *temp_list_ptr = NULL;
    prov_app_list_struct *new_node = NULL;
    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_alloc_app_node");
    new_node = jdd_MemAlloc(1, sizeof(prov_app_list_struct));
    if (NULL == new_node)
    {
        return CCA_STATUS_MEMFULL;
    }
    new_node->app_content = jdd_MemAlloc(1, sizeof(prov_application_content_struct));
    if (NULL == new_node->app_content)
    {
        jdd_MemFree(new_node);
        new_node = NULL;
        return CCA_STATUS_MEMFULL;
    }
    memset(new_node->app_content->app_to_proxy, 0, sizeof(new_node->app_content->app_to_proxy));
    new_node->app_list_next = NULL;

    if (g_prov_cntx.app_list)
    {
        temp_list_ptr = (prov_app_list_struct*) g_prov_cntx.app_list;  /* ->app_list_next; */
        while (temp_list_ptr->app_list_next != NULL)
        {
            temp_list_ptr = (prov_app_list_struct*) temp_list_ptr->app_list_next;
        }
        temp_list_ptr->app_list_next = (prov_app_list_struct*) new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cntx.app_list = (prov_app_list_struct*) new_node;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_current_app_node_content
 * DESCRIPTION
 *  Find last node in app list
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
prov_application_content_struct *mmi_prov_get_current_app_node_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_app_list_struct *temp_list_ptr = g_prov_cntx.app_list;

    /* cca_status_enum retcode = CCA_STATUS_OK; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_current_app_node_content");
    if (temp_list_ptr)
    {

        while (temp_list_ptr->app_list_next != NULL)
        {
            temp_list_ptr = (prov_app_list_struct*) temp_list_ptr->app_list_next;
        }

    }
    else
    {
        ASSERT(0);
    }
    return temp_list_ptr->app_content;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_alloc_bkm_node
 * DESCRIPTION
 *  Allocates meory for bkm node
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_alloc_bkm_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_bkm_list_struct *temp_list_ptr = NULL;
    prov_bkm_list_struct *new_node = NULL;
    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_alloc_bkm_node");
    new_node = jdd_MemAlloc(1, sizeof(prov_bkm_list_struct));
    if (NULL == new_node)
    {
        return CCA_STATUS_MEMFULL;
    }
    new_node->bkm_content = jdd_MemAlloc(1, sizeof(prov_bookmark_content_struct));
    if (NULL == new_node->bkm_content)
    {
        jdd_MemFree(new_node);
        new_node = NULL;
        return CCA_STATUS_MEMFULL;
    }
    new_node->bkm_list_next = NULL;

    if (g_prov_cntx.bkm_list)
    {
        temp_list_ptr = (prov_bkm_list_struct*) g_prov_cntx.bkm_list;  /* ->bkm_list_next; */
        while (temp_list_ptr->bkm_list_next != NULL)
        {
            temp_list_ptr = (prov_bkm_list_struct*) temp_list_ptr->bkm_list_next;
        }
        temp_list_ptr->bkm_list_next = new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cntx.bkm_list = new_node;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_current_bkm_node_content
 * DESCRIPTION
 *  Find last node in bkm list
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
prov_bookmark_content_struct *mmi_prov_get_current_bkm_node_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_bkm_list_struct *temp_list_ptr = g_prov_cntx.bkm_list;

    /* cca_status_enum retcode = CCA_STATUS_OK; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_current_bkm_node_content");
    if (temp_list_ptr)
    {

        while (temp_list_ptr->bkm_list_next != NULL)
        {
            temp_list_ptr = (prov_bkm_list_struct*) temp_list_ptr->bkm_list_next;
        }

    }
    else
    {
        ASSERT(0);
    }
    return temp_list_ptr->bkm_content;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_last_bkm_node
 * DESCRIPTION
 *  free bookmark list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_last_bkm_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_bkm_list_struct *temp_list_ptr;
    prov_bkm_list_struct *temp_list_parent_ptr;

    /* cca_status_enum retcode = CCA_STATUS_OK; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_free_last_bkm_node");
    ASSERT(g_prov_cntx.bkm_list);
    if (g_prov_cntx.bkm_list->bkm_list_next)
    {
        temp_list_parent_ptr = g_prov_cntx.bkm_list;
        temp_list_ptr = g_prov_cntx.bkm_list->bkm_list_next;
        while (temp_list_ptr->bkm_list_next != NULL)
        {
            temp_list_parent_ptr = temp_list_ptr;
            temp_list_ptr = temp_list_ptr->bkm_list_next;

        }
        ASSERT(temp_list_ptr);
        ASSERT(temp_list_ptr->bkm_content);
        jdd_MemFree(temp_list_ptr->bkm_content);
        temp_list_ptr->bkm_content = NULL;
        jdd_MemFree(temp_list_ptr);
        temp_list_ptr = NULL;
        temp_list_parent_ptr->bkm_list_next = NULL;
    }
    else
    {
        jdd_MemFree(g_prov_cntx.bkm_list->bkm_content);
        g_prov_cntx.bkm_list->bkm_content = NULL;
        jdd_MemFree(g_prov_cntx.bkm_list);
        g_prov_cntx.bkm_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_copy_data_value
 * DESCRIPTION
 *  Copy data value
 * PARAMETERS
 *  src_ptr         [OUT]       
 *  data            [IN]        
 *  data_length     [IN]        
 *  str_dcs         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
cca_status_enum mmi_prov_copy_data_value(U8 *src_ptr, cca_core_data_struct *data, U16 data_length, U8 str_dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_copy_data_value");
    if (data->size <= 0 || data->type != CCA_DT_STR)
    {
        ASSERT(0);
    }
    if (data->values.s[0])
    {
        strncpy((S8*) src_ptr, (S8*) data->values.s[0], data_length);
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_proxy_node_handler
 * DESCRIPTION
 *  Handle proxy node
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_proxy_node_handler(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cca_core_data_struct *data = NULL;
    prov_proxy_content_struct *proxy_content = NULL;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_proxy_node_handler");
    if (mmi_prov_alloc_proxy_node() == CCA_STATUS_MEMFULL)
    {
        return CCA_STATUS_MEMFULL;
    }
    proxy_content = mmi_prov_get_current_proxy_node_content();
    if (proxy_content == NULL)
    {
        ASSERT(0);
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {

        switch (data->id)
        {
            case CCA_NS_OMA_PROXY_ID:
                status = mmi_prov_copy_data_value(proxy_content->px_id, data, (PROV_PROXY_ID_LEN - 1), PH_DCS_ASCII);
                break;
            case CCA_NS_OMA_NAME:
                status = mmi_prov_copy_data_value(
                            proxy_content->px_name,
                            data,
                            (NVRAM_WAP_PROFILE_NAME_LEN - 1),
                            PH_DCS_ASCII_UCS);
                break;

            case CCA_NS_OMA_PXADDR:
                status = mmi_prov_copy_data_value(proxy_content->px_addr, data, (PROV_PX_ADDR_LEN - 1), PH_DCS_ASCII);
                break;

            case CCA_NS_DATAACCTID:

                if (data->size)
                {
                    proxy_content->px_primary_dataacc_id = data->values.i[0];
                    // proxy_content->px_secondary_dataacc_id = -1;/*Currntly not in used*/
                }
                break;

            case CCA_NS_OMA_PXADDRTYPE:

                if (data->size)
                {
                    proxy_content->px_addrtype = data->values.i[0];
                }
                break;

            case CCA_NS_OMA_STARTPAGE:
                status = mmi_prov_copy_data_value(
                            proxy_content->px_startpage,
                            data,
                            (NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN - 1),
                            PH_DCS_ASCII);
                break;
        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_port_node_handler
 * DESCRIPTION
 *  Handle port node
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_port_node_handler(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_parm = 0;
    S32 port_number = 0;

    cca_status_enum status = CCA_STATUS_OK;
    S8 *portnbr_parm = NULL;

    /* cca_core_data_struct *data = NULL; */
    prov_proxy_content_struct *proxy_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_port_node_handler");
    proxy_content = mmi_prov_get_current_proxy_node_content();
    if (proxy_content == NULL)
    {
        ASSERT(0);
    }
    if (!strlen((S8*) proxy_content->px_id))
    {
        ASSERT(0);
    }
    if (mmi_cca_doc_get_nodedata_str_first(iter_datalist, CCA_NS_OMA_PORTNBR, &portnbr_parm) != CCA_STATUS_MEMFULL)
    {
        if (portnbr_parm)
        {
            port_number = atoi(portnbr_parm);
        }
        if (mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_SERVICE, &service_parm) == CCA_STATUS_MEMFULL)
        {
            return CCA_STATUS_MEMFULL;
        }

    }
    else
    {
        return CCA_STATUS_MEMFULL;
    }

    switch (service_parm)
    {
        case CCA_NS_VAL_CL_WSP:
        case CCA_NS_VAL_CL_SEC_WSP:

            proxy_content->px_port = PROV_PORT_9200;    /* Later changed */
            /* Currently Not supported */
            break;

        case CCA_NS_VAL_CO_WSP:

            proxy_content->px_service = PH_CONN_TYPE_CONNECTION_OREINTED;
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_9201);
            break;

        case CCA_NS_VAL_CO_SEC_WSP:

            proxy_content->px_service = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_9203);
            break;

        case CCA_NS_VAL_OTA_HTTP_TLS_TO:

            proxy_content->px_service = PH_CONN_TYPE_HTTP;
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_443);
            break;

        case CCA_NS_VAL_OTA_HTTP_TLS_PO:

            proxy_content->px_service = PH_CONN_TYPE_HTTP;
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_443);
            break;

        case CCA_NS_VAL_OTA_HTTP_TO:
        case CCA_NS_VAL_OTA_HTTP_PO:

            proxy_content->px_service = PH_CONN_TYPE_HTTP;
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_80);
            break;

        default:
            if (portnbr_parm != NULL)
            {
                port_number = atoi(portnbr_parm);
                if (port_number == PROV_PORT_9201)
                {
                    proxy_content->px_service = PH_CONN_TYPE_CONNECTION_OREINTED;
                }
                else if (port_number == PROV_PORT_9203)
                {
                    proxy_content->px_service = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                }
                else
                {
                    proxy_content->px_service = PH_CONN_TYPE_HTTP;
                }
            }
            else
            {
                proxy_content->px_service = PH_CONN_TYPE_HTTP;
            }
            mmi_prov_handle_port_params(&proxy_content->px_port, portnbr_parm, PROV_PORT_80);
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_pxauthinfo_node_handler
 * DESCRIPTION
 *  Handle pxauthinfo node
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_pxauthinfo_node_handler(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    prov_proxy_content_struct *proxy_content = NULL;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_pxauthinfo_node_handler");
    proxy_content = mmi_prov_get_current_proxy_node_content();
    if (proxy_content == NULL)
    {
        ASSERT(0);
    }
    if (!strlen((S8*) proxy_content->px_id))
    {
        ASSERT(0);
    }
    /* Only cosidering the first pxauthinfo */
    if (strlen((S8*) proxy_content->px_authid) || strlen((S8*) proxy_content->px_authpw))
    {
        return status;
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {

        switch (data->id)
        {
            case CCA_NS_OMA_PXAUTH_ID:
                status = mmi_prov_copy_data_value(
                            proxy_content->px_authid,
                            data,
                            (NVRAM_WAP_PROFILE_USERNAME_LEN - 1),
                            PH_DCS_ASCII);
                break;

            case CCA_NS_OMA_PXAUTH_PW:
                status = mmi_prov_copy_data_value(
                            proxy_content->px_authpw,
                            data,
                            (NVRAM_WAP_PROFILE_PASSWORD_LEN - 1),
                            PH_DCS_ASCII);
                break;
        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_application_node_handler
 * DESCRIPTION
 *  Handle app node
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_application_node_handler(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;

    /* U8 to_prxoy_count = 0; */
    prov_application_content_struct *app_content = NULL;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_application_node_handler");
    if (mmi_prov_alloc_app_node() == CCA_STATUS_MEMFULL)
    {
        return CCA_STATUS_MEMFULL;
    }
    app_content = mmi_prov_get_current_app_node_content();
    if (app_content == NULL)
    {
        ASSERT(0);
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {

        switch (data->id)
        {
            case CCA_NS_OMA_NAME:
                status = mmi_prov_copy_data_value(
                            app_content->app_name,
                            data,
                            (NVRAM_WAP_PROFILE_NAME_LEN - 1),
                            PH_DCS_ASCII_UCS);
                break;
            case CCA_NS_OMA_TO_PROXY:
                status = mmi_prov_handle_to_proxy_params(app_content, data);
                break;

            case CCA_NS_OMA_ADDR:
                status = mmi_prov_copy_data_value(
                            app_content->app_url,
                            data,
                            (NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN - 1),
                            PH_DCS_ASCII);
                break;

        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_resource_node_handler
 * DESCRIPTION
 *  Handle resource node
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_resource_node_handler(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bkm_flag = MMI_FALSE;
    cca_core_data_struct *data = NULL;
    prov_application_content_struct *app_content = NULL;
    prov_bookmark_content_struct *bkm_content = NULL;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_resource_node_handler");
    if (mmi_prov_alloc_bkm_node() == CCA_STATUS_MEMFULL)
    {
        return CCA_STATUS_MEMFULL;
    }
    bkm_content = mmi_prov_get_current_bkm_node_content();
    app_content = mmi_prov_get_current_app_node_content();
    if (bkm_content == NULL || app_content == NULL)
    {
        ASSERT(0);
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {

        switch (data->id)
        {
            case CCA_NS_OMA_NAME:
                status = mmi_prov_copy_data_value(
                            bkm_content->bm_title,
                            data,
                            (PROV_BKM_TITLE_LEN - 1) * ENCODING_LENGTH,
                            PH_DCS_ASCII_UCS);
                break;
            case CCA_NS_OMA_URI:
                status = mmi_prov_copy_data_value(bkm_content->bm_url, data, (PROV_BKM_URL_LEN - 1), PH_DCS_ASCII);
                break;
            case CCA_NS_OMA_STARTPAGE:
                bkm_flag = MMI_TRUE;
                break;

        }
    }
    if (bkm_flag)
    {
        if (strlen((S8*) bkm_content->bm_url))
        {
            strncpy((S8*) app_content->app_url, (S8*) bkm_content->bm_url, (NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN - 1));
        }
        mmi_prov_free_last_bkm_node();
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_mms_nodes_process_callback
 * DESCRIPTION
 *  Callback function called by CCA as per the node like (proxy,port ,apllication & bookmark)
 *  being triggered.Used only for MMS.
 * PARAMETERS
 *  hConfig             [IN]        
 *  node_h              [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [IN]        
 *  user_data           [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_mms_nodes_process_callback(
                    S32 hConfig,
                    S32 node_h,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //cca_core_data_struct *data = NULL;
    //    S32 service_parm = 0, px_addrtype = -1;
    //    S8 *portnbr_parm = NULL, i = 0;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_mms_nodes_process_callback");
    ASSERT(iter_datalist);
    switch (node_symbol)
    {
        case PROV_MMS_NODE_PROXY:
            status = mmi_prov_proxy_node_handler(iter_datalist);
            break;

        case PROV_MMS_NODE_PORT:
            status = mmi_prov_port_node_handler(iter_datalist);
            break;

        case PROV_MMS_NODE_PXAUTHINFO:
            status = mmi_prov_pxauthinfo_node_handler(iter_datalist);
            break;

        case PROV_MMS_NODE_APP:
            status = mmi_prov_application_node_handler(iter_datalist);
            break;

    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_to_proxy_params
 * DESCRIPTION
 *  It fills the prot parameter for the proxy.
 * PARAMETERS
 *  app_content     [IN]        
 *  data            [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_handle_to_proxy_params(
                    prov_application_content_struct *app_content,
                    cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 proxy_count, loop_count;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_handle_to_proxy_params");
    proxy_count = data->size <= MAX_TO_RPOXY ? data->size : MAX_TO_RPOXY;
    for (loop_count = 0; loop_count < proxy_count; loop_count++)
    {
        app_content->app_to_proxy[loop_count] = jdd_MemAlloc(1, PROV_PROXY_ID_LEN);
        if (app_content->app_to_proxy[loop_count] == NULL)
        {
            return CCA_STATUS_MEMFULL;
        }
        strncpy(
            (S8*) app_content->app_to_proxy[loop_count],
            (S8*) data->values.s[loop_count],
            (PROV_PROXY_ID_LEN - 1));
    }
    return status;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_port_params
 * DESCRIPTION
 *  It fills the prot parameter for the proxy.
 * PARAMETERS
 *  px_port                     [IN]        
 *  portnbr_parm                [IN]        
 *  default_portnbr_parm        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_port_params(U16 *px_port, S8 *portnbr_parm, S32 default_portnbr_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 port_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_handle_port_params");
    if (!portnbr_parm || (!strlen(portnbr_parm)))
    {
        *px_port = default_portnbr_parm;
    }
    else
    {
        port_number = atoi(portnbr_parm);
        if (port_number <= 0 || port_number >= PH_USHORT_MAX)
        {
            *px_port = default_portnbr_parm;
        }
        else
        {
            *px_port = port_number;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_valid_proxy_node
 * DESCRIPTION
 *  This API creates profile list based on the proxy list and application list.
 * PARAMETERS
 *  proxy_content       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_prov_check_valid_proxy_node(prov_proxy_content_struct *proxy_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_check_valid_proxy_node");
    if ((proxy_content->px_port == PROV_PORT_9200) ||
        ((proxy_content->px_addrtype != CCA_NS_VAL_IPV4) &&
         (proxy_content->px_addrtype != CCA_NS_VAL__INVALID) && (proxy_content->px_addrtype != CCA_NS_VAL__EMPTY)))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_merge_proxy_application_node_list
 * DESCRIPTION
 *  This API creates profile list based on the proxy list and application list.
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_merge_proxy_application_node_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    cca_status_enum retcode = CCA_STATUS_OK;
    prov_app_list_struct *app_list_ptr = (prov_app_list_struct*) g_prov_cntx.app_list;
    prov_proxy_list_struct *proxy_list_ptr = (prov_proxy_list_struct*) g_prov_cntx.proxy_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_merge_proxy_application_node_list");
    while (app_list_ptr)
    {
        count = 0;
        while (app_list_ptr->app_content->app_to_proxy[count] != NULL && count < MAX_PROFILE_COUNT)
        {
            proxy_list_ptr = (prov_proxy_list_struct*) g_prov_cntx.proxy_list;
            while (proxy_list_ptr)
            {
                if (strcmp
                    ((S8*) app_list_ptr->app_content->app_to_proxy[count],
                     (S8*) proxy_list_ptr->proxy_content->px_id) == 0 &&
                    mmi_prov_check_valid_proxy_node(proxy_list_ptr->proxy_content))
                {
                    if (g_prov_cntx.prov_type == PROV_BRS_SETTINGS)
                    {
                        retcode = mmi_prov_create_wap_profile_list(proxy_list_ptr->proxy_content, app_list_ptr->app_content);
                    }
                    else if (g_prov_cntx.prov_type == PROV_MMS_SETTINGS)
                    {
                        retcode = mmi_prov_create_mms_profile_list(proxy_list_ptr->proxy_content, app_list_ptr->app_content);
                    }
                    if (retcode != CCA_STATUS_OK)
                    {
                        return retcode;
                    }
                    break;
                }
                proxy_list_ptr = (prov_proxy_list_struct*) proxy_list_ptr->proxy_list_next;
            }
            count++;
        }
        app_list_ptr = (prov_app_list_struct*) app_list_ptr->app_list_next;
    }
    if ((!g_prov_cntx.profile_count) && (!mmi_prov_get_bookmark_node_count()))
    {
        retcode = CCA_STATUS_FAIL;
    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_wap_profile_list
 * DESCRIPTION
 *  Creates wap profile list
 * PARAMETERS
 *  proxy_content       [IN]        
 *  app_content         [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_create_wap_profile_list(
                    prov_proxy_content_struct *proxy_content,
                    prov_application_content_struct *app_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* U8 proxy_content->px_addrtype; */

    cca_status_enum retcode = CCA_STATUS_OK;
    prov_wap_profile_list_struct *profile_list;
    nvram_wap_profile_content_struct *profile_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_create_wap_profile_list");
    ASSERT(proxy_content && app_content);
    if (mmi_prov_alloc_wap_profile_node() == CCA_STATUS_MEMFULL)
    {
        return CCA_STATUS_MEMFULL;
    }
    profile_list = mmi_prov_get_current_wap_profile_node();
    profile_content = profile_list->profile_content;
    if (profile_content == NULL)
    {
        ASSERT(0);
    }
    g_prov_cntx.profile_count++;
    profile_content->data_account = proxy_content->px_primary_dataacc_id;
    profile_content->conn_type = proxy_content->px_service;
    profile_content->proxy_port = proxy_content->px_port;
    if (strlen((S8*) app_content->app_url))
    {
        memcpy(profile_content->homepage_url, app_content->app_url, NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN);
    }
    else
    {
        memcpy(profile_content->homepage_url, proxy_content->px_startpage, NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN);
    }
    if (strlen((S8*) app_content->app_name))
    {
        memcpy(profile_list->profile_name, app_content->app_name, NVRAM_WAP_PROFILE_NAME_LEN);
    }
    else
    {
        memcpy(profile_list->profile_name, proxy_content->px_name, NVRAM_WAP_PROFILE_NAME_LEN);
    }

    memcpy(profile_content->username, proxy_content->px_authid, NVRAM_WAP_PROFILE_USERNAME_LEN);
    memcpy(profile_content->password, proxy_content->px_authpw, NVRAM_WAP_PROFILE_PASSWORD_LEN);
    if (mmi_prov_convert_ip_string_to_array((S8*) proxy_content->px_addr, (U8*) profile_content->proxy_ip) ==
        PROV_ERR)
    {
        memset(profile_content->proxy_ip, 0, MAX_PART_IP_ADDRESS);
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_mms_profile_list
 * DESCRIPTION
 *  Creates mms profile list
 * PARAMETERS
 *  proxy_content       [IN]        
 *  app_content         [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_create_mms_profile_list(
                    prov_proxy_content_struct *proxy_content,
                    prov_application_content_struct *app_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cca_status_enum retcode = CCA_STATUS_OK;
    prov_mms_profile_list_struct *profile_list;
    nvram_mms_profile_content_struct *profile_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_create_mms_profile_list");
    ASSERT(proxy_content && app_content);
    if (mmi_prov_alloc_mms_profile_node() == CCA_STATUS_MEMFULL)
    {
        return CCA_STATUS_MEMFULL;
    }
    profile_list = mmi_prov_get_current_mms_profile_node();
    profile_content = profile_list->profile_content;
    if (profile_content == NULL)
    {
        ASSERT(0);
    }
    g_prov_cntx.profile_count++;
    profile_content->data_account = proxy_content->px_primary_dataacc_id;
    profile_content->conn_type = proxy_content->px_service;
    profile_content->proxy_port = proxy_content->px_port;
    if (strlen((S8*) app_content->app_url))
    {
        memcpy(profile_content->mmsc_url, app_content->app_url, NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN);    /* check all the macro and if necessary then replace */
    }
    else
    {
        memcpy(profile_content->mmsc_url, proxy_content->px_startpage, NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN);
    }
    if (strlen((S8*) app_content->app_name))
    {
        memcpy(profile_list->profile_name, app_content->app_name, NVRAM_WAP_PROFILE_NAME_LEN);
    }
    else
    {
        memcpy(profile_list->profile_name, proxy_content->px_name, NVRAM_WAP_PROFILE_NAME_LEN);
    }

    memcpy(profile_content->username, proxy_content->px_authid, NVRAM_WAP_PROFILE_USERNAME_LEN);
    memcpy(profile_content->password, proxy_content->px_authpw, NVRAM_WAP_PROFILE_PASSWORD_LEN);
    if (mmi_prov_convert_ip_string_to_array((S8*) proxy_content->px_addr, (U8*) profile_content->proxy_ip) ==
        PROV_ERR)
    {
        memset(profile_content->proxy_ip, 0, MAX_PART_IP_ADDRESS);
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_alloc_wap_profile_node
 * DESCRIPTION
 *  Allocates wap profile node
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_alloc_wap_profile_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_wap_profile_list_struct *temp_list_ptr = NULL;
    prov_wap_profile_list_struct *new_node = NULL;
    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_alloc_wap_profile_node");
    new_node = jdd_MemAlloc(1, sizeof(prov_wap_profile_list_struct));
    if (NULL == new_node)
    {
        return CCA_STATUS_MEMFULL;
    }
    new_node->profile_content = jdd_MemAlloc(1, sizeof(nvram_wap_profile_content_struct));
    if (NULL == new_node->profile_content)
    {
        jdd_MemFree(new_node);
        new_node = NULL;
        return CCA_STATUS_MEMFULL;
    }
    new_node->profile_list_next = NULL;

    if (g_prov_cntx.wap_profile_list)
    {
        temp_list_ptr = (prov_wap_profile_list_struct*) g_prov_cntx.wap_profile_list;  /* ->profile_list_next; */
        while (temp_list_ptr->profile_list_next != NULL)
        {
            temp_list_ptr = (prov_wap_profile_list_struct*) temp_list_ptr->profile_list_next;
        }
        temp_list_ptr->profile_list_next = new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cntx.wap_profile_list = new_node;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_current_wap_profile_node
 * DESCRIPTION
 *  Find last wap profile node
 * PARAMETERS
 *  void
 * RETURNS
 *  prov_wap_profile_list_struct *
 *****************************************************************************/
prov_wap_profile_list_struct *mmi_prov_get_current_wap_profile_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_wap_profile_list_struct *temp_list_ptr = g_prov_cntx.wap_profile_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_current_wap_profile_node");
    if (temp_list_ptr)
    {

        while (temp_list_ptr->profile_list_next != NULL)
        {
            temp_list_ptr = (prov_wap_profile_list_struct*) temp_list_ptr->profile_list_next;
        }

    }
    else
    {
        ASSERT(0);
    }
    return temp_list_ptr;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_alloc_mms_profile_node
 * DESCRIPTION
 *  Allocates mms profile node
 * PARAMETERS
 *  void
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum mmi_prov_alloc_mms_profile_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_mms_profile_list_struct *temp_list_ptr = NULL;
    prov_mms_profile_list_struct *new_node = NULL;
    cca_status_enum retcode = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_alloc_mms_profile_node");
    new_node = jdd_MemAlloc(1, sizeof(prov_mms_profile_list_struct));
    if (NULL == new_node)
    {
        return CCA_STATUS_MEMFULL;
    }
    new_node->profile_content = jdd_MemAlloc(1, sizeof(nvram_mms_profile_content_struct));
    if (NULL == new_node->profile_content)
    {
        jdd_MemFree(new_node);
        new_node = NULL;
        return CCA_STATUS_MEMFULL;
    }
    new_node->profile_list_next = NULL;

    if (g_prov_cntx.mms_profile_list)
    {
        temp_list_ptr = (prov_mms_profile_list_struct*) g_prov_cntx.mms_profile_list;  /* ->profile_list_next; */
        while (temp_list_ptr->profile_list_next != NULL)
        {
            temp_list_ptr = (prov_mms_profile_list_struct*) temp_list_ptr->profile_list_next;
        }
        temp_list_ptr->profile_list_next = new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cntx.mms_profile_list = new_node;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_current_mms_profile_node
 * DESCRIPTION
 *  Find last mms profile node
 * PARAMETERS
 *  void
 * RETURNS
 *  prov_wap_profile_list_struct *
 *****************************************************************************/
prov_mms_profile_list_struct *mmi_prov_get_current_mms_profile_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_mms_profile_list_struct *temp_list_ptr = g_prov_cntx.mms_profile_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_current_mms_profile_node");
    if (temp_list_ptr)
    {

        while (temp_list_ptr->profile_list_next != NULL)
        {
            temp_list_ptr = (prov_mms_profile_list_struct*) temp_list_ptr->profile_list_next;
        }

    }
    else
    {
        ASSERT(0);
    }
    return temp_list_ptr;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_proxy_app_nodes
 * DESCRIPTION
 *  This API frees all the memory used to create a profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_proxy_app_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_proxy_list_struct *temp_proxy_list;
    prov_app_list_struct *temp_app_list;
    U8 loop_count = 0;

    /* void *temp_list; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_free_proxy_app_nodes");
    while (g_prov_cntx.proxy_list)
    {

        temp_proxy_list = (prov_proxy_list_struct*) g_prov_cntx.proxy_list;
        g_prov_cntx.proxy_list = (prov_proxy_list_struct*) g_prov_cntx.proxy_list->proxy_list_next;

        jdd_MemFree(temp_proxy_list->proxy_content);
        temp_proxy_list->proxy_content = NULL;

        jdd_MemFree(temp_proxy_list);
        temp_proxy_list = NULL;
    }

    while (g_prov_cntx.app_list)
    {

        temp_app_list = (prov_app_list_struct*) g_prov_cntx.app_list;
        g_prov_cntx.app_list = (prov_app_list_struct*) g_prov_cntx.app_list->app_list_next;
        while (temp_app_list->app_content->app_to_proxy[loop_count])
        {
            jdd_MemFree(temp_app_list->app_content->app_to_proxy[loop_count]);
            temp_app_list->app_content->app_to_proxy[loop_count] = NULL;
            loop_count++;
            ASSERT(loop_count < MAX_TO_RPOXY);
        }
        jdd_MemFree(temp_app_list->app_content);
        temp_app_list->app_content = NULL;

        jdd_MemFree(temp_app_list);
        temp_app_list = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_bookmark_nodes
 * DESCRIPTION
 *  This API frees all the memory used to create bookmark nodes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_bookmark_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_bkm_list_struct *temp_bkm_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_free_bookmark_nodes");
    while (g_prov_cntx.bkm_list)
    {

        temp_bkm_list = (prov_bkm_list_struct*) g_prov_cntx.bkm_list;
        g_prov_cntx.bkm_list = (prov_bkm_list_struct*) g_prov_cntx.bkm_list->bkm_list_next;

        jdd_MemFree(temp_bkm_list->bkm_content);
        temp_bkm_list->bkm_content = NULL;

        jdd_MemFree(temp_bkm_list);
        temp_bkm_list = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_profile_nodes
 * DESCRIPTION
 *  This API frees all the memory used to create a profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_profile_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_wap_profile_list_struct *temp_wap_profile_list;
    prov_mms_profile_list_struct *temp_mms_profile_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_free_profile_nodes");
    while (g_prov_cntx.wap_profile_list)
    {

        temp_wap_profile_list = (prov_wap_profile_list_struct*) g_prov_cntx.wap_profile_list;
        g_prov_cntx.wap_profile_list = (prov_wap_profile_list_struct*) g_prov_cntx.wap_profile_list->profile_list_next;

        jdd_MemFree(temp_wap_profile_list->profile_content);
        temp_wap_profile_list->profile_content = NULL;

        jdd_MemFree(temp_wap_profile_list);
        temp_wap_profile_list = NULL;
    }

    while (g_prov_cntx.mms_profile_list)
    {

        temp_mms_profile_list = (prov_mms_profile_list_struct*) g_prov_cntx.mms_profile_list;
        g_prov_cntx.mms_profile_list = (prov_mms_profile_list_struct*) g_prov_cntx.mms_profile_list->profile_list_next;

        jdd_MemFree(temp_mms_profile_list->profile_content);
        temp_mms_profile_list->profile_content = NULL;

        jdd_MemFree(temp_mms_profile_list);
        temp_mms_profile_list = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_entry_show_setting_info
 * DESCRIPTION
 *  Displays details of the provisioning settings(Browser or MMS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_entry_show_setting_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U8 *display_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_SHOW_SETTING_INFO, NULL, mmi_prov_entry_show_setting_info, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_entry_show_setting_info");

    DeleteScreenIfPresent(SCR_ID_PROF_HDLR_SHOW_SETTING_INFO);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_SHOW_SETTING_INFO);
    if (sizeof(subMenuData) < (PROV_DISPLAY_INFO_SIZE * 2))
    {
        ASSERT(0);
    }

    display_info = (PU8) subMenuData;

    if (g_prov_cntx.prov_type == PROV_BRS_SETTINGS)
    {
        memset(display_info, 0, (PROV_DISPLAY_INFO_SIZE * 2));  /* Multiplication By 2 is for displaying Bookmark information */
        mmi_prov_create_display_info_for_browser(display_info);
    }
    else if (g_prov_cntx.prov_type == PROV_MMS_SETTINGS)
    {
        memset(display_info, 0, PROV_DISPLAY_INFO_SIZE);
        mmi_prov_create_display_info_for_mms(display_info);
    }

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_INSTALL,
        0,
        STR_ID_CCA_SKIP,
        0,
        (U8*) display_info,
        mmi_ucs2strlen((const S8*)display_info),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_prov_install_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_prov_install_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_prov_skip_profile, KEY_EVENT_UP);
    SetKeyHandler(mmi_prov_skip_profile, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_prov_end_key_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_end_key_handler
 * DESCRIPTION
 *  End key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_end_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_end_key_handler");
    /* free memory */
    mmi_prov_free_profile_nodes();
    mmi_prov_free_bookmark_nodes();
    mmi_prov_send_response(CCA_STATUS_ENDKEY_PRESSED);
    DisplayIdleScreen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_profile_node_count
 * DESCRIPTION
 *  Get profile count
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_prov_get_profile_node_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    prov_wap_profile_list_struct *temp_wap_list;
    prov_mms_profile_list_struct *temp_mms_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_profile_node_count");
    if (g_prov_cntx.prov_type == PROV_BRS_SETTINGS)
    {
        temp_wap_list = g_prov_cntx.wap_profile_list;
        while (temp_wap_list != NULL)
        {
            temp_wap_list = (prov_wap_profile_list_struct*) temp_wap_list->profile_list_next;
            count++;
        }
    }
    else if (g_prov_cntx.prov_type == PROV_MMS_SETTINGS)
    {
        temp_mms_list = g_prov_cntx.mms_profile_list;
        while (temp_mms_list != NULL)
        {
            temp_mms_list = (prov_mms_profile_list_struct*) temp_mms_list->profile_list_next;
            count++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_bookmark_node_count
 * DESCRIPTION
 *  Get bookmark count
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_prov_get_bookmark_node_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    prov_bkm_list_struct *temp_bkm_list = g_prov_cntx.bkm_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_get_bookmark_node_count");
    while (temp_bkm_list != NULL)
    {
        temp_bkm_list = (prov_bkm_list_struct*) temp_bkm_list->bkm_list_next;
        count++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_update_profile_node_list
 * DESCRIPTION
 *  Updates profilr list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_update_profile_node_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_wap_profile_list_struct *temp_wap_list;
    prov_mms_profile_list_struct *temp_mms_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_update_profile_node_list");
    if (g_prov_cntx.prov_type == PROV_BRS_SETTINGS)
    {
        temp_wap_list = g_prov_cntx.wap_profile_list;
        if (temp_wap_list)
        {
            g_prov_cntx.wap_profile_list =
                (prov_wap_profile_list_struct*) g_prov_cntx.wap_profile_list->profile_list_next;

            jdd_MemFree(temp_wap_list->profile_content);
            temp_wap_list->profile_content = NULL;

            jdd_MemFree(temp_wap_list);
            temp_wap_list = NULL;
        }
    }
    else if (g_prov_cntx.prov_type == PROV_MMS_SETTINGS)
    {
        temp_mms_list = g_prov_cntx.mms_profile_list;
        if (temp_mms_list)
        {
            g_prov_cntx.mms_profile_list =
                (prov_mms_profile_list_struct*) g_prov_cntx.mms_profile_list->profile_list_next;

            jdd_MemFree(temp_mms_list->profile_content);
            temp_mms_list->profile_content = NULL;

            jdd_MemFree(temp_mms_list);
            temp_mms_list = NULL;

        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_display_info_for_browser
 * DESCRIPTION
 *  This API creates a format to display the details of browser & bookmark settings
 * PARAMETERS
 *  display_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_create_display_info_for_browser(U8 *display_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 len = 0;
    S16 index = 0;
    S8 dotted[] = "...";
    U8 dotted_unicode[PROV_DOT_SIZE];
    S8 new_line[] = "\n";
    U8 new_line_info[PROV_NEW_LINE_SIZE];
    S8 profile_count[PROV_COUNT_SIZE];
    S8 ip_address[PROV_IP_ADDRESS_LEN];
    S8 proxy_port[PROV_MAX_PROXY_PORT_LENGTH];
    S8 buffer[PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN * ENCODING_LENGTH];
    S8 bookmark_title[PROV_BKM_TITLE_SIZE];

    nvram_wap_profile_content_struct *profile_content = NULL;
    prov_bkm_list_struct *temp_bkm_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_create_display_info_for_browser");
    if (g_prov_cntx.wap_profile_list != NULL)
    {
        profile_content = g_prov_cntx.wap_profile_list->profile_content;
    }
    temp_bkm_list = g_prov_cntx.bkm_list;

    mmi_asc_to_ucs2((S8*) new_line_info, (S8*) new_line);
    mmi_asc_to_ucs2((S8*) dotted_unicode, (S8*) dotted);

    if (profile_content != NULL)
    {
        /* App Name */
        mmi_ucs2cpy((PS8) display_info, GetString(STR_ID_CCA_BROWSER));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        /* Number of profiles */
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_CCA_PROFILE));

        sprintf(
            profile_count,
            "%c %d/%d",
            ':',
            ((g_prov_cntx.profile_count - mmi_prov_get_profile_node_count()) + 1),
            g_prov_cntx.profile_count);
        mmi_asc_to_ucs2((S8*) buffer, (S8*) profile_count);
        mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Profile Name:");
        //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_PROFILE_NAME));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        memset(buffer, '\0', sizeof(buffer));

        mmi_chset_utf8_to_ucs2_string(
            (U8*) buffer,
            (PROV_MAX_DISPLAY_PROFILE_NAME_LEN * ENCODING_LENGTH),
            (U8*) g_prov_cntx.wap_profile_list->profile_name);

        mmi_ucs2cat((PS8) display_info, (S8*) buffer);

        len = mmi_chset_utf8_strlen((U8*) g_prov_cntx.wap_profile_list->profile_name);
        if (len > PROV_MAX_DISPLAY_PROFILE_NAME_LEN)
        {
            mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
        }

        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        /* Homepage url */
        //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Homepage:");
        //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_HOMEPAGE));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        memset(buffer, '\0', sizeof(buffer));

        mmi_chset_utf8_to_ucs2_string(
            (U8*) buffer,
            ((PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN - 1) * ENCODING_LENGTH),
            (U8*) profile_content->homepage_url);

        mmi_ucs2cat((PS8) display_info, (S8*) buffer);

        len = mmi_chset_utf8_strlen((U8*) profile_content->homepage_url);
        if (len >= PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN)
        {
            mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
        }

        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        /* Connection Type */
        //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Connection Type:");
        //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_CONN_TYPE));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        if (profile_content->conn_type == PH_CONN_TYPE_HTTP)
        {
            mmi_ucs2cat((PS8) display_info, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
        }
        else if (profile_content->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED
                 || profile_content->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE)
        {
            mmi_ucs2cat((PS8) display_info, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_CONNECTION));
        }
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        /* Data Account */
        //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Data Account:");
        //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_DATA_ACCNT));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        memset(buffer, '\0', sizeof(buffer));

        mmi_dtcnt_get_account_name(profile_content->data_account, (S8*) buffer, MAX_DATA_ACCOUNT_NAME_LEN);

        if (buffer != NULL && buffer[0] != '\0')
        {
            len = mmi_ucs2strlen((S8*) buffer);
            if (len > PROV_MAX_DISPLAY_DATA_ACCNT_NAME_LEN)
            {
                mmi_ucs2ncat((PS8) display_info, buffer, PROV_MAX_DISPLAY_DATA_ACCNT_NAME_LEN);
                mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
            }
            else
            {
                mmi_ucs2cat((PS8) display_info, (S8*) buffer);
            }
        }
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        /* Proxy Server */
        //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Proxy Server:");
        //mmi_ucs2cat((PS8) display_info, buffer);
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_PROXY_SERVER));
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

        sprintf(
            ip_address,
            "%d.%d.%d.%d%c",
            profile_content->proxy_ip[0],
            profile_content->proxy_ip[1],
            profile_content->proxy_ip[2],
            profile_content->proxy_ip[3],
            ':');

        mmi_asc_to_ucs2((S8*) buffer, (S8*) ip_address);
        mmi_ucs2cat((PS8) display_info, (S8*) buffer);

        sprintf(proxy_port, "%d", profile_content->proxy_port);
        mmi_asc_to_ucs2((S8*) buffer, (S8*) proxy_port);
        mmi_ucs2cat((PS8) display_info, (S8*) buffer);

        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
        mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    }

    /* Bookmark Information */
    /* Number of Bookmarks */
    if (temp_bkm_list != NULL)
    {
        mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_BOOKMARKS));
        sprintf(bookmark_title, "%d", mmi_prov_get_bookmark_node_count());
        mmi_asc_to_ucs2((S8*) buffer, (S8*) bookmark_title);
        mmi_ucs2cat((PS8) display_info, buffer);

        while (temp_bkm_list != NULL)
        {
            mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
            mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

            mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_BOOKMARK));
            sprintf(bookmark_title, "%d%c ", index + 1, ':');
            mmi_asc_to_ucs2((S8*) buffer, (S8*) bookmark_title);
            mmi_ucs2cat((PS8) display_info, buffer);
            if (temp_bkm_list->bkm_content->bm_title[0] != '\0')
            {
                memset(buffer, '\0', sizeof(buffer));
                mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

                mmi_chset_utf8_to_ucs2_string(
                    (U8*) buffer,
                    (PROV_MAX_DISPLAY_PROFILE_NAME_LEN * ENCODING_LENGTH),
                    (U8*) temp_bkm_list->bkm_content->bm_title);

                mmi_ucs2cat((PS8) display_info, (S8*) buffer);

                len = mmi_chset_utf8_strlen((U8*) temp_bkm_list->bkm_content->bm_title);

                if (len > PROV_MAX_DISPLAY_PROFILE_NAME_LEN)
                {
                    mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
                }
            }

            memset(buffer, '\0', sizeof(buffer));
            mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

            mmi_chset_utf8_to_ucs2_string(
                (U8*) buffer,
                ((PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN - 1) * ENCODING_LENGTH),
                (U8*) temp_bkm_list->bkm_content->bm_url);

            mmi_ucs2cat((PS8) display_info, (S8*) buffer);

            len = mmi_chset_utf8_strlen((U8*) temp_bkm_list->bkm_content->bm_url);

            if (len >= PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN)
            {
                mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
            }

            index++;
            temp_bkm_list = (prov_bkm_list_struct*) temp_bkm_list->bkm_list_next;
            if ((mmi_ucs2strlen((S8*) display_info) + PROV_MIN_DISPLAY_BKM_INFO_SIZE) > PROV_DISPLAY_INFO_SIZE)
            {
                mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
                mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
                break;
            }
        }   /* End of while */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_display_info_for_mms
 * DESCRIPTION
 *  This API creates a format to display the details of MMS settings
 * PARAMETERS
 *  display_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_create_display_info_for_mms(U8 *display_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 len = 0;
    S8 dotted[] = "...";
    S8 dotted_unicode[PROV_DOT_SIZE];
    S8 new_line[] = "\n";
    U8 new_line_info[PROV_NEW_LINE_SIZE];
    S8 profile_count[PROV_COUNT_SIZE];
    S8 ip_address[PROV_IP_ADDRESS_LEN];
    S8 proxy_port[PROV_MAX_PROXY_PORT_LENGTH];

    S8 buffer[(PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN * ENCODING_LENGTH)];
    nvram_mms_profile_content_struct *profile_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_create_display_info_for_mms");
    ASSERT(g_prov_cntx.mms_profile_list);
    profile_content = g_prov_cntx.mms_profile_list->profile_content;
    mmi_asc_to_ucs2((S8*) new_line_info, (S8*) new_line);
    mmi_asc_to_ucs2((S8*) dotted_unicode, (S8*) dotted);

    /* App Name */
    mmi_ucs2cpy((PS8) display_info, GetString(STR_ID_CCA_MMS));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    /* Number of profiles */
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_CCA_PROFILE));

    sprintf(
        profile_count,
        "%c %d/%d",
        ':',
        ((g_prov_cntx.profile_count - mmi_prov_get_profile_node_count()) + 1),
        g_prov_cntx.profile_count);
    mmi_asc_to_ucs2((S8*) buffer, (S8*) profile_count);
    mmi_ucs2cat((PS8) display_info, (S8*) buffer);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Profile Name:");
    //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_PROFILE_NAME));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    memset(buffer, '\0', sizeof(buffer));

    mmi_chset_utf8_to_ucs2_string(
        (U8*) buffer,
        (PROV_MAX_DISPLAY_PROFILE_NAME_LEN * ENCODING_LENGTH),
        (U8*) g_prov_cntx.mms_profile_list->profile_name);

    mmi_ucs2cat((PS8) display_info, (S8*) buffer);

    len = mmi_chset_utf8_strlen((U8*) g_prov_cntx.mms_profile_list->profile_name);

    if (len > PROV_MAX_DISPLAY_PROFILE_NAME_LEN)
    {
        mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
    }

    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    /* Homepage url */
    //mmi_asc_to_ucs2((S8*) buffer, (S8*) "MMSC Address:");
    //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_MMSC_ADD));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    memset(buffer, '\0', sizeof(buffer));

    mmi_chset_utf8_to_ucs2_string(
        (U8*) buffer,
        ((PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN - 1) * ENCODING_LENGTH),
        (U8*) profile_content->mmsc_url);

    mmi_ucs2cat((PS8) display_info, (S8*) buffer);

    len = mmi_chset_utf8_strlen((U8*) profile_content->mmsc_url);

    if (len >= PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN)
    {
        mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
    }

    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    /* Connection Type */
    //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Connection Type:");
    // mmi_ucs2cat((PS8) display_info, (S8*) buffer);
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_CONN_TYPE));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    if (profile_content->conn_type == PH_CONN_TYPE_HTTP)
    {
        mmi_ucs2cat((PS8) display_info, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
    }
    else if (profile_content->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED
             || profile_content->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE)
    {
        mmi_ucs2cat((PS8) display_info, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_CONNECTION));
    }
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    /* Data Account */
    //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Data Account:");
    //mmi_ucs2cat((PS8) display_info, (S8*) buffer);
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_DATA_ACCNT));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    memset(buffer, '\0', sizeof(buffer));
    mmi_dtcnt_get_account_name(profile_content->data_account, (S8*) buffer, MAX_DATA_ACCOUNT_NAME_LEN);
    if (buffer != NULL && buffer[0] != '\0')
    {
        len = mmi_ucs2strlen((S8*) buffer);
        if (len > PROV_MAX_DISPLAY_DATA_ACCNT_NAME_LEN)
        {
            mmi_ucs2ncat((PS8) display_info, buffer, PROV_MAX_DISPLAY_DATA_ACCNT_NAME_LEN);
            mmi_ucs2cat((PS8) display_info, (S8*) dotted_unicode);
        }
        else
        {
            mmi_ucs2cat((PS8) display_info, (S8*) buffer);
        }
    }
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    /* Proxy Server */
    //mmi_asc_to_ucs2((S8*) buffer, (S8*) "Proxy Server:");
    //mmi_ucs2cat((PS8) display_info, buffer);
    mmi_ucs2cat((PS8) display_info, GetString(STR_ID_PROV_CCA_PROXY_SERVER));
    mmi_ucs2cat((PS8) display_info, (S8*) new_line_info);

    sprintf(
        ip_address,
        "%d.%d.%d.%d%c",
        profile_content->proxy_ip[0],
        profile_content->proxy_ip[1],
        profile_content->proxy_ip[2],
        profile_content->proxy_ip[3],
        ':');

    mmi_asc_to_ucs2((S8*) buffer, (S8*) ip_address);
    mmi_ucs2cat((PS8) display_info, buffer);

    sprintf(proxy_port, "%d", profile_content->proxy_port);
    mmi_asc_to_ucs2((S8*) buffer, (S8*) proxy_port);
    mmi_ucs2cat((PS8) display_info, (S8*) buffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_install_setting
 * DESCRIPTION
 *  Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_install_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 profile_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_install_setting");
    profile_count = (g_prov_cntx.profile_count - mmi_prov_get_profile_node_count()) + 1;
    if (g_prov_cntx.prov_type == PROV_BRS_SETTINGS)
    {
        mmi_ph_install_brw_profile(g_prov_cntx.wap_profile_list, g_prov_cntx.bkm_list, profile_count);
    }
    else if (g_prov_cntx.prov_type == PROV_MMS_SETTINGS)
    {
        mmi_ph_install_mms_profile(g_prov_cntx.mms_profile_list, profile_count);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_skip_profile
 * DESCRIPTION
 *  Skip the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_skip_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel(STR_ID_CCA_SKIP_PROFILE, mmi_prov_skip_profile_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_skip_profile_callback
 * DESCRIPTION
 *  callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_skip_profile_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_show_next_profile_info(MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_show_next_profile_info
 * DESCRIPTION
 *  Show next profile if left
 * PARAMETERS
 *  prof_screen_exist       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_show_next_profile_info(MMI_BOOL prof_screen_exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    PROV_RETCODE retcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_show_next_profile_info");
    mmi_prov_update_profile_node_list();
    mmi_prov_free_bookmark_nodes();
    count = mmi_prov_get_profile_node_count();
    if (!count) /* No profile left */
    {
        /* check at least 1 profile should installed successfully */
        retcode = mmi_ph_get_setting_installed_flag();
        if (retcode == PROV_OK)
        {
            mmi_prov_send_response(CCA_STATUS_OK);
        }
        else if (retcode == PROV_SETTING_SKIPPED)
        {
            mmi_prov_send_response(CCA_STATUS_SETTING_SKIPPED);
        }
        else if (retcode == PROV_ERR)
        {
            mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
        }
    }
    if (prof_screen_exist && (!count))
    {
        GoBacknHistory(1);
    }
    else if (prof_screen_exist || (!count))
    {
        GoBackHistory();
    }
    else
    {
        mmi_prov_entry_show_setting_info();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_send_response
 * DESCRIPTION
 *  This API sends the status of the profile whether it is being installed succesfully,skipped or Invalid profile
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_send_response(cca_status_enum status)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cca_app_configure_rsp_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_prov_send_response");

    ASSERT(g_prov_cntx.config_id && g_prov_cntx.config_h);
    ASSERT(!
           (g_prov_cntx.proxy_list || g_prov_cntx.app_list || g_prov_cntx.bkm_list || g_prov_cntx.wap_profile_list ||
            g_prov_cntx.mms_profile_list));
    mmi_ph_reset_flags();

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = PRT_MMI_CCA_APP_CONFIGURE_RSP;

    local_data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

    local_data->config_id = g_prov_cntx.config_id;
    local_data->hConfig = g_prov_cntx.config_h;
    local_data->status = status;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;

    g_prov_cntx.config_id = 0;
    g_prov_cntx.config_h = 0;

    OslMsgSendExtQueue(&Message);

}

#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* _JPROVISIONING_C */ 

