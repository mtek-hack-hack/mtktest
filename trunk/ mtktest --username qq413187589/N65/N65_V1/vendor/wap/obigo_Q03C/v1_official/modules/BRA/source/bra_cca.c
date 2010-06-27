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
 *
 * Filename:
 * ---------
 * bra_cca.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   CCA provisioning & DM profile handler
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 *
 *******************************************************************************/



#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif 

#ifdef BRA_CFG_CCA


#ifdef BRA_CONFIG_PROVISIONING
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#include "msf_chrs.h"
#include "msf_log.h"
#include "msf_url.h"

#include "bra_prof.h"
#include "bra_sig.h"
#include "bra_prs.h"
#include "bra_main.h"
#include "bra_cmn.h"
#include "bra_dlg.h"
#include "bra_bkm.h"
#include "bra_view.h"
#include "bra_if.h"
#include "bra_sif.h"
#include "bra_set.h"
#include "bra_req.h"
#include "bra_cca.h"
#include "bra_str.h"

#include "prs_if.h"
#include "prs_def.h"
#include "prs_cnst.h"

#ifdef __TCPIP__
#include "kal_release.h"          /* Basic data type */

#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"           /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"          /* Task creation */
#include "custom_config.h"

#include "stacklib.h"             /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h"           /* Event scheduler */

#include "stack_timer.h"          /* Stack timer */

#include "app_buff_alloc.h"

#include "nvram_data_items.h"

#include "l3_inc_enums.h"
#include "l4a.h"
#include "custom_data_account.h"
#include "custom_mmi_default_value.h"

#endif /*__TCPIP__ */

 
#include "CentralConfigAgentGprot.h"


#ifdef BRA_CFG_DM
#include "bftype.h"
#include "cbfunc.h"
#endif


#include "bra_cbm.h"


#ifndef BRA_CFG_CCA_SHOW_WHOLE_PROF
//#define BRA_CFG_CCA_SHOW_WHOLE_PROF
#endif


/**********************************************************************
 * Constant Defines
 **********************************************************************/


#ifdef BRA_CFG_PROV_MULTI_BEARER
#define BRA_CCA_MAX_NBR_BEARERS                 (2) 
#else
#define BRA_CCA_MAX_NBR_BEARERS                 (1)
#endif

    

#define BRA_CCA_DATA_ACCOUNT_NAME_MAX_SIZE      (128)

#define BRA_CCA_IP_MAX_SEGMENT                  (4)
#define BRA_CCA_NUMBER_MAX_DIGIT                (20)

#define BRA_CCA_PORT_MAX_NUM                    (6)
#define BRA_CCA_PORT_MIN_VALUE                  (0)
#define BRA_CCA_PORT_MAX_VALUE                  (65535)

#define BRA_CCA_PORT_HTTP_DEFAULT               (80)
#define BRA_CCA_PORT_WSP_CL                     (9200)
#define BRA_CCA_PORT_WSP_CO                     (9201)
#define BRA_CCA_PORT_WSP_SEC_CL                 (9202)
#define BRA_CCA_PORT_WSP_SEC_CO                 (9203)


#define BRA_CCA_DEFAULT_MMS_HOMEPAGE            "http://mms"
#define BRA_CCA_DEFAULT_PROXY_ADDR              "0.0.0.0"

#define BRA_CCA_NODE_ID_PROXY                   "proxy_node"
#define BRA_CCA_NODE_ID_PORT                    "port_node"
#define BRA_CCA_NODE_ID_PXAUTHINFO              "pxauth_node"
#define BRA_CCA_NODE_ID_APPLICATION             "app_node"
#define BRA_CCA_NODE_ID_RESOURCE                "res_node"

#define BRA_CCA_PROXY_ID                        "proxy_id"
#define BRA_CCA_APP_ID_WAP                      "w2"
#define BRA_CCA_APP_ID_MMS                      "w4"


/**********************************************************************
 * enum Defines
 **********************************************************************/

typedef enum
{
    BRA_CCA_DOC_TYPE_PRV,
    BRA_CCA_DOC_TYPE_DM,
    BRA_CCA_DOC_TYPE_MAX_ITEM
}bra_cca_doc_type_enum;


typedef enum
{
    BRA_CCA_NS_PROXY,
    BRA_CCA_NS_PORT,
    BRA_CCA_NS_PXAUTHINFO,
    BRA_CCA_NS_APPLICATION,
    BRA_CCA_NS_RESOURCE,
    BRA_CCA_NS_MAX_ITEM
}bra_cca_symbol_enum;


typedef struct bra_cca_list_head
{
    struct bra_cca_list_head *next;
}bra_cca_list_head_t;


typedef struct
{
    
    int         type;                                  /*HDI_SOCKET_BEARER_GSM_CSD or HDI_SOCKET_BEARER_GSM_GPRS now*/
    int         id;                                    /*data account id*/
    char        *name;                                 /*name==NULL && id == -1: invalid*/
}bra_cca_data_account_t;


typedef struct bra_cca_proxy
{   
    struct bra_cca_proxy    *next;                     /*should be the first element*/
    char                    *proxy_id;                 /*proxy-id*/
    char                    *proxy_name;               /*use for profile name*/ 

    char                    *homepage;                 /*homepage in proxy node*/

    char                    *proxy_addr;               /*proxy address , only the first node used, if is "0.0.0.0", it's a fake proxy node*/
    int                     conn_type;                 /*connection type  http or wsp*/
    int                     port;                      /*proxy port    only for http*/
    int                     sec_mode;
    int                     data_acct_num;
    char                    *data_acct_name;           /*only use for multi bearer.*/
    bra_cca_data_account_t  data_account[BRA_CCA_MAX_NBR_BEARERS];

    int                     auth_parsed;
    char                    *username;                 /*proxy username, use the first proxy/authinfo node*/
    char                    *password;                 /*proxy password*/
}bra_cca_proxy_t;


typedef struct bra_cca_resource                        /*bookmark list or homepage*/
{
    struct bra_cca_resource *next;                     /*should be the first element*/
    char                    *homepage;
    char                    *title;
    char                    *url;
}bra_cca_resource_t;


typedef struct bra_cca_proxy_id
{
    struct bra_cca_proxy_id *next;                     /*should be the first element*/
    char                    *proxy_id;
}bra_cca_proxy_id_t;


typedef struct bra_cca_application
{
    struct bra_cca_application  *next;                 /*should be the first element*/
    char                        *app_id;               /*application id */
    char                        *name;                 /*may use for profile name*/

    bra_cca_proxy_id_t          *curr_proxy_id;        /*use for install*/
    bra_cca_proxy_id_t          *proxy_id_list;

    char                        *addr;                 /*mmsc address application/addr or application/appaddr/addr  may be homepage priority high*/
    
    int                         is_res_updated;
    bra_cca_resource_t          *curr_res;
    bra_cca_resource_t          *res_list;
}bra_cca_application_t;


typedef struct  bra_cca_profile
{   
    struct bra_cca_profile  *next;                     /*should be the first element*/
    bra_cca_proxy_t         *proxy;                    /*pointer to item in proxy node list*/
    bra_cca_application_t   *application;              /*pointer to item in application node list*/
    int                     sel_prof_id;               /*profile id selected to update*/
    cca_status_enum         result;    
}bra_cca_profile_t;


typedef struct
{
    MSF_UINT16  config_id;
    MSF_UINT16  app_id;
    MSF_INT32   prof_id; 
    MSF_INT32   hConfig;
}bra_cca_ind_t;


typedef struct
{
    bra_cca_doc_type_enum   cca_doc_type;              /*cca document type*/
    bra_cca_profile_t       *curr_prof;
    bra_cca_profile_t       *prof_list;                /*valid profile, the first profile is defined by the first application node, may all are install to one profile, so no limit here*/

    bra_cca_proxy_t         *curr_proxy;
    bra_cca_proxy_t         *proxy_list;               /*all proxy node parsed*/

    bra_cca_application_t   *curr_app;
    bra_cca_application_t   *app_list;                 /*all application node parsed*/
}bra_cca_doc_t;


typedef struct
{
    int                 sim_id;                         /*sim id */
    int                 prof_type;                     /*profile type: wap or mms*/
    bra_cca_ind_t       cca_ind;                       /*cca message indication*/
    bra_cca_doc_t       cca_doc;                       /*cca doc parsed, any profile invalid would be discarded*/
    cca_status_enum     result;
    int                 next_prof_id;                  /*the start index of profile id to check whether is free profile*/
}bra_cca_context_t;


/* Select Profile menu */
typedef struct {
    MsfWindowHandle window;
    MsfActionHandle select;
    MsfActionHandle back;
} bra_cca_prof_menu_t;


const U16 bra_cca_mapping_table[] = 
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, BRA_CCA_NS_PROXY,0xFFFF, 
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, BRA_CCA_NS_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, BRA_CCA_NS_PXAUTHINFO, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, BRA_CCA_NS_APPLICATION, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_RESOURCE, BRA_CCA_NS_RESOURCE, 0xFFFF
};



static bra_cca_context_t *bra_cca_cntx = NULL;






/**********************************************************************
* BRA_SIG_CCA_APP_CONFIGURE_IND handler 
**********************************************************************/

/*utilities*/

static void
bra_cca_list_add_node_by_iter(bra_cca_list_head_t **list, 
                              bra_cca_list_head_t **curr_node,
                              bra_cca_list_head_t *node);


/*app configure response*/
static void
bra_cca_handle_app_configure_result(void);

static void
bra_cca_send_app_configure_rsp(MSF_UINT16 bra_sim_id, MSF_UINT16 config_id, MSF_INT32 hConfig, cca_status_enum result);

static cca_status_enum
bra_cca_get_app_configure_status_returned(cca_status_enum result);

/*structure free operation*/

static void 
bra_cca_free_context(bra_cca_context_t* p);

static void
bra_cca_free_cca_ind(bra_cca_ind_t* p);

static void
bra_cca_free_cca_doc(bra_cca_doc_t* p);

static void
bra_cca_free_profile_list(bra_cca_profile_t *list);

static void
bra_cca_free_proxy_list(bra_cca_proxy_t *list);

static void 
bra_cca_free_proxy_node(bra_cca_proxy_t* p);

static void
bra_cca_free_application_list(bra_cca_application_t *list);

static void
bra_cca_free_application_node(bra_cca_application_t* p);

static void
bra_cca_free_proxy_id_list(bra_cca_proxy_id_t *list);

static void
bra_cca_free_res_list(bra_cca_resource_t *res_list);

static void
bra_cca_free_resource_node(bra_cca_resource_t *res);


/*cca document node callback*/
static cca_status_enum
bra_cca_doc_node_callback(S32 hConfig, S32 hNode, U16 node_symbol,
                          cca_iterator_struct *iter_datalist, void *user_data);


/*cca document parser*/
static cca_status_enum
bra_cca_parse_proxy_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_parse_proxy_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data);

static cca_status_enum
bra_cca_parse_data_account(bra_cca_proxy_t *proxy, cca_core_data_struct *data);

static cca_status_enum
bra_cca_parse_port_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_parse_port_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data);

static int
bra_cca_is_wsp_cl_type_port_node(int conn_type,  int port);

static cca_status_enum
bra_cca_parse_pxauthinfo_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_parse_pxauthinfo_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data);

static char*
bra_cca_parse_authinfo_string(cca_core_data_struct *data, int max_len);

static cca_status_enum
bra_cca_parse_application_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_parse_application_params(bra_cca_application_t *app, cca_core_data_struct *data);

static cca_status_enum
bra_cca_parse_application_proxy_id(bra_cca_application_t *app, cca_core_data_struct *data);

static cca_status_enum
bra_cca_parse_resource_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_parse_resource_params(bra_cca_resource_t *res, cca_core_data_struct *data);

static char*
bra_cca_parse_utf8_name(const cca_core_data_struct *data);

static char*
bra_cca_parse_url(const cca_core_data_struct *data);

static char*
bra_cca_make_complete_url(const char* url);

static void
bra_cca_clean_up_url (char *url);


/*profile list creation and validation*/
static cca_status_enum
bra_cca_create_valid_profile_list(int prof_type, bra_cca_doc_t *cca_doc);

static bra_cca_profile_t * 
bra_cca_create_valid_profile(int prof_type, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_delete_invalid_application_from_list(int prof_type, bra_cca_application_t **list);

static cca_status_enum
bra_cca_delete_invalid_resource_from_list(int prof_type, bra_cca_resource_t **list);

static cca_status_enum
bra_cca_delete_invalid_proxy_from_list(int prof_type, bra_cca_proxy_t **list);
static void
bra_cca_set_duplicated_proxy_to_invalid(bra_cca_proxy_t *list, bra_cca_proxy_t *proxy);


static cca_status_enum
bra_cca_validate_application(int prof_type, bra_cca_application_t *app);

static cca_status_enum
bra_cca_validate_proxy(int prof_type, bra_cca_proxy_t *proxy);

static cca_status_enum
bra_cca_validate_profile(int prof_type, bra_cca_profile_t *prof);

static void
bra_cca_revise_bookmark(bra_cca_resource_t *res_list);

static void
bra_cca_revise_conn_type_and_port(int *conn_type, int *port, int sec_mode);

static int
bra_cca_get_conn_type_by_port(int port);

static int
bra_cca_get_port_by_conn_type(int conn_type, int sec_mode);

static void 
bra_cca_doc_get_profile_restart(bra_cca_doc_t *cca_doc);

static bra_cca_application_t * 
bra_cca_doc_get_profile_next(bra_cca_doc_t *cca_doc);

static bra_cca_proxy_t *
bra_cca_get_proxy_node_by_id(bra_cca_proxy_t *proxy_list, const char *proxy_id);


/*install next profile*/

static int
bra_cca_is_all_profiles_installed(void);

static void
bra_cca_handle_all_profiles_installed(void);

static void
bra_cca_activate_profile(int prof_type, int sim_id, int prof_id); 

static cca_status_enum
bra_cca_get_profile_list_install_result(bra_cca_doc_t *cca_doc);


/*profile information menu*/
static void
bra_cca_create_profile_info_menu(void);

static void
bra_cca_delete_profile_info_menu(bra_win_t *win);

static void
bra_cca_action_profile_info_menu (ctk_screen_handle scrid);

static void
bra_cca_action_skip_profile (ctk_screen_handle scrid);

static void 
bra_cca_skip_profile_confirmation(MsfActionType response);


/*profile information collection*/

static kal_uint8*
bra_cca_generate_key_value(kal_uint8* src, int *allocated_size, 
                           int key_id, const kal_uint8* value, int value_id);

static kal_uint8*
bra_cca_generate_profile_info_head(kal_uint8 *text, int *text_size,
                                   int prof_type, bra_cca_doc_t *cca_doc);

static kal_uint8*
bra_cca_generate_profile_info_body(kal_uint8 *text, int *text_size,
                                   int prof_type, bra_cca_profile_t *profile);

static kal_uint8*
bra_cca_generate_proxy_info(kal_uint8 *text, int *text_size, bra_cca_proxy_t *proxy);

static kal_uint8*
bra_cca_generate_bookmark_info(kal_uint8* text, int *text_size, bra_cca_application_t *app);


static int
bra_cca_get_profile_number(bra_cca_profile_t * list);

static int
bra_cca_get_current_profile_index(bra_cca_profile_t *list, bra_cca_profile_t *curr_prof);

static int
bra_cca_get_bookmark_number(bra_cca_resource_t* res_list);

/*get profile key-value*/
static char*
bra_cca_get_profile_name(bra_cca_profile_t *profile);

static int
bra_cca_get_profile_homepage(int prof_type, bra_cca_profile_t *profile, char**title, char** url);

#ifdef BRA_CFG_CCA_SHOW_WHOLE_PROF
static char*
bra_cca_get_muliti_data_account_name(bra_cca_proxy_t *proxy);
#endif

static int
bra_cca_get_bearer_type_string_id(bra_cca_proxy_t *proxy);

static int
bra_cca_is_simple_bookmak_setting(int prof_type, bra_cca_profile_t *profile);


/*profile selection menu*/
static void
bra_cca_create_profile_select_menu(void);

static void 
bra_cca_action_delete_profile_select_menu (bra_win_t *win);

static void
bra_cca_action_profile_select_menu (bra_win_t *win, MSF_UINT32 bra_action);

/**/
static int
bra_cca_can_replace_profile_in_using(int prof_type, int prof_id);

/*get free profile*/
static int 
bra_cca_get_next_free_profile_id(int prof_type, int sim_id, int *next_prof_id);

static int
bra_cca_is_free_profile(int prof_type, bra_cca_profile_t *profile);

static int
bra_cca_is_mmsc_addr_valid(const char* addr);

static int
bra_cca_is_zero_proxy_address(const char *addr);


/*update profile*/
static void
bra_cca_update_current_profile(void);

static cca_status_enum
bra_cca_update_profile_by_id(bra_cca_doc_type_enum cca_doc_type,
                             int prof_type, int sim_id, int prof_id, bra_cca_profile_t *profile);

static cca_status_enum
bra_cca_update_profile_name(int prof_type, bra_cca_profile_t *profile);

static cca_status_enum
bra_cca_update_profile_homepage(int prof_type,  bra_cca_profile_t *profile);

static cca_status_enum
bra_cca_update_profile_proxy(int prof_type, bra_cca_proxy_t *proxy);

static cca_status_enum
bra_cca_update_profile_data_account(int prof_type, bra_cca_proxy_t *proxy);

static cca_status_enum
bra_cca_update_profile_bookmark(int prof_type, bra_cca_application_t *app);



/**********************************************************************
* BRA_SIG_CCA_GET_PROF_IND handler 
**********************************************************************/
/*send response*/
static void
bra_cca_send_get_profile_rsp(MSF_UINT16 bra_sim_id,
                             MSF_UINT16 app_id, 
                             MSF_INT32 prof_id, 
                             MSF_INT32 hConfig,
                             cca_status_enum result);

/*indication validation*/
static cca_status_enum
bra_cca_validate_app_id_and_prof_id(int app_id, int prof_id);

static int 
bra_cca_can_get_profile(int prof_type, int sim_id, int prof_id);

static int
bra_cca_can_allow_dm_operations(int prof_type, int sim_id, int prof_id);

static int
bra_cca_is_activated_profile_in_using(int prof_type);  

static void
bra_cca_get_default_profile_info(bra_cca_get_prof_ind_t *get_prof_ind,
                                 bra_cca_proxy_t *proxy,
                                 bra_cca_application_t *app,
                                 bra_cca_resource_t *res);

static void  
bra_cca_get_profile_info(bra_cca_get_prof_ind_t *get_prof_ind,
                         bra_cca_proxy_t *proxy,
                         bra_cca_application_t *app,
                         bra_cca_resource_t *res); /*res only use to get browser homepage*/


static void
bra_cca_get_real_conn_type_and_port(int prof_type, int *conn_type,  int *port);

/*create cca document*/
static cca_status_enum
bra_cca_create_cca_doc(bra_cca_get_prof_ind_t* get_prof_ind, 
                       S32 *hConfig);

static cca_status_enum 
bra_cca_create_cca_doc_node_tree(bra_cca_get_prof_ind_t *get_prof_ind,
                                 S32* hRoot);

static cca_status_enum
bra_cca_create_proxy_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                     bra_cca_proxy_t *proxy_info);

static cca_status_enum
bra_cca_create_port_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                    bra_cca_proxy_t *proxy_info);

static cca_status_enum
bra_cca_create_authinfo_node_add_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                        bra_cca_proxy_t *proxy_info);

