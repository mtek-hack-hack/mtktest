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
 * phb_se.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the data descriptor. It maintains number of records, record size, free count,
 *   bits of the bitmap, free list implemented in bitmap.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <string.h>

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "kal_trace.h"
#include "phb_trc.h"

/* include the LID */
// #include "nvram_data_items.h"
#include "nvram_user_defs.h"

#include "sim_common_enums.h"
#include "l4c_common_enum.h"
#ifdef __MCD__
#include "mcd_l3_inc_struct.h"
#endif
#include "l4c_utility.h"  /* for l4c_is_src_from_rmmi */

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

#include "nvram_data_items.h"
#include "phb_config.h"
#include "phb_utils.h"

#include "phb_handler_read.h"
#include "phb_se.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_SE_C_

#define SIG_DIGITS      6
#define SIG_MOD_VAL     10000000
#define SIG_DIV_VAL     10000
#define SIG_WIDTH_VAL   255

#define COUNTRYCODE_ELEMENT_COUNT sizeof(countrycode) / sizeof(countrycode[0])

/* Defines memory allocation of name_num_index for PHB, FDN, and BDN */
#ifdef __GEMINI__
#ifdef __PHB_SORT_ENABLE__
/* memory allocation of indexing structure (name_num_index) for PHB */
data_entry_struct data_entry_table_PHB[2][PHB_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_PHB[2][PHB_INDEX_MAX_ENTRIES_COUNT];
pindex_struct num_index_PHB[2][PHB_INDEX_MAX_ENTRIES_COUNT];
#endif /* __PHB_SORT_ENABLE__ */

ext_index_struct *ext_index_table;
ext_index_struct ext_index_table_context[2][EXT1_MAX_ENTRIES_COUNT];

#ifdef __PHB_USIM_SUPPORT__
kal_uint8 *anr_index_table;
kal_uint8 anr_index_table_context[2][ANR_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
kal_uint8 *email_index_table;
kal_uint8 email_index_table_context[2][EMAIL_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
kal_uint8 *sne_index_table;
kal_uint8 sne_index_table_context[2][SNE_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
#endif /* __PHB_USIM_SUPPORT__ */ 

/* memory allocation of indexing structure (name_num_index) for FDN */
data_entry_struct data_entry_table_FDN[2][FDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_FDN[2][FDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct num_index_FDN[2][FDN_INDEX_MAX_ENTRIES_COUNT];

/* memory allocation of indexing structure (name_num_index) for BDN */
data_entry_struct data_entry_table_BDN[2][BDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_BDN[2][BDN_INDEX_MAX_ENTRIES_COUNT];
#else /* __GEMINI__ */
#ifdef __PHB_SORT_ENABLE__
/* memory allocation of indexing structure (name_num_index) for PHB */
data_entry_struct data_entry_table_PHB[PHB_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_PHB[PHB_INDEX_MAX_ENTRIES_COUNT];
pindex_struct num_index_PHB[PHB_INDEX_MAX_ENTRIES_COUNT];
#endif /* __PHB_SORT_ENABLE__ */ 

ext_index_struct ext_index_table[EXT1_MAX_ENTRIES_COUNT];

#ifdef __PHB_USIM_SUPPORT__
kal_uint8 anr_index_table[ANR_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
kal_uint8 email_index_table[EMAIL_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
kal_uint8 sne_index_table[SNE_INDEX_MAX_ENTRIES_COUNT] = {0xFF};
#endif /* __PHB_USIM_SUPPORT__ */ 

/* memory allocation of indexing structure (name_num_index) for FDN */
data_entry_struct data_entry_table_FDN[FDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_FDN[FDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct num_index_FDN[FDN_INDEX_MAX_ENTRIES_COUNT];

/* memory allocation of indexing structure (name_num_index) for BDN */
data_entry_struct data_entry_table_BDN[BDN_INDEX_MAX_ENTRIES_COUNT];
pindex_struct name_index_BDN[BDN_INDEX_MAX_ENTRIES_COUNT];
#endif /* __GEMINI__ */
/* NOTE: BDN NEED NOT support num_index */

static kal_uint16 phb_binary_search_country_code(kal_uint8 *bcd_array);
static kal_uint8 phb_se_cal_signature_num(kal_uint8 ton_npi, kal_uint8 *bcd_array, kal_uint8 length, kal_uint8 *num);

extern kal_uint8 convert_to_digit(kal_uint8 *source, kal_uint8 *dest);
#ifdef __PHB_USIM_SUPPORT__
extern kal_bool is_usim_type(void);
#endif

/* Solution for PinYin sorting hang problem */

#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
#ifdef __GEMINI__
alpha_id_type *alpha_id_pinyin_PHB;
alpha_id_type alpha_id_pinyin_PHB_context[2][PHB_INDEX_MAX_ENTRIES_COUNT];
#else /* __GEMINI__ */
alpha_id_type alpha_id_pinyin_PHB[PHB_INDEX_MAX_ENTRIES_COUNT];
#endif /* __GEMINI__ */
#endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */

/*****************************************************************************
 * FUNCTION
 *  phb_se_new
 * DESCRIPTION
 *  Constructor of the Search Engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_new()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index;
#ifdef __GEMINI__
    kal_uint8 i = 0;
#endif /* __GEMINI__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   kal_trace(TRACE_FUNC, FUNC_PHB_SE_NEW); */
#ifdef __GEMINI__
    if (phb_current_mod == MOD_PHB)
    {
        i = 0;
    }
    else if (phb_current_mod == MOD_PHB_2)
    {
        i = 1;
    }
    else
    {
        ASSERT(0);
    }
#ifdef __PHB_SORT_ENABLE__
    name_num_index = &phb_ptr->indices.phb_index;
    name_num_index->data_entry_table.table = data_entry_table_PHB[i];
    name_num_index->name_index.table = name_index_PHB[i];
    name_num_index->num_index.table = num_index_PHB[i];
    phb_name_num_index_new(name_num_index, PHB_INDEX_MAX_ENTRIES_COUNT);
#endif /* __PHB_SORT_ENABLE__ */ 
    kal_mem_set(ext_index_table_context[i], (kal_uint8) PHB_INVALID_VALUE, EXT1_MAX_ENTRIES_COUNT * sizeof(ext_index_struct));

    name_num_index = &phb_ptr->indices.fdn_index;
    phb_ptr->indices.fdn_index.data_entry_table.table = data_entry_table_FDN[i];
    phb_ptr->indices.fdn_index.name_index.table = name_index_FDN[i];
    phb_ptr->indices.fdn_index.num_index.table = num_index_FDN[i];
    phb_name_num_index_new(name_num_index, FDN_INDEX_MAX_ENTRIES_COUNT);

    name_num_index = &phb_ptr->indices.bdn_index;
    name_num_index->data_entry_table.table = data_entry_table_BDN[i];
    name_num_index->name_index.table = name_index_BDN[i];
    name_num_index->num_index.table = NULL; /* BDN need NOT num_index */

    phb_name_num_index_new(name_num_index, BDN_INDEX_MAX_ENTRIES_COUNT);
#else /* __GEMINI__ */
#ifdef __PHB_SORT_ENABLE__
    name_num_index = &phb_ptr->indices.phb_index;
    name_num_index->data_entry_table.table = &data_entry_table_PHB[0];
    name_num_index->name_index.table = &name_index_PHB[0];
    name_num_index->num_index.table = &num_index_PHB[0];
    phb_name_num_index_new(name_num_index, PHB_INDEX_MAX_ENTRIES_COUNT);
#endif /* __PHB_SORT_ENABLE__ */ 
    kal_mem_set(&ext_index_table[0], (kal_uint8) PHB_INVALID_VALUE, EXT1_MAX_ENTRIES_COUNT * sizeof(ext_index_struct));

    name_num_index = &phb_ptr->indices.fdn_index;
    phb_ptr->indices.fdn_index.data_entry_table.table = &data_entry_table_FDN[0];
    phb_ptr->indices.fdn_index.name_index.table = &name_index_FDN[0];
    phb_ptr->indices.fdn_index.num_index.table = &num_index_FDN[0];
    phb_name_num_index_new(name_num_index, FDN_INDEX_MAX_ENTRIES_COUNT);

    name_num_index = &phb_ptr->indices.bdn_index;
    name_num_index->data_entry_table.table = &data_entry_table_BDN[0];
    name_num_index->name_index.table = &name_index_BDN[0];
    name_num_index->num_index.table = NULL; /* BDN need NOT num_index */

    phb_name_num_index_new(name_num_index, BDN_INDEX_MAX_ENTRIES_COUNT);
#endif /* __GEMINI__ */
}   /* end of phb_se_new */


/*****************************************************************************
 * FUNCTION
 *  phb_se_reset
 * DESCRIPTION
 *  Reset the Search Engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_reset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_SE_RESET); */

#ifdef __PHB_SORT_ENABLE__
    phb_name_num_index_reset(&phb_ptr->indices.phb_index);
#endif 
    kal_mem_set(&ext_index_table[0], (kal_uint8) PHB_INVALID_VALUE, EXT1_MAX_ENTRIES_COUNT * sizeof(ext_index_struct));
    phb_name_num_index_reset(&phb_ptr->indices.fdn_index);
    phb_name_num_index_reset(&phb_ptr->indices.bdn_index);
}   /* end of phb_se_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_se_ext_index_set
 * DESCRIPTION
 *  Append the ext_index
 * PARAMETERS
 *  record_index        [IN]        
 *  ext_index           [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_ext_index_set(kal_uint16 record_index, kal_uint8 ext_index, phb_type_enum phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ext_index >= 1);
    if (ext_index != (kal_uint8) PHB_INVALID_VALUE)
    {
        ext_index_table[ext_index - 1].record_index = record_index;
    #ifdef __PHB_USIM_SUPPORT__
        ext_index_table[ext_index - 1].type = phb_type;
    #endif 
    }
}   /* end of phb_se_ext_index_set */


/*****************************************************************************
 * FUNCTION
 *  phb_se_ext_index_delete
 * DESCRIPTION
 *  Append the ext_index
 * PARAMETERS
 *  record_index        [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_ext_index_delete(kal_uint16 record_index, phb_type_enum phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EXT1_MAX_ENTRIES_COUNT; i++)
    {
    #ifdef __PHB_USIM_SUPPORT__
        if (ext_index_table[i].record_index == record_index && ext_index_table[i].type == phb_type)
        {
            ext_index_table[i].record_index = (kal_uint16) PHB_INVALID_VALUE;
            ext_index_table[i].type = PHB_NONE;
            return;
        }
    #else /* __PHB_USIM_SUPPORT__ */ 
        if (ext_index_table[i].record_index == record_index)
        {
            ext_index_table[i].record_index = (kal_uint16) PHB_INVALID_VALUE;
            return;
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 
    }
}   /* end of phb_se_ext_index_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_se_ext_index_find
 * DESCRIPTION
 *  Find the ext_index
 * PARAMETERS
 *  record_index        [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 phb_se_ext_index_find(kal_uint16 record_index, phb_type_enum phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        return (kal_uint8) PHB_INVALID_VALUE;
    }

    for (i = 0; i < EXT1_MAX_ENTRIES_COUNT; i++)
    {
    #ifdef __PHB_USIM_SUPPORT__
        if (ext_index_table[i].record_index == record_index && ext_index_table[i].type == phb_type)
    #else 
        if (ext_index_table[i].record_index == record_index)
    #endif 
            return (i + 1);
    }
    return (kal_uint8) PHB_INVALID_VALUE;
}

#ifdef __PHB_USIM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  phb_se_iap_index_set
 * DESCRIPTION
 *  Append the ext_index
 * PARAMETERS
 *  adn_index       [IN]        
 *  data_index      [IN]        
 *  data_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_iap_index_set(kal_uint16 adn_index, kal_uint8 data_index, data_desc_enum data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data_index >= 1);
    if (data_type == DATA_DESC_ANRA)
    {
        anr_index_table[data_index - 1] = adn_index;
    }
    else if (data_type == DATA_DESC_EMAIL)
    {
        email_index_table[data_index - 1] = adn_index;
    }
    else if (data_type == DATA_DESC_SNE)
    {
        sne_index_table[data_index - 1] = adn_index;
    }
    else
    {
        ASSERT(0);
    }
}   /* end of phb_se_iap_index_set */


/*****************************************************************************
 * FUNCTION
 *  phb_se_iap_index_delete
 * DESCRIPTION
 *  Append the ext_index
 * PARAMETERS
 *  adn_index       [IN]        
 *  data_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_iap_index_delete(kal_uint16 adn_index, phb_type_enum data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(adn_index >= 1);
    if (data_type == DATA_DESC_ANRA)
    {
        for (i = 0; i < ANR_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (anr_index_table[i] == adn_index)
            {
                anr_index_table[i] = (kal_uint8) PHB_INVALID_VALUE;
                return;
            }
        }
    }
    else if (data_type == DATA_DESC_EMAIL)
    {
        for (i = 0; i < EMAIL_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (email_index_table[i] == adn_index)
            {
                email_index_table[i] = (kal_uint8) PHB_INVALID_VALUE;
                return;
            }
        }
    }
    else if (data_type == DATA_DESC_SNE)
    {
        for (i = 0; i < SNE_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (sne_index_table[i] == adn_index)
            {
                sne_index_table[i] = (kal_uint8) PHB_INVALID_VALUE;
                return;
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}   /* end of phb_se_iap_index_append */


/*****************************************************************************
 * FUNCTION
 *  phb_se_iap_index_find
 * DESCRIPTION
 *  Find the ext_index
 * PARAMETERS
 *  adn_index       [IN]        
 *  data_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_se_iap_index_find(kal_uint16 adn_index, data_desc_enum data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (adn_index == (kal_uint16) PHB_INVALID_VALUE || adn_index == 0)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    if (data_type == DATA_DESC_ANRA)
    {
        for (i = 0; i < ANR_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (anr_index_table[i] == adn_index)
            {
                return (i + 1);
            }
        }
    }
    else if (data_type == DATA_DESC_EMAIL)
    {
        for (i = 0; i < EMAIL_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (email_index_table[i] == adn_index)
            {
                return (i + 1);
            }
        }
    }
    else if (data_type == DATA_DESC_SNE)
    {
        for (i = 0; i < SNE_INDEX_MAX_ENTRIES_COUNT; i++)
        {
            if (sne_index_table[i] == adn_index)
            {
                return (i + 1);
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}
#endif /* __PHB_USIM_SUPPORT__ */ /* __PHB_USIM_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_index_values
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  tel_number          [?]         
 *  signature           [?]         
 *  num                 [?]         
 *  name_num_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_se_get_index_values(
                phb_type_enum type,
                l4_addr_bcd_struct *tel_number,
                kal_uint8 *signature,
                kal_uint8 *num,
                name_num_index_type **name_num_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_GET_INDEX_VALUES);

#ifdef __PHB_SORT_ENABLE__
    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
#else 
    if ((type == PHB_FDN) || (type == PHB_BDN))
#endif 
    {

      /**
       * Because FDN matching is prefix matching,
       * telephone number sorting of FDN is according to first 2 digits,
       * and signature is not used.
       */
        if (type == PHB_FDN)
        {
            *name_num_index = &phb_ptr->indices.fdn_index;
            *signature = (kal_uint8) PHB_INVALID_VALUE;
            *num = tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET];
        }
        /* (type == PHB_PHONEBOOK) ||(type == PHB_BDN) */
        else
        {
        #ifdef __PHB_SORT_ENABLE__      /* support phonebook sort only no MMI */
            /* Telephone number sorting of PHONEBOOK is according to last 2 digits. */
            if (type == PHB_PHONEBOOK)
            {
                *name_num_index = &phb_ptr->indices.phb_index;
            }

            else if (type == PHB_BDN)
        #endif /* __PHB_SORT_ENABLE__ */ 
                *name_num_index = &phb_ptr->indices.bdn_index;

            *signature = phb_se_cal_signature_num(
                            tel_number->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET],
                            &tel_number->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (kal_uint8) (tel_number->addr_length - L4_ADDR_BCD_TEL_NUM_OFFSET),
                            num);
        }
    }
}   /* end of phb_se_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_se_build_index_convert_name
 * DESCRIPTION
 *  Build index of certain type
 * PARAMETERS
 *  pNameString     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
/* 20030202 Wilson, temporary solution for PinYin sorting hang problem */
#if defined(__PINYIN_SORTING_ZI__)

#elif  defined(__PINYIN_SORTING_KA__)
extern const signed char *GetPYString(unsigned char *HZ);
#endif 

#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
void phb_se_build_index_convert_name(kal_uint8 *pNameString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 in_count, out_count, i;
    kal_uint8 InputString[32];  /* Original Input String, Should be the same as L4_MAX_NAME or smaller */
    kal_uint8 *pInputString;    /* Pointer to Original Input String */

#if defined(__PINYIN_SORTING_ZI__)
    kal_uint16 code;
    kal_uint8 pResultBuffer[32 * 2];
#elif  defined(__PINYIN_SORTING_KA__)
    kal_uint8 code[2];
    const kal_int8 *pResultBuffer;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(InputString, pNameString, 32);
    memset(pNameString, 0, 32);
    pInputString = (kal_uint8*) InputString;
    in_count = out_count = 0;

    while (!((*pInputString == 0) && (*(pInputString + 1) == 0)) && in_count < 32)
    {

    #if defined(__PINYIN_SORTING_ZI__)
        code = *((kal_uint16*) pInputString);
        code = (code << 8) | (code >> 8);
        if ((code >= 0x4e00) && (code <= 0x9fa5) && Zi8GetCharInfo(code, (kal_uint16*) pResultBuffer, 32 * 2, 1))
    #elif defined(__PINYIN_SORTING_KA__)
        code[0] = pInputString[1];
        code[1] = pInputString[0];
        if ((pResultBuffer = GetPYString(code)) != NULL)
    #endif 
        {   /* A Chinese, convert to its PinYin string */
            i = 0;
            while ((pResultBuffer[i] != 0x00) && (out_count < 32) && (i < 32 * 2))
            {
                pNameString[out_count] = pResultBuffer[i];
                out_count++;
            #if defined(__PINYIN_SORTING_ZI__)
                i = i + 2;
            #elif defined(__PINYIN_SORTING_KA__)
                i = i + 1;
            #endif 
            }
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            pNameString[out_count++] = 0x20;
        #endif 
        }
        else    // if(*pInputString == 0)   /*NOT a Chinese character, Is a ASCII character. Ex. 'A' "0x0041"*/
        {
            pNameString[out_count] = *(pInputString + 1);
            out_count++;
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            pNameString[out_count++] = 0x20;
        #endif 
        }

        in_count += 2;
        pInputString += 2;
    }

}
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 


/*****************************************************************************
 * FUNCTION
 *  phb_se_build_index
 * DESCRIPTION
 *  Build index of certain type
 * PARAMETERS
 *  type                [IN]        
 *  record_index        [IN]        
 *  ext_index           [IN]        
 *  phb_entry           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_build_index(phb_type_enum type, kal_uint16 record_index, kal_uint8 ext_index, phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* 20040223 Wilson, temporary solution for PinYin sorting hang problem */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)

    kal_uint8 temp_name_length;
    kal_uint8 temp_name[PHB_ALPHA_ID_DEPTH];
    kal_uint8 is_convert = 0;
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_BUILD_INDEX);
    if (ext_index == 0)
    {
        ext_index = (kal_uint8) PHB_INVALID_VALUE;
    }
    if (type == PHB_PHONEBOOK && ext_index != (kal_uint8) PHB_INVALID_VALUE)
    {
        phb_se_ext_index_set(record_index, ext_index, type);
    }
#ifdef __PHB_SORT_ENABLE__
    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
#else 
    if ((type == PHB_FDN) || (type == PHB_BDN))
#endif 
    {
        kal_uint16 data_entry_pos;

        kal_uint8 signature;
        kal_uint8 tel_num;
        name_num_index_type *name_num_index;

        phb_se_get_index_values(type, &phb_entry->tel_number, &signature, &tel_num, &name_num_index);

        /* amanda add, put number in name for sorting */
        if (phb_entry->alpha_id.name_length == 0)
        {
            kal_uint8 fake_name_bcd[15];
            kal_uint8 *temp_ptr;

            kal_mem_cpy(fake_name_bcd, &phb_entry->tel_number.addr_bcd[1], 10);
            fake_name_bcd[10] = 0xff;
            temp_ptr = phb_entry->alpha_id.name;
            phb_entry->alpha_id.name_length = 0;
            if (phb_entry->tel_number.addr_bcd[0] & 0x10)
            {
                *(temp_ptr++) = '+';
                phb_entry->alpha_id.name_length++;
            }
            phb_entry->alpha_id.name_length += convert_to_digit(fake_name_bcd, temp_ptr);
            phb_entry->alpha_id.name_dcs = PHB_ASCII;
        }
        /* Handle 0x81 case for sorting */
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_81)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 7;

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }

            phb_entry->alpha_id.name_length = count;
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            memcpy(phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);

        }
        /* Handle 0x82 case for sorting */
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_82)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 8;
            base_ptr |= phb_entry->alpha_id.name[offset++];

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }

            phb_entry->alpha_id.name_length = count;
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            memcpy(phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);

        }
    #endif /* __PHB_0x81_SUPPORT__ */ 
        /* 20040223 Wilson, temporary solution for PinYin sorting hang problem */
    #if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)

        else if (type == PHB_PHONEBOOK && phb_entry->alpha_id.name_dcs == PHB_UCS2)
        {
            kal_mem_cpy((kal_uint8*) temp_name, (kal_uint8*) phb_entry->alpha_id.name, PHB_ALPHA_ID_DEPTH);
            temp_name_length = phb_entry->alpha_id.name_length;

            phb_se_build_index_convert_name((kal_uint8*) phb_entry->alpha_id.name);
            phb_entry->alpha_id.name_length = strlen((char*)phb_entry->alpha_id.name);
            phb_entry->alpha_id.name_dcs = PHB_ASCII;

            is_convert = 1;
        }
    #endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

        data_entry_pos = phb_det_append(
                            &name_num_index->data_entry_table,
                            (alpha_id_type*) & phb_entry->alpha_id,
                            phb_entry->storage,
                            record_index,
                            signature,
                            tel_num,
                            ext_index);
        if (data_entry_pos == (kal_uint16) PHB_INVALID_VALUE)
        {
            return;
        }

        phb_pindex_append(&name_num_index->name_index, data_entry_pos);
        phb_pindex_append(&name_num_index->num_index, data_entry_pos);

        /* 20040223 Wilson, temporary solution for PinYin sorting hang problem */
    #if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)

        if (is_convert)
        {
            alpha_id_pinyin_PHB[data_entry_pos].charset = PHB_UCS2;

            if (temp_name_length < PHB_ALPHA_ID_DEPTH)
            {
                alpha_id_pinyin_PHB[data_entry_pos].length = temp_name_length;
            }
            else
            {
                alpha_id_pinyin_PHB[data_entry_pos].length = PHB_ALPHA_ID_DEPTH;
            }

            kal_mem_cpy(
                (kal_uint8*) alpha_id_pinyin_PHB[data_entry_pos].data,
                (kal_uint8*) temp_name,
                PHB_ALPHA_ID_DEPTH);
        }
        else
        {
            alpha_id_pinyin_PHB[data_entry_pos].charset = PHB_ASCII;
        }
    #endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

    }
}   /* end of phb_se_build_index */


