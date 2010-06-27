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
 *   mspro_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Adaption driver of file system for MS-Pro
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************
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
#include "mspro_def.h"

extern void GPTI_BusyWait(kal_uint16 len);

#if defined(__MSDC_MSPRO__)
#define SECTOR_SIZE 512	
#define MSDC_MEDIA_DESCRIPTOR		0xF8
#define MAX_TRY	2

static int  DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors)
{
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	MSP_STATUS status;
	kal_uint8 retry = 0;
	kal_uint16 read; 

	gMSDC_Handle->timeout_count = 0;	
start:
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Read but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_READ_SECTOR_ERROR;
	}
	MSDC_PDNControl(KAL_FALSE);
	status = MSP_CMD_ReadWriteData(Sector,Sectors,(kal_uint32*)Buffer,&read,MSP_READ);
	if(status != MSP_NOERROR)
		goto err_exit;
	
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
   
err_exit:
	if(retry++ <= MAX_TRY && kal_query_systemInit()== KAL_FALSE)
	{
		gMSP.is_failed = KAL_TRUE;
		if(status == MSP_ERR_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:re-mount(read fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(MSP_Initialize() != MSP_NOERROR)
				return FS_MSDC_READ_SECTOR_ERROR;
		}		
		
		//dbg_print("read sector failed! retry: %d \r\n",retry);	
		goto start;
	}	
	MSDC_PDNControl(KAL_TRUE);	
	return FS_MSDC_READ_SECTOR_ERROR   ;
}

/*-----------------------------------*/
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	MSP_STATUS status;
	kal_uint8 retry = 0;
	kal_uint16 write;

	gMSDC_Handle->timeout_count = 0;	
start:
	if(!gMSDC_Handle->mIsInitialized)
	{
		//dbg_print("Read but not Initialized \r\n");
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_READ_SECTOR_ERROR;
	}
	MSDC_PDNControl(KAL_FALSE);
	status = MSP_CMD_ReadWriteData(Sector,Sectors,(kal_uint32*)Buffer,&write,MSP_WRITE);
	if(status != MSP_NOERROR)
		goto err_exit;
	
	MSDC_PDNControl(KAL_TRUE);
   return FS_NO_ERROR;
   
err_exit:
	if(retry++ <= MAX_TRY && kal_query_systemInit()== KAL_FALSE)
	{
		gMSP.is_failed = KAL_TRUE;
		if(status == MSP_ERR_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count == 3 && gMSDC_Handle->mIsPresent == KAL_TRUE)
		{
			kal_print("[MSDC]:re-mount(write fail)");
			gMSDC_Handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(MSP_Initialize() != MSP_NOERROR)
				return FS_MSDC_READ_SECTOR_ERROR;
		}		
		//dbg_print("write sector failed! retry: %d \r\n",retry);	
		goto start;
	}	
	MSDC_PDNControl(KAL_TRUE);	
	return FS_MSDC_WRITE_SECTOR_ERROR   ;
}

/*-----------------------------------*/
static int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags)
{		  
	if(gMSDC_Handle->mIsInitialized)
		return SECTOR_SIZE;
	gMSP.is_failed = KAL_FALSE;

start:		
	if(!gMSDC_Handle->mIsPresent)
	{
		MSDC_PDNControl(KAL_TRUE);
		return FS_MSDC_MOUNT_ERROR;
	}	
	MSDC_PDNControl(KAL_FALSE);
	MSP_POWER_ON();
	if(MSP_Initialize() != MSP_NOERROR)
	{		
		goto err_exit;
	}	
		
	MSDC_PDNControl(KAL_TRUE);
   return SECTOR_SIZE;
   
err_exit:
	MSP_POWER_OFF();
	/*
	if(retry++ <= 1)
	{		
		gMSP.is_failed = KAL_TRUE;
		goto start;
	}
	*/
	gMSP.is_failed = KAL_TRUE;
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
   kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);

   DiskGeometry->Sectors = gMSP.user_block*gMSP.block_size;
   //DiskGeometry->Sectors = gSD.mBKNum;
   // 0xF8 is the standard value for fixed media, 0xF0 is for removable media.
   // The important point is whatever value is put in here must also be put in the first
   // byte of he FAT[0].
	*MediaDescriptor = MSDC_MEDIA_DESCRIPTOR;
   if(gMSP.is_wp)
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
	MSP_STATUS status;

	if(!gMSDC_Handle->mIsInitialized)
		return FS_MSDC_FORMAT_ERROR;
	MSDC_PDNControl(KAL_FALSE);
	status = MSP_CMD_Format(MSP_FULL,NULL);
	MSDC_PDNControl(KAL_TRUE);
	if(status)
		return FS_MSDC_FORMAT_ERROR;
	
	return FS_NO_ERROR;
}

FS_Driver FS_MspDrv = {
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
#endif //__MSDC_MSPRO__


