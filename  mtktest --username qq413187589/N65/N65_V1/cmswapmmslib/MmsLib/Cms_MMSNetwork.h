/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: cms_mms_network.h

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



#ifndef _CMS_MMS_NETWORK_H_
#define _CMS_MMS_NETWORK_H_

#include "Cms_MMSGlobal.h"
#include "Cms_MMSCfg.h"
#include "Cms_MMSMain.h"


#if __cplusplus
extern "C" {
#endif

/*CMS_MMS_S32	init_app(P_ManagerDocument manager);
CMS_MMS_S32	init_network(P_ManagerDocument manager);
CMS_MMS_S32	destroy_network(void);*/

int CMS_MMS_SEND_CONFIRM(char *filename);
int CMS_MMS_ON_NOTIRESP_INDICATE(CMS_MMS_S8 *filename,CMS_MMS_S8 *noti_resp_filename);
int CMS_MMS_NOTIRESP_INDICATE(char *filename);
int CMS_MMS_RETRIVE_CONFIRM(char *filename);
//int CMS_MMS_ACKN_INDICATE(MMSHANDLE	mmsdoc);
/*tauren.chow 20050922 modify for mms push indicate begin*/
int CMS_MMS_ON_DELI_INDICATE(MMSHANDLE	mmsdoc,smsproc sproc);
int CMS_MMS_ON_NOTI_INDICATE(MMSHANDLE	mmsdoc,smsproc sproc);
/*tauren.chow 20050922 modify for mms push indicate end*/
int CMS_MMS_ON_PUSH_INDICATE(char *filename,smsproc sproc);

//CMS_MMS_S32 mms_network_callback(CMS_MMS_S32 msg, void *data);
//CMS_MMS_S32	mms_createnetthread(CMS_MMS_S8 *filename);



#endif /* _CMS_MMS_NETWORK_H_ */
