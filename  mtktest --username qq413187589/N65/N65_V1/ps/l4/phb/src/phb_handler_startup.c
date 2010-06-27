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
 * phb_handler_startup.c
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

#include "nvram_struct.h"
#include "nvram_enums.h"
#include "nvram_interface.h"
/* NVRAM_EF_PHB_LID */
// #include "nvram_data_items.h"
#include "nvram_user_defs.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "ps2sim_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#ifdef __SAT__
#include "ps2sat_struct.h"
#endif 

#include "l4_defs.h"
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

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#include "phb_handler_write.h"
#endif 

/* SIM access */
#include "phb_sim_access.h"

/* NVRAM_EF_PHB_LID structure */
#include "phb_nvram_data.h"
#include "phb_nvram_access.h"

#include "phb_config.h"
#include "phb_handler_startup.h"

#ifdef __GEMINI__
#include  "sim_common_enums.h"
#endif /* __GEMINI__ */

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_STARTUP_C_

#define SIM_EF_EXT_SIZE 13
#ifdef __USIM_SUPPORT__
#define PHB_TYPE_1_FILE 0xA8
#define PHB_TYPE_2_FILE 0xA9
#define PHB_TYPE_3_FILE 0xAA
#define PHB_ADN_DO 0xC0
#define PHB_IAP_DO 0xC1
#define PHB_EXT1_DO 0xC2
#define PHB_SNE_DO 0xC3
#define PHB_ANR_DO 0xC4
#define PHB_PBC_DO 0xC5
#define PHB_GRP_DO 0xC6
#define PHB_AAS_DO 0xC7
#define PHB_GAS_DO 0xC8
#define PHB_UID_DO 0xC9
#define PHB_EMAIL_DO 0xCA
#define PHB_CCP1_DO 0xCB


extern kal_bool is_usim_type(void);
#endif /* __USIM_SUPPORT__ */

#ifdef __PHB_USIM_SUPPORT__
static void phb_build_gas_index(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_build_grp_index(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif /* __PHB_USIM_SUPPORT__ */ 

static void phb_startup_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
void phb_startup_confirm(phb_errno_enum result, control_block_type *control_block);
static void phb_build_index(ilm_struct *ilm_ptr, control_block_type *control_block);

void phb_get_info(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_get_info_set_value(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_get_info_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);

static void phb_startup_copy_ln(ilm_struct *ilm_ptr, control_block_type *control_block);

#ifndef __PHB_NVRAM_LN_ONLY__
static void phb_startup_translate_ln_from_sim(kal_uint8 *data, control_block_type *control_block);
#endif 

void phb_init_ln_confirm(phb_errno_enum result, control_block_type *control_block);


/*****************************************************************************
 * FUNCTION
 *  phb_read_ecc
 * DESCRIPTION
 *  This is phb_read_ecc function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_ecc(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    else
    {

        /* Reading ECC */
    #ifdef __USIM_SUPPORT__
        if (is_usim_type())
        {
            if (control_block->data[0] != 0xff)
            {
                kal_mem_cpy(
                    &phb_ptr->ecc.ecc[phb_ptr->ecc.num_ecc * NUM_OF_BYTE_ECC],
                    (void const*)(control_block->data),
                    NUM_OF_BYTE_ECC);
                phb_ptr->ecc.num_ecc++;
            }
        }
        else
    #endif /* __USIM_SUPPORT__ */ 
        {
            kal_uint8 i;
            kal_uint8 num_of_rec = phb_ptr->ecc.num_ecc / NUM_OF_BYTE_ECC;

            phb_ptr->ecc.num_ecc = 0;
            for (i = 0; i < num_of_rec; i++)
            {
                if (control_block->data[i * NUM_OF_BYTE_ECC] != 0xff)
                {
                    kal_mem_cpy(
                        &phb_ptr->ecc.ecc[phb_ptr->ecc.num_ecc * NUM_OF_BYTE_ECC],
                        (void const*)(control_block->data + i * NUM_OF_BYTE_ECC),
                        NUM_OF_BYTE_ECC);
                    phb_ptr->ecc.num_ecc++;
                }
            }
        }
        if (++control_block->actual_count >= control_block->total)
        {
            /* phb_starup_handler */
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            ++control_block->record_index;
            phb_issue_IO_read(control_block);
        }
    }
}   /* end of phb_build_ecc_index function */


#ifdef __USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_read_pbr
 * DESCRIPTION
 *  This is phb_read_pbr function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_pbr(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    else
    {
        /* Reading PBR */
        kal_uint8 fileType = 0;
        kal_uint8 pos = 0;
        kal_uint8 anr_num = 0;
        data_desc_enum do_type = 0xFF;

        if (control_block->actual_count == 0)   /* first pbr */
        {
            while (pos < phb_ptr->data_desc[DATA_DESC_PBR].record_size)
            {
                switch (control_block->data[pos])
                {
                    case PHB_TYPE_1_FILE:
                        fileType = 1;
                        break;
                    case PHB_TYPE_2_FILE:
                        fileType = 2;
                        break;
                    case PHB_TYPE_3_FILE:
                        fileType = 3;
                        break;
                    case PHB_ADN_DO:
                        do_type = DATA_DESC_ADN;
                        if (control_block->data[pos + 1] == 3)  /* add length + 1 */
                        {
                            phb_ptr->adn_sfi = control_block->data[pos + 4];
                        }
                        break;
                    case PHB_EXT1_DO:
                        do_type = DATA_DESC_EXT1;
                        break;
                #ifdef __PHB_USIM_SUPPORT__
                    case PHB_IAP_DO:
                        do_type = DATA_DESC_IAP;
                        break;
                    case PHB_SNE_DO:
                        do_type = DATA_DESC_SNE;
                        phb_ptr->sne_type = fileType;
                        if (fileType == 2 && phb_ptr->iap_length < PHB_IAP_MAX_OBJECT)
                        {
                            phb_ptr->iap_sne = phb_ptr->iap_length;
                            phb_ptr->iap_length++;
                        }
                        break;
                    case PHB_ANR_DO:
                        if (anr_num == 0)
                        {
                            do_type = DATA_DESC_ANRA;
                            phb_ptr->anra_type = fileType;
                            if (fileType == 2 && phb_ptr->iap_length < PHB_IAP_MAX_OBJECT)
                            {
                                phb_ptr->iap_anra = phb_ptr->iap_length;
                                phb_ptr->iap_length++;
                            }
                        }
                        else if (anr_num == 1)
                        {
                            do_type = DATA_DESC_ANRB;
                            phb_ptr->anrb_type = fileType;
                            if (fileType == 2 && phb_ptr->iap_length < PHB_IAP_MAX_OBJECT)
                            {
                                phb_ptr->iap_anrb = phb_ptr->iap_length;
                                phb_ptr->iap_length++;
                            }
                        }
                        else if (anr_num == 2)
                        {
                            do_type = DATA_DESC_ANRC;
                            phb_ptr->anrc_type = fileType;
                            if (fileType == 2 && phb_ptr->iap_length < PHB_IAP_MAX_OBJECT)
                            {
                                phb_ptr->iap_anrc = phb_ptr->iap_length;
                                phb_ptr->iap_length++;
                            }
                        }
                        anr_num++;
                        break;
                    case PHB_PBC_DO:
                        do_type = DATA_DESC_PBC;
                        break;
                    case PHB_GRP_DO:
                        do_type = DATA_DESC_GRP;
                        break;
                    case PHB_AAS_DO:
                        do_type = DATA_DESC_AAS;
                        break;
                    case PHB_GAS_DO:
                        do_type = DATA_DESC_GAS;
                        break;
                    case PHB_UID_DO:
                        do_type = DATA_DESC_UID;
                        break;
                    case PHB_EMAIL_DO:
                        /* if (phb_ptr->email_support_type == 0) */
                        phb_ptr->email_type = fileType;
                        do_type = DATA_DESC_EMAIL;
                        if (fileType == 2 && phb_ptr->iap_length < PHB_IAP_MAX_OBJECT)
                        {
                            phb_ptr->iap_email = phb_ptr->iap_length;
                            phb_ptr->iap_length++;
                        }
                        break;
                    case PHB_CCP1_DO:
                        break;
                #endif /* __PHB_USIM_SUPPORT__ */
                    default:
                        do_type = 0xFF;
                        break;
                }
                switch (control_block->data[pos])
                {
                    case PHB_TYPE_1_FILE:
                    case PHB_TYPE_2_FILE:
                    case PHB_TYPE_3_FILE:
                        pos = pos + 2;
                        break;
                    default:
                        if (do_type != 0xFF)
                        {
                            /* set path */
                            phb_ptr->path[do_type][0] = control_block->data[pos + 2];
                            phb_ptr->path[do_type][1] = control_block->data[pos + 3];
                            phb_ptr->data_desc[do_type].is_support = KAL_TRUE;
                        }
                        pos = pos + control_block->data[pos + 1] + 2;   /* add length + 1 tag + 1 size */
                        break;
                }
            }
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if (control_block->actual_count == 1)  /* second pbr */
        {
            anr_num = 0;
            while (pos < phb_ptr->data_desc[DATA_DESC_PBR].record_size)
            {
                switch (control_block->data[pos])
                {
                    case PHB_TYPE_1_FILE:
                        fileType = 1;
                        break;
                    case PHB_TYPE_2_FILE:
                        fileType = 2;
                        break;
                    case PHB_TYPE_3_FILE:
                        fileType = 3;
                        break;
                    case PHB_ADN_DO:
                        do_type = DATA_DESC_ADN1;
                        if (control_block->data[pos + 1] == 3)  /* add length + 1 */
                        {
                            phb_ptr->adn1_sfi = control_block->data[pos + 4];
                        }
                        break;
                    case PHB_IAP_DO:
                        do_type = DATA_DESC_IAP1;
                        break;
                    case PHB_SNE_DO:
                        do_type = DATA_DESC_SNE1;
                        break;
                    case PHB_ANR_DO:
                        if (anr_num == 0)
                        {
                            do_type = DATA_DESC_ANRA1;
                        }
                        else if (anr_num == 1)
                        {
                            do_type = DATA_DESC_ANRB1;
                        }
                        else if (anr_num == 2)
                        {
                            do_type = DATA_DESC_ANRC1;
                        }
                        anr_num++;
                        break;
                    case PHB_PBC_DO:

                        break;
                    case PHB_GRP_DO:

                        break;
                    case PHB_AAS_DO:

                        break;
                    case PHB_GAS_DO:

                        break;
                    case PHB_UID_DO:

                        break;
                    case PHB_EMAIL_DO:
                        /* if (phb_ptr->email_support_type == 0) */

                        break;
                    case PHB_CCP1_DO:
                        fileType = 1;
                        break;

                }
                switch (control_block->data[pos])
                {
                    case PHB_TYPE_1_FILE:
                    case PHB_TYPE_2_FILE:
                        pos = pos + 2;
                        break;
                    case PHB_TYPE_3_FILE:
                        pos = pos + 2 + control_block->data[pos + 1];   /* skip all type 3 content */
                        break;
                    default:
                        pos = pos + control_block->data[pos + 1] + 1;
                        break;
                }
            }

        }

        if (++control_block->actual_count < control_block->total)
        {
            ++control_block->record_index;
            phb_issue_IO_read(control_block);
        }
        else
    #endif /* __PHB_USIM_SUPPORT__ */
        {
            /* phb_startup_handler */
            (*control_block->controller) (NULL, control_block);
        }
    }
}   /* end of phb_build_ecc_index function */
#endif /* _USIM_SUPPORT__ */


#ifdef __PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_get_next_process_index
 * DESCRIPTION
 *  This is phb_get_next_adn function of PHB module.
 * PARAMETERS
 *  record_index        [IN]        
 *  type                [IN]        
 *  kal_uint16(?)       [IN]        The record index
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_get_next_process_index(kal_uint16 record_index, phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == PHB_ANR && phb_ptr->anra_type == 2)
    {
        return (kal_uint16) record_index;
    }
    else if (type == PHB_EMAIL && phb_ptr->email_type == 2)
    {
        return (kal_uint16) record_index;
    }
    else if (record_index != (kal_uint16) PHB_INVALID_VALUE)
    {
        kal_uint16 i;

        for (i = record_index; i < phb_ptr->data_desc[DATA_DESC_ADN].record_num; i++)
        {
            free_status_enum free_status;

            free_status = phb_data_desc_is_free(DATA_DESC_ADN, i);
         /**
         * This case results from:
         * 1. Non supported EF.
         * 2. Attempt written record index excceds max supported capacity.
         */

            if (free_status == RECORD_INVALID)
            {
                return (kal_uint16) PHB_INVALID_VALUE;
            }

            if (free_status == RECORD_OCCUPIED)
            {
                return i;
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_build_anr_index
 * DESCRIPTION
 *  This is build_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_anr_index(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 next_record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        next_record_index = phb_get_next_process_index(control_block->record_index, PHB_ANR);
        if (next_record_index == (kal_uint16) PHB_INVALID_VALUE)        /* no other ADN */
        {
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            control_block->actual_count += (next_record_index - control_block->record_index);
            control_block->record_index = next_record_index;
            phb_issue_IO_read(control_block);
        }
    }
    else
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        /* For valid record, control_block.data must not NULL */
        if (phb_entry != NULL)
        {
        #if defined(__MMI_FMI__)
            /* Send out indication for each anr entries and wait response to read next. */
            l4cphb_startup_read_anr_ind_struct *l4cphb_startup_read_anr_ind =
                (l4cphb_startup_read_anr_ind_struct*) construct_local_para(
                                                        sizeof(l4cphb_startup_read_anr_ind_struct),
                                                        TD_CTRL);
            // TODO: anr type

            memcpy(
                &l4cphb_startup_read_anr_ind->anr_entry[0].tel_number,
                &(((phb_entry_struct*) control_block->data)->tel_number),
                sizeof(l4_addr_bcd_struct));
            l4cphb_startup_read_anr_ind->access_id = control_block->ID;
            l4cphb_startup_read_anr_ind->anr_entry[0].record_index =
                ((phb_entry_struct*) control_block->data)->record_index;
            l4cphb_startup_read_anr_ind->anr_entry[0].adn_record_index =
                ((phb_entry_struct*) control_block->data)->record_index;
            l4cphb_startup_read_anr_ind->anr_entry[0].anr_type = 0;
            l4cphb_startup_read_anr_ind->num_of_entry = 1;
            phb_send_ilm(
                MOD_L4C,
                MSG_ID_L4CPHB_STARTUP_READ_ANR_IND,
                (local_para_struct*) l4cphb_startup_read_anr_ind,
                NULL);
        #endif /* defined(__MMI_FMI__) */ 
            if (control_block->seg_record_index != (kal_uint8) PHB_INVALID_VALUE)
            {
                phb_se_ext_index_set(control_block->record_index, control_block->seg_record_index, PHB_ANRA);
            }
            if (phb_ptr->anra_type == 2)
            {
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_FALSE);
            }
        #if defined(__MMI_FMI__)
            return;
        #endif 
        }
        /* an invalid record */
        else
        {
            if (phb_ptr->anra_type == 2)
            {
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_TRUE);
            }

            /* Reset control_block->data */
            control_block->data = (kal_uint8*) & control_block->temp_entry;
        }
        // TODO: multiple read
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        if (++control_block->actual_count >= control_block->total)      /* remove it after ANR multiple read is implemented */
        {
            (*control_block->controller) (NULL, control_block);
            /* phb_usim_startup_handler(NULL, control_block); */
        }
        else
        {
            ++control_block->record_index;
            next_record_index = phb_get_next_process_index(control_block->record_index, PHB_ANR);
            if (next_record_index == (kal_uint16) PHB_INVALID_VALUE)    /* no other ADN */
            {
                (*control_block->controller) (NULL, control_block);
            }
            else
            {
                control_block->actual_count += (next_record_index - control_block->record_index);
                control_block->record_index = next_record_index;
                phb_issue_IO_read(control_block);
            }
        }
    }
}   /* end of phb_build_anr_index function */


/*****************************************************************************
 * FUNCTION
 *  phb_build_email_index
 * DESCRIPTION
 *  This is build_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_email_index(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 next_record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        next_record_index = phb_get_next_process_index(control_block->record_index, PHB_EMAIL);
        if (next_record_index == (kal_uint16) PHB_INVALID_VALUE)        /* no other ADN */
        {
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            control_block->actual_count += (next_record_index - control_block->record_index);
            control_block->record_index = next_record_index;
            phb_issue_IO_read(control_block);
        }
    }
    else
    {
        /* Building index for email EF */
        phb_email_struct *email_entry = (phb_email_struct*) control_block->data;

        /* For valid record, control_block.data must not NULL */
        if (email_entry != NULL &&
            phb_data_desc_is_free(DATA_DESC_ADN, email_entry->adn_record_index) == RECORD_OCCUPIED)
        {
        #if defined(__MMI_FMI__)
            /* Send out indication for each email entries and wait response to read next. */
            l4cphb_startup_read_email_ind_struct *l4cphb_startup_read_email_ind =
                (l4cphb_startup_read_email_ind_struct*)
                construct_local_para(sizeof(l4cphb_startup_read_email_ind_struct), TD_CTRL);

            memcpy(
                &l4cphb_startup_read_email_ind->email_entry,
                (phb_email_struct*) email_entry,
                sizeof(phb_email_struct));
            l4cphb_startup_read_email_ind->access_id = control_block->ID;
            phb_send_ilm(
                MOD_L4C,
                MSG_ID_L4CPHB_STARTUP_READ_EMAIL_IND,
                (local_para_struct*) l4cphb_startup_read_email_ind,
                NULL);
        #endif /* defined(__MMI_FMI__) */ 
            if (phb_ptr->email_type == 2)
            {
                phb_se_iap_index_set(
                    l4cphb_startup_read_email_ind->email_entry[0].adn_record_index,
                    (kal_uint8)control_block->record_index,
                    DATA_DESC_EMAIL);
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_FALSE);
            }
        #if defined(__MMI_FMI__)
            return;
        #endif 
        }
        /* an invalid record */
        else
        {
            if (phb_ptr->email_type == 2)
            {
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_TRUE);
            }

            /* Reset control_block->data */
            control_block->data = (kal_uint8*) & control_block->temp_email_entry;
        }
    #if 0   // TODO: multiple read
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        if (++control_block->actual_count >= control_block->total)      /* remove it after multiple read is implemented */
        {
            (*control_block->controller) (NULL, control_block);
            /* phb_usim_startup_handler(NULL, control_block); */
        }
        else
        {
            ++control_block->record_index;
            next_record_index = phb_get_next_process_index(control_block->record_index, PHB_EMAIL);
            if (next_record_index == (kal_uint16) PHB_INVALID_VALUE)    /* no other ADN */
            {
                (*control_block->controller) (NULL, control_block);
            }
            else
            {
                control_block->actual_count += (next_record_index - control_block->record_index);
                control_block->record_index = next_record_index;
                phb_issue_IO_read(control_block);
            }
        }
    }
}   /* end of phb_build_index function */


