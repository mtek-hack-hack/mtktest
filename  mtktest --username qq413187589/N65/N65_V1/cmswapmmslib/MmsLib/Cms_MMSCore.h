/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSCore.h"

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

#ifndef _MMSCORE_H_
#define _MMSCORE_H_

#include "Cms_MMSGlobal.h"
#include "Cms_MMSCfg.h"
#include "Cms_MMSClib.h"
#include "Cms_MMSMain.h"

/*------------------------DRM BEGIN---------------------*/
/*luyan 04-07-09*/
/* content-type block maybe include these information*/
typedef struct TAG_MMS_CONTENT_TYPE_INF
{
	CMS_MMS_S32	charset;
	CMS_MMS_S8	content_type[MAX_CONTENT_LENGTH];
	CMS_MMS_S8	filename[MAX_NAME_LENGTH];
	CMS_MMS_S8  boundary_str[MAX_BOUNDARY_STR_LENGTH];
}MMS_CONTENT_TYPE_INF;
typedef MMS_CONTENT_TYPE_INF*	P_MMS_CONTENT_TYPE_INF;

/* inner the content data(head) maybe include these information */
typedef struct TAG_MMS_CONTENT_DRM_INF
{
	CMS_MMS_S8	type[MAX_CONTENT_LENGTH];
	CMS_MMS_S8	id[MAX_NAME_LENGTH];
	CMS_MMS_S8  location[MAX_NAME_LENGTH];
	CMS_MMS_S8	encoding[MAX_NAME_LENGTH];
}MMS_CONTENT_DRM_INF;
typedef MMS_CONTENT_DRM_INF*	P_MMS_CONTENT_DRM_INF;

/* this struct used to parse the content which include drm message */
typedef struct TAG_DRM_ATTR_MAP
{
     CMS_MMS_S8		attr_title[MAX_CONTENT_LENGTH];
	 CMS_MMS_S8		attr_code;
}DRM_ATTR_MAP;

/* the attr's count in the map */
#define ATTR_NUM	4
#define CONTENT_TYPE				 0x01
#define CONTENT_TRANSFER_ENCODING	 0x02
#define CONTENT_LOCATION				0x03
#define CONTENT_ID						0x04

static DRM_ATTR_MAP attr_map[] = 
{
	{"CONTENT-TYPE",CONTENT_TYPE},
	{"CONTENT-TRANSFER-ENCODING",CONTENT_TRANSFER_ENCODING},
	{"CONTENT-LOCATION",CONTENT_LOCATION},
	{"CONTENT-ID",CONTENT_ID}

};  
/*------------------------DRM END---------------------*/

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
	CMS_MMS_S8				m_address[MAX_NAME_LENGTH];
}MMS_RECEPIENT;
typedef MMS_RECEPIENT*	p_MMS_RECEPIENT;


/* struct define: CmsMMSHead
 * define head field of MMS PDU
 */
