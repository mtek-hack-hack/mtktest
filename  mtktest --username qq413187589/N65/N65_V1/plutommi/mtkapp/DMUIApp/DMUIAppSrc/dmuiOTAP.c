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
*	dmuiOTAP.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file for DM provisioning.
*
* Author:
* -------
*	XiangJun Dan (mbj06013)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_SYNCML_DM_OTAP__


#include "DMGprot.h"

#include "dmuiappdef.h"
#include "dmuiprot.h"

#include "SettingProfile.h"
#include "IdleAppDef.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"

/* URL check function head file */
#include "app_url.h"

#include "CentralConfigAgentGProt.h"    /* CCA header */

/***************************************************************************** 
* Global Variable
*****************************************************************************/
syncml_dm_ota_context_struct syncml_dm_ota_context;
syncml_dm_ota_context_struct *g_syncml_dm_ota_context = &syncml_dm_ota_context;

static U8 gui_valid_flag = 0;
/***************************************************************************** 
* External Variable
*****************************************************************************/
extern dmui_context_struct *ptr_dmui_context;

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void playRequestedTone(ALL_TONE_ENUM);

extern void mmi_dm_print_info(dm_account_struct * ptr_dm_account);

/*****************************************************************************
* Local Function 
*****************************************************************************/
static MMI_BOOL Is_ANSII_format(S8 *dest);
static void mmi_syncml_dm_ansii2unicode(S8 *pOutBuffer, S8 *pInBuffer, U32 len);

static S16 mmi_syncml_dm_new_otap_proxy(syncml_dm_ota_context_struct *cntx);
static void mmi_syncml_dm_free_otap_proxy(void);

/* init DM server id list and primary server id */
static void mmi_syncml_dm_init_data(void);

/* END key when display SYNCML setting information */
static U8 mmi_syncml_dm_exit_install(void* in_param);

/* find empty profile exist or not */
static void mmi_syncml_dm_find_empty_profile(void);

/* when user select skip in display screen and pop up this confirm window */
static void mmi_syncml_dm_display_skip_confirm(void);

/* entry a process of install profile */
static void mmi_syncml_dm_install_profile(void);

/* function to receive node data from CCA */
static cca_status_enum mmi_syncml_dm_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data);

/* entry replace screen */
static void mmi_syncml_dm_entry_replacement(void);

/* get valid profile number */
static U8 mmi_syncml_dm_get_valid_profile_num(void);

/* display server id list */
static void mmi_syncml_dm_server_id_list(void);

/* high light and select function in server id list */
static void mmi_syncml_dm_server_id_list_select(S32 index);

/* replace server id function */
static void mmi_syncml_dm_replace_profile(void);

/* send update profile result message to CCA */
static void mmi_syncml_dm_send_cca_update_prof_end(cca_status_enum status);

/* send get profile result message to CCA */
static void mmi_syncml_send_cca_dm_get_profile(cca_status_enum status);

