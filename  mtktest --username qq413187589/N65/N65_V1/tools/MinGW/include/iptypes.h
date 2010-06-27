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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/iptypes.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Id: iptypes.h,v 1.1 2007/05/17 07:25:29 bw Exp $
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
* $Log: iptypes.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/iptypes.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Id: iptypes.h,v 1.1 2007/05/14 09:46:41 bw Exp $
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
* ~Log: iptypes.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/iptypes.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: iptypes.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: iptypes.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _IPTYPES_H
#define _IPTYPES_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <sys/types.h>
#ifdef __cplusplus
extern "C" {
#endif
#define DEFAULT_MINIMUM_ENTITIES 32
#define MAX_ADAPTER_ADDRESS_LENGTH 8
#define MAX_ADAPTER_DESCRIPTION_LENGTH 128
#define MAX_ADAPTER_NAME_LENGTH 256
#define MAX_DOMAIN_NAME_LEN 128
#define MAX_HOSTNAME_LEN 128
#define MAX_SCOPE_ID_LEN 256
#define BROADCAST_NODETYPE 1
#define PEER_TO_PEER_NODETYPE 2
#define MIXED_NODETYPE 4
#define HYBRID_NODETYPE 8
#define IF_OTHER_ADAPTERTYPE 0
#define IF_ETHERNET_ADAPTERTYPE 1
#define IF_TOKEN_RING_ADAPTERTYPE 2
#define IF_FDDI_ADAPTERTYPE 3
#define IF_PPP_ADAPTERTYPE 4
#define IF_LOOPBACK_ADAPTERTYPE 5
typedef struct {
  char String[16];
} IP_ADDRESS_STRING, *PIP_ADDRESS_STRING, IP_MASK_STRING, *PIP_MASK_STRING;
typedef struct _IP_ADDR_STRING {
  struct _IP_ADDR_STRING* Next;
  IP_ADDRESS_STRING IpAddress;
  IP_MASK_STRING IpMask;
  DWORD Context;
} IP_ADDR_STRING, *PIP_ADDR_STRING;
typedef struct _IP_ADAPTER_INFO {
  struct _IP_ADAPTER_INFO* Next;
  DWORD ComboIndex;
  char AdapterName[MAX_ADAPTER_NAME_LENGTH+4];
  char Description[MAX_ADAPTER_DESCRIPTION_LENGTH+4];
  UINT AddressLength;
  BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
  DWORD Index;
  UINT Type;
  UINT DhcpEnabled;
  PIP_ADDR_STRING CurrentIpAddress;
  IP_ADDR_STRING IpAddressList;
  IP_ADDR_STRING GatewayList;
  IP_ADDR_STRING DhcpServer;
  BOOL HaveWins;
  IP_ADDR_STRING PrimaryWinsServer;
  IP_ADDR_STRING SecondaryWinsServer;
  time_t LeaseObtained;
  time_t LeaseExpires;
} IP_ADAPTER_INFO, *PIP_ADAPTER_INFO;
typedef struct _IP_PER_ADAPTER_INFO {
  UINT AutoconfigEnabled;
  UINT AutoconfigActive;
  PIP_ADDR_STRING CurrentDnsServer;
  IP_ADDR_STRING DnsServerList;
} IP_PER_ADAPTER_INFO, *PIP_PER_ADAPTER_INFO;
typedef struct _FIXED_INFO {
  char HostName[MAX_HOSTNAME_LEN+4] ;
  char DomainName[MAX_DOMAIN_NAME_LEN+4];
  PIP_ADDR_STRING CurrentDnsServer;
  IP_ADDR_STRING DnsServerList;
  UINT NodeType;
  char ScopeId[MAX_SCOPE_ID_LEN+4];
  UINT EnableRouting;
  UINT EnableProxy;
  UINT EnableDns;
} FIXED_INFO, *PFIXED_INFO;

#ifdef __cplusplus
}
#endif
#endif /* _IPTYPES_H */