/*****************************************************************************
 * FUNCTION
 *  phb_se_finish_build
 * DESCRIPTION
 *  Calculate signature of a telephone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_finish_build()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 20040223 Wilson, temporary solution for PinYin sorting hang problem */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    data_entry_struct *table;
    kal_uint16 i;
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_FINISH_BUILD);

    /* FDN index is not build here, since it is built when FDN is scanned */

    /* 20050408 Jo, If MMI providing sorting mechanism, it does not need to sort in L4 */
#ifdef __PHB_SORT_ENABLE__
    phb_name_num_index_sort(&phb_ptr->indices.phb_index);
#endif /* __PHB_SORT_NAME__ */
    phb_name_num_index_sort(&phb_ptr->indices.bdn_index);

    /* 20040223 Wilson, temporary solution for PinYin sorting hang problem */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)

    table = phb_ptr->indices.phb_index.data_entry_table.table;

    for (i = 0; i < phb_ptr->indices.phb_index.data_entry_table.used_count; i++)
    {
        if (alpha_id_pinyin_PHB[i].charset == PHB_UCS2)
        {
            table[i].alpha_id.charset = PHB_UCS2;
            table[i].alpha_id.length = alpha_id_pinyin_PHB[i].length;

            kal_mem_cpy(
                (kal_uint8*) table[i].alpha_id.data,
                (kal_uint8*) alpha_id_pinyin_PHB[i].data,
                PHB_ALPHA_ID_DEPTH);
        }
    }

