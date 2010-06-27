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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/fenv.h,v 1.1 2007/05/17 07:25:28 bw Exp $
*
* $Id: fenv.h,v 1.1 2007/05/17 07:25:28 bw Exp $
*
* $Date: 2007/05/17 07:25:28 $
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
* $Log: fenv.h,v $
* Revision 1.1  2007/05/17 07:25:28  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/fenv.h,v 1.1 2007/05/14 09:46:39 bw Exp $
*
* ~Id: fenv.h,v 1.1 2007/05/14 09:46:39 bw Exp $
*
* ~Date: 2007/05/14 09:46:39 $
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
* ~Log: fenv.h,v $
* Revision 1.1  2007/05/14 09:46:39  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/fenv.h,v 1.2 2007/04/04 06:51:31 bw Exp $
*
* ~Id: fenv.h,v 1.2 2007/04/04 06:51:31 bw Exp $
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
* ~Log: fenv.h,v $
* Revision 1.2  2007/04/04 06:51:31  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _FENV_H_
#define _FENV_H_


/* FPU status word exception flags */
#define FE_INVALID	0x01
#define FE_DENORMAL	0x02
#define FE_DIVBYZERO	0x04
#define FE_OVERFLOW	0x08
#define FE_UNDERFLOW	0x10
#define FE_INEXACT	0x20
#define FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#define FE_TONEAREST	0x0000
#define FE_DOWNWARD	0x0400
#define FE_UPWARD	0x0800
#define FE_TOWARDZERO	0x0c00

#ifndef RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
typedef unsigned short fexcept_t;

/* This 28-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv */
typedef struct
{
  unsigned short __control_word;
  unsigned short __unused0;
  unsigned short __status_word;
  unsigned short __unused1;
  unsigned short __tag_word;
  unsigned short __unused2;  
  unsigned int	 __ip_offset;    /* instruction pointer offset */
  unsigned short __ip_selector;  
  unsigned short __opcode;
  unsigned int	 __data_offset;
  unsigned short __data_selector;  
  unsigned short __unused3;
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((const fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((const fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((const fenv_t *) 0)

#ifdef __cplusplus
extern "C" {
#endif

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

extern int __cdecl feclearexcept (int);
extern int __cdecl fegetexceptflag (fexcept_t * flagp, int excepts);
extern int __cdecl feraiseexcept (int excepts );
extern int __cdecl fesetexceptflag (const fexcept_t *, int);
extern int __cdecl fetestexcept (int excepts);

/* 7.6.3 Rounding */

extern int __cdecl fegetround (void);
extern int __cdecl fesetround (int mode);

/* 7.6.4 Environment */

extern int __cdecl fegetenv (fenv_t * envp);
extern int __cdecl fesetenv (const fenv_t * );
extern int __cdecl feupdateenv (const fenv_t *);
extern int __cdecl feholdexcept (fenv_t *);

#ifdef __cplusplus
}
#endif
#endif	/* Not RC_INVOKED */

#endif /* ndef _FENV_H */