/*****************************************************************************
 * FUNCTION
 *  phb_usim_startup_handler
 * DESCRIPTION
 *  This is startup function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_usim_startup_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP); */
    if ((control_block->proc_stage <= startup_build_ext4_index) && (phb_ptr->data_desc[DATA_DESC_ANRA].is_support))
    {
        control_block->primary_ID = FILE_G_ANR_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_ANRA][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_ANRA][1];
        control_block->secondary_ID = (kal_uint16) FILE_G_EXT1_IDX;
        phb_control_block_set(
            control_block,
            phb_build_anr_index,
            phb_usim_startup_handler,
            phb_startup_err_handler,
            startup_build_anr_index);
        if (phb_ptr->data_desc[DATA_DESC_ANRA].record_num > 0)
        {
            control_block->record_index = 1;
            control_block->data = (void*)&control_block->temp_entry;
            control_block->length = phb_ptr->data_desc[DATA_DESC_ANRA].record_size;
            phb_control_block_set_IO(
                control_block,
                PHB_ANR,
                control_block->record_index,
                phb_ptr->data_desc[DATA_DESC_ANRA].record_num);
            control_block->storage = PHB_SIM;
            phb_build_anr_index(NULL, control_block);
        }
        /* This type of phone book data is not supported by storage. Continue next step */
        else
        {
            phb_usim_startup_handler(NULL, control_block);
        }
    }

    else if ((control_block->proc_stage <= startup_build_anr_index) && (phb_ptr->data_desc[DATA_DESC_EMAIL].is_support))
    {
        control_block->primary_ID = FILE_G_EMAIL_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_EMAIL][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_EMAIL][1];
        control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
        phb_control_block_set(
            control_block,
            phb_build_email_index,
            phb_usim_startup_handler,
            phb_startup_err_handler,
            startup_build_email_index);
        if (phb_ptr->data_desc[DATA_DESC_EMAIL].record_num > 0)
        {
            control_block->record_index = 1;    // TODO: set to the frist ADN record
            control_block->data = (void*)&control_block->temp_email_entry;
            control_block->length = phb_ptr->data_desc[DATA_DESC_EMAIL].record_size;
            phb_control_block_set_IO(
                control_block,
                PHB_EMAIL,
                control_block->record_index,
                phb_ptr->data_desc[DATA_DESC_EMAIL].record_num);
            control_block->storage = PHB_SIM;
            phb_build_email_index(NULL, control_block);
        }
        /* This type of phone book data is not supported by storage. Continue next step */
        else
        {
            phb_usim_startup_handler(NULL, control_block);
        }
    }
#ifdef __MMI_FMI__
    /* USIM GAS */
    else if ((control_block->proc_stage <= startup_build_email_index) && (phb_ptr->data_desc[DATA_DESC_GAS].is_support))
    {
        control_block->primary_ID = FILE_G_GAS_IDX;
        control_block->secondary_ID = FILE_NONE;
        phb_control_block_set(
            control_block,
            phb_build_gas_index,
            phb_usim_startup_handler,
            phb_startup_err_handler,
            startup_build_gas_index);
        if (phb_ptr->data_desc[DATA_DESC_GAS].record_num > 0)
        {
            control_block->record_index = 1;
            control_block->data = (void*)&control_block->temp_entry;
            control_block->length = phb_ptr->data_desc[DATA_DESC_GAS].record_size;
            phb_control_block_set_IO(control_block, PHB_GAS, 1, phb_ptr->data_desc[DATA_DESC_GAS].record_num);
            control_block->storage = PHB_SIM;
            phb_build_gas_index(NULL, control_block);
        }
        /* This type of phone book data is not supported by storage. Continue next step */
        else
        {
            phb_usim_startup_handler(NULL, control_block);
        }
    }
    /* USIM GRP */
    else if ((control_block->proc_stage <= startup_build_gas_index) && (phb_ptr->data_desc[DATA_DESC_GRP].is_support))
    {
        control_block->primary_ID = FILE_G_GRP_IDX;
        control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
        phb_control_block_set(
            control_block,
            phb_build_grp_index,
            phb_usim_startup_handler,
            phb_startup_err_handler,
            startup_build_grp_index);
        if (phb_ptr->data_desc[DATA_DESC_GRP].record_num > 0)
        {
            control_block->record_index = 1;
            control_block->data = (void*)&control_block->temp_entry;
            control_block->length = phb_ptr->data_desc[DATA_DESC_GRP].record_size;
            phb_control_block_set_IO(control_block, PHB_GRP, 1, phb_ptr->data_desc[DATA_DESC_GRP].record_num);
            control_block->storage = PHB_SIM;
            phb_build_grp_index(NULL, control_block);
        }
        /* This type of phone book data is not supported by storage. Continue next step */
        else
        {
            phb_usim_startup_handler(NULL, control_block);
        }
    }
