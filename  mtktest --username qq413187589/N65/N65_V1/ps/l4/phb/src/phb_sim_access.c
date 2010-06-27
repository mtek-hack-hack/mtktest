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
 * phb_sim_access.c
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

#include "l4_defs.h"
/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"
#include "phb_handler_startup.h"

#include "phb_context.h"

#include "phb_common.h"
#include "phb_ilm.h"
#include "phb_utils.h"
#include "phb_se.h"

#include "phb_sim_access.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_SIM_ACCESS_C_

/* SIM constants */
#define SIM_WRITE_OFFSET   5

/* Offset begun after alpha id, these are for write operation */
#define BCD_LEN_OFFSET     0
#define TON_NPI_OFFSET     1
#define TEL_NUMBER_OFFSET  2
#define CAP_CNF_OFFSET     12
#define SIM_EXT_ID_OFFSET  13

#define EF_EXT_TYPE_ADDITIONAL_DATA    0x02
#define EF_EXT_TYPE_SUBADDRESS         0x01

/* EFext types and constants */
typedef struct
{
    kal_uint8 record_type;
    kal_uint8 ext_data_length;
    kal_uint8 ext_data[EF_TEL_NUMBER_SIZE];
    kal_uint8 identifier;
} ef_ext_type;


static void phb_sim_file_info_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);

static void phb_sim_read_record(kal_uint16 file_idx, kal_uint16 record_index, kal_uint16 length, kal_uint8 access_id);
static kal_uint8 phb_sim_reassemble_tel_num(ef_ext_type *data_ptr, control_block_type *control_block);
static void phb_sim_read_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);

static void phb_sim_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 *data,
                kal_uint16 length,
                kal_uint8 access_id);
static kal_bool phb_sim_write_segmented_record(
                    control_block_type *control_block,
                    data_desc_enum type,
                    kal_uint8 chained_id);

static void phb_sim_write_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_sim_delete_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static kal_bool phb_sim_prepare_data_to_write(
                    control_block_type *control_block,
                    kal_uint8 *buffer,
                    kal_uint8 chained_id);
static kal_uint16 phb_sync_translate_ln_to_sim(
                    kal_uint8 *data,
                    nvram_ef_phb_ln_struct *record,
                    nvram_ef_phb_ln_struct *record1,
                    control_block_type *control_block);


