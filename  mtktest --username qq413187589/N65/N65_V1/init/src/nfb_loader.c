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
 *   NFB_loader.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "kal_release.h"
#include "app_buff_alloc.h"
#include "bl_loader.h"
#include "bmt.h"
#include "pwic.h" 
#include "device.h"
#include "nfb_loader.h"

 
#ifdef _NAND_FLASH_BOOTING_


#define BOOTLOADER_THRESHOLD_8BITS    0x400000
#define BOOTLOADER_THRESHOLD_16BITS   0x800000

#define NFB_PERCENTAGE_STEP           10

#define MAX_IMAGE_NUMBER              8

extern kal_uint32 Image$$INTSRAM_MULTIMEDIA$$Base;

extern void SYS_InitRegions(void);
extern kal_bool DRV_NFB_POWERON(void);
extern void CacheInitSecondaryMAUI(void);
extern void ShowCategory401Screen(kal_uint16 percentage);
extern kal_int32 NFB_ReadPhysicalPage(kal_int32 PhyBlock, kal_int32 PhyPage, void * Data);

#if ( defined(__MAUI_BASIC__) || defined(__L1_STANDALONE__) || defined(EMPTY_MMI) )
#define NFB_DisplayProgressBar(X)
#else
#define NFB_DisplayProgressBar(X) ShowCategory401Screen(X) 
#endif

kal_bool   NFB_SecondaryImageLoaded = KAL_FALSE;


