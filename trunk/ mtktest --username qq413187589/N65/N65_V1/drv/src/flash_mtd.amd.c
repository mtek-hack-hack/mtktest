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
 *    flash_mtd.amd.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for AMD series devices.
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

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#include "intrCtrl.h"
#include "drv_comm.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
#include <stdio.h>

/********************************************************************************************
 * !!CAUTION!!
 * No matter what kinds of modifications are made in this file, corresponding verifications 
 * are required on both multiple and single bank devices.
 * For example, sanity test should be passed on both Crystal25V3 and Crystal25V3SB projects.
 ********************************************************************************************/

/* Global reclaration */
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);
void WaitReady_AMD(kal_uint32 addr,kal_uint16 data);

extern kal_uint32 NOR_Flash_Base_Address;
extern kal_uint32 NOR_FDM_MARK_COPY;
extern const kal_uint32 NOR_FDM_MARK;

#if defined(__MAUI_BASIC__) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

extern kal_uint8 IRQCode2Line[];
extern kal_uint32 NOR_Flash_Base_Address;

#if defined(MT6205B)
kal_uint32 g_savedMask;
#endif

#if (defined(MT6205B) || defined(MT6223) || defined(MT6223P) || defined(MT6223B))
#define TEST_IRQ_CODE (IRQ_SIM_CODE) /* SIM is not enabled in basic load */
#else
#define TEST_IRQ_CODE (IRQ_NFI_CODE) /* NFI should be free in single bank environment */
#endif

void NORTestLISR(void)
{
   extern NOR_FLASH_DRV_Data  FlashDriveData;
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static trigger_count = 0;
   volatile kal_uint32* ram_ptr = 0;
   volatile kal_uint32* rom_ptr = (volatile kal_uint32 *)mtd_data->CurrAddr;
   /* check whether the flash is in ready state */
   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   if( (ram_ptr[0] != rom_ptr[0]) || (ram_ptr[1] != rom_ptr[1]) || 
       (ram_ptr[2] != rom_ptr[2]) || (ram_ptr[3] != rom_ptr[3]) )
       EXT_ASSERT(0,0,0,0);
   trigger_count++;
   IRQClearInt(TEST_IRQ_CODE);
}

static void insertTestLISR(void)
{
   IRQ_Register_LISR(TEST_IRQ_CODE, NORTestLISR,"FAKE NFI");
   IRQSensitivity(TEST_IRQ_CODE,LEVEL_SENSITIVE);
   IRQUnmask(TEST_IRQ_CODE);
}

static void triggerTestIRQ(void)
{
   kal_uint8 line;
   kal_uint32 irq_mask = 0;

   irq_mask = DisableIRQ();
   line = IRQCode2Line[TEST_IRQ_CODE];
   *IRQ_SOFT = line;
   RestoreIRQ(irq_mask);
}
#endif /*__MAUI_BASIC__ && __SINGLE_BANK_NOR_FLASH_SUPPORT__*/

#ifdef __AMD_SERIES_NOR__

/* ************************************************************
         SPANSION(AMD) NOR FLASH MTD Flash Driver
   ************************************************************ */

#ifdef __PAGE_BUFFER_PROGRAM__
   extern kal_uint32 PAGE_BUFFER_SIZE;
#endif

#ifdef __SPANSION_PL_N__
   extern kal_uint32 INT_GetCurrentTime(void);
#endif

static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex);
#ifdef __SPANSION_NS_N__
static void DYBCMD_AMD(volatile FLASH_CELL *fp, kal_uint32 ActionFlag);
#endif
/*-----------------------------------*/
#ifndef __NOR_FDM5__
static int MountDevice_AMD(void * DriveData, void *Info)
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 i, MaxBlockSize = 0;
#ifdef __SPANSION_NS_J__   
   kal_uint32 block;
   volatile FLASH_CELL * fp;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
   kal_uint32 TotalSize_Block = 0;
   kal_uint32 TotalSize_Bank = 0;
#endif
   i = 0;
   FlashInfo->TotalBlocks = 0;      
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
      TotalSize_Block += D->RegionInfo[i].BlockSize * D->RegionInfo[i].RegionBlocks;
#endif

      if(D->RegionInfo[i].BlockSize > MaxBlockSize)
         MaxBlockSize = D->RegionInfo[i].BlockSize;
      i++;
   }
   FlashInfo->ActualRegionNum = i;

#ifdef __SPANSION_NS_J__   
   for(block=0; block<FlashInfo->TotalBlocks; block++)
   {
      D->CurrAddr = BlockAddress(D, block);
      fp = (volatile FLASH_CELL *) D->CurrAddr;
   
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      fp[0] = 0x60;
      fp[0] = 0x60;
      *(kal_uint16*)(((kal_uint32)fp)|0x80)  = 0x60;
      fp[0] = 0xF0;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
#endif
   
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
   
   return FS_NO_ERROR;
}
#endif

/* loop count for time measurement */
#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_50US (325)
#define COUNTER_20US (130)
#define COUNTER_15US (97)
#define COUNTER_10US (65)
#define COUNTER_05US (32)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_50US (658)
#define COUNTER_20US (263)
#define COUNTER_15US (197)
#define COUNTER_10US (132)
#define COUNTER_05US (66)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_50US (1316)
#define COUNTER_20US (526)
#define COUNTER_15US (395)
#define COUNTER_10US (263)
#define COUNTER_05US (132)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_50US (2604)
#define COUNTER_20US (1042)
#define COUNTER_15US (781)
#define COUNTER_10US (521)
#define COUNTER_05US (260)

#else

#error "Unsupported MCU clock rate for single bank support V2!"

#endif

#define CHECK_LOG_START(a) 
#define CHECK_LOG_STOP(a) 
/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

/*
 * Following global variables should be modified only when I-bit is disabled
 */
extern kal_bool NOR_FLASH_BUSY;
extern kal_bool NOR_FLASH_SUSPENDED;

#if defined(MT6205B)
extern kal_uint32 SNOR_IRQ_STATUS;
kal_uint32 snor_check_irq_soft;
#endif

#if defined(LA_TRIGGER_DEBUG)

#define LA_TRIGGER_PIN (43)
#define RETURN_TRIGGER_PIN (44)
#define CHECK_TRIGGER_PIN (45)
#define CACHE_TRIGGER_PIN (46)

void triggerLA(void)
{
   DRV_Reg(GPIO_DOUT3) |= 0x0800; //set GPIO pin state to high
            }
static void triggerReturn(void)
      {
   DRV_Reg(GPIO_DOUT3) |= 0x1000; //set GPIO pin state to high
      }
static void deassertReturn(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x1000); //set GPIO pin state to low
            }
static void triggerCheck(void)
            {
   DRV_Reg(GPIO_DOUT3) |= 0x2000; //set GPIO pin state to high
            }
static void deassertCheck(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x2000); //set GPIO pin state to low
      }
void triggerDisable(void)
{
   DRV_Reg(GPIO_DOUT3) |= 0x4000; //set GPIO pin state to high
            }
void deaseertDisable(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x4000); //set GPIO pin state to low
      }
#else /* defined(LA_TRIGGER_DEBUG) */

#define triggerLA(a) 
#define triggerReturn(a) 
#define deassertReturn(a) 
#define triggerCheck(a) 
#define deassertCheck(a) 
#define triggerDisable(a) 
#define deaseertDisable(a) 

#endif /* LA_TRIGGER_DEBUG */


#define EraseCommand_AMD(addr) \
   do{\
      addr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;\
      addr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;\
      addr[ADDR_UNLOCK_1] = CMD_SERASE;\
      addr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;\
      addr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;\
      addr[0]     = CMD_SERASE_END;\
      NOR_FLASH_BUSY = KAL_TRUE;\
   } while(0);

#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(_LOW_COST_SINGLE_BANK_FLASH_)
#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */
#endif
static void EraseCommand_AMD(volatile FLASH_CELL *fp)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[ADDR_UNLOCK_1] = CMD_SERASE;
   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[0]     = CMD_SERASE_END;
   RestoreIRQMask(savedMask);
}
#if defined(_LOW_COST_SINGLE_BANK_FLASH_)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifdef __SPANSION_NS_N__
static void DYBCMD_AMD(volatile FLASH_CELL *fp, kal_uint32 ActionFlag)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   
   if(ActionFlag == DYB_UNLOCK)
   {
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_DYB_ENTER;
      fp[0] = CMD_DYB_ACT;
      fp[0] = CMD_DYB_CLR;
      fp[0] = CMD_DYB_EXIT1;
      fp[0] = CMD_DYB_EXIT2;
   }
   else
   {
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_DYB_ENTER;
      fp[0] = CMD_DYB_ACT;
      fp[0] = CMD_DYB_SET;
      fp[0] = CMD_DYB_EXIT1;
      fp[0] = CMD_DYB_EXIT2;
   }
   RestoreIRQMask(savedMask);
}
#endif

/*-----------------------------------*/
#if defined(__SPANSION_GL_N__)
__inline static void DelayAWhile_AMD(void * DriveData)
{
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 data_cache_id = 0;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   FLASH_CELL s1 = 0, s2 = 0;
   do
   {
      data_cache_id = INT_DisableDataCache();
      s1 = fp[1];
      s2 = fp[1];
      INT_RestoreDataCache(data_cache_id);
      if(s2 & POLL_ERASE_START)
      {
         break;
      }
   }
   while(1);
}

#elif defined(__SPANSION_GL_A__)

__inline static void DelayAWhile_AMD(void * DriveData)
{
   kal_uint32 wait_count = COUNTER_05US;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 data_cache_id = 0;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   FLASH_CELL s1 = 0, s2 = 0;
   do
   {
      data_cache_id = INT_DisableDataCache();
      s1 = fp[1];
      s2 = fp[1];
      INT_RestoreDataCache(data_cache_id);
      if(s2 & POLL_ERASE_START)
      {
         break;
      }
   }
   while(wait_count--);
}

#elif defined(__SPANSION_PL_N__)

__inline static void DelayAWhile_AMD(void)
{
   
#if defined(MT6205B)

   volatile kal_uint32 i;
   for (i=0;i<COUNTER_10US;i++);
   
#else

   volatile kal_uint32 CurrentTime,StartTime;
   
   StartTime = INT_GetCurrentTime(); //32KHz Fregquency Counter
   while(1)
   {
      CurrentTime = INT_GetCurrentTime();
      if((CurrentTime > StartTime) && ((CurrentTime-StartTime)>=2))
         break;
      if((CurrentTime < StartTime) && (CurrentTime>=1))
         break;
   }
#endif
     
   return;
}
#endif //__SPANSION_PL_N__

