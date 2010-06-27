/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSSmil.h"

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

Modified By: Shawn Pan 2003.5.16

Environment: 

Revision History:

=====================================================================*/

#ifndef	_CMS_SMIL_H_
#define _CMS_SMIL_H_




#include "Cms_MMSGlobal.h"
#include "Cms_MMSDoc.h"


/* define bool integer */
#ifndef     TRUE
#define		TRUE		1
#endif
#ifndef     FALSE
#define		FALSE		0
#endif



#define MMS_TXT_SIZE_SMALL	12
#define MMS_TXT_SIZE_NORMAL	16
#define MMS_TXT_SIZE_LARGE	20


#ifndef MMS_RGB
#define MMS_RGB(r, g ,b)    ((CMS_MMS_U32) (((CMS_MMS_U8)(r) | ((CMS_MMS_U16)(g)<<8)) | ((CMS_MMS_U32)((CMS_MMS_U8)(b))<<16)))
#endif

/* define document type */
#ifndef     DOCUMENT_TYPE_WML
#define		DOCUMENT_TYPE_WML			1
#endif
#ifndef     DOCUMENT_TYPE_SMIL
#define		DOCUMENT_TYPE_SMIL			2
#endif
#ifndef     DOCUMENT_TYPE_MMS
#define		DOCUMENT_TYPE_MMS			3
#endif

/* define image type */

#ifndef     MMS_TYPE_WBMP
#define		MMS_TYPE_WBMP				1
#endif
#ifndef     MMS_TYPE_BMP1
#define		MMS_TYPE_BMP1				2//20051018 chaozhuzh modify for MTK
#endif
#ifndef     MMS_TYPE_GIF
#define		MMS_TYPE_GIF				3
#endif
#ifndef     MMS_TYPE_JPEG
#define		MMS_TYPE_JPEG				4
#endif
#ifndef     MMS_TYPE_PNG
#define		MMS_TYPE_PNG				5
#endif

#ifndef MMS_TYPE_BMP
#define MMS_TYPE_BMP 0x09
#endif



/*=============== structures define ===================================*/



CMS_MMS_S32 cms_parse_mms(CMS_MMS_S8 * filename, pMMS_EDocument theDocument);
CMS_MMS_S32	MMS_2Smil(pMMS_EDocument pDocument, CMS_MMS_FILE out);
MMSHANDLE	cms_integrate_mms(pMMS_EDocument pMms_edoc);


#endif