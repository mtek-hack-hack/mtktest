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
 *	csmcc_atfunc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for exporting function declaration used by L4C module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _CSMCC_ATFUNC_H
#define _CSMCC_ATFUNC_H

typedef struct l4c_call_entry_struct
{
   kal_uint8 src_id;
   kal_uint8 call_id;
   kal_uint8 call_orig;
   kal_uint8 call_state;
   kal_uint8 call_mode;
   kal_uint8 call_type;
   kal_uint8 mpty;
   l4_addr_bcd_struct number;
   kal_uint8 priority;
} l4c_call_entry_struct;

extern kal_bool l4ccsm_cc_get_call_info (
                       kal_uint8 call_id,
                       l4c_call_entry_struct *call_info,
                       kal_uint8 *next_call_id);
                       
extern kal_bool l4ccsm_cc_get_acm(
                       kal_uint32 *acm,
                       kal_uint32 *acmmax);
                       
extern kal_bool l4ccsm_cc_get_ccm(
                       kal_uint8 call_id,
                       kal_uint32 *ccm);

extern kal_bool 
l4ccsm_cc_get_data_rate(kal_uint32 *rate);

extern kal_bool 
l4ccsm_cc_get_data_call_info(kal_uint8 *data_call_type);

#ifdef __TCPIP__
#include "custom_nvram_editor_data_item.h"
extern kal_bool 
l4ccsm_cc_get_csd_prof(kal_uint8 csd_prof_id, nvram_ef_csd_profile_struct *csd_prof_ptr);
extern kal_bool 
l4ccsm_cc_get_empty_csd_prof(kal_uint8 *empty_csd_prof_entry);
extern kal_bool 
l4ccsm_cc_get_csd_prof_id(kal_uint8 *csd_prof_id);
#endif

extern kal_bool l4ccsm_cc_get_mt_call(
                       kal_uint8 *call_id);

extern kal_bool l4ccsm_cc_get_in_call(
                       kal_uint8 *call_id);
                                              
extern kal_bool  l4ccsm_cc_get_outgoing_call(kal_uint8 *call_id);
                                              
extern kal_bool l4ccsm_cc_get_active_call(
                       kal_uint8 *call_id);
                      
extern kal_bool l4ccsm_cc_set_addr_type(
                       kal_uint8 addr_type);
                       
extern kal_bool l4ccsm_cc_get_addr_type(
                       kal_uint8 *addr_type);
                       
extern kal_bool l4ccsm_cc_test_addr_type(kal_uint8 const **supp_ptr);
                       
extern kal_bool l4ccsm_cc_set_call_mode (
                       kal_uint8 call_mode);
                       
extern kal_bool l4ccsm_cc_get_call_mode(
                       kal_uint8 *call_mode);
                       
extern kal_bool l4ccsm_cc_test_call_mode(kal_uint8 const **supp_ptr);
                       
extern kal_bool csmcc_check_cbst_para_supported(
                                   kal_uint8 bearer_speed,
                                   kal_uint8 bearer_name,
                                   kal_uint8 bearer_ce,
                                   kal_bool need_check_fax);

extern kal_bool l4ccsm_cc_set_bearer_service_type (
                       kal_uint8 bearer_speed,
                       kal_uint8 bearer_name,
                       kal_uint8 bearer_ce);

#if 0 /*mtk01602, 070606*/
#ifdef __SATCE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /*mtk01602, 070606*/
extern kal_bool l4ccsm_cc_get_bearer_service_type (
                       kal_uint8 *bearer_speed,
                       kal_uint8 *bearer_name,
                       kal_uint8 *bearer_ce);

extern kal_bool l4ccsm_cc_test_bearer_service_type(kal_uint8 const **supp_ptr);
                       
extern kal_bool l4ccsm_cc_set_sns_mode (
                       kal_uint8 sns_mode);
                       
extern kal_bool l4ccsm_cc_get_sns_mode (
                       kal_uint8 *sns_mode);
                       
extern kal_bool l4ccsm_cc_test_sns_mode(kal_uint8 const **supp_ptr);
                       
