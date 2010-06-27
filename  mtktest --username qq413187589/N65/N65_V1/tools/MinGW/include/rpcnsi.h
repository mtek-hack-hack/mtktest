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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/rpcnsi.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: rpcnsi.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Date: 2007/05/17 07:25:33 $
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
* $Log: rpcnsi.h,v $
* Revision 1.1  2007/05/17 07:25:33  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/rpcnsi.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: rpcnsi.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Date: 2007/05/14 09:46:48 $
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
* ~Log: rpcnsi.h,v $
* Revision 1.1  2007/05/14 09:46:48  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/rpcnsi.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: rpcnsi.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Date: 2007/04/04 06:51:33 $
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
* ~Log: rpcnsi.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _RPCNSI_H
#define _RPCNSI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef void *RPC_NS_HANDLE;
#define RPC_C_NS_SYNTAX_DEFAULT 0
#define RPC_C_NS_SYNTAX_DCE 3
#define RPC_C_PROFILE_DEFAULT_ELT 0
#define RPC_C_PROFILE_ALL_ELT 1
#define RPC_C_PROFILE_MATCH_BY_IF 2
#define RPC_C_PROFILE_MATCH_BY_MBR 3
#define RPC_C_PROFILE_MATCH_BY_BOTH 4
#define RPC_C_NS_DEFAULT_EXP_AGE -1

