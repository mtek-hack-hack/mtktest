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
 *  CentralConfigAgentGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
 *
 *  This is the one and only file to be included for accessing CCA APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_CCAGPROT_H
#define MMI_CCAGRPOT_H

#ifndef _QUEUE_GPROT_H
#include "QueueGProt.h"
#endif

#ifndef MMI_CCACONST_H
#include "CentralConfigAgentConst.h"
#endif

#ifndef MMI_CCARESDEF_H
#include "CentralConfigAgentResDef.h"
#endif

#ifndef MMI_CCASYMBOLS_H
#include "CentralConfigAgentSymbols.h"
#endif

#ifndef MMI_CCADEFS_H
#include "CentralConfigAgentDefs.h"
#endif

#ifndef MMI_CCAPROT_H
#include "CentralConfigAgentProt.h"
#endif



cca_status_enum mmi_cca_doc_process(S32 hConfig, const U16 *mapping_table, const S32 size, CCA_FP_PARAM_PROC param_callback, CCA_FP_NODE_PROC node_callback, void *user_data);

cca_status_enum mmi_cca_doc_nodedata_next(cca_iterator_struct *iter_datalist, cca_core_data_struct **data_obj);



void mmi_cca_init(void);
void mmi_cca_reset(void);



/* DOCUMENT MANIPULATION APIs */
S32 mmi_cca_doc_new(S32 hRootNode);
void mmi_cca_docroot_release(S32 hRoot);
void mmi_cca_doc_node_release_all(S32 hNode);

S32 mmi_cca_doc_new_rootnode(void);
S32 mmi_cca_doc_new_node(U16 node_symbol);
S32 mmi_doc_duplicate_node(S32 node);
S32 mmi_cca_doc_new_node_and_attach(U16 node_symbol, S32 hParentNode);
cca_status_enum mmi_cca_doc_attach_node_to_parent(S32 hNode, S32 hParentNode);
cca_status_enum mmi_cca_doc_add_node_to_parent(S32 hNode, S32 hParentNode);
void mmi_cca_doc_node_detach(S32 hNode);

S32 mmi_cca_oma_generate_virtual_proxy_node(const char *tonapid, const char *vrpxy_cca_node_id, char **out_new_pxy_id);
S32 mmi_cca_oma_fix_doc(S32 hRoot);
S32 mmi_cca_oma_generate_deprel_node(S32 hRoot);
void mmi_cca_oma_sort_new_doc(S32 hRoot);

cca_status_enum mmi_cca_doc_add_nodedata_int(S32 hNode, U16 param_id, const S32 value);
cca_status_enum mmi_cca_doc_add_nodedata_str(S32 hNode, U16 param_id, const S8 *value);
cca_status_enum mmi_cca_doc_add_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values);
cca_status_enum mmi_cca_doc_add_nodedata_strs(S32 hNode, U16 param_id, S32 size, const S8 **values);

cca_status_enum mmi_cca_doc_get_nodes(S32 hConfig, U16 node_symbol, cca_iterator_struct **iter_nodelist, S32 *size);
cca_status_enum mmi_cca_doc_get_nodedata(cca_iterator_struct *iter_nodelist, cca_iterator_struct **iter_datalist, S32 *size);

cca_status_enum mmi_cca_doc_get_nodedata_by_param(cca_iterator_struct *iter, U16 param_id, cca_core_data_struct **data_obj);
cca_status_enum mmi_cca_doc_get_nodedata_int_first(cca_iterator_struct *iter, U16 param_id, S32 *value);
cca_status_enum mmi_cca_doc_get_nodedata_str_first(cca_iterator_struct *iter, U16 param_id, S8 **value);
cca_status_enum mmi_cca_doc_get_nodedata_ints(cca_iterator_struct *iter, U16 param_id, S32 **values, S32 *size);
cca_status_enum mmi_cca_doc_get_nodedata_strs(cca_iterator_struct *iter, U16 param_id, S8 ***values, S32 *size);

