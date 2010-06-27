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
 * FileName:
 * ---------
 * msf_file.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating WAP File APIs.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "app_buff_alloc.h"

#include "stdarg.h"
#include "stdio.h"

#include "msf_cfg.h"
#include "bra_cfg.h"
#include "msm_int.h"
#include "msf_env.h"

#include "fat_fs.h"     /* file system */
#include "L4Dr.h"
#include "FileManagerGProt.h"

#include "wapadp.h"

#ifdef __FS_ASCII__

/************
 * CHAR FS
 ************/
#define FILE_SPRINTF sprintf
#define FILE_CHAR_T kal_char
#define FILE_STRCAT strcat
#define FILE_STRCPY strcpy
#define FILE_STRCMP strcmp
#define FILE_UTF8_STRLEN strlen
#define FILE_NAME_ALLOC(size) MSF_MEM_ALLOC(MSF_MODID_MSM, (size))
#define FILE_WCH2CH_LEN(x) x
#define FILE_CH2WCH_LEN(x) x
#define FILE_UTF8_ADP2FS(dest,src,size) strcpy((kal_char*)dest,src)
#define FILE_FS_ADP2UTF8(dest,src,size) strcpy((kal_char*)dest,src)

#else /* __FS_ASCII__ */ 

/************
 * WCHAR FS
 ************/

extern int widget_utf8_length(const kal_uint8 *s);
extern int widget_utf8_to_ucs2_string(kal_uint8 *dest, int dest_size, kal_uint8 *src);
extern int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, kal_uint8 *src);

#define FILE_CHAR_T kal_wchar
#define FILE_SPRINTF kal_wsprintf
#define FILE_STRCAT kal_wstrcat
#define FILE_STRCPY kal_wstrcpy
#define FILE_STRCMP kal_wstrcmp
#define FILE_UTF8_STRLEN(x) widget_utf8_length((const kal_uint8*)(x))
#define FILE_NAME_ALLOC(size) MSF_MEM_ALLOC(MSF_MODID_MSM, (size)*2)
#define FILE_WCH2CH_LEN(x) (x<<1)
#define FILE_CH2WCH_LEN(x) (x>>1)
#define FILE_UTF8_ADP2FS(dest,src,size) widget_utf8_to_ucs2_string((kal_uint8*)dest,size,(kal_uint8*)src)
#define FILE_FS_ADP2UTF8(dest,src,size) widget_ucs2_to_utf8_string((kal_uint8*)dest,size,(kal_uint8*)src)

#endif /* __FS_ASCII__ */ 

#define FILE_NAME_FREE(fn)    if((fn) != NULL) MSF_MEM_FREE(MSF_MODID_MSM, (fn))

/**********************************************************************
 * HDI File Funktions 
 **********************************************************************/

extern void widget_fileNotify(MSF_UINT8 modId, int handle, int eventType);

#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern kal_bool mmi_usb_check_path_exported(char *path);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifndef __MTK_TARGET__
#define FILEDBG_(x)     /* empty */
#else 
#define FILEDBG_(x)     /* empty */
#endif 

#define HDI_MAX_FILE_BLK            (1) /* totally files opened simultaneously */
#define HDI_MAX_FILE_NUM            (15)        /* reference. RTF_MAX_FILES */
#define HDI_INVALID_FILE            (-1)
// #define HDI_FILE_DELAY_TIME         (KAL_TICKS_100_MSEC+KAL_TICKS_100_MSEC+KAL_TICKS_100_MSEC+KAL_TICKS_500_MSEC)/*0.8sec*/
#define HDI_FILE_DELAY_TIME         (KAL_TICKS_100_MSEC+KAL_TICKS_100_MSEC)     /* 2004.06 Flash delay time typically 700ms */

#define HDI_FILE_CNTX(X)            (HDI_file_cntx.X)
#define HDI_FILE_PTR(X)             (&HDI_file_cntx.file_block[X/HDI_MAX_FILE_NUM]->file_pool[X%HDI_MAX_FILE_NUM])
#define HDI_FILE_BLK(X,Y)           (&HDI_file_cntx.file_block[X]->file_pool[Y])
#define FILE_SEEK_TYPE_TO_FS(type)  (type == HDI_FILE_SEEK_SET) ? FS_FILE_BEGIN : ((type == HDI_FILE_SEEK_CUR) ? FS_FILE_CURRENT:FS_FILE_END)

#ifdef __PRODUCTION_RELEASE__
#define HDI_FILE_ASSERT(x)
#else 
#define HDI_FILE_ASSERT(x)           ASSERT(x)  /* temp use for development */
#endif 

#if 0
#if (!defined(APP_STORAGE_IN_SYS_DRV)) && defined(MMS_SUPPORT)
/* under construction !*/
#else
/* under construction !*/
#endif
#endif /* 0 */ 

/*
 * following files either important or only close when terminate, 
 * * thus we need to flush file for every write operation 
 * * 
 * * Reference: MSM_CRITICAL_FILES[]
 */
const char *const hdi_needflush_file_list[] = 
{
    "/msm/registry.dat",
    "/stk/auth/index.dat",
    "/stk/cache/index.dat",
    "/stk/cookie/index.dat",
    "/uis/0.ndx",
    "/sec/storage/S_0",
    ""  /* end */
};

/* flag */
#define HDI_FILE_NEED_FLUSH 0x01

typedef struct
{
#if !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE) || defined(MMS_IN_LARGE_STORAGE)
    kal_char *file_name;
#endif 

    FS_HANDLE fd;       /* file handle */
    kal_uint8 mod_id;   /* module id of opened file */
    kal_uint8 is_read_delay;
    kal_uint8 is_write_delay;
    kal_uint8 flag;
#ifdef MMS_IN_LARGE_STORAGE
    kal_uint32 fs_flag;
#endif 

    eventid event_id;   /* for timer */
} HDI_file_struct;

typedef struct HDI_file_block_struct
{
    HDI_file_struct file_pool[HDI_MAX_FILE_NUM];
} HDI_file_block_struct;

typedef struct
{
    HDI_file_block_struct *file_block[HDI_MAX_FILE_BLK];    /* max. two file blocks */
    HDI_file_block_struct basic_block;

    stack_timer_struct base_timer;
    event_scheduler *evt_scheduler;

} HDI_file_cntx_struct;

HDI_file_cntx_struct HDI_file_cntx = {0};

void HDI_file_init_timer(void);
void HDI_file_deinit_timer(void);

#if !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE)

static int msf_max_open_files = 0;


/*****************************************************************************
 * FUNCTION
 *  HDI_list_number_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_number_opened_files()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < HDI_MAX_FILE_BLK; i++)
        if (HDI_FILE_CNTX(file_block[i]) != NULL)
        {
            for (j = 0; j < HDI_MAX_FILE_NUM; j++)
            {
                if (HDI_FILE_BLK(i, j)->fd != -1)
                {
                    count++;
                }
            }
        }
    if (count > msf_max_open_files)
    {
        msf_max_open_files = count;
    }

#ifndef __MTK_TARGET__
    FILEDBG_(printf("# opened files = %d, max = %d", count, msf_max_open_files);
        )
#else /* __MTK_TARGET__ */ 
    /* kal_prompt_trace(MOD_WAP, "# opened files = %d, max = %d", count, msf_max_open_files); */
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDI_reset_number_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_reset_number_opened_files()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msf_max_open_files = 0;
}

#endif /* !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE) */ 

#ifndef __MTK_TARGET__


/*****************************************************************************
 * FUNCTION
 *  HDI_list_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_opened_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("\nopened files by WAP:\n========================================\n");
        )HDI_list_number_opened_files();

    for (i = 0; i < HDI_MAX_FILE_BLK; i++)
        if (HDI_FILE_CNTX(file_block[i]) != NULL)
        {
            for (j = 0; j < HDI_MAX_FILE_NUM; j++)
            {
                if (HDI_FILE_BLK(i, j)->fd != -1)
                {
                    FILEDBG_(printf("%d\t%d\t%s\n", i, j, HDI_FILE_BLK(i, j)->file_name));
                }
            }
        }
    FILEDBG_(printf("========================================\n");
)}
#else /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDI_list_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_opened_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDI_list_number_opened_files();

    for (i = 0; i < HDI_MAX_FILE_BLK; i++)
        if (HDI_FILE_CNTX(file_block[i]) != NULL)
        {
            for (j = 0; j < HDI_MAX_FILE_NUM; j++)
            {
                if (HDI_FILE_BLK(i, j)->fd != -1)
                {
                    (void)0;    /* kal_prompt_trace(MOD_WAP, "%d\t%d\t%s", i,j,HDI_FILE_BLK(i,j)->file_name); */
                }
            }
        }
}
#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDI_fileNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  handle          [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_fileNotify(MSF_UINT8 modId, int handle, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId == MSF_MODID_WIDGET)
    {
        widget_fileNotify(modId, handle, eventType);
    }
    else
    {
        HDIc_fileNotify(modId, handle, eventType);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDI_fileBlockInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_block      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_fileBlockInit(HDI_file_block_struct *file_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < HDI_MAX_FILE_NUM; i++)
    {
        file_block->file_pool[i].fd = HDI_INVALID_FILE;
        file_block->file_pool[i].is_read_delay = KAL_FALSE;
        file_block->file_pool[i].is_write_delay = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDI_fileInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_fileInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*=======================
    * initialize file block 
    *=======================*/
    HDI_fileBlockInit(&HDI_FILE_CNTX(basic_block));

    HDI_FILE_CNTX(file_block[0]) = &HDI_FILE_CNTX(basic_block);

    for (i = 1; i < HDI_MAX_FILE_BLK; i++)
    {
        HDI_FILE_CNTX(file_block[i]) = NULL;
    }

   /*===================
    * initialize timer 
    *===================*/
    HDI_file_init_timer();

}   /* end of HDI_fileInit */


/*****************************************************************************
 * FUNCTION
 *  HDI_fileDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_fileDeinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1st block uses static memory */
    for (i = 1; i < HDI_MAX_FILE_BLK; i++)
    {
        if (HDI_FILE_CNTX(file_block[i]) != NULL)
        {
            MSF_MEM_FREE(MSF_MODID_MSM, HDI_FILE_CNTX(file_block[i]));
            HDI_FILE_CNTX(file_block[i]) = NULL;
        }
    }

   /*===================
    * deinitialize timer 
    *===================*/
    HDI_file_deinit_timer();
}


/*****************************************************************************
 * FUNCTION
 *  HDI_get_file_entry_from_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  blk         [IN]        
 *  fd          [IN]        
 *  indx        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDI_get_file_entry_from_block(kal_uint8 blk, int fd, kal_uint8 *indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HDI_FILE_CNTX(file_block[blk]) == NULL)
    {
        return KAL_FALSE;
    }

    for (i = 0; i < HDI_MAX_FILE_NUM; i++)
    {
        if (HDI_FILE_BLK(blk, i)->fd == fd)
        {
            if (indx)
            {
                *indx = blk * HDI_MAX_FILE_NUM + i;
            }
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HDI_get_file_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd          [IN]        
 *  indx        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDI_get_file_entry(int fd, kal_uint8 *indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;    /* reset */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (HDI_get_file_entry_from_block(i, fd, indx) == KAL_TRUE)
        {
            return KAL_TRUE;
        }
        else
        {
            i++;
        }

        /* file entries in preallocated file block are not enough */
        if ((fd == HDI_INVALID_FILE) && (i > 0) && (HDI_FILE_CNTX(file_block[i]) == NULL))
        {
            HDI_FILE_CNTX(file_block[i]) = (HDI_file_block_struct*)
                MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(HDI_file_block_struct));
            HDI_fileBlockInit(HDI_FILE_CNTX(file_block[i]));
        }

    } while (i < HDI_MAX_FILE_BLK);

    /* We must guarentee that free slots are always available. */
    /* HDI_FILE_ASSERT(fd != HDI_INVALID_FILE); */

    return KAL_FALSE;

}   /* HDI_get_file_entry */

/*
 * FS mode:
 * FS_READ_WRITE        
 * FS_READ_ONLY         
 * FS_OPEN_SHARED       
 * FS_OPEN_NO_DIR       
 * FS_OPEN_DIR           
 * FS_CREATE             
 * FS_CREATE_ALWAYS     
 * FS_COMMITTED     
 * FS_CACHE_DATA 
 * FS_LAZY_DATA     
 * 
 */


