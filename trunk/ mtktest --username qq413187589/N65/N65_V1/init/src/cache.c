/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/


/*******************************************************************************
 * Include header files.
 *******************************************************************************/

#include "kal_release.h"
#include "reg_base.h"
#include "cache_hw.h"
#include "cache_sw.h"
#include "init.h"
#include "cp15.h"
#include "mmu.h"
#include "dma_hw.h"
#include "usb_hw.h"


#ifdef __MTK_TARGET__

/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6238)

extern kal_uint32 Image$$ROM$$Base;
extern kal_uint32 Image$$INTSRAM_CODE$$Base;
extern kal_uint32 Image$$INTSRAM_CODE$$Limit;

#ifdef _NAND_FLASH_BOOTING_ 

extern kal_uint32 Image$$ROM$$Length;
extern kal_uint32 Image$$PRIMARY_EXTSRAM$$Base;
extern kal_uint32 Image$$SECONDARY_ROM$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
extern kal_uint32 Image$$DUMMY_END$$Base;
#else   /* _NAND_FLASH_BOOTING_ */
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
#endif   /* _NAND_FLASH_BOOTING_ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

extern kal_uint32 Image$$SINGLE_BANK_CODE$$Base;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$Limit;
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#endif  /* MT6228 || MT6229 || MT6230 || MT6225 || MT6238 */


/*******************************************************************************
 * Define import functions.
 *******************************************************************************/

extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_uint32 custom_get_1st_ROM_Length(void);
extern kal_uint32 custom_get_2nd_ROM_Length(void);
extern void custom_get_EXTSRAM_size(kal_uint32 *size);
extern kal_uint32 custom_get_fat_addr(void);
extern kal_uint32 custom_get_fat_len(void);
extern void INT_GetSysMemoryInfo(kal_uint32 **info, kal_uint16 *count);
extern void custom_get_MaxAvailableMemorySegment(kal_uint32 **start_ptr, kal_uint32 *available_length);

/*
 * Contant definitions.
 */
#define SIZE_1KB  0x400
#define SIZE_4MB  0x400000
#define SIZE_16MB 0x1000000

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6238)

#ifdef _NAND_FLASH_BOOTING_ 
#define ROMStartAddress          (kal_uint32)&Image$$ROM$$Base
#define ROMLength                (kal_uint32)&Image$$ROM$$Length
#define ROMEndAddress            (kal_uint32)&Image$$PRIMARY_EXTSRAM$$Base
#define RAMStartAddress          (kal_uint32)&Image$$PRIMARY_EXTSRAM$$Base
#define RAMLength                ((kal_uint32)&Image$$SECONDARY_ROM$$Base - RAMStartAddress)
#define FATTYROMStartAddress     (kal_uint32)&Image$$SECONDARY_ROM$$Base
#define FATTYROMEndAddress       (kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base
#define FATTYRAMStartAddress     (kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base
#define FATTYRAMLength           ((kal_uint32)&Image$$DUMMY_END$$Base - FATTYRAMStartAddress)
#else /* _NAND_FLASH_BOOTING_ */

#define ROMStartAddress          (kal_uint32)((kal_uint32)&Image$$ROM$$Base & 0xf8000000)
#define ROMLength                custom_get_1st_ROM_Length()
#define ROMEndAddress            (ROMStartAddress + custom_get_NORFLASH_ROMSpace())
#define RAMStartAddress          (kal_uint32)((kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base & 0xf8000000)
#define RAMLength                0    /* for NFB compatible only; query at run time */
#endif /* _NAND_FLASH_BOOTING_ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

#define RAMCODEStartAddress      ((kal_uint32)&Image$$SINGLE_BANK_CODE$$Base & ~(SIZE_1KB-1))
#define RAMCODEEndAddress        (kal_uint32)((kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base)

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#define INTSRAMCODEStartAddress  (kal_uint32)&Image$$INTSRAM_CODE$$Base
#define INTSRAMCODERange         (kal_uint32)(((kal_uint32)&Image$$INTSRAM_CODE$$Limit) & 0x0fffffff)

#endif  /* MT6228 || MT6229 || MT6230 || MT6225 || MT6238 */

#if defined(MT6228) || defined(MT6229) || defined(MT6230)
#define MAX_MPU_CHANNEL_LEN      (SIZE_4MB)
#define MAX_CACHE_CHANNEL_LEN    (SIZE_4MB)
#define MIN_MPU_CHANNEL_LEN      (SIZE_1KB)
#define MIN_CACHE_CHANNEL_LEN    (SIZE_1KB)
#define CACHE_SIZE_INDEX         (12)
#define CACHE_CHANNEL_NUM        (8)
#define MPU_SIZE_INDEX           (12)
#define MPU_CHANNEL_NUM          (8)
#endif /* MT6228 || MT6229 || MT6230 */

