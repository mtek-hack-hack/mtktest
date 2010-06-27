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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/profil.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Id: profil.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Date: 2007/05/17 07:25:32 $
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
* $Log: profil.h,v $
* Revision 1.1  2007/05/17 07:25:32  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/profil.h,v 1.1 2007/05/14 09:46:46 bw Exp $
*
* ~Id: profil.h,v 1.1 2007/05/14 09:46:46 bw Exp $
*
* ~Date: 2007/05/14 09:46:46 $
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
* ~Log: profil.h,v $
* Revision 1.1  2007/05/14 09:46:46  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/profil.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: profil.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Date: 2007/04/04 06:51:33 $
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
* ~Log: profil.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* profil.h: gprof profiling header file

   Copyright 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

/*
 * This file is taken from Cygwin distribution. Please keep it in sync.
 * The differences should be within __MINGW32__ guard.
 */

/* profiling frequency.  (No larger than 1000) */
#define PROF_HZ			100

/* convert an addr to an index */
#define PROFIDX(pc, base, scale)	\
  ({									\
    size_t i = (pc - base) / 2;				\
    if (sizeof (unsigned long long int) > sizeof (size_t))		\
      i = (unsigned long long int) i * scale / 65536;			\
    else								\
      i = i / 65536 * scale + i % 65536 * scale / 65536;		\
    i;									\
  })

/* convert an index into an address */
#define PROFADDR(idx, base, scale)		\
  ((base)					\
   + ((((unsigned long long)(idx) << 16)	\
       / (unsigned long long)(scale)) << 1))

/* convert a bin size into a scale */
#define PROFSCALE(range, bins)		(((bins) << 16) / ((range) >> 1))

typedef void *_WINHANDLE;

struct profinfo {
    _WINHANDLE targthr;			/* thread to profile */
    _WINHANDLE profthr;			/* profiling thread */
    u_short *counter;			/* profiling counters */
    u_long lowpc, highpc;		/* range to be profiled */
    u_int scale;			/* scale value of bins */
};

int profile_ctl(struct profinfo *, char *, size_t, u_long, u_int);
int profil(char *, size_t, u_long, u_int);

