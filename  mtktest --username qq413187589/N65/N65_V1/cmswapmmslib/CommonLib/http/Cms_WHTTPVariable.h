/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTPVariable.h

功能描述		: 定义工程使用变量类型

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _CMS_HTTPVARIABLE_H
#define _CMS_HTTPVARIABLE_H
#include "CmsHttp.h"
#include "cms_basedef.h"

#ifndef TI //  Modified by TIPrj[2005/6/29]
#ifdef __cplusplus
extern "C" {
#endif
#endif

#define CALLFUCERR			-1
#define CALLFUCSUC			0
#define MEMBERRY_ERRO		(int)7
#define NO_LEN_IN_RESPONSE  -2
#define PAGE_ERRO           -3
#define PARAM_ERRO		    -4
#define CONTENT_TOO_LONG    -5



#ifndef TI //  Modified by TIPrj[2005/6/29]
#ifdef __cplusplus
};
#endif
#endif

#endif