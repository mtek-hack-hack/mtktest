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
 * phb_name_num_index.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is name-num index. Data stucture of name-num index is defined, as well as functions
 *   for its basic operations.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_utils.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_NAME_NUM_INDEX_C_

/**
 * This type is used when comparing alpha_id and storage. 
 * Since the generic binary search used only searches for single key, 
 * these two fields cannot but combine together.
 */
typedef struct
{
    alpha_id_type *alpha_id;
    phb_storage_enum storage;
} alpha_id_storage_type;

static void phb_compare_by_alpha_id_storage(
                data_entry_table_type *external_data,
                alpha_id_storage_type *first,
                pindex_struct *second_pos,
                compare_result_type *result);
static void phb_compare_by_tel_num_sig(
                data_entry_table_type *external_data,
                num_sig_type *first,
                pindex_struct *second_pos,
                compare_result_type *result);
static void phb_compare_by_alpha_id_storage_for_sort(
                data_entry_table_type *external_data,
                pindex_struct *first_pos,
                pindex_struct *second_pos,
                compare_result_type *result);
static kal_uint16 phb_binary_search(
                    pindex_struct *a,
                    data_entry_table_type *external_data,
                    kal_uint16 length,
                    int low,
                    int high,
                    void *key,
                    compare_func_type compare);

static void phb_fast_quicksort(
                pindex_struct *a,
                data_entry_table_type *external_data,
                kal_uint16 l,
                kal_uint16 r,
                compare_func_type compare);


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_get_size
 * DESCRIPTION
 *  Returns size of memory occupied by the name-num index.
 * PARAMETERS
 *  slots       [IN]        Total slots of table
 * RETURNS
 *  Size of memory
 *****************************************************************************/
kal_uint16 phb_name_num_index_get_size(kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_GET_SIZE);

    return phb_det_get_size(slots) + phb_pindex_get_size(slots) + phb_pindex_get_size(slots);
}


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_new
 * DESCRIPTION
 *  Constructor of name_num_index.
 * PARAMETERS
 *  name_num_index      [IN]        The allocated memory for the new pindex
 *  slots               [IN]        Total slots of table
 * RETURNS
 *  void
 *****************************************************************************/
void phb_name_num_index_new(name_num_index_type *name_num_index, kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_NEW); */

    ASSERT(name_num_index != NULL);

    phb_det_new(&name_num_index->data_entry_table, slots);
    phb_pindex_new(&name_num_index->name_index, slots);

    if (name_num_index->num_index.table == NULL)
    {
        phb_pindex_new(&name_num_index->num_index, 0);
    }
    else
    {
        phb_pindex_new(&name_num_index->num_index, slots);
    }
}   /* end of phb_name_num_index_new */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_reset
 * DESCRIPTION
 *  Reset data-entry-table.
 * PARAMETERS
 *  name_num_index      [?]         
 *  det(?)              [IN]        The data-entry-table to reset
 * RETURNS
 *  void
 *****************************************************************************/