/*-----------------------------------*/
#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(_LOW_COST_SINGLE_BANK_FLASH_))
#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */
#endif

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
/* ------------------------------------------------------------------ */
kal_int32 CheckReadyAndResume_AMD(kal_uint32 addr,kal_uint16 data) /* for program operation only */
{
   kal_uint32 data_cache_id;
   static kal_uint16 check_data = 0;
   static kal_uint16 toggle_data = 0;
   kal_uint32 savedMask;
   kal_int32   status = RESULT_FLASH_BUSY;
   #if defined(MT6205B)
   kal_uint16 irq_sts = 0;
   #endif

   triggerCheck();

   #ifndef MT6205B
   savedMask = SaveAndSetIRQMask();
   #endif
   CHECK_LOG_START(sla_id[22])

   if(NOR_FLASH_SUSPENDED)
   {
      #if !defined(__PRODUCTION_RELEASE__)
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr);
      #endif
      *(volatile kal_uint16*)addr = CMD_RESU_SEC_ERASE;
      NOR_FLASH_SUSPENDED = KAL_FALSE;
   }

   data_cache_id = INT_DisableDataCache();
   check_data = *(volatile kal_uint16*)addr;

   toggle_data = *(volatile kal_uint16*)addr;

   if( ((check_data & POLL_BUSY) != (data & POLL_BUSY)) ||
       ((check_data ^ toggle_data) & TOGGLE_BUSY) )
   {
#ifndef __SST_NOR__
      if( check_data & POLL_TIMEOUT )
      {

         check_data = *(volatile kal_uint16*)addr;

         if( check_data == data ) /* in case that DQ5 of data happens to be "1" */
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            status = RESULT_FLASH_DONE;
         }
         else
         {
            #ifdef __PRODUCTION_RELEASE__
            *(volatile kal_uint16*)addr = CMD_RESET;
            INT_RestoreDataCache(data_cache_id);
            #endif
            SNOR_MTD_ASSERT(0,check_data,data,addr);
         }
      }
      else if( check_data & TOGGLE_BUFFER_ABORT )
      {
         check_data = *(volatile kal_uint16*)addr;
         if( check_data!= data)
   {
         #ifdef __PRODUCTION_RELEASE__
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_1) = CMD_UNLOCK_1;
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_2) = CMD_UNLOCK_2;
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_1) = CMD_RESET;
         #endif
            INT_RestoreDataCache(data_cache_id);
            SNOR_MTD_ASSERT(0,check_data,data,addr);
         }
         NOR_FLASH_BUSY = KAL_FALSE;
         status = RESULT_FLASH_DONE;
      }
      else
#endif /* __SST_NOR__ */
      {
         check_data = *(volatile kal_uint16*)addr;
         toggle_data = *(volatile kal_uint16*)addr;

         if( (check_data == data) && !((toggle_data^check_data)&TOGGLE_BUSY) )
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            status = RESULT_FLASH_DONE;
         }
         }
      }
      else
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      check_data = *(volatile kal_uint16*)addr;

      if(check_data == data)
      {
         status = RESULT_FLASH_DONE;
      }
      else
      {
         status = RESULT_FLASH_FAIL;
      }
}

   INT_RestoreDataCache(data_cache_id);

   CHECK_LOG_STOP(sla_id[22])
   #ifndef MT6205B
   RestoreIRQMask(savedMask);
   #endif

   deassertCheck();
   return status;
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*-----------------------------------*/
#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
static int ProgramData_TOSHIBA(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) (D->CurrAddr);
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *)((kal_uint32)Address&(~((Layout->BlkSize-1))));
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif   
   
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

         savedMask = SaveAndSetIRQMask();
         bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         bp[ADDR_UNLOCK_1] = CMD_PROG;
         ((volatile FLASH_CELL*)Address)[0] = ((FLASH_CELL*)Data)[0];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_AMD((kal_uint32)Address, *(kal_uint16*)Data);
         RestoreIRQMask(savedMask);         
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            while(!CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data));
         }
         else
         {
            while(!CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data))
            {
               savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)Address);
            }
         }

         CHECK_LOG_STOP(sla_id[5])
         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);
         while(!CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data));

         CHECK_LOG_STOP(sla_id[5])
         #endif /* MT6205B */
#else
         RestoreIRQMask(savedMask);
         WaitReady_AMD((kal_uint32)Address, *(kal_uint16*)Data);
#endif
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

         savedMask = SaveAndSetIRQMask();
         bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         bp[ADDR_UNLOCK_1] = CMD_PROG;
         fp[0]     = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_AMD((kal_uint32)fp, (kal_uint16)Cell);
         RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell));
         }
         else
         {
            while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell))
            {
               savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)Address);
            }
         }

         CHECK_LOG_STOP(sla_id[5])
         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);
         while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell));

         CHECK_LOG_STOP(sla_id[5])
         #endif /* MT6205B */
#else         
         RestoreIRQMask(savedMask);
         WaitReady_AMD((kal_uint32)fp, (kal_uint16)Cell);
#endif
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
         kal_uint32 i, j=0;
#ifdef __PAGE_BUFFER_PROGRAM__
         kal_uint32 Words;
         kal_uint32 ProgramWords;
#endif
         volatile FLASH_CELL *fp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;
#ifndef __PAGE_BUFFER_PROGRAM__
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];
               savedMask = SaveAndSetIRQMask();
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               bp[ADDR_UNLOCK_1] = CMD_PROG;
               fp[i] = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
               RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell));
               }
               else
               {
                  while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell))
                  {
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)Address);
                  }
               }

               CHECK_LOG_STOP(sla_id[5])
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               while(!CheckReadyAndResume_AMD((kal_uint32)Address, (kal_uint16)Cell));

               CHECK_LOG_STOP(sla_id[5])
               #endif /* MT6205B */
#else               
               RestoreIRQMask(savedMask);
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
#endif
            } /* end of for loop */
#else  //__PAGE_BUFFER_PROGRAM__
            FLASH_CELL prog_buffer[BUFFER_PROGRAM_ITERATION_LENGTH];
            Words = (Length/sizeof(FLASH_CELL));
            b = (kal_uint8 *)prog_buffer;
            j = 0;
   #ifdef __TOSHIBA_TV__ 
            ProgramWords = 8; //TOSHIBA_TV only support 8 word auto page program
   #endif
            while(Words > 0 )
            {
   #ifdef __TOSHIBA_TV__
               if ((Words >= 8) && (!((kal_uint32)fp & (8*sizeof(FLASH_CELL)-1))) )
               {
                  for(i = 0; i < ProgramWords*sizeof(FLASH_CELL); i++)
                  {
                     b[i] = bdp[j++];
                  }
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = 0xE6;
               
                  for(i = 0; i < ProgramWords; i++)
                  {
                     fp[i] = prog_buffer[i];
                  }
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]);
                  RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                  #if defined(MT6205B)
                  if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]));
                  }
                  else
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]))
                     {
                        savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                     }
                  }

                  CHECK_LOG_STOP(sla_id[8])
                  RestoreIRQMask(savedMask);

                  #else /* !MT6205B */

                  RestoreIRQMask(savedMask);
                  while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]));

                  CHECK_LOG_STOP(sla_id[8])
                  #endif /* MT6205B */
#else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]);               
#endif
                  Words -= ProgramWords;
                  fp += ProgramWords;            
               }
               else
               {
                  b[0] = bdp[j++];
                  b[1] = bdp[j++];
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = CMD_PROG;
                  fp[0] = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[0], (kal_uint16)Cell);
                  RestoreIRQMask(savedMask);

#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                  #if defined(MT6205B)
                  if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)Cell));
                  }
                  else
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)Cell))
                     {
                        savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[0]);
                     }
                  }

                  CHECK_LOG_STOP(sla_id[5])
                  RestoreIRQMask(savedMask);

                  #else /* !MT6205B */

                  RestoreIRQMask(savedMask);
                  while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)Cell));

                  CHECK_LOG_STOP(sla_id[5])
                  #endif /* MT6205B */
#else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[0], (kal_uint16)Cell);
#endif
                  Words -= 1;
                  fp += 1;            
               }               
   #elif defined __TOSHIBA_TY__
               {	
                  kal_uint16 PageProgramCommand;
                  if ((Words >= 32)&& (!((kal_uint32)fp & (32*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 32;
                     PageProgramCommand = 0xE8;
                  }
                  else if ((Words >= 16)&& (!((kal_uint32)fp & (16*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 16;
                     PageProgramCommand = 0xE7;
                  }
                  else if ((Words >= 8)&& (!((kal_uint32)fp & (8*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 8;
                     PageProgramCommand = 0xE6;
                  }
                  else if ((Words >= 4)&& (!((kal_uint32)fp & (4*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 4;
                     PageProgramCommand = 0xE5;
                  }
                  else
                  {
                     ProgramWords = 1;
                     PageProgramCommand = CMD_PROG;
                  }
                  
                  for(i = 0; i < ProgramWords*sizeof(FLASH_CELL); i++)
                  {
                     b[i] = bdp[j++];
                  }
 
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = PageProgramCommand;
               
                  for(i = 0; i < ProgramWords; i++)
                  {
                  	fp[i] = prog_buffer[i];
                  }
      #ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords -1]);
                  RestoreIRQMask(savedMask);
      #elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                  #if defined(MT6205B)
                  if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]));
                  }
                  else
                  {
                     while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]))
                     {
                        savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                     }
                  }

                  CHECK_LOG_STOP(sla_id[8])
                  RestoreIRQMask(savedMask);

                  #else /* !MT6205B */

                  RestoreIRQMask(savedMask);
                  while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords-1]));

                  CHECK_LOG_STOP(sla_id[8])
                  #endif /* MT6205B */
      #else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buffer[ProgramWords -1]);               
      #endif
                  Words -= ProgramWords;
                  fp += ProgramWords;
               }
   #else 
               ASSERT(0);
   #endif              
            }//while(Words > 0 )
#endif //__PAGE_BUFFER_PROGRAM__
         }
         else
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;
#ifndef __PAGE_BUFFER_PROGRAM__
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               savedMask = SaveAndSetIRQMask();
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               bp[ADDR_UNLOCK_1] = CMD_PROG;
               fp[i] = dp[i];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);
               RestoreIRQMask(savedMask);
#else
               RestoreIRQMask(savedMask);
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);               
#endif
            }
#else //__PAGE_BUFFER_PROGRAM__
            Words = (Length/sizeof(FLASH_CELL));
   #ifdef __TOSHIBA_TV__
            ProgramWords = 8;
   #endif
            while(Words > 0 )
            {
   #ifdef __TOSHIBA_TV__
               if ((Words >= 8) && (!((kal_uint32)fp & (8*sizeof(FLASH_CELL)-1))) )
               {
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = 0xE6;
               
                  for(i = 0; i < ProgramWords; i++)
                  {
                     fp[i] = dp[i];
                  }
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
                  RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                 #if defined(MT6205B)
                 if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]));
                 }
                 else
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]))
                    {
                       savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                    }
                 }

                 CHECK_LOG_STOP(sla_id[10])
                 RestoreIRQMask(savedMask);

                 #else /*!MT6205B*/

                 RestoreIRQMask(savedMask);
                 while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]));

                 CHECK_LOG_STOP(sla_id[10])
                 #endif /*MT6205B*/
