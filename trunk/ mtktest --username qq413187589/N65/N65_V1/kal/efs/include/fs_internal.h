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
 *	fs_internal.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _FS_INTERNAL_H
#define _FS_INTERNAL_H

/************************* Internal Define *************************/
#define MT_REC_RMDIR             0x00000001           //MTExtDelete
#define MT_REC_SAVE_NAME         0x00000002           //MTExtFindReset
#define MT_MAX_MSDC_TYPE         3                    //MTTestMSDC, MTCloseMSDC
#define MT_MAX_FILE_NUM          256                  //MTExtFindReset: max file/folder number under one folder
#define CopyBufferSize           512*4                //CopyFile, GetSaveNameByIndex
#define MT_PGS_PERCENTAGE        5                    //CopyFile
#define MT_PGS_PERIOD_MASK       0xfffffff0           //CopyFileLightWeight(), trigger user call back every 16 frame ~ 72ms
#define MT_MAX_WIDE_NAME         512
#define MT_MAX_WIDE_PATH         RTF_MAX_PATH + 4     //+4 for recursive action
#define MT_MAX_QUOTA_ENTRY       40                   //For gFS_ExtQuotaSet entry 
#define MT_MAXPATH_IN_WCHAR_UNIT 260                  //RTF_MAX_PATH = 520 char = 260 wide-char
   //FS_Move internal flag to distinguish status
#define MT_XMOVE_SRC_EXIST       0x00000001           //will be forbidden initial if fail
#define MT_XMOVE_SRC_IS_FOLDER   0x00000002
#define MT_XMOVE_SRC_IS_VIRTUAL  0x00000004
#define MT_XMOVE_SRC_ATTR_RO     0x00000008
#define MT_XMOVE_SRC_DEVICE_RO   0x00000010
#define MT_XMOVE_DEST_EXIST      0x00000100
#define MT_XMOVE_DEST_IS_FOLDER  0x00000200
#define MT_XMOVE_DEST_ATTR_RO    0x00000400
#define MT_XMOVE_DEST_DEVICE_RO  0x00000800           //will be forbidden initial if fail
#define MT_XMOVE_SAME_DRIVE      0x00001000
#define MT_XMOVE_SAME_DEVICE     0x00002000
#define MT_XMOVE_COPYSECTOR      0x00004000
   // Recursive Config
#define RECCONF_NAMEBUF_GUARD_PRINT     (0xF5F5FAFA)
#define RECCONF_NAMEBUF_PACKAGE_SIZE    (RTF_MAX_PATH + 4 /* additional null */ + sizeof(int) /* guard */)
#define RECCONF_DIRSTACK_SIZE           (39 * sizeof(RTFDirEntry)) // 39 * 52 = 2028

