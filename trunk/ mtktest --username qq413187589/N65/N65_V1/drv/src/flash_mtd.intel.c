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
 *    flash_mtd.intel.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for INTEL series devices.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "flash_mtd.h"
#include "reg_base.h"


#ifdef __INTEL_SERIES_NOR__

/* ************************************************************
         INTEL NOR FLASH MTD Flash Driver
   ************************************************************ */

#define UNLOCK_COMMAND(a) \
           {\
              fp[a] = INTEL_CMD_LOCK_SETUP;\
              fp[a] = INTEL_CMD_UNLOCK;\
              fp[a] = INTEL_CMD_RD_ARRAY;}

#define LOCK_COMMAND(a) \
           {\
              fp[a] = INTEL_CMD_LOCK_SETUP;\
              fp[a] = INTEL_CMD_LOCK;\
              fp[a] = INTEL_CMD_RD_ARRAY;}

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(_LOW_COST_SINGLE_BANK_FLASH_))
#ifdef __MTK_TARGET__
   #pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */
#endif 

/* Support INTEL-series Page Buffer Program */
#ifdef __PAGE_BUFFER_PROGRAM__
   extern kal_uint32 PAGE_BUFFER_SIZE;
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

extern kal_bool NOR_FLASH_BUSY; /*should be modified only when I-bit is disabled*/
extern kal_bool NOR_FLASH_SUSPENDED; /*should be modified only when I-bit is disabled*/

#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/


static int CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex);

#ifndef __NOR_FDM5__
static int MountDevice_INTEL(void * DriveData,void *Info )
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 i=0;
   // for unlock block
   kal_uint32 block;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
   kal_uint32 TotalSize_Block = 0;
   kal_uint32 TotalSize_Bank = 0;
#endif


   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
      TotalSize_Block += D->RegionInfo[i].BlockSize * D->RegionInfo[i].RegionBlocks;
#endif
      i++;
   }
   FlashInfo->ActualRegionNum = i;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)

   /*check customization */
   i=0;
   while(D->BankInfo[i].BankSize != 0)
   {
      TotalSize_Bank += D->BankInfo[i].BankSize * D->BankInfo[i].Banks;
      i++;
   }
   EXT_ASSERT(TotalSize_Bank==TotalSize_Block,0,0,0);   
   
#endif    

   /* unlock all blocks */
   for(block=0; block<FlashInfo->TotalBlocks; block++)
   {
      D->CurrAddr = BlockAddress(D, block);
      fp = (volatile FLASH_CELL *) D->CurrAddr;

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   return FS_NO_ERROR;
}

#endif


static void DelayAWhile_SIB(kal_uint32 Delay)
{
   
   volatile kal_uint32 CurrentTime,StartTime;
   
   StartTime = INT_GetCurrentTime(); //32KHz Fregquency Counter
   
   if(Delay != 0)
   {
       while(1)
       {
          CurrentTime = INT_GetCurrentTime();
          if(StartTime > CurrentTime)
          {
             if (CurrentTime> Delay)
                break;
          }
          else if ((CurrentTime-StartTime)>(Delay))
             break;
       }
   }
   while(1)
   {
      CurrentTime = INT_GetCurrentTime();
      if(StartTime != CurrentTime)
         break;
   }
   
   return;
}

/*-----------------------------------*/
void WaitReady_SIB(kal_uint32 addr,kal_uint16 wait_method,kal_uint32 Delay)
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;

   data_cache_id = INT_DisableDataCache();

   DelayAWhile_SIB(Delay);
   
   while(1)
   {
      DelayAWhile_SIB(0);
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
      stat_data = *(volatile kal_uint16*)addr;
      if(stat_data & INTEL_READY_FLAG)
         break;
   }
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);

   if(wait_method == INTEL_WAIT_PROGRAM)
   {
      /* Program */
      if (stat_data & INTEL_PROGRAM_ERROR_FLAG)
         ASSERT(0);
   }else if (wait_method == INTEL_WAIT_ERASE) {
      /* Erase */
      if (stat_data & INTEL_ERASE_ERROR_FLAG)
         ASSERT(0);   
   }else{
      /* Sibley Blank Check */ 
      return;
   }
}


