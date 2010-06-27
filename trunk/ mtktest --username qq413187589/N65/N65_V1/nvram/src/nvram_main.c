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
 * nvram_main.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
#include <string.h>

#include "kal_release.h"        /* Basic data type */
#include "stdio.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

/* Statistics */
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "tst_buff_pool.h"
#include "sysconf_statistics.h"

#include "nvram.h"
#include "nvram_defs.h"
#include "custom_nvram_sec.h"
#include "nvram_context.h"
#include "nvram_ltable.h"
#include "nvram_io.h"
#include "nvram_main.h"

#include "nvram_handler_startup.h"
#include "nvram_handler_reset.h"
#include "nvram_handler_read.h"
#include "nvram_handler_write.h"
#include "nvram_handler_tst.h"
#include "nvram_ilm.h"  /* __SHADOW_SUPPORT_SB__ */

#include "nvram_drval_fat.h"
#include "nvram_user_defs.h"
#include "nvram_interface.h"

#include "Fat_fs.h"
#include "pwic.h"

/* Factory mode, should not send ADC calibration data to BMT  */
#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#include "IntrCtrl.h"
#endif /* __MULTI_BOOT__ */ 

/***************************************************************************** 
* Define
*****************************************************************************/
#define OVERHEAD_CLUSTER         8      /* extra space in bytes needed for conflict resolution. ex, report files */
#define DISPLAY_WARNING_TIME 1000       /* 1000 ticks = 4.6 sec */
#define CHANGE_ARRAY_SIZE (NVRAM_EF_LAST_LID_CUST + 1)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    kal_bool checked;
    WCHAR diskfile[NVRAM_FILE_LEN + 1];
} diskTableEntry;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
kal_uint32 BytesPerCluster;  /* will be set to exact value in nvram_get_disk_file_info */

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/
#if (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI))
extern void MMISWChangeWarning(
                kal_uint8 type,
                kal_uint32 space,
                kal_uint8 const *codeversion,
                kal_uint8 const *diskversion);
#endif /* (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)) */ 

extern void *kal_tmp_mem_alloc(kal_uint32 size);
extern void kal_tmp_mem_free(void *mem_ptr);

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
extern void MMICheckDiskDisplay(void);
#endif 
extern void nvram_read_confirm
    (module_type dest_id,
     nvram_errno_enum result, nvram_read_req_struct *nvram_read_req, kal_uint16 size, peer_buff_struct *peer_buf_ptr);

/***************************************************************************** 
* Global Function
*****************************************************************************/
kal_bool nvram_read_system_record(kal_uint8 *buffer, kal_uint16 size);
void nvram_set_lock_state(kal_uint8 *coded_version);

/***************************************************************************** 
* Local Function
*****************************************************************************/
static kal_bool nvram_init_all_ldi(nvram_reset_category_enum reset_category);
static kal_bool nvram_scan_all_ldi(void);

static void nvram_special_service(void);

#if defined(__WIFI_SUPPORT__)
static void nvram_send_wndrv_cal(void);
#endif 
static void nvram_send_bmt_cal(void);

#ifndef __PRODUCTION_RELEASE__
static void nvram_notify_exception(void);
static void nvram_notify_statistics(void);
#endif /* __PRODUCTION_RELEASE__ */ 

static kal_bool nvram_supplementary_check(kal_uint8 LIDtoCheck);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static kal_uint32 *nvram_init_tmp_pool = NULL;
static diskTableEntry *DiskTable = NULL;
static kal_uint16 DiskFileCount = 0;
static kal_uint32 *LIDChangeArray = NULL;   /* [count, lid1, lid2,..] ex. [3, 12, 29] */
static kal_uint32 LIDChanged = 0;

static kal_uint32 *LIDChangeArraySYS = NULL;        /* [count, lid1, lid2,..] ex. [3, 12, 29] */
static kal_uint32 LIDChangedSYS = 0;
static kal_uint8 last_ex_record = 1;


/*****************************************************************************
 * FUNCTION
 *  nvram_create
 * DESCRIPTION
 *  NVRAM task create function
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool nvram_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct nvram_handler_info = 
    {
        nvram_task_main,    /* task entry function */
        nvram_init,         /* task initialization function */
        NULL,               /* task configuration function */
        nvram_reset,        /* task reset handler */
        nvram_deinit,       /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & nvram_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_task_main
 * DESCRIPTION
 *  NVRAM task
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    /* nvram special service */
    nvram_special_service();

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        nvram_main(&current_ilm);

        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_main
 * DESCRIPTION
 *  This is main() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ilm_ptr != NULL);

    if (ilm_ptr != NULL)
    {
        if ((ilm_ptr->msg_id >= MSG_ID_NVRAM_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_NVRAM_CODE_END))
        {

            if (ilm_ptr->msg_id == MSG_ID_NVRAM_STARTUP_REQ)
            {
                nvram_startup_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_RESET_REQ)
            {
                nvram_reset_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_READ_REQ)
            {
                nvram_read_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_REQ)
            {
                nvram_write_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_SET_LOCK_REQ)
            {
                nvram_set_lock_handler(ilm_ptr);
            }
        }
    #ifdef __SHADOW_SUPPORT_SB__
        else if (ilm_ptr->msg_id == MSG_ID_TIMER_EXPIRY)
        {
            kal_prompt_trace(MOD_NVRAM, "Shadow NVRAM Periodic Flushing");
            nvram_timer_expiry_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
        }
    #endif /* __SHADOW_SUPPORT_SB__ */ 
    #ifdef TST_HANDLER
        else
        {
            /* not nvram defined message */
            if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
            {
                nvram_tst_handler(ilm_ptr);
            }
        }
    #endif /* TST_HANDLER */ 

    }
}   /* end of module main function */


