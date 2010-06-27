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
 *  CentralConfigAgentProt.h
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
#ifndef MMI_CCAPROT_H
#define MMI_CCAPROT_H

#include "MMIDataType.h"


void* mmi_cca_malloc(U32 size);
void mmi_cca_mfree(void *ptr);
#define mmi_cca_malloc_type(x) (x*)mmi_cca_malloc((U32)sizeof(x))

void mmi_cca_log_enable(U8 enable);
U8 mmi_cca_log_is_enabled(void);

typedef U8(*CCA_FP_LIST_ELEM_EQUAL)(void* elem,
                                    void* user_data);

void mmi_cca_trigger_memfull_notify(void);
U8 mmi_cca_oma_is_memfull_during_app_configure (void);

void mmi_cca_doc_link_list_elem_to_last(cca_generic_ptr_struct **start, cca_generic_ptr_struct *elem);

cca_doc_node_datalist_struct* mmi_cca_doc_datalist_new(U16 param_id, cca_data_type_enum data_type);
cca_doc_node_datalist_struct* mmi_cca_doc_datalist_find_ptr(cca_doc_node_datalist_struct *datalist, U16 param_id);
U8 mmi_cca_doc_datalist_has_param_value(cca_doc_node_datalist_struct *datalist, U16 param_id, cca_data_type_enum datatype, void *value);
void mmi_cca_doc_datalist_attach_to_node(cca_doc_node_struct* node, cca_doc_node_datalist_struct* datalist);
cca_doc_node_datalist_struct* mmi_cca_doc_detach_datalist(cca_doc_node_struct *node, U16 param_id);
cca_status_enum mmi_cca_doc_coredata_extend(cca_core_data_struct *data_obj, U32 num_extend);
cca_status_enum mmi_cca_doc_coredata_append(cca_core_data_struct *data_obj, S32 size, void *values);
U8 mmi_cca_doc_coredata_values_exists_int(S32 *values_i, S32 size, S32 val);
U8 mmi_cca_doc_coredata_values_exists_str(S8 **values_s, S32 size, S8 *str);

void mmi_cca_doc_coredata_reset(cca_core_data_struct* coredata);
void mmi_cca_doc_coredata_release_values(cca_core_data_struct *coredata);
void mmi_cca_doc_datalist_release(cca_doc_node_datalist_struct *datalist, U8 deep_delete);
void mmi_cca_doc_node_release(cca_doc_node_struct *node, U8 deep_delete);
void mmi_cca_doc_nodelist_release(cca_doc_nodelist_struct *nodelist, U8 deep_delete);
void mmi_cca_doc_iter_nodes_list_release(cca_doc_iter_nodes_struct *iter_nodes_list, U8 releaseLevel);
void mmi_cca_doc_release(S32 hConfig);

cca_iterator_struct* mmi_cca_iterator_new(cca_traverse_type_enum trType, cca_iter_type_enum itType, cca_generic_ptr_struct* begin, U8 dpDel);
void mmi_cca_iterator_fill(cca_iterator_struct *iter, cca_traverse_type_enum trType, cca_iter_type_enum itType, cca_generic_ptr_struct* begin, U8 dpDel);
void mmi_cca_iterator_next_preorder_node(cca_iterator_struct* iter);

cca_doc_iter_nodes_struct* mmi_cca_doc_iter_nodes_new(U16 node_id);
cca_doc_iter_nodes_struct* mmi_cca_doc_construct_iter_nodes_list(cca_doc_node_struct *root);
cca_doc_nodelist_struct* mmi_cca_doc_nodelist_new(cca_doc_node_struct *node);

cca_doc_node_struct* mmi_cca_doc_parse_mapping_table(const U16 *table, const S32 size);

S32 mmi_cca_doc_find_node_match_param_value(S32 hStartNode, U16 node_symbol, U16 param, cca_data_type_enum datatype, void *value);
void* mmi_cca_doc_list_find(cca_generic_ptr_struct *list, CCA_FP_LIST_ELEM_EQUAL fpEqual, void *user_data);
U8 mmi_cca_doc_equal_node_id(void* elem, void* user_data);
U8 mmi_cca_doc_equal_param_id(void* elem, void* user_data);

