/*==============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

==============================================================

 Project Name: mini_Browser Ver3.20
 
 File Name   : CmsJPEG.h

 Description : JPEG module

 Last Modify : 05/27/2003
 
 Written By  : HaiYong Le

==============================================================*/

#ifndef CMSJPEG_H
#define CMSJPEG_H

/*======================== Headers File ======================*/

#include "CmsBrowserCfg.h"
#include "CmsFunc.h"

CMS_BROWSER_BOOL Cms_Browser_LayoutJPEG(m_ImageElement ele);
CMS_BROWSER_BOOL Cms_Browser_DrawJPEG(m_ImageElement ele);

extern int BJPGGetDimension(char *filename, int *w, int *h, void *mempool);
extern int BJPGDraw(char *filename, int x, int y, int w, int h, void *mempool);

#endif