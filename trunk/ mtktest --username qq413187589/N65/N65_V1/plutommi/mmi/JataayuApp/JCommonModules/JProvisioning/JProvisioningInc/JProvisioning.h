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
 * JProvisioning.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   header file for JProvisioning.c file
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JPROVISIONING_H
#define _JPROVISIONING_H

#include "MMI_features.h"
#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include "ddl.h"
#ifdef __MMI_JATAAYU_CCA_SUPPORT__

#include "MMIDataType.h"
#include "CentralConfigAgentGProt.h"
#include "JProvWap.h"
#include "JProfileHandlerTypes.h"

#define PROV_DEFAULT_PROF_ID  0
#define PROV_ACTIVATED_PROF_ID   CCA_PROF_CURRENT

#define PROV_PORT_443      443
#define PROV_PORT_9200     9200
#define PROV_PORT_9202     9202
#define PROV_PORT_9201     9201
#define PROV_PORT_9203     9203
#define PROV_PORT_80    80

typedef enum
{
    PROV_BRW_NODE_PROXY,
    PROV_BRW_NODE_PORT,
    PROV_BRW_NODE_PXAUTHINFO,
    PROV_BRW_NODE_APP,
    PROV_BRW_NODE_RESOURCE
} prov_brw_node_symbol_enum;

typedef enum
{
    PROV_MMS_NODE_PROXY,
    PROV_MMS_NODE_PORT,
    PROV_MMS_NODE_PXAUTHINFO,
    PROV_MMS_NODE_APP
} prov_mms_node_symbol_enum;

typedef enum
{
    BRW_PROV_APP_BROWSER,
    BRW_PROV_APP_MMS
} prov_application_type_enum;

#define PROV_PROXY_ID_LEN              (32)
#define PROV_PX_ADDR_LEN               (40)

#define PROV_DEFAULT_HTTP_PORT            (8080)
#define PROV_IP_PART_MAX_VALUE            (255)

#define MAX_PROFILE_COUNT 5
#define MAX_TO_RPOXY MAX_PROFILE_COUNT

#define PROV_NEW_LINE_SIZE                    5
#define PROV_DOT_SIZE                         8
#define PROV_COUNT_SIZE                       8
#define PROV_IP_ADDRESS_LEN                  17
#define PROV_MAX_PROXY_PORT_LENGTH            6
#define PROV_DISPLAY_INFO_SIZE              512
#define PROV_MAX_DISPLAY_PROFILE_NAME_LEN    16
#define PROV_MAX_DISPLAY_HOMEPAGE_URL_LEN    31
#define PROV_MAX_DISPLAY_DATA_ACCNT_NAME_LEN 16
#define PROV_BKM_TITLE_SIZE                  14
#define PROV_MIN_DISPLAY_BKM_INFO_SIZE       75

typedef struct
{
    U8 bm_title[PROV_BKM_TITLE_LEN *ENCODING_LENGTH];
    U8 bm_url[PROV_BKM_URL_LEN];
} prov_bookmark_content_struct;

typedef struct
{
    U8 px_primary_dataacc_id;
    U8 px_secondary_dataacc_id;
    /* U8 px_dcs; */
    U8 px_id[PROV_PROXY_ID_LEN];
    U8 px_addr[PROV_PX_ADDR_LEN];
    U16 px_addrtype;
    U8 px_service;
    U16 px_port;
    U8 px_authid[NVRAM_WAP_PROFILE_USERNAME_LEN];
    U8 px_authpw[NVRAM_WAP_PROFILE_PASSWORD_LEN];
    U8 px_name[NVRAM_WAP_PROFILE_NAME_LEN];
    U8 px_startpage[NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN];
} prov_proxy_content_struct;

typedef struct
{
    /* U8 app_dcs; */
    U8 *app_to_proxy[MAX_PROFILE_COUNT];
    U8 app_url[NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN];
    U8 app_name[NVRAM_WAP_PROFILE_NAME_LEN];
} prov_application_content_struct;

typedef struct prov_proxy_list_struct prov_proxy_list_struct;
typedef struct prov_proxy_list_struct
{
    prov_proxy_content_struct *proxy_content;
    prov_proxy_list_struct *proxy_list_next;

} prov_proxy_list_struct;

typedef struct prov_app_list_struct prov_app_list_struct;
typedef struct prov_app_list_struct
{
    prov_application_content_struct *app_content;
    prov_app_list_struct *app_list_next;

} prov_app_list_struct;

typedef struct prov_bkm_list_struct prov_bkm_list_struct;
typedef struct prov_bkm_list_struct
{
    prov_bookmark_content_struct *bkm_content;
    prov_bkm_list_struct *bkm_list_next;

} prov_bkm_list_struct;

typedef struct prov_wap_profile_list_struct prov_wap_profile_list_struct;
typedef struct prov_wap_profile_list_struct
{
    U8 profile_name[NVRAM_WAP_PROFILE_NAME_LEN];
    nvram_wap_profile_content_struct *profile_content;
    prov_wap_profile_list_struct *profile_list_next;

} prov_wap_profile_list_struct;

typedef struct prov_mms_profile_list_struct prov_mms_profile_list_struct;
typedef struct prov_mms_profile_list_struct
{
    U8 profile_name[NVRAM_WAP_PROFILE_NAME_LEN];
    nvram_mms_profile_content_struct *profile_content;
    prov_mms_profile_list_struct *profile_list_next;

} prov_mms_profile_list_struct;