cca_doc_node_struct *mmi_cca_doc_match(cca_doc_node_struct *root, U16 *path, S8 size);

cca_status_enum mmi_cca_oma_get_deprel_childs(S32 hConfig, cca_doc_node_struct **nodeDepRelBegin);
void mmi_cca_oma_mark_depset(cca_doc_node_struct *nodeDepRelBegin, S8 *refIdToMark);
cca_status_enum mmi_cca_oma_is_depset(S32 hConfig, cca_doc_node_struct *l1node);
cca_status_enum mmi_cca_oma_check_in_app_context(S32 hConfig, cca_doc_node_struct *l1node);
cca_status_enum mmi_cca_oma_doc_contains_appid(S32 hConfig, const S8 **appids, const S32 numAppIds);
void mmi_cca_oma_handle_new_doc(S32 hConfig);
void mmi_cca_oma_new_doc_continue(void);
cca_status_enum mmi_cca_oma_retrieve_all_appids(S32 hConfig, cca_doc_node_datalist_struct *datalist_res);
cca_status_enum mmi_cca_oma_retrieve_nodeids(S32 hConfig, cca_doc_node_datalist_struct *datalist_res);
cca_iterator_struct* mmi_cca_oma_construct_appcheck_datalist(S32 hConfig);
void mmi_cca_oma_construct_l1symbols(S32 hConfig, S32 max_symbols, S32 *num_symbols, U16 *l1symbols, S32 *l1symbols_count);
U8 mmi_cca_oma_is_appid_exist(S8 *appidToFind, const S8 **appids, const S32 numAppIds);
U8 mmi_cca_oma_is_node_symbol_exist(U16 symbolToFind, const U16 *l1node_symbols, const S32 num_l1node_symbols);
cca_status_enum mmi_cca_oma_find_proxy_ref_by(S32 hConfig, cca_doc_node_struct *l1node, cca_ref_by_struct *ref_by);
cca_status_enum mmi_cca_oma_mark_in_app_context(S32 hConfig);
U8 mmi_cca_oma_is_in_app_context(cca_doc_node_struct *l1node);
void mmi_cca_oma_new_doc_process_next_app(void);
cca_status_enum mmi_cca_oma_add_dataacctid_to_ref_nodes(S32 hConfig);


void mmi_cca_configure_complete(void);

void mmi_cca_reset_context(void);

int mmi_cca_new_config_result(U16 config_id, cca_status_enum result);
cca_status_enum mmi_cca_get_config_result(U16 config_id);
U8 mmi_cca_update_config_result(U16 config_id, cca_status_enum result);

void mmi_cca_app_configure_ind_hdlr(void *msg);
void mmi_cca_app_configure_rsp_hdlr(void *msg);
void mmi_cca_source_new_doc_ind_hdlr(void *msg);
void mmi_cca_source_ui_invalid_setting_ind_hdlr(void *msg);
void mmi_cca_source_ui_new_setting_ind_hdlr(void *msg);
void mmi_cca_source_ui_new_setting_rsp_hdlr(void *msg);
void mmi_cca_source_ui_auth_ind_hdlr(void *msg);
void mmi_cca_new_doc_continue_ind_hdlr(void *msg);
void mmi_cca_get_prof_ind_hdlr(void *local_param, int mod_id, void *ilm);
void mmi_cca_update_prof_ind_hdlr(void *local_param, int mod_id, void *ilm);
void mmi_cca_app_get_prof_rsp_hdlr(void *msg);
void mmi_cca_app_update_prof_rsp_hdlr(void *msg);
void mmi_cca_app_get_prof_ind_hdlr(void *msg);
void mmi_cca_app_update_prof_ind_hdlr(void *msg);

module_type mmi_cca_get_module_id_by_app(U16 app_id);
module_type mmi_cca_get_module_id_by_config(U16 config_id);
MMI_ID_TYPE mmi_cca_get_app_names(U16 config_id);

