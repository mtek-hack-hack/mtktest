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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  FlashConf.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to configure flash device for FAT.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRVFLASH_H
#define DRVFLASH_H

#ifdef FLASH_DISKDRV_DEBUG
#define ONE_BYTE_ALIGN_ADS
#endif

// MTD driver
#define REGION_NUM 8
#define NON_BLOCK_STATUS  (0x8) //4 bit pattern for version check

//FOR FDM5
#define INVALID_BLOCK_ID 0xffff
#define INVALID_TABLE_ID 0xffff
#define INVALID_LOGICAL_NUM 0xffffff
#define INVALID_NOR_ADDR 0xffffffff
#define INVALID_PHY_PAGE 0xffffffff
#define INVALID_ENTRY 0xffff

//FOR FDM4
#define INVALID_BLOCK_INDEX   0xFFFFFFFF
#define INVALID_SECTOR_INDEX  0xFFFFFFFF
#define INVALID_ERASE_COUNT   0x00FFFFFF // we only have 24 bits
#define MAX_ERASE_COUNT       (INVALID_ERASE_COUNT-1)

/* Global defines */
#define SPARE_RESERVED_RATIO    (10)
#define MINIMUM_SPARE_AMOUNT    (2)
#define SLEEP_MODE_SPARE_AMOUNT (4)
#define GC_THRESHOLD_DIVISION   (3)
#define GC_THRESHOLD_GAP        (1)

/******** RESULT for Single Bank ************/
#define RESULT_FLASH_DONE (1)
#define RESULT_FLASH_BUSY (0)
#define RESULT_FLASH_FAIL (-1)

#ifndef __MTK_TARGET__
#pragma pack(1)
#endif
typedef ONE_BYTE_ALIGN_ADS struct {
   DWORD TotalBlocks;
   DWORD BlockSize[REGION_NUM];
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   DWORD AvailInRegion[REGION_NUM]; /*empty and the number of blocks in erase queue*/
#endif
   UINT  RegionBlocks[REGION_NUM];
   UINT  ActualRegionNum;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   WORD  PageSize;
#endif
} NOR_MTD_FlashInfo;
#ifndef __MTK_TARGET__
#pragma pack()
#endif

/* add ONE_BYTE_ALIGN_ADS keyword to this struct so that it won't violate ARM's ADS compiler rule. 
 * No need, since this structure is included into another ONE_BYTE_ALIGN_ADS structure in pointer form
 */
typedef struct {
   int     (* MountDevice)  (void * DriveData, void * Info);
   int     (* ShutDown)     (void * DriveData);
   void *  (* MapWindow)    (void * DriveData, DWORD BlockIndex, DWORD WindowIndex);
   int     (* EraseBlock)   (void * DriveData, DWORD BlockIndex);
   int     (* ProgramData)  (void * DriveData, void * Address, void * Data, UINT Length);
   int     (*NonBlockEraseBlock) (void * DriveData, DWORD  BlockIndex); /* Added by Eric */
   int     (*CheckDeviceReady)   (void * DriveData, DWORD BlockIndex); /* Added by Eric */
   int     (*SuspendErase)       (void * DriveData, DWORD BlockIndex); /* Added by Eric */
   int     (*ResumeErase)        (void * DriveData, DWORD BlockIndex); /* Added by Eric */
   int     (*BlankCheck)             (void * DriveData, DWORD BlockIndex);
   int     (*OTPAccess)           (void * DriveData, int accesstype, UINT Offset, void * BufferPtr, UINT Length);
   int     (*OTPQueryLength)      (void * DriveData, UINT *Length);
   int     (*LockEraseBlkAddr)         (void * DriveData, void *Address,UINT Action);
   kal_bool (*IsEraseSuspended)     (void * DriveData, DWORD BlockIndex);
} NOR_MTD_Driver;

/*LockEraseBlkAddr Action*/
#define ACTION_UNLOCK 0
#define ACTION_LOCK 1
#define ACTION_ERASE 2


// This is the file MTD for testing only

typedef struct {
   const  char * FileName;
   DWORD  FileSize;
   DWORD  BlockSize;
   DWORD  WindowSize;
   HANDLE H;
   BYTE * BaseAddr;
   void * CurrAddr;
} NORMtdFileData;


// Flash Info
typedef struct {
   DWORD BlockSize;
   DWORD RegionBlocks;
} FlashRegionInfo;
#define EndRegionInfo  {0, 0}

typedef struct {
   DWORD BankSize;
   DWORD Banks;
} FlashBankInfo;
#define EndBankInfo  {0, 0}

