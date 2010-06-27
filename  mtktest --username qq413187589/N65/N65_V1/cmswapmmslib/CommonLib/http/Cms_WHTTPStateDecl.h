/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTPSateDecl.h

功能描述		: HTTP状态宏定义文件,只在定义HTTPMachine时用到

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
/*针对wap2.0特点 & socket异步处理方式*/
STATE_NAME(HTTP_NULL)
STATE_NAME(HTTP_NET_CONNECTING)
STATE_NAME(HTTP_WAITING)
STATE_NAME(HTTP_WAITING_IP)
STATE_NAME(HTTP_CONNECTING)
STATE_NAME(HTTP_CONNECTED)
STATE_NAME(HTTP_SENDDATA) // 数据发送状态，可能会和服务器congestion，如果此时对方服务器关闭，要自动重发
STATE_NAME(HTTP_WAIT_COMPLETE)//增加等待SOCKET关闭一个状态
STATE_NAME(HTTP_WAIT_JAVA_REPORT_RESPONSE)
/*********************************************************/
ROW(HTTP_NULL,
	HTTPBrowserStart,
	1,
	{
	/*进行网络连接*/
    	null_browserstart_netcnting(machine,current_event);
	},
	HTTP_NET_CONNECTING)

ROW(HTTP_NET_CONNECTING,
	RequestErro,
	1,
	{
	/*
	请求非法
	*/
//		netcnting_RequestErro_null(machine,current_event);
	},
	HTTP_NET_CONNECTING)

ROW(HTTP_WAITING,
	RequestErro,
	1,
	{
	/*
	请求非法
	*/
//		netcnting_RequestErro_null(machine,current_event);
	},
	HTTP_WAITING)
	
