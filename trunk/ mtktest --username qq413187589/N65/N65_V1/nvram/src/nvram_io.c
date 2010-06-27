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
 * nvram_io.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main() function of NVRAM module.
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
#include "string.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "nvram.h"
#include "nvram_user_defs.h"

/* Prerequisite of nvram_context.h */
#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_context.h"

#include "nvram_io.h"
/* For FAT */
#include "fs_type.h"
#include "fat_fs.h"
#include "fs_func.h"/*__SECURITY_OTP__*/
#include "nvram_lid_statistics.h"

#include "nvram_drval_fat.h"
#include "custom_mmi_default_value.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */ 

#ifdef __SHADOW_SUPPORT_SB__
#include "nvram_ilm.h"
#endif 
#include "drv_comm.h"
#include "wdt_sw.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#undef  _FILE_CODE_
#define _FILE_CODE_ _NVRAM_MAIN_C_

/***************************************************************************** 
* Global Variable
*****************************************************************************/
/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __SHADOW_NVRAM__
static kal_uint8 next_flush = 0, next_request = 0, total_dirty = 0;
static kal_uint8 dirty_threshold = 1;
#endif /* __SHADOW_NVRAM__ */ /* __SHADOW_NVRAM */

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern const kal_wchar *NVRAM_CLEAN_FOLDER_LIST[];
extern const kal_wchar *NVRAM_COMMON_CLEAN_FOLDER_LIST[];
extern kal_uint8 shadow_item_total;
extern kal_uint16 shadow_buffer_size;
extern kal_int32 nvram_fat_last_err;
extern kal_uint32 nvram_fat_last_line;

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer);
extern void nvram_restore_byte_cache(kal_uint8 *buffer);
extern void nvram_restore_short_cache(kal_uint16 *buffer);
extern void nvram_restore_double_cache(kal_uint32 *buffer);
extern void WDT_Restart2(void);

/***************************************************************************** 
* Local Function
*****************************************************************************/
static nvram_errno_enum nvram_read_data_item_single(
                            ltable_entry_struct *ldi,
                            kal_uint16 rec_index,
                            kal_uint16 rec_amount,
                            kal_uint8 *buffer,
                            kal_uint16 buffer_size);
static nvram_errno_enum nvram_read_data_item_multiple(
                            ltable_entry_struct *ldi,
                            kal_uint16 rec_index,
                            kal_uint16 rec_amount,
                            kal_uint8 *buffer,
                            kal_uint16 buffer_size);
static nvram_errno_enum nvram_write_data_item_single(
                            ltable_entry_struct *ldi,
                            kal_uint16 index,
                            kal_uint8 *buffer,
                            kal_uint16 buffer_size,
                            kal_bool is_init);
static nvram_errno_enum nvram_write_data_item_multiple(
                            ltable_entry_struct *ldi,
                            kal_uint16 index,
                            kal_uint8 *buffer,
                            kal_uint16 buffer_size,
                            kal_bool is_init);
static void nvram_factory_restore_setting(void);
static kal_bool nvram_factory_rmdir_user(nvram_reset_category_enum category);


/*****************************************************************************
 * FUNCTION
 *  nvram_nand_error_handling
 * DESCRIPTION
 *  This is is a special handling that is used to cover nand bad block is found.
 * PARAMETERS
 *  ldi             [IN]        MUST be 1 ~ (total_LID - 1)
 *  nvramname       [IN]        
 *  buffer          [IN]        MUST be even-bytes aligned.
 *  buffer_size     [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2
 * RETURNS
 *  FS error code
 *****************************************************************************/
