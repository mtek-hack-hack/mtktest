/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSCfg.h"

    $Revision:

    $vision:       1.00

    $Date:         05/16/2003

    $Author:       Shawn

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

Abstract:

Modified By:

Environment: 

Revision History:

=====================================================================*/
#ifndef	_MMSCFG_H_
#define _MMSCFG_H_
#define		ENCODE_NAME
//#define		CMS_MMS_DEBUG

//if have WAP stack support,used for debug
#define HAVE_CMSWAPSTACK

//if have the tcp/ip support,used for debug


#define CENT_MMS_LIBRARY_REALEASE
#undef CENT_MMS_LIBRARY_DEBUG
#define CENT_DEF_UNICODE

#include "cms_sysfun.h"
#include "cms_debug.h"

#undef DOPOD_TEST
#ifdef DOPOD_TEST
//#define cms_malloc malloc
//#define cms_free free
#endif

#if 0
	#define MMS_ACCESSORY
#endif

#define cms_mms_debug cms_trace
#endif /* _MMSCFG_H_ */