/*****************************************************************************
 * FUNCTION
 *  HDI_FileModeTranslate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 HDI_FileModeTranslate(int mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 m = 0;   /* reset */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mode & HDI_FILE_SET_RDONLY))   /* read only */
    {
        m |= FS_READ_ONLY;
    }

    /* write only, but FS does not have this mode
       set READ/WRITE */
    if ((mode & HDI_FILE_SET_WRONLY) || (mode & HDI_FILE_SET_RDWR))
    {
        m |= FS_READ_WRITE;
    }

    if ((mode & HDI_FILE_SET_BUFFERED)) /* access data in RAM */
    {
        m |= FS_LAZY_DATA;
    }

    /* HDI_FILE_SET_APPEND */

    if ((mode & HDI_FILE_SET_CREATE))
    {
        m |= FS_CREATE;
    }

    /* HDI_FILE_SET_EXCL */

    return m;
}


/*****************************************************************************
 * FUNCTION
 *  HDI_FileErrorNoTranslate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDI_FileErrorNoTranslate(FS_HANDLE err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err >= 0)
    {
        return err;
    }

    FILEDBG_(printf("HDI_FileErrorNoTranslate: error cause from FS=%d\n", err);
        )switch (err)
    {
        case FS_PATH_NOT_FOUND:
        case FS_FILE_NOT_FOUND:
        case FS_INVALID_FILENAME:
            return HDI_FILE_ERROR_PATH; /* Note that applications might check this error code */

        case FS_ACCESS_DENIED:
        case FS_DEVICE_EXPORTED_ERROR:
            return HDI_FILE_ERROR_ACCESS;

        case FS_MEDIA_CHANGED:
            return HDI_FILE_ERROR_ACCESS;

        case FS_TOO_MANY_FILES:
            HDI_FILE_ASSERT(0); /* this is not allowed */
            return HDI_FILE_ERROR_ACCESS;

        case FS_DISK_FULL:
        case FS_APP_QUOTA_FULL:
            return HDI_FILE_ERROR_FULL; /* Note that applications might check this error code */

        case FS_FILE_EXISTS:
            return HDI_FILE_ERROR_EXIST;    /* Note that applications might check this error code */

            /* File System is busy now, return immediately with cause "DELAY" */
        case FS_FLASH_ERASE_BUSY:
        case FS_LOCK_MUTEX_FAIL:
            return HDI_FILE_ERROR_DELAYED;

        default:
            return HDI_FILE_ERROR_INVALID;

    }

}   /* end of HDI_FileErrorNoTranslate */


/*****************************************************************************
 * FUNCTION
 *  HDI_FileGetDiskLabel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDI_FileGetDiskLabel(wap_storage_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int system_disk = -1;
    static int MMS_disk = -1;
    static int public_disk = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case WAP_STORAGE_SYSTEM:
            if (system_disk < 0)
            {
                system_disk = WAP_SYSTEM_DRV;
            }
            ASSERT(system_disk > 0);
            return system_disk;

        case WAP_STORAGE_MMS:
            if (MMS_disk < 0)
            {
            #ifdef MMS_IN_LARGE_STORAGE
                /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
                MMS_disk = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            #else /* MMS_IN_LARGE_STORAGE */ 
                MMS_disk = WAP_SYSTEM_DRV;
            #endif /* MMS_IN_LARGE_STORAGE */ 
            }
            ASSERT(MMS_disk > 0);
            return MMS_disk;

        case WAP_STORAGE_PUBLIC:
            /* Order: 1. Visible NAND 2. Invisible NOR (system drive) */
            if (public_disk < 0)
            {
                public_disk = MMI_PUBLIC_DRV;
            }
            ASSERT(public_disk > 0);
            return public_disk;

        default:
            ASSERT(0);
            return 0;   /* Unreached */
    }
}   /* end of HDI_FileGetDiskLabel */

/*=====================================
 * HDIa File Timer Stuff
 *=====================================*/


/*****************************************************************************
 * FUNCTION
 *  HDI_file_start_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_p        [?]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_start_base_timer(void *base_timer_p, unsigned int time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_p, MSF_FILE_TIMER_ID, time_out);
}


/*****************************************************************************
 * FUNCTION
 *  HDI_file_stop_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_p        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_stop_base_timer(void *base_timer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_p);
}


/*****************************************************************************
 * FUNCTION
 *  HDI_file_deinit_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_deinit_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete the Timer Context */
    evshed_delete_all_events(HDI_FILE_CNTX(evt_scheduler));
    
    stack_stop_timer(&(HDI_FILE_CNTX(base_timer)));

}


/*****************************************************************************
 * FUNCTION
 *  HDI_file_init_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_init_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create Base timer */

    if(HDI_FILE_CNTX(evt_scheduler) == NULL)
    {
        stack_init_timer(&(HDI_FILE_CNTX(base_timer)), "HDI_FILE_BASE_TIMER", MOD_WAP);

        /* Create an Event Scheduler */
        HDI_FILE_CNTX(evt_scheduler) =
            (event_scheduler*)
            new_evshed(
                &(HDI_FILE_CNTX(base_timer)),
                HDI_file_start_base_timer,
                HDI_file_stop_base_timer,
                0,
                (malloc_fp_t) kal_evshed_get_mem,
                kal_evshed_free_mem,
                0);
    }

}   /* end of HDI_file_init_timer */


/*****************************************************************************
 * FUNCTION
 *  HDI_file_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_notify(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDI_file_struct *file_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_ptr != NULL);

    file_ptr = (HDI_file_struct*) msg_ptr;

    file_ptr->event_id = NULL;

    if (file_ptr->fd != HDI_INVALID_FILE)
    {
        if (file_ptr->is_read_delay)
        {
            file_ptr->is_read_delay = KAL_FALSE;
            HDI_fileNotify(file_ptr->mod_id, file_ptr->fd, HDI_FILE_READ_READY);
        }

        if (file_ptr->is_write_delay)
        {
            file_ptr->is_write_delay = KAL_FALSE;
            HDI_fileNotify(file_ptr->mod_id, file_ptr->fd, HDI_FILE_WRITE_READY);
        }
    }

}   /* end of HDI_file_notify */


/*****************************************************************************
 * FUNCTION
 *  HDI_file_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_start_timer(HDI_file_struct *file_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_ptr->event_id = evshed_set_event(
                            HDI_FILE_CNTX(evt_scheduler),
                            (kal_timer_func_ptr) HDI_file_notify,
                            (void*)file_ptr,
                            HDI_FILE_DELAY_TIME);

}   /* end of HDI_file_start_timer */


/*****************************************************************************
 * FUNCTION
 *  HDI_file_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_stop_timer(HDI_file_struct *file_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evshed_cancel_event(HDI_FILE_CNTX(evt_scheduler), &file_ptr->event_id);

}   /* end of HDI_file_stop_timer */


/*****************************************************************************
 * FUNCTION
 *  HDI_file_timer_expiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_file_timer_expiry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_is_time_out_valid(&(HDI_FILE_CNTX(base_timer))))
    {
        evshed_timer_handler(HDI_FILE_CNTX(evt_scheduler));
    }

    stack_process_time_out(&(HDI_FILE_CNTX(base_timer)));

}   /* end of HDI_file_timer_expiry */

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  is_mms_storage_exported_to_pc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool is_mms_storage_exported_to_pc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar mms_folder_path[10] = {0};
    int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_MMS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(mms_folder_path, "%c", drv_letter);
    kal_wstrcat(mms_folder_path, L"\\");

    if (mmi_usb_check_path_exported((char*)mms_folder_path) == MMI_FALSE)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}
#endif /* __USB_IN_NORMAL_MODE__ */ 
/* 
 * / ==> \ 
 */


/*****************************************************************************
 * FUNCTION
 *  HDI_FileNameTranslate
 * DESCRIPTION
 *  This function translates file name from Obigo format to File System
 *  format. Specifically, the translations are listed below:
 *  a. utf8 --> ucs2
 *  b. / --> \
 *  c. remove "/external/"
 * PARAMETERS
 *  filename        [IN]        
 *  a(?)            [IN]        Src, pointer of file name
 * RETURNS
 *  a pointer of translated file name, integration shall free this pointer.
 *****************************************************************************/
kal_uint8 *HDI_FileNameTranslate(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int len, size;
    int use_external = 0;
    kal_uint8 *dest;
    kal_uint8 wap_fs_root_folder[32];
    kal_uint8 wap_fs_root_folder_len;
    char *src = NULL;
    char *src_tmp = NULL;
    kal_int32 srcLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(filename);

    src = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, srcLen + 5);
    if (!src)
    {
        ASSERT(0);
    }
    memset(src, 0x00, srcLen + 5);
    src_tmp = src;

    {
        char *mms_str = NULL;
        char cpfilename = 1;

        mms_str = (char*)strstr(filename, "/mms/");
        if (!mms_str)
        {
            mms_str = (char*)strstr(filename, "\\mms\\");
            if (!mms_str)
            {
                goto cpyfilename;
            }
        }
        if ((mms_str && (strstr(mms_str, "mms.cn") || strstr(mms_str, "mms.tp") || strstr(mms_str, "mms.bk"))))
        {
            strncpy(src, filename, mms_str - filename + 4);
            strcat(src, "_sys");
            strcat(src, mms_str + 4);
            cpfilename = 0;
        }
    #ifdef MMS_IN_LARGE_STORAGE
        else
        {
            /* Change "wache\mms" to "\mms" */
            if (strstr(filename, "wcache") != NULL)
            {
                strncpy(src, mms_str, srcLen);
                cpfilename = 0;
            }
        }
    #endif /* MMS_IN_LARGE_STORAGE */ 
        if (cpfilename == 1)
        {
          cpyfilename:
            memcpy(src, filename, srcLen);
        }
    }

    sprintf((char*)wap_fs_root_folder, "%c:%s", WAP_SYSTEM_DRV, WAP_FS_ROOT_FOLDER);
    wap_fs_root_folder_len = strlen((const char*)wap_fs_root_folder);

    /* ASSERT(src && (src[0] == '/' || src[0] == '\\')); */
    ASSERT(src);

    /* check whether "/external/" exists */
    if (strncmp(src, HDI_EXTERNAL_PATH, HDI_EXTERNAL_LEN) == 0)
    {
        src += HDI_EXTERNAL_LEN;    /* skip "/external/" */
        use_external = 1;
    }
    else if (strncmp(src, "/mms/", 5) == 0 || strncmp(src, "\\mms\\", 5) == 0)
    {
        src += 5;
        use_external = 2;
    }
    else if (strncmp(src, "/public/", 8) == 0 || strncmp(src, "\\public\\", 8) == 0)
    {
        src += 8;
        use_external = 3;
    }
    else if (strncmp(src, WIDGET_RAWFILE_DIRECTORY, WIDGET_RAWFILE_DIRECTORY_LEN) == 0)
    {
        src += WIDGET_RAWFILE_DIRECTORY_LEN;
        use_external = 4;
    }
    else if (strncmp(src, WIDGET_RAWFILE_MMS_DIRECTORY, WIDGET_RAWFILE_MMS_DIRECTORY_LEN) == 0)
    {
        src += WIDGET_RAWFILE_MMS_DIRECTORY_LEN;
        use_external = 4;
    }
#ifdef BRA_CFG_OFFLINE_PAGES
    else if (strncmp(src, "/brs/", 5) == 0 || strncmp(src, "\\brs\\", 5) == 0)
    {
        src += 5;
        use_external = 5;
    }
#endif /* BRA_CFG_OFFLINE_PAGES */ 
    else if (strncmp(src, WAP_DOWNLOAD_FOLDER, WAP_DOWNLOAD_FOLDER_LEN) == 0)
    {
        src += WAP_DOWNLOAD_FOLDER_LEN;
        use_external = 6;
    }

    if (use_external == 1)
    {
        len = FILE_UTF8_STRLEN(src);
    }
    else if (use_external == 2)
#ifdef MMS_IN_LARGE_STORAGE
        len = FILE_UTF8_STRLEN(src) + 7;    /* e.g. "D:\MMS\" */
#else 
        len = FILE_UTF8_STRLEN(src) + 8;    /* e.g. "C:\@MMS\" */
#endif 
    else if (use_external == 3)
    {
        len = FILE_UTF8_STRLEN(src) + 3;    /* e.g. "D:\" */
    }
    else if (use_external == 4)
    {
        len = FILE_UTF8_STRLEN(src) + 11;   /* e.g. "C:\@wcache\" */
    }
