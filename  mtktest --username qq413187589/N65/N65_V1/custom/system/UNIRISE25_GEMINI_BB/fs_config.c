/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   fs_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines all resource setting in file system
 *
 * Author:
 * -------
 *   system auto generator V0.30
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _KAL_RELEASE_H
#include "kal_release.h"
#endif

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

   /* IMPORT DEVICE DRIVER and DRIVER DATA */
#include "drvflash.h"
extern NOR_FLASH_DRV_Data  FlashDriveData;
extern FS_Driver NORFlashDriver;

#ifdef NAND_SUPPORT
#include "NAND_FDM.h"
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
extern FS_Driver NANDFlashDriver;
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
#include "msdc_def.h"
extern FS_Driver FS_MsDrv;
extern FS_Driver FS_SdDrv;
extern FS_Driver FS_MspDrvAll;
extern FS_Driver FS_SdDrv2;
#endif

#ifdef __OTG_ENABLE__
#include "usb_host_ms_adap.h"
extern kal_uint8 USBHost_Media_Handle[];
extern FS_Driver FS_OTGDrv;
#endif

   /* EXTRA DRIVE/FILEHANDLE NUM Declaration */
#ifdef __OTG_ENABLE__

#ifdef __SIM_PLUS__
#define EXTRA_DRIVE_NUM (4 + 1)
#else
#define EXTRA_DRIVE_NUM (4)
#endif

#else /* __OTG_ENABLE__ */

#ifdef __SIM_PLUS__
#define EXTRA_DRIVE_NUM (1)
#else
#define EXTRA_DRIVE_NUM (0)
#endif

#endif /* __OTG_ENABLE__ */

#ifdef __J2ME__
#include "j2me_custom.h"
#if (defined(J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT))
#define EXTRA_FH_NUM    (J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT)
#else
#define EXTRA_FH_NUM	(0)
#endif
#else /* __J2ME__ */
#define EXTRA_FH_NUM	(0)
#endif /* __J2ME__ */

/************************ User Configuration ************************/
/* The nubmer of drive in file system: EXTERNAL_DRIVE_NUM + X; 1 <= X <= 5 */ 
//Each one of the defined device (NOR, NAND, Card, External) should has at least one drive.
//If partition is applied on the device, one more drive should be allocated.
//EXTERNAL_DRIVE_NUM: number of drive for USB OTG External, don't remove
const UINT FS_MAX_DRIVES = EXTRA_DRIVE_NUM + 3;

/* The number of buffer in file system:  X >= 1 */
const UINT FS_MAX_BUFFERS = 16;

/* The number of file handle in file system: EXTRA_FH_NUM + X;
 * EXTRA_FH_NUM: number of file handle for downloadable application, don't remove
 * X >=  4 #if GSM
 * X >= 16 #if GPRS
 * Recommend Value For General Case: 24  # modify this value to best fit your case
 *
 *      24 =  9 (foreground app.) + 12 (basic background app. worst case) + 3 (optional)
 * 
 * Table of Background File Handle Usage by optional application/feature
 * { 4,  BlueTooth FTP + OPP profile },
 * { 1,  IRDA Support                },
 * { 1,  DT Support (Phone Suite)    },
 * { 2,  IMPS                        },
 * { 1,  EMail                       },
 * { 1,  POC                         },
 * { 1,  SIP                         },
 */
const UINT FS_MAX_FILES = EXTRA_FH_NUM + 24;

/* The number of tasks that will use file system: X >=  5 #if GSM
 *                                                X >= 10 #if GPRS
 * Default Value: 22 (GPRS), 26 (EDGE)
 * Common {NVRAM, MMI, MED, FMT, WAP, WPS, L4, L1AUDIO}
 * Discount 1 per feature OFF to optimize
 * {BLUETOOTH, DT, EMAIL, GDC, GDD, IMPS, JAVA, POC, SIP, XDM}
 * {VOIP, DHCP, TFTP, SAF, SUPC, RTSP, DM, DRMT}
 */
const UINT FS_MAX_THREAD = 22;

/* The max number of continuous cluster for copy iteration
 *
 * Default value: 128 , 32 (MT6223P)
 */
#if defined(MT6223P)
const UINT FS_MAX_COPY_CLUSTER =  32;
#else /* MT6223P */
const UINT FS_MAX_COPY_CLUSTER = 128;
#endif /* MT6223P */

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

#ifdef _NAND_FLASH_BOOTING_
/* The size of sanity check buffer in byte */
/* It's for system drive on NAND flash booting type project */
/* If the size is not big enough, it will assert when booting up */
const UINT FS_MAX_CHECK_BUFFER = 5*1024;
#else
const UINT FS_MAX_CHECK_BUFFER = 4;
#endif

/* Device List Configuration */
FS_Device gFS_DeviceList[] = {
#ifndef _NAND_FLASH_BOOTING_
	{FS_DEVICE_FDISK, 0, FS_DEVICE_NOR_FLASH, &NORFlashDriver, (void *)&FlashDriveData, NULL},
#endif

#ifdef NAND_SUPPORT
	{FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&NANDFlashDriveData, NULL},
#endif

#ifdef __MSDC_MS__
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_MsDrv, (void *)&gMSDC_Handle, NULL},
#elif (defined __MSDC_SD_MMC__)
	#if defined(__SIM_PLUS__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[SD_EXT], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_SIMPLUS  , &FS_SdDrv, (void *)&MSDC_Blk[SD_SIM], NULL},
        #elif defined(__MSDC2_SD_MMC__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv , (void *)&MSDC_Blk[0], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv2, (void *)&MSDC_Blk[1], NULL},
	#else
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[0], NULL},	
	#endif		
#elif (defined __MSDC_MSPRO__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_CHECK_PART
                           | FS_DEVICE_MEMORY_STICK, &FS_MspDrvAll, (void *)&gMSDC_Handle, NULL},
#endif 
#ifdef __OTG_ENABLE__
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[0], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[1], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[2], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[3], NULL},
#endif
   { 0, 0, 0, 0, 0, 0 }    // end of list marker
};

/************* Do not modify anything behind this line *************/
FS_Drive          gFS_DriveTable[FS_MAX_DRIVES];
FS_File           gFS_FileTable[FS_MAX_FILES];
FS_Buffer         gFS_BufferTable[FS_MAX_BUFFERS];
BYTE              gFS_BufferData[FS_MAX_BUFFERS * FS_BUFFER_SIZE];
kal_taskid        gFS_TaskList[FS_MAX_THREAD];
FS_ExceptionData* gFS_TaskData[FS_MAX_THREAD][MAX_TLS_INDEX];

#ifdef __FS_TRACE_SUPPORT__
kal_bool          gFS_TraceTask[FS_MAX_THREAD][FS_TRACE_INDEX] = {KAL_FALSE, KAL_FALSE};
#endif

BYTE              gFS_SanityCheckBuffer[FS_MAX_CHECK_BUFFER];
const int         gFS_DeviceNumOfSYSDRV = 1;

FS_Tables gFS_Data  = 
{ 
   gFS_DriveTable,
   gFS_FileTable,
   gFS_BufferTable,
   gFS_BufferData 
};