void phb_name_num_index_reset(name_num_index_type *name_num_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_RESET); */

    ASSERT(name_num_index != NULL);

    phb_det_reset(&name_num_index->data_entry_table);
    phb_pindex_reset(&name_num_index->name_index);
    phb_pindex_reset(&name_num_index->num_index);
}   /* end of phb_det_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_append
 * DESCRIPTION
 *  Append to name_num_index.
 * PARAMETERS
 *  name_num_index      [IN]        The name_num_index
 *  alpha_id            [?]         
 *  storage             [IN]        
 *  record_index        [IN]        
 *  signature           [IN]        
 *  tel_num             [IN]        
 *  ext_index           [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_uint16 phb_name_num_index_append(
            name_num_index_type *name_num_index,
            alpha_id_type *alpha_id,
            phb_storage_enum storage,
            kal_uint16 record_index,
            kal_uint8 signature,
            kal_uint8 tel_num,
            kal_uint8 ext_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 data_entry_pos;
    kal_uint16 index, pos_in_pindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_APPEND);

    ASSERT(name_num_index != NULL);

    data_entry_pos = phb_det_append(
                        &name_num_index->data_entry_table,
                        alpha_id,
                        storage,
                        record_index,
                        signature,
                        tel_num,
                        ext_index);
    if (data_entry_pos == (kal_uint16) PHB_INVALID_VALUE)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    index =
        pos_in_pindex = (name_num_index->name_index.used_count == 0) ?
        0 : (kal_uint16) phb_name_num_index_find_index_by_alpha_id_storage(name_num_index, alpha_id, storage);
    if (phb_pindex_insert(&name_num_index->name_index, pos_in_pindex, data_entry_pos) == (kal_uint16) PHB_INVALID_VALUE)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    if (name_num_index->num_index.slots > 0)
    {
        pos_in_pindex = (name_num_index->num_index.used_count == 0) ?
            0 : (kal_uint16) phb_name_num_index_find_index_by_num_sig(name_num_index, signature, tel_num);
        if (phb_pindex_insert(&name_num_index->num_index, pos_in_pindex, data_entry_pos) ==
            (kal_uint16) PHB_INVALID_VALUE)
        {
            return (kal_uint16) PHB_INVALID_VALUE;
        }
    }

    return index;
}   /* end of phb_pindex_append */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_update
 * DESCRIPTION
 *  Update.
 * PARAMETERS
 *  name_num_index      [IN]        The name_num_index
 *  old_index           [IN]        
 *  alpha_id            [?]         
 *  signature           [IN]        
 *  tel_num             [IN]        
 *  ext_index           [IN]        
 *  old_ext_index       [?]         
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_uint16 phb_name_num_index_update(
            name_num_index_type *name_num_index,
            kal_uint16 old_index,
            alpha_id_type *alpha_id,
            kal_uint8 signature,
            kal_uint8 tel_num,
            kal_uint8 ext_index,
            kal_uint8 *old_ext_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 data_entry_pos;
    data_entry_struct *data_entry;
    kal_uint16 old_num_index, new_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_UPDATE);

    ASSERT(name_num_index != NULL);

    data_entry_pos = name_num_index->name_index.table[old_index].position;
    data_entry = &name_num_index->data_entry_table.table[data_entry_pos];

    if (name_num_index->num_index.slots > 0)
    {
        old_num_index = phb_name_num_index_find_index_by_num_sig_exact_match(
                            name_num_index,
                            data_entry->tel_num_sig,
                            data_entry->tel_num,
                            data_entry_pos);
        new_index = phb_name_num_index_find_index_by_num_sig(name_num_index, signature, tel_num);
        if (new_index == name_num_index->num_index.used_count || new_index > old_num_index)     /* should exclude the old one */
        {
            --new_index;
        }
        if ((new_index = phb_pindex_update(
                            &name_num_index->num_index,
                            old_num_index,
                            new_index,
                            data_entry_pos)) == (kal_uint16) PHB_INVALID_VALUE)
        {
            return (kal_uint16) PHB_INVALID_VALUE;
        }
    }

    new_index = phb_name_num_index_find_index_by_alpha_id_storage(name_num_index, alpha_id, data_entry->storage);

    if (new_index == name_num_index->name_index.used_count)
    {
        --new_index;
    }
    else if (new_index > old_index)
    {
        new_index--;
    }

    if ((new_index = phb_pindex_update(
                        &name_num_index->name_index,
                        old_index,
                        new_index,
                        data_entry_pos)) == (kal_uint16) PHB_INVALID_VALUE)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    data_entry_pos = name_num_index->name_index.table[new_index].position;
    *old_ext_index = name_num_index->data_entry_table.table[data_entry_pos].ext_index;
    phb_det_set(
        &name_num_index->data_entry_table,
        data_entry_pos,
        alpha_id,
        data_entry->storage,
        data_entry->record_index,
        signature,
        tel_num,
        ext_index);
    return new_index;
}   /* end of phb_name_num_index_update */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_get_data_entry
 * DESCRIPTION
 *  Returns the data-entry of the name_num_inex at `position'
 * PARAMETERS
 *  name_num_index      [IN]        The name_num_index
 *  position            [IN]        
 * RETURNS
 *  the data-entry
 *****************************************************************************/
data_entry_struct *phb_name_num_index_get_data_entry(name_num_index_type *name_num_index, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_GET_DATA_ENTRY);

    ASSERT(name_num_index != NULL);

    return &name_num_index->data_entry_table.table[position];
}


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_delete
 * DESCRIPTION
 *  Delete `index'th element of data-entry-table in name_num_index.
 *  The name_index and num_index are also re-ogranized.
 * PARAMETERS
 *  name_num_index      [IN]        The name_num_index
 *  index               [IN]        
 *  ext_index           [?]         
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_bool phb_name_num_index_delete(name_num_index_type *name_num_index, kal_uint16 index, kal_uint8 *ext_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 old_index, old_data_entry_pos;
    data_entry_struct *old_data_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_DELETE);

    ASSERT(name_num_index != NULL);

    old_data_entry_pos = name_num_index->name_index.table[index].position;
    old_data_entry = &name_num_index->data_entry_table.table[old_data_entry_pos];
    old_index = phb_name_num_index_find_index_by_num_sig_exact_match(
                    name_num_index,
                    old_data_entry->tel_num_sig,
                    old_data_entry->tel_num,
                    old_data_entry_pos);
    if (name_num_index->num_index.slots > 0)
    {
        phb_pindex_delete(&name_num_index->num_index, old_index);
    }

    phb_pindex_delete(&name_num_index->name_index, index);
    *ext_index = old_data_entry->ext_index;
    phb_det_delete(&name_num_index->data_entry_table, old_data_entry_pos);

   /** 
    * Since certain entry is deleted from data_entry_table, 
    * `position''s stored in pindex are not synchronous.
    * Reorganize is needed. *Sigh*
    */
    if (name_num_index->num_index.slots > 0)
    {
        phb_pindex_relink(&name_num_index->num_index, old_data_entry_pos);
    }

    phb_pindex_relink(&name_num_index->name_index, old_data_entry_pos);

    return KAL_TRUE;
}   /* end of phb_pindex_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_find_index_by_alpha_id
 * DESCRIPTION
 *  Search the index of name_num_index->name_index by alpha_id
 * PARAMETERS
 *  name_num_index      [?]     
 *  alpha_id            [?]     
 * RETURNS
 *  index to name_num_index->name_index
 *****************************************************************************/
kal_uint16 phb_name_num_index_find_index_by_alpha_id(name_num_index_type *name_num_index, alpha_id_type *alpha_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 candidate;
    compare_result_type result, result1;    /* Wilson 2004-02-18 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_ALPHA_ID);

    ASSERT(name_num_index != NULL);

    if (name_num_index->name_index.used_count == 0)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    candidate = phb_binary_search(
                    name_num_index->name_index.table,
                    &name_num_index->data_entry_table,
                    name_num_index->name_index.used_count,
                    0,
                    (kal_uint16) (name_num_index->name_index.used_count - 1),
                    alpha_id,
                    (compare_func_type) phb_compare_by_alpha_id);

    if (candidate < name_num_index->name_index.used_count)
    {
        phb_compare_by_alpha_id(
            &name_num_index->data_entry_table,
            alpha_id,
            &name_num_index->name_index.table[candidate],
            &result);

        /* MTK Wilson 2004-02-18, Compare with next record to see if more match */
        phb_compare_by_alpha_id(
            &name_num_index->data_entry_table,
            alpha_id,
            &name_num_index->name_index.table[candidate + 1],
            &result1);
        /* if (result.distance > 0) */
        if (result.distance > 0 || result1.same_count > result.same_count)      /* Wilson 2004-05-16 */
        {
            return candidate + 1;
        }
        /* END MTK */
    }
    return candidate;
}   /* end of phb_name_num_index_find_index_by_alpha_id */

/* MTK 2003-12-30 Wilson, For Exactly Match after PinYin Search */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_after_find_index_by_alpha_id
 * DESCRIPTION
 *  Use encoding to compare if two UCS2 string with the same PinYin spelling.
 * PARAMETERS
 *  name_num_index      [?]         
 *  alpha_id            [?]         
 *  candidate           [IN]        
 * RETURNS
 *  index to name_num_index->name_index
 *****************************************************************************/