typedef struct _CmsMMSHead
{
	/* Internal Flags */
	CMS_MMS_S32	flagMultipartRelated;

	/* Header Fields Flags */
    CMS_MMS_S32	flagBccAvailable;
    CMS_MMS_S32	flagCcAvailable;
    CMS_MMS_S32	flagContentTypeAvailable;
    CMS_MMS_S32	flagDateAvailable;
    CMS_MMS_S32	flagDeliveryReportAvailable;
    CMS_MMS_S32	flagDeliveryTimeAvailable;
    CMS_MMS_S32	flagDeliveryTimeAbsolute;
    CMS_MMS_S32	flagExpiryAvailable;
    CMS_MMS_S32	flagExpiryAbsolute;
    CMS_MMS_S32	flagFromAvailable;
    CMS_MMS_S32	flagMessageClassAvailable;
    CMS_MMS_S32	flagMessageIdAvailable;
    CMS_MMS_S32	flagMessageTypeAvailable;
    CMS_MMS_S32	flagMMSVersionAvailable;
    CMS_MMS_S32	flagPriorityAvailable;
    CMS_MMS_S32	flagReadReplyAvailable;
    CMS_MMS_S32	flagSenderVisibilityAvailable;
    CMS_MMS_S32	flagStatusAvailable;
    CMS_MMS_S32	flagSubjectAvailable;
    CMS_MMS_S32	flagToAvailable;
    CMS_MMS_S32	flagTransactionIdAvailable;
	/* hulf add */
    CMS_MMS_S32	flagContentLocationAvailable;
    CMS_MMS_S32	flagReportAllowedAvailable;
    CMS_MMS_S32	flagResponseStatusAvailable;
    CMS_MMS_S32	flagResponseTextAvailable;
    CMS_MMS_S32	flagMessageSizeAvailable;

	/* head flied value */
	
/* 
*	Revised by longqiangl 
*	2003-07-01 
*/
	//CMS_MMS_S8		Mms_bcc[MAX_NAME_LENGTH];/* Address of the recipient. */
	//CMS_MMS_S8		Mms_cc[MAX_NAME_LENGTH];	/* Address of the recipient. */
	p_MMS_RECEPIENT		p_bcc_head;
	p_MMS_RECEPIENT		p_cc_head;	

	CMS_MMS_S8		Mms_content_location[MAX_CONTENTLOCATON_LENGTH];	
									/* This field defines the location of the message. */
	CMS_MMS_S8		Mms_content_type[MAX_CONTENT_LENGTH];		
									/* The content type of the message. */
	CMS_MMS_S32		Mms_date;				/* Arrival time of the message at MMSProxy -Relay. 
										MMS Proxy -Relaywill generate this field when 
										not supplied by terminal. */
	
	CMS_MMS_S32		Mms_delivery_time;		/* default: immediate.
										Time of desired delivery. Indicates the earliest 
										possible delivery of the message to the recipient. 
										The field has two formats, either absolute or 
										CMS_MMS_S32erval. */
	CMS_MMS_S32		Mms_expiry;				/* default: maximum.
										Length of time the message will be stored in MMS
										Proxy-Relayor time to delete the message. The field has
										two formats, either absolute or CMS_MMS_S32erval. */
	CMS_MMS_S8		Mms_from[MAX_NAME_LENGTH];	
									/* Address of the sender. If hiding the address of the sender
										from the recipient is supported, the MMS Proxy -Relay
										will not add this field to a message header. */
	
	CMS_MMS_S8				Mms_message_ID[MAX_MESSAGEID_LENGTH];	
									/* This is an unique reference assigned to message. This ID
										SHALL always be present when the originator client
										requested a read reply.
										The ID enables a client to match read reports with */
									/* Encoded as in email address as per [RFC822]. 
										The characters "<" and ">" are not included. */
	CMS_MMS_U8		Mms_message_class;		/* Class of the message. */
	CMS_MMS_U8		Mms_delivery_report;	/* Default determined when service is ordered.
										Specifies whether the user wants a delivery 
										report from each recipient. When Message-Class 
										is Auto, the field SHALL always be present and 
										the value SHALL be No. */
	CMS_MMS_U8		Mms_message_type;		/* Specifies the message type. */
	CMS_MMS_U8		Mms_mms_version;		/* The MMS version number. According to this
										specification, the version is 1.0. */
									/* The three most significant bits of the Short-CMS_MMS_S32eger are 
										CMS_MMS_S32erpreted to encode a major version number in the range 1-7,
										and the four least significant bits contain a minor version 
										number in the range 0-14. If there is only a major version
										number, this is encoded by placing the value 15 in the four 
										least significant bits [WAPWSP]. */
	CMS_MMS_U64		Mms_message_size;		/* Full size of message in octets. */
	CMS_MMS_U8		Mms_priority;			/* Default: Normal.
												Priority of the message for the recipient. */
	CMS_MMS_U8		Mms_read_reply;			/* Specifies whether the user wants a read report from each
										recipient as a new message. When Message-Class is
										Auto, the field SHALL always be present and the value
										SHALL be No. */
	CMS_MMS_U8		Mms_report_allowed;		/* Default: Yes.
												Sending of delivery report allowed to the user or not. */
	CMS_MMS_U8		Mms_response_status;	/* MMS specific status. */
	CMS_MMS_S8				Mms_response_text[MAX_RESPONSETEXT_LENGTH];
											/* Description which qualifies the response status value. */
	CMS_MMS_S8		Mms_subj[MAX_SUBJECT_LENGTH+12];	
	
									/* Subject of the message. */
/* 
*	Revised by longqiangl 
*	2003-07-01 
*/
	//CMS_MMS_S8		Mms_to[MAX_NAME_LENGTH];	
									/* Address of the recipient. */
	p_MMS_RECEPIENT		p_to_head;	

	
									/* Address of the recipient. */
	CMS_MMS_S8		Mms_transaction_ID[MAX_NAME_LENGTH];
	CMS_MMS_U8		Mms_sender_visibility;	/* Default: show address/phone number of the
										sender to the recipient unless the sender has a secret
										number/address.
										Hide = don't show any address. Show = show even secret
										address. */
	CMS_MMS_U8		Mms_status;				/* Message status. The status Retrieved SHALL be used
											only after successful retrieval of multimedia message. */

									/* This transaction ID identifies the M-Send.conf and the
										corresponding request only. */
	//CENT_FILL_FIELD2
} CmsMMSHead;

