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
 * phb_handler_read.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup handler of PHB module.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_enums.h"

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
#include "phb_utils.h"
#include "phb_ilm.h"
/* SIM access */
#include "phb_sim_access.h"
/* NVRAM access */
#include "phb_nvram_access.h"

#include "phb_handler_read.h"

#include "phb_sap.h"
#include "phb_se.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_READ_C_

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);
static void phb_read_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_read_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block);
static kal_bool phb_is_read_param_valid(l4cphb_read_req_struct *l4cphb_read_req);

static void phb_read_ln_confirm(
                phb_errno_enum result,
                nvram_ef_phb_ln_struct *record2,
                kal_uint8 src_id,
                control_block_type *control_block);


/*****************************************************************************
 * FUNCTION
 *  phb_read_handler
 * DESCRIPTION
 *  This is phb_read_handler function of PHB module.
 *  Read SOP:
 *  phb_control_block_set_param(),
 *  phb_control_block_set(),
 *  phb_control_block_set_IO(),
 *  se_control_block()
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ);

    if (ilm_ptr != NULL)
    {
        l4cphb_read_req_struct *l4cphb_read_req;

        l4cphb_read_req = (l4cphb_read_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_read_confirm(PHB_ERRNO_BUSY, 0, l4cphb_read_req->src_id, ilm_ptr->msg_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_read_req->src_id;
        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == READ_NONE)
            {
                l4cphb_phb_entry_array_struct *phb_entry_array;
                phb_entry_struct *phb_entry;
                peer_buff_struct *peer_buf_ptr;

                /* Invalid parameters */
                if (phb_is_read_param_valid(l4cphb_read_req) == KAL_FALSE)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

                /* If request total is 0, or nothing can be read, return READ_SUCCESS with total = 0 */
                if (l4cphb_read_req->total == 0)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

            /**
             * Read SOP:
             * phb_control_block_set_param(),
             * phb_control_block_set(),
             * phb_control_block_set_IO(),
             * se_control_block()
             */
                control_block->total = l4cphb_read_req->total;
                phb_entry_array =
                    (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
                control_block->need_free_peer = KAL_TRUE;
                phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);

                phb_entry = &phb_entry_array->array[0];

                if (l4cphb_read_req->type == PHB_ECC)
                {
                    kal_uint8 i;
                    kal_uint8 index;
                    phb_entry_struct *phb_entry_ith = phb_entry;

                    if (l4c_is_src_from_rmmi(control_block->src_id))  // for CPBR (EN)
                    {
                    	  index = (kal_uint8) l4cphb_read_req->record_index - 1;
                    }
                    else
                    {
                        index = (kal_uint8) l4cphb_read_req->index - 1;
                    }
                    control_block->type = PHB_ECC;
                    control_block->total = 0;

                    /* phb_ptr->ecc.num_ecc now contains number of records */
                    for (i = index; (i < phb_ptr->ecc.num_ecc) && (control_block->total < l4cphb_read_req->total); ++i)
                    {
                        kal_uint16 len;

                        phb_entry_ith->storage = PHB_SIM;

                        len = bcd_len(&phb_ptr->ecc.ecc[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
                        len = (len + 1) >> 1;

                        phb_entry_ith->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                        phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                        kal_mem_cpy(
                            &phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (void const*)&phb_ptr->ecc.ecc[i * NUM_OF_BYTE_ECC],
                            len);

                        ++control_block->total;
                        phb_entry_ith->tel_number.addr_bcd[phb_entry_ith->tel_number.addr_length] = 0xff;
                        if (l4c_is_src_from_rmmi(control_block->src_id)) // for CPBR (EN)
                        {
                            phb_entry_ith->record_index = i + 1;
                        }
                        ++phb_entry_ith;
                    }
                    phb_entry_array->no_array = (kal_uint8) (control_block->actual_count = control_block->total);

                    phb_read_confirm(
                        PHB_ERRNO_READ_SUCCESS,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }
                else
                {
                    phb_control_block_set(
                        control_block,
                        phb_read_continue,
                        phb_read_handler,
                        phb_read_err_handler,
                        READ_NONE);
                    /* This function sets actual_count */
                    phb_control_block_set_IO(
                        control_block,
                        l4cphb_read_req->type,
                        l4cphb_read_req->index,
                        l4cphb_read_req->total);

                    /* Set proc_stage, storage, record_index, primary_ID, and secondary_ID */
                    if (phb_se_set_control_block(
                            control_block,
                            OP_READ,
                            l4cphb_read_req->storage,
                            l4cphb_read_req->record_index) == KAL_FALSE)
                    {
                        phb_read_err_handler(NULL, control_block);
                        return;
                    }
                    control_block->data = (kal_uint8*) phb_entry;
                    control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                    phb_read_continue(NULL, control_block);
                }
            }
            /* error */
            else
            {
                phb_read_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_read_confirm(
                PHB_ERRNO_NOT_READY,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
            return;
        }

    }
    else
    {
        if (control_block->proc_stage == READ_CONTINUE)
        {
            phb_read_confirm(
                PHB_ERRNO_READ_SUCCESS,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
        }
        else if (control_block->proc_stage == READ_CONTINUE_SPECIFIC)
        {
            if (control_block->data == NULL)
            {
                phb_read_confirm(
                    PHB_ERRNO_READ_EMPTY,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
            else
            {
                phb_read_confirm(
                    PHB_ERRNO_READ_SUCCESS,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
        }

        /* error */
        else
        {
            phb_read_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_read_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_read_err_handler
 * DESCRIPTION
 *  This is phb_read_err_handler function of PHB module.
 *  
 *  Requirement:
 *  Error handlers should destruct control_block.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 packed_peer_buff_len;
    kal_uint8 *pdu_ptr;
    l4cphb_phb_entry_array_struct *pdu_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */

    pdu_ptr = get_pdu_ptr(control_block->peer_buf_ptr, &packed_peer_buff_len);

    pdu_data = (l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);
    pdu_data->no_array = control_block->actual_count;
    control_block->actual_count = 0;
    phb_read_confirm(
        PHB_ERRNO_READ_FAIL,
        control_block->actual_count,
        control_block->src_id,
        control_block->cnf_msg_id,
        control_block);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_read_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_read_continue
 * DESCRIPTION
 *  This is phb_read_continue function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_CONT);

    if (ilm_ptr == NULL)
    {
        if ((control_block->cnf_msg_id != MSG_ID_L4CPHB_READ_REQ) &&
            (control_block->actual_count >= control_block->total))
        {
            phb_read_confirm(
                PHB_ERRNO_SUCCESS,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
        }

        else
        {
            phb_issue_IO_read(control_block);
        }
    }
    else
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

      /**
       * User specifies physical location to read;
       * therefore, the read phb_entry could be NULL.
       */
        if ((control_block->index == (kal_uint16) PHB_INVALID_VALUE) &&
            (control_block->record_index != (kal_uint16) PHB_INVALID_VALUE))
        {
         /**
          * Here, control_block->data could be NULL, if read back data is empty.
          */
         /**
          * Since alpha_id's stored in index are truncated,
          * phb_entry->alpha_id must be truncated, too, if necessary;
          * so that comparison could work properly.
          */
            if (phb_entry != NULL)
            {
                phb_entry->index = phb_se_get_index_by_record_index(
                                    control_block->type,
                                    control_block->storage,
                                    control_block->record_index);
                /* phb_se_search_by_record_index_name(control_block->type,
                   control_block->storage,
                   control_block->record_index,
                   (alpha_id_type*)&phb_entry->alpha_id); */
                /* phb_entry->index++; */

                /* Read complete, now return control back to controller */
                control_block->actual_count = 1;
            }

            (*control_block->controller) (NULL, control_block);
        }

      /**
       * User doesn't specify physical location to read,
       * therefore, the read phb_entry is always valid!!
       */
        else
        {

         /**
          * Unless someone modifies the underlying storage
          * while PHB is reading, the phb_entry just read is always valid!
          * However, prevent this WEIRD case for safety.
          */
            if (phb_entry == NULL)
            {
                phb_read_err_handler(NULL, control_block);
                return;
            }

            /* Set index field of next entry to read */
            phb_entry->index = (control_block->index)++;

            /* Read complete, now return control back to controller */
            if (++control_block->actual_count >= control_block->total)
            {
                (*control_block->controller) (NULL, control_block);
            }
            /* Still others to read */
            else
            {
                /* set storage, record_index, primary_ID, and secondary_ID */
                if (phb_se_set_control_block(
                        control_block,
                        OP_READ,
                        control_block->storage,
                        control_block->record_index) == KAL_FALSE)
                {
                    phb_read_err_handler(NULL, control_block);
                    return;
                }

                /* shift next read address */
                control_block->data = (kal_uint8*) (((phb_entry_struct*) control_block->data) + 1);
                /* 20040918, Retreive lenght again in case file id change */
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                phb_issue_IO_read(control_block);
            }
        }
    }
}   /* end of phb_read_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_read_confirm
 * DESCRIPTION
 *  This is phb_read_confirm function of PHB module.
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
static void phb_read_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type msg_id = MSG_ID_L4CPHB_READ_CNF;   /* avoid compilation warning */
    local_para_struct *local_param_ptr = NULL;
    peer_buff_struct *peer_buf_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_CNF, result, actual_count, src_id, cnf_msg_id);

    if ((result == PHB_ERRNO_BUSY) || (control_block->cnf_msg_id == MSG_ID_L4CPHB_READ_REQ))
    {
        l4cphb_read_cnf_struct *l4cphb_read_cnf;

        l4cphb_read_cnf = (l4cphb_read_cnf_struct*) construct_local_para(sizeof(l4cphb_read_cnf_struct), TD_CTRL);
        l4cphb_read_cnf->total = actual_count;
        l4cphb_read_cnf->src_id = src_id;

        l4cphb_read_cnf->result = result;

        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_CNF, (local_para_struct*) l4cphb_read_cnf, NULL);
            return;
        }

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_read_cnf->cause = control_block->cause;

        msg_id = MSG_ID_L4CPHB_READ_CNF;
        local_param_ptr = (local_para_struct*) l4cphb_read_cnf;
    }
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_WRITE_REQ)
    {
        l4cphb_write_cnf_struct *l4cphb_write_cnf;

        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, control_block->actual_count, control_block->src_id);

        l4cphb_write_cnf = (l4cphb_write_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->result = result;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_write_cnf->cause = control_block->cause;

        l4cphb_write_cnf->total = control_block->actual_count;
        l4cphb_write_cnf->src_id = control_block->src_id;
        l4cphb_write_cnf->old_index = control_block->candidate;

        msg_id = MSG_ID_L4CPHB_WRITE_CNF;
        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;
    }
#ifdef __PHB_USIM_SUPPORT__
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_WRITE_USIM_REQ)
    {
        l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;

        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, control_block->actual_count, control_block->src_id);

        l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_write_usim_cnf_struct),
                                                            TD_CTRL);
        l4cphb_write_cnf->result = result;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_write_cnf->cause = control_block->cause;

        l4cphb_write_cnf->total = control_block->actual_count;
        l4cphb_write_cnf->src_id = control_block->src_id;
        l4cphb_write_cnf->old_index = control_block->candidate;

        msg_id = MSG_ID_L4CPHB_WRITE_USIM_CNF;
        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;
    }