extern kal_bool l4ccsm_cc_set_char_framing (
                       kal_uint8 cf_format,
                       kal_uint8 cf_parity);

extern kal_bool l4ccsm_cc_get_char_framing (
                       kal_uint8 *cf_format,
                       kal_uint8 *cf_parity);

extern kal_bool l4ccsm_cc_test_char_framing(kal_uint8 const **supp_ptr);
                      
extern kal_bool l4ccsm_cc_set_v120_param (
                      kal_uint8 v120_rah,
                      kal_uint8 v120_mfm,
                      kal_uint8 v120_mode,
                      kal_uint8 v120_llineg,
                      kal_uint8 v120_assign,
                      kal_uint8 v120_negtype);
                      
extern kal_bool l4ccsm_cc_get_v120_param (
                      kal_uint8 *v120_rah,
                      kal_uint8 *v120_mfm,
                      kal_uint8 *v120_mode,
                      kal_uint8 *v120_llineg,
                      kal_uint8 *v120_assign,
                      kal_uint8 *v120_negtype);                      
                      
extern kal_bool l4ccsm_cc_test_v120_param(kal_uint8 const **supp_ptr);
                     
extern kal_bool l4ccsm_cc_set_rlp_param (
                      kal_uint8 rlp_iws,
                      kal_uint8 rlp_mws,
                      kal_uint8 rlp_T1,
                      kal_uint8 rlp_N2,
                      kal_uint8 rlp_ver,
                      kal_uint8 rlp_T4);

extern kal_bool l4ccsm_cc_get_rlp_param (
                      kal_uint8 *rlp_iws,
                      kal_uint8 *rlp_mws,
                      kal_uint16 *rlp_T1,
                      kal_uint8 *rlp_N2,
                      kal_uint8 *rlp_ver,
                      kal_uint8 *rlp_T4);
                      
extern kal_bool l4ccsm_cc_test_rlp_param(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_set_data_compression_param (
                      kal_uint8 dir,
                      kal_uint8 negotiation,
                      kal_uint16 max_dict,
                      kal_uint8 max_string);
                      
extern kal_bool l4ccsm_cc_get_data_compression_mode(
                      kal_uint8 *dir,
                      kal_uint8 *negotiation,
                      kal_uint16 *max_dict,
                      kal_uint8 *max_string);

extern kal_bool l4ccsm_cc_test_data_compression_param(kal_uint8 const **supp_ptr);
                      
extern kal_bool l4ccsm_cc_test_aoc_mode(kal_uint8 const **supp_ptr);
                      
extern kal_bool l4ccsm_cc_set_cug_param (
                      kal_uint8 cug_temporary_mode,
                      kal_uint8 cug_index,
                      kal_uint8 cug_suppress);
                      
extern kal_bool l4ccsm_cc_get_cug_param (
                      kal_uint8 *cug_temporary_mode,
                      kal_uint8 *cug_index,
                      kal_uint8 *cug_suppress);
                      
extern kal_bool l4ccsm_cc_test_cug_param(kal_uint8 const **supp_ptr);
                      
extern kal_bool l4ccsm_cc_test_clip_mode(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_test_clir_mode(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_test_colp_mode(kal_uint8 const **supp_ptr);
                      
extern kal_bool l4ccsm_cc_set_fclass_mode(
                      kal_uint8 fclass_mode);

extern kal_bool l4ccsm_cc_get_fclass_mode(
                      kal_uint8 *fclass_mode);
                      
extern kal_bool l4ccsm_cc_test_fclass_mode(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_test_chld_mode(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_test_vts_mode(kal_uint8 const **supp_ptr);

extern kal_bool l4ccsm_cc_test_cpas_mode(kal_uint8 const **supp_ptr);

extern kal_uint8 csmcc_get_line_id(void);

extern kal_bool l4ccsm_cc_set_ctm_status(kal_uint8 ctm_status);

extern kal_bool l4ccsm_cc_set_iwf(kal_uint8 iwf);

extern kal_bool l4ccsm_cc_get_iwf(kal_uint8 * iwf);
                      
#endif /* _CSMCC_EXT_FUNC_H */


