/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_whttp_public.h

功能描述		: 公共信息

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn
================================================================*/
#ifndef _CMS_WHTTP_PUBLIC_H
#define _CMS_WHTTP_PUBLIC_H

#include "Cms_WHTTP.h"
#include "Cms_WHTTPHeader.h"
#include "Cms_WHTTPCookie.h"
#include "Cms_WAP.h"
#include "WHTTP2Socket.h"
#include "AuthenticationManager.h"

#ifdef SUPPORT_HTTP_TLS
#include "cmsSSLHttpInterface.h" 
#endif

//#include "CmsBrowserPublic.h"
#include "CmsCTLDownload.h"
#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_TIMER0 0
#define HTTP_TIMER1 1

#define  POSTCONTENTREPORT_ 899
#define  POSTCONTENTREPORT_SUCCESS		(POSTCONTENTREPORT_+1)
#define  POSTCONTENTREPORT_MEMBER_ERRO	(POSTCONTENTREPORT_+2)
#define  POSTCONTENTREPORT_USER_DISCARD	(POSTCONTENTREPORT_+3)
#define  POSTCONTENTREPORT_DISCONNECT	(POSTCONTENTREPORT_+4)
#define  POSTCONTENTREPORT_UNKOWN_FILE	(POSTCONTENTREPORT_+5)
#define DESTCOOKIESBVFLEN	600	
/*===============引用的外部变量===================*/
extern HTTPMachine			*HTTPGlobalMachine;
extern struct _RequestURL	RequestURL;
extern struct _pre_reserved_URL pre_reserved_URL;
extern Content_Struct		Content_Buffer;
extern enum _GPRSState		GPRSState;
extern Cms_BR_HttpPatam_t	*current_param;

/*保存的回调函数指针*/
extern Cms_BR_HttpCallBack_t Cms_Browser_CBFunction;
extern HTCodingInf		 	 CodingInf;
extern HTResponseInf		 HTTPResponseInf;
extern int HTTPWorking ;
/*===============引用的外部函数===================*/
extern void Cms_Browser_DisplaySecurityIndicate(unsigned char bSecurity);
extern void sendCONNECTCommandToProxy(void);
extern int getCurrentComeDataTimes(void);
extern unsigned int CmsGetCurrentTimerTick(void);
extern int DealwithRequest(CMS_VOID);
extern int		CmsIsImgStackDL(void);
extern void		parse_receivedcontent(void);
extern void		exception_event_nurse(void);
extern void		set_abort_flag(void);
extern void		clear_abort_flag(void);
extern void		httpPostRedirectionEvent(unsigned char *redirectUrl);
extern void		HttpPostExceptionEvent(void);
extern int		tlsCallHttpCBFunction(const unsigned char *bufTLS,const int content_len);  
extern CMS_BOOL getSafeConnectType(void);
extern void		FreeHttpResponseParing3PartsMem(void);
extern void		restorHttpTaskType(void);
extern httpTask_e getHttpTaskType(void);
extern int		exchangeSTRPort2INTPort(unsigned char *strport);
extern void		set_recbuf_flag_zero(void);
extern  int		IfNeedPostDownloadRateOfProcess(void);
extern  int		httpPostDownloadRateOfProcess(int total,int cur,int typeID,int resultDownload);
extern void		freeCurrentdownRequestURLmemery(void);
extern int		inURL(const char * str);
extern int		postPopAuthenticateDialogEvent(void);
extern void		postMemeryErroReportToServer(void);
extern void		postDownSuccessReportToServer(void);
extern void     postUserDiscardReportToServer(void);
extern int		getIfPageInResponse(void);
extern void		restoreDownLoadContentTypeFlag(void);
extern void		CmsSendContentReport(int Id);
extern int		recordCurrentAuthenticateInfo(Authenticate_Type_e authenType,const unsigned char *authenStrInfo);
extern int		httpPostAuthenticateEvent(void);
extern void		destroyDigestAuthenticate(void);
extern void     initDigestAuthenticate(void);
extern Cms_BR_HttpMethod_e getCurrentHTTPMethod(void);
extern void SetIfHaveContentLenInResponseFlag(CMS_BOOL flag);
extern CMS_BOOL getIfHaveContentLenInResponseFlag(void);
extern char		*getSYNCMLaccept(void);
extern int getCurrentSocketID(void);
#ifdef SYNCML_SUPPORT
extern void		Cms_Syncml_Access_HttpData(Cms_BR_HttpData_Ptr http_data );
#endif
/*===========引用centel外部函数===================*/
extern void		Cms_AuthenticationEditor(void);
extern void		brw_NetConnect(void);
extern void		Cms_DisplayState(int state);
extern CMS_VOID http_dispatch_event(CMS_U8 MessageID);

extern void		brw_GetGatewayParameter(unsigned char *p_Ip, int *p_Port);
extern void		Cms_SetUseragent(unsigned char * u_a);
extern int		Cms_Brower_GetSecuritySetting(void);
extern int		get_abort_flag(void);
extern Cms_ContentType_e get_current_download_conten_type(void);
extern int IfCurrentSocketClosed(void);
extern void clearCallFlag(void);
//extern CMS_BROWSER_BOOL CmsWAPWBXMLToWML(P_CMS_BROWSER_U8 data, CMS_BROWSER_U32 len, P_CMS_BROWSER_U8 result, CMS_BROWSER_U32 resultlen);
#ifdef SUPPORT_HTTP_TLS
	   void		setTunnelFlag(void);
	   void		clearTunnelFlag(void);
	   CMS_BOOL	getTunnelFlag(void);
	   void sendOPTIONCSommandToServer(void);
#endif
#ifdef __cplusplus
};
#endif

#endif