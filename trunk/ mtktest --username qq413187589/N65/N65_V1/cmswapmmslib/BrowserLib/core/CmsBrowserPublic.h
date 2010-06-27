/*==============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

==============================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBrowserPublic.c

功能描述		: 外部公用数据结构以及宏定义

最近修改时间	: 10/17/2003
 
代码编写人员	: 乐海勇

==============================================================*/

#ifndef CMSBROWSERPUBLIC_H
#define CMSBROWSERPUBLIC_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "CmsDisplay.h"
#include "CmsBrowserReturn.h"



//  Modified by TIPrj[2005/6/29]

#ifndef MC_PCC_FILL_STRUCT1
#define MC_PCC_FILL_STRUCT1 unsigned:0; unsigned:8; unsigned:0;
#endif

#ifndef MC_PCC_FILL_STRUCT2
#define MC_PCC_FILL_STRUCT2 unsigned:0; unsigned:8; unsigned:8; unsigned:0;
#endif

#ifndef MC_PCC_FILL_STRUCT3
#define MC_PCC_FILL_STRUCT3 unsigned:0; unsigned:8; unsigned:8; unsigned:8; unsigned:0;
#endif

#define CMS_NOTOUCHPANNEL		/*=== 对于类似手机一类没有触摸屏的目标设备，采用LINK_FOCUS的机制 ===*/


/*
 *Relativly ,the show softkey interface is defined bellow.
 *CMS_BROWSER_VOID Cms_DisplaySoftKey(P_CMS_BROWSER_U8 pls, P_CMS_BROWSER_U8 Rls);
 */	 
typedef enum _CMS_BROWSER_STR_RESOURCE
{
	CMS_STR_RESOURCE_EMPTY, //NULL String
	CMS_STR_RESOURCE_BACK,	//"Back"||"返回"
	CMS_STR_RESOURCE_RETRY,	//"Retry"||"重试"
	CMS_STR_RESOURCE_LINK,	//"Link"||"链接"
	CMS_STR_RESOURCE_EDIT,	//"Edit"||"编辑"
	CMS_STR_RESOURCE_SELECT,//"Select"||"选择"
	CMS_STR_RESOURCE_CANCLE,//"Cancle"||"取消"
	CMS_STR_RESOURCE_OK,	//"OK"||"确定"
	CMS_STR_RESOURCE_EXIT,   //"EXIT"||"退出"
	/* 添加各种提示信息字符串 */
	CMS_STR_NO_SERVER,			//"No server"
	CMS_STR_NO_SUCH_SERVER,		//"No such server"
	CMS_STR_DIALING_FAILED,		//"Dialing failed"
	CMS_STR_CONNECTION_DISC,    //"Connection disconnected"
	CMS_STR_DIALING_CON_DISC,   //"Dialing connection is disconnected"
	CMS_STR_DOWN_RING_FAIL,     //"Download ring failed"
	CMS_STR_DATA_ERROR,             //"Data error"
	CMS_STR_SERVER_REJECT,          //"Server reject"
	CMS_STR_INVALID_ADDRESS,        //"Invalid address"
	CMS_STR_INVALID_URL,            //"Invalid url"
	CMS_STR_ERROR_PAGE,             //"Error page"
	CMS_STR_ERROR_PAGE_TRY,         //"Error page,please try later"
	
	CMS_STR_GETWAY_ERROR,           //"Gateway error"
	CMS_STR_GETWAY_NO_RES,          //"Gateway not response"
	CMS_STR_SERVER_ERROR,           //"Server error"
	CMS_STR_TIME_OUT,               //"Time out"
	CMS_STR_RES_TIME_OUT,           //"The server's response time out"
	CMS_STR_UNSUPPORT_FILE,         //"not support file"
	CMS_STR_UNSUPPORT_SORRY,        //"Sorry! Not support such file type%s%s"

	CMS_STR_SUBMIT,                 //"submit"
	CMS_STR_BUTTON,                 //"button"
	CMS_STR_RESET,                  //"reset"

	CMS_STR_SUBJECT,                //"Subject :"
	CMS_STR_ISSURER,                //"Issuer :"
	CMS_STR_VALID_NOTBEFORE,        //"Valid not before :"
	CMS_STR_VALID_NOTAFTER,         //"Valid not after :"
	CMS_STR_MD_ALGORITHMS,          //"MD algorithms : sha1\nDigest value :"
	CMS_STR_SIGN_ALGO,              //"Signature algorithms :"
	CMS_STR_SIGNATURE,              //"Signature :\n"

	CMS_STR_VALID_CERT,             //"valid security certificate"
	CMS_STR_INVALID_CERT,           //"invalid security certificate or unsupported certificate type"
	CMS_STR_UNTRUST_CERT,           //"this certificate cannot be verified up to a trusted certificateion authority"
	CMS_STR_REVOKED_CERT,           //"security certificate revoked"
	CMS_STR_EXPIER_CERT,            //"security certificate expired or not valid yet"
	CMS_STR_ERPURPOSE_CERT,         //"invalid security certificate purpose"
	CMS_STR_UNMACTH_CERT,           //"The name on the security certificate is invalid or does not match the name of the site"
	
	CMS_STR_UNKNOWN_ERROR,          //"unknown error"
	CMS_STR_CERT_WARNING_PROBLEM,   //"information you exchange with this site cannot be viewed or changed by others , however , there is a problem with the site's security certificate"
	
	CMS_STR_ENCRYPT_METHOD,         //"%s with %d bits encryption( High ) , RSA with %d bits exchange"
	CMS_STR_CERT_INFO,              //"security certificate info"
	
	CMS_STR_MALLOC_FAILED,          //"system malloc failed,exit please!"
	CMS_STR_NET_EXCEPTION,          //"Net exception, please exit browser"

	CMS_STR_BIG_FILE,               //"Big file"
	CMS_STR_BIG_FILE_TO_DOWN,       //"File is too big to download"

	CMS_STR_CON_SECURED,			//"Connection Secured"
	CMS_STR_CON_TO_SERVICE,			//"Connecting to service"
	CMS_STR_SECURED_CA,				//"Connecting in security to server,whether continue?"
									
	CMS_STR_DOWNLOADING_IMAGE,      //"Downloading(%d/%d)"
	CMS_STR_DOWNLOADIMG_OK			//"Download Finished"	
}CMS_BROWSER_STR_RESOURCE;