ROW(HTTP_NET_CONNECTING,
	FD_NETCONNECT,
	1,
	{
	/*
	网络连接成功,空操作
	*/
		netcnting_netconnect_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_NULL,
	FD_NETCLOSE,
	1,
	{
	/*
	网络连接成功,空操作
	*/
		null_netclose_null(machine,current_event);
	},
	HTTP_NULL)
	
ROW(HTTP_NET_CONNECTING,
	FD_NETCLOSE,
	1,
	{
	/*
	网络连接成功,空操作
	*/
		netcnting_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_WAITING,
	FD_NETCLOSE,
	1,
	{
	/*
	网络disconnect
	*/
		waiting_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_WAITING_IP,
	FD_NETCLOSE,
	1,
	{
	/*
	网络disconnect
	*/
		waitingip_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_CONNECTING,
	FD_NETCLOSE,
	1,
	{
	/*
	网络disconnect
	*/
		cnting_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_CONNECTED,
	FD_NETCLOSE,
	get_download_state() != CMS_YES,
	{
	/*
	网络disconnect
	*/
		cnted_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_CONNECTED,
	FD_NETCLOSE,
	get_download_state() == CMS_YES,
	{
	/*
	网络disconnect
	*/
		cnted_ok_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_SENDDATA,
	FD_NETCLOSE,
	1,
	{
	/*
	网络disconnect
	*/
		cnted_netclose_null(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_WAIT_COMPLETE,
	FD_NETCLOSE,
	1,
	{
	/*
	网络disconnect
	*/
		cnted_netclose_null(machine,current_event);
	},
	HTTP_NULL)


/*	网页请求*/
ROW(HTTP_WAITING,
	HTTPMethodInvokeRequest,
	1,
	{
		 waiting_htrequest_waitingip(machine,current_event);
	},
	HTTP_WAITING_IP)

ROW(HTTP_WAITING_IP,
	FD_GETHOSTIP,
	1,
	{
		 waitingip_getip_connecting(machine,current_event);
	},
	HTTP_CONNECTING)

ROW(HTTP_CONNECTING,
	FD_CONNECT,
	1,
	{
//		cnting_connect_connected(machine,current_event);
	},
	HTTP_CONNECTED)

ROW(HTTP_CONNECTED,
	SendDataRequest,
	1,
	{
		sending_request_connected(machine,current_event);
	},
	HTTP_SENDDATA)

//=============主要针对一次连接多次请求的情况
ROW(HTTP_SENDDATA,//如果和服务器响应发生冲突，需要自动重发
	FD_Qos_REMOTECLOSED,
	1,
	{	
		cnted_remoteclosed_waiting(machine,current_event);
	},
	HTTP_SENDDATA)

ROW(HTTP_SENDDATA,//如果和服务器响应发生冲突，需要自动重发
	FD_WRITE,
	1,
	{	
		senddata_remoteclosed_senddata(machine,current_event);
	},
	HTTP_SENDDATA)
ROW(HTTP_SENDDATA,//如果和服务器响应发生冲突，需要自动重发
	FD_WRITE_FAILED,
	1,
	{	
		senddata_sendfailed_waiting(machine,current_event);
	},
	HTTP_WAITING)	
ROW(HTTP_SENDDATA,//如果和服务器响应发生冲突，需要自动重发
	FD_Qos_SOCKETCLOSED,
	1,
	{	
		sending_autoRetry_waiting(machine,current_event);
	},
	HTTP_WAITING)
//============	

ROW(HTTP_SENDDATA,//如果有第一次Read事件来，说明没有发生冲突，驱动回正常状态
	FD_READ,
	1,
	{	
		cnted_read_receving(machine,current_event);
	},
	HTTP_CONNECTED)

ROW(HTTP_CONNECTED,
	FD_READ,
	1,
	{	
		cnted_read_receving(machine,current_event);
	},
	HTTP_CONNECTED)


ROW(HTTP_CONNECTED,
	FD_Qos,
	1,
	{
//		cnted_qos_waiting(machine,current_event);
	},
	HTTP_WAITING)

//处理当服务器连接不上的异常情况,服务器关闭事件一律不改变状态
ROW(HTTP_CONNECTING,
	FD_Qos_REMOTECLOSED,
	1,
	{
		cnting_remoteclosed_waiting(machine,current_event);
	},
	HTTP_CONNECTING)
ROW(HTTP_CONNECTING,
	FD_Qos_SOCKETCLOSED,
	1,
	{
		cnting_qos_socketclosed_waiting(machine,current_event);
	},
	HTTP_WAITING)
	
//注:当服务器关闭消息到后，不改变状态，由本地socket关闭事件来处理
ROW(HTTP_CONNECTED,
	FD_Qos_REMOTECLOSED,
	1,
	{
		cnted_remoteclosed_waiting(machine,current_event);
	},
	HTTP_CONNECTED)

ROW(HTTP_CONNECTED,
	FD_Qos_SOCKETCLOSED,
	1,
	{
		cnted_fd_qos_socketclosed_waiting(machine,current_event);
	},
	HTTP_WAITING)

//注:当服务器关闭消息到后，不改变状态，由本地socket关闭事件来处理
ROW(HTTP_WAIT_COMPLETE,
	FD_Qos_REMOTECLOSED,
	1,
	{
		//昨天调的时候，这个是关闭的
		cnted_remoteclosed_waiting(machine,current_event);
	},
	HTTP_WAIT_COMPLETE)

ROW(HTTP_WAIT_COMPLETE,
//	FD_Qos_REMOTECLOSED,
	FD_Qos_SOCKETCLOSED,
	1,
	{
		abort_loading_remoteclosed_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTING,
	FD_Qos_HOSTUNREACHED ,
	1,
	{
		cnting_hostunreached_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_WAITING,
	BrowserAbort,
	1,
	{
		waiting_browserabort_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_WAITING_IP,
	BrowserAbort,
	1,
	{
		waitingip_browserabort_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTING,
	BrowserAbort,
	1,
	{
		cnting_browserabort_waiting(machine,current_event);
	},
	HTTP_WAITING)


ROW(HTTP_CONNECTED,
	BrowserAbort,
	1,
	{
		cnted_browserabort_waiting(machine,current_event);
	},
	HTTP_WAITING)

	//注意，后继不能是HTTP_WAIT_COMPLETE
ROW(HTTP_WAITING_IP,
	NewDownLoadTaskAbort,
	1,
	{
		cnted_browserabort_waiting(machine,current_event);
	},
	HTTP_WAITING)
	
ROW(HTTP_CONNECTING,
	NewDownLoadTaskAbort,
	1,
	{
		cnted_browserabort_waiting(machine,current_event);
	},
	HTTP_WAIT_COMPLETE)

ROW(HTTP_SENDDATA,
	NewDownLoadTaskAbort,
	1,
	{
		cnted_browserabort_waiting(machine,current_event);
	},
	HTTP_WAIT_COMPLETE)
	
ROW(HTTP_CONNECTED,
	NewDownLoadTaskAbort,
	1,
	{
		cnted_browserabort_waiting(machine,current_event);
	},
	HTTP_WAIT_COMPLETE)

ROW(HTTP_WAITING_IP,
	ExceptionDealing,
	1,
	{
//		ExceptionDealing_waiting(machine,current_event);
	},
	HTTP_WAITING)
	
ROW(HTTP_CONNECTING,
	ExceptionDealing,
	1,
	{
//		ExceptionDealing_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTED,
	ExceptionDealing,
	1,
	{
//		ExceptionDealing_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTED,
	ResumeMachineStateToWaiting,
	1,
	{
	},
	HTTP_WAITING)
ROW(HTTP_CONNECTING,
	ResumeMachineStateToWaiting,
	1,
	{
	},
	HTTP_WAITING)
ROW(HTTP_WAITING_IP,
	ResumeMachineStateToWaiting,
	1,
	{
	},
	HTTP_WAITING)

#ifdef SUPPORT_HTTP_TIMER
	
ROW(HTTP_NET_CONNECTING,
	TimerOut,
	1,
	{
		waiting_FD_NETCONNECT_timeOut(machine,current_event);
	},
	HTTP_NULL)

ROW(HTTP_WAITING_IP,
	TimerOut,
	1,
	{
		waiting_FD_GETHOSTIP_timeOut(machine,current_event);
	},
	HTTP_WAITING)
	
ROW(HTTP_CONNECTING,
	TimerOut,
	1,
	{
		waiting_FD_CONNECT_timeOut(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_SENDDATA,
	TimerOut,
	1,
	{
		waiting_FD_READ_timeOut(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_WAIT_COMPLETE,
	TimerOut,
	1,
	{
		waiting_SOCKETCLOSE_timeOut(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTED,
	TimerOut,
	getCurrentSocketID() == -1,
	{
		cnted_SOCKETCLOSE_timeOut(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTED,
	TimerOut,
	1,
	{
		waiting_FD_READ_timeOut(machine,current_event);
	},
	HTTP_WAITING)
	
ROW(HTTP_SENDDATA,
	SEND_JAVA_REPORT,
	1,
	{
	},
	HTTP_WAIT_JAVA_REPORT_RESPONSE)

ROW(HTTP_WAIT_JAVA_REPORT_RESPONSE,//如果有第一次Read事件来，说明没有发生冲突，驱动回正常状态
	FD_READ,
	1,
	{	
		response_read_receving(machine,current_event);
	},
	HTTP_CONNECTED)

ROW(HTTP_WAIT_JAVA_REPORT_RESPONSE,
	TimerOut,
	Content_Buffer.JavaReportSendAgain == 0,
	{
		waitingResponse_TimerOut_waitingResponse(machine,current_event);
	},
	HTTP_WAIT_JAVA_REPORT_RESPONSE)
	
ROW(HTTP_WAIT_JAVA_REPORT_RESPONSE,
	TimerOut,
	Content_Buffer.JavaReportSendAgain != 0,
	{
		waitingResponse_TimerOut_waitingResponse(machine,current_event);
	},
	HTTP_CONNECTED)

//注:当服务器关闭消息到后，不改变状态，由本地socket关闭事件来处理
ROW(HTTP_WAIT_JAVA_REPORT_RESPONSE,
	FD_Qos_REMOTECLOSED,
	1,
	{
		//昨天调的时候，这个是关闭的
		cnted_remoteclosed_waiting(machine,current_event);
	},
	HTTP_WAIT_JAVA_REPORT_RESPONSE)

ROW(HTTP_WAIT_JAVA_REPORT_RESPONSE,
	FD_Qos_SOCKETCLOSED,
	1,
	{
		// 需要处理一些界面上的问题和内存的释放
		// 当做下载失败处理
		wait_java_response_socketclosed_waiting( machine, current_event );
//		abort_loading_remoteclosed_waiting(machine,current_event);
	},
	HTTP_WAITING)

ROW(HTTP_CONNECTED,
	JAVA_REPORT_RESUME,
	1,
	{
	},
	HTTP_WAIT_JAVA_REPORT_RESPONSE)

#endif

#undef STATE_NAME
#undef ROW