/*************************************************************************
* FUNCTION
*  NFB_startLoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void NFB_startLoadingSecondaryMAUI(void)
{
   kal_bool   displayStatus=KAL_FALSE;
   kal_int32  ret;
   kal_int32  length;   
   kal_uint16 percentage;
   kal_uint32 blockNo, index;
   kal_uint32 check_point, percentage_step;
   kal_uint32 accumulativeSize, totalLength;
   kal_uint32 *destinationPtr; 
   kal_uint32 SecondaryMAUIReadFailed=0, pagesPerBlock=0, threshold=0, pageIndex=0;

   Nand_ImageList_S  *imageHeaderPtr = (Nand_ImageList_S *)(&Image$$INTSRAM_MULTIMEDIA$$Base);   
   
   ret = NFB_ReadPhysicalPage(0xFFFFFFFF, 0xFFFFFFFF, 0);
   if ( ret==16 )
      threshold = BOOTLOADER_THRESHOLD_16BITS;
   else if ( ret==8 )
      threshold = BOOTLOADER_THRESHOLD_8BITS;
   else
      EXT_ASSERT(SecondaryMAUIReadFailed, ret, 0, 0);
      
   EXT_ASSERT((imageHeaderPtr->m_image_count<MAX_IMAGE_NUMBER), imageHeaderPtr->m_image_count, 0, 0);      
     
   /* Read the first page to get the NAND-flash configuration */
   if ( imageHeaderPtr->m_image_count>1 )
      ret = NFB_ReadPhysicalPage((imageHeaderPtr->m_image[1]).m_start_block, \
                                 0, \
                                 (kal_uint32 *)(imageHeaderPtr->m_image[1]).m_load_addr);
                                  
   if ( ret==2048 )
      pagesPerBlock = 64;         
   else if ( ret==512 )
      pagesPerBlock = 32;
   else
      EXT_ASSERT(SecondaryMAUIReadFailed, ret, 0, 0);     
                                     
   /* Sum the total length of each image */
   index = 1;
   totalLength = 0;
   while ( index<imageHeaderPtr->m_image_count )
   {
      if ((imageHeaderPtr->m_image[index]).m_reserved == NULL)
      {
         totalLength += (imageHeaderPtr->m_image[index]).m_length;
      }
      index++;
   }
   
   accumulativeSize = (imageHeaderPtr->m_image[0]).m_length + ret;   
   
   if ( accumulativeSize >= threshold )
      percentage_step = totalLength / NFB_PERCENTAGE_STEP;
   else if ( (totalLength+accumulativeSize) > threshold )
      percentage_step = (totalLength+accumulativeSize-threshold) / NFB_PERCENTAGE_STEP;
   else
      percentage_step = 0;
         
   percentage = 0;
   check_point = accumulativeSize + percentage_step;                               
      
   index = 1;
   while ( index<imageHeaderPtr->m_image_count )
   {
      destinationPtr = (kal_uint32 *)(imageHeaderPtr->m_image[index]).m_load_addr;        
      length = (kal_int32)(imageHeaderPtr->m_image[index]).m_length;
      blockNo = (imageHeaderPtr->m_image[index]).m_start_block;
      
      if ( index==1 )
      {
         destinationPtr += (ret>>2);
         length -= ret;      
         pageIndex = 1;         
      }      
      if ((imageHeaderPtr->m_image[index]).m_reserved != NULL)
      {
         index++;
         continue;
      }
      
      while ( length>0 )
      {            
         if ( (accumulativeSize >= threshold) && (displayStatus==KAL_FALSE) && (percentage_step!=0) )
         {
            /* Ready to latch-up power, BMT will do the final judgement! */
            DRV_NFB_POWERON();
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            NFB_DisplayProgressBar(percentage);            
            percentage += NFB_PERCENTAGE_STEP;
            displayStatus = KAL_TRUE;
         }
         
         /* Reading a block */
         while ( (pageIndex < pagesPerBlock) && (length>0) )
         {
            ret = NFB_ReadPhysicalPage(blockNo, pageIndex, destinationPtr);
            
            if ( ret!=-1 )
            {
               accumulativeSize += ret;
               destinationPtr += (ret>>2);
               length -= ret;
               pageIndex++;
            }
            // Bad block 
            else
               break; 
         }
         
         blockNo++;
         pageIndex = 0;
         
         if ( (accumulativeSize >= check_point) &&  (displayStatus==KAL_TRUE) && (percentage_step!=0) )
         {
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            NFB_DisplayProgressBar(percentage);    
            percentage += NFB_PERCENTAGE_STEP;
            check_point = accumulativeSize + percentage_step;
         }
      }
      index ++;
   }
   
   if ( displayStatus==KAL_FALSE )
   {
      /* Ready to latch-up power, BMT will do the final judgement! */
      DRV_NFB_POWERON();
   }
   else
   {
      /* Ready to show-up the first screen, MMI will do the final judgement! */
      NFB_DisplayProgressBar(100);    
   }
}

 
/*************************************************************************
* FUNCTION
*  NFB_LoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void NFB_LoadingSecondaryMAUI(void)
{  
   /* Start data transfer */
   NFB_startLoadingSecondaryMAUI();     
   
   /* Initialize RW region for SECONDARY_EXTSRAM_RW */
   SYS_InitRegions();
  
   /* Cacheable the RO-CODE and RO-DATA area */
   CacheInitSecondaryMAUI();
   
   NFB_SecondaryImageLoaded = KAL_TRUE;    
}

/*************************************************************************
* Enhanced NFB, on-demand loader
*  
* GLOABL VARIABLES
*************************************************************************/
kal_bool   NFB_ThirdRomConfiged = KAL_FALSE;

#define MAX_CONTENT_NUMBER              8
#define ENFB_ID_IMAGEHEADER    0x42464E45   /* ENFB */
#define ENFB_IDSTRING1         "ENFB"
#define ENFB_IDSTRING2         "ENFB3RDROM!"

#define ENFB_TYPE_ID_MASK      0xFF000000
#define ENFB_PAGESIZE          2048

#define ENFB_UINT_RSHIFT       2

typedef struct _ENFB_Header_
{
   kal_char    ID1[11];
   kal_uint8   type;
   kal_uint32  begin;
   kal_uint32  end;
   kal_char    ID2[12];
} ENFB_HEADER;

typedef struct 
{
   kal_uint32   type;
   kal_uint32   offset;
   kal_uint32   length;
} enfb_indextbl;

