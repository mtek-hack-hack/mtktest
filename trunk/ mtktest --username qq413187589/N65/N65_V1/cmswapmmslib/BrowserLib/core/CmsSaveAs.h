/*================================================================

文件名			: CmsSaveAs.h

功能描述		: 页面保存模块功能及接口函数定义

最近修改时间	: 11/19/2004
 
代码编写人员	: 潘正海

================================================================*/

#ifndef _CMS_SAVEAS_H_
#define _CMS_SAVEAS_H_

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

/*========================= 函数定义 =======================*/
int Cms_LocalPageLoad( unsigned char *title, /* (in) title */ 
					   unsigned char *url,	 /* (int) url */
					   unsigned char *buf,   /* (in)data buf 不要释放内容 */
					   unsigned int  len	 /* (in)buf length */);

int Cms_Browser_SavePageEvent(CMS_BROWSER_VOID);


CMS_BROWSER_RET Cms_Browser_AddSavePage(P_CMS_BROWSER_U8 title);
int AddFileList( char* filename, int type );
char* GetNameFromFileList(int filenum);
int GetTypeFromFileList(int filenum);

CMS_BROWSER_RET Cms_Browser_TestLocalEvent(void);
char* GetSnapShotPtr( void );


#endif