typedef enum
{
   API_ENUM_OPEN = 1,
   API_ENUM_OPENHINT,
   API_ENUM_CLOSE,
   API_ENUM_CLOSEALL,
   API_ENUM_READ,
   API_ENUM_WRITE,
   API_ENUM_SETSEEKHINT,
   API_ENUM_SEEK,
   API_ENUM_COMMIT,
   API_ENUM_RELEASEFH,
   API_ENUM_ABORT,
   API_ENUM_PARSEFH,
   API_ENUM_GETFILEINFO,
   API_ENUM_GETFILESIZE,
   API_ENUM_GETFILEPOSITION,
   API_ENUM_SETFILETIME,
   API_ENUM_GETATTRIBUTES,
   API_ENUM_GETFIRSTCLUSTER,
   API_ENUM_SETATTRIBUTES,
   API_ENUM_DELETE,
   API_ENUM_PSEUDOMERGE,
   API_ENUM_CHECKFILE,
   API_ENUM_GETCURRENTDIR,
   API_ENUM_SETCURRENTDIR,
   API_ENUM_CREATEDIR,
   API_ENUM_REMOVEDIR,
   API_ENUM_GETFOLDERSIZE,
   API_ENUM_EXTEND,
   API_ENUM_TRUNCATE,
   API_ENUM_MAKEFILENAME,
   API_ENUM_RENAME,
   API_ENUM_MOVE,
   API_ENUM_COUNT,
   API_ENUM_XDELETE,
   API_ENUM_FINDFIRST,
   API_ENUM_FINDNEXT,
   API_ENUM_FINDFIRSTN,
   API_ENUM_FINDNEXTN,
   API_ENUM_FINDCLOSE,
   API_ENUM_XFINDRESET,
   API_ENUM_XFINDSTART,
   API_ENUM_XFINDCLOSE,
   API_ENUM_CREATEBOOTSECTOR,
   API_ENUM_GETPARTITIONINFO,
   API_ENUM_COMMITALL,
   API_ENUM_GETDRIVE,
   API_ENUM_MAPPINGDRIVE,   
   API_ENUM_GENERALFORMAT,
   API_ENUM_QMGETFREE,
   API_ENUM_GETCLUSTERSIZE,
   API_ENUM_CHECKDRIVE,
   API_ENUM_CREATEMASTERBOOTRECORD,
   API_ENUM_SPLITPARTITION,
   API_ENUM_GETDISKINFO,
   API_ENUM_SHUTDOWN,
   API_ENUM_UNLOCKALL,
   API_ENUM_SANITYCHECK,
   API_ENUM_SETDISKFLAG,
   API_ENUM_CHECKDISKFLAG,
   API_ENUM_CLEARDISKFLAG,
   API_ENUM_GETDEVTYPE,
   API_ENUM_GETDEVSTATUS,
   API_ENUM_LOCKFAT,
   API_ENUM_TESTMSDC,
   API_ENUM_CLOSEMSDC,
   API_ENUM_SETTRACE,
   API_ENUM_DUMPFHTABLE,
   API_ENUM_GENVIRTUALFILENAME,
   API_ENUM_CONFIGEXTDEVICE,
   API_ENUM_GETDIRCACHE,
   API_ENUM_SETDIRCACHE,
   API_ENUM_EXPIREDIRCACHE,
   API_ENUM_OTPREAD,
   API_ENUM_OTPWRITE,
   API_ENUM_OTPLOCK,
   API_ENUM_OTPQUERYLENGTH,
   API_ENUM_SWEEPDEVICE,
   API_ENUM_COUNTUSEDFH,
   API_ENUM_GETDEVPARTITIONS,
   API_ENUM_RECOVERDEVICE
}FS_API_ENUM;

/* ---  ScanDrive Engine Internal Usage */
typedef RTFCluster MTRAWClusterValue(RTFDrive * Drive, RTFCluster Cluster);

typedef struct __InternScanDataStruct {
   RTFDrive             * Drive;
   MTRAWClusterValue    * RAWCluster;
   BYTE                 * ClusterMap;
   RTFDOSDirEntry         D;
   RTFCluster             ClsOffset;
   RTFCluster             ClsSpan;
   RTFCluster             ClsRange;
}InternScanDataStruct;

/* ---  Recursive Engine Internal Usage, Act priviate data */
typedef struct __InternCallBackParameter {
   // Configured parameter
   DWORD                  Flag;
   FS_ProgressCallback  * Progress;
   UINT                   Total;
   UINT                   ProgInfo;
   // Final Result and Status
   int                    Result;
   int                    ErrorCode;
   // Run-Time Self-Use Context, Optional for temporal / sparital coherence
   RTFDrive             * Drive;
   MTRAWClusterValue    * RAWCluster;
}InternCallBackData;

typedef struct __InternRecursiveEngineStruct {
   // Run-Time Used Resource
   WCHAR                * NameBuf;
   WCHAR                * CurrPath;
   WCHAR                * DestPath;         /* 3rd Name Buffer used by XDelete or XCopy */
   RTFDirEntry          * LevelStack;
   // Boundary Check
   int                    LevelLimit;
   UINT                   CurrLeftLen;
   // Final Result and Status
   int                    TravStatus;
   // Configure-Time Setup , Generic CallBack Functions
   UINT                   PrefixPathLen; /* Length of the Prefix Path in CurrPath */
   UINT                   DestPrefixPathLen; /* Length of the Prefix Path in DestPath */
   InternCallBackData     Parameters;
}InternRecursiveEngineStruct;

typedef int MTGenericCallBack(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo);

/************************* Internal APIs *************************/
extern void SweepDrive(BYTE DriveIdx);
extern int  ChkQuotaConfig(BYTE DriveIdx);
extern void CloseDevice(RTFDevice * Dev);
extern int  ReleaseFH(void * TaskId);
extern int  CountUsedFH(void * TaskId);