#else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);            
#endif
                  Words -= ProgramWords;
                  fp += ProgramWords;
                  dp += ProgramWords;
               }
               else
               {
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = CMD_PROG;
                  fp[0] = dp[0];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[0], (kal_uint16)dp[0]);
                  RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                 #if defined(MT6205B)
                 if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)dp[0]));
                 }
                 else
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)dp[0]))
                    {
                       savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[0]);
                    }
                 }

                 CHECK_LOG_STOP(sla_id[10])
                 RestoreIRQMask(savedMask);

                 #else /*!MT6205B*/

                 RestoreIRQMask(savedMask);
                 while(!CheckReadyAndResume_AMD((kal_uint32)&fp[0], (kal_uint16)dp[0]));

                 CHECK_LOG_STOP(sla_id[10])
                 #endif /*MT6205B*/
#else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[0], (kal_uint16)dp[0]);
#endif
                  Words -= 1;
                  fp += 1;
                  dp += 1;
               }               
   #elif defined __TOSHIBA_TY__
               {
                  kal_uint16 PageProgramCommand;
                  if ((Words >= 32)&& (!((kal_uint32)fp & (32*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 32;
                     PageProgramCommand = 0xE8;
                  }
                  else if ((Words >= 16)&& (!((kal_uint32)fp & (16*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 16;
                     PageProgramCommand = 0xE7;
                  }
                  else if ((Words >= 8)&& (!((kal_uint32)fp & (8*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 8;
                     PageProgramCommand = 0xE6;
                  }
                  else if ((Words >= 4)&& (!((kal_uint32)fp & (4*sizeof(FLASH_CELL)-1))))
                  {
                     ProgramWords = 4;
                     PageProgramCommand = 0xE5;
                  }
                  else
                  {
                     ProgramWords = 1;
                     PageProgramCommand = CMD_PROG;
                  }
                  
                  savedMask = SaveAndSetIRQMask();
                  bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
                  bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
                  bp[ADDR_UNLOCK_1] = PageProgramCommand;
               
                  for(i = 0; i < ProgramWords; i++)
                  {
                     fp[i] = dp[i];
                  }
      #ifdef _LOW_COST_SINGLE_BANK_FLASH_
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
                  RestoreIRQMask(savedMask);
      #elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

                  NOR_FLASH_BUSY = KAL_TRUE;

                 #if defined(MT6205B)
                 if( kal_query_systemInit() || INT_QueryExceptionStatus() )
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]));
                 }
                 else
                 {
                    while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]))
                    {
                       savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                    }
                 }

                 CHECK_LOG_STOP(sla_id[10])
                 RestoreIRQMask(savedMask);

                 #else /*!MT6205B*/

                 RestoreIRQMask(savedMask);
                 while(!CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]));

                 CHECK_LOG_STOP(sla_id[10])
                 #endif /*MT6205B*/
      #else               
                  RestoreIRQMask(savedMask);
                  WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);            
      #endif
                  Words -= ProgramWords;
                  fp += ProgramWords;
                  dp += ProgramWords;                  
               }
   #else
               ASSERT(0);
   #endif               
            }//while(Words > 0 )
#endif  //__PAGE_BUFFER_PROGRAM__
         }
      }
      break;
   }
   return FS_NO_ERROR;
}

#else //(defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))

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
             EXT_ASSERT(0,0,0,0); 
       }
    }
    else if((kal_uint32)Address&0x1==0 && (kal_uint32)Data&0x1==0)
    {
       kal_uint16* Source = (kal_uint16*)Address;
       kal_uint16* Dest = (kal_uint16*)Data;

       for(i=0;i<(Length>>1);i++)
       {
          if(Source[i] != Dest[i])
             EXT_ASSERT(0,0,0,0); 
       }
    }
    else
    {
       kal_uint8* Source = (kal_uint8*)Address;
       kal_uint8* Dest = (kal_uint8*)Data;

       for(i=0;i<Length;i++)
       {
          if(Source[i] != Dest[i])
             EXT_ASSERT(0,0,0,0); 
       }
    }   
}


static int ProgramData_AMD(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_uint32 savedMask;
   kal_uint32  restore_value;
#ifdef __SPANSION_NS_N__
   volatile FLASH_CELL *BlkAddr;
#endif
   
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_int32 result = RESULT_FLASH_BUSY;
   kal_uint16 irq_sts = 0;
#endif
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *)((kal_uint32)Address&(~((Layout->BlkSize-1))));
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#ifdef __SPANSION_NS_N__
   BlkAddr = (volatile FLASH_CELL *)CalBlkAddr(DriveData, (kal_uint32)Address);
   savedMask = SaveAndSetIRQMask();
   DYBCMD_AMD(BlkAddr,DYB_UNLOCK);
   RestoreIRQMask(savedMask);         
#endif
   
   #ifdef DEBUG
   //can't write zero bytes into flash
   ASSERT(Length != 0);
   #endif

   CHECK_LOG_START(sla_id[30])

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

         savedMask = SaveAndSetIRQMask();
         #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
         restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
         #endif
         CHECK_LOG_START(sla_id[5])
         bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         bp[ADDR_UNLOCK_1] = CMD_PROG;
         ((volatile FLASH_CELL*)Address)[0] = ((FLASH_CELL*)Data)[0];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_AMD((kal_uint32)Address, *(kal_uint16*)Data);
         #if  (defined(MT6205B))   
         INT_RestoreCodePrefetch(restore_value);
         #endif
         RestoreIRQMask(savedMask);         
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            do
            {
               result = CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data);
            }while(result==RESULT_FLASH_BUSY);
         }
         else
         {
            do
            {
               result = CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data);
               if(result==RESULT_FLASH_BUSY)
                  savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)Address);
            }while(result==RESULT_FLASH_BUSY);
         }

         CHECK_LOG_STOP(sla_id[5])
         INT_RestoreCodePrefetch(restore_value);
         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);

         do
         {
            result = CheckReadyAndResume_AMD((kal_uint32)Address, *(kal_uint16*)Data);
         }while(result==RESULT_FLASH_BUSY);

         CHECK_LOG_STOP(sla_id[5])
         #endif /* MT6205B */
#else
         RestoreIRQMask(savedMask);
         WaitReady_AMD((kal_uint32)Address, *(kal_uint16*)Data);
#endif
         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (volatile FLASH_CELL *) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

         #ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!((~fp[0]) & Cell))
         #endif

         savedMask = SaveAndSetIRQMask();
         #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
         restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
         #endif
         CHECK_LOG_START(sla_id[6])
         bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         bp[ADDR_UNLOCK_1] = CMD_PROG;
         fp[0]     = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         WaitReady_AMD((kal_uint32)fp, (kal_uint16)Cell);
         #if  (defined(MT6205B))   
         INT_RestoreCodePrefetch(restore_value);
         #endif
         RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;

         #if defined(MT6205B)
         if( kal_query_systemInit() || INT_QueryExceptionStatus() )
         {
            do
            {
               result = CheckReadyAndResume_AMD((kal_uint32)fp, (kal_uint16)Cell);
            }while(result==RESULT_FLASH_BUSY);
         }
         else
         {
            do
            {
               result = CheckReadyAndResume_AMD((kal_uint32)fp, (kal_uint16)Cell);
               if(result==RESULT_FLASH_BUSY)
               savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)fp);
            }while(result==RESULT_FLASH_BUSY);
            }
         INT_RestoreCodePrefetch(restore_value);
         CHECK_LOG_STOP(sla_id[6])
         RestoreIRQMask(savedMask);

         #else /* !MT6205B */

         RestoreIRQMask(savedMask);
         do
         {
            result = CheckReadyAndResume_AMD((kal_uint32)fp, (kal_uint16)Cell);
         }while(result==RESULT_FLASH_BUSY);

         CHECK_LOG_STOP(sla_id[6])
         #endif /* MT6205B */
#else         
         RestoreIRQMask(savedMask);
         WaitReady_AMD((kal_uint32)fp, (kal_uint16)Cell);
#endif
      }
      break;
   default:
      #ifdef DEBUG

      //Misaligned write into flash
      ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
      //Misaligned length write into flash
      ASSERT(!(Length % sizeof(FLASH_CELL)));
      {
         kal_uint32 i;
         volatile FLASH_CELL *fp = (void*) Address;
         FLASH_CELL * V = Data;

         for (i=0; i<Length/sizeof(FLASH_CELL); i++)
            ASSERT(!((~fp[i]) & V[i]));//Attempt to set bits in flash!
      }
      #endif /*DEBUG*/

      {
         kal_uint32 i, j;
#ifdef __PAGE_BUFFER_PROGRAM__
         kal_uint32 Words;
         kal_uint32 ProgramWords;
         kal_uint32 ISRCountBefore,ISRCountAfter;
#endif
         volatile FLASH_CELL *fp,*dfp;
         FLASH_CELL *dtp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;
#ifndef __PAGE_BUFFER_PROGRAM__
            j = 0;
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];
               savedMask = SaveAndSetIRQMask();
               #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
               restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
               #endif
               CHECK_LOG_START(sla_id[7])
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               bp[ADDR_UNLOCK_1] = CMD_PROG;
               fp[i] = Cell;
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
               #if  (defined(MT6205B))   
               INT_RestoreCodePrefetch(restore_value);
               #endif
               RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
                  }while(result==RESULT_FLASH_BUSY);
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
                     if(result==RESULT_FLASH_BUSY)
                        savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               INT_RestoreCodePrefetch(restore_value);
               CHECK_LOG_STOP(sla_id[7])
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
               }while(result==RESULT_FLASH_BUSY);

               CHECK_LOG_STOP(sla_id[7])
               #endif /* MT6205B */
               
               if(result == RESULT_FLASH_FAIL)
                  return result;

#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/                
               RestoreIRQMask(savedMask);
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)Cell);
#endif
            }
#else /* !__PAGE_BUFFER_PROGRAM__ */
            FLASH_CELL prog_buff[BUFFER_PROGRAM_ITERATION_LENGTH];
            b = (kal_uint8*)prog_buff;

            j = 0;
            Words = (Length/sizeof(FLASH_CELL));
            while(Words>0)
            {
               ProgramWords = Words > PAGE_BUFFER_SIZE ?  PAGE_BUFFER_SIZE : Words ;
               if ((kal_uint32)fp & (sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1))
               {
                  FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                  if ( ProgramWords > (pageb-fp))
                     ProgramWords = pageb - fp;  
               }
               ProgramWords = ProgramWords > BUFFER_PROGRAM_ITERATION_LENGTH ?  BUFFER_PROGRAM_ITERATION_LENGTH : ProgramWords ;
               for(i = 0; i < ProgramWords*sizeof(FLASH_CELL); i++)
               {
                  b[i] = bdp[j++];
               }
               
               dfp = fp;
               dtp = prog_buff;
               
               savedMask = SaveAndSetIRQMask();
               #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
               restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
               #endif
               CHECK_LOG_START(sla_id[8])

               ISRCountBefore = processing_irqCnt;
               
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               *dfp = CMD_WRITETOBUFFER;
               *dfp = ProgramWords -1;// set data count
               *dfp++ = *dtp++;

#if ((!defined(_LOW_COST_SINGLE_BANK_FLASH_))&& (!defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) )               
               RestoreIRQMask(savedMask);
#endif
               
               for(i = 1; i < ProgramWords; i++)
               {
                  *dfp++ = *dtp++;
               }
               fp[0] = CMD_BUFFERTOFLASH;
               
               ISRCountAfter = processing_irqCnt;
               
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buff[ProgramWords -1]);
               #if  (defined(MT6205B))   
               INT_RestoreCodePrefetch(restore_value);
               #endif
               RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buff[ProgramWords-1]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buff[ProgramWords-1]);
                     if(result==RESULT_FLASH_BUSY)
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                  }while(result==RESULT_FLASH_BUSY);               
               }
               INT_RestoreCodePrefetch(restore_value);
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               #ifdef __SPANSION_PL_N__
               DelayAWhile_AMD();
               #endif //__SPANSION_PL_N__
               do
               {
                  result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buff[ProgramWords-1]);
               }while(result==RESULT_FLASH_BUSY);

               CHECK_LOG_STOP(sla_id[8])
               #endif /* MT6205B */

               if(result == RESULT_FLASH_FAIL)
                  return result;
