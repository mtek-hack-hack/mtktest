/*==============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2005
 ALL RIGHTS RESERVED

==============================================================

工程名称		: Provisioning Ver1.0
 
文件名			: CmsProvisioning.h

功能描述		: Provisioning解析模块

最近修改时间	: 02/24/2005
 
代码编写人员	: 乐海勇

==============================================================*/

#ifndef _CMSPROVISIONING_H_
#define _CMSPROVISIONING_H_

/*============================================================*/

#include "Cms_WAPMain.h"
#include "cms_sysfun.h"
#include "Cms_Debug.h" 


/*============================================================*/
// #if __cplusplus
#ifdef  __cplusplus //  Modified by TIPrj[2005/7/4]
extern "C" {
#endif
/*=================== Provisioning数据结构定义 ==================*/	

typedef struct _CMS_BOOKMARK_
{
	P_CMS_U8 pName;
	P_CMS_U8 pURL;

}CMS_BOOKMARK, *P_CMS_BOOKMARK;

typedef struct _CMS_PPP_
{
	P_CMS_U8 pAuthType;
	P_CMS_U8 pAuthName;
	P_CMS_U8 pAuthSecret;
	P_CMS_U8 pLoginType;

}CMS_PPP, *P_CMS_PPP;

typedef struct _CMS_PROXY_
{
	P_CMS_U8 pPROXY;
	P_CMS_U8 pProxyType;
	P_CMS_U8 pAuthName;
	P_CMS_U8 pAuthSecret;
	P_CMS_U8 pLoginType;

}CMS_PROXY, *P_CMS_PROXY;

typedef struct _CMS_CSD_
{
	P_CMS_U8 pDialString;
	P_CMS_U8 pCallType;
	P_CMS_U8 pCallSpeed;

}CMS_CSD, *P_CMS_CSD;

typedef struct _CMS_ADDRESS_
{
	P_CMS_U8	pBearer;
	P_CMS_U8	pPort;
	P_CMS_U8	pISPName;
	P_CMS_U8	pSMSCAddress;
	P_CMS_U8	pUSSDServiceCode;
	P_CMS_U8	pGPRSAccessPointName;
	CMS_PPP		PPP;
	CMS_CSD		CSD;
	CMS_PROXY	PROXY;

}CMS_ADDRESS, *P_CMS_ADDRESS;

typedef struct _CMS_SETTING_
{
	P_CMS_U8 pID;
	P_CMS_U8 pName;
	P_CMS_U8 pHomepage;
	P_CMS_U8 pMMSCenter;
	CMS_ADDRESS Address;
	CMS_BOOKMARK Bookmark;

}CMS_SETTING, *P_CMS_SETTING;

/*=================== 函数定义 ==================*/	

CMS_BOOL CmsGetSetting(P_CMS_SETTING pSetting);
CMS_BOOL CmsFreeSetting(P_CMS_SETTING pSetting);
CMS_BOOL CmsGetBookmark(P_CMS_BOOKMARK pBookmark);
CMS_BOOL CmsFreeBookmark(P_CMS_BOOKMARK pBookmark);

//#if __cplusplus
#ifdef __cplusplus //Modified by TIPrj[2005/6/29]
}
#endif

#endif	/*=== end of _CMSPROVISIONING_H_ ===*/