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
 * fsal_buffer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   File System Abstraction Layer, buffered read/write handling.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "fsal.h"

extern kal_uint32   SaveAndSetIRQMask( void );
extern void     RestoreIRQMask( kal_uint32 );

/* read the block from file system into buffer */
static FSAL_Status FSAL_CacheFill(STFSAL *pstFSAL, kal_uint32 uBlock)
{
   FSAL_Status ret;
   kal_uint32 uFileOffsetOfBlock;
   kal_int32  uBytesToRead;

   FSAL_CHECK_ARG(pstFSAL!=NULL);

#if FSAL_VERBOSE
      printf("fsal_cache_fill(uBlock=%d)\n", uBlock);
#endif

   uFileOffsetOfBlock = uBlock * pstFSAL->uBufSize;
   if ((ret=FSAL_Direct_Seek(pstFSAL, uFileOffsetOfBlock))!=FSAL_OK) {
      return ret;
   }

   /* handle the last block of the file */
   if (uFileOffsetOfBlock + pstFSAL->uBufSize > pstFSAL->uFileSize)
      uBytesToRead = pstFSAL->uFileSize - uFileOffsetOfBlock;
   else
      uBytesToRead = pstFSAL->uBufSize;

   pstFSAL->uLastReadCount = 0;

#if FSAL_VERBOSE
   printf("   expected read len=%d\n", uBytesToRead);
#endif

   if (uBytesToRead > 0) {
      /* Since we have calculated the actual data count to read, this FSAL_Direct_Read should 
       * return only FSAL_OK; otherwise, error occured.
       */
      if ((ret = FSAL_Direct_Read(pstFSAL, pstFSAL->pbBuf, (kal_uint32)uBytesToRead)) != FSAL_OK) {
#if FSAL_VERBOSE
         printf("   actual read len=%d\n", pstFSAL->uLastReadCount);
         printf("   fill fail\n");
#endif
         return ret;
      }
   }

   if (pstFSAL->uLastReadCount != 0) {
      pstFSAL->uCachedBlock = uBlock;
      pstFSAL->bDirty = KAL_FALSE;
   }
#if FSAL_VERBOSE
   printf("   actual read len=%d\n", pstFSAL->uLastReadCount);
   printf("   fill success\n");
#endif
   return FSAL_OK;
}



static FSAL_Status fsal_read_block(STFSAL *pstFSAL, kal_uint8 *pbBuf, kal_uint32 uBlock, kal_uint32 uOffset, kal_uint32 uLen)
{
   FSAL_Status ret;
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(uBlock!=0xFFFFFFFF);
   FSAL_CHECK_ARG(pstFSAL->bBuffering==KAL_TRUE);

#if FSAL_VERBOSE
   printf("fsal_read_block(uBlock=%d)\n", uBlock);
#endif

   if (pstFSAL->uCachedBlock != uBlock) {
      /* cache miss */
      if ((ret = FSAL_CacheFlush(pstFSAL)) != FSAL_OK)
         return ret;
      if ((ret = FSAL_CacheFill(pstFSAL, uBlock)) != FSAL_OK)
         return ret;
   }

   FSAL_ASSERT(uOffset+uLen <= pstFSAL->uBufSize);
   if (pstFSAL->uFileOffset+uLen > pstFSAL->uFileSize) {
      kal_int32 uBytesToRead = (kal_int32)pstFSAL->uFileSize - (kal_int32)pstFSAL->uFileOffset;
      if (uBytesToRead <= 0) {
         pstFSAL->uLastReadCount = 0;
      } else {
         kal_mem_cpy(pbBuf, (pstFSAL->pbBuf) + uOffset, uBytesToRead);
         pstFSAL->uLastReadCount = (kal_uint32)uBytesToRead;
      }
      pstFSAL->uFileOffset = pstFSAL->uFileSize;
      return FSAL_READ_OVER_EOF;
   } else {
      kal_mem_cpy(pbBuf, (pstFSAL->pbBuf) + uOffset, uLen);
      pstFSAL->uFileOffset += uLen;
      pstFSAL->uLastReadCount = uLen;
      return FSAL_OK;
   }
}



