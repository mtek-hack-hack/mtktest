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
 *   Adaption driver of file system for Memory Stick
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
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "ms_def.h"

#if defined(__MSDC_MS__) || defined(__MSDC_MSPRO__)

#define MAX_CLUSTERS (0x0FFF6 - 2)
#define SECTOR_SIZE 512	
#define MSDC_MEDIA_DESCRIPTOR		0xF8
#define MAX_TRY	1

static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);

const kal_uint8 MS_MBR[MS_SUPPORT_TYPES][MS_MBR_SIZE] = {
{ 0x80, 0x01, 0x0C, 0x00, 0x01, 0x01, 0x10, 0xF5, 0x1B, 0x00, 0x00, 0x00, 0xA5, 0x1E, 0x00, 0x00},
{ 0x80, 0x01, 0x0A, 0x00, 0x01, 0x01, 0x50, 0xED, 0x19, 0x00, 0x00, 0x00, 0xA7, 0x3D, 0x00, 0x00},
{ 0x80, 0x01, 0x0A, 0x00, 0x01, 0x03, 0x50, 0xED, 0x19, 0x00, 0x00, 0x00, 0x67, 0x7B, 0x00, 0x00},
{ 0x80, 0x01, 0x04, 0x00, 0x01, 0x03, 0xD0, 0xDD, 0x13, 0x00, 0x00, 0x00, 0x6D, 0xF7, 0x00, 0x00},
{ 0x80, 0x02, 0x08, 0x00, 0x01, 0x07, 0xD0, 0xDD, 0x27, 0x00, 0x00, 0x00, 0xD9, 0xEE, 0x01, 0x00},
{ 0x80, 0x02, 0x02, 0x00, 0x06, 0x0F, 0xD0, 0xDD, 0x21, 0x00, 0x00, 0x00, 0xDF, 0xDD, 0x03, 0x00}
};


__align(4) kal_uint8 MS_buffer[16*1024];

/*-----------------------------------*/
kal_uint16 MS_GetLPIndex(kal_uint32 ladrs)
{
	kal_uint8	seg;
	kal_uint16 min;

	seg = (ladrs < 494)?0:((ladrs-494)/496 + 1);
	min = (seg == 0)?0:(seg*496-2);		

	return ladrs - min;
	
}

#if defined(MS_FORMAT)
static int MS_MountDevice(int DeviceType)
{
	kal_uint8 *sector = (kal_uint8*)MSDC_Sector;
	FS_MasterBootRecord *MBR;
	FS_BootRecord *PBR;
	int status;	
	kal_bool IsMBRExist;
   kal_uint8 type = 0;
   kal_uint8 c = gMS.Capacity;
   	
   // get index for MS_MBR => (type) is the index
   while((c >>= 1) != 2)
   	type++;	   
	
	IsMBRExist = KAL_FALSE;
	// read MBR at sector 0
	status = ReadSectors(NULL,0,1,(void*)sector);	  		
	MBR = (FS_MasterBootRecord*)sector;
	PBR = (FS_BootRecord*)sector;
	if( MBR->Signature == 0xAA55 &&
		MBR->PTable[0].BootIndicator == 0x80)
	{
		IsMBRExist = KAL_TRUE;
	}
	if(!IsMBRExist)
	{	
		// create MBR
		kal_mem_set((void*)MBR,0,sizeof(MBR));
		kal_mem_cpy((void*)&(MBR->PTable[0]),MS_MBR[type],MS_MBR_SIZE);
		MBR->Signature = 0xAA55;
		status = WriteSectors(NULL,0,1,(void*)sector);
		if(status < NO_ERROR)
			return FS_MSDC_MOUNT_ERROR;
		// create PBR
		FS_CreateBootSector((void*)sector, (FS_PartitionRecord*)MS_MBR[type], (BYTE)MSDC_MEDIA_DESCRIPTOR, 
			(UINT)gMS.PagesPerBlk, (gMS.Capacity < 128)?FS_FMT_FAT_12:FS_FMT_FAT_16);
		PBR->NearJump[0] = 0xE9;
		PBR->NearJump[1] = 0x00;
		PBR->NearJump[2] = 0x00;
		kal_mem_set((void*)PBR->BP.OEMName,0x20,8);
		PBR->BP.SectorsPerCluster = gMS.PagesPerBlk;
		PBR->BP.DirEntries = 0x200;
		PBR->BP.E._16.BPB.PhysicalDiskNumber = 0;
		PBR->BP.E._16.BPB.CurrentHead = 0;
		PBR->BP.E._16.BPB.SerialNumber = 0;
		kal_mem_set((void*)PBR->BP.E._16.BPB.Label,0x20,11);	
		status = WriteSectors(NULL, PBR->BP.NumberOfHiddenSectors,1,(void*)sector);
		if(status < NO_ERROR)
			return FS_MSDC_MOUNT_ERROR;
		
	}
	
	return FS_NO_ERROR;
}
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
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	MS_STATUS status;
	kal_uint8 PagesPerBlk,page,readpage,len,*ptr, extra[4];
	kal_uint32 lba,pba;
	kal_uint8 retry = 0;
	
	gMSDC_Handle->timeout_count = 0;
