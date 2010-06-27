/*================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: WHTTP2Socket.h

功能描述		: 提供socket函数，当移入PS时需要修改socket接口函数

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _WHTTP2SOCKET_H
#define _WHTTP2SOCKET_H

#ifdef __cplusplus
extern "C" {
#endif

extern int	Cms_InitSocket(void);
extern int	Cms_gethostbyname(char *url);
extern int	Cms_gethostip(void);
extern int	Cms_Connect(void);
extern int	Cms_Send(const unsigned char *rePdu,int dataLen);
extern int	Cms_Receive(void);
extern void Cms_CloseSocket(void);
extern int	gethostip(int RequestId,char *IPaddress);

#define INVALIDE_SOCKET	-1
#define SOCKETRECDATABUFLEN 3072//1999   //changed by yangjun 05-10-8
#define DNR_ERROR 7
#define DNR_NEEDNOT 8

/* ------ shutdown flags. ------- */
#define BSD_SD_RECEIVE      0x00
#define BSD_SD_SEND         0x01
#define BSD_SD_BOTH         0x02
/*打开MODENTCPROAD宏可以走GPRS模块走，否则走以太网*/
#ifdef WIN32
//#define MODENTCPROAD
#endif

#define _BSD_BASEERR				200
#define BSD_EWOULDBLOCK				(_BSD_BASEERR+1)
#define BSD_EINPROGRESS				(_BSD_BASEERR+2)
#define BSD_ENOTSOCK				(_BSD_BASEERR+3)
#define BSD_EMSGSIZE				(_BSD_BASEERR+4)
#define BSD_EPROTONOSUPPORT			(_BSD_BASEERR+5)
#define BSD_EOPNOTSUPP				(_BSD_BASEERR+6)
#define BSD_EAFNOSUPPORT			(_BSD_BASEERR+7)
#define BSD_EADDRNOTAVAIL			(_BSD_BASEERR+8)
#define BSD_EADDRINUSE				(_BSD_BASEERR+9)
#define BSD_ENETDOWN				(_BSD_BASEERR+10)
#define BSD_ECONNABORTED			(_BSD_BASEERR+11)
#define BSD_ECONNRESET				(_BSD_BASEERR+12)
#define BSD_ENOBUFS					(_BSD_BASEERR+13)
#define BSD_EISCONN					(_BSD_BASEERR+14)
#define BSD_ENOTCONN				(_BSD_BASEERR+15)
#define BSD_ETIMEDOUT				(_BSD_BASEERR+16)
#define BSD_ECONNREFUSED			(_BSD_BASEERR+17)
#define BSD_EHOSTUNREACH			(_BSD_BASEERR+18)
#define BSD_EINVAL					(_BSD_BASEERR+19)
#define BSD_EINTR					(_BSD_BASEERR+20)
#define BSD_ENOMEM					(_BSD_BASEERR+21)
#define BSD_ENOTRECORDED			(_BSD_BASEERR+22)
#define BSD_EALREADY				(_BSD_BASEERR+23)
#define BSD_ESOCKTNOSUPPORT			(_BSD_BASEERR+24)
#define BSD_ENOTBOUND				(_BSD_BASEERR+25)
/* New error types to advertise application from uplink 
   flow control due to mechanism of windows in TCP */
#define BSD_ESNDWNDCLOSED			(_BSD_BASEERR+26)
#define BSD_ESNDWNDFULL				(_BSD_BASEERR+27)

/* BSD not used */
#define BSD_EPROTOTYPE				(_BSD_BASEERR+30)
#define BSD_ENOTEMPTY				(_BSD_BASEERR+31)
#define BSD_EPROCLIM				(_BSD_BASEERR+32)
#define BSD_EUSERS					(_BSD_BASEERR+33)
#define BSD_EDQUOT					(_BSD_BASEERR+34)
#define BSD_ESTALE					(_BSD_BASEERR+35)
#define BSD_EREMOTE					(_BSD_BASEERR+36)
#define BSD_EDESTADDRREQ			(_BSD_BASEERR+37)
#define BSD_EPFNOSUPPORT			(_BSD_BASEERR+38)
#define BSD_EFAULT					(_BSD_BASEERR+39)
#define BSD_ENETUNREACH				(_BSD_BASEERR+40)
#define BSD_ENETRESET				(_BSD_BASEERR+41)
#define BSD_ESHUTDOWN				(_BSD_BASEERR+42)
#define BSD_ETOOMANYREFS			(_BSD_BASEERR+43)
#define BSD_ELOOP					(_BSD_BASEERR+44)
#define BSD_ENAMETOOLONG			(_BSD_BASEERR+45)
#define BSD_EHOSTDOWN				(_BSD_BASEERR+46)
#define BSD_ENOPROTOOPT				(_BSD_BASEERR+47)
#define BSD_EBADF					(_BSD_BASEERR+49)
#define BSD_EACCES					(_BSD_BASEERR+50)
#define BSD_EMFILE					(_BSD_BASEERR+51)

#define _BSD_NOTIMPL				(_BSD_BASEERR+99)

#define BSD_IPPROTO_TCP		6
#define BSD_SOL_SOCKET      0xffff          /* options for socket level */
#define BSD_SO_LINGER       0x0080          /* linger on close if data present */
#define BSD_SO_SNDBUF       0x1001          /* send buffer size */


/*========(3)===============*/
#ifndef _D_NET
/*=========(3)==============*/

typedef int SOCKET;
#define PORT_NUM		80
#define AF_INET			1
#define SOCK_STREAM		1         /* stream socket */
#define SOCK_DGRAM		2         /* datagram socket */
#define SOCK_RAW		3	     /* raw-protocol interface */
#define IPPROTO_TCP		(6)
#define SOCKET_ERROR	-1
#define INVALID_SOCKET	(SOCKET) -1



/*************************************************************************
	 函数声明
 ************************************************************************/
SOCKET socket(int af, int type, int protocol);
int  cmsgethostbyname(char * url); 
int gethostip(int RequestId,char *IPaddress);
int  closesocket(SOCKET s);
int  connect(SOCKET s,char * ipaddress,int port);
int  send(SOCKET s,const char * buf, int len);	
int  recv(SOCKET s,char * buf, int len,int flag);
	   
#endif

int getlasterror(void);	


#ifdef __cplusplus
};
#endif

#endif