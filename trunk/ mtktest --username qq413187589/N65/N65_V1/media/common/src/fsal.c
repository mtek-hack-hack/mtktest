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
 * fsal.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   File System Abstraction Layer.
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
 *
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

#ifndef FSAL_STANDALONE
   #include "drm_gprot.h"
#endif

/* Put common code of FSAL_Open series APIs in this function */
void fsal_Open_Internal(STFSAL *pstFSAL)
{
   /* pstFSAL has been checked to be valid in FSAL_Open series APIs */
   pstFSAL->bBuffering = KAL_FALSE;
   pstFSAL->pbBuf = NULL;
   pstFSAL->uBufSize = 0;
   /* reserved value to identify an invalid read buffer */
   pstFSAL->uCachedBlock = 0xFFFFFFFF;
   pstFSAL->bDirty = KAL_FALSE;
   pstFSAL->uLastReadCount = 0;
}



FSAL_Status FSAL_Open(STFSAL *pstFSAL, void *szFile, FSAL_FileMode eMode)
{
   FSAL_Status ret;
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(szFile!=NULL);

   /* Open File */
   if ((ret=FSAL_Direct_Open(pstFSAL, szFile, eMode))!=FSAL_OK)
      return ret;

   /* Set File Size */
   if (eMode != FSAL_ROMFILE) {
      pstFSAL->uRamFileSize = 0;
      if ((ret=FSAL_Direct_GetFileSize(pstFSAL, &(pstFSAL->uFileSize)))!=FSAL_OK) {
         FSAL_Direct_Close(pstFSAL);
         return ret;
      }
   }

   /* Set File Position */
   if (eMode == FSAL_READ || eMode == FSAL_WRITE || eMode == FSAL_ROMFILE) {
      pstFSAL->uFileOffset = 0;
      pstFSAL->uRamFileOffset = 0;
   } else if (eMode == FSAL_APPEND ) {
      pstFSAL->uFileOffset = pstFSAL->uFileSize;
      if ((ret=FSAL_Direct_Seek(pstFSAL, pstFSAL->uFileOffset))!=FSAL_OK) {
         FSAL_Direct_Close(pstFSAL);
         return ret;
      }
   }

/*
   if ((ret=FSAL_Direct_GetCurPos(pstFSAL, &(pstFSAL->uFileOffset)))!=FSAL_OK) {
      FSAL_Direct_Close(pstFSAL);
      return ret;
   }
*/
   fsal_Open_Internal(pstFSAL);

   return FSAL_OK;
}



FSAL_Status FSAL_Open_WithHandle(STFSAL *pstFSAL, void *pFileHandle)
{
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pFileHandle!=NULL);

   /* Set File Handle */
#if FSAL_PLATFORM_WIN32
   pstFSAL->hFile = pFileHandle;
#elif FSAL_PLATFORM_KAL
   pstFSAL->hFile = (FS_HANDLE) pFileHandle;
#elif FSAL_PLATFORM_MEMORY
   FSAL_ASSERT(KAL_FALSE);
#endif
   pstFSAL->pbFile = NULL;

   /* Set File Size */
   if ((ret = FSAL_Direct_GetFileSize(pstFSAL, &(pstFSAL->uFileSize))) != FSAL_OK)
      return ret;

   /* Set File Position */
   if ((ret = FSAL_Direct_GetCurPos(pstFSAL, &(pstFSAL->uFileOffset))) != FSAL_OK)
      return ret;

   fsal_Open_Internal(pstFSAL);

   return FSAL_OK;
}



FSAL_Status FSAL_Open_Attach(STFSAL *pstFSAL, STFSAL *pstFSAL_Existing)
{
   FSAL_Status ret;
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pstFSAL_Existing!=NULL);

   pstFSAL->hFile = pstFSAL_Existing->hFile;
   pstFSAL->pbFile = pstFSAL_Existing->pbFile;

   /* Set File Size */
   pstFSAL->uFileSize = pstFSAL_Existing->uFileSize;
   pstFSAL->uRamFileSize = pstFSAL_Existing->uRamFileSize;

   /* Set File Position */
   if ((kal_int32)(pstFSAL->hFile) != -1) {
      if ((ret = FSAL_Direct_GetCurPos(pstFSAL_Existing, &(pstFSAL->uFileOffset))) != FSAL_OK)
         return ret;
   } else if ((ret=FSAL_Direct_GetCurPos(pstFSAL_Existing, &(pstFSAL->uRamFileOffset))) != FSAL_OK)
      return ret;

   fsal_Open_Internal(pstFSAL);

   return FSAL_OK;
}



