/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ws2san.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Id: ws2san.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Date: 2007/05/17 07:25:42 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: ws2san.h,v $
* Revision 1.1  2007/05/17 07:25:42  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2007
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ws2san.h,v 1.1 2007/05/14 09:47:06 bw Exp $
*
* ~Id: ws2san.h,v 1.1 2007/05/14 09:47:06 bw Exp $
*
* ~Date: 2007/05/14 09:47:06 $
*
* ~Name: 1.1 $
*
* ~Locker$
*
* ~Revision: 1.1 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: ws2san.h,v $
* Revision 1.1  2007/05/14 09:47:06  bw
* UNI@bw_20070514 17:21:01 MTK初始版本.合并U25V20到U26V28.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ws2san.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Id: ws2san.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Date: 2007/04/04 06:51:40 $
*
* ~Name: 1.2 $
*
* ~Locker$
*
* ~Revision: 1.2 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: ws2san.h,v $
* Revision 1.2  2007/04/04 06:51:40  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ws2san.h
 *
 * WinSock Direct (SAN) support
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __WS2SAN_H
#define __WS2SAN_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include <winsock2.h>
#include "ntddk.h"


#define WSPAPI STDCALL

/* FIXME: Unknown definitions */
typedef PVOID LPWSPDATA;
typedef PDWORD LPWSATHREADID;
typedef PVOID LPWSPPROC_TABLE;
typedef struct _WSPUPCALLTABLEEX WSPUPCALLTABLEEX;
typedef WSPUPCALLTABLEEX *LPWSPUPCALLTABLEEX;

#define SO_MAX_RDMA_SIZE                  0x700D
#define SO_RDMA_THRESHOLD_SIZE            0x700E