/*****************************************************************************
 * FUNCTION
 *  nvram_construct_disk_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_construct_disk_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];
    WCHAR filename[NVRAM_FILE_LEN + 1];
    kal_uint16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(namepattern, "*");

    nvram_init_tmp_pool = (kal_uint32 *) kal_tmp_mem_alloc(CHANGE_ARRAY_SIZE * 2 + (kal_uint32)(DiskFileCount * sizeof(diskTableEntry)));
    LIDChangeArray = nvram_init_tmp_pool;
    LIDChangeArraySYS= nvram_init_tmp_pool + CHANGE_ARRAY_SIZE;

    if (DiskFileCount > 0)
    {
        DiskTable = (diskTableEntry *)(nvram_init_tmp_pool + CHANGE_ARRAY_SIZE * 2);

        if (!DiskTable)
        {
            return KAL_FALSE;
        }

        kal_mem_set(DiskTable, 0, DiskFileCount * sizeof(diskTableEntry));
    }
    else
    {
        return KAL_FALSE;
    }

    handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, FS_MAX_PATH);
    if (handle > 0)
    {
        index = 0;
        do
        {
            if (index >= DiskFileCount) /* entry numbers mismatch .... error out */
            {
                return KAL_FALSE;
            }

            kal_wstrncpy(DiskTable[index].diskfile, filename, NVRAM_FILE_LEN);
            DiskTable[index].diskfile[NVRAM_FILE_LEN] = 0;  /* Terminator */
            index++;
        }
        while (FS_FindNext(handle, &fileinfo, filename, FS_MAX_PATH) == FS_NO_ERROR);
    }
    else
    {
        return KAL_FALSE;
    }

    FS_FindClose(handle);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_destruct_disk_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_destruct_disk_table(kal_bool ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        kal_tmp_mem_free(nvram_init_tmp_pool);
        nvram_init_tmp_pool = NULL;
        
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_search_disk_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_search_disk_table(char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    diskTableEntry *dfile;
    kal_uint16 index;
    WCHAR filename[NVRAM_FILE_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* translate name into 2-byte format because file names in Disk table are in 2-byte format */
    kal_wsprintf(filename, "%s", name);

    for (index = 0; index < DiskFileCount; index++)
    {
        dfile = &(DiskTable[index]);

        if (!dfile->checked)
        {
            if (!kal_wstrcmp(dfile->diskfile, filename))
            {
                dfile->checked = KAL_TRUE;  /* mark this file in the Disk table */
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}

#ifdef NVRAM_TESTING_USE
/* nvram_delete_disk_files_with_prefix loops thru Disk Table and delete files with the specified prefix. */


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_disk_files_with_prefix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_delete_disk_files_with_prefix(char *prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    diskTableEntry *dfile;
    kal_uint16 index;
    WCHAR fnameprefix[NVRAM_FILE_LEN + 1];
    WCHAR filename[NVRAM_MAX_PATH_LEN];
    kal_uint32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* translate prefix into 2-byte format because file names in Disk table are in 2-byte format */
    kal_wsprintf(fnameprefix, "%s", prefix);

    for (index = 0; index < DiskFileCount; index++)
    {
        dfile = &(DiskTable[index]);

        if (!dfile->checked)
        {
            if (!kal_wstrncmp(dfile->diskfile, fnameprefix, FILE_PREFIX_LEN))
            {
                dfile->checked = KAL_TRUE;  /* mark this file in the Disk table */

                kal_wsprintf(filename, "%s\\%w\0", NVRAM_FS_DATAITEM_PATH, dfile->diskfile);

                retval = FS_Delete(filename);
                if ((retval != FS_NO_ERROR) && (retval != FS_FILE_NOT_FOUND))
                {
                    return KAL_FALSE;
                }
            }
        }
    }

    return KAL_TRUE;
}
#endif /* NVRAM_TESTING_USE */ 

/* nvram_delete_disk_files_unchecked loops thru Disk Table and delete all unchecked files.  */


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_disk_files_unchecked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_delete_disk_files_unchecked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    diskTableEntry *dfile;
    kal_uint16 index;
    WCHAR filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < DiskFileCount; index++)
    {
        dfile = &(DiskTable[index]);

        if (!dfile->checked)
        {
            dfile->checked = KAL_TRUE;  /* mark this file in the Disk table. does this matter? */

            kal_wsprintf(filename, "%s\\%w\0", NVRAM_FS_DATAITEM_PATH, dfile->diskfile);

            if (FS_Delete(filename) != FS_NO_ERROR)
            {
                return KAL_FALSE;
            }
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_all_nvram_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_delete_all_nvram_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];
    WCHAR filename[NVRAM_FILE_LEN + 1];
    WCHAR fullfilename[NVRAM_MAX_PATH_LEN];
    kal_uint32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(namepattern, "*");

    handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, FS_MAX_PATH);
    if (handle > 0)
    {
        do
        {
            kal_wsprintf(fullfilename, "%s\\%w\0", NVRAM_FS_DATAITEM_PATH, filename);
            retval = FS_Delete(fullfilename);
            if (retval != FS_NO_ERROR)
            {
                return KAL_FALSE;
            }
        }
        while (FS_FindNext(handle, &fileinfo, filename, FS_MAX_PATH) == FS_NO_ERROR);
    }
    else
    {
        return KAL_FALSE;
    }

    FS_FindClose(handle);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_report_conflict_data_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  LID     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_report_conflict_data_item(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LIDChanged++;
    ASSERT(LIDChanged <= 255);
    LIDChangeArray[0] = LIDChanged; /* Count */
    LIDChangeArray[LIDChanged] = LID;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_report_sys_data_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  LID     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_report_sys_data_item(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LIDChangedSYS++;
    ASSERT(LIDChangedSYS <= 255);
    LIDChangeArraySYS[0] = LIDChangedSYS;   /* Count */
    LIDChangeArraySYS[LIDChangedSYS] = LID;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_create_report_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_create_report_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[32];
    FS_HANDLE handle;
    kal_uint32 filelen = (1 + LIDChanged) * sizeof(kal_uint32);
    kal_uint32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", NVRAM_SWCHANGE_REPORT_FILE);
    FS_Delete(filename);

    handle = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle > FS_NO_ERROR)
    {
        if (FS_Write(handle, LIDChangeArray, filelen, &written) != FS_NO_ERROR)
        {
            FS_Close(handle);
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    FS_Close(handle);

    kal_wsprintf(filename, "%s", NVRAM_SWCHANGE_REPORT_FILE_TXT);
    FS_Delete(filename);

    handle = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle > FS_NO_ERROR)
    {
        kal_uint32 index, desc_len;
        kal_char buf[NVRAM_MAX_DESC_LEN + 1];
        ltable_entry_struct *ldi;

        for (index = 1; index <= LIDChanged; index++)
        {
            if (!NVRAM_IS_LID_VALID(LIDChangeArray[index]))
            {
                continue;
            }
            nvram_get_data_item(ldi, LIDChangeArray[index]);

            desc_len = strlen(ldi->description);
            desc_len = (desc_len > NVRAM_MAX_DESC_LEN ? NVRAM_MAX_DESC_LEN : desc_len);

            kal_mem_cpy(buf, ldi->description, desc_len);
            buf[desc_len] = ',';
            if (FS_Write(handle, buf, desc_len + 1, &written) != FS_NO_ERROR)
            {
                FS_Close(handle);
                return KAL_FALSE;
            }
        }
    }
    else
    {
        return KAL_FALSE;
    }

    FS_Close(handle);

    return KAL_TRUE;
}

#ifdef NVRAM_TESTING_USE


/*****************************************************************************
 * FUNCTION
 *  nvram_create_backup_enforce_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_int     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_create_backup_enforce_file(kal_uint32 control_int)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[32];
    FS_HANDLE handle;
    kal_uint32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", NVRAM_SWFORCEUPGRADE_FILE);
    FS_Delete(filename);

    handle = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle > FS_NO_ERROR)
    {
        if (FS_Write(handle, &control_int, sizeof(kal_uint32), &written) != FS_NO_ERROR)
        {
            FS_Close(handle);
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    FS_Close(handle);

}
#endif /* NVRAM_TESTING_USE */ 

#ifdef NVRAM_TESTING_USE


/*****************************************************************************
 * FUNCTION
 *  nvram_remove_backup_enforce_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_remove_backup_enforce_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", NVRAM_SWFORCEUPGRADE_FILE);
    FS_Delete(filename);
}
#endif /* NVRAM_TESTING_USE */ 

#if (defined(SW_CHANGE_BLOCKING))


/*****************************************************************************
 * FUNCTION
 *  nvram_check_for_backup_enforced
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_check_for_backup_enforced(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[32];
    FS_HANDLE handle;
    kal_uint32 control_int;
    kal_uint32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", NVRAM_SWFORCEUPGRADE_FILE);

    handle = FS_Open(filename, FS_READ_ONLY);
    if (handle > FS_NO_ERROR)
    {
        if (FS_Read(handle, &control_int, sizeof(kal_uint32), &read) != FS_NO_ERROR)
        {
            FS_Close(handle);
            return KAL_TRUE;
        }
        else if (control_int == 1)
        {
            FS_Close(handle);
            return KAL_FALSE;   /* only when the control value is 1, we do not enforce backup */
        }
    }
    else
    {
        return KAL_TRUE;
    }

    FS_Close(handle);

    return KAL_TRUE;
}
#endif /* (defined(SW_CHANGE_BLOCKING)) */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_swchange_warning
 * DESCRIPTION
 *  To warn the user there is no enough space to perform software change.
 * PARAMETERS
 *  SpaceNedded     [IN]        
 *  diskversion     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_swchange_warning(kal_uint32 SpaceNedded, kal_uint8 const *diskversion)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tick_start, tick_now;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI))
    MMISWChangeWarning(0, SpaceNedded, nvram_ptr->coded_version, (kal_uint8 const*)diskversion);
