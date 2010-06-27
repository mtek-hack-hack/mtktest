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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/scsiwmi.h,v 1.1 2007/05/17 07:25:41 bw Exp $
*
* $Id: scsiwmi.h,v 1.1 2007/05/17 07:25:41 bw Exp $
*
* $Date: 2007/05/17 07:25:41 $
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
* $Log: scsiwmi.h,v $
* Revision 1.1  2007/05/17 07:25:41  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/scsiwmi.h,v 1.1 2007/05/14 09:47:05 bw Exp $
*
* ~Id: scsiwmi.h,v 1.1 2007/05/14 09:47:05 bw Exp $
*
* ~Date: 2007/05/14 09:47:05 $
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
* ~Log: scsiwmi.h,v $
* Revision 1.1  2007/05/14 09:47:05  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/scsiwmi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: scsiwmi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Date: 2007/04/04 06:51:39 $
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
* ~Log: scsiwmi.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * scsiwmi.h
 *
 * SCSI WMILIB interface.
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

#ifndef __SCSIWMI_H
#define __SCSIWMI_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"
#include "srb.h"


typedef struct _SCSIWMI_REQUEST_CONTEXT {
  PVOID  UserContext;
  ULONG  BufferSize;
  PUCHAR  Buffer;
  UCHAR  MinorFunction;
  UCHAR  ReturnStatus;
  ULONG  ReturnSize;
} SCSIWMI_REQUEST_CONTEXT, *PSCSIWMI_REQUEST_CONTEXT;

#ifdef _GUID_DEFINED
# warning _GUID_DEFINED is deprecated, use GUID_DEFINED instead
#endif

#if ! (defined _GUID_DEFINED || defined GUID_DEFINED)
#define GUID_DEFINED
typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[ 8 ];
} GUID;
#endif

#ifndef _LPCGUID_DEFINED
#define _LPCGUID_DEFINED
typedef const GUID *LPCGUID;
#endif

typedef struct _SCSIWMIGUIDREGINFO {
  LPCGUID  Guid;
  ULONG  InstanceCount;
  ULONG  Flags;
} SCSIWMIGUIDREGINFO, *PSCSIWMIGUIDREGINFO;

typedef UCHAR DDKAPI
(*PSCSIWMI_QUERY_REGINFO)(
	IN PVOID  DeviceContext,
	IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
	OUT PWCHAR  *MofResourceName);

typedef BOOLEAN DDKAPI
(*PSCSIWMI_QUERY_DATABLOCK)(
  IN PVOID  Context,
  IN PSCSIWMI_REQUEST_CONTEXT  DispatchContext,
  IN ULONG  GuidIndex,
  IN ULONG  InstanceIndex,
  IN ULONG  InstanceCount,
  IN OUT PULONG  InstanceLengthArray,
  IN ULONG  BufferAvail,
  OUT PUCHAR  Buffer);

typedef BOOLEAN DDKAPI
(*PSCSIWMI_SET_DATABLOCK)(
  IN PVOID  DeviceContext,
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN ULONG  GuidIndex,
  IN ULONG  InstanceIndex,
  IN ULONG  BufferSize,
  IN PUCHAR  Buffer);

typedef BOOLEAN DDKAPI
(*PSCSIWMI_SET_DATAITEM)(
  IN PVOID  DeviceContext,
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN ULONG  GuidIndex,
  IN ULONG  InstanceIndex,
  IN ULONG  DataItemId,
  IN ULONG  BufferSize,
  IN PUCHAR  Buffer);

typedef BOOLEAN DDKAPI
(*PSCSIWMI_EXECUTE_METHOD)(
  IN PVOID  DeviceContext,
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN ULONG  GuidIndex,
  IN ULONG  InstanceIndex,
  IN ULONG  MethodId,
  IN ULONG  InBufferSize,
  IN ULONG  OutBufferSize,
  IN OUT PUCHAR  Buffer);

typedef enum _SCSIWMI_ENABLE_DISABLE_CONTROL {
	ScsiWmiEventControl,
	ScsiWmiDataBlockControl
} SCSIWMI_ENABLE_DISABLE_CONTROL;

typedef BOOLEAN DDKAPI
(*PSCSIWMI_FUNCTION_CONTROL)(
  IN PVOID  DeviceContext,
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN ULONG  GuidIndex,
  IN SCSIWMI_ENABLE_DISABLE_CONTROL  Function,
  IN BOOLEAN  Enable);

typedef struct _SCSIWMILIB_CONTEXT {
  ULONG  GuidCount;
  PSCSIWMIGUIDREGINFO  GuidList;
  PSCSIWMI_QUERY_REGINFO  QueryWmiRegInfo;
  PSCSIWMI_QUERY_DATABLOCK  QueryWmiDataBlock;
  PSCSIWMI_SET_DATABLOCK  SetWmiDataBlock;
  PSCSIWMI_SET_DATAITEM  SetWmiDataItem;
  PSCSIWMI_EXECUTE_METHOD  ExecuteWmiMethod;
  PSCSIWMI_FUNCTION_CONTROL  WmiFunctionControl;
} SCSI_WMILIB_CONTEXT, *PSCSI_WMILIB_CONTEXT;

SCSIPORTAPI
BOOLEAN
DDKAPI
ScsiPortWmiDispatchFunction(
  IN PSCSI_WMILIB_CONTEXT  WmiLibInfo,
  IN UCHAR  MinorFunction,
  IN PVOID  DeviceContext,
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN PVOID  DataPath,
  IN ULONG  BufferSize,
  IN PVOID  Buffer);

#define ScsiPortWmiFireAdapterEvent(  \
  HwDeviceExtension,                  \
  Guid,                               \
  InstanceIndex,                      \
  EventDataSize,                      \
  EventData)                          \
    ScsiPortWmiFireLogicalUnitEvent(  \
	  HwDeviceExtension,                \
	  0xff,                             \
	  0,                                \
	  0,                                \
	  Guid,                             \
	  InstanceIndex,                    \
	  EventDataSize,                    \
	  EventData)

/*
 * ULONG
 * ScsiPortWmiGetReturnSize(
 *   PSCSIWMI_REQUEST_CONTEXT  RequestContext);
 */
#define ScsiPortWmiGetReturnSize(RequestContext) \
  ((RequestContext)->ReturnSize)

/* UCHAR 
 * ScsiPortWmiGetReturnStatus(
 *   PSCSIWMI_REQUEST_CONTEXT  RequestContext);
 */ 
#define ScsiPortWmiGetReturnStatus(RequestContext) \
  ((RequestContext)->ReturnStatus)

SCSIPORTAPI
VOID
DDKAPI
ScsiPortWmiPostProcess(
  IN PSCSIWMI_REQUEST_CONTEXT  RequestContext,
  IN UCHAR  SrbStatus,
  IN ULONG  BufferUsed);

SCSIPORTAPI
VOID
DDKAPI
ScsiPortWmiFireLogicalUnitEvent(
  IN PVOID  HwDeviceExtension,
  IN UCHAR  PathId,
  IN UCHAR  TargetId,
  IN UCHAR  Lun,
  IN LPGUID  Guid,
  IN ULONG  InstanceIndex,
  IN ULONG  EventDataSize,
  IN PVOID  EventData);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __SCSIWMI_H */
