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
 *  CentralConfigAgentDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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
#ifndef MMI_CCADEFS_H
#define MMI_CCADEFS_H

#include "MMIDataType.h"


/* ILM Primitive Structs */
typedef struct {
    LOCAL_PARA_HDR
    U16 sim_id;
    U16 config_id;
    S32 hConfig;
    S32 num_symbols;
    U16 l1symbols[CCA_TREE_MAX_CHILDS];
    S32 l1symbols_count[CCA_TREE_MAX_CHILDS];
} mmi_cca_app_configure_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    U16 sim_id;
    U16 config_id;
    S32 hConfig;
    cca_status_enum status;
} mmi_cca_app_configure_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    U16 sim_id;
    U16 spec_id;
    S32 hConfig;
} mmi_cca_source_new_doc_ind_struct;

/*
typedef struct {
    LOCAL_PARA_HDR
} cca_source_new_doc_rsp_struct;
*/

typedef struct {
    LOCAL_PARA_HDR
    U16 sim_id;
    cca_status_enum status;
} mmi_cca_source_ui_invalid_setting_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    S32 trans_id;
    U16 sim_id;
    U16 spec_id;
    S32 num_apps;
    U16 app_ids[CCA_MAX_APPS];
} mmi_cca_source_ui_new_setting_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    S32 trans_id;
    U16 sim_id;
    cca_status_enum response;
} mmi_cca_source_ui_new_setting_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    S32 trans_id;
    U16 spec_id;
    S32 max_attempts;
    cca_status_enum status;
} mmi_cca_source_ui_auth_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    S32 trans_id;
    S8 pin[CCA_MAX_PIN_CHARS+1];
    cca_status_enum status;
} mmi_cca_source_ui_auth_rsp_struct;


typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to retrieve: CCA_PROF_CURRENT or >=0 values */
} mmi_cca_get_prof_ind_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to retrieve: CCA_PROF_CURRENT or >=0 values */
	S32 hConfig;
	cca_status_enum result;     /* {CCA_STATUS_OK, CCA_STATUS_FAIL, CCA_STATUS_MEMFULL} */
} mmi_cca_get_prof_rsp_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to retrieve: CCA_PROF_CURRENT or >=0 values */
} mmi_cca_app_get_prof_ind_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to retrieve: CCA_PROF_CURRENT or >=0 values */
	S32 hConfig;
	cca_status_enum result;     /* {CCA_STATUS_OK, CCA_STATUS_FAIL, CCA_STATUS_MEMFULL} */
} mmi_cca_app_get_prof_rsp_struct;


typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to update: CCA_PROF_CURRENT or >=0 values */
	S32 hConfig;
} mmi_cca_update_prof_ind_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to update: CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;
	cca_status_enum result;
} mmi_cca_update_prof_rsp_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to update: CCA_PROF_CURRENT or >=0 values */
	S32 hConfig;
} mmi_cca_app_update_prof_ind_struct;

typedef struct {
	LOCAL_PARA_HDR
    U16 sim_id;
	U16 app_id;     /* {CCA_APP_DTACCT, CCA_APP_BROWSER, CCA_APP_MMS...} */
	S32 prof_id;    /* profile ID to update: CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;
	cca_status_enum result;     /* {CCA_STATUS_OK, CCA_STATUS_FAIL, CCA_STATUS_MEMFULL} */
} mmi_cca_app_update_prof_rsp_struct;



typedef struct cca_core_data_struct cca_core_data_struct;
typedef struct cca_core_data_struct {
    S32 size;
    union
    {
        S32 *i;
        S8 **s;
    } values;
    U16 id;
    cca_data_type_enum type;    /* CCA_DT_INT (0), CCA_DT_STR (1) */
} cca_core_data_struct;

typedef struct cca_doc_node_datalist_struct cca_doc_node_datalist_struct;
typedef struct cca_doc_node_datalist_struct {
    cca_doc_node_datalist_struct *next;
    cca_core_data_struct data;
} cca_doc_node_datalist_struct;

typedef struct cca_doc_node_struct cca_doc_node_struct;
typedef struct cca_doc_node_struct {
    cca_doc_node_struct *next;
    cca_doc_node_struct *parent;
    cca_doc_node_struct *child;

    S32 num_data;
    S32 num_child;
    cca_doc_node_datalist_struct *listchain;
    U16 node_id;
    //char mask;	/* 0=will be traversed, 1=skipped during traversal */
} cca_doc_node_struct;

