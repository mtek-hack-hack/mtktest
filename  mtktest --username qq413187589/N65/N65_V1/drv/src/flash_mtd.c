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
 *	FlashConf.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a flash MTD driver for AMD and Toshiba flash devices.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "flash_mtd.h"
#include "reg_base.h"
#include "intrCtrl.h"

#define CHECK_LOG_START(a) 
#define CHECK_LOG_STOP(a) 

#if ( (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(__MTK_TARGET__) )
kal_uint32 NOR_Flash_Base_Address = 0;
   #pragma arm section code = "SNORCODE"
#endif 

#ifndef __NOR_FDM5__
void * BlockAddress(void* DriverData, kal_uint32 BlockIndex)
{
   NOR_Flash_MTD_Data * D=DriverData;
   kal_uint32 addr  = 0;
   kal_uint32 region = 0, BlockUpperBound = 0;

   BlockUpperBound = D->RegionInfo[0].RegionBlocks;
   while(BlockUpperBound <= BlockIndex)
   {
      addr += D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;
      region++;
      BlockUpperBound += D->RegionInfo[region].RegionBlocks;
   }
   addr += (BlockIndex - (BlockUpperBound-D->RegionInfo[region].RegionBlocks)) * D->RegionInfo[region].BlockSize;

   return (D->BaseAddr + addr);
}

#ifdef __SPANSION_NS_N__
kal_uint32 CalBlkAddr(void* DriverData, kal_uint32 Addr)
{
   NOR_Flash_MTD_Data * D=DriverData;
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;
   
   Addr -= (kal_uint32)D->BaseAddr;
   
   /*calculate the start block index*/
   AddrUpperBound = (D->RegionInfo[region].RegionBlocks) * (D->RegionInfo[region].BlockSize);
   
   do{
      if (AddrUpperBound >= Addr)
         break;
      else
      {
         StartBlkIndex += D->RegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound += D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;
      }
   }while(D->RegionInfo[region].RegionBlocks != 0);

   if(D->RegionInfo[region].RegionBlocks == 0 )
   {
      EXT_ASSERT(0,0,0,0);
   }
   return (kal_uint32)D->BaseAddr + (Addr &(~(D->RegionInfo[region].BlockSize-1)));
}
#endif /*__SPANSION_NS_N__*/
#else /*__NOR_FDM5__*/

void * BlockAddress(void * DriverData, kal_uint32 BlockIndex)
{
   NOR_MTD_DATA * D = DriverData;
   if (BlockIndex >= (D->LayoutInfo->TotalBlks))
		EXT_ASSERT(0,0,0,0);

   return (D->BaseAddr + BlockIndex* (D->LayoutInfo->BlkSize) );
}

#endif
#if  (defined(_LOW_COST_SINGLE_BANK_FLASH_) && defined(__MTK_TARGET__))
   #pragma arm section code
#endif 

/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define INVALID_BLOCK_ENTRY (0xFFFFFFFF)

#ifdef __MTK_TARGET__
#if defined(MT6205B)
   #pragma arm section code = "SNORCODE", rwdata = "SNORRW", zidata = "SNORZI"
#endif
#endif

#if defined(MT6205B)
kal_uint32 SNOR_IRQ_STATUS = 0;
#endif
kal_bool NOR_FLASH_BUSY = KAL_FALSE;
kal_bool NOR_FLASH_SUSPENDED = KAL_FALSE;

#if defined(MT6205B)

NOR_AddrLookup addr_lookup_tbl[LOOKUP_TABLE_SIZE][2];

kal_uint32 CHECK_PENDING_IRQ(kal_uint32 irq_mask, kal_uint32 address)
{
   kal_uint16 irq_sts = 0;
   volatile FLASH_CELL *flash_ptr = (volatile FLASH_CELL *)address;
   irq_sts = *IRQ_STS;
   if(irq_sts)
   {
      *IRQ_EOI = irq_sts;
      *IRQ_SOFT = irq_sts;
      SNOR_IRQ_STATUS = irq_sts;
      /*make sure this access is not pending on bus*/
      irq_sts = *IRQ_SOFT;
      Flash_ReturnReady();
      RestoreIRQMask(irq_mask);
      irq_mask = SaveAndSetIRQMask();
      /*work around method, sometimes IRQ_SOFT will not trigger IRQ*/
      irq_sts = *IRQ_SOFT;
      while(irq_sts)
      {
         *IRQ_EOI = irq_sts;
         *IRQ_SOFT = irq_sts;
         /*make sure this access is not pending on bus*/
         irq_sts = *IRQ_SOFT;
         RestoreIRQMask(irq_mask);
         irq_mask = SaveAndSetIRQMask();
         irq_sts = *IRQ_SOFT;
      }
   }
   if(NOR_FLASH_SUSPENDED)
   {
      #if !defined(__PRODUCTION_RELEASE__)
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, address, SNOR_IRQ_STATUS, *IRQ_SOFT);
      #endif
      *flash_ptr = CMD_RESU_SEC_ERASE;
      NOR_FLASH_SUSPENDED = KAL_FALSE;
   }
   return irq_mask;
}

