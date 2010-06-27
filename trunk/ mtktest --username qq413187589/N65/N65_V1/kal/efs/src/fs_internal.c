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
 *     fs_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file defines the internals of file system abstraction layer
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
#include <stdio.h>
#include "kal_release.h"
#include "app_buff_alloc.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "fs_kal.h"
#include "fs_type.h"
#include "fs_internal.h"

/************************* Internal Use *************************/
//Global Data
#ifdef __FS_CHECKDRIVE_SUPPORT__
kal_bool g_CheckDrive = KAL_FALSE;
#endif

// External & Dynamic Device
kal_bool g_ExternalDevice = KAL_FALSE; // init as not configured 

// Abort Mechanism
kal_bool  g_Xdelete   = KAL_TRUE; //must be init with true

//Outside Function
extern void nvram_space_reserve(kal_uint32 *size_from_code);
extern void nvram_get_folder_name(WCHAR *nvram_folder_name);
extern int Check_NORFlash_Formatted(void);
extern kal_uint32 L1I_GetTimeStamp(void);

#ifdef __FS_SORT_SUPPORT__
static int InsertSort(UINT Target, RTFDirLocation * Pos, UINT Value, UINT Index, RTFDirLocation * PosList, UINT * Hex);
#endif

#ifdef __FS_QM_SUPPORT__ 
static int FolderInQuotaSet(WCHAR * Folder);
#endif

#ifdef __FS_CHECKDRIVE_SUPPORT__
static int        ScanFindFirst(WCHAR * NamePattern, RTFDirEntry * DirPos);
static int        ScanFindNext(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos);
static void       ScanFATDelete(InternScanDataStruct *SDCD, RTFCluster Cluster);
#endif

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
#endif

/* ---------------------------------------------------------------------------------- */
/* Conventions For Source Code Maintain in fs_internal.c                              */
/* > *Must* put FS Trace Log with XRAISE error in rtfiles.c and fs_func.c             */
/*   however, sub-routines here usually are middleware between rtfiles and fs_func    */
/*   you may skip FS Trace if the XRAISE doesn't need log                             */
/* ---------------------------------------------------------------------------------- */

/* Close all files on this device and then discard all related buffer */
void CloseDevice(RTFDevice * Dev)
{
   int i;
   RTFile * f;
      
   if(Dev == NULL) return;
   //Lock RTF and device before calling this function
   FlushAllBuffers(Dev);
   DiscardAllBuffers(Dev);
   
   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Lock != 0) && (f->Dev == Dev))
      {
         //don't call RTFClose here cuz it will unmount device
         FreeFTSlot(f);      
      }
   }   
   //should not unlock here
}
/* ------------------------------------------------------------------------------- */
/* Lookup device number by DriveLetter , 0 if not found */
int FindDeviceNumberByDriveIdx(int DriveIdx)
{
   RTFDrive * Drive = NULL;

   // locate Drive by index , or find it by type flag
   if (DriveIdx == (BYTE)DrvMappingNew) //Capital 'Z'
   {
      Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
      return Drive->Dev->DeviceNumber;
   }
   else if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
      return Drive->Dev->DeviceNumber;
   }
   return 0;
}
/* ------------------------------------------------------------------------------- */
/* Lookup device type by translate to flag query */
RTFDevice * FindFirstDeviceByType(FS_DEVICE_TYPE_ENUM dtype)
{
   UINT match;
   RTFDevice * Dev = gFS_DeviceList;

   switch(dtype)
   {
      case FS_DEVICE_TYPE_NOR:
         match = MT_DEVICE_NOR_FLASH;
         break;

      case FS_DEVICE_TYPE_NAND:
         match = MT_DEVICE_NAND_FLASH;
         break;

      case FS_DEVICE_TYPE_EXTERNAL:
         match = MT_DEVICE_EXTERNAL;
         break;

      case FS_DEVICE_TYPE_CARD:
         match = RTF_DEVICE_REMOVABLE;
         break;

      case FS_DEVICE_TYPE_SIMPLUS:
         match = MT_DEVICE_SIMPLUS;
         break;

      default: /* WRONG PARAMETER */
         return NULL;
   }

   for (; Dev->DeviceType; Dev++)
   {
      if (Dev->DeviceFlags & match)
      {
         return Dev;
      }
   }
   return NULL;
}

/* ------------------------------------------------------------------------------- */
/* Mount FS on the Removable Device
 * NOTE: This sub-routine DO NOT check argument, use it careful!!
 */
int MountRemovableDevice(RTFDevice *Dev)
{
   int Result2 = RTF_NO_ERROR;

#ifndef __PRODUCTION_RELEASE__
   ASSERT(Dev != NULL);
#endif

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
         DiscardAllBuffers(Dev);
         /* Here we assume only one drive on the dev */
         MountLogicalDrive(Dev->DevData.FirstDrive, HasFileSystem);
         break;
      default:
         if (XVALUE == MT_MSDC_MOUNT_ERROR)
      	 {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "DevFlags: %x; DriverData: %x",
                           Dev->DeviceFlags, (unsigned int) Dev->DriverData);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_MSDC_MOUNT_ERROR, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
      	 }
      	 else
         {
            XTRY
               case XCODE:
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
//                  if ((Dev->DeviceFlags & MT_DEVICE_SIMPLUS) == 0) // There may be also no MBR in simplus card
                     Dev->DeviceType = RTF_DEVICE_FLOPPY;
                  MountLogicalDrive(Dev->DevData.FirstDrive, HasFileSystem);
                  break;
               default:
                  XHANDLED;
                  Result2 = XVALUE;
                  Dev->DevData.MountState = NotMounted;
                  break;
               case XFINALLY:
                  Dev->DeviceType = FS_DEVICE_FDISK;
                  break;
            XENDX
            /* XTRY ~ XENDX Block don't return directly */
            if (Result2 == RTF_NO_ERROR)
               XVALUE = RTF_NO_ERROR;
            else
            {
               XVALUE = MT_MSDC_MOUNT_ERROR;
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "DevFlags: %x; DriverData: %x",
                              Dev->DeviceFlags, (unsigned int) Dev->DriverData);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result2, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
            }
         }
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
/* Mount Drive and Issue BatchCountFreeClusters on the Fixed Device Again
 * NOTE: This sub-routine DO NOT check argument, use it careful!!
 */
int ReMountDriveAndCountFreeClusters(RTFDrive *Drive)
{
   int Result = RTF_NO_ERROR;

#ifndef __PRODUCTION_RELEASE__
   ASSERT(Drive != NULL);
#endif

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         DiscardAllBuffers(Drive->Dev);
         MountLogicalDrive(Drive, HasFileSystem);
         BatchCountFreeClusters(Drive);
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return Result;
}

/* ------------------------------------------------------------------------------- */
int ReleaseFH(void * TaskId)
{
   RTFile * f;
   UINT i;
      
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      
   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if (TaskId)
      {
         if (f->Task == TaskId)
            FreeFTSlot(f);
      }
      else if ((f->Task == kal_get_current_thread_ID()) && (f->Task != NULL))
      {         
         FreeFTSlot(f);   
      }
   }   
   
   RTFSYSFreeMutex(RTFLock);
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int CountUsedFH(void * TaskId)
{
   RTFile * f;
   UINT i;
   int  Result=0;
      
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      
   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if (TaskId)
      {
         if (f->Task == TaskId) Result++;
      }
      else if (f->Unique)
      {
         Result++;
      }
   }   
   
   RTFSYSFreeMutex(RTFLock);
   return Result;
}
/* ------------------------------------------------------------------------------- */
/* Copy file to file, this function get at least 512B mem */
#ifdef __FS_MOVE_SUPPORT__

static int CopyFileSyncLastDateTime(RTFHANDLE FileSrc, RTFHANDLE FileDst)
{
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;

   XTRY
      case XCODE:
         f1 = ParseFileHandle(FileSrc);
         /* do-not sync date time with virtual file file handle */
         if (f1->SpecialKind == FileMapFile) break;
         RTFSYSFreeMutex(RTFLock);
         f2 = ParseFileHandle(FileDst);

         f2->DirEntry.Dir.DateTime = f1->DirEntry.Dir.DateTime;
         f2->DirEntry.Dir.FileSize = f1->DirEntry.Dir.FileSize;
         // inherit the attributes in copying process
         f2->DirEntry.Dir.Attributes = f1->DirEntry.Dir.Attributes;
         UpdateDirEntry(f2);
         break;
      default:
         break;
      case XFINALLY:
         if (f2 != NULL) /* imply f1 != NULL, see above */
         {
            UnlockDevice(f2->Dev);
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            UnlockDevice(f1->Dev);
         }
         else if (f1 != NULL)
         {
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, f1->Dev, RTF_INFINITE); /* it may raise an exception after release the system lock */
            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API
   return RTF_NO_ERROR;
}

int CopyFileLightWeight(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress)
{
   RTFHANDLE FHandle1 = NULL, FHandle2 = NULL;
   int volatile Result = RTF_NO_ERROR;
   kal_char *Content = NULL;
   UINT wLength1, wLength2 = 0, wLength3 = 0;
   UINT allLength = 0, okLength = 0;
   kal_uint32  LastPgsTime;
   
   
   Content = get_ctrl_buffer(CopyBufferSize);

   FHandle1 = RTFOpen(SrcFullPath, RTF_READ_ONLY | RTF_OPEN_NO_DIR);  
   if (FHandle1 < RTF_NO_ERROR)
   {
      Result = FHandle1;
      goto CopyReturn;
   }            

   RTFGetFileSize(FHandle1, &wLength1);

   FHandle2 = RTFOpen(DstFullPath, RTF_READ_WRITE | RTF_OPEN_NO_DIR | RTF_CREATE);
   if (FHandle2 < RTF_NO_ERROR)
   {
      Result = FHandle2;
      goto CopyReturn;
   }

   allLength = wLength1*2; //Read then write should double
   LastPgsTime = L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK;

   while(wLength1 > 0)
   {      
      if (wLength1 >= CopyBufferSize) 
      {
         wLength2 = CopyBufferSize;
         wLength1 -= CopyBufferSize;
      }
      else
      {
         memset(Content, 0, CopyBufferSize); //reduce time, do it here only
         wLength2 = wLength1;
         wLength1 = 0;
      }

      Result = RTFRead(FHandle1, Content, wLength2, &wLength3);
      if (Result < RTF_NO_ERROR)
         goto CopyReturn;      
               
      Result = RTFWrite(FHandle2, Content, wLength2, &wLength3);
      if (Result < RTF_NO_ERROR)
         goto CopyReturn;   
         
      okLength += wLength3*2;

      if (Progress != NULL)
      {
         if (LastPgsTime != (L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK))
         {
            LastPgsTime = L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK;
            Progress(FS_MOVE_PGS_ING, allLength, okLength, FHandle1); 
         }
      }
   }

   CopyFileSyncLastDateTime(FHandle1, FHandle2);

CopyReturn:
   if(Content) free_ctrl_buffer(Content);
   if(FHandle1 > 0) RTFClose(FHandle1);
   if(FHandle2 > 0) RTFClose(FHandle2);
   if(Result < RTF_NO_ERROR)
   {
      int Tmp_Result;
      Tmp_Result = RTFDelete(DstFullPath);
#ifdef __FS_TRACE_SUPPORT__
      if(Tmp_Result < RTF_NO_ERROR)
      {
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "DstFullPath: %s", DstFullPath);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 3, __LINE__, Tmp_Result, NULL, (BYTE *)TraceTmpBuf);
         }
      }
#endif
   }
   return Result;
}

/* This subroutine fetch continguous cluster chain and fill into ClusterArray */
static int CopyFileListClusterChain(RTFHANDLE FileSrc, RTFCluster *ClusterArray, int ArraySize, UINT *CurrFilePointer)
{
   RTFile * volatile f1 = NULL;
   int      volatile idx=0;

   XTRY
      case XCODE:
         f1 = ParseFileHandle(FileSrc);
         if (f1->Cluster != 0)
         {
            while (f1->Cluster < RTF_CLUSTER_CHAIN_END && idx < ArraySize)
            {
               if (f1->Valid == MT_ENUM_FH_ABORTED)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_ABORTED_ERROR, NULL, NULL);
#endif
                  XRAISE(MT_ABORTED_ERROR);
               }
               ClusterArray[idx++] = f1->Cluster;
               f1->LastCluster = f1->Cluster;
               f1->Cluster = GetClusterValue(f1->Drive, f1->LastCluster);
               f1->FilePointer += f1->Drive->ClusterSize;
               if (f1->Cluster != f1->LastCluster + 1) break;
            }
         }
         *CurrFilePointer = f1->FilePointer;
         break;
      default:
         break;
      case XFINALLY:
         if (f1 != NULL) UnlockDevice(f1->Dev);
         break;
   XEND_API
   return idx;
}

