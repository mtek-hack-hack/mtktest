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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/custcntl.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Id: custcntl.h,v 1.1 2007/05/17 07:25:26 bw Exp $
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
* $Log: custcntl.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/custcntl.h,v 1.1 2007/05/14 09:46:37 bw Exp $
*
* ~Id: custcntl.h,v 1.1 2007/05/14 09:46:37 bw Exp $
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
* ~Log: custcntl.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/custcntl.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Id: custcntl.h,v 1.2 2007/04/04 06:51:30 bw Exp $
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
* ~Log: custcntl.h,v $
* Revision 1.2  2007/04/04 06:51:30  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _CUSTCNTL_H
#define _CUSTCNTL_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CCF_NOTEXT 1
#define CCHCCCLASS 32
#define CCHCCDESC 32
#define CCHCCTEXT 256

typedef struct tagCCSTYLEA {
	DWORD flStyle;
	DWORD flExtStyle;
	CHAR szText[CCHCCTEXT];
	LANGID lgid;
	WORD wReserved1;
} CCSTYLEA,*LPCCSTYLEA;
typedef struct tagCCSTYLEW {
	DWORD flStyle;
	DWORD flExtStyle;
	WCHAR szText[CCHCCTEXT];
	LANGID lgid;
	WORD wReserved1;
} CCSTYLEW,*LPCCSTYLEW;
typedef struct tagCCSTYLEFLAGA {
	DWORD flStyle;
	DWORD flStyleMask;
	LPSTR pszStyle;
} CCSTYLEFLAGA,*LPCCSTYLEFLAGA;
typedef struct tagCCSTYLEFLAGW {
	DWORD flStyle;
	DWORD flStyleMask;
	LPWSTR pszStyle;
} CCSTYLEFLAGW,*LPCCSTYLEFLAGW;
typedef BOOL(CALLBACK* LPFNCCSTYLEA)(HWND,LPCCSTYLEA);
typedef INT(CALLBACK* LPFNCCSIZETOTEXTA)(DWORD,DWORD,HFONT,LPSTR);
typedef struct tagCCINFOA {
	CHAR szClass[CCHCCCLASS];
	DWORD flOptions;
	CHAR szDesc[CCHCCDESC];
	UINT cxDefault;
	UINT cyDefault;
	DWORD flStyleDefault;
	DWORD flExtStyleDefault;
	DWORD flCtrlTypeMask;
	CHAR szTextDefault[CCHCCTEXT];
	INT cStyleFlags;
	LPCCSTYLEFLAGA aStyleFlags;
	LPFNCCSTYLEA lpfnStyle;
	LPFNCCSIZETOTEXTA lpfnSizeToText;
	DWORD dwReserved1;
	DWORD dwReserved2;
} CCINFOA,*LPCCINFOA;
typedef UINT(CALLBACK* LPFNCCINFOA)(LPCCINFOA);
typedef BOOL(CALLBACK* LPFNCCSTYLEW)(HWND,LPCCSTYLEW);
typedef INT (CALLBACK* LPFNCCSIZETOTEXTW)(DWORD,DWORD,HFONT,LPWSTR);
typedef struct tagCCINFOW {
	WCHAR szClass[CCHCCCLASS];
	DWORD flOptions;
	WCHAR szDesc[CCHCCDESC];
	UINT cxDefault;
	UINT cyDefault;
	DWORD flStyleDefault;
	DWORD flExtStyleDefault;
	DWORD flCtrlTypeMask;
	WCHAR szTextDefault[CCHCCTEXT];
	INT cStyleFlags;
	LPCCSTYLEFLAGW aStyleFlags;
	LPFNCCSTYLEW lpfnStyle;
	LPFNCCSIZETOTEXTW lpfnSizeToText;
	DWORD dwReserved1;
	DWORD dwReserved2;
} CCINFOW,*LPCCINFOW;
typedef UINT(CALLBACK* LPFNCCINFOW)(LPCCINFOW);

UINT CALLBACK CustomControlInfoA(LPCCINFOA acci);
UINT CALLBACK CustomControlInfoW(LPCCINFOW acci);

#ifdef UNICODE
typedef CCSTYLEW CCSTYLE,*LPCCSTYLE;
typedef CCSTYLEFLAGW CCSTYLEFLAG,*LPCCSTYLEFLAG;
typedef CCINFOW CCINFO,*LPCCINFO;
#define LPFNCCSTYLE LPFNCCSTYLEW
#define LPFNCCSIZETOTEXT LPFNCCSIZETOTEXTW
#define LPFNCCINFO LPFNCCINFOW
#else
typedef CCSTYLEA CCSTYLE,*LPCCSTYLE;
typedef CCSTYLEFLAGA CCSTYLEFLAG,*LPCCSTYLEFLAG;
typedef CCINFOA CCINFO,*LPCCINFO;
#define LPFNCCSTYLE LPFNCCSTYLEA
#define LPFNCCSIZETOTEXT LPFNCCSIZETOTEXTA
#define LPFNCCINFO LPFNCCINFOA
#endif
#ifdef __cplusplus
}
#endif
#endif
