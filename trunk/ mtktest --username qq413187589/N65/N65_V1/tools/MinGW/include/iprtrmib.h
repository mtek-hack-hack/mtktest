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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/iprtrmib.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Id: iprtrmib.h,v 1.1 2007/05/17 07:25:29 bw Exp $
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
* $Log: iprtrmib.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/iprtrmib.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Id: iprtrmib.h,v 1.1 2007/05/14 09:46:41 bw Exp $
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
* ~Log: iprtrmib.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/iprtrmib.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: iprtrmib.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: iprtrmib.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _IPRTRMIB_H
#define _IPRTRMIB_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <ipifcons.h>
#ifdef __cplusplus
extern "C" {
#endif
#ifndef ANY_SIZE
#define ANY_SIZE 1
#endif
#define MAXLEN_PHYSADDR 8
#define MAXLEN_IFDESCR 256
#ifndef MAX_INTERFACE_NAME_LEN
#define MAX_INTERFACE_NAME_LEN 256
#endif
#define MIB_IPNET_TYPE_OTHER 1
#define MIB_IPNET_TYPE_INVALID 2
#define MIB_IPNET_TYPE_DYNAMIC 3
#define MIB_IPNET_TYPE_STATIC 4
#define MIB_TCP_RTO_OTHER 1
#define MIB_TCP_RTO_CONSTANT 2
#define MIB_TCP_RTO_RSRE 3
#define MIB_TCP_RTO_VANJ 4
#define MIB_TCP_STATE_CLOSED 1                 
#define MIB_TCP_STATE_LISTEN 2                 
#define MIB_TCP_STATE_SYN_SENT 3                 
#define MIB_TCP_STATE_SYN_RCVD 4                 
#define MIB_TCP_STATE_ESTAB 5                 
#define MIB_TCP_STATE_FIN_WAIT1 6                 
#define MIB_TCP_STATE_FIN_WAIT2 7                 
#define MIB_TCP_STATE_CLOSE_WAIT 8                 
#define MIB_TCP_STATE_CLOSING 9                
#define MIB_TCP_STATE_LAST_ACK 10                
#define MIB_TCP_STATE_TIME_WAIT 11                
#define MIB_TCP_STATE_DELETE_TCB 12                
#define MIB_USE_CURRENT_TTL ((DWORD)-1)
#define MIB_USE_CURRENT_FORWARDING ((DWORD)-1)
#define MIB_TCP_MAXCONN_DYNAMIC ((DWORD)-1)
typedef struct {
  DWORD dwAddr;
  DWORD dwIndex;
  DWORD dwMask;
  DWORD dwBCastAddr;
  DWORD dwReasmSize;
  unsigned short unused1;
  unsigned short unused2;
} MIB_IPADDRROW, *PMIB_IPADDRROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_IPADDRROW table[ANY_SIZE];
} MIB_IPADDRTABLE, *PMIB_IPADDRTABLE;
typedef struct {
  DWORD dwForwardDest;
  DWORD dwForwardMask;
  DWORD dwForwardPolicy;
  DWORD dwForwardNextHop;
  DWORD dwForwardIfIndex;
  DWORD dwForwardType;
  DWORD dwForwardProto;
  DWORD dwForwardAge;
  DWORD dwForwardNextHopAS;
  DWORD dwForwardMetric1;
  DWORD dwForwardMetric2;
  DWORD dwForwardMetric3;
  DWORD dwForwardMetric4;
  DWORD dwForwardMetric5;
} MIB_IPFORWARDROW, *PMIB_IPFORWARDROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_IPFORWARDROW table[ANY_SIZE];
} MIB_IPFORWARDTABLE, *PMIB_IPFORWARDTABLE;
typedef struct {
  DWORD dwIndex;
  DWORD dwPhysAddrLen;
  BYTE bPhysAddr[MAXLEN_PHYSADDR];
  DWORD dwAddr;
  DWORD dwType;
} MIB_IPNETROW, *PMIB_IPNETROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_IPNETROW table[ANY_SIZE];
} MIB_IPNETTABLE, *PMIB_IPNETTABLE;
typedef struct {
  DWORD dwMsgs;
  DWORD dwErrors;
  DWORD dwDestUnreachs;
  DWORD dwTimeExcds;
  DWORD dwParmProbs;
  DWORD dwSrcQuenchs;
  DWORD dwRedirects;
  DWORD dwEchos;
  DWORD dwEchoReps;
  DWORD dwTimestamps;
  DWORD dwTimestampReps;
  DWORD dwAddrMasks;
  DWORD dwAddrMaskReps;
} MIBICMPSTATS, *PMIBICMPSTATS;
typedef struct {
  MIBICMPSTATS icmpInStats;
  MIBICMPSTATS icmpOutStats;
} MIBICMPINFO, *PMIBICMPINFO;
typedef struct {
  MIBICMPINFO stats;
} MIB_ICMP, *PMIB_ICMP;
typedef struct {
  WCHAR wszName[MAX_INTERFACE_NAME_LEN];
  DWORD dwIndex;
  DWORD dwType;
  DWORD dwMtu;
  DWORD dwSpeed;
  DWORD dwPhysAddrLen;
  BYTE bPhysAddr[MAXLEN_PHYSADDR];
  DWORD dwAdminStatus;
  DWORD dwOperStatus;
  DWORD dwLastChange;
  DWORD dwInOctets;
  DWORD dwInUcastPkts;
  DWORD dwInNUcastPkts;
  DWORD dwInDiscards;
  DWORD dwInErrors;
  DWORD dwInUnknownProtos;
  DWORD dwOutOctets;
  DWORD dwOutUcastPkts;
  DWORD dwOutNUcastPkts;
  DWORD dwOutDiscards;
  DWORD dwOutErrors;
  DWORD dwOutQLen;
  DWORD dwDescrLen;
  BYTE  bDescr[MAXLEN_IFDESCR];
} MIB_IFROW, *PMIB_IFROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_IFROW table[ANY_SIZE];
} MIB_IFTABLE, *PMIB_IFTABLE;
typedef struct {
  DWORD dwForwarding;
  DWORD dwDefaultTTL;
  DWORD dwInReceives;
  DWORD dwInHdrErrors;
  DWORD dwInAddrErrors;
  DWORD dwForwDatagrams;
  DWORD dwInUnknownProtos;
  DWORD dwInDiscards;
  DWORD dwInDelivers;
  DWORD dwOutRequests;
  DWORD dwRoutingDiscards;
  DWORD dwOutDiscards;
  DWORD dwOutNoRoutes;
  DWORD dwReasmTimeout;
  DWORD dwReasmReqds;
  DWORD dwReasmOks;
  DWORD dwReasmFails;
  DWORD dwFragOks;
  DWORD dwFragFails;
  DWORD dwFragCreates;
  DWORD dwNumIf;
  DWORD dwNumAddr;
  DWORD dwNumRoutes;
} MIB_IPSTATS, *PMIB_IPSTATS;
typedef struct {
  DWORD dwRtoAlgorithm;
  DWORD dwRtoMin;
  DWORD dwRtoMax;
  DWORD dwMaxConn;
  DWORD dwActiveOpens;
  DWORD dwPassiveOpens;
  DWORD dwAttemptFails;
  DWORD dwEstabResets;
  DWORD dwCurrEstab;
  DWORD dwInSegs;
  DWORD dwOutSegs;
  DWORD dwRetransSegs;
  DWORD dwInErrs;
  DWORD dwOutRsts;
  DWORD dwNumConns;
} MIB_TCPSTATS, *PMIB_TCPSTATS;
typedef struct {
  DWORD dwState;
  DWORD dwLocalAddr;
  DWORD dwLocalPort;
  DWORD dwRemoteAddr;
  DWORD dwRemotePort;
} MIB_TCPROW, *PMIB_TCPROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_TCPROW table[ANY_SIZE];
} MIB_TCPTABLE, *PMIB_TCPTABLE;
typedef struct {
  DWORD dwInDatagrams;
  DWORD dwNoPorts;
  DWORD dwInErrors;
  DWORD dwOutDatagrams;
  DWORD dwNumAddrs;
} MIB_UDPSTATS, *PMIB_UDPSTATS;
typedef struct {
  DWORD dwLocalAddr;
  DWORD dwLocalPort;
} MIB_UDPROW, *PMIB_UDPROW;
typedef struct {
  DWORD dwNumEntries;
  MIB_UDPROW table[ANY_SIZE];
} MIB_UDPTABLE, *PMIB_UDPTABLE;
#ifdef __cplusplus
}
#endif
#endif /* _IPRTRMIB_H */
