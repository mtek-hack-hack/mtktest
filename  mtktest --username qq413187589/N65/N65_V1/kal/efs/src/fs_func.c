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
 *	fs_func.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file wrap the file system
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
 *============================================================================
 ****************************************************************************/
#include <stdio.h>
#include "kal_release.h"
#include "app_buff_alloc.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "fs_kal.h"
#include "fs_type.h"
#include "fs_internal.h"
#include "fat_fs.h"

#if defined(FS_EVALUATE) && defined(DEBUG_KAL)
#define __FS_DEBUG__
#endif

#ifdef DEBUG_KAL
extern void kal_check_stack(void);
#endif /* DEBUG_KAL */
extern kal_bool INT_QueryExceptionStatus(void);

/* ------------------------------------------------------------------------------- */
int FS_Open(const WCHAR * FileName, UINT Flag)
{
   int Result = RTF_NO_ERROR;
   WCHAR * FileName2;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Open=> FileName: %s, Flag: 0x%x", (BYTE *)FileName, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_OPEN, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   FileName2 = TruncateWideWhiteSpacesAndPeriods(FileName);
   Result = RTFOpen(FileName2, Flag);

#ifdef __FS_TRACE_SUPPORT__
   if((g_TraceFlag & FS_TRACE_API) && Result > RTF_NO_ERROR)
   {
      kal_sprintf(TraceTmpBuf, "FS_Open<= Return FileHandle: %x", Result);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_OPEN, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_OpenHint(const WCHAR * FileName, UINT Flag, FS_FileLocationHint * DSR_Hint)
{
   int Result = RTF_NO_ERROR;
   WCHAR * FileName2;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_OpenHint=> FileName: %s", (BYTE *)FileName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_OPENHINT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   FileName2 = TruncateWideWhiteSpacesAndPeriods(FileName);
   Result = RTFOpenHint(FileName2, Flag, (RTFDirLocation *)DSR_Hint);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Close(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Close=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CLOSE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFClose(FileHandle);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CloseAll(void)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CloseAll");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CLOSEALL, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (INT_QueryExceptionStatus() == KAL_FALSE)
   {
      RTFSYSErrorExit("It's not allowed to be used under normal state!", (UINT)kal_get_current_thread_ID());
   }

   Result = RTFCloseAll();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Read(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      RTFile * tmp_f;
      tmp_f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
      kal_sprintf(TraceTmpBuf, "FS_Read=> DataPtr: 0x%x, Length: %d", (UINT)DataPtr, Length);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_READ, tmp_f, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFRead(FileHandle, DataPtr, Length, Read);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Write(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      RTFile * tmp_f;
      tmp_f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
      kal_sprintf(TraceTmpBuf, "FS_Write=> DataPtr: 0x%x, Length: %d", (UINT)DataPtr, Length);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_WRITE, tmp_f, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFWrite(FileHandle, DataPtr, Length, Written);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides user to specify several check points of file to speedup
      the seek function. FS_Seek will start to seek from these places.
PARAMETER
      FileHandle: The file handle to be seeked
      HintNum:    Number of hint
      Hint:       Pointer to user defined hint
RETURN
      Success:    The number of hint that is successfully set
      Error:      RTF_ACCESS_DENIED
NOTE
      1. User should specify the hint in "bytes".
      2. This function only provides hint. One should not call this to extend file.
         i.e. Hint in bytes cannot be larger than the file size.
      3. User should allocate and free the memory by himself
      4. User should sort the hint by himself (small to big), or hint setting will
         be stopped by the number not in sequence
------------------------------------------------------------------------------- */
int FS_SetSeekHint(FS_HANDLE FileHandle, UINT HintNum, FS_FileLocationHint * Hint)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;
   UINT Tmp1, Tmp2;
   UINT Ofs, Ofs2;
   UINT FileSize, ClusterSize, Index;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      RTFile * tmp_f;
      tmp_f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
      kal_sprintf(TraceTmpBuf, "FS_SetSeekHint=> FileHandle: %x, HintNum: %d", FileHandle, HintNum);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SETSEEKHINT, tmp_f, (BYTE *)TraceTmpBuf);
   }
#endif

   if((RTFLock == NULL) || (Hint == NULL))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
#endif
      return RTF_ACCESS_DENIED;
   }

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);

         FileSize = f->DirEntry.Dir.FileSize;
         ClusterSize = f->Drive->ClusterSize;
         Tmp2 = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

         while(1)
         {
            Index = Hint[f->HintNum].Index;
            if(f->HintNum == HintNum)
               break;
            if(Index > FileSize)
               break;
            if(f->HintNum)
            {
               if(Index < Hint[f->HintNum-1].Index)
                  break;
            }
            Ofs = (f->HintNum) ? (Index - Hint[f->HintNum-1].Index) : (Index);
            Ofs2 = 0;
            f->Seek_Hint = (RTFDirLocation *)Hint;
            while(Ofs >= ClusterSize)
            {
               if(Tmp2 < 2L)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FAT_ALLOC_ERROR, NULL, NULL);
#endif
                  XRAISE(RTF_FAT_ALLOC_ERROR);
               }
               if(Tmp2 >= RTF_CLUSTER_CHAIN_END)
                  break; //incorrect file size
               Ofs -= ClusterSize;
               Ofs2 += ClusterSize;
               Tmp1 = Tmp2;
               Tmp2 = GetClusterValue(f->Drive, Tmp1);
            }
            if(Tmp2 >= RTF_CLUSTER_CHAIN_END)
               break;

            Hint[f->HintNum].Index = (f->HintNum) ?
                                     (Ofs2 + f->Seek_Hint[f->HintNum-1].Index) : Ofs2;
            Hint[f->HintNum].Cluster = Tmp2;

            f->HintNum++;
         }
         Result = f->HintNum;
         break;
      default:
         if (f != NULL)
         {
            f->HintNum = 0;
            f->Seek_Hint = 0;
         }
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f != NULL) UnlockDevice(f->Dev);
         SafeUnlock(MT_LOCK_EXT);
         break;
   XEND_API

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      RTFile * tmp_f;
      tmp_f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
      kal_sprintf(TraceTmpBuf, "FS_Seek=> FileHandle: %x, Offset: %d, Whence: %d", FileHandle, Offset, Whence);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SEEK, tmp_f, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFSeek(FileHandle, Offset, Whence);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Commit(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      RTFile * tmp_f;
      tmp_f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
      kal_sprintf(TraceTmpBuf, "FS_Commit=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_COMMIT, tmp_f, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFCommit(FileHandle);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function will do the file handle garbage collection
PARAMETER
      TaskId:  The magic number of the task
RETURN
      Success: RTF_NO_ERROR
------------------------------------------------------------------------------- */
int FS_ReleaseFH(void * TaskId)
{

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      if(TaskId)
         kal_sprintf(TraceTmpBuf, "FS_ReleaseFH=> TaskId: 0x%x", (UINT)TaskId);
      else
         kal_sprintf(TraceTmpBuf, "FS_ReleaseFH=> TaskId: All");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_RELEASEFH, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   ReleaseFH(TaskId);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to abort the action on the
      specified file handle
PARAMETER
      ActionHandle: the specified file handle
RETURN
      Success:  RTF_NO_ERROR
      Fail:     RTF_PARAM_ERROR
------------------------------------------------------------------------------- */
int FS_Abort(UINT ActionHandle)
{
   RTFile * f;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Abort=> FileHandle: %x", ActionHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_ABORT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   //do not lock here
   if(ActionHandle == FS_ABORT_CHECK_DRIVE)
   {
#ifdef __FS_CHECKDRIVE_SUPPORT__
      g_CheckDrive = KAL_FALSE;
#else
      return RTF_PARAM_ERROR;
#endif
   }
   else if(ActionHandle == FS_ABORT_XDELETE)
   {
      g_Xdelete = KAL_FALSE;
   }
   else
   {
      f = gFS_Data.FileTable + (ActionHandle&((1 << (4*sizeof(int))) - 1));
      f->Valid = MT_ENUM_FH_ABORTED;
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function parse the file handle to a index (start from 0) to file table
PARAMETER
      FileHandle: the specified file handle
RETURN
      >=0    : the index to file table
      Error : RTF_INVALID_FILE_HANDLE
------------------------------------------------------------------------------- */
int FS_ParseFH(FS_HANDLE FileHandle)
{
   UINT U = FileHandle >> (4*sizeof(int));
   UINT i = FileHandle & ((1 << (4*sizeof(int))) - 1);
   RTFile * f;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_ParseFH=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_PARSEFH, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   f = gFS_Data.FileTable + i;
   if (i >= FS_MAX_FILES)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2, __LINE__, RTF_INVALID_FILE_HANDLE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Lock == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Unique != U)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Dev == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_INVALID_FILE_HANDLE;
   }

   return i;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetFileInfo=> FileHandle: %x, FileInfo: 0x%x", FileHandle, (UINT)FileInfo);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETFILEINFO, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFGetFileInfo(FileHandle, (RTFFileInfo *)FileInfo);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFileSize(FS_HANDLE FileHandle, UINT * Size)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetFileSize=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETFILESIZE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFGetFileSize(FileHandle, Size);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFilePosition(FS_HANDLE FileHandle, UINT * Position)
{
   RTFile * f;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetFilePosition=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETFILEPOSITION, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);
   f = gFS_Data.FileTable + (FileHandle & ((1 << (4*sizeof(int))) - 1));
   *Position = f->FilePointer;
   if( f->SpecialKind == FileMapFile )
   {
      *Position -= f->DirEntry.ShortPos.Index; /* BIAS */
   }
   SafeUnlock(MT_LOCK_RTF);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_SetFileTime=> FileHandle: %x, Time: 0x%x", FileHandle, (UINT)Time);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SETFILETIME, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFSetFileTime(FileHandle, (RTFDOSDateTime *)Time);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetAttributes(const WCHAR * FileName)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetAttributes=> FileName: %s", (BYTE *)FileName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETATTRIBUTES, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFGetAttributes(FileName);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_SetAttributes(const WCHAR * FileName, BYTE Attributes)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_SetAttributes=> FileName: %s, Attributes: 0x%x", (BYTE *)FileName, Attributes);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SETATTRIBUTES, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFSetAttributes(FileName, Attributes);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Delete(const WCHAR * FileName)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Delete=> FileName: %s", (BYTE *)FileName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_DELETE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFDelete(FileName);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides merge facility for MMTF
PARAMETER
      FileName1:  File being extended
      FileName2:  Append to FileName1, and FileName2 will be deleted
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILENAME
                  RTF_FILE_NOT_FOUND
                  RTF_ACCESS_DENIED
                  RTF_DRIVE_NOT_FOUND
NOTE
      This function will
      (1) Check file size and cross link
      (2) Append File2 to File1 without caring the last cluster of
          File1 is not cluster alinged. One calling this API should
          be aware that RTF_COMMITTED is the default setting of this call.
------------------------------------------------------------------------------- */
int FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2)
{
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;
   RTFCluster lastC_Pos, lastC_Value, CrossPilot;
   UINT ClusterCount = 1;
   int volatile Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_PseudoMerge=> FileName1: %s, FileName2: %s", (BYTE *)FileName1, (BYTE *)FileName2);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_PSEUDOMERGE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (RTFLock == NULL)
      RTFInit();

   XTRY
      case XCODE:
         f1 = ParseFileName((char *)FileName1);
         RTFSYSFreeMutex(RTFLock);
         f2 = ParseFileName((char *)FileName2);

         if(f1->Drive != f2->Drive)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         /* General check */
         if(f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_WRITE_PROTECTION, NULL, NULL);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }

         if ((f1->SpecialKind != NormalFile) || (f2->SpecialKind != NormalFile))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName1);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f2, SEARCH_FILES, (char *)FileName2, NULL)) //merge has done before
            goto MergeReturn;

         if (!SearchFile(f1, SEARCH_FILES, (char *)FileName1, NULL)) //search to fill data
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName1);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         CheckNotOpen(f1);
         CheckNotOpen(f2);

         if ((f1->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME)) ||
             (f2->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME)))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName1);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
         }

          f1->Flags |= RTF_COMMITTED;
          f2->Flags |= RTF_COMMITTED;

         /* Check file2 size */
         lastC_Pos = FIRST_FILE_CLUSTER(f2->DirEntry.Dir);
         CrossPilot = lastC_Pos;
         lastC_Value = GetClusterValue(f2->Drive, lastC_Pos);
         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FAT_ALLOC_ERROR, NULL, NULL);
#endif
               XRAISE(RTF_FAT_ALLOC_ERROR);
            }
            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f2->Drive, lastC_Pos);
            ClusterCount++;
         }

         /* If not correct, start to modify file2 size */
         if((f2->DirEntry.Dir.FileSize <= f2->Drive->ClusterSize*(ClusterCount-1)) ||
            (f2->DirEntry.Dir.FileSize > f2->Drive->ClusterSize*ClusterCount))
         {
            f2->DirEntry.Dir.FileSize = f2->Drive->ClusterSize*ClusterCount;
            UpdateDirEntry(f2);
         }

         /* Check file1 size */
         ClusterCount = 1;
         lastC_Pos = FIRST_FILE_CLUSTER(f1->DirEntry.Dir);
         lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FAT_ALLOC_ERROR, NULL, NULL);
#endif
               XRAISE(RTF_FAT_ALLOC_ERROR);
            }
            if(lastC_Pos == CrossPilot) /* Cross link */
            {
               DeleteDirEntry(f2); // will commit itself if with RTF_COMMITTED
               goto MergeReturn;
            }
            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
            ClusterCount++;
         }

         /* If not correct, start to modify file1 size */
         if((f1->DirEntry.Dir.FileSize <= f1->Drive->ClusterSize*(ClusterCount-1)) ||
            (f1->DirEntry.Dir.FileSize > f1->Drive->ClusterSize*ClusterCount))
         {
            f1->DirEntry.Dir.FileSize = f1->Drive->ClusterSize*ClusterCount;
            UpdateDirEntry(f1);
         }

         /* Modify file size of File1 */
         if(f1->Drive->ClusterSize > 0)
            f1->DirEntry.Dir.FileSize =
               ((f1->DirEntry.Dir.FileSize + f1->Drive->ClusterSize - 1) / f1->Drive->ClusterSize)
               *(f1->Drive->ClusterSize) + f2->DirEntry.Dir.FileSize;
         else
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_DRIVE_NOT_FOUND, NULL, NULL);
#endif
            XRAISE(RTF_DRIVE_NOT_FOUND);
         }
         UpdateDirEntry(f1);

         lastC_Pos = FIRST_FILE_CLUSTER(f1->DirEntry.Dir);
         lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FAT_ALLOC_ERROR, NULL, NULL);
