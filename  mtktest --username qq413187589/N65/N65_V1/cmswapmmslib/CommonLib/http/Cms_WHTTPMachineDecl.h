/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_HTTPMachineDecl.h

功能描述		: HTTP状态机宏定义文件

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/

SESSION_MACHINE({
	INTEGER(timerid);
	INTEGER(state);
	EVENT_POINTER(http_event_saved);
	EVENT_POINTER(http_event_queue_head);
	EVENT_POINTER(http_event_queue_tail);
})

#undef INTEGER
#undef EVENT_POINTER
#undef SESSION_MACHINE
/*--Shouming 2004-7-31*/