#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/                               
#ifdef __SPANSION_PL_N__
               DelayAWhile_AMD();
#endif //__SPANSION_PL_N__
               WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)prog_buff[ProgramWords -1]);
               if(ISRCountBefore != ISRCountAfter)
               {
                  CompareData((void*)fp,(void*)prog_buff,ProgramWords);
               }
#endif
               Words -= ProgramWords;
               fp += ProgramWords;
            }
#endif
         }
         else /* if((((kal_uint32)Data) % sizeof(FLASH_CELL))) */
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;
#ifndef __PAGE_BUFFER_PROGRAM__
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               savedMask = SaveAndSetIRQMask();
               #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
               restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
               #endif
               CHECK_LOG_START(sla_id[9])
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               bp[ADDR_UNLOCK_1] = CMD_PROG;
               fp[i] = dp[i];
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);
               #if  (defined(MT6205B))   
               INT_RestoreCodePrefetch(restore_value);
               #endif
               RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);
                  }while(result==RESULT_FLASH_BUSY);              
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);
                     if(result==RESULT_FLASH_BUSY)
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[i]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               INT_RestoreCodePrefetch(restore_value);
               CHECK_LOG_STOP(sla_id[9])
               RestoreIRQMask(savedMask);

               #else /* !MT6205B */

               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);
               }while(result==RESULT_FLASH_BUSY);

              CHECK_LOG_STOP(sla_id[9])
              #endif /* MT6205B */
               
               if(result == RESULT_FLASH_FAIL)
                  return result;
#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/

               RestoreIRQMask(savedMask);
               WaitReady_AMD((kal_uint32)&fp[i], (kal_uint16)dp[i]);               
#endif
            }
#else /* !__PAGE_BUFFER_PROGRAM__ */
            Words = (Length/sizeof(FLASH_CELL));
            while(Words>0)
            {
               ProgramWords = Words > PAGE_BUFFER_SIZE ?  PAGE_BUFFER_SIZE : Words ;
               if ((kal_uint32)fp & (sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1))
               {
                  FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                  if ( ProgramWords > (pageb-fp))
                     ProgramWords = pageb - fp;  
               }
               ProgramWords = ProgramWords > BUFFER_PROGRAM_ITERATION_LENGTH ?  BUFFER_PROGRAM_ITERATION_LENGTH : ProgramWords ;

               dfp = fp;
               dtp = dp;
                              
               savedMask = SaveAndSetIRQMask();
               #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
               restore_value = INT_DisableCodePrefetch();//disable code cache prefetch
               #endif
               CHECK_LOG_START(sla_id[10])
               
               ISRCountBefore = processing_irqCnt;               
               
               bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
               bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
               *fp = CMD_WRITETOBUFFER;
               *fp = ProgramWords -1;// set data count
               *dfp++ = *dtp++; 
               
#if ((!defined(_LOW_COST_SINGLE_BANK_FLASH_))&& (!defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) )               
               RestoreIRQMask(savedMask);
#endif
               
               for(i = 1; i < ProgramWords; i++)
               {
                  *dfp++ = *dtp++; 
               }
               *fp = CMD_BUFFERTOFLASH;
               
               ISRCountAfter = processing_irqCnt;
               
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
               WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
               #if  (defined(MT6205B))   
               INT_RestoreCodePrefetch(restore_value);
               #endif
               RestoreIRQMask(savedMask);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;

               #if defined(MT6205B)
               if( kal_query_systemInit() || INT_QueryExceptionStatus() )
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
                  }while(result==RESULT_FLASH_BUSY);
               }
               else
               {
                  do
                  {
                     result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
                     if(result==RESULT_FLASH_BUSY)
                     savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[ProgramWords -1]);
                  }while(result==RESULT_FLASH_BUSY);
               }

               CHECK_LOG_STOP(sla_id[10])
               INT_RestoreCodePrefetch(restore_value);
               RestoreIRQMask(savedMask);

               #else /*!MT6205B*/

               RestoreIRQMask(savedMask);
               #ifdef __SPANSION_PL_N__
               DelayAWhile_AMD();
               #endif //__SPANSION_PL_N__
               do
               {
                  result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
               }while(result==RESULT_FLASH_BUSY);

               CHECK_LOG_STOP(sla_id[10])
               #endif /*MT6205B*/

               if(result == RESULT_FLASH_FAIL)
                  return result;

#else /*_LOW_COST_SINGLE_BANK_FLASH_ elif __SINGLE_BANK_NOR_FLASH_SUPPORT__*/
#ifdef __SPANSION_PL_N__
               DelayAWhile_AMD();
#endif //__SPANSION_PL_N__
               WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
               if(ISRCountBefore != ISRCountAfter)
               {
                  CompareData((void*)fp,(void*)dp,ProgramWords);
               }
#endif //_LOW_COST_SINGLE_BANK_FLASH_
               Words -= ProgramWords;
               fp += ProgramWords;
               dp += ProgramWords;
            }
#endif
         }
      }
      break;
   }
#ifdef __SPANSION_NS_N__   
   savedMask = SaveAndSetIRQMask();
   DYBCMD_AMD(BlkAddr,DYB_LOCK);
   RestoreIRQMask(savedMask);
#endif

   CHECK_LOG_STOP(sla_id[30])
#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   return result;
#else
   return FS_NO_ERROR;
#endif
}
#endif //__TOSHIBA_TV__

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

static kal_uint32 getNORCheckMarkAddr(void)
{
   #if (defined(MT6225) || defined(MT6229)|| defined(MT6230))
   kal_uint32 addr = ((kal_uint32)&NOR_FDM_MARK) | 0x4000000;
   #else
   kal_uint32 addr = (kal_uint32)&NOR_FDM_MARK;
   #endif
   return addr;
}

static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   kal_uint32 idx = 0;
   kal_uint32 data_cache;
   static kal_uint16 toggle1 = 0 ;
   static kal_uint16 toggle2 = 0;
#ifdef __MULTI_BANK_NOR_DEVICE__
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData; 
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)mtd_data->CurrAddr;   
#else
   kal_uint32 ram_copy = NOR_FDM_MARK_COPY;
   volatile kal_uint32* rom_ptr = (volatile kal_uint32*)getNORCheckMarkAddr();
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)getNORCheckMarkAddr();
#endif
   /* issue suspend command */
   flash_base[0] = CMD_SUSP_SEC_ERASE;
   /* wait for 5us first */
   idx = COUNTER_05US;
   while(idx--);
   do
   {
      toggle1 = check_ptr[0];
      toggle2 = check_ptr[0];
      if( (toggle1 ^ toggle2) & TOGGLE_BUSY )
      {
#ifndef __MULTI_BANK_NOR_DEVICE__
         if( toggle2 & POLL_TIMEOUT )
         {
            toggle1 = check_ptr[0];
            toggle2 = check_ptr[0];

            if( (toggle1 ^ toggle2) & TOGGLE_BUSY ) /* operation timed out */
            {
               triggerLA();
               #ifdef __PRODUCTION_RELEASE__
               flash_base[0] = CMD_RESET;
               #endif
               SNOR_MTD_ASSERT(0, toggle1, toggle2, rom_ptr[0]);/* something wrong */
            }
            else if( ram_copy == rom_ptr[0] )
            {
               NOR_FLASH_SUSPENDED = KAL_TRUE;
               break;/* operation is suspended or finished */
            }
            else /* erase time out or unexpected case */
            {
               triggerLA();
               #ifdef __PRODUCTION_RELEASE__
               flash_base[0] = CMD_RESET;
               #endif
               SNOR_MTD_ASSERT(0, ram_copy, rom_ptr[0], rom_ptr[0]);/* something wrong */
            }
         }
#endif /*!__MULTI_BANK_NOR_DEVICE__*/
      }
      else
      {
#ifdef __MULTI_BANK_NOR_DEVICE__
         NOR_FLASH_SUSPENDED = KAL_TRUE;
         break;/* operation is suspended or finished */         
#else
         if( ram_copy == rom_ptr[0] )
         {
            NOR_FLASH_SUSPENDED = KAL_TRUE;
            break;/* operation is suspended or finished */
         }
         else /* erase time out or unexpected case */
         {
            triggerLA();
            #ifdef __PRODUCTION_RELEASE__
            flash_base[0] = CMD_RESET;
            #endif
            SNOR_MTD_ASSERT(0, ram_copy, rom_ptr[0], rom_ptr[0]);/* something wrong */
         }
#endif
      }
      /* wait for another 5us */
      idx = COUNTER_05US;
      while(idx--);
   } while(1);

}

void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static FLASH_CELL status_1, status_2;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;
#ifdef __MULTI_BANK_NOR_DEVICE__
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
#else
   kal_uint32 ram_copy = NOR_FDM_MARK_COPY;
   volatile kal_uint32* rom_ptr = (volatile kal_uint32*)getNORCheckMarkAddr();
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)getNORCheckMarkAddr();
#endif /*__MULTI_BANK_NOR_DEVICE__*/
   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;

   triggerReturn();
   CHECK_LOG_START(sla_id[17])

   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {

   data_cache_id = INT_DisableDataCache();

   status_1 = check_ptr[0];
   status_2 = check_ptr[0];

   if((status_1 ^ status_2) & TOGGLE_BUSY)
   {
      waitReady(flash_p);
   }
#ifndef __MULTI_BANK_NOR_DEVICE__
   else if( ram_copy != rom_ptr[0] )
   {
      status_1 = check_ptr[0];
      status_2 = check_ptr[0];

      if((status_1 ^ status_2) & TOGGLE_BUSY)
      {
         waitReady(flash_p);
      }
      else if( ram_copy != rom_ptr[0] )
      {
         triggerLA();
         #ifdef __PRODUCTION_RELEASE__
         flash_p[0] = CMD_RESET;
         #endif
         INT_RestoreDataCache(data_cache_id);
         SNOR_MTD_ASSERT(0, ram_copy, rom_ptr[0], rom_ptr[0]);/* something wrong */
      }
      else
         NOR_FLASH_BUSY = KAL_FALSE;
   }
#endif /*!__MULTI_BANK_NOR_DEVICE__*/
   else
      NOR_FLASH_BUSY = KAL_FALSE;

   INT_RestoreDataCache(data_cache_id);
   }
   deassertReturn();
   CHECK_LOG_STOP(sla_id[17])
}

