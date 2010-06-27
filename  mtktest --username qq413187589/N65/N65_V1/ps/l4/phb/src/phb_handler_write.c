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
 * phb_handler_write.c
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

// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "sim_common_enums.h"
#include "l4c_common_enum.h"
#ifdef __MCD__
#include "mcd_l3_inc_struct.h"
#endif
#include "l4c_utility.h"  /* for l4c_is_src_from_rmmi */

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
#include "phb_utils.h"

/* ErrorStruct */
#include "asn-error.h"
#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_sap.h"
#include "phb_handler_read.h"
#include "phb_handler_write.h"
#include "phb_nvram_access.h"
#include "phb_sim_access.h"

#include "nvram_enums.h"
#include "nvram_struct.h"

#ifdef __GEMINI__
#include  "sim_common_enums.h"
#endif /* __GEMINI__ */

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_WRITE_C_

static void phb_write_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_write_continue(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_write_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block);

#ifdef __PHB_USIM_SUPPORT__
static void phb_write_usim_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_write_usim_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block);
#endif /* __PHB_USIM_SUPPORT__ */ 

static void phb_sync_confirm(phb_errno_enum result, control_block_type *control_block);
static void phb_write_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block);
static kal_bool phb_update_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block);

static kal_bool phb_edit_ln(control_block_type *control_block);

#ifndef __PHB_LN_SINGLE_COUNT__
static kal_bool phb_compare_bcd(kal_uint8 length1, kal_uint8 length2, kal_uint8 *bcd1, kal_uint8 *bcd2);
#endif 

#if (MAX_PHB_LN_ENTRY <= 20)
static void phb_ln_renew_entry1(kal_uint8 index, phb_ln_entry_struct *entry, nvram_ef_phb_ln_struct *record);
static void phb_ln_renew_entry2(
                kal_uint8 index,
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2);
#endif /* (MAX_PHB_LN_ENTRY <= 20) */ 

static void phb_ln_push_new_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2);

extern kal_uint8 convert_to_digit(kal_uint8 *source, kal_uint8 *dest);


/*****************************************************************************
 * FUNCTION
 *  phb_write_handler
 * DESCRIPTION
 *  This is phb_write_handler function of PHB module.
 *  Handles write request from L4C.
 *  3 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  WRITE          0xFFFF         valid    valid          Write an entry to user-specified physical location - {`storage', `record_index'}
 *  This operation is `add'.
 *  valid          ignored  0xFFFF         Write an entry to `index'th entry maintained by PHB.
 *  This opeartion is `update'.
 *  0xFFFF         valid    0xFFFF         Write an entry to `storage'. The physical location written is a free record searched by PHB.
 *  This opeartion is `add'.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE);

    if (ilm_ptr != NULL)
    {
        l4cphb_write_req_struct *l4cphb_write_req;

        l4cphb_write_req = (l4cphb_write_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_write_confirm(PHB_ERRNO_BUSY, 0, l4cphb_write_req->src_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_write_req->src_id;

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == WRITE_NONE)
            {
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;

                phb_entry_struct *phb_entry;
                l4cphb_phb_entry_array_struct *l4cphb_phb_entry_array;

                /* Error: ECC and SDN are read only */
                if (!phb_is_type_valid(l4cphb_write_req->type) ||
                    (l4cphb_write_req->type == PHB_ECC) || (l4cphb_write_req->type == PHB_SDN))
                {
                    phb_write_err_handler(NULL, control_block);
                    return;
                }

                /* First we have to unpack user's request */
            /**
             * Number of entries can be wriiten is exactly 1.
             * Hence, number of entries in peer buffer is expected to be 1.
             *
             * Since the entry to write is requested from L4C,
             * here a temporary l4cphb_phb_entry_array is allocated, so that user's
             * parameter can be unpacked to control_block->temp_entry.
             */

                pdu_ptr = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);
                l4cphb_phb_entry_array = (l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);
                phb_entry = &l4cphb_phb_entry_array->array[0];

            /**
             * After copying user's parameter from peer buffer, temporary
             * l4cphb_phb_entry_array can be freed.
             *
             * The entry to be written is stored in temp_entry!!
             */
                kal_mem_cpy(&control_block->temp_entry, (void const*)phb_entry, sizeof(phb_entry_struct));

            /**
             * Finally, the data to write is prepared in control_block->temp_entry.
             * Now the prepared data can be written.
             */
                /* This is for fectching necessary parameters from temp_entry */
                phb_entry = (phb_entry_struct*) & control_block->temp_entry;

                phb_control_block_set_param(control_block, WRITE_CONTINUE, NULL, NULL);

                phb_control_block_set(
                    control_block,
                    phb_write_continue,
                    phb_write_handler,
                    phb_write_err_handler,
                    WRITE_CONTINUE);
                phb_control_block_set_IO(control_block, l4cphb_write_req->type, phb_entry->index, 1);

                /**
                  * Temporarily stores number of entries to be piggybacked.
                  * Don't forget to restore it back to control_block->total before
                  * read_fake(), if necessary.
                  */
                control_block->total_piggyback = l4cphb_write_req->total;

                /* set storage, record_index, primary_ID, and secondary_ID */
                if (phb_se_set_control_block(
                        control_block,
                        OP_WRITE,
                        phb_entry->storage,
                        phb_entry->record_index) == KAL_FALSE)
                {
                    phb_write_err_handler(NULL, control_block);
                    return;
                }

                if (l4c_is_src_from_rmmi(control_block->src_id))
                {
                    phb_entry->index = control_block->index;
                }

                /* data stores data to be written, and length is record size of storage */
                control_block->data = (kal_uint8*) & control_block->temp_entry;
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                phb_write_continue(NULL, control_block);
            }
            /* error */
            else
            {
                phb_write_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_write_confirm(PHB_ERRNO_BUSY, control_block->actual_count, control_block->src_id, control_block);
            return;
        }

    }
    /* Write confirmed */
    else if (control_block->proc_stage == WRITE_CONTINUE)
    {
        /* Piggyback is not required. */
        if (control_block->total_piggyback < 1)
        {
            phb_write_confirm(PHB_ERRNO_SUCCESS, control_block->actual_count, control_block->src_id, control_block);
        }
        /* Piggyback is required */
        else
        {
            /* Now we have to transform the state to a *FAKE* read state. */
            phb_entry_struct *phb_entry;

            /* Restore total_piggyback */
            control_block->total = control_block->total_piggyback;

            /* The just written entry is still there! */
            phb_entry = (phb_entry_struct*) & control_block->temp_entry;

            /* control_block->set_IO() need not be invoked, because type, total is already be set. */
            /* Weird error happened. Anyway, the entry is already written successfully. */
            if (phb_se_is_in_range(control_block->type, phb_entry->index, &control_block->total) == KAL_FALSE)
            {
                control_block->actual_count = 1;
                phb_write_confirm(PHB_ERRNO_SUCCESS, control_block->actual_count, control_block->src_id, control_block);
                return;
            }

            /* If any critial error occured. read_err_handler will handle it. */
            if (phb_read_fake(control_block, phb_entry) == KAL_FALSE)
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
        phb_write_err_handler(NULL, control_block);
        return;
    }
}   /* end of phb_write_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_write_err_handler
 * DESCRIPTION
 *  This is phb_write_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    control_block->actual_count = 0;
    phb_write_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_write_err_handler function */

