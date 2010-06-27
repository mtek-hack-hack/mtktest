/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSProvide.h"

    $Revision:

    $vision:       1.00

    $Date:         05/23/2003

    $Author:       Shawn Pan

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
#ifndef     _CMS_MMS_PROVIDE_H
#define     _CMS_MMS_PROVIDE_H
#include "Cms_callback.h"//  Modified by TIPrj[2005/7/14]  
#include "Cms_MMSGlobal.h"
#include "Cms_MMSDoc.h"
#ifndef     MMSHANDLE
#define		MMSHANDLE		void*
#endif

#ifndef     bool
#define     bool            int
#endif



#ifndef WTP_PACKET_SIZE
#define WTP_PACKET_SIZE  1395//1020
#endif
//#define CECW_RECV_MRU  WTP_PACKET_SIZE+10   
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

/*------------------------------------------------------------------------
 *
 *
 *
 *               the size of variable in a struct should be times of 4 bytes 
 *           this is padding
 *
 *
------------------------------------------------------------------------*/

/*------------------------------------------------------------------------
 *
 *
 *			
 *          use this to  malloc space
 *           
 *
 *
------------------------------------------------------------------------*/
#ifndef WTP_MTU
#define WTP_MTU                         1500
#endif
#ifndef WTP_RECV_MAXSPACE
#define WTP_RECV_MAXSPACE               WTP_MTU+100
#endif
/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS head field definition
 *
 *
 *
------------------------------------------------------------------------*/
#ifndef     MMS_BCC
#define		MMS_BCC					0x01
#endif

#ifndef		MMS_CC
#define		MMS_CC					0x02
#endif

#ifndef		MMS_CONTENT_LOCATION
#define		MMS_CONTENT_LOCATION	0x03
#endif

#ifndef		MMS_CONTENT_TYPE
#define		MMS_CONTENT_TYPE		0x04
#endif

#ifndef		MMS_DATE	
#define		MMS_DATE				0x05
#endif

#ifndef		MMS_DELIVERY_REPORT
#define		MMS_DELIVERY_REPORT		0x06
#endif

#ifndef		MMS_DELIVERY_TIME
#define		MMS_DELIVERY_TIME		0x07
#endif

#ifndef		MMS_EXPIRY
#define		MMS_EXPIRY				0x08
#endif

#ifndef		MMS_FROM
#define		MMS_FROM				0x09
#endif

#ifndef		MMS_MESSAGE_CLASS
#define		MMS_MESSAGE_CLASS		0x0a
#endif

#ifndef		MMS_MESSAGE_ID
#define		MMS_MESSAGE_ID			0x0b
#endif

#ifndef		MMS_MESSAGE_TYPE
#define		MMS_MESSAGE_TYPE		0x0c
#endif

#ifndef		MMS_MMS_VERSION
#define		MMS_MMS_VERSION			0x0d
#endif

#ifndef		MMS_MESSAGE_SIZE
#define		MMS_MESSAGE_SIZE		0x0e
#endif

#ifndef		MMS_PRIORITY
#define		MMS_PRIORITY			0x0f
#endif

#ifndef		MMS_READ_REPLY
#define		MMS_READ_REPLY			0x10
#endif

#ifndef		MMS_REPORT_ALLOWED
#define		MMS_REPORT_ALLOWED		0x11
#endif

#ifndef		MMS_RESPONSE_STATUS
#define		MMS_RESPONSE_STATUS		0x12
#endif

#ifndef		MMS_RESPONSE_TEXT
#define		MMS_RESPONSE_TEXT		0x13
#endif

#ifndef		MMS_SENDER_VISIBILITY
#define		MMS_SENDER_VISIBILITY	0x14
#endif

#ifndef		MMS_STATUS
#define		MMS_STATUS				0x15
#endif

#ifndef		MMS_SUBJECT
#define		MMS_SUBJECT				0x16
#endif

#ifndef		MMS_TO
#define		MMS_TO					0x17
#endif

#ifndef		MMS_TRANSACTION_ID
#define		MMS_TRANSACTION_ID		0x18
#endif


/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS message type value definition
 *
 *
 *
------------------------------------------------------------------------*/
#ifndef		MMS_MESSAGE_TYPE_SEND_REQ
#define		MMS_MESSAGE_TYPE_SEND_REQ			128
#endif

