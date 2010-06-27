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

#ifndef _PRIVUT_H /* Prevent multiple inclusion */
#define _PRIVUT_H

#include "msf_lib.h"        /* For FILE */	/* LOKO 22/5 2002 */
/*#include "ansilibs.h"*/        /* For FILE */	/* LOKO 19/3 2002 */
/*loko#include "stdio.h"*/  /* For FILE */
#include "config.h" /* For __DOS__ */
#include "ut.h"     /* For u8, u32, & ut_sdfn */

#include "heap.h"
#include "thrdcst.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Global configuration flags, used by ut_setflags() and ut_getflags() */
extern u32 _ut_flags;
extern int _ut_isInitialised;

/* For ASN.1 BER tag stuff */
extern const u8 CST32EXPORTDATA * CST16EXPORTDATA _ut_berids[];

/* Application name */
extern char ut_name[];

/** Error stuff **/

/* Number of characters remembered from application name */
#define _UT_NAME_SZ (23)

/* Number of characters allowed for error messages */
#define _UT_MESSAGE_SZ (511)

/* Last error message */
extern char _ut_message[];

/* List of recorded error numbers */
extern u32 _ut_errors[];

/* Number of recorded error numbers */
extern unsigned _ut_nerrors;

/* Usage message */
extern const char *_ut_usage;

/* Whether or not to log errors */
extern int _ut_log_on;

/* Log file */
extern char _ut_log_file[];

/* Log stream */
extern FILE *_ut_log_stream;

/* Shutdown function */
extern ut_sdfn _ut_shutdown;

/* Memory log file */
extern char _ut_mlogname[];

/* Memory shutdown function */
extern void _ut_mshutdown(void);

#ifdef WITH_mm_soh

/* Is the SOH enabled. */
extern utb
_ut_heap_initialized;

/* Maximum entity on the heap. */
extern u32
_ut_heap_max;

/* Initialize small object heap system */
extern void
_ut_heapmgr_init
(u32 maxHeaped, u32 initialSize);

/* Destroy small object heap system */
extern void
_ut_heapmgr_shutdown
(void);

/* Notify heap manager of thread exit */
extern void
_ut_heapmgr_threadexit
(void);

/* Get or create this thread's heap; enbiggens it as necessary to hold size */
extern ut_Heap *
_ut_heap_get
(u32 size);

#endif /* WITH_mm_soh */

/*
 * Critical Section support.
 */

/* semaphore initialization and shutdown functions */
extern void _ut_mtinit(void);
extern void _ut_mtshutdown(void);

extern CSTMutex *_ut_log_locker;
extern CSTMutex *_ut_mem_locker;

#ifdef __cplusplus
}
#endif

#endif /* not _PRIVUT_H */
