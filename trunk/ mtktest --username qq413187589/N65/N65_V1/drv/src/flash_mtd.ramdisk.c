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
 *    flash_mtd.ramdisk.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for ramdisk series devices.
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
 *============================================================================

/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "flash_opt.h"
#include "flash_mtd.h"

#ifdef __RAMDISK__

/* ************************************************************
         RAMDISK MTD Flash Driver
   ************************************************************ */


#define SIZE_2MB	2097152
#define SIZE_1MB	1048576
#define SIZE_512KB	524288
#define SIZE_256KB	262144

#define RAM_SIZE	SIZE_256KB

static kal_uint8 ram_disk[RAM_SIZE];

static int MountDevice_RAM(void * DriveData, void *Info)
{
   NOR_Flash_MTD_Data * D = DriveData;
   NOR_MTD_FlashInfo * FlashInfo=Info;
   kal_uint32 i, MaxBlockSize = 0;

   i = 0;
   D->BaseAddr = (kal_uint8 *)ram_disk;
   kal_mem_set((kal_uint8 *)(ram_disk), 0xFF, RAM_SIZE);
   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;

      if(D->RegionInfo[i].BlockSize > MaxBlockSize)
         MaxBlockSize = D->RegionInfo[i].BlockSize;
      i++;
   }
   FlashInfo->ActualRegionNum = i;
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ShutDown_RAM(void * DriveData)
{
   NOR_Flash_MTD_Data * D = DriveData;

   D->CurrAddr = NULL;
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int EraseBlock_RAM(void * DriveData, kal_uint32 BlockIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 region = 0, BlockUpperBound = 0;

   BlockUpperBound = D->RegionInfo[0].RegionBlocks;
   while(BlockUpperBound <= BlockIndex)
   {
      region++;
      BlockUpperBound += D->RegionInfo[region].RegionBlocks;
   }
#ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
#endif

   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

   kal_mem_set((kal_uint8 *)(D->CurrAddr), 0xFF, D->RegionInfo[region].BlockSize);

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ProgramData_RAM(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   NOR_Flash_MTD_Data *D = DriveData;

   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

   #ifdef DEBUG
   //can't write zero bytes into flash
   ASSERT(Length != 0);
   #endif

   switch (Length)
   {
      case sizeof(FLASH_CELL):
         #if defined(DEBUG)
            //Misaligned write into flash
            ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         #endif

         #ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!(~((volatile FLASH_CELL*)Address)[0] & ((FLASH_CELL*)Data)[0]));
         #endif

         ((volatile FLASH_CELL*)Address)[0] = ((FLASH_CELL*)Data)[0];
         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (void*) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

         #ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!((~fp[0]) & Cell))
         #endif

         fp[0]     = Cell;
      }
      break;
   default:
      #ifdef DEBUG
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         //Misaligned length write into flash
         ASSERT(!(Length % sizeof(FLASH_CELL)));
      #endif
      #ifdef DEBUG
      {
         kal_uint32 i;
         volatile FLASH_CELL *fp = (void*) Address;
         FLASH_CELL * V = Data;

         for (i=0; i<Length/sizeof(FLASH_CELL); i++)
            ASSERT(!((~fp[i]) & V[i]));//Attempt to set bits in flash!
      }
      #endif

      {
         kal_uint32 i, j;
         volatile FLASH_CELL *fp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;

            j = 0;
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];
               fp[i] = Cell;
            }
         }
         else
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;

            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               fp[i] = dp[i];
            }
         }
      }
      break;
   }
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int NonBlockEraseBlock_RAM(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
   ASSERT(0);
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int CheckDeviceReady_RAM(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int SuspendErase_RAM(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   ASSERT(0);
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ResumeErase_RAM(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   ASSERT(0);
   return FS_NO_ERROR;
}

/*-----------------------------------*/
NOR_MTD_Driver DriverName =
{
   MountDevice_RAM,
   ShutDown_RAM,
   MapWindow,
   EraseBlock_RAM,
   ProgramData_RAM,
   NonBlockEraseBlock_RAM,
   CheckDeviceReady_RAM,
   SuspendErase_RAM,
   ResumeErase_RAM
};

#endif //__RAMDISK__