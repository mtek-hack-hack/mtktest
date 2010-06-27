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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ntddvol.h,v 1.1 2007/05/17 07:25:40 bw Exp $
*
* $Id: ntddvol.h,v 1.1 2007/05/17 07:25:40 bw Exp $
*
* $Date: 2007/05/17 07:25:40 $
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
* $Log: ntddvol.h,v $
* Revision 1.1  2007/05/17 07:25:40  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ntddvol.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Id: ntddvol.h,v 1.1 2007/05/14 09:47:04 bw Exp $
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
* ~Log: ntddvol.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ntddvol.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: ntddvol.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: ntddvol.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ntddvol.h
 *
 * Volume IOCTL interface.
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

#ifndef __NTDDVOL_H
#define __NTDDVOL_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"


#define IOCTL_VOLUME_BASE                 ((ULONG) 'V')

#define IOCTL_VOLUME_LOGICAL_TO_PHYSICAL \
  CTL_CODE(IOCTL_VOLUME_BASE, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_PHYSICAL_TO_LOGICAL \
  CTL_CODE(IOCTL_VOLUME_BASE, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_READ_PLEX \
  CTL_CODE(IOCTL_VOLUME_BASE, 11, METHOD_OUT_DIRECT, FILE_READ_ACCESS)

#define IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS \
  CTL_CODE(IOCTL_VOLUME_BASE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_IS_CLUSTERED \
  CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_QUERY_VOLUME_NUMBER \
  CTL_CODE(IOCTL_VOLUME_BASE, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_IS_PARTITION \
  CTL_CODE(IOCTL_VOLUME_BASE, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_SET_GPT_ATTRIBUTES \
  CTL_CODE(IOCTL_VOLUME_BASE, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_GET_GPT_ATTRIBUTES \
  CTL_CODE(IOCTL_VOLUME_BASE, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_SUPPORTS_ONLINE_OFFLINE \
  CTL_CODE(IOCTL_VOLUME_BASE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_ONLINE \
  CTL_CODE(IOCTL_VOLUME_BASE, 2, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_VOLUME_OFFLINE \
  CTL_CODE(IOCTL_VOLUME_BASE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_VOLUME_IS_OFFLINE \
  CTL_CODE(IOCTL_VOLUME_BASE, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_IS_IO_CAPABLE \
  CTL_CODE(IOCTL_VOLUME_BASE, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_VOLUME_QUERY_FAILOVER_SET \
  CTL_CODE(IOCTL_VOLUME_BASE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)


typedef struct _VOLUME_LOGICAL_OFFSET {
  LONGLONG  LogicalOffset;
} VOLUME_LOGICAL_OFFSET, *PVOLUME_LOGICAL_OFFSET;

typedef struct _VOLUME_PHYSICAL_OFFSET {
  ULONG  DiskNumber;
  LONGLONG  Offset;
} VOLUME_PHYSICAL_OFFSET, *PVOLUME_PHYSICAL_OFFSET;

typedef struct _VOLUME_PHYSICAL_OFFSETS {
  ULONG  NumberOfPhysicalOffsets;
  VOLUME_PHYSICAL_OFFSET  PhysicalOffset[1];
} VOLUME_PHYSICAL_OFFSETS, *PVOLUME_PHYSICAL_OFFSETS;

typedef struct _VOLUME_READ_PLEX_INPUT {
  LARGE_INTEGER  ByteOffset;
  ULONG  Length;
  ULONG  PlexNumber;
} VOLUME_READ_PLEX_INPUT, *PVOLUME_READ_PLEX_INPUT;

typedef struct _VOLUME_GET_GPT_ATTRIBUTES_INFORMATION {
  ULONGLONG  GptAttributes;
} VOLUME_GET_GPT_ATTRIBUTES_INFORMATION, *PVOLUME_GET_GPT_ATTRIBUTES_INFORMATION;

typedef struct _VOLUME_SET_GPT_ATTRIBUTES_INFORMATION {
	ULONGLONG  GptAttributes;
	BOOLEAN  RevertOnClose;
	BOOLEAN  ApplyToAllConnectedVolumes;
	USHORT  Reserved1;
	ULONG  Reserved2;
} VOLUME_SET_GPT_ATTRIBUTES_INFORMATION, *PVOLUME_SET_GPT_ATTRIBUTES_INFORMATION;

typedef struct _DISK_EXTENT {
	ULONG  DiskNumber;
	LARGE_INTEGER  StartingOffset;
	LARGE_INTEGER  ExtentLength;
} DISK_EXTENT, *PDISK_EXTENT;

typedef struct _VOLUME_DISK_EXTENTS {
	ULONG  NumberOfDiskExtents;
	DISK_EXTENT  Extents[1];
} VOLUME_DISK_EXTENTS, *PVOLUME_DISK_EXTENTS;

typedef struct _VOLUME_NUMBER {
	ULONG  VolumeNumber;
	WCHAR  VolumeManagerName[8];
} VOLUME_NUMBER, *PVOLUME_NUMBER;

typedef struct _VOLUME_FAILOVER_SET {
	ULONG  NumberOfDisks;
	ULONG  DiskNumbers[1];
} VOLUME_FAILOVER_SET, *PVOLUME_FAILOVER_SET;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NTDDVOL_H */
