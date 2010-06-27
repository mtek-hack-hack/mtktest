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
 * Filename:
 * ---------
 * nvram_ltable.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is 
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include <string.h>

#include "kal_release.h"
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
#include "custom_jump_tbl.h"
#include "resource_custpack_jtbl.h"
#endif /* !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) */


#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_context.h"

#include "nvram_data_items.h"
#include "nvram_ltable.h"

#include "nvram_user_defs.h"
#include "nvram_drval_fat.h"
#include "nvram_enums.h"
#include "nvram_io.h"

#include "FS_type.h"
#include "FS_func.h"
#include "nvram_lid_statistics.h"
 /***************************************************************************** 
* Typedef
*****************************************************************************/
/***************************************************************************** 
* Local Variable
*****************************************************************************/
#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
static custpack_nvram_header *custpack_nvram_header_ptr;
#endif 


static kal_uint16 custpack_idx = 0;
/***************************************************************************** 
* External Variable
*****************************************************************************/
extern kal_uint8 *CODED_SECRET_KEY;


extern kal_char *release_verno(void);
extern kal_char *release_branch(void);

#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
extern void *custpack2ndJumpTbl[];
extern Type_Preamble_Content CustPackResPreamble;
#endif /* !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) */
/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __SHADOW_NVRAM__
shadow_ltable_struct shadow_ltable[NVRAM_SHADOW_TOTAL];
kal_uint8 dirty_list[NVRAM_SHADOW_TOTAL];
#endif /* __SHADOW_NVRAM__ */ 
/***************************************************************************** 
* Global Function
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  nvram_pre_init
 * DESCRIPTION
 *  This function init necessary NVRAM information.
 *  (no matter NVRAM task is on or not)
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).(?)(?)
 *****************************************************************************/
void nvram_pre_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 nvram_sec_key[];

    kal_uint8 *sec_key_ptr = CODED_SECRET_KEY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->ltable.table == NULL)    /* assume that ltable still not initialized if total_LID==0 */
    {
        if (nvram_ptr->secret_key == NULL)
        {
            nvram_ptr->secret_key = nvram_sec_key;

            nvram_init_sec_ro(&sec_key_ptr);
            
            custom_nvram_get_key((char*)sec_key_ptr, nvram_ptr->secret_key);
        
        }
        /* Construct logical data item table */
        nvram_ptr->ltable.table = logical_data_item_table;
        nvram_ptr->ltable.total_LID = NVRAM_TOTAL_LID;
        nvram_ltable_construct(&nvram_ptr->ltable);
    }

}