#ifdef BRA_CFG_OFFLINE_PAGES
    else if (use_external == 5)
    {
        len = FILE_UTF8_STRLEN(src) + 7;    /* e.g. "D:\BRS\" */
    }
#endif /* BRA_CFG_OFFLINE_PAGES */ 
    else if (use_external == 6)
    {
        len = FILE_UTF8_STRLEN(src) + 12;    /* e.g. "D:\download\" */
    }
    else
    {
        len = FILE_UTF8_STRLEN(src) + wap_fs_root_folder_len;
    }

    size = FILE_WCH2CH_LEN((len + 3));  /* for '/' '*' '\0' */

    dest = MSF_MEM_ALLOC(MSF_MODID_MSM, (kal_uint16) size);

    /* adapt UTF8 format to format supported by FS */
    if (use_external == 1)
    {
        FILE_UTF8_ADP2FS(dest, src, size);
    }
    else if (use_external == 2)
    {
        int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_MMS);
        char mmsfolder[10];

    #ifdef MMS_IN_LARGE_STORAGE
        sprintf(mmsfolder, "%c:\\mms\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, mmsfolder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(7), src, size - FILE_WCH2CH_LEN(7));
    #else /* MMS_IN_LARGE_STORAGE */ 
        sprintf(mmsfolder, "%c:\\@mms\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, mmsfolder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(8), src, size - FILE_WCH2CH_LEN(8));
    #endif /* MMS_IN_LARGE_STORAGE */ 
    }
    else if (use_external == 3)
    {
        int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_PUBLIC);
        char public_folder[5];

        sprintf(public_folder, "%c:\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, public_folder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(3), src, size - FILE_WCH2CH_LEN(3));
    }
    else if (use_external == 4)
    {
        int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_SYSTEM);
        char cache_folder[32];

        sprintf(cache_folder, "%c:\\@wcache\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, cache_folder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(11), src, size - FILE_WCH2CH_LEN(11));
    }
#ifdef BRA_CFG_OFFLINE_PAGES
    else if (use_external == 5)
    {
        int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_PUBLIC);
        char offline_folder[10];

        sprintf(offline_folder, "%c:\\brs\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, offline_folder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(7), src, size - FILE_WCH2CH_LEN(7));
    }
#endif /* BRA_CFG_OFFLINE_PAGES */ 
    else if (use_external == 6)
    {
        int drv_letter = HDI_FileGetDiskLabel(WAP_STORAGE_PUBLIC);
        char download_folder[15];

        sprintf(download_folder, "%c:\\download\\", drv_letter);

        FILE_UTF8_ADP2FS(dest, download_folder, size);
        FILE_UTF8_ADP2FS(dest + FILE_WCH2CH_LEN(12), src, size - FILE_WCH2CH_LEN(12));
    }
    else
    {
        FILE_UTF8_ADP2FS(dest, wap_fs_root_folder, size);
        ASSERT(((FILE_CHAR_T*) dest)[wap_fs_root_folder_len] == (FILE_CHAR_T) 0);
        FILE_UTF8_ADP2FS(
            dest + FILE_WCH2CH_LEN(wap_fs_root_folder_len),
            ((*src == '/') ? src + 1 : src),
            size - FILE_WCH2CH_LEN(wap_fs_root_folder_len));
    }

    for (i = 0; i < len; i++)
    {
        if (((FILE_CHAR_T*) dest)[i] == (FILE_CHAR_T) '/')
        {
            ((FILE_CHAR_T*) dest)[i] = (FILE_CHAR_T) '\\';
        }
    }

    /*
     * 040118 Justin 
     * * remove ending slash due to filesystem bug (fixed)
     * * FIXME. However, we alwys need to add backslash after drive name (e.g. "C:\")
     */
    for (i = len - 1; i > 0; i--)
    {
        if (((FILE_CHAR_T*) dest)[i] == (FILE_CHAR_T) '\\')
        {
            ((FILE_CHAR_T*) dest)[i] = (FILE_CHAR_T) 0;
        }
        else
        {
            break;
        }
    }
    if (src_tmp)
    {
        MSF_MEM_FREE(MSF_MODID_MSM, src_tmp);
    }
    return dest;
}   /* end of HDI_FileNameTranslate */