// Erase block Info
/* add ONE_BYTE_ALIGN_ADS keyword to this struct so that it won't violate ARM's ADS compiler rule. 
 * No need, since this structure is included into another ONE_BYTE_ALIGN_ADS structure in pointer form
 */
typedef struct {
   DWORD BlockIndex;
   DWORD EraseCount;
} NOR_EraseInfo;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
// address look up buffer
#define LOOKUP_TABLE_SIZE  (8)
typedef struct {
   DWORD BlockIndex;
   DWORD BaseAddress;
} NOR_AddrLookup;
#endif

typedef struct {
   DWORD  Signature;
   BYTE * BaseAddr;
   FlashRegionInfo * RegionInfo;
   BYTE * CurrAddr;
   FlashBankInfo *BankInfo;
   BYTE * CurrBankAddr;
   DWORD CurrBankSize;
   BYTE * CurrPollAddr;
#ifndef __MTK_TARGET__
   const char        *FileName;
   void              *flash_device;
   BYTE              *rootMTDcache;
   BYTE              *MTDcache;
   DWORD             first;
   DWORD             last_WinAddr;
   DWORD             last_region;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_AddrLookup  lookup_tbl[LOOKUP_TABLE_SIZE][2];
#endif
} NOR_Flash_MTD_Data;

#ifndef __MTK_TARGET__
   #ifndef FLASH_DISKDRV_DEBUG
      #define MakeMtdFlashData(a, b)   0x0, 0x000000, b, NULL, "..\\..\\fs\\flash_device.img", NULL, NULL, NULL
   #else
      #define MakeMtdFlashData(a, b)   0x0, 0x000000, b, NULL, "..\\flash_device.img", NULL, NULL, NULL
   #endif
#else
#define MakeMtdFlashData(a, b)   a, b, NULL
#endif

/* Multi-sector Protection Entry */
#ifndef __MTK_TARGET__
#pragma pack(1)
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/* Erase queue data structure */
typedef ONE_BYTE_ALIGN_ADS struct {
   kal_uint32 head;
   kal_uint32 tail;
   kal_uint32* queue;
} NOR_EraseQueue;
/* Flash state maintainence */
typedef enum
{
	NOR_IN_READY = 0xF0,
	NOR_IN_PROGRAM,
	NOR_IN_SUSPENDED_PROGRAM,
	NOR_IN_ERASE,
	NOR_IN_SUSPENDED_ERASE,
	NOR_IN_ERROR
} NOR_Flash_State;

extern NOR_Flash_State FlashState;

#define Query_Flash_State(a) \
{\
   a = FlashState; \
}

#define Set_Flash_State(a) \
{\
   FlashState = a; \
}

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

typedef ONE_BYTE_ALIGN_ADS struct {
   DWORD LogicalSectorID;
   DWORD PysicalSectorID_new;
} MS_ENTRY;

#define MSTABLE_ENTRY_NUM    16

// Flash driver's data
typedef ONE_BYTE_ALIGN_ADS struct {
   DWORD TotalFATSectors;
   NOR_MTD_Driver * MTDDriver;
   void *    MTDData;
   WORD      *AvailSectorsInBlock;
   WORD      *ValidSectorsInBlock;
   NOR_MTD_FlashInfo FlashInfo;
   DWORD     HeaderSize[REGION_NUM];        // offset to first sector data in flash block
   DWORD     SectorsPerBlock[REGION_NUM];
   DWORD     ActiveBlock;
   DWORD     ReclaimEraseCount;
   DWORD     ReclaimBlockID;
   DWORD TotalPhysicalSectors;
   DWORD PartitionSectors;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   DWORD GCHighThreshold;
   DWORD GCMiddleThreshold;
   DWORD GCLowThreshold;
   DWORD GCBlockSectors;
#else
   DWORD GCThreshold;
#endif
   DWORD AvailSectors;
   DWORD DeletedSectors;
   DWORD StartSector;
   DWORD Sectors;
   DWORD SectorsLeft;
   DWORD     BLOCKID_OFFSET;
   DWORD     SECTORIDX_MASK;
   DWORD     PHY_SECTOR_OFFSET;

   DWORD     MS_count;
   MS_ENTRY  MSEntryTable[MSTABLE_ENTRY_NUM];
   BYTE      *SectorMap;
   BYTE      *Buffer;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   BYTE      BlockInErase;
   WORD      queueSize;
   WORD      eraseItems;
   NOR_EraseInfo  *EraseQueue;
   /* Sleep mode support -- may need to be removed to internal RAM when DCM is enabled */
   DWORD     processedBankAddr;
   DWORD     processedBlock;
   DWORD     processedEraseCount;
   kal_bool  IsEraseSuspended;
   DWORD     IdleReclaimBlockID;
   DWORD     ProgramFailBuffer[512/sizeof(DWORD)];
   DWORD     RegionMaxBlock;
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
} NOR_FLASH_DRV_Data;