static void nvram_assign_table_entry(kal_uint16 position, ltable_entry_struct* ldi)
{
    logical_data_item_table[position] = ldi;
        
#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
            if (logical_data_item_table[position]->category & NVRAM_CATEGORY_CUSTPACK)
            {
                if (logical_data_item_table[position]->LID == NVRAM_EF_CUSTPACK_VERNO_LID)
                {
                    logical_data_item_table[position]->default_value = custpack_nvram_header_ptr->version;
                }
                else
                {
                    logical_data_item_table[position]->default_value =
                        custpack_nvram_header_ptr->custpack_default[custpack_idx++];
                }
            }
#endif /* !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) */

    /* Assign SecuPack */
    if (logical_data_item_table[position]->category & NVRAM_CATEGORY_SECUPACK)
    {
        nvram_assign_secupack_entry(position);
    }
    
    /* Calculate record ID for each logical data item */
    /* System records occupies 1 and 2 of record ID, 0 of Logical data item ID */

    /**
     * Prevent human error.
     * Since multiple copied attribute DOES NOT support for 
     * linear fixed logical data items, the attribute is prohibited.
     */
#ifdef __NVRAM_COMPOSED_SUPPORT__
    if (!(ldi->category & NVRAM_CATEGORY_COMPOSED))
#endif 
    {
        kal_uint16 ldi_size = ldi->size * ldi->total_records;

        if (ldi->size > nvram_ptr->max_record_size)
        {
            nvram_ptr->max_record_size = ldi->size;
        }

        if (ldi_size > nvram_ptr->max_LDI_size)
        {
            nvram_ptr->max_LDI_size = ldi_size;
        }

        /* Only NVRAM_ATTR_MULTIPLE occupies extra record */
        if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
        {
            ++nvram_ptr->total_record_ID;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  ltable_construct
 * DESCRIPTION
 *  Constructor of ltable. Calculate  Record ID according to each logical data item's
 *  attributes.
 * PARAMETERS
 *  ltable          [IN/OUT]        The user configured logical data item table.
 *  total(?)        [IN]            Number of elements in ltable. Must not less than 1.
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_ltable_construct(ltable_type *ltable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    ltable_entry_struct *ltable_entry;
    void **custpack_header = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_ptr->max_record_size = 0;
    nvram_ptr->max_LDI_size = 0;

#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
    custpack_header = (void **)GET_ResCUSTPACK_Addr(ENTRY_PREAMBLE);
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))  /* dummy reference to make the variable exist */
    {
        /* CustPack NVRAM Initialized in NVRAM init procedure */
        custpack_nvram_header_ptr = (custpack_nvram_header*) custpack_header[CUSTPACK_NVRAM];
     }
#endif /* !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) */

   /**
    * `logical_data_item_table' is combined from 
    * `logical_date_item_table_vendor'
    * `logical_date_item_table_comm_app'
    * and
    * `logical_data_item_table_cust'
    */
    i = 0;
    while (logical_data_item_table_core[i].LID != 0xF1F2)
    {
        if (logical_data_item_table_core[i].size == 0 || 
            logical_data_item_table_core[i].total_records == 0)
        {
			i++;
            continue;   /* invalid LID */
        }
        
        nvram_assign_table_entry(logical_data_item_table_core[i].LID, &logical_data_item_table_core[i]);
        i++;
    }

    i = 0;
    while (logical_data_item_table_comm_app[i].LID != 0xF1F2)
    {
        if (logical_data_item_table_comm_app[i].LID == 0 || 
            logical_data_item_table_comm_app[i].size == 0 || 
            logical_data_item_table_comm_app[i].total_records == 0)
        {
			i++;
            continue;   /* invalid LID */
        }
        
        nvram_assign_table_entry(logical_data_item_table_comm_app[i].LID, &logical_data_item_table_comm_app[i]);
        i++;        
    }
    
    for (i = NVRAM_LAST_COMMAPP_LID; i < NVRAM_TOTAL_LID; ++i)
    {
            if (logical_data_item_table_cust[i - NVRAM_LAST_COMMAPP_LID].LID == 0 ||
                logical_data_item_table_cust[i - NVRAM_LAST_COMMAPP_LID].size == 0 ||
                logical_data_item_table_cust[i - NVRAM_LAST_COMMAPP_LID].total_records == 0)
            {
                continue;   /* invalid LID */
            }

            /* Here could be some redundant data items; place to correct position */
            nvram_assign_table_entry(logical_data_item_table_cust[i - NVRAM_LAST_COMMAPP_LID].LID, 
                                     &logical_data_item_table_cust[i - NVRAM_LAST_COMMAPP_LID]);

    }

    /* First, define system-level record */

    nvram_ptr->coded_version = (kal_uint8*) release_verno();

   /**
    * If length of returned verno is larger than maximum capacity, 
    * truncate it to retain tail `CODED_DATA_VERSION_SIZE' bytes, and
    * use it as coded_version.
    * Note that maximum capacity is exactly CODED_DATA_VERSION_SIZE, 
    * instead of (CODED_DATA_VERSION_SIZE - 1); because CODED_PADDING
    * guarantees to terminated it with zero.
    */
    if (strlen((kal_char*) nvram_ptr->coded_version) > CODED_DATA_VERSION_SIZE)
    {
        kal_uint16 len = strlen((kal_char*) nvram_ptr->coded_version) - CODED_DATA_VERSION_SIZE;

        nvram_ptr->coded_version += len;
    }

    /* Branch version */
    ltable_entry = ltable->table[NVRAM_EF_BRANCH_VERNO_LID];
    ltable_entry->default_value = (kal_uint8*) release_branch();

    /* Default lock status is LOCKED -- by using lock pattern of CODED_LOCK_PATTERN */
    ltable_entry = ltable->table[NVRAM_EF_SYS_LID];
    kal_mem_set(coded_version_lock, 0, NVRAM_EF_SYS_SIZE);
    strncpy((kal_char*) coded_version_lock, (kal_char*) nvram_ptr->coded_version, CODED_DATA_VERSION_SIZE);
    kal_mem_cpy(coded_version_lock + CODED_DATA_VERSION_SIZE, CODED_PADDING, CODED_PADDING_SIZE);
    kal_mem_cpy(
        coded_version_lock + CODED_DATA_VERSION_SIZE + CODED_PADDING_SIZE,
        CODED_LOCK_PATTERN,
        CODED_LOCK_PATTERN_SIZE);
    ltable_entry->default_value = (kal_uint8 const*)coded_version_lock;

    /*
     * Though system-level record is confidential, the attribute is not defined here. 
     * It is controlled by NVRAM Layer directly.
     */
    custom_nvram_encrypt(
        nvram_ptr->secret_key,
        coded_version_lock + CODED_LOCK_PATTERN_OFFSET,
        CODED_LOCK_PATTERN_SIZE,
        (nvram_ptr->coded_version[9] - '0') * 10 + (nvram_ptr->coded_version[10] - '0'));

    nvram_ptr->last_LID = ltable->total_LID - 1;

}   /* end of ltable_construct function */

#ifdef __SHADOW_NVRAM__


/*****************************************************************************
 * FUNCTION
 *  nvram_shadow_construct
 * DESCRIPTION
 *  Read Shadow data items for FAT and fill them into Shadow Buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_shadow_construct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 shadow_used_size = GUARD_PATTERN_SIZE;
    kal_uint16 rec_index;
    nvram_lid_enum file_idx;
    kal_uint8 segment = 0;
    ltable_entry_struct *ldi;
    nvram_errno_enum ret;
    kal_uint32 shadow_total_to_verify = 0;
    kal_uint32 shadow_size_to_verify = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dynamically allocated; reduce ZI consumption */


    /* construct guard pattern */
    kal_mem_set(ShadowBuffer, 0xf1, GUARD_PATTERN_SIZE);

    for (file_idx = 0; file_idx < NVRAM_TOTAL_LID; ++file_idx)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);

    #ifdef __SHADOW_SUPPORT_SB__
        if ((NORMAL_BOOT == stack_query_boot_mode()) && (ldi->category & NVRAM_CATEGORY_SHADOW))
    #else /* __SHADOW_SUPPORT_MS__ */
        if ((USBMS_BOOT == stack_query_boot_mode()) && (ldi->category & NVRAM_CATEGORY_SHADOW_MS))
    #endif 
        {
            /* construct the shadow lookup table */
            shadow_ltable[segment].LID = ldi->LID;
            shadow_ltable[segment].offset = ShadowBuffer + shadow_used_size;

            /* bi-way link */
            ldi->record_ID = segment;

            kal_mem_set(shadow_ltable[segment].dirty_records, 0x00, NVRAM_MAX_SHADOW_REC* sizeof(kal_uint32));

            /* construct the shadow buffer */
            for (rec_index = 1; rec_index <= ldi->total_records; rec_index++)
            {
                kal_uint16 rec_amount;

                if (nvram_ptr->software_change_status & NVRAM_EMPTY_FAT)
                {   /* if the FAT is empty, we can directly copy default to Shadow */
                    rec_amount = 1;
                    nvram_get_default_value_to_write(ldi, rec_index, shadow_ltable[segment].offset + ((rec_index - 1) * ldi->size), ldi->size);

                }
                else
                {
                    rec_amount = (ldi->total_records - rec_index + 1);

                    if (rec_amount * (ldi->size + NVRAM_CHKSUM_SIZE) > MAX_NVRAM_RECORD_SIZE)
                    {
                        rec_amount = MAX_NVRAM_RECORD_SIZE / (ldi->size + NVRAM_CHKSUM_SIZE);
                    }

                    ret = nvram_read_data_item(ldi, rec_index, rec_amount, shadow_ltable[segment].offset + ((rec_index - 1) * ldi->size), ldi->size);
                    
                    ASSERT(ret == NVRAM_ERRNO_SUCCESS);
                    rec_index += (rec_amount - 1);
                }

                shadow_used_size += (ldi->size) * rec_amount;
            }

            segment++;
            /* shadow items count */
            shadow_total_to_verify++;
            /* shadow size */
            shadow_size_to_verify += ldi->size * ldi->total_records;

        }

    }