typedef struct 
{
   kal_uint32   BaseBlockNo;               /* The 3rd Rom begin block   */
   kal_uint32   AtblBlockNo;               /* The alocation table block */
   kal_uint32   pagesPerBlock;             /* geometry information */
   kal_uint32   pagesize;                  /* geometry information */
   kal_uint32   MaxOffset;
   kal_uint32   ShiftToBlockSeq;           /* use shift to speed up */
   kal_uint32   ShiftToPageSeq;            /* use shift to speed up */
   kal_uint32   AtblBuffer[ ENFB_PAGESIZE >> ENFB_UINT_RSHIFT ];
   kal_uint32   a_pageNo;
   kal_uint32   ReadBuffer[ ENFB_PAGESIZE >> ENFB_UINT_RSHIFT ];
   kal_uint32   l_offset;
   kal_uint32   l_blockNo;
   kal_mutexid  critical_section;
} enfb_context;

static enfb_context  enfb_g;
static enfb_indextbl enfb_t[MAX_CONTENT_NUMBER];
/*************************************************************************
 * LIB/CODE DYNAMIC DOWNLOAD CONFIGURE
*************************************************************************/
typedef struct 
{
   kal_uint16   count;
   kal_uint8    flag;
   kal_uint8    type;
   void        *dst_addr;
} enfb_libtbl;

extern kal_uint32  Load$$THIRD_ROM$$Base;

static enfb_libtbl enfb_c[] =
{
   {0, 0, ENFB_CONTENT_ENDMARKER, }
};

/*************************************************************************
 * ARTIFICIAL and SEMI-FINISHED THIRD ROM HEADER
*************************************************************************/
#pragma arm section rodata = "NFB3RDROM_HEADER_HINT"
#define ENFB_IDSTRING3  "ENFB3RDROM"   /* MUST SYNC with script tools/EnfbPack3rdRom.pl ; it add tail ! */ 
#define ENFB_TBLNUM     8
const ENFB_HEADER g_enfb_3rdrom_header[ENFB_TBLNUM]=
{
   {ENFB_IDSTRING3, ENFB_CONTENT_IMAGERES,
                   0 /* external */,
                   0 /* external */,
                   "CustENFBImg" /* MUST SYNC with script tools/EnfbPack3rdRom.pl */ },
   {ENFB_IDSTRING3, ENFB_CONTENT_STRINGRES,
                   0 /* external */,
                   0 /* external */,
                   "CustENFBStr" /* MUST SYNC with script tools/EnfbPack3rdRom.pl */ },
   {ENFB_IDSTRING3, ENFB_CONTENT_ENDMARKER,
                   ((kal_uint32) &Load$$THIRD_ROM$$Base),
                   0 /* Tail mark */,
                   NULL }
};
#pragma arm section rodata


/*************************************************************************
* Enhanced NFB, on-demand loader
*  
* SUB-ROUTINES
*************************************************************************/
static kal_bool NFB_RES_init_tbl(kal_uint32 RomMaxLength)
{
   kal_uint32 i;
   ENFB_HEADER *header_ptr = (ENFB_HEADER*) enfb_g.ReadBuffer;

   for (i=0; i<MAX_CONTENT_NUMBER; header_ptr++)
   {
      if (strncmp(header_ptr->ID1, ENFB_IDSTRING2, 11) == 0)
      {
         enfb_t[i].type   = header_ptr->type;
         enfb_t[i].offset = header_ptr->begin;
         enfb_t[i].length = (header_ptr->end >= header_ptr->begin) ? header_ptr->end - header_ptr->begin + 1 : 0;

         if (i > 0) /* valid the ordering */
         {
            if (header_ptr->type == ENFB_CONTENT_ENDMARKER ) /* end-of-content */
            {
               if ((enfb_t[i-1].offset + enfb_t[i-1].length) > RomMaxLength)
               {
                  return KAL_FALSE;
               }
               return KAL_TRUE;
            }

            if (enfb_t[i].type > enfb_t[i-1].type
             && enfb_t[i].offset > enfb_t[i-1].offset
             && enfb_t[i-1].length > 0
             && enfb_t[i].offset >= (enfb_t[i-1].offset + enfb_t[i-1].length) )
            {
               /* pass , do-nothing */
            }
            else
            {
               return KAL_FALSE;
            }
         }

         i++;
      }
      else
      {
         return KAL_FALSE;
      }
   }
#define TooManyContent    0
   ASSERT(TooManyContent);

   return KAL_FALSE;
}
      
