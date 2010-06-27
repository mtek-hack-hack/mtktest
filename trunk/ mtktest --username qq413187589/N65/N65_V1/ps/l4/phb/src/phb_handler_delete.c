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
 * phb_handler_delete.c
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
#include "nvram_enums.h"
#include "nvram_struct.h"

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
#include "phb_sap.h"

/* ErrorStruct */
#include "asn-error.h"
#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_handler_read.h"
#include "phb_handler_delete.h"
#include "phb_nvram_access.h"

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#include "phb_handler_write.h"
#endif 

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_DELETE_C_

#if (MAX_PHB_LN_ENTRY > 20)
static kal_bool first_round;
#endif 

static void phb_delete_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_delete_continue(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_delete_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block);

static void phb_delete_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block);
static kal_bool phb_delete_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block);
static void phb_ln_delete_entry(kal_uint8 index, nvram_ef_phb_ln_struct *record);

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
static void phb_delete_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type);
#endif 

#ifdef __PHB_USIM_SUPPORT__
extern kal_bool is_usim_type(void);
#endif

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);

#ifndef __PHB_SORT_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  phb_delete_find_next_deleted
 * DESCRIPTION
 *  Find record index of next occupied record
 * PARAMETERS
 *  storage             [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_delete_find_next_deleted(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_enum type;
    data_desc_type *data_desc_entry;
    kal_uint16 byte_counter;
    kal_uint16 bit_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_FIND_NEXT_FREE); */
    if (storage == PHB_NVRAM)
    {
        type = DATA_DESC_PHB;
    }
    else
    {
        type = DATA_DESC_ADN;
    }
    data_desc_entry = &phb_ptr->data_desc[type];
    ASSERT(data_desc_entry != NULL);

    if ((data_desc_entry->is_support == KAL_FALSE) ||
        (data_desc_entry->free_count == phb_data_desc_get_record_size(type)))
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
                if (!(data_desc_entry->free_bitmap[byte_counter] & (1 << bit_counter)))
                {
                    return (byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter + 1;
                }
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_delete_find_next_deleted */
#endif /* __PHB_SORT_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_delete_handler
 * DESCRIPTION
 *  This is phb_delete_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE);

    if (ilm_ptr != NULL)
    {
        l4cphb_delete_req_struct *l4cphb_delete_req;

        l4cphb_delete_req = (l4cphb_delete_req_struct*) ilm_ptr->local_para_ptr;

      /**
       * Delete should be exclusive from other operations, otherwise they could conflict.
       * Current PHB implementation doesn't prevent such conditions.
       * Such condition should happen at caller's own risk.
       */
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_delete_confirm(PHB_ERRNO_BUSY, 0, l4cphb_delete_req->src_id, control_block);
                return;
            }

            control_block->src_id = l4cphb_delete_req->src_id;
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == DELETE_NONE)
            {
                /* Reset actual count to zero */
                control_block->actual_count = 0;

                /* Error: ECC and SDN are read only */
                if (!phb_is_type_valid(l4cphb_delete_req->type) ||
                    (l4cphb_delete_req->type == PHB_ECC) ||
                    (l4cphb_delete_req->type == PHB_SDN) || (l4cphb_delete_req->type == PHB_GAS))

                {
                    phb_delete_err_handler(NULL, control_block);
                    return;
                }

                if (l4cphb_delete_req->total == (kal_uint16) PHB_INVALID_VALUE)
                {
                #ifdef __PHB_DELETE_ALL_TURBO__
        	    nvram_reset_req_struct *reset_req;
                #endif
                    if (l4cphb_delete_req->index != 1)
                    {
                        phb_delete_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block);
                        return;
                    }
                #ifdef __PHB_DELETE_ALL_TURBO__
                    control_block->proc_stage = DELETE_ALL_CONTINUE;
                    control_block->IO_cnf_receive = phb_delete_handler;
    
                    reset_req = (nvram_reset_req_struct *)
                           construct_local_para(sizeof(nvram_reset_req_struct), TD_CTRL);

                    reset_req->LID = NVRAM_EF_PHB_LID;
                    reset_req->reset_category = NVRAM_RESET_CERTAIN;
                    reset_req->access_id = l4cphb_delete_req->src_id;
                #ifdef __GEMINI__
                    reset_req->rec_index = 1;
                    reset_req->rec_amount= NVRAM_EF_PHB_TOTAL;
                #endif /* __GEMINI__ */
                    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_RESET_REQ, (local_para_struct *) reset_req, NULL);
                    return;                
                #else /* __PHB_DELETE_ALL_TURBO__*/
                /* Delete all!! */
                    /* Ok, index = 1 and total = 0xFFFF, delete all! */
                    l4cphb_delete_req->total = phb_se_get_total_of_type(l4cphb_delete_req->type);
                    /* amanda add */
                    if (l4cphb_delete_req->type == PHB_PHONEBOOK)
                    {
                        control_block->storage = l4cphb_delete_req->storage;
                    #ifdef __PHB_SORT_ENABLE__
                        l4cphb_delete_req->index = phb_se_get_index_by_storage(control_block->storage);
                    #else 
                        l4cphb_delete_req->index = phb_delete_find_next_deleted(control_block->storage);
                    #endif 
                        if (l4cphb_delete_req->index == PHB_INVALID_VALUE)
                        {
                            phb_delete_confirm(PHB_ERRNO_SUCCESS, 0, l4cphb_delete_req->src_id, control_block);
                            return;
                        }
                    }
                #endif /* __PHB_DELETE_ALL_TURBO__ */
                }

                if (l4cphb_delete_req->index != (kal_uint16) PHB_INVALID_VALUE)
                {
                    /* Since this is a delete operation, no need to prepare data for deletion. */
                    control_block->total = l4cphb_delete_req->total;
                    if (l4cphb_delete_req->type == PHB_PHONEBOOK ||
                        (l4c_is_src_from_rmmi(control_block->src_id) && l4cphb_delete_req->type == PHB_FDN) ||
                        phb_se_is_in_range(
                            l4cphb_delete_req->type,
                            l4cphb_delete_req->index,
                            &l4cphb_delete_req->total) == KAL_TRUE)
                    {
                        /* This is for fectching necessary parameters from temp_entry */
                        l4cphb_delete_req->total = control_block->total;
                        phb_control_block_set_param(control_block, DELETE_CONTINUE, NULL, NULL);

                        phb_control_block_set(
                            control_block,
                            phb_delete_continue,
                            phb_delete_handler,
                            phb_delete_err_handler,
                            DELETE_CONTINUE);
                        phb_control_block_set_IO(
                            control_block,
                            l4cphb_delete_req->type,
                            l4cphb_delete_req->index,
                            l4cphb_delete_req->total);

                  /**
                   * Temporarily stores number of entries to be piggybacked.
                   * Don't forget to restore it back to control_block->total before
                   * read_fake(), if necessary.
                   */
                        control_block->total_piggyback = l4cphb_delete_req->total_piggyback;

                        /* set storage, record_index, primary_ID, and secondary_ID */
                        if (phb_se_set_control_block(
                                control_block,
                                OP_DELETE,
                                l4cphb_delete_req->storage,
                                (kal_uint16) PHB_INVALID_VALUE) == KAL_FALSE)
                        {
                            phb_delete_err_handler(NULL, control_block);
                            return;
                        }

                        /* Since this is a delete operation, no need to set data. */
                        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                        /*
                         * If it is a MSISDN entry, need to read the data from SIM first to see if the MSISDN uses extenstion 1
                         * *    So allocate buffer to store read data for phb_issue_IO_read() command here.
                         */
                        if (l4cphb_delete_req->type == PHB_MSISDN)
                        {
                            control_block->data = get_ctrl_buffer(sizeof(phb_entry_struct));
                        }

                        phb_delete_continue(NULL, control_block);
                    }
                    else
                    {
                        phb_delete_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block);
                        return;
                    }
                }
                /* error */
                else
                {
                    phb_delete_err_handler(NULL, control_block);
                    return;
                }
            }
        #ifdef __PHB_DELETE_ALL_TURBO__ 
            else if(control_block->proc_stage == DELETE_ALL_CONTINUE)
            {
                nvram_reset_cnf_struct *msg_ptr = NULL;
                msg_ptr = (nvram_reset_cnf_struct*) ilm_ptr->local_para_ptr;
                if (msg_ptr->result == NVRAM_ERRNO_SUCCESS)
                {
                    phb_delete_confirm(PHB_ERRNO_SUCCESS, 0xFFFF, control_block->src_id, control_block);
                    return;
                }
                else
                {
                    phb_delete_confirm(PHB_ERRNO_FAIL, 0xFFFF, control_block->src_id, control_block);
                    return;            
                }   
            }       
        #endif /* __PHB_DELETE_ALL_TURBO__ */
            /* error */
            else
            {
                phb_delete_err_handler(NULL, control_block);
                return;
            }
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            phb_delete_confirm(PHB_ERRNO_NOT_READY, control_block->actual_count, control_block->src_id, control_block);
            return;
        }
    }
    else
    {
        /* Delete confirmed */
        if (control_block->proc_stage == DELETE_CONTINUE)
        {
            /* Piggyback is not required. */
        #ifdef __PHB_SORT_ENABLE__
            if (control_block->total_piggyback < 1)
        #else 
            if (control_block->total_piggyback < 1 || control_block->type == PHB_PHONEBOOK)
        #endif 
            {
                phb_delete_confirm(
                    PHB_ERRNO_SUCCESS,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block);
            }
            /* Piggyback is required */
            else
            {
                /* Now we have to transform the state to a *FAKE* read state. */
                control_block->total = control_block->total_piggyback;

            /**
             * Weird error happened. Anyway, the entry is already written
             * successfully.
             */
                if (phb_se_is_in_range(control_block->type, control_block->index, &control_block->total) == KAL_FALSE)
                {
                    phb_delete_confirm(
                        PHB_ERRNO_SUCCESS,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block);
                    return;
                }

                /* If any critial error occured. read_err_handler will handle it. */
                if (phb_read_fake(control_block, NULL) == KAL_FALSE)
                {
                    return;
                }

                /* Finally, faking complete....Now continue reading */
                phb_read_continue(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            phb_delete_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_delete_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_err_handler
 * DESCRIPTION
 *  This is phb_delete_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_delete_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_continue
 * DESCRIPTION
 *  This is phb_delete_continue function of PHB module.
 *  
 *  Since only exactly one entry can be written at a time, this function just issues write
 *  request if it's time to begin write prepared data, or give control back to controller.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CONT);

    /* It's time to write prepared dat */
    if (ilm_ptr == NULL)
    {
        /*
         * If it is a MSISDN record, need to retrieve data first to see if it uses a extension 1 record.
         * *  So issue IO read here before issue IO delete
         */
        if (control_block->type == PHB_MSISDN)
        {
            phb_issue_IO_read(control_block);
        }
        else
        {
            phb_issue_IO_delete(control_block);
        }
    }
    /* Write confirmed. Give control back to contoller */
    else
    {
        /* 
         * For 1 to 1 mapping
         * For MSISDN, read the record from SIM first to see if it uses extension 1 record
         * and then issue IO delete command here.
         */
        if (control_block->type == PHB_MSISDN)
        {
            /* Free control buffer for SIM read. The data is not needed later. */
            if (control_block->data != NULL)
            {
                free_ctrl_buffer(control_block->data);
                control_block->data = NULL;
            }

            /*
             *   Use "candidate" variable in control block to check if this is first time receive MSISDN read confirm.
             *   If first time come in, issue delete command to delete MSISDN record here.
             */
            if (control_block->candidate == 0)
            {
                control_block->candidate = 1;
                phb_issue_IO_delete(control_block);
                return;
            }
            else    /* control_block->candidate == 1, after phb_issue_IO_delete() command. */
            {
                kal_uint8 ext_index = (kal_uint8) PHB_INVALID_VALUE;

                ++control_block->index;

                /*
                 *  Makr extension record to free if MSISDN uses extension record.
                 *  No need to mark primary_ID free because MSISDN status does not keep in phb.
                 */
                ext_index = control_block->seg_record_index;
                if (ext_index > 0 && ext_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                        ext_index,
                        KAL_TRUE);
                }
                /* mark data_desc_table free_bitmap as free for for MSISDN */
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_TRUE);
            }
            control_block->seg_record_index = 0;
        }
        else
        {
            kal_uint8 ext_index = (kal_uint8) PHB_INVALID_VALUE;

            control_block->candidate = control_block->index;
            /* First we have to sync the deleted entry into search engine */
            /* The deleted index is in control_block->index */
            if (control_block->type == PHB_PHONEBOOK && control_block->storage == PHB_SIM)
            {
                ext_index = phb_se_ext_index_find(control_block->record_index, control_block->type);
                /* delete entry in ext_index_table */
                phb_se_ext_index_delete(control_block->record_index, control_block->type);
            }
            phb_se_delete(control_block->type, (kal_uint16) (control_block->index - 1), &ext_index);

            /* Delete complete, mark it as FREE */
            phb_data_desc_mark_free(
                phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                control_block->record_index,
                KAL_TRUE);
            if (ext_index > 0 && ext_index != (kal_uint8) PHB_INVALID_VALUE)
            {
                phb_data_desc_mark_free(phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage), ext_index, KAL_TRUE);
            }
        #ifdef __PHB_USIM_SUPPORT__
            if (control_block->type == PHB_PHONEBOOK && control_block->storage == PHB_SIM && is_usim_type())
            {
                kal_uint16 iap_index = 0;

                ext_index = phb_se_ext_index_find(control_block->record_index, PHB_ANRA);
                /* Delete complete, mark it as FREE */
                if (ext_index > 0 && ext_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    /* delete entry in ext_index_table */
                    phb_se_ext_index_delete(control_block->record_index, PHB_ANRA);
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                        ext_index,
                        KAL_TRUE);
                }

                ext_index = phb_se_ext_index_find(control_block->record_index, PHB_ANRB);
                /* Delete complete, mark it as FREE */
                if (ext_index > 0 && ext_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    /* delete entry in ext_index_table */
                    phb_se_ext_index_delete(control_block->record_index, PHB_ANRB);
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                        ext_index,
                        KAL_TRUE);
                }
                ext_index = phb_se_ext_index_find(control_block->record_index, PHB_ANRC);

                /* Delete complete, mark it as FREE */
                if (ext_index > 0 && ext_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    /* delete entry in ext_index_table */
                    phb_se_ext_index_delete(control_block->record_index, PHB_ANRC);
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                        ext_index,
                        KAL_TRUE);
                }
                if (phb_ptr->email_type == 2)
                {
                    iap_index = phb_se_iap_index_find(control_block->record_index, DATA_DESC_EMAIL);
                    if (iap_index > 0 && iap_index != (kal_uint8) PHB_INVALID_VALUE)
                    {
                        /* delete entry in iap_index_table */
                        phb_se_iap_index_delete(control_block->record_index, DATA_DESC_EMAIL);
                        /* Since data is deleted, that record must be marked */
                        phb_data_desc_mark_free(DATA_DESC_EMAIL, iap_index, KAL_TRUE);
                    }
                }
            }
        #endif /* __PHB_USIM_SUPPORT__ */ 
        }

        ++control_block->actual_count;

        /* Delete complete, now return control back to controller */
        if (control_block->actual_count >= control_block->total)
        {
            (*control_block->controller) (NULL, control_block);
        }
      /**
       * Still others to delete
       * Since index, total is in ensured to be in range, tested in handler(), it is uncessary
       * to test it here.
       */
        else if (control_block->index != (kal_uint16) PHB_INVALID_VALUE)
        {
         /**
          * Index should NOT be decremented!!
          * Because entries will be shift into the deleted index!!
          */

            /* amanda add */
            if (control_block->type == PHB_PHONEBOOK)
            {
            #ifdef __PHB_SORT_ENABLE__
                control_block->index = phb_se_get_index_by_storage(control_block->storage);
            #else 
                control_block->index = phb_delete_find_next_deleted(control_block->storage);
            #endif 
                /* no more to delete */
                if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
                {
                    (*control_block->controller) (NULL, control_block);
                    return;
                }

            }
            /* set storage, record_index, primary_ID, and secondary_ID */
            if (phb_se_set_control_block(
                    control_block,
                    OP_DELETE,
                    PHB_STORAGE_NONE,
                    (kal_uint16) PHB_INVALID_VALUE) == KAL_FALSE)
            {
                phb_delete_err_handler(NULL, control_block);
                return;
            }

            control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

            phb_issue_IO_delete(control_block);
        }
        /* error */
        else
        {
            phb_delete_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_delete_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_confirm
 * DESCRIPTION
 *  This is phb_delete_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    local_para_struct *local_param_ptr = NULL;

    l4cphb_delete_cnf_struct *l4cphb_delete_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CNF, result, actual_count, src_id);

    l4cphb_delete_cnf = (l4cphb_delete_cnf_struct*) construct_local_para(sizeof(l4cphb_delete_cnf_struct), TD_CTRL);
    l4cphb_delete_cnf->total = actual_count;
    l4cphb_delete_cnf->src_id = src_id;

    local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;

    /* If result is PHB_ERRNO_BUSY, reject newly received request */
    l4cphb_delete_cnf->result = result;

    /* Confirm to in-processing operation */
    if (result != PHB_ERRNO_BUSY)
    {
        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_delete_cnf->cause = control_block->cause;
        l4cphb_delete_cnf->old_index = control_block->candidate;

        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_CNF, local_param_ptr, NULL);
}   /* end of phb_delete_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_handler
 * DESCRIPTION
 *  This is phb_delete_ln_handler function of PHB module.
 *  Handles delete last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            l4cphb_delete_ln_req_struct *msg_ptr;

            msg_ptr = (l4cphb_delete_ln_req_struct*) ilm_ptr->local_para_ptr;
        #if (MAX_PHB_LN_ENTRY > 20)
            first_round = KAL_TRUE;
        #endif 
            control_block = phb_alloc_control_block();

            if (control_block == NULL)
            {
                phb_delete_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        /* if (phb_ptr->state == PHB_STATE_READY) */
        {
            if (control_block->proc_stage == DEL_LN_NONE)
            {
                l4cphb_delete_ln_req_struct *msg_ptr = (l4cphb_delete_ln_req_struct*) ilm_ptr->local_para_ptr;

            #if (MAX_PHB_LN_ENTRY > 20)
                kal_uint8 no_skip;
                kal_uint8 seg_total;

                if (msg_ptr->index == 0xff)
                {
                    no_skip = 0;
                }
                else
                {
                    no_skip = msg_ptr->index / PHB_MAX_LN_ENTRIES;      /* 0-based */
                }
                seg_total = ((phb_get_ln_total_entry(msg_ptr->type) + PHB_MAX_LN_ENTRIES - 1)
                             / PHB_MAX_LN_ENTRIES) - no_skip;
                control_block->index = msg_ptr->index;
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

                /* save req info */
                control_block->IO_cnf_receive = phb_delete_ln_handler;
                control_block->seg_record_index = msg_ptr->index;
                control_block->src_id = msg_ptr->src_id;
                control_block->type = msg_ptr->type;

                if (control_block->type == PHB_LND)
                {
                    control_block->seg_total = PHB_TOT_LND_LIDS;
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
                else if (control_block->type == PHB_LNM)
                {
                    control_block->seg_total = PHB_TOT_LNM_LIDS;
                    control_block->secondary_ID = PHB_LNM_LID_START;
                }
                else if (control_block->type == PHB_LNR)
                {
                    control_block->seg_total = PHB_TOT_LNR_LIDS;
                    control_block->secondary_ID = PHB_LNR_LID_START;
                }
                else
                {
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }

            #ifdef __GEMINI__
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ */
                if (msg_ptr->index == 0xff)
                {
                    /* delete all */
                    control_block->total_piggyback = 0;
                    control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
                    kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));

                    if (control_block->seg_total > 1)
                    {
                        control_block->proc_stage = DEL_LN_WRITE_CONTINUE;
                    }
                    else
                    {
                        control_block->proc_stage = DEL_LN_WRITE;
                    }

                    phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                #ifdef __PHB_RECORD_LN_TYPE_SEQ__
                    phb_delete_ln_type_seq(0, (kal_uint8) control_block->type);
                #endif 

                    free_ctrl_buffer(control_block->data);
                    return;
                }
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->seg_total = seg_total;
                if (seg_total <= 2)
                {
                    control_block->secondary_ID += no_skip;
                }
                else    /* need backward read */
                {
                    control_block->secondary_ID +=
                        (PHB_TOT_LNM_LIDS - (PHB_TOT_LNM_LIDS - seg_total) - 1 - 1 + no_skip);
                }
                control_block->seg_record_index -= (PHB_MAX_LN_ENTRIES * no_skip);
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

                control_block->proc_stage = DEL_LN_READ;
                control_block->total_piggyback = msg_ptr->total;

                phb_read_ln_from_nvram(control_block);
                return;
            }
            else if (control_block->proc_stage == DEL_LN_READ)
            {
                kal_bool updated;
                kal_uint16 length;
                nvram_read_cnf_struct *msg_ptr = NULL;
                nvram_ef_phb_ln_struct *pdu_data;

                msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    pdu_data = (nvram_ef_phb_ln_struct*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);

                    /* keep first read data in control_block->data */
                    hold_peer_buff(ilm_ptr->peer_buff_ptr);
                    control_block->data = (kal_uint8*) ilm_ptr->peer_buff_ptr;

                    /* if (control_block->type != PHB_LND)
                       {
                       control_block->secondary_ID ++;
                       control_block->proc_stage = DEL_LN_READ_CONTINUE;
                       
                       phb_read_ln_from_nvram (control_block);
                       return;
                       }
                       else
                       { */
                    if (control_block->seg_total > 1)
                    {
                        control_block->secondary_ID++;
                        control_block->seg_total--;
                        control_block->proc_stage = DEL_LN_READ_CONTINUE;

                        phb_read_ln_from_nvram(control_block);
                        return;
                    }
                    else
                    {
                        control_block->proc_stage = DEL_LN_WRITE;
                        updated = phb_delete_ln(NULL, control_block);

                        if (updated == KAL_TRUE)
                        {
                            /* write LND file */
                            phb_write_ln_to_nvram(NULL, control_block);
                            return;
                        }
                    }
                    /* } */
                }
                phb_delete_ln_confirm(PHB_ERRNO_READ_FAIL, control_block->src_id, control_block);
            }
            else if (control_block->proc_stage == DEL_LN_READ_CONTINUE)
            {
                kal_bool updated;
                kal_uint16 length;
                nvram_read_cnf_struct *msg_ptr = NULL;
                nvram_ef_phb_ln_struct *pdu_data;

                msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    pdu_data = (nvram_ef_phb_ln_struct*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);

                    /* keep second read data in control_block->peer_buf_ptr */
                    hold_peer_buff(ilm_ptr->peer_buff_ptr);
                    control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

                    updated = phb_delete_ln(pdu_data, control_block);

                    if (updated == KAL_TRUE)
                    {
                        control_block->proc_stage = DEL_LN_WRITE_CONTINUE;

                        /* write second file */
                        phb_write_ln_to_nvram(pdu_data, control_block);
                        return;
                    }
                }
                phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
            else if (control_block->proc_stage == DEL_LN_WRITE_CONTINUE)
            {
                nvram_write_cnf_struct *msg_ptr = NULL;

                msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    if (control_block->seg_record_index == 0xff)
                    {
                        /* delete all */
                        control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
                        kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));

                        control_block->secondary_ID++;
                        control_block->seg_total--;
                        if (control_block->seg_total <= 1)
                        {
                            control_block->proc_stage = DEL_LN_WRITE;
                        }
                        phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);

                        free_ctrl_buffer(control_block->data);
                        return;
                    }
                    control_block->proc_stage = DEL_LN_WRITE;
                    control_block->secondary_ID--;

                    /* write first file */
                    phb_write_ln_to_nvram(NULL, control_block);
                    return;
                }
                else
                {
                    /* error */
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }
            }
            else if (control_block->proc_stage == DEL_LN_WRITE)
            {
                nvram_write_cnf_struct *msg_ptr = NULL;

                msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->seg_total > 1)
                {
                    control_block->seg_total--;
                    if (control_block->seg_total == 1)
                    {
                        control_block->secondary_ID -= 1;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                    }
                    control_block->proc_stage = DEL_LN_READ;
                    if (control_block != NULL)
                    {
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                        }
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                        }
                    }
                    first_round = KAL_FALSE;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ /* MAX_PHB_LN_ENTRY > 20 */

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    phb_delete_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
                }
                else
                {
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }
            }
            else
                /* wrong state */
            {
                phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
        }
        /* else
           phb_delete_ln_confirm (PHB_ERRNO_BUSY,
           control_block->src_id, control_block); */
    }
    else
    {
        phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_confirm
 * DESCRIPTION
 *  This is phb_delete_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_write_ln_cnf_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_write_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_write_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    param_ptr->total = 0;

    if ((result == PHB_ERRNO_SUCCESS) && (control_block->total_piggyback > 0))
    {
        param_ptr->total = control_block->total_piggyback;
    }
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_LN_CNF, param_ptr, NULL);
    if (control_block != NULL)
    {
        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        if (control_block->peer_buf_ptr != NULL)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        phb_free_control_block(control_block);
    }

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    if (result == PHB_ERRNO_SUCCESS)
    {
        phb_write_ln_type_seq_handler(NULL, NULL);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}   /* end of phb_delete_ln_confirm */