#endif 
    kal_get_time(&tick_start);

    do
    {
        kal_get_time(&tick_now);

        if ((tick_now - tick_start) >= DISPLAY_WARNING_TIME)
        {
            break;
        }

    } while (1);

}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_disk_file_size
 * DESCRIPTION
 *  To calc the existence file size on FS.
 * PARAMETERS
 *  DiskFileSizeTotal       [OUT]       Total existence file size
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_get_disk_file_size(kal_uint32 *DiskFileSizeTotal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry fileinfo;
    FS_HANDLE handle;
    WCHAR namepattern[32];
    WCHAR filename[NVRAM_FILE_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NVRAM_FS_MAKE_LID_PATH_FILENAME_1(namepattern, "*");

    DiskFileCount = 0;
    *DiskFileSizeTotal = 0;

    /* phase 1: collect disk file count and allocate DiskTable */
    handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, FS_MAX_PATH);
    if (handle > 0)
    {
        do
        {
            DiskFileCount++;
            *DiskFileSizeTotal += BytesPerCluster * (1 + (fileinfo.FileSize - 1) / BytesPerCluster);
        }
        while (FS_FindNext(handle, &fileinfo, filename, FS_MAX_PATH) == FS_NO_ERROR);
    }
    else
    {
        return KAL_FALSE;
    }

    FS_FindClose(handle);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_disk_file_info
 * DESCRIPTION
 *  To get infomation of NVRAM FS usage.
 * PARAMETERS
 *  diskfilesize        [OUT]       Total existence file size
 *  freespace           [OUT]       Free space of FS (in byte)
 *  overhead            [OUT]       Overhead space (in byte)
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_bool nvram_get_disk_file_info(kal_uint32 *diskfilesize, kal_uint32 *freespace, kal_uint32 *overhead)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR DriveName[8];
    FS_DiskInfo DI;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(DriveName, "%s\0", "Z:\\");
    if (FS_GetDiskInfo((const WCHAR*)DriveName, &DI, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE | FS_DI_FAT_STATISTICS) <
        FS_NO_ERROR)
    {
        return KAL_FALSE;
    }

    /* Set BytesPerCluster to the accurate value */
    BytesPerCluster = DI.BytesPerSector * DI.SectorsPerCluster;

    *freespace = BytesPerCluster * DI.FreeClusters;

    if (!nvram_get_disk_file_size(diskfilesize))
    {
        return KAL_FALSE;
    }

    *overhead = BytesPerCluster * OVERHEAD_CLUSTER;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_code_file_size
 * DESCRIPTION
 *  To get infomation of NVRAM RO usage.
 * PARAMETERS
 *  CodeFileSizeTotal       [OUT]       Total RO size
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_code_file_size(kal_uint32 *CodeFileSizeTotal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    nvram_lid_enum file_idx;
    kal_uint32 onefilesize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *CodeFileSizeTotal = 2 * BytesPerCluster * (1 + (NVRAM_EF_SYS_SIZE - 1) / BytesPerCluster);

    for (file_idx = NVRAM_EF_SYS_LID + 1; file_idx < nvram_ptr->ltable.total_LID; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);

        /* each record followed by a 2-byte checksum */
        onefilesize = (ldi->size + 2) * ldi->total_records;
        if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
        {
            *CodeFileSizeTotal += 2 * BytesPerCluster * (1 + (onefilesize - 1) / BytesPerCluster);
        }
        else
        {
            *CodeFileSizeTotal += BytesPerCluster * (1 + (onefilesize - 1) / BytesPerCluster);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_conflict_resolve_prelim
 * DESCRIPTION
 *  To calc the disk size that software upgrade needs.
 * PARAMETERS
 *  sysrecord       [IN]        Sysrecord
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_conflict_resolve_prelim(kal_uint8 *sysrecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 diskfilesize, codefilesize, freespace, overhead;
    kal_int32 spaceDelta;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!nvram_get_disk_file_info(&diskfilesize, &freespace, &overhead))
    {
        return KAL_FALSE;
    }

    nvram_get_code_file_size(&codefilesize);

    spaceDelta = codefilesize + overhead - diskfilesize;

    if ((spaceDelta > 0) && (spaceDelta > freespace))
    {
        kal_uint32 spaceNeeded = spaceDelta - freespace;
        kal_uint8 diskversion[CODED_DATA_VERSION_SIZE + 1];

        kal_mem_cpy(diskversion, sysrecord, CODED_DATA_VERSION_SIZE);
        diskversion[CODED_DATA_VERSION_SIZE] = '\0';

        /* 
         * no enough space for conflict resolution, need to 
         * 1. show the space delta on the LCD. 
         * 2. power off. hopefully users will delete some files to make it work next time
         */
        nvram_swchange_warning(spaceNeeded, diskversion);

    #if !defined(__FS_CHECKDRIVE_SUPPORT__)
        FS_ClearDiskFlag();
    #endif 
        FS_ShutDown();
        DRV_POWEROFF();
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_version_conflict_resolve
 * DESCRIPTION
 *  To perform software upgrade.
 * PARAMETERS
 *  sysrecord       [IN]        Sysrecord
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_version_conflict_resolve(kal_uint8 *sysrecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool rtn_val = KAL_TRUE;
    kal_bool important_LDI_changed = KAL_FALSE;
    kal_bool BACKUP_ENFORCED;
    ltable_entry_struct *ldi;
    nvram_lid_enum file_idx, index;
    NVRAM_FILE_NAME nvramname1, nvramname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latch power first and show the first picture */
    DRV_POWERON();
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    MMICheckDiskDisplay();
#endif 

    if (!nvram_conflict_resolve_prelim(sysrecord) || !nvram_construct_disk_table())
    {
        rtn_val = KAL_FALSE;
        return nvram_destruct_disk_table(rtn_val);
    }

    LIDChangeArray[0] = 0;  /* Count */
    LIDChanged = 0;

    /****** 1st phase for loop starts here. The looping is based on the Code table ******/
    for (file_idx = NVRAM_EF_SYS_LID + 1; file_idx < nvram_ptr->ltable.total_LID; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);
        if (ldi->category & NVRAM_CATEGORY_SYSTEM)  /* those data items need to be reset to code default values */
        {
            nvram_report_sys_data_item(ldi->LID);
        }
        else if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr)) /* Process Multiple */
        {

            /* construct filename1 */
            NVRAM_MAKE_LID_FILENAME(nvramname1, ldi->fileprefix, 'a', ldi->fileverno);
            /* construct filename2 */
            NVRAM_MAKE_LID_FILENAME(nvramname2, ldi->fileprefix, 'b', ldi->fileverno);

            if (nvram_search_disk_table(nvramname1) && nvram_search_disk_table(nvramname2))
            {
            }   /* We found them both, which means their format has not been changed. Good. Do nothing. */
            else
            {
                /* report the data item */
                nvram_report_conflict_data_item(ldi->LID);

                if (ldi->attr & NVRAM_ATTR_IMPORTANT)
                {
                    important_LDI_changed = KAL_TRUE;
                }
            }
        }
        else    /* Process Single */
        {
            /* construct filename */
            NVRAM_MAKE_LID_FILENAME(nvramname1, ldi->fileprefix, '_', ldi->fileverno);

            if (nvram_search_disk_table(nvramname1))
            {
            }   /* We found it, which means its format has not been changed. Good. Do nothing. */
            else
            {
                /* report the data item */
                nvram_report_conflict_data_item(ldi->LID);

                if (ldi->attr & NVRAM_ATTR_IMPORTANT)
                {
                    important_LDI_changed = KAL_TRUE;
                }
            }
        }
    }
    /****** 1st phase for loop ends here ******/

    /*
     * 1. check if IMEI is locked, if so, do 2, else fall thru
     * 2. display [disk SW version] [LIDs], prompt user input
     * 3. fall thru if yes is got, else go version_resolve_exit and poweroff
     */
    if (!nvram_create_report_file())
    {
        rtn_val = KAL_FALSE;
        return nvram_destruct_disk_table(rtn_val);
    }

#if (defined(SW_CHANGE_BLOCKING))
    /* blocking enabled: check for SWFORCEBACKUP */
    BACKUP_ENFORCED = nvram_check_for_backup_enforced();
#else /* (defined(SW_CHANGE_BLOCKING)) */ 
    BACKUP_ENFORCED = KAL_FALSE;
#endif /* (defined(SW_CHANGE_BLOCKING)) */ 

    if (BACKUP_ENFORCED && important_LDI_changed)
    {
        kal_uint8 diskversion[CODED_DATA_VERSION_SIZE + 1];

        kal_mem_cpy(diskversion, sysrecord, CODED_DATA_VERSION_SIZE);
        diskversion[CODED_DATA_VERSION_SIZE] = '\0';

        nvram_swchange_warning(0, diskversion);

    #if !defined(__FS_CHECKDRIVE_SUPPORT__)
        FS_ClearDiskFlag();
    #endif 
        FS_ShutDown();
        DRV_POWEROFF();
    }
    else
    {
        /* 
         * Keep the flag in the system = users want this behavior happens ni the future. 
         * nvram_remove_backup_enforce_file();  
         */
    }

    /* remove all files left unchecked in Disk table */
    if (!nvram_delete_disk_files_unchecked())
    {
        rtn_val = KAL_FALSE;
        return nvram_destruct_disk_table(rtn_val);
    }

    /****** 2nd phase for loop starts here. The looping is based on LIDChangeArray ******/
    for (index = 1; index <= LIDChanged; index++)
    {
        file_idx = LIDChangeArray[index];

        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);
/* __GEMINI__ */
        if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records))