#if defined(MT6225)
#define MAX_MPU_CHANNEL_LEN     (SIZE_16MB)
#define MAX_CACHE_CHANNEL_LEN   (SIZE_16MB)
#define MIN_MPU_CHANNEL_LEN     (SIZE_1KB)
#define MIN_CACHE_CHANNEL_LEN   (SIZE_1KB)
#define CACHE_SIZE_INDEX        (14)
#define CACHE_CHANNEL_NUM       (8)
#define MPU_SIZE_INDEX          (14)
#define MPU_CHANNEL_NUM         (8)
#endif /* MT6225 */

#if defined(MT6238)
#define FATStartAddress          (custom_get_fat_addr() | INT_RetrieveFlashBaseAddr())
#define FATLength custom_get_fat_len()
#define BBRegStartAddress 0x80000000
#define BBRegLength 0x4200000
#endif  /* MT6238 */


/*******************************************************************************
 * Define global data.
 *******************************************************************************/

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
static kal_uint16 MPUChannelStatus = 0;
static kal_uint16 CodeCacheChannelStatus = 0;
#endif  /* MT6228 || MT6229 || MT6230 || MT6225 */

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
static kal_bool l2c_fbbr = 0, l2c_mpeg4 = 0;
#endif /* MT6228 || MT6229 || MT6230 || MT6238 */

#if defined(__ARM9_MMU__)

#pragma arm section zidata = "PAGETABLE"
/* page table */
static __align(16 * 1024) kal_uint32 page_tbl[4096];
#pragma arm section zidata

kal_uint32 *fpt_pool, fpt_pool_indx, fpt_pool_size, *cpt_pool, cpt_pool_indx, cpt_pool_size;

#endif  /* __ARM9_MMU__ */


#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)

/*************************************************************************
* FUNCTION
*  GateDG
*
* DESCRIPTION
*  This function used to gate DMA and GMC.
*  NoteXXX: This function is dedicated for IDLE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/
kal_uint32 GateDG(void)
{
   kal_uint32 val = 0;

   /* NoteXXX: no need to disable IRQ since idle task already did it */

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
      val |= DataCacheLocking2Way;

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* get DMA and GMC */
   val |= DataCacheGATEDG;

   *L2C_CON = val | DataCacheEnabled;

   /* no need to wait for data cache ready since it will block all accesses automatically */
//   DataCacheWaitCommandReady();

   return 0;
}


/*************************************************************************
* FUNCTION
*  UngateDG
*
* DESCRIPTION
*  This function used to un-gate DMA and GMC.
*  NoteXXX: This function is dedicated for IDLE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/
void UngateDG(kal_uint32 val)
{
   val = 0;

   /* NoteXXX: no need to disable IRQ since idle task already did it */

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
      val |= DataCacheLocking2Way;

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* un-gate DMA and GMC */
   *L2C_CON = val | DataCacheEnabled;

   /* no need to wait for data cache ready since it will block all accesses automatically */
//   DataCacheWaitCommandReady();
}


/*************************************************************************
* FUNCTION
*  EnableFBBR
*
* DESCRIPTION
*  This function used to eanble FBBR.
*  NoteXXX: This function is dedicated for JAVA.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/
kal_uint32 EnableFBBR(void)
{
   kal_uint32 saved, val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_fbbr = KAL_TRUE;

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
      val |= DataCacheLocking2Way;

   /* enable FBBR */
   val |= DataCacheFBBR;
   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();

   return 0;
}


/*************************************************************************
* FUNCTION
*  DisableFBBR
*
* DESCRIPTION
*  This function used to disable FBBR.
*  NoteXXX: This function is dedicated for JAVA.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/
void DisableFBBR(kal_uint32 val)
{
   kal_uint32 saved;

   val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_fbbr = KAL_FALSE;

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
      val |= DataCacheLocking2Way;

   /* disable FBBR */
   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();
}


/*************************************************************************
* FUNCTION
*  Lock2WaysForMPEG4
*
* DESCRIPTION
*  This function used to lock 2 cache ways for VIDEO ENCODE.
*  NoteXXX: this function is dedicated for VIDEO ENCODE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/
kal_uint32 Lock2WaysForMPEG4(void)
{
   kal_uint32 saved, val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* set flag */
   l2c_mpeg4 = KAL_TRUE;

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* lock 2 cache ways */
   val |= DataCacheLocking2Way;
   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();

   return 0;
}


/*************************************************************************
* FUNCTION
*  Unlock2WaysForMPEG4
*
* DESCRIPTION
*  This function used to unlock 2 ways reserved by VIDEO ENCODE.
*  NoteXXX: This function is dedicated for VIDEO ENCODE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/
void Unlock2WaysForMPEG4(kal_uint32 val)
{
   kal_uint32 saved;

   val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_mpeg4 = KAL_FALSE;

   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* un-lock 2 cache ways */
   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();
}

#endif  /* MT6228 || MT6229 || MT6230 || MT6238 */


/*************************************************************************
* FUNCTION
*  invalidate_arm9_dcache
*
* DESCRIPTION
*  This function invalidates the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
#if defined(__ARM9_MMU__)

   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   static const kal_uint32 line_size_mask = 0x0000001F, line_size = 0x00000020;
   kal_uint32 i;


   if (addr & line_size_mask) {
      EXT_ASSERT(0, addr, len, 0);
   } else if (len & line_size_mask) {
      EXT_ASSERT(0, addr, len, 0);
   } else {
      for (i = len; i != 0; i -= line_size) {
         cp15_invalidate_dcache_single(addr + i - line_size);
      }
   }

   return 0;
   
#else   /* __ARM9_MMU__ */

   return -1;

