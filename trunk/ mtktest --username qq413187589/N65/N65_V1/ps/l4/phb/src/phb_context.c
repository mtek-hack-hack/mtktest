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
 * phb_context.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#undef  _FILE_CODE_
#define _FILE_CODE_  _PHB_CONTEXT_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

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
#include "phb_config.h"

#ifdef __GEMINI__
#include  "sim_common_enums.h"
#endif /* __GEMINI__ */

#ifdef __GEMINI__
phb_context_type phb_context[2];
phb_context_type *phb_ptr;

extern ext_index_struct *ext_index_table;
extern ext_index_struct ext_index_table_context[2][EXT1_MAX_ENTRIES_COUNT];

#ifdef __PHB_USIM_SUPPORT__
extern kal_uint8 *anr_index_table;
extern kal_uint8 anr_index_table_context[2][ANR_INDEX_MAX_ENTRIES_COUNT];
extern kal_uint8 *email_index_table;
extern kal_uint8 email_index_table_context[2][EMAIL_INDEX_MAX_ENTRIES_COUNT];
extern kal_uint8 *sne_index_table;
extern kal_uint8 sne_index_table_context[2][SNE_INDEX_MAX_ENTRIES_COUNT];
#endif /* __PHB_USIM_SUPPORT__ */ 

#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
extern alpha_id_type *alpha_id_pinyin_PHB;
extern alpha_id_type alpha_id_pinyin_PHB_context[2][PHB_INDEX_MAX_ENTRIES_COUNT];
#endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */

#else /* __GEMINI__ */
phb_context_type phb_context;
phb_context_type *phb_ptr = &phb_context;
#endif /* __GEMINI__ */

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#ifdef __GEMINI__
kal_uint8 phb_ln_type_seq_context[2][PHB_TOTAL_LN_ENTRIES];
kal_uint8 *phb_ln_type_seq;
#else /* __GEMINI__ */
kal_uint8 phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES];
#endif /* __GEMINI__ */
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */

#if (MAX_PHB_LN_ENTRY > 20)
phb_ln_entry_struct shifted_entry;
#endif 


/*****************************************************************************
 * FUNCTION
 *  phb_context_reset
 * DESCRIPTION
 *  Reset context of PHB. Including:
 *  1. Clean ECC.
 *  2. Reset dn_type to TYPE_NONE.
 *  3. Construct control_blocks.
 *  4. Reset state to STATE_NOT_READY.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_context_reset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    kal_mem_set(&phb_ptr->ecc, 0, sizeof(sim_ecc_struct));
    phb_ptr->dn_type = TYPE_NONE;

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {
        phb_control_block_construct(&phb_ptr->control_block[i], i);
    }

    phb_ptr->state = PHB_STATE_NOT_READY;

    phb_ptr->adn_alpha_length = 30;
    phb_ptr->fdn_alpha_length = 30;
    phb_ptr->bdn_alpha_length = 30;
    phb_ptr->msisdn_alpha_length = 30;
    phb_ptr->compare_digit = 0;
#ifdef __PHB_USIM_SUPPORT__
    if (is_usim_type())
    {
        phb_ptr->is_usim = KAL_TRUE;
    }
    else
    {
        phb_ptr->is_usim = KAL_FALSE;
    }
    phb_ptr->anra_type = 0;
    phb_ptr->anrb_type = 0;
    phb_ptr->anrc_type = 0;
    phb_ptr->sne_type = 0;
    phb_ptr->email_type = 0;
    phb_ptr->group_alpha_length = 30;
    phb_ptr->sne_alpha_length = 30;
    phb_ptr->email_length = 60;
#endif /* __PHB_USIM_SUPPORT__ */ 
}

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__


