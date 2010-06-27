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

#ifndef	_CMS_MMS_H_
#define _CMS_MMS_H_


#include "Cms_MMSGlobal.h"
#include "Cms_MMSCfg.h"
#include	"Cms_MMSClib.h"
//#include    "Cms_WAPOctstr.h"
#include "Cms_MMSTcenProvide.h"
//#include "Cms_MMSProvide.h"
#ifdef HAVE_CMSWAPSTACK
#include "Cms_WAPMain.h"    
//#include "../CommonLib/http/Cms_WAP.h"          
#endif
#include    "Cms_WAPOctstr.h"



#define MMS_EMAIL_SUPPORT
/********************************** Macros ***********************************/
//2003.12.05
#define DEFAULT_SEND_MAXSIZE 55000
#define DEFAULT_RECV_MAXSIZE 55000

/* define mms net work state */

/*
#define MMS_WAP_CONNECT_CLOSE		0x0000//WAP_STOP
#define MMS_WAP_CONNECTED			0x0001//WAP_CONNECT
#define MMS_WAP_DATA_RECEIVED		0x0002//WAP_DATA
#define MMS_WAP_TIME_OUT			0x0003//WAP_TIMEOUT
#define MMS_WAP_DOWNLOAD_FAILED		0x0004//WAP_DOWNFAIL
#define MMS_WAP_DOWNLOAD_SUCCESS	0x0005//WAP_DOWNLOAD
*/
#define MMS_PUSH_ERROR_SERVERINIT	0x0101
#define MMS_PUSH_ERROR_ACCEPT		0x0102
#define MMS_PUSH_ERROR_OPENFILE		0x0103
#define MMS_PUSH_OK					0x0104

#define MMS_SENDSTATUS_OK			0x0111
#define MMS_SENDSTATUS_ERROR		0x0112
#define MMS_RECEIVESTATUS_OK		0x0113
#define MMS_RECEIVESTATUS_ERROR		0x0114

#define	MMS_MESSAGE_ON_SEND_REQ			0x0121
#define	MMS_MESSAGE_ON_SEND_CONF		0x0122
#define	MMS_MESSAGE_ON_NOTIFICATION_IND	0x0123
#define	MMS_MESSAGE_ON_NOTIFYRESP_IND	0x0124
#define	MMS_MESSAGE_ON_RETRIVE_CONF		0x0125
#define	MMS_MESSAGE_ON_ACKNOWLEDGE_IND	0x0126
#define	MMS_MESSAGE_ON_DELIVERY_IND		0x0127

/* macro define of deffrient mms pdu head field length */
#ifndef MAX_VERSION_LENGTH
#define MAX_VERSION_LENGTH			16
#endif
#ifndef MAX_MESSAGEID_LENGTH
#define MAX_MESSAGEID_LENGTH		40
#endif
#ifndef MAX_CONTENTLOCATON_LENGTH
#define MAX_CONTENTLOCATON_LENGTH	100
#endif
#ifndef MAX_RESPONSETEXT_LENGTH
#define MAX_RESPONSETEXT_LENGTH		30
#endif

#ifndef MAX_NAME_LENGTH
#define MAX_NAME_LENGTH				128/*64*/
#endif

#ifndef MAX_CONTENT_LENGTH
#define MAX_CONTENT_LENGTH			128
#endif
#ifndef MAX_SUBJECT_LENGTH
#define MAX_SUBJECT_LENGTH			255   	/*20051104 chaozhuzh modify for subject */
#endif

#ifndef MAX_BOUNDARY_STR_LENGTH	
#define MAX_BOUNDARY_STR_LENGTH   40
#endif	

#ifndef MAX_URL_LENGTH
#define MAX_URL_LENGTH				256
#endif
#ifndef MAX_LENGTH
#define MAX_LENGTH				256
#endif
#ifndef FILE_BLOCK_LENGTH
#define FILE_BLOCK_LENGTH			2048
#endif
#ifndef MAX_SUB_CODE_NUM
#define MAX_SUB_CODE_NUM           40
#endif

/* define address type */
#define		ADDRESS_TYPE_UNKNOWN		0
#define		ADDRESS_TYPE_PLMN			1
#define		ADDRESS_TYPE_IPV4			2
#define		ADDRESS_TYPE_IPV6			3
#define		ADDRESS_TYPE_EMAIL			4