#endif  /* __ARM9_MMU__ */
}


/*************************************************************************
* FUNCTION
*  clean_arm9_dcache
*
* DESCRIPTION
*  This function cleans the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 clean_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
#if defined(__ARM9_MMU__)

   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   static const kal_uint32 line_size_mask = 0x0000001F, line_size = 0x00000020;
   kal_uint32 i;


   if (addr & line_size_mask) {
      EXT_ASSERT(0, addr, len, 0);
   } else if (len & line_size_mask) {
      EXT_ASSERT(0, addr, len, 0);
   } else {
      for (i = len; i != 0; i -= line_size) {
         cp15_clean_dcache_single(addr + i - line_size);
      }
   }

   /* drain write buffer to ensure data is flushed */
   cp15_drain_write_buffer();

   return 0;

#else   /* __ARM9_MMU__ */

   return -1;

#endif  /* __ARM9_MMU__ */
}


#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)

/*************************************************************************
* FUNCTION
*  MPUGetChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
* RETURNS
*
*************************************************************************/
kal_bool MPUGetChannel(kal_uint16 *channel)
{
   kal_uint16  i, status;
   kal_uint32  interruptMask;
      
   interruptMask = SaveAndSetIRQMask();
   
   status = MPUChannelStatus;
   
   for (i=0; i<MPU_CHANNEL_NUM; i++)
   {
      if ( status&0x01)
         status >>= 1;
      else
         break;
   }
   
   if ( i>=MPU_CHANNEL_NUM )
   {
      RestoreIRQMask(interruptMask);   
      return KAL_FALSE;
   }  
   
   *channel = i;
   MPUChannelStatus |= (0x01 << i);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  MPUFreeChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*   
*
* RETURNS
*
*************************************************************************/
kal_bool MPUFreeChannel(kal_uint16 *channel)
{   
   kal_uint16  channel_no = *channel;
   kal_uint32  interruptMask;
   
   ASSERT(channel_no<MPU_CHANNEL_NUM);
   
   interruptMask = SaveAndSetIRQMask();
   
   MPUChannelStatus &= ~(0x01 << channel_no);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  CodeCacheGetChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
* RETURNS
*
*************************************************************************/
kal_bool CodeCacheGetChannel(kal_uint16 *channel)
{
   kal_uint16  i, status;
   kal_uint32  interruptMask;
      
   interruptMask = SaveAndSetIRQMask();
   
   status = CodeCacheChannelStatus;
   
   for (i=0; i<CACHE_CHANNEL_NUM; i++)
   {
      if ( status&0x01)
         status >>= 1;
      else
         break;
   }
   
   if ( i>=CACHE_CHANNEL_NUM )
   {
      RestoreIRQMask(interruptMask);   
      return KAL_FALSE;
   }  
   
   *channel = i;
   CodeCacheChannelStatus |= (0x01 << i);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  CodeCacheFreeChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*   
*
* RETURNS
*
*************************************************************************/
kal_bool CodeCacheFreeChannel(kal_uint16 *channel)
{   
   kal_uint16 channel_no = *channel;
   kal_uint32 interruptMask;
   
   ASSERT(channel_no<CACHE_CHANNEL_NUM);
   
   interruptMask = SaveAndSetIRQMask();
   
   CodeCacheChannelStatus &= ~(0x01 << channel_no);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}


#pragma arm section code = "INTERNCODE"

/*************************************************************************
* FUNCTION
*  CodeCacheConifg
*
* DESCRIPTION
*   This function could be used to configure code cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void CodeCacheConfig(CacheType type, kal_bool enable)
{  
   kal_uint32  interruptMask;
   
   interruptMask = SaveAndSetIRQMask();

   *CACHE_CON &= ~(0x0d);
   /* Invalid all cache line */
   *CACHE_OP = 0x03;
   /* Reset counters */
   *CACHE_HCNT0L = 0x00;
   *CACHE_HCNT0U = 0x00;
   *CACHE_CCNT0L = 0x00;
   *CACHE_CCNT0U = 0x00;
   *CACHE_HCNT1L = 0x00;
   *CACHE_HCNT1U = 0x00;
   *CACHE_CCNT1L = 0x00;
   *CACHE_CCNT1U = 0x00;
   
   if ( enable && (type!=NO_CACHE) )
      *CACHE_CON |= (type | 0x0d);
      
   RestoreIRQMask(interruptMask);
}


/*************************************************************************
* FUNCTION
*  CodeCacheSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  cacheable region.
*
* RETURNS
*
*************************************************************************/
void CodeCacheSetting(CacheMenuType *cacheMenu)
{
   kal_uint32  setting, range, index, size;
   kal_uint32  interruptMask;

   ASSERT (cacheMenu->c_channel<CACHE_CHANNEL_NUM);
   ASSERT (cacheMenu->c_range<=MAX_CACHE_CHANNEL_LEN);
        
   /* Look forward the least-fit range */
   index = CACHE_SIZE_INDEX;
   size = MAX_CACHE_CHANNEL_LEN;
   range = cacheMenu->c_range;
   while ( range<size )
   {
      index--;
      size >>= 1;
      ASSERT(size >= MIN_CACHE_CHANNEL_LEN);
   }
   range = (RegionSize)((index)<<1);
   
   setting = ((cacheMenu->c_addr & (0xffffffff << index)) & 0xfffffc00) | range;
   if ( cacheMenu->c_enable )
      setting |= 0x41;
      
   interruptMask = SaveAndSetIRQMask();
   
   *(MPU_CACHE0+cacheMenu->c_channel) = setting;
   
   RestoreIRQMask(interruptMask);
}


/*************************************************************************
* FUNCTION
*  MPUSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  protectable region.
*
* RETURNS
*
*************************************************************************/
void MPUSetting(MPUMenuType *menu)
{
   kal_uint32 setting, range, index, size;
   kal_uint32 interruptMask;

   ASSERT (menu->m_channel<MPU_CHANNEL_NUM);
   ASSERT (menu->m_range<=MAX_MPU_CHANNEL_LEN);

   /* Look forward the least-fit range */
   /* Look forward the least-fit range */
   index = MPU_SIZE_INDEX;
   size = MAX_MPU_CHANNEL_LEN;
   range = menu->m_range;
   while ( range<size )
   {
      index--;
      size >>= 1;
      ASSERT(size >= MIN_MPU_CHANNEL_LEN);
   }
   range = (RegionSize)((index)<<1);
   
   setting = ((menu->m_addr & (0xffffffff << index)) & 0xfffffc00) | menu->m_attribute | range;
   if ( menu->m_enable )
      setting |= 0x01;
      
   interruptMask = SaveAndSetIRQMask();
   
   *(MPU_PORT0+menu->m_channel) = setting;
   *CACHE_CON |= 0x02;
   
   RestoreIRQMask(interruptMask);
}

/*************************************************************************
* FUNCTION
*  CacheAccessHitCount
*
* DESCRIPTION
*  Return the hit count on code cache, the first 4 regions are collected on
*  group 1, while others at group 2.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void CacheAccessHitCount(CodeCacheHitCount *ret)
{
   ret->hitCount1 = *(volatile kal_uint64 *)(CACHE_HCNT0L);
   ret->accessCount1 = *(volatile kal_uint64 *)(CACHE_CCNT0L);
   
   ret->hitCount2 = *(volatile kal_uint64 *)(CACHE_HCNT1L);
   ret->accessCount2 = *(volatile kal_uint64 *)(CACHE_CCNT1L);
}

#endif  /* MT6228 || MT6229 || MT6230 || MT6225 */


#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)

/*************************************************************************
* FUNCTION
*  DataCacheConfig
*
* DESCRIPTION
*  This function used to configure Data cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool DataCacheConfig(kal_bool enable, kal_bool reservedForMPEG4)
{
   kal_uint32 tempValue;
   kal_uint32 interruptMask;
   kal_bool   status;
   
   interruptMask = SaveAndSetIRQMask();
   
   // Bypass data cache
   *L2C_CON = DataCacheDisabled;
   // Wait for command finishing
   DataCacheWaitCommandReady();
   
   // Invalidate all cache lines
   *L2C_CON = DataCacheInvalidateAll;
   // Wait for command finishing
   DataCacheWaitCommandReady();
   
   if ( enable )
   {      
      tempValue = DataCacheEnabled;
      
      if ( reservedForMPEG4 )
          tempValue |= DataCacheLocking2Way;
         
      *L2C_CON = tempValue;
             
      // Wait for command finishing
      DataCacheWaitCommandReady();
      
      status = KAL_TRUE;
   }
   else
      status = KAL_FALSE;
      
   RestoreIRQMask(interruptMask);
  
   return status;
}

#endif  /* MT6228 || MT6229 || MT6230 || MT6238 */

#pragma arm section code


/*************************************************************************
* FUNCTION
*  SetupMPUbyROMSegment
*
* DESCRIPTION
*  This function used to configure the MPU by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
static void
SetupMPUbyROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size)
{
   MPUMenuType    MPUsetting;
   kal_uint32     size;
   kal_bool       retval;

   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;   

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;   

   /* check start address align to MIN_MPU_CHANNEL_LEN */
   ASSERT( (start_addr & (MIN_MPU_CHANNEL_LEN-1)) == 0x0 );

   /* check end address & start address + total_size */
   ASSERT( start_addr + total_size <= end_addr );

   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_MPU_CHANNEL_LEN; size <= MAX_MPU_CHANNEL_LEN; size <<= 1) {

         /* check if the start address is aligned to the size */
         if (start_addr & (size-1)) {
               
            /* not aligned */

            /* revert to the previous size */
            size >>= 1;

            break;

         }

         /* check if size best hit */
         if (size == total_size) {
            
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {

            /* check if the configuration of this size will overwrite the next region */
            if ((start_addr + size) > end_addr) {

               /* revert to the previous size */
               size >>= 1;

            }

            /* find the fit size and exit */
            break;
         }

         /* exit when reach max size */
         if (size == MAX_MPU_CHANNEL_LEN) {

            break;
         }

      } /* for ( size = MIN_MPU_CHANNEL_LEN ... MAX_MPU_CHANNEL_LEN ) */

      /* specify the start address of MPU setting */
      MPUsetting.m_addr = start_addr;

      /* specify the range of MPU setting */
      MPUsetting.m_range = size;

      /* get a MPU cahnnel */
      retval = MPUGetChannel(&MPUsetting.m_channel);

      /* ensure that a channel is available */
      ASSERT(retval == KAL_TRUE);

      /* configure the MPU */
      MPUSetting(&MPUsetting);
   
      /* move start_addr to the next address */
      start_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {

         /* no remaining part */

         total_size = 0;

      } else {

         total_size -= size;
      }
   }
}
#endif   /* MT6228 || MT6229 || MT6230 || MT6225 */

