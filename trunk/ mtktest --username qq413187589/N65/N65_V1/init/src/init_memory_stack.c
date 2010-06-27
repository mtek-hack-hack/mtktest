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
 *   init_memory_stack.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the stack distribution, will be referenced in bootarm.s
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

#include <stdarg.h>
#include "kal_release.h"
#include "stack_main.h"
#include "init.h"

#ifdef __MTK_TARGET__

#ifdef _NAND_FLASH_BOOTING_

#if ( defined(MT6229) || defined(MT6230) || defined(MT6238))
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$ZI$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$ZI$$Length;
#endif /* MT6229 || MT6230 */

/* for INT_QueryBiggestPool */
extern kal_uint32 Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit;

/* for INT_GetSysMemoryInfo */
extern kal_uint32 Image$$PRIMARY_EXTSRAM$$Base;
extern kal_uint32 Image$$SECONDARY_ROM$$Base;

#else /* _NAND_FLASH_BOOTING */

/* for INT_QueryBiggestPool */
#if ( !defined(MT6205B) && !defined(MT6208) )
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit;
#endif /* !MT6205B and !MT6208 */

#if defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P) || defined(MT6238)
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$ZI$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$ZI$$Length;
#endif   /* MT6229 || MT6230 || MT6223 || MT6223P */

#endif /* _NAND_FLASH_BOOTING */

extern kal_uint32 Image$$ROM$$Base;
extern kal_uint32 Image$$EXTSRAM$$Base;

extern kal_uint32 SYS_Stack_Pool[];
extern kal_uint32 BOOT_SYS_Stack_End;

extern void custom_get_EXTSRAM_size(kal_uint32 *);
extern void custom_get_MaxAvailableMemorySegment(kal_uint32 **start_ptr, kal_uint32 *available_length);

extern kal_char _stack_pattern_ptr[];
extern kal_uint32 INT_SwitchStackAndBranch(void *new_stack, kal_func_ptr func, kal_uint32 argc, va_list argv);
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32 irq);
extern int INT_GetCurrentSP(void);

switch_stack_info_struct switch_stack_info_g[SWITCH_STACK_INFO_NUM];
kal_uint32 switch_stack_info_cnt_g = 0;

switch_stack_history_struct switch_stack_history_g[SWITCH_STACK_HISTORY_NUM];
kal_uint32 switch_stack_history_cur_g = 0;


/*************************************************************************
* FUNCTION
*  INT_QueryBiggestPool
*
* DESCRIPTION
*  Query the biggest Pool, available for META mode only!
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool INT_QueryBiggestPool(kal_uint32 *availableSize, void **ptr)
{
#if defined (IC_BURNIN_TEST)

   *availableSize = 0;
   *ptr = 0;

   return KAL_TRUE;

#elif defined(MT6205B) || defined(MT6208)   /* IC_BURNIN_TEST */

   return KAL_FALSE;

#else   /* IC_BURNIN_TEST */

   boot_mode_type mode;
   kal_uint32  *start_ptr;
   kal_uint32  available_length;
      
   mode = stack_query_boot_mode();
   
   ASSERT(mode==FACTORY_BOOT);
 
   custom_get_MaxAvailableMemorySegment(&start_ptr, &available_length);
   
