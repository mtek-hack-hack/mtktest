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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/sys/utime.h,v 1.1 2007/05/17 07:25:44 bw Exp $
*
* $Id: utime.h,v 1.1 2007/05/17 07:25:44 bw Exp $
*
* $Date: 2007/05/17 07:25:44 $
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
* $Log: utime.h,v $
* Revision 1.1  2007/05/17 07:25:44  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/sys/utime.h,v 1.1 2007/05/14 09:47:07 bw Exp $
*
* ~Id: utime.h,v 1.1 2007/05/14 09:47:07 bw Exp $
*
* ~Date: 2007/05/14 09:47:07 $
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
* ~Log: utime.h,v $
* Revision 1.1  2007/05/14 09:47:07  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/sys/utime.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Id: utime.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Date: 2007/04/04 06:51:41 $
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
* ~Log: utime.h,v $
* Revision 1.2  2007/04/04 06:51:41  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * utime.h
 *
 * Support for the utime function.
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
 * ~Date: 2006/04/29 04:42:06 $
 *
 */

#ifndef	__STRICT_ANSI__

#ifndef	_UTIME_H_
#define	_UTIME_H_

/* All the headers include this file. */
#include <_mingw.h>

#define __need_wchar_t
#define __need_size_t
#ifndef RC_INVOKED
#include <stddef.h>
#endif	/* Not RC_INVOKED */
#include <sys/types.h>

#ifndef	RC_INVOKED

/*
 * Structure used by _utime function.
 */
struct _utimbuf
{
	time_t	actime;		/* Access time */
	time_t	modtime;	/* Modification time */
};


#ifndef	_NO_OLDNAMES
/* NOTE: Must be the same as _utimbuf above. */
struct utimbuf
{
	time_t	actime;
	time_t	modtime;
};
#endif	/* Not _NO_OLDNAMES */


#ifdef	__cplusplus
extern "C" {
#endif

_CRTIMP int __cdecl	_utime (const char*, struct _utimbuf*);
_CRTIMP int __cdecl	_futime (int, struct _utimbuf*);

/* The wide character version, only available for MSVCRT versions of the
 * C runtime library. */
#ifdef __MSVCRT__
_CRTIMP int __cdecl	_wutime (const wchar_t*, struct _utimbuf*);
#endif /* MSVCRT runtime */
#ifndef	_NO_OLDNAMES
_CRTIMP int __cdecl	utime (const char*, struct utimbuf*);
#endif	/* Not _NO_OLDNAMES */

#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _UTIME_H_ */

#endif	/* Not __STRICT_ANSI__ */