#ifdef __PHB_USIM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  phb_write_usim_handler
 * DESCRIPTION
 *  This is phb_write_usim_handler function of PHB module.
 *  Handles write request from L4C.
 *  3 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  WRITE          0xFFFF         valid    valid          Write an entry to user-specified physical location - {`storage', `record_index'}
 *  This operation is `add'.
 *  valid          ignored  0xFFFF         Write an entry to `index'th entry maintained by PHB.
 *  This opeartion is `update'.
 *  0xFFFF         valid    0xFFFF         Write an entry to `storage'. The physical location written is a free record searched by PHB.
 *  This opeartion is `add'.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_usim_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE);

    if (ilm_ptr != NULL)
    {
        l4cphb_write_usim_req_struct *l4cphb_write_req;

        l4cphb_write_req = (l4cphb_write_usim_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_write_confirm(PHB_ERRNO_BUSY, 0, l4cphb_write_req->src_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_write_req->src_id;

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == WRITE_USIM_NONE)
            {
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;

                phb_entry_struct *phb_entry;
                l4cphb_phb_entry_array_struct *l4cphb_phb_entry_array;
                kal_uint8 ext1_need_num = 0;

                /* USIM type only */

                /* default ext1 parent should be ADN (Phonebook) */
                control_block->ext1_parent_type = PHB_PHONEBOOK;

                /* First we have to unpack user's request */
            /**
             * Number of entries can be wriiten is exactly 1.
             * Hence, number of entries in peer buffer is expected to be 1.
             *
             * Since the entry to write is requested from L4C,
             * here a temporary l4cphb_phb_entry_array is allocated, so that user's
             * parameter can be unpacked to control_block->temp_entry.
             */

                if (ilm_ptr->peer_buff_ptr == NULL)
                {
                    /* phb_write_usim_err_handler(NULL, control_block); */
                    phb_write_usim_confirm(PHB_ERRNO_FAIL, 0, control_block->src_id, control_block);
                    return;
                }
                pdu_ptr = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);
                l4cphb_phb_entry_array = (l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);
                phb_entry = &l4cphb_phb_entry_array->array[0];

            /**
             * After copying user's parameter from peer buffer, temporary
             * l4cphb_phb_entry_array can be freed.
             *
             * The entry to be written is stored in temp_entry!!
             */
                kal_mem_cpy(&control_block->temp_entry, (void const*)phb_entry, sizeof(phb_entry_struct));

            /**
             * Finally, the data to write is prepared in control_block->temp_entry.
             * Now the prepared data can be written.
             */
                /* This is for fectching necessary parameters from temp_entry */
                phb_entry = (phb_entry_struct*) & control_block->temp_entry;
                /* set phonebook type since control_block->type will be cleared after write anr stage */
                phb_entry->type = l4cphb_write_req->type;
                kal_mem_cpy(
                    &control_block->temp_email_entry,
                    (void const*)&l4cphb_write_req->email,
                    sizeof(phb_email_struct));
                kal_mem_cpy(&control_block->temp_anra, (void const*)&l4cphb_write_req->anra, sizeof(phb_anr_struct));
                kal_mem_cpy(&control_block->temp_anrb, (void const*)&l4cphb_write_req->anrb, sizeof(phb_anr_struct));
                kal_mem_cpy(&control_block->temp_anrc, (void const*)&l4cphb_write_req->anrc, sizeof(phb_anr_struct));
                kal_mem_cpy(&control_block->temp_sne, (void const*)&l4cphb_write_req->sne, sizeof(l4_name_struct));
                control_block->temp_group_id = l4cphb_write_req->group_type;
                control_block->hidden_info = l4cphb_write_req->hidden_info;
                if (phb_ptr->iap_length > 0)
                {
                    kal_mem_set ((kal_uint8*)control_block->temp_iap,   0xff, 
                                  phb_ptr->data_desc[DATA_DESC_IAP].record_size);
                }

                /* check if enough EXT1 */
                /* First, find out whether free records in EFext suffice */

                if (phb_se_ext_index_find(phb_entry->record_index, PHB_PHONEBOOK) == (kal_uint8) PHB_INVALID_VALUE)
                {
                    ext1_need_num +=
                        ((phb_entry->tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN + EF_TEL_NUMBER_SIZE -
                          1) / EF_TEL_NUMBER_SIZE);
                }
                if (phb_se_ext_index_find(phb_entry->record_index, PHB_ANRA) == (kal_uint8) PHB_INVALID_VALUE)
                {
                    ext1_need_num +=
                        ((control_block->temp_anra.tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN +
                          EF_TEL_NUMBER_SIZE - 1) / EF_TEL_NUMBER_SIZE);
                }
                if (phb_se_ext_index_find(phb_entry->record_index, PHB_ANRB) == (kal_uint8) PHB_INVALID_VALUE)
                {
                    ext1_need_num +=
                        ((control_block->temp_anrb.tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN +
                          EF_TEL_NUMBER_SIZE - 1) / EF_TEL_NUMBER_SIZE);
                }
                if (phb_se_ext_index_find(phb_entry->record_index, PHB_ANRC) == (kal_uint8) PHB_INVALID_VALUE)
                {
                    ext1_need_num +=
                        ((control_block->temp_anrc.tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN +
                          EF_TEL_NUMBER_SIZE - 1) / EF_TEL_NUMBER_SIZE);
                }
                if (phb_data_desc_get_free_count(DATA_DESC_EXT1) < ext1_need_num)
                {
                    /* SIM has no more space to chain long numbers */
                    control_block->cause = SIM_EF_RECORD_FULL;
                    /* phb_write_usim_err_handler(NULL, control_block); */
                    phb_write_usim_confirm(PHB_ERRNO_FAIL, 0, control_block->src_id, control_block);
                    return;
                }
                if (phb_ptr->email_type == 2 &&
                    control_block->temp_email_entry.email_length > 0 &&
                    phb_data_desc_get_free_count(DATA_DESC_EMAIL) < 1)
                {
                    /* add operation */
                    if (control_block->temp_email_entry.adn_record_index == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        /* SIM has no more space to add e-mail */
                        control_block->cause = PHB_ERRNO_EMAIL_FULL;
                        /* phb_write_usim_err_handler(NULL, control_block); */
                        phb_write_usim_confirm(PHB_ERRNO_EMAIL_FULL, 0, control_block->src_id, control_block);
                        return;
                    }
                    else    /* add non-empty email or edit operation */
                    {
                        kal_uint16 email_index = phb_se_iap_index_find(
                                                    control_block->temp_email_entry.adn_record_index,
                                                    DATA_DESC_EMAIL);

                        if (email_index == (kal_uint16) PHB_INVALID_VALUE)
                        {
                            /* SIM has no more space to add e-mail */
                            control_block->cause = PHB_ERRNO_EMAIL_FULL;
                            /* phb_write_usim_err_handler(NULL, control_block); */
                            phb_write_usim_confirm(PHB_ERRNO_EMAIL_FULL, 0, control_block->src_id, control_block);
                            return;
                        }
                    }
                }

                phb_control_block_set_param(control_block, WRITE_USIM_ANR, NULL, NULL);

                phb_control_block_set(
                    control_block,
                    phb_write_continue,
                    phb_write_usim_handler,
                    phb_write_err_handler,
                    WRITE_USIM_ANR);
                phb_control_block_set_IO(control_block, l4cphb_write_req->type, phb_entry->index, 1);

            /**
             * Temporarily stores number of entries to be piggybacked.
             * Don't forget to restore it back to control_block->total before read_fake(), if necessary.
             */
                control_block->total_piggyback = l4cphb_write_req->total;

                /* set storage, record_index, primary_ID, and secondary_ID */
                if (phb_se_set_control_block(
                        control_block,
                        OP_WRITE,
                        phb_entry->storage,
                        phb_entry->record_index) == KAL_FALSE)
                {
                    phb_write_usim_err_handler(NULL, control_block);
                    return;
                }

                if (l4c_is_src_from_rmmi(control_block->src_id))
                {
                    phb_entry->index = control_block->index;
                }

                /* data stores data to be written, and length is record size of storage */
                control_block->data = (kal_uint8*) & control_block->temp_entry;
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                phb_write_continue(NULL, control_block);
            }
            /* error */
            else
            {
                phb_write_usim_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_free_control_block(control_block);
            control_block = NULL;
            phb_write_usim_confirm(PHB_ERRNO_BUSY, 0, l4cphb_write_req->src_id, control_block);
            return;
        }

    }
    /* Write ANR */
    else if (control_block->proc_stage <= WRITE_USIM_ANR && phb_ptr->anra_type != 0)
    {
        kal_uint16 anr_index = 0;

        phb_control_block_set_param(control_block, WRITE_USIM_EMAIL, NULL, NULL);

        if (phb_ptr->anra_type == 1)
        {
            anr_index = control_block->temp_entry.record_index;
        }
        else if (phb_ptr->anra_type == 2)
        {
            /* add operation */
            if (control_block->temp_anra.adn_record_index == (kal_uint16) PHB_INVALID_VALUE &&
                control_block->temp_anra.tel_number.addr_length == 0)
            {
                /* don't need to write e-mail field */
                phb_write_usim_handler(NULL, control_block);
                return;
            }
            else    /* add non-empty email or edit operation */
            {
                anr_index = phb_se_iap_index_find(control_block->temp_anra.adn_record_index, DATA_DESC_ANRA);
                if (anr_index == (kal_uint16) PHB_INVALID_VALUE)
                {
                    anr_index = phb_data_desc_find_next_free(DATA_DESC_ANRA);
                }
                control_block->temp_anra.record_index = anr_index;
            }
            /* the final adn index. */
            control_block->temp_anra.adn_record_index = control_block->temp_entry.record_index;
        }
        phb_control_block_set(
            control_block,
            phb_write_continue,
            phb_write_usim_handler,
            phb_write_err_handler,
            WRITE_USIM_EMAIL);
        phb_control_block_set_IO(control_block, PHB_ANR, anr_index, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        control_block->primary_ID = FILE_G_ANR_IDX;
        control_block->secondary_ID = FILE_G_EXT1_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_ANRA][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_ANRA][1];
        // TODO: need more test
        control_block->record_index = anr_index;
        /*
         * if (phb_se_set_control_block(control_block,
         * OP_WRITE,
         * PHB_SIM,
         * control_block->temp_entry.index) ==
         * KAL_FALSE)
         * {
         * phb_write_usim_err_handler(NULL, control_block);
         * return;
         * }
         */
        //if (control_block->src_id == RMMI_SRC)
        //   phb_entry->index = control_block->index;

        /* data stores data to be written, and length is record size of storage */
        control_block->data = (kal_uint8*) & control_block->temp_anra;
        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

        phb_write_continue(NULL, control_block);
    }
    /* Write EMAIL */
    else if (control_block->proc_stage <= WRITE_USIM_EMAIL && phb_ptr->email_type != 0)
    {
        kal_uint16 email_index = (kal_uint16) PHB_INVALID_VALUE;

        phb_control_block_set_param(control_block, WRITE_USIM_SNE, NULL, NULL);

        if (phb_ptr->email_type == 1)
        {
            email_index = control_block->temp_entry.record_index;
        }
        else if (phb_ptr->email_type == 2)
        {
            /* add operation */
            if (control_block->temp_email_entry.adn_record_index == (kal_uint16) PHB_INVALID_VALUE &&
                control_block->temp_email_entry.email_length == 0)
            {
                /* don't need to write e-mail field */
                phb_write_usim_handler(NULL, control_block);
                return;
            }
            else    /* add non-empty email or edit operation */
            {
                email_index = phb_se_iap_index_find(control_block->temp_email_entry.adn_record_index, DATA_DESC_EMAIL);
                if (email_index == (kal_uint16) PHB_INVALID_VALUE && control_block->temp_email_entry.email_length == 0) /* both empty */
                {
                    /* don't need to write e-mail field */
                    phb_write_usim_handler(NULL, control_block);
                    return;
                }
                else if (email_index != (kal_uint16) PHB_INVALID_VALUE && control_block->temp_email_entry.email_length == 0)    /* modify from non-empty to empty */
                {
                    /* no releation with adn. */
                    control_block->temp_email_entry.adn_record_index = 0xFF;
                    control_block->temp_iap[phb_ptr->iap_email] = 0xFF;
                }
                else
                {
                    if (email_index == (kal_uint16) PHB_INVALID_VALUE)  /* origin is empty */
                    {
                        email_index = phb_data_desc_find_next_free(DATA_DESC_EMAIL);
                        if (email_index == (kal_uint16) PHB_INVALID_VALUE)      /* can't find empty record */
                        {
                            ASSERT(0);
                            phb_write_usim_handler(NULL, control_block);
                            return;
                        }
                    }
                    /* the final adn index. */
                    control_block->temp_email_entry.adn_record_index = control_block->temp_entry.record_index;
                    control_block->temp_iap[phb_ptr->iap_email] = email_index;
                }
                control_block->temp_email_entry.record_index = email_index;
            }
        }

        phb_control_block_set(
            control_block,
            phb_write_continue,
            phb_write_usim_handler,
            phb_write_err_handler,
            WRITE_USIM_SNE);
        phb_control_block_set_IO(control_block, PHB_EMAIL, email_index, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        control_block->primary_ID = FILE_G_EMAIL_IDX;
        control_block->secondary_ID = FILE_NONE;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_EMAIL][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_EMAIL][1];
        control_block->record_index = email_index;
        /*
         * if (phb_se_set_control_block(control_block,
         * OP_WRITE,
         * PHB_SIM,
         * control_block->temp_entry.index) ==
         * KAL_FALSE)
         * {
         * phb_write_usim_err_handler(NULL, control_block);
         * return;
         * }
         */
        //if (control_block->src_id == RMMI_SRC)
        //   phb_entry->index = control_block->index;

        /* data stores data to be written, and length is record size of storage */
        control_block->data = (kal_uint8*) & control_block->temp_email_entry;
        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

        phb_write_continue(NULL, control_block);
    }
    /* Write IAP */
    else if (control_block->proc_stage <= WRITE_USIM_IAP &&
             phb_ptr->data_desc[DATA_DESC_IAP].record_size > 0)
    {
        phb_control_block_set_param(control_block,
                                    WRITE_USIM_GRP,
                                    NULL,
                                    NULL);
 
       phb_control_block_set(control_block,
                             phb_write_continue,
                             phb_write_usim_handler,
                             phb_write_err_handler,
                             WRITE_USIM_CONTINUE);
       phb_control_block_set_IO(control_block,
                                PHB_IAP,
                                control_block->temp_entry.record_index,
                                1);
 
       /* set storage, record_index, primary_ID, and secondary_ID */
       control_block->primary_ID = FILE_G_IAP_IDX;
       control_block->secondary_ID = FILE_NONE;
       kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
       control_block->path[4] = phb_ptr->path[DATA_DESC_IAP][0];
       control_block->path[5] = phb_ptr->path[DATA_DESC_IAP][1];
       control_block->record_index = control_block->temp_entry.record_index;
 
       /* data stores data to be written, and length is record size of storage */
       control_block->data = control_block->temp_iap;
       control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
       phb_write_continue(NULL, control_block);
    }
    /* Write Group */
    else if (control_block->proc_stage <= WRITE_USIM_GRP && phb_ptr->data_desc[DATA_DESC_GRP].is_support)
    {
        phb_control_block_set_param(control_block, WRITE_USIM_CONTINUE, NULL, NULL);

        phb_control_block_set(
            control_block,
            phb_write_continue,
            phb_write_usim_handler,
            phb_write_err_handler,
            WRITE_USIM_CONTINUE);
        phb_control_block_set_IO(control_block, PHB_GRP, control_block->temp_entry.record_index, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        control_block->primary_ID = FILE_G_GRP_IDX;
        control_block->secondary_ID = FILE_NONE;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_GRP][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_GRP][1];
        control_block->record_index = control_block->temp_entry.record_index;
        /*
         * if (phb_se_set_control_block(control_block,
         * OP_WRITE,
         * PHB_SIM,
         * control_block->temp_entry.index) ==
         * KAL_FALSE)
         * {
         * phb_write_usim_err_handler(NULL, control_block);
         * return;
         * }
         */
        //if (control_block->src_id == RMMI_SRC)
        //   phb_entry->index = control_block->index;

        /* data stores data to be written, and length is record size of storage */
        *control_block->data = control_block->temp_group_id;
        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

        phb_write_continue(NULL, control_block);
    }

    /* Write confirmed */
    else if (control_block->proc_stage <= WRITE_USIM_CONTINUE)
    {
        /* Piggyback is not required. */
        if (control_block->total_piggyback < 1)
        {
            phb_write_usim_confirm(
                PHB_ERRNO_SUCCESS,
                control_block->actual_count,
                control_block->src_id,
                control_block);
        }
        /* Piggyback is required */
        else
        {
            /* Now we have to transform the state to a *FAKE* read state. */
            phb_entry_struct *phb_entry;

            /* Restore total_piggyback */
            control_block->total = control_block->total_piggyback;

            /* The just written entry is still there! */
            phb_entry = (phb_entry_struct*) & control_block->temp_entry;

            /* control_block->set_IO() need not be invoked, because type, total is already be set. */
            /* Weird error happened. Anyway, the entry is already written successfully. */
        #ifdef __PHB_USIM_SUPPORT__
            if (phb_se_is_in_range(phb_entry->type, phb_entry->index, &control_block->total) == KAL_FALSE)
        #else 
            if (phb_se_is_in_range(control_block->type, phb_entry->index, &control_block->total) == KAL_FALSE)
        #endif 
            {
                control_block->actual_count = 1;
                phb_write_usim_confirm(
                    PHB_ERRNO_SUCCESS,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block);
                return;
            }

            /* If any critial error occured. read_err_handler will handle it. */
            if (phb_read_fake(control_block, phb_entry) == KAL_FALSE)
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
        phb_write_err_handler(NULL, control_block);
        return;
    }
}   /* end of phb_write_usim_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_write_usim_err_handler
 * DESCRIPTION
 *  This is phb_write_usim_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_usim_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    control_block->actual_count = 0;
    phb_write_usim_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);

}   /* end of phb_write_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_write_usim_confirm
 * DESCRIPTION
 *  This is phb_write_usim_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_usim_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    local_para_struct *local_param_ptr = NULL;
    l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

    l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
    l4cphb_write_cnf->total = actual_count;
    l4cphb_write_cnf->src_id = src_id;

    local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

    /* If result is PHB_ERRNO_BUSY, reject newly received request */
    l4cphb_write_cnf->result = result;

    /* Confirm to in-processing operation */
    if (result != PHB_ERRNO_BUSY)
    {
        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_write_cnf->cause = control_block->cause;
        l4cphb_write_cnf->old_index = control_block->candidate;

        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_USIM_CNF, local_param_ptr, NULL);
}   /* end of phb_write_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_set_grp_handler
 * DESCRIPTION
 *  This is phb_set_grp_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_set_grp_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
        l4cphb_set_grp_req_struct *l4cphb_set_req;

        l4cphb_set_req = (l4cphb_set_grp_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_write_confirm(PHB_ERRNO_BUSY, 0, l4cphb_set_req->src_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_set_req->src_id;

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == WRITE_USIM_NONE)
            {
                control_block->temp_group_id = l4cphb_set_req->group_type;

                //phb_control_block_set_param(control_block,
                //                        WRITE_USIM_ANR,
                //                        NULL,
                //                        NULL);

                phb_control_block_set(control_block, phb_write_continue, phb_set_grp_handler, phb_write_err_handler, 0);
                phb_control_block_set_IO(
                    control_block,
                    PHB_GRP,
                    l4cphb_set_req->record_index,   /* only set index, not including record_index */
                    1);
                /* set storage, record_index, primary_ID, and secondary_ID */
                control_block->primary_ID = FILE_G_GRP_IDX;
                control_block->secondary_ID = FILE_NONE;
                kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                control_block->path[4] = phb_ptr->path[DATA_DESC_GRP][0];
                control_block->path[5] = phb_ptr->path[DATA_DESC_GRP][1];
                control_block->record_index = l4cphb_set_req->record_index;
                control_block->storage = PHB_SIM;

                /* data stores data to be written, and length is record size of storage */
                /* *control_block->data = control_block->temp_group_id; */
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                if (phb_sim_write_first_record(control_block, (kal_uint8) PHB_INVALID_VALUE) == KAL_FALSE)
                {
                    /* Possibly because segemented data cannot be written */
                    phb_write_confirm(
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
                phb_write_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_free_control_block(control_block);
            control_block = NULL;
            phb_write_confirm(PHB_ERRNO_BUSY, 0, l4cphb_set_req->src_id, control_block);
            return;
        }

    }
    /* Write confirmed */
    else
    {
        phb_write_confirm(PHB_ERRNO_SUCCESS, 1, control_block->src_id, control_block);
        return;
    }
}
#endif /* __PHB_USIM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_write_continue
 * DESCRIPTION
 *  This is phb_write_continue function of PHB module.
 *  
 *  Since only exactly one entry can be written at a time, this function just issues write
 *  request if it's time to begin write prepared data, or give control back to controller.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CONT);

    /* It's time to write prepared data */
    if (ilm_ptr == NULL)
    {
        if (phb_issue_IO_write(control_block) == KAL_FALSE)
        {
            /* Possibly because segemented data cannot be written */
            phb_write_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
            return;
        }
    }
#ifdef __PHB_USIM_SUPPORT__
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_SET_GRP_REQ)
    {
        /* Then give control back to controller */
        (*control_block->controller) (NULL, control_block);
    }
#endif /* __PHB_USIM_SUPPORT__ */
    /* Write confirmed. Give control back to contoller */
    else
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        /* For 1 to 1 mapping */
        if (control_block->type == PHB_MSISDN)
        {
            phb_entry->index = phb_entry->record_index = control_block->index;
            phb_data_desc_mark_free(
                phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                control_block->record_index,
                KAL_FALSE);
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if (control_block->type == PHB_GAS)
        {
        }
        else if (control_block->type == PHB_GRP || control_block->type == PHB_IAP)
        {
            phb_entry->index = control_block->record_index;
        }
        else if (control_block->type == PHB_EMAIL)
        {
            if (phb_ptr->email_type == 2)
            {
                /* set email_index_table */
                phb_se_iap_index_set(
                    control_block->temp_email_entry.adn_record_index,
                    (kal_uint8)control_block->record_index,
                    DATA_DESC_EMAIL);
                /* Since data is written or become empty, that record must be marked */
                phb_data_desc_mark_free(
                    DATA_DESC_EMAIL,
                    control_block->record_index,
                    ((control_block->temp_email_entry.adn_record_index == 0xFF) ? KAL_TRUE : KAL_FALSE));
            }
        }
    #endif /* __PHB_USIM_SUPPORT__ */
        /* First we have to sync the written entry into search engine */
        else
        {
         /**
          * If this control path is reached, then one of the following
          * conditions is true:
          * 1. For `add' operation, a free record must be found and
          *   the requested entry is successfully written.
          * 2. For `update' operation, the record addressed by
          *   record_index must be occupied, and the requested
          *   entry is successfully updated.
          */

            /* This write is a add operation */
            control_block->candidate = control_block->index;

            if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
            {
                kal_uint16 total = 0, available = 0;

                if (control_block->seg_record_index == 0)
                {
                    control_block->seg_record_index = (kal_uint8) PHB_INVALID_VALUE;
                }
                if ((control_block->type == PHB_PHONEBOOK || control_block->type == PHB_ANR)
                    && control_block->storage == PHB_SIM &&
                    control_block->seg_record_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    /* set ext_index_table */
                    phb_se_ext_index_set(
                        control_block->record_index,
                        control_block->seg_record_index,
                        control_block->ext1_parent_type);
                }
            #ifndef __PHB_SORT_ENABLE__
                if (control_block->type == PHB_PHONEBOOK)
                {
                    phb_entry->index = control_block->record_index;
                }
                else
            #endif /* __PHB_SORT_ENABLE__ */ 
                    phb_entry->index = phb_se_append(
                                        control_block->type,
                                        control_block->record_index,
                                        control_block->seg_record_index,
                                        phb_entry);

                /* Mark free-list as used! */
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_FALSE);

            /**
             * Since it's an add operation, MMI needs to be informed
             * whether this newly added entry causes storage full.
             */
                if (control_block->type == PHB_PHONEBOOK)
                {
                    l4cphb_phonebook_status_req(control_block->storage, &total, &available);
                }
                else
                {
                    l4cphb_status_req(control_block->type, &total, &available);
                }

                /* Storage full! */
                if ((total != 0) && (available == 0))
                {
                    control_block->cause = PHB_CAUSE_STORAGE_FULL;
                }
            }

            /* This write is a overwrite/update operation */
            else
            {
                kal_uint8 old_ext_index = (kal_uint8) PHB_INVALID_VALUE;

                if (control_block->seg_record_index == 0)
                {
                    control_block->seg_record_index = (kal_uint8) PHB_INVALID_VALUE;
                }
                /* seg_record_index could be Invalid for update */
                if ((control_block->type == PHB_PHONEBOOK || control_block->type == PHB_ANR) &&
                    control_block->storage == PHB_SIM)
                {
                    if (control_block->seg_record_index != (kal_uint8) PHB_INVALID_VALUE)
                    {
                        /* set ext_index_table */
                        phb_se_ext_index_set(
                            control_block->record_index,
                            control_block->seg_record_index,
                            control_block->ext1_parent_type);
                    }
                    else    /* new ext index is 0, check the old ext index */
                    {
                        old_ext_index = phb_se_ext_index_find(control_block->record_index, control_block->ext1_parent_type);
                        if (old_ext_index != (kal_uint8) PHB_INVALID_VALUE)
                        {
                            phb_se_ext_index_delete(control_block->record_index, control_block->ext1_parent_type);
                        }
                    }
                }
            #ifndef __PHB_SORT_ENABLE__     /* seg_record_index could be Invalid for update */
                if (control_block->type == PHB_PHONEBOOK || control_block->type == PHB_ANR)
                {
                    phb_entry->index = control_block->record_index;
                }
                else
            #endif /* __PHB_SORT_ENABLE__ */ 
                {
                    phb_entry->index = phb_se_update(
                                        control_block->type,
                                        control_block->seg_record_index,
                                        phb_entry,
                                        --phb_entry->index,
                                        &old_ext_index);
                }
                if (control_block->seg_record_index == (kal_uint8) PHB_INVALID_VALUE &&
                    old_ext_index > 0 && old_ext_index != (kal_uint8) PHB_INVALID_VALUE)
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                        (kal_uint16)old_ext_index,
                        KAL_TRUE);
                }
            }

            /* Weird error occured!! */
            if (phb_entry->index == (kal_uint16) PHB_INVALID_VALUE)
            {
                phb_write_err_handler(NULL, control_block);
                return;
            }

            phb_entry->index++;
            phb_entry->record_index = control_block->record_index;
        }

        /* Then give control back to controller */
        (*control_block->controller) (NULL, control_block);
    }
}   /* end of phb_write_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_write_confirm
 * DESCRIPTION
 *  This is phb_write_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block)
{
#ifdef __PHB_USIM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block->cnf_msg_id == MSG_ID_L4CPHB_WRITE_USIM_REQ)
    {
        local_para_struct *local_param_ptr = NULL;
        l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;

        l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_write_cnf_struct),
                                                            TD_CTRL);
        l4cphb_write_cnf->total = actual_count;
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;

        /* Confirm to in-processing operation */
        if (result != PHB_ERRNO_BUSY)
        {
            /* Field 'cause' is meaningful when I/O occured by using control blocks */
            l4cphb_write_cnf->cause = control_block->cause;
            l4cphb_write_cnf->old_index = control_block->candidate;

            phb_free_control_block(control_block);
        }
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_USIM_CNF, local_param_ptr, NULL);
    }
    else if (control_block->cnf_msg_id == MSG_ID_L4CPHB_SET_GRP_REQ)
    {
        local_para_struct *local_param_ptr = NULL;
        l4cphb_set_grp_cnf_struct *l4cphb_write_cnf;

        l4cphb_write_cnf = (l4cphb_set_grp_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_set_grp_cnf_struct),
                                                            TD_CTRL);
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;

        /* Confirm to in-processing operation */
        if (result != PHB_ERRNO_BUSY)
        {
            /* Field `cause' is meaningful when I/O occured by using control blocks */
            /* l4cphb_write_cnf->cause = control_block->cause; */
            l4cphb_write_cnf->record_index = control_block->record_index;
            l4cphb_write_cnf->group_type = control_block->temp_group_id;

            phb_free_control_block(control_block);
        }
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SET_GRP_CNF, local_param_ptr, NULL);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        local_para_struct *local_param_ptr = NULL;
        l4cphb_write_cnf_struct *l4cphb_write_cnf;

        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

        l4cphb_write_cnf = (l4cphb_write_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->total = actual_count;
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;

        /* Confirm to in-processing operation */
        if (result != PHB_ERRNO_BUSY)
        {
            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_write_cnf->cause = control_block->cause;
            l4cphb_write_cnf->old_index = control_block->candidate;

            phb_free_control_block(control_block);
        }

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_CNF, local_param_ptr, NULL);
    }
}   /* end of phb_write_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_to_erase_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_to_erase_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (sim_write_req_struct*) construct_local_para((kal_uint16) sizeof(sim_write_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = 0;
    param_ptr->access_id = control_block->ID;

    /* the record to be written to SIM is empty */
    //control_block->index--;
    kal_mem_set((kal_uint8 *)param_ptr->data, 0xff, control_block->seg_len);
    param_ptr->length = control_block->seg_len;
    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, param_ptr, NULL);
}


