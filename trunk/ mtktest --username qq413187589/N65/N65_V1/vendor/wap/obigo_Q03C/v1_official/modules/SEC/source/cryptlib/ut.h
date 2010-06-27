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
 
#ifndef _UT_H /* Prevent multiple inclusion */
#define _UT_H

#include "msf_lib.h"        /* For FILE */ /* For size_t */	/* LOKO 22/5 2002 */
/*#include "ansilibs.h"*/        /* For FILE */ /* For size_t */	/* LOKO 19/3 2002 */
/*loko#include "stdio.h"*/     /* For FILE */
/*loko#include "stdlib.h"*/    /* For size_t */

/* ************** */
/* 20/3 2001 LOKO */
/*#include "wchar.h"*/     /* For wchar_t */	
/* ************** */

#include "cstopt.h"    /* For system-specific settings */

#include "uttypes.h"   /* For u32, wchar_t, etc. */
#include "blt_asn1.h" /*PRW 2003-03-25: Resolve filename conflict*/      /* For ASN.1 stuff */
#include "asnconv.h"   /* For backwards compatibility */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define UTEXPORT   /* legacy reasons */

/* Macros */ 

#define ut_min(a,b)  ((a) < (b) ? (a) : (b))
#define ut_max(a,b)  ((a) > (b) ? (a) : (b))

#define U16_SWAP_BYTES(a)  ((((a) & 0xff) << 8) | (((a) >> 8) & 0xff))

/* Ensure that MSB of a u16 comes first */

#ifdef WORDS_BIGENDIAN
#define U16_TO_U8_ORDER(a)  (a)
#else
#define U16_TO_U8_ORDER(a)  U16_SWAP_BYTES(a)
#endif


/* Function:    <ut_setflags>
 * Summary:     Sets CST configuration information.
 * Syntax:      u32 rval = ut_setflags(u32 ORed_flags);
 * Description: The ut_setflags() function is called before ut_init().
 *              It uses ORed-together flags to tell ut_init() which
 *              configuration properties to turn on or off. The
 *              possible flags are:
 *              - CSTFLAGS_USESTDERR: Tells various internal functions
 *                that stderr is available for use for emergency error
 *                logging.
 *              - CSTFLAGS_MULTITHREADED: On all systems, turns on
 *                multithreading and critical section protection within
 *                CST. For multithreaded applications call
 *                the alternative ut_init_mt() initialization function.
 *                On UNIX systems, POSIX mutices are used; on Windows,
 *                Win32 critical sections.
 *              - CSTFLAGS_TIMESTAMP_ERRORLOG: When set, error messages
 *                produced by ut_log0(), ut_log1() or the rest of the
 *                ut__log() functions are preceded by a timestamp. The
 *                timestamp is produced by the standard run-time library
 *                ctime() function.
 *              - CSTFLAGS_NO_MEMLOG: In debug mode, when set, turns off 
 *                memory logging. This can result in a substantial
 *                performance gain. In NDEBUG (release) mode, has no
 *                effect.
 *              - CSTFLAGS_THREAD_LOCAL_HEAP: A side effect of the pseudo
 *                object-oriented design of the CST and associated
 *                libraries is that they may incur a great number of
 *                small memory allocation operations. On multiprocessor
 *                machines with inefficient memory allocators, this may
 *                hamper scalability due to the use of a global semaphore
 *                into the memory heap. If you enable this flag,
 *                CST employs its own lock-free, thread-local memory
 *                heap for efficient small object allocation and
 *                deallocation. This may be slightly more costly than
 *                the standard allocator and may result in slightly
 *                increased memory usage, but it may enhance scalability.
 *
 *                *WARNING*: If you enable this flag under WIN32, you
 *                must call the function ut_thread_exiting() immediately
 *                before any of your threads exit. This releases the local 
 *                heap upon thread exit. The POSIX threading system includes
 *                automatic cleanup facilities.               
 *              Any flags that cannot be set (because they refer to
 *              behavior that isn't supported on the given system)
 *              are filtered out before the flags are stored. This can
 *              result in the return from ut_getflags() being different
 *              from the argument to ut_setflags(). ut_setflags() returns
 *              the flags that couldn't be set; if all flags could be
 *              set correctly, it returns 0.
 *
 *              ut_setflags() MUST be called before ut_init(). It will
 *              have no effect if you call it after ut_init().
 * Returns:     This function returns the value of the flags that weren't set
 *              or 0 on total success. If it is called again it returns ~1 and 
 *              makes no change. It does not log errors.
 * Example:     This example tries to set the flags. On failure it checks
 *              to see what the set flags are and continues if the set
 *              flags are the same as the ones that should have been
 *              set.
 *           (code)
 *              if(ut_setflags (CSTFLAGS_USESTDERR | CSTFLAGS_MULTITHREADED)) {
 *                u32 flags = ut_getflags();
 *                if (flags != (CSTFLAGS_USESTDERR | CSTFLAGS_MULTITHREADED)) {
 *                  fprintf (stderr, "App has already been initialized "
 *                    "with incompatible settings\n");
 *                  exit(1);
 *                }
 *              }
 *           (/code)
 * Notes:       Only call ut_setflags() once.
 */
extern u32 ut_setflags(u32 flags);

/* Function:    <ut_getflags>
 * Summary:     Gets CST configuration information.
 * Syntax:      u32 flags = ut_getflags();
 * Description: Returns the flags set by a previous successful call to
 *              ut_setflags. A list of flags is given below. In Win16
 *              environments, the multithreading flags are never set.
 * Returns:     This function returns 0 if ut_setflags() has not been called.
 * Example:     See ut_setflags().
 */
extern u32 ut_getflags(void);

/* Flag values for ut_setflags() */

/* Multithreading configuration */

#define CSTFLAGS_USESTDERR             0x00000001L
#define CSTFLAGS_MULTITHREADED         0x00000002L
#ifndef WIN32
/* deprecated... */
#define CSTFLAGS_MUTEX_PTHREAD         0x00000000L
#endif  /* def/ndef WIN32 */
#define CSTFLAGS_TIMESTAMP_ERRORLOG    0x00000008L
#define CSTFLAGS_NO_MEMLOG             0x00000010L
#define CSTFLAGS_THREAD_LOCAL_HEAP     0x00000020L

/* Decoders for use on flags returned from ut_getflags() */

#define CSTFLAGS_GET_USESTDERR(x)           (x & (CSTFLAGS_USESTDERR))
#define CSTFLAGS_GET_MULTITHREADED(x)       (x & (CSTFLAGS_MULTITHREADED))
#define CSTFLAGS_GET_TIMESTAMP_ERRORLOG(x)  (x & (CSTFLAGS_TIMESTAMP_ERRORLOG))
#define CSTFLAGS_GET_NO_MEMLOG(x)           (x & (CSTFLAGS_NO_MEMLOG))
#define CSTFLAGS_GET_THREAD_LOCAL_HEAP(x)   (x & (CSTFLAGS_THREAD_LOCAL_HEAP))

/* Handy macro... */
#define CST_PRINTIFSTDERR(x) if(CSTFLAGS_GET_USESTDERR(ut_getflags())) \
      fprintf(stderr,(x))


/* Function:    <ut_init>
 * Summary:     Initializes CST library.
 * Syntax:      void ut_init(const char *appname, const char *usage,
 *                const char *logfile, FILE *logstream);
 * Description: The ut_init() function initializes the current application's 
 *              CST engine. It MUST be called, once and only once, when
 *              the application is started up. In the same way,
 *              ut_shutdown() MUST be called when the application is shut down.
 *
 *              Multithreaded applications should, in preference, call the
 *              ut_init_mt() function for full threading support.
 *              The ut_init() function provides basic support for multithreaded
 *              applications, but it cannot enable support for advanced features
 *              such as the thread-local heap.
 *
 *              Before calling ut_init(), call ut_setflags()
 *              to set configuration information. The call to ut_init()
 *              commits these configuration choices, which can't then be
 *              modified.
 *
 *              The arguments to ut_init() itself set configuration
 *              choices for error logging using ut__log(). You should
 *              always call ut_init() even if you aren't using ut__log()
 *              (or its derivatives ut_log0(), ut_log1(), etc.),
 *              as internal CST routines will call these functions in
 *              the event of an internal error. The arguments are:
 *
 *              - appname: ut__log() precedes all error messages with
 *                the name of the executable. This is derived from
 *                appname, so if you call
 *           (code)
 *                ut_init("microdes", ...);
 *           (/code)
 *                all error messages will start microdes:.
 *                  If appname includes directory names, these are stripped 
 *                off and appname is set equal to the text after the last
 *                separator ("\" for Windows/DOS, "/" for Unix). In DOS,
 *                the trailing .exe is stripped as well. The remaining
 *                string is cut to the first 23 letters if it is more
 *                than 23 letters long.
 *                  If appname == NULL, it is set internally to unknown. 
 *                When ut_shutdown() is called in debug mode, if there is
 *                any remaining unfreed memory, the memory log is appended
 *                to the file ./appname.unf. This can be of some help
 *                in tracking down memory leaks. appname can be any
 *                length
 *              - usage: If you are writing a command-line application,
 *                usage is a description of the command-line syntax. If the
 *                application is called with incorrect arguments, it
 *                should call
 *           (code)
 *                ut_log0(<errno>, UT_AXARGS, "Syntax error:");
 *           (/code)
 *                The UT_AXARGS argument tells the function to terminate
 *                the application and print usage to the console. usage
 *                need not be \n-terminated.
 *              - logfile is the name of the file that all error
 *                messages from ut__log() are logged to. If logfile is
 *                NULL, error messages are not logged to a file.
 *              - logstream is the name of an open, writable FILE stream
 *                that all error messages from ut__log() are logged to.
 *                If logstream is NULL, error messages are not logged to
 *                a stream. The usual values for logstream would be
 *                stderr or NULL.
 *              ut_init() can only be called once. It will not give a
 *              failure message if called a second time, but second and
 *              subsequent calls to ut_init will have no effect. The
 *              function ut_isInitialised() returns 1 if ut_init() has
 *              already been called and 0 otherwise.
 * Returns:     void.
 * Errors:      None.  Only the first 23 characters of the application file
 *              name are recorded. The function complains if it is compiled with
 *              UT_MHIST and it is unable to write to memory log (which it
 *              otherwise blanks). 
 * Notes:       You can use the functions ut_log_will_print() and ut_log_file()
 *              to ascertain what behavior for ut__log() has been specified.
 *
 *              See ut_init_mt() for details on initializing a
 *              multithreaded application.
 */

extern
void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_init(char *appname, const char *usage, char *logfile,
    FILE *logstream);

/* Function:    <ut_isInitialised>
 * Summary:     Checks if the CST library is initialized.
 * Syntax:      int result = ut_isInitialised();
 * Description: The ut_isInitialised() function returns 1 if ut_init() has 
 *              already been called; otherwise it returns 0.
 * Returns:     The function returns 1 if ut_init() has already be called;
 *              otherwise, it returns 0.
 */
extern int ut_isInitialised(void);

/* Function:    <ut_shutdown>
 * Summary:     Shuts down CST. In debug mode, checks for unfreed memory.
 * Syntax:      ut_shutdown();
 * Description: The ut_shutdown() function should be the final CST function
 *              called by your application. It frees all resources that
 *              were allocated by ut_init().
 *              If CST was operating in multithreaded mode, it closes 
 *              all the critical section protectors and deallocates
 *              any associated memory. It also finishes all the error
 *              logging. In debug mode, it checks to see if there is any
 *              memory allocated with ut_new_mem() that still has to be
 *              freed with ut_dispose_mem(). If there is any such memory
 *              it appends details of the allocation to the file
 *              ./appname.unf (where appname was the first argument to
 *              ut_init(), and unf stands for "unfreed"); this can be
 *              used to track down the memory leaks. In release (NDEBUG)
 *              mode, no memory checking is performed.
 * Returns:     This function returns no values.
 */
extern 
void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_shutdown(void);

/* Errors */

#define UT_EBASE (0x00100000) /* Module code */

#define UT_ENOLOG  (UT_EBASE + 0x40000) /* Cannot write memory stats file */
#define UT_ENFREE  (UT_EBASE + 0x40100) /* Memory still allocated on shutdown */
#define UT_ENOMEM  (UT_EBASE + 0x40200) /* Out of memory */
#define UT_EBADMEM (UT_EBASE + 0x40201) /* PROBLEM WITH MEMORY */
#define UT_ETHREAD (UT_EBASE + 0x40202) /* Threading-related problem */
#define UT_EDUMLG  (UT_EBASE + 0x40300) /* Dumped memory log */
#define UT_EA1ISZ  (UT_EBASE + 0x40400) /* Object too large (decoding) */
#define UT_EUNEXP  (UT_EBASE + 0x40500) /* Wrong type */
#define UT_ETLS32  (UT_EBASE + 0x40600) /* Integer too large (decoding) */
#define UT_ENFBIT  (UT_EBASE + 0x40700) /* Bit string with nonfull last byte */
#define UT_EA1ITP  (UT_EBASE + 0x40800) /* Unrecognized type (decoding) */
#define UT_ESEM    (UT_EBASE + 0x40900) /* problem locking or unlocking semaphore*/
#define UT_EPARAM  (UT_EBASE + 0x40A00) /* PARAMETER ERROR*/
#define UT_EALINI  (UT_EBASE + 0x40B00) /* already initialized*/