#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 

}   /* end of phb_se_finish_build */


/*****************************************************************************
 * FUNCTION
 *  phb_se_append
 * DESCRIPTION
 *  Build index of certain type
 * PARAMETERS
 *  type                [IN]        
 *  record_index        [IN]        
 *  ext_index           [IN]        
 *  phb_entry           [?]         
 * RETURNS
 *  index inserted to internal index
 *****************************************************************************/
kal_uint16 phb_se_append(phb_type_enum type, kal_uint16 record_index, kal_uint8 ext_index, phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_APPEND);

    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
    {
        kal_bool fake_name = KAL_FALSE;
        kal_uint8 signature;
        kal_uint8 tel_num;
        kal_uint16 index;
        name_num_index_type *name_num_index;

    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        l4_name_struct temp_name;

        temp_name.name_dcs = 0;
    #endif /* __PHB_0x81_SUPPORT__ */ 

        phb_se_get_index_values(type, &phb_entry->tel_number, &signature, &tel_num, &name_num_index);

        /* amanda add, put number in name for sorting */
        if (phb_entry->alpha_id.name_length == 0)
        {
            kal_uint8 fake_name_bcd[15];
            kal_uint8 *temp_ptr;

            fake_name = KAL_TRUE;
            kal_mem_cpy(fake_name_bcd, &phb_entry->tel_number.addr_bcd[1], 10);
            fake_name_bcd[10] = 0xff;
            temp_ptr = phb_entry->alpha_id.name;
            phb_entry->alpha_id.name_length = 0;
            if (phb_entry->tel_number.addr_bcd[0] & 0x10)
            {
                *(temp_ptr++) = '+';
                phb_entry->alpha_id.name_length++;
            }
            phb_entry->alpha_id.name_length += convert_to_digit(fake_name_bcd, temp_ptr);
            phb_entry->alpha_id.name_dcs = PHB_ASCII;
        }
        /* Convert 0x81 to 0x80 in L4 for sorting. */
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_81)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            kal_mem_cpy(&temp_name, &phb_entry->alpha_id, sizeof(l4_name_struct));

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 7;

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }
            kal_mem_cpy(&phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            phb_entry->alpha_id.name_length = count;
        }
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_82)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            kal_mem_cpy(&temp_name, &phb_entry->alpha_id, sizeof(l4_name_struct));

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 8;
            base_ptr |= phb_entry->alpha_id.name[offset++];

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }
            kal_mem_cpy(&phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            phb_entry->alpha_id.name_length = count;
        }
    #endif /* __PHB_0x81_SUPPORT__ */ 
        index = phb_name_num_index_append(
                    name_num_index,
                    (alpha_id_type*) & phb_entry->alpha_id,
                    phb_entry->storage,
                    record_index,
                    signature,
                    tel_num,
                    ext_index);
        if (fake_name == KAL_TRUE)
        {
            kal_mem_set(phb_entry->alpha_id.name, 0, 30);
            phb_entry->alpha_id.name_length = 0;
        }
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        if (temp_name.name_dcs == PHB_UCS2_81 || temp_name.name_dcs == PHB_UCS2_82)
        {
            kal_mem_cpy(&phb_entry->alpha_id, &temp_name, sizeof(l4_name_struct));
        }
    #endif /* __PHB_0x81_SUPPORT__ */ 
        return index;
    }

    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_se_append */


/*****************************************************************************
 * FUNCTION
 *  phb_se_update
 * DESCRIPTION
 *  Build index of certain type
 * PARAMETERS
 *  type                [IN]        
 *  ext_index           [IN]        
 *  phb_entry           [?]         
 *  old_index           [IN]        
 *  old_ext_index       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_se_update(
            phb_type_enum type,
            kal_uint8 ext_index,
            phb_entry_struct *phb_entry,
            kal_uint16 old_index,
            kal_uint8 *old_ext_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_UPDATE);

#ifdef __PHB_SORT_ENABLE__
    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
#else 
    if ((type == PHB_FDN) || (type == PHB_BDN))
#endif 
    {
        kal_bool fake_name = KAL_FALSE;
        kal_uint8 signature;
        kal_uint8 tel_num;
        kal_uint16 index;
        name_num_index_type *name_num_index;

    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        l4_name_struct temp_name;

        temp_name.name_dcs = 0;
    #endif /* __PHB_0x81_SUPPORT__ */ 

        phb_se_get_index_values(type, &phb_entry->tel_number, &signature, &tel_num, &name_num_index);

        /* amanda add, put number in name for sorting */
        if (phb_entry->alpha_id.name_length == 0)
        {
            kal_uint8 fake_name_bcd[15];
            kal_uint8 *temp_ptr;

            fake_name = KAL_TRUE;
            kal_mem_cpy(fake_name_bcd, &phb_entry->tel_number.addr_bcd[1], 10);
            fake_name_bcd[10] = 0xff;
            temp_ptr = phb_entry->alpha_id.name;
            phb_entry->alpha_id.name_length = 0;
            if (phb_entry->tel_number.addr_bcd[0] & 0x10)
            {
                *(temp_ptr++) = '+';
                phb_entry->alpha_id.name_length++;
            }
            phb_entry->alpha_id.name_length += convert_to_digit(fake_name_bcd, temp_ptr);
            phb_entry->alpha_id.name_dcs = PHB_ASCII;
        }
        /* Convert 0x81 to 0x80 in L4 for sorting. */
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_81)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            kal_mem_cpy(&temp_name, &phb_entry->alpha_id, sizeof(l4_name_struct));

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 7;

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }
            kal_mem_cpy(&phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            phb_entry->alpha_id.name_length = count;
        }
        else if (phb_entry->alpha_id.name_dcs == PHB_UCS2_82)
        {
            kal_uint8 offset = 0;
            kal_uint8 specified_decoded_str_len;
            kal_uint16 ch;
            kal_uint16 base_ptr;
            kal_uint8 count;
            kal_uint8 result[PHB_ALPHA_ID_DEPTH];

            kal_mem_cpy(&temp_name, &phb_entry->alpha_id, sizeof(l4_name_struct));

            ++offset;
            specified_decoded_str_len = phb_entry->alpha_id.name[offset++];
            base_ptr = phb_entry->alpha_id.name[offset++] << 8;
            base_ptr |= phb_entry->alpha_id.name[offset++];

            for (count = 0; offset < phb_entry->alpha_id.name_length;)
            {
                ch = phb_entry->alpha_id.name[offset++];

                /* Exceeds capacity, truncate */
                if ((count + 1) >= PHB_ALPHA_ID_DEPTH)
                {
                    break;
                }

                /* All bytes are docoed */
                if ((count + 1) >= (specified_decoded_str_len * 2))
                {
                    break;
                }

                if (ch < 0x80)
                {
                    result[count++] = 0x0;
                    result[count++] = (kal_uint8) ch;
                }
                else
                {
                    ch &= 0x7F;
                    ch += base_ptr;

                    result[count++] = phb_more_significant_char(ch);
                    result[count++] = phb_less_significant_char(ch);
                }
            }
            kal_mem_cpy(&phb_entry->alpha_id.name, result, PHB_ALPHA_ID_DEPTH);
            phb_entry->alpha_id.name_dcs = PHB_UCS2;
            phb_entry->alpha_id.name_length = count;
        }
    #endif /* __PHB_0x81_SUPPORT__ */ 

        index = phb_name_num_index_update(
                    name_num_index,
                    old_index,
                    (alpha_id_type*) & phb_entry->alpha_id,
                    signature,
                    tel_num,
                    ext_index,
                    old_ext_index);
        if (fake_name == KAL_TRUE)
        {
            kal_mem_set(phb_entry->alpha_id.name, 0, 30);
            phb_entry->alpha_id.name_length = 0;
        }
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        if (temp_name.name_dcs == PHB_UCS2_81 || temp_name.name_dcs == PHB_UCS2_82)
        {
            kal_mem_cpy(&phb_entry->alpha_id, &temp_name, sizeof(l4_name_struct));
        }
    #endif /* __PHB_0x81_SUPPORT__ */ 
        return index;
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_se_update */


/*****************************************************************************
 * FUNCTION
 *  phb_se_delete
 * DESCRIPTION
 *  Build index of certain type
 * PARAMETERS
 *  type            [IN]        
 *  old_index       [IN]        
 *  ext_index       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_se_delete(phb_type_enum type, kal_uint16 old_index, kal_uint8 *ext_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_DELETE);

#ifdef __PHB_SORT_ENABLE__
    if (type == PHB_PHONEBOOK)
    {
        name_num_index = &phb_ptr->indices.phb_index;
    }
    else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ 
        name_num_index = &phb_ptr->indices.fdn_index;
    else if (type == PHB_BDN)
    {
        name_num_index = &phb_ptr->indices.bdn_index;
    }

    if (name_num_index != NULL)
    {
        phb_name_num_index_delete(name_num_index, old_index, ext_index);
    }
}   /* end of phb_se_delete */