#if defined(__MTK_TARGET__)
    ASSERT(shadow_total_to_verify == shadow_item_total);
    ASSERT((shadow_size_to_verify + (GUARD_PATTERN_SIZE * 2)) == shadow_buffer_size);
#else
	 shadow_buffer_size = shadow_size_to_verify + (GUARD_PATTERN_SIZE * 2);
#endif /* defined(__SHADOW_NVRAM__) */ 

    /* construct guard pattern */
    kal_mem_set(ShadowBuffer + shadow_used_size, 0xf2, GUARD_PATTERN_SIZE);
}
#endif /* __SHADOW_NVRAM__ */ 

#ifdef __SECURITY_OTP__


/*****************************************************************************
 * FUNCTION
 *  nvram_otp_construct
 * DESCRIPTION
 *  Construct OTP table.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_otp_construct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 file_idx;
    ltable_entry_struct *ldi;
    kal_uint32 fs_otp_size = 0;
    kal_uint8 nvram_otp_idx = 0;
    kal_uint32 nvram_otp_size = 0;  /* if version is supported, init it as version length */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (file_idx = NVRAM_EF_SYS_LID; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
    {
        nvram_get_data_item(ldi, file_idx);

        if (ldi->attr & NVRAM_ATTR_OTP)
        {
            ASSERT(ldi->total_records == 1);
            ASSERT(nvram_otp_idx < NVRAM_OTP_TOTAL);

            nvram_otp_ltable[nvram_otp_idx].offset = nvram_otp_size;
            nvram_otp_size += ldi->size;

            nvram_otp_ltable[nvram_otp_idx].LID = ldi->LID;
            nvram_otp_idx++;
        }
    }
#ifdef __MTK_TARGET__    
    FS_OTPQueryLength(FS_DEVICE_TYPE_NOR, &fs_otp_size);
#else
    fs_otp_size = 256;
#endif
    ASSERT(nvram_otp_size <= fs_otp_size);

}
#endif /* __SECURITY_OTP__ */ 

