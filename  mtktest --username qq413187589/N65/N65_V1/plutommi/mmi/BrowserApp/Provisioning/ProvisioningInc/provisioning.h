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
 * JProfileHandlerProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares the function prototypes for the profile handler module
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CentralConfigAgentGProt.h"
#include "custom_nvram_editor_data_item.h"
#include "ProfileHandlerTypes.h"
#include "DataAccountDef.h"
#include "DataAccountGprot.h"
#ifdef SYNCML_DM_SUPPORT
#include "cbfunc.h"
#endif
#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__
typedef enum
{
    BRW_PROV_BROWSER_PROXY = 0,
    BRW_PROV_BROWSER_PORT,
    BRW_PROV_BROWSER_AUTHINFO,
    BRW_PROV_BROWSER_APP,
    BRW_PROV_BROWSER_RESOURCE
} prov_brw_node_symbol_enum;

typedef enum
{
    BRW_PROV_MMS_PROXY = 0,
    BRW_PROV_MMS_PORT,
    BRW_PROV_MMS_AUTHINFO,
    BRW_PROV_MMS_APP
} prov_mms_node_symbol_enum;

typedef enum
{
    BRW_PROV_APP_BROWSER,
    BRW_PROV_APP_MMS
} prov_application_type_enum;

typedef enum
{
    VALIDATION_SUCCESS = 0,
    VALIDATION_FAILURE
} prov_validation_enum;

typedef enum
{
    PROV_OK,
    PROV_ERR
} prov_ret_code_enum;

const U16 cca_mapping_browser[] = {CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, BRW_PROV_BROWSER_PROXY, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, BRW_PROV_BROWSER_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, BRW_PROV_BROWSER_AUTHINFO, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, BRW_PROV_BROWSER_APP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_RESOURCE, BRW_PROV_BROWSER_RESOURCE, 0xFFFF,
};

const U16 cca_mapping_mms[] = {CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, BRW_PROV_MMS_PROXY, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, BRW_PROV_MMS_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, BRW_PROV_MMS_AUTHINFO, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, BRW_PROV_MMS_APP, 0xFFFF
};

//#define PROV_APPLICATION_APP_NAME_LEN     (16)
//#define PROV_APPLICATION_APP_ID_LEN       (16)
#define PROV_PROXY_ID_LEN              (32)
#define PROV_PX_ADDR_LEN               (40)
//#define PROV_PROXY_NAME_LEN               (31)
//#define PROV_PX_AUTH_ID_LEN               (16)
//#define PROV_PX_AUTH_PWD_LEN           (16)

//#define  MAX_PART_IP_ADDRESS           (4)

#define PROV_DEFAULT_HTTP_PORT            (8080)
#define PROV_IP_PART_MAX_VALUE            (255)

#define MAX_PROFILE_COUNT 5
#define MAX_BOOKMARK_COUNT 5
#define MAX_BOOKMARK_TITLE_LEN	NVRAM_PROFILE_NAME_LEN
#define MAX_BOOKMARK_URL_LEN	NVRAM_PROFILE_URL_LEN
#define MAX_TO_RPOXY MAX_PROFILE_COUNT

#define     PROV_NEW_LINE_SIZE                5
#define     PROV_COUNT_SIZE                 8
#define		PROV_EXTRA_BYTES				400+(NVRAM_PROFILE_URL_LEN*4)
#define     PROV_DISPLAY_INFO_SIZE            sizeof(prov_profile_context_struct)+PROV_EXTRA_BYTES
#define		MMI_PROV_DEFAULT_INDEX			-1

typedef struct
{
	U8	bm_title[MAX_BOOKMARK_TITLE_LEN * ENCODING_LENGTH];
	U8  bm_url[MAX_BOOKMARK_URL_LEN];
}prov_bookmark_struct;

