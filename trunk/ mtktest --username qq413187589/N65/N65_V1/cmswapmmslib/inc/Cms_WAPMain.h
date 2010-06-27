/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: WAP STACK Ver 1.20
 
 File Name   : Cms_WAPMain.h

 Description : To Implement Browser application

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology

******************************************************************************/

#ifndef _CMS_WAPMAIN_H
#define _CMS_WAPMAIN_H

#include "cms_basedef.h"
#include "Cms_callback.h"//  Modified by TIPrj[2005/7/14]  
/*================================================*/

typedef enum
{
	WAP_NONE = 0,
	WAP_CONNECT,                 //连接wap网关成功
	WAP_DISCONNECT,              //与wap网关断开


	WAP_CONTINUE = 0x10,
	WAP_SWITCHING_PROTOCOLS = 0x11,
	WAP_DATA,                    //wsp 20，并且userdata 正确
	WAP_NO_DATA,                 //wsp 20 ,可是userdata没有
	WAP_CREATE = 0x21,
	WAP_ACCEPTED = 0x22,
	WAP_NON_AUTHORITATIVE_INFORMATION = 0x23,
	WAP_NO_CONTENT = 0x24,
	WAP_RESET_CONTENT = 0x25,
	WAP_PARTIAL_CONTENT = 0x26,
	WAP_MULTIPLE_CHOICES = 0x30,
	WAP_MOVED_PERMANENTLY = 0x31,
	WAP_MOVED_TEMPORARILY = 0x32,
	WAP_SEE_OTHER = 0x33,
	WAP_NOT_MODIFIED = 0x34,
	WAP_USE_PROXY = 0x35,
	WAP_RESERVED = 0x36,
	WAP_TEMPORARY_REDIRECT = 0x37,
	WAP_BAD_REQUEST = 0x40,
	WAP_UNAUTHORIZED = 0x41,
	WAP_PAYMENT_REQUIRED = 0x42,
	WAP_FORBIDDEN = 0x43,
	WAP_NOT_FOUND = 0x44,
	WAP_METHOD_NOT_ALLOWED = 0x45,
	WAP_NOT_ACCEPTABLE = 0x46,
	WAP_PROXY_AUTHENTICATION_REQUIRED = 0x47,
	WAP_REQUEST_TIMEOUT = 0x48,
	WAP_CONFLICT = 0x49,
	WAP_GONE = 0x4a,
	WAP_LENGTH_REQUIRED = 0x4b,
	WAP_PRECONDITION_FAILED = 0x4c,
	WAP_REQUEST_ENTITY_TOO_LARGE = 0x4d,
	WAP_REQUEST_URI_TOO_LARGE = 0x4e,
	WAP_UNSUPPORTED_MEDIA_TYPE = 0x4f,
	WAP_REQUESTED_RANGE_NOT_SATISFIABLE = 0x50,
	WAP_EXPECTATION_FAILED = 0x51,
	WAP_INTERNAL_SERVER_ERROR = 0x60,
	WAP_NOT_IMPLEMENTED = 0x61,
	WAP_BAD_GATEWAY = 0x62,
	WAP_SERVICE_UNAVAILABLE = 0x63,
	WAP_GATEWAY_TIMEOUT = 0x64,
	WAP_HTTP_VERSION_NOT_SUPPORTED = 0x65,


	WAP_TIMEOUT,        //暂未使用
	WAP_OBJ_MOVED,      //add by roger
	WAP_ERROR_DATA,    //当网关放弃时，或者收到错误的数据时
	WAP_USERABORT    //当用户放弃操作时
}WAP_STATUS;

typedef enum
{
	LIB_STATUS_SENDRETURN,                  //发送完毕
		LIB_STATUS_RECVRETURN,                 //接收完毕
		LIB_STATUS_NORMAL_STATUS,               //正常状态,反映库的活动情况如正在发送，正在接收等
		LIB_STATUS_TOTAL_BYTES,
		LIB_STATUS_SENDED_BYTES,
		LIB_STATUS_RECVED_BYTES
}MMS_LIBSTATUS;  
//  Modified by TIPrj[2005/6/29]  

/*================================================*/

typedef void (*wapproc)(int msg,char *data,int len);

void    Cms_BRW_WAPOpen(unsigned char * host, long port, wapproc proc);
void 	Cms_WAPOpen(unsigned char * host, long port, wapproc proc);//for mms
void 	Cms_WAPClose(void);
void 	Cms_WAPGetURL(unsigned char * url);
void 	Cms_WAPPostURL(unsigned char * url, unsigned char * param, unsigned int paramLen, FILE_HANDLE file);
void 	Cms_BRW_WAPPostURL(unsigned char * url, unsigned char * param, unsigned int paramLen, FILE_HANDLE file);
void    Cms_WAPDisconnect(void);
void    Cms_OTA_WAPOpen(unsigned char * host, long port, unsigned char * capability,int capability_len,unsigned char * head,int head_len,wapproc proc);
void    Cms_OTA_SetMaxRecvSize(int size);


void    Cms_WAPInit(int target);
void  	Cms_WAPDone(void );
void  	Cms_WAPConnect(void );
void  	Cms_WAPGet(unsigned char * url);
void  	Cms_WAPPost(unsigned char * url, unsigned char * param, unsigned int paramLen);
void  	Cms_WAPSendUDP(unsigned char * buf, int len);
unsigned char 	Cms_UDPInput(void );/*--Shawn 2003-01-02*/

void CmsWtpUserAbort( void );
void CmsWspDisconnect( void );
void CmsWtpSetTimer( void );
void CmsWtpSetMsgSize( unsigned int size );
int  CmsIsWspConnected( void );

#endif