/* send status to CCA application */
static void mmi_dmui_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status);
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document 
 *  relevant to SYNCML DM
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the SYNCML settings for each profile.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY, 
            CCA_NS_SYNCML_DM_PROXY,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PORT, 
            CCA_NS_SYNCML_DM_PORT,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PXAUTHINFO, 
            CCA_NS_SYNCML_DM_PXAUTHINFO,0xFFFF,            
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION, 
            CCA_NS_SYNCML_DM_APPLICATION,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPADDR,
            CCA_NS_SYNCML_DM_APPADDR,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_PORT,
            CCA_NS_SYNCML_DM_APPPORT,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPAUTH, 
            CCA_NS_SYNCML_DM_APPAUTH,0xFFFF
    };
  
    cca_status_enum status;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_proc_cca_doc(), conf_id = %d , doc_hdl= %d", conf_id,doc_hdl);

    if (g_syncml_dm_ota_context == NULL) 
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]CCA_STATUS_FAIL");
        return;
    }
    
    memset(g_syncml_dm_ota_context, 0x00, sizeof(syncml_dm_ota_context_struct));

    g_syncml_dm_ota_context->conf_id = conf_id;
    g_syncml_dm_ota_context->doc_hdl = doc_hdl;
    
    /* Extract data SYNCML DM settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_syncml_dm_proc_cca_nodes, 
                g_syncml_dm_ota_context);

    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (mmi_syncml_dm_get_valid_profile_num() == 0) 
    {        
        /* Now, terminate the SYNCML OTA provisioning application. */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]CCA_STATUS_INVALID_SETTING");
        mmi_dmui_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        return;
    }
    
    /* if DM server id not init */
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[0]) == 0)
    {
        /* check and init DM UI server id information */
        ptr_dmui_context->dmui_status = MMI_DM_OTA_LIST_SERVERID_STATUS;
        mmi_syncml_dm_init_data();
    }
    else
    {
        /* provisioning information screen GUI is NULL */
        gui_valid_flag = 0;

        /* Ready to install profiles. */
        mmi_syncml_dm_entry_installation();
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_dm_free_otap_proxy
* DESCRIPTION
*  The function frees memory of the control block, and clears the proxy ptr.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_syncml_dm_free_otap_proxy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_free_syncml_ota_cntx()");    
    /* Nothing to do. Return. */
    if (g_syncml_dm_ota_context== NULL) 
    {
        MMI_ASSERT(0);
    }    

    /* Free all proxy. */
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++) 
    {
        if (g_syncml_dm_ota_context->proxy[i] != NULL) 
        {
            OslMfree(g_syncml_dm_ota_context->proxy[i]);
            g_syncml_dm_ota_context->proxy[i] = NULL;
        }
    }
    /* Free the control block. */

}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_dm_new_otap_proxy
* DESCRIPTION
*  This function allocates a temporary storage for SYNC profile. And it will 
*  turn on the flag such that we can process subsequent nodes/parameters
*  again.
* PARAMETERS
*  cntx            [IN]            control block for SYNC OTA provisioning
* RETURNS
*  On success, return the index of the newly allocated profile. Otherwise, 
*  return -1, i.e., an invalid index.
*****************************************************************************/
static S16 mmi_syncml_dm_new_otap_proxy(syncml_dm_ota_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* No more temporary profile storage. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_new_otap_proxy()");

    if (cntx->num_proxy == MAX_SYNCML_DM_PROFILES) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_proxy;
    
    /* Allocate memory for the profile. */
    cntx->proxy[index] = (mmi_dm_ota_conn_setting_struct*)OslMalloc(sizeof(mmi_dm_ota_conn_setting_struct));
    if (cntx->proxy[index] == NULL) 
    {
        return -1;
    }

    memset(cntx->proxy[index], 0x00, sizeof(mmi_dm_ota_conn_setting_struct));

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
static cca_status_enum mmi_syncml_dm_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_dm_ota_context_struct *cntx;
    cca_status_enum status = 0;
    cca_core_data_struct *param;
    S16 index_profile, index_proxy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (syncml_dm_ota_context_struct*)user_data;
    index_profile = cntx->num_profiles;
    index_proxy = cntx->num_proxy;

    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]mmi_syncml_dm_proc_cca_nodes() function -- symbol = %d \n", symbol);

    switch (symbol)
    {
        case CCA_NS_SYNCML_DM_PROXY:  /* 0 */
		{
            index_proxy = mmi_syncml_dm_new_otap_proxy(cntx);

            ASSERT(index_proxy != -1);

            cntx->num_proxy++;

            if(cntx->num_proxy > MAX_SYNCML_DM_PROFILES)
            {
                return CCA_STATUS_OK;
            }

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_PROXY === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_PROXY_ID: /* 0x0c02 */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_id = %s \n", 
                                    param->values.s[0]);

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy]->proxy_id, 
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy]->proxy_id, 
                                        (S8*)param->values.s[0], (DM_MAX_ID_STR/2 - 1));
                                }

                            }
                        }
                        break;

                    case CCA_NS_OMA_PROXY_PW:   /* 0x0c03 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PPGAUTH_TYPE:   /* 0x0c04 */
                        if (param->values.i[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PROXY_PROVIDER_ID:  /* 0x0c05 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_NAME:   /* 0x0c06 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_STARTPAGE:  /* 0x0c0a */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_BASAUTH_ID: /* 0x0c0b */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_BASAUTH_PW: /* 0x0c0c */
                        if (param->values.s[0])
                        {
                        }
                        break;
                    
                    case CCA_NS_OMA_PHYSICAL_PROXY_ID: /* 0x0c17 */
                        if (param->values.s[0])
                        {
                        }
                        break;   
                        
                    case CCA_NS_OMA_PXADDR: /* 0x0c18 */
                        if(param->values.s[0])  
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_addr = %s \n", 
                                    param->values.s[0]);

                                if (str_length * 2 < DM_MAX_IP_SIZE)
                                {
                                mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy]->proxy_addr, 
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy]->proxy_addr, 
                                        (S8*)param->values.s[0], (DM_MAX_IP_SIZE/2 - 1));   
                                }

                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_PXADDRTYPE: /* 0x0c19 */
                        /*If data isn't CCA_NS_VAL_IPV4,we pass this node*/
                        if((S8)param->values.i[0]!= (S8)CCA_NS_VAL_IPV4)
                        {
                            return CCA_STATUS_FAIL;
                        }
                        break; 

                    case CCA_NS_OMA_PXADDR_FQDN:    /* 0x0c1a */
                        if (param->values.s[0])
                        {
                            
                        }
                        break;

                    case CCA_NS_DATAACCTID: /* 0x0403 */
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] data_account_id = %d \n", 
                                param->values.i[0]);

                          	cntx->proxy[index_proxy]->data_account_id = param->values.i[0];
                        }
                        break;           
 
                    default:
                        break;
                        
                }                
            }
            /* End of while */
            
            status = CCA_STATUS_OK;
            break;
        } 
        /* END of case CCA_NS_SYNCML_DM_PROXY: */
        
        case CCA_NS_SYNCML_DM_PORT: /* 2 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_PORT === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_PORTNBR: /* 0x0c15 */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_port = %s \n", 
                                    param->values.s[0]);

                                cntx->proxy[index_proxy - 1]->proxy_port = atoi(param->values.s[0]); 

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_port = %d \n", 
                                    cntx->proxy[index_proxy - 1]->proxy_port);
                            }
                        }
                        break;   
                        
                    case CCA_NS_OMA_SERVICE:
                        /* If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                            we pass this node */
                        if (param->values.i[0] != CCA_NS_VAL_OTA_HTTP_TO)
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_OMA_SERVICE == %d \n", 
                                param->values.i[0]);

                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_OMA_SERVICE not HTTP!!!");
                        }
                        break;
                        
                    default:
                        break;
                        
                }
            }
            status = CCA_STATUS_OK;            
            break;            
        }  
        /* END of case CCA_NS_SYNCML_DM_PORT: */

        case CCA_NS_SYNCML_DM_PXAUTHINFO:   /* 3 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                    switch (param->id)
                    {
                        PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_PXAUTHINFO === param->id = %d \n", param->id);

                        case CCA_NS_OMA_PXAUTH_TYPE:
                            break;

                        case CCA_NS_OMA_PXAUTH_ID:
                            if(param->values.s[0])
                            {
                                if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                                {
                                    U8 str_length = strlen((S8*)param->values.s[0]);

                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_user_name = %s \n", 
                                        param->values.s[0]);

                                    if (str_length * 2 < DM_MAX_PROXY_LEN)
                                    {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy - 1]->proxy_user_name, 
                                            (S8*)param->values.s[0], str_length); 
                                    }
                                    else
                                    {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy - 1]->proxy_user_name, 
                                            (S8*)param->values.s[0], (DM_MAX_PROXY_LEN/2 -1)); 
                                    }
       
                                }
                            }
                            break;  
                            
                        case CCA_NS_OMA_PXAUTH_PW:
                            if(param->values.s[0])
                            {
                                if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                                {
                                    U8 str_length = strlen((S8*)param->values.s[0]);

                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_user_pw = %s \n", 
                                        param->values.s[0]);

                                    if (str_length * 2 < DM_MAX_PROXY_LEN)
                                    {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy - 1]->proxy_user_pw, 
                                            (S8*)param->values.s[0], str_length); 
                                    }
                                    else
                                    {
                                        mmi_syncml_dm_ansii2unicode((S8*)cntx->proxy[index_proxy - 1]->proxy_user_pw, 
                                            (S8*)param->values.s[0], (DM_MAX_PROXY_LEN/2 - 1)); 
                                    }
       
                                }
                            }
                            break; 
                            
                        default:
                            break;
                            
                    }
            }
            status = CCA_STATUS_OK;            
            break;            
        }
        /* END of case CCA_NS_SYNCML_DM_PXAUTHINFO: */

        case CCA_NS_SYNCML_DM_APPLICATION:  /* 1 */
        {
            /* When start process this node,we predefine all the node proxy have already been processed */            
            /* Prepare a storage for the new profile. And get the new index. */
            if (cntx->num_profiles == MAX_SYNCML_DM_PROFILES)
                return CCA_STATUS_FAIL;
            
            index_profile = cntx->num_profiles;
            cntx->num_profiles++;

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_APPLICATION === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_APPID:  /* 0c4c */  /* syncml dm appid is "w7" */
                        if(param->values.s[0])
                        {
                            if(strcmp((S8*)param->values.s[0], (S8*)"w7") != 0)
                            {
                                return CCA_STATUS_FAIL;
                            }
                            
                            cntx->isvalidprof[index_profile] = MMI_TRUE;
                        }
                        break;
                
                    case CCA_NS_OMA_NAME:   /* 0c06 */ /* acct name & unused */
                        if(strlen(param->values.s[0]))
                        {
                        }
                        break;

                    case CCA_NS_OMA_PROVIDER_ID:    /* provide id */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);
                                
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] server_id = %s \n", 
                                    param->values.s[0]);
                                
                                if (str_length == 0)
                                {
                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                    break;
                                }

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].server_id, 
                                        (S8*)param->values.s[0], str_length);
                                    
                                    cntx->isvalidprof[index_profile] = MMI_TRUE;
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].server_id, 
                                        (S8*)param->values.s[0], (DM_MAX_ID_STR/2 - 1));
                                    
                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                }
                                
                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_INIT:
                        if(param->values.s[0])
                        {
                        }
                        break;  
                        
                    case CCA_NS_OMA_TO_PROXY:   /* 0x0c50 */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);

                               PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_id = %s \n", 
                                   param->values.s[0]);

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].proxy_id,
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].proxy_id,
                                        (S8*)param->values.s[0], (DM_MAX_ID_STR/2 - 1));
                                }


                            }
                        }
                        break;

                    case CCA_NS_OMA_ADDR:   /* server address */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] server_addr = %s \n", 
                                    param->values.s[0]);

                                if (str_length * 2 < DM_MAX_URI_SIZE)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].server_addr, 
                                        (S8*)param->values.s[0], str_length); 
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile].server_addr, 
                                        (S8*)param->values.s[0], (DM_MAX_URI_SIZE/2 - 1)); 

                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                }
 
                            }
                        }
                        break;         
                        
                    case CCA_NS_OMA_ADDRTYPE:   /* must be IPV4 */
                        if(param->values.i[0] != CCA_NS_VAL_IPV4)
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_OMA_ADDRTYPE = = %d \n", 
                                param->values.i[0]);

                            return CCA_STATUS_FAIL;
                        }
                        break;     
                      
                    default:
                        break;
                        
                }
            }   /* END of while loop */
            
            status = CCA_STATUS_OK;
            break;
        }    
        /* END of case CCA_NS_SYNCML_DM_APPLICATION: */

        case CCA_NS_SYNCML_DM_APPPORT: /* 2 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_PORT === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_PORTNBR: /* 0x0c15 */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] port_num = %s \n", 
                                    param->values.s[0]);

                                cntx->profile[index_profile-1].port_num = atoi(param->values.s[0]);

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] port_num = %d \n", 
                                    cntx->profile[index_profile-1].port_num);
                            }
                        }
                        break;   
                        
                    case CCA_NS_OMA_SERVICE:
                        /* If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                            we pass this node */
                        if (param->values.i[0] != CCA_NS_VAL_OTA_HTTP_TO)
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_OMA_SERVICE = = %d \n", 
                                    param->values.i);

                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_OMA_SERVICE not HTTP!!!");
                        }
                        break;
                        
                    default:
                        break;
                        
                }
            }
            status = CCA_STATUS_OK;            
            break;            
        }  
        /* END of case CCA_NS_SYNCML_DM_APPPORT: */

        case CCA_NS_SYNCML_DM_APPADDR:  /* 4 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_APPADDR === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_ADDR:   /* server address */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);

                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] server_addr = %s \n", 
                                    param->values.s[0]);

                                if (str_length * 2 < DM_MAX_URI_SIZE)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile - 1].server_addr, 
                                        (S8*)param->values.s[0], str_length); 
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)cntx->profile[index_profile - 1].server_addr, 
                                        (S8*)param->values.s[0], (DM_MAX_URI_SIZE/2 - 1)); 
                                    
                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]overflow server_addr");
                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
                                }
                            }
                        }
                        break;         

                    case CCA_NS_OMA_ADDRTYPE:   /* must be IPV4 */
                        if(param->values.i[0] != CCA_NS_VAL_IPV4)
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]OMA_ADDRTYPE not IPV4!!!" );
                            return CCA_STATUS_FAIL;
                        }
                        break; 

                    default:
                        break;
                        
                }
            }

            status = CCA_STATUS_OK;            
            break;
        }     
        /* END of case CCA_NS_SYNCML_DM_APPADDR: */

        case CCA_NS_SYNCML_DM_APPAUTH:  /* 6 */
        {
            mmi_dm_ota_appauth_struct auth_data;

            memset(&auth_data, 0x00, sizeof(mmi_dm_ota_appauth_struct));
            
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] CCA_NS_SYNCML_DM_APPAUTH === param->id = %d \n", 
                    param->id);

                switch (param->id)
                {
                    case CCA_NS_OMA_AAUTHLEVEL: 
                        /*Predefine this param is received earlier than any other params of this node.
                        If authlevel is not CCA_NS_VAL_CLIENT,we pass this node*/
                        switch(param->values.i[0])
                        {
                        case CCA_NS_VAL_APPSRV:     /* save AAUTHNAME AAUTHSECRET as username userpassword */
                            auth_data.auth_level = CCA_NS_VAL_APPSRV;
                            break;

                        case CCA_NS_VAL_OBEX:
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]receive CCA_NS_VAL_OBEX");
                            return CCA_STATUS_FAIL;
                            break;

                        case CCA_NS_VAL_CLIENT:
                            auth_data.auth_level = CCA_NS_VAL_CLIENT;
                            break;

                        default:
                            return CCA_STATUS_FAIL;
                            break;
                        }
                        break;   
                        
                    case CCA_NS_OMA_AAUTHTYPE:
                        {
                            PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] auth_pref = %d \n", 
                                param->values.i[0]);
  
                            switch(param->values.i[0])
                            {
                                case CCA_NS_VAL_BASIC:  /* BASIC auth Type */
                                    auth_data.auth_pref = DM_AUTH_TYPE_BASIC;    
                                    break;

                                case CCA_NS_VAL_DIGEST: /* MD5 auth type */   
                                    auth_data.auth_pref = DM_AUTH_TYPE_MD5;    
                                    break;
                         
                                case CCA_NS_VAL_HMAC:   /* HMAC auth type */
                                    auth_data.auth_pref = DM_AUTH_TYPE_HMAC;
                                    break;

                                case CCA_NS_VAL_HTTP_BASIC:
                                case CCA_NS_VAL_HTTP_DIGEST:
                                case CCA_NS_VAL_WTLS_SS:
                                case CCA_NS_VAL_X509:
                                case CCA_NS_VAL_SECURID:
                                case CCA_NS_VAL_SAFEWORD:
                                case CCA_NS_VAL_DIGIPASS:
                                    return CCA_STATUS_FAIL;
                                    break;

                                default:    /* None auth type */
                                    auth_data.auth_pref = DM_AUTH_TYPE_NONE;
                                    break;

                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_AAUTHNAME:  /* user name */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);
                                
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] auth_name = %s \n", 
                                    param->values.s[0]);

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_name, 
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_name, 
                                        (S8*)param->values.s[0], (DM_MAX_ID_STR/2 - 1));
   
                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]overflow auth_name");
                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
                                }
                            }
                            break;
                            
                        }
                        break;   
                        
                    case CCA_NS_OMA_AAUTHSECRET:    /* user password */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);
 
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] auth_pw = %s \n", 
                                    param->values.s[0]);
                                
                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_pw, 
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_pw, 
                                        (S8*)param->values.s[0], (DM_MAX_ID_STR/2 - 1));
                                    
                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]overflow auth_pw");
                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
                                }
                            }
                            break;
                        }
                        break;   
                        
                    case CCA_NS_OMA_AAUTHDATA:  /* nonce name */
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*)param->values.s[0]);
                                
                                PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] auth_nonce = %s \n", 
                                    param->values.s[0]);
                                
                                if (str_length * 2 < DM_MAX_NAME_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_nonce, 
                                        (S8*)param->values.s[0], str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode((S8*)auth_data.auth_nonce, 
                                        (S8*)param->values.s[0], (DM_MAX_NAME_STR/2 - 1));
                                    
                                    PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning]overflow auth_nonce");

                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
                                }
                            }
                            break;
                        }
                        break;

                    default:
                        break;
                        
                }
            }

            switch (auth_data.auth_level)
            {
            case CCA_NS_VAL_APPSRV:
                {
                    mmi_ucs2cpy((S8*)cntx->profile[index_profile - 1].server_pw, (S8*)auth_data.auth_pw);

                    mmi_ucs2cpy((S8*)cntx->profile[index_profile - 1].server_nonce, (S8*)auth_data.auth_nonce);
                }
                break;

            case CCA_NS_VAL_CLIENT:
                {
                    mmi_ucs2cpy((S8*)cntx->profile[index_profile - 1].user_name, (S8*)auth_data.auth_name);

                    mmi_ucs2cpy((S8*)cntx->profile[index_profile - 1].user_pw, (S8*)auth_data.auth_pw);
                    
                    mmi_ucs2cpy((S8*)cntx->profile[index_profile - 1].client_nonce, (S8*)auth_data.auth_nonce);

                    cntx->profile[index_profile - 1].auth_pref = auth_data.auth_pref;
                }
                break;

            default:
                break;
            }

            status = CCA_STATUS_OK;
            break;
        } 

        default:
            return CCA_STATUS_OK;
        break;
            
    }

    return status;
}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_get_valid_profile_num
* DESCRIPTION
*  This function checks if there is any valid profile.
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static U8 mmi_syncml_dm_get_valid_profile_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, num = 0;
    U8 temp_url_addr[DM_MAX_URI_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_get_valid_profile_num()");

    for(i = 0; i < g_syncml_dm_ota_context->num_profiles; i++)
    {
        if(&g_syncml_dm_ota_context->profile[i])    /* only to judge the profiles exist in buffer. */
        {
            if(g_syncml_dm_ota_context->isvalidprof[i]) /* only to judge the profiles mapped already */
            {
                /*************************************************************************************
                *                               Check params of DM setting                           *
                *************************************************************************************/
                /* check server id valid or not */
                if (mmi_ucs2strlen((S8*)g_syncml_dm_ota_context->profile[i].server_id) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }
                
                /* check server address valid or not */
                memset(temp_url_addr, 0x00, DM_MAX_URI_SIZE);
                mmi_ucs2_to_asc((S8*)temp_url_addr, (S8*)g_syncml_dm_ota_context->profile[i].server_addr);
                if (applib_url_is_valid((const char *)temp_url_addr) != 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check address type */
                /* when address not ipv4 return fail to CCA */
                
                /* check server password when */
                if (mmi_ucs2strlen((S8*)g_syncml_dm_ota_context->profile[i].server_pw) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check server nonce */
                if (mmi_ucs2strlen((S8*)g_syncml_dm_ota_context->profile[i].server_nonce) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check user name */
                if (mmi_ucs2strlen((S8*)g_syncml_dm_ota_context->profile[i].user_name) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /*************************************************************************************
                *                       Check params of Connection setting                           *
                *************************************************************************************/
                /* need compare proxy id and valid or invalid proxy id and data account id */
                {
                    U8 j = 0;

                    for (j = 0; j < g_syncml_dm_ota_context->num_proxy; j++)
                    {
                        if (mmi_ucs2cmp((S8*)g_syncml_dm_ota_context->profile[i].proxy_id, 
                            (S8*)g_syncml_dm_ota_context->proxy[j]->proxy_id) == 0)
                        {
                            memset(&g_syncml_dm_ota_context->profile[i].conn_setting, 0x00, 
                                sizeof(mmi_dm_ota_conn_setting_struct));

                            /* add data account id */ 
                            g_syncml_dm_ota_context->profile[i].conn_setting.data_account_id = 
                                g_syncml_dm_ota_context->proxy[j]->data_account_id;

                            /* add proxy IP */
                            memset(temp_url_addr, 0x00, DM_MAX_URI_SIZE);
                            mmi_ucs2_to_asc((S8*)temp_url_addr, (S8*)g_syncml_dm_ota_context->proxy[j]->proxy_addr);
                            if (applib_url_is_valid((const char *)temp_url_addr) != 0)
                            {
                                mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[i].conn_setting.proxy_addr, 
                                    (S8*)L"0.0.0.0");
                            }
                            else
                            {
                                mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[i].conn_setting.proxy_addr,
                                (S8*)g_syncml_dm_ota_context->proxy[j]->proxy_addr);
                            }


                            /* add proxy port */
                            if (g_syncml_dm_ota_context->proxy[j]->proxy_port > 65535)
                            {
                                g_syncml_dm_ota_context->profile[i].conn_setting.proxy_port = 0;
                            }
                            else
                            {
                                g_syncml_dm_ota_context->profile[i].conn_setting.proxy_port = 
                                g_syncml_dm_ota_context->proxy[j]->proxy_port;
                            }


                            /* add proxy user name */
                            mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[i].conn_setting.proxy_user_name,
                                (S8*)g_syncml_dm_ota_context->proxy[j]->proxy_user_name);

                            /* add proxy user password */
                            mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[i].conn_setting.proxy_user_pw,
                                (S8*)g_syncml_dm_ota_context->proxy[j]->proxy_user_pw);

                            /* set proxy use flag */
                            if ((mmi_ucs2strlen((S8*)g_syncml_dm_ota_context->profile[i].proxy_id) == 0)
                                || (mmi_ucs2ncmp((S8*)g_syncml_dm_ota_context->profile[i].proxy_id, 
                                (S8*)L"@CCA@GEN@", 9) == 0))
                            {
                                g_syncml_dm_ota_context->profile[i].conn_setting.proxy_used = MMI_FALSE;
                            }
                            else
                            {
                                g_syncml_dm_ota_context->profile[i].conn_setting.proxy_used = MMI_TRUE;
                            }

                            break;
                        }
                    }

                    /* match proxy ID failed */
                    if (j == g_syncml_dm_ota_context->num_proxy)
                    {
                        memset(&g_syncml_dm_ota_context->profile[i].conn_setting, 0x00, 
                            sizeof(mmi_dm_ota_conn_setting_struct));
                        
                        g_syncml_dm_ota_context->profile[i].conn_setting.data_account_id = (U16)-1;
                        
                        g_syncml_dm_ota_context->profile[i].conn_setting.proxy_port = (U32)0;
                        
                        mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[i].conn_setting.proxy_addr, (S8*)L"0.0.0.0");

                        g_syncml_dm_ota_context->profile[i].conn_setting.proxy_used = MMI_FALSE;
                    }
                }
            }				
        }

        if(g_syncml_dm_ota_context->isvalidprof[i] == MMI_TRUE)
        {
            num++;
        }
    }

    mmi_syncml_dm_free_otap_proxy();

    return num;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *info;
    U8 *gui_buffer = NULL;
    U8 i, total_valid = 0;
    U8 current_valid = 0;
    U8 tmp[DM_MAX_URI_SIZE * ENCODING_LENGTH];
    S8 tmpnum[4 * ENCODING_LENGTH];
    mmi_dm_ota_account_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the current interesting profile. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_entry_installation()");

    for(i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if(g_syncml_dm_ota_context->isvalidprof[i] == MMI_TRUE)
        {
            /* count of total valid profile */
            total_valid++;
        }
    }

    if(total_valid == 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]CCA_STATUS_INVALID_SETTING ");
        mmi_dmui_send_cca_app_configure_rsp(g_syncml_dm_ota_context->conf_id, g_syncml_dm_ota_context->doc_hdl,
                CCA_STATUS_INVALID_SETTING);
    }

    while ((g_syncml_dm_ota_context->isvalidprof[g_syncml_dm_ota_context->iter] != MMI_TRUE)
            &&(g_syncml_dm_ota_context->iter < MAX_SYNCML_DM_PROFILES))
    {
        /* current profile index */
        g_syncml_dm_ota_context->iter++;
    }

    if (g_syncml_dm_ota_context->iter == MAX_SYNCML_DM_PROFILES)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]iter > MAX_SYNCML_DM_PROFILES \n");
        
        ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL);
        return;
    }

    /* Obtain a temporary buffer to show messages. */
    info = (S8*)subMenuData;

    for(i = 0; i < g_syncml_dm_ota_context->iter + 1; i++)
    {
        if(g_syncml_dm_ota_context->isvalidprof[i])
        {
            /* current profile number index */
            current_valid++;
        }
    }

    prof = (mmi_dm_ota_account_struct *)(&g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);
    
    /* Profile name */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_SYNCMLDM));
    mmi_ucs2cat(info, (S8*)L": ");
    mmi_ucs2cat(info, (S8*)prof->server_id);
    mmi_ucs2cat(info, (S8*)L"\n\n"); 
    
    /* Current profile num */
    mmi_ucs2cat(info, (S8*)GetString(STR_ID_DM_OTA_PROFILE));
    mmi_ucs2cat(info, (S8*)L": ");    
    sprintf((S8*)&tmpnum,"%d", current_valid);
    memset(tmp,0,sizeof(tmp));
    mmi_syncml_dm_ansii2unicode(
                (S8*)tmp,
                (S8*)tmpnum,
                strlen((S8*)&tmpnum));
    mmi_ucs2cat(info, (S8*)tmp);
    mmi_ucs2cat(info, (S8*)L"/");
    sprintf((S8*)&tmpnum,"%d",total_valid);
    memset(tmp,0,sizeof(tmp));
    mmi_syncml_dm_ansii2unicode(
                (S8*) tmp,
                (S8*) tmpnum,
                strlen((S8*)&tmpnum));
    mmi_ucs2cat(info, (S8*)tmp);  
    mmi_ucs2cat(info, (S8*)L"\n\n"); 
    
    /* Server address */
    mmi_ucs2cat(info, (S8*)GetString(STR_ID_DMUI_SERVER_ADDRESS));
    mmi_ucs2cat(info, (S8*)L": "); 
    mmi_ucs2cat(info, (S8*)prof->server_addr);
    mmi_ucs2cat(info, (S8*)L"\n\n");  

    EntryNewScreen(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL, mmi_syncml_dm_entry_installation, NULL);
    
    if (gui_valid_flag != current_valid)   /* first in this screen or entry this screen with a new profile */
    {
        gui_valid_flag = current_valid;
        gui_buffer = NULL;
    }
    else if (gui_valid_flag == current_valid)
    {   
        gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_OTA_PROVISIONING_INFO);
    }

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_INSTALL,
        0,
        STR_ID_CCA_SKIP,
        0,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);      

    SetLeftSoftkeyFunction(mmi_syncml_dm_find_empty_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);

    /* Delete screens associated with previous profile. Clear delete screen 
       callback temporarily to prevent from terminating app. */
    ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL);   
    DeleteScreenIfPresent(SCR_ID_DM_OTA_PROVISIONING_INFO);
    DeleteScreenIfPresent(SCR_ID_DM_OTA_SKIP_CONFIRM);
    SetDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, mmi_syncml_dm_exit_install);   
    /* 
    SetKeyHandler(mmi_syncml_dm_exit_install, KEY_END, KEY_EVENT_DOWN);
    */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_init_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS 
 *  void
 *  
 *****************************************************************************/