#endif
               XRAISE(RTF_FAT_ALLOC_ERROR);
            }
            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
         }

         /* Start to delete File2 DIR entry */
         DeleteDirEntry(f2);

         /* Connect two chains */
         SetClusterValue(f1->Drive, lastC_Pos, FIRST_FILE_CLUSTER(f2->DirEntry.Dir));
         CommitBuffer(f1->Dev);

MergeReturn:
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f2 != NULL) /* imply f1 != NULL, see above */
         {
            FreeFTSlotAndDevice(f2);
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            FreeFTSlotAndDevice(f1);
         }
         else if (f1 != NULL)
         {
            FreeFTSlotAndDevice(f1);
         }
         break;
   XEND_API

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides sanity check function for the specified file
PARAMETER
      FileName:  File to be checked
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_CHECKDISK_RETRY (sanity check fail)
                  Other error code caused by user error (from FS_Open fail)
NOTE
      This function will adjust the allocated clusters to fit the file size
      automatically if needed
------------------------------------------------------------------------------- */
int FS_CheckFile(const WCHAR * FileName)
{
   RTFile * volatile f = NULL;
   RTFCluster lastC_Pos, lastC_Value;
   UINT ClusterCount = 0, ClusterCount2;
   int volatile Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CheckFile=> FileName: %s", (BYTE *)FileName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CHECKFILE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }

         if(f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL)) //search to fill data
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         CheckNotOpen(f);

         f->Flags |= RTF_COMMITTED;

         /* Count the cluster chain length , base on Dir.FileSize , ROUND-UP */
         ClusterCount2 = (f->DirEntry.Dir.FileSize + f->Drive->ClusterSize - 1) / f->Drive->ClusterSize;

         lastC_Pos = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         if(lastC_Pos != 0)
         {
            lastC_Value = GetClusterValue(f->Drive, lastC_Pos);
            while(lastC_Value < RTF_CLUSTER_CHAIN_END)
            {
               if(lastC_Value < 2L) //The Cluster Chain BROKEN
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_CHECKDISK_RETRY, NULL, NULL);
#endif
                  XRAISE(RTF_CHECKDISK_RETRY);
               }

               if ((ClusterCount == ClusterCount2)) //The Chain should END , but not
               {
                  if( ClusterCount2 > 0 )
                  {
                     SetClusterValue(f->Drive, lastC_Pos, 0x0FFFFFFFL); //RTF_CHAIN_END_MARK
                  }
                  else
                  {
                     SetClusterValue(f->Drive, lastC_Pos, 0);
                     UpdateClusterWatermark(f->Drive, lastC_Pos, 1);
                     SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
                     UpdateDirEntry(f);
                  }
               }
               else if ( ClusterCount > ClusterCount2 ) //The Chain has redundancy, Clear it
               {
                  SetClusterValue(f->Drive, lastC_Pos, 0);
                  UpdateClusterWatermark(f->Drive, lastC_Pos, 1);
               }

               /* Next iteration */
               lastC_Pos = lastC_Value;
               lastC_Value = GetClusterValue(f->Drive, lastC_Pos);
               ClusterCount++;
            }

            /* The Last Cluster, CHAIN_END_MARK */
            if( ++ClusterCount > ClusterCount2 ) //Clear Original CHAIN_END_MARK
            {
               SetClusterValue(f->Drive, lastC_Pos, 0);
               UpdateClusterWatermark(f->Drive, lastC_Pos, 1);
            }
         } //END if ( File's First Cluster != 0 )

         /* If not correct, start to modify file size */
         if (ClusterCount < ClusterCount2) //Dir.FileSize > actual allocated FAT Chain Capability
         {
            f->DirEntry.Dir.FileSize = f->Drive->ClusterSize*ClusterCount;
            UpdateDirEntry(f);
         }

         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f != NULL) FreeFTSlotAndDevice(f);
         break;
   XEND_API

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetCurrentDir(WCHAR * DirName, UINT MaxLength)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetCurrentDir=> DirName: %s, MaxLength: %d", (BYTE *)DirName, MaxLength);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETCURRENTDIR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFGetCurrentDir(DirName, MaxLength);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_SetCurrentDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_SetCurrentDir=> DirName: %s", (BYTE *)DirName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SETCURRENTDIR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFSetCurrentDir(DirName);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CreateDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;
   WCHAR * DirName2;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CreateDir=> DirName: %s", (BYTE *)DirName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CREATEDIR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   DirName2 = TruncateWideWhiteSpacesAndPeriods(DirName);
   Result = RTFCreateDir(DirName2);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_RemoveDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_RemoveDir=> DirName: %s", (BYTE *)DirName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_REMOVEDIR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFRemoveDir(DirName);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Extend(FS_HANDLE FileHandle, UINT Length)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Extend=> FileHandle: %x, Length: %d", FileHandle, Length);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_EXTEND, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFExtend(FileHandle, Length);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Truncate(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Truncate=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_TRUNCATE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFTruncate(FileHandle);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_MakeFileName(FS_HANDLE FileHandle, UINT Flag, WCHAR * FileName, UINT MaxLength)
{
   int Result = RTF_NO_ERROR;
   RTFDirLocation Pos;
   RTFile * f;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_MakeFileName=> FileHande: %x Flag: 0x%x", FileHandle, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_MAKEFILENAME, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (MaxLength < ((8+3+1+1) * sizeof(WCHAR)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "MaxLength: %d", MaxLength);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   Result = FS_ParseFH(FileHandle);
   if (Result < RTF_NO_ERROR)
      return Result;

   f = gFS_Data.FileTable + Result;

   if (Flag & FS_LONGNAME_ATTR)
      Pos = f->DirEntry.LongPos;
   else
      Pos = f->DirEntry.ShortPos;

   if (Pos.Cluster == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, f, NULL);
#endif
      return RTF_PARAM_ERROR;
   }

   Result = MTMakeFileName(f->Drive, &Pos, FileName, MaxLength);

#ifdef __FS_TRACE_SUPPORT__
   if (Result < RTF_NO_ERROR)
   {
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, f, NULL);
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Rename(const WCHAR * FileName, const WCHAR * NewName)
{
   int Result = RTF_NO_ERROR;
   WCHAR * NewName2;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Rename=> FileName: %s, NewName: %s", (BYTE *)FileName, (BYTE *)NewName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_RENAME, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   NewName2 = TruncateWideWhiteSpacesAndPeriods(NewName);
   Result = RTFRename(FileName, NewName2);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}


/* ------------------------------------------------------------------------------- */
int FS_FindFirst(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindFirst=> Pattern: %s, AttrMask: 0x%x, MaxLength: %d", (BYTE *)NamePattern, AttrMask, MaxLength);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDFIRST, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFFindFirstEx(NamePattern, Attr, AttrMask, (RTFDOSDirEntry *)FileInfo, FileName, MaxLength);

#ifdef __FS_TRACE_SUPPORT__
   if((g_TraceFlag & FS_TRACE_API) && Result > RTF_NO_ERROR)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindFirst<= Return FileHandle: %x", Result);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDFIRST, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindNext=> FileHandle: %x, MaxLength: %d", FileHandle, MaxLength);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDNEXT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFFindNextEx(FileHandle, (RTFDOSDirEntry *)FileInfo, FileName, MaxLength);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to find Nth matching file
      and multi-patterns are supported
PARAMETER
      NamePattern:   Find Pattern (Must have drive name)
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      Attr:          The attributes must have
      AttrMask:      The attributes must not have
      FileInfo:      File information
      FileName:      File name
      MaxLength:     The length of the file name buffer
      EntryIndex:    Find Nth index
RETURN
      Success:  RTF_NO_ERROR
      Error:    RTF_PARAM_ERROR
                RTF_FILE_NOT_FOUND
------------------------------------------------------------------------------- */
int FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray,
                  UINT PatternNum, BYTE ArrayMask, BYTE Attr, BYTE AttrMask,
                  FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength,
                  UINT EntryIndex, UINT Flag)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindFirstN=> Pattern: %s, PatternNum: %d, MaxLength: %d, EntryIndex: %d, Flag: 0x%x", (BYTE *)NamePattern, PatternNum, MaxLength, EntryIndex, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDFIRSTN, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)NamePattern);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))
         {
            if(f->DirEntry.DirCluster == 0)
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (FileInfo)
                  * (RTFDOSDirEntry *)FileInfo = f->DirEntry.Dir;
               setASCII(FileName, 0, '\\');
               setASCII(FileName, 1, 0);
               AttrMask = Attr = 0xFF;
            }
            else
               SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
         }

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if(f)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   if ((Result >= RTF_NO_ERROR) && (A[0] != 0xFF)  && (A[1] != 0xFF))
   {
      UINT Count = 0, reval = RTF_NO_ERROR;

      while((reval = FS_FindNextN(Result, PatternArray, PatternNum, ArrayMask, FileInfo, FileName, MaxLength, Flag)) == RTF_NO_ERROR)
      {
         if(Count == EntryIndex)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & FS_TRACE_API)
            {
               kal_sprintf(TraceTmpBuf, "FS_FindFirstN<= Return FileHandle: %x", Result);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDFIRSTN, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            return Result;
         }
         Count++;
      }
      RTFFindClose(Result);
      return reval;
   }
   else
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)NamePattern);
#endif
      return Result;
   }
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to find next matching file
      and multi-patterns are supported
PARAMETER
      Handle:        The file handle record the find position
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      FileInfo:      File information
      FileName:      File name
      MaxLength:     The length of the file name buffer
RETURN
      Success:       RTF_NO_ERROR
      Error:         MT_ABORTED_ERROR
                     RTF_INVALID_FILE_HANDLE
                     RTF_NO_MORE_FILES
------------------------------------------------------------------------------- */
int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum,
                 BYTE ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName,
                 UINT MaxLength, UINT Flag)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   UINT i;
   WCHAR * volatile FindName = NULL;
   UINT FindLength = 0;
   int LastIsLFN = 0;
   BYTE NTReserved = 0;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindNextN=> FileHandle: %x, PatternNum: %d, MaxLength: %d, Flag: 0x%x", Handle, PatternNum, MaxLength, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDNEXTN, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         if(f->Valid == MT_ENUM_FH_ABORTED)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_ABORTED_ERROR, f, NULL);
#endif
            XRAISE(MT_ABORTED_ERROR);
         }

         if(f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILE_HANDLE, f, NULL);
#endif
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILE_HANDLE, f, NULL);
#endif
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if((A[0] == 0xFF) && (A[1] == 0xFF))
         {
/*#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
            XRAISE(RTF_NO_MORE_FILES);
         }

         if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if (D == NULL)
            {
/*#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
               XRAISE(RTF_NO_MORE_FILES);
            }

            Kind = EntryType(D);

            LastIsLFN--;

            if(Kind == NeverUsed)
            {
/*#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
               XRAISE(RTF_NO_MORE_FILES);
            }
            else if(Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if(FindName == NULL)
               {
                  FindName = get_ctrl_buffer(MT_MAX_WIDE_NAME);
                  if(FindName == NULL)
                  {
#ifdef __FS_TRACE_SUPPORT__
                     if(g_TraceFlag & MT_TRACE_ERROR)
                        MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
                     XRAISE(MT_FAIL_GET_MEM);
                  }
                  memset(FindName, 0, MT_MAX_WIDE_NAME);
                  FindLength = MT_MAX_WIDE_NAME;
               }
               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));
                  if(Limit > ( ((char *)FindName) + FindLength - 1))
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FindName + --LFNIndex * 26, LD);
               LastIsLFN = 2;
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               int j;
               if(D->FileName[0] == 0x2E)
               {
                  if((D->FileName[1] != 0x20) && (D->FileName[1] != 0x2E))
                     goto ContinueFindNextN_3;
                  for (j = 2; j <= 7; j++)
                  {
                     if(D->FileName[j] != 0x20)
                     {
                        goto ContinueFindNextN_3;
                     }
                  }
                  goto ContinueFindNextN_2;
                  /* dot, dot-dot */
               }
ContinueFindNextN_3:
               if(FileInfo)
                  * (RTFDOSDirEntry *)FileInfo = *D;

               FileInfo->NTReserved = MT_ENUM_FIND_NONE;
               if((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  if(PatternNum > 0)
                  {
                     if(D->Attributes & ArrayMask)
                     {
                        if(FileNamesMatch((WCHAR *)NamePattern, FindName))
                        {
                           if(Flag != FS_FIND_LFN_TRUNC)
                           {
                              if(kal_wstrlen(FindName) >= MaxLength/2)
                              {
                                 LastIsLFN--;
                                 goto ContinueFindNextN_1;
                              }
                              else
                              {
                                 for(i = 0 ; i < (MaxLength/2 - 1); i++)
                                 {
                                    if(FindName[i] == NULL)
                                       break;
                                    FileName[i] = FindName[i];
                                 }
                                 FileName[i] = 0x0000;
                              }
                           }
                           FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                           goto SkipFindNextN;
                        }
                        goto ContinueFindNextN_1;
                     }

                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                        {
#ifdef __FS_TRACE_SUPPORT__
                           if(g_TraceFlag & MT_TRACE_ERROR)
                              MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, NULL);
#endif
                           XRAISE(RTF_PARAM_ERROR);
                        }

                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FindName))
                        {
                           if(Flag != FS_FIND_LFN_TRUNC)
                           {
                              if(kal_wstrlen(FindName) >= MaxLength/2)
                              {
                                 LastIsLFN--;
                                 goto ContinueFindNextN_1;
                              }
                              else
                              {
                                 for(i = 0 ; i < (MaxLength/2 - 1); i++)
                                 {
                                    if(FindName[i] == NULL)
                                       break;
                                    FileName[i] = FindName[i];
                                 }
                                 FileName[i] = 0x0000;
                              }
                           }
                           FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                           goto SkipFindNextN;
                        }
                     }
                  }
                  else if(FileNamesMatch((WCHAR *)NamePattern, FindName))
                  {
                     if(Flag != FS_FIND_LFN_TRUNC)
                     {
                        if(kal_wstrlen(FindName) >= MaxLength/2)
                        {
                           LastIsLFN--;
                           goto ContinueFindNextN_1;
                        }
                        else
                        {
                           for(i = 0 ; i < (MaxLength/2 - 1); i++)
                           {
                              if(FindName[i] == NULL)
                                 break;
                              FileName[i] = FindName[i];
                           }
                           FileName[i] = 0x0000;
                        }
                     }
                     FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                     goto SkipFindNextN;
                  }
               }
