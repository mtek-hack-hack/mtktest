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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/intshcut.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Id: intshcut.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Date: 2007/05/17 07:25:29 $
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
* $Log: intshcut.h,v $
* Revision 1.1  2007/05/17 07:25:29  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/intshcut.h,v 1.1 2007/05/14 09:46:40 bw Exp $
*
* ~Id: intshcut.h,v 1.1 2007/05/14 09:46:40 bw Exp $
*
* ~Date: 2007/05/14 09:46:40 $
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
* ~Log: intshcut.h,v $
* Revision 1.1  2007/05/14 09:46:40  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/intshcut.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: intshcut.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Date: 2007/04/04 06:51:31 $
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
* ~Log: intshcut.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _INTSHCUT_H
#define _INTSHCUT_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <isguids.h>
#ifdef __cplusplus
extern "C" { 
#endif 
#define INTSHCUTAPI DECLSPEC_IMPORT
#define E_FLAGS MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1000)
#define IS_E_EXEC_FAILED MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x2002)
#define URL_E_INVALID_SYNTAX MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1001)
#define URL_E_UNREGISTERED_PROTOCOL MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1002)
typedef enum iurl_seturl_flags {
 IURL_SETURL_FL_GUESS_PROTOCOL=1,
 IURL_SETURL_FL_USE_DEFAULT_PROTOCOL,
 ALL_IURL_SETURL_FLAGS=(IURL_SETURL_FL_GUESS_PROTOCOL|IURL_SETURL_FL_USE_DEFAULT_PROTOCOL)
} IURL_SETURL_FLAGS;
typedef enum iurl_invokecommand_flags {
 IURL_INVOKECOMMAND_FL_ALLOW_UI=1,
 IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB,
 ALL_IURL_INVOKECOMMAND_FLAGS=(IURL_INVOKECOMMAND_FL_ALLOW_UI|IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB)
} IURL_INVOKECOMMAND_FLAGS;
typedef enum translateurl_in_flags {
 TRANSLATEURL_FL_GUESS_PROTOCOL=1,
 TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL,
 ALL_TRANSLATEURL_FLAGS=(TRANSLATEURL_FL_GUESS_PROTOCOL|TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL)
} TRANSLATEURL_IN_FLAGS;
typedef enum urlassociationdialog_in_flags {
 URLASSOCDLG_FL_USE_DEFAULT_NAME=1,
 URLASSOCDLG_FL_REGISTER_ASSOC,
 ALL_URLASSOCDLG_FLAGS=(URLASSOCDLG_FL_USE_DEFAULT_NAME|URLASSOCDLG_FL_REGISTER_ASSOC)
} URLASSOCIATIONDIALOG_IN_FLAGS;
typedef enum mimeassociationdialog_in_flags {
 MIMEASSOCDLG_FL_REGISTER_ASSOC=1,
 ALL_MIMEASSOCDLG_FLAGS=MIMEASSOCDLG_FL_REGISTER_ASSOC
} MIMEASSOCIATIONDIALOG_IN_FLAGS;
typedef struct urlinvokecommandinfo {
 DWORD dwcbSize;
 DWORD dwFlags;
 HWND hwndParent;
 PCSTR pcszVerb;
} URLINVOKECOMMANDINFO,*PURLINVOKECOMMANDINFO;
typedef const URLINVOKECOMMANDINFO CURLINVOKECOMMANDINFO;
typedef const URLINVOKECOMMANDINFO *PCURLINVOKECOMMANDINFO;
#undef INTERFACE
#define INTERFACE IUniformResourceLocator
DECLARE_INTERFACE_(IUniformResourceLocator,IUnknown)
{
 STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
 STDMETHOD_(ULONG,AddRef)(THIS) PURE;
 STDMETHOD_(ULONG,Release)(THIS) PURE;
 STDMETHOD(SetURL)(THIS_ PCSTR,DWORD) PURE;
 STDMETHOD(GetURL)(THIS_ PSTR*) PURE;
 STDMETHOD(InvokeCommand)(THIS_ PURLINVOKECOMMANDINFO) PURE;
};
typedef IUniformResourceLocator *PIUniformResourceLocator;
typedef const IUniformResourceLocator CIUniformResourceLocator;
typedef const IUniformResourceLocator *PCIUniformResourceLocator;

BOOL WINAPI InetIsOffline(DWORD);
HRESULT WINAPI MIMEAssociationDialogA(HWND,DWORD,PCSTR,PCSTR,PSTR,UINT);
HRESULT WINAPI MIMEAssociationDialogW(HWND,DWORD,PCWSTR,PCWSTR,PWSTR,UINT);
HRESULT WINAPI TranslateURLA(PCSTR,DWORD,PSTR*);
HRESULT WINAPI TranslateURLW(PCWSTR,DWORD,PWSTR*);
HRESULT WINAPI URLAssociationDialogA(HWND,DWORD,PCSTR,PCSTR,PSTR,UINT);
HRESULT WINAPI URLAssociationDialogW(HWND,DWORD,PCWSTR,PCWSTR,PWSTR,UINT);
#ifdef UNICODE
#define TranslateURL TranslateURLW
#define MIMEAssociationDialog MIMEAssociationDialogW
#define URLAssociationDialog URLAssociationDialogW
#else
#define TranslateURL TranslateURLA
#define MIMEAssociationDialog MIMEAssociationDialogA
#define URLAssociationDialog URLAssociationDialogA
#endif 
#ifdef __cplusplus
} 
#endif 
#endif 