int CopyFileOnSameDrive(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress)
{
   RTFHANDLE   FHandle1 = NULL, FHandle2 = NULL;
   RTFCluster *ClustersArray = NULL;
   int         ReadCluster, WrittenCluster;
   int volatile Result = RTF_NO_ERROR;
   UINT allLength = 0, okLength = 0;
   kal_uint32  LastPgsTime;
   
   FHandle1 = RTFOpen(SrcFullPath, RTF_READ_ONLY | RTF_OPEN_NO_DIR);  
   if (FHandle1 < RTF_NO_ERROR)
   {
      Result = FHandle1;
      goto CopyReturn;
   }            

   FHandle2 = RTFOpen(DstFullPath, RTF_READ_WRITE | RTF_OPEN_NO_DIR | RTF_CREATE);
   if (FHandle2 < RTF_NO_ERROR)
   {
      Result = FHandle2;
      goto CopyReturn;
   }

   ClustersArray  = get_ctrl_buffer(512);
   memset(ClustersArray, 0xFF, 512); //reduce time, do it here only

   RTFGetFileSize(FHandle1, &allLength);
   LastPgsTime = L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK;

   /* Fill Contingous Clusters Chain into ClustersArray */
   ReadCluster = CopyFileListClusterChain(FHandle1, ClustersArray, FS_MAX_COPY_CLUSTER, &okLength);
   while (ReadCluster > 0)
   {
      /* Copy to Destination file */
      WrittenCluster = MTCopyFileByClusterChain(FHandle2, ClustersArray, ReadCluster);
      if (WrittenCluster < 0)
      {
         Result = WrittenCluster;
         goto CopyReturn;
      }

      /* Check Progress */
      if (Progress != NULL)
      {
         if (LastPgsTime != (L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK))
         {
            LastPgsTime = L1I_GetTimeStamp() & MT_PGS_PERIOD_MASK;
            Progress(FS_MOVE_PGS_ING, allLength, okLength, FHandle1);
         }
      }

      /* Fill Contingous Clusters Chain into ClustersArray, Iteration */
      ReadCluster = CopyFileListClusterChain(FHandle1, ClustersArray, FS_MAX_COPY_CLUSTER, &okLength);
   }

   if (ReadCluster == 0)
   {
      CopyFileSyncLastDateTime(FHandle1, FHandle2);
   }
   else
   {
      Result = ReadCluster;
   }

CopyReturn:
   if (ClustersArray) free_ctrl_buffer(ClustersArray);
   if (FHandle1 > 0) RTFClose(FHandle1);
   if (FHandle2 > 0) RTFClose(FHandle2);
   if (Result < RTF_NO_ERROR)
   {
      int Tmp_Result;
      Tmp_Result = RTFDelete(DstFullPath);
#ifdef __FS_TRACE_SUPPORT__
      if(Tmp_Result < RTF_NO_ERROR)
      {
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "DstFullPath: %s", DstFullPath);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 3, __LINE__, Tmp_Result, NULL, (BYTE *)TraceTmpBuf);
         }
      }
#endif
   }
   return Result;
}
#endif /* __FS_MOVE_SUPPORT__ */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/* ------------------------------------------------------------------------------- */
/* This function do "cd..". This function will keep the last back slash */
static int CdUp(WCHAR * Path)
{
   UINT idx;
   if(Path[kal_wstrlen((WCHAR *)Path)-1] == 0x5C)
   {
      Path[kal_wstrlen((WCHAR *)Path)-1] = 0;
      Path[kal_wstrlen((WCHAR *)Path)] = 0;
   }
   idx = kal_wstrlen((WCHAR *)Path);
   while((Path[idx] != 0x5C) && (idx > 0))
   {
      Path[idx] = 0;
      idx--;
   }
   return idx;
}
#endif

/* ------------------------------------------------------------------------------- */
/* Insert a node to sort list */
#ifdef __FS_SORT_SUPPORT__

static int InsertSort(UINT Target, RTFDirLocation * Pos, UINT Value, UINT Index, RTFDirLocation * PosList, UINT * Hex)
{
   int i, Max; //cannot be UINT
   
   Max = (Index < (MT_MAX_FILE_NUM - 2))? (Index-1) : (MT_MAX_FILE_NUM - 2);
   
   for(i=Max; i>=Target; i--)
   {
      if(i < 0) break;
      if(PosList[i].Cluster)
      {
         PosList[i+1].Cluster = PosList[i].Cluster;
         PosList[i+1].Index = PosList[i].Index;
         Hex[i+1] = Hex[i];
      }
   }
   PosList[Target].Cluster = Pos->Cluster;
   PosList[Target].Index = Pos->Index;
   Hex[Target] = Value;
   
   return RTF_NO_ERROR;
}

#endif

/* ------------------------------------------------------------------------------- */
/* Speedup find for sort */
#ifdef __FS_SORT_SUPPORT__

int GetFindByPos(const WCHAR * Pattern, RTFDOSDirEntry * FileInfo, WCHAR * FileName, 
                 UINT MaxLength, RTFDirLocation * Pos, UINT Flag)
{
   int volatile Result = RTF_NO_ERROR; 
   RTFDOSDirEntry * D;
   LFNDirEntry * LD;
   int Kind, LFNIndex = -1;
   RTFDrive * Drive;   
   RTFDirLocation Pos_Copy;
   
   if (DrvMappingNew == (int) Pattern[0])
   {
      Drive = &gFS_Data.DriveTable[DrvMappingOld - (int) MT_BASE_DRIVE_LETTER];
   }
   else if ( (Pattern[0] >= (WCHAR) MT_BASE_DRIVE_LETTER) &&
             (((int) Pattern[0] - (int) MT_BASE_DRIVE_LETTER) < FS_MAX_DRIVES) )
   {
      Drive = &gFS_Data.DriveTable[(int) Pattern[0] - (int) MT_BASE_DRIVE_LETTER];
   }
   else
   {
      /* XXX : Not RTF_DRIVE_NOT FOUND */
      return RTF_PATH_NOT_FOUND;
   }

   Pos_Copy.Cluster = Pos->Cluster;
   Pos_Copy.Index = Pos->Index;
   
   XTRY //exception handler for GetDir
      case XCODE:   
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
               
         D = GetDir(Drive, &Pos_Copy); //check for current dir entry
         
         if(D == NULL) 
            return RTF_NO_MORE_FILES;
            
         Kind = EntryType(D);

         if(Kind != InUse) //try to make LFN
         {            
            WCHAR * FindName = NULL;
            UINT FindLength;
            kal_bool Release_Mem = KAL_FALSE;
            
            if(Kind == Lfn)
            { 
               if(Flag == FS_FIND_LFN_TRUNC)
               {
                  FindName = get_ctrl_buffer(MT_MAX_WIDE_NAME);
                  if(FindName == NULL)
                     goto GetFindByPosNotTrunc;
                  Release_Mem = KAL_TRUE;
                  memset(FindName, 0, MT_MAX_WIDE_NAME);
                  FindLength = MT_MAX_WIDE_NAME;
               }
               else
               {
GetFindByPosNotTrunc:               
                  FindName = FileName;
                  FindLength = MaxLength;
               }
            }
            
            while(Kind == Lfn)
            {
               LD = (void*) D;
               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
      
                  Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));
                  if (Limit > (((char *)FindName) + FindLength - 1))
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }               
               if(LFNIndex != (LD->Ord & 0x3F))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FindName + --LFNIndex * 26, LD);         
               
               D = NextDir(Drive, &Pos_Copy);
               Kind = EntryType(D);
            }
            if (LFNIndex == 0) //forget checksum to speedup
            {
               if(Release_Mem)
               {
                  WORD i;
                  for(i = 0 ; i < (MaxLength/2 - 1); i++)
                     FileName[i] = FindName[i];
                  FileName[i] = 0x0000;
                  free_ctrl_buffer(FindName);
               }
               if(FileInfo)
               {
                  *FileInfo = *D;   
                  FileInfo->NTReserved = MT_ENUM_FIND_LFN;
               }                       
               break;
            }            
         }                 
                  
         if((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
         {
            FileNameExtendToWCHAR((char *)FileName);
            if(FileInfo)
            {
               *FileInfo = *D;   
               /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
               if (FileInfo->FileName[0] == 0x05)
                  FileInfo->FileName[0] = 0xE5;
               /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
               FileInfo->NTReserved = MT_ENUM_FIND_SFN;
            }             
            MTCheckFileNameCase(FileName, MaxLength, D->NTReserved);
            break;
         }         
         else
            XRAISE(RTF_NO_MORE_FILES);
            
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API         
   
   return Result;
}      
                          
#endif

/* ------------------------------------------------------------------------------- */
/* Sort function for sorting by file name, type, size, date */
#ifdef __FS_SORT_SUPPORT__
int Sort(const WCHAR * FileName, WCHAR * TmpName, RTFDOSDirEntry * FileInfo, UINT Flag, 
         RTFDirLocation * PosList, UINT * Hex, UINT Index, const WCHAR * Pattern, 
         RTFDirLocation * Pos)
{
   UINT i = 0, j = 0, Value = 0;
   int Result = RTF_NO_ERROR;     
   int Guard_1 = Index-1, Guard_2 = -1, Range;

   if(Flag & FS_SORT_NAME)
   {                           
      Value = wchartoupper(FileName[0])*256*256 + wchartoupper(FileName[1]);
            
      i = (Index-1)/2;
      while(1)
      {                
SortNameStart:                    
         if(PosList[i].Cluster == 0) 
         {
            PosList[i].Cluster = Pos->Cluster;
            PosList[i].Index = Pos->Index;
            Hex[i] = Value;
            goto SortReturn;
         }
         if(Value < Hex[i])
         {
SortNameCheck:        
            if(i == 0)
            {
               InsertSort(i, Pos, Value, Index, PosList, Hex);
               goto SortReturn;                           
            }                            
            Guard_1 = i;
            Range = (i - Guard_2)/2;               
            if(Range)
               i -= Range;
            else            
               i--;
            if((i <= Guard_2) && (Guard_2 >= 0))
            {
               i++;
               InsertSort(i, Pos, Value, Index, PosList, Hex);
               goto SortReturn;                           
            }                           
            goto SortNameStart;
         }
         else if(Value == Hex[i])
         {            
            memset(TmpName, 0, MT_MAX_WIDE_NAME);            
            Result = GetFindByPos(Pattern, FileInfo, TmpName, MT_MAX_FILE_NUM, &PosList[i], FS_FIND_DEFAULT);  
            if(Result < RTF_NO_ERROR)
               goto SortReturn;
                           
            for(j=2; j<=RTF_MAX_PATH; j++)
            {          
               if(((FileName[j] == NULL) && (TmpName[j] == NULL)) ||
                   (wchartoupper(FileName[j]) > wchartoupper(TmpName[j])))
                  break;
               if(wchartoupper(FileName[j]) < wchartoupper(TmpName[j]))
                  goto SortNameCheck;
            }
         }
         Guard_2 = i;
         Range = (Guard_1 - i)/2;
         if(Range)
            i += Range;
         else
            i++;
         if(i >= Guard_1)
         {
            InsertSort(i, Pos, Value, Index, PosList, Hex);
            goto SortReturn;                           
         }
      }      
   }
   else if(Flag & FS_SORT_TYPE)
   {            
      UINT TypeIdx = 0;               
      char * sPtr;      
         
      sPtr = kal_dchar_strrchr((char *)FileName, 0x002e);
      if(sPtr)
      {
         sPtr += 2;
         TypeIdx = (sPtr - (char *)FileName)/2;
         Value = wchartoupper(FileName[TypeIdx])*256*256 + wchartoupper(FileName[TypeIdx+1]);
      }
         
      i = (Index-1)/2;
      while(1)
      {                
SortTypeStart: 
         if(PosList[i].Cluster == 0) 
         {
            PosList[i].Cluster = Pos->Cluster;
            PosList[i].Index = Pos->Index;
            Hex[i] = Value;
            goto SortReturn;
         }
         if(Value < Hex[i])
         {
SortTypeCheckAhead:        
            if(i == 0)
            {
               InsertSort(i, Pos, Value, Index, PosList, Hex);
               goto SortReturn;                           
            }                            
            Guard_1 = i;
            Range = (i - Guard_2)/2;               
            if(Range)
               i -= Range;
            else            
               i--;
            if((i <= Guard_2) && (Guard_2 >= 0))
            {
               i++;
               InsertSort(i, Pos, Value, Index, PosList, Hex);
               goto SortReturn;                           
            }                           
            goto SortTypeStart;
         }
         else if(Value == Hex[i])
         {
            UINT CheckPoint; 
            int OffSet;
            kal_bool ExtNameTieFlag = KAL_FALSE;
            char * TmpsPtr;
            UINT TmpDotIdx;
            
            /* Now first 2 WCHAR of extension name is the same,
             * fetch full name and compare from 3rd WCHAR of extension name
             */
            memset(TmpName, 0, MT_MAX_WIDE_NAME);            
            Result = GetFindByPos(Pattern, FileInfo, TmpName, MT_MAX_FILE_NUM, &PosList[i], FS_FIND_DEFAULT);  
            if(Result < RTF_NO_ERROR)
               goto SortReturn;
            
            if(TypeIdx == 0 || (Value & 0x0000FFFF) == 0x00000000)
            { /* There is no extension name on both filename,
               * or just singular WCHAR extension name on both filename,
               * or the extension name are compared and tie to tie.
               */
SortTypeTie:   ExtNameTieFlag = KAL_TRUE;
               CheckPoint = 0;
               OffSet = 0;
               goto SortTypeContinue;
            }else
            {
               TmpsPtr = kal_dchar_strrchr((char *)TmpName, 0x002e);
               TmpDotIdx = (TmpsPtr - (char *)TmpName)/2 + 1;
               OffSet = TmpDotIdx - TypeIdx;
               CheckPoint = TypeIdx + 2;
            }
               
SortTypeContinue:
            for(j=CheckPoint; j<=RTF_MAX_PATH; j++)
            {          
               if((FileName[j] == NULL) && (TmpName[j+OffSet] == NULL))
               {
                  if(ExtNameTieFlag == KAL_FALSE)
                  {  goto SortTypeTie;}
                  break;
               }
               if((TmpName[j+OffSet] == 0x2E) || (wchartoupper(FileName[j]) > wchartoupper(TmpName[j+OffSet])))
                  goto SortTypeCheckBehind;
               if((FileName[j] == 0x2E) || wchartoupper(FileName[j]) < wchartoupper(TmpName[j+OffSet]))
                  goto SortTypeCheckAhead;
            }
         }

         /* ELSE : Value > Hex[i] { */
SortTypeCheckBehind:
         Guard_2 = i;
         Range = (Guard_1 - i)/2;
         if(Range)
            i += Range;
         else
            i++;
         if(i >= Guard_1)
         {
            InsertSort(i, Pos, Value, Index, PosList, Hex);
            goto SortReturn;                           
         }               
         /* } ELSE : Value > Hex[i] */

      } /* while(1) */
   }
   else if(Flag & FS_SORT_ATTR)
   {
      Value = FileInfo->Attributes;
   }
   else if(Flag & FS_SORT_SIZE)
   {
      Value = FileInfo->FileSize;
   }   
   else if(Flag & FS_SORT_TIME)
   {      
      Value = (FileInfo->DateTime.Year1980*12*31*24*60*60) +
              (FileInfo->DateTime.Month*31*24*60*60) +
              (FileInfo->DateTime.Day*24*60*60) +
              (FileInfo->DateTime.Hour*60*60) +
              (FileInfo->DateTime.Minute*60) +
              (FileInfo->DateTime.Second2);
   }
   else
   {
      Result = RTF_PARAM_ERROR;
      goto SortReturn;
   }
      
   for(i=0; i<Index; i++)
   {
      if(PosList[i].Cluster == 0) 
      {
         PosList[i].Cluster = Pos->Cluster;
         PosList[i].Index = Pos->Index;
         Hex[i] = Value;
         break;
      }            
      if(Value < Hex[i])
      {
         InsertSort(i, Pos, Value, Index, PosList, Hex);         
         break;
      }
   }         
SortReturn:   
   return Result;
}

#endif

/* ------------------------------------------------------------------------------- */
/* Special FinFirst for FindReset */
int FindFirst(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, UINT PatternNum, 
              BYTE ArrayMask, BYTE Attr, BYTE AttrMask, RTFDOSDirEntry * FileInfo, 
              WCHAR * FileName, UINT MaxLength, RTFDirLocation * Pos_Hint)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   //const RTFDOSDirEntry * D;
   RTFDirLocation * Pos;
   BYTE * volatile A;

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))
         {
            if(f->DirEntry.DirCluster == 0)
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (FileInfo)
                  *FileInfo = f->DirEntry.Dir;
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
         if (f){
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
               }
         break;
   XEND_API

   if ((Result >= RTF_NO_ERROR) && (A[0] != 0xFF)  && (A[1] != 0xFF))
   {
      int R = FindNext(Result, PatternArray, PatternNum, ArrayMask, FileInfo, FileName, MaxLength, Pos_Hint);

      if (R == RTF_NO_ERROR)
         return Result;
      else
      {
         RTFFindClose(Result);
         return R;
      }
   }
   else
      return Result;
}