ContinueFindNextN_1:
               if((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR) &&
                  (LastIsLFN != 1)) //LFN match fail, don't have to match SFN
               {
                  UINT i;

                  FileNameExtendToWCHAR((char *)FileName);

                  if(PatternNum > 0)
                  {
                     if(D->Attributes & ArrayMask)
                     {
                        if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                        {
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
                           if (FileInfo->FileName[0] == 0x05)
                              FileInfo->FileName[0] = 0xE5;
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
                           FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                           NTReserved = D->NTReserved;
                           break;
                        }
                        goto ContinueFindNextN_2;
                     }

                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                        {
#ifdef __FS_TRACE_SUPPORT__
                           if(g_TraceFlag & MT_TRACE_ERROR)
                              MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, NULL);
#endif
                           XRAISE(RTF_PARAM_ERROR);
                        }

                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                        {
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
                           if (FileInfo->FileName[0] == 0x05)
                              FileInfo->FileName[0] = 0xE5;
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
                           FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                           NTReserved = D->NTReserved;
                           goto SkipFindNextN;
                        }
                     }
                  }
                  else if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                  {
                     /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
                     if (FileInfo->FileName[0] == 0x05)
                        FileInfo->FileName[0] = 0xE5;
                     /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
                     FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                     NTReserved = D->NTReserved;
                     break;
                  }
               }
            }
ContinueFindNextN_2:
            if(Kind != Lfn)
               LFNIndex = -1;
         }
SkipFindNextN:
         if(Flag == FS_FIND_LFN_TRUNC)
         {
            for(i = 0 ; i < (MaxLength/2 - 1); i++)
            {
               if(FindName[i] == NULL)
                  break;
               FileName[i] = FindName[i];
            }
            FileName[i] = 0x0000;
         }
         MTCheckFileNameCase(FileName, MaxLength, NTReserved);
         break;
      default:
         break;
      case XFINALLY:
         if(FindName != NULL) free_ctrl_buffer(FindName);
         if(f != NULL) UnlockDevice(f->Dev);
         break;
   XEND_API

   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int FS_FindClose(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_FindClose=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_FINDCLOSE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFFindClose(FileHandle);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to reset a sort list
      recursively
PARAMETER
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      AttrMask:      Filter out the name with these attributes
      Flag:          MT_NO_SORT, MT_SORT_NAME, MT_SORT_SIZE, MT_SORT_ATTR,
                     MT_SORT_TIME, MT_SORT_TYPE
      Timeout:       RTF_NO_WAIT, RTF_INFINITE
      Position:      The pointer to sorted array
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
               RTF_TOO_MANY_FILES
NOTE
      1. No matter sort or not, no matter what kinds of sort, files
         should always put behind folders
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_XFindReset(const WCHAR * Pattern, FS_Pattern_Struct * PatternArray, UINT PatternNum,
                  BYTE ArrayMask, BYTE AttrMask, UINT Flag, UINT Timeout, UINT * Position)
{
   RTFHANDLE FHandle = 0;
   int Result = RTF_NO_ERROR;
   UINT *Hex = NULL, *Hex_File = NULL;
   UINT Count = 0, Count_File = 0;
   WCHAR * TmpName = NULL;
   WCHAR * FileName = NULL;
   RTFDOSDirEntry FileInfo;
   RTFDirLocation * PosList = NULL;
   RTFDirLocation * PosList_File = NULL;
   RTFDirLocation Pos_Hint;

#ifdef FS_EVALUATE
   kal_uint32 time_1,time_2;
   double rate;
   UINT Total = 0;

   //not count if no evaluate to reduce time
   Result = RecAUX_CountNumOfObjUnderFolderTree(Pattern, Flag, NULL, 0);
   if(Result <= RTF_NO_ERROR)
      goto FindResetReturn;
   if(Result > MT_MAX_FILE_NUM)
   {
      Result = RTF_TOO_MANY_FILES;
      goto FindResetReturn;
   }
   Total = Result;

   kal_get_time(&time_1);
#endif

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_XFindReset=> Pattern: %s, PatternNum: %d, Flag: 0x%x", (BYTE *)Pattern, PatternNum, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_XFINDRESET, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (RTFLock == NULL)
      RTFInit();

   if(MTSortLock == NULL)
      MTSortLock = RTFSYSAllocMutex("MTSortLock");

   Result = SafeLock(MT_LOCK_SORT, NULL, Timeout);

   if(Result < RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)Pattern);
#endif
      goto FindResetReturn;
   }

   //init
   Hex = NULL;
   Hex_File = NULL;
   TmpName = NULL;
   FileName = NULL;
   PosList = NULL;
   PosList_File = NULL;

   if(((Flag & FS_FILE_TYPE) == 0) && ((Flag & FS_DIR_TYPE) == 0))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      Result = RTF_PARAM_ERROR;
      goto FindResetReturn;
   }

   if(((Flag & FS_NO_SORT) == 0) && ((Flag & FS_SORT_NAME) == 0) &&
      ((Flag & FS_SORT_SIZE) == 0) && ((Flag & FS_SORT_ATTR) == 0) &&
      ((Flag & FS_SORT_TIME) == 0) && ((Flag & FS_SORT_TYPE) == 0))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      Result = RTF_PARAM_ERROR;
      goto FindResetReturn;
   }

   if(Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_NO_SORT | FS_SORT_NAME | FS_SORT_SIZE | FS_SORT_ATTR | FS_SORT_TIME | FS_SORT_TYPE))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      Result = RTF_PARAM_ERROR;
      goto FindResetReturn;
   }

   Hex = get_ctrl_buffer(4*MT_MAX_FILE_NUM);
   if(Hex == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
      Result = MT_FAIL_GET_MEM;
      goto FindResetReturn;
   }
   memset(Hex, 0, 4*MT_MAX_FILE_NUM);

   Hex_File = get_ctrl_buffer(4*MT_MAX_FILE_NUM);
   if(Hex_File == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
      Result = MT_FAIL_GET_MEM;
      goto FindResetReturn;
   }
   memset(Hex_File, 0, 4*MT_MAX_FILE_NUM);

   PosList = get_ctrl_buffer(sizeof(RTFDirLocation)*MT_MAX_FILE_NUM);
   if(PosList == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
      Result = MT_FAIL_GET_MEM;
      goto FindResetReturn;
   }
   memset(PosList, 0, sizeof(RTFDirLocation)*MT_MAX_FILE_NUM);

   PosList_File = get_ctrl_buffer(sizeof(RTFDirLocation)*MT_MAX_FILE_NUM);
   if(PosList_File == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
      Result = MT_FAIL_GET_MEM;
      goto FindResetReturn;
   }
   memset(PosList_File, 0, sizeof(RTFDirLocation)*MT_MAX_FILE_NUM);


   FileName = get_ctrl_buffer(MT_MAX_WIDE_NAME); /* To get candidate file name */
   if(FileName == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
      Result = MT_FAIL_GET_MEM;
      goto FindResetReturn;
   }

   if(Flag & (FS_SORT_NAME | FS_SORT_TYPE))
   {
      TmpName = get_ctrl_buffer(MT_MAX_WIDE_NAME); /* It has a great chance to use for comparison */
      if(TmpName == NULL)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FAIL_GET_MEM, NULL, NULL);
#endif
         Result = MT_FAIL_GET_MEM;
         goto FindResetReturn;
      }
   }
   //even if(Flag & FS_NO_SORT), still need to sort,
   //because files should always behind folders

   if(Flag & FS_DIR_TYPE)
      FHandle = FindFirst((WCHAR *)Pattern, PatternArray, PatternNum, ArrayMask, 0, AttrMask, &FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, &Pos_Hint);
   else
      FHandle = FindFirst((WCHAR *)Pattern, PatternArray, PatternNum, ArrayMask, 0, AttrMask|RTF_ATTR_DIR, &FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, &Pos_Hint);

   if(FHandle >= RTF_NO_ERROR)
   {
      *Position = (UINT)PosList;

      if(!WFNamesMatch((char *)FileName, (char *)dchar_dot))
      {//Don't worry about dchar_dot_dot here

         if((FileInfo.Attributes & RTF_ATTR_DIR) && (Flag & FS_DIR_TYPE))
         {//----------------------------- Sort Folder ------------------------------------
            Count++;
            if(Flag & FS_NO_SORT)
            {
               PosList[Count-1].Cluster = Pos_Hint.Cluster;
               PosList[Count-1].Index = Pos_Hint.Index;
            }
            else
               Result = Sort(FileName, TmpName, &FileInfo, Flag, (RTFDirLocation *)PosList,
                            (UINT *)Hex, Count, (WCHAR *)Pattern, &Pos_Hint);
         }
         else if(!(FileInfo.Attributes & RTF_ATTR_DIR) && (Flag & FS_FILE_TYPE))
         {//----------------------------- Sort File ------------------------------------
            Count_File++;
            if(Flag & FS_NO_SORT)
            {
               PosList_File[Count_File-1].Cluster = Pos_Hint.Cluster;
               PosList_File[Count_File-1].Index = Pos_Hint.Index;
            }
            else
               Result = Sort(FileName, TmpName, &FileInfo, Flag, (RTFDirLocation *)PosList_File,
                            (UINT *)Hex_File, Count_File, (WCHAR *)Pattern, &Pos_Hint);
         }
         if(Result < RTF_NO_ERROR)
            goto FindResetReturn;
      }
      while((Result = FindNext(FHandle, PatternArray, PatternNum, ArrayMask, &FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, &Pos_Hint)) == RTF_NO_ERROR)
      {
         if(Result >= RTF_NO_ERROR)
         {
            if(!WFNamesMatch((char *)FileName, (char *)dchar_dot_dot))
            {//Don't worry about dchar_dot here

               if((FileInfo.Attributes & RTF_ATTR_DIR) && (Flag & FS_DIR_TYPE))
               {//----------------------------- Sort Folder ------------------------------------
                  Count++;
                  if((Count + Count_File) > MT_MAX_FILE_NUM)
                  {
                     Result = RTF_TOO_MANY_FILES;
                     goto FindResetReturn;
                  }
                  if(Flag & FS_NO_SORT)
                  {
                     PosList[Count-1].Cluster = Pos_Hint.Cluster;
                     PosList[Count-1].Index = Pos_Hint.Index;
                  }
                  else
                     Result = Sort(FileName, TmpName, &FileInfo, Flag, (RTFDirLocation *)PosList,
                                  (UINT *)Hex, Count, (WCHAR *)Pattern, &Pos_Hint);
               }
               else if(!(FileInfo.Attributes & RTF_ATTR_DIR) && (Flag & FS_FILE_TYPE))
               {//----------------------------- Sort File ------------------------------------
                  Count_File++;
                  if((Count + Count_File) > MT_MAX_FILE_NUM)
                  {
                     Result = RTF_TOO_MANY_FILES;
                     goto FindResetReturn;
                  }
                  if(Flag & FS_NO_SORT)
                  {
                     PosList_File[Count_File-1].Cluster = Pos_Hint.Cluster;
                     PosList_File[Count_File-1].Index = Pos_Hint.Index;
                  }
                  else
                     Result = Sort(FileName, TmpName, &FileInfo, Flag,
                                  (RTFDirLocation *)PosList_File, (UINT *)Hex_File, Count_File,
                                  (WCHAR *)Pattern, &Pos_Hint);
               }
               if(Result < RTF_NO_ERROR)
                  goto FindResetReturn;
            }
         }
         else break;
      }
      if((Result != RTF_NO_MORE_FILES) && (Result < RTF_NO_ERROR))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
#endif
         goto FindResetReturn;
      }
   }
   else
   {
      Result = FHandle;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
#endif
      goto FindResetReturn;
   }

   //Connet Folder and File sort result
   {
      UINT i, j = 0;
      for(i=0; i<Count_File; i++)
      {
         PosList[Count+j].Cluster = PosList_File[i].Cluster;
         PosList[Count+j].Index = PosList_File[i].Index;
         j++;
      }
   }

   Result = Count + Count_File;

FindResetReturn:
   if(FHandle > 0) RTFClose(FHandle);
   if(Hex) free_ctrl_buffer(Hex);
   if(Hex_File) free_ctrl_buffer(Hex_File);
   if(PosList_File) free_ctrl_buffer(PosList_File);
   if(FileName) free_ctrl_buffer(FileName);
   if(TmpName) free_ctrl_buffer(TmpName);

#ifdef FS_EVALUATE
   kal_get_time(&time_2);
   rate = (double)(((double)Total)/((time_2-time_1)*0.004615));
   if(rate && (Result > RTF_NO_ERROR))
      return (Count + Count_File);
