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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ws2spi.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Id: ws2spi.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Date: 2007/05/17 07:25:37 $
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
* $Log: ws2spi.h,v $
* Revision 1.1  2007/05/17 07:25:37  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ws2spi.h,v 1.1 2007/05/14 09:46:55 bw Exp $
*
* ~Id: ws2spi.h,v 1.1 2007/05/14 09:46:55 bw Exp $
*
* ~Date: 2007/05/14 09:46:55 $
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
* ~Log: ws2spi.h,v $
* Revision 1.1  2007/05/14 09:46:55  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ws2spi.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Id: ws2spi.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Date: 2007/04/04 06:51:35 $
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
* ~Log: ws2spi.h,v $
* Revision 1.2  2007/04/04 06:51:35  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * ws2spi.h
 *
 * Winsock 2 Service Provider interface.
 *
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef _WS2SPI_H
#define _WS2SPI_H

#include <winsock2.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define WSPAPI WSAAPI
#define WSPDESCRIPTION_LEN 255

#ifndef RC_INVOKED

typedef struct WSPData {
	WORD wVersion;
	WORD wHighVersion;
	WCHAR szDescription[WSPDESCRIPTION_LEN+1];
} WSPDATA, FAR *LPWSPDATA;
typedef struct _WSATHREADID {
	HANDLE ThreadHandle;
	DWORD Reserved;
} WSATHREADID, FAR *LPWSATHREADID;

typedef BOOL (CALLBACK FAR *LPBLOCKINGCALLBACK)(DWORD);
typedef VOID (CALLBACK FAR *LPWSAUSERAPC)(DWORD);

