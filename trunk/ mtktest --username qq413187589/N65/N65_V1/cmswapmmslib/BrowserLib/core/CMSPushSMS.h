/*===============================================

C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology(NanJing) Co.,Ltd 2000-2003
 ALL RIGHTS RESERVED

=================================================

 工程名称	: CMS_mWAP Ver2.0

 文件名		: CmsPushSMS.h  

功能描述	: CMS_mWAP协议栈的PUSH SMS接口API声明
 
编写时间	: 09/25/2003

编写人员	: 乐海勇

=================================================*/

#ifndef CMSPUSHSMS_H
#define CMSPUSHSMS_H

/*===============================================*/
#include "CmsBrowserPublic.h"

/*=== PUSH消息对应AP类型 ===*/
/*===========================
			 说明:
	接口返回的AP类型中,除了
NOT_PUSH_AP和PUSH_MMS_AP,其
余类型的都需要将SMS消息体交
给WAP浏览器处理 			 
============================*/
typedef enum _PUSH_SMS_AP
{
	NOT_PUSH_AP = -1,		/*=== 不是PUSH消息 ===*/
	PUSH_ANY_AP,			/*=== 任意WAP应用 ===*/
	PUSH_SIA_AP,			/*=== PUSH SIA 应用 ===*/
	PUSH_WML_AP,			/*=== WML用户代理 ===*/
	PUSH_WTA_AP,			/*=== WTA用户代理 ===*/
	PUSH_MMS_AP,			/*=== MMS用户代理 ===*/
	PUSH_SYNCML_ALERT_AP,		/*=== SyncML Alert应用 ===*/
	PUSH_LOCATION_AP,		/*=== Location用户代理 ===*/
	PUSH_SYNCML_DM_AP,		/*=== SyncML Device Management应用 ===*/
	PUSH_DRM_AP,			/*=== DRM(Digital Rights Management)用户代理 ===*/
	PUSH_EMN_AP,			/*=== EMN(Email Notification)用户代理 ===*/
	PUSH_WV_AP			/*=== WV(Wireless Village)用户代理 ===*/
		
}PUSH_SMS_AP;


/*=============函数声明============*/

/*===查找PUSH消息对应的AP===*/
PUSH_SMS_AP CmsDispatchPush(CMS_BROWSER_U8 *PushPDU, CMS_BROWSER_U32 PDULength);
CMS_BROWSER_U32 CmsGetUnitVarValue(P_CMS_BROWSER_U8 PDU , P_CMS_BROWSER_U8 pOffset);
#endif
