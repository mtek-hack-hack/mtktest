/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_HTTPEventDecl.h

功能描述		: 事件宏定义文件，此文件功能有三：
					1、定义具体事件struct结构，such as：struct SConnectRequest
														{
															CMS_S32 source_port;
														};
					2、定义HTTPEvent的struct数据结构
					3、

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
 
/*
 http与socket交互的事件		
*/
HTTP_EVENT(FD_CONNECT,
          {
        INTEGER(connect_type);
          })

HTTP_EVENT(FD_WRITE,
          {
          INTEGER(write_counter);
          })

HTTP_EVENT(FD_READ,
	  {
	  INTEGER(read_counter);
	  })

HTTP_EVENT(FD_Qos,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_NETCONNECT,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_NETCLOSE,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_Qos_SOCKETCLOSED,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_Qos_REMOTECLOSED,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_Qos_HOSTUNREACHED,
          {
         INTEGER(a);
          })

HTTP_EVENT(FD_GETHOSTIP,
          {
         INTEGER(a);
          })
			  			  
HTTP_EVENT(SendDataRequest,
		  {
			INTEGER(method_type);
		  })

HTTP_EVENT(ReceiveDataRequest,
		  {
			INTEGER(method_type);
		  })

/*
 *添加该事件的目的只是测试多余的FD_READ事件，和系统没有关系
 *add by shoumingl,/9/13/2004
 */
HTTP_EVENT(TestFD_READ,
		  {
			  INTEGER(method_type);
		  })

/*
重定向事件
*/
HTTP_EVENT(RedirectRequest,
		  {
			  INTEGER(redirect_code);
		  })
/*上层调用事件*/
/*
浏览器放弃当前下载
*/
HTTP_EVENT(BrowserAbort,
		  {
			INTEGER(abort_reason);
		  }) 
/*
启动浏览器
*/
HTTP_EVENT(HTTPBrowserStart,
		  {
			INTEGER(a);
		  })
/*
HTTP请求事件
*/
HTTP_EVENT(HTTPMethodInvokeRequest,
		  {	
		 INTEGER(method_type);
          })
/*下载异常，状态机复位*/
HTTP_EVENT(ExceptionDealing,
		  {	
		 INTEGER(a);
          })
/*请求错误*/
HTTP_EVENT(RequestErro,
		  {	
		 INTEGER(a);
          })

HTTP_EVENT(TimerOut,
		  {	
		 INTEGER(a);
          })

HTTP_EVENT(ResumeMachineStateToWaiting,
		  {	
		 INTEGER(a);
          })

//发生浏览器ABORT事件，目的是进行新的下载任务事件
HTTP_EVENT(NewDownLoadTaskAbort,
		  {	
		 INTEGER(a);
          })

//发送失败，
HTTP_EVENT(FD_WRITE_FAILED,
		  {	
		 INTEGER(a);
          })

//发送java下载报告事件，
HTTP_EVENT(SEND_JAVA_REPORT,
		  {	
		 INTEGER(a);
          })

HTTP_EVENT(JAVA_REPORT_RESUME,
		  {	
		 INTEGER(a);
          })
#undef HTTP_EVENT
#undef INTEGER
#undef SESSION_MACHINE
#undef HTTPHEADER
