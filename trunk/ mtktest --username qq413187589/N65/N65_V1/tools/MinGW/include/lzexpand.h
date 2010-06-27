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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/lzexpand.h,v 1.1 2007/05/17 07:25:30 bw Exp $
*
* $Id: lzexpand.h,v 1.1 2007/05/17 07:25:30 bw Exp $
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
* $Log: lzexpand.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/lzexpand.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: lzexpand.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Date: 2007/05/14 09:46:43 $
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
* ~Log: lzexpand.h,v $
* Revision 1.1  2007/05/14 09:46:43  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/lzexpand.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: lzexpand.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: lzexpand.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _LZEXPAND_H
#define _LZEXPAND_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define LZERROR_BADINHANDLE	(-1)
#define LZERROR_BADOUTHANDLE	(-2)
#define LZERROR_READ	(-3)
#define LZERROR_WRITE	(-4)
#define LZERROR_GLOBALLOC	(-5)
#define LZERROR_GLOBLOCK	(-6)
#define LZERROR_BADVALUE	(-7)
#define LZERROR_UNKNOWNALG	(-8)
LONG WINAPI CopyLZFile(INT,INT);
INT WINAPI GetExpandedNameA(LPSTR,LPSTR);
INT WINAPI GetExpandedNameW(LPWSTR,LPWSTR);
VOID APIENTRY LZClose(INT);
LONG APIENTRY LZCopy(INT,INT);
VOID WINAPI LZDone(VOID);
INT WINAPI LZInit(INT);
INT WINAPI LZOpenFileA(LPSTR,LPOFSTRUCT,WORD);
INT WINAPI LZOpenFileW(LPWSTR,LPOFSTRUCT,WORD);
INT WINAPI LZRead(INT,LPSTR,INT);
LONG WINAPI LZSeek(INT,LONG,INT);
INT WINAPI LZStart(VOID);
#ifdef UNICODE
#define GetExpandedName GetExpandedNameW
#define LZOpenFile  LZOpenFileW
#else
#define GetExpandedName GetExpandedNameA
#define LZOpenFile  LZOpenFileA
#endif
#ifdef __cplusplus
}
#endif
#endif