/* struct define: MMSContentHead
 * define data block head information in rfc2387 mutipart/related
 */
/*typedef struct _MMSContentHead
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
	CMS_MMS_S32		start;								/* start poCMS_MMS_S32 of this data block */
	CMS_MMS_S32		length;								/* length of this data block */
	CMS_MMS_S8		type[MAX_CONTENT_LENGTH];			/* format type of this block */
	CMS_MMS_S8		id[MAX_NAME_LENGTH+2];					/* id value or filename of this block */
	CMS_MMS_S8		filename[MAX_NAME_LENGTH];			/* file name of this block */
	CMS_MMS_S8		forwardlock;						/*1:drm forwardlocked content; 0: free content */
	CMS_MMS_S8		boundary_str[MAX_BOUNDARY_STR_LENGTH]; /*if this content is forwardlocked(forwardlock=1),there is a boundray string which indicate the tag in the content data  */
	struct _MMSContentList	*firstchild;		/* first child of this data block */
	struct _MMSContentList	*next;				/* next of this data block */
	int char_set;						//2003.9.5
	
}MMSContentList;
	

/* struct define: CmsMMSDocument
 *  CmsMMSDocument describe a mms pdu
 */
typedef struct _CmsMMSDocument
{
	CMS_MMS_S8		mmsfile[MAX_NAME_LENGTH];	/* filename of mm */
	CMS_MMS_S8		mmsstart[MAX_NAME_LENGTH];	/* smil or wml document id(filename) */
	CMS_MMS_S8		mmstype[MAX_NAME_LENGTH];	/* document type */
	MMSContentList  *ccontent;				/* current content in body */
	CmsMMSHead		*mmshead;				/* head of mm */
	MMSContentList  *content;				/* content list in body */
	CMS_MMS_S32     mms_totalsize;			//2003.11.03
}CmsMMSDocument;
typedef CmsMMSDocument *P_MMS_DOCUMENT;

/* struct define: CmsMMSDecoder
 *  CmsMMSDecoder decoder a mms pdu
 */