static void mmi_syncml_dm_init_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LIST_SERVERID_REQ, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_find_empty_profile
 * DESCRIPTION
 *  find a empty profile or a exist profile has a same server id to replace 
 * PARAMETERS
 *  void
 * RETURNS 
 *  void
 *  
 *****************************************************************************/
static void mmi_syncml_dm_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Find an empty profile. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_find_empty_profile()");

    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        /* if the server id is exist */
        if (mmi_ucs2cmp((S8*)ptr_dmui_context->dmui_serverid_array[i], 
            (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id) == 0)
        {
            // Pop up exist server id screen and wait user select
            DisplayConfirm(
                STR_GLOBAL_INSTALL,
                0,
                STR_ID_CCA_SKIP,
                0,
                get_string(STR_ID_DM_OTA_SERVERID_EXIST_REPLACE), 
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            g_syncml_dm_ota_context->edit_serverid_index = i;
            
            /* start a install process */
            SetLeftSoftkeyFunction(mmi_syncml_dm_install_profile, KEY_EVENT_UP);
            
            SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);
                   
            return;
        }
    }

    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_serverid_array[i]) == 0)
        {
            /* add this profile to DM PS and save to NVRAM */
            mmi_syncml_dm_install_profile();

            return;
        }
    }

    /* Can not find a empty profile. Enter profile replacement. */
    mmi_syncml_dm_entry_replacement();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_display_skip_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS 
 *  void
 *  
 *****************************************************************************/