/* __GEMINI__ */            
        {
            rtn_val = KAL_FALSE;
            return nvram_destruct_disk_table(rtn_val);
        }

    }

    /* those data items need to be reset to code default values */
    for (index = 1; index <= LIDChangedSYS; index++)
    {
        file_idx = LIDChangeArraySYS[index];

        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);

/* __GEMINI__ */
        if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records))
/* __GEMINI__ */            
        {
            rtn_val = KAL_FALSE;
            return nvram_destruct_disk_table(rtn_val);
        }
    }
   /****** 2nd phase for loop ends here ******/

    /****** rewrite system records ******/
    nvram_get_data_item(ldi, NVRAM_EF_SYS_LID);
/* __GEMINI__ */
       if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records))
/* __GEMINI__ */            
    {
        rtn_val = KAL_FALSE;
        return nvram_destruct_disk_table(rtn_val);
    }

    return nvram_destruct_disk_table(rtn_val);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_init
 * DESCRIPTION
 *  This is init() function of NVRAM module.
 *  This function initialize all the context variables required for NVRAM module
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool nvram_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ld_init_result = KAL_TRUE;
    nvram_drv_status_enum drv_init_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Assume that BytesPerCluster still not initialized if BytesPerCluster==0 */
    if (BytesPerCluster == 0)
    {
        BytesPerCluster = FS_GetClusterSize('Z');
    }

    nvram_pre_init();
   /**
    * As long as system-device reports unformatted, format all devices and 
    * re-initialize all logical data items.
    */

    nvram_drv_fat_set_max_record_number(nvram_ptr->total_record_ID);

    nvram_ptr->software_change_status = 0;

    /* Initialization OK */
    if ((drv_init_result = nvram_drv_fat_init()) == NVRAM_DRV_OK)
    {
        kal_uint8 sys_record[NVRAM_EF_SYS_SIZE];

        /* Read back system-level record to retrieve software-lock status and data version */
      /**
       * 1. Read failed, 
       *    NVRAM Layer must re-initialize all logical data items b'coz we could not ensure the healthy of all ldi
       * 2. Read success but incompatible versions, 
       *    NVRAM Layer must re-initialize all `USER' category logical data items.
       */

        kal_mem_set(sys_record, 0, NVRAM_EF_SYS_SIZE);
        if ((ld_init_result = nvram_read_system_record(sys_record, NVRAM_EF_SYS_SIZE)) == KAL_FALSE)
        {
            /* read system rec failed */
            nvram_ptr->software_change_status |= NVRAM_SOFTWARE_CHANGE;
            ld_init_result = nvram_init_all_ldi(NVRAM_RESET_ALL);
        }
        else if (strncmp((kal_char*) sys_record, (kal_char*) nvram_ptr->coded_version, CODED_DATA_VERSION_SIZE) != 0)
        {
            /* version incompatible */
            nvram_ptr->software_change_status |= NVRAM_SOFTWARE_CHANGE;

            if (!(ld_init_result = nvram_version_conflict_resolve(sys_record)))
            {
                /* if errors happen during conflict resolution, initialize all LIDs */
                ld_init_result = nvram_init_all_ldi(NVRAM_RESET_ALL);
            }

            /* handle branch/BIN change */
            {
                ltable_entry_struct *ldi;

                nvram_get_data_item(ldi, NVRAM_EF_BRANCH_VERNO_LID);
                if (!nvram_supplementary_check(NVRAM_EF_BRANCH_VERNO_LID))
                {
/* __GEMINI__ */
                    ld_init_result = nvram_reset_data_items(NVRAM_RESET_BRANCH, ldi, 0, 0);
/* __GEMINI__ */
                    nvram_ptr->software_change_status |= NVRAM_BRANCH_CHANGE;
                }

                nvram_get_data_item(ldi, NVRAM_EF_CUSTPACK_VERNO_LID);
                if (!nvram_supplementary_check(NVRAM_EF_CUSTPACK_VERNO_LID))
                {
/* __GEMINI__ */
                    ld_init_result = nvram_reset_data_items(NVRAM_RESET_CUSTPACK, ldi, 0, 0);
/* __GEMINI__ */
                    nvram_ptr->software_change_status |= NVRAM_CUSTPACK_CHANGE;
                }
            }
        }
        else
        {
            /* handle branch/BIN change */
            {
                ltable_entry_struct *ldi;

                nvram_get_data_item(ldi, NVRAM_EF_BRANCH_VERNO_LID);
                if (!nvram_supplementary_check(NVRAM_EF_BRANCH_VERNO_LID))
                {
/* __GEMINI__ */
                    ld_init_result = nvram_reset_data_items(NVRAM_RESET_BRANCH, ldi, 0, 0);
/* __GEMINI__ */
                    nvram_ptr->software_change_status |= NVRAM_BRANCH_CHANGE;
                }

                nvram_get_data_item(ldi, NVRAM_EF_CUSTPACK_VERNO_LID);
                if (!nvram_supplementary_check(NVRAM_EF_CUSTPACK_VERNO_LID))
                {
/* __GEMINI__ */
                    ld_init_result = nvram_reset_data_items(NVRAM_RESET_CUSTPACK, ldi, 0, 0);
/* __GEMINI__ */
                    nvram_ptr->software_change_status |= NVRAM_CUSTPACK_CHANGE;
                }
            }

            /* Read sys record success and version compatible */
            nvram_scan_all_ldi();

            nvram_set_lock_state((kal_uint8*) sys_record);
        }
    }
    else if(drv_init_result == NVRAM_DRV_DRIVE_BROKEN ||
            drv_init_result == NVRAM_DRV_DRIVE_VNOERR)
    {
        nvram_ptr->dev_broken = KAL_TRUE;
    }
    else    /* NVRAM_DRV_UNFORMATTED */
    {
        nvram_ptr->software_change_status |= NVRAM_EMPTY_FAT;

        nvram_drv_fat_init(); /* Format all devices */

        ld_init_result = nvram_init_all_ldi(NVRAM_RESET_ALL);
    }

    if (nvram_ptr->dev_broken)
    {
        nvram_ptr->state = NVRAM_STATE_READY;
    }
    else if (ld_init_result == KAL_TRUE)
    {
/* __GEMINI__ */
        nvram_reset_data_items(NVRAM_RESET_FACTORY, 0, 0, 0);
/* __GEMINI__ */

    #ifdef __SHADOW_SUPPORT_SB__
        FS_SetDiskFlag();   /* Set flag everytime */

        if (NORMAL_BOOT == stack_query_boot_mode())
        {
            nvram_shadow_construct();
            nvram_timer_init();
            FS_LockFAT(FS_LOCK_NONBLOCK_ENUM);
        }
    #elif defined(__SHADOW_SUPPORT_MS__)
        if (USBMS_BOOT == stack_query_boot_mode())
        {
            nvram_shadow_construct();
        }
    #endif 

    #ifdef __SECURITY_OTP__
        nvram_otp_construct();
    #endif
    
        nvram_config_com_port();

        nvram_ptr->state = NVRAM_STATE_READY;

    }
    else
    {
        nvram_ptr->state = NVRAM_STATE_NULL;
    }

    return KAL_TRUE;
}   /* end of nvram_init function */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_system_record
 * DESCRIPTION
 *  Read back system record.
 *  
 *  This function is supposed to be called only when:
 *  1> unformatted device.
 *  2> incompatible version.
 * PARAMETERS
 *  driver      [?]         
 *  buffer      [?]         
 *  size        [IN]        Should be NVRAM_EF_SYS_SIZE
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_read_system_record(kal_uint8 *buffer, kal_uint16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_drv_status_enum drv_status_1st, drv_status_2nd;
    kal_uint8 second_buffer[NVRAM_EF_SYS_SIZE];
    ltable_entry_struct *ldi;
    NVRAM_FILE_NAME nvramname1, nvramname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_data_item(ldi, NVRAM_EF_SYS_LID);
    kal_mem_set(&second_buffer, 0, NVRAM_EF_SYS_SIZE);
    NVRAM_MAKE_LID_FILENAME(nvramname1, ldi->fileprefix, 'a', ldi->fileverno);

    NVRAM_MAKE_LID_FILENAME(nvramname2, ldi->fileprefix, 'b', ldi->fileverno);

    /* Success!! Great!! */
    /* First copy is healthy, try to re-sync with the second copy. */
    drv_status_1st = nvram_drv_fat_read(nvramname1, 1, 1, buffer, size, ldi->attr & NVRAM_ATTR_MSP);
    if (drv_status_1st == NVRAM_DRV_OK)
    {
        /* Read second copy. */
        drv_status_2nd = nvram_drv_fat_read(nvramname2, 1, 1, second_buffer, size, ldi->attr & NVRAM_ATTR_MSP);

        /* The second copy is corrupted, sync it with this copy. */
        if ((drv_status_2nd != NVRAM_DRV_OK) || (kal_mem_cmp(buffer, second_buffer, size) != 0))
        {
            /* Second copy is empty, initialize it; though we dunno why. */
            if (drv_status_2nd == NVRAM_DRV_EMPTY_RECORD)
            {
                nvram_drv_fat_write(buffer, nvramname2, 1, size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);
            }
            /* Second copy is healthy, but not sync with first copy. */
            else
            {
                nvram_drv_fat_write(buffer, nvramname2, 1, size, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE);
            }
        }
    }
    /* First copy is corrupted, but second copy is still healthy, sync first copy with it */
    else if ((drv_status_2nd = nvram_drv_fat_read(nvramname2, 1, 1, buffer, size, ldi->attr & NVRAM_ATTR_MSP)) == NVRAM_DRV_OK)
    {
        /* First copy is empty, initialize it; though we dunno why. */
        if (drv_status_1st == NVRAM_DRV_EMPTY_RECORD)
        {
            nvram_drv_fat_write(buffer, nvramname1, 1, size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE);
        }
        else
        {
            nvram_drv_fat_write(buffer, nvramname1, 1, size, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE);
        }
    }
    /* Both copies are corrupted..sigh */
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}   /* end of nvram_init_all_ldi */