kal_bool Flash_CheckReady(void)
{
   static FLASH_CELL status_1 = 0, status_2 = 0;
   kal_uint32 data_cache_id = 0;
   kal_bool result = KAL_FALSE;
#ifdef __MULTI_BANK_NOR_DEVICE__
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData; 
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
#else
   kal_uint32 ram_copy = NOR_FDM_MARK_COPY;
   volatile kal_uint32* rom_ptr = (volatile kal_uint32*)getNORCheckMarkAddr();
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)getNORCheckMarkAddr();
#endif

   CHECK_LOG_START(sla_id[24])

   data_cache_id = INT_DisableDataCache();
   status_1 = check_ptr[0];
   status_2 = check_ptr[0];

   if(!((status_1 ^ status_2) & TOGGLE_BUSY)) /* not toggling */
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      result = KAL_TRUE;
#ifndef __MULTI_BANK_NOR_DEVICE__
      if(rom_ptr[0] == ram_copy)
      {
         NOR_FLASH_BUSY = KAL_FALSE;
         result = KAL_TRUE;
      }
#endif
   }

   INT_RestoreDataCache(data_cache_id);

   CHECK_LOG_STOP(sla_id[24])
   return result;
}

void Flash_ResumeOperation(void)
{
#ifdef __MULTI_BANK_NOR_DEVICE__
   extern NOR_FLASH_DRV_Data  FlashDriveData;
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *)mtd_data->CurrPollAddr;
#else
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *) NOR_Flash_Base_Address;   
#endif
   CHECK_LOG_START(sla_id[25])

   #if !defined(__PRODUCTION_RELEASE__)
   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && NOR_FLASH_SUSPENDED, NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (flash_p[0]<<16)|flash_p[0]);
   #endif

   flash_p[0] = CMD_RESU_SEC_ERASE;

   NOR_FLASH_SUSPENDED = KAL_FALSE;

   CHECK_LOG_STOP(sla_id[25])
}

void Flash_SuspendOperation(void)
{
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData; 
   kal_uint32 data_cache_id = 0;
   static FLASH_CELL toggle1 = 0, toggle2 = 0;
#ifdef __MULTI_BANK_NOR_DEVICE__
   extern NOR_FLASH_DRV_Data  FlashDriveData;
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
#else
   kal_uint32 ram_copy = NOR_FDM_MARK_COPY;
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *) NOR_Flash_Base_Address;
   volatile kal_uint32* rom_ptr = (volatile kal_uint32*)getNORCheckMarkAddr();
   volatile kal_uint16* check_ptr = (volatile kal_uint16*)getNORCheckMarkAddr();
#endif
   CHECK_LOG_START(sla_id[26])

   #if !defined(__PRODUCTION_RELEASE__)
   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && !(NOR_FLASH_SUSPENDED), NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (flash_p[0]<<16)|flash_p[0]);
   #endif
   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));



   data_cache_id = INT_DisableDataCache();

   flash_p[0] = CMD_SUSP_SEC_ERASE;

   do
   {
      toggle1 = check_ptr[0];
      toggle2 = check_ptr[0];
      if(!((toggle1 ^ toggle2) & TOGGLE_BUSY))
      {
#ifdef __MULTI_BANK_NOR_DEVICE__
            NOR_FLASH_SUSPENDED = KAL_TRUE;
            break;         
#else
         if(rom_ptr[0] == ram_copy)
         {
            NOR_FLASH_SUSPENDED = KAL_TRUE;
            break;
         }
#endif
      }
   }
   while(1);

   INT_RestoreDataCache(data_cache_id);

   CHECK_LOG_STOP(sla_id[26])
}

/* program a word at one time */
void Flash_ProgramData(void *target, void *src, kal_uint32 size)
{
   volatile FLASH_CELL *dest = (volatile FLASH_CELL*)target;
   FLASH_CELL toggle1 = 0, toggle2 = 0;
   kal_uint32 idx = 0;
   kal_uint32 data_cache_id = 0;

   CHECK_LOG_START(sla_id[27])

   SNOR_MTD_ASSERT(!((((kal_uint32)dest) & (sizeof(FLASH_CELL)-1)) || (((kal_uint32)src) & (sizeof(FLASH_CELL)-1))), 
                   (kal_uint32)dest, (kal_uint32)src, sizeof(FLASH_CELL));

   #if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
   data_cache_id = INT_DisableCodePrefetch();
   #else
   data_cache_id = INT_DisableDataCache();
   #endif

   while(size)
   {
      dest[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      dest[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      dest[ADDR_UNLOCK_1] = CMD_PROG;
      dest[idx] = ((FLASH_CELL*)src)[idx];
      NOR_FLASH_BUSY = KAL_TRUE;
      do
      {
         toggle1 = dest[idx];
         toggle2 = dest[idx];
         if( !((toggle1 ^ toggle2) & TOGGLE_BUSY) )
         {
            toggle1 = dest[idx];
            if(toggle1 == ((FLASH_CELL*)src)[idx])
            {
               NOR_FLASH_BUSY = KAL_FALSE;
               break;
            }
            else
               SNOR_MTD_ASSERT(0, toggle1, toggle2, ((FLASH_CELL*)src)[idx]);
         }
      }
      while(1);
      idx++;
      size -= sizeof(FLASH_CELL);
   }
   
   #if  (defined(MT6205B))   
   INT_RestoreCodePrefetch(data_cache_id);
   #else
   INT_RestoreDataCache(data_cache_id);
   #endif

   CHECK_LOG_STOP(sla_id[27])
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ || __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

void WaitReady_AMD(kal_uint32 addr,kal_uint16 data)
{
   kal_uint16 stat_data = 0;
   kal_uint32 data_cache_id;
   kal_uint16 data_toggle1 = 0, data_toggle2 = 0;
   kal_uint32 savedMask;
   #if defined(MT6205B)
   kal_uint16 irq_sts = 0;
   #endif

   CHECK_LOG_START(sla_id[29])

   do
   {
      #if !defined(MT6205B)
      CHECK_LOG_START(sla_id[0])
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      #endif

      data_toggle1 = *(volatile kal_uint16*)addr;
      data_toggle2 = *(volatile kal_uint16*)addr;

      #if !defined(MT6205B)
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
      CHECK_LOG_STOP(sla_id[0])
      #endif

      if( (data_toggle1^data_toggle2) & TOGGLE_BUSY )
      {
      #ifndef __SST_NOR__
         if( (data_toggle1 & POLL_TIMEOUT) && (data_toggle2 & POLL_TIMEOUT) )
         {
            #if !defined(MT6205B)
            CHECK_LOG_START(sla_id[1])
            savedMask = SaveAndSetIRQMask();
            data_cache_id = INT_DisableDataCache();
            #endif

            data_toggle1 = *(volatile kal_uint16*)addr;
            data_toggle2 = *(volatile kal_uint16*)addr;

            #if !defined(MT6205B)
            INT_RestoreDataCache(data_cache_id);
            RestoreIRQMask(savedMask);
            CHECK_LOG_STOP(sla_id[1])
            #endif
            if((data_toggle1^data_toggle2) & TOGGLE_BUSY)
            {
            #ifdef __PRODUCTION_RELEASE__
               *(volatile kal_uint16*)addr = CMD_RESET;
            #endif
               INT_RestoreDataCache(data_cache_id);
               SNOR_MTD_ASSERT(0, data_toggle2, data, addr);
            }
         }
      #endif /* __SST_NOR__ */
      }
      else if( (data_toggle1^data_toggle2) & TOGGLE_ERASE_SUSPEND ) /* erase operation is suspended */
      {
         savedMask = SaveAndSetIRQMask();
         *(volatile kal_uint16*)addr = CMD_RESU_SEC_ERASE; /* resume suspended erase operation */
         NOR_FLASH_SUSPENDED = KAL_FALSE;
         RestoreIRQMask(savedMask);
      }
      else
      {
         #if !defined(MT6205B)
         CHECK_LOG_START(sla_id[2])
         savedMask = SaveAndSetIRQMask();
         data_cache_id = INT_DisableDataCache();
         #endif

         data_toggle1 = *(volatile kal_uint16*)addr;
         data_toggle2 = *(volatile kal_uint16*)addr;

         #if !defined(MT6205B)
         INT_RestoreDataCache(data_cache_id);
         RestoreIRQMask(savedMask);
         CHECK_LOG_STOP(sla_id[2])
         #endif

         if(data_toggle1 == data_toggle2)
         {
            #if !defined(MT6205B)
            CHECK_LOG_START(sla_id[3])
            savedMask = SaveAndSetIRQMask();
            data_cache_id = INT_DisableDataCache();
            #endif

            stat_data = *(volatile kal_uint16*)addr;

            #if !defined(MT6205B)
            INT_RestoreDataCache(data_cache_id);
            RestoreIRQMask(savedMask);
            CHECK_LOG_STOP(sla_id[3])
            #endif

            if(stat_data == data)
            {
               break;/* operation is finished */
            }
            else
            {
               savedMask = SaveAndSetIRQMask();
               *(volatile kal_uint16*)addr = CMD_RESU_SEC_ERASE; /* resume suspended erase operation */
               NOR_FLASH_SUSPENDED = KAL_FALSE;
               RestoreIRQMask(savedMask);
            }
         }
      }

      #ifdef MT6205B
      /* check pending IRQ */
      irq_sts = (kal_uint16)*IRQ_STS;
      if(irq_sts)
      {
         Flash_ReturnReady();
         *IRQ_SOFT = irq_sts;
         INT_RestoreDataCache(data_cache_id);
         RestoreIRQMask(savedMask);

         savedMask = SaveAndSetIRQMask();
         data_cache_id = INT_DisableDataCache();
      }
#endif

   }while(1);

   CHECK_LOG_STOP(sla_id[29])

   return;

}
#else /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
void WaitReady_AMD(kal_uint32 addr,kal_uint16 data)//Validate!!
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;
#ifdef __SST_NOR__
   kal_uint16 data_toggle1 = 0, data_toggle2 = 0;
#else 
   kal_bool  pass_flag = 0;
#endif

   data_cache_id = INT_DisableDataCache();

#ifndef __SST_NOR__
   while(pass_flag == 0)
   {
      while(1)
      {
         stat_data = *(volatile kal_uint16*)addr;
         if((stat_data & POLL_BUSY) == (data & POLL_BUSY))
            break;

         if(stat_data & POLL_TIMEOUT) //DQ5 = 1 may imply a timeout happens
         {
            stat_data = *(volatile kal_uint16*)addr;
            if((stat_data & POLL_BUSY) == (data & POLL_BUSY))
               break;
            else
            {
               *(volatile kal_uint16*)addr = CMD_RESET;
               INT_RestoreDataCache(data_cache_id);
               EXT_ASSERT(0,0,0,0);
               return;
            }
         }

      }  /* Inner While(1) */

      stat_data = *(volatile kal_uint16*)addr;
      if ( stat_data==data )
      {
         pass_flag = 1;
      }
   }  /* Outer While(1) */
#else
	/* use toggle method instead of data polling method */ 
	/* SST also can use data polling method, but need to disable DQ5 check */
	/* because SST don't support DQ5 */
   while(1)
   {
      data_toggle1 = *(volatile kal_uint16*)addr;
      data_toggle2 = *(volatile kal_uint16*)addr;
      if( !((data_toggle1^data_toggle2) & TOGGLE_BUSY) )
      {
         data_toggle1 = *(volatile kal_uint16*)addr;
         data_toggle2 = *(volatile kal_uint16*)addr;
         if(data_toggle1 == data_toggle2)
         {
            stat_data = *(volatile kal_uint16*)addr;
            if(stat_data == data)
               break;
            else
               EXT_ASSERT(0,0,0,0);
         }
      }
   }
#endif

   INT_RestoreDataCache(data_cache_id);
   return;
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
/*-----------------------------------*/
#ifndef __NOR_FDM5__
static int ShutDown_AMD(void * DriveData)
{
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->CurrAddr;
   FLASH_CELL s1, s2;
   kal_uint32 data_cache_id;
   kal_uint32 savedMask;

   data_cache_id = INT_DisableDataCache();

   while(1)
   {
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      savedMask = SaveAndSetIRQMask();      
      if(NOR_FLASH_SUSPENDED)
      {                
         fp[0] = CMD_RESU_SEC_ERASE; /* resume suspended erase operation */
         NOR_FLASH_SUSPENDED = KAL_FALSE;
      }
      s1 = fp[0];
      s2 = fp[0];
      RestoreIRQMask(savedMask);
#else
      s1 = fp[0];
      s2 = fp[0];
#endif   	      
      if ((s1 ^ s2)==0)
         break;
      else
      {
         if(s2 & TOGGLE_TIMEOUT)
         {
            s1 = fp[0];
            s2 = fp[0];
            if ((s1 ^ s2)==0)
               break;
            else
            {
               fp[0] = CMD_RESET;
               break;
            }
         }
      }
   }

   D->CurrAddr = NULL;
   INT_RestoreDataCache(data_cache_id);
   return FS_NO_ERROR;
}
#endif

/*-----------------------------------*/
static int EraseBlock_AMD(void * DriveData, kal_uint32 BlockIndex) /* MapWindow required */
{
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
   #if defined(MT6205B)
   kal_uint16 irq_sts = 0;
   #endif
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#ifdef __SPANSION_NS_N__
   DYBCMD_AMD(fp,DYB_UNLOCK);
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
   CHECK_LOG_START(sla_id[4])
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   EraseCommand_AMD(fp);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   #if defined(MT6205B)
   if( !( kal_query_systemInit() || INT_QueryExceptionStatus()) )
   {
      savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[0]);
   }
   #else
   //CHECK_LOG_STOP(sla_id[4])
   RestoreIRQMask(savedMask);
   #endif /* !M6205B */
#endif

#if defined(__SPANSION_PL_N__) 
   DelayAWhile_AMD();
#endif

#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   #if defined(MT6205B)
   if(kal_query_systemInit() || INT_QueryExceptionStatus())
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(DriveData, BlockIndex));
   else
   {
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(DriveData, BlockIndex))
      {
         savedMask = CHECK_PENDING_IRQ(savedMask, (kal_uint32)&fp[0]);
      }
   }
   #else
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(DriveData, BlockIndex) );
   #endif /* MT6205B */

   CHECK_LOG_STOP(sla_id[4])

   #if defined(MT6205B)
   RestoreIRQMask(savedMask);
   #endif
