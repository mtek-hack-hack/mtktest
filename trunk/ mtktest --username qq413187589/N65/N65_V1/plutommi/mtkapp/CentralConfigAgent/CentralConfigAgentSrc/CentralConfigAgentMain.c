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
 *  CentralConfigAgentMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Main: primitive handlers / memory management / init / deinit
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

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/

#include "CentralConfigAgentGProt.h"

#include "ProtocolEvents.h"

#include "kal_active_module.h"

/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
#define CCA_MAX_MEM_SIZE    1024*10
#define CCA_MAX_MEMFULL_CB  CCA_MFID_SIZE

/* static varaibles declaration */
static U8 cca_mempool_g[CCA_MAX_MEM_SIZE];
static KAL_ADM_ID cca_admid_g;
static S32 cca_mempool_max_alloc;
static S32 cca_mempool_total_left;
static U8 cca_log_enabled = 0;

/* global varaibles declaration */
cca_context_struct cca_context_g;
static CCA_FP_MEMFULL_CB cca_memfull_cb[CCA_MAX_MEMFULL_CB];


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_init
 * DESCRIPTION
 *  CCA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_INIT_BEGIN);

    cca_admid_g = kal_adm_create((void*)cca_mempool_g, (kal_uint32)CCA_MAX_MEM_SIZE, NULL, (kal_bool)KAL_FALSE);

    cca_mempool_max_alloc = kal_adm_get_max_alloc_size(cca_admid_g);
    cca_mempool_total_left = kal_adm_get_total_left_size(cca_admid_g);
    
    memset(cca_memfull_cb, 0, sizeof(CCA_FP_MEMFULL_CB)*CCA_MAX_MEMFULL_CB);

    ASSERT(cca_admid_g);

    /* set protocol event handlers */
    SetProtocolEventHandler(mmi_cca_app_configure_ind_hdlr, PRT_MMI_CCA_APP_CONFIGURE_IND);
    SetProtocolEventHandler(mmi_cca_app_configure_rsp_hdlr, PRT_MMI_CCA_APP_CONFIGURE_RSP);
    SetProtocolEventHandler(mmi_cca_source_new_doc_ind_hdlr, PRT_MMI_CCA_SOURCE_NEW_DOC_IND);
    SetProtocolEventHandler(mmi_cca_source_ui_invalid_setting_ind_hdlr, PRT_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND);
    SetProtocolEventHandler(mmi_cca_source_ui_new_setting_ind_hdlr, PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_IND);
    SetProtocolEventHandler(mmi_cca_source_ui_new_setting_rsp_hdlr, PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP);
    SetProtocolEventHandler(mmi_cca_source_ui_auth_ind_hdlr, PRT_MMI_CCA_SOURCE_UI_AUTH_IND);
    SetProtocolEventHandler(mmi_cca_new_doc_continue_ind_hdlr, PRT_MMI_CCA_NEW_DOC_CONTINUE_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_cca_get_prof_ind_hdlr, PRT_MMI_CCA_GET_PROF_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_cca_update_prof_ind_hdlr, PRT_MMI_CCA_UPDATE_PROF_IND);
    SetProtocolEventHandler(mmi_cca_app_get_prof_rsp_hdlr, PRT_MMI_CCA_APP_GET_PROF_RSP);
    SetProtocolEventHandler(mmi_cca_app_update_prof_rsp_hdlr, PRT_MMI_CCA_APP_UPDATE_PROF_RSP);
    SetProtocolEventHandler(mmi_cca_app_get_prof_ind_hdlr, PRT_MMI_CCA_APP_GET_PROF_IND);
    SetProtocolEventHandler(mmi_cca_app_update_prof_ind_hdlr, PRT_MMI_CCA_APP_UPDATE_PROF_IND);

    mmi_cca_reset_context();

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_INIT_END);
    mmi_cca_log_enable(1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_reset
 * DESCRIPTION
 *  CCA reset function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_RESET);

    mmi_cca_log_enable(0);
    if (kal_adm_delete(cca_admid_g) != KAL_SUCCESS)
        ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_malloc
 * DESCRIPTION
 *  CCA malloc function
 * PARAMETERS
 *  size    [in]
 * RETURNS
 *  malloc'd pointer (0 if mem full)
 *****************************************************************************/