static cca_status_enum
bra_cca_create_application_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                           bra_cca_application_t *app_info);

static cca_status_enum
bra_cca_create_resource_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind,
                                       bra_cca_resource_t *res_info);



/**********************************************************************
* BRA_SIG_CCA_UPDATE_PROF_IND handler 
**********************************************************************/

/*send response*/
static void
bra_cca_handle_update_profile_result(bra_cca_update_prof_ind_t *update_prof_ind, cca_status_enum result, bra_cca_doc_t *cca_doc);

static void
bra_cca_send_update_profile_rsp(MSF_UINT16 bra_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id, MSF_INT32 hConfig, cca_status_enum result);

/*update profile*/

static int
bra_cca_get_absolute_prof_id(int sim_id, int app_id, int dm_prof_id);

static int
bra_cca_can_update_profile(int prof_type, int sim_id, int prof_id);

static cca_status_enum
bra_cca_create_dm_profile(int prof_type, bra_cca_doc_t *cca_doc);

static cca_status_enum
bra_cca_revise_dm_profile(int prof_type, bra_cca_profile_t *profile);

static void
bra_cca_revise_dm_conn_type_and_port(int prof_type, int *conn_type, int *port);


/**********************************************************************
* DM check function
*for get/update are generate operations, 
*so we do not include them to BRA_CFG_DM macro 
**********************************************************************/
#ifdef BRA_CFG_DM

static void
bra_cca_register_dm_check_function(void);

static bf_bool
bra_cca_dm_wap_check_function(void);

#ifdef BRA_CONFIG_MMS
static bf_bool
bra_cca_dm_mms_check_function(void);
#endif /* BRA_CONFIG_MMS */

#endif /*BRA_CFG_DM*/


static int
bra_cca_get_cca_sim_id(int bra_sim_id);

/**********************************************************************
* extern function declaration 
**********************************************************************/

extern void
BRAa_setBearerType(int net_id);
void msm_compute_checksum_critical_file_by_index(int idx);






/**********************************************************************
* functions 
**********************************************************************/

void
bra_cca_init(void)
{
#ifdef BRA_CFG_DM
    bra_cca_register_dm_check_function();
#endif
}


void 
bra_cca_handle_key_end_event(void)
{
    if (bra_cca_cntx == NULL)
        return;
    bra_cca_cntx->result = CCA_STATUS_ENDKEY_PRESSED;
    bra_cca_handle_app_configure_result();
}



/*BRA_SIG_CCA_APP_CONFIGURE_IND*/
/* only can return to cca the following status now
  status = CCA_STATUS_OK;
           CCA_STATUS_INVALID_SETTING;
           CCA_STATUS_SETTING_SKIPPED;
           CCA_STATUS_ENDKEY_PRESSED;
*/
void
bra_cca_handle_app_configure(bra_cca_app_configure_ind_t *app_cfg_ind)
{
     ASSERT(app_cfg_ind != NULL);
    ASSERT(app_cfg_ind->hConfig);
    
    ASSERT(app_cfg_ind->config_id == CCA_CONFIG_BROWSER || 
        app_cfg_ind->config_id == CCA_CONFIG_MMS);
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_B04925EE88A1F6FBCAB53123A27FB773, "BRA: CCA: app, new configure, config_id=%d hConfig=%d\n",
        app_cfg_ind->config_id, app_cfg_ind->hConfig));

#ifdef BRA_CFG_DUAL_SIM
    if (app_cfg_ind->sim_id == BRA_SIM_ID_DEFAULT)
    {
        if (app_cfg_ind->config_id == CCA_CONFIG_BROWSER)
            app_cfg_ind->sim_id = bra_sim_get_bra_sim_id_in_active_use();
        else
        {   
            app_cfg_ind->sim_id = bra_sim_get_sim_card_number();
            if (app_cfg_ind->sim_id != BRA_SIM_ID_SIM1 && app_cfg_ind->sim_id != BRA_SIM_ID_SIM2)
                app_cfg_ind->sim_id = BRA_SIM_ID_SIM1;
        }
    }
#endif /* BRA_CFG_DUAL_SIM */


#ifndef BRA_CONFIG_MMS
    if (app_cfg_ind->config_id == CCA_CONFIG_MMS)
    {
        bra_cca_send_app_configure_rsp(app_cfg_ind->sim_id, app_cfg_ind->config_id,
            app_cfg_ind->hConfig,
            CCA_STATUS_SETTING_SKIPPED);
        return;
    }
#endif 

    
    if (bra_cca_cntx != NULL)
        bra_cca_free_context(bra_cca_cntx);
    
    /*alloc context struct*/
    bra_cca_cntx = BRA_ALLOCTYPE(bra_cca_context_t);
    memset(bra_cca_cntx, 0, sizeof(bra_cca_context_t));
    bra_cca_cntx->cca_doc.cca_doc_type = BRA_CCA_DOC_TYPE_PRV; /*set CCA doc type*/
    /*set indication*/
    bra_cca_cntx->sim_id = app_cfg_ind->sim_id;
    bra_cca_cntx->cca_ind.config_id = app_cfg_ind->config_id;
    bra_cca_cntx->cca_ind.hConfig = app_cfg_ind->hConfig;
    
    if (app_cfg_ind->config_id == CCA_CONFIG_BROWSER)
        bra_cca_cntx->prof_type =  BRA_PROF_ID_BRA;
    else 
        bra_cca_cntx->prof_type = BRA_PROF_ID_MMS;
    
    
    /*parse cca document*/
    bra_cca_cntx->result = mmi_cca_doc_process((S32)bra_cca_cntx->cca_ind.hConfig,
                                               (const U16 *)bra_cca_mapping_table, 
                                               (const S32)(sizeof(bra_cca_mapping_table)/sizeof(U16)),
                                               NULL,
                                               bra_cca_doc_node_callback,
                                               (void *)&(bra_cca_cntx->cca_doc));
    
    if (bra_cca_cntx->result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                        BRA_CCA_11AD20F3A538D4DFF9EA807BDA94AD41, "BRA: CCA: app, parse, mmi_cca_doc_process parsed error=%d\n",
                        bra_cca_cntx->result));
        
        bra_cca_handle_app_configure_result();
        return;
    }

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_65AA220E7592AB279A53531C9C11DA30, "BRA: CCA: app, parse, ok\n"));

    
    /*create profile list*/    
    bra_cca_cntx->result = bra_cca_create_valid_profile_list(bra_cca_cntx->prof_type, &(bra_cca_cntx->cca_doc));
    if (bra_cca_cntx->result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                        BRA_CCA_FE4942905E9610F8BAA30A7D7BB16960, "BRA: CCA: app, create, create profile list error=%d\n",
                        bra_cca_cntx->result));
        
        bra_cca_handle_app_configure_result();
        return;
    }

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_FA97927F7763289AD3840D4D74E99490, "BRA: CCA: app, profile list is ready\n"));

    /*install profile list*/    
    BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN,    BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE,    bra_cca_cntx);
}


static void
bra_cca_handle_app_configure_result(void)
{
    /*invalid status will be asserted */
    bra_cca_cntx->result = bra_cca_get_app_configure_status_returned(bra_cca_cntx->result);

    bra_cca_send_app_configure_rsp((MSF_UINT16)bra_cca_cntx->sim_id, bra_cca_cntx->cca_ind.config_id,
        bra_cca_cntx->cca_ind.hConfig,
        bra_cca_cntx->result);
    
    bra_cca_free_context(bra_cca_cntx);
    bra_cca_cntx = NULL;
}


static void
bra_cca_send_app_configure_rsp(MSF_UINT16 bra_sim_id, MSF_UINT16 config_id, MSF_INT32 hConfig, cca_status_enum result)
{
    MYQUEUE                             message;
    mmi_cca_app_configure_rsp_struct    *data;

    
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
    data->sim_id = (U16)bra_cca_get_cca_sim_id((int)bra_sim_id);
    data->config_id = (U16)config_id;
    data->hConfig = (S32)hConfig;
    data->status = result;
    
    message.oslSrcId        = MOD_WAP;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = MSG_ID_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}


static cca_status_enum
bra_cca_get_app_configure_status_returned(cca_status_enum result)
{
    if (result == CCA_STATUS_OK || 
        result == CCA_STATUS_INVALID_SETTING ||
        result == CCA_STATUS_SETTING_SKIPPED || 
        result == CCA_STATUS_ENDKEY_PRESSED)
        return result;


    return CCA_STATUS_INVALID_SETTING;
}



static void
bra_cca_list_add_node_by_iter(bra_cca_list_head_t **list, 
                              bra_cca_list_head_t **curr_node,
                              bra_cca_list_head_t *node)
{
    if(node == NULL)
        return;

    node->next = NULL;
    if (*list == NULL)
    {
        *list = node;
        *curr_node = *list;
    }
    else
    {
        (*curr_node)->next = node;
        *curr_node = (*curr_node)->next;
    }
}


static void 
bra_cca_free_context(bra_cca_context_t* p)
{
    if (p == NULL)
        return;
    
    bra_cca_free_cca_ind(&(p->cca_ind));
    bra_cca_free_cca_doc(&(p->cca_doc));
    BRA_FREE(p);   
}


static void
bra_cca_free_cca_ind(bra_cca_ind_t* p)
{
    if (p == NULL)
        return;
    memset(p, 0, sizeof(bra_cca_ind_t));
    return;
}


static void
bra_cca_free_cca_doc(bra_cca_doc_t* p)
{
    if ( p == NULL)
        return;

    bra_cca_free_profile_list(p->prof_list);
    p->prof_list = NULL;
    p->curr_prof = NULL;

    bra_cca_free_proxy_list(p->proxy_list);
    p->proxy_list = NULL;
    p->curr_proxy = NULL;

    bra_cca_free_application_list(p->app_list);
    p->app_list = NULL;
    p->curr_app = NULL;
}


static void
bra_cca_free_profile_list(bra_cca_profile_t *list)
{
    bra_cca_profile_t    *p;
    bra_cca_profile_t    *next;


    p = list;
    next = list;
    while (p != NULL)
    { 
        next = p->next;
        BRA_FREE(p); /*only free this node itself*/
        p = next;
    }
}


static void
bra_cca_free_proxy_list(bra_cca_proxy_t *list)
{
    bra_cca_proxy_t        *p;
    bra_cca_proxy_t        *next;

    
    p = list;
    next = list;
    while (p != NULL)
    { 
        next = p->next;
        bra_cca_free_proxy_node(p);
        p = next;
    }
}


static void 
bra_cca_free_proxy_node(bra_cca_proxy_t* p)
{
    int        i;


    if (p == NULL)
        return;
    
    if (p->proxy_id)
        BRA_FREE(p->proxy_id);
    
    if (p->proxy_name)
        BRA_FREE(p->proxy_name);
    
    if (p->homepage)
        BRA_FREE(p->homepage);
    
    if (p->proxy_addr)
        BRA_FREE(p->proxy_addr);
    
    if (p->data_acct_name)
        BRA_FREE(p->data_acct_name);
    
    for (i = 0; i < BRA_CCA_MAX_NBR_BEARERS; i++)
    {
        if (p->data_account[i].name)
            BRA_FREE(p->data_account[i].name);
    }
    if (p->username)
        BRA_FREE(p->username);
    
    if (p->password)
        BRA_FREE(p->password);
    
    BRA_FREE(p);
}



static void
bra_cca_free_application_list(bra_cca_application_t *list)
{
    bra_cca_application_t    *p;
    bra_cca_application_t    *next;

    
    p = list;
    next = list;
    while (p != NULL)
    { 
        next = p->next;
        bra_cca_free_application_node(p);
        p = next;
    }
}


static void
bra_cca_free_application_node(bra_cca_application_t* p)
{
    if (p == NULL)
        return;
    if (p->app_id)
        BRA_FREE(p->app_id);
    if (p->name)
        BRA_FREE(p->name);

    bra_cca_free_proxy_id_list(p->proxy_id_list);
    bra_cca_free_res_list(p->res_list);
    
    BRA_FREE(p);
}


static void
bra_cca_free_proxy_id_list(bra_cca_proxy_id_t *list)
{
    bra_cca_proxy_id_t        *p;
    bra_cca_proxy_id_t        *next;
    
    p = list;
    next = list;
    while (p != NULL)
    { 
        next = p->next;
        if (p->proxy_id)
            BRA_FREE(p->proxy_id);
        BRA_FREE(p);
        p = next;
    }
}


static void
bra_cca_free_res_list(bra_cca_resource_t *res_list)
{
    bra_cca_resource_t        *p;
    bra_cca_resource_t        *next;
    
    p = res_list;
    next = res_list;
    while (p != NULL)
    { 
        next = p->next;
        bra_cca_free_resource_node(p);
        p = next;
    }
}


static void
bra_cca_free_resource_node(bra_cca_resource_t *res)
{
    if (res == NULL)
        return;
    if (res->homepage)
        BRA_FREE(res->homepage);
    if (res->title)
        BRA_FREE(res->title);
    if (res->url)
        BRA_FREE(res->url);
    BRA_FREE(res);
}


static cca_status_enum
bra_cca_doc_node_callback(S32 hConfig, S32 hNode, U16 node_symbol,
                          cca_iterator_struct *iter_datalist, void *user_data)
{
    cca_status_enum         ret;
    bra_cca_doc_t           *cca_doc;

    
    cca_doc = (bra_cca_doc_t*)user_data;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_763E407EA3E86648C5E4C11AAF422B81, "BRA: CCA: parse, node callback node_symbol=%d\n", node_symbol));

    switch(node_symbol)
    {
    case BRA_CCA_NS_PROXY:
        ret = bra_cca_parse_proxy_node(hConfig, hNode, iter_datalist, cca_doc);
        break;

    case BRA_CCA_NS_PORT:
        ret = bra_cca_parse_port_node(hConfig, hNode, iter_datalist, cca_doc);
        break;

    case BRA_CCA_NS_PXAUTHINFO:
        ret = bra_cca_parse_pxauthinfo_node(hConfig, hNode, iter_datalist, cca_doc);
        break;

    case BRA_CCA_NS_APPLICATION:
        ret = bra_cca_parse_application_node(hConfig, hNode, iter_datalist, cca_doc);
        break;

    case BRA_CCA_NS_RESOURCE:
        ret = bra_cca_parse_resource_node(hConfig, hNode, iter_datalist, cca_doc);
        break;

    default:
        ret = CCA_STATUS_OK;
        break;
    }
    return ret;
}


static cca_status_enum
bra_cca_parse_proxy_node(S32 hConfig, S32 hNode, 
                         cca_iterator_struct *iter_datalist,
                         bra_cca_doc_t *cca_doc)
{
    int                     i;
    cca_core_data_struct    *data;
    bra_cca_proxy_t         *proxy;

    
    proxy = BRA_ALLOCTYPE(bra_cca_proxy_t);
    memset(proxy, 0, sizeof(bra_cca_proxy_t));

    proxy->port = -1;       /*used to judge whether this port already parsed*/
    proxy->conn_type = -1;
   
    for (i = 0; i < BRA_CCA_MAX_NBR_BEARERS; i++)
        proxy->data_account[i].id = -1;

    bra_cca_list_add_node_by_iter((bra_cca_list_head_t * *)&(cca_doc->proxy_list),
                                  (bra_cca_list_head_t * *)&(cca_doc->curr_proxy),
                                  (bra_cca_list_head_t *)proxy);

    while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
    {
        bra_cca_parse_proxy_params(cca_doc->curr_proxy, data);   
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_proxy_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data)
{
    int         i;
    
    switch (data->id)
    {
    case CCA_NS_OMA_PROXY_ID:
        
        ASSERT(proxy->proxy_id == NULL);
        
        for (i = 0; i < data->size; i++)
        {
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_DD06B4BAD6CC35EC88B9E446575E74D9, "BRA: CCA: parse, raw proxy_id=%s\n",  BRA_CMN_HNV(data->values.s[i])));

            if(data->values.s[0] == NULL || strlen(data->values.s[0]) == 0)
                continue;
            proxy->proxy_id = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)data->values.s[i]);
            break;
        }
        break;
        
    case CCA_NS_OMA_NAME:
        
        ASSERT(proxy->proxy_name == NULL);
        
        proxy->proxy_name = bra_cca_parse_utf8_name((const cca_core_data_struct*)data);

        break;
        
    case CCA_NS_OMA_PXADDR:

        ASSERT(proxy->proxy_addr == NULL);

        for (i = 0; i < data->size; i++)
        {
            unsigned char   ip[BRA_CCA_IP_MAX_SEGMENT];

            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_4C14DCFD9A80F16FE3D3F91146C9AF21, "BRA: CCA: parse, raw pxaddr=%s\n",  BRA_CMN_HNV(data->values.s[i])));

            if (data->values.s[i] == NULL || 0 == strlen (data->values.s[i]))
                continue;
            /*only support ipv4*/
           if (BRA_CCA_IP_MAX_SEGMENT != bra_cmn_get_address((const char *) data->values.s[i],(unsigned char *)ip))
              continue;
           proxy->proxy_addr = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)data->values.s[i]);
              break;
        }
        break;
 
    case CCA_NS_OMA_STARTPAGE:

        ASSERT(proxy->homepage == NULL);
        proxy->homepage = bra_cca_parse_url((const cca_core_data_struct*)data);
        break;
        
    case CCA_NS_DATAACCTID:
        bra_cca_parse_data_account(proxy, data);
        break;
        
    default:
        break;
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_data_account(bra_cca_proxy_t *proxy, cca_core_data_struct *data)
{
    int     i;
    int     j;
    int     ret;
    int     bearer_type;
    char    bearer_name[BRA_CCA_DATA_ACCOUNT_NAME_MAX_SIZE]; 


    proxy->data_acct_num = 0;
    for (i = 0; i < data->size; i++)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_890F275C88D65D4DBAB30B21EF841FDD, "BRA: CCA: parse, raw net id=%d\n",  data->values.i[i]));

        if (proxy->data_acct_num >= BRA_CCA_MAX_NBR_BEARERS)
            break;

        if (data->values.i[i] < 0)
            continue;
         bearer_type = HDIa_networkAccountGetBearer(data->values.i[i]);
        
        if (bearer_type != HDI_SOCKET_BEARER_GSM_CSD &&
            bearer_type != HDI_SOCKET_BEARER_GSM_GPRS)
            continue;

        if (bearer_type == HDI_SOCKET_BEARER_GSM_CSD && 
            always_ask_get_original_id_data_account(data->values.i[i]) >= custom_get_csd_profile_num())
            continue;

        if (bearer_type == HDI_SOCKET_BEARER_GSM_GPRS && 
            always_ask_get_original_id_data_account(data->values.i[i]) >= custom_get_csd_profile_num() + custom_get_gprs_profile_num())
            continue;

        /*check duplication*/
        for (j = 0; j < proxy->data_acct_num; j++)
        {
            if( bearer_type == proxy->data_account[j].type)
                break;
        }
        if (j < proxy->data_acct_num) /*duplicate*/
            continue;
        
       
        proxy->data_account[proxy->data_acct_num].type = bearer_type;
        proxy->data_account[proxy->data_acct_num].id = data->values.i[i];

        /*HDIa_networkAccountGetName only use strncpy but not add '\0', so we must use memset here*/ 
        memset(bearer_name, 0, BRA_CCA_DATA_ACCOUNT_NAME_MAX_SIZE * sizeof(char));
        ret = HDIa_networkAccountGetName(proxy->data_account[proxy->data_acct_num].id,
            bearer_name, BRA_CCA_DATA_ACCOUNT_NAME_MAX_SIZE);
        if(ret == 0)
            proxy->data_account[proxy->data_acct_num].name = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)bearer_name);

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_A9DDDF83F68A083470C00929B6FDCB5D, "BRA: CCA: parse, data acct name=%s\n",  bearer_name));
        proxy->data_acct_num++; 
    }
    return CCA_STATUS_OK;
}


