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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/symcat.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Id: symcat.h,v 1.1 2007/05/17 07:25:35 bw Exp $
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
* $Log: symcat.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/symcat.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Id: symcat.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Date: 2007/05/14 09:46:52 $
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
* ~Log: symcat.h,v $
* Revision 1.1  2007/05/14 09:46:52  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/symcat.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: symcat.h,v 1.2 2007/04/04 06:51:34 bw Exp $
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
* ~Log: symcat.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* Symbol concatenation utilities.

   Copyright (C) 1998, 2000 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifndef SYM_CAT_H
#define SYM_CAT_H

#if defined (__STDC__) || defined (ALMOST_STDC) || defined (HAVE_STRINGIZE)
#define CONCAT2(a,b)	 a##b
#define CONCAT3(a,b,c)	 a##b##c
#define CONCAT4(a,b,c,d) a##b##c##d
#define STRINGX(s) #s
#else
/* Note one should never pass extra whitespace to the CONCATn macros,
   e.g. CONCAT2(foo, bar) because traditonal C will keep the space between
   the two labels instead of concatenating them.  Instead, make sure to
   write CONCAT2(foo,bar).  */
#define CONCAT2(a,b)	 a/**/b
#define CONCAT3(a,b,c)	 a/**/b/**/c
#define CONCAT4(a,b,c,d) a/**/b/**/c/**/d
#define STRINGX(s) "s"
#endif

#define XCONCAT2(a,b)     CONCAT2(a,b)
#define XCONCAT3(a,b,c)   CONCAT3(a,b,c)
#define XCONCAT4(a,b,c,d) CONCAT4(a,b,c,d)

/* Note the layer of indirection here is typically used to allow
   stringification of the expansion of macros.  I.e. "#define foo
   bar", "XSTRING(foo)", to yield "bar".  Be aware that this only
   works for __STDC__, not for traditional C which will still resolve
   to "foo".  */
#define XSTRING(s) STRINGX(s) 

#endif /* SYM_CAT_H */