/*===============browser and GIF Timer ID definition====*/


/*=================== Message Macros ===================*/

#ifndef CMS_LINUX
#define CMS_MESSAGE_START_ID				0x0500		/*=== 浏览器消息号起始值 ===*/
#else
#define CMS_MESSAGE_START_ID				0	/*=== 浏览器消息号起始值 ===*/
#endif

#define CMS_MESSAGE_BROWSERINIT				CMS_MESSAGE_START_ID		/*=== 浏览器初始化消息 ===*/
#define	CMS_MESSAGE_BROWSEREXIT				(CMS_MESSAGE_START_ID+1)	/*=== 退出浏览器消息 ===*/
#define CMS_MESSAGE_BROWSERNEWURI			(CMS_MESSAGE_START_ID+2)	/*=== 新建网络连接消息 ===*/
#define CMS_MESSAGE_BROWSERLOCAL			(CMS_MESSAGE_START_ID+3)	/*=== 浏览本地文件消息 ===*/
#define CMS_MESSAGE_BROWSERSETHOMEPAGE		(CMS_MESSAGE_START_ID+4)	/*=== 设置主页消息 ===*/
#define CMS_MESSAGE_BROWSERLINKHOMEPAGE		(CMS_MESSAGE_START_ID+5)	/*=== 浏览主页消息 ===*/
#define	CMS_MESSAGE_BROWSERSAVEASLOCAL		(CMS_MESSAGE_START_ID+6)	/*=== 另存为本地文件消息 ===*/
#define	CMS_MESSAGE_BROWSERUPPAGE			(CMS_MESSAGE_START_ID+7)	/*=== 上翻一页消息 ===*/
#define CMS_MESSAGE_BROWSERDOWNPAGE			(CMS_MESSAGE_START_ID+8)	/*=== 下翻一页消息 ===*/
#define CMS_MESSAGE_BROWSERPENDOWN			(CMS_MESSAGE_START_ID+9)	/*=== 用户点击消息 ===*/
#define	CMS_MESSAGE_BROWSERPREVPAGE			(CMS_MESSAGE_START_ID+10)	/*=== 后退消息 ===*/
#define CMS_MESSAGE_BROWSERNEXTPAGE			(CMS_MESSAGE_START_ID+11)	/*=== 前进消息 ===*/
#define CMS_MESSAGE_BROWSERREFRESHPAGE		(CMS_MESSAGE_START_ID+12)	/*=== 刷新消息 ===*/
#define CMS_MESSAGE_BROWSERSTOPPAGE			(CMS_MESSAGE_START_ID+13)	/*=== 停止消息 ===*/
#define CMS_MESSAGE_BROWSERPARSER			(CMS_MESSAGE_START_ID+14)	/*=== 解析消息 ===*/
#define CMS_MESSAGE_BROWSERLAYOUT			(CMS_MESSAGE_START_ID+15)	/*=== 排版消息 ===*/
#define CMS_MESSAGE_BROWSERDRAW				(CMS_MESSAGE_START_ID+16)	/*=== 显示消息 ===*/
#define CMS_MESSAGE_BROWSEREDITBOX			(CMS_MESSAGE_START_ID+17)	/*=== 编辑框消息 ===*/
#define CMS_MESSAGE_BROWSEROPENNET			(CMS_MESSAGE_START_ID+18)	/*=== 建立网络连接消息 ===*/
#define CMS_MESSAGE_BROWSEROPENNETSUCCESS	(CMS_MESSAGE_START_ID+19)	/*=== 建立网络连接成功消息 ===*/
#define CMS_MESSAGE_BROWSEROPENNETFAILED	(CMS_MESSAGE_START_ID+20)	/*=== 建立网络连接失败消息 ===*/
#define CMS_MESSAGE_BROWSERCLOSENET			(CMS_MESSAGE_START_ID+21)	/*=== 关闭网络连接消息 ===*/
#define CMS_MESSAGE_BROWSERCREATETCPSOCKET	(CMS_MESSAGE_START_ID+22)	/*=== 创建TCP套接字消息 ===*/
#define CMS_MESSAGE_BROWSERCLOSETCPSOCKET	(CMS_MESSAGE_START_ID+23)	/*=== 关闭TCP套接字消息 ===*/
#define CMS_MESSAGE_BROWSERCREATEUDPSOCKET	(CMS_MESSAGE_START_ID+24)	/*=== 创建UDP套接字消息 ===*/
#define CMS_MESSAGE_BROWSERCLOSEUDPSOCKET	(CMS_MESSAGE_START_ID+25)	/*=== 关闭UDP套接字消息 ===*/
#define CMS_MESSAGE_BROWSERGETHOST			(CMS_MESSAGE_START_ID+26)	/*=== 域名解析消息 ===*/
#define CMS_MESSAGE_BROWSERGETHOSTSUCCESS	(CMS_MESSAGE_START_ID+27)	/*=== 域名解析成功消息 ===*/
#define CMS_MESSAGE_BROWSERGETHOSTFAILED	(CMS_MESSAGE_START_ID+28)	/*=== 域名解析失败消息 ===*/
#define CMS_MESSAGE_BROWSERTCPCONNECT		(CMS_MESSAGE_START_ID+29)	/*=== 连接SERVER消息 ===*/
#define CMS_MESSAGE_BROWSERTCPCONNSUCCESS	(CMS_MESSAGE_START_ID+30)	/*=== 连接SERVER成功消息 ===*/
#define CMS_MESSAGE_BROWSERTCPCONNFAILED	(CMS_MESSAGE_START_ID+31)	/*=== 连接SERVER失败消息 ===*/
#define CMS_MESSAGE_BROWSERTCPSEND			(CMS_MESSAGE_START_ID+32)	/*=== TCP发送数据消息 ===*/
#define CMS_MESSAGE_BROWSERTCPRECV			(CMS_MESSAGE_START_ID+33)	/*=== TCP接收数据消息 ===*/
#define CMS_MESSAGE_BROWSERTCPRECVSUCCESS	(CMS_MESSAGE_START_ID+34)	/*=== TCP接收数据成功消息 ===*/
#define CMS_MESSAGE_BROWSERTCPRECVFAILED	(CMS_MESSAGE_START_ID+35)	/*=== TCP接收数据失败消息 ===*/
#define CMS_MESSAGE_BROWSERUDPSENDTO		(CMS_MESSAGE_START_ID+36)	/*=== UDP发送数据消息 ===*/
#define CMS_MESSAGE_BROWSERUDPRECVFROM		(CMS_MESSAGE_START_ID+37)	/*=== UDP接收数据消息 ===*/
#define CMS_MESSAGE_BROWSERRECVFROMSUCCESS	(CMS_MESSAGE_START_ID+38)	/*=== UDP接收数据成功消息 ===*/
#define CMS_MESSAGE_BROWSERRECVFROMFAILED	(CMS_MESSAGE_START_ID+39)	/*=== UDP接收数据失败消息 ===*/
#define CMS_MESSAGE_BROWSERNETWORKERROR		(CMS_MESSAGE_START_ID+40)	/*=== 网络错误消息 ===*/
#define CMS_MESSAGE_BROWSERMAILADDRESS		(CMS_MESSAGE_START_ID+41)	/*=== Email调用 ===*/
#define CMS_MESSAGE_BROWSERCALLREQUEST		(CMS_MESSAGE_START_ID+42)	/*=== 电话接口消息 ===*/
#define CMS_MESSAGE_BROWSERSTOREPHONENUM	(CMS_MESSAGE_START_ID+43)	/*=== 电话调用+存入电话本 ===*/
#define CMS_MESSAGE_BROWSERJAVADOWNLOAD		(CMS_MESSAGE_START_ID+44)	/*=== JAR下载消息 ===*/