/* Prototypes for service provider procedure table */
typedef SOCKET (WSPAPI *LPWSPACCEPT)(SOCKET,LPSOCKADDR,LPINT,LPCONDITIONPROC,DWORD,LPINT);
typedef INT (WSPAPI *LPWSPADDRESSTOSTRING)(LPSOCKADDR,DWORD,LPWSAPROTOCOL_INFOW,LPWSTR,LPDWORD,LPINT);
typedef INT (WSPAPI *LPWSPASYNCSELECT)(SOCKET,HWND,UINT,LONG,LPINT);
typedef INT (WSPAPI *LPWSPBIND)(SOCKET,CONST LPSOCKADDR,INT,LPINT);
typedef INT (WSPAPI *LPWSPCANCELBLOCKINGCALL)(LPINT);
typedef INT (WSPAPI *LPWSPCLEANUP)(LPINT);
typedef INT (WSPAPI *LPWSPCLOSESOCKET)(SOCKET,LPINT);
typedef INT (WSPAPI *LPWSPCONNECT)(SOCKET,CONST LPSOCKADDR,INT,LPWSABUF,LPWSABUF,LPQOS,LPQOS,LPINT);
typedef INT (WSPAPI *LPWSPDUPLICATESOCKET)(SOCKET,DWORD,LPWSAPROTOCOL_INFOW,LPINT);
typedef INT (WSPAPI *LPWSPENUMNETWORKEVENTS)(SOCKET,WSAEVENT,LPWSANETWORKEVENTS,LPINT);
typedef INT (WSPAPI *LPWSPEVENTSELECT)(SOCKET,WSAEVENT,LONG,LPINT);
typedef BOOL (WSPAPI *LPWSPGETOVERLAPPEDRESULT)(SOCKET,LPWSAOVERLAPPED,LPDWORD,BOOL,LPDWORD,LPINT);
typedef INT (WSPAPI *LPWSPGETPEERNAME)(SOCKET,LPSOCKADDR,LPINT,LPINT);
typedef BOOL (WSPAPI *LPWSPGETQOSBYNAME)(SOCKET,LPWSABUF,LPQOS,LPINT);
typedef INT (WSPAPI *LPWSPGETSOCKNAME)(SOCKET,LPSOCKADDR,LPINT,LPINT);
typedef INT (WSPAPI *LPWSPGETSOCKOPT)(SOCKET,INT,INT,CHAR FAR*,LPINT,LPINT);
typedef INT (WSPAPI *LPWSPIOCTL)(SOCKET,DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,
LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPWSATHREADID,LPINT);
typedef SOCKET (WSPAPI *LPWSPJOINLEAF)(SOCKET,CONST LPSOCKADDR,INT,LPWSABUF,LPWSABUF,LPQOS,LPQOS,DWORD,LPINT);
typedef INT (WSPAPI *LPWSPLISTEN)(SOCKET,INT,LPINT);
typedef INT (WSPAPI *LPWSPRECV)(SOCKET,LPWSABUF,DWORD,LPDWORD,LPDWORD,
LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPWSATHREADID,LPINT);
typedef INT (WSPAPI *LPWSPRECVDISCONNECT)(SOCKET,LPWSABUF,LPINT);
typedef INT (WSPAPI *LPWSPRECVFROM)(SOCKET,LPWSABUF,DWORD,LPDWORD,LPDWORD,LPSOCKADDR,
LPINT,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPWSATHREADID,LPINT);
typedef INT (WSPAPI *LPWSPSELECT)(INT,LPFD_SET,LPFD_SET,LPFD_SET,CONST LPTIMEVAL,LPINT);
typedef INT (WSPAPI *LPWSPSEND)(SOCKET,LPWSABUF,DWORD,LPDWORD,DWORD,
LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPWSATHREADID,LPINT);
typedef INT (WSPAPI *LPWSPSENDDISCONNECT)(SOCKET,LPWSABUF,LPINT);
typedef INT (WSPAPI *LPWSPSENDTO)(SOCKET,LPWSABUF,DWORD,LPDWORD,DWORD,CONST LPSOCKADDR,
INT,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPWSATHREADID,LPINT);
typedef INT (WSPAPI *LPWSPSETSOCKOPT)(SOCKET,INT,INT,CONST CHAR FAR*,INT,LPINT);
typedef INT (WSPAPI *LPWSPSHUTDOWN)(SOCKET,INT,LPINT);
typedef SOCKET (WSPAPI *LPWSPSOCKET)(INT,INT,INT,LPWSAPROTOCOL_INFOW,GROUP,DWORD,LPINT);
typedef INT (WSPAPI *LPWSPSTRINGTOADDRESS)(LPWSTR,INT,LPWSAPROTOCOL_INFOW,LPSOCKADDR,LPINT,LPINT);

/* Service provider procedure table */
typedef struct _WSPPROC_TABLE {
  LPWSPACCEPT lpWSPAccept;
  LPWSPADDRESSTOSTRING lpWSPAddressToString;
  LPWSPASYNCSELECT lpWSPAsyncSelect;
  LPWSPBIND lpWSPBind;
  LPWSPCANCELBLOCKINGCALL lpWSPCancelBlockingCall;
  LPWSPCLEANUP lpWSPCleanup;
  LPWSPCLOSESOCKET lpWSPCloseSocket;
  LPWSPCONNECT lpWSPConnect;
  LPWSPDUPLICATESOCKET lpWSPDuplicateSocket;
  LPWSPENUMNETWORKEVENTS lpWSPEnumNetworkEvents;
  LPWSPEVENTSELECT lpWSPEventSelect;
  LPWSPGETOVERLAPPEDRESULT lpWSPGetOverlappedResult;
  LPWSPGETPEERNAME lpWSPGetPeerName;
  LPWSPGETSOCKNAME lpWSPGetSockName;
  LPWSPGETSOCKOPT lpWSPGetSockOpt;
  LPWSPGETQOSBYNAME lpWSPGetQOSByName;
  LPWSPIOCTL lpWSPIoctl;
  LPWSPJOINLEAF lpWSPJoinLeaf;
  LPWSPLISTEN lpWSPListen;
  LPWSPRECV lpWSPRecv;
  LPWSPRECVDISCONNECT lpWSPRecvDisconnect;
  LPWSPRECVFROM lpWSPRecvFrom;
  LPWSPSELECT lpWSPSelect;
  LPWSPSEND lpWSPSend;
  LPWSPSENDDISCONNECT lpWSPSendDisconnect;
  LPWSPSENDTO lpWSPSendTo;
  LPWSPSETSOCKOPT lpWSPSetSockOpt;
  LPWSPSHUTDOWN lpWSPShutdown;
  LPWSPSOCKET lpWSPSocket;
  LPWSPSTRINGTOADDRESS lpWSPStringToAddress;
} WSPPROC_TABLE, FAR* LPWSPPROC_TABLE;

