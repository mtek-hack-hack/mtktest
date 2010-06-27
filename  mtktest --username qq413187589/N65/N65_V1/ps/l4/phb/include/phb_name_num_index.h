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
 * phb_name_num_index.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the name-num index. Data stucture of the index is defined, as well as functions
 *   for its basic operations.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_NAME_NUM_INDEX_H
#define _PHB_NAME_NUM_INDEX_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef _PHB_DATA_ENTRY_TABLE_H
#error "phb_data_entry_table.h should be included"
#endif 
#ifndef _PHB_PINDEX_H
#error "phb_pindex.h should be included"
#endif 

#ifndef __MMI_FMI__
#define __PHB_SORT_ENABLE__
#endif 

    typedef struct
    {
        data_entry_table_type data_entry_table;
        pindex_type name_index;
        pindex_type num_index;
    } name_num_index_type;

/**
 * The comparison result is specified as follows:
 * `distance' is greater than, equal to, or less than 0, according to `first' is 
 * greater than, equal to, or less than `second'. Besides, the absolute value of
 * `distance' shows the distance between `first' and `second'.
 *
 * `same_count' specifies how many consecutive characters are equal between
 * `first' and `second'.
 */
    typedef struct
    {
        kal_int32 distance;
        kal_uint8 same_count;
    } compare_result_type;

    typedef struct
    {
        kal_uint8 signature;
        kal_uint8 tel_num;
    } num_sig_type;

    typedef void (*compare_func_type) (void *external_data, void *first, void *second, compare_result_type *result);

    extern kal_uint16 phb_name_num_index_get_size(kal_uint16 slots);
    extern void phb_name_num_index_new(name_num_index_type *name_num_index, kal_uint16 slots);
    extern void phb_name_num_index_reset(name_num_index_type *name_num_index);
    extern kal_uint16 phb_name_num_index_append(
                        name_num_index_type *name_num_index,
                        alpha_id_type *alpha_id,
                        phb_storage_enum storage,
                        kal_uint16 record_index,
                        kal_uint8 signature,
                        kal_uint8 tel_num,
                        kal_uint8 ext_index);
    extern kal_uint16 phb_name_num_index_update(
                        name_num_index_type *name_num_index,
                        kal_uint16 old_index,
                        alpha_id_type *alpha_id,
                        kal_uint8 signature,
                        kal_uint8 tel_num,
                        kal_uint8 ext_index,
                        kal_uint8 *old_ext_index);
    extern data_entry_struct *phb_name_num_index_get_data_entry(
                                name_num_index_type *name_num_index,
                                kal_uint16 position);
    extern kal_bool phb_name_num_index_delete(
                        name_num_index_type *name_num_index,
                        kal_uint16 index,
                        kal_uint8 *ext_index);
    extern kal_uint16 phb_name_num_index_find_index_by_alpha_id(
                        name_num_index_type *name_num_index,
                        alpha_id_type *alpha_id);
    /* MTK 2003-12-30 Wilson, For Exactly Match after PinYin Search */
    extern kal_uint16 phb_name_num_index_after_find_index_by_alpha_id(
                        name_num_index_type *name_num_index,
                        alpha_id_type *alpha_id,
                        kal_uint16 candidate);
    /* END MTK */
    extern kal_uint16 phb_name_num_index_find_index_by_alpha_id_storage(
                        name_num_index_type *name_num_index,
                        alpha_id_type *alpha_id,
                        phb_storage_enum storage);
    extern kal_uint16 phb_name_num_index_find_index_by_num_sig(
                        name_num_index_type *name_num_index,
                        kal_uint8 signature,
                        kal_uint8 tel_num);
    extern kal_uint16 phb_name_num_index_find_index_by_num_sig_exact_match(
                        name_num_index_type *name_num_index,
                        kal_uint8 signature,
                        kal_uint8 tel_num,
                        kal_uint16 position);
    extern void phb_name_num_index_sort(name_num_index_type *name_num_index);
    extern void phb_compare_by_key_alpha_id(
                    alpha_id_type *first,
                    alpha_id_type *second,
                    compare_result_type *result);
    extern void phb_compare_by_alpha_id(
                    data_entry_table_type *external_data,
                    alpha_id_type *first,
                    pindex_struct *second_pos,
                    compare_result_type *result);

    /* MTK 2003-12-30 Wilson, For Exactly Match after PinYin Search */
    extern void phb_compare_by_key_alpha_id_by_encoding(
                    alpha_id_type *first,
                    alpha_id_type *second,
                    compare_result_type *result);
    extern kal_bool phb_compare_by_alpha_id_by_encoding(
                        data_entry_table_type *external_data,
                        alpha_id_type *first,
                        pindex_struct *second_pos,
                        compare_result_type *result);
    /* END MTK */
    extern void phb_compare_by_alpha_id_for_sort(
                    data_entry_table_type *external_data,
                    pindex_struct *first_pos,
                    pindex_struct *second_pos,
                    compare_result_type *result);
    extern void phb_compare_by_tel_num_sig_for_sort(
                    data_entry_table_type *external_data,
                    pindex_struct *first_pos,
                    pindex_struct *second_pos,
                    compare_result_type *result);
#ifdef __cplusplus
}
#endif 

#endif /* _PHB_NAME_NUM_INDEX_H */ 