/* ------------------------------------------------------------------------------- */
/* Special FinNext for FindReset */
int FindNext(RTFHANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum, 
             BYTE ArrayMask, RTFDOSDirEntry * FileInfo, WCHAR * FileName, 
             UINT MaxLength, RTFDirLocation * Pos_Hint)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   int LastIsLFN = 0;
   kal_bool HintDone = KAL_FALSE;
   BYTE NTReserved = 0;

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);
                                    
         if(f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
            XRAISE(RTF_NO_MORE_FILES);

         if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
               XRAISE(RTF_NO_MORE_FILES);

            Kind = EntryType(D);

            LastIsLFN--;            
                   
            if(Kind == NeverUsed)
               XRAISE(RTF_NO_MORE_FILES);
               
            else if(Kind == Lfn)
            {               
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  Pos_Hint->Cluster = Pos->Cluster;
                  Pos_Hint->Index = Pos->Index;
               }
               
               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + MaxLength - 1))
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
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
               LastIsLFN = 2;
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               if(FileInfo)
                  *FileInfo = *D;

               FileInfo->NTReserved = MT_ENUM_FIND_NONE;
               if((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  UINT i;
                  
                  if(PatternNum > 0)
                  {
                     if(D->Attributes & ArrayMask)                                                 
                     {
                        if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                        {
                           FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                           goto SkipFindNext;
                        }                           
                        goto ContinueFindNext_1;
                     }
                     
                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                           XRAISE(RTF_PARAM_ERROR);
                           
                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                        {
                           FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                           goto SkipFindNext;
                        }
                     }
                  }                  
                  else if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                  {
                     FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                     break;
                  }                     
               }
ContinueFindNext_1:
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
                           Pos_Hint->Cluster = Pos->Cluster;
                           Pos_Hint->Index = Pos->Index;                                                      
                           break;
                        }          
                        HintDone = KAL_FALSE;          
                        goto ContinueFindNext_2;
                     }
                     
                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                           XRAISE(RTF_PARAM_ERROR);  
                                                                                                         
                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                        {
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
                           if (FileInfo->FileName[0] == 0x05)
                              FileInfo->FileName[0] = 0xE5;
                           /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
                           FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                           NTReserved = D->NTReserved;
                           Pos_Hint->Cluster = Pos->Cluster;
                           Pos_Hint->Index = Pos->Index;                           
                           goto SkipFindNext;
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
                     Pos_Hint->Cluster = Pos->Cluster;
                     Pos_Hint->Index = Pos->Index;
                     break;
                  }
               }               
               HintDone = KAL_FALSE;
            }
            else
               HintDone = KAL_FALSE;
ContinueFindNext_2:                        
            if(Kind != Lfn)
               LFNIndex = -1;
         }
SkipFindNext:         
         MTCheckFileNameCase(FileName, MaxLength, NTReserved);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int GetFirstClusterByFileName(const WCHAR *FileName, UINT * Cluster)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         *Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

/* ------------------------------------------------------------------------------- */
int GetFirstClusterByFileHandle(RTFHANDLE FileHandle, UINT * Cluster)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_DATA_ERROR);
         *Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            UnlockDevice(f->Dev);
         break;
   XEND_API

   return Result;
}
/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__ 

static int FolderInQuotaSet(WCHAR * Folder)
{
   int i, j, k, m;
   WCHAR *WidePath = NULL;
   
   WidePath = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(WidePath == NULL)
      return 0;
         
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      memset(WidePath, 0, RTF_MAX_PATH);
      k = strlen((char *)gFS_ExtQuotaSet[i].Path) - 1; //remove the last '\'
      m = 0;
      for(j = 3; j < k; j++, m++)
         WidePath[m] = gFS_ExtQuotaSet[i].Path[j];
      if(kal_dchar_strcmp((char *)Folder, (char *)WidePath) == 0)
      {
         if(WidePath) free_ctrl_buffer(WidePath); 
         return 1;
      }
   }
   if(WidePath) free_ctrl_buffer(WidePath); 
   return 0;
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__ 

void SweepDrive(BYTE DriveIdx)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   int  Result = RTF_NO_ERROR;
   int  i;
   UINT j = 0;
   UINT RFS = 0;
   int  FolderSize; 
   RTFDrive * Drive;
   WCHAR *WidePath = NULL;
   WCHAR *WideName = NULL;
   WCHAR RootName[4];
   RTFHANDLE FHandle;
   RTFDOSDirEntry FileInfo;
   
   /*----------------------------------------------------------------*/
   /* Code Body , SECTION A :                                        */
   /*----------------------------------------------------------------*/
   if (DriveIdx == (BYTE)DrvMappingNew) //Capital 'Z'
      Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
   else
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   
   /* do nothing if alreay swept before */
   if (Drive->QuotaMgt) return;

   /* This Drive must successful mounted */
   ASSERT(Drive->MountState == HasFileSystem);

   /* Get disk free space */   
   if(Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
   {
      ReMountDriveAndCountFreeClusters(Drive);
   }
   
   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
   
   /*----------------------------------------------------------------*/
   /* Code Body , SECTION B : Check gFS_ExtQuotaSet Table Setting    */
   /*----------------------------------------------------------------*/
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      if (DriveIdx == gFS_ExtQuotaSet[i].Path[0])         
      {
         if (gFS_ExtQuotaSet[i].Qmax == FS_QMAX_NO_LIMIT)
         {
            gFS_IntQuotaSet[i].Qmax = 0;
         }
         else
         {
            if (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE)
            {
               if (gFS_ExtQuotaSet[i].Qmax % Drive->ClusterSize)
                  gFS_IntQuotaSet[i].Qmax = (gFS_ExtQuotaSet[i].Qmax / Drive->ClusterSize) + 1;
               else 
                  gFS_IntQuotaSet[i].Qmax = (gFS_ExtQuotaSet[i].Qmax / Drive->ClusterSize);
            }
            else
            {
               gFS_IntQuotaSet[i].Qmax = gFS_ExtQuotaSet[i].Qmax;
            }
         }
         
         if (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE)
         {
            if (gFS_ExtQuotaSet[i].Qmin % Drive->ClusterSize)
               gFS_IntQuotaSet[i].Qmin = (gFS_ExtQuotaSet[i].Qmin / Drive->ClusterSize) + 1;
            else
               gFS_IntQuotaSet[i].Qmin = (gFS_ExtQuotaSet[i].Qmin / Drive->ClusterSize);
         }
         else
         {
            gFS_IntQuotaSet[i].Qmin = gFS_ExtQuotaSet[i].Qmin;
         }
      }
   }
   
   /*----------------------------------------------------------------*/
   /* Code Body , SECTION C : Disk Free Space And Quota Entry Usage  */
   /*----------------------------------------------------------------*/
   /* Raise Drive Quota Flag */
   Drive -> QuotaMgt = 1;
   
   /* Start to sweep disk */         
   WidePath = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   WideName = get_ctrl_buffer(MT_MAX_WIDE_NAME);
   
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {            
      if (DriveIdx == gFS_ExtQuotaSet[i].Path[0])
      {         
         j = i;

         memset(WidePath, 0, RTF_MAX_PATH);    
         strcpy((char *)WidePath, (char *)gFS_ExtQuotaSet[i].Path);
         FileNameExtendToWCHAR((char *)WidePath);
         
         // C - 1. Is Folder Exist ?
         Result = RecAUX_IsFolder(WidePath);
         if (Result < RTF_NO_ERROR)
         {
            gFS_IntQuotaSet[i].Qnow = 0;
            goto SweepCalc;
         }

         FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0);
         
         if (FolderSize > RTF_NO_ERROR)
            gFS_IntQuotaSet[i].Qnow = FolderSize;
         else
            gFS_IntQuotaSet[i].Qnow = 0;
         
         // C - 2. Remove DEL
         if (gFS_ExtQuotaSet[i].Priority == MT_QP_DEL_ENUM)
         {
            Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);               
            if(Result >= RTF_NO_ERROR)
            {
               SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);             
               gFS_IntQuotaSet[i].Qnow = 0;
            }
            else //error handling
            {
               FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0);
               
               if (FolderSize > RTF_NO_ERROR)
                  gFS_IntQuotaSet[i].Qnow = FolderSize;
               else
                  gFS_IntQuotaSet[i].Qnow = 0;               
            }
         }   
         // C - 3. Remove if over quota
         if (gFS_IntQuotaSet[i].Qmax) //quota with limit
         {                              
            if (gFS_IntQuotaSet[i].Qnow > gFS_IntQuotaSet[i].Qmax)
            {
               Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
               if (Result >= RTF_NO_ERROR)
               {
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);             
                  gFS_IntQuotaSet[i].Qnow = 0;                  
               }
            }            
            else //error handling
            {
               FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0);
               
               if (FolderSize > RTF_NO_ERROR)
                  gFS_IntQuotaSet[i].Qnow = FolderSize;
               else
                  gFS_IntQuotaSet[i].Qnow = 0;               
            }
         }
         // C - 4. Count RFS