/*use first port node with valid port number, or use first port node with valid service*/
static cca_status_enum
bra_cca_parse_port_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc)
{
    cca_core_data_struct    *data;
    bra_cca_proxy_t         proxy;


    ASSERT(cca_doc != NULL);

    proxy.port = -1;
    proxy.conn_type = -1;

    if (cca_doc->cca_doc_type == BRA_CCA_DOC_TYPE_DM)
    {
        /*check whether already parse one port node*/
        if (cca_doc->curr_proxy->port != -1 && cca_doc->curr_proxy->conn_type != -1)
            return CCA_STATUS_OK;

        while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
        {
            bra_cca_parse_port_params(&proxy, data);  
        }
        cca_doc->curr_proxy->port = proxy.port;
        cca_doc->curr_proxy->conn_type = proxy.conn_type;
    }
    else /*handle CCA provisioning profile*/
    {
        /* the port node which provides both valid port number and valid connection type has the highest priority,
         * because the operator's requirement is the main aim and it's better to get all these info from
         * the operator than only to get half of these info from the operator and guess another half.
         * so, here do not stop parsing next port node until find this best port node.
         * if do not want to find this suitable port node, please change the judgment to
         * if ((cca_doc->curr_proxy->port != -1 || cca_doc->curr_proxy->conn_type != -1) && 
         *    FALSE == bra_cca_is_wsp_cl_type_port_node(cca_doc->curr_proxy->conn_type, cca_doc->curr_proxy->port))
         */
        if (cca_doc->curr_proxy->port != -1 && cca_doc->curr_proxy->conn_type != -1 && 
            FALSE == bra_cca_is_wsp_cl_type_port_node(cca_doc->curr_proxy->conn_type, cca_doc->curr_proxy->port))
            return CCA_STATUS_OK;
        
        /*now, we do not have any valid port, 
         *we still try to find port in current node, if have, use it according port priority
        */
      
        while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
        {
            bra_cca_parse_port_params(&proxy, data);  
        }
        /* PORTNBR must provided according to OMA spec, but some operators may not adhere to the OMA spec strictly,
           and they may only provide a service parameter, so, here just to loose the judgment */
        if (proxy.port == -1 && proxy.conn_type == -1) 
            return CCA_STATUS_OK;
        
        /* check if a valid port is parsed, remember it, try to find another one more suitably than this */
        if ((cca_doc->curr_proxy->port == -1 && cca_doc->curr_proxy->conn_type == -1)||
             ((cca_doc->curr_proxy->port == -1 || cca_doc->curr_proxy->conn_type == -1) &&
             proxy.port != -1 && proxy.conn_type != -1 && 
             FALSE == bra_cca_is_wsp_cl_type_port_node(proxy.conn_type, proxy.port)) || 
            FALSE == bra_cca_is_wsp_cl_type_port_node(proxy.conn_type, proxy.port))
        {
            cca_doc->curr_proxy->port = proxy.port;
            cca_doc->curr_proxy->conn_type = proxy.conn_type;
        }
    }        
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_port_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data)
{
    int                   i;
    int                   port;


    if (proxy == NULL || data == NULL)
        return CCA_STATUS_FAIL;

    switch (data->id)
    {
    case CCA_NS_OMA_PORTNBR:
        for (i = 0; i < data->size; i++)
        {
            if (data->values.s[i] == NULL)
                continue;
            port = atoi((const char*)data->values.s[i]);
            if (port < BRA_CCA_PORT_MIN_VALUE || port > BRA_CCA_PORT_MAX_VALUE)
                continue;
            proxy->port = port;
            break;
        }
        break;

    case CCA_NS_OMA_SERVICE:
        for (i = 0; i < data->size; i++)
        {
            switch (data->values.i[i])
            {
            case CCA_NS_VAL_CL_WSP:
                proxy->sec_mode = FALSE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_WSP_CL;
                break;

            case CCA_NS_VAL_CL_SEC_WSP:
                proxy->sec_mode = TRUE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_WSP_CL;
                break;
                
            case CCA_NS_VAL_CO_WSP:
                proxy->sec_mode = FALSE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_WSP_CO;
                break;

            case CCA_NS_VAL_CO_SEC_WSP:
                proxy->sec_mode = TRUE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_WSP_CO;
                break;
                
            case CCA_NS_VAL_OTA_HTTP_PO:
            case CCA_NS_VAL_OTA_HTTP_TO:
                proxy->sec_mode = FALSE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_HTTP;
                break;

            case CCA_NS_VAL_OTA_HTTP_TLS_PO:
            case CCA_NS_VAL_OTA_HTTP_TLS_TO:
                proxy->sec_mode = TRUE;
                proxy->conn_type = BRA_SET_CONNECTION_TYPE_HTTP;
                break;
                
            default:    /*do not have valid service parameter, do nothing, then find next*/
                break;
            }
            if (proxy->conn_type != -1 && proxy->conn_type != BRA_SET_CONNECTION_TYPE_WSP_CL)
                break;
        }
        break;
    }
    return CCA_STATUS_OK;
}


static int
bra_cca_is_wsp_cl_type_port_node(int conn_type,  int port)
{
    if (conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
        return TRUE;
    if (conn_type == -1 && 
        (port == BRA_CCA_PORT_WSP_CL || port == BRA_CCA_PORT_WSP_SEC_CL))
        return TRUE;
    return FALSE;
}


static cca_status_enum
bra_cca_parse_pxauthinfo_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc)
{
    cca_core_data_struct    *data;
    bra_cca_proxy_t         proxy;


    if (cca_doc == NULL)
        return CCA_STATUS_FAIL;

    /*check wether already parsed one node*/
    if (cca_doc->curr_proxy->auth_parsed == TRUE)
        return CCA_STATUS_OK;    

    proxy.auth_parsed = FALSE;
    proxy.username = NULL;
    proxy.password = NULL;
    while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
    {
        bra_cca_parse_pxauthinfo_params(&proxy, data);  
    }

    /*validation*/
    if (proxy.auth_parsed == TRUE)
    {
        if (cca_doc->cca_doc_type == BRA_CCA_DOC_TYPE_PRV &&
            (proxy.username == NULL || 0 == strlen(proxy.username)) && 
            (proxy.password != NULL && 0 < strlen(proxy.password)))
        {
            BRA_FREE(proxy.password);
        }
        else /*find valid info*/
        {
            cca_doc->curr_proxy->username = proxy.username;
            cca_doc->curr_proxy->password = proxy.password;
            cca_doc->curr_proxy->auth_parsed = TRUE;
        }
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_pxauthinfo_params(bra_cca_proxy_t *proxy, cca_core_data_struct *data)
{
    if (proxy == NULL || data == NULL)
        return CCA_STATUS_FAIL;

    switch (data->id)
    {
    case CCA_NS_OMA_PXAUTH_ID:
        if (data->size) /*for username can be null, so only get the first one*/
        {
            proxy->username = bra_cca_parse_authinfo_string(data, BRA_CFG_MAX_NBR_PX_AUTH_NAME);
            proxy->auth_parsed = TRUE;
        }
        break;
    case CCA_NS_OMA_PXAUTH_PW:
        if (data->size)
        {
            proxy->password = bra_cca_parse_authinfo_string(data, BRA_CFG_MAX_NBR_PX_AUTH_PWD);
            proxy->auth_parsed = TRUE;
        }
        break;
    default:
        break;
    }
    return CCA_STATUS_OK;    
}
  
 
static char*
bra_cca_parse_authinfo_string(cca_core_data_struct *data, int max_len)
{
    int         len;
    char        *str;
    
    
    if (data == NULL || data->size <= 0)
        return NULL;
    
    if (data->values.s[0] == NULL || 0 == (len = strlen(data->values.s[0])))
        return NULL;
    
    if (max_len <= 0 || len <= max_len)
        str = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)data->values.s[0]);
    else
        str = msf_cmmn_strndup(MSF_MODID_BRA, (const char*)data->values.s[0], max_len);
    return str;
}


static cca_status_enum
bra_cca_parse_application_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc)
{
    bra_cca_application_t  *app;
    cca_core_data_struct    *data;
    
    
    ASSERT(cca_doc);
    
    app = BRA_ALLOCTYPE(bra_cca_application_t);
    memset(app, 0, sizeof(bra_cca_application_t));

    bra_cca_list_add_node_by_iter((bra_cca_list_head_t * *)&(cca_doc->app_list),
                                  (bra_cca_list_head_t * *)&(cca_doc->curr_app),
                                  (bra_cca_list_head_t *)app);

    while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
    {
        bra_cca_parse_application_params(cca_doc->curr_app, data);   
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_application_params(bra_cca_application_t *app, cca_core_data_struct *data)
{
    switch (data->id)
    {
    case CCA_NS_OMA_NAME:
        app->name = bra_cca_parse_utf8_name((const cca_core_data_struct*)data);

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_7E1C334FF17CB776BD3BC5FE35E49CA8, "BRA: CCA: parse, appname=%s\n", BRA_CMN_HNV(app->name)));

        break;
        
    case CCA_NS_OMA_TO_PROXY:
        bra_cca_parse_application_proxy_id(app, data);
        break;
        
    case CCA_NS_OMA_ADDR:
        app->addr = bra_cca_parse_url((const cca_core_data_struct*)data);

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_E86A130C0163E068376E381A8DE069BB, "BRA: CCA: parse, addr=%s\n", BRA_CMN_HNV(app->addr)));
        break;
        
    default:
        break;
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_application_proxy_id(bra_cca_application_t *app, cca_core_data_struct *data)
{
    int                    i;
    bra_cca_proxy_id_t    *id;
    

    if (app == NULL || data == NULL)
        return CCA_STATUS_FAIL;

    for (i = 0; i < data->size; i ++)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_17BEB12DB8B9F15741414EEE97B518A1, "BRA: CCA: parse, raw to_proxy_id=%s\n", BRA_CMN_HNV(data->values.s[i])));

        if (data->values.s[i] == NULL || strlen(data->values.s[i]) == 0)
            continue;
        /*check duplication*/
        id = app->proxy_id_list;
        while (id != NULL) 
        {
            if (strcmp (id->proxy_id, data->values.s[i]) == 0)
                break;  
            id = id->next;
        }
        if (id != NULL)
            continue;
        
        id = BRA_ALLOCTYPE(bra_cca_proxy_id_t);
        id->proxy_id = msf_cmmn_strdup(MSF_MODID_BRA, (const char *)data->values.s[i]);
        id->next = NULL;

         bra_cca_list_add_node_by_iter((bra_cca_list_head_t * *)&app->proxy_id_list,
                                  (bra_cca_list_head_t * *)&app->curr_proxy_id,
                                  (bra_cca_list_head_t *)id);
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_resource_node(S32 hConfig, S32 hNode, cca_iterator_struct *iter_datalist, bra_cca_doc_t *cca_doc)
{
    bra_cca_application_t   *app;
    bra_cca_resource_t      *res;
    cca_core_data_struct    *data;

    
    ASSERT(cca_doc);
    ASSERT(cca_doc->curr_app);

    app = cca_doc->curr_app;
    
    res = BRA_ALLOCTYPE(bra_cca_resource_t);
    memset(res, 0, sizeof(bra_cca_resource_t));

    bra_cca_list_add_node_by_iter((bra_cca_list_head_t * *)&app->res_list,
                                  (bra_cca_list_head_t * *)&app->curr_res,
                                  (bra_cca_list_head_t *)res);
    
    while (CCA_STATUS_OK == mmi_cca_doc_nodedata_next(iter_datalist, &data))
    {
        bra_cca_parse_resource_params(app->curr_res, data);   
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_parse_resource_params(bra_cca_resource_t *res, cca_core_data_struct *data)
{
    if (res == NULL || data == NULL)
        return CCA_STATUS_FAIL;

    switch (data->id)
    {
    case CCA_NS_OMA_URI:
        res->url = bra_cca_parse_url((const cca_core_data_struct*)data);
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_299E0F71D8FC0920950512AFC71A3A61, "BRA: CCA: parse, res uri=%s\n", BRA_CMN_HNV(res->url)));
        break;
        
    case CCA_NS_OMA_NAME:
         res->title = bra_cca_parse_utf8_name((const cca_core_data_struct*)data);
         MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
             BRA_CCA_7594B00B8968F1DDDF2F06B9DC246F83, "BRA: CCA: parse, res title=%s\n", BRA_CMN_HNV(res->title)));
        break;
        
    case CCA_NS_OMA_STARTPAGE:
        if(data->size)  /* for STARTPAGE has no value, so, do not care the value*/
            res->homepage = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)BRA_CMN_HNV(data->values.s[0]));

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_2150C8382EC8D0A76EC3C8D0D4B5D040, "BRA: CCA: parse, res homepage=%d\n", res->homepage == NULL ? 0 : 1));
        break;
    default:
        break;
    }
    return CCA_STATUS_OK;
}


static char*
bra_cca_parse_utf8_name(const cca_core_data_struct *data)
{
    int     i;
    int     len;
    char    *name = NULL;
    

    if (data == NULL)
        return NULL;

    for (i = 0; i < data->size; i++)
    {
        
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_ABCAFE3B274EEAD45F117FFAF8BABFBD, "BRA: CCA: parse, raw utf8 name=%s\n", BRA_CMN_HNV(data->values.s[i])));
      
        /*truncate it here*/
        if (data->values.s[i] == NULL)
            continue;

        len = widget_utf8_length((const kal_uint8 *)data->values.s[i]);
        if (len == 0)
            continue;
        len = (len > BRA_CFG_MAX_NBR_CHARS_TITLE ? BRA_CFG_MAX_NBR_CHARS_TITLE : len);
        name = bra_cmn_trunc_utf8_str(data->values.s[i], len);
        break;
    }
    return name;
}


static char*
bra_cca_parse_url(const cca_core_data_struct *data)
{
    int         i;
    int         len;
    char        *temp_url;
    char        *url = NULL;


    if (data == NULL)
        return NULL;
    
    for (i = 0; i < data->size; i++)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_098E96BF9B059157DD851CC18C57FEBA, "BRA: CCA: parse, raw url=%s\n", BRA_CMN_HNV(data->values.s[i])));

        if (data->values.s[i] == NULL || 0 == (len = strlen(data->values.s[i])))
            continue;
        temp_url = bra_cca_make_complete_url((const char*)data->values.s[i]);
        if (temp_url == NULL)
            continue;
        if (!check_url(temp_url) || !bra_cmn_url_is_valid(temp_url))
        {
            BRA_FREE(temp_url);
            continue;
        }
        len = strlen((const char*)temp_url);
        if (len <= BRA_CFG_MAX_NBR_CHARS_URL)
        {
            url = temp_url;
        }
        else
        {
            url = msf_cmmn_strndup(MSF_MODID_BRA, (const char *)temp_url, BRA_CFG_MAX_NBR_CHARS_URL);
            BRA_FREE(temp_url);
        }
        break;
    }
    return url;
}


static char*
bra_cca_make_complete_url(const char* url)
{
    char    *temp = NULL;
    char    *new_url = NULL;


    if (url == NULL)
        return NULL;
    temp = msf_cmmn_strdup(MSF_MODID_BRA, url);
    bra_cca_clean_up_url(temp);
    new_url = msf_url_make_complete(MSF_MODID_BRA, temp);
    BRA_FREE(temp);
    return new_url;
}


static void
bra_cca_clean_up_url (char *url)
{
    char *s;
    int   i;
    

    if (url == NULL)
        return;
    
    s = msf_cmmn_skip_blanks ((const char*)url);
    i = msf_cmmn_skip_trailing_blanks ((const char*)s, strlen ((const char*)s));
    if (s != url) 
    {
        memmove (url, s, i);
    }
    url[i] = '\0';
}


static cca_status_enum
bra_cca_create_valid_profile_list(int prof_type, bra_cca_doc_t *cca_doc)
{
    cca_status_enum   result;
    bra_cca_profile_t *profile;
    
    
    if (cca_doc == NULL)
        return CCA_STATUS_FAIL;
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_85257026E84C76A500FC13AC24BF12D2, "BRA: CCA: create, to validate app list and proxy list\n"));

    result = bra_cca_delete_invalid_application_from_list(prof_type, &cca_doc->app_list);
    if (CCA_STATUS_OK != result)
        return result; 

    result = bra_cca_delete_invalid_proxy_from_list(prof_type, &cca_doc->proxy_list);
    if (CCA_STATUS_OK != result)
        return result; 
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_C19846C06DB67FB10E49858D9FBC51E1, "BRA: CCA: create, to create valid profile list\n"));

    cca_doc->prof_list = NULL;
    cca_doc->curr_prof = NULL;
    bra_cca_doc_get_profile_restart(cca_doc);
    while (bra_cca_doc_get_profile_next(cca_doc))
    {
        profile = bra_cca_create_valid_profile(prof_type, cca_doc);
        if (profile)
        {
            bra_cca_list_add_node_by_iter((bra_cca_list_head_t * *)&(cca_doc->prof_list),
                (bra_cca_list_head_t**)&(cca_doc->curr_prof),
                (bra_cca_list_head_t*)profile);
        }
    }
    if (cca_doc->prof_list == NULL)
        return CCA_STATUS_INVALID_SETTING;

    /*should reset the curr_prof*/
    cca_doc->curr_prof = cca_doc->prof_list;

    return CCA_STATUS_OK;
}


static bra_cca_profile_t * 
bra_cca_create_valid_profile(int prof_type, bra_cca_doc_t *cca_doc)
{
    bra_cca_profile_t    temp;
    bra_cca_profile_t    *profile;
    bra_cca_proxy_t      *proxy = NULL;
    
   
    
    if (cca_doc == NULL || cca_doc->curr_app == NULL) /*reach the end of application list*/
        return NULL;     
    
    /*get next proxy id in app node*/
    if (cca_doc->curr_app->proxy_id_list != NULL)
    {
        /*reach the end of to-proxy-id list*/
        if (cca_doc->curr_app->curr_proxy_id == NULL) 
            return NULL;

        proxy = bra_cca_get_proxy_node_by_id(cca_doc->proxy_list, 
            (const char *)cca_doc->curr_app->curr_proxy_id->proxy_id);

        if (proxy == NULL)/*check bookmark setting*/
        {
            if (prof_type == BRA_PROF_ID_MMS)
                return NULL;
            if (cca_doc->curr_app->res_list == NULL)
                return NULL;
            bra_cca_revise_bookmark(cca_doc->curr_app->res_list);
        }
    }
    
    temp.application = cca_doc->curr_app;
    temp.proxy = proxy;
    temp.next = NULL;

    if (CCA_STATUS_OK != bra_cca_validate_profile(prof_type, &temp)) 
        return NULL;
    profile = BRA_ALLOCTYPE(bra_cca_profile_t);
    profile->application = temp.application;
    profile->proxy = temp.proxy;
    profile->next = temp.next;
    profile->sel_prof_id = -1;
    profile->result = CCA_STATUS_OK;
    return profile;
}