#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   while(CheckDeviceReady_AMD(DriveData, BlockIndex)!= FS_NO_ERROR);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifdef __SPANSION_NS_N__
   DYBCMD_AMD(fp,DYB_LOCK);
#endif

   return FS_NO_ERROR;
}
/*-----------------------------------*/
static int NonBlockEraseBlock_AMD(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) 
   kal_uint32 savedMask = 0;
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   #ifdef DEBUG
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#ifdef __SPANSION_NS_N__
   DYBCMD_AMD(fp,DYB_UNLOCK);
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) 
   #if !defined(MT6205B)
   savedMask = SaveAndSetIRQMask();
   #endif
   CHECK_LOG_START(sla_id[11])
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   EraseCommand_AMD(fp);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) 
   CHECK_LOG_STOP(sla_id[11])
   #if !defined(MT6205B)
   RestoreIRQMask(savedMask);
   #endif
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifdef __SPANSION_PL_N__
   DelayAWhile_AMD();
#endif
   return FS_NO_ERROR;
}
/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) 
static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex) /* for erase operation only, MapWindow required */
{
   FLASH_CELL s1, s2;
   kal_uint32 data_cache_id;
   kal_int32 status = FS_DATA_ERROR;
#if defined(NOR_FLASH_BLANK_VERIFICATION)
   kal_uint32 idx = 0;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask = 0;
#endif
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   SNOR_MTD_ASSERT((~D->Signature == (kal_uint32)D->RegionInfo), (kal_uint32)(~D->Signature), (kal_uint32)D->RegionInfo, 0);
   #ifndef __PRODUCTION_RELEASE__
   //EraseBlock: block not mapped
    /* commented out to reduce IRQ latency on MT6205B platforms */
   #if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)&&defined(__MULTI_BANK_NOR_DEVICE__))
   SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)BlockAddress(D, BlockIndex), 0);
   #endif
   #endif
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   SNOR_MTD_ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo), 0, 0, 0);
#endif

   /* ensure that the status check is atomic */
   #if !defined(MT6205B)
   savedMask = SaveAndSetIRQMask();
   #endif
   CHECK_LOG_START(sla_id[12])

   data_cache_id = INT_DisableDataCache();

   s1 = fp[1];
   s2 = fp[1];

   if ((s1 ^ s2) & TOGGLE_BUSY)
   {
      if(s2 & TOGGLE_TIMEOUT)
      {
         s1 = fp[1];
         s2 = fp[1];
         if( (s1 ^ s2) & TOGGLE_BUSY )
         {
            /* operation timed out */
         #ifdef __PRODUCTION_RELEASE__
            fp[0] = CMD_RESET;
         #endif
            SNOR_MTD_ASSERT(0, 0, 0, 0);
         }
         else
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            status = FS_NO_ERROR;
         }
      }
      else
         status = FS_FLASH_ERASE_BUSY;
   }
   else if (((s1 ^ s2) & TOGGLE_ERASE_SUSPEND))
   {
      /* flash is erase suspended */
      #if !defined(__PRODUCTION_RELEASE__)
      SNOR_MTD_ASSERT( NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (kal_uint32)fp, (fp[0] << 16) | fp[0] );
      #endif
      fp[0] = CMD_RESU_SEC_ERASE;
      NOR_FLASH_SUSPENDED = KAL_FALSE;
      status = FS_FLASH_ERASE_BUSY;
   }
   else
   {
      s1 = fp[1];
      s2 = fp[1];

      if(s2 == 0xffff)
      {
         NOR_FLASH_BUSY = KAL_FALSE;
         /* blank check */
         #if (defined(NOR_FLASH_BLANK_VERIFICATION) && !defined(MT6205B))
         #ifndef __PRODUCTION_RELEASE__
         {
            kal_uint32 region = 0, BlockUpperBound = 0;

            INT_RestoreDataCache(data_cache_id);
            RestoreIRQMask(savedMask);

            BlockUpperBound = D->RegionInfo[0].RegionBlocks;
            while((BlockUpperBound <= BlockIndex) && D->RegionInfo[region].RegionBlocks)
            {
               region++;
               BlockUpperBound += D->RegionInfo[region].RegionBlocks;
            }
            for(idx = 0 ; idx < (D->RegionInfo[region].BlockSize/sizeof(FLASH_CELL)); idx++)
            {
               if(fp[idx] != 0xFFFF)
               {
                  /* illegal state */
               #ifdef __PRODUCTION_RELEASE__
                  fp[0] = CMD_RESET;
               #endif
                  SNOR_MTD_ASSERT(0, (kal_uint32)&fp[idx], fp[idx], idx);/* something wrong */
               }
            }
         }
         return FS_NO_ERROR;
         #endif /* __PRODUCTION_RELEASE__ */
         #endif /* NOR_FLASH_BLANK_VERIFICATION && !MT6205B */
         status = FS_NO_ERROR;
      }
      else
      {
         #ifdef __PRODUCTION_RELEASE__
         fp[0] = CMD_RESET;/* ensure flash in read mode */
         #endif
         SNOR_MTD_ASSERT(0, s1, s2, 0);
      }
   }
   CHECK_LOG_STOP(sla_id[12])

   INT_RestoreDataCache(data_cache_id);

   #if !defined(MT6205B)
   RestoreIRQMask(savedMask);
   #endif

   #ifndef __PRODUCTION_RELEASE__
   SNOR_MTD_ASSERT(status != FS_DATA_ERROR, 0, 0, 0);
   #endif
   return status;
}
#else
static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   FLASH_CELL s1, s2;
   kal_uint32 data_cache_id;
    
#ifndef __PRODUCTION_RELEASE__
   static kal_uint32 test_times=0;
#endif

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif
   
   data_cache_id = INT_DisableDataCache();

   s1 = fp[1];
   s2 = fp[1];
   if (((s1 ^ s2) & TOGGLE_ERASE_SUSPEND))
   {
      if(!((s1 ^ s2) & TOGGLE_BUSY))
      {
         /* flash is erase suspended */
         fp[0] = CMD_RESU_SEC_ERASE;
      }
      INT_RestoreDataCache(data_cache_id);
      return FS_FLASH_ERASE_BUSY;
   }
   else
   {
      s1 = fp[1];
      s2 = fp[1];
   
      if(s2 == 0xffff)
      {
         INT_RestoreDataCache(data_cache_id);
#ifndef __PRODUCTION_RELEASE__
         test_times = 0;
#endif
         return FS_NO_ERROR;
      }
      else
      {
         /* the erase operation is reset abnormally */
         if(!(s1 ^ s2))
         {
#ifndef __PRODUCTION_RELEASE__

            /* MAUI_00218339: S71PL129JB0BAW9U need another busy time before     */
            /* polling, modify to allow second erase command to solve this issue */
            test_times++;
            if (test_times > 1)  
               ASSERT(0);
#endif
            EraseCommand_AMD(fp);
         }
         INT_RestoreDataCache(data_cache_id);
         return FS_FLASH_ERASE_BUSY;
      }
   }
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
/*-----------------------------------*/
static int SuspendErase_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   FLASH_CELL s;
   kal_uint32 data_cache_id;
   
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #if (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint32 savedMask;
   #ifdef DEBUG
   //EraseBlock: block not mapped
   SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)BlockAddress(D, BlockIndex), BlockIndex);
   #elif !defined(_LOW_COST_SINGLE_BANK_FLASH_)
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   #endif
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

