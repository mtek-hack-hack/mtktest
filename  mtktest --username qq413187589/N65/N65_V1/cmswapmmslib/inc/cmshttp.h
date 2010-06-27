/************************************************************************* 
 * Copyright (c) 2000-2003 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-8-18   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn    	    	
 * 文  件：  cmshttp.h 	
 * 描  述：			  
 ************************************************************************/
#ifndef _CMSHTTP_H
#define _CMSHTTP_H

#ifdef __cplusplus
extern "C" {
#endif

#define CONTENT_FORWARD_YES  0// 允许转发
#define CONTENT_FORWARD_NO  1//不允许转发
#define HTTP_METHOD_GET		0
#define HTTP_METHOD_POST	1
#define HTTP_METHOD_OPTIONS	2
#define HTTP_METHOD_HEAD	3
#define HTTP_METHOD_PUT		4
#define HTTP_METHOD_DELETE	5
#define HTTP_METHOD_TRACE	6
#define HTTP_METHOD_CONNECT 7
/*支持紫移通mFlash下载*/
#define SUPPORT_ZIYITONG
/*http中定时器开关，关闭此宏则不起动定时器功能*/
#define SUPPORT_HTTP_TIMER 

/*http中TLS 开关，关闭此宏则不启动TLS功能*/
#define SUPPORT_HTTP_TLS

/*mmsHttp测试功能*/
//#define TESTMMS

/*定义是否走ccproxy*/	
//#define CCPROXY

#ifdef _D_DF
/*SYNCML 开关*/
//#define SYNCML_SUPPORT
#endif

/*MULTI REQUEST LOCK,宏打开可以支持一次连接多次请求*/
#define MULTI_REQUEST_SUPPORT

/* 枚举http方法 */
typedef enum 
{
	GET_METHOD		= 0x40,	/* get method */
	POST_METHOD		= 0x60,	/* post method */
	OPTIONS_METHOD	= 0X10,	/*options method*/
	HEAD_MEHTOD		= 0X20,	/*head method*/
	CONNECT_METHOD  = 0X90  /*CONNECT method*/

}Cms_BR_HttpMethod_e;

/* 枚举url链接方式 */
typedef enum 
{
	OUTLINE_URL = 1,	/* outline url */
	INLINE_URL	= 0		/* inline url */
}Cms_BR_Url_e;

typedef enum
{
	CODING_UTF8 = 0,    /* utf8编码  */
	CODING_GB,			/* GB编码    */
	CODING_8859_1,	    /* 88591编码 */
	CODING_UNKNOW       /* 未知编码  */  //  Modified by TIPrj[2005/6/29]
	
} Cms_EncodingType_e;
	
/* 定义链接参数 */
typedef struct _tagNetParam
{
	 char		*name;	/* 参数名称 */
	 char		*value;	/* 参数数值 */
	struct _tagNetParam	*next;	/* 下一个参数 */

}Cms_BR_NetParam_t, *Cms_BR_NetParam_Ptr;

/* 用于定义browser模拟传递给http模块的接口参数 */
typedef struct _tagHttpParam
{
	Cms_BR_HttpMethod_e	http_method;		/* http方法 */
	
	Cms_BR_Url_e			url_type;		/* 当前rul类型,是否为页内链接 */
	char				*http_url;		/* http的url内容 */
	
	char					*param;			/* 参数字符串 */
	unsigned int			param_len;		/* 参数长度 */
	
}Cms_BR_HttpPatam_t,*Cms_BR_HttpPatam_Ptr;
	
	
/*=== http下载文件类型定义 ===*/
typedef enum 
{
	CMS_HTTP_CONTENT_ML					= 0,				/*=== 标记语言 ===*/
	CMS_HTTP_TEXT_PLAIN,									/*普通文本类型*/
	CMS_HTTP_CONTENT_CSS,								/*=====CSS=========*/
	CMS_HTTP_CONTENT_HTML,								/* text/html content type */
	
	CMS_HTTP_CONTENT_GIF					= 20,			/*=== GIF ===*/
	CMS_HTTP_CONTENT_JPEG,								/*=== JPEG ===*/
	CMS_HTTP_CONTENT_WBMP,								/*=== WBMP ===*/
	CMS_HTTP_CONTENT_BMP,								/*=== BMP ===*/
	CMS_HTTP_CONTENT_PNG,								/*=== PNG ===*/
	CMS_HTTP_CONTENT_IMAGE_ZDD,							/*Download descriptor*/
	CMS_HTTP_CONTENT_IMAGE_VIS,							/*有关VIS的 mime type*/
	CMS_HTTP_CONTENT_IMAGE_DRM,							/*有关drm的 mime type*/
	CMS_HTTP_CONTENT_IMAGE_BILL,						/*计费信息*/
	CMS_HTTP_CONTENT_IMAGE_STL,							/*状态回报*/
	CMS_HTTP_CONTENT_CHAOTEX_CIM,						/*=== mFlash ===*/
	CMS_HTTP_CONTENT_DZD,								/*学习机课件*/
	CMS_HTTP_CONTENT_IMAGE_KJJ,							/*Lenovo Kjj	*///chaozhu.zhou add for lenovo kjj
	
	CMS_HTTP_CONTENT_MIDI				= 50,			/*=== Midi ===*/
	CMS_HTTP_CONTENT_AMR,								/*=== ARM music ===*/
	CMS_HTTP_BROWSER_MUSIC_SMAF,
	CMS_HTTP_CONTENT_MP3,
	CMS_HTTP_CONTENT_MPEG4,
	CMS_HTTP_CONTENT_AAC,
	CMS_HTTP_CONTENT_WMA,
	CMS_HTTP_CONTENT_X_WAVE,							/*=== wave music ===*/
	CMS_HTTP_CONTENT_IMY,								/**/
	CMS_HTTP_CONTENT_3GP,								/**/	
	CMS_HTTP_CONTENT_GSX,		
	CMS_HTTP_CONTENT_FJAD				= 100,
	CMS_HTTP_CONTENT_FJAR,
	CMS_HTTP_CONTENT_WMLSCRIPT,							/*====wmlscript===*/
	CMS_HTTP_CONTENT_WMLSCRIPTC,						/*====wmlscriptc===*/
	
	CMS_HTTP_CONTENT_DRM_MESSAGE    	= 150,			/*=====DRM MESSAGE== =======*/
	CMS_HTTP_CONTENT_DRM_CONTENT,						/*=====DRM CONTENT== =======*/
	CMS_HTTP_CONTENT_DRM_RIGHTS_XML,					/*=====DRM  版权描述文件== =======*/
	CMS_HTTP_CONTENT_DRM_RIGHTS_WBXML,				/*=====DRM  版权对象文件二进制描述== =======*/
	CMS_HTTP_CONTENT_DRM_XWAV,							/*=== audio/x-wav===*/
	
	CMS_HTTP_BROWER_SETTING_XML		= 200,			/*http provisioning xml doc*/
	CMS_HTTP_BROWER_SETTING_WBXML,						/*浏览器二进制XML文件*/
	CMS_HTTP_BROWER_BOOKMARK_SETTING_XML,				/*书签配置XML*/
	CMS_HTTP_BROWER_BOOKMARK_SETTING_WBXML,			/*书签二进制WBXML*/
	CMS_HTTP_BROWSER_SYNCML_XML,
	CMS_HTTP_BROWSER_SYNCML_WBXML,
	CMS_HTTP_CONTENT_MSVG,								/*=== Mobile SVG ===*/
	
	CMS_HTTP_OCTET_STREAM				= 252,			/*=== 未知类型文件STREAM ===*/
	CMS_HTTP_CONTENT_DLING_FILE			= 253,			/*=== 下载未知类型文件 ===*/
	CMS_HTTP_CONTENT_DLING_IMG			= 254,			/*=== 下载图片标记 ===*/
	CMS_HTTP_CONTENT_DLFAILED			= 255			/*=== 下载失败的文件 ===*/
	
}Cms_ContentType_e;

typedef enum
{
	HTTP_Continue				= 100,
	HTTP_Switching_Protocols	= 101,
	HTTP_OK						= 200,
	HTTP_Created				= 201,
	HTTP_Accepted				= 202,
	HTTP_Non_Authoritative		= 203,
	HTTP_No_Content				= 204,
	HTTP_Reset_Content			= 205,
	HTTP_Partial_Content		= 206,
	HTTP_Multiple_Choices		= 300,
	HTTP_Moved_Permanently		= 301,
	HTTP_Found					= 302,
	HTTP_See_Other				= 303,
	HTTP_Not_Modified			= 304,	
	HTTP_Use_Proxy				= 305,
	HTTP_Temporary_Redirect		= 307,
	HTTP_Bad_Request			= 400,
	HTTP_Unauthorized			= 401,
	HTTP_Payment_Required		= 402,
	HTTP_Forbidden				= 403,
	HTTP_Not_Found				= 404,
	HTTP_Method_Not_Allowed		= 405,
	HTTP_Not_Acceptable			= 406,
	HTTP_Proxy_Authentication_Required = 407,
	HTTP_Request_Timeout		= 408,
	HTTP_Conflict				= 409,
	HTTP_Gone					= 410,		
	HTTP_Length_Required		= 411,
	HTTP_Precondition_Failed	= 412,
	HTTP_Request_Entity_Too_Large = 413,
	HTTP_Request_URI_Too_Long	= 414,
	HTTP_Unsupported_Media_Type = 415,
	HTTP_Requested_Range_Not_Satisfiable = 416,
	HTTP_Expectation_Failed		= 417,
	HTTP_Internal_Server_Error	= 500,
	HTTP_Not_Implemented        = 501,
	HTTP_Bad_Gateway			= 502,
	HTTP_Service_Unavailable	= 503,
	HTTP_Gateway_Timeout		= 504,
	HTTP_HTTP_Version_Not_Supported = 505,

	/*包括服务器response解析失败、
	从socket收到长度为0、
	页面太大都认为是NODATA事件,
	统一递交给浏览器一样处理*/
	HTTP_NO_DATA	,			
	/*服务器忙事件,可能的情况会包括服务器连接不上,DNS解析失败,服务器socket异常关闭*/
	HTTP_CONNECT_SERVER_FAILED,
	/*服务器暂时关闭*/
	HTTP_NO_SUCH_SERVER,
	/*下载中断失败，也就是说当正在下载造成的异常，没有正常结束*/
	HTTP_DOWNLOADING_FAILED,
	/*拨号连接GPRS失败*/
	HTTP_DIALING_FAILED,
	/*GPRS异常断开失败*/
	HTTP_GPRS_DISCONNECT,//这个是在有下载任务时发生的事件类型
	/*TIMER OUT*/
	HTTP_TIMER_OUT,
	/*内存分配严重失败*/
	HTTP_MALLOC_FAILED,
	/*socket失败*/
	HTTP_FILE_TOO_LARGE,
	HTTP_SOCKET_ERRO,
	HTTP_GPRS_CONNECTION_DISAPPEAR,//这个浏览器没有下载任务时，发生断线，无需提示
	
	HTTP_NOT_SUPPORT_CONTENT_TYPE  //浏览器不支持该类型文件的下载

} HTTP_state_code_e;

typedef enum 
{
	NORMAL_HTTP_TASK = 0,	//普通下载业务
	WTA_HTTP_TASK,			//WTA下载业务
	PUSH_HTTP_TASK,			//PUSH下载业务
	SYNCML_HTTP_TASK,			//其他下载业务
	MMS_HTTP_TASK				//彩信业务
} httpTask_e;

//http cache response data struct
typedef enum
{
	CACHE_NULL = -1,
	CACHE_PUBLIC ,
	CACHE_PRIVATE ,
	CACHE_NO_CACHE,
	CACHE_NO_STORE,
	CACHE_NO_TRANSFORM,
	CACHE_MUST_REVALIDATE,
	CACHE_PROXY_REVALIDATE,
	CACHE_MAX_AGE,
	CACHE_S_MAXAGE

} CACHE_RESPONSE_DIRECTIVE_e;
typedef struct  
{
	CACHE_RESPONSE_DIRECTIVE_e cache_response_directive_e;
	int delta_seconds;//当cache_response_directive_e为CACHE_MAX_AGE或者CACHE_S_MAXAGE
							//时才能读取delta_seconds值
} CACHE_RESPONSE_DIRECTIVE_s;


/* 用于定义http模块返回的数据 */
typedef struct _tagHttpData
{	
	Cms_ContentType_e	content_type;		/* http数据content type */
	Cms_EncodingType_e    coding_type;      /* http数据content 编码类型 */	
	 int				content_len;		/* http数据长度 */
	 unsigned char		*content_buf;		/* http数据buf */	 
	 HTTP_state_code_e	status_code;		/* server 应答状态*/	 
	 char				*backUrl;           /*返回URL地址给上层调用*/
	 CACHE_RESPONSE_DIRECTIVE_s cache_response_directive;/*返回cache info*/
}Cms_BR_HttpData_t, *Cms_BR_HttpData_Ptr;


void Cms_BR_Access_HttpData( Cms_BR_HttpData_Ptr http_data );
typedef void (*Cms_BR_HttpCallBack_t)( Cms_BR_HttpData_Ptr http_data );

int DiscardHttpCurrentDownLoadTask(void);
extern char *getDownLoadContentType(void);
void ChangeUrlWithContentLocation(char *newurl);
#ifdef __cplusplus
};
#endif

#endif
