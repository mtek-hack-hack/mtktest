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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/smbus.h,v 1.1 2007/05/17 07:25:41 bw Exp $
*
* $Id: smbus.h,v 1.1 2007/05/17 07:25:41 bw Exp $
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
* $Log: smbus.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/smbus.h,v 1.1 2007/05/14 09:47:05 bw Exp $
*
* ~Id: smbus.h,v 1.1 2007/05/14 09:47:05 bw Exp $
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
* ~Log: smbus.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/smbus.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: smbus.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: smbus.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * smbus.h
 *
 * System Management Bus driver interface
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

#ifndef __SMBUS_H
#define __SMBUS_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#if !defined(SMBCLASS)
  #define SMBCLASSAPI DECLSPEC_IMPORT
#else
  #define SMBCLASSAPI DECLSPEC_EXPORT
#endif

#define SMB_BUS_REQUEST \
  CTL_CODE(FILE_DEVICE_UNKNOWN, 0, METHOD_NEITHER, FILE_ANY_ACCESS)

#define SMB_DEREGISTER_ALARM_NOTIFY \
  CTL_CODE(FILE_DEVICE_UNKNOWN, 2, METHOD_NEITHER, FILE_ANY_ACCESS)

#define SMB_REGISTER_ALARM_NOTIFY \
  CTL_CODE(FILE_DEVICE_UNKNOWN, 1, METHOD_NEITHER, FILE_ANY_ACCESS)


struct _SMB_CLASS;

#define SMB_MAX_DATA_SIZE                 32

/* SMB_REQUEST.Status constants */
#define SMB_STATUS_OK                     0x00
#define SMB_UNKNOWN_FAILURE               0x07
#define SMB_ADDRESS_NOT_ACKNOWLEDGED      0x10
#define SMB_DEVICE_ERROR                  0x11
#define SMB_COMMAND_ACCESS_DENIED         0x12
#define SMB_UNKNOWN_ERROR                 0x13
#define SMB_DEVICE_ACCESS_DENIED          0x17
#define SMB_TIMEOUT                       0x18
#define SMB_UNSUPPORTED_PROTOCOL          0x19
#define SMB_BUS_BUSY                      0x1A

/* SMB_REQUEST.Protocol constants */
#define SMB_WRITE_QUICK                   0x00
#define SMB_READ_QUICK                    0x01
#define SMB_SEND_BYTE                     0x02
#define SMB_RECEIVE_BYTE                  0x03
#define SMB_WRITE_BYTE                    0x04
#define SMB_READ_BYTE                     0x05
#define SMB_WRITE_WORD                    0x06
#define SMB_READ_WORD                     0x07
#define SMB_WRITE_BLOCK                   0x08
#define SMB_READ_BLOCK                    0x09
#define SMB_PROCESS_CALL                  0x0A
#define SMB_MAXIMUM_PROTOCOL              0x0A

typedef struct _SMB_REQUEST {
  UCHAR  Status;
  UCHAR  Protocol;
  UCHAR  Address;
  UCHAR  Command;
  UCHAR  BlockLength;
  UCHAR  Data[SMB_MAX_DATA_SIZE];
} SMB_REQUEST, *PSMB_REQUEST;

typedef VOID STDCALL
(*SMB_ALARM_NOTIFY)(
  PVOID  Context,
  UCHAR  Address,
  USHORT  Data);

typedef struct _SMB_REGISTER_ALARM {
  UCHAR  MinAddress;
  UCHAR  MaxAddress;
  SMB_ALARM_NOTIFY  NotifyFunction;
  PVOID  NotifyContext;
} SMB_REGISTER_ALARM, *PSMB_REGISTER_ALARM;

/* SMB_CLASS.XxxVersion constants */
#define SMB_CLASS_MAJOR_VERSION           0x0001
#define SMB_CLASS_MINOR_VERSION           0x0000

typedef NTSTATUS DDKAPI
(*SMB_RESET_DEVICE)(
  IN struct _SMB_CLASS  *SmbClass,
  IN PVOID  SmbMiniport);

typedef VOID DDKAPI
(*SMB_START_IO)(
  IN struct _SMB_CLASS  *SmbClass,
  IN PVOID  SmbMiniport);

typedef NTSTATUS DDKAPI
(*SMB_STOP_DEVICE)(
  IN struct _SMB_CLASS  *SmbClass,
  IN PVOID  SmbMiniport);

typedef struct _SMB_CLASS {
  USHORT  MajorVersion;
  USHORT  MinorVersion;
  PVOID  Miniport;
  PDEVICE_OBJECT  DeviceObject;
  PDEVICE_OBJECT  PDO;
  PDEVICE_OBJECT  LowerDeviceObject;
  PIRP  CurrentIrp;
  PSMB_REQUEST  CurrentSmb;
  SMB_RESET_DEVICE  ResetDevice;
  SMB_START_IO  StartIo;
  SMB_STOP_DEVICE  StopDevice;
} SMB_CLASS, *PSMB_CLASS;

SMBCLASSAPI
VOID
DDKAPI
SmbClassAlarm(
  IN PSMB_CLASS  SmbClass,
  IN UCHAR  Address,
  IN USHORT  Data);

SMBCLASSAPI
VOID
DDKAPI
SmbClassCompleteRequest(
  IN PSMB_CLASS  SmbClass);

typedef NTSTATUS DDKAPI
(*PSMB_INITIALIZE_MINIPORT)(
  IN PSMB_CLASS  SmbClass,
  IN PVOID  MiniportExtension,
  IN PVOID  MiniportContext);

SMBCLASSAPI
NTSTATUS
DDKAPI
SmbClassCreateFdo(
  IN PDRIVER_OBJECT  DriverObject,
  IN PDEVICE_OBJECT  PDO,
  IN ULONG  MiniportExtensionSize,
  IN PSMB_INITIALIZE_MINIPORT  MiniportInitialize,
  IN PVOID  MiniportContext,
  OUT PDEVICE_OBJECT  *FDO);

SMBCLASSAPI
NTSTATUS
DDKAPI
SmbClassInitializeDevice(
  IN ULONG  MajorVersion,
  IN ULONG  MinorVersion,
  IN PDRIVER_OBJECT  DriverObject);

SMBCLASSAPI
VOID
DDKAPI
SmbClassLockDevice(
  IN PSMB_CLASS  SmbClass);

SMBCLASSAPI
VOID
DDKAPI
SmbClassUnlockDevice(
  IN PSMB_CLASS  SmbClass);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __SMBUS_H */
