/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsWBMP.h

功能描述		: WBMP解析排版模块功能及接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSWBMP_H
#define CMSWBMP_H


/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

int CmsDrawWbmp( char *filename,int xPosition,int yPosition,int screenwidth);
CMS_BROWSER_RET Cms_Browser_GetWBMPDimensiont(P_CMS_BROWSER_U8 filename, /*CMS_BROWSER_U32 filelen,*/ P_CMS_BROWSER_U32 w, P_CMS_BROWSER_U32 h);

/*========================= 函数定义 =======================*/

#endif