#define CMS_MESSAGE_BROWSERLOCALPAGESAVE	(CMS_MESSAGE_START_ID+45)	/*=== 保存本地页面消息 ===*/
#define CMS_MESSAGE_BROWSERLOCALPAGELOAD	(CMS_MESSAGE_START_ID+46)	/*=== 装载本地页面消息 ===*/
#define CMS_MESSAGE_BROWSERSAVEITEM			(CMS_MESSAGE_START_ID+47)	/*=== 保存item消息 ===*/

#define CMS_MESSAGE_BROWSERSOCCLOSESUCCESS		(CMS_MESSAGE_START_ID+50)	/*=== socket close success消息 ===*/
#define CMS_MESSAGE_BROWSERSOCCLOSEFAIL			(CMS_MESSAGE_START_ID+51)	/*=== socket close fail消息 ===*/
#define WAP_DATA_RECVED	                 				(CMS_MESSAGE_START_ID + 100)/*wap 协议栈是数据传上来*/
#define CMS_MESSAGE_BROWSERPAGEDOWN 			(CMS_MESSAGE_START_ID + 101)
#define CMS_MESSAGE_BROWSERPAGEUP 				(CMS_MESSAGE_START_ID + 102)
#define CMS_MESSAGE_BROWSERTOUCHPENDOWN 		(CMS_MESSAGE_START_ID + 103)
#define CMS_MESSAGE_BROWSERTOUCHPENUP 			(CMS_MESSAGE_START_ID + 104)
#define CMS_MESSAGE_BROWSERDEVDEACTIVEATE		(CMS_MESSAGE_START_ID + 105)