/*****************************************************************************
 * FUNCTION
 *  phb_se_search_by_record_index_name
 * DESCRIPTION
 *  Find a exact match of record index, using name to speed up searching.
 *  
 *  If alpha_id is NULL, this function performs linear searching
 *  on name_num_index to look up given record_index.
 * PARAMETERS
 *  type                [IN]        
 *  storage             [IN]        
 *  record_index        [IN]        
 *  alpha_id            [?]         
 * RETURNS
 *  Index (to name_index) of matched record_index.
 *****************************************************************************/
kal_uint16 phb_se_search_by_record_index_name(
            phb_type_enum type,
            phb_storage_enum storage,
            kal_uint16 record_index,
            alpha_id_type *alpha_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index;
    compare_result_type result;

    kal_uint8 len = 0;
    kal_uint16 candidate_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SEARCH_BY_RECORD_INDEX_NAME);

#ifdef __PHB_SORT_ENABLE__
    if (type == PHB_PHONEBOOK)
    {
        name_num_index = &phb_ptr->indices.phb_index;
    }
    else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ 
        name_num_index = &phb_ptr->indices.fdn_index;
    else if (type == PHB_BDN)
    {
        name_num_index = &phb_ptr->indices.bdn_index;
    }
    else
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    if (alpha_id != NULL)
    {
        /* Max searching length is PHB_ALPHA_ID_DEPTH */
        len = alpha_id->length;
        if (len > PHB_ALPHA_ID_DEPTH)
        {
            alpha_id->length = PHB_ALPHA_ID_DEPTH;
        }

        /* Find first hit by using binary search */
        candidate_index = phb_name_num_index_find_index_by_alpha_id(name_num_index, alpha_id);

        /* Not found..Impossible, because a nearest neighbor should be returned */
        if (candidate_index == (kal_uint16) PHB_INVALID_VALUE)
        {
            /* Restore length */
            alpha_id->length = len;

            return (kal_uint16) PHB_INVALID_VALUE;
        }
    }
    else
    {
        candidate_index = 0;
    }

   /**
    * Since names (truncated) are sorted and thus they are grouped together,
    * linear searching can be started from first candidate,
    * try to matching record_index of each candidate.
    * Once found, its index should be set to confirmation primitive.
    */
    for (; (candidate_index < name_num_index->data_entry_table.used_count); ++(candidate_index))
    {
        pindex_struct position;

        if ((name_num_index->data_entry_table.table[name_num_index->name_index.table[candidate_index].position].
             storage == storage) &&
            (name_num_index->data_entry_table.table[name_num_index->name_index.table[candidate_index].position].
             record_index == record_index))
        {
            /* Restore length */
            if (alpha_id)
            {
                alpha_id->length = len;
            }
            return candidate_index;
        }

        if (alpha_id != NULL)
        {
            position.position = name_num_index->name_index.table[candidate_index].position;
            phb_compare_by_alpha_id(&name_num_index->data_entry_table, alpha_id, &position, &result);

            /* No more candidates */
            if (result.distance != 0)
            {
                break;
            }
        }
    }

    /* Restore length */
    alpha_id->length = len;

    /* No found? Impossible! */
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_se_search_by_record_index_name */


/*****************************************************************************
 * FUNCTION
 *  phb_se_is_next_also_candidate
 * DESCRIPTION
 *  Determines whether next candidate is also a candidate.
 * PARAMETERS
 *  name_num_index      [?]         
 *  candidate_index     [IN]        
 *  is_byname           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_se_is_next_also_candidate(
            name_num_index_type *name_num_index,
            kal_uint16 candidate_index,
            kal_bool is_byname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    compare_result_type result;

    pindex_struct candidate_position;
    pindex_struct next_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_IS_NEXT_ALSO_CANDIDATE);

    /* BYNAME */
    if ((is_byname == KAL_TRUE) && (candidate_index < (name_num_index->name_index.used_count - 1)))
    {
        candidate_position.position = name_num_index->name_index.table[candidate_index].position;
        next_position.position = name_num_index->name_index.table[candidate_index + 1].position;

        phb_compare_by_alpha_id_for_sort(
            &name_num_index->data_entry_table,
            &candidate_position,
            &next_position,
            &result);

        if (result.distance == 0)
        {
            return KAL_TRUE;
        }
    }
    /* BYNUMBER */
    else if ((is_byname == KAL_FALSE) && (candidate_index < name_num_index->num_index.used_count - 1))
    {
        candidate_position.position = name_num_index->num_index.table[candidate_index].position;
        next_position.position = name_num_index->num_index.table[candidate_index + 1].position;

        phb_compare_by_tel_num_sig_for_sort(
            &name_num_index->data_entry_table,
            &candidate_position,
            &next_position,
            &result);

        if (result.distance == 0)
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}   /* end of phb_search_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_se_search_by_name
 * DESCRIPTION
 *  Search by name.
 *  This function returns the index of first candidate. Because the search behavior of PHB
 *  is fixed-length matching.
 * PARAMETERS
 *  type                        [IN]        
 *  alpha_id                    [?]         
 *  first_candidate_index       [?]         
 *  is_more_candidate           [?]         
 * RETURNS
 *  First cadidate which is index to name_index
 *****************************************************************************/
name_num_index_type *phb_se_search_by_name(
                        phb_type_enum type,
                        alpha_id_type *alpha_id,
                        kal_uint16 *first_candidate_index,
                        kal_bool *is_more_candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index;

    kal_uint8 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SEARCH_BY_NAME);

#ifdef __PHB_SORT_ENABLE__
    if (type == PHB_PHONEBOOK)
    {
        name_num_index = &phb_ptr->indices.phb_index;
    }
    else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ /* __PHB_SORT_NAME__ */
        name_num_index = &phb_ptr->indices.fdn_index;
    else if (type == PHB_BDN)
    {
        name_num_index = &phb_ptr->indices.bdn_index;
    }
    else
    {
        return NULL;
    }

    /* Max searching length is PHB_ALPHA_ID_DEPTH */
    len = alpha_id->length;
    if (len > PHB_ALPHA_ID_DEPTH)
    {
        alpha_id->length = PHB_ALPHA_ID_DEPTH;
    }

    /* Find first hit by using binary search */
    *first_candidate_index = phb_name_num_index_find_index_by_alpha_id(name_num_index, alpha_id);

   /**
    * Unless there are no entries, the nearest neighbor is ALWAYS found.
    */
    if (*first_candidate_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        *is_more_candidate = KAL_FALSE;
        return NULL;
    }

    /* MTK 2003-12-30 Wilson, Compare String again if is a UCS2 character.(Exactly Encoding match) */
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    if ((alpha_id->charset == PHB_UCS2) && (*first_candidate_index < name_num_index->name_index.used_count))
    {
        *first_candidate_index = phb_name_num_index_after_find_index_by_alpha_id(name_num_index, alpha_id, *first_candidate_index);
    }
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 
    /* END MTK */

    if (*first_candidate_index >= name_num_index->name_index.used_count)
    {
        --(*first_candidate_index);
    }

   /**
    * Condition for determining whether more candidates exist:
    * 1. For BYNAME:
    *   Since a nearest neighbor is always found, only when
    *   length of query pattern and length of pattern are both
    *   larger than ALPHA_ID_DEPTH,
    *   and stored pattern of this candidate is the same as next candidate
    *   should verify this candidate.
    *   Futhermore, when doing verification, if this candidate is not a
    *   hit, and next neighbor of this candidate also meets the
    *   condition above, proceed verification for next candidate;
    *   otherwise, a hit is found, and stop verification.
    *
    * 2. For BYNUMBER:
    *   As long as both of signature and 2 digits of telephone number
    *   are the same as query pattern, the candidate has to be verified.
    *   If hit, temporarily stores it, and proceeds for next candidate,
    *   until there are no candidates.
    */
    if ((name_num_index->data_entry_table.used_count > 0) && (len > PHB_ALPHA_ID_DEPTH))
    {
        data_entry_struct *data_entry;

        data_entry =
            &name_num_index->data_entry_table.table[name_num_index->name_index.table[*first_candidate_index].position];
        if (data_entry->alpha_id.length >= PHB_ALPHA_ID_DEPTH)
        {
            compare_result_type result;

            phb_compare_by_key_alpha_id(alpha_id, &data_entry->alpha_id, &result);
            if ((result.distance == 0) &&
                (phb_se_is_next_also_candidate(name_num_index, *first_candidate_index, KAL_TRUE)))
            {
                *is_more_candidate = KAL_TRUE;
            }
        }
    }
    else
    {
        *is_more_candidate = KAL_FALSE;
    }

    /* Restore length */
    alpha_id->length = len;

    return name_num_index;
}   /* end of phb_se_search_by_name */


/*****************************************************************************
 * FUNCTION
 *  phb_se_compare_tel_number_with_first_character
 * DESCRIPTION
 *  compare tel number with first character.
 * PARAMETERS
 *  type        [IN]        
 *  tel_num     [?]         
 *  first_candidate_index       [?]         
 *  is_more_candidate           [?]         
 * RETURNS
 *  First cadidate which is index to num_index
 *  For PHB_BYNUMBER, could return NULL if no candidate found.
 *****************************************************************************/
name_num_index_type *phb_se_compare_tel_number_with_first_character(
                        phb_type_enum type,
                        l4_addr_bcd_struct *tel_num,
                        kal_uint16 *first_candidate_index,
                        kal_bool *is_more_candidate)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index;
    kal_uint8 num;
    kal_uint8 signature;
    kal_uint16 position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SEARCH_BY_TEL_NUM);

#ifdef __PHB_SORT_ENABLE__
    if ((type != PHB_PHONEBOOK) && (type != PHB_FDN) && (type != PHB_BDN))
#else 
    if ((type != PHB_FDN) && (type != PHB_BDN))
#endif 
    {
        return NULL;
    }
    else
    {
        phb_se_get_index_values(type, tel_num, &signature, &num, &name_num_index);
        num |= 0xf0;
        *first_candidate_index = phb_name_num_index_find_index_by_num_sig(name_num_index, signature, num);
    }

   /**
    * Unless there are no entries, the nearest neighbor is ALWAYS found.
    */
    if (*first_candidate_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        *is_more_candidate = KAL_FALSE;
        return NULL;
    }

    position = name_num_index->num_index.table[*first_candidate_index].position;
    if (*first_candidate_index >= name_num_index->num_index.used_count)
    {
        --(*first_candidate_index);
    }

   /**
    * verification the first character only.
    */
    if (((name_num_index->data_entry_table.table[position].tel_num & 0xf0) == 0xf0) &&
        (name_num_index->data_entry_table.table[position].tel_num == num))
    {
        *is_more_candidate = phb_se_is_next_also_candidate(name_num_index, *first_candidate_index, KAL_FALSE);
        return name_num_index;
    }
    return NULL;
}   /* phb_se_compare_tel_number_with_first_character */


/*****************************************************************************
 * FUNCTION
 *  phb_se_search_by_tel_num
 * DESCRIPTION
 *  Search by tel number.
 * PARAMETERS
 *  type                        [IN]        
 *  tel_num                     [?]         
 *  first_candidate_index       [?]         
 *  is_more_candidate           [?]         
 * RETURNS
 *  First cadidate which is index to num_index
 *  For PHB_BYNUMBER, could return NULL if no candidate found.
 *****************************************************************************/
