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

/*******************************************************************************
 * Filename:
 * ---------
 * phb_context.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is context declarations.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PHB_CONTEXT_H
#define _PHB_CONTEXT_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef _PS2SIM_STRUCT_H
#error "ps2sim_struct.h should be included"
#endif 
#ifndef _PHB_CONTROL_BLOCK_H
#error "phb_control_block.h should be included"
#endif 
#ifndef _PHB_DATA_DESC_H
#error "phb_data_desc.h should be included"
#endif 
#ifndef _PHB_DATA_ENTRY_TABLE_H
#error "phb_data_entry_table.h should be included"
#endif 
#ifndef _PHB_NAME_NUM_INDEX_H
#error "phb_name_num_index.h should be included"
#endif 
#ifndef _PHB_PINDEX_H
#error "phb_pindex.h should be included"
#endif 

    typedef enum
    {
        PHB_STATE_NULL,                 /* NULL state */
        PHB_STATE_LN_NOT_READY,         /* PHB and LN both not ready */
        PHB_STATE_NOT_READY,            /* PHB not ready and FDN not ready */
        PHB_STATE_NOT_READY_FDN_READY,  /* PHB still not ready, but FDN ready. */
        PHB_STATE_READY                 /* PHB ready */
    } phb_state_enum;

    /* The indexing structure */
    typedef struct
    {
    #ifdef __PHB_SORT_ENABLE__
        name_num_index_type phb_index;
    #endif 
        name_num_index_type fdn_index;
        name_num_index_type bdn_index;
    } indices_type;

    typedef struct
    {
        phb_state_enum        state;
        sim_dn_enum           dn_type;

        kal_bool              drop_cnf;

        kal_uint8             fdn_alpha_length;
        kal_uint8             bdn_alpha_length;
        kal_uint8             msisdn_alpha_length;
        kal_uint8             adn_alpha_length;
        kal_uint8             compare_digit;

    #ifdef __PHB_USIM_SUPPORT__
        kal_bool              is_usim;   /* is_usim_type() */
        kal_uint8             adn1_sfi;
        kal_uint8             anra_type;
        kal_uint8             anrb_type;
        kal_uint8             anrc_type;
        kal_uint8             email_type;
        kal_uint8             sne_type;
        kal_uint8             group_alpha_length;
        kal_uint8             sne_alpha_length;
        kal_uint8             email_length;
        kal_uint8             iap_length;
        kal_uint8             iap_anra;
        kal_uint8             iap_anrb;
        kal_uint8             iap_anrc;
        kal_uint8             iap_email;
        kal_uint8             iap_sne;
    #endif /* __PHB_USIM_SUPPORT__ */ 
    #ifdef __USIM_SUPPORT__
        kal_uint8 adn_sfi;
        kal_uint8             path[USIM_DATA_DESC_TOTAL][2];
    #endif /* _USIM_SUPPORT__ */

        kal_uint16            adn_size;

        control_block_type    control_block[PHB_CONCURRENCY_DEGREE];

        /* The data descriptor */
        data_desc_type        data_desc[DATA_DESC_TOTAL];

        /* The indexing structure */
        indices_type          indices;

        sim_ecc_struct        ecc;
    } phb_context_type;

    extern phb_context_type *phb_ptr;
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#ifdef __GEMINI__
    extern kal_uint8 *phb_ln_type_seq;
#else /* __GEMINI__ */
    extern kal_uint8 phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES];
#endif /* __GEMINI__ */
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__
    extern void phb_clear_lnd_type_seq(void);
#endif 
    extern void phb_set_ln_type_seq(kal_uint16 num, kal_uint8 type);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
#if (MAX_PHB_LN_ENTRY > 20)
    extern kal_uint16 phb_get_ln_total_entry(kal_uint8 type);
    extern phb_ln_entry_struct shifted_entry;
#endif /* (MAX_PHB_LN_ENTRY > 20) */ 

    extern void phb_context_reset(void);
    extern control_block_type *phb_alloc_control_block(void);
    extern void phb_free_control_block(control_block_type *control_block);

    extern void phb_reset_all_control_blocks(void);
#ifdef __GEMINI__
    extern void phb_context_selection(kal_uint8 sim_interface);
#endif

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_CONTEXT_H */ 
/* End of file phb_context.h */