#endif /* __MMI_FMI__ */ 
    else if (control_block->proc_stage <= startup_build_grp_index)
    {
        /* Build all indices */
        phb_se_finish_build();

        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);

        phb_ptr->state = PHB_STATE_READY;
        kal_trace(TRACE_STATE, STATE_PHB_READY);
        phb_startup_confirm(PHB_ERRNO_SUCCESS, control_block);
    }
}   /* end of phb_usim_startup_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_startup_phase1_indicator
 * DESCRIPTION
 *  This is phb_startup_phase1_indicator function of PHB module.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_phase1_indicator(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_startup_phase1_ind_struct *l4cphb_startup_phase1_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_CNF, result); */

    l4cphb_startup_phase1_ind =
        (l4cphb_startup_phase1_ind_struct*) construct_local_para(sizeof(l4cphb_startup_phase1_ind_struct), TD_CTRL);
    l4cphb_startup_phase1_ind->result = PHB_ERRNO_SUCCESS;

    l4cphb_startup_phase1_ind->adn_size = phb_ptr->adn_size;
    l4cphb_startup_phase1_ind->phb_size = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
    l4cphb_startup_phase1_ind->adn_alpha_length = phb_ptr->adn_alpha_length;
    l4cphb_startup_phase1_ind->fdn_alpha_length = phb_ptr->fdn_alpha_length;
    l4cphb_startup_phase1_ind->bdn_alpha_length = phb_ptr->bdn_alpha_length;
    l4cphb_startup_phase1_ind->msisdn_alpha_length = phb_ptr->msisdn_alpha_length;

    l4cphb_startup_phase1_ind->is_usim = KAL_TRUE;
    l4cphb_startup_phase1_ind->is_group_support = phb_ptr->data_desc[DATA_DESC_GRP].is_support;
    l4cphb_startup_phase1_ind->anra_support_type = phb_ptr->anra_type;
    l4cphb_startup_phase1_ind->anrb_support_type = phb_ptr->anrb_type;
    l4cphb_startup_phase1_ind->anrc_support_type = phb_ptr->anrc_type;
    l4cphb_startup_phase1_ind->sne_support_type = phb_ptr->sne_type;
    l4cphb_startup_phase1_ind->email_support_type = phb_ptr->email_type;
    l4cphb_startup_phase1_ind->group_alpha_length = phb_ptr->group_alpha_length;
    l4cphb_startup_phase1_ind->gas_size = phb_ptr->data_desc[DATA_DESC_GAS].record_size;
    l4cphb_startup_phase1_ind->sne_alpha_length = phb_ptr->sne_alpha_length;
    l4cphb_startup_phase1_ind->email_length = phb_ptr->email_length;
    l4cphb_startup_phase1_ind->anra_size = phb_ptr->data_desc[DATA_DESC_ANRA].record_size;
    l4cphb_startup_phase1_ind->anrb_size = phb_ptr->data_desc[DATA_DESC_ANRB].record_size;
    l4cphb_startup_phase1_ind->anrc_size = phb_ptr->data_desc[DATA_DESC_ANRC].record_size;
    l4cphb_startup_phase1_ind->sne_size = phb_ptr->data_desc[DATA_DESC_SNE].record_size;
    l4cphb_startup_phase1_ind->email_size = phb_ptr->data_desc[DATA_DESC_EMAIL].record_size;

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_PHASE1_IND, (local_para_struct*) l4cphb_startup_phase1_ind, NULL);
}   /* end of phb_startup_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_build_index_continue
 * DESCRIPTION
 *  Send out indication for each record for USIM entries.
 *  and wait response to read next. Only turn on when LMMI exists.
 * PARAMETERS
 *  control_block       [IN]        Current control block
 * RETURNS
 *  void
 *****************************************************************************/
void phb_build_index_continue(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must be in those stage. */
    ASSERT((control_block->proc_stage >= startup_build_ext4_index) &&
           (control_block->proc_stage <= startup_build_index_finish))
        if (++control_block->actual_count >= control_block->total)
    {
        (*control_block->controller) (NULL, control_block);
    }
    else if (control_block->proc_stage == startup_build_anr_index ||
             control_block->proc_stage == startup_build_email_index)
    {
        kal_uint16 next_record_index;

        ++control_block->record_index;
        next_record_index = phb_get_next_process_index(control_block->record_index, control_block->type);
        control_block->actual_count += (next_record_index - control_block->record_index);
        if (next_record_index == (kal_uint16) PHB_INVALID_VALUE)        /* no other ADN */
        {
            phb_usim_startup_handler(NULL, control_block);
        }
        else
        {
            control_block->actual_count += (next_record_index - control_block->record_index);
            control_block->record_index = next_record_index;
            phb_issue_IO_read(control_block);
        }
    }
    else
    {
        ++control_block->record_index;
        phb_issue_IO_read(control_block);
    }
}

#if defined(__MMI_FMI__)


/*****************************************************************************
 * FUNCTION
 *  phb_build_gas_index
 * DESCRIPTION
 *  This is build_gas_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_gas_index(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    else
    {
        /* Building GAS */
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        /* For valid record, control_block.data must not NULL */
        if (phb_entry != NULL)
        {
            /*
             *  Send out indication for each record for GAS entries.
             *  and wait response to read next.
             */
            l4cphb_startup_read_gas_ind_struct *l4cphb_startup_read_ind =
                (l4cphb_startup_read_gas_ind_struct*) construct_local_para(
                                                        sizeof(l4cphb_startup_read_gas_ind_struct),
                                                        TD_CTRL);

            memcpy(
                &l4cphb_startup_read_ind->gas_entry,
                (phb_entry_struct*) control_block->data,
                sizeof(phb_entry_struct));
            l4cphb_startup_read_ind->access_id = control_block->ID;
            l4cphb_startup_read_ind->num_of_entry = 1;  /* ADN doesn't have multiple read */
            phb_send_ilm(
                MOD_L4C,
                MSG_ID_L4CPHB_STARTUP_READ_GAS_IND,
                (local_para_struct*) l4cphb_startup_read_ind,
                NULL);
            /*
             *   Wait for MMI response to continue to read next entry.
             *   So does not read next entry until MMI confirm.
             */
            return;
        }
        /* an invalid record */
        else
        {
            /* Reset control_block->data */
            control_block->data = (kal_uint8*) & control_block->temp_entry;
        }

        if (++control_block->actual_count >= control_block->total)
        {
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            ++control_block->record_index;
            phb_issue_IO_read(control_block);
        }
    }
}   /* end of phb_build_index function */


