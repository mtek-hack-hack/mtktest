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
 *  FSSim_def.h
 *
 * Project:
 * --------
 *  FSSIM
 *
 * Description:
 * ------------
 *  This file defines type, data structure, constant of File System Simulation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __FSSIM_DEF_H
#define __FSSIM_DEF_H

#ifndef _WINDOWS_
#error "windows.h must be included before FSSim_def.h"
#endif

#ifndef UNICODE
#error "UNICODE must be defined"
#endif

/* SECTION FOR Environment Switch
 * NOTE: MoDIS will *NOT* define __MTK_TARGET__ global option.
 */
#if defined(__MTK_TARGET__)
#error "__MTK_TARGET__ defined, wrong environment!"
#endif 

/*
 * Constant defitions
 */

/* max number of file handles */
#define FSSIM_MAX_FILE 16

/* number of NOR flash */
#define FSSIM_NORFLASH_CNT 1

/* number of NAND flash */
#define FSSIM_NANDFLASH_CNT 1

/* number of Memory Card */
#define FSSIM_MEMCARD_CNT 1

/* max number of drives */
#define FSSIM_MAX_DRIVE 3

/* bytes per sector */
#define FSSIM_BYTES_PER_SECTOR 512

/* sectors per cluster */
#define FSSIM_SECTORS_PER_CLUSER 4

/* Determine Local Path to be mapped as File System Simulator pre-fix path */

/* WAY 1 -------- Relative to Execution Binary  (Recommanded and Offical) */
#define FSSIM_RELATIVE_PATH_FOR_ROOT_DIR  L"..\\..\\WIN32FS\\"

/* WAY 2 -------- Proper Setting on INI file */
#define FSSIM_INI_FILENAME  L"MoDIS.ini"
#define FSSIM_INI_SECTION   L"FileSystem"
#define FSSIM_INI_KEY       L"Local_Map_Path"

/* directory names to simulate drives (C:\ = DRIVE_C\, D:\ = DRIVE_D\ */
#define FSSIM_DRIVE_DIR L"DRIVE_X\\"

#define FSSIM_DRIVE_DIR_PREFIX L"DRIVE_"

/* system drive name */
#define FSSIM_SYSTEM_DRIVE L'C'

/* system remapped drive name */
#define FSSIM_REMAP_SYSTEM_DRIVE L'Z'

/* the format of drive name specified in FS_GeneralFormat */
#define FSSIM_DRIVE_FORMAT L"\\\\.\\"

typedef enum { STATE_FREE = 0, STATE_INUSE = 1 };

#define FSSIM_BUFF_SIZE 512

#define FSSIM_BEFORE_RECURSIVE 1

#define FSSIM_AFTER_RECURSIVE 2

#define MT_MAX_FILE_NUM 256

#define FSSIM_SFN_LEN (8 + 3 + 1 + 1)

/* default value returned by FS_QmGetFree */
#define FSSIM_QUOTA_SIZE (10 * 1024 * 1024)

#define FSSIM_VFN_SIZE_IN_WCHAR  (FS_GenVFN_SIZE / sizeof(TCHAR))

/*
 * Macro definitions
 */
#if defined(MMI_ON_WIN32)

#define fssim_printf PRINT_INFORMATION

#else   /* MMI_ON_WIN32 */

#define fssim_printf(s) printf s

#endif  /* MMI_ON_WIN32 */

/*
 * Type definitions
 */

typedef struct FSSIM_FILE_STRUCT
{
    HANDLE handle;
    DWORD flags;
    void *taskid;
    unsigned int   unique;
    unsigned short state;
    unsigned short isabort; /* 1: abort; 0: not abort */
    union {
        int (*copy_progress)(int Action, UINT Total, UINT Completed, UINT Info);
        void (*format_progress)(const char *DriveName, int Action, UINT Total, UINT Completed);
    } progress;
    unsigned short findattr1;
    unsigned short findattr2;
    unsigned int drive; /* index of fssim_drvinfo of locating drive */
    FS_DOSDirEntry DirEntry;
    TCHAR filename[MAX_PATH];
} FSSIM_FILE_T;

#define copyprogress progress.copy_progress
#define formatprogress progress.format_progress

