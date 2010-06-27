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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/iphlpapi.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Id: iphlpapi.h,v 1.1 2007/05/17 07:25:29 bw Exp $
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
* $Log: iphlpapi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/iphlpapi.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Id: iphlpapi.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Date: 2007/05/14 09:46:41 $
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
* ~Log: iphlpapi.h,v $
* Revision 1.1  2007/05/14 09:46:41  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/iphlpapi.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: iphlpapi.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: iphlpapi.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _IPHLPAPI_H
#define _IPHLPAPI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <iprtrmib.h>
#include <ipexport.h>
#include <iptypes.h>
#ifdef __cplusplus
extern "C" {
#endif
DWORD WINAPI AddIPAddress(IPAddr,IPMask,DWORD,PULONG,PULONG);
DWORD WINAPI CreateIpForwardEntry(PMIB_IPFORWARDROW);
DWORD WINAPI CreateIpNetEntry(PMIB_IPNETROW);
DWORD WINAPI CreateProxyArpEntry(DWORD,DWORD,DWORD);
DWORD WINAPI DeleteIPAddress(ULONG);
DWORD WINAPI DeleteIpForwardEntry(PMIB_IPFORWARDROW);
DWORD WINAPI DeleteIpNetEntry(PMIB_IPNETROW);
DWORD WINAPI DeleteProxyArpEntry(DWORD,DWORD,DWORD);
DWORD WINAPI EnableRouter(HANDLE*,OVERLAPPED*);
DWORD WINAPI FlushIpNetTable(DWORD);
DWORD WINAPI GetAdapterIndex(LPWSTR,PULONG);
DWORD WINAPI GetAdaptersInfo(PIP_ADAPTER_INFO,PULONG);
DWORD WINAPI GetBestInterface(IPAddr,PDWORD);
DWORD WINAPI GetBestRoute(DWORD,DWORD,PMIB_IPFORWARDROW);
DWORD WINAPI GetFriendlyIfIndex(DWORD);
DWORD WINAPI GetIcmpStatistics(PMIB_ICMP);
DWORD WINAPI GetIfEntry(PMIB_IFROW);
DWORD WINAPI GetIfTable(PMIB_IFTABLE,PULONG,BOOL);
DWORD WINAPI GetInterfaceInfo(PIP_INTERFACE_INFO,PULONG);
DWORD WINAPI GetIpAddrTable(PMIB_IPADDRTABLE,PULONG,BOOL);
DWORD WINAPI GetIpForwardTable(PMIB_IPFORWARDTABLE,PULONG,BOOL);
DWORD WINAPI GetIpNetTable(PMIB_IPNETTABLE,PULONG,BOOL);
DWORD WINAPI GetIpStatistics(PMIB_IPSTATS);
DWORD WINAPI GetNetworkParams(PFIXED_INFO,PULONG);
DWORD WINAPI GetNumberOfInterfaces(PDWORD);
DWORD WINAPI GetPerAdapterInfo(ULONG,PIP_PER_ADAPTER_INFO, PULONG);
BOOL WINAPI GetRTTAndHopCount(IPAddr,PULONG,ULONG,PULONG);
DWORD WINAPI GetTcpStatistics(PMIB_TCPSTATS);
DWORD WINAPI GetTcpTable(PMIB_TCPTABLE,PDWORD,BOOL);
DWORD WINAPI GetUniDirectionalAdapterInfo(PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS,PULONG);
DWORD WINAPI GetUdpStatistics(PMIB_UDPSTATS);
DWORD WINAPI GetUdpTable(PMIB_UDPTABLE,PDWORD,BOOL);
DWORD WINAPI IpReleaseAddress(PIP_ADAPTER_INDEX_MAP);
DWORD WINAPI IpRenewAddress(PIP_ADAPTER_INDEX_MAP);
DWORD WINAPI NotifyAddrChange(PHANDLE,LPOVERLAPPED);
DWORD WINAPI NotifyRouteChange(PHANDLE,LPOVERLAPPED);
DWORD WINAPI SendARP(IPAddr,IPAddr,PULONG,PULONG);
DWORD WINAPI SetIfEntry(PMIB_IFROW);
DWORD WINAPI SetIpForwardEntry(PMIB_IPFORWARDROW);
DWORD WINAPI SetIpNetEntry(PMIB_IPNETROW);
DWORD WINAPI SetIpStatistics(PMIB_IPSTATS);
DWORD WINAPI SetIpTTL(UINT);
DWORD WINAPI SetTcpEntry(PMIB_TCPROW);
DWORD WINAPI UnenableRouter(OVERLAPPED*, LPDWORD);
#ifdef __cplusplus
}
#endif
#endif /* _IPHLPAPI_H */
