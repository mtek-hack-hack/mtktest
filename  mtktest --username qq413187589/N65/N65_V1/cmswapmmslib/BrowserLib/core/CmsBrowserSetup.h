/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBrowserSetup.h

功能描述		: 设置模块功能及接口函数定义

最近修改时间	: 11/4/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSBROWSERSETUP_H
#define CMSBROWSERSETUP_H

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

/*========================= 函数定义 =======================*/

CMS_BROWSER_RET	 Cms_Browser_GetBrowserSetup(P_CMSBROWSERSETUP setup);
CMS_BROWSER_VOID Cms_Browser_GetBrowserSetupFromFile(CMS_BROWSER_VOID);
CMS_BROWSER_RET	 Cms_Browser_SaveBrowserSetupToFile(CMS_BROWSER_VOID);
CMS_BROWSER_RET	 Cms_Browser_SaveBrowserSetup(P_CMSBROWSERSETUP setup);

CMS_BROWSER_VOID Cms_Browser_SetupCacheON(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_SetupCacheOFF(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetCacheSetup(CMS_BROWSER_VOID);

CMS_BROWSER_VOID Cms_Browser_LanguageEN(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_LanguageCN(CMS_BROWSER_VOID);

CMS_BROWSER_VOID Cms_Browser_SetupImgOn(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_SetupImgOff(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetImgSetup(CMS_BROWSER_VOID);

void CmsGetImgDisplaySetting( void );

CMS_BROWSER_VOID Cms_Browser_GetHomepageSetup(P_CMS_BROWSER_U8 Phomepage);
CMS_BROWSER_VOID Cms_Browser_GetGateWaySetup(P_CMS_BROWSER_U8 GateWay, P_CMS_BROWSER_U8 Port);

CMS_BROWSER_VOID Cms_Browser_SetupHomePage(P_CMS_BROWSER_U8);
CMS_BROWSER_VOID Cms_Browser_SetupPort(P_CMS_BROWSER_U8);
CMS_BROWSER_VOID Cms_Browser_SetupGateWay(P_CMS_BROWSER_U8);

int	CmsIsPageTimer( void );

void Set_WmlOnEventFlag( void );
void Clear_WmlOnEventFlag( void );
int Is_WmlOnEventFlag( void );

void Set_GoPrevFlag( void );
void Clear_GoPrevFlag( void );
int Is_GoPrevFlag( void );

void Set_NoBackWardFlag( void );
void Clear_NoBackWardFlag( void );
int  Is_NobackWardFlag( void );

void Set_HtmlFlag( void );
void Clear_HtmlFlag( void );
int Is_HtmlFlag( void );


void Set_WapIdleState( void );
void Set_WapDownloadItemState( void );
void Set_WapDownloadState( void );

void Set_JavaSetupReportFlag( void );
void Clear_JavaSetupReportFlag( void );
int  Is_JavaSetupReportFlag( void );

void CmsSetAbortFlag( void );
void CmsClearAbortFlag( void );
int IsAbortFlag( void );

void Clear_DownloadProgress( void );
void SaveDownloadRateOfProcess(int total,int cur,int typeID,int resultDownload);
void RestDownloadRateOfProcess( void );


int Cms_IsBrowserRunning( void );

void Cms_SetEmptyPageFlag( void );
void Cms_ClearEmptyPageFlag( void );
int  Cms_IsEmptyPageFlag( void );

void Cms_SetLayoutImageFlag( void );
void Cms_ClearLayoutImageFlag( void );
int Cms_IsLayoutImage( void );

void Set_InsertHistoryFlag(void);
void Clear_InsertHistoryFlag(void);
int  IsNeedToInsertHistory(void);

void ClearRefreshWhenGoPrev( void );
void SetRefreshWhenGoPrev( void );
int  IsRefreshWhenGoPrev( void );

#endif