/*************************************************************************
* FUNCTION
*  SetupCACHEbyROMSegment
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
static void
SetupCACHEbyROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size)
{
   CacheMenuType  CACHEsetting;
   kal_uint32     size;
   kal_bool       retval;

   /* specify enable flag of CACHE setting */
   CACHEsetting.c_enable = 1;      

   /* check start address align to MIN_CACHE_CHANNEL_LEN */
   ASSERT( (start_addr & (MIN_CACHE_CHANNEL_LEN-1)) == 0x0 );

   /* check end address & start address + total_size */
   ASSERT( start_addr + total_size <= end_addr );
   
   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_CACHE_CHANNEL_LEN; size <= MAX_CACHE_CHANNEL_LEN; size <<= 1) {

         /* check if the start address is aligned to the size */
         if (start_addr & (size-1)) {
               
            /* not aligned */

            /* revert to the previous size */
            size >>= 1;

            break;

         }

         /* check if size best hit */
         if (size == total_size) {
            
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {

            /* check if the configuration of this size will overwrite the next region */
            if ((start_addr + size) > end_addr) {

               /* revert to the previous size */
               size >>= 1;

            }

            /* find the fit size and exit */
            break;
         }

         /* exit when reach max size */
         if (size == MAX_CACHE_CHANNEL_LEN) {

            break;
         }

      } /* for ( size = MIN_CACHE_CHANNEL_LEN ... MAX_CACHE_CHANNEL_LEN ) */

      /* specify the start address of CACHE setting */
      CACHEsetting.c_addr = start_addr;

      /* specify the range of CACHE setting */
      CACHEsetting.c_range = size;

      /* get a CACHE cahnnel */
      retval = CodeCacheGetChannel(&CACHEsetting.c_channel);

      /* ensure that a channel is available */
      ASSERT(retval == KAL_TRUE);

      /* configure the CACHE */
      CodeCacheSetting(&CACHEsetting);

      /* move start_addr to the next address */
      start_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {

         /* no remaining part */

         total_size = 0;

      } else {

         total_size -= size;
      }
   }
}
#endif   /* MT6228 || MT6229 || MT6230 || MT6225 */