static cca_status_enum
bra_cca_delete_invalid_application_from_list(int prof_type, bra_cca_application_t **list)
{ 
    bra_cca_application_t    *cur;
    bra_cca_application_t    *pre;
    

    if (list == NULL)
        return CCA_STATUS_OK;

    cur = *list;
    pre = *list;
    while(cur)
    {
        if (CCA_STATUS_OK == bra_cca_validate_application(prof_type, cur))
        {
            pre = cur;
            cur = cur->next;
        }
        else
        {
            if (cur == *list)
            {
                *list = cur->next;
            }
            pre->next = cur->next;
            bra_cca_free_application_node(cur);
            cur = pre->next;
        }
    }
    /*application node must be provided*/
    if (*list == NULL)
        return CCA_STATUS_INVALID_SETTING;
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_delete_invalid_resource_from_list(int prof_type, bra_cca_resource_t **list)
{ 
    int                   len;
    bra_cca_resource_t    *cur;
    bra_cca_resource_t    *pre;
    
    
    if (list == NULL)
        return CCA_STATUS_OK;
   
    if (prof_type != BRA_PROF_ID_BRA)
    {
        bra_cca_free_res_list(*list);
        *list = NULL;
        return CCA_STATUS_OK;
    }

    cur = *list;
    pre = *list;
    while(cur)
    {
        /*url must be provided and must be valid url now*/
        if (cur->url != NULL && 0 < (len = widget_utf8_length((const kal_uint8 *)cur->url))) 
        {
            /*generate title if null, for title can be null while adding bookmark*/
            if (cur->title == NULL || 0 == strlen(cur->title))
            {
                if (cur->title)
                    BRA_FREE(cur->title);
                len = (len > BRA_MAXCHAR_STR_TITLE ? BRA_MAXCHAR_STR_TITLE : len);
                cur->title = bra_cmn_trunc_utf8_str(cur->url, len);
            }
            pre = cur;
            cur = cur->next;
        }
        else
        {
            if (cur == *list)
            {
                *list = cur->next;
            }
            pre->next = cur->next;
            bra_cca_free_resource_node(cur);
            cur = pre->next;
        }
    }
    /* resource list can be null*/
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_delete_invalid_proxy_from_list(int prof_type, bra_cca_proxy_t **list)
{ 
    bra_cca_proxy_t        *cur;
    bra_cca_proxy_t        *pre;
    

    if (list == NULL)
        return CCA_STATUS_OK;

    cur = *list;
    pre = *list;
    while(cur)
    {
        /*set all duplicated proxy node to invalid node*/
        bra_cca_set_duplicated_proxy_to_invalid(*list, cur);

        if (CCA_STATUS_OK == bra_cca_validate_proxy(prof_type, cur))
        {
            pre = cur;
            cur = cur->next;
        }
        else
        {
            if (cur == *list)
            {
                *list = cur->next;
            }
            pre->next = cur->next;

            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_3FB75B064494BD3432AFF05DB8753014, "BRA: CCA: create, invalid proxy id=%s\n", BRA_CMN_HNV(cur->proxy_id)));
  
            bra_cca_free_proxy_node(cur);
            cur = pre->next;
        }
    }
    /*proxy node can be null for bookmark setting*/
    return CCA_STATUS_OK;
}


static void
bra_cca_set_duplicated_proxy_to_invalid(bra_cca_proxy_t *list, bra_cca_proxy_t *proxy)
{
    bra_cca_proxy_t *cur;
        
    if (list == NULL || proxy == NULL)
        return;

    cur = list;
    while (cur)
    {
        if (cur->proxy_id != NULL && proxy->proxy_id != NULL && cur != proxy)
        {
            
            if (0 == strcmp ((const char*)cur->proxy_id, (const char*)proxy->proxy_id))
            {
                MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_CCA_0DF8FBAE270C8FA8CCF794051C661CEE, "BRA: CCA: create, duplicate proxy id=%s\n", BRA_CMN_HNV(cur->proxy_id)));

                /*only  set it to invalid proxy node, then validate it and delete in from list*/
                BRA_FREE(cur->proxy_id);
                cur->proxy_id = NULL;
            }
        }
        cur = cur->next;
    }
}


static cca_status_enum
bra_cca_validate_application(int prof_type, bra_cca_application_t *app)
{
    bra_cca_proxy_id_t  *id;


    if (app == NULL)
        return CCA_STATUS_FAIL;
    
    if (prof_type == BRA_PROF_ID_MMS) /*MMSC validation*/
    {
        if (FALSE == bra_cca_is_mmsc_addr_valid((const char*)app->addr))
            return CCA_STATUS_FAIL;
    }

    bra_cca_delete_invalid_resource_from_list(prof_type, &app->res_list);

    /*can be homepage or bookmark setting*/
    id = app->proxy_id_list;
    while (id)
    {
        if (id->proxy_id != NULL && strlen (id->proxy_id) != 0)
            break;           
        id = id->next;
    }
    if (id == NULL)
    {   
        if (prof_type == BRA_PROF_ID_MMS)
            return CCA_STATUS_FAIL;

        /*check bookmark setting*/
        if (app->res_list == NULL)
            return CCA_STATUS_FAIL;
        
        bra_cca_revise_bookmark(app->res_list);
    }
    
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_validate_proxy(int prof_type, bra_cca_proxy_t *proxy)
{
    int                     i;
    int                     find = 0;
    unsigned char           ip[BRA_CCA_IP_MAX_SEGMENT];
    

    if (proxy == NULL)
        return CCA_STATUS_FAIL;
    
    if (proxy->proxy_id == NULL || strlen(proxy->proxy_id) == 0)
        return CCA_STATUS_FAIL;

    /*do not support WSP CL type now*/
    if (TRUE == bra_cca_is_wsp_cl_type_port_node(proxy->conn_type, proxy->port))
        return CCA_STATUS_FAIL;

    if (proxy->proxy_addr == NULL || strlen(proxy->proxy_addr) == 0) /*mandatory*/
        return CCA_STATUS_FAIL;
    
    /*validate proxy address, only support ipv4*/
    if (BRA_CCA_IP_MAX_SEGMENT != bra_cmn_get_address((const char *)proxy->proxy_addr, (unsigned char *)ip))
        return CCA_STATUS_FAIL;
    
    /*must have one or more data account*/
    for (i = 0; i < BRA_CCA_MAX_NBR_BEARERS; i++)
    {
#ifndef MMS_CFG_FALLBACK_SUPPORT
        if (find > 0 && prof_type == BRA_PROF_ID_MMS) 
        {
            if (proxy->data_account[i].id >= 0)
            {
                proxy->data_acct_num--;
                proxy->data_account[i].type = 0;
                proxy->data_account[i].id = -1;
                if (proxy->data_account[i].name)
                {
                    BRA_FREE(proxy->data_account[i].name);
                    proxy->data_account[i].name = NULL;
                }
            }
        }
#endif /*MMS_CFG_FALLBACK_SUPPORT*/
        if (proxy->data_account[i].id >= 0)
        {
            find++;
        }
    }
    if (find == 0)  /*must provide data account id*/
        return CCA_STATUS_FAIL;

    /*revise the connection type and port if error*/
    bra_cca_revise_conn_type_and_port(&(proxy->conn_type), &(proxy->port), proxy->sec_mode);
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_validate_profile(int prof_type, bra_cca_profile_t *prof)
{
    if (prof == NULL)
        return CCA_STATUS_FAIL;

    /*proxy can be null, for bookmarks etting*/
    if (prof->application == NULL)
        return CCA_STATUS_INVALID_SETTING;
    return CCA_STATUS_OK;
}


static void
bra_cca_revise_bookmark(bra_cca_resource_t *res_list)
{
    bra_cca_resource_t  *res;
    
    
    /*change homepage to bookmark*/
    res = res_list;
    while (res)
    {
        if (res->homepage)
        {
            BRA_FREE(res->homepage);
            res->homepage = NULL;
        }
        res = res->next;
    }
}


static void
bra_cca_revise_conn_type_and_port(int *conn_type, int *port, int sec_mode)
{
    if (conn_type == NULL || port == NULL)
        return;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_01E4713E2CFE44079AF23BFB5C1CE18D, "BRA: CCA: create, revise port=%d, conn_type=%d\n", *port, *conn_type));

#ifndef BRA_CONFIG_SECURITY
    sec_mode = FALSE;
    if ((*conn_type == -1 || *conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL) && 
        *port == BRA_CCA_PORT_WSP_SEC_CL)
    {
        *port = BRA_CCA_PORT_WSP_CL;
    }
    else if ((*conn_type == -1 || *conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO ) &&
        *port == BRA_CCA_PORT_WSP_SEC_CO)
    {
        *port = BRA_CCA_PORT_WSP_CO;
    }
#endif
    
    if (*conn_type >= 0 && *port >= 0)   
    {
        if (*conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
        {
#ifdef BRA_CONFIG_HTTP_EXT
            if (*port == BRA_CCA_PORT_WSP_CL || 
                *port == BRA_CCA_PORT_WSP_SEC_CL ||
                *port == BRA_CCA_PORT_WSP_SEC_CO)
            {
                *port = BRA_CCA_PORT_HTTP_DEFAULT;
            }
            else
            {
                /*do not change the port number, even HTTP & 9201,
                for this combination may be ok in some network environment*/
            }
#endif /* BRA_CONFIG_HTTP_EXT */
           *port = bra_cca_get_port_by_conn_type(*conn_type, sec_mode);
        }
        else
        {
            *port = bra_cca_get_port_by_conn_type(*conn_type, sec_mode);
        }
        return;
    }
    if (*conn_type < 0 && *port < 0) /*do no find any port node, use default*/
    {
        *conn_type = BRA_CFG_PROF_DEFAULT_CON_TYPE;
        *port = BRA_CCA_PORT_WSP_CO; /*BRA_CFG_PROF_DEFAULT_PRX_PORT*/
    }
    else if(*port < 0)  /*get port from connection type*/
    {
        *port = bra_cca_get_port_by_conn_type(*conn_type, sec_mode);
    }
    else if (*conn_type < 0)  /*get connection type from port*/
    {
        *conn_type = bra_cca_get_conn_type_by_port(*port);
    }
}


static int
bra_cca_get_conn_type_by_port(int port)
{
    int     conn_type;


    switch (port)
    {
    case BRA_CCA_PORT_WSP_CL:
    case BRA_CCA_PORT_WSP_SEC_CL:
        conn_type = BRA_SET_CONNECTION_TYPE_WSP_CL;
        break;
        
    case BRA_CCA_PORT_WSP_CO:
    case BRA_CCA_PORT_WSP_SEC_CO:
        conn_type = BRA_SET_CONNECTION_TYPE_WSP_CO;
        break;
        
    default:
#ifdef BRA_CONFIG_HTTP_EXT
        conn_type = BRA_SET_CONNECTION_TYPE_HTTP;
#else
        conn_type = BRA_SET_CONNECTION_TYPE_WSP_CO;
#endif
        break;
    }
    return conn_type;
}


static int
bra_cca_get_port_by_conn_type(int conn_type, int sec_mode)
{
    int port;


    switch (conn_type)
    {
    case BRA_SET_CONNECTION_TYPE_WSP_CL:
        port = (sec_mode == FALSE ? BRA_CCA_PORT_WSP_CL : BRA_CCA_PORT_WSP_SEC_CL);
        break;
    case BRA_SET_CONNECTION_TYPE_WSP_CO:
        port = (sec_mode == FALSE ? BRA_CCA_PORT_WSP_CO : BRA_CCA_PORT_WSP_SEC_CO);
        break;

#ifdef BRA_CONFIG_HTTP_EXT        
    case BRA_SET_CONNECTION_TYPE_HTTP:
        port = BRA_CCA_PORT_HTTP_DEFAULT;
        break;
#endif  /* BRA_CONFIG_HTTP_EXT */
        
    default:
        port = BRA_CCA_PORT_WSP_CO;
    }
    return port;
}



static void 
bra_cca_doc_get_profile_restart(bra_cca_doc_t *cca_doc)
{
    ASSERT(cca_doc);
    
    cca_doc->curr_prof = NULL;
    cca_doc->curr_app = NULL;
    cca_doc->curr_proxy = NULL;
}


static bra_cca_application_t * 
bra_cca_doc_get_profile_next(bra_cca_doc_t *cca_doc)
{
    ASSERT (cca_doc);
    
    if (cca_doc->curr_app == NULL) /*reach the end of application list, restart*/
    {
        cca_doc->curr_app = cca_doc->app_list; /*reset to the first application node*/
        if (cca_doc->curr_app)
            cca_doc->curr_app->curr_proxy_id = cca_doc->curr_app->proxy_id_list;
    }
    else
    {
        if (cca_doc->curr_app->curr_proxy_id == NULL) /*reach the end of to-proxy-id list in current application, find next application*/
        {
            /*get next application*/
            cca_doc->curr_app = cca_doc->curr_app->next;
            if (cca_doc->curr_app)
                cca_doc->curr_app->curr_proxy_id = cca_doc->curr_app->proxy_id_list;
        }
        else                                           /*find the next to-proxy-id in proxy-id list of current application*/ 
            cca_doc->curr_app->curr_proxy_id = cca_doc->curr_app->curr_proxy_id->next;
    }
    return cca_doc->curr_app;
}


static bra_cca_proxy_t *
bra_cca_get_proxy_node_by_id(bra_cca_proxy_t *proxy_list, const char *proxy_id)
{
    bra_cca_proxy_t        *proxy;
    
    
    if (proxy_list == NULL || proxy_id == NULL)
        return NULL;
    proxy = proxy_list;
    
    while (proxy)
    {
        if (strcmp (proxy->proxy_id, proxy_id) == 0)
            return proxy;
        proxy = proxy->next;
    }
    return NULL;
}




/**********************************************************************
* BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE handler 
**********************************************************************/


void
bra_cca_handle_profile_install_continue(void)
{
    if (FALSE == bra_cca_is_all_profiles_installed())
    {
        /*begin to install next profile*/
        bra_cca_create_profile_info_menu();
    }
    else
    {
        /*active the first profile ,send response to cca, and free resource*/
        bra_cca_handle_all_profiles_installed();
    }
}


static int
bra_cca_is_all_profiles_installed(void)
{
    return (bra_cca_cntx->cca_doc.curr_prof == NULL);
}


static void
bra_cca_handle_all_profiles_installed(void)
{
    bra_cca_profile_t *profile;


    /*check whether all profile installed */
   if(FALSE == bra_cca_is_all_profiles_installed())
       return;
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_C092932748FDC0288F4586FC0C48CB11, "BRA: CCA: app, all profiles are handled\n"));
    
    /*find first profile installed successfully, do not care the replacation*/
    profile = bra_cca_cntx->cca_doc.prof_list;
    while (profile)
    {
        if (profile->result == CCA_STATUS_OK &&
            FALSE == bra_cca_is_simple_bookmak_setting(bra_cca_cntx->prof_type, profile))
        {
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_87EEBC91FBD003583B131C26276E0A15, "BRA: CCA: app, active profile type=%d, id=%d\n", 
                bra_cca_cntx->prof_type, profile->sel_prof_id));
            
            bra_cca_activate_profile(bra_cca_cntx->prof_type, bra_cca_cntx->sim_id, profile->sel_prof_id);  
            break;
        }
        profile = profile->next;
    }
    bra_cca_cntx->result = bra_cca_get_profile_list_install_result(&(bra_cca_cntx->cca_doc));
    bra_cca_handle_app_configure_result();
    return;
}



static void
bra_cca_activate_profile(int prof_type, int sim_id, int prof_id)  
{
    int     old_sim_id;
    int     old_prof_id;
    int     old_prof_type;


    if (prof_id < 0 || prof_id >= BRA_CFG_N_PROFILES)
        return;
    if (prof_type != BRA_PROF_ID_BRA && prof_type != BRA_PROF_ID_MMS)
        return;

    old_sim_id = bra_prof_get_profile_sim_id();
    old_prof_type = bra_prof_get_profile_id();
    old_prof_id = bra_prof_get_absolute_profile();
    bra_prof_set_sim_selected_profile(prof_type, sim_id, prof_id, NULL);
    bra_prof_activate_sim_profile(prof_type, sim_id, prof_id);

    BRAa_setBearerType(bra_prof_get_key_int_value(bra_prof_get_profile_id(), BRA_PROF_KEY_NET_ID));
    /*save + calc checksum*/
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
    
    /* should restore old profile while updating WAP in MMS profile editing screen or
    updating MMS in WAP profile editing screen */
    if (bra_win_get_window(BRA_WIN_ID_PROFILE_MENU) || prof_type == BRA_PROF_ID_MMS)
        bra_prof_set_sim_selected_profile(old_prof_type, old_sim_id, old_prof_id, NULL);
}


static cca_status_enum
bra_cca_get_profile_list_install_result(bra_cca_doc_t *cca_doc)
{
    bra_cca_profile_t   *p;
    MSF_BOOL            is_skip = FALSE;
    MSF_BOOL            is_invalid = FALSE;

    
    ASSERT(cca_doc);
    
    p = cca_doc->prof_list;
    
    while (p)
    {
        if (p->result == CCA_STATUS_OK)
            return CCA_STATUS_OK;   /*find at least one*/
        else if (p->result == CCA_STATUS_SETTING_SKIPPED)
            is_skip = TRUE;
        else
            is_invalid = TRUE;
        p = p->next;
    }
    if (is_skip == TRUE)
        return CCA_STATUS_SETTING_SKIPPED;
    return CCA_STATUS_INVALID_SETTING;
}



static void
bra_cca_create_profile_info_menu(void)
{
    
    bra_cca_prof_menu_t *dlg;
    kal_uint8           *text;
    ctk_screen_handle   scrid;
    MsfPosition         pos =  {0, 0};
    int                 text_size = 200;    /*init size, can be extended*/
    

    text = BRA_ALLOC(text_size);
    text[0] = '\0';
    text[1] = '\0';
    
    text = bra_cca_generate_profile_info_head(text, &text_size, bra_cca_cntx->prof_type, &(bra_cca_cntx->cca_doc));
    text= bra_cca_generate_profile_info_body(text, &text_size, bra_cca_cntx->prof_type, bra_cca_cntx->cca_doc.curr_prof);
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                 BRA_CCA_DEBD366150AA4882830291BEDEAA8E01, "BRA: CCA: profile info len=%d\n", strlen((const char*)text)));

    dlg = BRA_ALLOCTYPE(bra_cca_prof_menu_t);
    memset(dlg, 0, sizeof(bra_cca_prof_menu_t));
    
    /*Create Form*/
    dlg->window = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, text, 
        (MSF_UINT16)BRA_STR_ID_INSTALL_SETTING, 0); 
    
    BRA_FREE(text);
    
    scrid = HDIa_widgetCtkGetScreenHandle(dlg->window);
    
    ctk_screen_addLSK_UA(scrid, BRA_STR_ID_INSTALL, IMG_GLOBAL_OK, NULL, bra_cca_action_profile_info_menu, KAL_TRUE);
    ctk_screen_addRSK_UA(scrid, BRA_STR_ID_SKIP, IMG_GLOBAL_BACK, NULL, bra_cca_action_skip_profile, KAL_TRUE);
    
    bra_win_show_window (BRA_WIN_ID_CCA_PROF_INFO_MENU, 
        (bra_win_t*)dlg, 
        (MsfPosition*)&pos, 
        bra_cca_delete_profile_info_menu, 
        NULL,
        NULL); 
}


static void
bra_cca_delete_profile_info_menu(bra_win_t *win)
{
    bra_cca_prof_menu_t *p;
    

    p = (bra_cca_prof_menu_t*)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    
    BRA_FREE (p);
}