typedef struct FSSIM_DRVINFO_STRUCT
{
    TCHAR drive;    /* drive name (single character) */
    TCHAR remap_drive;  /* remapped drive name */
    unsigned int is_current;
    unsigned int dev;
    unsigned int bytespersector;
    unsigned int sectorspercluser;
    unsigned int totalclusters; /* assign value for disk total space */
    unsigned int takenclusters; /* don't assign value, for pseudo disk free space */
    TCHAR dir_name[MAX_PATH];   /* the current directory in the drive (Real Path) */
} FSSIM_DRVINFO_T;

typedef struct FSSIM_COPYDIR_PARAM_STRUCT
{
    TCHAR path[MAX_PATH];
    DWORD total;
    DWORD completed;
    int fh;    /* file handle */
} FSSIM_COPYDIR_PARAM_T;

typedef struct FSSIM_SORT_STRUCT
{
    TCHAR filename[MAX_PATH];
    FS_DOSDirEntry fileinfo;
} FSSIM_SORT_T;

typedef struct FSSIM_DRVMAP_STRCUT
{
    TCHAR original;
    TCHAR mapped;
} FSSIM_DRVMAP_T;

typedef struct FSSIM_FORMAT_PARAM_STRUCT
{
    TCHAR *drive;
    DWORD total;
    DWORD completed;
    int level;
    int fh;
} FSSIM_FORMAT_PARAM_T;

typedef struct FSSIM_SUM_SIZE_PARAM_STRUCT
{
    struct FSSIM_SUM_SIZE_PARAM_STRUCT *next;
    unsigned int directory_entry_cnt;
    unsigned int allocated_cluster_cnt;
    unsigned int size_of_cluster_unit;
} FSSIM_SUM_SIZE_PARAM_T;

typedef struct FSSIM_HW_DEVICE_STRUCT
{   
    unsigned int mount_state;
    unsigned int busy_status;
} FSSIM_HW_DEVICE_STRUCT_T;

typedef struct FSSIM_VIRTUAL_FILENAME_STRUCT
{
    TCHAR name_once[FSSIM_VFN_SIZE_IN_WCHAR];
    unsigned int vf_size;
    unsigned int vf_offset;
    unsigned int vf_gen_fh_unique;
} FSSIM_VIRTUAL_FILENAME_T;

typedef struct FSSIM_VFTABLE_STRUCT
{   unsigned int allocat_size;
    unsigned int usage_size;
    FSSIM_VIRTUAL_FILENAME_T *data;
    unsigned int link[FSSIM_MAX_FILE+1];
    unsigned int pos[FSSIM_MAX_FILE+1];
    unsigned int bias[FSSIM_MAX_FILE+1];
    unsigned int link_unique[FSSIM_MAX_FILE+1];
} FSSIM_VFTABLE_T;

typedef int (*fssim_search_callbak)(TCHAR *fullname, TCHAR *filename, void *param, int order);

/*
 * Declaration of exported global variables. ATTRIBUTE --- build-time , run-time constant
 */
extern TCHAR fssim_root_dir[];

extern void *fssim_mutex;
extern void *fssim_sort_mutex;
extern void *fssim_disk_space_mutex;

extern const TCHAR fssim_vfname_prefix[];
extern const TCHAR fssim_nvram_path[];

extern FS_QuotaStruct gFS_ExtQuotaSet[];
extern const UINT FS_MAX_QSET;

extern const FS_PartitionRecord fssim_partition[];
extern const FSSIM_HW_DEVICE_STRUCT_T fssim_device[];

/*
 * Declaration of exported global variables. ATTRIBUTE --- run-time update frequently
 */
extern FSSIM_FILE_T fssim_file[];
extern FSSIM_VFTABLE_T fssim_vfgen;

extern FSSIM_DRVMAP_T fssim_drvmap;
extern FSSIM_DRVINFO_T fssim_drvinfo[];
extern FS_InternQStruct gFS_IntQuotaSet[];

extern FSSIM_SORT_T fssim_sort[];
extern int fssim_sort_cnt;

/*
 * Declaration of internal functions.
 */
void *fssim_create_mutex();
void fssim_take_mutex(void *mutex);
void fssim_give_mutex(void *mutex);
void *fssim_get_task_self_id();
void fssim_print_str(const TCHAR *str);

#endif  /* __FSSIM_DEF_H */


