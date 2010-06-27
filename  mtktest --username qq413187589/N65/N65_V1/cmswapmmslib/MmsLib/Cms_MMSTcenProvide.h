/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSTcenProvide.h"

    $Revision:

    $vision:       1.00

    $Date:         05/23/2003

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
#ifndef     _CMS_MMS_TCEN_PROVIDE_H
#define     _CMS_MMS_TCEN_PROVIDE_H


//extern void *cms_malloc(unsigned int length);
//extern void *cms_mallocTrace(unsigned int length,char * filename, int line);
//#define cms_malloc(len) cms_mallocTrace(len, __FILE__, __LINE__)
//extern void cms_free(void *pointer);

extern void mms_NetConnect(void);
extern void mms_NetDisconnect(void);

//extern void cms_mms_debug(unsigned char *prompt_string,short data_size,void *p_data);
extern void mms_Tracer(char *p_Buf);

/*chaozhuzh 20051005 modify for MTK begin*/
extern void mms_StartTimer(unsigned char id,long ms);
extern void mms_StopTimer (unsigned char id);
/*chaozhuzh 20051005 modify for MTK end*/



#endif