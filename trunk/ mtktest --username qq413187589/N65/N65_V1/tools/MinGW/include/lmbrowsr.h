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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmbrowsr.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmbrowsr.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Date: 2007/05/17 07:25:30 $
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
* $Log: lmbrowsr.h,v $
* Revision 1.1  2007/05/17 07:25:30  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmbrowsr.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmbrowsr.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Date: 2007/05/14 09:46:42 $
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
* ~Log: lmbrowsr.h,v $
* Revision 1.1  2007/05/14 09:46:42  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmbrowsr.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmbrowsr.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmbrowsr.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMBROWSR_H
#define _LMBROWSR_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define BROWSER_ROLE_PDC 1
#define BROWSER_ROLE_BDC 2
typedef struct _BROWSER_STATISTICS {
	LARGE_INTEGER StatisticsStartTime;
	LARGE_INTEGER NumberOfServerAnnouncements;
	LARGE_INTEGER NumberOfDomainAnnouncements;
	ULONG NumberOfElectionPackets;
	ULONG NumberOfMailslotWrites;
	ULONG NumberOfGetBrowserServerListRequests;
	ULONG NumberOfServerEnumerations;
	ULONG NumberOfDomainEnumerations;
	ULONG NumberOfOtherEnumerations;
	ULONG NumberOfMissedServerAnnouncements;
	ULONG NumberOfMissedMailslotDatagrams;
	ULONG NumberOfMissedGetBrowserServerListRequests;
	ULONG NumberOfFailedServerAnnounceAllocations;
	ULONG NumberOfFailedMailslotAllocations;
	ULONG NumberOfFailedMailslotReceives;
	ULONG NumberOfFailedMailslotWrites;
	ULONG NumberOfFailedMailslotOpens;
	ULONG NumberOfDuplicateMasterAnnouncements;
LARGE_INTEGER NumberOfIllegalDatagrams;
} BROWSER_STATISTICS,*PBROWSER_STATISTICS,*LPBROWSER_STATISTICS;
typedef struct _BROWSER_STATISTICS_100 {
	LARGE_INTEGER StartTime;
	LARGE_INTEGER NumberOfServerAnnouncements;
	LARGE_INTEGER NumberOfDomainAnnouncements;
	ULONG NumberOfElectionPackets;
	ULONG NumberOfMailslotWrites;
	ULONG NumberOfGetBrowserServerListRequests;
	LARGE_INTEGER NumberOfIllegalDatagrams;
} BROWSER_STATISTICS_100,*PBROWSER_STATISTICS_100;
typedef struct _BROWSER_STATISTICS_101 {
	LARGE_INTEGER StartTime;
	LARGE_INTEGER NumberOfServerAnnouncements;
	LARGE_INTEGER NumberOfDomainAnnouncements;
	ULONG NumberOfElectionPackets;
	ULONG NumberOfMailslotWrites;
	ULONG NumberOfGetBrowserServerListRequests;
	LARGE_INTEGER NumberOfIllegalDatagrams;
	ULONG NumberOfMissedServerAnnouncements;
	ULONG NumberOfMissedMailslotDatagrams;
	ULONG NumberOfMissedGetBrowserServerListRequests;
	ULONG NumberOfFailedServerAnnounceAllocations;
	ULONG NumberOfFailedMailslotAllocations;
	ULONG NumberOfFailedMailslotReceives;
	ULONG NumberOfFailedMailslotWrites;
	ULONG NumberOfFailedMailslotOpens;
	ULONG NumberOfDuplicateMasterAnnouncements;
} BROWSER_STATISTICS_101,*PBROWSER_STATISTICS_101;

NET_API_STATUS WINAPI I_BrowserServerEnum(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,DWORD,LPCWSTR,PDWORD);
NET_API_STATUS WINAPI I_BrowserServerEnumEx(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,DWORD,LPCWSTR,LPCWSTR);
NET_API_STATUS I_BrowserQueryEmulatedDomains(LPWSTR,PBYTE*,PDWORD);
NET_API_STATUS I_BrowserQueryOtherDomains(LPCWSTR,PBYTE*,PDWORD,PDWORD);
NET_API_STATUS I_BrowserResetNetlogonState(LPCWSTR);
NET_API_STATUS I_BrowserSetNetlogonState(LPWSTR,LPWSTR,LPWSTR,DWORD);
NET_API_STATUS I_BrowserQueryStatistics(LPCWSTR,LPBROWSER_STATISTICS*);
NET_API_STATUS I_BrowserResetStatistics(LPCWSTR);
WORD I_BrowserServerEnumForXactsrv(LPCWSTR,LPCWSTR,ULONG,USHORT,PVOID,WORD,DWORD,PDWORD,PDWORD,DWORD,LPCWSTR,LPCWSTR,PWORD);
NET_API_STATUS I_BrowserDebugTrace(PWCHAR,PCHAR);
#ifdef __cplusplus
}
#endif
#endif 