name_num_index_type *phb_se_search_by_tel_num(
                        phb_type_enum type,
                        l4_addr_bcd_struct *tel_num,
                        kal_uint16 *first_candidate_index,
                        kal_bool *is_more_candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    name_num_index_type *name_num_index;
    kal_uint8 num;
    kal_uint8 signature;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SEARCH_BY_TEL_NUM);

#ifdef __PHB_SORT_ENABLE__
    if ((type != PHB_PHONEBOOK) && (type != PHB_FDN) && (type != PHB_BDN))
#else 
    if ((type != PHB_FDN) && (type != PHB_BDN))
#endif 
    {
        *is_more_candidate = KAL_FALSE;
        return NULL;
    }
    else
    {
        phb_se_get_index_values(type, tel_num, &signature, &num, &name_num_index);

        *first_candidate_index = phb_name_num_index_find_index_by_num_sig(name_num_index, signature, num);
    }

   /**
    * Unless there are no entries, the nearest neighbor is ALWAYS found.
    */
    if (*first_candidate_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        *is_more_candidate = KAL_FALSE;
        return NULL;
    }

    if (*first_candidate_index >= name_num_index->num_index.used_count)
    {
        --(*first_candidate_index);
    }

   /**
    * Since search of PHB_BYNUMBER is exact matching,
    * verification is needed.
    */
    else if ((name_num_index->data_entry_table.used_count == 0) ||
             (name_num_index->data_entry_table.table[name_num_index->num_index.table[*first_candidate_index].position].
              tel_num != num) ||
             (name_num_index->data_entry_table.table[name_num_index->num_index.table[*first_candidate_index].position].
              tel_num_sig != signature))
    {
        *first_candidate_index = (kal_uint16) PHB_INVALID_VALUE;
        return NULL;
    }

    *is_more_candidate = phb_se_is_next_also_candidate(name_num_index, *first_candidate_index, KAL_FALSE);

    return name_num_index;
}   /* end of phb_se_search_by_tel_num */


/*****************************************************************************
 * FUNCTION
 *  phb_se_cal_signature_num
 * DESCRIPTION
 *  Calculate signature of a telephone number by using Mid-Square hash function.
 * PARAMETERS
 *  ton_npi         [IN]        
 *  bcd_array       [?]         
 *  length          [IN]        
 *  num             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint8 phb_se_cal_signature_num(kal_uint8 ton_npi, kal_uint8 *bcd_array, kal_uint8 length, kal_uint8 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 position, cc_offset;
    kal_bool is_first = KAL_TRUE;
    kal_uint8 digit = 0;
    unsigned long value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_CAL_SIGNATURE_NUM);

    /* NPI should be unknow(0) or E.164 ISDN/telephony numbering plan(1) */

    /* TON is international */
    if (FETCH_TON(ton_npi) == TON_INTERNATIONAL)
    {
        position = phb_se_get_differntiable_digits(bcd_array, &cc_offset);
    }
    else if (phb_less_significant_nibble(bcd_array[0]) == 0)
    {
        position = 1;
    }
    else
    {
        position = 0;
    }

   /**
    * If position is even, is_first must be adjusted to false for
    * get_next_bcd_digit() to retrieve second bcd
    */
    if (position & 1)
    {
        is_first = KAL_FALSE;
    }

    /* Position is BCD-digit offset, it must be adjusted byte offset */
    position = position >> 1;

    while (position < length)
    {
        position = get_next_bcd_digit(bcd_array, position, &is_first, &digit);

        /* Hit! However, is_first and offset already shift to next position! */
        if (digit >= DN_VALID_DIGIT_LIMIT)
        {
            if (is_first == KAL_TRUE)
            {
                is_first = KAL_FALSE;
                --position;
            }
            else
            {
                is_first = KAL_TRUE;
            }
            break;
        }

        value = (unsigned long)(value * 10 + digit);
    }

   /**
    * First digit is invalid!eg, +886-p-1234, what the hell is this number?!
    * Such telephone numbers will get a 0x00, 0xFF for signature and num,
    * respectively.
    */
    if ((position == 0) && (is_first == KAL_TRUE))
    {
        *num = (kal_uint8) PHB_INVALID_VALUE;
    }

   /**
    * Invalid digit is found at first half of byte, ie, less significant nibble.
    * Fetch 2 digits in previous byte.
    */
    if (is_first == KAL_TRUE)
    {
        *num = bcd_array[position - 1];
    }

   /**
    * Invalid digit is found at second half of byte, ie, more significant nibble.
    * Fetch digit in first half of byte and second half of previous byte.
    */
    else
    {
        digit = phb_less_significant_nibble(bcd_array[position]) << 4;

        if (position > 0)
        {
            digit |= phb_more_significant_nibble(bcd_array[position - 1]);
        }

        *num = digit;
    }

    return (kal_uint8) ((((value * value) % SIG_MOD_VAL) / SIG_DIV_VAL) % SIG_WIDTH_VAL);
}   /* end of phb_se_build_index */


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 * RETURNS
 *  record index if success, PHB_INVALID_VALUE otherwise.
 *****************************************************************************/
kal_uint16 phb_se_get_record_index(phb_type_enum type, kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_GET_RECORD_INDEX);

