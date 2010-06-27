/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSDebug.h"

    $Revision:

    $vision:       1.00

    $Date:         08/10/2002

    $Author:       hulf

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

#ifndef CMS_MMS_DEBUG_H
#ifdef CENT_MMS_LIBRARY_DEBUG
#elif (defined CENT_MMS_LIBRARY_REALEASE)
//#define cms_mms_debug(val1,val2)   mms_Tracer(val1)
#elif(defined DOPOD_TEST)
/*
#define cms_mms_debug(val1,val2)              {  \
												char* temp;  \
												FILE*f;  \
												f = fopen("\\windows\\cmsmms\\sr1.txt", "ab+");  \
												fprintf(f,val1,val2);  \
												fclose(f);  \
											}
*/
 #else
//#define  cms_mms_debug(val1,val2)  printf(val1,val2)

#endif




void mms_hex_write(unsigned char *buff,int len);





#endif