kal_uint16 phb_name_num_index_after_find_index_by_alpha_id(
            name_num_index_type *name_num_index,
            alpha_id_type *alpha_id,
            kal_uint16 candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    compare_result_type result, new_result, char_result, new_char_result;
    kal_int16 new_candidate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(name_num_index != NULL);

    /* Count the same count and distance of the original candidate in PinYin string and Encoding String. */
    if (candidate < name_num_index->name_index.used_count)
    {
        phb_compare_by_alpha_id(
            &name_num_index->data_entry_table,
            alpha_id,
            &name_num_index->name_index.table[candidate],
            &result);

        if (!phb_compare_by_alpha_id_by_encoding(
                &name_num_index->data_entry_table,
                alpha_id,
                &name_num_index->name_index.table[candidate],
                &char_result))
        {
            char_result.same_count = 0; /* Not a UCS2 encoding */
        }
    }

    /* Compare new candidate, if same count is larger or distance is smaller, replace with original candidate. */
    new_candidate = candidate + 1;
    while (new_candidate < name_num_index->name_index.used_count)
    {
        if (phb_compare_by_alpha_id_by_encoding(
                &name_num_index->data_entry_table,
                alpha_id,
                &name_num_index->name_index.table[new_candidate],
                &new_char_result))
        {
            phb_compare_by_alpha_id(
                &name_num_index->data_entry_table,
                alpha_id,
                &name_num_index->name_index.table[new_candidate],
                &new_result);

            if (new_result.same_count != result.same_count)
            {
                break;
            }

            if (new_char_result.same_count > char_result.same_count)
            {
                candidate = new_candidate;
                char_result.same_count = new_char_result.same_count;
                char_result.distance = new_char_result.distance;
            }
            /*
             * else if ((new_char_result.same_count == char_result.same_count) &&
             * (abs(new_char_result.distance) < abs(char_result.distance))) 
             * {
             * candidate = new_candidate;
             * char_result.distance = new_char_result.distance;
             * }
             */
        }

        new_candidate++;
    }

    return candidate;
}   /* end of phb_name_num_index_find_index_by_alpha_id */

/* END MTK 2003-12-30 Wilson */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_find_index_by_alpha_id_storage
 * DESCRIPTION
 *  Search the index of name_num_index->name_index by alpha_id and storage
 * PARAMETERS
 *  name_num_index      [?]         
 *  alpha_id            [?]         
 *  storage             [IN]        
 * RETURNS
 *  index to name_num_index->name_index
 *****************************************************************************/
kal_uint16 phb_name_num_index_find_index_by_alpha_id_storage(
            name_num_index_type *name_num_index,
            alpha_id_type *alpha_id,
            phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alpha_id_storage_type alpha_id_storage;
    kal_uint16 candidate;
    compare_result_type result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_ALPHA_ID_STORAGE);

    ASSERT(name_num_index != NULL);

    alpha_id_storage.alpha_id = alpha_id;
    alpha_id_storage.storage = storage;

    if (name_num_index->name_index.used_count == 0)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    candidate = phb_binary_search(
                    name_num_index->name_index.table,
                    &name_num_index->data_entry_table,
                    name_num_index->name_index.used_count,
                    0,
                    (kal_uint16) (name_num_index->name_index.used_count - 1),
                    &alpha_id_storage,
                    (compare_func_type) phb_compare_by_alpha_id_storage);

    if (candidate < name_num_index->name_index.used_count)
    {
        phb_compare_by_alpha_id_storage(
            &name_num_index->data_entry_table,
            &alpha_id_storage,
            &name_num_index->name_index.table[candidate],
            &result);
        if (result.distance > 0)
        {
            return candidate + 1;
        }
    }
    return candidate;
}   /* end of phb_name_num_index_find_index_by_alpha_id_storage */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_find_index_by_num_sig
 * DESCRIPTION
 *  Search the index of first occurence of telephone number in
 *  name_num_index->num_index.
 * PARAMETERS
 *  name_num_index      [?]         
 *  signature           [IN]        
 *  tel_num             [IN]        
 * RETURNS
 *  index to name_num_index->num_index
 *****************************************************************************/