/*-----------------------------------*/
void WaitReady_INTEL(kal_uint32 addr,kal_uint16 wait_method)
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;

   data_cache_id = INT_DisableDataCache();

   while(1)
   {
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
      stat_data = *(volatile kal_uint16*)addr;
      if(stat_data & INTEL_READY_FLAG)
         break;
   }
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);

   if(wait_method == INTEL_WAIT_PROGRAM)
   {
      /* Program */
      if (stat_data & INTEL_PROGRAM_ERROR_FLAG)
         ASSERT(0);
   }else if (wait_method == INTEL_WAIT_ERASE) {
      /* Erase */
      if (stat_data & INTEL_ERASE_ERROR_FLAG)
         ASSERT(0);   
   }else{
      /* Sibley Blank Check */ 
      return;
   }
}

static int LockEraseBlkAddr_INTEL(void * DriveData, void *BlkAddr,UINT ACTION)
{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) BlkAddr;

   if(ACTION == ACTION_UNLOCK)
   {
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   else if(ACTION== ACTION_LOCK)
   {
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      LOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( !(fp[2] & INTEL_BLOCK_LOCK_FLAG))
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   else if (ACTION== ACTION_ERASE)
   {
      savedMask = SaveAndSetIRQMask();
      //Erase command
      fp[0] = INTEL_CMD_ERASE_SETUP;
      fp[0] = INTEL_CMD_ERASE_CONFIRM;
   
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
      WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
      RestoreIRQMask(savedMask);
#else
      RestoreIRQMask(savedMask);
      WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
#endif      
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}


/*-----------------------------------*/
#ifndef __NOR_FDM5__
static int ShutDown_INTEL(void * DriveData)
{
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr;
   
#ifndef __INTEL_SIBLEY__
   WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
#else
   kal_uint32 region = 0;

   while(D->RegionInfo[region].RegionBlocks != 0)
   {
      WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
      fp += D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;
      region++;
   }
#endif

   D->CurrAddr = NULL;
   return FS_NO_ERROR;
}
#endif

/*-----------------------------------*/
static int EraseBlock_INTEL(void * DriveData, kal_uint32 BlockIndex)
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
   fp[0] = INTEL_CMD_ERASE_SETUP;
   fp[0] = INTEL_CMD_ERASE_CONFIRM;
   
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
   WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
   RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
   #if defined(MT6205B)
   if(kal_query_systemInit() || INT_QueryExceptionStatus())
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_INTEL(DriveData, BlockIndex));
   else
   {
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_INTEL(DriveData, BlockIndex))
      {
         savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[0]);
      }
   }
   #else
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady_INTEL(DriveData, BlockIndex) );
   #endif /* MT6205B */

   #if defined(MT6205B)
   RestoreIRQMask(savedMask);
   #endif   
#else
   RestoreIRQMask(savedMask);
   WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
#endif   
   return FS_NO_ERROR;
}

/*-----------------------------------*/
extern volatile kal_uint32 processing_irqCnt;
void CompareData(void * Address, void * Data, kal_uint32 Length)
{
    kal_uint32 i;

    if((kal_uint32)Address&0x3==0 && (kal_uint32)Data&0x3==0)
    {
       kal_uint32* Source = (kal_uint32*)Address;
       kal_uint32* Dest = (kal_uint32*)Data;
       for(i=0;i<(Length>>2);i++)
       {
          if(Source[i] != Dest[i])
             ASSERT(0); 
       }
    }
    else if((kal_uint32)Address&0x1==0 && (kal_uint32)Data&0x1==0)
    {
       kal_uint16* Source = (kal_uint16*)Address;
       kal_uint16* Dest = (kal_uint16*)Data;
       for(i=0;i<(Length>>1);i++)
       {
          if(Source[i] != Dest[i])
             ASSERT(0); 
       }
    }
    else
    {
       kal_uint8* Source = (kal_uint8*)Address;
       kal_uint8* Dest = (kal_uint8*)Data;
       for(i=0;i<Length;i++)
       {
          if(Source[i] != Dest[i])
             ASSERT(0); 
       }
    }
}

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))

