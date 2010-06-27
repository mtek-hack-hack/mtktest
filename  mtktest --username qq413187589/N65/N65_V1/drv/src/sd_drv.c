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
 *   ms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Adaption driver of file system for SD card
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#include "kal_release.h"
#include "app_buff_alloc.h"
#include "fat_fs.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "ms_def.h"
#include "intrCtrl.h"
#include "msdc_lsd.h"

#ifdef DRV_LSD
//#define LSD_SINGLE_READ
//#define LSD_SINGLE_WRITE
/*to test where card consumes power whenever it is in transfer state*/
//#define TEST_TRANSFER_STATE_CONSUME_POWER
#endif

#if defined(__MSDC_SD_MMC__)

#define MAX_CLUSTERS (0x0FFF6 - 2)
#define SECTOR_SIZE 512	
#define MSDC_MEDIA_DESCRIPTOR		0xF8
#define SD_MAX_RETRY	2

static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
static kal_uint32 sd_r,sd_w;
extern kal_bool INT_USBBoot(void);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static int  DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	
	SDC_CMD_STATUS status;
	kal_uint8 retry = 0;
	kal_uint32 adrs;

#if defined(__SIM_PLUS__)
	sd_select_enum sel;
	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
		sel = SD_EXT;
	else
		sel = SD_SIM;
	MSDC_Switch_Card(sel);
#endif
	
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD->flags & SD_FLAG_HCS_SUPPORT)
		adrs = Sector;
	else
	#endif		
		adrs = Sector * SECTOR_SIZE;
	gMSDC_Handle->timeout_count = 0;
start:
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Read but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_READ_SECTOR_ERROR;
	}
	retry ++;
	MSDC_PDNControl(KAL_FALSE);
#ifndef LSD_SINGLE_READ
	if(Sectors > 1)
		status = SD_ReadMultiBlock((kal_uint32)adrs,(kal_uint32*)Buffer,(kal_uint32)Sectors);
	else
		status = SD_ReadSingleBlock((kal_uint32)adrs,(kal_uint32*)Buffer);
#else
	while(Sectors){
		status = SD_ReadSingleBlock((kal_uint32)adrs,(kal_uint32*)Buffer);

		if(status != NO_ERROR )
			break;
		(kal_uint8 *)Buffer += SECTOR_SIZE;
		Sector ++;
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
		if(gSD->flags & SD_FLAG_HCS_SUPPORT)
			adrs = Sector;
		else
	#endif		
		adrs = Sector * SECTOR_SIZE;
	
		Sectors--;
	}
#endif
	if(status != NO_ERROR )
	{		
		sd_r++;
		if(kal_query_systemInit()== KAL_TRUE)
		{
			MSDC_PDNControl(KAL_TRUE);
			return FS_MSDC_READ_SECTOR_ERROR;
		}		
		//dbg_print("read retry:%d,status:%d,total %d\r\n",retry,status,sd_r);
		if(status == ERR_CMD_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count++ == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:re-mount(read fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(SD_Initialize() != NO_ERROR)
			{
				MSDC_PDNControl(KAL_TRUE);
				return FS_MSDC_READ_SECTOR_ERROR;
			}
		}
		if(retry >= SD_MAX_RETRY)
		{
			MSDC_PDNControl(KAL_TRUE);
			return FS_MSDC_READ_SECTOR_ERROR;
		}
		else
		{
			// kal_prompt_trace(MOD_AUD,"CRC etry:%d,status:%d",retry,status);
			goto start;			
		}
	}
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	SDC_CMD_STATUS status;
	kal_uint8 retry = 0;
	kal_uint32 adrs;

#if defined(__SIM_PLUS__)
	sd_select_enum sel;
	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
		sel = SD_EXT;
	else
		sel = SD_SIM;
	MSDC_Switch_Card(sel);
#endif
	
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD->flags & SD_FLAG_HCS_SUPPORT)
		adrs = Sector;
	else
	#endif
		adrs = Sector * SECTOR_SIZE;	
	gMSDC_Handle->timeout_count = 0;	
start:
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Write but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_WRITE_SECTOR_ERROR;
	}
	retry++;
	MSDC_PDNControl(KAL_FALSE);