/*****************************************************************************
 * FUNCTION
 *  phb_build_grp_index
 * DESCRIPTION
 *  This is build_grp_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_grp_index(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }

    else
    {
        control_block->group_id[control_block->record_index - 1] = control_block->data[0];
        /* Send ind after read all grp */
        if (++control_block->actual_count >= control_block->total)
        {
            /* Send out indication for each record for GRP entries. */
            l4cphb_startup_read_grp_ind_struct *l4cphb_startup_read_ind =
                (l4cphb_startup_read_grp_ind_struct*) construct_local_para(
                                                        sizeof(l4cphb_startup_read_grp_ind_struct),
                                                        TD_CTRL);

            memcpy(&l4cphb_startup_read_ind->grp, control_block->group_id, ADN_INDEX_MAX_ENTRIES_COUNT);        /* MAX_PHB_SIM_ENTRY */
            l4cphb_startup_read_ind->access_id = control_block->ID;
            phb_send_ilm(
                MOD_L4C,
                MSG_ID_L4CPHB_STARTUP_READ_GRP_IND,
                (local_para_struct*) l4cphb_startup_read_ind,
                NULL);
            /* Wait for MMI response to continue to read next EF. */
            return;
        }
        else
        {
            ++control_block->record_index;
            phb_issue_IO_read(control_block);
        }
    }
}   /* end of phb_build_index function */
#endif /* defined(__MMI_FMI__) */ 
#endif /* __PHB_USIM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_startup_handler
 * DESCRIPTION
 *  This is startup function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP);

    if (ilm_ptr != NULL)
    {
        if (phb_ptr->state == PHB_STATE_NOT_READY)
        {
            kal_uint16 phb_total, phb_size;
            l4cphb_startup_req_struct *l4cphb_startup_req;
            l4cphb_startup_req = (l4cphb_startup_req_struct*) ilm_ptr->local_para_ptr;

         /**
          * Since startup is an implicit reset, there 2 ways to implement this:
          *
          * 1. Forbidden other operations to PHB except approve and search:
          *   In this implementation,
          *   startup handler should always uses the first control_block,
          *   and lock all control_blocks are locked temporarily;
          *   thus prevent other operations, except approve and search,
          *   from accessing PHB while it is busy.
          *
          * 2. Allow all other operations to provide maximum possible
          *   concurrency degrees.
          *
          * Curretly, solution 1 is implemented.
          * Control_blocks are all locked to interrupt all other in-processing
          * operations and reject all further requests, to prevent
          * multiple access to PHB when it is not ready.
          *
          * However, FDN is required to be approved even when PHB
          * is not ready. That means a control_block is required to
          * approve an FDN, even during startup procedure, which locks
          * all control_blocks. To solve this problem, solution 1 cannot
          * be adopted directly. The modified solution is:
          *
          * 1. Reset all control block which stops all current actions.
          * 2. Allocate one control block for startup procedure, and
          *   allows FDN approval only. All other request will be
          *   rejected even a free control block is found, since
          *   PHB state is not ready.
          */

            control_block = phb_alloc_control_block();
            ASSERT(control_block != NULL);

            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;

            phb_ptr->dn_type = l4cphb_startup_req->dn_type;

            kal_trace(TRACE_INFO, INFO_PHB_STARTUP_MODE, phb_ptr->dn_type);

            /* Send begin indication to MMI, MMI will clear it's variable and reload phonebook. */
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_BEGIN_IND, NULL, NULL);

        #ifdef __GEMINI__
            if (phb_current_mod == MOD_PHB_2)
            {
                phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
            }
            else if (phb_current_mod == MOD_PHB)
        #endif /* __GEMINI__ */
            {
                if (nvram_get_info(NVRAM_EF_PHB_LID, &phb_total, &phb_size) == NVRAM_ERRNO_SUCCESS)
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_TRUE);

                /*
                 * MAX_ENTRIES_COUNT must NOT be exceeded. See comment
                 * of phb_get_info_set_value() for detail.
                 */
                    if (phb_total > NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT)
                    {
                        phb_total = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
                    }
                    phb_data_desc_set(DATA_DESC_PHB, phb_total, phb_size);
                }
                else
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
                }
            }
            phb_data_desc_set_is_support(
                DATA_DESC_ADN,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_ADN, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */
                (kal_bool) ((sim_service_table_query(SERVICE_ADN) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_FDN,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_FDN, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */            
                (kal_bool) ((sim_service_table_query(SERVICE_FDN) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_BDN,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_BDN, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_BDN) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_MSISDN,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_MSISDN, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_MSISDN) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_SDN,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_SDN, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_SDN) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_EXT1,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_EXT1, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_EXT1) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_EXT2,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_EXT2, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_EXT2) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */

            phb_data_desc_set_is_support(
                DATA_DESC_EXT3,
            #ifdef __GEMINI__
                (kal_bool) ((sim_service_table_query(SERVICE_EXT3, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #else /* __GEMINI__ */                
                (kal_bool) ((sim_service_table_query(SERVICE_EXT3) == SERVICE_SUPPORT) ? KAL_TRUE : KAL_FALSE));
            #endif /* __GEMINI__ */            

            control_block->proc_stage = startup_info_size_nvram;
            phb_get_info(ilm_ptr, control_block);
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);
            return;
        }
    }
    else
    {
        kal_trace(TRACE_INFO, INFO_PHB_FILE_INFO_GOT);
        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BEGIN);

        /* SIM ECC */
        if (control_block->proc_stage == startup_info_compare_digit)
        {
        #ifdef __USIM_SUPPORT__
            if (is_usim_type())
            {
                phb_ptr->ecc.num_ecc = 0;
                control_block->primary_ID = FILE_U_ECC_IDX;
            }
            else
        #endif /* __USIM_SUPPORT__ */ 
                control_block->primary_ID = FILE_ECC_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            phb_control_block_set(
                control_block,
                phb_read_ecc,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_ecc_index);
        #ifdef __USIM_SUPPORT__
            if (is_usim_type() && phb_ptr->data_desc[DATA_DESC_ECC].record_num)
            {
                /* USIM ECC is linear fixed */
                control_block->record_index = 1;
                control_block->length = phb_ptr->data_desc[DATA_DESC_ECC].record_size;
                phb_control_block_set_IO(control_block, PHB_ECC, 1, phb_ptr->data_desc[DATA_DESC_ECC].record_num);
                control_block->storage = PHB_SIM;
                phb_read_ecc(NULL, control_block);
            }
            else if (!is_usim_type() && phb_ptr->ecc.num_ecc > 0)
        #else
            if (phb_ptr->ecc.num_ecc > 0)
        #endif /* __USIM_SUPPORT__ */ 
            {
            /**
             * SIM ECC is transparent,
             * hence index(para of SIM_READ_REQ means offset) must be 0
             */
                control_block->record_index = 0;
                control_block->length = phb_ptr->ecc.num_ecc;
                phb_control_block_set_IO(control_block, PHB_ECC, 0, 1);
                control_block->storage = PHB_SIM;
                phb_read_ecc(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM FDN */
      /**
       * Handling of FDN is a special case.
       * In current implementation,once reading a record of an EF failed,
       * PHB stops reading that EF and continues next step immediately.
       *
       * However, even when PHB is not ready, approval FDN should be
       * available as soon as FDN is scanned. Consider error reading FDN
       * records, building index and state transition for FDN is needed either
       * successful case (in phb_build_index())
       * or reading fail case (in phb_startup_err_handler()).
       */
        else if ((control_block->proc_stage <= startup_build_ecc_index) &&
                 (phb_ptr->data_desc[DATA_DESC_FDN].is_support))
        {
         /**
          * Once FDN index building finished, state will be transit to FDN_READY.
          * Note that PHB is not ready at this moment
          */
            control_block->primary_ID = FILE_FDN_IDX;
            control_block->secondary_ID = FILE_EXT2_IDX;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_fdn_index);
            if (phb_ptr->data_desc[DATA_DESC_FDN].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_FDN].record_size;
                phb_control_block_set_IO(control_block, PHB_FDN, 1, phb_ptr->data_desc[DATA_DESC_FDN].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        else if ((control_block->proc_stage <= startup_build_fdn_index) &&
                 (phb_ptr->data_desc[DATA_DESC_PHB].is_support))
        {
            control_block->primary_ID = NVRAM_EF_PHB_LID;
            control_block->secondary_ID = PHB_NULL_VALUE;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_phb_index);
            if (phb_ptr->data_desc[DATA_DESC_PHB].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_data_desc_get_record_size(DATA_DESC_PHB);
                phb_control_block_set_IO(control_block, PHB_PHONEBOOK, 1, phb_ptr->data_desc[DATA_DESC_PHB].record_num);
                control_block->storage = PHB_NVRAM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM ADN */
        else if ((control_block->proc_stage <= startup_build_phb_index) &&
                 (phb_ptr->data_desc[DATA_DESC_ADN].is_support))
        {
        #ifdef __USIM_SUPPORT__
            if (is_usim_type())
            {
                control_block->primary_ID = FILE_G_ADN_IDX;
                kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                control_block->path[4] = phb_ptr->path[DATA_DESC_ADN][0];
                control_block->path[5] = phb_ptr->path[DATA_DESC_ADN][1];
                control_block->secondary_ID = FILE_G_EXT1_IDX;
            }
            else
        #endif /* __USIM_SUPPORT__ */ 
            {
                control_block->primary_ID = FILE_ADN_IDX;
                control_block->secondary_ID = FILE_EXT1_IDX;
            }
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_adn_index);
            if (phb_ptr->data_desc[DATA_DESC_ADN].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_ADN].record_size;
                phb_control_block_set_IO(control_block, PHB_PHONEBOOK, 1, phb_ptr->data_desc[DATA_DESC_ADN].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM BDN */
        else if ((control_block->proc_stage <= startup_build_adn_index) &&
                 (phb_ptr->data_desc[DATA_DESC_BDN].is_support))
        {
            control_block->primary_ID = FILE_BDN_IDX;
            control_block->secondary_ID = FILE_EXT3_IDX;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_bdn_index);
            if (phb_ptr->data_desc[DATA_DESC_BDN].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_BDN].record_size;
                phb_control_block_set_IO(control_block, PHB_BDN, 1, phb_ptr->data_desc[DATA_DESC_BDN].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM MSISDN */
        else if ((control_block->proc_stage <= startup_build_bdn_index) &&
                 (phb_ptr->data_desc[DATA_DESC_MSISDN].is_support))
        {
            control_block->primary_ID = FILE_MSISDN_IDX;
            control_block->secondary_ID = FILE_EXT1_IDX;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_msisdn_index);
            if (phb_ptr->data_desc[DATA_DESC_MSISDN].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_MSISDN].record_size;
                phb_control_block_set_IO(control_block, PHB_MSISDN, 1, phb_ptr->data_desc[DATA_DESC_MSISDN].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }
        /* SIM EXT1 */
        else if ((control_block->proc_stage <= startup_build_msisdn_index) &&
                 (phb_ptr->data_desc[DATA_DESC_EXT1].is_support))
        {
        #ifdef __USIM_SUPPORT__
            if (is_usim_type())
            {
                control_block->primary_ID = FILE_G_EXT1_IDX;
                kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                control_block->path[4] = phb_ptr->path[DATA_DESC_EXT1][0];
                control_block->path[5] = phb_ptr->path[DATA_DESC_EXT1][1];
            }
            else
        #endif /* __USIM_SUPPORT__ */ 
                control_block->primary_ID = FILE_EXT1_IDX;
            control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_ext1_index);
            if (phb_ptr->data_desc[DATA_DESC_EXT1].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_EXT1].record_size;
                phb_control_block_set_IO(
                    control_block,
                    PHB_SDN,    /* ignored */
                    1,
                    phb_ptr->data_desc[DATA_DESC_EXT1].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM EXT2 */
        else if ((control_block->proc_stage <= startup_build_ext1_index) &&
                 (phb_ptr->data_desc[DATA_DESC_EXT2].is_support))
        {
            control_block->primary_ID = FILE_EXT2_IDX;
            control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_ext2_index);
            if (phb_ptr->data_desc[DATA_DESC_EXT2].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_EXT2].record_size;
                phb_control_block_set_IO(
                    control_block,
                    PHB_SDN,    /* ignored */
                    1,
                    phb_ptr->data_desc[DATA_DESC_EXT2].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* SIM EXT4 */
        else if ((control_block->proc_stage <= startup_build_ext2_index) &&
                 (phb_ptr->data_desc[DATA_DESC_EXT4].is_support))
        {
            control_block->primary_ID = FILE_EXT4_IDX;
            control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
            phb_control_block_set(
                control_block,
                phb_build_index,
                phb_startup_handler,
                phb_startup_err_handler,
                startup_build_ext4_index);
            if (phb_ptr->data_desc[DATA_DESC_EXT4].record_num > 0)
            {
                control_block->record_index = 1;
                control_block->data = (void*)&control_block->temp_entry;
                control_block->length = phb_ptr->data_desc[DATA_DESC_EXT4].record_size;
                phb_control_block_set_IO(
                    control_block,
                    PHB_SDN,    /* ignored */
                    1,
                    phb_ptr->data_desc[DATA_DESC_EXT4].record_num);
                control_block->storage = PHB_SIM;
                phb_build_index(NULL, control_block);
            }
            /* This type of phone book data is not supported by storage. Continue next step */
            else
            {
                phb_startup_handler(NULL, control_block);
            }
        }

        /* finished...... */
        else if (control_block->proc_stage <= startup_build_ext4_index)
        {
        #ifdef __PHB_USIM_SUPPORT__
            if (is_usim_type())
            {
                phb_startup_phase1_indicator(control_block);
                phb_usim_startup_handler(NULL, control_block);
            }
            else
        #endif /* __PHB_USIM_SUPPORT__ */ 
            {
                /* Build all indices */
                phb_se_finish_build();

                kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);
                phb_ptr->state = PHB_STATE_READY;
                kal_trace(TRACE_STATE, STATE_PHB_READY);
                phb_startup_confirm(PHB_ERRNO_SUCCESS, control_block);
            }
        }
    }
}   /* end of phb_startup_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_startup_err_handler
 * DESCRIPTION
 *  This is startup error handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __USIM_SUPPORT__
    kal_uint16 i;
#endif/* def __USIM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_ERR);

    /* Bypass error, and continue next step */
    control_block->IO_stage = IO_NONE;

    if ((ilm_ptr != NULL) && (control_block != NULL))
    {
        /* A FDN record read failed */
        if (control_block->proc_stage == startup_build_fdn_index)
        {
            phb_name_num_index_sort(&phb_ptr->indices.fdn_index);
            phb_ptr->state = PHB_STATE_NOT_READY_FDN_READY;
        }
    #ifdef __USIM_SUPPORT__
        if (control_block->proc_stage == startup_info_pbr_contents)
        {
            for (i = 0; i < DATA_DESC_PBR; i++)
            phb_ptr->data_desc[i].is_support = KAL_FALSE;
        }
    #endif
        if (control_block->proc_stage <= startup_info_ext4_record_num)
        {
            (*control_block->controller) (ilm_ptr, control_block);
        }
        else
        {
            (*control_block->controller) (NULL, control_block);
        }
    }
}   /* end of phb_startup_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_prepare_phb_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 *  pdu_ptr             [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_prepare_phb_entry(control_block_type *control_block, kal_uint8 *pdu_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 alpha_id_length = phb_data_desc_get_record_size(DATA_DESC_PHB) - NVRAM_PHB_LENGTH_AFTER_ALPHA_ID;
    phb_nvram_ef_struct phb_nvram_ef;
    phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(control_block != NULL);

    /* Now unpack the data read from peer buffer */
    phb_entry = (phb_entry_struct*) control_block->data;

    phb_nvram_ef.alpha_id = pdu_ptr;
    phb_nvram_ef.mandatory = (phb_nvram_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

    /* Clean area for storing data read from storage. */
    kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

    phb_entry->index = control_block->index;
    phb_entry->record_index = control_block->record_index;
    phb_entry->storage = PHB_NVRAM;
    /* amanda add */
    phb_entry->type = PHB_PHONEBOOK;

    if (!is_empty(pdu_ptr, control_block->length))
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
}


/*****************************************************************************
 * FUNCTION
 *  phb_build_index
 * DESCRIPTION
 *  This is build_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_index(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_read(control_block);
    }
    else
    {
        /* Building index for EF's, except ECC */
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        if (control_block->proc_stage == startup_build_phb_index)       /* multiple nvram records */
        {
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            kal_uint16 i;

        #if defined(__MMI_FMI__)
            kal_uint8 count = 0;

            /*
             * MTK Jo: Send out indication for multiple record of NVRAM entries.
             *  and wait response to read next block.
             */
            l4cphb_startup_read_ind_struct *l4cphb_startup_read_ind;
        #endif /* defined(__MMI_FMI__) */ 

            /* Get the Pointer to the Message from the Peer Buffer Ptr */
            pdu_ptr = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);
            control_block->total = pdu_length / control_block->length;

            if (is_empty(pdu_ptr, pdu_length))  /* check all record first */
            {
                kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                phb_entry->tel_number.addr_length = 0;
                control_block->actual_count += control_block->total;
                control_block->total_piggyback = control_block->total;
                for (i = 0; i < control_block->total; i++)
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                        control_block->record_index,
                        KAL_TRUE);
                    control_block->record_index++;
                }
                /* Reset control_block->data */
                control_block->data = (kal_uint8*) & control_block->temp_entry;
                phb_build_index_continue_adn(control_block);
                return;
            }
        #if defined(__MMI_FMI__)
            l4cphb_startup_read_ind =
                (l4cphb_startup_read_ind_struct*) construct_local_para(
                                                    sizeof(l4cphb_startup_read_ind_struct),
                                                    TD_CTRL);
        #endif /* defined(__MMI_FMI__) */ 
            for (i = 0; i < control_block->total; i++)
            {
                if (i != 0)
                {
                    pdu_ptr += control_block->length;
                }
                phb_prepare_phb_entry(control_block, pdu_ptr);

                if ((phb_entry != NULL) &&
                    ((phb_entry->alpha_id.name_length != 0) || (phb_entry->tel_number.addr_length != 0)))
                {
                #if defined(__MMI_FMI__)
                    memcpy(
                        &l4cphb_startup_read_ind->phb_entry[count],
                        (phb_entry_struct*) control_block->data,
                        sizeof(phb_entry_struct));
                    count++;
                #endif /* defined(__MMI_FMI__) */ 
                    phb_se_build_index(
                        PHB_PHONEBOOK,
                        control_block->record_index,
                        control_block->seg_record_index,
                        (phb_entry_struct*) control_block->data);
                }
                /* an invalid record */
                else
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                        control_block->record_index,
                        KAL_TRUE);
                    /* Reset control_block->data */
                    control_block->data = (kal_uint8*) & control_block->temp_entry;
                }
                control_block->actual_count++;
                control_block->total_piggyback++;
                control_block->record_index++;
            }
        #if defined(__MMI_FMI__)
            l4cphb_startup_read_ind->access_id = control_block->ID;
            l4cphb_startup_read_ind->num_of_entry = count;
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_READ_IND, (local_para_struct*) l4cphb_startup_read_ind, NULL);
            /*
             *  Jo: Wait for MMI response to continue to read next multiple entry.
             *  Do not read next block until MMI confirm.
             */
            return;
        #endif /* defined(__MMI_FMI__) */ 
        }

        /* For valid record, control_block.data must not NULL */
        else if (phb_entry != NULL)
        {
            if ((!(control_block->primary_ID == FILE_EXT1_IDX && control_block-> storage == PHB_SIM)) &&
        #ifdef __USIM_SUPPORT__
                (!(control_block->primary_ID == FILE_G_EXT1_IDX && control_block-> storage == PHB_SIM)) &&
        #endif 
                (!(control_block->primary_ID == FILE_EXT2_IDX && control_block-> storage == PHB_SIM)) &&
                (!(control_block->primary_ID == FILE_EXT3_IDX && control_block-> storage == PHB_SIM)) &&
                (!(control_block->primary_ID == FILE_EXT4_IDX && control_block-> storage == PHB_SIM)) &&
                ((phb_entry->alpha_id.name_length != 0) || (phb_entry->tel_number.addr_length != 0)))
            {
                if (control_block->proc_stage == startup_build_adn_index)
                {
                #if defined(__MMI_FMI__)
                    /*
                     *  Send out indication for each record for ADN and NVRAM entries.
                     *  and wait response to read next.
                     */
                    l4cphb_startup_read_ind_struct *l4cphb_startup_read_ind =
                        (l4cphb_startup_read_ind_struct*) construct_local_para(
                                                            sizeof(l4cphb_startup_read_ind_struct),
                                                            TD_CTRL);

                    memcpy(
                        &l4cphb_startup_read_ind->phb_entry,
                        (phb_entry_struct*) control_block->data,
                        sizeof(phb_entry_struct));
                    l4cphb_startup_read_ind->access_id = control_block->ID;
                    l4cphb_startup_read_ind->num_of_entry = 1;  /* ADN doesn't have multiple read */
                    phb_send_ilm(
                        MOD_L4C,
                        MSG_ID_L4CPHB_STARTUP_READ_IND,
                        (local_para_struct*) l4cphb_startup_read_ind,
                        NULL);
                #endif /* defined(__MMI_FMI__) */ 

                    phb_se_build_index(
                        PHB_PHONEBOOK,
                        control_block->record_index,
                        control_block->seg_record_index,
                        (phb_entry_struct*) control_block->data);

                    /*
                     *   If it a ADN record, wait for MMI response to continue to read next entry.
                     *   So does not read next entry until MMI confirm.
                     *   As for other record( BDN, FDN...), it remains the old way to read next entry.
                     */
                #if defined(__MMI_FMI__)
                    return;
                #endif 
                }
                else if (control_block->proc_stage == startup_build_fdn_index)
                {
                    phb_se_build_index(
                        PHB_FDN,
                        control_block->record_index,
                        control_block->seg_record_index,
                        (phb_entry_struct*) control_block->data);
                }
                else if (control_block->proc_stage == startup_build_bdn_index)
                {
                    phb_se_build_index(
                        PHB_BDN,
                        control_block->record_index,
                        control_block->seg_record_index,
                        (phb_entry_struct*) control_block->data);
                }

                /* MSISDN and SDN use 1 to 1 mapping, no index is built. */
                else if (control_block->proc_stage == startup_build_msisdn_index)
                {
                }

            /**
             * Skip records read from EXT1 ~ EXT4;
             * these are just scanned for building free-list;
             * no index should be built anyway.
             */

                else if ((control_block->proc_stage != startup_build_ext1_index) ||
                         (control_block->proc_stage != startup_build_ext2_index) ||
                         (control_block->proc_stage != startup_build_ext4_index))
                {
                    (*control_block->controller) (NULL, control_block);
                    return;
                }
            }
        }
        /* an invalid record */
        else
        {
            if ((!(control_block->primary_ID == FILE_EXT1_IDX && control_block-> storage == PHB_SIM)) &&
        #ifdef __USIM_SUPPORT__
                (!(control_block->primary_ID == FILE_G_EXT1_IDX && control_block-> storage == PHB_SIM)) &&
        #endif 
                (!(control_block->primary_ID == FILE_EXT2_IDX && control_block-> storage == PHB_SIM)) && 
                (!(control_block->primary_ID == FILE_EXT4_IDX && control_block-> storage == PHB_SIM)))
            {
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                    control_block->record_index,
                    KAL_TRUE);
            }

            /* Reset control_block->data */
            control_block->data = (kal_uint8*) & control_block->temp_entry;
        }

        if (control_block->primary_ID == NVRAM_EF_PHB_LID && control_block->storage == PHB_NVRAM)
        {
            phb_build_index_continue_adn(control_block);
        }
        else if (++control_block->actual_count >= control_block->total)
        {
            /* All FDN records successfully read */
            if (control_block->proc_stage == startup_build_fdn_index)
            {
                phb_name_num_index_sort(&phb_ptr->indices.fdn_index);
                phb_ptr->state = PHB_STATE_NOT_READY_FDN_READY;
            }
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            ++control_block->record_index;
            phb_issue_IO_read(control_block);
        }
    }
}   /* end of phb_build_index function */