/* ------------------------------------------------------------------ */
kal_int32 CheckReadyAndResume_INTEL(kal_uint32 addr,kal_uint16 data) /* for program operation only */
{
   kal_uint32 data_cache_id;
   static kal_uint16 check_data = 0;
   //static kal_uint16 toggle_data = 0;
   kal_uint32 savedMask;
   kal_int32   status = RESULT_FLASH_BUSY;

   #ifndef MT6205B
   savedMask = SaveAndSetIRQMask();
   #endif


   if(NOR_FLASH_SUSPENDED)
   {
      #if !defined(__PRODUCTION_RELEASE__)
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr);
      #endif
      *(volatile kal_uint16*)addr = INTEL_CMD_RESUME;
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
      NOR_FLASH_SUSPENDED = KAL_FALSE;
   }

   data_cache_id = INT_DisableDataCache();

   *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;   
   check_data = *(volatile kal_uint16*)addr;
   if(check_data & INTEL_READY_FLAG)
   {
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;
      check_data = *(volatile kal_uint16*)addr;
      SNOR_MTD_ASSERT(check_data == data, addr,check_data, data);
      NOR_FLASH_BUSY = KAL_FALSE;
      status = RESULT_FLASH_DONE;
   }

   INT_RestoreDataCache(data_cache_id);

   #ifndef MT6205B
   RestoreIRQMask(savedMask);
   #endif

   return status;
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


#ifndef __INTEL_SIBLEY__
static int ProgramData_INTEL(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_uint32 savedMask;
   kal_uint32  restore_value;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_int32 result = RESULT_FLASH_BUSY;
#endif
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));   
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if  (defined(_LOW_COST_SINGLE_BANK_FLASH_) && defined(MT6205B))   
   //disable code cache prefetch
   restore_value = *(kal_uint32 *)(0x80010030);
   *(kal_uint32 *)(0x80010030) &= ~(0x2);
#endif

   switch (Length)
   {
      case sizeof(FLASH_CELL):
         savedMask = SaveAndSetIRQMask();
         ((volatile FLASH_CELL*)Address)[0] = INTEL_CMD_PGM_WORD;
         ((volatile FLASH_CELL*)Address)[0] = ((FLASH_CELL*)Data)[0];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_INTEL((kal_uint32)Address, INTEL_WAIT_PROGRAM);         
         RestoreIRQMask(savedMask);         
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            while(!CheckReadyAndResume_INTEL((kal_uint32)Address, *(kal_uint16*)Data));
         }
         else
         {
            while(!CheckReadyAndResume_INTEL((kal_uint32)Address, *(kal_uint16*)Data))
            {
               savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)Address);
            }
         }
         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);
         while(!CheckReadyAndResume_INTEL((kal_uint32)Address, *(kal_uint16*)Data));

         #endif /* MT6205B */
#else
         RestoreIRQMask(savedMask);
         WaitReady_INTEL((kal_uint32)Address, INTEL_WAIT_PROGRAM);
#endif         
         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (FLASH_CELL*) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

         savedMask = SaveAndSetIRQMask();
         fp[0] = INTEL_CMD_PGM_WORD;
         fp[0] = Cell;         
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_PROGRAM);
         RestoreIRQMask(savedMask);         
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            while(!CheckReadyAndResume_INTEL((kal_uint32)fp, (kal_uint16)Cell));
         }
         else
         {
            while(!CheckReadyAndResume_INTEL((kal_uint32)fp, (kal_uint16)Cell))
            {
               savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)fp);
            }
         }

         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);
         while(!CheckReadyAndResume_INTEL((kal_uint32)fp, (kal_uint16)Cell));

         #endif /* MT6205B */
#else
         RestoreIRQMask(savedMask);
         WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_PROGRAM);
#endif         
      }
      break;

      case 512:
      {
      	kal_uint32 ISRCountBefore,ISRCountAfter;
         kal_uint32 i, j, k;
         volatile FLASH_CELL *fp,*dfp;
         FLASH_CELL *dtp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))   // Data address is not word-aligned
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;
#ifdef __PAGE_BUFFER_PROGRAM__
            FLASH_CELL TempBuff[BUFFER_PROGRAM_ITERATION_LENGTH];
            kal_uint8*  TempBuffU8 = (kal_uint8*)TempBuff;

#endif
            j = 0;

#ifndef __PAGE_BUFFER_PROGRAM__      // word program

            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];
               savedMask = SaveAndSetIRQMask();
               fp[i] = INTEL_CMD_PGM_WORD;
               fp[i] = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_               
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
               RestoreIRQMask(savedMask);               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell));
               }
               else
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell))
                  {
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }
               }

               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell));

               #endif /* MT6205B */
