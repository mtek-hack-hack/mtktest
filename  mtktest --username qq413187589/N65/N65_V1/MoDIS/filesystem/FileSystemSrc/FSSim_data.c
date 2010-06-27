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
 *  FSSim_data.c
 *
 * Project:
 * --------
 *  FSSIM
 *
 * Description:
 * ------------
 *  This file defines global variables of File System Simulation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define UNICODE 

#include <windows.h>

#ifndef MMI_ON_WIN32
#include "kal_release.h"
#endif

#include "fs_type.h"
#include "fat_fs.h"

#include "FSSim_def.h"
/*
 * Array of file handles.
 */
TCHAR fssim_root_dir[MAX_PATH * 2];

/*
 * Array of file handles.
 */
FSSIM_FILE_T fssim_file[FSSIM_MAX_FILE + 1];

/*
 * Global mutex.
 */
void *fssim_mutex;
void *fssim_sort_mutex;
void *fssim_disk_space_mutex;

/*
 * Array of drives' information.
 */
FSSIM_DRVINFO_T fssim_drvinfo[FSSIM_MAX_DRIVE] =
{   /* SAMPLE Line
	 * { DriveLetter, , , DEVICE_TYPE , SectorSize(512), SectorsPerCluster(4), TotalClusters = Disk Size, , }
	 */
    {FSSIM_SYSTEM_DRIVE, 0, 1, FS_DEVICE_TYPE_NOR, FSSIM_BYTES_PER_SECTOR, FSSIM_SECTORS_PER_CLUSER, 1077, 0, 0},
    {FSSIM_SYSTEM_DRIVE + 1, 0, 0, FS_DEVICE_TYPE_NAND, FSSIM_BYTES_PER_SECTOR, FSSIM_SECTORS_PER_CLUSER, 67890, 0, 0},
    {FSSIM_SYSTEM_DRIVE + 2, 0, 0, FS_DEVICE_TYPE_CARD, FSSIM_BYTES_PER_SECTOR, FSSIM_SECTORS_PER_CLUSER, 67890, 0, 0}
};

/*
 * Array of drives' information.
 */
const FSSIM_HW_DEVICE_STRUCT_T fssim_device[FSSIM_MAX_DRIVE + 1] =
{   {0,0},
    {1,0}, /* FS_DEVICE_TYPE_NOR */
    {1,0}, /* FS_DEVICE_TYPE_NAND*/
    {1,0}  /* FS_DEVICE_TYPE_CARD*/
};

/*
 * Array of FSSIM_SORT_T.
 */
FSSIM_SORT_T fssim_sort[MT_MAX_FILE_NUM];

/*
 * Count of items in fssim_sort[].
 */
int fssim_sort_cnt;

/*
 * Array of FS_PartitionInfo.
 */
const FS_PartitionRecord fssim_partition[FSSIM_MAX_DRIVE] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/*
 * Drive mapping data structure.
 */
FSSIM_DRVMAP_T fssim_drvmap;

/*
 * Virtual File Name Generate and Register Table 
 */
FSSIM_VFTABLE_T fssim_vfgen; 

/*
 * Virtual File Name Prefix
 */
const TCHAR fssim_vfname_prefix[] = L"\\\\.\\FMapF\\";

/*
 * NVRAM Folder Name to ByPass QuotaMgt
 */
const TCHAR fssim_nvram_path[] = L"Z:\\@NVRAM\\";

/*
 * Qutoa Management Feature
 *      COPY quota setting 
 */
/************************ User Configuration ************************/
//Set your entry below
//Max quota set entry number is 40
FS_QuotaStruct gFS_ExtQuotaSet[] =
{
   {"Z:\\@Java\\", FS_QP_HIG_ENUM, 200*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

   {"Z:\\@USER\\", FS_QP_HIG_ENUM,  20*1024,  30 * 1024      , FS_COUNT_IN_BYTE},

   {"\0", 0, 0, 0, 0} //Entry for End
};

/************* Do not modify anything behind this line *************/
const UINT FS_MAX_QSET = ((sizeof(gFS_ExtQuotaSet)/sizeof(FS_QuotaStruct)) - 1);
#define FSSIM_DATA_MAX_QSET (2+1)
FS_InternQStruct gFS_IntQuotaSet[FSSIM_DATA_MAX_QSET]; //each entry size is 12 bytes
#undef UNICODE

