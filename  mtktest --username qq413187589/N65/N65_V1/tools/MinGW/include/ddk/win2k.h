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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/win2k.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Id: win2k.h,v 1.1 2007/05/17 07:25:42 bw Exp $
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
* $Log: win2k.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/win2k.h,v 1.1 2007/05/14 09:47:05 bw Exp $
*
* ~Id: win2k.h,v 1.1 2007/05/14 09:47:05 bw Exp $
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
* ~Log: win2k.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/win2k.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Id: win2k.h,v 1.2 2007/04/04 06:51:40 bw Exp $
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
* ~Log: win2k.h,v $
* Revision 1.2  2007/04/04 06:51:40  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * win2k.h
 *
 * Definitions only used in Windows 2000 and earlier versions
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

#ifndef __WIN2K_H
#define __WIN2K_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "ntddk.h"

#pragma pack(push,4)

typedef enum _BUS_DATA_TYPE {
  ConfigurationSpaceUndefined = -1,
  Cmos,
  EisaConfiguration,
  Pos,
  CbusConfiguration,
  PCIConfiguration,
  VMEConfiguration,
  NuBusConfiguration,
  PCMCIAConfiguration,
  MPIConfiguration,
  MPSAConfiguration,
  PNPISAConfiguration,
  SgiInternalConfiguration,
  MaximumBusDataType
} BUS_DATA_TYPE, *PBUS_DATA_TYPE;

NTOSAPI
VOID
DDKAPI
ExReleaseResourceForThreadLite(
  IN PERESOURCE  Resource,
  IN ERESOURCE_THREAD  ResourceThreadId);

NTOSAPI
NTSTATUS
DDKAPI
IoReadPartitionTable(
  IN PDEVICE_OBJECT  DeviceObject,
  IN ULONG  SectorSize,
  IN BOOLEAN  ReturnRecognizedPartitions,
  OUT struct _DRIVE_LAYOUT_INFORMATION  **PartitionBuffer);

NTOSAPI
NTSTATUS
DDKAPI
IoSetPartitionInformation(
  IN PDEVICE_OBJECT  DeviceObject,
  IN ULONG  SectorSize,
  IN ULONG  PartitionNumber,
  IN ULONG  PartitionType);

NTOSAPI
NTSTATUS
DDKAPI
IoWritePartitionTable(
  IN PDEVICE_OBJECT  DeviceObject,
  IN ULONG  SectorSize,
  IN ULONG  SectorsPerTrack,
  IN ULONG  NumberOfHeads,
  IN struct _DRIVE_LAYOUT_INFORMATION  *PartitionBuffer);

/*
 * PVOID MmGetSystemAddressForMdl(
 *   IN PMDL  Mdl); 
 */
#define MmGetSystemAddressForMdl(Mdl) \
  (((Mdl)->MdlFlags & (MDL_MAPPED_TO_SYSTEM_VA | \
    MDL_SOURCE_IS_NONPAGED_POOL)) ? \
      ((Mdl)->MappedSystemVa) : \
      (MmMapLockedPages((Mdl), KernelMode)))

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __WIN2K_H */