#endif

   if(Result <= RTF_NO_ERROR) //if no items, release, too
   {
      if(PosList) free_ctrl_buffer(PosList);
      SafeUnlock(MT_LOCK_SORT);
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result; //if success, don't release until MTExtFindClose
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to get a sort list
      recursively
PARAMETER
      Pattern:    Find Pattern
      FileInfo:   File information
      FileName:   File name
      MaxLength:  The length of FileName buffer
      Index:      Find index
      Position:   The sorted list
RETURN
      Success:  RTF_NO_ERROR
      Error:    RTF_PARAM_ERROR
                RTF_NO_MORE_FILES
                RTF_ACCESS_DENIED
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName,
                  UINT MaxLength, UINT Index, UINT * Position, UINT Flag)
{
   int Result = RTF_NO_ERROR;
   RTFDirLocation Pos;
   RTFDirLocation * PosList;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_XFindStart=> Pattern: %s, MaxLength: %d, Index: %d, Flag: 0x%x", (BYTE *)Pattern, MaxLength, Index, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_XFINDSTART, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if((RTFLock == NULL) || (MTSortLock == NULL) || (RTFSYSOwnMutex(MTSortLock) == KAL_FALSE))
      return RTF_ACCESS_DENIED;

   PosList = (void *)*(int **)Position;
   Pos = PosList[Index];

   if(Pos.Cluster < 2)
   {
/*#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
      return RTF_NO_MORE_FILES;
   }

   Result = GetFindByPos(Pattern, (RTFDOSDirEntry *)FileInfo, FileName, MaxLength, &Pos, Flag);
   if(Result >= RTF_NO_ERROR)
      Result = Index + 1;
#ifdef __FS_TRACE_SUPPORT__
   else
   {
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to close a sort list
PARAMETER
      Position:   Sorted list pointer
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_PARAM_ERROR
                  RTF_ACCESS_DENIED
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_XFindClose(UINT * Position)
{
#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_XFindClose=> Position: 0x%x", (UINT)Position);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_XFINDCLOSE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if((RTFLock == NULL) || (MTSortLock == NULL))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
#endif
      return RTF_ACCESS_DENIED;
   }

   if(RTFSYSOwnMutex(MTSortLock) == KAL_FALSE)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
#endif
      return RTF_ACCESS_DENIED;
   }

   if(*Position) free_ctrl_buffer(*(int **)Position);

   SafeUnlock(MT_LOCK_SORT);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif
   return RTF_NO_ERROR;
}

#endif

/* ------------------------------------------------------------------------------- */
int FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, BYTE MediaDescriptor, UINT MinSectorsPerCluster, UINT Flags)
{
   int Result = RTF_NO_ERROR;

   Result = RTFCreateBootSector(BootSector, (RTFPartitionRecord *)Partition, MediaDescriptor, MinSectorsPerCluster, Flags);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetPartitionInfo=> DriveName: %s, PartitionInfo: 0x%x", (BYTE *)DriveName, (UINT)PartitionInfo);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETPARTITIONINFO, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFGetPartitionInfo(DriveName, (RTFPartitionInfo *)PartitionInfo);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CommitAll(const WCHAR * DriveName)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CommitAll=> DriveName: %s", (BYTE *)DriveName);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_COMMITALL, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFCommitAll(DriveName);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides users to get drive name at run time
PARAMETER
      Type:
         MT_DRIVE_I_SYSTEM    (0x00000004)
         MT_DRIVE_V_NORMAL    (0x00000008)
         MT_DRIVE_V_REMOVABLE (0x00000010)
         MT_DRIVE_V_EXTERNAL  (0x00000020)
         MT_DRIVE_V_SIMPLUS  (0x00000040)
      Serial:
         Positive integer     (same type drive may have several choices)
      AltMask:
         MT_NO_ALT_DRIVE      (0x00000001, No alternative)
         MT_ONLY_ALT_SERIAL   (0x00000002, alternative serial)
         other                (OR alternative type)
RETURN
      Success:                0x43~0x47 (A~G)
      Error:                  RTF_PARAM_ERROR
                              RTF_DRIVE_NOT_FOUND
NOTE
       Drive name support:    Floppy*2 + NOR*2 + NAND*2 + Removable*n (n>0)
------------------------------------------------------------------------------- */
int FS_GetDrive(UINT Type, UINT Serial, UINT AltMask)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDrive=> Type: 0x%x, Serial: 0x%x, AltMask: 0x%x", Type, Serial, AltMask);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETDRIVE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = MTGetDrive(Type, Serial, AltMask);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides NVRAM to map system drive name at run time
PARAMETER
      UpperOldDrv: Old drive name with capitalization determinated by FS
      UpperNewDrv: New drive name with capitalization defined by NVRAM
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_DRIVE_NOT_READY
NOTE
      1. Only one combination is supported. Call twice will lose former setting.
      2. Only NVRAM can call this function.
------------------------------------------------------------------------------- */
int FS_MappingDrive(UINT UpperOldDrv, UINT UpperNewDrv)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_MappingDrive=> Old Drive: %c, New Drive: %c", UpperOldDrv, UpperNewDrv);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_MAPPINGDRIVE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = MTMappingDrive(UpperOldDrv, UpperNewDrv);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides general format facility for File Manager
PARAMETER
      DriveName:  The drive that should be formatted
      Level:      High or Low
      Progress:   The callback function
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_UNSUPPORTED_DRIVER_FUNCTION
               RTF_MEDIA_CHANGED
NOTE
      1. When formating, other tasks should not be blocked at FS
      2. Only File Manager can call this function.
      3. Double lock in this function!
------------------------------------------------------------------------------- */
int FS_GeneralFormat(const WCHAR * DriveName, UINT Level, FS_FormatCallback Progress)
{
   RTFile * volatile f2;
   RTFDrive * Drive = NULL;
   UINT i;
   RTFDevice * volatile Dev;
   int volatile Result = RTF_NO_ERROR;
   signed char InputDrive;
   WCHAR FileName[16];
   FS_DOSDateTime Time;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GeneralFormat=> DriveName: %s, Level: 0x%x", (BYTE *)DriveName, Level);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GENERALFORMAT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if(RTFLock == NULL)
      RTFInit();

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   XTRY
   case XCODE:
      if (Level != FS_FORMAT_HIGH && Level != FS_FORMAT_LOW)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "Format Level: 0x%x", Level);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_PARAM_ERROR);
      }


      for (i=5; i>0; i--)
      {
         if (DriveName[i] == 0x3A)
         {
            if ((BYTE)DriveName[i-1] == DrvMappingNew)
               InputDrive = DrvMappingOld - MT_BASE_DRIVE_LETTER;
            else
               InputDrive = (BYTE)DriveName[i-1] - MT_BASE_DRIVE_LETTER;

            if ((InputDrive > FS_MAX_DRIVES) || (InputDrive < 0))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Drive index: 0x%x", (BYTE)DriveName[i-1]);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_PARAM_ERROR);
            }
            Drive = &gFS_Data.DriveTable[InputDrive];
            break;
         }
      }

      if (Drive == NULL)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "Drive index: 0x%x", (BYTE)DriveName[i-1]);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_PARAM_ERROR);
      }

      Dev = Drive->Dev;

      if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         if (FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
         { 
            Result = FS_DEVICE_BUSY;
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR");
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND");
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card");
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 2, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Result);
         }
      }

      SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);
      MTFMLock->DeviceNum_1 = Dev->DeviceNumber;

      if(Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)DriveName);
#endif
         XRAISE(RTF_WRITE_PROTECTION);
      }

      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);

      FlushAllBuffers(Dev);
      DiscardAllBuffers(Dev);

      for (i=0, f2 = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f2++)
      {
         if ((f2->Lock != 0) && (f2->Drive == Drive))
         {
            FreeFTSlot(f2);
         }
      }

      if(Level == FS_FORMAT_HIGH)
      {
         if ((Dev->Driver->HighLevelFormat) && 
            ((Dev->DeviceFlags & FS_DEVICE_MEMORY_STICK) != FS_DEVICE_MEMORY_STICK)) //only for MSDC now
         {
            SafeUnlock(MT_LOCK_RTF); //unlock RTF only
            Result = Dev->Driver->HighLevelFormat(Dev->DriverData, Drive->FirstSector);
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
            if(Result < RTF_NO_ERROR)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)DriveName);
#endif
               XRAISE(Result);
            }
            Dev->DevData.MountState = NotMounted; // mspro
         }
         else
         {
            SafeUnlock(MT_LOCK_RTF); //unlock RTF only
            Result = RTFFormat(DriveName, 0, (RTFFormatCallback) Progress, RTF_FMT_SINGLE_FAT | RTF_FMT_NO_LOW_LEVEL);
            if(Result < RTF_NO_ERROR)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)DriveName);
#endif
               XRAISE(Result);
            }
            if ((Dev->Driver->HighLevelFormat) && 
                ((Dev->DeviceFlags & FS_DEVICE_MEMORY_STICK) == FS_DEVICE_MEMORY_STICK)) //only for MSDC now
            {
               Result = Dev->Driver->HighLevelFormat(Dev->DriverData, Drive->FirstSector);
               if(Result < RTF_NO_ERROR)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)DriveName);
#endif
                  XRAISE(Result);
               }
            }
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
            if (Dev->DeviceFlags & FS_DEVICE_MEMORY_STICK)
            {
               kal_wstrncpy(FileName, DriveName, 1);
               FileName[0] = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
               kal_wstrcpy(FileName + 1, L":\\MEMSTICK.IND");
               Result = RTFOpen(FileName, FS_ATTR_HIDDEN | FS_CREATE_ALWAYS);
               if(Result < RTF_NO_ERROR)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)DriveName);
#endif
                  XRAISE(Result);
               }
               memset((char *)(&Time), 0, sizeof(FS_DOSDateTime));
               RTFSetFileCreatedTime(Result, (RTFDOSDateTime *)(&Time));
               RTFClose(Result);
               RTFSetAttributes(FileName, FS_ATTR_READ_ONLY | FS_ATTR_HIDDEN);
            }
         }
      }
      else if(Level == FS_FORMAT_LOW)
      {
         if((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) ||
            (!Dev->Driver->LowLevelFormat))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DRIVER_FUNCTION, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_UNSUPPORTED_DRIVER_FUNCTION);
         }
         SafeUnlock(MT_LOCK_RTF); //unlock RTF only
         Result = RTFFormat(DriveName, 0, (RTFFormatCallback) Progress, RTF_FMT_SINGLE_FAT | RTF_FMT_FORCE_LOW_LEVEL);
         if(Result < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)DriveName);
#endif
            XRAISE(Result);
         }
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
      }

      if(Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {
         MountRemovableDevice(Dev);
      }
      break;
   default:
      Result = XVALUE; //API dose not need XHANDLED
      if(Progress) Progress((char *)DriveName, FS_FMT_PGS_FAIL, 0, 0);
      break;
   case XFINALLY:
      MTFMLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);
      break;
   XEND_API

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function can query the free space left in gFS_ExtQuotaSet (Quota Management only)
PARAMETER
      Path: The path defined in gFS_ExtQuotaSet
RETURN
      Success: Free space in bytes
      Error:   RTF_PATH_NOT_FOUND         (QM token not found)
               RTF_DRIVE_NOT_FOUND        (QM token found, but not mounted)
               RTF_INVALID_FILE_SYSTEM    (QM token found, but freecluster unknow yet)
               RTF_ACCESS_DENIED          (QM token found, but flag is not enabled)
NOTE
      Path name should be exactly the same as one in gFS_ExtQuotaSet
------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

int FS_QmGetFree(const BYTE * Path)
{
   int Result = RTF_PATH_NOT_FOUND;
   int RFS_for_Other, FreeSpace1, FreeSpace2;
   int i, j, k;
   RTFDrive * Drive;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_QmGetFree=> Path: %s", Path);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_QMGETFREE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);

   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      /* Match Drive Letter *both* QSET and input Path */
      if(Path[0] != gFS_ExtQuotaSet[i].Path[0])
      {
         if((gFS_ExtQuotaSet[i].Path[0] == (BYTE) DrvMappingNew && Path[0] == (BYTE) DrvMappingOld) ||
            (gFS_ExtQuotaSet[i].Path[0] == (BYTE) DrvMappingOld && Path[0] == (BYTE) DrvMappingNew))       
         {
            // no-op and fall-through
         }
         else
         {
            continue;
         }
      }

      /* Compare the Path */
      for(j = 1; j < RTF_MAX_PATH/2; j++)
      {
         if((gFS_ExtQuotaSet[i].Path[j] == 0x00) && (Path[j] == 0x00)) //match
         {
            /* calculate RFS_for_Other */
            RFS_for_Other = 0;
            for(k = FS_MAX_QSET - 1 ; k >= 0 ; k--)
            {
               if(k != i)
               {
                  if(gFS_IntQuotaSet[k].Qmin > gFS_IntQuotaSet[k].Qnow)
                     RFS_for_Other += (gFS_IntQuotaSet[k].Qmin - gFS_IntQuotaSet[k].Qnow);
               }
            }

            /* locate drive */
            if(Path[0] == (BYTE)DrvMappingNew)
               Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
            else
               Drive = &gFS_Data.DriveTable[Path[0] - MT_BASE_DRIVE_LETTER];
            if(Drive->MountState < HasFileSystem)
            {
               Result = RTF_DRIVE_NOT_FOUND;
               goto QmGetFreeReturn;
            }
            if(Drive->QuotaMgt)
            {
               if(Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
               {
                  Result = RTF_INVALID_FILE_SYSTEM;
                  goto QmGetFreeReturn;
               }

               FreeSpace1 = (Drive->FreeClusterCount > RFS_for_Other) ?
                            (Drive->FreeClusterCount - RFS_for_Other) : 0;
               if(gFS_IntQuotaSet[i].Qmax == 0) //FS_QMAX_NO_LIMIT
               {
                  Result = FreeSpace1;
               }
               else
               {
                  FreeSpace2 = gFS_IntQuotaSet[i].Qmax - gFS_IntQuotaSet[i].Qnow;
                  Result = (FreeSpace1 > FreeSpace2) ? FreeSpace2 : FreeSpace1; //min
               }
               Result *= Drive->ClusterSize;
               goto QmGetFreeReturn;
            }
            else
            {
               Result = RTF_ACCESS_DENIED;
               goto QmGetFreeReturn;
            }
         }

         if(gFS_ExtQuotaSet[i].Path[j] != Path[j])
            break;
      } /* End for(j...) */
   } /* End for(i...) */

QmGetFreeReturn:
   SafeUnlock(MT_LOCK_RTF);

#ifdef __FS_TRACE_SUPPORT__
   if(Result < RTF_NO_ERROR)
   {
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)Path);
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function returns the cluster size of the specified drive
PARAMETER
      DriveIdx: The drive index ('Z' or 0x43, 0x44, ...etc.)
RETURN
      Success:  Cluster size in byte
      Error:    RTF_DRIVE_NOT_FOUND
                RTF_INVALID_FILE_SYSTEM