/* Prototypes for service provider upcall procedure table */
typedef BOOL (WSPAPI *LPWPUCLOSEEVENT)(WSAEVENT,LPINT);
typedef INT (WSPAPI *LPWPUCLOSESOCKETHANDLE)(SOCKET,LPINT);
typedef INT (WSPAPI *LPWPUCLOSETHREAD)(LPWSATHREADID,LPINT);
typedef WSAEVENT (WSPAPI *LPWPUCREATEEVENT)(LPINT);
typedef SOCKET (WSPAPI *LPWPUCREATESOCKETHANDLE)(DWORD,DWORD,LPINT);
typedef SOCKET (WSPAPI *LPWPUFDISSET)(SOCKET,LPFD_SET);
typedef INT (WSPAPI *LPWPUGETPROVIDERPATH)(LPGUID,LPWSTR,LPINT,LPINT);
typedef SOCKET (WSPAPI *LPWPUMODIFYIFSHANDLE)(DWORD,SOCKET,LPINT);
typedef INT (WSPAPI *LPWPUOPENCURRENTTHREAD)(LPWSATHREADID,LPINT);
typedef BOOL (WSPAPI *LPWPUPOSTMESSAGE)(HWND,UINT,WPARAM,LPARAM);
typedef INT (WSPAPI *LPWPUQUERYBLOCKINGCALLBACK)(DWORD,LPBLOCKINGCALLBACK FAR*,LPDWORD,LPINT);
typedef INT (WSPAPI *LPWPUQUERYSOCKETHANDLECONTEXT)(SOCKET,LPDWORD,LPINT);
typedef INT (WSPAPI *LPWPUQUEUEAPC)(LPWSATHREADID,LPWSAUSERAPC,DWORD,LPINT);
typedef BOOL (WSPAPI *LPWPURESETEVENT)(WSAEVENT,LPINT);
typedef BOOL (WSPAPI *LPWPUSETEVENT)(WSAEVENT,LPINT);
/* Available only directly from the DLL */
typedef INT (WSPAPI *LPWPUCOMPLETEOVERLAPPEDREQUEST)(SOCKET,LPWSAOVERLAPPED,DWORD,DWORD,LPINT);

/* Service Provider upcall table */
typedef struct _WSPUPCALLTABLE {
	LPWPUCLOSEEVENT lpWPUCloseEvent;
	LPWPUCLOSESOCKETHANDLE lpWPUCloseSocketHandle;
	LPWPUCREATEEVENT lpWPUCreateEvent;
	LPWPUCREATESOCKETHANDLE lpWPUCreateSocketHandle;
	LPWPUFDISSET lpWPUFDIsSet;
	LPWPUGETPROVIDERPATH lpWPUGetProviderPath;
	LPWPUMODIFYIFSHANDLE lpWPUModifyIFSHandle;
	LPWPUPOSTMESSAGE lpWPUPostMessage;
	LPWPUQUERYBLOCKINGCALLBACK lpWPUQueryBlockingCallback;
	LPWPUQUERYSOCKETHANDLECONTEXT lpWPUQuerySocketHandleContext;
	LPWPUQUEUEAPC lpWPUQueueApc;
	LPWPURESETEVENT lpWPUResetEvent;
	LPWPUSETEVENT lpWPUSetEvent;
	LPWPUOPENCURRENTTHREAD lpWPUOpenCurrentThread;
	LPWPUCLOSETHREAD lpWPUCloseThread;
} WSPUPCALLTABLE, FAR* LPWSPUPCALLTABLE;

