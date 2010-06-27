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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/dde.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Id: dde.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Date: 2007/05/17 07:25:26 $
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
* $Log: dde.h,v $
* Revision 1.1  2007/05/17 07:25:26  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/dde.h,v 1.1 2007/05/14 09:46:38 bw Exp $
*
* ~Id: dde.h,v 1.1 2007/05/14 09:46:38 bw Exp $
*
* ~Date: 2007/05/14 09:46:38 $
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
* ~Log: dde.h,v $
* Revision 1.1  2007/05/14 09:46:38  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/dde.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Id: dde.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Date: 2007/04/04 06:51:30 $
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
* ~Log: dde.h,v $
* Revision 1.2  2007/04/04 06:51:30  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _DDE_H
#define _DDE_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define WM_DDE_FIRST	0x03E0
#define WM_DDE_INITIATE	(WM_DDE_FIRST)
#define WM_DDE_TERMINATE	(WM_DDE_FIRST+1)
#define WM_DDE_ADVISE	(WM_DDE_FIRST+2)
#define WM_DDE_UNADVISE	(WM_DDE_FIRST+3)
#define WM_DDE_ACK	(WM_DDE_FIRST+4)
#define WM_DDE_DATA	(WM_DDE_FIRST+5)
#define WM_DDE_REQUEST	(WM_DDE_FIRST+6)
#define WM_DDE_POKE	(WM_DDE_FIRST+7)
#define WM_DDE_EXECUTE	(WM_DDE_FIRST+8)
#define WM_DDE_LAST	(WM_DDE_FIRST+8)

#ifndef RC_INVOKED
typedef struct {
	unsigned short bAppReturnCode:8,reserved:6,fBusy:1,fAck:1;
} DDEACK;
typedef struct {
	unsigned short reserved:14,fDeferUpd:1,fAckReq:1;
	short cfFormat;
} DDEADVISE;
typedef struct {
	unsigned short unused:12,fResponse:1,fRelease:1,reserved:1,fAckReq:1;
	short cfFormat;
	BYTE Value[1];
} DDEDATA;
typedef struct {
	unsigned short unused:13,fRelease:1,fReserved:2;
	short cfFormat;
	BYTE  Value[1];
} DDEPOKE;
typedef struct {
        unsigned short unused:13,
                 fRelease:1,
                 fDeferUpd:1,
         fAckReq:1;
    short    cfFormat;
} DDELN;

typedef struct {
	unsigned short unused:12,fAck:1,fRelease:1,fReserved:1,fAckReq:1;
    short cfFormat;
    BYTE rgb[1];
} DDEUP;
BOOL WINAPI DdeSetQualityOfService(HWND,const SECURITY_QUALITY_OF_SERVICE*,PSECURITY_QUALITY_OF_SERVICE);
BOOL WINAPI ImpersonateDdeClientWindow(HWND,HWND);
LPARAM WINAPI PackDDElParam(UINT,UINT_PTR,UINT_PTR); 
BOOL WINAPI UnpackDDElParam(UINT,LPARAM,PUINT_PTR,PUINT_PTR); 
BOOL WINAPI FreeDDElParam(UINT,LPARAM); 
LPARAM WINAPI ReuseDDElParam(LPARAM,UINT,UINT,UINT_PTR,UINT_PTR); 
#endif

#ifdef __cplusplus
}
#endif
#endif