void FSAL_SetBuffer(STFSAL *pstFSAL, kal_uint32 uBufferSize, kal_uint8 *pbBuf)
{
   FSAL_ASSERT_NO_RET_VAL(pstFSAL!=NULL);   
   /* If opened in FSAL_ROMFILE mode, it is unnecessary to set buffer. */
   if (pstFSAL->pbFile) {
      pstFSAL->bBuffering = KAL_FALSE;
      return;
   }

   if (uBufferSize == 0 || pbBuf == NULL) {
      pstFSAL->bBuffering = KAL_FALSE;
   } else {
      pstFSAL->bBuffering = KAL_TRUE;
   }
   pstFSAL->pbBuf = pbBuf;
   pstFSAL->uBufSize = uBufferSize;
}



FSAL_Status FSAL_Close(STFSAL *pstFSAL)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CacheFlush(pstFSAL);
   return FSAL_Direct_Close(pstFSAL);
}

void FSAL_Set_DRM_Permission(STFSAL *pstFSAL, kal_uint8 uDRMpermission)
{
	pstFSAL->uDRMpermission = 0x11111100 | uDRMpermission;
}

/*------ file system abstraction layer ------*/

/* The following functions are file-system dependent. */

FSAL_Status FSAL_Direct_Open(STFSAL *pstFSAL, void* szFile, FSAL_FileMode eMode)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(szFile!=NULL);

   if (FSAL_ROMFILE == eMode) {
      /* uRamFileSize should be set in advance. */
      FSAL_ASSERT(pstFSAL->uRamFileSize!=0);
#if FSAL_PLATFORM_WIN32
      pstFSAL->hFile = (FILE*)-1;
#elif FSAL_PLATFORM_KAL
      pstFSAL->hFile = -1;
#endif
      pstFSAL->pbFile = (kal_uint8*)szFile;
      return FSAL_OK;
   }
   pstFSAL->pbFile = 0;
   
#if FSAL_PLATFORM_WIN32
   {
      char* szMode;
      switch(eMode) {
      case FSAL_READ:
         szMode = "rb";
         break;
      case FSAL_WRITE:
         szMode = "wb+";
         break;
      case FSAL_APPEND:
         szMode = "ab+";
         break;
      default:
         FSAL_CHECK_ARG(KAL_FALSE);
      }
      if (0 == (pstFSAL->hFile = fopen((char*)szFile, szMode)))
         return FSAL_OPEN_ERROR;
    }
#elif FSAL_PLATFORM_KAL
   {
      kal_uint32 uFlags;
      switch (eMode & ~FSAL_NONBLOCKING) {
      case FSAL_READ:
         uFlags = FS_READ_ONLY | FS_OPEN_NO_DIR;
         break;
      case FSAL_WRITE:
         uFlags = FS_READ_WRITE | FS_CREATE_ALWAYS;
         break;
      case FSAL_APPEND:
         uFlags = FS_READ_WRITE | FS_CREATE;
         break;
      case FSAL_READ_SHARED:
         uFlags = FS_READ_ONLY | FS_OPEN_SHARED;
         break;
      default:
         FSAL_CHECK_ARG(KAL_FALSE);
      }
      if(eMode & FSAL_NONBLOCKING)
         uFlags |= FS_NONBLOCK_MODE;
      uFlags |= FS_NOBUSY_CHECK_MODE; // Disable busy check mode
      
      if( 0x11111100 != (0xFFFFFF00 & pstFSAL->uDRMpermission))
         	pstFSAL->uDRMpermission = 0x11111100 | DRM_PERMISSION_PLAY;

      if ((pstFSAL->hFile = DRM_open_file((kal_wchar*)szFile, uFlags, (kal_uint8)pstFSAL->uDRMpermission)) < 0) {
         pstFSAL->iFSErrorCode = pstFSAL->hFile;
         if (pstFSAL->iFSErrorCode==FS_DEVICE_BUSY || pstFSAL->iFSErrorCode==FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
            kal_prompt_trace(MOD_MED, "[FSAL] FS_Open Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_OPEN_ERROR;
         }
      }
   }
#endif
   return FSAL_OK;
}