/*****************************************************************************
 * FUNCTION
 *  phb_clear_lnd_type_seq
 * DESCRIPTION
 *  Clear the lnd type sequence.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_clear_lnd_type_seq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < PHB_TOTAL_LN_ENTRIES || phb_ln_type_seq[j] == 0xff)
    {
        if (phb_ln_type_seq[j] != PHB_LND)
        {
            phb_ln_type_seq[i] = phb_ln_type_seq[j];
            i++;
        }
        j++;
    }
    while (i < PHB_TOTAL_LN_ENTRIES)
    {
        phb_ln_type_seq[i] = 0xff;
        i++;
    }
}
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_set_ln_type_seq
 * DESCRIPTION
 *  Set the ln type sequence by given type.
 * PARAMETERS
 *  num         [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_set_ln_type_seq(kal_uint16 num, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num > PHB_TOTAL_LN_ENTRIES)
    {
        ASSERT(0);
        num = PHB_TOTAL_LN_ENTRIES;
    }
    for (i = 0; i < num; i++)
    {
        phb_ln_type_seq[i] = type;
    }
}

#if (MAX_PHB_LN_ENTRY > 20)


/*****************************************************************************
 * FUNCTION
 *  phb_get_ln_total_entry
 * DESCRIPTION
 *  Get the total number of ln entry by the given type.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 phb_get_ln_total_entry(kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < PHB_TOTAL_LN_ENTRIES && phb_ln_type_seq[i] != 0xff)
    {
        if (phb_ln_type_seq[i] == type)
        {
            total++;
        }
        i++;
    }
    return total;
}
#endif /* (MAX_PHB_LN_ENTRY > 20) */ /* MAX_PHB_LN_ENTRY > 20 */
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_alloc_control_block
 * DESCRIPTION
 *  Allocate of control_block.
 * PARAMETERS
 *  void
 *  control_block(?)        [IN]        The control_block
 * RETURNS
 *  The allocated control_block is success, NULL otherwise.
 *****************************************************************************/
control_block_type *phb_alloc_control_block()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    control_block_type *control_block = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {

        if (phb_ptr->control_block[i].is_allocated == KAL_TRUE)
        {
            continue;
        }

        control_block = &phb_ptr->control_block[i];

        phb_control_block_construct(control_block, i);
        control_block->is_allocated = KAL_TRUE;

        break;
    }

#ifdef __GEMINI__
    if (control_block == NULL)
    {
        kal_prompt_trace(MOD_PHB, "phb_alloc_control_block = null, mod = %d", phb_current_mod); 
    }
#endif
    return control_block;
}


/*****************************************************************************
 * FUNCTION
 *  phb_free_control_block
 * DESCRIPTION
 *  Destructs / resets the control block.
 * PARAMETERS
 *  control_block       [IN]        The control_block to set
 * RETURNS
 *  void
 *****************************************************************************/
void phb_free_control_block(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(control_block->is_allocated == KAL_TRUE);

    kal_mem_set(control_block, 0, sizeof(control_block_type));
    /* control_block->is_allocated = KAL_FALSE; */
}   /* end of control_block_set_destruct */


/*****************************************************************************
 * FUNCTION
 *  phb_reset_all_control_blocks
 * DESCRIPTION
 *  Reset all control_blocks
 * PARAMETERS
 *  void
 *  control_block(?)        [IN]        The control_block
 * RETURNS
 *  First control_block.(?)
 *****************************************************************************/
void phb_reset_all_control_blocks()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    control_block_type *control_block = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {

        control_block = &phb_ptr->control_block[i];

        phb_control_block_construct(control_block, i);

        control_block->is_allocated = KAL_FALSE;
    }
}


#ifdef __GEMINI__
/*****************************************************************************
 * FUNCTION
 *  phb_context_selection
 * DESCRIPTION
 *  This is deinit() function of PHB module.
 *  This function finalize all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
void phb_context_selection(kal_uint8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface == SIM1)
    {
        phb_ptr = &phb_context[0];
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        phb_ln_type_seq = phb_ln_type_seq_context[0];
    #endif

        ext_index_table = ext_index_table_context[0];
    #ifdef __PHB_USIM_SUPPORT__
        anr_index_table = anr_index_table_context[0];
        email_index_table = email_index_table_context[0];
        sne_index_table = sne_index_table_context[0];
    #endif /* __PHB_USIM_SUPPORT__ */

    #if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
          alpha_id_pinyin_PHB = alpha_id_pinyin_PHB_context[0];
    #endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */

        phb_current_mod = MOD_PHB;
    }
    else if (sim_interface == SIM2)
    {
        phb_ptr = &phb_context[1];
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        phb_ln_type_seq = phb_ln_type_seq_context[1];
    #endif

        ext_index_table = ext_index_table_context[1];
    #ifdef __PHB_USIM_SUPPORT__
        anr_index_table = anr_index_table_context[1];
        email_index_table = email_index_table_context[1];
        sne_index_table = sne_index_table_context[1];
    #endif /* __PHB_USIM_SUPPORT__ */

    #if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
          alpha_id_pinyin_PHB = alpha_id_pinyin_PHB_context[1];
    #endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */

        phb_current_mod = MOD_PHB_2;    
    }
}
#endif /* __GEMINI__ */