#ifdef __PHB_RECORD_LN_TYPE_SEQ__
/*****************************************************************************
 * FUNCTION
 *  phb_shift_left_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_seq_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_shift_left_ln_type_seq(kal_uint16 del_seq_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (del_seq_index >= PHB_TOTAL_LN_ENTRIES - 1)
    {
        phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES - 1] = 0xff;
    }
    else
    {
        while (del_seq_index < PHB_TOTAL_LN_ENTRIES - 1 && phb_ln_type_seq[del_seq_index + 1] != 0xff)
        {
            phb_ln_type_seq[del_seq_index] = phb_ln_type_seq[del_seq_index + 1];
            del_seq_index++;
        }
        /* last one should be 0xff */
        phb_ln_type_seq[del_seq_index] = 0xff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_seq_index       [IN]        
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 j = 0;
    kal_uint16 del_index = (PHB_TOTAL_LN_ENTRIES - 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_uint8 update_type = phb_ln_type_seq[0];
    //kal_uint8 tmp_type;
    if (del_seq_index > 0)
    {
        for (del_index = PHB_TOTAL_LN_ENTRIES - 1; del_seq_index > 0; del_index--)
        {
            if (phb_ln_type_seq[del_index] == type)
            {
                del_seq_index--;
            }
        }
        del_index++;
        phb_shift_left_ln_type_seq(del_index);
    }
    else
    {
        while (i < del_index && phb_ln_type_seq[i] != 0xff)
        {
            if (phb_ln_type_seq[i] == type)
            {
                phb_ln_type_seq[i] = 0xff;
                j = i;
                phb_shift_left_ln_type_seq(i);
                while (phb_ln_type_seq[j] == type)
                {
                    phb_shift_left_ln_type_seq(j);
                }
            }
            i++;
        }
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record              [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_delete_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 total, i;
    kal_uint16 len;
    nvram_ef_phb_ln_struct *record0 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record0 = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &len);

    if (record != NULL)
    {
        total = record0->no_entry + record->no_entry;
    }
    else
    {
        total = record0->no_entry;
    }

    if (total - 1 < control_block->seg_record_index)
    {
        return KAL_FALSE;
    }

#if (MAX_PHB_LN_ENTRY > 20)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    if (first_round)
    {
        phb_delete_ln_type_seq(
            (kal_uint16) (phb_get_ln_total_entry((kal_uint8) control_block->type) - control_block->index),
            (kal_uint8) control_block->type);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    if (!first_round)   /* need use shiftedEntry */
    {
        phb_ln_entry_struct buffer_entry;

        kal_mem_cpy(&buffer_entry, &shifted_entry, sizeof(phb_ln_entry_struct));
        if (record == NULL)
        {
            /* del entry in file 1 */
            i = control_block->seg_record_index;
            phb_ln_delete_entry(i, record0);
            control_block->seg_total = 0;
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &shifted_entry, sizeof(phb_ln_entry_struct));
            record0->no_entry++;
        }
        else if (record->no_entry > 0)
        {
            /* del entry in file 1 and push one entry from file 2 to file 1 */
            i = control_block->seg_record_index;
            if (control_block->seg_total > 1)   /* at least 2 (one is itself) */
            {
                kal_mem_cpy(&shifted_entry, &record0->array[0], sizeof(phb_ln_entry_struct));
                phb_ln_delete_entry(0, record0);
            }
            else
            {
                phb_ln_delete_entry(i, record0);
            }
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &record->array[0], sizeof(phb_ln_entry_struct));
            record0->no_entry++;
            phb_ln_delete_entry(0, record);
            kal_mem_cpy(&record->array[PHB_MAX_LN_ENTRIES - 1], &buffer_entry, sizeof(phb_ln_entry_struct));
            record->no_entry++;
        }
        else
        {
            /* del entry in file 1 */
            i = control_block->seg_record_index;
            phb_ln_delete_entry(i, record0);
            control_block->seg_total = 0;
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &shifted_entry, sizeof(phb_ln_entry_struct));
            record0->no_entry++;
        }

    }
    else if (control_block->seg_record_index >= PHB_MAX_LN_ENTRIES)