#endif /* __PHB_USIM_SUPPORT__ */ 
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_DELETE_REQ)
    {
        l4cphb_delete_cnf_struct *l4cphb_delete_cnf;

        kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CNF, result, control_block->actual_count, control_block->src_id);

        l4cphb_delete_cnf = (l4cphb_delete_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_delete_cnf_struct),
                                                            TD_CTRL);
        l4cphb_delete_cnf->result = result;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_delete_cnf->cause = control_block->cause;

        l4cphb_delete_cnf->total = control_block->actual_count;
        l4cphb_delete_cnf->src_id = control_block->src_id;
        l4cphb_delete_cnf->old_index = control_block->candidate;

        msg_id = MSG_ID_L4CPHB_DELETE_CNF;
        local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;
    }
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_SEARCH_REQ)
    {
        l4cphb_search_cnf_struct *l4cphb_search_cnf;

        kal_trace(
            TRACE_FUNC,
            FUNC_PHB_SEARCH_CNF,
            result,
            control_block->actual_count,
            control_block->src_id,
            control_block->cnf_msg_id);

        l4cphb_search_cnf = (l4cphb_search_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_search_cnf_struct),
                                                            TD_CTRL);
        l4cphb_search_cnf->result = result;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_search_cnf->cause = control_block->cause;

        l4cphb_search_cnf->total = control_block->actual_count;
        l4cphb_search_cnf->src_id = control_block->src_id;

        msg_id = MSG_ID_L4CPHB_SEARCH_CNF;
        local_param_ptr = (local_para_struct*) l4cphb_search_cnf;
    }

    /* Pack from control_block->peer_buf_ptr */
    if (control_block->peer_buf_ptr != NULL)
    {
        peer_buf_ptr = (peer_buff_struct*) control_block->peer_buf_ptr;
        control_block->peer_buf_ptr = NULL;
    }
    control_block->need_free_peer = KAL_FALSE;

    phb_free_control_block(control_block);

    phb_send_ilm(MOD_L4C, (kal_uint16) msg_id, local_param_ptr, peer_buf_ptr);
}   /* end of phb_read_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_read_fake
 * DESCRIPTION
 *  This is phb_read_fake function of PHB module.
 *  Fakes reading state to meet piggyback requirement of write, delete operation.
 *  This function just fakes valid read operation by setting control_block
 *  correctly.
 *  
 *  It DOES NOT send any IO primitives. It is left for caller to judege which
 *  function to call for issueing prmitives.
 *  Also keep original prmitive ID.
 *  
 *  Once this function is called, caller should completely leave program
 *  control to phb_handler_read.c; that is, read handler will take over
 *  control, hance as long as caller encounters any error, just return,
 *  since read handler will handle them in advance.
 *  
 *  Prerequisite:
 *  // 1. control_block->length is not set. Caller should ensure to set length correctly.
 *  1. length will be set by this function. Caller should not set it.
 *  2. phb_control_block_set_IO() must be called in advance.
 *  3. Caller must set control_block->total.
 *  4. The given index MUST start from 1
 *  5. phb_se_is_in_range() should be called in advance.
 *  6. control_block->cnf_msg_id must be set!!
 * PARAMETERS
 *  control_block       [?]         
 *  cached_entry        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_read_fake(control_block_type *control_block, phb_entry_struct *cached_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Now we have to transform the state to a *FAKE* read state. */
    l4cphb_phb_entry_array_struct *phb_entry_array;
    peer_buff_struct *peer_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_FAKE);

   /**
    * For write operation, the just written entry is still there!
    * It's in control_block->temp_entry and passed in as a cached_entry.
    */

    /* phb_se_is_in_range ?? */

    /* First, construct the array for piggyback reading */
    phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
    control_block->need_free_peer = KAL_TRUE;
    phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);

    phb_control_block_set(control_block, phb_read_continue, phb_read_handler, phb_read_err_handler, READ_CONTINUE);
   /**
    * Next, set_IO() is unnecessary, since it MUST be set by caller ALREADY.
    */

    /* This function is called for piggybacked write */
    if (cached_entry != NULL)
    {
        /* Copy the just written entry to array */
        kal_mem_cpy(&phb_entry_array->array[0], (void const*)cached_entry, sizeof(phb_entry_struct));

      /**
       * Since index of the just written entry is translated,
       * increment the index will make the reading from next entry of
       * the just written entry.
       */
        control_block->actual_count = 1;

        /* Reset record_index */
        control_block->record_index = (kal_uint16) PHB_INVALID_VALUE;
    }
    /* This function is called for piggybacked delete, or search */
    else
    {
        control_block->actual_count = 0;
    }

    /* Cannot but read physical storage for piggyback opeartion. */
    if (control_block->actual_count < control_block->total)
    {
      /**
       * Try to set control_block for next index; this is only needed when
       * cached_entry exists.
       */
        if (cached_entry != NULL)
        {
            control_block->index = cached_entry->index + 1;
        }

        /* Assign storage and record_index */
        /* set storage, record_index, primary_ID, and secondary_ID */
        if (phb_se_set_control_block(
                control_block,
                OP_READ,
                control_block->storage,
                control_block->record_index) == KAL_FALSE)
        {
            phb_read_err_handler(NULL, control_block);
            return KAL_FALSE;
        }

        /* Assign control_block->data */
        /* This function is called for piggybacked write */
        if (cached_entry != NULL)
        {
            /* shift next read address */
            control_block->data = (kal_uint8*) & phb_entry_array->array[1];
        }
        else
        {
            control_block->data = (kal_uint8*) & phb_entry_array->array[0];
        }

        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
    }

   /**
    * If there is exactly only one to be piggybacked, which is already conveyed
    * in cache_entry, nothing is done here. Instead, read_continue() will
    * response back without reading phyiscal storage any further.
    */

    return KAL_TRUE;
}   /* end of phb_read_fake */


