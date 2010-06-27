/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsParser.c

功能描述		: 解析模块功能及接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSPARSER_H
#define CMSPARSER_H

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

/*========================= 函数定义 =======================*/

CMS_BROWSER_RET		Cms_Browser_ParserEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID	Cms_Browser_UpPageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID	Cms_Browser_DownPageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET		Cms_Browser_OpenLocalEvent(P_CMS_BROWSER_U8 filename);
CMS_BROWSER_VOID	Cms_Browser_SetHomepageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID	Cms_Browser_GotoHomepageEvent(CMS_BROWSER_BOOL refresh);

CMS_BROWSER_U32		CmsBRGetEleHasAttr(CMS_BROWSER_VOID* p_BR_Element, CMS_BROWSER_U32 attrid);

CMS_BROWSER_VOID Cms_Browser_DestroyJADInfomation(P_CMS_BROWSER_JAD jadinfo);
CMS_BROWSER_BOOL Cms_Browser_GetJADInfomation(P_CMS_BROWSER_U8 jadfilename, P_CMS_BROWSER_JAD jadinfo);
void CmsFreeAWMLVarList( VarlistPtr varhead );
void CmsFreeAWMLVar( VarlistPtr varhead );
VarlistPtr Cms_CreateVarList(void);


//int InitInbuf( void );
void DestroyInbuf( void );
int GetInbufLen( void );
void ResetInBuf( void );
int	Content2Inbuf(unsigned char *source, unsigned int size );
unsigned char *GetInbuf( void );
int GetInbufTotleLen( void );


int SaveContent( unsigned char *content, unsigned int len );
int ReadContent2Inbuf( void );
void DestroyContent( void );

#endif