/*****************************************************************************
 * FUNCTION
 *  HDI_FileNameFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fname       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_FileNameFree(kal_uint8 *fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILE_NAME_FREE(fname);
}


/*****************************************************************************
 * FUNCTION
 *  HDI_needFlush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDI_needFlush(const char *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (strlen(hdi_needflush_file_list[i]) == 0)
        {
            break;
        }
        if (strcmp(fileName, hdi_needflush_file_list[i]) == 0)
        {
            return KAL_TRUE;
        }
        i++;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HDI_supportNonBlockingMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDI_supportNonBlockingMode(const char *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (FS_GetDevType((FILE_CHAR_T*) fileName) == FS_DEVICE_TYPE_NOR ? KAL_TRUE : KAL_FALSE);
}

extern MSF_BOOL MMS_FILE_OPEN_BLOCK_FLAG;   /* Scottie: It is specified to MMS service. */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileOpen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  fileName        [IN]        
 *  mode            [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileOpen(MSF_UINT8 modId, const char *fileName, int mode, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;
    FS_HANDLE fd;
    FS_DiskInfo diskinfo;    
    kal_uint8 *fname;
    kal_uint32 flag = HDI_FileModeTranslate(mode) | FS_OPEN_SHARED;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fileName == NULL || FILE_UTF8_STRLEN(fileName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    /* convert slash '/' to backslash '\' */
    fname = HDI_FileNameTranslate(fileName);

    /* Check disk space if size is assigned */
    if((mode & HDI_FILE_SET_CREATE) && size > 0)
    {
        ret = FS_GetDiskInfo((WCHAR *)fname, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if(ret >= 0 && diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector < size)
        {
            HDI_FileNameFree(fname);
            return HDI_FILE_ERROR_FULL;
        }
    }

    /* Scottie: Support MMS to open file using block mode */
#ifdef MMS_SUPPORT
    if (MMS_FILE_OPEN_BLOCK_FLAG && (modId == MSF_MODID_MMS || modId == MSF_MODID_MEA || modId == MSF_MODID_MMC))
    {
        mode |= HDI_FILE_SET_CUSTOM_BLOCKING;
    }
    /* delete preserved mms index space to ensure that mms index is wriiten successfully. */
    if (modId == MSF_MODID_MMS && (mode & HDI_FILE_SET_CREATE) && strstr(fileName, "mms.tp"))
    {
        HDIa_fileRemove("\\mms_sys\\index.tmp");
    }
#endif /* MMS_SUPPORT */ 

    /* Justin. NAND flash does not support non-blocking mode */
    if (!(mode & HDI_FILE_SET_CUSTOM_BLOCKING) && HDI_supportNonBlockingMode((const char*)fname))
    {
        flag |= FS_NONBLOCK_MODE;
    }

    /* this both SET_CREATE and SET_EXCL are set
       and the file already exist, return ERROR_EXIST */
    if ((mode & HDI_FILE_SET_CREATE) && (mode & HDI_FILE_SET_EXCL))
    {
        int h;
        FS_DOSDirEntry info;
        kal_uint8 *dummy = FILE_NAME_ALLOC(MAX_HDI_FILE_NAME_SIZE);

        h = FS_FindFirst((FILE_CHAR_T*) fname, 0, 0, &info, (FILE_CHAR_T*) dummy, MAX_HDI_FILE_NAME_SIZE * 2);

        FILE_NAME_FREE(dummy);

        if (h > 0)
        {
            FS_FindClose(h);
            FILE_NAME_FREE(fname);
            return HDI_FILE_ERROR_EXIST;
        }
    }

    /* get a free file slot, Note that FS_FindFirst open one more file */
    if (HDI_get_file_entry(HDI_INVALID_FILE, &entry) != KAL_TRUE)
    {
        FILE_NAME_FREE(fname);
        return HDI_FILE_ERROR_ACCESS;
    }

    fd = FS_Open((FILE_CHAR_T*) fname, flag);
    FILE_NAME_FREE(fname);

    if (fd < 0)
    {
        fd = HDI_FileErrorNoTranslate(fd);
    }
    else
    {
        /* open successfully */

        /* because FS doesn't support APPEND mode, thus we shall seek the 
           file pointer to the end of file */
        if ((mode & HDI_FILE_SET_APPEND))
        {
            ret = FS_Seek(fd, 0, FS_FILE_END);

            if (ret < 0)
            {
                FS_Close(fd);
                return HDI_FileErrorNoTranslate(ret);
            }
        }

        if ((mode & HDI_FILE_SET_CREATE) && size > 0)
        {
            ret = FS_Seek(fd, size, FS_FILE_BEGIN);
            FS_Seek(fd, 0, FS_FILE_BEGIN);
        }

    #if !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE) || defined(MMS_IN_LARGE_STORAGE)
        HDI_FILE_PTR(entry)->file_name = (kal_char*) MSF_MEM_ALLOC(MSF_MODID_MSM, strlen(fileName) + 1);
        strcpy(HDI_FILE_PTR(entry)->file_name, fileName);
    #endif /* !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE) || defined(MMS_IN_LARGE_STORAGE) */ 

        HDI_FILE_PTR(entry)->fd = fd;
        HDI_FILE_PTR(entry)->mod_id = modId;
        HDI_FILE_PTR(entry)->is_read_delay = KAL_FALSE;
        HDI_FILE_PTR(entry)->is_write_delay = KAL_FALSE;
        HDI_FILE_PTR(entry)->flag = 0;
    #ifdef MMS_IN_LARGE_STORAGE
        HDI_FILE_PTR(entry)->fs_flag = flag;
    #endif 
        if (HDI_needFlush(fileName) == KAL_TRUE)
        {
            HDI_FILE_PTR(entry)->flag |= HDI_FILE_NEED_FLUSH;
        }
    }

    FILEDBG_(printf("file open: name=%s fd=%d\n", fileName, fd); HDI_list_opened_files();
        )
#ifdef FILE_DEBUG_VERBOSE
        HDI_list_number_opened_files();
    /* kal_prompt_trace(MOD_WAP, "file open %s", fileName); */
#endif /* FILE_DEBUG_VERBOSE */ 

    return fd;
}   /* end of HDIa_fileOpen */

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGenVirtualFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  vfs_name        [?]         
 *  name_len        [IN]        
 *  offset          [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileGenVirtualFileName(int fileHandle, char *vfs_name, int name_len, int offset, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fs_result;
    kal_uint8 *fname;
    kal_uint8 *pstr;
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(vfs_name, 0, name_len);
    fname = FILE_NAME_ALLOC(FS_GenVFN_SIZE);
    memset(fname, 0, FS_GenVFN_SIZE);
    fs_result = FS_GenVirtualFileName(
                    fileHandle,
                    (U16*) fname,
                    (unsigned int)FS_GenVFN_SIZE,
                    (unsigned int)offset,
                    (unsigned int)len);

    if (fs_result != 0)
    {
        FILE_NAME_FREE(fname);
        return HDI_FILE_ERROR_ACCESS;
    }
    else
    {
        /* convert the virtual file name */
        strcpy(vfs_name, HDI_EXTERNAL_PATH);
        pstr = (U8*) vfs_name + strlen(vfs_name);
        str_len = widget_ucs2_to_utf8_string(pstr, name_len - HDI_EXTERNAL_LEN, fname);
        FILE_NAME_FREE(fname);
        HDI_FILE_ASSERT(str_len < (name_len - HDI_EXTERNAL_LEN));
        /* Append the default file type */
        strcat(vfs_name, ".vir");

        return HDI_FILE_OK;
    }
}
#endif /* WIDGET_VIRTUAL_FILE_SUPPORT */ /* #ifdef WIDGET_VIRTUAL_FILE_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileClose(int fileHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HDI_get_file_entry(fileHandle, &entry) == KAL_FALSE)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    /* mark the file slot as free */
    HDI_FILE_PTR(entry)->fd = HDI_INVALID_FILE;

    /* if already started a timer for notify, stop it now */
    if ((HDI_FILE_PTR(entry)->is_read_delay == KAL_TRUE) || (HDI_FILE_PTR(entry)->is_write_delay == KAL_TRUE))
    {
        HDI_file_stop_timer(HDI_FILE_PTR(entry));
    }

#ifdef FILE_DEBUG_VERBOSE
    HDI_list_number_opened_files();
    /* kal_prompt_trace(MOD_WAP, "file close %s", HDI_FILE_PTR(entry)->file_name);   */
#endif /* FILE_DEBUG_VERBOSE */ 

#if !defined(__MTK_TARGET__) || defined(FILE_DEBUG_VERBOSE) || defined(MMS_IN_LARGE_STORAGE)
    MSF_MEM_FREE(MSF_MODID_MSM, HDI_FILE_PTR(entry)->file_name);
#endif 

    FILEDBG_(HDI_list_opened_files();
        )return HDI_FileErrorNoTranslate(FS_Close(fileHandle));

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileWrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_fileWrite(int fileHandle, void *data, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;
    long ret;

    long actual_write = 0;  /* with initial size */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    if (HDI_get_file_entry(fileHandle, &entry) == KAL_FALSE)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    if (size > 0)
    {
        ret = FS_Write(fileHandle, data, size, (kal_uint32*) (&actual_write) /* johnnie */ );

        if (ret < 0 && actual_write == 0)
        {
            return HDI_FileErrorNoTranslate(ret);
        }
        else if ((HDI_FILE_PTR(entry)->flag & HDI_FILE_NEED_FLUSH) != 0)
        {
            FS_Commit(fileHandle);
        }
        //#if defined(MTK_KAL_MNT)
        //      else
        //      {        
        //         FS_Commit(fileHandle);
        //     }
        //#endif
    }
#ifdef MMS_IN_LARGE_STORAGE
    if (actual_write != size)
    {

        if (!(HDI_FILE_PTR(entry)->fs_flag & FS_NONBLOCK_MODE))
        {
            long actual_write_tmp = 0;
            int repeat_write_times = 0;
            void *data_ptr = data;
            long size_tmp = (size - actual_write);

            data_ptr = (unsigned char*)data_ptr + actual_write;
            while (1)
            {
                wap_task_sleep(1);
                actual_write_tmp = 0;
                ret = FS_Write(fileHandle, data_ptr, size_tmp, (kal_uint32*) (&actual_write_tmp) /* johnnie */ );
                actual_write += actual_write_tmp;
                size_tmp -= actual_write_tmp;
                data_ptr = (unsigned char*)data_ptr + actual_write_tmp;
                repeat_write_times++;
                if ((ret < 0 && ret != FS_FLASH_ERASE_BUSY && ret != FS_LOCK_MUTEX_FAIL && ret != -123) ||
                    (actual_write >= size) || (repeat_write_times >= 20))
                {
                    FILEDBG_(printf
                             ("file write error in blocked mode, after WAP fix, wrBytes:%d,actualByte:%d, result:%d\n",
                              size, actual_write, ret);
                        )if ((HDI_FILE_PTR(entry)->flag & HDI_FILE_NEED_FLUSH) != 0)
                    {
                        FS_Commit(fileHandle);
                    }
                    return actual_write;
                }
            }

        }

    }

#endif /* MMS_IN_LARGE_STORAGE */ 

    FILEDBG_(printf("file write: fd=%d size=%d, actual write=%d\n", fileHandle, size, actual_write);
             {
             int i; for (i = 0; i < actual_write; i++)
             {
             printf("%x ", ((kal_uint8*) data)[i]); if (((i + 1) % 16) == 0) printf("\n");}
             }
    )

        return actual_write;
}   /* end of HDIa_fileWrite */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRead
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_fileRead(int fileHandle, void *data, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;
    kal_int32 ret;
    kal_uint32 read_bytes = 0;  /* with initial size */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    if (HDI_get_file_entry(fileHandle, &entry) == KAL_FALSE)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    /* 12/15/2003 Kevin: Obigo's porting guide requires this explicitly */
    if (size == 0)
    {
        return 0;
    }

    ret = FS_Read(fileHandle, data, size, &read_bytes);

    if (ret < 0 && read_bytes == 0)
    {
        return HDI_FileErrorNoTranslate(ret);
    }

    if (read_bytes == 0)    /* end-of-file */
    {
        FILEDBG_(printf("file read EOF: fd=%d\n", fileHandle);
            )return HDI_FILE_ERROR_EOF;
    }
#ifdef MMS_IN_LARGE_STORAGE
    if (read_bytes != size)
    {
        if (!(HDI_FILE_PTR(entry)->fs_flag & FS_NONBLOCK_MODE))
        {
            long actual_read_tmp = 0;
            int repeat_read_times = 0;
            void *data_ptr = data;
            long size_tmp = (size - read_bytes);

            data_ptr = (unsigned char*)data_ptr + read_bytes;

            while (1)
            {
                wap_task_sleep(1);
                actual_read_tmp = 0;
                ret = FS_Read(fileHandle, data_ptr, size_tmp, (kal_uint32*) (&actual_read_tmp) /* johnnie */ );
                read_bytes += actual_read_tmp;
                size_tmp -= actual_read_tmp;
                data_ptr = (unsigned char*)data_ptr + actual_read_tmp;
                repeat_read_times++;
                if ((ret == 0 && actual_read_tmp == 0) ||
                    (ret < 0 && ret != FS_FLASH_ERASE_BUSY && ret != FS_LOCK_MUTEX_FAIL && ret != -123) ||
                    (read_bytes >= size) || (repeat_read_times >= 20))
                {
                    return read_bytes;
                }
            }
        }
    }
#endif /* MMS_IN_LARGE_STORAGE */ 

    FILEDBG_(printf("file read: fd=%d size=%d actual size=%d\n", fileHandle, size, read_bytes);
             {
             int i; for (i = 0; i < read_bytes; i++) printf("%d", ((kal_uint8*) data)[i]); printf("\n");}
    )

        return read_bytes;
}   /* end of HDIa_fileRead */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSeek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  offset          [IN]        
 *  seekMode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_fileSeek(int fileHandle, long offset, int seekMode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long cur_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HDI_get_file_entry(fileHandle, NULL) == KAL_FALSE)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    FILEDBG_(
                {
                if (seekMode == HDI_FILE_SEEK_SET)
                {
                printf("file seek from begin: fd=%d, offset=%d\n", fileHandle, offset);
                }
                else
                if (seekMode == HDI_FILE_SEEK_CUR)
                {
                printf("file seek from current: fd=%d, offset=%d\n", fileHandle, offset);
                }
                else
                printf("file seek from end: fd=%d, offset=%d\n", fileHandle, offset);}
    )

        cur_pos = FS_Seek(fileHandle, offset, FILE_SEEK_TYPE_TO_FS(seekMode));

    /* not error actually, file is too long */
    if ((cur_pos < 0) && (cur_pos == FS_LONG_FILE_POS))
    {
        FS_FileInfo info;

        if (FS_GetFileInfo(fileHandle, &info) < 0)
        {
            return -1;
        }
        cur_pos = info.FilePos;
    }

    FILEDBG_(printf("file seek: cur pos=%d\n", cur_pos);
        )return cur_pos;
}   /* end of HDIa_fileSeek */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRemove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileRemove(const char *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fileName == NULL || FILE_UTF8_STRLEN(fileName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    /* convert slash '/' to backslash '\' */
    fname = HDI_FileNameTranslate(fileName);

    ret = HDI_FileErrorNoTranslate(FS_Delete((FILE_CHAR_T*) fname));

    FILE_NAME_FREE(fname);

#ifdef MMS_SUPPORT
    /* Preallocate a mms index space */
    if (strstr(fileName, "mms.bk"))
    {
        int filehandle = -1;

        filehandle = HDIa_fileOpen(
                        MSF_MODID_MMS,
                        "\\mms_sys\\index.tmp",
                        HDI_FILE_SET_WRONLY | HDI_FILE_SET_CREATE | HDI_FILE_SET_CUSTOM_BLOCKING,
                        5120);
        if (filehandle >= 0)
        {
            HDIa_fileClose(filehandle);
        }
    }
#endif /* MMS_SUPPORT */ 

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileMkDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileMkDir(const char *dirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILEDBG_(printf("make dir: %s\n", dirName);
        )
        /* convert slash '/' to backslash '\' */
        fname = HDI_FileNameTranslate(dirName);

    ret = HDI_FileErrorNoTranslate(FS_CreateDir((FILE_CHAR_T*) fname));
#ifdef MMS_IN_LARGE_STORAGE
    if (ret == FS_NO_ERROR && ((strncmp(dirName, "/mms/", 5) == 0 || strncmp(dirName, "\\mms\\", 5) == 0)))
    {
        FS_SetAttributes((unsigned short*)fname, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
#endif /* MMS_IN_LARGE_STORAGE */ 
#ifdef BRA_CFG_OFFLINE_PAGES
    if (ret == FS_NO_ERROR && ((strncmp(dirName, "/brs/", 5) == 0 || strncmp(dirName, "\\brs\\", 5) == 0)))
    {
        FS_SetAttributes((unsigned short*)fname, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
#endif /* BRA_CFG_OFFLINE_PAGES */ 
    if (ret == FS_NO_ERROR && (strncmp(dirName, WAP_DOWNLOAD_FOLDER, WAP_DOWNLOAD_FOLDER_LEN) == 0))
    {
        FS_SetAttributes((unsigned short*)fname, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
    FILE_NAME_FREE(fname);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRmDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileRmDir(const char *dirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILEDBG_(printf("remove dir: %s\n", dirName);
        )
        /* convert slash '/' to backslash '\' */
        fname = HDI_FileNameTranslate(dirName);

    ret = HDI_FileErrorNoTranslate(FS_RemoveDir((FILE_CHAR_T*) fname));

    FILE_NAME_FREE(fname);

    return ret;
}

/* Extension.h */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileCheckDirExist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileCheckDirExist(const char *dirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return 0;
    }

    /* convert slash '/' to backslash '\' */
    fname = HDI_FileNameTranslate(dirName);

    fd = FS_Open((FILE_CHAR_T*) fname, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);

    FILE_NAME_FREE(fname);

    if (fd < 0)
    {
        return 0;
    }
    else
    {
        FS_Close(fd);
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetSizeDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileGetSizeDir(const char *dirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret;
    int h;                  /* save temp. file handle for find */
    FS_DOSDirEntry info;
    kal_uint8 *fsearch;
    kal_uint8 *fname;
    kal_uint8 no_entry = 0; /* with initial value */
    FILE_CHAR_T star[6];    /* "\*" */
    FILE_CHAR_T p_dir[6];   /* ".." */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILEDBG_(printf("get size dir: %s\n", dirName);
        )
        /* convert slash '/' to backslash '\' */
        fsearch = HDI_FileNameTranslate(dirName);

    FILE_SPRINTF(star, "\\*");
    fname = FILE_NAME_ALLOC(MAX_HDI_FILE_NAME_SIZE);

    FILE_STRCAT((FILE_CHAR_T*) fsearch, star);

    h = FS_FindFirst((FILE_CHAR_T*) fsearch, 0, 0, &info, (FILE_CHAR_T*) fname, MAX_HDI_FILE_NAME_SIZE * 2);
    FILE_NAME_FREE(fsearch);

    if (h < 0)
    {
        FILE_NAME_FREE(fname);
        return HDI_FILE_ERROR_PATH;
    }

    FILE_SPRINTF(p_dir, "..");

    do
    {
        if (FILE_STRCMP((FILE_CHAR_T*) fname, (FILE_CHAR_T*) ".") != 0 &&
            FILE_STRCMP((FILE_CHAR_T*) fname, (FILE_CHAR_T*) p_dir) != 0)
        {
            no_entry++;
        }

    } while ((ret = FS_FindNext(h, &info, (FILE_CHAR_T*) fname, MAX_HDI_FILE_NAME_SIZE * 2)) == FS_NO_ERROR);

    FILE_NAME_FREE(fname);

    if (FS_FindClose(h) < 0)
    {
        return -1;
    }

    return no_entry;

}   /* end of HDIa_fileGetSizeDir */


/*****************************************************************************
 * FUNCTION
 *  HDI_fileReadDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 *  size1               [?]         
 *  dirHandle           [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDI_fileReadDir(
        const char *dirName,
        int pos,
        char *nameBuf,
        int nameBufLength,
        int *type,
        int *size,
        long *size1,
        int *dirHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h = -1;             /* save temp. file handle for find */
    FS_DOSDirEntry info;
    kal_uint8 *fsearch;
    FILE_CHAR_T star[6];    /* "\*" */
    FILE_CHAR_T p_dir[6];   /* ".." */
    FILE_CHAR_T *filename;

    /* with initial value */
    kal_uint32 ret = FS_NO_ERROR;
    int index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILEDBG_(printf("read dir: %s pos:%d\n", dirName, pos);
        )
#ifdef __FS_ASCII__
        filename = nameBuf;
#else /* __FS_ASCII__ */ 
        /* if wide-char file system is adopted, wstrxxx will check the alignment, 
           ie, address shall be 2-byte alignment, however, we cannot ensure that 
           the 'nameBuf' is 2-byte alignment, thus an extra buffer is needed,
           before returnning this function, 
           this function will copy the 'filename' to 'nameBuf' */
        filename = FILE_NAME_ALLOC(nameBufLength);
#endif /* __FS_ASCII__ */ 

    /* convert slash '/' to backslash '\' */
    fsearch = HDI_FileNameTranslate(dirName);

    FILE_SPRINTF(star, "\\*");
    FILE_STRCAT((FILE_CHAR_T*) fsearch, star);

    /* the length of output filename is in bytes, not wchar */
    if (!dirHandle || *dirHandle < 0)
    {
        h = FS_FindFirst((FILE_CHAR_T*) fsearch, 0, 0, &info, (FILE_CHAR_T*) filename, nameBufLength * 2);
        if (h < 0)
        {
        #ifndef __FS_ASCII__
            FILE_NAME_FREE(filename);
        #endif 
            FILE_NAME_FREE(fsearch);
            return HDI_FILE_ERROR_PATH;
        }
        if (dirHandle)
        {
            *dirHandle = h;
            FILE_SPRINTF(p_dir, "..");

            if (FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) ".") != 0 &&
                FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) p_dir) != 0)
            {
                index++;
            }

            if (index == pos)
            {
                ret = FS_NO_ERROR;
                goto exit;
            }
        }
    }

    FILE_NAME_FREE(fsearch);

    /* for HDIa_fileReadDirSeq() only */
    if (dirHandle && *dirHandle < 0)
    {
        *dirHandle = h;
    }
    FILE_SPRINTF(p_dir, "..");

    if (!dirHandle)
    {
        do
        {
            if (FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) ".") != 0 &&
                FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) p_dir) != 0)
            {
                index++;
            }

            if (index == pos)
            {
                break;
            }

        } while ((ret = FS_FindNext(h, &info, (FILE_CHAR_T*) filename, nameBufLength * 2)) == FS_NO_ERROR);
    }
    else if (dirHandle && *dirHandle >= 0)  /* for HDIa_fileReadDirSeq() only */
    {
        while ((ret = FS_FindNext(*dirHandle, &info, (FILE_CHAR_T*) filename, nameBufLength * 2)) == FS_NO_ERROR)
        {
            if (FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) ".") != 0 &&
                FILE_STRCMP((FILE_CHAR_T*) filename, (FILE_CHAR_T*) p_dir) != 0)
            {
                break;
            }
        }
    }
  exit:
    if (ret == FS_NO_ERROR)
    {
        if ((info.Attributes & FS_ATTR_DIR))
        {
            *type = HDI_FILE_DIRTYPE;
        }
        else
        {
            *type = HDI_FILE_FILETYPE;
            if (size)
            {
                *size = info.FileSize;
            }
            if (size1)
            {
                *size1 = info.FileSize;
            }
        }
    }
    if (!dirHandle || *dirHandle < 0)
    {
        FS_FindClose(h);
    }

#ifndef __FS_ASCII__
    if (ret == HDI_FILE_OK)
    {
        FILE_FS_ADP2UTF8(nameBuf, filename, nameBufLength);
    }

    FILE_NAME_FREE(filename);
#endif /* __FS_ASCII__ */ 

    if (ret != FS_NO_ERROR)
    {
        return HDI_FILE_ERROR_INVALID;  /* the value of 'pos' did not present a valid entry */
    }

    return HDI_FILE_OK;

}   /* end of HDIa_fileReadDir */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileReadDir(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDI_fileReadDir(dirName, pos, nameBuf, nameBufLength, type, size /* int */ , NULL /* long */ , NULL);
}

/* dirHanlde shall not be larger than 0 when application calls at first time */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirSeq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 *  dirHandle           [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileReadDirSeq(
        const char *dirName,
        int pos,
        char *nameBuf,
        int nameBufLength,
        int *type,
        int *size,
        int *dirHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDI_fileReadDir(dirName, pos, nameBuf, nameBufLength, type, size /* int */ , NULL /* long */ , dirHandle);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirSeqClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirHandle       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_fileReadDirSeqClose(int *dirHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*dirHandle > 0)
    {
        FS_FindClose(*dirHandle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirLong
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileReadDirLong(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDI_fileReadDir(dirName, pos, nameBuf, nameBufLength, type, NULL /* int */ , size /* long */ , NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_fileSetSize(int fileHandle, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;
    FS_FileInfo info;
    kal_int32 cur_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 12/15/2003 Kevin: add size < 0 to meet porting guide's requirement */
    if ((HDI_get_file_entry(fileHandle, &entry) == KAL_FALSE) || (size < 0))
    {
        return HDI_FILE_ERROR_INVALID;
    }

    FILEDBG_(printf("set size: fd=%d size=%d\n", fileHandle, size);
        )
        /* get current allocated size & file pointer */
        if (FS_GetFileInfo(fileHandle, &info) < 0)
        {
        return -1;
        }

    if ((cur_pos = FS_Seek(fileHandle, 0, FS_FILE_CURRENT)) < 0)
    {
        return -1;
    }

    if ((U32) size > info.AllocatedSize)
    {
        /* need to extend the file */

    #if 1   /* 05/21/2003 by Kevin,
           because FS_Extend only enlarge "allocated" file size, 
           not the current file size */
        if (FS_Seek(fileHandle, size, FS_FILE_BEGIN) < 0)
        {
            return -1;
        }
    #else /* 1 */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 1 */ 

    }
    else if ((U32) size < info.AllocatedSize)
    {
        /* need to truncate the file */

        /* use FS_Truncate to shorter the file size, 
           FS_truncate set the current file size to "current file pointer"
           thus we need to seek the file pointer to the position we desired 
           and then truncate it !! */
        if (FS_Seek(fileHandle, size, FS_FILE_BEGIN) < 0)
        {
            return -1;
        }

        if (FS_Truncate(fileHandle) < 0)
        {
            return -1;
        }
    }

    /* set file pointer to original one */
    if (cur_pos < size)
    {
        FS_Seek(fileHandle, cur_pos, FS_FILE_BEGIN);
    }

    return size;

}   /* end of HDIa_fileSetSize */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_fileGetSize(const char *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    kal_uint32 size;
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fileName == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILEDBG_(printf("get size %s\n", fileName);
        )
        /* convert slash '/' to backslash '\' */
        fname = HDI_FileNameTranslate(fileName);

    /* because FS_GetFileSize doesn't take file name as argument, thus
       we shall oepn this file first */
    fd = FS_Open((FILE_CHAR_T*) fname, FS_READ_ONLY | FS_OPEN_SHARED);

    FILE_NAME_FREE(fname);

    /* fix return values */
    if (fd < 0)
    {
        return HDI_FileErrorNoTranslate(fd);
    }

    ret = FS_GetFileSize(fd, &size);

    FS_Close(fd);

    if (ret == FS_NO_ERROR)
    {
        FILEDBG_(printf("get size %d\n", size);
            )return size;
    }
    else
    {
        return HDI_FileErrorNoTranslate(ret);
    }

}   /* end of HDIa_fileGetSize */


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSelect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_fileSelect(int fileHandle, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HDI_get_file_entry(fileHandle, &entry) == KAL_FALSE)
    {
        return;
    }

    FILEDBG_(printf("file select: fd=%d event=%d\n", fileHandle, eventType);
        )
        /* for one file, only start timer once */
        if ((HDI_FILE_PTR(entry)->is_read_delay == KAL_FALSE) && (HDI_FILE_PTR(entry)->is_write_delay == KAL_FALSE))
    {
        HDI_file_start_timer(HDI_FILE_PTR(entry));
    }

    if (eventType == HDI_FILE_EVENT_READ)
    {
        HDI_FILE_PTR(entry)->is_read_delay = KAL_TRUE;
    }
    else
    {
        HDI_FILE_PTR(entry)->is_write_delay = KAL_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcName     [IN]        
 *  dstName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_fileRename(const char *srcName, const char *dstName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;
    kal_uint8 *fname1;
    kal_uint8 *fname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcName == NULL || dstName == NULL || FILE_UTF8_STRLEN(srcName) == 0 || FILE_UTF8_STRLEN(dstName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    /* convert slash '/' to backslash '\' */
    fname1 = HDI_FileNameTranslate(srcName);
    fname2 = HDI_FileNameTranslate(dstName);

    ret = FS_Rename((FILE_CHAR_T*) fname1, (FILE_CHAR_T*) fname2);

    FILE_NAME_FREE(fname1);
    FILE_NAME_FREE(fname2);

    if (ret == FS_ACCESS_DENIED)
    {
        return HDI_FILE_ERROR_EXIST;
    }

    return HDI_FileErrorNoTranslate(ret);
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileMove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcName     [IN]        
 *  dstName     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_fileMove(const char *srcName, const char *dstName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *fname1;
    kal_uint8 *fname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcName == NULL || dstName == NULL || FILE_UTF8_STRLEN(srcName) == 0 || FILE_UTF8_STRLEN(dstName) == 0)
    {
        return;
    }

    /* convert slash '/' to backslash '\' */
    fname1 = HDI_FileNameTranslate(srcName);
    fname2 = HDI_FileNameTranslate(dstName);

    FS_Move((const WCHAR*)fname1, (const WCHAR*)fname2, FS_MOVE_COPY, NULL, NULL, 0);

    FILE_NAME_FREE(fname1);
    FILE_NAME_FREE(fname2);

    HDIa_fileRemove(srcName);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileHideDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_fileHideDir(const char *dirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dirName == NULL || FILE_UTF8_STRLEN(dirName) == 0)
    {
        return;
    }

    FILEDBG_(printf("Hide dir: %s\n", dirName);
        )
        /* convert slash '/' to backslash '\' */
        fname = HDI_FileNameTranslate(dirName);

    FS_SetAttributes((unsigned short*)fname, FS_ATTR_DIR | FS_ATTR_HIDDEN);
}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileCloseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_fileCloseAll(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < HDI_MAX_FILE_NUM; i++)
    {
        if ((HDI_FILE_PTR(i)->fd != HDI_INVALID_FILE) && (HDI_FILE_PTR(i)->mod_id == modId))
        {
            /* HDI_FILE_ERROR_ACCESS on closing files of removed memory card */
            if ((ret = HDIa_fileClose(HDI_FILE_PTR(i)->fd)) != 0 && ret != HDI_FILE_ERROR_ACCESS)
            {
                HDI_FILE_ASSERT(0); /* error occurred */
            }
        }
    }
}

#ifdef HDI_FILE_UT

#define HDI_FILE_VERDICT_FAIL ASSERT(0);

/* 1-1   Open with mode of HDI_FILE_SET_CREATE, file not exists   Create a new file */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int r;
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_1: create file\n");
        )HDIa_fileRemove("c:\\fileut.txt"); /* remove anyway */

    f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_CREATE, 0);
    if (f > 0)
    {
        FILEDBG_(printf("FileUT1_1 pass\n");
            )r = HDIa_fileClose(f);
    }

    if (f <= 0 || r != 0)
    {
        FILEDBG_(printf("FileUT1_1 fail\n");
            );
    HDI_FILE_VERDICT_FAIL}
}

/* 1-2   Open with mode of HDI_FILE_SET_CREATE, file exists Open the existed file */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_2: open existing file\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_CREATE, 0);
    if (f > 0)
    {
        FILEDBG_(printf("FileUT1_2 pass\n");
            )r = HDIa_fileClose(f);
    }

    if (f <= 0 || r != 0)
    {
        FILEDBG_(printf("FileUT1_2 fail\n");
            );
    HDI_FILE_VERDICT_FAIL}
}

/* 1-3   Open with mode of HDI_FILE_SET_CREATE + HDI_FILE_SET_EXCL   Return fail if file exists */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_3: open existing file, shall fail\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_EXCL, 0);
    if (f != HDI_FILE_ERROR_EXIST)
    {
        FILEDBG_(printf("FileUT1_3 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT1_3 pass\n");
    )}

}

/* 1-4   Open with mode of HDI_FILE_SET_RDONLY  Try to write the file, the write action shall be failed. If we try to write, the error cause shall be HDI_FILE_ERROR_ACCESS */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    long ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_4: open read-only file and try to write\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT1_4 fail: cannot open fileutEX.txt\n");
            )HDI_FILE_VERDICT_FAIL return;
    }
    else
    {
        /* FILEDBG_(printf("FileUT1_4: open fileutEX.txt success\n");) */

        ret = HDIa_fileWrite(f, "abc", 3);
        if (ret != HDI_FILE_ERROR_ACCESS)
        {
            FILEDBG_(printf("FileUT1_4 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT1_4 pass\n");
        )}

        ret = HDIa_fileClose(f);
        ASSERT(ret == 0);
    }

}