------------------------------------------------------------------------------- */
int FS_GetClusterSize(UINT DriveIdx)
{
   int volatile Result = RTF_DRIVE_NOT_FOUND;
   RTFDrive * Drive;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetClusterSize=> DriveIdx: %d", DriveIdx);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETCLUSTERSIZE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   // locate Drive by index , or find it by type flag
   if (DriveIdx == (BYTE)DrvMappingNew) //Capital 'Z'
   {
      Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
   }
   else if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   }
   else
   {
      return Result;
   }

   if (Drive->MountState == HasFileSystem && Drive->Dev->DevData.MountState >= Mounted)
   {
      Result = Drive->ClusterSize;
   }
   else
   {
      /* Tell caller that it was Not Initialized Yet */
      Result = RTF_INVALID_FILE_SYSTEM;
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function Create the MBR (Sector 0)
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry)
{
   int Result = RTF_NO_ERROR;

   Result = RTFCreateMasterBootRecord(SectorBuffer, (RTFPartitionRecord *)DiskGeometry);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function Split the Partition 0
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_SplitPartition(void * MasterBootRecord, UINT Sectors)
{
   int Result = RTF_NO_ERROR;

   Result = RTFSplitPartition(MasterBootRecord, Sectors);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      Reterive information about a logical drive
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags)
{
   int Result = RTF_NO_ERROR;
   int i;
   RTFDevice * volatile Dev=NULL;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDiskInfo=> DriveName: %s, Flags: 0x%x", (BYTE *)DriveName, Flags);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETDISKINFO, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   i = FindDeviceNumberByDriveIdx((int)DriveName[0]);
   if (i)
   {
      Dev = &gFS_DeviceList[i - 1];
      if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         if (FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
         {
            Result = FS_DEVICE_BUSY;
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR");
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND");
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card");
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 2, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            return Result;
         }
      }
   }

   if (RTFLock == NULL)
      RTFInit();

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   if (Dev && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
   {
      SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);
      MTXLock->DeviceNum_1 = i;
   }

   Result = RTFGetDiskInfoEx(DriveName, (RTFDiskInfo *)DiskInfo, Flags);

   if (Dev && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
   {
      MTXLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_EXT);
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
void FS_ShutDown(void)
{
#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_ShutDown");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_SHUTDOWN, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   RTFShutDown();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif
}

/* ------------------------------------------------------------------------------- */
int FS_UnlockAll(void)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_UnlockAll");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_UNLOCKALL, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFUnlockAll();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to handle the following critical jobs
      (1) RUN ONCE
          <a> file system initialization, 
              fixed device mount, system drive mount
          <b> make 'Z' drive letter as system drive alias
          <c> system drive power lose recovery
          <d> file system trace/debug level default setting
          <e> system drive quota sweep
          <f> mount removable card device
      (2) RUN AFTER FILE SYSTEM INITIALIZED
          <g> quota configure check
PARAMETER
      None
RETURN
      (1) Return <c> status , power lose recovery on system drive
      (2) OK:      RTF_NO_ERROR 
          ERROR:   MT_QUOTA_OVER_DISK_SPACE
                   MT_QUOTA_USAGE_WARNING
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */
int FS_SanityCheck(void)
{
   int Result = RTF_NO_ERROR;
   int drvLetter;
   RTFDevice * Dev = NULL;

   Dev = &gFS_DeviceList[gFS_DeviceNumOfSYSDRV - 1];

   if (RTFLock == NULL)
   /* RUN ONCE Block */
   {
      RTFInit();

      /* XXX */
      drvLetter = MTGetDrive(MT_DRIVE_I_SYSTEM, 1, MT_NO_ALT_DRIVE);
      if (drvLetter > 0)
         MTMappingDrive(drvLetter, 90);

      if ( (Dev->DevData.ErrorCondition == FS_FDM_USER_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_SYS_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_MULTIPLE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_VERSION_MISMATCH)
         )
      {
         Result = Dev->DevData.ErrorCondition;
      }
      if (Result == RTF_NO_ERROR)
      {
         Result = RTFSanityCheck();

#ifdef __FS_TRACE_SUPPORT__ 
      #ifdef __FS_DEBUG_ALL___    
         MTSetTrace(MT_TRACE_API | MT_TRACE_ERROR | MT_TRACE_ALL_TASK, RTF_INFINITE);
      #elif defined __FS_DEBUG_API___ 
         MTSetTrace(MT_TRACE_API | MT_TRACE_ALL_TASK, RTF_INFINITE);
      #elif defined __FS_DEBUG_ERR___ 
         MTSetTrace(MT_TRACE_ERROR | MT_TRACE_ALL_TASK, RTF_INFINITE);
      #endif
#endif /* __FS_TRACE_SUPPORT__ */

#ifdef __FS_QM_SUPPORT__   
         if (stack_query_boot_mode() != USBMS_BOOT)
         {
            SweepDrive('Z');
         }
#endif /* __FS_QM_SUPPORT__ */
      }

      if (FindFirstDeviceByType(FS_DEVICE_TYPE_CARD) != NULL)
      {
         MountRemovableDevice( FindFirstDeviceByType(FS_DEVICE_TYPE_CARD) );
      }
   }
   else
   /* 2ND CALL Block */
   {
      if ( (Dev->DevData.ErrorCondition == FS_FDM_USER_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_SYS_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_MULTIPLE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_VERSION_MISMATCH)
         )
      {
         Result = Dev->DevData.ErrorCondition;
      }
   
      if (Result == RTF_NO_ERROR)
      {
#ifdef __FS_QM_SUPPORT__   
         Result = ChkQuotaConfig('Z');
#endif /* __FS_QM_SUPPORT__ */
      }
   }

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_SetDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

   Result = RTFSetDiskFlag();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CheckDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CheckDiskFlag");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CHECKDISKFLAG, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFCheckDiskFlag();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_ClearDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_ClearDiskFlag");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CLEARDISKFLAG, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = RTFClearDiskFlag();

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function return the flash type for the corresponding path
PARAMETER
      Path: The full-path which begin with drive letter 
RETURN
      Success:  FS_DEVICE_TYPE_NOR (1)
                FS_DEVICE_TYPE_NAND (2)
                FS_DEVICE_TYPE_CARD (3)
                FS_DEVICE_TYPE_EXTERNAL (4)
      Error:    RTF_DRIVE_NOT_FOUND
------------------------------------------------------------------------------- */
int FS_GetDevType(const WCHAR * Path)
{
   int volatile Result = RTF_DRIVE_NOT_FOUND;
   RTFDrive *Drive = NULL;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDevType=> Path: %s", (char *)Path);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETDEVTYPE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (RTFLock == NULL)
      RTFInit();

   /* Get Drive */
   if (Path == NULL)
   {
      return RTF_PARAM_ERROR;
   }

   if (DrvMappingNew == (int) Path[0])
   {
      Drive = &gFS_Data.DriveTable[DrvMappingOld - (int) MT_BASE_DRIVE_LETTER];
   } else if ( (Path[0] >= (WCHAR) MT_BASE_DRIVE_LETTER) &&
               (((int) Path[0] - (int) MT_BASE_DRIVE_LETTER) < FS_MAX_DRIVES) )
   {
      Drive = &gFS_Data.DriveTable[(int) Path[0] - (int) MT_BASE_DRIVE_LETTER];
   }

   /* Now Get Device Type by Drive ptr */
   if (Drive)
   {
      if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
         Result = FS_DEVICE_TYPE_NOR;
      else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         Result = FS_DEVICE_TYPE_NAND;
      else if(Drive->Dev->DeviceFlags & MT_DEVICE_EXTERNAL)
         Result = FS_DEVICE_TYPE_EXTERNAL;
      else if(Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
         Result = FS_DEVICE_TYPE_CARD;
   }

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to let task looks up the
      device status
PARAMETER
      QueryTarget: the index number get from FS_GetDrive
                OR the type enum get from FS_GetDevType
      Flag:        FS_MOUNT_STATE_ENUM
                or FS_FEATURE_STATE_ENUM
                or FS_EXPORT_STATE_ENUM
RETURN
      Success:  RTF_NO_ERROR (means depends on the flag,
                              FS_MOUNT_STATE_ENUM => Mounted,
                              FS_FEATURE_STATE_ENUM => Device not busy,
                              FS_EXPORT_STATE_ENUM => Device not exported.)
                              FS_CARD_BATCHCOUNT_STATE_ENUM => Is free cluster counted on CARD
      Error:    RTF_PARAM_ERROR
                MT_MSDC_MOUNT_ERROR
                MT_FLASH_MOUNT_ERROR
                MT_DEVICE_BUSY
                MT_DEVICE_EXPORTED_ERROR
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */
int FS_GetDevStatus(UINT QueryTarget, UINT QueryType)
{
   RTFDrive * Drive = NULL;
   RTFDevice * Dev = NULL;
   kal_taskid current_task;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDevStatus=> Target: 0x%X, Type: %d", QueryTarget, QueryType);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETDEVSTATUS, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   // locate Drive by index , or find it by type flag
   if (QueryTarget >= MT_BASE_DRIVE_LETTER && QueryTarget < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[QueryTarget - MT_BASE_DRIVE_LETTER];
   }
   else if (QueryTarget < FS_DEVICE_TYPE_MAX_VALUE)
   {
      Dev = FindFirstDeviceByType(QueryTarget);
   }

   // Return if neither Dev nor Drive found
   if (Drive == NULL && Dev == NULL)
   {  // Fall through... and return PARAM_ERROR
   }
   else
   {  // Now Do Query job
      if (Dev == NULL)
      {
         Dev = Drive->Dev;
      }

      switch (QueryType)
      {
         case FS_MOUNT_STATE_ENUM:
            if (Dev->DevData.MountState >= Mounted)
            {
               if ((Drive == NULL) || /* QueryTarget is Device */
                   (Drive != NULL && Drive->MountState == HasFileSystem) /* QueryTarget is Drive */)
               {
                  return RTF_NO_ERROR;
               }
            }

            if (Drive == NULL && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
            /* QueryTarget is Device, query for OTG Card Reader */
            {
               if (g_ExternalDevice == KAL_TRUE)
               {
                  return RTF_NO_ERROR;
               }
#ifdef __FS_TRACE_SUPPORT__
               if (g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Status Query Target: 0x%x, Type: %d", QueryTarget, QueryType);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_EXTERNAL_DEVICE_NOT_PRESENT, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               return MT_EXTERNAL_DEVICE_NOT_PRESENT;
            } 
            /* Otherwise, treat as built-in card or card-slot */
            else if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
            {
#ifdef __FS_TRACE_SUPPORT__
               if (g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Status Query Target: 0x%x, Type: %d", QueryTarget, QueryType);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_MSDC_MOUNT_ERROR, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               return MT_MSDC_MOUNT_ERROR;
            }
            else if (Dev->DeviceFlags & (MT_DEVICE_NAND_FLASH | MT_DEVICE_NOR_FLASH))
            {
#ifdef __FS_TRACE_SUPPORT__
               if (g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Status Query Target: 0x%x, Type: %d", QueryTarget, QueryType);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, MT_FLASH_MOUNT_ERROR, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               if (Dev->DevData.ErrorCondition < 0)
               {
                  return Dev->DevData.ErrorCondition;
               }
               else
               {
                  return MT_FLASH_MOUNT_ERROR;
               }
            }
            // should not touch here, but throw away
            break;

         case FS_FEATURE_STATE_ENUM:
            current_task = kal_get_current_thread_ID();
            
            if (MTFMLock)
            {
               if (MTFMLock->DeviceNum_1 == Dev->DeviceNumber)
               // Candidates : FS_CheckDrive() , FS_GeneralFormat()
                  if (MTFMLock->rtf_sem_owner != current_task)
                     return MT_DEVICE_BUSY;
            }

#ifdef __FS_MOVE_SUPPORT__
            if (MTMoveLock)
            {
               if ((MTMoveLock->DeviceNum_1 == Dev->DeviceNumber) ||
                   (MTMoveLock->DeviceNum_2 == Dev->DeviceNumber))
               // Candidates : FS_Move()
                  if (MTMoveLock->rtf_sem_owner != current_task)
                     return MT_DEVICE_BUSY;
            }
#endif

            if (MTXdelLock)
            {
               if (MTXdelLock->DeviceNum_1 == Dev->DeviceNumber)
               // Candidates : FS_XDelete()
                  if (MTXdelLock->rtf_sem_owner != current_task)
                     return MT_DEVICE_BUSY;
            }

            if (MTXLock)
            {
               if (MTXLock->DeviceNum_1 == Dev->DeviceNumber)
               // Candidates : FS_Count() , FS_GetFolderSize() , FS_GetDiskInfo()
                  if (MTXLock->rtf_sem_owner != current_task)
                     return MT_DEVICE_BUSY;
            }
            
            return RTF_NO_ERROR;

         case FS_EXPORT_STATE_ENUM:
            if (Dev->DeviceFlags & MT_DEVICE_EXPORTING)
            {
               return MT_DEVICE_EXPORTED_ERROR;
            }
            return RTF_NO_ERROR;

         case FS_CARD_BATCHCOUNT_STATE_ENUM:
            if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
            {
               if (Drive == NULL)
               {
                  Drive = Dev->DevData.FirstDrive;
               }
               if (Drive != NULL)
               {
                  if (Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
                  {
                     return FS_CARD_BATCHCOUNT_NOT_PRESENT;
                  }
                  else
                  {
                     return FS_NO_ERROR;
                  }
               }
            }
            break;

         default:
            break;
      }
   }

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & MT_TRACE_ERROR)
   {
      kal_sprintf(TraceTmpBuf, "Status Query Target: 0x%x, Type: %d, FindDev: %x", QueryTarget, QueryType, (UINT)Dev);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   return RTF_PARAM_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides task to lock whole file system in USB mode or set to
      nonblock/block access on driver in NORMAL mode
Parameter
      Type: FS_LOCK_TYPE_ENUM
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_TIMEOUT
------------------------------------------------------------------------------- */
int FS_LockFAT(UINT Type)
{
   RTFDevice *Dev;
   RTFDrive  *Drive = NULL;
   RTFile    *f;
   int        i;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_LockFAT=> Type: %d", Type);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_LOCKFAT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   switch(Type)
   {
      case FS_LOCK_USB_ENUM:
         /* USB Boot Mode Entering */
         SysLockFAT = 1;
         break;

      case FS_UNLOCK_USB_ENUM:
         /* USB Boot Mode Exiting */
         SysLockFAT = 0;
         break;

      case FS_LOCK_BLOCK_ENUM:
         SysBlockFAT = 1;
         break;

      case FS_LOCK_NONBLOCK_ENUM:
         SysBlockFAT = 0;
         break;

      case FS_EXPORT_ENUM:
         /* USB Normal Mode Access Entring */
         SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

         /* Export - 1 : Set exporting flag on normal devices, except for NO_EXPORT flags and system device device
          *          ==> app cannot open file on those devices
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            XTRY
               case XCODE:
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                  if (Dev->DeviceFlags & MT_DEVICE_NO_EXPORT || Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
                  {  /* do nothing */
                  }
                  else
                  {
                     FlushAllBuffers(Dev);
                     Dev->DeviceFlags |= MT_DEVICE_EXPORTING;
                  }
                  break;
               default:
                  if ((Dev->DeviceFlags & FS_DEVICE_REMOVABLE) && (XVALUE == FS_DRIVE_NOT_READY))
                  {
                     Dev->DeviceFlags |= MT_DEVICE_EXPORTING;
                     XHANDLED;
                  }
                  break;
               case XFINALLY:
                  SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                  break;   
            XEND
         }

         /* Export - 2 : Scan FileTable and set MT_ENUM_FH_EXPORTED for non system drive
          *          ==> app access file handle will get error next time
          *          NOTE: system drive is located on the last partition of gFS_DeviceNumOfSYSDRV device 
          */
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               Drive = Dev->DevData.FirstDrive;
               break; /* system drive found */
            }
         }
         for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
         {
            if (f->Drive != NULL && f->Drive != Drive)
            {
               if (f->Dev->DeviceFlags & MT_DEVICE_NO_EXPORT)
                  continue;
               f->Valid = MT_ENUM_FH_EXPORTED;
            }
         }
         RTFSYSFreeMutex(RTFLock);

         /* Export - 3 : Process each exported device, determined by MT_DEVICE_EXPORTING flag
          *          ==> set the logical drive to unmount state
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceFlags & MT_DEVICE_EXPORTING)
            {
               SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
               for(Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
               {
                  Drive->MountState = Mounted; /* Mounted state means MBR/PBR scan already done */
               }
               SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
            }
         }

         SafeUnlock(MT_LOCK_FMT);
         break; /* End of FS_EXPORT_ENUM Block */

      case FS_PURGE_HANDLE_ENUM:
         /* USB Normal Mode Access : PURGE Open FileHandle
          * ----------------------------------------------
          * When public drive and system drive on the same device, there may be some filehandle
          * created concurrency during (A) FS_EXPORT_ENUM   to   (B) FS_Open(WholePublicDrive).
          * Purge Handle is required to help USB task to clear intruded filehandle.
          */

         /* Purge - 1 : Search the system drive */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               Drive = Dev->DevData.FirstDrive;
               break; /* system drive found */
            }
         }

         /* Purge - 2 : Lock Device and Purge FileHandles */
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
         {
            if (f->Dev == Drive->Dev && f->Drive != Drive)
            {
               f->Valid = MT_ENUM_FH_EXPORTED;
            }
         }
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break; /* End of FS_PURGE_HANDLE_ENUM Block */

      case FS_REMOUNT_ENUM:
         /* USB Normal Mode Access Exiting */
         SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);
         
         /* Remount - 1 : Scan file handle table and Garbage Collection
          */
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
         {
            if(f->Valid == MT_ENUM_FH_EXPORTED)
            {
               FreeFTSlot(f);
            }
         }
         RTFSYSFreeMutex(RTFLock);

         /* Remount - 2 : ReMount exported and unmounted dirves 
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceFlags & MT_DEVICE_NO_EXPORT)
               continue;
            /* system drive device may contain dirty buffers, flush it first */
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               XTRY
                  case XCODE:
                     SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                     FlushAllBuffers(Dev);
                     break;
                  default:
                     break;
                  case XFINALLY:
                     SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                     break;   
               XEND
            }
            /* Removable device may have several partitions... for example SIM_PLUS */
            if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
            {
               if (MountRemovableDevice(Dev) != RTF_NO_ERROR)
               /* removable device status not ready, skip logical drive mount below */
                  continue;
            }
            for(Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
            {
               if (Drive->MountState == HasFileSystem)
                  continue;
               ReMountDriveAndCountFreeClusters(Drive);
            }
         }

         /* Remount - 3 : turn off the exporting flag on each device
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if ((Dev->DeviceFlags & MT_DEVICE_EXPORTING) == 0)
               continue;
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
            Dev->DeviceFlags &= ~MT_DEVICE_EXPORTING;
            SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         }

         SafeUnlock(MT_LOCK_FMT);

         break; /* End of FS_REMOUNT_ENUM block */

      case FS_CARD_BUSY_NONBLOCK_ENUM:
         CardBusyCheck = 1;
         break;

      default:
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "Type: %d", Type);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         return RTF_PARAM_ERROR;
   }
   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides mount/un-mount FS facility on MSDC Card Slots for File Manager