/*****************************************************************************
 * FUNCTION
 *  phb_build_index_continue_adn
 * DESCRIPTION
 *  Send out indication for each record for ADN and NVRAM entries.
 *  and wait response to read next. Only turn on when LMMI exists.
 * PARAMETERS
 *  control_block       [IN]        Current control block
 * RETURNS
 *  void
 *****************************************************************************/
void phb_build_index_continue_adn(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must be an ADN record. */
    ASSERT((control_block->proc_stage == startup_build_phb_index) ||
           (control_block->proc_stage = startup_build_adn_index))
        if (control_block->proc_stage == startup_build_phb_index)
    {
        /* control_block->actual_count has already increased in phb_build_index function */
        if (control_block->actual_count >= phb_data_desc_get_record_num(DATA_DESC_PHB))
        {
            (*control_block->controller) (NULL, control_block);
        }
        else
        {
            phb_issue_IO_read(control_block);
        }
        return;
    }

    if (++control_block->actual_count >= control_block->total)
    {
        (*control_block->controller) (NULL, control_block);
    }
    else
    {
        ++control_block->record_index;
        phb_issue_IO_read(control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_startup_confirm
 * DESCRIPTION
 *  This is phb_startup_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_confirm(phb_errno_enum result, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_startup_cnf_struct *l4cphb_startup_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_CNF, result);

    l4cphb_startup_cnf = (l4cphb_startup_cnf_struct*) construct_local_para(sizeof(l4cphb_startup_cnf_struct), TD_CTRL);
    l4cphb_startup_cnf->result = result;

    l4cphb_startup_cnf->adn_size = phb_ptr->adn_size;
    l4cphb_startup_cnf->phb_size = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
    l4cphb_startup_cnf->adn_alpha_length = phb_ptr->adn_alpha_length;
    l4cphb_startup_cnf->fdn_alpha_length = phb_ptr->fdn_alpha_length;
    l4cphb_startup_cnf->bdn_alpha_length = phb_ptr->bdn_alpha_length;
    l4cphb_startup_cnf->msisdn_alpha_length = phb_ptr->msisdn_alpha_length;
    l4cphb_startup_cnf->is_sim_refresh = 0;

#ifdef __PHB_USIM_SUPPORT__
    if (is_usim_type())
    {
        /* phb_ptr->state = PHB_STATE_READY; //already set after finish to read grp */
    }
    else
    {
        phb_ptr->state = PHB_STATE_READY;
        kal_trace(TRACE_STATE, STATE_PHB_READY);
    }
#endif /* __PHB_USIM_SUPPORT__ */ 

    if ((result == PHB_ERRNO_BUSY) || (control_block->cnf_msg_id == MSG_ID_L4CPHB_STARTUP_REQ))
    {
        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
            return;
        }
        phb_free_control_block(control_block);
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
        return;
    }
    else
    {
    #ifdef __SAT__
        if (control_block->cnf_msg_id == MSG_ID_SAT_FILE_CHANGE_IND)
        {
            l4cphb_startup_cnf->is_sim_refresh = 1; /* SIM refresh */
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
            phb_sat_file_change_confirm(result, control_block->src_id, control_block);
            return;
        }
    #endif /* __SAT__ */ 
        /* Abnormal! */
        kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
    }
}   /* end of phb_startup_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_get_info
 * DESCRIPTION
 *  This is get_info function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_get_info(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, INFO_PHB_FILE_INFO_BEGIN);

    /* Get file size of ECC */
    if (control_block->proc_stage == startup_info_size_nvram)
    {
        control_block->secondary_ID = PHB_NULL_VALUE;
        control_block->storage = PHB_SIM;
    #ifdef __USIM_SUPPORT__
        if (is_usim_type())
        {
            control_block->primary_ID = FILE_U_ECC_IDX;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_ecc_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else
    #endif /* __USIM_SUPPORT__ */ 
        {
            control_block->primary_ID = FILE_ECC_IDX;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_ecc_file_size);
            phb_sim_file_info(control_block, SIM_FILE_SIZE);
        }
    }
#ifdef __USIM_SUPPORT__
    else if (control_block->proc_stage <= startup_info_ecc_record_num)
    {
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_ecc_record_size);
        phb_sim_file_info(control_block, SIM_REC_SIZE);
    }
    else if (control_block->proc_stage <= startup_info_pbr_record_num)
    {
        if (control_block->proc_stage <= startup_info_ecc_record_size)
        {
            control_block->primary_ID = FILE_G_PBR_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_pbr_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_pbr_record_num)
        {
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_pbr_record_size);
            phb_sim_file_info(control_block, SIM_REC_SIZE);
        }
    }
    /* USIM PBR */
    else if ((control_block->proc_stage <= startup_info_pbr_record_size) && is_usim_type())
    {
        control_block->primary_ID = FILE_G_PBR_IDX; /* or FILE_U_PBR_IDX */
        control_block->secondary_ID = FILE_NONE;
        phb_control_block_set(
            control_block,
            phb_read_pbr,
            phb_get_info,
            phb_startup_err_handler,
            startup_info_pbr_contents);
        if (phb_ptr->data_desc[DATA_DESC_PBR].record_num > 0)
        {
            control_block->record_index = 1;
            control_block->length = phb_ptr->data_desc[DATA_DESC_PBR].record_size;
            phb_control_block_set_IO(control_block, PHB_NONE, 1, phb_ptr->data_desc[DATA_DESC_PBR].record_num);
            control_block->storage = PHB_SIM;
            phb_read_pbr(NULL, control_block);
        }
        /* This type of phone book data is not supported by storage. Continue next step */
        else
        {
            phb_get_info(NULL, control_block);
        }
    }