#define WSAID_REGISTERMEMORY \
  {0xC0B422F5, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_DEREGISTERMEMORY \
  {0xC0B422F6, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_REGISTERRDMAMEMORY \
  {0xC0B422F7, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_DEREGISTERRDMAMEMORY \
  {0xC0B422F8, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_RDMAWRITE \
  {0xC0B422F9, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_RDMAREAD \
  {0xC0B422FA, 0xF58C, 0x11d1, {0xAD, 0x6C, 0x00, 0xC0, 0x4F, 0xA3, 0x4A, 0x2D}}

#define WSAID_MEMORYREGISTRATIONCACHECALLBACK \
  {0xE5DA4AF8, 0xD824, 0x48CD, {0xA7, 0x99, 0x63, 0x37, 0xA9, 0x8E, 0xD2, 0xAF}}

typedef struct _WSABUFEX {
	u_long  len; 
	char FAR  *buf; 
	HANDLE  handle; 
} WSABUFEX, FAR * LPWSABUFEX;

#if 0
typedef struct _WSPUPCALLTABLEEX {
	LPWPUCLOSEEVENT  lpWPUCloseEvent;
	LPWPUCLOSESOCKETHANDLE  lpWPUCloseSocketHandle;
	LPWPUCREATEEVENT  lpWPUCreateEvent;
	LPWPUCREATESOCKETHANDLE  lpWPUCreateSocketHandle;
	LPWPUFDISSET  lpWPUFDIsSet;
	LPWPUGETPROVIDERPATH  lpWPUGetProviderPath;
	LPWPUMODIFYIFSHANDLE  lpWPUModifyIFSHandle;
	LPWPUPOSTMESSAGE  lpWPUPostMessage;
	LPWPUQUERYBLOCKINGCALLBACK  lpWPUQueryBlockingCallback;
	LPWPUQUERYSOCKETHANDLECONTEXT  lpWPUQuerySocketHandleContext;
	LPWPUQUEUEAPC  lpWPUQueueApc;
	LPWPURESETEVENT  lpWPUResetEvent;
	LPWPUSETEVENT  lpWPUSetEvent;
	LPWPUOPENCURRENTTHREAD  lpWPUOpenCurrentThread;
	LPWPUCLOSETHREAD  lpWPUCloseThread;
	LPWPUCOMPLETEOVERLAPPEDREQUEST lpWPUCompleteOverlappedRequest;
} WSPUPCALLTABLEEX, FAR * LPWSPUPCALLTABLEEX;
#endif

int WSPAPI
WSPStartupEx(
  IN WORD  wVersionRequested,
  OUT LPWSPDATA  lpWSPData,
  IN LPWSAPROTOCOL_INFOW  lpProtocolInfo,
  IN LPWSPUPCALLTABLEEX  lpUpcallTable,
  OUT LPWSPPROC_TABLE  lpProcTable);

typedef int WSPAPI
(*LPWSPSTARTUPEX)(
  IN WORD  wVersionRequested,
  OUT LPWSPDATA  lpWSPData,
  IN LPWSAPROTOCOL_INFOW  lpProtocolInfo,
  IN LPWSPUPCALLTABLEEX  lpUpcallTable,
  OUT LPWSPPROC_TABLE  lpProcTable);

#define MEM_READ                          1
#define MEM_WRITE                         2
#define MEM_READWRITE                     3

int WSPAPI
WSPDeregisterMemory(
  IN SOCKET  s,
  IN HANDLE  Handle,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPDEREGISTERMEMORY)(
  IN SOCKET  s,
  IN HANDLE  Handle,
  OUT LPINT  lpErrno);

int WSPAPI
WSPDeregisterRdmaMemory(
  IN SOCKET  s,
  IN LPVOID  lpRdmaBufferDescriptor,
  IN DWORD  dwDescriptorLength,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPDEREGISTERRDMAMEMORY)(
  IN SOCKET  s,
  IN LPVOID  lpRdmaBufferDescriptor,
  IN DWORD  dwDescriptorLength,
  OUT LPINT  lpErrno);

int WSPAPI
WSPMemoryRegistrationCacheCallback(
  IN PVOID  lpvAddress,
  IN SIZE_T  Size,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPMEMORYREGISTRATIONCACHECALLBACK)(
  IN PVOID  lpvAddress,
  IN SIZE_T  Size,
  OUT LPINT  lpErrno);

int WSPAPI
WSPRdmaRead(
  IN SOCKET  s,
  IN LPWSABUFEX  lpBuffers,
  IN DWORD  dwBufferCount,
  IN LPVOID  lpTargetBufferDescriptor,
  IN DWORD  dwTargetDescriptorLength,
  IN DWORD  dwTargetBufferOffset,
  OUT LPDWORD  lpdwNumberOfBytesRead,
  IN DWORD  dwFlags,
  IN LPWSAOVERLAPPED  lpOverlapped,
  IN LPWSAOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine,
  IN LPWSATHREADID  lpThreadId,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPRDMAREAD)(
  IN SOCKET  s,
  IN LPWSABUFEX  lpBuffers,
  IN DWORD  dwBufferCount,
  IN LPVOID  lpTargetBufferDescriptor,
  IN DWORD  dwTargetDescriptorLength,
  IN DWORD  dwTargetBufferOffset,
  OUT LPDWORD  lpdwNumberOfBytesRead,
  IN DWORD  dwFlags,
  IN LPWSAOVERLAPPED  lpOverlapped,
  IN LPWSAOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine,
  IN LPWSATHREADID  lpThreadId,
  OUT LPINT  lpErrno);

int WSPAPI
WSPRdmaWrite(
  IN SOCKET  s,
  IN LPWSABUFEX  lpBuffers,
  IN DWORD  dwBufferCount,
  IN LPVOID  lpTargetBufferDescriptor,
  IN DWORD  dwTargetDescriptorLength,
  IN DWORD  dwTargetBufferOffset,
  OUT LPDWORD  lpdwNumberOfBytesWritten,
  IN DWORD  dwFlags,
  IN LPWSAOVERLAPPED  lpOverlapped,
  IN LPWSAOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine,
  IN LPWSATHREADID  lpThreadId,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPRDMAWRITE)(
  IN SOCKET  s,
  IN LPWSABUFEX  lpBuffers,
  IN DWORD  dwBufferCount,
  IN LPVOID  lpTargetBufferDescriptor,
  IN DWORD  dwTargetDescriptorLength,
  IN DWORD  dwTargetBufferOffset,
  OUT LPDWORD  lpdwNumberOfBytesWritten,
  IN DWORD  dwFlags,
  IN LPWSAOVERLAPPED  lpOverlapped,
  IN LPWSAOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine,
  IN LPWSATHREADID  lpThreadId,
  OUT LPINT  lpErrno);

HANDLE WSPAPI
WSPRegisterMemory(
  IN SOCKET  s,
  IN PVOID  lpBuffer,
  IN DWORD  dwBufferLength,
  IN DWORD  dwFlags,
  OUT LPINT  lpErrno);

int WSPAPI
WSPRegisterRdmaMemory(
  IN SOCKET  s,
  IN PVOID  lpBuffer,
  IN DWORD  dwBufferLength,
  IN DWORD  dwFlags,
  OUT LPVOID  lpRdmaBufferDescriptor,
  IN OUT LPDWORD  lpdwDescriptorLength,
  OUT LPINT  lpErrno);

typedef int WSPAPI
(*LPFN_WSPREGISTERRDMAMEMORY)(
  IN SOCKET  s,
  IN PVOID  lpBuffer,
  IN DWORD  dwBufferLength,
  IN DWORD  dwFlags,
  OUT LPVOID  lpRdmaBufferDescriptor,
  IN OUT LPDWORD  lpdwDescriptorLength,
  OUT LPINT  lpErrno);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __WS2SAN_H */