kal_uint16 phb_name_num_index_find_index_by_num_sig(
            name_num_index_type *name_num_index,
            kal_uint8 signature,
            kal_uint8 tel_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 candidate;
    compare_result_type result;
    num_sig_type num_sig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_NUM_SIG);

    ASSERT(name_num_index != NULL);

    if (name_num_index->num_index.used_count == 0)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    num_sig.signature = signature;
    num_sig.tel_num = tel_num;

    candidate = phb_binary_search(
                    name_num_index->num_index.table,
                    &name_num_index->data_entry_table,
                    name_num_index->num_index.used_count,
                    0,
                    (kal_uint16) (name_num_index->num_index.used_count - 1),
                    &num_sig,
                    (compare_func_type) phb_compare_by_tel_num_sig);

    if (candidate < name_num_index->num_index.used_count)
    {
        phb_compare_by_tel_num_sig(
            &name_num_index->data_entry_table,
            &num_sig,
            &name_num_index->num_index.table[candidate],
            &result);
        if (result.distance > 0)
        {
            return candidate + 1;
        }
    }
    return candidate;
}   /* end of name_num_index_find_index_by_num */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_find_index_by_num_sig_exact_match
 * DESCRIPTION
 *  Search the index of exact matching of telephone number and `position' stored in
 *  name_num_index->num_index.
 * PARAMETERS
 *  name_num_index      [?]         
 *  signature           [IN]        
 *  tel_num             [IN]        
 *  position            [IN]        
 * RETURNS
 *  index to name_num_index->num_index
 *****************************************************************************/
kal_uint16 phb_name_num_index_find_index_by_num_sig_exact_match(
            name_num_index_type *name_num_index,
            kal_uint8 signature,
            kal_uint8 tel_num,
            kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 index;

    data_entry_table_type *det;
    pindex_type *name_index;
    pindex_type *num_index;
    num_sig_type num_sig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_NUM_SIG_EXACT_MATCH);

    ASSERT(name_num_index != NULL);

    if (name_num_index->name_index.used_count == 0)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    det = &name_num_index->data_entry_table;
    name_index = &name_num_index->name_index;
    num_index = &name_num_index->num_index;

    num_sig.signature = signature;
    num_sig.tel_num = tel_num;

    index = phb_binary_search(
                num_index->table,
                det,
                num_index->used_count,
                0,
                (kal_uint16) (num_index->used_count - 1),
                &num_sig,
                (compare_func_type) phb_compare_by_tel_num_sig);
    for (i = index; (i < num_index->used_count) &&
         (det->table[num_index->table[i].position].tel_num ==
          det->table[num_index->table[index].position].tel_num); ++i)
    {
        if (num_index->table[i].position == position)
        {
            break;
        }
    }
    return i;
}   /* end of phb_name_num_index_find_index_by_num_sig_exact_match */


/*****************************************************************************
 * FUNCTION
 *  phb_name_num_index_sort
 * DESCRIPTION
 *  Use phb_fast_quicksort to sort internal indices.
 * PARAMETERS
 *  name_num_index      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_name_num_index_sort(name_num_index_type *name_num_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_entry_table_type *det;
    pindex_type *name_index;
    pindex_type *num_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NAME_NUM_INDEX_SORT);

    ASSERT(name_num_index != NULL);

    if (name_num_index->name_index.used_count == 0)
    {
        return;
    }

    det = &name_num_index->data_entry_table;
    name_index = &name_num_index->name_index;
    num_index = &name_num_index->num_index;

    phb_fast_quicksort(
        name_index->table,
        det,
        0,
        (kal_uint16) (name_index->used_count - 1),
        (compare_func_type) phb_compare_by_alpha_id_storage_for_sort);

    if (num_index->slots > 0)
    {
        phb_fast_quicksort(
            num_index->table,
            det,
            0,
            (kal_uint16) (num_index->used_count - 1),
            (compare_func_type) phb_compare_by_tel_num_sig_for_sort);
    }
}   /* end of phb_name_num_index_sort */


/*****************************************************************************
 * FUNCTION
 *  phb_istring_icmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  istr_first      [?]     
 *  istr_second     [?]     
 *  result          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_istring_icmp(istring_type *istr_first, istring_type *istr_second, compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 len1, len2;
    kal_uint8 min_len, max_len;

    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_ISTRING_ICMP);

    result->same_count = 0;
    result->distance = 0;

    ASSERT((istr_first != NULL) && (istr_second != NULL));

    len1 = istring_len(istr_first);
    len2 = istring_len(istr_second);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; ++i)
    {
        kal_uint16 char1, char2;

        /* All characters are identical from 0 to min_len. */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                result->distance = istring_char_at(istr_first, i);
            }
            /* First and second is congruence */
            else if (len1 == len2)
            {
                result->distance = 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                result->distance = -istring_char_at(istr_second, i);
            }

         /** 
          * Special case:
          * Since empty alpha id is desired to be sorted more ascending, 
          * As long as length of either istr_frist or istr_second is 0, 
          * one of which length is 0 have to be treated as greater!!
          * Such that it will be sorted as more ascending.
          */
            if (min_len == 0)
            {
                result->distance = -result->distance;
            }

            break;
        }

        /* First, compare from 0 to min_len */
        else
        {
            char1 = istring_char_at(istr_first, i);
            char2 = istring_char_at(istr_second, i);

         /**
          * Now compare char1 and char2.
          * For a UCS2 character that falls in BASIC LATIN collection(0020 - 007E, 
          * see http://www.evertype.com/standards/iso10646/ucs-collections.html),
          * it should be treated as equal to that in ASCII charset.
          * => This is no problem because get_char convert an ASCII character to an UCS2
          *    character.
          */
            if ((result->distance = compare_chars(char1, char2)) == 0)
            {
                result->same_count++;
            }
            /* First and second is not equal, return distance */
            else
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_key_alpha_id
 * DESCRIPTION
 *  Compare two alpha_id's. Their length could be unequal when comparing.
 *  For ASCII charset, character comparison is case insensitive.
 * PARAMETERS
 *  first                   [?]         
 *  second                  [?]         
 *  result                  [?]         
 *  external_data(?)        [IN]        External data
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
void phb_compare_by_key_alpha_id(alpha_id_type *first, alpha_id_type *second, compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    istring_type istr_first, istr_second;

    /* MTK 2003-12-30 Wilson, For PinYin Search. */
    kal_uint8 temp1[PHB_ALPHA_ID_DEPTH], temp2[PHB_ALPHA_ID_DEPTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_KEY_ALPHA_ID);

    /* MTK 2003-12-30 Wilson, For PinYin Search */
    if ((first->charset == PHB_UCS2) && (find_pinyin_str_for_ucs2_with_tone(first->data, temp1)))
    {
        istr_first.data = temp1;
        istr_first.length = strlen((char*)istr_first.data);
        istr_first.charset = PHB_ASCII;
    }
    else
    {
        istr_first.length = first->length;
        istr_first.charset = first->charset;
        istr_first.data = first->data;
    }

    //MTK 2003-12-30 Wilson, For PinYin Search
    //Use for encoding match
    if ((second->charset == PHB_UCS2 && first->charset == PHB_UCS2) &&
        (find_pinyin_str_for_ucs2_with_tone(second->data, temp2)))
    {
        istr_second.data = temp2;
        istr_second.length = strlen((char*)istr_second.data);
        istr_second.charset = PHB_ASCII;
    }
    /* Use for PinYin Match */
    else if ((second->charset == PHB_UCS2 && first->charset == PHB_ASCII) &&
             (find_pinyin_str_for_ucs2_without_tone(second->data, temp2)))
    {
        istr_second.data = temp2;
        istr_second.length = strlen((char*)istr_second.data);
        istr_second.charset = PHB_ASCII;
    }
    else
    {
        istr_second.length = second->length;
        istr_second.charset = second->charset;
        istr_second.data = second->data;
    }

    phb_istring_icmp(&istr_first, &istr_second, result);
}   /* end of phb_compare_by_alpha_id */
#else /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_key_alpha_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  first       [?]     
 *  second      [?]     
 *  result      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_compare_by_key_alpha_id(alpha_id_type *first, alpha_id_type *second, compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    istring_type istr_first, istr_second;
    kal_uint16 code;
    kal_uint8 *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_KEY_ALPHA_ID);

    istr_first.length = first->length;
    istr_first.charset = first->charset;
    istr_first.data = first->data;

    code = *((kal_uint16*) second->data);
    if ((second->charset == PHB_UCS2)
        && (code >= 0x4e00 && code <= 0x9fa5) && ((temp = (kal_uint8*) find_pinying_str_for_ucs2(code)) != NULL))
    {
        istr_second.data = temp;
        istr_second.length = strlen((char*)istr_second.data);
        istr_second.charset = PHB_ASCII;
    }
    else
    {
        istr_second.length = second->length;
        istr_second.charset = second->charset;
        istr_second.data = second->data;
    }

    phb_istring_icmp(&istr_first, &istr_second, result);
}   /* end of phb_compare_by_alpha_id */
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id
 * DESCRIPTION
 *  Compare two alpha_id's. Their length could be unequal when comparing.
 *  For ASCII charset, character comparison is case insensitive.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first               [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  second(?)
 * RETURNS
 *  void
 *****************************************************************************/
void phb_compare_by_alpha_id(
        data_entry_table_type *external_data,
        alpha_id_type *first,
        pindex_struct *second_pos,
        compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_ALPHA_ID);

    phb_compare_by_key_alpha_id(first, &external_data->table[second_pos->position].alpha_id, result);
}   /* end of phb_compare_by_alpha_id */

/* MTK 2003-12-30 Wilson, For Exactly Match after PinYin Search */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_key_alpha_id_by_encoding
 * DESCRIPTION
 *  Compare two UCS2 string using their encoding only.
 * PARAMETERS
 *  first       [?]     
 *  second      [?]     
 *  result      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_compare_by_key_alpha_id_by_encoding(
        alpha_id_type *first,
        alpha_id_type *second,
        compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    istring_type istr_first, istr_second;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    istr_first.length = first->length;
    istr_first.charset = first->charset;
    istr_first.data = first->data;

    istr_second.length = second->length;
    istr_second.charset = second->charset;
    istr_second.data = second->data;

    phb_istring_icmp(&istr_first, &istr_second, result);
}   /* end of phb_compare_by_alpha_id */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id_by_encoding
 * DESCRIPTION
 *  Compare two UCS2 string using their encoding only.
 * PARAMETERS
 *  external_data       [?]     
 *  first               [?]     
 *  second_pos          [?]     
 *  result              [?]     
 * RETURNS
 *  True if input string is UCS2
 *****************************************************************************/
kal_bool phb_compare_by_alpha_id_by_encoding(
            data_entry_table_type *external_data,
            alpha_id_type *first,
            pindex_struct *second_pos,
            compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (external_data->table[second_pos->position].alpha_id.charset == PHB_UCS2)
    {
        phb_compare_by_key_alpha_id_by_encoding(first, &external_data->table[second_pos->position].alpha_id, result);
    }
    else
    {
        return 0;
    }

    return 1;

}   /* end of phb_compare_by_alpha_id */

/* END MTK 2003-12-30 */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id_storage
 * DESCRIPTION
 *  Compare two alpha_id and storage's.
 *  Inequality definition: SIM is larger than NVRAM.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first               [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  second(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_compare_by_alpha_id_storage(
                data_entry_table_type *external_data,
                alpha_id_storage_type *first,
                pindex_struct *second_pos,
                compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_ALPHA_ID_STORAGE);

    phb_compare_by_alpha_id(external_data, first->alpha_id, second_pos, result);

    /* MTK 2004-04-19 Wilson, Put ASCII string in front of UCS2 string.(For PinYin Search) */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    if (result->distance == 0)
    {
        /* If Original String is ASCII, appears before UCS2. For PinYin conversion only. */
        if (first->alpha_id->charset != external_data->table[second_pos->position].alpha_id.charset)
        {
            if (first->alpha_id->charset == PHB_UCS2)
            {
                result->distance = 1;
            }
            else
            {
                result->distance = -1;
            }
        }
    }
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

    /* Only when 2 alpha_id's are identical should their storage's are required to compare */
    if (result->distance == 0)
    {
        if (first->storage != external_data->table[second_pos->position].storage)
        {
         /**
          * Define SIM is lexicongraphically larger than NVRAM.
          * Hence, if 2 alpha id's are identical, NVRAM appears in front
          * of SIM
          */
            if (first->storage == PHB_SIM)
            {
                result->distance = 1;
            }
            else
            {
                result->distance = -1;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_tel_num_sig
 * DESCRIPTION
 *  Compare two 2-digits telephone numbers. If they are equal, compare
 *  signature.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first               [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  second(?)
 * RETURNS
 *  result->distance is greater than, equal to, or less than 0, according to(?)
 *  first is greater than, equal to, or less than second.(?)
 *****************************************************************************/
static void phb_compare_by_tel_num_sig(
                data_entry_table_type *external_data,
                num_sig_type *first,
                pindex_struct *second_pos,
                compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_TEL_NUM_SIG);

    result->same_count = 0;
    result->distance = 0;

    if (first->tel_num > external_data->table[second_pos->position].tel_num)
    {
        result->distance = 1;
    }
    else if (first->tel_num < external_data->table[second_pos->position].tel_num)
    {
        result->distance = -1;
    }

    /* (first->tel_num == 
       external_data->table[second_pos->position].tel_num) */
    else
    {
        if (first->signature > external_data->table[second_pos->position].tel_num_sig)
        {
            result->distance = 1;
        }
        else if (first->signature < external_data->table[second_pos->position].tel_num_sig)
        {
            result->distance = -1;
        }

        /* (first->signature == external_data->table[second_pos->position].tel_num_sig) */
        else
        {
            result->distance = 0;
        }
    }
}   /* end of phb_compare_by_tel_num_sig */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id_for_sort
 * DESCRIPTION
 *  Compare two alpha_id's. Their length could be unequal when comparing.
 *  For ASCII charset, character comparison is case insensitive.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first_pos           [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  first(?)
 *  second(?)
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
void phb_compare_by_alpha_id_for_sort(
        data_entry_table_type *external_data,
        pindex_struct *first_pos,
        pindex_struct *second_pos,
        compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    istring_type istr_first, istr_second;

    /* MTK 2003-12-30 Wilson, For PinYin Sort. */
    kal_uint8 temp1[PHB_ALPHA_ID_DEPTH], temp2[PHB_ALPHA_ID_DEPTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_ALPHA_ID_FOR_SORT);

    /* if charset == PHB_UCS2,  && first byte range is Chinese, go lookup table 
       for subsititue string for compare */
    /* MTK 2003-12-30 Wilson, For PinYin Sort. */
    if ((external_data->table[first_pos->position].alpha_id.charset == PHB_UCS2) &&
        (find_pinyin_str_for_ucs2_with_tone(external_data->table[first_pos->position].alpha_id.data, temp1)))
    {
        istr_first.data = temp1;
        istr_first.length = strlen((char*)istr_first.data);
        istr_first.charset = PHB_ASCII;
    }
    else
    {
        istr_first.length = external_data->table[first_pos->position].alpha_id.length;
        istr_first.charset = external_data->table[first_pos->position].alpha_id.charset;
        istr_first.data = external_data->table[first_pos->position].alpha_id.data;
    }

    /* MTK 2003-12-30 Wilson, For PinYin Sort. */
    if ((external_data->table[second_pos->position].alpha_id.charset == PHB_UCS2) &&
        (find_pinyin_str_for_ucs2_with_tone(external_data->table[second_pos->position].alpha_id.data, temp2)))
    {
        istr_second.data = temp2;
        istr_second.length = strlen((char*)istr_second.data);
        istr_second.charset = PHB_ASCII;
    }
    else
    {
        istr_second.length = external_data->table[second_pos->position].alpha_id.length;
        istr_second.charset = external_data->table[second_pos->position].alpha_id.charset;
        istr_second.data = external_data->table[second_pos->position].alpha_id.data;
    }

    phb_istring_icmp(&istr_first, &istr_second, result);
}   /* end of phb_compare_by_alpha_id */
#else /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id_for_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  external_data       [?]     
 *  first_pos           [?]     
 *  second_pos          [?]     
 *  result              [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_compare_by_alpha_id_for_sort(
        data_entry_table_type *external_data,
        pindex_struct *first_pos,
        pindex_struct *second_pos,
        compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    istring_type istr_first, istr_second;
    kal_uint16 code;
    kal_uint8 *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_ALPHA_ID_FOR_SORT);

    /* if charset == PHB_UCS2,  && first byte range is Chinese, go lookup table 
       for subsititue string for compare */
    code = *((kal_uint16*) external_data->table[first_pos->position].alpha_id.data);
    if ((external_data->table[first_pos->position].alpha_id.charset == PHB_UCS2)
        && (code >= 0x4e00 && code <= 0x9fa5) && ((temp = (kal_uint8*) find_pinying_str_for_ucs2(code)) != NULL))
    {
        istr_first.data = temp;
        istr_first.length = strlen((char*)istr_first.data);
        istr_first.charset = PHB_ASCII;
    }
    else
    {
        istr_first.length = external_data->table[first_pos->position].alpha_id.length;
        istr_first.charset = external_data->table[first_pos->position].alpha_id.charset;
        istr_first.data = external_data->table[first_pos->position].alpha_id.data;
    }

    code = *((kal_uint16*) external_data->table[second_pos->position].alpha_id.data);
    if ((external_data->table[second_pos->position].alpha_id.charset == PHB_UCS2)
        && (code >= 0x4e00 && code <= 0x9fa5) && ((temp = (kal_uint8*) find_pinying_str_for_ucs2(code)) != NULL))
    {
        istr_second.data = temp;
        istr_second.length = strlen((char*)istr_second.data);
        istr_second.charset = PHB_ASCII;
    }
    else
    {
        istr_second.length = external_data->table[second_pos->position].alpha_id.length;
        istr_second.charset = external_data->table[second_pos->position].alpha_id.charset;
        istr_second.data = external_data->table[second_pos->position].alpha_id.data;
    }

    phb_istring_icmp(&istr_first, &istr_second, result);
}   /* end of phb_compare_by_alpha_id */
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_alpha_id_storage_for_sort
 * DESCRIPTION
 *  Compare two alpha_id and storage's.
 *  Inequality definition: SIM is larger than NVRAM.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first_pos           [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  first(?)
 *  second(?)
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)    /* MTK 2004-04-19 Wilson */
extern alpha_id_type alpha_id_pinyin_PHB[];
#endif 

static void phb_compare_by_alpha_id_storage_for_sort(
                data_entry_table_type *external_data,
                pindex_struct *first_pos,
                pindex_struct *second_pos,
                compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_ALPHA_ID_STORAGE_FOR_SORT);

    phb_compare_by_alpha_id_for_sort(external_data, first_pos, second_pos, result);

    /* MTK 2004-04-19 Wilson, Put ASCII string in front of UCS2 string.(For PinYin Search) */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    if (result->distance == 0)
    {
        /* If Original String is ASCII, appears before UCS2. For PinYin conversion only. */
        if (alpha_id_pinyin_PHB[first_pos->position].charset != alpha_id_pinyin_PHB[second_pos->position].charset)
        {
            if (alpha_id_pinyin_PHB[first_pos->position].charset == PHB_UCS2)
            {
                result->distance = 1;
            }
            else
            {
                result->distance = -1;
            }
        }
    }
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 
    /* Only when 2 alpha_id's are identical should their storage's are required to compare */
    if (result->distance == 0)
    {
        if (external_data->table[first_pos->position].storage != external_data->table[second_pos->position].storage)
        {
         /**
          * Define SIM is lexicongraphically larger than NVRAM.
          * Hence, if 2 alpha id's are identical, NVRAM appears in front
          * of SIM
          */
            if (external_data->table[first_pos->position].storage == PHB_SIM)
            {
                result->distance = 1;
            }
            else
            {
                result->distance = -1;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_compare_by_tel_num_sig_for_sort
 * DESCRIPTION
 *  Compare two 2-digits telephone numbers. If they are equal, compare
 *  signature.
 * PARAMETERS
 *  external_data       [IN]        External data
 *  first_pos           [?]         
 *  second_pos          [?]         
 *  result              [?]         
 *  first(?)
 *  second(?)
 * RETURNS
 *  result->distance is greater than, equal to, or less than 0, according to(?)
 *  first is greater than, equal to, or less than second.(?)
 *****************************************************************************/
void phb_compare_by_tel_num_sig_for_sort(
        data_entry_table_type *external_data,
        pindex_struct *first_pos,
        pindex_struct *second_pos,
        compare_result_type *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BY_TEL_NUM_SIG_FOR_SORT);

    result->same_count = 0;
    result->distance = 0;

    if (external_data->table[first_pos->position].tel_num > external_data->table[second_pos->position].tel_num)
    {
        result->distance = 1;
    }
    else if (external_data->table[first_pos->position].tel_num < external_data->table[second_pos->position].tel_num)
    {
        result->distance = -1;
    }

    /* (external_data->table[first_pos->position].tel_num == 
       external_data->table[second_pos->position].tel_num) */
    else
    {
        if (external_data->table[first_pos->position].tel_num_sig >
            external_data->table[second_pos->position].tel_num_sig)
        {
            result->distance = 1;
        }
        else if (external_data->table[first_pos->position].tel_num_sig <
                 external_data->table[second_pos->position].tel_num_sig)
        {
            result->distance = -1;
        }

        /* (external_data->table[second_pos->position].tel_num_sig == external_data->table[second_pos->position].tel_num_sig) */
        else
        {
            result->distance = 0;
        }
    }
}   /* end of phb_compare_by_tel_num_sig */


/*****************************************************************************
 * FUNCTION
 *  phb_binary_search
 * DESCRIPTION
 *  A generic binary search function that retrieves the index from primary index
 *  
 *  Note:
 *  Since the array to be searched does not stores unique keys,
 *  nearest algorithm is ALWAYS applied!!
 * PARAMETERS
 *  a                       [?]         
 *  external_data           [?]         
 *  length                  [IN]        
 *  low                     [IN]        
 *  high                    [IN]        
 *  key                     [?]         
 *  compare                 [IN]        
 *  name_num_index(?)       [IN]        The name_num_index
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
static kal_uint16 phb_binary_search(
                    pindex_struct *a,
                    data_entry_table_type *external_data,
                    kal_uint16 length,
                    int low,
                    int high,
                    void *key,
                    compare_func_type compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int mid;
    compare_result_type result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_BINARY_SEARCH);

    ASSERT(compare != NULL);

    while (low <= high)
    {
        mid = (high + low) / 2;

        (*compare) (external_data, key, &a[mid], &result);
        if (result.distance == 0)
        {

         /**
          * Try to find nearest (only when lower neighbor is available).
          * If lower neighbor also matches, we should go to lower half for 
          * binary search, instead of just returning this one.
          */
            if (mid > 0)
            {
                (*compare) (external_data, key, &a[mid - 1], &result);
                if ((mid - 1 >= 0) && (result.distance) == 0)
                {
                    high = mid - 1;
                    continue;
                }
            }

            /* Nearest matched, return. */
            return mid;
        }
        else if (result.distance < 0)
        {
            /* key is less than mid, search lower half */
            high = mid - 1;
        }
        else if (result.distance > 0)
        {
            /* key is greater than mid, search upper half */
            low = mid + 1;
        }
        else
        {
            return (kal_uint16) PHB_INVALID_VALUE;
        }
    }

    /* Termination check */
    if (low > high)
    {
        kal_uint8 same_count_low, same_count_high;
        kal_uint32 dist_low, dist_high;

      /**
       * Choose one that doesn't exceeds the boundaries.
       */
        if (high < 0)
        {
            return (kal_uint16) low;
        }

      /**
       * If low exceeds upper bound, stop trying to match nearest neighbor, 
       * return immediately.
       *
       * For index operations, such as append/insert, this value is
       * returned for appending extra elements into indices.
       *
       * For searching operations, caller should check whether upper bound
       * is exceeded, and decrement this return value to locate nearest neighbor 
       * if necessary.
       */
        if (low > (length - 1))
        {
            return (kal_uint16) low;
        }

        return (kal_uint16) high;
      /**
       * Try to find nearest neighbor:
       * Chooes one that gets higher score.
       */
        (*compare) (external_data, key, &a[low], &result);
        dist_low = phb_abs(result.distance);
        same_count_low = result.same_count;

        (*compare) (external_data, key, &a[high], &result);
        dist_high = phb_abs(result.distance);
        same_count_high = result.same_count;

        /* First, compare same_count's */
        if (same_count_high != same_count_low)
        {
            if (same_count_high > same_count_low)
            {
                return (kal_uint16) high;
            }
            else
            {
                return (kal_uint16) low;
            }
        }
        /* same_count's are equal, compare distance */
        else if (dist_high > dist_low)
        {
            return (kal_uint16) low;
        }
        else
        {
            return (kal_uint16) high;
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;  /* impossible */
}

/**
 * This fast-quicksort algorithm is derived from Denis Ahrens, James Gosling,
 * and Kevin A. Smith.
 *
 * The sorting performance of this fast-quicksort algorithm is quite impressive, see the
 * following URL for performance comparison.
 * Since it uses median-of-three pivot, it doesn't suffers from *pathological* cases, ie,
 * sorting a already sorted array.
 *
 * See: http://www.cs.ubc.ca/spider/harrison/Java/sorting-demo.html
 * for comparison and demonstration of various sorting algorithms.
 * Also see: http://ciips.ee.uwa.edu.au/~morris/Year2/PLDS210/sorting.html
 * for some guidelines.
 *
 * The following is the original comment included in their source codes.
 * ps: the original code is for Java.
 */
/**
 * A quick sort demonstration algorithm
 * SortAlgorithm.java
 *
 * @author James Gosling
 * @author Kevin A. Smith
 * @version @(#)QSortAlgorithm.java 1.3, 29 Feb 1996
 * extended with TriMedian and InsertionSort by Denis Ahrens
 * with all the tips from Robert Sedgewick (Algorithms in C++).
 * It uses TriMedian and InsertionSort for lists shorts than 4.
 * <fuhrmann@cs.tu-berlin.de>
 */
/** This is a generic version of C.A.R Hoare's Quick Sort 
 * algorithm.  This will handle arrays that are already
 * sorted, and arrays with duplicate keys.<BR>
 *
 * If you think of a one dimensional array as going from
 * the lowest index on the left to the highest index on the right
 * then the parameters to this function are lowest index or
 * left and highest index or right.  The first time you call
 * this function it will be with the parameters 0, a.length - 1.
 *
 * @param a an integer array
 * @param lo0 left boundary of array partition
 * @param hi0 right boundary of array partition
 */


/*****************************************************************************
 * FUNCTION
 *  phb_swap
 * DESCRIPTION
 *  Part of the fast-quicksort algorithm.
 *  Swaps 'i'th and 'j'th elements in the array `a'.
 * PARAMETERS
 *  a       [IN]        The array to be sorted.
 *  i       [IN]        Swaps with j
 *  j       [IN]        Swaps with i
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
static void phb_swap(pindex_struct *a, kal_uint16 i, kal_uint16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pindex_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SWAP);

    kal_mem_cpy(&temp, (void const*)&a[i], sizeof(pindex_struct));
    kal_mem_cpy(&a[i], (void const*)&a[j], sizeof(pindex_struct));
    kal_mem_cpy(&a[j], (void const*)&temp, sizeof(pindex_struct));
}   /* end of phb_swap */