/*****************************************************************************
 * FUNCTION
 *  phb_sim_file_info
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  control_block       [?]         
 *  info_type           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_file_info(control_block_type *control_block, sim_info_type_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_FILE_INFO);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        sim_file_info_req_struct *sim_file_info_req;

        sim_file_info_req = (sim_file_info_req_struct*) construct_local_para(
                                                            sizeof(sim_file_info_req_struct),
                                                            TD_CTRL);
        sim_file_info_req->file_idx = control_block->primary_ID;
    #ifdef __USIM_SUPPORT__
        kal_mem_cpy(sim_file_info_req->path, control_block->path, 6);
    #endif 
        sim_file_info_req->info_type = info_type;
        sim_file_info_req->access_id = control_block->ID;

        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_sim_file_info_cnf;
        phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, sim_file_info_req, NULL);

        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of module main function */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_file_info_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_file_info_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_FILE_INFO_CNF);

    ASSERT(control_block != NULL);

    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_file_info_cnf->result == SIM_CMD_SUCCESS)
    {
        /* amanda add */
        if (sim_file_info_cnf->num_of_rec > 0)
        {
            if (sim_file_info_cnf->file_idx == FILE_FDN_IDX)
            {
                phb_ptr->fdn_alpha_length = (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 14;
            }
            else if (sim_file_info_cnf->file_idx == FILE_BDN_IDX)
            {
                phb_ptr->bdn_alpha_length = (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 15;
            }
            else if (sim_file_info_cnf->file_idx == FILE_MSISDN_IDX)
            {
                phb_ptr->msisdn_alpha_length = (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 14;
            }
        }

        if (control_block->IO_stage == IO_WAIT)
        {
            /* success */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_FILE_INFO);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_file_info_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_sim_file_info_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_read_record(kal_uint16 file_idx, kal_uint16 record_index, kal_uint16 length, kal_uint8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_req_struct *sim_read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ_RECORD);

    sim_read_req = (sim_read_req_struct*) construct_local_para(sizeof(sim_read_req_struct), TD_CTRL);
#ifdef __USIM_SUPPORT__
    if (is_usim_type())
    {
        data_desc_enum type = phb_data_desc_get_desc_by_ID(file_idx, PHB_SIM);

        if (type != PHB_INVALID_VALUE)
        {
            kal_mem_cpy(sim_read_req->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            sim_read_req->path[4] = phb_ptr->path[type][0];
            sim_read_req->path[5] = phb_ptr->path[type][1];
        }
    }
#endif /* __USIM_SUPPORT__ */ 

    sim_read_req->file_idx = file_idx;
    sim_read_req->para = (kal_uint8) record_index;
    sim_read_req->length = (kal_uint8) length;
    sim_read_req->access_id = (kal_uint8) access_id;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_READ_REQ, sim_read_req, NULL);
}   /* end of phb_sim_read_record */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  Read SIM from control_block specified primary_ID, record_index, and length
 *  
 *  Prerequisite:
 *  pimary_ID, secondary_ID, record_index and length.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_read(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_sim_read_cnf;
        phb_sim_read_record(
            control_block->primary_ID,
            control_block->record_index,
            control_block->length,
            control_block->ID);
        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_sim_read */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_reassemble_tel_num
 * DESCRIPTION
 *  This function reassembles data read from SIM.
 * PARAMETERS
 *  data_ptr            [IN]        Must be a EFext structure in SIM!!
 *  control_block       [?]         
 * RETURNS
 *  identifier of chained extension record.
 *****************************************************************************/
static kal_uint8 phb_sim_reassemble_tel_num(ef_ext_type *data_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_entry_struct *phb_entry;

    kal_uint8 len;
    kal_uint8 sim_ext_record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_REASSEMBLE_TEL_NUM);

    ASSERT(control_block != NULL);

    phb_entry = (phb_entry_struct*) control_block->data;
    phb_entry->storage = PHB_SIM;

    if ((phb_entry->tel_number.addr_length + data_ptr->ext_data_length) > L4_MAX_ADDR_BCD)
    {
        len = L4_MAX_ADDR_BCD - phb_entry->tel_number.addr_length;
        sim_ext_record_index = (kal_uint8) PHB_INVALID_VALUE;   /* truncate!! */
    }
    else
    {
        len = data_ptr->ext_data_length;
        sim_ext_record_index = data_ptr->identifier;
    }
    kal_mem_cpy(
        &phb_entry->tel_number.addr_bcd[phb_entry->tel_number.addr_length],
        (void const*)data_ptr->ext_data,
        len);
    phb_entry->tel_number.addr_length += len;

    return sim_ext_record_index;
}   /* end of phb_sim_reassemble */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_read_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_cnf_struct *sim_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ_CNF);

    ASSERT(control_block != NULL);

    sim_read_cnf = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_read_cnf->result == SIM_CMD_SUCCESS)
    {
        /* success */
        if (control_block->IO_stage == IO_WAIT)
        {
        #ifdef __USIM_SUPPORT__
            /* Reading ECC or PBR. Return to return_location for reading pbr */
            if (control_block->primary_ID == FILE_ECC_IDX ||
                control_block->primary_ID == FILE_U_ECC_IDX || control_block->primary_ID == FILE_G_PBR_IDX)
        #else /* __USIM_SUPPORT__ */ 
            /* Reading ECC. Return to return_location for reading ecc */
            if (control_block->primary_ID == FILE_ECC_IDX)
        #endif /* __USIM_SUPPORT__ */ 
            {
                control_block->data = (kal_uint8*) sim_read_cnf->data;
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
            else if ((control_block->primary_ID == FILE_EXT1_IDX) ||
        #ifdef __PHB_USIM_SUPPORT
                     (control_block->primary_ID == FILE_G_EXT1_IDX) ||
        #endif 
                     (control_block->primary_ID == FILE_EXT2_IDX) ||
                     (control_block->primary_ID == FILE_EXT3_IDX) || (control_block->primary_ID == FILE_EXT4_IDX))
            {
                kal_uint16 len;
                ef_ext_type *ef_ext;

                ef_ext = (ef_ext_type*) sim_read_cnf->data;
                if ((len = sim_read_cnf->length) > sizeof(ef_ext))
                {
                    len = sizeof(ef_ext_type);
                }

                if (!is_empty((kal_uint8*) ef_ext, len))
                {
                    control_block->data = (kal_uint8*) ef_ext;
                }
                else
                {
                    control_block->data = NULL;
                }

                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            }
        #ifdef __PHB_USIM_SUPPORT__
            else if (control_block->primary_ID == FILE_G_ANR_IDX)
            {
                kal_uint8 anr_alpha_id_length = 1;
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;

                phb_ef_struct phb_ef;
                phb_entry_struct *phb_entry;

                pdu_ptr = sim_read_cnf->data;
                pdu_length = sim_read_cnf->length;

                phb_entry = (phb_entry_struct*) control_block->data;

                /* phb_ef.alpha_id = (kal_uint8*)pdu_ptr; */
                phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + anr_alpha_id_length);

                /* Clean area for storing data read from stroage. */
                kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

                phb_entry->index = control_block->index;
                phb_entry->record_index = control_block->record_index;
                phb_entry->storage = PHB_SIM;

                phb_entry->type = PHB_ANR;

                if (!is_empty(pdu_ptr, pdu_length))
                {
                    kal_uint8 sim_ext_record_index;

                    /* Set up phb_entry->tel_number */
                    if (phb_ef.mandatory->len > 0 && phb_ef.mandatory->len != 0xff && phb_ef.mandatory->len <= (EF_TEL_NUMBER_SIZE + 1) && !(phb_ef.mandatory->len == 1 && phb_ef.mandatory->ton_npi != 0x91))  /* only accept + if length 1 */
                    {
                        phb_entry->tel_number.addr_length = phb_ef.mandatory->len;
                        phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_ef.mandatory->ton_npi;
                        kal_mem_cpy(
                            &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (void const*)&phb_ef.mandatory->tel_number,
                            /* TON_NPI_SIZE + */ phb_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                        phb_entry->tel_number.addr_bcd[phb_ef.mandatory->len] = 0xff;
                    }
                    else
                    {
                        kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
                        phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                    }

                    /* Empty Record!! - If Number field is empty, regard it as an empty record!! */
                    if (phb_entry->tel_number.addr_length == 0)
                    {
                        kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                        control_block->data = NULL;

                        phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                        return;
                    }

                    /* Need reassembly? */
                    sim_ext_record_index = phb_ef.mandatory->ext_id;
                    control_block->seg_record_index = (kal_uint8) PHB_INVALID_VALUE;
                    if ((control_block->secondary_ID != PHB_NULL_VALUE) &&
                        (sim_ext_record_index != (kal_uint8) PHB_INVALID_VALUE) &&
                        (sim_ext_record_index > 0) &&
                        (sim_ext_record_index <= phb_data_desc_get_record_num(phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage))) &&
                        (phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                        /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                        (phb_ef.mandatory->len == PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN))
                    {

                        if ((phb_ptr->state != PHB_STATE_READY) &&
                            (control_block->proc_stage == startup_build_anr_index))
                        {
                            control_block->seg_record_index = sim_ext_record_index;
                            phb_data_desc_mark_free(
                                phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                                sim_ext_record_index,
                                KAL_FALSE);
                        }

                        control_block->IO_stage = IO_REASSEMBLY;
                        control_block->IO_cnf_receive = phb_sim_read_cnf;

                  /**
                   * control_block->record_index MUST NOT be modified;
                   * that is counter of current read primary_ID!!!
                   */

                        phb_sim_read_record(
                            control_block->secondary_ID,
                            sim_ext_record_index,
                            phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID (control_block->secondary_ID, control_block->storage)),
                            control_block->ID);
                        return;
                    }
                }

                /* Empty record!! */
                else
                {
                    kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                    phb_entry->tel_number.addr_length = 0;
                    /* control_block->data cannot be NULL for 1 to 1 mapping */
                    control_block->data = NULL;
                }

                /* read complete */
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
            else if (control_block->primary_ID == FILE_G_EMAIL_IDX)
            {
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;
                kal_uint8 email_length = phb_ptr->email_length;
                phb_email_struct *email_entry;

                pdu_ptr = sim_read_cnf->data;

                pdu_length = sim_read_cnf->length;

                email_entry = (phb_email_struct*) control_block->data;

                /* Clean area for storing data read from stroage. */
                kal_mem_set(email_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_email_struct));

                email_entry->record_index = control_block->record_index;
                email_entry->adn_record_index = control_block->record_index;    // TODO: index

                if (*pdu_ptr != 0xFF)
                {
                    istring_type istring;

                    /* Set up email_entry->email_address */
                    istring.length = PHB_EMAIL_MAX_LEN;
                    istring.data = (kal_uint8*) email_entry->email_address;
                    email_entry->email_length = istring_decode_from_sim(email_length, pdu_ptr, &istring);

                    /* need null terminator at the end */
                    if (email_entry->email_length > PHB_EMAIL_MAX_LEN)
                    {
                        email_entry->email_length = PHB_EMAIL_MAX_LEN;
                        email_entry->email_address[PHB_EMAIL_MAX_LEN] = 0;
                    }
                    if (phb_ptr->email_type == 1)
                    {
                        email_entry->adn_record_index = control_block->record_index;
                    }
                    else
                    {
                        email_entry->adn_record_index = *(pdu_ptr + phb_ptr->email_length + 1);
                    }
                    email_entry->record_index = control_block->record_index;
                }
                else    /* Empty record!! */
                {
                    kal_mem_set(email_entry, 0, sizeof(phb_email_struct));
                    control_block->data = NULL;
                }

                /* read complete */
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
            else if (control_block->primary_ID == FILE_G_GRP_IDX)
            {
                control_block->data[0] = sim_read_cnf->data[0];
                /* read complete */
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
        #endif /* __PHB_USIM_SUPPORT__ */ 
            /* ADN-like structures */
            else
            {
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;
                phb_ef_struct phb_ef;
                phb_entry_struct *phb_entry;
                kal_uint8 alpha_id_length;

            #ifdef __PHB_USIM_SUPPORT__
                if (control_block->primary_ID == FILE_G_GAS_IDX)
                {
                    alpha_id_length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                }
                else
            #endif /* __PHB_USIM_SUPPORT__ */ 
                    alpha_id_length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage)) -
                        PHB_LENGTH_AFTER_ALPHA_ID;

                /* Note that BDN is total 15 bytes after ALPHA_ID field */
                if (control_block->primary_ID == FILE_BDN_IDX)
                {
                    alpha_id_length--;
                }

                pdu_ptr = sim_read_cnf->data;
                pdu_length = sim_read_cnf->length;

                phb_entry = (phb_entry_struct*) control_block->data;

                phb_ef.alpha_id = (kal_uint8*) pdu_ptr;
                phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

                /* Clean area for storing data read from stroage. */
                kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

                phb_entry->index = control_block->index;
                phb_entry->record_index = control_block->record_index;
                phb_entry->storage = PHB_SIM;

                /* amanda add */
                if (control_block->primary_ID == FILE_FDN_IDX)
                {
                    phb_entry->type = PHB_FDN;
                }
                else if (control_block->primary_ID == FILE_BDN_IDX)
                {
                    phb_entry->type = PHB_BDN;
                }
                else if (control_block->primary_ID == FILE_ADN_IDX)
                {
                    phb_entry->type = PHB_PHONEBOOK;
                }
            #ifdef __PHB_USIM_SUPPORT__
                else if (control_block->primary_ID == FILE_G_ADN_IDX)
                {
                    phb_entry->type = PHB_PHONEBOOK;
                }
                else if (control_block->primary_ID == FILE_G_GAS_IDX)
                {
                    phb_entry->type = PHB_GAS;
                }
            #endif /* __PHB_USIM_SUPPORT__ */ 
                else
                {
                    phb_entry->type = PHB_NONE;
                }

                if (!is_empty(pdu_ptr, pdu_length)      /* && 
                                                           (phb_ef.mandatory->len <= PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN) */ )
                {
                    istring_type istring;

                    kal_uint8 sim_ext_record_index;

                    /* Set up phb_entry->alpha_id */
                    istring.length = phb_entry->alpha_id.name_length = L4_MAX_NAME;
                    istring.data = (kal_uint8*) phb_entry->alpha_id.name;
                    phb_entry->alpha_id.name_length = istring_decode_from_sim(alpha_id_length, phb_ef.alpha_id, &istring);

                    if (phb_entry->alpha_id.name_length == 0)
                    {
                        istring.charset = PHB_ASCII;
                    }
                    phb_entry->alpha_id.name_dcs = istring.charset;

               /**
               *  No matter ASCII or UCS2 string, always makes last two byte 0
               *  Because MMI maximum length is L4_MAX_NAME, 
               *  and need two bytes null terminator at the end
               */
                    if (phb_entry->alpha_id.name_length >= (L4_MAX_NAME - 2))
                    {
                        phb_entry->alpha_id.name_length = (L4_MAX_NAME - 2);
                        phb_entry->alpha_id.name[L4_MAX_NAME - 1] = 0;
                        phb_entry->alpha_id.name[L4_MAX_NAME - 2] = 0;
                    }

               /** 
                * If returned decoded length of alpha id is 0, 
                * it is either stored alpha id is empty, 
                * or alpha id encoding is erroneous 
                */

                    /* Set up phb_entry->tel_number */
                    if (phb_ef.mandatory->len > 0 && phb_ef.mandatory->len != 0xff && phb_ef.mandatory->len <= (EF_TEL_NUMBER_SIZE + 1) && !(phb_ef.mandatory->len == 1 && phb_ef.mandatory->ton_npi != 0x91) && (phb_ef.mandatory->ton_npi != 0x00))  /* only accept + if length 1 */
                    {
                        phb_entry->tel_number.addr_length = phb_ef.mandatory->len;
                        phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_ef.mandatory->ton_npi;
                        kal_mem_cpy(
                            &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (void const*)&phb_ef.mandatory->tel_number,
                            /* TON_NPI_SIZE + */ phb_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                        phb_entry->tel_number.addr_bcd[phb_ef.mandatory->len] = 0xff;
                    }
                    else
                    {
                        kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
                        phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                    }

                    /* Empty Record!!  - If Name and Number field are both empty, regard it as an empty record!! */
                    if ((phb_entry->alpha_id.name_length == 0) && (phb_entry->tel_number.addr_length == 0))
                    {
                        kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));

                        /* control_block->data cannot be NULL for 1 to 1 mapping */
                        if ((control_block->type != PHB_MSISDN) && (control_block->type != PHB_SDN))
                        {
                            control_block->data = NULL;
                        }

                        if (control_block->type == PHB_MSISDN && phb_ptr->state != PHB_STATE_READY)
                        {
                            phb_data_desc_mark_free(
                                phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                                control_block->record_index,
                                KAL_TRUE);
                        }
                        phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                        return;
                    }

                    /* Set up phb_entry->cap_cnf_id */
                    phb_entry->cap_cnf_id = phb_ef.mandatory->cap_cnf_id;

                    /* Need reassembly? */
                    sim_ext_record_index = phb_ef.mandatory->ext_id;
                    control_block->seg_record_index = (kal_uint8) PHB_INVALID_VALUE;
                    if ((control_block->secondary_ID != PHB_NULL_VALUE) &&
                        (sim_ext_record_index != (kal_uint8) PHB_INVALID_VALUE) &&
                        (sim_ext_record_index > 0) &&
                        (sim_ext_record_index <= phb_data_desc_get_record_num(phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage))) &&
                        (phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                        /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                        (phb_ef.mandatory->len == PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN))
                    {

                        if ((phb_ptr->state != PHB_STATE_READY) &&
                            ((control_block->proc_stage == startup_build_adn_index) ||
                             (control_block->proc_stage == startup_build_fdn_index) ||
                             (control_block->proc_stage == startup_build_bdn_index) ||
                             (control_block->proc_stage == startup_build_msisdn_index)))
                        {
                            control_block->seg_record_index = sim_ext_record_index;
                            phb_data_desc_mark_free(
                                phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                                sim_ext_record_index,
                                KAL_FALSE);
                        }

                        /* 
                         * Record extension 1 record index for MSISDN deletion pricedure only.
                         * For MSISDN does not keep in  PHB, need to read back info before deletion.
                         */
                        if (control_block->type == PHB_MSISDN)
                        {
                            control_block->seg_record_index = sim_ext_record_index;
                        }

                        control_block->IO_stage = IO_REASSEMBLY;
                        control_block->IO_cnf_receive = phb_sim_read_cnf;

                  /**
                   * control_block->record_index MUST NOT be modified;
                   * that is counter of current read primary_ID!!!
                   */

                        phb_sim_read_record(
                            control_block->secondary_ID,
                            sim_ext_record_index,
                            phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID (control_block->secondary_ID, control_block->storage)),
                            control_block->ID);
                        return;
                    }
                }

                /* Empty record!! */
                else
                {
                    kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                    phb_entry->tel_number.addr_length = 0;

                    /* control_block->data cannot be NULL for 1 to 1 mapping */
                    if ((control_block->type != PHB_MSISDN) && (control_block->type != PHB_SDN))
                    {
                        control_block->data = NULL;
                    }
                    if (control_block->type == PHB_MSISDN && phb_ptr->state != PHB_STATE_READY)
                    {
                        phb_data_desc_mark_free(
                            phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                            control_block->record_index,
                            KAL_TRUE);
                    }
                }

                /* read complete */
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
        }
        else if (control_block->IO_stage == IO_REASSEMBLY)
        {
            if (sim_read_cnf->file_idx == control_block->secondary_ID)
            {
                kal_uint8 sim_ext_record_index;
                phb_entry_struct *phb_entry;
                ef_ext_type *ef_ext;

                /* sim_read_cnf->data is a EFext */
                ef_ext = (ef_ext_type*) sim_read_cnf->data;

                if (ef_ext->ext_data_length <= PHB_EF_EXT_MAX_TEL_NUMBER_LEN)
                {
                    sim_ext_record_index = phb_sim_reassemble_tel_num(ef_ext, control_block);

                    phb_entry = (phb_entry_struct*) control_block->data;
                    /* need reassembly? */
                    if ((control_block->secondary_ID != (kal_uint16) PHB_NULL_VALUE) &&
                        (sim_ext_record_index != (kal_uint8) PHB_INVALID_VALUE) &&
                        (phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                        (sim_ext_record_index > 0) &&
                        (sim_ext_record_index <= phb_data_desc_get_record_num(phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage))) &&
                        /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                        (ef_ext->ext_data_length == PHB_EF_EXT_MAX_TEL_NUMBER_LEN))
                    {
                        control_block->IO_stage = IO_REASSEMBLY;
                        control_block->IO_cnf_receive = phb_sim_read_cnf;
                        /* control_block->record_index = sim_ext_record_index; */
                        phb_sim_read_record(
                            control_block->secondary_ID,
                            sim_ext_record_index,
                            phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID (control_block->secondary_ID, control_block->storage)),
                            control_block->ID);
                    }
                    /* read complete */
                    else
                    {
                        phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                        return;
                    }
                }

                /* Illegal length, do recovery. */
                else
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                    return;
                }
            }
         /** 
          * Wrong state: this CNF is not for us. 
          * Abnormal, consume message.
          */
            else
            {
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
                return;
            }
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if (control_block->IO_stage == IO_ANR_REASSEMBLY)
        {
            if (sim_read_cnf->file_idx == control_block->secondary_ID)
            {
                kal_uint8 sim_ext_record_index;
                phb_entry_struct *phb_entry;
                ef_ext_type *ef_ext;

                /* sim_read_cnf->data is a EFext */
                ef_ext = (ef_ext_type*) sim_read_cnf->data;

                if (ef_ext->ext_data_length <= PHB_EF_EXT_MAX_TEL_NUMBER_LEN)
                {
                    sim_ext_record_index = phb_sim_reassemble_tel_num(ef_ext, control_block);

                    phb_entry = (phb_entry_struct*) control_block->data;
                    /* need reassembly? */
                    if ((control_block->secondary_ID != (kal_uint16) PHB_NULL_VALUE) &&
                        (sim_ext_record_index != (kal_uint8) PHB_INVALID_VALUE) &&
                        (phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                        /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                        (ef_ext->ext_data_length == PHB_EF_EXT_MAX_TEL_NUMBER_LEN))
                    {
                        control_block->IO_stage = IO_ANR_REASSEMBLY;
                        control_block->IO_cnf_receive = phb_sim_read_cnf;
                        /* control_block->record_index = sim_ext_record_index; */
                        phb_sim_read_record(
                            control_block->secondary_ID,
                            sim_ext_record_index,
                            phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID (control_block->secondary_ID, control_block->storage)),
                            control_block->ID);
                    }
                    /* read complete */
                    else
                    {
                        phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                        return;
                    }
                }

                /* Illegal length, do recovery. */
                else
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                    return;
                }
            }
            /* Wrong state: this CNF is not for us. Abnormal, consume message. */
            else
            {
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
                return;
            }
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 

      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_read_cnf->result;
        control_block->IO_stage = IO_NONE;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_sim_read_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  
 *  Prerequisite:
 *  data must not be NULL.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  data                [?]         
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 *data,
                kal_uint16 length,
                kal_uint8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_req_struct *sim_write_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_RECORD);

    sim_write_req = (sim_write_req_struct*) construct_local_para(sizeof(sim_write_req_struct), TD_CTRL);
    sim_write_req->file_idx = file_idx;
    sim_write_req->para = (kal_uint8) record_index;

    /* Clean data before write to SIM */
    kal_mem_set(&sim_write_req->data[0], (kal_uint8) PHB_INVALID_VALUE, MAX_DATA_LEN);

    if (data != NULL)
    {
        /* Set data */
        kal_mem_cpy(&sim_write_req->data[SIM_WRITE_OFFSET], (void const*)data, length);
    }