kal_bool FSAL_IsRamFile(STFSAL *pstFSAL) {
   if (pstFSAL->uRamFileSize != 0) {
      return KAL_TRUE;
   } else {
      return KAL_FALSE;
   }
}



kal_uint8* FSAL_GetRamFilePointer(STFSAL *pstFSAL) {
   if (pstFSAL->uRamFileSize != 0) {
      return (kal_uint8*)pstFSAL->pbFile;
   } else {
      return NULL;  
   }
}



void FSAL_Direct_SetRamFileSize(STFSAL *pstFSAL, kal_uint32 uSize)
{
   FSAL_ASSERT_NO_RET_VAL(pstFSAL!=NULL);
   pstFSAL->uRamFileSize = uSize;
}



void FSAL_Direct_SetMaxRamFileSize(STFSAL *pstFSAL, kal_uint32 uSize)
{
#if FSAL_PLATFORM_MEMORY
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   pstFSAL->uMaxRamFileSize = uSize;
#endif
}



FSAL_Status FSAL_Direct_Close(STFSAL *pstFSAL)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   if (pstFSAL->pbFile) {
      pstFSAL->pbFile = 0;
      pstFSAL->uRamFileSize = 0;
      pstFSAL->uRamFileOffset = 0;
      pstFSAL->uDRMpermission = 0;
      return FSAL_OK;
   }
#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   fflush((FILE*)pstFSAL->hFile);
   if (fclose((FILE*)pstFSAL->hFile)!=0)
      return FSAL_CLOSE_ERROR;
#elif FSAL_PLATFORM_KAL
   {
      FSAL_CHECK_ARG(pstFSAL->hFile>=0);
      if ((pstFSAL->iFSErrorCode = DRM_close_file(pstFSAL->hFile)) < 0) {
         if (pstFSAL->iFSErrorCode==FS_DEVICE_BUSY || pstFSAL->iFSErrorCode==FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
            kal_prompt_trace(MOD_MED, "[FSAL] FS_Close Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_CLOSE_ERROR;
         }
      }
      pstFSAL->hFile = -1;
      pstFSAL->uFileSize = 0;
      pstFSAL->uFileOffset = 0;
      pstFSAL->uDRMpermission = 0;
   }
#endif
   return FSAL_OK;
}