typedef struct _CmsMMSDecoder
{
	P_MMS_DOCUMENT	md_Message;
	CMS_MMS_S32		md_bMultipartRelated;
	CMS_MMS_S32		md_bMessageAvailable;
	CMS_MMS_S32		md_bHeaderDecoded;
	CMS_MMS_S8		m_In[FILE_BLOCK_LENGTH];
	CMS_MMS_FILE	fp;
	CMS_MMS_S32		m_i;
	CMS_MMS_S32		m_long;
	CMS_MMS_S32		m_base;
	CMS_MMS_S32		state;
}CmsMMSDecoder;
typedef CmsMMSDecoder *P_MMS_DECODER;

/* struct define: CmsMMSEncoder
 *  CmsMMSEncoder encoder a mms pdu
 */
typedef struct _CmsMMSEncoder
{
	P_MMS_DOCUMENT	m_Message;
	CMS_MMS_S32		me_bMultipartRelated;
	CMS_MMS_S32		me_bMessageAvailable;
	CMS_MMS_S32		me_bMessageEncoded;
	CMS_MMS_FILE	m_Out;
}CmsMMSEncoder;
typedef CmsMMSEncoder *P_MMS_ENCODER;

CMS_MMS_S32 cms_mms_encode(P_MMS_DOCUMENT mmsdocument);
CMS_MMS_S32 cms_mms_decode(P_MMS_DOCUMENT mmsdocument);

/* inner function define */
/* decoder */
CMS_MMS_U8 decodeByte(CMS_MMS_U8 value); 
CMS_MMS_S32 unsignedByte(CMS_MMS_S8 value); 
CMS_MMS_S32 readMultipleByteInt(P_MMS_DECODER pmmsdecoder, CMS_MMS_S32 length); 
CMS_MMS_S32	readTextString(P_MMS_DECODER pmmsdecoder, CMS_MMS_S8	*text, CMS_MMS_S32 length); 
CMS_MMS_S32 readUintvar(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_S32 readValueLength(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID    readWellKnownMedia(P_MMS_DECODER pmmsdecoder, CMS_MMS_S8 fvalue[128]); 
CMS_MMS_S32	    readContentTypeValue(
							P_MMS_DECODER pmmsdecoder,\
							P_MMS_CONTENT_TYPE_INF p_content_inf 
							); 
CMS_MMS_VOID    readHeadContentTypeValue(P_MMS_DECODER pmmsdecoder, CMS_MMS_S8 value[128]); 
CMS_MMS_U8 getaddresstype(CMS_MMS_S8 *value); 
CMS_MMS_VOID readMMBodyMultiPartRelated(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID readMMBodyMultiPartMixed(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID readMMBodyMultiPartMixed(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID readMMHeader(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID decodeHeader(P_MMS_DECODER pmmsdecoder); 
CMS_MMS_VOID decodeBody(P_MMS_DECODER pmmsdecoder); 

/* encoder */
CMS_MMS_S32	EncodeMultiByteNumber(CMS_MMS_S32 ldate, CMS_MMS_U8 date[16]); 
CMS_MMS_S32 EncodeUintvarNumber(CMS_MMS_S8 data[16], CMS_MMS_S32 lData); 
CMS_MMS_U8 encodeContentType(CMS_MMS_S8 *ContentType); 
CMS_MMS_VOID writeUintvar(P_MMS_ENCODER pmmsencoder, CMS_MMS_S32 value); 
CMS_MMS_VOID writeValueLength(P_MMS_ENCODER pmmsencoder, CMS_MMS_S32 value); 
CMS_MMS_S32 getNumContents(P_MMS_ENCODER pmmsencoder);
CMS_MMS_S32	getcontentlength(MMSContentList *list); 
CMS_MMS_VOID encodeContent(P_MMS_ENCODER pmmsencoder, MMSContentList *list);
CMS_MMS_S32 Encodelist(P_MMS_ENCODER pmmsencoder, MMSContentList *list); 
CMS_MMS_VOID mmsencodehead(P_MMS_ENCODER pmmsencoder); 
CMS_MMS_S32 mmsencodebody(P_MMS_ENCODER pmmsencoder); 

#endif /* _MMSCORE_H_ */
