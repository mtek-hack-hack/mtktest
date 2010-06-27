/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBRWMLScript.h

功能描述		: 缓存模块功能及接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSBRWMLSCRIPT_H
#define CMSBRWMLSCRIPT_H

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"



/*========================= 函数定义 =======================*/

CMS_BROWSER_BOOL CmsBRInitWMLScript(CMS_BROWSER_VOID);

CMS_BROWSER_U32 CmsBRLoadWMLScript(P_CMS_BROWSER_U8 pURL, 
									P_CMS_BROWSER_U8 pBC, 
									CMS_BROWSER_U32 BCLen);

CMS_BROWSER_VOID CmsBRReleaseWMLScript(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL CmsBRRunWMLScript(P_CMS_BROWSER_U8 pFunction);
void WB_SetWMLStatus( void );

CMS_BROWSER_VOID CmsBRWMLScriptEvent(P_CMS_BROWSER_U8 pURL, 
									P_CMS_BROWSER_U8 pBC, 
									CMS_BROWSER_U32 BCLen,
									unsigned char   content_type,
									P_CMS_BROWSER_U8 pFunction);/* content_type 0: bin; 1:text */

#endif
