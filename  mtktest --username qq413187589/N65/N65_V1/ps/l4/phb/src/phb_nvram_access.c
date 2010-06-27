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
 * phb_nvram_access.c
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
// #include "nvram_data_items.h"
#include "nvram_user_defs.h"
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
#include "l4_defs.h"
#include "nvram.h"
/* NVRAM_EF_PHB_LID structure */
#include "phb_nvram_data.h"

#include "phb_common.h"
#include "phb_ilm.h"
#include "phb_utils.h"
#include "phb_nvram_access.h"

/* ErrorStruct */
#include "asn-error.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_NVRAM_ACCESS_C_

static void phb_nvram_read_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_nvram_read_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 access_id,
                kal_uint16 rec_amount);

static void phb_nvram_write_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_nvram_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 access_id,
                peer_buff_struct *peer_buffer);

static void phb_nvram_delete_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static kal_bool phb_nvram_prepare_data_to_write(control_block_type *control_block, kal_uint8 *buffer);


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  access_id           [IN]        
 *  rec_amount          [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_read_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 access_id,
                kal_uint16 rec_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *nvram_read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_READ_RECORD);

    nvram_read_req = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
    nvram_read_req->file_idx = (kal_uint8) file_idx;
    nvram_read_req->para = record_index;
    nvram_read_req->access_id = access_id;
    nvram_read_req->rec_amount = rec_amount;

    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, nvram_read_req, NULL);
}   /* end of phb_sim_read_record */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_read
 * DESCRIPTION
 *  This is phb_nvram_read function of PHB module.
 *  
 *  There are 3 encoding mechanisms defined in 11.11.
 *  Assume number of UCS2 characters to be stored is x,
 *  byte size needed in storage for each encoding mechanism is
 *  calculated as follows:
 *  
 *  1> coding 80: 1(tag/80) + 2*x
 *  2> coding 81: 1(tag/81) + 1(length) + 1(character collection) + x
 *  3> coding 82: 1(tag/82) + 1(length) + 2(character collection) + x
 *  
 *  To support 30 characters, space needed in NVRAM is at least 61
 *  bytes for ALPHA_ID field.
 *  To support 40 digits, speces needed in NVRAM is at least 20 bytes
 *  for DIALLING_NUMBER/SSC_STRING field.
 *  Hence, NVRAM_EF_PHB_SIZE should be (61 + 1 + 1 + 20 + 1 + 1)
 *  = 85 bytes. To be even-byte aligned, 86 bytes is needed.
 *  Thus, ALPHA_ID is allocated 62 bytes.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_nvram_read(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_READ);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        kal_uint16 rec_amount = 1;

        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_nvram_read_cnf;
        if (control_block->primary_ID == NVRAM_EF_PHB_LID && phb_ptr->state != PHB_STATE_READY)
        {
            kal_uint16 leftToRead = phb_data_desc_get_record_num(DATA_DESC_PHB) - control_block->actual_count;

            rec_amount = 2000 / control_block->length;
            if (rec_amount > leftToRead)
            {
                rec_amount = leftToRead;
            }
        }
        phb_nvram_read_record(control_block->primary_ID, control_block->record_index, control_block->ID, rec_amount);
        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_nvram_read */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_read_cnf
 * DESCRIPTION
 *  This is phb_nvram_read_cnf function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_read_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *nvram_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_READ_CNF);

    ASSERT(control_block != NULL);

    nvram_read_cnf = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;

    if ((nvram_read_cnf->result == NVRAM_IO_ERRNO_OK) || (nvram_read_cnf->result == NVRAM_IO_ERRNO_INIT))
    {
        if (control_block->IO_stage == IO_WAIT && control_block->primary_ID == NVRAM_EF_PHB_LID &&
            phb_ptr->state != PHB_STATE_READY)
        {
            /* success */
            control_block->IO_stage = IO_NONE;
            control_block->IO_cnf_receive = NULL;
            control_block->peer_buf_ptr = (kal_uint8*) ilm_ptr->peer_buff_ptr;
            control_block->total_piggyback = 0;
            /* read complete, back to phb_build_index function */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
        else if (control_block->IO_stage == IO_WAIT)
        {
            kal_uint8 alpha_id_length = phb_data_desc_get_record_size(DATA_DESC_PHB) - NVRAM_PHB_LENGTH_AFTER_ALPHA_ID;

            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            phb_nvram_ef_struct phb_nvram_ef;
            phb_entry_struct *phb_entry;

            /* success */
            control_block->IO_stage = IO_NONE;
            control_block->IO_cnf_receive = NULL;

            /* Now unpack the data read from peer buffer */

            /* Get the Pointer to the Message from the Peer Buffer Ptr */
            pdu_ptr = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);

            phb_entry = (phb_entry_struct*) control_block->data;

            phb_nvram_ef.alpha_id = (kal_uint8*) pdu_ptr;
            phb_nvram_ef.mandatory = (phb_nvram_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

            /* Clean area for storing data read from storage. */
            kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

            phb_entry->index = control_block->index;
            phb_entry->record_index = control_block->record_index;
            phb_entry->storage = PHB_NVRAM;
            /* amanda add */
            phb_entry->type = PHB_PHONEBOOK;

            if (!is_empty(pdu_ptr, pdu_length)  /* && 
                                                   (phb_nvram_ef.mandatory->len <= NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN) */ )
            {
                istring_type istring;

                /* Set up phb_entry->alpha_id */
                istring.length = phb_entry->alpha_id.name_length = L4_MAX_NAME;
                istring.data = (kal_uint8*) phb_entry->alpha_id.name;
                phb_entry->alpha_id.name_length = istring_decode_from_sim(alpha_id_length, phb_nvram_ef.alpha_id, &istring);
                if (phb_entry->alpha_id.name_length == 0)
                {
                    istring.charset = PHB_ASCII;
                }

            /** 
             * If returned decoded length of alpha id is 0, 
             * it is either stored alpha id is empty, 
             * or alpha id encoding is erroneous 
             */

                phb_entry->alpha_id.name_dcs = istring.charset;
                if (phb_entry->alpha_id.name_length >= L4_MAX_NAME)
                {
                    if (phb_entry->alpha_id.name_dcs == PHB_ASCII)
                    {
                        phb_entry->alpha_id.name_length--;
                        phb_entry->alpha_id.name[L4_MAX_NAME - 1] = 0;
                    }
                    else if (phb_entry->alpha_id.name_dcs == PHB_UCS2)
                    {
                        phb_entry->alpha_id.name_length -= 2;
                        phb_entry->alpha_id.name[L4_MAX_NAME - 1] = 0;
                        phb_entry->alpha_id.name[L4_MAX_NAME - 2] = 0;
                    }
                }

            /**
             * Truncate read back DIALLING_NUMBER, if necessary, 
             * before it is stored into phb_entry.
             */
                if (phb_nvram_ef.mandatory->len > NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN)
                {
                    phb_nvram_ef.mandatory->len = NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN;
                }

                if (phb_nvram_ef.mandatory->len > 0 && phb_nvram_ef.mandatory->len != 0xff)
                {
                    /* Set up phb_entry->tel_number */
                    /* LENGTH */
                    phb_entry->tel_number.addr_length = phb_nvram_ef.mandatory->len;
                    /* TON/NPI */
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_nvram_ef.mandatory->ton_npi;
                    /* DIALLING_NUMBER/SSC_STRING */
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_nvram_ef.mandatory->tel_number,
                        /* TON_NPI_SIZE + */ phb_nvram_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                    phb_entry->tel_number.addr_bcd[phb_nvram_ef.mandatory->len] = 0xff;
                }

                else
                {
                    kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                }
                /* Set up phb_entry->cap_cnf_id */
                phb_entry->cap_cnf_id = phb_nvram_ef.mandatory->cap_cnf_id;
            }

            /* Incorrect LENGTH field */
            else
            {
                kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                phb_entry->tel_number.addr_length = 0;
                control_block->data = NULL;
            }

            /* read complete */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_NVRAM_IO_STATE_READ);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        /* Accessing NVRAM is not required to return error cause */
        control_block->IO_stage = IO_NONE;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_nvram_read_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_read_compare_digit_cnf
 * DESCRIPTION
 *  This is phb_nvram_read_compare_digit_cnf function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_read_compare_digit_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *nvram_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_FILE_INFO_CNF);

    ASSERT(control_block != NULL);

    nvram_read_cnf = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;

    if (control_block->IO_stage == IO_WAIT &&
        (nvram_read_cnf->result == NVRAM_IO_ERRNO_OK || nvram_read_cnf->result == NVRAM_IO_ERRNO_INIT))
    {
        kal_uint16 length;
        kal_uint8 *pdu_data = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);

        phb_ptr->compare_digit = *pdu_data;
        if (control_block->IO_stage == IO_WAIT)
        {
            /* success */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
    }
    /* error occured, call error handler */
    phb_ptr->compare_digit = 7;
    /* control_block->cause = sim_file_info_cnf->result; */
    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
    return;
}   /* end of phb_nvram_read_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_read_compare_digit
 * DESCRIPTION
 *  This is phb_nvram_read_compare_digit function of PHB module.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_nvram_read_compare_digit(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_bool result = KAL_FALSE; */

    /* kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_READ); */
    nvram_read_req_struct *nvram_read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(control_block != NULL);

    /* if (control_block->IO_stage == IO_NONE) */

    control_block->IO_stage = IO_WAIT;
    control_block->IO_cnf_receive = phb_nvram_read_compare_digit_cnf;
    nvram_read_req = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
    nvram_read_req->file_idx = NVRAM_EF_PHB_COMPARE_DIGIT_LID;
    nvram_read_req->para = 1;
    nvram_read_req->access_id = control_block->ID;
    nvram_read_req->rec_amount = 1;
    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, nvram_read_req, NULL);
    /* result = KAL_TRUE; */
    /* Abnormal, return false */
    /* else */
}   /* end of phb_nvram_read */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_write_record
 * DESCRIPTION
 *  This function issues NVRAM_WRITE_REQ to nvram.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  access_id           [IN]        
 *  peer_buf_ptr        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 access_id,
                peer_buff_struct *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_req_struct *nvram_write_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_WRITE_RECORD);

    nvram_write_req = (nvram_write_req_struct*) construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
    nvram_write_req->file_idx = (kal_uint8) file_idx;
    nvram_write_req->para = record_index;
    nvram_write_req->access_id = access_id;

    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, nvram_write_req, peer_buf_ptr);
}   /* end of phb_nvram_write_record */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_write
 * DESCRIPTION
 *  This function issues NVRAM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_nvram_write(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_WRITE);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        data_desc_enum type;
        phb_entry_struct *phb_entry;

        /* Nothing to write? error! */
        if ((phb_entry = (phb_entry_struct*) control_block->data) == NULL)
        {
            result = KAL_FALSE;
        }

        else if ((control_block->primary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
                 ((type = phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage)) !=
                  (data_desc_enum) PHB_INVALID_VALUE))
        {
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            control_block->IO_stage = IO_WAIT;
            control_block->IO_cnf_receive = phb_nvram_write_cnf;

         /**
          * Find the Number of bits that has to be used by the packed 
          * structure. Since the lenght is in number of bits, we have 
          * to convert that into number of octets 
          */
            pdu_length = control_block->length;

            /* Construct peer buffer */
            peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
            pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

         /**
          * Truncate bytes exceeds maximum capacity!!
          *
          * addr_length needs not to be restored, since it just reflects 
          * what is written actually. 
          */
            if (phb_entry->tel_number.addr_length > NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN)
            {
                phb_entry->tel_number.addr_length = NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN;
            }

            control_block->seg_total = 0;

            if (phb_nvram_prepare_data_to_write(control_block, pdu_ptr) == KAL_FALSE)
            {
                return KAL_FALSE;
            }

            /* Preparation of data content complete! */

            phb_nvram_write_record(
                control_block->primary_ID,
                control_block->record_index,
                control_block->ID,
                peer_buf_ptr);

            result = KAL_TRUE;
        }
        /* Error */
        else
        {
            result = KAL_FALSE;
        }

    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_nvram_write */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_write_cnf
 * DESCRIPTION
 *  This function issues NVRAM_READ_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_write_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_WRITE_CNF);

    ASSERT(control_block != NULL);

    nvram_write_cnf = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;

    if ((nvram_write_cnf->result == NVRAM_IO_ERRNO_OK) || (nvram_write_cnf->result == NVRAM_IO_ERRNO_INIT))
    {
        if (control_block->IO_stage == IO_WAIT)
        {
            /* Write complete */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_NVRAM_IO_STATE_WRITE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        /* Accessing NVRAM is not required to return error cause */

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_nvram_write_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_delete
 * DESCRIPTION
 *  This function issues NVRAM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_nvram_delete(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_DELETE);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        data_desc_enum type;
        phb_entry_struct *phb_entry;

        phb_entry = (phb_entry_struct*) control_block->data;

        if ((control_block->primary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
            ((type = phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage)) != (data_desc_enum) PHB_INVALID_VALUE))
        {
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            control_block->IO_stage = IO_WAIT;
            control_block->IO_cnf_receive = phb_nvram_delete_cnf;

         /**
          * Find the Number of bits that has to be used by the packed 
          * structure. Since the lenght is in number of bits, we have 
          * to convert that into number of octets 
          */
            pdu_length = control_block->length;

            /* Construct peer buffer */
            peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
            pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

            kal_mem_set(pdu_ptr, (kal_uint8) PHB_INVALID_VALUE, pdu_length);

            phb_nvram_write_record(
                control_block->primary_ID,
                control_block->record_index,
                control_block->ID,
                peer_buf_ptr);
            result = KAL_TRUE;
        }
        /* Error */
        else
        {
            result = KAL_FALSE;
        }

    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_nvram_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_delete_cnf
 * DESCRIPTION
 *  This function issues NVRAM_READ_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_nvram_delete_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_NVRAM_DELETE_CNF);

    ASSERT(control_block != NULL);

    nvram_write_cnf = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;

    if ((nvram_write_cnf->result == NVRAM_IO_ERRNO_OK) || (nvram_write_cnf->result == NVRAM_IO_ERRNO_INIT))
    {
        if (control_block->IO_stage == IO_WAIT)
        {
            /* Delete complete */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_NVRAM_IO_STATE_DELETE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        /* Accessing NVRAM is not required to return error cause */

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_nvram_delete_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_nvram_prepare_data_to_write
 * DESCRIPTION
 *  Prepare data stored in given phb_entry_struct to approprieate structure
 *  for raw data to write, depending on it is written to SIM or NVRAM.
 *  
 *  Prerequisite:
 *  1. phb_entry->tel_number.addr_length must be set.
 *  2. control_block->seg_total must be set.
 *  3. control_block->length must be set.
 * PARAMETERS
 *  control_block       [?]     
 *  buffer              [?]     
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_bool phb_nvram_prepare_data_to_write(control_block_type *control_block, kal_uint8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_nvram_ef_mandatory_struct *phb_nvram_ef_mandatory = NULL;
    phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

    kal_uint8 alpha_id_length = 0;
    kal_uint8 tel_number_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PREPARE_DATA_TO_WRITE);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    alpha_id_length = control_block->length - NVRAM_PHB_LENGTH_AFTER_ALPHA_ID;
    kal_mem_set(buffer, 0xFF, control_block->length);

    /* Now prepare the data content */
    if (phb_entry->alpha_id.name_length > 0)
    {
        istring_type istr;

        istr.length = phb_entry->alpha_id.name_length;
        istr.charset = phb_entry->alpha_id.name_dcs;
        istr.data = &phb_entry->alpha_id.name[0];

        /* Error occured when encoding alph-id field */
        if (istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer) == 0)
        {
            return KAL_FALSE;
        }
    }

    phb_nvram_ef_mandatory = (phb_nvram_ef_mandatory_struct*) & buffer[alpha_id_length];

   /**
    * Truncate requested DIALLING_NUMBER/SSC_STRING, if necessary,
    * before storing it into NVRAM.
    */
    if (phb_entry->tel_number.addr_length == 1) /* Empty number */
    {
        /* "+" character */
        if (phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
        {
            phb_nvram_ef_mandatory->len = 1;
            phb_nvram_ef_mandatory->ton_npi = 0x91;
        }
        else
        {
            phb_nvram_ef_mandatory->len = 0xff;
            phb_nvram_ef_mandatory->ton_npi = 0xff;
        }
        kal_mem_set((kal_uint8*) phb_nvram_ef_mandatory->tel_number, 0xff, NVRAM_EF_TEL_NUMBER_SIZE);
    }
    else
    {
        if (phb_entry->tel_number.addr_length > NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN)
        {
            phb_entry->tel_number.addr_length = NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN;
        }

        /* LENGTH */
        phb_nvram_ef_mandatory->len = phb_entry->tel_number.addr_length;
        if (phb_nvram_ef_mandatory->len > 0)
        {
            tel_number_size = phb_nvram_ef_mandatory->len - 1;  /* amanda change */
        }
        /* TON/NPI */
        phb_nvram_ef_mandatory->ton_npi = phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
        /* DIALLING_NUMBER/SSC_STRING */
        kal_mem_cpy(
            &phb_nvram_ef_mandatory->tel_number[0],
            (void const*)&phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
            tel_number_size);
    }
    phb_nvram_ef_mandatory->cap_cnf_id = phb_entry->cap_cnf_id;

    return KAL_TRUE;
}   /* end of phb_is_type_valid */


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_from_nvram(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (nvram_read_req_struct*) construct_local_para((kal_uint16) sizeof(nvram_read_req_struct), TD_CTRL);

    param_ptr->file_idx = NVRAM_EF_PHB_LN_ENTRY_LID;
    param_ptr->para = control_block->secondary_ID;
    param_ptr->access_id = control_block->ID;

    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdu_data            [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_to_nvram(nvram_ef_phb_ln_struct *pdu_data, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;
    nvram_write_req_struct *param_ptr;
    peer_buff_struct *peer_buff_ptr = NULL;
    nvram_ef_phb_ln_struct *pdu_stream_ptr, *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;

    param_ptr = (nvram_write_req_struct*) construct_local_para((kal_uint16) sizeof(nvram_write_req_struct), TD_CTRL);

    param_ptr->file_idx = NVRAM_EF_PHB_LN_ENTRY_LID;
    param_ptr->para = control_block->secondary_ID;
    param_ptr->access_id = control_block->ID;

    peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(
                                            sizeof(nvram_ef_phb_ln_struct),
                                            0,  /* no header */
                                            0,  /* no tail */
                                            TD_DL);

    pdu_stream_ptr = (nvram_ef_phb_ln_struct*) get_pdu_ptr(peer_buff_ptr, &len);

    if (pdu_data != NULL)
    {
        kal_mem_cpy(pdu_stream_ptr, pdu_data, sizeof(nvram_ef_phb_ln_struct));
    }
    else
    {
        record = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &len);
        kal_mem_cpy(pdu_stream_ptr, record, sizeof(nvram_ef_phb_ln_struct));
    }

    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, param_ptr, peer_buff_ptr);
}

#ifdef __PHB_RECORD_LN_TYPE_SEQ__


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_type_seq_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_type_seq_to_nvram(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* nvram_ef_phb_ln_type_seq_struct *pdu_data = NULL; */
    kal_uint16 len;
    kal_uint16 i;
    nvram_write_req_struct *param_ptr;
    peer_buff_struct *peer_buff_ptr = NULL;
    nvram_ef_phb_ln_type_seq_struct *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;

    param_ptr = (nvram_write_req_struct*) construct_local_para((kal_uint16) sizeof(nvram_write_req_struct), TD_CTRL);

    param_ptr->file_idx = NVRAM_EF_PHB_LN_TYPE_SEQ_LID;
#ifdef __GEMINI__
    if (phb_current_mod == MOD_PHB_2)
    {
        param_ptr->para = 2;
    }
    else
#endif /* __GEMINI__ */
    {
        param_ptr->para = 1;
    }
    param_ptr->access_id = control_block->ID;

    peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(
                                            sizeof(nvram_ef_phb_ln_type_seq_struct),
                                            0,  /* no header */
                                            0,  /* no tail */
                                            TD_DL);

    /* control_block->data = (kal_uint8 *)peer_buff_ptr; */

    //record = (nvram_ef_phb_ln_type_seq_struct *)
    //   get_pdu_ptr ((peer_buff_struct *)control_block->data, &len);
    record = (nvram_ef_phb_ln_type_seq_struct*) get_pdu_ptr(peer_buff_ptr, &len);

    for (i = 0; i < PHB_TOTAL_LN_ENTRIES; i++)
    {
        record->type_seq[i] = phb_ln_type_seq[i];
    }
    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, param_ptr, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_type_seq_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_type_seq_from_nvram(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (nvram_read_req_struct*) construct_local_para((kal_uint16) sizeof(nvram_read_req_struct), TD_CTRL);

    param_ptr->file_idx = NVRAM_EF_PHB_LN_TYPE_SEQ_LID;
#ifdef __GEMINI__
    if (phb_current_mod == MOD_PHB_2)
    {
        param_ptr->para = 2;
    }
    else
#endif /* __GEMINI__ */
    {
        param_ptr->para = 1;
    }  
    param_ptr->access_id = control_block->ID;

    phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, param_ptr, NULL);
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