/* Well-known Parameter Assignments */
#define		MMS_TYPE_PA_TYPE				0x09
#define		MMS_TYPE_PA_START				0x0A

/* macro define of deffrient mms bool field value */
#define		MMS_FIELD_VALUE_YES			128
#define		MMS_FIELD_VALUE_NO			129


/* macro define of deffrient time field type value */
#define		MMS_TIME_TYPE_ABCOLUTE		128
#define		MMS_TIME_TYPE_RELATIVE		129

/* macro define of from field value type value */
#define		MMS_FROM_VALUE_TYPE_ADDRESS	128
#define		MMS_FROM_VALUE_TYPE_INSERT	129

/* macro define of from message class type value */
#define		MMS_MESSAGE_CLASS_TYPE_PERSONAL			128
#define		MMS_MESSAGE_CLASS_TYPE_ADVERTISEMENT	129
#define		MMS_MESSAGE_CLASS_TYPE_INFORMATIONAL	130
#define		MMS_MESSAGE_CLASS_TYPE_AUTO				131



/* macro define of message priority value */
#define		MMS_PRIORITY_VALUE_LOW		128
#define		MMS_PRIORITY_VALUE_NORMAL	129
#define		MMS_PRIORITY_VALUE_HIGH		130


/* macro define of send visibility value */
#define		MMS_SENDER_VISIBILITY_HIDE			128
#define		MMS_SENDER_VISIBILITY_SHOW			129


/* macro define of status value */
#define		MMS_STATUS_VALUE_EXPIRED			128
#define		MMS_STATUS_VALUE_RETRIVED			129
#define		MMS_STATUS_VALUE_REJECTED			130
#define		MMS_STATUS_VALUE_DEFERRED			131
#define		MMS_STATUS_VALUE_UNRECOGNISED		132


#define MAX_TEXT_LENGTH     20*1024
typedef enum 
{               
	MMS_NOUSE=-1

	#define MMS_EVENT(name, fields) ,name
	#define INTEGER
	#define OCTSTR
	#include "Cms_MMSEventDecl.h"

} MMSEventType;

typedef enum 
{  
	MMSSTATE_NOUSE= -1

	#define STATE_NAME(name) ,name
	#define ROW(state, event, condition, action, next_state)
	#include "Cms_MMSStateDecl.h"

} MMSState;

	#define INTEGER(name) CMS_MMS_S32 name
	#define OCTSTR(name) Octstr *name
	#define MMS_EVENT(name, fields) struct name fields;
	#include "Cms_MMSEventDecl.h"

typedef struct MMSEvent MMSEvent;
struct MMSEvent 
{
	MMSEventType type;
	MMSEvent *next;

	#define INTEGER(name) 
	#define OCTSTR(name) 
	#define MMS_EVENT(name, fields) struct name name;
	#include "Cms_MMSEventDecl.h"
};
//2003.10.30
typedef struct MMSMachine MMSMachine;
struct MMSMachine
	#define OCTSTR(name)  Octstr *name
	#define INTEGER(name) CMS_S64 name
	#define CHARARR8(name) unsigned char name[8]
	#define EVENT_POINTER(name) MMSEvent *name
	#define MMS_MACHINE(fields) fields
	#include "Cms_MMSMachineDecl.h"
;



typedef enum 
{
	MMS_ABORT_USERREQ = 1,
	MMS_ABORT_WAPERROR
}MMS_ABORT_TYPE;
//CECW needs note
typedef struct
{
	int fd;  
}t_CMSFile;//CMS file struct

typedef struct tagNetLinkTimer {
	long start_time;
	long interval;
	//WTPMachine *machine;
	//MMSEvent *event;
}NetLinkTimer;

//2003.8.31
typedef struct tagContent_fname_cid_mapper CONTENT_FNAME_CID_MAPPER;
struct tagContent_fname_cid_mapper
{
	char fname[MAX_NAME_LENGTH];
	char cid[MAX_NAME_LENGTH];
	int ctype;
	//加入判断该资源是否用到
	int isused;
	CONTENT_FNAME_CID_MAPPER *next;
};


#endif /* _CMS_MMS_H_ */
