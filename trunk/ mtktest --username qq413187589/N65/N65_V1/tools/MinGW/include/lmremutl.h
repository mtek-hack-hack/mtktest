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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmremutl.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmremutl.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmremutl.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmremutl.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmremutl.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmremutl.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmremutl.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmremutl.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmremutl.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMREMUTL_H
#define _LMREMUTL_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SUPPORTS_REMOTE_ADMIN_PROTOCOL 2
#define SUPPORTS_RPC 4
#define SUPPORTS_SAM_PROTOCOL 8
#define SUPPORTS_UNICODE 16
#define SUPPORTS_LOCAL 32
#define SUPPORTS_ANY 0xFFFFFFFF
#define NO_PERMISSION_REQUIRED 1
#define ALLOCATE_RESPONSE 2
#define USE_SPECIFIC_TRANSPORT 0x80000000
#ifndef DESC_CHAR_UNICODE
typedef CHAR DESC_CHAR;
#else 
typedef WCHAR DESC_CHAR;
#endif 
typedef DESC_CHAR *LPDESC;
typedef struct _TIME_OF_DAY_INFO {
	DWORD tod_elapsedt;
	DWORD tod_msecs;
	DWORD tod_hours;
	DWORD tod_mins;
	DWORD tod_secs;
	DWORD tod_hunds;
	LONG tod_timezone;
	DWORD tod_tinterval;
	DWORD tod_day;
	DWORD tod_month;
	DWORD tod_year;
	DWORD tod_weekday;
} TIME_OF_DAY_INFO,*PTIME_OF_DAY_INFO,*LPTIME_OF_DAY_INFO;
NET_API_STATUS WINAPI NetRemoteTOD(LPCWSTR,PBYTE*);
NET_API_STATUS WINAPI NetRemoteComputerSupports(LPCWSTR,DWORD,PDWORD);
NET_API_STATUS RxRemoteApi(DWORD,LPCWSTR,LPDESC,LPDESC,LPDESC,LPDESC,LPDESC,LPDESC,LPDESC,DWORD,... );
#ifdef __cplusplus
}
#endif
#endif 
