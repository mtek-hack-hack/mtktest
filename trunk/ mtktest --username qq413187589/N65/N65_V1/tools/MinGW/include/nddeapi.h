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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/nddeapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: nddeapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Date: 2007/05/17 07:25:31 $
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
* $Log: nddeapi.h,v $
* Revision 1.1  2007/05/17 07:25:31  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/nddeapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Id: nddeapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Date: 2007/05/14 09:46:44 $
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
* ~Log: nddeapi.h,v $
* Revision 1.1  2007/05/14 09:46:44  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/nddeapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: nddeapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Date: 2007/04/04 06:51:32 $
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
* ~Log: nddeapi.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _NDDEAPI_H
#define _NDDEAPI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef CNLEN /* also in lmcons.h */
#define CNLEN 15
#define UNCLEN (CNLEN + 2)
#endif
#define SEP_CHAR ','
#define BAR_CHAR "|"
#define SEP_WCHAR L','
#define BAR_WCHAR L"|"
#define NDDE_NO_ERROR 0
#define NDDE_ACCESS_DENIED 1
#define NDDE_BUF_TOO_SMALL 2
#define NDDE_ERROR_MORE_DATA 3
#define NDDE_INVALID_SERVER 4
#define NDDE_INVALID_SHARE 5
#define NDDE_INVALID_PARAMETER 6
#define NDDE_INVALID_LEVEL 7
#define NDDE_INVALID_PASSWORD 8
#define NDDE_INVALID_ITEMNAME 9
#define NDDE_INVALID_TOPIC 10
#define NDDE_INTERNAL_ERROR 11
#define NDDE_OUT_OF_MEMORY 12
#define NDDE_INVALID_APPNAME 13
#define NDDE_NOT_IMPLEMENTED 14
#define NDDE_SHARE_ALREADY_EXIST 15
#define NDDE_SHARE_NOT_EXIST 16
#define NDDE_INVALID_FILENAME 17
#define NDDE_NOT_RUNNING 18
#define NDDE_INVALID_WINDOW 19
#define NDDE_INVALID_SESSION 20
#define NDDE_INVALID_ITEM_LIST 21
#define NDDE_SHARE_DATA_CORRUPTED 22
#define NDDE_REGISTRY_ERROR 23
#define NDDE_CANT_ACCESS_SERVER 24
#define NDDE_INVALID_SPECIAL_COMMAND 25
#define NDDE_INVALID_SECURITY_DESC 26
#define NDDE_TRUST_SHARE_FAIL 27
#define MAX_NDDESHARENAME 256
#define MAX_DOMAINNAME 15
#define MAX_USERNAME 15
#define MAX_APPNAME 255
#define MAX_TOPICNAME 255
#define MAX_ITEMNAME 255
#define NDDEF_NOPASSWORDPROMPT 0x0001
#define NDDEF_NOCACHELOOKUP 0x0002
#define NDDEF_STRIP_NDDE 0x0004
#define SHARE_TYPE_OLD 0x01
#define SHARE_TYPE_NEW 0x02
#define SHARE_TYPE_STATIC 0x04
#define NDDE_TRUST_SHARE_START 0x80000000L
#define NDDE_TRUST_SHARE_INIT 0x40000000L
#define NDDE_TRUST_SHARE_DEL 0x20000000L
#define NDDE_TRUST_CMD_SHOW 0x10000000L
#define NDDE_CMD_SHOW_MASK 0x0000FFFFL
struct NDdeShareInfo_tag {
	LONG lRevision;
	LPTSTR lpszShareName;
	LONG lShareType;
	LPTSTR lpszAppTopicList;
	LONG fSharedFlag;
	LONG fService;
	LONG fStartAppFlag;
	LONG nCmdShow;
	LONG qModifyId[2];
	LONG cNumItems;
	LPTSTR lpszItemList;
} NDDESHAREINFO,*PNDDESHAREINFO;