#ifdef __MTK_TARGET__

extern kal_mutexid fdm_reclaim_mutex;
extern kal_eventgrpid  nor_egid;
#define NOR_BRECL_EVENT 0x1
#define NOR_FRECL_EVENT 0x2
#define NOR_DMAN_EVENT 0x4

#endif

/* Flash Bank Info */
typedef struct {
   DWORD BankSize;
   DWORD Banks;
} NORBankInfo;
#define EndBankInfo  {0, 0}

/* Flash Layout Info */
typedef struct {
   DWORD TotalLSMT;
   DWORD BlkSize;
   DWORD PageSize;
   NORBankInfo *BankInfo;
   WORD TblEntrys;
   WORD TotalBlks;
} NORLayoutInfo;

typedef struct {
   DWORD  Signature;
   BYTE * BaseAddr;
   NORLayoutInfo * LayoutInfo;
#ifndef __MTK_TARGET__
   const char        *FileName;
   void              *flash_device;
   BYTE              *rootMTDcache;
   BYTE              *MTDcache;
   DWORD             modify;                    //first time, don't need to write to file
   DWORD             last_WinAddr;    // next address calling mapwindow
   DWORD             last_region;        //next region calling mapwindow
#endif
} NOR_MTD_DATA;

typedef ONE_BYTE_ALIGN_ADS struct  
{
   DWORD MSCount;
   DWORD LogPageID[MSTABLE_ENTRY_NUM];
   WORD NewEntryID[MSTABLE_ENTRY_NUM];
   WORD OldEntryID[MSTABLE_ENTRY_NUM];
}MS_TABLE;

typedef ONE_BYTE_ALIGN_ADS struct { 
   WORD LogBlkID;
   WORD TblIDInBlk;
}LSMGEntry;

//flash driver data for FDM5.0
typedef ONE_BYTE_ALIGN_ADS struct {
   DWORD    TotalFATSectors;
   NOR_MTD_Driver * MTDDriver;
   void *      MTDData;
   int  (* DiscardSectors) (void * DriveData, UINT Sector, UINT Sectors);
   void (*ReclaimBlock) (void* DriveData, kal_bool isBackground);
   DWORD    SecondPartitionSectors;
   DWORD    HeaderSize[2];  //HeaderSize[0]: data block header size
                                        //HeaderSize[1]: table block header size
   DWORD    *InvalidEntryInTblBlk; //valid entry in table block
   DWORD    TotalAvail[2];   // TotalAvail[0]: total available pages in data block
                                         //TotalAvail[0]: total available tables in table block
                                         //not include empty block (2 spare block)
   DWORD    TotalInvalid[2]; // TotalInvalid[0]: total invalid pages in data block
                                        //TotalInvalid[0]: total invalid tables in table block
   DWORD    ReclHighThreshold[2]; //unit ReclHighThreshold[0]: Pages ReclHighThreshold[1]: Tables 
   DWORD    ReclLowThreshold[2];
   DWORD    SystemThreshold[2];
   kal_bool   NeedResumeFlag;
   kal_bool   NeedFRecl;
   LSMGEntry    *LSMG;            // logical sector mapping group table
   WORD      ReclType;
   WORD      *LBM;              //logical block mapping table
   WORD      *AvailInBlk;     //available page in data block, available table in table block
   WORD      *InvalidInBlk;     //valid  page in data block, valid table in table block
   WORD      ActiveBlk[2];    // ActiveBlk[0]: active data block
                                        //ActiveBlk[1]: active table block
   WORD      ReclLogBlkID;  //ReclLogBlkID == INVALID_BLOCK_ID means no block need reclamation
   WORD      ErasingPhyBlk;
   WORD      ReclToPhyBlkID;
   WORD      ReclFromPhyBlkID;
   WORD      PageSizeShift;
   WORD      BlkIDShift;
   WORD      TblSizeShift;
   WORD      TblIDShift;
   WORD      PagesPerBlk; 
   WORD      TblsPerBlk;
   WORD      TblBlks;
   WORD      SetTblBlks;
   WORD      DataBlks;
   MS_TABLE  MSTable;
   BYTE      *Buffer;
   BYTE      *CopyBuffer;
} NOR_FTL_DATA;


#ifndef __MTK_TARGET__
#pragma pack()
#endif

