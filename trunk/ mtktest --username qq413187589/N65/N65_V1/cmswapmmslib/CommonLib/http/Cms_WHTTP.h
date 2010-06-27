/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTP.h

功能描述		: 设置模块功能及接口函数定义

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _CMS_HTTP_H
#define _CMS_HTTP_H

/********************************************************/


#include "Cms_WHTTPVariable.h"
#include "CmsHttp.h"
#include "Cms_WAP.h"
/********************************************************/
#ifdef __cplusplus
extern "C" {
#endif


typedef struct HTTPMachine HTTPMachine;

typedef struct HTTPEvent	HTTPEvent;



enum http_abort_reason
{
	BROWSERABORT,
/*
说明：暂时http abort事件只区分
上层abort事件、网络层socket异常事件以及不可知abort事件
*/
	NETABORT,
	UNKNOWNABORT

}; 

typedef enum 
{               
	NOUSE1=-1,

	#define HTTP_EVENT(name, fields) name,
	#define INTEGER
//	#define HTTP_MACHINE
	#define SESSION_MACHINE
	#define HTTPHEADER
	#include "Cms_WHTTPEventDecl.h"
#ifdef SUPPORT_HTTP_TLS
    TLS_HANDSHAKE_SUCCESS =200,

    TLS_HANDSHAKE_FAIL,
    TLS_CLOSE_BY_SERVER,
    TLS_FAILED
#endif
} HTTPEventType;

typedef enum 
{  
	NOUSE= -1

	#define STATE_NAME(name) ,name
	#define ROW(state, event, condition, action, next_state)
	#include "Cms_WHTTPStateDecl.h"

} HTTPState;

	#define INTEGER(name) CMS_S32 name
	#define SESSION_MACHINE(name) HTTPMachine *name
	#define HTTPHEADER(name) HTTPHeader *name
	#define HTTP_EVENT(name, fields) struct name fields;
	#include "Cms_WHTTPEventDecl.h"


struct HTTPEvent 
{
	HTTPEventType type;
	HTTPEvent *next;

	#define INTEGER(name) 
	#define SESSION_MACHINE(name) 
	#define HTTPHEADER(name) 
	#define HTTP_EVENT(name, fields) struct name name;
	#include "Cms_WHTTPEventDecl.h"
};

struct HTTPMachine
	#define INTEGER(name) CMS_S64 name
	#define EVENT_POINTER(name) HTTPEvent *name
	#define SESSION_MACHINE(fields) fields
	#include "Cms_WHTTPMachineDecl.h"
;

typedef struct HTTPHeader 
{
    struct HTTPHeader *next;
    P_CMS_U8 key;
    P_CMS_U8 value;

} HTTPHeader;

struct _RequestURL
{
	 char *  URLscheme;
	 char *  URLauthortity;
	 char *  URLpath;
	 char *  URLquery;
	 char *  URLfragment;
	 char *  URLPort;
} ;

 struct _pre_reserved_URL
{
	char *current_host;
	char *current_path;
	char *current_server_ip;  /*such as "61.155.114.21"*/

	int  host_len;	/* host length */
	int  path_len;  /* host length */
} ;

/*********************************************************/

/*
 * Initialize the httP subsystem. This MUST be called before any other
 * functions in this header.
 */
//CMS_VOID http_init(CMS_VOID);


/*
 * Create a httPEvent structure and initialize it to be empty. Return a
 * pointer to the structure or NULL if there was a failure.
 */
HTTPEvent *http_event_create(HTTPEventType type);


/*
 * Destroy a httPEvent structure, including all its members.
 */
CMS_VOID http_event_destroy(HTTPEvent *event);


/*
 * Find the correct HTTPMachine to send the event to, or create a new
 * one, and then make that machine handle the event.下层向HTTP传递消息事件
 */
//extern CMS_VOID http_dispatch_event(CMS_U8 MessageID);


/*
 * Create a HTTPMachine structure and initialize it to be empty. Return a
 * pointer to the structure or NULL if there was a failure.
 */
HTTPMachine *http_machine_create(CMS_VOID);

void http_machine_destroy(CMS_VOID) ;

/*
 * Feed a HTTPEvent to a HTTPMachine. Handle errors, do not report them to
 * the caller.
 */
CMS_VOID http_handle_event(HTTPMachine *machine, HTTPEvent *current_event);

int http_parse_url(char *url,Cms_BR_Url_e url_type);

/*
根据上层传递过来的参数格式话请求发送包
*/

CMS_VOID http_request_format(unsigned char *szBuffer);

/*create 浏览器启动事件*/
HTTPEvent * HTTPCreateBrowserStartupRequest(CMS_VOID);
/*create HTTP请求事件*/
HTTPEvent * HTTPCreateSMethodInvokeRequest(CMS_VOID);
/*create 发送数据事件*/
HTTPEvent * HTTPCreateSendDataRequest(CMS_S32 method_type);
/*create 接受完数据解析数据事件*/
HTTPEvent * HTTPCreateReceiveDataRequest(CMS_VOID);
/*create 解析完数据重定向事件*/
HTTPEvent * HTTPCreateRedirectRequest(CMS_VOID);
/*create 异常放弃事件*/
HTTPEvent * HTTPCreateBrowserAbortRequest(CMS_VOID);
/*
 *添加该事件的目的只是测试多余的FD_READ事件，和系统没有关系
 *add by shoumingl,/9/13/2004
 */
HTTPEvent * HTTPCreateTestFD_READRequest(CMS_VOID);
HTTPEvent * HTTPCreateRequestErroRequest(CMS_VOID);
HTTPEvent * HTTPCreateResumeMachineStateToWaiting(CMS_VOID);
HTTPEvent * HTTPCreateNewDownLoadTaskAbortEvent(CMS_VOID);
extern CMS_VOID http_dispatch_event(CMS_U8 MessageID);

#ifdef __cplusplus
};
#endif

#endif

