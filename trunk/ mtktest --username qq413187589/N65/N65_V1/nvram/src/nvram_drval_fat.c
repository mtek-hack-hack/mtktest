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
 * nvram_drval_fat.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is Driver adaption level functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdio.h"
#include "fat_fs.h"

#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stack_common.h"
#include "stack_msgs.h"

#include "nvram_drval_fat.h"
#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_context.h"
#include "nvram_data_items.h"
#include "nvram_trc.h"

#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */ 

#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
#endif
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static kal_uint8 nvram_drval_max_rcd;
static kal_uint8 nvram_drval_dsp_exception_cnt = 0;

kal_int32 nvram_fat_last_err;
kal_uint32 nvram_fat_last_line;

/*****************************************************************************
 * FUNCTION
 *  nvram_drval_write_dsp_exception
 * DESCRIPTION
 *  write dsp exception "file" (not NVRAM data items) to flash.
 * PARAMETERS
 *  length      [IN]        
 *  record      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drval_write_dsp_exception(kal_uint16 length, kal_uint8 *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile = 0;

    TCHAR filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_FS_MAKE_DSP_EXCEP_FILENAME(filename);

    if (!nvram_drval_dsp_exception_cnt)
        /* First time, Create always, No committed */
    {
        hFile = FS_Open((const TCHAR*)filename, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_OPEN_NO_DIR);
    }
    else
    {
        hFile = FS_Open((const TCHAR*)filename, FS_CREATE | FS_READ_WRITE | FS_OPEN_NO_DIR);
    }

    if (hFile > FS_NO_ERROR)
    {
        nvram_drval_dsp_exception_cnt++;

        FS_Seek(hFile, 0, FS_FILE_END);
        FS_Write(hFile, record, length, NULL);

        FS_Close(hFile);
    }

}   /* end of nvram_drval_write_dsp_exception */


/*****************************************************************************
 * FUNCTION
 *  nvram_drval_caculate_checksum
 * DESCRIPTION
 *  produce the check sum of the given record.
 * PARAMETERS
 *  checksum        [?]         
 *  buf             [?]         
 *  size            [IN]        
 * RETURNS
 *  checksum(?)
 *****************************************************************************/