#ifdef _NAND_FLASH_BOOTING_

   *availableSize = ((kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit) -
                     (kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
   *ptr = &Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;

#else

   *availableSize = ((kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit) - 
                     (kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
   *ptr = &Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
   
#endif   

   if ( *availableSize < available_length )
   {
       *availableSize = available_length;
      *ptr = start_ptr;     
   }
   
   return KAL_TRUE;
   
#endif /* IC_BURNIN_TEST */
}


/*************************************************************************
* FUNCTION
*  INT_GetSystemStackStartEndAddress
*
* DESCRIPTION
*  Retrieve start address and end address of the system stack
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void INT_GetSystemStackStartEndAddress(kal_uint32 *start, kal_uint32 *end)
{
   *start = (kal_uint32)SYS_Stack_Pool;
   *end   = BOOT_SYS_Stack_End;
}


/*************************************************************************
* FUNCTION
*  INT_RetrieveFlashBaseAddr
*
* DESCRIPTION
*   This function returns flash base address to caller.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 INT_RetrieveFlashBaseAddr(void)
{
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) )

#ifndef _NAND_FLASH_BOOTING_

   return ( ((kal_uint32)(&Image$$ROM$$Base) & 0xf8000000) | 0x04000000 );
   
#endif

#endif
#if defined(MT6238)

#ifndef _NAND_FLASH_BOOTING_

   return ((kal_uint32)(&Image$$ROM$$Base) & 0xf0000000) | 0x08000000;

#else   /* !_NAND_FLASH_BOOTING_ */
   
   return (kal_uint32)(&Image$$ROM$$Base) & 0xf0000000;

#endif   /* !_NAND_FLASH_BOOTING_ */

#endif   /* MT6238 */


   return (kal_uint32)((kal_uint32)(&Image$$ROM$$Base) & 0xf8000000) ;
}

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/*************************************************************************
* FUNCTION
*  INT_LocateInNORFlash
*
* DESCRIPTION
*   This function returns whether the passed address is within flash bank.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
kal_bool INT_LocateInNORFlash(kal_uint32 addr)
{
   kal_uint32 base = (kal_uint32)&Image$$ROM$$Base;
   kal_uint32 end = base + custom_get_NORFLASH_ROMSpace();

   if( ((addr >= base) && (addr < end))
   #if defined(MT6225)
       || ((addr >= (base|0x04000000)) && (addr < (end|0x04000000)))
   #endif
   )
      return KAL_TRUE;
   else
      return KAL_FALSE;

}

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*************************************************************************
* FUNCTION
*  INT_RetrieveDSPTXRXBaseAddr
*
* DESCRIPTION
*   This function returns flash base address to caller.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool INT_RetrieveDSPTXRXBaseAddr(kal_uint32 *TX_Base, kal_uint32 *RX_Base,
                                     kal_uint32 *CS,
                                     kal_uint32 *TX_Size, kal_uint32 *RX_Size)
{
#if defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P) || defined(MT6238)

   kal_uint32     chipSelect;
   kal_uint32     region_sz;

#if defined(IC_BURNIN_TEST)

   *TX_Base = 0;
   *RX_Base = 0;
   return KAL_TRUE;

#elif defined(_NAND_FLASH_BOOTING_)   /* IC_BURNIN_TEST */

   *TX_Base = (kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_TX$$Base;
   *RX_Base = (kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_RX$$Base;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_TX$$Length
                      +(kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_TX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_RX$$Length
                      +(kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_RX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *RX_Size = region_sz;
#if defined(MT6238)
   chipSelect = (*TX_Base&0xF0000000) >> 27;
#else
   
   chipSelect = (*TX_Base&0xF8000000) >> 27;
#endif	// #if defined(MT6238)
   
#if defined(MT6238)
   ASSERT(chipSelect<=2);
#else
   ASSERT(chipSelect<2);
#endif
   
   *CS = chipSelect;

   return KAL_TRUE;
   
#else   /* IC_BURNIN_TEST */

   *TX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
   *RX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;
   
   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_TX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_TX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_RX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_RX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *RX_Size = region_sz;
#if defined(MT6238)
   chipSelect = (*TX_Base&0xF0000000) >> 27;
#else   
   chipSelect = (*TX_Base&0xF8000000) >> 27;
#endif	// #if defined(MT6238)
   
#if defined(MT6238)
   ASSERT(chipSelect<=2);
#else
   ASSERT(chipSelect<2);
#endif

   
   *CS = chipSelect;

   return KAL_TRUE;

#endif /* IC_BURNIN_TEST */   

#else   /* MT6229 || MT6230 */

   return KAL_FALSE;

#endif   /* MT6229 || MT6230 || MT6223 || defined(MT6223P) */
}


/*************************************************************************
* FUNCTION
*  INT_QueryMemoryInfo
*
* DESCRIPTION
*  Queue memory information, including start address, end address and length.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void INT_QueryMemoryInfo(kal_uint32 *ext_start, kal_uint32 *ext_len, kal_uint32 *int_start, kal_uint32 *int_len)
{
   custom_get_EXTSRAM_size(ext_len);
   
#ifdef MT6205B

   *int_len = 32*1024;
   *ext_start = 0x10000000;
   *int_start = 0x40000000;
   return;
   
#else /* MT6205B */

#ifdef _NAND_FLASH_BOOTING_
   *ext_start = (kal_uint32)&Image$$ROM$$Base;
#else
   *ext_start = ((kal_uint32)&Image$$ROM$$Base) ^ 0x08000000;
#endif   
      
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) )
   *int_start = 0xa0000000;
#elif defined(MT6238)
   *int_start = 0x50000000;

#else      
   *int_start = 0x40000000;
#endif   
      
#if defined(MT6226) || defined(MT6227) || defined(MT6226M)|| defined(MT6227D) || defined(MT6226D)
   *int_len = (128+156)*1024;
#elif defined(MT6219)   /* MT6226 || MT6227 || MT6226M || defined(MT6227D) || defined(MT6226D)*/
   *int_len = 512*1024;
#elif defined(MT6218B)  /* MT6226 || MT6227 || MT6226M || defined(MT6227D) || defined(MT6226D)*/
   *int_len = 256*1024;
#elif defined(MT6225)   /* MT6226 || MT6227 || MT6226M || defined(MT6227D) || defined(MT6226D)*/
   *int_len = 72*1024;
#elif defined(MT6223) || defined(MT6223P)   /* MT6226 || MT6227 || MT6226M */
   *int_len = 40*1024;   
#elif defined(MT6238)
   *int_len = (46 + 72) * 1024;
#else /* MT6226 || MT6227 || MT6226M */
   *int_len = 128*1024;   
#endif   /* MT6226 || MT6227 || MT6226M || defined(MT6227D) || defined(MT6226D)*/

   return;
   
#endif /* MT6205B */
}

/*************************************************************************
* FUNCTION
*  INT_GetSysMemoryInfo
*
* DESCRIPTION
*  This API is design for TST/TR/Catcher to do exception handling.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
static kal_uint32 SysMemoryInfo[] = /* address ,  length , address , length , ... */
{     
   /* Internal RAM (address) { */
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) )
   0xa0000000,
#elif defined(MT6238)
   0x50000000,
#else
   0x40000000,
#endif
   /* Internal RAM (address) } */

   /* Internal RAM (length) { */
#if defined(MT6205B)
    32 * 1024,
#elif defined(MT6223) || defined(MT6223P)
    40 * 1024,
#elif defined(MT6225)
    72 * 1024,
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6217)
   128 * 1024,
