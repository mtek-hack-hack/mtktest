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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ntddkbd.h,v 1.1 2007/05/17 07:25:39 bw Exp $
*
* $Id: ntddkbd.h,v 1.1 2007/05/17 07:25:39 bw Exp $
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
* $Log: ntddkbd.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ntddkbd.h,v 1.1 2007/05/14 09:47:03 bw Exp $
*
* ~Id: ntddkbd.h,v 1.1 2007/05/14 09:47:03 bw Exp $
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
* ~Log: ntddkbd.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ntddkbd.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: ntddkbd.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: ntddkbd.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ntddkbd.h
 *
 * Keyboard IOCTL interface
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

#ifndef __NTDDKBD_H
#define __NTDDKBD_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"


#define DD_KEYBOARD_DEVICE_NAME           "\\Device\\KeyboardClass"
#define DD_KEYBOARD_DEVICE_NAME_U         L"\\Device\\KeyboardClass"

#define IOCTL_KEYBOARD_QUERY_ATTRIBUTES \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_INDICATORS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0010, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0020, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_QUERY_TYPEMATIC \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_SET_TYPEMATIC \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0001, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_KEYBOARD_SET_INDICATORS \
  CTL_CODE(FILE_DEVICE_KEYBOARD, 0x0002, METHOD_BUFFERED, FILE_ANY_ACCESS)


DEFINE_GUID(GUID_DEVINTERFACE_KEYBOARD, \
  0x884b96c3, 0x56ef, 0x11d1, 0xbc, 0x8c, 0x00, 0xa0, 0xc9, 0x14, 0x05, 0xdd);

#define KEYBOARD_ERROR_VALUE_BASE         10000

/* KEYBOARD_INPUT_DATA.MakeCode constants */
#define KEYBOARD_OVERRUN_MAKE_CODE        0xFF

/* KEYBOARD_INPUT_DATA.Flags constants */
#define KEY_MAKE                          0
#define KEY_BREAK                         1
#define KEY_E0                            2
#define KEY_E1                            4

typedef struct _KEYBOARD_INPUT_DATA {
  USHORT  UnitId;
  USHORT  MakeCode;
  USHORT  Flags;
  USHORT  Reserved;
  ULONG  ExtraInformation;
} KEYBOARD_INPUT_DATA, *PKEYBOARD_INPUT_DATA;


typedef struct _KEYBOARD_TYPEMATIC_PARAMETERS {
	USHORT  UnitId;
	USHORT  Rate;
	USHORT  Delay;
} KEYBOARD_TYPEMATIC_PARAMETERS, *PKEYBOARD_TYPEMATIC_PARAMETERS;

typedef struct _KEYBOARD_ID {
	UCHAR  Type;
	UCHAR  Subtype;
} KEYBOARD_ID, *PKEYBOARD_ID;

#define ENHANCED_KEYBOARD(Id) ((Id).Type == 2 || (Id).Type == 4 || FAREAST_KEYBOARD(Id))
#define FAREAST_KEYBOARD(Id)  ((Id).Type == 7 || (Id).Type == 8)

typedef struct _KEYBOARD_INDICATOR_PARAMETERS {
  USHORT  UnitId;
  USHORT  LedFlags;
} KEYBOARD_INDICATOR_PARAMETERS, *PKEYBOARD_INDICATOR_PARAMETERS;

typedef struct _INDICATOR_LIST {
  USHORT  MakeCode;
  USHORT  IndicatorFlags;
} INDICATOR_LIST, *PINDICATOR_LIST;

typedef struct _KEYBOARD_INDICATOR_TRANSLATION {
  USHORT  NumberOfIndicatorKeys;
  INDICATOR_LIST  IndicatorList[1];
} KEYBOARD_INDICATOR_TRANSLATION, *PKEYBOARD_INDICATOR_TRANSLATION;

typedef struct _KEYBOARD_ATTRIBUTES {
	KEYBOARD_ID  KeyboardIdentifier;
	USHORT  KeyboardMode;
	USHORT  NumberOfFunctionKeys;
	USHORT  NumberOfIndicators;
	USHORT  NumberOfKeysTotal;
	ULONG  InputDataQueueLength;
	KEYBOARD_TYPEMATIC_PARAMETERS  KeyRepeatMinimum;
	KEYBOARD_TYPEMATIC_PARAMETERS  KeyRepeatMaximum;
} KEYBOARD_ATTRIBUTES, *PKEYBOARD_ATTRIBUTES;

typedef struct _KEYBOARD_UNIT_ID_PARAMETER {
  USHORT  UnitId;
} KEYBOARD_UNIT_ID_PARAMETER, *PKEYBOARD_UNIT_ID_PARAMETER;

typedef struct _KEYBOARD_IME_STATUS {
	USHORT  UnitId;
	ULONG  ImeOpen;
	ULONG  ImeConvMode;
} KEYBOARD_IME_STATUS, *PKEYBOARD_IME_STATUS;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NTDDKBD_H */
