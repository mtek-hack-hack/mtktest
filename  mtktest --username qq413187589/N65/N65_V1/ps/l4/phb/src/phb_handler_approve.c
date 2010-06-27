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
 * phb_handler_approve.c
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
 * removed!
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
#include "phb_handler_approve.h"

#include "smu_common_enums.h"
#include "l3_inc_enums.h"

#include "phb_sap.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_APPROVE_C_

static kal_bool phb_approve_ecc(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    phb_entry_struct *phb_entry);
static kal_bool phb_approve_sat_ecc(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    phb_entry_struct *phb_entry);                    
static kal_bool phb_approve_fdn(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    l4cphb_approve_req_struct *l4cphb_approve_req);
static void phb_approve_rest_for_PHB_not_ready(l4cphb_approve_req_struct *l4cphb_approve_req);
static void phb_approve_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_approve_continue(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_approve_confirm(
                phb_errno_enum result,
                phb_type_enum type,
                kal_uint8 src_id,
                control_block_type *control_block,
                phb_entry_struct *phb_entry);
static kal_bool phb_compare_tel_number_prefix(l4_addr_bcd_struct *given, l4_addr_bcd_struct *candidate);

typedef enum
{
    phb_ecc_num_911,
    phb_ecc_num_E911,   /* +911 */
#if defined(__MEXICO_ECC__)
    phb_ecc_num_080,
    phb_ecc_num_E080,
    phb_ecc_num_060,
    phb_ecc_num_E060,
    phb_ecc_num_08,
    phb_ecc_num_E08,
#endif /* defined(__MEXICO_ECC__) */ 
#if defined(__CPHS__)
    phb_ecc_num_999,
    phb_ecc_num_E999,
#endif /* defined(__CPHS__) */
#if defined(__RUSSIA_ECC__)
    phb_ecc_num_01,
    phb_ecc_num_E01,
    phb_ecc_num_02,
    phb_ecc_num_E02,
    phb_ecc_num_03,
    phb_ecc_num_E03,
    phb_ecc_num_001,
    phb_ecc_num_E001,        
    phb_ecc_num_002,
    phb_ecc_num_E002,
    phb_ecc_num_003,
    phb_ecc_num_E003,
#endif /* defined(__RUSSIA_ECC__) */
    phb_ecc_num_112,
    phb_ecc_num_E112,
    phb_ecc_num_total
} eum_phb_ecc_num;

static kal_uint8 phb_ecc_num[phb_ecc_num_total * NUM_OF_BYTE_ECC] = 
{
    0x19, 0xf1, 0xff,
    0x9e, 0x11, 0xff,
#if defined(__MEXICO_ECC__)
    0x80, 0xf0, 0xff,
    0x0e, 0x08, 0xff,
    0x60, 0xf0, 0xff,
    0x0e, 0x06, 0xff,
    0x80, 0xff, 0xff,
    0x0e, 0xf8, 0xff,
#endif /* defined(__MEXICO_ECC__) */ 
#if defined(__CPHS__)
    0x99, 0xf9, 0xff,
    0x9e, 0x99, 0xff,
#endif /* defined(__CPHS__) */
#if defined(__RUSSIA_ECC__)
    0x10, 0xff, 0xff,
    0x0e, 0xf1, 0xff,
    0x20, 0xff, 0xff,
    0x0e, 0xf2, 0xff,
    0x30, 0xff, 0xff,
    0x0e, 0xf3, 0xff,
    0x00, 0xf1, 0xff,
    0x0e, 0x10, 0xff,
    0x00, 0xf2, 0xff,
    0x0e, 0x20, 0xff,
    0x00, 0xf3, 0xff,
    0x0e, 0x30, 0xff,
#endif /* defined(__RUSSIA_ECC__) */ 
    0x11, 0xf2, 0xff,
    0x1e, 0x21, 0xff
};

typedef enum
{
    phb_sat_ecc_num_911,
    phb_sat_ecc_num_E911,   /* +911 */
    phb_sat_ecc_num_112,
    phb_sat_ecc_num_E112,
    phb_sat_ecc_num_total
} eum_phb_sat_ecc_num;

static kal_uint8 phb_sat_ecc_num[phb_sat_ecc_num_total * NUM_OF_BYTE_ECC] = 
{
    0x19, 0xf1, 0xff,
    0x9e, 0x11, 0xff,
    0x11, 0xf2, 0xff,
    0x1e, 0x21, 0xff
};


/*****************************************************************************
 * FUNCTION
 *  phb_approve_handler
 * DESCRIPTION
 *  This is phb_approve_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_approve_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_APPROVE);

    if (ilm_ptr != NULL)
    {
        l4cphb_approve_req_struct *l4cphb_approve_req;

        l4cphb_approve_req = (l4cphb_approve_req_struct*) ilm_ptr->local_para_ptr;

        /*  If dn_type is not given at phb startup time, try to reget when approve call. */
        if (phb_ptr->dn_type == TYPE_NONE || phb_ptr->dn_type == 0xff)
        {
            phb_ptr->dn_type = l4csmu_get_dial_mode();
        }

        kal_trace(TRACE_INFO, INFO_PHB_STARTUP_MODE, phb_ptr->dn_type);

        control_block = phb_alloc_control_block();

        /* according to sim owner, if dn_type == TYPE_NONE, it means that sim is not ready */
        /* so only the ecc could be dial, others will be approve FAIL */
        if (phb_ptr->dn_type == TYPE_NONE)
        {
            l4_addr_bcd_struct *tel_number = &l4cphb_approve_req->tel_number;
            phb_entry_struct phb_entry;

            if (phb_approve_ecc(NULL, tel_number, &phb_entry) == KAL_TRUE)
            {
            /**
             * This statement is due to PHB is not ready,
             * but control_block is successfully allocated.
             */
                if (control_block != NULL)
                {
                    phb_free_control_block(control_block);
                }

                phb_approve_confirm(PHB_ERRNO_SUCCESS, PHB_ECC, l4cphb_approve_req->src_id, NULL, &phb_entry);
                return;
            }
            else
            {
                if (control_block != NULL)
                {
                    phb_free_control_block(control_block);
                }                

                phb_approve_confirm(
                    PHB_ERRNO_FAIL,
                    PHB_NONE,
                    l4cphb_approve_req->src_id,
                    NULL,
                    NULL);
                return;
            }      
        }

      /**
       * Appove is a special case. PHB must support for approval
       * when it is not ready.
       * Hence, allocation of control_block is examined after PHB is ready.
       */

      /**
       * If control_block cannot be allocated, means that maximum concurrency
       * degree of PHB is reached.
       * However, appoval must be continued, request cannot be rejected.
       */
        if ((phb_ptr->state == PHB_STATE_READY) && (control_block != NULL))
        {
            control_block->src_id = l4cphb_approve_req->src_id;
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;

            if (control_block->proc_stage == APPROVE_NONE)
            {
                l4_addr_bcd_struct *tel_number;

                tel_number = &l4cphb_approve_req->tel_number;
                control_block->actual_count = 0;

                /* Approve ECC! */
                if (phb_approve_ecc(control_block, tel_number, &control_block->temp_entry) == KAL_TRUE)
                {
                    control_block->actual_count = control_block->total = 1;
                    control_block->type = PHB_ECC;

                    phb_approve_confirm(
                        PHB_ERRNO_SUCCESS,
                        control_block->type,
                        control_block->src_id,
                        control_block,
                        NULL);
                    return;
                }

            /**
             * *Sigh*, Not an ECC.
             * So, pray that FDN is not enabled
             *
             * Since PHB is already startup-ed,
             * dn_type is followed to approve a dialling number.
             */

                if (phb_approve_fdn(control_block, tel_number, l4cphb_approve_req) == KAL_TRUE)
                {
                    return;
                }

            /**
             * Type could be ADN, BDN, or ADN_BDN.
             * No matter which type is, at this moment, this attempting phone number
             * is APPROVED!
             */
                if ((phb_ptr->dn_type == TYPE_ADN) || (phb_ptr->dn_type == TYPE_ADN_BDN))
                {
                    kal_bool is_more_candidates;

                    control_block->type = PHB_PHONEBOOK;

                    /* Searching into phone book is not necessary. Good! */
                    if (l4cphb_approve_req->is_retrieve != KAL_TRUE)
                    {
                        control_block->proc_stage = APPROVE_FDN;
                        phb_approve_confirm(
                            PHB_ERRNO_SUCCESS,
                            control_block->type,
                            control_block->src_id,
                            control_block,
                            NULL);
                        return;
                    }

                    /* Searching required. Make *FAKE* search by PHB_BYNUMBER request */
                    else
                    {
                        l4_addr_bcd_struct *tel_number;

                        tel_number = &l4cphb_approve_req->tel_number;
                        control_block->candidate_name_num_index = phb_se_search_by_tel_num(
                                                                    control_block->type,
                                                                    tel_number,
                                                                    &control_block->candidate,
                                                                    &is_more_candidates);

                        /* No candidates. Great! */
                        if ((control_block->candidate == (kal_uint16) PHB_INVALID_VALUE) ||
                            (control_block->candidate_name_num_index == NULL))
                        {
                            control_block->actual_count = 0;
                            phb_approve_confirm(
                                PHB_ERRNO_SUCCESS,
                                control_block->type,
                                control_block->src_id,
                                control_block,
                                NULL);
                            return;
                        }

                        /* So, let's search... */
                        control_block->match_result = MATCH_FAIL;

                        /* One entry of l4cphb_phb_entry_array_struct will be allocated */
                        phb_search_fake(control_block, ilm_ptr, control_block->type, tel_number);

                        phb_search_continue(NULL, control_block);
                        return;
                    }
                }

            /**
             * What the hell is this type!?
             * Currently, treat it as FDN disabled.
             * Hence, it is ALWAYS approved, but searching is unnecessary,
             * since neither ADN nor FDN is enabled.
             */
                else if (phb_ptr->dn_type == TYPE_NONE)
                {
                    control_block->type = PHB_NONE;
                    control_block->actual_count = 0;
                    phb_approve_confirm(
                        PHB_ERRNO_SUCCESS,
                        control_block->type,
                        control_block->src_id,
                        control_block,
                        NULL);
                    return;
                }

                /* Exception case, dn_type is invalid! Make approval failed! */
                else
                {
                    control_block->type = PHB_NONE;
                    control_block->actual_count = 0;
                    phb_approve_confirm(
                        PHB_ERRNO_FAIL,
                        control_block->type,
                        control_block->src_id,
                        control_block,
                        NULL);
                    return;
                }
            }
            /* error */
            else
            {
                phb_approve_err_handler(NULL, control_block);
                return;
            }
        }

      /**
       * If PHB is not ready, this control path will be reached,
       * whether a control_block is allocated or not.
       *
       * Under such condition, ECC still need to be approved,
       * so does other dialling numbers accoding to dialing mode;
       * because, even maximum concurrency degree is reached,
       * user attempted dialling CANNOT be rejected.
       *
       * Sigh, so lousy...
       */
        else
        {
            /* Since control_block is not allocated, MUST NOT use it!! */
            l4_addr_bcd_struct *tel_number = &l4cphb_approve_req->tel_number;
            phb_entry_struct phb_entry;

            kal_trace(TRACE_STATE, ERROR_PHB_STATE);

            if (phb_approve_ecc(NULL, tel_number, &phb_entry) == KAL_TRUE)
            {
            /**
             * This statement is due to PHB is not ready,
             * but control_block is successfully allocated.
             */
                if (control_block != NULL)
                {
                    phb_free_control_block(control_block);
                }

                phb_approve_confirm(PHB_ERRNO_SUCCESS, PHB_ECC, l4cphb_approve_req->src_id, NULL, &phb_entry);
                return;
            }

            if (control_block != NULL)
            {
                control_block->src_id = l4cphb_approve_req->src_id;
                /* Retain msg_id */
                control_block->cnf_msg_id = ilm_ptr->msg_id;
                /* FDN can be approved only if control_block is allocated */
                if ((phb_ptr->state == PHB_STATE_NOT_READY_FDN_READY) &&
                    (phb_approve_fdn(control_block, tel_number, l4cphb_approve_req) == KAL_TRUE))
                {
                    return;
                }

            /**
             * This statement is due to PHB is not ready,
             * but control_block is successfully allocated.
             */
                phb_free_control_block(control_block);
            }

            phb_approve_rest_for_PHB_not_ready(l4cphb_approve_req);
            return;
        }

    }
    else
    {
        /* Verification over. */
        if (control_block->proc_stage == APPROVE_FDN || control_block->proc_stage == APPROVE_FDN_ONE_CHARACTER)
        {
            /* The attempting phone number matches no candidate, NOT APPROVED! */
            if (control_block->actual_count == 0)
            {
            /**
             * Since this entry is not approved by FDN (that implicitly means
             * FDN is enabled), it is uncessary to search into PHB_PHONEBOOK
             * for retrieving the entry that matches this phone number.
             */
                control_block->proc_stage = APPROVE_FDN;
                control_block->cause = PHB_CAUSE_FDN_BLOCKED;
                phb_approve_confirm(PHB_ERRNO_FAIL, control_block->type, control_block->src_id, control_block, NULL);
                return;
            }

            /* The attempting phone number matches some candidate, APPROVED! */
         /**
          * Should consider whether searching into PHB_PHONEBOOK is meaningful,
          * when FDN is enabled, and the attempting phone number is approved by
          * FDN ?!
          */
         /**
          * Currently, it is supposed searching into PHONEBOOK is meaningless.
          * Meanwhile, this is also the behavior that most ME providers adpoted.
          */
            control_block->proc_stage = APPROVE_FDN;
            phb_approve_confirm(PHB_ERRNO_SUCCESS, control_block->type, control_block->src_id, control_block, NULL);
            return;
        }
        /* error */
        else
        {
            phb_approve_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_approve_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_ecc
 * DESCRIPTION
 *  Standard ECC number is 112.
 *  This code is used to approve telephone number from
 *  statndard ECC and EFecc;  even when PHB is not ready or SIM not ready yet.
 *  Note that CPHS defines 999 ECC number.
 * PARAMETERS
 *  control_block       [?]         
 *  tel_number          [?]         
 *  phb_entry           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_approve_ecc(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    kal_uint8 i;
    kal_uint16 len;
    kal_uint16 len2;
    kal_uint8 c1 = 0;
    kal_bool bcd_flag = KAL_TRUE;
    kal_uint16 bcd_offset = 0;
    kal_uint16 bcd_n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First, examine if the attempting phone number is ECC */
    sim_ecc_struct *eccs = &phb_ptr->ecc;

    /* Clean phb_entry */
    kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

    for (i = 0; i < eccs->num_ecc; ++i)
    {
        /* Try exact matching ECC */
        len = bcd_len(&eccs->ecc[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
        len2 = bcd_len(
                &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                (kal_uint16) (tel_number->addr_length - L4_ADDR_BCD_TON_NPI_SIZE));
        if (len > len2)
        {
            continue;
        }

        if (len > 0 && compare_n_bcd(
                        &eccs->ecc[i * NUM_OF_BYTE_ECC],
                        &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        len) == 0)
        {
            if (len == len2)    /* same len */
            {
                result = KAL_TRUE;
            }
            else    /* len2 > len */
            {
                bcd_n = len;
                bcd_flag = KAL_TRUE;
                bcd_offset = 0;
                while (bcd_n > 0)
                {
                    bcd_offset = get_next_bcd_digit(
                                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                    bcd_offset,
                                    &bcd_flag,
                                    &c1);
                    bcd_n--;
                }
                bcd_offset = get_next_bcd_digit(
                                &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                bcd_offset,
                                &bcd_flag,
                                &c1);
                if (c1 == 0x0C || c1 == 0x0D)   /* with p or w */
                {
                    result = KAL_TRUE;
                }
            }
            if (result == KAL_TRUE)
            {
                len = (len + 1) >> 1;
                phb_entry->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                kal_mem_cpy(
                    &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    (void const*)&eccs->ecc[i * NUM_OF_BYTE_ECC],
                    len);

                phb_entry->storage = PHB_SIM;

                break;
            }
        }
    }

    /* Try to approve hardcoded ECC's */
    if (result == KAL_FALSE)
    {
        phb_entry->storage = PHB_STORAGE_NONE;
        for (i = 0; i < phb_ecc_num_total; ++i)
        {
            /* Try exact matching ECC */
            len = bcd_len(&phb_ecc_num[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
            len2 = bcd_len(
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    (kal_uint16) (tel_number->addr_length - L4_ADDR_BCD_TON_NPI_SIZE));
            if (len > len2)
            {
                continue;
            }

            if (compare_n_bcd(
                    &phb_ecc_num[i * NUM_OF_BYTE_ECC],
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    len) == 0)
            {
                if (len == len2)    /* same len */
                {
                    result = KAL_TRUE;
                }
                else    /* len2 > len */
                {
                    bcd_n = len;
                    bcd_flag = KAL_TRUE;
                    bcd_offset = 0;

                    while (bcd_n > 0)
                    {
                        bcd_offset = get_next_bcd_digit(
                                        &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                        bcd_offset,
                                        &bcd_flag,
                                        &c1);
                        bcd_n--;
                    }
                    bcd_offset = get_next_bcd_digit(
                                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                    bcd_offset,
                                    &bcd_flag,
                                    &c1);
                    if (c1 == 0x0C || c1 == 0x0D || c1 == 0x0E)   /* with p or w or + */
                    {
                        result = KAL_TRUE;
                    }
                }
                if (result == KAL_TRUE)
                {
                    len = (len + 1) >> 1;
                    phb_entry->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&eccs->ecc[i * NUM_OF_BYTE_ECC],
                        len);
                    break;
                }
            }
            i++; /* skip the first digit is + */
        }
    }
    /* Consider *31# or #31# case */
    if (((tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] == 0x3a ||
                  tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] == 0x3b) &&
                 tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 1] == 0xb1))
    {
        phb_entry->storage = PHB_STORAGE_NONE;
        for (i = 0; i < phb_ecc_num_total; ++i)
        {
            /* Try exact matching ECC */
            len = bcd_len(&phb_ecc_num[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
            len2 = bcd_len(
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                    (kal_uint16) (tel_number->addr_length - L4_ADDR_BCD_TON_NPI_SIZE - 2));
            if (len > len2)
            {
                continue;
            }

            if (compare_n_bcd(
                    &phb_ecc_num[i * NUM_OF_BYTE_ECC],
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                    len) == 0)
            {
                if (len == len2)    /* same len */
                {
                    result = KAL_TRUE;
                }
                else    /* len2 > len */
                {
                    bcd_n = len;
                    bcd_flag = KAL_TRUE;
                    bcd_offset = 0;
                    while (bcd_n > 0)
                    {
                        bcd_offset = get_next_bcd_digit(
                                        &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                                        bcd_offset,
                                        &bcd_flag,
                                        &c1);
                        bcd_n--;
                    }
                    bcd_offset = get_next_bcd_digit(
                                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                                    bcd_offset,
                                    &bcd_flag,
                                    &c1);
                    if (c1 == 0x0C || c1 == 0x0D || c1 == 0x0E)   /* with p or w or + */
                    {
                        result = KAL_TRUE;
                    }
                }
                if (result == KAL_TRUE)
                {
                    len = (len + 1) >> 1;
                    phb_entry->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_ecc_num[i * NUM_OF_BYTE_ECC],
                        len);
                    break;
                }
            }
        }
    }
    return result;
}   /* end of phb_approve_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_sat_ecc
 * DESCRIPTION
 *  Standard ECC number is 112.
 *  This code is used to approve telephone number from
 *  statndard ECC and EFecc;  even when PHB is not ready or SIM not ready yet.
 *  Note that CPHS defines 999 ECC number.
 * PARAMETERS
 *  control_block       [?]         
 *  tel_number          [?]         
 *  phb_entry           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_approve_sat_ecc(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    kal_uint8 i;
    kal_uint16 len;
    kal_uint16 len2;
    kal_uint8 c1 = 0;
    kal_bool bcd_flag = KAL_TRUE;
    kal_uint16 bcd_offset = 0;
    kal_uint16 bcd_n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clean phb_entry */
    kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

    /* Try to approve hardcoded ECC's */
    if (result == KAL_FALSE)
    {
        phb_entry->storage = PHB_STORAGE_NONE;
        for (i = 0; i < phb_sat_ecc_num_total; ++i)
        {
            /* Try exact matching ECC */
            len = bcd_len(&phb_sat_ecc_num[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
            len2 = bcd_len(
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    (kal_uint16) (tel_number->addr_length - L4_ADDR_BCD_TON_NPI_SIZE));
            if (len > len2)
            {
                continue;
            }

            if (compare_n_bcd(
                    &phb_sat_ecc_num[i * NUM_OF_BYTE_ECC],
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    len) == 0)
            {
                if (len == len2)    /* same len */
                {
                    result = KAL_TRUE;
                }
                else    /* len2 > len */
                {
                    bcd_n = len;
                    bcd_flag = KAL_TRUE;
                    bcd_offset = 0;

                    while (bcd_n > 0)
                    {
                        bcd_offset = get_next_bcd_digit(
                                        &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                        bcd_offset,
                                        &bcd_flag,
                                        &c1);
                        bcd_n--;
                    }
                    bcd_offset = get_next_bcd_digit(
                                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                                    bcd_offset,
                                    &bcd_flag,
                                    &c1);
                    if (c1 == 0x0C || c1 == 0x0D || c1 == 0x0E)   /* with p or w or + */
                    {
                        result = KAL_TRUE;
                    }
                }
                if (result == KAL_TRUE)
                {
                    len = (len + 1) >> 1;
                    phb_entry->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_sat_ecc_num[i * NUM_OF_BYTE_ECC],
                        len);
                    break;
                }
            }
            i++; /* skip the first digit is + */
        }
    }
    /* Consider *31# or #31# case */
    if (((tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] == 0x3a ||
                  tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] == 0x3b) &&
                 tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 1] == 0xb1))
    {
        phb_entry->storage = PHB_STORAGE_NONE;
        for (i = 0; i < phb_sat_ecc_num_total; ++i)
        {
            /* Try exact matching ECC */
            len = bcd_len(&phb_sat_ecc_num[i * NUM_OF_BYTE_ECC], NUM_OF_BYTE_ECC);
            len2 = bcd_len(
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                    (kal_uint16) (tel_number->addr_length - L4_ADDR_BCD_TON_NPI_SIZE - 2));
            if (len > len2)
            {
                continue;
            }

            if (compare_n_bcd(
                    &phb_sat_ecc_num[i * NUM_OF_BYTE_ECC],
                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                    len) == 0)
            {
                if (len == len2)    /* same len */
                {
                    result = KAL_TRUE;
                }
                else    /* len2 > len */
                {
                    bcd_n = len;
                    bcd_flag = KAL_TRUE;
                    bcd_offset = 0;
                    while (bcd_n > 0)
                    {
                        bcd_offset = get_next_bcd_digit(
                                        &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                                        bcd_offset,
                                        &bcd_flag,
                                        &c1);
                        bcd_n--;
                    }
                    bcd_offset = get_next_bcd_digit(
                                    &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET + 2],
                                    bcd_offset,
                                    &bcd_flag,
                                    &c1);
                    if (c1 == 0x0C || c1 == 0x0D || c1 == 0x0E)   /* with p or w or + */
                    {
                        result = KAL_TRUE;
                    }
                }
                if (result == KAL_TRUE)
                {
                    len = (len + 1) >> 1;
                    phb_entry->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_sat_ecc_num[i * NUM_OF_BYTE_ECC],
                        len);
                    break;
                }
            }
        }
    }
    return result;
}   /* end of phb_approve_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_fdn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block           [?]         
 *  tel_number              [?]         
 *  l4cphb_approve_req      [?]         
 *  ilm_ptr(?)              [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_approve_fdn(
                    control_block_type *control_block,
                    l4_addr_bcd_struct *tel_number,
                    l4cphb_approve_req_struct *l4cphb_approve_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_more_candidates;
    kal_uint8 fdn_proc_stage = APPROVE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * FDN enabled.
     *
     * When FDN is enabled, is_retrieve should be ignored.
     * Because, FDN defines just prefix, moreover, could be extended by user,
     * searching that phone number either in FDN or PHB_PHONEBOOK is
     * meaningless!
     *
     * Note:
     * FDN approved number need not be retrieved!!
     */
    if ((phb_ptr->dn_type == TYPE_FDN) || (phb_ptr->dn_type == TYPE_FDN_BDN))
    {
        l4_addr_bcd_struct *num_pattern;
        name_num_index_type *name_num_index;
        data_entry_struct *data_entry;

        control_block->type = PHB_FDN;
        control_block->candidate_name_num_index = 
            phb_se_compare_tel_number_with_first_character(control_block->type, tel_number, &control_block->candidate, &is_more_candidates);
        if ((control_block->candidate != (kal_uint16) PHB_INVALID_VALUE) &&
            (control_block->candidate_name_num_index != NULL))
        {
           /**
            * Since match the first character, it is ncessary to search into PHB_PHONEBOOK
            * for retrieving the entry that matches this TON.
            */
            fdn_proc_stage = APPROVE_FDN_ONE_CHARACTER;
        }
        else
        {
            control_block->candidate_name_num_index = phb_se_search_by_tel_num(control_block->type, tel_number, &control_block->candidate, &is_more_candidates);
            fdn_proc_stage = APPROVE_FDN;

            /* No candidates. Great! */
            if ((control_block->candidate == (kal_uint16) PHB_INVALID_VALUE) ||
                (control_block->candidate_name_num_index == NULL))
            {
                control_block->actual_count = 0;

             /**
              * Since this entry is not approved by FDN under
              * FDN enabled condition, it is uncessary to search into PHB_PHONEBOOK
              * for retrieving the entry that matches this phone number.
              */
                control_block->proc_stage = APPROVE_FDN;
                phb_approve_confirm(PHB_ERRNO_FAIL, control_block->type, control_block->src_id, control_block, NULL);
                return KAL_TRUE;
            }
        }
        /**
         * At least one candidate is found.
         * Must verify the attempting phone number with each candidate.
         */
        /**
         * Now hold local parameter, since we have to verify telephone number
         * Don't forget to release it.
         */
        num_pattern = (l4_addr_bcd_struct*) get_ctrl_buffer(sizeof(l4_addr_bcd_struct));
        kal_mem_cpy(num_pattern, (void const*)&l4cphb_approve_req->tel_number, sizeof(l4_addr_bcd_struct));

        phb_control_block_set_param(control_block, fdn_proc_stage, num_pattern, NULL);
        phb_control_block_set(
            control_block,
            phb_approve_continue,
            phb_approve_handler,
            phb_approve_err_handler,
            fdn_proc_stage);

        /**
         * Read specific record for verification.
         */
        phb_control_block_set_IO(control_block, control_block->type, (kal_uint16) PHB_INVALID_VALUE, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        name_num_index = (name_num_index_type*) control_block->candidate_name_num_index;
        data_entry =
            &name_num_index->data_entry_table.table[name_num_index->num_index.table[control_block->candidate].position];

        phb_se_set_control_block(
            control_block,
            OP_READ,
            (phb_storage_enum) data_entry->storage,
            data_entry->record_index);

        /**
         * Since phb_se_set_control_block() modifies control_block->proc_stage,
         * it has to be restored.
         */
        control_block->proc_stage = fdn_proc_stage;

        control_block->data = (kal_uint8*) & control_block->temp_entry;
        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

        phb_approve_continue(NULL, control_block);
        return KAL_TRUE;
    }

    return KAL_FALSE;
}   /* end of phb_approve_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_rest_for_PHB_not_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4cphb_approve_req      [?]         
 *  ilm_ptr(?)              [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_approve_rest_for_PHB_not_ready(l4cphb_approve_req_struct *l4cphb_approve_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_dn_enum dn_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /**
    * Since PHB is not ready, dn_type could be un-determined.
    * What PHB can do is directly query SMU.
    */
    if (phb_ptr->state != PHB_STATE_READY)
    {
        dn_type = l4csmu_get_dial_mode();
    }
    else
    {
        dn_type = phb_ptr->dn_type;
    }

   /**
    * Due to control_block is not allocated, PHB cannot try to
    * approve the attempting dialling number.
    */
    if ((dn_type == TYPE_FDN) || (dn_type == TYPE_FDN_BDN))
    {
        phb_approve_confirm(PHB_ERRNO_FAIL, PHB_NONE, l4cphb_approve_req->src_id, NULL, NULL);
        return;
    }
    else if ((dn_type == TYPE_ADN) || (dn_type == TYPE_BDN) || (dn_type == TYPE_ADN_BDN) || (dn_type == TYPE_FDN_BDN) ||
            /**
             * What the hell is this type!?
             * Currently, treat it as FDN disabled.
             * Hence, it is ALWAYS approved, but searching is unnecessary,
             * since neither ADN nor FDN is enabled.
             */
             (dn_type == TYPE_NONE))
    {
        phb_approve_confirm(PHB_ERRNO_SUCCESS, PHB_NONE, l4cphb_approve_req->src_id, NULL, NULL);
        return;
    }

    /* Exception case, dn_type is invalid! Make approval failed! */
    else
    {
        phb_approve_confirm(PHB_ERRNO_FAIL, PHB_NONE, l4cphb_approve_req->src_id, NULL, NULL);
        return;
    }
}   /* end of phb_approve_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_err_handler
 * DESCRIPTION
 *  This is phb_approve_err_handler function of PHB module.
 *  This function should only be called when a request is IN PROECESSING.
 *  That means error handler is called if error occured while processing the
 *  request and after controller received the request and returned.
 *  Ie, if a request is just being handled and it is rejected,
 *  controller/handler should call confirm to reject it directly.
 *  
 *  Hence, unlike handler invokes confirm with EXCEPTION which gives up
 *  just received request; when this function is called, the in-processing
 *  request is given up.
 *  
 *  So, the difference between invoking confirm with EXCEPTION and
 *  error handler is: whether control_block_alloc() is invoked; if true,
 *  call latter, otherwise, call former.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_approve_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_APPROVE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    control_block->actual_count = 0;
    phb_approve_confirm(PHB_ERRNO_FAIL, control_block->type, control_block->src_id, control_block, NULL);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_approve_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_continue
 * DESCRIPTION
 *  This is phb_approve_continue function of PHB module.
 *  
 *  Note:
 *  Only searching PHB_PHBONEBOOK and PHB_BYNUMBER can reach this function.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_approve_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_APPROVE_CONT);

    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    /* Read confirmed. Now verify the entry! */
    else
    {
        /* Note: only approving FDN can reach here. */

        /* Query pattern is stored in local_param_ptr */
        l4_addr_bcd_struct *given = (l4_addr_bcd_struct*) control_block->local_param_ptr;

        /* The just read back candidate is stored in control_block->data */
        phb_entry_struct *candidate_entry = (phb_entry_struct*) control_block->data;
        l4_addr_bcd_struct *candidate_pattern = &candidate_entry->tel_number;

        /* It's approving FDN now */
        if (control_block->proc_stage == APPROVE_FDN_ONE_CHARACTER)
        {
            if ((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x80) ||
                (candidate_pattern->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x80) ||
                (((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) == 0x90) && ((candidate_pattern->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) == 0x90)) ||
                (((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) != 0x90) && ((candidate_pattern->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) != 0x90)))                
            {
                ++control_block->actual_count;

                /* Give control back to controller */
                (*control_block->controller) (NULL, control_block);
                return;
            }
            /* Verification complete, finally control can be returned back to controller */
            if (!phb_se_is_next_also_candidate(
                    (name_num_index_type*) control_block->candidate_name_num_index,
                    control_block->candidate,
                    KAL_FALSE))
            {
                kal_bool is_more_candidates;
                name_num_index_type *name_num_index;
                data_entry_struct *data_entry;
                control_block->candidate_name_num_index = phb_se_search_by_tel_num(control_block->type, given, &control_block->candidate, &is_more_candidates);
                control_block->proc_stage = APPROVE_FDN;

                /* No candidates. Great! */
                if ((control_block->candidate == (kal_uint16) PHB_INVALID_VALUE) ||
                    (control_block->candidate_name_num_index == NULL))
                {
                    control_block->actual_count = 0;

                 /**
                  * Since this entry is not approved by FDN under
                  * FDN enabled condition, it is uncessary to search into PHB_PHONEBOOK
                  * for retrieving the entry that matches this phone number.
                  */
                    phb_approve_confirm(PHB_ERRNO_FAIL, control_block->type, control_block->src_id, control_block, NULL);
                    return;
                }
                /* Read specific record for verification. */
                phb_control_block_set_IO(control_block, control_block->type, (kal_uint16) PHB_INVALID_VALUE, 1);
                /* set storage, record_index, primary_ID, and secondary_ID */
                name_num_index = (name_num_index_type*) control_block->candidate_name_num_index;
                data_entry =
                    &name_num_index->data_entry_table.table[name_num_index->num_index.table[control_block->candidate].position];

                phb_se_set_control_block(
                    control_block,
                    OP_READ,
                    (phb_storage_enum) data_entry->storage,
                    data_entry->record_index);

                /**
                 * Since phb_se_set_control_block() modifies control_block->proc_stage,
                 * it has to be restored.
                 */
                control_block->proc_stage = APPROVE_FDN;

                control_block->data = (kal_uint8*) & control_block->temp_entry;
                phb_issue_IO_read(control_block);
                return;
            }

         /**
          * This iteration is not approved. Still others to verify.
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
                        (phb_storage_enum) data_entry->storage,
                        data_entry->record_index) == KAL_FALSE)
                {
                    phb_approve_err_handler(NULL, control_block);
                    return;
                }

                control_block->proc_stage = APPROVE_FDN_ONE_CHARACTER;
                control_block->data = (kal_uint8*) & control_block->temp_entry;
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                phb_issue_IO_read(control_block);
                return;
            }
        }
        else if (control_block->proc_stage == APPROVE_FDN)
        {
            /* Finally, Approved by FDN!! */
            if (phb_compare_tel_number_prefix(given, candidate_pattern) == KAL_TRUE)
            {
                ++control_block->actual_count;

                /* Give control back to controller */
                (*control_block->controller) (NULL, control_block);
                return;
            }

            /* *Sigh*, Continue verification. */

            /* Verification complete, finally control can be returned back to controller */
            if (!phb_se_is_next_also_candidate(
                    (name_num_index_type*) control_block->candidate_name_num_index,
                    control_block->candidate,
                    KAL_FALSE))
            {
                (*control_block->controller) (NULL, control_block);
            }

         /**
          * This iteration is not approved. Still others to verify.
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
                        (phb_storage_enum) data_entry->storage,
                        data_entry->record_index) == KAL_FALSE)
                {
                    phb_approve_err_handler(NULL, control_block);
                    return;
                }

                control_block->proc_stage = APPROVE_FDN;
                control_block->data = (kal_uint8*) & control_block->temp_entry;
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                phb_issue_IO_read(control_block);
                return;
            }
        }
        /* Abnormal: state error */
        else
        {
            phb_approve_err_handler(NULL, control_block);
            return;
        }
    }
}   /* end of phb_approve_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_approve_confirm
 * DESCRIPTION
 *  This is phb_approve_confirm function of PHB module.
 * PARAMETERS
 *  result                          [IN]        
 *  type                            [IN]        
 *  src_id                          [IN]        
 *  control_block                   [?]         
 *  phb_entry_weird_approved        [?]         
 *  ilm_ptr(?)                      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_approve_confirm(
                phb_errno_enum result,
                phb_type_enum type,
                kal_uint8 src_id,
                control_block_type *control_block,
                phb_entry_struct *phb_entry_weird_approved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;
    peer_buff_struct *peer_buf_ptr = NULL;

    l4cphb_approve_cnf_struct *l4cphb_approve_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_APPROVE_CNF, result, type, src_id);

    l4cphb_approve_cnf = (l4cphb_approve_cnf_struct*) construct_local_para(sizeof(l4cphb_approve_cnf_struct), TD_CTRL);
    l4cphb_approve_cnf->type = type;
    l4cphb_approve_cnf->src_id = src_id;

    local_param_ptr = (local_para_struct*) l4cphb_approve_cnf;

    /* If result is PHB_ERRNO_BUSY, reject newly received request */
    l4cphb_approve_cnf->result = result;

    /* Confirm to in-processing operation */
    if (result != PHB_ERRNO_BUSY)
    {
        if (control_block != NULL)
        {
            /* Field 'cause' is meaningful when I/O occured by using control blocks */
            l4cphb_approve_cnf->cause = control_block->cause;

            /* First we release local parameter. */
            if (control_block->local_param_ptr != NULL)
            {
                free_ctrl_buffer(control_block->local_param_ptr);
            }

            /* A hit is stored in temp_entry, it must be packed into peer buffer */
            if ((result == PHB_ERRNO_SUCCESS) && (control_block->actual_count > 0))
            {
                phb_entry_struct *phb_entry = &control_block->temp_entry;
                l4cphb_phb_entry_array_struct *phb_entry_array;

                phb_entry_array =
                    (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
                phb_entry_array->no_array = control_block->actual_count;
                kal_mem_cpy(&phb_entry_array->array[0], (void const*)phb_entry, sizeof(phb_entry_struct));
                control_block->peer_buf_ptr = NULL;
            }

            phb_free_control_block(control_block);
        }

        /* Only approval when PHB is not ready should reach here. */
        else if (phb_entry_weird_approved != NULL)
        {
            /* A hit is passed from phb_entry */
            if (result == PHB_ERRNO_SUCCESS)
            {
                l4cphb_phb_entry_array_struct *phb_entry_array;

                phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, 1);
                phb_entry_array->no_array = 1;
                kal_mem_cpy(
                    &phb_entry_array->array[0],
                    (void const*)phb_entry_weird_approved,
                    sizeof(phb_entry_struct));
            }
        }
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_APPROVE_CNF, local_param_ptr, peer_buf_ptr);
}   /* end of phb_approve_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_compare_tel_number_prefix
 * DESCRIPTION
 *  This is phb_compare_tel_number_prefix function of PHB module.
 *  Try prefix matching `given' to `candidate'.
 *  
 *  Algorightm:
 * PARAMETERS
 *  given           [?]         
 *  candidate       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_compare_tel_number_prefix(l4_addr_bcd_struct *given, l4_addr_bcd_struct *candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Recover the wrong length from SIM */
    //if (candidate->addr_bcd[candidate->addr_length - 1] == 0xff)
    //    candidate->addr_length--;
    candidate->addr_length = (bcd_exact_len((kal_uint8*)candidate->addr_bcd, candidate->addr_length)+1)/2;
   /**
    * Since attempting phone number is only allowed to be extended from
    * an FDN entry, if attempting phone number is shorter than candidate,
    * then it must not be an extension of candidate.
    */
    if (given->addr_length < candidate->addr_length)
    {
        return KAL_FALSE;
    }

    /* First, compare TON/NPI. If requested TON is 000, 010(national call) is allowed */
    if (!((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x80) ||
        (candidate->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x80) ||
        (((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) == 0x90) && ((candidate->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) == 0x90)) ||
        (((given->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) != 0x90) && ((candidate->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] & 0x90) != 0x90)))) 
    {
        return KAL_FALSE;
    }

    len = bcd_len(
            &candidate->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
            (kal_uint16) (candidate->addr_length - L4_ADDR_BCD_TON_NPI_SIZE));

    /* Next, compare digits */
    /* Currently, PERFECT MATCHING is implemented, no wildcard supported */
    if (compare_n_bcd(
            &candidate->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
            &given->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
            len) == 0)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}   /* end of phb_compare_tel_number_prefix */


/*****************************************************************************
 * FUNCTION
 *  phb_is_number_ecc
 * DESCRIPTION
 *  Check if the number is ECC
 *  
 *  Algorightm:
 * PARAMETERS
 *  tel_number
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool phb_is_number_ecc(l4_addr_bcd_struct *tel_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    phb_entry_struct *phb_entry = get_ctrl_buffer(sizeof(phb_entry_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = phb_approve_ecc(NULL, tel_number, phb_entry);
    free_ctrl_buffer(phb_entry);
    
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  phb_is_sat_number_ecc
 * DESCRIPTION
 *  Check if the number is ECC
 *  
 *  Algorightm:
 * PARAMETERS
 *  tel_number
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool phb_is_sat_number_ecc(l4_addr_bcd_struct *tel_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    phb_entry_struct *phb_entry = get_ctrl_buffer(sizeof(phb_entry_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = phb_approve_sat_ecc(NULL, tel_number, phb_entry);    
    free_ctrl_buffer(phb_entry);

    return result;
}