/*****************************************************************************
 * FUNCTION
 *  nvram_supplementary_check
 * DESCRIPTION
 *  do some supplementary check, such as branch or customer package
 * PARAMETERS
 *  LIDtoCheck      [IN]        Should be the record to check
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_supplementary_check(kal_uint8 LIDtoCheck)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_data_item(ldi, LIDtoCheck);
    if (ldi->total_records == 1)    /* only allow transparent EF */
    {
        kal_uint8 *buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);

        if (nvram_read_data_item(ldi, 1, 1, buffer, ldi->size) == NVRAM_IO_ERRNO_OK)
        {
            if (ldi->default_value == NULL)
            {
                return KAL_TRUE;    /* disable the check */
            }

            if (strcmp((kal_char*) buffer, (kal_char*) ldi->default_value) != 0)
            {
                return KAL_FALSE;
            }
            else
            {
                return KAL_TRUE;
            }
        }
        else
        {
            return KAL_FALSE;   /* read fail, corrupted or deleted */
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_init_all_ldi
 * DESCRIPTION
 *  Formats device by invoking drv_format() function. Re-initialize all logical data items to
 *  default value.
 *  
 *  This function is supposed to be called only when:
 *  1> unformatted device.
 *  2> system level record read error.
 *  3> incompatible version.
 * PARAMETERS
 *  reset_category          [IN]        
 *  is_after_format(?)      [IN]        Only when device is just re-formatted will this value be true.
 * RETURNS
 *  Result of writing system records. KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool nvram_init_all_ldi(nvram_reset_category_enum reset_category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool write_status = KAL_FALSE;

    ltable_entry_struct *ldi;
    NVRAM_FILE_NAME nvramname1, nvramname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean up all nvram files */
    if (reset_category == NVRAM_RESET_ALL)
    {
        /* Latch power first and show the first picture */
        DRV_POWERON();
    #if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
        MMICheckDiskDisplay();
    #endif 
        if (!(nvram_ptr->software_change_status & NVRAM_EMPTY_FAT))
        {
            nvram_delete_all_nvram_files();
        }
    }

    /* Initialize all logical data items of `reset_category' */
    nvram_get_data_item(ldi, 0);
/* __GEMINI__ */
    nvram_reset_data_items(reset_category, ldi, 0, 0);
/* __GEMINI__ */

    /* Ok, all logical data items are initialized. Now initialize system-level record */
    nvram_get_data_item(ldi, NVRAM_EF_SYS_LID);

    NVRAM_MAKE_LID_FILENAME(nvramname1, ldi->fileprefix, 'a', ldi->fileverno);

    NVRAM_MAKE_LID_FILENAME(nvramname2, ldi->fileprefix, 'b', ldi->fileverno);

    /* Redundant the system-level record */
    if (nvram_drv_fat_write((kal_uint8*) ldi->default_value, nvramname1, 1, ldi->size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE) == NVRAM_DRV_OK)
    {
        write_status = KAL_TRUE;
    }
    if (nvram_drv_fat_write((kal_uint8*) ldi->default_value, nvramname2, 1, ldi->size, ldi->attr & NVRAM_ATTR_MSP, KAL_TRUE) == NVRAM_DRV_OK)
    {
        write_status = KAL_TRUE;
    }

    ASSERT(write_status == KAL_TRUE);

    /* Fatal error. Cannot write system-level record!? */
    if (write_status == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    /* Set lock state to nvram context */
    nvram_set_lock_state((kal_uint8*) (ldi->default_value));

    return write_status;
}   /* end of nvram_init_all_ldi */


/*****************************************************************************
 * FUNCTION
 *  nvram_scan_all_ldi
 * DESCRIPTION
 *  Scan all data item and compare the files to make sure the files is vaild
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_scan_all_ldi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;
    nvram_lid_enum file_idx;
    ltable_entry_struct *ldi;
    FS_FileLocationHint Hint;
    NVRAM_FILE_NAME nvramname;
    kal_int32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must clear up Hint beforehand */
    memset(&Hint, 0, sizeof(Hint));

    for (file_idx = NVRAM_EF_SYS_LID + 1; file_idx < nvram_ptr->ltable.total_LID; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);

        NVRAM_MAKE_LID_FILENAME(
            nvramname,
            ldi->fileprefix,
            (NVRAM_IS_ATTR_MULTIPLE(ldi->attr) ? 'a' : '_'),
            ldi->fileverno);

        file_size = nvram_drv_fat_get_record_size(nvramname, &Hint);
        if ((ldi->attr & NVRAM_ATTR_MSP && file_size < 0) || /* SML default changed */
            (!(ldi->attr & NVRAM_ATTR_MSP) && file_size != ((ldi->size + sizeof(kal_uint16)) * ldi->total_records)))
        {
/* __GEMINI__ */            
            ret = nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records);
/* __GEMINI__ */

            if (ret == KAL_FALSE)
            {
                break;
            }
        }

    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_test_lock
 * DESCRIPTION
 *  get lock state from nvram context.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if locked, else KAL_FALSE
 *****************************************************************************/
kal_bool nvram_test_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_ptr->lock;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_set_lock_state
 * DESCRIPTION
 *  Set lock state to nvram context.
 * PARAMETERS
 *  coded_version       [IN]        Pointer to address of version/lock pattern.
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_set_lock_state(kal_uint8 *coded_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 *lock_pattern = coded_version + CODED_LOCK_PATTERN_OFFSET;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First, decrypt the default value to obtain current lock status */
    custom_nvram_decrypt(
        nvram_ptr->secret_key,
        lock_pattern,
        CODED_LOCK_PATTERN_SIZE,
        (nvram_ptr->coded_version[9] - '0') * 10 + (nvram_ptr->coded_version[10] - '0'));

    /* Compare the lock pattern to set current lock status */
    if (kal_mem_cmp(lock_pattern, NVRAM_LOCK_PATTERN_LOCKED, CODED_LOCK_PATTERN_SIZE) == 0)
    {
        nvram_ptr->lock = KAL_TRUE;
    }
    else
    {
        nvram_ptr->lock = KAL_FALSE;
    }

    /* Restore default value, ie, encrypt it back. */
    custom_nvram_encrypt(
        nvram_ptr->secret_key,
        lock_pattern,
        CODED_LOCK_PATTERN_SIZE,
        (nvram_ptr->coded_version[9] - '0') * 10 + (nvram_ptr->coded_version[10] - '0'));
}   /* end of nvram_get_lock_state */


/*****************************************************************************
 * FUNCTION
 *  nvram_reset
 * DESCRIPTION
 *  This is reset() function of NVRAM module.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)
    nvram_ptr->state = NVRAM_STATE_NULL;
#endif
    return KAL_TRUE;
}   /* end of nvram_reset function */


/*****************************************************************************
 * FUNCTION
 *  nvram_deinit
 * DESCRIPTION
 *  This is deinit() function of NVRAM module.
 *  This function finalize all the context variables required for NVRAM module
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool nvram_deinit(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /**
    *  Temporary Implementation here... 
    *  Should we provide a driver de-init function point in drv_func_table?
   *  Calling the Driver function directly is not a good idea...
   **/

    return KAL_TRUE;

}   /* end of nvram_init function */


