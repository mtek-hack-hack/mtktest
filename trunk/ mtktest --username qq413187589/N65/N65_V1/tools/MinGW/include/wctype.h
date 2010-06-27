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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/wctype.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Id: wctype.h,v 1.1 2007/05/17 07:25:35 bw Exp $
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
* $Log: wctype.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/wctype.h,v 1.1 2007/05/14 09:46:53 bw Exp $
*
* ~Id: wctype.h,v 1.1 2007/05/14 09:46:53 bw Exp $
*
* ~Date: 2007/05/14 09:46:53 $
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
* ~Log: wctype.h,v $
* Revision 1.1  2007/05/14 09:46:53  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/wctype.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Id: wctype.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Date: 2007/04/04 06:51:35 $
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
* ~Log: wctype.h,v $
* Revision 1.2  2007/04/04 06:51:35  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* 
 * wctype.h
 *
 * Functions for testing wide character types and converting characters.
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Mumit Khan <khan@xraylith.wisc.edu>
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

#ifndef _WCTYPE_H_
#define _WCTYPE_H_

/* All the headers include this file. */
#include <_mingw.h>

#define	__need_wchar_t
#define	__need_wint_t
#ifndef RC_INVOKED
#include <stddef.h>
#endif	/* Not RC_INVOKED */

/*
 * The following flags are used to tell iswctype and _isctype what character
 * types you are looking for.
 */
#define	_UPPER		0x0001
#define	_LOWER		0x0002
#define	_DIGIT		0x0004
#define	_SPACE		0x0008
#define	_PUNCT		0x0010
#define	_CONTROL	0x0020
#define	_BLANK		0x0040
#define	_HEX		0x0080
#define	_LEADBYTE	0x8000

#define	_ALPHA		0x0103

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WEOF
#define	WEOF	(wchar_t)(0xFFFF)
#endif

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif

/* Wide character equivalents - also in ctype.h */
_CRTIMP int __cdecl	iswalnum(wint_t);
_CRTIMP int __cdecl	iswalpha(wint_t);
_CRTIMP int __cdecl	iswascii(wint_t);
_CRTIMP int __cdecl	iswcntrl(wint_t);
_CRTIMP int __cdecl	iswctype(wint_t, wctype_t);
_CRTIMP int __cdecl	is_wctype(wint_t, wctype_t);	/* Obsolete! */
_CRTIMP int __cdecl	iswdigit(wint_t);
_CRTIMP int __cdecl	iswgraph(wint_t);
_CRTIMP int __cdecl	iswlower(wint_t);
_CRTIMP int __cdecl	iswprint(wint_t);
_CRTIMP int __cdecl	iswpunct(wint_t);
_CRTIMP int __cdecl	iswspace(wint_t);
_CRTIMP int __cdecl	iswupper(wint_t);
_CRTIMP int __cdecl	iswxdigit(wint_t);

_CRTIMP wchar_t __cdecl	towlower(wchar_t);
_CRTIMP wchar_t __cdecl	towupper(wchar_t);

_CRTIMP int __cdecl	isleadbyte (int);

/* Also in ctype.h */

#ifdef __DECLSPEC_SUPPORTED
__MINGW_IMPORT unsigned short _ctype[];
# ifdef __MSVCRT__
  __MINGW_IMPORT unsigned short* _pctype;
# else	/* CRTDLL */
  __MINGW_IMPORT unsigned short* _pctype_dll;
# define  _pctype _pctype_dll
# endif

#else		/* ! __DECLSPEC_SUPPORTED */
extern unsigned short** _imp___ctype;
#define _ctype (*_imp___ctype)
# ifdef __MSVCRT__
  extern unsigned short** _imp___pctype;
# define _pctype (*_imp___pctype)
# else	/* CRTDLL */
  extern unsigned short** _imp___pctype_dll;
# define _pctype (*_imp___pctype_dll)
# endif	/* CRTDLL */
#endif		/*  __DECLSPEC_SUPPORTED */


#if !(defined (__NO_INLINE__) || defined(__NO_CTYPE_INLINES) \
      || defined(__WCTYPE_INLINES_DEFINED))
#define __WCTYPE_INLINES_DEFINED
extern __inline__ int __cdecl iswalnum(wint_t wc) {return (iswctype(wc,_ALPHA|_DIGIT));}
extern __inline__ int __cdecl iswalpha(wint_t wc) {return (iswctype(wc,_ALPHA));}
extern __inline__ int __cdecl iswascii(wint_t wc) {return ((wc & ~0x7F) ==0);}
extern __inline__ int __cdecl iswcntrl(wint_t wc) {return (iswctype(wc,_CONTROL));}
extern __inline__ int __cdecl iswdigit(wint_t wc) {return (iswctype(wc,_DIGIT));}
extern __inline__ int __cdecl iswgraph(wint_t wc) {return (iswctype(wc,_PUNCT|_ALPHA|_DIGIT));}
extern __inline__ int __cdecl iswlower(wint_t wc) {return (iswctype(wc,_LOWER));}
extern __inline__ int __cdecl iswprint(wint_t wc) {return (iswctype(wc,_BLANK|_PUNCT|_ALPHA|_DIGIT));}
extern __inline__ int __cdecl iswpunct(wint_t wc) {return (iswctype(wc,_PUNCT));}
extern __inline__ int __cdecl iswspace(wint_t wc) {return (iswctype(wc,_SPACE));}
extern __inline__ int __cdecl iswupper(wint_t wc) {return (iswctype(wc,_UPPER));}
extern __inline__ int __cdecl iswxdigit(wint_t wc) {return (iswctype(wc,_HEX));}
extern __inline__ int __cdecl isleadbyte(int c) {return (_pctype[(unsigned char)(c)] & _LEADBYTE);}
#endif /* !(defined(__NO_CTYPE_INLINES) || defined(__WCTYPE_INLINES_DEFINED)) */


typedef wchar_t wctrans_t;
_CRTIMP wint_t __cdecl		towctrans(wint_t, wctrans_t);
_CRTIMP wctrans_t __cdecl	wctrans(const char*);
_CRTIMP wctype_t __cdecl	wctype(const char*);

#ifdef __cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _WCTYPE_H_ */