cca_status_enum mmi_cca_doc_nodedata_by_param(S32 hNode, U16 param_id, cca_core_data_struct **data_obj);
cca_status_enum mmi_cca_doc_nodedata_int_first(S32 hNode, U16 param_id, S32 *value);
cca_status_enum mmi_cca_doc_nodedata_str_first(S32 hNode, U16 param_id, S8 **value);
cca_status_enum mmi_cca_doc_nodedata_ints(S32 hNode, U16 param_id, S32 **values, S32 *size);
cca_status_enum mmi_cca_doc_nodedata_strs(S32 hNode, U16 param_id, S8 ***values, S32 *size);

cca_status_enum mmi_cca_doc_update_coredata_int(cca_core_data_struct *data_obj, const S32 value);
cca_status_enum mmi_cca_doc_update_coredata_str(cca_core_data_struct *data_obj, const S8 *value);
cca_status_enum mmi_cca_doc_update_coredata_ints(cca_core_data_struct *data_obj, S32 size, const S32 *values);
cca_status_enum mmi_cca_doc_update_coredata_strs(cca_core_data_struct *data_obj, S32 size, const S8 **values);

cca_status_enum mmi_cca_doc_update_nodedata_int(S32 hNode, U16 param_id, const S32 value);
cca_status_enum mmi_cca_doc_update_nodedata_str(S32 hNode, U16 param_id, const S8 *value);
cca_status_enum mmi_cca_doc_update_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values);
cca_status_enum mmi_cca_doc_update_nodedata_strs(S32 hNode, U16 param_id, S32 size, const S8 **values);

U8 mmi_cca_doc_coredata_remove_value(cca_core_data_struct *coredata, cca_data_type_enum type, void *value);
cca_status_enum mmi_cca_doc_remove_nodedata(S32 hNode, U16 param_id);

U8 mmi_cca_doc_node_has_param_value(S32 hNode, U16 param, cca_data_type_enum datatype, void *value);
U8 mmi_cca_doc_coredata_exists_int(cca_core_data_struct *coredata, S32 val);
U8 mmi_cca_doc_coredata_exists_str(cca_core_data_struct *coredata, S8 *str);
U8 mmi_cca_doc_coredata_is_equal(cca_core_data_struct *cd1, cca_core_data_struct *cd2);
U8 mmi_cca_doc_node_check_equal_content(S32 hNode1, S32 hNode2);

//cca_status_enum mmi_cca_doc_get_node_stats(cca_iterator_struct *iter_nodelist, cca_flag_enum stats_flag, cca_node_stats_struct **node_stat_obj);
//void mmi_cca_doc_nodestats_release(cca_node_stats_struct *stats_obj);

/* UTILITY APIs */
void mmi_cca_ui_common_cancel(U16 text_str_id, void (*cancel_cb)(void));
U8 mmi_cca_is_ascii_string(const S8 *str);
void mmi_cca_register_memfull_notify(CCA_FP_MEMFULL_CB callback, U8 identifier);
void mmi_cca_deregister_memfull_notify(U8 identifier);


/* ITERATOR APIs */
void* mmi_cca_iterator_next(cca_iterator_struct *iter);
void mmi_cca_iterator_release(cca_iterator_struct *iter);
void mmi_cca_iterator_restart(cca_iterator_struct *iter);

/* DEPENDENCY RELATIONSHIP APIs */
cca_status_enum mmi_cca_oma_add_deprel(S32 hRoot, U16 dep_id, S8 *node_id, S8 *ref_id, S32 hSrcNode);
cca_status_enum mmi_cca_oma_add_dataacctid(S32 hConfig, S8 *nap_node_id, S32 dataacctid);


/* UI related functions */
U8 mmi_cca_idle_check(void);

void mmi_cca_allow_popup(U8 allowed); /* FALSE: disable, TURE: enable */


#endif  /* MMI_CCAGPROT_H */