/************************************************************************/
/* 区分相同的网络事件的不同来源                                         */
/************************************************************************/
#define	CMS_NEWURL_FROM_PAGE			0x80000000	/* 表示新的url页面请求    */
#define CMS_NEWURL_FROM_PAGE_IMG		0x40000000	/* 表示页面内下载图片的url*/

#define TEST_DOWNLOAD

/*=================== Basic Data types ===================*/

typedef unsigned char		CMS_BROWSER_U8;			/*=== unsigned 8 bit data  ===*/
typedef unsigned short		CMS_BROWSER_U16;		/*=== unsigned 16 bit data ===*/
typedef unsigned int		CMS_BROWSER_U32;		/*=== unsigned 32 bit data ===*/
typedef unsigned long		CMS_BROWSER_U64;		/*=== unsigned 64 bit data ===*/
typedef char			    CMS_BROWSER_S8;			/*=== signed 8 bit data  ===*/
typedef short	        	CMS_BROWSER_S16;		/*=== signed 16 bit data ===*/
typedef int		        	CMS_BROWSER_S32;		/*=== signed 32 bit data ===*/
typedef long	    		CMS_BROWSER_S64;		/*=== signed 64 bit data ===*/

#if 0	/* declaring a void parameter list with a typedef is nonstandard. */
typedef void				CMS_BROWSER_VOID;		/*=== void ===*/
#else
#define CMS_BROWSER_VOID	void
#endif

