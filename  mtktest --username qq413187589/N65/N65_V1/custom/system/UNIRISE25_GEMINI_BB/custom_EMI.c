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
 *   custom_EMI.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *   EMI auto generator V4.17
 *
 *   Memory Device database last modified on 2009/11/16
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

#define FLASHCONF_C

#ifndef FLASH_DISKDRV_DEBUG
#include "kal_release.h"
#else
#include <stdlib.h>
#endif

#include "flash_opt.h"
#include "reg_base.h"
#include "MemoryDevice_TypeDef.h"
#include "custom_MemoryDevice.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "NAND_FDM.h"
#include "custom_emi.h"

/*
 ****************************************************************************
 Essential Declarations for NOR-Flash Disk
 ****************************************************************************
*/

#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   */

#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )

/* System Drive on NAND-flash */
const kal_uint32 NFB_BASE_ADDRESS = FLASH_BASE_ADDRESS;
const kal_uint32 NFB_ALLOCATED_FAT_SPACE = ALLOCATED_FAT_SPACE;

#else/* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */

#ifndef __NOR_FDM5__

/* System Drive on NOR-flash */

#ifndef __INTEL_SIBLEY__

/* Each FAT sector is 512bytes (0x200) */
#define TOTAL_SECTORS   (ALLOCATED_FAT_SPACE/0x200)

kal_uint8 FDMBuffer[512];

FS_Driver NORFlashDriver =
{
   NOR_MountDevice,
   NOR_ShutDown,
   NOR_ReadSectors,
   NOR_WriteSectors,
   NOR_MediaChanged,
   NULL,
   NOR_GetDiskGeometry,
   NOR_LowLevelFormat,
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NULL,
#else
   NOR_NonBlockWriteSectors,
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   NOR_RecoverableWriteSectors,
   NOR_ResumeSectorStates,
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

/* Each FAT sector is 1024bytes (0x200) */
#define TOTAL_SECTORS   (ALLOCATED_FAT_SPACE/0x400)

kal_uint8 FDMBuffer[1024];

FS_Driver NORFlashDriver =
{
   SIB_MountDevice,
   NOR_ShutDown,
   SIB_ReadSectors,
   SIB_WriteSectors,
   NOR_MediaChanged,
   NULL,
   SIB_GetDiskGeometry,
   SIB_LowLevelFormat,
   SIB_NonBlockWriteSectors,
   SIB_RecoverableWriteSectors,
   SIB_ResumeSectorStates,
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

#endif /* __INTEL_SIBLEY__ */

static WORD AVAILSECTORS[TOTAL_BLOCKS];
static WORD VALIDSECTORS[TOTAL_BLOCKS];
static BYTE SectorMap[TOTAL_SECTORS];
NOR_FLASH_DRV_Data  FlashDriveData;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
//static kal_uint32 EraseQueue[TOTAL_BLOCKS];
static NOR_EraseInfo EraseBlockQueue[SNOR_ERASE_QUEUE_SIZE];
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

extern NOR_MTD_Driver NORFlashMtd;

#ifdef __MTK_TARGET__

static NOR_Flash_MTD_Data mtdflash;
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

#else

static NOR_Flash_MTD_Data mtdflash =
{
   MakeMtdFlashData((BYTE *)FLASH_BASE_ADDRESS, RegionInfo)
};

#endif /* __MTK_TARGET__ */

#endif /*__NOR_FDM5__*/
#endif /* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */

#ifdef PARTITION_SIZE

 #if (PARTITION_SIZE > 0 && PARTITION_SIZE < NAND_MINIMUM_PARTITION_SIZE)
  #error " PARTITION_SIZE MUST be larger than NAND_MINIMUM_PARTITION_SIZE !!"
 #endif

 #if (defined(_NAND_FLASH_BOOTING_))
  #if ( (PARTITION_SIZE << 9) > ALLOCATED_FAT_SPACE)
   #error " PARTITION_SIZE MUST be less than ALLOCATED_FAT_SPACE !!"
  #endif
 #endif /* _NAND_FLASH_BOOTING_ */

#endif /* PARTITION_SIZE */

kal_uint32 custom_part_secs = PARTITION_SIZE;
NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif /* !__UBL__ && !__FUE__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_setEMI(void)
{
#if (defined(MT6225) || defined(MT6227D) || defined(MT6226D) || defined(MT6223) || defined(MT6223P)) && !defined(ADMUX_MCP)
   *(volatile kal_uint32 *)(0x80010078) = 0;
#endif

   if ( EMI_CSConfiguration[0] != UNUSED )
         *(EMI_CONA) = EMI_SettingOnCS[0];

   if ( EMI_CSConfiguration[1] != UNUSED )
         *(EMI_CONB) = EMI_SettingOnCS[1];

   if ( EMI_CSConfiguration[2] != UNUSED )
         *(EMI_CONC) = EMI_SettingOnCS[2];

   if ( EMI_CSConfiguration[3] != UNUSED )
         *(EMI_COND) = EMI_SettingOnCS[3];

   /* Setting EMI general control register and cache/prefetch size if necessary */
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )

   *EMI_GENA = EMI_GENERAL_CONTROL_0;
   *EMI_GENB = EMI_GENERAL_CONTROL_1;

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   *EMI_GENC = EMI_GENERAL_CONTROL_2;
#endif /* MT6229, MT6230, MT6268T */

#elif ( defined(MT6205B) || defined(MT6208) )

   *EMI_GEN = EMI_GENERAL_CONTROL;

#else

   *EMI_GEN = EMI_GENERAL_CONTROL;
   *PREFETCH_CON = EMI_CACHE_PREFETCH;

#endif

   return 0;

}

