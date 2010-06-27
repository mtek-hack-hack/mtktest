#ifndef CMSBRWTCENPROVIDE_H
#define CMSBRWTCENPROVIDE_H


#include "CmsBrowserPublic.h"


extern CMS_BROWSER_U32 Cms_GetCharacterWidth(CMS_BROWSER_U8 font,CMS_BROWSER_U16 Utf16);

extern void Cms_DrawErrorImg(int x, int y);

//extern CMS_BROWSER_BOOL Cms_Browser_DrawRect(CMS_BROWSER_U32 x, CMS_BROWSER_U32 y, CMS_BROWSER_U32 width, CMS_BROWSER_U32 height, CMS_BROWSER_BOOL Clear);

extern CMS_BROWSER_VOID    Cms_Browser_TimeDelay(CMS_BROWSER_U16 millisecond);
extern void Cms_SetUseragent(unsigned char * u_a);
//extern CMS_BROWSER_VOID Cms_Browser_RefreshScreen(CMS_BROWSER_VOID);
#endif