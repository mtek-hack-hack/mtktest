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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/secext.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: secext.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Date: 2007/05/17 07:25:33 $
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
* $Log: secext.h,v $
* Revision 1.1  2007/05/17 07:25:33  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/secext.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: secext.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Date: 2007/05/14 09:46:48 $
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
* ~Log: secext.h,v $
* Revision 1.1  2007/05/14 09:46:48  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/secext.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: secext.h,v 1.2 2007/04/04 06:51:34 bw Exp $
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
* ~Log: secext.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _SECEXT_H
#define _SECEXT_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef RC_INVOKED
#if (_WIN32_WINNT >= 0x0500)
typedef enum 
{
  NameUnknown = 0, 
  NameFullyQualifiedDN = 1, 
  NameSamCompatible = 2, 
  NameDisplay = 3, 
  NameUniqueId = 6, 
  NameCanonical = 7, 
  NameUserPrincipal = 8, 
  NameCanonicalEx = 9, 
  NameServicePrincipal = 10, 
  NameDnsDomain = 12
} EXTENDED_NAME_FORMAT, *PEXTENDED_NAME_FORMAT;

BOOLEAN WINAPI GetComputerObjectNameA(EXTENDED_NAME_FORMAT,LPSTR,PULONG);
BOOLEAN WINAPI GetComputerObjectNameW(EXTENDED_NAME_FORMAT,LPWSTR,PULONG);
BOOLEAN WINAPI GetUserNameExA(EXTENDED_NAME_FORMAT,LPSTR,PULONG);
BOOLEAN WINAPI GetUserNameExW(EXTENDED_NAME_FORMAT,LPWSTR,PULONG);
BOOLEAN WINAPI TranslateNameA(LPCSTR,EXTENDED_NAME_FORMAT,EXTENDED_NAME_FORMAT,LPSTR,PULONG);
BOOLEAN WINAPI TranslateNameW(LPCWSTR,EXTENDED_NAME_FORMAT,EXTENDED_NAME_FORMAT,LPWSTR,PULONG);

#ifdef UNICODE
#define GetComputerObjectName GetComputerObjectNameW
#define GetUserNameEx GetUserNameExW
#define TranslateName TranslateNameW
#else
#define GetComputerObjectName GetComputerObjectNameA
#define GetUserNameEx GetUserNameExA
#define TranslateName TranslateNameA
#endif


#endif /* ! RC_INVOKED */
#endif /* _WIN32_WINNT >= 0x0500 */
#endif /* ! _SECEXT_H */