/*************************************************************************
* FUNCTION
*  SetupMPUonTCM
*
* DESCRIPTION
*  This function used to configure the MPU on TCM
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
static void
SetupMPUonTCM(void)
{
   MPUMenuType    MPUsetting;
   kal_bool retval;

   /* specify the start address */
   MPUsetting.m_addr = INTSRAMCODEStartAddress;

   /* specify the total size */
   MPUsetting.m_range = INTSRAMCODERange;

   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;

   /* get a MPU cahnnel */
   retval = MPUGetChannel(&MPUsetting.m_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the MPU */
   MPUSetting(&MPUsetting);
}
#endif   /* MT6228 || MT6229 || MT6230 || MT6225 */

/*************************************************************************
* FUNCTION
*  SetupMPUCacheByFeature
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
static void
SetupMPUCacheByFeature(void)
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   MPUMenuType    MPUsetting;
   CacheMenuType  CACHEsetting;
   kal_bool retval;

   /*
    * Configure RAM code for single bank support as READABLE_BUT_NON_WRITEABLE.
    */

   /* specify the start address */
   MPUsetting.m_addr = RAMCODEStartAddress;

   /* specify the total size */
   MPUsetting.m_range = RAMCODEEndAddress - RAMCODEStartAddress;

   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;

   /* get a MPU cahnnel */
   retval = MPUGetChannel(&MPUsetting.m_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the MPU */
   MPUSetting(&MPUsetting);

   /*
    * SINGLE_BANK_CODE Code Cache configuration.
    */
   /* specify the start address of CACHE setting */
   CACHEsetting.c_addr = RAMCODEStartAddress;

   /* specify the range of CACHE setting */
   CACHEsetting.c_range = RAMCODEEndAddress - RAMCODEStartAddress;

   /* get a CACHE cahnnel */
   retval = CodeCacheGetChannel(&CACHEsetting.c_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the CACHE */
   CodeCacheSetting(&CACHEsetting);

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

}
#endif   /* MT6228 || MT6229 || MT6230 || MT6225 */


#if defined(__ARM9_MMU__)

/*************************************************************************
* FUNCTION
*  alloc_ptbl
*
* DESCRIPTION
*  This function allocates memory for page table.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  size   -   page table size
*
* RETURNS
*  memory address for the page table
*
*************************************************************************/
kal_uint32 alloc_ptbl(kal_uint32 size)
{
   kal_uint32 addr;


   addr = 0;

   if (size == CPT_SIZE) {
      if ((cpt_pool_indx + size) > cpt_pool_size) {
         /* out-of-memory */
         //EXT_ASSERT(0, size, cpt_pool_indx, cpt_pool_size);
         cpt_pool_indx += size;
         addr = NULL;
      } else {
         addr = (kal_uint32)((kal_uint8 *)cpt_pool + cpt_pool_indx);
         cpt_pool_indx += size;
      }
   } else if (size == FPT_SIZE) {
      if ((fpt_pool_indx + size) > fpt_pool_size) {
         /* out-of-memory */
         //EXT_ASSERT(0, size, fpt_pool_indx, fpt_pool_size);
         fpt_pool_indx += size;
         addr = NULL;
      } else {
         addr = (kal_uint32)((kal_uint8 *)fpt_pool + fpt_pool_indx);
         fpt_pool_indx += size;
      }
   } else {
      EXT_ASSERT(0, size, 0, 0);
   }

   return addr;
}


/*************************************************************************
* FUNCTION
*  check_cptbl_pool
*
* DESCRIPTION
*  This function checks if the coarse page table pool is exhausted.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  none
*
* RETURNS
*  
*
*************************************************************************/
kal_uint32 check_cptbl_pool()
{
   if (cpt_pool_indx > cpt_pool_size) {
      return cpt_pool_indx - cpt_pool_size;
   } else {
      return 0;
   }
}


/*************************************************************************
* FUNCTION
*  check_fptbl_pool
*
* DESCRIPTION
*  This function checks if the fine page table pool is exhausted.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  none
*
* RETURNS
*  
*
*************************************************************************/
kal_uint32 check_fptbl_pool()
{
   if (fpt_pool_indx > fpt_pool_size) {
      return fpt_pool_indx - fpt_pool_size;
   } else {
      return 0;
   }
}


/*************************************************************************
* FUNCTION
*  mk_pte
*
* DESCRIPTION
*  This function makes a page table entry according to specification.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  page_tbl   -   page table
*  addr       -   virtual address for the entry
*  size       -   page size
*  ap         -   access permission
*  c          -   cacheable
*  b          -   bufferable
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 mk_pte(kal_uint32 *page_tbl, kal_uint32 addr, kal_uint32 size, kal_uint32 ap, kal_uint32 c, kal_uint32 b)
{
   kal_uint32 tbl, *tbl_ptr, indx;
   kal_int32 i;


   tbl = 0;
   tbl_ptr = NULL;
   indx = 0;
   i = 0;

   switch (size) {
      case PAGE_SIZE_1KB:
         if (!is_fptd(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one find page and one page table entry */
            tbl = alloc_ptbl(FPT_SIZE);
            if (tbl == NULL) {
               return -1;
            }
            mk_fpt(tbl, addr);
            page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] = mk_fptd(tbl, DOMAIN00);
         }

         tbl_ptr = (kal_uint32 *)(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] & FPT_BASE_MASK);
         tbl_ptr[(addr & 0x000ffc00) >> PAGE_SIZE_1KB_SHIFT] = mk_tpd(addr, ap, c, b);

         break;

      case PAGE_SIZE_4KB:
         if (!is_cptd(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one coarse page and one page table entry */
            tbl = alloc_ptbl(CPT_SIZE);
            if (tbl == NULL) {
               return -1;
            }
            mk_cpt(tbl, addr);
            page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] = mk_cptd(tbl, DOMAIN00);
         }

         tbl_ptr = (kal_uint32 *)(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] & CPT_BASE_MASK); 
         tbl_ptr[(addr & 0x000ff000) >> PAGE_SIZE_4KB_SHIFT] = mk_spd(addr, ap, c, b);

         break;

      case PAGE_SIZE_64KB:
         if (!is_cptd(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one coarse page and one page table entry */
            tbl = alloc_ptbl(CPT_SIZE);
            if (tbl == NULL) {
               return -1;
            }
            mk_cpt(tbl, addr);
            page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] = mk_cptd(tbl, DOMAIN00);
         }

         tbl_ptr = (kal_uint32 *)(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] & CPT_BASE_MASK); 

         indx = (addr & 0x000ff000) >> PAGE_SIZE_4KB_SHIFT;
         for (i = 16; i != 0; i--) {
            tbl_ptr[indx + i - 1] = mk_lpd(addr, ap, c, b);
         }

         break;

      case PAGE_SIZE_1MB:
         page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] = mk_sd(addr, ap, DOMAIN00, c, b);

         break;

      default:
         ASSERT(0);
         break;
   }

   return 0;
}


