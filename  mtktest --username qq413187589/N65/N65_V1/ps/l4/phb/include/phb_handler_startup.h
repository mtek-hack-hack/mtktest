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
 * phb_handler_startup.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is declarations of startup handler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _PHB_HANDLER_STARTUP_H
#define _PHB_HANDLER_STARTUP_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
#error "stack_ltlcom.h should be included"
#endif 

    /* Order of states must be SYNCHRONOUS with code */
    typedef enum
    {
        startup_none,
        startup_info_size_nvram,
        startup_info_ecc_record_num,    /* USIM- ECC */
        startup_info_ecc_record_size,   /* USIM- ECC */
        startup_info_pbr_record_num,    /* USIM- PBR */
        startup_info_pbr_record_size,   /* USIM- PBR */
        /* USIM PBR is required to be read before ADN */
        startup_info_pbr_contents,

        startup_info_ecc_file_size,     /* SIM- ECC */
        startup_info_adn_record_num,
        startup_info_adn1_record_num,
        /* USIM field information */
        startup_info_iap_record_size,   /* 10 */
        startup_info_anra_record_num,
        startup_info_anrb_record_num,
        startup_info_anrc_record_num,
        startup_info_anra1_record_num,
        startup_info_anrb1_record_num,
        startup_info_anrc1_record_num,
        startup_info_email_record_num,
        /* startup_info_email_record_size, */
        startup_info_sne_record_num,
        /* startup_info_sne_record_size, */
        startup_info_gas_record_num,
        /* startup_info_gas_record_size, */
        startup_info_grp_record_num,

        startup_info_fdn_record_num,    /* 20 */
        startup_info_fdn_record_size,
        startup_info_bdn_record_num,
        startup_info_bdn_record_size,
        startup_info_msisdn_record_num,
        startup_info_msisdn_record_size,
        startup_info_sdn_record_num,
        startup_info_sdn_record_size,   /* 30 */
        startup_info_ext1_record_num,
        startup_info_ext2_record_num,
        startup_info_ext3_record_num,
        startup_info_ext4_record_num,

        startup_info_compare_digit,
        startup_build_ecc_index,
        /* FDN is required to be accessed earlier than PHB, ADN, */
        startup_build_fdn_index,
        startup_build_phb_index,
        startup_build_adn_index,
        startup_build_bdn_index,
        /* MSISDN and SDN use 1 to 1 mapping, no index is built. */
        /* Now MSISDN data_desc should build for AT cmd */
        startup_build_msisdn_index,
        startup_build_ext1_index,   /* 40 */
        startup_build_ext2_index,
        /* Since SDN, EXT3 is read only, free-bitmap is not needed, thus saves memory consumption */
        startup_build_ext4_index,

        startup_build_anr_index,
        startup_build_email_index,
        startup_build_gas_index,
        startup_build_grp_index,
        startup_build_index_finish,
        startup_confirm
    } startup_stage_enum;

    typedef enum
    {
        ERASE_LN_NONE,
        ERASE_LN_CONTINUE = 0x10,   /* To avoid conflict with READ_CONTINUE */
        COPY_LN_NONE,
        COPY_LN_READ,
        COPY_LN_READ_FILE,
        COPY_LN_WRITE,
        WRITE_LN_TYPE_SEQ
    } erase_stage_enum;

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    typedef enum
    {
        SYNC_LN_TYPE_SEQ_NONE,
        SYNC_LN_TYPE_SEQ_CONTINUE = 0x10    /* To avoid conflict with READ_CONTINUE */
    } sync_ln_type_seq_stage_enum;

    extern void phb_startup_sync_ln_type_seq(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

    extern void phb_startup_handler(ilm_struct *ilm_ptr, control_block_type *control_block);

    extern void phb_startup_erase_ln(ilm_struct *ilm_ptr, control_block_type *control_block);

#ifdef __PHB_USIM_SUPPORT__
    extern void phb_usim_startup_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif 

#ifdef __SAT__
    extern void phb_sat_file_change_confirm(
                    phb_errno_enum result,
                    kal_uint8 src_id,
                    control_block_type *control_block);
#endif /* __SAT__ */ 

    /* MTK 2004-08-13, Wilson */
    extern void phb_build_index_continue_adn(control_block_type *control_block);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_HANDLER_STARTUP_H */ 

