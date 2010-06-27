/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: mini_Browser Ver3.20
 
 File Name   : CmsNetMessage.h

 Description : Network Marco

 Last Modify : 02/18/2003
 
 Written By  : HaiYong Le


*****************************************************************/

#ifndef CMSNETMESSAGE_H
#define CMSNETMESSAGE_H

/****************************************************************/

#include "CmsBrowserPublic.h"

/****************************************************************/

typedef struct netParam
{
#ifdef SUPPORT_WAPSTACK
	CMS_BROWSER_SOCKET 		s;							/*=== 网页套接字 ===*/
	CMS_BROWSER_SOCKET 		imgs;						/*=== 图片套接字 ===*/
	CMS_BROWSER_SOCKADDRIN  hostadd;					/*=== 主机地址信息结构 ===*/
#endif
	
	CMS_BROWSER_S32			type;						/*=== TCP or UDP ===*/
	CMS_BROWSER_S32			af_net;						/*=== AF_NET ===*/
	CMS_BROWSER_S32			protocol;					/*=== 保留 ===*/
	P_CMS_BROWSER_U8		buf;						/*=== (发送、接收)缓冲区指针 ===*/
	CMS_BROWSER_S32			dataLen;					/*=== (发送、接收)缓冲区有效的数据长度 ===*/
	CMS_BROWSER_S32			recvLen;					/*=== 接收缓冲区的长度 ===*/
	CMS_BROWSER_S32			flags;						/*=== 标记(保留) ===*/			/*=== 标记(保留) ===*/
	CMS_BROWSER_BOOL		Method;						/*=== CMS_BROWSER_FALSE: GET     CMS_BROWSER_TRUE: POST ===*/
	P_CMS_BROWSER_U8		PostParam;		
	CMS_BROWSER_S32			TCPIPStatus;				/*=== 浏览器发往TCP/IP的状态 ===*/

	CMS_BROWSER_U8			url[512];				/*=== 要浏览的网页URI ===*/
	
}CMS_NETPARAM;


typedef enum
{	
/*============  浏览器发往TCP/IP/PPP的状态 ============*/

		CMS_BROWSER_DIAL_FUN,			/*=== 0: 要求拨号(状态机复位，拨号初始化，拨号，建链) ===*/
		CMS_BROWSER_CLOSE_NET,			/*=== 1: 要求挂断(交还拨号初始化占用的资源) ===*/
		CMS_BROWSER_CLOSE_SOCKET,		/*=== 2: 要求关闭套接字 ===*/
		CMS_BROWSER_TCP_GETHOST_FUN,	/*=== 3: 要求TCP连接初始化 (包括创建TCP套接字、gethostbyname操作) ===*/
		CMS_BROWSER_TCP_CONNECT_FUN,	/*=== 4: 要求TCP连接 (包括connect以及send操作) ===*/
		CMS_BROWSER_UDP_CONNECT_FUN,	/*=== 5: 要求UDP连接 (包括创建UDP套接字) ===*/
		CMS_BROWSER_RECV_FUN,			/*=== 6: 要求接收数据(TCP) ===*/
		CMS_BROWSER_SENDTO_FUN,			/*=== 7: 要求发送数据(UDP) ===*/	
		CMS_BROWSER_RECVFROM_FUN		/*=== 8: 要求接收数据(UDP) ===*/	

}CMS_BROWSER_TCPIP_STATUS;


#endif
