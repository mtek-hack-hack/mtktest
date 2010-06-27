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
 *   custom_nor_large_disk.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   defines prototypes and data structure which will be used in NOR FDM 5.0
 *
 * Author:
 * -------
 *   Yoda Chen (mtk01178)     system auto generator V0.30
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

#include "custom_MemoryDevice.h"
#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "flash_opt.h"

#ifdef __NOR_FDM5__

#define STORAGE_NO_PARTITION 0xFFFFFFFF

/*****************************************
 * Don't modify any code above this line *
 *****************************************/

/*******************************************************************************
   Follow the 6 steps below to configure flash memory for FAT
   
   Step 1. Modify the value of FLASH_BASE_ADDRESS, which is the starting address
           of the flash memory allocated for FAT

   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
           
   Step 3. Modify the value of Block size 
           
   Step 4. Fill the flash bank (partition) information table,
           flash device features flexible, multi-bank read-while-program and 
           read-while-erase capability, enabling background programming or erasing in 
           one bank simultaneously with code execution or data reads in another bank.
           Each element in the table is the format as below:
           {bank size, bank number},   
                          
   Step 5. Modify the value of LSMT, you can see MemoryDevice_FlashDisk_FAQ for 
           detail information
      
   Step 6: Define the toal sectors (512bytes) of system drive
           the remainder is the size of public drive
           If there is no partiton (just one drive, system drive)
           set this value to STORAGE_NO_PARTITION (0xFFFFFFFF) 
 
           
   Note : Code region and FAT region can not share the same bank (partition)
*******************************************************************************/



/***********
 * Step 1. *
 ***********/
#define FLASH_BASE_ADDRESS x

/***********
 * Step 2. *
 ***********/
#define ALLOCATED_FAT_SPACE x

/***********
 * Step 3. *
 ***********/
#define NOR_BLOCK_SIZE x

/***********
 * Step 4. *
 ***********/
static NORBankInfo BankInfo[] =
{
   {x,x},
   EndBankInfo /* Don't modify this line */
};

/***********
 * Step 5. *
 ***********/
#define NOR_TOTAL_LSMT x

/***********
 * Step 6. *
 ***********/
#define NOR_SYSDRV_SECTORS x


/*****************************************
 * Don't modify any code below this line *
 *****************************************/

#define NOR_TOTAL_BLOCKS (ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)
#define NOR_TOTAL_TABLE_BLOCKS 32
NOR_FTL_DATA  FlashDriveData;
static NORLayoutInfo LayoutInfo;

#ifndef __INTEL_SIBLEY__

#define NOR_PAGE_SIZE 512

FS_Driver NORFlashDriver = {
   nNOR_MountDevice,
   nShutDown,
   nNOR_ReadSectors,
   nNOR_WriteSectors,
   NOR_MediaChanged,
   nNOR_DiscardSectors,
   nGetDiskGeometry,
   nNOR_LowLevelFormat,
   nNOR_NonBlockWriteSectors,
   nNOR_RecoverableWriteSectors,
   nNOR_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};
   
#else

#define NOR_PAGE_SIZE 1024

FS_Driver NORFlashDriver = {
   nSIB_MountDevice,
   nShutDown,
   nSIB_ReadSectors,
   nSIB_WriteSectors,
   NOR_MediaChanged,
   nSIB_DiscardSectors,
   nGetDiskGeometry,
   nSIB_LowLevelFormat,
   nSIB_NonBlockWriteSectors,
   nSIB_RecoverableWriteSectors,
   nSIB_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};
#endif /*__INTEL_SIBLEY__*/


static kal_uint16  NOR_LBM[NOR_TOTAL_BLOCKS];
static LSMGEntry   NOR_LSMG[NOR_TOTAL_LSMT]; // need to check in the program
static kal_uint16  NOR_AvailInBlk[NOR_TOTAL_BLOCKS];
static kal_uint16  NOR_InvaildInBlk[NOR_TOTAL_BLOCKS];
static kal_uint32  NOR_InvalidEntryInTblBlk[NOR_TOTAL_TABLE_BLOCKS];
static kal_uint8 FDMBuffer[NOR_PAGE_SIZE];
static kal_uint8 CopyBuffer[NOR_PAGE_SIZE];
static NOR_MTD_DATA mtdflash;
kal_eventgrpid  nor_egid = NULL;

extern NOR_MTD_Driver NORFlashMtd;
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);



void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )
   	/* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)&LayoutInfo);

#ifdef __MTK_TARGET__
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + FLASH_BASE_ADDRESS);
#endif
   LayoutInfo.BankInfo = BankInfo;
   LayoutInfo.TotalBlks = NOR_TOTAL_BLOCKS;
   LayoutInfo.BlkSize = NOR_BLOCK_SIZE;
   LayoutInfo.PageSize = NOR_PAGE_SIZE;
   LayoutInfo.TotalLSMT= NOR_TOTAL_LSMT;
   mtdflash.LayoutInfo = (NORLayoutInfo *)&LayoutInfo;

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.LBM = NOR_LBM;
   FlashDriveData.LSMG = NOR_LSMG;
   FlashDriveData.AvailInBlk = NOR_AvailInBlk;
   FlashDriveData.InvalidInBlk = NOR_InvaildInBlk;
   FlashDriveData.InvalidEntryInTblBlk = NOR_InvalidEntryInTblBlk;
   FlashDriveData.SecondPartitionSectors = NOR_SYSDRV_SECTORS;
   FlashDriveData.SetTblBlks = NOR_TOTAL_TABLE_BLOCKS;
   FlashDriveData.Buffer = FDMBuffer;
   FlashDriveData.CopyBuffer = CopyBuffer;
#ifndef __INTEL_SIBLEY__
   FlashDriveData.ReclaimBlock = nNOR_ReclaimBlock;
#else
   FlashDriveData.ReclaimBlock = nSIB_ReclaimBlock;
#endif /* __INTEL_SIBLEY__ */
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#endif /*__NOR_FDM5__*/