SweepCalc:         
         if (gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qnow)
            RFS += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Qnow);
      }
   }
   
   /* Special for NVRAM
    * Note !!! nvram interface split on 2006/07/17,
    * here we get the NVRAM name only
    */ 
   nvram_get_folder_name(NvramName);
      
   /*----------------------------------------------------------------*/
   /* Code Body , SECTION D : Start to Sweep to Get More Free Space  */
   /*----------------------------------------------------------------*/
   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   {
      memset(WidePath, 0, MT_MAX_WIDE_NAME); 
      strncpy((char *)WidePath, (char *)gFS_ExtQuotaSet[j].Path, 3);    
      FileNameExtendToWCHAR((char *)WidePath);      
      kal_wstrcpy(RootName, WidePath);      
      
      // D - 1. Remove files
      RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE, NULL, 0);
   }
        
   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   { 
      // D - 2. Remove folders not in gFS_ExtQuotaSet   
      kal_wstrcat(WidePath, L"*");
      FHandle = RTFFindFirstEx(WidePath, 0, 0, &FileInfo, WideName, RTF_MAX_PATH);
      if (FHandle > 0)
      {
         if (!WFNamesMatch((char *)WideName, (char *)dchar_dot))
         //Don't worry about dchar_dot_dot here
         {
            if (WFNamesMatch((char *)WideName, (char *)NvramName))
               goto SweepFolder;
              
            if (FileInfo.Attributes & RTF_ATTR_DIR)
            {                                    
               if (WideName[0] == 0x40) //'@'
               {
                  if (FolderInQuotaSet(WideName)) //in table
                     goto SweepFolder;
               }               
               kal_wstrcpy(WidePath, RootName);
               kal_wstrcat(WidePath, WideName);
               RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
               if(Drive->FreeClusterCount >= RFS)
                  goto SweepReturn;
            }
         }
SweepFolder:
         while(RTFFindNextEx(FHandle, &FileInfo, (WCHAR *)WideName, RTF_MAX_PATH) == RTF_NO_ERROR)
         {
            if (!WFNamesMatch((char *)WideName, (char *)dchar_dot_dot))
            {
               if (WFNamesMatch((char *)WideName, (char *)NvramName))
                  goto SweepFolder;
               if (FileInfo.Attributes & RTF_ATTR_DIR)
               {
                  if (WideName[0] == 0x40) //'@'
                  {
                     if (FolderInQuotaSet(WideName)) //in table
                        goto SweepFolder;
                  }
                  kal_wstrcpy(WidePath, RootName);
                  kal_wstrcat(WidePath, WideName);
                  RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
                  if (Drive->FreeClusterCount >= RFS)
                     goto SweepReturn;
               }
            }
         }
      }
   }
              
   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   {         
      for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
      {
         if (DriveIdx == gFS_ExtQuotaSet[i].Path[0])
         {                           
            // D - 3. Remove LOW
            if (gFS_ExtQuotaSet[i].Priority == MT_QP_LOW_ENUM)
            {                   
               memset(WidePath, 0, RTF_MAX_PATH);    
               strcpy((char *)WidePath, (char *)gFS_ExtQuotaSet[i].Path);
               FileNameExtendToWCHAR((char *)WidePath);                  

               Result = RecAUX_IsFolder(WidePath);
               if (Result < RTF_NO_ERROR) continue;

               Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
               if(Result >= RTF_NO_ERROR)
               {  
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);             
                  if(gFS_IntQuotaSet[i].Qnow > gFS_IntQuotaSet[i].Qmin)
                     RFS += gFS_IntQuotaSet[i].Qmin;
                  else
                     RFS += gFS_IntQuotaSet[i].Qnow;
                  gFS_IntQuotaSet[i].Qnow = 0;
                  if (Drive->FreeClusterCount >= RFS)
                     goto SweepReturn;
               }
            }
         }
      } /* for (i = FS_MAX_QSET - 1 ; i >= 0; i--) , Priority LOW */
   }

   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   {
      for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
      {            
         if (DriveIdx == gFS_ExtQuotaSet[i].Path[0])
         {                           
            // D - 4. Remove MID
            if (gFS_ExtQuotaSet[i].Priority == MT_QP_MID_ENUM)
            {                   
               memset(WidePath, 0, RTF_MAX_PATH);                            
               strcpy((char *)WidePath, (char *)gFS_ExtQuotaSet[i].Path);
               FileNameExtendToWCHAR((char *)WidePath);                     

               Result = RecAUX_IsFolder(WidePath);
               if (Result < RTF_NO_ERROR) continue;

               Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
               if(Result >= RTF_NO_ERROR)
               {
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
                  if (gFS_IntQuotaSet[i].Qnow > gFS_IntQuotaSet[i].Qmin)
                     RFS += gFS_IntQuotaSet[i].Qmin;
                  else
                     RFS += gFS_IntQuotaSet[i].Qnow;
                  gFS_IntQuotaSet[i].Qnow = 0;
                  if (Drive->FreeClusterCount >= RFS)
                     goto SweepReturn;
               }
            }
         }
      } /* for (i = FS_MAX_QSET - 1 ; i >= 0; i--) , Priority MID */
   }
   
   /*----------------------------------------------------------------*/
   /* Code Body , SECTION E : ENDING                                 */
   /*----------------------------------------------------------------*/
SweepReturn:       
   if(WidePath) free_ctrl_buffer(WidePath);   
   if(WideName) free_ctrl_buffer(WideName);   
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);   
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__ 

int ChkQuotaConfig(BYTE DriveIdx)
{
   int        Result = RTF_NO_ERROR, i;
   UINT       MRS = 0, RFS = 0;
   RTFDrive * Drive;
#ifndef __PRODUCTION_RELEASE__
   int        k, j;
   kal_bool   g_FirstDownload = KAL_TRUE;
   BYTE       MaxDrvIdx;
#endif

   if(DriveIdx == (BYTE)DrvMappingNew) //Capital 'Z'
      Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
   else
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   
   /* This Drive must successful mounted, and swept called before */
   ASSERT(Drive->MountState == HasFileSystem && Drive->QuotaMgt == 1);

   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);             
   
#ifndef __PRODUCTION_RELEASE__
   /* Check gFS_ExtQuotaSet table setting */         
   //only check at first download
   if (Check_NORFlash_Formatted() == 0)
      g_FirstDownload = KAL_FALSE;
   
   if (g_FirstDownload == KAL_TRUE)
   {       
      // Here is in-house debug use configure error
      ASSERT((FS_MAX_QSET+1) <= MT_MAX_QUOTA_ENTRY);        
      for (i = MT_BASE_DRIVE_INDEX; i < FS_MAX_DRIVES; i++)
      {      
         if (gFS_Data.DriveTable[i].Dev == NULL)      
         break;                  
      }
      MaxDrvIdx = (MT_BASE_DRIVE_LETTER + i - 1);
      
      for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
      {
         //Check table setting
         // Here is configure error

         if (DriveIdx != (BYTE)DrvMappingNew)   
            ASSERT((gFS_ExtQuotaSet[i].Path[0] >= MT_BASE_DRIVE_LETTER) && (gFS_ExtQuotaSet[i].Path[0]) <= MaxDrvIdx);
         ASSERT(gFS_ExtQuotaSet[i].Path[1] == 0x3A);   //':'
         ASSERT(gFS_ExtQuotaSet[i].Path[2] == 0x5C);   //'\'
         ASSERT(gFS_ExtQuotaSet[i].Path[3] == 0x40);   //'@'
         ASSERT(strlen((char *)gFS_ExtQuotaSet[i].Path) <= MT_MAXPATH_IN_WCHAR_UNIT );
         k = strlen((char *)gFS_ExtQuotaSet[i].Path) - 1;
         ASSERT(gFS_ExtQuotaSet[i].Path[k] == 0x5C);   //'\'     
         for(j = 4; j < k; j++)
            ASSERT(gFS_ExtQuotaSet[i].Path[j] != 0x5C);//not support multi-level folder
         ASSERT(gFS_ExtQuotaSet[i].Priority <= MT_QP_DEL_ENUM);
         ASSERT(gFS_ExtQuotaSet[i].Qmax != 0);
         ASSERT(gFS_ExtQuotaSet[i].Qmin <= gFS_ExtQuotaSet[i].Qmax);             
         ASSERT((gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE) || (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_CLUSTER));
      }
   }
#endif

   /* Get NVRAM's MRS */
   nvram_space_reserve(&MRS);

   /* Calculate MRS, RFS */
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      if (DriveIdx == gFS_ExtQuotaSet[i].Path[0])         
      {                 
         if (Drive->Clusters < gFS_IntQuotaSet[i].Qmax)
         {
            /* App. Quota Max over disk space
             * This should be configuration error
             */ 
#ifdef __FS_TRACE_SUPPORT__
            if (g_TraceFlag & MT_TRACE_ERROR) //force print
            {
               kal_sprintf(TraceTmpBuf, "Capability %d; Quota Idx = %d", Drive->Clusters, i);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_QUOTA_OVER_DISK_SPACE, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            Result = MT_QUOTA_OVER_DISK_SPACE;
            break;
         }

         MRS += gFS_IntQuotaSet[i].Qmin;

         if (gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qnow)
         {
            RFS += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Qnow);
         }
      }
   }

   if (Drive->Clusters < MRS)
   {
      /* Total Minal Reserved Space for Applications (NVRAM included) over disk space
       * This should be configuration error
       */ 
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR) //force print
      {
         kal_sprintf(TraceTmpBuf, "Capability %d; MRS = %d", Drive->Clusters, MRS);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_QUOTA_OVER_DISK_SPACE, NULL, (BYTE *)TraceTmpBuf);
       }
#endif
      Result = MT_QUOTA_OVER_DISK_SPACE;
   }
   else if (Drive->FreeClusterCount <= RFS)
   {
      /* Minal Reserved Space Not Enought for Application required,
       * This should be run-time disk full error, raise warnning
       */ 
#ifdef __FS_TRACE_SUPPORT__
      if (g_TraceFlag & MT_TRACE_ERROR) //force print 
      {
         kal_sprintf(TraceTmpBuf, "FreeCluster %d; RFS = %d", Drive->FreeClusterCount, RFS);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_QUOTA_USAGE_WARNING, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      Result = MT_QUOTA_USAGE_WARNING;
   }

   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   return Result;
}
#endif

/* ------------------------------------------------------------------------------- */
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

/* ------------------------------------------------------------------------------- */
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
#endif //__P_PROPRIETARY_COPYRIGHT__

/* ------------------------------------------------------------------------------- */
int MTMakeFileName(RTFDrive * Drive, RTFDirLocation * Pos, WCHAR * FileName, UINT MaxLength)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFDOSDirEntry * D = GetDir(Drive, Pos);
   int Kind;

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);
         do
         {
            if (D == NULL)
               XRAISE(RTF_PARAM_ERROR);

            Kind = EntryType(D);

            if (Kind == NeverUsed)
            {
               XRAISE(RTF_PARAM_ERROR);
            }
            else if (Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  // see if it fits
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  /* characters stored in the LFN entry are in 2-byte unicode*/
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if (Limit > ( ((char *)FileName) + MaxLength - 1)) /* not able to hold */
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if (Kind == InUse)
            {
               // check against LFN first
               if ((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  break;
               }
               // try short name
               if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR) )
               {
                  FileNameExtendToWCHAR((char *)FileName);
                  break;
               }
            }
            if (Kind != Lfn)
               LFNIndex = -1;
            D = NextDir(Drive, Pos);
         } while (1);
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF);
         break;
   XEND_API
   return RTF_NO_ERROR;

}

/* ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Utilities For Directory Entries Processing
 **************************************************/

static int ScanFindFirst(WCHAR * NamePattern, RTFDirEntry * DirPos)
{ 
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;
   BYTE Attr = 0, AttrMask = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))
         {
            if(f->DirEntry.DirCluster == 0)
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (DirPos)
                  DirPos->Dir = f->DirEntry.Dir;
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
         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   return Result;
}