#ifndef     MMS_MESSAGE_TYPE_SEND_CONF
#define		MMS_MESSAGE_TYPE_SEND_CONF			129
#endif
#ifndef     MMS_MESSAGE_TYPE_NOTIFICATION_IND
#define		MMS_MESSAGE_TYPE_NOTIFICATION_IND	130
#endif

#ifndef     MMS_MESSAGE_TYPE_NOTIFYRESP_IND
#define		MMS_MESSAGE_TYPE_NOTIFYRESP_IND		131
#endif

#ifndef     MMS_MESSAGE_TYPE_RETRIVE_CONF
#define		MMS_MESSAGE_TYPE_RETRIVE_CONF		132
#endif

#ifndef     MMS_MESSAGE_TYPE_ACKNOWLEDGE_IND
#define		MMS_MESSAGE_TYPE_ACKNOWLEDGE_IND	133
#endif

#ifndef     MMS_MESSAGE_TYPE_DELIVERY_IND
#define		MMS_MESSAGE_TYPE_DELIVERY_IND		134
#endif
/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS head field macro definition
 *
 *
 *
------------------------------------------------------------------------*/

/* define address type */
#ifndef		ADDRESS_TYPE_UNKNOWN
#define		ADDRESS_TYPE_UNKNOWN		0
#endif
#ifndef		ADDRESS_TYPE_PLMN
#define		ADDRESS_TYPE_PLMN			1
#endif
#ifndef		ADDRESS_TYPE_IPV4
#define		ADDRESS_TYPE_IPV4			2
#endif

#ifndef		ADDRESS_TYPE_IPV6
#define		ADDRESS_TYPE_IPV6			3
#endif
#ifndef		ADDRESS_TYPE_EMAIL
#define		ADDRESS_TYPE_EMAIL			4
#endif

/* Well-known Parameter Assignments */
#ifndef		MMS_TYPE_PA_TYPE
#define		MMS_TYPE_PA_TYPE				0x09
#endif
#ifndef		MMS_TYPE_PA_START
#define		MMS_TYPE_PA_START				0x0A
#endif

/* macro define of deffrient mms bool field value */
#ifndef		MMS_FIELD_VALUE_YES
#define		MMS_FIELD_VALUE_YES			128
#endif

#ifndef		MMS_FIELD_VALUE_NO
#define		MMS_FIELD_VALUE_NO			129
#endif


/* macro define of deffrient time field type value */
#ifndef		MMS_TIME_TYPE_ABCOLUTE
#define		MMS_TIME_TYPE_ABCOLUTE		128
#endif
#ifndef		MMS_TIME_TYPE_RELATIVE
#define		MMS_TIME_TYPE_RELATIVE		129
#endif

/* macro define of from field value type value */
#ifndef		MMS_FROM_VALUE_TYPE_ADDRESS
#define		MMS_FROM_VALUE_TYPE_ADDRESS	128
#endif
#ifndef		MMS_FROM_VALUE_TYPE_INSERT
#define		MMS_FROM_VALUE_TYPE_INSERT	129
#endif

/* macro define of from message class type value */
#ifndef		MMS_MESSAGE_CLASS_TYPE_PERSONAL
#define		MMS_MESSAGE_CLASS_TYPE_PERSONAL			128
#endif
#ifndef		MMS_MESSAGE_CLASS_TYPE_ADVERTISEMENT
#define		MMS_MESSAGE_CLASS_TYPE_ADVERTISEMENT	129
#endif
#ifndef		MMS_MESSAGE_CLASS_TYPE_INFORMATIONAL
#define		MMS_MESSAGE_CLASS_TYPE_INFORMATIONAL	130
#endif
#ifndef		MMS_MESSAGE_CLASS_TYPE_AUTO
#define		MMS_MESSAGE_CLASS_TYPE_AUTO				131
#endif

#ifndef		MMS_DELIVERY_REPORT_YES                
#define		MMS_DELIVERY_REPORT_YES                   1
#endif

#ifndef		MMS_DELIVERY_REPORT_NO                
#define		MMS_DELIVERY_REPORT_NO                   0
#endif

#ifndef		MMS_READ_REPORT_YES                
#define		MMS_READ_REPORT_YES                   1
#endif

#ifndef		MMS_READ_REPORT_NO                
#define		MMS_READ_REPORT_NO                   0
#endif