#ifndef LSD_SINGLE_WRITE
	if(Sectors > 1)
	{
		if(gMSDC_Handle->mMSDC_type == SD_CARD)
			SD_SetPreEraseBlk(Sectors);		
		status = SD_WriteMultiBlock((kal_uint32)adrs,(kal_uint32*)Buffer,(kal_uint32)Sectors);
	}
	else
		status = SD_WriteSingleBlock((kal_uint32)adrs,(kal_uint32*)Buffer);	
#else
	while(Sectors){
		status = SD_WriteSingleBlock((kal_uint32)adrs,(kal_uint32*)Buffer);

		if(status != NO_ERROR )
			break;
		(kal_uint8 *)Buffer += SECTOR_SIZE;
		Sector ++;
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
		if(gSD->flags & SD_FLAG_HCS_SUPPORT)
			adrs = Sector;
		else
	#endif		
		adrs = Sector * SECTOR_SIZE;
	
		Sectors--;
	}
#endif
	if(status != NO_ERROR)
	{
		sd_w++;		
		if(kal_query_systemInit()== KAL_TRUE)
		{
			MSDC_PDNControl(KAL_TRUE);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		//dbg_print("write retry:%d,status:%d,total %d\r\n",retry,status,sd_w);
		if(status == ERR_CMD_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count++ == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:SD re-mount (write fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(SD_Initialize() != NO_ERROR)
			{
				MSDC_PDNControl(KAL_TRUE);
				return FS_MSDC_WRITE_SECTOR_ERROR;
			}
		}		
		if(retry >= SD_MAX_RETRY)
		{
			MSDC_PDNControl(KAL_TRUE);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		else
		{
			// kal_prompt_trace(MOD_AUD,"CRC write Error retry %d",retry);
			goto start;			
		}
	}
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
}



SD_SelfFormat()
{
    
    FS_PartitionRecord Par, Par1;
    //static kal_uint8 p[512];

    kal_mem_set((void*)&Par, 0, sizeof Par);
    Par.Sectors = gSD->mCSD.capacity/512;
 
        FS_CreateMasterBootRecord(MSDC_Sector, &Par);
 
        WriteSectors(gMSDC_Handle, 0, 1, MSDC_Sector);
 
    Par = ((FS_MasterBootRecord *)MSDC_Sector)->PTable[0];
    FS_CreateBootSector((void*)MSDC_Sector, &Par, 0xF8, 0, FS_FMT_SINGLE_FAT );
    WriteSectors(gMSDC_Handle, Par.RelativeSector, 1, MSDC_Sector);
 /*  End of SelfFormat */

}

#ifdef DRV_LSD
extern kal_uint32 notifiedFMT;
#endif

/*-----------------------------------*/
static int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags)
{	
	kal_uint8 retry = 0;

	#if defined(__SIM_PLUS__)
	sd_select_enum sel;
	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
		sel = SD_EXT;
	else
	{
		sel = SD_SIM;
	}
	MSDC_Switch_Card(sel);
	#endif
	

#ifdef DRV_LSD
	/*notifiedFMT may be modified by FMT and MMI tasks, but it is no need to protect this, FMT can't preempt MMI*/
	if(1 == notifiedFMT)/*in this state. we dont allow any access on memory card, we will return fail on any mount trial*/	
	{
		return FS_MSDC_MOUNT_ERROR;
	}
#endif

	if(gMSDC_Handle->mIsInitialized)
		return SECTOR_SIZE;
	gMSDC_Handle->is_init_timeout = KAL_FALSE;		
start:		
	if(!gMSDC_Handle->mIsPresent)
	{		
		//dbg_print("not present \r\n");
		
		#if defined(_NAND_FLASH_BOOTING_)
		// add the following code for solving plug in or out the SD card during 
		// NFB loading process. The card detection interruptwill disapperared 		 
		// while interrupt controller is masked.
		IRQMask(IRQ_MSDC_CODE);
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
			else
				gMSDC_Handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_TRUE;
			else
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
		}
		IRQUnmask(IRQ_MSDC_CODE);
		#endif // _NAND_FLASH_BOOTING_
		
		if(!gMSDC_Handle->mIsPresent)	
		{
			MSDC_PDNControl(KAL_TRUE);			
			return FS_MSDC_MOUNT_ERROR;
		}
	}
	MSDC_PDNControl(KAL_FALSE);
	if(SD_Initialize() != NO_ERROR)
	{		
		goto err_exit;
	}	
	//if(SD_MountDevice(DeviceType) != FS_NO_ERROR)
		//return FS_MSDC_MOUNT_ERROR;

	//dbg_print("Mount success! \r\n");

#ifdef MSDC_SDMMC_NAND
	/*for SDMMC NAND, some manufacturs sale NAND with all sectors zero, we should format it first*/
	if(ReadSectors( DriveData, 0, 1, MSDC_Sector) != NO_ERROR)
		goto err_exit;
	if(0x55aa != (MSDC_Sector[128] & 0xffff0000)){/*it doesn't have correct MBR*/
		SD_SelfFormat();
	}
	else{
		if(ReadSectors( DriveData, 1, 1, MSDC_Sector) != NO_ERROR)
			goto err_exit;
		if(0x55aa != (MSDC_Sector[128] & 0xffff0000)){/*it doesn't have correct PBR*/
			SD_SelfFormat();
		}
	}
#endif
	
	MSDC_PDNControl(KAL_TRUE);

#ifdef DRV_LSD
	if(KAL_TRUE == kal_query_systemInit()){/*we don't let access memory card before FMT get plug in message*/
		/*there is no task can access when system init*/
		notifiedFMT = 1;
		return FS_MSDC_MOUNT_ERROR;
	}
#endif

   return SECTOR_SIZE;
   
err_exit:
	if(retry++ <= SD_MAX_RETRY && gMSDC_Handle->is_init_timeout == KAL_FALSE)
	{
		//dbg_print("SD MountDevice failed! retry: %d \r\n",retry);
		goto start;
	}
	#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	gMSDC_Handle->mIsPresent = KAL_FALSE;
	#endif	

	#if defined(__SIM_PLUS__)
	
	if(INT_USBBoot() == KAL_TRUE && current_card == SD_SIM)
	{
		gMSDC_Handle->mIsPresent = KAL_FALSE;
	}
	#endif
	
	MSDC_PDNControl(KAL_TRUE);
	return FS_MSDC_MOUNT_ERROR;
	
}