static void
bra_cca_action_profile_info_menu (ctk_screen_handle scrid)
{
    CTK_UNUSED(scrid);
    

    /*install simple bookmark setting*/
    if (TRUE == bra_cca_is_simple_bookmak_setting(bra_cca_cntx->prof_type, bra_cca_cntx->cca_doc.curr_prof))
    {
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);

        bra_cca_cntx->cca_doc.curr_prof->result = 
            bra_cca_update_profile_bookmark(bra_cca_cntx->prof_type,
                bra_cca_cntx->cca_doc.curr_prof->application);
       
        bra_cca_cntx->cca_doc.curr_prof = bra_cca_cntx->cca_doc.curr_prof->next; 
      
        BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, 
            BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE, 
            bra_cca_cntx);
        return;
    }

    /*try to find a free profile*/
    bra_cca_cntx->cca_doc.curr_prof->sel_prof_id = 
                bra_cca_get_next_free_profile_id(bra_cca_cntx->prof_type, 
                bra_cca_cntx->sim_id, &bra_cca_cntx->next_prof_id);

    if (bra_cca_cntx->cca_doc.curr_prof->sel_prof_id >= 0)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_28B1F20C10AE3015B8A0314C5640FD13, "BRA: CCA: app, update free profile, id=%d\n",
            bra_cca_cntx->cca_doc.curr_prof->sel_prof_id));

        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
        bra_cca_update_current_profile();
        /*process next profile*/
        bra_cca_cntx->cca_doc.curr_prof = bra_cca_cntx->cca_doc.curr_prof->next; 
        BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, 
            BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE, 
            bra_cca_cntx);
    }
    else /*no find free profile, show profile selection menu*/
    {  

        bra_cca_create_profile_select_menu();
    }
}


static void
bra_cca_action_skip_profile (ctk_screen_handle scrid)
{
    CTK_UNUSED(scrid);
    
    bra_dlg_create_dlg (MsfConfirmation,
        BRA_STR_SKIP_PROFILE, 
        BRA_STR_YES,  
        BRA_STR_NO,
        0, 
        bra_cca_skip_profile_confirmation);
}


static void 
bra_cca_skip_profile_confirmation(MsfActionType response)
{
    if(response == MsfOk)
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_B3C0208CFCD06FFF56B860986909A699, "BRA: CCA: app, update, skip current profile\n"));

        bra_cca_cntx->cca_doc.curr_prof->result = CCA_STATUS_SETTING_SKIPPED;
        bra_cca_cntx->cca_doc.curr_prof = bra_cca_cntx->cca_doc.curr_prof->next;
        /*close current profile information menu, then show next profile information*/
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, 
            BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE, 
            bra_cca_cntx);
    }
}


static kal_uint8*
bra_cca_generate_key_value(kal_uint8* src, int *allocated_size, int key_id, const kal_uint8* value, int value_id)
{
    kal_uint8   *new_text = src;
    
    
    if (src == NULL || allocated_size == NULL)
        return new_text;

    if (key_id <= 0)  /*add a blank line*/
    {
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*)"\n");
        return new_text;
    }
    
    new_text = widget_ucs2str_append_id(MSF_MODID_BRA, new_text, allocated_size, key_id);
    if (value)
    {
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*) " : ");
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, value);
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*)"\n\n");
    }
    else if (value_id > 0)
    {
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*) " : ");
        new_text = widget_ucs2str_append_id(MSF_MODID_BRA, new_text, allocated_size, value_id);
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*)"\n\n");
    }
    else
        new_text = widget_ucs2str_append_utf8(MSF_MODID_BRA, new_text, allocated_size, (kal_uint8*)"\n");
    return new_text;
}



static kal_uint8*
bra_cca_generate_profile_info_head(kal_uint8 *text, int *text_size, int prof_type, bra_cca_doc_t *cca_doc)
{
    int                 key_id;
    int                 prof_num;
    int                 curr_prof_index;
    kal_uint8           *new_text = text;
    char                rate[BRA_CCA_NUMBER_MAX_DIGIT * 2];
    
    
    if (text == NULL || text_size == NULL || cca_doc == NULL || cca_doc->curr_prof == NULL)
        return new_text;
    
    /*application name*/
    key_id = (prof_type == BRA_PROF_ID_BRA ? BRA_STR_ID_BROWSER : BRA_STR_ID_MMS);
    new_text = bra_cca_generate_key_value(new_text, text_size, key_id, NULL, 0);
    
    /*profile number*/
    prof_num  = bra_cca_get_profile_number(cca_doc->prof_list);
    curr_prof_index= bra_cca_get_current_profile_index(cca_doc->prof_list, cca_doc->curr_prof);
    
    ASSERT(curr_prof_index <= prof_num);  
    
    sprintf(rate, "%d/%d", curr_prof_index, prof_num);
    new_text = bra_cca_generate_key_value(new_text, text_size, BRA_STR_ID_PROFILE, (const kal_uint8 *)rate, 0);
    return new_text;
}


static kal_uint8*
bra_cca_generate_profile_info_body(kal_uint8 *text, int *text_size, int prof_type, bra_cca_profile_t *profile)
{
    char                *temp;
    kal_uint8           *new_text = text;
    
    
    if (profile == NULL || text == NULL || text_size == NULL)
        return new_text;

    if ( TRUE == bra_cca_is_simple_bookmak_setting(prof_type, profile))
    {
        /*homepages are already changed to bookmarks in validation process*/
        new_text = bra_cca_generate_bookmark_info(new_text, text_size,
            profile->application);
        return new_text;
    }

    /*profile name*/
    temp = bra_cca_get_profile_name(profile);
    new_text = bra_cca_generate_key_value(new_text, text_size,
        BRA_STR_ID_PROFILE_NAME,
        (const kal_uint8 *)temp, 
        BRA_STR_ID_DEFAULT_PROFILE_NAME); /*use default if not provided*/
    
    /*home page*/
    bra_cca_get_profile_homepage(prof_type, profile, NULL, &temp);
    if (prof_type == BRA_PROF_ID_BRA)
        temp = (temp == NULL ? BRA_CFG_DEFAULT_HOMPAGE_URL : temp);
    new_text = bra_cca_generate_key_value(new_text, text_size, 
        BRA_STR_ID_HOMEPAGE,
        (const kal_uint8 *)BRA_CMN_HNV(temp),
        0);
    
    /*proxy*/
    new_text = bra_cca_generate_proxy_info(new_text, text_size,
        profile->proxy);
    
    
    /*bookmark*/
    if (prof_type == BRA_PROF_ID_BRA )
        new_text = bra_cca_generate_bookmark_info(new_text, text_size, profile->application);
    
    return new_text;
}


static kal_uint8*
bra_cca_generate_proxy_info(kal_uint8 *text, int *text_size, bra_cca_proxy_t *proxy)
{
    int                  value_id;
    kal_uint8            *new_text = text;
  
    
    if (proxy == NULL)
        return new_text;
    
    /*data acount*/
#ifndef BRA_CFG_CCA_SHOW_WHOLE_PROF
    value_id = bra_cca_get_bearer_type_string_id(proxy);
    new_text = bra_cca_generate_key_value(new_text, text_size,
        BRA_STR_ID_ACCOUNT, NULL, value_id);
#else
    {
        char        *temp;

        temp = bra_cca_get_muliti_data_account_name(proxy);
        new_text = bra_cca_generate_key_value(new_text, text_size,
                                              BRA_STR_ID_ACCOUNT, (const kal_uint8 *)BRA_CMN_HNV(temp), 0);
    }
#endif /*BRA_CFG_CCA_SHOW_WHOLE_PROF*/


    /*connection type*/
    if (proxy->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
        value_id = BRA_STR_ID_HTTP;
    else
        value_id = BRA_STR_ID_CONN_ORIENT;
    new_text = bra_cca_generate_key_value(new_text, text_size,
        BRA_STR_ID_CONN_TYPE, NULL, value_id);
    
    /*gateway*/
    if (proxy->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
        value_id = BRA_STR_ID_PRX_ADDR;
    else
        value_id = BRA_STR_ID_GATEWAY;
    new_text = bra_cca_generate_key_value(new_text, text_size,  
        value_id, (const kal_uint8 *)BRA_CMN_HNV(proxy->proxy_addr), 0);
    
    /*port*/
#ifdef BRA_CFG_CCA_SHOW_WHOLE_PROF
    if (proxy->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
    {
        char     port[BRA_CCA_PORT_MAX_NUM * 2];

        sprintf(port, "%d", proxy->port);
        new_text = bra_cca_generate_key_value(new_text, text_size,
            BRA_STR_ID_PRX_PORT, (const kal_uint8 *)port, 0);
    }
    else if (proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL ||
        proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
    {
        int value_id = BRA_STR_ID_OFF;
        
        if (proxy->port == BRA_CCA_PORT_WSP_SEC_CL || proxy->port == BRA_CCA_PORT_WSP_SEC_CO)
            value_id = BRA_STR_ID_ON;
        
        new_text = bra_cca_generate_key_value(new_text, text_size,
            BRA_STR_ID_SECURITY, NULL, value_id);
    }

    /*username*/
    new_text = bra_cca_generate_key_value(new_text, text_size,
        BRA_STR_ID_PRX_UID, (const kal_uint8 *)BRA_CMN_HNV(proxy->username),
        0);
    
    
    /*password*/
    new_text = bra_cca_generate_key_value(new_text, text_size,
        BRA_STR_ID_PRX_PWD, (const kal_uint8 *)BRA_CMN_HNV(proxy->password),
        0);
    
#endif /*BRA_CFG_CCA_SHOW_WHOLE_PROF*/

    return new_text;
}


static kal_uint8*
bra_cca_generate_bookmark_info(kal_uint8* text, int *text_size, bra_cca_application_t *app)
{
    bra_cca_resource_t  *res;
    char                *title;
    int                 bkm_num;
    int                 first = FALSE;
    kal_uint8           *new_text = text;
    int                 get_bkm_head = FALSE;
    char                str_num[BRA_CCA_NUMBER_MAX_DIGIT];


    if (app == NULL || app->res_list == NULL)
        return new_text;
    
    /*check whether already installed, for that application node can has more than one to-proxy */
    if (app->is_res_updated == TRUE)
        return new_text;

    res = app->res_list;
    while (res)
    {
        if (res->homepage && first == FALSE) /*only skip the first homepage*/
        {
            first = TRUE;
        }
        else
        {
            if (get_bkm_head == FALSE)            
            {
                get_bkm_head = TRUE;

                bkm_num = bra_cca_get_bookmark_number(app->res_list);
                sprintf(str_num, "%d", bkm_num);
                new_text = bra_cca_generate_key_value(new_text, text_size,
                    BRA_STR_ID_BOOKMARKS, (const kal_uint8*)str_num, 0);
            }

            title = (res->title == NULL ? res->url : res->title);
            new_text = bra_cca_generate_key_value(new_text, text_size,
                BRA_STR_ID_TITLE, (const kal_uint8*)BRA_CMN_HNV(title), 0);
            
            new_text = bra_cca_generate_key_value(new_text, text_size,
                BRA_STR_ID_ADDRESS, (const kal_uint8*)BRA_CMN_HNV(res->url), 0);
        }
        res = res->next;
    }
    return new_text;
}


static int
bra_cca_get_profile_number(bra_cca_profile_t * list)
{
    bra_cca_profile_t   *p;
    int                 i = 0;
    
    
    if (list == NULL)
        return 0;
    
    p = list;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}


static int
bra_cca_get_current_profile_index(bra_cca_profile_t *list, bra_cca_profile_t *curr_prof)
{
    int                 i = 0;
    bra_cca_profile_t   *p;
    
    
    if (list == NULL || curr_prof == NULL)
        return 0;
    
    p = list;
    while (p)
    {
        i++;
        if (p == curr_prof)
            break;
        p = p->next;
    }
    return i;
}


static int
bra_cca_get_bookmark_number(bra_cca_resource_t* res_list)
{
    bra_cca_resource_t  *res;
    int                 i = 0;
    int                 first = FALSE;
    
    
    if (res_list == NULL)
        return 0;
    
    res = res_list;
    while (res)
    {
        if (res->homepage && first == FALSE) /*only skip the first homepage*/
        {
            first = TRUE;
        }
        else
        {
            i++;
        }
        res = res->next;
    }
    return i;
}


static char*
bra_cca_get_profile_name(bra_cca_profile_t *profile)
{
    if (profile == NULL)
        return NULL;
    if (profile->application && profile->application->name)
        return profile->application->name;

    if (profile->proxy && profile->proxy->proxy_name)
        return profile->proxy->proxy_name;
    return  NULL;
}


static int
bra_cca_get_profile_homepage(int prof_type, bra_cca_profile_t *profile, char**title, char** url)
{
    bra_cca_resource_t *res;
    
    
    if (profile == NULL || (title == NULL && url == NULL))
        return FALSE;

    if (title)
        *title = NULL;
    if (url)
        *url = NULL;

    if (prof_type == BRA_PROF_ID_MMS)
    {
        if(profile->application->addr == NULL)
            return FALSE;
        if (url)
            *url = profile->application->addr;
        return TRUE;
    }

    if(profile->application != NULL)
    {
        res = profile->application->res_list;
        while (res)
        {
            if (res->homepage) /*only get the first one*/
            {
                if (title)
                    *title = res->title;
                if (url)
                    *url = res->url;
                return TRUE;
            }
            res = res->next;
        }
    }

    if (profile->proxy)    
    {
        if (profile->proxy->homepage == NULL)
            return FALSE;
        if (url)
            *url = profile->proxy->homepage;
        return TRUE;
    }
    return FALSE;
}


#ifdef BRA_CFG_CCA_SHOW_WHOLE_PROF
static char*
bra_cca_get_muliti_data_account_name(bra_cca_proxy_t *proxy)
{
    int     k;
    int     i;
    char    *name;
    int     len = 0;
    const int bearer_list[] = {HDI_SOCKET_BEARER_GSM_GPRS, 
                               HDI_SOCKET_BEARER_GSM_CSD};
    
    if (proxy == NULL)
        return NULL;

    if (proxy->data_acct_name)
        return proxy->data_acct_name;

    for (i = 0; i < proxy->data_acct_num; i++)
    {
        if (proxy->data_account[i].name == NULL || proxy->data_account[i].id < 0)
            break;
        len += strlen(proxy->data_account[i].name) + 1;
    }
    if (len == 0)
        return NULL;

    name = BRA_ALLOC(len + 1);
    name[0] = '\0';
    for (k = 0; k >= sizeof(bearer_list)/sizeof(int); k++)
    {
        for (i = 0; i < proxy->data_acct_num; i++)
        {
            if (proxy->data_account[i].type == bearer_list[k])
            {
                if (proxy->data_account[i].name)
                {
                    if (k > 0)
                        strcat(name, "/");
                    strcat(name, proxy->data_account[i].name);
                }
                break;
            }
        }
    }
    proxy->data_acct_name = name;
    return proxy->data_acct_name;
}
#endif /*BRA_CFG_CCA_SHOW_WHOLE_PROF*/


static int
bra_cca_get_bearer_type_string_id(bra_cca_proxy_t *proxy)
{

    
    if (proxy == NULL || proxy->data_acct_num < 1)
        return 0;
    if (proxy->data_acct_num > 1)
        return BRA_STR_ID_BEARER_GPRS_GSM_DUAL;
    if(proxy->data_account[0].type == HDI_SOCKET_BEARER_GSM_GPRS)
        return BRA_STR_ID_BEARER_GPRS;
    return BRA_STR_ID_BEARER_GSM_CSD;
}


static int
bra_cca_is_simple_bookmak_setting(int prof_type, bra_cca_profile_t *profile)
{
    bra_cca_resource_t *res;


    if (prof_type != BRA_PROF_ID_BRA)
        return FALSE;
    
    if (profile == NULL)
        return FALSE;
    
    
    if (profile->proxy != NULL || profile->application == NULL)
        return FALSE;
    
    if (profile->application->res_list == NULL)
        return FALSE;

    res = profile->application->res_list;
    while (res)
    {
        if(res->url != NULL && 0 < strlen(res->url))
            break;
        res = res->next;
    }
    if (res == NULL)
        return FALSE;

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_14D95549FBC81B36683ED68581EEC0E4, "BRA: CCA: app, update, is simple bookmark setting\n"));

    return TRUE;
}


static void
bra_cca_create_profile_select_menu(void)    
{
    int                        i;
    bra_prof_names_t           *p;
    bra_cca_prof_menu_t        *win;
    MsfDeviceProperties        prop;  
    MsfPosition                pos = BRA_CFG_MENU_POS;

    
    /*remove menu key action from screen*/
    bra_view_disable ();  
    
    /*Get Device properties. e.g. the screen size since this can be dynamicaly changed*/
    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

    /*Allocate memory for the structure to hold the window and action handles
    If other static variables are needed these can be added to the menu type.
    Note thoug that the first item must be the window handle*/
    win = BRA_ALLOCTYPE (bra_cca_prof_menu_t);
    /*Create the Back and Accept action handle*/
    win->select = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
        BRA_STR_INSTALL,
        MsfSelect,
        1, 
        0x8000);
    win->back   = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
        BRA_STR_BACK,
        MsfBack,
        1, 
        0x8000);
    /*Now create the actual menu window*/
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,MsfExclusiveChoice,
        &prop.displaySize,
        win->select,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);

    /*Set window title*/
    MSF_WIDGET_SET_TITLE (win->window, BRA_STR_REPLACE_SETTING);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_TITLE);
    
    /*Add the available profile names to the menu*/
    p = bra_prof_get_sim_all_profile_names (bra_cca_cntx->prof_type, bra_cca_cntx->sim_id);
    
    for (i = 0; i < p->n_items; i++)
    {
        MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, p->s[i],  0, 0, 0, TRUE);
        MSF_WIDGET_RELEASE (p->s[i]);
    }
    
    BRA_FREE (p);
    /*Set Preselected menu item*/
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 0, MSF_CHOICE_ELEMENT_SELECTED);
    
    /*Add the previously created actions to the window*/
    MSF_WIDGET_ADD_ACTION (win->window, win->back);
    MSF_WIDGET_ADD_ACTION (win->window, win->select);
    
    /*Finally Show dialog. Note that the in focus parameter is NULL, i.e. this menu has no need
    to know if it is in focus or not.*/
    bra_win_show_window (BRA_WIN_ID_CCA_PROF_SELECT_MENU, 
        (bra_win_t*)win, 
        &pos, 
        bra_cca_action_delete_profile_select_menu, 
        NULL,
        bra_cca_action_profile_select_menu);
}


static void 
bra_cca_action_delete_profile_select_menu (bra_win_t *win)
{
    bra_cca_prof_menu_t *p;
    
    /*First retrieve the window structure*/
    p = (bra_cca_prof_menu_t *)(win);
    
    /*Remove the window from the screen*/
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    /*Release all widgets*/
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->select);
    MSF_WIDGET_RELEASE (p->back);
    
    /*Finally dealloc the window structure*/
    BRA_FREE (p);
}


