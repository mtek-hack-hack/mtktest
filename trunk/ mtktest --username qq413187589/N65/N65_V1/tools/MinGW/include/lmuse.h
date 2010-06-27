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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmuse.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmuse.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmuse.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmuse.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmuse.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmuse.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmuse.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmuse.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmuse.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMUSE_H
#define _LMUSE_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include <lmuseflg.h>
#define USE_LOCAL_PARMNUM 1
#define USE_REMOTE_PARMNUM 2
#define USE_PASSWORD_PARMNUM 3
#define USE_ASGTYPE_PARMNUM 4
#define USE_USERNAME_PARMNUM 5
#define USE_DOMAINNAME_PARMNUM 6
#define USE_OK 0
#define USE_PAUSED 1
#define USE_SESSLOST 2
#define USE_DISCONN 2
#define USE_NETERR 3
#define USE_CONN 4
#define USE_RECONN 5
#define USE_WILDCARD ((DWORD)-1)
#define USE_DISKDEV 0
#define USE_SPOOLDEV 1
#define USE_CHARDEV 2
#define USE_IPC 3
typedef struct _USE_INFO_0 {
	LPWSTR ui0_local;
	LPWSTR ui0_remote;
}USE_INFO_0,*PUSE_INFO_0,*LPUSE_INFO_0;
typedef struct _USE_INFO_1 {
	LPWSTR ui1_local;
	LPWSTR ui1_remote;
	LPWSTR ui1_password;
	DWORD ui1_status;
	DWORD ui1_asg_type;
	DWORD ui1_refcount;
	DWORD ui1_usecount;
}USE_INFO_1,*PUSE_INFO_1,*LPUSE_INFO_1;
typedef struct _USE_INFO_2 {
	LPWSTR ui2_local;
	LPWSTR ui2_remote;
	LPWSTR ui2_password;
	DWORD ui2_status;
	DWORD ui2_asg_type;
	DWORD ui2_refcount;
	DWORD ui2_usecount;
	LPWSTR ui2_username;
	LPWSTR ui2_domainname;
}USE_INFO_2,*PUSE_INFO_2,*LPUSE_INFO_2;
NET_API_STATUS WINAPI NetUseAdd(LPWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS WINAPI NetUseDel(LPWSTR,LPWSTR,DWORD);
NET_API_STATUS WINAPI NetUseEnum(LPWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetUseGetInfo(LPWSTR,LPWSTR,DWORD,PBYTE*);
#ifdef __cplusplus
}
#endif
#endif 