/*************************************************************************
* FUNCTION
*  mk_pt
*
* DESCRIPTION
*  This function makes page table for the specified region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   start address of the region
*  lenght   -   length of the region (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 mk_pt(kal_uint32 addr, kal_uint32 len, kal_uint32 ap, kal_uint32 c, kal_uint32 b)
{
   kal_uint32 s;


   while (len > 0) {
      /* try to find a best-fit page size */
      if (len >= PAGE_SIZE_1MB && (addr & PAGE_SIZE_1MB_MASK) == 0) {
         s = PAGE_SIZE_1MB;
      } else if ((len + (addr & PAGE_SIZE_1MB_MASK)) & ~PAGE_SIZE_1MB_MASK) {
         if ((addr & PAGE_SIZE_64KB_MASK) == 0) {
            s = PAGE_SIZE_64KB;
         } else if ((addr & PAGE_SIZE_4KB_MASK) == 0) {
            s = PAGE_SIZE_4KB;
         } else {
            s = PAGE_SIZE_1KB;
         }
      } else if (len >= PAGE_SIZE_64KB && (len & PAGE_SIZE_4KB_MASK) == 0 && (addr & PAGE_SIZE_4KB_MASK) == 0) {
         s = PAGE_SIZE_64KB;
      } else if ((len & PAGE_SIZE_4KB_MASK) == 0 && (addr & PAGE_SIZE_4KB_MASK) == 0) {
         s = PAGE_SIZE_4KB;
      } else {
         s = PAGE_SIZE_1KB;
      }
      
      /* make a page table entry */
      if (mk_pte(page_tbl, addr, s, ap, c, b) == -1) {
         return -1;
      }

      /* cotinue to process */
      addr += s;
      if (s >= len) {
         len = 0;
      } else {
         len = ((len / s) - 1) * s + (len % s);
      }
   }

   return 0;
}

