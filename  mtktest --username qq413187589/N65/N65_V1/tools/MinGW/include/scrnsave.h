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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/scrnsave.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: scrnsave.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Date: 2007/05/17 07:25:33 $
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
* $Log: scrnsave.h,v $
* Revision 1.1  2007/05/17 07:25:33  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/scrnsave.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: scrnsave.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Date: 2007/05/14 09:46:48 $
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
* ~Log: scrnsave.h,v $
* Revision 1.1  2007/05/14 09:46:48  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/scrnsave.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: scrnsave.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Date: 2007/04/04 06:51:34 $
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
* ~Log: scrnsave.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
  Screen saver library by Anders Norlander <anorland@hem2.passagen.se>

  This library is (hopefully) compatible with Microsoft's
  screen saver library.

  This is public domain software.

 */
#ifndef _SCRNSAVE_H
#define _SCRNSAVE_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* configure dialog identifier */
#define DLG_SCRNSAVECONFIGURE 2003

#define idsIsPassword		1000
#define idsIniFile		1001
#define idsScreenSaver		1002
#define idsPassword		1003
#define idsDifferentPW		1004
#define idsChangePW		1005
#define idsBadOldPW		1006
#define idsAppName		1007
#define idsNoHelpMemory		1008
#define idsHelpFile		1009
#define idsDefKeyword		1010

#define IDS_DESCRIPTION 1
#define ID_APP 100

#define WS_GT (WS_GROUP | WS_TABSTOP)
#define SCRM_VERIFYPW		WM_APP
#define MAXFILELEN		13
#define TITLEBARNAMELEN		40
#define APPNAMEBUFFERLEN	40
#define BUFFLEN			255

#ifndef RC_INVOKED

/* functions provided by the aothor of the screen saver */
BOOL WINAPI ScreenSaverConfigureDialog(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI RegisterDialogClasses(HANDLE);
LONG WINAPI ScreenSaverProc(HWND,UINT,WPARAM,LPARAM);

/* Change name of function if we are using UNICODE */
#ifdef UNICODE
#define DefScreenSaverProc DefScreenSaverProcW
#endif

/* default screen saver proc; call instead of DefWindowProc */
LONG WINAPI DefScreenSaverProc(HWND,UINT,WPARAM,LPARAM);

/* change password */
void WINAPI ScreenSaverChangePassword(HWND);

/* globals that may be used by screen saver */
extern HINSTANCE	hMainInstance;
extern HWND		hMainWindow;
extern BOOL		fChildPreview;
extern TCHAR		szName[];
extern TCHAR		szAppName[];
extern TCHAR		szIniFile[];
extern TCHAR		szScreenSaver[];
extern TCHAR		szHelpFile[];
extern TCHAR		szNoHelpMemory[];
extern UINT		MyHelpMessage;

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif

#endif /* _SCRNSAVE_H */