static void mmi_syncml_dm_display_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DM_OTA_SKIP_CONFIRM, NULL, NULL, NULL);
    
    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_CCA_SKIP_PROFILE,
        IMG_GLOBAL_QUESTION,
        NULL);
    
    SetLeftSoftkeyFunction(mmi_syncml_dm_next_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_exit_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS 
 *  void
 *  
 *****************************************************************************/
static U8 mmi_syncml_dm_exit_install(void* in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_exit_install");
    /* ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL); */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]CCA_STATUS_ENDKEY_PRESSED");
    mmi_dmui_send_cca_app_configure_rsp(g_syncml_dm_ota_context->conf_id, g_syncml_dm_ota_context->doc_hdl, 
        CCA_STATUS_ENDKEY_PRESSED);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_next_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS 
 *  void
 *  
 *****************************************************************************/
void mmi_syncml_dm_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_next_profile()");

    /* Increase the index of the iterator to process next profile. */
    g_syncml_dm_ota_context->iter++;
    
    /* Whether there is another profile needed to be installed. */
    if (g_syncml_dm_ota_context->iter < g_syncml_dm_ota_context->num_profiles) 
    {
        if(g_syncml_dm_ota_context->isvalidprof[g_syncml_dm_ota_context->iter])
        {
            /* Try to install next profile */
            mmi_syncml_dm_entry_installation();
        }
        else
        {
            mmi_syncml_dm_next_profile();
        }
    } 
    else 
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_next_profile() 222");
        
        /* Send a response back to CCA and free memory. */    
        if (g_syncml_dm_ota_context->num_installed == 0) 
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning] CCA_STATUS_SETTING_SKIPPED ");
            mmi_dmui_send_cca_app_configure_rsp(g_syncml_dm_ota_context->conf_id, g_syncml_dm_ota_context->doc_hdl,
                CCA_STATUS_SETTING_SKIPPED);
        } 
        else 
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning] CCA_STATUS_OK ");
            mmi_dmui_send_cca_app_configure_rsp(g_syncml_dm_ota_context->conf_id, g_syncml_dm_ota_context->doc_hdl, 
                CCA_STATUS_OK);
        }

        /* Clear the delete screen callback. */
        ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL);
        ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_SERVERID_LIST, NULL);

        DeleteScreenIfPresent(SCR_ID_DM_OTA_PROVISIONING_INFO);
        DeleteScreenIfPresent(SCR_ID_DM_OTA_SKIP_CONFIRM);
        DeleteScreenIfPresent(SCR_ID_DM_OTA_SERVERID_LIST);
        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_entry_replacement
 * DESCRIPTION
 *  display replace screen
 * PARAMETERS
 *  void    
 * RETURNS 
 *  void
 *****************************************************************************/