Parameter
      slot_id:   DriverData Pointer
Return
      Success: RTF_NO_ERROR (Card is present)
               MT_MSDC_NOT_PRESENT (Card is not present)
               MT_EXTERNAL_DEVICE_NOT_PRESENT (Card Reader is not present)
      Error:   MT_MSDC_MOUNT_ERROR
               RTF_UNSUPPORTED_DEVICE
               RTF_UNSUPPORTED_DRIVER_FUNCTION
Restriction
      1. Only File Manager can call this function.
      2. Other tasks cannot use MSDC until File Manager mount it back.
 ------------------------------------------------------------------------------- */
int FS_TestMSDC(void * slot_id)
{
   RTFDevice * Dev;
   int volatile Result;
   int i;
   RTFile * volatile f;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_TestMSDC=> slot_id: %x", (UINT) slot_id);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_TESTMSDC, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (RTFLock == NULL)
      RTFInit();

   if (MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   /* TestMSDC - 1 : Lock FMT */
   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   /* TestMSDC - 2 : Find the Device Slot */
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if ((Dev->DriverData == slot_id) && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
         break;

   if (Dev-> DeviceType == 0) /* Device Not Found */
   {
      SafeUnlock(MT_LOCK_FMT);
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "slot_id: %x", (UINT) slot_id);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DEVICE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_UNSUPPORTED_DEVICE;
   }

   /* TestMSDC - 3 : DRV API MessageAck() , MediaChanged() */
   if (Dev->Driver->MessageAck && Dev->Driver->MediaChanged)
   {
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MessageAck(Dev->DriverData, FS_DEV_SLOT_ACK_ENUM);
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MediaChanged(Dev->DriverData);
   }
   else
   {
      SafeUnlock(MT_LOCK_FMT);
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "slot_id: %x", (UINT) slot_id);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DRIVER_FUNCTION, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* TestMSDC - 4 : Consider Exported Case */
   if (Dev->DeviceFlags & MT_DEVICE_EXPORTING)
   {
      switch (Result)
      {
         /* 4-1 : Return Exported Error */
         case MT_MSDC_PRESNET_NOT_READY:
         case RTF_NO_ERROR:
            Result = MT_DEVICE_EXPORTED_ERROR;
            break;

         /* 4-2 : Return Plug-Out */
         case MT_MSDC_NOT_PRESENT:
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:
         default:
            Result = MT_MSDC_NOT_PRESENT;
            break;
      }
      SafeUnlock(MT_LOCK_FMT);
      return Result;
   }

   /* TestMSDC - 5 : Branch By Previous MountState Primary, By MediaChanged() Return Value Secondary */
   if (Dev->DevData.MountState == NotMounted) 
   {
      switch (Result)
      {
         /* 5-A-1 : Mount The Removable Device */
         case MT_MSDC_PRESNET_NOT_READY:
         case RTF_NO_ERROR:
            Result = MountRemovableDevice(Dev);
            break;

         /* 5-A-2 : Do Nothing */
         case MT_MSDC_NOT_PRESENT:
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:
         default:
            break;
      }
   }
   else /* Previous MountState == Mounted ; However, May not HasFileSystem */
   {
      switch (Result)
      {
         /* 5-B-1 : Set UnMount, Release all Opened File Handle */
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:
         case MT_MSDC_NOT_PRESENT:
            Dev->DevData.MountState = NotMounted;
            for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
            {
               if(f->Dev == Dev)
               {
                  f->Valid = MT_ENUM_FH_MEDIACHANGED;
               }
            }
            break;

         /* 5-B-2 : Set UnMount, Release all Opened File Handle, Then Re-Mount it */
         case MT_MSDC_PRESNET_NOT_READY:
            Dev->DevData.MountState = NotMounted;
            for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
            {
               if(f->Dev == Dev)
               {
                  f->Valid = MT_ENUM_FH_MEDIACHANGED;
               }
            }
            Result = MountRemovableDevice(Dev);
            break;

         /* 5-B-3 : Do Nothing */
         case RTF_NO_ERROR:
            if (Dev->DevData.MountState < HasFileSystem)
            {
               Result = MountRemovableDevice(Dev);
            }
            break;
         default:
            break;
      }
   }

   /* TestMSDC - 6 : UnLock and Return */
   SafeUnlock(MT_LOCK_FMT);
   if (Result == MT_MSDC_PRESNET_NOT_READY)
      return MT_MSDC_MOUNT_ERROR;
   return Result;
}


/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides formal plug out facility on MSDC (built-in or OTG external) for File Manager
PARAMETER
      DriveIdx:   The drive index (0x43, 0x44, ...etc.)
      Mode:       FS_NONBLOCK_MODE
                  0x0  default block mode
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_PARAM_ERROR
                  RTF_DRIVE_NOT_FOUND
                  RTF_INVALID_FILE_SYSTEM
                  RTF_TIMEOUT
NOTE
      1. Only File Manager can call this function.
      2. Double lock in this function!
 ------------------------------------------------------------------------------- */
int FS_CloseMSDC(UINT DriveIdx, UINT Mode)
{
   RTFDrive * Drive;
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CloseMSDC=> DriveIdx: %d", DriveIdx);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CLOSEMSDC, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if(RTFLock == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RTFLock = NULL !");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_INVALID_FILE_SYSTEM;
   }

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   if((Mode != FS_NONBLOCK_MODE) && (Mode != 0x0))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DriveIdx: %d, Mode = 0x%x", DriveIdx, Mode);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   // locate Drive by index
   if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   }
   else
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DriveIdx: %d", DriveIdx);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_DRIVE_NOT_FOUND, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_DRIVE_NOT_FOUND;
   }

   if((Drive->Dev == NULL) || ((Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DriveIdx: %d", DriveIdx);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DEVICE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_UNSUPPORTED_DEVICE;
   }

   // Now Lock FMT, DEVICE, and RTFLock
   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   if(Mode == FS_NONBLOCK_MODE)
   {
      Result = SafeLock(MT_LOCK_DEV, Drive->Dev, RTF_NO_WAIT);
      if(Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "DriveIdx: %d", DriveIdx);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         goto CloseReturn;
      }
      Result = SafeLock(MT_LOCK_RTF, NULL, RTF_NO_WAIT);
      if(Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "DriveIdx: %d", DriveIdx);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         goto CloseReturn;
      }
   }
   else
   {
      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
   }

   // Now Do clean up jobs
   XTRY
   case XCODE:
      CloseDevice(Drive->Dev);
      break;
   default:
      Result = XVALUE; //API dose not need XHANDLED
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);
      break;
   case XFINALLY:
      Drive->Dev->DevData.MountState = NotMounted;
      break;
   XEND_API

CloseReturn:
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to trace file system behavior
PARAMETER
      Flag: FS_TRACE_API, MT_TRACE_ERROR, FS_TRACE_DISABLE
RETURN
      This function always return successful
 ------------------------------------------------------------------------------- */
#ifdef __FS_TRACE_SUPPORT__

int FS_SetTrace(UINT Flag, UINT Timeout)
{
   MTSetTrace(Flag, Timeout);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_NO_ERROR;
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to dump file handle table
RETURN
      This function always return successful
 ------------------------------------------------------------------------------- */
#ifdef __FS_TRACE_SUPPORT__

int FS_DumpFHTable(void)
{
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_DumpFHTable");
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_DUMPFHTABLE, NULL, (BYTE *)TraceTmpBuf);
   }

   MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_ERROR_RESERVED, NULL, NULL);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_NO_ERROR;
}

#endif


/* -------------------------------------------------------------------------------
DESCRIPTION
      Some file formats pack multiple objects inside. This API is designed for programmers
      who want to process inside objects without copy overhead. Users call this API to 
      generate a virtual file name (full-path string in fact) first. Then users can 
      FS_Open(), FS_Read(), and FS_Seek() against virtual file just like a normal file.
PARAMETER
      LargeFile         The file-handler of the real-file that virtual-file mapped into.
      VFileNameBuf      A pointer of the file name string buffer provided to store 
                        generated file name.
      BufLength         The available buffer length (in byte unit) of VFileNameBuf provided
                        to prevent buffer overflow.
      VFBeginOffset     Specify the segment beginning (in byte unit) in the real-file to
                        be treated as virtual-file content.
      VFValidLength     Specify the segment length (in byte unit) in the real-file to be
                        treated as virtual-file content.
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILENAME
                  RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_GenVirtualFileName(FS_HANDLE File, WCHAR * VFileNameBuf, UINT BufLength, UINT VFBeginOffset, UINT VFValidLength)
{
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GenVirtualFileName=> FileHandle: %x, VFBegin: %d, VFLength: %d", File, VFBeginOffset, VFValidLength);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GENVIRTUALFILENAME, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = MTGenVirtualFileName( File, VFileNameBuf, BufLength, VFBeginOffset, VFValidLength);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      To support a special kind of device --- Card Reader, which contain variance number of slots.
PARAMETER
      Action         accept FS_SETUP_EXT_DEVICE or FS_RELEASE_EXT_DEVICE only
      DrvFuncs       The Device Driver Callback Functions, {MountDevice, Shutdown, ... }
      Slots          Number of independent slots, fill 1 device entry and *allocate* 1 
                     drive element per slot.
      SlotIdArray    The DriverData (treat as slot-id) array to be fill on device list.
      SlotsDone      The Number of slots that configured and supported in FS.
RETURN
      Success:    Number of slots configured succeed.
      Error:      RTF_INVALID_FILENAME
                  RTF_PARAM_ERROR
NOTE
      Currently, No *allocate* operation commited, this API is design to keep FMT/FS/DRV iterface
      complete. But not real dynamic yet!
 ------------------------------------------------------------------------------- */
