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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ddk/ntddtdi.h,v 1.1 2007/05/17 07:25:39 bw Exp $
*
* $Id: ntddtdi.h,v 1.1 2007/05/17 07:25:39 bw Exp $
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
* $Log: ntddtdi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ddk/ntddtdi.h,v 1.1 2007/05/14 09:47:04 bw Exp $
*
* ~Id: ntddtdi.h,v 1.1 2007/05/14 09:47:04 bw Exp $
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
* ~Log: ntddtdi.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ddk/ntddtdi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
*
* ~Id: ntddtdi.h,v 1.2 2007/04/04 06:51:39 bw Exp $
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
* ~Log: ntddtdi.h,v $
* Revision 1.2  2007/04/04 06:51:39  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ntddtdi.h
 *
 * TDI IOCTL interface
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

#ifndef __NTDDTDI_H
#define __NTDDTDI_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"


#define DD_TDI_DEVICE_NAME                "\\Device\\UNKNOWN"
#define DD_TDI_DEVICE_NAME_U              L"\\Device\\UNKNOWN"

#define _TDI_CONTROL_CODE(Request, Method) \
  CTL_CODE(FILE_DEVICE_TRANSPORT, Request, Method, FILE_ANY_ACCESS)

#define IOCTL_TDI_ACCEPT                  _TDI_CONTROL_CODE(0,  METHOD_BUFFERED)
#define IOCTL_TDI_CONNECT                 _TDI_CONTROL_CODE(1,  METHOD_BUFFERED)
#define IOCTL_TDI_DISCONNECT              _TDI_CONTROL_CODE(2,  METHOD_BUFFERED)
#define IOCTL_TDI_LISTEN                  _TDI_CONTROL_CODE(3,  METHOD_BUFFERED)
#define IOCTL_TDI_QUERY_INFORMATION       _TDI_CONTROL_CODE(4,  METHOD_OUT_DIRECT)
#define IOCTL_TDI_RECEIVE                 _TDI_CONTROL_CODE(5,  METHOD_OUT_DIRECT)
#define IOCTL_TDI_RECEIVE_DATAGRAM        _TDI_CONTROL_CODE(6,  METHOD_OUT_DIRECT)
#define IOCTL_TDI_SEND                    _TDI_CONTROL_CODE(7,  METHOD_IN_DIRECT)
#define IOCTL_TDI_SEND_DATAGRAM           _TDI_CONTROL_CODE(8,  METHOD_IN_DIRECT)
#define IOCTL_TDI_SET_EVENT_HANDLER       _TDI_CONTROL_CODE(9,  METHOD_BUFFERED)
#define IOCTL_TDI_SET_INFORMATION         _TDI_CONTROL_CODE(10, METHOD_IN_DIRECT)
#define IOCTL_TDI_ASSOCIATE_ADDRESS       _TDI_CONTROL_CODE(11, METHOD_BUFFERED)
#define IOCTL_TDI_DISASSOCIATE_ADDRESS    _TDI_CONTROL_CODE(12, METHOD_BUFFERED)
#define IOCTL_TDI_ACTION                  _TDI_CONTROL_CODE(13, METHOD_OUT_DIRECT)

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __NTDDTDI_H */