START:	
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Read but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_READ_SECTOR_ERROR;
	}
	gMS.is_write = KAL_FALSE;
	PagesPerBlk = gMS.PagesPerBlk;
	lba = Sector/PagesPerBlk;
	page = Sector%PagesPerBlk;
	ptr = (kal_uint8*) Buffer;
	MSDC_PDNControl(KAL_FALSE);
	while(1)
	{
		if(PagesPerBlk - page < Sectors)
			len = PagesPerBlk - page;
		else
			len = Sectors;			
		ASSERT(len >= 1 && len <= 32);
		status = MS_API_LogToPhy(gMS.pLPTbl,lba,&pba);
		if(status != MS_NOERROR)
			goto ERR_EXIT;//return FS_MSDC_READ_SECTOR_ERROR;
		if(len == 1)
			status = MS_API_ReadSinglePage(pba,page,(kal_uint32*)ptr,NULL);
		else
			status = MS_API_ReadBlock(pba, (kal_uint32*)ptr, NULL, page, len, &readpage);	
		if(status != MS_NOERROR)
			goto ERR_EXIT;//return FS_MSDC_READ_SECTOR_ERROR;
		//============ change the update status ====================//
		MS_API_ReadExtraData(pba, 0, (kal_uint32*)extra);
    	if(MS_UPDATE_STATUS(extra[OVERWRITE_FLAG]) == 0)
    	{
    		kal_uint32 i;
    		kal_uint16 *FreeTable, *LPTable, spareblk;
    		kal_uint8  readpage;
			// find a unused block from FreeTable, erase it and write updated info into it

			LPTable = gMS.pLPTbl;
			FreeTable = gMS.pFreeTbl;			
			i = 0;
			while((FreeTable[i++] == 0xFFFF) && (i < MS_FREETABLE_SIZE));
			spareblk = FreeTable[i-1];
			MS_API_ReadBlock(pba,(kal_uint32*)MS_buffer, (kal_uint32 *)extra, 0, PagesPerBlk, &readpage);
			extra[0] |= MS_OVFLG_UDST;
			MS_API_WriteExtraData(spareblk, 0, (kal_uint32 *)extra);
			MS_API_WriteBlock(spareblk,(kal_uint32*)MS_buffer, (kal_uint32 *)extra, 0, PagesPerBlk, &readpage);				
			MS_API_EraseBlock(pba);
			// update the LPTable and FreeTable
			LPTable[MS_GetLPIndex(lba)] = spareblk;
			FreeTable[i-1] = pba;    		
    	}
		//================================//
		Sectors -= len;
		if(Sectors == 0) break;
		page = 0;
		ptr += 	MS_PAGE_SIZE*len;
		lba++;	
	}
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
   
ERR_EXIT:		
	if(retry++ <= MAX_TRY && kal_query_systemInit()== KAL_FALSE)
	{		
		if(status == MS_ERR_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:re-mount(read fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(MS_Initialize() != NO_ERROR)
				return FS_MSDC_READ_SECTOR_ERROR;
		}
		
		//dbg_print("R: fail retry:%d adrs:%d sectors: %d \r\n",retry,Sector, Sectors);
		goto START;
	}
	MSDC_PDNControl(KAL_TRUE);
	return FS_MSDC_READ_SECTOR_ERROR;
}

