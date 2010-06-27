/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsFunc.h

功能描述		: mBrowser和目标OS的底层接口函数定义

最近修改时间	: 10/17/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSFUNC_H
#define CMSFUNC_H

/***************************************************************/

#include "CmsBrowserPublic.h"
#include "cms_sysfun.h"
#include "CmsHttp.h" //only for Cms_ContentType_e

/***************************************************************/

#ifdef __cplusplus 
extern "C" {
#endif
	
/*==============================================================*/
/*						 System Operation					    */
/*==============================================================*/

P_CMS_BROWSER_VOID Cms_Browser_Malloc(CMS_BROWSER_U32 length);
//CMS_BROWSER_VOID   cms_free(P_CMS_BROWSER_VOID FreeMem);
P_CMS_BROWSER_VOID Cms_Browser_MemSet(P_CMS_BROWSER_VOID dest,  CMS_BROWSER_S32 c, CMS_BROWSER_U32 count);
P_CMS_BROWSER_VOID Cms_Browser_MemCpy(P_CMS_BROWSER_VOID dest, P_CMS_BROWSER_VOID src, CMS_BROWSER_U32 count);
P_CMS_BROWSER_VOID Cms_Browser_MemMove(P_CMS_BROWSER_VOID dest, P_CMS_BROWSER_VOID src, CMS_BROWSER_U32 count);

CMS_BROWSER_S32 Cms_Browser_MemCmp( P_CMS_BROWSER_VOID dest, 
								   P_CMS_BROWSER_VOID src, 
								   CMS_BROWSER_U32 count );

P_CMS_BROWSER_U8   Cms_Browser_StrUpr(P_CMS_BROWSER_U8 string);
CMS_BROWSER_U32    Cms_Browser_StrLen(P_CMS_BROWSER_U8 string);
P_CMS_BROWSER_U8   Cms_Browser_StrCpy(P_CMS_BROWSER_U8 destStr, P_CMS_BROWSER_U8 srcStr);
P_CMS_BROWSER_U8   Cms_Browser_StrNCpy(P_CMS_BROWSER_U8 destStr, P_CMS_BROWSER_U8 srcStr, CMS_BROWSER_U32 count);
P_CMS_BROWSER_U8   Cms_Browser_StrStr(P_CMS_BROWSER_U8 string, P_CMS_BROWSER_U8 be_searched);
CMS_BROWSER_S32    Cms_Browser_StrCmp(P_CMS_BROWSER_U8 string1, P_CMS_BROWSER_U8 string2);
CMS_BROWSER_S32    Cms_Browser_StrNCmp(P_CMS_BROWSER_U8 string1, P_CMS_BROWSER_U8 string2, CMS_BROWSER_U32 count);
P_CMS_BROWSER_U8   Cms_Browser_StrCat(P_CMS_BROWSER_U8 destStr, P_CMS_BROWSER_U8 srcStr);
P_CMS_BROWSER_U8   Cms_Browser_StrNCat(P_CMS_BROWSER_U8 destStr, P_CMS_BROWSER_U8 srcStr, CMS_BROWSER_U32 count);
CMS_BROWSER_U32    Cms_Browser_atoi(P_CMS_BROWSER_U8 string);
CMS_BROWSER_U64    Cms_Browser_atol(P_CMS_BROWSER_U8 string);
P_CMS_BROWSER_U8   Cms_Browser_ltoa(CMS_BROWSER_U64 value, P_CMS_BROWSER_U8 result);
CMS_BROWSER_VOID   Cms_Browser_Sprintf(P_CMS_BROWSER_U8 content, P_CMS_BROWSER_U8 mode, CMS_BROWSER_U32 value);
CMS_BROWSER_S32	   Cms_Browser_UpCmpStr(P_CMS_BROWSER_U8 s1, P_CMS_BROWSER_U8 s2);

/*============================================================*/
/*							GUI Operation					  */
/*============================================================*/
void Cms_Browser_CreateImgFilename(void);
CMS_BROWSER_U32 Cms_Browser_GetStringWidth(CMS_BROWSER_U8 font, P_CMS_BROWSER_U8 string);
CMS_BROWSER_BOOL Cms_Browser_DrawPoint(CMS_BROWSER_U32 x, CMS_BROWSER_U32 y, CMS_BROWSER_U32 color);
void Cms_DrawErrorImg(int x, int y);

int Cms_Browser_DrawLine(int x, int y, int length, int Horizontal) ;

int Cms_Browser_ClearRect(unsigned int x, unsigned int y, 
						  unsigned int width, unsigned int height,
						  unsigned int BackGroudColor);
int Cms_Browser_DrawRect(int x, int y, int width, int height, int Clear);

int Cms_DrawString(	unsigned char font_type,
								int x,
								int y,
								unsigned char *string,
								int space,
								unsigned int color,
								unsigned char Mark,
								int isAnchor,
								unsigned char updateflag);
void Cms_DrawRectBgColor( int x, 
						  int y, 
						  int width, 
						  int height,
						  int BackGroudColor);

void Cms_ChangeFont(unsigned int new_color, unsigned char new_type );

/*============================================================*/
/*							Time Operation					  */
/*============================================================*/

CMS_BROWSER_VOID Cms_Browser_TimeDelay(CMS_BROWSER_U16 millisecond);
CMS_BROWSER_BOOL Cms_Browser_SetTimer(CMS_BROWSER_OS_TIMER timer, CMS_BROWSER_U16 timeout);
CMS_BROWSER_BOOL Cms_Browser_DestroyTimer(CMS_BROWSER_OS_TIMER timer);
CMS_BROWSER_BOOL Cms_Browser_TimerExpire(CMS_BROWSER_OS_TIMER timer, CMS_BROWSER_U32 timeid);
void mms_StartTimer(unsigned char id,long ms);
void mms_StopTimer (unsigned char id);
//6.10 Dukela
CMS_BROWSER_VOID Cms_Browser_Timer4Event(CMS_BROWSER_VOID);
/*============================================================*/
/*							File Operation					  */
/*============================================================*/

CMS_BROWSER_FILEHANDLE Cms_Browser_FileOpen(P_CMS_BROWSER_U8 filename, CMS_FILE_OPENMODE mode);
CMS_BROWSER_BOOL Cms_Browser_FileHandleInvalid(CMS_BROWSER_FILEHANDLE file);
CMS_BROWSER_S64  Cms_Browser_GetFileLength(CMS_BROWSER_FILEHANDLE file);
CMS_BROWSER_BOOL Cms_Browser_FileSeek(CMS_BROWSER_FILEHANDLE stream, CMS_BROWSER_S64 offset, CMS_BROWSER_S32 origin);
CMS_BROWSER_BOOL Cms_Browser_FileClose(CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_VOID Cms_Browser_FileDelete(P_CMS_BROWSER_U8 filename);
CMS_BROWSER_S32	 Cms_Browser_FileWrite(P_CMS_BROWSER_U8 buffer, CMS_BROWSER_S32 size, CMS_BROWSER_S32 count, CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_S32	 Cms_Browser_FileRead(P_CMS_BROWSER_U8 buffer, CMS_BROWSER_S32 size, CMS_BROWSER_S32 count, CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_S32  Cms_Browser_FileGetc(CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_S32  Cms_Browser_FilePutc(CMS_BROWSER_S32 c, CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_BOOL Cms_Browser_FileEnd(CMS_BROWSER_FILEHANDLE stream);
CMS_BROWSER_BOOL Cms_Browser_SaveData2File( P_CMS_BROWSER_U8	p_file_name,
										   P_CMS_BROWSER_U8	p_data,
										   CMS_BROWSER_S32		data_len);


/*============================================================*/
/*							Network Operation				  */
/*============================================================*/
CMS_BROWSER_U16  Cms_Browser_htons(CMS_BROWSER_U16 port);

#ifdef SUPPORT_GIF//CMS_WIN32_MFC
/*============================================================*/
/*							extern function					  */
/*============================================================*/
CMS_BROWSER_BOOL CmsGIFStartTimer(CMS_BROWSER_OS_TIMER timer, CMS_BROWSER_U16 timeout);
extern CMS_BROWSER_BOOL	CmsBrowserStartTimer(CMS_BROWSER_OS_TIMER cmstimer, CMS_BROWSER_U16 timeout);
extern CMS_BROWSER_BOOL	CmsBrowserDestroyTimer(CMS_BROWSER_OS_TIMER cmstimer);
extern CMS_BROWSER_VOID	Cms_Browser_RefreshScreen(CMS_BROWSER_VOID);
extern CMS_BROWSER_VOID Cms_Browser_RefreshRect(CMS_BROWSER_U32 x, CMS_BROWSER_U32 y, CMS_BROWSER_U32 w, CMS_BROWSER_U32 h);
#endif





CMS_BROWSER_U32 CMS_Browser_GetStringPixels(P_CMS_BROWSER_U8 string);
void wap_download( void );
void Cms_DisplayState(int state);
void CmsBrwJavaJarFile(P_CMS_BROWSER_S8 ii, int jlen);
void Cms_SaveData(unsigned char * data, int datalen, Cms_ContentType_e type, int forwardtype);

 void *mms_Malloc(unsigned int length);
 void mms_Free (void *pointer);
 unsigned char * brw_GetResourceByID(int id);
 void Cms_DisplaySoftKey (unsigned char *pls, unsigned char * Rls);

 extern CMS_BROWSER_U32 Cms_GetCharacterWidth (CMS_BROWSER_U8 font,CMS_BROWSER_U16 Utf16);
/*************************************************************************
	 centel function
 ************************************************************************/
//#define _D_PARSER	/* parser test */

#ifdef __cplusplus 
}
#endif


#endif