#ifdef __VOIP__
/*****************************************************************************
 * FUNCTION
 *  phb_set_last_voice_ln_index
 * DESCRIPTION
 *  skip the voip record and get the last voice call ln index
 * PARAMETERS
 *  control_block       [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void phb_set_last_voice_ln_index(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_phb_ln_struct *pdu_data, *pdu_data1 = NULL;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //control_block->IO_stage = IO_WAIT;

    pdu_data = (nvram_ef_phb_ln_struct*) get_pdu_ptr(control_block->peer_buf_ptr, &length);
    if (control_block->data != NULL)
    {
        //ASSERT(pdu_data->no_entry == PHB_MAX_LN_ENTRIES);
        /* second NVRAM LID: 20 Entries will read 2nd data, too */
        pdu_data1 = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &length);
    }
    if (control_block->index == 0xFFFF)
    {
        if (control_block->data)
        {
            control_block->index = pdu_data->no_entry + pdu_data1->no_entry;
        }
        else
        {
            control_block->index = pdu_data->no_entry;
        }
    }

    if (pdu_data1 && control_block->index > PHB_MAX_LN_ENTRIES)
    {
        while (control_block->index > PHB_MAX_LN_ENTRIES)
        {
            if (pdu_data1->array[control_block->index - PHB_MAX_LN_ENTRIES -1].addr_type == PHB_LN_CALL)
            {
                return;
            }
            control_block->index--; /* skip voip ln */
        }
    }
    
    while (control_block->index > 0)
    {
        if (pdu_data->array[control_block->index-1].addr_type == PHB_LN_CALL)
        {
            return;
        }
        control_block->index--; /* skip voip ln */
    }
    //if (pdu_data->array[control_block->index].addr_type == PHB_LN_CALL)
    //{
    //    return;
    //}
}


