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
 * phb_data_entry_table.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is data-entry-table. Data stucture of the table is defined, as well as functions
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
#include "phb_data_entry_table.h"
#include "phb_utils.h"

#undef _FILE_CODE_
#define _FILE_CODE_ _PHB_DATA_ENTRY_TABLE_C_


/*****************************************************************************
 * FUNCTION
 *  phb_det_get_size
 * DESCRIPTION
 *  Returns size of memory occupied by the name-num index.
 * PARAMETERS
 *  slots       [IN]        Total slots of table
 * RETURNS
 *  Size of memory
 *****************************************************************************/
kal_uint16 phb_det_get_size(kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_DET_GET_SIZE); */

    return sizeof(data_entry_table_type) + sizeof(data_entry_struct) * slots;
}


/*****************************************************************************
 * FUNCTION
 *  phb_det_new
 * DESCRIPTION
 *  Constructor.
 * PARAMETERS
 *  det         [IN]        The allocated memory for the new data-entry-table
 *  slots       [IN]        
 *  size(?)     [IN]        Total slots of table
 * RETURNS
 *  void
 *****************************************************************************/
void phb_det_new(data_entry_table_type *det, kal_uint16 slots)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_DET_NEW); */

    det->slots = slots;
    phb_det_reset(det);
}   /* end of phb_det_new */


/*****************************************************************************
 * FUNCTION
 *  phb_det_reset
 * DESCRIPTION
 *  Reset data-entry-table.
 * PARAMETERS
 *  det     [IN]        The data-entry-table to reset
 * RETURNS
 *  void
 *****************************************************************************/
void phb_det_reset(data_entry_table_type *det)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_DET_RESET); */

    ASSERT(det != NULL);

    det->used_count = 0;
    kal_mem_set(det->table, (kal_uint8) PHB_INVALID_VALUE, det->slots * sizeof(data_entry_struct));
}   /* end of phb_det_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_det_append
 * DESCRIPTION
 *  Append to data-entry-table.
 * PARAMETERS
 *  det                 [IN]        The det
 *  alpha_id            [?]         
 *  storage             [IN]        
 *  record_index        [IN]        
 *  signature           [IN]        
 *  tel_num             [IN]        
 *  ext_index           [IN]        
 * RETURNS
 *  Position where new data is appended if success, PHB_INVALID_VALUE else.
 *  Lower bound is 0.
 *****************************************************************************/
kal_uint16 phb_det_append(
            data_entry_table_type *det,
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
    kal_uint16 position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DET_APPEND);

    ASSERT(det != NULL);

    if (det->used_count >= det->slots)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    phb_det_set(det, det->used_count, alpha_id, storage, record_index, signature, tel_num, ext_index);

    position = det->used_count++;
    return position;
}   /* end of phb_det_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_det_set
 * DESCRIPTION
 *  Set `position'th element of det with new values.
 * PARAMETERS
 *  det                 [IN]        The data-entry-table
 *  position            [IN]        The position, start from 0.
 *  alpha_id            [?]         
 *  storage             [IN]        
 *  record_index        [IN]        
 *  signature           [IN]        
 *  tel_num             [IN]        
 *  ext_index           [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_bool phb_det_set(
            data_entry_table_type *det,
            kal_uint16 position,
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
    data_entry_struct *data_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DET_SET);

    ASSERT(det != NULL);

    if (position > det->slots)
    {
        return KAL_FALSE;
    }

    data_entry = &det->table[position];

    kal_mem_cpy(&data_entry->alpha_id, (void const*)alpha_id, sizeof(alpha_id_type));
    if (alpha_id->length > PHB_ALPHA_ID_DEPTH)
    {
        data_entry->alpha_id.length = PHB_ALPHA_ID_DEPTH;
    }

    data_entry->storage = storage;
    data_entry->record_index = record_index;
    data_entry->tel_num_sig = signature;
    data_entry->tel_num = tel_num;
    data_entry->ext_index = ext_index;

    return KAL_TRUE;
}   /* end of phb_pindex_insert */


/*****************************************************************************
 * FUNCTION
 *  phb_det_delete
 * DESCRIPTION
 *  Delete `position'th element of table of det
 * PARAMETERS
 *  det             [IN]        The data-entry-table
 *  position        [IN]        The position
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.
 *****************************************************************************/
kal_bool phb_det_delete(data_entry_table_type *det, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DET_DELETE);

    ASSERT(det != NULL);

    if (position > (det->used_count - 1))
    {
        return KAL_FALSE;
    }

    table_shift(
        &det->used_count,
        &det->slots,
        det->table,
        sizeof(data_entry_struct),
        shift_up,
        (kal_uint16) (position + 1));
    kal_mem_set(&det->table[--det->used_count], (kal_uint8) PHB_INVALID_VALUE, sizeof(data_entry_struct));

    return KAL_TRUE;
}   /* end of phb_pindex_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_det_get
 * DESCRIPTION
 *  Get `position'th element of table of det
 * PARAMETERS
 *  det             [IN]        The data-entry-table
 *  position        [IN]        The position
 * RETURNS
 *  The data entry if success, NULL otherwise.
 *****************************************************************************/
data_entry_struct *phb_det_get(data_entry_table_type *det, kal_uint16 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DET_GET);

    ASSERT(det != NULL);

    if (position < det->used_count)
    {
        return &det->table[position];
    }

    return NULL;
}   /* end of phb_det_get */


/*****************************************************************************
 * FUNCTION
 *  phb_det_get_pos_by_record_index
 * DESCRIPTION
 *  Get `position'th element in data entry table by record index
 * PARAMETERS
 *  det             [IN]        The data-entry-table
 *  record_index    [IN]        The record_index
 * RETURNS
 *  The data entry if success, NULL otherwise.
 *****************************************************************************/
kal_uint16 phb_det_get_pos_by_record_index(data_entry_table_type *det, kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 pos = (kal_uint16) PHB_INVALID_VALUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DET_GET_POS_BY_RECORD_INDEX);

    ASSERT(det != NULL);

    for(i = 0; i < det->used_count; i++)
    {
        if(det->table[i].record_index == record_index)
        {
            pos = i;
            break;
        }
    }
    return pos;
}