/* Memory utilities */

#if ((defined NDEBUG) || (defined _IN_UT_MEMORY_C))

/* Function:    <ut_new_mem>
 * Summary:     Allocates new memory.
 * Syntax:      (void *) ptr = ut_new_mem(size_t msize);
 * Description: The ut_new_mem() function allocates msize octets of memory
 *              and returns a pointer to the start of the block. 
 *
 *              In release (NDEBUG) mode, ut_new_mem() simply wraps malloc(). 
 *
 *              In debug mode, ut_new_mem() is a macro that calls the
 *              function ut__new_mem() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_new_mem() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed, it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how CST uses this
 *              information.
 *
 * Returns:     ut_new_mem() returns 0 on failure (lack of memory).
 * Memory:      Memory that is allocated with ut_new_mem() MUST be freed
 *              with ut_dispose_mem().
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_new_mem() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 */
extern void
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_new_mem(size_t size);

#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
/* Function:    <ut_ensure_mem>
 * Summary:     Ensures (reallocates) memory.
 * Syntax:      void *new = ut_ensure_mem(void *ptr, size_t msize);
 * Description: The ut_ensure_mem() function reallocates the memory at ptr
 *              to be msize octets. The old contents are preserved up to
 *              the minimum of the old and new sizes.  A pointer to the
 *              new space is returned. 
 *
 *              In release (NDEBUG) mode, ut_ensure_mem() simply wraps
 *              realloc() if ptr is nonzero and malloc() if ptr is zero. 
 *
 *              In debug mode, ut_ensure_mem() is a macro which calls the
 *              function ut__ensure_mem() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_ensure_mem() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how the CST uses this
 *              information.
 *
 * Memory:      Memory that is allocated with ut_ensure_mem() MUST be freed
 *              with ut_dispose_mem().
 * Errors:      ut_ensure_mem() returns 0 on failure due to lack of memory. It
 *              does NOT free the old data in such circumstances.
 *             
 *              ut_ensure_mem() will also fail (in a compiler-dependent way) if
 *              ptr is nonzero but does not correspond to a location where
 *              memory has already been allocated. Therefore, the following code
 *              will generally fail if tmp1 is not initialized to zero.
 *           (code)
 *              u8   *tmp1, *tmp2;
 *              tmp2 = ut_ensure_mem(tmp1, 8);
 *           (/code)
 *              
 *              This can result in code that succeeds in debug mode but
 *              fails in release mode.
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_ensure_mem() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.          
 *
 *              The function does not free the memory at ptr if it fails
 *              due to lack of memory. Code like
 *           (code)
 *              tmp = ut_ensure_mem(tmp, 16);
 *           (/code)
 *              should therefore be avoided, as it overwrites the
 *              pointer to the original memory.
 */
extern void
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_ensure_mem(void *ptr, size_t size);
#endif /* not WITH_mm_wip */

/* Function:    <ut_dispose_mem>
 * Summary:     Disposes of memory allocated with ut_new_mem().
 *              ut_ensure_mem().
 * Syntax:      ut_dispose_mem(void *ptr);
 * Description: The ut_dispose_mem() function frees the memory at ptr.
 *              ptr must be a value previously returned by
 *              ut_new_mem() or ut_ensure_mem().
 *
 *              In release (NDEBUG) mode, ut_dispose_mem() simply wraps free(). 
 *
 *              In debug mode, ut_dispose_mem() is a macro that calls the
 *              function ut__dispose_mem() (which should otherwise never be
 *              called directly). This function frees the memory and
 *              removes the entry from the memory log created by
 *              ut_new_mem() and/or ut_ensure_mem(). When ut_shutdown() is
 *              called at the end of the application, the internal log
 *              contains a list of all the memory that was allocated
 *              with ut_new_mem() or ut_ensure_mem() and not
 *              subsequently freed with ut_dispose_mem(). See ut_init()
 *              for more details of how the CST uses this information.
 * Returns:     This function returns no value.
 * Memory:      In debug mode, ut_dispose_mem aborts on attempts to free
 *              unallocated memory.
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_dispose_mem() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also fail.
 *              
 */

extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_mem(void *ptr);


/* Function:    <ut_new_mblk_f>
 * Summary:     Creates a ut_mblk *.
 * Syntax:      ut_mblk * rval = ut_new_mblk_f(size_t size);
 * Description: The ut_new_mblk() function allocates sizeof(ut_mblk) octets
 *              of memory at rval and then calls *rval = ut_new_mblk (size).
 *
 *              In debug mode, ut_new_mblk_f() is a macro that calls the
 *              function ut__new_mblk_f() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_new_mblk() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how the CST uses this
 *              information.
 *
 * Returns:     Returns 0 on failure (lack of memory).
 * Memory:      Memory that is allocated with ut_new_mem() MUST be freed
 *              with ut_dispose_mem(). The memory that this function allocates
 *              can therefore be freed with:
 *           (code)
 *              ut_dispose_mblk_f(rval);
 *           (/code)
 *              or
 *           (code)
 *              ut_dispose_mem(rval->data);
 *              ut_dispose_mem(rval);
 *           (/code)
 *                
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_new_mblk_f() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash. 
 */

ut_mblk
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_new_mblk_f(size_t size);

/* Function:    <ut_copy_mblk_f>
 * Summary:     Creates a ut_mblk *.
 * Syntax:      int rval = ut_copy_mblk_f(ut_mblk **new, ut_mblk *old);
 * Description: The ut_copy_mblk_f() function allocates sizeof(ut_mblk) octets
 *              of memory at *new and then copies *old to **new, allocating
 *              memory at new->data.
 *
 *              In debug mode, ut_copy_mblk_f() is a macro which calls the
 *              function ut__copy_mblk_f() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_copy_mblk_f() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how the CST uses this
 *              information.
 * Returns:     The function returns 0 on success or -1 on failure (lack of 
 *              memory).
 * Memory:      Memory that is allocated with ut_new_mem() MUST be freed
 *              with ut_dispose_mem(). The memory that this function allocates
 *              can therefore be freeed with:
 *           (code)
 *              ut_dispose_mblk_f(*new);
 *           (/code)
 *              or
 *           (code)
 *              ut_dispose_mem((*new)->data);
 *              ut_dispose_mem(*new);
 *           (/code)
 *                
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_copy_mblk_f() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 *              
 */
int 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_copy_mblk_f(ut_mblk **copy, ut_mblk *orig);

/* Function:    <ut_dispose_mblk_f>
 * Summary:     Disposes of memory allocated with ut_new_mblk_f().
 * Syntax:      ut_dispose_mblk_f(ut_mblk *old);
 * Description: The ut_dispose_mblk_f() function frees the memory at 
 *              old->data (if it is non-NULL) and old (if it is non-NULL).
 *              The memory must have been allocated with ut_new_mem(),
 *              ut_ensure_mem(), or one of the other functions that calls
 *              them.
 *
 *              In release (NDEBUG) mode, ut_dispose_mem() simply frees
 *              the memory at old and old->data.
 *
 *              In debug mode, ut_dispose_mblk_f() is a macro that calls the
 *              function ut__dispose_mblk_f() (which should otherwise never be
 *              called directly). This function frees the memory and
 *              removes the entry from the memory log created by
 *              ut_new_mem(), ut_ensure_mem(). When ut_shutdown() is
 *              called at the end of the application, the internal log
 *              contains a list of all the memory that was allocated
 *              with ut_new_mem() or ut_ensure_mem() and not
 *              subsequently freed with ut_dispose_mem(). See ut_init()
 *              for more details of how the CST uses this information.
 * Returns:     This function returns no value.
 * Memory:      In debug mode, ut_dispose_mblk_f() aborts on attempts to
 *              free unallocated memory.
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_dispose_mem() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 *              
 */
void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_mblk_f(ut_mblk *old);


/* Function:    <ut_new_mblk>
 * Summary:     Creates a ut_mblk.
 * Syntax:      ut_mblk rval = ut_new_mblk(size_t size);
 * Description: The ut_new_mblk() function allocates size octets
 *              of memory at rval.data and sets rval.size = size.
 *
 *              In debug mode, ut_new_mblk() is a macro that calls the
 *              function ut__new_mblk() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_new_mblk() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how CST uses this
 *              information.
 *
 * Returns:     On failure (lack of memory), rval.data = 0.
 * Memory:      Memory that is allocated with ut_new_mem() MUST be freed
 *              with ut_dispose_mem(). The memory that this function allocates
 *              can therefore be freed with:
 *           (code)
 *              ut_dispose_mblk(&rval);
 *           (/code)
 *              or
 *           (code)
 *              ut_dispose_mem(rval.data);
 *           (/code)
 *                
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_new_mblk() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 *              
 */
extern ut_mblk 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_new_mblk(size_t size);

#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
/* Function:    <ut_ensure_mblk>
 * Summary:     Ensures (reallocates) memory.
 * Syntax:      int rval = ut_ensure_mblk(ut_mblk *block, size_t msize);
 * Description: The ut_ensure_mblk() function reallocates the memory at 
 *              block.data to be msize octets. The old contents are preserved 
 *              up to the minimum of the old and new sizes. A pointer to the
 *              new space is returned.
 *
 *              In debug mode, ut_ensure_mblk() is a macro that calls the
 *              function ut__ensure_mblk() (which should otherwise never be
 *              called directly). This function notes the file and line
 *              that ut_ensure_mblk() was called from and logs them
 *              internally. When ut_shutdown() is called at the end of
 *              the application, the internal log is able to check for
 *              unfreed memory and state where it was allocated. The log
 *              also writes some bytes of known data before and after
 *              the allocated block; when the memory is freed it uses
 *              this known data to check for array bounds overruns. See
 *              ut_init() for more details of how CST uses this
 *              information.
 * Memory:      Memory that is allocated with ut_ensure_mblk() MUST be freed
 *              with ut_dispose_mblk().
 * Returns:     The function returns 0 on success or -1 on failure due to lack 
 *              of memory. It does NOT free the old data in such circumstances.           
 * Errors:      The function will also fail (in a compiler-dependent way) if
 *              block is nonzero but does not correspond to a location where
 *              memory has already been allocated. The following code will
 *              generally fail if tmp1 is not initialized to zero:
 *           (code)
 *              ut_mblk tmp1;
 *              rval = ut_ensure_mblk(tmp1, 8);
 *           (/code)
 *              This can result in code that succeeds in debug mode but
 *              fails in release mode.
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_ensure_mblk() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_ensure_mblk(ut_mblk *block, size_t size);
#endif /* not WITH_mm_wip */

/* Function:    <ut_dispose_mblk>
 * Summary:     Disposes of memory allocated with ut_new_mblk().
 * Syntax:      ut_dispose_mblk(ut_mblk *old);
 * Description: The ut_dispose_mblk() function frees the memory at old.data.
 *              old.data must have been allocated by ut_new_mem() or 
 *              ut_ensure_mem(), or by one of the functions that call them.
 *
 *              In debug mode, ut_dispose_mblk() is a macro that calls the
 *              function ut__dispose_mblk() (which should otherwise never be
 *              called directly). This function frees the memory and
 *              removes the entry from the memory log created by
 *              ut_new_mem() and/or ut_ensure_mem(). When ut_shutdown() is
 *              called at the end of the application, the internal log
 *              contains a list of all the memory that was allocated
 *              with ut_new_mem() or ut_ensure_mem() and not
 *              subsequently freed with ut_dispose_mem(). See ut_init()
 *              for more details of how the CST uses this information.
 *
 *              The function checks to see if old->data is zero before
 *              attempting to free it.
 * Returns:     This function returns no value.
 * Memory:      In debug mode, ut_dispose_mblk() aborts on attempts to free
 *              unallocated memory.
 * Notes:       This function only works properly if ut_init() was
 *              called when the application was initialized. 
 *
 *              Because ut_dispose_mblk() is a macro in debug mode and a
 *              function in release mode, any code that is compiled with
 *              the NDEBUG flag specified and then linked to a debug
 *              build of CST will crash. Code that is compiled without
 *              the NDEBUG flag and linked to a release build of CST will
 *              also crash.
 *              
 */
extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_mblk(ut_mblk *old);

#else /* NDEBUG or _IN_UT_MEMORY_C/neither */

#define ut_new_mem(size)          (ut__new_mem(__FILE__, __LINE__, size))
#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
#define ut_ensure_mem(ptr, size)  (ut__ensure_mem(__FILE__, __LINE__, ptr, size))
#endif /* not WITH_mm_wip */
#define ut_dispose_mem(ptr)       (ut__dispose_mem(__FILE__, __LINE__, ptr))
#define ut_new_mblk(size)         (ut__new_mblk(__FILE__, __LINE__, size))
#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
#define ut_ensure_mblk(ptr, size) (ut__ensure_mblk(__FILE__, __LINE__, ptr, size))
#endif /* not WITH_mm_wip */
#define ut_dispose_mblk(ptr)      (ut__dispose_mblk(__FILE__, __LINE__, ptr))
#define ut_new_mblk_f(size)       (ut__new_mblk_f(__FILE__, __LINE__, size))
#define ut_copy_mblk_f(copy, orig) (ut__copy_mblk_f(__FILE__, __LINE__, copy, orig))
#define ut_dispose_mblk_f(ptr)    (ut__dispose_mblk_f(__FILE__, __LINE__, ptr))

