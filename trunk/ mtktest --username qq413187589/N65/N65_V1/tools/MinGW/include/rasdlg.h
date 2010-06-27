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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/rasdlg.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Id: rasdlg.h,v 1.1 2007/05/17 07:25:32 bw Exp $
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
* $Log: rasdlg.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/rasdlg.h,v 1.1 2007/05/14 09:46:47 bw Exp $
*
* ~Id: rasdlg.h,v 1.1 2007/05/14 09:46:47 bw Exp $
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
* ~Log: rasdlg.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/rasdlg.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: rasdlg.h,v 1.2 2007/04/04 06:51:33 bw Exp $
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
* ~Log: rasdlg.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _RASDLG_H_
#define _RASDLG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <ras.h>

#define RASPBDEVENT_AddEntry	1
#define RASPBDEVENT_EditEntry	2
#define RASPBDEVENT_RemoveEntry	3
#define RASPBDEVENT_DialEntry	4
#define RASPBDEVENT_EditGlobals	5
#define RASPBDEVENT_NoUser	6
#define RASPBDEVENT_NoUserEdit	7
 
#define RASPBDFLAG_PositionDlg	1
#define RASPBDFLAG_ForceCloseOnDial	2
#define RASPBDFLAG_NoUser	16

#define RASEDFLAG_PositionDlg	1
#define RASEDFLAG_NewEntry	2
#define RASEDFLAG_CloneEntry	4

#define RASDDFLAG_PositionDlg	1

#ifndef RC_INVOKED
#include <pshpack4.h>

typedef struct tagRASENTRYDLGA
{
	DWORD dwSize;
	HWND  hwndOwner;
	DWORD dwFlags;
	LONG  xDlg;
	LONG  yDlg;
	CHAR  szEntry[RAS_MaxEntryName + 1];
	DWORD dwError;
	ULONG_PTR reserved;
	ULONG_PTR reserved2;
} RASENTRYDLGA, *LPRASENTRYDLGA;
typedef struct tagRASENTRYDLGW
{
	DWORD dwSize;
	HWND  hwndOwner;
	DWORD dwFlags;
	LONG  xDlg;
	LONG  yDlg;
	WCHAR szEntry[RAS_MaxEntryName + 1];
	DWORD dwError;
	ULONG_PTR reserved;
	ULONG_PTR reserved2;
} RASENTRYDLGW, *LPRASENTRYDLGW;

typedef struct tagRASDIALDLG
{
	DWORD dwSize;
	HWND  hwndOwner;
	DWORD dwFlags;
	LONG  xDlg;
	LONG  yDlg;
	DWORD dwSubEntry;
	DWORD dwError;
	ULONG_PTR reserved;
	ULONG_PTR reserved2;
} RASDIALDLG, *LPRASDIALDLG;

/* Application-defined callback functions */
typedef VOID (WINAPI* RASPBDLGFUNCW)(DWORD, DWORD, LPWSTR, LPVOID);
typedef VOID (WINAPI* RASPBDLGFUNCA)(DWORD, DWORD, LPSTR, LPVOID);

typedef struct tagRASPBDLGA
{
	DWORD         dwSize;
	HWND          hwndOwner;
	DWORD         dwFlags;
	LONG          xDlg;
	LONG          yDlg;
	ULONG_PTR     dwCallbackId;
	RASPBDLGFUNCA pCallback;
	DWORD         dwError;
	ULONG_PTR     reserved;
	ULONG_PTR     reserved2;
} RASPBDLGA, *LPRASPBDLGA;
typedef struct tagRASPBDLGW
{
	DWORD         dwSize;
	HWND          hwndOwner;
	DWORD         dwFlags;
	LONG          xDlg;
	LONG          yDlg;
	ULONG_PTR     dwCallbackId;
	RASPBDLGFUNCW pCallback;
	DWORD         dwError;
	ULONG_PTR     reserved;
	ULONG_PTR     reserved2;
} RASPBDLGW, *LPRASPBDLGW;

typedef struct tagRASNOUSERA
{
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwTimeoutMs;
	CHAR  szUserName[UNLEN + 1];
	CHAR  szPassword[PWLEN + 1];
	CHAR  szDomain[DNLEN + 1];
} RASNOUSERA, *LPRASNOUSERA;
typedef struct tagRASNOUSERW
{
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwTimeoutMs;
	WCHAR szUserName[UNLEN + 1];
	WCHAR szPassword[PWLEN + 1];
	WCHAR szDomain[DNLEN + 1];
} RASNOUSERW, *LPRASNOUSERW ;

#include <poppack.h>

BOOL APIENTRY RasDialDlgA(LPSTR,LPSTR,LPSTR,LPRASDIALDLG);
BOOL APIENTRY RasDialDlgW(LPWSTR,LPWSTR,LPWSTR,LPRASDIALDLG);
BOOL APIENTRY RasEntryDlgA(LPSTR,LPSTR,LPRASENTRYDLGA);
BOOL APIENTRY RasEntryDlgW(LPWSTR,LPWSTR,LPRASENTRYDLGW);
BOOL APIENTRY RasPhonebookDlgA(LPSTR,LPSTR,LPRASPBDLGA);
BOOL APIENTRY RasPhonebookDlgW(LPWSTR,LPWSTR,LPRASPBDLGW);

#ifdef UNICODE
typedef RASENTRYDLGW	RASENTRYDLG, *LPRASENTRYDLG;
typedef RASPBDLGW	RASPBDLG, *LPRASPBDLG;
typedef RASNOUSERW	RASNOUSER, *LPRASNOUSER;
#define RasDialDlg	RasDialDlgW
#define RasEntryDlg	RasEntryDlgW
#define RasPhonebookDlg	RasPhonebookDlgW
#else
typedef RASENTRYDLGA	RASENTRYDLG, *LPRASENTRYDLG;
typedef RASPBDLGA	RASPBDLG, *LPRASPBDLG;
typedef RASNOUSERA	RASNOUSER, *LPRASNOUSER;
#define RasDialDlg	RasDialDlgA
#define RasEntryDlg	RasEntryDlgA
#define RasPhonebookDlg	RasPhonebookDlgA
#endif /* UNICODE */

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif
#endif
