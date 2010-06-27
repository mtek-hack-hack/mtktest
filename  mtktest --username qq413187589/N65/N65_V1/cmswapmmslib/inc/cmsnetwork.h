/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsNetwork.h

功能描述		: 网络模块功能及接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSNETWORK_H
#define CMSNETWORK_H

/*=================== browser state message ID =========*/ 
/*
 *These string ID was used for function
 *CMS_BROWSER_VOID Cms_Browser_DisplayState(CMS_BROWSER_STATE_STR message);
 */
typedef enum _CMS_BROWSER_STATE_STR
{
	STATE_DOWNLOAD_FAILED,		//"Download Failed!"||"下载失败"
	STATE_DOWNLOADING,			//"Downloading . . . "||"正在下载 . . ."             
	STATE_DOWNLOAD_SUCCESS,		//"Download success "||"下载成功"                                      
	STATE_DECODE_FAILED,		//"Decode Failed!"||"解码失败"                 
	STATE_GATEWAY_DISCONNECTED,	//"Gateway disconnected"||"网关已断开"                                   
	STATE_HANGUPING,			//"Hanguping . . . "||"挂断中 . . ."                                               
	STATE_PARSER_FAILED,		//"parser failed!"||"解析网页失败!"                                         
	STATE_CHARSET_BEYOND,		//"Charset not supported!"||"不支持的字符集"                                 
	STATE_ABOUT_BLANK,			//"about blank"||"主页未设置"   
	STATE_PAGE_REFRESHING,	    //"Page refreshing..."||"自动装载,请稍等..."                                            
	STATE_PAGE_ERROR,			//"Page error!"||"页面错误!"                                                     
	STATE_DOWNLOAD_BEGAIN,		//"Download  . . ."||"准备下载 . . ."                                                        
	STATE_CONNECTING,			//"Connecting . . . "||"连接中 . . ."
	STATE_DIALING,				//"Dialing . . . "||"拨号中 . . ."
	STATE_DIAL_FAILED,			//"Dial failed "||"拨号失败"                                              
	STATE_SENDING,				//"Sending . . ."||"正在发送数据 . . ."                                                        
	STATE_PARAM_ERROR,			//"Param error!"||"应用参数错误！"                                           
	STATE_NO_MEMORY,			//"No memory!"||"资源不足！"                                             
	STATE_CONNECT_FAILED,		//"Connect failed!"||"网关连接失败"                                         
	STATE_TIMER_ERROR,			//"Timer error!"||"定时器操作错误！"                                           
	STATE_UNKNOWN_ERROR,		//"Unknown error!"||"未知错误类型！"                                         
	STATE_WAPSTACK_BUSY,		//"WAP stack busy!"||"协议栈忙！"                                        
	STATE_NETWORK_TIMEOUT,		//"Network Timeout!"||"网络超时！"                                       
	STATE_RECONNECTING,			//"Reconnecting . . . "||"重连接网关"                                     
	STATE_WAPSTACK_SUSPENDED,	//"WAP stack suspended!"||"协议栈已挂起！"                                   
	STATE_WAPSTACK_RESUME_FAILED,	//"WAP stack resume failed!"||"协议栈恢复失败！"                               
	STATE_WAPSTACK_RESUMED,		//"WAP stack resumed!"||"协议栈已恢复！" 
	STATE_PARSERING,			//Parsering
	STATE_LAYOUTING,			//Layouting
	STATE_DRAWING,				//Drawing

	STATE_WMLSCRIPT,			/* wml script status */
	STATE_WTAI,

	STATE_TLS_WAIT_CONFIRM  ,	/* tls 连接建立时等待用户确认服务器证书.  */
	STATE_WTLS_WAIT_CONFIRM ,	/* wtls 连接建立时等待用户确认服务器证书. */
	STATE_OS_SOCKET_INVALIED,	/*系统创建socket失败，浏览器退出*/
	//浏览器正常运行中不作任何动作的状态， 陈飞
	STATE_NORMAL				/* 既然定了那么多状态，不做任何动作也应该是一种状态 */ //  Modified by TIPrj[2005/6/29]
	
}CMS_BROWSER_STATE_STR;



/*************************************************************************
	 枚举网络事件
 ************************************************************************/
typedef enum
{
	EVENT_NETLINK_RETURN,
	EVENT_NETCLOSE_RETURN,
	EVENT_SOCKETCONNECT_RETURN,
	EVENT_GETHOSTIP_RETURN,
	EVENT_DATARRIVED,
	EVENT_SOCKETCLOSED_RETURN,
	EVENT_REMOTESOCKETCLOSED,
	EVENT_DATASENT_RETURN,
	EVENT_SOCKETBUFFERFREE
} NET_EVENT_E;



/* 网络事件的参数 */
typedef enum
{
	NETLINK_SUCCESS,
	NETLINK_FAILED,
	NETCLOSE_SUCEESS,
	NETCLOSE_FAILED,
	SOCKETCONNECT_SUCCESS,
	SOCKETCONNECT_FAILED //  Modified by TIPrj[2005/6/29]
}NET_EVENT_PARAM_E;


/*************************************************************************
	 浏览器网络事件
 ************************************************************************/
typedef enum
{
	BRW_NETLINK_RETURN = 0,
		BRW_SENDDATA_RETURN,
		BRW_DATAARRIVED,
		BRW_NETCLOSELINK_RETURN,
		BRW_WTP_TIMEROUT_MSG,
		BRW_WML_TIMEROUT_MSG  //  Modified by TIPrj[2005/6/29]
}BRW_CenMsgType;

typedef enum
{
	BRW_NETLINK_FAILED,
		BRW_NETLINK_SUCCESS
}BRW_NETLINK_RETURN_VALUE;//网络连接后

typedef enum
{
	BRW_SENDDATA_FAILED,
		BRW_SENDDATA_SUCCESS
}BRW_SENDDATA_RETURN_VALUE;//发送数据后返回消息


typedef enum 
{
	BRW_NETCLOSELINK_ERROR,
		BRW_NETCLOSELINK_SUCCESS
}BRW_NETCLOSELINK_RETURN_VALUE;

/************************************************************************* 
 * 描  述：  分发网络事件 
 * 返回值：  void
 * 全局量：  
 * 日  期：  2004-10-30
 * 作  者：  滕永; yongt@mobilesoft.com.cn
 ************************************************************************/
void NetPostEvent(NET_EVENT_E type,NET_EVENT_PARAM_E param1,void* param2);
void brwEventPostEvent (BRW_CenMsgType type,unsigned int param1,void* param2);
void brwEventProcessEvent (void);
#ifdef WIN32
void CreateReadDataEvent( void );
#endif

/*************************************************************************
	 客户提供的接口函数
 ************************************************************************/
int	CmsGetNetType( void );
int CmsGetNetRoad( void );
void brw_NetDisconnect ( void );
void brw_GetGatewayParameter( unsigned char *ip,int * port );



/*************************************************************************
	 下载图片的图片
 ************************************************************************/
void CmsInitImgStack( void );
int	 CmsIsDownLoadImg( void );
void CmsDownloadImg( void );
int  CmsIsImgStackDL( void );
int  CmsAbortDownload( void );


#endif
