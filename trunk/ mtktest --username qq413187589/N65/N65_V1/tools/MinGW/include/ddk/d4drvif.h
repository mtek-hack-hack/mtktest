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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/d4drvif.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Id: d4drvif.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Date: 2007/05/17 07:25:37 $
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
* $Log: d4drvif.h,v $
* Revision 1.1  2007/05/17 07:25:37  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/d4drvif.h,v 1.1 2007/05/14 09:47:01 bw Exp $
*
* ~Id: d4drvif.h,v 1.1 2007/05/14 09:47:01 bw Exp $
*
* ~Date: 2007/05/14 09:47:01 $
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
* ~Log: d4drvif.h,v $
* Revision 1.1  2007/05/14 09:47:01  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/d4drvif.h,v 1.2 2007/04/04 06:51:38 bw Exp $
*
* ~Id: d4drvif.h,v 1.2 2007/04/04 06:51:38 bw Exp $
*
* ~Date: 2007/04/04 06:51:38 $
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
* ~Log: d4drvif.h,v $
* Revision 1.2  2007/04/04 06:51:38  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * d4drvif.h
 *
 * DOT4 driver IOCTL interface
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

#ifndef __D4DRVIF_H
#define __D4DRVIF_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"
#include "d4iface.h"

#define FILE_DEVICE_DOT4                  0x3a
#define IOCTL_DOT4_USER_BASE              2049

#define IOCTL_DOT4_ADD_ACTIVITY_BROADCAST \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 4, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DOT4_CLOSE_CHANNEL \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 1, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DOT4_CREATE_SOCKET \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 7, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_DESTROY_SOCKET \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 9, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_OPEN_CHANNEL \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 0, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_READ \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 2, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_REMOVE_ACTIVITY_BROADCAST \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 5, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DOT4_WAIT_ACTIVITY_BROADCAST \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 6, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_WAIT_FOR_CHANNEL \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 8, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_DOT4_WRITE \
  CTL_CODE(FILE_DEVICE_DOT4, IOCTL_DOT4_USER_BASE + 3, METHOD_IN_DIRECT, FILE_ANY_ACCESS)


#define MAX_SERVICE_LENGTH                40

typedef struct _DOT4_DC_CREATE_DATA {
  unsigned char  bPsid;
  CHAR  pServiceName[MAX_SERVICE_LENGTH + 1];
  unsigned char  bType;
  ULONG  ulBufferSize;
  USHORT  usMaxHtoPPacketSize;
  USHORT  usMaxPtoHPacketSize;
  unsigned char bHsid;
} DOT4_DC_CREATE_DATA, *PDOT4_DC_CREATE_DATA;

typedef struct _DOT4_DC_DESTROY_DATA {
    unsigned char  bHsid;
} DOT4_DC_DESTROY_DATA, *PDOT4_DC_DESTROY_DATA;

typedef struct _DOT4_DC_OPEN_DATA {
  unsigned char  bHsid;
  unsigned char  fAddActivity;
  CHANNEL_HANDLE  hChannelHandle;
} DOT4_DC_OPEN_DATA, *PDOT4_DC_OPEN_DATA;

typedef struct _DOT4_DRIVER_CMD {
  CHANNEL_HANDLE  hChannelHandle;
  ULONG  ulSize;
  ULONG  ulOffset;
  ULONG  ulTimeout;
} DOT4_DRIVER_CMD, *PDOT4_DRIVER_CMD;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __D4DRVIF_H */