static enfb_indextbl* NFB_RES_lookup_tbl(kal_uint32 cid)
{
   enfb_indextbl *p;

   for (p=enfb_t; p->type < cid; p++);

   if (p->type == ENFB_CONTENT_ENDMARKER )
   {
      return NULL;
   }
   else if (cid == p->type)
   {
      return p;
   }
   return NULL;
}

static void NFB_RES_locate_block(kal_uint32 to_offset)
{
   kal_int32 val1, val2; /* Note the variable will be reused serveral times for different purpose */

   /* best case : the same block -- short cut */
   val1 = to_offset - enfb_g.l_offset;
   if (val1 >= 0 && val1 < (1 << enfb_g.ShiftToBlockSeq))
   {
      /* enfb_g.l_blockNo = enfb_g.l_blockNo; */
      return;
   }

   /* good : the offset is in the AtblBuffer (page cache hit) */ 
   val2 = to_offset >> (enfb_g.ShiftToBlockSeq + enfb_g.ShiftToPageSeq - ENFB_UINT_RSHIFT); 
   if (enfb_g.a_pageNo == val2)
   {
      val1             = to_offset >> enfb_g.ShiftToBlockSeq;
      val2             = (1 << (enfb_g.ShiftToPageSeq - ENFB_UINT_RSHIFT)) - 1;
      enfb_g.l_blockNo = enfb_g.AtblBuffer[ val1 & val2 ];
      enfb_g.l_offset  = val1 << enfb_g.ShiftToBlockSeq;
      return;
   }

   /* not bad : the offset is the 1st block (set value directly) */
   if (to_offset < (1 << enfb_g.ShiftToBlockSeq))
   {
      enfb_g.l_blockNo = enfb_g.BaseBlockNo;
      enfb_g.l_offset  = 0;
      return;
   }

   /* all short cut fail : need to flush AtblBuffer and lookup */
   val1 = NFB_ReadPhysicalPage( enfb_g.AtblBlockNo, \
                                val2, \
                                (void *)enfb_g.AtblBuffer);
   ASSERT(val1 > 0);
   
   enfb_g.a_pageNo  = val2;
   val1             = to_offset >> enfb_g.ShiftToBlockSeq;
   val2             = (1 << (enfb_g.ShiftToPageSeq - ENFB_UINT_RSHIFT)) - 1;
   enfb_g.l_blockNo = enfb_g.AtblBuffer[ val1 & val2 ];
   enfb_g.l_offset  = val1 << enfb_g.ShiftToBlockSeq;

}

static void NFB_RES_partial_page_read(kal_int32 page_index, void * dst_addr, kal_uint32 start, kal_uint32 length)
{
   void *buf_ptr = (void *) enfb_g.ReadBuffer;

   NFB_ReadPhysicalPage( enfb_g.l_blockNo, \
                         page_index,       \
                         buf_ptr);
   buf_ptr = (void *)((kal_uint32) buf_ptr + start);
   memcpy(dst_addr, buf_ptr, length);
}

