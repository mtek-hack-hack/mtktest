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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mgmtapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mgmtapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: mgmtapi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mgmtapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Id: mgmtapi.h,v 1.1 2007/05/14 09:46:44 bw Exp $
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
* ~Log: mgmtapi.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mgmtapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mgmtapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mgmtapi.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
  mgmtapi.h - Header file for the SNMP Management API

  Written by Filip Navara <xnavara@volny.cz>

  References (2003-08-25):
    http://msdn.microsoft.com/library/en-us/snmp/snmp/snmp_reference.asp

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef _MGMTAPI_H
#define _MGMTAPI_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef _SNMP_H
#include <snmp.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SNMP_MGMTAPI_TIMEOUT	40
#define SNMP_MGMTAPI_SELECT_FDERRORS	41
#define SNMP_MGMTAPI_TRAP_ERRORS	42
#define SNMP_MGMTAPI_TRAP_DUPINIT	43
#define SNMP_MGMTAPI_NOTRAPS	44
#define SNMP_MGMTAPI_AGAIN	45
#define SNMP_MGMTAPI_INVALID_CTL	46
#define SNMP_MGMTAPI_INVALID_SESSION	47
#define SNMP_MGMTAPI_INVALID_BUFFER	48
#define MGMCTL_SETAGENTPORT	1

#ifndef RC_INVOKED

typedef PVOID LPSNMP_MGR_SESSION;

BOOL WINSNMPAPI SnmpMgrClose(LPSNMP_MGR_SESSION);
BOOL WINSNMPAPI SnmpMgrCtl(LPSNMP_MGR_SESSION,DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD);
BOOL WINSNMPAPI SnmpMgrGetTrap(AsnObjectIdentifier*,AsnNetworkAddress*,AsnInteger*,AsnInteger*,AsnTimeticks*,SnmpVarBindList*);
BOOL WINSNMPAPI SnmpMgrGetTrapEx(AsnObjectIdentifier*,AsnNetworkAddress*,AsnNetworkAddress*,AsnInteger*,AsnInteger*,AsnOctetString*,AsnTimeticks*,SnmpVarBindList*);
BOOL WINSNMPAPI SnmpMgrOidToStr(AsnObjectIdentifier*,LPSTR*);
LPSNMP_MGR_SESSION WINSNMPAPI SnmpMgrOpen(LPSTR,LPSTR,INT,INT);
INT WINSNMPAPI SnmpMgrRequest(LPSNMP_MGR_SESSION,BYTE,SnmpVarBindList*,AsnInteger*,AsnInteger*);
BOOL WINSNMPAPI SnmpMgrStrToOid(LPSTR,AsnObjectIdentifier*);
BOOL WINSNMPAPI SnmpMgrTrapListen(HANDLE*);

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif
#endif