/*****************************************************************************
 * FUNCTION
 *  nvram_special_service
 * DESCRIPTION
 *  This is special service function of NVRAM module.
 *  Suppose NVRAM should be a passive object, provide service for other modules' read/write require
 *  But for some special purpose (exception/statistic notification, debugging reason),
 *  it should provide some special active services as it start up. These services will be
 *  grouped in this function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_special_service(void)
{
#ifndef __PRODUCTION_RELEASE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MULTI_BOOT__
    if (NORMAL_BOOT == stack_query_boot_mode())
#endif 
    {

        nvram_notify_exception();
        nvram_notify_statistics();
    }

#endif /* __PRODUCTION_RELEASE__ */ 

#ifdef __MTK_TARGET__
    nvram_send_L1_cal();

#if defined(__WCDMA_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(__WIFI_SUPPORT__)
#if defined(__SHADOW_SUPPORT_MS__)
        if (USBMS_BOOT != stack_query_boot_mode())
        {
            nvram_send_wndrv_cal();
        }
#endif /* __SHADOW_SUPPORT_MS__ */
#endif /* __WIFI_SUPPORT__ */

    nvram_send_bmt_cal();
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  nvram_notify_exception
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __PRODUCTION_RELEASE__
static void nvram_notify_exception(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    ltable_entry_struct *ldi;
    nvram_errno_enum ret;
    EX_LOG_T *exception_ptr;
    kal_char *output_buf, *task_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    output_buf = (kal_char*) get_ctrl_buffer(128 * sizeof(kal_char));
    task_name = (kal_char*) get_ctrl_buffer(8 * sizeof(kal_char));
    exception_ptr = (EX_LOG_T*) get_ctrl_buffer(NVRAM_EF_SYS_EXCEPTION_SIZE);

    nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

    /* Get ALL Exception Records */
    for (i = 1; i <= NVRAM_EF_SYS_EXCEPTION_TOTAL; i++)
    {
        ret = nvram_read_data_item(ldi, i, 1, (kal_uint8*) exception_ptr, NVRAM_EF_SYS_EXCEPTION_SIZE);        /* multi-rec read support */
        if (((ret == NVRAM_IO_ERRNO_OK) || (ret == NVRAM_IO_ERRNO_INIT)) && (exception_ptr->header.ex_nvram != 0xFF))
        {
            last_ex_record = i;
            kal_mem_cpy(task_name, &exception_ptr->envinfo.execution_unit[0], 8);
            task_name[7] = '\0';

            sprintf(
                output_buf,
                "NVRAM: Notification!!! Pending exceptions [SN: %x] [Type: %x] [TaskName: %8s][SysTime: (%2d/%2d) %2d:%2d]\n",
                exception_ptr->header.ex_serial_num,
                exception_ptr->header.ex_type,
                task_name,
                exception_ptr->envinfo.rtc.rtc_mon,
                exception_ptr->envinfo.rtc.rtc_day,
                exception_ptr->envinfo.rtc.rtc_hour,
                exception_ptr->envinfo.rtc.rtc_min);
            /* total output string length is 105 bytes */
            kal_print(output_buf);
        }
        else
        {
            /* 1. The exception records are sequentially deployed, once ex_nvram flag is 0xFF, there should be no exception records behind */
            /* 2. If read error somehow, notify and terminate */
            if ((ret != NVRAM_IO_ERRNO_OK) && (ret != NVRAM_IO_ERRNO_INIT))
            {
                strcpy(output_buf, "NVRAM: Read exception error!");
                kal_print(output_buf);
            }
            break;
        }
    }

    free_ctrl_buffer(output_buf);
    free_ctrl_buffer(task_name);
    free_ctrl_buffer(exception_ptr);
}   /* end of nvram_notify_exception function */
#endif /* __PRODUCTION_RELEASE__ */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_report_last_exception
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_name_p     [?]     
 *  type_p          [?]     
 *  time_p          [?]     
 *  status_p        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_report_last_exception(void *task_name_p, void *type_p, void *time_p, void *status_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    nvram_errno_enum ret;
    EX_LOG_T *exception_ptr;

    kal_char *task_name = (kal_char*) task_name_p;
    exception_type *type = (exception_type*) type_p;
    ex_rtc_struct *time = (ex_rtc_struct*) time_p;
    kal_bool *status = (kal_bool*) status_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    exception_ptr = (EX_LOG_T*) get_ctrl_buffer(NVRAM_EF_SYS_EXCEPTION_SIZE);

    nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

    ret = nvram_read_data_item(ldi, last_ex_record, 1, (kal_uint8*) exception_ptr, NVRAM_EF_SYS_EXCEPTION_SIZE);       /* multi-rec read support */
    if ((last_ex_record != 0) && (ret == NVRAM_IO_ERRNO_OK))
    {
        kal_mem_cpy(task_name, &exception_ptr->envinfo.execution_unit[0], 8);
        task_name[7] = '\0';

        *type = exception_ptr->header.ex_type;
        memcpy((void*)time, (void*)&(exception_ptr->envinfo.rtc), sizeof(ex_rtc_struct));

        *status = KAL_TRUE;
    }
    else
    {
        *status = KAL_FALSE;
    }

    free_ctrl_buffer(exception_ptr);
}   /* end of nvram_notify_exception function */