#endif /* not NDEBUG */

/* These functions should never be called directly. */

extern void 
CST32EXPORTTYPE * CST16EXPORTTYPE ut__new_mem(const char *, unsigned, size_t);
#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
extern void 
CST32EXPORTTYPE * CST16EXPORTTYPE ut__ensure_mem(const char *, unsigned, void *, size_t);
#endif /* not WITH_mm_wip */
extern void  
CST32EXPORTTYPE CST16EXPORTTYPE ut__dispose_mem(const char *, unsigned, void *);
extern ut_mblk
CST32EXPORTTYPE CST16EXPORTTYPE ut__new_mblk(const char *, unsigned, size_t);
#ifndef WITH_mm_wip /* WIP doesn't support realloc, so can't do this <sigh> */
extern int   
CST32EXPORTTYPE CST16EXPORTTYPE ut__ensure_mblk(const char *, unsigned, ut_mblk *, size_t);
#endif /* not WITH_mm_wip */
extern void  
CST32EXPORTTYPE CST16EXPORTTYPE ut__dispose_mblk(const char *, unsigned, ut_mblk *);
extern ut_mblk 
CST32EXPORTTYPE * CST16EXPORTTYPE ut__new_mblk_f(const char *, unsigned, size_t);
extern int   
CST32EXPORTTYPE CST16EXPORTTYPE ut__copy_mblk_f(const char *, unsigned, ut_mblk **, ut_mblk *);
extern void  
CST32EXPORTTYPE CST16EXPORTTYPE ut__dispose_mblk_f(const char *, unsigned, ut_mblk *);


/* Function:    <ut_copy_mblk>
 * Summary:     Copies contents from one ut_mblk to another.
 * Syntax:      int rval = ut_copy_mblk (ut_mblk *dst, ut_mblk *src);
 * Description: The ut_copy_mblk() function copies the contents of src to dst. 
 *              The routine allocates memory only at dst->data, so dst must be
 *              either the address of an existing ut_mblk or a pointer to 
 *              memory which has been allocated with 
 *              ut_new_mem(sizeof (ut_mblk)).
 * Returns:     The function returns 0 on success or -1 on failure. It
 *              fails on inability to allocate memory at dst->data.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *            (code)
 *              ut_dispose_mem(dst->data);
 *            (/code)
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
ut_copy_mblk(ut_mblk *dst, ut_mblk *src);

/* Function:    <ut_merge_list>
 * Summary:     Merges all the data in a ut_mblk_list into a single byte array.
 * Syntax:      u8 *buf = ut_merge_list(ut_mblk_list inlist, 
 *                int dispose_on_fail);
 * Description: The ut_merge_list() function concatenates all of the
 *              data contained in inlist into a single buffer at buf.
 *              It will only fail if it is unable to allocate sufficient
 *              continuous memory at buf to hold all the data. The
 *              memory at inlist is disposed of if the function
 *              succeeds, or if the function fails and dispose_on_fail
 *              is nonzero. This means that a subsequent call
 *              to ut_dispose_list(inlist) will have undefined, probably
 *              bad, results. If dispose_on_fail is zero and there is
 *              insufficient memory to complete the operation, this
 *              function has no effect.
 *
 *              inlist is assumed to be null-terminated.
 *
 *              Note that ut_merge_list returns a u8 *, not a ut_mblk.
 *              To accurately obtain the length of the data at buf, use
 *              code such as the following:
 *           (code)
 *               size_t        total = 0;     // the total data length 
 *               ut_mblk_list  cur = inlist;
 *               for(cur = inlist; cur; cur = cur->next)
 *                 total += cur->block.used;
 *           (/code)
 * Returns:     This function returns a pointer to the start of the
 *              concatenated data on success or 0 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              buf = ut_merge_list(inlist, 0);
 *              ...
 *              ut_dispose_mem(buf);
 *           (/code)
 *              Also note that if this function returns successfully,
 *              you MUST NOT call ut_dispose_list(inlist).
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_merge_list(ut_mblk_list inlist, int dispose_on_fail);

/* Function:    <ut_copy_list>
 * Summary:     Copies a ut_mblk_list.
 * Syntax:      ut_mblk_list rval = ut_copy_list(ut_mblk_list original);
 * Description: The ut_copy_list() function copies all of the contents
 *              of original to rval. It returns a copy of original on
 *              success or 0 on failure (out of memory).
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_list(rval);
 *           (/code)
 */
extern ut_mblk_list
CST32EXPORTTYPE CST16EXPORTTYPE
ut_copy_list(ut_mblk_list original);

/* Function:    <ut_dispose_list>
 * Summary:     Disposes of a ut_mblk_list and all of its data.
 * Syntax:      ut_dispose_list(ut_mblk_list inlist);
 * Description: The ut_dispose_list() function disposes of all the
 *              entries in inlist and all the memory associated with those
 *              entries.
 * Memory:      This function allocates no memory.
 */
extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_list(ut_mblk_list inlist);

/* Function:    <ut_dispose_list_outer>
 * Summary:     Disposes of ut_mblk_list but preserves contents.
 * Syntax:      ut_dispose_list_outer(ut_mblk_list inlist);
 * Description: The ut_dispose_list_outer() function disposes of the
 *              memory in the ut_mblk_lists at inlist, but leaves the
 *              memory in the actual ut_mblks intact. Use this when
 *              disposing of ut_mblk_lists created with
 *              ut_add_list_item_before() and ut_add_list_item_after().
 * Memory:      This function allocates no memory.
 */
extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_list_outer(ut_mblk_list);

/* Function:    <ut_dispose_list_item>
 * Summary:     Deletes a single item from a ut_mblk_list.
 * Syntax:      ut_dispose_list_item(ut_mblk_list inlist);
 * Description: The ut_dispose_list_item() function disposes of all
 *              the memory associated with the single ut_mblk_list item inlist. 
 *              It joins inlist->prev to inlist->next if they exist.
 * Memory:      This function allocates no memory.
 */
extern void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_list_item(ut_mblk_list inlist);


/* Function:    <ut_dispose_list_item_outer>
 * Summary:     Deletes item from ut_mblk_list but preserves contents.
 * Syntax:      ut_dispose_list_item_outer(ut_mblk_list inlist);
 * Description: The ut_dispose_list_item_outer() function disposes of
 *              the ut_mblk_list wrapper at inlist, but preserves the
 *              memory at inlist->block.data. Use this when disposing
 *              of ut_mblk_lists created with ut_add_list_item_before()
 *              and ut_add_list_item_after().
 *              It joins inlist->prev to inlist->next if they exist.
 * Memory:      This function allocates no memory.
 */
extern void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_list_item_outer(ut_mblk_list);


/* Function:    <ut_add_list_item_before>
 * Summary:     Adds a ut_mblk to a ut_mblk_list.
 * Syntax:      ut_mblk_list rval = ut_add_list_item_before(ut_mblk_list
 *                inlist, ut_mblk *mitem);
 * Description: The ut_add_list_item_before() function puts a ut_mblk into
 *              a ut_mblk_list as the item before the current one. If
 *              inlist is 0, a new inlist is formed containing mitem as the
 *              only item.
 *
 *              This function puts the ut_mblk itself, not a copy of the
 *              ut_mblk, into inlist. Calling ut_dispose_mblk(mitem) also
 *              removes the data from its location in inlist.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      Dispose of the memory allocated by this function
 *              of using ut_dispose_list_outer() to dispose of the list
 *              wrappers, and then ut_dispose_mblk() on each of the list
 *              items in turn.
 * Errors:      This function fails on null second argument (in debug mode)
 *              or memory allocation failure.
 * Notes:       Do not use both ut_add_list_item_*() and
 *              ut_copy_list_item_*() functions to add items to the same
 *              list, or it will be very difficult to manage the memory
 *              reliably.
 *
 *              This function should be called with the syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_add_list_item_before(inlist, mitem))) {
 *                ut_dispose_list_outer(inlist);
 *                // dispose of all ut_mblks, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_mblk_list
CST32EXPORTTYPE CST16EXPORTTYPE
ut_add_list_item_before(ut_mblk_list inlist, ut_mblk *item);

/* Function:    <ut_add_list_item_after>
 * Summary:     Adds a ut_mblk to a ut_mblk_list.
 * Syntax:      ut_mblk_list rval = ut_add_list_item_after(ut_mblk_list
 *                inlist, ut_mblk *mitem);
 * Description: The ut_add_list_item_after() function puts a ut_mblk into
 *              a ut_mblk_list as the item after the current one. If
 *              inlist is 0, a new list is formed containing mitem as the
 *              only item.
 *
 *              This function puts the ut_mblk itself, not a copy of the
 *              ut_mblk, into inlist. Calling ut_dispose_mblk(mitem) 
 *              also removes the data from its location in inlist.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      Dispose of the memory allocated by this function
 *              of using ut_dispose_list_outer() to dispose of the list
 *              wrappers, and then ut_dispose_mblk() on each of the list
 *              items in turn.
 * Errors:      This function fails on null second argument (in debug mode)
 *              or memory allocation failure.
 * Notes:       Do not use both ut_add_list_item_*() and
 *              ut_copy_list_item_*() functions to add items to the same
 *              list, or it will be very difficult to manage the memory
 *              reliably.
 *
 *              This function should be called with the syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_add_list_item_after(inlist, mitem))) {
 *                ut_dispose_list_outer(inlist);
 *                // dispose of all ut_mblks, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_mblk_list
CST32EXPORTTYPE CST16EXPORTTYPE
ut_add_list_item_after(ut_mblk_list inlist, ut_mblk *item);

/* Function:    <ut_copy_list_item_before>
 * Summary:     Copies a ut_mblk to a ut_mblk_list.
 * Syntax:      ut_mblk_list rval = ut_copy_list_item_before(ut_mblk_list
 *              inlist, ut_mblk *mitem);
 * Description: The ut_copy_list_item_before() function puts a ut_mblk into
 *              a ut_mblk_list as the item before the current one. If
 *              inlist is 0, a new list is formed containing mitem as the
 *              only item.
 *
 *              This function puts a copy of mitem into inlist. Therefore
 *              it allocates enough memory to hold mitem.data as well as
 *              the memory for the list item itself.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      Dispose of the memory allocated by this function
 *              of using ut_dispose_list().
 * Errors:      This function fails on null second argument (in debug mode)
 *              or memory allocation failure.
 * Notes:       Do not use both ut_copy_list_item_*() and
 *              ut_copy_list_item_*() functions to copy items to the same
 *              list, or it will be very difficult to manage the memory
 *              reliably.
 *
 *              This function should be called with the syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_copy_list_item_before(inlist, mitem))) {
 *                ut_dispose_list_outer(inlist);
 *                // dispose of all ut_mblks, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_mblk_list
CST32EXPORTTYPE CST16EXPORTTYPE
ut_copy_list_item_before(ut_mblk_list inlist, ut_mblk *item);

/* Function:    <ut_copy_list_item_before>
 * Summary:     Copies a ut_mblk to a ut_mblk_list.
 * Syntax:      ut_mblk_list rval = ut_copy_list_item_before(ut_mblk_list
 *              inlist, ut_mblk *mitem);
 * Description: The ut_copy_list_item_before() function puts a ut_mblk into
 *              a ut_mblk_list as the item before the current one. If
 *              inlist is 0, a new list is formed containing mitem as the
 *              only item.
 *
 *              This function puts a copy of mitem into inlist. Therefore
 *              it allocates enough memory to hold mitem.data as well as 
 *              the memory for the list item itself.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      Dispose of the memory allocated by this function
 *              of using ut_dispose_list().
 * Errors:      fails on null second argument (in debug mode) or memory
 *              allocation failure.
 * Notes:       Do not use both ut_copy_list_item_*() and
 *              ut_copy_list_item_*() functions to copy items to the same
 *              list, or it will be very difficult to manage the memory
 *              reliably.
 *
 *              This function should be called with the syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_copy_list_item_before(inlist, mitem))) {
 *                ut_dispose_list_outer(inlist);
 *                // dispose of all ut_mblks, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_mblk_list
CST32EXPORTTYPE CST16EXPORTTYPE
ut_copy_list_item_after(ut_mblk_list inlist, ut_mblk *item);

/* Function:    <ut_count_list_items>
 * Summary:     Counts the number of items in a ut_mblk_list.
 * Syntax:      int rval = ut_count_list_items(ut_mblk_list inlist);
 * Description: The ut_count_list_items() function returns the number of items 
 *              in inlist, starting with inlist and continuing until we reach 
 *              a null item or we get back to inlist.
 * Memory:      This function allocates no memory.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
ut_count_list_items(ut_mblk_list inlist);

/* Function:    <ut_get_list_used>
 * Summary:     Gets total memory used in a ut_mblk_list.
 * Syntax:      size_t rval = ut_get_list_used(ut_mblk_list inlist);
 * Description: The ut_get_list_used() function counts the total amount of 
 *              memory used by the items in the ut_mblk_list, starting with 
 *              inlist and adding the used fields in each item until we reach 
 *              a null item or we get back to inlist.
 * Memory:      This function allocates no memory.
 */