#ifdef __USIM_SUPPORT__
    if (is_usim_type())
    {
        data_desc_enum type = phb_data_desc_get_desc_by_ID(file_idx, PHB_SIM);

        if (type != PHB_INVALID_VALUE)
        {
            kal_mem_cpy(sim_write_req->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            sim_write_req->path[4] = phb_ptr->path[type][0];
            sim_write_req->path[5] = phb_ptr->path[type][1];
        }
    }
#endif /* __USIM_SUPPORT__ */ 

    sim_write_req->length = (kal_uint8) length;
    sim_write_req->access_id = access_id;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, sim_write_req, NULL);
}   /* end of phb_sim_write_record */


#ifdef __PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_anr_segmented_record
 * DESCRIPTION
 *  This function prepares data content for the segmented part of telephone numbers then
 *  invokes sim_write_record() to write a record.
 *  
 *  Prerequisites:
 *  control_block->phb_entry must not NULL.
 *  control_block->seg_total and control_block->seg_len must be set correctly.
 * PARAMETERS
 *  control_block       [?]         
 *  anr_entry           [?]         
 *  phb_type            [IN]        
 *  chained_id          [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool phb_sim_write_anr_segmented_record(
                    control_block_type *control_block,
                    phb_anr_struct *anr_entry,
                    phb_type_enum phb_type,
                    kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ef_ext_type ef_ext_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_SEGMENTED_RECORD); */

    ASSERT(control_block != NULL);

    /* phb_entry is ensured non-NULL by caller */

    control_block->IO_stage = IO_ANR_SEGMENTATION;
    control_block->IO_cnf_receive = phb_sim_write_cnf;

    /* find if this ADN has ext1 record to write first */
    control_block->seg_record_index = phb_se_ext_index_find(control_block->record_index, phb_type);

    if (control_block->seg_record_index == (kal_uint8) PHB_INVALID_VALUE || control_block->seg_record_index == 0)
    {
        control_block->seg_record_index = (kal_uint8) phb_data_desc_find_next_free(DATA_DESC_EXT1);
        if (control_block->seg_record_index == (kal_uint8) PHB_INVALID_VALUE)
        {
            /* Error: cannot find a free record to write */
            return KAL_FALSE;
        }
    }

    /* Now prepare the data content in ext_buffer */
    kal_mem_set(&ef_ext_buffer, (kal_uint8) PHB_INVALID_VALUE, sizeof(ef_ext_type));
    ef_ext_buffer.record_type = EF_EXT_TYPE_ADDITIONAL_DATA;
    ef_ext_buffer.ext_data_length = control_block->seg_len;
    ef_ext_buffer.identifier = chained_id;

    kal_mem_cpy(
        ef_ext_buffer.ext_data,
        (void const*)&anr_entry->tel_number.addr_bcd[anr_entry->tel_number.addr_length - control_block->seg_total - control_block->seg_len],
        control_block->seg_len);
    phb_sim_write_record(
        control_block->secondary_ID,
        control_block->seg_record_index,
        (kal_uint8*) & ef_ext_buffer,
        sizeof(ef_ext_buffer),
        control_block->ID);
    return KAL_TRUE;
}   /* end of phb_sim_write_segmented_record */
#endif /* __PHB_USIM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_segmented_record
 * DESCRIPTION
 *  This function prepares data content for the segmented part of telephone numbers then
 *  invokes sim_write_record() to write a record.
 *  
 *  Prerequisites:
 *  control_block->phb_entry must not NULL.
 *  control_block->seg_total and control_block->seg_len must be set correctly.
 * PARAMETERS
 *  control_block       [?]         
 *  type                [IN]        
 *  chained_id          [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool phb_sim_write_segmented_record(
                    control_block_type *control_block,
                    data_desc_enum type,
                    kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_entry_struct *phb_entry;
    ef_ext_type ef_ext_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_SEGMENTED_RECORD);

    ASSERT(control_block != NULL);

    /* phb_entry is ensured non-NULL by caller */
    phb_entry = (phb_entry_struct*) control_block->data;

    control_block->IO_stage = IO_SEGMENTATION;
    control_block->IO_cnf_receive = phb_sim_write_cnf;

    /* find if this ADN has ext1 record to write first */
    control_block->seg_record_index = phb_se_get_ext_index(control_block->type, phb_entry);
    if (control_block->seg_record_index == (kal_uint8) PHB_INVALID_VALUE || control_block->seg_record_index == 0)
    {
        control_block->seg_record_index = (kal_uint8) phb_data_desc_find_next_free(type);
        if (control_block->seg_record_index == (kal_uint8) PHB_INVALID_VALUE)
        {
            /* Error: cannot find a free record to write */
            control_block->cause = SIM_EF_RECORD_FULL;
            return KAL_FALSE;
        }
    }

    /* Now prepare the data content in ext_buffer */
    kal_mem_set(&ef_ext_buffer, (kal_uint8) PHB_INVALID_VALUE, sizeof(ef_ext_type));
    ef_ext_buffer.record_type = EF_EXT_TYPE_ADDITIONAL_DATA;
    ef_ext_buffer.ext_data_length = control_block->seg_len;
    ef_ext_buffer.identifier = chained_id;

    kal_mem_cpy(
        ef_ext_buffer.ext_data,
        (void const*)&phb_entry->tel_number.addr_bcd[phb_entry->tel_number.addr_length - control_block->seg_total - control_block->seg_len],
        control_block->seg_len);
    phb_sim_write_record(
        control_block->secondary_ID,
        control_block->seg_record_index,
        (kal_uint8*) & ef_ext_buffer,
        sizeof(ef_ext_buffer),
        control_block->ID);
    return KAL_TRUE;
}   /* end of phb_sim_write_segmented_record */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_first_record
 * DESCRIPTION
 *  This function prepares data content for the first part of telephone numbers then
 *  invokes sim_write_record() to write a record.
 *  
 *  Prerequisites:
 *  control_block->phb_entry must not be NULL.
 *  primary_ID and its data_desc_type must no be PHB_INVALID_VALUE
 *  control_block->data and length must be setup.
 * PARAMETERS
 *  control_block       [?]         
 *  chained_id          [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_write_first_record(
            control_block_type *control_block,
            /* data_desc_enum type, */ kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *ef_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_FIRST_RECORD);

    ASSERT(control_block != NULL);

    control_block->IO_stage = IO_WAIT;
    control_block->IO_cnf_receive = phb_sim_write_cnf;

    ef_buffer = (kal_uint8*) get_ctrl_buffer(control_block->length);

    if (phb_sim_prepare_data_to_write(control_block, ef_buffer, chained_id) == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    /* Perparation of data content complete! */
    phb_sim_write_record(
        control_block->primary_ID,
        control_block->record_index,
        ef_buffer,
        control_block->length,
        control_block->ID);

    if (ef_buffer != NULL)
    {
        free_ctrl_buffer(ef_buffer);
    }

    return KAL_TRUE;
}   /* end of phb_sim_write_first_record */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 *  
 *  Assumption:
 *  control_block->type, control_block->primary_ID is assumed to be valid.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_write(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    kal_uint8 ext1_need_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        data_desc_enum type = DATA_DESC_PHB;
        phb_entry_struct *phb_entry;

    #ifdef __PHB_USIM_SUPPORT__
        if (phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage) == DATA_DESC_ANRA)
        {
            control_block->ext1_parent_type = PHB_ANRA; // TODO: another type?
        }
        else
    #endif /* __PHB_USIM_SUPPORT__ */ 
        {
            control_block->ext1_parent_type = PHB_PHONEBOOK;
        }
        /* Nothing to write? error! */
        if ((phb_entry = (phb_entry_struct*) control_block->data) == NULL)
        {
            return KAL_FALSE;
        }

        /* check if enough EXT1 */
        /* First, find out whether free records in EFext suffice */
        if (phb_se_get_ext_index(control_block->ext1_parent_type, phb_entry) == (kal_uint8) PHB_INVALID_VALUE)
        {
        #ifdef __PHB_USIM_SUPPORT__
            if (control_block->ext1_parent_type == PHB_PHONEBOOK)
        #endif 
            {
                ext1_need_num +=
                    ((phb_entry->tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN + EF_TEL_NUMBER_SIZE -
                      1) / EF_TEL_NUMBER_SIZE);
            }
        }
        if ((control_block->secondary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
            ((type = phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage)) !=
             (data_desc_enum) PHB_INVALID_VALUE) && phb_data_desc_get_free_count(type) < ext1_need_num
            && (control_block->index == (kal_uint16) PHB_INVALID_VALUE))
        {
            /* SIM has no more space to chain long numbers */
            control_block->cause = SIM_EF_RECORD_FULL;
            result = KAL_FALSE;
        }

    #ifdef __PHB_USIM_SUPPORT__
        else if (phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage) == DATA_DESC_ANRA)
        {
            control_block->seg_total = 0;
            if (control_block->ext1_parent_type == PHB_ANRA &&
                ((control_block->temp_anra.tel_number.addr_length - TON_NPI_SIZE) > EF_TEL_NUMBER_SIZE))
            {
                /* ext1_need_num += ((control_block->temp_anra.tel_number.addr_length - PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN + EF_TEL_NUMBER_SIZE - 1) / EF_TEL_NUMBER_SIZE); */
                if ((control_block->seg_len =
                     (control_block->temp_anra.tel_number.addr_length - TON_NPI_SIZE) % EF_TEL_NUMBER_SIZE) == 0)
                {
                    control_block->seg_len = EF_TEL_NUMBER_SIZE;
                }

                result = phb_sim_write_anr_segmented_record(
                            control_block,
                            &(control_block->temp_anra),
                            control_block->ext1_parent_type,
                            (kal_uint8) PHB_INVALID_VALUE);

            }
            else if (control_block->ext1_parent_type == PHB_ANRB)
            {
            }
            else if (control_block->ext1_parent_type == PHB_ANRC)
            {
            }
            /* Segmentation is not needed */
            /* control_block->type, control_block->primary_ID is assumed to be valid. */
            else
            {
                control_block->seg_total = 0;
                result = phb_sim_write_first_record(control_block, /* type, */ (kal_uint8) PHB_INVALID_VALUE);
            }
            return result;
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 

        /* Need segmentation */
        else if ((type != (data_desc_enum) PHB_INVALID_VALUE) &&
                 ((phb_entry->tel_number.addr_length - TON_NPI_SIZE) > EF_TEL_NUMBER_SIZE))
        {
            control_block->seg_total = 0;

            /* Each write iteration writes a segment of data from tail to head */
         /** 
          * Because first segment stored in ADN-like EF could store 1 byte 
          * more than EXT-like EF, decrement length to retain that byte to
          * be written in first segment.
          */
            if ((control_block->seg_len = (phb_entry->tel_number.addr_length - TON_NPI_SIZE) % EF_TEL_NUMBER_SIZE) == 0)
            {
                control_block->seg_len = EF_TEL_NUMBER_SIZE;
            }

            result = phb_sim_write_segmented_record(control_block, type, (kal_uint8) PHB_INVALID_VALUE);
        }

        /* Segmentation is not needed */
        /* control_block->type, control_block->primary_ID is assumed to be valid. */
        else
        {
            control_block->seg_total = 0;
            result = phb_sim_write_first_record(control_block, /* type, */ (kal_uint8) PHB_INVALID_VALUE);
        }
    }
    /* Error */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_sim_write */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_write_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_CNF);

    ASSERT(control_block != NULL);

    sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_write_cnf->result == SIM_CMD_SUCCESS)
    {
        /* Success */
        if (control_block->IO_stage == IO_WAIT)
        {
            control_block->IO_stage = IO_NONE;
            control_block->IO_cnf_receive = NULL;
            (*control_block->return_location) (ilm_ptr, control_block);
        }
        /* In segmentation ? */
        else if ((control_block->IO_stage == IO_SEGMENTATION) &&
                 (sim_write_cnf->file_idx == control_block->secondary_ID))
        {
            data_desc_enum type;
            phb_entry_struct *phb_entry;

            phb_entry = (phb_entry_struct*) control_block->data;

            control_block->seg_total += control_block->seg_len;

            /* Since segmented data is written, that record must be marked */
            phb_data_desc_mark_free(
                phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                control_block->seg_record_index,
                KAL_FALSE);

            /* Still need segmentation */
            if ((control_block->secondary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
                ((type = phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage)) !=
                 (data_desc_enum) PHB_INVALID_VALUE) &&
                ((phb_entry->tel_number.addr_length - TON_NPI_SIZE - control_block->seg_total) > EF_TEL_NUMBER_SIZE))
            {
                control_block->seg_len = EF_TEL_NUMBER_SIZE;

                /* Error: cannot find a free record to write */
                if (phb_sim_write_segmented_record(control_block, type, control_block->seg_record_index) == KAL_FALSE)
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
            }
            /* Finally, segmentation is not needed. First record now can be written */
            else if ((control_block->primary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
                     ((type = phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage)) !=
                      (data_desc_enum) PHB_INVALID_VALUE))
            {
                /* Error: cannot write first record */
                if (phb_sim_write_first_record(control_block, /* type, */ control_block->seg_record_index) ==
                    KAL_FALSE)
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
            }
         /** 
          * Wrong state: this CNF is not for us. 
          * Abnormal, consume message.
          */
            else
            {
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                return;
            }
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if ((control_block->IO_stage == IO_ANR_SEGMENTATION) &&
                 (sim_write_cnf->file_idx == control_block->secondary_ID))
        {
            data_desc_enum type;
            phb_anr_struct *anr_entry = &(control_block->temp_anra);

            control_block->seg_total += control_block->seg_len;

            //set ext_index_table
            //phb_se_ext_index_set(control_block->record_index, 
            //                        control_block->seg_record_index, 
            //                        control_block->ext1_parent_type);
            /* Since segmented data is written, that record must be marked */
            phb_data_desc_mark_free(
                phb_data_desc_get_desc_by_ID(control_block->secondary_ID, control_block->storage),
                control_block->seg_record_index,
                KAL_FALSE);

            /* Still need segmentation */
            if ((anr_entry->tel_number.addr_length - TON_NPI_SIZE - control_block->seg_total) > EF_TEL_NUMBER_SIZE)
            {
                control_block->seg_len = EF_TEL_NUMBER_SIZE;

                /* Error: cannot find a free record to write */
                if (phb_sim_write_anr_segmented_record(
                        control_block,
                        anr_entry,
                        control_block->ext1_parent_type,
                        control_block->seg_record_index) == KAL_FALSE)
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
            }
            /* Finally, segmentation is not needed. First record now can be written */
            else if ((control_block->primary_ID != (kal_uint16) PHB_INVALID_VALUE) &&
                     ((type = phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage)) !=
                      (data_desc_enum) PHB_INVALID_VALUE))
            {
                /* Error: cannot write first record */
                if (phb_sim_write_first_record(control_block, /* type, */ control_block->seg_record_index) ==
                    KAL_FALSE)
                {
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
            }
            /* Wrong state: this CNF is not for us. Abnormal, consume message. */
            else
            {
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                return;
            }
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 
        /* Wrong state: currently it is not waiting. Abnormal, consume message. */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_write_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_sim_write_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_delete
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_delete(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_DELETE);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_sim_delete_cnf;
        phb_sim_write_record(
            control_block->primary_ID,
            control_block->record_index,
            NULL,
            control_block->length,
            control_block->ID);
        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of phb_sim_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_delete_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_delete_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_DELETE_CNF);

    ASSERT(control_block != NULL);

    sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_write_cnf->result == SIM_CMD_SUCCESS)
    {
        if (control_block->IO_stage == IO_WAIT)
        {
            /* success */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_write_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_sim_delete_cnf */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_prepare_data_to_write
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
 *  chained_id          [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_bool phb_sim_prepare_data_to_write(control_block_type *control_block, kal_uint8 *buffer, kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PREPARE_DATA_TO_WRITE);

#ifdef __PHB_USIM_SUPPORT__
    if (control_block->type == PHB_ANR)
    {
        phb_ef_mandatory_struct *phb_ef_mandatory = NULL;
        phb_anr_struct *anr_entry = (phb_anr_struct*) control_block->data;

        kal_uint8 tel_number_size = 0;

        /* Referenced control_block shall not be NULL) */
        ASSERT(control_block != NULL);

        kal_mem_set(buffer, 0xFF, control_block->length);
        buffer[0] = 0;
        /* Now prepare the data content */
        phb_ef_mandatory = (phb_ef_mandatory_struct*) & buffer[1];

        if (anr_entry->tel_number.addr_length == 1) /* Empty number */
        {
            /* "+" character */
            if (anr_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
            {
                phb_ef_mandatory->len = 1;
                phb_ef_mandatory->ton_npi = 0x91;
            }
            else
            {
                phb_ef_mandatory->len = 0xff;
                phb_ef_mandatory->ton_npi = 0xff;
            }
            kal_mem_set((kal_uint8*) phb_ef_mandatory->tel_number, 0xff, EF_TEL_NUMBER_SIZE);  /* 0x91 */
        }
        else
        {
            /* Length of telephone number is ensured to be less than EF_TEL_NUMBER_SIZE */
            phb_ef_mandatory->len = anr_entry->tel_number.addr_length - control_block->seg_total;
            if (phb_ef_mandatory->len > 0)
            {
                tel_number_size = phb_ef_mandatory->len - 1;
            }
            phb_ef_mandatory->ton_npi = anr_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
            kal_mem_cpy(
                &phb_ef_mandatory->tel_number[0],
                (void const*)&anr_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                tel_number_size);
        }
        phb_ef_mandatory->cap_cnf_id = anr_entry->cap_cnf_id;
        phb_ef_mandatory->ext_id = chained_id;
    }
    else if (control_block->type == PHB_EMAIL)
    {
        phb_email_struct *email_entry = (phb_email_struct*) control_block->data;

        kal_uint8 alpha_id_length = 0;

        /* Referenced control_block shall not be NULL) */
        ASSERT(control_block != NULL);

        alpha_id_length = control_block->length;
        if (phb_ptr->email_type == 2)
        {
            alpha_id_length -= 2;
        }
        kal_mem_set(buffer, 0xFF, control_block->length);

        /* Now prepare the data content */
        if (email_entry->email_length > 0)
        {
            istring_type istr;
            kal_uint8 write_length;

            istr.length = email_entry->email_length;
            istr.charset = CHARSET_ASCII;
            istr.data = &email_entry->email_address[0];

            /* Error occured when encoding alph-id field */
            write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
            if (write_length == 0)
            {
                return KAL_FALSE;
            }
            email_entry->email_length = write_length;

            email_entry->email_address[email_entry->email_length] = 0;
            /* email_entry->email_address[email_entry->email_length + 1] = 0; */
        }
        if (phb_ptr->email_type == 2)
        {
            buffer[alpha_id_length] = phb_ptr->adn_sfi;
            buffer[alpha_id_length + 1] = email_entry->adn_record_index;
        }
    }
    else if (control_block->type == PHB_GAS)
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        kal_uint8 alpha_id_length = 0;

        /* Referenced control_block shall not be NULL) */
        ASSERT(control_block != NULL);

        alpha_id_length = control_block->length;
        kal_mem_set(buffer, 0xFF, control_block->length);

        /* Now prepare the data content */
        if (phb_entry->alpha_id.name_length > 0)
        {
            istring_type istr;
            kal_uint8 write_length;

            istr.length = phb_entry->alpha_id.name_length;
            istr.charset = phb_entry->alpha_id.name_dcs;
            istr.data = &phb_entry->alpha_id.name[0];

            /* Error occured when encoding alph-id field */
            write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
            if (write_length == 0)
            {
                return KAL_FALSE;
            }
            /* amanda add */
            if (phb_entry->alpha_id.name_dcs == CHARSET_ASCII)
            {
                phb_entry->alpha_id.name_length = write_length;
            }
        #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
            else if (phb_entry->alpha_id.name_dcs == CHARSET_UCS2_81)
            {
                phb_entry->alpha_id.name_length = write_length;
                phb_entry->alpha_id.name[1] = write_length - 3;
            }
        #endif /* __PHB_0x81_SUPPORT__ */ 
            else
            {
                phb_entry->alpha_id.name_length = write_length * 2;
            }

            phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
            phb_entry->alpha_id.name[phb_entry->alpha_id.name_length + 1] = 0;
        }
    }
    else if (control_block->type == PHB_GRP)
    {
        kal_mem_set(buffer, 0x00, control_block->length);   /* '00'- no group indicated */
        buffer[0] = control_block->temp_group_id;
    }
    else if (control_block->type == PHB_IAP)
    {
        kal_mem_cpy(buffer,
                    control_block->temp_iap,
                    control_block->length);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        phb_ef_mandatory_struct *phb_ef_mandatory = NULL;
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        kal_uint8 alpha_id_length = 0;
        kal_uint8 tel_number_size = 0;

        /* Referenced control_block shall not be NULL) */
        ASSERT(control_block != NULL);

        alpha_id_length = control_block->length - PHB_LENGTH_AFTER_ALPHA_ID;
        if (control_block->type == PHB_BDN)
        {
            alpha_id_length--;
        }
        kal_mem_set(buffer, 0xFF, control_block->length);

        /* Now prepare the data content */
        if (phb_entry->alpha_id.name_length > 0)
        {
            istring_type istr;
            kal_uint8 write_length;

            istr.length = phb_entry->alpha_id.name_length;
            istr.charset = phb_entry->alpha_id.name_dcs;
            istr.data = &phb_entry->alpha_id.name[0];

            /* Error occured when encoding alph-id field */
            write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
            if (write_length == 0)
            {
                return KAL_FALSE;
            }
            /* amanda add */
            if (phb_entry->alpha_id.name_dcs == CHARSET_ASCII)
            {
                phb_entry->alpha_id.name_length = write_length;
            }
        #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
            else if (phb_entry->alpha_id.name_dcs == CHARSET_UCS2_81)
            {
                phb_entry->alpha_id.name_length = write_length;
                phb_entry->alpha_id.name[1] = write_length - 3;
            }
        #endif /* __PHB_0x81_SUPPORT__ */ 
            else
            {
                phb_entry->alpha_id.name_length = write_length * 2;
            }

            phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
            phb_entry->alpha_id.name[phb_entry->alpha_id.name_length + 1] = 0;
        }

        phb_ef_mandatory = (phb_ef_mandatory_struct*) & buffer[alpha_id_length];

        if (phb_entry->tel_number.addr_length == 1) /* Empty number */
        {
            /* "+" character */
            if (phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
            {
                phb_ef_mandatory->len = 1;
                phb_ef_mandatory->ton_npi = 0x91;
            }
            else
            {
                phb_ef_mandatory->len = 0xff;
                phb_ef_mandatory->ton_npi = 0xff;
            }
            kal_mem_set((kal_uint8*) phb_ef_mandatory->tel_number, 0xff, EF_TEL_NUMBER_SIZE);  /* 0x91 */
        }
        else
        {
            /* Length of telephone number is ensured to be less than EF_TEL_NUMBER_SIZE */
            phb_ef_mandatory->len = phb_entry->tel_number.addr_length - control_block->seg_total;
            if (phb_ef_mandatory->len > 0)
            {
                tel_number_size = phb_ef_mandatory->len - 1;
            }
            phb_ef_mandatory->ton_npi = phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
            kal_mem_cpy(
                &phb_ef_mandatory->tel_number[0],
                (void const*)&phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                tel_number_size);
        }
        phb_ef_mandatory->cap_cnf_id = phb_entry->cap_cnf_id;
        phb_ef_mandatory->ext_id = chained_id;
    }
    return KAL_TRUE;
}   /* end of phb_is_type_valid */


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_from_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (sim_read_req_struct*) construct_local_para((kal_uint16) sizeof(sim_read_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = control_block->index;
    param_ptr->length = control_block->length / control_block->seg_total;
    param_ptr->access_id = control_block->ID;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_READ_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_to_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 length;
    sim_write_req_struct *param_ptr;
    nvram_ef_phb_ln_struct *pdu_data, *pdu_data1 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;

    pdu_data = (nvram_ef_phb_ln_struct*) get_pdu_ptr(control_block->peer_buf_ptr, &length);

    if (control_block->data != NULL)
    {
        /* second NVRAM LID */
        pdu_data1 = (nvram_ef_phb_ln_struct*) get_pdu_ptr((peer_buff_struct*) control_block->data, &length);
    }

    param_ptr = (sim_write_req_struct*) construct_local_para((kal_uint16) sizeof(sim_write_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = 0;
    param_ptr->access_id = control_block->ID;
    param_ptr->length = phb_sync_translate_ln_to_sim(param_ptr->data, pdu_data, pdu_data1, control_block);

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_sync_translate_ln_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]     
 *  record              [?]     
 *  record1             [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 phb_sync_translate_ln_to_sim(
                    kal_uint8 *data,
                    nvram_ef_phb_ln_struct *record,
                    nvram_ef_phb_ln_struct *record1,
                    control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __VOIP__
    kal_uint8 flag;
    kal_uint16 index, back_index;
#endif /* !__VOIP__ */
    phb_ln_entry_struct *entry = NULL;

    kal_uint16 rec_size = control_block->seg_len;
    kal_uint16 alpha_size = rec_size - PHB_LENGTH_AFTER_ALPHA_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data += 5;

#ifdef __VOIP__
    if (control_block->index > PHB_MAX_LN_ENTRIES)
    {
        entry = &record1->array[control_block->index - PHB_MAX_LN_ENTRIES - 1];
        control_block->index--;
    }
    else
    {
        entry = &record->array[control_block->index - 1];
        control_block->index--;
    }
#else /* __VOIP__*/
    /* write LND to SIM should start from the oldest record, i.e the last one in NVRAM 
       LID2 if possible */

    /* flag(default): which NVRAM LID is to be written to SIM in this round */
    flag = 1;
    /* index(default): which record in the first NVRAM LID is to be written to SIM in this round */
    index = PHB_MAX_LN_ENTRIES - control_block->index - 1;

    /* LID2 if possible
       control_block->index: how many records has been written to SIM */
    if (record1 != NULL)
    {
        /* two NVRAM LIDs
           back_index: which record in total NVRAM LIDs is to be written to SIM in this round */
        /* if (control_block->seg_total <= record->no_entry + record1->no_entry) */
        back_index = control_block->seg_total - control_block->index - 1;
        //else
        //back_index = PHB_MAX_LNM_ENTRIES- control_block->index - 1;
        if (back_index >= PHB_MAX_LN_ENTRIES /* record->no_entry */ )
        {
            /* record to be written to SIM in this round is in the second NVRAM LID */
            flag = 2;
            /* index: which record in the second NVRAM LID is to be written to SIM in this round */
            index = back_index - PHB_MAX_LN_ENTRIES;
            if (index >= record1->no_entry)
            {
                /* the record in NVRAM to be written to SIM is empty */
                control_block->index++;
                kal_mem_set(data, 0xff, rec_size);
                return rec_size;
            }
            else
            {
                entry = &record1->array[index];
                control_block->index++;
            }
        }
        else
        {
            /* record to be written to SIM in this round is in the first NVRAM LID
               index: which record in the first NVRAM LID is to be written to SIM in this round */
            index = back_index;
        }

    }
#if (MAX_PHB_LN_ENTRY <= 10) || (MAX_PHB_LN_ENTRY > 20)
    else    /* only one LID */
    {
        /* back_index: which record in total NVRAM LIDs is to be written to SIM */
        back_index = control_block->seg_total - control_block->index - 1;
        if (back_index < PHB_MAX_LN_ENTRIES)
        {
            index = back_index;
        }
    }
#endif /* (MAX_PHB_LN_ENTRY <= 10) || (MAX_PHB_LN_ENTRY > 20) */

    if (flag == 1)
    {
        /* record to be written to SIM in this round is in the first NVRAM LID */
        if (index >= record->no_entry)
        {
            /* the record in NVRAM to be written to SIM is empty */
            control_block->index++;
            kal_mem_set(data, 0xff, rec_size);
            return rec_size;
        }
        else
        {
            entry = &record->array[index];
            control_block->index++;
        }
    }
#endif /* __VOIP__ */
    /* Now prepare the data content */
    if ((entry->name_length > 0) && (alpha_size > 0))
    {
        istring_type istr;

        istr.length = entry->name_length;
        istr.charset = entry->name_dcs;
        istr.data = &entry->name[0];

        /* Error occured when encoding alph-id field */
        if (istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, (kal_uint8) alpha_size, data) == 0)
        {
            return 0;
        }
    }
    else
    {
        kal_mem_set(data, 0, alpha_size);
    }

    data[alpha_size] = entry->addr_length;
    data[alpha_size + 1] = entry->addr_bcd[0];
    kal_mem_cpy(data + alpha_size + 2, &entry->addr_bcd[1], 10);
    data[alpha_size + 12] = 0;
    data[alpha_size + 13] = 0;

    return rec_size;
}