/*****************************************************************************
 * FUNCTION
 *  nvram_notify_statistics
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __PRODUCTION_RELEASE__
static void nvram_notify_statistics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    nvram_errno_enum ret;
    stack_statistics_struct *stat_ptr;
    kal_char *output_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    output_buf = (kal_char*) get_ctrl_buffer(128 * sizeof(kal_char));
    stat_ptr = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);

    nvram_get_data_item(ldi, NVRAM_EF_SYS_STATISTICS_LID);

    /* Read statistaics data item */
    ret = nvram_read_data_item(ldi, 1, 1, (kal_uint8*) stat_ptr, NVRAM_EF_SYS_STATISTICS_SIZE);        /* multi-rec read support */
    if (((ret == NVRAM_IO_ERRNO_OK) || (ret == NVRAM_IO_ERRNO_INIT)) &&
        (stat_ptr->stack_stats_status == STACK_STATS_UPDATE))
    {
        sprintf(output_buf, "NVRAM: Notification!!! Statistics updated \n");
        kal_print(output_buf);
    }

    free_ctrl_buffer(output_buf);
    free_ctrl_buffer(stat_ptr);
}   /* end of nvram_notify_statistics function */
#endif /* __PRODUCTION_RELEASE__ */ 

#ifdef __MTK_TARGET__