/*****************************************************************************
 * FUNCTION
 *  phb_sync_handler
 * DESCRIPTION
 *  This is phb_sync_handler function of PHB module.
 *  Handles sync request from L4C when power off.
 *  Copyies LND records from NVRAM to SIM, if supported
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
    #ifdef __PHB_NVRAM_LN_ONLY__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
        return;
    #else /* __PHB_NVRAM_LN_ONLY__ */ 
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_sync_confirm(PHB_ERRNO_BUSY, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

        if (control_block->proc_stage == SYNC_NONE)
        {
            control_block->proc_stage = SYNC_READ_FILE;
            control_block->IO_cnf_receive = phb_sync_handler;

        #ifdef __GEMINI__
            if (sim_service_table_query(SERVICE_LND, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT)
        #else /* __GEMINI__ */
            if (sim_service_table_query(SERVICE_LND) == SERVICE_SUPPORT)
        #endif /* __GEMINI__ */
            {
                sim_file_info_req_struct *param_ptr;

                /* SIM card supports LND, get file info */
                param_ptr = (sim_file_info_req_struct*)
                    construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

                param_ptr->file_idx = FILE_LND_IDX;
                param_ptr->access_id = control_block->ID;
                phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
                return;
            }
            else
            {
                /* SIM card doesn't support LND, no need to sync */
                phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_FILE)
        {
            sim_file_info_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                if (msg_ptr->num_of_rec == 0)
                {
                    /* SIM card LND num is 0l, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
                control_block->seg_len = msg_ptr->file_size / msg_ptr->num_of_rec;
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = phb_get_ln_total_entry(PHB_LND);
                control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
            #else
                control_block->seg_total = MAX_PHB_LN_ENTRY;            
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                control_block->length = msg_ptr->file_size;
                control_block->index = msg_ptr->num_of_rec;
                control_block->proc_stage = SYNC_ERASE_SIM; /* index will used to indicate the SIM index */
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = (control_block->total + PHB_MAX_LN_ENTRIES - 1) / PHB_MAX_LN_ENTRIES;
                if (control_block->total > 2)
                {
                    control_block->secondary_ID = PHB_LND_LID_START + control_block->total - 2;
                }
                else
                {
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
            #else /* (MAX_PHB_LN_ENTRY > 20) */ 
                control_block->secondary_ID = PHB_LND_LID_START;
                control_block->total = PHB_TOT_LND_LIDS;
            #endif /* MAX_PHB_LN_ENTRY > 20 */
            #ifdef __GEMINI__
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ */
                control_block->data = NULL;
                phb_write_ln_to_erase_sim(control_block);
                return;
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_ERASE_SIM)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                control_block->index--;
                if (control_block->index > 0)
        {
                    phb_write_ln_to_erase_sim(control_block);
                    return;
                }
                else
                {
                    control_block->proc_stage = SYNC_READ; /* index will be set to 0xFFFF */
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;
                control_block->index = 0xFFFF;

                if (control_block->total > 1)
                {
                    /* NVRAM has more than one LND LID, continue to read */
                    control_block->proc_stage = SYNC_READ_CONTINUE;
                    control_block->secondary_ID++;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
                {
                    /* NVRAM only has one LND LID, prepare to write to SIM */
                    //Jo: here. to determine if all are voip entry.
                    phb_set_last_voice_ln_index(control_block);
                    if (control_block->index == 0)
                    {
                        /* No Voice Call LN, stop writing */
                        phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                        return;
                    }
                    control_block->proc_stage = SYNC_WRITE_CONTINUE;
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            }
            else
            {
                /* read NVRAM fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_CONTINUE)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (void*)ilm_ptr->peer_buff_ptr;
            }
            /* all NVRAM LND LIDs are read, prepare to write to SIM */
            phb_set_last_voice_ln_index(control_block);
            if (control_block->index == 0)
            {
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->total > 2)
                {
                    if (control_block != NULL)
                    {
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                        }
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                        }
                    }
                    control_block->proc_stage = SYNC_READ; /* index will be set 0xFFFF */
                    control_block->total -= 2;
                    if (control_block->total > 1)
                    {
                        control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                        control_block->secondary_ID -= 3;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                        control_block->seg_total = PHB_MAX_LN_ENTRIES;
                    }
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
            #endif /* (MAX_PHB_LN_ENTRY > 20) */
                {
                    /* No Voice Call LN, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
            }
            else
            {
                control_block->proc_stage = SYNC_WRITE_CONTINUE;
                phb_write_ln_to_sim(control_block);
            }
            return;
        }
        else if (control_block->proc_stage == SYNC_WRITE_CONTINUE)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                //control_block->index--;
                if (control_block->index > 0)
                {
                    phb_set_last_voice_ln_index(control_block);
                }
                if (control_block->index == 0)
                {
                #if (MAX_PHB_LN_ENTRY > 20)
                    if (control_block->total > 2)
                    {
                        if (control_block != NULL)
                        {
                            if (control_block->peer_buf_ptr != NULL)
                            {
                                free_peer_buff(control_block->peer_buf_ptr);
                            }
                            if (control_block->data != NULL)
                            {
                                free_peer_buff((peer_buff_struct*) control_block->data);
                            }
                        }
                        control_block->proc_stage = SYNC_READ; /* index will be set 0xFFFF */
                        control_block->total -= 2;
                        if (control_block->total > 1)
                        {
                            control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                            control_block->secondary_ID -= 3;
                        }
                        else
                        {
                            control_block->secondary_ID -= 2;
                            control_block->seg_total = PHB_MAX_LN_ENTRIES;
                        }
                        control_block->data = NULL;
                        phb_read_ln_from_nvram(control_block);
                        return;
                    }
                    else
                #endif /* (MAX_PHB_LN_ENTRY > 20) */
                    /* No Voice Call LN, stop writing */
                    {
                        phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                        return;
                    }
                }
                else
                {
                    phb_write_ln_to_sim(control_block);
                return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
    }
    #endif /* __PHB_NVRAM_LN_ONLY__ */ 
}
#else /* __VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  phb_sync_handler
 * DESCRIPTION
 *  This is phb_sync_handler function of PHB module.
 *  Handles sync request from L4C when power off.
 *  Copyies LND records from NVRAM to SIM, if supported
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [IN/OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
    #ifdef __PHB_NVRAM_LN_ONLY__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
        return;
    #else /* __PHB_NVRAM_LN_ONLY__ */ 
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_sync_confirm(PHB_ERRNO_BUSY, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

        if (control_block->proc_stage == SYNC_NONE)
        {
            control_block->proc_stage = SYNC_READ_FILE;
            control_block->IO_cnf_receive = phb_sync_handler;

        #ifdef __GEMINI__
            if (sim_service_table_query(SERVICE_LND, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT)
        #else /* __GEMINI__ */
            if (sim_service_table_query(SERVICE_LND) == SERVICE_SUPPORT)
        #endif /* __GEMINI__ */
            {
                sim_file_info_req_struct *param_ptr;

                /* SIM card supports LND, get file info */
                param_ptr = (sim_file_info_req_struct*)
                    construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

                param_ptr->file_idx = FILE_LND_IDX;
                param_ptr->access_id = control_block->ID;
                phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
                return;
            }
            else
            {
                /* SIM card doesn't support LND, no need to sync */
                phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_FILE)
        {
            sim_file_info_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
            #if (MAX_PHB_LN_ENTRY > 20)
                kal_uint8 total;
            #endif 
                if (msg_ptr->num_of_rec == 0)
                {
                    /* SIM card LND num is 0l, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
                control_block->seg_len = msg_ptr->file_size / msg_ptr->num_of_rec;
            #if (MAX_PHB_LN_ENTRY > 20)
                total = phb_get_ln_total_entry(PHB_LND);
                if (total < msg_ptr->num_of_rec)
                {
                    control_block->seg_total = total;
                }
                else
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                    /* save SIM card LND file info, read NVRAM LND data */
                    control_block->seg_total = msg_ptr->num_of_rec;
                control_block->length = msg_ptr->file_size;

                control_block->index = msg_ptr->num_of_rec;
                control_block->proc_stage = SYNC_ERASE_SIM;
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = (control_block->seg_total + PHB_MAX_LN_ENTRIES - 1) / PHB_MAX_LN_ENTRIES;
                if (control_block->total > 2)
                {
                    control_block->secondary_ID = PHB_LND_LID_START + control_block->total - 2;
                }
                else
                {
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
                control_block->actual_count = control_block->seg_total;
                control_block->seg_total -=
                    ((control_block->secondary_ID - PHB_LND_LID_START) * PHB_MAX_LN_ENTRIES);
            #else /* (MAX_PHB_LN_ENTRY > 20) */ 
                control_block->secondary_ID = PHB_LND_LID_START;
                control_block->total = PHB_TOT_LND_LIDS;
            #endif /* MAX_PHB_LN_ENTRY > 20 */
            #ifdef __GEMINI__
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ */
                control_block->data = NULL;
                phb_write_ln_to_erase_sim(control_block);
                return;
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_ERASE_SIM)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                control_block->index--;
                if (control_block->index > 0)
                {
                    phb_write_ln_to_erase_sim(control_block);
                    return;
                }
                else
                {
                    control_block->proc_stage = SYNC_READ; /* index will be set to 0xFFFF */
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

                if (control_block->total > 1)
                {
                    /* NVRAM has more than one LND LID, continue to read */
                    control_block->proc_stage = SYNC_READ_CONTINUE;
                    control_block->secondary_ID++;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
                {
                    /* NVRAM only has one LND LID, prepare to write to SIM */
                    control_block->index = 0;
                    control_block->proc_stage = SYNC_WRITE_CONTINUE;
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            }
            else
            {
                /* read NVRAM fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_CONTINUE)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (void*)ilm_ptr->peer_buff_ptr;
            }
            /* all NVRAM LND LIDs are read, prepare to write to SIM */
            control_block->index = 0;
            control_block->proc_stage = SYNC_WRITE_CONTINUE;
            phb_write_ln_to_sim(control_block);
            return;
        }
        else if (control_block->proc_stage == SYNC_WRITE_CONTINUE)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                if (control_block->index < control_block->seg_total)
                {
                    /* SIM card LND still has space, continue to write */
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->index < control_block->actual_count)
                {
                    if (control_block != NULL)
                    {
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                        }
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                        }
                    }
                    control_block->proc_stage = SYNC_READ;
                    control_block->actual_count -= control_block->seg_total;
                    control_block->total = control_block->actual_count / PHB_MAX_LN_ENTRIES;
                    if (control_block->total > 1)
                    {
                        control_block->secondary_ID -= 3;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                    }
                    if (control_block->actual_count > PHB_MAX_LN_ENTRIES)
                    {
                        control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                    }
                    else
                    {
                        control_block->seg_total = PHB_MAX_LN_ENTRIES;
                    }
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                else
                {
                    /* SIM card LND full, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
    }
    #endif /* __PHB_NVRAM_LN_ONLY__ */ 
}
#endif /* __VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  phb_sync_confirm
 * DESCRIPTION
 *  This is phb_sync_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sync_confirm(phb_errno_enum result, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block != NULL)
    {
        if (control_block->peer_buf_ptr != NULL)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
}   /* end of phb_sync_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_handler
 * DESCRIPTION
 *  This is phb_write_ln_handler function of PHB module.
 *  Handles write last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
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
            l4cphb_write_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_write_ln_req_struct*) ilm_ptr->local_para_ptr;

            control_block = phb_alloc_control_block();
            /* Cannot allocate, means that PHB is still operating. Reject request! */
            if (control_block == NULL)
            {
                phb_write_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        if (control_block->proc_stage == WRITE_LN_NONE)
        {
            kal_uint16 length;
            l4cphb_write_ln_req_struct *msg_ptr = (l4cphb_write_ln_req_struct*) ilm_ptr->local_para_ptr;
            l4cphb_phb_ln_entry_array_struct *pdu_data;

            pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);

            ASSERT(msg_ptr->total <= PHB_MAX_LN_ENTRIES);
            /* save req info */
            control_block->proc_stage = WRITE_LN_READ;
            control_block->IO_cnf_receive = phb_write_ln_handler;

            control_block->type = msg_ptr->type;
            control_block->src_id = msg_ptr->src_id;
            control_block->total_piggyback = msg_ptr->total;
            control_block->index = msg_ptr->index;

            /* keep entry to be written in peer_buf_ptr */
            hold_peer_buff(ilm_ptr->peer_buff_ptr);
            control_block->need_free_peer = KAL_TRUE;
            control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

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

            if (msg_ptr->index != 0xff)
            {
                control_block->seg_total = 1;
                control_block->secondary_ID += msg_ptr->index / PHB_MAX_LN_ENTRIES;
            }
        #ifdef __GEMINI__
            if (phb_current_mod == MOD_PHB_2)
            {
                control_block->secondary_ID += PHB_TOTAL_LN_LID;
            }
        #endif /* __GEMINI__ */
            phb_read_ln_from_nvram(control_block);
            return;
        }
        else if (control_block->proc_stage == WRITE_LN_READ)
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

                if (control_block->seg_total > 1)
                {
                    control_block->secondary_ID++;
                    control_block->proc_stage = WRITE_LN_READ_CONTINUE;
                    control_block->seg_total--;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
                {
                    control_block->proc_stage = WRITE_LN_WRITE;

                    if (control_block->index == 0xff)
                    {
                        updated = phb_update_ln(NULL, control_block);   /* for ln_10 or not full ln_50 */
                    }
                    else
                    {
                        updated = phb_edit_ln(control_block);
                    }

                    if (updated == KAL_TRUE)
                    {
                        /* write LND file */
                        phb_write_ln_to_nvram(NULL, control_block);
                        return;
                    }
                }
            }
            /* 1. NVRAM IO Err      2. se_total is 1 and updated is FALSE */
            phb_write_ln_confirm(PHB_ERRNO_READ_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_READ_CONTINUE)
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

                updated = phb_update_ln(pdu_data, control_block);
                if (control_block->seg_total > 0)
                {
                    control_block->seg_total--;
                }

                if (updated == KAL_TRUE)
                {
                    control_block->proc_stage = WRITE_LN_WRITE_CONTINUE;

                    /* write second file */
                    phb_write_ln_to_nvram(pdu_data, control_block);
                    return;
                }
            }
            /* 1. NVRAM IO Err      2. updated is FALSE */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_WRITE_CONTINUE)
        {
            nvram_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                control_block->proc_stage = WRITE_LN_WRITE;
                control_block->secondary_ID--;

                /* write first file */
                phb_write_ln_to_nvram(NULL, control_block);
                return;
            }
            /* NVRAM IO Err */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_WRITE)
        {
            nvram_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->seg_total > 0)
                {
                    control_block->secondary_ID += 2;   /* back to second from first and then plus 1 to 3 */
                    control_block->proc_stage = WRITE_LN_READ;
                    if (control_block->data != NULL)
                    {
                        free_peer_buff((peer_buff_struct*) control_block->data);
                    }
                    phb_read_ln_from_nvram(control_block);
                }
                else
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                    phb_write_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
            }
            else
            {
                phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
        }
        else
        {
            /* wrong proc_stage for write_ln_handler */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
    }
    else
    {
        phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}


#if (MAX_PHB_LN_ENTRY > 20)
/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_old_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_old_entry(nvram_ef_phb_ln_struct *record, nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_ln_entry_struct buffer_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_cpy(&buffer_entry, &record2->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    if (record2->no_entry > 0)
    {
        phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);
    }
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
    kal_mem_cpy(&record->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));

    kal_mem_cpy(&shifted_entry, &buffer_entry, sizeof(phb_ln_entry_struct));

    record->array[0].count = 1;
    if (record2->no_entry < PHB_MAX_LN_ENTRIES)
    {
        record2->no_entry++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  entry       [?]     
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry)
    {
        kal_mem_cpy(&shifted_entry, &record2->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
        phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);
        kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
        phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
        kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
        record->array[0].count = 1;
        if (record2->no_entry < PHB_MAX_LN_ENTRIES)
        {
            record2->no_entry++;
        }
    }
    else
    {
        phb_ln_push_old_entry(record, record2);
    }
}
#endif /* MAX_PHB_LN_ENTRY > 20 */


#ifdef __PHB_RECORD_LN_TYPE_SEQ__
/*****************************************************************************
 * FUNCTION
 *  phb_shift_ln_type_seq
 * DESCRIPTION
 *  This is phb_shift_ln_type_seq function of PHB module.
 *  Shift the ln type sequence to the right position
 *  from latest(0) to oldest(PHB_TOTAL_LN_ENTRIES-1).
 * PARAMETERS
 *  del_seq_index       [IN]        
 *  type                [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_shift_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 del_index = PHB_TOTAL_LN_ENTRIES - 1;
    kal_uint8 update_type = phb_ln_type_seq[0];
    kal_uint8 tmp_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (del_seq_index > 0)
    {
        for (del_index = PHB_TOTAL_LN_ENTRIES - 1; del_seq_index > 0; del_index--)
        {
            if (phb_ln_type_seq[del_index] == type)
            {
                del_seq_index--;
            }
            if (del_index == 0) /* in case the nvram data item is missing */
            {
                break;
            }
        }
        del_index++;
    }
    while (i < del_index && phb_ln_type_seq[i] != 0xff)
    {
        tmp_type = phb_ln_type_seq[i + 1];
        phb_ln_type_seq[i + 1] = update_type;
        update_type = tmp_type;
        i++;
    }
    phb_ln_type_seq[0] = type;
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_type_seq_handler
 * DESCRIPTION
 *  This is phb_write_ln_type_seq_handler function of PHB module.
 *  Handles write last number type seqence for mixed call log.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_type_seq_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block == NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);
    }

    if (control_block->proc_stage == WRITE_LN_TYPE_SEQ_NONE)
    {
        control_block->IO_cnf_receive = phb_write_ln_type_seq_handler;
        control_block->proc_stage = WRITE_LN_TYPE_SEQ_CONTINUE;
        /* control_block->secondary_ID = 1; */
        phb_write_ln_type_seq_to_nvram(control_block);
        return;
    }
    else if (control_block->proc_stage == WRITE_LN_TYPE_SEQ_CONTINUE)
    {
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;
        //if (control_block->data != NULL)
        //   free_peer_buff ((peer_buff_struct *)control_block->data);
        if (control_block->need_free_peer == KAL_TRUE)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        phb_free_control_block(control_block);
        if (msg_ptr->result != NVRAM_IO_ERRNO_OK)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
        }
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_confirm
 * DESCRIPTION
 *  This is phb_write_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
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
    param_ptr->type = 0;

    if (result != PHB_ERRNO_BUSY)
    {
        ASSERT(control_block != NULL);
        param_ptr->type = (kal_uint8) control_block->type;

        param_ptr->total = control_block->total;

        if ((result == PHB_ERRNO_SUCCESS) && (control_block->total_piggyback > 0))
        {
            param_ptr->total = control_block->total_piggyback;
        }

        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        if (control_block->need_free_peer == KAL_TRUE)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        phb_free_control_block(control_block);
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        if (result == PHB_ERRNO_SUCCESS)
        {
        #ifdef __PHB_LN_SINGLE_COUNT__
            if (phb_get_ln_total_entry(param_ptr->type) == PHB_MAX_LNM_ENTRIES)
            {
                /* full */
                phb_shift_ln_type_seq(1, param_ptr->type);
            }
            else
            {
                /* add new entry for type seq */
                phb_shift_ln_type_seq(0, param_ptr->type);
            }
        #endif /* __PHB_LN_SINGLE_COUNT__ */ 

            phb_write_ln_type_seq_handler(NULL, NULL);
        }
    #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    }
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_LN_CNF, param_ptr, NULL);
}   /* end of phb_write_ln_confirm */


#ifndef __PHB_LN_SINGLE_COUNT__
/*****************************************************************************
 * FUNCTION
 *  phb_compare_bcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length1     [IN]        
 *  length2     [IN]        
 *  bcd1        [?]         
 *  bcd2        [?]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_compare_bcd(kal_uint8 length1, kal_uint8 length2, kal_uint8 *bcd1, kal_uint8 *bcd2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_LN_EXACT_MATCH__

    if (length1 != length2)
    {
        return KAL_FALSE;
    }

    for (i = 0; i < length1; i++)
    {
        if (bcd1[i] != bcd2[i])
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;

#else /* __PHB_LN_EXACT_MATCH__ */ 

    kal_int16 j, match = 0, min_len;
    kal_int16 len1, len2;
    kal_uint8 temp1[MAX_CC_ADDR_LEN * 2], temp2[MAX_CC_ADDR_LEN * 2];
    kal_uint8 *temp1_number;
    kal_uint8 *temp2_number;
    kal_uint8 condition;

    len1 = convert_to_digit(&bcd1[1], temp1);
    len2 = convert_to_digit(&bcd2[1], temp2);

    /* Ignore *31# and #31# case */
    temp1_number = (kal_uint8*) temp1;
    temp2_number = (kal_uint8*) temp2;
    while (((temp1_number[0] == '*') || (temp1_number[0] == '#')) &&
           (temp1_number[1] == '3') && (temp1_number[2] == '1') && (temp1_number[3] == '#'))
    {
        temp1_number += 4;
        len1 -= 4;
    }
    while (((temp2_number[0] == '*') || (temp2_number[0] == '#')) &&
           (temp2_number[1] == '3') && (temp2_number[2] == '1') && (temp2_number[3] == '#'))
    {
        temp2_number += 4;
        len2 -= 4;
    }

    /*
     * #ifdef __PHB_COMPARE_NUMBER_9_DIGIT__
     * condition = 9;
     * #endif
     */
    if (phb_ptr->compare_digit < 6 || phb_ptr->compare_digit > (MAX_CC_ADDR_LEN - 1))
    {
        condition = 6;
    }
    else
    {
        condition = phb_ptr->compare_digit;
    }

    if (len1 > len2)
    {
        min_len = len2;
    }
    else
    {
        min_len = len1;
    }

    for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (temp1_number[i] == temp2_number[j])
        {
            match++;
        }
        else
        {
            break;
        }
    }
    if (match >= condition || (match == min_len && len1 == len2))
    {
        if (len1 > len2)
        {
            kal_mem_cpy(bcd2, bcd1, MAX_CC_ADDR_LEN);
        }
        return KAL_TRUE;
    }

    return KAL_FALSE;

#endif /* __PHB_LN_EXACT_MATCH__ */ 
}