/*****************************************************************************
 * FUNCTION
 *  phb_is_read_param_valid
 * DESCRIPTION
 *  2 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  READ           valid    n     ignored  0xFFFF         From PHB maintained index, read n entries.
 *  0xFFFF   1     valid    valid          Read a entry stored in {`storage', `record_index'}.The index of that entry,
 *  maintained by PHB, is also returned in confirmation primitive.
 * PARAMETERS
 *  l4cphb_read_req     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_is_read_param_valid(l4cphb_read_req_struct *l4cphb_read_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Is type valid ? */
    if (!phb_is_type_valid(l4cphb_read_req->type))
    {
        return KAL_FALSE;
    }

    /* Should be scenario 1 */
    /* index must be valid, total must be valid */
    if (l4cphb_read_req->record_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        /* Now check whether index, total fall into valid range of that type */
        return phb_se_is_in_range(l4cphb_read_req->type, l4cphb_read_req->index, &l4cphb_read_req->total);
    }
    /* Read specific record of certain storage is required */
    else
    {
        data_desc_enum type = DATA_DESC_PHB;

        /* Using case 2 of read to read ECC, MSISDN, and SDN is forbidden!  */
        if (((l4cphb_read_req->type == PHB_ECC) ||
            (l4cphb_read_req->type == PHB_MSISDN) || (l4cphb_read_req->type == PHB_SDN))
            && !l4c_is_src_from_rmmi(l4cphb_read_req->src_id))
        {
            return KAL_FALSE;
        }

        /* Total must be 1 for this operation */
        if (l4cphb_read_req->total != 1)
        {
            return KAL_FALSE;
        }

      /**
       * Since specific record is specified,
       * validity must be checked through data_desc
       */
        if (l4cphb_read_req->type == PHB_PHONEBOOK)
        {
            if (l4cphb_read_req->storage == PHB_SIM)
            {
                type = DATA_DESC_ADN;
            }
            else if (l4cphb_read_req->storage == PHB_NVRAM)
            {
                type = DATA_DESC_PHB;
            }
            else
            {
                return KAL_FALSE;
            }
        }
        else if (l4cphb_read_req->type == PHB_FDN)
        {
            type = DATA_DESC_FDN;
        }
        else if (l4cphb_read_req->type == PHB_BDN)
        {
            type = DATA_DESC_BDN;
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if (l4cphb_read_req->type == PHB_GAS)
        {
            type = DATA_DESC_GAS;
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 

        if (l4cphb_read_req->record_index > phb_data_desc_get_record_num(type))
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}   /* end of phb_is_read_param_valid */


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_handler
 * DESCRIPTION
 *  This is phb_read_ln_handler function of PHB module.
 *  Handles read last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
        if (control_block == NULL)
        {
            l4cphb_read_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_read_ln_req_struct*) ilm_ptr->local_para_ptr;
            control_block = phb_alloc_control_block();
            /* Cannot allocate, means that PHB is still operating. Reject request! */
            if (control_block == NULL)
            {
                phb_read_ln_confirm(PHB_ERRNO_BUSY, NULL, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        if (control_block->proc_stage == READ_LN_NONE)
        {
            l4cphb_read_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_read_ln_req_struct*) ilm_ptr->local_para_ptr;

            control_block->proc_stage = READ_LN_READ;
            control_block->IO_cnf_receive = phb_read_ln_handler;

            control_block->type = msg_ptr->type;
            control_block->src_id = msg_ptr->src_id;

            if (msg_ptr->type == PHB_LND)
            {
                control_block->seg_total = PHB_TOT_LND_LIDS;
                control_block->secondary_ID = PHB_LND_LID_START;
            }
            else if (msg_ptr->type == PHB_LNM)
            {
                control_block->seg_total = PHB_TOT_LNM_LIDS;
                control_block->secondary_ID = PHB_LNM_LID_START;
            }
            else if (msg_ptr->type == PHB_LNR)
            {
                control_block->seg_total = PHB_TOT_LNR_LIDS;
                control_block->secondary_ID = PHB_LNR_LID_START;
            }
            else
            {
                phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
                return;
            }
            ASSERT(msg_ptr->seq_id <= 10);
            control_block->secondary_ID += (msg_ptr->seq_id - 1);
        #ifdef __GEMINI__
            if (phb_current_mod == MOD_PHB_2)
            {
                control_block->secondary_ID += PHB_TOTAL_LN_LID;
            }
        #endif /* __GEMINI__ */
        #if (MAX_PHB_LN_ENTRY > 20)
            control_block->actual_count = (kal_uint16) phb_get_ln_total_entry((kal_uint8) control_block->type);
            if (control_block->actual_count < (msg_ptr->seq_id - 1) * PHB_MAX_LN_ENTRIES)
            {
                ASSERT(0);
            }
            else
            {
                control_block->actual_count -= ((msg_ptr->seq_id - 1) * PHB_MAX_LN_ENTRIES);
            }
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

            phb_read_ln_from_nvram(control_block);
            return;
        }
        else if (control_block->proc_stage == READ_LN_READ)
        {
            kal_uint16 length;
            nvram_read_cnf_struct *msg_ptr = NULL;
            nvram_ef_phb_ln_struct *pdu_data;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                control_block->IO_cnf_receive = phb_read_ln_handler;

                pdu_data = (nvram_ef_phb_ln_struct*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);

                /* keep first read data in control_block->data */
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (kal_uint8*) ilm_ptr->peer_buff_ptr;
                control_block->total = pdu_data->no_entry;

                phb_read_ln_confirm(PHB_ERRNO_SUCCESS, NULL, control_block->src_id, control_block);
                return;
            }
            else
            {
                phb_read_ln_confirm(PHB_ERRNO_READ_FAIL, NULL, control_block->src_id, control_block);
            }
        }
        else
        {
            phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
        }
    }
    else
    {
        phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_confirm
 * DESCRIPTION
 *  This is phb_read_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  record2             [?]         
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_ln_confirm(
                phb_errno_enum result,
                nvram_ef_phb_ln_struct *record2,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_read_ln_cnf_struct *param_ptr;
    peer_buff_struct *peer_buff_ptr = NULL;
    l4cphb_phb_ln_entry_array_struct *pdu_stream_ptr;
    nvram_ef_phb_ln_struct *src_ptr;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_read_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_read_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    param_ptr->total = 0;

    if (control_block != NULL)
    {
    #ifdef __GEMINI__
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID -= PHB_TOTAL_LN_LID;
        }
    #endif /* __GEMINI__ */

        if (control_block->secondary_ID >= PHB_LND_LID_START && control_block->secondary_ID < PHB_LNM_LID_START)
        {
            param_ptr->type = PHB_LND;
        }
        else if (control_block->secondary_ID >= PHB_LNM_LID_START && control_block->secondary_ID < PHB_LNR_LID_START)
        {
            param_ptr->type = PHB_LNM;
        }
        else if (control_block->secondary_ID >= PHB_LNR_LID_START && control_block->secondary_ID <= PHB_TOTAL_LN_LID)
        {
            param_ptr->type = PHB_LNR;
        }
    }
    if ((result == PHB_ERRNO_SUCCESS) && (control_block->total > 0))
    {
        param_ptr->total = control_block->total;
        pdu_stream_ptr = (l4cphb_phb_ln_entry_array_struct*)
            l4cphb_alloc_ln_peer_buf(&peer_buff_ptr, param_ptr->total);

        src_ptr = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &length);

        /* pdu_stream_ptr->no_array = param_ptr->total;
           pdu_stream_ptr->array = (phb_ln_entry_struct *)get_ctrl_buffer
           (sizeof (phb_ln_entry_struct) * param_ptr->total); */

        kal_mem_cpy(pdu_stream_ptr->array, &src_ptr->array[0], sizeof(phb_ln_entry_struct) * src_ptr->no_entry);
        if (record2 != NULL)
        {
            kal_mem_cpy(
                &pdu_stream_ptr->array[src_ptr->no_entry],
                &record2->array[0],
                sizeof(phb_ln_entry_struct) * record2->no_entry);
        }
    }
#if (MAX_PHB_LN_ENTRY >10)
    if (control_block && (control_block->total == PHB_MAX_LN_ENTRIES) &&
    #if (MAX_PHB_LN_ENTRY > 20)
        control_block->actual_count > control_block->total)
    #else
        (((control_block->secondary_ID == 1) && (control_block->type == PHB_LND)) ||
        ((control_block->secondary_ID == 3) && (control_block->type == PHB_LNM)) ||
        ((control_block->secondary_ID == 5) && (control_block->type == PHB_LNR))))
    #endif
    {
        param_ptr->more_data = KAL_TRUE;
    }
    else