/*-----------------------------------*/
static int  MediaChanged(void * DriveData)
{	
#if defined(__SIM_PLUS__)
	sd_select_enum sel;
	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
		sel = SD_EXT;
	else
		sel = SD_SIM;
	MSDC_Switch_Card(sel);
#endif
	
	if(gMSDC_Handle->mIsPresent)
	{
		if(gMSDC_Handle->mIsInitialized)
		{
		
		#ifdef MSDC_MUST_RECORD_PLUGOUT
			MSDC_everPlugOut = KAL_FALSE;
		#endif
   		return FS_NO_ERROR;
		}
		else
		{
		#ifdef MSDC_MUST_RECORD_PLUGOUT
			/*current state is present not mount, we have to check whether it plug out before*/
			if(KAL_TRUE == MSDC_everPlugOut){
				/*send FMT a new message, and return plug out*/
				MSDC_everPlugOut = KAL_FALSE;
			#if !defined(FMT_NOT_PRESENT)
				MSDC_SendCardInd(MOD_FMT, SD_EXT);
			#endif
				return FS_MSDC_NOT_PRESENT;
			}
			MSDC_everPlugOut = KAL_FALSE;
		#endif
			return FS_MSDC_PRESNET_NOT_READY;
		}
	}
#ifdef MSDC_MUST_RECORD_PLUGOUT
	MSDC_everPlugOut = KAL_FALSE;
#endif
	return FS_MSDC_NOT_PRESENT;
}

/*-----------------------------------*/
static int  GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
#if defined(__SIM_PLUS__)
	sd_select_enum sel;
	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
		sel = SD_EXT;
	else
		sel = SD_SIM;
	MSDC_Switch_Card(sel);
#endif
   if(gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized){
   	kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);
   	DiskGeometry->Sectors = gSD->mCSD.capacity/512;
   	// 0xF8 is the standard value for fixed media, 0xF0 is for removable media.
   	// The important point is whatever value is put in here must also be put in the first
   	// byte of he FAT[0].
	*MediaDescriptor = MSDC_MEDIA_DESCRIPTOR;
	if(gSD->mWPEnabled)
		return FS_WRITE_PROTECTION;		
   	return FS_NO_ERROR;
   }
   else{
   	return FS_MSDC_NOT_PRESENT;
   }
}

