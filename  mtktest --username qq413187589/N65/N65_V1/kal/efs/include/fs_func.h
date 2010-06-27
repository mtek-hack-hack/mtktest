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
 *	fs_func.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file declares the exported APIs
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FS_TYPE_H
#error "Please include fs_type.h first..."
#endif

#ifndef _FS_FUNC_H
#define _FS_FUNC_H

// General I/O
extern int FS_Open(const WCHAR * FileName, UINT Flag);
extern int FS_OpenHint(const WCHAR * FileName, UINT Flag, FS_FileLocationHint * DSR_Hint);
extern int FS_Close(FS_HANDLE FileHandle);
extern int FS_CloseAll(void);
extern int FS_Read(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read);
extern int FS_Write(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written);
extern int FS_SetSeekHint(FS_HANDLE FileHandle, UINT HintNum, FS_FileLocationHint * Hint);
extern int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence);
extern int FS_Commit(FS_HANDLE FileHandle);
extern int FS_ReleaseFH(void * TaskId);
extern int FS_Abort(UINT ActionHandle);
extern int FS_ParseFH(FS_HANDLE FileHandle);
extern int FS_GenVirtualFileName(FS_HANDLE FileHandle, WCHAR * VFileNameBuf, UINT BufLength, UINT VFBeginOffset, UINT VFValidLength);

//Information
extern int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo);
extern int FS_GetFileSize(FS_HANDLE FileHandle, UINT * Size);
extern int FS_GetFilePosition(FS_HANDLE FileHandle, UINT * Position);
extern int FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time);
extern int FS_GetAttributes(const WCHAR * FileName);
extern int FS_GetFirstCluster(FS_HANDLE FileHandle, UINT * Cluster);

//File Only Operation
extern int FS_SetAttributes(const WCHAR * FileName, BYTE Attributes);
extern int FS_Delete(const WCHAR * FileName);
extern int FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2);
extern int FS_CheckFile(const WCHAR * FileName);

//Folder Only Operation
extern int FS_GetCurrentDir(WCHAR * DirName, UINT MaxLength);
extern int FS_SetCurrentDir(const WCHAR * DirName);
extern int FS_CreateDir(const WCHAR * DirName);
extern int FS_RemoveDir(const WCHAR * DirName);
extern int FS_GetFolderSize(const WCHAR *DirName, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);

//File and Folder Operations
extern int FS_Extend(FS_HANDLE FileHandle, UINT Length);
extern int FS_Truncate(FS_HANDLE FileHandle);
extern int FS_MakeFileName(FS_HANDLE FileHandle, UINT Flag, WCHAR * FileName, UINT MaxLength);
extern int FS_Rename(const WCHAR * FileName, const WCHAR * NewName);

#ifdef __FS_MOVE_SUPPORT__
extern int FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, UINT Flag, FS_ProgressCallback Progress, BYTE *RecursiveStack, const UINT StackSize);
#endif

extern int FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
extern int FS_XDelete(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);

//Find File
extern int FS_FindFirst(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);
extern int FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);
extern int FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT EntryIndex, UINT Flag);
extern int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT Flag);
extern int FS_FindClose(FS_HANDLE FileHandle);

#ifdef __FS_SORT_SUPPORT__
extern int FS_XFindReset(const WCHAR * Pattern, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, BYTE AttrMask, UINT Flag, UINT Timeout, UINT * Position);
extern int FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT Index, UINT * Position, UINT Flag);
extern int FS_XFindClose(UINT * Position);
#endif

//Drive Management
extern int FS_GetDrive(UINT Type, UINT Serial, UINT AltMask);
extern int FS_GeneralFormat(const WCHAR * DriveName, UINT Level, FS_FormatCallback Progress);
extern int FS_GetClusterSize(UINT DriveIdx);
#ifdef __FS_QM_SUPPORT__
extern int FS_QmGetFree(const BYTE * Path);
#endif
extern int FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, BYTE MediaDescriptor, UINT MinSectorsPerCluster, UINT Flags);
extern int FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo);
extern int FS_CommitAll(const WCHAR * DriveName);
extern int FS_MappingDrive(UINT UpperOldDrv, UINT UpperNewDrv);

//Power Lost Detection and Recovery
extern int FS_SetDiskFlag(void);
extern int FS_CheckDiskFlag(void);
extern int FS_ClearDiskFlag(void);
#ifdef __FS_CHECKDRIVE_SUPPORT__
extern int FS_CheckDrive(const UINT DriveIdx, BYTE * CheckBuffer, const UINT CheckBufferSize);
#endif

//Disk Management
extern int FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry);
extern int FS_SplitPartition(void * MasterBootRecord, UINT Sectors);
extern int FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags);
extern int FS_GetDevType(const WCHAR * Path);
extern int FS_GetDevStatus(UINT DriveIdx, UINT Flag);
extern int FS_GetDevPartitions(UINT QueryTarget);

//Card management
extern int FS_TestMSDC(void *slot_id);
extern int FS_CloseMSDC(UINT MSDCIndex, UINT Mode);

//OTG Card Reader Management 
extern int FS_ConfigExtDevice(int Action, FS_Driver *DrvFuncs, int Slots, void **SlotIdArray, int *SlotsConfiged);

//File System Run-Time LifeCycle
extern void FS_ShutDown(void);
extern int FS_UnlockAll(void);
extern int FS_SanityCheck(void);
extern int FS_LockFAT(UINT Type);

//File System Run-Time Debug
extern int FS_CountUsedFH(int flag);
#ifdef __FS_TRACE_SUPPORT__
extern int FS_SetTrace(UINT Flag, UINT Timeout);
extern int FS_DumpFHTable(void);
#endif

//Copyright
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//DirCache
extern int FS_SetDirCache(FS_HANDLE FileHandle, UINT NewValue);
extern int FS_GetDirCache(FS_HANDLE FileHandle, UINT *CurrValue);
extern int FS_ExpireDirCache(FS_HANDLE FileHandle);

//Flash Device Direct IO
extern int FS_OTPWrite(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length);
extern int FS_OTPRead(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length);
extern int FS_OTPQueryLength(int devtype, UINT *Length);
extern int FS_OTPLock(int devtype);

//Flash Sweep or Recover
extern int FS_SweepDevice(const int devtype);
extern int FS_RecoverDevice(const int devtype);
#endif //_FS_FUNC_H


