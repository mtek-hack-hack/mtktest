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
 * phb_data_desc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the data descriptor. It maintains number of records, record size, free count,
 *   bits of the bitmap, free list implemented in bitmap.
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

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"
#include "phb_context.h"

/* prerequisite of phb_data_desc.h */
#include "nvram_data_items.h"
#include "phb_config.h"
/* include the LID */
// #include "nvram_data_items.h"
#include "nvram_user_defs.h"

#undef _FILE_CODE_
#define _FILE_CODE_ PHB_DATA_DESCRIPTOR_C


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_entry_reset
 * DESCRIPTION
 *  Reset the data descriptor
 * PARAMETERS
 *  data_desc_entry     [?]         
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_data_desc_entry_reset(data_desc_type *data_desc_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_ENTRY_RESET); */

    ASSERT(data_desc_entry != NULL);

    data_desc_entry->is_support = KAL_FALSE;
    data_desc_entry->record_num = 0;
    data_desc_entry->record_size = 0;

    data_desc_entry->free_count = 0;

    if (data_desc_entry->free_bitmap != NULL)
    {
        kal_mem_set(data_desc_entry->free_bitmap, 0, data_desc_entry->free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
    }
}   /* end of phb_data_desc_entry_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_entry_new
 * DESCRIPTION
 *  Constructor of data descriptor
 * PARAMETERS
 *  data_desc_entry     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_data_desc_entry_new(data_desc_type *data_desc_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_ENTRY_NEW); */
    phb_data_desc_entry_reset(data_desc_entry);
}


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_new
 * DESCRIPTION
 *  Constructor of data descriptor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_new()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_NEW); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_ptr->data_desc[i].free_bitmap_bits = (kal_uint16) (data_desc_bytes[i] << BYTE_SIZE_SHIFT_ARITHMETIC);
        phb_data_desc_entry_new(&phb_ptr->data_desc[i]);
    }
}   /* end of phb_data_desc_new */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_reset
 * DESCRIPTION
 *  Reset the data descriptor
 * PARAMETERS
 *  void
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_reset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_RESET); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_data_desc_entry_reset(&phb_ptr->data_desc[i]);
    }
}   /* end of phb_data_desc_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_reset_free_count
 * DESCRIPTION
 *  Reset free count of the data descriptor
 * PARAMETERS
 *  void
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_reset_free_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_RESET_FREE_COUNT); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_ptr->data_desc[i].free_count = 0;
        if (phb_ptr->data_desc[i].free_bitmap != NULL)
        {
            kal_mem_set(
                phb_ptr->data_desc[i].free_bitmap,
                0,
                phb_ptr->data_desc[i].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
        }
    }
}   /* end of phb_data_desc_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_set_is_support
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  is_support          [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_set_is_support(data_desc_enum type, kal_bool is_support)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_SET_IS_SUPPORT);

    phb_ptr->data_desc[type].is_support = is_support;
}   /* end of phb_data_desc_set_is_support */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_record_size
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_data_desc_get_record_size(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_RECORD_SIZE);

    return ((type == DATA_DESC_EXT1) ||
            (type == DATA_DESC_EXT2) || (type == DATA_DESC_EXT3)) ? 13 : phb_ptr->data_desc[type].record_size;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_record_num
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_data_desc_get_record_num(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_RECORD_NUM);

    return phb_ptr->data_desc[type].record_num;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_set
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  record_num          [IN]        
 *  record_size         [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_set(data_desc_enum type, kal_uint16 record_num, kal_uint16 record_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_SET);

    phb_ptr->data_desc[type].record_num = record_num;
    phb_ptr->data_desc[type].record_size = record_size;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_mark_free
 * DESCRIPTION
 *  Mark free to the data-descriptor.
 *  Note that a free record is marked as 1 in bitmap.
 * PARAMETERS
 *  type                [IN]        
 *  pos                 [IN]        
 *  is_free             [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_mark_free(data_desc_enum type, kal_uint16 pos, kal_bool is_free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];
    kal_uint8 *free_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_MARK_FREE);

    ASSERT(data_desc_entry != NULL);

    if ((--pos >= data_desc_entry->record_num) ||
        ((pos >> BYTE_SIZE_SHIFT_ARITHMETIC) >= data_desc_bytes[type]) || (type == DATA_DESC_SDN))
    {
        return;
    }

    free_bitmap = (kal_uint8*) data_desc_entry->free_bitmap;
    if (is_free)
    {
      /**
       * Only when 'pos' is not marked as free is allowed to be marked as free.
       */
        if (!(free_bitmap[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (pos % BYTE_SIZE))))
        {

            free_bitmap[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (pos % BYTE_SIZE);

            if (data_desc_entry->free_count < data_desc_entry->record_num)
            {
                data_desc_entry->free_count++;
            }
        }
    }
    else
    {
      /**
       * Only when 'pos' is marked as free is allowed to be marked as not free.
       */
        if (free_bitmap[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (pos % BYTE_SIZE)))
        {
            free_bitmap[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8) (~(1 << (pos % BYTE_SIZE)));

            if (data_desc_entry->free_count > 0)
            {
                data_desc_entry->free_count--;
            }
        }
    }
}   /* end of data_desc_append */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_find_next_free
 * DESCRIPTION
 *  Find record index of next free record
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_data_desc_find_next_free(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];

    kal_uint16 byte_counter;
    kal_uint16 bit_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_FIND_NEXT_FREE);

    ASSERT(data_desc_entry != NULL);

    if ((data_desc_entry->is_support == KAL_FALSE) &&
        (data_desc_entry->free_count == 0) || (data_desc_entry->free_bitmap == NULL))
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    for (byte_counter = 0;
         byte_counter < (data_desc_entry->free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC); ++byte_counter)
    {
        if (data_desc_entry->free_bitmap[byte_counter] != 0)
        {
            for (bit_counter = 0; (bit_counter < BYTE_SIZE) &&
                 (((byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter) < data_desc_entry->record_num);
                 ++bit_counter)
            {
                if (data_desc_entry->free_bitmap[byte_counter] & (1 << bit_counter))
                {
                    return (byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter + 1;
                }
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of data_desc_append */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_free_count
 * DESCRIPTION
 *  Find record index of next free record
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_data_desc_get_free_count(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_FREE_COUNT);

    ASSERT(data_desc_entry != NULL);

    return data_desc_entry->free_count;
}   /* end of data_desc_append */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_is_free
 * DESCRIPTION
 *  Tests whether a record is free
 * PARAMETERS
 *  type                [IN]        
 *  pos                 [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
free_status_enum phb_data_desc_is_free(data_desc_enum type, kal_uint16 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_IS_FREE);

    ASSERT(data_desc_entry != NULL);

    if ((data_desc_entry->is_support == KAL_FALSE) ||
        (--pos >= data_desc_entry->record_num) ||
        ((pos >> BYTE_SIZE_SHIFT_ARITHMETIC) >= data_desc_bytes[type]) || (type == DATA_DESC_SDN))
    {
        return RECORD_INVALID;
    }

    if (((kal_uint8*) data_desc_entry->free_bitmap)[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (pos % BYTE_SIZE)))
    {
        return RECORD_FREE;
    }

    return RECORD_OCCUPIED;
}   /* end of phb_data_desc_is_free */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_desc_by_ID
 * DESCRIPTION
 *  Return corresponding data descriptor type of sim_file_id
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  Return corresponding data descriptor type of sim_file_id
 *****************************************************************************/
data_desc_enum phb_data_desc_get_desc_by_ID(kal_uint16 file_id, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_DESC_BY_ID);

    if (storage == PHB_NVRAM)
    {
        if (file_id == NVRAM_EF_PHB_LID)
            return DATA_DESC_PHB;
    }
    else if (storage == PHB_SIM)
    {
        switch (file_id)
        {
            case FILE_ADN_IDX:
                return DATA_DESC_ADN;

            case FILE_FDN_IDX:
                return DATA_DESC_FDN;

            case FILE_MSISDN_IDX:
                return DATA_DESC_MSISDN;

            case FILE_SDN_IDX:
                return DATA_DESC_SDN;

            case FILE_BDN_IDX:
                return DATA_DESC_BDN;

            case FILE_EXT1_IDX:
                return DATA_DESC_EXT1;

            case FILE_EXT2_IDX:
                return DATA_DESC_EXT2;

            case FILE_EXT3_IDX:
                return DATA_DESC_EXT3;

            case FILE_EXT4_IDX:
                return DATA_DESC_EXT4;

        #ifdef __USIM_SUPPORT__
            case FILE_G_EXT1_IDX:
                return DATA_DESC_EXT1;

            case FILE_G_ADN_IDX:
                return DATA_DESC_ADN;

            case FILE_G_PBR_IDX:
                return DATA_DESC_PBR;
        #endif /* __USIM_SUPPORT__ */

        #ifdef __PHB_USIM_SUPPORT__
            case FILE_G_IAP_IDX:
                return DATA_DESC_IAP;

            case FILE_G_GRP_IDX:
                return DATA_DESC_GRP;

            case FILE_G_ANR_IDX:
                return DATA_DESC_ANRA;

            case FILE_G_SNE_IDX:
                return DATA_DESC_SNE;

            case FILE_G_EMAIL_IDX:
                return DATA_DESC_EMAIL;

            case FILE_G_GAS_IDX:
                return DATA_DESC_GAS;

            case FILE_G_PBC_IDX:
            case FILE_G_CCP1_IDX:
            case FILE_G_PSC_IDX:
            case FILE_G_CC_IDX:
            case FILE_G_PUID_IDX:
            case FILE_G_AAS_IDX:
                break;
        #endif /* __PHB_USIM_SUPPORT__ */ 
        }
    }
    else
    {
        ASSERT(0);
    }
    return (data_desc_enum) PHB_INVALID_VALUE;
}   /* end of phb_data_desc_get_desc_by_ID */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_ID_by_desc
 * DESCRIPTION
 *  Return corresponding ID of data descriptor type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_uint16 phb_data_desc_get_ID_by_desc(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_ID_BY_DESC);

    switch (type)
    {
        case DATA_DESC_PHB:
            return NVRAM_EF_PHB_LID;

        case DATA_DESC_ADN:
            return FILE_ADN_IDX;

        case DATA_DESC_FDN:
            return FILE_FDN_IDX;

        case DATA_DESC_MSISDN:
            return FILE_MSISDN_IDX;

        case DATA_DESC_SDN:
            return FILE_SDN_IDX;

        case DATA_DESC_BDN:
            return FILE_BDN_IDX;

        case DATA_DESC_EXT1:
            return FILE_EXT1_IDX;

        case DATA_DESC_EXT2:
            return FILE_EXT2_IDX;

        case DATA_DESC_EXT3:
            return FILE_EXT3_IDX;

        case DATA_DESC_EXT4:
            return FILE_EXT4_IDX;
    }

    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_data_desc_get_ID_by_desc */