static int ScanFindNext(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   kal_bool HintDone = KAL_FALSE;
   const WCHAR *p;

   memset(DirPos, 0, sizeof(RTFDirEntry));
   
   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);
                                    
         if(f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
            XRAISE(RTF_NO_MORE_FILES);

         if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
               XRAISE(RTF_NO_MORE_FILES);

            Kind = EntryType(D);

            if(Kind == NeverUsed)
               XRAISE(RTF_NO_MORE_FILES);
               
            else if(Kind == Lfn)
            {               
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  DirPos->LongPos.Cluster = Pos->Cluster;
                  DirPos->LongPos.Index = Pos->Index;
               }
               
               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;
                  
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + RTF_MAX_PATH - 1))
                      LFNIndex = -2;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -2;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               if(DirPos)
                  DirPos->Dir = *D;
               if(LFNIndex == -2)
                  DelDirEntry(f->Drive, &DirPos->LongPos, Pos);
               else if((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {                                    
                  p = (WCHAR *)FileName;
                  while (p[0])
                  {
                     if (!IsValidLongNameChar(*p++))
                     {
                        DelDirEntry(f->Drive, &DirPos->LongPos, Pos);
                        HintDone = KAL_FALSE;
                        goto ScanFindNextContinue;
                     }
                  }                  
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               else if(MakeShortFileName(D, (char *)FileName, RTF_MAX_PATH) != RTF_NO_ERROR)
                  DelDirEntry(f->Drive, &DirPos->LongPos, Pos);                  
               else 
               {                                    
                  FileNameExtendToWCHAR((char *)FileName);
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               HintDone = KAL_FALSE;
            }
            else //Kind = Available
               HintDone = KAL_FALSE;
ScanFindNextContinue:                                         
            if(Kind != Lfn)
               LFNIndex = -1;
         }            
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}
#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Macros & Utilities For BIT MAP Operation
 **************************************************/

#define INLINE_CMPARE_CLUSTER_BIT(Cdata, Cluster)   \
        (Cluster >= Cdata->ClsOffset && Cluster <= Cdata->ClsRange)

#define INLINE_GET_CLUSTER_BIT(Cdata, Cluster)      \
        ((Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] & 1 << ((Cluster - Cdata->ClsOffset) % 8)) != 0) 

#define INLINE_SET_CLUSTER_BIT(Cdata, Cluster)      \
        (Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] |= 1 << ((Cluster - Cdata->ClsOffset) % 8))

#define INLINE_CLEAR_CLUSTER_BIT(Cdata, Cluster)    \
        (Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] &= ~(1 << ((Cluster - Cdata->ClsOffset) % 8)))

static void Clear_ClusterMap_Chain(InternScanDataStruct *SDCD, RTFCluster Cluster, UINT Count)
{
   while (Count--)
   {
      if (INLINE_CMPARE_CLUSTER_BIT(SDCD, Cluster))
         INLINE_CLEAR_CLUSTER_BIT(SDCD, Cluster);
      Cluster = (SDCD->RAWCluster)(SDCD->Drive, Cluster);
      if ((Cluster < 2L) || (Cluster >= SDCD->Drive->Clusters))
         break;
   }
}

static void ScanRootDirFATChain(InternScanDataStruct *SDCD)
{
   // FAT32   Root Directory must marked
   if(SDCD->Drive->FATType == 32)
   {
      RTFCluster tmpCluster, nextCluster;

      tmpCluster = SDCD->Drive->FirstDirSector; /* Note that it's not sector number in FAT32 */

      do
      {
         nextCluster = (SDCD->RAWCluster)(SDCD->Drive, tmpCluster);

         if (INLINE_CMPARE_CLUSTER_BIT(SDCD, tmpCluster))
            INLINE_SET_CLUSTER_BIT(SDCD, tmpCluster);

         if (nextCluster >= 2L && nextCluster < SDCD->Drive->Clusters)
         {  /* Valid Cluster */
            tmpCluster = nextCluster;
            continue;
         }

         if (nextCluster < RTF_CLUSTER_CHAIN_END)
         {
            /* InValid Cluster , Truncate the FAT Chain */
            SetClusterValue(SDCD->Drive, tmpCluster, RTF_CLUSTER_CHAIN_END);
            return;
         }

      } while (nextCluster < RTF_CLUSTER_CHAIN_END);

   } /* if(SDCD->Drive->FATType == 32) */
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Second Level Procedures
 **************************************************/
static int IfFHEnough(void) //for CHECKDRIVE_SUPPORT ScanDirTree only
{
   int i, j = 0;
   RTFile * f = gFS_Data.FileTable;
   
   for (i=0; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Dev == NULL) && (f->Task == NULL))
         j++;
   }

   if (j)
      return j;
   return RTF_TOO_MANY_FILES;
}

static int ScanDirTree(InternScanDataStruct *SDCD)
{
   RTFHANDLE FHandle = NULL;
   RTFHANDLE *HistoryFH = NULL;
   UINT i = 0;
   WCHAR *Filename1 = NULL, *Filename2 = NULL, *Filename3 = NULL;
   int idx = 0, Result = RTF_NO_ERROR;
   RTFDirEntry DirPos;
   RTFCluster C;
   RTFCluster FATClusters, DirClusters;

   HistoryFH = get_ctrl_buffer((FS_MAX_FILES)*4); 
   if(HistoryFH == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      return Result;
   }
   memset(HistoryFH, 0, (FS_MAX_FILES)*4);
   
   Filename1 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename1 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   memset(Filename1, 0, MT_MAX_WIDE_PATH);
   
   Filename2 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename2 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   memset(Filename2, 0, MT_MAX_WIDE_PATH);
   
   Filename3 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename3 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   memset(Filename3, 0, MT_MAX_WIDE_PATH);
   kal_wstrncpy((WCHAR *)Filename3, (WCHAR *)SDCD->Drive->CurrDir, 3); /* Scan From Root */
   
   ScanRootDirFATChain(SDCD); /* FAT32 Only */

   while(idx >= 0)
   {
ScanDirTreeFirst:
      Result = IfFHEnough() - 2 /* Reserve 2 file handle for concurrency */;
      if(Result < RTF_NO_ERROR)
      {
         Result = RTF_TOO_MANY_FILES;
         goto ScanDirTreeReturn;
      }

      memset(Filename1, 0, MT_MAX_WIDE_PATH);
      if(kal_dchar_strlen((char *)Filename3) > RTF_MAX_PATH)
      {
         Result = MT_PATH_OVER_LEN_ERROR;
         goto ScanDirTreeReturn;
      }
      kal_wstrcpy((WCHAR *)Filename1, (WCHAR *)Filename3);
      kal_wstrcat((WCHAR *)Filename1, L"*");
      FHandle = ScanFindFirst((WCHAR *)Filename1, &DirPos);
      if(FHandle > 0)
      {
ScanDirTreeNext:
         while((Result = ScanFindNext(FHandle, (WCHAR *)Filename2, &DirPos)) == RTF_NO_ERROR)
         {
            if(g_CheckDrive == KAL_FALSE)
               goto ScanDirTreeReturn;

            if((!WFNamesMatch((char *)Filename2, (char *)dchar_dot)) &&
               (!WFNamesMatch((char *)Filename2, (char *)dchar_dot_dot)))
            {
               FATClusters = 0;
               SDCD->D = DirPos.Dir;
               C = FIRST_FILE_CLUSTER(SDCD->D); 
               //Invalid cluster
               if(FileNameInvalid((const char *)SDCD->D.FileName) || (C == 1L) || 
                  (C >= SDCD->Drive->Clusters) ||
                  ((SDCD->D.Attributes & RTF_ATTR_DIR) && (C == 0)) )
               {
                  DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                  goto ScanDirTreeNext;
               }
               if ((C != RTF_ROOT_DIR) && (C != 0))
               {
                  do
                  {
                     //Invalid cluster
                     if ((C < 2L) || (C >= SDCD->Drive->Clusters))
                     {
                        DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                        goto ScanDirTreeNext;
                     }
                     //Cross link
                     if (INLINE_CMPARE_CLUSTER_BIT(SDCD, C) && INLINE_GET_CLUSTER_BIT(SDCD, C))
                     {
                        Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                        DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                        ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); 
                        Result = RTF_CHECKDISK_RETRY;
                        goto ScanDirTreeReturn;
                     }
                     else 
                     //Set Bit
                     {
                        if (INLINE_CMPARE_CLUSTER_BIT(SDCD, C))
                           INLINE_SET_CLUSTER_BIT(SDCD, C);
                     }
                     FATClusters++;
                     C = (SDCD->RAWCluster)(SDCD->Drive, C);
                  } while (g_CheckDrive == KAL_TRUE && C < RTF_CLUSTER_CHAIN_END);
                  
               }
               if((SDCD->D.Attributes & RTF_ATTR_DIR) == 0) //File
               {
                  DirClusters = (SDCD->D.FileSize > 0) ? ((SDCD->D.FileSize-1) / SDCD->Drive->ClusterSize) + 1 : 0;

                  //Size too small
                  if (FATClusters > DirClusters)
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
                  //Size too large
                  else if (FATClusters < DirClusters)
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
               }
               else //Folder
               {
                  #if defined(FS_CHECKDRIVE_SUPPORT_REMOVAL_DEEP_FOLDER)
                  /* Enable this option if you want to remove the folder that located in too deep level */
                  if(idx == (FS_MAX_FILES-2))
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
                  #endif /* FS_CHECKDRIVE_SUPPORT_REMOVAL_DEEP_FOLDER */
                  kal_wstrcat((WCHAR *)Filename3, (WCHAR *)Filename2);
                  kal_wstrcat((WCHAR *)Filename3, L"\\");
                  HistoryFH[idx] = FHandle;
                  idx++;
                  goto ScanDirTreeFirst;
               }
            } /* If Not dot , dotdot */
         }

         if((Result != RTF_NO_MORE_FILES) && (Result < 0))
            goto ScanDirTreeReturn;
      }
      else /* (FHandle < 0) */
      {
         Result = FHandle;
         goto ScanDirTreeReturn;
      } /* End of ScanFindFrist */

      idx--;
      if(idx >= 0)
      {
         if(FHandle > 0)
         { 
            RTFFindClose(FHandle);
         }
         FHandle = HistoryFH[idx];
         HistoryFH[idx] = 0;
         CdUp((WCHAR *)Filename3);
         goto ScanDirTreeNext;
      }
      else
         break;
   } /* while( idx >= 0) */

ScanDirTreeReturn: 
   if(idx >= 0)
   {
      for(i = 0; i <= idx; i++)
      {
         if(HistoryFH[i] == 0) break;
         RTFFindClose(HistoryFH[i]);
      }
   }
   if(FHandle > 0) 
   {
      RTFFindClose(FHandle);
   }
   if(Filename1) free_ctrl_buffer(Filename1);
   if(Filename2) free_ctrl_buffer(Filename2);
   if(Filename3) free_ctrl_buffer(Filename3);
   if(HistoryFH) free_ctrl_buffer(HistoryFH);

   if((Result != RTF_NO_MORE_FILES) && (Result < RTF_NO_ERROR))
      return Result;
   return RTF_NO_ERROR;
}

static void ChkLostClusters(InternScanDataStruct *SDCD)
{
   RTFCluster i, C;
   UINT State = 1;

   // mark up all free and bad clusters
   i = (SDCD->ClsOffset) ? SDCD->ClsOffset : 2;

   for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++)
   {
      if (!INLINE_GET_CLUSTER_BIT(SDCD, i))
      {
         C = (SDCD->RAWCluster)(SDCD->Drive, i);
         /* Free or Broken Cluster */
         if (C == 0 || C == RTF_BAD_CLUSTER)
         {
            INLINE_SET_CLUSTER_BIT(SDCD, i);
         }
         /**********************************************************************************
          * The strange cluster value should not happen during power lose.
          * There's many trade-off opinions on dealing with this.
          * Conclusion is, 3 policies applied on different cases,
          * 1) Leave it as-is , applied on system drive , RTFCheckDisk().
          *    Because Critial Application such as NVRAM will stop system when hit.
          * 2) EXT_ASSERT() , applied on public drive when in-house testing.
          *    To early detect error.
          * 3) Logging, warnning and clear , applied on public drive when production released.
          *    To achieve integrity of file system.
          ************************************************************ 2006/03/31 ***********/
         else if (C == 1 || C >= SDCD->Drive->Clusters)
         {
#ifdef __PRODUCTION_RELEASE__
            /*  
             *  EXT_WARN(i, C); 
             *  Do-nothing means clear it;
             */;
#else
            if ((SDCD->Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0 && (C < RTF_CLUSTER_CHAIN_END))
               EXT_ASSERT(0, i, C, 0);
            /* INLINE_SET_CLUSTER_BIT(SDCD, i); *//* means Leave it as-is */
#endif
         }
      }
   } /* for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++) */

   // look for unmarked areas
   C = 0;
   i = (SDCD->ClsOffset) ? SDCD->ClsOffset : 2;
   for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++)
   {
      if (State != INLINE_GET_CLUSTER_BIT(SDCD, i))
      {
         if (State == 0) // end of a lost chain
         {
            RTFCluster j;
            for (j=0; j < C; j++)
               SetClusterValue(SDCD->Drive, j+i-C, 0);
         }
         State = !State;
         C = 0;
      }
      C++;
   }
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Utilities For Dirve Specific Operation
 **************************************************/