typedef CMS_BROWSER_U8 *	P_CMS_BROWSER_U8;
typedef CMS_BROWSER_U16 *	P_CMS_BROWSER_U16; 
typedef CMS_BROWSER_U32 *	P_CMS_BROWSER_U32;
typedef CMS_BROWSER_U64 *	P_CMS_BROWSER_U64;  
typedef CMS_BROWSER_S8 *	P_CMS_BROWSER_S8;
typedef CMS_BROWSER_S16 *	P_CMS_BROWSER_S16;  
typedef CMS_BROWSER_S32 *	P_CMS_BROWSER_S32; 
typedef CMS_BROWSER_S64 *	P_CMS_BROWSER_S64;
typedef CMS_BROWSER_VOID *	P_CMS_BROWSER_VOID;

typedef int CMS_BROWSER_BOOL;
#define CMS_BROWSER_FALSE 0
#define CMS_BROWSER_TRUE 1

typedef enum _CMS_BROWSER_LANGUAGE
{
	CMS_CHINESE,	
	CMS_ENGLISH	
}CMS_BROWSER_GUI_LANGUAGE;

/*=================== Special Data types ===================*/

typedef	int				CMS_BROWSER_FILEHANDLE;	/*=== 文件句柄 ===  */

typedef CMS_BROWSER_S32 CMS_BROWSER_OS_TIMER;

#define CMS_BROWSER_INVALIDTIMER	8				/*=== 无效定时器 ===*/
#define CMS_BROWSER_INVALIDTIMERID	8				/*=== 无效定时器ID号 ===*/


typedef enum _CMS_FILE_OPENMODE
{
	CMS_FILE_READONLY = 0,	
	CMS_FILE_WRITEONLY,
	CMS_FILE_APPEND

}CMS_FILE_OPENMODE;
#ifndef CMS_SEEK_SET
#define CMS_SEEK_SET		0		/*=== 文件起始位置标记 ===*/
#endif
#ifndef CMS_SEEK_CUR
#define CMS_SEEK_CUR		1		/*=== 文件当前位置标记 ===*/
#endif
#ifndef CMS_SEEK_END
#define CMS_SEEK_END		2		/*=== 文件结尾位置标记 === revised by shawn 2004.03.14*/
#endif
#ifndef CMS_EOF
#define	CMS_EOF				EOF		/*=== 读到文件结尾时的返回值 ===*/
#endif



#define	CMS_BROWSER_INVALID_FILEHANDLE	0		/*=== 无效文件句柄 ===*/
#define CMS_BROWSER_INVALID_SOCKET	((CMS_BROWSER_SOCKET)(~0))	/*=== 无效套接字号 ===*/

#define CMS_MAX_PUSH   20		/*=== 最大未处理PUSH消息数 ===*/
#define	CMS_MAX_SAVE	20		/*=== 最多存储的页面数 ===*/
#define	MAXSTOREHISTORY	20      /* NEC要求成20条 */    /*10*/		/*=== 最多存储的历史记录 ===*/
#define	MAX_INPUTDNS	20		/*=== 记录用户输入URI的最大值 ===*/
#define	BOOKMARKNUM		20		/*=== 最多保存的书签数 ===*/
#define	DOWNLOADRETRY	3		/*=== 下载失败后重试的次数 ===*/

#ifndef CMS_LINUX
#define		CONF_DIRECTORY		"D:\\cmswapfile\\"			/*=== 调试信息和配置文件存放路径 ===*/
#define		CURR_DIRECTORY		"D:\\cmswapfile\\"			/*=== 临时文件存放路径 ===*/
#define		IMAGE_DIRECTORY		"D:\\cmswapfile\\"	/*=== 图片文件路径 ===*/
#define		CACHE_DIRECTORY		"D\\cmswapfile\\"	/*=== CACHE相关文件存放路径 ===*/
#define		TMPDLFILENAME			"D\\tempdl.dat"/*=== 下载文件时使用的临时文件名 ===*/
#else
#define		CONF_DIRECTORY		"/usr/local/temp/browser/"			
#define		CURR_DIRECTORY		"/usr/local/temp/browser/"			
#define		IMAGE_DIRECTORY		"/usr/local/temp/cache/"	
#define		CACHE_DIRECTORY		"/usr/local/temp/cache/"	
#define		TMPDLFILENAME		"/usr/local/temp/cache/tempdl.dat"
#endif