extern size_t
CST32EXPORTTYPE CST16EXPORTTYPE
ut_get_list_used(ut_mblk_list inlist);

/* Function:    <ut_get_list_size>
 * Summary:     Gets total memory allocated in a ut_mblk_list.
 * Syntax:      size_t rval = ut_get_list_size(ut_mblk_list inlist);
 * Description: The ut_get_list_used() function counts the total amount of 
 *              memory allocated for the items in the ut_mblk_list, starting 
 *              with inlist and adding the used fields in each item until we 
 *              reach a null item or we get back to inlist.
 * Memory:      This function allocates no memory.
 */
extern size_t
CST32EXPORTTYPE CST16EXPORTTYPE
ut_get_list_size(ut_mblk_list inlist);



/* Type:        <ut_vlist>
 * Description: Generic holding structure for void *s.
 *
 * dispose is a function which disposes of the appropriate void * in
 * contents. It is called by ut_dispose_vlist and ut_dispose_vlist_item.
 * 
 * NOTE! If no specific dispose function is provided, ut_dispose_vlist
 * and ut_dispose_vlist_item call ut_dispose_mem to dispose of the
 * contents. This can lead to memory leaks if you're not careful.
 */

typedef struct ut_vlist_s *ut_vlist;

struct ut_vlist_s {
  ut_vlist  prev;
  ut_vlist  next;
  void     *contents;
  void    (*dispose)(void *);
};


/* Function:    <ut_dispose_vlist>
 * Summary:     Completely disposes of a ut_vlist.
 * Syntax:      ut_dispose_vlist(ut_vlist inlist);
 * Description: The ut_dispose_vlist() function disposes of a ut_vlist
 *              and all its contents, using litem->dispose for each
 *              list litem litem.
 * Memory:      This function allocates no memory.
 */

extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_vlist(ut_vlist inlist);


/* Function:    <ut_dispose_vlist_outer>
 * Summary:     Disposes of ut_vlist but preserve contents.
 * Syntax:      ut_dispose_vlist_outer(ut_vlist inlist);
 * Description: The ut_dispose_vlist_outer() function disposes of the
 *              memory in the ut_vlists at inlist, but leaves the
 *              memory in the actual void *s intact.
 * Memory:      This function allocates no memory.
 */
extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_vlist_outer(ut_vlist inlist);

/* Function:    <ut_dispose_vlist_item>
 * Summary:     Deletes a single item from a ut_vlist.
 * Syntax:      ut_dispose_vlist_item(ut_vlist list);
 * Description: The ut_dispose_vlist_item() function disposes of all
 *              the memory associated with the single ut_vlist item inlist,
 *              using inlist->dispose if it exists and ut_dispose_mem otherwise.
 *              It joins inlist->prev to inlist->next if they exist.
 * Memory:      This function allocates no memory.
 */
extern void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_vlist_item(ut_vlist inlist);


/* Function:    <ut_dispose_vlist_item_outer>
 * Summary:     Deletes item from ut_vlist but preserve contents.
 * Syntax:      ut_dispose_vlist_item_outer(ut_vlist inlist);
 * Description: The ut_dispose_vlist_item_outer() function disposes of
 *              the ut_vlist wrapper at inlist, but preserves the
 *              memory at inlist->contents. This is for use 
 *              when disposing of ut_vlists created with
 *              ut_add_vlist_item_before() and ut_add_vlist_item_after().
 *
 *              It joins inlist->prev to inlist->next if they exist.
 * Memory:      This function allocates no memory.
 */
extern void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_dispose_vlist_item_outer(ut_vlist inlist);


/* Function:    <ut_add_vlist_item_before>
 * Summary:     Adds a void * to a ut_vlist.
 * Syntax:      ut_vlist rval = ut_add_vlist_item_before(ut_vlist inlist, 
 *                void *contents, void(*dispose)(void *));
 * Description: The ut_add_vlist_item_before() function puts a void * into
 *              a ut_vlist as the item before the current one. If
 *              inlist is 0, a new inlist is formed containing mitem as the
 *              only item.
 * 
 *              dispose is a function that disposes of the void * in
 *              contents appropriately. It is called by ut_dispose_vlist() and 
 *              ut_dispose_vlist_item().
 * 
 *              If no specific dispose function is provided, ut_dispose_vlist
 *              and ut_dispose_vlist_item call ut_dispose_mem to dispose of the
 *              contents.

 *              This function puts the void * itself, not a copy of the
 *              void *, into inlist.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      The memory allocated by this function can be disposed
 *              of using ut_dispose_vlist_outer() to dispose of the list
 *              wrappers, and then the appropriate dispose on each of the list
 *              items in turn. Alternatively the entire list can be dispoosed
 *              of with ut_dispose_vlist().
 * Errors:      This function fails on null second argument (in debug mode)
 *              or memory allocation failure.
 * Notes:       This function should be called with the syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_add_vlist_item_before(inlist, mitem, disposfn))) {
 *                ut_dispose_vlist_outer(inlist);
 *                // dispose of all void *s, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_vlist
CST32EXPORTTYPE CST16EXPORTTYPE
ut_add_vlist_item_before(ut_vlist inlist, void *contents,
   void(*dispose)(void *));

/* Function:    <ut_add_vlist_item_after>
 * Summary:     Adds a void * to a ut_vlist.
 * Syntax:      ut_vlist rval = ut_add_vlist_item_after(ut_vlist inlist, 
 *                void *contents, void(*dispose)(void *));
 * Description: The ut_add_vlist_item_after() function puts a void * into
 *              a ut_vlist as the item after the current one. If
 *              inlist is 0, a new inlist is formed containing mitem as the
 *              only item.
 * 
 *              dispose is a function that disposes of the void * in
 *              contents appropriately. It is called by ut_dispose_vlist() and 
 *              ut_dispose_vlist_item().
 * 
 *              If no specific dispose function is provided, ut_dispose_vlist
 *              and ut_dispose_vlist_item call ut_dispose_mem to dispose of the
 *              contents.

 *              This function puts the void * itself, not a copy of the
 *              void *, into inlist.
 * Returns:     This function returns 0 on failure (out of memory, or
 *              mitem == NULL); a pointer to the new list if the first
 *              argument was 0; and the first argument otherwise. 
 * Memory:      The memory allocated by this function can be disposed
 *              of using ut_dispose_vlist_outer() to dispose of the list
 *              wrappers, and then the appropriate dispose on each of the list
 *              items in turn. Alternatively the entire list can be dispoosed
 *              of with ut_dispose_vlist().
 * Errors:      This function fails on null second argument (in debug mode)
 *              or memory allocation failure.
 * Notes:       Call this function with the following syntax (for
 *              example):  
 *           (code)
 *              if(!(rval = ut_add_vlist_item_after(inlist, mitem, disposfn))) {
 *                ut_dispose_vlist_outer(inlist);
 *                // dispose of all void *s, if required...
 *              }
 *              else
 *                inlist = tmplist;
 *           (/code)
 *              This maintains a handle to the old list in case it needs to be
 *              disposed of.
 */
extern ut_vlist
CST32EXPORTTYPE CST16EXPORTTYPE
ut_add_vlist_item_after(ut_vlist inlist, void *contents,
   void(*dispose)(void *));



/* Function:    <ut_count_vlist_items>
 * Summary:     Counts the number of items in a ut_vlist.
 * Syntax:      int rval = ut_count_vlist_items(ut_vlist inlist);
 * Description: The ut_count_vlist_items() function counts the number
 *              of items in the list pointed to by inlist, starting
 *              with inlist and counting until it reaches either a null
 *              item or inlist again.
 * Memory:      This function allocates no memory.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
ut_count_vlist_items(ut_vlist inlist);

/* Function:    <ut_get_vlist_item>
 * Summary:     Gets the nth item from a list.
 * Syntax:      ut_vlist rval = ut_get_vlist_item(ut_vlist inlist, int index);
 * Description: The ut_get_vlist_item() function sets rval = inlist and then
 *              calls rval = rval->next index number of times.
 * Memory:      This function allocates no memory.
 */
extern ut_vlist
CST32EXPORTTYPE CST16EXPORTTYPE
ut_get_vlist_item(ut_vlist inlist, int index);


/* Function:    <ut_gopt>
 * Summary:     Parses a command line.
 * Syntax:      switch = ut_gopt(char **argv, char *opts);
 * Description: Given a command-line split into an array of words in argv (i.e. a
 *              standard C argv), switch parses the command-line for valid
 *              switches as defined in opts (example:   qr: allows two
 *              switches, -q and -r; -r would expect a parameter either
 *              immediately following or separated from it by a space).
 * Return:      If it encounters a valid switch, gopt returns the letter of that
 *              switch and sets ut_optarg (see below) to point to the
 *              beginning of the switch's parameter (if applicable).  It can
 *              return three other values:  
 *              . -1: end of switches.  This occurs when gopt reaches the end
 *                     of argv or when it encounters a word not beginning with
 *                     a -, or when it encounters the word `--'.  The exact
 *                     cause can be determined if desired by looking at
 *                     ut_optind and argv[ut_optind] (see below).
 *              . -2: invalid switch.  This occurs when gopt encounters the null
 *                     switch (`-'), a `-:  ', or a switch not listed in opts.
 *                     The exact cause can be determined by examining ut_optopt
 *                     (see below).
 *              . -3: missing parameter.  This occurs when the last switch on
 *                     the command line requires a parameter.
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_gopt(char **argv, char *opts);


/* Data:        <ut_optind>
 * Summary:     Index of word currently being examined in argv
 */
extern int ut_optind;


/* Data:        <ut_optopt>
 * Summary:     Current switch. Useful for error handling on return of -2 
 *              or -3
 */
extern int ut_optopt;

/* Data:        <ut_optarg>
 * Summary:     Pointer to argument to current switch
 */
extern char *ut_optarg;


/* The error control, which uses the ut prefix, defines the number of errors
 * to be stored. If more than this number of errors occur, then only the first
 * UT_NERRS/2 and the last UT_NERRS/2 will be recorded.
 */
#define UT_NERRS (30)

/* Type:        <ut_action>
 * Summary:     Specifies the action to take in response to error (for ut_log).
 */
typedef enum {
  UT_ACONTINUE = -2, /* Report message and continue execution */
  UT_AABORT,         /* Core dump if possible, otherwise EXIT_FAIL */
  UT_AXOK,           /* Exit, successful termination */
  UT_AXFAIL,         /* Exit, general internal error failure */
  UT_AXFILE,         /* Exit, file-related problem */
  UT_AXMEMORY,       /* Exit, memory failure */
  UT_AXTEST,         /* Exit, failed test (or assert) */
  UT_AXARGS,         /* Exit, bad command-line arguments */
  UT_AXABORT,        /* Exit, user abort request */
  UT_AXINPUT,        /* Exit, bad input (user or file) */
  UT_AXPANIC,        /* Exit, something bad happened */
  UT_AXNO = 127      /* Exit, `false' for apps returning true/false answers */
} ut_action;

/* Type:        <ut_emask>
 * Summary:     Defines the mask to use when testing for occurrence of an 
 *              error (for ut_test).
 */

typedef enum {
  UT_MANY,     /* Matches most recent error it comes across */
  UT_MMOD,     /* Just matches module number */
  UT_MERR,     /* Just matches error number */
  UT_MMOD_ERR, /* Matches module number and error number */
  UT_MEXACT    /* Matches module, error, and instance numbers */
} ut_emask;

/* Type:        <ut_sdfn>
 * Summary:     Shutdown function type
 */
typedef void (*ut_sdfn)(ut_action);


/* Data:        <ut_name>
 * Summary:     Tidied version of application name - derived from that
 *              submitted to ut_init()
 */

extern char ut_name[];

/* Data:        <ut_errno>
 * Summary:     Value of errno last time it was nonzero on entry to ut__log()
 */

extern int ut_errno;


/* Function:    <ut_wipe>
 * Summary:     Clears the error queue.
 * Syntax:      ut_wipe(void);
 * Description: The ut_wipe() function clears the current error queue; it should
 *              be called after an error has been detected and dealt with.
 */
extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_wipe(void);

