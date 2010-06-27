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
 * phb_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file configs memory allocation.
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
#ifndef _PHB_CONFIG_H
#define _PHB_CONFIG_H

/* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef _PHB_DEFS_H
#error "phb_defs.h should be included"
#endif 

/**
 * Defines memory allocation of name_num_index for PHB, FDN, and BDN 
 * had better be multiple of 8, because free-bitmap comes from these values.
 */

/** 
 * The value of MAX_ENTRIES_COUNT is a tradeoff.
 * Record number that exceeds this value will NOT be managed by PHB.
 * Not only free-bitmap management, but also entire indexing structure.
 * In other words, records stored exceeds this value will not be seen.
 *
 * Refer to comment of "case startup_info_adn_record_num:" of 
 * phb_get_info_set_value() function.
 *
 * Separate storage space with separate management data structures
 * are maintained so that though view to these records are mixed, they
 * are actually maintained individually. Thus free-bitmap and add/update/
 * delete operations can be consistent and synchronous.
 */

#define ADN_INDEX_MAX_ENTRIES_COUNT             MAX_PHB_SIM_ENTRY

#define NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT       MAX_PHB_PHONE_ENTRY

/* DO NOT take away (), or precedence problem will happen!!! */
#define PHB_INDEX_MAX_ENTRIES_COUNT             (NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT + ADN_INDEX_MAX_ENTRIES_COUNT)
#ifdef __MEXICO_ECC__
#define FDN_INDEX_MAX_ENTRIES_COUNT             50
#else 
#define FDN_INDEX_MAX_ENTRIES_COUNT             32
#endif 
#define BDN_INDEX_MAX_ENTRIES_COUNT             32

/** 
 * MSISDN and SDN now uses 1 to 1 mapping. 
 * Under this scheme,  empty record could be read.
 * Reason that adopt this scheme is MSISDN/SDN is NOT SORTED.
 *
 * If there is gap between records, continuous index will skip that empty record.
 * Once new record is added into that record, in this session that new
 * record appears to be the last one. However, next time system reboot,
 * that record appears into that gap, ie, between records instead of being
 * last one. That leads to an inconsistent view. Hence, 1 to 1 mapping is used
 * and this issue is left for MMI to decide.
 *
 * Another solution is: once a new record is appended, it is synchronized into
 * pindex according to record_index; in other words, pindex is sorted by 
 * record_index. This could results in consitent view and upper layer can 
 * fully take advantage of PHB module, such as free-list lookup. However, 
 * if upper layer sorts by ALPHA ID, sort by record index is meaningless;
 * since read a record by index could return non continuous ALPHA ID 
 * records. Evenetually upper layer still need to sort them.
 *
 * Conclusion: use 1 to 1 mapping. >=I
 */
#define MSISDN_INDEX_MAX_ENTRIES_COUNT          4
#define SDN_INDEX_MAX_ENTRIES_COUNT             32

#define EXT1_MAX_ENTRIES_COUNT                  8
#define EXT2_MAX_ENTRIES_COUNT                  8
#define EXT3_MAX_ENTRIES_COUNT                  8
#define EXT4_MAX_ENTRIES_COUNT                  8

/* USIM PHB */
#define ANR_INDEX_MAX_ENTRIES_COUNT             40
#define EMAIL_INDEX_MAX_ENTRIES_COUNT           40
#define SNE_INDEX_MAX_ENTRIES_COUNT             40

/**
 * Defines memory allocation for data descriptor, 
 * should be (???_MAX_ENTRIES_COUNT + 7) / 8
 */
#define FREE_BITMAP_NVRAM_PHB_BYTES             ((NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_ADN_BYTES                   ((ADN_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_FDN_BYTES                   ((FDN_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_BDN_BYTES                   ((BDN_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_MSISDN_BYTES                ((MSISDN_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_SDN_BYTES                   (0)
#define FREE_BITMAP_EXT1_BYTES                  ((EXT1_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_EXT2_BYTES                  ((EXT2_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_EXT3_BYTES                  (0)
#define FREE_BITMAP_EXT4_BYTES                  ((EXT4_MAX_ENTRIES_COUNT + 7) / 8)

#define FREE_BITMAP_ECC_BYTES                   (0)
#define FREE_BITMAP_PBR_BYTES                   (0)
#define FREE_BITMAP_IAP_BYTES                   (0)
#define FREE_BITMAP_SNE_BYTES                   ((SNE_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_ANRA_BYTES                  ((ANR_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_ANRB_BYTES                  ((ANR_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_ANRC_BYTES                  ((ANR_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_PBC_BYTES                   (0)
#define FREE_BITMAP_GRP_BYTES                   (FREE_BITMAP_ADN_BYTES)
#define FREE_BITMAP_UID_BYTES                   (0)
#define FREE_BITMAP_EMAIL_BYTES                 ((EMAIL_INDEX_MAX_ENTRIES_COUNT + 7) / 8)
#define FREE_BITMAP_IAP1_BYTES                  (0)
#define FREE_BITMAP_ADN1_BYTES                  (0)
#define FREE_BITMAP_SNE1_BYTES                  (0)
#define FREE_BITMAP_ANRA1_BYTES                 (0)
#define FREE_BITMAP_ANRB1_BYTES                 (0)
#define FREE_BITMAP_ANRC1_BYTES                 (0)
#define FREE_BITMAP_PBC1_BYTES                  (0)
#define FREE_BITMAP_GRP1_BYTES                  (0)
#define FREE_BITMAP_UID1_BYTES                  (0)
#define FREE_BITMAP_EMAIL1_BYTES                (0)
#define FREE_BITMAP_AAS_BYTES                   (0)
#define FREE_BITMAP_GAS_BYTES                   (0)

extern kal_uint16 const data_desc_bytes[];

#endif /* _PHB_CONFIG_H */ 