#if (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   CHECK_LOG_START(sla_id[15])
#endif   

   data_cache_id = INT_DisableDataCache();
   
   fp[0]     = CMD_SUSP_SEC_ERASE;

   s = fp[0];
   while(!(s&POLL_BUSY))
      s = fp[0];

   INT_RestoreDataCache(data_cache_id);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_TRUE;
#endif

#if (defined(_LOW_COST_SINGLE_BANK_FLASH_)  || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   CHECK_LOG_STOP(sla_id[15])
   RestoreIRQMask(savedMask);
#endif    

   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int ResumeErase_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
#endif 
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      //EraseBlock: block not mapped
      SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)BlockAddress(D, BlockIndex), BlockIndex);
      #else
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   #endif
#else 
   CHECK_LOG_START(sla_id[16])
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
#endif   

   fp[0]     = CMD_RESU_SEC_ERASE;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_FALSE;
   RestoreIRQMask(savedMask);
#endif

   CHECK_LOG_STOP(sla_id[16])
   return FS_NO_ERROR;
}

#if defined(__FOTA_ENABLE__)
static int LockEraseBlkAddr_AMD(void * DriveData, void *BlkAddr,UINT ACTION)
{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) BlkAddr;

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
      EraseCommand_AMD(fp);
#ifdef __SPANSION_PL_N__
   DelayAWhile_AMD();
#endif
      WaitReady_AMD((kal_uint32)fp,0xFFFF);
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}
#endif /* __FOTA_ENABLE__ */

/********************************************/
/*                                          */
/*           FDM5.0 MTD SUPPORT             */
/*                                          */
/********************************************/
#ifdef __NOR_FDM5__

static int MountDevice_AMD(void * DriveData, void * Info)
{
   NOR_MTD_DATA * D = DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   kal_uint32 TotalPhysicalPages;
   kal_uint32 TblEntryShift=0,j=1;

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

   return FS_NO_ERROR;
}

static int ShutDown_AMD(void * DriveData)
{
   NOR_MTD_DATA * D = DriveData;
   NORBankInfo * BankInfo = D->LayoutInfo->BankInfo;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr; 
   FLASH_CELL s1, s2; 
   kal_uint32 i=0,j=0;

   for(i=0;BankInfo[i].Banks !=0;i++)
      for(j=0;j<BankInfo[i].Banks;j++)
      {
         while(1)
         {
            s1 = fp[0];
            s2 = fp[0];
            if ((s1 ^ s2)==0)
               break;
            else
            {
               if(s2 & TOGGLE_TIMEOUT)
               {
                  s1 = fp[0];
                  s2 = fp[0];
                  if ((s1 ^ s2)==0)
                     break;
                  else
                  {
                     fp[0] = CMD_RESET;
                     break;
                  }
               }
            }
         }
         fp= (volatile FLASH_CELL*)((kal_uint32)fp + (kal_uint32)BankInfo[i].BankSize);
      }

   return FS_NO_ERROR;
}
#endif

#if defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif

/*--------------------------------------------------------------------------
     Single bank NOR flash support
  --------------------------------------------------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */

#ifdef __SPANSION_GL_N__
#define ERASE_ROUNDS (32)
kal_int32 EraseBlockList(void * DriveData, kal_uint32* list, kal_uint32 items)
{
   NOR_Flash_MTD_Data *D = (NOR_Flash_MTD_Data *)DriveData;
   kal_uint32 savedMask;
   kal_uint32 rounds = 0;
   kal_uint32 idx = 0, start = 0;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr; 
   while(items)
   {
      if(items > ERASE_ROUNDS)
         rounds = ERASE_ROUNDS;
      else
         rounds = items;

      savedMask = SaveAndSetIRQMask();
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_SERASE;
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      for(idx = 0; idx < rounds; idx++)
      {
         fp = (volatile FLASH_CELL*)BlockAddress(D, list[idx+start]);
         fp[0] = CMD_SERASE_END;
      }
      D->CurrAddr = (BYTE *)fp;/* for CheckDeviceReady_AMD() use */
      RestoreIRQMask(savedMask);
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(D, list[idx-1+start]));
      start += rounds;
      items -= rounds;
   }
   return 0;
}
#endif/* __SPANSION_GL_N__ */

#if defined(__MAUI_BASIC__) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
void WaitReadyAndResume_AMD(kal_uint32 addr,kal_uint16 data) /* for program operation only */
{
   kal_uint16 stat_data = 0;
   kal_uint32 data_cache_id;
   kal_uint16 data_toggle1 = 0, data_toggle2 = 0;
   kal_uint32 savedMask;
   #if defined(MT6205B)
   kal_uint16 irq_sts = 0;
   #endif

   do
   {
      #ifndef MT6205B
      savedMask = SaveAndSetIRQMask();
      CHECK_LOG_START(sla_id[18])
      data_cache_id = INT_DisableDataCache();
      #else
      data_cache_id = INT_DisableDataCache();
      #endif
      data_toggle1 = *(volatile kal_uint16*)addr;
      data_toggle2 = *(volatile kal_uint16*)addr;
      #ifndef MT6205B
      INT_RestoreDataCache(data_cache_id);
      CHECK_LOG_STOP(sla_id[18])
      RestoreIRQMask(savedMask);
      #endif
      if( (data_toggle1^data_toggle2) & TOGGLE_BUSY )
      {
#ifndef __SST_NOR__
         if( (data_toggle1 & POLL_TIMEOUT) && (data_toggle2 & POLL_TIMEOUT) )
         {
            #ifndef MT6205B
            savedMask = SaveAndSetIRQMask();
            CHECK_LOG_START(sla_id[19])
            data_cache_id = INT_DisableDataCache();
            #else
            data_cache_id = INT_DisableDataCache();
            #endif
            data_toggle1 = *(volatile kal_uint16*)addr;
            data_toggle2 = *(volatile kal_uint16*)addr;
            #ifndef MT6205B
            INT_RestoreDataCache(data_cache_id);
            CHECK_LOG_STOP(sla_id[19])
            RestoreIRQMask(savedMask);
            #endif
            if((data_toggle1^data_toggle2) & TOGGLE_BUSY)
            {
            #ifdef __PRODUCTION_RELEASE__
               *(volatile kal_uint16*)addr = CMD_RESET;
            #endif
               SNOR_MTD_ASSERT(0,data_toggle1,data_toggle2,data);
            }
         }
#endif
      #ifdef MT6205B
      /* check pending IRQ */
         irq_sts = (kal_uint16)*IRQ_STS;
         if(irq_sts)
         {
            INT_RestoreDataCache(data_cache_id);
            Flash_ReturnReady();
            *IRQ_SOFT = irq_sts;
            RestoreIRQMask(g_savedMask);
         }
      #endif
      }
      else
      {
         if( (data_toggle1^data_toggle2) & TOGGLE_ERASE_SUSPEND ) /* operation is suspended */
         {
            #ifndef MT6205B
            savedMask = SaveAndSetIRQMask();
            CHECK_LOG_START(sla_id[20])
            data_cache_id = INT_DisableDataCache();
            #endif
            *(volatile kal_uint16*)addr = CMD_RESU_SEC_ERASE; /* resume suspended operation */
            #ifndef MT6205B
            CHECK_LOG_STOP(sla_id[20])
            RestoreIRQMask(savedMask);
            data_cache_id = INT_DisableDataCache();
            #endif
         }
         else
         {
            #ifndef MT6205B
            savedMask = SaveAndSetIRQMask();
            data_cache_id = INT_DisableDataCache();
            CHECK_LOG_START(sla_id[21])
            #endif
            data_toggle1 = *(volatile kal_uint16*)addr;
            data_toggle2 = *(volatile kal_uint16*)addr;
            #ifndef MT6205B
            CHECK_LOG_STOP(sla_id[21])
            RestoreIRQMask(savedMask);
            data_cache_id = INT_DisableDataCache();
            #endif
            if(data_toggle1 == data_toggle2)
            {
               stat_data = *(volatile kal_uint16*)addr;
               if(stat_data == data)
                  break;/* operation is finished */
               else
               {
               #ifdef __PRODUCTION_RELEASE__
                  *(volatile kal_uint16*)addr = CMD_RESET;
               #endif
                  SNOR_MTD_ASSERT(0,data_toggle1,stat_data,data);
               }
            }
         }
      }
   }while(1);

   return;

}
#endif

/* ------------------------------------------------------------------ */
kal_bool IsEraseSuspended_AMD(void * DriveData, DWORD BlockIndex)
{
   kal_uint16 data_toggle1 = 0, data_toggle2 = 0;
   kal_uint32 data_cache_id = 0, savedMask = 0;
   kal_bool   status = KAL_FALSE;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
      SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)(BlockAddress(D, BlockIndex)), BlockIndex); 
      #else
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
      #endif
   #endif
#else 
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif
   
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && !defined(MT6205B))
   savedMask = SaveAndSetIRQMask();
   CHECK_LOG_START(sla_id[23])
   #endif

   data_cache_id = INT_DisableDataCache();

   data_toggle1 = fp[1];
   data_toggle2 = fp[1];

   INT_RestoreDataCache(data_cache_id);
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && !defined(MT6205B))
   CHECK_LOG_STOP(sla_id[23])
   RestoreIRQMask(savedMask);
   #endif

   if ( (data_toggle1 ^ data_toggle2) & TOGGLE_ERASE_SUSPEND )
   {
      if(!((data_toggle1 ^ data_toggle2) & TOGGLE_BUSY))
      {
         /* flash is erase suspended */
         status = KAL_TRUE;
      }
      status = KAL_FALSE;
   }
   return status;
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/****************************************************************************/
/*                                                                          */
/*                    Support NOR Flash OTP Function                        */
/*                                                                          */
/****************************************************************************/

#ifdef __SECURITY_OTP__

extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

static const kal_uint32 NOR_OTPOffset=0x100;
static const kal_uint32 NOR_OTPLength=0x100;

#define CMD_OTP_ENTRY 0x88
#define CMD_OTP_EXIT  0x90
#define CMD_OTP_ZERO  0x00
#define CMD_AUTOSELECT_ENTRY 0x90
#define CMD_AUTOSELECT_EXIT  0xF0
#define CMD_LOCKREG_ENTRY    0x40
#define CMD_LOCKREG_PROG     0xA0
#define CMD_LOCKREG_EXIT1    0x90
#define CMD_LOCKREG_EXIT2    0x00


#define OTP_ERR_NONE 0
#define OTP_ERR_OVERSCOPE 1
#define OTP_ERR_BUSY 2
#define OTP_ERR_WAIT 3

#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */

kal_int32
OTPCheckWriteReady_AMD(kal_uint32 addr,kal_uint16 data)
{
   kal_uint16 data_test1,data_test2;
   kal_uint32 data_cache_id;
   kal_int32 status = OTP_ERR_NONE;

 
   data_cache_id = INT_DisableDataCache();
   data_test1 = *(volatile kal_uint16*)addr;
   if((data_test1 & POLL_BUSY) == (data & POLL_BUSY))
   {
      data_test1 = *(volatile kal_uint16*)addr;
      data_test2 = *(volatile kal_uint16*)addr;
      if (data_test2 == data)
         status = OTP_ERR_NONE;
      else
      {
         status = OTP_ERR_WAIT;
      }    
   }
   else if(data_test1 & POLL_TIMEOUT) //DQ5 = 1 may imply a timeout happens
   {
      data_test1 = *(volatile kal_uint16*)addr;
      data_test2 = *(volatile kal_uint16*)addr;
           
      if((data_test1 ^ data_test2) & TOGGLE_BUSY)
      {
         status = OTP_ERR_WAIT;
      }
   }
   else
   {
      status = OTP_ERR_BUSY;
   }
   INT_RestoreDataCache(data_cache_id);
   return status;
}

/*************************************************************************
* FUNCTION
*    OTPRead
*
* DESCRIPTION
*    This function implements the OTP read function, first it enter 
*    secured silicon sector, and read data from "Offset", totally read 
*    "Length" bytes, then exit secured silicon sector mode
*
* PARAMETERS
*    D: driver structure
*    Offset: the start position want to read (unit:bytes)
*    BufferPtr: the buffer address want to read to
*    Length: total length want to read (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*
*************************************************************************/

/* While the Secured Silicon Sector access is enabled, simultaneous 
 * operations are not allow fro bank A. 
 */

kal_int32 
OTPRead_AMD(void * DriveData,
            kal_uint32 Offset, 
            void * BufferPtr,
            kal_uint32 Length)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask,i;
   volatile FLASH_CELL *BaseAddr;
   kal_uint8 *src,*dest;
   kal_uint32 data_cache_id;

   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));
   
   BaseAddr = (volatile FLASH_CELL *)INT_RetrieveFlashBaseAddr();
   src = (kal_uint8 *)((kal_uint32)BaseAddr + NOR_OTPOffset + Offset);
   dest =(kal_uint8 *)BufferPtr;
   
   /* Base Addr check */
   ASSERT(!(((kal_uint32)BaseAddr) % sizeof(FLASH_CELL)));
   
   /* check if read scope is out of range */ 
   if( (Offset > NOR_OTPLength) ||
       (Offset+ Length)> NOR_OTPLength )
   {
      return FS_FLASH_OTP_OVERSCOPE;   
   }
   
   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();
   
   /* Enter Secured Silicon Sector Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_ENTRY; 
      
   /* Read Secured Silicon Sector Data */
   for(i=0; i< Length; i++)
      dest[i] = src[i];
   
   /* Exit Secured Silicon Sector Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
   BaseAddr[0] =  CMD_OTP_ZERO;
   
   /* Enable Interrupt */    
   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);
   
   return FS_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*    OTPWrite
*
* DESCRIPTION
*    This function implements the OTP write function, first it enter 
*    secured silicon sector, and write data from "Offset", totally write 
*    "Length" bytes, then exit secured silicon sector mode.
*    Be carefully, do not set bit to one if it is zero
*
* PARAMETERS
*    D: driver structure
*    Offset: the start position want to write (unit:bytes)
*    BufferPtr: the buffer address want to write from
*    Length: total length want to write (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/


kal_int32 
OTPWrite_AMD(void * DriveData,
             kal_uint32 Offset, 
             void * BufferPtr,
             kal_uint32 Length)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask,DoneLength=0;
   volatile FLASH_CELL *BaseAddr;
   FLASH_CELL IndicatorBit;
   kal_int32 status;
   
   kal_uint8 *src,*dest;
   kal_uint16 *dest16;
   FLASH_CELL CELL;
   kal_uint8 *CELLPtr = (kal_uint8 *)&CELL;

   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));
   
   BaseAddr = (volatile FLASH_CELL*)INT_RetrieveFlashBaseAddr();
   dest = (kal_uint8 *)((kal_uint32)BaseAddr + NOR_OTPOffset + Offset);
   src =(kal_uint8 *)BufferPtr;
   
   /* Base Addr check */
   ASSERT(!(((kal_uint32)BaseAddr) % sizeof(FLASH_CELL)));
   
   /* check if read scope is out of range */ 
   if( (Offset > NOR_OTPLength) ||
       (Offset+ Length)> NOR_OTPLength )
   {
      return FS_FLASH_OTP_OVERSCOPE;   
   }
   
   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();
   
   /* Enter Auto Select Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_AUTOSELECT_ENTRY;
   
   IndicatorBit = BaseAddr[3];
   
   /* Exit Auto Select Mode */
   BaseAddr[0] = CMD_AUTOSELECT_EXIT;
   
   /* Enable Interrupt */    
   RestoreIRQMask(savedMask); 
      
   if ((IndicatorBit & 0x40))
   {
      return FS_FLASH_OTP_LOCK_ALREADY;
   } 
   
   while ( DoneLength < Length )
   {
      /* Disable Interrupt */
      savedMask = SaveAndSetIRQMask();
   
      /* Enter Secured Silicon Sector Mode */
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_ENTRY; 
      
      //enter write command to flash 
      if ( ((kal_uint32)dest&(sizeof(FLASH_CELL)-1)) || ((Length-DoneLength)==1) ) //not word align
      {
         kal_uint32 ofs = ((kal_uint32) dest) & (sizeof(FLASH_CELL)-1);
         kal_uint8 *b = (kal_uint8 *)&CELL; 
         
         dest16 = (kal_uint16 *)(((kal_uint32)dest) & ~(sizeof(FLASH_CELL)-1));
         CELL = dest16[0];
         b[ofs] = src[0];
         
      }
      else //word align
      {
         dest16 = (kal_uint16 *)dest;
         CELLPtr[0] = src[0];
         CELLPtr[1] = src[1];
      }
      /*check write content:attempt to set bits in flash (0->1) */
      if((~(dest16[0])) & CELL)
      {
         /* exit secured Silicon Sector Mode */
         BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
         BaseAddr[0] =  CMD_OTP_ZERO; 
         BaseAddr[0] = CMD_RESET; 
         /* Enable Interrupt */    
         RestoreIRQMask(savedMask);
         EXT_ASSERT(0,0,0,0);
      }
      
      //write one word to flash
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_PROG;
      dest16[0] = CELL;
      
      /* check till ready */
      while(1)
      {
         
         status = OTPCheckWriteReady_AMD((kal_uint32)dest16 ,(kal_uint16) CELL);
         if(status == OTP_ERR_NONE)
         {
            break;
         }else if(status == OTP_ERR_WAIT)
         {
            /* exit secured Silicon Sector Mode */
            BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
            BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
            BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
            BaseAddr[0] =  CMD_OTP_ZERO; 
            BaseAddr[0] = CMD_RESET; 
            /* Enable Interrupt */    
            RestoreIRQMask(savedMask);
            EXT_ASSERT(0,0,0,0);
         }         
      }
      /* Exit Secured Silicon Sector Mode */
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
      BaseAddr[0] =  CMD_OTP_ZERO;
      /* Enable Interrupt */    
      RestoreIRQMask(savedMask);
      
      /* addr offset */
      if ( ((kal_uint32)dest&(sizeof(FLASH_CELL)-1)) || ((Length-DoneLength)==1) ) //not word align
      {
         dest+=1;
         src+=1;
         DoneLength+=1;    
      }
      else
      {
         dest+=2;
         src+=2;
         DoneLength+=2; 
      }
   }
   return FS_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*    OTPLock
*
* DESCRIPTION
*    This function implements the OTP lock function. 
* PARAMETERS
*    D: driver structure
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/


kal_int32 
OTPLock_AMD(void * DriveData)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask;
   volatile FLASH_CELL *BaseAddr = (volatile FLASH_CELL*)INT_RetrieveFlashBaseAddr();
   FLASH_CELL IndicatorBit,CELL;
   kal_int32 status;


   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));
   
  
   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();
   
   /* Enter Auto Select Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_AUTOSELECT_ENTRY;
   
   IndicatorBit = BaseAddr[3];
      
   /* Exit Auto Select Mode */
   BaseAddr[0] = CMD_AUTOSELECT_EXIT; 
      
   if ((IndicatorBit & 0x40))
   {
      /* Enable Interrupt */    
      RestoreIRQMask(savedMask);
      return FS_FLASH_OTP_LOCK_ALREADY;
   }
   
   /* Enter Lock Register Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_LOCKREG_ENTRY;
   CELL = BaseAddr[0];
   CELL &= 0xFFFE;
   BaseAddr[0] = CMD_LOCKREG_PROG;
   BaseAddr[0] = CELL;
   DelayAWhile_AMD();    
   
   /* check till ready */
   while( (status = OTPCheckWriteReady_AMD((kal_uint32)BaseAddr ,(kal_uint16) CELL)) != OTP_ERR_NONE)
   {
      if (status == OTP_ERR_WAIT)
      {
         BaseAddr[0] = CMD_RESET;
         /* Enable Interrupt */    
         RestoreIRQMask(savedMask);
         EXT_ASSERT(0,0,0,0);
      }
   }
   
   BaseAddr[0] = CMD_LOCKREG_EXIT1;
   BaseAddr[0] = CMD_LOCKREG_EXIT2;
      
   /* Enable Interrupt */    
   RestoreIRQMask(savedMask);
         
   return FS_NO_ERROR;
}

kal_int32 
OTPAccess_AMD(void * DriveData, kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   if (accesstype==FS_OTP_READ)
   {
      return OTPRead_AMD(DriveData, Offset, BufferPtr,Length);
   }
   else if (accesstype==FS_OTP_WRITE)
   {
      return OTPWrite_AMD(DriveData,Offset,BufferPtr,Length);
   }
   else if (accesstype==FS_OTP_LOCK)
   {
      return OTPLock_AMD(DriveData);
   }
   else
   {
      ASSERT(0);
   }
}

kal_int32   
OTPQueryLength_AMD(void * DriveData, UINT *LengthPtr)
{
   *LengthPtr = NOR_OTPLength;
   return FS_NO_ERROR;
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

# endif /*__SECURITY_OTP__*/

/*-----------------------------------*/
NOR_MTD_Driver DriverName =
{
   MountDevice_AMD,
   ShutDown_AMD,
   MapWindow,
   EraseBlock_AMD,
#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
   ProgramData_TOSHIBA,
#else
   ProgramData_AMD,
#endif
   NonBlockEraseBlock_AMD,
   CheckDeviceReady_AMD,
   SuspendErase_AMD,
   ResumeErase_AMD,
   NULL,
#ifdef __SECURITY_OTP__
   OTPAccess_AMD,
   OTPQueryLength_AMD,
#else
   NULL,
   NULL,
#endif
#if defined(__FOTA_ENABLE__)
   LockEraseBlkAddr_AMD
#else
   NULL
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   ,IsEraseSuspended_AMD
#else
   ,NULL
#endif

};

#endif //__AMD_SERIES_NOR__