static void mmi_syncml_dm_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_entry_replacement()");

    DisplayConfirm(
        STR_GLOBAL_YES,
        0,
        STR_ID_CCA_SKIP,
        0,
        get_string(STR_ID_DM_OTA_SERVERID_FULL_REPLACE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* list server id and wait user select */
    SetLeftSoftkeyFunction(mmi_syncml_dm_server_id_list, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_install_profile
 * DESCRIPTION
 *  entry install profile process and save profile to DM PS
 * PARAMETERS
 *  void    
 * RETURNS 
 *  void
 *****************************************************************************/
static void mmi_syncml_dm_install_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 temp_nodename[DM_MAX_ID_STR];
    dm_add_account_struct *dm_ota_add_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_dm_install_profile()");

    dm_ota_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));
    
    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

    /* search the same server id */
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (mmi_ucs2cmp((S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id,
            (S8*)ptr_dmui_context->dmui_serverid_array[i]) == 0)
        {
            gui_itoa((U32)i, (UI_string_type)temp_nodename, 10);
            break;
        }
    }

    /* find same server id and get the node name */
    if (mmi_ucs2strlen((S8*)temp_nodename) == 0)
    {
        for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
        {
            if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[i]) == 0)
            {
            gui_itoa((U32)i, (UI_string_type)temp_nodename, 10);
            break;
        }
    }
    }

    g_syncml_dm_ota_context->edit_serverid_index = i;

    /* set current node name string to profile */
    mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].node_name, (S8*)temp_nodename);
    
    /* set value to dm_ota_add_account struct */
    mmi_syncml_dm_set_value(&dm_ota_add_account->dm_account, 
        &g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);

    ptr_dmui_context->dmui_status = MMI_DM_OTA_ADD_ACCOUNT_STATUS;
    
    mmi_dm_print_info(&dm_ota_add_account->dm_account); 

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dm_ota_add_account);
    
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_set_value
 * DESCRIPTION
 *  set value of dm_account_struct
 * PARAMETERS
 *  ptr_dm_account    [IN]     
 *  ptr_dm_ota        [IN]     
 * RETURNS 
 *  void
 *****************************************************************************/