typedef struct cca_doc_nodelist_struct cca_doc_nodelist_struct;
typedef struct cca_doc_nodelist_struct {
	cca_doc_nodelist_struct *next;
	cca_doc_node_struct *node;
} cca_doc_nodelist_struct;

typedef struct cca_doc_iter_nodes_struct cca_doc_iter_nodes_struct;
typedef struct cca_doc_iter_nodes_struct {
    cca_doc_iter_nodes_struct *next;

    cca_doc_nodelist_struct *nodes;
    S32 num_nodes;
    U16 node_id;
} cca_doc_iter_nodes_struct;


typedef struct cca_document_struct cca_document_struct;
typedef struct cca_document_struct {
    cca_doc_node_struct *doc_tree;	/* include dependency setting as a child node within Root */

    cca_doc_iter_nodes_struct *iter_nodes_list;

    U16 config_id;
    U8 dtAcctIDAdded;

    /* size of list in each level = number of nodes in that level (span across all parent nodes) */
    //cca_nodelist_struct* nodelist_by_level[CCA_TREE_MAX_LEVELS];

    /* size of array = number of symbols of a specific configuration type, index=symbol ID & CCA_NS_CLEARNS */
    //cca_nodelist_t** nodelist_by_symbol;

    /* size of array = number of added nodes, code should traverse through all elements in list to find a matching symbol */
    //cca_map_symbol_nodelist_struct *nodelist_by_symbol;

} cca_document_struct;



typedef struct cca_node_stats_struct cca_node_stats_struct;
typedef struct cca_node_stats_struct {
    S32 num_child;
    S32 *child_ids;
    S32 *num_child_instances;
    S32 num_parent;
    S32 *parent_ids;
} cca_node_stats_struct;

typedef struct cca_generic_ptr_struct cca_generic_ptr_struct;
typedef struct cca_generic_ptr_struct {
	cca_generic_ptr_struct *next;
	cca_generic_ptr_struct *parent;
	cca_generic_ptr_struct *child;
} cca_generic_ptr_struct;

typedef struct cca_iterator_struct cca_iterator_struct;
typedef struct cca_iterator_struct {
	cca_generic_ptr_struct *current;
	cca_generic_ptr_struct *head_node;
	cca_generic_ptr_struct *prev_node;
	cca_traverse_type_enum traverse_type;
	cca_iter_type_enum iter_type;
	U8 deep_delete; /* 0: false, 1: true */
    S8 crt_level;

	// detach handler
	// release handler
} cca_iterator_struct;


typedef struct {
    U16 ref_by_node_symbols[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_node_symbols_count;

    S32 ref_by_node_handles[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_node_handles_count;

    S8 *ref_by_appids[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_appids_count;
} cca_ref_by_struct;



typedef cca_status_enum(*CCA_FP_PARAM_PROC) (S32 hConfig,
                                             U16 param_symbol,
                                             cca_core_data_struct *data,
                                             void *user_data);

typedef cca_status_enum(*CCA_FP_NODE_PROC) (S32 hConfig,
                                            S32 hNode,
                                            U16 node_symbol,
                                            cca_iterator_struct *iter_datalist,
                                            void *user_data);

typedef cca_status_enum(*CCA_FP_APP_CHECK) (U16 config_id,
                                            S32 hConfig,
                                            cca_iterator_struct *iter_datalist);

typedef void(*CCA_FP_MEMFULL_CB) (U8 identifier);


typedef struct {
    U16 config_id;
    CCA_FP_APP_CHECK fpAppCheckDoc;
    const S8 **appids;
    S32 num_appids;
    const U16 *l1node_symbols;
    S32 num_l1node_symbols;
} cca_app_config_struct;

typedef struct {
    U16 config_id;
    cca_status_enum result;
} cca_app_config_result_struct;

typedef struct {
    cca_state_enum state;
    U16 sim_id;
    
    /* provisioning context */
    U16 specId;
    S32 hConfig;
    S32 crtConfigIndex;
    cca_app_config_result_struct configResult[CCA_MAX_APPS];
    S32 numApp;

    /* async context */
    module_type src_mod_id;
    U16 appId;
    S32 profId;
    S32 asynchConfig;
    cca_oper_enum oper;

} cca_context_struct;


/* global variables */
extern const cca_app_config_struct cca_app_config_g[];
extern cca_context_struct cca_context_g;


#endif  /* MMI_CCADEFS_H */