#if defined(__WIFI_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  nvram_send_wndrv_cal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_send_wndrv_cal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     /**
      *    file_idx should be the first L1 element in the logical data item ID enum
      *    Currently, L1 calibration data element is as following:
      *    NVRAM_EF_L1_AGCPATHLOSS_LID, NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
      *    NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 
      *    NVRAM_EF_L1_AFCDATA_LID, VRAM_EF_L1_L1SPFC_LID, 
      */

    nvram_lid_enum file_idx;
    ltable_entry_struct *ldi;
    peer_buff_struct *peer_buf_ptr;
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;
    nvram_read_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

    for (file_idx = NVRAM_EF_WNDRV_START; file_idx < NVRAM_EF_WNDRV_START + NVRAM_WNDRV_CAL_ELEMENT_TOTAL; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }

        nvram_get_data_item(ldi, file_idx);

        local_data->access_id = 0;
        local_data->file_idx = (file_idx);
        local_data->para = 1;

        pdu_length = ldi->size;
        peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
        ASSERT(peer_buf_ptr != NULL);

        pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);
        ASSERT(pdu_ptr != NULL);

        nvram_read_confirm(
            MOD_WNDRV,
            nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length),
            local_data,
            ldi->size,
            peer_buf_ptr);
    }

    free_local_para((local_para_struct*) local_data);

}   /* end of nvram_send_wndrv_cal function */
#endif /* defined(__WIFI_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_send_bmt_cal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_send_bmt_cal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    peer_buff_struct *peer_buf_ptr;
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;
    nvram_read_req_struct *local_data;
    module_type dest_mod = MOD_BMT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_data_item(ldi, NVRAM_EF_ADC_LID);

    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

    local_data->access_id = 0;
    local_data->file_idx = NVRAM_EF_ADC_LID;
    local_data->para = 1;

    pdu_length = NVRAM_EF_ADC_SIZE;
    peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
    ASSERT(peer_buf_ptr != NULL);

    pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);
    ASSERT(pdu_ptr != NULL);

#ifdef __MULTI_BOOT__
    /* Factory mode */
    if (INT_BootMode() == MTK_FACTORY_MODE)
    {
        dest_mod = MOD_L1;
    }
    else
    {
        dest_mod = MOD_BMT;
    }
#endif /* __MULTI_BOOT__ */ 

    nvram_read_confirm(
        dest_mod,
        nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length),  /* multi-rec read support */
        local_data,
        ldi->size,
        peer_buf_ptr);

    free_local_para((local_para_struct*) local_data);
}
#endif /* __MTK_TARGET__ */ 