#endif /* __USIM_SUPPORT__ */ 
    else if ((control_block->proc_stage <= startup_info_adn_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_ADN].is_support))
    {
        if (control_block->proc_stage <= startup_info_ecc_file_size)
        {
        #ifdef __USIM_SUPPORT__
            if (is_usim_type())
            {
                control_block->primary_ID = FILE_G_ADN_IDX;
                kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                kal_mem_cpy(control_block->path + 4, phb_ptr->path[DATA_DESC_ADN], 2);
            }
            else
        #endif /* __USIM_SUPPORT__ */ 
                control_block->primary_ID = FILE_ADN_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_adn_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_adn_record_num)
        {
        #ifdef __PHB_USIM_SUPPORT__
            if (is_usim_type())
            {
                control_block->proc_stage = startup_info_adn1_record_num;
            }
            else
        #endif /* __PHB_USIM_SUPPORT__ */ 
            {
                control_block->proc_stage = startup_info_grp_record_num;
            }
            (*control_block->controller)(NULL, control_block);
        }
        else
        {
            return;
        }
    }
#ifdef __PHB_USIM_SUPPORT__
   else if (control_block->proc_stage <= startup_info_adn1_record_num && 
		phb_ptr->data_desc[DATA_DESC_IAP].is_support)
   {
        control_block->primary_ID = FILE_G_IAP_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_IAP][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_IAP][1];
        control_block->storage = PHB_SIM;
        phb_control_block_set(control_block,
                    phb_get_info_set_value,
                    phb_get_info,
                    phb_get_info_err_handler,
                    startup_info_iap_record_size);
        phb_sim_file_info(control_block, SIM_REC_SIZE);
   }
    else if (control_block->proc_stage <= startup_info_iap_record_size && phb_ptr->data_desc[DATA_DESC_ANRA].is_support)
    {
        if (phb_ptr->anra_type == 1)
        {
            phb_ptr->data_desc[DATA_DESC_ANRA].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_ANRA1].record_num = phb_ptr->data_desc[DATA_DESC_ADN1].record_num;
            phb_ptr->data_desc[DATA_DESC_ANRA].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1;
            phb_ptr->data_desc[DATA_DESC_ANRA1].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1;
            control_block->proc_stage = startup_info_anra_record_num;
            (*control_block->controller) (NULL, control_block);
        }
        else if (phb_ptr->anra_type == 2)
        {
            control_block->primary_ID = FILE_G_ANR_IDX;
            kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            control_block->path[4] = phb_ptr->path[DATA_DESC_ANRA][0];
            control_block->path[5] = phb_ptr->path[DATA_DESC_ANRA][1];
            phb_ptr->data_desc[DATA_DESC_ANRA].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1 + 2;
            phb_ptr->data_desc[DATA_DESC_ANRA1].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1 + 2;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_anra_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else
        {
            ASSERT(0);
            return;
        }
    }
    else if (control_block->proc_stage <= startup_info_anra_record_num && phb_ptr->data_desc[DATA_DESC_ANRB].is_support)
    {
        if (phb_ptr->anrb_type == 1)
        {
            phb_ptr->data_desc[DATA_DESC_ANRB].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_ANRB1].record_num = phb_ptr->data_desc[DATA_DESC_ADN1].record_num;
            phb_ptr->data_desc[DATA_DESC_ANRB].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1;
            phb_ptr->data_desc[DATA_DESC_ANRB1].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1;
            control_block->proc_stage = startup_info_anrb_record_num;
            (*control_block->controller) (NULL, control_block);
        }
        else if (phb_ptr->anrb_type == 2)
        {
            control_block->primary_ID = FILE_G_ANR_IDX;
            kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            control_block->path[4] = phb_ptr->path[DATA_DESC_ANRB][0];
            control_block->path[5] = phb_ptr->path[DATA_DESC_ANRB][1];
            phb_ptr->data_desc[DATA_DESC_ANRB].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1 + 2;
            phb_ptr->data_desc[DATA_DESC_ANRB1].record_size = PHB_LENGTH_AFTER_ALPHA_ID + 1 + 2;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_anrb_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
    }
    else if (control_block->proc_stage <= startup_info_anrc1_record_num &&
             phb_ptr->data_desc[DATA_DESC_EMAIL].is_support)
    {
        if (phb_ptr->email_type == 1)
        {
            phb_ptr->data_desc[DATA_DESC_EMAIL].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_EMAIL1].record_num = phb_ptr->data_desc[DATA_DESC_ADN1].record_num;
            control_block->proc_stage = startup_info_email_record_num;
            (*control_block->controller) (NULL, control_block);
        }
        else if (phb_ptr->email_type == 2)
        {
            control_block->primary_ID = FILE_G_EMAIL_IDX;
            kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            control_block->path[4] = phb_ptr->path[DATA_DESC_EMAIL][0];
            control_block->path[5] = phb_ptr->path[DATA_DESC_EMAIL][1];

            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_email_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else
        {
            ASSERT(0);
            return;
        }
    }
    else if (control_block->proc_stage <= startup_info_email_record_num &&
             (phb_ptr->data_desc[DATA_DESC_SNE].is_support))
    {
        if (phb_ptr->sne_type == 1)
        {
            phb_ptr->data_desc[DATA_DESC_SNE].record_num = phb_ptr->data_desc[DATA_DESC_SNE].record_num;
            control_block->proc_stage = startup_info_sne_record_num;
            (*control_block->controller) (NULL, control_block);
        }
        else if (phb_ptr->sne_type == 2)
        {
            control_block->primary_ID = FILE_G_SNE_IDX;
            kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            control_block->path[4] = phb_ptr->path[DATA_DESC_SNE][0];
            control_block->path[5] = phb_ptr->path[DATA_DESC_SNE][1];
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_sne_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else
        {
            ASSERT(0);
            return;
        }
    }
    else if (control_block->proc_stage <= startup_info_sne_record_num && (phb_ptr->data_desc[DATA_DESC_GAS].is_support))
    {
        control_block->primary_ID = FILE_G_GAS_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_GAS][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_GAS][1];
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_gas_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
    else if (control_block->proc_stage <= startup_info_gas_record_num && (phb_ptr->data_desc[DATA_DESC_GRP].is_support))
    {
        control_block->primary_ID = FILE_G_GRP_IDX;
        kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
        control_block->path[4] = phb_ptr->path[DATA_DESC_GRP][0];
        control_block->path[5] = phb_ptr->path[DATA_DESC_GRP][1];
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_grp_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
#endif /* __PHB_USIM_SUPPORT__ */ 
    else if ((control_block->proc_stage <= startup_info_fdn_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_FDN].is_support))
    {
        if (control_block->proc_stage <= startup_info_grp_record_num)
        {
            control_block->primary_ID = FILE_FDN_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_fdn_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_fdn_record_num)
        {
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_fdn_record_size);
            phb_sim_file_info(control_block, SIM_REC_SIZE);
        }
        else
        {
            return;
        }
    }
    else if ((control_block->proc_stage <= startup_info_bdn_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_BDN].is_support))
    {
        if (control_block->proc_stage <= startup_info_fdn_record_size)
        {
            control_block->primary_ID = FILE_BDN_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_bdn_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_bdn_record_num)
        {
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_bdn_record_size);
            phb_sim_file_info(control_block, SIM_REC_SIZE);
        }
        else
        {
            return;
        }
    }
    else if ((control_block->proc_stage <= startup_info_msisdn_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_MSISDN].is_support))
    {
        if (control_block->proc_stage <= startup_info_bdn_record_size)
        {
            control_block->primary_ID = FILE_MSISDN_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_msisdn_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_msisdn_record_num)
        {
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_msisdn_record_size);
            phb_sim_file_info(control_block, SIM_REC_SIZE);
        }
        else
        {
            return;
        }
    }
    else if ((control_block->proc_stage <= startup_info_sdn_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_SDN].is_support))
    {
        if (control_block->proc_stage <= startup_info_msisdn_record_size)
        {
            control_block->primary_ID = FILE_SDN_IDX;
            control_block->secondary_ID = PHB_NULL_VALUE;
            control_block->storage = PHB_SIM;
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_sdn_record_num);
            phb_sim_file_info(control_block, SIM_REC_NUM);
        }
        else if (control_block->proc_stage <= startup_info_sdn_record_num)
        {
            phb_control_block_set(
                control_block,
                phb_get_info_set_value,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_sdn_record_size);
            phb_sim_file_info(control_block, SIM_REC_SIZE);
        }
        else
        {
            return;
        }
    }
    else if ((control_block->proc_stage <= startup_info_sdn_record_size) &&
             (phb_ptr->data_desc[DATA_DESC_EXT1].is_support))
    {
    #ifdef __PHB_USIM_SUPPORT__
        if (is_usim_type())
        {
            control_block->primary_ID = FILE_G_EXT1_IDX;
            kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
            control_block->path[4] = phb_ptr->path[DATA_DESC_EXT1][0];
            control_block->path[5] = phb_ptr->path[DATA_DESC_EXT1][1];
        }
        else
    #endif /* __PHB_USIM_SUPPORT__ */ 
            control_block->primary_ID = FILE_EXT1_IDX;
        control_block->secondary_ID = PHB_NULL_VALUE;
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_ext1_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
    else if ((control_block->proc_stage <= startup_info_ext1_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_EXT2].is_support))
    {
        control_block->primary_ID = FILE_EXT2_IDX;
        control_block->secondary_ID = PHB_NULL_VALUE;
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_ext2_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
    else if ((control_block->proc_stage <= startup_info_ext2_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_EXT3].is_support))
    {
        control_block->primary_ID = FILE_EXT3_IDX;
        control_block->secondary_ID = PHB_NULL_VALUE;
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_ext3_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
    else if ((control_block->proc_stage <= startup_info_ext3_record_num) &&
             (phb_ptr->data_desc[DATA_DESC_EXT4].is_support))
    {
        control_block->primary_ID = FILE_EXT4_IDX;
        control_block->secondary_ID = PHB_NULL_VALUE;
        control_block->storage = PHB_SIM;
        phb_control_block_set(
            control_block,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_ext4_record_num);
        phb_sim_file_info(control_block, SIM_REC_NUM);
    }
   /**
    * Either proc_stage is startup_info_ext4_record_num,
    * or proc_stage corresponding EF is not supported
    */
    else if (control_block->proc_stage <= startup_info_ext4_record_num)
    {
        phb_control_block_set(
            control_block,
            phb_get_info,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_compare_digit);
        phb_nvram_read_compare_digit(control_block);
    }
    else
    {
        control_block->proc_stage = startup_info_compare_digit;
        control_block->controller = phb_startup_handler;
        (*control_block->controller) (NULL, control_block);
    }
}   /* end of phb_get_info function */


