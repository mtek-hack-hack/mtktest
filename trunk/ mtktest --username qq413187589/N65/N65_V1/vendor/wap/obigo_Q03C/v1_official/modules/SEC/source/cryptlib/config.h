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

#ifndef _CST_CONFIG_H /* Prevent multiple inclusion */
#define _CST_CONFIG_H

#ifdef THIS_WAS_A_SPOOF   /* THIS WILL NEED TO BE TAKEN OUT */
#define CSTEXPORTTYPE
#define CSTEXPORTDATA
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif

#if (defined(MSDOS) || defined(__MSDOS__) || defined (_DOS) || defined(_WINDOWS) || defined (WIN32) || defined (_WIN32)) && !defined(__DOS__)
#  define __DOS__
#endif /* (defined(MSDOS) || defined(__MSDOS__)) && !defined(__DOS__) */

/* Check for MAC compilation with CodeWarrior... */
#if ((defined (__POWERPC__) || defined (__CFM68K__) || defined (__MC68K__)) && !defined (__MAC__))
#define __MAC__
#endif

#if defined (__MVS__)

#  ifndef SEPARATOR
#    define SEPARATOR '/'
#  endif
#  define HAVE_SYS_TIME_H (1)
#  define HAVE_DIRENT_H (1)
#  define HAVE_UNISTD_H (1)
#  define USE_RAND (1)
#  define TIMEOFDAY_DOES_TZ (0)
#ifndef WORDS_BIGENDIAN
#  define WORDS_BIGENDIAN (1)
#endif
#elif defined (__TANDEM__)

#  ifndef SEPARATOR
#    define SEPARATOR '.'
#  endif
#  define CST_NO_THREADS
#  define TIMEOFDAY_DOES_TZ (1)
#  define HAVE_SYS_TIME_H (0)
#ifndef WORDS_BIGENDIAN
#  define WORDS_BIGENDIAN (1)
#endif
#  define NOT_HAVE_DIRECT_H (1)

#elif defined (__MAC__)

#  ifndef SEPARATOR
#    define SEPARATOR '/'
#  endif
#  define HAVE_SYS_TIME_H (0)
#  define HAVE_DIRENT_H (0)
#  define HAVE_UNISTD_H (1)
#  define USE_RAND (0)
#  define TIMEOFDAY_DOES_TZ (0)
#ifndef WORDS_BIGENDIAN
#  define WORDS_BIGENDIAN (1)
#endif
#elif defined(__DOS__)

#  ifndef SEPARATOR
#    define SEPARATOR '\\'
#  endif
#  define HAVE_SYS_TIME_H (0)
#  define HAVE_DIRENT_H (0)
#  define HAVE_UNISTD_H (0)
#  define USE_RAND (1)

#  if !defined(__WATCOMC__)
#    define TIMEOFDAY_DOES_TZ (1)
#  endif /* not __WATCOMC__ */

#else /* Unix, probably */

#  ifndef SEPARATOR
#    define SEPARATOR '/'
#  endif
#  if defined(__WINDOWS_386__)
#    define HAVE_SYS_TIME_H (0)
#    define USE_RAND (1)
#  else
#    define HAVE_SYS_TIME_H (1)
#    define HAVE_DIRENT_H (1)
#    define HAVE_UNISTD_H (1)

/* gettimeofday takes only one parameter under the (very few) sysv systems 
 * I've seen.
 * They don't like random()/srandom() either.
 */

#    if defined(SVR4) || defined(__svr4__) || defined(SYSV) || \
           defined(__sysv__)
#      define USE_RAND (1)
#      define TIMEOFDAY_DOES_TZ (1)
#    else /* sysv-svr4/not sysv-svr4 */
#      define USE_RAND (0)
#      define TIMEOFDAY_DOES_TZ (1)
#    endif /* not sysv-svr4 */

#  endif

#endif /* not defined (__MVS__) */

/* Assuming we're using gcc, so this line will work. It depends on the
 * flag cppflag_system defined in the Makefile.
 */

#if (defined CST_SYS_9000_826 || defined CST_SYS_9000_800 \
  || defined CST_SYS_sun4u)
#ifndef WORDS_BIGENDIAN
#  define WORDS_BIGENDIAN (1)
#endif
#else
/* removed by JAK 28/2-2001		#  define WORDS_BIGENDIAN (BYTES_BIG_ENDIAN)*/
#endif

/* Do we do threadsafety? Not on HP_UX or Win16, we don't. */

#if (defined (CST_OS_HP_UX) && defined (CST_REL_B_10_20)) || \
    (defined (CST_OS_OSF1)) || \
    (defined (__DOS__) && !defined(WIN32))
#  ifndef CST_NO_THREADS
#    define CST_NO_THREADS
#  endif
#endif  /* def <various> */

/* Clock tick information. On the Sparc, the clock resolution is 0.000001s, but this
 * value only changes 60 times a second. TICKS_PER_SEC holds this number. If
 * it's undefined, I assume that the machine's clock ticks at maximum
 * resolution. 
 */
#ifndef TICKS_PER_SEC
#ifdef __sun__ /* On suns it seems to be 60 a second.. */
#define TICKS_PER_SEC (60.0)
#else /* __sun__/not __sun__ */
#define TICKS_PER_SEC CLOCKS_PER_SEC
#endif /* not __sun__ */
#endif /* not TICKS_PER_SEC */

/* SYS_sun4u implies UltraSparc which is technically 
 * 64 bit but enabling 64 bit doesn't help because it
 * does not provide some operations. Hence sun4uhu to disable
 * it for the time being. 
 */
#if defined (CST_SYS_alpha) || defined (CST_SYS_sun4uhu)
#  define CST_ARCH_64
#endif /* defined <alpha/sparc> */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _CST_CONFIG_H */
