/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ResGenerator.h"

#include "MainFrm.h"
#include "DCMLHandler.h"
#include "CustomizeEngine.h"
#include "CustDataRes.h"
#include "FontDCL.h"
#include "FontRes.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CCustomizeEngine	en;

void GenerateStringFile();
void GenerateImageFile();
void GenerateMenu();
void ClearFiles();
//void AddApplicationInfo(U32 nId, S8* pName, U32 nMinId, U32 nMaxId);
char pLang[] = {'E','\0','n','\0','g','\0','l','\0','i','\0','s','\0','h','\0','\0','\0'};
void CustomizeCallback(void* pValue);
extern "C" S32 (*UCS2Strcmp)( const S8 *string1, const S8 *string2  );
extern "C" StringResList	gStringList[MAX_LANGUAGES];

extern	"C" CUSTOM_STRING* gpStringRes;
extern "C" CUSTOM_STRING_MAP*	 gpStringMapRes;
extern "C" CUSTOM_STRMAP_SEARCH*	gpStrMapSearch;

extern "C" sLanguageDetails gLanguageArray[MAX_LANGUAGES];
extern "C" U16 gCurrLangIndex;
extern "C" CUSTOM_STRING	nCustStrings[MAX_STRING_IDS];
extern "C" CUSTOM_IMAGE	nCustImageNames[];
extern "C" CUSTOM_IMAGE_MAP ImageIdMap[];
extern "C" CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];
extern	"C" IMAGENAME_LIST ImageNameList[];

extern "C" CUSTOM_MENU		nCustMenus[MAX_MENU_ITEMS];

extern "C" unsigned short CurrMaxStringId; /* By default set to max number of string ids*/
extern "C" unsigned short CurrMaxStringNum; //Max Number Ids
extern "C" U32 CurrTotalStrLen; //Current String Length
extern "C" unsigned short CurrMaxStringIdSearch;

extern "C" unsigned short CurrMaxImageId; //Max String Ids
extern "C" unsigned short CurrMaxSearchImageId; //Max String Ids

extern "C" unsigned short CurrMaxImageNum; //Max Number Ids
extern "C" unsigned short CurrMaxMenuItemIndex; //Max menu Ids

extern "C" void InitUnicodeSupport(void);


extern "C" U16 gCurrLangIndex;
void PopulateMapSearch(void);
void PopulateImageSearch(void);
void Customize();
void SetCurrLanguage(S8 nIndex);

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
extern "C" HWND	hWnd;
CMainFrame*	gpFrame;

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
//	ON_MESSAGE(WM_GENSTRFILE,HandleStrFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
/*
void Test()
{
	int kk = 0;
}*/
void CMainFrame::HandleStrFile(WPARAM wParam, LPARAM lParam)
{

}

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}
extern "C" void DebugWindowAlloc();

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	SetTimer(1,500,0);
	gpFrame = this;
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
#define	DISPLAY_TAG	"***"

extern "C" void PopulateResData(void);
void InitUnicodeSupport(void);
#define	DISPLAY_TAG	"***"
CString csDisplay(DISPLAY_TAG);
DWORD	dwThreadId;
unsigned long __stdcall CheckResources(void* p);
extern "C" S8 CustImgPath[];

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		KillTimer(1);
		((CEditView*)GetActiveView())->GetEditCtrl().SetReadOnly();

		hWnd = ((CEditView*)GetActiveView())->m_hWnd;
//		HANDLE handle = CreateThread(NULL,0,CheckResources,NULL,0,&dwThreadId);

		DebugWindowAlloc();

		InitUnicodeSupport();
		ClearFiles();
		PopulateResData();
		en.SetCustImgPath((void*)CustImgPath);
		GenerateStringFile();
		GenerateImageFile();

		GenerateMenu();
//		::TerminateThread(handle,0);
		PostQuitMessage(0);
	}
	CFrameWnd::OnTimer(nIDEvent);
}
unsigned long __stdcall CheckResources(void* p)
{
	while(1)
	{
		gpFrame->DisplayView();
	//	Sleep(200);

	}
	return 0;
}


extern "C" void AddStringInfo(int StrId,char* pString,char* pStringDisplay)
{
	en.AddStringResource(StrId,pString,pStringDisplay);
}

extern "C" void AddImageInfo(int ImgId,char* pImage,char* pIMageDisplay)
{
	en.AddImageResource(ImgId,pImage,pIMageDisplay);
}


extern "C" void AddApplicationInfo(U32 nId, S8* pName, U32 nMinId, U32 nMaxId)
{
	en.AddApplicationInfo(nId,(void*)pName,nMinId,nMaxId);
}