typedef struct
{
    S8 primary_dataacc_id;
    S8 secondary_dataacc_id;
    U8 conn_type;
    U8 dcs;
    U16 proxy_port;
    U8 proxy_ip[4];
    U8 url[NVRAM_PROFILE_URL_LEN];
    U8 name[(NVRAM_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 username[NVRAM_PROFILE_USERNAME_LEN];
    U8 password[NVRAM_PROFILE_PASSWORD_LEN];
	S16 bookmark_count;
	prov_bookmark_struct *bookmark[MAX_BOOKMARK_COUNT];
} prov_profile_context_struct;

typedef struct
{
    S8 px_primary_dataacc_id;
    S8 px_secondary_dataacc_id;
    U8 px_dcs;
    U8 px_id[PROV_PROXY_ID_LEN];
    U8 px_addr[PROV_PX_ADDR_LEN];
    U8 px_addrtype;
    U8 px_service;
    U16 px_port;
    U8 px_authid[NVRAM_PROFILE_USERNAME_LEN];
    U8 px_authpw[NVRAM_PROFILE_PASSWORD_LEN];
    U8 px_name[(NVRAM_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 px_startpage[NVRAM_PROFILE_URL_LEN];
} prov_proxy_content_struct;

typedef struct
{
    U8 app_dcs;
    U8 *app_to_proxy[MAX_PROFILE_COUNT];
    U8 app_url[NVRAM_PROFILE_URL_LEN];
    U8 app_name[(NVRAM_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH];
	S16 bookmark_count;
	prov_bookmark_struct *bookmark[MAX_BOOKMARK_COUNT];
} prov_application_content_struct;


typedef enum
{
    SCR_ID_PROV_HDLR_LIST = JATAAYU_PROVISIONING_BASE + 50,
    SCR_ID_PROV_INFO_DISPLAY,
	SCR_ID_PROV_DUMMY
} scr_provisioning_list_enum;

extern void mmi_prov_browser_profile_handle_configuration_document(S32 hConfig);
extern void mmi_prov_mms_profile_handle_configuration_document(S32 hConfig);

extern cca_status_enum mmi_prov_browser_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);

extern cca_status_enum mmi_prov_mms_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);

extern prov_validation_enum mmi_prov_validate_setting(void);
//extern prov_validation_enum mmi_prov_mms_validate_setting(void);

extern void mmi_prov_merge_proxy_application_node_list(void);

extern void mmi_prov_browser_handle_proxy_params(
                prov_proxy_content_struct *proxy_content,
                cca_core_data_struct *data);
extern void mmi_prov_browser_handle_application_params(
                prov_application_content_struct *application_content,
                cca_core_data_struct *data);
extern void mmi_prov_browser_handle_resource_params(
				prov_application_content_struct *application_content,
				cca_core_data_struct *data);
extern void mmi_prov_browser_handle_port_params(
                prov_proxy_content_struct *proxy_content,
                S8 *portnbr_parm,
                S32 default_portnbr_parm);
extern void mmi_prov_browser_handle_service_params(
                prov_proxy_content_struct *proxy_content,
                S32 service_parm,
                S8 *portnbr_parm);
extern S32 mmi_prov_check_ip(S8 *s);
extern U8 mmi_prov_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p);

extern void mmi_prov_create_profile(
                prov_application_content_struct *app_node,
                prov_proxy_content_struct *proxy_node,
                S16 proxy_index);

extern void mmi_prov_fill_name_parm(U8 *name, U8 dcs);
extern void mmi_prov_fill_url_parm(prov_application_content_struct *app_node, prov_proxy_content_struct *proxy_node);
extern void mmi_prov_fill_other_parm(prov_proxy_content_struct *proxy_node);
extern void mmi_brw_fill_bookmark_parm(prov_application_content_struct *app_node);

extern pBOOL mmi_prov_fill_profile_list_by_proxy(void);

extern void mmi_prov_commit_setting(void);

extern void mmi_prov_free_proxy_app_nodes(void);

extern void mmi_prov_send_end_key_event(void);
extern pBOOL mmi_prov_end_key_callback(void);
extern void mmi_prov_send_response(cca_status_enum status);
extern void mmi_brw_prov_get_content_from_setting(void);
extern S32 mmi_prov_dm_browser_construct_doc(nvram_profile_content_struct *profile_content,S32 prof_index,
								  cca_state_enum status);
extern S32 mmi_prov_dm_mms_construct_doc(nvram_profile_content_struct *profile_content,S32 prof_index,
								  cca_state_enum status);
#ifdef SYNCML_DM_SUPPORT
extern void mmi_prov_dm_app_recv_prof_ind(void *msg);
extern void mmi_prov_dm_app_update_prof_ind(void *msg);
extern cca_state_enum mmi_prov_dm_brw_update_profile(S32 hConfig, S32 index, S32 profile_count, 
													 prof_profile_enum profile_type);
extern cca_oma_values_enum mmi_prov_dm_get_conn_type(prof_conn_type_enum conn_type, U16 port_parm);
#endif
extern void mmi_prov_init(void);
extern void rsk_handling_profile_content_display(void);
extern void mmi_brw_prov_update_remaining_profile_count(void);
extern void mmi_brw_prov_create_display_info(void);
S8* mmi_brw_prov_get_bearer_name(S8 data_acc_id);
extern void mmi_brw_prov_delete_screen(void);
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_prov_check_bookmark(void);
#endif
extern void mmi_brw_skip_profile(void);
extern void mmi_prov_send_cca_status(void);

#ifdef SYNCML_DM_SUPPORT
bf_bool browser_check_func(void);
bf_bool mms_check_func(void);
#endif

#endif