RPC_STATUS RPC_ENTRY RpcNsBindingExportA(unsigned long,unsigned char*,RPC_IF_HANDLE,RPC_BINDING_VECTOR*,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsBindingUnexportA(unsigned long,unsigned char*,RPC_IF_HANDLE,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsBindingLookupBeginA(unsigned long,unsigned char*,RPC_IF_HANDLE,UUID*,unsigned long,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsBindingLookupNext(RPC_NS_HANDLE,RPC_BINDING_VECTOR**);
RPC_STATUS RPC_ENTRY RpcNsBindingLookupDone(RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsGroupDeleteA(unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrAddA(unsigned long,unsigned char*,unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrRemoveA(unsigned long,unsigned char*,unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrInqBeginA(unsigned long,unsigned char*,unsigned long,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrInqNextA(RPC_NS_HANDLE,unsigned char**);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrInqDone(RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsProfileDeleteA(unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltAddA(unsigned long,unsigned char*,RPC_IF_ID*,unsigned long,unsigned char*,unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltRemoveA(unsigned long,unsigned char*,RPC_IF_ID*,unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltInqBeginA(unsigned long,unsigned char*,unsigned long,RPC_IF_ID*,unsigned long,unsigned long,unsigned char*,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltInqNextA(RPC_NS_HANDLE,RPC_IF_ID*,unsigned char**,unsigned long*,unsigned char**);
RPC_STATUS RPC_ENTRY RpcNsProfileEltInqDone(RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsEntryObjectInqNext(IN  RPC_NS_HANDLE,OUT UUID*);
RPC_STATUS RPC_ENTRY RpcNsEntryObjectInqDone(IN OUT RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsEntryExpandNameA(unsigned long,unsigned char*,unsigned char**);
RPC_STATUS RPC_ENTRY RpcNsMgmtBindingUnexportA(unsigned long,unsigned char*,RPC_IF_ID*,unsigned long,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryCreateA(unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryDeleteA(unsigned long,unsigned char*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryInqIfIdsA(unsigned long,unsigned char*,RPC_IF_ID_VECTOR**);
RPC_STATUS RPC_ENTRY RpcNsMgmtHandleSetExpAge(RPC_NS_HANDLE,unsigned long);
RPC_STATUS RPC_ENTRY RpcNsMgmtInqExpAge(unsigned long*);
RPC_STATUS RPC_ENTRY RpcNsMgmtSetExpAge(unsigned long);
RPC_STATUS RPC_ENTRY RpcNsBindingImportNext(RPC_NS_HANDLE,RPC_BINDING_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsBindingImportDone(RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsBindingSelect(RPC_BINDING_VECTOR*,RPC_BINDING_HANDLE*);
#ifndef UNICODE_ONLY
RPC_STATUS RPC_ENTRY RpcNsEntryObjectInqBeginA(unsigned long,unsigned char*,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsBindingImportBeginA(unsigned long,unsigned char*,RPC_IF_HANDLE,UUID*,RPC_NS_HANDLE*);
#endif
#ifdef RPC_UNICODE_SUPPORTED
RPC_STATUS RPC_ENTRY RpcNsBindingExportW(unsigned long,unsigned short*,RPC_IF_HANDLE,RPC_BINDING_VECTOR*,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsBindingUnexportW(unsigned long,unsigned short*,RPC_IF_HANDLE,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsBindingLookupBeginW(unsigned long,unsigned short*,RPC_IF_HANDLE,UUID*,unsigned long,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsGroupDeleteW(unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrAddW(unsigned long,unsigned short*,unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrRemoveW(unsigned long,unsigned short*,unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrInqBeginW(unsigned long,unsigned short*,unsigned long,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsGroupMbrInqNextW(RPC_NS_HANDLE,unsigned short**);
RPC_STATUS RPC_ENTRY RpcNsProfileDeleteW(unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltAddW(unsigned long,unsigned short*, RPC_IF_ID*,unsigned long,unsigned short*,unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltRemoveW(unsigned long,unsigned short*, RPC_IF_ID*,unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltInqBeginW(unsigned long,unsigned short*, unsigned long,RPC_IF_ID*,unsigned long,unsigned long,unsigned short*, RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsProfileEltInqNextW(RPC_NS_HANDLE,RPC_IF_ID*, unsigned short**,unsigned long*,unsigned short**);
RPC_STATUS RPC_ENTRY RpcNsEntryObjectInqBeginW(unsigned long,unsigned short*,RPC_NS_HANDLE*);
RPC_STATUS RPC_ENTRY RpcNsEntryExpandNameW(unsigned long,unsigned short*,unsigned short**);
RPC_STATUS RPC_ENTRY RpcNsMgmtBindingUnexportW(unsigned long,unsigned short*,RPC_IF_ID*,unsigned long,UUID_VECTOR*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryCreateW(unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryDeleteW(unsigned long,unsigned short*);
RPC_STATUS RPC_ENTRY RpcNsMgmtEntryInqIfIdsW(unsigned long,unsigned short , RPC_IF_ID_VECTOR**);
RPC_STATUS RPC_ENTRY RpcNsBindingImportBeginW(unsigned long,unsigned short*,RPC_IF_HANDLE,UUID*,RPC_NS_HANDLE*);
#endif /* RPC_UNICODE_SUPPORTED */
#ifdef UNICODE
#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginW
#define RpcNsBindingImportBegin RpcNsBindingImportBeginW
#define RpcNsBindingExport RpcNsBindingExportW
#define RpcNsBindingUnexport RpcNsBindingUnexportW
#define RpcNsGroupDelete RpcNsGroupDeleteW
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddW
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveW
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginW
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextW
#define RpcNsEntryExpandName RpcNsEntryExpandNameW
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginW
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportW
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateW
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteW
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsW
#define RpcNsProfileDelete RpcNsProfileDeleteW
#define RpcNsProfileEltAdd RpcNsProfileEltAddW
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveW
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginW
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextW
#else
#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginA
#define RpcNsBindingImportBegin RpcNsBindingImportBeginA
#define RpcNsBindingExport RpcNsBindingExportA
#define RpcNsBindingUnexport RpcNsBindingUnexportA
#define RpcNsGroupDelete RpcNsGroupDeleteA
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddA
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveA
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginA
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextA
#define RpcNsEntryExpandName RpcNsEntryExpandNameA
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginA
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportA
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateA
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteA
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsA
#define RpcNsProfileDelete RpcNsProfileDeleteA
#define RpcNsProfileEltAdd RpcNsProfileEltAddA
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveA
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginA
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextA
#endif
#ifdef __cplusplus
}
#endif
#endif