typedef INT (WSPAPI *LPWSPSTARTUP)(WORD,LPWSPDATA,LPWSAPROTOCOL_INFOW,WSPUPCALLTABLE,LPWSPPROC_TABLE);

/* Prototypes for service provider namespace procedure table */
typedef INT (WSPAPI *LPNSPCLEANUP)(LPGUID);
typedef INT (WSPAPI *LPNSPGETSERVICECLASSINFO)(LPGUID,LPDWORD,LPWSASERVICECLASSINFOW);
typedef INT (WSPAPI *LPNSPINSTALLSERVICECLASS)(LPGUID,LPWSASERVICECLASSINFOW);
typedef INT (WSPAPI *LPNSPLOOKUPSERVICEBEGIN)(LPGUID,LPWSAQUERYSETW,LPWSASERVICECLASSINFOW,DWORD,LPHANDLE);
typedef INT (WSPAPI *LPNSPLOOKUPSERVICEEND)(HANDLE);
typedef INT (WSPAPI *LPNSPLOOKUPSERVICENEXT)(HANDLE,DWORD,LPDWORD,LPWSAQUERYSET);
typedef INT (WSPAPI *LPNSPREMOVESERVICECLASS)(LPGUID,LPGUID);
typedef INT (WSPAPI *LPNSPSETSERVICE)(LPGUID,LPWSASERVICECLASSINFOW,LPWSAQUERYSETW,WSAESETSERVICEOP,DWORD);

typedef struct _NSP_ROUTINE {
  DWORD cbSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  LPNSPCLEANUP NSPCleanup;
  LPNSPLOOKUPSERVICEBEGIN NSPLookupServiceBegin;
  LPNSPLOOKUPSERVICENEXT NSPLookupServiceNext;
  LPNSPLOOKUPSERVICEEND NSPLookupServiceEnd;
  LPNSPSETSERVICE NSPSetService;
  LPNSPINSTALLSERVICECLASS NSPInstallServiceClass;
  LPNSPREMOVESERVICECLASS NSPRemoveServiceClass;
  LPNSPGETSERVICECLASSINFO NSPGetServiceClassInfo;
} NSP_ROUTINE, *PNSP_ROUTINE, *LPNSP_ROUTINE; 

INT WSPAPI NSPStartup(LPGUID,LPNSP_ROUTINE);

/* WinSock 2 DLL function prototypes */
INT WSPAPI WPUCompleteOverlappedRequest(SOCKET,LPWSAOVERLAPPED,DWORD,DWORD,LPINT);
INT WSPAPI WSPStartup(WORD,LPWSPDATA,LPWSAPROTOCOL_INFOW,WSPUPCALLTABLE,LPWSPPROC_TABLE);
INT WSPAPI WSCDeinstallProvider(LPGUID,LPINT);
INT WSPAPI WSCEnumProtocols(LPINT,LPWSAPROTOCOL_INFOW,LPDWORD,LPINT);
INT WSPAPI WSCGetProviderPath(LPGUID,LPWSTR,LPINT,LPINT);
INT WSPAPI WSCInstallProvider(CONST LPGUID,CONST LPWSTR,CONST LPWSAPROTOCOL_INFOW,DWORD,LPINT);
INT WSPAPI WSCEnableNSProvider(LPGUID,BOOL);
INT WSPAPI WSCInstallNameSpace(LPWSTR,LPWSTR,DWORD,DWORD,LPGUID);
INT WSPAPI WSCUnInstallNameSpace(LPGUID);
INT WSPAPI WSCWriteProviderOrder(LPDWORD,DWORD);

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WS2SPI_H */
