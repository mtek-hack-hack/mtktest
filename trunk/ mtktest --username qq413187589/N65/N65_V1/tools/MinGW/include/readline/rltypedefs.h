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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/readline/rltypedefs.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Id: rltypedefs.h,v 1.1 2007/05/17 07:25:42 bw Exp $
*
* $Date: 2007/05/17 07:25:42 $
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
* $Log: rltypedefs.h,v $
* Revision 1.1  2007/05/17 07:25:42  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/readline/rltypedefs.h,v 1.1 2007/05/14 09:47:06 bw Exp $
*
* ~Id: rltypedefs.h,v 1.1 2007/05/14 09:47:06 bw Exp $
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
* ~Log: rltypedefs.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/readline/rltypedefs.h,v 1.2 2007/04/04 06:51:40 bw Exp $
*
* ~Id: rltypedefs.h,v 1.2 2007/04/04 06:51:40 bw Exp $
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
* ~Log: rltypedefs.h,v $
* Revision 1.2  2007/04/04 06:51:40  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* rltypedefs.h -- Type declarations for readline functions. */

/* Copyright (C) 2000 Free Software Foundation, Inc.

   This file is part of the GNU Readline Library, a library for
   reading lines of text with interactive input and history editing.

   The GNU Readline Library is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2, or
   (at your option) any later version.

   The GNU Readline Library is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   The GNU General Public License is often shipped with GNU software, and
   is generally kept in a file called COPYING or LICENSE.  If you do not
   have a copy of the license, write to the Free Software Foundation,
   59 Temple Place, Suite 330, Boston, MA 02111 USA. */

#ifndef _RL_TYPEDEFS_H_
#define _RL_TYPEDEFS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Old-style */

#if !defined (_FUNCTION_DEF)
#  define _FUNCTION_DEF

typedef int Function ();
typedef void VFunction ();
typedef char *CPFunction ();
typedef char **CPPFunction ();

#endif /* _FUNCTION_DEF */

/* New style. */

#if !defined (_RL_FUNCTION_TYPEDEF)
#  define _RL_FUNCTION_TYPEDEF

/* Bindable functions */
typedef int rl_command_func_t __P((int, int));

/* Typedefs for the completion system */
typedef char *rl_compentry_func_t __P((const char *, int));
typedef char **rl_completion_func_t __P((const char *, int, int));

typedef char *rl_quote_func_t __P((char *, int, char *));
typedef char *rl_dequote_func_t __P((char *, int));

typedef int rl_compignore_func_t __P((char **));

typedef void rl_compdisp_func_t __P((char **, int, int));

/* Type for input and pre-read hook functions like rl_event_hook */
typedef int rl_hook_func_t __P((void));

/* Input function type */
typedef int rl_getc_func_t __P((FILE *));

/* Generic function that takes a character buffer (which could be the readline
   line buffer) and an index into it (which could be rl_point) and returns
   an int. */
typedef int rl_linebuf_func_t __P((char *, int));

/* `Generic' function pointer typedefs */
typedef int rl_intfunc_t __P((int));
#define rl_ivoidfunc_t rl_hook_func_t
typedef int rl_icpfunc_t __P((char *));
typedef int rl_icppfunc_t __P((char **));

typedef void rl_voidfunc_t __P((void));
typedef void rl_vintfunc_t __P((int));
typedef void rl_vcpfunc_t __P((char *));
typedef void rl_vcppfunc_t __P((char **));
#endif /* _RL_FUNCTION_TYPEDEF */

#ifdef __cplusplus
}
#endif

#endif /* _RL_TYPEDEFS_H_ */
