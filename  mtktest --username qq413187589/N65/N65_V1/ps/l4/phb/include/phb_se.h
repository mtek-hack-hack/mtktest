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
 * phb_se.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the Search Engine.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_SE_H
#define _PHB_SE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef _L4C2PHB_ENUMS_H
#error "l4c2phb_enums.h should be included"
#endif 
#ifndef _PHB_NAME_NUM_INDEX_H
#error "phb_name_num_index.h should be included"
#endif 
#ifndef _PHB_PINDEX_H
#error "phb_pindex.h should be included"
#endif 
#ifndef _PHB_CONTROL_BLOCK_H
#error "phb_control_block.h should be included"
#endif 

    extern char const *const countrycode[];

    extern void phb_se_new(void);
    extern void phb_se_reset(void);
    extern void phb_se_build_index(
                    phb_type_enum type,
                    kal_uint16 record_index,
                    kal_uint8 ext_index,
                    phb_entry_struct *phb_entry);
    extern void phb_se_finish_build(void);
    extern kal_uint16 phb_se_append(
                        phb_type_enum type,
                        kal_uint16 record_index,
                        kal_uint8 ext_index,
                        phb_entry_struct *phb_entry);
    extern kal_uint16 phb_se_update(
                        phb_type_enum type,
                        kal_uint8 ext_index,
                        phb_entry_struct *phb_entry,
                        kal_uint16 old_index,
                        kal_uint8 *old_ext_index);
    extern void phb_se_delete(phb_type_enum type, kal_uint16 old_index, kal_uint8 *ext_index);
    extern kal_uint16 phb_se_search_by_record_index_name(
                        phb_type_enum type,
                        phb_storage_enum storage,
                        kal_uint16 record_index,
                        alpha_id_type *alpha_id);
    extern name_num_index_type *phb_se_search_by_name(
                                    phb_type_enum type,
                                    alpha_id_type *alpha_id,
                                    kal_uint16 *first_candidate_index,
                                    kal_bool *is_more_candidate);
    extern name_num_index_type *phb_se_compare_tel_number_with_first_character(
                            phb_type_enum type,
                            l4_addr_bcd_struct *tel_num,
                            kal_uint16 *first_candidate_index,
                            kal_bool *is_more_candidate);
    extern name_num_index_type *phb_se_search_by_tel_num(
                                    phb_type_enum type,
                                    l4_addr_bcd_struct *tel_num,
                                    kal_uint16 *first_candidate_index,
                                    kal_bool *is_more_candidate);
    extern kal_bool phb_se_is_next_also_candidate(
                        name_num_index_type *name_num_index,
                        kal_uint16 candidate_index,
                        kal_bool is_byname);
    extern kal_bool phb_se_is_in_range(phb_type_enum type, kal_uint16 index, kal_uint16 *total);
    extern kal_uint16 phb_se_get_total_of_type(phb_type_enum type);
    extern kal_uint8 phb_se_get_differntiable_digits(kal_uint8 *bcd_array, kal_uint16 *cc_index);
    extern kal_uint8 se_get_last_valid_digit(kal_uint8 *bcd_array, kal_uint8 length);
    extern kal_bool phb_se_set_control_block(
                        control_block_type *control_block,
                        op_enum op,
                        phb_storage_enum storage,
                        kal_uint16 record_index);

#ifdef __PHB_SORT_ENABLE__
    extern kal_uint16 phb_se_get_index_by_storage(phb_storage_enum storage);
#endif 

    extern void phb_se_ext_index_set(kal_uint16 record_index, kal_uint8 ext_index, phb_type_enum phb_type);
    extern void phb_se_ext_index_delete(kal_uint16 record_index, phb_type_enum phb_type);
    extern kal_uint8 phb_se_ext_index_find(kal_uint16 record_index, phb_type_enum phb_type);

    extern kal_uint8 phb_se_get_ext_index(phb_type_enum type, phb_entry_struct *entry);

    extern kal_uint16 phb_se_get_index_by_record_index(
                        phb_type_enum type,
                        phb_storage_enum storage,
                        kal_uint16 record_index);

#ifdef __PHB_USIM_SUPPORT__
    extern void phb_se_iap_index_delete(kal_uint16 adn_index, phb_type_enum data_type);
    extern kal_uint16 phb_se_iap_index_find(kal_uint16 adn_index, data_desc_enum data_type);
    extern void phb_se_iap_index_set(kal_uint16 adn_index, kal_uint8 data_index, data_desc_enum data_type);
#endif 

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_SE_H */ 

