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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/excpt.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Id: excpt.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Date: 2007/05/17 07:25:26 $
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
* $Log: excpt.h,v $
* Revision 1.1  2007/05/17 07:25:26  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/excpt.h,v 1.1 2007/05/14 09:46:38 bw Exp $
*
* ~Id: excpt.h,v 1.1 2007/05/14 09:46:38 bw Exp $
*
* ~Date: 2007/05/14 09:46:38 $
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
* ~Log: excpt.h,v $
* Revision 1.1  2007/05/14 09:46:38  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/excpt.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: excpt.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: excpt.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* 
 * excpt.h
 *
 * Support for operating system level structured exception handling.
 *
 * NOTE: This is very preliminary stuff. I am also pretty sure it is
 *       completely Intel specific.
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 *  Based on code by Mikey <jeffdb@netzone.com>
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
 * ~Date: 2006/04/29 04:41:34 $
 *
 */

#ifndef	_EXCPT_H_
#define	_EXCPT_H_

/* All the headers include this file. */
#include <_mingw.h>

#ifndef	__STRICT_ANSI__

#include <windef.h>

/*
 * NOTE: The constants structs and typedefs below should be defined in the
 *       Win32 API headers.
 */
#define	EH_NONCONTINUABLE	0x01
#define	EH_UNWINDING		0x02
#define	EH_EXIT_UNWIND		0x04
#define	EH_STACK_INVALID	0x08
#define	EH_NESTED_CALL		0x10

#ifndef	RC_INVOKED

typedef enum {
	ExceptionContinueExecution,
	ExceptionContinueSearch,
	ExceptionNestedException,
	ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;


/*
 * End of stuff that should be in the Win32 API files.
 */


#ifdef	__cplusplus
extern "C" {
#endif

/*
 * The type of function that is expected as an exception handler to be
 * installed with _try1.
 */
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)
		(struct _EXCEPTION_RECORD*, void*, struct _CONTEXT*, void*);

/*
 * This is not entirely necessary, but it is the structure installed by
 * the _try1 primitive below.
 */
typedef struct _EXCEPTION_REGISTRATION
{
	struct _EXCEPTION_REGISTRATION*	prev;
	PEXCEPTION_HANDLER		handler;
} EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

typedef EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
typedef PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;

/*
 * A macro which installs the supplied exception handler.
 * Push the pointer to the new handler onto the stack,
 * then push the pointer to the old registration structure (at fs:0)
 * onto the stack, then put a pointer to the new registration
 * structure (i.e. the current stack pointer) at fs:0.
 */
#define __try1(pHandler) \
	__asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

/*
 * A macro which (despite its name) *removes* an installed
 * exception handler. Should be used only in conjunction with the above
 * install routine __try1.
 * Move the pointer to the old reg. struct (at the current stack
 * position) to fs:0, replacing the pointer we installed above,
 * then add 8 to the stack pointer to get rid of the space we
 * used when we pushed on our new reg. struct above. Notice that
 * the stack must be in the exact state at this point that it was
 * after we did _try1 or this will smash things.
 */
#define	__except1	\
	__asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
	 : : : "%eax");

#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not strict ANSI */

#endif	/* _EXCPT_H_ not defined */