void* mmi_cca_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(cca_admid_g, (kal_uint32)size);
    cca_mempool_max_alloc = kal_adm_get_max_alloc_size(cca_admid_g);
    cca_mempool_total_left = kal_adm_get_total_left_size(cca_admid_g);

    if (!ptr)
    {
        mmi_cca_trigger_memfull_notify();
        MMI_TRACE(CCA_TRACE_ERROR, MMI_CCA_MALLOC_MEMORY_INFO, size, cca_mempool_max_alloc, cca_mempool_total_left);
        MMI_TRACE(CCA_TRACE_ERROR, MMI_CCA_MALLOC_NULL);
     }

    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_mfree
 * DESCRIPTION
 *  CCA mfree function
 * PARAMETERS
 *  ptr    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_mfree(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(cca_admid_g, ptr);
    cca_mempool_max_alloc = kal_adm_get_max_alloc_size(cca_admid_g);
    cca_mempool_total_left = kal_adm_get_total_left_size(cca_admid_g);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_register_memfull_notify
 * DESCRIPTION
 *  register a callback func to be triggered when CCA mem full
 * PARAMETERS
 *  callback    [in]
 *  identifier  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_register_memfull_notify(CCA_FP_MEMFULL_CB callback, U8 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(identifier < CCA_MAX_MEMFULL_CB);
    cca_memfull_cb[identifier] = callback;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_deregister_memfull_notify
 * DESCRIPTION
 *  deregister a memfull callback func
 * PARAMETERS
 *  identifier  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_deregister_memfull_notify(U8 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(identifier < CCA_MAX_MEMFULL_CB);
    cca_memfull_cb[identifier] = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_trigger_memfull_notify
 * DESCRIPTION
 *  trigger all memfull notify func
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_trigger_memfull_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<CCA_MAX_MEMFULL_CB; i++)
        if (cca_memfull_cb[i])
            cca_memfull_cb[i]((U8)i);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_log_enable
 * DESCRIPTION
 *  enable or disable CCA log
 * PARAMETERS
 *  enable  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_log_enable(U8 enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cca_log_enabled = enable;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_enable_log
 * DESCRIPTION
 *  enable or disable CCA log
 * PARAMETERS
 *  enable  [in]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_cca_log_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cca_log_enabled;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_reset_provisioning_context
 * DESCRIPTION
 *  reset provisioning context parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_reset_provisioning_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_RESET_PROVISIONING_CONTEXT);

    if (cca_context_g.hConfig)
    {
        mmi_cca_doc_release(cca_context_g.hConfig);
        cca_context_g.hConfig = 0;
    }
    cca_context_g.sim_id = MMI_CCA_SIM_ID_DEFAULT;
    cca_context_g.specId = 0;
    cca_context_g.crtConfigIndex = 0;
    cca_context_g.numApp = 0;
    kal_mem_set(cca_context_g.configResult, 0, sizeof(cca_app_config_result_struct)*CCA_MAX_APPS);

    cca_context_g.state = CCA_STATE_IDLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_has_provisioning_context
 * DESCRIPTION
 *  check if provisioning context parameters exists
 * PARAMETERS
 *  void
 * RETURNS
 *  0       no provisoning context
 *  1       has provisoning context
 *****************************************************************************/
U8 mmi_cca_has_provisioning_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_HAS_PROVISIONING_CONTEXT, (cca_context_g.hConfig!=0));

    return (cca_context_g.hConfig!=0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_start_provisioning_job
 * DESCRIPTION
 *  execute the provisioning job
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_start_provisioning_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_START_PROVISIONING_JOB, cca_context_g.state);

    ASSERT(cca_context_g.hConfig);

    cca_context_g.state = CCA_STATE_PROVISIONING;
    switch (cca_context_g.specId)
    {
        case CCA_SPEC_OMA:
            mmi_cca_oma_handle_new_doc(cca_context_g.hConfig);
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_reset_async_context
 * DESCRIPTION
 *  reset asynchronous event context parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_reset_async_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*---------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_RESET_ASYNC_CONTEXT);

    cca_context_g.src_mod_id = MOD_NIL;
    cca_context_g.sim_id = MMI_CCA_SIM_ID_DEFAULT;
    cca_context_g.appId = 0;
    cca_context_g.profId = 0;
    cca_context_g.asynchConfig = 0;  // do not free this document as it'll be used & freed by caller module
    cca_context_g.oper = CCA_OPER_NULL;
    cca_context_g.state = CCA_STATE_IDLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_has_async_context
 * DESCRIPTION
 *  check if exists any asynchronous context parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  0       no async context
 *  1       has async context
 *****************************************************************************/
U8 mmi_cca_has_async_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_HAS_ASYNC_CONTEXT, cca_context_g.oper);

    return (cca_context_g.oper != CCA_OPER_NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_start_async_job
 * DESCRIPTION
 *  execute the asynchronous job (eg, get/update profile)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_start_async_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_START_ASYNC_JOB, 
        cca_context_g.src_mod_id, cca_context_g.state, cca_context_g.oper);
    
    ASSERT(cca_context_g.oper != CCA_OPER_NULL);

    cca_context_g.state = CCA_STATE_ASYNC;
    switch (cca_context_g.oper)
    {
        case CCA_OPER_GET:
            mmi_cca_send_cca_app_get_prof_ind(cca_context_g.sim_id, cca_context_g.appId, cca_context_g.profId);
            break;

        case CCA_OPER_UPDATE:
            mmi_cca_send_cca_app_update_prof_ind(cca_context_g.sim_id, cca_context_g.appId, cca_context_g.profId, cca_context_g.asynchConfig);
            break;

        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_reset_context
 * DESCRIPTION
 *  reset CCA global context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_RESET_CONTEXT);

    mmi_cca_reset_provisioning_context();
    mmi_cca_reset_async_context();
    cca_context_g.state = CCA_STATE_IDLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_has_queued_job
 * DESCRIPTION
 *  check whether there exists queued job(s)
 *  caller must ensure the relevant context parameters in previous job are cleaned
 *  and have state set to CCA_STATE_IDLE
 * PARAMETERS
 *  void
 * RETURNS
 *  0       no more job
 *  1       has queued job
 *****************************************************************************/
