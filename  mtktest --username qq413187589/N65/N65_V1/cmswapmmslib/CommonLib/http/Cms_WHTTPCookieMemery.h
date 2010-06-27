/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTPCookieMemery.h

功能描述		: this module provides a simple HTTP Cookie managerment according to 
					viutual memery file system

最近修改时间	: 9/16/2004
 
代码编写人员	: shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _CMS_WHTTPCOOKIEMANAGE_H
#define _CMS_WHTTPCOOKIEMANAGE_H

#include "Cms_WHTTPCookie.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOTALDOMAINS					30
#define DOMAINMAXLEN					40
#define PATHMAXLEN						150
#define CMS_HTTP_FILE int
	
#define FORMAT_STATION_SEPERATE			8
#define HEAD_DOMAIN_SEPERATE			16
#define DOMAIN_PATH_SEPERATE			1000

#define DOMAIN_NUMS_FIELD_BYTES			4	
#define FORMAT_FLAG_FIELD_BYTES			4	
#define DOMAIN_TAIL_FIELD_BYTES			4
#define PATH_TAIL_FIELD_BYTES			4
	
#define DOMAIN_LEN_FIELD_BYTES			4
#define DOMAIN_TAG_FIELD_BYTES			4

#define PATH_LEN_FIELD_BYTES			4
#define EXPIRE_LEN_FIELD_BYTES			4
#define COOKIE_NAME_LEN_FIELD_BYTES		4
#define PATH_TAG_FIELD_BYTES			4

#define COOKIE_BUF_FORMAT_FLAG 1224
/*_CookiePathNode 内存path节点*/
struct _CookiePathNode
{
	unsigned char *path;
	unsigned char *cookieName;
	unsigned char *expire;
	struct _CookiePathNode *next;
	int           next_path_offset;
};
typedef struct _CookiePathNode CookiePathNode;

/*_CookiePathNode 内存domain节点*/
struct _CookieHostNode
{
	int path_offset;
	unsigned char	*domain;
	struct _CookieHostNode *next;
	CookiePathNode	*sonNode;
};
typedef	struct _CookieHostNode CookieHostNode;

struct _cookiebuf
{
	int numbers_domain;		/*记录domain的数目*/
	int format_flag;		/*记录内存块格式化标记*/
	int domain_tail;		/*记录domain域尾部位置*/
	int path_tail;			/*记录path域尾部位置*/
	
	unsigned char *buffer;	/*从centel获取的内存块首地址*/
	unsigned int  length;	/*从centel获取的内存块长度*/
};
typedef struct _cookiebuf Cms_cookie_buf;

typedef enum
{
	CMS_JANUARY = 1,
	CMS_FEBRUARY ,
	CMS_MARCH,
	CMS_APRIL,
	CMS_MAY,
	CMS_JUNE,
	CMS_JULY,
	CMS_AUGUST,
	CMS_SEPTEMBER,
	CMS_OCTOBER,
	CMS_NOVEMBER,
	CMS_DECEMBER
} month_e;

typedef enum
{
	CMS_MONDAY = 1,
	CMS_TUESDAY,
	CMS_WEDNESDAY,
	CMS_THURSDAY,
	CMS_FRIDAY,
	CMS_SATURDAY,
	CMS_SUNNDAY
} week_e;
/*
 *	保存所有的cookie信息,全部刷新保存
 */
// void cms_SaveCookie(void); //  Modified by TIPrj[2005/7/5]
CMS_BOOL match2strHead(const CMS_U8 *cookiePath,const CMS_U8 *fetchPath);
extern int cms_manage_set_cookie(HTSETCookie * pSetCookie);
extern int cms_manage_cookie(unsigned char *cookie);
#ifdef __cplusplus
};
#endif

#endif