/* Function:    <ut_test>
 * Summary:     Tests if error ernum has occurred.
 * Syntax:      int rval = ut_test(u32 ernum, ut_emask mask);
 * Description: The ut_test() function tests whether error ernum has occurred.
 *              The test is only made on those components of the error number 
 *              indicated by mask. These are none (returns true if any error has 
 *              occurred), module-only, error type only, module and error,
 *              or module-error-instance.
 *
 *              If an unsuitable mask is supplied the return value will
 *              be zero; otherwise, it is 1 if the error has occurred, 0 if not.
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_test(u32 ernum, ut_emask mask);


/* Function:    <ut_log_will_print>
 * Summary:     Returns 1 if ut__log will produce output.
 * Syntax:      int rval = ut_log_will_print(void);
 * Description: The ut_log_will_print() function returns 1 if ut__log
 *              will write to anywhere (i.e. if at least one of the
 *              third and fourth arguments to ut_init() was non-null).
 *              If ut__log will not write the message to anywhere, the
 *              function returns 0.
 * Memory:      This function allocates no memory.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
ut_log_will_print(void);


/* Function:    <ut_log_file>
 * Summary:     Returns the name of the file that ut__log writes to.
 * Syntax:      char * rval = ut_log_file(void);
 * Description: The ut_log_file() function returns the name of the file
 *              ut__log writes to (the third argument to ut_init()), or
 *              0 if no such file was specified.
 * Memory:      This function allocates no memory.
 * Notes:       Do not attempt to free the memory at rval!
 */
extern char
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_log_file(void);

/* Function:    <ut_get_message>
 * Summary:     Gets last error message logged.
 * Syntax:      char rval = ut_get_message();
 * Description: The ut_get_message() function returns a pointer to the last 
 *              error message logged, or 0 if no messages have been logged.
 */
extern char
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_get_message(void);

/* Function:    <ut_get_ernum>
 * Summary:     Gets an error number by index.
 * Syntax:      ernum = ut_get_ernum(int idx);
 * Description: Returns the idx'th recorded error, 0 being the first recorded.
 *              If idx is negative, the (-idx)'th most recent is returned, -1
 *              being the most recent (last recorded).  If more than UT_NERRS
 *              errors have been recorded since the last ut_wipe(), then only
 *              the first and last UT_NERRS/2 of them will be accessible; thus
 *              we recommend that only the first or last be tested for.  A
 *              request for an error outside these bounds will produce a 0 (no
 *              error).
 */

extern u32 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_get_ernum(int n);

/* Function:    <ut_set_shutdown>
 * Summary:     Sets function to call if ut_log shuts down the application.
 * Syntax:      ut_sdfn rval = ut_set_shutdown(ut_sdfn newfn);
 * Description: Instructs ut_log to call a handler in the event of a shutdown.
 *              The handler will be called with the exit code (i.e. general
 *              reason) for the shutdown, and should in turn call next with
 *              this if next is non-null.
 *
 *              In other words, the code for a handler should look like this: 
 *            (code)
 *                static ut_sdfn next = 0;
 *                void handler(ut_action reason)
 *                {
 *                  .. handler code goes here ..
 *                  if(next)
 *                    next(reason);
 *                }
 *            (/code)
 *              ut_set_shutdown() attempts to prevent direct infinite
 *              loops by ignoring repeated requests to place the same handler
 *              on the list, but it cannot prevent this if another handler
 *              has been substituted in the meantime. To protect against
 *              this, the handler should be installed as follows:  
 *            (code)
 *                if(!next)
 *                  next = ut_set_shutdown(handler);
 *            (/code)
 */

extern ut_sdfn 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_set_shutdown(ut_sdfn newfn);

/* Function:    <ut_log_on>
 * Summary:     Turns error logging on.
 * Syntax:      ut_log_on();
 * Description: The ut_log_on() function turns error logging on. The
 *              ut_log_off() function turns error logging off. Error
 *              logging is on by default. These functions manipulate a
 *              global static variable, so use them sparingly!
 * Memory:      These functions allocate no memory.
 * Notes:       These functions are threadsafed with the same critical
 *              section lock as ut__log().
 */

extern void 
ut_log_on(void);


/* Function:    <ut_log_off>
 * Summary:     Turns error logging off.
 * Syntax:      ut_log_off();
 * Description: The ut_log_on() function turns error logging on. The
 *              ut_log_off() function turns error logging off. Error
 *              logging is on by default. These functions manipulate a
 *              global static variable, so use them sparingly!
 * Memory:      These functions allocate no memory.
 * Notes:       These functions are threadsafed with the same critical
 *              section lock as ut__log().
 */

extern void
ut_log_off(void);

/* Function:    <ut__log>
 * Summary:     Logs errors.
 * Syntax:      ut_logN(errno, action, format [, args]);
 * Description: The ut__log() function does three things:
 *              - Sets the specified error number, errno.
 *              - Logs the indicated error message (format, args) to the 
 *                log file and log stream that were specified as the
 *                third and fourth arguments to ut_init().
 *              - Acts as requested by action (abort, continue,
 *                exit with code).
 *
 *              Invoke this function through the macros ut_logN(),
 *              where N is the number of extra arguments to the
 *              printf format string.
 *
 *              If errno is nonzero, it is copied into ut_errno and
 *              then set to zero.
 *
 *              The error message generated consists of:
 *              - A timestamp (optional).
 *              - The error number (optional).
 *              - File and line information (in debug mode).
 *              - The message specified in (format, args).
 *              - A usage message (optional).
 *
 *              If errno is 0, no error number is displayed. In debug
 *              mode, the file and line number from which ut_logN() is
 *              called are also displayed. If the action is UT_AXARGS,
 *              the usage message supplied to ut_init() is appended to
 *              the specified error message. If you specified
 *              CSTFLAGS_TIMESTAMP_ERRORLOG to the ut_setflags()
 *              function, the error message will be preceded by a
 *              timestamp generated by ctime().
 *
 *              If action is UT_ACONTINUE, the application continues to
 *              execute. Otherwise, any UT_AX* action results in a call
 *              to the user-installed shutdown function (if any), except
 *              for UT_AXABORT, which calls abort().
 *              Any errors that abort or exit may use error number 0, as
 *              the error number will never need to be tested for.
 * Notes:       Mke sure that the error message is not longer than 
 *              UT_MESSAGE_SZ (511) characters and that ut_log can open the 
 *              logfile. Otherwise, it exits immediately without calling
 *              shutdown functions. 
 */

extern void
UT_LOG_EXPORTTYPE
ut__log(const char *file, const unsigned line, const u32 ernum,
    const ut_action act, const char *fmt, ...);

#ifdef NDEBUG /* Debug mode is OFF */
  #define ut_log0(n,a,f)                   ut__log(0,0,n,a,f)
  #define ut_log1(n,a,f,x1)                ut__log(0,0,n,a,f,x1)
  #define ut_log2(n,a,f,x1,x2)             ut__log(0,0,n,a,f,x1,x2)
  #define ut_log3(n,a,f,x1,x2,x3)          ut__log(0,0,n,a,f,x1,x2,x3)
  #define ut_log4(n,a,f,x1,x2,x3,x4)       ut__log(0,0,n,a,f,x1,x2,x3,x4)
  #define ut_log5(n,a,f,x1,x2,x3,x4,x5)    ut__log(0,0,n,a,f,x1,x2,x3,x4,x5)
  #define ut_log6(n,a,f,x1,x2,x3,x4,x5,x6) ut__log(0,0,n,a,f,x1,x2,x3,x4,x5,x6)
#else /* NDEBUG/not NDEBUG - Debug mode is ON */
  #define ut_log0(n,a,f)                   ut__log(__FILE__,__LINE__,n,a,f)
  #define ut_log1(n,a,f,x1)                ut__log(__FILE__,__LINE__,n,a,f,x1)
  #define ut_log2(n,a,f,x1,x2)             ut__log(__FILE__,__LINE__,n,a,f,x1,x2)
  #define ut_log3(n,a,f,x1,x2,x3)          ut__log(__FILE__,__LINE__,n,a,f,x1,x2,x3)
  #define ut_log4(n,a,f,x1,x2,x3,x4)       ut__log(__FILE__,__LINE__,n,a,f,x1,x2,x3,x4)
  #define ut_log5(n,a,f,x1,x2,x3,x4,x5)    ut__log(__FILE__,__LINE__,n,a,f,x1,x2,x3,x4,x5)
  #define ut_log6(n,a,f,x1,x2,x3,x4,x5,x6) ut__log(__FILE__,__LINE__,n,a,f,x1,x2,x3,x4,x5,x6)
#endif /* not NDEBUG */

#ifdef _WINDLL

/* Function:    <dllexit>
 * Summary:     Exits a dll.
 * Syntax:      dllexit(ut_action);
 * Description: The exit routine for dlls. We tell the user to CTRL-ALT-DELETE
 *              out of the application and exit.
 */
extern void dllexit(ut_action);
#endif


/* Function:    <ut_i2osp>
 * Summary:     Converts an integer to an octet string.
 * Syntax:      ut_i2osp(integer, octet, length);
 * Description: This function implements the I2OSP Integer-to-Octet-String 
 *              Primitive of IEEE P1363 and other standards. It converts the 
 *              integer (which must be non-negative) to an octet string of the
 *              given length. The given length of bytes must already have
 *              been allocated at octet. 
 * Returns:     This function returns 0 on success, -1 on failure or -2 in 
 *              debug mode if octet is null.           
 * Errors:      Fails if octet is 0 or length is less than necessary to
 *              contain the given integer. 
 * Notes:       See also ut_os2ip().
 */

extern int
ut_i2osp(u32 integer, u8 *octet, size_t length);

/* Function:    <ut_os2ip>
 * Summary:     Converts an octet string to an integer.
 * Syntax:      ut_os2ip (octet, length, &int)
 * Description: This function implements the I2OSP Octet-String-To_Integer 
 *              Primitive of IEEE P1363 and other standards. It converts the
 *              octet string to an integer. 
 * Returns:     The function returns 0 on success, -1 on failure or -2 in debug
 *              mode if octet or integer is 0.
 * Errors:      Fails if the length bytes at octet contain more data than
 *              can be put into an integer. 
 * Notes:       See also ut_i2osp(). The functions mpm_i2osp() and mpm_os2ip()
 *              will be provided in the future to convert integers longer than
 *              a u32.                           
 */

extern int
ut_os2ip(u8 *octet, size_t length, u32 *integer);


/* Function:    <ut_t_b64>
 * Summary:     Converts binary data to base-64 encoded.
 * Syntax:      int rval = ut_t_b64(ut_mblk *inblk, ut_mblk *outblk); 
 * Description: The ut_t_b64() function converts the binary data in
 *              inblk->data to base-64 encoded data at outblk->data. It
 *              allocates memory at outblk->data using ut_ensure_mem(),
 *              so outblk->data must be 0 if no memory is allocated
 *              there prior to the call. The function puts a \r\n
 *              (CR-LF) after every 76 characters of output, and at the
 *              end of the output block.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode, if either argument is 0, or if there is an
 *              internal memory overrun, it aborts.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(outblk->data);
 *           (/code)
 * Notes:       This function was not really designed to process more
 *              than one block at a time. If it is not possible to read
 *              the entire message that you want to encode into memory,
 *              you should read in in multiples of 57 octets (which will
 *              translate into multiples of 76 base-64 encoded octets).
 *
 *              Base-64 encoding is specified in RFC 2047.
 */
extern int ut_t_b64(ut_mblk *inblk, ut_mblk *outblk);


/* Function:    <ut_f_b64>
 * Summary:     Converts base-64 encoded data to binary.
 * Syntax:      int ut_f_b64(ut_mblk *inblk, ut_mblk *outblk);
 * Description: The ut_f_b64() function converts the base-64 encoded
 *              data at inblk->data to binary data at outblk->data. It
 *              allocates memory at outblk->data using ut_ensure_mem(),
 *              so outblk->data must be 0 if no memory is allocated there
 *              prior to the call. The function skips all characters
 *              that don't belong in the base-64 character set and stops
 *              when it comes across an '=' sign or when it runs out of
 *              input data. If the number of bytes of parseable input data is 1
 *              mod 4 the function throws an error; otherwise, it
 *              decodes as much as possible of the trailing input data as if
 *              it was terminated by '='.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode, if either argument is 0 or if there is an
 *              internal memory overrun, it aborts.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(outblk->data);
 *           (/code)
 * Notes:       This function was not really designed to process more
 *              than one block at a time. If it is not possible to read
 *              the entire message that you want to encode into memory,
 *              you should read in in multiples of 78 octets (which will
 *              translate 76-character lines plus the (CR-LF) at the
 *              end, so there will not be any trailing data).
 *
 *              Base-64 encoding is specified in RFC 2045.
 */
extern int ut_f_b64(ut_mblk *in, ut_mblk *out);

/* Type:        <ut_file_type>
 * Summary:     Defines types for file magic number handling.
 */

typedef enum {
  UT_FILE_BAD_MAGIC = -3,
  UT_FILE_EMPTY,
  UT_FILE_UNKNOWN,
  UT_FILE_DB,
  UT_FILE_PSE,
  UT_FILE_XCINFO,
  UT_FILE_PSECURE,
  UT_FILE_WCKEYS,
  UT_FILE_WCCIPHR,
  UT_N_FILETYPES
} ut_file_type;


/* Returns number of significant bytes in a u32 (0 is regarded as having one
 * significant byte). */
#define UT_NSB(x) ((x) & 0xffff0000L ? ((x) & 0xff000000L ? 4 :   3) : ((x) & 0xff00L ? 2 : 1))