U8 mmi_cca_has_queued_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_HAS_QUEUED_JOB);

    return (mmi_cca_has_provisioning_context() || mmi_cca_has_async_context());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_do_next_queued_job
 * DESCRIPTION
 *  execute the next queued job
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_do_next_queued_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_DO_NEXT_QUEUED_JOB);

    if (mmi_cca_has_provisioning_context())
    {
        mmi_cca_start_provisioning_job();
        return;
    }

    if (mmi_cca_has_async_context())
    {
        mmi_cca_start_async_job();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_new_config_result
 * DESCRIPTION
 *  add new config result entry to context
 * PARAMETERS
 *  config_id       [in]
 *  result          [in]
 * RETURNS
 *  -1      config_id not found
 *  otherwise the index at which entry was added
 *****************************************************************************/
int mmi_cca_new_config_result(U16 config_id, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_NEW_CONFIG_RESULT, config_id, result);

    for (i=0; i<cca_context_g.numApp; i++)
    {
        if (cca_context_g.configResult[i].config_id == config_id)
        {
            MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_NEW_CONFIG_RESULT_ERROR_EXIST);
            return -1;
        }
    }

    ASSERT(cca_context_g.numApp < CCA_MAX_APPS);

    cca_context_g.configResult[cca_context_g.numApp].result = result;
    cca_context_g.configResult[cca_context_g.numApp].config_id = config_id;
    cca_context_g.numApp++;

    return cca_context_g.numApp-1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_get_config_result
 * DESCRIPTION
 *  retrieve config result given a config_id
 * PARAMETERS
 *  config_id       [in]
 * RETURNS
 *  CCA_STATUS_NOT_FOUND      config_id not found
 *  otherwise the stored config result
 *****************************************************************************/
