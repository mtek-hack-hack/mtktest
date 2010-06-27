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
 * phb_data_desc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the data_descriptor.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_DATA_DESC_H
#define _PHB_DATA_DESC_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
#error "stack_ltlcom.h should be included"
#endif 
#ifndef _PHB_DEFS_H
#error "phb_defs.h should be included"
#endif 

    typedef enum
    {
    #ifdef __USIM_SUPPORT__
        DATA_DESC_ECC,
    #endif
    #ifdef __PHB_USIM_SUPPORT__
        DATA_DESC_IAP,
        DATA_DESC_SNE,
        DATA_DESC_ANRA,
        DATA_DESC_ANRB,
        DATA_DESC_ANRC,
        DATA_DESC_PBC,
        DATA_DESC_GRP,
        DATA_DESC_UID,
        DATA_DESC_EMAIL,
        DATA_DESC_IAP1, /* 10 */
        DATA_DESC_ADN1,
        DATA_DESC_SNE1,
        DATA_DESC_ANRA1,
        DATA_DESC_ANRB1,
        DATA_DESC_ANRC1,
        DATA_DESC_PBC1,
        DATA_DESC_GRP1,
        DATA_DESC_UID1,
        DATA_DESC_EMAIL1,
        DATA_DESC_AAS,
        DATA_DESC_GAS,
    #endif /* __PHB_USIM_SUPPORT__ */ 
        DATA_DESC_ADN,
        DATA_DESC_EXT1,
        USIM_DATA_DESC_TOTAL,
        DATA_DESC_PHB = USIM_DATA_DESC_TOTAL,
        DATA_DESC_FDN,
        DATA_DESC_BDN,
        DATA_DESC_MSISDN,
        DATA_DESC_SDN,
        DATA_DESC_EXT2,
        DATA_DESC_EXT3,
        DATA_DESC_EXT4,
    #ifdef __USIM_SUPPORT__
        DATA_DESC_PBR,  /* fixed path */
    #endif 
        DATA_DESC_TOTAL
    } data_desc_enum;

    typedef struct
    {
        kal_bool is_support;
        kal_uint16 record_num;  /* total record number in storage */
        kal_uint16 record_size; /* size of record in storage */
        kal_uint16 free_count;
        kal_uint16 free_bitmap_bits;
        kal_uint8 *free_bitmap;
    } data_desc_type;

#ifdef __PHB_USIM_SUPPORT__
    typedef struct
    {
        kal_int8 support_type;
        kal_int8 path[2];
        kal_uint16 record_num;  /* total record number in storage */
        kal_uint16 record_size; /* size of record in storage */
        kal_uint16 free_count;
        kal_uint16 free_bitmap_bits;
        kal_uint8 *free_bitmap;
    } pbr_data_desc_type;
#endif /* __PHB_USIM_SUPPORT__ */ 

    typedef enum
    {
        RECORD_INVALID,
        RECORD_OCCUPIED,
        RECORD_FREE
    } free_status_enum;

    extern void phb_data_desc_new(void);
    extern void phb_data_desc_reset(void);
    extern void phb_data_desc_reset_free_count(void);
    extern void phb_data_desc_set_is_support(data_desc_enum type, kal_bool is_support);
    extern kal_uint16 phb_data_desc_get_record_size(data_desc_enum type);
    extern kal_uint16 phb_data_desc_get_record_num(data_desc_enum type);
    extern void phb_data_desc_set(data_desc_enum type, kal_uint16 record_num, kal_uint16 record_size);
    extern void phb_data_desc_mark_free(data_desc_enum type, kal_uint16 pos, kal_bool is_free);
    extern free_status_enum phb_data_desc_is_free(data_desc_enum type, kal_uint16 pos);
    extern kal_uint16 phb_data_desc_find_next_free(data_desc_enum type);
    extern kal_uint16 phb_data_desc_get_free_count(data_desc_enum type);
    extern data_desc_enum phb_data_desc_get_desc_by_ID(kal_uint16 file_id, kal_uint8 storage);
    extern kal_uint16 phb_data_desc_get_ID_by_desc(data_desc_enum type);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_DATA_DESC_H */ 

