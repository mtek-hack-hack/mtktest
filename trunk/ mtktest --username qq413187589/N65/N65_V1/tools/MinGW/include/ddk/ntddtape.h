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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ntddtape.h,v 1.1 2007/05/17 07:25:39 bw Exp $
*
* $Id: ntddtape.h,v 1.1 2007/05/17 07:25:39 bw Exp $
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
* $Log: ntddtape.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ntddtape.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Id: ntddtape.h,v 1.1 2007/05/14 09:47:04 bw Exp $
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
* ~Log: ntddtape.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ntddtape.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: ntddtape.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: ntddtape.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ntddtape.h
 *
 * Tape device IOCTL interface.
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

#ifndef __NTDDTAPE_H
#define __NTDDTAPE_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"
#include "ntddstor.h"


#define DD_TAPE_DEVICE_NAME               "\\Device\\Tape"
#define DD_TAPE_DEVICE_NAME_U             L"\\Device\\Tape"

#define IOCTL_TAPE_BASE                   FILE_DEVICE_TAPE

#define IOCTL_TAPE_CHECK_VERIFY         CTL_CODE(IOCTL_TAPE_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_CREATE_PARTITION     CTL_CODE(IOCTL_TAPE_BASE, 0x000a, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_TAPE_ERASE                CTL_CODE(IOCTL_TAPE_BASE, 0x0000, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_TAPE_FIND_NEW_DEVICES     CTL_CODE(IOCTL_DISK_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_GET_DRIVE_PARAMS     CTL_CODE(IOCTL_TAPE_BASE, 0x0005, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_GET_MEDIA_PARAMS     CTL_CODE(IOCTL_TAPE_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_GET_POSITION         CTL_CODE(IOCTL_TAPE_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_GET_STATUS           CTL_CODE(IOCTL_TAPE_BASE, 0x0009, METHOD_BUFFERED, FILE_READ_ACCESS )

#define IOCTL_TAPE_PREPARE              CTL_CODE(IOCTL_TAPE_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_SET_DRIVE_PARAMS     CTL_CODE(IOCTL_TAPE_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_TAPE_SET_MEDIA_PARAMS     CTL_CODE(IOCTL_TAPE_BASE, 0x0008, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_SET_POSITION         CTL_CODE(IOCTL_TAPE_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_TAPE_WRITE_MARKS          CTL_CODE(IOCTL_TAPE_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)


typedef enum _TAPE_DRIVE_PROBLEM_TYPE {
  TapeDriveProblemNone, 
  TapeDriveReadWriteWarning,
  TapeDriveReadWriteError, 
  TapeDriveReadWarning,
  TapeDriveWriteWarning,
  TapeDriveReadError,
  TapeDriveWriteError, 
  TapeDriveHardwareError,
  TapeDriveUnsupportedMedia, 
  TapeDriveScsiConnectionError,
  TapeDriveTimetoClean, 
  TapeDriveCleanDriveNow,
  TapeDriveMediaLifeExpired, 
  TapeDriveSnappedTape
} TAPE_DRIVE_PROBLEM_TYPE;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NTDDTAPE_H */
