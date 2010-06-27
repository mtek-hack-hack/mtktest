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
 * phb_nvram_access.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _PHB_NVRAM_ACCESS_H_
#define _PHB_NVRAM_ACCESS_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
#error "stack_ltlcom.h should be included"
#endif 

#ifndef __PHB_MULTIPLE_READ__
#define __PHB_MULTIPLE_READ__
#endif 

    /* Byte size of DIALLING_NUMBER/SSC_STRING allocated in NVRAM */
#define NVRAM_EF_TEL_NUMBER_SIZE 20

    /* Byte size after ALPHA_ID field allocated in NVRAM */
#define NVRAM_PHB_LENGTH_AFTER_ALPHA_ID      (1 + 1 + NVRAM_EF_TEL_NUMBER_SIZE + 1 + 1)

/**
 * Maximum bytes of TON/NPI and DIALLING_NUMBER/SSC_STRING 
 * fields allocated in NVRAM
 */
#define NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN       (TON_NPI_SIZE + NVRAM_EF_TEL_NUMBER_SIZE)

/** 
 * Originally, PHB wants to make structures of NVRAM and SIMadn
 * uniform. However, this seems hard to achieve, since what SPEC defines
 * doesn't meet customers' requirements. Sigh.
 */

    /* phone book entries structure allocated in NVRAM */
    typedef struct
    {
        kal_uint8 len;
        kal_uint8 ton_npi;
        kal_uint8 tel_number[NVRAM_EF_TEL_NUMBER_SIZE];
        kal_uint8 cap_cnf_id;
        kal_uint8 ext_id;   /* Should not be used for nvram_access. */
        /* Note that BDN has 1 byte more: comparison method ID */
    } phb_nvram_ef_mandatory_struct;

    typedef struct
    {
        kal_uint8 *alpha_id;
        phb_nvram_ef_mandatory_struct *mandatory;
    } phb_nvram_ef_struct;

    extern kal_bool phb_nvram_read(control_block_type *control_block);
    extern kal_bool phb_nvram_write(control_block_type *control_block);
    extern kal_bool phb_nvram_delete(control_block_type *control_block);

    extern void phb_nvram_read_compare_digit(control_block_type *control_block);

    extern void phb_read_ln_from_nvram(control_block_type *control_block);
    extern void phb_write_ln_to_nvram(nvram_ef_phb_ln_struct *pdu_data, control_block_type *control_block);

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    extern void phb_write_ln_type_seq_to_nvram(control_block_type *control_block);
    extern void phb_read_ln_type_seq_from_nvram(control_block_type *control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_NVRAM_ACCESS_H_ */ 

