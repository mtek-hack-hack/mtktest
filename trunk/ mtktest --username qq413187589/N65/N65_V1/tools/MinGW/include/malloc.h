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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/malloc.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: malloc.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: malloc.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/malloc.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: malloc.h,v 1.1 2007/05/14 09:46:43 bw Exp $
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
* ~Log: malloc.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/malloc.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: malloc.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: malloc.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * malloc.h
 *
 * Support for programs which want to use malloc.h to get memory management
 * functions. Unless you absolutely need some of these functions and they are
 * not in the ANSI headers you should use the ANSI standard header files
 * instead.
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
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
 * ~Revision: 1.1 $
 * ~Author: bw $
 * ~Date: 2006/04/29 04:41:37 $
 *
 */

#ifndef	__STRICT_ANSI__

#ifndef _MALLOC_H_
#define _MALLOC_H_

/* All the headers include this file. */
#include <_mingw.h>

#include <stdlib.h>

#ifndef RC_INVOKED

/*
 * The structure used to walk through the heap with _heapwalk.
 */
typedef	struct _heapinfo
{
	int*	_pentry;
	size_t	_size;
	int	_useflag;
} _HEAPINFO;

/* Values for _heapinfo.useflag */
#define _USEDENTRY 0
#define _FREEENTRY 1

#ifdef	__cplusplus
extern "C" {
#endif
/*
   The _heap* memory allocation functions are supported on NT
   but not W9x. On latter, they always set errno to ENOSYS.
*/
_CRTIMP int __cdecl _heapwalk (_HEAPINFO*);
#ifdef __GNUC__
#define _alloca(x) __builtin_alloca((x))
#endif

#ifndef	_NO_OLDNAMES
_CRTIMP int __cdecl heapwalk (_HEAPINFO*);
#ifdef __GNUC__
#define alloca(x) __builtin_alloca((x))
#endif
#endif	/* Not _NO_OLDNAMES */

_CRTIMP int __cdecl _heapchk (void);	/* Verify heap integrety. */
_CRTIMP int __cdecl _heapmin (void);	/* Return unused heap to the OS. */
_CRTIMP int __cdecl _heapset (unsigned int);

_CRTIMP size_t __cdecl _msize (void*);
_CRTIMP size_t __cdecl _get_sbh_threshold (void); 
_CRTIMP int __cdecl _set_sbh_threshold (size_t);
_CRTIMP void* __cdecl _expand (void*, size_t); 

#ifdef __cplusplus
}
#endif

#endif	/* RC_INVOKED */

#endif /* Not _MALLOC_H_ */

#endif /* Not __STRICT_ANSI__ */