UINT WINAPI NDdeGetErrorStringA(UINT,LPSTR,DWORD);
UINT WINAPI NDdeGetErrorStringW(UINT,LPWSTR,DWORD);
UINT WINAPI NDdeGetShareSecurityA(LPSTR,LPSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
UINT WINAPI NDdeGetShareSecurityW(LPWSTR,LPWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
UINT WINAPI NDdeGetTrustedShareA(LPSTR,LPSTR,PDWORD,PDWORD,PDWORD);
UINT WINAPI NDdeGetTrustedShareW(LPWSTR,LPWSTR,PDWORD,PDWORD,PDWORD);
BOOL WINAPI NDdeIsValidShareNameA(LPSTR);
BOOL WINAPI NDdeIsValidShareNameW(LPWSTR);
BOOL WINAPI NDdeIsValidAppTopicListA(LPSTR);
BOOL WINAPI NDdeIsValidAppTopicListW(LPWSTR);
UINT WINAPI NDdeSetShareSecurityA(LPSTR,LPSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
UINT WINAPI NDdeSetShareSecurityW(LPWSTR,LPWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
UINT WINAPI NDdeSetTrustedShareA(LPSTR,LPSTR,DWORD);
UINT WINAPI NDdeSetTrustedShareW(LPWSTR,LPWSTR,DWORD);
UINT WINAPI NDdeShareAddA(LPSTR,UINT,PSECURITY_DESCRIPTOR,PBYTE,DWORD);
UINT WINAPI NDdeShareAddW(LPWSTR,UINT,PSECURITY_DESCRIPTOR,PBYTE,DWORD);
UINT WINAPI NDdeShareDelA(LPSTR,LPSTR,UINT);
UINT WINAPI NDdeShareDelW(LPWSTR,LPWSTR,UINT);
UINT WINAPI NDdeShareEnumA(LPSTR,UINT,PBYTE,DWORD,PDWORD,PDWORD);
UINT WINAPI NDdeShareEnumW(LPWSTR,UINT,PBYTE,DWORD,PDWORD,PDWORD);
UINT WINAPI NDdeShareGetInfoA(LPSTR,LPSTR,UINT,PBYTE,DWORD,PDWORD,PWORD);
UINT WINAPI NDdeShareGetInfoW(LPWSTR,LPWSTR,UINT,PBYTE,DWORD,PDWORD,PWORD);
UINT WINAPI NDdeShareSetInfoA(LPSTR,LPSTR,UINT,PBYTE,DWORD,WORD);
UINT WINAPI NDdeShareSetInfoW(LPWSTR,LPWSTR,UINT,PBYTE,DWORD,WORD);
UINT WINAPI NDdeTrustedShareEnumA(LPSTR,UINT,PBYTE,DWORD,PDWORD,PDWORD);
UINT WINAPI NDdeTrustedShareEnumW(LPWSTR,UINT,PBYTE,DWORD,PDWORD,PDWORD);
#ifdef UNICODE
#define NDdeShareAdd NDdeShareAddW
#define NDdeShareDel NDdeShareDelW
#define NDdeSetShareSecurity NDdeSetShareSecurityW
#define NDdeGetShareSecurity NDdeGetShareSecurityW
#define NDdeShareEnum NDdeShareEnumW
#define NDdeShareGetInfo NDdeShareGetInfoW
#define NDdeShareSetInfo NDdeShareSetInfoW
#define NDdeGetErrorString NDdeGetErrorStringW
#define NDdeSetTrustedShare NDdeSetTrustedShareW
#define NDdeGetTrustedShare NDdeGetTrustedShareW
#define NDdeTrustedShareEnum NDdeTrustedShareEnumW
#else
#define NDdeShareAdd NDdeShareAddA
#define NDdeShareDel NDdeShareDelA
#define NDdeSetShareSecurity NDdeSetShareSecurityA
#define NDdeGetShareSecurity NDdeGetShareSecurityA
#define NDdeShareEnum NDdeShareEnumA
#define NDdeShareGetInfo NDdeShareGetInfoA
#define NDdeShareSetInfo NDdeShareSetInfoA
#define NDdeGetErrorString NDdeGetErrorStringA
#define NDdeIsValidShareName NDdeIsValidShareNameA
#define NDdeIsValidAppTopicList NDdeIsValidAppTopicListA
#define NDdeSetTrustedShare NDdeSetTrustedShareA
#define NDdeGetTrustedShare NDdeGetTrustedShareA
#define NDdeTrustedShareEnum NDdeTrustedShareEnumA
#endif
#ifdef __cplusplus
}
#endif
#endif