/* Function:    <ut_u32_bitlen>
 * Summary:     Returns the number of significant bits in a u32.
 * Syntax:      size_t rval = ut_u32_bitlen(u32 query);
 */

extern size_t
ut_u32_bitlen(u32 query);


/* Function:    <ut_u8_bitlen>
 * Summary:     Returns the number of significant bits in a u8.
 * Syntax:      size_t rval = ut_u8_bitlen(u8 query);
 */

extern size_t
ut_u8_bitlen(u8 query);

/* Function:    <ut_choose>
 * Summary:     Tries to match an abbreviation against a list of names.            
 * Syntax:      match = ut_choose(abbreviation, clist);
 * Description: This function tries to match abbreviation against one of the 
 *              structures pointed to by list. These structures are arbitrary 
 *              except in that their first element must be a const char *, 
 *              their name.
 *
 *              list is an array of pointers to such structures whose last
 *              element is null.  Matching is based on the idea of each name
 *              being a `-' separated series of words, and the abbreviation is
 *              a `-' separated list of case-insensitive abbreviations of these
 *              words. MDC2-DES-single-width could be abbreviated as any of the
 *              following, for example:  
 *              . mdc2-des-single-width          
 *              . m-d-s-w
 *              . mdc2                           
 *              . mdc-d-s
 *              This function is intended for matching user-typed names against
 *              the canonical names in bsapis[], prngs[], or hashes[].  If
 *              abbreviation is null but list contains only one item, then a
 *              match is made against that item.
 * Errors:      Aborts on bad parameters (null list).
 * Notes:       ut_choose_default() returns the first item in the list.
 */

#ifndef _CSTFORWIN16DLL
  extern const void
CST32EXPORTTYPE * CST16EXPORTTYPE
  ut_choose(char *abbreviation, const void *clist);

/* Function:    <ut_choose_default>
 * Summary:     Returns the first item in a list.
 * Syntax:      ut_choose_default(clist);
 */

  extern const void
CST32EXPORTTYPE * CST16EXPORTTYPE
  ut_choose_default(const void *clist);

  #define BSAPIS  (const void *) bsapis
  #define HASHES  (const void *) hashes
  #define PADS    (const void *) pads
  #define PRNGS   (const void *) prngs
#else
  extern const void
CST32EXPORTTYPE * CST16EXPORTTYPE
  ut_choose(char *abbreviation, u32 list_type_flag);

  extern const void
CST32EXPORTTYPE * CST16EXPORTTYPE
  ut_choose_default(u32 list_type_flag);

  #define UT_CHOOSE_FLAG_BASE  0x01000000   /* arbitrary base */
  #define BSAPIS               (UT_CHOOSE_FLAG_BASE + 1)
  #define HASHES               (UT_CHOOSE_FLAG_BASE + 2)
  #define PRNGS                (UT_CHOOSE_FLAG_BASE + 3)
  #define PADS                 (UT_CHOOSE_FLAG_BASE + 4)
#endif    /* CST for 16-bit Win DLL / Not CST for 16-bit Win DLL */

/* Function:    <ut_u32sqrt>
 * Summary:     Returns largest integer less than the square root.
 * Syntax:      unsigned root = ut_u32sqrt(number);
 * Description: Returns the largest unsigned less than or equal to the square
 *              root of its argument.
 * Errors:      None.
 */
extern unsigned 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_u32sqrt(u32 number);


/* Function:    <ut_get_name>
 * Summary:     Gets application name.
 * Syntax:      char *name = ut_get_name()
 * Description: Returns the name of the application as sent in to ut_init().
 * Errors:      None.
 */

extern char
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_get_name(void);


/* Function:    <ut_set_name>
 * Summary:     Sets application name.
 * Syntax:      ut_set_name();
 * Description: The ut_set_name() function sets the name of the
 *              application, overriding the name supplied to ut_init().
 *              This changes the name given at the start of log messages
 *              and the <name>.unf file that records any unfreed memory
 *              when ut_shutdown() is called; it does not change the
 *              error log filename or the log output stream.
 * Memory:      This function allocates no memory.
 * Notes:       This function is mainly intended for use when forking
 *              processes.
 */
extern void
CST32EXPORTTYPE CST16EXPORTTYPE
ut_set_name(char *lidx);

/* Flags for use in ut_check_password() */

#define UT_CPWD_LC     (0x01UL)   /* lower-case */
#define UT_CPWD_UC     (0x02UL)   /* upper-case */
#define UT_CPWD_NUM    (0x04UL)   /* numeric */
#define UT_CPWD_OTH    (0x08UL)   /* other character */

/* Function:    <ut_check_password_ascii>
 * Summary:     Performs rudimentary password security check.
 * Syntax:      int rval = ut_check_password_ascii(char *pwd, size_t minlen,
 *                u32 flags)
 * Description: The ut_check_password_ascii() function checks that pwd passes
 *              a number of basic security checks. The number of
 *              characters in pwd must be at least minlen. If minlen is
 *              0, it defaults to 8 internally. flags is a set
 *              of other constraints XORed together, as follows:
 *              - if (flags & UT_CPWD_LC), the password must contain at
 *                least one lowercase (a-z) character.
 *              - if (flags & UT_CPWD_UC), the password must contain at
 *                least one uppercase (A-Z) character.
 *              - if (flags & UT_CPWD_NUM), the password must contain at
 *                least one numeric (0-9) character.
 *              - if (flags & UT_CPWD_OTH), the password must contain at
 *                least one character that is neither a letter nor a
 *                number.
 *              If flags is 0, it is set internally to be UT_CPWD_LC |
 *              UT_CPWD_UC | UT_CPWD_NUM | UT_CPWD_OTH (the strongest
 *              possible check).
 * Returns:     This function returns 0 on success; 1 if the password is too 
 *              short; 2 if it fails one of the other checks; -2 in debug mode 
 *              if pwd is 0 (NULL). 
 * Notes:       Calling with (pwd, 0, 0) gives sensible defaults. Any flags
 *              other than the four defined above are ignored.
 *              
 *              ut_check_password() is defined as a macro. If _UNICODE is
 *              defined it wraps ut_check_password_unicode(). If _UNICODE
 *              is not defined it wraps ut_check_password_ascii().
 */

extern int
ut_check_password_ascii(const char *pwd, size_t minlen, u32 flags);

/* Function:    <ut_check_password_unicode>
 * Summary:     Performs rudimentary password security check.
 * Syntax:      int rval = ut_check_password_unicode(wchar_t *pwd,
 *                size_t minlen, u32 flags)
 * Description: The ut_check_password_unicode() function checks that pwd
 *              passes a number of basic security checks. The function first
 *              check to see if the password is actually ASCII; if it is ASCII,
 *              the function applies the tests based on the length and
 *              the flags, while if it is not ASCII, the function
 *              applies the tests based on the length alone. The number of
 *              characters in pwd must be at least minlen. If minlen is
 *              0, it defaults to 8 internally. flags is a set
 *              of other constraints XORed together, as follows:
 *              - if (flags & UT_CPWD_LC), the password must contain at
 *                least one lowercase (a-z) character.
 *              - if (flags & UT_CPWD_UC), the password must contain at
 *                least one uppercase (A-Z) character.
 *              - if (flags & UT_CPWD_NUM), the password must contain at
 *                least one numeric (0-9) character.
 *              - if (flags & UT_CPWD_OTH), the password must contain at
 *                least one character that is neither a letter nor a
 *                number.
 *              If flags is 0, it is set internally to be UT_CPWD_LC |
 *              UT_CPWD_UC | UT_CPWD_NUM | UT_CPWD_OTH (the strongest
 *              possible check).
 * Returns:     The function returns 0 on success; 1 if the password is too 
 *              short; 2 if it fails one of the other checks; -2 in debug mode 
 *              if pwd is 0 (NULL); -1 on internal failure. 
 * Notes:       Calling with (pwd, 0, 0) gives sensible defaults. Any flags 
 *              other than the four defined above are ignored.
 *
 *              ut_check_password() is defined as a macro. If _UNICODE is
 *              defined it wraps ut_check_password_unicode(). If _UNICODE
 *              is not defined it wraps ut_check_password_ascii().
 */
 
extern int
ut_check_password_unicode(const wchar_t *pwd, size_t minlen, u32 flags);

/* Function:    <ut_check_password>
 * Summary:     Performs rudimentary password security check.
 * Description: ut_check_password() is defined as a macro. If _UNICODE is
 *              defined it wraps ut_check_password_unicode(). If _UNICODE
 *              is not defined it wraps ut_check_password_ascii().
 * Notes:       See ut_check_password_unicode() and ut_check_password_ascii().
 */

#ifndef _UNICODE
#define ut_check_password(p, m, f) ut_check_password_ascii(p, m, f)
#else
#define ut_check_password(p, m, f) ut_check_password_unicode(p, m, f)
#endif


/* Function:    <ut_strdup_ascii>
 * Summary:     Duplicates a string.
 * Syntax:      char *result = ut_strdup_ascii(char *in);
 * Description: The ut_strdup_ascii() function duplicates the string passed
 *              to it at in. It behaves exactly like strdup() but uses
 *              ut_new_mem for allocation.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(result);
 *           (/code)
 * Notes:       ut_strdup() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_strdup_unicode() and takes and
 *              returns a wchar_t *. If _UNICODE is not defined, it
 *              wraps ut_strdup_ascii() and takes and returns a char *.
 */


extern char *ut_strdup_ascii(char *in);


/* Function:    <ut_strdup_unicode>
 * Summary:     Duplicates a string.
 * Syntax:      wchar_t *result = ut_strdup_unicode(wchar_t *in);
 * Description: The ut_strdup_unicode() function duplicates the string passed
 *              to it at in. It behaves exactly like strdup() but uses
 *              ut_new_mem for allocation.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(result);
 *           (/code)
 * Notes:       ut_strdup() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_strdup_unicode() and takes and
 *              returns a wchar_t *. If _UNICODE is not defined, it
 *              wraps ut_strdup_ascii() and takes and returns a char *.
 */

extern wchar_t *ut_strdup_unicode(wchar_t *in);

/* Function:    <ut_strdup>
 * Summary:     Duplicates a string.
 * Description: ut_strdup() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_strdup_unicode() and takes and
 *              returns a wchar_t *. If _UNICODE is not defined, it
 *              wraps ut_strdup_ascii() and takes and returns a char *.
 * Notes:       See ut_strdup_unicode() and ut_strdup_ascii().
 */

#ifndef _UNICODE
#define ut_strdup(i) ut_strdup_ascii(i)
#else
#define ut_strdup(i) ut_strdup_unicode(i)
#endif /* ndef/def _UNICODE */



/* Function:    <ut_bin2hex_ascii>
 * Summary:     Converts a binary array to a printable hex string.
 * Syntax:      char * rval = ut_bin2hex_ascii(ut_mblk *mem);
 * Description: The ut_bin2hex_ascii() function converts the data at
 *              mem->data to a printable hex representation of
 *              that data and returns a pointer to the string created.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(rval);
 *           (/code)
 * Notes:       ut_bin2hex() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_bin2hex_unicode() and returns a
 *              wchar_t *. If _UNICODE is not defined, it wraps
 *              ut_bin2hex_ascii() and returns a char *.
 */

extern char *
ut_bin2hex_ascii(ut_mblk *mem);

/* Function:    <ut_bin2hex_unicode>
 * Summary:     Converts a binary array to a printable hex string.
 * Syntax:      wchar_t * rval = ut_bin2hex_unicode(ut_mblk *mem);
 * Description: The ut_bin2hex_unicode() function converts the data at
 *              mem->data to a printable hex representation of
 *              that data and returns a pointer to the string created.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(rval);
 *           (/code)
 * Notes:       ut_bin2hex() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_bin2hex_unicode() and returns a
 *              wchar_t *. If _UNICODE is not defined, it wraps
 *              ut_bin2hex_ascii() and returns a char *.
 */

extern wchar_t *
ut_bin2hex_unicode(ut_mblk *mem);

/* Function:    <ut_bin2hex>
 * Summary:     Converts a binary array to a printable hex string.
 * Description: ut_bin2hex() is defined as a macro. If _UNICODE is
 *              defined, it wraps ut_bin2hex_unicode() and returns a
 *              wchar_t *. If _UNICODE is not defined, it wraps
 *              ut_bin2hex_ascii() and returns a char *.
 * Notes:       See ut_bin2hex_unicode() and ut_bin2hex_ascii().
 */

#ifdef _UNICODE
#define ut_bin2hex(m) ut_bin2hex_unicode(m)
#else
#define ut_bin2hex(m) ut_bin2hex_ascii(m)
#endif  /* def _UNICODE */


/* Function:    <ut_string2wstring>
 * Summary:     Converts a zero-terminated ASCII string to a wide character
 *              string.
 * Syntax:      int rval = ut_string2wstring(char *str, wchar_t **dst);
 * Description: The ut_string2wstring() function converts the zero-terminated
 *              ASCII character string in src to a zero-terminated
 *              Unicode string in dst.
 *
 *              On success, memory is allocated at *dst and the function
 *              returns 0; on failure, no memory is allocated and the
 *              function returns -1. In debug mode, the function returns
 *              -2 if str or dst are NULL.
 *
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              wchar_t *dst;
 *              ...
 *              ut_string2wstring(str, &dst);
 *              ...
 *              ut_dispose_mem (dst);
 *           (/code)
 */