#ifdef __PHB_RECORD_LN_TYPE_SEQ__


/*****************************************************************************
 * FUNCTION
 *  phb_update_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  total       [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static phb_update_ln_type_seq(kal_uint16 pos, kal_uint16 total, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos == total)
    {
        if (total == PHB_MAX_LNM_ENTRIES)
        {
            /* full */
            phb_shift_ln_type_seq(1, type);
        }
        else
        {
            /* add new entry for type seq */
            phb_shift_ln_type_seq(0, type);
        }
    }
    else if (pos == 0 && total > 0) /* itself */
    {
        phb_shift_ln_type_seq(total, type);
    }
    else
    {
        phb_shift_ln_type_seq(pos, type);
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

#endif /* __PHB_LN_SINGLE_COUNT__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_update_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record              [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_update_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 total, i;
    kal_uint8 *pdu_ptr;
    kal_uint16 len;
    phb_ln_entry_struct *entry = NULL;
    l4cphb_phb_ln_entry_array_struct *pdu_data = NULL;
    nvram_ef_phb_ln_struct *record0 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block->need_free_peer)
    {
        /* get entry to be written */
        pdu_ptr = get_pdu_ptr(control_block->peer_buf_ptr, &len);

        pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);

        entry = (phb_ln_entry_struct*) & pdu_data->array[0];
        entry->call_duration = 0;
    }

    record0 = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &len);

    if (record != NULL)
    {
        total = record->no_entry + record0->no_entry;
    }
    else
    {
        total = record0->no_entry;
    }