static void
bra_cca_action_profile_select_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
    int                    i;
    bra_cca_prof_menu_t    *p;
    
    
    /*First retreive the window structure*/  
    p = (bra_cca_prof_menu_t *)(win);
    
    
    if (bra_action == p->back)
    {
        ASSERT(bra_cca_cntx->cca_doc.curr_prof);
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
        return;
    }

    /*The Accept action was enabled. Now find out which menu item that was selected*/
    for(i = 0; i < BRA_PROF_GET_PROF_NUM(bra_cca_cntx->prof_type); i++)
    {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
        {
            if (FALSE == bra_cca_can_replace_profile_in_using(bra_cca_cntx->prof_type, i))
            {
                bra_dlg_create_dlg (MsfConfirmation,
                    BRA_STR_PROFILE_IN_USE, 
                    BRA_STR_YES, 
                    NULL,
                    0, 
                    NULL);
                return;
            }

            if (bra_cca_cntx->prof_type == BRA_PROF_ID_MMS)
                i += BRA_CFG_N_WAP_PROFILES;
            bra_cca_cntx->cca_doc.curr_prof->sel_prof_id = i; /*get absolute profile id*/
            bra_cca_update_current_profile();

            /*process next profile*/
            bra_cca_cntx->cca_doc.curr_prof = bra_cca_cntx->cca_doc.curr_prof->next; 
            BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, 
                BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE, 
                bra_cca_cntx);
        }
    }
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
}      



static int
bra_cca_can_replace_profile_in_using(int prof_type, int prof_id)
{
    return TRUE;
}


static int 
bra_cca_get_next_free_profile_id(int prof_type, int sim_id, int *next_prof_id)
{
    int                     i;
    bra_cca_application_t   app;
    bra_cca_resource_t      res;
    bra_cca_proxy_t         proxy;
    bra_cca_profile_t       profile;
    int                     prof_num;
    bra_cca_get_prof_ind_t  get_prof_ind;
    int                     old_sim_id;
    int                     old_prof_type;
    int                     old_prof_id;


    if (next_prof_id == NULL)
        return -1;

    /*get profile type and max number*/
    if (prof_type == BRA_PROF_ID_BRA)
    {
        get_prof_ind.app_id = CCA_APP_BROWSER;
        prof_num = BRA_CFG_N_WAP_PROFILES;
    }
    else
    {
        get_prof_ind.app_id = CCA_APP_MMS;
        prof_num = BRA_CFG_N_MMS_PROFILES;
    }
    get_prof_ind.sim_id = sim_id;

    if (*next_prof_id >= prof_num)
        return -1;

    profile.application = &app;
    profile.proxy = &proxy;

    old_sim_id = bra_prof_get_profile_sim_id();
    old_prof_id = bra_prof_get_absolute_profile();
    old_prof_type = bra_prof_get_profile_id();

    for (i = *next_prof_id; i < prof_num; i++)
    {
        get_prof_ind.prof_id = i;
        memset(&proxy, 0, sizeof(bra_cca_proxy_t));
        memset(&res, 0, sizeof(bra_cca_resource_t));
        memset(&app, 0, sizeof(bra_cca_application_t));
        app.res_list = &res; 
        bra_cca_get_profile_info(&get_prof_ind, &proxy, &app, &res);
        if (FALSE != bra_cca_is_free_profile(prof_type, &profile))
            break;
    }

    /*restore old profile*/
    bra_prof_set_sim_selected_profile(old_prof_type, old_sim_id, old_prof_id, NULL);

    if (*next_prof_id < prof_num)
        *next_prof_id = i + 1;  /*set the start index to find next free profile*/
    
    if (i >= prof_num)
        return -1;
    if (prof_type == BRA_PROF_ID_MMS)
        i += BRA_CFG_N_WAP_PROFILES;

    return i;
}



static int
bra_cca_is_free_profile(int prof_type, bra_cca_profile_t *profile)
{
  
    if (profile == NULL || profile->proxy == NULL || profile->application == NULL)
        return TRUE;

    /*wsp protocol should have proxy*/
    if (profile->proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL
        || profile->proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
    {
        /*should have gateway for wsp*/
        if (TRUE == bra_cca_is_zero_proxy_address((const char *)profile->proxy->proxy_addr))
            return TRUE;
        if (profile->proxy->port != BRA_CCA_PORT_WSP_CL &&
            profile->proxy->port != BRA_CCA_PORT_WSP_CO &&
            profile->proxy->port != BRA_CCA_PORT_WSP_SEC_CL &&
            profile->proxy->port != BRA_CCA_PORT_WSP_SEC_CO)
            return TRUE;
    }

    if ((profile->proxy->username == NULL || 0 == strlen(profile->proxy->username)) &&
        (profile->proxy->password != NULL && 0 != strlen(profile->proxy->password)))
        return TRUE;
    
    /*can not have net id*/
    if (profile->proxy->data_account[0].id < 0 )
        return TRUE;

    if (prof_type == BRA_PROF_ID_MMS)
    {   /*should have application node to save mmsc address*/
        if (profile->application == NULL ||
            FALSE == bra_cca_is_mmsc_addr_valid((const char*)profile->application->addr))
            return TRUE;
    }
    return FALSE;
}


static int
bra_cca_is_mmsc_addr_valid(const char* addr)
{
    int     scheme_type;


    if (addr == NULL)
        return FALSE;

    if(!check_url((char*)addr) || !bra_cmn_url_is_valid((char*)addr))
        return FALSE;

    scheme_type = msf_url_get_scheme_type(addr);
    if (scheme_type != msf_scheme_http && scheme_type != msf_scheme_https && scheme_type != msf_scheme_empty)
        return FALSE;
    return TRUE;
}


static int
bra_cca_is_zero_proxy_address(const char *addr)
{
    unsigned char ip[BRA_CCA_IP_MAX_SEGMENT];

    if (addr == NULL || strlen(addr) == 0)
        return TRUE;
    if (BRA_CCA_IP_MAX_SEGMENT != bra_cmn_get_address((const char *)addr, (unsigned char *)ip))
        return TRUE;
    if (ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0)
         return TRUE;
    return FALSE;
}


static void
bra_cca_update_current_profile(void)
{
    ASSERT(bra_cca_cntx->cca_doc.curr_prof);

    if (bra_cca_cntx->cca_doc.curr_prof == NULL)
        return;
    bra_cca_cntx->cca_doc.curr_prof->result = 
        bra_cca_update_profile_by_id(bra_cca_cntx->cca_doc.cca_doc_type,
                                     bra_cca_cntx->prof_type,
                                     bra_cca_cntx->sim_id,
                                     bra_cca_cntx->cca_doc.curr_prof->sel_prof_id,
                                     bra_cca_cntx->cca_doc.curr_prof);
}


static cca_status_enum
bra_cca_update_profile_by_id(bra_cca_doc_type_enum cca_doc_type, 
                             int prof_type, int sim_id, int prof_id, bra_cca_profile_t *profile)
{
    int         old_sim_id;
    int         old_prof_id;
    int         old_prof_type;

    /*here use absolute profile id*/
    if (profile == NULL || prof_id < 0)
        return CCA_STATUS_FAIL;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_F1E715292F97E9C14FE836543B6D1A7D, "BRA: CCA: update, new profile type=%d, id=%d\n", prof_type, prof_id));

    old_sim_id = bra_prof_get_profile_sim_id();
    old_prof_id = bra_prof_get_absolute_profile();
    old_prof_type = bra_prof_get_profile_id();

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_D6FEF357D33DAAF2024D3E60ECEE5AB7, "BRA: CCA: update, old profile type=%d, id=%d\n", old_prof_type, old_prof_id));

    bra_prof_set_sim_selected_profile(prof_type, sim_id, prof_id, NULL);

    if (cca_doc_type == BRA_CCA_DOC_TYPE_DM)
    {
        bra_cca_revise_dm_profile(prof_type, profile);
    }
    /*profile name*/
    bra_cca_update_profile_name(prof_type, profile);
    
    /*homepage*/
    bra_cca_update_profile_homepage(prof_type, profile);

    /*proxy*/
    bra_cca_update_profile_proxy(prof_type, profile->proxy);
    
    /*bookmark*/
    bra_cca_update_profile_bookmark(prof_type, profile->application);

    /*save + calc checksum*/
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);

    /*restore old profile, for DM can update profile while in editing*/
    bra_prof_set_sim_selected_profile(old_prof_type, old_sim_id, old_prof_id, NULL);
    
    return CCA_STATUS_OK;  
}


static cca_status_enum
bra_cca_update_profile_name(int prof_type, bra_cca_profile_t *profile)
{
    char        *old_name;
    char        *new_name;


    if (profile == NULL)
        return CCA_STATUS_FAIL;

    old_name = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PROF_STR); 
    new_name = bra_cca_get_profile_name(profile);

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_80D3C94EAFCD8146BA1F5DA13146254A, "BRA: CCA: update, profile name:%s\n", BRA_CMN_HNV(new_name)));

    if (0 == strcmp ((const char*)BRA_CMN_HNV(old_name), (const char*)BRA_CMN_HNV(new_name)))
        return CCA_STATUS_OK;
   
    bra_prof_change_key_str_value(prof_type, BRA_PROF_KEY_PROF_STR, BRA_CMN_HNV(new_name), NULL);     
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_update_profile_homepage(int prof_type,  bra_cca_profile_t *profile)
{
    char    *new_url = NULL;
    char    *new_title = NULL;
    char*   old_url = NULL;
    char*   old_title = NULL;
    
    if (profile == NULL)
        return CCA_STATUS_FAIL;

    /*homepage*/  
    bra_cca_get_profile_homepage(prof_type, profile, &new_title, &new_url);
    old_title = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_TITLE);
    old_url = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_URL);

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_04A31D30DF957FA8A4746FACB7747B24, "BRA: CCA: update, homepage title=%s\n", BRA_CMN_HNV(new_title)));

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_C50C6E9D5EEA1CADD635BB7F1B4DBB16, "BRA: CCA: update, homepage url=%s\n", BRA_CMN_HNV(new_url)));

   
    if (0 != strcmp((const char*)BRA_CMN_HNV(new_title), (const char*)BRA_CMN_HNV(old_title)))
    {
        if (bra_prof_is_bra_profile_in_active_use(prof_type, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
            bra_cmn_set_local_hompage_title (BRA_STRCONV(BRA_CMN_HNV(new_title)));  
        bra_prof_change_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_TITLE, BRA_CMN_HNV(new_title), NULL);
    }    

    if (0 != strcmp((const char*)BRA_CMN_HNV(new_url), (const char*)BRA_CMN_HNV(old_url)))
    {
        if (prof_type == BRA_PROF_ID_BRA)
            new_url = (new_url == NULL ? BRA_CFG_DEFAULT_HOMPAGE_URL : new_url);
        else
            new_url = (new_url == NULL ? BRA_CCA_DEFAULT_MMS_HOMEPAGE : new_url);
        if (bra_prof_is_bra_profile_in_active_use(prof_type, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
            bra_cmn_set_local_hompage_url (BRA_CMN_HNV(new_url));  
        bra_prof_change_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_URL, BRA_CMN_HNV(new_url), NULL);
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_update_profile_proxy(int prof_type, bra_cca_proxy_t *proxy)
{
    char        *temp;
    int         old_port;
    int         old_conn_type;

    if (proxy == NULL)
        return CCA_STATUS_OK;
        
    /*data account*/
    bra_cca_update_profile_data_account(prof_type, proxy);
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_A72A61F0E2D958130C7AEF7F876B2C17, "BRA: CCA: update, conn_type=%d, port=%d, addr=%s\n", 
        proxy->conn_type, proxy->port, BRA_CMN_HNV(proxy->proxy_addr)));

    /*gateway, note:
      NULL address should be updated when both new address and old address are both zero address.
      for example, the old address may be zero one when factory setting is used.*/
    temp = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_ADDR);
    if (0 != strcmp((const char*)BRA_CMN_HNV(temp), (const char*)BRA_CMN_HNV(proxy->proxy_addr)) ||
        TRUE == bra_cca_is_zero_proxy_address((const char*)proxy->proxy_addr))
    {
        if (TRUE == bra_cca_is_zero_proxy_address((const char*)proxy->proxy_addr))
        {
            bra_prof_change_key_str_value (prof_type, BRA_PROF_KEY_PRX_ADDR, "", NULL);
        }
        else
        {
            bra_prof_change_key_str_value (prof_type, BRA_PROF_KEY_PRX_ADDR,
                BRA_CMN_HNV(proxy->proxy_addr), NULL);
        }
    }
    
    /*connection type and port*/
    bra_cca_get_real_conn_type_and_port(prof_type, &old_conn_type, &old_port);
    if (proxy->conn_type != old_conn_type)
        bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_CON_TYPE, proxy->conn_type, NULL);
    if (proxy->port != old_port || proxy->conn_type != old_conn_type)  
    {
        if ((proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO && proxy->port == BRA_CCA_PORT_WSP_CO) ||
            (proxy->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL && proxy->port == BRA_CCA_PORT_WSP_CL))
        {
            bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_PRX_PORT, 0, NULL);
        }
        else
        {
            bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_PRX_PORT, proxy->port, NULL);
        }
    }

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_1E9F48D5DD2A6A4B4D912A8E8A0E06FC, "BRA: CCA: update, user=%s, pass=%s\n", 
        BRA_CMN_HNV(proxy->username), BRA_CMN_HNV(proxy->password)));

    /*username*/
    temp = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_UID);
    if (0 != strcmp((const char*)BRA_CMN_HNV(temp), (const char*)BRA_CMN_HNV(proxy->username)))
        bra_prof_change_key_str_value (prof_type, BRA_PROF_KEY_PRX_UID, 
                                       BRA_CMN_HNV(proxy->username), NULL);

    /*password*/
    temp = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_PWD);
    if (0 != strcmp((const char*)BRA_CMN_HNV(temp), (const char*)BRA_CMN_HNV(proxy->password)))
        bra_prof_change_key_str_value (prof_type, BRA_PROF_KEY_PRX_PWD, 
                                       BRA_CMN_HNV(proxy->password), NULL);

    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_update_profile_data_account(int prof_type, bra_cca_proxy_t *proxy)
{ 
    int         old_value;
    int         new_value;
#ifdef BRA_CFG_PROF_FALLBACK
    int         i;
    int         j;
    char*       prof_keys[] = {BRA_PROF_KEY_NET_ID_GSM, BRA_PROF_KEY_NET_ID_GPRS};
    const  int  bearer_types[] = {HDI_SOCKET_BEARER_GSM_CSD, HDI_SOCKET_BEARER_GSM_GPRS};
#endif   
    
    
    if (proxy == NULL)
        return CCA_STATUS_OK;
    
    ASSERT(proxy->data_acct_num > 0)
        
   if (proxy->data_acct_num == 1)
   {   
       MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
           BRA_CCA_AB11B5EEBD78B3DB5FFE91C9884DAA76, "BRA: CCA: update, net id=%d\n", proxy->data_account[0].id));

#ifdef BRA_CFG_CONN_ALWAYS_ASK
       if (0 != bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_IS_ASK))
            bra_prof_change_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_IS_ASK, 0, NULL);
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

       old_value = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID);    

       new_value = always_ask_encode_data_account_id((kal_uint32)proxy->data_account[0].id, 
           (always_ask_sim_info_enum)bra_cbm_get_cbm_sim_id(bra_prof_get_profile_sim_id()),
           (kal_uint8)bra_cbm_get_app_id(prof_type), FALSE);

       if (new_value != old_value)
       {
           bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_NET_ID, new_value, NULL);                
       }

#ifdef BRA_CFG_PROF_FALLBACK
       old_value = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_DUAL); 
       if (0 != old_value)
           bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_NET_ID_DUAL, 0, NULL);                
       
#endif /*BRA_CFG_PROF_FALLBACK*/
 
       return CCA_STATUS_OK;

    }

#ifdef BRA_CFG_PROF_FALLBACK

#ifdef BRA_CFG_CONN_ALWAYS_ASK
   if (0 != bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_IS_ASK))
       bra_prof_change_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_IS_ASK, 0, NULL);
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

    for (i = 0; i < proxy->data_acct_num; i++) 
    {
        for (j = 0; j < sizeof(bearer_types)/sizeof(int); j++)
        {
            if (proxy->data_account[i].type == bearer_types[j])
                    break;
        }
        if (j == sizeof(bearer_types)/sizeof(int))
              continue;

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_AB11B5EEBD78B3DB5FFE91C9884DAA76, "BRA: CCA: update, net id=%d\n", proxy->data_account[i].id));

        old_value = bra_prof_get_key_int_value(prof_type, prof_keys[j]);

        new_value = always_ask_encode_data_account_id((kal_uint32)proxy->data_account[i].id, 
            (always_ask_sim_info_enum)bra_cbm_get_cbm_sim_id(bra_prof_get_profile_sim_id()),
            (kal_uint8)bra_cbm_get_app_id(prof_type), FALSE);

        if (new_value != old_value)
        {
            bra_prof_change_key_int_value (prof_type, prof_keys[j], new_value, 0);
        }

        if (proxy->data_account[i].type == HDI_SOCKET_BEARER_GSM_GPRS)
        {
            old_value = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID);
            if (proxy->data_account[i].id != old_value)
            {
                bra_prof_change_key_int_value (prof_type, BRA_PROF_KEY_NET_ID, 
                                               proxy->data_account[i].id, 0);
            }
        }
    }
    old_value = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_DUAL);
    if (1 != old_value)
        bra_prof_change_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_DUAL, 1, NULL);
    
#endif /*BRA_CFG_PROF_FALLBACK*/

    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_update_profile_bookmark(int prof_type, bra_cca_application_t *app)
{
    int                 ret;
    bra_cca_resource_t  *res;
    int                 first = FALSE;
    int                 result = FALSE;
    int                 i = 0;
    int                 num = 0;
    bra_cca_resource_t  **new_list;


    if (prof_type != BRA_PROF_ID_BRA)
        return CCA_STATUS_OK;

    if (app == NULL)
        return CCA_STATUS_OK;
    
    if (app->is_res_updated == TRUE)
        return CCA_STATUS_OK;

    num = bra_cca_get_bookmark_number(app->res_list);
    new_list = BRA_ALLOC(num * sizeof(bra_cca_resource_t*));
    memset(new_list, 0, num * sizeof(bra_cca_resource_t*));

    /*generate bookmark array in reverse older*/
    i = num - 1;
    res = app->res_list;
    while (res)
    {
        if (res->homepage && first == FALSE) /*only skip the first homepage*/
        {
            first = TRUE;
        }
        else
        {
            if (i >= 0)
            {
                new_list[i] = res;
                i--;
            }
        }
        res = res->next;
    }
    
    for (i = 0; i < num; i++)
    {
        res = new_list[i];
        if (res != NULL)
        {
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_00AA91EE1FA2D2D76BAB03E861AD1973, "BRA: CCA: update, boomark title =%s\n", BRA_CMN_HNV(res->title)));
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_5EDB927D5A6C23FA14400D3B43257776, "BRA: CCA: update, boomark url =%s\n", BRA_CMN_HNV(res->url)));
            
            ret = bra_bkm_offline_add_new_bookmark_to_file(res->title, res->url);
            if (ret != 0 && result == FALSE)
                result = TRUE;
        }
    }
    BRA_FREE(new_list);

    app->is_res_updated = TRUE;
    if (result == TRUE) /*at least one bookmark updated*/
        return CCA_STATUS_OK;
    return CCA_STATUS_SETTING_SKIPPED;
}





/**********************************************************************
* BRA_SIG_CCA_GET_PROF_IND handler 
**********************************************************************/