/*****************************************************************************
 * FUNCTION
 *  phb_quicksort
 * DESCRIPTION
 *  Part of the fast-quicksort algorithm.
 *  Swaps 'i'th and 'j'th elements in the array `a'.
 * PARAMETERS
 *  a                   [IN]        The array to be sorted.
 *  external_data       [?]         
 *  l                   [IN]        The lower bound of the array `a'
 *  r                   [IN]        The upper bound of the array `a'
 *  compare             [IN]        
 *  compare_func(?)     [IN]        Caller-provided comparison function
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
static void phb_quicksort(
                pindex_struct *a,
                data_entry_table_type *external_data,
                kal_uint16 l,
                kal_uint16 r,
                compare_func_type compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 const M = 4;
    kal_uint16 i;
    kal_uint16 j;
    pindex_struct v;

    compare_result_type result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_QUICKSORT);

    ASSERT(compare != NULL);

    if ((r - l) > M)
    {
        i = (r + l) / 2;

        /* a[l] > a[i] */
        (*compare) (external_data, &a[l], &a[i], &result);
        if (result.distance > 0)
        {
            phb_swap(a, l, i);  /* Tri-Median Methode! */
        }

        /* a[l] > a[r] */
        (*compare) (external_data, &a[l], &a[r], &result);
        if (result.distance > 0)
        {
            phb_swap(a, l, r);
        }

        /* a[i] > a[r] */
        (*compare) (external_data, &a[i], &a[r], &result);
        if (result.distance > 0)
        {
            phb_swap(a, i, r);
        }

        j = r - 1;
        phb_swap(a, i, j);
        i = l;
        kal_mem_cpy(&v, (void const*)&a[j], sizeof(pindex_struct));

        for (;;)
        {
            /* a[++i] < v */
            do
            {
                (*compare) (external_data, &a[++i], &v, &result);
            } while (result.distance < 0);

            /* a[--j] > v */
            do
            {
                (*compare) (external_data, &a[--j], &v, &result);
            } while (result.distance > 0);
            if (j < i)
            {
                break;
            }

            phb_swap(a, i, j);
        }
        phb_swap(a, i, (kal_uint16) (r - 1));
        phb_quicksort(a, external_data, l, j, compare);
        phb_quicksort(a, external_data, (kal_uint16) (i + 1), r, compare);
    }
}   /* end of phb_quicksort */


