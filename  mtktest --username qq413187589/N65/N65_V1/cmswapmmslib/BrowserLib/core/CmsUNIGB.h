/*==============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

==============================================================

 Project Name: mini_Browser Ver3.20
 
 File Name   : CmsUNIGB.h

 Description : Unicode and GB-2312 exchange module

 Last Modify : 02/18/2003
 
 Written By  : HaiYong Le

==============================================================*/

#ifndef CMSUNIGB_H
#define CMSUNIGB_H

/*======================== Headers File ======================*/

#include "CmsBrowserCfg.h"
#include "CmsFunc.h"




/*========================= Function =======================*/

CMS_BROWSER_VOID	Cms_Browser_Trans2UniGB(P_CMS_BROWSER_U8 input,P_CMS_BROWSER_U8 output);

CMS_BROWSER_VOID	Cms_TransUinT2GB(P_CMS_BROWSER_U8 inUIN, P_CMS_BROWSER_U8 outGB);

CMS_BROWSER_VOID	Cms_Browser_Uni_GB(CMS_BROWSER_U16 uni, P_CMS_BROWSER_U8 Uword);

void  Cms_ShowInfoBox( unsigned char* str );

#ifdef SUPPORT_UNICODE
CMS_BROWSER_VOID Cms_Browser_Trans2UTF8(P_CMS_BROWSER_U8 input, P_CMS_BROWSER_U8 output);
#endif

#endif