/*BRA_SIG_CCA_GET_PROF_IND*/
/*can get current profile in using*/
/* only can return to cca the following status now
  status = CCA_STATUS_OK;
           CCA_STATUS_OUT_OF_RANGE;
           CCA_STATUS_NOT_FOUND;
           CCA_STATUS_MEMFULL;
*/
void
bra_cca_handle_get_profile(bra_cca_get_prof_ind_t *get_prof_ind)
{
    S32                    hConfig;
    cca_status_enum        result;
    cca_status_enum        valid;
    int                    prof_type;
    int                    prof_id;

    
    /*parameter validation*/
    if (get_prof_ind == NULL)
        return;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_2CD500604A05F76D9C121C29E03026F4, "BRA: CCA: DM get, handle get profile, app_id=%d prof_id=%d\n",
        get_prof_ind->app_id, get_prof_ind->prof_id));

    if (get_prof_ind->app_id != CCA_APP_BROWSER &&
        get_prof_ind->app_id != CCA_APP_MMS)
        return;

#ifdef BRA_CFG_DUAL_SIM
    if (get_prof_ind->sim_id == BRA_SIM_ID_DEFAULT)
    {
        if (get_prof_ind->app_id == CCA_APP_BROWSER)
            get_prof_ind->sim_id = bra_sim_get_bra_sim_id_in_active_use();
        else
        {
            get_prof_ind->sim_id = bra_sim_get_sim_card_number();
            if (get_prof_ind->sim_id != BRA_SIM_ID_SIM1 && get_prof_ind->sim_id != BRA_SIM_ID_SIM2)
                get_prof_ind->sim_id = BRA_SIM_ID_SIM1;
        }
    }
#endif /* BRA_CFG_DUAL_SIM */

#ifndef BRA_CONFIG_MMS
    if (get_prof_ind->app_id == CCA_APP_MMS)
    {
        bra_cca_send_get_profile_rsp(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id, 
            NULL, CCA_STATUS_FAIL);
        return;
    }
#endif 

    prof_type = (get_prof_ind->app_id == CCA_APP_BROWSER ? BRA_PROF_ID_BRA : BRA_PROF_ID_MMS);
    prof_id = bra_cca_get_absolute_prof_id(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id);
    if (FALSE == bra_cca_can_get_profile(prof_type, get_prof_ind->sim_id, prof_id))
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_0B64D68764A44E16796C8527BA69C9F1, "BRA: CCA: DM get, can not get profile\n"));
        
        bra_cca_send_get_profile_rsp(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id, 
            NULL, CCA_STATUS_FAIL);
        return;

    }

    /*here, DM can get any profile at any time but may can update the profile in using*/

    /*create cca document, if the prof_id is invalid, a default profile is generated */
    result = bra_cca_create_cca_doc(get_prof_ind, (S32*)&hConfig);
    if (result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_9F70B43952F9C7356AED266BFD0DB14A, "BRA: CCA: DM get, create cca doc fail result=%d\n", result));

        bra_cca_send_get_profile_rsp(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id, 
            NULL, CCA_STATUS_MEMFULL);
        return;
    }

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_00859FEC6A4266243B3F897D33C15C84, "BRA: CCA: DM get, cca document is ready\n"));

    /*send response to cca*/
    valid = bra_cca_validate_app_id_and_prof_id(get_prof_ind->app_id, get_prof_ind->prof_id);
    if(valid != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_B31AB64F1EE02990C6582DBD6B2E8626, "BRA: CCA: DM get, out of profile id range\n"));

        result = CCA_STATUS_OUT_OF_RANGE;
    }
    bra_cca_send_get_profile_rsp(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id, hConfig, result);
}



static void
bra_cca_send_get_profile_rsp(MSF_UINT16 bra_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id, MSF_INT32 hConfig, cca_status_enum result)
{
    MYQUEUE                                message;
    mmi_cca_app_get_prof_rsp_struct        *data;
    
    data = (mmi_cca_app_get_prof_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
    data->sim_id = (U16)bra_cca_get_cca_sim_id((int)bra_sim_id);
    data->app_id = (U16)app_id;
    data->prof_id = (S32)prof_id;
    data->hConfig = (S32)hConfig;
    data->result = result;
    
    message.oslSrcId        = MOD_WAP;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = MSG_ID_MMI_CCA_APP_GET_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}


static cca_status_enum
bra_cca_validate_app_id_and_prof_id(int app_id, int prof_id)
{
    if (app_id == CCA_APP_BROWSER && 
        ((prof_id < 0 && prof_id != CCA_PROF_CURRENT) ||
        prof_id >= BRA_CFG_N_WAP_PROFILES)) 
    {
        return CCA_STATUS_OUT_OF_RANGE;
    }
    
    if (app_id == CCA_APP_MMS&& 
        ((prof_id < 0 && prof_id != CCA_PROF_CURRENT) ||
        prof_id >= BRA_CFG_N_MMS_PROFILES)) 
    {
        return CCA_STATUS_OUT_OF_RANGE;
    }
    return CCA_STATUS_OK;
}


static int 
bra_cca_can_get_profile(int prof_type, int sim_id, int prof_id)
{
    return bra_cca_can_allow_dm_operations(prof_type, sim_id, prof_id);
}


static int
bra_cca_can_allow_dm_operations(int prof_type, int sim_id, int prof_id)
{
    int   old_sim_id;
    int   old_prof_type;


    /*installing provisioning setting*/
    if (bra_win_get_window(BRA_WIN_ID_CCA_PROF_INFO_MENU) || 
        bra_win_get_window(BRA_WIN_ID_CCA_PROF_SELECT_MENU))
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_0048CA3ED97EF91B8251ADE8C9E94F2C, "BRA: CCA: DM op, prov installing, not allow DM Operations\n"));
        return FALSE;
    }
    /*in editing profile*/
    old_sim_id = bra_prof_get_profile_sim_id();
    old_prof_type = bra_prof_get_profile_id();
    if (old_sim_id == sim_id && old_prof_type == prof_type)
    {
        if (bra_win_get_window(BRA_WIN_ID_PROFILE_MENU))
        {
            MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_C0FD80EFEB27F61799D5A818E13ADC20, "BRA: CCA: DM op, profile editing, not allow DM Operations\n"));
            return FALSE;
        }
    }

    if (prof_type == BRA_PROF_ID_BRA)
    {
        if (prof_id >= 0 && bra_prof_is_bra_profile_in_active_use(prof_type, sim_id, prof_id))
        {
            if (TRUE == bra_cca_is_activated_profile_in_using(prof_type))  
                return FALSE;
        }
    }
    return TRUE;


}


static int
bra_cca_is_activated_profile_in_using(int prof_type)  
{
    if (prof_type == BRA_PROF_ID_MMS)
        return TRUE;
    if (prof_type == BRA_PROF_ID_BRA)
    {
        /*in connecting or has viewable page or in editing*/
        if (bra_view_is_busy() || bra_view_if_has_viewable_page())
        {
            MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_4BFC496257CB9B9D45987DE1E0D817AF, "BRA: CCA: DM op, downloading page, not allow DM Operations\n"));
            return TRUE;
        }

#ifdef BRA_CFG_PROF_FALLBACK
        if (bra_sif_is_pending_bearer_switch())
        {
            MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_F68D69BF477F457E0DD793168509DC14, "BRA: CCA: DM op, bearer switching, not allow DM Operations\n"));
            return TRUE;
        }
#endif

    }
    return FALSE;
}


static void
bra_cca_get_default_profile_info(bra_cca_get_prof_ind_t *get_prof_ind,
                                 bra_cca_proxy_t *proxy,
                                 bra_cca_application_t *app,
                                 bra_cca_resource_t *res)
{
    int   i;
 
    
    if (get_prof_ind == NULL)
        return;
    if(proxy == NULL && app == NULL && res == NULL)
        return;
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_66540FF7C26031537E14AF405653FDEF, "BRA: CCA: DM get, get default profile info\n"));

    if (proxy)
    {
        proxy->proxy_name = NULL;
        proxy->proxy_addr = BRA_CCA_DEFAULT_PROXY_ADDR;
        proxy->conn_type = BRA_CFG_PROF_DEFAULT_CON_TYPE;
        proxy->port = BRA_CCA_PORT_WSP_CO;
        proxy->username = NULL;
        proxy->password = NULL;
   
        proxy->data_account[0].id = BRA_CFG_PROF_DEFAULT_NET_ID;
        for (i = 1; i < BRA_CCA_MAX_NBR_BEARERS; i++)
            proxy->data_account[i].id = -1;
    }
    if (app)
    {
        app->name = NULL;
        if (get_prof_ind->app_id == CCA_APP_BROWSER)
        {   
            if(res)
                res->url = BRA_CFG_DEFAULT_HOMPAGE_URL;
        }
        else
            app->addr = BRA_CFG_DEFAULT_HOMPAGE_URL;
    }
}


static void 
bra_cca_get_profile_info(bra_cca_get_prof_ind_t *get_prof_ind,
                         bra_cca_proxy_t *proxy,
                         bra_cca_application_t *app,
                         bra_cca_resource_t *res)
{
    int   i;
    int   prof_type;
    int   prof_id;
    
    
   if (get_prof_ind == NULL)
        return;
   if(proxy == NULL && app == NULL && res == NULL)
        return;
    
    prof_type = (get_prof_ind->app_id == CCA_APP_BROWSER ? BRA_PROF_ID_BRA : BRA_PROF_ID_MMS);
    prof_id = bra_cca_get_absolute_prof_id(get_prof_ind->sim_id, get_prof_ind->app_id, get_prof_ind->prof_id);
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_361E2DAE447A3C4DE659C094F0DD4C6E, "BRA: CCA: DM get, get profile info prof_type=%d, prof_id=%d\n", prof_type, prof_id));

    /*load selected profile*/
    bra_prof_set_sim_selected_profile(prof_type, get_prof_ind->sim_id, prof_id, NULL);
    
    if (proxy)
    {
        proxy->proxy_name = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PROF_STR);  
        proxy->proxy_addr = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_ADDR);
      
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_5002AD063E12C13E7E995C767D533921, "BRA: CCA: DM get, profile info, proxy addr=%s\n", BRA_CMN_HNV(proxy->proxy_addr)));

        /*connection type and port*/
        bra_cca_get_real_conn_type_and_port(prof_type, &proxy->conn_type, &proxy->port);
    
        /*data account -- do not get name here */
        proxy->data_account[0].id = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID); 
        proxy->data_account[0].type = HDIa_networkAccountGetBearer(proxy->data_account[0].id);
        proxy->data_acct_num = 1;

        for (i = 1; i < BRA_CCA_MAX_NBR_BEARERS; i++)
            proxy->data_account[i].id = -1;
        
#ifdef BRA_CFG_PROF_FALLBACK
        if ( prof_type == BRA_PROF_ID_BRA &&
            1 == bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_DUAL))
        {
            proxy->data_account[0].id = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_GPRS);
            proxy->data_account[0].type = HDIa_networkAccountGetBearer(proxy->data_account[0].id);
            
            proxy->data_account[1].id = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_GSM);
            proxy->data_account[1].type = HDIa_networkAccountGetBearer(proxy->data_account[1].id);
            proxy->data_acct_num = 2;
        }
#endif /*BRA_CFG_PROF_FALLBACK*/
        
#ifdef MMS_CFG_FALLBACK_SUPPORT
        if ( prof_type == BRA_PROF_ID_MMS &&
            1 == bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_DUAL))
        {
            proxy->data_account[0].id = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_GPRS);
            proxy->data_account[0].type = HDIa_networkAccountGetBearer(proxy->data_account[0].id);
           
            proxy->data_account[1].id = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_NET_ID_GSM);
            proxy->data_account[1].type = HDIa_networkAccountGetBearer(proxy->data_account[1].id);
            proxy->data_acct_num = 2;
        }
#endif /*MMS_CFG_FALLBACK_SUPPORT*/
        

        /*user & password*/
        proxy->username =  bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_UID);
        proxy->password = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PRX_PWD);
    }
    
    if (app)
    {
        app->name = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_PROF_STR); 
        /*homepage*/
        if (prof_type == BRA_PROF_ID_BRA)
        {
            if (res)
            {
                res->homepage = NULL; /*do not care this parameter, set to null*/
                res->next = NULL;
                res->title = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_TITLE);
                res->url = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_URL);

                MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_CCA_C616240F438D90734C24B18D2E281A3C, "BRA: CCA: DM get, profile info, homepage=%s\n", BRA_CMN_HNV(res->url)));
            }
        }
        else
        {
            app->addr = bra_prof_get_key_str_value(prof_type, BRA_PROF_KEY_HOMEPAGE_URL);
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_CCA_C0196F14021F6746556D8D40DE217461, "BRA: CCA: DM get, profie info, mmsc=%s\n", BRA_CMN_HNV(app->addr)));
        }
    }
}


static void
bra_cca_get_real_conn_type_and_port(int prof_type, int *conn_type,  int *port)
{
    if (conn_type == NULL || port == NULL)
        return;


    /*conntion type*/
   *conn_type = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_CON_TYPE);
    
    /*get real port*/ 
   *port = bra_prof_get_key_int_value(prof_type, BRA_PROF_KEY_PRX_PORT);

   MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
       BRA_CCA_77CC7064DDA4875C247147F7C988CD5A, "BRA: CCA: profile info, conn_type=%d, port=%d\n", *conn_type, *port));

    if (*conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO && *port == 0)
        *port = BRA_CCA_PORT_WSP_CO;
    else if (*conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL && *port == 0)
         *port = BRA_CCA_PORT_WSP_CL;
}


static cca_status_enum
bra_cca_create_cca_doc(bra_cca_get_prof_ind_t* get_prof_ind, S32 *hConfig)
{
    S32                    hRoot;
    cca_status_enum        result;
    
    
    if(hConfig == NULL)
        return CCA_STATUS_FAIL;
    
    *hConfig = 0;
    result = bra_cca_create_cca_doc_node_tree(get_prof_ind, (S32*)&hRoot);
    if (result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_0C197D27384D07C35CE718BBDD9D47C1, "BRA: CCA: DM get, create cca node tree fail\n"));

        mmi_cca_docroot_release(hRoot);
        return CCA_STATUS_FAIL;
    }
    *hConfig = mmi_cca_doc_new(hRoot);
    if (!*hConfig)
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_CCA_8C5154576CD2044A5A61270FCAA968FC, "BRA: CCA: DM get, create cca doc hConfig fail\n"));

        mmi_cca_docroot_release(hRoot);
        return CCA_STATUS_FAIL;
    }
    return CCA_STATUS_OK;
}


static cca_status_enum 
bra_cca_create_cca_doc_node_tree(bra_cca_get_prof_ind_t *get_prof_ind, S32* hRoot)
{
    cca_status_enum       result;
    bra_cca_application_t app_info;
    bra_cca_resource_t    res_info;
    bra_cca_proxy_t       proxy_info;
    int                   old_sim_id;
    int                   old_prof_type;
    int                   old_prof_id;

    
    if(get_prof_ind == NULL || hRoot == NULL)
        return CCA_STATUS_FAIL;    
    
    *hRoot = mmi_cca_doc_new_rootnode();
    if (!*hRoot)
    {
        return CCA_STATUS_MEMFULL;
    }
    
    memset(&proxy_info, 0, sizeof(bra_cca_proxy_t));
    memset(&res_info, 0, sizeof(bra_cca_resource_t));
    memset(&app_info, 0, sizeof(bra_cca_application_t));
    app_info.res_list = &res_info;
    
    old_sim_id = bra_prof_get_profile_sim_id();
    old_prof_id = bra_prof_get_absolute_profile();
    old_prof_type = bra_prof_get_profile_id();

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_0894F597B35915C180417F9213573032, "BRA: CCA: DM get, to create node tree old prof type=%d prof id=%d\n",
        old_prof_type, old_prof_id));

    if (CCA_STATUS_OK != bra_cca_validate_app_id_and_prof_id(get_prof_ind->app_id, get_prof_ind->prof_id))
        bra_cca_get_default_profile_info(get_prof_ind, &proxy_info, &app_info, &res_info);
    else
        bra_cca_get_profile_info(get_prof_ind, &proxy_info, &app_info, &res_info);
    

    result = bra_cca_create_proxy_node_and_attach(*hRoot, get_prof_ind, &proxy_info);
    if (result != CCA_STATUS_OK)
        return result;

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_A9DBF389C0BB242E092CED3A5D89AA7A, "BRA: CCA: DM get, created proxy node\n"));

    result = bra_cca_create_application_node_and_attach(*hRoot, get_prof_ind, &app_info);
    if (result != CCA_STATUS_OK)
        return result;

   MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_4EACECB599B3A604C01BB49D89BB6BCD, "BRA: CCA: DM get, created app node\n"));
   /*restore old profile*/    
   bra_prof_set_sim_selected_profile(old_prof_type, old_sim_id, old_prof_id, NULL);
   return CCA_STATUS_OK;  
}