#endif  /* __ARM9_MMU__ */


/*************************************************************************
* FUNCTION
*  CacheInit
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void CacheInit(void)
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
   /*
    * MPU configuration.
    * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE.
    */
   SetupMPUbyROMSegment(   ROMStartAddress,
                           ROMEndAddress,
                           ROMLength);
   
   /*
    * Configure code and RO in the TCM as READABLE_BUT_NON_WRITEABLE.
    */
   SetupMPUonTCM();

   /*
    * Cache configuration.
    * Configure the region of code and RO as code-cacheable.
    */
   SetupCACHEbyROMSegment( ROMStartAddress,
                           ROMEndAddress,
                           ROMLength);

   SetupMPUCacheByFeature();

#endif   /* MT6228 || MT6229 || MT6230 || MT6225 */

#if defined(MT6228) || defined(MT6229) || defined(MT6230)
   /* enable code cache */
   CodeCacheConfig(CACHE_4WAY, KAL_TRUE);
   /* enable data cache */
   DataCacheConfig(KAL_TRUE, KAL_FALSE);

#elif defined(MT6225)

   /* enable code cache */
   CodeCacheConfig(CACHE_2WAY, KAL_TRUE);

#endif  /* MT6228 || MT6229 || MT6230 */

#if defined(MT6238)

   EXTSRAM_REGION_INFO_T *regionp;
   kal_uint32 ret, ram_addr, ram_len, *ram_info, cnt;



   /*
    * Create a page table.
    */

   /* make the EXTSRAM info table */
   custom_mk_ram_info();

   /* get fpt pool */
   custom_query_fpt_pool(&fpt_pool, &fpt_pool_size);

   /* get cpt pool */
   custom_query_cpt_pool(&cpt_pool, &cpt_pool_size);

   /* make the default page table */
   mk_def_pt(page_tbl);

   ret = 0;
   do {
      /* configure ROM as READ_ONLY and cached region */
      ret = mk_pt(ROMStartAddress, ROMLength, PRIV_READ_ONLY, PAGE_CACHEABLE, PAGE_BUFFERABLE);
      if (ret == -1) {
         break;
      }

      /* configure cached RAM as READ_WRITE and cached region */
      custom_query_cached_extsram_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         ret = mk_pt(regionp->addr, regionp->len, PRIV_READ_WRITE, PAGE_CACHEABLE, PAGE_BUFFERABLE);
         regionp++;
      }
      if (ret == -1) {
         break;
      }

      /* configure non-cached RAM as READ_WRITE and non-cached region */
#if defined(_MAUI_SOFTWARE_LA_)
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
#else   /* _MAUI_SOFTWARE_LA_ */
      custom_query_noncached_extsram_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         ret = mk_pt(regionp->addr, regionp->len, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
         regionp++;
      }
      if (ret == -1) {
         break;
      }
