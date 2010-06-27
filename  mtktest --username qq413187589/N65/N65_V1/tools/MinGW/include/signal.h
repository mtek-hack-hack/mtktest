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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/signal.h,v 1.1 2007/05/17 07:25:34 bw Exp $
*
* $Id: signal.h,v 1.1 2007/05/17 07:25:34 bw Exp $
*
* $Date: 2007/05/17 07:25:34 $
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
* $Log: signal.h,v $
* Revision 1.1  2007/05/17 07:25:34  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/signal.h,v 1.1 2007/05/14 09:46:50 bw Exp $
*
* ~Id: signal.h,v 1.1 2007/05/14 09:46:50 bw Exp $
*
* ~Date: 2007/05/14 09:46:50 $
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
* ~Log: signal.h,v $
* Revision 1.1  2007/05/14 09:46:50  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/signal.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: signal.h,v 1.2 2007/04/04 06:51:34 bw Exp $
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
* ~Log: signal.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* 
 * signal.h
 *
 * A way to set handlers for exceptional conditions (also known as signals).
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
 * ~Date: 2006/04/29 04:41:44 $
 *
 */

#ifndef	_SIGNAL_H_
#define	_SIGNAL_H_

/* All the headers include this file. */
#include <_mingw.h>

/*
 * The actual signal values. Using other values with signal
 * produces a SIG_ERR return value.
 *
 * NOTE: SIGINT is produced when the user presses Ctrl-C.
 *       SIGILL has not been tested.
 *       SIGFPE doesn't seem to work?
 *       SIGSEGV does not catch writing to a NULL pointer (that shuts down
 *               your app; can you say "segmentation violation core dump"?).
 *       SIGTERM comes from what kind of termination request exactly?
 *       SIGBREAK is indeed produced by pressing Ctrl-Break.
 *       SIGABRT is produced by calling abort.
 * TODO: The above results may be related to not installing an appropriate
 *       structured exception handling frame. Results may be better if I ever
 *       manage to get the SEH stuff down.
 */
#define	SIGINT		2	/* Interactive attention */
#define	SIGILL		4	/* Illegal instruction */
#define	SIGFPE		8	/* Floating point error */
#define	SIGSEGV		11	/* Segmentation violation */
#define	SIGTERM		15	/* Termination request */
#define SIGBREAK	21	/* Control-break */
#define	SIGABRT		22	/* Abnormal termination (abort) */

#define NSIG 23     /* maximum signal number + 1 */

#ifndef	RC_INVOKED

#ifndef _SIG_ATOMIC_T_DEFINED
typedef int sig_atomic_t;
#define _SIG_ATOMIC_T_DEFINED
#endif

/*
 * The prototypes (below) are the easy part. The hard part is figuring
 * out what signals are available and what numbers they are assigned
 * along with appropriate values of SIG_DFL and SIG_IGN.
 */

/*
 * A pointer to a signal handler function. A signal handler takes a
 * single int, which is the signal it handles.
 */
typedef	void (*__p_sig_fn_t)(int);

/*
 * These are special values of signal handler pointers which are
 * used to send a signal to the default handler (SIG_DFL), ignore
 * the signal (SIG_IGN), or indicate an error return (SIG_ERR).
 */
#define	SIG_DFL	((__p_sig_fn_t) 0)
#define	SIG_IGN	((__p_sig_fn_t) 1)
#define	SIG_ERR ((__p_sig_fn_t) -1)

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Call signal to set the signal handler for signal sig to the
 * function pointed to by handler. Returns a pointer to the
 * previous handler, or SIG_ERR if an error occurs. Initially
 * unhandled signals defined above will return SIG_DFL.
 */
_CRTIMP __p_sig_fn_t __cdecl	signal(int, __p_sig_fn_t);

/*
 * Raise the signal indicated by sig. Returns non-zero on success.
 */
_CRTIMP int __cdecl	raise (int);

#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _SIGNAL_H_ */

