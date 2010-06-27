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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/nspapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: nspapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: nspapi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/nspapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Id: nspapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
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
* ~Log: nspapi.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/nspapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: nspapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: nspapi.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _NSPAPI_H
#define _NSPAPI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define NS_ALL		0

#define NS_SAP		1
#define NS_NDS		2
#define NS_PEER_BROWSE	3

#define NS_TCPIP_LOCAL	10
#define NS_TCPIP_HOSTS	11
#define NS_DNS		12
#define NS_NETBT	13
#define NS_WINS		14

#define NS_NBP		20

#define NS_MS		30
#define NS_STDA		31
#define NS_NTDS		32

#define NS_X500		40
#define NS_NIS		41
#define NS_NISPLUS	42

#define NS_WRQ		50

#define SERVICE_REGISTER	1
#define SERVICE_DEREGISTER	2
#define SERVICE_FLUSH		3
#define SERVICE_FLAG_HARD	0x00000002

#ifndef RC_INVOKED

#if defined (_WINSOCK_H) || defined (_WINSOCK2_H) /* needed for LPSOCKADDR */
#ifndef __CSADDR_T_DEFINED /* also in winsock2.h, but not in winsock.h */
#define __CSADDR_T_DEFINED
typedef struct _SOCKET_ADDRESS {
	LPSOCKADDR lpSockaddr;
	INT iSockaddrLength;
} SOCKET_ADDRESS,*PSOCKET_ADDRESS,*LPSOCKET_ADDRESS;
typedef struct _CSADDR_INFO {
	SOCKET_ADDRESS LocalAddr;
	SOCKET_ADDRESS RemoteAddr;
	INT iSocketType;
	INT iProtocol;
} CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#endif
#endif

#ifndef __BLOB_T_DEFINED /* also in wtypes.h and winsock2.h */
#define __BLOB_T_DEFINED
typedef struct _BLOB {
	ULONG	cbSize;
	BYTE	*pBlobData;
} BLOB,*PBLOB,*LPBLOB;
#endif

typedef struct _SERVICE_ADDRESS {
	DWORD dwAddressType;
	DWORD dwAddressFlags;
	DWORD dwAddressLength;
	DWORD dwPrincipalLength;
	BYTE *lpAddress;
	BYTE *lpPrincipal;
} SERVICE_ADDRESS;
typedef struct _SERVICE_ADDRESSES {
	DWORD dwAddressCount;
	SERVICE_ADDRESS Addresses[1];
} SERVICE_ADDRESSES, *PSERVICE_ADDRESSES, *LPSERVICE_ADDRESSES;
typedef struct _SERVICE_INFOA {
	LPGUID lpServiceType;
	LPSTR lpServiceName;
	LPSTR lpComment;
	LPSTR lpLocale;
	DWORD dwDisplayHint;
	DWORD dwVersion;
	DWORD dwTime;
	LPSTR lpMachineName;
	LPSERVICE_ADDRESSES lpServiceAddress;
	BLOB ServiceSpecificInfo;
} SERVICE_INFOA, *LPSERVICE_INFOA;
typedef struct _SERVICE_INFOW {
	LPGUID lpServiceType;
	LPWSTR lpServiceName;
	LPWSTR lpComment;
	LPWSTR lpLocale;
	DWORD dwDisplayHint;
	DWORD dwVersion;
	DWORD dwTime;
	LPWSTR lpMachineName;
	LPSERVICE_ADDRESSES lpServiceAddress;
	BLOB ServiceSpecificInfo;
} SERVICE_INFOW, *LPSERVICE_INFOW;

typedef void *LPSERVICE_ASYNC_INFO;
INT WINAPI SetServiceA(DWORD,DWORD,DWORD,LPSERVICE_INFOA,LPSERVICE_ASYNC_INFO,LPDWORD);
INT WINAPI SetServiceW(DWORD,DWORD,DWORD,LPSERVICE_INFOA,LPSERVICE_ASYNC_INFO,LPDWORD);
INT WINAPI GetAddressByNameA(DWORD,LPGUID,LPSTR,LPINT,DWORD,LPSERVICE_ASYNC_INFO,LPVOID,LPDWORD,LPTSTR,LPDWORD);
INT WINAPI GetAddressByNameW(DWORD,LPGUID,LPWSTR,LPINT,DWORD,LPSERVICE_ASYNC_INFO,LPVOID,LPDWORD,LPTSTR,LPDWORD);

#ifdef UNICODE
typedef SERVICE_INFOW SERVICE_INFO, *LPSERVICE_INFO;
#define _SERVICE_INFO SERVICE_INFOW
#define SetService SetServiceW
#define GetAddressByName GetAddressByNameW
#else
typedef SERVICE_INFOA SERVICE_INFO, *LPSERVICE_INFO;
#define _SERVICE_INFO SERVICE_INFOA
#define SetService SetServiceA
#define GetAddressByName GetAddressByNameA
#endif

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif
#endif /* _NSPAPI_H */