/*****************************************************************************
 * FUNCTION
 *  phb_insertion_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a                   [?]         
 *  external_data       [?]         
 *  lo0                 [IN]        
 *  hi0                 [IN]        
 *  compare             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_insertion_sort(
        pindex_struct *a,
        data_entry_table_type *external_data,
        kal_uint16 lo0,
        kal_uint16 hi0,
        compare_func_type compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    compare_result_type result;

    kal_uint16 i;
    kal_uint16 j;
    pindex_struct v;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_INSERTION_SORT);

    ASSERT(compare != NULL);

    for (i = lo0 + 1; i <= hi0; ++i)
    {
        kal_mem_cpy(&v, (void const*)&a[i], sizeof(pindex_struct));

        j = i;
        while (j > lo0)
        {

            /* a[j - 1] <= v */
            (*compare) (external_data, &a[j - 1], &v, &result);
            if (result.distance <= 0)
            {
                break;
            }

            kal_mem_cpy(&a[j], (void const*)&a[j - 1], sizeof(pindex_struct));
            j--;
        }
        kal_mem_cpy(&a[j], (void const*)&v, sizeof(pindex_struct));
    }
}   /* end of phb_insertion_sort */


/*****************************************************************************
 * FUNCTION
 *  phb_fast_quicksort
 * DESCRIPTION
 *  Sort an array by using caller-provided comparison function.
 * PARAMETERS
 *  a                   [IN]        The array to be sorted.
 *  external_data       [?]         
 *  l                   [IN]        The lower bound of the array `a'
 *  r                   [IN]        The upper bound of the array `a'
 *  compare             [IN]        
 *  compare_func(?)     [IN]        Caller-provided comparison function
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
static void phb_fast_quicksort(
                pindex_struct *a,
                data_entry_table_type *external_data,
                kal_uint16 l,
                kal_uint16 r,
                compare_func_type compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_FAST_QUICKSORT);

    phb_quicksort(a, external_data, l, r, compare);
    phb_insertion_sort(a, external_data, l, r, compare);
}   /* end of phb_fast_quicksort */

