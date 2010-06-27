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
 *   custom_EMI.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *   EMI auto generator V4.17
 *
 *   Memory Device database last modified on 2009/11/16
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__
#include "flash_opt.h"

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
   NOR_FLASH,
   RAM,
   UNUSED,
   UNUSED

};


/*
 ****************************************************************************
 Specify RAM size in Bytes
 ****************************************************************************
*/
const kal_uint32  EMI_EXTSRAM_SIZE = ((32)<<20)>> 3;

/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
#if ( defined(MT6205B) || defined(MT6208) )
#define EMI_GENERAL_CONTROL          0x0100

#elif defined(MT6228)
#define EMI_GENERAL_CONTROL_0        x

#elif defined(MT6225)
#define EMI_GENERAL_CONTROL_0        0x40008000
#define EMI_GENERAL_CONTROL_1        0x739c739c

#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
#define EMI_GENERAL_CONTROL_0        x

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
#define EMI_GENERAL_CONTROL          0xeeee0780
#define EMI_CACHE_PREFETCH           0x03030107

#elif ( defined(MT6223)  || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )
#define EMI_GENERAL_CONTROL          0xeeeefb80
#define EMI_CACHE_PREFETCH           0x03030107

#else /* defined(MT6227) || defined(MT6226) || defined(MT6226M) */
#define EMI_GENERAL_CONTROL          0xeeeefb80
#define EMI_CACHE_PREFETCH           0x03030107

#endif

/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/
#if ( defined(MT6205B) || defined(MT6208) )

const kal_uint16   EMI_SettingOnCS[4] =
{
   0x4102,
   0x4102,
   0,
   0
};

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0x44054324,
   0x44064304,
   0,
   0
};

#elif ( defined(MT6227) || defined(MT6226) || defined(MT6226M) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0x44054324,
   0x44064304,
   0,
   0
};

#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0x40514648,
   0x40514808,
   0,
   0
};

#elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0x44c94324,
   0x44c94404,
   0,
   0
};

#endif


/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/

/*
 *******************************************************************************
   Follow the steps below to configure flash memory for FAT

   Note : All sectors allocated for FAT MUST be continuous sectors.

 *******************************************************************************
*/

/*******************************************************************************
   Step 1. Modify the value of FLASH_BASE_ADDRESS, which is the starting address
           of the flash memory allocated for FAT
 *******************************************************************************/
#define FLASH_BASE_ADDRESS    0x00E00000

/*******************************************************************************
   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
 *******************************************************************************/
#define ALLOCATED_FAT_SPACE   0x00200000

/*******************************************************************************
   Step 3. Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
               S_sector: the size of sector in the region
               N_sector: the number of sectors in the region
 *******************************************************************************/
#if defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define FLASH_REGIONINFO_VAR_MODIFIER  static
#else /* _LOW_COST_SINGLE_BANK_FLASH_ || __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#define FLASH_REGIONINFO_VAR_MODIFIER  static const
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ || __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo RegionInfo[] =
{
   {0x10000, 31},
   {0x2000, 8},
   EndRegionInfo /* Don't modify this line */
};



/*******************************************************************************
   Step 4. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/
#define TOTAL_BLOCKS          39

/*******************************************************************************
   Step 5. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
kal_uint32 PAGE_BUFFER_SIZE = 0;

/*******************************************************************************
   !CAUTION! !!Only for Enhanced Single Bank NOR Flash support!!
   Step 6. Modify the size of block erase queue, which is the number of reserved 
           blocks. It is recommended to be 10~20% of TOTAL_BLOCK value.
           If this value is less than 2, the FDM would use 1.5 internally.
 *******************************************************************************/
#define SNOR_ERASE_QUEUE_SIZE   5 

/*******************************************************************************
   Step 7. This is for the Enhanced Signle Bank Support, when this feature is
           turned on and still use multi-bank device, this table should be filled
           with correct value.
 
           This Table define the flash bank information which starts from 
           FLASH_BASE_ADDRESS, please fill the flash bank information table, every
           entry defines the memory space that contains continuous banks of equal size.
           Each entry element in the table is the format as below:
           {S_Bank, N_Bank},
               S_Bank: the size of bank in the entry
               N_Bank: the number of banks in the entry
 *******************************************************************************/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
FLASH_REGIONINFO_VAR_MODIFIER FlashBankInfo BankInfo[] =
{
   { 0x200000, 1 },
   EndBankInfo /* Don't modify this line */
};
#endif 

/*******************************************************************************
   NOR FLASH BLOCKS SIZE LOOKUP TABLE
          Each entry element
          {Offset, Block_Size},
               Offset:     the offset address
               Block_Size: the size of block
 *******************************************************************************/
#if 0
FLASH_REGIONINFO_VAR_MODIFIER FlashBlockTBL NOTREADYYET[] = /* Don't modify this line */
{
{0x0 , 0x2000},
{0x10000,0x10000},
{0xFF0000, 0x2000},
   EndBlockInfo /* Don't modify this line */
};
#endif


#endif /* __CUSTOM_EMI__ */