#else
               RestoreIRQMask(savedMask);
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
#endif                              
            }

#else       // page buffer program
            for(k = 0; k < (Length/sizeof(FLASH_CELL))/PAGE_BUFFER_SIZE; k++)
            {
               for(i = 0; i < PAGE_BUFFER_SIZE*sizeof(FLASH_CELL); i++)
               {
                  TempBuffU8[i] = bdp[j++];
               }
               
               dfp = &(fp[k*PAGE_BUFFER_SIZE]);
               dtp = TempBuff;

               savedMask = SaveAndSetIRQMask();
               ISRCountBefore = processing_irqCnt;

               *dfp = INTEL_CMD_CLR_SR;   //clear status register first
               *dfp = INTEL_CMD_BUF_PGM;  //enter buffered programming
               *dfp = PAGE_BUFFER_SIZE-1; //set data count
               *dfp++ = *dtp++;

#if ((!defined(_LOW_COST_SINGLE_BANK_FLASH_))&& (!defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) )               
               RestoreIRQMask(savedMask);
#endif                              
               
               for(i = 1; i < PAGE_BUFFER_SIZE; i++)
               {
                  *dfp++ = *dtp++;         // fill data to device buffer
               }

               fp[k*PAGE_BUFFER_SIZE] = INTEL_CMD_BUF_PGM_CNF;   // set confirm command to flush buffer to flash

               ISRCountAfter = processing_irqCnt;

#ifdef _LOW_COST_SINGLE_BANK_FLASH_     
               WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               RestoreIRQMask(savedMask);
               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)TempBuff[PAGE_BUFFER_SIZE-1]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)TempBuff[PAGE_BUFFER_SIZE-1]);
                     if(result==RESULT_FLASH_BUSY)
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1]);
                  }while(result==RESULT_FLASH_BUSY);               
               }
               INT_RestoreCodePrefetch(restore_value);
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)TempBuff[PAGE_BUFFER_SIZE-1]);
               }while(result==RESULT_FLASH_BUSY);

               #endif /* MT6205B */

#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/             
               WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               if(ISRCountBefore != ISRCountAfter)
               {
                  CompareData((void*)&(fp[k*PAGE_BUFFER_SIZE]),(void*)TempBuff,PAGE_BUFFER_SIZE);
               }
#endif
            }
#endif
         }
         else   //Data address is word-aligned
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;

#ifndef __PAGE_BUFFER_PROGRAM__      // word program
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               savedMask = SaveAndSetIRQMask();
               fp[i] = INTEL_CMD_PGM_WORD;
               fp[i] = dp[i];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_      
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);           
               RestoreIRQMask(savedMask);               
               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]));
               }
               else
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]))
                  {
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }
               }

               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]));

               #endif /* MT6205B */
#else
               RestoreIRQMask(savedMask);
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
#endif               
            }
#else         // page buffer program
            for(k = 0; k < (Length/sizeof(FLASH_CELL))/PAGE_BUFFER_SIZE; k++)
            {
               dfp = &(fp[k*PAGE_BUFFER_SIZE]);
               dtp = &(dp[k*PAGE_BUFFER_SIZE]);

               savedMask = SaveAndSetIRQMask();
               
               ISRCountBefore = processing_irqCnt;
               
               *dfp = INTEL_CMD_CLR_SR;    //clear status register first
               *dfp = INTEL_CMD_BUF_PGM;   // enter buffered programming
               *dfp = PAGE_BUFFER_SIZE-1;  // set data count
               *dfp++ = *dtp++; 

#if ((!defined(_LOW_COST_SINGLE_BANK_FLASH_))&& (!defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) )               
               RestoreIRQMask(savedMask);
#endif

               for(i = 1; i < PAGE_BUFFER_SIZE; i++)
               {
                  *dfp++ = *dtp++;  // fill data to device buffer
               }

               fp[k*PAGE_BUFFER_SIZE] = INTEL_CMD_BUF_PGM_CNF; // set confirm command to flush buffer to flash

               ISRCountAfter = processing_irqCnt;

#ifdef _LOW_COST_SINGLE_BANK_FLASH_      
               WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               RestoreIRQMask(savedMask);               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)dp[(k+1)*PAGE_BUFFER_SIZE-1]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)dp[(k+1)*PAGE_BUFFER_SIZE-1]);
                     if(result==RESULT_FLASH_BUSY)
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1]);
                  }while(result==RESULT_FLASH_BUSY);               
               }
               INT_RestoreCodePrefetch(restore_value);
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)dp[(k+1)*PAGE_BUFFER_SIZE-1]);
               }while(result==RESULT_FLASH_BUSY);

               #endif /* MT6205B */

