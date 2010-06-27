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
 *    flash_mtd.renesas.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for renesas series devices.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/********************************************************/
/*                  Include Header Files                */
/********************************************************/
#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "flash_mtd.h"

#ifdef __RENESAS_SERIES_NOR__

/* ************************************************************
         RENESAS NOR FLASH MTD Flash Driver
   ************************************************************ */
   
/* Support RENESAS-series Page Buffer Program */
#ifdef __PAGE_BUFFER_PROGRAM__
   extern kal_uint32 PAGE_BUFFER_SIZE;
#endif

#ifdef __RENESAS_64M__

{\
   fp[0] = 0x60;\
   fp[0] = (((kal_uint32)D->CurrAddr >> 16)& (~(1<<7))) ;\
   fp[0] = 0xAC;\
   fp[0] = ((~((kal_uint32)D->CurrAddr >> 16))& (~(1<<7))) ;\
   fp[0] = 0x7B;\
}

#else

#define UNLOCK_COMMAND \
{\
   fp[0] = 0x60;\
   fp[0] = ((kal_uint32)D->CurrAddr >> 16);\
   fp[0] = 0xAC;\
   fp[0] = (~((kal_uint32)D->CurrAddr >> 16));\
   fp[0] = 0x7B;\
}
#endif


static int CheckDeviceReady_RENESAS(void * DriveData, kal_uint32 BlockIndex);

#ifndef __NOR_FDM5__
static int MountDevice_RENESAS(void * DriveData, void *Info)
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 i=0;

   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
      i++;
   }
   FlashInfo->ActualRegionNum = i;

   return FS_NO_ERROR;
}
#else
static int MountDevice_RENESAS(void * DriveData, void *Info)
{
   NOR_MTD_DATA * D = DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   kal_uint32 TotalPhysicalPages;
   kal_uint32 TblEntryShift=0,j=1;

   // check and assign D->LayoutInfo
   TotalPhysicalPages = (Layout->BlkSize)/(Layout->PageSize)*(Layout->TotalBlks);
   j = TotalPhysicalPages;
   while(j<TotalPhysicalPages)
   {
      j = j << 1;
      TblEntryShift++;
   }
   TblEntryShift = TblEntryShift>>1;
   if((TblEntryShift) >8)
	   TblEntryShift=8;
   Layout->TblEntrys = 1<<TblEntryShift;

   if ( (Layout->TblEntrys * Layout->TotalLSMT) < TotalPhysicalPages)
      ASSERT(0);

   return FS_NO_ERROR;
}
#endif

/*-----------------------------------*/
void WaitReady_RENESAS(kal_uint32 addr,kal_uint16 data)//Validate!!
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;

   data_cache_id = INT_DisableDataCache();

   while(1)
   {
      *(volatile kal_uint16*)addr = 0x70;
      stat_data = *(volatile kal_uint16*)addr;
      if(stat_data & 0x80)
         break;
   }
   /* Clear status register */
   *(volatile kal_uint16*)addr = 0x50;
   /* Return to read mode */
   *(volatile kal_uint16*)addr = 0xFF;

   INT_RestoreDataCache(data_cache_id);

   if(data == 0)
   {
      /* Program */
      if (stat_data & 0x10)
         ASSERT(0);
   }else{
      /* Erase */
      if (stat_data & 0x28)
         ASSERT(0);
   }
}

