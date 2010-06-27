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
 * phb_pindex.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a primary index. Data stucture of primary index is defined, as well as functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

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
#include "phb_pindex.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ PHB_PINDEX_C


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_get_size
 * DESCRIPTION
 *  Returns size of memory occupied by a pindex.
 * PARAMETERS
 *  slots       [IN]        Total slots of table
 * RETURNS
 *  Size of memory
 *****************************************************************************/
kal_uint16 phb_pindex_get_size(kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_GET_SIZE); */

    return sizeof(pindex_type) + sizeof(pindex_struct) * slots;
}


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_new
 * DESCRIPTION
 *  Constructor of pindex(primary index).
 * PARAMETERS
 *  pindex      [IN]        The allocated memory for the new pindex
 *  slots       [IN]        
 *  size(?)     [IN]        Total slots of table
 * RETURNS
 *  void
 *****************************************************************************/
void phb_pindex_new(pindex_type *pindex, kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_NEW); */

    ASSERT(pindex != NULL);

    pindex->slots = slots;
    phb_pindex_reset(pindex);
}   /* end of phb_pindex_new */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_reset
 * DESCRIPTION
 *  Reset pindex(primary index).
 * PARAMETERS
 *  pindex      [IN]        The pindex to reset
 * RETURNS
 *  void
 *****************************************************************************/
void phb_pindex_reset(pindex_type *pindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_RESET); */

    ASSERT(pindex != NULL);

    pindex->used_count = 0;

    if (pindex->slots > 0)
    {
        kal_mem_set(pindex->table, (kal_uint8) PHB_INVALID_VALUE, pindex->slots * sizeof(pindex_struct));
    }
}   /* end of phb_pindex_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_append
 * DESCRIPTION
 *  Append to pindex(primary index).
 * PARAMETERS
 *  pindex          [IN]        The pindex
 *  position        [IN]        The data to append
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_uint16 phb_pindex_append(pindex_type *pindex, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_APPEND);

    ASSERT(pindex != NULL);

    if (pindex->used_count < pindex->slots)
    {
        pindex->table[pindex->used_count++].position = position;
        return (kal_uint16) PHB_INVALID_VALUE;
    }
    return pindex->used_count;
}   /* end of phb_pindex_append */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_insert
 * DESCRIPTION
 *  Insert `position' into `index'th element of table of pindex(primary index).
 * PARAMETERS
 *  pindex          [IN]        The pindex
 *  index           [IN]        The `index'th element in table to store `position'
 *  position        [IN]        The data to append
 * RETURNS
 *  index appended.
 *****************************************************************************/
kal_uint16 phb_pindex_insert(pindex_type *pindex, kal_uint16 index, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_INSERT);

    ASSERT(pindex != NULL);

   /** 
    * Being inserted index could be equal to used_count.
    * Note that capacity must no be exceeded after insertion.
    */
    if ((index > pindex->used_count) || (pindex->used_count >= pindex->slots))
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    /* If the entry to be inserted is head or tail, shift is not needed. */
    if (!((pindex->used_count == 0) || (index >= pindex->used_count)))
    {
        /* Shift down one slot, so that the entry could be inserted. */
        table_shift(&pindex->used_count, &pindex->slots, pindex->table, sizeof(pindex_struct), shift_down, index);
    }

    pindex->table[index].position = position;
    ++pindex->used_count;

    return index;
}   /* end of phb_pindex_insert */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_update
 * DESCRIPTION
 *  Update `old_index'th element of table to `new_index' with new value `new_pos'.
 * PARAMETERS
 *  pindex          [IN]        The pindex
 *  old_index       [IN]        The old index
 *  new_index       [IN]        The new index
 *  new_pos         [IN]        The data to append
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_uint16 phb_pindex_update(pindex_type *pindex, kal_uint16 old_index, kal_uint16 new_index, kal_uint16 new_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_UPDATE);

    ASSERT(pindex != NULL);

    if ((old_index > (pindex->used_count - 1)) || (new_index > (pindex->used_count - 1)))
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    /* Same index, nothing has to be done. */
    if (new_index == old_index)
    {
        return new_index;
    }

    if (new_index > old_index)
    {
        table_range_shift(
            &pindex->used_count,
            &pindex->slots,
            pindex->table,
            sizeof(pindex_struct),
            shift_up,
            (kal_uint16) (old_index + 1),
            new_index);
        pindex->table[new_index].position = new_pos;
    }

    else
    {
        table_range_shift(
            &pindex->used_count,
            &pindex->slots,
            pindex->table,
            sizeof(pindex_struct),
            shift_down,
            new_index,
            (kal_uint16) (old_index - 1));
        pindex->table[new_index].position = new_pos;
    }

    return new_index;
}   /* end of phb_pindex_insert */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_delete
 * DESCRIPTION
 *  Delete `index'th element of table of pindex
 * PARAMETERS
 *  pindex      [IN]        The pindex
 *  index       [IN]        The index
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_bool phb_pindex_delete(pindex_type *pindex, kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_DELETE);

    ASSERT(pindex != NULL);

    if (index > (pindex->used_count - 1))
    {
        return KAL_FALSE;
    }

    table_shift(
        &pindex->used_count,
        &pindex->slots,
        pindex->table,
        sizeof(pindex_struct),
        shift_up,
        (kal_uint16) (index + 1));

    pindex->table[--pindex->used_count].position = (kal_uint16) PHB_INVALID_VALUE;

    return KAL_TRUE;
}   /* end of phb_pindex_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_relink
 * DESCRIPTION
 *  This function is used to relink with data_entry_table due to
 *  unmatched index when some entry of data_entry_table is deleted.
 * PARAMETERS
 *  pindex              [IN]        The pindex
 *  old_position        [IN]        
 *  index(?)            [IN]        The index
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
void phb_pindex_relink(pindex_type *pindex, kal_uint16 old_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_RELINK);

    ASSERT(pindex != NULL);

    /* No other way except linear searching. *Sigh* */
    for (i = 0; i < pindex->used_count; ++i)
        if (pindex->table[i].position > old_position)
        {
            --pindex->table[i].position;
        }
}   /* end of phb_pindex_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_get_pos
 * DESCRIPTION
 *  Return `index'th element of table of pindex
 * PARAMETERS
 *  pindex      [IN]        The pindex
 *  index       [IN]        The index
 * RETURNS
 *  position if success, PHB_INVALID_VALUE otherwise.
 *****************************************************************************/
kal_uint16 phb_pindex_get_pos(pindex_type *pindex, kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_GET_POS);

    ASSERT(pindex != NULL);

    if (--index < pindex->used_count)
    {
        return pindex->table[index].position;
    }

    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_pindex_get_pos */


/*****************************************************************************
 * FUNCTION
 *  phb_pindex_get_index_by_position
 * DESCRIPTION
 *  Return `index'th element of pindex table by position in data_desc_table
 * PARAMETERS
 *  pindex      [IN]        The pindex
 *  position    [IN]        The position
 * RETURNS
 *  position if success, PHB_INVALID_VALUE otherwise.
 *****************************************************************************/
kal_uint16 phb_pindex_get_index_by_position(pindex_type *pindex, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 index = (kal_uint16) PHB_INVALID_VALUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PINDEX_GET_INDEX_BY_POSITION);

    ASSERT(pindex != NULL);

    for(i = 0; i < pindex->used_count; i++)
    {
        if(pindex->table[i].position == position)
        {
            index = i;
            break;
        }
    }

    return index;
}