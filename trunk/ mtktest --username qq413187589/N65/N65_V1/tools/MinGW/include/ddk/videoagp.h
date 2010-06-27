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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/videoagp.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Id: videoagp.h,v 1.1 2007/05/17 07:25:42 bw Exp $
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
* $Log: videoagp.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/videoagp.h,v 1.1 2007/05/14 09:47:05 bw Exp $
*
* ~Id: videoagp.h,v 1.1 2007/05/14 09:47:05 bw Exp $
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
* ~Log: videoagp.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/videoagp.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Id: videoagp.h,v 1.2 2007/04/04 06:51:40 bw Exp $
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
* ~Log: videoagp.h,v $
* Revision 1.2  2007/04/04 06:51:40  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * videoagp.h
 *
 * Video miniport AGP interface
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

#ifndef __VIDEOAGP_H
#define __VIDEOAGP_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"
#include "video.h"


#define VIDEO_AGP_RATE_1X                 0x00000001
#define VIDEO_AGP_RATE_2X                 0x00000002
#define VIDEO_AGP_RATE_4X                 0x00000004
#define VIDEO_AGP_RATE_8X                 0x00000008

typedef enum _VIDEO_PORT_CACHE_TYPE {
	VpNonCached = 0,
	VpWriteCombined,
	VpCached
} VIDEO_PORT_CACHE_TYPE;

typedef BOOLEAN DDKAPI
(*PAGP_COMMIT_PHYSICAL)(
  IN  PVOID  HwDeviceExtension,
  IN  PVOID  PhysicalReserveContext,
  IN  ULONG  Pages,
  IN  ULONG  Offset);

typedef PVOID DDKAPI
(*PAGP_COMMIT_VIRTUAL)(
	IN  PVOID  HwDeviceExtension,
	IN  PVOID  VirtualReserveContext,
	IN  ULONG  Pages,
	IN  ULONG  Offset);

typedef VOID DDKAPI
(*PAGP_FREE_PHYSICAL)(
	IN  PVOID  HwDeviceExtension,
	IN  PVOID  PhysicalReserveContext,
	IN  ULONG  Pages,
	IN  ULONG  Offset);

typedef VOID DDKAPI
(*PAGP_FREE_VIRTUAL)(
  IN  PVOID  HwDeviceExtension,
  IN  PVOID  VirtualReserveContext,
  IN  ULONG  Pages,
  IN  ULONG  Offset);

typedef VOID DDKAPI
(*PAGP_RELEASE_PHYSICAL)(
  IN  PVOID  HwDeviceExtension,
  IN  PVOID  PhysicalReserveContext);

typedef VOID DDKAPI
(*PAGP_RELEASE_VIRTUAL)(
	IN  PVOID  HwDeviceExtension,
	IN  PVOID  VirtualReserveContext);

typedef PHYSICAL_ADDRESS DDKAPI
(*PAGP_RESERVE_PHYSICAL)(
  IN  PVOID  HwDeviceExtension,
  IN  ULONG  Pages,
  IN  VIDEO_PORT_CACHE_TYPE  Caching,
  OUT PVOID  *PhysicalReserveContext);

typedef PVOID DDKAPI
(*PAGP_RESERVE_VIRTUAL)(
  IN  PVOID  HwDeviceExtension,
  IN  HANDLE  ProcessHandle,
  IN  PVOID  PhysicalReserveContext,
  OUT PVOID  *VirtualReserveContext);

typedef BOOLEAN DDKAPI
(*PAGP_SET_RATE)(
	IN  PVOID  HwDeviceExtension,
	IN  ULONG  AgpRate);

typedef struct _VIDEO_PORT_AGP_SERVICES {
  PAGP_RESERVE_PHYSICAL  AgpReservePhysical;
  PAGP_RELEASE_PHYSICAL  AgpReleasePhysical;
  PAGP_COMMIT_PHYSICAL  AgpCommitPhysical;
  PAGP_FREE_PHYSICAL  AgpFreePhysical;
  PAGP_RESERVE_VIRTUAL  AgpReserveVirtual;
  PAGP_RELEASE_VIRTUAL  AgpReleaseVirtual;
  PAGP_COMMIT_VIRTUAL  AgpCommitVirtual;
  PAGP_FREE_VIRTUAL  AgpFreeVirtual;
  ULONGLONG  AllocationLimit;
} VIDEO_PORT_AGP_SERVICES, *PVIDEO_PORT_AGP_SERVICES;

VPAPI
BOOLEAN
DDKAPI
VideoPortGetAgpServices(
	IN  PVOID  HwDeviceExtension,
	IN  PVIDEO_PORT_AGP_SERVICES  AgpServices);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __VIDEOAGP_H */