/*
 * ChkMonopolizeDrive()
 *  To get exclusion control on specific drive.
 *  check if any opening file handle on this drive,
 */
static void ChkMonopolizeDrive(RTFDrive * Drive)
{
   int i;
   RTFile * f;
      
   //Lock RTF and device before calling this function
   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Lock != 0) && (f->Drive == Drive))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 3, __LINE__, RTF_ACCESS_DENIED, f, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_ACCESS_DENIED);
      }
   }   
   //should not unlock here
}

static void ScanFATDelete(InternScanDataStruct *SDCD, RTFCluster Cluster)
{
   RTFCluster NextCluster;

   while (g_CheckDrive == KAL_TRUE && Cluster < RTF_CLUSTER_CHAIN_END)
   {
      NextCluster = (SDCD->RAWCluster)(SDCD->Drive, Cluster);
      SetClusterValue(SDCD->Drive, Cluster, 0);
      Cluster = NextCluster;
   }
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

static RTFCluster ScanFAT12_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   RTFCluster Result = 0;
   DWORD Pos;
   UINT  B1, B2;
   BYTE  * FATPtr;

   Pos    = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
   FATPtr = MTProxyGetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift));
   B1     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

   Pos++;
   FATPtr = MTProxyGetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift));
   B2     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

   Result = (Cluster & 1) ? ((B2 << 4) | (B1 >> 4)) : (((B2 & 0x0F) << 8) | B1);
   if (Result >= 0xFF7)
      Result |= 0x0FFFF000;
   return Result;
}

static RTFCluster ScanFAT16_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   RTFCluster Result = 0;
   WORD * FATPtr = MTProxyGetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)));
   Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)];
   if (Result >= 0xFFF7)
      Result |= 0x0FFF0000;
   return Result;
}

static RTFCluster ScanFAT32_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   RTFCluster Result = 0;
   DWORD * FATPtr = MTProxyGetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)));
   Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1)] & 0x0FFFFFFF;
   return Result;
}

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Main Procedure
 **************************************************/
int ScanDrive(RTFDrive * Drive, void * Buffer, unsigned int BufferLen)
{
   InternScanDataStruct SDCD;
   int volatile Result = RTF_NO_ERROR;
   RTFDirEntry Root;

   /* ScanDrive - 1. Setup Scan-Disk-Control-Data */
   SDCD.Drive      = Drive;
   SDCD.ClusterMap = (BYTE*) Buffer;
   SDCD.ClsSpan    = (BufferLen - 1) * 8;

   XTRY
      case XCODE:
         /* ScanDrive - 2. Lock Device, and exclusion access check */
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         ChkMonopolizeDrive(Drive);

         /* ScanDrive - 3. Hook the Function Pointer to do faster GetClusterValue() */
         switch (Drive->FATType)
         {
            case 12:   SDCD.RAWCluster = ScanFAT12_GetRAWClusterValue; break;
            case 16:   SDCD.RAWCluster = ScanFAT16_GetRAWClusterValue; break;
            case 32:   SDCD.RAWCluster = ScanFAT32_GetRAWClusterValue; break;
            default:   EXT_ASSERT(0, (UINT)Drive, (UINT)Drive->FATType, 0);
         }

         /* ScanDrive - 4. Build Recursive initial Data */
ScanDriveAgain:
         SDCD.ClsOffset  = 0;

ScanDriveNextIterative:
         SDCD.ClsRange   = SDCD.ClsOffset + SDCD.ClsSpan;
         if (SDCD.ClsRange > Drive->Clusters)
         {
            SDCD.ClsRange = Drive->Clusters;
         }

         MakePseudoRootDirEntry(Drive, &Root);
         SDCD.D = Root.Dir;

         memset(SDCD.ClusterMap, 0, SDCD.ClsSpan / 8 + 1);

         /* ScanDrive - 5. Detail Scan by Root Directory */
         Result = ScanDirTree(&SDCD);
         if (Result == RTF_CHECKDISK_RETRY)
         {
            goto ScanDriveAgain;
         }
         else if (Result < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__            
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 3, __LINE__, Result, NULL, NULL);
#endif             
            XRAISE(Result);
         }

         ChkLostClusters(&SDCD);
         FlushAllBuffers(SDCD.Drive->Dev);

         if (SDCD.ClsRange < Drive->Clusters)
         {
            SDCD.ClsOffset = SDCD.ClsRange;
            goto ScanDriveNextIterative;
         }

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return Result;
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */
/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Folder Traverse Engine
 *  Members:
 *          RecTravStart
 *          RecTravClose
 *          RecTravNextFolder
 *          RecTravBackward
 *          RecTravDownLevel
 *          RecTravUpLevel
 **************************************************/

/* Note: Usage Sample C:\ABC\* , must be end with star */
const static WCHAR dchar_backslash_star_postfix[] = /* \* */ { 0x005c, 0x002a, 0x0000};
RTFHANDLE RecTravStart(WCHAR * PathNamePattern)
{ 
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;
   BYTE Attr = 0, AttrMask = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathNamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)PathNamePattern, NULL)) // search a file or a direcotry
         {
            // PathNamePattern is a file, and found !
            XRAISE(RTF_PARAM_ERROR);
         }
         // else we found the parent

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;

         Attr = RTF_ATTR_DIR; /* Folder Only */
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   return Result;
}

int RecTravClose(RTFHANDLE Handle)
{
   return RTFClose(Handle);
}

static int RecTravNextFolder(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const WCHAR * NamePattern;
   RTFDirLocation * Pos;
   kal_bool HintDone = KAL_FALSE;
   BYTE * A;

#ifdef __EFS_DEBUG__
   ASSERT(DirPos != NULL && FileName != NULL);
#endif /* __EFS_DEBUG__ */
   memset(DirPos, 0, sizeof(RTFDirEntry));
   
   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         if (f->SpecialKind != NormalFile)
         {
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if (f->Valid == MT_ENUM_FH_ABORTED)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, MT_ABORTED_ERROR, NULL, NULL);
#endif
            XRAISE(MT_ABORTED_ERROR);
         }

         NamePattern = kal_wstrrchr((WCHAR*)f->FullName, 0x005c);
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         // Must be a star to identify the traverse filehandle
         if (kal_wstrcmp(NamePattern, dchar_backslash_star_postfix) != 0 || A[0] != RTF_ATTR_DIR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, RTF_PARAM_ERROR, NULL, NULL);
#endif
            XRAISE(RTF_PARAM_ERROR);
         }

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
            {
               XRAISE(RTF_NO_MORE_FILES);
            }

            Kind = EntryType(D);

            if(Kind == NeverUsed)
            {
               XRAISE(RTF_NO_MORE_FILES);
            }
               
            else if(Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  DirPos->LongPos.Cluster = Pos->Cluster;
                  DirPos->LongPos.Index = Pos->Index;
               }

               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;
                  
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + RTF_MAX_PATH - 1))
                      LFNIndex = -2;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -2;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               DirPos->Dir = *D;
               DirPos->DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

               // try LFN first
               if((LFNIndex == 0) &&
                  (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)) ) // Note: Name Match not requeired 
               {
                  /* Now found one that with LFN & SFN */
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }

               // try short name
               if ((D->FileName[0] != 0x2e) /* skip dot or dot-dot */ &&
                   (MakeShortFileName(D, (char *)FileName, RTF_MAX_PATH) == RTF_NO_ERROR))
               {
                  /* Now found one that with SFN only */
                  if (D->FileName[0] == 0x05)
                  {
                     FileName[0] = 0xE5;
                  }
                  FileNameExtendToWCHAR((char *)FileName);

                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               HintDone = KAL_FALSE;
            }
            else
               HintDone = KAL_FALSE;
            if(Kind != Lfn)
               LFNIndex = -1;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/**********************************************************
 * RecTravDownLevel   ---- implement for fast
 *    f:            The File Table Pointer
 *    SaveDirInfo:  The Current DirPos to be Saved
 *    NewDirInfo :  The Down Level DirPos to be Setup
 *    FolderName :  The Folder Name to be append on 
 *
 **********************************************************/
static void RecTravDownLevel(RTFile *f, RTFDirEntry *SaveDirInfo, RTFDirEntry *NewDirInfo, WCHAR *FolderName)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;
   unsigned int NameLen;

#ifdef __EFS_DEBUG__
   ASSERT(SaveDirInfo != NULL && NewDirInfo != NULL);
   ASSERT(FolderName != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         
   // Now save and swap the directory Entry information
   memcpy(SaveDirInfo, &(f->DirEntry), sizeof(RTFDirEntry));
   memcpy(&(f->DirEntry), NewDirInfo,  sizeof(RTFDirEntry));

   // Reset position information
   Pos  = (void*) &f->Cluster;
   Pos->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
   Pos->Index   = -1;

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NameLen = kal_wstrlen(FolderName);

   kal_wstrncpy(++NamePtr, FolderName, NameLen);
   kal_wstrcpy (NamePtr+NameLen, dchar_backslash_star_postfix);

   RTFSYSFreeMutex(RTFLock);
}

/**********************************************************
 * RecTravUpLevel   ---- implement for fast
 *    f:            The File Table Pointer
 *    UpDirInfo:  The Current DirPos to be Saved
 *
 **********************************************************/
static void RecTravUpLevel(RTFile *f, RTFDirEntry *UpDirInfo)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;

#ifdef __EFS_DEBUG__
   ASSERT(UpDirInfo != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         
   // Now clear position information, shift directory information as position information
   Pos  = (void*) &f->Cluster;
   Pos->Cluster = f->DirEntry.ShortPos.Cluster;
   Pos->Index   = f->DirEntry.ShortPos.Index;

   // Reload the Directory info
   memcpy(&(f->DirEntry), UpDirInfo,  sizeof(RTFDirEntry));

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NamePtr[0] = 0x0;

   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   kal_wstrcpy(NamePtr, dchar_backslash_star_postfix);

   RTFSYSFreeMutex(RTFLock);
}

/**********************************************************
 * RecTravUpLevelAndBackward   ---- implement for fast
 *    f:          The File Table Pointer
 *    UpDirInfo:  The Current DirPos to be Saved, and set back to reterive name again
 *
 **********************************************************/
static void RecTravUpLevelAndBackward(RTFile *f, RTFDirEntry *UpDirInfo)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;

#ifdef __EFS_DEBUG__
   ASSERT(UpDirInfo != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         
   // Now clear position information, shift directory information as position information
   // But, set back to the parent entry
   Pos  = (void*) &f->Cluster;
   if (f->DirEntry.LongPos.Cluster != 0)
   {
      Pos->Cluster= f->DirEntry.LongPos.Cluster;
      Pos->Index  = f->DirEntry.LongPos.Index - 1;
   }
   else
   {
      Pos->Cluster= f->DirEntry.ShortPos.Cluster;
      Pos->Index  = f->DirEntry.ShortPos.Index - 1;
   }

   // Reload the Directory info
   memcpy(&(f->DirEntry), UpDirInfo,  sizeof(RTFDirEntry));

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NamePtr[0] = 0x0;

   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   kal_wstrcpy(NamePtr, dchar_backslash_star_postfix);

   RTFSYSFreeMutex(RTFLock);
}

/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Directroy Tree Traverse Core
 *  Members:
 *          RecTravCore_DFS
 *          RecTravCore_BFS
 *          RecTravCore_Flat
 *          RecTravCore_CloseAndRootNodeAct
 *          RecTravCore_DFS_CR
 **************************************************/
/**************************************************
 * Structure Member Required
 * TravFH     --- The FileHandle To Get Next Folder
 * MyCallBack --- The CallBack To Process Found Item
 * NameBuf
 * LevelStack
 * ListFH --- The FileHandle To Get File In Current Level
 **************************************************/

void RecTravCore_DFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   int         LevelIdx=0;
   RTFDirEntry TmpDirPos;

#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;

   int         TravResult;
   WCHAR*      NamePtr;

   fp = gFS_Data.FileTable + i;
#ifdef __EFS_DEBUG__
   ASSERT(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);

   ASSERT(Act != NULL && TravCB->NameBuf != NULL);