typedef struct {
   DWORD Blocks;
   DWORD BlockSize;
   DWORD EraseCountMax;
   DWORD EraseCountMin;
   DWORD EraseCountAverage;
   DWORD SectorsInUse;
   DWORD SectorsDeleted;
   DWORD SectorsAvail;
} NORFlashInfo;

/* Definition for power loss test */
#if defined(FLASH_DISKDRV_DEBUG) && defined(POWERLOSS_TEST)
#include <setjmp.h>
extern jmp_buf mark;
extern int Test_CD_Value;
#ifndef __NOR_FDM5__
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
enum
{
/* 1*/WriteSector_SECTOR_WRITING = 1,
/* 2*/WriteSector_SECTOR_WRITTEN,
/* 3*/WriteSector_SECTOR_DELETED,
/* 4*/WriteSector_SECTOR_VALID,
/* 5*/WriteSector_SECTOR_MS_WRITTEN,
/* 6*/ReclaimBlock_pre_BLOCK_RECLAIMING,
/* 7*/ReclaimBlock_pre_BLOCK_RECLAIMED,
/* 8*/ReclaimBlock_pre_BLOCK_VIRGINE,
/* 9*/ReclaimBlock_post_BLOCK_EMPTY,
/*10*/SetActiveBlock_BLOCK_FULL,
/*11*/SetActiveBlock_BLOCK_ACTIVE,
/*12*/ResumeSectorStates_SECTOR_MS_BEINGVALIDATED,
/*13*/WriteSector_SECTOR_MOVING,
/*14*/WriteSectors_Validate_MS_Sector,
/*15*/WriteSectors_Validate_MS_VALID_Sector,
/*16*/ReclaimEraseQueueItem_BLOCK_VIRGINE,
/*17*/IdleReclaimBlocks_BLOCK_RECLAIMING,
/*18*/IdleReclaimBlocks_BLOCK_RECLAIMING_COPYSECTOR,
/*19*/IdleReclaimBlocks_BLOCK_VIRGINE,
/*20*/IdleReclaimBlocks_RECALIM_ONE_MORE_BLOCK,
/*21*/IdleReclaimBlocks_BLOCK_RECLAIMED
};

#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case WriteSector_SECTOR_MS_WRITTEN:\
         case ReclaimBlock_pre_BLOCK_RECLAIMING:\
         case ReclaimBlock_pre_BLOCK_RECLAIMED:\
         case ReclaimBlock_pre_BLOCK_VIRGINE:\
         case ReclaimBlock_post_BLOCK_EMPTY:\
         case SetActiveBlock_BLOCK_FULL:\
         case SetActiveBlock_BLOCK_ACTIVE:\
         case WriteSectors_Validate_MS_Sector:\
            Test_CD_Value -= 50;\
            break;\
         case ResumeSectorStates_SECTOR_MS_BEINGVALIDATED:\
            Test_CD_Value -= 50;\
            break;\
         case IdleReclaimBlocks_BLOCK_RECLAIMING:\
         case IdleReclaimBlocks_BLOCK_RECLAIMING_COPYSECTOR:\
         case IdleReclaimBlocks_BLOCK_VIRGINE:\
         case IdleReclaimBlocks_RECALIM_ONE_MORE_BLOCK:\
         case IdleReclaimBlocks_BLOCK_RECLAIMED:\
            Test_CD_Value -= 50;\
            break;\
         case WriteSectors_Validate_MS_Sector:\
         case WriteSectors_Validate_MS_VALID_Sector:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#else /*!__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
enum
{
/* 1*/WriteSector_SECTOR_WRITING = 1,
/* 2*/WriteSector_SECTOR_WRITTEN,
/* 3*/WriteSector_SECTOR_DELETED,
/* 4*/WriteSector_SECTOR_VALID,
/* 5*/WriteSector_SECTOR_MS_WRITTEN,
/* 6*/ReclaimBlock_pre_BLOCK_RECLAIM,
/* 7*/ReclaimBlock_pre_BLOCK_VIRGINE,
/* 8*/ReclaimBlock_post_BLOCK_EMPTY,
/* 9*/SetActiveBlock_BLOCK_FULL,
/*10*/SetActiveBlock_BLOCK_ACTIVE,
/*11*/ResumeSectorStates_SECTOR_MS_BEINGVALIDATED,
/*12*/WriteSector_SECTOR_MOVING,
/*13*/WriteSectors_Validate_MS_Sector
};