/* macro define of message priority value */
#ifndef		MMS_PRIORITY_VALUE_LOW
#define		MMS_PRIORITY_VALUE_LOW		128
#endif
#ifndef		MMS_PRIORITY_VALUE_NORMAL
#define		MMS_PRIORITY_VALUE_NORMAL	129
#endif
#ifndef		MMS_PRIORITY_VALUE_HIGH
#define		MMS_PRIORITY_VALUE_HIGH		130
#endif




/* macro define of send visibility value */
#define		MMS_SENDER_VISIBILITY_HIDE			128
#define		MMS_SENDER_VISIBILITY_SHOW			129


/* macro define of status value */
#define		MMS_STATUS_VALUE_EXPIRED			128
#define		MMS_STATUS_VALUE_RETRIVED			129
#define		MMS_STATUS_VALUE_REJECTED			130
#define		MMS_STATUS_VALUE_DEFERRED			131
#define		MMS_STATUS_VALUE_UNRECOGNISED		132
#if 0 //  Modified by TIPrj[2005/7/13]
/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS bottom message funcion param definition
 *
 *
 *
------------------------------------------------------------------------*/
typedef enum
{
	NETLINK_RETURN = 0,
	SENDDATA_RETURN,
	DATAARRIVED,
	NETCLOSELINK_RETURN,
	FILEOPRATE_RETURN,
	DIR_OPREATE_RETURN,
	//CECW_TIMER_MSG,//timout　
	WTP_TIMEROUT_MSG
}CenMsgType;

typedef enum
{
	NETLINK_FAILED,
	NETLINK_SUCCESS
}NETLINK_RETURN_VALUE;//after netlink

typedef enum
{
	SENDDATA_FAILED,
	SENDDATA_SUCCESS
}SENDDATA_RETURN_VALUE;



typedef enum
{
	MMSNETLINKING,
	MMSNETLINK_SUCCESS,
	WAPCONNECT_SUCCESS,
	MMS_RECEIVING,
	MMS_SENDING,
	MMSNETLINK_FAILED,
	MMSWAPCONNECT_FAILED,
	//MMSSEND_FAILED,
	//MMSSEND_SUCCESS,
	MMSRECV_FAILED,
	MMSRECV_FAILED_BY_NOT_FOUND,
	MMSRECV_FINISHED,
	MMSRECV_SUCCESS,
	MMSOPR_CANCEL,
	MMSWAP_DISCONNECTED,
	MMSSYSTEM_ERROR,
	MMSUNKNOWN_ERROR,
	MMSNET_DISCONNECTED,
	MMSNET_DISCONNECTING,
	/* macro define of Response status value */
	MMS_RESPONSE_STATUS_VALUE_OK					=128,
	MMS_RESPONSE_STATUS_VALUE_E_UNSPECIFIED			=129,
	MMS_RESPONSE_STATUS_VALUE_E_SERVICE_DENIED		=130,
	MMS_RESPONSE_STATUS_VALUE_E_FORMAT_CORRUPT		=131,
	MMS_RESPONSE_STATUS_VALUE_E_ADDRESS_UNRESOLVED	=132,
	MMS_RESPONSE_STATUS_VALUE_E_MESSAGE_NOT_FOUND	=133,
	MMS_RESPONSE_STATUS_VALUE_E_NETWORK_PROBLEM		=134,
	MMS_RESPONSE_STATUS_VALUE_E_NOT_ACCEPTED		=135,
	MMS_RESPONSE_STATUS_VALUE_E_UNSUPORTED_MESSAGE	=136,
	MMS_RESPONSE_STATUS_VALUE_E_UNKNOW_ERROR        =999,

}MMS_LIBSTATUS_VALUE;


typedef enum
{
	SMS_TYPE_DELIVERY_IND,             
	SMS_TYPE_NOTIFICATION_IND,          
	SMS_TYPE_UNKNOW,
}SMS_HANDLE_STATUS;


typedef enum mmsliberrcode{
	MMS_NO_ERROR = 0,                             //没有错误
	MMSMEMORY_ERROR,
	MMSSEND_ABORT,
	MMSRECV_ABORT,
	MMSTEXT_TOOLARGE,
	MMSIMAGEAUDIO_TOOLARGE,
	MMSMSG_TOOLARGE,
}MMSLIBERRCODE;