#elif defined(MT6208)
   192 * 1024,
#elif defined(MT6218B)
   256 * 1024,
#elif defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
   (128+156) * 1024,
#elif defined(MT6219)
   512 * 1024,
#elif defined(MT6238)
   32 * 1024,   /* ITCM */
#else

#error internal RAM length should be determined for new chipset

#endif
   /* Internal RAM (length in word unit) } */
#if defined(MT6238)
   0x50020000, 80 * 1024,   /* DTCM */
#endif  /* MT6238 */
     
   /* External RAM (#1, value determined run-time) */
   0, 0,

   /* External RAM (#2, value determined run-time, NFB only) */
#ifdef _NAND_FLASH_BOOTING_
   0, 0,
#endif
};

void INT_GetSysMemoryInfo( kal_uint32 **info, kal_uint16* count )
{
#ifdef _NAND_FLASH_BOOTING_
   SysMemoryInfo[2] = (kal_uint32)&Image$$PRIMARY_EXTSRAM$$Base;
   SysMemoryInfo[3] = (kal_uint32)&Image$$SECONDARY_ROM$$Base - SysMemoryInfo[2];

   SysMemoryInfo[4] = (kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
   custom_get_EXTSRAM_size(&(SysMemoryInfo[5]));
   SysMemoryInfo[5] -= SysMemoryInfo[4];
#else /* _NAND_FLASH_BOOTING_ */

#if !defined(MT6238)
   SysMemoryInfo[2] = ((kal_uint32)&Image$$EXTSRAM$$Base) & 0xF8000000;
   custom_get_EXTSRAM_size(&(SysMemoryInfo[3]));
#endif

#endif /* _NAND_FLASH_BOOTING_ */

   *info  = (kal_uint32*)SysMemoryInfo;
   *count = sizeof(SysMemoryInfo)/sizeof(kal_uint32)/2;
}

/*************************************************************************
* FUNCTION
*  INT_SwitchStackToRun
*
* DESCRIPTION
*  Switch current stack pointer to new_stack and then run func(...).
*
* CALLS
*      INT_SwitchStackAndBranch
*
* PARAMETERS
*      stack_start    the start address of the new stack (NOT a pointer of start address)
*      stack_size     the size of the stack
*      func           the pointer of function which want to run
*      argc           the number of arguments of func
*      ...            the arguments of func
*
* RETURNS
*      The reture value of func
*
*************************************************************************/
kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...)
{
   #define NO_AVAILABLE 0xffff
   
   kal_uint32 i, available = NO_AVAILABLE;
   kal_taskid task_self_id = kal_get_task_self_id();
   kal_uint32 irq;
   kal_uint32 *stack_ptr;
   kal_uint32 ret;
   va_list    argv;

   /*********** Step 1: Align The Stack **************************************/

   /* check whether the stack start address is 8-byte alignment or not */
   if ((kal_uint32)stack_start & 7) {
      /* we need to adjust the stack size since we will adjust the stack start address */
      stack_size -= (8 - (kal_uint32)stack_start & 7);

      /* insure that the stack start address is 8-byte alignment */
      stack_start = (void *)(((kal_uint32)stack_start & 0xfffffff8) + 8);
   }

   /* insure that the stack size is multiple of 8 bytes */
   stack_size &= ~7;


   /*********** Step 2: Guarantee Not Overlap ********************************/

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* check the stack not overlap with previous stacks */
   for (i = 0; i < switch_stack_info_cnt_g; i++)
   {
      if (switch_stack_info_g[i].stack_start)
      {
      	
         if ((kal_uint32)stack_start < (kal_uint32)switch_stack_info_g[i].stack_end
            && (kal_uint32)stack_start + stack_size > (kal_uint32)switch_stack_info_g[i].stack_start)
         {
            #define SWITCH_STACK_OVERLAP 0
            EXT_ASSERT(SWITCH_STACK_OVERLAP,
                       (kal_uint32)stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_end);
         }
      }
      else if (available == NO_AVAILABLE)
      {
      	 /* mark it an available slot */
         available = i;
      }
   }
   
   /* if no available slot, increase the count of slots */
   if (available == NO_AVAILABLE)
   {
      if (switch_stack_info_cnt_g < SWITCH_STACK_INFO_NUM)
      {
         available = switch_stack_info_cnt_g;
         switch_stack_info_cnt_g++;
      }
      else
      {
         #define SWITCH_STACK_NO_MORE_SLOT 0
         EXT_ASSERT(SWITCH_STACK_NO_MORE_SLOT,
                    (kal_uint32)switch_stack_info_cnt_g, 0, 0);
      }
   }

   /* fill the info of the stack */
   switch_stack_info_g[available].stack_start = stack_start;
   switch_stack_info_g[available].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);

   switch_stack_history_g[switch_stack_history_cur_g].state       = STACK_ALLOCATED;
   switch_stack_history_g[switch_stack_history_cur_g].stack_start = stack_start;
   switch_stack_history_g[switch_stack_history_cur_g].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);
   switch_stack_history_g[switch_stack_history_cur_g].old_sp      = (void *)INT_GetCurrentSP();
   switch_stack_history_g[switch_stack_history_cur_g].task_id     = task_self_id;

   switch_stack_history_cur_g++;
   if (switch_stack_history_cur_g == SWITCH_STACK_HISTORY_NUM)
      switch_stack_history_cur_g = 0;

   RestoreIRQMask(irq);       /* end of critical section */


   /*********** Step 3: Fill Guard Pattern ***********************************/

   /* fill the guard pattern in the start of the stack */
   stack_ptr = (kal_uint32*)stack_start;
   *stack_ptr = *((kal_uint32*)_stack_pattern_ptr);
   *(stack_ptr+1) = *((kal_uint32*)&_stack_pattern_ptr[4]);
   
   /* fill the guard pattern in the end of the stack */
   stack_ptr = (kal_uint32*)stack_start+(stack_size>>2)-2;
   *stack_ptr = *((kal_uint32*)_stack_pattern_ptr);
   *(stack_ptr+1) = *((kal_uint32*)&_stack_pattern_ptr[4]);


   /*********** Step 4: Call Assembly Function *******************************/

   /* call the assembly function to switch stack and branch func(...) */   
   va_start(argv, argc);
   ret = INT_SwitchStackAndBranch(stack_ptr, func, argc, argv);
   va_end(argv);


   /*********** Step 5: Check Guard Pattern **********************************/

   /* check the guard pattern of the start */
   stack_ptr = (kal_uint32*)stack_start;
   if ( (*stack_ptr != *((kal_uint32*)_stack_pattern_ptr)) || 
        (*(stack_ptr+1) != *((kal_uint32*)&_stack_pattern_ptr[4])) ) {
            #define SWITCH_STACK_CORRUPTED 0
            EXT_ASSERT(SWITCH_STACK_CORRUPTED,
                       (kal_uint32)stack_ptr,
                       (kal_uint32)stack_start,
                       (kal_uint32)stack_size);
        }

   /* check the guard pattern of the end */
   stack_ptr = (kal_uint32*)(kal_uint32*)stack_start+(stack_size>>2)-2;
   if ( (*stack_ptr != *((kal_uint32*)_stack_pattern_ptr)) || 
        (*(stack_ptr+1) != *((kal_uint32*)&_stack_pattern_ptr[4])) ) {
            #define SWITCH_STACK_OVERFLOW 0
            EXT_ASSERT(SWITCH_STACK_OVERFLOW,
                       (kal_uint32)stack_ptr,
                       (kal_uint32)stack_start,
                       (kal_uint32)stack_size);
        }

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* clear the stack info */
   switch_stack_info_g[available].stack_start = 0;
   while (switch_stack_info_cnt_g && !(switch_stack_info_g[switch_stack_info_cnt_g-1].stack_start))
      switch_stack_info_cnt_g--;

   i = switch_stack_history_cur_g;
   do
   {
      if (i == 0)
         i = SWITCH_STACK_HISTORY_NUM - 1;
      else
         i--;

      if (switch_stack_history_g[i].stack_start == stack_start
          && switch_stack_history_g[i].state == STACK_ALLOCATED)
      {
         switch_stack_history_g[i].state = STACK_FREED;
         break;
      }
   } while (i != switch_stack_history_cur_g);

   RestoreIRQMask(irq);       /* end of critical section */


   /* return the return value of func(...) */
   return ret;
}