#else /* (MAX_PHB_LN_ENTRY > 20) */ 

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    phb_delete_ln_type_seq((kal_uint16) (total - control_block->seg_record_index), control_block->type);
#endif 

    if (control_block->seg_record_index >= PHB_MAX_LN_ENTRIES)
#endif /* MAX_PHB_LN_ENTRY > 20 */
    {
        /* del entry in file2 */
        i = control_block->seg_record_index - PHB_MAX_LN_ENTRIES;
        phb_ln_delete_entry(i, record);
    }
    else if (record == NULL)
    {
        /* del entry in file 1 */
        i = control_block->seg_record_index;
        phb_ln_delete_entry(i, record0);
    }
    else if (record->no_entry > 0)
    {
        /* del entry in file 1 and push one entry from file 2 to file 1 */
        i = control_block->seg_record_index;
    #if (MAX_PHB_LN_ENTRY > 20)
        if (control_block->seg_total > 1)   /* at least 2 (one is itself) */
        {
            kal_mem_cpy(&shifted_entry, &record0->array[0], sizeof(phb_ln_entry_struct));
            phb_ln_delete_entry(0, record0);
        }
        else
    #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            phb_ln_delete_entry(i, record0);
        kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &record->array[0], sizeof(phb_ln_entry_struct));
        record0->no_entry++;
        phb_ln_delete_entry(0, record);
    }
    else
    {
        /* del entry in file 1 */
        i = control_block->seg_record_index;
        phb_ln_delete_entry(i, record0);
    }

    if ((total - control_block->seg_record_index - 1) < control_block->total_piggyback)
    {
        control_block->total_piggyback = total - control_block->seg_record_index - 1;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_ln_delete_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  record      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_delete_entry(kal_uint8 index, nvram_ef_phb_ln_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = index + 1; i < record->no_entry; i++)
    {
        kal_mem_cpy(&record->array[i - 1], &record->array[i], sizeof(phb_ln_entry_struct));
    }
    record->no_entry--;
    return;
}

