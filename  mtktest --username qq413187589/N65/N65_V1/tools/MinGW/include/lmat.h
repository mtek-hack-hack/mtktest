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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmat.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmat.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmat.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmat.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmat.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmat.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmat.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: lmat.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: lmat.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMAT_H
#define _LMAT_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define JOB_RUN_PERIODICALLY	1
#define JOB_EXEC_ERROR	2
#define JOB_RUNS_TODAY	4
#define JOB_ADD_CURRENT_DATE	8
#define JOB_NONINTERACTIVE	16
#define JOB_INPUT_FLAGS	(JOB_RUN_PERIODICALLY|JOB_ADD_CURRENT_DATE|JOB_NONINTERACTIVE)
#define JOB_OUTPUT_FLAGS (JOB_RUN_PERIODICALLY|JOB_EXEC_ERROR|JOB_RUNS_TODAY|JOB_NONINTERACTIVE)
typedef struct _AT_ENUM {
	DWORD JobId;
	DWORD JobTime;
	DWORD DaysOfMonth;
	UCHAR DaysOfWeek;
	UCHAR Flags;
	LPWSTR Command;
} AT_ENUM,*PAT_ENUM,*LPAT_ENUM;
typedef struct _AT_INFO {
	DWORD JobTime;
	DWORD DaysOfMonth;
	UCHAR DaysOfWeek;
	UCHAR Flags;
	LPWSTR Command;
} AT_INFO,*PAT_INFO,*LPAT_INFO;
NET_API_STATUS WINAPI NetScheduleJobAdd(LPWSTR,PBYTE,LPDWORD);
NET_API_STATUS WINAPI NetScheduleJobDel(LPWSTR,DWORD,DWORD);
NET_API_STATUS WINAPI NetScheduleJobEnum(LPWSTR,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetScheduleJobGetInfo(LPWSTR,DWORD,PBYTE*);
#ifdef __cplusplus
}
#endif
#endif