/*=== 浏览器下载文件类型定义 ===*/
typedef enum 
{
    DOWNLOAD_ML,				/*=== 标记语言 ===*/
    DOWNLOAD_GIF,				/*=== GIF ===*/
    DOWNLOAD_JPEG,				/*=== JPEG ===*/
    DOWNLOAD_WBMP,				/*=== WBMP ===*/
    DOWNLOAD_BMP,				/*=== BMP ===*/
    DOWNLOAD_PNG,				/*=== PNG ===*/
    DOWNLOAD_MSVG,				/*=== Mobile SVG ===*/
    DOWNLOAD_MIDI,				/*=== Midi ===*/
    DOWNLOAD_SMAF,              /*=== SMAF ===*/
    DOWNLOAD_IMY,              /*=== IMY ===add by yangjun for imy support*/
	DOWNLOAD_AMR,               /*=== AMR ===*/
    DOWNLOAD_FJAD,
    DOWNLOAD_FJAR,
    DOWNLOAD_DLING_FILE = 253,	/*=== 下载未知类型文件 ===*/
    DOWNLOAD_IMG = 254,	        /*=== 下载图片标记 ===*/
    DOWNLOAD_FAILED = 255		/*=== 下载失败的文件 ===*/

}EBrwDownloadType;

/*=================== Setup Data types ===================*/

/*=== 浏览器设置 ===*/
typedef struct _CMSBROWSERSETUP					
{
	CMS_BROWSER_BOOL	Cms_WEBIMG_Support;	/*=== 是否支持GIF和JPEG ===*/
	CMS_BROWSER_BOOL	Cms_Cache_Support;	/*=== 是否支持网页缓存 ===*/
	CMS_BROWSER_U8		Cms_Homepage[70];	/*=== 主页URL ===*/
	MC_PCC_FILL_STRUCT2                

	CMS_BROWSER_U8		Cms_WAP_Gateway[50];/*=== WAP网关地址 ===*/
	MC_PCC_FILL_STRUCT2
	CMS_BROWSER_U16		Cms_WAP_Port;		/*=== WAP网关端口 ===*/
	MC_PCC_FILL_STRUCT2
		
} CMSBROWSERSETUP, *P_CMSBROWSERSETUP;

/*=== 相关应用类型 ===*/
typedef enum _CMS_APPLICATION_TYPE
{
	CMS_WTA,
	CMS_EMAIL

}CMS_APPLICATION_TYPE;

/*=== 附加功能接口数据结构(Email和电话) ===*/
typedef struct _CMS_APPLICATION_DATA					
{
	P_CMS_BROWSER_U8	Cms_WTAI_Phonenumber;	/*=== WTA电话号码 ===*/
	P_CMS_BROWSER_U8	Cms_WTAI_Name;			/*=== WTA新电话条目的名称 ===*/
	P_CMS_BROWSER_U8	Cms_MAIL_Address;		/*=== Email地址 ===*/
	
} CMS_APPLICATION_DATA, *P_CMS_APPLICATION_DATA;


typedef struct _CMS_BROWSER_JAD_
{
	P_CMS_BROWSER_U8 MIDlet_JAR_Size;
	P_CMS_BROWSER_U8 MIDlet_JAR_URL;
	P_CMS_BROWSER_U8 MIDlet_Install_NOTIFY_URL;
	P_CMS_BROWSER_U8 MIDlet_Name;
	P_CMS_BROWSER_U8 MIDlet_Vendor;
	P_CMS_BROWSER_U8 MIDlet_Description;
}CMS_BROWSER_JAD, *P_CMS_BROWSER_JAD;

/*=== PUSH Box Data Structure ===*/
typedef CMS_BROWSER_U32 CMS_BROWSER_PUSH_TYPE;
#define CMS_BROWSER_SIL_PUSH			0
#define CMS_BROWSER_CO_PUSH				1
#define CMS_BROWSER_OTA_SETTING_PUSH	2