static cca_status_enum
bra_cca_create_proxy_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                     bra_cca_proxy_t *proxy_info)
{
    int              i;
    S32              hNode;
    cca_status_enum  result;
    char             *proxy_addr;
    
    
    if(hRoot == 0 || proxy_info == NULL)
        return CCA_STATUS_FAIL;
    
    /*create proxy node*/
    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, hRoot);
    if (!hNode)
        return CCA_STATUS_MEMFULL;
    
    /*add nodeid*/  
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, (const S8 *)BRA_CCA_NODE_ID_PROXY);
    if (result !=  CCA_STATUS_OK)
        return result;
    
    /*add proxy-id*/
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PROXY_ID, (const S8 *)BRA_CCA_PROXY_ID);
    if (result !=  CCA_STATUS_OK)
        return result;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_69F31F60D78515AB4601040AE00912FD, "BRA: CCA: DM get, proxy name=%s\n", BRA_CMN_HNV(proxy_info->proxy_name)));
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, 
        (const S8 *)BRA_CMN_HNV(proxy_info->proxy_name));
    if (result !=  CCA_STATUS_OK)
        return result;


    result = mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);
    if (result !=  CCA_STATUS_OK)
        return result;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_725430F4791DDFEA4D27269D03EEBFA4, "BRA: CCA: DM get, proxy addr=%s\n", BRA_CMN_HNV(proxy_info->proxy_addr)));

    if (proxy_info->proxy_addr == NULL || 0 == strlen (proxy_info->proxy_addr)) 
        proxy_addr = BRA_CCA_DEFAULT_PROXY_ADDR;
    else
        proxy_addr = proxy_info->proxy_addr;
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXADDR, (const S8 *)proxy_addr);
    if (result !=  CCA_STATUS_OK)
        return result;

    /*data account*/
    for (i = 0; i < BRA_CCA_MAX_NBR_BEARERS; i++)
    {
        if (proxy_info->data_account[i].id < 0)
            break;

        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
            BRA_CCA_FB1068363836245FBF4FC9E2E5F83133, "BRA: CCA: DM get, net id=%d\n", proxy_info->data_account[i].id));
       result = mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_DATAACCTID, 
            (const S32)proxy_info->data_account[i].id);
        if (result != CCA_STATUS_OK)
            return result;
    }

    result = bra_cca_create_port_node_and_attach(hNode, get_prof_ind, proxy_info);
    if (result != CCA_STATUS_OK)
        return result;

    result = bra_cca_create_authinfo_node_add_attach(hNode, get_prof_ind, proxy_info);
    if (result != CCA_STATUS_OK)
        return result;

    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_create_port_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                    bra_cca_proxy_t *proxy_info)
{
    S32                    hNode;
    cca_status_enum        result;
    S32                    wsp_service;
    char                   port[BRA_CCA_PORT_MAX_NUM * 2];
    const S32              http_service[] = {CCA_NS_VAL_OTA_HTTP_TO,
                                          CCA_NS_VAL_OTA_HTTP_TLS_TO};
    
    
    if(hRoot == 0 || proxy_info == NULL)
        return CCA_STATUS_FAIL;

    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, hRoot);
    if (!hNode)
        return CCA_STATUS_MEMFULL;
    
    /*add nodeid*/  
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, 
        (const S8 *)BRA_CCA_NODE_ID_PORT);
    if (result !=  CCA_STATUS_OK)
        return result;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_0C04E276243512138121E729DBD47824, "BRA: CCA: DM get, conn type=%d\n", proxy_info->conn_type));

    if (proxy_info->conn_type == BRA_SET_CONNECTION_TYPE_HTTP) 
    {
        result = mmi_cca_doc_add_nodedata_ints(hNode, CCA_NS_OMA_SERVICE,
            (S32)sizeof(http_service)/sizeof(S32),
            (const S32 *)http_service);
    }
    else if (proxy_info->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
    {
        if (proxy_info->port == BRA_CCA_PORT_WSP_SEC_CL)
            wsp_service = CCA_NS_VAL_CL_SEC_WSP;
        else
            wsp_service = CCA_NS_VAL_CL_WSP;
        result = mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_SERVICE, (const S32)wsp_service);
    }
    else if (proxy_info->conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
    {
        if (proxy_info->port == BRA_CCA_PORT_WSP_SEC_CO)
            wsp_service = CCA_NS_VAL_CO_SEC_WSP;
        else
            wsp_service = CCA_NS_VAL_CO_WSP;
        result = mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_SERVICE, (const S32)wsp_service);
    }
    if (result != CCA_STATUS_OK)
        return result;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_E1FAF6A98285DA88FB4561A09C5A9F0E, "BRA: CCA: DM get, port=%d\n", proxy_info->port));

    sprintf(port, "%d", proxy_info->port); 
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PORTNBR, port);
    if (result != CCA_STATUS_OK)
        return result;
    
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_create_authinfo_node_add_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                        bra_cca_proxy_t *proxy_info)
{
    S32                     hNode;
    cca_status_enum         result;
    
    
    if(hRoot == 0 || proxy_info == NULL)
        return CCA_STATUS_FAIL;

    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, hRoot);
    if (!hNode)
        return CCA_STATUS_MEMFULL;

    /*add nodeid*/  
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, 
        (const S8 *)BRA_CCA_NODE_ID_PXAUTHINFO);
    if (result !=  CCA_STATUS_OK)
        return result;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_B7FF1B31832A838F193FC5FBD7F9733F, "BRA: CCA: DM get, user=%s\n", BRA_CMN_HNV(proxy_info->username)));

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_ID, 
                                         (const S8*)BRA_CMN_HNV(proxy_info->username));
    if (result != CCA_STATUS_OK)
        return result;
        
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_A74A2F1CC1B2BAD08EB78C5B5AB701B9, "BRA: CCA: DM get, pwd=%s\n", BRA_CMN_HNV(proxy_info->password)));

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_PW, 
                                           (const S8*)BRA_CMN_HNV(proxy_info->password));
    if (result != CCA_STATUS_OK)
        return result;
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_create_application_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind, 
                                           bra_cca_application_t *app_info)
{
    cca_status_enum     result;
    S32                 hNode;
    char                *app_id;
    

    if(hRoot == 0 || get_prof_ind == NULL || app_info == NULL)
        return CCA_STATUS_FAIL;
    
    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, hRoot);
    if (!hNode)
        return CCA_STATUS_MEMFULL;
    
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, 
        (const S8*)BRA_CCA_NODE_ID_APPLICATION);
    if (result != CCA_STATUS_OK)
        return result;
    
    app_id = (get_prof_ind->app_id == CCA_APP_BROWSER ? BRA_CCA_APP_ID_WAP : BRA_CCA_APP_ID_MMS);    
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_APPID, 
        (const S8*)app_id);
    if (result != CCA_STATUS_OK)
        return result;
    
    /*application*/
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, 
        (const S8*)BRA_CMN_HNV(app_info->name));
    if (result != CCA_STATUS_OK)
        return result;
    
    /*proxy id*/
    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_TO_PROXY, 
        (const S8*)BRA_CCA_NODE_ID_PROXY);
    if (result != CCA_STATUS_OK)
        return result;
    
    if (get_prof_ind->app_id == CCA_APP_BROWSER)
    {
        result = bra_cca_create_resource_node_and_attach(hNode, get_prof_ind, app_info->res_list);
        if (result != CCA_STATUS_OK)
            return result;
    }
    else
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
            BRA_CCA_7A18B75389EEC120C0CEBC8C9BDA55DF, "BRA: CCA: DM get, homepage=%s\n", BRA_CMN_HNV(app_info->addr)));

        result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_ADDR, 
            (const S8*)BRA_CMN_HNV(app_info->addr));
        if (result != CCA_STATUS_OK)
            return result;
    }
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_create_resource_node_and_attach(S32 hRoot, bra_cca_get_prof_ind_t *get_prof_ind,
                                       bra_cca_resource_t *res_info)
{
    cca_status_enum     result;
    S32                 hNode;

    
    if(hRoot == 0 || res_info == NULL)
        return CCA_STATUS_FAIL;

    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_RESOURCE, hRoot);
    if (!hNode)
        return CCA_STATUS_MEMFULL;

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, 
        (const S8*)BRA_CCA_NODE_ID_RESOURCE);
    if (result != CCA_STATUS_OK)
        return result;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_A3B871B6582E452C99235A4F3A1276BC, "BRA: CCA: DM get, homepage title=%s\n", BRA_CMN_HNV(res_info->title)));

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, 
        (const S8*)BRA_CMN_HNV(res_info->title));
    if (result != CCA_STATUS_OK)
        return result;
    
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, 
        BRA_CCA_7A18B75389EEC120C0CEBC8C9BDA55DF, "BRA: CCA: DM get, homepage=%s\n", BRA_CMN_HNV(res_info->url)));

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_URI, 
        (const S8*)BRA_CMN_HNV(res_info->url));
    if (result != CCA_STATUS_OK)
        return result;

    result = mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_STARTPAGE, 
        (const S8*)BRA_CMN_HNV(NULL));
    if (result != CCA_STATUS_OK)
        return result;

    return CCA_STATUS_OK;
}



/**********************************************************************
* BRA_SIG_CCA_UPDATE_PROF_IND handler 
**********************************************************************/


/* only can return to cca the following status now
  status = CCA_STATUS_OK;
           CCA_STATUS_FAIL;
           CCA_STATUS_MEMFULL;
*/
void
bra_cca_handle_update_profile(bra_cca_update_prof_ind_t *update_prof_ind)
{
    
    cca_status_enum result;
    bra_cca_doc_t   cca_doc;
    int             prof_id;
    int             prof_type;
    
    

    /*check parameter*/
    if(update_prof_ind == NULL)
        return;

    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_9A54696FA89C795C4538C88F1F566CC5, "BRA: CCA: DM update, handle update profile, app_id=%d prof_id=%d hConfig=%d\n",
        update_prof_ind->app_id, update_prof_ind->prof_id, update_prof_ind->hConfig));

    if(update_prof_ind->app_id != CCA_APP_BROWSER &&
        update_prof_ind->app_id != CCA_APP_MMS)
        return;

#ifdef BRA_CFG_DUAL_SIM
    if (update_prof_ind->sim_id == BRA_SIM_ID_DEFAULT)
    {
        if (update_prof_ind->app_id == CCA_APP_BROWSER)
            update_prof_ind->sim_id = bra_sim_get_bra_sim_id_in_active_use();
        else
        {
            update_prof_ind->sim_id = bra_sim_get_sim_card_number();
            if (update_prof_ind->sim_id != BRA_SIM_ID_SIM1 && update_prof_ind->sim_id != BRA_SIM_ID_SIM2)
                update_prof_ind->sim_id = BRA_SIM_ID_SIM1;
        }
    }
#endif /* BRA_CFG_DUAL_SIM */

#ifndef BRA_CONFIG_MMS
    if (update_prof_ind->app_id == CCA_APP_MMS)
    {
        bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, NULL);
        return;
    }
#endif 
    
   if (update_prof_ind->hConfig == NULL)
    {
       bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, NULL);
        return;
    }
        
    result = bra_cca_validate_app_id_and_prof_id(update_prof_ind->app_id, update_prof_ind->prof_id);
    if (result != CCA_STATUS_OK)
    {
        bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, NULL);
        return;
    }


    /*here, DM can get any profile at any time but may can update the profile in using*/

    /*check whether can update profile*/
    prof_type = (update_prof_ind->app_id == CCA_APP_BROWSER ? BRA_PROF_ID_BRA : BRA_PROF_ID_MMS);
    prof_id = bra_cca_get_absolute_prof_id(update_prof_ind->sim_id, update_prof_ind->app_id,
        update_prof_ind->prof_id);
    
    if (FALSE == bra_cca_can_update_profile(prof_type, update_prof_ind->sim_id, prof_id))
    {   
       MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_EDB6E035221E013F05E8ED3A58097307, "BRA: CCA: DM update, no update in using\n"));

       bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, NULL);
        return;
        
    }
    

    /*parse cca document*/
    memset(&cca_doc, 0, sizeof(bra_cca_doc_t));
    cca_doc.cca_doc_type = BRA_CCA_DOC_TYPE_DM;  /*set CCA document type*/
    result = mmi_cca_doc_process((S32)update_prof_ind->hConfig,
                                 (const U16 *)bra_cca_mapping_table, 
                                 (const S32)(sizeof(bra_cca_mapping_table)/sizeof(U16)),
                                 NULL,
                                 bra_cca_doc_node_callback,
                                 (void *)&(cca_doc));
    
    if (result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_103AF945C312EB70C53653FB271E326B, "BRA: CCA: DM udpate, parse fail result=%d\n", result));
        bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, &cca_doc);
        return;
    }

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_6ED608FF22114B741B8BE79D9A7B63C3, "BRA: CCA: DM udpate, parse, cca doc ok\n"));

    result = bra_cca_create_dm_profile(prof_type, &cca_doc);
    if (result != CCA_STATUS_OK)
    {
        MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_FEB24D745C8E99CEC47CA9AB26F3AD3D, "BRA: CCA: DM udpate, create, invalid profile list\n"));

        bra_cca_handle_update_profile_result(update_prof_ind, CCA_STATUS_FAIL, &cca_doc);
        return;
    } 
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_1FDD8954564DA0ADCBFF67528CF7407A, "BRA: CCA: DM udpate, create, DM profile is ready\n"));

    /*update specified profile*/
    result = bra_cca_update_profile_by_id(cca_doc.cca_doc_type, prof_type, update_prof_ind->sim_id, prof_id, cca_doc.prof_list);

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_CCA_6DDF805E7A71413F7C6ADE4E8789772A, "BRA: CCA: DM udpate, udpate, finished\n"));
    
    /*
    for MMS profile, every profile can be updated and activated at any time.
    for WAP profile, if current activated profile is in using, no profile can be activated;
    */
    if (prof_type == BRA_PROF_ID_MMS ||
        (prof_type == BRA_PROF_ID_BRA && FALSE == bra_cca_is_activated_profile_in_using(prof_type)))
    {
        bra_cca_activate_profile(prof_type, (int)update_prof_ind->sim_id, prof_id); 
    }

    /*send response to cca*/
    if (result != CCA_STATUS_OK)
        result = CCA_STATUS_FAIL;
    bra_cca_handle_update_profile_result(update_prof_ind, result, &cca_doc);
}


static void
bra_cca_handle_update_profile_result(bra_cca_update_prof_ind_t *update_prof_ind, cca_status_enum result, bra_cca_doc_t *cca_doc)
{
    bra_cca_send_update_profile_rsp(update_prof_ind->sim_id, update_prof_ind->app_id, update_prof_ind->prof_id,
                                    update_prof_ind->hConfig, result);
    if (cca_doc)
        bra_cca_free_cca_doc(cca_doc);
}


static void
bra_cca_send_update_profile_rsp(MSF_UINT16 bra_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id, MSF_INT32 hConfig, cca_status_enum result)
{
    MYQUEUE                             message;
    mmi_cca_app_update_prof_rsp_struct  *data;
    
    data = (mmi_cca_app_update_prof_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
 
    data->sim_id = (U16)bra_cca_get_cca_sim_id((int)bra_sim_id);
    data->app_id = (U16)app_id;
    data->prof_id = (S32)prof_id;
    data->hConfig = (S32)hConfig;
    data->result = result;
    
    message.oslSrcId        = MOD_WAP;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}


static int
bra_cca_get_absolute_prof_id(int sim_id, int app_id, int dm_prof_id)
{
    int     prof_id;
    

    /* now the sim_id is already revised, can only be master or slave */
    if (app_id == CCA_APP_BROWSER)
    {
        if (dm_prof_id == CCA_PROF_CURRENT)
            prof_id = bra_prof_get_sim_activated_profile_id(BRA_PROF_ID_BRA, sim_id);
        else
            prof_id = dm_prof_id;
    }
    else
    {
        if (dm_prof_id == CCA_PROF_CURRENT)
            prof_id = bra_prof_get_sim_activated_profile_id(BRA_PROF_ID_MMS, sim_id);
         else
            prof_id = dm_prof_id + BRA_CFG_N_WAP_PROFILES;
    }
    return prof_id;
}



static int
bra_cca_can_update_profile(int prof_type, int sim_id, int prof_id)
{
    return bra_cca_can_allow_dm_operations(prof_type, sim_id, prof_id);
}


static cca_status_enum
bra_cca_create_dm_profile(int prof_type, bra_cca_doc_t *cca_doc)
{
    if (cca_doc == NULL)
        return CCA_STATUS_FAIL;
    
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_CCA_768C75EEA1370F0880BA0BAE851FE39C, "BRA: CCA: update, to create dm profile needed to udpate\n"));

    if (cca_doc->app_list == NULL && cca_doc->proxy_list == NULL)
        return CCA_STATUS_FAIL;

    /*only get the first profile, for DM only update one profile at one time now*/
    cca_doc->prof_list = BRA_ALLOCTYPE(bra_cca_profile_t);
    cca_doc->prof_list->application = cca_doc->app_list;
    cca_doc->prof_list->proxy = cca_doc->proxy_list;
    cca_doc->prof_list->next = NULL;
    cca_doc->prof_list->result = CCA_STATUS_OK;
    cca_doc->prof_list->sel_prof_id = -1;
    return CCA_STATUS_OK;
}


static cca_status_enum
bra_cca_revise_dm_profile(int prof_type, bra_cca_profile_t *profile)
{
    if (profile == NULL)
        return CCA_STATUS_FAIL;

    if (profile->application == NULL || profile->proxy == NULL)
    {
        return CCA_STATUS_FAIL;
    }

    /*revise homepage*/
    if (prof_type == BRA_PROF_ID_MMS)
    { 
        if (FALSE == bra_cca_is_mmsc_addr_valid((const char*)profile->application->addr))
        {
            BRA_FREE(profile->application->addr);
            profile->application->addr = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)BRA_CCA_DEFAULT_MMS_HOMEPAGE);
        }
    }

    /*revise data account*/
    if (profile->proxy->data_acct_num <= 0)
    {
        profile->proxy->data_account[0].id = 0;
        profile->proxy->data_acct_num = 1;
    }

    /*revise gateway*/
    if (profile->proxy->proxy_addr == NULL)
    {
        /*for zero address can be set ok, so do nothing here*/
    }
    
    /*revise port and connection type*/
    bra_cca_revise_dm_conn_type_and_port(prof_type, 
                                         &(profile->proxy->conn_type), 
                                         &(profile->proxy->port));
    return CCA_STATUS_OK;
}


static void
bra_cca_revise_dm_conn_type_and_port(int prof_type, int *conn_type, int *port)
{
     int  old_conn_type;
     int  old_port;


    if (conn_type == NULL || port == NULL)
        return;
    bra_cca_get_real_conn_type_and_port(prof_type, &old_conn_type, &old_port);
    if (*conn_type == old_conn_type && *port == old_port)
        return;
    /*connection have changed, that's to say this connection type is ok, use it*/
    if (*conn_type != old_conn_type)
    {
        /*do not support WSP CL now*/
        if (*conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
            *conn_type = BRA_SET_CONNECTION_TYPE_WSP_CO;
        return;
    }
    /*do not support WSP CL now*/
    if (*port == BRA_CCA_PORT_WSP_CL)
        *port = BRA_CCA_PORT_WSP_CO;
    else if (*port == BRA_CCA_PORT_WSP_SEC_CL)
        *port = BRA_CCA_PORT_WSP_SEC_CO;
    else if (*port == -1)
        *port = BRA_CCA_PORT_WSP_CO;
    /*only port is changed, change connection type by port, temp solution*/
    *conn_type = bra_cca_get_conn_type_by_port(*port);
}


#ifdef BRA_CFG_DM

static void
bra_cca_register_dm_check_function(void)
{
    mmi_dm_set_check_function(DM_SETTING_TYPE_WAP, bra_cca_dm_wap_check_function);

#ifdef BRA_CONFIG_MMS
    mmi_dm_set_check_function(DM_SETTING_TYPE_MMS, bra_cca_dm_mms_check_function);
#endif
}


static bf_bool
bra_cca_dm_wap_check_function(void)
{
    /*use prof_id = -1 to avoid the check of browser in using*/
    return bra_cca_can_allow_dm_operations(BRA_PROF_ID_BRA, -1, -1);
}


#ifdef BRA_CONFIG_MMS
static bf_bool
bra_cca_dm_mms_check_function(void)
{
    /*prof_id is no useful here now*/
    return bra_cca_can_allow_dm_operations(BRA_PROF_ID_MMS, -1, -1);
}
#endif /* BRA_CONFIG_MMS */

#endif /*BRA_CFG_DM*/


MSF_UINT16
bra_cca_get_bra_sim_id(MSF_UINT16 cca_sim_id)
{
    MSF_UINT16   bra_sim_id = 0;


#ifdef BRA_CFG_DUAL_SIM

    switch (cca_sim_id)
    {
    case MMI_CCA_SIM_ID_SIM1:
        bra_sim_id = BRA_SIM_ID_SIM1;
        break;

    case MMI_CCA_SIM_ID_SIM2:
        bra_sim_id = BRA_SIM_ID_SIM2;
        break;

    default:
        bra_sim_id = BRA_SIM_ID_DEFAULT;
        break;
    }
#endif /* BRA_CFG_DUAL_SIM */

    return bra_sim_id;
}


static int
bra_cca_get_cca_sim_id(int bra_sim_id)
{
    int   cca_sim_id  = MMI_CCA_SIM_ID_DEFAULT;


#ifdef BRA_CFG_DUAL_SIM
    switch (bra_sim_id)
    {
    case BRA_SIM_ID_SIM1:
        cca_sim_id = MMI_CCA_SIM_ID_SIM1;
        break;

    case BRA_SIM_ID_SIM2:
        cca_sim_id = MMI_CCA_SIM_ID_SIM2;
        break;

    default:
        cca_sim_id = MMI_CCA_SIM_ID_DEFAULT;
        break;
    }
#endif /* BRA_CFG_DUAL_SIM */
    return  cca_sim_id;
}

#endif /*BRA_CFG_CCA*/
#endif /*BRA_CONFIG_PROVISIONING*/

