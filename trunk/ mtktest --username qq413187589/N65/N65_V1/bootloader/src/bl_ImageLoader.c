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
 *   bl_ImageLoader.c
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading image.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include <kal_release.h>
#include <bl_Init.h>
#include <bl_loader.h>
#include <bl_NFI.h>
#include <stdio.h>
#include <stdlib.h>
 
 
#define TOTAL_BIN_PACK   8

#define BACK_UP_ADDRESS  0x40000000

/*
typedef struct _BOOTLHeader_
{
   kal_char    ID1[12];
   kal_char    version[4];
   kal_uint32  length;
   kal_uint32  startAddr;
   kal_uint32  checksum;
   kal_char    ID2[8];
   NFI_MENU    NFIinfo;
   kal_uint16  pagesPerBlock;   
   kal_uint16  totalBlocks;
   kal_uint16  blockShift;
   kal_uint16  linkAddr[6];
   kal_uint16  lastBlock;
} BOOTL_HEADER;
*/
BOOTL_HEADER  BLHeader;   

#pragma arm section zidata = "INTERNZI"

/*
typedef struct {
	kal_uint32  m_load_addr;
	kal_uint32  m_length;
} Nand_ImageInfo_S;


typedef struct {
	Nand_ImageInfo_S	m_image[10];
	kal_uint32        m_image_count;
} Nand_ImageList_S;
*/
Nand_ImageList_S ImageHeader; 

#pragma arm section zidata


const kal_char blID1[12] = "BOOTLOADER!";
const kal_char blID2[8] = "NFIINFO";


extern const kal_int8 BootLDVerno[];
extern void jump_cmd(kal_uint32 baseAddr);
 
 
/**********************************************************
Description : C entry of the project.
Input       : None
Output      : None
***********************************************************/
void _errorExit(_RET_CODE errorCode, kal_uint32 pageNo, kal_uint32 *ptr)
{
   switch ( errorCode )
   {
      case NFI_ZERO_POINTER: 
         dbg_print("\n\n\rNFI Read Error: Zero pointer is encountered!\n\r");
         break;
      case NFI_READ_DATA_TIMEOUT:          
         dbg_print("\n\n\rNFI Read Error: Timeout while reading data!\n\r");
         break;
      case NFI_READ_SPARE_TIMEOUT:          
         dbg_print("\n\n\rNFI Read Error: Timeout while reading spare data!\n\r");
         break;
      case DMA_TRANSFER_DATA_TIMEOUT:          
         dbg_print("\n\n\rNFI Read Error: DMA timeout while transferring data!\n\r");
         break;
      case DMA_TRANSFER_SPARE_TIMEOUT:          
         dbg_print("\n\n\rNFI Read Error: DMA timeout while transferring spare data!\n\r");
         break;
      case NFI_ECC_2BITS_ERR: 
         dbg_print("\n\n\rNFI Read Error: NFI ECC 2-bits error!\n\r");
         break;
      default:
         break;
   }
   
   dbg_print(".....@ Page numberd %d, desitination address %x\n\r", pageNo, (kal_uint32)ptr);
   dbg_print(".....Good-bye with error!\n\n\n\r");
   
   while (1)
      WacthDogRestart();
}


