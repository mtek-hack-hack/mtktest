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
 * phb_handler_search.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is write handler of PHB module.
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
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

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
#include "phb_se.h"

#include "phb_common.h"
#include "phb_ilm.h"
#include "phb_utils.h"

#include "phb_handler_read.h"
#include "phb_handler_search.h"

#include "phb_sap.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_SEARCH_C_

static void phb_search_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_search_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block);
static match_result_enum phb_compare_tel_number(l4_addr_bcd_struct *given, l4_addr_bcd_struct *candidate);


/*****************************************************************************
 * FUNCTION
 *  phb_search_handler
 * DESCRIPTION
 *  This is phb_search_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_search_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEARCH);

    if (ilm_ptr != NULL)
    {
        l4cphb_search_req_struct *l4cphb_search_req;

        l4cphb_search_req = (l4cphb_search_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_search_confirm(PHB_ERRNO_BUSY, 0, l4cphb_search_req->src_id, MSG_ID_INVALID_TYPE, control_block);
            return;
        }

        control_block->src_id = l4cphb_search_req->src_id;

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if ((phb_ptr->state == PHB_STATE_READY) &&
            ((l4cphb_search_req->type == PHB_PHONEBOOK) ||
             (l4cphb_search_req->type == PHB_FDN) ||
             (l4cphb_search_req->type == PHB_BDN)) && ((l4cphb_search_req->pattern_tag == PHB_BYNAME) ||
    #ifdef __PHB_SORT_ENABLE__
                                                       (l4cphb_search_req->pattern_tag == PHB_BYNAME_EXACT) ||
    #endif 
                                                       (l4cphb_search_req->pattern_tag == PHB_BYNUMBER)))
        {
            if (control_block->proc_stage == SEARCH_NONE)
            {
                kal_bool is_more_candidates;
                l4_name_struct *alpha_id;

            #ifdef __PHB_SORT_ENABLE__
                l4_addr_bcd_struct *tel_number;
            #endif 

            /**
             * Here we borrow total_piggyback to store pattern_tag.
             * When used!?
             */
                /* control_block->total_piggyback = l4cphb_search_req->pattern_tag; */
                control_block->total_piggyback = l4cphb_search_req->total;

                /* Search by name, valid for both of PHB_PHONEBOOK, PHB_FDN and PHB_BDN */
                if ((l4cphb_search_req->pattern_tag == PHB_BYNAME) ||
                    (l4cphb_search_req->pattern_tag == PHB_BYNAME_EXACT))
                {
                    alpha_id = &l4cphb_search_req->pattern_value.alpha_id;
                    control_block->candidate_name_num_index = phb_se_search_by_name(
                                                                l4cphb_search_req->type,
                                                                (alpha_id_type*) alpha_id,
                                                                &control_block->candidate,
                                                                &is_more_candidates);

               /**
                * For SEARCH_BYNAME, no candidate is impossible.
                * Because a nearest one is always found,
                * therefore candidate_count is at least 1.
                */
                }

            #ifdef __PHB_SORT_ENABLE__
                /* Search by telephone number, only valid for PHB_PHONEBOOK */
                else if ((l4cphb_search_req->pattern_tag == PHB_BYNUMBER) && (l4cphb_search_req->type == PHB_PHONEBOOK))
                {
                    tel_number = &l4cphb_search_req->pattern_value.tel_number;
                    control_block->candidate_name_num_index = phb_se_search_by_tel_num(
                                                                l4cphb_search_req->type,
                                                                tel_number,
                                                                &control_block->candidate,
                                                                &is_more_candidates);

                }
            #endif /* __PHB_SORT_ENABLE__ */ 
                /* Illegal comination of parameters. */
                else
                {
                    phb_search_err_handler(NULL, control_block);
                    return;
                }

                /* Search telephone number in phonebook: nvram_ef_phb_lid and ADN */

                /* No candidate, great!! */
                if ((control_block->candidate == (kal_uint16) PHB_INVALID_VALUE) ||
                    (control_block->candidate_name_num_index == NULL))
                {
                    control_block->actual_count = 0;
                    phb_search_confirm(
                        PHB_ERRNO_SUCCESS,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

                /* Exactly only one candidate is found! Great!! */
            /**
             * Q: The query pattern may exceeds ALPHA_ID_DEPTH,
             *   why NOT exact match alpha_id, then retrieves the following
             *   entries begun from the index to that one?
             *
             * A: Though exact matching is possible, retrieves from that index is
             *   non-sense, because the sorted array is not precise, that means
             *   the following entries begun from that index could be erroneous.
             */
                if (l4cphb_search_req->pattern_tag == PHB_BYNAME)
                {
                    kal_uint16 index;

               /**
                * Search BYNAME, if alpha_id.name_length <= PHB_ALPHA_ID_DEPTH,
                * then there must be exactly one nearest hit!
                *
                * Note: hit must start from 1.
                */
                    index = control_block->candidate;

                    if (l4cphb_search_req->total < 1)
                    {
                        l4cphb_search_req->total = 1;
                    }

                    phb_control_block_set_IO(control_block, l4cphb_search_req->type, ++index, l4cphb_search_req->total);

                    if (phb_se_is_in_range(control_block->type, index, &control_block->total) == KAL_FALSE)
                    {
                        control_block->actual_count = 0;
                        phb_search_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block->cnf_msg_id,
                            control_block);
                        return;
                    }

                    /* Piggyback is ALWAYS required. */

               /**
                * Now we have to transform the state to a *FAKE* read state.
                * The fakes status ALWAYS read from index, instead of specific record.
                */

                    /* If any critial error occured. read_err_handler will handle it. */
                    if (phb_read_fake(control_block, NULL) == KAL_FALSE)
                    {
                        return;
                    }

                    /* Finally, faking complete....Now continue reading */
                    phb_read_continue(NULL, control_block);
                    return;
                }
            #ifdef __PHB_SORT_ENABLE__
                else if (l4cphb_search_req->pattern_tag == PHB_BYNAME_EXACT)
                {
                    kal_uint16 i, start, count = 0;
                    pindex_type *name_index;
                    data_entry_table_type *desc_table;

                    if (l4cphb_search_req->type == PHB_PHONEBOOK)
                    {
                        control_block->type = l4cphb_search_req->type;
                        name_index = (pindex_type*) & phb_ptr->indices.phb_index.name_index;
                        desc_table = (data_entry_table_type*) & phb_ptr->indices.phb_index.data_entry_table;
                    }
                    else
                    {
                        control_block->actual_count = 0;
                        phb_search_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block->cnf_msg_id,
                            control_block);
                        return;
                    }

                    for (i = control_block->candidate; i < name_index->used_count; i++)
                        if (phb_is_prefix(
                                (alpha_id_type*) & l4cphb_search_req->pattern_value.alpha_id,
                                (alpha_id_type*) & desc_table->table[name_index->table[i].position]. alpha_id))
                        {
                            break;
                        }

                    if (i == name_index->used_count)
                    {
                        /* NOT found any match */
                        control_block->actual_count = 0;
                        phb_search_confirm(
                            PHB_ERRNO_SUCCESS,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block->cnf_msg_id,
                            control_block);
                        return;
                    }
                    count++;
                    start = i;
                    for (i = start + 1; i < name_index->used_count; i++)
                        if (phb_is_prefix(
                                (alpha_id_type*) & l4cphb_search_req->pattern_value.alpha_id,
                                (alpha_id_type*) & desc_table->table[name_index->table[i].position]. alpha_id))
                        {
                            count++;
                        }
                    /* total "count" matches starting from "start" */

                    control_block->index = start + 1;
                    control_block->record_index = (kal_uint16) PHB_INVALID_VALUE;
                    if (count > 15)
                    {
                        count = 15;
                    }
                    control_block->total = count;
                    /* If any critial error occured. read_err_handler will handle it. */
                    if (phb_read_fake(control_block, NULL) == KAL_FALSE)
                    {
                        return;
                    }

                    /* Finally, faking complete....Now continue reading */
                    phb_read_continue(NULL, control_block);
                    return;
                }
            #endif /* __PHB_SORT_ENABLE__ */ 

                /* For PHB_BYNAME, more than 1 candidate exists, sigh, verification is necessary */

            /**
             * Even only exactly one candidate is found for searching BYNUMBER,
             * verification is still needed.
             */

            /**
             * Only search of PHB_BYNUMBER can reach here.
             *
             * Candidates of searching telephone number are selected.
             * Now verify them. So lousy..
             */

            /**
             * Initialize hit and same_count of control_block, also
             * increment index to candidate, since it begins from 1.
             */
                control_block->match_result = MATCH_FAIL;

                phb_search_fake(
                    control_block,
                    ilm_ptr,
                    l4cphb_search_req->type,
                    &l4cphb_search_req->pattern_value.tel_number);

                phb_search_continue(NULL, control_block);
            }
            /* error */
            else
            {
                phb_search_err_handler(NULL, control_block);
                return;
            }
        }
        /* error, either STATE_NOT_READY or incorrect type requested for searching */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            if (phb_ptr->state != PHB_STATE_READY)
            {
                control_block->actual_count = 0;
                phb_search_confirm(
                    PHB_ERRNO_NOT_READY,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
            else
            {
                phb_search_err_handler(NULL, control_block);
            }
            return;
        }

    }
    else
    {
        /* Verification over. */
        if (control_block->proc_stage == SEARCH_CONTINUE)
        {
         /**
          * Only search of PHB_BYNUMBER can reach here.
          * And no piggyback is provided, so confirmation can be sent back now.
          * Hence, if found, actual_count is 1 and will be transfered to `total' field of
          * confirmation primitive; otherwise it is 0.
          */

            /* No candidate matches! */
            if (control_block->actual_count == 0)
            {
                control_block->actual_count = 0;
                phb_search_confirm(
                    PHB_ERRNO_FAIL,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
            else
            {
                name_num_index_type *name_num_index = (name_num_index_type*) control_block->candidate_name_num_index;
                data_entry_struct *data_entry;
                l4cphb_phb_entry_array_struct *phb_entry_array;

                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;

                data_entry =
                    &name_num_index->data_entry_table.table[name_num_index->num_index.table[control_block->candidate].
                                                            position];
            /**
             * To reduce code size, another possible function which
             * searches index to name_index by index to num_index
             * is not implemented .
             */
                pdu_ptr = get_pdu_ptr(control_block->peer_buf_ptr, &pdu_length);
                phb_entry_array = ((l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr));
                phb_entry_array->array[0].index = phb_se_search_by_record_index_name(
                                                    control_block->type,
                                                    data_entry->storage,
                                                    data_entry->record_index,
                                                    &data_entry->alpha_id);
                phb_entry_array->array[0].index++;
                control_block->actual_count = 1;
                phb_search_confirm(
                    PHB_ERRNO_SUCCESS,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
        }
        /* error */
        else
        {
            phb_search_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_search_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_search_err_handler
 * DESCRIPTION
 *  This is phb_search_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_search_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEARCH_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    control_block->actual_count = 0;
    phb_search_confirm(
        PHB_ERRNO_FAIL,
        control_block->actual_count,
        control_block->src_id,
        control_block->cnf_msg_id,
        control_block);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_search_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_search_continue
 * DESCRIPTION
 *  This is phb_search_continue function of PHB module.
 *  
 *  Note:
 *  Only searching PHB_PHBONEBOOK and PHB_BYNUMBER can reach this function.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_search_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEARCH_CONT);

    /* It's time to write prepared dat */
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    /* Read confirmed. Now verify the entry! */
    else
    {
        /* Only PHB_BYNUMBER can reach here */

        /* Query pattern is stored in local_param_ptr */
        l4_addr_bcd_struct *given = (l4_addr_bcd_struct*) control_block->local_param_ptr;

        /* The just read back candidate is stored in control_block->data */
        phb_entry_struct *candidate_entry = (phb_entry_struct*) control_block->data;
        l4_addr_bcd_struct *candidate = &candidate_entry->tel_number;

        match_result_enum result = phb_compare_tel_number(given, candidate);

      /**
       * First we have to verify the candidate. The most possible candidate is
       * copied into the first element of l4cphb_phb_entry_array_struct stored
       * in control_block->peer_buf_ptr.
       */
      /**
       * Verification passed: perfect matched: CC/NDC/SN are all matched.
       * Finally we found it!
       */
        if ((result == MATCH_PERFECT) ||
         /**
          * Verification passed: partial matched: only NDC/SN are matched
          * Other candidate still have chances to match.
          * *Sigh*, Retain this candidate and go on verification.
          */
            (result == MATCH_PARTIAL))
        {
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            ++control_block->actual_count;

            pdu_ptr = get_pdu_ptr(control_block->peer_buf_ptr, &pdu_length);
            kal_mem_cpy(
                (phb_entry_struct*) & ((l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr))-> array[0],
                (void const*)candidate_entry,
                sizeof(phb_entry_struct));

            if (result == MATCH_PERFECT)
            {
                (*control_block->controller) (NULL, control_block);
                return;
            }
        }

        /* *Sigh*, Continue verification. */

        /* Verification complete, finally control can be returned back to controller */
        /* if (control_block->actual_count > control_block->candidate_count) */
        if (!phb_se_is_next_also_candidate(
                (name_num_index_type*) control_block->candidate_name_num_index,
                control_block->candidate,
                KAL_FALSE))
        {
            (*control_block->controller) (NULL, control_block);
        }

      /**
       * Still others to verify.
       * Since index, total is in ensured to be in range, tested in handler(), it is uncessary
       * to test it here.
       */
        else
        {
            name_num_index_type *name_num_index;
            data_entry_struct *data_entry;

            /* Set index field of next entry to read */
            control_block->index = ++control_block->candidate;

         /**
          * Read specific record for verification.
          */
            phb_control_block_set_IO(control_block, control_block->type, (kal_uint16) PHB_INVALID_VALUE, 1);

            /* set storage, record_index, primary_ID, and secondary_ID */
            name_num_index = (name_num_index_type*) control_block->candidate_name_num_index;
            data_entry =
                &name_num_index->data_entry_table.table[name_num_index->num_index.table[control_block->candidate].
                                                        position];

            if (phb_se_set_control_block(
                    control_block,
                    OP_READ,
                    data_entry->storage,
                    data_entry->record_index) == KAL_FALSE)
            {
                phb_search_err_handler(NULL, control_block);
                return;
            }

            control_block->proc_stage = SEARCH_CONTINUE;
            control_block->data = (kal_uint8*) & control_block->temp_entry;
            control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

            phb_issue_IO_read(control_block);
            return;
        }
    }
}   /* end of phb_search_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_search_confirm
 * DESCRIPTION
 *  This is phb_search_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cnf_msg_id          [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_search_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;
    peer_buff_struct *peer_buf_ptr = NULL;

    kal_uint16 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEARCH_CNF, result, actual_count, src_id, cnf_msg_id);

    /* First we release local parameter. */
    if ((result != PHB_ERRNO_BUSY) && (control_block->local_param_ptr != NULL))
    {
        free_ctrl_buffer(control_block->local_param_ptr);
    }

    if ((result == PHB_ERRNO_BUSY) || (control_block->cnf_msg_id == MSG_ID_L4CPHB_SEARCH_REQ))
    {
        l4cphb_search_cnf_struct *l4cphb_search_cnf;

        l4cphb_search_cnf = (l4cphb_search_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_search_cnf_struct),
                                                            TD_CTRL);
        l4cphb_search_cnf->total = actual_count;
        l4cphb_search_cnf->src_id = src_id;
        l4cphb_search_cnf->result = result;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_search_cnf->cause = control_block->cause;

        if (result == PHB_ERRNO_BUSY)
        {

            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SEARCH_CNF, (local_para_struct*) l4cphb_search_cnf, NULL);
            return;
        }

        local_param_ptr = (local_para_struct*) l4cphb_search_cnf;

        msg_id = MSG_ID_L4CPHB_SEARCH_CNF;
    }

   /**
    * Under ADN mode, only when is_retrieve is true and searching into
    * physical storage device is required will call search_continue(), which
    * in consequence results in this search_confirm() is invoked.
    *
    * Since it is ADN mode, no matter the search result is,
    * the approval result is ALWAYS success!!
    */
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_APPROVE_REQ)
    {
        l4cphb_approve_cnf_struct *l4cphb_approve_cnf;

        l4cphb_approve_cnf = (l4cphb_approve_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_approve_cnf_struct),
                                                            TD_CTRL);
        l4cphb_approve_cnf->result = PHB_ERRNO_SUCCESS;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_approve_cnf->cause = control_block->cause;

        l4cphb_approve_cnf->type = control_block->type;
        l4cphb_approve_cnf->src_id = control_block->src_id;

        local_param_ptr = (local_para_struct*) l4cphb_approve_cnf;

        msg_id = MSG_ID_L4CPHB_APPROVE_CNF;
    }

    /* EXCEPTION cannot reach here */
    if (control_block->peer_buf_ptr != NULL)
    {
        if (control_block->actual_count > 0)
        {
            peer_buf_ptr = (peer_buff_struct*) control_block->peer_buf_ptr;
            control_block->peer_buf_ptr = NULL;
        }
        else
        {
            free_ctrl_buffer(control_block->peer_buf_ptr);
            peer_buf_ptr = NULL;
        }
        control_block->need_free_peer = KAL_FALSE;
    }

    phb_free_control_block(control_block);

    phb_send_ilm(MOD_L4C, msg_id, local_param_ptr, peer_buf_ptr);
}   /* end of phb_search_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_tel_number
 * DESCRIPTION
 *  This is phb_compare_tel_number function of PHB module.
 *  
 *  Algorightm:
 *  
 *  1> given => international:               +886-2-12345
 *  1-1> candidate => international:      +886-2-12345  match!!
 *  1-2> candidate => non-international:     0-2-12345  match!!
 *  
 *  2> given => non-international:              0-2-12345
 *  1-1> candidate => international:      +886-2-12345  match!!
 *  1-2> candidate => non-international:     0-2-12345  match!!
 * PARAMETERS
 *  given           [?]         
 *  candidate       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static match_result_enum phb_compare_tel_number(l4_addr_bcd_struct *given, l4_addr_bcd_struct *candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;
    kal_uint16 given_cc_index, candidate_cc_index;
    kal_uint16 given_cc_offset, candidate_cc_offset;
    kal_bool given_flag_bcd = KAL_TRUE, candidate_flag_bcd = KAL_TRUE;
    kal_uint8 given_bcd, candidate_bcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Here only compares only differentiable digits.
     * International code issues are left to caller to decide.
     * Note that the returned offset is BCD digit offset, instead of byte offset.
     */
    given_cc_offset = phb_se_get_differntiable_digits(&given->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET], &given_cc_index);
    candidate_cc_offset = phb_se_get_differntiable_digits(&candidate->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET], &candidate_cc_index);

   /** Cannot shortcut return by unequal length of differentiable digits!!
    * Because each digit must be compared until a `p' digit is found!!
    */

   /**
    * If position is even, flag must be adjusted to false for
    * get_next_bcd_digit() to retrieve second bcd
    */
    if (given_cc_offset & 1)
    {
        given_flag_bcd = KAL_FALSE;
    }
    if (candidate_cc_offset & 1)
    {
        candidate_flag_bcd = KAL_FALSE;
    }

    /* Position is BCD-digit offset, it must be adjusted byte offset */
    given_cc_offset = given_cc_offset >> 1;
    candidate_cc_offset = candidate_cc_offset >> 1;

    result = MATCH_PARTIAL;
    while ((given_cc_offset < (given->addr_length - L4_ADDR_BCD_TON_NPI_SIZE)) &&
           (candidate_cc_offset < (candidate->addr_length - L4_ADDR_BCD_TON_NPI_SIZE)))
    {
        given_cc_offset = get_next_bcd_digit(
                            &given->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            given_cc_offset,
                            &given_flag_bcd,
                            &given_bcd);
        candidate_cc_offset = get_next_bcd_digit(
                                &candidate->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                candidate_cc_offset,
                                &candidate_flag_bcd,
                                &candidate_bcd);

        /* Compare not more than number of valid digits of given phone number. */
        if (given_bcd >= DN_VALID_DIGIT_LIMIT)
        {
            break;
        }

        if (given_bcd != candidate_bcd)
        {
            result = MATCH_FAIL;
            break;
        }
    }

    if ((result == MATCH_PARTIAL) && (
                                         /* Non-internation code, and all matches */
                                         ((given_cc_index == (kal_uint16) PHB_INVALID_VALUE) &&
                                          (candidate_cc_index == (kal_uint16) PHB_INVALID_VALUE)) ||
                                         /* Internation code, and all matches */
                                         ((given_cc_index != (kal_uint16) PHB_INVALID_VALUE) &&
                                          (candidate_cc_index != (kal_uint16) PHB_INVALID_VALUE) &&
                                          (given_cc_index == candidate_cc_index))))
    {
        result = MATCH_PERFECT;
    }

    return result;
}   /* end of phb_search_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_search_fake
 * DESCRIPTION
 *  This is phb_read_fake function of PHB module.
 *  Fakes reading state to meet piggyback requirement of write, delete operation.
 *  
 *  Prerequisite:
 *  1. Candidates must be selected first.
 *  2. phb_query_method_enum must be set to control_block->piggyback
 *  3. One entry of l4cphb_phb_entry_array_struct is always allocated
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr             [IN]        The primitives
 *  type                [IN]        
 *  given_pattern       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_search_fake(
        control_block_type *control_block,
        ilm_struct *ilm_ptr,
        phb_type_enum type,
        l4_addr_bcd_struct *given_pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_phb_entry_array_struct *phb_entry_array;
    l4_addr_bcd_struct *num_pattern;
    name_num_index_type *name_num_index;
    data_entry_struct *data_entry;
    peer_buff_struct *peer_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEARCH_FAKE);

   /**
    * First, allocate memory to temporarily store given entry,
    * since we have to verify telephone number, and put it into local paramter.
    *
    * Don't forget to release it!
    */
    num_pattern = (l4_addr_bcd_struct*) get_ctrl_buffer(sizeof(l4_addr_bcd_struct));
    kal_mem_cpy(num_pattern, (void const*)given_pattern, sizeof(l4_addr_bcd_struct));

    phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, 1);
    control_block->need_free_peer = KAL_TRUE;

   /**
    * Read SOP:
    * phb_control_block_set_param(),
    * phb_control_block_set(),
    * phb_control_block_set_IO(),
    * se_control_block()
    */
    /* num_pattern is temporarily stored in local_param_ptr */
    phb_control_block_set_param(control_block, SEARCH_CONTINUE, num_pattern, peer_buf_ptr);
    phb_control_block_set(
        control_block,
        phb_search_continue,
        phb_search_handler,
        phb_search_err_handler,
        SEARCH_CONTINUE);

   /**
    * Read specific record for verification.
    */
    phb_control_block_set_IO(control_block, type, (kal_uint16) PHB_INVALID_VALUE, 1);

    /* set storage, record_index, primary_ID, and secondary_ID */
    name_num_index = (name_num_index_type*) control_block->candidate_name_num_index;
    data_entry =
        &name_num_index->data_entry_table.table[name_num_index->num_index.table[control_block->candidate].position];

    phb_se_set_control_block(control_block, OP_READ, data_entry->storage, data_entry->record_index);

   /**
    * Since phb_se_set_control_block() modifies control_block->proc_stage,
    * it has to be restored.
    */
    control_block->proc_stage = SEARCH_CONTINUE;

    control_block->data = (kal_uint8*) & control_block->temp_entry;
    control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
}

