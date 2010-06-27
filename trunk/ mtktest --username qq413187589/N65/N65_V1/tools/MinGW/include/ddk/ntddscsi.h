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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ntddscsi.h,v 1.1 2007/05/17 07:25:39 bw Exp $
*
* $Id: ntddscsi.h,v 1.1 2007/05/17 07:25:39 bw Exp $
*
* $Date: 2007/05/17 07:25:39 $
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
* $Log: ntddscsi.h,v $
* Revision 1.1  2007/05/17 07:25:39  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ntddscsi.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Id: ntddscsi.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Date: 2007/05/14 09:47:04 $
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
* ~Log: ntddscsi.h,v $
* Revision 1.1  2007/05/14 09:47:04  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ntddscsi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: ntddscsi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: ntddscsi.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ntddscsi.h
 *
 * SCSI port IOCTL interface.
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

#ifndef __NTDDSCSI_H
#define __NTDDSCSI_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"


#define DD_SCSI_DEVICE_NAME               "\\Device\\ScsiPort"
#define DD_SCSI_DEVICE_NAME_U             L"\\Device\\ScsiPort"

#define IOCTL_SCSI_BASE                   FILE_DEVICE_CONTROLLER

#define IOCTL_SCSI_GET_INQUIRY_DATA \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0403, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_SCSI_GET_CAPABILITIES \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0404, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_SCSI_GET_ADDRESS \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0406, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_SCSI_MINIPORT \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0402, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_SCSI_PASS_THROUGH \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_SCSI_PASS_THROUGH_DIRECT \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_SCSI_RESCAN_BUS \
  CTL_CODE(IOCTL_SCSI_BASE, 0x0407, METHOD_BUFFERED, FILE_ANY_ACCESS)


DEFINE_GUID(ScsiRawInterfaceGuid, \
  0x53f56309L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

DEFINE_GUID(WmiScsiAddressGuid, \
  0x53f5630fL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

typedef struct _SCSI_PASS_THROUGH {
  USHORT  Length;
  UCHAR  ScsiStatus;
  UCHAR  PathId;
  UCHAR  TargetId;
  UCHAR  Lun;
  UCHAR  CdbLength;
  UCHAR  SenseInfoLength;
  UCHAR  DataIn;
  ULONG  DataTransferLength;
  ULONG  TimeOutValue;
  ULONG_PTR DataBufferOffset;
  ULONG  SenseInfoOffset;
  UCHAR  Cdb[16];
} SCSI_PASS_THROUGH, *PSCSI_PASS_THROUGH;

typedef struct _SCSI_PASS_THROUGH_DIRECT {
  USHORT  Length;
  UCHAR  ScsiStatus;
  UCHAR  PathId;
  UCHAR  TargetId;
  UCHAR  Lun;
  UCHAR  CdbLength;
  UCHAR  SenseInfoLength;
  UCHAR  DataIn;
  ULONG  DataTransferLength;
  ULONG  TimeOutValue;
  PVOID  DataBuffer;
  ULONG  SenseInfoOffset;
  UCHAR  Cdb[16];
} SCSI_PASS_THROUGH_DIRECT, *PSCSI_PASS_THROUGH_DIRECT;

typedef struct _SRB_IO_CONTROL { 
  ULONG  HeaderLength; 
  UCHAR  Signature[8]; 
  ULONG  Timeout; 
  ULONG  ControlCode; 
  ULONG  ReturnCode; 
  ULONG  Length; 
} SRB_IO_CONTROL, *PSRB_IO_CONTROL; 

typedef struct _SCSI_ADDRESS {
	ULONG  Length;
	UCHAR  PortNumber;
	UCHAR  PathId;
	UCHAR  TargetId;
	UCHAR  Lun;
} SCSI_ADDRESS, *PSCSI_ADDRESS;

typedef struct _SCSI_BUS_DATA {
	UCHAR  NumberOfLogicalUnits;
	UCHAR  InitiatorBusId;
	ULONG  InquiryDataOffset;
}SCSI_BUS_DATA, *PSCSI_BUS_DATA;

typedef struct _SCSI_ADAPTER_BUS_INFO {
	UCHAR  NumberOfBuses;
	SCSI_BUS_DATA  BusData[1];
} SCSI_ADAPTER_BUS_INFO, *PSCSI_ADAPTER_BUS_INFO;

typedef struct _IO_SCSI_CAPABILITIES {
	ULONG  Length;
	ULONG  MaximumTransferLength;
	ULONG  MaximumPhysicalPages;
	ULONG  SupportedAsynchronousEvents;
	ULONG  AlignmentMask;
	BOOLEAN  TaggedQueuing;
	BOOLEAN  AdapterScansDown;
	BOOLEAN  AdapterUsesPio;
} IO_SCSI_CAPABILITIES, *PIO_SCSI_CAPABILITIES;

typedef struct _SCSI_INQUIRY_DATA {
	UCHAR  PathId;
	UCHAR  TargetId;
	UCHAR  Lun;
	BOOLEAN  DeviceClaimed;
	ULONG  InquiryDataLength;
	ULONG  NextInquiryDataOffset;
	UCHAR  InquiryData[1];
} SCSI_INQUIRY_DATA, *PSCSI_INQUIRY_DATA;

#define SCSI_IOCTL_DATA_OUT               0
#define SCSI_IOCTL_DATA_IN                1
#define SCSI_IOCTL_DATA_UNSPECIFIED       2

typedef struct _DUMP_POINTERS {
	PADAPTER_OBJECT  AdapterObject;
	PVOID  MappedRegisterBase;
	PVOID  DumpData;
	PVOID  CommonBufferVa;
	LARGE_INTEGER  CommonBufferPa;
	ULONG  CommonBufferSize;
	BOOLEAN  AllocateCommonBuffers;
	BOOLEAN  UseDiskDump;
	UCHAR  Spare1[2];
	PVOID  DeviceObject;
} DUMP_POINTERS, *PDUMP_POINTERS;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NTDDSCSI_H */