/* 1-5   Open with mode of HDI_FILE_SET_WRONLY  or HDI_FILE_SET_RDWR    Because FS does not support Write Only mode, thus affect of WRONLY is the same as RDWR */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    long ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_5: open write-only and rw file\n");
        )
        /* write only */
        f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_WRONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT1_5 fail: cannot open fileutEX.txt\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    /* FILEDBG_(printf("FileUT1_5: open fileutEX.txt success\n");) */

    ret = HDIa_fileWrite(f, "abc", 3);
    if (ret < 0)
    {
        FILEDBG_(printf("FileUT1_5: failed to write file\n");
            )ret = HDIa_fileClose(f);
        ASSERT(ret == 0);
        HDI_FILE_VERDICT_FAIL return;
    }
    else
    {
        /* FILEDBG_(printf("FileUT1_5: write % bytes\n", ret);) */
    }

    ret = HDIa_fileClose(f);
    ASSERT(ret == 0);

    /* read-write */
    f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT1_5 fail: cannot open fileutEX.txt\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    {
        kal_uint8 data[10];

        /* FILEDBG_(printf("FileUT1_5: open fileutEX.txt success\n");) */

        /* write */
        ret = HDIa_fileWrite(f, "abc", 3);
        if (ret < 0)
        {
            FILEDBG_(printf("FileUT1_5: failed to write file\n");
                )HDI_FILE_VERDICT_FAIL return;
        }
        else
        {
            /* FILEDBG_(printf("FileUT1_5: write % bytes\n", ret);) */
        }

        /* seek */
        HDIa_fileSeek(f, -3, HDI_FILE_SEEK_CUR);

        /* read */
        ret = HDIa_fileRead(f, data, 3);
        if (ret < 0)
        {
            FILEDBG_(printf("FileUT1_5: failed to read file\n");
                )ret = HDIa_fileClose(f);
            ASSERT(ret == 0);
            HDI_FILE_VERDICT_FAIL return;
        }

        data[ret] = '\0';
        /* FILEDBG_(printf("FileUT1_5: read %d bytes, data=%s\n", ret, data);) */
        if (data[0] != 'a' || data[1] != 'b' || data[2] != 'c')
        {
            FILEDBG_(printf("FileUT1_5: read data is wrong\n");
        )HDI_FILE_VERDICT_FAIL}

        ret = HDIa_fileClose(f);
        ASSERT(ret == 0);

        FILEDBG_(printf("FileUT1_5 pass\n");
    )}

}