void mmi_syncml_dm_set_value(dm_account_struct* ptr_dm_account, mmi_dm_ota_account_struct* ptr_dm_ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_set_value ");
    MMI_ASSERT(ptr_dm_account != NULL);
    MMI_ASSERT(ptr_dm_ota != NULL);

    /* ------------------   application ---------------------- */
    /* app port number */
    ptr_dm_account->port_num = ptr_dm_ota->port_num;

    /* app auth type */
    ptr_dm_account->auth_pref = ptr_dm_ota->auth_pref;

    /* app address type (only support ipV4 now)*/
    ptr_dm_account->addr_type = ptr_dm_ota->addr_type;

    /* app node name string */
    mmi_ucs2cpy((S8*)ptr_dm_account->node_name, (S8*)ptr_dm_ota->node_name);

    /* app server address */
    mmi_ucs2cpy((S8*)ptr_dm_account->server_addr, (S8*)ptr_dm_ota->server_addr);

    /* app server id */
    mmi_ucs2cpy((S8*)ptr_dm_account->server_id, (S8*)ptr_dm_ota->server_id);

    /* app server password */
    mmi_ucs2cpy((S8*)ptr_dm_account->server_pw, (S8*)ptr_dm_ota->server_pw);

    /* app server nonce */
    mmi_ucs2cpy((S8*)ptr_dm_account->server_nonce, (S8*)ptr_dm_ota->server_nonce);

    /* app user name */
    mmi_ucs2cpy((S8*)ptr_dm_account->user_name, (S8*)ptr_dm_ota->user_name);

    /* app user password */
    mmi_ucs2cpy((S8*)ptr_dm_account->user_pw, (S8*)ptr_dm_ota->user_pw);
    
    /* app client nonce */
    mmi_ucs2cpy((S8*)ptr_dm_account->client_nonce, (S8*)ptr_dm_ota->client_nonce);

    /* app acct name */
    mmi_ucs2cpy((S8*)ptr_dm_account->acct_name, (S8*)ptr_dm_ota->acct_name);

    /* ---------------------    connection setting -------------------- */
    /* connection setting type */
    mmi_ucs2cpy((S8*)ptr_dm_account->conn_setting.conn_ref, (S8*)ptr_dm_ota->conn_setting.conn_ref);
    
    /* connection setting proxy address */
    mmi_ucs2cpy((S8*)ptr_dm_account->conn_setting.proxy_addr, (S8*)ptr_dm_ota->conn_setting.proxy_addr);

    /* connection setting proxy user name */
    mmi_ucs2cpy((S8*)ptr_dm_account->conn_setting.proxy_user_name, (S8*)ptr_dm_ota->conn_setting.proxy_user_name);

    /* connection setting proxy user password */
    mmi_ucs2cpy((S8*)ptr_dm_account->conn_setting.proxy_user_pw, (S8*)ptr_dm_ota->conn_setting.proxy_user_pw);

    /* connection setting proxy port number */
    ptr_dm_account->conn_setting.proxy_port = ptr_dm_ota->conn_setting.proxy_port;

    /* connection setting data account id */
    ptr_dm_account->conn_setting.data_account_id = ptr_dm_ota->conn_setting.data_account_id;

    /* connection setting proxy used or not */
    ptr_dm_account->conn_setting.proxy_used = ptr_dm_ota->conn_setting.proxy_used;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_send_cca_app_configure_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_CONFIGURE_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dmui_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
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
 *  mmi_syncml_dm_server_id_list
 * DESCRIPTION
 *  entry server id list screen and wait user select
 * PARAMETERS
 *  void    
 * RETURNS 
 *  void
 *****************************************************************************/
static void mmi_syncml_dm_server_id_list(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8  i;
    U8  *gui_buffer = NULL;
    PU8 sub_menu_data_ptrs[DMUI_MAX_SERVERID];
    U16 serverid_states_icon[DMUI_MAX_SERVERID];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]mmi_syncml_dm_server_id_list function");  
    
    EntryNewScreen(SCR_ID_DM_OTA_SERVERID_LIST, NULL, NULL, NULL);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_OTA_SERVERID_LIST);
    
    RegisterHighlightHandler(mmi_syncml_dm_server_id_list_select);
    
    for (i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        if ((*ptr_dmui_context->dmui_serverid_array[i] == 0) && 
            (*(ptr_dmui_context->dmui_serverid_array[i] + 1) == 0))
        {
            sub_menu_data_ptrs[i] = (U8*)GetString(STR_ID_DMUI_LIST_EMPTY);
            
            serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
        }
        else
        {
            sub_menu_data_ptrs[i] = (U8*)ptr_dmui_context->dmui_serverid_array[i];
            
            if ((mmi_ucs2cmp((S8*)sub_menu_data_ptrs[i], (S8*)ptr_dmui_context->dmui_primary_serverid) == 0)
                && (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_primary_serverid) != 0))
            {
                serverid_states_icon[i] = IMG_ID_DMUI_SEL_IMAGE;
            }
            else
            {
                serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
            }
        }
    }
    
    ShowCategory73Screen(
        STR_ID_DMUI_MAIN,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_SELECT,
        0,
        STR_ID_CCA_SKIP,
        0,
        DMUI_MAX_SERVERID,
        sub_menu_data_ptrs,
        serverid_states_icon,
        (U16*)gIndexIconsImageList,
        0,
        gui_buffer,
        1);

    ClearDelScrnIDCallbackHandler(SCR_ID_DM_OTA_PROVISIONING_INFO, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_DM_OTA_SERVERID_LIST, mmi_syncml_dm_exit_install); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_server_id_list_select
 * DESCRIPTION
 *  entry server id list screen and wait user select
 * PARAMETERS
 *  index [OUT] current index of high light    
 * RETURNS 
 *  void
 *****************************************************************************/