/*------------------------------------------------------------------------
 *
 *
 *
 *                 some data stucture set before sending
 *					
 *
 *
------------------------------------------------------------------------*/
typedef struct tag_send_setting
{
	char *send_vfilename;
	char *conf_vfilename;
}MMS_SEND_SETTING;
typedef struct tag_recv_setting
{
	char *get_url;
	char *recv_vfilename;
	bool immediate_recv;   //if receiving immediately,1 means receiving imediately;0,the opposite.
	int recv_msgsize;
}MMS_RECV_SETTING;
typedef struct tag_mmsconfig_setting
{
	unsigned char *wap_gateway;  //gateway address，China Mobile provide it as "10.0.0.172"  2003.11.03
	char *mms_centery;  //mms centry，China Mobile provide as "Http://mmsc.monternet.com/"
	int   wap_port;     //wap wtp port  9201
}MMS_CONFIG_SETTING;
/*------------------------------------------------------------------------
 *
 *
 *
 *                 display some subject as phone to the upper
 *					
 *
 *
------------------------------------------------------------------------*/
typedef struct tag_sms_msg
{
	int  msgsize;                      //消息大小
	long de_date;					   //delivery report date
	int  de_status;                    //delivery report status

	char *de_msgid;                    //delivery report message id
	char *de_to;                        //delivery report receiver


    char *mms_url;                     //MMS所在的URL
    char *phone_number;                //发件人的电话
    char *subject;                     //MMS主题
	char *tid;                          //transaction ID
}NOTIFICATION_IND_SMS_MSG;

#endif //  Modified by TIPrj[2005/7/13]
#if 0
/*------------------------------------------------------------------------
 *
 *
 *
 *                     MMS callback mmsproc
 *					report the status to upper
 *
 *
------------------------------------------------------------------------*/
typedef enum
{
	LIB_STATUS_SENDRETURN,                  
	LIB_STATUS_RECVRETURN,                 
	LIB_STATUS_NORMAL_STATUS,               
	LIB_STATUS_TOTAL_BYTES,
	LIB_STATUS_SENDED_BYTES,
	LIB_STATUS_RECVED_BYTES,
}MMS_LIBSTATUS;  
#endif
/*------------------------------------------------------------------------
 *                 MMS文档结构定义
 *					
 *
 *
------------------------------------------------------------------------*/
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

#ifndef MAX_BOUNDARY_STR_LENGTH	
#define MAX_BOUNDARY_STR_LENGTH   40
#endif	

#ifndef MAX_CONTENT_LENGTH
#define MAX_CONTENT_LENGTH			128
#endif
#ifndef MAX_SUBJECT_LENGTH
#define MAX_SUBJECT_LENGTH			255		 	/*20051104 chaozhuzh modify for subject */
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


/* 
*	Added by longqiangl 
*	2003-07-01 
*	MMS client should process correctly multi-recepient information
*	tag_MMS_RECEPIENT is defined for this consideration
*	The MMS recepient information , including To/CC/BCC  
*/
typedef struct tag_MMS_RECEPIENT
{
	struct tag_MMS_RECEPIENT 	*p_next;

	/* Address of the recipient. */
	char				m_address[MAX_NAME_LENGTH];
}MMS_RECEPIENT;
typedef MMS_RECEPIENT*	p_MMS_RECEPIENT;