/* 1-6   Open with mode of HDI_FILE_SET_APPEND  Check whether file pointer is at EOF. */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    long ret;
    kal_uint8 data[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_6: append\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_APPEND, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT1_6 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT1_6: open fileutEX.txt success\n");) */

        ret = HDIa_fileRead(f, data, 10);
        if (ret != HDI_FILE_ERROR_EOF)
        {
            FILEDBG_(printf("FileUT1_6 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT1_6 pass\n");
        )}
        f = HDIa_fileClose(f);
        ASSERT(f == 0);
    }

}

/*
 * 1-7   Open fail - file does not exist  
 * * 1. filename is a null pointerl
 * * 2. file does not exist
 * * 3. path does not exist  
 */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_7: null filename, file/path not exist\n");
        )
        /* case1 */
        f = HDIa_fileOpen(0, 0 /* null file name */ , HDI_FILE_SET_RDWR, 0);

    if (f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT1_7 fail: filename is null\n");
            )HDI_FILE_VERDICT_FAIL return;
    }
    else
    {
        /* FILEDBG_(printf("FileUT1_7: filename is null\n");) */
    }

    /* case2 */
    f = HDIa_fileOpen(0, "c:\\NOTexistfile.txt", HDI_FILE_SET_RDWR, 0);

    if (f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT1_7 fail: this file not exist\n");
            )HDI_FILE_VERDICT_FAIL return;
    }
    else
    {
        /* FILEDBG_(printf("FileUT1_7: cannot open a file not exist\n");) */
    }

    /* case3 */
    f = HDIa_fileOpen(0, "c:\\NOTexistDir\\abc.txt", HDI_FILE_SET_RDWR, 0);

    if (f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT1_7 fail: this path not exist\n");
            )HDI_FILE_VERDICT_FAIL return;
    }
    else
    {
        /* FILEDBG_(printf("FileUT1_7: cannot open a file which path is exist\n");) */
    }

    FILEDBG_(printf("FileUT1_7 pass\n");
)}

/* 1-8   Open fail - open too many files */


/*****************************************************************************
 * FUNCTION
 *  FileUT1_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT1_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    int f[10];
    int r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT1_8: open too many files\n");
        )for (i = 0; i < (HDI_MAX_FILE_BLK * HDI_MAX_FILE_NUM); i++)
    {
        f[i] = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);
        if (f[i] <= 0)
        {
            if (f[i] == HDI_FILE_ERROR_FULL)
            {
                /* FILEDBG_(printf("FileUT1_8: open too many file\n");) */
            }
            else
            {
                FILEDBG_(printf("FileUT1_8 fail: cannot open fileutEX.txt\n");
            )HDI_FILE_VERDICT_FAIL}
            break;
        }
        else
        {
            /* FILEDBG_(printf("FileUT1_8: open fileutEX.txt success\n");) */
        }
    }

    if (f[i] >= 0)
    {
        i++;
        f[i] = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);
        if (f[i] == HDI_FILE_ERROR_FULL)
        {
            /* FILEDBG_(printf("FileUT1_8: open too many file\n");) */
        }
        else
        {
            FILEDBG_(printf("FileUT1_8 fail: cannot open fileutEX.txt, ret=%d\n", f);
        )HDI_FILE_VERDICT_FAIL}
    }

    for (j = 0; j < i; j++)
    {
        r = HDIa_fileClose(f[j]);
        ASSERT(r == 0);
    }

    FILEDBG_(printf("FileUT1_8 pass\n");
)}

/* 2-1   Close ok Close an opened file */


/*****************************************************************************
 * FUNCTION
 *  FileUT2_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT2_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT2_1: close an opened file\n");
        )
        /* close an opended file */
        f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT2_1 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT2_1: open fileutEX.txt success\n");) */

        ret = HDIa_fileClose(f);

        if (ret != 0)
        {
            FILEDBG_(printf("FileUT2_1 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT2_1 pass\n");
        )}
    }

}

/* 2-2   Close fail - invalid file handle Close a file which not be opened before.  Error cause: HDI_FILE_ERROR_INVALID  */


/*****************************************************************************
 * FUNCTION
 *  FileUT2_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT2_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT2_2: close an invalid file\n");
        )
        /* close an unopened file */
        ret = HDIa_fileClose(-11);

    if (ret == 0)
    {
        FILEDBG_(printf("FileUT2_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT2_2 pass\n");
    )}

}

/* 3-1   Read ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT3_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT3_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint32 ret;
    kal_uint8 data[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT3_1: read\n");
        )
        /* close an opended file */
        f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT3_1 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT3_1: open fileutEX.txt success\n");) */

        ret = HDIa_fileRead(f, data, 3);
        if (ret > 0)
        {
            FILEDBG_(printf("FileUT3_1 pass");
        )}
        else
        {
            FILEDBG_(printf("FileUT3_1 fail\n");
        )HDI_FILE_VERDICT_FAIL}

        ret = HDIa_fileClose(f);
        ASSERT(ret == 0);
    }

}

/* 3-2   Read fail - EOF      Error cause: HDI_FILE_ERROR_EOF  */


/*****************************************************************************
 * FUNCTION
 *  FileUT3_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT3_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint32 ret;
    kal_uint8 data[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT3_2: read EOF\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT3_2 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT3_2: open fileutEX.txt success\n");) */

        HDIa_fileSeek(f, 0, HDI_FILE_SEEK_END);

        ret = HDIa_fileRead(f, data, 3);
        if (ret != HDI_FILE_ERROR_EOF)
        {
            FILEDBG_(printf("FileUT3_2 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT3_2 pass\n");
        )}

        ret = HDIa_fileClose(f);
        ASSERT(ret == 0);
    }
}

/* 4-1   Write ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT4_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT4_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT4_1: write\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_WRONLY, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT4_1 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT4_1: open fileutEX.txt success\n");) */

        ret = HDIa_fileWrite(f, "xyz", 3);
        if (ret > 0)
        {
            FILEDBG_(printf("FileUT4_1 pass\n");
        )}
        else
        {
            FILEDBG_(printf("FileUT4_1 fail\n");
        )HDI_FILE_VERDICT_FAIL}

        ret = HDIa_fileClose(f);
        ASSERT(ret == 0);
    }

}

/* 5-1   Rename c:\file1 to c:\file2   file1 exist, file2 not exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT5_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT5_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int r;
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT5_1: remane fileForRename.txt to fileForRename1.txt\n");
        )f = HDIa_fileRemove("c:\\fileForRename1.txt"); /* ensure this file not exist */
    if (f != 0 && f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT5_1 fail: delete fail cause=%d\n", f);
    )HDI_FILE_VERDICT_FAIL}

    f = HDIa_fileOpen(0, "c:\\fileForRename.txt", HDI_FILE_SET_CREATE, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT5_1 fail: cannot open fileForRename.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT5_1: open fileForRename.txt success\n");) */
        r = HDIa_fileClose(f);
        ASSERT(r == 0);

        /* rename */
        f = HDIa_fileRename("c:\\fileForRename.txt", "c:\\fileForRename1.txt");
        if (f != 0)
        {
            FILEDBG_(printf("FileUT5_1 fail: rename fail cause=%d\n", f);
        )HDI_FILE_VERDICT_FAIL}

        /* check whether src file been deleted */
        f = HDIa_fileOpen(0, "c:\\fileForRename.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_EXCL, 0);

        if (f > 0)
        {
            /* FILEDBG_(printf("FileUT5_1 pass: fileForRename.txt not exist\n");) */
        }
        else
        {
            FILEDBG_(printf("FileUT5_1 fail: fileForRename.txt exist\n");
        )HDI_FILE_VERDICT_FAIL}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);

        /* check dst file exist or not */
        f = HDIa_fileOpen(0, "c:\\fileForRename1.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_EXCL, 0);

        if (f == HDI_FILE_ERROR_EXIST)
        {
            /* FILEDBG_(printf("FileUT5_1 pass: fileForRename1.txt exist\n");) */
        }
        else
        {
            FILEDBG_(printf("FileUT5_1 fail: fileForRename1.txt not exist\n");
        )HDI_FILE_VERDICT_FAIL}

        FILEDBG_(printf("FileUT5_1 pass\n");
    )}

}

/* 5-2   Rename a dir ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT5_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT5_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT5_2: remane dirForRename to dirForRename\n");
        )ret = HDIa_fileRmDir("c:\\dirForRename1"); /* ensure dest dir not exist */
    if (ret != 0 && ret != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT5_2 fail: rmdir fail cause=%d\n", ret);
    )HDI_FILE_VERDICT_FAIL}

    ret = HDIa_fileMkDir("c:\\dirForRename");   /* ensure src dir exists */
    if (ret == HDI_FILE_ERROR_EXIST || ret == 0)
    {
        /* FILEDBG_(printf("FileUT5_2: create dir succ\n");) */
    }
    else
    {
        FILEDBG_(printf("FileUT5_2: create dir fail\n");
    )HDI_FILE_VERDICT_FAIL}

    /* rename */
    if (HDIa_fileRename("c:\\dirForRename", "c:\\dirForRename1") != 0)
    {
        FILEDBG_(printf("FileUT5_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT5_2 pass\n");
    )}
}

