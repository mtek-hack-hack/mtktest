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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/sys/locking.h,v 1.1 2007/05/17 07:25:43 bw Exp $
*
* $Id: locking.h,v 1.1 2007/05/17 07:25:43 bw Exp $
*
* $Date: 2007/05/17 07:25:43 $
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
* $Log: locking.h,v $
* Revision 1.1  2007/05/17 07:25:43  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/sys/locking.h,v 1.1 2007/05/14 09:47:06 bw Exp $
*
* ~Id: locking.h,v 1.1 2007/05/14 09:47:06 bw Exp $
*
* ~Date: 2007/05/14 09:47:06 $
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
* ~Log: locking.h,v $
* Revision 1.1  2007/05/14 09:47:06  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/sys/locking.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Id: locking.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Date: 2007/04/04 06:51:40 $
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
* ~Log: locking.h,v $
* Revision 1.2  2007/04/04 06:51:40  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * locking.h
 *
 * Constants for the mode parameter of the locking function.
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

#ifndef	_LOCKING_H_
#define	_LOCKING_H_

/* All the headers include this file. */
#include <_mingw.h>

#define	_LK_UNLCK	0	/* Unlock */
#define	_LK_LOCK	1	/* Lock */
#define	_LK_NBLCK	2	/* Non-blocking lock */
#define	_LK_RLCK	3	/* Lock for read only */
#define	_LK_NBRLCK	4	/* Non-blocking lock for read only */

#ifndef	NO_OLDNAMES
#define	LK_UNLCK	_LK_UNLCK
#define	LK_LOCK		_LK_LOCK
#define	LK_NBLCK	_LK_NBLCK
#define	LK_RLCK		_LK_RLCK
#define	LK_NBRLCK	_LK_NBRLCK
#endif	/* Not NO_OLDNAMES */

#endif	/* Not _LOCKING_H_ */

#endif	/* Not __STRICT_ANSI__ */