extern int
ut_string2wstring(const char *str, wchar_t **dst);

/* Function:    <ut_ascii2bmp>
 * Summary:     Converts an ASCII string to a BMP string.
 * Syntax:      int rval = ut_ascii2bmp(ut_mblk *asciiblk, ut_mblk *bmpblk);
 * Description: The ut_ascii2bmp() function converts the ASCII characters 
 *              in asciiblk->data to a null- terminated big-endian
 *              Unicode string (an ASN.1 BMP STRING) in bmpblk->data, by
 *              putting a null byte in front of each ASCII character.
 *              The function converts asciiblk->used characters, and then
 *              appends a null-terminating double byte. It assumes the
 *              data passed to it is legitimate ASCII data and does not
 *              parse it in any way.
 *
 *              On success, bmpblk->used is set to the number of bytes
 *              occupied by the BMP characters, excluding the two
 *              trailing NULL bytes. bmpblk->size is the amount of memory
 *              allocated, including the memory for the trailing NULL
 *              bytes. This is a change from the behavior in CST v7.2
 *              and earlier versions, where bmpblk->used included the length
 *              of the NULL bytes.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode it returns -2 if given invalid parameters.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(bmpblk->data);
 *           (/code)
 * Notes:       This functionality changed in CST v7.3. Previous versions 
 *              converted asciiblk->data up to the first NULL byte, rather than
 *              up to asciiblk->used, and set bmpblk->used to include the two
 *              trailing NULL bytes.
 */
extern
int 
ut_ascii2bmp(ut_mblk *asciiblk, ut_mblk *bmpblk);

/* Function:    <ut_wstring2bmp>
 * Summary:     Converts a zero-terminated wide character string to a
 *              BMP string.
 * Syntax:      int rval = ut_wstring2bmp(wchar_t *src, ut_mblk *bmpblk);
 * Description: The ut_wstring2bmp() function converts the zero-terminated
 *              wide character string in src to a zero-terminated big-endian
 *              16-bit Unicode string (an ASN.1 BMP STRING) in bmpblk->data.
 *              The data is simply copied, flipped if necessary and narrowed.
 *              No other processing is performed.
 *
 *              On success, bmpblk->used is set to the number of bytes
 *              occupied by the BMP characters, excluding the two
 *              trailing NULL bytes. bmpblk->size is the amount of memory
 *              allocated, including the memory for the trailing NULL
 *              bytes.
 * Returns:     This function returns 0 on success or -1 on failure, including
 *              if the source string contains characters that cannot be
 *              represented in 16-bit Unicode (i.e., >65535). In
 *              debug mode it returns -2 if given invalid parameters.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(bmpblk->data);
 *           (/code)
 */
extern
int 
ut_wstring2bmp(const wchar_t *src, ut_mblk *bmpblk);


/* Function:    <ut_wstrlen>
 * Summary:     Defines a portable strlen for Unicode character strings.
 * Syntax:      size_t rval = ut_wstrlen(wchar_t *wstr);
 * Description: The ut_wstrlen() function counts the number of wchar_t
 *              characters in wstr, excluding the terminal NULL
 *              character.
 * Memory:      This function allocates no memory.
 * Notes:       This function is actually a macro that maps to wcslen()
 *              under Windows and to ut_wstrlen_impl() on non-Windows
 *              platforms.
 */

#ifdef __DOS__
#define ut_wstrlen(x)    wcslen(x)
#else
#define ut_wstrlen(x)    ut_wstrlen_impl((const wchar_t *)x)
#endif /* def/ndef DOS */

/* Function:    <ut_wstrlen_impl>
 * Summary:     Implements a strlen for Unicode character strings.
 * Syntax:      size_t rval = ut_wstrlen_impl(wchar_t *wstr);
 * Description: The ut_wstrlen_impl() function counts the number of wchar_t
 *              characters in wstr, excluding the terminal NULL
 *              character.
 * Memory:      This function allocates no memory.
 */

extern
size_t
ut_wstrlen_impl(const wchar_t *wstr);


/* Function:    <ut_wstring2string>
 * Summary:     Converts a null-terminated wide character string to an ASCII 
 *              string.
 * Syntax:      int rval = ut_wstring2string(const wchar_t *wstr, char **str);
 * Description: The ut_wstring2string() function takes a null-terminated
 *              wide character string in wstr, and checks to see if all
 *              the characters in it are ASCII characters. If they are,
 *              it writes the corresponding ASCII string to the char *
 *              pointed at by str.
 * Returns:     This function returns 0 on success, 1 if the string was
 *              not ASCII, -1 if there was a failure allocating memory
 *              at *str, and -2 in debug mode if wstr or str is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              char *aStr;
 *              ...
 *              ut_wstring2string(wstr, &aStr);
 *              ...
 *              ut_dispose_mem(aStr);
 *           (/code)
 */
extern
int
ut_wstring2string(const wchar_t *wstr, char **str);


/* Function:    <ut_wstring2string_len>
 * Summary:     Converts a wide character string of known length to 
 *              an ASCII string.
 * Syntax:      int rval = ut_wstring2string_len(const wchar_t *wstr,
 *                 size_t len, char **str);
 * Description: The ut_wstring2string_len() function takes a wide character
 *              string at wstr that contains len wide characters, and
 *              checks to see if all the characters in it are ASCII
 *              characters. If they are, it writes the corresponding
 *              ASCII string to the char * pointed at by str.
 *
 *              This function returns 0 on success, 1 if the string was
 *              not ASCII, -1 if there was a failure allocating memory
 *              at *str, and -2 in debug mode if wstr or str is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              char *aStr;
 *              ...
 *              ut_wstring2string(wstr, &aStr);
 *              ...
 *              ut_dispose_mem(aStr);
 *           (/code)
 */
extern
int
ut_wstring2string_len(const wchar_t *wstr, size_t len, char **str);


/* Function:    <ut_tryReduceUnicodeByteArrayToAscii>
 * Summary:     Tries to convert a Unicode byte array to ASCII.
 * Syntax:      size_t rval = ut_tryReduceUnicodeByteArrayToAscii
 *                (wchar_t *wpphr, size_t len, u8 **aOut);
 * Description: The ut_tryReduceUnicodeByteArrayToAscii() function,
 *              given a wchar_t array wpphr of length (IN BYTES) len,
 *              first checks to see if it's Unicode (ie if len is 0
 *              mod sizeof(wchar_t)). If this is the case, it attempts
 *              to convert it to ASCII using ut_wstring2string_len().
 *              
 * Returns:     If the array is non-Unicode, the function returns 0 and
 *              *aOut is set to 0.
 *
 *              If the array is Unicode, but not ASCII, the function
 *              returns len and *aOut is set to wpphr.
 *
 *              If the array is ASCII, the function creates a char *
 *              of the length of the ASCII string (len / sizeof (wchar_t))
 *              and writes the converted ASCII char * to it. It returns the
 *              length of the created array.
 *
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              u8 *aOut = 0;  // important to initialize to 0
 *              ...
 *              ut_tryReduceUnicodeByteArrayToAscii(wpphr, len, &aOut);
 *              ...
 *              if (aOut && aOut != wpphr)
 *                ut_dispose_mem(aOut);
 *           (/code)
 * Notes:       The argument len is the length IN BYTES of
 *              wpphr, not the length in wchar_ts.
 */
extern
size_t
ut_tryReduceUnicodeByteArrayToAscii(wchar_t *wpphr, size_t len, u8 **aOut);


/* Function:    <ut_wfopen>
 * Summary:     Opens a file whose name is given by a wide character string.
 * Syntax:      FILE * rval = ut_wfopen(const wchar_t *fname,
 *                const wchar_t *mode);
 * Description: The ut_wfopen() function opens the file whose name is
 *              given in fname, using the mode given in mode.
 *
 *              On Windows systems, this call simply wraps _wfopen().
 *
 *              On Unix systems, this call attempts to convert fname and
 *              mode into ASCII strings. If this is possible, it opens
 *              the file specified. If not, it returns NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              fclose (rval);
 *           (/code)
 */
extern
FILE *
ut_wfopen(const wchar_t *fname, const wchar_t *mode);


/* type for ut_wstat */

#ifdef __DOS__
typedef struct _stat ut_wstat_s;
#else
typedef struct stat ut_wstat_s;
#endif

/* Function:    <ut_wstat>
 * Summary:     Stat a file whose name is given by a wide character string.
 * Syntax:      int rval = ut_wstat(wchar_t *fname, ut_wstat_s *st);
 * Description: The ut_wstat() function stats the file whose name is
 *              given in fname, storing the stat information in st.
 *
 *              On Windows systems, this call simply wraps _wstat().
 *
 *              On Unix systems, this call attempts to convert fname
 *              into an ASCII string. If this is possible, it stats
 *              the file specified. If not, it returns -1 (which it also
 *              does if the inner call to stat() fails).
 * Memory:      This function allocates no memory.
 */
extern
int
ut_wstat(wchar_t *fname, ut_wstat_s *st);


/* Function:    <ut_bmp2ascii>
 * Summary:     Converts a BMP string to an ASCII string.
 * Syntax:      int rval = ut_bmp2ascii(ut_mblk *bmpblk, ut_mblk *asciiblk);
 * Description: The ut_bmp2ascii() function converts the BMP string
 *              (big-endian Unicode characters) in bmpblk->data to a null-
 *              terminated ASCII string in asciiblk->data if possible, by
 *              stripping the leading zero byte off each character. It fails
 *              if this conversion is not possible.
 *
 *              On success, asciiblk->used is set to the number of bytes
 *              occupied by the ASCII characters, excluding the
 *              trailing NULL byte. In other words, if there were no
 *              double NULL bytes in bmpblk->data, asciiblk->used will
 *              be strlen(asciiblk->data). asciiblk->size is the amount
 *              of memory allocated, including the memory for the
 *              trailing NULL byte -- in other words,
 *              strlen(asciiblk->data) + 1. This is a change from the
 *              behavior in CST v7.2 and earlier versions, where 
 *              asciiblk->used included the length of the NULL byte.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode it returns -2 if given invalid parameters.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(asciiblk->data);
 *           (/code)
 * Notes:       This functionality changed in CST v7.3. Previous versions
 *              converted bmpblk->data up to the first NULL double byte, rather
 *              than up to bmpblk->used, and set asciiblk->used to include the
 *              trailing NULL byte.
 */
extern
int 
ut_bmp2ascii(ut_mblk *bmpblk, ut_mblk *asciiblk);


/* Function:    <ut_unicode_normalise_len>
 * Summary:     Converts a Unicode string to compatibility normalized form.
 * Syntax:      u16 * rval = ut_unicode_normalise_len(u16 *in, size_t len);
 * Description: The ut_unicode_normalise_len() function converts a
 *              Unicode string to compatibility normalized form. This
 *              ensures that different possible representations of the
 *              same character are all mapped to the same, known
 *              representation. The function takes as input a u16 *
 *              pointing to len Unicode characters.
 * Returns:     The function returns a u16 * pointing to the
 *              (null-terminated) normalized Unicode string, or 0 on
 *              error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(rval);
 *           (/code)
 */
extern
u16 *
ut_unicode_normalise_len(u16 *in, size_t len);


/* Function:    <ut_unicode_normalise_nolen>
 * Summary:     Converts a Unicode string to compatibility normalized form.
 * Syntax:      u16 * rval = ut_unicode_normalise_nolen(u16 *in);
 * Description: The ut_unicode_normalise_nolen() function converts a
 *              Unicode string to compatibility normalized form. This
 *              ensures that different possible representations of the
 *              same character are all mapped to the same, known
 *              representation. The function takes as input a u16 *, in,
 *              pointing to Unicode characters. The string at in must be
 *              NULL-terminated; the function then uses ut_bmp_strlen()
 *              to obtain the length.
 * Returns:     The function returns a u16 * pointing to the
 *              (null-terminated) normalized Unicode string or 0 on
 *              error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(rval);
 *           (/code)
 */
extern
u16 *
ut_unicode_normalise_nolen(u16 *in);

/* Function:    <ut_bmp_strlen>
 * Summary:     Defines a portable strlen for 16-bit BMP character strings.
 * Syntax:      size_t rval = ut_bmp_strlen(u8 *bmpstring);
 * Description: The ut_bmp_strlen() function counts the number of 16-bit
 *              characters in bmpstring, excluding the terminal NULL
 *              character.
 * Memory:      This function allocates no memory.
 */

extern
size_t
ut_bmp_strlen(const u8 *bmpstring);

/* Type:        <ut_magic>
 * Summary:     Handles the magic number stuff.
 */

typedef struct {
  ut_file_type  type;
  unsigned char version;
  unsigned char revision;
} ut_magic;


/* Function:    <ut_stream_magic>
 * Summary:     Handles magic on an already open stream.
 * Syntax:      ut_stream_magic(FILE *stream, const char *mode, ut_magic *bm);
 */