#endif /* __EFS_DEBUG__ */

   do
   {
      // setup current folder
      kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);      
      NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
      *(++NamePtr) = 0x0;
      TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath);

      // DFS
      TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos);
      if (TravResult == RTF_NO_ERROR) // 1 folder found
      {
         if (LevelIdx == TravCB->LevelLimit) // The directory tree is too deep to reach, fail
         {
            TravCB->TravStatus = RTF_TOO_MANY_FILES;
            break;
         }

         if (kal_wstrlen(TravCB->NameBuf) + 3 > TravCB->CurrLeftLen)
         {  // The Path Length over Spec. definiation , reserve \\ , * , and \0
            TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
            break;
         }

         RecTravDownLevel(fp, TravCB->LevelStack + LevelIdx, &TmpDirPos, TravCB->NameBuf);
         LevelIdx++;
         continue;
      }
      else if (TravResult == RTF_NO_MORE_FILES) // No more folder, List all Files
      {
         int ListResult, ActResult;

         memset(&TmpDirPos, 0, sizeof(RTFDirEntry));
         ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, RTF_ATTR_DIR, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
         if (ListFH < 0)   ListResult = ListFH;
         else              ListResult = RTF_NO_ERROR;
         
         while(ListResult == RTF_NO_ERROR)
         {
            ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */);
            if (ActResult < RTF_NO_ERROR)
            {  // path over len or operation abort indication
               ListResult = ActResult;
               continue;
            }

            ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
         }
         RTFFindClose(ListFH);

         if (ListResult == RTF_NO_MORE_FILES) // No more folder, No more files
         {
            if (LevelIdx-- > 0)
            {
               RecTravUpLevelAndBackward(fp, TravCB->LevelStack + LevelIdx);
               // setup current folder
               kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);      
               NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
               *(++NamePtr) = 0x0;
               TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath);
               // Reterieve the folder name
               TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos); 
#ifdef __EFS_DEBUG__
               // Double Check
               ASSERT(TravResult == RTF_NO_ERROR);
#endif /* __EFS_DEBUG__ */
               // Act
               ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* Folder */);
               if (ActResult < RTF_NO_ERROR)
               {  // path over len or operation abort indication
                  ListResult = ActResult;
                  goto DFS_LIST_ERROR;
               }
            }
            continue;
         }
DFS_LIST_ERROR:
         TravCB->TravStatus = ListResult;
         break;
      }
      else
      {
/* DFS_TRAV_ERROR: */
         TravCB->TravStatus = TravResult;
         break;
      } /* END switch (TravResult) */
   } while (LevelIdx >= 0);
} 

void RecTravCore_BFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   int         LevelIdx=0;
   RTFDirEntry TmpDirPos;

#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;

   int         ListResult;
   int         ActResult;
   WCHAR*      NamePtr;

   fp = gFS_Data.FileTable + i;
#ifdef __EFS_DEBUG__
   ASSERT(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
 
   ASSERT(Act != NULL && TravCB->NameBuf != NULL);
#endif /* __EFS_DEBUG__ */

   do
   {
      // setup current folder
      kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);      
      NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
      *(++NamePtr) = 0x0;
      TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath);

      // BFS
      ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, RTF_ATTR_DIR, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
      if (ListFH < 0)   ListResult = ListFH;
      else              ListResult = RTF_NO_ERROR;
      
      while(ListResult == RTF_NO_ERROR)
      {
         ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */);
         if (ActResult < RTF_NO_ERROR)
         {  // path over len or operation abort indication
            ListResult = ActResult;
            continue;
         }

         ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
      }
      RTFFindClose(ListFH);

      if (ListResult == RTF_NO_MORE_FILES) // No more files, Trav Next Folder 
      {
         int TravResult;

BFS_PREV_LEVEL:
         TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos);

         if (TravResult == RTF_NO_ERROR) // 1 folder found
         {
            ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* Folder */);
            if (ActResult < RTF_NO_ERROR)
            {  // path over len or operation abort indication
               ListResult = ActResult;
               goto BFS_LIST_ERROR;
            }

            if (LevelIdx == TravCB->LevelLimit) // The directory tree is too deep to reach, fail
            {
               TravCB->TravStatus = RTF_TOO_MANY_FILES;
               break;
            }

            if ((kal_wstrlen(TravCB->NameBuf) + (NamePtr - TravCB->CurrPath) + 3) >= MT_MAXPATH_IN_WCHAR_UNIT)
            {  // The Path Length over Spec. definiation , reserve \\ , * , and \0
               TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
               break;
            }

            RecTravDownLevel(fp, TravCB->LevelStack + LevelIdx, &TmpDirPos, TravCB->NameBuf);
            LevelIdx++;
            continue;
         }
         else if (TravResult == RTF_NO_MORE_FILES) // No more files, No more folders
         {
            if (LevelIdx-- > 0)
            {
               RecTravUpLevel(fp, TravCB->LevelStack + LevelIdx);
               goto BFS_PREV_LEVEL;
            }
            continue;
         }
/* BFS_TRAV_ERROR: */
         TravCB->TravStatus = TravResult;
         break;
      }
BFS_LIST_ERROR:
      TravCB->TravStatus = ListResult;
      break;
   } while (LevelIdx >= 0);
} 

void RecTravCore_Flat(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   RTFDirEntry TmpDirPos;

#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;

   int         ListResult = RTF_NO_ERROR;
   int         ActResult;
   WCHAR*      NamePtr;

   fp = gFS_Data.FileTable + i;
#ifdef __EFS_DEBUG__
   ASSERT(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
 
   ASSERT(Act != NULL && TravCB->NameBuf != NULL);
#endif /* __EFS_DEBUG__ */

   // setup current folder
   kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);      
   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
   *(++NamePtr) = 0x0;
   TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath);

   // Flat , list all 
   ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, 0, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
   if (ListFH < 0)   ListResult = ListFH;
         
   while(ListResult == RTF_NO_ERROR)
   {
      if (TmpDirPos.Dir.FileName[0] != 0x2e) // skip dot and dot-dot
      {
         ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */);
         if (ActResult < RTF_NO_ERROR)
         {  // path over len or operation abort indication
            ListResult = ActResult;
            continue;
         }
      }
      ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, RTF_MAX_PATH);
   }
   RTFFindClose(ListFH);

   if (ListResult == RTF_NO_MORE_FILES) // No more folder, No more files
   {
      TravCB->TravStatus = RTF_NO_ERROR;
   }
   else // Error Handle of Flat
   {
      TravCB->TravStatus = ListResult;
   }
}

void RecTravCore_CloseAndRootNodeAct(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;
   WCHAR*      NamePtr;
   RTFDirEntry TmpDirPos;

   fp = gFS_Data.FileTable + i;
#ifdef __EFS_DEBUG__
   ASSERT(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
 
   ASSERT(Act != NULL && TravCB->NameBuf != NULL);
#endif /* __EFS_DEBUG__ */

   // setup Name Buf & current folder
   kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName); /* C:\Level1\* */
   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
   if (NamePtr == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "NULL NamePtr(Could not find 0x005c)");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, 0, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      return;
   }

   *NamePtr = 0x0;

   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
   if (NamePtr == NULL) /* ROOT Directory, do nothing */
   {
      return;
   }
   NamePtr++;
   kal_wstrcpy(TravCB->NameBuf, NamePtr);
   *NamePtr = 0x0;
   TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath);

   // prepare Dos Dir Entry
   memcpy(&TmpDirPos, &(fp->DirEntry), sizeof(RTFDirEntry));

   // Close Before Act
   RecTravClose(TravFH);
   
   // Act
   Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File or Dir */);

}

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
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __EFS_DEBUG__ */
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
#endif /* __P_PROPRIETARY_COPYRIGHT__ */

/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Generic CallBack Class
 *  Members:
 *          RecAct_List
 *          RecAct_CountNum
 *          RecAct_CountSize
 *          RecAct_Deletion
 *          RecAct_Copy
 *          RecAct_CopyrightDeletion
 *          RecAct_CopyrightList
 **************************************************/
/**************************************************
 * Structure Member Required
 **************************************************/
int RecAct_CountNum(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
#ifdef __EFS_DEBUG__
   ASSERT(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   if ((RES->Parameters.Flag & FS_FILTER_SYSTEM_ATTR) && (ObjInfo->Attributes & RTF_ATTR_SYSTEM))
   {
      return 0;
   }

   if ((RES->Parameters.Flag & FS_FILTER_HIDDEN_ATTR) && (ObjInfo->Attributes & RTF_ATTR_HIDDEN))
   {
      return 0;
   }

   if ((RES->Parameters.Flag & FS_DIR_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR))
   {
      RES->Parameters.Result++;   
   }
   else if ((RES->Parameters.Flag & FS_FILE_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR) == 0)
   {
      RES->Parameters.Result++;   
   }

   return 0;
}

int RecAct_CountSize(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
   UINT volatile Count = 0;
   RTFile * volatile f = NULL;
   UINT Cluster, NextCluster = 0;

#ifdef __EFS_DEBUG__
   ASSERT(RES != NULL && ObjName != NULL && ObjInfo != NULL);
   ASSERT(RES->Parameters.Drive != NULL && RES->Parameters.RAWCluster != NULL);
#endif /* __EFS_DEBUG__ */

   XTRY
      case XCODE:               
         f = ParseFileHandle(RES->Parameters.ProgInfo);
         Cluster = FIRST_FILE_CLUSTER((*ObjInfo));
         while (NextCluster < RTF_CLUSTER_CHAIN_END)
         {
            NextCluster = RES->Parameters.RAWCluster(RES->Parameters.Drive, Cluster);
            if (NextCluster < 2)
               break;
               
            Count++;
            Cluster = NextCluster;
         }
      default:
         break;
      case XFINALLY:
         if (f != NULL)
         {
            UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   if (RES->Parameters.Flag & FS_COUNT_IN_CLUSTER)
   {
      RES->Parameters.Result += Count;
   }
   else if (RES->Parameters.Flag & FS_COUNT_IN_BYTE)
   {
      RES->Parameters.Result += Count << RES->Parameters.Drive->ClusterShift;
   }

   return 0;
}

int RecAct_Deletion(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
   int result = RTF_NO_ERROR;

#ifdef __EFS_DEBUG__
   ASSERT(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   if ((RES->Parameters.Flag & FS_XDEL_ABORT_WATCH) && (g_Xdelete != KAL_TRUE))
      return MT_ABORTED_ERROR;

   if (kal_wstrlen(ObjName) > RES->CurrLeftLen)
   {  // The Path Length of that file over Spec. definiation 
      return MT_PATH_OVER_LEN_ERROR;
   }

   kal_wstrcpy(RES->DestPath, RES->CurrPath);
   kal_wstrcat(RES->DestPath, ObjName);

   if ((RES->Parameters.Flag & FS_DIR_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR))
   {
      result = RTFRemoveDir(RES->DestPath);
//      if (result < 0) return 0; /* Ignore Fail on Folder Deletion */
      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
      }
      RES->Parameters.Result++;
   }
   else if ((RES->Parameters.Flag & FS_FILE_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR) == 0)
   {
      result = RTFDelete(RES->DestPath);
      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
         return 1;
      }
      RES->Parameters.Result++;
   }

   return 0;
}

#ifdef __FS_MOVE_SUPPORT__
int RecAct_Copy(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
   int result = RTF_NO_ERROR;
   int Len_Curr, Len_Obj;

#ifdef __EFS_DEBUG__
   ASSERT(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   Len_Curr = kal_wstrlen(RES->CurrPath);
   Len_Obj  = kal_wstrlen(ObjName);

   if (Len_Obj > RES->CurrLeftLen)
   {  // The Src Path Length of that file over Spec. definiation 
      return MT_PATH_OVER_LEN_ERROR;
   }

   if (Len_Curr - RES->PrefixPathLen + RES->DestPrefixPathLen + Len_Obj > MT_MAXPATH_IN_WCHAR_UNIT)
   {  // The Dest Path Length of that file over Spec. definiation 
      return MT_PATH_OVER_LEN_ERROR;
   }

   kal_wstrcpy(RES->DestPath + RES->DestPrefixPathLen, RES->CurrPath + RES->PrefixPathLen);
   kal_wstrcat(RES->DestPath, ObjName);

   if (ObjInfo->Attributes & RTF_ATTR_DIR)
   {
      result = RTFCreateDir(RES->DestPath);
      if (result < 0) return 0; /* Ignore Fail on Folder Creation */
      RES->Parameters.Result++;
   }
   else
   {
      /* Note :  Here we will borrow RES->CurrPath to store full source path */
      kal_wstrcat(RES->CurrPath, ObjName);

      if ((RES->Parameters.Flag & (MT_XMOVE_SAME_DRIVE|MT_XMOVE_COPYSECTOR)) == (MT_XMOVE_SAME_DRIVE|MT_XMOVE_COPYSECTOR))
      {
         result = CopyFileOnSameDrive(RES->CurrPath, RES->DestPath, RES->Parameters.Progress);
      }
      else
      {
         result = CopyFileLightWeight(RES->CurrPath, RES->DestPath, RES->Parameters.Progress);
      }
      /* Note :  Here we will return RES->CurrPath to store full source path */
      RES->CurrPath[Len_Curr] = 0x0;

      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
         return MT_ABORTED_ERROR;
      }
      RES->Parameters.Result++;
   }

   if (RES->Parameters.Progress)
   {
      RES->Parameters.Progress(FS_MOVE_PGS_ING, RES->Parameters.Total, RES->Parameters.Result, RES->Parameters.ProgInfo);
   }

   return 0;
}
#endif /* __FS_MOVE_SUPPORT__ */

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
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
#endif /* __P_PROPRIETARY_COPYRIGHT__ */

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
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __P_PROPRIETARY_COPYRIGHT__ */
/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Engine Configure Utilities
 *  Members:
 *          RecConf_Alloc
 *          RecConf_Free
 **************************************************/

void RecConf_Alloc(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize)
{
   kal_char                    *bufptr;
   InternRecursiveEngineStruct *RESptr;

   /* Memory Usage : 64 + 3 * ((520+4) + 4) = 1648 */
   bufptr = get_ctrl_buffer(sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE);

   memset(bufptr, 0, sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE);

   RESptr = (InternRecursiveEngineStruct *) bufptr;
   if (RecursiveStack == NULL)
   {
      RESptr->LevelStack = get_ctrl_buffer(RECCONF_DIRSTACK_SIZE);
      RESptr->LevelLimit = RECCONF_DIRSTACK_SIZE / sizeof(RTFDirEntry);
   }
   else
   {
      /* Must 4-Byte align buffer pointer, stop dangerous usage early */
      EXT_ASSERT( ((UINT)RecursiveStack & 0x03) == 0x00, (UINT)RecursiveStack, StackSize, 0);
      RESptr->LevelStack = (void *)RecursiveStack;
      RESptr->LevelLimit = StackSize / sizeof(RTFDirEntry);
   }

   bufptr          += sizeof(InternRecursiveEngineStruct);
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->CurrPath = (WCHAR*)(bufptr + sizeof(int));

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->NameBuf  = (WCHAR*)(bufptr + sizeof(int));

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->DestPath = (WCHAR*)(bufptr + sizeof(int));

   *RES = RESptr;
}

void RecConf_Free(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize)
{
   kal_char                    *bufptr;

   /* Check RECCONF_NAMEBUF_GUARD_PRINT */
   bufptr = (void *)(*RES);
   bufptr          += sizeof(InternRecursiveEngineStruct);
   ASSERT(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   ASSERT(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   ASSERT(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);
   
   /* Free Memory */
   if (RecursiveStack == NULL)
   {
      free_ctrl_buffer((*RES)->LevelStack);
   }
   free_ctrl_buffer((*RES));
   *RES = NULL;
}

/* ------------------------------------------------------------------------------- */
/**************************************************
 *  Recursive Type API Auxiliary Sub-Routines
 *  Members:
 *          RecAUX_IsFolder
 *          RecAUX_IsFolderRW
 *          RecAUX_TestSrcAndDestPath
 *          RecAUX_CountNumOfObjUnderFolderTree
 *          RecAUX_CountSumOfSizeUnderFolderTree
 *          RecAUX_XDeleteFolder
 *          RecAUX_XCopyFolder
 **************************************************/
int RecAUX_IsFolder(const WCHAR * PathName)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathName);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)PathName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_PARAM_ERROR);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