typedef struct _CmsMMSHead
{
	/* Internal Flags */
	int	flagMultipartRelated;

	/* Header Fields Flags */
    int	flagBccAvailable;
    int	flagCcAvailable;
    int	flagContentTypeAvailable;
    int	flagDateAvailable;
    int	flagDeliveryReportAvailable;
    int	flagDeliveryTimeAvailable;
    int	flagDeliveryTimeAbsolute;
    int	flagExpiryAvailable;
    int	flagExpiryAbsolute;
    int	flagFromAvailable;
    int	flagMessageClassAvailable;
    int	flagMessageIdAvailable;
    int	flagMessageTypeAvailable;
    int	flagMMSVersionAvailable;
    int	flagPriorityAvailable;
    int	flagReadReplyAvailable;
    int	flagSenderVisibilityAvailable;
    int	flagStatusAvailable;
    int	flagSubjectAvailable;
    int	flagToAvailable;
    int	flagTransactionIdAvailable;
	/* hulf add */
    int	flagContentLocationAvailable;
    int	flagReportAllowedAvailable;
    int	flagResponseStatusAvailable;
    int	flagResponseTextAvailable;
    int	flagMessageSizeAvailable;

	/* head flied value */
	
/* 
*	Revised by longqiangl 
*	2003-07-01 
*/
	//char		Mms_bcc[MAX_NAME_LENGTH];/* Address of the recipient. */
	//char		Mms_cc[MAX_NAME_LENGTH];	/* Address of the recipient. */
	p_MMS_RECEPIENT		p_bcc_head;
	p_MMS_RECEPIENT		p_cc_head;	

	char		Mms_content_location[MAX_CONTENTLOCATON_LENGTH];	
									/* This field defines the location of the message. */
	char		Mms_content_type[MAX_CONTENT_LENGTH];		
									/* The content type of the message. */
	int		Mms_date;				/* Arrival time of the message at MMSProxy -Relay. 
										MMS Proxy -Relaywill generate this field when 
										not supplied by terminal. */
	
	int		Mms_delivery_time;		/* default: immediate.
										Time of desired delivery. Indicates the earliest 
										possible delivery of the message to the recipient. 
										The field has two formats, either absolute or 
										CMS_MMS_S32erval. */
	int		Mms_expiry;				/* default: maximum.
										Length of time the message will be stored in MMS
										Proxy-Relayor time to delete the message. The field has
										two formats, either absolute or CMS_MMS_S32erval. */
	char		Mms_from[MAX_NAME_LENGTH];	
									/* Address of the sender. If hiding the address of the sender
										from the recipient is supported, the MMS Proxy -Relay
										will not add this field to a message header. */
	
	char				Mms_message_ID[MAX_MESSAGEID_LENGTH];	
									/* This is an unique reference assigned to message. This ID
										SHALL always be present when the originator client
										requested a read reply.
										The ID enables a client to match read reports with */
									/* Encoded as in email address as per [RFC822]. 
										The characters "<" and ">" are not included. */
	unsigned char		Mms_message_class;		/* Class of the message. */
	unsigned char		Mms_delivery_report;	/* Default determined when service is ordered.
										Specifies whether the user wants a delivery 
										report from each recipient. When Message-Class 
										is Auto, the field SHALL always be present and 
										the value SHALL be No. */
	unsigned char		Mms_message_type;		/* Specifies the message type. */
	unsigned char		Mms_mms_version;		/* The MMS version number. According to this
										specification, the version is 1.0. */
									/* The three most significant bits of the Short-CMS_MMS_S32eger are 
										CMS_MMS_S32erpreted to encode a major version number in the range 1-7,
										and the four least significant bits contain a minor version 
										number in the range 0-14. If there is only a major version
										number, this is encoded by placing the value 15 in the four 
										least significant bits [WAPWSP]. */
	long		Mms_message_size;		/* Full size of message in octets. */
	unsigned char		Mms_priority;			/* Default: Normal.
												Priority of the message for the recipient. */
	unsigned char		Mms_read_reply;			/* Specifies whether the user wants a read report from each
										recipient as a new message. When Message-Class is
										Auto, the field SHALL always be present and the value
										SHALL be No. */
	unsigned char		Mms_report_allowed;		/* Default: Yes.
												Sending of delivery report allowed to the user or not. */
	unsigned char		Mms_response_status;	/* MMS specific status. */
	char				Mms_response_text[MAX_RESPONSETEXT_LENGTH];
											/* Description which qualifies the response status value. */
	char 	Mms_subj[MAX_SUBJECT_LENGTH+12];	
	
									/* Subject of the message. */
/* 
*	Revised by longqiangl 
*	2003-07-01 
*/
	//char		Mms_to[MAX_NAME_LENGTH];	
									/* Address of the recipient. */
	p_MMS_RECEPIENT		p_to_head;	

	
									/* Address of the recipient. */
	char		Mms_transaction_ID[MAX_NAME_LENGTH];
	unsigned char		Mms_sender_visibility;	/* Default: show address/phone number of the
										sender to the recipient unless the sender has a secret
										number/address.
										Hide = don't show any address. Show = show even secret
										address. */
	unsigned char		Mms_status;				/* Message status. The status Retrieved SHALL be used
											only after successful retrieval of multimedia message. */

									/* This transaction ID identifies the M-Send.conf and the
										corresponding request only. */
	//CENT_FILL_FIELD2
} CmsMMSHead;

/* struct define: MMSContentHead
 * define data block head information in rfc2387 mutipart/related
 */
/*
typedef struct _MMSContentHead
{
	CMS_MMS_S8	Charset[30];					
	CMS_MMS_S8	Type[30];						
	CMS_MMS_S8	Encoding[30];					
}	MMSContentHead;
*/
/* struct define: MMSContentList
 * define data block list in MMS PDU body
 */