#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/    

               WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               if(ISRCountBefore != ISRCountAfter)
               {
                  CompareData((void*)&(fp[k*PAGE_BUFFER_SIZE]),(void*)&(dp[k*PAGE_BUFFER_SIZE]),PAGE_BUFFER_SIZE);
               }
#endif               
            }
#endif

         }
      }
      break;

      default:
      {
         kal_uint32 i, j;
         volatile FLASH_CELL *fp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))  // Data address is not word-aligned
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;

            j = 0;
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];
               savedMask = SaveAndSetIRQMask();
               fp[i] = INTEL_CMD_PGM_WORD;
               fp[i] = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_      
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
               RestoreIRQMask(savedMask);               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell));
               }
               else
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell))
                  {
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }
               }

               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)Cell));

               #endif /* MT6205B */
#else               
               RestoreIRQMask(savedMask);
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
#endif               
            }
         }
         else  // Data address is word-aligned
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;

            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               savedMask = SaveAndSetIRQMask();
               fp[i] = INTEL_CMD_PGM_WORD;
               fp[i] = dp[i];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_      
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);             
               RestoreIRQMask(savedMask);               
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]));
               }
               else
               {
                  while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]))
                  {
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }
               }

               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               while(!CheckReadyAndResume_INTEL((kal_uint32)&fp[i], (kal_uint16)dp[i]));

               #endif /* MT6205B */
#else
               RestoreIRQMask(savedMask);
               WaitReady_INTEL((kal_uint32)&fp[i], INTEL_WAIT_PROGRAM);
#endif               
            }
         }
      }
      break;

   }

#if  (defined(_LOW_COST_SINGLE_BANK_FLASH_) && defined(MT6205B))   
   //enable code cache prefetch
   *(kal_uint32 *)(0x80010030) = restore_value;
#endif   

   return FS_NO_ERROR;
}

#else //__INTEL_SIBLEY__