void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_stream_magic(FILE *stream, const char *mode, ut_magic *bm);


/* Function:    <ut_string_magic>
 * Summary:     Handles magic on a string.
 * Syntax:      ut_string_magic(char *string, const char *mode, ut_magic *bm);
 */

void 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_string_magic(char *string, const char *mode, ut_magic *bm);


/* Function:    <ut_open_magic_ascii>
 * Summary:     Gives a non-null ut_magic pointer and handles the magic stuff.
 *              Otherwise just acts like fopen.
 * Syntax:      ut_open_magic_ascii(const char *filename, const char *mode, 
 *                ut_magic *bm);
 * Description: The ut_open_magic_ascii() function looks at the flags it gets 
 *              to decide the mode of access and how to handle the magic number 
 *              information if there is some.  If the mode starts with a `w' then 
 *              then the file has been discarded and we can write the magic safely.  
 *              If the mode starts  with `r', then it's read and checked for validity.  
 *              If the mode starts with something else (e.g. `a'), no action is taken.
 * Notes:       ut_open_magic() is defined as a macro. If _UNICODE is defined
 *              it wraps ut_open_magic_unicode(). If _UNICODE is not defined
 *              it wraps ut_open_magic_ascii().
 */


FILE
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_open_magic_ascii(const char *filename, const char *mode, ut_magic *bm);

/* Function:    <ut_open_magic_unicode>
 * Summary:     Gives a non-null ut_magic pointer and handles the magic stuff.
 *              Otherwise just acts like fopen.
 * Syntax:      ut_open_magic_unicode(const char *filename, const char *mode, 
 *                ut_magic *bm);
 * Description: The ut_open_magic_unicode() function looks at the flags it gets 
 *              to decide the mode of access and how to handle the magic number 
 *              information if there is some.  If the mode starts with a `w' then 
 *              then the file has been discarded and we can write the magic safely.  
 *              If the mode starts  with `r', then it's read and checked for validity.  
 *              If the mode starts with something else (e.g. `a'), no action is taken.
 * Notes:       ut_open_magic() is defined as a macro. If _UNICODE is defined
 *              it wraps ut_open_magic_unicode(). If _UNICODE is not defined
 *              it wraps ut_open_magic_ascii().
 */

FILE
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_open_magic_unicode(const wchar_t *filename, const wchar_t *mode,
   ut_magic *bm);

/* Function:    <ut_open_magic>
 * Summary:     Gives a non-null ut_magic pointer and handles the magic stuff.
 *              Otherwise just acts like fopen.
 * Description: ut_open_magic() is defined as a macro. If _UNICODE is defined
 *              it wraps ut_open_magic_unicode(). If _UNICODE is not defined
 *              it wraps ut_open_magic_ascii().
 * Notes:       See ut_open_magic_unicode() and ut_open_magic_ascii().
 */

#ifndef _UNICODE
#define ut_open_magic(fn,md,bm) ut_open_magic_ascii(fn,md,bm)
#else
#define ut_open_magic(fn,md,bm) ut_open_magic_unicode(fn,md,bm)
#endif


/* Function:    <ut_provides_RSA>
 * Summary:     Returns 1 if this version of the CST can perform RSA
 *              encryption/ signing, 0 otherwise.
 * Syntax:      int rval = ut_provides_rsa();
 */

extern int
ut_provides_RSA(void);


/* Function:    <ut_load_RSAprovider>
 * Summary:     Loads a shared library/DLL to provide RSA in software.
 * Syntax:      int rval = ut_load_RSAprovider (const char *libname);
 * Description: The ut_load_RSAprovider() function loads a shared library
 *              or dynamic link library (DLL) to provide RSA functions.
 *              The argument dllname is the name of the library to be
 *              loaded. The function can only load shared libraries/DLLs
 *              that have been explicitly catered for within CST;
 *              currently, the only library supported is the AT&T
 *              Cryptographic Development Kit or CDK (denoted by libname
 *              = "cdk32mt" or libname = "cdk32md"), but we hope to add
 *              to this list shortly.
 * 
 *              A library that's been loaded with ut_load_RSAprovider() can
 *              be unloaded with ut_unload_RSAprovider(). Alternatively, the
 *              currently loaded library is automatically unloaded on the
 *              terminating call to ut_shutdown(). It is also unloaded on
 *              a call to ut_load_RSAprovider.
 *
 *              Currently, ut_load_RSAprovider() is automatically called by
 *              ut_init() and will attempt to load the AT&T CDK, so there is
 *              no need for you to call this function to be called explicitly. 
 *              It is provided for forward extensibility.
 * Returns:     This function returns 0 on success or -1 on failure.
 */

extern int
ut_load_RSAprovider(const char *dllname);

/* Function:    <ut_unload_RSAprovider>
 * Summary:     Unloads a shared library/DLL loaded with ut_load_RSAprovider().
 * Syntax:      ut_unload_RSAprovider ();
 */

extern void
ut_unload_RSAprovider(void);


/* Type:        <ut_RSAprovider>
 * Summary:     Lists possible RSA providers.
 */

typedef enum {
  RSA_PROVIDER_CST = -1,
  RSA_PROVIDER_NONE = 0,
  RSA_PROVIDER_CDK,
  RSA_PROVDER_MAX
} ut_RSAprovider;

/* Function:    <ut_get_RSAprovider>
 * Summary:     Finds out which RSA provider is loaded.
 * Syntax:      ut_RSAprovider rval = ut_getRSAprovider();
 */

extern
ut_RSAprovider
ut_get_RSAprovider(void);


/* Type:        <ut_threadops>
 * Summary:     The ut_threadops_s structure is defined in thrdcst.h.
 * 
 */

typedef struct ut_threadops_s ut_threadops;


/* Data:        <ut_threadops_Posix>
 * Summary:     Null thread operations; provide singleton implementation for
 *              singlethreaded environments
 */

extern const ut_threadops *ut_threadops_Null;

#ifndef CST_NO_THREADS
#  ifndef WIN32
/* Data:        <ut_threadops_Posix>
 * Summary:     POSIX-based thread operations suitable for most 
 *              UNIX environments
 */
extern const ut_threadops *ut_threadops_Posix;
#  else /* !WIN32 */
/* Data:        <ut_threadops_Win32>
 * Summary:     WIN32-based thread operations for Windows
 */
extern const ut_threadops *ut_threadops_Win32;
#  endif /* /!WIN32 */
#endif /* CST_NO_THREADS */

/* Function:    <ut_threadops_set>
 * Summary:     Sets the thread operations function block to be used by the
 *              CST for threadsafety.
 * Syntax:      err = ut_threadops_set(threadops);
 * Description: This function sets the thread operations function block to be 
 *              used by the CST for threadsafety. Valid predefined blocks are
 *              defined above. In a multithreaded application this must be 
 *              called before ut_init_nodefaults(). The ut_init_mt() function
 *              sets the appropriate POSIX or Win32 threading operations
 *              automatically. Custom threading operations can be defined,
 *              as defined in include/thrdcst.h.
 * Returns:     This function returns 0 on success or -1 on error. For example,
 *              an error occurs if thread operations are already set.
 */

extern int
ut_threadops_set
(const ut_threadops *ops);


/* Function:    <ut_threadops_get>
 * Summary:     Returns the thread operations function block in use by CST
 *              for threadsafety.
 * Syntax:      threadops = ut_threadops_get();
 * Returns:     This function returns the thread operations function block on
 *              success or NULL if none is set.
 */

extern const ut_threadops *
ut_threadops_get
(void);


/* Function:    <ut_thread_exiting>
 * Summary:     Notifies CST that thread is about to exit.
 * Syntax:      ut_thread_exiting();
 * Description: In certain situations CST requires notification whenever
 *              a thread exits in order to free up thread-local storage
 *              resources. In these situations, this function should be called
 *              by the thread that is about to exit. Failure to do so will
 *              result in resource leakage. In environments with a few
 *              long-running threads, this may not be a problem; in environments
 *              with many short-lived threads, it will be a problem.
 *
 *              The only situation that currently demands this function is when
 *              thread-local heaps are enabled (CST_FLAGS_THREAD_LOCAL_HEAP)
 *              under Win32: Win32 does not support the automatic cleanup
 *              mechanisms provided by environments such as POSIX.
 *              It is permissible to call this function in other environments.
 */

extern void
ut_thread_exiting
(void);


/* Function:    <ut_init_mt>
 * Summary:     Initializes CST library for a multithreaded application.
 * Syntax:      void ut_init_mt(const char *appname, const char *usage,
 *                const char *logfile, FILE *logstream);
 * Description: The ut_init_mt() function initializes the current application's 
 *              CST engine for use in a multithreaded environment. This pulls
 *              in OS support for mutices and thread-local storage, which will
 *              require your application to link against the appropriate system
 *              libraries (e.g. -lposix).
 *
 *              See ut_init().
 */
extern void    
CST32EXPORTTYPE CST16EXPORTTYPE
ut_init_mt(char *appname, const char *usage, char *file, FILE *stream);

/* Function:    <ut_init_nodefaults>
 * Summary:     Initializes CST library with no default system model.
 * Syntax:      void ut_init_nodefaults(const char *appname, const char *usage,
 *                const char *logfile, FILE *logstream);
 * Description: The ut_init_nodefaults() function initializes the current
 *              application's CST engine after all system-model settings
 *              have been manually assigned.
 *
 *              Currently relevant model settings are just the thread operations
 *              function block (see ut_threadops_set()).
 *
 *              Use this when you want to configure your own system model
 *              (for example, when those supplied by CST are inappropriate) and
 *              do not want to draw in the library dependencies introduced by
 *              ut_init() and ut_init_mt().
 *
 *              See ut_init().
 */
extern void    
CST32EXPORTTYPE CST16EXPORTTYPE
ut_init_nodefaults(char *appname, const char *usage, char *file, FILE *stream);



#ifdef NDEBUG
# define ut_assert(expr) ((void) 0)
#else /* ?NDEBUG */
# define ut_assert(expr) if (!(expr)) ut_log1 (0UL, UT_AABORT, "Assertion failed: \"%s\" is not true.", #expr)
#endif /* !NDEBUG */

/* Type:        <ut_asn1type>
 * Summary:     Deprecated. Use the ASN.1 identifiers instead.
 */

typedef enum {
  UT_ASN1_CONTEXT = -2, /* Tag is context-specific */
  UT_ASN1_UNKNOWN = -1, /* Unrecognized (error return value) */
  UT_ASN1_BOOL,         /* boolean type. Use 0xff for true */
  UT_ASN1_INTEGER,      /* Integer - could be an s32, an mpm_arc, .. */
  UT_ASN1_BITSTRING,    /* Bit string - usually translates into mblk */
  UT_ASN1_OCTETSTRING,  /* Octet string - again, usually an mblk */
  UT_ASN1_NULL,         /* A null (usually means no parameters) */
  UT_ASN1_OBJECTID,     /* An object ID, complicated */
  UT_ANS1_REAL,         /* The real type. Encoding for this is complicated */
  UT_ASN1_ENUMERATED,   /* The enumerated type */
  UT_ASN1_NUMERIC,      /* As the name implies, a numeric string */
  UT_ASN1_PRINTSTRING,  /* A printable string, often mblk */
  UT_ASN1_T61STRING,    /* teletext string */
  UT_ASN1_VIDEOTEX,     /* The videotex string type */
  UT_ASN1_IA5,          /* used for dns/url/email strings */
  UT_ASN1_TIME,         /* UTC time */
  UT_ASN1_GENERALTIME,  /* Basically, TIME + century */
  UT_ASN1_GRAPHIC,      /* a generalized graphical string */
  UT_ASN1_VISIBLE,      /* implied by the name */
  UT_ASN1_GENERALSTRING,/* A generalized string type */
  UT_ASN1_UNISTR,       /* Microsoft Universal String type */
  UT_ASN1_CONS_OCTET,   /* A Constructed Octet Sring */
  UT_ASN1_SEQUENCE,     /* Sequence - context-dependent; no explicit support */
  UT_ASN1_SET,          /* A set, again context-dependent */
  UT_ASN1_NTYPES        /* Total number of recognized types */
} ut_asn1type;

/* Function:    <ut ASN.1 handling>
 * Syntax:      These functions are deprecated. Use the asn1_ functions 
 *              instead.
 */


/* Function:    <ut_sizeof_type2bertag>
 * Summary:     Deprecated. Use asn1_sizeof_type2bertag() instead.
 */
extern size_t 
CST32EXPORTTYPE CST16EXPORTTYPE
ut_sizeof_type2bertag(ut_asn1type type);

/* Function:    <ut_type2bertag>
 * Summary:     Deprecated. Use asn1_type2bertag() instead.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_type2bertag(ut_asn1type type, u8 *dest);

/* Function:    <ut_bertag2type>
 * Summary:     Deprecated. Use asn1_bertag2type() instead.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_bertag2type(u8 *src, ut_asn1type *type);

/* Function:    <ut_qbertag2type>
 * Summary:     Deprecated. Use asn1_qbertag2type() instead.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
ut_qbertag2type(u8 *src, ut_asn1type *type);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _UT_H */