#ifdef __PHB_SORT_ENABLE__
    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;

        if (type == PHB_PHONEBOOK)
        {
            name_num_index = &phb_ptr->indices.phb_index;
        }
        else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if ((type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;

        if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ /* __PHB_SORT_NAME__ */
            name_num_index = &phb_ptr->indices.fdn_index;
        else if (type == PHB_BDN)
        {
            name_num_index = &phb_ptr->indices.bdn_index;
        }

        return phb_det_get(
                &name_num_index->data_entry_table,
                phb_pindex_get_pos(&name_num_index->name_index, index))->record_index;
    }
    else
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }
}   /* end of phb_se_get_record_index */


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_index_by_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  storage             [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 phb_se_get_index_by_record_index(phb_type_enum type, phb_storage_enum storage, kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i, total, position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_SORT_ENABLE__
    if ((type == PHB_PHONEBOOK) || (type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;

        if (type == PHB_PHONEBOOK)
        {
            name_num_index = &phb_ptr->indices.phb_index;
        }
        else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if ((type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;

        if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ /* __PHB_SORT_NAME__ */
            name_num_index = &phb_ptr->indices.fdn_index;
        else if (type == PHB_BDN)
        {
            name_num_index = &phb_ptr->indices.bdn_index;
        }

        total = name_num_index->name_index.used_count;
        for (i = 0; i < total; i++)
        {
            position = name_num_index->name_index.table[i].position;
            if (name_num_index->data_entry_table.table[position].storage == storage &&
                name_num_index->data_entry_table.table[position].record_index == record_index)
            {
                break;
            }
        }
        if (i == total)
        {
            return (kal_uint16) PHB_INVALID_VALUE;
        }
        return i + 1;
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_se_is_in_range
 * DESCRIPTION
 *  Test whether given index and total in range.
 *  If total is not, enforce it.
 *  Because best-effort service is provided, if total is not in range,
 *  total will be adjusted.
 *  
 *  Note:
 *  1. ecc should not use this function.
 *  2. lower bound of index is 0.
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 *  total       [?]         
 * RETURNS
 *  KAL_TRUE if valid, KAL_FALSE else.
 *****************************************************************************/
kal_bool phb_se_is_in_range(phb_type_enum type, kal_uint16 index, kal_uint16 *total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pindex_type *pindex = NULL;
    kal_uint16 used_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_IS_IN_RANGE);

    if (type == PHB_PHONEBOOK)
    {
    #ifdef __PHB_SORT_ENABLE__
        pindex = &phb_ptr->indices.phb_index.name_index;
    #else 
        return KAL_TRUE;
    #endif 
    }
    else if (type == PHB_FDN)
    {
        pindex = &phb_ptr->indices.fdn_index.name_index;
    }
    else if (type == PHB_BDN)
    {
        pindex = &phb_ptr->indices.bdn_index.name_index;
    }

    if (pindex != NULL)
    {
        used_count = pindex->used_count;
    }
    else if (type == PHB_ECC)
    {
        used_count = phb_ptr->ecc.num_ecc;
    }
    else if (type == PHB_MSISDN)
    {
        used_count = phb_data_desc_get_record_num(DATA_DESC_MSISDN);
    }
    else if (type == PHB_SDN)
    {
        used_count = phb_data_desc_get_record_num(DATA_DESC_SDN);
    }
    else
    {
        return KAL_FALSE;
    }

    /* Nothing to read, should confirm READ_SUCCESS with total = 0 */
    if (used_count == 0)
    {
        *total = 0;
        return KAL_TRUE;
    }

    /* index begin from 1 */
    /* Cannot continue operation */
    if (index > used_count)
    {
        return KAL_FALSE;
    }

    if ((index >= 1) && (index <= used_count))
    {
      /**
       * For total = 0 request, don't reject it. Instead, confirm with result of
       * READ_SUCCESS
       */

      /**
       * total should not exceeds MAX_PHB_ENTRIES; otherwise it could
       * results in allocation of huge memory.
       */
        if (*total > PHB_MAX_PHB_ENTRIES)
        {
            *total = PHB_MAX_PHB_ENTRIES;
        }

        /* Adjust total */
        if ((index + *total) > (used_count + 1))
        {
            *total = used_count + 1 - index;
        }
        return KAL_TRUE;
    }
    return KAL_FALSE;
}   /* end of phb_se_is_in_range */


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_total_of_type
 * DESCRIPTION
 *  Get total number of entries of `type'
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  Total number of entries if success, PHB_INVALID_VALUE otherwise.
 *****************************************************************************/
kal_uint16 phb_se_get_total_of_type(phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pindex_type *pindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_GET_TOTAL_OF_TYPE);

#ifdef __PHB_SORT_ENABLE__
    if (type == PHB_PHONEBOOK)
    {
        pindex = &phb_ptr->indices.phb_index.name_index;
    }
    else if (type == PHB_FDN)
#else /* __PHB_SORT_ENABLE__ */ 
    if (type == PHB_FDN)
#endif /* __PHB_SORT_ENABLE__ */ /* __PHB_SORT_NAME__ */
        pindex = &phb_ptr->indices.fdn_index.name_index;
    else if (type == PHB_BDN)
    {
        pindex = &phb_ptr->indices.bdn_index.name_index;
    }
    else
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    return pindex->used_count;
}   /* end of phb_se_get_total_of_type */


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_differntiable_digits
 * DESCRIPTION
 *  Get offset of differentiable digits of a telephone number
 * PARAMETERS
 *  bcd_array       [IN]        The array containing BCD digits.
 *  cc_index        [OUT]       The matched country code index to `countrycode' table. If not found, this value is PHB_INVALID_VALUE.
 * RETURNS
 *  Offset of differentiable digits of a telephone number
 *****************************************************************************/
kal_uint8 phb_se_get_differntiable_digits(kal_uint8 *bcd_array, kal_uint16 *cc_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_GET_DIFFERNTIABLE_DIGITS);

    /* If this telephone number is not an international number, try to pill of its prefix */
    if ((*cc_index = phb_binary_search_country_code(bcd_array)) == (kal_uint16) PHB_INVALID_VALUE)
    {
        /* Local prefix found, pill off! */
        if (phb_less_significant_nibble(bcd_array[0]) == 0)
        {
            return 1;
        }

        /* Ok, not found, give up. */
        return 0;
    }

    /* This is an international number, pill it off! */
    return strlen(countrycode[*cc_index]);
}   /* end of phb_se_get_differntiable_digits */

char const *const countrycode[] = 
{
    "1",    /*  Canada, United States, Bahamas, Bermuda, Caribbean nations */
    "20",   /*  Egypt */
    "212",  /* Morocco */
    "213",  /* Algeria */
    "216",  /* Tunisia */
    "218",  /* Libya */
    "220",  /* Gambia */
    "221",  /* Senegal */
    "222",  /* Mauritania */
    "223",  /* Mali */
    "224",  /* Guinea */
    "225",  /* Cote d'Ivoire (Ivory Coast) */
    "226",  /* Burkina Faso */
    "227",  /* Niger */
    "228",  /* Togolese Republic */
    "229",  /* Benin */
    "230",  /* Mauritius */
    "231",  /* Liberia */
    "232",  /* Sierra Leone */
    "233",  /* Ghana */
    "234",  /* Nigeria */
    "235",  /* Chad */
    "236",  /* Central African Republic */
    "237",  /* Cameroon */
    "238",  /* Cape Verde */
    "239",  /* Sao Tome and Principe */
    "240",  /* Equatorial Guinea */
    "241",  /* Gabon */
    "242",  /* Congo */
    "243",  /* Zaire */
    "244",  /* Angola */
    "245",  /* Guinea-Bissau */
    "246",  /* Diego Garcia */
    "247",  /* Ascension */
    "248",  /* Seychelles */
    "249",  /* Sudan */
    "250",  /* Rwanda */
    "251",  /* Ethiopia */
    "252",  /* Somalia */
    "253",  /* Djibouti */
    "254",  /* Kenya */
    "255",  /* Tanzania */
    "256",  /* Uganda */
    "257",  /* Burundi */
    "258",  /* Mozambique */
    "259",  /* Zanzibar */
    "260",  /* Zambia */
    "261",  /* Madagascar */
    "262",  /* Reunion */
    "263",  /* Zimbabwe */
    "264",  /* Namibia */
    "265",  /* Malawi */
    "266",  /* Lesotho */
    "267",  /* Botswana */
    "268",  /* Swaziland */
    "269",  /* Comoros and Mayotte */
    "27",   /* South Africa */
    "290",  /* Saint Helena */
    "291",  /* Eritrea */
    "297",  /* Aruba */
    "298",  /* Faroe Islands */
    "299",  /* Greenland */
    "30",   /* Greece */
    "31",   /* Netherlands */
    "32",   /* Belgium */
    "33",   /* France */
    "34",   /* Spain */
    "350",  /* Gibraltar */
    "351",  /* Portugal */
    "352",  /* Luxembourg */
    "353",  /* Ireland */
    "354",  /* Iceland */
    "355",  /* Albania */
    "356",  /* Malta */
    "357",  /* Cyprus */
    "358",  /* Finland */
    "359",  /* Bulgaria */
    "36",   /* Hungary */
    "37",   /* (DISCONTINUED - was East Germany; 49 now used throughout Germany) */
    "370",  /* Lithuania */
    "371",  /* Latvia */
    "372",  /* Estonia */
    "373",  /* Moldova */
    "374",  /* Armenia */
    "375",  /* Belarus */
    "376",  /* Andorra */
    "377",  /* Monaco */
    "378",  /* San Marino */
    "379",  /* Vatican City */
    "38",   /* (DISCONTINUED - Yugoslavia now split into 381, 385, 386, 387, 389) */
    "380",  /* Ukraine */
    "381",  /* Yugoslavia */
    "385",  /* Croatia */
    "386",  /* Slovenia */
    "387",  /* Bosnia and Herzegovina */
    "389",  /* Macedonia (Former Yugoslav Rep.) */
    "39",   /* Italy */
    "40",   /* Romania */
    "41",   /* Switzerland and Liechtenstein */
    "42",   /* Czech and Slovak Republics */
    "43",   /* Austria */
    "44",   /* United Kingdom */
    "45",   /* Denmark */
    "46",   /* Sweden */
    "47",   /* Norway */
    "48",   /* Poland */
    "49",   /* Germany */
    "500",  /* Falkland Islands */
    "501",  /* Belize */
    "502",  /* Guatemala */
    "503",  /* El Salvador */
    "504",  /* Honduras */
    "505",  /* Nicaragua */
    "506",  /* Costa Rica */
    "507",  /* Panama */
    "508",  /* Saint Pierre and Miquelon */
    "509",  /* Haiti */
    "51",   /* Peru */
    "52",   /* Mexico */
    "53",   /* Cuba */
    "54",   /* Argentina */
    "55",   /* Brazil */
    "56",   /* Chile */
    "57",   /* Colombia */
    "58",   /* Venezuela */
    "590",  /* Guadeloupe */
    "591",  /* Bolivia */
    "592",  /* Guyana */
    "593",  /* Ecuador */
    "594",  /* Guiana */
    "595",  /* Paraguay */
    "596",  /* Martinique */
    "597",  /* Suriname */
    "598",  /* Uruguay */
    "599",  /* Netherlands Antilles */
    "60",   /* Malaysia */
    "61",   /* Australia */
    "62",   /* Indonesia */
    "63",   /* Philippines */
    "64",   /* New Zealand */
    "65",   /* Singapore */
    "66",   /* Thailand */
    "670",  /* Northern Mariana Islands */
    "671",  /* Guam */
    "672",  /* Australian External Territories */
    "673",  /* Brunei Darussalam */
    "674",  /* Nauru */
    "675",  /* Papua New Guinea */
    "676",  /* Tonga */
    "677",  /* Solomon Islands */
    "678",  /* Vanuatu */
    "679",  /* Fiji */
    "680",  /* Palau */
    "681",  /* Wallis and Futuna */
    "682",  /* Cook Islands */
    "683",  /* Niue */
    "684",  /* American Samoa */
    "685",  /* Western Samoa */
    "686",  /* Kiribati */
    "687",  /* New Caledonia */
    "688",  /* Tuvalu */
    "689",  /* French Polynesia */
    "690",  /* Tokelau */
    "691",  /* Micronesia */
    "692",  /* Marshall Islands */
    "7",    /* Russia, Kazakhstan, Tajikistan, Turkmenistan, Uzbekistan */
    "800",  /* International Freephone */
    "81",   /* Japan */
    "82",   /* Korea */
    "84",   /* Vietnam */
    "850",  /* North Korea */
    "852",  /* Hong Kong */
    "853",  /* Macau */
    "855",  /* Cambodia */
    "856",  /* Laos */
    "86",   /* China */
    "870",  /* Inmarsat: SNAC service */
    "871",  /* Inmarsat: Atlantic Ocean East */
    "872",  /* Inmarsat: Pacific Ocean */
    "873",  /* Inmarsat: Indian Ocean */
    "874",  /* Inmarsat: Atlantic Ocean West */
    "875",  /* Reserved for maritime mobile services */
    "876",  /* Reserved for maritime mobile services */
    "877",  /* Reserved for maritime mobile services */
    "878",  /* Reserved for maritime mobile services */
    "879",  /* Reserved for maritime mobile services */
    "880",  /* Bangladesh */
    "886",  /* Taiwan */
    "90",   /* Turkey */
    "91",   /* India */
    "92",   /* Pakistan */
    "93",   /* Afghanistan */
    "94",   /* Sri Lanka */
    "95",   /* Burma (Myanmar) */
    "960",  /* Maldives */
    "961",  /* Lebanon */
    "962",  /* Jordan */
    "963",  /* Syria */
    "964",  /* Iraq */
    "965",  /* Kuwait */
    "966",  /* Saudi Arabia */
    "967",  /* Yemen */
    "968",  /* Oman */
    "969",  /* (formerly South Yemen - now 967 after unification) */
    "971",  /* United Arab Emirates */
    "972",  /* Israel */
    "973",  /* Bahrain */
    "974",  /* Qatar */
    "975",  /* Bhutan */
    "976",  /* Mongolia */
    "977",  /* Nepal */
    "98",   /* Iran */
    "994",  /* Azerbaijan */
    "995",  /* Georgia */
    "996"   /* Kyrgyz Republic */
};

#define country_code_count 215


/*****************************************************************************
 * FUNCTION
 *  phb_compare_country_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  external_data       [?]         
 *  external_pos        [IN]        
 *  key                 [?]         
 * RETURNS
 *  
 *****************************************************************************/
static int phb_compare_country_code(void *external_data, int external_pos, void *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_COUNTRY_CODE);

    return compare_n_string_bcd(
            countrycode[external_pos],
            (kal_uint8*) key,
            (kal_uint16) strlen(countrycode[external_pos]));
}


/*****************************************************************************
 * FUNCTION
 *  phb_binary_search_country_code
 * DESCRIPTION
 *  Search the country code for a given bcd digits.
 * PARAMETERS
 *  bcd_array       [IN]        Array of BCD digits.
 * RETURNS
 *  If found, hit index to countrycode array is returned; otherwise PHB_INVALID_VALUE is
 *  returned.
 *****************************************************************************/
static kal_uint16 phb_binary_search_country_code(kal_uint8 *bcd_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_BINARY_SEARCH_COUNTRY_CODE);

    index = binary_search((void*)countrycode, 0, country_code_count - 1, bcd_array, phb_compare_country_code);
    if (index == -1)
    {
        return (kal_uint16) PHB_UTILS_INVALID_VALUE;
    }

    return (kal_uint16) index;
}


/*****************************************************************************
 * FUNCTION
 *  phb_se_set_control_block_for_delete
 * DESCRIPTION
 *  Set primary_ID and secondary_ID, index to record index.
 *  
 *  Note: When this function is called by phb_se_set_control_block(),
 *  for write operation, control_block->storage is already set.
 * PARAMETERS
 *  control_block       [?]         
 *  storage             [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool phb_se_set_control_block_for_delete(control_block_type *control_block, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_type_enum type = control_block->type;
    kal_uint16 index = control_block->index;
    kal_uint16 position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SET_CONTROL_BLOCK_TRANSLATE_INDEX);

    /* Types using name_num_index */
    if ((type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;
        data_entry_struct *data_entry;

        if (type == PHB_FDN)
        {
            name_num_index = &phb_ptr->indices.fdn_index;
            control_block->primary_ID = FILE_FDN_IDX;
            control_block->secondary_ID = FILE_EXT2_IDX;
        }
        else if (type == PHB_BDN)
        {
            name_num_index = &phb_ptr->indices.bdn_index;
            control_block->primary_ID = FILE_BDN_IDX;
            control_block->secondary_ID = FILE_EXT3_IDX;
        }

      /**
       * Accessing specific record is not specified, record_index and
       * storage have to be translated.
       */
      /**
       * Possible cominations are:
       * 1. OP_READ (is_specific is implicitly KAL_FALSE, and therefore index must be valid)
       *   Read case 1.
       * 2. OP_WRITE; however, even is_specific is KAL_FALSE, index may be invalid.
       *   Write case 1, 3.
       */
        if (index != (kal_uint16) PHB_INVALID_VALUE)
        {
            /* error */
            if ((position = phb_pindex_get_pos(&name_num_index->name_index, index)) == (kal_uint16) PHB_INVALID_VALUE)
            {
                return KAL_FALSE;
            }

            data_entry = phb_det_get(&name_num_index->data_entry_table, position);
         /**
          * Possibly because multiple access CONFLICT!!
          *
          * Eg, a (Read, Write)/Delete conflict.
          * Consider one delete request deletes some entries, which
          * shrinks number of entries of indices. However, another read request
          * got number of entries before indices is shrinked, and attempting to
          * read that entry. At this moment, returned data_entry could
          * be NULL!!
          *
          * For Read/Write, they would not be conflict, because
          * write request is either add or update, which only grows
          * number of entires of indices. Result of read operation
          * depends on the moment it access indices.
          */
            if (data_entry == NULL)
            {
                return KAL_FALSE;
            }

            /* For delete. Specific record is not specified and fdn need to set the storage */
            control_block->storage = data_entry->storage;
            control_block->record_index = control_block->index;
        }
      /**
       * Do some final check.
       */
        if (((type == PHB_FDN) || (type == PHB_BDN)) && (control_block->storage != PHB_SIM))
        {
            return KAL_FALSE;
        }
    }
    else if (type == PHB_PHONEBOOK)
    {
        /* data_entry_struct* data_entry; */
      /**
       * Accessing specific record is not specified, record_index and
       * storage have to be translated.
       */
     /**
      * Possible cominations are:
      * 1. OP_READ (is_specific is implicitly KAL_FALSE, and therefore index must be valid)
      *   Read case 1.
      * 2. OP_WRITE; however, even is_specific is KAL_FALSE, index may be invalid.
      *   Write case 1, 3.
      */
        if (index != (kal_uint16) PHB_INVALID_VALUE)
        {
        /**
         * Possibly because multiple access CONFLICT!!
         *
         * Eg, a (Read, Write)/Delete conflict.
         * Consider one delete request deletes some entries, which
         * shrinks number of entries of indices. However, another read request
         * got number of entries before indices is shrinked, and attempting to
         * read that entry. At this moment, returned data_entry could
         * be NULL!!
         *
         * For Read/Write, they would not be conflict, because
         * write request is either add or update, which only grows
         * number of entires of indices. Result of read operation
         * depends on the moment it access indices.
         */
            //if (data_entry == NULL)
            //   return KAL_FALSE;

            /* For delete. index is specified for record */
            control_block->storage = storage;
            control_block->record_index = control_block->index;

         /**
          * No matter whether it is accessing specific record,
          * control_block->storage should already be set now.
          */
            if (type == PHB_PHONEBOOK)
            {
                if (control_block->storage == PHB_NVRAM)
                {
                    control_block->primary_ID = NVRAM_EF_PHB_LID;
                    control_block->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                }
            #ifdef __USIM_SUPPORT__
                else if (control_block->storage == PHB_SIM && is_usim_type())
                {
                    control_block->primary_ID = FILE_G_ADN_IDX;
                    kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                    kal_mem_cpy(control_block->path + 4, phb_ptr->path[DATA_DESC_ADN], 2);
                    control_block->secondary_ID = FILE_G_EXT1_IDX;
                }
            #endif /* __USIM_SUPPORT__ */ 
                else if (control_block->storage == PHB_SIM)
                {
                    control_block->primary_ID = FILE_ADN_IDX;
                    control_block->secondary_ID = FILE_EXT1_IDX;
                }
                else
                {
                    control_block->primary_ID = (kal_uint16) PHB_NULL_VALUE;
                    control_block->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                    return KAL_FALSE;
                }
            }
            /* setup of primary ID and secondary ID complete */
        }
    }
    /* Types using 1 to 1 mapping. */
    else if ((type == PHB_MSISDN) || (type == PHB_SDN))
    {
      /**
       * For type of FDN, BDN, primary_ID, secondary_ID, and storage are
       * constant.
       */
        if (type == PHB_MSISDN)
        {
            control_block->primary_ID = FILE_MSISDN_IDX;
            control_block->secondary_ID = FILE_EXT1_IDX;
        }
        else if (type == PHB_SDN)
        {
            control_block->primary_ID = FILE_SDN_IDX;
            control_block->secondary_ID = FILE_EXT3_IDX;
        }

        /* For delete operations, storage is ignored. */
        control_block->storage = PHB_SIM;

        /* It is unnecessary to check free list. */

      /**
       * For 1 to 1 mapping EF's, index is always equal to record_index.
       */
        control_block->record_index = index;
    }
    /* error */
    else
    {
        control_block->primary_ID = (kal_uint16) PHB_INVALID_VALUE;
        control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
        control_block->storage = PHB_STORAGE_NONE;
        control_block->index = (kal_uint16) PHB_INVALID_VALUE;

        return KAL_FALSE;
    }

    return KAL_TRUE;
}   /* end of se_set_control_block_physical_storage */


/*****************************************************************************
 * FUNCTION
 *  phb_se_set_control_block_translate_index
 * DESCRIPTION
 *  Translate index to record index, if necessary.
 *  
 *  Note: When this function is called by phb_se_set_control_block(),
 *  for write operation, control_block->storage is already set.
 * PARAMETERS
 *  control_block       [?]         
 *  op                  [IN]        
 *  is_specific         [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool phb_se_set_control_block_translate_index(
                    control_block_type *control_block,
                    op_enum op,
                    kal_bool is_specific)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_type_enum type = control_block->type;
    kal_uint16 index = control_block->index;
    kal_uint16 position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SET_CONTROL_BLOCK_TRANSLATE_INDEX);

    /* Types using name_num_index */
    if ((type == PHB_PHONEBOOK) ||
#ifdef __PHB_USIM_SUPPORT__
        (type == PHB_GAS) ||
#endif 
        (type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;
        data_entry_struct *data_entry;

    #ifdef __PHB_SORT_ENABLE__
        if (type == PHB_PHONEBOOK)
        {
            name_num_index = &phb_ptr->indices.phb_index;
        }

      /**
       * For type of FDN, BDN, primary_ID, secondary_ID, and storage are
       * constant.
       */
        else if (type == PHB_FDN)
    #else /* __PHB_SORT_ENABLE__ */ 
        if (type == PHB_FDN)
    #endif /* __PHB_SORT_ENABLE__ */ 
        {
            name_num_index = &phb_ptr->indices.fdn_index;
            control_block->primary_ID = FILE_FDN_IDX;
            control_block->secondary_ID = FILE_EXT2_IDX;
        }
        else if (type == PHB_BDN)
        {
            name_num_index = &phb_ptr->indices.bdn_index;
            control_block->primary_ID = FILE_BDN_IDX;
            control_block->secondary_ID = FILE_EXT3_IDX;
        }
    #ifdef __PHB_USIM_SUPPORT__
        else if (type == PHB_GAS)
        {
            control_block->primary_ID = FILE_G_GAS_IDX;
            control_block->secondary_ID = FILE_NONE;
        }
    #endif /* __PHB_USIM_SUPPORT__ */ 

      /**
       * Accessing specific record is not specified, record_index and
       * storage have to be translated.
       */
    #ifdef __PHB_SORT_ENABLE__
        if (is_specific == KAL_FALSE)
    #else 
        if (is_specific == KAL_FALSE && type != PHB_PHONEBOOK && type != PHB_GAS)
    #endif 
        {
         /**
          * Possible cominations are:
          * 1. OP_READ (is_specific is implicitly KAL_FALSE, and therefore index must be valid)
          *   Read case 1.
          * 2. OP_WRITE; however, even is_specific is KAL_FALSE, index may be invalid.
          *   Write case 1, 3.
          */
            if (index != (kal_uint16) PHB_INVALID_VALUE)
            {
                if (l4c_is_src_from_rmmi(control_block->src_id) && control_block->type == PHB_FDN)
                {
                    if ((position = phb_det_get_pos_by_record_index(&name_num_index->data_entry_table, control_block->index)) == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        return KAL_FALSE;
                    }
                    if ((control_block->index = phb_pindex_get_index_by_position(&name_num_index->name_index, position)) == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        return KAL_FALSE;
                    }
                    control_block->index++;
                }
                else
                {                
                    /* error */
                    if ((position = phb_pindex_get_pos(&name_num_index->name_index, index)) == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        return KAL_FALSE;
                    }
                }
                data_entry = phb_det_get(&name_num_index->data_entry_table, position);
            /**
             * Possibly because multiple access CONFLICT!!
             *
             * Eg, a (Read, Write)/Delete conflict.
             * Consider one delete request deletes some entries, which
             * shrinks number of entries of indices. However, another read request
             * got number of entries before indices is shrinked, and attempting to
             * read that entry. At this moment, returned data_entry could
             * be NULL!!
             *
             * For Read/Write, they would not be conflict, because
             * write request is either add or update, which only grows
             * number of entires of indices. Result of read operation
             * depends on the moment it access indices.
             */
                if (data_entry == NULL)
                {
                    return KAL_FALSE;
                }

                /* For read, delete or write of case 3, 4. Specific record is not specified */
                if ((op == OP_READ) ||
                    (op == OP_DELETE) || (control_block->record_index == (kal_uint16) PHB_INVALID_VALUE))
                {
                    /* Read case 1 ignores storage parameter */
                    control_block->storage = data_entry->storage;
                    control_block->record_index = data_entry->record_index;
                }

            /**
             * Write case 1. Specific record and index is specified, therefore
             * user claimed record_index and storage must be verified.
             */
                if ((op == OP_WRITE) &&
                    (control_block->record_index != (kal_uint16) PHB_INVALID_VALUE) &&
                    ((control_block->storage != data_entry->storage) ||
                     (control_block->record_index != data_entry->record_index)))
                {
                    return KAL_FALSE;
                }

                /* Case 3. Nothing to be done. */
            }

        }

      /**
       * No matter whether it is accessing specific record,
       * control_block->storage should already be set now.
       */
        if (type == PHB_PHONEBOOK)
        {
            if (control_block->storage == PHB_NVRAM)
            {
                control_block->primary_ID = NVRAM_EF_PHB_LID;
                control_block->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
            }
        #ifdef __USIM_SUPPORT__
            else if (control_block->storage == PHB_SIM && is_usim_type())
            {
                control_block->primary_ID = FILE_G_ADN_IDX;
                kal_mem_cpy(control_block->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
                kal_mem_cpy(control_block->path + 4, phb_ptr->path[DATA_DESC_ADN], 2);
                control_block->secondary_ID = FILE_G_EXT1_IDX;
            }
        #endif /* __USIM_SUPPORT__ */ 
            else if (control_block->storage == PHB_SIM)
            {
                control_block->primary_ID = FILE_ADN_IDX;
                control_block->secondary_ID = FILE_EXT1_IDX;
            }
            else
            {
                control_block->primary_ID = (kal_uint16) PHB_NULL_VALUE;
                control_block->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                return KAL_FALSE;
            }
        }
        /* setup of primary ID and secondary ID complete */

        /* Since it's a write operation, free-list must be checked. */
        if (op == OP_WRITE)
        {
            /* Special case of Write case 1, 2: RMMI/AT-command */
            if (l4c_is_src_from_rmmi(control_block->src_id))
            {
                free_status_enum free_status;

                if (control_block->record_index != (kal_uint16) PHB_INVALID_VALUE)
                {
                    free_status = phb_data_desc_is_free(
                                    phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                                    control_block->record_index);
                    /**
                      * This case results from:
                      * 1. Non supported EF.
                      * 2. Attempt written record index excceds max supported capacity.
                      */
                    if (free_status == RECORD_INVALID)
                    {
                        return KAL_FALSE;
                    }

                    /* Add operation */
                    else if (free_status == RECORD_FREE)
                    {
                        control_block->index = (kal_uint16) PHB_INVALID_VALUE;
                    }

            /**
             * Update operation..
             * Cannot but look up index for user. DAMN.
             */
                    else
                    {
                        /* Lookup index to name_index for record_index. */
                        control_block->index = phb_se_search_by_record_index_name(
                                                control_block->type,
                                                control_block->storage,
                                                control_block->record_index,
                                                NULL);

               /**
                * Since it is the index to name_index(lower bound is 0),
                * increment 1.
                */
                        ++control_block->index;
                    }
                }
                else
                {
                    control_block->record_index = phb_data_desc_find_next_free(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                    if (control_block->record_index == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                        return KAL_FALSE;
                    }
                }
            }

            /* 2. Write case 1, 3, 4; however, even is_specific is KAL_FALSE, index may be invalid. */
            else if (is_specific == KAL_FALSE)
            {
                /* 'Add' operation, search for a new free record to write */
                if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
                {
                    control_block->record_index = phb_data_desc_find_next_free(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                    /* No free record found!! */
                    if (control_block->record_index == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                        return KAL_FALSE;
                    }
                }

                /* For valid control_block->index, record_index is already set!! */
            }

            /* Write case 2: Speicific record is specified by user */
            /* (is_specific == KAL_TRUE) */
            else
            {
            /**
             * Index must be scanned to prevent an exsiting record being
             * overwritten which is already indexed by search engine, but
             * user specified index field is invalid. This serious error could
             * fail PHB module. Hence, examination of free-list is needed
             * to determine whether this record_index is free.
             */

             /**
              * Not free! User specified record_index, storage are all valid,
              * and index is invalid. Suppose it is a `add' operation. However,
              * data_desc indicates that record_index is not empty.
              * A conflict!
              */
                if (phb_data_desc_is_free(
                        phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage),
                        control_block->record_index) != RECORD_FREE)
                {
                    return KAL_FALSE;
                }
            }

        }

      /**
       * Setup for primary_ID, secondary_ID and storage complete
       * Do some final check.
       */
        /* PHB_PHONEBOOK need NOT be checked, since it is checked already. */
        if (((type == PHB_FDN) || (type == PHB_BDN)) && (control_block->storage != PHB_SIM))
        {
            return KAL_FALSE;
        }
    }

    /* Types using 1 to 1 mapping. */
    else if ((type == PHB_MSISDN) || (type == PHB_SDN))
    {
      /**
       * For type of FDN, BDN, primary_ID, secondary_ID, and storage are
       * constant.
       */
        if (type == PHB_MSISDN)
        {
            control_block->primary_ID = FILE_MSISDN_IDX;
            control_block->secondary_ID = FILE_EXT1_IDX;
        }
        else if (type == PHB_SDN)
        {
            control_block->primary_ID = FILE_SDN_IDX;
            control_block->secondary_ID = FILE_EXT3_IDX;
        }

        /* For read operations, storage is ignored. */
        if ((op == OP_READ) || (op == OP_DELETE))
        {
            control_block->storage = PHB_SIM;
        }

        /* Only write operations need to check storage. */
        else if ((op == OP_WRITE) && (control_block->storage != PHB_SIM))
        {
            return KAL_FALSE;
        }

        /* It is unnecessary to check free list. */

      /**
       * For 1 to 1 mapping EF's, index is always equal to record_index.
       */
        if (is_specific == KAL_FALSE)
        {
            if ((type == PHB_MSISDN) && (op == OP_WRITE) && (control_block->index == (kal_uint16) PHB_INVALID_VALUE))
            {
                if (l4c_is_src_from_rmmi(control_block->src_id))
                {
                    control_block->record_index = phb_data_desc_find_next_free(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                    if (control_block->record_index == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                        return KAL_FALSE;
                    }
                    else
                    {
                        control_block->index = control_block->index;
                    }
                }
                else
                {
                    return KAL_FALSE;
                }
            }
            else
            {
                control_block->record_index = index;
            }
        }
        else
        {
            control_block->index = control_block->record_index;
        }
    }
    /* error */
    else
    {
        control_block->primary_ID = (kal_uint16) PHB_INVALID_VALUE;
        control_block->secondary_ID = (kal_uint16) PHB_INVALID_VALUE;
        control_block->storage = PHB_STORAGE_NONE;
        control_block->index = (kal_uint16) PHB_INVALID_VALUE;

        return KAL_FALSE;
    }

    return KAL_TRUE;
}   /* end of se_set_control_block_physical_storage */


/*****************************************************************************
 * FUNCTION
 *  phb_se_set_control_block
 * DESCRIPTION
 *  Set proc_stage, primary_ID, secondary_ID, and record_index of control_block,
 *  by its index and record_index toggle.
 *  Hence, this function controls whether read/write opeartion is available!!!
 *  
 *  Prerequisite:
 *  1. Before this function is called, type, index and total of control_block must be set.
 *  ie, phb_control_block_set_IO() must be called before this function.
 *  2. And, phb_se_is_in_range() should be called before this function.
 *  
 *  Assumption:
 *  Caller ensures parameters, such as control_block->index, are ok. Ie.,
 *  already call phb_is_read_param_valid().
 * PARAMETERS
 *  control_block       [?]         
 *  op                  [IN]        
 *  storage             [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_se_set_control_block(
            control_block_type *control_block,
            op_enum op,
            phb_storage_enum storage,
            kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SE_SET_CONTROL_BLOCK);

    if (op == OP_READ)
    {
      /**
       * User doesn't specify physical location to read, or this function
       * is called several times since it's the same session of
       * read operation.
       * Ignore storage and record_index; lookup by index
       */
        if ((record_index == (kal_uint16) PHB_INVALID_VALUE) || (control_block->proc_stage == READ_CONTINUE))
        {
            control_block->proc_stage = READ_CONTINUE;

            return phb_se_set_control_block_translate_index(control_block, op, KAL_FALSE);
        }
      /**
       * User specifies physical location to read. Since this case can only
       * read exactly one record and thus it is impossible that this function
       * is called again. So don't worry about re-entrant problem.
       */
        else
        {
            control_block->proc_stage = READ_CONTINUE_SPECIFIC;
            control_block->storage = storage;
            control_block->record_index = record_index;

         /**
          * For read, if user specifies physical location, total must be 1, and index must
          * be PHB_INVALID_VALUE.
          */
            control_block->total = 1;
            control_block->index = (kal_uint16) PHB_INVALID_VALUE;

            return phb_se_set_control_block_translate_index(control_block, op, KAL_TRUE);
        }
    }
    else if (op == OP_WRITE)
    {
        /* Case 3, 4. User doesn't specify physical location to write */
        if (record_index == (kal_uint16) PHB_INVALID_VALUE)
        {
            if ((control_block->index != (kal_uint16) PHB_INVALID_VALUE) &&
                (storage != PHB_SIM) && (storage != PHB_NVRAM))
            {
                return KAL_FALSE;
            }

            /* MSISDN is only allowed to be written by following case 3. */
            if ((control_block->type == PHB_MSISDN) && (control_block->index == (kal_uint16) PHB_INVALID_VALUE) && !l4c_is_src_from_rmmi(control_block->src_id))  // for CPBW (ON)
            {
                return KAL_FALSE;
            }

            control_block->storage = storage;
            control_block->record_index = record_index;

            return phb_se_set_control_block_translate_index(control_block, op, KAL_FALSE);
        }
        /* Case 1, 2. User specifies physical location to write */
        else
        {
            if ((storage != PHB_SIM) && (storage != PHB_NVRAM))
            {
                return KAL_FALSE;
            }

            /* MSISDN is only allowed to be written by following case 3. */
            if ((control_block->type == PHB_MSISDN) && !l4c_is_src_from_rmmi(control_block->src_id))  // for CPBW (ON)
            {
                return KAL_FALSE;
            }

            control_block->storage = storage;
            control_block->record_index = record_index;

         /**
          * Enforce the value of index, instead of total, which specifies number of entries
          * to piggyback.
          */
            control_block->total = 1;

            /* Case 2. User only specifies which index to update. control_block->index is already specified by user */
            if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
            {
                return phb_se_set_control_block_translate_index(control_block, op, KAL_TRUE);
            }

            /* Case 1. User specifies physical location to write, and specifies which index to update */
            else
            {
                return phb_se_set_control_block_translate_index(control_block, op, KAL_FALSE);
            }
        }
    }
    /* (op ==  OP_DELETE) */
    else
    {
        /* For delete operation, record_index must be invalid. */
        /* For 1 to 1 mapping, each delete needs translation for index and record_index */
        if ((record_index == (kal_uint16) PHB_INVALID_VALUE) || (control_block->type == PHB_MSISDN))
        {
            if (control_block->type == PHB_PHONEBOOK)
            {
                return phb_se_set_control_block_for_delete(control_block, storage);
            }
            else
            {
                return phb_se_set_control_block_translate_index(control_block, op, KAL_FALSE);
            }
        }
    }

    return KAL_FALSE;
}

#ifdef __PHB_SORT_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_index_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 phb_se_get_index_by_storage(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i, total, position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = phb_ptr->indices.phb_index.name_index.used_count;
    for (i = 0; i < total; i++)
    {
        position = phb_ptr->indices.phb_index.name_index.table[i].position;
        if (phb_ptr->indices.phb_index.data_entry_table.table[position].storage == storage)
        {
            break;
        }
    }

    if (i == total)
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }
    return i + 1;
}
#endif /* __PHB_SORT_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_se_get_ext_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  entry       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 phb_se_get_ext_index(phb_type_enum type, phb_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add operation */
    if (entry->index == (kal_uint16) PHB_INVALID_VALUE)
    {
        return (kal_uint8) PHB_INVALID_VALUE;
    }

    /* update operation */
    if ((type == PHB_PHONEBOOK) ||
#ifdef __PHB_USIM_SUPPORT__
        (type == PHB_ANRA) || (type == PHB_ANRB) || (type == PHB_ANRC) ||
#endif 
        (type == PHB_FDN) || (type == PHB_BDN))
    {
        name_num_index_type *name_num_index = NULL;
        kal_uint16 pos;

    #ifdef __PHB_USIM_SUPPORT__
        if (type == PHB_PHONEBOOK || type == PHB_ANRA || type == PHB_ANRB || type == PHB_ANRC)
    #else 
        if (type == PHB_PHONEBOOK)
    #endif 
            return phb_se_ext_index_find(entry->record_index, type);
        else if (type == PHB_FDN)
        {
            name_num_index = &phb_ptr->indices.fdn_index;
        }
        else if (type == PHB_BDN)
        {
            name_num_index = &phb_ptr->indices.bdn_index;
        }

        pos = name_num_index->name_index.table[entry->index - 1].position;
        return name_num_index->data_entry_table.table[pos].ext_index;
    }

    return (kal_uint8) PHB_INVALID_VALUE;
}