void mmi_cca_send_app_configure_ind(U16 sim_id, U16 config_id, S32 hConfig);
void mmi_cca_send_new_doc_continue_ind(void);
void mmi_cca_send_source_new_doc_rsp(void);
void mmi_cca_send_source_ui_new_setting_rsp(S32 trans_id, U16 sim_id, cca_status_enum response);
void mmi_cca_send_source_ui_auth_rsp(S32 trans_id, S8 *pin, cca_status_enum status);
void mmi_cca_send_cca_get_prof_rsp(module_type dest_mod_id, U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result);
void mmi_cca_send_cca_app_get_prof_ind(U16 sim_id, U16 app_id, S32 prof_id);
void mmi_cca_send_cca_update_prof_rsp(module_type dest_mod_id, U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result);
void mmi_cca_send_cca_app_update_prof_ind(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig);
void mmi_cca_send_cca_app_get_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result);
void mmi_cca_send_cca_app_update_prof_rsp(U16 sim_id,U16 app_id, S32 prof_id, S32 hConfig, cca_status_enum result);

void mmi_cca_dispatch_mmi_cca_app_configure_ind(mmi_cca_app_configure_ind_struct *newConfigDoc);
void mmi_cca_dispatch_mmi_profile_operations(cca_oper_enum oper, U16 app_id, void *local_parm);

void mmi_cca_ui_entry_progressing(void);
void mmi_cca_ui_entry_settings_info(void);
void mmi_cca_ui_entry_summary_report(void);
void mmi_cca_ui_entry_idle_screen(void);
//void mmi_cca_ui_handle_endkey(void);
void mmi_cca_ui_handle_memfull(void);
void mmi_cca_ui_show_abort(void (*abort_cb)(void));
void mmi_cca_ui_handle_abort_rsk(void);
void mmi_cca_ui_show_popup(U16 strid, U16 imgid);
void mmi_cca_ui_handle_settings_info_rsk(void);
void mmi_cca_ui_handle_settings_info_abort(void);
void mmi_cca_ui_handle_settings_info_lsk(void);
U8 mmi_cca_ui_handle_settings_info_historydel(void *in_param);
void mmi_cca_ui_show_settings_info_screen(void);
void mmi_cca_ui_show_summary_report_screen(void);
void mmi_cca_ui_handle_summary_report_lsk(void);
U8 mmi_cca_ui_handle_summary_report_historydel(void *in_param);
void mmi_cca_ui_entry_new_setting_conf_screen(void);
void mmi_cca_ui_handle_new_setting_conf_lsk(void);
void mmi_cca_ui_handle_new_setting_conf_rsk(void);
void mmi_cca_ui_handle_new_setting_conf_abort(void);
void mmi_cca_ui_exit_new_setting_conf_screen(void);
void mmi_cca_ui_entry_auth_screen(void);
void mmi_cca_ui_exit_auth_screen(void);
void mmi_cca_ui_handle_auth_lsk(void);
void mmi_cca_ui_handle_auth_rsk(void);
void mmi_cca_ui_handle_auth_abort(void);
U8 mmi_cca_ui_handle_auth_historydel(void *in_param);


void mmi_cca_send_cca_app_configure_rsp(U16 sim_id, U16 conf_id, S32 doc_hdl, cca_status_enum status);

U16 mmi_cca_revise_sim_id(U16 sim_id);



void mmi_cca_log(S8 *format, ...);

#define MMI_CCA_LOG(x) mmi_cca_log x
#ifndef __MTK_TARGET__
#define MMI_CCA_LOG_DOC(hConfig) mmi_cca_log_print_doc((cca_generic_ptr_struct*)(((cca_document_struct*)(hConfig))->doc_tree))
#else
#define MMI_CCA_LOG_DOC(hConfig)
#endif

#ifndef __MTK_TARGET__
void mmi_cca_log_print_doc(cca_generic_ptr_struct* root);
void mmi_cca_log_print_coredata(cca_core_data_struct *coredata);
void mmi_cca_log_print_node(cca_doc_node_struct *node);
void mmi_cca_log_print_iter_nodelist(cca_iterator_struct *iter_nodelist);
void mmi_cca_log_print_iter_datalist(cca_iterator_struct *iter_datalist);
#endif  /* __MTK_TARGET__ */

#endif  /* MMI_CCAPROT_H */