FSAL_Status FSAL_Direct_Read(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(uSize>0);

   {
      FSAL_Status ret;      
      if ((ret = FSAL_Direct_GetFileSize(pstFSAL, &(pstFSAL->uFileSize))) != FSAL_OK)
         return ret;
   }

   /* RAM File Mode */
   if (pstFSAL->pbFile) {
      if (pstFSAL->uRamFileOffset + uSize > pstFSAL->uRamFileSize) {
         /* Calculate the available data count. */
         pstFSAL->uLastReadCount = pstFSAL->uRamFileSize - pstFSAL->uRamFileOffset;
         kal_mem_cpy(pbBuf, pstFSAL->pbFile + pstFSAL->uRamFileOffset, pstFSAL->uLastReadCount);
         pstFSAL->uRamFileOffset = pstFSAL->uRamFileSize;
         return FSAL_READ_OVER_EOF;
      } else {
         kal_mem_cpy(pbBuf, pstFSAL->pbFile + pstFSAL->uRamFileOffset, uSize);
         pstFSAL->uRamFileOffset += uSize;
         pstFSAL->uLastReadCount = uSize;
         return FSAL_OK;
      }
   }
   
#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   pstFSAL->uLastReadCount = fread(pbBuf, 1, uSize, (FILE*)pstFSAL->hFile);
   if (pstFSAL->uLastReadCount != uSize) {
      if (feof((FILE*)pstFSAL->hFile)) {
         return FSAL_READ_OVER_EOF;
      } else {
         return FSAL_READ_ERROR;
      }
   }
   {  /// Make sure the file position is located correctly.
      int pos = ftell((FILE*)pstFSAL->hFile);
      fseek((FILE*)pstFSAL->hFile, pos, SEEK_SET);
   }
#elif FSAL_PLATFORM_KAL
   FSAL_CHECK_ARG(pstFSAL->hFile>=0);
   {
      pstFSAL->iFSErrorCode = DRM_read_file(pstFSAL->hFile, (void*)pbBuf, uSize, &(pstFSAL->uLastReadCount));
      if (pstFSAL->iFSErrorCode < 0) {
         if (pstFSAL->iFSErrorCode == FS_DEVICE_BUSY || pstFSAL->iFSErrorCode == FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
            kal_prompt_trace(MOD_MED, "[FSAL] FS_Read Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_READ_ERROR;
         }
      }
      if (pstFSAL->uLastReadCount != uSize) {
         return FSAL_READ_OVER_EOF;
      }
   }
#endif
   return FSAL_OK;
}



FSAL_Status FSAL_Direct_Write(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pbBuf!=NULL);
   FSAL_CHECK_ARG(uSize>0);
#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   if (fwrite(pbBuf, uSize, 1, (FILE*)pstFSAL->hFile)!=1)
     return FSAL_WRITE_ERROR;

   {  /// Make sure the file position is located correctly.
      int pos = ftell((FILE*)pstFSAL->hFile);
      fseek((FILE*)pstFSAL->hFile, pos, SEEK_SET);
   }
#elif FSAL_PLATFORM_KAL
   FSAL_CHECK_ARG(pstFSAL->hFile>=0);
   {
      kal_uint32 uBytesWritten;
      pstFSAL->iFSErrorCode = FS_Write(pstFSAL->hFile, (void*)pbBuf, uSize, &uBytesWritten);
      if ((pstFSAL->iFSErrorCode<0) || (uBytesWritten!=uSize)) {
         if(pstFSAL->iFSErrorCode==FS_DEVICE_BUSY || pstFSAL->iFSErrorCode==FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
            kal_prompt_trace(MOD_MED, "[FSAL] FS_Write Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_WRITE_ERROR;
         }
      }
   }
#elif FSAL_PLATFORM_MEMORY
   FSAL_CHECK_ARG(pstFSAL->pbFile!=NULL);
   {
      kal_mem_cpy(pstFSAL->pbFile + pstFSAL->uRamFileOffset, pbBuf, uSize);
      pstFSAL->uRamFileOffset += uSize;
      if (pstFSAL->uRamFileOffset > pstFSAL->uRamFileSize) {
         pstFSAL->uRamFileSize = pstFSAL->uRamFileOffset;
      }
      FSAL_CHECK_ARG(pstFSAL->uRamFileOffset <= pstFSAL->uMaxRamFileSize);
   }
#endif
   return FSAL_OK;
}



FSAL_Status FSAL_Direct_Seek(STFSAL *pstFSAL, kal_uint32 uOffset)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   if (pstFSAL->pbFile) {
      pstFSAL->uRamFileOffset = uOffset;
      if (pstFSAL->uRamFileOffset > pstFSAL->uRamFileSize) {
         pstFSAL->uRamFileOffset = pstFSAL->uRamFileSize;
         return FSAL_SEEK_OVER_EOF;
      }
      return FSAL_OK;
   }

#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   if (fseek((FILE*)pstFSAL->hFile, uOffset, SEEK_SET)!=0)
      return FSAL_SEEK_ERROR;
#elif FSAL_PLATFORM_KAL
   {
      FSAL_CHECK_ARG(pstFSAL->hFile>=0);
      {
         kal_uint32 uCurOffset;
         FSAL_Status eFSALRet;
         if ((eFSALRet=FSAL_Direct_GetCurPos(pstFSAL, &uCurOffset))!=FSAL_OK)
            return eFSALRet;
         
         /* Because the performance of FS_Seek is very bad, we must avoid calling FS_Seek whenever possible. */
         if (uCurOffset == uOffset)
            return FSAL_OK;
         else {
            pstFSAL->iFSErrorCode = DRM_seek_file(pstFSAL->hFile, uOffset, FS_FILE_BEGIN);
            if ((pstFSAL->iFSErrorCode < 0) || (pstFSAL->iFSErrorCode != (kal_int32) uOffset)) {
               if (pstFSAL->iFSErrorCode==FS_DEVICE_BUSY || pstFSAL->iFSErrorCode==FS_LOCK_MUTEX_FAIL)
                  return FSAL_DEVICE_BUSY;
               else if(pstFSAL->iFSErrorCode==FS_INVALID_FILE_POS){
                  return FSAL_SEEK_OVER_EOF;
               }else{
                  kal_prompt_trace(MOD_MED, "[FSAL] FS_Seek Error:%d\n", pstFSAL->iFSErrorCode);
                  return FSAL_SEEK_ERROR;
               }
            }
         }
      }
   }
#endif
   return FSAL_OK;
}



