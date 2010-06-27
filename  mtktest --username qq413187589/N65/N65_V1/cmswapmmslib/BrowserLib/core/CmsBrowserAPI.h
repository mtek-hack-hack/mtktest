/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

==================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBrowserAPI.h

功能描述		: mBrowser各模块对外接口函数定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSBROWSERAPI_H
#define CMSBROWSERAPI_H

/*======================== 公共头文件 ======================*/

#include "CmsBrowserPublic.h"

/*==========================================================*/

#ifdef __cplusplus 
extern "C" {
#endif

/*========================= 浏览器库注册接口函数定义 ===================*/
#ifdef CMS_LIBRARY
CMS_BROWSER_BOOL CmsRegisterBrowser(PBROWSER_FUNC pApp_Func);
#endif

/*========================= 设置模块接口函数定义 =======================*/

CMS_BROWSER_RET	 Cms_Browser_GetBrowserSetup(P_CMSBROWSERSETUP setup);
CMS_BROWSER_RET	 Cms_Browser_SaveBrowserSetup(P_CMSBROWSERSETUP setup);

CMS_BROWSER_VOID Cms_Browser_SetupCacheON(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_SetupCacheOFF(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetCacheSetup(CMS_BROWSER_VOID);

CMS_BROWSER_VOID Cms_Browser_LanguageEN(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_LanguageCN(CMS_BROWSER_VOID);

CMS_BROWSER_VOID Cms_Browser_SetupImgOn(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_SetupImgOff(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetImgSetup(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GetHomepageSetup(P_CMS_BROWSER_U8 Phomepage);
CMS_BROWSER_VOID Cms_Browser_GetGateWaySetup(P_CMS_BROWSER_U8 GateWay, P_CMS_BROWSER_U8 Port);

CMS_BROWSER_VOID Cms_Browser_SetupHomePage(P_CMS_BROWSER_U8);
CMS_BROWSER_VOID Cms_Browser_SetupPort(P_CMS_BROWSER_U8);
CMS_BROWSER_VOID Cms_Browser_SetupGateWay(P_CMS_BROWSER_U8);
CMS_BROWSER_VOID Cms_Browser_SetDefault_ColorFont( void );
CMS_BROWSER_U8   Cms_Browser_GetCurrent_FontType( void );
CMS_BROWSER_U32  Cms_Browser_GetCurrent_FontColor( void );

/*========================= 书签模块接口函数定义 =======================*/

CMS_BROWSER_BOOL Cms_Browser_BookmarkFull(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_GetBookmark(P_CMS_BROWSER_U8 **bookmarkcontent);
CMS_BROWSER_RET Cms_Browser_AddBookmark(P_CMS_BROWSER_U8 title);
CMS_BROWSER_RET Cms_Browser_DeleteBookmark(CMS_BROWSER_U32 ID);
CMS_BROWSER_RET Cms_Browser_LinkBookmark(CMS_BROWSER_U32 ID);
CMS_BROWSER_VOID Cms_Browser_DeleteAllBookmark(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_GetBookmarkTitle(CMS_BROWSER_U32 ID, P_CMS_BROWSER_U8 title);
CMS_BROWSER_RET Cms_Browser_GetBookmarkURL(CMS_BROWSER_U32 ID, P_CMS_BROWSER_U8 url);
CMS_BROWSER_RET Cms_Browser_RenameBookmarkTitle(CMS_BROWSER_U32 ID, P_CMS_BROWSER_U8 newTitle);
CMS_BROWSER_RET Cms_Browser_EditBookmark(CMS_BROWSER_U32 ID, P_CMS_BROWSER_U8 newTitle,P_CMS_BROWSER_U8 newUrl);

CMS_BROWSER_VOID Cms_Brw_CancelPageDownload(CMS_BROWSER_VOID);
CMS_BROWSER_U32 Cms_Brw_Get_Cancel_OK(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Brw_Set_Cancel_OK(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Brw_Clear_Cancel_OK(CMS_BROWSER_VOID);

/*========================= 缓存模块接口函数定义 =======================*/

CMS_BROWSER_BOOL Cms_Browser_AddACache(P_CMS_BROWSER_U8 data,int len, P_CMS_BROWSER_U8 addurl, CMS_BROWSER_S32 expire_time);
void			 CmsCacheInit(void);
void			 CmsCacheExit(void);
int              Cms_Browser_GetCacheData(void);
void CmsSetCacheFlag( void );
void CmsClearCacheFlag( void );
int CmsIsSupportCache( void );

/*========================= 历史记录模块接口函数定义 ===================*/

CMS_BROWSER_VOID Cms_Browser_GoPrevURIEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GoNextURIEvent(CMS_BROWSER_VOID);

P_CMS_BROWSER_U8 Cms_Browser_GeUItHistoryTitle(CMS_BROWSER_U8);
P_CMS_BROWSER_U8 Cms_Browser_GetUIHistoryUrl(CMS_BROWSER_U8 ID);
void Cms_Browser_UILinkPageHistory(CMS_BROWSER_U8);

/*========================= 初始化模块接口函数定义 =====================*/

CMS_BROWSER_RET Cms_Browser_StartEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_ExitEvent(CMS_BROWSER_VOID);


/*========================= URL输入模块接口函数定义 ====================*/

P_CMS_BROWSER_U8 *Cms_Browser_GetInputHistoryEvent(CMS_BROWSER_VOID);
P_CMS_BROWSER_U8 Cms_Browser_GetCurrentInputHistory(CMS_BROWSER_U32 inputid);
CMS_BROWSER_RET Cms_Browser_ModifyCurrentInputHistroy(CMS_BROWSER_U32 inputid, P_CMS_BROWSER_U8 newuri);
CMS_BROWSER_BOOL Cms_Browser_InputHistoryFull(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_AddInputHistoryEvent(P_CMS_BROWSER_U8 newuri);
CMS_BROWSER_RET Cms_Browser_DeleteInputHistoryEvent(CMS_BROWSER_U32 ID);
CMS_BROWSER_VOID Cms_Browser_DeleteAllInputHistoryEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_LinkInputHistory(CMS_BROWSER_U32 ID);
/*== add by roger for Tcentel 03/30/2004 ==*/
CMS_BROWSER_RET Cms_Browser_NewInputURIEvent(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_MarkFocusEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET	Cms_Browser_InsertHistory(CMS_BROWSER_VOID);
/*========================= 页面保存模块接口函数定义 ===================*/

CMS_BROWSER_RET Cms_Browser_GetAllSavedPageTitle(P_CMS_BROWSER_U8 **pagetitle);
CMS_BROWSER_BOOL Cms_Browser_SavePageFull(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_AddSavePage(P_CMS_BROWSER_U8 title);
CMS_BROWSER_RET Cms_Browser_DeleteSavePage(CMS_BROWSER_U32 saveID);
CMS_BROWSER_VOID Cms_Browser_DeleteAllSavePage(CMS_BROWSER_VOID);
P_CMS_BROWSER_U8 Cms_Browser_GetSavePageTitle(CMS_BROWSER_U32 ID);
P_CMS_BROWSER_U8 Cms_Browser_GetSavePageURL(CMS_BROWSER_U32 ID);
CMS_BROWSER_RET Cms_Browser_BrowserSavePage(CMS_BROWSER_U32 ID);
CMS_BROWSER_RET Cms_Browser_RenameSavePageTitle(CMS_BROWSER_U32 ID, P_CMS_BROWSER_U8 newTitle);
int Cms_LocalPageLoad( unsigned char *title,/* (in) title */ 
					   unsigned char *url,	 /* (int) url */
					   unsigned char *buf, /* (in)data buf 不要释放内容 */
					   unsigned int  len	/* (in)buf length */);
int Cms_Browser_SavePageEvent( void );
int CmsIsHaveBgSound( void );


/*========================= 排版模块接口函数定义 =======================*/
CMS_BROWSER_VOID  Cms_Browser_LayoutInit(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_LayoutEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_DrawEvent(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_LastPage(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetInputParam(P_CMS_BROWSER_U8 param);
CMS_BROWSER_VOID Cms_Browser_GetParam(P_CMS_BROWSER_S32 type,P_CMS_BROWSER_U8 *param,P_CMS_BROWSER_S32 len);
CMS_BROWSER_BOOL Cms_Browser_PageNULL(CMS_BROWSER_VOID);
P_CMS_BROWSER_U8 Cms_Browser_GetCurrentTitle(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GetPageTitle(P_CMS_BROWSER_U8 title, CMS_BROWSER_S32 len);

void Cms_Brw_MarqueeTimeExpier( void *time );

/*========================= 解析模块接口函数定义 =======================*/

CMS_BROWSER_RET Cms_Browser_ParserEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_UpPageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_DownPageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_OpenLocalEvent(P_CMS_BROWSER_U8 filename);
CMS_BROWSER_VOID Cms_Browser_SetHomepageEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GotoHomepageEvent(CMS_BROWSER_BOOL refresh);
CMS_BROWSER_RET Cms_Browser_Parserurl(CMS_BROWSER_S32 judge);

CMS_BROWSER_RET Cms_Browser_CreateCore (CMS_BROWSER_BOOL clearinput);

CMS_BROWSER_U32 CmsBRGetEleHasAttr(CMS_BROWSER_VOID* p_BR_Element, CMS_BROWSER_U32 attrid);
P_CMS_BROWSER_U8 CmsBRGetAttr(CMS_BROWSER_VOID *p_BR_Element,CMS_BROWSER_U8 attr_type);



/*========================= 网络模块接口函数定义 =======================*/

CMS_BROWSER_VOID Cms_Browser_NetworkInvalid(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_PageRefreshEvent(CMS_BROWSER_VOID);
P_CMS_BROWSER_U8 Cms_Browser_GetCurrentURL(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_NewInputURIEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_UserCancleDownload(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_NetworkNoSignal(CMS_BROWSER_VOID);

#ifdef TEST_DOWNLOAD

CMS_BROWSER_RET Cms_Browser_DownloadEvent( unsigned int message_id );
//#define	Cms_Browser_DownloadEvent	Cms_Browser_DownloadEventID

#else

CMS_BROWSER_RET Cms_Browser_DownloadEvent(CMS_BROWSER_VOID);

#endif


CMS_BROWSER_RET Cms_Browser_OpenNetEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_CloseNetEvent(CMS_BROWSER_VOID);
CMS_BROWSER_U64	 Cms_Browser_GetCurrentDownloadSize(CMS_BROWSER_VOID);
CMS_BROWSER_U64	 Cms_Browser_GetTotalDownloadSize(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_ExternBookmarkEvent(P_CMS_BROWSER_U8 url);

CMS_BROWSER_RET Cms_Browser_CreateTCPSocketEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_CloseTCPSocketEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_CreateUDPSocketEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_CloseUDPSocketEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_GetHostEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_ConnectEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_TCPSendEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_TCPRecvEvent(CMS_BROWSER_VOID);

int Cms_Http_DownLoad( void );

/*========================= 触摸屏模块接口函数定义 =====================*/

CMS_BROWSER_RET Cms_Browser_PenDownEvent(CMS_BROWSER_U16 x, CMS_BROWSER_U16 y);
CMS_BROWSER_BOOL Cms_Browser_GetEditStyle(P_CMS_BROWSER_U32 pMaxlength);
P_CMS_BROWSER_U8 Cms_Browser_GetOriginParam(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetApplicationData(P_CMS_APPLICATION_DATA appdata, CMS_APPLICATION_TYPE type);
CMS_BROWSER_VOID Cms_Browser_DestroyApplicationData(P_CMS_APPLICATION_DATA appdata);

/*========================= 定时器超时接口函数定义 =====================*/

CMS_BROWSER_BOOL Cms_Browser_TimerExpireEvent(CMS_BROWSER_U32 timeid);
CMS_BROWSER_VOID Cms_Browser_WMLTimerEvent(CMS_BROWSER_VOID);




/*========================= 二叉树模块接口函数定义 ==================*/
CMS_BROWSER_RET BiMarkFocusLink( void *p,	/* input table ele */
								 unsigned char is_mark );/* is mark */
void *GetTableEle( void *p);
int	GetTableElePos( void *node,		/* table node	*/
				    int	 *tx,		/* x pos (out)	*/
					int  *ty,		/* y pos (out)	*/
					int	 *bx,		/* x_end (out)  */
					int  *by);		/* y_end (out)  */
void BiMoveLeft( void );
void BiMoveRight( void );
void Cms_DrawRectBgColor ( int x, int y, int width, int height, int BackGroudColor);

int	GetTableEleIndex( void *node );
int GetScreenLeft( void );
void SetScreenLeft(int pos );
void* GetObjectPtr(void* pObject);
unsigned char GetObjectFlag(void* pObject);
int CmsGetObjectPos( void* pObject, unsigned char objectflag, 
								int*tx, int*ty, int*bx, int*by);



/*========================= 链接焦点处理 ===============================*/
#ifdef CMS_NOTOUCHPANNEL
CMS_BROWSER_BOOL Cms_Browser_LastLinkFocusEvent(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_NextLinkFocusEvent(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GoLinkFocusEvent(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_ResetOptionSelect(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_RefreshLinkFocus(CMS_BROWSER_VOID);
void CmsBrwMoveLinkFocusTabPrev( void );
void CmsBrwMoveLinkFocusTabNext( void );
void CmsSetMoveLinkFocusFlag( void );
CMS_BROWSER_S32 CmsBrwMoveLinkFocus( unsigned char direction );
CMS_BROWSER_S32 CmsBrwSaveLinkFocusToTab( void* pObject, CMS_BROWSER_U8	objectflag );
CMS_BROWSER_S32 CmsBrwSaveLinkFocusInPage( void* pObject, CMS_BROWSER_U8 objectflag );
int Cms_IsFirstURL(void);
int Cms_IsLastURL(void);
int Cms_Browser_HasFocus(void);
void Cms_Browser_PageDown( void );
void Cms_Browser_PageUp( void );
void Cms_OnTouchPanelDownEvent(void );
void Cms_OnTouchPanelUPEvent(void );
#endif

/*========================= Gif Draw functions =========================*/
CMS_BROWSER_BOOL Cms_Browser_GIFExpire(CMS_BROWSER_U32 timerid);

/*========================= 启迪接口 ==========================*/
void Cms_GetSoftKey(int keyValue);
void Cms_UpdateScreen(CMS_BROWSER_U32 a, CMS_BROWSER_U32 b,CMS_BROWSER_U32 c, CMS_BROWSER_U32 d);
void Cms_Scroll(int all_pages,int current_page,int scroll_type );/* 0:垂直 1：水平 */

void Cms_SetDownloadSuccess( void );
void Cms_SetDownloadFailed( void );

/* 保存文件的控制接口 */
void Set_FileToSave(void);
void Clear_FileToSave(void);
int  IsFileNeedToSave(void);

CMS_BROWSER_BOOL Cms_Browser_AccessKey(P_CMS_BROWSER_U8 pKey);

CMS_BROWSER_VOID Cms_SetBrowserBusy(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_ClearBrowserBusy(CMS_BROWSER_VOID);

CMS_BROWSER_BOOL Cms_Browser_ClearDispalyArea(CMS_BROWSER_VOID);
CMS_BROWSER_U32 Cms_GetLineFit(P_CMS_BROWSER_U8 str, CMS_BROWSER_U32 m_end, P_CMS_BROWSER_U32 max_width, CMS_BROWSER_S32 ls);
CMS_BROWSER_VOID Cms_Browser_RefreshScreen (CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_PostMessage (CMS_BROWSER_U32 MessageID);
int	CmsGetNetType( void );

#ifdef __cplusplus 
}
#endif

#endif

