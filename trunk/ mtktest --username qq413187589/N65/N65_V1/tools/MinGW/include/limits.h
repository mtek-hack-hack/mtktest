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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/limits.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Id: limits.h,v 1.1 2007/05/17 07:25:29 bw Exp $
*
* $Date: 2007/05/17 07:25:29 $
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
* $Log: limits.h,v $
* Revision 1.1  2007/05/17 07:25:29  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/limits.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Id: limits.h,v 1.1 2007/05/14 09:46:41 bw Exp $
*
* ~Date: 2007/05/14 09:46:41 $
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
* ~Log: limits.h,v $
* Revision 1.1  2007/05/14 09:46:41  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/limits.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: limits.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Date: 2007/04/04 06:51:31 $
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
* ~Log: limits.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* 
 * limits.h
 *
 * Defines constants for the sizes of integral types.
 *
 * NOTE: GCC should supply a version of this header and it should be safe to
 *       use that version instead of this one (maybe safer).
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
 * ~Date: 2006/04/29 04:41:35 $
 *
 */

#ifndef _LIMITS_H_
#define _LIMITS_H_

/* All the headers include this file. */
#include <_mingw.h>

/*
 * File system limits
 *
 * TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
 *       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
 * NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
 *       required for the NUL. TODO: Test?
 */
#define PATH_MAX	(259)

/*
 * Characteristics of the char data type.
 *
 * TODO: Is MB_LEN_MAX correct?
 */
#define CHAR_BIT	8
#define MB_LEN_MAX	2

#define SCHAR_MIN	(-128)
#define SCHAR_MAX	127

#define UCHAR_MAX	255

/* TODO: Is this safe? I think it might just be testing the preprocessor,
 *       not the compiler itself... */
#if	('\x80' < 0)
#define CHAR_MIN	SCHAR_MIN
#define CHAR_MAX	SCHAR_MAX
#else
#define CHAR_MIN	0
#define CHAR_MAX	UCHAR_MAX
#endif

/*
 * Maximum and minimum values for ints.
 */
#define INT_MAX		2147483647
#define INT_MIN		(-INT_MAX-1)

#define UINT_MAX	0xffffffff

/*
 * Maximum and minimum values for shorts.
 */
#define SHRT_MAX	32767
#define SHRT_MIN	(-SHRT_MAX-1)

#define USHRT_MAX	0xffff

/*
 * Maximum and minimum values for longs and unsigned longs.
 *
 * TODO: This is not correct for Alphas, which have 64 bit longs.
 */
#define LONG_MAX	2147483647L

#define LONG_MIN	(-LONG_MAX-1)

#define ULONG_MAX	0xffffffffUL


/*
 * The GNU C compiler also allows 'long long int'
 */
#if	!defined(__STRICT_ANSI__) && defined(__GNUC__)

#define LONG_LONG_MAX	9223372036854775807LL
#define LONG_LONG_MIN	(-LONG_LONG_MAX-1)

#define ULONG_LONG_MAX	(2ULL * LONG_LONG_MAX + 1)

/* ISO C9x macro names */
#define LLONG_MAX LONG_LONG_MAX
#define LLONG_MIN LONG_LONG_MIN
#define ULLONG_MAX ULONG_LONG_MAX

#endif /* Not Strict ANSI and GNU C compiler */


#endif /* not _LIMITS_H_ */