FSAL_Status FSAL_Direct_GetCurPos(STFSAL *pstFSAL, kal_uint32* puPosition)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puPosition!=NULL);
   if (pstFSAL->pbFile) {
      *puPosition = pstFSAL->uRamFileOffset;
      return FSAL_OK;
   }
#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   *puPosition = ftell((FILE*)pstFSAL->hFile);
#elif FSAL_PLATFORM_KAL
   {
      FSAL_CHECK_ARG(pstFSAL->hFile>=0);
      //pstFSAL->iFSErrorCode = FS_GetFilePosition(pstFSAL->hFile, puPosition);
      pstFSAL->iFSErrorCode = DRM_file_pos(pstFSAL->hFile, puPosition);
      if (pstFSAL->iFSErrorCode < 0) {
         if (pstFSAL->iFSErrorCode == FS_DEVICE_BUSY || pstFSAL->iFSErrorCode == FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
            kal_prompt_trace(MOD_MED, "[FSAL] FS_GetFilePosition Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_FATAL_ERROR;
         }
      }
   }
#endif
   return FSAL_OK;
}



FSAL_Status FSAL_Direct_GetFileSize(STFSAL *pstFSAL, kal_uint32 *puFileSize)
{
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puFileSize!=NULL);
   if ( pstFSAL->pbFile ) {
      *puFileSize = pstFSAL->uRamFileSize;
      return FSAL_OK;
   }
#if FSAL_PLATFORM_WIN32
   FSAL_CHECK_ARG(pstFSAL->hFile!=NULL);
   {
      kal_uint32 uCurPos;
      uCurPos = ftell((FILE*)pstFSAL->hFile);
      if (fseek((FILE*)pstFSAL->hFile, 0, SEEK_END)!=0)
        return FSAL_SEEK_ERROR;
      *puFileSize = ftell((FILE*)pstFSAL->hFile);
      if (fseek((FILE*)pstFSAL->hFile, uCurPos, SEEK_SET)!=0)
        return FSAL_SEEK_ERROR;
   }
#elif FSAL_PLATFORM_KAL
   {
      FSAL_CHECK_ARG(pstFSAL->hFile >= 0);
      pstFSAL->iFSErrorCode = DRM_file_size(pstFSAL->hFile, puFileSize);
      if (pstFSAL->iFSErrorCode < 0) {
         if (pstFSAL->iFSErrorCode == FS_DEVICE_BUSY || pstFSAL->iFSErrorCode == FS_LOCK_MUTEX_FAIL)
            return FSAL_DEVICE_BUSY;
         else {
         	kal_prompt_trace(MOD_MED, "[FSAL] FS_GetFileSize Error:%d\n", pstFSAL->iFSErrorCode);
            return FSAL_FATAL_ERROR;
         }
      }
   }
#endif
   return FSAL_OK;
}



/* Return the last file system error for error handling */
int FSAL_GetLastError(STFSAL *pstFSAL)
{
   FSAL_CHECK_ARG(pstFSAL != NULL);

#if FSAL_PLATFORM_WIN32
   return FSAL_FATAL_ERROR;
#elif FSAL_PLATFORM_KAL
   return pstFSAL->iFSErrorCode;
#elif FSAL_PLATFORM_MEMORY
   return FSAL_FATAL_ERROR;
#endif
}



int FSAL_GetLastReadCount(STFSAL *pstFSAL) {
   FSAL_CHECK_ARG(pstFSAL!=NULL);
   return (int) pstFSAL->uLastReadCount;
}



