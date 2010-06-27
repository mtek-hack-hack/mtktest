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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lmstats.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lmstats.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lmstats.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lmstats.h,v 1.1 2007/05/14 09:46:42 bw Exp $
*
* ~Id: lmstats.h,v 1.1 2007/05/14 09:46:42 bw Exp $
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
* ~Log: lmstats.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lmstats.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lmstats.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lmstats.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LMSTATS_H
#define _LMSTATS_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define STATSOPT_CLR 1
#define STATS_NO_VALUE ((ULONG)-1)
#define STATS_OVERFLOW ((ULONG)-2)
typedef struct _STAT_SERVER_0 {
	DWORD sts0_start;
	DWORD sts0_fopens;
	DWORD sts0_devopens;
	DWORD sts0_jobsqueued;
	DWORD sts0_sopens;
	DWORD sts0_stimedout;
	DWORD sts0_serrorout;
	DWORD sts0_pwerrors;
	DWORD sts0_permerrors;
	DWORD sts0_syserrors;
	DWORD sts0_bytessent_low;
	DWORD sts0_bytessent_high;
	DWORD sts0_bytesrcvd_low;
	DWORD sts0_bytesrcvd_high;
	DWORD sts0_avresponse;
	DWORD sts0_reqbufneed;
	DWORD sts0_bigbufneed;
} STAT_SERVER_0,*PSTAT_SERVER_0,*LPSTAT_SERVER_0;
#ifdef LM20_WORKSTATION_STATISTICS
typedef struct _STAT_WORKSTATION_0 {
	DWORD stw0_start;
	DWORD stw0_numNCB_r;
	DWORD stw0_numNCB_s;
	DWORD stw0_numNCB_a;
	DWORD stw0_fiNCB_r;
	DWORD stw0_fiNCB_s;
	DWORD stw0_fiNCB_a;
	DWORD stw0_fcNCB_r;
	DWORD stw0_fcNCB_s;
	DWORD stw0_fcNCB_a;
	DWORD stw0_sesstart;
	DWORD stw0_sessfailcon;
	DWORD stw0_sessbroke;
	DWORD stw0_uses;
	DWORD stw0_usefail;
	DWORD stw0_autorec;
	DWORD stw0_bytessent_r_lo;
	DWORD stw0_bytessent_r_hi;
	DWORD stw0_bytesrcvd_r_lo;
	DWORD stw0_bytesrcvd_r_hi;
	DWORD stw0_bytessent_s_lo;
	DWORD stw0_bytessent_s_hi;
	DWORD stw0_bytesrcvd_s_lo;
	DWORD stw0_bytesrcvd_s_hi;
	DWORD stw0_bytessent_a_lo;
	DWORD stw0_bytessent_a_hi;
	DWORD stw0_bytesrcvd_a_lo;
	DWORD stw0_bytesrcvd_a_hi;
	DWORD stw0_reqbufneed;
	DWORD stw0_bigbufneed;
} STAT_WORKSTATION_0,*PSTAT_WORKSTATION_0,*LPSTAT_WORKSTATION_0;
#else
typedef struct _STAT_WORKSTATION_0 {
	LARGE_INTEGER StatisticsStartTime;
	LARGE_INTEGER BytesReceived;
	LARGE_INTEGER SmbsReceived;
	LARGE_INTEGER PagingReadBytesRequested;
	LARGE_INTEGER NonPagingReadBytesRequested;
	LARGE_INTEGER CacheReadBytesRequested;
	LARGE_INTEGER NetworkReadBytesRequested;
	LARGE_INTEGER BytesTransmitted;
	LARGE_INTEGER SmbsTransmitted;
	LARGE_INTEGER PagingWriteBytesRequested;
	LARGE_INTEGER NonPagingWriteBytesRequested;
	LARGE_INTEGER CacheWriteBytesRequested;
	LARGE_INTEGER NetworkWriteBytesRequested;
	DWORD InitiallyFailedOperations;
	DWORD FailedCompletionOperations;
	DWORD ReadOperations;
	DWORD RandomReadOperations;
	DWORD ReadSmbs;
	DWORD LargeReadSmbs;
	DWORD SmallReadSmbs;
	DWORD WriteOperations;
	DWORD RandomWriteOperations;
	DWORD WriteSmbs;
	DWORD LargeWriteSmbs;
	DWORD SmallWriteSmbs;
	DWORD RawReadsDenied;
	DWORD RawWritesDenied;
	DWORD NetworkErrors;
	DWORD Sessions;
	DWORD FailedSessions;
	DWORD Reconnects;
	DWORD CoreConnects;
	DWORD Lanman20Connects;
	DWORD Lanman21Connects;
	DWORD LanmanNtConnects;
	DWORD ServerDisconnects;
	DWORD HungSessions;
	DWORD UseCount;
	DWORD FailedUseCount;
	DWORD CurrentCommands;
} STAT_WORKSTATION_0,*PSTAT_WORKSTATION_0,*LPSTAT_WORKSTATION_0;
#endif

NET_API_STATUS WINAPI NetStatisticsGet(LPWSTR,LPWSTR,DWORD,DWORD,PBYTE*);
#ifdef __cplusplus
}
#endif
#endif 