static int ProgramData_SIB(void * DriveData, void * Address, void * Data, kal_uint32 Length){

   volatile FLASH_CELL* fp = (volatile FLASH_CELL*)Address;
   FLASH_CELL *dp = (FLASH_CELL*)Data;
   kal_uint8 *Bdp = (kal_uint8 *)Data;
   kal_uint32 savedMask,i;
   kal_uint32 ISRCountBefore,ISRCountAfter;
   
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   

   // buffer program, data address is word-aligned
   if(Length > 16)
   {
      ISRCountBefore = processing_irqCnt;
      ASSERT((Length&1)==0);  
      if (((kal_uint32)Data&0x1)==0) 
      {
         fp[0] = INTEL_CMD_CLR_SR;        //clear status register first			
         fp[0] = SIB_CMD_PGM_BUF_C1;    			 
         fp[0] = (Length>>1)-1;                   
         for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
         {
            fp[i] = dp[i];   
         }
         fp[0] = SIB_CMD_PGM_BUF_C2;
      }
      // buffer program, data address is not word-aligned
      else 
      {                                                   
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;
         
         //buffered program      	
         fp[0] = INTEL_CMD_CLR_SR;          //clear status register first			
         fp[0] = SIB_CMD_PGM_BUF_C1;      		 
         fp[0] = (Length>>1)-1;			
         for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
         {
            b[0] = Bdp[0];
            b[1] = Bdp[1];
            fp[i] = Cell;	
            Bdp+=2;
         }
         fp[0] = SIB_CMD_PGM_BUF_C2;		
      }
      ISRCountAfter = processing_irqCnt;    

      WaitReady_SIB((kal_uint32)&fp[0], INTEL_WAIT_PROGRAM, Length >> 5 );

      if(ISRCountBefore != ISRCountAfter)
      {
         CompareData(Address,Data,Length);
      }
   }
   //word program
   else if(Length <= 16)  
   {
      kal_uint32 AddrPtr = (kal_uint32)Address;
      kal_uint32 DataPtr = (kal_uint32)Data;
      kal_uint32 ofs;
      FLASH_CELL Cell;
      kal_uint8 *b = (kal_uint8*) &Cell;
      
      // A3 must equal to zero
      ASSERT(((kal_uint32)Address&0x10)==0 &&(((kal_uint32)Address+Length-1)&0x10)==0); 

      while(Length >0)
      {
         if ((AddrPtr % sizeof(FLASH_CELL) !=0) || (Length < sizeof(FLASH_CELL)))
         {
            ofs = (AddrPtr) & (sizeof(FLASH_CELL)-1);
            fp = (FLASH_CELL*) (AddrPtr & ~(sizeof(FLASH_CELL)-1)); // round it down
            Cell = fp[0];
            b[ofs] = ((kal_uint8*)DataPtr)[0];
            Length=Length-1;
            AddrPtr=AddrPtr+1;
            DataPtr=DataPtr+1;
         }
         else
         {
            fp = (FLASH_CELL*) (AddrPtr);
            b[0] = ((kal_uint8*)DataPtr)[0];
            b[1] = ((kal_uint8*)DataPtr)[1];
            Length=Length-2;
            AddrPtr=AddrPtr+2;
            DataPtr=DataPtr+2;
         }
         savedMask = SaveAndSetIRQMask();
         fp[0] = SIB_CMD_PGM_WORD;
         fp[0] = Cell;
         RestoreIRQMask(savedMask);
         WaitReady_SIB((kal_uint32)fp, INTEL_WAIT_PROGRAM,0);
      }
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}
#endif //__INTEL_SIBLEY__

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(_LOW_COST_SINGLE_BANK_FLASH_))
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#ifdef __MTK_TARGET__
#if (defined(MT6205B) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) )
#pragma arm section code = "INTERNCODE"
#else
#pragma arm section code = "SNORCODE"
#endif /* MT6205B */
#endif /* __MTK_TARGET__ */
#endif

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))

extern NOR_FLASH_DRV_Data  FlashDriveData;
extern kal_bool NOR_FLASH_BUSY;
extern kal_bool NOR_FLASH_SUSPENDED;

static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   static FLASH_CELL s = 0 ;

   /* issue suspend command */
   flash_base[0] = INTEL_CMD_SUSPEND;
   flash_base[0] = INTEL_CMD_RD_SR;
   
   s = flash_base[0];
   while(!(s&INTEL_READY_FLAG))
   {
      flash_base[0] = INTEL_CMD_RD_SR;
      s = flash_base[0];
   }
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   flash_base[0] = INTEL_CMD_RD_ARRAY;

}
void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static FLASH_CELL s;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;

   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {
      data_cache_id = INT_DisableDataCache();

      flash_p[0] = INTEL_CMD_RD_SR;
      s = flash_p[0];

      if(!( s & INTEL_READY_FLAG))
      {
         waitReady(flash_p);
      }
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
      }
      flash_p[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
   }
}

kal_bool Flash_CheckReady(void)
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static FLASH_CELL s;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;
   kal_bool result = KAL_FALSE;

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;

   data_cache_id = INT_DisableDataCache();
   
   flash_p[0] = INTEL_CMD_RD_SR;
   s = flash_p[0];
   
   if(s & INTEL_READY_FLAG)
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      result = KAL_TRUE;
   }
   flash_p[0] = INTEL_CMD_RD_ARRAY;
   INT_RestoreDataCache(data_cache_id);

   return result;
}

void Flash_ResumeOperation(void)
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) mtd_data->CurrAddr;

   #if !defined(__PRODUCTION_RELEASE__)
   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && NOR_FLASH_SUSPENDED, NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (fp[0]<<16)|fp[0]);
   #endif

   fp[0] = INTEL_CMD_RESUME;
   fp[0] = INTEL_CMD_RD_SR;
   
   NOR_FLASH_SUSPENDED = KAL_FALSE;
}