/*-----------------------------------*/
static int  ShutDown(void * DriveData)
{
#ifdef  __TST_WRITE_TO_FILE_ONLY__
	/*error recording: write error log to memory card here*/
	MSDC_ErrorRecordingReset();
#endif
   return FS_NO_ERROR;
}


/*******************************************
 * File System <--> Device Driver Interface
 * High Level Format 
 *
 * Sample Code
 ******************************************/
#include <fs_type.h>
#include <rtfiles.h>

/* FIXME */
//kal_uint8 SectorBuffer[512];

int highlevelformat(void * DriveData, UINT BaseSectorNumber)
{
   int              FATType;
   int        SystemSectors,
             RootDirSectors,
                 FATSectors,
                    Written;
   int             FatCount,
                 StartOfFAT,
                 InfoSector;
   int		i, y;
   FS_BootRecord       *PBR;
   kal_uint8 MediaDescriptor;
   int Result   = RTF_NO_ERROR;
   
   /* HLF - 1 - Read the PBR sector */
   ///* FIXME */ DrvDirect.ReadSector(SectorBuffer     /* Buffer */ ,
   //                                 BaseSectorNumber /* Sector Number */);
   ReadSectors(DriveData, BaseSectorNumber, 1, MSDC_Sector);

   PBR = (FS_BootRecord*)&MSDC_Sector;

   /* HLF - 2 - Setup PBR sector content and attributes */
   {
      if (PBR->BP.SectorsOnDisk != 0)
         PBR->BP.TotalSectors = PBR->BP.SectorsOnDisk;

      if (PBR->Signature != 0xAA55 ||
          //PBR->BP.TotalSectors > Par.Partition.Sectors ||
          PBR->BP.TotalSectors > (gSD->mCSD.capacity/512) ||
          PBR->BP.BytesPerSector != 512 ||
          PBR->BP.SectorsPerCluster == 0 ||
          PBR->BP.ReservedSectors == 0 ||
          PBR->BP.NumberOfFATs == 0)
      {
         return FS_INVALID_FILE_SYSTEM;
      }

      FATSectors     = (PBR->BP.SectorsPerFAT) ? PBR->BP.SectorsPerFAT : PBR->BP.E._32.SectorsPerFAT;
      RootDirSectors = (PBR->BP.DirEntries * 32 + (PBR->BP.BytesPerSector - 1)) / PBR->BP.BytesPerSector;

      Written        = PBR->BP.TotalSectors
                     - PBR->BP.ReservedSectors
                     - PBR->BP.NumberOfFATs * FATSectors
                     - RootDirSectors;
      Written = Written / PBR->BP.SectorsPerCluster;

      if (Written <= 0xFF4L)            FATType = 12;
      else if (Written <= 0xFFF4l)      FATType = 16;
      else if (Written <= 0xFFFFFF4l)   FATType = 32;
      else             return FS_INVALID_FILE_SYSTEM;
      Written = 0;

      if (FATType == 32)
      {
         RootDirSectors = PBR->BP.SectorsPerCluster;

         if (PBR->BP.E._32.RootDirCluster != 2)
         {
            PBR->BP.E._32.RootDirCluster = 2;
            /*
            Result = RTFSeek(Drive, 0, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) return Result;

            Result = RTFWrite(Drive, (void*)PBR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) return Result;
            */
            //above seek and write seems mean write to specific sector
            WriteSectors(DriveData, BaseSectorNumber , 1, (void *)PBR);

	     /*
            Result = RTFSeek(Drive, PBR->BP.E._32.BackupBootSector * SECTOR_SIZE, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) return Result;

            Result = RTFWrite(Drive, (void*)PBR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) return Result;
            */
            WriteSectors(DriveData, BaseSectorNumber + PBR->BP.E._32.BackupBootSector , 1, (void *)PBR);
         }
      }

      SystemSectors  = PBR->BP.ReservedSectors
                     + PBR->BP.NumberOfFATs * FATSectors
                     + RootDirSectors;

      FatCount       = PBR->BP.NumberOfFATs;
      StartOfFAT     = PBR->BP.ReservedSectors;
      InfoSector     = PBR->BP.E._32.FSInfoSector;
   }

   /*we get MediaDescriptor for step 6 usage, since we will clear MSDC_Sector*/
   MediaDescriptor = PBR->BP.MediaDescriptor;
   /*we need MSDC_Sector to be 512-byte-0 now*/
   kal_mem_set(MSDC_Sector, 0, 512);
   
   /* HLF - 3 - Formating cont, FAT32 reserved sector write down */
   {
     
      if ((FATType == 32) && (InfoSector > 0) && (InfoSector < StartOfFAT))
      {
         /* FIXME */ 
         //DrvDirect.ZeroSector( BaseSectorNumber + InfoSector /* Start Sector Number */ ,
         //                      1                             /* Zero Sector Count   */ );
         WriteSectors(DriveData, BaseSectorNumber + InfoSector, 1, MSDC_Sector);
      }
   }

   SD_startFastFormat();
   /* HLF - 4 - Formating cont, start, FAT Table write down , remember FAT begin sector */
   {
         /* FIXME */ 
         //DrvDirect.ZeroSector( BaseSectorNumber + StartOfFAT /* Start Sector Number */ ,
         //                      FATSectors * FatCount         /* Zero Sector Count   */ );
      #ifdef DRV_LSD
         WriteSectors(DriveData, BaseSectorNumber + StartOfFAT, FATSectors * FatCount , MSDC_Sector);
      #else
         for(i = 0; i < FATSectors * FatCount; i++){
         	WriteSectors(DriveData, BaseSectorNumber + StartOfFAT + i, 1 , MSDC_Sector);
         }
      #endif
   }
   /* HLF - 5 - Formating cont, Root directory write down */
   {
      int x;
      x = StartOfFAT + FATSectors * FatCount;
         /* FIXME */ 
         //DrvDirect.ZeroSector( BaseSectorNumber + x          /* Start Sector Number */ ,
         //                      RootDirSectors                /* Zero Sector Count   */ );
      #ifdef DRV_LSD
         WriteSectors(DriveData, BaseSectorNumber + x, RootDirSectors , MSDC_Sector);
      #else
         for(i = 0; i < RootDirSectors; i++){
         	WriteSectors(DriveData, BaseSectorNumber + x + i, 1 , MSDC_Sector);
         }
      #endif
   }
   SD_closeFastFormat();
   /* HLF - 6 - Formating final, 1st FAT sector must be rewritten */
   {
      
     
    

     
      switch (FATType)
      {
         case 32:
            {
               //kal_uint32 * FPtr = (void*) ScratchSector;
               MSDC_Sector[2] = 0x0FFFFFFF; // this is for the root dir
               MSDC_Sector[1] = 0x0FFFFFFF;
               break;
            }
         case 16:
            {
               kal_uint16 * FPtr = (void*) MSDC_Sector;
               FPtr[1] = 0xFFFF;
               break;
            }
         case 12:
            {
            	 kal_uint8 *FPtr = (void *)MSDC_Sector;
               /* FIXME */ FPtr[2] = 0xFF;
               /* FIXME */ FPtr[1] = 0xFF;
               /* FIXME */ FPtr[0] = MediaDescriptor;
               break;
            }
      }
      for (i = 0, y = StartOfFAT;
           i < FatCount;
           i++  , y+= FATSectors)
      {
         ///* FIXME */ DrvDirect.WriteSector(SectorBuffer     /* Buffer */ ,
         //                              BaseSectorNumber + y /* Sector Number */);
         WriteSectors(DriveData, BaseSectorNumber + y, 1 , MSDC_Sector);
      }
   }
   /* HLF - 7 - The END */
   return FS_NO_ERROR;
}



FS_Driver FS_SdDrv = {
   MountDevice,
   ShutDown,
   ReadSectors,
   WriteSectors,
   MediaChanged,
   DiscardSectors,
   GetDiskGeometry,
   NULL,
   NULL,
   NULL,
   NULL,
   highlevelformat,
   NULL,
   MSDC_GetCardStatus   
};
#endif // (__MSDC_SD_MMC__)