/*-----------------------------------*/
#ifndef __NOR_FDM5__
static int ShutDown_RENESAS(void * DriveData)
{
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr;

   WaitReady_RENESAS((kal_uint32)fp, 1);

   D->CurrAddr = NULL;
   return FS_NO_ERROR;
}
#else
static int ShutDown_RENESAS(void * DriveData)
{
   return FS_NO_ERROR;
}
#endif
/*-----------------------------------*/
static int EraseBlock_RENESAS(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif


   savedMask = SaveAndSetIRQMask();
   //Erase command
   UNLOCK_COMMAND;

   fp[0] = 0x20;
   fp[0] = 0xD0;
   RestoreIRQMask(savedMask);

   WaitReady_RENESAS((kal_uint32)fp, 1);

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ProgramData_RENESAS(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
    kal_uint32 savedMask;
    volatile FLASH_CELL *fp; 
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   switch (Length)
   {
      case 1:
         {
            kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*) &Cell;

            fp = (FLASH_CELL*) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
            Cell = fp[0];

            b[ofs] = ((kal_uint8*)Data)[0];

            savedMask = SaveAndSetIRQMask();
            UNLOCK_COMMAND;

            fp[0] = 0x40;
            fp[0] = Cell;
            RestoreIRQMask(savedMask);
            WaitReady_RENESAS((kal_uint32)Address, 0);
         }
         break;

      case 512:
         {
            kal_uint32 i, j, k;

            fp = (volatile FLASH_CELL *)Address;
            if((((kal_uint32)Data) & (sizeof(FLASH_CELL)-1)))// Data address is not word-aligned
            {
               kal_uint8 *bdp =  (kal_uint8*)Data;
               FLASH_CELL Cell;
               kal_uint8 *b = (kal_uint8*)&Cell;

               j = 0;

#ifndef __PAGE_BUFFER_PROGRAM__      // word program

               for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
               {
                  b[0] = bdp[j++];
                  b[1] = bdp[j++];
                  savedMask = SaveAndSetIRQMask();
                  UNLOCK_COMMAND;

                  fp[i] = 0x40;
                  fp[i] = Cell;
                  RestoreIRQMask(savedMask);
                  WaitReady_RENESAS((kal_uint32)&fp[i], 0);
               }

#else // page buffer program
               for(i = 0; i < (Length/sizeof(FLASH_CELL));)
               {
                  k = i+ PAGE_BUFFER_SIZE;
                  for(; i < k ; i++)
                  {
                     b[0] = bdp[j++];
                     b[1] = bdp[j++];
                     savedMask = SaveAndSetIRQMask();
                     UNLOCK_COMMAND;
                     fp[i] = 0x74;
                     fp[i] = Cell;         // fill data to device buffer
                     RestoreIRQMask(savedMask);
                  }
                  savedMask = SaveAndSetIRQMask();
                  UNLOCK_COMMAND;
                  fp[i-1] = 0x0E;
                  fp[i-1] = 0xD0;
                  RestoreIRQMask(savedMask);
                  WaitReady_RENESAS((kal_uint32)&fp[i-PAGE_BUFFER_SIZE], 0);
               }  
#endif
            }
            else   // Data address is word-aligned
            {
               FLASH_CELL *dp = (FLASH_CELL*)Data;

#ifndef __PAGE_BUFFER_PROGRAM__      // word program
               for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
               {
                  savedMask = SaveAndSetIRQMask();
                  UNLOCK_COMMAND;
                  fp[i] = 0x40;
                  fp[i] = dp[i];
                  RestoreIRQMask(savedMask);
                  WaitReady_RENESAS((kal_uint32)&fp[i], 0);
               }  
#else // page buffer program
               for(i = 0; i < (Length/sizeof(FLASH_CELL));)
               {
                  k = i + PAGE_BUFFER_SIZE;
		  for(; i < k; i++)
                  {
                     savedMask = SaveAndSetIRQMask();
                     UNLOCK_COMMAND;
                     fp[i] = 0x74;
                     fp[i] = dp[i];         // fill data to device buffer
                     RestoreIRQMask(savedMask);
                  }
                  savedMask = SaveAndSetIRQMask();
                  UNLOCK_COMMAND;
                  fp[i-1] = 0x0E;
                  fp[i-1] = 0xD0;
                  RestoreIRQMask(savedMask);
                  WaitReady_RENESAS((kal_uint32)&fp[i-PAGE_BUFFER_SIZE], 0);
               }  
#endif
            }
         }
         break;

      default:
         {
            kal_uint32 i;

            fp = (FLASH_CELL*)Address;
            for(i = 0; i < (Length/sizeof(FLASH_CELL)); i++)
            {
               savedMask = SaveAndSetIRQMask();
               UNLOCK_COMMAND;

               fp[i] = 0x40;
               fp[i] = ((FLASH_CELL*)Data)[i];
               RestoreIRQMask(savedMask);
               WaitReady_RENESAS((kal_uint32)Address, 0);
            }
         }
         break;
   }
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int NonBlockEraseBlock_RENESAS(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   savedMask = SaveAndSetIRQMask();
   //Erase command
   UNLOCK_COMMAND;

   fp[0] = 0x20;
   fp[0] = 0xD0;
   RestoreIRQMask(savedMask);

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int CheckDeviceReady_RENESAS(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id; 
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif


   data_cache_id = INT_DisableDataCache();

   fp[0] = 0x70;
   stat_data = fp[0];
   fp[0] = 0xFF;
   INT_RestoreDataCache(data_cache_id);
   if(stat_data & 0x80)
   {
      /* Clear Status Register */
      fp[0] = 0x50;
      if(stat_data & 0x28)
      {
         ASSERT(0);
      }
      else
      {
         return FS_NO_ERROR;
      }
   }
   else
   {
      return FS_FLASH_ERASE_BUSY;
   }
}

/*-----------------------------------*/
static int SuspendErase_RENESAS(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   FLASH_CELL s = 0;
   kal_uint32 data_cache_id;
   
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#endif   

   data_cache_id = INT_DisableDataCache();

   fp[0] = 0xB0;

   fp[0] = 0x70;
   s = fp[0];
   while(!(s&0x80))
   {
      fp[0] = 0x70;
      s = fp[0];
   }
   fp[0] = 0xFF;

   INT_RestoreDataCache(data_cache_id);
   
#ifdef _LOW_COST_SINGLE_BANK_FLASH_  
   RestoreIRQMask(savedMask);
#endif    
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ResumeErase_RENESAS(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   fp[0] = 0xD0;

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int LockEraseBlkAddr_RENESAS(void * DriveData, void *BlkAddr,UINT ACTION)
{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) BlkAddr;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   if(ACTION == ACTION_UNLOCK)
   {
      return 0;
   }
   else if(ACTION== ACTION_LOCK)
   {
      return 0;
   }
   else if (ACTION== ACTION_ERASE)
   {
      savedMask = SaveAndSetIRQMask();
      //Erase command
      UNLOCK_COMMAND;

      fp[0] = 0x20;
      fp[0] = 0xD0;
      RestoreIRQMask(savedMask);
      WaitReady_RENESAS((kal_uint32)fp, 1);
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}

/*-----------------------------------*/

NOR_MTD_Driver DriverName =
{
   MountDevice_RENESAS,
   ShutDown_RENESAS,
   MapWindow,
   EraseBlock_RENESAS,
   ProgramData_RENESAS,
   NonBlockEraseBlock_RENESAS,
   CheckDeviceReady_RENESAS,
   SuspendErase_RENESAS,
   ResumeErase_RENESAS,
   NULL,
   NULL,
   NULL,
   LockEraseBlkAddr_RENESAS
};

#endif  //__RENESAS_SERIES_NOR__