/* Sample Code for FSAL Unit Test */
/*
void _fsal_unit_test(void) {
#define FSAL_BUFFER_SIZE 3
#define READ_BUFFER_SIZE 64
#define ITERATION_COUNT  8
#define RAM_FILE_SIZE    43
   STFSAL test_file;
   char fsal_buffer[FSAL_BUFFER_SIZE];
   char read_buffer[READ_BUFFER_SIZE];
   int last_read_count, exp_read_count;
   unsigned int cur_pos, exp_cur_pos, file_size, i;
   char ram_file[RAM_FILE_SIZE]      = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFG";
   char write_content[RAM_FILE_SIZE] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFG";
   int bytes_to_read[ITERATION_COUNT]  = {2, 6, 7, 9, 0, 6, 13, 6};
   int bytes_to_write[ITERATION_COUNT] = {9, 1, 2, 5, 3, 6, 12, 5};
   FSAL_Status ret;
   char *ptr;
#if 0
   {
      int pos;
      FILE *fp = fopen("D:\\test4.txt", "wb+");
      if (fwrite(ram_file, 1, 9, fp) != 9)
         printf("error 1\n");
      pos = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      pos = ftell(fp);

      if (fread(read_buffer, 1, 8, fp) != 8)
         printf("error 2\n");
      pos = ftell(fp);
      fseek(fp, 8, SEEK_SET);
      pos = ftell(fp);
      fflush(fp);
      pos = ftell(fp);
      if (fwrite(ram_file+9, 1, 7, fp) != 7)
         printf("error 3\n");
      pos = ftell(fp);
      fclose(fp);
      exit(0);
   }
#endif
   /// write testing
   exp_cur_pos = 0;
   ptr = ram_file;
   FSAL_Open(&test_file, "D:\\test2.txt", FSAL_WRITE);
   FSAL_SetBuffer(&test_file, FSAL_BUFFER_SIZE, fsal_buffer);
   for (i = 0; i<ITERATION_COUNT; i++) {
      if ((ret = FSAL_Write(&test_file, ptr, bytes_to_write[i])) != FSAL_OK)
         assert(0);
      if ((ret = FSAL_Seek(&test_file, exp_cur_pos)) != FSAL_OK)
         assert(0);
      if ((ret = FSAL_Read(&test_file, read_buffer, bytes_to_write[i])) != FSAL_OK)
         assert(0);

      assert(strncmp(read_buffer, ptr, bytes_to_write[i]) == 0);
      exp_cur_pos += bytes_to_write[i];
      ptr += bytes_to_write[i];

      FSAL_GetCurPos(&test_file, &cur_pos);
      assert(cur_pos == exp_cur_pos);
   }
   FSAL_Close(&test_file);

   /// read testing
   exp_cur_pos = 0;
   FSAL_Open(&test_file, "D:\\test1.txt", FSAL_READ);
   FSAL_SetBuffer(&test_file, FSAL_BUFFER_SIZE, fsal_buffer);
   for (i = 0; i<ITERATION_COUNT; i++) {
      ret = FSAL_Read(&test_file, read_buffer, bytes_to_read[i]);
      if (ret != FSAL_OK && ret != FSAL_READ_OVER_EOF) {
         assert(0);
      }         
      exp_read_count = bytes_to_read[i];
      exp_cur_pos += bytes_to_read[i];
      FSAL_GetFileSize(&test_file, &file_size);
      if (exp_cur_pos >= file_size) {
         exp_read_count = file_size - exp_cur_pos + bytes_to_read[i];
         exp_cur_pos = file_size;
      }
      FSAL_GetCurPos(&test_file, &cur_pos);
      assert(cur_pos == exp_cur_pos);
      last_read_count = FSAL_GetLastReadCount(&test_file);
      assert(last_read_count == exp_read_count);
      assert(0 == strncmp(ram_file + cur_pos - last_read_count, read_buffer, last_read_count));
   }

   /// RAM file read testing
   exp_cur_pos = 0;
   FSAL_Direct_SetRamFileSize(&test_file, RAM_FILE_SIZE);
   FSAL_Open(&test_file, ram_file, FSAL_ROMFILE);
   for (i = 0; i<ITERATION_COUNT; i++) {
      ret = FSAL_Read(&test_file, read_buffer, bytes_to_read[i]);
      if (ret != FSAL_OK && ret != FSAL_READ_OVER_EOF) {
         assert(0);
      }
      exp_read_count = bytes_to_read[i];
      exp_cur_pos += bytes_to_read[i];
      FSAL_GetFileSize(&test_file, &file_size);
      if (exp_cur_pos >= file_size) {
         exp_read_count = file_size - exp_cur_pos + bytes_to_read[i];
         exp_cur_pos = file_size;
      }
      FSAL_GetCurPos(&test_file, &cur_pos);
      assert(cur_pos == exp_cur_pos);
      last_read_count = FSAL_GetLastReadCount(&test_file);
      assert(last_read_count == exp_read_count);
      assert(0 == strncmp(ram_file + cur_pos - last_read_count, read_buffer, last_read_count));
   }
   FSAL_Close(&test_file);
}
*/