FSAL_Status FSAL_Read(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pbBuf!=NULL);

   if (uSize==0) {
      pstFSAL->uLastReadCount = 0;
      return FSAL_OK;
   }

   if (KAL_TRUE==pstFSAL->bBuffering) {
      kal_uint32 uStartBlock, uEndBlock;
      kal_uint32 uOffsetInBlock, uLenInBlock;
      kal_uint32 uReadLength = 0;
      FSAL_Status ret;

      uStartBlock = (pstFSAL->uFileOffset) / pstFSAL->uBufSize;
      uEndBlock = (pstFSAL->uFileOffset + uSize - 1) / pstFSAL->uBufSize;

      /* handle the first block */
      uOffsetInBlock = (pstFSAL->uFileOffset) % pstFSAL->uBufSize;
      if (uEndBlock==uStartBlock)
         uLenInBlock = uSize;
      else
         uLenInBlock = pstFSAL->uBufSize - uOffsetInBlock;
      if ((ret = fsal_read_block(pstFSAL, pbBuf, uStartBlock, uOffsetInBlock, uLenInBlock)) != FSAL_OK) {
         return ret;
      }
      pbBuf += uLenInBlock;
      uSize -= uLenInBlock;
      
      /* handle the middle blocks, using FSAL_Direct_Read rather than fsal_read_block */
      if (uEndBlock>uStartBlock+1) {
         if ((ret = FSAL_Direct_Seek(pstFSAL, pstFSAL->uFileOffset)) != FSAL_OK)
            return ret;
         uReadLength = (uEndBlock-uStartBlock-1)*pstFSAL->uBufSize;
         ret = FSAL_Direct_Read(pstFSAL, pbBuf, uReadLength);
         pstFSAL->uFileOffset += pstFSAL->uLastReadCount;
         pstFSAL->uLastReadCount += uLenInBlock;
         if (ret != FSAL_OK) {
            return ret;
         }
         pbBuf += uReadLength;
         uSize -= uReadLength;
      }

      /* handle the last block */
      if(uEndBlock!=uStartBlock) {
         ret = fsal_read_block(pstFSAL, pbBuf, uEndBlock, 0, uSize);
         pstFSAL->uLastReadCount += (uLenInBlock + uReadLength);
         if (ret != FSAL_OK) {
            return ret;
         }
         uSize -= uSize;
      }

      FSAL_ASSERT(uSize==0);
      return FSAL_OK;
   } else if (KAL_FALSE==pstFSAL->bBuffering) {
      return FSAL_Direct_Read(pstFSAL, pbBuf, uSize);
   } else {
      return FSAL_MEMORY_CORRUPTION;
   }
}



FSAL_Status FSAL_CacheFlush(STFSAL *pstFSAL)
{
   FSAL_Status ret;
   kal_uint32 uFileOffsetOfBlock;
   kal_int32  uBytesToWrite;

   FSAL_CHECK_ARG(pstFSAL!=NULL);

#if FSAL_VERBOSE
      printf("fsal_cache_flush(uBlock=%d)\n", pstFSAL->uCachedBlock);
#endif

   if (pstFSAL->bBuffering!=KAL_TRUE)
      return FSAL_OK;

   if (pstFSAL->uCachedBlock==0xFFFFFFFF) {
      return FSAL_OK;
   }

   if (pstFSAL->bDirty!=KAL_TRUE) {
      return FSAL_OK;
   }

   uFileOffsetOfBlock = (pstFSAL->uCachedBlock) * (pstFSAL->uBufSize);
   if ((ret = FSAL_Direct_Seek(pstFSAL, uFileOffsetOfBlock)) != FSAL_OK) {
      return ret;
   }

   /* handle the last block of the file */
   if (uFileOffsetOfBlock + pstFSAL->uBufSize > pstFSAL->uFileSize)
      uBytesToWrite = pstFSAL->uFileSize - uFileOffsetOfBlock;
   else
      uBytesToWrite = pstFSAL->uBufSize;

#if FSAL_VERBOSE
   printf("   expected write len=%d\n", uBytesToWrite);
#endif

   if (uBytesToWrite > 0) {
      if ((ret = FSAL_Direct_Write(pstFSAL, pstFSAL->pbBuf, (kal_uint32)uBytesToWrite)) != FSAL_OK) {
#if FSAL_VERBOSE
         printf("   flush fail\n");
#endif
         return ret;
      }
   }
#if FSAL_VERBOSE
   printf("   flush success\n");
#endif
   pstFSAL->bDirty = KAL_FALSE;
   return FSAL_OK;
}



static FSAL_Status fsal_write_block(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uBlock, kal_uint32 uOffset, kal_uint32 uLen)
{
   FSAL_Status ret;
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(uBlock!=0xFFFFFFFF); /* XXX: SHOULD BE ABLE To HANDLE */
   FSAL_CHECK_ARG(KAL_TRUE==pstFSAL->bBuffering);

#if FSAL_VERBOSE
   printf("fsal_write_block(uBlock=%d)\n", uBlock);
#endif

   if (pstFSAL->uCachedBlock != uBlock) {
      /* cache miss */
      if ((ret = FSAL_CacheFlush(pstFSAL)) != FSAL_OK)
         return ret;
      if ((ret = FSAL_CacheFill(pstFSAL, uBlock)) != FSAL_OK)
         return ret;
   }

   FSAL_ASSERT(uOffset+uLen <= pstFSAL->uBufSize);
   kal_mem_cpy((pstFSAL->pbBuf) + uOffset, pbBuf, uLen);
   pstFSAL->uFileOffset += uLen;
   if (pstFSAL->uFileOffset > pstFSAL->uFileSize)
      pstFSAL->uFileSize = pstFSAL->uFileOffset;

#if FSAL_VERBOSE
   printf("   file size = %d\n", pstFSAL->uFileSize);
#endif

   pstFSAL->uCachedBlock = uBlock;
   pstFSAL->bDirty = KAL_TRUE;
   return FSAL_OK;
}



