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
 *   fota.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implement the function of FOTA firmware update downlaod 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************
*   Include File      
********************************************/

#include "fota.h"
#include "custom_fota.h"
#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "fat_fs.h"
#include "DrvFlash.h"

typedef struct {
	kal_uint16		m_manu_id;
	kal_uint16		m_dev_id;
	kal_uint16		m_ext_dev_id1;
	kal_uint16		m_ext_dev_id2;
	kal_uint32		m_fat_begin_addr;
	kal_uint32		m_fat_length;
} FlashDevInfo_ST;

typedef struct {
	kal_char			m_identifier[16];
	kal_char			m_platform_id[128];
	kal_char			m_project_id[64];
	kal_uint16			m_nfb_identifier;
	kal_uint16			m_flash_dev_cnt;
	FlashDevInfo_ST		        m_flash_info[6];
	kal_uint32			m_sb_crc;
	kal_uint32			m_sb_addr;
	kal_uint32			m_sb_length;
	kal_uint32			m_cust_para_addr;
	kal_uint32			m_cust_para_len;
	kal_uint32			m_bit_ctrl;
} MTK_ROMInfo_v05_ST;


#if  defined(__NOR_FDM5__)
   extern NOR_FTL_DATA  FlashDriveData;
#else
   extern NOR_FLASH_DRV_Data  FlashDriveData;
#endif

/*******************************************************************************
 *   Global Function and Structure Definition
 *******************************************************************************/

FOTA_DATA FOTAData={STATUS_FOTA_NOT_INITIAL};

/*******************************************************************************
 *   Static Function and Structure Definition
 *******************************************************************************/
static kal_int32 FOTA_Authentication(void* Header);
static kal_int32 FOTA_MTD_Erase(kal_uint32 BlockIndex);
static kal_int32 FOTA_ComparePlatformID(kal_char* OldId, kal_char* NewId);
static void* FOTA_BlockAddress(kal_uint32 BlockIndex);
static void FOTA_MTD_Program(void * Address, void * Data, kal_uint32 Length);
static kal_int32 FOTA_MTD_Program_Buffer(void *Buffer);
static void FOTA_MTD_WaitEraseDone(void);

extern kal_mutexid fdm_reclaim_mutex;

static void FOTA_LOCK(void)
{
      kal_take_mutex(fdm_reclaim_mutex);
}

static void FOTA_UNLOCK(void)
{
      kal_give_mutex(fdm_reclaim_mutex);
}


/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Initialize
DESCRIPTION
   FOTA Initialization API
   1. Initialize data structure and progress initial step
   2. Register customized authentication function or encryption function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Initialize(void)
{
   extern kal_uint32 INT_RetrieveFlashBaseAddr(void);
   kal_int32 Ret;
   FOTAData.FlashBaseAddr = INT_RetrieveFlashBaseAddr();
   FOTAData.NextBlkOffset = 0;
   FOTAData.BufferIndex = 0;
   if((Ret = FOTA_CustomInitialize()) < 0)
      return Ret;
   else
      FOTAData.Status = STATUS_FOTA_INITIALIZED;
   return ERROR_FOTA_SUCCESS;   
}



/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_WriteData
DESCRIPTION
   FOTA write data API
   1. This function is used to write data to spare image pool
   2. This API only allow sequentially writing mechanism
   3. Authentication mechanism is executed during writing
PARAMETER
   Length: the length of writing (Unit: Bytes)
   Buffer: the start address of buffer
