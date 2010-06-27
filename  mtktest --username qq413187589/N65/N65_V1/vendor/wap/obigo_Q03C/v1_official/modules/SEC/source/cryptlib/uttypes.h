/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#ifndef _UTTYPES_H /* Prevent multiple inclusion */
#define _UTTYPES_H

/*Removed by ANAO 29/3-2001 #include "stddef.h"*/
/*Removed by JAK 28/2-2001	#include "sys/types.h"*/

#ifdef __cplusplus 
extern "C" {
#endif

#ifndef __BALTIMORE_TYPES_DEFINED__
#define __BALTIMORE_TYPES_DEFINED__

#include "msf_def.h"
#include "msf_lib.h"

#ifndef SEC_OFF_T
#define SEC_OFF_T
	typedef long sec_off_t;
#endif

  
  
	#ifndef abort							/* LOKO 29/5 2001 */
	#define abort()
	#endif

  /* Inserted 20/8 2002 LOKO */
  /*  WCHAR   :   16 bit unsigned character   */
  #ifndef _WINDOWS_
	  #ifdef TRGT_SDLM
		  typedef MSF_UINT16     WCHAR;
	  #elif defined TRGT_SEOS
		  typedef unsigned int   WCHAR;
	  #else
		  typedef unsigned short WCHAR;
	  #endif
  #endif

	#ifndef wchar_t						/* LOKO 14/5 2001 */
	#ifndef _WCHAR_T_DEFINED	/* LOKO 29/5 2001 */
	#define wchar_t WCHAR
	#endif
	#endif
	
	#ifndef LONG_MIN			/*ANAO 22/5	2001*/
	#define LONG_MIN    (-2147483647L - 1) /* minimum (signed) long value */
	#endif
	
	#ifndef LONG_MAX			/*ANAO 22/5	2001*/
	#define LONG_MAX      2147483647L   /* maximum (signed) long value */
	#endif
	
#ifndef TRGT_VXWORKS	/* LOKO 11/3 2002 */
	typedef MSF_INT8    int8_t;
	typedef MSF_INT16   int16_t;
	typedef MSF_INT32   int32_t;
	typedef MSF_UINT8   uint8_t;
	typedef MSF_UINT16  uint16_t;
	typedef MSF_UINT32  uint32_t;
#endif


#endif /* !__BALTIMORE_TYPES_DEFINED__ */

typedef int8_t          s8;
typedef uint8_t         u8;
typedef int16_t         s16;
typedef uint16_t        u16;
typedef int32_t         s32;
typedef uint32_t        u32;



typedef enum {
  UT_FALSE, UT_TRUE     
}                       utb;

/* Memory block - for passing to and from ASN.1 functions, holding arbitrary
 *  * pieces of 8-bit data, .. */
typedef struct {
  u8     *data;
  size_t  size;
  size_t  used;
} ut_mblk;

/* List of memory blocks */
typedef struct ut_mblk_list_s *ut_mblk_list;

struct ut_mblk_list_s {
  ut_mblk_list prev;
  ut_mblk_list next;
  ut_mblk      block;
};
  
#ifdef __cplusplus
}
#endif

#endif /* _UTTYPES_H */