/* 5-3   Rename c:\file1 to c:\dir1\file2 file1/dir1 exist, file2 not exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT5_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT5_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT5_3: remane c:\\fileForRename.txt to c:\\ExistDir\\fileForRename1.txt\n");
        )r = HDIa_fileRemove("c:\\ExistDir\\fileForRename1.txt");       /* ensure this file not exist */
    if (r != 0 && r != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT5_3 fail: delete fail cause=%d\n", r);
    )HDI_FILE_VERDICT_FAIL}

    f = HDIa_fileOpen(0, "c:\\fileForRename.txt", HDI_FILE_SET_CREATE, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT5_3 fail: cannot open fileForRename.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT5_3: open fileForRename.txt success\n");) */
        r = HDIa_fileClose(f);
        ASSERT(r == 0);

        /* rename */
        r = HDIa_fileRename("c:\\fileForRename.txt", "c:\\ExistDir\\fileForRename1.txt");
        if (r != 0)
        {
            FILEDBG_(printf("FileUT5_3: rename fail %d\n", r);
                )HDI_FILE_VERDICT_FAIL return;
        }

        /* check whether src file been deleted */
        f = HDIa_fileOpen(0, "c:\\fileForRename.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_EXCL, 0);

        if (f > 0)
        {
            /* FILEDBG_(printf("FileUT5_3 pass: fileForRename.txt not exist\n");) */
        }
        else
        {
            FILEDBG_(printf("FileUT5_3 fail: fileForRename.txt exist\n");
        )HDI_FILE_VERDICT_FAIL}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);

        /* check dst file exist or not */
        f = HDIa_fileOpen(0, "c:\\ExistDir\\fileForRename1.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_EXCL, 0);

        if (f == HDI_FILE_ERROR_EXIST)
        {
            /* FILEDBG_(printf("FileUT5_3 pass: fileForRename1.txt exist\n");) */
        }
        else
        {
            FILEDBG_(printf("FileUT5_3 fail: fileForRename1.txt not exist\n");
        )HDI_FILE_VERDICT_FAIL}

        FILEDBG_(printf("FileUT5_3 pass\n");
    )}

}

/* 5-4   Rename fail - old file/dir name not exist    Error cause: HDI_FILE_ERROR_PATH */


/*****************************************************************************
 * FUNCTION
 *  FileUT5_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT5_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT5_4: remane file1 to file2, file1 not exist\n");
        )HDIa_fileRemove("c:\\fileForRename.txt");  /* ensure this file not exist */

    /* rename */
    if (HDIa_fileRename("c:\\fileForRename.txt", "c:\\ExistDir\\fileForRename1.txt") != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT5_4 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT5_4 pass\n");
    )}
}

/* 5-5   Rename fail - new file/dir already existed      Error cause: HDI_FILE_ERROR_EXIST */


/*****************************************************************************
 * FUNCTION
 *  FileUT5_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT5_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT5_5: remane file1 to file2, but file2 exists\n");
        )f = HDIa_fileOpen(0, "c:\\fileForRename.txt", HDI_FILE_SET_CREATE, 0);
    ASSERT(f > 0);
    r = HDIa_fileClose(f);
    ASSERT(r == 0);

    f = HDIa_fileOpen(0, "c:\\fileForRename1.txt", HDI_FILE_SET_CREATE, 0);
    ASSERT(f > 0);
    r = HDIa_fileClose(f);
    ASSERT(r == 0);

    /* rename */
    if (HDIa_fileRename("c:\\fileForRename.txt", "c:\\fileForRename1.txt") != HDI_FILE_ERROR_EXIST)
    {
        FILEDBG_(printf("FileUT5_5 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT5_5 pass\n");
    )}
}

/* 6-1   Remove ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT6_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT6_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT6_1: remove file\n");
        )ret = HDIa_fileRemove("c:\\fileutEX.txt");

    if (ret != 0)
    {
        FILEDBG_(printf("FileUT6_1 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT6_1 pass\n");
    )}

}

/* 6-2   Remove fail - file not exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT6_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT6_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT6_2: remove an unexist file\n");
        )ret = HDIa_fileRemove("c:\\fileutNOTExist.txt");

    if (ret == HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT6_2 pass\n");
    )}
    else
    {
        FILEDBG_(printf("FileUT6_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}

}

/* 7-1   Seek to BEGIN */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_1: seek to begin\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR | HDI_FILE_SET_CREATE, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_1 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT7_1: open fileutEX.txt success\n");) */

        if (HDIa_fileSeek(f, 0, HDI_FILE_SEEK_SET) != 0)
        {
            FILEDBG_(printf("FileUT7_1 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_1 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);

    }

}

/* 7-2   Seek to END */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_2: seek to end\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_2 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FS_FileInfo info;

        /* FILEDBG_(printf("FileUT7_2: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "abcde", 5);

        FS_GetFileInfo(f, &info);

        if (HDIa_fileSeek(f, 0, HDI_FILE_SEEK_END) != info.DirEntry->FileSize)
        {
            FILEDBG_(printf("FileUT7_2 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_2 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-4   Seek from begin, offset = n */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_3: seek from begin, offset=n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_3 fail: cannot open fileutEX.txt\n");
    )}
    else
    {

        /* FILEDBG_(printf("FileUT7_3: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "abcde", 5);

        if (HDIa_fileSeek(f, 3, HDI_FILE_SEEK_SET) != 3)
        {
            FILEDBG_(printf("FileUT7_3 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_3 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-4   Seek from begin, offset = -n */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_4: seek from begin, offset=-n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_4 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {

        /* FILEDBG_(printf("FileUT7_4: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "abcde", 5);

        if (HDIa_fileSeek(f, -3, HDI_FILE_SEEK_SET) > 0)
        {
            FILEDBG_(printf("FileUT7_4 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_4 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-5   Seek from END, offset = -n */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_5: seek from end, offset=-n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_5 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FS_FileInfo info;

        /* FILEDBG_(printf("FileUT7_5: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "abcde", 5);

        FS_GetFileInfo(f, &info);

        if (HDIa_fileSeek(f, -3, HDI_FILE_SEEK_END) != (info.DirEntry->FileSize - 3))
        {
            FILEDBG_(printf("FileUT7_5 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_5 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-6   Seek from END, offset = n  In FS, file will be extended n bytes */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_6: seek from end, offset=n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_6 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FS_FileInfo info;
        long size;

        /* FILEDBG_(printf("FileUT7_6: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "abcde", 5);

        FS_GetFileInfo(f, &info);
        size = info.DirEntry->FileSize;

        if (HDIa_fileSeek(f, 3, HDI_FILE_SEEK_END) != (size + 3))
        {
            FILEDBG_(printf("FileUT7_6 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_6 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-7   Seek from Current Position, offset = n */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_7: seek from current, offset=n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_7 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT7_7: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "1234567890", 10);

        HDIa_fileSeek(f, 5, HDI_FILE_SEEK_SET); /* current pos at 5 */

        if (HDIa_fileSeek(f, 3, HDI_FILE_SEEK_CUR) != 8)
        {
            FILEDBG_(printf("FileUT7_7 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_7 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 7-8   Seek from Current Position, offset = -n */


/*****************************************************************************
 * FUNCTION
 *  FileUT7_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT7_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT7_8: seek from current, offset=-n\n");
        )f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_RDWR, 0);

    if (f <= 0)
    {
        FILEDBG_(printf("FileUT7_8 fail: cannot open fileutEX.txt\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        /* FILEDBG_(printf("FileUT7_8: open fileutEX.txt success\n");) */

        HDIa_fileWrite(f, "1234567890", 10);

        HDIa_fileSeek(f, 5, HDI_FILE_SEEK_SET); /* current pos at 5 */

        if (HDIa_fileSeek(f, -3, HDI_FILE_SEEK_CUR) != 2)
        {
            FILEDBG_(printf("FileUT7_8 fail\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT7_8 pass\n");
        )}

        r = HDIa_fileClose(f);
        ASSERT(r == 0);
    }

}

/* 8-1   Create c:\dir1 dir1 not exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT8_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT8_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT8_1: create an unexist dir\n");
        )f = HDIa_fileMkDir("c:\\NOTEXDir");

    if (f != 0)
    {
        FILEDBG_(printf("FileUT8_1 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT8_1 pass\n");
            )r = HDIa_fileRmDir("c:\\NOTEXDir");
        ASSERT(r == 0);
    }

}

/* 8-2   Create c:\dir1\dir2  dir1 not exist Error cause: HDI_FILE_ERROR_PATH */


/*****************************************************************************
 * FUNCTION
 *  FileUT8_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT8_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT8_2: create dir, path not exist\n");
        )f = HDIa_fileMkDir("c:\\NOTEXDir\\NOTEXDir");

    if (f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT8_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT8_2 pass\n");
    )}

}

/* 8-3   Create an existing dir     Error cause: HDI_FILE_ERROR_EXIST */


/*****************************************************************************
 * FUNCTION
 *  FileUT8_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT8_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT8_3: create an existing dir\n");
        )f = HDIa_fileMkDir("c:\\ExistDir");

    if (f != HDI_FILE_ERROR_EXIST)
    {
        FILEDBG_(printf("FileUT8_3 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT8_3 pass\n");
    )}

}

/* delete the Dir including its file/subdir recursively */


/*****************************************************************************
 * FUNCTION
 *  FileUT_RmDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_dir      [IN]        
 *  dirName1        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long FileUT_RmDir(const FILE_CHAR_T *parent_dir, const FILE_CHAR_T *dirName1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h, ret, r;
    FS_DOSDirEntry info;
    FILE_CHAR_T fname[100], dirName[60];
    FILE_CHAR_T fsearch[60];
    FILE_CHAR_T star[6];    /* "\*" */
    FILE_CHAR_T bs[4];      /* "\" */
    FILE_CHAR_T p_dir[6];   /* ".." */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILE_SPRINTF(bs, "\\");

    if (parent_dir != NULL)
    {
        FILE_STRCPY(dirName, parent_dir);
        FILE_STRCAT(dirName, bs);
        FILE_STRCAT(dirName, dirName1);
        FILE_STRCPY(fsearch, dirName);
    }
    else
    {
        FILE_STRCPY(dirName, dirName1);
        FILE_STRCPY(fsearch, dirName1);
    }

    FILE_SPRINTF(star, "\\*");
    FILE_STRCAT(fsearch, star);

    /* check whether this dir contains file or subdir */
    h = FS_FindFirst((FILE_CHAR_T*) fsearch, 0, 0, &info, (FILE_CHAR_T*) fname, MAX_HDI_FILE_NAME_SIZE);

    FILE_SPRINTF(p_dir, "..");

    if (h > 0)
    {
        if ((info.Attributes & FS_ATTR_DIR))
        {
            if (FILE_STRCMP(fname, (FILE_CHAR_T*) ".") != 0 && FILE_STRCMP(fname, (FILE_CHAR_T*) p_dir) != 0)
            {
                FileUT_RmDir(dirName, fname);
            }
        }
        else
        {
            FILE_CHAR_T fn[100];

            FILE_STRCPY(fn, dirName);
            FILE_STRCAT(fn, bs);
            FILE_STRCAT(fn, fname);
            r = FS_Delete(fn);
            if (r != 0)
            {
                FILEDBG_(printf("FileUT_RmDir: delete fail %d\n", r);
            )}
        }

        while ((ret = FS_FindNext(h, &info, fname, MAX_HDI_FILE_NAME_SIZE)) == FS_NO_ERROR)
        {
            if ((info.Attributes & FS_ATTR_DIR))
            {
                if (FILE_STRCMP(fname, (FILE_CHAR_T*) ".") != 0 && FILE_STRCMP(fname, (FILE_CHAR_T*) p_dir) != 0)
                {
                    FileUT_RmDir(dirName, fname);
                }
            }
            else
            {
                FILE_CHAR_T fn[100];

                FILE_STRCPY(fn, dirName);
                FILE_STRCAT(fn, bs);
                FILE_STRCAT(fn, fname);
                r = FS_Delete(fn);
                if (r != 0)
                {
                    FILEDBG_(printf("FileUT_RmDir: delete fail %d\n", r);
                )}
            }
        }
        FS_FindClose(h);
    }

    h = FS_RemoveDir(dirName);
    /* ASSERT(h==0); */

    return h;

}

/* 9-1   Remove c:\dir1 dir1 exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT9_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT9_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_fileMkDir("c:\\EXDir3");

    fname = HDI_FileNameTranslate("c:\\EXDir3");

    FILEDBG_(printf("FileUT9_1: remove an existing dir\n");
        )f = FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname);

    FILE_NAME_FREE(fname);

    if (f != 0)
    {
        FILEDBG_(printf("FileUT9_1 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT9_1 pass\n");
    )}

}

/* 9-2   Remove a dir but it still contains files or subdir */


/*****************************************************************************
 * FUNCTION
 *  FileUT9_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT9_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT9_2: remove a dir which contains files\n");
        )HDIa_fileOpen(0, "c:\\ExistDir\\fileutEX.txt", HDI_FILE_SET_CREATE, 0);

    f = HDIa_fileRmDir("c:\\ExistDir");
    if (f != HDI_FILE_ERROR_ACCESS)
    {
        FILEDBG_(printf("FileUT9_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT9_2 pass\n");
    )}

}

/* 9-3   Remove c:\dir1 dir1 not exist */


/*****************************************************************************
 * FUNCTION
 *  FileUT9_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT9_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    kal_uint8 *fname = HDI_FileNameTranslate("c:\\NOTEXDir");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT9_3: remove a dir which not exist\n");
        )FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname);

    FILE_NAME_FREE(fname);

    f = HDIa_fileRmDir("c:\\NOTEXDir");
    if (f != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT9_3 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT9_3 pass\n");
    )}

}

/* 10-1  Dir is empty   Shall return zero */


/*****************************************************************************
 * FUNCTION
 *  FileUT10_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT10_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *fname = HDI_FileNameTranslate("c:\\EXDir");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT10_1: get no. of entry of an empty dir\n");
        )FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname);

    FILE_NAME_FREE(fname);

    HDIa_fileMkDir("c:\\EXDir");

    if (HDIa_fileGetSizeDir("c:\\EXDir") != 0)
    {
        FILEDBG_(printf("FileUT10_1 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT10_1 pass\n");
    )}

}

/* 10-2  Dir contains two files and one dir  Shall return three */


/*****************************************************************************
 * FUNCTION
 *  FileUT10_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT10_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f1, f2, r;
    kal_uint8 *fname = HDI_FileNameTranslate("c:\\EXDir");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT10_2: get no. of entry of a dir with 2 files and 1 subdir\n");
        )FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname);

    FILE_NAME_FREE(fname);

    HDIa_fileMkDir("c:\\EXDir");

    HDIa_fileMkDir("c:\\EXDir\\Dir1");  /* create dir */
    f1 = HDIa_fileOpen(0, "c:\\EXDir\\f1.txt", HDI_FILE_SET_CREATE, 0);
    f2 = HDIa_fileOpen(0, "c:\\EXDir\\f2.txt", HDI_FILE_SET_CREATE, 0);

    if (HDIa_fileGetSizeDir("c:\\EXDir") != 3)
    {
        FILEDBG_(printf("FileUT10_2 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT10_2 pass\n");
    )}

    r = HDIa_fileClose(f1);
    ASSERT(r == 0);
    r = HDIa_fileClose(f2);
    ASSERT(r == 0);
}