static void NFB_RES_Read_Routine(void * dst_addr, kal_uint32 rom_offset, kal_uint32 length)
{
   kal_int32  pg;
   kal_uint32 s1;

   /* split to 3 seagments */
   NFB_RES_locate_block(rom_offset);
      
   s1 = rom_offset & ((1 << enfb_g.ShiftToPageSeq) - 1);
   pg = (rom_offset - enfb_g.l_offset) >> enfb_g.ShiftToPageSeq;

   /* segment 1 --- to page align */
   if (s1)
   {
      if ((s1 + length) > enfb_g.pagesize)
      {
         NFB_RES_partial_page_read( pg,        \
                                    dst_addr,  \
                                    s1,        \
                                    enfb_g.pagesize - s1);
         dst_addr = (void *)((kal_uint32) dst_addr + (enfb_g.pagesize - s1));
         length   -= (enfb_g.pagesize - s1);
         pg++;
      }
      else
      {
         NFB_RES_partial_page_read( pg,       \
                                    dst_addr, \
                                    s1,       \
                                    length);
         dst_addr  = (void *)((kal_uint32) dst_addr + length);
         length    = 0;
         pg++;
      }
   }
      
   /* segment 2 --- times of pagesize */
   while (length > enfb_g.pagesize)
   {
      if (pg == enfb_g.pagesPerBlock)
      {
         NFB_RES_locate_block( enfb_g.l_offset + (1 << enfb_g.ShiftToBlockSeq));
         pg = 0;
      }
      NFB_ReadPhysicalPage( enfb_g.l_blockNo, \
                            pg,               \
                            dst_addr);
      dst_addr  = (void *)((kal_uint32)dst_addr + enfb_g.pagesize);
      length   -= enfb_g.pagesize;
      pg++;
   }

   /* segment 3 --- remain to end */
   if (length)
   {
      if (pg == enfb_g.pagesPerBlock)
      {
         NFB_RES_locate_block( enfb_g.l_offset + (1 << enfb_g.ShiftToBlockSeq));
         pg = 0;
      }
      NFB_RES_partial_page_read( pg,       \
                                 dst_addr, \
                                 0,        \
                                 length);
      length = 0;
   }

}

/*************************************************************************
* FUNCTION
*  NFB_InitThirdROM
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void NFB_InitThirdROM(void)
{  
   kal_uint32         i;
   kal_int32          ret;
   Nand_ImageList_S  *imageHeaderPtr = (Nand_ImageList_S *)(&Image$$INTSRAM_MULTIMEDIA$$Base);   

   ASSERT(NFB_SecondaryImageLoaded == KAL_FALSE);

   for (i=2; i<imageHeaderPtr->m_image_count; i++)
   {
      if (imageHeaderPtr->m_image[i].m_reserved == ENFB_ID_IMAGEHEADER)
      {
         /* init MTD first */
         ret = NFB_ReadPhysicalPage(0xFFFFFFFF, 0xFFFFFFFF, 0);
         ASSERT(ret == 8 || ret == 16);

         /* init allocation table first */
         enfb_g.AtblBlockNo = imageHeaderPtr->m_image[i].m_start_block;
         ret = NFB_ReadPhysicalPage( enfb_g.AtblBlockNo, \
                                     0, \
                                     (void *)enfb_g.AtblBuffer);
         if (ret == (-1)) break;
         enfb_g.a_pageNo    = 0;

         /* init third rom geometry then */
         enfb_g.MaxOffset   = imageHeaderPtr->m_image[i].m_length;
         enfb_g.BaseBlockNo = enfb_g.AtblBuffer[0];

         ret = NFB_ReadPhysicalPage( enfb_g.BaseBlockNo, \
                                     0, \
                                     (void *)enfb_g.ReadBuffer);
         
         ASSERT(ret <= ENFB_PAGESIZE); /* supported page size */
         enfb_g.pagesize      = ret;
         if ( ret==2048 )
         {
            enfb_g.pagesPerBlock   = 64;
            enfb_g.ShiftToPageSeq  = 11;
            enfb_g.ShiftToBlockSeq = 11 + 6;
         }
         else if ( ret==512 )
         {
            enfb_g.pagesPerBlock   = 32;
            enfb_g.ShiftToPageSeq  =  9;
            enfb_g.ShiftToBlockSeq =  9 + 5;
         }
         else
         {
            break;
         }
         /* ASSERT() --- not necessary , SecondaryROM do assert later*/

         /* init 3rd ROM current position */
         enfb_g.l_offset  = 0;
         enfb_g.l_blockNo = enfb_g.BaseBlockNo;

         /* init done , raise flag */
         NFB_ThirdRomConfiged = NFB_RES_init_tbl(enfb_g.MaxOffset);

         /* create mutex */
         enfb_g.critical_section = kal_create_mutex("ENFB_Loader");
         return;
      }
   }
}