#ifdef __PHB_LN_SINGLE_COUNT__  /* don't need to find the same record */
    i = total;

#else /* __PHB_LN_SINGLE_COUNT__ */ 
    for (i = 0; i < total; i++)
    {
        if (i < PHB_MAX_LN_ENTRIES)
        {
#ifdef __VOIP__
            if (entry->addr_type == PHB_LN_VOIP && record0->array[i].addr_type == PHB_LN_VOIP &&
                strcmp((char*)entry->addr_bcd, (char*)record0->array[i].addr_bcd) == 0)
            {
                break;
            }
            else if (entry->addr_type == PHB_LN_CALL&& record0->array[i].addr_type == PHB_LN_CALL)
#endif /* __VOIP__ */
            if (phb_compare_bcd(
                    entry->addr_length,
                    record0->array[i].addr_length,
                    (kal_uint8*) entry->addr_bcd,
                    (kal_uint8*) record0->array[i].addr_bcd) == KAL_TRUE)
            {
                break;
            }
        }
        else if (record != NULL)
        {
#ifdef __VOIP__
            if (entry->addr_type == PHB_LN_VOIP && record0->array[i - PHB_MAX_LN_ENTRIES].addr_type == PHB_LN_VOIP &&
                strcmp((char*)entry->addr_bcd, (char*)record0->array[i - PHB_MAX_LN_ENTRIES].addr_bcd) == 0)
            {
                break;
            }
            else if (entry->addr_type == PHB_LN_CALL&& record0->array[i].addr_type == PHB_LN_CALL)
#endif /* __VOIP__ */
            {
                if (phb_compare_bcd(
                        entry->addr_length,
                        record->array[i - PHB_MAX_LN_ENTRIES].addr_length,
                        (kal_uint8*) entry->addr_bcd,
                        (kal_uint8*) record->array[i - PHB_MAX_LN_ENTRIES].addr_bcd) == KAL_TRUE)
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    phb_update_ln_type_seq((kal_uint16)i, (kal_uint16)total, (kal_uint8) control_block->type);
#endif 
#endif /* __PHB_LN_SINGLE_COUNT__ */ 

#if (MAX_PHB_LN_ENTRY > 20)
    if (control_block->seg_total > 1 && total == PHB_MAX_LN_ENTRIES * 2)
    {
        /* no empty space, update the first 2 LN entries first. */
        phb_ln_push_entry(entry, record0, record);
    }
    else if (total < PHB_MAX_LN_ENTRIES)
    {
        /* file still has space, add new entry and update in file 1 */
        if (record0->no_entry > 0)
        {
            phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
        }
        if (!entry) /* The entry is released. Not the first round. */
        {
            kal_mem_cpy(&record0->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));
            control_block->seg_total = 0;
        }
        else
        {
            kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
        }
        record0->array[0].count = 1;
        record0->no_entry++;
        total++;
    }
    else if (total > PHB_MAX_LN_ENTRIES && total < (PHB_MAX_LN_ENTRIES * 2))
    {
        /* file 1 is full, file 2 still has stpace, over write to file 2 */
        if (control_block->seg_total > 0)
        {
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_entry(entry, record0, record);
            total++;
            control_block->seg_total = 0;
        }
        else
        {
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_new_entry(entry, record0, record);
            total++;
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES)
    {
        if (record != NULL)
        {
            if (control_block->seg_total > 1 || (!entry && record->no_entry == 0))
            {
                phb_ln_push_entry(entry, record0, record);
            }
            else
            {
                /* file 1 is full, file 2 still has stpace, over write to file 2 */
                phb_ln_push_new_entry(entry, record0, record);
            }
            total++;
        }
        else
        {
            /* file 1 is full, corrupt last */
            phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
            if (!control_block->need_free_peer)
            {
                /* the last entry */
                kal_mem_cpy(&record0->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));
                if (control_block->seg_total == 1)  /* last one */
                {
                    control_block->seg_total = 0;
                }
            }
            else
            {
                kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
            }
            record0->array[0].count = 1;
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES * 2)
    {
        if (!entry) /* not first round */
        {
            phb_ln_push_entry(entry, record0, record);
        }
        else
        {
            phb_ln_push_new_entry(entry, record0, record);
        }
    }
    if (control_block->seg_total > 1 && total < PHB_MAX_LN_ENTRIES * 2) /* treat as only 2 ln records */
    {
        control_block->seg_total = 0;
    }
#else /* (MAX_PHB_LN_ENTRY > 20) */ 
    if (total < PHB_MAX_LN_ENTRIES)
    {
        /* file still has space, update in file 1 */
        if (i == total)
        {
            /* not found, add new entry in file 1 */
            if (record0->no_entry > 0)
            {
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
            }
            kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
            record0->array[0].count = 1;
            record0->no_entry++;
            total++;
        }
        else
            /* found, renew old entry in file 1 */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
    }
    else if (total > PHB_MAX_LN_ENTRIES && total < (PHB_MAX_LN_ENTRIES * 2))
    {
        /* file 1 is full, file 2 still has stpace, over write to file 2 */
        if (i == total)
        {
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_new_entry(entry, record0, record);
            total++;
        }
        else if (i < PHB_MAX_LN_ENTRIES)
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
        else
            /* found in file 2, renew old entry */
        {
            phb_ln_renew_entry2((kal_uint8) (i - PHB_MAX_LN_ENTRIES), entry, record0, record);
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES)
    {
        if (i == total) /* not found, add new entry */
        {
            if (record != NULL)
            {
                /* file 1 is full, file 2 still has stpace, over write to file 2 */
                phb_ln_push_new_entry(entry, record0, record);
                total++;
            }
            else
            {
                /* file 1 is full, corrupt last */
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
                kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
                record0->array[0].count = 1;
            }
        }
        else
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES * 2)
    {
        /* no empty space */
        if (i == total)
        {
            /* not found */
            phb_ln_push_new_entry(entry, record0, record);
        }
        else if (i < PHB_MAX_LN_ENTRIES)
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
        else
            /* found in file 2, renew old entry */
        {
            phb_ln_renew_entry2((kal_uint8) (i - PHB_MAX_LN_ENTRIES), entry, record0, record);
        }
    }
#endif /* MAX_PHB_LN_ENTRY > 20 */

    control_block->total = total;
    if (total < control_block->total_piggyback)
    {
        control_block->total_piggyback = total;
    }

    if (control_block->need_free_peer)
    {
        free_peer_buff(control_block->peer_buf_ptr);
        control_block->need_free_peer = KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_edit_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_edit_ln(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_uint8 *pdu_ptr;
    kal_uint16 len;
    phb_ln_entry_struct *entry;
    l4cphb_phb_ln_entry_array_struct *pdu_data;
    nvram_ef_phb_ln_struct *record = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get entry to be edit */
    pdu_ptr = get_pdu_ptr(control_block->peer_buf_ptr, &len);

    pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);

    entry = (phb_ln_entry_struct*) & pdu_data->array[0];

    record = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &len);

    i = control_block->index % PHB_MAX_LN_ENTRIES;
    kal_mem_cpy(&record->array[i], entry, sizeof(phb_ln_entry_struct));
    control_block->total = 0;
#if (MAX_PHB_LN_ENTRY > 20)
    control_block->seg_total = 0;
#endif 
    return KAL_TRUE;
}


#if (MAX_PHB_LN_ENTRY <= 20)
/*****************************************************************************
 * FUNCTION
 *  phb_ln_renew_entry1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  entry       [?]         
 *  record      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_renew_entry1(kal_uint8 index, phb_ln_entry_struct *entry, nvram_ef_phb_ln_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->array[index].count < 255)
    {
        entry->count = record->array[index].count + 1;
    }

    phb_shift_ln((kal_uint8) (index - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
}


/*****************************************************************************
 * FUNCTION
 *  phb_ln_renew_entry2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  entry       [?]         
 *  record      [?]         
 *  record2     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_renew_entry2(
                kal_uint8 index,
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->array[index].count < 255)
    {
        entry->count = record2->array[index].count + 1;
    }
    phb_shift_ln((kal_uint8) (index - 1), record2);
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
}
#endif /* (MAX_PHB_LN_ENTRY <= 20) */ /* MAX_PHB_LN_ENTRY <= 20 */


/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_new_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  entry       [?]     
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_new_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
    record->array[0].count = 1;
    if (record2->no_entry < PHB_MAX_LNM_ENTRIES - PHB_MAX_LN_ENTRIES)
    {
        record2->no_entry++;
    }
}