/*************************************************************************
* FUNCTION
*  INT_QuerySystemRAMInfo
*
* DESCRIPTION
*  This function gets the start address and lenght of system RAM.
*
* CALLS
*
* PARAMETERS
*  addr   -   pointer to store start address of system RAM
*  len    -   pointer to sttore length of system RAM
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 INT_QuerySystemRAMInfo(kal_uint32 *addr, kal_uint32 *len)
{
#if defined(MT6228)
   *addr = 0x40000000;
   *len = 128 * 1024;
   return 0;
#elif defined(MT6229)
   *addr = 0x40000000;
   *len = 128 * 1024;
   return 0;
#elif defined(MT6225)
   *addr = 0x40000000;
   *len = 48 * 1024;
   return 0;
#elif defined(MT6238)
   *addr = 0x40000000;
   *len = 96 * 1024;
   return 0;
#else
   *addr = 0xFFFFFFFF;
   *len = 0;
   return -1;
#endif  /* MT6235 */
}

/*************************************************************************
* FUNCTION
*  INT_QueryIsNonCachedRAM
*
* DESCRIPTION
*  This function checks if the specified buffer in the non-cached RAM.
*
* CALLS
*
* PARAMETERS
*  addr   -   buffer start address
*  len    -   buffer length
*
* RETURNS
*  1 for in non-cached RAM; 0 for in cached RAM
*
*************************************************************************/
kal_int32 INT_QueryIsNonCachedRAM(kal_uint32 addr, kal_uint32 len)
{
#if defined(MT6238)

   EXTSRAM_REGION_INFO_T *regionp;
   kal_int32 ret;


   ret = custom_query_noncached_extsram_region(&regionp);

   if (ret == -1) {
      return 1;
   }

   while (regionp->addr != 0 || regionp->len != 0) {
      if (addr >= regionp->addr && (addr + len) <= (regionp->addr + regionp->len)) {
         return 1;
      }
      regionp++;
   }

   return 0;

#else   /* MT6238 */

   return 1;

#endif  /* MT6238 */
}

/*************************************************************************
* FUNCTION
*  INT_QueryIsCachedRAM
*
* DESCRIPTION
*  This function checks if the specified buffer in the cached RAM.
*
* CALLS
*
* PARAMETERS
*  addr   -   buffer start address
*  len    -   buffer length
*
* RETURNS
*  1 for in cached RAM; 0 for in non-cached RAM
*
*************************************************************************/
kal_int32 INT_QueryIsCachedRAM(kal_uint32 addr, kal_uint32 len)
{
#if defined(MT6238)

   EXTSRAM_REGION_INFO_T *regionp;
   kal_int32 ret;


   ret = custom_query_cached_extsram_region(&regionp);

   if (ret == -1) {
      return 0;
   }

   while (regionp->addr != 0 || regionp->len != 0) {
      if (addr >= regionp->addr && (addr + len) <= (regionp->addr + regionp->len)) {
         return 1;
      }
      regionp++;
   }

   return 0;

#else   /* MT6238 */

   return 0;

#endif  /* MT6238 */
}

#endif  /* __MTK_TARGET__ */