static void mmi_syncml_dm_server_id_list_select(S32 index)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    g_syncml_dm_ota_context->edit_serverid_index = (U32)index;

    SetLeftSoftkeyFunction(mmi_syncml_dm_replace_profile, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);
    
    /*
    SetKeyHandler(mmi_syncml_dm_exit_install, KEY_END, KEY_EVENT_DOWN);
    */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_replace_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS 
 *  void
 *****************************************************************************/
static void mmi_syncml_dm_replace_profile(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *ptr_dm_ota_del = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dm_ota_del = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
    mmi_ucs2cpy((S8*)ptr_dm_ota_del->server_id,
        (S8*)ptr_dmui_context->dmui_serverid_array[g_syncml_dm_ota_context->edit_serverid_index]);

    /*
    if (mmi_ucs2cmp((S8*)ptr_dm_ota_del->server_id, (S8*)ptr_dmui_context->dmui_primary_serverid) == 0)
    */
    {
        /* if replace activated server id */
        ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS;
    }
    /*
    else
    {
        / * if replace inactivated server id * /
        ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_INACTIVATED_DEL_ACCOUNT_STATUS;
    }
    */
    
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, ptr_dm_ota_del);
    
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_ansii2unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest             [IN]     
 *  dest_size        [IN]     
 * RETURNS 0,1
 *  
 *****************************************************************************/
static void mmi_syncml_dm_ansii2unicode(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*)pOutBuffer, (S8*)pInBuffer, (U32)len+1);
}


/*****************************************************************************
 * FUNCTION
 *  Is_ANSII_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest             [IN]     
 *  dest_size        [IN]     
 * RETURNS 0,1
 *  
 *****************************************************************************/