static DWORD LookupAddress(void * DriveData, DWORD BlockIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;
   DWORD  addr = 0;
   static DWORD replaced = 0;
   static DWORD look_up_hit = 0;
   static DWORD look_up_miss = 0;
   if( addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != INVALID_BLOCK_ENTRY )
   {
      if(addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != BlockIndex)
      {
         if(addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != INVALID_BLOCK_ENTRY)
         {
            if(addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != BlockIndex)
            {
               look_up_miss++;
               if( replaced & (0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))) )
               {
                  addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
                  addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
                  replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
               }
               else
               {
                  addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
                  addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
                  replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
               }
            }
            else
            {
               look_up_hit++;
               addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress;
               replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
            }
         }
         else
         {
            look_up_miss++;
            addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
            addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
            replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
         }
      }
      else
      {
         look_up_hit++;
         addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress;
         replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
      }
   }
   else
   {
      look_up_miss++;
      addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
      addr = addr_lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
      replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
   }
   return addr;
}
#else
static DWORD LookupAddress(void * DriveData, DWORD BlockIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;
   DWORD  addr = 0;
   static DWORD replaced = 0;
   static DWORD look_up_hit = 0;
   static DWORD look_up_miss = 0;
   if( D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != INVALID_BLOCK_ENTRY )
   {
      if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != BlockIndex)
      {
         if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != INVALID_BLOCK_ENTRY)
         {
            if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != BlockIndex)
            {
               look_up_miss++;
               if( replaced & (0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))) )
               {
                  D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
                  addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
                  replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
               }
               else
               {
                  D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
                  addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
                  replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
               }
            }
            else
            {
               look_up_hit++;
               addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress;
               replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
            }
         }
         else
         {
            look_up_miss++;
            D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
            addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
            replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
         }
      }
      else
      {
         look_up_hit++;
         addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress;
         replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
      }
   }
   else
   {
      look_up_miss++;
      D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
      addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (DWORD)BlockAddress(D, BlockIndex);
      replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
   }
   return addr;
}
#endif

#ifdef __MTK_TARGET__
#if defined(MT6205B)
   #pragma arm section code, rwdata, zidata
#endif
#endif

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__*/
/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)

#ifdef __MULTI_BANK_NOR_DEVICE__
void MapBank(NOR_Flash_MTD_Data * D)
{ 
   kal_uint32 offset = (kal_uint32)D->CurrAddr - (kal_uint32)D->BaseAddr;
   kal_uint32 Partiton =0;
   kal_uint32 Addr=0;
   kal_uint32 BankAddrUpperBound = D->BankInfo[Partiton].BankSize * D->BankInfo[Partiton].Banks;
   
   while(offset >= BankAddrUpperBound )
   {
      Addr += BankAddrUpperBound;
      offset -= BankAddrUpperBound;
      Partiton++;
      BankAddrUpperBound = D->BankInfo[Partiton].BankSize * D->BankInfo[Partiton].Banks;
   }
   Addr += ((offset/D->BankInfo[Partiton].BankSize)*D->BankInfo[Partiton].BankSize);
   D->CurrBankAddr = D->BaseAddr + Addr;
   D->CurrBankSize = D->BankInfo[Partiton].BankSize;
   return;
}
#endif /*__MULTI_BANK_NOR_DEVICE__*/
void * MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;

   /* MapWindow: window index greater zero */
   ASSERT(WindowIndex == 0);
   D->CurrAddr = (void *)LookupAddress(D, BlockIndex);

#ifdef __MULTI_BANK_NOR_DEVICE__
   if (((kal_uint32)D->CurrAddr) < ((kal_uint32)D->CurrBankAddr) ||
      ((kal_uint32)D->CurrAddr) >= ((kal_uint32)D->CurrBankAddr + (kal_uint32)D->CurrBankSize))
   {
      MapBank(D);
   }
   if(((kal_uint32)D->CurrAddr) == ((kal_uint32)D->CurrBankAddr) )
   {
      D->CurrPollAddr = (void*)((kal_uint32)D->CurrBankAddr+(kal_uint32)D->CurrBankSize - 4);
   }
   else
   {
      D->CurrPollAddr = D->CurrBankAddr;
   }  
#endif /*__MULTI_BANK_NOR_DEVICE__*/

   return D->CurrAddr;
}

#else /*!defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
void * MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;

   /* MapWindow: window index greater zero */
   ASSERT(WindowIndex == 0);
   return D->CurrAddr = BlockAddress(D, BlockIndex);
}
#endif /*defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__*/