typedef struct _Cms_Browser_PUSH
{
	CMS_BROWSER_PUSH_TYPE PUSHType;
	P_CMS_BROWSER_VOID pPUSHData;
	
}CMS_BROWSER_PUSH, *P_CMS_BROWSER_PUSH;
/*xiaoyongq 20060223
typedef struct _Cms_SIL_PUSH
{
	P_CMS_BROWSER_U8 pTitle;
	P_CMS_BROWSER_U8 pSI_id;
	P_CMS_BROWSER_U8 pCreated;
	P_CMS_BROWSER_U8 pExpires;
	P_CMS_BROWSER_U8 pURL;
	CMS_BROWSER_BOOL downloaded;
	
}CMS_SIL_PUSH, *P_CMS_SIL_PUSH; */
//整合SIL Push与MTO Push于一个结构
typedef struct _Cms_ALL_PUSH
{
	CMS_BROWSER_PUSH_TYPE PUSHType;//类型
	P_CMS_BROWSER_U8 pTitle;//书签名称,设置名称
	P_CMS_BROWSER_U8 pSI_id;//NULL
	P_CMS_BROWSER_U8 pCreated;//接收时间
	P_CMS_BROWSER_U8 pExpires;//有效时间
	P_CMS_BROWSER_U8 pURL;//书签URL,设置主页

	P_CMS_BROWSER_U8 pGPRSAPN;
//	P_CMS_BROWSER_U8 pSettingISPName;
	P_CMS_BROWSER_U8 pSettingPort;
	P_CMS_BROWSER_U8 pSettingGateway;	

	P_CMS_BROWSER_U8 pUserName;
	P_CMS_BROWSER_U8 pUserPassword;
	P_CMS_BROWSER_U8 pAuthenticationMode;
	CMS_BROWSER_BOOL downloaded;
	
}CMS_ALL_PUSH, *P_CMS_ALL_PUSH;
/*=================== DEBUG DEFINE ===================*/


#ifdef CMS_BROWSER_DEBUG
#define Cms_Browser_Assert(expression, str) \
{ \
	if(expression) \
	{ \
		FILE *debug_f; \
		debug_f = fopen("D:\\BrowserAssert.txt", "ab+"); \
		if(debug_f != NULL) \
		{ \
			fwrite((const void*)str, 1, strlen((char *)str), debug_f); \
			fclose(debug_f); \
		} \
	} \
} 
#define Cms_Browser_ClearAssertInfo() \
{ \
	FILE *debug_f; \
	debug_f = fopen("D:\\BrowserAssert.txt", "rb"); \
	if(debug_f != NULL) \
	{ \
		fclose(debug_f); \
		remove("D:\\BrowserAssert.txt"); \
	} \
}
#else
#define Cms_Browser_Assert(expression, str) 
#define Cms_Browser_ClearAssertInfo()
#endif

#ifndef BTRACER
	#define BTRACER(str)     mms_Tracer((P_CMS_BROWSER_S8)str)
#endif

#ifndef BTRACER1
	#define BTRACER1(str,data1)  \
     \
    { CMS_BROWSER_U8 mv_buf[128];  \
    Cms_Browser_Sprintf((P_CMS_BROWSER_U8)mv_buf, (P_CMS_BROWSER_U8)str, (CMS_BROWSER_U32)data1); \
        Cms_Browser_StrCat((P_CMS_BROWSER_U8)mv_buf, (P_CMS_BROWSER_U8)"\n"); \
        BTRACER(mv_buf);  \
        }
#endif
        
#ifndef BTRACER2        
	#define BTRACER2(str,data1, data2)  \
     \
    { char mv_buf[128];  \
    sprintf(mv_buf, str, data1, data2); \
        strcat(mv_buf, "\n"); \
        BTRACER(mv_buf);  \
        }
#endif
        
#ifndef BTRACER3        
	#define BTRACER3(str,data1, data2, data3)  \
     \
    { char mv_buf[128];  \
    sprintf(mv_buf, str, data1, data2, data3); \
        strcat(mv_buf, "\n"); \
        BTRACER(mv_buf);  \
        }
#endif
        
#ifndef BTRACER4        
	#define BTRACER4(str,data1, data2, data3, data4)  \
     \
    { char mv_buf[128];  \
    sprintf(mv_buf, str, data1, data2, data3, data4); \
        strcat(mv_buf, "\n"); \
        BTRACER(mv_buf);  \
        }
#endif



#ifdef __cplusplus 
extern "C" {
#endif
/*=== WAP协议栈外部接口函数 ===*/


#include "Cms_WAPMain.h"



#ifdef __cplusplus 
}
#endif

#include "CmsBrowserAPI.h"

#endif