/**********************************************************
Description : MultiPagaReading
Input       : None
Output      : None
***********************************************************/
static kal_uint32 MultiPagaReading(kal_uint8 index)
{
   _RET_CODE   status;
   kal_uint32  *ptr;
   kal_int32   length;
   kal_uint32  blockNo, maskI, pageTracking;
   kal_uint32  curPosition; /* in terms of pages */
   kal_uint32  addr1;
   kal_uint16  addr2;   
   kal_uint32  spare[64>>2];
   
   pageTracking = 0;
   blockNo = ImageHeader.m_image[index].m_start_block;   ;
   maskI = (0xffffffff >> (32-(BLHeader.blockShift - BLHeader.NFIinfo.pageShift)));
   /* Current position in terms of page */
   curPosition = blockNo << (BLHeader.blockShift - BLHeader.NFIinfo.pageShift);
      
   /* Exact position in terms of pages */
   addr1 = curPosition << BLHeader.NFIinfo.pageShift;
   addr2 = 0;
   if ( BLHeader.NFIinfo.addressCycle>4 )
   {
      if ( curPosition&0xffff0000 )
         addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
   }

   length = ImageHeader.m_image[index].m_length;   
   ptr = (kal_uint32 *)ImageHeader.m_image[index].m_load_addr;   
   
   /* The first block, which contains Image Header at last page, 
      must be skipped; thre processing is seperated from the others 
      blocks for performance consideration */      
   if ( length>(BLHeader.NFIinfo.pageSize*(BLHeader.pagesPerBlock-1)) )
   {
      while ( pageTracking<(BLHeader.pagesPerBlock-1) )
      {
#ifdef BIT_ERROR_TEST
		EmulateBitError((kal_uint32 *)ptr, (kal_uint32 *)&spare[0], 
 			BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize);
#endif

#ifdef BL_ECC_ENABLE     
         status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                               BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
         if ( status!=NFI_SUCCESS )
            _errorExit(status, curPosition, ptr);
   
         status = NFI_ParityCheck(ptr, &spare[0], BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                                  BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.IOInterface, \
                                  BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
         if ( status<0 )
            _errorExit(status, curPosition, ptr);
#else
         status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                               BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
         if ( status!=NFI_SUCCESS )
            _errorExit(status, curPosition, ptr);
#endif /* BL_ECC_ENABLE */    
   
         ptr = (kal_uint32 *)((kal_uint32)ptr + BLHeader.NFIinfo.pageSize);
         length -= BLHeader.NFIinfo.pageSize;
         pageTracking++;
         if ( pageTracking==(BLHeader.pagesPerBlock-1) )
            curPosition += 2;
         else
            curPosition++;
         addr1 = curPosition << BLHeader.NFIinfo.pageShift;  
         addr2 = 0;      
         if ( BLHeader.NFIinfo.addressCycle>4 )
         {
            if ( curPosition&0xffff0000 )
               addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
         }                                    
      }
   } 

   WacthDogRestart();
   while ( length>0 )
   {
      /* Looking for the next good block */
      if ( (curPosition & maskI)==0 )
      {
         status = KAL_FALSE;
         blockNo++;
         do
         {
            WacthDogRestart();
            
            if ( BLHeader.NFIinfo.addressCycle>4 )
            {
               if ( curPosition&0xffff0000 )
                  addr2 = (kal_uint16)(curPosition>>BLHeader.NFIinfo.pageShift);
            }
               
            if ( GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) == KAL_TRUE )  
               status = KAL_TRUE;
            else
            {
#ifdef BL_DEBUG               
               dbg_print("\n\rBad block at blokc %x\n\r", blockNo);
#endif /* BL_DEBUG */               
               /* Skip the bad block */
               blockNo++;
               curPosition = (blockNo << (BLHeader.blockShift - BLHeader.NFIinfo.pageShift));
               addr1 = curPosition << BLHeader.NFIinfo.pageShift;
               addr2 = 0;      
               if ( BLHeader.NFIinfo.addressCycle>4 )
               {
                  if ( curPosition&0xffff0000 )
                     addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
               }
            }         
         } while ( status==KAL_FALSE );          
         
         dbg_print("..");       
      }

#ifdef BIT_ERROR_TEST
 		EmulateBitError((kal_uint32 *)ptr, (kal_uint32 *)&spare[0], 
 			BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize);
#endif

#ifdef BL_ECC_ENABLE     
      status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
      if ( status!=NFI_SUCCESS )
         _errorExit(status, curPosition, ptr);

      status = NFI_ParityCheck(ptr, &spare[0], BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.IOInterface, \
                               BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
      if ( status<0 )
         _errorExit(status, curPosition, ptr);
#else
      status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_FALSE, KAL_FALSE);
      if ( status!=NFI_SUCCESS )
         _errorExit(status, curPosition, ptr);
#endif /* BL_ECC_ENABLE */     
         
      ptr = (kal_uint32 *)((kal_uint32)ptr + BLHeader.NFIinfo.pageSize);
      length -= BLHeader.NFIinfo.pageSize;
      curPosition++;
      addr1 = curPosition << BLHeader.NFIinfo.pageShift;      
      addr2 = 0;      
      if ( BLHeader.NFIinfo.addressCycle>4 )
      {
         if ( curPosition&0xffff0000 )
            addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
      }
   } 
      
   return blockNo;
}