int FS_ConfigExtDevice(int Action, FS_Driver *DrvFuncs, int Slots, void **SlotIdArray, int *SlotsConfiged)
{  
   int Result = RTF_NO_ERROR;
   RTFDevice *Dev = NULL;
   int DevEntryCnt = 0;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_ConfigExtDevice=> Action: %d, DrvFuncs: %x, Slots: %d", Action, (UINT) DrvFuncs, Slots);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CONFIGEXTDEVICE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* ConfigExt - 1 check parameter */
   if ((DrvFuncs == NULL) || (SlotIdArray == NULL) || (Slots < 1))
   {
      return RTF_PARAM_ERROR;
   }

   /* ConfigExt - 2 Protect for concurrency or un-init state */
   if (RTFLock == NULL)
      RTFInit();

   if (MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   *SlotsConfiged = 0;

   /* ConfigExt - 3 Locate First Entry by Driver and Check if not supported */
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      if ((Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
      {
         break;
      }
   }

   if (Dev->DeviceType == 0) /* NOT FOUND */
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DrvFuncs: %x Not Found in DeviceList", (UINT) DrvFuncs);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DEVICE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      SafeUnlock(MT_LOCK_FMT);
      return RTF_UNSUPPORTED_DEVICE;
   }

   if (Dev->Driver->MessageAck == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DrvFuncs: %x without MessageAck() Member", (UINT) DrvFuncs);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_UNSUPPORTED_DRIVER_FUNCTION, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      SafeUnlock(MT_LOCK_FMT);
      return RTF_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* ConfigExt - 4 Procedure -- IN */
   if (Action == FS_SETUP_EXT_DEVICE)
   {
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MessageAck(NULL, FS_DEV_IN_ACK_ENUM);
      if (Result >= RTF_NO_ERROR)
      {
         /* Assumption:
          *  The DeviceList Cannot be Dynamic ReSize, Determined on Build-time
          */
         /* Dev is the First Entry  */
         for (DevEntryCnt = 0 /* , Dev = gFS_DeviceList */; Dev->DeviceType; Dev++)
         {
            if (Slots > 0 && (Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
            {
#ifdef FS_DYNAMIC_DEVICE_SUPPORT
               /******** PSEUDO CODE *********
                * Lock Dev and RTF
                      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                * Setup DeviceList
                      Dev->DriverData = SlotIdArray[DevEntryCnt];
                * Allocate Drive Table Entry
                      DrivePtr = malloc();
                * Hook to Device List 
                      Dev->DevData.FirstDrive = DrivePtr;
                      DrivePtr->Dev = Dev;
                * Hook to DriveLetter Lookup Table
                      DriveLetterTBL[ 'M' + DevEntryCnt ] = DrivePtr;
                * Release LOCK
                      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                ******************************/
#else
               /* NOTE: AllocateDrive() will pass even if it run out of gFS_Data.DriveTable
                *       Check Dev->DevData.FirstDrive here to make sure it's enough
                */
               if (Dev->DevData.FirstDrive == NULL)
               {
                  continue;
               }
#endif
               DevEntryCnt++;
               Slots--;
            }
         }
         /* Set *SlotsConfiged Value HERE */
         *SlotsConfiged = DevEntryCnt;
         
         g_ExternalDevice = KAL_TRUE;
      }
   }
   /* ConfigExt - 4 OUT_ACK procedure, !!MUST!! call MessageAck() after release */
   else if (Action == FS_RELEASE_EXT_DEVICE)
   {
      /* Assumption:
       *  The DeviceList Cannot be Dynamic ReSize, Determined on Build-time
       */
      /* Dev is the First Entry  */
      for (DevEntryCnt = 0 /* , Dev = gFS_DeviceList */; Dev->DeviceType; Dev++)
      {
         if (Slots > 0 && (Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
         {
#ifdef FS_DYNAMIC_DEVICE_SUPPORT
            /******** PSEUDO CODE *********
             * Lock Dev and RTF
                   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
             * Safe CHECK for FileTable
                   .....
             * Release Device-->Drive Relation Linking
                   DrivePtr = Dev->DevData.FirstDrive;
                   Dev->DevData.FirstDrive = NULL;
                   DrivePtr->Dev = NULL;
             * Clear Reference on DriveLetter Lookup Table
                   DriveLetterTBL[ 'M' + DevEntryCnt ] = NULL;
             * Clear Slot-id on DeviceList TABLE
                   Dev->DriverData = NULL;
             * Free Drive Table Entry
                   free( DrivePtr );
             * Release LOCK
                   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
             ******************************/
#else
            /* NOTE: AllocateDrive() will pass even if it run out of gFS_Data.DriveTable
             *       Check Dev->DevData.FirstDrive here to make sure it's enough
             */
            if (Dev->DevData.FirstDrive == NULL)
            {
               continue;
            }
#endif
            DevEntryCnt++;
            Slots--;
         }
      }
      /* Set *SlotsConfiged Value HERE */
      *SlotsConfiged = DevEntryCnt;
      
      g_ExternalDevice = KAL_FALSE;
      //XXX: don't lock device && don't check Dev's MountState
      Result = DrvFuncs->MessageAck(NULL, FS_DEV_OUT_ACK_ENUM);
   }
   /* ConfigExt - 5 NO such action, bye */
   else
   {
      Result = RTF_PARAM_ERROR;
   }

   SafeUnlock(MT_LOCK_FMT);
   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to check drive
      !! Function prototype rewritten since W06.13 !! 
PARAMETER
      DriveIdx: The drive index ('Z' or 0x43, 0x44, ...etc.)
      CheckBuffer: The buffer get from caller
      CheckBufferLength: The buffer length, must > 2048
RETURN
      Success: RTF_NO_ERROR
      Error:   MT_FAIL_GET_MEM
               RTF_DRIVE_NOT_FOUND
               RTF_WRITE_PROTECTION
               RTF_INVALID_FILE_SYSTEM
               RTF_ACCESS_DENIED
               MT_ABORTED_ERROR
NOTE
      1. Recommand Check Buffer Size : 128MB Disk Size ===>  8KB
                                     for 1GB Size Disk ===> 32KB
 ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__

int FS_CheckDrive(const UINT DriveIdx, BYTE * CheckBuffer, const UINT CheckBufferSize)
{
   int Result = RTF_NO_ERROR;
   RTFDrive *Drive;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CheckDrive=> DriveIdx: %x", DriveIdx);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_CHECKDRIVE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* FS_CheckDrive - 1a , RAM Parameter Check */
   if(CheckBuffer == NULL || CheckBufferSize <= 2)
   {
      Result = MT_FAIL_GET_MEM;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 1b , DriveIdx Parameter Check */
   if (DriveIdx == (BYTE)DrvMappingNew) //Capital 'Z'
   {
      Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
   }
   else if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   }
   else
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 1c , Drive Status, Access Check */
   if (Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
   {
      Result = RTF_WRITE_PROTECTION;
      goto CheckDiskReturn;
   }
   else if (Drive->MountState != HasFileSystem || Drive->Dev->DevData.MountState < HasFileSystem)
   {
      Result = RTF_INVALID_FILE_SYSTEM;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 2a , Retrieve FMT Lock and Raise Busy State */
   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);
   MTFMLock->DeviceNum_1 = Drive->Dev->DeviceNumber;

   /* FS_CheckDrive - 2b , Erect Flag of CHECKDRIVE */
   g_CheckDrive = KAL_TRUE;

   /* FS_CheckDrive - 2c , Do Job of CHECKDRIVE */
   Result = ScanDrive(Drive, (void *)CheckBuffer, CheckBufferSize);

   /* FS_CheckDrive - 2d , Clear flags and Busy State */
   if (g_CheckDrive == KAL_FALSE)
   {
      Result = MT_ABORTED_ERROR;
   }
   g_CheckDrive = KAL_FALSE;

   MTFMLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_FMT);

   /* FS_CheckDrive - 3 , Clean Up */
CheckDiskReturn:
#ifdef __FS_TRACE_SUPPORT__
   if(Result < RTF_NO_ERROR)
   {
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "DriveIdx: %x", DriveIdx);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
   }
#endif

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}
#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
      NewValue: The new reusable value to be associated.
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */
int FS_SetDirCache(FS_HANDLE FileHandle, UINT NewValue)
{
   RTFile * volatile f=NULL;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_SetDirCache => FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_SETDIRCACHE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);
         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               MTTraceFS((UINT)kal_get_task_self_id(), 2, __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
            }
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }
         MTSetDirCacheValue(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), NewValue);
      default:
         break;
      case XFINALLY:
         if (f != NULL) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
      NewValue: The new reusable value to be associated.
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */
int FS_GetDirCache(FS_HANDLE FileHandle, UINT *CurrValue)
{
   RTFile * volatile f=NULL;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDirCache=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_GETDIRCACHE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);
         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               MTTraceFS((UINT)kal_get_task_self_id(), 2, __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
            }
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }
         MTGetDirCacheValue(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), CurrValue);
      default:
         break;
      case XFINALLY:
         if (f != NULL) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */
int FS_ExpireDirCache(FS_HANDLE FileHandle)
{
   RTFile * volatile f=NULL;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_ExpireDirCache=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_EXPIREDIRCACHE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);
         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               MTTraceFS((UINT)kal_get_task_self_id(), 2, __LINE__, RTF_ACCESS_DENIED, NULL, NULL);
            }
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }
         MTExpireDirCacheValue(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
      default:
         break;
      case XFINALLY:
         if (f != NULL) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to count the number of files
      or folders recursively
PARAMETER
      FullPath:          Source path to be counted
      Flag:              FS_FILE_TYPE, FS_DIR_TYPE, FS_RECURSIVE_TYPE
      RecursiveStack:    A memory pointer to store deep folder hierarchy recrusive data
      StackSize:         The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               MT_FAIL_GET_MEM
NOTE
      1. This API belong to Recursive Class
------------------------------------------------------------------------------- */
int FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Count=> FullPath: %s, Flag: 0x%x", (BYTE *)FullPath, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_COUNT, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   if (RTFLock == NULL)
      RTFInit();

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   /* Count - 1 : Parameter Check */
   if(((Flag & FS_FILE_TYPE) == 0) && ((Flag & FS_DIR_TYPE) == 0) && ((Flag & FS_RECURSIVE_TYPE) == 0))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   if(Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(FullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
   }
   else
   {
   Result = RecAUX_IsFolder(FullPath);
   }

   if (Result < RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
      }
#endif
      return Result;
   }



   /* Count - 2 : Action */

   SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);
   MTXLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
   Result = RecAUX_CountNumOfObjUnderFolderTree(FullPath, Flag, RecursiveStack, StackSize);
   MTXLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_EXT);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to get folder size
PARAMETER
      DirName        : Full source path to be counted
      Flag           : FS_COUNT_IN_BYTE, FS_COUNT_IN_CLUSTER
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      >0       : Size in byte or cluster
      Error    : RTF_PATH_NOT_FOUND, RTF_PARAM_ERROR
NOTE
      1. The size here counts for FAT allocation, not only data setctor allocation
      2. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
int FS_GetFolderSize(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetFolderSize=> FullPath: %s", (char *)FullPath);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETFOLDERSIZE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* GetFolderSize - 1 : Parameter Check */
   if((Flag != FS_COUNT_IN_BYTE) && (Flag != FS_COUNT_IN_CLUSTER))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, NULL);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(FullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
   }
   else
   {
   Result = RecAUX_IsFolder(FullPath);
   }

   if (Result < RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)FullPath);
      }
#endif
      return Result;
   }

   /* GetFolderSize - 2 : Action */
   if (RTFLock == NULL)
      RTFInit();

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);
   MTXLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
   Result = RecAUX_CountSumOfSizeUnderFolderTree(FullPath, Flag, RecursiveStack, StackSize);
   MTXLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_EXT);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to delete a file or folder
      recursively
PARAMETER
      FullPath       : Source path to be deleted
      Flag           : FS_FILE_TYPE, FS_DIR_TYPE, FS_RECURSIVE_TYPE
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
NOTE
      1. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
int FS_XDelete(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_XDelete=> FullPath: %s, Flag: 0x%x", (BYTE *)FullPath, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_XDELETE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* XDelete - 1 : Parameter Check */
   if (((Flag &  (FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE)) == 0) ||
        (Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE))         )
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Flag: 0x%x", Flag);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return RTF_PARAM_ERROR;
   }

   if (RTFLock == NULL)
      RTFInit();

   if(MTXdelLock == NULL)
      MTXdelLock = RTFSYSAllocMutex("MTXdelLock");

   Result = RecAUX_IsFolderRW(FullPath);
   // the path is a file
   if (Result == RTF_PARAM_ERROR)
   {
      SafeLock(MT_LOCK_XDEL, NULL, RTF_INFINITE);
      MTXdelLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);

      Result = RTFDelete(FullPath);

      MTXdelLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_XDEL);

      return Result;
   }
   
   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(FullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
   }
   
   if (Result < RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, (BYTE *)FullPath);
      }
#endif
      return Result;
   }

   /* XDelete - 2 : Action */
   SafeLock(MT_LOCK_XDEL, NULL, RTF_INFINITE);
   MTXdelLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
   g_Xdelete = KAL_TRUE;

   Result = RecAUX_XDeleteFolder(FullPath, Flag | FS_XDEL_ABORT_WATCH, RecursiveStack, StackSize);

   g_Xdelete = KAL_TRUE;
   MTXdelLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_XDEL);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to move/copy a file or folder
PARAMETER
      SrcFullPath    : Source path to be moved/copied
      DstFullPath    : Destination path
      Flag           : FS_MOVE_COPY, FS_MOVE_KILL, FS_MOVE_OVERWRITE
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               RTF_FILE_EXISTS
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
NOTE
      1. Original RTFRename does not allow move to different drive
      2. Only can file to file or dir to dir
      3. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
#ifdef __FS_MOVE_SUPPORT__

int FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, UINT Flag, FS_ProgressCallback Progress,
            BYTE *RecursiveStack, const UINT StackSize)
{
   int  Result = RTF_NO_ERROR;
   int  Status = 0;
   int  Total  = 0;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_Move=> SrcPath: %s, DstPath: %s, Flag: 0x%x",
                                (BYTE *)SrcFullPath, (BYTE *)DstFullPath, Flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_MOVE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* XMove,XCopy - 1 : Mutex Init & Take Move Lock */
   if (Progress) Progress(FS_MOVE_PGS_PREPARE, 0, 0, 0);

   if (RTFLock == NULL)
      RTFInit();

   if (MTMoveLock == NULL)
      MTMoveLock = RTFSYSAllocMutex("MTMoveLock");

   SafeLock(MT_LOCK_MOVE, NULL, RTF_INFINITE);
   MTMoveLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)SrcFullPath[0]);
   MTMoveLock->DeviceNum_2 = FindDeviceNumberByDriveIdx((int)DstFullPath[0]);

   /* XMove,XCopy - 2 : Parameter Check */
   if ((kal_wstrcmp(SrcFullPath, DstFullPath) == 0)   || /* same path action */
       ((Flag &  (FS_MOVE_KILL | FS_MOVE_COPY)) == 0) || /* No action flag   */
       ((Flag & ~(FS_MOVE_KILL | FS_MOVE_COPY | FS_MOVE_OVERWRITE)) != 0) /* other flag not allowed */
      )
   {
      Result = RTF_PARAM_ERROR;
      goto MoveReturn;
   }

   /* XMove,XCopy - 3 : Test SrcFullPath & DstFullPath */
   Status = RecAUX_TestSrcAndDestPath(SrcFullPath, DstFullPath);
   if (Status < RTF_NO_ERROR) { Result = Status; goto MoveReturn; }
   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(SrcFullPath)
     || MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(SrcFullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
      goto MoveReturn;
   }

   /* XMove,XCopy - 4 : Operation Logical Check before Dispatch */
   if (Flag & FS_MOVE_KILL)
   {
      if (Status & MT_XMOVE_SRC_DEVICE_RO) { Result = RTF_WRITE_PROTECTION; goto MoveReturn; }
      if ((Status & MT_XMOVE_SRC_ATTR_RO) &&
          (Status & MT_XMOVE_SAME_DRIVE) == 0) { Result = MT_READ_ONLY_ERROR; goto MoveReturn; }
      if (Status & MT_XMOVE_SRC_IS_VIRTUAL) { Result = MT_READ_ONLY_ERROR; goto MoveReturn; }
   }
   if (Status & MT_XMOVE_DEST_EXIST)
   {
      if (Flag & FS_MOVE_OVERWRITE)
      {
         if (Status & MT_XMOVE_DEST_ATTR_RO) { Result = MT_READ_ONLY_ERROR; goto MoveReturn; }
         if (Status & MT_XMOVE_DEST_IS_FOLDER)
            Result = RecAUX_XDeleteFolder(DstFullPath, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, RecursiveStack, StackSize);
         else
            Result = RTFDelete(DstFullPath);
      }
      else
      {
         Result = RTF_FILE_EXISTS;
      }
      if (Result < RTF_NO_ERROR)
         goto MoveReturn;
   }

   /* XMove,XCopy - 5 : Operation Dispatch */
   if (Progress) Progress(FS_MOVE_PGS_START, 0, 0, 0);

   if ((Flag & FS_MOVE_KILL) && (Status & MT_XMOVE_SAME_DRIVE)) /* 5-1, move in same drive */
   {
      if (Progress) Progress(FS_MOVE_PGS_ING, 2, 1, 0);
      Result = RTFRename(SrcFullPath, DstFullPath);
      goto MoveReturn;
   }

   if ((Status & MT_XMOVE_SRC_IS_FOLDER) == 0) /* 5-2, move/copy 1 file */
   {
      // Check the same device and do speed up
      // 5-2-A
      if ((Status & (MT_XMOVE_SRC_IS_VIRTUAL|MT_XMOVE_SAME_DRIVE|MT_XMOVE_COPYSECTOR))
                  ==                        (MT_XMOVE_SAME_DRIVE|MT_XMOVE_COPYSECTOR))
      {
         Result = CopyFileOnSameDrive(SrcFullPath, DstFullPath, Progress);
      }
      // 5-2-B
      else
      {
         Result = CopyFileLightWeight(SrcFullPath, DstFullPath, Progress);
      }
      if (Result >= RTF_NO_ERROR && (Flag & FS_MOVE_KILL))
      {
         Result = RTFDelete(SrcFullPath);
      }
   }
   else /* 5-3, move/copy 1 folder */
   {
      RTFCreateDir(DstFullPath);

      Total = RecAUX_CountNumOfObjUnderFolderTree(SrcFullPath, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, RecursiveStack, StackSize);
      ASSERT (Total >= RTF_NO_ERROR);

      Result = RecAUX_XCopyFolder(SrcFullPath, DstFullPath, Status, Progress, (UINT) Total, RecursiveStack, StackSize);

      if (Result >= RTF_NO_ERROR && (Flag & FS_MOVE_KILL))
      {
         Result = RecAUX_XDeleteFolder(SrcFullPath, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, RecursiveStack, StackSize);
      }
   }

   /* XMove,XCopy - 6 : Operation Finished */