/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_InitDRAM(void)
{

   return -1;
}

#if ( !defined(__UBL__) && !defined(__FUE__) )

#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  custom_setAdvEMI()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_setAdvEMI(void)
{
   kal_int8    status = 0;

   return status;
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_size()
*
* DESCRIPTION
*  Return predefined external SRAM size.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_get_EXTSRAM_size(kal_uint32 *size)
{
   *size = (kal_uint32)EMI_EXTSRAM_SIZE;
}

/*************************************************************************
* FUNCTION
*  custom_ifLPSDRAM()
*
* DESCRIPTION
*  Query if the memory device is LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The memory device is LPSDRAM
*  KAL_FALSE: The memory device is not LPSDRAM
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom_ifLPSDRAM(void)
{
#if defined(DRAM_CS) && defined(DRAM_SIZE)
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif      
}

/*************************************************************************
* FUNCTION
*  custom_get_NORFLASH_ROMSpace()
*
* DESCRIPTION
*  Query the of space configured for NORFLASH ROM
*
* PARAMETERS
*
* RETURNS
*  BASE ADDRESS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32
custom_get_NORFLASH_ROMSpace(void)
{
#if   defined(_NAND_FLASH_BOOTING_)
   return 0;
#elif defined(__FS_SYSDRV_ON_NAND__)
   return FLASH_BASE_ADDRESS + ALLOCATED_FAT_SPACE;
#else
   return FLASH_BASE_ADDRESS;
#endif
}

/*************************************************************************
* FUNCTION
*  Initialize_FDD_tables
*
* DESCRIPTION
*  Initialize important information for NOR-flash disk
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
extern kal_uint32 NOR_Flash_Base_Address;
#if defined(MT6205B)
extern NOR_AddrLookup addr_lookup_tbl[][];
#endif
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#ifndef __NOR_FDM5__
void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

   /* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)RegionInfo);

#ifdef __MTK_TARGET__
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_Flash_Base_Address =INT_RetrieveFlashBaseAddr();
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + FLASH_BASE_ADDRESS);
#endif /* __MTK_TARGET__ */

   mtdflash.RegionInfo = (FlashRegionInfo *)RegionInfo;
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   mtdflash.BankInfo = (FlashBankInfo*)BankInfo;
#endif

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.AvailSectorsInBlock = AVAILSECTORS;
   FlashDriveData.ValidSectorsInBlock = VALIDSECTORS;
   FlashDriveData.SectorMap = (BYTE*)SectorMap;
   FlashDriveData.PartitionSectors = PARTITION_SECTORS;
   FlashDriveData.Buffer = FDMBuffer;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FlashDriveData.queueSize = SNOR_ERASE_QUEUE_SIZE;
   FlashDriveData.EraseQueue = EraseBlockQueue;
   /* align page buffer size for iteration */
   #if defined(__PAGE_BUFFER_PROGRAM__)
   PAGE_BUFFER_SIZE = BUFFER_PROGRAM_ITERATION_LENGTH;
   #endif /* __PAGE_BUFFER_PROGRAM__ */
   /* initialize address look up table */
   #if defined(MT6205B)
   memset(addr_lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #else /* MT6205B */
   memset(mtdflash.lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #endif /* MT6205B */
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}
#endif /*__NOR_FDM5__*/


void nor_sweep_device(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_DMAN_EVENT, KAL_OR);
#endif
   return;
}

void nor_manual_reclaim(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_BRECL_EVENT, KAL_OR);
#endif
   return;
}
#endif /* !__UBL__ && !__FUE__ */

