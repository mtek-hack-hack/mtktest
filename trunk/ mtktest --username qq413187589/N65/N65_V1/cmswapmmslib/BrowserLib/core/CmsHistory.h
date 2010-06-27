/*================================================================

文件名			: CmsHistroy.h

功能描述		: 历史记录模块功能及接口函数定义

最近修改时间	: 11/15/2004
 
代码编写人员	: 潘正海

================================================================*/


#ifndef _CMS_HISTORY_H_
#define _CMS_HISTORY_H_


/*=========公共头文件=============*/

#include "CmsBrowserPublic.h"

/*========================================*/

P_HISTORY Cms_Create_History_Q(CMS_BROWSER_VOID);
void Cms_Browser_FreeAHisNode(P_HISTORYNODE his_node);
void Cms_FreeHeadHistory(P_HISTORYNODE his_node);
CMS_BROWSER_VOID Cms_Free_History_Q(CMS_BROWSER_VOID);
P_HISTORYNODE Cms_Create_History_Node(CMS_BROWSER_BOOL method, P_CMS_BROWSER_U8 url, 
									  P_CMS_BROWSER_U8 param,CMS_BROWSER_U32  prevtabindex);
int Cms_Browser_InsertToHistory_Q(P_HISTORYNODE his_node);
int Cms_Browser_InvalidTailURI(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_InvalidCurrentURI(CMS_BROWSER_VOID);
int Cms_Browser_MoveToPrevURL(void);
int Cms_Browser_MoveToNextURL(void);
CMS_BROWSER_RET Cms_Browser_GetPrevURI(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GoPrevURIEvent(CMS_BROWSER_VOID);
CMS_BROWSER_RET Cms_Browser_GetNextURI(CMS_BROWSER_VOID);
CMS_BROWSER_VOID Cms_Browser_GoNextURIEvent(CMS_BROWSER_VOID);
CMS_BROWSER_BOOL Cms_Browser_GetJADURL(P_CMS_BROWSER_U8 url, CMS_BROWSER_U32 urllen);
CMS_BROWSER_RET Cms_Browser_InsertHistory(CMS_BROWSER_VOID);
void Cms_Browser_ConfirmInsertHistory(void);
char* Cms_GetCurHistoryURL(void);
char* Cms_GetCurrentURL(void);
void Cms_Browser_LinkPageHistory(CMS_BROWSER_U8 ID);
CMS_BROWSER_VOID Cms_Browser_InvalidCurrentHis(CMS_BROWSER_VOID);
P_CMS_BROWSER_U8 Cms_Browser_GetUIHistoryTitle(CMS_BROWSER_U8 ID);
typedef struct _BRWHISTORY	{	
    CMS_BROWSER_S32   urlCurrent;              				 /* 数组url的当前位置 */
	P_CMS_BROWSER_U8  url[MAXSTOREHISTORY];	    	/*=== 历史记录指针数组 ===*/
    P_CMS_BROWSER_U8  title[MAXSTOREHISTORY];		/*=== 历史记录的标题 ===*/
}BRWHISTORY, *P_BRWHISTORY;//add by xiaoyongq 

#endif