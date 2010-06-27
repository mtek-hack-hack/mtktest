/************************************************************************* 
 * Copyright (c) 2000-2003 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-7-22   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn    	    	
 * 文  件：  cms_debug.h 	
 * 描  述：	调试函数定义
 ************************************************************************/

#ifndef _CMS_DEBUG_H
#define _CMS_DEBUG_H

#include "CmsPlatFormCFG.h"

/***************************************************************************** 
* 版本发布相关宏定义
*****************************************************************************/
/*
1.客户项目前期可自行设定UA,此时为DEBUG版本,开启CMS_DEBUG_VERSION
2.正式版本发布,开启CMS_CUSTOM_UA 同时关闭CMS_DEBUG_VERSION	(联想所有项目)
3.项目维护期,客户不可修改UA.关闭CMS_CUSTOM_UA和CMS_DEBUG_VERSION
4.目标版本TRACE 开关为CMS_TARGET_TRACE
5.浏览器排版方式宏为CMS_FOCUS_LOOP
*/
//#define CMS_DEBUG_VERSION 	/*DEBUG版本,限制浏览器显示标题和彩信有效期*/
#define CMS_CUSTOM_UA		/*Custom 设定UA	*/
#define CMS_TARGET_TRACE	/*目标版本TRACE开关*/

#define CMS_FOCUS_LOOP 	/*焦点循环操作*/
//#define NO_SUPPORT_JAVA	/*不支持JAVA下载*/



/***************************************************************************** 
* TRACE 相关函数
*****************************************************************************/
void _cms_trace(char* str,...);
void _cms_trace_data(unsigned char *data, int datalen);
void mms_Tracer(char *);


#ifdef WIN32

void cms_clear_trace( void );


	#ifdef CMS_TARGET_TRACE
		/* WIN32平台显示trace信息 */
		#define cms_trace	_cms_trace
		//#define cms_trace_data	_cms_trace_data
		#define cms_trace_data
	#else
		/* 目标平台关闭trace信息 */
		#define cms_trace
		#define cms_trace_data


	#endif	


#else

	#ifdef CMS_TARGET_TRACE
		/* 目标平台显示trace信息 */
		#define cms_trace	_cms_trace
		#define cms_trace_data	//_cms_trace_data

	#else
		/* 目标平台关闭trace信息 */
		#define cms_trace
		#define cms_trace_data
		#define Cms_Browser_Assert(expression, str) 
		#define Cms_Browser_ClearAssertInfo()

	#endif	

#endif


#endif /*_CMS_DEBUG_H*/