FSAL_Status FSAL_Write(STFSAL *pstFSAL, kal_uint8 *pbBuf, kal_uint32 uSize)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pbBuf!=NULL);

   if (uSize==0)
      return FSAL_OK;

   if (KAL_TRUE==pstFSAL->bBuffering) {
      kal_uint32 uStartBlock, uEndBlock;
      kal_uint32 uOffsetInBlock, uSizeInBlock;

      uStartBlock = (pstFSAL->uFileOffset) / pstFSAL->uBufSize;
      uEndBlock = (pstFSAL->uFileOffset + uSize - 1) / pstFSAL->uBufSize;

      /* handle the first block */
      uOffsetInBlock = (pstFSAL->uFileOffset) % pstFSAL->uBufSize;
      if (uEndBlock==uStartBlock)
         uSizeInBlock = uSize;
      else
         uSizeInBlock = pstFSAL->uBufSize - uOffsetInBlock;
      if(fsal_write_block(pstFSAL, pbBuf, uStartBlock, uOffsetInBlock, uSizeInBlock)!=FSAL_OK)
         return FSAL_WRITE_ERROR;
      pbBuf += uSizeInBlock;
      uSize -= uSizeInBlock;
      
      /* handle the middle blocks, using FSAL_Direct_Write rather than fsal_write_block */
      if (uEndBlock>uStartBlock+1) {
         kal_uint32 write_length;
         FSAL_Status ret;
         write_length = (uEndBlock-uStartBlock-1)*pstFSAL->uBufSize;         
         if ((ret = FSAL_CacheFlush(pstFSAL)) != FSAL_OK)
            return ret;
         if ((ret = FSAL_Direct_Write(pstFSAL, pbBuf, write_length)) != FSAL_OK)
            return ret;
         pbBuf += write_length;
         uSize -= write_length;
         pstFSAL->uFileOffset += write_length;
         pstFSAL->uFileSize += write_length;
      }

      /* handle the last block */
      if(uEndBlock!=uStartBlock) {
         FSAL_Status ret;
         if ((ret = fsal_write_block(pstFSAL, pbBuf, uEndBlock, 0, uSize)) != FSAL_OK)
            return ret;
         uSize -= uSize;
      }

      FSAL_ASSERT(uSize==0);
      return FSAL_OK;
   } else if (KAL_FALSE==pstFSAL->bBuffering) {
      return FSAL_Direct_Write(pstFSAL, pbBuf, uSize);
   } else {
      return FSAL_MEMORY_CORRUPTION;
   }
}



FSAL_Status FSAL_Seek(STFSAL *pstFSAL, kal_uint32 uOffset)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);

   if (KAL_TRUE==pstFSAL->bBuffering) {
      pstFSAL->uFileOffset = uOffset;
      return FSAL_OK;
   } else if (KAL_FALSE==pstFSAL->bBuffering) {
	   return FSAL_Direct_Seek(pstFSAL, uOffset);
   } else {
      return FSAL_MEMORY_CORRUPTION;
   }
}



FSAL_Status FSAL_GetCurPos(STFSAL *pstFSAL, kal_uint32 *puPosition)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puPosition!=NULL);

   if (KAL_TRUE==pstFSAL->bBuffering) {
      *puPosition = pstFSAL->uFileOffset;
      return FSAL_OK;
   } else if (KAL_FALSE==pstFSAL->bBuffering) {
      return FSAL_Direct_GetCurPos(pstFSAL, puPosition);
   } else {
      return FSAL_MEMORY_CORRUPTION;
   }
}



FSAL_Status FSAL_GetFileSize(STFSAL *pstFSAL, kal_uint32 *puFileSize)
{
   FSAL_Status eRet;
   kal_uint32 uSize;
   kal_uint32 savedMask;
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puFileSize!=NULL);

   eRet = FSAL_Direct_GetFileSize(pstFSAL, &uSize);
   *puFileSize = uSize;

#ifdef __MTK_TARGET__
// To prevent race condition
   savedMask = SaveAndSetIRQMask();
   pstFSAL->uFileSize = uSize;
   RestoreIRQMask(savedMask);
#endif

   if (KAL_TRUE==pstFSAL->bBuffering) {
      return eRet;      
   } else if (KAL_FALSE==pstFSAL->bBuffering) {
      return eRet;
   } else {
      return FSAL_MEMORY_CORRUPTION;
   }
}