void nvram_drval_caculate_checksum(kal_uint16 *checksum, kal_uint8 *buf, kal_uint16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint8 *byte_chksum = (kal_uint8*) checksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checksum = 0;
    for (i = 0; i < size; i++)
    {
        if (i & 0x1)
        {
            *(byte_chksum + 1) += *(buf + i);
        }
        else
        {
            *byte_chksum += *(buf + i);
        }
    }
}   /* end of nvram_drval_caculate_checksum */


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_init
 * DESCRIPTION
 *  This is nvram_drv_fat_init() function of NVRAM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  if NVRAM folder does not exist, it means the FAT is empty.
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile;
    kal_int32 Ret;
    nvram_drv_status_enum format_state = NVRAM_DRV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Prevent human error! Define NVRAM_MAX_PATH_LEN is less than actual maximum path length
     * Actually path length is length of path(18) + filename(12) + null-terminator(1)
     */
    Ret = NVRAM_FS_GET_FULL_PATH_LEN;
    ASSERT(NVRAM_MAX_PATH_LEN > Ret);

    /* check nvram root folder, if not exist, create it! */
    NVRAM_FS_MAKE_ROOT_PATH(filename);
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_DIR);
    if (hFile == FS_FILE_NOT_FOUND || hFile == FS_PATH_NOT_FOUND)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const TCHAR*)filename);
        EXT_ASSERT(Ret == FS_NO_ERROR, (kal_uint32) Ret, 0, 0);
        format_state = NVRAM_DRV_UNFORMATTED;
    }
    else if (hFile == FS_FDM_USER_DRIVE_BROKEN ||
             hFile == FS_FDM_SYS_DRIVE_BROKEN ||
             hFile == FS_FDM_MULTIPLE_BROKEN)
    {
        return NVRAM_DRV_DRIVE_BROKEN;
    }
    else if (hFile == FS_FDM_VERSION_MISMATCH)
    {
        return NVRAM_DRV_DRIVE_VNOERR;
    }
    else if (hFile > FS_NO_ERROR)   /* Success */
    {
        FS_Close(hFile);
    }
    else
    {
        EXT_ASSERT(KAL_FALSE, (kal_uint32) hFile, 0, 0);    /* Other case should not occur */
        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check USER folder, if not exist, create it! */
    NVRAM_FS_MAKE_USER_PATH(filename);
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_DIR);
    if (hFile == FS_FILE_NOT_FOUND || hFile == FS_PATH_NOT_FOUND)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const TCHAR*)filename);
    }
    else if (hFile > FS_NO_ERROR)   /* Success */
    {
        FS_Close(hFile);
    }
    else
    {
        EXT_ASSERT(KAL_FALSE, (kal_uint32) hFile, 0, 0);    /* Other case should not occur */
        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check nvram data folder, if not exist, create it! */
    NVRAM_FS_MAKE_DATAITEM_PATH(filename);
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_DIR);
    if (hFile == FS_FILE_NOT_FOUND)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const TCHAR*)filename);
        EXT_ASSERT(Ret == FS_NO_ERROR, (kal_uint32) Ret, 0, 0);
        format_state = NVRAM_DRV_UNFORMATTED;
    }
    else if (hFile > FS_NO_ERROR)
    {
        FS_Close(hFile);
    }
    else
    {
        EXT_ASSERT(KAL_FALSE, (kal_uint32) hFile, 0, 0);    /* Other case should not occur */
        return NVRAM_DRV_FATAL_ERROR;
    }

    return format_state;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_format
 * DESCRIPTION
 *  Dummy format function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drv_fat_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Folder is ready as init, nothing to do in format */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_read
 * DESCRIPTION
 *  read record from FAT.
 * PARAMETERS
 *  nvramname           [?]         
 *  section_number      [IN]        
 *  amount              [IN]        
 *  buffer              [?]         
 *  size                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_read(kal_char *nvramname, 
                                         kal_uint16 section_number, 
                                         kal_uint16 amount, 
                                         kal_uint8 *buffer, /* size*amount */ 
                                         kal_uint16 size, /* size of one record */
                                         kal_bool ismsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_uint16 chksum1 = 0, chksum2 = 0;
    kal_uint32 i, remainLen = 0;
    kal_uint8 *buffer_with_chksum = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined(__MTK_SECURE_PLATFORM__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    ismsp = KAL_FALSE;
    remainLen = 0;
#endif /* __MTK_SECURE_PLATFORM__  && __MTK_TARGET__ */

    buffer_with_chksum = (kal_uint8*) get_ctrl_buffer((size + NVRAM_CHKSUM_SIZE + remainLen) * amount);
    ASSERT(buffer_with_chksum != NULL);
    if (section_number < 1)
    {
        nvram_fat_last_err = NVRAM_DRV_INVALID_RECORD_ID;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: NVRAM_DRV_INVALID_RECORD_ID");
        free_ctrl_buffer(buffer_with_chksum);
        return NVRAM_DRV_INVALID_RECORD_ID;
    }

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (hFile == FS_FILE_NOT_FOUND)
    {
        nvram_fat_last_err = NVRAM_DRV_EMPTY_RECORD;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: NVRAM_DRV_EMPTY_RECORD");
        free_ctrl_buffer(buffer_with_chksum);
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        nvram_fat_last_err = hFile;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: FS_Open = %d", hFile);
        free_ctrl_buffer(buffer_with_chksum);
        FS_Close(hFile);
        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        nvram_fat_last_err = NVRAM_DRV_EMPTY_RECORD;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: NVRAM_DRV_EMPTY_RECORD");
        free_ctrl_buffer(buffer_with_chksum);
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, (section_number - 1) * (size + NVRAM_CHKSUM_SIZE + remainLen), FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, buffer_with_chksum, (kal_uint32) ((size + NVRAM_CHKSUM_SIZE + remainLen) * amount), &len);
    }
    else
    {
        nvram_fat_last_err = Ret;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: FS_Seek = %d", Ret);        
        free_ctrl_buffer(buffer_with_chksum);
        FS_Close(hFile);
        return NVRAM_DRV_FATAL_ERROR;
    }
    
    if (Ret != FS_NO_ERROR)
    {
        nvram_fat_last_err = Ret;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: FS_Read = %d", Ret);
        free_ctrl_buffer(buffer_with_chksum);
        FS_Close(hFile);
        return NVRAM_DRV_FATAL_ERROR;
    }

#if defined(__MTK_SECURE_PLATFORM__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__  && __MTK_TARGET__ */

    /* Handle multi-record reading */
    for (i = 0; i < amount; i++)
    {
        if (ismsp && remainLen)
        {
            /* checksum from file */
            /*
             *   |         content              | chksum1 | chksum2 | padding |
             *   |         content              | chksum1 | chksum2 | padding |
             *   |         content              |    *    |    *    |
             */
            chksum2  = *(kal_uint8*) (buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE + remainLen) * i + size);
            chksum2 |= *(kal_uint8*) (buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE + remainLen) * i + size + 1) << 8;
            
            /* checksum from content */
            nvram_drval_caculate_checksum(&chksum1, buffer_with_chksum + ((size + NVRAM_CHKSUM_SIZE + remainLen) * i), size);
        }
        else
        {
            /* checksum from file */
            /*
             *   |         content              | chksum1 | chksum2 |
             *   |         content              | chksum1 | chksum2 |
             *   |         content              |    *    |    *    |
             */
            chksum2 = *(kal_uint8*) (buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE) * i + size);
            chksum2 |= *(kal_uint8*) (buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE) * i + size + 1) << 8;

            /* checksum from content */
            nvram_drval_caculate_checksum(&chksum1, buffer_with_chksum + ((size + NVRAM_CHKSUM_SIZE) * i), size);
        }


        if ((chksum1 != chksum2))
        {
            nvram_fat_last_err = NVRAM_DRV_CHECKSUM_ERROR;
            nvram_fat_last_line = __LINE__;
            kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_read: NVRAM_DRV_CHECKSUM_ERROR");
            
            free_ctrl_buffer(buffer_with_chksum);
            FS_Close(hFile);
            return NVRAM_DRV_CHECKSUM_ERROR;
        }
        if (ismsp && remainLen)
        {
            kal_mem_cpy(buffer + (size * i), buffer_with_chksum + ((size + NVRAM_CHKSUM_SIZE + remainLen) * i), size);
        }
        else
        {
            kal_mem_cpy(buffer + (size * i), buffer_with_chksum + ((size + NVRAM_CHKSUM_SIZE) * i), size);
        }
        
    }   /* for(i=0;i<amount;i++) */
    free_ctrl_buffer(buffer_with_chksum);
    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_read_exception_item
 * DESCRIPTION
 *  read exception record from FAT.
 * PARAMETERS
 *  buffer              [?]         
 *  nvramname           [?]         
 *  section_number      [IN]        
 *  size                [IN]        
 *  readsize            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_read_exception_item
    (kal_uint8 *buffer, kal_char *nvramname, kal_uint16 section_number, kal_uint16 size, kal_uint16 readsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (section_number < 1)
    {
        /* kal_print("Nvram write: section_number < 1 !"); */
        return NVRAM_DRV_INVALID_RECORD_ID;
    }

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        /* kal_print("Nvram read: FS_Open return error!"); */
        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, (section_number - 1) * (size + sizeof(kal_uint16)), FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, buffer, (kal_uint32) readsize, &len);
    }

    if (Ret != FS_NO_ERROR)
    {
        /* kal_print("Nvram read: Read error!"); */
        FS_Close(hFile);
        return NVRAM_DRV_CHECKSUM_ERROR;
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write
 * DESCRIPTION
 *  write record(s) to FAT.
 * PARAMETERS
 *  buffer              [?]         
 *  nvramname           [?]         
 *  section_number      [IN]        
 *  size                [IN]        
 *  initialize          [IN]        true for reset, false for normal write.
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_write(kal_uint8 *buffer, 
                                          kal_char *nvramname, 
                                          kal_uint16 section_number, 
                                          kal_uint16 size, 
                                          kal_bool ismsp,
                                          kal_bool initialize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0, remainLen = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_int32 openOption = FS_READ_WRITE | FS_OPEN_NO_DIR;
    kal_uint16 chksum = 0;
    kal_uint8 *buffer_with_chksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (section_number < 1)
    {
        nvram_fat_last_err = NVRAM_DRV_INVALID_RECORD_ID;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "invalid record#=%d", section_number);
        return NVRAM_DRV_INVALID_RECORD_ID;
    }

#if defined(__MTK_SECURE_PLATFORM__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    ismsp = KAL_FALSE;
    remainLen = 0;
#endif /* __MTK_SECURE_PLATFORM__  && __MTK_TARGET__ */

    nvram_drval_caculate_checksum(&chksum, buffer, size);

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    if (initialize == KAL_TRUE)
    {
        /* Reinitialize, Create always, No committed */
        openOption |= FS_CREATE_ALWAYS;
    }
    else
    {
        openOption |= FS_CREATE;
    #if !defined(_NAND_FLASH_BOOTING_) && !defined(__SHADOW_SUPPORT_SB__) && !defined(__FS_SYSDRV_ON_NAND__)
        openOption |= FS_PROTECTION_MODE;   /* boot from NAND and single bank NOR don't support this */
    #endif 
    }

#ifdef __SHADOW_SUPPORT_SB__
    if ((nvram_ptr->state == NVRAM_STATE_READY) && (NORMAL_BOOT == stack_query_boot_mode()))
    {
        openOption |= FS_NONBLOCK_MODE;
    }
    else
    {
        openOption |= FS_COMMITTED; /* force to flush FS level buffer */
    }
#endif /* __SHADOW_SUPPORT_SB__ */ 

    hFile = FS_Open((const TCHAR*)filename, openOption);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        nvram_fat_last_err = hFile;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "FS_Open status:FS_FILE_NOT_FOUND");
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }
#ifdef __SHADOW_SUPPORT_SB__
    else if (hFile == FS_FLASH_ERASE_BUSY)
    {
        nvram_fat_last_err = hFile;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "FS_Open status: FS_FLASH_ERASE_BUSY");
        FS_Close(hFile);
        return NVRAM_DRV_ERASE_BUSY;
    }
