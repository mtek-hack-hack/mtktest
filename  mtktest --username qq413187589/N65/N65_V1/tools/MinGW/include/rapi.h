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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/rapi.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Id: rapi.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Date: 2007/05/17 07:25:32 $
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
* $Log: rapi.h,v $
* Revision 1.1  2007/05/17 07:25:32  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/rapi.h,v 1.1 2007/05/14 09:46:47 bw Exp $
*
* ~Id: rapi.h,v 1.1 2007/05/14 09:46:47 bw Exp $
*
* ~Date: 2007/05/14 09:46:47 $
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
* ~Log: rapi.h,v $
* Revision 1.1  2007/05/14 09:46:47  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/rapi.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: rapi.h,v 1.2 2007/04/04 06:51:33 bw Exp $
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
* ~Log: rapi.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* rapi.h - main header file for the RAPI API

        NOTE: This strictly does not belong in the Win32 API since it's
        really part of Platform SDK.

*/

#ifndef _RAPI_H
#define _RAPI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

typedef struct IRAPIStream
{
  struct IRAPIStreamVtbl * lpVtbl;
} IRAPIStream;

typedef struct IRAPIStreamVtbl IRAPIStreamVtbl;

typedef enum tagRAPISTREAMFLAG
{
  STREAM_TIMEOUT_READ
} RAPISTREAMFLAG;

struct IRAPIStreamVtbl
{
  HRESULT (__stdcall * SetRapiStat)( IRAPIStream *, RAPISTREAMFLAG, DWORD);
  HRESULT (__stdcall * GetRapiStat)( IRAPIStream *, RAPISTREAMFLAG, DWORD *);
};

typedef  HRESULT (STDAPICALLTYPE RAPIEXT)(DWORD, BYTE, DWORD, BYTE, IRAPIStream	*);

typedef struct _RAPIINIT
{
  DWORD cbSize;
  HANDLE heRapiInit;
  HRESULT hrRapiInit;
} RAPIINIT;

STDAPI CeRapiInit (void);
STDAPI CeRapiInitEx (RAPIINIT*);
STDAPI_(BOOL) CeCreateProcess (LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES,
			       BOOL, DWORD, LPVOID, LPWSTR, LPSTARTUPINFO, LPPROCESS_INFORMATION);
STDAPI CeRapiUninit (void);

STDAPI_(BOOL) CeWriteFile (HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
STDAPI_(HANDLE) CeCreateFile (LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE); 
STDAPI_(BOOL) CeCreateDirectory (LPCWSTR, LPSECURITY_ATTRIBUTES); 
STDAPI_(DWORD) CeGetLastError (void);
STDAPI_(BOOL) CeGetFileTime (HANDLE, LPFILETIME, LPFILETIME, LPFILETIME); 
STDAPI_(BOOL) CeCloseHandle (HANDLE); 

#endif /* _RAPI_H */