typedef struct
{
    U8 prov_type;
    U8 profile_count;
    U16 config_id;
    S32 config_h;
    prov_proxy_list_struct *proxy_list;
    prov_app_list_struct *app_list;
    prov_bkm_list_struct *bkm_list;
    prov_wap_profile_list_struct *wap_profile_list;
    prov_mms_profile_list_struct *mms_profile_list;
} prov_context_struct;

extern void mmi_prov_new_brw_setting_ind(mmi_cca_app_configure_ind_struct *newConfigDoc);
extern void mmi_prov_new_mms_setting_ind(mmi_cca_app_configure_ind_struct *newConfigDoc);
extern cca_status_enum mmi_prov_brw_nodes_process_callback(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);
extern cca_status_enum mmi_prov_alloc_proxy_node(void);
extern prov_proxy_content_struct *mmi_prov_get_current_proxy_node_content(void);
extern cca_status_enum mmi_prov_alloc_app_node(void);
extern prov_application_content_struct *mmi_prov_get_current_app_node_content(void);
extern cca_status_enum mmi_prov_alloc_bkm_node(void);
extern prov_bookmark_content_struct *mmi_prov_get_current_bkm_node_content(void);
extern void mmi_prov_free_last_bkm_node(void);
extern cca_status_enum mmi_prov_copy_data_value(U8 *src_ptr, cca_core_data_struct *data, U16 data_length, U8 str_dcs);
extern cca_status_enum mmi_prov_proxy_node_handler(cca_iterator_struct *iter_datalist);
extern cca_status_enum mmi_prov_port_node_handler(cca_iterator_struct *iter_datalist);
extern cca_status_enum mmi_prov_pxauthinfo_node_handler(cca_iterator_struct *iter_datalist);
extern cca_status_enum mmi_prov_application_node_handler(cca_iterator_struct *iter_datalist);
extern cca_status_enum mmi_prov_resource_node_handler(cca_iterator_struct *iter_datalist);
extern cca_status_enum mmi_prov_mms_nodes_process_callback(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);

extern void mmi_prov_handle_port_params(U16 *px_port, S8 *portnbr_parm, S32 default_portnbr_parm);
extern cca_status_enum mmi_prov_merge_proxy_application_node_list(void);
extern cca_status_enum mmi_prov_create_wap_profile_list(
                        prov_proxy_content_struct *proxy_content,
                        prov_application_content_struct *app_content);
extern cca_status_enum mmi_prov_create_mms_profile_list(
                        prov_proxy_content_struct *proxy_content,
                        prov_application_content_struct *app_content);
extern prov_mms_profile_list_struct *mmi_prov_get_current_mms_profile_node(void);
extern prov_wap_profile_list_struct *mmi_prov_get_current_wap_profile_node(void);
extern void mmi_prov_free_proxy_app_nodes(void);
extern void mmi_prov_entry_show_setting_info(void);
extern void mmi_prov_create_display_info_for_browser(U8 *display_info);
extern void mmi_prov_create_display_info_for_mms(U8 *display_info);
extern void mmi_prov_skip_profile(void);
extern void mmi_prov_skip_profile_callback(void);
extern void mmi_prov_install_setting(void);
extern U8 mmi_prov_get_profile_node_count(void);
extern void mmi_prov_end_key_handler(void);
extern void mmi_prov_show_next_profile_info(MMI_BOOL prof_screen_exist);
extern void mmi_prov_send_response(cca_status_enum status);
extern void mmi_prov_cca_app_config_req_hdlr(void *msg);
extern cca_status_enum mmi_prov_alloc_wap_profile_node(void);
extern cca_status_enum mmi_prov_alloc_mms_profile_node(void);
extern cca_status_enum mmi_prov_handle_to_proxy_params(
                        prov_application_content_struct *app_content,
                        cca_core_data_struct *data);
extern U8 mmi_prov_get_bookmark_node_count(void);
extern void mmi_prov_free_mem(void);
extern void mmi_prov_free_bookmark_nodes(void);
extern void mmi_prov_free_profile_nodes(void);

#ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__

extern void mmi_prov_cca_dm_init(void);
extern bf_bool mmi_prov_cca_dm_check_func(void);
extern PROV_RETCODE mmi_prov_cca_dm_check_set_prof_id(S32 prof_id, S32 max_prof_id);
extern S32 mmi_prov_cca_dm_check_get_prof_id(S32 prof_id, S32 max_prof_id);
extern cca_status_enum mmi_prov_cca_dm_update_brw_profile(S32 doc_config_h, S32 prof_id);
extern cca_status_enum mmi_prov_cca_dm_update_mms_profile(S32 doc_config_h, S32 prof_id);
extern void mmi_prov_cca_dm_update_prof_ind(void *msg);
extern void mmi_prov_cca_dm_get_prof_ind(void *msg);
extern S32 mmi_prov_cca_dm_construct_brw_doc(prov_wap_profile_list_struct *wap_profile_list);
extern S32 mmi_prov_cca_dm_construct_mms_doc(prov_mms_profile_list_struct *mms_profile_list);
extern cca_oma_values_enum mmi_prov_cca_dm_convert_conn_type(U8 conn_type, U16 port_parm);

#endif /* __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */ /* #ifdef __MMI_JATAAYU_SYNCML_DM_SUPPORT__ */
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* _JPROVISIONING_H */ 