/*************************************************************************
* FUNCTION
*  NFB_RES_Load
*
* DESCRIPTION
*  Invoked by resource retriever to get specific content segment in the 
*  on-demand load ROM image.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#define NFBLOADER_CRITICAL_SECTION_BEGIN          do{ \
                    if(kal_query_systemInit()) break; \
             kal_take_mutex(enfb_g.critical_section); \
                                            }while(0)
#define NFBLOADER_CRITICAL_SECTION_END            do{ \
                    if(kal_query_systemInit()) break; \
             kal_give_mutex(enfb_g.critical_section); \
                                            }while(0)
kal_bool NFB_RES_Load(kal_uint8 cid, void * dst_addr, kal_uint32 offset, kal_uint32 length)
{  
   enfb_indextbl *tbl_ptr = NULL;
   kal_uint32     to_offset;

   /* lookup index table */
   if (NFB_ThirdRomConfiged)
   {
      tbl_ptr = NFB_RES_lookup_tbl((kal_uint32) cid);
   }

   EXT_ASSERT(NFB_ThirdRomConfiged && tbl_ptr, (kal_uint32)cid, offset, length);

   /* check invalid segment */ 
   if ((offset+length) > tbl_ptr->length)
   {
      return KAL_FALSE;
   }

   to_offset = tbl_ptr->offset + offset;

   NFBLOADER_CRITICAL_SECTION_BEGIN;

   NFB_RES_Read_Routine(dst_addr, to_offset, length);

   NFBLOADER_CRITICAL_SECTION_END;

   return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  NFB_RES_Loadv
*
* DESCRIPTION
*  usually invoked by application to get a group of content in the on-demand
*  load ROM image.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
* LIMITATION / CAUTION
*    1. Order N^2 ;
*       Assumption is CPU should be faster than I/O ==> performance gain if sorted access, and
*       the application may not provide sorted scatter array, and
*       it need extra pointer array space to do sort before batch I/O
*    2. Application can not provide duplicate offset in the scatter array,
*       split proc 1 and proc 2 to avoid wrong action when such strange input case.
*************************************************************************/
kal_bool NFB_RES_Loadv(kal_uint8 cid, enfb_scatter *scatter, kal_uint32 scatter_number)
{
   enfb_indextbl *tbl_ptr = NULL;
   kal_uint32     load_count, scatter_done;
   kal_uint32     prev_offset, next_offset;
   kal_uint32     scatter_index;
   enfb_scatter  *scatter_ptr;

   /* lookup index table */
   if (NFB_ThirdRomConfiged)
   {
      tbl_ptr = NFB_RES_lookup_tbl((kal_uint32) cid);
   }

   EXT_ASSERT(NFB_ThirdRomConfiged && tbl_ptr && scatter && scatter_number,
              (kal_uint32)cid,
              (kal_uint32)scatter,
              scatter_number);

   NFBLOADER_CRITICAL_SECTION_BEGIN;

   /* proc 1 --- seek the lowest offset record in scatter array */
   load_count   = 0;
   
   for (prev_offset = tbl_ptr->length, scatter_index = 0, scatter_ptr = NULL;
        scatter_index < scatter_number;
        scatter_index++)
   {
      if (scatter[scatter_index].offset < prev_offset)
      {
         prev_offset = scatter[scatter_index].offset;
         scatter_ptr = scatter + scatter_index;
      }
   }
   if (scatter_ptr != NULL &&
      (prev_offset + scatter_ptr->length <= tbl_ptr->length))
   {
      NFB_RES_Read_Routine(scatter_ptr->dst_addr, prev_offset + tbl_ptr->offset, scatter_ptr->length);
      load_count++;
   }

   /* proc 2 --- Do remain record in scatter array */
   for (scatter_done = 1;
        scatter_done < scatter_number;
        scatter_done++)
   {
      for (next_offset = tbl_ptr->length, scatter_index = 0, scatter_ptr = NULL;
           scatter_index < scatter_number;
           scatter_index++)
      {
         if (scatter[scatter_index].offset > prev_offset &&
             scatter[scatter_index].offset < next_offset)
         {
            next_offset = scatter[scatter_index].offset;
            scatter_ptr = scatter + scatter_index;
         }
      }
      /* get the sorted one, then check the segment valid or not */
      if (scatter_ptr != NULL &&
         (next_offset + scatter_ptr->length <= tbl_ptr->length))
      {
         NFB_RES_Read_Routine(scatter_ptr->dst_addr, next_offset + tbl_ptr->offset, scatter_ptr->length);
         prev_offset = next_offset;
         load_count++;
      }
   }

   NFBLOADER_CRITICAL_SECTION_END;
   
   if (load_count != scatter_number)
   {
      return KAL_FALSE;
   }
   return KAL_TRUE;
}