kal_int32 nvram_nand_error_handling(ltable_entry_struct *ldi, kal_char *nvramname, kal_uint8 *buffer, kal_uint16 buffer_size)
{
#if defined (_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__)
        /* special error handling for NAND bad block */
        kal_int32 ret;
        kal_wchar temp_name1[NVRAM_MAX_PATH_LEN], temp_name2[NVRAM_MAX_PATH_LEN];
        
        kal_wsprintf(temp_name1, "Z:\\NVRAM\\NVD_DATA\\%s", nvramname);
        NVRAM_MAKE_LID_FILENAME((kal_char *)nvramname, ldi->fileprefix, '^', ldi->fileverno);

        // TODO: to handle multi-default
        ret = nvram_drv_fat_write(buffer, nvramname, ldi->total_records, buffer_size, ldi->attr&NVRAM_ATTR_MSP, KAL_TRUE);
        EXT_ASSERT((ret == FS_NO_ERROR), ret, 0, 0);

        ret = FS_Delete(temp_name1);

        kal_wsprintf(temp_name2, "Z:\\NVRAM\\NVD_DATA\\%s", nvramname);
        
        ret = FS_Move(temp_name2, temp_name1, FS_MOVE_KILL, NULL, NULL, 0);
        EXT_ASSERT((ret == FS_NO_ERROR), ret, 0, 0);

        return ret;
#endif /* _NAND_FLASH_BOOTING_ || __FS_SYSDRV_ON_NAND__ */
}


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item
 * DESCRIPTION
 *  This is nvram_read_data_item() function of NVRAM module.
 * PARAMETERS
 *  ldi             [IN]        MUST be 1 ~ (total_LID - 1)
 *  rec_index       [IN]        
 *  rec_amount      [IN]        
 *  buffer          [IN]        MUST be even-bytes aligned.
 *  buffer_size     [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2
 *  index(?)        [IN]        MUST be 1 ~ total_records
 * RETURNS
 *  NVRAM_IO_ERRNO_OK    if read successfully.
 *  NVRAM_IO_ERRNO_CHK   if checksum error, and cannot be reset to default value.
 *  NVRAM_IO_ERRNO_INIT  if checksum error, but successfully reset to default value.
 *****************************************************************************/
nvram_errno_enum nvram_read_data_item
    (ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;
    kal_bool default_only = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(ldi->LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    if (buffer_size < ldi->size)
    {
        return NVRAM_IO_ERRNO_INVALID_SIZE;
    }
    
    if (nvram_ptr->dev_broken)
        default_only = KAL_TRUE;
    
#if defined(__SHADOW_SUPPORT_MS__)
    if (stack_query_boot_mode() == USBMS_BOOT &&
        !(ldi->category & NVRAM_CATEGORY_SHADOW_MS) && 
        nvram_ptr->state == NVRAM_STATE_READY)
        default_only = KAL_TRUE;
#endif /* defined(__SHADOW_SUPPORT_MS__) */ 
    
    if (default_only)
    {
        kal_uint8 i;

        for (i = 0; i < rec_amount; i++)
        {
            nvram_get_default_value_to_write(ldi, i + 1, buffer + (i * ldi->size), ldi->size);
        }

        return NVRAM_IO_ERRNO_OK;
    }

#ifdef __SECURITY_OTP__
    /* Handle request to OTP */
    if ((nvram_ptr->state != NVRAM_STATE_READY) && (ldi->attr & NVRAM_ATTR_OTP))
    {
        return NVRAM_IO_ERRNO_OK;
    }
    else  if ((nvram_ptr->state == NVRAM_STATE_READY) && (ldi->attr&NVRAM_ATTR_OTP))
    {
        status = nvram_read_otp_data_item(ldi, buffer, ldi->size); 
    }
    else
#endif
    /* Read content of the specified logical data item depending on whether it is multiple copied */
#ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
    {
        status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, ldi->size);
    }
    else
    {
        status = nvram_read_data_item_single(ldi, rec_index, rec_amount, buffer, ldi->size);
    }

    /**
    * Read finished. If this logical data item is confidential, decryption is needed.
    *
    */
    if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
    {
        custom_nvram_decrypt(
            nvram_ptr->secret_key,
            buffer,
            buffer_size,
            (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
    }

    kal_prompt_trace(
        MOD_NVRAM,
        "Read Result: LID=%d, status=%d, size=%d, des=%s",
        ldi->LID,
        status,
        ldi->size,
        ldi->description);
    return status;
}   /* end of nvram_read_data_item */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item_single
 * DESCRIPTION
 *  This is nvram_read_data_item_single() function of NVRAM module.
 * PARAMETERS
 *  ldi             [?]         
 *  rec_index       [IN]        
 *  rec_amount      [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_read_data_item_single
    (ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status = NVRAM_ERRNO_SUCCESS;
    nvram_drv_status_enum drv_status;
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, '_', ldi->fileverno);

#ifdef __NVRAM_COMPOSED_SUPPORT__
    if (ldi->category & NVRAM_CATEGORY_COMPOSED)
    {
        driver = &nvram_ptr->driver_table.table[nvram_ptr->ltable.table[ldi->device]->device];
        drv_status = nvram_drv_fat_read_composed(nvramname, rec_index, buffer, buffer_size, nvram_ptr->ltable.table[ldi->device]->size, ldi->total_records    /* startAddr */
            );
    }
    else
#endif /* __NVRAM_COMPOSED_SUPPORT__ */ 
    {
        drv_status = nvram_drv_fat_read(nvramname, rec_index, rec_amount, buffer, buffer_size, ldi->attr & NVRAM_ATTR_MSP);
    }
    /* Success!! Great!! */
    if (drv_status == NVRAM_DRV_OK)
    {
        status = NVRAM_IO_ERRNO_OK;
    }

    /* Sigh. Failed..... */
    else
    {

        if (drv_status == NVRAM_DRV_EMPTY_RECORD)
        {
            kal_int32 i;
/* __GEMINI__ */         
            if(nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records))
/* __GEMINI__ */                
                drv_status = NVRAM_DRV_OK;
                
             for (i = 0; i < rec_amount; i++)
             {
                /* 
                 * we have to use get_default_to_write instead of memcpy, 
                 * because there might be LID with NVRAM_CATEGORY_MULTI_DEFAULT
                 */
                nvram_get_default_value_to_write(ldi, rec_index + i, buffer + (i * buffer_size), buffer_size);
             }
                
        }
        else
        {
            nvram_get_default_value_to_write(ldi, rec_index, buffer, buffer_size);
    
            if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
            {
                custom_nvram_encrypt(
                    nvram_ptr->secret_key,
                    buffer,
                    ldi->size,
                    (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
            }

            drv_status = nvram_drv_fat_write(buffer, nvramname, rec_index, buffer_size, ldi->attr&NVRAM_ATTR_MSP, KAL_FALSE);
            if (drv_status != NVRAM_DRV_OK)
            {
                kal_prompt_trace(
                    MOD_NVRAM,
                    "Read Single Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                    ldi->LID,
                    drv_status,
                    nvram_fat_last_err,
                    __LINE__);        
            }
        }

        if (drv_status == NVRAM_DRV_OK)
        {
            status = NVRAM_IO_ERRNO_OK;
        }
        else
    #ifdef __SHADOW_SUPPORT_SB__
            status = NVRAM_IO_ERRNO_CHK;
    #else 
            ASSERT(0);
    #endif 
    }

    return status;
}   /* end of nvram_read_data_item_single */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item_multiple
 * DESCRIPTION
 *  This is nvram_read_data_item_multiple() function of NVRAM module.
 *  Note that multiple copied attribute DOES NOT support for
 *  linear fixed logical data items.
 *  Hence this function is NEVER called for linear fixed logical data items.
 * PARAMETERS
 *  ldi             [?]         
 *  rec_index       [IN]        
 *  rec_amount      [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 * RETURNS
 *  NVRAM_IO_ERRNO_INIT if all copies are corrupted and any of them is reset successfully.
 *  NVRAM_IO_ERRNO_CHK if all copies are corrupted and reset failed.
 *  NVRAM_IO_ERRNO_OK at least one valid copy is read.
 *****************************************************************************/
static nvram_errno_enum nvram_read_data_item_multiple
    (ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;
    nvram_drv_status_enum drv_status;

    kal_uint8 ID;
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_status = NVRAM_DRV_CHECKSUM_ERROR;

    /* First, try to find one valid / healthy copy */
    for (ID = 0; ID < 2; ID++)
    {
        NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'a' + ID, ldi->fileverno);
        drv_status = nvram_drv_fat_read(nvramname, rec_index, rec_amount, buffer, buffer_size, ldi->attr & NVRAM_ATTR_MSP);

        /* Success!! Great!! */
        if (drv_status == NVRAM_DRV_OK)
        {
            break;
        }
        else
        {
            kal_prompt_trace(
                MOD_NVRAM,
                "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                ldi->LID,
                drv_status,
                nvram_fat_last_err,
                __LINE__);        
        }
        
    }

    /* At least one fisrt valid copy, identified by `record_ID', is found */
    if (drv_status == NVRAM_DRV_OK)
    {
        kal_uint16 first_valid_ID = ID;
        kal_uint8 *extra_buffer = NULL;

        extra_buffer = (kal_uint8*) get_ctrl_buffer(buffer_size * rec_amount);

        ASSERT(extra_buffer != NULL);
      /**
       * This moment `buffer' contains the data of the first valid copy. 
       * Hence, update each corrupted copy with the data of first valid copy
       * Here, restart from first copy to attemp synchronizing each copy.
       */
        for (ID = 0; ID < 2; ID++)
        {
            if (ID == first_valid_ID)
            {
                continue;
            }

            /* Now, syncrhonize all corrupted copy with first valid copy. */
            NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'a' + ID, ldi->fileverno);
            
            drv_status = nvram_drv_fat_read(nvramname, rec_index, rec_amount, extra_buffer, buffer_size, ldi->attr & NVRAM_ATTR_MSP);
            
            if (drv_status != NVRAM_DRV_OK)
            {
                kal_prompt_trace(
                    MOD_NVRAM,
                    "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                    ldi->LID,
                    drv_status,
                    nvram_fat_last_err,
                    __LINE__);
            }

            /* This copy is valid /healthy, skip. */
            if ((drv_status == NVRAM_DRV_OK) && (kal_mem_cmp(extra_buffer, buffer, buffer_size) == 0))
            {
                continue;
            }
            /* Corrupted copy found, we have to reset it, sigh... */
            /*
             * Empty record. Reset it. 
             * Note that multiple copied attribute DOES NOT support for 
             * linear fixed logical data items.
             */
            else if (drv_status == NVRAM_DRV_EMPTY_RECORD)
            {
/* __GEMINI__ */                
                if(nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records))
/* __GEMINI__ */
                {
                    drv_status = NVRAM_DRV_OK;
                }
                else
                {
                    kal_prompt_trace(
                        MOD_NVRAM,
                        "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                        ldi->LID,
                        drv_status,
                        nvram_fat_last_err,
                        __LINE__);        
                }
                    
            }
            /* Not empty, it is safe to just reset this section. */
            else
            {
                /* Synchornize the corrupted copy in a best effort manner */
                drv_status = nvram_drv_fat_write(buffer, nvramname, rec_index, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE);

                if (drv_status != NVRAM_DRV_OK)
                {
                    kal_prompt_trace(
                        MOD_NVRAM,
                        "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                        ldi->LID,
                        drv_status,
                        nvram_fat_last_err,
                        __LINE__);
                    
                    /* special error handling for NAND bad block */
                    if (drv_status == FS_DATA_ERROR)
                    {
                        nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
                    }

                }
            }
        }

        if (extra_buffer != NULL)
        {
            free_ctrl_buffer(extra_buffer);
        }

        status = NVRAM_IO_ERRNO_OK;
    }
    /* Failed, no valid copy, sigh..... */
    else
    {
        status = NVRAM_IO_ERRNO_CHK;
    #ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MTK_SECURE_PLATFORM__  */    
        {
            nvram_get_default_value_to_write(ldi, rec_index, buffer, buffer_size);
    
            /* A confidential logical data item. Encrypt it. */
            if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
            {
                custom_nvram_encrypt(
                    nvram_ptr->secret_key,
                    buffer,
                    ldi->size,
                    (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
            }

            /*
             * Since logical data item is already exist and this partial reset of logical data item
             * is due to checksum error,  drv_write() is invoked. 
             */

            /* Reset all copy to default value! */
            for (ID = 0; ID < 2; ID++)
            {
                NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'a' + ID, ldi->fileverno);

                drv_status = nvram_drv_fat_write(buffer, nvramname, rec_index, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE);
            
             /**
              * Empty record. Sync it. 
              * Note that multiple copied attribute DOES NOT support for 
              * linear fixed logical data items.
              */
                if (drv_status == NVRAM_DRV_EMPTY_RECORD)
                {
                    drv_status = nvram_drv_fat_write(buffer, nvramname, ldi->total_records, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);

                    if (drv_status != NVRAM_DRV_OK)
                    {
                        kal_prompt_trace(
                            MOD_NVRAM,
                            "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                            ldi->LID,
                            drv_status,
                            nvram_fat_last_err,
                            __LINE__);        
                    }
                
                }
                /* special error handling for NAND bad block */
                else if (drv_status == FS_DATA_ERROR)
                {
                    nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
                }

                if (drv_status == NVRAM_DRV_OK)
                {
                    status = NVRAM_IO_ERRNO_OK;
                }
                else
            #ifdef __SHADOW_SUPPORT_SB__
                    status = NVRAM_IO_ERRNO_CHK;
            #else 
                    ASSERT(0);
            #endif 
            }
            
        }

    }

    return status;
}   /* end of nvram_read_data_item_multiple */


/*****************************************************************************
 * FUNCTION
 *  nvram_get_default_value_to_write
 * DESCRIPTION
 *  This is nvram_get_default_value_to_write() function of NVRAM module.
 *  Get default value of certain logical data item.
 *  The default value is copied into buffer.
 *  The returned content of buffer may be encrypted if needed.
 * PARAMETERS
 *  ldi             [?]         
 *  rec_index       [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 * RETURNS
 *  KAL_FALSE if no default value defined, KAL_TRUE otherwise.(?)
 *****************************************************************************/
void nvram_get_default_value_to_write
    (ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 const *default_value = ldi->default_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Multi default value */
    if ((ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
    {
        rec_index--;
    }
    else
    {
        rec_index = 0;
    }

    if ((ldi->LID >= NVRAM_EF_L1_START && ldi->LID <= NVRAM_EF_L1_END) ||
        (ldi->LID >= NVRAM_EF_UL1_START && ldi->LID <= NVRAM_EF_UL1_END) ||
#if defined(__WIFI_SUPPORT__)
        (ldi->LID >= NVRAM_EF_WNDRV_START && ldi->LID <= NVRAM_EF_WNDRV_END) ||
#endif 
        (ldi->LID == NVRAM_EF_AUDIO_PARAM_LID))
    {
        nvram_get_L1_default_value_to_write(ldi->LID, buffer);
    }
    else
    {
        if (default_value == NULL || default_value == (kal_uint8 const*)NVRAM_EF_FF_DEFAULT)
            /* No default value supplied. Fill the buffer with 0xFF. */
        {
            kal_mem_set(buffer, (kal_uint8) NVRAM_INVALID_VALUE, buffer_size);
        }
        else if (default_value == (kal_uint8 const*)NVRAM_EF_ZERO_DEFAULT)
            /* Default value is all the same value (0x00) Fill it as well. */
        {
            kal_mem_set(buffer, (kal_uint8) NVRAM_EF_ZERO_DEFAULT_VALUE, buffer_size);
        }
    #ifdef NVRAM_SHORTREG_SIZE
        else if (default_value == (kal_uint8*) NVRAM_EF_SHORTREG_DEFAULT)
        {
            kal_uint16 i;

            for (i = 0; i < NVRAM_EF_SHORTREG_SIZE; i++)
            {
                if (ldi->LID == NVRAM_EF_SHORTREG_DEFAULT[i].LID)
                {
                    break;
                }
            }

            ASSERT(i < NVRAM_EF_SHORTREG_SIZE);

            kal_mem_cpy(
                buffer,
                (void*)NVRAM_EF_SHORTREG_DEFAULT[i].real_default,
                NVRAM_EF_SHORTREG_DEFAULT[i].real_size);
            kal_mem_set(
                buffer + NVRAM_EF_SHORTREG_DEFAULT[i].real_size,
                (kal_uint8) NVRAM_EF_ZERO_DEFAULT_VALUE,
                buffer_size - NVRAM_EF_SHORTREG_DEFAULT[i].real_size);
        }
    #endif /* NVRAM_SHORTREG_SIZE */ 
        else
        {
            kal_mem_cpy(buffer, (void*)(ldi->default_value + (ldi->size * rec_index)), ldi->size);
        }
    }
}   /* end of nvram_get_default_value_to_write */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_data_item
 * DESCRIPTION
 *  This is nvram_write_data_item() function of NVRAM module.
 * PARAMETERS
 *  ldi                 [IN]        MUST be 1 ~ (total_LID - 1)
 *  index               [IN]        MUST be 1 ~ total_records
 *  data                [?]         
 *  is_init             [IN]        
 *  buffer_size(?)      [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2 Note that content of `data' could be changed due to encyrption!!
 *  buffer(?)           [IN]        MUST be even-bytes aligned.
 * RETURNS
 *  NVRAM_IO_ERRNO_INVALID_LID
 *  NVRAM_IO_ERRNO_INVALID_RECORD
 *  NVRAM_IO_ERRNO_INVALID_SIZE
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.
 *****************************************************************************/
nvram_errno_enum nvram_write_data_item(ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *data, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(ldi->LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }
    
    if (nvram_ptr->dev_broken)
    {
        return NVRAM_IO_ERRNO_OK;
    }
#if defined(__SHADOW_SUPPORT_SB__) && defined(__MTK_TARGET__)
    else if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
    {
        if (!(ldi->category & NVRAM_CATEGORY_SHADOW))
        {
            kal_bool LID_NOT_IN_SHADOW = KAL_FALSE;
            EXT_ASSERT(LID_NOT_IN_SHADOW, ldi->LID, 0, 0);
        }
    }
#else /* __SHADOW_SUPPORT_SB__ */ /* __SHADOW_SUPPORT_MS__ */
    else if ((nvram_ptr->state == NVRAM_STATE_READY) && (USBMS_BOOT == stack_query_boot_mode()))
    {
        return NVRAM_IO_ERRNO_OK;
    }
#endif /* __SHADOW_SUPPORT_SB__ */ /* __SHADOW_NVRAM__ */

    /* Global software lock status is locked and this logical data item's attribute is write-protected. */
    if ((nvram_ptr->lock == KAL_TRUE) && NVRAM_IS_ATTR_WRITEPROTECT(ldi->attr))
    {
        return NVRAM_IO_ERRNO_LOCKED;
    }

    /* Construct a even bytes aligned buffer, and assign it to returned data pointer */
    if (data == NULL)
    {
        return NVRAM_IO_ERRNO_INVALID_SIZE;
    }

    /* Confidential logical data item, encrypt it. */
    if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
    {
        custom_nvram_encrypt(
            nvram_ptr->secret_key,
            data,
            ldi->size,
            (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
    }

#ifdef __SECURITY_OTP__
    /* Handle request to OTP */
    if (
#ifndef __MTK_TARGET__
        (ldi->category & NVRAM_CATEGORY_COMPOSED && nvram_ptr->state != NVRAM_STATE_READY) ||
#endif
        (ldi->attr & NVRAM_ATTR_OTP &&  nvram_ptr->state == NVRAM_STATE_READY))
    {
            status = nvram_write_otp_data_item(ldi, data);
    }
    else if ((nvram_ptr->state != NVRAM_STATE_READY) && (ldi->attr & NVRAM_ATTR_OTP))
    {
        return NVRAM_IO_ERRNO_OK;
    }
    else
#endif
    /* Write content of the specified logical data item depending on whether it is multiple copied */
#ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
    {
        status = nvram_write_data_item_multiple(ldi, index, data, ldi->size, is_init);
    }
    else
    {
        status = nvram_write_data_item_single(ldi, index, data, ldi->size, is_init);
    }

#ifdef __SHADOW_NVRAM__ /* To make sure the Shadow Buffer is plain text */
#ifdef __SHADOW_SUPPORT_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
#endif 
    {
        if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
        {
            custom_nvram_decrypt(
                nvram_ptr->secret_key,
                data,
                ldi->size,
                (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
        }
    }
#endif /* __SHADOW_NVRAM__ */ 


    kal_prompt_trace(MOD_NVRAM, "Write Result: LID=%d, status=%d, des=%s", ldi->LID, status, ldi->description);
    return status;
}   /* end of nvram_write_data_item */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_data_item_single
 * DESCRIPTION
 *  This is nvram_write_data_item_single() function of NVRAM module.
 * PARAMETERS
 *  ldi             [?]         
 *  index           [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 *  is_init         [IN]        
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write(?)
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.(?)
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_write_data_item_single
    (ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *buffer, kal_uint16 buffer_size, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;
    nvram_drv_status_enum drv_status;
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, '_', ldi->fileverno);

    status = NVRAM_IO_ERRNO_CHK;
    drv_status = nvram_drv_fat_write(buffer, nvramname, index, buffer_size, ldi->attr & NVRAM_ATTR_MSP, is_init);
    if (drv_status != NVRAM_DRV_OK)
    {
        kal_prompt_trace(
            MOD_NVRAM,
            "Write Single Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
            ldi->LID,
            drv_status,
            nvram_fat_last_err,
            __LINE__);        
    }
        

    /* Success!! Great!! */
    if (drv_status == NVRAM_DRV_OK)
    {
        status = NVRAM_IO_ERRNO_OK;
    }

   /**
    * Something wrong. Maybe sudden power-off happened during 
    * last time reset, which result in a empty record for this logical data item.
    * Anyway, reset it to default.
    *
    * As for linear fixed logical data items, all sections must be reset to default, 
    * then write only this section.
    */
    else if (drv_status == NVRAM_DRV_EMPTY_RECORD)
    {
        status = NVRAM_IO_ERRNO_CHK;

      /**
       * As for linear fixed logical data items, all sections must be reset to default, 
       * then write only this section.
       */
        if (ldi->total_records > 1)
        {
            kal_uint8 *extra_buffer = NULL;

            extra_buffer = (kal_uint8*) get_ctrl_buffer(buffer_size + NVRAM_CHKSUM_SIZE);

            ASSERT(extra_buffer != NULL);

            nvram_get_default_value_to_write(ldi, index, extra_buffer, buffer_size);
            /* A confidential logical data item. Encrypt it. */
            if (NVRAM_IS_ATTR_CONFIDENTIAL(ldi->attr))
            {
                custom_nvram_encrypt(
                    nvram_ptr->secret_key,
                    extra_buffer,
                    ldi->size,
                    (ldi->fileprefix[2] << 4) + (ldi->fileprefix[3] >> 4));
            }

            drv_status = nvram_drv_fat_write(extra_buffer, nvramname, ldi->total_records, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);

            /* special error handling for NAND bad block */
            if (drv_status == FS_DATA_ERROR)
            {
                nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
            }


            if (extra_buffer != NULL)
            {
                free_ctrl_buffer(extra_buffer);
            }

            drv_status = nvram_drv_fat_write(buffer, nvramname, index, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE);

            /* special error handling for NAND bad block */
            if (drv_status == FS_DATA_ERROR)
            {
                nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
            }            
        }
        else
        {
            drv_status = nvram_drv_fat_write(buffer, nvramname, ldi->total_records, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);

            if (drv_status != NVRAM_DRV_OK)
            {
                kal_prompt_trace(
                    MOD_NVRAM,
                    "Write Single Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                    ldi->LID,
                    drv_status,
                    nvram_fat_last_err,
                    __LINE__);        
            }

            /* special error handling for NAND bad block */
            if (drv_status == FS_DATA_ERROR)
            {
                nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
            }        
        }

        if (drv_status == NVRAM_DRV_OK)
        {
            status = NVRAM_IO_ERRNO_OK;
        }
        else
    #ifdef __SHADOW_SUPPORT_SB__
            status = NVRAM_IO_ERRNO_CHK;
    #else 
            ASSERT(0);
    #endif 
    }
#ifdef __SHADOW_SUPPORT_SB__
    else if (drv_status == NVRAM_DRV_ERASE_BUSY)
    {
        status = NVRAM_IO_ERRNO_BUSY;
    }
#endif /* __SHADOW_SUPPORT_SB__ */ 
    /* Sigh. Failed..... */
    else
#ifdef __SHADOW_SUPPORT_SB__
        status = NVRAM_IO_ERRNO_CHK;
#else 
        ASSERT(0);
#endif 

    return status;
}   /* end of nvram_write_data_item_single */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_data_item_multiple
 * DESCRIPTION
 *  This is nvram_write_data_item_multiple() function of NVRAM module.
 * PARAMETERS
 *  ldi             [?]         
 *  index           [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 *  is_init         [IN]        
 * RETURNS
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.
 *****************************************************************************/
static nvram_errno_enum nvram_write_data_item_multiple
    (ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *buffer, kal_uint16 buffer_size, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;
    nvram_drv_status_enum drv_status;

    kal_uint8 record_ID;
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = NVRAM_IO_ERRNO_CHK;

    for (record_ID = 0; record_ID < 2; record_ID++)
    {
        NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'a' + record_ID, ldi->fileverno);

        drv_status = nvram_drv_fat_write(buffer, nvramname, index, buffer_size, ldi->attr & NVRAM_ATTR_MSP, is_init);

        if (drv_status != NVRAM_DRV_OK)
        {
            kal_prompt_trace(
                MOD_NVRAM,
                "Write Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                ldi->LID,
                drv_status,
                nvram_fat_last_err,
                __LINE__);        
        }

        if (drv_status == NVRAM_DRV_EMPTY_RECORD)
        {
            drv_status = nvram_drv_fat_write(buffer, nvramname, ldi->total_records, buffer_size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);

            if (drv_status != NVRAM_DRV_OK)
            {
                kal_prompt_trace(
                    MOD_NVRAM,
                    "Write Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d",
                    ldi->LID,
                    drv_status,
                    nvram_fat_last_err,
                    __LINE__);        
            }
            
        }

        /* special error handling for NAND bad block */
        if (drv_status == FS_DATA_ERROR)
        {
            nvram_nand_error_handling(ldi, nvramname, buffer, buffer_size);
        }

        if (drv_status == NVRAM_DRV_OK)
        {
            status = NVRAM_IO_ERRNO_OK;
        }
    #ifdef __SHADOW_SUPPORT_SB__
        else if (drv_status == NVRAM_DRV_ERASE_BUSY)
        {
            status = NVRAM_IO_ERRNO_BUSY;
        }
    #endif /* __SHADOW_SUPPORT_SB__ */ 
        else
    #ifdef __SHADOW_SUPPORT_SB__
            status = NVRAM_IO_ERRNO_CHK;
    #else 
            ASSERT(0);
    #endif 
    }

    return status;
}   /* end of nvram_write_data_item_multiple */


#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  nvram_reset_data_item_difference
 * DESCRIPTION
 *  Resset only the difference of a data item
 * PARAMETERS
 *  ldi     [?]     the data item to reset
 * RETURNS
 *  True for success, and False for fail
 *****************************************************************************/
kal_bool nvram_reset_data_item_difference(ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 default_value_buffer_size, file_value_buffer_size;
    kal_uint8 *default_value_buffer, *file_value_buffer;
    ltable_entry_struct target;
    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];
    WCHAR filename[NVRAM_FILE_LEN + 1];
    FS_HANDLE handle;
    kal_char new_verno[FILE_VERNO_LEN + 1];
    kal_uint16 new_size;
    kal_bool lock_state = nvram_ptr->lock;
    kal_bool status = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Cannot allocate memory! */
    if ((default_value_buffer_size = nvram_ptr->max_record_size) & 1)
    {
        default_value_buffer_size += 1;
    }
    if ((default_value_buffer = (kal_uint8*) get_ctrl_buffer(default_value_buffer_size)) == NULL)
    {
        ASSERT(KAL_FALSE);
        return KAL_FALSE;
    }

    /* Since reset is highest priority, the software lock must be unlocked temporarily. */
    nvram_ptr->lock = KAL_FALSE;

    kal_mem_cpy(&target, ldi, sizeof(ltable_entry_struct));

    if ((default_value_buffer_size = target.size) & 1)
    {
        default_value_buffer_size += 1;
    }

    kal_wsprintf(namepattern, "%s\\%s*", NVRAM_FS_DATAITEM_PATH, target.fileprefix);

    /* find file by pattern "fileprefix*" */
    handle = FS_FindFirst(namepattern, 0, 0, &fileinfo, filename, FS_MAX_PATH);
    if (handle > 0)
    {
        nvram_get_default_value_to_write(&target, 0, default_value_buffer, default_value_buffer_size);
        file_value_buffer_size = fileinfo.FileSize - 2;

        /* backup LID info */
        strcpy(new_verno, target.fileverno);
        new_size = target.size;

        target.fileverno[0] = fileinfo.FileName[5];
        target.fileverno[1] = fileinfo.FileName[6];
        target.fileverno[2] = fileinfo.FileName[7];

        target.size = file_value_buffer_size;

        file_value_buffer = (kal_uint8*) get_ctrl_buffer(file_value_buffer_size);

        EXT_ASSERT(file_value_buffer, 0, 0, 0);

        nvram_read_data_item(&target, 1, 1, file_value_buffer, file_value_buffer_size);

        if ((file_value_buffer_size) < default_value_buffer_size)
        {
         /**
          * if file size < default size
          *replace default[0]~default[file size] with file[0]~file[file size]
          */
            kal_mem_cpy(default_value_buffer, file_value_buffer, file_value_buffer_size);
        }
        else if ((file_value_buffer_size) > default_value_buffer_size)
        {
         /**
          * if file size > default size
          * truncate file[0]~file[file size] to file[0]~file[default size]
          */
            kal_mem_cpy(default_value_buffer, file_value_buffer, default_value_buffer_size);
        }
        else;   /* The size is not changed. */

      /**
       *  update the file name associate the version
       *  kal_sprintf(verno_string,"%s",ldi->fileverno);
       */
        FS_Rename((WCHAR*) fileinfo.FileName, (WCHAR*) new_verno);
        target.size = new_size;

        if (file_value_buffer != NULL)
        {
            free_ctrl_buffer(file_value_buffer);
        }

    }
    else
    {
        return KAL_FALSE;
    }

    nvram_write_data_item(&target, target.total_records, default_value_buffer, KAL_TRUE);

    if (default_value_buffer != NULL)
    {
        free_ctrl_buffer(default_value_buffer);
    }

    /* Restore lock state */
    nvram_ptr->lock = lock_state;

    return status;
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_data_items
 * DESCRIPTION
 *  This is nvram_reset_data_item() function of NVRAM module.
 *  
 *  When invoking nvram_write_data_item(), `is_init' flag is ALWAYS TRUE;
 *  such that for each data item to be written:
 *  
 *  1. Driver Layer could delete records of the data item, if it
 *  already exists.
 *  (In current flash driver, namely fd, this function is fd_rcd_delete())
 *  
 *  2. Then Driver Layer write default value to each record of the data item.
 *  (In current flash driver, namely fd, this function is fd_rcd_initialize())
 *  
 *  This function may be invoked due to incompatible version.
 *  For data items located in the `reset_category',
 *  they may be (1) newly added, (2)newly removed, or (3)just default value modified.
 *  Consider invoking nvram_write_data_item() with `is_init' flag set to true for
 *  each case:
 *  (1) Newly added:
 *  Invoke fd_rcd_delete() to delete records of the data item is no effect.
 *  fd_rcd_initialize() will allocate spaces for that data item.
 *  
 *  (2) Newly deleted:
 *  This results in a effect of "shift" due to some data item LID's are deleted.
 *  It should be ok since fd_rcd_delete()/fd_rcd_initialize() will be called
 *  for each valid LID. Of course, some out-of-dated LID's are possibly
 *  left and occupies FLASH space.
 *  
 *  (3) Default value modified:
 *  This is ok.
 * PARAMETERS
 *  reset_category      [IN]        Coubld be NVRAM_RESET_ALL NVRAM_RESET_SYSTEM NVRAM_RESET_USER
 *  ldi                 [?]         
 * RETURNS
 *  
 *****************************************************************************/
/* __GEMINI__ */
kal_bool nvram_reset_data_items(nvram_reset_category_enum reset_category, ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount)
/* __GEMINI__ */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool lock_state = nvram_ptr->lock;
    kal_bool status = KAL_TRUE;

    kal_uint16 default_value_buffer_size, file_idx;
    kal_uint8 *default_value_buffer;
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((nvram_ptr->state == NVRAM_STATE_READY) && !NVRAM_IS_LID_VALID(ldi->LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

#ifdef __SECURITY_OTP__
    if(ldi->attr & NVRAM_ATTR_OTP)
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
            return KAL_TRUE;
        else
            return KAL_FALSE;
        
    }
#endif
    /* Cannot allocate memory! */
    if ((default_value_buffer_size = nvram_ptr->max_record_size) & 1)
    {
        default_value_buffer_size += 1;
    }

    if ((default_value_buffer = (kal_uint8*) get_ctrl_buffer(default_value_buffer_size)) == NULL)
    {
        ASSERT(KAL_FALSE);
        return KAL_FALSE;
    }

    /* Since reset is highest priority, the software lock must be unlocked temporarily. */
    nvram_ptr->lock = KAL_FALSE;

    /* Since entire logical data item is to be reset, nvram_write_data_item() is invoked. */
    switch (reset_category)
    {
        case NVRAM_RESET_CERTAIN:
        {

            if ((default_value_buffer_size = ldi->size) & 1)
            {
                default_value_buffer_size += 1; /* Make the buffer even */
            }

            /* For multi default value */
            for (i = rec_index; i < (rec_index + rec_amount); i++)
            {
                nvram_get_default_value_to_write(ldi, i, default_value_buffer, default_value_buffer_size);
            #ifdef __SHADOW_SUPPORT_SB__
                if ((nvram_ptr->state == NVRAM_STATE_READY)
                    && (NORMAL_BOOT == stack_query_boot_mode()) && (ldi->category & NVRAM_CATEGORY_SHADOW))
                {
                    nvram_add_shadow_request(ldi, i, default_value_buffer);

                    nvram_flush_shadow();   /* Should be moved out of the for loop */
                }
                else
            #elif defined(__SHADOW_SUPPORT_MS__)
                if ((nvram_ptr->state == NVRAM_STATE_READY) && (USBMS_BOOT == stack_query_boot_mode()))
                {
                    if (ldi->category & NVRAM_CATEGORY_SHADOW_MS)
                    {
                        nvram_add_shadow_request(ldi, i, default_value_buffer);
                    }
                }
            #endif /* __SHADOW_NVRAM__ */
                {
                    if ((ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                    {
                        nvram_write_data_item(ldi, i, default_value_buffer, KAL_FALSE);
                    }
                    else
                    {
                        nvram_write_data_item(ldi, ldi->total_records, default_value_buffer, KAL_TRUE);
                        break;
                    }
                }
            }
            break;
        }
        case NVRAM_RESET_ALL:
        case NVRAM_RESET_USER:
        case NVRAM_RESET_SYSTEM:
        {
        #ifdef __SHADOW_NVRAM__
            if (nvram_ptr->state != NVRAM_STATE_READY)
        #endif 
            {
                for (file_idx = NVRAM_EF_SYS_LID + 1; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
                {
                    if (!NVRAM_IS_LID_VALID(file_idx))
                    {
                        continue;
                    }

                    nvram_get_data_item(ldi, file_idx);

                #ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif        

                    if ((reset_category == NVRAM_RESET_ALL) || (ldi->category & reset_category))
                    {

                        for (i = 1; i < (ldi->total_records + 1); i++)
                        {
                            nvram_get_default_value_to_write(
                                ldi,
                                i,
                                default_value_buffer,
                                default_value_buffer_size);
                            if ((ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                            {
                                nvram_write_data_item(ldi, i, default_value_buffer, KAL_FALSE);
                            }
                            else
                            {
                                nvram_write_data_item(ldi, ldi->total_records, default_value_buffer, KAL_TRUE);
                                break;
                            }
                        }
                    }
                }
            }
            break;
        }
        case NVRAM_RESET_FACTORY:
        {
            if (nvram_ptr->state != NVRAM_STATE_READY)
            {
                kal_uint8 sys_cache[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
                
                nvram_get_data_item(ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);

                nvram_read_data_item(ldi, NVRAM_SYS_FACTORY_FLAG, 1, sys_cache, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

                if (sys_cache[0] == 1)
                {
                    nvram_factory_rmdir_user(reset_category);
                    sys_cache[0] = 0;
                    nvram_write_data_item(ldi, NVRAM_SYS_FACTORY_FLAG, sys_cache, KAL_FALSE);
                }
            }
            else
            {
                for (file_idx = NVRAM_EF_START; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
                {

                if (!NVRAM_IS_LID_VALID(file_idx))
                {
                    continue;
                }

                nvram_get_data_item(ldi, file_idx);
                
                #ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif        

                if ((ldi->category & NVRAM_CATEGORY_FACTORY))
                {
                    for (i = 1; i < (ldi->total_records + 1); i++)
                    {
                        nvram_get_default_value_to_write(
                            ldi,
                            i,
                            default_value_buffer,
                            default_value_buffer_size);
                    #ifdef __SHADOW_SUPPORT_SB__
                        if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
                        {
                            if ((ldi->category & NVRAM_CATEGORY_SHADOW))
                            {
                                nvram_add_shadow_request(
                                    ldi,
                                    (ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT) ? i : 0,
                                    default_value_buffer);
                                nvram_flush_shadow();
                            }
                            else
                            {
                                kal_bool LID_NOT_IN_SHADOW = KAL_FALSE;
                                EXT_ASSERT(LID_NOT_IN_SHADOW, ldi->LID, 0, 0);
                            }
                        }
                        else
                    #elif defined(__SHADOW_SUPPORT_MS__)
                        if ((nvram_ptr->state == NVRAM_STATE_READY) && (USBMS_BOOT == stack_query_boot_mode()))
                        {
                            if ((ldi->category & NVRAM_CATEGORY_SHADOW_MS))
                            {
                                nvram_add_shadow_request(
                                    ldi,
                                    (ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT) ? i : 0,
                                    default_value_buffer);
                            }
                        }
                        else
                    #endif /* __SHADOW_NVRAM__ */
                            nvram_write_data_item(
                                ldi,
                                (kal_uint16) ((ldi-> category & NVRAM_CATEGORY_MULTI_DEFAULT) ? i : ldi->total_records),
                                default_value_buffer,
                                !(ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT));

                        if (!(ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                        {
                            break;
                        }
                    }
                }
            }

            /* Reset MMI setting */
            nvram_factory_restore_setting();

                /* Reset those folders specified in nvram_user_config.c NVRAM_CLEAN_FOLDER_LIST */
            #ifdef __MULTI_BOOT__
                if (FACTORY_BOOT == stack_query_boot_mode())
                {
                    /* META mode only */
                    nvram_factory_rmdir_user(reset_category);
                }
                else
            #endif /* __MULTI_BOOT__ */ 
                {
                    kal_uint8 sys_cache[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
                    
                    memset(sys_cache, 0, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

                    sys_cache[0] = 1;
                    nvram_get_data_item(ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);

                    nvram_write_data_item(ldi, NVRAM_SYS_FACTORY_FLAG, sys_cache, KAL_FALSE);
                }
            }
            break;
        }
        case NVRAM_RESET_CUSTPACK:
        {
            for (file_idx = NVRAM_EF_START; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
            {
                if (!NVRAM_IS_LID_VALID(file_idx))
                {
                    continue;
                }

                nvram_get_data_item(ldi, file_idx);

                if (ldi->category & NVRAM_CATEGORY_CUSTPACK)
                {
                    for (i = 1; i < (ldi->total_records + 1); i++)
                    {
                        nvram_get_default_value_to_write(
                            ldi,
                            i,
                            default_value_buffer,
                            default_value_buffer_size);
                        if ((ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                        {
                            nvram_write_data_item(ldi, i, default_value_buffer, KAL_FALSE);
                        }
                        else
                        {
                            nvram_write_data_item(ldi, ldi->total_records, default_value_buffer, KAL_TRUE);
                            break;
                        }
                    }
                }
            }
            
            nvram_factory_rmdir_user(reset_category);
            
            break;
        }
        case NVRAM_RESET_BRANCH:
        {
            for (file_idx = NVRAM_EF_BRANCH_VERNO_LID; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
            {
                if (!NVRAM_IS_LID_VALID(file_idx))
                {
                    continue;
                }

                nvram_get_data_item(ldi, file_idx);

            #ifdef   __MTK_SECURE_PLATFORM__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif        

                if (!(ldi->category & NVRAM_CATEGORY_BRANCH))
                {
                    for (i = 1; i < (ldi->total_records + 1); i++)
                    {
                        nvram_get_default_value_to_write(
                            ldi,
                            i,
                            default_value_buffer,
                            default_value_buffer_size);
                        if ((ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                        {
                            nvram_write_data_item(ldi, i, default_value_buffer, KAL_FALSE);
                        }
                        else
                        {
                            nvram_write_data_item(ldi, ldi->total_records, default_value_buffer, KAL_TRUE);
                            break;
                        }
                    }
                }
            }

            nvram_factory_rmdir_user(reset_category);

            break;
        }
    #ifdef __SHADOW_SUPPORT_SB__
        case NVRAM_RESET_SHADOW:
        {
            if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
            {
                for (file_idx = NVRAM_EF_SYS_LID + 1; file_idx < nvram_ptr->ltable.total_LID; ++file_idx)
                {
                    if (!NVRAM_IS_LID_VALID(file_idx))
                    {
                        continue;
                    }

                    nvram_get_data_item(ldi, file_idx);

                    if (ldi->category & NVRAM_CATEGORY_SHADOW)
                    {
                        for (i = 1; i < (ldi->total_records + 1); i++)
                        {
                            nvram_get_default_value_to_write(
                                ldi,
                                i,
                                default_value_buffer,
                                default_value_buffer_size);
                            if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
                            {
                                if ((ldi->category & NVRAM_CATEGORY_SHADOW))
                                {
                                    nvram_add_shadow_request(
                                        ldi,
                                        (ldi-> category & NVRAM_CATEGORY_MULTI_DEFAULT) ? i : 0,
                                        default_value_buffer);
                                    nvram_flush_shadow();
                                }
                                else
                                {
                                    kal_bool LID_NOT_IN_SHADOW = KAL_FALSE;
                                    EXT_ASSERT(LID_NOT_IN_SHADOW, ldi->LID, 0, 0);
                                }
                            }
                            else
                            {
                                nvram_write_data_item(
                                    ldi,
                                    (ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT) ? i : ldi-> total_records,
                                    default_value_buffer,
                                    !(ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT));
                            }

                            if (!(ldi->category & NVRAM_CATEGORY_MULTI_DEFAULT))
                            {
                                break;
                            }
                        }
                    }
                }
            }

            break;
        }
    #endif /* __SHADOW_SUPPORT_SB__ */ 

        default:
        {
            ASSERT(KAL_FALSE);
            status = KAL_FALSE;
        }
    }

    if (default_value_buffer != NULL)
    {
        free_ctrl_buffer(default_value_buffer);
    }

    /* Restore lock state */
    nvram_ptr->lock = lock_state;

    return status;
}   /* end of nvram_reset_data_item */

#ifdef __SHADOW_NVRAM__
/*****************************************************************************
 * FUNCTION
 *  nvram_get_next_flush_lid
 * DESCRIPTION
 *  To get next flush lid
 * PARAMETERS
 *  void  
 * RETURNS
 *  kal_uint8 next_flush
 *****************************************************************************/
kal_uint8 nvram_get_next_flush_lid(void)
{
    return next_flush;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_total_dirty
 * DESCRIPTION
 *  To get total_dirty
 * PARAMETERS
 *  void  
 * RETURNS
 *  kal_uint8 total_dirty
 *****************************************************************************/
kal_uint8 nvram_get_total_dirty(void)
{
    return total_dirty;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_dirty_list
 * DESCRIPTION
 *  To get dirty_list
 * PARAMETERS
 *  list    [IN]    dirty_list
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_dirty_list(kal_uint8 *list)
{
    list = dirty_list;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_next_shadow_rec_to_flush
 * DESCRIPTION
 *  Find a dirty record to fulsh
 * PARAMETERS
 *  ldi                 [IN]        
 *  shadow_entry        [IN]        
 *  buffer              [IN]        
 *  rec_index           [IN]        
 * RETURNS
 *  Found or not.
 *****************************************************************************/
static nvram_errno_enum nvram_get_next_shadow_rec_to_flush
    (ltable_entry_struct *ldi, shadow_ltable_struct *shadow_entry, kal_uint8 **buffer, kal_uint16 *rec_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer && rec_index)
    {
        /* search all bits in the bit map, dirty_records */
        for (i = 1; i <= ldi->total_records; i++)
        {
            if (shadow_entry->dirty_records[i / 32] & (1 << (i % 32)))
            {
                    *buffer = shadow_entry->offset + (ldi->size * (i - 1));
                    *rec_index = i;
                return NVRAM_ERRNO_SUCCESS;
            }
        }
    }
    else
    {
        for (i = 0; i < NVRAM_MAX_SHADOW_REC; ++i)
        {
            if (shadow_entry->dirty_records[i] != 0)
                return NVRAM_ERRNO_SUCCESS;
        }
    }
    return NVRAM_ERRNO_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_set_shadow_rec_flag
 * DESCRIPTION
 *  Set or Reset the dirtry flag in bit map
 * PARAMETERS
 *  shadow_entry        [IN]        
 *  rec_index           [IN]        
 *  isDirty             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_set_shadow_rec_flag(shadow_ltable_struct *shadow_entry, kal_uint16 rec_index, kal_bool isDirty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Always start from record 1 */
    
    if (isDirty)
    {
        shadow_entry->dirty_records[rec_index / 32] |= (1 << (rec_index % 32));
    }
    else
    {
        shadow_entry->dirty_records[rec_index / 32] &= (~(1 << (rec_index % 32)));
    }

}


/*****************************************************************************
 * FUNCTION
 *  nvram_add_shadow_request
 * DESCRIPTION
 *  Add a write request to dirty list
 * PARAMETERS
 *  ldi             [IN]        
 *  rec_index       [IN]        
 *  buffer          [IN]        
 * RETURNS
 *  Always success
 *****************************************************************************/
nvram_errno_enum nvram_add_shadow_request(ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    shadow_ltable_struct *shadow_entry = &shadow_ltable[ldi->record_ID];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvram_get_next_shadow_rec_to_flush(ldi, shadow_entry, NULL, NULL) == NVRAM_ERRNO_FAIL)
    {

        dirty_list[next_request] = ldi->LID;

        if (++next_request >= shadow_item_total)
        {
            next_request = 0;
        }

        ++total_dirty;
    }

    if (rec_index > 0)
    {
        kal_mem_cpy(shadow_entry->offset + ((rec_index - 1) * ldi->size), buffer, ldi->size);

        nvram_set_shadow_rec_flag(shadow_entry, rec_index, KAL_TRUE);
    }
    else
    {
        for (rec_index = 1; rec_index <= (ldi->total_records); rec_index++)
        {
            kal_mem_cpy(shadow_entry->offset + ((rec_index - 1) * ldi->size), buffer, ldi->size);

            nvram_set_shadow_rec_flag(shadow_entry, rec_index, KAL_TRUE);

        }
    }
    return NVRAM_ERRNO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_flush_shadow
 * DESCRIPTION
 *  Flush Shadow Buffer to the flash
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_flush_shadow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum result;
    kal_uint16 rec_index;
    kal_uint8 *buffer = NULL;
    shadow_ltable_struct *shadow_entry;
    ltable_entry_struct *ldi;
    kal_uint8 LID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SHADOW_SUPPORT_SB__
    ASSERT(NORMAL_BOOT == stack_query_boot_mode());
#else /* __SHADOW_SUPPORT_SB__ */ /* __SHADOW_SUPPORT_MS__ */
    if (nvram_ptr->state == NVRAM_STATE_READY)
    {
        return;
    }
#endif /* __SHADOW_SUPPORT_SB__ */ /* __SHADOW_NVRAM__ */

    ASSERT(ShadowBuffer[0] == 0xF1 &&
           ShadowBuffer[1] == 0xF1 && 
           ShadowBuffer[shadow_buffer_size - GUARD_PATTERN_SIZE] == 0xF2 &&
           ShadowBuffer[shadow_buffer_size - GUARD_PATTERN_SIZE + 1] == 0xF2 );

    while (total_dirty && (total_dirty >= dirty_threshold))
    {
        LID = dirty_list[next_flush];

        nvram_get_data_item(ldi, LID);

        shadow_entry = &shadow_ltable[ldi->record_ID];
        result = nvram_get_next_shadow_rec_to_flush(ldi, shadow_entry, &buffer, &rec_index);

        if (result == NVRAM_ERRNO_SUCCESS)
        {
            result = nvram_write_data_item(ldi, rec_index, buffer, KAL_FALSE);
            WDT_Restart2();
            kal_prompt_trace(MOD_NVRAM, "Flush Shadow item = %s, rec# = %d, result = %d, Total dirty=%d", ldi->description, rec_index, result, total_dirty);
        }
        else
        {

            if (++next_flush >= shadow_item_total)
            {
                next_flush = 0;
            }

            if (total_dirty > 0)
            {
                --total_dirty;
            }

        #ifdef __SHADOW_SUPPORT_SB__
            if ((total_dirty >= dirty_threshold) && (nvram_ptr->state == NVRAM_STATE_READY))
            {
                nvram_restart_timer();
            }
            else
            {
                nvram_stop_timer();
            }
        #endif /* __SHADOW_SUPPORT_SB__ */ 
            result = NVRAM_ERRNO_SUCCESS;

        }

        if (result != NVRAM_IO_ERRNO_OK)
        {
        #ifdef __SHADOW_SUPPORT_SB__
            if ((total_dirty >= dirty_threshold) && (nvram_ptr->state == NVRAM_STATE_READY))
            {
                nvram_restart_timer();
            }
            else
            {
                nvram_stop_timer();
            }
        #endif /* __SHADOW_SUPPORT_SB__ */ 
            break;

        }
        else
        {
            nvram_set_shadow_rec_flag(shadow_entry, rec_index, KAL_FALSE);
        }

    }
}

#endif /* __SHADOW_NVRAM__ */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_factory_restore_setting
 * DESCRIPTION
 *  Restore MMI Cache settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_factory_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 LID, i;
    ltable_entry_struct *ldi;
    kal_uint8 *buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_CACHE_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer);

    for (i = 0; i < 3; i++)
    {
        LID = NVRAM_EF_CACHE_BYTE_LID + i;
        nvram_get_data_item(ldi, LID);

        nvram_read_data_item(ldi, 1, 1, buffer, NVRAM_CACHE_SIZE);
        if (LID == NVRAM_EF_CACHE_BYTE_LID) /* reset settings in CACHE_BYTE */
        {
            nvram_restore_byte_cache(buffer);
        }
        else if (LID == NVRAM_EF_CACHE_SHORT_LID)   /* reset settings in CACHE_SHORT */
        {
            nvram_restore_short_cache((kal_uint16*) buffer);
        }
        else if (LID == NVRAM_EF_CACHE_DOUBLE_LID)  /* reset settings in CACHE_DOUBLE */
        {
            nvram_restore_double_cache((kal_uint32*) buffer);
        }
    #ifdef __SHADOW_SUPPORT_SB__
        if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
        {

            nvram_add_shadow_request(ldi, 1, buffer);

            nvram_flush_shadow();   /* Should be moved out of the for loop */
        }
        else
    #endif /* __SHADOW_SUPPORT_SB__ */ 
            nvram_write_data_item(ldi, 1, buffer, KAL_FALSE);

    }

    if (buffer)
    {
        free_ctrl_buffer(buffer);
    }

}


/*****************************************************************************
 * FUNCTION
 *  nvram_factory_rmdir_user
 * DESCRIPTION
 *  Remove customizable folder list
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or not
 *****************************************************************************/
static kal_bool nvram_factory_rmdir_user(nvram_reset_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 dir_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dir_idx = 0; dir_idx < NVRAM_MAX_CLEAN_FOLDERS; dir_idx++)
    {

        if (NVRAM_CLEAN_FOLDER_LIST[dir_idx] != NULL)
        {
            FS_XDelete(NVRAM_CLEAN_FOLDER_LIST[dir_idx], (FS_FILE_TYPE | FS_RECURSIVE_TYPE), NULL, 0);
        }
        
        if (category != NVRAM_RESET_CUSTPACK)
        {
            if (NVRAM_COMMON_CLEAN_FOLDER_LIST[dir_idx] != NULL)
            {
                FS_XDelete(NVRAM_COMMON_CLEAN_FOLDER_LIST[dir_idx], (FS_FILE_TYPE | FS_RECURSIVE_TYPE), NULL, 0);
            }
        }
    }
    return KAL_TRUE;
}


#ifdef __SECURITY_OTP__
#ifndef __MTK_TARGET__

ltable_entry_struct ldi_otp =
{
    NVRAM_EF_LAST_LID_CUST + 1,
    256,
    1,
    NVRAM_EF_ZERO_DEFAULT,
    NVRAM_ATTR_AVERAGE,
    NVRAM_CATEGORY_COMPOSED,
    "CT05",
    "000",
    "Fake OTP\0",
    NVRAM_RESERVED_VALUE
};

int OTP_Read_FAKE(kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_uint16 chksum1 = 0, chksum2 = 0;
    kal_uint32 i;
    NVRAM_FILE_NAME nvramname;
    ltable_entry_struct *ldi = &ldi_otp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(BufferPtr);
    
    NVRAM_MAKE_LID_FILENAME(nvramname, ldi.fileprefix, '_', ldi.fileverno);

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (hFile == FS_FILE_NOT_FOUND)
    {
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }

    len = 256;
    if((Offset + Length) > len)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_OVERSCOPE;
    }
    
    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, BufferPtr, Length, &len);
    }

    if (Ret != FS_NO_ERROR)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


int OTP_Write_FAKE(kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_int32 openOption = FS_READ_WRITE | FS_OPEN_NO_DIR;
    kal_uint16 chksum = 0;
    kal_uint8 *buffer_with_chksum;
    NVRAM_FILE_NAME nvramname;
    ltable_entry_struct *ldi = &ldi_otp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, '_', ldi->fileverno);

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    openOption |= FS_CREATE;
    openOption |= FS_PROTECTION_MODE;
    openOption |= FS_READ_WRITE;

    kal_prompt_trace(MOD_NVRAM, "OTP Write Area: %x~%x", Offset, Offset+Length-1);
    
    hFile = FS_Open((const TCHAR*)filename, openOption);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            kal_prompt_trace(MOD_NVRAM, "Init OTP");
            /* Reinitialize, Create always, No committed */
            openOption |= FS_CREATE_ALWAYS;
            hFile = FS_Open((const TCHAR*)filename, openOption);    
            if(hFile >= FS_NO_ERROR)
            {
                buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
                ASSERT(buffer_with_chksum);
                memset(buffer_with_chksum, 0x00, Length);
                /* init fake OTP file */
                Ret = FS_Write(hFile, buffer_with_chksum, ldi->size, &len);
                ASSERT(Ret >= FS_NO_ERROR)
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return NVRAM_DRV_OK;
            }
        }
        else
            return FS_FLASH_OTP_WRITEFAIL;
    }
    ASSERT(hFile >= FS_NO_ERROR);

    /* start write */
    
    /* Update one of the sections if linear-fixed */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            FS_Close(hFile);

            kal_prompt_trace(MOD_NVRAM, "Init OTP");
            /* Reinitialize, Create always, No committed */
            openOption |= FS_CREATE_ALWAYS;
            hFile = FS_Open((const TCHAR*)filename, openOption);    
            if(hFile >= FS_NO_ERROR)
            {
                buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
                ASSERT(buffer_with_chksum);
                memset(buffer_with_chksum, 0x00, Length);
                /* init fake OTP file */
                Ret = FS_Write(hFile, buffer_with_chksum, ldi->size, &len);
                ASSERT(Ret >= FS_NO_ERROR)
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return NVRAM_DRV_OK;
            }
        }
        else
            return FS_FLASH_OTP_WRITEFAIL;

    }

    /* seek to the section start in this record */
    Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        kal_uint8 i = 0;
        
        kal_prompt_trace(MOD_NVRAM, "OTP Area Allowed: %x~%x", Ret, Ret+Length-1);
        buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
        ASSERT(buffer_with_chksum);
        Ret = FS_Read(hFile, buffer_with_chksum, Length, &len);
        for(i = 0; i< Length; ++i)
        {
            if(buffer_with_chksum[i])
            {
                kal_prompt_trace(MOD_NVRAM, "OTP Area programmed twice: %x~%x", Offset, Offset+Length-1);
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return FS_FLASH_OTP_WRITEFAIL;
            }
        }
        
        kal_mem_cpy(buffer_with_chksum, BufferPtr, Length);
        Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);

        Ret = FS_Write(hFile, buffer_with_chksum, Length, &len);
        ASSERT(Ret == FS_NO_ERROR);
        if (Ret != FS_NO_ERROR)
        {
            free_ctrl_buffer(buffer_with_chksum);
            FS_Close(hFile);
            return Ret;
        }
        free_ctrl_buffer(buffer_with_chksum);
    }
    else
    {
        FS_Close(hFile);
        kal_prompt_trace(MOD_NVRAM, "OTP Area Overscope: 0x%X~0x%X", Offset, Offset+Length-1);
        return FS_FLASH_OTP_OVERSCOPE;
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
* FUNCTION
*  nvram_read_otp_data_item
* DESCRIPTION
*	Read OTP data
* PARAMETERS
* RETURNS
*  NVRAM error code.
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
nvram_errno_enum nvram_read_otp_data_item(ltable_entry_struct* ldi, kal_uint8* buffer, kal_uint16 buffer_size)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    kal_uint32 offset = 0;
    kal_int32  result;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    if(!(ldi->attr & NVRAM_ATTR_OTP))
        return NVRAM_ERRNO_INVALID;
    
    nvram_get_otp_offset(offset, ldi->LID);


#ifndef __MTK_TARGET__
    result = OTP_Read_FAKE(offset, buffer, buffer_size);
#else
    result = FS_OTPRead(FS_DEVICE_TYPE_NOR, offset, buffer, buffer_size);
#endif

    kal_prompt_trace(MOD_NVRAM, "OTP_Read result = %d, range =%x : %x", result, offset, offset+ldi->size-1);

    if(result < FS_NO_ERROR)
        return NVRAM_ERRNO_FAIL;
    else
        return NVRAM_ERRNO_SUCCESS;

}


/*****************************************************************************
* FUNCTION
*  nvram_write_otp_data_item
* DESCRIPTION
*	Write OTP data
* PARAMETERS
* RETURNS
*  NVRAM error code.
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
nvram_errno_enum nvram_write_otp_data_item(ltable_entry_struct* ldi, kal_uint8* data)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 offset;
   kal_int32 result;
   kal_uint32 fs_otp_size;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    if(!(ldi->attr & NVRAM_ATTR_OTP) 
#ifndef __MTK_TARGET__
        && !(ldi->category & NVRAM_CATEGORY_COMPOSED)
#endif  
      )
        return NVRAM_ERRNO_INVALID;

#ifndef __MTK_TARGET__
    if(ldi->attr & NVRAM_ATTR_OTP)
#endif
    {
        nvram_get_otp_offset(offset, ldi->LID);
    }

#ifdef __MTK_TARGET__
    FS_OTPQueryLength(FS_DEVICE_TYPE_NOR, &fs_otp_size);
#else
    fs_otp_size = 256;
#endif

    if((offset + ldi->size) < fs_otp_size)
#ifndef __MTK_TARGET__
    {
        result = OTP_Write_FAKE(offset, data, ldi->size);
    }
#else
    {
        
        kal_uint32 i = 0;
        kal_uint8 is_empty = 1;
        kal_uint8 *buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);
        ASSERT(buffer);
        FS_OTPRead(FS_DEVICE_TYPE_NOR, offset, buffer, ldi->size);
        for (; i< ldi->size; i++)
        {
            if (buffer[i] != 0xFF)
            {
                free_ctrl_buffer(buffer);
                kal_prompt_trace(MOD_NVRAM, "OTP Area programmed twice: %x~%x", offset, offset+ldi->size-1);
                return NVRAM_ERRNO_OTP_WRITETWICE;
            }
            if (data[i] != 0xFF)
            {
                is_empty = 0;
            }
        }
        free_ctrl_buffer(buffer);

        if (is_empty)
            return NVRAM_ERRNO_OTP_INVALID_INPUT;
        
        result = FS_OTPWrite(FS_DEVICE_TYPE_NOR, offset, data, ldi->size);
    }
#endif
    else
        return NVRAM_ERRNO_OTP_INVALID_RANGE;

    kal_prompt_trace(MOD_NVRAM, "OTP_Write result = %d", result);

    switch(result)
    {
        case FS_FLASH_OTP_UNKNOWERR: /* -123 */
            return NVRAM_ERRNO_OTP_UNKNOW;
        case FS_FLASH_OTP_OVERSCOPE: /* -124 */
            return NVRAM_ERRNO_OTP_OVERSCOPE;
        case FS_FLASH_OTP_WRITEFAIL:/* -125 */
            return NVRAM_ERRNO_OTP_WRITEFAIL;
        default:
            if(result < FS_NO_ERROR)
                return NVRAM_ERRNO_FAIL;
            else
                return NVRAM_ERRNO_SUCCESS;
        
    }
}

#endif /*__SECURITY_OTP__*/