RETURN
   0: means pass write success (ERROR_FOTA_SUCCESS)
   < 0: writing action is fail
      ERROR_FOTA_AUTH_ROMINFO: authentication fail, can't find rom info
      ERROR_FOTA_AUTH_FATBEGIN: authentication fail, fat begin address is different
      ERROR_FOTA_AUTH_FATLEN: authentication fail, fat length is different
      ERROR_FOTA_AUTH_HCHECKSUM: authentication fail, header checksum fail
      ERROR_FOTA_AUTH_ID: authentication fail, platform id is different
      ERROR_FOTA_AUTH_VERSION: authentication fail, downgrade is not allowed
      ERROR_FOTA_AUTH_IMAGELEN: authentication fail, image length too large
	 ERROR_FOTA_AUTH_FAIL: authentication fail before
	 ERROR_FOTA_OVERRANGE: write over the spare image pool range
	 ERROR_FOTA_NOT_INITIALIZED: not call FOTA_Initialize before
--------------------------------------------------------------------------------- */
kal_int32 FOTA_WriteData(kal_uint32 Length, void* Buffer)
{
   kal_int32 result;

   if (FOTAData.Status == STATUS_FOTA_NOT_INITIAL)
      return ERROR_FOTA_NOT_INITIALIZED;
   else if (FOTAData.Status == STATUS_FOTA_AUTH_FAIL)
      return ERROR_FOTA_AUTH_FAIL;
   
   while(Length > 0)
   {

      if ((FOTAData.BufferIndex+Length)>=FOTA_BUFFER_SIZE)
      {
         if(FOTAData.BufferIndex==0)
         {
            result = FOTA_MTD_Program_Buffer((void*)Buffer);
         	  if (result < 0)
               return result;
            Buffer = (void*)((kal_uint32)Buffer + FOTA_BUFFER_SIZE );
            Length -= FOTA_BUFFER_SIZE;
         }
         else
         {
            if(FOTAData.BufferIndex != FOTA_BUFFER_SIZE)
            {
               kal_mem_cpy((void*)&FOTAData.FOTABuffer[FOTAData.BufferIndex/4], Buffer, FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               Buffer = (void*)((kal_uint32)Buffer + (FOTA_BUFFER_SIZE - FOTAData.BufferIndex));
               Length -= (FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               FOTAData.BufferIndex = FOTA_BUFFER_SIZE;
            }
            result = FOTA_MTD_Program_Buffer((void*)FOTAData.FOTABuffer);
         	  if (result < 0)
               return result;
            FOTAData.BufferIndex = 0;
         }
      }
      else
      {
         kal_mem_cpy((void*)&FOTAData.FOTABuffer[FOTAData.BufferIndex/4], Buffer, Length);
         FOTAData.BufferIndex += Length;
         Buffer = (void*)((kal_uint32)Buffer + Length);
         Length = 0;
      }
   }
   return ERROR_FOTA_SUCCESS;   
}


/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Finalize
DESCRIPTION
   FOTA finalization API
   1. compare calculated checksum with image checksum in the header after 
       whole image is written 
   2. mark the status to UPDATE_NEEDED 
PARAMETER
   void
RETURN
   0: means pass error check step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_AUTH_FAIL: authentication fail, final step is not allowed
      ERROR_FOTA_IMAGE_CHECKSUM: image checksum error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Finalize(void)
{
   kal_uint32 UpdateFlag = UPDATE_NEED;
   kal_int32 index,result;
   kal_uint32 ImageChecksum=FOTAData.ImageChecksum;
   kal_uint32 *CheckPtr; 
   kal_uint32 ImageLen = FOTAData.ImageLength;

   if (FOTAData.Status != STATUS_FOTA_AUTH_PASS)
      return ERROR_FOTA_AUTH_FAIL;

   if(FOTAData.BufferIndex != 0)
   {
      result = FOTA_MTD_Program_Buffer((void*)FOTAData.FOTABuffer);
      if (result < 0)
         return result;
   }

   /*check image checksum*/
   CheckPtr = (kal_uint32*)FOTAData.ImageStartAddr;
   for(index=0;index<ImageLen/4;index++)
   {
      ImageChecksum ^= *CheckPtr++;
   }
   if(ImageChecksum != 0)
      return ERROR_FOTA_IMAGE_CHECKSUM;

   FOTA_MTD_Program((void*)(FOTAData.SpareBaseAddr), (void*)&UpdateFlag, sizeof(UpdateFlag));

   FOTAData.Status = STATUS_FOTA_FINAL;
     
   return ERROR_FOTA_SUCCESS;
}

static kal_int32 FOTA_MTD_Erase(kal_uint32 BlockIndex)
{
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data *MtdDataPtr = FlashDriveData.MTDData;
   NOR_MTD_Driver *MtdDriverPtr = FlashDriveData.MTDDriver;
   kal_uint32 TempCurrAddr;

   /*lock*/
   FOTA_LOCK();
   FOTA_MTD_WaitEraseDone();
   TempCurrAddr = (kal_uint32)MtdDataPtr->CurrAddr;
   MtdDataPtr->CurrAddr = FOTA_BlockAddress(BlockIndex);
   MtdDriverPtr->LockEraseBlkAddr(MtdDataPtr, MtdDataPtr->CurrAddr,ACTION_UNLOCK);
   MtdDriverPtr->EraseBlock(MtdDataPtr,BlockIndex);
   MtdDataPtr->CurrAddr =(void*)TempCurrAddr;
   FOTA_UNLOCK();
   /*unlock*/
#else /*__NOR_FDM5__*/
   NOR_MTD_DATA *MtdDataPtr = FlashDriveData.MTDData;
   NOR_MTD_Driver *MtdDriverPtr = FlashDriveData.MTDDriver;

   /*lock*/
   FOTA_LOCK();
   FOTA_MTD_WaitEraseDone();
   MtdDriverPtr->LockEraseBlkAddr(MtdDataPtr, FOTA_BlockAddress(BlockIndex),ACTION_UNLOCK);
   MtdDriverPtr->LockEraseBlkAddr(MtdDataPtr, FOTA_BlockAddress(BlockIndex),ACTION_ERASE);
   FOTA_UNLOCK();
   /*unlock*/

#endif /*__NOR_FDM5__*/

   return 0;
}

static void FOTA_MTD_Program(void * Address, void * Data, kal_uint32 Length)
{
#ifndef __NOR_FDM5__
      NOR_Flash_MTD_Data* MtdDataPtr = (NOR_Flash_MTD_Data*)FlashDriveData.MTDData;
      NOR_MTD_Driver * MtdDriverPtr = (NOR_MTD_Driver *)FlashDriveData.MTDDriver;
      
      FOTA_LOCK();
      FOTA_MTD_WaitEraseDone();
      MtdDriverPtr->ProgramData((void*)MtdDataPtr, Address,Data, Length);
      FOTA_UNLOCK();
#else /*__NOR_FDM5__*/
      NOR_MTD_DATA *MtdDataPtr = FlashDriveData.MTDData;
      NOR_MTD_Driver * MtdDriverPtr = (NOR_MTD_Driver *)FlashDriveData.MTDDriver;
      
      FOTA_LOCK();
      FOTA_MTD_WaitEraseDone();
      MtdDriverPtr->ProgramData((void*)MtdDataPtr, Address,Data, Length);
      FOTA_UNLOCK();
#endif /*__NOR_FDM5__*/
}


static kal_int32 FOTA_MTD_Program_Buffer(void *Buffer)
{
   kal_uint32 i;
   kal_int32 Ret;

   if(FOTAData.SpareCurrAddr == FOTAData.SpareBaseAddr && FOTAData.Status == STATUS_FOTA_INITIALIZED)
   {
         if((Ret=FOTA_Authentication(Buffer))<0)
         {
            FOTAData.Status = STATUS_FOTA_AUTH_FAIL;
            return Ret;
         }
   }
   else if(FOTAData.Status != STATUS_FOTA_AUTH_PASS)
   {
      return ERROR_FOTA_AUTH_FAIL;
   }

   if(FOTAData.Decrypt != (CALLBACK_Auth_FUNC)NULL)
      return FOTAData.Decrypt(Buffer);


#ifndef __INTEL_SIBLEY__
   for(i=0 ; i< FOTA_BUFFER_SIZE; i+=512)
   {

      if(FOTAData.SpareCurrAddr >= FOTAData.NextBlockAddr)
      {
         if (FOTAData.SpareCurrAddr >= FOTAData.TotalFOTALength + FOTAData.SpareBaseAddr)
         {
            FOTAData.Status = STATUS_FOTA_OVERRANGE;
            return ERROR_FOTA_OVERRANGE;
         }
         else
            FOTA_MTD_Erase(FOTAData.NextBlkOffset);
         FOTAData.NextBlkOffset++;
         FOTAData.NextBlockAddr = (kal_uint32)FOTA_BlockAddress(FOTAData.NextBlkOffset);
      }
      FOTA_MTD_Program((void*)(FOTAData.SpareCurrAddr),(void*)((kal_uint32)Buffer+i), 512);      
      FOTAData.SpareCurrAddr += 512;
   }
#else
   for(i=0 ; i< FOTA_BUFFER_SIZE; i+=1024)
   {

      if(FOTAData.SpareCurrAddr >= FOTAData.NextBlockAddr)
      {
         if (FOTAData.SpareCurrAddr >= FOTAData.TotalFOTALength + FOTAData.SpareBaseAddr)
         {
            FOTAData.Status = STATUS_FOTA_OVERRANGE;
            return ERROR_FOTA_OVERRANGE;
         }
         else
            FOTA_MTD_Erase(FOTAData.NextBlkOffset);
         FOTAData.NextBlkOffset++;
         FOTAData.NextBlockAddr = (kal_uint32)FOTA_BlockAddress(FOTAData.NextBlkOffset);
      }
      FOTA_MTD_Program((void*)(FOTAData.SpareCurrAddr), (void*)((kal_uint32)Buffer+i), 1024);

      FOTAData.SpareCurrAddr += 1024;
   }
#endif
   return ERROR_FOTA_SUCCESS;
}

static kal_int32 FOTA_Authentication(void* Header)
{
   
   CompressImageHeader *ImageHeaderPtr = Header;
   FUE_FLAG *FUEFlagPtr = (FUE_FLAG *)Header;
   kal_char *CompareStr = "MTK_ROMINFO_v";
   kal_int32 index=0,Ret;
   kal_bool FindFlag=KAL_FALSE;
   kal_char *StartPosition = (kal_char *) FOTAData.OriginalBaseAddr;
   MTK_ROMInfo_v05_ST *ROMInfoPtr=NULL;
   kal_uint32 Checksum=0,*CheckPtr;

   if(FOTAData.Auth != (CALLBACK_Auth_FUNC)NULL)
      return FOTAData.Auth(Header);

   /*find rom info in original image pool*/
   while((kal_uint32)StartPosition < (1024*1024 + FOTAData.OriginalBaseAddr))
   {
      if(StartPosition[0] == CompareStr[0])
      {
         for(index=1;index<13;index++)
         {
            if(StartPosition[index] != CompareStr[index])
               break;
         }
      }
      if(index==13)
      {
         FindFlag = 1;
         ROMInfoPtr = (MTK_ROMInfo_v05_ST *)StartPosition;
         break;
      }
      else
         StartPosition++;
   }
   if(FindFlag == KAL_FALSE)
   {
      return ERROR_FOTA_AUTH_ROMINFO;
   }
   else
   {
      /*check image header checksum*/
      CheckPtr = (kal_uint32*)ImageHeaderPtr;
      for(index=0;index<sizeof(CompressImageHeader)/4;index++)
      {
            Checksum ^= *CheckPtr++;
      }
      if(Checksum != 0)
         return ERROR_FOTA_AUTH_HCHECKSUM;

      /*check FAT begin address*/
      if(ROMInfoPtr->m_flash_info[0].m_fat_begin_addr != ImageHeaderPtr->FATBeginAddr)
         return ERROR_FOTA_AUTH_FATBEGIN;

      /*check FAT length*/
      if(ROMInfoPtr->m_flash_info[0].m_fat_length != ImageHeaderPtr->FATLength)
         return ERROR_FOTA_AUTH_FATLEN;

      /*check platform id and software version*/
      Ret = FOTA_ComparePlatformID((kal_char*)ROMInfoPtr->m_platform_id,(kal_char*)ImageHeaderPtr->PlatformID);
      if (Ret <0) return Ret;
            
      /*check image size*/
      if (ImageHeaderPtr->ImageLength > FOTAData.TotalFOTALength)
         return ERROR_FOTA_AUTH_IMAGELEN;
   }

      FOTAData.ImageChecksum = ImageHeaderPtr->ImageCheckSum;
      FOTAData.ImageLength = ImageHeaderPtr->ImageLength;

#ifndef __INTEL_SIBLEY__
   FOTAData.ImageStartAddr = ImageHeaderPtr->StartAddr + FOTAData.SpareBaseAddr;
   FUEFlagPtr->UpdateFlag = UPDATE_SKIP;
   FUEFlagPtr->StartAddr = ImageHeaderPtr->StartAddr;
   FUEFlagPtr->ImageLen = ImageHeaderPtr->ImageLength;
#else
   FOTAData.ImageStartAddr = ImageHeaderPtr->StartAddr + FOTAData.SpareBaseAddr + 1024;
   FUEFlagPtr->UpdateFlag = UPDATE_SKIP;
   FUEFlagPtr->StartAddr = ImageHeaderPtr->StartAddr + 1024;
   FUEFlagPtr->ImageLen = ImageHeaderPtr->ImageLength;
   FOTA_MTD_Erase(FOTAData.NextBlkOffset);
   FOTAData.NextBlkOffset++;
   FOTAData.NextBlockAddr = (kal_uint32)FOTA_BlockAddress(FOTAData.NextBlkOffset);
   FOTA_MTD_Program((void*)(FOTAData.SpareCurrAddr),(void*)FUEFlagPtr, sizeof(FUE_FLAG));
   FOTAData.SpareCurrAddr += 1024;
#endif

   FOTAData.Status = STATUS_FOTA_AUTH_PASS;
   
   return ERROR_FOTA_SUCCESS;
}

static void * FOTA_BlockAddress(kal_uint32 BlockOffset)
{
   kal_uint32 addr  = 0;
   kal_uint32 region = 0, BlockUpperBound = 0, BlockIndex = BlockOffset;

   BlockIndex += FOTAData.SpareStartBlkIndex;

   BlockUpperBound = FOTAData.NORRegionInfo[0].RegionBlocks;
  
   while(BlockUpperBound <= BlockIndex)
   {
      addr += FOTAData.NORRegionInfo[region].RegionBlocks * FOTAData.NORRegionInfo[region].BlockSize;
      region++;
      BlockUpperBound += FOTAData.NORRegionInfo[region].RegionBlocks;
   }
   addr += (BlockIndex - (BlockUpperBound-FOTAData.NORRegionInfo[region].RegionBlocks)) * FOTAData.NORRegionInfo[region].BlockSize;

   return (void*)(addr + FOTAData.FlashBaseAddr);
}

kal_uint32 FOTA_StringToValue(kal_char* String)
{
   kal_uint32 Value=0;
   kal_uint32 Temp;
   while(*String>='0' && *String<='9')
   {
      Temp = *String++ - '0';
      Value = Value*10 + Temp;
   }
   return Value;
}

static kal_int32 FOTA_ComparePlatformID(kal_char* OldId, kal_char* NewId)
{
   kal_uint32 OldIndex=0,NewIndex=0;
   kal_uint32 OldValue, NewValue;
   while( (OldId[OldIndex] != '.') && (NewId[NewIndex] !='.'))
   {
      if (OldId[OldIndex++] != NewId[NewIndex++])
      {
         return ERROR_FOTA_AUTH_ID;
      }
   }
   while((OldId[OldIndex] != 'W')&&(OldId[OldIndex] != 'w'))
   {
      OldIndex++;
   }
   while((NewId[NewIndex] != 'W' )&&(NewId[NewIndex] != 'w' ))
   {
      NewIndex++;
   }
   NewIndex++;OldIndex++;
   OldValue = FOTA_StringToValue(&OldId[OldIndex]);
   NewValue = FOTA_StringToValue(&NewId[NewIndex]);
   if(NewValue < OldValue)
      return ERROR_FOTA_AUTH_VERSION;
   while(OldId[OldIndex] != '_')
   {
      OldIndex++;
   }
   while(NewId[NewIndex] != '_' )
   {
      NewIndex++;
   }
   NewIndex++;OldIndex++;
   OldValue = FOTA_StringToValue(&OldId[OldIndex]);
   NewValue = FOTA_StringToValue(&NewId[NewIndex]);
   if(NewValue < OldValue)
      return ERROR_FOTA_AUTH_VERSION;
   return ERROR_FOTA_SUCCESS;
   
}

void FOTA_Reg_Auth(CALLBACK_Auth_FUNC Auth)
{
   FOTAData.Auth = Auth;
}

void FOTA_Reg_Decrypt(CALLBACK_Decrypt_FUNC Decrypt)
{
   FOTAData.Decrypt= Decrypt;
}


static void FOTA_MTD_WaitEraseDone(void)
{
#ifndef __NOR_FDM5__
   extern kal_bool INT_QueryExceptionStatus(void);
   NOR_MTD_Driver *MtdDriverPtr = FlashDriveData.MTDDriver;
   kal_uint32 frame_tick = FOTA_FRAME_TICK;
   NOR_Flash_MTD_Data *MtdDataPtr = FlashDriveData.MTDData;
   

   /* Typical erase time = 700ms */
   /* Typical frame_tick = 70 * 4.6ms = 322ms */

   if(FlashDriveData.ReclaimBlockID == INVALID_BLOCK_INDEX)
      return;
   while(MtdDriverPtr->CheckDeviceReady(MtdDataPtr, FlashDriveData.ReclaimBlockID) != FS_NO_ERROR)
   {
      if(INT_QueryExceptionStatus() == KAL_FALSE)
      {
         /* This procedure should only be activated in normal mode */
         kal_sleep_task(frame_tick);
         frame_tick = frame_tick >> 1;
         if(frame_tick < 2)
            frame_tick = 2;
      }
   }
   return;

#else /*__NOR_FDM5__*/
   extern kal_bool INT_QueryExceptionStatus(void);
   NOR_MTD_Driver *MtdDriverPtr = FlashDriveData.MTDDriver;
   kal_uint32 frame_tick = FOTA_FRAME_TICK;
   NOR_MTD_DATA *MtdDataPtr = FlashDriveData.MTDData;

   while(FlashDriveData.NeedResumeFlag== KAL_FALSE && FlashDriveData.ErasingPhyBlk != INVALID_BLOCK_ID)
   {
      if(MtdDriverPtr->CheckDeviceReady(MtdDataPtr, FlashDriveData.ErasingPhyBlk) == FS_NO_ERROR)
         break;
      if(INT_QueryExceptionStatus() == KAL_FALSE)
      {
         /* This procedure should only be activated in normal mode */
         kal_sleep_task(frame_tick);
         frame_tick = frame_tick >> 1;
         if(frame_tick < 2)
            frame_tick = 2;
      }
   }
   return;
   
#endif /*__NOR_FDM5__*/
}