/*************************************************************************
 * COMMON ROUTINES FOR LIB/CODE DYNAMIC DOWNLOAD
*************************************************************************/
static enfb_libtbl * NFB_LIB_lookup_tbl(kal_uint8 cid)
{
   enfb_libtbl *l;

   for (l=enfb_c; l->type < cid; l++);

   if (l->type == ENFB_CONTENT_ENDMARKER )
   {
      return NULL;
   }
   else if (cid == l->type)
   {
      return l;
   }
   return NULL;
}

static void NFB_LIB_conflict_detect(void *address)
{
   enfb_libtbl *l;

   for (l=enfb_c; l->type < ENFB_CONTENT_ENDMARKER; l++)
   {
      if (l->flag) ASSERT(l->dst_addr != address);
   }
}

/*************************************************************************
* FUNCTION
*  NFB_LIB_Load
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
* LIMITATION / CAUTION
*************************************************************************/
void NFB_LIB_Load(kal_uint8 cid)
{
   enfb_indextbl *tbl_ptr = NULL;
   enfb_libtbl   *lib_ptr = NULL;

   /* 1. lookup index table */
   if (NFB_ThirdRomConfiged)
   {
      tbl_ptr = NFB_RES_lookup_tbl((kal_uint32) cid);
   }

   EXT_ASSERT(NFB_ThirdRomConfiged && tbl_ptr, (kal_uint32)cid, 0, 0);

   /* 2. Look up code table */
   lib_ptr = NFB_LIB_lookup_tbl(cid);

   NFBLOADER_CRITICAL_SECTION_BEGIN;

   /* 3. conflic check, assert if detect */
   NFB_LIB_conflict_detect(lib_ptr->dst_addr);

   /* 4. trigger load operation */
   NFB_RES_Read_Routine(lib_ptr->dst_addr, tbl_ptr->offset, tbl_ptr->length);

   /* 5. raise flag & unlock */
   lib_ptr->count++;
   lib_ptr->flag = (kal_uint8) KAL_TRUE;

   NFBLOADER_CRITICAL_SECTION_END;
}

/*************************************************************************
* FUNCTION
*  NFB_LIB_Unload
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
* LIMITATION / CAUTION
*************************************************************************/
void NFB_LIB_Unload(kal_uint8 cid)
{
   enfb_indextbl *tbl_ptr = NULL;
   enfb_libtbl   *lib_ptr = NULL;

   /* 1. lookup index table */
   if (NFB_ThirdRomConfiged)
   {
      tbl_ptr = NFB_RES_lookup_tbl((kal_uint32) cid);
   }

   EXT_ASSERT(NFB_ThirdRomConfiged && tbl_ptr, (kal_uint32)cid, 0, 0);

   /* 2. Look up code table */
   lib_ptr = NFB_LIB_lookup_tbl(cid);

   NFBLOADER_CRITICAL_SECTION_BEGIN;
   
   /* 3. conflic check, assert if detect */
   ASSERT(lib_ptr->flag == KAL_TRUE);
   
   /* 4. give the flag & exit */
   lib_ptr->flag = KAL_FALSE;

   NFBLOADER_CRITICAL_SECTION_END;
}

#endif /* _NAND_FLASH_BOOTING_ */