#endif /* __SHADOW_SUPPORT_SB__ */ 
    else if (hFile <= FS_NO_ERROR)
    {
        nvram_fat_last_err = hFile;
        nvram_fat_last_line = __LINE__;
        kal_prompt_trace(MOD_NVRAM, "FS_Open status: %d", hFile);
        FS_Close(hFile);
        return hFile;
    }

    /* start write */
    if (initialize == KAL_TRUE)
    {
        /* Multiple-default data items won't reach here */
        /* Reset all sections to default value, section_number is total section number of this rcd */
        kal_uint16 rec_index = 1;

        for (rec_index = 1; rec_index <= section_number; rec_index++)
        {
            kal_uint16 rec_amount = (section_number - rec_index + 1);
            kal_uint16 i = 0;

            if (rec_amount * (size + NVRAM_CHKSUM_SIZE + remainLen) > MAX_NVRAM_RECORD_SIZE)
            {
                rec_amount = MAX_NVRAM_RECORD_SIZE / (size + NVRAM_CHKSUM_SIZE + remainLen);
            }

            buffer_with_chksum = (kal_uint8*) get_ctrl_buffer((size + NVRAM_CHKSUM_SIZE + remainLen) * rec_amount);;
            ASSERT(buffer_with_chksum != NULL);

            for (i = 0; i < rec_amount; i++)    /* fill buffer_with_chksum with buffer+check sum */
            {
                if (ismsp)
                {
                    kal_mem_cpy(buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE + remainLen) * i, buffer, size);
                    kal_mem_cpy(buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE + remainLen) * i + size, &chksum, NVRAM_CHKSUM_SIZE);
                    kal_mem_set(buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE + remainLen) * i + size+ NVRAM_CHKSUM_SIZE, 0x00, remainLen);

                #if defined(__MTK_SECURE_PLATFORM__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* __MTK_SECURE_PLATFORM__  && __MTK_TARGET__ */    
                }
                else
                {
                    kal_mem_cpy(buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE) * i, buffer, size);
                    kal_mem_cpy(buffer_with_chksum + (size + NVRAM_CHKSUM_SIZE) * i + size, &chksum, NVRAM_CHKSUM_SIZE);
                }
            }


            Ret = FS_Write(hFile, buffer_with_chksum, (kal_uint32) (size + NVRAM_CHKSUM_SIZE + remainLen) * rec_amount, &len);
            if (Ret != FS_NO_ERROR)
            {
                nvram_fat_last_err = Ret;
                nvram_fat_last_line = __LINE__;
                kal_prompt_trace(MOD_NVRAM, "FS_Write(chksum) status= %d", hFile);

                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return Ret;
            }

            rec_index += (rec_amount - 1);
            free_ctrl_buffer(buffer_with_chksum);
        }
    }
    else
    {
        /* Update one of the sections if linear-fixed */
        Ret = FS_GetFileSize(hFile, &len);
        if ((Ret == FS_NO_ERROR) && (len == 0))
        {
            nvram_fat_last_err = NVRAM_DRV_EMPTY_RECORD;
            nvram_fat_last_line = __LINE__;
            kal_prompt_trace(MOD_NVRAM, "FS_GetFileSize: len is 0");

            FS_Close(hFile);
            return NVRAM_DRV_EMPTY_RECORD;
        }

        /* seek to the section start in this record */
        Ret = FS_Seek(hFile, (section_number - 1) * (size + NVRAM_CHKSUM_SIZE + remainLen), FS_FILE_BEGIN);
        if (Ret >= FS_NO_ERROR)
        {
            buffer_with_chksum = (kal_uint8*) get_ctrl_buffer((size + NVRAM_CHKSUM_SIZE + remainLen));
            ASSERT(buffer_with_chksum != NULL);

            if (ismsp && remainLen)
            {
                kal_mem_cpy(buffer_with_chksum, buffer, size);
                kal_mem_cpy(buffer_with_chksum + size, &chksum, NVRAM_CHKSUM_SIZE);
                kal_mem_set(buffer_with_chksum + size+ NVRAM_CHKSUM_SIZE, 0x00, remainLen);
            }
            else
            {
                kal_mem_cpy(buffer_with_chksum, buffer, size);
                kal_mem_cpy(buffer_with_chksum + size, &chksum, NVRAM_CHKSUM_SIZE);
            }

        #if defined(__MTK_SECURE_PLATFORM__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MTK_SECURE_PLATFORM__  && __MTK_TARGET__ */

            Ret = FS_Write(hFile, buffer_with_chksum, (kal_uint32) (size + NVRAM_CHKSUM_SIZE + remainLen), &len);
            if (Ret != FS_NO_ERROR)
            {
                nvram_fat_last_err = Ret;
                nvram_fat_last_line = __LINE__;
                kal_prompt_trace(MOD_NVRAM, "FS_Write(record) status: %d", Ret);

                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
            #ifdef __SHADOW_SUPPORT_SB__
                    if (Ret == FS_FLASH_ERASE_BUSY)
                    {
                        return NVRAM_DRV_ERASE_BUSY;
                    }
            #endif /* __SHADOW_SUPPORT_SB__ */ 
                
                return Ret;
            }
            free_ctrl_buffer(buffer_with_chksum);
        }
        else
        {
            nvram_fat_last_err = Ret;
            nvram_fat_last_line = __LINE__;
            kal_prompt_trace(MOD_NVRAM, "FS_Seek(record) status: %d", Ret);

            FS_Close(hFile);
            #ifdef __SHADOW_SUPPORT_SB__
                    if (Ret == FS_FLASH_ERASE_BUSY)
                    {
                        return NVRAM_DRV_ERASE_BUSY;
                    }
            #endif /* __SHADOW_SUPPORT_SB__ */ 
            
            return Ret;
        }
    }
    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_read_composed
 * DESCRIPTION
 *  read composed record from FAT.
 * PARAMETERS
 *  nvramname           [?]         
 *  section_number      [IN]        
 *  buffer              [?]         
 *  size                [IN]        
 *  whole_size          [IN]        
 *  startAddr           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_read_composed(
                        kal_char *nvramname,
                        /* file name */ kal_uint16 section_number,
                        /* record id */ kal_uint8 *buffer,
                        /* read buffer, size*amount */ kal_uint16 size,
                        /* size of one record */ kal_uint16 whole_size,
                        /* whole size of container file */ kal_uint16 startAddr /* start address in container file */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_uint16 chksum1 = 0, chksum2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (section_number < 1)
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: section_number = %d", section_number);
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        return NVRAM_DRV_INVALID_RECORD_ID;
    }

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const TCHAR*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (hFile == FS_FILE_NOT_FOUND)
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: FS_FILE_NOT_FOUND (%d)", hFile);
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: hFile = %d", hFile);
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: len is 0");
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, (section_number - 1) * (whole_size + sizeof(chksum1)) + startAddr, FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, buffer, (kal_uint32) size, &len);
    }

    if (Ret != FS_NO_ERROR)
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: Ret = %d", Ret);
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        FS_Close(hFile);
        return NVRAM_DRV_CHECKSUM_ERROR;
    }

    nvram_drval_caculate_checksum(&chksum1, buffer, size);
    Ret = FS_Read(hFile, &chksum2, (kal_uint32) sizeof(chksum2), &len);
    if (!((Ret == FS_NO_ERROR) && (chksum1 == chksum2)))
    {
    #ifdef _NVRAM_DEBUG_
        {
            kal_char debugmsg[64];

            sprintf(debugmsg, "nvram_drv_fat_read: Ret = %d, chksum1 = %d, chksum2 = %d", Ret, chksum1, chksum2);
            kal_print(debugmsg);
        }
    #endif /* _NVRAM_DEBUG_ */ 

        FS_Close(hFile);
        return NVRAM_DRV_CHECKSUM_ERROR;
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write_composed
 * DESCRIPTION
 *  write composed record to FAT.
 * PARAMETERS
 *  nvramname           [?]         
 *  section_number      [IN]        
 *  buffer              [?]         
 *  size                [IN]        
 *  whole_size          [IN]        
 *  startAddr           [IN]        
 *  initialize          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_write_composed
    (kal_char *nvramname,
     kal_uint16 section_number,
     kal_uint8 *buffer, kal_uint16 size, kal_uint16 whole_size, kal_uint16 startAddr, kal_bool initialize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;
    kal_uint16 chksum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (section_number < 1)
    {
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: section_number = %d", section_number);
        return NVRAM_DRV_INVALID_RECORD_ID;
    }

    nvram_drval_caculate_checksum(&chksum, buffer, size);

    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    /* open NV_RCD(RCD#) file */
    hFile = FS_Open((const TCHAR*)filename, FS_CREATE | FS_READ_WRITE | FS_OPEN_NO_DIR);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: FS_FILE_NOT_FOUND (%d)", hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: hFile = %d", hFile);
        return NVRAM_DRV_FATAL_ERROR;
    }

    if (initialize == KAL_TRUE)
    {
        /* Reset all sections to default value, section_number is total section number of this rcd */
        kal_uint16 i = 1;

        for (i = 1; i <= section_number; i++)
        {
            /* write data */
            Ret = FS_Seek(hFile, (i - 1) * (whole_size + sizeof(chksum)) + startAddr, FS_FILE_BEGIN);

            if (Ret >= FS_NO_ERROR)
            {
                Ret = FS_Write(hFile, buffer, (kal_uint32) size, &len);
            }

            if (Ret >= FS_NO_ERROR)
            {
                Ret = FS_Write(hFile, (void*)&chksum, sizeof(chksum), &len);
            }

            if (Ret != FS_NO_ERROR)
            {
                kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: Ret = %d", Ret);
                FS_Close(hFile);

                if (Ret == FS_TOO_MANY_FILES || Ret == FS_DISK_FULL)
                {
                    return NVRAM_DRV_NOT_ENOUGH_SPACE;
                }
                else
                {
                    return NVRAM_DRV_CHECKSUM_ERROR;
                }
            }
        }
    }
    else
    {

        /* Update one of the sections if linear-fixed */
        Ret = FS_GetFileSize(hFile, &len);
        if ((Ret == FS_NO_ERROR) && (len == 0))
        {
            kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: len is 0");
            FS_Close(hFile);
            return NVRAM_DRV_EMPTY_RECORD;
        }

        /* seek to the section start in this record */
        Ret = FS_Seek(hFile, (section_number - 1) * (whole_size + sizeof(chksum)) + startAddr, FS_FILE_BEGIN);
        if (Ret >= FS_NO_ERROR)
        {
            Ret = FS_Write(hFile, buffer, (kal_uint32) size, &len);
            if (Ret == FS_NO_ERROR)
            {
                Ret = FS_Write(hFile, (void*)&chksum, sizeof(chksum), &len);
            }
        }

        if (Ret != FS_NO_ERROR)
        {
            kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_write: Ret = %d", Ret);
            FS_Close(hFile);

            if (Ret == FS_TOO_MANY_FILES || Ret == FS_DISK_FULL)
            {
                return NVRAM_DRV_NOT_ENOUGH_SPACE;
            }
            else
            {
                return NVRAM_DRV_CHECKSUM_ERROR;
            }
        }
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_delete
 * DESCRIPTION
 *  delete files from FAT.
 * PARAMETERS
 *  nvramname       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drv_fat_delete(kal_char *nvramname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    TCHAR filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_int32 Ret = NVRAM_DRV_CHECKSUM_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* translate record id to filename */
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);

    Ret = FS_Delete((const TCHAR*)filename);
    kal_prompt_trace(MOD_NVRAM, "nvram_drv_fat_delete: Ret = %d", Ret);
    if (Ret != FS_NO_ERROR)
    {
        /* delete error handler */
        ASSERT(KAL_FALSE);
    }

    FS_Close(hFile);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_set_max_record_number
 * DESCRIPTION
 *  set the max record number.
 * PARAMETERS
 *  RecordNumber        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drv_fat_set_max_record_number(kal_uint8 RecordNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the max record number for the boundary of data files number */
    if (RecordNumber > nvram_drval_max_rcd)
    {
        nvram_drval_max_rcd = RecordNumber;
    }

}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_get_record_size
 * DESCRIPTION
 *  get the record size.
 * PARAMETERS
 *  nvramname       [?]     
 *  Hint            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 nvram_drv_fat_get_record_size(kal_char *nvramname, void *Hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    TCHAR filename[NVRAM_MAX_PATH_LEN];
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);
    if ((hFile = FS_OpenHint(filename, FS_READ_ONLY, (FS_FileLocationHint*) Hint)) > 0)
    {
        if (FS_GetFileSize(hFile, &size) != FS_NO_ERROR)
        {
            size = 0;
        }

        FS_Close(hFile);
        return size;
    }
    else
        return hFile;

}