int RecAUX_IsFolderRW(const WCHAR * PathName)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathName);
         if (f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            XRAISE(RTF_WRITE_PROTECTION);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)PathName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_PARAM_ERROR);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

/**********************************************************
 * RecAUX_TestSrcAndDestPath   ---- The sub-routine to check source full path and destination full path
 * RETURNS
 *    < RTF_NO_ERROR , serious error
 *    >= 0           , Value that combination of MT_XMOVE_XXX bit flag
 *
 **********************************************************/
int RecAUX_TestSrcAndDestPath(const WCHAR * SrcPathName, const WCHAR * DestPathName)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;

   XTRY
      case XCODE:
         /* TestSrcAndDestPath - 1 : Process SrcPathName basic test */
         f1 = ParseFileName((char *)SrcPathName);
         if (f1->SpecialKind == FileMapFile)
         {
            Result |= MT_XMOVE_SRC_IS_VIRTUAL;
         }
         else
         {
            if (f1->SpecialKind != NormalFile)
               XRAISE(RTF_INVALID_FILENAME);
            if (!SearchFile(f1, SEARCH_FILES, (char *)SrcPathName, NULL))
               XRAISE(RTF_PATH_NOT_FOUND);
            CheckNotOpen(f1);
         }

         /* TestSrcAndDestPath - 2 : Try to access DestPathName, f2 */
         RTFSYSFreeMutex(RTFLock);

         f2 = ParseFileName((char *)DestPathName);
         if (f2->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (f2->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            XRAISE(RTF_WRITE_PROTECTION);

         /* TestSrcAndDestPath - 3 : set result accroding to f1     */
         Result |= MT_XMOVE_SRC_EXIST;
         if (f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
            Result |= MT_XMOVE_SRC_IS_FOLDER;
         if (f1->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
            Result |= MT_XMOVE_SRC_ATTR_RO;
         if (f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            Result |= MT_XMOVE_SRC_DEVICE_RO;

         /* TestSrcAndDestPath - 4 : set result accroding to f2     */
         if (SearchFile(f2, SEARCH_FILES, (char *)DestPathName, NULL))
         {
            Result |= MT_XMOVE_DEST_EXIST;
            CheckNotOpen(f2);
            if (f2->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
               Result |= MT_XMOVE_DEST_IS_FOLDER;
            if (f2->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
               Result |= MT_XMOVE_DEST_ATTR_RO;
         }
         if (f2->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            Result |= MT_XMOVE_DEST_DEVICE_RO;

         /* TestSrcAndDestPath - 5 : set result accroding to f1,f2  */
         if (f1->Dev == f2->Dev)
            Result |= MT_XMOVE_SAME_DEVICE;
         if (f1->Drive == f2->Drive)
            Result |= MT_XMOVE_SAME_DRIVE;
         if (f2->Dev->Driver->CopySectors != NULL)
            Result |= MT_XMOVE_COPYSECTOR;

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
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, f1->Dev, RTF_INFINITE); /* it may raise an exception after release the system lock */
            FreeFTSlotAndDevice(f1);
         }
         break;
   XEND_API

   return Result;
}

/**********************************************************
 * RecAUX_CountNumOfObjUnderFolderTree   ---- The sub-procedure to do FS_Count
 *
 **********************************************************/
int RecAUX_CountNumOfObjUnderFolderTree(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* CountNumOfObjUnderFolderTree - 1 : Setup InternRecursiveEngineStruct & Resources */
   RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   ReCB->Parameters.Flag = Flag;

   /* CountNumOfObjUnderFolderTree - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, L"\\*");
   TravFH = RecTravStart(ReCB->NameBuf);
   if (TravFH < 0)
   {
      Result = TravFH;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravStart Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else
   {

   /* CountNumOfObjUnderFolderTree - 3 : Recusrive Traverse Call */
   if (Flag & FS_RECURSIVE_TYPE)
   {
      RecTravCore_BFS(ReCB, TravFH, RecAct_CountNum);
      RecTravClose(TravFH);
   }
   else
   {
      RecTravCore_Flat(ReCB, TravFH, RecAct_CountNum);
      RecTravClose(TravFH);
   }

   /* CountNumOfObjUnderFolderTree - 4 : Check Result and Error Status after Recusrive Call */
   if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
   {
      Result = ReCB->TravStatus;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravCore Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
   {
      Result = ReCB->Parameters.ErrorCode;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTrav Action Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else /* Success */
   {
      Result = ReCB->Parameters.Result;
   }
   
   } /* if RecTracStart(...) */

   /* CountNumOfObjUnderFolderTree - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}
/**********************************************************
 * RecAUX_CountSumOfSizeUnderFolderTree   ---- The sub-procedure to do FS_GetFolderSize
 *
 **********************************************************/
int RecAUX_CountSumOfSizeUnderFolderTree(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* CountSumOfSizeUnderFolderTree - 1 : Setup InternRecursiveEngineStruct & Resources */
   RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   ReCB->Parameters.Flag = Flag;

   /* CountSumOfSizeUnderFolderTree - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, L"\\*");
   TravFH = RecTravStart(ReCB->NameBuf);
   if (TravFH < 0)
   {
      Result = TravFH;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravStart Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else
   {

   /* CountSumOfSizeUnderFolderTree - 3 : Recusrive Traverse Call */
   if ((BYTE)FullPath[0] == (BYTE)DrvMappingNew) //Capital 'Z'
   {
      ReCB->Parameters.Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
   }
   else
   {
      ReCB->Parameters.Drive = &gFS_Data.DriveTable[(BYTE)(FullPath[0]) - MT_BASE_DRIVE_LETTER];
   }

   switch (ReCB->Parameters.Drive->FATType)
   {
      case 12:   ReCB->Parameters.RAWCluster = ScanFAT12_GetRAWClusterValue; break;
      case 16:   ReCB->Parameters.RAWCluster = ScanFAT16_GetRAWClusterValue; break;
      case 32:   ReCB->Parameters.RAWCluster = ScanFAT32_GetRAWClusterValue; break;
      default:   ASSERT(0);
   }
   ReCB->Parameters.ProgInfo = TravFH;

   RecTravCore_BFS(ReCB, TravFH, RecAct_CountSize);
   RecTravCore_CloseAndRootNodeAct(ReCB, TravFH, RecAct_CountSize);

   /* CountSumOfSizeUnderFolderTree - 4 : Check Result and Error Status after Recusrive Call */
   if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
   {
      Result = ReCB->TravStatus;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravCore Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
   {
      Result = ReCB->Parameters.ErrorCode;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTrav Action Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else /* Success */
   {
      Result = ReCB->Parameters.Result;
   }
   
   } /* if RecTracStart(...) */

   /* CountSumOfSizeUnderFolderTree - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}

/**********************************************************
 * RecAUX_XDeleteFolder   ---- The sub-procedure to do FS_XDelete
 *
 **********************************************************/
int RecAUX_XDeleteFolder(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* XDeleteFolder - 1 : Setup InternRecursiveEngineStruct & Resources */
   RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   ReCB->Parameters.Flag = Flag;

   /* XDeleteFolder - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, L"\\*");
   TravFH = RecTravStart(ReCB->NameBuf);
   if (TravFH < 0)
   {
      Result = TravFH;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravStart Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else
   {

   /* XDeleteFolder - 3 : Recusrive Traverse Call */
   if (Flag & FS_RECURSIVE_TYPE)
   {
      RecTravCore_DFS(ReCB, TravFH, RecAct_Deletion);
      RecTravCore_CloseAndRootNodeAct(ReCB, TravFH, RecAct_Deletion);
   }
   else
   {
      RecTravCore_Flat(ReCB, TravFH, RecAct_Deletion);
      RecTravClose(TravFH);
   }

   /* XDeleteFolder - 4 : Check Result and Error Status after Recusrive Call */
   if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
   {
      Result = ReCB->TravStatus;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravCore Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
   {
      Result = ReCB->Parameters.ErrorCode;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTrav Action Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else /* Success */
   {
      Result = ReCB->Parameters.Result;
   }
   
   } /* if RecTracStart(...) */

   /* XDeleteFolder - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}

#ifdef __FS_MOVE_SUPPORT__
/**********************************************************
 * RecAUX_XCopyFolder   ---- The sub-procedure to do FS_Move
 *
 **********************************************************/
int RecAUX_XCopyFolder(const WCHAR * FullPath, const WCHAR * DstPath, int Status,
                       FS_ProgressCallback Progress, UINT Total, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* XCopyFolder - 1 : Setup InternRecursiveEngineStruct & Resources */
   RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   ReCB->Parameters.Flag     = (Status & (MT_XMOVE_SAME_DRIVE | MT_XMOVE_SAME_DEVICE));
   ReCB->Parameters.Progress = Progress;
   ReCB->Parameters.Total    = Total;

   /* XCopyFolder - 2 : Start a Traverse Handle */
   ReCB->DestPrefixPathLen   = kal_wstrlen(DstPath);
   ReCB->PrefixPathLen       = kal_wstrlen(FullPath);

   kal_wstrcpy(ReCB->DestPath, DstPath);
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, L"\\*");

   TravFH = RecTravStart(ReCB->NameBuf);
   if (TravFH < 0)
   {
      Result = TravFH;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravStart Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else
   {

   /* XCopyFolder - 3 : Recusrive Traverse Call */
   ReCB->Parameters.ProgInfo = TravFH;
   RecTravCore_BFS(ReCB, TravFH, RecAct_Copy);
   RecTravClose(TravFH);

   /* XCopyFolder - 4 : Check Result and Error Status after Recusrive Call */
   if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
   {
      Result = ReCB->TravStatus;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTravCore Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
   {
      Result = ReCB->Parameters.ErrorCode;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "RecTrav Action Error");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 3 , __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
   }
   else /* Success */
   {
      Result = ReCB->Parameters.Result;
   }
   
   } /* if RecTracStart(...) */

   /* XCopyFolder - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}
#endif /* __FS_MOVE_SUPPORT__ */
