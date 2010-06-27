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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmalert.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmalert.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmalert.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmalert.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmalert.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmalert.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmalert.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: lmalert.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: lmalert.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMALERT_H
#define _LMALERT_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define ALERTER_MAILSLOT TEXT("\\\\.\\MAILSLOT\\Alerter")
#define ALERT_PRINT_EVENT TEXT("PRINTING")
#define ALERT_MESSAGE_EVENT TEXT("MESSAGE")
#define ALERT_ERRORLOG_EVENT TEXT("ERRORLOG")
#define ALERT_ADMIN_EVENT TEXT("ADMIN")
#define ALERT_USER_EVENT TEXT("USER")
#define ALERT_OTHER_INFO(x) ((PBYTE)(x)+sizeof(STD_ALERT))
#define ALERT_VAR_DATA(p) ((PBYTE)(p)+sizeof(*p))
#define PRJOB_QSTATUS 3
#define PRJOB_DEVSTATUS 508
#define PRJOB_COMPLETE 4
#define PRJOB_INTERV 8
#define PRJOB_ 16
#define PRJOB_DESTOFFLINE 32
#define PRJOB_DESTPAUSED 64
#define PRJOB_NOTIFY 128
#define PRJOB_DESTNOPAPER 256
#define PRJOB_DELETED 32768
#define PRJOB_QS_QUEUED 0
#define PRJOB_QS_PAUSED 1
#define PRJOB_QS_SPOOLING 2
#define PRJOB_QS_PRINTING 3
#ifdef __cplusplus
extern "C" {
#endif
typedef struct _ADMIN_OTHER_INFO {
	DWORD alrtad_errcode;
	DWORD alrtad_numstrings;
}ADMIN_OTHER_INFO,*PADMIN_OTHER_INFO,*LPADMIN_OTHER_INFO;
typedef struct _STD_ALERT {
	DWORD alrt_timestamp;
	TCHAR alrt_eventname[EVLEN+1];
	TCHAR alrt_servicename[SNLEN+1];
}STD_ALERT,*PSTD_ALERT,*LPSTD_ALERT;
typedef struct _ERRLOG_OTHER_INFO {
	DWORD alrter_errcode;
	DWORD alrter_offset;
}ERRLOG_OTHER_INFO,*PERRLOG_OTHER_INFO,*LPERRLOG_OTHER_INFO;
typedef struct _PRINT_OTHER_INFO {
	DWORD alrtpr_jobid;
	DWORD alrtpr_status;
	DWORD alrtpr_submitted;
	DWORD alrtpr_size;
}PRINT_OTHER_INFO,*PPRINT_OTHER_INFO,*LPPRINT_OTHER_INFO;
typedef struct _USER_OTHER_INFO {
	DWORD alrtus_errcode;
	DWORD alrtus_numstrings;
}USER_OTHER_INFO,*PUSER_OTHER_INFO,*LPUSER_OTHER_INFO;
NET_API_STATUS WINAPI NetAlertRaise(LPCWSTR,PVOID,DWORD);
NET_API_STATUS WINAPI NetAlertRaiseEx(LPCWSTR,PVOID,DWORD,LPCWSTR);
#ifdef __cplusplus
}
#endif
#endif