extern "C" void AddMenuInfo(CUSTOM_MENU* pMenu, int nSize)
{
//	AddMenuInDCML(pMenu,nSize);
}

void GenerateStringFile()
{
#ifdef  __ASCII 
	en.SetCurrentLanguage((void*)"English");
#else
	
	en.SetCurrentLanguage((void*)pLang);
#endif
	en.GenerateStringResourceFiles((LPVOID)gpStringRes,CurrMaxStringNum,CurrTotalStrLen);
	PopulateMapSearch();
	en.GenerateStringMapFiles((LPVOID)gpStringMapRes,CurrMaxStringId);
        en.GenerateAddStringResourceFiles((LPVOID)gpStrMapSearch,CurrMaxStringIdSearch);
#ifdef  __ASCII 
	en.GenerateStringStructFiles((void*)"English",CurrMaxStringId,CurrMaxStringNum,CurrMaxStringIdSearch);
#else
	en.GenerateStringStructFiles((void*)pLang,CurrMaxStringId,CurrMaxStringNum,CurrMaxStringIdSearch);
#endif

    gStringList[gCurrLangIndex].nTotalStrRes=CurrMaxStringNum ;
	gStringList[gCurrLangIndex].nTotalStrMap=CurrMaxStringId;
	gStringList[gCurrLangIndex].nTotalStrMapSearch=CurrMaxStringIdSearch;
}

void GenerateImageFile()
{
	PopulateImageSearch();
	en.GenerateImageResourceFiles((LPVOID)ImageNameList,CurrMaxImageNum);
	en.GenerateImageMapFiles((LPVOID)ImageIdMap,CurrMaxImageId);
	en.GenerateImageMapSearchFiles((LPVOID)ImageIdSearchMap,CurrMaxSearchImageId);
}

void GenerateMenu()
{
	en.CreateMenuResource(nCustMenus,CurrMaxMenuItemIndex);
}

void ClearFiles()
{
	en.ClearResources();
}


void PopulateMapSearch()
{
	U16 i=0;
	U16 j=0;
	U16 index=0;
	U16 start=0;

	for (i=0;i<MAX_STRING_MAP_SIZE;i++) {
		if (gpStringMapRes[i]!=(U16)-1){
			if (!start) {
				gpStrMapSearch[j].nMinStrId=gpStrMapSearch[j].nMaxStrId=i;
				gpStrMapSearch[j].nMapIndex=index;
				index++;
				start=1;
			}
			else {
				gpStrMapSearch[j].nMaxStrId=i;
				index++;
			}
		}
		else	
			if (start) {
				j++;
				start=0;
			}
	}
	
	CurrMaxStringIdSearch=j;
	j=0;
	for (i=0;i<MAX_STRING_MAP_SIZE;i++) {
		if ((gpStringMapRes[i]!=(U16)-1)&&(i!=j))
		{
			gpStringMapRes[j]=gpStringMapRes[i];
			j++;
			gpStringMapRes[i]=-1;
		}
	}
	CurrMaxStringId=j;
}

void PopulateImageSearch()
{
	U16 i=0;
	U16 j=0;
	U16 index=0;
	U16 start=0;

	for (i=0;i<MAX_IMAGE_IDS_SIZE;i++) {
		if (ImageIdMap[i].nImageNum!=(U16)-1){
			if (!start) {
				ImageIdSearchMap[j].minImageId=ImageIdSearchMap[j].maxImageId=i;
				ImageIdSearchMap[j].index=index;
				index++;
				start=1;
			}
			else {
				ImageIdSearchMap[j].maxImageId=i;
				index++;
			}
		}
		else	
			if (start) {
				j++;
				start=0;
			}
	}
	
	CurrMaxSearchImageId=j;
	j=0;
	for (i=0;i<MAX_IMAGE_IDS_SIZE;i++) {
		if ((ImageIdMap[i].nImageNum!=(U16)-1)&&(i!=j))
		{
			ImageIdMap[j].nImageNum=ImageIdMap[i].nImageNum;
			ImageIdMap[j].nImageId=ImageIdMap[i].nImageId;

			j++;
			ImageIdMap[i].nImageNum=-1;
		}
	}
	CurrMaxImageId=j;
}

void CMainFrame::DisplayView()
{
	static CString csDisplay(_T(""));

	csDisplay = csDisplay+DISPLAY_TAG;
	((CEditView*)GetActiveView())->GetEditCtrl().SetWindowText(csDisplay);

}
