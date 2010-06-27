#ifndef REDIRECTFUNC_H
#define REDIRECTFUNC_H

extern void Cms_SendPDU(void *pp_data,long vp_length,unsigned char *host,int port);
extern void Cms_RecvPDU(void *pp_data,long *pp_length,unsigned char *host,int port);
extern int Brw_Jpeg_DrawPixel(unsigned char *DataBuf, int Height, int Width, int Component,
					int xPosition, int yPosition, double proportion);
extern void           Cms_SaveCookie(void);
extern unsigned  char *Cms_GetCookie(unsigned int *bufferlength); 

#ifndef brw_SendPDU
#define brw_SendPDU Cms_SendPDU
#endif

#ifndef mms_SendPDU
#define mms_SendPDU Cms_SendPDU
#endif

#ifndef mms_RecvPDU 
#define mms_RecvPDU Cms_RecvPDU
#endif

#ifndef brw_RecvPDU 
#define brw_RecvPDU Cms_RecvPDU
#endif

#ifndef CmsBrwDrawPixel
#define CmsBrwDrawPixel Brw_Jpeg_DrawPixel
#endif

#ifndef Cms_Browser_DisplayState
#define Cms_Browser_DisplayState
#endif

#ifndef Cms_Browser_DrawHZ
#define Cms_Browser_DrawHZ
#endif

#ifndef Cms_Browser_GetHZWidth
#define Cms_Browser_GetHZWidth
#endif

#ifndef Cms_Browser_GetCharWidth 
#define Cms_Browser_GetCharWidth 
#endif

#ifndef centel_getcookie
#define centel_getcookie Cms_GetCookie
#endif

#ifndef centel_savecookie
#define centel_savecookie Cms_SaveCookie
#endif

#ifndef CmsGetTime
#define CmsGetTime CmsGetCurrentTime
#endif

#endif // WAP12SOCKET_H

