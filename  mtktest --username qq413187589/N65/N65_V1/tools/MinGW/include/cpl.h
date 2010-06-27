/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/cpl.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Id: cpl.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Date: 2007/05/17 07:25:26 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: cpl.h,v $
* Revision 1.1  2007/05/17 07:25:26  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2007
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/cpl.h,v 1.1 2007/05/14 09:46:37 bw Exp $
*
* ~Id: cpl.h,v 1.1 2007/05/14 09:46:37 bw Exp $
*
* ~Date: 2007/05/14 09:46:37 $
*
* ~Name: 1.1 $
*
* ~Locker$
*
* ~Revision: 1.1 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: cpl.h,v $
* Revision 1.1  2007/05/14 09:46:37  bw
* UNI@bw_20070514 17:21:01 MTK初始版本.合并U25V20到U26V28.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/cpl.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Id: cpl.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Date: 2007/04/04 06:51:30 $
*
* ~Name: 1.2 $
*
* ~Locker$
*
* ~Revision: 1.2 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: cpl.h,v $
* Revision 1.2  2007/04/04 06:51:30  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _CPL_H
#define _CPL_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define WM_CPL_LAUNCH (WM_USER+1000)
#define WM_CPL_LAUNCHED (WM_USER+1001)
#define CPL_DYNAMIC_RES 0
#define CPL_INIT 1
#define CPL_GETCOUNT 2
#define CPL_INQUIRE 3
#define CPL_SELECT 4
#define CPL_DBLCLK 5
#define CPL_STOP 6
#define CPL_EXIT 7
#define CPL_NEWINQUIRE 8
#define CPL_STARTWPARMS 9
#define CPL_SETUP 200
typedef LONG(APIENTRY *APPLET_PROC)(HWND,UINT,LONG,LONG);
typedef struct tagCPLINFO {
	int idIcon;
	int idName;
	int idInfo;
	LONG lData;
} CPLINFO,*LPCPLINFO;
typedef struct tagNEWCPLINFOA {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwHelpContext;
	LONG lData;
	HICON hIcon;
	CHAR szName[32];
	CHAR szInfo[64];
	CHAR szHelpFile[128];
} NEWCPLINFOA,*LPNEWCPLINFOA;
typedef struct tagNEWCPLINFOW {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwHelpContext;
	LONG lData;
	HICON hIcon;
	WCHAR szName[32];
	WCHAR szInfo[64];
	WCHAR szHelpFile[128];
} NEWCPLINFOW,*LPNEWCPLINFOW;
#ifdef UNICODE
typedef NEWCPLINFOW NEWCPLINFO,*LPNEWCPLINFO;
#else
typedef NEWCPLINFOA NEWCPLINFO,*LPNEWCPLINFO;
#endif
#ifdef __cplusplus
}
#endif
#endif