static MMI_BOOL Is_ANSII_format(S8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *p = dest;  
    U8 ansii_max_value = 127;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]Is_ANSII_format NULL point");
    
    while(*p != '\0')
    {
        if(*p < ansii_max_value )
        {
            p++;
        }     
        else
        {
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}


/***************************************************************************
*                       
***************************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_syncml_send_cca_dm_get_profile
* DESCRIPTION
*  This function to send profile information to CCA
* PARAMETERS
*  cca_status_enum [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_syncml_send_cca_dm_get_profile(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_get_prof_rsp_struct *data;

    S32 hconfig, hroot, hnode ,temnode,connect_type;
    dm_account_struct dm_profile;
    U8 temp_str[DM_MAX_ID_STR * ENCODING_LENGTH];
    S8 tempint[10];
    S8 temp_ip_addr[4][DMUI_MAX_IPADDRES_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][provisioning]mmi_syncml_send_cca_dm_get_prof_rsp()");

    memset(&dm_profile, 0x00, sizeof(dm_account_struct));

    memcpy(&dm_profile, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

    hroot = mmi_cca_doc_new_rootnode();

    if (!hroot)
    {
        MMI_ASSERT(0);
    }

    /* add proxy node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release(hroot); 
        MMI_ASSERT(0);
    }

        /* add node ID */
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_NODEID, "PROXY_1");

        /* add proxy ID */
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PROXY_ID, "PROXY_1");

        /* translate and add IP address */
        mmi_ucs2_to_asc((S8*)temp_ip_addr, (S8*)dm_profile.conn_setting.proxy_addr);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXADDR, (S8*)temp_ip_addr);

        /* add proxy address type */
        mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);

        /* add data account id */
        mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_DATAACCTID, (S32)dm_profile.conn_setting.data_account_id);   

    /* add proxy port node */
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, temnode);

        /* add proxy port */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]proxy_port = %d \n",
            dm_profile.conn_setting.proxy_port);        
        sprintf((S8*)tempint, "%d", (U32)dm_profile.conn_setting.proxy_port);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]tempint = %s \n", tempint); 
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PORTNBR, (S8*)tempint);

        /* add connect type */
        /*
        connect_type = (dm_profile.conn_type == SYNCML_TRANS_HTTP) ? CCA_NS_VAL_OTA_HTTP_TO : CCA_NS_VAL_CL_WSP;
        */
        /* NOW DM only support HTTP */
        connect_type = CCA_NS_VAL_OTA_HTTP_TO;
        mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_SERVICE, (S32)connect_type);    

    /* add proxy auth info node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, temnode);

        /* add proxy user name */
        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.conn_setting.proxy_user_name);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXAUTH_ID, (S8*)temp_str);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.conn_setting.proxy_user_pw);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXAUTH_PW, (S8*)temp_str);
    
    /* add application node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release(hroot); 
        MMI_ASSERT(0);
    }
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_NODEID ,"APPLICATION_1");
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_APPID ,"w7");

        mmi_cca_doc_add_nodedata_str(hnode,CCA_NS_OMA_TO_PROXY , "PROXY_1");

    /* add app address node */    
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPADDR, temnode);
    
        mmi_ucs2_to_asc((S8*)temp_ip_addr, (S8*)dm_profile.server_addr);
        mmi_cca_doc_add_nodedata_str(hnode,CCA_NS_OMA_ADDR , (S8*)temp_ip_addr);   

    /* add app auth node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPAUTH, temnode);  
        
        mmi_cca_doc_add_nodedata_int(hnode,CCA_NS_OMA_AAUTHLEVEL , CCA_NS_VAL_APPSRV);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.server_id);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHNAME, (S8*)temp_str);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.server_pw);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHSECRET, (S8*)temp_str);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.server_nonce);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHDATA, (S8*)temp_str);

    /* add app auth node 2 */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPAUTH, temnode);  

        mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHLEVEL , CCA_NS_VAL_CLIENT);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.user_name);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHNAME , (S8*)temp_str);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.user_pw);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHSECRET , (S8*)temp_str);

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)dm_profile.client_nonce);
        mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHDATA, (S8*)temp_str);

    hconfig = mmi_cca_doc_new(hroot);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
    data->app_id = ptr_dmui_context->app_id;
    data->prof_id = ptr_dmui_context->prof_id; 
    data->hConfig = hconfig;
    data->result = status;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_GET_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
 
    OslMsgSendExtQueue(&message);    
}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_dm_send_cca_get_prof_rsp
* DESCRIPTION
*  This function to send profile information from DM PS
* PARAMETERS
*  app_id   [IN]
*  prof_id  [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_syncml_dm_send_cca_get_prof_rsp(U16 app_id, S32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]mmi_syncml_send_cca_dm_get_prof_rsp"); 

    ptr_dmui_context->app_id = app_id;
    ptr_dmui_context->prof_id = prof_id;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI] app_id = %d, prof_id = %d", app_id, prof_id);

    /* if server id array not init */
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[DM_DEFAULT_PROFILE_INDEX]) == 0)
		{
        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_FAIL);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]no valid default profile!");
		}

    if (dm_get_account(ptr_dmui_context->dmui_serverid_array[DM_DEFAULT_PROFILE_INDEX], 
            &ptr_dmui_context->dmui_cur_edit_account) == KAL_TRUE)
        {
        mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);
        
        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_OK);
        }
    else
    {
        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_FAIL);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]DM OTA dm_get_account failed");
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_dm_send_cca_update_prof_rsp
* DESCRIPTION
*  This function to receive update request from CCA
* PARAMETERS
*  app_id   [IN]
*  prof_id  [IN]
*  hConfig  [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_syncml_dm_send_cca_update_prof_rsp(U16 app_id, S32 prof_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_nodename[DM_MAX_ID_STR];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY, 
            CCA_NS_SYNCML_DM_PROXY,0xFFFF,
            CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PORT, 
            CCA_NS_SYNCML_DM_PORT,0xFFFF,
            CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PXAUTHINFO, 
            CCA_NS_SYNCML_DM_PXAUTHINFO,0xFFFF,            
            CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION, 
            CCA_NS_SYNCML_DM_APPLICATION,0xFFFF,
            CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPADDR,
            CCA_NS_SYNCML_DM_APPADDR,0xFFFF,
            CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_PORT,
            CCA_NS_SYNCML_DM_APPPORT,0xFFFF,
            CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPAUTH, 
            CCA_NS_SYNCML_DM_APPAUTH,0xFFFF
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]mmi_syncml_dm_send_cca_update_prof_rsp()"); 

    if (g_syncml_dm_ota_context == NULL) 
    {
        MMI_ASSERT(0);
    }

    memset(g_syncml_dm_ota_context, 0x00, sizeof(syncml_dm_ota_context_struct));

    ptr_dmui_context->app_id = app_id;
    
    ptr_dmui_context->prof_id = prof_id;
    
    ptr_dmui_context->hConfig = hConfig;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI] app_id = %d, prof_id = %d", app_id, prof_id);

    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

    mmi_cca_doc_process(hConfig, 
        proc_tbl,
        sizeof(proc_tbl) / sizeof(U16),
        NULL, 
        mmi_syncml_dm_proc_cca_nodes, 
        g_syncml_dm_ota_context);

    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (mmi_syncml_dm_get_valid_profile_num() == 0) 
    {        
        /* Now, terminate the SYNCML OTA provisioning application. */
        mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL)");
        return;
    }

    gui_itoa((U32)DM_DEFAULT_PROFILE_INDEX, (UI_string_type)temp_nodename, 10);

    {
        U8 tempprt[DM_MAX_ID_STR];

        mmi_ucs2_to_asc((S8*)tempprt, (S8*)temp_nodename);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI][Provisioning]node_name = %s \n", tempprt); 
    }

    mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[0].node_name, (S8*)temp_nodename);
    
    mmi_syncml_dm_set_value(&ptr_dmui_context->dmui_cur_edit_account, &g_syncml_dm_ota_context->profile[0]);

    mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);    

    /* add account struct to DM PS */
        if (dm_add_account(&ptr_dmui_context->dmui_cur_edit_account) == KAL_TRUE)
        {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[DM_DEFAULT_PROFILE_INDEX],
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);
            
        if (dm_set_pid((U8*)ptr_dmui_context->dmui_cur_edit_account.server_id) == KAL_TRUE)
        {
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid,
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);
            
            mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_OK);
            
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_OK)");
        }
        else
        {
            mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);

            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]primary serverid add error!!! \n");

            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL)");
        }

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS; 
        
        }
    else
    {
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
        
        mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);
        
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL)"); 
            }
        }

       
/*****************************************************************************
* FUNCTION
*  mmi_syncml_dm_send_cca_update_prof_end
* DESCRIPTION
*  This function to send update result to CCA
* PARAMETERS
*  cca_status_enum [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_syncml_dm_send_cca_update_prof_end(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;    
    mmi_cca_app_update_prof_rsp_struct *data;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
    data->app_id = ptr_dmui_context->app_id;
    data->prof_id = ptr_dmui_context->prof_id;
    data->hConfig = ptr_dmui_context->hConfig;
    data->result = status;
    
    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_UPDATE_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

#endif /* __MMI_SYNCML_DM_OTAP__ */


