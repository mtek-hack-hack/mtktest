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

#ifndef _BENCH_H /* Prevent multiple inclusion */
#define _BENCH_H

#include "ut.h"   /* For CST32EXPORTTYPE CST16EXPORTTYPE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef enum {INIT, DUMMY, TEST, FINISH} benchmode;

/*ERRORS*/


#define BENCH_EBASE (0x00040000) /* Module Code*/

#define BENCH_EPARAM (BENCH_EBASE + 0x00001) /* Bad parameters*/



/* Function:  <bench>
 * Syntax:    bench(argc, argv, fnames, flist, xtraparse, xtrainfo);
 * Semantics: Given an application's argc and argv, plus a 0-terminated
 *              sorted array of function names and an array of corresponding
 *              functions, this will benchmark them as indicated by the command
 *              line arguments.  The functions are of type
 *                  void(benchmode mode, long seed)
 *              .. where mode will be one of INIT, DUMMY, TEST or FINISH:
 *                INIT:   Function should initialize its static variables;
 *                          seed should be used to seed its random number
 *                          generator.
 *                DUMMY:  Function should do everything except call the
 *                          function it times - for calculating timing
 *                          overheads.
 *                TEST:   Function should call the function it times - for
 *                          genuine timing runs.
 *                FINISH: Function should tidy up after itself - this would
 *                          include freeing any space allocated during INIT.
 *              xtraparse(opt, arg, cmdname, fnames) is a function to parse an
 *                extra command line option (supplied in the bench_xtraargs)
 *                opt with argument (if applicable) arg.
 *              xtrainfo() is called after the normal timing banner is
 *                dispayed to allow any extra state (such as that controlled
 *                by xtraparse()) to be displayed.
 * Example:   fnames = {"add", "addc", "div", "sub", "subb", 0}
 *            flist = {add, addc, div, sub, subb}
 *            command line = "bench -o add,sub -s 9283 -t 3.2"
 *            .. this would benchmark add() & sub() for 3.2 CPU seconds with a
 *              random number seed of 9283.
 */
extern void 
 CST32EXPORTTYPE CST16EXPORTTYPE
bench(int, char **, char **, void (**)(benchmode, long),
    void (*)(char, char *, char *, char **), void (*)(void));

/* Variables: <bench_xtraargs>, <bench_xtrahelp>
 * Purpose:   bench_xtraargs contains a getopt-style list of any extra
 *              arguments which bench should allow - these are parsed by
 *              xtraparse().
 *            bench_xtrahelp contains a message which is tagged on to the end
 *              of the
 *              usage message displayed in case of bad arguments.
 */
extern char *bench_xtraargs, *bench_xtrahelp;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _BENCH_H */