#endif  /* _MAUI_SOFTWARE_LA_ */

      INT_GetSysMemoryInfo(&ram_info, (kal_uint16 *)&cnt);
      /* configure ITCM as READ_ONLY and non-cached region */
      ret = mk_pt(ram_info[0], ram_info[1], PRIV_READ_ONLY, PAGE_NO_CACHE, PAGE_NO_CACHE);
      if (ret == -1) {
         break;
      }
      /* configure DTCM as READ_WRITE and non-cached region */
      ret = mk_pt(ram_info[2], ram_info[3], PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
      if (ret == -1) {
         break;
      }
   } while (0);

   if (ret == -1) {
      /* remake page table due to failure */

      /* configure ROM as READ_ONLY and cached region */
      mk_pt(ROMStartAddress, FATStartAddress - ROMStartAddress, PRIV_READ_ONLY, PAGE_CACHEABLE, PAGE_BUFFERABLE);

      /* configure RAM as READ_WRITE and non-cached region */
      custom_get_EXTSRAM_size(&ram_len);
      mk_pt(RAMStartAddress, ram_len, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

      INT_GetSysMemoryInfo(&ram_info, (kal_uint16 *)&cnt);
      /* configure ITCM DTCM as READ_WRITE and non-cached region */
      ret = mk_pt(ram_info[0], 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   }

   /* configure FAT as READ_WRITE and non-cached region */
   mk_pt(FATStartAddress, FATLength, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure system RAM as READ_WRITE and non-cached region */
   /* don't need to care the exact size because system RAM is for multimedia function only */
   INT_QuerySystemRAMInfo(&ram_addr, &ram_len);
   ret = mk_pt(ram_addr, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure BB registers as READ_WRITE and cached region */
   mk_pt(BBRegStartAddress, BBRegLength, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure LCD registers as READ_WRITE and cached region */
   mk_pt(LCD_base, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure VFIFO as READ_WRITE and non-cached region */
   mk_pt(DMA_VPORT_BASE, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure USB registers as READ_WRITE and non-cached region */
   //mk_pt(USB_base, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0x60000000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);

   /* configure DSP sherif as READ_WRITE and non-cached region */
   mk_pt(DPRAM_CPU_base, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(DPRAM2_CPU_base, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA2000000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA2100000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA2200000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA2300000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA3000000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA3100000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA3200000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);
   mk_pt(0xA3300000, 0x100000, PRIV_READ_WRITE, PAGE_NO_CACHE, PAGE_NO_CACHE);


   /*
    * Enable ICache, DCache, and MMU.
    */

#if !defined(_NAND_FLASH_BOOTING_)

   /* set translation table base */
   cp15_write_tbbr((kal_uint32)page_tbl);

   /* set domain 0 access control */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

   /* enable ROM protect */
   cp15_enable_rom_protect();

   /* enable alignment fault */
   cp15_enable_alignment_fault();

   /* enable MMU */
   cp15_enable_mmu();

#endif   /* !_NAND_FLASH_BOOTING_ */

   /* enable ICache */
   cp15_enable_icache();

#if !defined(_NAND_FLASH_BOOTING_)

   /* enable DCache */
   cp15_enable_dcache();

#endif  /* !_NAND_FLASH_BOOTING_ */

   /* enable L2 data cache */
   DataCacheConfig(KAL_TRUE, KAL_FALSE);

#endif  /* MT6238 */
}


#ifdef _NAND_FLASH_BOOTING_

/*************************************************************************
* FUNCTION
*  CacheInitBalancedMAUI
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void CacheInitSecondaryMAUI(void)
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)
   /*
    * MPU configuration.
    * Configure the SECONDARY_ROM region as READABLE_BUT_NON_WRITEABLE.
    */

   SetupMPUbyROMSegment(   FATTYROMStartAddress,
                           FATTYROMEndAddress,
                           custom_get_2nd_ROM_Length());
   
   /*
    * Cache configuration.
    * Configure the SECONDARY_ROM region as code-cacheable.
    */

   SetupCACHEbyROMSegment( FATTYROMStartAddress,
                           FATTYROMEndAddress,
                           custom_get_2nd_ROM_Length());
#endif  /* MT6228 || MT6229 || MT6230 || MT6225 */

#if defined(MT6238)

   /* configure 2nd ROM as READ_ONLY and cached regions */
//   mk_pt(FATTYROMStartAddress, custom_get_2nd_ROM_Length(), PRIV_READ_ONLY, PAGE_CACHEABLE, PAGE_BUFFERABLE);

   /* configure 2nd RAM as READ_WRITE and cached regions */
//   mk_pt(FATTYRAMStartAddress, FATTYRAMLength, PRIV_READ_WRITE, PAGE_CACHEABLE, PAGE_BUFFERABLE);

   /* set translation table base */
   cp15_write_tbbr((kal_uint32)page_tbl);

   /* set domain 0 access control */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

   /* enable ROM protect */
   cp15_enable_rom_protect();

   /* enable alignment fault */
   cp15_enable_alignment_fault();

   /* enable MMU */
   cp15_enable_mmu();

   /* enable DCache */
   cp15_enable_dcache();

#endif  /* MT6238 */
}

#endif /* _NAND_FLASH_BOOTING_ */

#endif /* __MTK_TARGET__ */