/* 10-3  Dir is not exist     Error cause: HDI_FILE_ERROR_PATH */


/*****************************************************************************
 * FUNCTION
 *  FileUT10_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT10_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *fname = HDI_FileNameTranslate("c:\\EXDir");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT10_3: get no. of entry of inexistent dir\n");
        )FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname);     /* ensure this dir inexistent */

    FILE_NAME_FREE(fname);

    if (HDIa_fileGetSizeDir("c:\\EXDir") != HDI_FILE_ERROR_PATH)
    {
        FILEDBG_(printf("FileUT10_3 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT10_3 pass\n");
    )}

}

/* 11-1  Dir contains two files and one dir */


/*****************************************************************************
 * FUNCTION
 *  FileUT11_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT11_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int r, f1, f2;
    int type, size;
    kal_char fname[51];
    kal_uint8 *fname1 = HDI_FileNameTranslate("c:\\EXDir");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT11_1: read a dir with 2 files and 1 subdir\n");
        )FileUT_RmDir((FILE_CHAR_T*) NULL, (FILE_CHAR_T*) fname1);

    FILE_NAME_FREE(fname1);

    HDIa_fileMkDir("c:\\EXDir");

    HDIa_fileMkDir("c:\\EXDir\\Dir1");  /* create dir */
    f1 = HDIa_fileOpen(0, "c:\\EXDir\\f1.txt", HDI_FILE_SET_CREATE, 0);
    f2 = HDIa_fileOpen(0, "c:\\EXDir\\f2.txt", HDI_FILE_SET_CREATE, 0);

    /* read 1st entry */
    if (HDIa_fileReadDir("c:\\EXDir", 0, fname, 50, &type, &size) != 0)
    {
        FILEDBG_(printf("FileUT11_1: read 1st entry fail\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    if (type != HDI_FILE_DIRTYPE)
    {
        FILEDBG_(printf("FileUT11_1: 1st entry shall be a dir\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    /* read 2nd entry */
    if (HDIa_fileReadDir("c:\\EXDir", 1, fname, 50, &type, &size) != 0)
    {
        FILEDBG_(printf("FileUT11_1: read 1st entry fail\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    if (type != HDI_FILE_FILETYPE)
    {
        FILEDBG_(printf("FileUT11_1: 1st entry shall be a dir\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    /* read 3rd entry */
    if (HDIa_fileReadDir("c:\\EXDir", 2, fname, 50, &type, &size) != 0)
    {
        FILEDBG_(printf("FileUT11_1: read 1st entry fail\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    if (type != HDI_FILE_FILETYPE)
    {
        FILEDBG_(printf("FileUT11_1: 1st entry shall be a dir\n");
            )HDI_FILE_VERDICT_FAIL return;
    }

    r = HDIa_fileClose(f1);
    ASSERT(r == 0);
    r = HDIa_fileClose(f2);
    ASSERT(r == 0);

    FILEDBG_(printf("FileUT11_1 pass\n");
)}

/* 12-1  Extend file */


/*****************************************************************************
 * FUNCTION
 *  FileUT12_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT12_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT12_1: extend file size to 100\n");
        )
        /* ensure this file size is 0 */
        HDIa_fileRemove("c:\\fileut.txt");
    f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 0);

    if (HDIa_fileSetSize(f, 100) != 100)
    {
        FILEDBG_(printf("FileUT12_1 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FS_FileInfo info;

        FS_GetFileInfo(f, &info);

        if (info.AllocatedSize < 100)
        {
            FILEDBG_(printf("FileUT12_1 fail: file size < 100\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FILEDBG_(printf("FileUT12_1 pass\n");
        )}
    }

    r = HDIa_fileClose(f);
    ASSERT(r == 0);

}

/* 12-2  Truncate file */


/*****************************************************************************
 * FUNCTION
 *  FileUT12_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT12_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;
    FS_FileInfo info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT12_2: truncate file\n");
        )
        /* ensure this file size is 0 */
        HDIa_fileRemove("c:\\fileut.txt");
    f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 0);
    ASSERT(f > 0);
    if (HDIa_fileSetSize(f, 2000) != 2000)  /* ensure file size > 2000 */
    {
        FILEDBG_(printf("FileUT12_2 fail to set size to 2000\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FS_GetFileInfo(f, &info);
        /* FILEDBG_(printf("FileUT12_2 succeeds to set size to 2000, current allocated size=%d\n", info.AllocatedSize);) */

        /* truncate */
        if (HDIa_fileSetSize(f, 30) != 30)
        {
            FILEDBG_(printf("FileUT12_2 fail to set size to 30\n");
        )HDI_FILE_VERDICT_FAIL}
        else
        {
            FS_GetFileInfo(f, &info);
            FILEDBG_(printf("FileUT12_2 pass\n");
        )}
    }

    r = HDIa_fileClose(f);
    ASSERT(r == 0);

}

/* 12-3  Set size fail - file is read-only      Error cause: HDI_FILE_ERROR_ACCESS */


/*****************************************************************************
 * FUNCTION
 *  FileUT12_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT12_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT12_3: set size to a file which opened read-only\n");
        )
        /* ensure this file size is 0 */
        HDIa_fileRemove("c:\\fileut.txt");
    f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_CREATE, 0);
    r = HDIa_fileClose(f);
    ASSERT(r == 0);

    f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_RDONLY, 0);

    ASSERT(f > 0);

    if (HDIa_fileSetSize(f, 100) != HDI_FILE_ERROR_ACCESS)
    {
        FILEDBG_(printf("FileUT12_3 fail\n");
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT12_3 pass\n");
    )}

    r = HDIa_fileClose(f);
    ASSERT(r == 0);

}

/* 13-1  Get ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT13_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT13_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f, r;
    long size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT13_1: get file size\n");
        )f = HDIa_fileOpen(0, "c:\\fileut.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 0);

    HDIa_fileWrite(f, "abc", 3);    /* make sure file size is not zero */

    r = HDIa_fileClose(f);
    ASSERT(r == 0);

    size = HDIa_fileGetSize("c:\\fileut.txt");
    if (size < 0)
    {
        FILEDBG_(printf("FileUT13_1 fail, ret=%d\n", size);
    )HDI_FILE_VERDICT_FAIL}
    else
    {
        FILEDBG_(printf("FileUT13_1 pass\n");
    )}

}

/* 14-1  close ok */


/*****************************************************************************
 * FUNCTION
 *  FileUT14_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT14_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int r;
    kal_uint8 i, j;
    int f[5];
    char fname[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILEDBG_(printf("FileUT14_1: close all files belong to the module\n");
        )for (i = 0; i < 5; i++)
    {
        sprintf(fname, "c:\\utfile%d.txt", i);
        f[i] = HDIa_fileOpen(0, fname, HDI_FILE_SET_CREATE, 0);
        if (f[i] <= 0)
        {
            break;
        }
    }

    HDIa_fileCloseAll(0);

    for (j = 0; j < i; j++)
    {
        sprintf(fname, "c:\\utfile%d.txt", j);
        r = HDIa_fileRemove(fname);
        ASSERT(r == 0);
    }
}

/* HDI File API  regression test function */


/*****************************************************************************
 * FUNCTION
 *  FileUT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FileUT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f = HDIa_fileOpen(0, "c:\\fileutEX.txt", HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f >= 0)
    {
        FILEDBG_(printf("FileUT: create fileutEX.txt success\n");
            )HDIa_fileClose(f);
    }

    f = HDIa_fileMkDir("c:\\ExistDir");

    if (f == 0)
    {
        FILEDBG_(printf("FileUT: create ExistDir success\n");
    )}

#if 1
    /* open file */
    FileUT1_1();
    FileUT1_2();
    FileUT1_3();
    FileUT1_4();
    FileUT1_5();
    FileUT1_6();
    FileUT1_7();
    FileUT1_8();

    /* close file */
    FileUT2_1();
    FileUT2_2();

    /* read file */
    FileUT3_1();
    FileUT3_2();

    /* write file */
    FileUT4_1();

    /* rename file/dir */
    FileUT5_1();
    FileUT5_2();
    FileUT5_3();
    FileUT5_4();
    FileUT5_5();

    /* remove file */
    FileUT6_1();
    FileUT6_2();

    /* seek file */
    FileUT7_1();
    FileUT7_2();
    FileUT7_3();
    FileUT7_4();
    FileUT7_5();
    FileUT7_6();
    FileUT7_7();
    FileUT7_8();

    /* create dir */
    FileUT8_1();
    FileUT8_2();
    FileUT8_3();

    /* remove dir */
    FileUT9_1();
    FileUT9_2();
    FileUT9_3();

    /* get no. of entry of dir */
    FileUT10_1();
    FileUT10_2();
    FileUT10_3();

    /* read dir */
    FileUT11_1();

    /* set file size */
    FileUT12_1();
    FileUT12_2();
    FileUT12_3();

    /* get file size */
    FileUT13_1();

    /* close all */
    FileUT14_1();
#endif /* 1 */ 

    /* FileUT9_1(); */
}

#endif /* HDI_FILE_UT */ 