/*****************************************************************************
 * FUNCTION
 *  phb_get_info_set_value
 * DESCRIPTION
 *  This is get_info_set_value function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_info_set_value(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    switch (control_block->proc_stage)
    {
        case startup_info_ecc_file_size:
            phb_ptr->ecc.num_ecc = (kal_uint8) sim_file_info_cnf->length;
            break;

    #ifdef __USIM_SUPPORT__
        case startup_info_ecc_record_num:
            phb_ptr->data_desc[DATA_DESC_ECC].record_num =
                (sim_file_info_cnf->length < PBR_MAX_ENTRIES_COUNT) ? sim_file_info_cnf->length : PBR_MAX_ENTRIES_COUNT;
            break;
        case startup_info_ecc_record_size:
            phb_ptr->data_desc[DATA_DESC_ECC].record_size = sim_file_info_cnf->length;
            break;

        case startup_info_pbr_record_num:
            phb_ptr->data_desc[DATA_DESC_PBR].record_num =
                (sim_file_info_cnf->length < PBR_MAX_ENTRIES_COUNT) ? sim_file_info_cnf->length : PBR_MAX_ENTRIES_COUNT;
            break;
        case startup_info_pbr_record_size:
            phb_ptr->data_desc[DATA_DESC_PBR].record_size = sim_file_info_cnf->length;
            break;
    #endif /* __USIM_SUPPORT__ */

    #ifdef __PHB_USIM_SUPPORT__
        case startup_info_iap_record_size:
            phb_ptr->data_desc[DATA_DESC_IAP].record_num =
                phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_IAP].record_size = 
                sim_file_info_cnf->length;
        break;

        case startup_info_anra_record_num:
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_ANRA].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            if (phb_ptr->anra_type == 2)
            {
                phb_ptr->data_desc[DATA_DESC_ANRA].record_num =
                    (sim_file_info_cnf->num_of_rec < ANR_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : ANR_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_ANRA].free_count = phb_ptr->data_desc[DATA_DESC_ANRA].record_num;
                if (phb_ptr->data_desc[DATA_DESC_ANRA].free_bitmap != NULL)
                {
                    kal_mem_set(
                        phb_ptr->data_desc[DATA_DESC_ANRA].free_bitmap,
                        0xff,
                        phb_ptr->data_desc[DATA_DESC_ANRA].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
                }
            }
            else
            {
                phb_ptr->data_desc[DATA_DESC_ANRA].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            }
            break;
        case startup_info_anrb_record_num:
            break;
        case startup_info_anrc_record_num:
            break;
        case startup_info_email_record_num:
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_EMAIL].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            if (phb_ptr->email_type == 2)
            {
                phb_ptr->data_desc[DATA_DESC_EMAIL].record_num =
                    (sim_file_info_cnf->num_of_rec < EMAIL_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : EMAIL_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_EMAIL].free_count = phb_ptr->data_desc[DATA_DESC_EMAIL].record_num;
                phb_ptr->email_length = phb_ptr->data_desc[DATA_DESC_EMAIL].record_size - 2;
                if (phb_ptr->data_desc[DATA_DESC_EMAIL].free_bitmap != NULL)
                {
                    kal_mem_set(
                        phb_ptr->data_desc[DATA_DESC_EMAIL].free_bitmap,
                        0xff,
                        phb_ptr->data_desc[DATA_DESC_EMAIL].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
                }
            }
            else
            {
                phb_ptr->data_desc[DATA_DESC_EMAIL].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
                phb_ptr->email_length = phb_ptr->data_desc[DATA_DESC_EMAIL].record_size;
            }
            break;
        case startup_info_sne_record_num:
            phb_ptr->data_desc[DATA_DESC_SNE].record_num =
                (sim_file_info_cnf->num_of_rec < ADN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : ADN_INDEX_MAX_ENTRIES_COUNT;
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_SNE].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            if (phb_ptr->sne_type == 2)
            {
                phb_ptr->sne_alpha_length = phb_ptr->data_desc[DATA_DESC_SNE].record_size - 2;
                if (phb_ptr->data_desc[DATA_DESC_SNE].free_bitmap != NULL)
                {
                    kal_mem_set(
                        phb_ptr->data_desc[DATA_DESC_SNE].free_bitmap,
                        0xff,
                        phb_ptr->data_desc[DATA_DESC_SNE].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
                }
            }
            else
            {
                phb_ptr->sne_alpha_length = phb_ptr->data_desc[DATA_DESC_SNE].record_size;
            }
            break;
        case startup_info_gas_record_num:
            phb_ptr->data_desc[DATA_DESC_GAS].record_num =
                (sim_file_info_cnf->num_of_rec < GAS_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : GAS_MAX_ENTRIES_COUNT;
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_GAS].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->group_alpha_length = phb_ptr->data_desc[DATA_DESC_GAS].record_size;
            break;
        case startup_info_grp_record_num:
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_GRP].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->data_desc[DATA_DESC_GRP].record_num =
                (sim_file_info_cnf->num_of_rec < ADN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : ADN_INDEX_MAX_ENTRIES_COUNT;
            break;
    #endif /* __PHB_USIM_SUPPORT__ */ 

        case startup_info_adn_record_num:
         /**
          * Actual record number should be controlled by evaluating
          * MAX_ENTRIES_COUNT values.
          * This prevents a free record to be found when attempting
          * write a record that exceeds maximum capacity allocated
          * for management data structure.
          * Since it exceeds maximum capacity, write such a record is
          * meaningless, because it cannot be read by PHB module.
          * Further, if write such a record could result in failure of PHB
          * module. >=P
          */
            phb_ptr->data_desc[DATA_DESC_ADN].record_num =
                (sim_file_info_cnf->num_of_rec < ADN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : ADN_INDEX_MAX_ENTRIES_COUNT;
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->adn_size = sim_file_info_cnf->num_of_rec;
                phb_ptr->data_desc[DATA_DESC_ADN].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
                phb_ptr->adn_alpha_length = 
                    phb_ptr->data_desc[DATA_DESC_ADN].record_size - 14;
            }
            break;

        case startup_info_fdn_record_num:
            phb_ptr->data_desc[DATA_DESC_FDN].record_num =
                (sim_file_info_cnf->length < FDN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : FDN_INDEX_MAX_ENTRIES_COUNT;
            break;
        case startup_info_fdn_record_size:
            phb_ptr->data_desc[DATA_DESC_FDN].record_size = sim_file_info_cnf->length;
            break;

        case startup_info_bdn_record_num:
            phb_ptr->data_desc[DATA_DESC_BDN].record_num =
                (sim_file_info_cnf->length < BDN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : BDN_INDEX_MAX_ENTRIES_COUNT;
            break;
        case startup_info_bdn_record_size:
            phb_ptr->data_desc[DATA_DESC_BDN].record_size = sim_file_info_cnf->length;
            break;

        case startup_info_msisdn_record_num:
            phb_ptr->data_desc[DATA_DESC_MSISDN].record_num =
                (sim_file_info_cnf->length < MSISDN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : MSISDN_INDEX_MAX_ENTRIES_COUNT;
            break;
        case startup_info_msisdn_record_size:
            phb_ptr->data_desc[DATA_DESC_MSISDN].record_size = sim_file_info_cnf->length;
            break;

        case startup_info_sdn_record_num:
            phb_ptr->data_desc[DATA_DESC_SDN].record_num =
                (sim_file_info_cnf->length < SDN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : SDN_INDEX_MAX_ENTRIES_COUNT;
            break;
        case startup_info_sdn_record_size:
            phb_ptr->data_desc[DATA_DESC_SDN].record_size = sim_file_info_cnf->length;
            break;

        case startup_info_ext1_record_num:
            phb_ptr->data_desc[DATA_DESC_EXT1].record_num =
                (sim_file_info_cnf->length < EXT1_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : EXT1_MAX_ENTRIES_COUNT;
            /* phb_ptr->data_desc[DATA_DESC_EXT1].record_size = SIM_EF_EXT_SIZE; */
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_EXT1].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->data_desc[DATA_DESC_EXT1].free_count = phb_ptr->data_desc[DATA_DESC_EXT1].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;

        case startup_info_ext2_record_num:
            phb_ptr->data_desc[DATA_DESC_EXT2].record_num =
                (sim_file_info_cnf->length < EXT2_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : EXT2_MAX_ENTRIES_COUNT;
            /* phb_ptr->data_desc[DATA_DESC_EXT2].record_size = SIM_EF_EXT_SIZE; */
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_EXT2].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->data_desc[DATA_DESC_EXT2].free_count = phb_ptr->data_desc[DATA_DESC_EXT2].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;

        case startup_info_ext3_record_num:
            phb_ptr->data_desc[DATA_DESC_EXT3].record_num =
                (sim_file_info_cnf->length < EXT3_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : EXT3_MAX_ENTRIES_COUNT;
            /* phb_ptr->data_desc[DATA_DESC_EXT2].record_size = SIM_EF_EXT_SIZE; */
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_EXT3].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->data_desc[DATA_DESC_EXT3].free_count = phb_ptr->data_desc[DATA_DESC_EXT3].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;

        case startup_info_ext4_record_num:
            phb_ptr->data_desc[DATA_DESC_EXT4].record_num =
                (sim_file_info_cnf->length < EXT4_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->length : EXT4_MAX_ENTRIES_COUNT;
            /* phb_ptr->data_desc[DATA_DESC_EXT4].record_size = SIM_EF_EXT_SIZE; */
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_EXT4].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
            }
            phb_ptr->data_desc[DATA_DESC_EXT4].free_count = phb_ptr->data_desc[DATA_DESC_EXT4].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
    }

    (*control_block->controller) (NULL, control_block);
}   /* end of phb_get_info_set_value function */


/*****************************************************************************
 * FUNCTION
 *  phb_get_info_err_handler
 * DESCRIPTION
 *  This is get_info_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_info_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Bypass error, and continue next step */
    control_block->IO_stage = IO_NONE;
    (*control_block->controller) (NULL, control_block);
}   /* end of phb_get_info_err_handler function */

#ifdef __PHB_RECORD_LN_TYPE_SEQ__


/*****************************************************************************
 * FUNCTION
 *  phb_startup_sync_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_sync_ln_type_seq(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    if (is_sim_replaced((phb_current_mod == MOD_PHB) ? SIM1 : SIM2))
#else /* __GEMINI__ */
    if (is_sim_replaced())
#endif /* __GEMINI__ */
    {
        phb_set_ln_type_seq(PHB_TOTAL_LN_ENTRIES, 0xff);
        phb_startup_erase_ln(NULL, NULL);
        return;
    }
    if (control_block == NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);
    }

    if (control_block->proc_stage == SYNC_LN_TYPE_SEQ_NONE)
    {
        control_block->IO_cnf_receive = phb_startup_sync_ln_type_seq;
        control_block->proc_stage = SYNC_LN_TYPE_SEQ_CONTINUE;
    #ifdef __GEMINI__
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID = 2;
        }
        else
    #endif /* __GEMINI__ */
        {
            control_block->secondary_ID = 1;
        }
        control_block->IO_stage = IO_WAIT;
        phb_read_ln_type_seq_from_nvram(control_block);
        return;
    }
    else if (control_block->proc_stage == SYNC_LN_TYPE_SEQ_CONTINUE)
    {
        kal_uint16 length;
        nvram_read_cnf_struct *msg_ptr = NULL;
        nvram_ef_phb_ln_type_seq_struct *pdu_data;
        int i;

        msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;

        if (control_block->IO_stage == IO_WAIT && msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            /* control_block->IO_cnf_receive = phb_read_ln_handler; */
            pdu_data = (nvram_ef_phb_ln_type_seq_struct*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &length);
            for (i = 0; i < length; i++)
            {
                phb_ln_type_seq[i] = pdu_data->type_seq[i];
            }
        }
        else
        {
            /* all is 0xff */
            phb_set_ln_type_seq(PHB_TOTAL_LN_ENTRIES, 0xff);
        }
        control_block->IO_stage = IO_NONE;
    }
    phb_free_control_block(control_block);
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__
    /* SIM isn't replaced. Clear lnd type seq */
    phb_clear_lnd_type_seq();
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 
    phb_startup_erase_ln(NULL, NULL);
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_startup_erase_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_erase_ln(ilm_struct *ilm_ptr, control_block_type *control_block)
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
        control_block->cnf_msg_id = MSG_ID_L4CPHB_INIT_LN_REQ;
    }