typedef struct _MMSContentList
{
	int		start;								/* start poCMS_MMS_S32 of this data block */
	int		length;								/* length of this data block */
	char		type[MAX_CONTENT_LENGTH];			/* format type of this block */
	char		id[MAX_NAME_LENGTH];					/* id value or filename of this block */
	char		filename[MAX_NAME_LENGTH];			/* file name of this block */
	struct _MMSContentList	*firstchild;		/* first child of this data block */
	struct _MMSContentList	*next;				/* next of this data block */
}MMSContentList;


/* struct define: CmsMMSDocument
 *  CmsMMSDocument describe a mms pdu
 */
typedef struct _CmsMMSDocument
{
	char		mmsfile[MAX_NAME_LENGTH];	/* filename of mm */
	char		mmsstart[MAX_NAME_LENGTH];	/* smil or wml document id(filename) */
	char		mmstype[MAX_NAME_LENGTH];	/* document type */
	MMSContentList  *ccontent;				/* current content in body */
	CmsMMSHead		*mmshead;				/* head of mm */
	MMSContentList  *content;				/* content list in body */
	int     mms_totalsize;  //2003.11.03
}CmsMMSDocument;
typedef CmsMMSDocument *P_MMS_DOCUMENT;

/*------------------------------------------------------------------------
 *
 *
 *
 *                 the Interface of CECW &MMS lib 
 *                 about the bottom message handle					
 *
 *
------------------------------------------------------------------------*/


void mmsEventPostEvent(CenMsgType type,unsigned int param1,void* param2);
void mmsEventProcessEvent(void);
/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMs init，send receive SMS handle interface
 *					
 *
 *
------------------------------------------------------------------------*/
void WAP_GlobalV_Init(void);
void MMS_GlobalV_Init(void);

int MMS_Init(void);
int MMS_SetMaxSize(int send_maxsize,int recv_maxsize);
void MMS_Close(void);
bool MMS_Machine_Config(MMS_CONFIG_SETTING *p_cfgset);

MMSHANDLE MMS_NewMms(void);

int MMS_DeleteMms(MMSHANDLE mmsdoc);
int MMS_SetDefault(MMSHANDLE mmsdoc, int mmstype);
void	MmsSetReadReportDefault(MMSHANDLE mmsdoc,char* messageId);

int MMS_SetMmsFile(MMSHANDLE mmsdoc, char *mmsfile);
int MMS_GetMmsFile(MMSHANDLE mmsdoc, char *mmsfile);

int MMS_SetMmsHeadField(MMSHANDLE mmsdoc, int field, long ivalue, char *svalue);
int MMS_GetMmsHeadField(MMSHANDLE mmsdoc, int field, long *ivalue, char *svalue);
int MMS_ClearMmsHeadField(MMSHANDLE mmsdoc, int field);


//void mms_storecontent(MMSHANDLE mmsdoc);
void MMS_SetContentID_SUPPORT(int y_n);
int MMS_EncodeMms(MMSHANDLE mmsdoc);
int MMS_DecodeMms(MMSHANDLE mmsdoc);
CmsMMSHead *MMS_Decode_Header(char *filename);
void MMS_DeleteHead(CmsMMSHead* mmshead);
int MmsDecodeHead(MMSHANDLE mmsdoc);



int MMS_SendMms(MMS_SEND_SETTING *send_setting,mmsproc proc);
int MMS_ReceiveMms(MMS_RECV_SETTING *recv_setting,mmsproc proc);
int MMS_DeferMms(NOTIFICATION_IND_SMS_MSG *p_msg,MMS_CONFIG_SETTING *p_cfgset);
void MMS_SendRecvCancel(void);
int MMS_sms_onpushmessage(unsigned char *sms_userdata,int sms_userdata_len,int flag_userdata_head,smsproc proc);

/*P_MMS_DOUCMENT 和pMMS_EDocument struct converter*/
int cms_parse_mms(char * filename, pMMS_EDocument theDocument);
MMSHANDLE	cms_integrate_mms(pMMS_EDocument pMms_edoc);
//int cms_mms_saveasmodu(pMMS_EDocument pMms_edoc,char * mmsfile);
void timer_thread(void);
MMSLIBERRCODE MMS_GetLastError(void);

#undef bool

#endif  /*#ifndef     _CMS_MMS_PROVIDE_H*/