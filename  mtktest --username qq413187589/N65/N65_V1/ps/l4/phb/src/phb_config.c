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
 * phb_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_CONFIG_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"
#include "nvram_data_items.h"
#include "phb_config.h"

/* The order here must be synchronous with data_desc_enum of data_desc.h */
kal_uint16 const data_desc_bytes[] = 
{
#ifdef __USIM_SUPPORT__
    FREE_BITMAP_ECC_BYTES,  /* DATA_DESC_ECC */
#endif
#ifdef __PHB_USIM_SUPPORT__
    FREE_BITMAP_IAP_BYTES,
    FREE_BITMAP_SNE_BYTES,
    FREE_BITMAP_ANRA_BYTES,
    FREE_BITMAP_ANRB_BYTES,
    FREE_BITMAP_ANRC_BYTES,
    FREE_BITMAP_PBC_BYTES,
    FREE_BITMAP_GRP_BYTES,
    FREE_BITMAP_UID_BYTES,
    FREE_BITMAP_EMAIL_BYTES,
    FREE_BITMAP_IAP1_BYTES, /* 10 */
    FREE_BITMAP_ADN1_BYTES,
    FREE_BITMAP_SNE1_BYTES,
    FREE_BITMAP_ANRA1_BYTES,
    FREE_BITMAP_ANRB1_BYTES,
    FREE_BITMAP_ANRC1_BYTES,
    FREE_BITMAP_PBC1_BYTES,
    FREE_BITMAP_GRP1_BYTES,
    FREE_BITMAP_UID1_BYTES,
    FREE_BITMAP_EMAIL1_BYTES,
    FREE_BITMAP_AAS_BYTES,
    FREE_BITMAP_GAS_BYTES,
#endif /* __PHB_USIM_SUPPORT__ */ 
    FREE_BITMAP_ADN_BYTES,
    FREE_BITMAP_EXT1_BYTES,
    FREE_BITMAP_NVRAM_PHB_BYTES,
    FREE_BITMAP_FDN_BYTES,
    FREE_BITMAP_BDN_BYTES,
    FREE_BITMAP_MSISDN_BYTES,
    FREE_BITMAP_SDN_BYTES,
    FREE_BITMAP_EXT2_BYTES,
    FREE_BITMAP_EXT3_BYTES,
    FREE_BITMAP_EXT4_BYTES,
};

#ifdef __GEMINI__
/* Since MSISDN is 1 to 1 mapping, and SDN, EXT3 is read only, free-bitmap is not needed, thus saves memory consumption */
#if (FREE_BITMAP_NVRAM_PHB_BYTES)
kal_uint8 free_bitmap_NVRAM_PHB[FREE_BITMAP_NVRAM_PHB_BYTES];
#else 
kal_uint8 free_bitmap_NVRAM_PHB[1];
#endif 
kal_uint8 free_bitmap_ADN[2][FREE_BITMAP_ADN_BYTES];
kal_uint8 free_bitmap_FDN[2][FREE_BITMAP_FDN_BYTES];
kal_uint8 free_bitmap_BDN[2][FREE_BITMAP_BDN_BYTES];
kal_uint8 free_bitmap_MSISDN[2][FREE_BITMAP_MSISDN_BYTES];
kal_uint8 free_bitmap_EXT1[2][FREE_BITMAP_EXT1_BYTES];
kal_uint8 free_bitmap_EXT2[2][FREE_BITMAP_EXT2_BYTES];
kal_uint8 free_bitmap_EXT4[2][FREE_BITMAP_EXT4_BYTES];

#ifdef __PHB_USIM_SUPPORT__
kal_uint8 free_bitmap_EMAIL[2][FREE_BITMAP_EMAIL_BYTES];
#endif 

#else /* __GEMINI__*/

/* Since MSISDN is 1 to 1 mapping, and SDN, EXT3 is read only, free-bitmap is not needed, thus saves memory consumption */
#if (FREE_BITMAP_NVRAM_PHB_BYTES)
kal_uint8 free_bitmap_NVRAM_PHB[FREE_BITMAP_NVRAM_PHB_BYTES];
#else 
kal_uint8 free_bitmap_NVRAM_PHB[1];
#endif 
kal_uint8 free_bitmap_ADN[FREE_BITMAP_ADN_BYTES];
kal_uint8 free_bitmap_FDN[FREE_BITMAP_FDN_BYTES];
kal_uint8 free_bitmap_BDN[FREE_BITMAP_BDN_BYTES];
kal_uint8 free_bitmap_MSISDN[FREE_BITMAP_MSISDN_BYTES];
kal_uint8 free_bitmap_EXT1[FREE_BITMAP_EXT1_BYTES];
kal_uint8 free_bitmap_EXT2[FREE_BITMAP_EXT2_BYTES];
kal_uint8 free_bitmap_EXT4[FREE_BITMAP_EXT4_BYTES];

#ifdef __PHB_USIM_SUPPORT__
kal_uint8 free_bitmap_EMAIL[FREE_BITMAP_EMAIL_BYTES];
#endif 

#endif /* __GEMINI__ */