#endif
    {
        param_ptr->more_data = KAL_FALSE;
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_LN_CNF, param_ptr, peer_buff_ptr);
    /* if (peer_buff_ptr != NULL)
       free_ctrl_buffer (pdu_stream_ptr->array); */

    if (control_block != NULL)
    {
        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        phb_free_control_block(control_block);
    }
}   /* end of phb_read_ln_confirm */


#ifdef __PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_read_email_handler
 * DESCRIPTION
 *  This is phb_read_handler function of PHB module.
 *  Read SOP:
 *  phb_control_block_set_param(),
 *  phb_control_block_set(),
 *  phb_control_block_set_IO(),
 *  se_control_block()
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_email_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ);

    if (ilm_ptr != NULL)
    {
        l4cphb_read_req_struct *l4cphb_read_req;

        l4cphb_read_req = (l4cphb_read_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_read_confirm(PHB_ERRNO_BUSY, 0, l4cphb_read_req->src_id, ilm_ptr->msg_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_read_req->src_id;
        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == READ_NONE)
            {
                l4cphb_phb_entry_array_struct *phb_entry_array;
                phb_entry_struct *phb_entry;
                peer_buff_struct *peer_buf_ptr;

                /* Invalid parameters */
                if (phb_is_read_param_valid(l4cphb_read_req) == KAL_FALSE)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

                /* If request total is 0, or nothing can be read, return READ_SUCCESS with total = 0 */
                if (l4cphb_read_req->total == 0)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

            /**
             * Read SOP:
             * phb_control_block_set_param(),
             * phb_control_block_set(),
             * phb_control_block_set_IO(),
             * se_control_block()
             */
                control_block->total = l4cphb_read_req->total;
                phb_entry_array =
                    (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
                control_block->need_free_peer = KAL_TRUE;
                phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);

                phb_entry = &phb_entry_array->array[0];

                if (l4cphb_read_req->type == PHB_ECC)
                {
                    kal_uint8 i;
                    kal_uint8 index = (kal_uint8) l4cphb_read_req->index - 1;
                    phb_entry_struct *phb_entry_ith = phb_entry;

                    control_block->type = PHB_ECC;
                    control_block->total = 0;

                    /* phb_ptr->ecc.num_ecc now contains number of records */
                    for (i = index; (i < phb_ptr->ecc.num_ecc) && (control_block->total < l4cphb_read_req->total); ++i)
                    {
                        kal_uint16 len;

                        phb_entry_ith->storage = PHB_SIM;

                        len = bcd_len(&phb_ptr->ecc.ecc[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
                        len = (len + 1) >> 1;

                        phb_entry_ith->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                        phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                        kal_mem_cpy(
                            &phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (void const*)&phb_ptr->ecc.ecc[i * NUM_OF_BYTE_ECC],
                            len);

                        ++control_block->total;
                        phb_entry_ith->tel_number.addr_bcd[phb_entry_ith->tel_number.addr_length] = 0xff;
                        ++phb_entry_ith;
                    }
                    phb_entry_array->no_array = (kal_uint8) (control_block->actual_count = control_block->total);

                    phb_read_confirm(
                        PHB_ERRNO_READ_SUCCESS,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }
                else
                {
                    phb_control_block_set(
                        control_block,
                        phb_read_continue,
                        phb_read_handler,
                        phb_read_err_handler,
                        READ_NONE);
                    /* This function sets actual_count */
                    phb_control_block_set_IO(
                        control_block,
                        l4cphb_read_req->type,
                        l4cphb_read_req->index,
                        l4cphb_read_req->total);

                    /* Set proc_stage, storage, record_index, primary_ID, and secondary_ID */
                    if (phb_se_set_control_block(
                            control_block,
                            OP_READ,
                            l4cphb_read_req->storage,
                            l4cphb_read_req->record_index) == KAL_FALSE)
                    {
                        phb_read_err_handler(NULL, control_block);
                        return;
                    }
                    control_block->data = (kal_uint8*) phb_entry;
                    control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                    phb_read_continue(NULL, control_block);
                }
            }
            /* error */
            else
            {
                phb_read_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_read_confirm(
                PHB_ERRNO_NOT_READY,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
            return;
        }

    }
    else
    {
        if (control_block->proc_stage == READ_CONTINUE)
        {
            phb_read_confirm(
                PHB_ERRNO_READ_SUCCESS,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
        }
        else if (control_block->proc_stage == READ_CONTINUE_SPECIFIC)
        {
            if (control_block->data == NULL)
            {
                phb_read_confirm(
                    PHB_ERRNO_READ_EMPTY,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
            else
            {
                phb_read_confirm(
                    PHB_ERRNO_READ_SUCCESS,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block->cnf_msg_id,
                    control_block);
            }
        }

        /* error */
        else
        {
            phb_read_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_read_handler */
#endif /* __PHB_USIM_SUPPORT__ */ /* __PHB_USIM_SUPPORT */

