/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WAP.h

功能描述		: 为上层应用提供WAP函数接口

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn
================================================================*/
#ifndef _CMS_WAP_H
#define _CMS_WAP_H
#include "cmshttp.h"
#include "Cms_WHTTPVariable.h"
#ifdef __cplusplus
extern "C" {
#endif

#define TCPIPTESTSPENDTIME 
/*
#ifdef _D_DF
#define RECDATABUFLEN ( Cms_Browser_GetMaxSizeCanDownload() + 4*1024 )
#else
#define RECDATABUFLEN (120*1024)
#endif
*/
#define RECDATABUFLEN ( Cms_GetDownloadMaxSize() + 4*1024 )

/* java下载所需要的内存块根据上层传入的数值进行动态分配 */
#define RECJAVADATABUFLEN ( GetOtaJavaSize() + 4*1024 )
//#define RECDATALESSBUFLEN (20*1024)//会遇到分配100K内存失败的情况，再分配小内存20k
#define PRE_URL_HOST_LEN 200
#define PRE_URL_PATH_LEN 400
#define PRE_URL_IP_LEN 20
#define DOWNLOADCONTENTTYPELEN 60

//#define SENDDATA_ASYNC  //此宏用来把发送数据变为异步的


#define timerOutDefault 30000	//毫秒(2分钟),网络事件等待60秒//#define timerOutDefault 60000
#define timerOutDefault2 20000	//拨号结果等待20秒
#define AUTOTRYMAX       2/*20051102 cocoma xu modify修改重传次数以前是3*/

enum _GPRSState
{
	GPRSNull,
	GPRSConnecting,
	GPRSOnline
};
enum _WAP2ROAD
{
	GATEWAY_CMWAP,
	GATEWAY_CMNET
};
/*存放接收到的数据*/
typedef struct _whttp_info
{
	CMS_U32		Content_Len;

	unsigned	char * Data;
	int			recv_data_len;
	int			all_data_len;
	
	/*每次有新的链接时，该值复原为0，当socket成功接收数据后赋为1*/
	/*表示成功当前下载成功*/
	int		course_flag ;
	/*浏览器启动开始拨号，初值状态为0，拨号成功后状态为1*/
	int		dialing_flag;
	char    wap_gateway_ip[20];
	int		wap_gateway_port;
	int     have_connect_ip ;
	int     have_connect_port;
	enum _WAP2ROAD WAP2ROAD  ; 
	CMS_BOOL    IfSafeConnect;/*CMS_YES 是安全连接； CMS_NO 普通连接*/
	httpTask_e httpTask;
	char    downLoadContentType[DOWNLOADCONTENTTYPELEN];
	int     contentLenInReponse;
	int     headersLenInResponse;
	int		DownLoadTaskFlag ;//标记正在下载的是否是网页:1,yes;2,no;0,unknown
	CMS_BOOL IfHaveContentLenInResponseFlag;//CMS_NO，表示没有；CMS_YES，表示有
											//每次新任务开始时要设置为有
	CMS_BOOL initSocketFlag ;//CMS_NO,创建失败;CMS_YES，成功
	int     ConnectionFlagInResponse;//没有得到response时为-1;得到如果是close是0，keepalive是1；
	int     preSocketID;
	int     SendFailedAutoTryMax;
	int     ConnectFailedAutoTryMax;
	int		JavaReportSendAgain;
	int     javaTaskFlag;//0,not java download;1,java download
#ifdef SUPPORT_HTTP_TLS
    unsigned char *tls_send_data;
	CMS_BOOL    CurTunnelIfEstalbished;/*当前通道是否建立 CMS_YES;CMS_NO */
#endif
#ifdef TCPIPTESTSPENDTIME
	int     startTICK;		//启动TICK
	int     endTICK;	//终止TICK
#endif
	unsigned char *sendBuf;
	unsigned char *SendJavaReportData;
	int				SendJavaReportDataLen;
	
	unsigned char	*szBuffer;
	int				recv_tls_data;

} Content_Struct;

/*此函数让上层调用初始化WAP STACK，包括状态机的初始化，HTTPWorking状态的设定*/
CMS_BOOL Cms_WAP2StackInit( Cms_BR_HttpCallBack_t pFunction );
CMS_VOID 	Cms_WAP2StackDestroy(CMS_VOID);
/*下载网页函数，供上层调用*/
int			Cms_BR_Http_DownLoad(Cms_BR_HttpPatam_t *param);
/*用户取消此次下载*/
int			DiscardHttpCurrentDownLoadTask(CMS_VOID);

void		set_download_state(CMS_BOOL);
CMS_BOOL	get_download_state(void);
void		set_current_download_conten_type(void);
void		exception_nodata_download(HTTP_state_code_e exception_code);
Cms_BR_Url_e analyse_url_type(const char * url);

#ifdef __cplusplus
};
#endif

#endif /*_CMS_WAP_H*/