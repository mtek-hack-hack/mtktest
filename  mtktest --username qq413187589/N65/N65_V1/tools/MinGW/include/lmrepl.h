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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmrepl.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmrepl.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmrepl.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmrepl.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmrepl.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmrepl.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmrepl.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmrepl.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmrepl.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMREPL_H
#define _LMREPL_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define REPL_ROLE_EXPORT 1
#define REPL_ROLE_IMPORT 2
#define REPL_ROLE_BOTH 3
#define REPL_INTERVAL_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+0)
#define REPL_PULSE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+1)
#define REPL_GUARDTIME_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+2)
#define REPL_RANDOM_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+3)
#define REPL_UNLOCK_NOFORCE 0
#define REPL_UNLOCK_FORCE 1
#define REPL_STATE_OK 0
#define REPL_STATE_NO_MASTER 1
#define REPL_STATE_NO_SYNC 2
#define REPL_STATE_NEVER_REPLICATED 3
#define REPL_INTEGRITY_FILE 1
#define REPL_INTEGRITY_TREE 2
#define REPL_EXTENT_FILE 1
#define REPL_EXTENT_TREE 2
#define REPL_EXPORT_INTEGRITY_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+0)
#define REPL_EXPORT_EXTENT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+1)
typedef struct _REPL_INFO_0 {
	DWORD rp0_role;
	LPWSTR rp0_exportpath;
	LPWSTR rp0_exportlist;
	LPWSTR rp0_importpath;
	LPWSTR rp0_importlist;
	LPWSTR rp0_logonusername;
	DWORD rp0_interval;
	DWORD rp0_pulse;
	DWORD rp0_guardtime;
	DWORD rp0_random;
} REPL_INFO_0,*PREPL_INFO_0,*LPREPL_INFO_0;
typedef struct _REPL_INFO_1000 { DWORD rp1000_interval; } REPL_INFO_1000,*PREPL_INFO_1000,*LPREPL_INFO_1000;
typedef struct _REPL_INFO_1001 { DWORD rp1001_pulse; } REPL_INFO_1001,*PREPL_INFO_1001,*LPREPL_INFO_1001;
typedef struct _REPL_INFO_1002 { DWORD rp1002_guardtime; } REPL_INFO_1002,*PREPL_INFO_1002,*LPREPL_INFO_1002;
typedef struct _REPL_INFO_1003 { DWORD rp1003_random; } REPL_INFO_1003,*PREPL_INFO_1003,*LPREPL_INFO_1003;

NET_API_STATUS WINAPI NetReplGetInfo(LPCWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetReplSetInfo(LPCWSTR,DWORD,PBYTE,PDWORD);
typedef struct _REPL_EDIR_INFO_0 {
	LPWSTR rped0_dirname;
} REPL_EDIR_INFO_0,*PREPL_EDIR_INFO_0,*LPREPL_EDIR_INFO_0;
typedef struct _REPL_EDIR_INFO_1 {
	LPWSTR rped1_dirname;
	DWORD rped1_integrity;
	DWORD rped1_extent;
} REPL_EDIR_INFO_1,*PREPL_EDIR_INFO_1,*LPREPL_EDIR_INFO_1;
typedef struct _REPL_EDIR_INFO_2 {
	LPWSTR rped2_dirname;
	DWORD rped2_integrity;
	DWORD rped2_extent;
	DWORD rped2_lockcount;
	DWORD rped2_locktime;
} REPL_EDIR_INFO_2,*PREPL_EDIR_INFO_2,*LPREPL_EDIR_INFO_2;
typedef struct _REPL_EDIR_INFO_1000 {
	DWORD rped1000_integrity;
} REPL_EDIR_INFO_1000,*PREPL_EDIR_INFO_1000,*LPREPL_EDIR_INFO_1000;
typedef struct _REPL_EDIR_INFO_1001 {
	DWORD rped1001_extent;
} REPL_EDIR_INFO_1001,*PREPL_EDIR_INFO_1001,*LPREPL_EDIR_INFO_1001;
typedef struct _REPL_IDIR_INFO_0 { LPWSTR rpid0_dirname; } REPL_IDIR_INFO_0,*PREPL_IDIR_INFO_0,*LPREPL_IDIR_INFO_0;
typedef struct _REPL_IDIR_INFO_1 {
	LPWSTR rpid1_dirname;
	DWORD rpid1_state;
	LPWSTR rpid1_mastername;
	DWORD rpid1_last_update_time;
	DWORD rpid1_lockcount;
	DWORD rpid1_locktime;
} REPL_IDIR_INFO_1,*PREPL_IDIR_INFO_1,*LPREPL_IDIR_INFO_1;
NET_API_STATUS WINAPI NetReplExportDirAdd(LPCWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS WINAPI NetReplExportDirDel(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetReplExportDirEnum(LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetReplExportDirGetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetReplExportDirSetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS WINAPI NetReplExportDirLock(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetReplExportDirUnlock(LPCWSTR,LPCWSTR,DWORD);
NET_API_STATUS WINAPI NetReplImportDirAdd(LPCWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS WINAPI NetReplImportDirDel(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetReplImportDirEnum(LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetReplImportDirGetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetReplImportDirLock(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetReplImportDirUnlock(LPCWSTR,LPCWSTR,DWORD);
#ifdef __cplusplus
}
#endif
#endif 
