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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/tlhelp32.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Id: tlhelp32.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Date: 2007/05/17 07:25:35 $
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
* $Log: tlhelp32.h,v $
* Revision 1.1  2007/05/17 07:25:35  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/tlhelp32.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Id: tlhelp32.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Date: 2007/05/14 09:46:52 $
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
* ~Log: tlhelp32.h,v $
* Revision 1.1  2007/05/14 09:46:52  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/tlhelp32.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: tlhelp32.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Date: 2007/04/04 06:51:34 $
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
* ~Log: tlhelp32.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
	tlhelp32.h - Include file for Tool help functions.

	Written by Mumit Khan <khan@nanotech.wisc.edu>

	This file is part of a free library for the Win32 API. 

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/
#ifndef _TLHELP32_H
#define _TLHELP32_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define HF32_DEFAULT	1
#define HF32_SHARED	2
#define LF32_FIXED	0x1
#define LF32_FREE	0x2
#define LF32_MOVEABLE	0x4
#define MAX_MODULE_NAME32	255
#define TH32CS_SNAPHEAPLIST	0x1
#define TH32CS_SNAPPROCESS	0x2
#define TH32CS_SNAPTHREAD	0x4
#define TH32CS_SNAPMODULE	0x8
#define TH32CS_SNAPALL	(TH32CS_SNAPHEAPLIST|TH32CS_SNAPPROCESS|TH32CS_SNAPTHREAD|TH32CS_SNAPMODULE)
#define TH32CS_INHERIT	0x80000000
typedef struct tagHEAPLIST32 {
	DWORD dwSize;
	DWORD th32ProcessID;
	DWORD th32HeapID;
	DWORD dwFlags;
} HEAPLIST32,*PHEAPLIST32,*LPHEAPLIST32;
typedef struct tagHEAPENTRY32 {
	DWORD dwSize;
	HANDLE hHandle;
	DWORD dwAddress;
	DWORD dwBlockSize;
	DWORD dwFlags;
	DWORD dwLockCount;
	DWORD dwResvd;
	DWORD th32ProcessID;
	DWORD th32HeapID;
} HEAPENTRY32,*PHEAPENTRY32,*LPHEAPENTRY32;
typedef struct tagPROCESSENTRY32W {
	DWORD dwSize;
	DWORD cntUsage;
	DWORD th32ProcessID;
	DWORD th32DefaultHeapID;
	DWORD th32ModuleID;
	DWORD cntThreads;
	DWORD th32ParentProcessID;
	LONG pcPriClassBase;
	DWORD dwFlags;
	WCHAR szExeFile[MAX_PATH];
} PROCESSENTRY32W,*PPROCESSENTRY32W,*LPPROCESSENTRY32W;
typedef struct tagPROCESSENTRY32 {
	DWORD dwSize;
	DWORD cntUsage;
	DWORD th32ProcessID;
	DWORD th32DefaultHeapID;
	DWORD th32ModuleID;
	DWORD cntThreads;
	DWORD th32ParentProcessID;
	LONG pcPriClassBase;
	DWORD dwFlags;
	CHAR  szExeFile[MAX_PATH];
} PROCESSENTRY32,*PPROCESSENTRY32,*LPPROCESSENTRY32;
typedef struct tagTHREADENTRY32 {
	DWORD dwSize;
	DWORD cntUsage;
	DWORD th32ThreadID;
	DWORD th32OwnerProcessID;
	LONG tpBasePri;
	LONG tpDeltaPri;
	DWORD dwFlags;
} THREADENTRY32,*PTHREADENTRY32,*LPTHREADENTRY32;
typedef struct tagMODULEENTRY32W {
	DWORD dwSize;
	DWORD th32ModuleID;
	DWORD th32ProcessID;
	DWORD GlblcntUsage;
	DWORD ProccntUsage;
	BYTE *modBaseAddr;
	DWORD modBaseSize;
	HMODULE hModule; 
	WCHAR szModule[MAX_MODULE_NAME32 + 1];
	WCHAR szExePath[MAX_PATH];
} MODULEENTRY32W,*PMODULEENTRY32W,*LPMODULEENTRY32W;
typedef struct tagMODULEENTRY32 {
	DWORD dwSize;
	DWORD th32ModuleID;
	DWORD th32ProcessID;
	DWORD GlblcntUsage;
	DWORD ProccntUsage;
	BYTE *modBaseAddr;
	DWORD modBaseSize;
	HMODULE hModule;
	char szModule[MAX_MODULE_NAME32 + 1];
	char szExePath[MAX_PATH];
} MODULEENTRY32,*PMODULEENTRY32,*LPMODULEENTRY32;
BOOL WINAPI Heap32First(LPHEAPENTRY32,DWORD,DWORD);
BOOL WINAPI Heap32ListFirst(HANDLE,LPHEAPLIST32);
BOOL WINAPI Heap32ListNext(HANDLE,LPHEAPLIST32);
BOOL WINAPI Heap32Next(LPHEAPENTRY32);
BOOL WINAPI Module32First(HANDLE,LPMODULEENTRY32);
BOOL WINAPI Module32FirstW(HANDLE,LPMODULEENTRY32W);
BOOL WINAPI Module32Next(HANDLE,LPMODULEENTRY32);
BOOL WINAPI Module32NextW(HANDLE,LPMODULEENTRY32W);
BOOL WINAPI Process32First(HANDLE,LPPROCESSENTRY32);
BOOL WINAPI Process32FirstW(HANDLE,LPPROCESSENTRY32W);
BOOL WINAPI Process32Next(HANDLE,LPPROCESSENTRY32);
BOOL WINAPI Process32NextW(HANDLE,LPPROCESSENTRY32W);
BOOL WINAPI Thread32First(HANDLE,LPTHREADENTRY32);
BOOL WINAPI Thread32Next(HANDLE,LPTHREADENTRY32);
BOOL WINAPI Toolhelp32ReadProcessMemory(DWORD,LPCVOID,LPVOID,DWORD,LPDWORD);
HANDLE WINAPI CreateToolhelp32Snapshot(DWORD,DWORD);
#ifdef UNICODE
#define LPMODULEENTRY32 LPMODULEENTRY32W
#define LPPROCESSENTRY32 LPPROCESSENTRY32W
#define MODULEENTRY32 MODULEENTRY32W
#define Module32First Module32FirstW
#define Module32Next Module32NextW
#define PMODULEENTRY32 PMODULEENTRY32W
#define PPROCESSENTRY32 PPROCESSENTRY32W
#define PROCESSENTRY32 PROCESSENTRY32W
#define Process32First Process32FirstW
#define Process32Next Process32NextW
#endif /* UNICODE */
#ifdef __cplusplus
}
#endif
#endif /* _TLHELP32_H */

