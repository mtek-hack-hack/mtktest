/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsPendown.c

功能描述		: 触摸屏按键模块功能及接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSPENDOWN_H
#define CMSPENDOWN_H

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

/*========================= 函数定义 =======================*/

CMS_BROWSER_RET Cms_Browser_PenDownEvent(CMS_BROWSER_U16 x, CMS_BROWSER_U16 y);
CMS_BROWSER_BOOL Cms_Browser_GetEditStyle(P_CMS_BROWSER_U32 pMaxlength);
P_CMS_BROWSER_U8 Cms_Browser_GetOriginParam(CMS_BROWSER_VOID);

/*=====================================================*/


#endif
