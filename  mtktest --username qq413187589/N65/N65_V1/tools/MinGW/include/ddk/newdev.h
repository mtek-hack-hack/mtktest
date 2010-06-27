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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/newdev.h,v 1.1 2007/05/17 07:25:38 bw Exp $
*
* $Id: newdev.h,v 1.1 2007/05/17 07:25:38 bw Exp $
*
* $Date: 2007/05/17 07:25:38 $
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
* $Log: newdev.h,v $
* Revision 1.1  2007/05/17 07:25:38  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/newdev.h,v 1.1 2007/05/14 09:47:03 bw Exp $
*
* ~Id: newdev.h,v 1.1 2007/05/14 09:47:03 bw Exp $
*
* ~Date: 2007/05/14 09:47:03 $
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
* ~Log: newdev.h,v $
* Revision 1.1  2007/05/14 09:47:03  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/newdev.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: newdev.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: newdev.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * newdev.h
 *
 * Driver installation DLL interface
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

#ifndef __NEWDEV_H
#define __NEWDEV_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

/* UpdateDriverForPlugAndPlayDevices.InstallFlags constants */
#define INSTALLFLAG_FORCE                 0x00000001
#define INSTALLFLAG_READONLY              0x00000002
#define INSTALLFLAG_NONINTERACTIVE        0x00000004
#define INSTALLFLAG_BITS                  0x00000007

BOOL WINAPI
UpdateDriverForPlugAndPlayDevicesA(
  HWND  hwndParent,
  LPCSTR  HardwareId,
  LPCSTR  FullInfPath,
  DWORD  InstallFlags,
  PBOOL  bRebootRequired  OPTIONAL);

BOOL WINAPI
UpdateDriverForPlugAndPlayDevicesW(
  HWND  hwndParent,
  LPCWSTR  HardwareId,
  LPCWSTR  FullInfPath,
  DWORD  InstallFlags,
  PBOOL  bRebootRequired  OPTIONAL);

#ifdef UNICODE
#define UpdateDriverForPlugAndPlayDevices UpdateDriverForPlugAndPlayDevicesW
#else
#define UpdateDriverForPlugAndPlayDevices UpdateDriverForPlugAndPlayDevicesA
#endif /* UNICODE */

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NEWDEV_H */