#ifndef __PHB_ALWAYS_SYNC_SIM_LN__
#ifdef __GEMINI__
    if (is_sim_replaced((phb_current_mod == MOD_PHB) ? SIM1 : SIM2) == KAL_FALSE)
#else /* __GEMINI__ */
    if (is_sim_replaced() == KAL_FALSE)
#endif /* __GEMINI__ */
    {
        phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
        return;
    }
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 

    if (control_block->proc_stage == ERASE_LN_NONE)
    {
        control_block->IO_cnf_receive = phb_startup_erase_ln;
        control_block->proc_stage = ERASE_LN_CONTINUE;
        control_block->secondary_ID = PHB_LND_LID_START;
    #ifdef __GEMINI__
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID += PHB_TOTAL_LN_LID;
        }
    #endif /* __GEMINI__ */
        control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
        kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));
        phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
        return;
    }
    else if (control_block->proc_stage == ERASE_LN_CONTINUE)
    {
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            #ifdef __GEMINI__
                if ((((phb_current_mod == MOD_PHB_2) && (control_block->secondary_ID > PHB_TOTAL_LN_LID) && (control_block->secondary_ID < 2* PHB_TOTAL_LN_LID)) || ((phb_current_mod == MOD_PHB) && (control_block->secondary_ID < PHB_TOTAL_LN_LID)))&& 
            #else /* __GEMINI__ */
                if ((control_block->secondary_ID < PHB_TOTAL_LN_LID) && 
            #endif /* __GEMINI__ */
            #ifdef __GEMINI__
                (is_sim_replaced((phb_current_mod == MOD_PHB) ? SIM1 : SIM2) == KAL_TRUE)
            #else /* __GEMINI__ */
                (is_sim_replaced() == KAL_TRUE)
            #endif /* __GEMINI__ */
                )
            {
                control_block->secondary_ID++;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }
            else
            {
                /* copy LND from sim */
                control_block->proc_stage = COPY_LN_NONE;
                phb_startup_copy_ln(NULL, control_block);
                return;
            }
        }
        else
        {
            free_ctrl_buffer(control_block->data);
        #ifdef __PHB_RECORD_LN_TYPE_SEQ__
            control_block->proc_stage = WRITE_LN_TYPE_SEQ;
            phb_write_ln_type_seq_to_nvram(control_block);
        #else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
            phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
        #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
        }
    }
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    else if (control_block->proc_stage == WRITE_LN_TYPE_SEQ)
    {
        phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  phb_startup_copy_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_copy_ln(ilm_struct *ilm_ptr, control_block_type *control_block)
{
#ifndef __PHB_NVRAM_LN_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block->proc_stage == COPY_LN_NONE)
    {
    #ifdef __GEMINI__
        if (sim_service_table_query(SERVICE_LND, ((phb_current_mod == MOD_PHB) ? SIM1 : SIM2)) == KAL_TRUE)
    #else /* __GEMINI__ */
        if (sim_service_table_query(SERVICE_LND) == KAL_TRUE)
    #endif /* __GEMINI__ */
        {
            sim_file_info_req_struct *param_ptr;

            control_block->proc_stage = COPY_LN_READ_FILE;
            control_block->IO_cnf_receive = phb_startup_copy_ln;
            control_block->IO_stage = IO_WAIT;

            param_ptr = (sim_file_info_req_struct*)
                construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

            param_ptr->file_idx = FILE_LND_IDX;
            param_ptr->access_id = control_block->ID;
            phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
            return;
        }
    }
    else if (control_block->proc_stage == COPY_LN_READ_FILE)
    {
        sim_file_info_cnf_struct *msg_ptr = NULL;

        msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == SIM_CMD_SUCCESS)
        {
            if (msg_ptr->num_of_rec > 0)
            {
                control_block->index = 1;
                control_block->length = msg_ptr->file_size;
                control_block->seg_total = msg_ptr->num_of_rec;
                control_block->proc_stage = COPY_LN_READ;
                control_block->secondary_ID = PHB_LND_LID_START;
            #ifdef __GEMINI__
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ */

                phb_read_ln_from_sim(control_block);
                return;
            }
        }
    }
    else if (control_block->proc_stage == COPY_LN_READ)
    {
        sim_read_cnf_struct *msg_ptr = NULL;

        msg_ptr = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == SIM_CMD_SUCCESS)
        {
            phb_startup_translate_ln_from_sim((kal_uint8*) msg_ptr->data, control_block);

            if ((control_block->index % PHB_MAX_LN_ENTRIES) == 0)
            {
                /* has collected 10 entries, write one segment (10 records) to NVRAM first */
                control_block->proc_stage = COPY_LN_WRITE;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }

            if ((control_block->index < control_block->seg_total) && (control_block->index < PHB_MAX_LND_ENTRIES))
            {
                control_block->index++;
                phb_read_ln_from_sim(control_block);
                return;
            }
            else
            {
                control_block->proc_stage = COPY_LN_WRITE;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }
        }
    }
    else if (control_block->proc_stage == COPY_LN_WRITE)
    {
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            if ((control_block->index < control_block->seg_total) && (control_block->index < PHB_MAX_LND_ENTRIES))
            {
                control_block->proc_stage = COPY_LN_READ;
                control_block->secondary_ID++;
                control_block->index++;
                kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));
                phb_read_ln_from_sim(control_block);
                return;
            }
            else
            {
                free_ctrl_buffer(control_block->data);
            #ifdef __PHB_RECORD_LN_TYPE_SEQ__
                control_block->proc_stage = WRITE_LN_TYPE_SEQ;
                phb_write_ln_type_seq_to_nvram(control_block);
                control_block->IO_cnf_receive = phb_startup_erase_ln;
            #else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
                phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
            #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
                return;
            }
        }
    }
#endif /* __PHB_NVRAM_LN_ONLY__ */ 
    free_ctrl_buffer(control_block->data);
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    control_block->proc_stage = WRITE_LN_TYPE_SEQ;
    phb_write_ln_type_seq_to_nvram(control_block);
    control_block->IO_cnf_receive = phb_startup_erase_ln;
#else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}

#ifndef __PHB_NVRAM_LN_ONLY__


/*****************************************************************************
 * FUNCTION
 *  phb_startup_translate_ln_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_translate_ln_from_sim(kal_uint8 *data, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 rec_size, alpha_size;
    nvram_ef_phb_ln_struct *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record = (nvram_ef_phb_ln_struct*) control_block->data;

    rec_size = control_block->length / control_block->seg_total;
    alpha_size = rec_size - PHB_LENGTH_AFTER_ALPHA_ID;

    if ((data[alpha_size] != 0) && (is_empty(data, rec_size) == KAL_FALSE))
    {
        istring_type istring;
        phb_ef_struct phb_ef;

        phb_ef.alpha_id = data;
        phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) data + alpha_size);

        /* Set up phb_entry->alpha_id */
        record->array[record->no_entry].name_dcs = 0;
        record->array[record->no_entry].name_length = 0;
        kal_mem_set((kal_uint8*) record->array[record->no_entry].name, 0, L4_MAX_NAME);
        istring.length = L4_MAX_NAME;
        istring.data = (kal_uint8*) record->array[record->no_entry].name;
        record->array[record->no_entry].name_length = istring_decode_from_sim((kal_uint8) alpha_size, phb_ef.alpha_id, &istring);
        if (record->array[record->no_entry].name_length == 0)
        {
            istring.charset = PHB_ASCII;
        }
        record->array[record->no_entry].name_dcs = istring.charset;
        if (record->array[record->no_entry].name_length >= L4_MAX_NAME)
        {
            if (record->array[record->no_entry].name_dcs == PHB_ASCII)
            {
                record->array[record->no_entry].name_length--;
                record->array[record->no_entry].name[L4_MAX_NAME - 1] = 0;
            }
            else if (record->array[record->no_entry].name_dcs == PHB_UCS2)
            {
                record->array[record->no_entry].name_length -= 2;
                record->array[record->no_entry].name[L4_MAX_NAME - 1] = 0;
                record->array[record->no_entry].name[L4_MAX_NAME - 2] = 0;
            }
        }

        /* if (alpha_size >= 30)
           {
           kal_mem_cpy (record->array[record->no_entry].name, data, 29);
           record->array[record->no_entry].name[29] = 0;
           record->array[record->no_entry].name_length =
           strlen ((char*)record->array[record->no_entry].name);
           }
           else
           {
           kal_mem_cpy (record->array[record->no_entry].name, data, alpha_size);
           record->array[record->no_entry].name[alpha_size] = 0;
           record->array[record->no_entry].name_length =
           strlen ((char*)record->array[record->no_entry].name);
           } */
        if (*(data + alpha_size) <= 10)
        {
            record->array[record->no_entry].addr_length = *(data + alpha_size);
        }
        else
        {
            record->array[record->no_entry].addr_length = 10;
        }

        kal_mem_cpy(&record->array[record->no_entry].addr_bcd[1], data + alpha_size + 2, 10);
        record->array[record->no_entry].addr_bcd[record->array[record->no_entry].addr_length + 1] = 0xff;
        record->array[record->no_entry].addr_bcd[0] = *(data + alpha_size + 1);

        record->array[record->no_entry].count = 1;
        record->no_entry++;
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        phb_shift_ln_type_seq(0, PHB_LND);
    #endif 
    }
}
#endif /* __PHB_NVRAM_LN_ONLY__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_init_ln_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_ln_confirm(phb_errno_enum result, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_CNF, result);

    if ((result == PHB_ERRNO_BUSY) || (control_block->cnf_msg_id == MSG_ID_L4CPHB_INIT_LN_REQ))
    {
        l4cphb_init_ln_cnf_struct *l4cphb_init_ln_cnf;

        l4cphb_init_ln_cnf = (l4cphb_init_ln_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_init_ln_cnf_struct),
                                                            TD_CTRL);
        l4cphb_init_ln_cnf->result = result;

        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_LN_CNF, (local_para_struct*) l4cphb_init_ln_cnf, NULL);
            return;
        }

        phb_free_control_block(control_block);

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_LN_CNF, (local_para_struct*) l4cphb_init_ln_cnf, NULL);

        return;
    }
}   /* end of phb_init_ln_confirm */