#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case WriteSector_SECTOR_MS_WRITTEN:\
         case ReclaimBlock_pre_BLOCK_RECLAIM:\
         case ReclaimBlock_pre_BLOCK_VIRGINE:\
         case ReclaimBlock_post_BLOCK_EMPTY:\
         case SetActiveBlock_BLOCK_FULL:\
         case SetActiveBlock_BLOCK_ACTIVE:\
         case WriteSectors_Validate_MS_Sector:\
            Test_CD_Value -= 50;\
            break;\
         case ResumeSectorStates_SECTOR_MS_BEINGVALIDATED:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
#else /*FDM5*/
enum
{
/* 1*/ReclaimBlock_MARK_BLOCK_RECLAIM = 1,  
/* 2*/ReclaimBlock_MARK_BLOCK_COPYING,  
/* 3*/ReclaimBlock_TABLE_BLOCK_COPYING, 
/* 4*/ReclaimBlock_DATA_BLOCK_COPYING,
/* 5*/ReclaimBlock_MARK_BLOCK_ERASING,
/* 6*/ReclaimBlock_AFTER_ERASED,
/* 7*/CopyTable_MARK_COPYING,
/* 8*/CopyTable_MARK_ALLOCATING,
/* 9*/CopyTable_MARK_VALID,
/*10*/WritePage_MARK_TABLE_ENTRY_WRITING,
/*11*/WritePage_MARK_TABLE_ENTRY_WRITTEN,
/*12*/WritePage_MARK_PAGE_VALID,
/*13*/WritePage_MARD_TABLE_ENTRY_MS_WRITING,
/*14*/WritePage_MARD_TABLE_ENTRY_MS_BEGIN_VALID,
/*15*/SetActiveBlock_BLOCK_FULL,
/*16*/SetActiveBlock_BLOCK_ACTIVE
};


#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case ReclaimBlock_MARK_BLOCK_RECLAIM:\
         case ReclaimBlock_MARK_BLOCK_COPYING:\
         case ReclaimBlock_TABLE_BLOCK_COPYING:\
         case ReclaimBlock_DATA_BLOCK_COPYING:\
         case ReclaimBlock_MARK_BLOCK_ERASING:\
		 case ReclaimBlock_AFTER_ERASED:\
		 case CopyTable_MARK_COPYING:\
		 case CopyTable_MARK_ALLOCATING:\
		 case CopyTable_MARK_VALID:\
		 case WritePage_MARK_TABLE_ENTRY_WRITING:\
		 case WritePage_MARK_TABLE_ENTRY_WRITTEN:\
		 case WritePage_MARK_PAGE_VALID:\
		 case WritePage_MARD_TABLE_ENTRY_MS_WRITING:\
		 case WritePage_MARD_TABLE_ENTRY_MS_BEGIN_VALID:\
		 case SetActiveBlock_BLOCK_FULL:\
		 case SetActiveBlock_BLOCK_ACTIVE:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#endif /*__NOR_FDM5__*/
#define START_POINT  setjmp(mark)
#else
#define TEST_POINT(a)
#define START_POINT
#endif /* FLASH_DISKDRV_DEBUG */


/* Function Prototype */
int NOR_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags);
int NOR_ShutDown(void * DriveData);
int NOR_ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int NOR_WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int NOR_MediaChanged(void * DriveData);
int NOR_DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors);
int NOR_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int NOR_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, DWORD Flags);
int NOR_NonBlockWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int NOR_RecoverableWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int NOR_ResumeSectorStates(void * DriveData);

int SIB_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags);
int SIB_ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int SIB_WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int SIB_DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors);
int SIB_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int SIB_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, DWORD Flags);
int SIB_NonBlockWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int SIB_RecoverableWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int SIB_ResumeSectorStates(void * DriveData);


int nNOR_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags);
int nNOR_ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nNOR_WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nNOR_MediaChanged(void * DriveData);
int nNOR_DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors);
int nNOR_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, DWORD Flags);
int nNOR_NonBlockWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nNOR_RecoverableWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nNOR_ResumeSectorStates(void * DriveData);
void nNOR_ReclaimBlock(void* DriveData, kal_bool isBackground);

int nSIB_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags);
int nSIB_ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nSIB_WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nSIB_DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors);
int nGetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int nSIB_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, DWORD Flags);
int nSIB_NonBlockWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nSIB_RecoverableWriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
int nSIB_ResumeSectorStates(void * DriveData);
void nSIB_ReclaimBlock(void* DriveData, kal_bool isBackground);
int nShutDown(void * DriveData);

int OTPAccess(void * DriveData, int accesstype, UINT Offset, void * BufferPtr, UINT Length);
int OTPQueryLength(void * DriveData, UINT *Length);

/* internal helper function */
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
int NOR_EraseQueueItems(void * DriveData);
#endif
#endif