void Flash_SuspendOperation(void)
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;
      kal_uint32 data_cache_id;
   kal_uint32 data_cache;
   static FLASH_CELL s = 0 ;
   
   #if !defined(__PRODUCTION_RELEASE__)
   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && !(NOR_FLASH_SUSPENDED), NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (flash_p[0]<<16)|flash_p[0]);
   #endif
   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   data_cache_id = INT_DisableDataCache();

   /* issue suspend command */
   flash_p[0] = INTEL_CMD_SUSPEND;
   flash_p[0] = INTEL_CMD_RD_SR;
   
   s = flash_p[0];
   while(!(s&INTEL_READY_FLAG))
   {
      flash_p[0] = INTEL_CMD_RD_SR;
      s = flash_p[0];
   }
   flash_p[0] = INTEL_CMD_RD_ARRAY;
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   INT_RestoreDataCache(data_cache_id);
}

/* program a word at one time */
void Flash_ProgramData(void *target, void *src, kal_uint32 size)
{
   volatile FLASH_CELL *dest = (volatile FLASH_CELL*)target;
   FLASH_CELL stat_data;
   kal_uint32 idx = 0;
   kal_uint32 data_cache_id = 0;

   SNOR_MTD_ASSERT(!((((kal_uint32)dest) & (sizeof(FLASH_CELL)-1)) || (((kal_uint32)src) & (sizeof(FLASH_CELL)-1))), 
                   (kal_uint32)dest, (kal_uint32)src, sizeof(FLASH_CELL));

   #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
   data_cache_id = INT_DisableCodePrefetch();
   #else
   data_cache_id = INT_DisableDataCache();
   #endif

   while(size)
   {
      dest[idx] = INTEL_CMD_CLR_SR;
      dest[idx] = INTEL_CMD_PGM_WORD;
      dest[idx] = ((FLASH_CELL*)src)[idx];
      NOR_FLASH_BUSY = KAL_TRUE;
      
      while(1)
      {
         dest[idx] = INTEL_CMD_RD_SR;
         stat_data = dest[idx];
         if(stat_data & INTEL_READY_FLAG)
            break;
      }
      dest[idx]= INTEL_CMD_RD_ARRAY;
   
      if (stat_data & INTEL_PROGRAM_ERROR_FLAG)
         EXT_ASSERT(0,0,0,0);
      
      idx++;
      size -= sizeof(FLASH_CELL);
   }
   
   #if  (defined(MT6205B))   
   INT_RestoreCodePrefetch(data_cache_id);
   #else
   INT_RestoreDataCache(data_cache_id);
   #endif
}

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(_LOW_COST_SINGLE_BANK_FLASH_))
#ifdef __MTK_TARGET__
   #pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */
#endif 
/*-----------------------------------*/
static int NonBlockEraseBlock_INTEL(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   savedMask = SaveAndSetIRQMask();
   //Erase command
   fp[0] = INTEL_CMD_ERASE_SETUP;
   fp[0] = INTEL_CMD_ERASE_CONFIRM;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

   return FS_NO_ERROR;
}

/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) 
static kal_int32 CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   kal_uint16 stat_data;
   kal_int32   status;
   kal_uint32 data_cache_id;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask = 0;
#endif

   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));   

   /* ensure that the status check is atomic */
   #if !defined(MT6205B)
   savedMask = SaveAndSetIRQMask();
   #endif

   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];

   if(stat_data & INTEL_READY_FLAG)
   {
      if(stat_data & INTEL_ERASE_SUSPEND)
      {
         /* flash is erase suspended */
         #if !defined(__PRODUCTION_RELEASE__)
         SNOR_MTD_ASSERT( NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (kal_uint32)fp, (fp[0] << 16) | fp[0] );
         #endif
         fp[0] = INTEL_CMD_RESUME;
         NOR_FLASH_SUSPENDED = KAL_FALSE;
         status =  FS_FLASH_ERASE_BUSY;
      }
      else
      {
         fp[0] = INTEL_CMD_RD_ARRAY;
         NOR_FLASH_BUSY = KAL_FALSE;
         status = FS_NO_ERROR;
      }
   }
   else
   {
      status = FS_FLASH_ERASE_BUSY;
   }
   
   INT_RestoreDataCache(data_cache_id);

   #if !defined(MT6205B)
   RestoreIRQMask(savedMask);
   #endif
   
   return status;
}
#else
static int CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;
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
   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];
   fp[0] = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);
   
   if(stat_data & INTEL_READY_FLAG)
      return FS_NO_ERROR;
   else
      return FS_FLASH_ERASE_BUSY;
}
#endif
/*-----------------------------------*/
static int SuspendErase_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   FLASH_CELL s = 0;
   kal_uint32 data_cache_id;
   
