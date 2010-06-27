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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmsname.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmsname.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmsname.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmsname.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmsname.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmsname.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmsname.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmsname.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmsname.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMSNAME_H
#define _LMSNAME_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define SERVICE_WORKSTATION TEXT("LanmanWorkstation")
#define SERVICE_LM20_WORKSTATION TEXT("WORKSTATION")
#define WORKSTATION_DISPLAY_NAME TEXT("Workstation")
#define SERVICE_SERVER TEXT("LanmanServer")
#define SERVICE_LM20_SERVER TEXT("SERVER")
#define SERVER_DISPLAY_NAME TEXT("Server")
#define SERVICE_BROWSER TEXT("BROWSER")
#define SERVICE_LM20_BROWSER SERVICE_BROWSER
#define SERVICE_MESSENGER TEXT("MESSENGER")
#define SERVICE_LM20_MESSENGER SERVICE_MESSENGER
#define SERVICE_NETRUN TEXT("NETRUN")
#define SERVICE_LM20_NETRUN SERVICE_NETRUN
#define SERVICE_SPOOLER TEXT("SPOOLER")
#define SERVICE_LM20_SPOOLER SERVICE_SPOOLER
#define SERVICE_ALERTER TEXT("ALERTER")
#define SERVICE_LM20_ALERTER SERVICE_ALERTER
#define SERVICE_NETLOGON TEXT("NETLOGON")
#define SERVICE_LM20_NETLOGON SERVICE_NETLOGON
#define SERVICE_NETPOPUP TEXT("NETPOPUP")
#define SERVICE_LM20_NETPOPUP SERVICE_NETPOPUP
#define SERVICE_SQLSERVER TEXT("SQLSERVER")
#define SERVICE_LM20_SQLSERVER SERVICE_SQLSERVER
#define SERVICE_REPL TEXT("REPLICATOR")
#define SERVICE_LM20_REPL SERVICE_REPL
#define SERVICE_RIPL TEXT("REMOTEBOOT")
#define SERVICE_LM20_RIPL SERVICE_RIPL
#define SERVICE_TIMESOURCE TEXT("TIMESOURCE")
#define SERVICE_LM20_TIMESOURCE SERVICE_TIMESOURCE
#define SERVICE_AFP TEXT("AFP")
#define SERVICE_LM20_AFP SERVICE_AFP
#define SERVICE_UPS TEXT("UPS")
#define SERVICE_LM20_UPS SERVICE_UPS
#define SERVICE_XACTSRV TEXT("XACTSRV")
#define SERVICE_LM20_XACTSRV SERVICE_XACTSRV
#define SERVICE_TCPIP TEXT("TCPIP")
#define SERVICE_LM20_TCPIP SERVICE_TCPIP
#define SERVICE_NBT TEXT("NBT")
#define SERVICE_LM20_NBT SERVICE_NBT
#define SERVICE_LMHOSTS TEXT("LMHOSTS")
#define SERVICE_LM20_LMHOSTS SERVICE_LMHOSTS
#define SERVICE_TELNET TEXT("Telnet")
#define SERVICE_LM20_TELNET SERVICE_TELNET
#define SERVICE_SCHEDULE TEXT("Schedule")
#define SERVICE_LM20_SCHEDULE SERVICE_SCHEDULE
#define SERVICE_NTLMSSP TEXT("NtLmSsp")
#define SERVICE_DHCP TEXT("DHCP")
#define SERVICE_LM20_DHCP SERVICE_DHCP
#define SERVICE_NWSAP TEXT("NwSapAgent")
#define SERVICE_LM20_NWSAP SERVICE_NWSAP
#define NWSAP_DISPLAY_NAME TEXT("NW Sap Agent")
#define SERVICE_NWCS TEXT("NWCWorkstation")
#endif