/**********************************************************
Description : startLoading
Input       : None
Output      : None
***********************************************************/
void startLoading(void)
{
   kal_bool    status, flag;
   kal_uint32  blockNo, i, binNumber;
   kal_uint32  curPosition; /* in terms of pages */
   kal_uint32  addr1;
   kal_uint16  addr2;  
  
   dbg_print("\n\n\n\r~~~ Welcome to MTK Bootloader %s (since 2005) ~~~\n\r", BootLDVerno);
   dbg_print("**===================================================**\n\n\r");
   
   // Copy the Bootloader Header from predefined space
   {
      kal_uint32 *ptr_source = (kal_uint32 *)(0xa0000000);
      kal_uint32 *ptr_dest = (kal_uint32 *)&BLHeader;
      for (i=0; i<(64>>2); i++)
         *ptr_dest++ = *ptr_source++;
   }
   
   if ( strcmp(blID1, BLHeader.ID1) || strcmp(blID2, BLHeader.ID2) )
   {
       dbg_print("\nBootloader Header ID incorrect, quit!\n\r");
       dbg_print("\nID1(default %s) = %s\n\r", blID1, BLHeader.ID1);
       dbg_print("\nID2(default %s) = %s\n\n\n\r", blID2, BLHeader.ID2);
       return;
   }

   /*
    * NoteXXX: Since there are some problems in the BootROM, we cannot rely
    *          on BLHeader.lastBlock. We need to calculate the block number
    *          via BLHeader.linkAddr[].
    */
   dbg_print("Looking forward Image header!\n\r");
   /* search linkAddr to find out the boot loader image's last block */
   for (i = 0, blockNo = 0; i < 6; i++) {
      if (BLHeader.linkAddr[i] == 0) {
         break;
      } else {
         blockNo = BLHeader.linkAddr[i];
      }
   }
   /* increment by one to point to the Maui image's start block */
   blockNo++;

   flag = KAL_FALSE;   
   do 
   {
      WacthDogRestart();
      
      curPosition = (blockNo << (BLHeader.blockShift - BLHeader.NFIinfo.pageShift));
      addr1 = curPosition << BLHeader.NFIinfo.pageShift;
      addr2 = 0;      
      if ( BLHeader.NFIinfo.addressCycle>4 )
      {
         if ( curPosition&0xffff0000 )
            addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
      }
      
      if ( GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) == KAL_TRUE )
      {
         // Image header locates at the last page of the first good block
         curPosition = ((blockNo+1) << (BLHeader.blockShift - BLHeader.NFIinfo.pageShift)) - 1;
         addr1 = curPosition << BLHeader.NFIinfo.pageShift;
         addr2 = 0;
         if ( BLHeader.NFIinfo.addressCycle>4 )
         {
            if ( curPosition&0xffff0000 )
               addr2 = (kal_uint32)(curPosition >> BLHeader.NFIinfo.pageShift);
         }

#ifdef BIT_ERROR_TEST
 		EmulateBitError((kal_uint32 *)BACK_UP_ADDRESS, (kal_uint32 *)(BACK_UP_ADDRESS+2048), 
 			BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize);
#endif

#ifdef BL_ECC_ENABLE    
         status = NFI_PageRead((kal_uint32 *)BACK_UP_ADDRESS, (kal_uint32 *)(BACK_UP_ADDRESS+2048), BLHeader.NFIinfo.pageSize, \
                               BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
         if ( status!=NFI_SUCCESS )
            _errorExit(status, curPosition, (kal_uint32 *)BACK_UP_ADDRESS);
   
         status = NFI_ParityCheck((kal_uint32 *)BACK_UP_ADDRESS, (kal_uint32 *)(BACK_UP_ADDRESS+2048), BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                                  BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.IOInterface, \
                                  BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
         if ( status<0 )
            _errorExit(status, curPosition, (kal_uint32 *)BACK_UP_ADDRESS);
         {
           kal_uint32 *sourcePtr = (kal_uint32 *)BACK_UP_ADDRESS;
           kal_uint32 *destPtr = (kal_uint32 *)&ImageHeader;
           
           for (i=0; i<(sizeof(Nand_ImageList_S)>>2); i++)
              *destPtr++ = *sourcePtr++;
         }         
#else
         status = NFI_PageRead((kal_uint32 *)&ImageHeader, 0, sizeof(ImageHeader), \
                               BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, KAL_FALSE, KAL_FALSE);                               
#endif
         flag = KAL_TRUE;
         if ( ImageHeader.m_image_count>10 )
         {
            dbg_print("Image Header corrupted!\n\r");
            return;
         }
         else
            dbg_print("Image Header is found at Block %d!\n\r", blockNo);
      }
      else
      {
#ifdef BL_DEBUG         
         dbg_print("\n\rBad block at block %x\n\r", blockNo);
#endif /* BL_DEBUG */

         blockNo++;
      }
   } while ( (flag==KAL_FALSE) && (blockNo<=(BLHeader.totalBlocks>>2)) );
   
   if ( (blockNo>(BLHeader.totalBlocks>>2)) )
   {
      dbg_print("Image Header Not Fount, Quit!\n\r");
      return;
   }
   
   if ( (ImageHeader.m_image_count>TOTAL_BIN_PACK) )
   {
      dbg_print("Illegal Image Header Found (image count=%d), Quit!\n\r", ImageHeader.m_image_count);
      return;
   }
   
   dbg_print("\nNumber of image segments = %d\n\r", ImageHeader.m_image_count);
   for (i=0; i<ImageHeader.m_image_count; i++)
   {
      dbg_print("..[%d] Image size = %dBytes, start addr. =%x\n\r", \
                i, ImageHeader.m_image[i].m_length, ImageHeader.m_image[i].m_load_addr);
   }
   {
      kal_uint32 *sourcePtr = (kal_uint32 *)&ImageHeader;
      kal_uint32 *destPtr = (kal_uint32 *)BACK_UP_ADDRESS;
      
      for (i=0; i<(sizeof(Nand_ImageList_S)>>2); i++)
         *destPtr++ = *sourcePtr++;
   }
     
   dbg_print("\n\nStart loading image .."); 

#ifdef BL_DEBUG
   startGPTTImer3();   
#endif /* BL_DEBUG */
   
   binNumber = ImageHeader.m_image_count;
   
   WacthDogRestart();
   MultiPagaReading(0);   
   
#ifdef BL_DEBUG   
   addr2 = stopGPTTImer3();      
   {
      kal_char str[60];
      double output;
      
      output = ((double)addr2)*0.008;
            
      kal_sprintf(str,"\n\n\rTransfer done in %.04f seconds!\n\r", output);   
      dbg_print(str); 
      output = (((1/output)*ImageHeader.m_image[0].m_length) / 1024.0) / 1024.0;
      kal_sprintf(str,"Average bandwidth %.2f MB/s\n\n\r", output);   
      dbg_print(str); 
   }
#endif /* BL_DEBUG */
   
   dbg_print("\n\r.....Good-bye!\n\n\n\r");
   WacthDogRestart();
   
   jump_cmd(ImageHeader.m_image[0].m_load_addr);
}