#ifdef __FS_MOVE_SUPPORT__
extern int  CopyFileLightWeight(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress);
extern int  CopyFileOnSameDrive(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress);
#endif

#ifdef __FS_SORT_SUPPORT__
extern int  GetFindByPos(const WCHAR * Pattern, RTFDOSDirEntry * FileInfo, WCHAR * FileName, DWORD MaxLength, RTFDirLocation * Pos, DWORD Flag);
extern int  Sort(const WCHAR * FileName, WCHAR * TmpName, RTFDOSDirEntry * FileInfo, DWORD Flag, RTFDirLocation * PosList, DWORD * Hex, DWORD Index, const WCHAR * Pattern, RTFDirLocation * Pos);
#endif

extern int  FindFirst(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, DWORD PatternNum, BYTE ArrayMask, BYTE Attr, BYTE AttrMask, RTFDOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, RTFDirLocation * Pos_Hint);
extern int  FindNext(RTFHANDLE Handle, FS_Pattern_Struct * PatternArray, DWORD PatternNum, BYTE ArrayMask, RTFDOSDirEntry * FileInfo, WCHAR * FileName, DWORD MaxLength, RTFDirLocation * Pos_Hint);

#ifdef __FS_QM_SUPPORT__ 
extern void SweepDrive(BYTE DriveIdx);
#endif

#ifdef __FS_CHECKDRIVE_SUPPORT__
extern int  ScanDrive(RTFDrive * Drive, void * Buffer, unsigned int BufferLen);
#endif

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

extern int MTMakeFileName(RTFDrive * Drive, RTFDirLocation * Pos, WCHAR * FileName, UINT MaxLength);
extern int MTGenVirtualFileName(FS_HANDLE F, WCHAR * VFNBuf, UINT BufLen, UINT Offset, UINT Length);
extern int FindDeviceNumberByDriveIdx(int DriveIdx);
extern RTFDevice * FindFirstDeviceByType(FS_DEVICE_TYPE_ENUM);
extern int MountRemovableDevice(RTFDevice *Dev);
extern int ReMountDriveAndCountFreeClusters(RTFDrive *Drive);

      /* Object (File/Folder) Identify */
extern int GetFirstClusterByFileHandle(RTFHANDLE FileHandle, UINT * Cluster);
extern int GetFirstClusterByFileName(const WCHAR *FileName, UINT * Cluster);

      /* Recursive Class -- Engine */
RTFHANDLE RecTravStart(WCHAR * PathNamePattern);
int RecTravClose(RTFHANDLE Handle);

      /* Recursive Class -- Search */
void RecTravCore_DFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act);
void RecTravCore_BFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act);
void RecTravCore_Flat(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act);
void RecTravCore_CloseAndRootNodeAct(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act);
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

      /* Recursive Class -- Action */
int RecAct_List(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo);
int RecAct_CountNum(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo);
int RecAct_CountSize(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo);
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif

      /* Recursive Class -- Config */
void RecConf_Alloc(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize);
void RecConf_Free(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize);

      /* Recursive Class -- API auxilary */
int RecAUX_IsFolder(const WCHAR * PathName);
int RecAUX_IsFolderRW(const WCHAR * PathName);
int RecAUX_TestSrcAndDestPath(const WCHAR * SrcPathName, const WCHAR * DestPathName);
int RecAUX_CountNumOfObjUnderFolderTree(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
int RecAUX_CountSumOfSizeUnderFolderTree(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
int RecAUX_XDeleteFolder(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
int RecAUX_XCopyFolder(const WCHAR * FullPath, const WCHAR * DstPath, int Status,
                       FS_ProgressCallback Progress, UINT Total,
                       BYTE *RecursiveStack, const UINT StackSize);

/************* Internal Data *************/
#ifdef __FS_CHECKDRIVE_SUPPORT__
extern kal_bool g_CheckDrive;
#endif

extern kal_bool g_Xdelete;
extern kal_bool g_ExternalDevice;

extern UINT FS_MAX_COPY_CLUSTER;

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
#endif

#endif //_FS_INTERNAL_H