#if (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#endif   

   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_SUSPEND;
   fp[0] = INTEL_CMD_RD_SR;
   s = fp[0];
   while(!(s&INTEL_READY_FLAG))
   {
      fp[0] = INTEL_CMD_RD_SR;
      s = fp[0];
   }
   fp[0] = INTEL_CMD_RD_ARRAY;
   
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_TRUE;
#endif    

   INT_RestoreDataCache(data_cache_id);

#if (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
#endif    

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ResumeErase_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
#endif   	

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
#endif   

   fp[0] = INTEL_CMD_RESUME;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_FALSE;
   RestoreIRQMask(savedMask);
#endif

   return FS_NO_ERROR;
}
#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(_LOW_COST_SINGLE_BANK_FLASH_))
#ifdef __MTK_TARGET__
   #pragma arm section code
#endif /* __MTK_TARGET__ */
#endif 

/*-----------------------------------*/
#ifdef __INTEL_SIBLEY__
static int BlankCheck_SIB(void * DriveData, kal_uint32 BlockIndex) //Especially for Sibley
{
   kal_uint32 savedMask;
   kal_uint16 stat_data;

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
   //Blank Check Command
   fp[0] = SIB_CMD_BLANK_CK_C1;
   fp[0] = SIB_CMD_BLANK_CK_C2;
   RestoreIRQMask(savedMask);

   WaitReady_INTEL((kal_uint32)fp, SIB_WAIT_BLANK_CHECK); 
   //Read Status Command
   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];
   fp[0] = INTEL_CMD_CLR_SR;
   fp[0] = INTEL_CMD_RD_ARRAY;
   return (stat_data & SIB_NOT_ALL_ERASED_FLAG)?0:1; // SR[5]=1 means not all erased
}
#endif
/********************************************/
/*                                                                            */
/*                        FDM5.0 MTD SUPPORT                      */
/*                                                                            */
/********************************************/
#ifdef __NOR_FDM5__

static int MountDevice_INTEL(void * DriveData, void * Info)
{
   NOR_MTD_DATA * D = DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   kal_uint32 TotalPhysicalPages;
   kal_uint32 TblEntryShift=0,j=1;
   kal_uint32 block;
   volatile FLASH_CELL * fp;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;



   // check and assign D->LayoutInfo
   TotalPhysicalPages = (Layout->BlkSize)/(Layout->PageSize)*(Layout->TotalBlks);

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

   /* unlock all blocks */
   for(block=0; block< Layout->TotalBlks; block++)
   {
      
      fp = (volatile FLASH_CELL *) BlockAddress(D, block);

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   return FS_NO_ERROR;
}

static int ShutDown_INTEL(void * DriveData)
{
   NOR_MTD_DATA * D = DriveData;
   NORBankInfo * BankInfo = D->LayoutInfo->BankInfo;
   kal_uint32 fp = (kal_uint32)D->BaseAddr; 
   
   kal_uint32 i=0,j=0;

   for(i=0;BankInfo[i].Banks !=0;i++)
      for(j=0;j<BankInfo[i].Banks;j++)
      {
         WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
         fp+=(kal_uint32)BankInfo[i].BankSize;
      }
   return FS_NO_ERROR;
}
#endif
#if  (defined(_LOW_COST_SINGLE_BANK_FLASH_) && defined(__MTK_TARGET__))
   #pragma arm section code
#endif 

/*-----------------------------------*/
NOR_MTD_Driver DriverName =
{
   MountDevice_INTEL,
   ShutDown_INTEL,
   MapWindow,
   EraseBlock_INTEL,
#ifndef __INTEL_SIBLEY__
   ProgramData_INTEL,
#else
   ProgramData_SIB,
#endif
   NonBlockEraseBlock_INTEL,
   CheckDeviceReady_INTEL,
   SuspendErase_INTEL,
   ResumeErase_INTEL,
#ifndef __INTEL_SIBLEY__
   NULL,
#else
   BlankCheck_SIB,
#endif   
   NULL,
   NULL,
   LockEraseBlkAddr_INTEL
};


#endif //__INTEL_SERIES_NOR__