/*-----------------------------------*/
/*
only allow two case:
case 1: Sectors == 1
case 2: Sectors == gMS.PagesPerBlk

*/
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{	
	MS_STATUS status;
	kal_uint8 PagesPerBlk,page,pages,extra[4],owflag,len;
	kal_uint32 lba,pba,i,spareblk;
	kal_uint8 *p = NULL,*ptr;
	kal_uint16 *LPTable,*FreeTable;
	kal_uint8 retry = 0;
	
	gMSDC_Handle->timeout_count = 0;
START:	
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Write but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_WRITE_SECTOR_ERROR;
	}
	gMS.is_write = KAL_TRUE;
	LPTable = gMS.pLPTbl;
	FreeTable = gMS.pFreeTbl;
	PagesPerBlk = gMS.PagesPerBlk;
	ptr = (kal_uint8*)Buffer;
	p = (kal_uint8 * )MS_buffer;

	// get physical block address from sector	
	lba = Sector/PagesPerBlk;
	len = page = Sector%PagesPerBlk;
	MSDC_PDNControl(KAL_FALSE);
	while(1)
	{
		if(PagesPerBlk - page < Sectors)
			len = PagesPerBlk - page;
		else
			len = Sectors;			
		ASSERT(len >= 1 && len <= 32);
		status = MS_API_LogToPhy(LPTable,lba,&pba);
		if(status != MS_NOERROR)
			goto ERR_EXIT;

		// set update status to 0
		MS_API_ReadExtraData(pba, 0, (kal_uint32 *)extra);
		owflag = extra[0];
		extra[0] &= ~MS_OVFLG_UDST;
		MS_API_WriteOWF(pba, 0, extra[0]);
		
		// read the entire block
		status = MS_API_ReadBlock(pba,(kal_uint32*)p, (kal_uint32 *)extra, 0, PagesPerBlk, &pages);
		if(status != MS_NOERROR)
		{
			goto ERR_EXIT;
		}
		if(gMS.uc_pages != 0)
		{
			MS_API_LogToPhy(LPTable,lba,&pba);
			MS_API_ReadExtraData(pba, 0, (kal_uint32 *)extra);
			owflag = extra[0];
			extra[0] &= ~MS_OVFLG_UDST;
			status = MS_API_WriteExtraData(pba, 0, (kal_uint32 *)extra);
		}
		// update the page in the memory
		kal_mem_cpy((kal_uint8*)(p+page*MS_PAGE_SIZE), (kal_uint8*)ptr, MS_PAGE_SIZE*len);
		// find a unused block from FreeTable, erase it and write updated info into it
		i = 0;
		while((FreeTable[i++] == 0xFFFF) && (i < MS_FREETABLE_SIZE));
		spareblk = FreeTable[i-1];
		status = MS_API_EraseBlock(spareblk);
		if(status != MS_NOERROR)
			goto ERR_EXIT;
		extra[0] = (owflag|MS_OVFLG_UDST);
		status = MS_API_WriteBlock(spareblk, (kal_uint32*)p, (kal_uint32*)extra, 0, PagesPerBlk, &pages);
		if(status != MS_NOERROR)
			goto ERR_EXIT;
		// update the LPTable and FreeTable
		LPTable[MS_GetLPIndex(lba)] = spareblk;
		FreeTable[i-1] = pba;
		// erase original block
		status = MS_API_EraseBlock(pba);
		if(status != MS_NOERROR)
			goto ERR_EXIT;
		if(gMS.uc_pages || gMS.de_pages)
		{
			kal_uint32 pages;
			if(gMS.uc_pages)
				pages = gMS.uc_pages;
			else
				pages = gMS.de_pages;
			for(i=0;i<32;i++)
			{
				if(pages & (1<<i))
				{
					MS_API_ReadExtraData(spareblk, i, (kal_uint32 *)extra);
					extra[0] &= ~MS_OVFLG_PGST;
					MS_API_WriteExtraData(spareblk, i, (kal_uint32 *)extra);				
				}
			}
		}
		MS_API_ReadExtraData(spareblk, 0x18, (kal_uint32 *)extra);
		Sectors -= len;
		if(Sectors == 0) break;
		ptr += 	MS_PAGE_SIZE*len;		
		page = 0;
		lba++;			
	} // end of while
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
   
