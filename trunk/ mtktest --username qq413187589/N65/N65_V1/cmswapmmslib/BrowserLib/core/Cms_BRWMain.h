/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSMain.h"

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

#ifndef	_CMS_BRWMAIN_H_
#define _CMS_BRWMAIN_H_


//#include "Cms_MMSGlobal.h"
//#include "Cms_MMSCfg.h"
//#include	"Cms_MMSClib.h"
//#include    "Cms_WAPOctstr.h"
//#include "Cms_MMSTcenProvide.h"
//#include "Cms_MMSProvide.h"
//#include "Cms_WAPMain.h"    
//#include "Cms_WAP.h"          
#include "Cms_WAPOctstr.h"
//#include "Cms_WSP.h"


/********************************** Macros ***********************************/
//2003.12.05
//#define SUPPORTED_SEND_MMS_MAXSIZE 55000
//#define SUPPORTED_RECV_MMS_MAXSIZE 55000

/* define mms net work state */

/*
#define MMS_WAP_CONNECT_CLOSE		0x0000//WAP_STOP
#define MMS_WAP_CONNECTED			0x0001//WAP_CONNECT
#define MMS_WAP_DATA_RECEIVED		0x0002//WAP_DATA
#define MMS_WAP_TIME_OUT			0x0003//WAP_TIMEOUT
#define MMS_WAP_DOWNLOAD_FAILED		0x0004//WAP_DOWNFAIL
#define MMS_WAP_DOWNLOAD_SUCCESS	0x0005//WAP_DOWNLOAD
*/


typedef enum 
{               
	BRW_NOUSE=-1

	#define BRW_EVENT(name, fields) ,name
	#define INTEGER
	#define OCTSTR
	#include "Cms_BRWEventDecl.h"

} BRWEventType;

typedef enum 
{  
	BRWSTATE_NOUSE= -1

	#define STATE_NAME(name) ,name
	#define ROW(state, event, condition, action, next_state)
	#include "Cms_BRWStateDecl.h"

} BRWState;

	#define INTEGER(name) int name
	#define OCTSTR(name) Octstr *name
	#define BRW_EVENT(name, fields) struct name fields;
	#include "Cms_BRWEventDecl.h"

typedef struct BRWEvent BRWEvent;
struct BRWEvent 
{
	BRWEventType type;
	BRWEvent *next;

	#define INTEGER(name) 
	#define OCTSTR(name) 
	#define BRW_EVENT(name, fields) struct name name;
	#include "Cms_BRWEventDecl.h"
};

typedef struct BRWMachine BRWMachine;
struct BRWMachine
	#define OCTSTR(name)  Octstr *name
	#define INTEGER(name) CMS_S64 name
	#define CHARARR8(name) unsigned char name[8]
	#define EVENT_POINTER(name) BRWEvent *name
	#define BRW_MACHINE(fields) fields
	#include "Cms_BRWMachineDecl.h"
;



typedef enum 
{
	BRW_ABORT_USERREQ = 1,
	BRW_ABORT_WAPERROR //, //  Modified by TIPrj[2005/6/29]
}BRW_ABORT_TYPE;
//CECW needs note
typedef struct
{
	int fd;  
}t_CMSFile;//CMS file struct

typedef struct tagNetLinkTimer {
	long start_time;
	long interval;
	//WTPMachine *machine;
	//BRWEvent *event;
}NetLinkTimer;



void SetJarDownloadFail(void);
void setifCurrentDialingVirtual(int flag);
int CmsDownLoadJar( char *url, int message_size, brwproc call_back);
void ota_get_recvdata(unsigned char ** pp_data,int *p_len);
#endif /* _CMS_BRW_H_ */