cca_status_enum mmi_cca_get_config_result(U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO,  MMI_CCA_GET_CONFIG_RESULT, config_id);

    for (i=0; i<cca_context_g.numApp; i++)
        if (cca_context_g.configResult[i].config_id == config_id)
            return cca_context_g.configResult[i].result;

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CONFIG_RESULT_ERROR_CONFIG_ID_NOT_FOUND);

    return CCA_STATUS_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_update_config_result
 * DESCRIPTION
 *  update the config result entry in context
 * PARAMETERS
 *  config_id       [in]
 *  result          [in]
 * RETURNS
 *  0       config_id not found
 *  1       config result updated
 *****************************************************************************/
U8 mmi_cca_update_config_result(U16 config_id, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_UPDATE_CONFIG_RESULT, config_id,result);

    for (i=0; i<cca_context_g.numApp; i++)
    {
        if (cca_context_g.configResult[i].config_id == config_id)
        {
            cca_context_g.configResult[i].result = result;
            return 1;
        }
    }

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CONFIG_RESULT_ERROR_CONFIG_ID_NOT_FOUND);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_configure_complete
 * DESCRIPTION
 *  reset content + send indication to source
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_configure_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CONFIG_COMPLETE);
    
    /* send new_doc_res to source */
    mmi_cca_send_source_new_doc_rsp();

    /* reset provisioning context */
    mmi_cca_reset_provisioning_context();

    /* do next queued job if exists */
    if (mmi_cca_has_queued_job())
        mmi_cca_do_next_queued_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_configure_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_APP_CONFIGURE_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_configure_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_dispatch_mmi_cca_app_configure_ind((mmi_cca_app_configure_ind_struct*)msg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_configure_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_APP_CONFIGURE_RSP handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_configure_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_configure_rsp_struct*)msg;

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_CONFIG_RSP_HDLR, data->config_id, data->status);

    //MMI_CCA_LOG_DOC(data->hConfig);

    switch (data->status)
    {
        case CCA_STATUS_OK:
        case CCA_STATUS_INVALID_SETTING:
        case CCA_STATUS_SETTING_SKIPPED:
            ASSERT(cca_context_g.numApp>0 && cca_context_g.numApp<=CCA_MAX_APPS);
            if (!mmi_cca_update_config_result(data->config_id, data->status))
                ASSERT(0);

            if (mmi_cca_oma_is_memfull_during_app_configure() && data->status!=CCA_STATUS_OK)
                mmi_cca_update_config_result(data->config_id, CCA_STATUS_SETTING_SKIPPED);

            //switch (data->config_id & 0xFF00)
            switch (CCA_GET_SPEC(data->config_id))
            {
                case CCA_SPEC_OMA:
                    mmi_cca_oma_new_doc_process_next_app();
                    break;

                default:
                    break;
            }
            break;

        case CCA_STATUS_ENDKEY_PRESSED:
            mmi_cca_configure_complete();
            //mmi_cca_ui_handle_endkey();
            break;

        default:
            MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_CONFIG_RSP_HDLR_DEFAULT_STATUS);
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_source_new_doc_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_source_new_doc_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_new_doc_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_source_new_doc_ind_struct*)msg;

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SOURCE_NEW_DOC_IND_HDLR, data->spec_id, data->hConfig);

    if (data->hConfig == 0)
    {
        mmi_cca_send_source_new_doc_rsp();
        return;
    }

    /* fill provisioning context */
    cca_context_g.sim_id = data->sim_id;
    cca_context_g.specId = data->spec_id;
    cca_context_g.hConfig = data->hConfig;
    cca_context_g.crtConfigIndex = 0;
    memset(cca_context_g.configResult, 0, CCA_MAX_APPS*sizeof(cca_app_config_result_struct));
    cca_context_g.numApp = 0;

    if (cca_context_g.state != CCA_STATE_IDLE)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SOURCE_NEW_DOC_IND_HDLR_BUSY, cca_context_g.state);
        return;
    }

    mmi_cca_start_provisioning_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_new_doc_continue_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_NEW_DOC_CONTINUE_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_new_doc_continue_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_context_g.specId)
    {
        case CCA_SPEC_OMA:
            mmi_cca_oma_new_doc_continue();
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_get_prof_ind_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_GET_PROF_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_get_prof_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    mmi_cca_get_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_get_prof_ind_struct*)local_param;

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_GET_PROF_IND_HDLR, ilm_info->src_mod_id, data->app_id, data->prof_id);

    if (cca_context_g.state != CCA_STATE_IDLE)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_GET_PROF_IND_HDLR_BUSY, cca_context_g.state);

        mmi_cca_send_cca_get_prof_rsp(ilm_info->src_mod_id, data->sim_id, data->app_id, data->prof_id, 0, CCA_STATUS_CCA_BUSY);
        return;
    }

    cca_context_g.src_mod_id = ilm_info->src_mod_id;
    cca_context_g.sim_id = data->sim_id;
    cca_context_g.appId = data->app_id;
    cca_context_g.profId = data->prof_id;
    cca_context_g.oper = CCA_OPER_GET;

    cca_context_g.state = CCA_STATE_ASYNC;
    mmi_cca_start_async_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_update_prof_ind_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_UPDATE_PROF_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_update_prof_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    mmi_cca_update_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_update_prof_ind_struct*)local_param;

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_UPDATE_PROF_IND_HDLR, 
        ilm_info->src_mod_id, data->app_id, data->prof_id, data->hConfig);

    if (cca_context_g.state != CCA_STATE_IDLE)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_UPDATE_PROF_IND_HDLR_BUSY, cca_context_g.state);

        mmi_cca_send_cca_update_prof_rsp(ilm_info->src_mod_id, data->sim_id, data->app_id, data->prof_id, data->hConfig, CCA_STATUS_CCA_BUSY);
        return;
    }

    cca_context_g.src_mod_id = ilm_info->src_mod_id;
    cca_context_g.sim_id = data->sim_id;
    cca_context_g.appId = data->app_id;
    cca_context_g.profId = data->prof_id;
    cca_context_g.asynchConfig = data->hConfig;
    cca_context_g.oper = CCA_OPER_UPDATE;

    cca_context_g.state = CCA_STATE_ASYNC;
    mmi_cca_start_async_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_get_prof_rsp_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_APP_GET_PROF_RSP handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_get_prof_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_get_prof_rsp_struct*)msg;

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_GET_PROF_RSP_HDLR_CCA_STATE, cca_context_g.state,cca_context_g.oper);
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_GET_PROF_RSP_HDLR_DATA_INFO, 
        data->app_id, data->prof_id, data->hConfig, data->result);

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    ASSERT(cca_context_g.state == CCA_STATE_ASYNC);
    ASSERT(cca_context_g.oper == CCA_OPER_GET);
    ASSERT(cca_context_g.src_mod_id != MOD_NIL);
    mmi_cca_send_cca_get_prof_rsp(cca_context_g.src_mod_id, data->sim_id, data->app_id, data->prof_id, data->hConfig, data->result);

    /* reset async context */
    mmi_cca_reset_async_context();

    /* do next queued job if exists */
    if (mmi_cca_has_queued_job())
        mmi_cca_do_next_queued_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_update_prof_rsp_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_APP_UPDATE_PROF_RSP handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_update_prof_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_update_prof_rsp_struct*)msg;

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_UPDATE_PROF_RSP_HDLR_CCA_STATE, cca_context_g.state,cca_context_g.oper);
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_APP_UPDATE_PROF_RSP_HDLR_DATA_INFO, 
        data->app_id, data->prof_id, data->hConfig,data->result);

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    ASSERT(cca_context_g.state == CCA_STATE_ASYNC);
    ASSERT(cca_context_g.oper == CCA_OPER_UPDATE);
    ASSERT(cca_context_g.src_mod_id != MOD_NIL);
    mmi_cca_send_cca_update_prof_rsp(cca_context_g.src_mod_id, data->sim_id, data->app_id, data->prof_id, data->hConfig, data->result);

    /* reset async context */
    mmi_cca_reset_async_context();

    /* do next queued job if exists */
    if (mmi_cca_has_queued_job())
        mmi_cca_do_next_queued_job();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_get_prof_ind_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_APP_GET_PROF_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_get_prof_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_dispatch_mmi_profile_operations(CCA_OPER_GET, ((mmi_cca_app_get_prof_ind_struct*)msg)->app_id, msg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_app_update_prof_ind_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_APP_UPDATE_PROF_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_app_update_prof_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_update_prof_ind_struct*)msg;
    ASSERT(data->hConfig);
    mmi_cca_dispatch_mmi_profile_operations(CCA_OPER_UPDATE, data->app_id, msg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_app_configure_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_CONFIGURE_IND
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_app_configure_ind(U16 sim_id, U16 config_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    mmi_cca_app_configure_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_APP_CONFIG_IND, config_id, hConfig, cca_context_g.crtConfigIndex);

    data = (mmi_cca_app_configure_ind_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_configure_ind_struct));
    data->sim_id = sim_id;
    data->config_id = config_id;
    data->hConfig = hConfig;
    ((cca_document_struct*)hConfig)->config_id = config_id;
    ((cca_document_struct*)hConfig)->dtAcctIDAdded = 0;

    kal_mem_set(data->l1symbols, 0, CCA_TREE_MAX_CHILDS*sizeof(U16));
    kal_mem_set(data->l1symbols_count, 0, CCA_TREE_MAX_CHILDS*sizeof(U16));
    mmi_cca_oma_construct_l1symbols(hConfig, CCA_TREE_MAX_CHILDS, &(data->num_symbols), data->l1symbols, data->l1symbols_count);

    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = mmi_cca_get_module_id_by_config(config_id);
    ilm.oslSapId = 0;   /* CCA_SOURCE_SAP */
    ilm.oslMsgId = PRT_MMI_CCA_APP_CONFIGURE_IND;
    ilm.oslDataPtr = (oslParaType*)data;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_new_doc_continue_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_NEW_DOC_CONTINUE_IND
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_new_doc_continue_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_NEW_DOC_CONTINUE_IND);

    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = MOD_MMI;
    ilm.oslSapId = 0;   /* CCA_SOURCE_SAP */
    ilm.oslMsgId = PRT_MMI_CCA_NEW_DOC_CONTINUE_IND;
    ilm.oslDataPtr = 0;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_source_new_doc_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_NEW_DOC_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_source_new_doc_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_SOURCE_NEW_DOC_RSP);

    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = MOD_WAP;
    ilm.oslSapId = 0;   /* CCA_SOURCE_SAP */
    ilm.oslMsgId = PRT_MMI_CCA_SOURCE_NEW_DOC_RSP;
    ilm.oslDataPtr = 0;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_source_ui_new_setting_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_source_ui_new_setting_rsp(S32 trans_id, U16 sim_id, cca_status_enum response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    mmi_cca_source_ui_new_setting_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_SOURCE_UI_NEW_SETTING_RSP, trans_id, response);
    
    data = (mmi_cca_source_ui_new_setting_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_source_ui_new_setting_rsp_struct));
    data->trans_id = trans_id;
    data->sim_id = sim_id;
    data->response = response;

    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = MOD_WAP;
    ilm.oslSapId = 0;   /* CCA_SOURCE_SAP */
    ilm.oslMsgId = PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP;
    ilm.oslDataPtr = (oslParaType*)data;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_source_ui_auth_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_SOURCE_UI_AUTH_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_source_ui_auth_rsp(S32 trans_id, S8 *pin, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    mmi_cca_source_ui_auth_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    data = (mmi_cca_source_ui_auth_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_source_ui_auth_rsp_struct));
    data->trans_id = trans_id;
    data->status = status;
    kal_mem_set(data->pin, 0, CCA_MAX_PIN_CHARS+1);
    if (pin)
        strncpy(data->pin, pin, CCA_MAX_PIN_CHARS);

    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = MOD_WAP;
    ilm.oslSapId = 0;   /* CCA_SOURCE_SAP */
    ilm.oslMsgId = PRT_MMI_CCA_SOURCE_UI_AUTH_RSP;
    ilm.oslDataPtr = (oslParaType*)data;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_app_configure_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_CONFIGURE_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_app_configure_rsp(U16 sim_id, U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_APP_CONFIGURE_RSP,
        conf_id, doc_hdl, status);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
    data->sim_id = sim_id;
    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_get_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_GET_PROF_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_get_prof_rsp(module_type dest_mod_id, U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_get_prof_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_GET_PROF_RSP, 
        dest_mod_id, app_id, prof_id, hConfig, result);
    
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_get_prof_rsp_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = dest_mod_id;
    message.oslMsgId        = PRT_MMI_CCA_GET_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_app_get_prof_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_GET_PROF_IND
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_app_get_prof_ind(U16 sim_id, U16 app_id, S32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_get_prof_ind_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_APP_GET_PROF_IND, app_id, prof_id);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_ind_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_ind_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = mmi_cca_get_module_id_by_app(app_id);
    message.oslMsgId        = PRT_MMI_CCA_APP_GET_PROF_IND;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_update_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_UPDATE_PROF_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_update_prof_rsp(module_type dest_mod_id, U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_update_prof_rsp_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_UPDATE_PROF_RSP, 
        dest_mod_id, app_id, prof_id, hConfig, result);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_update_prof_rsp_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = dest_mod_id;
    message.oslMsgId        = PRT_MMI_CCA_UPDATE_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_app_update_prof_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_app_update_prof_ind(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_update_prof_ind_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_APP_UPDATE_PROF_IND, app_id, prof_id, hConfig);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_update_prof_ind_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_ind_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = mmi_cca_get_module_id_by_app(app_id);
    message.oslMsgId        = PRT_MMI_CCA_APP_UPDATE_PROF_IND;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_app_get_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_GET_PROF_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_app_get_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_get_prof_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_APP_GET_PROF_RSP, 
        app_id, prof_id, hConfig, result);
    
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    /* Send the response message. */
    message.oslSrcId        = stack_get_active_module_id();;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_GET_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_send_cca_app_update_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_send_cca_app_update_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_update_prof_rsp_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_SEND_CCA_APP_UPDATE_PROF_RSP, app_id, prof_id, hConfig, result);
    
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    /* Send the response message. */
    message.oslSrcId        = stack_get_active_module_id();;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_UPDATE_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_is_ascii_string
 * DESCRIPTION
 *  check if string is ASCII string
 * PARAMETERS
 *  
 * RETURNS
 *  0       Not ASCII
 *  1       ASCII string
 *****************************************************************************/
U8 mmi_cca_is_ascii_string(const S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while (*str != 0)
    {
        if (*str > 0x7F)
            return 0;
        str++;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_revise_sim_id
 * DESCRIPTION
 *  revise the sim_id
 * PARAMETERS
 *  sim_id    SIM id
 * RETURNS
 *  new sim_id
 *****************************************************************************/
U16 mmi_cca_revise_sim_id(U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifndef __MMI_DUAL_SIM__
   return MMI_CCA_SIM_ID_DEFAULT;
#else
    if (sim_id != MMI_CCA_SIM_ID_DEFAULT && 
        sim_id != MMI_CCA_SIM_ID_SIM1 && 
        sim_id != MMI_CCA_SIM_ID_SIM2)
    {
       return MMI_CCA_SIM_ID_DEFAULT;
    }
    return sim_id;
#endif /* __MMI_DUAL_SIM__ */
}


#endif  /* __MMI_CCA_SUPPORT__ */



