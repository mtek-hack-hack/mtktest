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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/pfhook.h,v 1.1 2007/05/17 07:25:40 bw Exp $
*
* $Id: pfhook.h,v 1.1 2007/05/17 07:25:40 bw Exp $
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
* $Log: pfhook.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/pfhook.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Id: pfhook.h,v 1.1 2007/05/14 09:47:04 bw Exp $
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
* ~Log: pfhook.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/pfhook.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: pfhook.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: pfhook.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * pfhook.h
 *
 * Packet filter API
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

#ifndef __PFHOOK_H
#define __PFHOOK_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"


#define DD_IPFLTRDRVR_DEVICE_NAME         L"\\Device\\IPFILTERDRIVER"

#define INVALID_PF_IF_INDEX               0xffffffff
#define ZERO_PF_IP_ADDR                   0

typedef ULONG IPAddr;

typedef enum _PF_FORWARD_ACTION {
	PF_FORWARD = 0,
	PF_DROP = 1,
	PF_PASS = 2,
	PF_ICMP_ON_DROP = 3
} PF_FORWARD_ACTION;

typedef PF_FORWARD_ACTION STDCALL
(*PacketFilterExtensionPtr)(
  IN unsigned char  *PacketHeader,
  IN unsigned char  *Packet, 
  IN unsigned int  PacketLength, 
  IN unsigned int  RecvInterfaceIndex, 
  IN unsigned int  SendInterfaceIndex, 
  IN IPAddr  RecvLinkNextHop, 
  IN IPAddr  SendLinkNextHop); 

typedef struct _PF_SET_EXTENSION_HOOK_INFO {
  PacketFilterExtensionPtr  ExtensionPointer; 
} PF_SET_EXTENSION_HOOK_INFO, *PPF_SET_EXTENSION_HOOK_INFO;

#define FSCTL_IPFLTRDRVR_BASE             FILE_DEVICE_NETWORK

#define _IPFLTRDRVR_CTL_CODE(function, method, access) \
  CTL_CODE(FSCTL_IPFLTRDRVR_BASE, function, method, access)

#define IOCTL_PF_SET_EXTENSION_POINTER \
  _IPFLTRDRVR_CTL_CODE(22, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __PFHOOK_H */
