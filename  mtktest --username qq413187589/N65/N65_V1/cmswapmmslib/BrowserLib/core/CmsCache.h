/*================================================================
 
文件名			: CmsCache.h

功能描述		: Cache模块得功能及接口函数定义

最近修改时间	: 08/11/2004
 
代码编写人员	: 潘正海

================================================================*/

#ifndef CMSNEWCACHE_H_
#define CMSNEWCACHE_H_

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"
#include "cmshttp.h"
#include "CmsCacheHeap.h"
#include "cms_time.h"


/******************结构定义**********************************/
struct CmsCacheTag;
typedef struct CmsCacheTag CmsCacheT;

struct CmsCacheTag
{
	char*		url; 
	Cms_ContentType_e	file_type;
	Cms_EncodingType_e	fileencoding;
	time_t		        expiretime;
	CACHEFILE_HANDLE    fd;	

	CmsCacheT*			next;
};

/*========================= 函数定义 =======================*/



void CmsSetCacheFlag( void );
void CmsClearCacheFlag( void );
int  CmsIsSupportCache( void );
int  CmsIsAddToCache( void );

#endif