ERR_EXIT:
	//dbg_print("W: fail %d\r\n",retry);
	if(retry++ <= MAX_TRY && kal_query_systemInit()== KAL_FALSE)
	{
		if(status == MS_ERR_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:re-mount(write fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(MS_Initialize() != NO_ERROR)
				return FS_MSDC_READ_SECTOR_ERROR;
		}		
		//dbg_print("W: fail retry:%d adrs:%d sectors: %d \r\n",retry,Sector, Sectors);
		goto START;
	}
	MSDC_PDNControl(KAL_TRUE);
	return FS_MSDC_WRITE_SECTOR_ERROR;
	
}

/*-----------------------------------*/
static int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags)
{
	kal_uint8 retry = 0;

	//dbg_print("MountDevice_MS \r\n");
	
	if(gMSDC_Handle->mIsInitialized)
		return SECTOR_SIZE;		
	
START:	
	if(!gMSDC_Handle->mIsPresent)
	{
		//dbg_print("not present \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_MOUNT_ERROR;
	}		
	MSDC_PDNControl(KAL_FALSE);
   if(MS_Initialize() != NO_ERROR)
   {   	
   	goto ERR_EXIT;
   }	
   #if defined(MS_FORMAT)
   if(MS_MountDevice(DeviceType) != FS_NO_ERROR)
   	goto ERR_EXIT;
	#endif
   // get total sector number
   {
	   int i = 0;
	  	FS_PartitionRecord *ptr;
	   kal_uint8 c = gMS.Capacity;
   		   
	   while((c >>= 1) != 2)
	   	i++;	   
		ptr = (FS_PartitionRecord*)MS_MBR[i];
		gMS.TotalSectors = ptr->Sectors;
   }
	   	
   MSDC_PDNControl(KAL_TRUE);
   return SECTOR_SIZE;
   
ERR_EXIT:	
	
	if(retry++ < MAX_TRY)
	{
		//dbg_print("Mount MS failed! retry: %d \r\n",retry);
		goto START;
	}
	MSDC_PDNControl(KAL_TRUE);
	return FS_MSDC_MOUNT_ERROR;
   
}

/*-----------------------------------*/
static int  MediaChanged(void * DriveData)
{
   //dbg_print("MediaChanged\n\r");
	if(gMSDC_Handle->mIsPresent)
	{
		if(gMSDC_Handle->mIsInitialized)
		{
		   //dbg_print("Ready\n\r");
   		return FS_NO_ERROR;
		}
		else
		{
		   //dbg_print("Not Init\n\r");
			return FS_MSDC_PRESNET_NOT_READY;
		}
	}

   //dbg_print("No card\n\r");
	return FS_MSDC_NOT_PRESENT;
}

/*-----------------------------------*/
static int  GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
   int i = 0;
   kal_uint8 c = gMS.Capacity;
   	
   // get index for MS_MBR
   while((c >>= 1) != 2)
   	i++;	   
   kal_mem_cpy((void*)DiskGeometry,(void*)MS_MBR[i],MS_MBR_SIZE);
	*MediaDescriptor = MSDC_MEDIA_DESCRIPTOR;
	if(gMS.is_wp)
		return FS_WRITE_PROTECTION;	
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  ShutDown(void * DriveData)
{
   return FS_NO_ERROR;
}

static int  HighLevelFormat(void * DriveData)
{
	MSDC_PDNControl(KAL_FALSE);
	MS_API_CheckLogicalAdrsValid();
	MSDC_PDNControl(KAL_TRUE);	
	
	return FS_NO_ERROR;
}

FS_Driver FS_MsDrv = {
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
   HighLevelFormat,
   NULL,
   MSDC_GetCardStatus   
};

#endif // (__MSDC_MS__)