MoveReturn:
   if (Result < RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
#endif
      if (Progress) Progress(FS_MOVE_PGS_FAIL, 0, 0, 0);
   }

   if (Progress) Progress(FS_MOVE_PGS_DONE, 0, 0, 0);

   MTMoveLock->DeviceNum_1 = 0;
   MTMoveLock->DeviceNum_2 = 0;
   SafeUnlock(MT_LOCK_MOVE);

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}
#endif /* __FS_MOVE_SUPPORT__ */

#ifdef __P_PROPRIETARY_COPYRIGHT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FS_TRACE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FS_TRACE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FS_TRACE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif //__P_PROPRIETARY_COPYRIGHT__

#ifdef __P_PROPRIETARY_COPYRIGHT__
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
#ifdef __FS_TRACE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FS_TRACE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif //__P_PROPRIETARY_COPYRIGHT__

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility to get the first cluster (unique file/folder
      information in a drive).
PARAMETER
      FileHandle: User provides specified file handle
      Cluster:    The first cluster number to return
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILE_HANDLE
                  RTF_DATA_ERROR
NOTE
      If the file or folder does not have any content (first cluster is zero),
      you will get RTF_DATA_ERROR
------------------------------------------------------------------------------- */
int FS_GetFirstCluster(FS_HANDLE FileHandle, UINT * Cluster)
{
   int Result;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetFirstCluster=> FileHandle: %x", FileHandle);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETFIRSTCLUSTER, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   Result = GetFirstClusterByFileHandle(FileHandle, Cluster);
   if (Result == RTF_NO_ERROR && *Cluster == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_DATA_ERROR, NULL, NULL);
#endif
      return RTF_DATA_ERROR;
   }
   if (Result < RTF_NO_ERROR)
   {
      *Cluster = 0;
   }
   return Result;
}

/*************************************************************************
* FUNCTION
*    FS_OTPRead
*
* DESCRIPTION
*    This function implements the OTP read function, first it enter 
*    secured silicon sector, and read data from "Offset", totally read 
*    "Length" bytes, then exit secured silicon sector mode
*
* PARAMETERS
*    Offset: the start position want to read (unit:bytes)
*    BufferPtr: the buffer address want to read to
*    Length: total length want to read (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*
*************************************************************************/
int FS_OTPRead(int devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   RTFDevice * Dev;
   static int last_errcode;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_OTPRead=> devtype: %x", devtype);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_OTPREAD, NULL, (BYTE *)TraceTmpBuf);
   }
#endif
   /* OTP_Read - 1 : Find the Device */
   Dev = FindFirstDeviceByType(devtype);
   if (Dev == NULL)
   {
      return FS_UNSUPPORTED_DEVICE;
   }

   /* OTP_Read - 2 : Lock Device for concurrency */
   SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

   /* OTP_Read - 3 : Perform IO operation */
   if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
   {
      last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_READ, Offset, BufferPtr, Length);
   }
   else
   {
      last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* OTP_Read - 4 : Free Device for concurrency */
   SafeUnlock(MT_LOCK_DEV);

   return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPWrite
*
* DESCRIPTION
*    This function implements the OTP write function, first it enter 
*    secured silicon sector, and write data from "Offset", totally write 
*    "Length" bytes, then exit secured silicon sector mode.
*    Be carefully, do not set bit to one if it is zero
*
* PARAMETERS
*    Offset: the start position want to write (unit:bytes)
*    BufferPtr: the buffer address want to write from
*    Length: total length want to write (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*   FS_FLASH_OTP_WRITEFAIL: program error occur
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/
int FS_OTPWrite(int devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   RTFDevice * Dev;
   static int last_errcode;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_OTPWrite=> devtype: %x", devtype);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_OTPWRITE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif
   /* OTP_Write - 1 : Find the Device */
   Dev = FindFirstDeviceByType(devtype);
   if (Dev == NULL)
   {
      return FS_UNSUPPORTED_DEVICE;
   }

   /* OTP_Write - 2 : Lock Device for concurrency */
   SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

   /* OTP_Write - 3 : Perform IO operation */
   if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
   {
      last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_WRITE, Offset, BufferPtr, Length);
   }
   else
   {
      last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* OTP_Write - 4 : Free Device for concurrency */
   SafeUnlock(MT_LOCK_DEV);

   return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPLcok
*
* DESCRIPTION
*    This function implements the OTP lock function, 
*
* PARAMETERS
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/
int FS_OTPLock(int devtype)
{
   RTFDevice * Dev;
   static int last_errcode;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_OTPLock=> devtype: %x", devtype);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_OTPLOCK, NULL, (BYTE *)TraceTmpBuf);
   }
#endif
   /* OTP_Lock - 1 : Find the Device */
   Dev = FindFirstDeviceByType(devtype);
   if (Dev == NULL)
   {
      return FS_UNSUPPORTED_DEVICE;
   }

   /* OTP_Lock - 2 : Lock Device for concurrency */
   SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

   /* OTP_Lock - 3 : Perform IO operation */
   if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
   {
      last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_LOCK, NULL, NULL, NULL);
   }
   else
   {
      last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* OTP_Lock - 4 : Free Device for concurrency */
   SafeUnlock(MT_LOCK_DEV);

   return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPQueryLength
*
* DESCRIPTION
*    This function implements the OTP length query function, 
*
* PARAMETERS
*    Length: total length pointer to be get (unit: byte)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*
*************************************************************************/
int FS_OTPQueryLength(int devtype, kal_uint32 *Length)
{
   RTFDevice * Dev;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_OTPQueryLength=> devtype: %x", devtype);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_OTPQUERYLENGTH, NULL, (BYTE *)TraceTmpBuf);
   }
#endif
   /* OTP_QueryLength - 1 : Find the Device */
   Dev = FindFirstDeviceByType(devtype);
   if (Dev == NULL)
   {
      return FS_UNSUPPORTED_DEVICE;
   }

   /* OTP_QueryLength - 2 : Check IO operation */
   if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
   {
      Dev->Driver->OTPQueryLength(Dev->DriverData, Length);
   }
   else
   {
      return FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   return FS_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to reclaim flash disk,
      piece by piece!!
PARAMETER
      DriveType: The DeviceType , NOR, NAND, ...
RETURN
      Success: RTF_NO_ERROR
      Retry:   RTF_CHECKDISK_RETRY
      Error:   RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_SweepDevice(const int DeviceType)
{
   static UINT LastDeviceType = 0xffffffff;
   static RTFDrive *LastDrive = NULL;
   static RTFCluster LastCluster;
   RTFDevice *Dev;
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_SweepDevice => DeviceType: %x", DeviceType);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_SWEEPDEVICE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* FS_SweepDrive - 1 , Check if the state hold */
   if (LastDeviceType != DeviceType)
   {
      Dev = FindFirstDeviceByType(DeviceType);
      if (Dev == NULL)
      {
         return RTF_PARAM_ERROR;
      }
      LastDeviceType = DeviceType;
      LastDrive      = Dev->DevData.FirstDrive;
      LastCluster    = 2;
   }

   /* FS_SweepDrive - 2 , Call the routine to discard sector piece by piece */
   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, LastDrive->Dev, RTF_INFINITE);
   Result = CleanUpDataSectors(LastDrive, &LastCluster, 128);
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   /* FS_SweepDrive - 3 , Return Continue/Stop indication */
   if (Result < 0 && LastCluster >= LastDrive->Clusters)
   {
      Dev = FindFirstDeviceByType(DeviceType); /* Need to reterive again */
      if (LastDrive->NextDrive != NULL)
      {
         LastDrive   = LastDrive->NextDrive;
         LastCluster = 2;
      }
      else
      {
         return RTF_NO_ERROR;
      }
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return RTF_CHECKDISK_RETRY;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provide various kinds of query about number of file handles
PARAMETER
      flag:  FS_FH_COUNT_CONFIGURED,
             FS_FH_COUNT_USED,
             FS_FH_COUNT_AVAILABLE,
             FS_FH_COUNT_CURRENT_TASK
RETURN
      >= 0: the number of file handles.
      Error:   RTF_PARAM_ERROR
      
------------------------------------------------------------------------------- */
int FS_CountUsedFH(int flag)
{
   int Result;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_CountUsedFH=> flag : %d ", flag);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_COUNTUSEDFH, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   switch (flag)
   {
      case FS_FH_COUNT_CURRENT_TASK:
         Result = CountUsedFH(kal_get_current_thread_ID());
         break;

      case FS_FH_COUNT_AVAILABLE:
         Result = FS_MAX_FILES - CountUsedFH(NULL);
         break;

      case FS_FH_COUNT_USED:
         Result = CountUsedFH(NULL);
         break;

      case FS_FH_COUNT_CONFIGURED:
         Result = FS_MAX_FILES;
         break;

      default:
         Result = FS_PARAM_ERROR;
         break;
   }

#ifdef __FS_DEBUG__
   kal_check_stack();
#endif

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to let task looks up the
      number of partitions on the specified device
PARAMETER
      QueryTarget: the index number get from FS_GetDrive
              OR the type enum get from FS_GetDevType
RETURN
      Success:  Number of partitions on the specified device
      Error:    RTF_PARAM_ERROR
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */
int FS_GetDevPartitions(UINT QueryTarget)
{
   RTFDrive * Drive = NULL;
   RTFDevice * Dev = NULL;

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_GetDevPartitions=> Target: 0x%X", QueryTarget);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , 0, API_ENUM_GETDEVPARTITIONS, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   // locate Drive by index , or find it by type flag
   if (QueryTarget >= MT_BASE_DRIVE_LETTER && QueryTarget < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[QueryTarget - MT_BASE_DRIVE_LETTER];
   }
   else if (QueryTarget < FS_DEVICE_TYPE_MAX_VALUE)
   {
      Dev = FindFirstDeviceByType(QueryTarget);
   }

   // Return if neither Dev nor Drive found
   if (Drive == NULL && Dev == NULL)
   {  // Fall through... and return PARAM_ERROR
   }
   else
   {  int count;
      if (Dev == NULL)
      {
         Dev = Drive->Dev;
      }
      // Now Do Counting job

      for(count = 0, Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive, count++);
      return count;
   }

#ifdef __FS_TRACE_SUPPORT__
   if (g_TraceFlag & MT_TRACE_ERROR)
   {
      kal_sprintf(TraceTmpBuf, "Get Dev Partitions Query Target: 0x%x, FindDev: %x", QueryTarget, (UINT)Dev);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   return RTF_PARAM_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility to force mount the removable device
PARAMETER
      None 
RETURN
      Success: RTF_NO_ERROR
      Error:   
NOTE
 ------------------------------------------------------------------------------- */
int FS_MountRemovableDevice(void)
{
    if (FindFirstDeviceByType(FS_DEVICE_TYPE_CARD) != NULL)
    {
       return MountRemovableDevice( FindFirstDeviceByType(FS_DEVICE_TYPE_CARD) );
    }
    return FS_UNSUPPORTED_DEVICE;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to recover flash disk,
PARAMETER
      DriveType: The DeviceType , NOR, NAND, ...
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_RecoverDevice(const int DeviceType)
{
   RTFDevice *Dev;
   RTFDrive  *Drive;
   int Result = RTF_NO_ERROR;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & FS_TRACE_API)
   {
      kal_sprintf(TraceTmpBuf, "FS_RecoverDevice=> DeviceType: %x", DeviceType);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((UINT)kal_get_task_self_id(), 2 , 0, API_ENUM_RECOVERDEVICE, NULL, (BYTE *)TraceTmpBuf);
   }
#endif

   /* FS_RecoverDevice - 1 , Get the device */
   Dev = FindFirstDeviceByType(DeviceType);
   if (Dev == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, FS_PARAM_ERROR, NULL, NULL);
      }
#endif
      return FS_PARAM_ERROR;
   }

   /* FS_RecoverDevice - 2 , see if function supported */
   if (Dev->DeviceFlags & FS_DEVICE_REMOVABLE)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, FS_UNSUPPORTED_DEVICE, NULL, NULL);
      }
#endif
      return FS_UNSUPPORTED_DEVICE;
   }

   if (Dev->Driver->RecoverDisk == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, FS_UNSUPPORTED_DRIVER_FUNCTION, NULL, NULL);
      }
#endif
      return FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* FS_RecoverDevice - 3 , do it and unmount all associated drive and the device */
   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);

   Result = Dev->Driver->RecoverDisk(Dev->DriverData);

   for ( Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
   {
      Drive->MountState = NotMounted;
   }
   Dev->DevData.MountState = NotMounted;
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   if (Result < FS_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_current_thread_ID(), 2 , __LINE__, Result, NULL, NULL);
      }
#endif
   }
   return Result;
}
