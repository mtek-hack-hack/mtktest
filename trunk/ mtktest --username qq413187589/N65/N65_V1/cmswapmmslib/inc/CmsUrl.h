#ifndef _CMSURL_H_
#define _CMSURL_H_

#include "cms_debug.h"
#include "cms_sysfun.h"
//#include "CmsBrowserPublic.h"

typedef struct _URL_TAG
{
	char * scheme;
	char * authority;
	char * path;
	char * query;
	char * fregment;
}URL,* pURL;


void initURL(void);
void freeURL(void);

//judge 判断页内url还是页外url，0 表示页内，1表示页外
unsigned char * urlstrcat(unsigned char * cururlstr, unsigned char * catstr);

int inURL(const char * str);
char * outABSURL(void);
void changeOutlineURL(const char * str);

//提供给socket 的接口
char * URLoutScheme(void);
char * URLoutAuthority(void);
char * URLoutHost(void);
char * URLoutPath(void);
char * URLoutQuery(void);
char * URLsetQuery(char * str);
char * URLoutFregment(void);

//提供给SCRIPT的接口

char * URLoutScriptScheme(char * cstr);
char * URLoutScriptAuthority(char * cstr);
char * URLoutScriptPath(char * cstr);
char * URLoutScriptQuery(char * cstr);
char * URLoutScriptFregment(char * cstr);
char * URLoutScriptHost(char * cstr);
char * URLoutScriptPort(char * cstr);
char * URLoutScriptParameters(char * cstr);
char * Eascape(const char * cstr);
char * UnEascape(const char * cstr);

//提供上层进行URL匹配
//返回0,表示完全匹配,返回-1,表示matchstr短,1,表示desstr短
int URL_matchURI(char * matchstr, char * desstr);
//返回0,表示前缀匹配完成,返回-1,表示失败
int URL_prefixURI(char * matchstr, char * desstr);

int hostscanner(char * host);
#endif
