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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mbstring.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mbstring.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: mbstring.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mbstring.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: mbstring.h,v 1.1 2007/05/14 09:46:43 bw Exp $
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
* ~Log: mbstring.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mbstring.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mbstring.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mbstring.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * mbstring.h
 *
 * Protototypes for string functions supporting multibyte characters. 
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

#ifndef _MBSTRING_H_
#define _MBSTRING_H_

/* All the headers include this file. */
#include <_mingw.h>

#ifndef RC_INVOKED

#define __need_size_t
#include <stddef.h>

#ifdef __cplusplus 
extern "C" {
#endif

#ifndef	__STRICT_ANSI__

/* character classification */
_CRTIMP int __cdecl _ismbcalnum (unsigned int);
_CRTIMP int __cdecl _ismbcalpha (unsigned int);
_CRTIMP int __cdecl _ismbcdigit (unsigned int);
_CRTIMP int __cdecl _ismbcgraph (unsigned int);
_CRTIMP int __cdecl _ismbcprint (unsigned int);
_CRTIMP int __cdecl _ismbcpunct (unsigned int);
_CRTIMP int __cdecl _ismbcspace (unsigned int);
_CRTIMP int __cdecl _ismbclower (unsigned int);
_CRTIMP int __cdecl _ismbcupper (unsigned int);
_CRTIMP int __cdecl _ismbclegal (unsigned int);
_CRTIMP int __cdecl _ismbcsymbol (unsigned int);


/* also in mbctype.h */
_CRTIMP int __cdecl _ismbblead (unsigned int );
_CRTIMP int __cdecl _ismbbtrail (unsigned int );
_CRTIMP int __cdecl _ismbslead ( const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _ismbstrail ( const unsigned char*, const unsigned char*);

_CRTIMP unsigned int __cdecl _mbctolower (unsigned int);
_CRTIMP unsigned int __cdecl _mbctoupper (unsigned int);

_CRTIMP void __cdecl _mbccpy (unsigned char*, const unsigned char*);
_CRTIMP size_t __cdecl _mbclen (const unsigned char*);

_CRTIMP unsigned int __cdecl _mbbtombc (unsigned int);
_CRTIMP unsigned int __cdecl _mbctombb (unsigned int);

/* Return value constants for these are defined in mbctype.h.  */
_CRTIMP int __cdecl _mbbtype (unsigned char, int);
_CRTIMP int __cdecl _mbsbtype (const unsigned char*, size_t);

_CRTIMP unsigned char* __cdecl  _mbscpy (unsigned char*, const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsncpy (unsigned char*, const unsigned char*, size_t);
_CRTIMP unsigned char* __cdecl  _mbsnbcpy (unsigned char*, const unsigned char*, size_t);
_CRTIMP unsigned char* __cdecl  _mbsset (unsigned char*, unsigned int);
_CRTIMP unsigned char* __cdecl  _mbsnset (unsigned char*, unsigned int, size_t);
_CRTIMP unsigned char* __cdecl  _mbsnbset (unsigned char*, unsigned int, size_t);
_CRTIMP unsigned char* __cdecl  _mbsdup (const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsrev (unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbscat (unsigned char*, const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsncat (unsigned char*, const unsigned char*, size_t);
_CRTIMP unsigned char* __cdecl  _mbsnbcat (unsigned char*, const unsigned char*, size_t);
_CRTIMP size_t __cdecl _mbslen (const unsigned char*);
_CRTIMP size_t __cdecl _mbsnbcnt (const unsigned char*, size_t);
_CRTIMP size_t __cdecl _mbsnccnt (const unsigned char*, size_t);
_CRTIMP unsigned char* __cdecl  _mbschr (const unsigned char*, unsigned int);
_CRTIMP unsigned char* __cdecl  _mbsrchr (const unsigned char*, unsigned int);
_CRTIMP size_t __cdecl _mbsspn (const unsigned char*, const unsigned char*);
_CRTIMP size_t __cdecl _mbscspn (const unsigned char*, const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsspnp (const unsigned char*, const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbspbrk (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _mbscmp (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _mbsicmp (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _mbsncmp (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnicmp (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnbcmp (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnbicmp (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbscoll (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _mbsicoll (const unsigned char*, const unsigned char*);
_CRTIMP int __cdecl _mbsncoll (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnicoll (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnbcoll (const unsigned char*, const unsigned char*, size_t);
_CRTIMP int __cdecl _mbsnbicoll (const unsigned char*, const unsigned char*, size_t);

_CRTIMP unsigned char* __cdecl  _mbsinc (const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsninc (const unsigned char*, size_t);
_CRTIMP unsigned char* __cdecl  _mbsdec (const unsigned char*, const unsigned char*);
_CRTIMP unsigned int __cdecl _mbsnextc  (const unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbslwr (unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbsupr (unsigned char*);
_CRTIMP unsigned char* __cdecl  _mbstok (unsigned char*, const unsigned char*);

/* Kanji */
_CRTIMP int __cdecl _ismbchira (unsigned int);
_CRTIMP int __cdecl _ismbckata (unsigned int);
_CRTIMP int __cdecl _ismbcl0 (unsigned int);
_CRTIMP int __cdecl _ismbcl1 (unsigned int);
_CRTIMP int __cdecl _ismbcl2 (unsigned int);
_CRTIMP unsigned int __cdecl _mbcjistojms (unsigned int);
_CRTIMP unsigned int __cdecl _mbcjmstojis (unsigned int);
_CRTIMP unsigned int __cdecl _mbctohira (unsigned int);
_CRTIMP unsigned int __cdecl _mbctokata (unsigned int);

#endif	/* Not strict ANSI */

#ifdef __cplusplus
}
#endif

#endif	/* Not RC_INVOKED */
#endif	/* Not _MBSTRING_H_ */


