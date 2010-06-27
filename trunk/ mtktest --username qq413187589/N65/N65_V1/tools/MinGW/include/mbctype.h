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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mbctype.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mbctype.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Date: 2007/05/17 07:25:31 $
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
* $Log: mbctype.h,v $
* Revision 1.1  2007/05/17 07:25:31  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mbctype.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: mbctype.h,v 1.1 2007/05/14 09:46:43 bw Exp $
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
* ~Log: mbctype.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mbctype.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mbctype.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mbctype.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* 
 * mbctype.h
 *
 * Functions for testing multibyte character types and converting characters.
 *
 * This file is part of the Mingw32 package.
 *
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef _MBCTYPE_H_
#define _MBCTYPE_H_

/* All the headers include this file. */
#include <_mingw.h>

/* return values for _mbsbtype  and  _mbbtype in mbstring.h */
#define _MBC_SINGLE 0 
#define _MBC_LEAD 1  
#define _MBC_TRAIL 2
#define _MBC_ILLEGAL (-1)

/*  args for setmbcp (in lieu of actual codepage)  */
#define _MB_CP_SBCS 0
#define _MB_CP_OEM (-2)
#define _MB_CP_ANSI (-3)
#define _MB_CP_LOCALE (-4)

/* TODO: bit masks */
/*
#define _MS
#define _MP
#define _M1
#define _M2
#define _SBUP
#define _SBLOW
*/

#ifndef RC_INVOKED

#ifdef __cplusplus 
extern "C" {
#endif

#ifndef	__STRICT_ANSI__

_CRTIMP int __cdecl _setmbcp (int);
_CRTIMP int __cdecl _getmbcp (void);

/* byte classification  */
/* NB: Corresponding _ismbc* functions are in mbstring.h */

_CRTIMP int __cdecl _ismbbalpha (unsigned int);
_CRTIMP int __cdecl _ismbbalnum (unsigned int);
_CRTIMP int __cdecl _ismbbgraph (unsigned int);
_CRTIMP int __cdecl _ismbbprint (unsigned int);
_CRTIMP int __cdecl _ismbbpunct (unsigned int);

_CRTIMP int __cdecl _ismbbkana (unsigned int);
_CRTIMP int __cdecl _ismbbkalnum (unsigned int);
_CRTIMP int __cdecl _ismbbkprint (unsigned int);
_CRTIMP int __cdecl _ismbbkpunct (unsigned int);


/* these are also in mbstring.h */
_CRTIMP int __cdecl _ismbblead (unsigned int);
_CRTIMP int __cdecl _ismbbtrail (unsigned int);
_CRTIMP int __cdecl _ismbslead (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _ismbstrail (const unsigned char*, const unsigned char*);

#ifdef __DECLSPEC_SUPPORTED
__MINGW_IMPORT unsigned char _mbctype[];
__MINGW_IMPORT unsigned char _mbcasemap[];
#endif

/* TODO : _MBCS_ mappings go in tchar.h */

#endif	/* Not strict ANSI */

#ifdef __cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _MCTYPE_H_ */

